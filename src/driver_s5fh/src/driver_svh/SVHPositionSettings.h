// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
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
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Georg Heppner
 * \date    2014-02-03
 * \date    2014-07-16
 *
 * This file contains the SVHPositionSettings data structure that is used to
 * receive and send the current parameters of the position controller within the hand.
 */
//----------------------------------------------------------------------
#ifndef SVHPOSITIONSETTINGS_H
#define SVHPOSITIONSETTINGS_H

#include <icl_comm/ByteOrderConversion.h>

namespace driver_svh {

/*!
 * \brief The SVHPositionSettings save the position controller paramters for a single motor
 */
struct SVHPositionSettings
{
public:
  //! Reference signal minimum value
  float wmn;
  //! Reference signal maximum value
  float wmx;
  //! Reference signal delta maximum threshold
  float dwmx;
  //! Measurement scaling
  float ky;
  //! Time base of controller
  float dt;
  //! Integral windup minimum value
  float imn;
  //! Integral windup maximum value
  float imx;
  //! Proportional gain
  float kp;
  //! Integral gain
  float ki;
  //! Differential gain
  float kd;

  //! Compares two SVHPositionsetting objects.
  bool operator == (const SVHPositionSettings& other) const
  {
    return
      (wmn == other.wmn
       && wmx == other.wmx
       && dwmx == other.dwmx
       && ky == other.ky
       && dt == other.dt
       && imn == other.imn
       && imx == other.imx
       && kp == other.kp
       && ki == other.ki
       && kd == other.kd);
  }
};

//! overload stream operator to easily serialize position settings data
inline icl_comm::ArrayBuilder& operator << (icl_comm::ArrayBuilder& ab, const SVHPositionSettings& data)
{
  ab << data.wmn
     << data.wmx
     << data.dwmx
     << data.ky
     << data.dt
     << data.imn
     << data.imx
     << data.kp
     << data.ki
     << data.kd;
  return ab;
}

//! overload stream operator to easily deserialize position settings data
inline icl_comm::ArrayBuilder& operator >> (icl_comm::ArrayBuilder& ab, SVHPositionSettings& data)
{
  ab >> data.wmn
     >> data.wmx
     >> data.dwmx
     >> data.ky
     >> data.dt
     >> data.imn
     >> data.imx
     >> data.kp
     >> data.ki
     >> data.kd;
  return ab;
}

//! Output stream operator to easily print position settings
inline std::ostream& operator << (std::ostream& o, const SVHPositionSettings& ps)
{
  o << "wmn " << ps.wmn << " "
    << "wmx " << ps.wmx << " "
    << "dwmx "<< ps.dwmx << " "
    << "ky "  << ps.ky  << " "
    << "dt "  << ps.dt  << " "
    << "imn " << ps.imn << " "
    << "imx " << ps.imx << " "
    << "kp "  << ps.kp  << " "
    << "ki "  << ps.ki  << " "
    << "kd "  << ps.kd << " "
    << std::endl;
  return o;
}





}

#endif // SVHPOSITIONSETTINGS_H