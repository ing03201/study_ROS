#include "ros/ros.h"
#include "topic_first/simplemsg.h"
class chatting{
    public:    
        chatting(){
            sub = nh.subscribe("chatter", 1000, &chatting::chatterCallback, this);
        }
         void chatterCallback(const topic_first::simplemsgConstPtr& ptr);
    
    private:
        ros::NodeHandle nh;
        ros::Subscriber sub;
};

void chatting::chatterCallback(const topic_first::simplemsgConstPtr& ptr){
        ROS_INFO("I heard from %s: [%s]", ptr->id.c_str(), ptr->data.c_str());
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "simple_sub");
    chatting c;
    ros::spin();
    return 0; 
}