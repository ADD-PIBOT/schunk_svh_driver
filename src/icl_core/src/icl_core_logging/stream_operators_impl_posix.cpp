// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2008-03-30
 *
 */
//----------------------------------------------------------------------
#include "icl_core_logging/stream_operators_impl_posix.h"

#include "icl_core/os_thread.h"

namespace icl_core {
namespace logging {
namespace hidden_posix {

ThreadStream& operator << (ThreadStream& stream, const ThreadId& thread_id)
{
  return stream << uint32_t(thread_id);
}

}
}
}
