#include "ros/ros.h"
#include "topic_first/simplemsg.h"

void chatterCallback(const topic_first::simplemsgConstPtr& ptr){
    ROS_INFO("I heard from %s: [%s]", ptr->id.c_str(), ptr->data.c_str());
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "simple_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);
    ros::spin();
    return 0;
}