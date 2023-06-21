// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from camera_control_msgs_ros2:msg/CameraControl.idl
// generated code does not contain a copyright notice

#ifndef CAMERA_CONTROL_MSGS_ROS2__MSG__DETAIL__CAMERA_CONTROL__BUILDER_HPP_
#define CAMERA_CONTROL_MSGS_ROS2__MSG__DETAIL__CAMERA_CONTROL__BUILDER_HPP_

#include "camera_control_msgs_ros2/msg/detail/camera_control__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace camera_control_msgs_ros2
{

namespace msg
{

namespace builder
{

class Init_CameraControl_gain
{
public:
  explicit Init_CameraControl_gain(::camera_control_msgs_ros2::msg::CameraControl & msg)
  : msg_(msg)
  {}
  ::camera_control_msgs_ros2::msg::CameraControl gain(::camera_control_msgs_ros2::msg::CameraControl::_gain_type arg)
  {
    msg_.gain = std::move(arg);
    return std::move(msg_);
  }

private:
  ::camera_control_msgs_ros2::msg::CameraControl msg_;
};

class Init_CameraControl_exposure_time
{
public:
  explicit Init_CameraControl_exposure_time(::camera_control_msgs_ros2::msg::CameraControl & msg)
  : msg_(msg)
  {}
  Init_CameraControl_gain exposure_time(::camera_control_msgs_ros2::msg::CameraControl::_exposure_time_type arg)
  {
    msg_.exposure_time = std::move(arg);
    return Init_CameraControl_gain(msg_);
  }

private:
  ::camera_control_msgs_ros2::msg::CameraControl msg_;
};

class Init_CameraControl_header
{
public:
  Init_CameraControl_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CameraControl_exposure_time header(::camera_control_msgs_ros2::msg::CameraControl::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CameraControl_exposure_time(msg_);
  }

private:
  ::camera_control_msgs_ros2::msg::CameraControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::camera_control_msgs_ros2::msg::CameraControl>()
{
  return camera_control_msgs_ros2::msg::builder::Init_CameraControl_header();
}

}  // namespace camera_control_msgs_ros2

#endif  // CAMERA_CONTROL_MSGS_ROS2__MSG__DETAIL__CAMERA_CONTROL__BUILDER_HPP_
