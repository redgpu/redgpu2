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
#define _499e19f8_context(value) value
#define _499e19f8_gpu(value) value
#define _499e19f8_handleName(value) value
#define _499e19f8_count(value) value
#define _499e19f8_outArrayTimestamp(value) value
#define _499e19f8_outStatuses(value) value
#define _499e19f8_optionalFile(value) value
#define _499e19f8_optionalLine(value) value
#define _499e19f8_optionalUserData(value) value
#else
typedef struct _s_499e19f8_context { RedContext value; } _s_499e19f8_context;
typedef struct _s_499e19f8_gpu { RedHandleGpu value; } _s_499e19f8_gpu;
typedef struct _s_499e19f8_handleName { char* value; } _s_499e19f8_handleName;
typedef struct _s_499e19f8_count { unsigned value; } _s_499e19f8_count;
typedef struct _s_499e19f8_outArrayTimestamp { RedHandleArrayTimestamp* value; } _s_499e19f8_outArrayTimestamp;
typedef struct _s_499e19f8_outStatuses { RedStatuses* value; } _s_499e19f8_outStatuses;
typedef struct _s_499e19f8_optionalFile { char* value; } _s_499e19f8_optionalFile;
typedef struct _s_499e19f8_optionalLine { int value; } _s_499e19f8_optionalLine;
typedef struct _s_499e19f8_optionalUserData { void* value; } _s_499e19f8_optionalUserData;
static inline _s_499e19f8_context _499e19f8_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_499e19f8_context){value}; }
static inline _s_499e19f8_gpu _499e19f8_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_499e19f8_gpu){value}; }
static inline _s_499e19f8_handleName _499e19f8_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_499e19f8_handleName){value}; }
static inline _s_499e19f8_count _499e19f8_count(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_499e19f8_count){value}; }
static inline _s_499e19f8_outArrayTimestamp _499e19f8_outArrayTimestamp(RedHandleArrayTimestamp* value) { return REDGPU_NP_STRUCT_INIT(_s_499e19f8_outArrayTimestamp){value}; }
static inline _s_499e19f8_outStatuses _499e19f8_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_499e19f8_outStatuses){value}; }
static inline _s_499e19f8_optionalFile _499e19f8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_499e19f8_optionalFile){value}; }
static inline _s_499e19f8_optionalLine _499e19f8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_499e19f8_optionalLine){value}; }
static inline _s_499e19f8_optionalUserData _499e19f8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_499e19f8_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateArrayTimestamp(_s_499e19f8_context context, _s_499e19f8_gpu gpu, _s_499e19f8_handleName handleName, _s_499e19f8_count count, _s_499e19f8_outArrayTimestamp outArrayTimestamp, _s_499e19f8_outStatuses outStatuses, _s_499e19f8_optionalFile optionalFile, _s_499e19f8_optionalLine optionalLine, _s_499e19f8_optionalUserData optionalUserData) {
  redCreateArrayTimestamp(context.value, gpu.value, handleName.value, count.value, outArrayTimestamp.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyArrayTimestamp redDestroyArrayTimestamp
#define _11d59feb_context(value) value
#define _11d59feb_gpu(value) value
#define _11d59feb_arrayTimestamp(value) value
#define _11d59feb_optionalFile(value) value
#define _11d59feb_optionalLine(value) value
#define _11d59feb_optionalUserData(value) value
#else
typedef struct _s_11d59feb_context { RedContext value; } _s_11d59feb_context;
typedef struct _s_11d59feb_gpu { RedHandleGpu value; } _s_11d59feb_gpu;
typedef struct _s_11d59feb_arrayTimestamp { RedHandleArrayTimestamp value; } _s_11d59feb_arrayTimestamp;
typedef struct _s_11d59feb_optionalFile { char* value; } _s_11d59feb_optionalFile;
typedef struct _s_11d59feb_optionalLine { int value; } _s_11d59feb_optionalLine;
typedef struct _s_11d59feb_optionalUserData { void* value; } _s_11d59feb_optionalUserData;
static inline _s_11d59feb_context _11d59feb_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_11d59feb_context){value}; }
static inline _s_11d59feb_gpu _11d59feb_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_11d59feb_gpu){value}; }
static inline _s_11d59feb_arrayTimestamp _11d59feb_arrayTimestamp(RedHandleArrayTimestamp value) { return REDGPU_NP_STRUCT_INIT(_s_11d59feb_arrayTimestamp){value}; }
static inline _s_11d59feb_optionalFile _11d59feb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_11d59feb_optionalFile){value}; }
static inline _s_11d59feb_optionalLine _11d59feb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_11d59feb_optionalLine){value}; }
static inline _s_11d59feb_optionalUserData _11d59feb_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_11d59feb_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyArrayTimestamp(_s_11d59feb_context context, _s_11d59feb_gpu gpu, _s_11d59feb_arrayTimestamp arrayTimestamp, _s_11d59feb_optionalFile optionalFile, _s_11d59feb_optionalLine optionalLine, _s_11d59feb_optionalUserData optionalUserData) {
  redDestroyArrayTimestamp(context.value, gpu.value, arrayTimestamp.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallArrayTimestampWrite redCallArrayTimestampWrite
#define _9e77bf0c_calls(value) value
#define _9e77bf0c_context(value) value
#define _9e77bf0c_arrayTimestamp(value) value
#define _9e77bf0c_index(value) value
#else
typedef struct _s_9e77bf0c_calls { RedHandleCalls value; } _s_9e77bf0c_calls;
typedef struct _s_9e77bf0c_context { RedContext value; } _s_9e77bf0c_context;
typedef struct _s_9e77bf0c_arrayTimestamp { RedHandleArrayTimestamp value; } _s_9e77bf0c_arrayTimestamp;
typedef struct _s_9e77bf0c_index { unsigned value; } _s_9e77bf0c_index;
static inline _s_9e77bf0c_calls _9e77bf0c_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_9e77bf0c_calls){value}; }
static inline _s_9e77bf0c_context _9e77bf0c_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_9e77bf0c_context){value}; }
static inline _s_9e77bf0c_arrayTimestamp _9e77bf0c_arrayTimestamp(RedHandleArrayTimestamp value) { return REDGPU_NP_STRUCT_INIT(_s_9e77bf0c_arrayTimestamp){value}; }
static inline _s_9e77bf0c_index _9e77bf0c_index(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9e77bf0c_index){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallArrayTimestampWrite(_s_9e77bf0c_calls calls, _s_9e77bf0c_context context, _s_9e77bf0c_arrayTimestamp arrayTimestamp, _s_9e77bf0c_index index) {
  redCallArrayTimestampWrite(calls.value, context.value, arrayTimestamp.value, index.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redArrayTimestampRead redArrayTimestampRead
#define _2dd70865_context(value) value
#define _2dd70865_gpu(value) value
#define _2dd70865_arrayTimestamp(value) value
#define _2dd70865_rangeFirst(value) value
#define _2dd70865_rangeCount(value) value
#define _2dd70865_out64BitTicksCounts(value) value
#define _2dd70865_outStatuses(value) value
#define _2dd70865_optionalFile(value) value
#define _2dd70865_optionalLine(value) value
#define _2dd70865_optionalUserData(value) value
#else
typedef struct _s_2dd70865_context { RedContext value; } _s_2dd70865_context;
typedef struct _s_2dd70865_gpu { RedHandleGpu value; } _s_2dd70865_gpu;
typedef struct _s_2dd70865_arrayTimestamp { RedHandleArrayTimestamp value; } _s_2dd70865_arrayTimestamp;
typedef struct _s_2dd70865_rangeFirst { unsigned value; } _s_2dd70865_rangeFirst;
typedef struct _s_2dd70865_rangeCount { unsigned value; } _s_2dd70865_rangeCount;
typedef struct _s_2dd70865_out64BitTicksCounts { void* value; } _s_2dd70865_out64BitTicksCounts;
typedef struct _s_2dd70865_outStatuses { RedStatuses* value; } _s_2dd70865_outStatuses;
typedef struct _s_2dd70865_optionalFile { char* value; } _s_2dd70865_optionalFile;
typedef struct _s_2dd70865_optionalLine { int value; } _s_2dd70865_optionalLine;
typedef struct _s_2dd70865_optionalUserData { void* value; } _s_2dd70865_optionalUserData;
static inline _s_2dd70865_context _2dd70865_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_2dd70865_context){value}; }
static inline _s_2dd70865_gpu _2dd70865_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_2dd70865_gpu){value}; }
static inline _s_2dd70865_arrayTimestamp _2dd70865_arrayTimestamp(RedHandleArrayTimestamp value) { return REDGPU_NP_STRUCT_INIT(_s_2dd70865_arrayTimestamp){value}; }
static inline _s_2dd70865_rangeFirst _2dd70865_rangeFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_2dd70865_rangeFirst){value}; }
static inline _s_2dd70865_rangeCount _2dd70865_rangeCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_2dd70865_rangeCount){value}; }
static inline _s_2dd70865_out64BitTicksCounts _2dd70865_out64BitTicksCounts(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2dd70865_out64BitTicksCounts){value}; }
static inline _s_2dd70865_outStatuses _2dd70865_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_2dd70865_outStatuses){value}; }
static inline _s_2dd70865_optionalFile _2dd70865_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2dd70865_optionalFile){value}; }
static inline _s_2dd70865_optionalLine _2dd70865_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2dd70865_optionalLine){value}; }
static inline _s_2dd70865_optionalUserData _2dd70865_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2dd70865_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redArrayTimestampRead(_s_2dd70865_context context, _s_2dd70865_gpu gpu, _s_2dd70865_arrayTimestamp arrayTimestamp, _s_2dd70865_rangeFirst rangeFirst, _s_2dd70865_rangeCount rangeCount, _s_2dd70865_out64BitTicksCounts out64BitTicksCounts, _s_2dd70865_outStatuses outStatuses, _s_2dd70865_optionalFile optionalFile, _s_2dd70865_optionalLine optionalLine, _s_2dd70865_optionalUserData optionalUserData) {
  redArrayTimestampRead(context.value, gpu.value, arrayTimestamp.value, rangeFirst.value, rangeCount.value, out64BitTicksCounts.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

