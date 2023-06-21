// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from camera_control_msgs_ros2:msg/CameraControl.idl
// generated code does not contain a copyright notice

#ifndef CAMERA_CONTROL_MSGS_ROS2__MSG__DETAIL__CAMERA_CONTROL__STRUCT_H_
#define CAMERA_CONTROL_MSGS_ROS2__MSG__DETAIL__CAMERA_CONTROL__STRUCT_H_

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

// Struct defined in msg/CameraControl in the package camera_control_msgs_ros2.
typedef struct camera_control_msgs_ros2__msg__CameraControl
{
  std_msgs__msg__Header header;
  uint32_t exposure_time;
  float gain;
} camera_control_msgs_ros2__msg__CameraControl;

// Struct for a sequence of camera_control_msgs_ros2__msg__CameraControl.
typedef struct camera_control_msgs_ros2__msg__CameraControl__Sequence
{
  camera_control_msgs_ros2__msg__CameraControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} camera_control_msgs_ros2__msg__CameraControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAMERA_CONTROL_MSGS_ROS2__MSG__DETAIL__CAMERA_CONTROL__STRUCT_H_
