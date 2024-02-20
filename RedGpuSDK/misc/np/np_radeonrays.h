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
#define np_rrCreateContext rrCreateContext
#define _76477c39_api_version(value) value
#define _76477c39_api(value) value
#define _76477c39_context(value) value
#else
typedef struct _s_76477c39_api_version { uint32_t value; } _s_76477c39_api_version;
typedef struct _s_76477c39_api { RRApi value; } _s_76477c39_api;
typedef struct _s_76477c39_context { RRContext* value; } _s_76477c39_context;
static inline _s_76477c39_api_version _76477c39_api_version(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_76477c39_api_version){value}; }
static inline _s_76477c39_api _76477c39_api(RRApi value) { return REDGPU_NP_STRUCT_INIT(_s_76477c39_api){value}; }
static inline _s_76477c39_context _76477c39_context(RRContext* value) { return REDGPU_NP_STRUCT_INIT(_s_76477c39_context){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrCreateContext(_s_76477c39_api_version api_version, _s_76477c39_api api, _s_76477c39_context context) {
  return rrCreateContext(api_version.value, api.value, context.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrDestroyContext rrDestroyContext
#define _35c0b64a_context(value) value
#else
typedef struct _s_35c0b64a_context { RRContext value; } _s_35c0b64a_context;
static inline _s_35c0b64a_context _35c0b64a_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_35c0b64a_context){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrDestroyContext(_s_35c0b64a_context context) {
  return rrDestroyContext(context.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrSetLogLevel rrSetLogLevel
#define _9c179593_log_level(value) value
#else
typedef struct _s_9c179593_log_level { RRLogLevel value; } _s_9c179593_log_level;
static inline _s_9c179593_log_level _9c179593_log_level(RRLogLevel value) { return REDGPU_NP_STRUCT_INIT(_s_9c179593_log_level){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrSetLogLevel(_s_9c179593_log_level log_level) {
  return rrSetLogLevel(log_level.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrSetLogFile rrSetLogFile
#define _a3a56cb6_filename(value) value
#else
typedef struct _s_a3a56cb6_filename { char* value; } _s_a3a56cb6_filename;
static inline _s_a3a56cb6_filename _a3a56cb6_filename(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a3a56cb6_filename){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrSetLogFile(_s_a3a56cb6_filename filename) {
  return rrSetLogFile(filename.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrCmdBuildGeometry rrCmdBuildGeometry
#define _f627a18d_context(value) value
#define _f627a18d_build_operation(value) value
#define _f627a18d_build_input(value) value
#define _f627a18d_build_options(value) value
#define _f627a18d_temporary_buffer(value) value
#define _f627a18d_geometry_buffer(value) value
#define _f627a18d_command_stream(value) value
#else
typedef struct _s_f627a18d_context { RRContext value; } _s_f627a18d_context;
typedef struct _s_f627a18d_build_operation { RRBuildOperation value; } _s_f627a18d_build_operation;
typedef struct _s_f627a18d_build_input { RRGeometryBuildInput* value; } _s_f627a18d_build_input;
typedef struct _s_f627a18d_build_options { RRBuildOptions* value; } _s_f627a18d_build_options;
typedef struct _s_f627a18d_temporary_buffer { RRDevicePtr value; } _s_f627a18d_temporary_buffer;
typedef struct _s_f627a18d_geometry_buffer { RRDevicePtr value; } _s_f627a18d_geometry_buffer;
typedef struct _s_f627a18d_command_stream { RRCommandStream value; } _s_f627a18d_command_stream;
static inline _s_f627a18d_context _f627a18d_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_f627a18d_context){value}; }
static inline _s_f627a18d_build_operation _f627a18d_build_operation(RRBuildOperation value) { return REDGPU_NP_STRUCT_INIT(_s_f627a18d_build_operation){value}; }
static inline _s_f627a18d_build_input _f627a18d_build_input(RRGeometryBuildInput* value) { return REDGPU_NP_STRUCT_INIT(_s_f627a18d_build_input){value}; }
static inline _s_f627a18d_build_options _f627a18d_build_options(RRBuildOptions* value) { return REDGPU_NP_STRUCT_INIT(_s_f627a18d_build_options){value}; }
static inline _s_f627a18d_temporary_buffer _f627a18d_temporary_buffer(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_f627a18d_temporary_buffer){value}; }
static inline _s_f627a18d_geometry_buffer _f627a18d_geometry_buffer(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_f627a18d_geometry_buffer){value}; }
static inline _s_f627a18d_command_stream _f627a18d_command_stream(RRCommandStream value) { return REDGPU_NP_STRUCT_INIT(_s_f627a18d_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrCmdBuildGeometry(_s_f627a18d_context context, _s_f627a18d_build_operation build_operation, _s_f627a18d_build_input build_input, _s_f627a18d_build_options build_options, _s_f627a18d_temporary_buffer temporary_buffer, _s_f627a18d_geometry_buffer geometry_buffer, _s_f627a18d_command_stream command_stream) {
  return rrCmdBuildGeometry(context.value, build_operation.value, build_input.value, build_options.value, temporary_buffer.value, geometry_buffer.value, command_stream.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetGeometryBuildMemoryRequirements rrGetGeometryBuildMemoryRequirements
#define _04be2d30_context(value) value
#define _04be2d30_build_input(value) value
#define _04be2d30_build_options(value) value
#define _04be2d30_memory_requirements(value) value
#else
typedef struct _s_04be2d30_context { RRContext value; } _s_04be2d30_context;
typedef struct _s_04be2d30_build_input { RRGeometryBuildInput* value; } _s_04be2d30_build_input;
typedef struct _s_04be2d30_build_options { RRBuildOptions* value; } _s_04be2d30_build_options;
typedef struct _s_04be2d30_memory_requirements { RRMemoryRequirements* value; } _s_04be2d30_memory_requirements;
static inline _s_04be2d30_context _04be2d30_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_04be2d30_context){value}; }
static inline _s_04be2d30_build_input _04be2d30_build_input(RRGeometryBuildInput* value) { return REDGPU_NP_STRUCT_INIT(_s_04be2d30_build_input){value}; }
static inline _s_04be2d30_build_options _04be2d30_build_options(RRBuildOptions* value) { return REDGPU_NP_STRUCT_INIT(_s_04be2d30_build_options){value}; }
static inline _s_04be2d30_memory_requirements _04be2d30_memory_requirements(RRMemoryRequirements* value) { return REDGPU_NP_STRUCT_INIT(_s_04be2d30_memory_requirements){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetGeometryBuildMemoryRequirements(_s_04be2d30_context context, _s_04be2d30_build_input build_input, _s_04be2d30_build_options build_options, _s_04be2d30_memory_requirements memory_requirements) {
  return rrGetGeometryBuildMemoryRequirements(context.value, build_input.value, build_options.value, memory_requirements.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrCmdBuildScene rrCmdBuildScene
#define _e47f0f00_context(value) value
#define _e47f0f00_build_input(value) value
#define _e47f0f00_build_options(value) value
#define _e47f0f00_temporary_buffer(value) value
#define _e47f0f00_scene_buffer(value) value
#define _e47f0f00_command_stream(value) value
#else
typedef struct _s_e47f0f00_context { RRContext value; } _s_e47f0f00_context;
typedef struct _s_e47f0f00_build_input { RRSceneBuildInput* value; } _s_e47f0f00_build_input;
typedef struct _s_e47f0f00_build_options { RRBuildOptions* value; } _s_e47f0f00_build_options;
typedef struct _s_e47f0f00_temporary_buffer { RRDevicePtr value; } _s_e47f0f00_temporary_buffer;
typedef struct _s_e47f0f00_scene_buffer { RRDevicePtr value; } _s_e47f0f00_scene_buffer;
typedef struct _s_e47f0f00_command_stream { RRCommandStream value; } _s_e47f0f00_command_stream;
static inline _s_e47f0f00_context _e47f0f00_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_e47f0f00_context){value}; }
static inline _s_e47f0f00_build_input _e47f0f00_build_input(RRSceneBuildInput* value) { return REDGPU_NP_STRUCT_INIT(_s_e47f0f00_build_input){value}; }
static inline _s_e47f0f00_build_options _e47f0f00_build_options(RRBuildOptions* value) { return REDGPU_NP_STRUCT_INIT(_s_e47f0f00_build_options){value}; }
static inline _s_e47f0f00_temporary_buffer _e47f0f00_temporary_buffer(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_e47f0f00_temporary_buffer){value}; }
static inline _s_e47f0f00_scene_buffer _e47f0f00_scene_buffer(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_e47f0f00_scene_buffer){value}; }
static inline _s_e47f0f00_command_stream _e47f0f00_command_stream(RRCommandStream value) { return REDGPU_NP_STRUCT_INIT(_s_e47f0f00_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrCmdBuildScene(_s_e47f0f00_context context, _s_e47f0f00_build_input build_input, _s_e47f0f00_build_options build_options, _s_e47f0f00_temporary_buffer temporary_buffer, _s_e47f0f00_scene_buffer scene_buffer, _s_e47f0f00_command_stream command_stream) {
  return rrCmdBuildScene(context.value, build_input.value, build_options.value, temporary_buffer.value, scene_buffer.value, command_stream.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetSceneBuildMemoryRequirements rrGetSceneBuildMemoryRequirements
#define _abd56990_context(value) value
#define _abd56990_build_input(value) value
#define _abd56990_build_options(value) value
#define _abd56990_memory_requirements(value) value
#else
typedef struct _s_abd56990_context { RRContext value; } _s_abd56990_context;
typedef struct _s_abd56990_build_input { RRSceneBuildInput* value; } _s_abd56990_build_input;
typedef struct _s_abd56990_build_options { RRBuildOptions* value; } _s_abd56990_build_options;
typedef struct _s_abd56990_memory_requirements { RRMemoryRequirements* value; } _s_abd56990_memory_requirements;
static inline _s_abd56990_context _abd56990_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_abd56990_context){value}; }
static inline _s_abd56990_build_input _abd56990_build_input(RRSceneBuildInput* value) { return REDGPU_NP_STRUCT_INIT(_s_abd56990_build_input){value}; }
static inline _s_abd56990_build_options _abd56990_build_options(RRBuildOptions* value) { return REDGPU_NP_STRUCT_INIT(_s_abd56990_build_options){value}; }
static inline _s_abd56990_memory_requirements _abd56990_memory_requirements(RRMemoryRequirements* value) { return REDGPU_NP_STRUCT_INIT(_s_abd56990_memory_requirements){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetSceneBuildMemoryRequirements(_s_abd56990_context context, _s_abd56990_build_input build_input, _s_abd56990_build_options build_options, _s_abd56990_memory_requirements memory_requirements) {
  return rrGetSceneBuildMemoryRequirements(context.value, build_input.value, build_options.value, memory_requirements.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrCmdIntersect rrCmdIntersect
#define _b7aaf1b6_context(value) value
#define _b7aaf1b6_scene_buffer(value) value
#define _b7aaf1b6_query(value) value
#define _b7aaf1b6_rays(value) value
#define _b7aaf1b6_ray_count(value) value
#define _b7aaf1b6_indirect_ray_count(value) value
#define _b7aaf1b6_query_output(value) value
#define _b7aaf1b6_hits(value) value
#define _b7aaf1b6_scratch(value) value
#define _b7aaf1b6_command_stream(value) value
#else
typedef struct _s_b7aaf1b6_context { RRContext value; } _s_b7aaf1b6_context;
typedef struct _s_b7aaf1b6_scene_buffer { RRDevicePtr value; } _s_b7aaf1b6_scene_buffer;
typedef struct _s_b7aaf1b6_query { RRIntersectQuery value; } _s_b7aaf1b6_query;
typedef struct _s_b7aaf1b6_rays { RRDevicePtr value; } _s_b7aaf1b6_rays;
typedef struct _s_b7aaf1b6_ray_count { uint32_t value; } _s_b7aaf1b6_ray_count;
typedef struct _s_b7aaf1b6_indirect_ray_count { RRDevicePtr value; } _s_b7aaf1b6_indirect_ray_count;
typedef struct _s_b7aaf1b6_query_output { RRIntersectQueryOutput value; } _s_b7aaf1b6_query_output;
typedef struct _s_b7aaf1b6_hits { RRDevicePtr value; } _s_b7aaf1b6_hits;
typedef struct _s_b7aaf1b6_scratch { RRDevicePtr value; } _s_b7aaf1b6_scratch;
typedef struct _s_b7aaf1b6_command_stream { RRCommandStream value; } _s_b7aaf1b6_command_stream;
static inline _s_b7aaf1b6_context _b7aaf1b6_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_b7aaf1b6_context){value}; }
static inline _s_b7aaf1b6_scene_buffer _b7aaf1b6_scene_buffer(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_b7aaf1b6_scene_buffer){value}; }
static inline _s_b7aaf1b6_query _b7aaf1b6_query(RRIntersectQuery value) { return REDGPU_NP_STRUCT_INIT(_s_b7aaf1b6_query){value}; }
static inline _s_b7aaf1b6_rays _b7aaf1b6_rays(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_b7aaf1b6_rays){value}; }
static inline _s_b7aaf1b6_ray_count _b7aaf1b6_ray_count(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_b7aaf1b6_ray_count){value}; }
static inline _s_b7aaf1b6_indirect_ray_count _b7aaf1b6_indirect_ray_count(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_b7aaf1b6_indirect_ray_count){value}; }
static inline _s_b7aaf1b6_query_output _b7aaf1b6_query_output(RRIntersectQueryOutput value) { return REDGPU_NP_STRUCT_INIT(_s_b7aaf1b6_query_output){value}; }
static inline _s_b7aaf1b6_hits _b7aaf1b6_hits(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_b7aaf1b6_hits){value}; }
static inline _s_b7aaf1b6_scratch _b7aaf1b6_scratch(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_b7aaf1b6_scratch){value}; }
static inline _s_b7aaf1b6_command_stream _b7aaf1b6_command_stream(RRCommandStream value) { return REDGPU_NP_STRUCT_INIT(_s_b7aaf1b6_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrCmdIntersect(_s_b7aaf1b6_context context, _s_b7aaf1b6_scene_buffer scene_buffer, _s_b7aaf1b6_query query, _s_b7aaf1b6_rays rays, _s_b7aaf1b6_ray_count ray_count, _s_b7aaf1b6_indirect_ray_count indirect_ray_count, _s_b7aaf1b6_query_output query_output, _s_b7aaf1b6_hits hits, _s_b7aaf1b6_scratch scratch, _s_b7aaf1b6_command_stream command_stream) {
  return rrCmdIntersect(context.value, scene_buffer.value, query.value, rays.value, ray_count.value, indirect_ray_count.value, query_output.value, hits.value, scratch.value, command_stream.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrGetTraceMemoryRequirements rrGetTraceMemoryRequirements
#define _c8d2629e_context(value) value
#define _c8d2629e_ray_count(value) value
#define _c8d2629e_scratch_size(value) value
#else
typedef struct _s_c8d2629e_context { RRContext value; } _s_c8d2629e_context;
typedef struct _s_c8d2629e_ray_count { uint32_t value; } _s_c8d2629e_ray_count;
typedef struct _s_c8d2629e_scratch_size { size_t* value; } _s_c8d2629e_scratch_size;
static inline _s_c8d2629e_context _c8d2629e_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_c8d2629e_context){value}; }
static inline _s_c8d2629e_ray_count _c8d2629e_ray_count(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_c8d2629e_ray_count){value}; }
static inline _s_c8d2629e_scratch_size _c8d2629e_scratch_size(size_t* value) { return REDGPU_NP_STRUCT_INIT(_s_c8d2629e_scratch_size){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrGetTraceMemoryRequirements(_s_c8d2629e_context context, _s_c8d2629e_ray_count ray_count, _s_c8d2629e_scratch_size scratch_size) {
  return rrGetTraceMemoryRequirements(context.value, ray_count.value, scratch_size.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrAllocateCommandStream rrAllocateCommandStream
#define _b1a1c898_context(value) value
#define _b1a1c898_command_stream(value) value
#else
typedef struct _s_b1a1c898_context { RRContext value; } _s_b1a1c898_context;
typedef struct _s_b1a1c898_command_stream { RRCommandStream* value; } _s_b1a1c898_command_stream;
static inline _s_b1a1c898_context _b1a1c898_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_b1a1c898_context){value}; }
static inline _s_b1a1c898_command_stream _b1a1c898_command_stream(RRCommandStream* value) { return REDGPU_NP_STRUCT_INIT(_s_b1a1c898_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrAllocateCommandStream(_s_b1a1c898_context context, _s_b1a1c898_command_stream command_stream) {
  return rrAllocateCommandStream(context.value, command_stream.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrReleaseCommandStream rrReleaseCommandStream
#define _cc8f6825_context(value) value
#define _cc8f6825_command_stream(value) value
#else
typedef struct _s_cc8f6825_context { RRContext value; } _s_cc8f6825_context;
typedef struct _s_cc8f6825_command_stream { RRCommandStream value; } _s_cc8f6825_command_stream;
static inline _s_cc8f6825_context _cc8f6825_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_cc8f6825_context){value}; }
static inline _s_cc8f6825_command_stream _cc8f6825_command_stream(RRCommandStream value) { return REDGPU_NP_STRUCT_INIT(_s_cc8f6825_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrReleaseCommandStream(_s_cc8f6825_context context, _s_cc8f6825_command_stream command_stream) {
  return rrReleaseCommandStream(context.value, command_stream.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrSumbitCommandStream rrSumbitCommandStream
#define _433bd54e_context(value) value
#define _433bd54e_command_stream(value) value
#define _433bd54e_wait_event(value) value
#define _433bd54e_out_event(value) value
#else
typedef struct _s_433bd54e_context { RRContext value; } _s_433bd54e_context;
typedef struct _s_433bd54e_command_stream { RRCommandStream value; } _s_433bd54e_command_stream;
typedef struct _s_433bd54e_wait_event { RREvent value; } _s_433bd54e_wait_event;
typedef struct _s_433bd54e_out_event { RREvent* value; } _s_433bd54e_out_event;
static inline _s_433bd54e_context _433bd54e_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_433bd54e_context){value}; }
static inline _s_433bd54e_command_stream _433bd54e_command_stream(RRCommandStream value) { return REDGPU_NP_STRUCT_INIT(_s_433bd54e_command_stream){value}; }
static inline _s_433bd54e_wait_event _433bd54e_wait_event(RREvent value) { return REDGPU_NP_STRUCT_INIT(_s_433bd54e_wait_event){value}; }
static inline _s_433bd54e_out_event _433bd54e_out_event(RREvent* value) { return REDGPU_NP_STRUCT_INIT(_s_433bd54e_out_event){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrSumbitCommandStream(_s_433bd54e_context context, _s_433bd54e_command_stream command_stream, _s_433bd54e_wait_event wait_event, _s_433bd54e_out_event out_event) {
  return rrSumbitCommandStream(context.value, command_stream.value, wait_event.value, out_event.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrReleaseEvent rrReleaseEvent
#define _e8a5dc0d_context(value) value
#define _e8a5dc0d_event(value) value
#else
typedef struct _s_e8a5dc0d_context { RRContext value; } _s_e8a5dc0d_context;
typedef struct _s_e8a5dc0d_event { RREvent value; } _s_e8a5dc0d_event;
static inline _s_e8a5dc0d_context _e8a5dc0d_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_e8a5dc0d_context){value}; }
static inline _s_e8a5dc0d_event _e8a5dc0d_event(RREvent value) { return REDGPU_NP_STRUCT_INIT(_s_e8a5dc0d_event){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrReleaseEvent(_s_e8a5dc0d_context context, _s_e8a5dc0d_event event) {
  return rrReleaseEvent(context.value, event.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrWaitEvent rrWaitEvent
#define _9e2369c1_context(value) value
#define _9e2369c1_event(value) value
#else
typedef struct _s_9e2369c1_context { RRContext value; } _s_9e2369c1_context;
typedef struct _s_9e2369c1_event { RREvent value; } _s_9e2369c1_event;
static inline _s_9e2369c1_context _9e2369c1_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_9e2369c1_context){value}; }
static inline _s_9e2369c1_event _9e2369c1_event(RREvent value) { return REDGPU_NP_STRUCT_INIT(_s_9e2369c1_event){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrWaitEvent(_s_9e2369c1_context context, _s_9e2369c1_event event) {
  return rrWaitEvent(context.value, event.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrReleaseDevicePtr rrReleaseDevicePtr
#define _8d1def0e_context(value) value
#define _8d1def0e_ptr(value) value
#else
typedef struct _s_8d1def0e_context { RRContext value; } _s_8d1def0e_context;
typedef struct _s_8d1def0e_ptr { RRDevicePtr value; } _s_8d1def0e_ptr;
static inline _s_8d1def0e_context _8d1def0e_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_8d1def0e_context){value}; }
static inline _s_8d1def0e_ptr _8d1def0e_ptr(RRDevicePtr value) { return REDGPU_NP_STRUCT_INIT(_s_8d1def0e_ptr){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrReleaseDevicePtr(_s_8d1def0e_context context, _s_8d1def0e_ptr ptr) {
  return rrReleaseDevicePtr(context.value, ptr.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_rrReleaseExternalCommandStream rrReleaseExternalCommandStream
#define _1141d4bb_context(value) value
#define _1141d4bb_command_stream(value) value
#else
typedef struct _s_1141d4bb_context { RRContext value; } _s_1141d4bb_context;
typedef struct _s_1141d4bb_command_stream { RRCommandStream value; } _s_1141d4bb_command_stream;
static inline _s_1141d4bb_context _1141d4bb_context(RRContext value) { return REDGPU_NP_STRUCT_INIT(_s_1141d4bb_context){value}; }
static inline _s_1141d4bb_command_stream _1141d4bb_command_stream(RRCommandStream value) { return REDGPU_NP_STRUCT_INIT(_s_1141d4bb_command_stream){value}; }
REDGPU_NP_DECLSPEC RRError REDGPU_NP_API np_rrReleaseExternalCommandStream(_s_1141d4bb_context context, _s_1141d4bb_command_stream command_stream) {
  return rrReleaseExternalCommandStream(context.value, command_stream.value);
}
#endif

