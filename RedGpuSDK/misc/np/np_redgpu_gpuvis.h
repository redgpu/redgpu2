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
#define np_redGpuVisTracingStart redGpuVisTracingStart
#define _ec50ad01_optionalFile(value) value
#define _ec50ad01_optionalLine(value) value
#define _ec50ad01_optionalUserData(value) value
#else
typedef struct _s_ec50ad01_optionalFile { char* value; } _s_ec50ad01_optionalFile;
typedef struct _s_ec50ad01_optionalLine { int value; } _s_ec50ad01_optionalLine;
typedef struct _s_ec50ad01_optionalUserData { void* value; } _s_ec50ad01_optionalUserData;
static inline _s_ec50ad01_optionalFile _ec50ad01_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ec50ad01_optionalFile){value}; }
static inline _s_ec50ad01_optionalLine _ec50ad01_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ec50ad01_optionalLine){value}; }
static inline _s_ec50ad01_optionalUserData _ec50ad01_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ec50ad01_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redGpuVisTracingStart(_s_ec50ad01_optionalFile optionalFile, _s_ec50ad01_optionalLine optionalLine, _s_ec50ad01_optionalUserData optionalUserData) {
  redGpuVisTracingStart(optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redGpuVisTracingCapture redGpuVisTracingCapture
#define _1a17bda6_optionalFile(value) value
#define _1a17bda6_optionalLine(value) value
#define _1a17bda6_optionalUserData(value) value
#else
typedef struct _s_1a17bda6_optionalFile { char* value; } _s_1a17bda6_optionalFile;
typedef struct _s_1a17bda6_optionalLine { int value; } _s_1a17bda6_optionalLine;
typedef struct _s_1a17bda6_optionalUserData { void* value; } _s_1a17bda6_optionalUserData;
static inline _s_1a17bda6_optionalFile _1a17bda6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1a17bda6_optionalFile){value}; }
static inline _s_1a17bda6_optionalLine _1a17bda6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1a17bda6_optionalLine){value}; }
static inline _s_1a17bda6_optionalUserData _1a17bda6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1a17bda6_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redGpuVisTracingCapture(_s_1a17bda6_optionalFile optionalFile, _s_1a17bda6_optionalLine optionalLine, _s_1a17bda6_optionalUserData optionalUserData) {
  redGpuVisTracingCapture(optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redGpuVisTracingStop redGpuVisTracingStop
#define _834b61bb_optionalFile(value) value
#define _834b61bb_optionalLine(value) value
#define _834b61bb_optionalUserData(value) value
#else
typedef struct _s_834b61bb_optionalFile { char* value; } _s_834b61bb_optionalFile;
typedef struct _s_834b61bb_optionalLine { int value; } _s_834b61bb_optionalLine;
typedef struct _s_834b61bb_optionalUserData { void* value; } _s_834b61bb_optionalUserData;
static inline _s_834b61bb_optionalFile _834b61bb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_834b61bb_optionalFile){value}; }
static inline _s_834b61bb_optionalLine _834b61bb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_834b61bb_optionalLine){value}; }
static inline _s_834b61bb_optionalUserData _834b61bb_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_834b61bb_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redGpuVisTracingStop(_s_834b61bb_optionalFile optionalFile, _s_834b61bb_optionalLine optionalLine, _s_834b61bb_optionalUserData optionalUserData) {
  redGpuVisTracingStop(optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

