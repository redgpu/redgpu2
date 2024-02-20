#pragma once

#ifndef REDGPU_NP_DECLSPEC
#define REDGPU_NP_DECLSPEC
#endif

#ifndef REDGPU_NP_API
#define REDGPU_NP_API
#endif

#ifndef REDGPU_NP_STRUCT_INIT
#ifdef __cplusplus
#define REDGPU_NP_STRUCT_INIT(x) x
#else
#define REDGPU_NP_STRUCT_INIT(x) (x)
#endif
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetDevicePtrFromVkBuffer rrGetDevicePtrFromVkBuffer
#define _7586bd4a_context(value) value
#define _7586bd4a_resource(value) value
#define _7586bd4a_offset(value) value
#define _7586bd4a_device_ptr(value) value
#else
typedef struct _s_7586bd4a_context { RRContext value; } _s_7586bd4a_context;
typedef struct _s_7586bd4a_resource { RedHandleArray value; } _s_7586bd4a_resource;
typedef struct _s_7586bd4a_offset { size_t value; } _s_7586bd4a_offset;
typedef struct _s_7586bd4a_device_ptr { RRDevicePtr* value; } _s_7586bd4a_device_ptr;
static inline _s_7586bd4a_context _7586bd4a_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_7586bd4a_context){value}; }
static inline _s_7586bd4a_resource _7586bd4a_resource(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_7586bd4a_resource){value}; }
static inline _s_7586bd4a_offset _7586bd4a_offset(size_t value) { return REDGPU_NP_STRUCT_INIT(_s_7586bd4a_offset){value}; }
static inline _s_7586bd4a_device_ptr _7586bd4a_device_ptr(RRDevicePtr* value) { return REDGPU_NP_STRUCT_INIT(_s_7586bd4a_device_ptr){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetDevicePtrFromVkBuffer(_s_7586bd4a_context context, _s_7586bd4a_resource resource, _s_7586bd4a_offset offset, _s_7586bd4a_device_ptr device_ptr) {
  return rrGetDevicePtrFromVkBuffer(context.value, resource.value, offset.value, device_ptr.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrCreateContextVk rrCreateContextVk
#define _3649d9fd_api_version(value) value
#define _3649d9fd_device(value) value
#define _3649d9fd_physical_device(value) value
#define _3649d9fd_command_queue(value) value
#define _3649d9fd_queue_family_index(value) value
#define _3649d9fd_context(value) value
#else
typedef struct _s_3649d9fd_api_version { uint32_t value; } _s_3649d9fd_api_version;
typedef struct _s_3649d9fd_device { RedHandleGpu value; } _s_3649d9fd_device;
typedef struct _s_3649d9fd_physical_device { RedHandleGpuDevice value; } _s_3649d9fd_physical_device;
typedef struct _s_3649d9fd_command_queue { RedHandleQueue value; } _s_3649d9fd_command_queue;
typedef struct _s_3649d9fd_queue_family_index { uint32_t value; } _s_3649d9fd_queue_family_index;
typedef struct _s_3649d9fd_context { RRContext* value; } _s_3649d9fd_context;
static inline _s_3649d9fd_api_version _3649d9fd_api_version(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_3649d9fd_api_version){value}; }
static inline _s_3649d9fd_device _3649d9fd_device(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_3649d9fd_device){value}; }
static inline _s_3649d9fd_physical_device _3649d9fd_physical_device(RedHandleGpuDevice value) { return REDGPU_NP_STRUCT_INIT(_s_3649d9fd_physical_device){value}; }
static inline _s_3649d9fd_command_queue _3649d9fd_command_queue(RedHandleQueue value) { return REDGPU_NP_STRUCT_INIT(_s_3649d9fd_command_queue){value}; }
static inline _s_3649d9fd_queue_family_index _3649d9fd_queue_family_index(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_3649d9fd_queue_family_index){value}; }
static inline _s_3649d9fd_context _3649d9fd_context(RRContext* value) { return REDGPU_NP_STRUCT_INIT(_s_3649d9fd_context){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrCreateContextVk(_s_3649d9fd_api_version api_version, _s_3649d9fd_device device, _s_3649d9fd_physical_device physical_device, _s_3649d9fd_command_queue command_queue, _s_3649d9fd_queue_family_index queue_family_index, _s_3649d9fd_context context) {
  return rrCreateContextVk(api_version.value, device.value, physical_device.value, command_queue.value, queue_family_index.value, context.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetCommandStreamFromVkCommandBuffer rrGetCommandStreamFromVkCommandBuffer
#define _9fb15427_context(value) value
#define _9fb15427_command_buffer(value) value
#define _9fb15427_command_stream(value) value
#else
typedef struct _s_9fb15427_context { RRContext value; } _s_9fb15427_context;
typedef struct _s_9fb15427_command_buffer { RedHandleCalls value; } _s_9fb15427_command_buffer;
typedef struct _s_9fb15427_command_stream { RRCommandStream* value; } _s_9fb15427_command_stream;
static inline _s_9fb15427_context _9fb15427_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_9fb15427_context){value}; }
static inline _s_9fb15427_command_buffer _9fb15427_command_buffer(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_9fb15427_command_buffer){value}; }
static inline _s_9fb15427_command_stream _9fb15427_command_stream(RRCommandStream* value) { return REDGPU_NP_STRUCT_INIT(_s_9fb15427_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetCommandStreamFromVkCommandBuffer(_s_9fb15427_context context, _s_9fb15427_command_buffer command_buffer, _s_9fb15427_command_stream command_stream) {
  return rrGetCommandStreamFromVkCommandBuffer(context.value, command_buffer.value, command_stream.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrAllocateDeviceBuffer rrAllocateDeviceBuffer
#define _9d6e0c3f_context(value) value
#define _9d6e0c3f_size(value) value
#define _9d6e0c3f_device_ptr(value) value
#else
typedef struct _s_9d6e0c3f_context { RRContext value; } _s_9d6e0c3f_context;
typedef struct _s_9d6e0c3f_size { size_t value; } _s_9d6e0c3f_size;
typedef struct _s_9d6e0c3f_device_ptr { RRDevicePtr* value; } _s_9d6e0c3f_device_ptr;
static inline _s_9d6e0c3f_context _9d6e0c3f_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_9d6e0c3f_context){value}; }
static inline _s_9d6e0c3f_size _9d6e0c3f_size(size_t value) { return REDGPU_NP_STRUCT_INIT(_s_9d6e0c3f_size){value}; }
static inline _s_9d6e0c3f_device_ptr _9d6e0c3f_device_ptr(RRDevicePtr* value) { return REDGPU_NP_STRUCT_INIT(_s_9d6e0c3f_device_ptr){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrAllocateDeviceBuffer(_s_9d6e0c3f_context context, _s_9d6e0c3f_size size, _s_9d6e0c3f_device_ptr device_ptr) {
  return rrAllocateDeviceBuffer(context.value, size.value, device_ptr.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrMapDevicePtr rrMapDevicePtr
#define _9147c399_context(value) value
#define _9147c399_device_ptr(value) value
#define _9147c399_mapping_ptr(value) value
#else
typedef struct _s_9147c399_context { RRContext value; } _s_9147c399_context;
typedef struct _s_9147c399_device_ptr { RRDevicePtr value; } _s_9147c399_device_ptr;
typedef struct _s_9147c399_mapping_ptr { void** value; } _s_9147c399_mapping_ptr;
static inline _s_9147c399_context _9147c399_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_9147c399_context){value}; }
static inline _s_9147c399_device_ptr _9147c399_device_ptr(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_9147c399_device_ptr){value}; }
static inline _s_9147c399_mapping_ptr _9147c399_mapping_ptr(void** value) { return REDGPU_NP_STRUCT_INIT(_s_9147c399_mapping_ptr){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrMapDevicePtr(_s_9147c399_context context, _s_9147c399_device_ptr device_ptr, _s_9147c399_mapping_ptr mapping_ptr) {
  return rrMapDevicePtr(context.value, device_ptr.value, mapping_ptr.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrUnmapDevicePtr rrUnmapDevicePtr
#define _1f75d004_context(value) value
#define _1f75d004_device_ptr(value) value
#define _1f75d004_mapping_ptr(value) value
#else
typedef struct _s_1f75d004_context { RRContext value; } _s_1f75d004_context;
typedef struct _s_1f75d004_device_ptr { RRDevicePtr value; } _s_1f75d004_device_ptr;
typedef struct _s_1f75d004_mapping_ptr { void** value; } _s_1f75d004_mapping_ptr;
static inline _s_1f75d004_context _1f75d004_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_1f75d004_context){value}; }
static inline _s_1f75d004_device_ptr _1f75d004_device_ptr(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_1f75d004_device_ptr){value}; }
static inline _s_1f75d004_mapping_ptr _1f75d004_mapping_ptr(void** value) { return REDGPU_NP_STRUCT_INIT(_s_1f75d004_mapping_ptr){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrUnmapDevicePtr(_s_1f75d004_context context, _s_1f75d004_device_ptr device_ptr, _s_1f75d004_mapping_ptr mapping_ptr) {
  return rrUnmapDevicePtr(context.value, device_ptr.value, mapping_ptr.value);
}
#endif

