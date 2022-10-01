/*******************************************************************************
* Copyright 2022 KAIST USRG LAB.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Hyungjoo Kim, Sungjae Min from USRG KAIST */

#ifndef SVH_PIBOT_H
#define SVH_PIBOT_H

#include <ros/ros.h>

#include "SVHNode.h"
#include "DynamicParameterClass.h"
#include "schunk_svh_driver/SVH_Hand_Mission.h"

#include <icl_core/EnumHelper.h>
#include <stdlib.h>  /* srand, rand */
#include <time.h>    /* time */

class SVHPibotMission
{
  public:
    SVHPibotMission(const ros::NodeHandle &nh);

    void mission_callback(const std_msgs::String &msg);

    ros::ServiceServer mission_task_server;
    bool hand_mission_server(schunk_svh_driver::SVH_Hand_Mission::Request &req,
                             schunk_svh_driver::SVH_Hand_Mission::Response &res);
  
  private:
    ros::NodeHandle _nh;
    void initPublisher();
    void initServer();

    ros::Publisher channel_pos_pub;
};

#endif // SVH_PIBOT_H