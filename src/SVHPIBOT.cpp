// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// This file is part of the SCHUNK SVH Driver suite.
//
// This program is free software licensed under the LGPL
// (GNU LESSER GENERAL PUBLIC LICENSE Version 3).
// You can find a copy of this license in LICENSE folder in the top
// directory of the source code.
//
// © Copyright 2014 SCHUNK Mobile Greifsysteme GmbH, Lauffen/Neckar Germany
// © Copyright 2014 FZI Forschungszentrum Informatik, Karlsruhe, Germany
//
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Hyungjoo Kim, Sungjae Min from USRG KAIST
 * \date    2022-09-30
 *
 * This file contains a very very simple test node that will generate a
 * sin movement for slected fingers of the Schunk Five finger hand.
 * It is only meant to be used as a quick test and demo program to use the
 * Schunk five finger hand and test its operation.
 */
//----------------------------------------------------------------------

#include "schunk_svh_driver/SVH_Hand_Mission.h"
#include "SVHPibot.h"

SVHPibotMission::SVHPibotMission(const ros::NodeHandle &nh)
: _nh(nh)
{
    initPublisher();
    initServer();
}

void SVHPibotMission::initPublisher()
{
    channel_pos_pub = _nh.advertise<sensor_msgs::JointState>("channel_targets", 1);
} 

void SVHPibotMission::initServer()
{
    mission_task_server = _nh.advertiseService("svh_hand_mission", &SVHPibotMission::hand_mission_server, this);
}

bool SVHPibotMission::hand_mission_server(schunk_svh_driver::SVH_Hand_Mission::Request &req,
                                          schunk_svh_driver::SVH_Hand_Mission::Response &res)
{
    std::string name_prefix;
    sensor_msgs::JointState channel_pos;
    channel_pos.name.resize(9);
    channel_pos.position.resize(9, 0.0);
    double default_pos = 0.0;
    
    try
    {
        _nh.param<std::string>("name_prefix", name_prefix, "right_hand");
    }
    catch (ros::InvalidNameException e)
    {
        ROS_ERROR("Parameter Error!");
    }

    channel_pos.name[0] = name_prefix + "_" + "Thumb_Flexion";
    channel_pos.name[1] = name_prefix + "_" + "Thumb_Opposition";
    channel_pos.name[2] = name_prefix + "_" + "Index_Finger_Distal";
    channel_pos.name[3] = name_prefix + "_" + "Index_Finger_Proximal";
    channel_pos.name[4] = name_prefix + "_" + "Middle_Finger_Proximal";
    channel_pos.name[5] = name_prefix + "_" + "Middle_Finger_Distal";
    channel_pos.name[6] = name_prefix + "_" + "Ring_Finger";
    channel_pos.name[7] = name_prefix + "_" + "Pinky";
    channel_pos.name[8] = name_prefix + "_" + "Finger_Spread";

    for (size_t channel = 0; channel < 9; ++channel)
        {
            double current_pose = 0.0;
            channel_pos.position[channel] = current_pose;
        }

    channel_pos.header.stamp = ros::Time::now();

    if(!req.name.data.compare("Switch_Mission"))
    {
        channel_pos.position[0] = 0.47;
        channel_pos.position[1] = default_pos;
        channel_pos.position[2] = default_pos;
        channel_pos.position[3] = default_pos;
        channel_pos.position[4] = 0.8;
        channel_pos.position[5] = 1.31;
        channel_pos.position[6] = 0.98;
        channel_pos.position[7] = 0.98;
        channel_pos.position[8] = 0.30;   
        channel_pos_pub.publish(channel_pos);     
    }

    else if(!req.name.data.compare("Pinch_Switch_Mission"))
    {
        channel_pos.position[0] = 0.40;
        channel_pos.position[1] = default_pos;
        channel_pos.position[2] = 0.90;
        channel_pos.position[3] = 0.25;
        channel_pos.position[4] = 0.80;
        channel_pos.position[5] = 1.32;
        channel_pos.position[6] = 0.98;
        channel_pos.position[7] = 0.98;
        channel_pos.position[8] = 0.45;
        channel_pos_pub.publish(channel_pos);
    }

    else if(!req.name.data.compare("Grasp_Yoke"))
    {
        channel_pos.position[0] = 0.25;
        channel_pos.position[1] = 0.00;
        channel_pos.position[2] = 0.65;
        channel_pos.position[3] = 0.65;
        channel_pos.position[4] = 0.55;
        channel_pos.position[5] = 0.72;
        channel_pos.position[6] = 0.52;
        channel_pos.position[7] = 0.52;
        channel_pos.position[8] = 0.05;
        channel_pos_pub.publish(channel_pos);
    }

    else if(!req.name.data.compare("Fuck_You"))
    {
        channel_pos.position[0] = 0.30;
        channel_pos.position[1] = 0.99;
        channel_pos.position[2] = 1.10;
        channel_pos.position[3] = 0.80;
        channel_pos.position[4] = default_pos;
        channel_pos.position[5] = default_pos;
        channel_pos.position[6] = 0.98;
        channel_pos.position[7] = 0.98;
        channel_pos.position[8] = 0.35;
        channel_pos_pub.publish(channel_pos);
    }
    else if(!req.name.data.compare("Default_Pose"))
    {
        channel_pos.position[0] = default_pos;
        channel_pos.position[1] = default_pos;
        channel_pos.position[2] = default_pos;
        channel_pos.position[3] = default_pos;
        channel_pos.position[4] = default_pos;
        channel_pos.position[5] = default_pos;
        channel_pos.position[6] = default_pos;
        channel_pos.position[7] = default_pos;
        channel_pos.position[8] = default_pos;
        channel_pos_pub.publish(channel_pos);
    }

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "svh_pibot");
    ros::NodeHandle nh("~");

    SVHPibotMission SVHPibot(nh);

    ros::Rate rate(10);
    while (nh.ok())
    {
        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
