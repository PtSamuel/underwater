// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from image_meta_msgs_ros2:msg/ImageMetaData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "image_meta_msgs_ros2/msg/detail/image_meta_data__rosidl_typesupport_introspection_c.h"
#include "image_meta_msgs_ros2/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "image_meta_msgs_ros2/msg/detail/image_meta_data__functions.h"
#include "image_meta_msgs_ros2/msg/detail/image_meta_data__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  image_meta_msgs_ros2__msg__ImageMetaData__init(message_memory);
}

void ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_fini_function(void * message_memory)
{
  image_meta_msgs_ros2__msg__ImageMetaData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(image_meta_msgs_ros2__msg__ImageMetaData, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "camera_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(image_meta_msgs_ros2__msg__ImageMetaData, camera_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "brightness",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(image_meta_msgs_ros2__msg__ImageMetaData, brightness),  // bytes offset in struct
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
    offsetof(image_meta_msgs_ros2__msg__ImageMetaData, exposure_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_exposure_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(image_meta_msgs_ros2__msg__ImageMetaData, max_exposure_time),  // bytes offset in struct
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
    offsetof(image_meta_msgs_ros2__msg__ImageMetaData, gain),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_message_members = {
  "image_meta_msgs_ros2__msg",  // message namespace
  "ImageMetaData",  // message name
  6,  // number of fields
  sizeof(image_meta_msgs_ros2__msg__ImageMetaData),
  ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_message_member_array,  // message members
  ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_init_function,  // function to initialize message memory (memory has to be allocated)
  ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_message_type_support_handle = {
  0,
  &ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_image_meta_msgs_ros2
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, image_meta_msgs_ros2, msg, ImageMetaData)() {
  ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_message_type_support_handle.typesupport_identifier) {
    ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ImageMetaData__rosidl_typesupport_introspection_c__ImageMetaData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
