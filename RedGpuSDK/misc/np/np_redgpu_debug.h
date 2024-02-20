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
#define np_redDebugArrayGetHandle redDebugArrayGetHandle
#define _83ceb3c8_context(value) value
#define _83ceb3c8_gpu(value) value
#define _83ceb3c8_outStatuses(value) value
#define _83ceb3c8_optionalFile(value) value
#define _83ceb3c8_optionalLine(value) value
#define _83ceb3c8_optionalUserData(value) value
#else
typedef struct _s_83ceb3c8_context { RedContext value; } _s_83ceb3c8_context;
typedef struct _s_83ceb3c8_gpu { RedHandleGpu value; } _s_83ceb3c8_gpu;
typedef struct _s_83ceb3c8_outStatuses { RedStatuses* value; } _s_83ceb3c8_outStatuses;
typedef struct _s_83ceb3c8_optionalFile { char* value; } _s_83ceb3c8_optionalFile;
typedef struct _s_83ceb3c8_optionalLine { int value; } _s_83ceb3c8_optionalLine;
typedef struct _s_83ceb3c8_optionalUserData { void* value; } _s_83ceb3c8_optionalUserData;
static inline _s_83ceb3c8_context _83ceb3c8_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_83ceb3c8_context){value}; }
static inline _s_83ceb3c8_gpu _83ceb3c8_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_83ceb3c8_gpu){value}; }
static inline _s_83ceb3c8_outStatuses _83ceb3c8_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_83ceb3c8_outStatuses){value}; }
static inline _s_83ceb3c8_optionalFile _83ceb3c8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_83ceb3c8_optionalFile){value}; }
static inline _s_83ceb3c8_optionalLine _83ceb3c8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_83ceb3c8_optionalLine){value}; }
static inline _s_83ceb3c8_optionalUserData _83ceb3c8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_83ceb3c8_optionalUserData){value}; }
REDGPU_NP_DECLSPEC RedHandleArray REDGPU_NP_API np_redDebugArrayGetHandle(_s_83ceb3c8_context context, _s_83ceb3c8_gpu gpu, _s_83ceb3c8_outStatuses outStatuses, _s_83ceb3c8_optionalFile optionalFile, _s_83ceb3c8_optionalLine optionalLine, _s_83ceb3c8_optionalUserData optionalUserData) {
  return redDebugArrayGetHandle(context.value, gpu.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDebugArrayCallPrint redDebugArrayCallPrint
#define _315f7631_context(value) value
#define _315f7631_gpu(value) value
#define _315f7631_calls(value) value
#define _315f7631_outStatuses(value) value
#define _315f7631_optionalFile(value) value
#define _315f7631_optionalLine(value) value
#define _315f7631_optionalUserData(value) value
#else
typedef struct _s_315f7631_context { RedContext value; } _s_315f7631_context;
typedef struct _s_315f7631_gpu { RedHandleGpu value; } _s_315f7631_gpu;
typedef struct _s_315f7631_calls { RedHandleCalls value; } _s_315f7631_calls;
typedef struct _s_315f7631_outStatuses { RedStatuses* value; } _s_315f7631_outStatuses;
typedef struct _s_315f7631_optionalFile { char* value; } _s_315f7631_optionalFile;
typedef struct _s_315f7631_optionalLine { int value; } _s_315f7631_optionalLine;
typedef struct _s_315f7631_optionalUserData { void* value; } _s_315f7631_optionalUserData;
static inline _s_315f7631_context _315f7631_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_315f7631_context){value}; }
static inline _s_315f7631_gpu _315f7631_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_315f7631_gpu){value}; }
static inline _s_315f7631_calls _315f7631_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_315f7631_calls){value}; }
static inline _s_315f7631_outStatuses _315f7631_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_315f7631_outStatuses){value}; }
static inline _s_315f7631_optionalFile _315f7631_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_315f7631_optionalFile){value}; }
static inline _s_315f7631_optionalLine _315f7631_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_315f7631_optionalLine){value}; }
static inline _s_315f7631_optionalUserData _315f7631_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_315f7631_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDebugArrayCallPrint(_s_315f7631_context context, _s_315f7631_gpu gpu, _s_315f7631_calls calls, _s_315f7631_outStatuses outStatuses, _s_315f7631_optionalFile optionalFile, _s_315f7631_optionalLine optionalLine, _s_315f7631_optionalUserData optionalUserData) {
  redDebugArrayCallPrint(context.value, gpu.value, calls.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

