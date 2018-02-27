libHaru PDF library build for Staticlibs
========================================

[![travis](https://travis-ci.org/staticlibs/external_hpdf.svg?branch=master)](https://travis-ci.org/staticlibs/external_hpdf)
[![appveyor](https://ci.appveyor.com/api/projects/status/github/staticlibs/external_hpdf?svg=true)](https://ci.appveyor.com/project/staticlibs/external-hpdf)

This project is a part of [Staticlibs](http://staticlibs.net/).

This project contains a CMake build file for building the [libharu](http://libharu.org/)
library that
can be used to build sources imported from [CentOS lookaside](https://github.com/staticlibs/lookaside_libharu.git).

Link to the [documentation](https://github.com/libharu/libharu/wiki).

How to build
------------

[CMake](http://cmake.org/) is required for building.

[pkg-config](http://www.freedesktop.org/wiki/Software/pkg-config/) utility is used for dependency management.
For Windows users ready-to-use binary version of `pkg-config` can be obtained from [tools_windows_pkgconfig](https://github.com/staticlibs/tools_windows_pkgconfig) repository.
See [StaticlibsPkgConfig](https://github.com/staticlibs/wiki/wiki/StaticlibsPkgConfig) for Staticlibs-specific details about `pkg-config` usage.

To build the library on Windows using Visual Studio 2013 Express run the following commands using
Visual Studio development command prompt 
(`C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts\VS2013 x86 Native Tools Command Prompt`):

    git clone https://github.com/staticlibs/external_zlib.git
    git clone https://github.com/staticlibs/lookaside_zlib.git
    git clone https://github.com/staticlibs/external_libpng.git
    git clone https://github.com/staticlibs/lookaside_libpng.git
    git clone https://github.com/staticlibs/external_hpdf.git
    git clone https://github.com/staticlibs/lookaside_libharu.git
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

**2018-02-28**
 * version 2.3.0-3
 * drop submodule

**2017-12-31**
 * version 2.3.0-2
 * vs2017 support

**2017-05-23**

 * version 2.3.0-1
 * initial public version
