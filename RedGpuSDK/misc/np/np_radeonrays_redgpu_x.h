#pragma once

#ifndef REDGPU_NP_STRUCT_INIT
#ifdef __cplusplus
#define REDGPU_NP_STRUCT_INIT(x) x
#else
#define REDGPU_NP_STRUCT_INIT(x) (x)
#endif
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetDevicePtrFromD3D12Resource rrGetDevicePtrFromD3D12Resource
#define _78b3204b_context(value) value
#define _78b3204b_resource(value) value
#define _78b3204b_offset(value) value
#define _78b3204b_device_ptr(value) value
#else
typedef struct _s_78b3204b_context { RRContext value; } _s_78b3204b_context;
typedef struct _s_78b3204b_resource { ID3D12Resource* value; } _s_78b3204b_resource;
typedef struct _s_78b3204b_offset { size_t value; } _s_78b3204b_offset;
typedef struct _s_78b3204b_device_ptr { RRDevicePtr* value; } _s_78b3204b_device_ptr;
static inline _s_78b3204b_context _78b3204b_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_78b3204b_context){value}; }
static inline _s_78b3204b_resource _78b3204b_resource(ID3D12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_78b3204b_resource){value}; }
static inline _s_78b3204b_offset _78b3204b_offset(size_t value) { return REDGPU_NP_STRUCT_INIT(_s_78b3204b_offset){value}; }
static inline _s_78b3204b_device_ptr _78b3204b_device_ptr(RRDevicePtr* value) { return REDGPU_NP_STRUCT_INIT(_s_78b3204b_device_ptr){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetDevicePtrFromD3D12Resource(_s_78b3204b_context context, _s_78b3204b_resource resource, _s_78b3204b_offset offset, _s_78b3204b_device_ptr device_ptr) {
  return rrGetDevicePtrFromD3D12Resource(context.value, resource.value, offset.value, device_ptr.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrCreateContextDX rrCreateContextDX
#define _3c48e4b2_api_version(value) value
#define _3c48e4b2_d3d_device(value) value
#define _3c48e4b2_command_queue(value) value
#define _3c48e4b2_context(value) value
#else
typedef struct _s_3c48e4b2_api_version { uint32_t value; } _s_3c48e4b2_api_version;
typedef struct _s_3c48e4b2_d3d_device { ID3D12Device* value; } _s_3c48e4b2_d3d_device;
typedef struct _s_3c48e4b2_command_queue { ID3D12CommandQueue* value; } _s_3c48e4b2_command_queue;
typedef struct _s_3c48e4b2_context { RRContext* value; } _s_3c48e4b2_context;
static inline _s_3c48e4b2_api_version _3c48e4b2_api_version(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_3c48e4b2_api_version){value}; }
static inline _s_3c48e4b2_d3d_device _3c48e4b2_d3d_device(ID3D12Device* value) { return REDGPU_NP_STRUCT_INIT(_s_3c48e4b2_d3d_device){value}; }
static inline _s_3c48e4b2_command_queue _3c48e4b2_command_queue(ID3D12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_3c48e4b2_command_queue){value}; }
static inline _s_3c48e4b2_context _3c48e4b2_context(RRContext* value) { return REDGPU_NP_STRUCT_INIT(_s_3c48e4b2_context){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrCreateContextDX(_s_3c48e4b2_api_version api_version, _s_3c48e4b2_d3d_device d3d_device, _s_3c48e4b2_command_queue command_queue, _s_3c48e4b2_context context) {
  return rrCreateContextDX(api_version.value, d3d_device.value, command_queue.value, context.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetCommandStreamFromD3D12CommandList rrGetCommandStreamFromD3D12CommandList
#define _bf44cf0e_context(value) value
#define _bf44cf0e_command_list(value) value
#define _bf44cf0e_command_stream(value) value
#else
typedef struct _s_bf44cf0e_context { RRContext value; } _s_bf44cf0e_context;
typedef struct _s_bf44cf0e_command_list { ID3D12GraphicsCommandList* value; } _s_bf44cf0e_command_list;
typedef struct _s_bf44cf0e_command_stream { RRCommandStream* value; } _s_bf44cf0e_command_stream;
static inline _s_bf44cf0e_context _bf44cf0e_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_bf44cf0e_context){value}; }
static inline _s_bf44cf0e_command_list _bf44cf0e_command_list(ID3D12GraphicsCommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_bf44cf0e_command_list){value}; }
static inline _s_bf44cf0e_command_stream _bf44cf0e_command_stream(RRCommandStream* value) { return REDGPU_NP_STRUCT_INIT(_s_bf44cf0e_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetCommandStreamFromD3D12CommandList(_s_bf44cf0e_context context, _s_bf44cf0e_command_list command_list, _s_bf44cf0e_command_stream command_stream) {
  return rrGetCommandStreamFromD3D12CommandList(context.value, command_list.value, command_stream.value);
}
#endif

