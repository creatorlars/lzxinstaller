cmake_minimum_required(VERSION 3.3)

if(WIN32)
    set(Qt5Core_DIR C:/Qt/5.14.2/msvc2017_64/lib/cmake/Qt5Core)
    set(Qt5_DIR C:/Qt/5.14.2/msvc2017_64/lib/cmake/Qt5)
    set(QT_DIR C:/Qt/5.14.2/msvc2017_64/lib/cmake/Qt5)
    set(XILINX_VIVADO_TOOLCHAIN_FILE C:/Xilinx/Vivado/2018.2/settings64.bat)
    set(XILINX_SDK_TOOLCHAIN_FILE C:/Xilinx/SDK/2018.2/settings64.bat)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} C:/Qt/5.14.2/msvc2017_64/lib/cmake/Qt5)
    set(CPACK_IFW_ROOT C:/Qt/Tools/QtInstallerFramework/4.0/bin)
else()
    set(Qt5Core_DIR /usr/local/Qt-5.14.2/lib/cmake/Qt5Core)
    set(Qt5_DIR /usr/local/Qt-5.14.2/lib/cmake/Qt5)
    set(QT_DIR /usr/local/Qt-5.14.2/lib/cmake/Qt5)
    set(XILINX_VIVADO_TOOLCHAIN_FILE /opt/Xilinx/Vivado/2018.2/settings64.sh)
    set(XILINX_SDK_TOOLCHAIN_FILE /opt/Xilinx/SDK/2018.2/settings64.sh)
    set(XILINX_PETALINUX_TOOLCHAIN_FILE /opt/pkg/petalinux/settings.sh)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/local/Qt-5.14.2/lib/cmake/Qt5)
    set(CPACK_IFW_ROOT /usr/local/tools)
endif()

project(lzx VERSION 1.0.0)

add_subdirectory(firmware/lzxplnx)
add_subdirectory(firmware/lzxcore-tbc2-base)

add_subdirectory(apps/lzxdfu)

set(CPACK_COMPONENTS_ALL lzxtbc2 lzxdfu)

set(CPACK_GENERATOR IFW)

     set(CPACK_PACKAGE_NAME "LZX")
     set(CPACK_PACKAGE_FILE_NAME lzx)
     set(CPACK_PACKAGE_HOMEPAGE_URL "https://www.lzxindustries.net")
     #set(CPACK_RESOURCE_FILE_README ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/readme.txt)
     #set(CPACK_RESOURCE_FILE_WELCOME ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/welcome.txt)
     #set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/license.txt)
     set(CPACK_PACKAGE_INSTALL_DIRECTORY "LZX")
     set(CPACK_PACKAGE_VERSION 1.0.0) # Version of installer
     set(CPACK_PACKAGE_VENDOR "LZX Industries")
    set(CPACK_IFW_VERBOSE ON)
    set(CPACK_IFW_PACKAGE_TITLE "LZX Wizard")
    set(CPACK_IFW_PRODUCT_URL "https://www.lzxindustries.net")
    set(CPACK_IFW_PACKAGE_ICON ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/lzx)
    set(CPACK_IFW_PACKAGE_ICON ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/window.png)
    set(CPACK_IFW_PACKAGE_LOGO ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/logo.png)
    set(CPACK_IFW_PACKAGE_WATERMARK ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/watermark.png)
    set(CPACK_IFW_PACKAGE_BANNER ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/banner.png)
    set(CPACK_IFW_PACKAGE_BACKGROUND ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/background.png)
    set(CPACK_IFW_PACKAGE_WIZARD_STYLE "Modern")
    set(CPACK_IFW_PACKAGE_TITLE_COLOR "#000000")
    set(CPACK_IFW_PACKAGE_MAINTENANCE_TOOL_NAME update)
    set(CPACK_IFW_PACKAGE_MAINTENANCE_TOOL_INI_FILE update.ini)
    set(CPACK_IFW_PACKAGE_START_MENU_DIRECTORY "LZX Industries")
    set(CPACK_IFW_DOWNLOAD_ALL TRUE)

include(CPack)
include(CPackIFW)  

if(WIN32)
cpack_ifw_add_repository(lzx URL http://downloads.lzxindustries.net/installer/win64/repository)
else()
cpack_ifw_add_repository(lzx URL http://downloads.lzxindustries.net/installer/Linux/repository)
endif()
              

cpack_add_component(lzxtbc2
                    DISPLAY_NAME "TBC2 Firmware"
                    DESCRIPTION "Firmware for LZX Industries TBC2 module."
                    EXPANDED)
                    
cpack_add_component(lzxdfu
                    DISPLAY_NAME "Firmware Update Utility"
                    DESCRIPTION "Firmware update utility app for LZX Industries devices."
                    EXPANDED)
                    
cpack_ifw_configure_component(lzxtbc2 
                     VERSION "1.0.0")

cpack_ifw_configure_component(lzxdfu 
                     VERSION "1.0.0")
