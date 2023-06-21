// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from image_meta_msgs_ros2:msg/ImageMetaData.idl
// generated code does not contain a copyright notice

#ifndef IMAGE_META_MSGS_ROS2__MSG__DETAIL__IMAGE_META_DATA__STRUCT_H_
#define IMAGE_META_MSGS_ROS2__MSG__DETAIL__IMAGE_META_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

// Struct defined in msg/ImageMetaData in the package image_meta_msgs_ros2.
typedef struct image_meta_msgs_ros2__msg__ImageMetaData
{
  std_msgs__msg__Header header;
  uint64_t camera_time;
  int16_t brightness;
  uint32_t exposure_time;
  uint32_t max_exposure_time;
  float gain;
} image_meta_msgs_ros2__msg__ImageMetaData;

// Struct for a sequence of image_meta_msgs_ros2__msg__ImageMetaData.
typedef struct image_meta_msgs_ros2__msg__ImageMetaData__Sequence
{
  image_meta_msgs_ros2__msg__ImageMetaData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} image_meta_msgs_ros2__msg__ImageMetaData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // IMAGE_META_MSGS_ROS2__MSG__DETAIL__IMAGE_META_DATA__STRUCT_H_
