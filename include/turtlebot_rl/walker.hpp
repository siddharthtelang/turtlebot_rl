/**
 * MIT License
 *
 * Copyright (c) 2022 Siddharth Telang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
* @file walker.hpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief 
 * @version 0.1
 * @date 22022-02-24
 * 
 * @copyright Copyright (c) 2022
*/

#ifndef INCLUDE_TURTLEBOT_RL_WALKER_HPP_
#define INCLUDE_TURTLEBOT_RL_WALKER_HPP_
#endif  // INCLUDE_TURTLEBOT_RL_WALKER_HPP_

#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <memory>
#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "../include/turtlebot_rl/obstacle_detector.hpp"

class Walker {
 public:
    /**
     * @brief Construct a new Walker object
     * 
     * @param nh_ node handle
     */
    explicit Walker(ros::NodeHandle *nh_);
    ~Walker();
    /**
     * @brief begins the walking process
     * 
     */
    void start_walking();
    /**
     * @brief Laser Sensor callback
     * 
     * @param msg data from sensor
     */
    void lidarCallback(const sensor_msgs::LaserScan::ConstPtr &msg);
    /**
     * @brief send velocity to TTB3
     * 
     * @param obs direction of obstacle
     */
    void send_velocity(std::string obs);
    int rate;
    ObstacleDetector *detect = new ObstacleDetector();

 private:
    ros::NodeHandle *nh;
    void init();
    ros::Subscriber lidar_sub;
    ros::Publisher vel_pub;
    std::string topic;
};

