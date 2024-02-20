#pragma once

#ifndef REDGPU_NP_STRUCT_INIT
#ifdef __cplusplus
#define REDGPU_NP_STRUCT_INIT(x) x
#else
#define REDGPU_NP_STRUCT_INIT(x) (x)
#endif
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redGpuVisTracingStart redGpuVisTracingStart
#define _68acf242_optionalFile(value) value
#define _68acf242_optionalLine(value) value
#define _68acf242_optionalUserData(value) value
#else
typedef struct _s_68acf242_optionalFile { char* value; } _s_68acf242_optionalFile;
typedef struct _s_68acf242_optionalLine { int value; } _s_68acf242_optionalLine;
typedef struct _s_68acf242_optionalUserData { void* value; } _s_68acf242_optionalUserData;
static inline _s_68acf242_optionalFile _68acf242_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_68acf242_optionalFile){value}; }
static inline _s_68acf242_optionalLine _68acf242_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_68acf242_optionalLine){value}; }
static inline _s_68acf242_optionalUserData _68acf242_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_68acf242_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redGpuVisTracingStart(_s_68acf242_optionalFile optionalFile, _s_68acf242_optionalLine optionalLine, _s_68acf242_optionalUserData optionalUserData) {
  redGpuVisTracingStart(optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redGpuVisTracingCapture redGpuVisTracingCapture
#define _385c5431_optionalFile(value) value
#define _385c5431_optionalLine(value) value
#define _385c5431_optionalUserData(value) value
#else
typedef struct _s_385c5431_optionalFile { char* value; } _s_385c5431_optionalFile;
typedef struct _s_385c5431_optionalLine { int value; } _s_385c5431_optionalLine;
typedef struct _s_385c5431_optionalUserData { void* value; } _s_385c5431_optionalUserData;
static inline _s_385c5431_optionalFile _385c5431_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_385c5431_optionalFile){value}; }
static inline _s_385c5431_optionalLine _385c5431_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_385c5431_optionalLine){value}; }
static inline _s_385c5431_optionalUserData _385c5431_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_385c5431_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redGpuVisTracingCapture(_s_385c5431_optionalFile optionalFile, _s_385c5431_optionalLine optionalLine, _s_385c5431_optionalUserData optionalUserData) {
  redGpuVisTracingCapture(optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redGpuVisTracingStop redGpuVisTracingStop
#define _90922b2e_optionalFile(value) value
#define _90922b2e_optionalLine(value) value
#define _90922b2e_optionalUserData(value) value
#else
typedef struct _s_90922b2e_optionalFile { char* value; } _s_90922b2e_optionalFile;
typedef struct _s_90922b2e_optionalLine { int value; } _s_90922b2e_optionalLine;
typedef struct _s_90922b2e_optionalUserData { void* value; } _s_90922b2e_optionalUserData;
static inline _s_90922b2e_optionalFile _90922b2e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_90922b2e_optionalFile){value}; }
static inline _s_90922b2e_optionalLine _90922b2e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_90922b2e_optionalLine){value}; }
static inline _s_90922b2e_optionalUserData _90922b2e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_90922b2e_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redGpuVisTracingStop(_s_90922b2e_optionalFile optionalFile, _s_90922b2e_optionalLine optionalLine, _s_90922b2e_optionalUserData optionalUserData) {
  redGpuVisTracingStop(optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

