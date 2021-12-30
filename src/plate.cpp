#include "ros/ros.h"
#include "std_msgs/Bool.h"

std_msgs::Bool success;

void btCallback(const std_msgs::Bool& toggle)
{
  ROS_INFO("receive msg = %d" , toggle.data);
}

int main(int argc , char** argv)
{
  ros::init(argc , argv , "manipulator_test");
  ros::NodeHandle nh;


  while(ros::ok())
  {
    ros::Subscriber bt_sub = nh.subscribe("toggle_bt" , 100 , btCallback);

    ros::spin();

  }


}
