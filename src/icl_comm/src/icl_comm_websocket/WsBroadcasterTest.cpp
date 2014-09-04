// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-


// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Georg Heppner <heppner@fzi.de>
 * \date    2014-5-20
 *
 */
//----------------------------------------------------------------------

#include <icl_comm_websocket/WsBroadcaster.h>
#include <boost/shared_ptr.hpp>

using namespace icl_comm::websocket;

// testing serial interface of s5fh driver
int main(int argc, const char* argv[])
{

  boost::shared_ptr<WsBroadcaster> bc_ptr;
  boost::shared_ptr<WsBroadcaster> bc_ptr2;

  // Set up the socket and other things
  try
  {
    bc_ptr = boost::shared_ptr<WsBroadcaster>(new WsBroadcaster(icl_comm::websocket::WsBroadcaster::eRT_LWA4P,"/tmp/ws_broadcaster"));
    bc_ptr2 = boost::shared_ptr<WsBroadcaster>(new WsBroadcaster(icl_comm::websocket::WsBroadcaster::eRT_SVH,"/tmp/ws_broadcaster"));

  }
  catch (SocketException e)
  {
    std::cout << e.what() << std::endl;
  }


  // This starts the Simulation
  try
  {
    if (bc_ptr)
    {
      bc_ptr->startSimulation(100);
    }

    if (bc_ptr2)
    {
      bc_ptr2->startSimulation(100);
    }

    while (1)
    {}

    // You would put in data like this:
    //    std::vector<double> pos(3,12.0);
    //    bc_ptr->robot.setJointPositions(pos);
    //    bc_ptr->sendState();

  }
  // Socket exception is thrown if socket can not be created or written
  catch (SocketException e)
  {
    std::cout << e.what() << std::endl;
  }


}
