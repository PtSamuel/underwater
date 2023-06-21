// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from image_meta_msgs_ros2:msg/ImageMetaData.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_META_MSGS_ROS2__MSG__DETAIL__IMAGE_META_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define IMAGE_META_MSGS_ROS2__MSG__DETAIL__IMAGE_META_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "image_meta_msgs_ros2/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "image_meta_msgs_ros2/msg/detail/image_meta_data__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace image_meta_msgs_ros2
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_image_meta_msgs_ros2
cdr_serialize(
  const image_meta_msgs_ros2::msg::ImageMetaData & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_image_meta_msgs_ros2
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  image_meta_msgs_ros2::msg::ImageMetaData & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_image_meta_msgs_ros2
get_serialized_size(
  const image_meta_msgs_ros2::msg::ImageMetaData & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_image_meta_msgs_ros2
max_serialized_size_ImageMetaData(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace image_meta_msgs_ros2

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_image_meta_msgs_ros2
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, image_meta_msgs_ros2, msg, ImageMetaData)();

#ifdef __cplusplus
}
#endif

#endif  // IMAGE_META_MSGS_ROS2__MSG__DETAIL__IMAGE_META_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
