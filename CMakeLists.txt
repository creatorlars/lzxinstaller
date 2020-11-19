cmake_minimum_required(VERSION 3.3)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/src/scripts/cmake)

set(DEBUG 0)

if(WIN32)
    set(XILINX_VIVADO_TOOLCHAIN_FILE C:/Xilinx/Vivado/2018.2/settings64.bat)
    set(XILINX_SDK_TOOLCHAIN_FILE C:/Xilinx/SDK/2018.2/settings64.bat)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} C:/Qt/5.14.2/msvc2017_64/lib/cmake/Qt5)
    set(CPACK_IFW_ROOT C:/Qt/Tools/QtInstallerFramework/4.0/bin)
else()
    set(XILINX_VIVADO_TOOLCHAIN_FILE /opt/Xilinx/Vivado/2018.2/settings64.sh)
    set(XILINX_SDK_TOOLCHAIN_FILE /opt/Xilinx/SDK/2018.2/settings64.sh)
    set(XILINX_PETALINUX_TOOLCHAIN_FILE /opt/pkg/petalinux/settings.sh)
    
endif()

project(lzxtools VERSION 0.1.0)
if(WIN32)
    find_package(Qt5 COMPONENTS Widgets SerialPort REQUIRED)
    if(Qt5_FOUND AND WIN32 AND TARGET Qt5::qmake AND NOT TARGET Qt5::windeployqt)
        get_target_property(_qt5_qmake_location Qt5::qmake IMPORTED_LOCATION)
        execute_process(
            COMMAND "${_qt5_qmake_location}" -query QT_INSTALL_PREFIX
            RESULT_VARIABLE return_code
            OUTPUT_VARIABLE qt5_install_prefix
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        set(imported_location "${qt5_install_prefix}/bin/windeployqt.exe")
        if(EXISTS ${imported_location})
            add_executable(Qt5::windeployqt IMPORTED)
            set_target_properties(Qt5::windeployqt PROPERTIES
                IMPORTED_LOCATION ${imported_location}
            )
        endif()
    endif()

    set(CPACK_PACKAGE_NAME "LZX Tools")
    set(CPACK_PACKAGE_FILE_NAME lzx-tools-installer)
    set(CPACK_PACKAGE_HOMEPAGE_URL "https://www.lzxindustries.net")
    #set(CPACK_RESOURCE_FILE_README ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/readme.txt)
    #set(CPACK_RESOURCE_FILE_WELCOME ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/welcome.txt)
    #set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/license.txt)
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "LZX")
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "LZX Tools")
    set(CPACK_PACKAGE_VERSION ${LZX_VERSION}) # Version of installer
    set(CPACK_PACKAGE_VENDOR "LZX Industries")
    set(CPACK_PACKAGE_EXECUTABLES lzxgui;LZX Gui;lzxterm;LZX Term;lzxpatch;LZX Patch)
    set(CPACK_CREATE_DESKTOP_LINKS lzxgui;LZX Gui;lzxterm;LZX Term;lzxpatch;LZX Patch) 
    set(CPACK_GENERATOR IFW)
    set(CPACK_IFW_PACKAGE_GROUP lzxtools)
    set(CPACK_IFW_VERBOSE ON)
    set(CPACK_IFW_PRODUCT_URL "https://www.lzxindustries.net")
    set(CPACK_IFW_PACKAGE_ICON ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/lzx)
    #set(CPACK_IFW_PACKAGE_ICON ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/window.png)
    #set(CPACK_IFW_PACKAGE_LOGO ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/logo.png)
    #set(CPACK_IFW_PACKAGE_WATERMARK ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/watermark.png)
    #set(CPACK_IFW_PACKAGE_BANNER ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/banner.png)
    #set(CPACK_IFW_PACKAGE_BACKGROUND ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/background.png)
    set(CPACK_IFW_PACKAGE_WIZARD_STYLE "Modern")
    set(CPACK_IFW_PACKAGE_TITLE_COLOR "#000000")
    set(CPACK_IFW_PACKAGE_MAINTENANCE_TOOL_NAME lzxupdate)
    set(CPACK_IFW_PACKAGE_MAINTENANCE_TOOL_INI_FILE lzxupdate.ini)
    set(CPACK_IFW_PACKAGE_START_MENU_DIRECTORY "LZX Industries")
    set(CPACK_IFW_DOWNLOAD_ALL TRUE)
    include(CPack)
    include(CPackIFW)   
    cpack_add_component_group(lzxtools DISPLAY_NAME "LZX Tools" DESCRIPTION "Software tools for LZX Industries devices.")
    cpack_ifw_add_repository(lzxtools URL http://downloads.lzxindustries.net/lzxtools)
endif()

add_subdirectory(artifacts/lzxcore-tbc2-base)
add_subdirectory(artifacts/lzxdfu)
add_subdirectory(artifacts/lzxplnx)

# BUILD FLOW - LINUX HOST
# Build All Core RTL Hardware Definition & Bitstream
# Create & Configure PetaLinux Project
# Build PetaLinux
# Export Petalinux BSP
# Build PetaLinux & FreeRTOS Applications
# Package Firmware Update Packages
# Build Desktop Applications for Linux
# Package Desktop Installer for Linux

# BUILD FLOW - WINDOWS HOST
# Cross Compile PetaLinux Applications for Windows
# Build Desktop Applications for Windows
# Package Desktop Installer for Windows

# BUILD FLOW - MAC HOST
# Build Desktop Applications for Mac
# Package Desktop Installer for Mac

# BUILD FLOW - DEPLOYMENT (LINUX HOST)
# Upload Packages To Deployment Repos