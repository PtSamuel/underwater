// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from image_meta_msgs_ros2:msg/ImageMetaData.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_META_MSGS_ROS2__MSG__DETAIL__IMAGE_META_DATA__TRAITS_HPP_
#define IMAGE_META_MSGS_ROS2__MSG__DETAIL__IMAGE_META_DATA__TRAITS_HPP_

#include "image_meta_msgs_ros2/msg/detail/image_meta_data__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<image_meta_msgs_ros2::msg::ImageMetaData>()
{
  return "image_meta_msgs_ros2::msg::ImageMetaData";
}

template<>
inline const char * name<image_meta_msgs_ros2::msg::ImageMetaData>()
{
  return "image_meta_msgs_ros2/msg/ImageMetaData";
}

template<>
struct has_fixed_size<image_meta_msgs_ros2::msg::ImageMetaData>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<image_meta_msgs_ros2::msg::ImageMetaData>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<image_meta_msgs_ros2::msg::ImageMetaData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // IMAGE_META_MSGS_ROS2__MSG__DETAIL__IMAGE_META_DATA__TRAITS_HPP_
