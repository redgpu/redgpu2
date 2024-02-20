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
#define np_rrGetDevicePtrFromD3D12Resource rrGetDevicePtrFromD3D12Resource
#define _46f8f610_context(value) value
#define _46f8f610_resource(value) value
#define _46f8f610_offset(value) value
#define _46f8f610_device_ptr(value) value
#else
typedef struct _s_46f8f610_context { RRContext value; } _s_46f8f610_context;
typedef struct _s_46f8f610_resource { ID3D12Resource* value; } _s_46f8f610_resource;
typedef struct _s_46f8f610_offset { size_t value; } _s_46f8f610_offset;
typedef struct _s_46f8f610_device_ptr { RRDevicePtr* value; } _s_46f8f610_device_ptr;
static inline _s_46f8f610_context _46f8f610_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_46f8f610_context){value}; }
static inline _s_46f8f610_resource _46f8f610_resource(ID3D12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_46f8f610_resource){value}; }
static inline _s_46f8f610_offset _46f8f610_offset(size_t value) { return REDGPU_NP_STRUCT_INIT(_s_46f8f610_offset){value}; }
static inline _s_46f8f610_device_ptr _46f8f610_device_ptr(RRDevicePtr* value) { return REDGPU_NP_STRUCT_INIT(_s_46f8f610_device_ptr){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetDevicePtrFromD3D12Resource(_s_46f8f610_context context, _s_46f8f610_resource resource, _s_46f8f610_offset offset, _s_46f8f610_device_ptr device_ptr) {
  return rrGetDevicePtrFromD3D12Resource(context.value, resource.value, offset.value, device_ptr.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrCreateContextDX rrCreateContextDX
#define _4339579d_api_version(value) value
#define _4339579d_d3d_device(value) value
#define _4339579d_command_queue(value) value
#define _4339579d_context(value) value
#else
typedef struct _s_4339579d_api_version { uint32_t value; } _s_4339579d_api_version;
typedef struct _s_4339579d_d3d_device { ID3D12Device* value; } _s_4339579d_d3d_device;
typedef struct _s_4339579d_command_queue { ID3D12CommandQueue* value; } _s_4339579d_command_queue;
typedef struct _s_4339579d_context { RRContext* value; } _s_4339579d_context;
static inline _s_4339579d_api_version _4339579d_api_version(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_4339579d_api_version){value}; }
static inline _s_4339579d_d3d_device _4339579d_d3d_device(ID3D12Device* value) { return REDGPU_NP_STRUCT_INIT(_s_4339579d_d3d_device){value}; }
static inline _s_4339579d_command_queue _4339579d_command_queue(ID3D12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_4339579d_command_queue){value}; }
static inline _s_4339579d_context _4339579d_context(RRContext* value) { return REDGPU_NP_STRUCT_INIT(_s_4339579d_context){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrCreateContextDX(_s_4339579d_api_version api_version, _s_4339579d_d3d_device d3d_device, _s_4339579d_command_queue command_queue, _s_4339579d_context context) {
  return rrCreateContextDX(api_version.value, d3d_device.value, command_queue.value, context.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetCommandStreamFromD3D12CommandList rrGetCommandStreamFromD3D12CommandList
#define _79041f48_context(value) value
#define _79041f48_command_list(value) value
#define _79041f48_command_stream(value) value
#else
typedef struct _s_79041f48_context { RRContext value; } _s_79041f48_context;
typedef struct _s_79041f48_command_list { ID3D12GraphicsCommandList* value; } _s_79041f48_command_list;
typedef struct _s_79041f48_command_stream { RRCommandStream* value; } _s_79041f48_command_stream;
static inline _s_79041f48_context _79041f48_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_79041f48_context){value}; }
static inline _s_79041f48_command_list _79041f48_command_list(ID3D12GraphicsCommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_79041f48_command_list){value}; }
static inline _s_79041f48_command_stream _79041f48_command_stream(RRCommandStream* value) { return REDGPU_NP_STRUCT_INIT(_s_79041f48_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetCommandStreamFromD3D12CommandList(_s_79041f48_context context, _s_79041f48_command_list command_list, _s_79041f48_command_stream command_stream) {
  return rrGetCommandStreamFromD3D12CommandList(context.value, command_list.value, command_stream.value);
}
#endif

