
OpenEaagles 3rd Party Libraries
===============================

The most current version of OpenEaagles can be found at [www.OpenEaagles.org][1].

* This package has been provided as a convenience for compiling in Windows. It contains executables, 'include' files and static libraries.

Applications
------------

* [Premake] - build configuration tool

* [mcpp] - portable C preprocessor (can be used as an alternative to Visual Studio C preprocessor - useful if Visual Studio is not installed on target computer)

* [Google Protocol buffers] message compiler

Libraries
---------

* [freetype] - portable font engine

* [FTGL] - library to draw fonts in OpenGL

* [freeglut] - an alternative to the OpenGL Utility Toolkit (GLUT) library

* [CIGI] - Common Image Generator Interface

* [JSBSim] - a C++-based dynamics model

* [Google protocol buffers]

* [ZeroMQ] - networking library

Notes
-----

* Visual Studio notes: All included libraries have been compiled assuming a multi-threaded DLL-based runtime library.  The libraries were compiled with:
   * Visual Studio 2013 update 5
   * Visual Studio 2015 update 3
   * Visual Studio 2017 15.0.0+26228.10 (update)

* Visual Studio 2015 & 2017
   * To compile Protocol Buffers 2.6.1, you need to define "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS"

Version Numbers
---------------

#### Build tool
* [Premake] - version 5.0 alpha 11

#### Graphics support
* [freetype2] - version 2.5.0.1
* [FTGL] - version 2.1.3rc5 (make sure to turn off "Whole Program Optimization")

#### Visual system interface
* [cigicl] - version 3.3.3a

#### Aerodynamics models
* [JSBSim] - pulled from CVS repository 04 July 2015

#### Binary data storage used by data recorder
* [Google protocol buffers] - version 2.6.1

Need to define "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS" for VS2017, otherwise, library will not compile.

#### Graphical User Interface (GUI) toolkits
* [freeglut] - version 3.0.0

Note: The standard freeglut header file has been modified so that we link against a static library but don't specify its name in the header file.

```
// freeglut_std.h modifications
#ifndef FREEGLUT_STATIC
#define FREEGLUT_STATIC           // we do want to link to a static library
#endif
#ifdef FREEGLUT_LIB_PRAGMAS
#define FREEGLUT_LIB_PRAGMAS 0    // we do not want the default libraries
#endif
```

#### Networking
* [ZeroMQ] - version 4.0.3

[1]: http://www.OpenEaagles.org
[Premake]: http://industriousone.com/premake
[mcpp]: http://mcpp.sourceforge.net/
[freetype]: http://www.freetype.org/
[FTGL]: http://sourceforge.net/projects/ftgl/
[freeglut]: http://freeglut.sourceforge.net
[CIGI]: http://cigi.sourceforge.net/index.php
[cigicl]: http://cigi.sourceforge.net/index.php
[JSBSIM]: http://www.jsbsim.org
[Google protocol buffers]: http://code.google.com/p/protobuf/
[ZeroMQ]: http://zeromq.org/
[freetype2]: http://www.freetype.org/freetype2/

