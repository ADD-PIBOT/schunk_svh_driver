# this is for emacs file handling -*- mode: cmake; indent-tabs-mode: nil -*-

# -- BEGIN LICENSE BLOCK ----------------------------------------------
// This file is part of the SCHUNK SVH Driver suite.
//
// This program is free software licensed under the LGPL
// (GNU LESSER GENERAL PUBLIC LICENSE Version 3).
// You can find a copy of this license in LICENSE.txt in the top
// directory of the source code.
//
// © Copyright 2014 SCHUNK Mobile Greifsysteme GmbH, Lauffen/Neckar Germany
// © Copyright 2014 FZI Forschungszentrum Informatik, Karlsruhe, Germany
//
# -- END LICENSE BLOCK ------------------------------------------------

#----------------------------------------------------------------------
# \file
#
# \author  Jan Oberlaender <oberlaender@fzi.de>
# \date    2014-08-13
#
# Try to find Ardcom.  Once done, this will define:
#  Ardcom_FOUND:          System has Ardcom
#  Ardcom_INCLUDE_DIRS:   The '-I' preprocessor flags (w/o the '-I')
#  Ardcom_LIBRARY_DIRS:   The paths of the libraries (w/o the '-L')
# Variables defined if pkg-config was employed:
#  Ardcom_DEFINITIONS:    Preprocessor definitions.
#  Ardcom_LIBRARIES:      only the libraries (w/o the '-l')
#  Ardcom_LDFLAGS:        all required linker flags
#  Ardcom_LDFLAGS_OTHER:  all other linker flags
#  Ardcom_CFLAGS:         all required cflags
#  Ardcom_CFLAGS_OTHER:   the other compiler flags
#  Ardcom_VERSION:        version of the module
#  Ardcom_PREFIX:         prefix-directory of the module
#  Ardcom_INCLUDEDIR:     include-dir of the module
#  Ardcom_LIBDIR:         lib-dir of the module
#----------------------------------------------------------------------

include(PrintLibraryStatus)
include(LibFindMacros)

libfind_lib_with_pkg_config(Ardcom Ardcom
  HEADERS ardcom/ardcom.h
  LIBRARIES libardcom.a libardcomsf.a
  )