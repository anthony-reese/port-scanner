include(D:/Qt/projects/port-scanner/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/port-scanner-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE D:/Qt/projects/port-scanner/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/port-scanner.exe
    GENERATE_QT_CONF
)
