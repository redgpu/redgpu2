#pragma once

#ifndef REDGPU_NP_STRUCT_INIT
#ifdef __cplusplus
#define REDGPU_NP_STRUCT_INIT(x) x
#else
#define REDGPU_NP_STRUCT_INIT(x) (x)
#endif
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetDevicePtrFromVkBuffer rrGetDevicePtrFromVkBuffer
#define _88d55845_context(value) value
#define _88d55845_resource(value) value
#define _88d55845_offset(value) value
#define _88d55845_device_ptr(value) value
#else
typedef struct _s_88d55845_context { RRContext value; } _s_88d55845_context;
typedef struct _s_88d55845_resource { RedHandleArray value; } _s_88d55845_resource;
typedef struct _s_88d55845_offset { size_t value; } _s_88d55845_offset;
typedef struct _s_88d55845_device_ptr { RRDevicePtr* value; } _s_88d55845_device_ptr;
static inline _s_88d55845_context _88d55845_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_88d55845_context){value}; }
static inline _s_88d55845_resource _88d55845_resource(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_88d55845_resource){value}; }
static inline _s_88d55845_offset _88d55845_offset(size_t value) { return REDGPU_NP_STRUCT_INIT(_s_88d55845_offset){value}; }
static inline _s_88d55845_device_ptr _88d55845_device_ptr(RRDevicePtr* value) { return REDGPU_NP_STRUCT_INIT(_s_88d55845_device_ptr){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetDevicePtrFromVkBuffer(_s_88d55845_context context, _s_88d55845_resource resource, _s_88d55845_offset offset, _s_88d55845_device_ptr device_ptr) {
  return rrGetDevicePtrFromVkBuffer(context.value, resource.value, offset.value, device_ptr.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrCreateContextVk rrCreateContextVk
#define _0bc4c766_api_version(value) value
#define _0bc4c766_device(value) value
#define _0bc4c766_physical_device(value) value
#define _0bc4c766_command_queue(value) value
#define _0bc4c766_queue_family_index(value) value
#define _0bc4c766_context(value) value
#else
typedef struct _s_0bc4c766_api_version { uint32_t value; } _s_0bc4c766_api_version;
typedef struct _s_0bc4c766_device { RedHandleGpu value; } _s_0bc4c766_device;
typedef struct _s_0bc4c766_physical_device { RedHandleGpuDevice value; } _s_0bc4c766_physical_device;
typedef struct _s_0bc4c766_command_queue { RedHandleQueue value; } _s_0bc4c766_command_queue;
typedef struct _s_0bc4c766_queue_family_index { uint32_t value; } _s_0bc4c766_queue_family_index;
typedef struct _s_0bc4c766_context { RRContext* value; } _s_0bc4c766_context;
static inline _s_0bc4c766_api_version _0bc4c766_api_version(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_0bc4c766_api_version){value}; }
static inline _s_0bc4c766_device _0bc4c766_device(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_0bc4c766_device){value}; }
static inline _s_0bc4c766_physical_device _0bc4c766_physical_device(RedHandleGpuDevice value) { return REDGPU_NP_STRUCT_INIT(_s_0bc4c766_physical_device){value}; }
static inline _s_0bc4c766_command_queue _0bc4c766_command_queue(RedHandleQueue value) { return REDGPU_NP_STRUCT_INIT(_s_0bc4c766_command_queue){value}; }
static inline _s_0bc4c766_queue_family_index _0bc4c766_queue_family_index(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_0bc4c766_queue_family_index){value}; }
static inline _s_0bc4c766_context _0bc4c766_context(RRContext* value) { return REDGPU_NP_STRUCT_INIT(_s_0bc4c766_context){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrCreateContextVk(_s_0bc4c766_api_version api_version, _s_0bc4c766_device device, _s_0bc4c766_physical_device physical_device, _s_0bc4c766_command_queue command_queue, _s_0bc4c766_queue_family_index queue_family_index, _s_0bc4c766_context context) {
  return rrCreateContextVk(api_version.value, device.value, physical_device.value, command_queue.value, queue_family_index.value, context.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetCommandStreamFromVkCommandBuffer rrGetCommandStreamFromVkCommandBuffer
#define _d91fee51_context(value) value
#define _d91fee51_command_buffer(value) value
#define _d91fee51_command_stream(value) value
#else
typedef struct _s_d91fee51_context { RRContext value; } _s_d91fee51_context;
typedef struct _s_d91fee51_command_buffer { RedHandleCalls value; } _s_d91fee51_command_buffer;
typedef struct _s_d91fee51_command_stream { RRCommandStream* value; } _s_d91fee51_command_stream;
static inline _s_d91fee51_context _d91fee51_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_d91fee51_context){value}; }
static inline _s_d91fee51_command_buffer _d91fee51_command_buffer(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_d91fee51_command_buffer){value}; }
static inline _s_d91fee51_command_stream _d91fee51_command_stream(RRCommandStream* value) { return REDGPU_NP_STRUCT_INIT(_s_d91fee51_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetCommandStreamFromVkCommandBuffer(_s_d91fee51_context context, _s_d91fee51_command_buffer command_buffer, _s_d91fee51_command_stream command_stream) {
  return rrGetCommandStreamFromVkCommandBuffer(context.value, command_buffer.value, command_stream.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrAllocateDeviceBuffer rrAllocateDeviceBuffer
#define _c71e36bb_context(value) value
#define _c71e36bb_size(value) value
#define _c71e36bb_device_ptr(value) value
#else
typedef struct _s_c71e36bb_context { RRContext value; } _s_c71e36bb_context;
typedef struct _s_c71e36bb_size { size_t value; } _s_c71e36bb_size;
typedef struct _s_c71e36bb_device_ptr { RRDevicePtr* value; } _s_c71e36bb_device_ptr;
static inline _s_c71e36bb_context _c71e36bb_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_c71e36bb_context){value}; }
static inline _s_c71e36bb_size _c71e36bb_size(size_t value) { return REDGPU_NP_STRUCT_INIT(_s_c71e36bb_size){value}; }
static inline _s_c71e36bb_device_ptr _c71e36bb_device_ptr(RRDevicePtr* value) { return REDGPU_NP_STRUCT_INIT(_s_c71e36bb_device_ptr){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrAllocateDeviceBuffer(_s_c71e36bb_context context, _s_c71e36bb_size size, _s_c71e36bb_device_ptr device_ptr) {
  return rrAllocateDeviceBuffer(context.value, size.value, device_ptr.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrMapDevicePtr rrMapDevicePtr
#define _e9031491_context(value) value
#define _e9031491_device_ptr(value) value
#define _e9031491_mapping_ptr(value) value
#else
typedef struct _s_e9031491_context { RRContext value; } _s_e9031491_context;
typedef struct _s_e9031491_device_ptr { RRDevicePtr value; } _s_e9031491_device_ptr;
typedef struct _s_e9031491_mapping_ptr { void** value; } _s_e9031491_mapping_ptr;
static inline _s_e9031491_context _e9031491_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_e9031491_context){value}; }
static inline _s_e9031491_device_ptr _e9031491_device_ptr(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_e9031491_device_ptr){value}; }
static inline _s_e9031491_mapping_ptr _e9031491_mapping_ptr(void** value) { return REDGPU_NP_STRUCT_INIT(_s_e9031491_mapping_ptr){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrMapDevicePtr(_s_e9031491_context context, _s_e9031491_device_ptr device_ptr, _s_e9031491_mapping_ptr mapping_ptr) {
  return rrMapDevicePtr(context.value, device_ptr.value, mapping_ptr.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrUnmapDevicePtr rrUnmapDevicePtr
#define _055ccb39_context(value) value
#define _055ccb39_device_ptr(value) value
#define _055ccb39_mapping_ptr(value) value
#else
typedef struct _s_055ccb39_context { RRContext value; } _s_055ccb39_context;
typedef struct _s_055ccb39_device_ptr { RRDevicePtr value; } _s_055ccb39_device_ptr;
typedef struct _s_055ccb39_mapping_ptr { void** value; } _s_055ccb39_mapping_ptr;
static inline _s_055ccb39_context _055ccb39_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_055ccb39_context){value}; }
static inline _s_055ccb39_device_ptr _055ccb39_device_ptr(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_055ccb39_device_ptr){value}; }
static inline _s_055ccb39_mapping_ptr _055ccb39_mapping_ptr(void** value) { return REDGPU_NP_STRUCT_INIT(_s_055ccb39_mapping_ptr){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrUnmapDevicePtr(_s_055ccb39_context context, _s_055ccb39_device_ptr device_ptr, _s_055ccb39_mapping_ptr mapping_ptr) {
  return rrUnmapDevicePtr(context.value, device_ptr.value, mapping_ptr.value);
}
#endif

