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
#define _f477b6f5_context(value) value
#define _f477b6f5_gpu(value) value
#define _f477b6f5_outStatuses(value) value
#define _f477b6f5_optionalFile(value) value
#define _f477b6f5_optionalLine(value) value
#define _f477b6f5_optionalUserData(value) value
#else
typedef struct _s_f477b6f5_context { RedContext value; } _s_f477b6f5_context;
typedef struct _s_f477b6f5_gpu { RedHandleGpu value; } _s_f477b6f5_gpu;
typedef struct _s_f477b6f5_outStatuses { RedStatuses* value; } _s_f477b6f5_outStatuses;
typedef struct _s_f477b6f5_optionalFile { char* value; } _s_f477b6f5_optionalFile;
typedef struct _s_f477b6f5_optionalLine { int value; } _s_f477b6f5_optionalLine;
typedef struct _s_f477b6f5_optionalUserData { void* value; } _s_f477b6f5_optionalUserData;
static inline _s_f477b6f5_context _f477b6f5_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_f477b6f5_context){value}; }
static inline _s_f477b6f5_gpu _f477b6f5_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_f477b6f5_gpu){value}; }
static inline _s_f477b6f5_outStatuses _f477b6f5_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_f477b6f5_outStatuses){value}; }
static inline _s_f477b6f5_optionalFile _f477b6f5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f477b6f5_optionalFile){value}; }
static inline _s_f477b6f5_optionalLine _f477b6f5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f477b6f5_optionalLine){value}; }
static inline _s_f477b6f5_optionalUserData _f477b6f5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f477b6f5_optionalUserData){value}; }
REDGPU_NP_DECLSPEC RedHandleArray REDGPU_NP_API np_redDebugArrayGetHandle(_s_f477b6f5_context context, _s_f477b6f5_gpu gpu, _s_f477b6f5_outStatuses outStatuses, _s_f477b6f5_optionalFile optionalFile, _s_f477b6f5_optionalLine optionalLine, _s_f477b6f5_optionalUserData optionalUserData) {
  return redDebugArrayGetHandle(context.value, gpu.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDebugArrayCallPrint redDebugArrayCallPrint
#define _5f1d5655_context(value) value
#define _5f1d5655_gpu(value) value
#define _5f1d5655_calls(value) value
#define _5f1d5655_outStatuses(value) value
#define _5f1d5655_optionalFile(value) value
#define _5f1d5655_optionalLine(value) value
#define _5f1d5655_optionalUserData(value) value
#else
typedef struct _s_5f1d5655_context { RedContext value; } _s_5f1d5655_context;
typedef struct _s_5f1d5655_gpu { RedHandleGpu value; } _s_5f1d5655_gpu;
typedef struct _s_5f1d5655_calls { RedHandleCalls value; } _s_5f1d5655_calls;
typedef struct _s_5f1d5655_outStatuses { RedStatuses* value; } _s_5f1d5655_outStatuses;
typedef struct _s_5f1d5655_optionalFile { char* value; } _s_5f1d5655_optionalFile;
typedef struct _s_5f1d5655_optionalLine { int value; } _s_5f1d5655_optionalLine;
typedef struct _s_5f1d5655_optionalUserData { void* value; } _s_5f1d5655_optionalUserData;
static inline _s_5f1d5655_context _5f1d5655_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_5f1d5655_context){value}; }
static inline _s_5f1d5655_gpu _5f1d5655_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_5f1d5655_gpu){value}; }
static inline _s_5f1d5655_calls _5f1d5655_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_5f1d5655_calls){value}; }
static inline _s_5f1d5655_outStatuses _5f1d5655_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_5f1d5655_outStatuses){value}; }
static inline _s_5f1d5655_optionalFile _5f1d5655_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5f1d5655_optionalFile){value}; }
static inline _s_5f1d5655_optionalLine _5f1d5655_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5f1d5655_optionalLine){value}; }
static inline _s_5f1d5655_optionalUserData _5f1d5655_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5f1d5655_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDebugArrayCallPrint(_s_5f1d5655_context context, _s_5f1d5655_gpu gpu, _s_5f1d5655_calls calls, _s_5f1d5655_outStatuses outStatuses, _s_5f1d5655_optionalFile optionalFile, _s_5f1d5655_optionalLine optionalLine, _s_5f1d5655_optionalUserData optionalUserData) {
  redDebugArrayCallPrint(context.value, gpu.value, calls.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

