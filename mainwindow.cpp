#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <boost/asio.hpp>
#include <chrono>
#include <QMessageBox>
#include <QApplication>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtConcurrent>
#include <QStyle>

using boost::asio::ip::tcp;
using namespace std::chrono;

bool is_port_open(const std::string& ip, int port, long& response_time_ms) {
    boost::asio::io_context io_context;
    tcp::socket socket(io_context);

    try {
        auto start = high_resolution_clock::now();
        tcp::endpoint endpoint(boost::asio::ip::make_address(ip), port);
        socket.connect(endpoint);
        auto end = high_resolution_clock::now();
        response_time_ms = duration_cast<milliseconds>(end - start).count();
        return true;
    } catch (boost::system::system_error&) {
        return false;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Port Scanner");
    disconnect(ui->scanButton, nullptr, nullptr, nullptr);
    connect(ui->scanButton, &QPushButton::clicked, this, &MainWindow::on_scanButton_clicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::on_clearButton_clicked);
    connect(ui->darkModeCheckBox, &QCheckBox::toggled, this, &MainWindow::toggleDarkMode);
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::isPortOpen(const QString& ip, int port, qint64& responseTime) {
    QElapsedTimer timer;
    timer.start();

    QTcpSocket socket;
    socket.connectToHost(ip, port);
    bool connected = socket.waitForConnected(100);  // 100 ms timeout
    responseTime = timer.elapsed();
    socket.disconnectFromHost();
    return connected;
}

void MainWindow::on_scanButton_clicked() {
    QString ip = ui->ipLineEdit->text();
    int startPort = ui->startPortSpinBox->value();
    int endPort = ui->endPortSpinBox->value();

    ui->resultTextEdit->clear();
    ui->scanStatusLabel->setText("🔍 Scanning in progress...");
    ui->scanButton->setEnabled(false);
    ui->progressBar->setRange(0, endPort - startPort + 1);
    ui->progressBar->setValue(0);

    results.clear();

   QFuture<void> future = QtConcurrent::run([=]() {
        int progress = 0;
        QElapsedTimer timer;

        for (int port = startPort; port <= endPort; ++port) {
            timer.restart();
            QTcpSocket socket;
            socket.connectToHost(ip, port);
            bool connected = socket.waitForConnected(100);

            if (connected) {
                int responseTime = timer.elapsed();
                QString result = QString("Port %1 is open (Response Time: %2 ms)").arg(port).arg(responseTime);

                QMetaObject::invokeMethod(this, [=]() {
                    ui->resultTextEdit->append(result);
                    results.append(result);
                }, Qt::QueuedConnection);

                socket.disconnectFromHost();
            }

            // Update progress bar
            QMetaObject::invokeMethod(this, [=]() {
                ui->progressBar->setValue(progress + 1);
            }, Qt::QueuedConnection);

            ++progress;
        }

        // Update UI when done
        QMetaObject::invokeMethod(this, [=]() {
            ui->scanStatusLabel->setText("✅ Scan complete.");
            ui->scanButton->setEnabled(true);
        }, Qt::QueuedConnection);
    });
    Q_UNUSED(future);
}

void MainWindow::on_exportButton_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Export Results", "", "Text Files (*.txt)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const QString &line : std::as_const(results))
            out << line << '\n';
        file.close();
    }
}

void MainWindow::applyButtonStyles(bool darkMode)
{
    QString darkStyle = R"(
        QMenuBar, QMenu {
            background-color: #353535;
            color: white;
        }
        QMenu::item:selected {
            background-color: #444;
        }
    )";

    QString lightStyle = R"(
        QMenuBar, QMenu {
            background-color: #f0f0f0;
            color: black;
        }
        QMenu::item:selected {
            background-color: #e0e0e0;
        }
    )";

    ui->menuBar->setStyleSheet(darkMode ? darkStyle : lightStyle);
}

void MainWindow::toggleDarkMode(bool enabled)
{
    QPalette darkPalette;
    if (enabled) {
        darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Text, Qt::white);
        darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Highlight, QColor(142, 45, 197).lighter());
        darkPalette.setColor(QPalette::HighlightedText, Qt::black);

        qApp->setStyle(QStyleFactory::create("Fusion"));
        qApp->setPalette(darkPalette);
    } else {
        qApp->setStyle(QStyleFactory::create("Fusion"));
        qApp->setPalette(enabled ? darkPalette : style()->standardPalette());
    }

    // ✅ Apply styles specifically to these buttons
    applyButtonStyles(enabled);
}

void MainWindow::on_darkModeCheckBox_toggled(bool checked)
{
    toggleDarkMode(checked);
}

void MainWindow::on_clearButton_clicked() {
    ui->resultTextEdit->clear();
    ui->scanStatusLabel->setText("🟢 Ready.");
    ui->scanButton->setEnabled(true);
    ui->progressBar->setValue(0);
    results.clear();
}

void MainWindow::on_actionExit_triggered() {
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, "About Port Scanner",
                       "Simple Port Scanner\nVersion 1.0\n\u00a9 2025");
}
