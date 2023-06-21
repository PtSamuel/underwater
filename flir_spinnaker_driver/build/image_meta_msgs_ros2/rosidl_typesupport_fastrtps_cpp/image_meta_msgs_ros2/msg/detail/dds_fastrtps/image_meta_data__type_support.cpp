// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from image_meta_msgs_ros2:msg/ImageMetaData.idl
// generated code does not contain a copyright notice
#include "image_meta_msgs_ros2/msg/detail/image_meta_data__rosidl_typesupport_fastrtps_cpp.hpp"
#include "image_meta_msgs_ros2/msg/detail/image_meta_data__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: camera_time
  cdr << ros_message.camera_time;
  // Member: brightness
  cdr << ros_message.brightness;
  // Member: exposure_time
  cdr << ros_message.exposure_time;
  // Member: max_exposure_time
  cdr << ros_message.max_exposure_time;
  // Member: gain
  cdr << ros_message.gain;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_image_meta_msgs_ros2
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  image_meta_msgs_ros2::msg::ImageMetaData & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: camera_time
  cdr >> ros_message.camera_time;

  // Member: brightness
  cdr >> ros_message.brightness;

  // Member: exposure_time
  cdr >> ros_message.exposure_time;

  // Member: max_exposure_time
  cdr >> ros_message.max_exposure_time;

  // Member: gain
  cdr >> ros_message.gain;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_image_meta_msgs_ros2
get_serialized_size(
  const image_meta_msgs_ros2::msg::ImageMetaData & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: camera_time
  {
    size_t item_size = sizeof(ros_message.camera_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: brightness
  {
    size_t item_size = sizeof(ros_message.brightness);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: exposure_time
  {
    size_t item_size = sizeof(ros_message.exposure_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_exposure_time
  {
    size_t item_size = sizeof(ros_message.max_exposure_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gain
  {
    size_t item_size = sizeof(ros_message.gain);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_image_meta_msgs_ros2
max_serialized_size_ImageMetaData(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: camera_time
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: brightness
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: exposure_time
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: max_exposure_time
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gain
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _ImageMetaData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const image_meta_msgs_ros2::msg::ImageMetaData *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ImageMetaData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<image_meta_msgs_ros2::msg::ImageMetaData *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ImageMetaData__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const image_meta_msgs_ros2::msg::ImageMetaData *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ImageMetaData__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ImageMetaData(full_bounded, 0);
}

static message_type_support_callbacks_t _ImageMetaData__callbacks = {
  "image_meta_msgs_ros2::msg",
  "ImageMetaData",
  _ImageMetaData__cdr_serialize,
  _ImageMetaData__cdr_deserialize,
  _ImageMetaData__get_serialized_size,
  _ImageMetaData__max_serialized_size
};

static rosidl_message_type_support_t _ImageMetaData__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ImageMetaData__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace image_meta_msgs_ros2

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_image_meta_msgs_ros2
const rosidl_message_type_support_t *
get_message_type_support_handle<image_meta_msgs_ros2::msg::ImageMetaData>()
{
  return &image_meta_msgs_ros2::msg::typesupport_fastrtps_cpp::_ImageMetaData__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, image_meta_msgs_ros2, msg, ImageMetaData)() {
  return &image_meta_msgs_ros2::msg::typesupport_fastrtps_cpp::_ImageMetaData__handle;
}

#ifdef __cplusplus
}
#endif
