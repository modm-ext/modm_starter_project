# modm CMake starter project

## Purpose

This project demonstrates how to use modm's cmake build system with your favorite IDE/CMake enviroment.
All defined flags from lbuild are properly mapped into CMake including per-file flags.
All build flags are filtered so compiler choice, build type, etc. is independent from what modm internally does.

CMake interface targets defined.

- `modm_warnings` Contains all warnings defined by lbuild.
- `modm_options` Contains compiler flags defined by lbuild.
- `modm` The modm library it self.

## Installation

Follow [this](https://modm.io/guide/installation/) guide to install Modm.
It's needed to apply the following pull-request to Modm for now.

`git fetch origin pull/568/head:feature/cmake`

### In project.xml

Update the repository path to reflect your modm installation.

```xml
<repositories>
   <repository><path>../modm/repo.lb</path></repository>
</repositories>
```

This section set build options and prevents lbuild from overwrite you main cmake file.

```xml
<options>
   <option name="modm:build:build.path">build</option>
   <option name="modm:build:cmake:include_cmakelists">false</option>
   <option name="modm:build:cmake:include_makefile">false</option>
</options>
```

### Configure cmake

cmake-gui or ccmake is excellent tools to configure cmake.

#### Default options

Name | Value
 --------------------------- | -----------------
|CACHE_BINARY                    |*/usr/bin/ccache|
|CACHE_OPTION                    |*ccache|
|CMAKE_BUILD_TYPE                |*MinSizeRel|
|CMAKE_INSTALL_PREFIX            |*/usr/local|
|ENABLE_CACHE                    |*ON|
|ENABLE_CLANG_TIDY               |*OFF|
|ENABLE_CPPCHECK                 |*OFF|
|ENABLE_DOXYGEN                  |*OFF|
|ENABLE_INCLUDE_WHAT_YOU_USE     |*OFF|
|ENABLE_IPO                      |*OFF|
|ENABLE_MODM_CHECK_EXCLUDE       |*OFF|
|ENABLE_PCH                      |*OFF|
|MODM_BMP_PORT                   |auto|
|MODM_DBG_UI                     |tui|
|MODM_ITM_FCPU                   |0|
|MODM_GCC_PATH                   |/usr/local/arm-none-eabi|
|WARNINGS_AS_ERRORS              |*ON|

`ENABLE_MODM_CHECK_EXCLUDE` Prevents cppcheck and clang-tidy from including the modm source tree.

### Manually build and flash a device

```bash
lbuild build
mkdir build
cd build
ccmake ..
make -j4
make program
```

`make (size | program | program-bmp | debug | debug-bmp | log-itu)`

### Good CMake resources

[Effective Modern CMake](https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1)
