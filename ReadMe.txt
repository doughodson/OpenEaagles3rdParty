
==================================================================
This package has been provided as a convenience for compiling
in Windows. It contains the executables, 'include' files and static
libraries.
==================================================================

------------------------------------------------------------------
Applications
------------------------------------------------------------------

Premake
http://industriousone.com/premake

mcpp - portable C preprocessor (used as an alternative to Visual Studio
C preprocessor - useful if Visual Studio is not installed on target computer)
http://mcpp.sourceforge.net/

Google Protocol buffers compiler (see protocol buffers below)

------------------------------------------------------------------
Libraries
------------------------------------------------------------------

freetype: A Free, High-Quality, and Portable Font Engine
http://www.freetype.org/

FTGL: A free, open source library to enable developers to use
arbitrary fonts in their OpenGL applications.
http://homepages.paradise.net.nz/henryj

freeglut: A completely OpenSourced alternative to the OpenGL
Utility Toolkit (GLUT) library.
http://freeglut.sourceforge.net

freeglut: A open source alternative to the original
          OpenGL Utility Toolkit (GLUT)

CIGI: Common Image Generator Interface
http://cigi.sourceforge.net/index.php

JSBSim: The Open Source Flight Dynamics Model in C++
http://www.jsbsim.org

Google protocol buffers
http://code.google.com/p/protobuf/

Visual Studio note: All included libraries have been compiled
for a multi-threaded DLL runtime library.  The libraries were
compiled with:

Visual Studio 2008 Service Pack #1 installed
Visual Studio 2010 Service Pack #1 installed
Visual Studio 2012 Update 3

==================================================================
Version Numbers
==================================================================

Build tool
----------
Premake : version 4.4 beta 5

Graphics support
----------------
freetype2 : version 2.5.0.1
FTGL      : version 2.1.3rc5 (make sure to turn off "Whole Program Optimization")

CIGI visual system interface
----------------------------
cigicl  : version 3.3.3a

Aero models
-----------
JSBSim : pulled from CVS repository 01 March 2013

Binary data storage used by data recorder
-----------------------------------------
Google protocol buffers : version 2.4.1

Graphical User Interface (GUI) toolkits
---------------------------------------
freeglut: version 2.8.1
   Note: The standard freeglut header file has been modified
   so that we link against a static library but don't specify its name in the
   header file.

// freeglut_std.h modifications
#define FREEGLUT_STATIC           // we do want to link to a static library
#define FREEGLUT_LIB_PRAGMAS 0    // we do not want the default libraries

FLTK: version 1.3.2

FOX: version 1.6.49
