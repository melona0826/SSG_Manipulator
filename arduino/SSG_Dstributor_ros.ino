#include <AccelStepper.h>
#include <ros.h>
#include <std_msgs/Bool.h>

#define dir_Pin_1 4
#define dir_Pin_2 11

#define step_Pin_1 5
#define step_Pin_2 12


#define bt 9

ros::NodeHandle nh;

std_msgs::Bool bt_on_off;
std_msgs::Bool pick_finsih;

void wait_success(const std_msgs::Bool& success)
{
  pick_finsih = success;
}

ros::Publisher toggle_bt("toggle_bt" , &bt_on_off);

void setup() {
  // put your setup code here, to run once:
  pinMode(bt , INPUT);
  pinMode(dir_Pin_1 , OUTPUT);
  pinMode(dir_Pin_2 , OUTPUT);

  pinMode(step_Pin_1 , OUTPUT);
  pinMode(step_Pin_2 , OUTPUT);

  pinMode(13 , OUTPUT);

  nh.initNode();
  nh.advertise(toggle_bt);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(bt) == HIGH)
  {
    bt_on_off.data = true;
    toggle_bt.publish(&bt_on_off);
    distribute();
    delay(2000);
  }

  else
  {
    bt_on_off.data = false;
    toggle_bt.publish(&bt_on_off);
  }


  nh.spinOnce();
}

void distribute()
{
  digitalWrite(dir_Pin_1 , HIGH);
  digitalWrite(dir_Pin_2 , HIGH);

  for(int x = 0; x < 200; x++)
  {
    digitalWrite(step_Pin_1 , HIGH);
    digitalWrite(step_Pin_2 , HIGH);

    digitalWrite(13 , HIGH);
    delayMicroseconds(2000);
    digitalWrite(step_Pin_1 , LOW);
    digitalWrite(step_Pin_2 , LOW);

    digitalWrite(13 , LOW);
    delayMicroseconds(2000);
  }
}
