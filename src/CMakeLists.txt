#------------------------------------------
# NAppGUI-v1.1.1.2372 CMake build script
#------------------------------------------
cmake_minimum_required(VERSION 2.8)
project(NAppGUI)

# NAppGUI Build Scripts
get_filename_component(ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR} PATH)
include(${ROOT_PATH}/prj/CMakeNAppGUI.txt)

# NAppGUI Libraries
staticLib("sewer" "" NRC_NONE)
staticLib("osbs" "sewer" NRC_NONE)
staticLib("core" "osbs" NRC_NONE)
staticLib("geom2d" "core" NRC_NONE)
staticLib("draw2d" "geom2d" NRC_NONE)
staticLib("osgui" "draw2d" NRC_NONE)
staticLib("gui" "draw2d" NRC_EMBEDDED)
staticLib("osapp" "osgui;gui" NRC_NONE)
staticLib("inet" "core" NRC_NONE)

# NAppGUI Sources
desktopApp("HelloWorld" "demo/hello" "" NRC_NONE NO)
desktopApp("HelloCpp" "demo/hellocpp" "" NRC_NONE NO)
staticLib("demo/casino" "draw2d" NRC_EMBEDDED)
desktopApp("Die" "demo/die" "demo/casino" NRC_EMBEDDED NO)
desktopApp("Dice" "demo/dice" "demo/casino" NRC_EMBEDDED NO)
desktopApp("Bricks" "demo/bricks" "" NRC_EMBEDDED NO)
desktopApp("Fractals" "demo/fractals" "" NRC_EMBEDDED NO)
desktopApp("Filters" "demo/filters" "" NRC_EMBEDDED NO)
desktopApp("Bode" "demo/bode" "" NRC_PACKED NO)
desktopApp("Products" "demo/products" "inet" NRC_PACKED NO)
desktopApp("GuiHello" "howto/guihello" "" NRC_EMBEDDED NO)
desktopApp("DrawHello" "howto/drawhello" "" NRC_EMBEDDED NO)
desktopApp("DrawImg" "howto/drawimg" "" NRC_EMBEDDED NO)
desktopApp("UrlImg" "howto/urlimg" "inet" NRC_EMBEDDED NO)
desktopApp("ColorView" "howto/colorview" "" NRC_EMBEDDED NO)
commandApp("howto/htjson" "inet;draw2d" NRC_EMBEDDED)
commandApp("howto/stlcmp" "" NRC_EMBEDDED)

# Your projects here!
