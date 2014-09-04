// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2008-03-29
 *
 */
//----------------------------------------------------------------------
#include <string.h>

#include "icl_core/os_win32_mem.h"

namespace icl_core {
namespace os {
namespace hidden_win32 {

void *memcpy(void *dest, void *src, size_t count)
{
  return ::memcpy(dest, src, count);
}

void *memset(void *dest, int c, size_t count)
{
  return ::memset(dest, c, count);
}

}
}
}
