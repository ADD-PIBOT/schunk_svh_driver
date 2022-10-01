# Schunk SVH driver
[![Build Status](https://travis-ci.org/fzi-forschungszentrum-informatik/schunk_svh_driver.svg?branch=master)](https://travis-ci.org/fzi-forschungszentrum-informatik/schunk_svh_driver)


## This is modified version of Schunk SVH driver from fzi-forschungszentrum-informatik for improve capability for ROS Melodic
### Modifier: Sungjae Min, sungjae_min@kaist.ac.kr

This is the driver package for the SCHUNK SVH Five-Finger-Hand.
It was developed on behalf of SCHUNK Mobile Greifsysteme GmbH, Lauffen/Neckar, Germany
at the FZI Research Center for Information Technology in Karlsruhe, Germany.

The package contains the following core components:
- The low level hardware driver
- The ROS abstraction layer
- 3D model and kinematics description for visualization and grasp planning
These main components are distributed under a LGPL license.

Furthermore this package contains a build system and two libraries that are not
part of the SVH Driver but which are needed to build it:
- icmaker  (BSD License)
- icl_core (LGPL License)
- icl_comm (LGPL License)
These components were independently developed at the
FZI Research Center for Information Technology in Karlsruhe, Germany.

Also included is the TinyXML Library which was developed by
Lee Thomason (http://www.grinninglizard.com)
and which ships unter the zlib/libpng license.


See license folder for the license texts.

### Upper information are given from original fzi-forschungszentrum-informatik/schunk_svh_driver

## Change log
### at fzi_icl_core/src/icl_core/ts/icl_core_config/ts_main.cpp and fzi_icl_core/src/icl_core/ts/icl_core_thread/ts_main.cpp
Comment out 

    BOOST_GLOBAL_FIXTURE(GlobalFixture)

to

    // BOOST_GLOBAL_FIXTURE(GlobalFixture)


### at fzi_icl_core/src/icl_core/ts/icl_core_thread/ts_PeriodicThread.cpp
Define substitute definition

    #define BOOST_MESSAGE(M) BOOST_TEST_MESSAGE(M)


### at schunk_svh_driver/src/driver_svh/src/driver_svh/SVHController.cpp
Change included header file path

    #include <boost/bind/bind.hpp>

to

    #include <boost/bind.hpp>


### at schunk_svh_driver/src/driver_svh/src/driver_svh/SVHSerialInterface.cpp
Change included header file path

    #include <boost/bind/bind.hpp>

to

    #include <boost/bind.hpp>

## Fixing count received packet error
### at schunk_svh_driver/src/driver_svh/src/driver_svh/SVHReceiveThread.cpp
#### in function bool SVHReceiveThread::receiveData()
Add force type casting at m_serial_device->Read(&data_byte, sizeof(uint8_t))
from

    int bytes = m_serial_device->Read(&data_byte, sizeof(uint8_t));

to

    int bytes = (int)m_serial_device->Read(&data_byte, sizeof(uint8_t));



## Hardware version enablement
### at schunk_svh_driver/etc/controller_user.yaml
Add hardware version 2.3

    parameter set: {
        major_version: 2,
        minor_version: 3,
    ...
    }

### Some files that related to PIBOT are created by Hyungjoo Kim and Sungjae Min from USRG KAIST
