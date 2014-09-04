// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2008-01-28
 *
 * \brief   Win32 implementation of the global thread functions.
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_OS_WIN32_THREAD_H_INCLUDED
#define ICL_CORE_OS_WIN32_THREAD_H_INCLUDED

#include <process.h>
#include <Windows.h>

#include "icl_core/ImportExport.h"

namespace icl_core {

typedef int pid_t;

namespace os {
namespace hidden_win32 {

typedef unsigned long ThreadId;

ICL_CORE_IMPORT_EXPORT ThreadId threadSelf();
ICL_CORE_IMPORT_EXPORT pid_t getpid();

}
}
}

#endif
