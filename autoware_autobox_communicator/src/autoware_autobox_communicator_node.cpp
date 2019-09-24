#include <autoware_autobox_communicator.h>

int main
(int argc, char *argv[])
{
    ros::init(argc, argv, "autoware_autobox_communicator");
    AutowareAutoboxCommunicator app;
    app.Run();
    
    return 0;
}