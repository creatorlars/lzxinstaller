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

# cpack_ifw_configure_component(lzxtbc2 
#                     NAME "TBC2 Firmware"
#                     DISPLAY_NAME "TBC2 Firmware" # Note: Internationalization supported
#                     DESCRIPTION "TBC2 Firmware" # Note: Internationalization supported
#                     VERSION "1.0.0"
#                     CHECKABLE true)


# cpack_ifw_configure_component(lzxdfu 
#                     NAME "Firmware Update Utility"
#                     DISPLAY_NAME "Firmware Update Utility" # Note: Internationalization supported
#                     DESCRIPTION "Firmware Update Utility" # Note: Internationalization supported
#                     VERSION "1.0.0"
#                     CHECKABLE true)                    

# cpack_ifw_configure_component(<compname> [COMMON] [ESSENTIAL] [VIRTUAL]
#                     [FORCED_INSTALLATION] [REQUIRES_ADMIN_RIGHTS]
#                     [NAME <name>]
#                     [DISPLAY_NAME <display_name>] # Note: Internationalization supported
#                     [DESCRIPTION <description>] # Note: Internationalization supported
#                     [UPDATE_TEXT <update_text>]
#                     [VERSION <version>]
#                     [RELEASE_DATE <release_date>]
#                     [SCRIPT <script>]
#                     [PRIORITY|SORTING_PRIORITY <sorting_priority>] # Note: PRIORITY is deprecated
#                     [DEPENDS|DEPENDENCIES <com_id> ...]
#                     [AUTO_DEPEND_ON <comp_id> ...]
#                     [LICENSES <display_name> <file_path> ...]
#                     [DEFAULT <value>]
#                     [USER_INTERFACES <file_path> <file_path> ...]
#                     [TRANSLATIONS <file_path> <file_path> ...]
#                     [REPLACES <comp_id> ...]
#                     [CHECKABLE <value>])

# cpack_ifw_configure_component_group(<groupname> [VIRTUAL]
#                     [FORCED_INSTALLATION] [REQUIRES_ADMIN_RIGHTS]
#                     [NAME <name>]
#                     [DISPLAY_NAME <display_name>] # Note: Internationalization supported
#                     [DESCRIPTION <description>] # Note: Internationalization supported
#                     [UPDATE_TEXT <update_text>]
#                     [VERSION <version>]
#                     [RELEASE_DATE <release_date>]
#                     [SCRIPT <script>]
#                     [PRIORITY|SORTING_PRIORITY <sorting_priority>] # Note: PRIORITY is deprecated
#                     [DEPENDS|DEPENDENCIES <com_id> ...]
#                     [AUTO_DEPEND_ON <comp_id> ...]
#                     [LICENSES <display_name> <file_path> ...]
#                     [DEFAULT <value>]
#                     [USER_INTERFACES <file_path> <file_path> ...]
#                     [TRANSLATIONS <file_path> <file_path> ...]
#                     [REPLACES <comp_id> ...]
#                     [CHECKABLE <value>])