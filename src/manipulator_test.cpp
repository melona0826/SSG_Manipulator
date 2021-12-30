#include <ros/ros.h>
#include <std_msgs/Bool.h>

class Sub_and_Pub
{
public:
  Sub_and_Pub()
  {
    pub_ = nh_.advertise<std_msgs::Bool>("pick_success" , 100);
    sub_ = nh_.subscribe("toggle_bt" , 100 , &Sub_and_Pub::btCallback , this);
    IN_ACTION.data = true;
    SUCCESS.data = false;
  }

  void btCallback(const std_msgs::Bool& toggle_bt)
  {
    ROS_INFO("receive msg = %d" , toggle_bt.data);

    if(toggle_bt.data)
    {
      ROS_INFO("Toggle Button is ON !");
      ROS_INFO("Manipulator go to pick !");
      pub_.publish(IN_ACTION);
      ros::Duration(5.0).sleep();
      ROS_INFO("Now System is Ready !");
      ros::Duration(0.5).sleep();
      pub_.publish(SUCCESS);
    }
    
    else
    {
      pub_.publish(SUCCESS);
    }
  }

private:
  ros::NodeHandle nh_;
  ros::Publisher pub_;
  ros::Subscriber sub_;

  std_msgs::Bool SUCCESS;
  std_msgs::Bool IN_ACTION;

};

int main(int argc , char** argv)
{
  ros::init(argc , argv , "manipulator_test");
  ROS_INFO("Now System is Ready !");
  Sub_and_Pub Success_and_Action;
  ros::spin();
}
