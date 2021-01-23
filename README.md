# NAppGUI
Cross-Platform C SDK. Build portable desktop applications for Windows, macOS and Linux, using just C.

![NAppGUI Stack](https://nappgui.com/img/start/nappgui_stack.png)

## Prerequisites
- [Visual Studio 2019](https://visualstudio.microsoft.com/vs/) - Windows
- [Xcode 12, 11, 10](https://developer.apple.com/xcode/) - macOS Big Sur, Catalina or Mojave
- GCC 9, 7 - Ubuntu 20.04 LTS or 18.04 LTS
- [CMake](https://cmake.org/download/) - Cross platform

## Running on Windows
### Open a terminal
```
C:\>git clone https://github.com/frang75/nappgui.git C:\nappgui
```

It will create a working copy on `C:\nappgui`

### Open CMake
- **Where is the source code:** `C:\nappgui\src` (Or `src` folder in your working copy)
- **Where to build the binaries:** `C:\nappgui_build` (Or other folder)
- [Configure]
- [Generate]
- [Open Project]

![NAppGUI CMake](https://nappgui.com/img/start/nappgui_cmake.png)

You must select the **Visual Studio 16 2019** generator with **x64** platform the first time.

![NAppGUI Generator](https://nappgui.com/img/start/cmake_generator.png)

### In Visual Studio 2019 (after click in [Open Project])
- Build->Build Solution
- Run the examples under `demo` or `howto`

![NAppGUI Build](https://nappgui.com/img/start/rundemo_visualstudio.png)

## Running on macOS

Get the working copy and run CMake in the same way as Windows, using `Xcode` generator.

```
git clone https://github.com/frang75/nappgui.git ~/nappgui
```
![Xcode_Debugging](https://nappgui.com/img/start/xcode_debug.png)

**Important:** `CMAKE_DEPLOYMENT_TARGET` must be `11.0`, `10.15` or `10.14`

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

## Edited
## Edited2
## Edited3
## Edited4
