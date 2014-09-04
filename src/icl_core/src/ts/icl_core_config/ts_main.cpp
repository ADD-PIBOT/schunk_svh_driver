// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2012-01-25
 *
 */
//----------------------------------------------------------------------
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include <icl_core/os_lxrt.h>
#include <icl_core_logging/Logging.h>

struct GlobalFixture
{
  GlobalFixture()
  {
    icl_core::os::lxrtStartup();
    icl_core::logging::initialize();
  }

  ~GlobalFixture()
  {
    icl_core::logging::shutdown();
    icl_core::os::lxrtShutdown();
  }
};

BOOST_GLOBAL_FIXTURE(GlobalFixture)
