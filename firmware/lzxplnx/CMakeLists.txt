cmake_minimum_required(VERSION 3.3)

install(FILES BOOT.BIN image.ub DESTINATION Firmware/TBC2 COMPONENT lzxtbc2)

# set(CPACK_COMPONENT_LZXPLNX_DISPLAY_NAME "LZX PetaLinux")
# set(CPACK_COMPONENT_LZXPLNX_DESCRIPTION "Linux kernel subsystem for TBC2, Memory Palace & Chromagnon.")
# set(CPACK_COMPONENT_LZXPLNX_GROUP "Firmware")

# set(CPACK_COMPONENTS_ALL ${CPACK_COMPONENTS_ALL} lzxplnx)