#include <autoware_autobox_communicator.h>

void AutowareAutoboxCommunicator::twist_cmd_callback
(const geometry_msgs::TwistStamped& target_signal)
{   
    receive_messages();
    target_linear_velocity_ = target_signal.twist.linear.x;
    target_angular_velocity_ = target_signal.twist.angular.z;
    target_acceleration_ = (target_linear_velocity_ - current_velocity_) * 0.2;
    target_steering_angle_ = target_angular_velocity_ * 0.1;
    send_messages();
}

void AutowareAutoboxCommunicator::receive_messages()
{
    
    // 1. Current velocity
    // 2. Selfdriving state of Autoware
}

void AutowareAutoboxCommunicator::send_messages()
{
    
    // 1. Selfdriving switch
    // 2. Steering switch
    // 3. Accel pedal switch
    // 4. Emergency pedal switch
    // 5. Target linear velocity
    // 6. Target angular velocity
    // 7. Target steering angle
    // 8. Target acceleration
}

/*
AutoMation_ON : 자율주행 스위치
LKAS_ON : 스티어링 스위치
ACC_ON : 속도페달 스위치
StandStill : 비상정
*/

void AutowareAutoboxCommunicator::Run()
{   
    std::thread autobox_thread(&AutoboxManager::Run, &autobox_manager_);
    autobox_manager_.read();
    ros::spin();
    autobox_thread.join();

    return;
}