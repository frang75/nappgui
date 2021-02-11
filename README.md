# NAppGUI
Cross-Platform C SDK. Build portable desktop applications for Windows, macOS and Linux, using just C.

![NAppGUI Stack](https://nappgui.com/img/start/nappgui_stack.png)

## Prerequisites
- **Windows:** [Visual Studio](https://visualstudio.microsoft.com/vs/)

- **macOS:** [Xcode](https://developer.apple.com/xcode/)

- **Linux:**
```
// Development tools
sudo apt-get install gcc
sudo apt-get install g++
sudo apt-get install git
sudo apt-get install make
sudo apt-get install cmake

// Development libraries
sudo apt-get install libgtk-3-dev
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
sudo apt-get install libcurl4-openssl-dev
```

- **All platforms:** [CMake](https://cmake.org/download/)

## Quick start in Windows

### Prerequisites
- [Visual Studio](https://visualstudio.microsoft.com/vs/)
- [CMake](https://cmake.org/download/)

### Open the Developer Command Prompt
```
(from C:\)

// Clone the NAppGUI repo
git clone --depth 1 https://github.com/frang75/nappgui.git nappgui_sdk

// Create a build directory
mkdir nappgui_build
cd nappgui_build

// Generate the Visual Studio Solution
cmake -G "Visual Studio 16 2019" ../nappgui_sdk/src

// Build the examples
msbuild NAppGUI.sln

// Run examples in 'demo' and 'howto' folders
.\demo\die\Debug\Die.exe
.\demo\bricks\Debug\Bricks.exe
.\demo\products\Debug\Products.exe
.\howto\col2dhello\Debug\Col2dHello.exe
.\howto\guihello\Debug\GuiHello.exe
...
```
![Running demo project in Windows](https://nappgui.com/img/start/run_demo_windows.png)

## Quick start in macOS

### Prerequisites
- [Xcode](https://developer.apple.com/xcode/)
- [CMake](https://cmake.org/download/)

### Open the Terminal
```
(from your home dir ~/)

// Clone the NAppGUI repo
git clone --depth 1 https://github.com/frang75/nappgui.git nappgui_sdk

// Create a build directory
mkdir nappgui_build
cd nappgui_build

// Generate the Xcode project
cmake -G "Xcode" ../nappgui_sdk/src

// Build the examples
xcodebuild

// Run examples in 'demo' and 'howto' folders
./demo/die/Debug/Die.app/Contents/MacOS/Die
./demo/bricks/Debug/Bricks.app/Contents/MacOS/Bricks
./demo/products/Debug/Products.app/Contents/MacOS/Products
./howto/col2dhello/Debug/Col2dHello.app/Contents/MacOS/Col2dHello
./howto/guihello/Debug/GuiHello.app/Contents/MacOS/GuiHello
...
```
![Running demo project in macOS](https://nappgui.com/img/start/run_demo_macos.png)

## Running on Ubuntu 20.04 or 18.04

Get the working copy and run CMake, using `Unix Makefiles` generator.

```
cd ~/nappgui_build         // Or your binary dir
make                       // Compile
./demo/die/Debug/Die       // Run an example
gdb ./demo/die/Debug/Die   // Debug an example
```
![gdb_Debugging](https://nappgui.com/img/start/debug_gdb.png)

**Important:**

* If you use `ECLIPSE CDT4 - Unix Makefiles` or other "Make based" generators, additional project files will be created.
* The package is not tested in others Linux platforms. Theoretically, it should works if `gcc-7` and `gtk3` are present.

## More info
- [NAppGUI Quick Start](https://nappgui.com/en/start/quick.html)
- [NAppGUI Hello World](https://nappgui.com/en/start/hello.html)
- [Create a new project](https://nappgui.com/en/start/newprj.html)
- [About Portability](https://nappgui.com/en/start/win_mac_linux.html)

## Edit
