// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2008-01-28
 *
 * \brief   Posix implementation of the global filesystem functions.
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_OS_POSIX_FS_H_INCLUDED
#define ICL_CORE_OS_POSIX_FS_H_INCLUDED

#include "icl_core/ImportExport.h"

namespace icl_core {
namespace os {
//! Internal implementation details for POSIX systems.
namespace hidden_posix {

ICL_CORE_IMPORT_EXPORT int rename(const char *old_filename, const char *new_filename);
ICL_CORE_IMPORT_EXPORT int unlink(const char *filename);

}
}
}

#endif
