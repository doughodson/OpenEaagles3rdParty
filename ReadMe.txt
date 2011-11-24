
==================================================================

This package has been provided as a convenience for compiling
in Windows. It contains the include files and static libraries
for the following toolkits.

freetype: A Free, High-Quality, and Portable Font Engine
http://freetype.sourceforge.net

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

Visual Studio note: All included libraries have been compiled
for a multi-threaded DLL runtime library.  The libraries were
compiled with:

Visual Studio 2008 Service Pack #1 installed
Visual Studio 2010 Service Pack #1 installed

==================================================================

Basic Graphics support
======================

freetype2 : version 2.4.5

FTGL : version 2.1.3rc5 (make sure to turn off "Whole Program Optimization")

Visual System support
=====================

cigicl  : version 3.3.2

Aero models
===========

JSBSim : pulled from CVS repository 26 June 2011

GUI toolkits
============

freeglut: version 2.6.0.  Note: The standard freeglut header file has been modified
   so that we link against a static library but don't specify its name in the
   header file.

// freeglut_std.h modifications
#define FREEGLUT_STATIC           // we do want to link to a static library
#define FREEGLUT_LIB_PRAGMAS 0    // we do not want the default libraries

FLTK: version 1.3.0

FOX: version 1.6.44

