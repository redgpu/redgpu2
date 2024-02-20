#pragma once

#ifndef REDGPU_NP_STRUCT_INIT
#ifdef __cplusplus
#define REDGPU_NP_STRUCT_INIT(x) x
#else
#define REDGPU_NP_STRUCT_INIT(x) (x)
#endif
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrCreateContext rrCreateContext
#define _152db25d_api_version(value) value
#define _152db25d_api(value) value
#define _152db25d_context(value) value
#else
typedef struct _s_152db25d_api_version { uint32_t value; } _s_152db25d_api_version;
typedef struct _s_152db25d_api { RRApi value; } _s_152db25d_api;
typedef struct _s_152db25d_context { RRContext* value; } _s_152db25d_context;
static inline _s_152db25d_api_version _152db25d_api_version(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_152db25d_api_version){value}; }
static inline _s_152db25d_api _152db25d_api(RRApi value) { return REDGPU_NP_STRUCT_INIT(_s_152db25d_api){value}; }
static inline _s_152db25d_context _152db25d_context(RRContext* value) { return REDGPU_NP_STRUCT_INIT(_s_152db25d_context){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrCreateContext(_s_152db25d_api_version api_version, _s_152db25d_api api, _s_152db25d_context context) {
  return rrCreateContext(api_version.value, api.value, context.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrDestroyContext rrDestroyContext
#define _44dff8d4_context(value) value
#else
typedef struct _s_44dff8d4_context { RRContext value; } _s_44dff8d4_context;
static inline _s_44dff8d4_context _44dff8d4_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_44dff8d4_context){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrDestroyContext(_s_44dff8d4_context context) {
  return rrDestroyContext(context.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrSetLogLevel rrSetLogLevel
#define _99db5dc1_log_level(value) value
#else
typedef struct _s_99db5dc1_log_level { RRLogLevel value; } _s_99db5dc1_log_level;
static inline _s_99db5dc1_log_level _99db5dc1_log_level(RRLogLevel value) { return REDGPU_NP_STRUCT_INIT(_s_99db5dc1_log_level){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrSetLogLevel(_s_99db5dc1_log_level log_level) {
  return rrSetLogLevel(log_level.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrSetLogFile rrSetLogFile
#define _12b7f4b1_filename(value) value
#else
typedef struct _s_12b7f4b1_filename { char* value; } _s_12b7f4b1_filename;
static inline _s_12b7f4b1_filename _12b7f4b1_filename(char* value) { return REDGPU_NP_STRUCT_INIT(_s_12b7f4b1_filename){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrSetLogFile(_s_12b7f4b1_filename filename) {
  return rrSetLogFile(filename.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrCmdBuildGeometry rrCmdBuildGeometry
#define _9de40314_context(value) value
#define _9de40314_build_operation(value) value
#define _9de40314_build_input(value) value
#define _9de40314_build_options(value) value
#define _9de40314_temporary_buffer(value) value
#define _9de40314_geometry_buffer(value) value
#define _9de40314_command_stream(value) value
#else
typedef struct _s_9de40314_context { RRContext value; } _s_9de40314_context;
typedef struct _s_9de40314_build_operation { RRBuildOperation value; } _s_9de40314_build_operation;
typedef struct _s_9de40314_build_input { RRGeometryBuildInput* value; } _s_9de40314_build_input;
typedef struct _s_9de40314_build_options { RRBuildOptions* value; } _s_9de40314_build_options;
typedef struct _s_9de40314_temporary_buffer { RRDevicePtr value; } _s_9de40314_temporary_buffer;
typedef struct _s_9de40314_geometry_buffer { RRDevicePtr value; } _s_9de40314_geometry_buffer;
typedef struct _s_9de40314_command_stream { RRCommandStream value; } _s_9de40314_command_stream;
static inline _s_9de40314_context _9de40314_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_9de40314_context){value}; }
static inline _s_9de40314_build_operation _9de40314_build_operation(RRBuildOperation value) { return REDGPU_NP_STRUCT_INIT(_s_9de40314_build_operation){value}; }
static inline _s_9de40314_build_input _9de40314_build_input(RRGeometryBuildInput* value) { return REDGPU_NP_STRUCT_INIT(_s_9de40314_build_input){value}; }
static inline _s_9de40314_build_options _9de40314_build_options(RRBuildOptions* value) { return REDGPU_NP_STRUCT_INIT(_s_9de40314_build_options){value}; }
static inline _s_9de40314_temporary_buffer _9de40314_temporary_buffer(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_9de40314_temporary_buffer){value}; }
static inline _s_9de40314_geometry_buffer _9de40314_geometry_buffer(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_9de40314_geometry_buffer){value}; }
static inline _s_9de40314_command_stream _9de40314_command_stream(RRCommandStream value) { return REDGPU_NP_STRUCT_INIT(_s_9de40314_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrCmdBuildGeometry(_s_9de40314_context context, _s_9de40314_build_operation build_operation, _s_9de40314_build_input build_input, _s_9de40314_build_options build_options, _s_9de40314_temporary_buffer temporary_buffer, _s_9de40314_geometry_buffer geometry_buffer, _s_9de40314_command_stream command_stream) {
  return rrCmdBuildGeometry(context.value, build_operation.value, build_input.value, build_options.value, temporary_buffer.value, geometry_buffer.value, command_stream.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetGeometryBuildMemoryRequirements rrGetGeometryBuildMemoryRequirements
#define _7f4671b0_context(value) value
#define _7f4671b0_build_input(value) value
#define _7f4671b0_build_options(value) value
#define _7f4671b0_memory_requirements(value) value
#else
typedef struct _s_7f4671b0_context { RRContext value; } _s_7f4671b0_context;
typedef struct _s_7f4671b0_build_input { RRGeometryBuildInput* value; } _s_7f4671b0_build_input;
typedef struct _s_7f4671b0_build_options { RRBuildOptions* value; } _s_7f4671b0_build_options;
typedef struct _s_7f4671b0_memory_requirements { RRMemoryRequirements* value; } _s_7f4671b0_memory_requirements;
static inline _s_7f4671b0_context _7f4671b0_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_7f4671b0_context){value}; }
static inline _s_7f4671b0_build_input _7f4671b0_build_input(RRGeometryBuildInput* value) { return REDGPU_NP_STRUCT_INIT(_s_7f4671b0_build_input){value}; }
static inline _s_7f4671b0_build_options _7f4671b0_build_options(RRBuildOptions* value) { return REDGPU_NP_STRUCT_INIT(_s_7f4671b0_build_options){value}; }
static inline _s_7f4671b0_memory_requirements _7f4671b0_memory_requirements(RRMemoryRequirements* value) { return REDGPU_NP_STRUCT_INIT(_s_7f4671b0_memory_requirements){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetGeometryBuildMemoryRequirements(_s_7f4671b0_context context, _s_7f4671b0_build_input build_input, _s_7f4671b0_build_options build_options, _s_7f4671b0_memory_requirements memory_requirements) {
  return rrGetGeometryBuildMemoryRequirements(context.value, build_input.value, build_options.value, memory_requirements.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrCmdBuildScene rrCmdBuildScene
#define _a8bf5716_context(value) value
#define _a8bf5716_build_input(value) value
#define _a8bf5716_build_options(value) value
#define _a8bf5716_temporary_buffer(value) value
#define _a8bf5716_scene_buffer(value) value
#define _a8bf5716_command_stream(value) value
#else
typedef struct _s_a8bf5716_context { RRContext value; } _s_a8bf5716_context;
typedef struct _s_a8bf5716_build_input { RRSceneBuildInput* value; } _s_a8bf5716_build_input;
typedef struct _s_a8bf5716_build_options { RRBuildOptions* value; } _s_a8bf5716_build_options;
typedef struct _s_a8bf5716_temporary_buffer { RRDevicePtr value; } _s_a8bf5716_temporary_buffer;
typedef struct _s_a8bf5716_scene_buffer { RRDevicePtr value; } _s_a8bf5716_scene_buffer;
typedef struct _s_a8bf5716_command_stream { RRCommandStream value; } _s_a8bf5716_command_stream;
static inline _s_a8bf5716_context _a8bf5716_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_a8bf5716_context){value}; }
static inline _s_a8bf5716_build_input _a8bf5716_build_input(RRSceneBuildInput* value) { return REDGPU_NP_STRUCT_INIT(_s_a8bf5716_build_input){value}; }
static inline _s_a8bf5716_build_options _a8bf5716_build_options(RRBuildOptions* value) { return REDGPU_NP_STRUCT_INIT(_s_a8bf5716_build_options){value}; }
static inline _s_a8bf5716_temporary_buffer _a8bf5716_temporary_buffer(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_a8bf5716_temporary_buffer){value}; }
static inline _s_a8bf5716_scene_buffer _a8bf5716_scene_buffer(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_a8bf5716_scene_buffer){value}; }
static inline _s_a8bf5716_command_stream _a8bf5716_command_stream(RRCommandStream value) { return REDGPU_NP_STRUCT_INIT(_s_a8bf5716_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrCmdBuildScene(_s_a8bf5716_context context, _s_a8bf5716_build_input build_input, _s_a8bf5716_build_options build_options, _s_a8bf5716_temporary_buffer temporary_buffer, _s_a8bf5716_scene_buffer scene_buffer, _s_a8bf5716_command_stream command_stream) {
  return rrCmdBuildScene(context.value, build_input.value, build_options.value, temporary_buffer.value, scene_buffer.value, command_stream.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetSceneBuildMemoryRequirements rrGetSceneBuildMemoryRequirements
#define _acd909a9_context(value) value
#define _acd909a9_build_input(value) value
#define _acd909a9_build_options(value) value
#define _acd909a9_memory_requirements(value) value
#else
typedef struct _s_acd909a9_context { RRContext value; } _s_acd909a9_context;
typedef struct _s_acd909a9_build_input { RRSceneBuildInput* value; } _s_acd909a9_build_input;
typedef struct _s_acd909a9_build_options { RRBuildOptions* value; } _s_acd909a9_build_options;
typedef struct _s_acd909a9_memory_requirements { RRMemoryRequirements* value; } _s_acd909a9_memory_requirements;
static inline _s_acd909a9_context _acd909a9_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_acd909a9_context){value}; }
static inline _s_acd909a9_build_input _acd909a9_build_input(RRSceneBuildInput* value) { return REDGPU_NP_STRUCT_INIT(_s_acd909a9_build_input){value}; }
static inline _s_acd909a9_build_options _acd909a9_build_options(RRBuildOptions* value) { return REDGPU_NP_STRUCT_INIT(_s_acd909a9_build_options){value}; }
static inline _s_acd909a9_memory_requirements _acd909a9_memory_requirements(RRMemoryRequirements* value) { return REDGPU_NP_STRUCT_INIT(_s_acd909a9_memory_requirements){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetSceneBuildMemoryRequirements(_s_acd909a9_context context, _s_acd909a9_build_input build_input, _s_acd909a9_build_options build_options, _s_acd909a9_memory_requirements memory_requirements) {
  return rrGetSceneBuildMemoryRequirements(context.value, build_input.value, build_options.value, memory_requirements.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrCmdIntersect rrCmdIntersect
#define _68d6beb2_context(value) value
#define _68d6beb2_scene_buffer(value) value
#define _68d6beb2_query(value) value
#define _68d6beb2_rays(value) value
#define _68d6beb2_ray_count(value) value
#define _68d6beb2_indirect_ray_count(value) value
#define _68d6beb2_query_output(value) value
#define _68d6beb2_hits(value) value
#define _68d6beb2_scratch(value) value
#define _68d6beb2_command_stream(value) value
#else
typedef struct _s_68d6beb2_context { RRContext value; } _s_68d6beb2_context;
typedef struct _s_68d6beb2_scene_buffer { RRDevicePtr value; } _s_68d6beb2_scene_buffer;
typedef struct _s_68d6beb2_query { RRIntersectQuery value; } _s_68d6beb2_query;
typedef struct _s_68d6beb2_rays { RRDevicePtr value; } _s_68d6beb2_rays;
typedef struct _s_68d6beb2_ray_count { uint32_t value; } _s_68d6beb2_ray_count;
typedef struct _s_68d6beb2_indirect_ray_count { RRDevicePtr value; } _s_68d6beb2_indirect_ray_count;
typedef struct _s_68d6beb2_query_output { RRIntersectQueryOutput value; } _s_68d6beb2_query_output;
typedef struct _s_68d6beb2_hits { RRDevicePtr value; } _s_68d6beb2_hits;
typedef struct _s_68d6beb2_scratch { RRDevicePtr value; } _s_68d6beb2_scratch;
typedef struct _s_68d6beb2_command_stream { RRCommandStream value; } _s_68d6beb2_command_stream;
static inline _s_68d6beb2_context _68d6beb2_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_68d6beb2_context){value}; }
static inline _s_68d6beb2_scene_buffer _68d6beb2_scene_buffer(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_68d6beb2_scene_buffer){value}; }
static inline _s_68d6beb2_query _68d6beb2_query(RRIntersectQuery value) { return REDGPU_NP_STRUCT_INIT(_s_68d6beb2_query){value}; }
static inline _s_68d6beb2_rays _68d6beb2_rays(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_68d6beb2_rays){value}; }
static inline _s_68d6beb2_ray_count _68d6beb2_ray_count(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_68d6beb2_ray_count){value}; }
static inline _s_68d6beb2_indirect_ray_count _68d6beb2_indirect_ray_count(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_68d6beb2_indirect_ray_count){value}; }
static inline _s_68d6beb2_query_output _68d6beb2_query_output(RRIntersectQueryOutput value) { return REDGPU_NP_STRUCT_INIT(_s_68d6beb2_query_output){value}; }
static inline _s_68d6beb2_hits _68d6beb2_hits(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_68d6beb2_hits){value}; }
static inline _s_68d6beb2_scratch _68d6beb2_scratch(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_68d6beb2_scratch){value}; }
static inline _s_68d6beb2_command_stream _68d6beb2_command_stream(RRCommandStream value) { return REDGPU_NP_STRUCT_INIT(_s_68d6beb2_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrCmdIntersect(_s_68d6beb2_context context, _s_68d6beb2_scene_buffer scene_buffer, _s_68d6beb2_query query, _s_68d6beb2_rays rays, _s_68d6beb2_ray_count ray_count, _s_68d6beb2_indirect_ray_count indirect_ray_count, _s_68d6beb2_query_output query_output, _s_68d6beb2_hits hits, _s_68d6beb2_scratch scratch, _s_68d6beb2_command_stream command_stream) {
  return rrCmdIntersect(context.value, scene_buffer.value, query.value, rays.value, ray_count.value, indirect_ray_count.value, query_output.value, hits.value, scratch.value, command_stream.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetTraceMemoryRequirements rrGetTraceMemoryRequirements
#define _df95045b_context(value) value
#define _df95045b_ray_count(value) value
#define _df95045b_scratch_size(value) value
#else
typedef struct _s_df95045b_context { RRContext value; } _s_df95045b_context;
typedef struct _s_df95045b_ray_count { uint32_t value; } _s_df95045b_ray_count;
typedef struct _s_df95045b_scratch_size { size_t* value; } _s_df95045b_scratch_size;
static inline _s_df95045b_context _df95045b_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_df95045b_context){value}; }
static inline _s_df95045b_ray_count _df95045b_ray_count(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_df95045b_ray_count){value}; }
static inline _s_df95045b_scratch_size _df95045b_scratch_size(size_t* value) { return REDGPU_NP_STRUCT_INIT(_s_df95045b_scratch_size){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetTraceMemoryRequirements(_s_df95045b_context context, _s_df95045b_ray_count ray_count, _s_df95045b_scratch_size scratch_size) {
  return rrGetTraceMemoryRequirements(context.value, ray_count.value, scratch_size.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrAllocateCommandStream rrAllocateCommandStream
#define _c1a18b72_context(value) value
#define _c1a18b72_command_stream(value) value
#else
typedef struct _s_c1a18b72_context { RRContext value; } _s_c1a18b72_context;
typedef struct _s_c1a18b72_command_stream { RRCommandStream* value; } _s_c1a18b72_command_stream;
static inline _s_c1a18b72_context _c1a18b72_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_c1a18b72_context){value}; }
static inline _s_c1a18b72_command_stream _c1a18b72_command_stream(RRCommandStream* value) { return REDGPU_NP_STRUCT_INIT(_s_c1a18b72_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrAllocateCommandStream(_s_c1a18b72_context context, _s_c1a18b72_command_stream command_stream) {
  return rrAllocateCommandStream(context.value, command_stream.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrReleaseCommandStream rrReleaseCommandStream
#define _74c7d604_context(value) value
#define _74c7d604_command_stream(value) value
#else
typedef struct _s_74c7d604_context { RRContext value; } _s_74c7d604_context;
typedef struct _s_74c7d604_command_stream { RRCommandStream value; } _s_74c7d604_command_stream;
static inline _s_74c7d604_context _74c7d604_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_74c7d604_context){value}; }
static inline _s_74c7d604_command_stream _74c7d604_command_stream(RRCommandStream value) { return REDGPU_NP_STRUCT_INIT(_s_74c7d604_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrReleaseCommandStream(_s_74c7d604_context context, _s_74c7d604_command_stream command_stream) {
  return rrReleaseCommandStream(context.value, command_stream.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrSumbitCommandStream rrSumbitCommandStream
#define _fdaac5d9_context(value) value
#define _fdaac5d9_command_stream(value) value
#define _fdaac5d9_wait_event(value) value
#define _fdaac5d9_out_event(value) value
#else
typedef struct _s_fdaac5d9_context { RRContext value; } _s_fdaac5d9_context;
typedef struct _s_fdaac5d9_command_stream { RRCommandStream value; } _s_fdaac5d9_command_stream;
typedef struct _s_fdaac5d9_wait_event { RREvent value; } _s_fdaac5d9_wait_event;
typedef struct _s_fdaac5d9_out_event { RREvent* value; } _s_fdaac5d9_out_event;
static inline _s_fdaac5d9_context _fdaac5d9_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_fdaac5d9_context){value}; }
static inline _s_fdaac5d9_command_stream _fdaac5d9_command_stream(RRCommandStream value) { return REDGPU_NP_STRUCT_INIT(_s_fdaac5d9_command_stream){value}; }
static inline _s_fdaac5d9_wait_event _fdaac5d9_wait_event(RREvent value) { return REDGPU_NP_STRUCT_INIT(_s_fdaac5d9_wait_event){value}; }
static inline _s_fdaac5d9_out_event _fdaac5d9_out_event(RREvent* value) { return REDGPU_NP_STRUCT_INIT(_s_fdaac5d9_out_event){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrSumbitCommandStream(_s_fdaac5d9_context context, _s_fdaac5d9_command_stream command_stream, _s_fdaac5d9_wait_event wait_event, _s_fdaac5d9_out_event out_event) {
  return rrSumbitCommandStream(context.value, command_stream.value, wait_event.value, out_event.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrReleaseEvent rrReleaseEvent
#define _46e5a406_context(value) value
#define _46e5a406_event(value) value
#else
typedef struct _s_46e5a406_context { RRContext value; } _s_46e5a406_context;
typedef struct _s_46e5a406_event { RREvent value; } _s_46e5a406_event;
static inline _s_46e5a406_context _46e5a406_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_46e5a406_context){value}; }
static inline _s_46e5a406_event _46e5a406_event(RREvent value) { return REDGPU_NP_STRUCT_INIT(_s_46e5a406_event){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrReleaseEvent(_s_46e5a406_context context, _s_46e5a406_event event) {
  return rrReleaseEvent(context.value, event.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrWaitEvent rrWaitEvent
#define _5a7d6e0d_context(value) value
#define _5a7d6e0d_event(value) value
#else
typedef struct _s_5a7d6e0d_context { RRContext value; } _s_5a7d6e0d_context;
typedef struct _s_5a7d6e0d_event { RREvent value; } _s_5a7d6e0d_event;
static inline _s_5a7d6e0d_context _5a7d6e0d_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_5a7d6e0d_context){value}; }
static inline _s_5a7d6e0d_event _5a7d6e0d_event(RREvent value) { return REDGPU_NP_STRUCT_INIT(_s_5a7d6e0d_event){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrWaitEvent(_s_5a7d6e0d_context context, _s_5a7d6e0d_event event) {
  return rrWaitEvent(context.value, event.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrReleaseDevicePtr rrReleaseDevicePtr
#define _2c502541_context(value) value
#define _2c502541_ptr(value) value
#else
typedef struct _s_2c502541_context { RRContext value; } _s_2c502541_context;
typedef struct _s_2c502541_ptr { RRDevicePtr value; } _s_2c502541_ptr;
static inline _s_2c502541_context _2c502541_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_2c502541_context){value}; }
static inline _s_2c502541_ptr _2c502541_ptr(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_2c502541_ptr){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrReleaseDevicePtr(_s_2c502541_context context, _s_2c502541_ptr ptr) {
  return rrReleaseDevicePtr(context.value, ptr.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrReleaseExternalCommandStream rrReleaseExternalCommandStream
#define _3ecf4988_context(value) value
#define _3ecf4988_command_stream(value) value
#else
typedef struct _s_3ecf4988_context { RRContext value; } _s_3ecf4988_context;
typedef struct _s_3ecf4988_command_stream { RRCommandStream value; } _s_3ecf4988_command_stream;
static inline _s_3ecf4988_context _3ecf4988_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_3ecf4988_context){value}; }
static inline _s_3ecf4988_command_stream _3ecf4988_command_stream(RRCommandStream value) { return REDGPU_NP_STRUCT_INIT(_s_3ecf4988_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrReleaseExternalCommandStream(_s_3ecf4988_context context, _s_3ecf4988_command_stream command_stream) {
  return rrReleaseExternalCommandStream(context.value, command_stream.value);
}
#endif

