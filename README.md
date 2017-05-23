libHaru PDF library build for Staticlibs
========================================

This project is a part of [Staticlibs](http://staticlibs.net/).

This project contains a CMake build file for building the [libharu](http://libharu.org/)
library. 

[libharu sources imported from Fedora EPEL lookaside](https://github.com/ojdkbuild/lookaside_libharu)
are used as a submodule of this project.

Link to the [documentation](https://github.com/libharu/libharu/wiki).

How to build
------------

[CMake](http://cmake.org/) is required for building.

To build the library on Windows using Visual Studio 2013 Express run the following commands using
Visual Studio development command prompt 
(`C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts\VS2013 x86 Native Tools Command Prompt`):

    git clone --recursive https://github.com/staticlibs/external_zlib.git
    git clone --recursive https://github.com/staticlibs/external_libpng.git
    git clone --recursive https://github.com/staticlibs/external_hpdf.git
    cd external_hpdf
    mkdir build
    cd build
    cmake ..
    msbuild external_hpdf.sln

Cloning of [external_zlib](https://github.com/staticlibs/external_zlib) and 
[external_libpng](https://github.com/staticlibs/external_libpng) is not required on Linux - system libraries will be used instead.

See [StaticlibsToolchains](https://github.com/staticlibs/wiki/wiki/StaticlibsToolchains) for 
more information about the toolchain setup and cross-compilation.

License information
-------------------

This project is released under the [Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0).

Changelog
---------

**2017-05-23**

 * version 2.3.0-1
 * initial public version
