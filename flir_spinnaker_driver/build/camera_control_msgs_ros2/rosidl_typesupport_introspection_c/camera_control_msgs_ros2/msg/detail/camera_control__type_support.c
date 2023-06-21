// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from camera_control_msgs_ros2:msg/CameraControl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "camera_control_msgs_ros2/msg/detail/camera_control__rosidl_typesupport_introspection_c.h"
#include "camera_control_msgs_ros2/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "camera_control_msgs_ros2/msg/detail/camera_control__functions.h"
#include "camera_control_msgs_ros2/msg/detail/camera_control__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CameraControl__rosidl_typesupport_introspection_c__CameraControl_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  camera_control_msgs_ros2__msg__CameraControl__init(message_memory);
}

void CameraControl__rosidl_typesupport_introspection_c__CameraControl_fini_function(void * message_memory)
{
  camera_control_msgs_ros2__msg__CameraControl__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CameraControl__rosidl_typesupport_introspection_c__CameraControl_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera_control_msgs_ros2__msg__CameraControl, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "exposure_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera_control_msgs_ros2__msg__CameraControl, exposure_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gain",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera_control_msgs_ros2__msg__CameraControl, gain),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CameraControl__rosidl_typesupport_introspection_c__CameraControl_message_members = {
  "camera_control_msgs_ros2__msg",  // message namespace
  "CameraControl",  // message name
  3,  // number of fields
  sizeof(camera_control_msgs_ros2__msg__CameraControl),
  CameraControl__rosidl_typesupport_introspection_c__CameraControl_message_member_array,  // message members
  CameraControl__rosidl_typesupport_introspection_c__CameraControl_init_function,  // function to initialize message memory (memory has to be allocated)
  CameraControl__rosidl_typesupport_introspection_c__CameraControl_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CameraControl__rosidl_typesupport_introspection_c__CameraControl_message_type_support_handle = {
  0,
  &CameraControl__rosidl_typesupport_introspection_c__CameraControl_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_camera_control_msgs_ros2
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, camera_control_msgs_ros2, msg, CameraControl)() {
  CameraControl__rosidl_typesupport_introspection_c__CameraControl_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!CameraControl__rosidl_typesupport_introspection_c__CameraControl_message_type_support_handle.typesupport_identifier) {
    CameraControl__rosidl_typesupport_introspection_c__CameraControl_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CameraControl__rosidl_typesupport_introspection_c__CameraControl_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
