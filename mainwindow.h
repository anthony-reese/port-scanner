#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QTcpSocket>
#include <QStyleFactory>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_scanButton_clicked();
    void on_exportButton_clicked();
    void on_clearButton_clicked();
    void toggleDarkMode(bool enabled);
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void applyButtonStyles(bool darkMode);
    void on_darkModeCheckBox_toggled(bool checked);

private:
Ui::MainWindow *ui;
QStringList results;
bool isPortOpen(const QString& ip, int port, qint64& responseTime);
};

#endif // MAINWINDOW_H
