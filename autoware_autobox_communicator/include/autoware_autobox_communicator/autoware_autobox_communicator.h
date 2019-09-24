#include <thread>
#include <functional>
#include <ros/ros.h>
#include <autobox_manager.h>
#include <geometry_msgs/TwistStamped.h>


// Communicate with Autobox and Autoware
class AutowareAutoboxCommunicator{
private:
    // Variables
    ros::NodeHandle node_handle_;                   // Node Handler
    ros::Subscriber target_signal_subscriber_;      // Control signal subscriber
    AutoboxManager  autobox_manager_;
    double          target_linear_velocity_;                 // Target linear velocity
    double          target_angular_velocity_;                // Target angular velocity
    double          target_acceleration_;                    // Accel pedal control quantity
    double          target_steering_angle_;                  // Handle control quantity
    
    
private:    //Read
    double current_velocity_;                       // Current velocity
    double autobox_state_;                          // State of Autobox. ON? or OFF?

private:    //Write
    

private:
    // Private Functions
    void twist_cmd_callback(const geometry_msgs::TwistStamped& target_signal);
    // Callback for twist_cmd
    void receive_messages();
    // Receive messages to Autobox
    void send_messages();
    // Send messages from Autobox
public:
    void Run();
};