// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from camera_control_msgs_ros2:msg/CameraControl.idl
// generated code does not contain a copyright notice

#ifndef CAMERA_CONTROL_MSGS_ROS2__MSG__DETAIL__CAMERA_CONTROL__TRAITS_HPP_
#define CAMERA_CONTROL_MSGS_ROS2__MSG__DETAIL__CAMERA_CONTROL__TRAITS_HPP_

#include "camera_control_msgs_ros2/msg/detail/camera_control__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<camera_control_msgs_ros2::msg::CameraControl>()
{
  return "camera_control_msgs_ros2::msg::CameraControl";
}

template<>
inline const char * name<camera_control_msgs_ros2::msg::CameraControl>()
{
  return "camera_control_msgs_ros2/msg/CameraControl";
}

template<>
struct has_fixed_size<camera_control_msgs_ros2::msg::CameraControl>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<camera_control_msgs_ros2::msg::CameraControl>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<camera_control_msgs_ros2::msg::CameraControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CAMERA_CONTROL_MSGS_ROS2__MSG__DETAIL__CAMERA_CONTROL__TRAITS_HPP_
