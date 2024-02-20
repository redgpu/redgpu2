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
#define np_redCreateArrayTimestamp redCreateArrayTimestamp
#define _ca446e21_context(value) value
#define _ca446e21_gpu(value) value
#define _ca446e21_handleName(value) value
#define _ca446e21_count(value) value
#define _ca446e21_outArrayTimestamp(value) value
#define _ca446e21_outStatuses(value) value
#define _ca446e21_optionalFile(value) value
#define _ca446e21_optionalLine(value) value
#define _ca446e21_optionalUserData(value) value
#else
typedef struct _s_ca446e21_context { RedContext value; } _s_ca446e21_context;
typedef struct _s_ca446e21_gpu { RedHandleGpu value; } _s_ca446e21_gpu;
typedef struct _s_ca446e21_handleName { char* value; } _s_ca446e21_handleName;
typedef struct _s_ca446e21_count { unsigned value; } _s_ca446e21_count;
typedef struct _s_ca446e21_outArrayTimestamp { RedHandleArrayTimestamp* value; } _s_ca446e21_outArrayTimestamp;
typedef struct _s_ca446e21_outStatuses { RedStatuses* value; } _s_ca446e21_outStatuses;
typedef struct _s_ca446e21_optionalFile { char* value; } _s_ca446e21_optionalFile;
typedef struct _s_ca446e21_optionalLine { int value; } _s_ca446e21_optionalLine;
typedef struct _s_ca446e21_optionalUserData { void* value; } _s_ca446e21_optionalUserData;
static inline _s_ca446e21_context _ca446e21_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_ca446e21_context){value}; }
static inline _s_ca446e21_gpu _ca446e21_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_ca446e21_gpu){value}; }
static inline _s_ca446e21_handleName _ca446e21_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ca446e21_handleName){value}; }
static inline _s_ca446e21_count _ca446e21_count(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ca446e21_count){value}; }
static inline _s_ca446e21_outArrayTimestamp _ca446e21_outArrayTimestamp(RedHandleArrayTimestamp* value) { return REDGPU_NP_STRUCT_INIT(_s_ca446e21_outArrayTimestamp){value}; }
static inline _s_ca446e21_outStatuses _ca446e21_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_ca446e21_outStatuses){value}; }
static inline _s_ca446e21_optionalFile _ca446e21_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ca446e21_optionalFile){value}; }
static inline _s_ca446e21_optionalLine _ca446e21_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ca446e21_optionalLine){value}; }
static inline _s_ca446e21_optionalUserData _ca446e21_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ca446e21_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateArrayTimestamp(_s_ca446e21_context context, _s_ca446e21_gpu gpu, _s_ca446e21_handleName handleName, _s_ca446e21_count count, _s_ca446e21_outArrayTimestamp outArrayTimestamp, _s_ca446e21_outStatuses outStatuses, _s_ca446e21_optionalFile optionalFile, _s_ca446e21_optionalLine optionalLine, _s_ca446e21_optionalUserData optionalUserData) {
  redCreateArrayTimestamp(context.value, gpu.value, handleName.value, count.value, outArrayTimestamp.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyArrayTimestamp redDestroyArrayTimestamp
#define _3233be2d_context(value) value
#define _3233be2d_gpu(value) value
#define _3233be2d_arrayTimestamp(value) value
#define _3233be2d_optionalFile(value) value
#define _3233be2d_optionalLine(value) value
#define _3233be2d_optionalUserData(value) value
#else
typedef struct _s_3233be2d_context { RedContext value; } _s_3233be2d_context;
typedef struct _s_3233be2d_gpu { RedHandleGpu value; } _s_3233be2d_gpu;
typedef struct _s_3233be2d_arrayTimestamp { RedHandleArrayTimestamp value; } _s_3233be2d_arrayTimestamp;
typedef struct _s_3233be2d_optionalFile { char* value; } _s_3233be2d_optionalFile;
typedef struct _s_3233be2d_optionalLine { int value; } _s_3233be2d_optionalLine;
typedef struct _s_3233be2d_optionalUserData { void* value; } _s_3233be2d_optionalUserData;
static inline _s_3233be2d_context _3233be2d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_3233be2d_context){value}; }
static inline _s_3233be2d_gpu _3233be2d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_3233be2d_gpu){value}; }
static inline _s_3233be2d_arrayTimestamp _3233be2d_arrayTimestamp(RedHandleArrayTimestamp value) { return REDGPU_NP_STRUCT_INIT(_s_3233be2d_arrayTimestamp){value}; }
static inline _s_3233be2d_optionalFile _3233be2d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3233be2d_optionalFile){value}; }
static inline _s_3233be2d_optionalLine _3233be2d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3233be2d_optionalLine){value}; }
static inline _s_3233be2d_optionalUserData _3233be2d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3233be2d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyArrayTimestamp(_s_3233be2d_context context, _s_3233be2d_gpu gpu, _s_3233be2d_arrayTimestamp arrayTimestamp, _s_3233be2d_optionalFile optionalFile, _s_3233be2d_optionalLine optionalLine, _s_3233be2d_optionalUserData optionalUserData) {
  redDestroyArrayTimestamp(context.value, gpu.value, arrayTimestamp.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallArrayTimestampWrite redCallArrayTimestampWrite
#define _69ac2ce9_calls(value) value
#define _69ac2ce9_context(value) value
#define _69ac2ce9_arrayTimestamp(value) value
#define _69ac2ce9_index(value) value
#else
typedef struct _s_69ac2ce9_calls { RedHandleCalls value; } _s_69ac2ce9_calls;
typedef struct _s_69ac2ce9_context { RedContext value; } _s_69ac2ce9_context;
typedef struct _s_69ac2ce9_arrayTimestamp { RedHandleArrayTimestamp value; } _s_69ac2ce9_arrayTimestamp;
typedef struct _s_69ac2ce9_index { unsigned value; } _s_69ac2ce9_index;
static inline _s_69ac2ce9_calls _69ac2ce9_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_69ac2ce9_calls){value}; }
static inline _s_69ac2ce9_context _69ac2ce9_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_69ac2ce9_context){value}; }
static inline _s_69ac2ce9_arrayTimestamp _69ac2ce9_arrayTimestamp(RedHandleArrayTimestamp value) { return REDGPU_NP_STRUCT_INIT(_s_69ac2ce9_arrayTimestamp){value}; }
static inline _s_69ac2ce9_index _69ac2ce9_index(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_69ac2ce9_index){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallArrayTimestampWrite(_s_69ac2ce9_calls calls, _s_69ac2ce9_context context, _s_69ac2ce9_arrayTimestamp arrayTimestamp, _s_69ac2ce9_index index) {
  redCallArrayTimestampWrite(calls.value, context.value, arrayTimestamp.value, index.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redArrayTimestampRead redArrayTimestampRead
#define _38bcaab7_context(value) value
#define _38bcaab7_gpu(value) value
#define _38bcaab7_arrayTimestamp(value) value
#define _38bcaab7_rangeFirst(value) value
#define _38bcaab7_rangeCount(value) value
#define _38bcaab7_out64BitTicksCounts(value) value
#define _38bcaab7_outStatuses(value) value
#define _38bcaab7_optionalFile(value) value
#define _38bcaab7_optionalLine(value) value
#define _38bcaab7_optionalUserData(value) value
#else
typedef struct _s_38bcaab7_context { RedContext value; } _s_38bcaab7_context;
typedef struct _s_38bcaab7_gpu { RedHandleGpu value; } _s_38bcaab7_gpu;
typedef struct _s_38bcaab7_arrayTimestamp { RedHandleArrayTimestamp value; } _s_38bcaab7_arrayTimestamp;
typedef struct _s_38bcaab7_rangeFirst { unsigned value; } _s_38bcaab7_rangeFirst;
typedef struct _s_38bcaab7_rangeCount { unsigned value; } _s_38bcaab7_rangeCount;
typedef struct _s_38bcaab7_out64BitTicksCounts { void* value; } _s_38bcaab7_out64BitTicksCounts;
typedef struct _s_38bcaab7_outStatuses { RedStatuses* value; } _s_38bcaab7_outStatuses;
typedef struct _s_38bcaab7_optionalFile { char* value; } _s_38bcaab7_optionalFile;
typedef struct _s_38bcaab7_optionalLine { int value; } _s_38bcaab7_optionalLine;
typedef struct _s_38bcaab7_optionalUserData { void* value; } _s_38bcaab7_optionalUserData;
static inline _s_38bcaab7_context _38bcaab7_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_38bcaab7_context){value}; }
static inline _s_38bcaab7_gpu _38bcaab7_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_38bcaab7_gpu){value}; }
static inline _s_38bcaab7_arrayTimestamp _38bcaab7_arrayTimestamp(RedHandleArrayTimestamp value) { return REDGPU_NP_STRUCT_INIT(_s_38bcaab7_arrayTimestamp){value}; }
static inline _s_38bcaab7_rangeFirst _38bcaab7_rangeFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_38bcaab7_rangeFirst){value}; }
static inline _s_38bcaab7_rangeCount _38bcaab7_rangeCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_38bcaab7_rangeCount){value}; }
static inline _s_38bcaab7_out64BitTicksCounts _38bcaab7_out64BitTicksCounts(void* value) { return REDGPU_NP_STRUCT_INIT(_s_38bcaab7_out64BitTicksCounts){value}; }
static inline _s_38bcaab7_outStatuses _38bcaab7_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_38bcaab7_outStatuses){value}; }
static inline _s_38bcaab7_optionalFile _38bcaab7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_38bcaab7_optionalFile){value}; }
static inline _s_38bcaab7_optionalLine _38bcaab7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_38bcaab7_optionalLine){value}; }
static inline _s_38bcaab7_optionalUserData _38bcaab7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_38bcaab7_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redArrayTimestampRead(_s_38bcaab7_context context, _s_38bcaab7_gpu gpu, _s_38bcaab7_arrayTimestamp arrayTimestamp, _s_38bcaab7_rangeFirst rangeFirst, _s_38bcaab7_rangeCount rangeCount, _s_38bcaab7_out64BitTicksCounts out64BitTicksCounts, _s_38bcaab7_outStatuses outStatuses, _s_38bcaab7_optionalFile optionalFile, _s_38bcaab7_optionalLine optionalLine, _s_38bcaab7_optionalUserData optionalUserData) {
  redArrayTimestampRead(context.value, gpu.value, arrayTimestamp.value, rangeFirst.value, rangeCount.value, out64BitTicksCounts.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

