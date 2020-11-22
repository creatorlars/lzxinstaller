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

install(FILES components/lzxcore-tbc2-base/lzxcore-tbc2-base.bit components/lzxcore-tbc2-base/lzxcore-tbc2-base.elf DESTINATION lzxcore-tbc2-base COMPONENT lzxcore-tbc2-base)
install(FILES components/lzxplnx/BOOT.BIN components/lzxplnx/image.ub DESTINATION lzxplnx COMPONENT lzxplnx)

set(CPACK_COMPONENTS_ALL lzxplnx lzxcore-tbc2-base)

set(CPACK_COMPONENT_LZXPLNX_DISPLAY_NAME "LZX PetaLinux")
set(CPACK_COMPONENT_LZXPLNX_DESCRIPTION "Linux kernel subsystem for TBC2, Memory Palace & Chromagnon.")
set(CPACK_COMPONENT_LZXPLNX_GROUP "Firmware")

set(CPACK_COMPONENT_LZXCORE-TBC2-BASE_DISPLAY_NAME "LZX TBC2 Base")
set(CPACK_COMPONENT_LZXCORE-TBC2-BASE_DESCRIPTION "Base firmware for TBC2.")
set(CPACK_COMPONENT_LZXCORE-TBC2-BASE_DEPENDS lzxplnx)
set(CPACK_COMPONENT_LZXCORE-TBC2-BASE_GROUP "Firmware")


set(CPACK_COMPONENT_GROUP_FIRMWARE_DESCRIPTION "Firmware update packages for LZX Industries devices.")
set(CPACK_GENERATOR IFW)



# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/src/scripts/cmake)

# set(DEBUG 0)




#     find_package(Qt5 COMPONENTS Widgets SerialPort REQUIRED)
#     if(Qt5_FOUND AND WIN32 AND TARGET Qt5::qmake AND NOT TARGET Qt5::windeployqt)
#         get_target_property(_qt5_qmake_location Qt5::qmake IMPORTED_LOCATION)
#         execute_process(
#             COMMAND "${_qt5_qmake_location}" -query QT_INSTALL_PREFIX
#             RESULT_VARIABLE return_code
#             OUTPUT_VARIABLE qt5_install_prefix
#             OUTPUT_STRIP_TRAILING_WHITESPACE
#         )
#         set(imported_location "${qt5_install_prefix}/bin/windeployqt.exe")
#         if(EXISTS ${imported_location})
#             add_executable(Qt5::windeployqt IMPORTED)
#             set_target_properties(Qt5::windeployqt PROPERTIES
#                 IMPORTED_LOCATION ${imported_location}
#             )
#         endif()
#     endif()

    #  set(CPACK_PACKAGE_NAME "LZX Installer")
     set(CPACK_PACKAGE_FILE_NAME lzx)
     set(CPACK_PACKAGE_HOMEPAGE_URL "https://www.lzxindustries.net")
#     #set(CPACK_RESOURCE_FILE_README ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/readme.txt)
#     #set(CPACK_RESOURCE_FILE_WELCOME ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/welcome.txt)
#     #set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/license.txt)
     set(CPACK_PACKAGE_INSTALL_DIRECTORY "LZX")
     set(CPACK_PACKAGE_VERSION ${LZX_VERSION}) # Version of installer
#     set(CPACK_PACKAGE_VENDOR "LZX Industries")
#     set(CPACK_PACKAGE_EXECUTABLES lzxgui;LZX Gui;lzxterm;LZX Term;lzxpatch;LZX Patch)
#     set(CPACK_CREATE_DESKTOP_LINKS lzxgui;LZX Gui;lzxterm;LZX Term;lzxpatch;LZX Patch) 

#    set(CPACK_IFW_PACKAGE_GROUP lzx-${CMAKE_SYSTEM})
    set(CPACK_IFW_VERBOSE ON)
    set(CPACK_IFW_PRODUCT_URL "https://www.lzxindustries.net")
    #set(CPACK_IFW_PACKAGE_ICON ${CMAKE_SOURCE_DIR}/src/apps/lzxtools/res/lzx)
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
#     include(CPack)
#     include(CPackIFW)   
#     cpack_add_component_group(lzxtools DISPLAY_NAME "LZX Tools" DESCRIPTION "Software tools for LZX Industries devices.")

include(CPack)
include(CPackIFW)  

if(WIN32)
cpack_ifw_add_repository(lzx URL http://downloads.lzxindustries.net/installer/win64/repository)
else()
cpack_ifw_add_repository(lzx URL http://downloads.lzxindustries.net/installer/Linux/repository)
endif()

# add_subdirectory(components/lzxplnx)
# add_subdirectory(components/lzxcore-tbc2-base)
# add_subdirectory(components/lzxdfu)
