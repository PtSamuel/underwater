// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from image_meta_msgs_ros2:msg/ImageMetaData.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_META_MSGS_ROS2__MSG__DETAIL__IMAGE_META_DATA__BUILDER_HPP_
#define IMAGE_META_MSGS_ROS2__MSG__DETAIL__IMAGE_META_DATA__BUILDER_HPP_

#include "image_meta_msgs_ros2/msg/detail/image_meta_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace image_meta_msgs_ros2
{

namespace msg
{

namespace builder
{

class Init_ImageMetaData_gain
{
public:
  explicit Init_ImageMetaData_gain(::image_meta_msgs_ros2::msg::ImageMetaData & msg)
  : msg_(msg)
  {}
  ::image_meta_msgs_ros2::msg::ImageMetaData gain(::image_meta_msgs_ros2::msg::ImageMetaData::_gain_type arg)
  {
    msg_.gain = std::move(arg);
    return std::move(msg_);
  }

private:
  ::image_meta_msgs_ros2::msg::ImageMetaData msg_;
};

class Init_ImageMetaData_max_exposure_time
{
public:
  explicit Init_ImageMetaData_max_exposure_time(::image_meta_msgs_ros2::msg::ImageMetaData & msg)
  : msg_(msg)
  {}
  Init_ImageMetaData_gain max_exposure_time(::image_meta_msgs_ros2::msg::ImageMetaData::_max_exposure_time_type arg)
  {
    msg_.max_exposure_time = std::move(arg);
    return Init_ImageMetaData_gain(msg_);
  }

private:
  ::image_meta_msgs_ros2::msg::ImageMetaData msg_;
};

class Init_ImageMetaData_exposure_time
{
public:
  explicit Init_ImageMetaData_exposure_time(::image_meta_msgs_ros2::msg::ImageMetaData & msg)
  : msg_(msg)
  {}
  Init_ImageMetaData_max_exposure_time exposure_time(::image_meta_msgs_ros2::msg::ImageMetaData::_exposure_time_type arg)
  {
    msg_.exposure_time = std::move(arg);
    return Init_ImageMetaData_max_exposure_time(msg_);
  }

private:
  ::image_meta_msgs_ros2::msg::ImageMetaData msg_;
};

class Init_ImageMetaData_brightness
{
public:
  explicit Init_ImageMetaData_brightness(::image_meta_msgs_ros2::msg::ImageMetaData & msg)
  : msg_(msg)
  {}
  Init_ImageMetaData_exposure_time brightness(::image_meta_msgs_ros2::msg::ImageMetaData::_brightness_type arg)
  {
    msg_.brightness = std::move(arg);
    return Init_ImageMetaData_exposure_time(msg_);
  }

private:
  ::image_meta_msgs_ros2::msg::ImageMetaData msg_;
};

class Init_ImageMetaData_camera_time
{
public:
  explicit Init_ImageMetaData_camera_time(::image_meta_msgs_ros2::msg::ImageMetaData & msg)
  : msg_(msg)
  {}
  Init_ImageMetaData_brightness camera_time(::image_meta_msgs_ros2::msg::ImageMetaData::_camera_time_type arg)
  {
    msg_.camera_time = std::move(arg);
    return Init_ImageMetaData_brightness(msg_);
  }

private:
  ::image_meta_msgs_ros2::msg::ImageMetaData msg_;
};

class Init_ImageMetaData_header
{
public:
  Init_ImageMetaData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImageMetaData_camera_time header(::image_meta_msgs_ros2::msg::ImageMetaData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ImageMetaData_camera_time(msg_);
  }

private:
  ::image_meta_msgs_ros2::msg::ImageMetaData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::image_meta_msgs_ros2::msg::ImageMetaData>()
{
  return image_meta_msgs_ros2::msg::builder::Init_ImageMetaData_header();
}

}  // namespace image_meta_msgs_ros2

#endif  // IMAGE_META_MSGS_ROS2__MSG__DETAIL__IMAGE_META_DATA__BUILDER_HPP_
