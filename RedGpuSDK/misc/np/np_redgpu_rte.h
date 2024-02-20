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
#define np_redRteCreateContext redRteCreateContext
#define _a3c68208_mallocFn(value) value
#define _a3c68208_freeFn(value) value
#define _a3c68208_optionalMallocTagged(value) value
#define _a3c68208_optionalFreeTagged(value) value
#define _a3c68208_debugCallback(value) value
#define _a3c68208_sdkVersion(value) value
#define _a3c68208_sdkExtensionsCount(value) value
#define _a3c68208_sdkExtensions(value) value
#define _a3c68208_optionalProgramName(value) value
#define _a3c68208_optionalProgramVersion(value) value
#define _a3c68208_optionalEngineName(value) value
#define _a3c68208_optionalEngineVersion(value) value
#define _a3c68208_optionalSettings(value) value
#define _a3c68208_outContext(value) value
#define _a3c68208_outStatuses(value) value
#define _a3c68208_optionalFile(value) value
#define _a3c68208_optionalLine(value) value
#define _a3c68208_optionalUserData(value) value
#define _a3c68208_rteParameters(value) value
#else
typedef struct _s_a3c68208_mallocFn { RedTypeProcedureMalloc value; } _s_a3c68208_mallocFn;
typedef struct _s_a3c68208_freeFn { RedTypeProcedureFree value; } _s_a3c68208_freeFn;
typedef struct _s_a3c68208_optionalMallocTagged { RedTypeProcedureMallocTagged value; } _s_a3c68208_optionalMallocTagged;
typedef struct _s_a3c68208_optionalFreeTagged { RedTypeProcedureFreeTagged value; } _s_a3c68208_optionalFreeTagged;
typedef struct _s_a3c68208_debugCallback { RedTypeProcedureDebugCallback value; } _s_a3c68208_debugCallback;
typedef struct _s_a3c68208_sdkVersion { RedSdkVersion value; } _s_a3c68208_sdkVersion;
typedef struct _s_a3c68208_sdkExtensionsCount { unsigned value; } _s_a3c68208_sdkExtensionsCount;
typedef struct _s_a3c68208_sdkExtensions { unsigned* value; } _s_a3c68208_sdkExtensions;
typedef struct _s_a3c68208_optionalProgramName { char* value; } _s_a3c68208_optionalProgramName;
typedef struct _s_a3c68208_optionalProgramVersion { unsigned value; } _s_a3c68208_optionalProgramVersion;
typedef struct _s_a3c68208_optionalEngineName { char* value; } _s_a3c68208_optionalEngineName;
typedef struct _s_a3c68208_optionalEngineVersion { unsigned value; } _s_a3c68208_optionalEngineVersion;
typedef struct _s_a3c68208_optionalSettings { void* value; } _s_a3c68208_optionalSettings;
typedef struct _s_a3c68208_outContext { RedContext* value; } _s_a3c68208_outContext;
typedef struct _s_a3c68208_outStatuses { RedStatuses* value; } _s_a3c68208_outStatuses;
typedef struct _s_a3c68208_optionalFile { char* value; } _s_a3c68208_optionalFile;
typedef struct _s_a3c68208_optionalLine { int value; } _s_a3c68208_optionalLine;
typedef struct _s_a3c68208_optionalUserData { void* value; } _s_a3c68208_optionalUserData;
typedef struct _s_a3c68208_rteParameters { RedRteCreateContextParameters* value; } _s_a3c68208_rteParameters;
static inline _s_a3c68208_mallocFn _a3c68208_mallocFn(RedTypeProcedureMalloc value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_mallocFn){value}; }
static inline _s_a3c68208_freeFn _a3c68208_freeFn(RedTypeProcedureFree value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_freeFn){value}; }
static inline _s_a3c68208_optionalMallocTagged _a3c68208_optionalMallocTagged(RedTypeProcedureMallocTagged value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_optionalMallocTagged){value}; }
static inline _s_a3c68208_optionalFreeTagged _a3c68208_optionalFreeTagged(RedTypeProcedureFreeTagged value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_optionalFreeTagged){value}; }
static inline _s_a3c68208_debugCallback _a3c68208_debugCallback(RedTypeProcedureDebugCallback value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_debugCallback){value}; }
static inline _s_a3c68208_sdkVersion _a3c68208_sdkVersion(RedSdkVersion value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_sdkVersion){value}; }
static inline _s_a3c68208_sdkExtensionsCount _a3c68208_sdkExtensionsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_sdkExtensionsCount){value}; }
static inline _s_a3c68208_sdkExtensions _a3c68208_sdkExtensions(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_sdkExtensions){value}; }
static inline _s_a3c68208_optionalProgramName _a3c68208_optionalProgramName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_optionalProgramName){value}; }
static inline _s_a3c68208_optionalProgramVersion _a3c68208_optionalProgramVersion(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_optionalProgramVersion){value}; }
static inline _s_a3c68208_optionalEngineName _a3c68208_optionalEngineName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_optionalEngineName){value}; }
static inline _s_a3c68208_optionalEngineVersion _a3c68208_optionalEngineVersion(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_optionalEngineVersion){value}; }
static inline _s_a3c68208_optionalSettings _a3c68208_optionalSettings(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_optionalSettings){value}; }
static inline _s_a3c68208_outContext _a3c68208_outContext(RedContext* value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_outContext){value}; }
static inline _s_a3c68208_outStatuses _a3c68208_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_outStatuses){value}; }
static inline _s_a3c68208_optionalFile _a3c68208_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_optionalFile){value}; }
static inline _s_a3c68208_optionalLine _a3c68208_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_optionalLine){value}; }
static inline _s_a3c68208_optionalUserData _a3c68208_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_optionalUserData){value}; }
static inline _s_a3c68208_rteParameters _a3c68208_rteParameters(RedRteCreateContextParameters* value) { return REDGPU_NP_STRUCT_INIT(_s_a3c68208_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateContext(_s_a3c68208_mallocFn mallocFn, _s_a3c68208_freeFn freeFn, _s_a3c68208_optionalMallocTagged optionalMallocTagged, _s_a3c68208_optionalFreeTagged optionalFreeTagged, _s_a3c68208_debugCallback debugCallback, _s_a3c68208_sdkVersion sdkVersion, _s_a3c68208_sdkExtensionsCount sdkExtensionsCount, _s_a3c68208_sdkExtensions sdkExtensions, _s_a3c68208_optionalProgramName optionalProgramName, _s_a3c68208_optionalProgramVersion optionalProgramVersion, _s_a3c68208_optionalEngineName optionalEngineName, _s_a3c68208_optionalEngineVersion optionalEngineVersion, _s_a3c68208_optionalSettings optionalSettings, _s_a3c68208_outContext outContext, _s_a3c68208_outStatuses outStatuses, _s_a3c68208_optionalFile optionalFile, _s_a3c68208_optionalLine optionalLine, _s_a3c68208_optionalUserData optionalUserData, _s_a3c68208_rteParameters rteParameters) {
  return redRteCreateContext(mallocFn.value, freeFn.value, optionalMallocTagged.value, optionalFreeTagged.value, debugCallback.value, sdkVersion.value, sdkExtensionsCount.value, sdkExtensions.value, optionalProgramName.value, optionalProgramVersion.value, optionalEngineName.value, optionalEngineVersion.value, optionalSettings.value, outContext.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyContext redRteDestroyContext
#define _cba668f6_context(value) value
#define _cba668f6_optionalFile(value) value
#define _cba668f6_optionalLine(value) value
#define _cba668f6_optionalUserData(value) value
#define _cba668f6_rteParameters(value) value
#else
typedef struct _s_cba668f6_context { RedContext value; } _s_cba668f6_context;
typedef struct _s_cba668f6_optionalFile { char* value; } _s_cba668f6_optionalFile;
typedef struct _s_cba668f6_optionalLine { int value; } _s_cba668f6_optionalLine;
typedef struct _s_cba668f6_optionalUserData { void* value; } _s_cba668f6_optionalUserData;
typedef struct _s_cba668f6_rteParameters { RedRteDestroyContextParameters* value; } _s_cba668f6_rteParameters;
static inline _s_cba668f6_context _cba668f6_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_cba668f6_context){value}; }
static inline _s_cba668f6_optionalFile _cba668f6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cba668f6_optionalFile){value}; }
static inline _s_cba668f6_optionalLine _cba668f6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cba668f6_optionalLine){value}; }
static inline _s_cba668f6_optionalUserData _cba668f6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cba668f6_optionalUserData){value}; }
static inline _s_cba668f6_rteParameters _cba668f6_rteParameters(RedRteDestroyContextParameters* value) { return REDGPU_NP_STRUCT_INIT(_s_cba668f6_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyContext(_s_cba668f6_context context, _s_cba668f6_optionalFile optionalFile, _s_cba668f6_optionalLine optionalLine, _s_cba668f6_optionalUserData optionalUserData, _s_cba668f6_rteParameters rteParameters) {
  return redRteDestroyContext(context.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateQueue redRteCreateQueue
#define _b155f18d_rteContext(value) value
#define _b155f18d_handleName(value) value
#define _b155f18d_queueFlags(value) value
#define _b155f18d_queuePriority(value) value
#define _b155f18d_outRteQueue(value) value
#define _b155f18d_outStatuses(value) value
#define _b155f18d_optionalFile(value) value
#define _b155f18d_optionalLine(value) value
#define _b155f18d_optionalUserData(value) value
#define _b155f18d_rteParameters(value) value
#else
typedef struct _s_b155f18d_rteContext { RedRteHandleContext value; } _s_b155f18d_rteContext;
typedef struct _s_b155f18d_handleName { char* value; } _s_b155f18d_handleName;
typedef struct _s_b155f18d_queueFlags { RedRteQueueBitflags value; } _s_b155f18d_queueFlags;
typedef struct _s_b155f18d_queuePriority { float value; } _s_b155f18d_queuePriority;
typedef struct _s_b155f18d_outRteQueue { RedRteQueue* value; } _s_b155f18d_outRteQueue;
typedef struct _s_b155f18d_outStatuses { RedStatuses* value; } _s_b155f18d_outStatuses;
typedef struct _s_b155f18d_optionalFile { char* value; } _s_b155f18d_optionalFile;
typedef struct _s_b155f18d_optionalLine { int value; } _s_b155f18d_optionalLine;
typedef struct _s_b155f18d_optionalUserData { void* value; } _s_b155f18d_optionalUserData;
typedef struct _s_b155f18d_rteParameters { void* value; } _s_b155f18d_rteParameters;
static inline _s_b155f18d_rteContext _b155f18d_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_b155f18d_rteContext){value}; }
static inline _s_b155f18d_handleName _b155f18d_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b155f18d_handleName){value}; }
static inline _s_b155f18d_queueFlags _b155f18d_queueFlags(RedRteQueueBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_b155f18d_queueFlags){value}; }
static inline _s_b155f18d_queuePriority _b155f18d_queuePriority(float value) { return REDGPU_NP_STRUCT_INIT(_s_b155f18d_queuePriority){value}; }
static inline _s_b155f18d_outRteQueue _b155f18d_outRteQueue(RedRteQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_b155f18d_outRteQueue){value}; }
static inline _s_b155f18d_outStatuses _b155f18d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b155f18d_outStatuses){value}; }
static inline _s_b155f18d_optionalFile _b155f18d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b155f18d_optionalFile){value}; }
static inline _s_b155f18d_optionalLine _b155f18d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b155f18d_optionalLine){value}; }
static inline _s_b155f18d_optionalUserData _b155f18d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b155f18d_optionalUserData){value}; }
static inline _s_b155f18d_rteParameters _b155f18d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b155f18d_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateQueue(_s_b155f18d_rteContext rteContext, _s_b155f18d_handleName handleName, _s_b155f18d_queueFlags queueFlags, _s_b155f18d_queuePriority queuePriority, _s_b155f18d_outRteQueue outRteQueue, _s_b155f18d_outStatuses outStatuses, _s_b155f18d_optionalFile optionalFile, _s_b155f18d_optionalLine optionalLine, _s_b155f18d_optionalUserData optionalUserData, _s_b155f18d_rteParameters rteParameters) {
  return redRteCreateQueue(rteContext.value, handleName.value, queueFlags.value, queuePriority.value, outRteQueue.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteArrayGetGpuAddress redRteArrayGetGpuAddress
#define _3dec13d3_rteContext(value) value
#define _3dec13d3_gpu(value) value
#define _3dec13d3_array(value) value
#define _3dec13d3_optionalFile(value) value
#define _3dec13d3_optionalLine(value) value
#define _3dec13d3_optionalUserData(value) value
#define _3dec13d3_rteParameters(value) value
#else
typedef struct _s_3dec13d3_rteContext { RedRteHandleContext value; } _s_3dec13d3_rteContext;
typedef struct _s_3dec13d3_gpu { RedHandleGpu value; } _s_3dec13d3_gpu;
typedef struct _s_3dec13d3_array { RedHandleArray value; } _s_3dec13d3_array;
typedef struct _s_3dec13d3_optionalFile { char* value; } _s_3dec13d3_optionalFile;
typedef struct _s_3dec13d3_optionalLine { int value; } _s_3dec13d3_optionalLine;
typedef struct _s_3dec13d3_optionalUserData { void* value; } _s_3dec13d3_optionalUserData;
typedef struct _s_3dec13d3_rteParameters { void* value; } _s_3dec13d3_rteParameters;
static inline _s_3dec13d3_rteContext _3dec13d3_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_3dec13d3_rteContext){value}; }
static inline _s_3dec13d3_gpu _3dec13d3_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_3dec13d3_gpu){value}; }
static inline _s_3dec13d3_array _3dec13d3_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_3dec13d3_array){value}; }
static inline _s_3dec13d3_optionalFile _3dec13d3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3dec13d3_optionalFile){value}; }
static inline _s_3dec13d3_optionalLine _3dec13d3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3dec13d3_optionalLine){value}; }
static inline _s_3dec13d3_optionalUserData _3dec13d3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3dec13d3_optionalUserData){value}; }
static inline _s_3dec13d3_rteParameters _3dec13d3_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3dec13d3_rteParameters){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redRteArrayGetGpuAddress(_s_3dec13d3_rteContext rteContext, _s_3dec13d3_gpu gpu, _s_3dec13d3_array array, _s_3dec13d3_optionalFile optionalFile, _s_3dec13d3_optionalLine optionalLine, _s_3dec13d3_optionalUserData optionalUserData, _s_3dec13d3_rteParameters rteParameters) {
  return redRteArrayGetGpuAddress(rteContext.value, gpu.value, array.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateHelperAllocatorDma redRteCreateHelperAllocatorDma
#define _5fbcf46f_rteContext(value) value
#define _5fbcf46f_outHelperAllocatorDma(value) value
#define _5fbcf46f_outStatuses(value) value
#define _5fbcf46f_optionalFile(value) value
#define _5fbcf46f_optionalLine(value) value
#define _5fbcf46f_optionalUserData(value) value
#define _5fbcf46f_rteParameters(value) value
#else
typedef struct _s_5fbcf46f_rteContext { RedRteHandleContext value; } _s_5fbcf46f_rteContext;
typedef struct _s_5fbcf46f_outHelperAllocatorDma { RedRteHandleHelperAllocatorDma* value; } _s_5fbcf46f_outHelperAllocatorDma;
typedef struct _s_5fbcf46f_outStatuses { RedStatuses* value; } _s_5fbcf46f_outStatuses;
typedef struct _s_5fbcf46f_optionalFile { char* value; } _s_5fbcf46f_optionalFile;
typedef struct _s_5fbcf46f_optionalLine { int value; } _s_5fbcf46f_optionalLine;
typedef struct _s_5fbcf46f_optionalUserData { void* value; } _s_5fbcf46f_optionalUserData;
typedef struct _s_5fbcf46f_rteParameters { void* value; } _s_5fbcf46f_rteParameters;
static inline _s_5fbcf46f_rteContext _5fbcf46f_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_5fbcf46f_rteContext){value}; }
static inline _s_5fbcf46f_outHelperAllocatorDma _5fbcf46f_outHelperAllocatorDma(RedRteHandleHelperAllocatorDma* value) { return REDGPU_NP_STRUCT_INIT(_s_5fbcf46f_outHelperAllocatorDma){value}; }
static inline _s_5fbcf46f_outStatuses _5fbcf46f_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_5fbcf46f_outStatuses){value}; }
static inline _s_5fbcf46f_optionalFile _5fbcf46f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5fbcf46f_optionalFile){value}; }
static inline _s_5fbcf46f_optionalLine _5fbcf46f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5fbcf46f_optionalLine){value}; }
static inline _s_5fbcf46f_optionalUserData _5fbcf46f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5fbcf46f_optionalUserData){value}; }
static inline _s_5fbcf46f_rteParameters _5fbcf46f_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5fbcf46f_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateHelperAllocatorDma(_s_5fbcf46f_rteContext rteContext, _s_5fbcf46f_outHelperAllocatorDma outHelperAllocatorDma, _s_5fbcf46f_outStatuses outStatuses, _s_5fbcf46f_optionalFile optionalFile, _s_5fbcf46f_optionalLine optionalLine, _s_5fbcf46f_optionalUserData optionalUserData, _s_5fbcf46f_rteParameters rteParameters) {
  return redRteCreateHelperAllocatorDma(rteContext.value, outHelperAllocatorDma.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyHelperAllocatorDma redRteDestroyHelperAllocatorDma
#define _7966010f_helperAllocatorDma(value) value
#define _7966010f_optionalFile(value) value
#define _7966010f_optionalLine(value) value
#define _7966010f_optionalUserData(value) value
#define _7966010f_rteParameters(value) value
#else
typedef struct _s_7966010f_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_7966010f_helperAllocatorDma;
typedef struct _s_7966010f_optionalFile { char* value; } _s_7966010f_optionalFile;
typedef struct _s_7966010f_optionalLine { int value; } _s_7966010f_optionalLine;
typedef struct _s_7966010f_optionalUserData { void* value; } _s_7966010f_optionalUserData;
typedef struct _s_7966010f_rteParameters { void* value; } _s_7966010f_rteParameters;
static inline _s_7966010f_helperAllocatorDma _7966010f_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_7966010f_helperAllocatorDma){value}; }
static inline _s_7966010f_optionalFile _7966010f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7966010f_optionalFile){value}; }
static inline _s_7966010f_optionalLine _7966010f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7966010f_optionalLine){value}; }
static inline _s_7966010f_optionalUserData _7966010f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7966010f_optionalUserData){value}; }
static inline _s_7966010f_rteParameters _7966010f_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7966010f_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyHelperAllocatorDma(_s_7966010f_helperAllocatorDma helperAllocatorDma, _s_7966010f_optionalFile optionalFile, _s_7966010f_optionalLine optionalLine, _s_7966010f_optionalUserData optionalUserData, _s_7966010f_rteParameters rteParameters) {
  return redRteDestroyHelperAllocatorDma(helperAllocatorDma.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaCreateArray redRteHelperAllocatorDmaCreateArray
#define _00c3eb95_helperAllocatorDma(value) value
#define _00c3eb95_arrayInfo(value) value
#define _00c3eb95_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _00c3eb95_outRteHelperArray(value) value
#define _00c3eb95_outStatuses(value) value
#define _00c3eb95_optionalFile(value) value
#define _00c3eb95_optionalLine(value) value
#define _00c3eb95_optionalUserData(value) value
#define _00c3eb95_rteParameters(value) value
#else
typedef struct _s_00c3eb95_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_00c3eb95_helperAllocatorDma;
typedef struct _s_00c3eb95_arrayInfo { RedRteHelperCreateArrayInfo* value; } _s_00c3eb95_arrayInfo;
typedef struct _s_00c3eb95_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_00c3eb95_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_00c3eb95_outRteHelperArray { RedRteHelperArray* value; } _s_00c3eb95_outRteHelperArray;
typedef struct _s_00c3eb95_outStatuses { RedStatuses* value; } _s_00c3eb95_outStatuses;
typedef struct _s_00c3eb95_optionalFile { char* value; } _s_00c3eb95_optionalFile;
typedef struct _s_00c3eb95_optionalLine { int value; } _s_00c3eb95_optionalLine;
typedef struct _s_00c3eb95_optionalUserData { void* value; } _s_00c3eb95_optionalUserData;
typedef struct _s_00c3eb95_rteParameters { void* value; } _s_00c3eb95_rteParameters;
static inline _s_00c3eb95_helperAllocatorDma _00c3eb95_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_00c3eb95_helperAllocatorDma){value}; }
static inline _s_00c3eb95_arrayInfo _00c3eb95_arrayInfo(RedRteHelperCreateArrayInfo* value) { return REDGPU_NP_STRUCT_INIT(_s_00c3eb95_arrayInfo){value}; }
static inline _s_00c3eb95_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _00c3eb95_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_00c3eb95_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_00c3eb95_outRteHelperArray _00c3eb95_outRteHelperArray(RedRteHelperArray* value) { return REDGPU_NP_STRUCT_INIT(_s_00c3eb95_outRteHelperArray){value}; }
static inline _s_00c3eb95_outStatuses _00c3eb95_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_00c3eb95_outStatuses){value}; }
static inline _s_00c3eb95_optionalFile _00c3eb95_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_00c3eb95_optionalFile){value}; }
static inline _s_00c3eb95_optionalLine _00c3eb95_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_00c3eb95_optionalLine){value}; }
static inline _s_00c3eb95_optionalUserData _00c3eb95_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_00c3eb95_optionalUserData){value}; }
static inline _s_00c3eb95_rteParameters _00c3eb95_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_00c3eb95_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaCreateArray(_s_00c3eb95_helperAllocatorDma helperAllocatorDma, _s_00c3eb95_arrayInfo arrayInfo, _s_00c3eb95_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_00c3eb95_outRteHelperArray outRteHelperArray, _s_00c3eb95_outStatuses outStatuses, _s_00c3eb95_optionalFile optionalFile, _s_00c3eb95_optionalLine optionalLine, _s_00c3eb95_optionalUserData optionalUserData, _s_00c3eb95_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaCreateArray(helperAllocatorDma.value, arrayInfo.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaCreateImage redRteHelperAllocatorDmaCreateImage
#define _dffd8455_helperAllocatorDma(value) value
#define _dffd8455_imageInfo(value) value
#define _dffd8455_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _dffd8455_outRteHelperImage(value) value
#define _dffd8455_outStatuses(value) value
#define _dffd8455_optionalFile(value) value
#define _dffd8455_optionalLine(value) value
#define _dffd8455_optionalUserData(value) value
#define _dffd8455_rteParameters(value) value
#else
typedef struct _s_dffd8455_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_dffd8455_helperAllocatorDma;
typedef struct _s_dffd8455_imageInfo { RedRteHelperCreateImageInfo* value; } _s_dffd8455_imageInfo;
typedef struct _s_dffd8455_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_dffd8455_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_dffd8455_outRteHelperImage { RedRteHelperImage* value; } _s_dffd8455_outRteHelperImage;
typedef struct _s_dffd8455_outStatuses { RedStatuses* value; } _s_dffd8455_outStatuses;
typedef struct _s_dffd8455_optionalFile { char* value; } _s_dffd8455_optionalFile;
typedef struct _s_dffd8455_optionalLine { int value; } _s_dffd8455_optionalLine;
typedef struct _s_dffd8455_optionalUserData { void* value; } _s_dffd8455_optionalUserData;
typedef struct _s_dffd8455_rteParameters { void* value; } _s_dffd8455_rteParameters;
static inline _s_dffd8455_helperAllocatorDma _dffd8455_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_dffd8455_helperAllocatorDma){value}; }
static inline _s_dffd8455_imageInfo _dffd8455_imageInfo(RedRteHelperCreateImageInfo* value) { return REDGPU_NP_STRUCT_INIT(_s_dffd8455_imageInfo){value}; }
static inline _s_dffd8455_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _dffd8455_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_dffd8455_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_dffd8455_outRteHelperImage _dffd8455_outRteHelperImage(RedRteHelperImage* value) { return REDGPU_NP_STRUCT_INIT(_s_dffd8455_outRteHelperImage){value}; }
static inline _s_dffd8455_outStatuses _dffd8455_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_dffd8455_outStatuses){value}; }
static inline _s_dffd8455_optionalFile _dffd8455_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_dffd8455_optionalFile){value}; }
static inline _s_dffd8455_optionalLine _dffd8455_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_dffd8455_optionalLine){value}; }
static inline _s_dffd8455_optionalUserData _dffd8455_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_dffd8455_optionalUserData){value}; }
static inline _s_dffd8455_rteParameters _dffd8455_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_dffd8455_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaCreateImage(_s_dffd8455_helperAllocatorDma helperAllocatorDma, _s_dffd8455_imageInfo imageInfo, _s_dffd8455_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_dffd8455_outRteHelperImage outRteHelperImage, _s_dffd8455_outStatuses outStatuses, _s_dffd8455_optionalFile optionalFile, _s_dffd8455_optionalLine optionalLine, _s_dffd8455_optionalUserData optionalUserData, _s_dffd8455_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaCreateImage(helperAllocatorDma.value, imageInfo.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperImage.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaCreateArraySimple redRteHelperAllocatorDmaCreateArraySimple
#define _e34316c9_helperAllocatorDma(value) value
#define _e34316c9_arrayBytesCount(value) value
#define _e34316c9_arrayUsageFlags(value) value
#define _e34316c9_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _e34316c9_outRteHelperArray(value) value
#define _e34316c9_outStatuses(value) value
#define _e34316c9_optionalFile(value) value
#define _e34316c9_optionalLine(value) value
#define _e34316c9_optionalUserData(value) value
#define _e34316c9_rteParameters(value) value
#else
typedef struct _s_e34316c9_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_e34316c9_helperAllocatorDma;
typedef struct _s_e34316c9_arrayBytesCount { uint64_t value; } _s_e34316c9_arrayBytesCount;
typedef struct _s_e34316c9_arrayUsageFlags { unsigned value; } _s_e34316c9_arrayUsageFlags;
typedef struct _s_e34316c9_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_e34316c9_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_e34316c9_outRteHelperArray { RedRteHelperArray* value; } _s_e34316c9_outRteHelperArray;
typedef struct _s_e34316c9_outStatuses { RedStatuses* value; } _s_e34316c9_outStatuses;
typedef struct _s_e34316c9_optionalFile { char* value; } _s_e34316c9_optionalFile;
typedef struct _s_e34316c9_optionalLine { int value; } _s_e34316c9_optionalLine;
typedef struct _s_e34316c9_optionalUserData { void* value; } _s_e34316c9_optionalUserData;
typedef struct _s_e34316c9_rteParameters { void* value; } _s_e34316c9_rteParameters;
static inline _s_e34316c9_helperAllocatorDma _e34316c9_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_e34316c9_helperAllocatorDma){value}; }
static inline _s_e34316c9_arrayBytesCount _e34316c9_arrayBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_e34316c9_arrayBytesCount){value}; }
static inline _s_e34316c9_arrayUsageFlags _e34316c9_arrayUsageFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e34316c9_arrayUsageFlags){value}; }
static inline _s_e34316c9_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _e34316c9_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e34316c9_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_e34316c9_outRteHelperArray _e34316c9_outRteHelperArray(RedRteHelperArray* value) { return REDGPU_NP_STRUCT_INIT(_s_e34316c9_outRteHelperArray){value}; }
static inline _s_e34316c9_outStatuses _e34316c9_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_e34316c9_outStatuses){value}; }
static inline _s_e34316c9_optionalFile _e34316c9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e34316c9_optionalFile){value}; }
static inline _s_e34316c9_optionalLine _e34316c9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e34316c9_optionalLine){value}; }
static inline _s_e34316c9_optionalUserData _e34316c9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e34316c9_optionalUserData){value}; }
static inline _s_e34316c9_rteParameters _e34316c9_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e34316c9_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaCreateArraySimple(_s_e34316c9_helperAllocatorDma helperAllocatorDma, _s_e34316c9_arrayBytesCount arrayBytesCount, _s_e34316c9_arrayUsageFlags arrayUsageFlags, _s_e34316c9_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_e34316c9_outRteHelperArray outRteHelperArray, _s_e34316c9_outStatuses outStatuses, _s_e34316c9_optionalFile optionalFile, _s_e34316c9_optionalLine optionalLine, _s_e34316c9_optionalUserData optionalUserData, _s_e34316c9_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaCreateArraySimple(helperAllocatorDma.value, arrayBytesCount.value, arrayUsageFlags.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaCreateArraySimpleWithData redRteHelperAllocatorDmaCreateArraySimpleWithData
#define _9059ed9d_helperAllocatorDma(value) value
#define _9059ed9d_callsSetToUploadArrayData(value) value
#define _9059ed9d_arrayDataBytesCount(value) value
#define _9059ed9d_arrayData(value) value
#define _9059ed9d_arrayUsageFlags(value) value
#define _9059ed9d_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _9059ed9d_outRteHelperArray(value) value
#define _9059ed9d_outStatuses(value) value
#define _9059ed9d_optionalFile(value) value
#define _9059ed9d_optionalLine(value) value
#define _9059ed9d_optionalUserData(value) value
#define _9059ed9d_rteParameters(value) value
#else
typedef struct _s_9059ed9d_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_9059ed9d_helperAllocatorDma;
typedef struct _s_9059ed9d_callsSetToUploadArrayData { RedHandleCalls value; } _s_9059ed9d_callsSetToUploadArrayData;
typedef struct _s_9059ed9d_arrayDataBytesCount { uint64_t value; } _s_9059ed9d_arrayDataBytesCount;
typedef struct _s_9059ed9d_arrayData { void* value; } _s_9059ed9d_arrayData;
typedef struct _s_9059ed9d_arrayUsageFlags { unsigned value; } _s_9059ed9d_arrayUsageFlags;
typedef struct _s_9059ed9d_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_9059ed9d_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_9059ed9d_outRteHelperArray { RedRteHelperArray* value; } _s_9059ed9d_outRteHelperArray;
typedef struct _s_9059ed9d_outStatuses { RedStatuses* value; } _s_9059ed9d_outStatuses;
typedef struct _s_9059ed9d_optionalFile { char* value; } _s_9059ed9d_optionalFile;
typedef struct _s_9059ed9d_optionalLine { int value; } _s_9059ed9d_optionalLine;
typedef struct _s_9059ed9d_optionalUserData { void* value; } _s_9059ed9d_optionalUserData;
typedef struct _s_9059ed9d_rteParameters { void* value; } _s_9059ed9d_rteParameters;
static inline _s_9059ed9d_helperAllocatorDma _9059ed9d_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_9059ed9d_helperAllocatorDma){value}; }
static inline _s_9059ed9d_callsSetToUploadArrayData _9059ed9d_callsSetToUploadArrayData(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_9059ed9d_callsSetToUploadArrayData){value}; }
static inline _s_9059ed9d_arrayDataBytesCount _9059ed9d_arrayDataBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_9059ed9d_arrayDataBytesCount){value}; }
static inline _s_9059ed9d_arrayData _9059ed9d_arrayData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9059ed9d_arrayData){value}; }
static inline _s_9059ed9d_arrayUsageFlags _9059ed9d_arrayUsageFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9059ed9d_arrayUsageFlags){value}; }
static inline _s_9059ed9d_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _9059ed9d_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9059ed9d_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_9059ed9d_outRteHelperArray _9059ed9d_outRteHelperArray(RedRteHelperArray* value) { return REDGPU_NP_STRUCT_INIT(_s_9059ed9d_outRteHelperArray){value}; }
static inline _s_9059ed9d_outStatuses _9059ed9d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_9059ed9d_outStatuses){value}; }
static inline _s_9059ed9d_optionalFile _9059ed9d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9059ed9d_optionalFile){value}; }
static inline _s_9059ed9d_optionalLine _9059ed9d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9059ed9d_optionalLine){value}; }
static inline _s_9059ed9d_optionalUserData _9059ed9d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9059ed9d_optionalUserData){value}; }
static inline _s_9059ed9d_rteParameters _9059ed9d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9059ed9d_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaCreateArraySimpleWithData(_s_9059ed9d_helperAllocatorDma helperAllocatorDma, _s_9059ed9d_callsSetToUploadArrayData callsSetToUploadArrayData, _s_9059ed9d_arrayDataBytesCount arrayDataBytesCount, _s_9059ed9d_arrayData arrayData, _s_9059ed9d_arrayUsageFlags arrayUsageFlags, _s_9059ed9d_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_9059ed9d_outRteHelperArray outRteHelperArray, _s_9059ed9d_outStatuses outStatuses, _s_9059ed9d_optionalFile optionalFile, _s_9059ed9d_optionalLine optionalLine, _s_9059ed9d_optionalUserData optionalUserData, _s_9059ed9d_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaCreateArraySimpleWithData(helperAllocatorDma.value, callsSetToUploadArrayData.value, arrayDataBytesCount.value, arrayData.value, arrayUsageFlags.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaCreateImageSimpleWithData redRteHelperAllocatorDmaCreateImageSimpleWithData
#define _6a16c8d3_helperAllocatorDma(value) value
#define _6a16c8d3_callsSetToUploadImageData(value) value
#define _6a16c8d3_imageDataBytesCount(value) value
#define _6a16c8d3_imageData(value) value
#define _6a16c8d3_imageInfo(value) value
#define _6a16c8d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral(value) value
#define _6a16c8d3_outRteHelperImage(value) value
#define _6a16c8d3_outStatuses(value) value
#define _6a16c8d3_optionalFile(value) value
#define _6a16c8d3_optionalLine(value) value
#define _6a16c8d3_optionalUserData(value) value
#define _6a16c8d3_rteParameters(value) value
#else
typedef struct _s_6a16c8d3_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_6a16c8d3_helperAllocatorDma;
typedef struct _s_6a16c8d3_callsSetToUploadImageData { RedHandleCalls value; } _s_6a16c8d3_callsSetToUploadImageData;
typedef struct _s_6a16c8d3_imageDataBytesCount { uint64_t value; } _s_6a16c8d3_imageDataBytesCount;
typedef struct _s_6a16c8d3_imageData { void* value; } _s_6a16c8d3_imageData;
typedef struct _s_6a16c8d3_imageInfo { RedRteHelperCreateImageInfo* value; } _s_6a16c8d3_imageInfo;
typedef struct _s_6a16c8d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral { unsigned value; } _s_6a16c8d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral;
typedef struct _s_6a16c8d3_outRteHelperImage { RedRteHelperImage* value; } _s_6a16c8d3_outRteHelperImage;
typedef struct _s_6a16c8d3_outStatuses { RedStatuses* value; } _s_6a16c8d3_outStatuses;
typedef struct _s_6a16c8d3_optionalFile { char* value; } _s_6a16c8d3_optionalFile;
typedef struct _s_6a16c8d3_optionalLine { int value; } _s_6a16c8d3_optionalLine;
typedef struct _s_6a16c8d3_optionalUserData { void* value; } _s_6a16c8d3_optionalUserData;
typedef struct _s_6a16c8d3_rteParameters { void* value; } _s_6a16c8d3_rteParameters;
static inline _s_6a16c8d3_helperAllocatorDma _6a16c8d3_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_6a16c8d3_helperAllocatorDma){value}; }
static inline _s_6a16c8d3_callsSetToUploadImageData _6a16c8d3_callsSetToUploadImageData(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_6a16c8d3_callsSetToUploadImageData){value}; }
static inline _s_6a16c8d3_imageDataBytesCount _6a16c8d3_imageDataBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_6a16c8d3_imageDataBytesCount){value}; }
static inline _s_6a16c8d3_imageData _6a16c8d3_imageData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6a16c8d3_imageData){value}; }
static inline _s_6a16c8d3_imageInfo _6a16c8d3_imageInfo(RedRteHelperCreateImageInfo* value) { return REDGPU_NP_STRUCT_INIT(_s_6a16c8d3_imageInfo){value}; }
static inline _s_6a16c8d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral _6a16c8d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6a16c8d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral){value}; }
static inline _s_6a16c8d3_outRteHelperImage _6a16c8d3_outRteHelperImage(RedRteHelperImage* value) { return REDGPU_NP_STRUCT_INIT(_s_6a16c8d3_outRteHelperImage){value}; }
static inline _s_6a16c8d3_outStatuses _6a16c8d3_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_6a16c8d3_outStatuses){value}; }
static inline _s_6a16c8d3_optionalFile _6a16c8d3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6a16c8d3_optionalFile){value}; }
static inline _s_6a16c8d3_optionalLine _6a16c8d3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6a16c8d3_optionalLine){value}; }
static inline _s_6a16c8d3_optionalUserData _6a16c8d3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6a16c8d3_optionalUserData){value}; }
static inline _s_6a16c8d3_rteParameters _6a16c8d3_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6a16c8d3_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaCreateImageSimpleWithData(_s_6a16c8d3_helperAllocatorDma helperAllocatorDma, _s_6a16c8d3_callsSetToUploadImageData callsSetToUploadImageData, _s_6a16c8d3_imageDataBytesCount imageDataBytesCount, _s_6a16c8d3_imageData imageData, _s_6a16c8d3_imageInfo imageInfo, _s_6a16c8d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral imageLayoutSuggestedDefaultValueIsImageLayoutGeneral, _s_6a16c8d3_outRteHelperImage outRteHelperImage, _s_6a16c8d3_outStatuses outStatuses, _s_6a16c8d3_optionalFile optionalFile, _s_6a16c8d3_optionalLine optionalLine, _s_6a16c8d3_optionalUserData optionalUserData, _s_6a16c8d3_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaCreateImageSimpleWithData(helperAllocatorDma.value, callsSetToUploadImageData.value, imageDataBytesCount.value, imageData.value, imageInfo.value, imageLayoutSuggestedDefaultValueIsImageLayoutGeneral.value, outRteHelperImage.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaDestroyArray redRteHelperAllocatorDmaDestroyArray
#define _2d758ca1_helperAllocatorDma(value) value
#define _2d758ca1_rteHelperArray(value) value
#define _2d758ca1_rteHelperAllocatorResourceMemory(value) value
#define _2d758ca1_outStatuses(value) value
#define _2d758ca1_optionalFile(value) value
#define _2d758ca1_optionalLine(value) value
#define _2d758ca1_optionalUserData(value) value
#define _2d758ca1_rteParameters(value) value
#else
typedef struct _s_2d758ca1_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_2d758ca1_helperAllocatorDma;
typedef struct _s_2d758ca1_rteHelperArray { RedHandleArray value; } _s_2d758ca1_rteHelperArray;
typedef struct _s_2d758ca1_rteHelperAllocatorResourceMemory { void* value; } _s_2d758ca1_rteHelperAllocatorResourceMemory;
typedef struct _s_2d758ca1_outStatuses { RedStatuses* value; } _s_2d758ca1_outStatuses;
typedef struct _s_2d758ca1_optionalFile { char* value; } _s_2d758ca1_optionalFile;
typedef struct _s_2d758ca1_optionalLine { int value; } _s_2d758ca1_optionalLine;
typedef struct _s_2d758ca1_optionalUserData { void* value; } _s_2d758ca1_optionalUserData;
typedef struct _s_2d758ca1_rteParameters { void* value; } _s_2d758ca1_rteParameters;
static inline _s_2d758ca1_helperAllocatorDma _2d758ca1_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_2d758ca1_helperAllocatorDma){value}; }
static inline _s_2d758ca1_rteHelperArray _2d758ca1_rteHelperArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_2d758ca1_rteHelperArray){value}; }
static inline _s_2d758ca1_rteHelperAllocatorResourceMemory _2d758ca1_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2d758ca1_rteHelperAllocatorResourceMemory){value}; }
static inline _s_2d758ca1_outStatuses _2d758ca1_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_2d758ca1_outStatuses){value}; }
static inline _s_2d758ca1_optionalFile _2d758ca1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2d758ca1_optionalFile){value}; }
static inline _s_2d758ca1_optionalLine _2d758ca1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2d758ca1_optionalLine){value}; }
static inline _s_2d758ca1_optionalUserData _2d758ca1_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2d758ca1_optionalUserData){value}; }
static inline _s_2d758ca1_rteParameters _2d758ca1_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2d758ca1_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaDestroyArray(_s_2d758ca1_helperAllocatorDma helperAllocatorDma, _s_2d758ca1_rteHelperArray rteHelperArray, _s_2d758ca1_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_2d758ca1_outStatuses outStatuses, _s_2d758ca1_optionalFile optionalFile, _s_2d758ca1_optionalLine optionalLine, _s_2d758ca1_optionalUserData optionalUserData, _s_2d758ca1_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaDestroyArray(helperAllocatorDma.value, rteHelperArray.value, rteHelperAllocatorResourceMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaDestroyImage redRteHelperAllocatorDmaDestroyImage
#define _d6f5518e_helperAllocatorDma(value) value
#define _d6f5518e_rteHelperImage(value) value
#define _d6f5518e_rteHelperAllocatorResourceMemory(value) value
#define _d6f5518e_outStatuses(value) value
#define _d6f5518e_optionalFile(value) value
#define _d6f5518e_optionalLine(value) value
#define _d6f5518e_optionalUserData(value) value
#define _d6f5518e_rteParameters(value) value
#else
typedef struct _s_d6f5518e_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_d6f5518e_helperAllocatorDma;
typedef struct _s_d6f5518e_rteHelperImage { RedHandleImage value; } _s_d6f5518e_rteHelperImage;
typedef struct _s_d6f5518e_rteHelperAllocatorResourceMemory { void* value; } _s_d6f5518e_rteHelperAllocatorResourceMemory;
typedef struct _s_d6f5518e_outStatuses { RedStatuses* value; } _s_d6f5518e_outStatuses;
typedef struct _s_d6f5518e_optionalFile { char* value; } _s_d6f5518e_optionalFile;
typedef struct _s_d6f5518e_optionalLine { int value; } _s_d6f5518e_optionalLine;
typedef struct _s_d6f5518e_optionalUserData { void* value; } _s_d6f5518e_optionalUserData;
typedef struct _s_d6f5518e_rteParameters { void* value; } _s_d6f5518e_rteParameters;
static inline _s_d6f5518e_helperAllocatorDma _d6f5518e_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_d6f5518e_helperAllocatorDma){value}; }
static inline _s_d6f5518e_rteHelperImage _d6f5518e_rteHelperImage(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_d6f5518e_rteHelperImage){value}; }
static inline _s_d6f5518e_rteHelperAllocatorResourceMemory _d6f5518e_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d6f5518e_rteHelperAllocatorResourceMemory){value}; }
static inline _s_d6f5518e_outStatuses _d6f5518e_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_d6f5518e_outStatuses){value}; }
static inline _s_d6f5518e_optionalFile _d6f5518e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d6f5518e_optionalFile){value}; }
static inline _s_d6f5518e_optionalLine _d6f5518e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d6f5518e_optionalLine){value}; }
static inline _s_d6f5518e_optionalUserData _d6f5518e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d6f5518e_optionalUserData){value}; }
static inline _s_d6f5518e_rteParameters _d6f5518e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d6f5518e_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaDestroyImage(_s_d6f5518e_helperAllocatorDma helperAllocatorDma, _s_d6f5518e_rteHelperImage rteHelperImage, _s_d6f5518e_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_d6f5518e_outStatuses outStatuses, _s_d6f5518e_optionalFile optionalFile, _s_d6f5518e_optionalLine optionalLine, _s_d6f5518e_optionalUserData optionalUserData, _s_d6f5518e_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaDestroyImage(helperAllocatorDma.value, rteHelperImage.value, rteHelperAllocatorResourceMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaFinalizeAndReleaseStagingMemory redRteHelperAllocatorDmaFinalizeAndReleaseStagingMemory
#define _b8199348_helperAllocatorDma(value) value
#define _b8199348_optionalCpuSignal(value) value
#define _b8199348_outStatuses(value) value
#define _b8199348_optionalFile(value) value
#define _b8199348_optionalLine(value) value
#define _b8199348_optionalUserData(value) value
#define _b8199348_rteParameters(value) value
#else
typedef struct _s_b8199348_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_b8199348_helperAllocatorDma;
typedef struct _s_b8199348_optionalCpuSignal { RedHandleCpuSignal value; } _s_b8199348_optionalCpuSignal;
typedef struct _s_b8199348_outStatuses { RedStatuses* value; } _s_b8199348_outStatuses;
typedef struct _s_b8199348_optionalFile { char* value; } _s_b8199348_optionalFile;
typedef struct _s_b8199348_optionalLine { int value; } _s_b8199348_optionalLine;
typedef struct _s_b8199348_optionalUserData { void* value; } _s_b8199348_optionalUserData;
typedef struct _s_b8199348_rteParameters { void* value; } _s_b8199348_rteParameters;
static inline _s_b8199348_helperAllocatorDma _b8199348_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_b8199348_helperAllocatorDma){value}; }
static inline _s_b8199348_optionalCpuSignal _b8199348_optionalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_b8199348_optionalCpuSignal){value}; }
static inline _s_b8199348_outStatuses _b8199348_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b8199348_outStatuses){value}; }
static inline _s_b8199348_optionalFile _b8199348_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b8199348_optionalFile){value}; }
static inline _s_b8199348_optionalLine _b8199348_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b8199348_optionalLine){value}; }
static inline _s_b8199348_optionalUserData _b8199348_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b8199348_optionalUserData){value}; }
static inline _s_b8199348_rteParameters _b8199348_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b8199348_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaFinalizeAndReleaseStagingMemory(_s_b8199348_helperAllocatorDma helperAllocatorDma, _s_b8199348_optionalCpuSignal optionalCpuSignal, _s_b8199348_outStatuses outStatuses, _s_b8199348_optionalFile optionalFile, _s_b8199348_optionalLine optionalLine, _s_b8199348_optionalUserData optionalUserData, _s_b8199348_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaFinalizeAndReleaseStagingMemory(helperAllocatorDma.value, optionalCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaFinalizeStagingMemory redRteHelperAllocatorDmaFinalizeStagingMemory
#define _78c802c1_helperAllocatorDma(value) value
#define _78c802c1_optionalCpuSignal(value) value
#define _78c802c1_outStatuses(value) value
#define _78c802c1_optionalFile(value) value
#define _78c802c1_optionalLine(value) value
#define _78c802c1_optionalUserData(value) value
#define _78c802c1_rteParameters(value) value
#else
typedef struct _s_78c802c1_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_78c802c1_helperAllocatorDma;
typedef struct _s_78c802c1_optionalCpuSignal { RedHandleCpuSignal value; } _s_78c802c1_optionalCpuSignal;
typedef struct _s_78c802c1_outStatuses { RedStatuses* value; } _s_78c802c1_outStatuses;
typedef struct _s_78c802c1_optionalFile { char* value; } _s_78c802c1_optionalFile;
typedef struct _s_78c802c1_optionalLine { int value; } _s_78c802c1_optionalLine;
typedef struct _s_78c802c1_optionalUserData { void* value; } _s_78c802c1_optionalUserData;
typedef struct _s_78c802c1_rteParameters { void* value; } _s_78c802c1_rteParameters;
static inline _s_78c802c1_helperAllocatorDma _78c802c1_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_78c802c1_helperAllocatorDma){value}; }
static inline _s_78c802c1_optionalCpuSignal _78c802c1_optionalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_78c802c1_optionalCpuSignal){value}; }
static inline _s_78c802c1_outStatuses _78c802c1_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_78c802c1_outStatuses){value}; }
static inline _s_78c802c1_optionalFile _78c802c1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_78c802c1_optionalFile){value}; }
static inline _s_78c802c1_optionalLine _78c802c1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_78c802c1_optionalLine){value}; }
static inline _s_78c802c1_optionalUserData _78c802c1_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_78c802c1_optionalUserData){value}; }
static inline _s_78c802c1_rteParameters _78c802c1_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_78c802c1_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaFinalizeStagingMemory(_s_78c802c1_helperAllocatorDma helperAllocatorDma, _s_78c802c1_optionalCpuSignal optionalCpuSignal, _s_78c802c1_outStatuses outStatuses, _s_78c802c1_optionalFile optionalFile, _s_78c802c1_optionalLine optionalLine, _s_78c802c1_optionalUserData optionalUserData, _s_78c802c1_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaFinalizeStagingMemory(helperAllocatorDma.value, optionalCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaReleaseStagingMemory redRteHelperAllocatorDmaReleaseStagingMemory
#define _b10d824d_helperAllocatorDma(value) value
#define _b10d824d_outStatuses(value) value
#define _b10d824d_optionalFile(value) value
#define _b10d824d_optionalLine(value) value
#define _b10d824d_optionalUserData(value) value
#define _b10d824d_rteParameters(value) value
#else
typedef struct _s_b10d824d_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_b10d824d_helperAllocatorDma;
typedef struct _s_b10d824d_outStatuses { RedStatuses* value; } _s_b10d824d_outStatuses;
typedef struct _s_b10d824d_optionalFile { char* value; } _s_b10d824d_optionalFile;
typedef struct _s_b10d824d_optionalLine { int value; } _s_b10d824d_optionalLine;
typedef struct _s_b10d824d_optionalUserData { void* value; } _s_b10d824d_optionalUserData;
typedef struct _s_b10d824d_rteParameters { void* value; } _s_b10d824d_rteParameters;
static inline _s_b10d824d_helperAllocatorDma _b10d824d_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_b10d824d_helperAllocatorDma){value}; }
static inline _s_b10d824d_outStatuses _b10d824d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b10d824d_outStatuses){value}; }
static inline _s_b10d824d_optionalFile _b10d824d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b10d824d_optionalFile){value}; }
static inline _s_b10d824d_optionalLine _b10d824d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b10d824d_optionalLine){value}; }
static inline _s_b10d824d_optionalUserData _b10d824d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b10d824d_optionalUserData){value}; }
static inline _s_b10d824d_rteParameters _b10d824d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b10d824d_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaReleaseStagingMemory(_s_b10d824d_helperAllocatorDma helperAllocatorDma, _s_b10d824d_outStatuses outStatuses, _s_b10d824d_optionalFile optionalFile, _s_b10d824d_optionalLine optionalLine, _s_b10d824d_optionalUserData optionalUserData, _s_b10d824d_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaReleaseStagingMemory(helperAllocatorDma.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaMapArray redRteHelperAllocatorDmaMapArray
#define _91483c45_helperAllocatorDma(value) value
#define _91483c45_rteHelperArray(value) value
#define _91483c45_rteHelperAllocatorResourceMemory(value) value
#define _91483c45_outVolatilePointer(value) value
#define _91483c45_outStatuses(value) value
#define _91483c45_optionalFile(value) value
#define _91483c45_optionalLine(value) value
#define _91483c45_optionalUserData(value) value
#define _91483c45_rteParameters(value) value
#else
typedef struct _s_91483c45_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_91483c45_helperAllocatorDma;
typedef struct _s_91483c45_rteHelperArray { RedHandleArray value; } _s_91483c45_rteHelperArray;
typedef struct _s_91483c45_rteHelperAllocatorResourceMemory { void* value; } _s_91483c45_rteHelperAllocatorResourceMemory;
typedef struct _s_91483c45_outVolatilePointer { void** value; } _s_91483c45_outVolatilePointer;
typedef struct _s_91483c45_outStatuses { RedStatuses* value; } _s_91483c45_outStatuses;
typedef struct _s_91483c45_optionalFile { char* value; } _s_91483c45_optionalFile;
typedef struct _s_91483c45_optionalLine { int value; } _s_91483c45_optionalLine;
typedef struct _s_91483c45_optionalUserData { void* value; } _s_91483c45_optionalUserData;
typedef struct _s_91483c45_rteParameters { void* value; } _s_91483c45_rteParameters;
static inline _s_91483c45_helperAllocatorDma _91483c45_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_91483c45_helperAllocatorDma){value}; }
static inline _s_91483c45_rteHelperArray _91483c45_rteHelperArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_91483c45_rteHelperArray){value}; }
static inline _s_91483c45_rteHelperAllocatorResourceMemory _91483c45_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_91483c45_rteHelperAllocatorResourceMemory){value}; }
static inline _s_91483c45_outVolatilePointer _91483c45_outVolatilePointer(void** value) { return REDGPU_NP_STRUCT_INIT(_s_91483c45_outVolatilePointer){value}; }
static inline _s_91483c45_outStatuses _91483c45_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_91483c45_outStatuses){value}; }
static inline _s_91483c45_optionalFile _91483c45_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_91483c45_optionalFile){value}; }
static inline _s_91483c45_optionalLine _91483c45_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_91483c45_optionalLine){value}; }
static inline _s_91483c45_optionalUserData _91483c45_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_91483c45_optionalUserData){value}; }
static inline _s_91483c45_rteParameters _91483c45_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_91483c45_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaMapArray(_s_91483c45_helperAllocatorDma helperAllocatorDma, _s_91483c45_rteHelperArray rteHelperArray, _s_91483c45_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_91483c45_outVolatilePointer outVolatilePointer, _s_91483c45_outStatuses outStatuses, _s_91483c45_optionalFile optionalFile, _s_91483c45_optionalLine optionalLine, _s_91483c45_optionalUserData optionalUserData, _s_91483c45_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaMapArray(helperAllocatorDma.value, rteHelperArray.value, rteHelperAllocatorResourceMemory.value, outVolatilePointer.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaUnmapArray redRteHelperAllocatorDmaUnmapArray
#define _5a1c9b78_helperAllocatorDma(value) value
#define _5a1c9b78_rteHelperArray(value) value
#define _5a1c9b78_rteHelperAllocatorResourceMemory(value) value
#define _5a1c9b78_outStatuses(value) value
#define _5a1c9b78_optionalFile(value) value
#define _5a1c9b78_optionalLine(value) value
#define _5a1c9b78_optionalUserData(value) value
#define _5a1c9b78_rteParameters(value) value
#else
typedef struct _s_5a1c9b78_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_5a1c9b78_helperAllocatorDma;
typedef struct _s_5a1c9b78_rteHelperArray { RedHandleArray value; } _s_5a1c9b78_rteHelperArray;
typedef struct _s_5a1c9b78_rteHelperAllocatorResourceMemory { void* value; } _s_5a1c9b78_rteHelperAllocatorResourceMemory;
typedef struct _s_5a1c9b78_outStatuses { RedStatuses* value; } _s_5a1c9b78_outStatuses;
typedef struct _s_5a1c9b78_optionalFile { char* value; } _s_5a1c9b78_optionalFile;
typedef struct _s_5a1c9b78_optionalLine { int value; } _s_5a1c9b78_optionalLine;
typedef struct _s_5a1c9b78_optionalUserData { void* value; } _s_5a1c9b78_optionalUserData;
typedef struct _s_5a1c9b78_rteParameters { void* value; } _s_5a1c9b78_rteParameters;
static inline _s_5a1c9b78_helperAllocatorDma _5a1c9b78_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_5a1c9b78_helperAllocatorDma){value}; }
static inline _s_5a1c9b78_rteHelperArray _5a1c9b78_rteHelperArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_5a1c9b78_rteHelperArray){value}; }
static inline _s_5a1c9b78_rteHelperAllocatorResourceMemory _5a1c9b78_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5a1c9b78_rteHelperAllocatorResourceMemory){value}; }
static inline _s_5a1c9b78_outStatuses _5a1c9b78_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_5a1c9b78_outStatuses){value}; }
static inline _s_5a1c9b78_optionalFile _5a1c9b78_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5a1c9b78_optionalFile){value}; }
static inline _s_5a1c9b78_optionalLine _5a1c9b78_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5a1c9b78_optionalLine){value}; }
static inline _s_5a1c9b78_optionalUserData _5a1c9b78_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5a1c9b78_optionalUserData){value}; }
static inline _s_5a1c9b78_rteParameters _5a1c9b78_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5a1c9b78_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaUnmapArray(_s_5a1c9b78_helperAllocatorDma helperAllocatorDma, _s_5a1c9b78_rteHelperArray rteHelperArray, _s_5a1c9b78_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_5a1c9b78_outStatuses outStatuses, _s_5a1c9b78_optionalFile optionalFile, _s_5a1c9b78_optionalLine optionalLine, _s_5a1c9b78_optionalUserData optionalUserData, _s_5a1c9b78_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaUnmapArray(helperAllocatorDma.value, rteHelperArray.value, rteHelperAllocatorResourceMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateHelperAllocatorVma redRteCreateHelperAllocatorVma
#define _815f30e5_rteContext(value) value
#define _815f30e5_outHelperAllocatorVma(value) value
#define _815f30e5_outStatuses(value) value
#define _815f30e5_optionalFile(value) value
#define _815f30e5_optionalLine(value) value
#define _815f30e5_optionalUserData(value) value
#define _815f30e5_rteParameters(value) value
#else
typedef struct _s_815f30e5_rteContext { RedRteHandleContext value; } _s_815f30e5_rteContext;
typedef struct _s_815f30e5_outHelperAllocatorVma { RedRteHandleHelperAllocatorVma* value; } _s_815f30e5_outHelperAllocatorVma;
typedef struct _s_815f30e5_outStatuses { RedStatuses* value; } _s_815f30e5_outStatuses;
typedef struct _s_815f30e5_optionalFile { char* value; } _s_815f30e5_optionalFile;
typedef struct _s_815f30e5_optionalLine { int value; } _s_815f30e5_optionalLine;
typedef struct _s_815f30e5_optionalUserData { void* value; } _s_815f30e5_optionalUserData;
typedef struct _s_815f30e5_rteParameters { void* value; } _s_815f30e5_rteParameters;
static inline _s_815f30e5_rteContext _815f30e5_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_815f30e5_rteContext){value}; }
static inline _s_815f30e5_outHelperAllocatorVma _815f30e5_outHelperAllocatorVma(RedRteHandleHelperAllocatorVma* value) { return REDGPU_NP_STRUCT_INIT(_s_815f30e5_outHelperAllocatorVma){value}; }
static inline _s_815f30e5_outStatuses _815f30e5_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_815f30e5_outStatuses){value}; }
static inline _s_815f30e5_optionalFile _815f30e5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_815f30e5_optionalFile){value}; }
static inline _s_815f30e5_optionalLine _815f30e5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_815f30e5_optionalLine){value}; }
static inline _s_815f30e5_optionalUserData _815f30e5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_815f30e5_optionalUserData){value}; }
static inline _s_815f30e5_rteParameters _815f30e5_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_815f30e5_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateHelperAllocatorVma(_s_815f30e5_rteContext rteContext, _s_815f30e5_outHelperAllocatorVma outHelperAllocatorVma, _s_815f30e5_outStatuses outStatuses, _s_815f30e5_optionalFile optionalFile, _s_815f30e5_optionalLine optionalLine, _s_815f30e5_optionalUserData optionalUserData, _s_815f30e5_rteParameters rteParameters) {
  return redRteCreateHelperAllocatorVma(rteContext.value, outHelperAllocatorVma.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyHelperAllocatorVma redRteDestroyHelperAllocatorVma
#define _f21d1fb2_helperAllocatorVma(value) value
#define _f21d1fb2_optionalFile(value) value
#define _f21d1fb2_optionalLine(value) value
#define _f21d1fb2_optionalUserData(value) value
#define _f21d1fb2_rteParameters(value) value
#else
typedef struct _s_f21d1fb2_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_f21d1fb2_helperAllocatorVma;
typedef struct _s_f21d1fb2_optionalFile { char* value; } _s_f21d1fb2_optionalFile;
typedef struct _s_f21d1fb2_optionalLine { int value; } _s_f21d1fb2_optionalLine;
typedef struct _s_f21d1fb2_optionalUserData { void* value; } _s_f21d1fb2_optionalUserData;
typedef struct _s_f21d1fb2_rteParameters { void* value; } _s_f21d1fb2_rteParameters;
static inline _s_f21d1fb2_helperAllocatorVma _f21d1fb2_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_f21d1fb2_helperAllocatorVma){value}; }
static inline _s_f21d1fb2_optionalFile _f21d1fb2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f21d1fb2_optionalFile){value}; }
static inline _s_f21d1fb2_optionalLine _f21d1fb2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f21d1fb2_optionalLine){value}; }
static inline _s_f21d1fb2_optionalUserData _f21d1fb2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f21d1fb2_optionalUserData){value}; }
static inline _s_f21d1fb2_rteParameters _f21d1fb2_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f21d1fb2_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyHelperAllocatorVma(_s_f21d1fb2_helperAllocatorVma helperAllocatorVma, _s_f21d1fb2_optionalFile optionalFile, _s_f21d1fb2_optionalLine optionalLine, _s_f21d1fb2_optionalUserData optionalUserData, _s_f21d1fb2_rteParameters rteParameters) {
  return redRteDestroyHelperAllocatorVma(helperAllocatorVma.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaCreateArray redRteHelperAllocatorVmaCreateArray
#define _abb54f78_helperAllocatorVma(value) value
#define _abb54f78_arrayInfo(value) value
#define _abb54f78_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _abb54f78_outRteHelperArray(value) value
#define _abb54f78_outStatuses(value) value
#define _abb54f78_optionalFile(value) value
#define _abb54f78_optionalLine(value) value
#define _abb54f78_optionalUserData(value) value
#define _abb54f78_rteParameters(value) value
#else
typedef struct _s_abb54f78_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_abb54f78_helperAllocatorVma;
typedef struct _s_abb54f78_arrayInfo { RedRteHelperCreateArrayInfo* value; } _s_abb54f78_arrayInfo;
typedef struct _s_abb54f78_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_abb54f78_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_abb54f78_outRteHelperArray { RedRteHelperArray* value; } _s_abb54f78_outRteHelperArray;
typedef struct _s_abb54f78_outStatuses { RedStatuses* value; } _s_abb54f78_outStatuses;
typedef struct _s_abb54f78_optionalFile { char* value; } _s_abb54f78_optionalFile;
typedef struct _s_abb54f78_optionalLine { int value; } _s_abb54f78_optionalLine;
typedef struct _s_abb54f78_optionalUserData { void* value; } _s_abb54f78_optionalUserData;
typedef struct _s_abb54f78_rteParameters { void* value; } _s_abb54f78_rteParameters;
static inline _s_abb54f78_helperAllocatorVma _abb54f78_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_abb54f78_helperAllocatorVma){value}; }
static inline _s_abb54f78_arrayInfo _abb54f78_arrayInfo(RedRteHelperCreateArrayInfo* value) { return REDGPU_NP_STRUCT_INIT(_s_abb54f78_arrayInfo){value}; }
static inline _s_abb54f78_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _abb54f78_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_abb54f78_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_abb54f78_outRteHelperArray _abb54f78_outRteHelperArray(RedRteHelperArray* value) { return REDGPU_NP_STRUCT_INIT(_s_abb54f78_outRteHelperArray){value}; }
static inline _s_abb54f78_outStatuses _abb54f78_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_abb54f78_outStatuses){value}; }
static inline _s_abb54f78_optionalFile _abb54f78_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_abb54f78_optionalFile){value}; }
static inline _s_abb54f78_optionalLine _abb54f78_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_abb54f78_optionalLine){value}; }
static inline _s_abb54f78_optionalUserData _abb54f78_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_abb54f78_optionalUserData){value}; }
static inline _s_abb54f78_rteParameters _abb54f78_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_abb54f78_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaCreateArray(_s_abb54f78_helperAllocatorVma helperAllocatorVma, _s_abb54f78_arrayInfo arrayInfo, _s_abb54f78_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_abb54f78_outRteHelperArray outRteHelperArray, _s_abb54f78_outStatuses outStatuses, _s_abb54f78_optionalFile optionalFile, _s_abb54f78_optionalLine optionalLine, _s_abb54f78_optionalUserData optionalUserData, _s_abb54f78_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaCreateArray(helperAllocatorVma.value, arrayInfo.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaCreateImage redRteHelperAllocatorVmaCreateImage
#define _ecda5ec4_helperAllocatorVma(value) value
#define _ecda5ec4_imageInfo(value) value
#define _ecda5ec4_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _ecda5ec4_outRteHelperImage(value) value
#define _ecda5ec4_outStatuses(value) value
#define _ecda5ec4_optionalFile(value) value
#define _ecda5ec4_optionalLine(value) value
#define _ecda5ec4_optionalUserData(value) value
#define _ecda5ec4_rteParameters(value) value
#else
typedef struct _s_ecda5ec4_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_ecda5ec4_helperAllocatorVma;
typedef struct _s_ecda5ec4_imageInfo { RedRteHelperCreateImageInfo* value; } _s_ecda5ec4_imageInfo;
typedef struct _s_ecda5ec4_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_ecda5ec4_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_ecda5ec4_outRteHelperImage { RedRteHelperImage* value; } _s_ecda5ec4_outRteHelperImage;
typedef struct _s_ecda5ec4_outStatuses { RedStatuses* value; } _s_ecda5ec4_outStatuses;
typedef struct _s_ecda5ec4_optionalFile { char* value; } _s_ecda5ec4_optionalFile;
typedef struct _s_ecda5ec4_optionalLine { int value; } _s_ecda5ec4_optionalLine;
typedef struct _s_ecda5ec4_optionalUserData { void* value; } _s_ecda5ec4_optionalUserData;
typedef struct _s_ecda5ec4_rteParameters { void* value; } _s_ecda5ec4_rteParameters;
static inline _s_ecda5ec4_helperAllocatorVma _ecda5ec4_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_ecda5ec4_helperAllocatorVma){value}; }
static inline _s_ecda5ec4_imageInfo _ecda5ec4_imageInfo(RedRteHelperCreateImageInfo* value) { return REDGPU_NP_STRUCT_INIT(_s_ecda5ec4_imageInfo){value}; }
static inline _s_ecda5ec4_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _ecda5ec4_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ecda5ec4_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_ecda5ec4_outRteHelperImage _ecda5ec4_outRteHelperImage(RedRteHelperImage* value) { return REDGPU_NP_STRUCT_INIT(_s_ecda5ec4_outRteHelperImage){value}; }
static inline _s_ecda5ec4_outStatuses _ecda5ec4_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_ecda5ec4_outStatuses){value}; }
static inline _s_ecda5ec4_optionalFile _ecda5ec4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ecda5ec4_optionalFile){value}; }
static inline _s_ecda5ec4_optionalLine _ecda5ec4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ecda5ec4_optionalLine){value}; }
static inline _s_ecda5ec4_optionalUserData _ecda5ec4_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ecda5ec4_optionalUserData){value}; }
static inline _s_ecda5ec4_rteParameters _ecda5ec4_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ecda5ec4_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaCreateImage(_s_ecda5ec4_helperAllocatorVma helperAllocatorVma, _s_ecda5ec4_imageInfo imageInfo, _s_ecda5ec4_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_ecda5ec4_outRteHelperImage outRteHelperImage, _s_ecda5ec4_outStatuses outStatuses, _s_ecda5ec4_optionalFile optionalFile, _s_ecda5ec4_optionalLine optionalLine, _s_ecda5ec4_optionalUserData optionalUserData, _s_ecda5ec4_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaCreateImage(helperAllocatorVma.value, imageInfo.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperImage.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaCreateArraySimple redRteHelperAllocatorVmaCreateArraySimple
#define _4e44cab7_helperAllocatorVma(value) value
#define _4e44cab7_arrayBytesCount(value) value
#define _4e44cab7_arrayUsageFlags(value) value
#define _4e44cab7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _4e44cab7_outRteHelperArray(value) value
#define _4e44cab7_outStatuses(value) value
#define _4e44cab7_optionalFile(value) value
#define _4e44cab7_optionalLine(value) value
#define _4e44cab7_optionalUserData(value) value
#define _4e44cab7_rteParameters(value) value
#else
typedef struct _s_4e44cab7_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_4e44cab7_helperAllocatorVma;
typedef struct _s_4e44cab7_arrayBytesCount { uint64_t value; } _s_4e44cab7_arrayBytesCount;
typedef struct _s_4e44cab7_arrayUsageFlags { unsigned value; } _s_4e44cab7_arrayUsageFlags;
typedef struct _s_4e44cab7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_4e44cab7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_4e44cab7_outRteHelperArray { RedRteHelperArray* value; } _s_4e44cab7_outRteHelperArray;
typedef struct _s_4e44cab7_outStatuses { RedStatuses* value; } _s_4e44cab7_outStatuses;
typedef struct _s_4e44cab7_optionalFile { char* value; } _s_4e44cab7_optionalFile;
typedef struct _s_4e44cab7_optionalLine { int value; } _s_4e44cab7_optionalLine;
typedef struct _s_4e44cab7_optionalUserData { void* value; } _s_4e44cab7_optionalUserData;
typedef struct _s_4e44cab7_rteParameters { void* value; } _s_4e44cab7_rteParameters;
static inline _s_4e44cab7_helperAllocatorVma _4e44cab7_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_4e44cab7_helperAllocatorVma){value}; }
static inline _s_4e44cab7_arrayBytesCount _4e44cab7_arrayBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_4e44cab7_arrayBytesCount){value}; }
static inline _s_4e44cab7_arrayUsageFlags _4e44cab7_arrayUsageFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4e44cab7_arrayUsageFlags){value}; }
static inline _s_4e44cab7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _4e44cab7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4e44cab7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_4e44cab7_outRteHelperArray _4e44cab7_outRteHelperArray(RedRteHelperArray* value) { return REDGPU_NP_STRUCT_INIT(_s_4e44cab7_outRteHelperArray){value}; }
static inline _s_4e44cab7_outStatuses _4e44cab7_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_4e44cab7_outStatuses){value}; }
static inline _s_4e44cab7_optionalFile _4e44cab7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4e44cab7_optionalFile){value}; }
static inline _s_4e44cab7_optionalLine _4e44cab7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4e44cab7_optionalLine){value}; }
static inline _s_4e44cab7_optionalUserData _4e44cab7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4e44cab7_optionalUserData){value}; }
static inline _s_4e44cab7_rteParameters _4e44cab7_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4e44cab7_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaCreateArraySimple(_s_4e44cab7_helperAllocatorVma helperAllocatorVma, _s_4e44cab7_arrayBytesCount arrayBytesCount, _s_4e44cab7_arrayUsageFlags arrayUsageFlags, _s_4e44cab7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_4e44cab7_outRteHelperArray outRteHelperArray, _s_4e44cab7_outStatuses outStatuses, _s_4e44cab7_optionalFile optionalFile, _s_4e44cab7_optionalLine optionalLine, _s_4e44cab7_optionalUserData optionalUserData, _s_4e44cab7_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaCreateArraySimple(helperAllocatorVma.value, arrayBytesCount.value, arrayUsageFlags.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaCreateArraySimpleWithData redRteHelperAllocatorVmaCreateArraySimpleWithData
#define _792da977_helperAllocatorVma(value) value
#define _792da977_callsSetToUploadArrayData(value) value
#define _792da977_arrayDataBytesCount(value) value
#define _792da977_arrayData(value) value
#define _792da977_arrayUsageFlags(value) value
#define _792da977_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _792da977_outRteHelperArray(value) value
#define _792da977_outStatuses(value) value
#define _792da977_optionalFile(value) value
#define _792da977_optionalLine(value) value
#define _792da977_optionalUserData(value) value
#define _792da977_rteParameters(value) value
#else
typedef struct _s_792da977_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_792da977_helperAllocatorVma;
typedef struct _s_792da977_callsSetToUploadArrayData { RedHandleCalls value; } _s_792da977_callsSetToUploadArrayData;
typedef struct _s_792da977_arrayDataBytesCount { uint64_t value; } _s_792da977_arrayDataBytesCount;
typedef struct _s_792da977_arrayData { void* value; } _s_792da977_arrayData;
typedef struct _s_792da977_arrayUsageFlags { unsigned value; } _s_792da977_arrayUsageFlags;
typedef struct _s_792da977_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_792da977_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_792da977_outRteHelperArray { RedRteHelperArray* value; } _s_792da977_outRteHelperArray;
typedef struct _s_792da977_outStatuses { RedStatuses* value; } _s_792da977_outStatuses;
typedef struct _s_792da977_optionalFile { char* value; } _s_792da977_optionalFile;
typedef struct _s_792da977_optionalLine { int value; } _s_792da977_optionalLine;
typedef struct _s_792da977_optionalUserData { void* value; } _s_792da977_optionalUserData;
typedef struct _s_792da977_rteParameters { void* value; } _s_792da977_rteParameters;
static inline _s_792da977_helperAllocatorVma _792da977_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_792da977_helperAllocatorVma){value}; }
static inline _s_792da977_callsSetToUploadArrayData _792da977_callsSetToUploadArrayData(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_792da977_callsSetToUploadArrayData){value}; }
static inline _s_792da977_arrayDataBytesCount _792da977_arrayDataBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_792da977_arrayDataBytesCount){value}; }
static inline _s_792da977_arrayData _792da977_arrayData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_792da977_arrayData){value}; }
static inline _s_792da977_arrayUsageFlags _792da977_arrayUsageFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_792da977_arrayUsageFlags){value}; }
static inline _s_792da977_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _792da977_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_792da977_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_792da977_outRteHelperArray _792da977_outRteHelperArray(RedRteHelperArray* value) { return REDGPU_NP_STRUCT_INIT(_s_792da977_outRteHelperArray){value}; }
static inline _s_792da977_outStatuses _792da977_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_792da977_outStatuses){value}; }
static inline _s_792da977_optionalFile _792da977_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_792da977_optionalFile){value}; }
static inline _s_792da977_optionalLine _792da977_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_792da977_optionalLine){value}; }
static inline _s_792da977_optionalUserData _792da977_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_792da977_optionalUserData){value}; }
static inline _s_792da977_rteParameters _792da977_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_792da977_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaCreateArraySimpleWithData(_s_792da977_helperAllocatorVma helperAllocatorVma, _s_792da977_callsSetToUploadArrayData callsSetToUploadArrayData, _s_792da977_arrayDataBytesCount arrayDataBytesCount, _s_792da977_arrayData arrayData, _s_792da977_arrayUsageFlags arrayUsageFlags, _s_792da977_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_792da977_outRteHelperArray outRteHelperArray, _s_792da977_outStatuses outStatuses, _s_792da977_optionalFile optionalFile, _s_792da977_optionalLine optionalLine, _s_792da977_optionalUserData optionalUserData, _s_792da977_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaCreateArraySimpleWithData(helperAllocatorVma.value, callsSetToUploadArrayData.value, arrayDataBytesCount.value, arrayData.value, arrayUsageFlags.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaCreateImageSimpleWithData redRteHelperAllocatorVmaCreateImageSimpleWithData
#define _9cc4038d_helperAllocatorVma(value) value
#define _9cc4038d_callsSetToUploadImageData(value) value
#define _9cc4038d_imageDataBytesCount(value) value
#define _9cc4038d_imageData(value) value
#define _9cc4038d_imageInfo(value) value
#define _9cc4038d_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral(value) value
#define _9cc4038d_outRteHelperImage(value) value
#define _9cc4038d_outStatuses(value) value
#define _9cc4038d_optionalFile(value) value
#define _9cc4038d_optionalLine(value) value
#define _9cc4038d_optionalUserData(value) value
#define _9cc4038d_rteParameters(value) value
#else
typedef struct _s_9cc4038d_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_9cc4038d_helperAllocatorVma;
typedef struct _s_9cc4038d_callsSetToUploadImageData { RedHandleCalls value; } _s_9cc4038d_callsSetToUploadImageData;
typedef struct _s_9cc4038d_imageDataBytesCount { uint64_t value; } _s_9cc4038d_imageDataBytesCount;
typedef struct _s_9cc4038d_imageData { void* value; } _s_9cc4038d_imageData;
typedef struct _s_9cc4038d_imageInfo { RedRteHelperCreateImageInfo* value; } _s_9cc4038d_imageInfo;
typedef struct _s_9cc4038d_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral { unsigned value; } _s_9cc4038d_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral;
typedef struct _s_9cc4038d_outRteHelperImage { RedRteHelperImage* value; } _s_9cc4038d_outRteHelperImage;
typedef struct _s_9cc4038d_outStatuses { RedStatuses* value; } _s_9cc4038d_outStatuses;
typedef struct _s_9cc4038d_optionalFile { char* value; } _s_9cc4038d_optionalFile;
typedef struct _s_9cc4038d_optionalLine { int value; } _s_9cc4038d_optionalLine;
typedef struct _s_9cc4038d_optionalUserData { void* value; } _s_9cc4038d_optionalUserData;
typedef struct _s_9cc4038d_rteParameters { void* value; } _s_9cc4038d_rteParameters;
static inline _s_9cc4038d_helperAllocatorVma _9cc4038d_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_9cc4038d_helperAllocatorVma){value}; }
static inline _s_9cc4038d_callsSetToUploadImageData _9cc4038d_callsSetToUploadImageData(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_9cc4038d_callsSetToUploadImageData){value}; }
static inline _s_9cc4038d_imageDataBytesCount _9cc4038d_imageDataBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_9cc4038d_imageDataBytesCount){value}; }
static inline _s_9cc4038d_imageData _9cc4038d_imageData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9cc4038d_imageData){value}; }
static inline _s_9cc4038d_imageInfo _9cc4038d_imageInfo(RedRteHelperCreateImageInfo* value) { return REDGPU_NP_STRUCT_INIT(_s_9cc4038d_imageInfo){value}; }
static inline _s_9cc4038d_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral _9cc4038d_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9cc4038d_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral){value}; }
static inline _s_9cc4038d_outRteHelperImage _9cc4038d_outRteHelperImage(RedRteHelperImage* value) { return REDGPU_NP_STRUCT_INIT(_s_9cc4038d_outRteHelperImage){value}; }
static inline _s_9cc4038d_outStatuses _9cc4038d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_9cc4038d_outStatuses){value}; }
static inline _s_9cc4038d_optionalFile _9cc4038d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9cc4038d_optionalFile){value}; }
static inline _s_9cc4038d_optionalLine _9cc4038d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9cc4038d_optionalLine){value}; }
static inline _s_9cc4038d_optionalUserData _9cc4038d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9cc4038d_optionalUserData){value}; }
static inline _s_9cc4038d_rteParameters _9cc4038d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9cc4038d_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaCreateImageSimpleWithData(_s_9cc4038d_helperAllocatorVma helperAllocatorVma, _s_9cc4038d_callsSetToUploadImageData callsSetToUploadImageData, _s_9cc4038d_imageDataBytesCount imageDataBytesCount, _s_9cc4038d_imageData imageData, _s_9cc4038d_imageInfo imageInfo, _s_9cc4038d_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral imageLayoutSuggestedDefaultValueIsImageLayoutGeneral, _s_9cc4038d_outRteHelperImage outRteHelperImage, _s_9cc4038d_outStatuses outStatuses, _s_9cc4038d_optionalFile optionalFile, _s_9cc4038d_optionalLine optionalLine, _s_9cc4038d_optionalUserData optionalUserData, _s_9cc4038d_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaCreateImageSimpleWithData(helperAllocatorVma.value, callsSetToUploadImageData.value, imageDataBytesCount.value, imageData.value, imageInfo.value, imageLayoutSuggestedDefaultValueIsImageLayoutGeneral.value, outRteHelperImage.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaDestroyArray redRteHelperAllocatorVmaDestroyArray
#define _f9dd53a5_helperAllocatorVma(value) value
#define _f9dd53a5_rteHelperArray(value) value
#define _f9dd53a5_rteHelperAllocatorResourceMemory(value) value
#define _f9dd53a5_outStatuses(value) value
#define _f9dd53a5_optionalFile(value) value
#define _f9dd53a5_optionalLine(value) value
#define _f9dd53a5_optionalUserData(value) value
#define _f9dd53a5_rteParameters(value) value
#else
typedef struct _s_f9dd53a5_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_f9dd53a5_helperAllocatorVma;
typedef struct _s_f9dd53a5_rteHelperArray { RedHandleArray value; } _s_f9dd53a5_rteHelperArray;
typedef struct _s_f9dd53a5_rteHelperAllocatorResourceMemory { void* value; } _s_f9dd53a5_rteHelperAllocatorResourceMemory;
typedef struct _s_f9dd53a5_outStatuses { RedStatuses* value; } _s_f9dd53a5_outStatuses;
typedef struct _s_f9dd53a5_optionalFile { char* value; } _s_f9dd53a5_optionalFile;
typedef struct _s_f9dd53a5_optionalLine { int value; } _s_f9dd53a5_optionalLine;
typedef struct _s_f9dd53a5_optionalUserData { void* value; } _s_f9dd53a5_optionalUserData;
typedef struct _s_f9dd53a5_rteParameters { void* value; } _s_f9dd53a5_rteParameters;
static inline _s_f9dd53a5_helperAllocatorVma _f9dd53a5_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_f9dd53a5_helperAllocatorVma){value}; }
static inline _s_f9dd53a5_rteHelperArray _f9dd53a5_rteHelperArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_f9dd53a5_rteHelperArray){value}; }
static inline _s_f9dd53a5_rteHelperAllocatorResourceMemory _f9dd53a5_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f9dd53a5_rteHelperAllocatorResourceMemory){value}; }
static inline _s_f9dd53a5_outStatuses _f9dd53a5_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_f9dd53a5_outStatuses){value}; }
static inline _s_f9dd53a5_optionalFile _f9dd53a5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f9dd53a5_optionalFile){value}; }
static inline _s_f9dd53a5_optionalLine _f9dd53a5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f9dd53a5_optionalLine){value}; }
static inline _s_f9dd53a5_optionalUserData _f9dd53a5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f9dd53a5_optionalUserData){value}; }
static inline _s_f9dd53a5_rteParameters _f9dd53a5_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f9dd53a5_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaDestroyArray(_s_f9dd53a5_helperAllocatorVma helperAllocatorVma, _s_f9dd53a5_rteHelperArray rteHelperArray, _s_f9dd53a5_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_f9dd53a5_outStatuses outStatuses, _s_f9dd53a5_optionalFile optionalFile, _s_f9dd53a5_optionalLine optionalLine, _s_f9dd53a5_optionalUserData optionalUserData, _s_f9dd53a5_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaDestroyArray(helperAllocatorVma.value, rteHelperArray.value, rteHelperAllocatorResourceMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaDestroyImage redRteHelperAllocatorVmaDestroyImage
#define _161f49b1_helperAllocatorVma(value) value
#define _161f49b1_rteHelperImage(value) value
#define _161f49b1_rteHelperAllocatorResourceMemory(value) value
#define _161f49b1_outStatuses(value) value
#define _161f49b1_optionalFile(value) value
#define _161f49b1_optionalLine(value) value
#define _161f49b1_optionalUserData(value) value
#define _161f49b1_rteParameters(value) value
#else
typedef struct _s_161f49b1_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_161f49b1_helperAllocatorVma;
typedef struct _s_161f49b1_rteHelperImage { RedHandleImage value; } _s_161f49b1_rteHelperImage;
typedef struct _s_161f49b1_rteHelperAllocatorResourceMemory { void* value; } _s_161f49b1_rteHelperAllocatorResourceMemory;
typedef struct _s_161f49b1_outStatuses { RedStatuses* value; } _s_161f49b1_outStatuses;
typedef struct _s_161f49b1_optionalFile { char* value; } _s_161f49b1_optionalFile;
typedef struct _s_161f49b1_optionalLine { int value; } _s_161f49b1_optionalLine;
typedef struct _s_161f49b1_optionalUserData { void* value; } _s_161f49b1_optionalUserData;
typedef struct _s_161f49b1_rteParameters { void* value; } _s_161f49b1_rteParameters;
static inline _s_161f49b1_helperAllocatorVma _161f49b1_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_161f49b1_helperAllocatorVma){value}; }
static inline _s_161f49b1_rteHelperImage _161f49b1_rteHelperImage(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_161f49b1_rteHelperImage){value}; }
static inline _s_161f49b1_rteHelperAllocatorResourceMemory _161f49b1_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_161f49b1_rteHelperAllocatorResourceMemory){value}; }
static inline _s_161f49b1_outStatuses _161f49b1_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_161f49b1_outStatuses){value}; }
static inline _s_161f49b1_optionalFile _161f49b1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_161f49b1_optionalFile){value}; }
static inline _s_161f49b1_optionalLine _161f49b1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_161f49b1_optionalLine){value}; }
static inline _s_161f49b1_optionalUserData _161f49b1_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_161f49b1_optionalUserData){value}; }
static inline _s_161f49b1_rteParameters _161f49b1_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_161f49b1_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaDestroyImage(_s_161f49b1_helperAllocatorVma helperAllocatorVma, _s_161f49b1_rteHelperImage rteHelperImage, _s_161f49b1_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_161f49b1_outStatuses outStatuses, _s_161f49b1_optionalFile optionalFile, _s_161f49b1_optionalLine optionalLine, _s_161f49b1_optionalUserData optionalUserData, _s_161f49b1_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaDestroyImage(helperAllocatorVma.value, rteHelperImage.value, rteHelperAllocatorResourceMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaFinalizeAndReleaseStagingMemory redRteHelperAllocatorVmaFinalizeAndReleaseStagingMemory
#define _bdb4ca16_helperAllocatorVma(value) value
#define _bdb4ca16_optionalCpuSignal(value) value
#define _bdb4ca16_outStatuses(value) value
#define _bdb4ca16_optionalFile(value) value
#define _bdb4ca16_optionalLine(value) value
#define _bdb4ca16_optionalUserData(value) value
#define _bdb4ca16_rteParameters(value) value
#else
typedef struct _s_bdb4ca16_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_bdb4ca16_helperAllocatorVma;
typedef struct _s_bdb4ca16_optionalCpuSignal { RedHandleCpuSignal value; } _s_bdb4ca16_optionalCpuSignal;
typedef struct _s_bdb4ca16_outStatuses { RedStatuses* value; } _s_bdb4ca16_outStatuses;
typedef struct _s_bdb4ca16_optionalFile { char* value; } _s_bdb4ca16_optionalFile;
typedef struct _s_bdb4ca16_optionalLine { int value; } _s_bdb4ca16_optionalLine;
typedef struct _s_bdb4ca16_optionalUserData { void* value; } _s_bdb4ca16_optionalUserData;
typedef struct _s_bdb4ca16_rteParameters { void* value; } _s_bdb4ca16_rteParameters;
static inline _s_bdb4ca16_helperAllocatorVma _bdb4ca16_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_bdb4ca16_helperAllocatorVma){value}; }
static inline _s_bdb4ca16_optionalCpuSignal _bdb4ca16_optionalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_bdb4ca16_optionalCpuSignal){value}; }
static inline _s_bdb4ca16_outStatuses _bdb4ca16_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_bdb4ca16_outStatuses){value}; }
static inline _s_bdb4ca16_optionalFile _bdb4ca16_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bdb4ca16_optionalFile){value}; }
static inline _s_bdb4ca16_optionalLine _bdb4ca16_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bdb4ca16_optionalLine){value}; }
static inline _s_bdb4ca16_optionalUserData _bdb4ca16_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bdb4ca16_optionalUserData){value}; }
static inline _s_bdb4ca16_rteParameters _bdb4ca16_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bdb4ca16_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaFinalizeAndReleaseStagingMemory(_s_bdb4ca16_helperAllocatorVma helperAllocatorVma, _s_bdb4ca16_optionalCpuSignal optionalCpuSignal, _s_bdb4ca16_outStatuses outStatuses, _s_bdb4ca16_optionalFile optionalFile, _s_bdb4ca16_optionalLine optionalLine, _s_bdb4ca16_optionalUserData optionalUserData, _s_bdb4ca16_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaFinalizeAndReleaseStagingMemory(helperAllocatorVma.value, optionalCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaFinalizeStagingMemory redRteHelperAllocatorVmaFinalizeStagingMemory
#define _ec0def1d_helperAllocatorVma(value) value
#define _ec0def1d_optionalCpuSignal(value) value
#define _ec0def1d_outStatuses(value) value
#define _ec0def1d_optionalFile(value) value
#define _ec0def1d_optionalLine(value) value
#define _ec0def1d_optionalUserData(value) value
#define _ec0def1d_rteParameters(value) value
#else
typedef struct _s_ec0def1d_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_ec0def1d_helperAllocatorVma;
typedef struct _s_ec0def1d_optionalCpuSignal { RedHandleCpuSignal value; } _s_ec0def1d_optionalCpuSignal;
typedef struct _s_ec0def1d_outStatuses { RedStatuses* value; } _s_ec0def1d_outStatuses;
typedef struct _s_ec0def1d_optionalFile { char* value; } _s_ec0def1d_optionalFile;
typedef struct _s_ec0def1d_optionalLine { int value; } _s_ec0def1d_optionalLine;
typedef struct _s_ec0def1d_optionalUserData { void* value; } _s_ec0def1d_optionalUserData;
typedef struct _s_ec0def1d_rteParameters { void* value; } _s_ec0def1d_rteParameters;
static inline _s_ec0def1d_helperAllocatorVma _ec0def1d_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_ec0def1d_helperAllocatorVma){value}; }
static inline _s_ec0def1d_optionalCpuSignal _ec0def1d_optionalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_ec0def1d_optionalCpuSignal){value}; }
static inline _s_ec0def1d_outStatuses _ec0def1d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_ec0def1d_outStatuses){value}; }
static inline _s_ec0def1d_optionalFile _ec0def1d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ec0def1d_optionalFile){value}; }
static inline _s_ec0def1d_optionalLine _ec0def1d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ec0def1d_optionalLine){value}; }
static inline _s_ec0def1d_optionalUserData _ec0def1d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ec0def1d_optionalUserData){value}; }
static inline _s_ec0def1d_rteParameters _ec0def1d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ec0def1d_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaFinalizeStagingMemory(_s_ec0def1d_helperAllocatorVma helperAllocatorVma, _s_ec0def1d_optionalCpuSignal optionalCpuSignal, _s_ec0def1d_outStatuses outStatuses, _s_ec0def1d_optionalFile optionalFile, _s_ec0def1d_optionalLine optionalLine, _s_ec0def1d_optionalUserData optionalUserData, _s_ec0def1d_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaFinalizeStagingMemory(helperAllocatorVma.value, optionalCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaReleaseStagingMemory redRteHelperAllocatorVmaReleaseStagingMemory
#define _f69c2293_helperAllocatorVma(value) value
#define _f69c2293_outStatuses(value) value
#define _f69c2293_optionalFile(value) value
#define _f69c2293_optionalLine(value) value
#define _f69c2293_optionalUserData(value) value
#define _f69c2293_rteParameters(value) value
#else
typedef struct _s_f69c2293_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_f69c2293_helperAllocatorVma;
typedef struct _s_f69c2293_outStatuses { RedStatuses* value; } _s_f69c2293_outStatuses;
typedef struct _s_f69c2293_optionalFile { char* value; } _s_f69c2293_optionalFile;
typedef struct _s_f69c2293_optionalLine { int value; } _s_f69c2293_optionalLine;
typedef struct _s_f69c2293_optionalUserData { void* value; } _s_f69c2293_optionalUserData;
typedef struct _s_f69c2293_rteParameters { void* value; } _s_f69c2293_rteParameters;
static inline _s_f69c2293_helperAllocatorVma _f69c2293_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_f69c2293_helperAllocatorVma){value}; }
static inline _s_f69c2293_outStatuses _f69c2293_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_f69c2293_outStatuses){value}; }
static inline _s_f69c2293_optionalFile _f69c2293_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f69c2293_optionalFile){value}; }
static inline _s_f69c2293_optionalLine _f69c2293_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f69c2293_optionalLine){value}; }
static inline _s_f69c2293_optionalUserData _f69c2293_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f69c2293_optionalUserData){value}; }
static inline _s_f69c2293_rteParameters _f69c2293_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f69c2293_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaReleaseStagingMemory(_s_f69c2293_helperAllocatorVma helperAllocatorVma, _s_f69c2293_outStatuses outStatuses, _s_f69c2293_optionalFile optionalFile, _s_f69c2293_optionalLine optionalLine, _s_f69c2293_optionalUserData optionalUserData, _s_f69c2293_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaReleaseStagingMemory(helperAllocatorVma.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaMapArray redRteHelperAllocatorVmaMapArray
#define _7147347a_helperAllocatorVma(value) value
#define _7147347a_rteHelperArray(value) value
#define _7147347a_rteHelperAllocatorResourceMemory(value) value
#define _7147347a_outVolatilePointer(value) value
#define _7147347a_outStatuses(value) value
#define _7147347a_optionalFile(value) value
#define _7147347a_optionalLine(value) value
#define _7147347a_optionalUserData(value) value
#define _7147347a_rteParameters(value) value
#else
typedef struct _s_7147347a_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_7147347a_helperAllocatorVma;
typedef struct _s_7147347a_rteHelperArray { RedHandleArray value; } _s_7147347a_rteHelperArray;
typedef struct _s_7147347a_rteHelperAllocatorResourceMemory { void* value; } _s_7147347a_rteHelperAllocatorResourceMemory;
typedef struct _s_7147347a_outVolatilePointer { void** value; } _s_7147347a_outVolatilePointer;
typedef struct _s_7147347a_outStatuses { RedStatuses* value; } _s_7147347a_outStatuses;
typedef struct _s_7147347a_optionalFile { char* value; } _s_7147347a_optionalFile;
typedef struct _s_7147347a_optionalLine { int value; } _s_7147347a_optionalLine;
typedef struct _s_7147347a_optionalUserData { void* value; } _s_7147347a_optionalUserData;
typedef struct _s_7147347a_rteParameters { void* value; } _s_7147347a_rteParameters;
static inline _s_7147347a_helperAllocatorVma _7147347a_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_7147347a_helperAllocatorVma){value}; }
static inline _s_7147347a_rteHelperArray _7147347a_rteHelperArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_7147347a_rteHelperArray){value}; }
static inline _s_7147347a_rteHelperAllocatorResourceMemory _7147347a_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7147347a_rteHelperAllocatorResourceMemory){value}; }
static inline _s_7147347a_outVolatilePointer _7147347a_outVolatilePointer(void** value) { return REDGPU_NP_STRUCT_INIT(_s_7147347a_outVolatilePointer){value}; }
static inline _s_7147347a_outStatuses _7147347a_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_7147347a_outStatuses){value}; }
static inline _s_7147347a_optionalFile _7147347a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7147347a_optionalFile){value}; }
static inline _s_7147347a_optionalLine _7147347a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7147347a_optionalLine){value}; }
static inline _s_7147347a_optionalUserData _7147347a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7147347a_optionalUserData){value}; }
static inline _s_7147347a_rteParameters _7147347a_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7147347a_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaMapArray(_s_7147347a_helperAllocatorVma helperAllocatorVma, _s_7147347a_rteHelperArray rteHelperArray, _s_7147347a_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_7147347a_outVolatilePointer outVolatilePointer, _s_7147347a_outStatuses outStatuses, _s_7147347a_optionalFile optionalFile, _s_7147347a_optionalLine optionalLine, _s_7147347a_optionalUserData optionalUserData, _s_7147347a_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaMapArray(helperAllocatorVma.value, rteHelperArray.value, rteHelperAllocatorResourceMemory.value, outVolatilePointer.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaUnmapArray redRteHelperAllocatorVmaUnmapArray
#define _264ceaf5_helperAllocatorVma(value) value
#define _264ceaf5_rteHelperArray(value) value
#define _264ceaf5_rteHelperAllocatorResourceMemory(value) value
#define _264ceaf5_outStatuses(value) value
#define _264ceaf5_optionalFile(value) value
#define _264ceaf5_optionalLine(value) value
#define _264ceaf5_optionalUserData(value) value
#define _264ceaf5_rteParameters(value) value
#else
typedef struct _s_264ceaf5_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_264ceaf5_helperAllocatorVma;
typedef struct _s_264ceaf5_rteHelperArray { RedHandleArray value; } _s_264ceaf5_rteHelperArray;
typedef struct _s_264ceaf5_rteHelperAllocatorResourceMemory { void* value; } _s_264ceaf5_rteHelperAllocatorResourceMemory;
typedef struct _s_264ceaf5_outStatuses { RedStatuses* value; } _s_264ceaf5_outStatuses;
typedef struct _s_264ceaf5_optionalFile { char* value; } _s_264ceaf5_optionalFile;
typedef struct _s_264ceaf5_optionalLine { int value; } _s_264ceaf5_optionalLine;
typedef struct _s_264ceaf5_optionalUserData { void* value; } _s_264ceaf5_optionalUserData;
typedef struct _s_264ceaf5_rteParameters { void* value; } _s_264ceaf5_rteParameters;
static inline _s_264ceaf5_helperAllocatorVma _264ceaf5_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_264ceaf5_helperAllocatorVma){value}; }
static inline _s_264ceaf5_rteHelperArray _264ceaf5_rteHelperArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_264ceaf5_rteHelperArray){value}; }
static inline _s_264ceaf5_rteHelperAllocatorResourceMemory _264ceaf5_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_264ceaf5_rteHelperAllocatorResourceMemory){value}; }
static inline _s_264ceaf5_outStatuses _264ceaf5_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_264ceaf5_outStatuses){value}; }
static inline _s_264ceaf5_optionalFile _264ceaf5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_264ceaf5_optionalFile){value}; }
static inline _s_264ceaf5_optionalLine _264ceaf5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_264ceaf5_optionalLine){value}; }
static inline _s_264ceaf5_optionalUserData _264ceaf5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_264ceaf5_optionalUserData){value}; }
static inline _s_264ceaf5_rteParameters _264ceaf5_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_264ceaf5_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaUnmapArray(_s_264ceaf5_helperAllocatorVma helperAllocatorVma, _s_264ceaf5_rteHelperArray rteHelperArray, _s_264ceaf5_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_264ceaf5_outStatuses outStatuses, _s_264ceaf5_optionalFile optionalFile, _s_264ceaf5_optionalLine optionalLine, _s_264ceaf5_optionalUserData optionalUserData, _s_264ceaf5_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaUnmapArray(helperAllocatorVma.value, rteHelperArray.value, rteHelperAllocatorResourceMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateHelperStructs redRteCreateHelperStructs
#define _04d87b90_rteContext(value) value
#define _04d87b90_outHelperStructs(value) value
#define _04d87b90_outStatuses(value) value
#define _04d87b90_optionalFile(value) value
#define _04d87b90_optionalLine(value) value
#define _04d87b90_optionalUserData(value) value
#define _04d87b90_rteParameters(value) value
#else
typedef struct _s_04d87b90_rteContext { RedRteHandleContext value; } _s_04d87b90_rteContext;
typedef struct _s_04d87b90_outHelperStructs { RedRteHandleHelperStructs* value; } _s_04d87b90_outHelperStructs;
typedef struct _s_04d87b90_outStatuses { RedStatuses* value; } _s_04d87b90_outStatuses;
typedef struct _s_04d87b90_optionalFile { char* value; } _s_04d87b90_optionalFile;
typedef struct _s_04d87b90_optionalLine { int value; } _s_04d87b90_optionalLine;
typedef struct _s_04d87b90_optionalUserData { void* value; } _s_04d87b90_optionalUserData;
typedef struct _s_04d87b90_rteParameters { void* value; } _s_04d87b90_rteParameters;
static inline _s_04d87b90_rteContext _04d87b90_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_04d87b90_rteContext){value}; }
static inline _s_04d87b90_outHelperStructs _04d87b90_outHelperStructs(RedRteHandleHelperStructs* value) { return REDGPU_NP_STRUCT_INIT(_s_04d87b90_outHelperStructs){value}; }
static inline _s_04d87b90_outStatuses _04d87b90_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_04d87b90_outStatuses){value}; }
static inline _s_04d87b90_optionalFile _04d87b90_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_04d87b90_optionalFile){value}; }
static inline _s_04d87b90_optionalLine _04d87b90_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_04d87b90_optionalLine){value}; }
static inline _s_04d87b90_optionalUserData _04d87b90_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_04d87b90_optionalUserData){value}; }
static inline _s_04d87b90_rteParameters _04d87b90_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_04d87b90_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateHelperStructs(_s_04d87b90_rteContext rteContext, _s_04d87b90_outHelperStructs outHelperStructs, _s_04d87b90_outStatuses outStatuses, _s_04d87b90_optionalFile optionalFile, _s_04d87b90_optionalLine optionalLine, _s_04d87b90_optionalUserData optionalUserData, _s_04d87b90_rteParameters rteParameters) {
  return redRteCreateHelperStructs(rteContext.value, outHelperStructs.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyHelperStructs redRteDestroyHelperStructs
#define _7d9e4306_helperStructs(value) value
#define _7d9e4306_optionalFile(value) value
#define _7d9e4306_optionalLine(value) value
#define _7d9e4306_optionalUserData(value) value
#define _7d9e4306_rteParameters(value) value
#else
typedef struct _s_7d9e4306_helperStructs { RedRteHandleHelperStructs value; } _s_7d9e4306_helperStructs;
typedef struct _s_7d9e4306_optionalFile { char* value; } _s_7d9e4306_optionalFile;
typedef struct _s_7d9e4306_optionalLine { int value; } _s_7d9e4306_optionalLine;
typedef struct _s_7d9e4306_optionalUserData { void* value; } _s_7d9e4306_optionalUserData;
typedef struct _s_7d9e4306_rteParameters { void* value; } _s_7d9e4306_rteParameters;
static inline _s_7d9e4306_helperStructs _7d9e4306_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_7d9e4306_helperStructs){value}; }
static inline _s_7d9e4306_optionalFile _7d9e4306_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7d9e4306_optionalFile){value}; }
static inline _s_7d9e4306_optionalLine _7d9e4306_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7d9e4306_optionalLine){value}; }
static inline _s_7d9e4306_optionalUserData _7d9e4306_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7d9e4306_optionalUserData){value}; }
static inline _s_7d9e4306_rteParameters _7d9e4306_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7d9e4306_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyHelperStructs(_s_7d9e4306_helperStructs helperStructs, _s_7d9e4306_optionalFile optionalFile, _s_7d9e4306_optionalLine optionalLine, _s_7d9e4306_optionalUserData optionalUserData, _s_7d9e4306_rteParameters rteParameters) {
  return redRteDestroyHelperStructs(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsSetStructDeclarationMembers redRteHelperStructsSetStructDeclarationMembers
#define _f7660459_helperStructs(value) value
#define _f7660459_structDeclarationMembersCount(value) value
#define _f7660459_structDeclarationMembers(value) value
#define _f7660459_structDeclarationMembersArrayROCount(value) value
#define _f7660459_structDeclarationMembersArrayRO(value) value
#define _f7660459_optionalFile(value) value
#define _f7660459_optionalLine(value) value
#define _f7660459_optionalUserData(value) value
#define _f7660459_rteParameters(value) value
#else
typedef struct _s_f7660459_helperStructs { RedRteHandleHelperStructs value; } _s_f7660459_helperStructs;
typedef struct _s_f7660459_structDeclarationMembersCount { unsigned value; } _s_f7660459_structDeclarationMembersCount;
typedef struct _s_f7660459_structDeclarationMembers { RedStructDeclarationMember* value; } _s_f7660459_structDeclarationMembers;
typedef struct _s_f7660459_structDeclarationMembersArrayROCount { unsigned value; } _s_f7660459_structDeclarationMembersArrayROCount;
typedef struct _s_f7660459_structDeclarationMembersArrayRO { RedStructDeclarationMemberArrayRO* value; } _s_f7660459_structDeclarationMembersArrayRO;
typedef struct _s_f7660459_optionalFile { char* value; } _s_f7660459_optionalFile;
typedef struct _s_f7660459_optionalLine { int value; } _s_f7660459_optionalLine;
typedef struct _s_f7660459_optionalUserData { void* value; } _s_f7660459_optionalUserData;
typedef struct _s_f7660459_rteParameters { void* value; } _s_f7660459_rteParameters;
static inline _s_f7660459_helperStructs _f7660459_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_f7660459_helperStructs){value}; }
static inline _s_f7660459_structDeclarationMembersCount _f7660459_structDeclarationMembersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f7660459_structDeclarationMembersCount){value}; }
static inline _s_f7660459_structDeclarationMembers _f7660459_structDeclarationMembers(RedStructDeclarationMember* value) { return REDGPU_NP_STRUCT_INIT(_s_f7660459_structDeclarationMembers){value}; }
static inline _s_f7660459_structDeclarationMembersArrayROCount _f7660459_structDeclarationMembersArrayROCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f7660459_structDeclarationMembersArrayROCount){value}; }
static inline _s_f7660459_structDeclarationMembersArrayRO _f7660459_structDeclarationMembersArrayRO(RedStructDeclarationMemberArrayRO* value) { return REDGPU_NP_STRUCT_INIT(_s_f7660459_structDeclarationMembersArrayRO){value}; }
static inline _s_f7660459_optionalFile _f7660459_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f7660459_optionalFile){value}; }
static inline _s_f7660459_optionalLine _f7660459_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f7660459_optionalLine){value}; }
static inline _s_f7660459_optionalUserData _f7660459_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f7660459_optionalUserData){value}; }
static inline _s_f7660459_rteParameters _f7660459_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f7660459_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsSetStructDeclarationMembers(_s_f7660459_helperStructs helperStructs, _s_f7660459_structDeclarationMembersCount structDeclarationMembersCount, _s_f7660459_structDeclarationMembers structDeclarationMembers, _s_f7660459_structDeclarationMembersArrayROCount structDeclarationMembersArrayROCount, _s_f7660459_structDeclarationMembersArrayRO structDeclarationMembersArrayRO, _s_f7660459_optionalFile optionalFile, _s_f7660459_optionalLine optionalLine, _s_f7660459_optionalUserData optionalUserData, _s_f7660459_rteParameters rteParameters) {
  return redRteHelperStructsSetStructDeclarationMembers(helperStructs.value, structDeclarationMembersCount.value, structDeclarationMembers.value, structDeclarationMembersArrayROCount.value, structDeclarationMembersArrayRO.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsAddStructDeclarationMember redRteHelperStructsAddStructDeclarationMember
#define _5c5b90ae_helperStructs(value) value
#define _5c5b90ae_slot(value) value
#define _5c5b90ae_type(value) value
#define _5c5b90ae_count(value) value
#define _5c5b90ae_visibleToStages(value) value
#define _5c5b90ae_inlineSampler(value) value
#define _5c5b90ae_slotTypeIsArrayRO(value) value
#define _5c5b90ae_optionalFile(value) value
#define _5c5b90ae_optionalLine(value) value
#define _5c5b90ae_optionalUserData(value) value
#define _5c5b90ae_rteParameters(value) value
#else
typedef struct _s_5c5b90ae_helperStructs { RedRteHandleHelperStructs value; } _s_5c5b90ae_helperStructs;
typedef struct _s_5c5b90ae_slot { unsigned value; } _s_5c5b90ae_slot;
typedef struct _s_5c5b90ae_type { unsigned value; } _s_5c5b90ae_type;
typedef struct _s_5c5b90ae_count { unsigned value; } _s_5c5b90ae_count;
typedef struct _s_5c5b90ae_visibleToStages { unsigned value; } _s_5c5b90ae_visibleToStages;
typedef struct _s_5c5b90ae_inlineSampler { RedHandleSampler* value; } _s_5c5b90ae_inlineSampler;
typedef struct _s_5c5b90ae_slotTypeIsArrayRO { RedBool32 value; } _s_5c5b90ae_slotTypeIsArrayRO;
typedef struct _s_5c5b90ae_optionalFile { char* value; } _s_5c5b90ae_optionalFile;
typedef struct _s_5c5b90ae_optionalLine { int value; } _s_5c5b90ae_optionalLine;
typedef struct _s_5c5b90ae_optionalUserData { void* value; } _s_5c5b90ae_optionalUserData;
typedef struct _s_5c5b90ae_rteParameters { void* value; } _s_5c5b90ae_rteParameters;
static inline _s_5c5b90ae_helperStructs _5c5b90ae_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_5c5b90ae_helperStructs){value}; }
static inline _s_5c5b90ae_slot _5c5b90ae_slot(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_5c5b90ae_slot){value}; }
static inline _s_5c5b90ae_type _5c5b90ae_type(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_5c5b90ae_type){value}; }
static inline _s_5c5b90ae_count _5c5b90ae_count(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_5c5b90ae_count){value}; }
static inline _s_5c5b90ae_visibleToStages _5c5b90ae_visibleToStages(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_5c5b90ae_visibleToStages){value}; }
static inline _s_5c5b90ae_inlineSampler _5c5b90ae_inlineSampler(RedHandleSampler* value) { return REDGPU_NP_STRUCT_INIT(_s_5c5b90ae_inlineSampler){value}; }
static inline _s_5c5b90ae_slotTypeIsArrayRO _5c5b90ae_slotTypeIsArrayRO(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_5c5b90ae_slotTypeIsArrayRO){value}; }
static inline _s_5c5b90ae_optionalFile _5c5b90ae_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5c5b90ae_optionalFile){value}; }
static inline _s_5c5b90ae_optionalLine _5c5b90ae_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5c5b90ae_optionalLine){value}; }
static inline _s_5c5b90ae_optionalUserData _5c5b90ae_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5c5b90ae_optionalUserData){value}; }
static inline _s_5c5b90ae_rteParameters _5c5b90ae_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5c5b90ae_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsAddStructDeclarationMember(_s_5c5b90ae_helperStructs helperStructs, _s_5c5b90ae_slot slot, _s_5c5b90ae_type type, _s_5c5b90ae_count count, _s_5c5b90ae_visibleToStages visibleToStages, _s_5c5b90ae_inlineSampler inlineSampler, _s_5c5b90ae_slotTypeIsArrayRO slotTypeIsArrayRO, _s_5c5b90ae_optionalFile optionalFile, _s_5c5b90ae_optionalLine optionalLine, _s_5c5b90ae_optionalUserData optionalUserData, _s_5c5b90ae_rteParameters rteParameters) {
  return redRteHelperStructsAddStructDeclarationMember(helperStructs.value, slot.value, type.value, count.value, visibleToStages.value, inlineSampler.value, slotTypeIsArrayRO.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsSetStructDeclarationMemberFlags redRteHelperStructsSetStructDeclarationMemberFlags
#define _8bcc2f8e_helperStructs(value) value
#define _8bcc2f8e_slot(value) value
#define _8bcc2f8e_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10(value) value
#define _8bcc2f8e_optionalFile(value) value
#define _8bcc2f8e_optionalLine(value) value
#define _8bcc2f8e_optionalUserData(value) value
#define _8bcc2f8e_rteParameters(value) value
#else
typedef struct _s_8bcc2f8e_helperStructs { RedRteHandleHelperStructs value; } _s_8bcc2f8e_helperStructs;
typedef struct _s_8bcc2f8e_slot { unsigned value; } _s_8bcc2f8e_slot;
typedef struct _s_8bcc2f8e_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10 { unsigned value; } _s_8bcc2f8e_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10;
typedef struct _s_8bcc2f8e_optionalFile { char* value; } _s_8bcc2f8e_optionalFile;
typedef struct _s_8bcc2f8e_optionalLine { int value; } _s_8bcc2f8e_optionalLine;
typedef struct _s_8bcc2f8e_optionalUserData { void* value; } _s_8bcc2f8e_optionalUserData;
typedef struct _s_8bcc2f8e_rteParameters { void* value; } _s_8bcc2f8e_rteParameters;
static inline _s_8bcc2f8e_helperStructs _8bcc2f8e_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_8bcc2f8e_helperStructs){value}; }
static inline _s_8bcc2f8e_slot _8bcc2f8e_slot(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8bcc2f8e_slot){value}; }
static inline _s_8bcc2f8e_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10 _8bcc2f8e_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8bcc2f8e_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10){value}; }
static inline _s_8bcc2f8e_optionalFile _8bcc2f8e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8bcc2f8e_optionalFile){value}; }
static inline _s_8bcc2f8e_optionalLine _8bcc2f8e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8bcc2f8e_optionalLine){value}; }
static inline _s_8bcc2f8e_optionalUserData _8bcc2f8e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8bcc2f8e_optionalUserData){value}; }
static inline _s_8bcc2f8e_rteParameters _8bcc2f8e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8bcc2f8e_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsSetStructDeclarationMemberFlags(_s_8bcc2f8e_helperStructs helperStructs, _s_8bcc2f8e_slot slot, _s_8bcc2f8e_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10 descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10, _s_8bcc2f8e_optionalFile optionalFile, _s_8bcc2f8e_optionalLine optionalLine, _s_8bcc2f8e_optionalUserData optionalUserData, _s_8bcc2f8e_rteParameters rteParameters) {
  return redRteHelperStructsSetStructDeclarationMemberFlags(helperStructs.value, slot.value, descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsCreateStructDeclaration redRteHelperStructsCreateStructDeclaration
#define _f55c2f96_helperStructs(value) value
#define _f55c2f96_descriptorSetLayoutCreateFlags(value) value
#define _f55c2f96_apiSupport(value) value
#define _f55c2f96_outStructDeclaration(value) value
#define _f55c2f96_outStatuses(value) value
#define _f55c2f96_optionalFile(value) value
#define _f55c2f96_optionalLine(value) value
#define _f55c2f96_optionalUserData(value) value
#define _f55c2f96_rteParameters(value) value
#else
typedef struct _s_f55c2f96_helperStructs { RedRteHandleHelperStructs value; } _s_f55c2f96_helperStructs;
typedef struct _s_f55c2f96_descriptorSetLayoutCreateFlags { unsigned value; } _s_f55c2f96_descriptorSetLayoutCreateFlags;
typedef struct _s_f55c2f96_apiSupport { RedRteHelperStructsApiSupport value; } _s_f55c2f96_apiSupport;
typedef struct _s_f55c2f96_outStructDeclaration { RedHandleStructDeclaration* value; } _s_f55c2f96_outStructDeclaration;
typedef struct _s_f55c2f96_outStatuses { RedStatuses* value; } _s_f55c2f96_outStatuses;
typedef struct _s_f55c2f96_optionalFile { char* value; } _s_f55c2f96_optionalFile;
typedef struct _s_f55c2f96_optionalLine { int value; } _s_f55c2f96_optionalLine;
typedef struct _s_f55c2f96_optionalUserData { void* value; } _s_f55c2f96_optionalUserData;
typedef struct _s_f55c2f96_rteParameters { void* value; } _s_f55c2f96_rteParameters;
static inline _s_f55c2f96_helperStructs _f55c2f96_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_f55c2f96_helperStructs){value}; }
static inline _s_f55c2f96_descriptorSetLayoutCreateFlags _f55c2f96_descriptorSetLayoutCreateFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f55c2f96_descriptorSetLayoutCreateFlags){value}; }
static inline _s_f55c2f96_apiSupport _f55c2f96_apiSupport(RedRteHelperStructsApiSupport value) { return REDGPU_NP_STRUCT_INIT(_s_f55c2f96_apiSupport){value}; }
static inline _s_f55c2f96_outStructDeclaration _f55c2f96_outStructDeclaration(RedHandleStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_f55c2f96_outStructDeclaration){value}; }
static inline _s_f55c2f96_outStatuses _f55c2f96_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_f55c2f96_outStatuses){value}; }
static inline _s_f55c2f96_optionalFile _f55c2f96_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f55c2f96_optionalFile){value}; }
static inline _s_f55c2f96_optionalLine _f55c2f96_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f55c2f96_optionalLine){value}; }
static inline _s_f55c2f96_optionalUserData _f55c2f96_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f55c2f96_optionalUserData){value}; }
static inline _s_f55c2f96_rteParameters _f55c2f96_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f55c2f96_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsCreateStructDeclaration(_s_f55c2f96_helperStructs helperStructs, _s_f55c2f96_descriptorSetLayoutCreateFlags descriptorSetLayoutCreateFlags, _s_f55c2f96_apiSupport apiSupport, _s_f55c2f96_outStructDeclaration outStructDeclaration, _s_f55c2f96_outStatuses outStatuses, _s_f55c2f96_optionalFile optionalFile, _s_f55c2f96_optionalLine optionalLine, _s_f55c2f96_optionalUserData optionalUserData, _s_f55c2f96_rteParameters rteParameters) {
  return redRteHelperStructsCreateStructDeclaration(helperStructs.value, descriptorSetLayoutCreateFlags.value, apiSupport.value, outStructDeclaration.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsCreateStructsMemory redRteHelperStructsCreateStructsMemory
#define _11d23ff7_helperStructs(value) value
#define _11d23ff7_allocateStructsCount(value) value
#define _11d23ff7_outStructsMemory(value) value
#define _11d23ff7_outStatuses(value) value
#define _11d23ff7_optionalFile(value) value
#define _11d23ff7_optionalLine(value) value
#define _11d23ff7_optionalUserData(value) value
#define _11d23ff7_rteParameters(value) value
#else
typedef struct _s_11d23ff7_helperStructs { RedRteHandleHelperStructs value; } _s_11d23ff7_helperStructs;
typedef struct _s_11d23ff7_allocateStructsCount { unsigned value; } _s_11d23ff7_allocateStructsCount;
typedef struct _s_11d23ff7_outStructsMemory { RedHandleStructsMemory* value; } _s_11d23ff7_outStructsMemory;
typedef struct _s_11d23ff7_outStatuses { RedStatuses* value; } _s_11d23ff7_outStatuses;
typedef struct _s_11d23ff7_optionalFile { char* value; } _s_11d23ff7_optionalFile;
typedef struct _s_11d23ff7_optionalLine { int value; } _s_11d23ff7_optionalLine;
typedef struct _s_11d23ff7_optionalUserData { void* value; } _s_11d23ff7_optionalUserData;
typedef struct _s_11d23ff7_rteParameters { void* value; } _s_11d23ff7_rteParameters;
static inline _s_11d23ff7_helperStructs _11d23ff7_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_11d23ff7_helperStructs){value}; }
static inline _s_11d23ff7_allocateStructsCount _11d23ff7_allocateStructsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_11d23ff7_allocateStructsCount){value}; }
static inline _s_11d23ff7_outStructsMemory _11d23ff7_outStructsMemory(RedHandleStructsMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_11d23ff7_outStructsMemory){value}; }
static inline _s_11d23ff7_outStatuses _11d23ff7_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_11d23ff7_outStatuses){value}; }
static inline _s_11d23ff7_optionalFile _11d23ff7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_11d23ff7_optionalFile){value}; }
static inline _s_11d23ff7_optionalLine _11d23ff7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_11d23ff7_optionalLine){value}; }
static inline _s_11d23ff7_optionalUserData _11d23ff7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_11d23ff7_optionalUserData){value}; }
static inline _s_11d23ff7_rteParameters _11d23ff7_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_11d23ff7_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsCreateStructsMemory(_s_11d23ff7_helperStructs helperStructs, _s_11d23ff7_allocateStructsCount allocateStructsCount, _s_11d23ff7_outStructsMemory outStructsMemory, _s_11d23ff7_outStatuses outStatuses, _s_11d23ff7_optionalFile optionalFile, _s_11d23ff7_optionalLine optionalLine, _s_11d23ff7_optionalUserData optionalUserData, _s_11d23ff7_rteParameters rteParameters) {
  return redRteHelperStructsCreateStructsMemory(helperStructs.value, allocateStructsCount.value, outStructsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsGetStruct redRteHelperStructsGetStruct
#define _b86a44b7_helperStructs(value) value
#define _b86a44b7_structIndex(value) value
#define _b86a44b7_optionalFile(value) value
#define _b86a44b7_optionalLine(value) value
#define _b86a44b7_optionalUserData(value) value
#define _b86a44b7_rteParameters(value) value
#else
typedef struct _s_b86a44b7_helperStructs { RedRteHandleHelperStructs value; } _s_b86a44b7_helperStructs;
typedef struct _s_b86a44b7_structIndex { unsigned value; } _s_b86a44b7_structIndex;
typedef struct _s_b86a44b7_optionalFile { char* value; } _s_b86a44b7_optionalFile;
typedef struct _s_b86a44b7_optionalLine { int value; } _s_b86a44b7_optionalLine;
typedef struct _s_b86a44b7_optionalUserData { void* value; } _s_b86a44b7_optionalUserData;
typedef struct _s_b86a44b7_rteParameters { void* value; } _s_b86a44b7_rteParameters;
static inline _s_b86a44b7_helperStructs _b86a44b7_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_b86a44b7_helperStructs){value}; }
static inline _s_b86a44b7_structIndex _b86a44b7_structIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b86a44b7_structIndex){value}; }
static inline _s_b86a44b7_optionalFile _b86a44b7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b86a44b7_optionalFile){value}; }
static inline _s_b86a44b7_optionalLine _b86a44b7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b86a44b7_optionalLine){value}; }
static inline _s_b86a44b7_optionalUserData _b86a44b7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b86a44b7_optionalUserData){value}; }
static inline _s_b86a44b7_rteParameters _b86a44b7_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b86a44b7_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleStruct REDGPU_NP_API np_redRteHelperStructsGetStruct(_s_b86a44b7_helperStructs helperStructs, _s_b86a44b7_structIndex structIndex, _s_b86a44b7_optionalFile optionalFile, _s_b86a44b7_optionalLine optionalLine, _s_b86a44b7_optionalUserData optionalUserData, _s_b86a44b7_rteParameters rteParameters) {
  return redRteHelperStructsGetStruct(helperStructs.value, structIndex.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsGetStructsCount redRteHelperStructsGetStructsCount
#define _e962846e_helperStructs(value) value
#define _e962846e_optionalFile(value) value
#define _e962846e_optionalLine(value) value
#define _e962846e_optionalUserData(value) value
#define _e962846e_rteParameters(value) value
#else
typedef struct _s_e962846e_helperStructs { RedRteHandleHelperStructs value; } _s_e962846e_helperStructs;
typedef struct _s_e962846e_optionalFile { char* value; } _s_e962846e_optionalFile;
typedef struct _s_e962846e_optionalLine { int value; } _s_e962846e_optionalLine;
typedef struct _s_e962846e_optionalUserData { void* value; } _s_e962846e_optionalUserData;
typedef struct _s_e962846e_rteParameters { void* value; } _s_e962846e_rteParameters;
static inline _s_e962846e_helperStructs _e962846e_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_e962846e_helperStructs){value}; }
static inline _s_e962846e_optionalFile _e962846e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e962846e_optionalFile){value}; }
static inline _s_e962846e_optionalLine _e962846e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e962846e_optionalLine){value}; }
static inline _s_e962846e_optionalUserData _e962846e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e962846e_optionalUserData){value}; }
static inline _s_e962846e_rteParameters _e962846e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e962846e_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redRteHelperStructsGetStructsCount(_s_e962846e_helperStructs helperStructs, _s_e962846e_optionalFile optionalFile, _s_e962846e_optionalLine optionalLine, _s_e962846e_optionalUserData optionalUserData, _s_e962846e_rteParameters rteParameters) {
  return redRteHelperStructsGetStructsCount(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsGetStructs redRteHelperStructsGetStructs
#define _e65e5dba_helperStructs(value) value
#define _e65e5dba_optionalFile(value) value
#define _e65e5dba_optionalLine(value) value
#define _e65e5dba_optionalUserData(value) value
#define _e65e5dba_rteParameters(value) value
#else
typedef struct _s_e65e5dba_helperStructs { RedRteHandleHelperStructs value; } _s_e65e5dba_helperStructs;
typedef struct _s_e65e5dba_optionalFile { char* value; } _s_e65e5dba_optionalFile;
typedef struct _s_e65e5dba_optionalLine { int value; } _s_e65e5dba_optionalLine;
typedef struct _s_e65e5dba_optionalUserData { void* value; } _s_e65e5dba_optionalUserData;
typedef struct _s_e65e5dba_rteParameters { void* value; } _s_e65e5dba_rteParameters;
static inline _s_e65e5dba_helperStructs _e65e5dba_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_e65e5dba_helperStructs){value}; }
static inline _s_e65e5dba_optionalFile _e65e5dba_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e65e5dba_optionalFile){value}; }
static inline _s_e65e5dba_optionalLine _e65e5dba_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e65e5dba_optionalLine){value}; }
static inline _s_e65e5dba_optionalUserData _e65e5dba_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e65e5dba_optionalUserData){value}; }
static inline _s_e65e5dba_rteParameters _e65e5dba_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e65e5dba_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleStruct* REDGPU_NP_API np_redRteHelperStructsGetStructs(_s_e65e5dba_helperStructs helperStructs, _s_e65e5dba_optionalFile optionalFile, _s_e65e5dba_optionalLine optionalLine, _s_e65e5dba_optionalUserData optionalUserData, _s_e65e5dba_rteParameters rteParameters) {
  return redRteHelperStructsGetStructs(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsGetStructDeclarationMembersCount redRteHelperStructsGetStructDeclarationMembersCount
#define _46345fbc_helperStructs(value) value
#define _46345fbc_optionalFile(value) value
#define _46345fbc_optionalLine(value) value
#define _46345fbc_optionalUserData(value) value
#define _46345fbc_rteParameters(value) value
#else
typedef struct _s_46345fbc_helperStructs { RedRteHandleHelperStructs value; } _s_46345fbc_helperStructs;
typedef struct _s_46345fbc_optionalFile { char* value; } _s_46345fbc_optionalFile;
typedef struct _s_46345fbc_optionalLine { int value; } _s_46345fbc_optionalLine;
typedef struct _s_46345fbc_optionalUserData { void* value; } _s_46345fbc_optionalUserData;
typedef struct _s_46345fbc_rteParameters { void* value; } _s_46345fbc_rteParameters;
static inline _s_46345fbc_helperStructs _46345fbc_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_46345fbc_helperStructs){value}; }
static inline _s_46345fbc_optionalFile _46345fbc_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_46345fbc_optionalFile){value}; }
static inline _s_46345fbc_optionalLine _46345fbc_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_46345fbc_optionalLine){value}; }
static inline _s_46345fbc_optionalUserData _46345fbc_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_46345fbc_optionalUserData){value}; }
static inline _s_46345fbc_rteParameters _46345fbc_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_46345fbc_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redRteHelperStructsGetStructDeclarationMembersCount(_s_46345fbc_helperStructs helperStructs, _s_46345fbc_optionalFile optionalFile, _s_46345fbc_optionalLine optionalLine, _s_46345fbc_optionalUserData optionalUserData, _s_46345fbc_rteParameters rteParameters) {
  return redRteHelperStructsGetStructDeclarationMembersCount(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsGetStructDeclarationMembers redRteHelperStructsGetStructDeclarationMembers
#define _d1f18e89_helperStructs(value) value
#define _d1f18e89_optionalFile(value) value
#define _d1f18e89_optionalLine(value) value
#define _d1f18e89_optionalUserData(value) value
#define _d1f18e89_rteParameters(value) value
#else
typedef struct _s_d1f18e89_helperStructs { RedRteHandleHelperStructs value; } _s_d1f18e89_helperStructs;
typedef struct _s_d1f18e89_optionalFile { char* value; } _s_d1f18e89_optionalFile;
typedef struct _s_d1f18e89_optionalLine { int value; } _s_d1f18e89_optionalLine;
typedef struct _s_d1f18e89_optionalUserData { void* value; } _s_d1f18e89_optionalUserData;
typedef struct _s_d1f18e89_rteParameters { void* value; } _s_d1f18e89_rteParameters;
static inline _s_d1f18e89_helperStructs _d1f18e89_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_d1f18e89_helperStructs){value}; }
static inline _s_d1f18e89_optionalFile _d1f18e89_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d1f18e89_optionalFile){value}; }
static inline _s_d1f18e89_optionalLine _d1f18e89_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d1f18e89_optionalLine){value}; }
static inline _s_d1f18e89_optionalUserData _d1f18e89_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d1f18e89_optionalUserData){value}; }
static inline _s_d1f18e89_rteParameters _d1f18e89_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d1f18e89_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedStructDeclarationMember* REDGPU_NP_API np_redRteHelperStructsGetStructDeclarationMembers(_s_d1f18e89_helperStructs helperStructs, _s_d1f18e89_optionalFile optionalFile, _s_d1f18e89_optionalLine optionalLine, _s_d1f18e89_optionalUserData optionalUserData, _s_d1f18e89_rteParameters rteParameters) {
  return redRteHelperStructsGetStructDeclarationMembers(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsDestroyStructDeclaration redRteHelperStructsDestroyStructDeclaration
#define _971201b9_helperStructs(value) value
#define _971201b9_optionalFile(value) value
#define _971201b9_optionalLine(value) value
#define _971201b9_optionalUserData(value) value
#define _971201b9_rteParameters(value) value
#else
typedef struct _s_971201b9_helperStructs { RedRteHandleHelperStructs value; } _s_971201b9_helperStructs;
typedef struct _s_971201b9_optionalFile { char* value; } _s_971201b9_optionalFile;
typedef struct _s_971201b9_optionalLine { int value; } _s_971201b9_optionalLine;
typedef struct _s_971201b9_optionalUserData { void* value; } _s_971201b9_optionalUserData;
typedef struct _s_971201b9_rteParameters { void* value; } _s_971201b9_rteParameters;
static inline _s_971201b9_helperStructs _971201b9_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_971201b9_helperStructs){value}; }
static inline _s_971201b9_optionalFile _971201b9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_971201b9_optionalFile){value}; }
static inline _s_971201b9_optionalLine _971201b9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_971201b9_optionalLine){value}; }
static inline _s_971201b9_optionalUserData _971201b9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_971201b9_optionalUserData){value}; }
static inline _s_971201b9_rteParameters _971201b9_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_971201b9_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsDestroyStructDeclaration(_s_971201b9_helperStructs helperStructs, _s_971201b9_optionalFile optionalFile, _s_971201b9_optionalLine optionalLine, _s_971201b9_optionalUserData optionalUserData, _s_971201b9_rteParameters rteParameters) {
  return redRteHelperStructsDestroyStructDeclaration(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsDestroyStructsMemory redRteHelperStructsDestroyStructsMemory
#define _c92c46fb_helperStructs(value) value
#define _c92c46fb_optionalFile(value) value
#define _c92c46fb_optionalLine(value) value
#define _c92c46fb_optionalUserData(value) value
#define _c92c46fb_rteParameters(value) value
#else
typedef struct _s_c92c46fb_helperStructs { RedRteHandleHelperStructs value; } _s_c92c46fb_helperStructs;
typedef struct _s_c92c46fb_optionalFile { char* value; } _s_c92c46fb_optionalFile;
typedef struct _s_c92c46fb_optionalLine { int value; } _s_c92c46fb_optionalLine;
typedef struct _s_c92c46fb_optionalUserData { void* value; } _s_c92c46fb_optionalUserData;
typedef struct _s_c92c46fb_rteParameters { void* value; } _s_c92c46fb_rteParameters;
static inline _s_c92c46fb_helperStructs _c92c46fb_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_c92c46fb_helperStructs){value}; }
static inline _s_c92c46fb_optionalFile _c92c46fb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c92c46fb_optionalFile){value}; }
static inline _s_c92c46fb_optionalLine _c92c46fb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c92c46fb_optionalLine){value}; }
static inline _s_c92c46fb_optionalUserData _c92c46fb_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c92c46fb_optionalUserData){value}; }
static inline _s_c92c46fb_rteParameters _c92c46fb_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c92c46fb_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsDestroyStructsMemory(_s_c92c46fb_helperStructs helperStructs, _s_c92c46fb_optionalFile optionalFile, _s_c92c46fb_optionalLine optionalLine, _s_c92c46fb_optionalUserData optionalUserData, _s_c92c46fb_rteParameters rteParameters) {
  return redRteHelperStructsDestroyStructsMemory(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsClear redRteHelperStructsClear
#define _1ee4ec30_helperStructs(value) value
#define _1ee4ec30_optionalFile(value) value
#define _1ee4ec30_optionalLine(value) value
#define _1ee4ec30_optionalUserData(value) value
#define _1ee4ec30_rteParameters(value) value
#else
typedef struct _s_1ee4ec30_helperStructs { RedRteHandleHelperStructs value; } _s_1ee4ec30_helperStructs;
typedef struct _s_1ee4ec30_optionalFile { char* value; } _s_1ee4ec30_optionalFile;
typedef struct _s_1ee4ec30_optionalLine { int value; } _s_1ee4ec30_optionalLine;
typedef struct _s_1ee4ec30_optionalUserData { void* value; } _s_1ee4ec30_optionalUserData;
typedef struct _s_1ee4ec30_rteParameters { void* value; } _s_1ee4ec30_rteParameters;
static inline _s_1ee4ec30_helperStructs _1ee4ec30_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_1ee4ec30_helperStructs){value}; }
static inline _s_1ee4ec30_optionalFile _1ee4ec30_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1ee4ec30_optionalFile){value}; }
static inline _s_1ee4ec30_optionalLine _1ee4ec30_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1ee4ec30_optionalLine){value}; }
static inline _s_1ee4ec30_optionalUserData _1ee4ec30_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1ee4ec30_optionalUserData){value}; }
static inline _s_1ee4ec30_rteParameters _1ee4ec30_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1ee4ec30_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsClear(_s_1ee4ec30_helperStructs helperStructs, _s_1ee4ec30_optionalFile optionalFile, _s_1ee4ec30_optionalLine optionalLine, _s_1ee4ec30_optionalUserData optionalUserData, _s_1ee4ec30_rteParameters rteParameters) {
  return redRteHelperStructsClear(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateRayTracingBuilder redRteCreateRayTracingBuilder
#define _2097d6bb_rteContext(value) value
#define _2097d6bb_rteHandleHelperAllocator(value) value
#define _2097d6bb_queueFamilyIndex(value) value
#define _2097d6bb_outRayTracingBuilder(value) value
#define _2097d6bb_outStatuses(value) value
#define _2097d6bb_optionalFile(value) value
#define _2097d6bb_optionalLine(value) value
#define _2097d6bb_optionalUserData(value) value
#define _2097d6bb_rteParameters(value) value
#else
typedef struct _s_2097d6bb_rteContext { RedRteHandleContext value; } _s_2097d6bb_rteContext;
typedef struct _s_2097d6bb_rteHandleHelperAllocator { void* value; } _s_2097d6bb_rteHandleHelperAllocator;
typedef struct _s_2097d6bb_queueFamilyIndex { unsigned value; } _s_2097d6bb_queueFamilyIndex;
typedef struct _s_2097d6bb_outRayTracingBuilder { RedRteHandleRayTracingBuilder* value; } _s_2097d6bb_outRayTracingBuilder;
typedef struct _s_2097d6bb_outStatuses { RedStatuses* value; } _s_2097d6bb_outStatuses;
typedef struct _s_2097d6bb_optionalFile { char* value; } _s_2097d6bb_optionalFile;
typedef struct _s_2097d6bb_optionalLine { int value; } _s_2097d6bb_optionalLine;
typedef struct _s_2097d6bb_optionalUserData { void* value; } _s_2097d6bb_optionalUserData;
typedef struct _s_2097d6bb_rteParameters { void* value; } _s_2097d6bb_rteParameters;
static inline _s_2097d6bb_rteContext _2097d6bb_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_2097d6bb_rteContext){value}; }
static inline _s_2097d6bb_rteHandleHelperAllocator _2097d6bb_rteHandleHelperAllocator(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2097d6bb_rteHandleHelperAllocator){value}; }
static inline _s_2097d6bb_queueFamilyIndex _2097d6bb_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_2097d6bb_queueFamilyIndex){value}; }
static inline _s_2097d6bb_outRayTracingBuilder _2097d6bb_outRayTracingBuilder(RedRteHandleRayTracingBuilder* value) { return REDGPU_NP_STRUCT_INIT(_s_2097d6bb_outRayTracingBuilder){value}; }
static inline _s_2097d6bb_outStatuses _2097d6bb_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_2097d6bb_outStatuses){value}; }
static inline _s_2097d6bb_optionalFile _2097d6bb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2097d6bb_optionalFile){value}; }
static inline _s_2097d6bb_optionalLine _2097d6bb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2097d6bb_optionalLine){value}; }
static inline _s_2097d6bb_optionalUserData _2097d6bb_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2097d6bb_optionalUserData){value}; }
static inline _s_2097d6bb_rteParameters _2097d6bb_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2097d6bb_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateRayTracingBuilder(_s_2097d6bb_rteContext rteContext, _s_2097d6bb_rteHandleHelperAllocator rteHandleHelperAllocator, _s_2097d6bb_queueFamilyIndex queueFamilyIndex, _s_2097d6bb_outRayTracingBuilder outRayTracingBuilder, _s_2097d6bb_outStatuses outStatuses, _s_2097d6bb_optionalFile optionalFile, _s_2097d6bb_optionalLine optionalLine, _s_2097d6bb_optionalUserData optionalUserData, _s_2097d6bb_rteParameters rteParameters) {
  return redRteCreateRayTracingBuilder(rteContext.value, rteHandleHelperAllocator.value, queueFamilyIndex.value, outRayTracingBuilder.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyRayTracingBuilder redRteDestroyRayTracingBuilder
#define _1c743ff7_rayTracingBuilder(value) value
#define _1c743ff7_optionalFile(value) value
#define _1c743ff7_optionalLine(value) value
#define _1c743ff7_optionalUserData(value) value
#define _1c743ff7_rteParameters(value) value
#else
typedef struct _s_1c743ff7_rayTracingBuilder { RedRteHandleRayTracingBuilder value; } _s_1c743ff7_rayTracingBuilder;
typedef struct _s_1c743ff7_optionalFile { char* value; } _s_1c743ff7_optionalFile;
typedef struct _s_1c743ff7_optionalLine { int value; } _s_1c743ff7_optionalLine;
typedef struct _s_1c743ff7_optionalUserData { void* value; } _s_1c743ff7_optionalUserData;
typedef struct _s_1c743ff7_rteParameters { void* value; } _s_1c743ff7_rteParameters;
static inline _s_1c743ff7_rayTracingBuilder _1c743ff7_rayTracingBuilder(RedRteHandleRayTracingBuilder value) { return REDGPU_NP_STRUCT_INIT(_s_1c743ff7_rayTracingBuilder){value}; }
static inline _s_1c743ff7_optionalFile _1c743ff7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1c743ff7_optionalFile){value}; }
static inline _s_1c743ff7_optionalLine _1c743ff7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1c743ff7_optionalLine){value}; }
static inline _s_1c743ff7_optionalUserData _1c743ff7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1c743ff7_optionalUserData){value}; }
static inline _s_1c743ff7_rteParameters _1c743ff7_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1c743ff7_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyRayTracingBuilder(_s_1c743ff7_rayTracingBuilder rayTracingBuilder, _s_1c743ff7_optionalFile optionalFile, _s_1c743ff7_optionalLine optionalLine, _s_1c743ff7_optionalUserData optionalUserData, _s_1c743ff7_rteParameters rteParameters) {
  return redRteDestroyRayTracingBuilder(rayTracingBuilder.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteRayTracingBuilderBuildBlas redRteRayTracingBuilderBuildBlas
#define _252d81b1_rayTracingBuilder(value) value
#define _252d81b1_blasInputsCount(value) value
#define _252d81b1_blasInputs(value) value
#define _252d81b1_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit(value) value
#define _252d81b1_outStatuses(value) value
#define _252d81b1_optionalFile(value) value
#define _252d81b1_optionalLine(value) value
#define _252d81b1_optionalUserData(value) value
#define _252d81b1_rteParameters(value) value
#else
typedef struct _s_252d81b1_rayTracingBuilder { RedRteHandleRayTracingBuilder value; } _s_252d81b1_rayTracingBuilder;
typedef struct _s_252d81b1_blasInputsCount { unsigned value; } _s_252d81b1_blasInputsCount;
typedef struct _s_252d81b1_blasInputs { RedRteRayTracingBuilderBlasInput* value; } _s_252d81b1_blasInputs;
typedef struct _s_252d81b1_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit { unsigned value; } _s_252d81b1_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit;
typedef struct _s_252d81b1_outStatuses { RedStatuses* value; } _s_252d81b1_outStatuses;
typedef struct _s_252d81b1_optionalFile { char* value; } _s_252d81b1_optionalFile;
typedef struct _s_252d81b1_optionalLine { int value; } _s_252d81b1_optionalLine;
typedef struct _s_252d81b1_optionalUserData { void* value; } _s_252d81b1_optionalUserData;
typedef struct _s_252d81b1_rteParameters { void* value; } _s_252d81b1_rteParameters;
static inline _s_252d81b1_rayTracingBuilder _252d81b1_rayTracingBuilder(RedRteHandleRayTracingBuilder value) { return REDGPU_NP_STRUCT_INIT(_s_252d81b1_rayTracingBuilder){value}; }
static inline _s_252d81b1_blasInputsCount _252d81b1_blasInputsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_252d81b1_blasInputsCount){value}; }
static inline _s_252d81b1_blasInputs _252d81b1_blasInputs(RedRteRayTracingBuilderBlasInput* value) { return REDGPU_NP_STRUCT_INIT(_s_252d81b1_blasInputs){value}; }
static inline _s_252d81b1_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit _252d81b1_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_252d81b1_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit){value}; }
static inline _s_252d81b1_outStatuses _252d81b1_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_252d81b1_outStatuses){value}; }
static inline _s_252d81b1_optionalFile _252d81b1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_252d81b1_optionalFile){value}; }
static inline _s_252d81b1_optionalLine _252d81b1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_252d81b1_optionalLine){value}; }
static inline _s_252d81b1_optionalUserData _252d81b1_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_252d81b1_optionalUserData){value}; }
static inline _s_252d81b1_rteParameters _252d81b1_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_252d81b1_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteRayTracingBuilderBuildBlas(_s_252d81b1_rayTracingBuilder rayTracingBuilder, _s_252d81b1_blasInputsCount blasInputsCount, _s_252d81b1_blasInputs blasInputs, _s_252d81b1_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit, _s_252d81b1_outStatuses outStatuses, _s_252d81b1_optionalFile optionalFile, _s_252d81b1_optionalLine optionalLine, _s_252d81b1_optionalUserData optionalUserData, _s_252d81b1_rteParameters rteParameters) {
  return redRteRayTracingBuilderBuildBlas(rayTracingBuilder.value, blasInputsCount.value, blasInputs.value, buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteRayTracingBuilderGetBlasGpuAddress redRteRayTracingBuilderGetBlasGpuAddress
#define _f28a5cda_rayTracingBuilder(value) value
#define _f28a5cda_blasIndex(value) value
#define _f28a5cda_optionalFile(value) value
#define _f28a5cda_optionalLine(value) value
#define _f28a5cda_optionalUserData(value) value
#define _f28a5cda_rteParameters(value) value
#else
typedef struct _s_f28a5cda_rayTracingBuilder { RedRteHandleRayTracingBuilder value; } _s_f28a5cda_rayTracingBuilder;
typedef struct _s_f28a5cda_blasIndex { unsigned value; } _s_f28a5cda_blasIndex;
typedef struct _s_f28a5cda_optionalFile { char* value; } _s_f28a5cda_optionalFile;
typedef struct _s_f28a5cda_optionalLine { int value; } _s_f28a5cda_optionalLine;
typedef struct _s_f28a5cda_optionalUserData { void* value; } _s_f28a5cda_optionalUserData;
typedef struct _s_f28a5cda_rteParameters { void* value; } _s_f28a5cda_rteParameters;
static inline _s_f28a5cda_rayTracingBuilder _f28a5cda_rayTracingBuilder(RedRteHandleRayTracingBuilder value) { return REDGPU_NP_STRUCT_INIT(_s_f28a5cda_rayTracingBuilder){value}; }
static inline _s_f28a5cda_blasIndex _f28a5cda_blasIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f28a5cda_blasIndex){value}; }
static inline _s_f28a5cda_optionalFile _f28a5cda_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f28a5cda_optionalFile){value}; }
static inline _s_f28a5cda_optionalLine _f28a5cda_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f28a5cda_optionalLine){value}; }
static inline _s_f28a5cda_optionalUserData _f28a5cda_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f28a5cda_optionalUserData){value}; }
static inline _s_f28a5cda_rteParameters _f28a5cda_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f28a5cda_rteParameters){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redRteRayTracingBuilderGetBlasGpuAddress(_s_f28a5cda_rayTracingBuilder rayTracingBuilder, _s_f28a5cda_blasIndex blasIndex, _s_f28a5cda_optionalFile optionalFile, _s_f28a5cda_optionalLine optionalLine, _s_f28a5cda_optionalUserData optionalUserData, _s_f28a5cda_rteParameters rteParameters) {
  return redRteRayTracingBuilderGetBlasGpuAddress(rayTracingBuilder.value, blasIndex.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteRayTracingBuilderBuildTlas redRteRayTracingBuilderBuildTlas
#define _3ba6a5b7_rayTracingBuilder(value) value
#define _3ba6a5b7_instancesCount(value) value
#define _3ba6a5b7_instances(value) value
#define _3ba6a5b7_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit(value) value
#define _3ba6a5b7_update(value) value
#define _3ba6a5b7_outStatuses(value) value
#define _3ba6a5b7_optionalFile(value) value
#define _3ba6a5b7_optionalLine(value) value
#define _3ba6a5b7_optionalUserData(value) value
#define _3ba6a5b7_rteParameters(value) value
#else
typedef struct _s_3ba6a5b7_rayTracingBuilder { RedRteHandleRayTracingBuilder value; } _s_3ba6a5b7_rayTracingBuilder;
typedef struct _s_3ba6a5b7_instancesCount { unsigned value; } _s_3ba6a5b7_instancesCount;
typedef struct _s_3ba6a5b7_instances { RedRteRayTracingAccelerationStructureInstance* value; } _s_3ba6a5b7_instances;
typedef struct _s_3ba6a5b7_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit { unsigned value; } _s_3ba6a5b7_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit;
typedef struct _s_3ba6a5b7_update { RedBool32 value; } _s_3ba6a5b7_update;
typedef struct _s_3ba6a5b7_outStatuses { RedStatuses* value; } _s_3ba6a5b7_outStatuses;
typedef struct _s_3ba6a5b7_optionalFile { char* value; } _s_3ba6a5b7_optionalFile;
typedef struct _s_3ba6a5b7_optionalLine { int value; } _s_3ba6a5b7_optionalLine;
typedef struct _s_3ba6a5b7_optionalUserData { void* value; } _s_3ba6a5b7_optionalUserData;
typedef struct _s_3ba6a5b7_rteParameters { void* value; } _s_3ba6a5b7_rteParameters;
static inline _s_3ba6a5b7_rayTracingBuilder _3ba6a5b7_rayTracingBuilder(RedRteHandleRayTracingBuilder value) { return REDGPU_NP_STRUCT_INIT(_s_3ba6a5b7_rayTracingBuilder){value}; }
static inline _s_3ba6a5b7_instancesCount _3ba6a5b7_instancesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3ba6a5b7_instancesCount){value}; }
static inline _s_3ba6a5b7_instances _3ba6a5b7_instances(RedRteRayTracingAccelerationStructureInstance* value) { return REDGPU_NP_STRUCT_INIT(_s_3ba6a5b7_instances){value}; }
static inline _s_3ba6a5b7_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit _3ba6a5b7_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3ba6a5b7_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit){value}; }
static inline _s_3ba6a5b7_update _3ba6a5b7_update(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_3ba6a5b7_update){value}; }
static inline _s_3ba6a5b7_outStatuses _3ba6a5b7_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_3ba6a5b7_outStatuses){value}; }
static inline _s_3ba6a5b7_optionalFile _3ba6a5b7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3ba6a5b7_optionalFile){value}; }
static inline _s_3ba6a5b7_optionalLine _3ba6a5b7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3ba6a5b7_optionalLine){value}; }
static inline _s_3ba6a5b7_optionalUserData _3ba6a5b7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3ba6a5b7_optionalUserData){value}; }
static inline _s_3ba6a5b7_rteParameters _3ba6a5b7_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3ba6a5b7_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteRayTracingBuilderBuildTlas(_s_3ba6a5b7_rayTracingBuilder rayTracingBuilder, _s_3ba6a5b7_instancesCount instancesCount, _s_3ba6a5b7_instances instances, _s_3ba6a5b7_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit, _s_3ba6a5b7_update update, _s_3ba6a5b7_outStatuses outStatuses, _s_3ba6a5b7_optionalFile optionalFile, _s_3ba6a5b7_optionalLine optionalLine, _s_3ba6a5b7_optionalUserData optionalUserData, _s_3ba6a5b7_rteParameters rteParameters) {
  return redRteRayTracingBuilderBuildTlas(rayTracingBuilder.value, instancesCount.value, instances.value, buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit.value, update.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteRayTracingBuilderGetTlas redRteRayTracingBuilderGetTlas
#define _f0e095a0_rayTracingBuilder(value) value
#define _f0e095a0_optionalFile(value) value
#define _f0e095a0_optionalLine(value) value
#define _f0e095a0_optionalUserData(value) value
#define _f0e095a0_rteParameters(value) value
#else
typedef struct _s_f0e095a0_rayTracingBuilder { RedRteHandleRayTracingBuilder value; } _s_f0e095a0_rayTracingBuilder;
typedef struct _s_f0e095a0_optionalFile { char* value; } _s_f0e095a0_optionalFile;
typedef struct _s_f0e095a0_optionalLine { int value; } _s_f0e095a0_optionalLine;
typedef struct _s_f0e095a0_optionalUserData { void* value; } _s_f0e095a0_optionalUserData;
typedef struct _s_f0e095a0_rteParameters { void* value; } _s_f0e095a0_rteParameters;
static inline _s_f0e095a0_rayTracingBuilder _f0e095a0_rayTracingBuilder(RedRteHandleRayTracingBuilder value) { return REDGPU_NP_STRUCT_INIT(_s_f0e095a0_rayTracingBuilder){value}; }
static inline _s_f0e095a0_optionalFile _f0e095a0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f0e095a0_optionalFile){value}; }
static inline _s_f0e095a0_optionalLine _f0e095a0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f0e095a0_optionalLine){value}; }
static inline _s_f0e095a0_optionalUserData _f0e095a0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f0e095a0_optionalUserData){value}; }
static inline _s_f0e095a0_rteParameters _f0e095a0_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f0e095a0_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedRteHandleRayTracingAccelerationStructure REDGPU_NP_API np_redRteRayTracingBuilderGetTlas(_s_f0e095a0_rayTracingBuilder rayTracingBuilder, _s_f0e095a0_optionalFile optionalFile, _s_f0e095a0_optionalLine optionalLine, _s_f0e095a0_optionalUserData optionalUserData, _s_f0e095a0_rteParameters rteParameters) {
  return redRteRayTracingBuilderGetTlas(rayTracingBuilder.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteRayTracingBuilderUpdateBlas redRteRayTracingBuilderUpdateBlas
#define _83ea9684_rayTracingBuilder(value) value
#define _83ea9684_blasIndex(value) value
#define _83ea9684_blasInput(value) value
#define _83ea9684_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit(value) value
#define _83ea9684_outStatuses(value) value
#define _83ea9684_optionalFile(value) value
#define _83ea9684_optionalLine(value) value
#define _83ea9684_optionalUserData(value) value
#define _83ea9684_rteParameters(value) value
#else
typedef struct _s_83ea9684_rayTracingBuilder { RedRteHandleRayTracingBuilder value; } _s_83ea9684_rayTracingBuilder;
typedef struct _s_83ea9684_blasIndex { unsigned value; } _s_83ea9684_blasIndex;
typedef struct _s_83ea9684_blasInput { RedRteRayTracingBuilderBlasInput* value; } _s_83ea9684_blasInput;
typedef struct _s_83ea9684_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit { unsigned value; } _s_83ea9684_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit;
typedef struct _s_83ea9684_outStatuses { RedStatuses* value; } _s_83ea9684_outStatuses;
typedef struct _s_83ea9684_optionalFile { char* value; } _s_83ea9684_optionalFile;
typedef struct _s_83ea9684_optionalLine { int value; } _s_83ea9684_optionalLine;
typedef struct _s_83ea9684_optionalUserData { void* value; } _s_83ea9684_optionalUserData;
typedef struct _s_83ea9684_rteParameters { void* value; } _s_83ea9684_rteParameters;
static inline _s_83ea9684_rayTracingBuilder _83ea9684_rayTracingBuilder(RedRteHandleRayTracingBuilder value) { return REDGPU_NP_STRUCT_INIT(_s_83ea9684_rayTracingBuilder){value}; }
static inline _s_83ea9684_blasIndex _83ea9684_blasIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_83ea9684_blasIndex){value}; }
static inline _s_83ea9684_blasInput _83ea9684_blasInput(RedRteRayTracingBuilderBlasInput* value) { return REDGPU_NP_STRUCT_INIT(_s_83ea9684_blasInput){value}; }
static inline _s_83ea9684_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit _83ea9684_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_83ea9684_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit){value}; }
static inline _s_83ea9684_outStatuses _83ea9684_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_83ea9684_outStatuses){value}; }
static inline _s_83ea9684_optionalFile _83ea9684_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_83ea9684_optionalFile){value}; }
static inline _s_83ea9684_optionalLine _83ea9684_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_83ea9684_optionalLine){value}; }
static inline _s_83ea9684_optionalUserData _83ea9684_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_83ea9684_optionalUserData){value}; }
static inline _s_83ea9684_rteParameters _83ea9684_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_83ea9684_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteRayTracingBuilderUpdateBlas(_s_83ea9684_rayTracingBuilder rayTracingBuilder, _s_83ea9684_blasIndex blasIndex, _s_83ea9684_blasInput blasInput, _s_83ea9684_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit, _s_83ea9684_outStatuses outStatuses, _s_83ea9684_optionalFile optionalFile, _s_83ea9684_optionalLine optionalLine, _s_83ea9684_optionalUserData optionalUserData, _s_83ea9684_rteParameters rteParameters) {
  return redRteRayTracingBuilderUpdateBlas(rayTracingBuilder.value, blasIndex.value, blasInput.value, buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateDeferredOperation redRteCreateDeferredOperation
#define _797e3933_rteContext(value) value
#define _797e3933_outDeferredOperation(value) value
#define _797e3933_outStatuses(value) value
#define _797e3933_optionalFile(value) value
#define _797e3933_optionalLine(value) value
#define _797e3933_optionalUserData(value) value
#define _797e3933_rteParameters(value) value
#else
typedef struct _s_797e3933_rteContext { RedRteHandleContext value; } _s_797e3933_rteContext;
typedef struct _s_797e3933_outDeferredOperation { RedRteHandleDeferredOperation* value; } _s_797e3933_outDeferredOperation;
typedef struct _s_797e3933_outStatuses { RedStatuses* value; } _s_797e3933_outStatuses;
typedef struct _s_797e3933_optionalFile { char* value; } _s_797e3933_optionalFile;
typedef struct _s_797e3933_optionalLine { int value; } _s_797e3933_optionalLine;
typedef struct _s_797e3933_optionalUserData { void* value; } _s_797e3933_optionalUserData;
typedef struct _s_797e3933_rteParameters { void* value; } _s_797e3933_rteParameters;
static inline _s_797e3933_rteContext _797e3933_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_797e3933_rteContext){value}; }
static inline _s_797e3933_outDeferredOperation _797e3933_outDeferredOperation(RedRteHandleDeferredOperation* value) { return REDGPU_NP_STRUCT_INIT(_s_797e3933_outDeferredOperation){value}; }
static inline _s_797e3933_outStatuses _797e3933_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_797e3933_outStatuses){value}; }
static inline _s_797e3933_optionalFile _797e3933_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_797e3933_optionalFile){value}; }
static inline _s_797e3933_optionalLine _797e3933_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_797e3933_optionalLine){value}; }
static inline _s_797e3933_optionalUserData _797e3933_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_797e3933_optionalUserData){value}; }
static inline _s_797e3933_rteParameters _797e3933_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_797e3933_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateDeferredOperation(_s_797e3933_rteContext rteContext, _s_797e3933_outDeferredOperation outDeferredOperation, _s_797e3933_outStatuses outStatuses, _s_797e3933_optionalFile optionalFile, _s_797e3933_optionalLine optionalLine, _s_797e3933_optionalUserData optionalUserData, _s_797e3933_rteParameters rteParameters) {
  return redRteCreateDeferredOperation(rteContext.value, outDeferredOperation.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyDeferredOperation redRteDestroyDeferredOperation
#define _7cb483f3_rteContext(value) value
#define _7cb483f3_deferredOperation(value) value
#define _7cb483f3_optionalFile(value) value
#define _7cb483f3_optionalLine(value) value
#define _7cb483f3_optionalUserData(value) value
#define _7cb483f3_rteParameters(value) value
#else
typedef struct _s_7cb483f3_rteContext { RedRteHandleContext value; } _s_7cb483f3_rteContext;
typedef struct _s_7cb483f3_deferredOperation { RedRteHandleDeferredOperation value; } _s_7cb483f3_deferredOperation;
typedef struct _s_7cb483f3_optionalFile { char* value; } _s_7cb483f3_optionalFile;
typedef struct _s_7cb483f3_optionalLine { int value; } _s_7cb483f3_optionalLine;
typedef struct _s_7cb483f3_optionalUserData { void* value; } _s_7cb483f3_optionalUserData;
typedef struct _s_7cb483f3_rteParameters { void* value; } _s_7cb483f3_rteParameters;
static inline _s_7cb483f3_rteContext _7cb483f3_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_7cb483f3_rteContext){value}; }
static inline _s_7cb483f3_deferredOperation _7cb483f3_deferredOperation(RedRteHandleDeferredOperation value) { return REDGPU_NP_STRUCT_INIT(_s_7cb483f3_deferredOperation){value}; }
static inline _s_7cb483f3_optionalFile _7cb483f3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7cb483f3_optionalFile){value}; }
static inline _s_7cb483f3_optionalLine _7cb483f3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7cb483f3_optionalLine){value}; }
static inline _s_7cb483f3_optionalUserData _7cb483f3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7cb483f3_optionalUserData){value}; }
static inline _s_7cb483f3_rteParameters _7cb483f3_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7cb483f3_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyDeferredOperation(_s_7cb483f3_rteContext rteContext, _s_7cb483f3_deferredOperation deferredOperation, _s_7cb483f3_optionalFile optionalFile, _s_7cb483f3_optionalLine optionalLine, _s_7cb483f3_optionalUserData optionalUserData, _s_7cb483f3_rteParameters rteParameters) {
  return redRteDestroyDeferredOperation(rteContext.value, deferredOperation.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDeferredOperationGetMaxConcurrency redRteDeferredOperationGetMaxConcurrency
#define _bc0d9b5c_rteContext(value) value
#define _bc0d9b5c_deferredOperation(value) value
#define _bc0d9b5c_optionalFile(value) value
#define _bc0d9b5c_optionalLine(value) value
#define _bc0d9b5c_optionalUserData(value) value
#define _bc0d9b5c_rteParameters(value) value
#else
typedef struct _s_bc0d9b5c_rteContext { RedRteHandleContext value; } _s_bc0d9b5c_rteContext;
typedef struct _s_bc0d9b5c_deferredOperation { RedRteHandleDeferredOperation value; } _s_bc0d9b5c_deferredOperation;
typedef struct _s_bc0d9b5c_optionalFile { char* value; } _s_bc0d9b5c_optionalFile;
typedef struct _s_bc0d9b5c_optionalLine { int value; } _s_bc0d9b5c_optionalLine;
typedef struct _s_bc0d9b5c_optionalUserData { void* value; } _s_bc0d9b5c_optionalUserData;
typedef struct _s_bc0d9b5c_rteParameters { void* value; } _s_bc0d9b5c_rteParameters;
static inline _s_bc0d9b5c_rteContext _bc0d9b5c_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_bc0d9b5c_rteContext){value}; }
static inline _s_bc0d9b5c_deferredOperation _bc0d9b5c_deferredOperation(RedRteHandleDeferredOperation value) { return REDGPU_NP_STRUCT_INIT(_s_bc0d9b5c_deferredOperation){value}; }
static inline _s_bc0d9b5c_optionalFile _bc0d9b5c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bc0d9b5c_optionalFile){value}; }
static inline _s_bc0d9b5c_optionalLine _bc0d9b5c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bc0d9b5c_optionalLine){value}; }
static inline _s_bc0d9b5c_optionalUserData _bc0d9b5c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bc0d9b5c_optionalUserData){value}; }
static inline _s_bc0d9b5c_rteParameters _bc0d9b5c_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bc0d9b5c_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDeferredOperationGetMaxConcurrency(_s_bc0d9b5c_rteContext rteContext, _s_bc0d9b5c_deferredOperation deferredOperation, _s_bc0d9b5c_optionalFile optionalFile, _s_bc0d9b5c_optionalLine optionalLine, _s_bc0d9b5c_optionalUserData optionalUserData, _s_bc0d9b5c_rteParameters rteParameters) {
  return redRteDeferredOperationGetMaxConcurrency(rteContext.value, deferredOperation.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDeferredOperationGetStatus redRteDeferredOperationGetStatus
#define _59fcedec_rteContext(value) value
#define _59fcedec_deferredOperation(value) value
#define _59fcedec_optionalFile(value) value
#define _59fcedec_optionalLine(value) value
#define _59fcedec_optionalUserData(value) value
#define _59fcedec_rteParameters(value) value
#else
typedef struct _s_59fcedec_rteContext { RedRteHandleContext value; } _s_59fcedec_rteContext;
typedef struct _s_59fcedec_deferredOperation { RedRteHandleDeferredOperation value; } _s_59fcedec_deferredOperation;
typedef struct _s_59fcedec_optionalFile { char* value; } _s_59fcedec_optionalFile;
typedef struct _s_59fcedec_optionalLine { int value; } _s_59fcedec_optionalLine;
typedef struct _s_59fcedec_optionalUserData { void* value; } _s_59fcedec_optionalUserData;
typedef struct _s_59fcedec_rteParameters { void* value; } _s_59fcedec_rteParameters;
static inline _s_59fcedec_rteContext _59fcedec_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_59fcedec_rteContext){value}; }
static inline _s_59fcedec_deferredOperation _59fcedec_deferredOperation(RedRteHandleDeferredOperation value) { return REDGPU_NP_STRUCT_INIT(_s_59fcedec_deferredOperation){value}; }
static inline _s_59fcedec_optionalFile _59fcedec_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_59fcedec_optionalFile){value}; }
static inline _s_59fcedec_optionalLine _59fcedec_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_59fcedec_optionalLine){value}; }
static inline _s_59fcedec_optionalUserData _59fcedec_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_59fcedec_optionalUserData){value}; }
static inline _s_59fcedec_rteParameters _59fcedec_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_59fcedec_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDeferredOperationGetStatus(_s_59fcedec_rteContext rteContext, _s_59fcedec_deferredOperation deferredOperation, _s_59fcedec_optionalFile optionalFile, _s_59fcedec_optionalLine optionalLine, _s_59fcedec_optionalUserData optionalUserData, _s_59fcedec_rteParameters rteParameters) {
  return redRteDeferredOperationGetStatus(rteContext.value, deferredOperation.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDeferredOperationJoin redRteDeferredOperationJoin
#define _0b570ac4_rteContext(value) value
#define _0b570ac4_deferredOperation(value) value
#define _0b570ac4_optionalFile(value) value
#define _0b570ac4_optionalLine(value) value
#define _0b570ac4_optionalUserData(value) value
#define _0b570ac4_rteParameters(value) value
#else
typedef struct _s_0b570ac4_rteContext { RedRteHandleContext value; } _s_0b570ac4_rteContext;
typedef struct _s_0b570ac4_deferredOperation { RedRteHandleDeferredOperation value; } _s_0b570ac4_deferredOperation;
typedef struct _s_0b570ac4_optionalFile { char* value; } _s_0b570ac4_optionalFile;
typedef struct _s_0b570ac4_optionalLine { int value; } _s_0b570ac4_optionalLine;
typedef struct _s_0b570ac4_optionalUserData { void* value; } _s_0b570ac4_optionalUserData;
typedef struct _s_0b570ac4_rteParameters { void* value; } _s_0b570ac4_rteParameters;
static inline _s_0b570ac4_rteContext _0b570ac4_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_0b570ac4_rteContext){value}; }
static inline _s_0b570ac4_deferredOperation _0b570ac4_deferredOperation(RedRteHandleDeferredOperation value) { return REDGPU_NP_STRUCT_INIT(_s_0b570ac4_deferredOperation){value}; }
static inline _s_0b570ac4_optionalFile _0b570ac4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0b570ac4_optionalFile){value}; }
static inline _s_0b570ac4_optionalLine _0b570ac4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0b570ac4_optionalLine){value}; }
static inline _s_0b570ac4_optionalUserData _0b570ac4_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0b570ac4_optionalUserData){value}; }
static inline _s_0b570ac4_rteParameters _0b570ac4_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0b570ac4_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDeferredOperationJoin(_s_0b570ac4_rteContext rteContext, _s_0b570ac4_deferredOperation deferredOperation, _s_0b570ac4_optionalFile optionalFile, _s_0b570ac4_optionalLine optionalLine, _s_0b570ac4_optionalUserData optionalUserData, _s_0b570ac4_rteParameters rteParameters) {
  return redRteDeferredOperationJoin(rteContext.value, deferredOperation.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateProcedureRayTracing redRteCreateProcedureRayTracing
#define _7b5ae618_rteContext(value) value
#define _7b5ae618_deferredOperation(value) value
#define _7b5ae618_procedureCache(value) value
#define _7b5ae618_state(value) value
#define _7b5ae618_outProcedure(value) value
#define _7b5ae618_outStatuses(value) value
#define _7b5ae618_optionalFile(value) value
#define _7b5ae618_optionalLine(value) value
#define _7b5ae618_optionalUserData(value) value
#define _7b5ae618_rteParameters(value) value
#else
typedef struct _s_7b5ae618_rteContext { RedRteHandleContext value; } _s_7b5ae618_rteContext;
typedef struct _s_7b5ae618_deferredOperation { RedRteHandleDeferredOperation value; } _s_7b5ae618_deferredOperation;
typedef struct _s_7b5ae618_procedureCache { RedHandleProcedureCache value; } _s_7b5ae618_procedureCache;
typedef struct _s_7b5ae618_state { RedRteProcedureRayTracingState* value; } _s_7b5ae618_state;
typedef struct _s_7b5ae618_outProcedure { RedHandleProcedure* value; } _s_7b5ae618_outProcedure;
typedef struct _s_7b5ae618_outStatuses { RedStatuses* value; } _s_7b5ae618_outStatuses;
typedef struct _s_7b5ae618_optionalFile { char* value; } _s_7b5ae618_optionalFile;
typedef struct _s_7b5ae618_optionalLine { int value; } _s_7b5ae618_optionalLine;
typedef struct _s_7b5ae618_optionalUserData { void* value; } _s_7b5ae618_optionalUserData;
typedef struct _s_7b5ae618_rteParameters { void* value; } _s_7b5ae618_rteParameters;
static inline _s_7b5ae618_rteContext _7b5ae618_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_7b5ae618_rteContext){value}; }
static inline _s_7b5ae618_deferredOperation _7b5ae618_deferredOperation(RedRteHandleDeferredOperation value) { return REDGPU_NP_STRUCT_INIT(_s_7b5ae618_deferredOperation){value}; }
static inline _s_7b5ae618_procedureCache _7b5ae618_procedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_7b5ae618_procedureCache){value}; }
static inline _s_7b5ae618_state _7b5ae618_state(RedRteProcedureRayTracingState* value) { return REDGPU_NP_STRUCT_INIT(_s_7b5ae618_state){value}; }
static inline _s_7b5ae618_outProcedure _7b5ae618_outProcedure(RedHandleProcedure* value) { return REDGPU_NP_STRUCT_INIT(_s_7b5ae618_outProcedure){value}; }
static inline _s_7b5ae618_outStatuses _7b5ae618_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_7b5ae618_outStatuses){value}; }
static inline _s_7b5ae618_optionalFile _7b5ae618_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7b5ae618_optionalFile){value}; }
static inline _s_7b5ae618_optionalLine _7b5ae618_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7b5ae618_optionalLine){value}; }
static inline _s_7b5ae618_optionalUserData _7b5ae618_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7b5ae618_optionalUserData){value}; }
static inline _s_7b5ae618_rteParameters _7b5ae618_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7b5ae618_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateProcedureRayTracing(_s_7b5ae618_rteContext rteContext, _s_7b5ae618_deferredOperation deferredOperation, _s_7b5ae618_procedureCache procedureCache, _s_7b5ae618_state state, _s_7b5ae618_outProcedure outProcedure, _s_7b5ae618_outStatuses outStatuses, _s_7b5ae618_optionalFile optionalFile, _s_7b5ae618_optionalLine optionalLine, _s_7b5ae618_optionalUserData optionalUserData, _s_7b5ae618_rteParameters rteParameters) {
  return redRteCreateProcedureRayTracing(rteContext.value, deferredOperation.value, procedureCache.value, state.value, outProcedure.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteProcedureRayTracingGetGroupCaptureReplayHandles redRteProcedureRayTracingGetGroupCaptureReplayHandles
#define _c744c963_rteContext(value) value
#define _c744c963_procedureRayTracing(value) value
#define _c744c963_groupIndexFirst(value) value
#define _c744c963_groupIndexCount(value) value
#define _c744c963_dataBytesCount(value) value
#define _c744c963_data(value) value
#define _c744c963_optionalFile(value) value
#define _c744c963_optionalLine(value) value
#define _c744c963_optionalUserData(value) value
#define _c744c963_rteParameters(value) value
#else
typedef struct _s_c744c963_rteContext { RedRteHandleContext value; } _s_c744c963_rteContext;
typedef struct _s_c744c963_procedureRayTracing { RedHandleProcedure value; } _s_c744c963_procedureRayTracing;
typedef struct _s_c744c963_groupIndexFirst { unsigned value; } _s_c744c963_groupIndexFirst;
typedef struct _s_c744c963_groupIndexCount { unsigned value; } _s_c744c963_groupIndexCount;
typedef struct _s_c744c963_dataBytesCount { uint64_t value; } _s_c744c963_dataBytesCount;
typedef struct _s_c744c963_data { void* value; } _s_c744c963_data;
typedef struct _s_c744c963_optionalFile { char* value; } _s_c744c963_optionalFile;
typedef struct _s_c744c963_optionalLine { int value; } _s_c744c963_optionalLine;
typedef struct _s_c744c963_optionalUserData { void* value; } _s_c744c963_optionalUserData;
typedef struct _s_c744c963_rteParameters { void* value; } _s_c744c963_rteParameters;
static inline _s_c744c963_rteContext _c744c963_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_c744c963_rteContext){value}; }
static inline _s_c744c963_procedureRayTracing _c744c963_procedureRayTracing(RedHandleProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_c744c963_procedureRayTracing){value}; }
static inline _s_c744c963_groupIndexFirst _c744c963_groupIndexFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c744c963_groupIndexFirst){value}; }
static inline _s_c744c963_groupIndexCount _c744c963_groupIndexCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c744c963_groupIndexCount){value}; }
static inline _s_c744c963_dataBytesCount _c744c963_dataBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_c744c963_dataBytesCount){value}; }
static inline _s_c744c963_data _c744c963_data(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c744c963_data){value}; }
static inline _s_c744c963_optionalFile _c744c963_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c744c963_optionalFile){value}; }
static inline _s_c744c963_optionalLine _c744c963_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c744c963_optionalLine){value}; }
static inline _s_c744c963_optionalUserData _c744c963_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c744c963_optionalUserData){value}; }
static inline _s_c744c963_rteParameters _c744c963_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c744c963_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteProcedureRayTracingGetGroupCaptureReplayHandles(_s_c744c963_rteContext rteContext, _s_c744c963_procedureRayTracing procedureRayTracing, _s_c744c963_groupIndexFirst groupIndexFirst, _s_c744c963_groupIndexCount groupIndexCount, _s_c744c963_dataBytesCount dataBytesCount, _s_c744c963_data data, _s_c744c963_optionalFile optionalFile, _s_c744c963_optionalLine optionalLine, _s_c744c963_optionalUserData optionalUserData, _s_c744c963_rteParameters rteParameters) {
  return redRteProcedureRayTracingGetGroupCaptureReplayHandles(rteContext.value, procedureRayTracing.value, groupIndexFirst.value, groupIndexCount.value, dataBytesCount.value, data.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteProcedureRayTracingGetGroupStackBytesCount redRteProcedureRayTracingGetGroupStackBytesCount
#define _21b9ff50_rteContext(value) value
#define _21b9ff50_procedureRayTracing(value) value
#define _21b9ff50_groupIndex(value) value
#define _21b9ff50_groupStage(value) value
#define _21b9ff50_optionalFile(value) value
#define _21b9ff50_optionalLine(value) value
#define _21b9ff50_optionalUserData(value) value
#define _21b9ff50_rteParameters(value) value
#else
typedef struct _s_21b9ff50_rteContext { RedRteHandleContext value; } _s_21b9ff50_rteContext;
typedef struct _s_21b9ff50_procedureRayTracing { RedHandleProcedure value; } _s_21b9ff50_procedureRayTracing;
typedef struct _s_21b9ff50_groupIndex { unsigned value; } _s_21b9ff50_groupIndex;
typedef struct _s_21b9ff50_groupStage { RedRteProcedureRayTracingGroupStage value; } _s_21b9ff50_groupStage;
typedef struct _s_21b9ff50_optionalFile { char* value; } _s_21b9ff50_optionalFile;
typedef struct _s_21b9ff50_optionalLine { int value; } _s_21b9ff50_optionalLine;
typedef struct _s_21b9ff50_optionalUserData { void* value; } _s_21b9ff50_optionalUserData;
typedef struct _s_21b9ff50_rteParameters { void* value; } _s_21b9ff50_rteParameters;
static inline _s_21b9ff50_rteContext _21b9ff50_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_21b9ff50_rteContext){value}; }
static inline _s_21b9ff50_procedureRayTracing _21b9ff50_procedureRayTracing(RedHandleProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_21b9ff50_procedureRayTracing){value}; }
static inline _s_21b9ff50_groupIndex _21b9ff50_groupIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_21b9ff50_groupIndex){value}; }
static inline _s_21b9ff50_groupStage _21b9ff50_groupStage(RedRteProcedureRayTracingGroupStage value) { return REDGPU_NP_STRUCT_INIT(_s_21b9ff50_groupStage){value}; }
static inline _s_21b9ff50_optionalFile _21b9ff50_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_21b9ff50_optionalFile){value}; }
static inline _s_21b9ff50_optionalLine _21b9ff50_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_21b9ff50_optionalLine){value}; }
static inline _s_21b9ff50_optionalUserData _21b9ff50_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_21b9ff50_optionalUserData){value}; }
static inline _s_21b9ff50_rteParameters _21b9ff50_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_21b9ff50_rteParameters){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redRteProcedureRayTracingGetGroupStackBytesCount(_s_21b9ff50_rteContext rteContext, _s_21b9ff50_procedureRayTracing procedureRayTracing, _s_21b9ff50_groupIndex groupIndex, _s_21b9ff50_groupStage groupStage, _s_21b9ff50_optionalFile optionalFile, _s_21b9ff50_optionalLine optionalLine, _s_21b9ff50_optionalUserData optionalUserData, _s_21b9ff50_rteParameters rteParameters) {
  return redRteProcedureRayTracingGetGroupStackBytesCount(rteContext.value, procedureRayTracing.value, groupIndex.value, groupStage.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallProcedureRayTracing redRteCallProcedureRayTracing
#define _309e3803_calls(value) value
#define _309e3803_rteContext(value) value
#define _309e3803_shaderBindingTableRayGeneration(value) value
#define _309e3803_shaderBindingTableMiss(value) value
#define _309e3803_shaderBindingTableHit(value) value
#define _309e3803_shaderBindingTableCallable(value) value
#define _309e3803_threadsCountX(value) value
#define _309e3803_threadsCountY(value) value
#define _309e3803_threadsCountZ(value) value
#define _309e3803_optionalFile(value) value
#define _309e3803_optionalLine(value) value
#define _309e3803_optionalUserData(value) value
#define _309e3803_rteParameters(value) value
#else
typedef struct _s_309e3803_calls { RedHandleCalls value; } _s_309e3803_calls;
typedef struct _s_309e3803_rteContext { RedRteHandleContext value; } _s_309e3803_rteContext;
typedef struct _s_309e3803_shaderBindingTableRayGeneration { RedRteGpuAddressStrideAndRange* value; } _s_309e3803_shaderBindingTableRayGeneration;
typedef struct _s_309e3803_shaderBindingTableMiss { RedRteGpuAddressStrideAndRange* value; } _s_309e3803_shaderBindingTableMiss;
typedef struct _s_309e3803_shaderBindingTableHit { RedRteGpuAddressStrideAndRange* value; } _s_309e3803_shaderBindingTableHit;
typedef struct _s_309e3803_shaderBindingTableCallable { RedRteGpuAddressStrideAndRange* value; } _s_309e3803_shaderBindingTableCallable;
typedef struct _s_309e3803_threadsCountX { unsigned value; } _s_309e3803_threadsCountX;
typedef struct _s_309e3803_threadsCountY { unsigned value; } _s_309e3803_threadsCountY;
typedef struct _s_309e3803_threadsCountZ { unsigned value; } _s_309e3803_threadsCountZ;
typedef struct _s_309e3803_optionalFile { char* value; } _s_309e3803_optionalFile;
typedef struct _s_309e3803_optionalLine { int value; } _s_309e3803_optionalLine;
typedef struct _s_309e3803_optionalUserData { void* value; } _s_309e3803_optionalUserData;
typedef struct _s_309e3803_rteParameters { void* value; } _s_309e3803_rteParameters;
static inline _s_309e3803_calls _309e3803_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_calls){value}; }
static inline _s_309e3803_rteContext _309e3803_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_rteContext){value}; }
static inline _s_309e3803_shaderBindingTableRayGeneration _309e3803_shaderBindingTableRayGeneration(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_shaderBindingTableRayGeneration){value}; }
static inline _s_309e3803_shaderBindingTableMiss _309e3803_shaderBindingTableMiss(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_shaderBindingTableMiss){value}; }
static inline _s_309e3803_shaderBindingTableHit _309e3803_shaderBindingTableHit(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_shaderBindingTableHit){value}; }
static inline _s_309e3803_shaderBindingTableCallable _309e3803_shaderBindingTableCallable(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_shaderBindingTableCallable){value}; }
static inline _s_309e3803_threadsCountX _309e3803_threadsCountX(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_threadsCountX){value}; }
static inline _s_309e3803_threadsCountY _309e3803_threadsCountY(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_threadsCountY){value}; }
static inline _s_309e3803_threadsCountZ _309e3803_threadsCountZ(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_threadsCountZ){value}; }
static inline _s_309e3803_optionalFile _309e3803_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_optionalFile){value}; }
static inline _s_309e3803_optionalLine _309e3803_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_optionalLine){value}; }
static inline _s_309e3803_optionalUserData _309e3803_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_optionalUserData){value}; }
static inline _s_309e3803_rteParameters _309e3803_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_309e3803_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallProcedureRayTracing(_s_309e3803_calls calls, _s_309e3803_rteContext rteContext, _s_309e3803_shaderBindingTableRayGeneration shaderBindingTableRayGeneration, _s_309e3803_shaderBindingTableMiss shaderBindingTableMiss, _s_309e3803_shaderBindingTableHit shaderBindingTableHit, _s_309e3803_shaderBindingTableCallable shaderBindingTableCallable, _s_309e3803_threadsCountX threadsCountX, _s_309e3803_threadsCountY threadsCountY, _s_309e3803_threadsCountZ threadsCountZ, _s_309e3803_optionalFile optionalFile, _s_309e3803_optionalLine optionalLine, _s_309e3803_optionalUserData optionalUserData, _s_309e3803_rteParameters rteParameters) {
  return redRteCallProcedureRayTracing(calls.value, rteContext.value, shaderBindingTableRayGeneration.value, shaderBindingTableMiss.value, shaderBindingTableHit.value, shaderBindingTableCallable.value, threadsCountX.value, threadsCountY.value, threadsCountZ.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallProcedureIndirect redRteCallProcedureIndirect
#define _bee0588e_calls(value) value
#define _bee0588e_rteContext(value) value
#define _bee0588e_array(value) value
#define _bee0588e_arrayBytesFirst(value) value
#define _bee0588e_count(value) value
#define _bee0588e_bytesStride(value) value
#define _bee0588e_optionalFile(value) value
#define _bee0588e_optionalLine(value) value
#define _bee0588e_optionalUserData(value) value
#define _bee0588e_rteParameters(value) value
#else
typedef struct _s_bee0588e_calls { RedHandleCalls value; } _s_bee0588e_calls;
typedef struct _s_bee0588e_rteContext { RedRteHandleContext value; } _s_bee0588e_rteContext;
typedef struct _s_bee0588e_array { RedHandleArray value; } _s_bee0588e_array;
typedef struct _s_bee0588e_arrayBytesFirst { uint64_t value; } _s_bee0588e_arrayBytesFirst;
typedef struct _s_bee0588e_count { unsigned value; } _s_bee0588e_count;
typedef struct _s_bee0588e_bytesStride { unsigned value; } _s_bee0588e_bytesStride;
typedef struct _s_bee0588e_optionalFile { char* value; } _s_bee0588e_optionalFile;
typedef struct _s_bee0588e_optionalLine { int value; } _s_bee0588e_optionalLine;
typedef struct _s_bee0588e_optionalUserData { void* value; } _s_bee0588e_optionalUserData;
typedef struct _s_bee0588e_rteParameters { void* value; } _s_bee0588e_rteParameters;
static inline _s_bee0588e_calls _bee0588e_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_bee0588e_calls){value}; }
static inline _s_bee0588e_rteContext _bee0588e_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_bee0588e_rteContext){value}; }
static inline _s_bee0588e_array _bee0588e_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_bee0588e_array){value}; }
static inline _s_bee0588e_arrayBytesFirst _bee0588e_arrayBytesFirst(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_bee0588e_arrayBytesFirst){value}; }
static inline _s_bee0588e_count _bee0588e_count(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bee0588e_count){value}; }
static inline _s_bee0588e_bytesStride _bee0588e_bytesStride(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bee0588e_bytesStride){value}; }
static inline _s_bee0588e_optionalFile _bee0588e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bee0588e_optionalFile){value}; }
static inline _s_bee0588e_optionalLine _bee0588e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bee0588e_optionalLine){value}; }
static inline _s_bee0588e_optionalUserData _bee0588e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bee0588e_optionalUserData){value}; }
static inline _s_bee0588e_rteParameters _bee0588e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bee0588e_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallProcedureIndirect(_s_bee0588e_calls calls, _s_bee0588e_rteContext rteContext, _s_bee0588e_array array, _s_bee0588e_arrayBytesFirst arrayBytesFirst, _s_bee0588e_count count, _s_bee0588e_bytesStride bytesStride, _s_bee0588e_optionalFile optionalFile, _s_bee0588e_optionalLine optionalLine, _s_bee0588e_optionalUserData optionalUserData, _s_bee0588e_rteParameters rteParameters) {
  return redRteCallProcedureIndirect(calls.value, rteContext.value, array.value, arrayBytesFirst.value, count.value, bytesStride.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallProcedureIndexedIndirect redRteCallProcedureIndexedIndirect
#define _b92d986c_calls(value) value
#define _b92d986c_rteContext(value) value
#define _b92d986c_array(value) value
#define _b92d986c_arrayBytesFirst(value) value
#define _b92d986c_count(value) value
#define _b92d986c_bytesStride(value) value
#define _b92d986c_optionalFile(value) value
#define _b92d986c_optionalLine(value) value
#define _b92d986c_optionalUserData(value) value
#define _b92d986c_rteParameters(value) value
#else
typedef struct _s_b92d986c_calls { RedHandleCalls value; } _s_b92d986c_calls;
typedef struct _s_b92d986c_rteContext { RedRteHandleContext value; } _s_b92d986c_rteContext;
typedef struct _s_b92d986c_array { RedHandleArray value; } _s_b92d986c_array;
typedef struct _s_b92d986c_arrayBytesFirst { uint64_t value; } _s_b92d986c_arrayBytesFirst;
typedef struct _s_b92d986c_count { unsigned value; } _s_b92d986c_count;
typedef struct _s_b92d986c_bytesStride { unsigned value; } _s_b92d986c_bytesStride;
typedef struct _s_b92d986c_optionalFile { char* value; } _s_b92d986c_optionalFile;
typedef struct _s_b92d986c_optionalLine { int value; } _s_b92d986c_optionalLine;
typedef struct _s_b92d986c_optionalUserData { void* value; } _s_b92d986c_optionalUserData;
typedef struct _s_b92d986c_rteParameters { void* value; } _s_b92d986c_rteParameters;
static inline _s_b92d986c_calls _b92d986c_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_b92d986c_calls){value}; }
static inline _s_b92d986c_rteContext _b92d986c_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_b92d986c_rteContext){value}; }
static inline _s_b92d986c_array _b92d986c_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_b92d986c_array){value}; }
static inline _s_b92d986c_arrayBytesFirst _b92d986c_arrayBytesFirst(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_b92d986c_arrayBytesFirst){value}; }
static inline _s_b92d986c_count _b92d986c_count(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b92d986c_count){value}; }
static inline _s_b92d986c_bytesStride _b92d986c_bytesStride(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b92d986c_bytesStride){value}; }
static inline _s_b92d986c_optionalFile _b92d986c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b92d986c_optionalFile){value}; }
static inline _s_b92d986c_optionalLine _b92d986c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b92d986c_optionalLine){value}; }
static inline _s_b92d986c_optionalUserData _b92d986c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b92d986c_optionalUserData){value}; }
static inline _s_b92d986c_rteParameters _b92d986c_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b92d986c_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallProcedureIndexedIndirect(_s_b92d986c_calls calls, _s_b92d986c_rteContext rteContext, _s_b92d986c_array array, _s_b92d986c_arrayBytesFirst arrayBytesFirst, _s_b92d986c_count count, _s_b92d986c_bytesStride bytesStride, _s_b92d986c_optionalFile optionalFile, _s_b92d986c_optionalLine optionalLine, _s_b92d986c_optionalUserData optionalUserData, _s_b92d986c_rteParameters rteParameters) {
  return redRteCallProcedureIndexedIndirect(calls.value, rteContext.value, array.value, arrayBytesFirst.value, count.value, bytesStride.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallProcedureComputeIndirect redRteCallProcedureComputeIndirect
#define _73c9536a_calls(value) value
#define _73c9536a_rteContext(value) value
#define _73c9536a_array(value) value
#define _73c9536a_arrayBytesFirst(value) value
#define _73c9536a_optionalFile(value) value
#define _73c9536a_optionalLine(value) value
#define _73c9536a_optionalUserData(value) value
#define _73c9536a_rteParameters(value) value
#else
typedef struct _s_73c9536a_calls { RedHandleCalls value; } _s_73c9536a_calls;
typedef struct _s_73c9536a_rteContext { RedRteHandleContext value; } _s_73c9536a_rteContext;
typedef struct _s_73c9536a_array { RedHandleArray value; } _s_73c9536a_array;
typedef struct _s_73c9536a_arrayBytesFirst { uint64_t value; } _s_73c9536a_arrayBytesFirst;
typedef struct _s_73c9536a_optionalFile { char* value; } _s_73c9536a_optionalFile;
typedef struct _s_73c9536a_optionalLine { int value; } _s_73c9536a_optionalLine;
typedef struct _s_73c9536a_optionalUserData { void* value; } _s_73c9536a_optionalUserData;
typedef struct _s_73c9536a_rteParameters { void* value; } _s_73c9536a_rteParameters;
static inline _s_73c9536a_calls _73c9536a_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_73c9536a_calls){value}; }
static inline _s_73c9536a_rteContext _73c9536a_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_73c9536a_rteContext){value}; }
static inline _s_73c9536a_array _73c9536a_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_73c9536a_array){value}; }
static inline _s_73c9536a_arrayBytesFirst _73c9536a_arrayBytesFirst(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_73c9536a_arrayBytesFirst){value}; }
static inline _s_73c9536a_optionalFile _73c9536a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_73c9536a_optionalFile){value}; }
static inline _s_73c9536a_optionalLine _73c9536a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_73c9536a_optionalLine){value}; }
static inline _s_73c9536a_optionalUserData _73c9536a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_73c9536a_optionalUserData){value}; }
static inline _s_73c9536a_rteParameters _73c9536a_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_73c9536a_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallProcedureComputeIndirect(_s_73c9536a_calls calls, _s_73c9536a_rteContext rteContext, _s_73c9536a_array array, _s_73c9536a_arrayBytesFirst arrayBytesFirst, _s_73c9536a_optionalFile optionalFile, _s_73c9536a_optionalLine optionalLine, _s_73c9536a_optionalUserData optionalUserData, _s_73c9536a_rteParameters rteParameters) {
  return redRteCallProcedureComputeIndirect(calls.value, rteContext.value, array.value, arrayBytesFirst.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallProcedureRayTracingIndirect redRteCallProcedureRayTracingIndirect
#define _81bb4a78_calls(value) value
#define _81bb4a78_rteContext(value) value
#define _81bb4a78_shaderBindingTableRayGeneration(value) value
#define _81bb4a78_shaderBindingTableMiss(value) value
#define _81bb4a78_shaderBindingTableHit(value) value
#define _81bb4a78_shaderBindingTableCallable(value) value
#define _81bb4a78_gpuAddress(value) value
#define _81bb4a78_optionalFile(value) value
#define _81bb4a78_optionalLine(value) value
#define _81bb4a78_optionalUserData(value) value
#define _81bb4a78_rteParameters(value) value
#else
typedef struct _s_81bb4a78_calls { RedHandleCalls value; } _s_81bb4a78_calls;
typedef struct _s_81bb4a78_rteContext { RedRteHandleContext value; } _s_81bb4a78_rteContext;
typedef struct _s_81bb4a78_shaderBindingTableRayGeneration { RedRteGpuAddressStrideAndRange* value; } _s_81bb4a78_shaderBindingTableRayGeneration;
typedef struct _s_81bb4a78_shaderBindingTableMiss { RedRteGpuAddressStrideAndRange* value; } _s_81bb4a78_shaderBindingTableMiss;
typedef struct _s_81bb4a78_shaderBindingTableHit { RedRteGpuAddressStrideAndRange* value; } _s_81bb4a78_shaderBindingTableHit;
typedef struct _s_81bb4a78_shaderBindingTableCallable { RedRteGpuAddressStrideAndRange* value; } _s_81bb4a78_shaderBindingTableCallable;
typedef struct _s_81bb4a78_gpuAddress { uint64_t value; } _s_81bb4a78_gpuAddress;
typedef struct _s_81bb4a78_optionalFile { char* value; } _s_81bb4a78_optionalFile;
typedef struct _s_81bb4a78_optionalLine { int value; } _s_81bb4a78_optionalLine;
typedef struct _s_81bb4a78_optionalUserData { void* value; } _s_81bb4a78_optionalUserData;
typedef struct _s_81bb4a78_rteParameters { void* value; } _s_81bb4a78_rteParameters;
static inline _s_81bb4a78_calls _81bb4a78_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_81bb4a78_calls){value}; }
static inline _s_81bb4a78_rteContext _81bb4a78_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_81bb4a78_rteContext){value}; }
static inline _s_81bb4a78_shaderBindingTableRayGeneration _81bb4a78_shaderBindingTableRayGeneration(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_81bb4a78_shaderBindingTableRayGeneration){value}; }
static inline _s_81bb4a78_shaderBindingTableMiss _81bb4a78_shaderBindingTableMiss(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_81bb4a78_shaderBindingTableMiss){value}; }
static inline _s_81bb4a78_shaderBindingTableHit _81bb4a78_shaderBindingTableHit(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_81bb4a78_shaderBindingTableHit){value}; }
static inline _s_81bb4a78_shaderBindingTableCallable _81bb4a78_shaderBindingTableCallable(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_81bb4a78_shaderBindingTableCallable){value}; }
static inline _s_81bb4a78_gpuAddress _81bb4a78_gpuAddress(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_81bb4a78_gpuAddress){value}; }
static inline _s_81bb4a78_optionalFile _81bb4a78_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_81bb4a78_optionalFile){value}; }
static inline _s_81bb4a78_optionalLine _81bb4a78_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_81bb4a78_optionalLine){value}; }
static inline _s_81bb4a78_optionalUserData _81bb4a78_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_81bb4a78_optionalUserData){value}; }
static inline _s_81bb4a78_rteParameters _81bb4a78_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_81bb4a78_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallProcedureRayTracingIndirect(_s_81bb4a78_calls calls, _s_81bb4a78_rteContext rteContext, _s_81bb4a78_shaderBindingTableRayGeneration shaderBindingTableRayGeneration, _s_81bb4a78_shaderBindingTableMiss shaderBindingTableMiss, _s_81bb4a78_shaderBindingTableHit shaderBindingTableHit, _s_81bb4a78_shaderBindingTableCallable shaderBindingTableCallable, _s_81bb4a78_gpuAddress gpuAddress, _s_81bb4a78_optionalFile optionalFile, _s_81bb4a78_optionalLine optionalLine, _s_81bb4a78_optionalUserData optionalUserData, _s_81bb4a78_rteParameters rteParameters) {
  return redRteCallProcedureRayTracingIndirect(calls.value, rteContext.value, shaderBindingTableRayGeneration.value, shaderBindingTableMiss.value, shaderBindingTableHit.value, shaderBindingTableCallable.value, gpuAddress.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallSetProcedureRayTracingStackBytesCount redRteCallSetProcedureRayTracingStackBytesCount
#define _af0e50cd_calls(value) value
#define _af0e50cd_rteContext(value) value
#define _af0e50cd_stackBytesCount(value) value
#define _af0e50cd_optionalFile(value) value
#define _af0e50cd_optionalLine(value) value
#define _af0e50cd_optionalUserData(value) value
#define _af0e50cd_rteParameters(value) value
#else
typedef struct _s_af0e50cd_calls { RedHandleCalls value; } _s_af0e50cd_calls;
typedef struct _s_af0e50cd_rteContext { RedRteHandleContext value; } _s_af0e50cd_rteContext;
typedef struct _s_af0e50cd_stackBytesCount { unsigned value; } _s_af0e50cd_stackBytesCount;
typedef struct _s_af0e50cd_optionalFile { char* value; } _s_af0e50cd_optionalFile;
typedef struct _s_af0e50cd_optionalLine { int value; } _s_af0e50cd_optionalLine;
typedef struct _s_af0e50cd_optionalUserData { void* value; } _s_af0e50cd_optionalUserData;
typedef struct _s_af0e50cd_rteParameters { void* value; } _s_af0e50cd_rteParameters;
static inline _s_af0e50cd_calls _af0e50cd_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_af0e50cd_calls){value}; }
static inline _s_af0e50cd_rteContext _af0e50cd_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_af0e50cd_rteContext){value}; }
static inline _s_af0e50cd_stackBytesCount _af0e50cd_stackBytesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_af0e50cd_stackBytesCount){value}; }
static inline _s_af0e50cd_optionalFile _af0e50cd_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_af0e50cd_optionalFile){value}; }
static inline _s_af0e50cd_optionalLine _af0e50cd_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_af0e50cd_optionalLine){value}; }
static inline _s_af0e50cd_optionalUserData _af0e50cd_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_af0e50cd_optionalUserData){value}; }
static inline _s_af0e50cd_rteParameters _af0e50cd_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_af0e50cd_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallSetProcedureRayTracingStackBytesCount(_s_af0e50cd_calls calls, _s_af0e50cd_rteContext rteContext, _s_af0e50cd_stackBytesCount stackBytesCount, _s_af0e50cd_optionalFile optionalFile, _s_af0e50cd_optionalLine optionalLine, _s_af0e50cd_optionalUserData optionalUserData, _s_af0e50cd_rteParameters rteParameters) {
  return redRteCallSetProcedureRayTracingStackBytesCount(calls.value, rteContext.value, stackBytesCount.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateHelperShaderBindingTable redRteCreateHelperShaderBindingTable
#define _fb109fe0_rteContext(value) value
#define _fb109fe0_rteHandleHelperAllocator(value) value
#define _fb109fe0_queueFamilyIndex(value) value
#define _fb109fe0_outHelperShaderBindingTable(value) value
#define _fb109fe0_outStatuses(value) value
#define _fb109fe0_optionalFile(value) value
#define _fb109fe0_optionalLine(value) value
#define _fb109fe0_optionalUserData(value) value
#define _fb109fe0_rteParameters(value) value
#else
typedef struct _s_fb109fe0_rteContext { RedRteHandleContext value; } _s_fb109fe0_rteContext;
typedef struct _s_fb109fe0_rteHandleHelperAllocator { void* value; } _s_fb109fe0_rteHandleHelperAllocator;
typedef struct _s_fb109fe0_queueFamilyIndex { unsigned value; } _s_fb109fe0_queueFamilyIndex;
typedef struct _s_fb109fe0_outHelperShaderBindingTable { RedRteHandleHelperShaderBindingTable* value; } _s_fb109fe0_outHelperShaderBindingTable;
typedef struct _s_fb109fe0_outStatuses { RedStatuses* value; } _s_fb109fe0_outStatuses;
typedef struct _s_fb109fe0_optionalFile { char* value; } _s_fb109fe0_optionalFile;
typedef struct _s_fb109fe0_optionalLine { int value; } _s_fb109fe0_optionalLine;
typedef struct _s_fb109fe0_optionalUserData { void* value; } _s_fb109fe0_optionalUserData;
typedef struct _s_fb109fe0_rteParameters { void* value; } _s_fb109fe0_rteParameters;
static inline _s_fb109fe0_rteContext _fb109fe0_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_fb109fe0_rteContext){value}; }
static inline _s_fb109fe0_rteHandleHelperAllocator _fb109fe0_rteHandleHelperAllocator(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fb109fe0_rteHandleHelperAllocator){value}; }
static inline _s_fb109fe0_queueFamilyIndex _fb109fe0_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_fb109fe0_queueFamilyIndex){value}; }
static inline _s_fb109fe0_outHelperShaderBindingTable _fb109fe0_outHelperShaderBindingTable(RedRteHandleHelperShaderBindingTable* value) { return REDGPU_NP_STRUCT_INIT(_s_fb109fe0_outHelperShaderBindingTable){value}; }
static inline _s_fb109fe0_outStatuses _fb109fe0_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_fb109fe0_outStatuses){value}; }
static inline _s_fb109fe0_optionalFile _fb109fe0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fb109fe0_optionalFile){value}; }
static inline _s_fb109fe0_optionalLine _fb109fe0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fb109fe0_optionalLine){value}; }
static inline _s_fb109fe0_optionalUserData _fb109fe0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fb109fe0_optionalUserData){value}; }
static inline _s_fb109fe0_rteParameters _fb109fe0_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fb109fe0_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateHelperShaderBindingTable(_s_fb109fe0_rteContext rteContext, _s_fb109fe0_rteHandleHelperAllocator rteHandleHelperAllocator, _s_fb109fe0_queueFamilyIndex queueFamilyIndex, _s_fb109fe0_outHelperShaderBindingTable outHelperShaderBindingTable, _s_fb109fe0_outStatuses outStatuses, _s_fb109fe0_optionalFile optionalFile, _s_fb109fe0_optionalLine optionalLine, _s_fb109fe0_optionalUserData optionalUserData, _s_fb109fe0_rteParameters rteParameters) {
  return redRteCreateHelperShaderBindingTable(rteContext.value, rteHandleHelperAllocator.value, queueFamilyIndex.value, outHelperShaderBindingTable.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyHelperShaderBindingTable redRteDestroyHelperShaderBindingTable
#define _b5868170_helperShaderBindingTable(value) value
#define _b5868170_optionalFile(value) value
#define _b5868170_optionalLine(value) value
#define _b5868170_optionalUserData(value) value
#define _b5868170_rteParameters(value) value
#else
typedef struct _s_b5868170_helperShaderBindingTable { RedRteHandleHelperShaderBindingTable value; } _s_b5868170_helperShaderBindingTable;
typedef struct _s_b5868170_optionalFile { char* value; } _s_b5868170_optionalFile;
typedef struct _s_b5868170_optionalLine { int value; } _s_b5868170_optionalLine;
typedef struct _s_b5868170_optionalUserData { void* value; } _s_b5868170_optionalUserData;
typedef struct _s_b5868170_rteParameters { void* value; } _s_b5868170_rteParameters;
static inline _s_b5868170_helperShaderBindingTable _b5868170_helperShaderBindingTable(RedRteHandleHelperShaderBindingTable value) { return REDGPU_NP_STRUCT_INIT(_s_b5868170_helperShaderBindingTable){value}; }
static inline _s_b5868170_optionalFile _b5868170_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b5868170_optionalFile){value}; }
static inline _s_b5868170_optionalLine _b5868170_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b5868170_optionalLine){value}; }
static inline _s_b5868170_optionalUserData _b5868170_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b5868170_optionalUserData){value}; }
static inline _s_b5868170_rteParameters _b5868170_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b5868170_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyHelperShaderBindingTable(_s_b5868170_helperShaderBindingTable helperShaderBindingTable, _s_b5868170_optionalFile optionalFile, _s_b5868170_optionalLine optionalLine, _s_b5868170_optionalUserData optionalUserData, _s_b5868170_rteParameters rteParameters) {
  return redRteDestroyHelperShaderBindingTable(helperShaderBindingTable.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperShaderBindingTableCreate redRteHelperShaderBindingTableCreate
#define _6636c89d_helperShaderBindingTable(value) value
#define _6636c89d_procedureRayTracing(value) value
#define _6636c89d_procedureRayTracingState(value) value
#define _6636c89d_optionalFile(value) value
#define _6636c89d_optionalLine(value) value
#define _6636c89d_optionalUserData(value) value
#define _6636c89d_rteParameters(value) value
#else
typedef struct _s_6636c89d_helperShaderBindingTable { RedRteHandleHelperShaderBindingTable value; } _s_6636c89d_helperShaderBindingTable;
typedef struct _s_6636c89d_procedureRayTracing { RedHandleProcedure value; } _s_6636c89d_procedureRayTracing;
typedef struct _s_6636c89d_procedureRayTracingState { RedRteProcedureRayTracingState* value; } _s_6636c89d_procedureRayTracingState;
typedef struct _s_6636c89d_optionalFile { char* value; } _s_6636c89d_optionalFile;
typedef struct _s_6636c89d_optionalLine { int value; } _s_6636c89d_optionalLine;
typedef struct _s_6636c89d_optionalUserData { void* value; } _s_6636c89d_optionalUserData;
typedef struct _s_6636c89d_rteParameters { void* value; } _s_6636c89d_rteParameters;
static inline _s_6636c89d_helperShaderBindingTable _6636c89d_helperShaderBindingTable(RedRteHandleHelperShaderBindingTable value) { return REDGPU_NP_STRUCT_INIT(_s_6636c89d_helperShaderBindingTable){value}; }
static inline _s_6636c89d_procedureRayTracing _6636c89d_procedureRayTracing(RedHandleProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_6636c89d_procedureRayTracing){value}; }
static inline _s_6636c89d_procedureRayTracingState _6636c89d_procedureRayTracingState(RedRteProcedureRayTracingState* value) { return REDGPU_NP_STRUCT_INIT(_s_6636c89d_procedureRayTracingState){value}; }
static inline _s_6636c89d_optionalFile _6636c89d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6636c89d_optionalFile){value}; }
static inline _s_6636c89d_optionalLine _6636c89d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6636c89d_optionalLine){value}; }
static inline _s_6636c89d_optionalUserData _6636c89d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6636c89d_optionalUserData){value}; }
static inline _s_6636c89d_rteParameters _6636c89d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6636c89d_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperShaderBindingTableCreate(_s_6636c89d_helperShaderBindingTable helperShaderBindingTable, _s_6636c89d_procedureRayTracing procedureRayTracing, _s_6636c89d_procedureRayTracingState procedureRayTracingState, _s_6636c89d_optionalFile optionalFile, _s_6636c89d_optionalLine optionalLine, _s_6636c89d_optionalUserData optionalUserData, _s_6636c89d_rteParameters rteParameters) {
  return redRteHelperShaderBindingTableCreate(helperShaderBindingTable.value, procedureRayTracing.value, procedureRayTracingState.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperShaderBindingTableGetGpuAddressStrideAndRange redRteHelperShaderBindingTableGetGpuAddressStrideAndRange
#define _d62b575c_helperShaderBindingTable(value) value
#define _d62b575c_outShaderBindingTableRayGeneration(value) value
#define _d62b575c_outShaderBindingTableMiss(value) value
#define _d62b575c_outShaderBindingTableHit(value) value
#define _d62b575c_outShaderBindingTableCallable(value) value
#define _d62b575c_optionalFile(value) value
#define _d62b575c_optionalLine(value) value
#define _d62b575c_optionalUserData(value) value
#define _d62b575c_rteParameters(value) value
#else
typedef struct _s_d62b575c_helperShaderBindingTable { RedRteHandleHelperShaderBindingTable value; } _s_d62b575c_helperShaderBindingTable;
typedef struct _s_d62b575c_outShaderBindingTableRayGeneration { RedRteGpuAddressStrideAndRange* value; } _s_d62b575c_outShaderBindingTableRayGeneration;
typedef struct _s_d62b575c_outShaderBindingTableMiss { RedRteGpuAddressStrideAndRange* value; } _s_d62b575c_outShaderBindingTableMiss;
typedef struct _s_d62b575c_outShaderBindingTableHit { RedRteGpuAddressStrideAndRange* value; } _s_d62b575c_outShaderBindingTableHit;
typedef struct _s_d62b575c_outShaderBindingTableCallable { RedRteGpuAddressStrideAndRange* value; } _s_d62b575c_outShaderBindingTableCallable;
typedef struct _s_d62b575c_optionalFile { char* value; } _s_d62b575c_optionalFile;
typedef struct _s_d62b575c_optionalLine { int value; } _s_d62b575c_optionalLine;
typedef struct _s_d62b575c_optionalUserData { void* value; } _s_d62b575c_optionalUserData;
typedef struct _s_d62b575c_rteParameters { void* value; } _s_d62b575c_rteParameters;
static inline _s_d62b575c_helperShaderBindingTable _d62b575c_helperShaderBindingTable(RedRteHandleHelperShaderBindingTable value) { return REDGPU_NP_STRUCT_INIT(_s_d62b575c_helperShaderBindingTable){value}; }
static inline _s_d62b575c_outShaderBindingTableRayGeneration _d62b575c_outShaderBindingTableRayGeneration(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_d62b575c_outShaderBindingTableRayGeneration){value}; }
static inline _s_d62b575c_outShaderBindingTableMiss _d62b575c_outShaderBindingTableMiss(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_d62b575c_outShaderBindingTableMiss){value}; }
static inline _s_d62b575c_outShaderBindingTableHit _d62b575c_outShaderBindingTableHit(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_d62b575c_outShaderBindingTableHit){value}; }
static inline _s_d62b575c_outShaderBindingTableCallable _d62b575c_outShaderBindingTableCallable(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_d62b575c_outShaderBindingTableCallable){value}; }
static inline _s_d62b575c_optionalFile _d62b575c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d62b575c_optionalFile){value}; }
static inline _s_d62b575c_optionalLine _d62b575c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d62b575c_optionalLine){value}; }
static inline _s_d62b575c_optionalUserData _d62b575c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d62b575c_optionalUserData){value}; }
static inline _s_d62b575c_rteParameters _d62b575c_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d62b575c_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperShaderBindingTableGetGpuAddressStrideAndRange(_s_d62b575c_helperShaderBindingTable helperShaderBindingTable, _s_d62b575c_outShaderBindingTableRayGeneration outShaderBindingTableRayGeneration, _s_d62b575c_outShaderBindingTableMiss outShaderBindingTableMiss, _s_d62b575c_outShaderBindingTableHit outShaderBindingTableHit, _s_d62b575c_outShaderBindingTableCallable outShaderBindingTableCallable, _s_d62b575c_optionalFile optionalFile, _s_d62b575c_optionalLine optionalLine, _s_d62b575c_optionalUserData optionalUserData, _s_d62b575c_rteParameters rteParameters) {
  return redRteHelperShaderBindingTableGetGpuAddressStrideAndRange(helperShaderBindingTable.value, outShaderBindingTableRayGeneration.value, outShaderBindingTableMiss.value, outShaderBindingTableHit.value, outShaderBindingTableCallable.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteGetInstanceProcAddr redRteGetInstanceProcAddr
#define _13b53647_optionalFile(value) value
#define _13b53647_optionalLine(value) value
#define _13b53647_optionalUserData(value) value
#define _13b53647_rteParameters(value) value
#else
typedef struct _s_13b53647_optionalFile { char* value; } _s_13b53647_optionalFile;
typedef struct _s_13b53647_optionalLine { int value; } _s_13b53647_optionalLine;
typedef struct _s_13b53647_optionalUserData { void* value; } _s_13b53647_optionalUserData;
typedef struct _s_13b53647_rteParameters { void* value; } _s_13b53647_rteParameters;
static inline _s_13b53647_optionalFile _13b53647_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_13b53647_optionalFile){value}; }
static inline _s_13b53647_optionalLine _13b53647_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_13b53647_optionalLine){value}; }
static inline _s_13b53647_optionalUserData _13b53647_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_13b53647_optionalUserData){value}; }
static inline _s_13b53647_rteParameters _13b53647_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_13b53647_rteParameters){value}; }
REDGPU_NP_DECLSPEC void* REDGPU_NP_API np_redRteGetInstanceProcAddr(_s_13b53647_optionalFile optionalFile, _s_13b53647_optionalLine optionalLine, _s_13b53647_optionalUserData optionalUserData, _s_13b53647_rteParameters rteParameters) {
  return redRteGetInstanceProcAddr(optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateContextFromRteContext redRteCreateContextFromRteContext
#define _6196f22b_rteContext(value) value
#define _6196f22b_malloc(value) value
#define _6196f22b_free(value) value
#define _6196f22b_optionalMallocTagged(value) value
#define _6196f22b_optionalFreeTagged(value) value
#define _6196f22b_debugCallback(value) value
#define _6196f22b_sdkVersion(value) value
#define _6196f22b_sdkExtensionsCount(value) value
#define _6196f22b_sdkExtensions(value) value
#define _6196f22b_optionalProgramName(value) value
#define _6196f22b_optionalProgramVersion(value) value
#define _6196f22b_optionalEngineName(value) value
#define _6196f22b_optionalEngineVersion(value) value
#define _6196f22b_optionalSettings(value) value
#define _6196f22b_outContext(value) value
#define _6196f22b_outStatuses(value) value
#define _6196f22b_optionalFile(value) value
#define _6196f22b_optionalLine(value) value
#define _6196f22b_optionalUserData(value) value
#define _6196f22b_rteParameters(value) value
#else
typedef struct _s_6196f22b_rteContext { RedRteHandleContext value; } _s_6196f22b_rteContext;
typedef struct _s_6196f22b_malloc { RedTypeProcedureMalloc value; } _s_6196f22b_malloc;
typedef struct _s_6196f22b_free { RedTypeProcedureFree value; } _s_6196f22b_free;
typedef struct _s_6196f22b_optionalMallocTagged { RedTypeProcedureMallocTagged value; } _s_6196f22b_optionalMallocTagged;
typedef struct _s_6196f22b_optionalFreeTagged { RedTypeProcedureFreeTagged value; } _s_6196f22b_optionalFreeTagged;
typedef struct _s_6196f22b_debugCallback { RedTypeProcedureDebugCallback value; } _s_6196f22b_debugCallback;
typedef struct _s_6196f22b_sdkVersion { RedSdkVersion value; } _s_6196f22b_sdkVersion;
typedef struct _s_6196f22b_sdkExtensionsCount { unsigned value; } _s_6196f22b_sdkExtensionsCount;
typedef struct _s_6196f22b_sdkExtensions { unsigned* value; } _s_6196f22b_sdkExtensions;
typedef struct _s_6196f22b_optionalProgramName { char* value; } _s_6196f22b_optionalProgramName;
typedef struct _s_6196f22b_optionalProgramVersion { unsigned value; } _s_6196f22b_optionalProgramVersion;
typedef struct _s_6196f22b_optionalEngineName { char* value; } _s_6196f22b_optionalEngineName;
typedef struct _s_6196f22b_optionalEngineVersion { unsigned value; } _s_6196f22b_optionalEngineVersion;
typedef struct _s_6196f22b_optionalSettings { void* value; } _s_6196f22b_optionalSettings;
typedef struct _s_6196f22b_outContext { RedContext* value; } _s_6196f22b_outContext;
typedef struct _s_6196f22b_outStatuses { RedStatuses* value; } _s_6196f22b_outStatuses;
typedef struct _s_6196f22b_optionalFile { char* value; } _s_6196f22b_optionalFile;
typedef struct _s_6196f22b_optionalLine { int value; } _s_6196f22b_optionalLine;
typedef struct _s_6196f22b_optionalUserData { void* value; } _s_6196f22b_optionalUserData;
typedef struct _s_6196f22b_rteParameters { void* value; } _s_6196f22b_rteParameters;
static inline _s_6196f22b_rteContext _6196f22b_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_rteContext){value}; }
static inline _s_6196f22b_malloc _6196f22b_malloc(RedTypeProcedureMalloc value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_malloc){value}; }
static inline _s_6196f22b_free _6196f22b_free(RedTypeProcedureFree value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_free){value}; }
static inline _s_6196f22b_optionalMallocTagged _6196f22b_optionalMallocTagged(RedTypeProcedureMallocTagged value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_optionalMallocTagged){value}; }
static inline _s_6196f22b_optionalFreeTagged _6196f22b_optionalFreeTagged(RedTypeProcedureFreeTagged value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_optionalFreeTagged){value}; }
static inline _s_6196f22b_debugCallback _6196f22b_debugCallback(RedTypeProcedureDebugCallback value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_debugCallback){value}; }
static inline _s_6196f22b_sdkVersion _6196f22b_sdkVersion(RedSdkVersion value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_sdkVersion){value}; }
static inline _s_6196f22b_sdkExtensionsCount _6196f22b_sdkExtensionsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_sdkExtensionsCount){value}; }
static inline _s_6196f22b_sdkExtensions _6196f22b_sdkExtensions(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_sdkExtensions){value}; }
static inline _s_6196f22b_optionalProgramName _6196f22b_optionalProgramName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_optionalProgramName){value}; }
static inline _s_6196f22b_optionalProgramVersion _6196f22b_optionalProgramVersion(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_optionalProgramVersion){value}; }
static inline _s_6196f22b_optionalEngineName _6196f22b_optionalEngineName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_optionalEngineName){value}; }
static inline _s_6196f22b_optionalEngineVersion _6196f22b_optionalEngineVersion(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_optionalEngineVersion){value}; }
static inline _s_6196f22b_optionalSettings _6196f22b_optionalSettings(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_optionalSettings){value}; }
static inline _s_6196f22b_outContext _6196f22b_outContext(RedContext* value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_outContext){value}; }
static inline _s_6196f22b_outStatuses _6196f22b_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_outStatuses){value}; }
static inline _s_6196f22b_optionalFile _6196f22b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_optionalFile){value}; }
static inline _s_6196f22b_optionalLine _6196f22b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_optionalLine){value}; }
static inline _s_6196f22b_optionalUserData _6196f22b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_optionalUserData){value}; }
static inline _s_6196f22b_rteParameters _6196f22b_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6196f22b_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateContextFromRteContext(_s_6196f22b_rteContext rteContext, _s_6196f22b_malloc malloc, _s_6196f22b_free free, _s_6196f22b_optionalMallocTagged optionalMallocTagged, _s_6196f22b_optionalFreeTagged optionalFreeTagged, _s_6196f22b_debugCallback debugCallback, _s_6196f22b_sdkVersion sdkVersion, _s_6196f22b_sdkExtensionsCount sdkExtensionsCount, _s_6196f22b_sdkExtensions sdkExtensions, _s_6196f22b_optionalProgramName optionalProgramName, _s_6196f22b_optionalProgramVersion optionalProgramVersion, _s_6196f22b_optionalEngineName optionalEngineName, _s_6196f22b_optionalEngineVersion optionalEngineVersion, _s_6196f22b_optionalSettings optionalSettings, _s_6196f22b_outContext outContext, _s_6196f22b_outStatuses outStatuses, _s_6196f22b_optionalFile optionalFile, _s_6196f22b_optionalLine optionalLine, _s_6196f22b_optionalUserData optionalUserData, _s_6196f22b_rteParameters rteParameters) {
  return redRteCreateContextFromRteContext(rteContext.value, malloc.value, free.value, optionalMallocTagged.value, optionalFreeTagged.value, debugCallback.value, sdkVersion.value, sdkExtensionsCount.value, sdkExtensions.value, optionalProgramName.value, optionalProgramVersion.value, optionalEngineName.value, optionalEngineVersion.value, optionalSettings.value, outContext.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateHelperAppWindow redRteCreateHelperAppWindow
#define _55973ae8_callbacks(value) value
#define _55973ae8_initialWindowWidth(value) value
#define _55973ae8_initialWindowHeight(value) value
#define _55973ae8_initialIsVsyncEnabled(value) value
#define _55973ae8_initialViewportClearColorR(value) value
#define _55973ae8_initialViewportClearColorG(value) value
#define _55973ae8_initialViewportClearColorB(value) value
#define _55973ae8_initialViewportClearColorA(value) value
#define _55973ae8_optionalProgramName(value) value
#define _55973ae8_optionalEngineName(value) value
#define _55973ae8_rteCreateContextParameters(value) value
#define _55973ae8_outHelperAppWindow(value) value
#define _55973ae8_outStatuses(value) value
#define _55973ae8_optionalFile(value) value
#define _55973ae8_optionalLine(value) value
#define _55973ae8_optionalUserData(value) value
#define _55973ae8_rteParameters(value) value
#else
typedef struct _s_55973ae8_callbacks { RedRteHelperAppCallbacks* value; } _s_55973ae8_callbacks;
typedef struct _s_55973ae8_initialWindowWidth { int value; } _s_55973ae8_initialWindowWidth;
typedef struct _s_55973ae8_initialWindowHeight { int value; } _s_55973ae8_initialWindowHeight;
typedef struct _s_55973ae8_initialIsVsyncEnabled { RedBool32 value; } _s_55973ae8_initialIsVsyncEnabled;
typedef struct _s_55973ae8_initialViewportClearColorR { float value; } _s_55973ae8_initialViewportClearColorR;
typedef struct _s_55973ae8_initialViewportClearColorG { float value; } _s_55973ae8_initialViewportClearColorG;
typedef struct _s_55973ae8_initialViewportClearColorB { float value; } _s_55973ae8_initialViewportClearColorB;
typedef struct _s_55973ae8_initialViewportClearColorA { float value; } _s_55973ae8_initialViewportClearColorA;
typedef struct _s_55973ae8_optionalProgramName { char* value; } _s_55973ae8_optionalProgramName;
typedef struct _s_55973ae8_optionalEngineName { char* value; } _s_55973ae8_optionalEngineName;
typedef struct _s_55973ae8_rteCreateContextParameters { RedRteCreateContextParameters* value; } _s_55973ae8_rteCreateContextParameters;
typedef struct _s_55973ae8_outHelperAppWindow { RedRteHandleHelperAppWindow* value; } _s_55973ae8_outHelperAppWindow;
typedef struct _s_55973ae8_outStatuses { RedStatuses* value; } _s_55973ae8_outStatuses;
typedef struct _s_55973ae8_optionalFile { char* value; } _s_55973ae8_optionalFile;
typedef struct _s_55973ae8_optionalLine { int value; } _s_55973ae8_optionalLine;
typedef struct _s_55973ae8_optionalUserData { void* value; } _s_55973ae8_optionalUserData;
typedef struct _s_55973ae8_rteParameters { void* value; } _s_55973ae8_rteParameters;
static inline _s_55973ae8_callbacks _55973ae8_callbacks(RedRteHelperAppCallbacks* value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_callbacks){value}; }
static inline _s_55973ae8_initialWindowWidth _55973ae8_initialWindowWidth(int value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_initialWindowWidth){value}; }
static inline _s_55973ae8_initialWindowHeight _55973ae8_initialWindowHeight(int value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_initialWindowHeight){value}; }
static inline _s_55973ae8_initialIsVsyncEnabled _55973ae8_initialIsVsyncEnabled(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_initialIsVsyncEnabled){value}; }
static inline _s_55973ae8_initialViewportClearColorR _55973ae8_initialViewportClearColorR(float value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_initialViewportClearColorR){value}; }
static inline _s_55973ae8_initialViewportClearColorG _55973ae8_initialViewportClearColorG(float value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_initialViewportClearColorG){value}; }
static inline _s_55973ae8_initialViewportClearColorB _55973ae8_initialViewportClearColorB(float value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_initialViewportClearColorB){value}; }
static inline _s_55973ae8_initialViewportClearColorA _55973ae8_initialViewportClearColorA(float value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_initialViewportClearColorA){value}; }
static inline _s_55973ae8_optionalProgramName _55973ae8_optionalProgramName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_optionalProgramName){value}; }
static inline _s_55973ae8_optionalEngineName _55973ae8_optionalEngineName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_optionalEngineName){value}; }
static inline _s_55973ae8_rteCreateContextParameters _55973ae8_rteCreateContextParameters(RedRteCreateContextParameters* value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_rteCreateContextParameters){value}; }
static inline _s_55973ae8_outHelperAppWindow _55973ae8_outHelperAppWindow(RedRteHandleHelperAppWindow* value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_outHelperAppWindow){value}; }
static inline _s_55973ae8_outStatuses _55973ae8_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_outStatuses){value}; }
static inline _s_55973ae8_optionalFile _55973ae8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_optionalFile){value}; }
static inline _s_55973ae8_optionalLine _55973ae8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_optionalLine){value}; }
static inline _s_55973ae8_optionalUserData _55973ae8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_optionalUserData){value}; }
static inline _s_55973ae8_rteParameters _55973ae8_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_55973ae8_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateHelperAppWindow(_s_55973ae8_callbacks callbacks, _s_55973ae8_initialWindowWidth initialWindowWidth, _s_55973ae8_initialWindowHeight initialWindowHeight, _s_55973ae8_initialIsVsyncEnabled initialIsVsyncEnabled, _s_55973ae8_initialViewportClearColorR initialViewportClearColorR, _s_55973ae8_initialViewportClearColorG initialViewportClearColorG, _s_55973ae8_initialViewportClearColorB initialViewportClearColorB, _s_55973ae8_initialViewportClearColorA initialViewportClearColorA, _s_55973ae8_optionalProgramName optionalProgramName, _s_55973ae8_optionalEngineName optionalEngineName, _s_55973ae8_rteCreateContextParameters rteCreateContextParameters, _s_55973ae8_outHelperAppWindow outHelperAppWindow, _s_55973ae8_outStatuses outStatuses, _s_55973ae8_optionalFile optionalFile, _s_55973ae8_optionalLine optionalLine, _s_55973ae8_optionalUserData optionalUserData, _s_55973ae8_rteParameters rteParameters) {
  return redRteCreateHelperAppWindow(callbacks.value, initialWindowWidth.value, initialWindowHeight.value, initialIsVsyncEnabled.value, initialViewportClearColorR.value, initialViewportClearColorG.value, initialViewportClearColorB.value, initialViewportClearColorA.value, optionalProgramName.value, optionalEngineName.value, rteCreateContextParameters.value, outHelperAppWindow.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyHelperAppWindow redRteDestroyHelperAppWindow
#define _b9b1d4b5_helperAppWindow(value) value
#define _b9b1d4b5_optionalFile(value) value
#define _b9b1d4b5_optionalLine(value) value
#define _b9b1d4b5_optionalUserData(value) value
#define _b9b1d4b5_rteParameters(value) value
#else
typedef struct _s_b9b1d4b5_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_b9b1d4b5_helperAppWindow;
typedef struct _s_b9b1d4b5_optionalFile { char* value; } _s_b9b1d4b5_optionalFile;
typedef struct _s_b9b1d4b5_optionalLine { int value; } _s_b9b1d4b5_optionalLine;
typedef struct _s_b9b1d4b5_optionalUserData { void* value; } _s_b9b1d4b5_optionalUserData;
typedef struct _s_b9b1d4b5_rteParameters { void* value; } _s_b9b1d4b5_rteParameters;
static inline _s_b9b1d4b5_helperAppWindow _b9b1d4b5_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_b9b1d4b5_helperAppWindow){value}; }
static inline _s_b9b1d4b5_optionalFile _b9b1d4b5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b9b1d4b5_optionalFile){value}; }
static inline _s_b9b1d4b5_optionalLine _b9b1d4b5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b9b1d4b5_optionalLine){value}; }
static inline _s_b9b1d4b5_optionalUserData _b9b1d4b5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b9b1d4b5_optionalUserData){value}; }
static inline _s_b9b1d4b5_rteParameters _b9b1d4b5_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b9b1d4b5_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyHelperAppWindow(_s_b9b1d4b5_helperAppWindow helperAppWindow, _s_b9b1d4b5_optionalFile optionalFile, _s_b9b1d4b5_optionalLine optionalLine, _s_b9b1d4b5_optionalUserData optionalUserData, _s_b9b1d4b5_rteParameters rteParameters) {
  return redRteDestroyHelperAppWindow(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowRun redRteHelperAppWindowRun
#define _8c740629_helperAppWindow(value) value
#define _8c740629_optionalFile(value) value
#define _8c740629_optionalLine(value) value
#define _8c740629_optionalUserData(value) value
#define _8c740629_rteParameters(value) value
#else
typedef struct _s_8c740629_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_8c740629_helperAppWindow;
typedef struct _s_8c740629_optionalFile { char* value; } _s_8c740629_optionalFile;
typedef struct _s_8c740629_optionalLine { int value; } _s_8c740629_optionalLine;
typedef struct _s_8c740629_optionalUserData { void* value; } _s_8c740629_optionalUserData;
typedef struct _s_8c740629_rteParameters { void* value; } _s_8c740629_rteParameters;
static inline _s_8c740629_helperAppWindow _8c740629_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_8c740629_helperAppWindow){value}; }
static inline _s_8c740629_optionalFile _8c740629_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8c740629_optionalFile){value}; }
static inline _s_8c740629_optionalLine _8c740629_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8c740629_optionalLine){value}; }
static inline _s_8c740629_optionalUserData _8c740629_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8c740629_optionalUserData){value}; }
static inline _s_8c740629_rteParameters _8c740629_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8c740629_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowRun(_s_8c740629_helperAppWindow helperAppWindow, _s_8c740629_optionalFile optionalFile, _s_8c740629_optionalLine optionalLine, _s_8c740629_optionalUserData optionalUserData, _s_8c740629_rteParameters rteParameters) {
  return redRteHelperAppWindowRun(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowClose redRteHelperAppWindowClose
#define _1e633dd3_helperAppWindow(value) value
#define _1e633dd3_optionalFile(value) value
#define _1e633dd3_optionalLine(value) value
#define _1e633dd3_optionalUserData(value) value
#define _1e633dd3_rteParameters(value) value
#else
typedef struct _s_1e633dd3_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_1e633dd3_helperAppWindow;
typedef struct _s_1e633dd3_optionalFile { char* value; } _s_1e633dd3_optionalFile;
typedef struct _s_1e633dd3_optionalLine { int value; } _s_1e633dd3_optionalLine;
typedef struct _s_1e633dd3_optionalUserData { void* value; } _s_1e633dd3_optionalUserData;
typedef struct _s_1e633dd3_rteParameters { void* value; } _s_1e633dd3_rteParameters;
static inline _s_1e633dd3_helperAppWindow _1e633dd3_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_1e633dd3_helperAppWindow){value}; }
static inline _s_1e633dd3_optionalFile _1e633dd3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1e633dd3_optionalFile){value}; }
static inline _s_1e633dd3_optionalLine _1e633dd3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1e633dd3_optionalLine){value}; }
static inline _s_1e633dd3_optionalUserData _1e633dd3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1e633dd3_optionalUserData){value}; }
static inline _s_1e633dd3_rteParameters _1e633dd3_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1e633dd3_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowClose(_s_1e633dd3_helperAppWindow helperAppWindow, _s_1e633dd3_optionalFile optionalFile, _s_1e633dd3_optionalLine optionalLine, _s_1e633dd3_optionalUserData optionalUserData, _s_1e633dd3_rteParameters rteParameters) {
  return redRteHelperAppWindowClose(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowSetViewport redRteHelperAppWindowSetViewport
#define _f85509e3_helperAppWindow(value) value
#define _f85509e3_calls(value) value
#define _f85509e3_optionalFile(value) value
#define _f85509e3_optionalLine(value) value
#define _f85509e3_optionalUserData(value) value
#define _f85509e3_rteParameters(value) value
#else
typedef struct _s_f85509e3_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_f85509e3_helperAppWindow;
typedef struct _s_f85509e3_calls { RedHandleCalls value; } _s_f85509e3_calls;
typedef struct _s_f85509e3_optionalFile { char* value; } _s_f85509e3_optionalFile;
typedef struct _s_f85509e3_optionalLine { int value; } _s_f85509e3_optionalLine;
typedef struct _s_f85509e3_optionalUserData { void* value; } _s_f85509e3_optionalUserData;
typedef struct _s_f85509e3_rteParameters { void* value; } _s_f85509e3_rteParameters;
static inline _s_f85509e3_helperAppWindow _f85509e3_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_f85509e3_helperAppWindow){value}; }
static inline _s_f85509e3_calls _f85509e3_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_f85509e3_calls){value}; }
static inline _s_f85509e3_optionalFile _f85509e3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f85509e3_optionalFile){value}; }
static inline _s_f85509e3_optionalLine _f85509e3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f85509e3_optionalLine){value}; }
static inline _s_f85509e3_optionalUserData _f85509e3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f85509e3_optionalUserData){value}; }
static inline _s_f85509e3_rteParameters _f85509e3_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f85509e3_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowSetViewport(_s_f85509e3_helperAppWindow helperAppWindow, _s_f85509e3_calls calls, _s_f85509e3_optionalFile optionalFile, _s_f85509e3_optionalLine optionalLine, _s_f85509e3_optionalUserData optionalUserData, _s_f85509e3_rteParameters rteParameters) {
  return redRteHelperAppWindowSetViewport(helperAppWindow.value, calls.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowIsVsyncEnabled redRteHelperAppWindowIsVsyncEnabled
#define _d2566f6e_helperAppWindow(value) value
#define _d2566f6e_optionalFile(value) value
#define _d2566f6e_optionalLine(value) value
#define _d2566f6e_optionalUserData(value) value
#define _d2566f6e_rteParameters(value) value
#else
typedef struct _s_d2566f6e_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_d2566f6e_helperAppWindow;
typedef struct _s_d2566f6e_optionalFile { char* value; } _s_d2566f6e_optionalFile;
typedef struct _s_d2566f6e_optionalLine { int value; } _s_d2566f6e_optionalLine;
typedef struct _s_d2566f6e_optionalUserData { void* value; } _s_d2566f6e_optionalUserData;
typedef struct _s_d2566f6e_rteParameters { void* value; } _s_d2566f6e_rteParameters;
static inline _s_d2566f6e_helperAppWindow _d2566f6e_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_d2566f6e_helperAppWindow){value}; }
static inline _s_d2566f6e_optionalFile _d2566f6e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d2566f6e_optionalFile){value}; }
static inline _s_d2566f6e_optionalLine _d2566f6e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d2566f6e_optionalLine){value}; }
static inline _s_d2566f6e_optionalUserData _d2566f6e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d2566f6e_optionalUserData){value}; }
static inline _s_d2566f6e_rteParameters _d2566f6e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d2566f6e_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedBool32 REDGPU_NP_API np_redRteHelperAppWindowIsVsyncEnabled(_s_d2566f6e_helperAppWindow helperAppWindow, _s_d2566f6e_optionalFile optionalFile, _s_d2566f6e_optionalLine optionalLine, _s_d2566f6e_optionalUserData optionalUserData, _s_d2566f6e_rteParameters rteParameters) {
  return redRteHelperAppWindowIsVsyncEnabled(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowSetVsyncEnabled redRteHelperAppWindowSetVsyncEnabled
#define _dbd486ee_helperAppWindow(value) value
#define _dbd486ee_enableVsync(value) value
#define _dbd486ee_optionalFile(value) value
#define _dbd486ee_optionalLine(value) value
#define _dbd486ee_optionalUserData(value) value
#define _dbd486ee_rteParameters(value) value
#else
typedef struct _s_dbd486ee_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_dbd486ee_helperAppWindow;
typedef struct _s_dbd486ee_enableVsync { RedBool32 value; } _s_dbd486ee_enableVsync;
typedef struct _s_dbd486ee_optionalFile { char* value; } _s_dbd486ee_optionalFile;
typedef struct _s_dbd486ee_optionalLine { int value; } _s_dbd486ee_optionalLine;
typedef struct _s_dbd486ee_optionalUserData { void* value; } _s_dbd486ee_optionalUserData;
typedef struct _s_dbd486ee_rteParameters { void* value; } _s_dbd486ee_rteParameters;
static inline _s_dbd486ee_helperAppWindow _dbd486ee_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_dbd486ee_helperAppWindow){value}; }
static inline _s_dbd486ee_enableVsync _dbd486ee_enableVsync(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_dbd486ee_enableVsync){value}; }
static inline _s_dbd486ee_optionalFile _dbd486ee_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_dbd486ee_optionalFile){value}; }
static inline _s_dbd486ee_optionalLine _dbd486ee_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_dbd486ee_optionalLine){value}; }
static inline _s_dbd486ee_optionalUserData _dbd486ee_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_dbd486ee_optionalUserData){value}; }
static inline _s_dbd486ee_rteParameters _dbd486ee_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_dbd486ee_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowSetVsyncEnabled(_s_dbd486ee_helperAppWindow helperAppWindow, _s_dbd486ee_enableVsync enableVsync, _s_dbd486ee_optionalFile optionalFile, _s_dbd486ee_optionalLine optionalLine, _s_dbd486ee_optionalUserData optionalUserData, _s_dbd486ee_rteParameters rteParameters) {
  return redRteHelperAppWindowSetVsyncEnabled(helperAppWindow.value, enableVsync.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowSetViewportClearColor redRteHelperAppWindowSetViewportClearColor
#define _4573ca2f_helperAppWindow(value) value
#define _4573ca2f_viewportClearColorR(value) value
#define _4573ca2f_viewportClearColorG(value) value
#define _4573ca2f_viewportClearColorB(value) value
#define _4573ca2f_viewportClearColorA(value) value
#define _4573ca2f_optionalFile(value) value
#define _4573ca2f_optionalLine(value) value
#define _4573ca2f_optionalUserData(value) value
#define _4573ca2f_rteParameters(value) value
#else
typedef struct _s_4573ca2f_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_4573ca2f_helperAppWindow;
typedef struct _s_4573ca2f_viewportClearColorR { float value; } _s_4573ca2f_viewportClearColorR;
typedef struct _s_4573ca2f_viewportClearColorG { float value; } _s_4573ca2f_viewportClearColorG;
typedef struct _s_4573ca2f_viewportClearColorB { float value; } _s_4573ca2f_viewportClearColorB;
typedef struct _s_4573ca2f_viewportClearColorA { float value; } _s_4573ca2f_viewportClearColorA;
typedef struct _s_4573ca2f_optionalFile { char* value; } _s_4573ca2f_optionalFile;
typedef struct _s_4573ca2f_optionalLine { int value; } _s_4573ca2f_optionalLine;
typedef struct _s_4573ca2f_optionalUserData { void* value; } _s_4573ca2f_optionalUserData;
typedef struct _s_4573ca2f_rteParameters { void* value; } _s_4573ca2f_rteParameters;
static inline _s_4573ca2f_helperAppWindow _4573ca2f_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_4573ca2f_helperAppWindow){value}; }
static inline _s_4573ca2f_viewportClearColorR _4573ca2f_viewportClearColorR(float value) { return REDGPU_NP_STRUCT_INIT(_s_4573ca2f_viewportClearColorR){value}; }
static inline _s_4573ca2f_viewportClearColorG _4573ca2f_viewportClearColorG(float value) { return REDGPU_NP_STRUCT_INIT(_s_4573ca2f_viewportClearColorG){value}; }
static inline _s_4573ca2f_viewportClearColorB _4573ca2f_viewportClearColorB(float value) { return REDGPU_NP_STRUCT_INIT(_s_4573ca2f_viewportClearColorB){value}; }
static inline _s_4573ca2f_viewportClearColorA _4573ca2f_viewportClearColorA(float value) { return REDGPU_NP_STRUCT_INIT(_s_4573ca2f_viewportClearColorA){value}; }
static inline _s_4573ca2f_optionalFile _4573ca2f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4573ca2f_optionalFile){value}; }
static inline _s_4573ca2f_optionalLine _4573ca2f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4573ca2f_optionalLine){value}; }
static inline _s_4573ca2f_optionalUserData _4573ca2f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4573ca2f_optionalUserData){value}; }
static inline _s_4573ca2f_rteParameters _4573ca2f_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4573ca2f_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowSetViewportClearColor(_s_4573ca2f_helperAppWindow helperAppWindow, _s_4573ca2f_viewportClearColorR viewportClearColorR, _s_4573ca2f_viewportClearColorG viewportClearColorG, _s_4573ca2f_viewportClearColorB viewportClearColorB, _s_4573ca2f_viewportClearColorA viewportClearColorA, _s_4573ca2f_optionalFile optionalFile, _s_4573ca2f_optionalLine optionalLine, _s_4573ca2f_optionalUserData optionalUserData, _s_4573ca2f_rteParameters rteParameters) {
  return redRteHelperAppWindowSetViewportClearColor(helperAppWindow.value, viewportClearColorR.value, viewportClearColorG.value, viewportClearColorB.value, viewportClearColorA.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowAddWaitSemaphore redRteHelperAppWindowAddWaitSemaphore
#define _96f9cc14_helperAppWindow(value) value
#define _96f9cc14_vkSemaphoreSubmitInfoKHR(value) value
#define _96f9cc14_optionalFile(value) value
#define _96f9cc14_optionalLine(value) value
#define _96f9cc14_optionalUserData(value) value
#define _96f9cc14_rteParameters(value) value
#else
typedef struct _s_96f9cc14_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_96f9cc14_helperAppWindow;
typedef struct _s_96f9cc14_vkSemaphoreSubmitInfoKHR { void* value; } _s_96f9cc14_vkSemaphoreSubmitInfoKHR;
typedef struct _s_96f9cc14_optionalFile { char* value; } _s_96f9cc14_optionalFile;
typedef struct _s_96f9cc14_optionalLine { int value; } _s_96f9cc14_optionalLine;
typedef struct _s_96f9cc14_optionalUserData { void* value; } _s_96f9cc14_optionalUserData;
typedef struct _s_96f9cc14_rteParameters { void* value; } _s_96f9cc14_rteParameters;
static inline _s_96f9cc14_helperAppWindow _96f9cc14_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_96f9cc14_helperAppWindow){value}; }
static inline _s_96f9cc14_vkSemaphoreSubmitInfoKHR _96f9cc14_vkSemaphoreSubmitInfoKHR(void* value) { return REDGPU_NP_STRUCT_INIT(_s_96f9cc14_vkSemaphoreSubmitInfoKHR){value}; }
static inline _s_96f9cc14_optionalFile _96f9cc14_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_96f9cc14_optionalFile){value}; }
static inline _s_96f9cc14_optionalLine _96f9cc14_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_96f9cc14_optionalLine){value}; }
static inline _s_96f9cc14_optionalUserData _96f9cc14_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_96f9cc14_optionalUserData){value}; }
static inline _s_96f9cc14_rteParameters _96f9cc14_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_96f9cc14_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowAddWaitSemaphore(_s_96f9cc14_helperAppWindow helperAppWindow, _s_96f9cc14_vkSemaphoreSubmitInfoKHR vkSemaphoreSubmitInfoKHR, _s_96f9cc14_optionalFile optionalFile, _s_96f9cc14_optionalLine optionalLine, _s_96f9cc14_optionalUserData optionalUserData, _s_96f9cc14_rteParameters rteParameters) {
  return redRteHelperAppWindowAddWaitSemaphore(helperAppWindow.value, vkSemaphoreSubmitInfoKHR.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowTempCallsCreateAndSet redRteHelperAppWindowTempCallsCreateAndSet
#define _b87380e0_helperAppWindow(value) value
#define _b87380e0_optionalFile(value) value
#define _b87380e0_optionalLine(value) value
#define _b87380e0_optionalUserData(value) value
#define _b87380e0_rteParameters(value) value
#else
typedef struct _s_b87380e0_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_b87380e0_helperAppWindow;
typedef struct _s_b87380e0_optionalFile { char* value; } _s_b87380e0_optionalFile;
typedef struct _s_b87380e0_optionalLine { int value; } _s_b87380e0_optionalLine;
typedef struct _s_b87380e0_optionalUserData { void* value; } _s_b87380e0_optionalUserData;
typedef struct _s_b87380e0_rteParameters { void* value; } _s_b87380e0_rteParameters;
static inline _s_b87380e0_helperAppWindow _b87380e0_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_b87380e0_helperAppWindow){value}; }
static inline _s_b87380e0_optionalFile _b87380e0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b87380e0_optionalFile){value}; }
static inline _s_b87380e0_optionalLine _b87380e0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b87380e0_optionalLine){value}; }
static inline _s_b87380e0_optionalUserData _b87380e0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b87380e0_optionalUserData){value}; }
static inline _s_b87380e0_rteParameters _b87380e0_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b87380e0_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleCalls REDGPU_NP_API np_redRteHelperAppWindowTempCallsCreateAndSet(_s_b87380e0_helperAppWindow helperAppWindow, _s_b87380e0_optionalFile optionalFile, _s_b87380e0_optionalLine optionalLine, _s_b87380e0_optionalUserData optionalUserData, _s_b87380e0_rteParameters rteParameters) {
  return redRteHelperAppWindowTempCallsCreateAndSet(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowTempCallsEndSubmitWaitAndDestroy redRteHelperAppWindowTempCallsEndSubmitWaitAndDestroy
#define _8a6e2e2d_helperAppWindow(value) value
#define _8a6e2e2d_tempCalls(value) value
#define _8a6e2e2d_optionalFile(value) value
#define _8a6e2e2d_optionalLine(value) value
#define _8a6e2e2d_optionalUserData(value) value
#define _8a6e2e2d_rteParameters(value) value
#else
typedef struct _s_8a6e2e2d_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_8a6e2e2d_helperAppWindow;
typedef struct _s_8a6e2e2d_tempCalls { RedHandleCalls value; } _s_8a6e2e2d_tempCalls;
typedef struct _s_8a6e2e2d_optionalFile { char* value; } _s_8a6e2e2d_optionalFile;
typedef struct _s_8a6e2e2d_optionalLine { int value; } _s_8a6e2e2d_optionalLine;
typedef struct _s_8a6e2e2d_optionalUserData { void* value; } _s_8a6e2e2d_optionalUserData;
typedef struct _s_8a6e2e2d_rteParameters { void* value; } _s_8a6e2e2d_rteParameters;
static inline _s_8a6e2e2d_helperAppWindow _8a6e2e2d_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_8a6e2e2d_helperAppWindow){value}; }
static inline _s_8a6e2e2d_tempCalls _8a6e2e2d_tempCalls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_8a6e2e2d_tempCalls){value}; }
static inline _s_8a6e2e2d_optionalFile _8a6e2e2d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8a6e2e2d_optionalFile){value}; }
static inline _s_8a6e2e2d_optionalLine _8a6e2e2d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8a6e2e2d_optionalLine){value}; }
static inline _s_8a6e2e2d_optionalUserData _8a6e2e2d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8a6e2e2d_optionalUserData){value}; }
static inline _s_8a6e2e2d_rteParameters _8a6e2e2d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8a6e2e2d_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowTempCallsEndSubmitWaitAndDestroy(_s_8a6e2e2d_helperAppWindow helperAppWindow, _s_8a6e2e2d_tempCalls tempCalls, _s_8a6e2e2d_optionalFile optionalFile, _s_8a6e2e2d_optionalLine optionalLine, _s_8a6e2e2d_optionalUserData optionalUserData, _s_8a6e2e2d_rteParameters rteParameters) {
  return redRteHelperAppWindowTempCallsEndSubmitWaitAndDestroy(helperAppWindow.value, tempCalls.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowOnFileDrop redRteHelperAppWindowOnFileDrop
#define _6d4e1289_helperAppWindow(value) value
#define _6d4e1289_filename(value) value
#define _6d4e1289_optionalFile(value) value
#define _6d4e1289_optionalLine(value) value
#define _6d4e1289_optionalUserData(value) value
#define _6d4e1289_rteParameters(value) value
#else
typedef struct _s_6d4e1289_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_6d4e1289_helperAppWindow;
typedef struct _s_6d4e1289_filename { char* value; } _s_6d4e1289_filename;
typedef struct _s_6d4e1289_optionalFile { char* value; } _s_6d4e1289_optionalFile;
typedef struct _s_6d4e1289_optionalLine { int value; } _s_6d4e1289_optionalLine;
typedef struct _s_6d4e1289_optionalUserData { void* value; } _s_6d4e1289_optionalUserData;
typedef struct _s_6d4e1289_rteParameters { void* value; } _s_6d4e1289_rteParameters;
static inline _s_6d4e1289_helperAppWindow _6d4e1289_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_6d4e1289_helperAppWindow){value}; }
static inline _s_6d4e1289_filename _6d4e1289_filename(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6d4e1289_filename){value}; }
static inline _s_6d4e1289_optionalFile _6d4e1289_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6d4e1289_optionalFile){value}; }
static inline _s_6d4e1289_optionalLine _6d4e1289_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6d4e1289_optionalLine){value}; }
static inline _s_6d4e1289_optionalUserData _6d4e1289_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6d4e1289_optionalUserData){value}; }
static inline _s_6d4e1289_rteParameters _6d4e1289_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6d4e1289_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowOnFileDrop(_s_6d4e1289_helperAppWindow helperAppWindow, _s_6d4e1289_filename filename, _s_6d4e1289_optionalFile optionalFile, _s_6d4e1289_optionalLine optionalLine, _s_6d4e1289_optionalUserData optionalUserData, _s_6d4e1289_rteParameters rteParameters) {
  return redRteHelperAppWindowOnFileDrop(helperAppWindow.value, filename.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetRteContext redRteHelperAppWindowGetRteContext
#define _e7fbecf3_helperAppWindow(value) value
#define _e7fbecf3_optionalFile(value) value
#define _e7fbecf3_optionalLine(value) value
#define _e7fbecf3_optionalUserData(value) value
#define _e7fbecf3_rteParameters(value) value
#else
typedef struct _s_e7fbecf3_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_e7fbecf3_helperAppWindow;
typedef struct _s_e7fbecf3_optionalFile { char* value; } _s_e7fbecf3_optionalFile;
typedef struct _s_e7fbecf3_optionalLine { int value; } _s_e7fbecf3_optionalLine;
typedef struct _s_e7fbecf3_optionalUserData { void* value; } _s_e7fbecf3_optionalUserData;
typedef struct _s_e7fbecf3_rteParameters { void* value; } _s_e7fbecf3_rteParameters;
static inline _s_e7fbecf3_helperAppWindow _e7fbecf3_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_e7fbecf3_helperAppWindow){value}; }
static inline _s_e7fbecf3_optionalFile _e7fbecf3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e7fbecf3_optionalFile){value}; }
static inline _s_e7fbecf3_optionalLine _e7fbecf3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e7fbecf3_optionalLine){value}; }
static inline _s_e7fbecf3_optionalUserData _e7fbecf3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e7fbecf3_optionalUserData){value}; }
static inline _s_e7fbecf3_rteParameters _e7fbecf3_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e7fbecf3_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedRteHandleContext REDGPU_NP_API np_redRteHelperAppWindowGetRteContext(_s_e7fbecf3_helperAppWindow helperAppWindow, _s_e7fbecf3_optionalFile optionalFile, _s_e7fbecf3_optionalLine optionalLine, _s_e7fbecf3_optionalUserData optionalUserData, _s_e7fbecf3_rteParameters rteParameters) {
  return redRteHelperAppWindowGetRteContext(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetGlfwWindow redRteHelperAppWindowGetGlfwWindow
#define _c49fa0c3_helperAppWindow(value) value
#define _c49fa0c3_optionalFile(value) value
#define _c49fa0c3_optionalLine(value) value
#define _c49fa0c3_optionalUserData(value) value
#define _c49fa0c3_rteParameters(value) value
#else
typedef struct _s_c49fa0c3_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_c49fa0c3_helperAppWindow;
typedef struct _s_c49fa0c3_optionalFile { char* value; } _s_c49fa0c3_optionalFile;
typedef struct _s_c49fa0c3_optionalLine { int value; } _s_c49fa0c3_optionalLine;
typedef struct _s_c49fa0c3_optionalUserData { void* value; } _s_c49fa0c3_optionalUserData;
typedef struct _s_c49fa0c3_rteParameters { void* value; } _s_c49fa0c3_rteParameters;
static inline _s_c49fa0c3_helperAppWindow _c49fa0c3_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_c49fa0c3_helperAppWindow){value}; }
static inline _s_c49fa0c3_optionalFile _c49fa0c3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c49fa0c3_optionalFile){value}; }
static inline _s_c49fa0c3_optionalLine _c49fa0c3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c49fa0c3_optionalLine){value}; }
static inline _s_c49fa0c3_optionalUserData _c49fa0c3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c49fa0c3_optionalUserData){value}; }
static inline _s_c49fa0c3_rteParameters _c49fa0c3_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c49fa0c3_rteParameters){value}; }
REDGPU_NP_DECLSPEC void* REDGPU_NP_API np_redRteHelperAppWindowGetGlfwWindow(_s_c49fa0c3_helperAppWindow helperAppWindow, _s_c49fa0c3_optionalFile optionalFile, _s_c49fa0c3_optionalLine optionalLine, _s_c49fa0c3_optionalUserData optionalUserData, _s_c49fa0c3_rteParameters rteParameters) {
  return redRteHelperAppWindowGetGlfwWindow(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetViewportWidth redRteHelperAppWindowGetViewportWidth
#define _008a775f_helperAppWindow(value) value
#define _008a775f_optionalFile(value) value
#define _008a775f_optionalLine(value) value
#define _008a775f_optionalUserData(value) value
#define _008a775f_rteParameters(value) value
#else
typedef struct _s_008a775f_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_008a775f_helperAppWindow;
typedef struct _s_008a775f_optionalFile { char* value; } _s_008a775f_optionalFile;
typedef struct _s_008a775f_optionalLine { int value; } _s_008a775f_optionalLine;
typedef struct _s_008a775f_optionalUserData { void* value; } _s_008a775f_optionalUserData;
typedef struct _s_008a775f_rteParameters { void* value; } _s_008a775f_rteParameters;
static inline _s_008a775f_helperAppWindow _008a775f_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_008a775f_helperAppWindow){value}; }
static inline _s_008a775f_optionalFile _008a775f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_008a775f_optionalFile){value}; }
static inline _s_008a775f_optionalLine _008a775f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_008a775f_optionalLine){value}; }
static inline _s_008a775f_optionalUserData _008a775f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_008a775f_optionalUserData){value}; }
static inline _s_008a775f_rteParameters _008a775f_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_008a775f_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowGetViewportWidth(_s_008a775f_helperAppWindow helperAppWindow, _s_008a775f_optionalFile optionalFile, _s_008a775f_optionalLine optionalLine, _s_008a775f_optionalUserData optionalUserData, _s_008a775f_rteParameters rteParameters) {
  return redRteHelperAppWindowGetViewportWidth(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetViewportHeight redRteHelperAppWindowGetViewportHeight
#define _0e4eac77_helperAppWindow(value) value
#define _0e4eac77_optionalFile(value) value
#define _0e4eac77_optionalLine(value) value
#define _0e4eac77_optionalUserData(value) value
#define _0e4eac77_rteParameters(value) value
#else
typedef struct _s_0e4eac77_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_0e4eac77_helperAppWindow;
typedef struct _s_0e4eac77_optionalFile { char* value; } _s_0e4eac77_optionalFile;
typedef struct _s_0e4eac77_optionalLine { int value; } _s_0e4eac77_optionalLine;
typedef struct _s_0e4eac77_optionalUserData { void* value; } _s_0e4eac77_optionalUserData;
typedef struct _s_0e4eac77_rteParameters { void* value; } _s_0e4eac77_rteParameters;
static inline _s_0e4eac77_helperAppWindow _0e4eac77_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_0e4eac77_helperAppWindow){value}; }
static inline _s_0e4eac77_optionalFile _0e4eac77_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0e4eac77_optionalFile){value}; }
static inline _s_0e4eac77_optionalLine _0e4eac77_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0e4eac77_optionalLine){value}; }
static inline _s_0e4eac77_optionalUserData _0e4eac77_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0e4eac77_optionalUserData){value}; }
static inline _s_0e4eac77_rteParameters _0e4eac77_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0e4eac77_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowGetViewportHeight(_s_0e4eac77_helperAppWindow helperAppWindow, _s_0e4eac77_optionalFile optionalFile, _s_0e4eac77_optionalLine optionalLine, _s_0e4eac77_optionalUserData optionalUserData, _s_0e4eac77_rteParameters rteParameters) {
  return redRteHelperAppWindowGetViewportHeight(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetWindowWidth redRteHelperAppWindowGetWindowWidth
#define _44d3ff0a_helperAppWindow(value) value
#define _44d3ff0a_optionalFile(value) value
#define _44d3ff0a_optionalLine(value) value
#define _44d3ff0a_optionalUserData(value) value
#define _44d3ff0a_rteParameters(value) value
#else
typedef struct _s_44d3ff0a_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_44d3ff0a_helperAppWindow;
typedef struct _s_44d3ff0a_optionalFile { char* value; } _s_44d3ff0a_optionalFile;
typedef struct _s_44d3ff0a_optionalLine { int value; } _s_44d3ff0a_optionalLine;
typedef struct _s_44d3ff0a_optionalUserData { void* value; } _s_44d3ff0a_optionalUserData;
typedef struct _s_44d3ff0a_rteParameters { void* value; } _s_44d3ff0a_rteParameters;
static inline _s_44d3ff0a_helperAppWindow _44d3ff0a_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_44d3ff0a_helperAppWindow){value}; }
static inline _s_44d3ff0a_optionalFile _44d3ff0a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_44d3ff0a_optionalFile){value}; }
static inline _s_44d3ff0a_optionalLine _44d3ff0a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_44d3ff0a_optionalLine){value}; }
static inline _s_44d3ff0a_optionalUserData _44d3ff0a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_44d3ff0a_optionalUserData){value}; }
static inline _s_44d3ff0a_rteParameters _44d3ff0a_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_44d3ff0a_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowGetWindowWidth(_s_44d3ff0a_helperAppWindow helperAppWindow, _s_44d3ff0a_optionalFile optionalFile, _s_44d3ff0a_optionalLine optionalLine, _s_44d3ff0a_optionalUserData optionalUserData, _s_44d3ff0a_rteParameters rteParameters) {
  return redRteHelperAppWindowGetWindowWidth(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetWindowHeight redRteHelperAppWindowGetWindowHeight
#define _8d34566e_helperAppWindow(value) value
#define _8d34566e_optionalFile(value) value
#define _8d34566e_optionalLine(value) value
#define _8d34566e_optionalUserData(value) value
#define _8d34566e_rteParameters(value) value
#else
typedef struct _s_8d34566e_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_8d34566e_helperAppWindow;
typedef struct _s_8d34566e_optionalFile { char* value; } _s_8d34566e_optionalFile;
typedef struct _s_8d34566e_optionalLine { int value; } _s_8d34566e_optionalLine;
typedef struct _s_8d34566e_optionalUserData { void* value; } _s_8d34566e_optionalUserData;
typedef struct _s_8d34566e_rteParameters { void* value; } _s_8d34566e_rteParameters;
static inline _s_8d34566e_helperAppWindow _8d34566e_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_8d34566e_helperAppWindow){value}; }
static inline _s_8d34566e_optionalFile _8d34566e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8d34566e_optionalFile){value}; }
static inline _s_8d34566e_optionalLine _8d34566e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8d34566e_optionalLine){value}; }
static inline _s_8d34566e_optionalUserData _8d34566e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8d34566e_optionalUserData){value}; }
static inline _s_8d34566e_rteParameters _8d34566e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8d34566e_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowGetWindowHeight(_s_8d34566e_helperAppWindow helperAppWindow, _s_8d34566e_optionalFile optionalFile, _s_8d34566e_optionalLine optionalLine, _s_8d34566e_optionalUserData optionalUserData, _s_8d34566e_rteParameters rteParameters) {
  return redRteHelperAppWindowGetWindowHeight(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetImGuiImplVulkanHWindowData redRteHelperAppWindowGetImGuiImplVulkanHWindowData
#define _e5c0e7fc_helperAppWindow(value) value
#define _e5c0e7fc_optionalFile(value) value
#define _e5c0e7fc_optionalLine(value) value
#define _e5c0e7fc_optionalUserData(value) value
#define _e5c0e7fc_rteParameters(value) value
#else
typedef struct _s_e5c0e7fc_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_e5c0e7fc_helperAppWindow;
typedef struct _s_e5c0e7fc_optionalFile { char* value; } _s_e5c0e7fc_optionalFile;
typedef struct _s_e5c0e7fc_optionalLine { int value; } _s_e5c0e7fc_optionalLine;
typedef struct _s_e5c0e7fc_optionalUserData { void* value; } _s_e5c0e7fc_optionalUserData;
typedef struct _s_e5c0e7fc_rteParameters { void* value; } _s_e5c0e7fc_rteParameters;
static inline _s_e5c0e7fc_helperAppWindow _e5c0e7fc_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_e5c0e7fc_helperAppWindow){value}; }
static inline _s_e5c0e7fc_optionalFile _e5c0e7fc_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e5c0e7fc_optionalFile){value}; }
static inline _s_e5c0e7fc_optionalLine _e5c0e7fc_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e5c0e7fc_optionalLine){value}; }
static inline _s_e5c0e7fc_optionalUserData _e5c0e7fc_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e5c0e7fc_optionalUserData){value}; }
static inline _s_e5c0e7fc_rteParameters _e5c0e7fc_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e5c0e7fc_rteParameters){value}; }
REDGPU_NP_DECLSPEC void* REDGPU_NP_API np_redRteHelperAppWindowGetImGuiImplVulkanHWindowData(_s_e5c0e7fc_helperAppWindow helperAppWindow, _s_e5c0e7fc_optionalFile optionalFile, _s_e5c0e7fc_optionalLine optionalLine, _s_e5c0e7fc_optionalUserData optionalUserData, _s_e5c0e7fc_rteParameters rteParameters) {
  return redRteHelperAppWindowGetImGuiImplVulkanHWindowData(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateHelperGBuffer redRteCreateHelperGBuffer
#define _912a0062_rteContext(value) value
#define _912a0062_rteHandleHelperAllocator(value) value
#define _912a0062_width(value) value
#define _912a0062_height(value) value
#define _912a0062_colorFormatsCount(value) value
#define _912a0062_colorFormats(value) value
#define _912a0062_depthFormat(value) value
#define _912a0062_outHelperGBuffer(value) value
#define _912a0062_outStatuses(value) value
#define _912a0062_optionalFile(value) value
#define _912a0062_optionalLine(value) value
#define _912a0062_optionalUserData(value) value
#define _912a0062_rteParameters(value) value
#else
typedef struct _s_912a0062_rteContext { RedRteHandleContext value; } _s_912a0062_rteContext;
typedef struct _s_912a0062_rteHandleHelperAllocator { void* value; } _s_912a0062_rteHandleHelperAllocator;
typedef struct _s_912a0062_width { unsigned value; } _s_912a0062_width;
typedef struct _s_912a0062_height { unsigned value; } _s_912a0062_height;
typedef struct _s_912a0062_colorFormatsCount { unsigned value; } _s_912a0062_colorFormatsCount;
typedef struct _s_912a0062_colorFormats { unsigned* value; } _s_912a0062_colorFormats;
typedef struct _s_912a0062_depthFormat { unsigned value; } _s_912a0062_depthFormat;
typedef struct _s_912a0062_outHelperGBuffer { RedRteHandleHelperGBuffer* value; } _s_912a0062_outHelperGBuffer;
typedef struct _s_912a0062_outStatuses { RedStatuses* value; } _s_912a0062_outStatuses;
typedef struct _s_912a0062_optionalFile { char* value; } _s_912a0062_optionalFile;
typedef struct _s_912a0062_optionalLine { int value; } _s_912a0062_optionalLine;
typedef struct _s_912a0062_optionalUserData { void* value; } _s_912a0062_optionalUserData;
typedef struct _s_912a0062_rteParameters { void* value; } _s_912a0062_rteParameters;
static inline _s_912a0062_rteContext _912a0062_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_rteContext){value}; }
static inline _s_912a0062_rteHandleHelperAllocator _912a0062_rteHandleHelperAllocator(void* value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_rteHandleHelperAllocator){value}; }
static inline _s_912a0062_width _912a0062_width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_width){value}; }
static inline _s_912a0062_height _912a0062_height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_height){value}; }
static inline _s_912a0062_colorFormatsCount _912a0062_colorFormatsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_colorFormatsCount){value}; }
static inline _s_912a0062_colorFormats _912a0062_colorFormats(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_colorFormats){value}; }
static inline _s_912a0062_depthFormat _912a0062_depthFormat(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_depthFormat){value}; }
static inline _s_912a0062_outHelperGBuffer _912a0062_outHelperGBuffer(RedRteHandleHelperGBuffer* value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_outHelperGBuffer){value}; }
static inline _s_912a0062_outStatuses _912a0062_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_outStatuses){value}; }
static inline _s_912a0062_optionalFile _912a0062_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_optionalFile){value}; }
static inline _s_912a0062_optionalLine _912a0062_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_optionalLine){value}; }
static inline _s_912a0062_optionalUserData _912a0062_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_optionalUserData){value}; }
static inline _s_912a0062_rteParameters _912a0062_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_912a0062_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateHelperGBuffer(_s_912a0062_rteContext rteContext, _s_912a0062_rteHandleHelperAllocator rteHandleHelperAllocator, _s_912a0062_width width, _s_912a0062_height height, _s_912a0062_colorFormatsCount colorFormatsCount, _s_912a0062_colorFormats colorFormats, _s_912a0062_depthFormat depthFormat, _s_912a0062_outHelperGBuffer outHelperGBuffer, _s_912a0062_outStatuses outStatuses, _s_912a0062_optionalFile optionalFile, _s_912a0062_optionalLine optionalLine, _s_912a0062_optionalUserData optionalUserData, _s_912a0062_rteParameters rteParameters) {
  return redRteCreateHelperGBuffer(rteContext.value, rteHandleHelperAllocator.value, width.value, height.value, colorFormatsCount.value, colorFormats.value, depthFormat.value, outHelperGBuffer.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyHelperGBuffer redRteDestroyHelperGBuffer
#define _341970df_helperGBuffer(value) value
#define _341970df_optionalFile(value) value
#define _341970df_optionalLine(value) value
#define _341970df_optionalUserData(value) value
#define _341970df_rteParameters(value) value
#else
typedef struct _s_341970df_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_341970df_helperGBuffer;
typedef struct _s_341970df_optionalFile { char* value; } _s_341970df_optionalFile;
typedef struct _s_341970df_optionalLine { int value; } _s_341970df_optionalLine;
typedef struct _s_341970df_optionalUserData { void* value; } _s_341970df_optionalUserData;
typedef struct _s_341970df_rteParameters { void* value; } _s_341970df_rteParameters;
static inline _s_341970df_helperGBuffer _341970df_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_341970df_helperGBuffer){value}; }
static inline _s_341970df_optionalFile _341970df_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_341970df_optionalFile){value}; }
static inline _s_341970df_optionalLine _341970df_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_341970df_optionalLine){value}; }
static inline _s_341970df_optionalUserData _341970df_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_341970df_optionalUserData){value}; }
static inline _s_341970df_rteParameters _341970df_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_341970df_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyHelperGBuffer(_s_341970df_helperGBuffer helperGBuffer, _s_341970df_optionalFile optionalFile, _s_341970df_optionalLine optionalLine, _s_341970df_optionalUserData optionalUserData, _s_341970df_rteParameters rteParameters) {
  return redRteDestroyHelperGBuffer(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetStruct redRteHelperGBufferGetStruct
#define _8bd80a5b_helperGBuffer(value) value
#define _8bd80a5b_index(value) value
#define _8bd80a5b_optionalFile(value) value
#define _8bd80a5b_optionalLine(value) value
#define _8bd80a5b_optionalUserData(value) value
#define _8bd80a5b_rteParameters(value) value
#else
typedef struct _s_8bd80a5b_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_8bd80a5b_helperGBuffer;
typedef struct _s_8bd80a5b_index { unsigned value; } _s_8bd80a5b_index;
typedef struct _s_8bd80a5b_optionalFile { char* value; } _s_8bd80a5b_optionalFile;
typedef struct _s_8bd80a5b_optionalLine { int value; } _s_8bd80a5b_optionalLine;
typedef struct _s_8bd80a5b_optionalUserData { void* value; } _s_8bd80a5b_optionalUserData;
typedef struct _s_8bd80a5b_rteParameters { void* value; } _s_8bd80a5b_rteParameters;
static inline _s_8bd80a5b_helperGBuffer _8bd80a5b_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_8bd80a5b_helperGBuffer){value}; }
static inline _s_8bd80a5b_index _8bd80a5b_index(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8bd80a5b_index){value}; }
static inline _s_8bd80a5b_optionalFile _8bd80a5b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8bd80a5b_optionalFile){value}; }
static inline _s_8bd80a5b_optionalLine _8bd80a5b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8bd80a5b_optionalLine){value}; }
static inline _s_8bd80a5b_optionalUserData _8bd80a5b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8bd80a5b_optionalUserData){value}; }
static inline _s_8bd80a5b_rteParameters _8bd80a5b_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8bd80a5b_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleStruct REDGPU_NP_API np_redRteHelperGBufferGetStruct(_s_8bd80a5b_helperGBuffer helperGBuffer, _s_8bd80a5b_index index, _s_8bd80a5b_optionalFile optionalFile, _s_8bd80a5b_optionalLine optionalLine, _s_8bd80a5b_optionalUserData optionalUserData, _s_8bd80a5b_rteParameters rteParameters) {
  return redRteHelperGBufferGetStruct(helperGBuffer.value, index.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetWidth redRteHelperGBufferGetWidth
#define _92a7098c_helperGBuffer(value) value
#define _92a7098c_optionalFile(value) value
#define _92a7098c_optionalLine(value) value
#define _92a7098c_optionalUserData(value) value
#define _92a7098c_rteParameters(value) value
#else
typedef struct _s_92a7098c_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_92a7098c_helperGBuffer;
typedef struct _s_92a7098c_optionalFile { char* value; } _s_92a7098c_optionalFile;
typedef struct _s_92a7098c_optionalLine { int value; } _s_92a7098c_optionalLine;
typedef struct _s_92a7098c_optionalUserData { void* value; } _s_92a7098c_optionalUserData;
typedef struct _s_92a7098c_rteParameters { void* value; } _s_92a7098c_rteParameters;
static inline _s_92a7098c_helperGBuffer _92a7098c_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_92a7098c_helperGBuffer){value}; }
static inline _s_92a7098c_optionalFile _92a7098c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_92a7098c_optionalFile){value}; }
static inline _s_92a7098c_optionalLine _92a7098c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_92a7098c_optionalLine){value}; }
static inline _s_92a7098c_optionalUserData _92a7098c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_92a7098c_optionalUserData){value}; }
static inline _s_92a7098c_rteParameters _92a7098c_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_92a7098c_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperGBufferGetWidth(_s_92a7098c_helperGBuffer helperGBuffer, _s_92a7098c_optionalFile optionalFile, _s_92a7098c_optionalLine optionalLine, _s_92a7098c_optionalUserData optionalUserData, _s_92a7098c_rteParameters rteParameters) {
  return redRteHelperGBufferGetWidth(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetHeight redRteHelperGBufferGetHeight
#define _ac39b6f2_helperGBuffer(value) value
#define _ac39b6f2_optionalFile(value) value
#define _ac39b6f2_optionalLine(value) value
#define _ac39b6f2_optionalUserData(value) value
#define _ac39b6f2_rteParameters(value) value
#else
typedef struct _s_ac39b6f2_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_ac39b6f2_helperGBuffer;
typedef struct _s_ac39b6f2_optionalFile { char* value; } _s_ac39b6f2_optionalFile;
typedef struct _s_ac39b6f2_optionalLine { int value; } _s_ac39b6f2_optionalLine;
typedef struct _s_ac39b6f2_optionalUserData { void* value; } _s_ac39b6f2_optionalUserData;
typedef struct _s_ac39b6f2_rteParameters { void* value; } _s_ac39b6f2_rteParameters;
static inline _s_ac39b6f2_helperGBuffer _ac39b6f2_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_ac39b6f2_helperGBuffer){value}; }
static inline _s_ac39b6f2_optionalFile _ac39b6f2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ac39b6f2_optionalFile){value}; }
static inline _s_ac39b6f2_optionalLine _ac39b6f2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ac39b6f2_optionalLine){value}; }
static inline _s_ac39b6f2_optionalUserData _ac39b6f2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ac39b6f2_optionalUserData){value}; }
static inline _s_ac39b6f2_rteParameters _ac39b6f2_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ac39b6f2_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperGBufferGetHeight(_s_ac39b6f2_helperGBuffer helperGBuffer, _s_ac39b6f2_optionalFile optionalFile, _s_ac39b6f2_optionalLine optionalLine, _s_ac39b6f2_optionalUserData optionalUserData, _s_ac39b6f2_rteParameters rteParameters) {
  return redRteHelperGBufferGetHeight(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetColorImage redRteHelperGBufferGetColorImage
#define _4044d4cc_helperGBuffer(value) value
#define _4044d4cc_index(value) value
#define _4044d4cc_optionalFile(value) value
#define _4044d4cc_optionalLine(value) value
#define _4044d4cc_optionalUserData(value) value
#define _4044d4cc_rteParameters(value) value
#else
typedef struct _s_4044d4cc_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_4044d4cc_helperGBuffer;
typedef struct _s_4044d4cc_index { unsigned value; } _s_4044d4cc_index;
typedef struct _s_4044d4cc_optionalFile { char* value; } _s_4044d4cc_optionalFile;
typedef struct _s_4044d4cc_optionalLine { int value; } _s_4044d4cc_optionalLine;
typedef struct _s_4044d4cc_optionalUserData { void* value; } _s_4044d4cc_optionalUserData;
typedef struct _s_4044d4cc_rteParameters { void* value; } _s_4044d4cc_rteParameters;
static inline _s_4044d4cc_helperGBuffer _4044d4cc_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_4044d4cc_helperGBuffer){value}; }
static inline _s_4044d4cc_index _4044d4cc_index(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4044d4cc_index){value}; }
static inline _s_4044d4cc_optionalFile _4044d4cc_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4044d4cc_optionalFile){value}; }
static inline _s_4044d4cc_optionalLine _4044d4cc_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4044d4cc_optionalLine){value}; }
static inline _s_4044d4cc_optionalUserData _4044d4cc_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4044d4cc_optionalUserData){value}; }
static inline _s_4044d4cc_rteParameters _4044d4cc_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4044d4cc_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleImage REDGPU_NP_API np_redRteHelperGBufferGetColorImage(_s_4044d4cc_helperGBuffer helperGBuffer, _s_4044d4cc_index index, _s_4044d4cc_optionalFile optionalFile, _s_4044d4cc_optionalLine optionalLine, _s_4044d4cc_optionalUserData optionalUserData, _s_4044d4cc_rteParameters rteParameters) {
  return redRteHelperGBufferGetColorImage(helperGBuffer.value, index.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetDepthImage redRteHelperGBufferGetDepthImage
#define _46f44520_helperGBuffer(value) value
#define _46f44520_optionalFile(value) value
#define _46f44520_optionalLine(value) value
#define _46f44520_optionalUserData(value) value
#define _46f44520_rteParameters(value) value
#else
typedef struct _s_46f44520_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_46f44520_helperGBuffer;
typedef struct _s_46f44520_optionalFile { char* value; } _s_46f44520_optionalFile;
typedef struct _s_46f44520_optionalLine { int value; } _s_46f44520_optionalLine;
typedef struct _s_46f44520_optionalUserData { void* value; } _s_46f44520_optionalUserData;
typedef struct _s_46f44520_rteParameters { void* value; } _s_46f44520_rteParameters;
static inline _s_46f44520_helperGBuffer _46f44520_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_46f44520_helperGBuffer){value}; }
static inline _s_46f44520_optionalFile _46f44520_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_46f44520_optionalFile){value}; }
static inline _s_46f44520_optionalLine _46f44520_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_46f44520_optionalLine){value}; }
static inline _s_46f44520_optionalUserData _46f44520_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_46f44520_optionalUserData){value}; }
static inline _s_46f44520_rteParameters _46f44520_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_46f44520_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleImage REDGPU_NP_API np_redRteHelperGBufferGetDepthImage(_s_46f44520_helperGBuffer helperGBuffer, _s_46f44520_optionalFile optionalFile, _s_46f44520_optionalLine optionalLine, _s_46f44520_optionalUserData optionalUserData, _s_46f44520_rteParameters rteParameters) {
  return redRteHelperGBufferGetDepthImage(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetStructMemberTexture redRteHelperGBufferGetStructMemberTexture
#define _aeb94277_helperGBuffer(value) value
#define _aeb94277_index(value) value
#define _aeb94277_outStructMemberTexture(value) value
#define _aeb94277_optionalFile(value) value
#define _aeb94277_optionalLine(value) value
#define _aeb94277_optionalUserData(value) value
#define _aeb94277_rteParameters(value) value
#else
typedef struct _s_aeb94277_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_aeb94277_helperGBuffer;
typedef struct _s_aeb94277_index { unsigned value; } _s_aeb94277_index;
typedef struct _s_aeb94277_outStructMemberTexture { RedStructMemberTexture* value; } _s_aeb94277_outStructMemberTexture;
typedef struct _s_aeb94277_optionalFile { char* value; } _s_aeb94277_optionalFile;
typedef struct _s_aeb94277_optionalLine { int value; } _s_aeb94277_optionalLine;
typedef struct _s_aeb94277_optionalUserData { void* value; } _s_aeb94277_optionalUserData;
typedef struct _s_aeb94277_rteParameters { void* value; } _s_aeb94277_rteParameters;
static inline _s_aeb94277_helperGBuffer _aeb94277_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_aeb94277_helperGBuffer){value}; }
static inline _s_aeb94277_index _aeb94277_index(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_aeb94277_index){value}; }
static inline _s_aeb94277_outStructMemberTexture _aeb94277_outStructMemberTexture(RedStructMemberTexture* value) { return REDGPU_NP_STRUCT_INIT(_s_aeb94277_outStructMemberTexture){value}; }
static inline _s_aeb94277_optionalFile _aeb94277_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_aeb94277_optionalFile){value}; }
static inline _s_aeb94277_optionalLine _aeb94277_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_aeb94277_optionalLine){value}; }
static inline _s_aeb94277_optionalUserData _aeb94277_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_aeb94277_optionalUserData){value}; }
static inline _s_aeb94277_rteParameters _aeb94277_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_aeb94277_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperGBufferGetStructMemberTexture(_s_aeb94277_helperGBuffer helperGBuffer, _s_aeb94277_index index, _s_aeb94277_outStructMemberTexture outStructMemberTexture, _s_aeb94277_optionalFile optionalFile, _s_aeb94277_optionalLine optionalLine, _s_aeb94277_optionalUserData optionalUserData, _s_aeb94277_rteParameters rteParameters) {
  return redRteHelperGBufferGetStructMemberTexture(helperGBuffer.value, index.value, outStructMemberTexture.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetColorTexture redRteHelperGBufferGetColorTexture
#define _b904279e_helperGBuffer(value) value
#define _b904279e_index(value) value
#define _b904279e_optionalFile(value) value
#define _b904279e_optionalLine(value) value
#define _b904279e_optionalUserData(value) value
#define _b904279e_rteParameters(value) value
#else
typedef struct _s_b904279e_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_b904279e_helperGBuffer;
typedef struct _s_b904279e_index { unsigned value; } _s_b904279e_index;
typedef struct _s_b904279e_optionalFile { char* value; } _s_b904279e_optionalFile;
typedef struct _s_b904279e_optionalLine { int value; } _s_b904279e_optionalLine;
typedef struct _s_b904279e_optionalUserData { void* value; } _s_b904279e_optionalUserData;
typedef struct _s_b904279e_rteParameters { void* value; } _s_b904279e_rteParameters;
static inline _s_b904279e_helperGBuffer _b904279e_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_b904279e_helperGBuffer){value}; }
static inline _s_b904279e_index _b904279e_index(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b904279e_index){value}; }
static inline _s_b904279e_optionalFile _b904279e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b904279e_optionalFile){value}; }
static inline _s_b904279e_optionalLine _b904279e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b904279e_optionalLine){value}; }
static inline _s_b904279e_optionalUserData _b904279e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b904279e_optionalUserData){value}; }
static inline _s_b904279e_rteParameters _b904279e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b904279e_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleTexture REDGPU_NP_API np_redRteHelperGBufferGetColorTexture(_s_b904279e_helperGBuffer helperGBuffer, _s_b904279e_index index, _s_b904279e_optionalFile optionalFile, _s_b904279e_optionalLine optionalLine, _s_b904279e_optionalUserData optionalUserData, _s_b904279e_rteParameters rteParameters) {
  return redRteHelperGBufferGetColorTexture(helperGBuffer.value, index.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetDepthTexture redRteHelperGBufferGetDepthTexture
#define _fece9577_helperGBuffer(value) value
#define _fece9577_optionalFile(value) value
#define _fece9577_optionalLine(value) value
#define _fece9577_optionalUserData(value) value
#define _fece9577_rteParameters(value) value
#else
typedef struct _s_fece9577_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_fece9577_helperGBuffer;
typedef struct _s_fece9577_optionalFile { char* value; } _s_fece9577_optionalFile;
typedef struct _s_fece9577_optionalLine { int value; } _s_fece9577_optionalLine;
typedef struct _s_fece9577_optionalUserData { void* value; } _s_fece9577_optionalUserData;
typedef struct _s_fece9577_rteParameters { void* value; } _s_fece9577_rteParameters;
static inline _s_fece9577_helperGBuffer _fece9577_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_fece9577_helperGBuffer){value}; }
static inline _s_fece9577_optionalFile _fece9577_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fece9577_optionalFile){value}; }
static inline _s_fece9577_optionalLine _fece9577_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fece9577_optionalLine){value}; }
static inline _s_fece9577_optionalUserData _fece9577_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fece9577_optionalUserData){value}; }
static inline _s_fece9577_rteParameters _fece9577_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fece9577_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleTexture REDGPU_NP_API np_redRteHelperGBufferGetDepthTexture(_s_fece9577_helperGBuffer helperGBuffer, _s_fece9577_optionalFile optionalFile, _s_fece9577_optionalLine optionalLine, _s_fece9577_optionalUserData optionalUserData, _s_fece9577_rteParameters rteParameters) {
  return redRteHelperGBufferGetDepthTexture(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetColorFormat redRteHelperGBufferGetColorFormat
#define _37109e36_helperGBuffer(value) value
#define _37109e36_index(value) value
#define _37109e36_optionalFile(value) value
#define _37109e36_optionalLine(value) value
#define _37109e36_optionalUserData(value) value
#define _37109e36_rteParameters(value) value
#else
typedef struct _s_37109e36_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_37109e36_helperGBuffer;
typedef struct _s_37109e36_index { unsigned value; } _s_37109e36_index;
typedef struct _s_37109e36_optionalFile { char* value; } _s_37109e36_optionalFile;
typedef struct _s_37109e36_optionalLine { int value; } _s_37109e36_optionalLine;
typedef struct _s_37109e36_optionalUserData { void* value; } _s_37109e36_optionalUserData;
typedef struct _s_37109e36_rteParameters { void* value; } _s_37109e36_rteParameters;
static inline _s_37109e36_helperGBuffer _37109e36_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_37109e36_helperGBuffer){value}; }
static inline _s_37109e36_index _37109e36_index(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_37109e36_index){value}; }
static inline _s_37109e36_optionalFile _37109e36_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_37109e36_optionalFile){value}; }
static inline _s_37109e36_optionalLine _37109e36_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_37109e36_optionalLine){value}; }
static inline _s_37109e36_optionalUserData _37109e36_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_37109e36_optionalUserData){value}; }
static inline _s_37109e36_rteParameters _37109e36_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_37109e36_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redRteHelperGBufferGetColorFormat(_s_37109e36_helperGBuffer helperGBuffer, _s_37109e36_index index, _s_37109e36_optionalFile optionalFile, _s_37109e36_optionalLine optionalLine, _s_37109e36_optionalUserData optionalUserData, _s_37109e36_rteParameters rteParameters) {
  return redRteHelperGBufferGetColorFormat(helperGBuffer.value, index.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetDepthFormat redRteHelperGBufferGetDepthFormat
#define _815c3c64_helperGBuffer(value) value
#define _815c3c64_optionalFile(value) value
#define _815c3c64_optionalLine(value) value
#define _815c3c64_optionalUserData(value) value
#define _815c3c64_rteParameters(value) value
#else
typedef struct _s_815c3c64_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_815c3c64_helperGBuffer;
typedef struct _s_815c3c64_optionalFile { char* value; } _s_815c3c64_optionalFile;
typedef struct _s_815c3c64_optionalLine { int value; } _s_815c3c64_optionalLine;
typedef struct _s_815c3c64_optionalUserData { void* value; } _s_815c3c64_optionalUserData;
typedef struct _s_815c3c64_rteParameters { void* value; } _s_815c3c64_rteParameters;
static inline _s_815c3c64_helperGBuffer _815c3c64_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_815c3c64_helperGBuffer){value}; }
static inline _s_815c3c64_optionalFile _815c3c64_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_815c3c64_optionalFile){value}; }
static inline _s_815c3c64_optionalLine _815c3c64_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_815c3c64_optionalLine){value}; }
static inline _s_815c3c64_optionalUserData _815c3c64_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_815c3c64_optionalUserData){value}; }
static inline _s_815c3c64_rteParameters _815c3c64_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_815c3c64_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redRteHelperGBufferGetDepthFormat(_s_815c3c64_helperGBuffer helperGBuffer, _s_815c3c64_optionalFile optionalFile, _s_815c3c64_optionalLine optionalLine, _s_815c3c64_optionalUserData optionalUserData, _s_815c3c64_rteParameters rteParameters) {
  return redRteHelperGBufferGetDepthFormat(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetAspectRatio redRteHelperGBufferGetAspectRatio
#define _3013eac0_helperGBuffer(value) value
#define _3013eac0_optionalFile(value) value
#define _3013eac0_optionalLine(value) value
#define _3013eac0_optionalUserData(value) value
#define _3013eac0_rteParameters(value) value
#else
typedef struct _s_3013eac0_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_3013eac0_helperGBuffer;
typedef struct _s_3013eac0_optionalFile { char* value; } _s_3013eac0_optionalFile;
typedef struct _s_3013eac0_optionalLine { int value; } _s_3013eac0_optionalLine;
typedef struct _s_3013eac0_optionalUserData { void* value; } _s_3013eac0_optionalUserData;
typedef struct _s_3013eac0_rteParameters { void* value; } _s_3013eac0_rteParameters;
static inline _s_3013eac0_helperGBuffer _3013eac0_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_3013eac0_helperGBuffer){value}; }
static inline _s_3013eac0_optionalFile _3013eac0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3013eac0_optionalFile){value}; }
static inline _s_3013eac0_optionalLine _3013eac0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3013eac0_optionalLine){value}; }
static inline _s_3013eac0_optionalUserData _3013eac0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3013eac0_optionalUserData){value}; }
static inline _s_3013eac0_rteParameters _3013eac0_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3013eac0_rteParameters){value}; }
REDGPU_NP_DECLSPEC float REDGPU_NP_API np_redRteHelperGBufferGetAspectRatio(_s_3013eac0_helperGBuffer helperGBuffer, _s_3013eac0_optionalFile optionalFile, _s_3013eac0_optionalLine optionalLine, _s_3013eac0_optionalUserData optionalUserData, _s_3013eac0_rteParameters rteParameters) {
  return redRteHelperGBufferGetAspectRatio(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteGpuWaitIdle redRteGpuWaitIdle
#define _b83d5a49_rteContext(value) value
#define _b83d5a49_optionalFile(value) value
#define _b83d5a49_optionalLine(value) value
#define _b83d5a49_optionalUserData(value) value
#define _b83d5a49_rteParameters(value) value
#else
typedef struct _s_b83d5a49_rteContext { RedRteHandleContext value; } _s_b83d5a49_rteContext;
typedef struct _s_b83d5a49_optionalFile { char* value; } _s_b83d5a49_optionalFile;
typedef struct _s_b83d5a49_optionalLine { int value; } _s_b83d5a49_optionalLine;
typedef struct _s_b83d5a49_optionalUserData { void* value; } _s_b83d5a49_optionalUserData;
typedef struct _s_b83d5a49_rteParameters { void* value; } _s_b83d5a49_rteParameters;
static inline _s_b83d5a49_rteContext _b83d5a49_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_b83d5a49_rteContext){value}; }
static inline _s_b83d5a49_optionalFile _b83d5a49_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b83d5a49_optionalFile){value}; }
static inline _s_b83d5a49_optionalLine _b83d5a49_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b83d5a49_optionalLine){value}; }
static inline _s_b83d5a49_optionalUserData _b83d5a49_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b83d5a49_optionalUserData){value}; }
static inline _s_b83d5a49_rteParameters _b83d5a49_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b83d5a49_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteGpuWaitIdle(_s_b83d5a49_rteContext rteContext, _s_b83d5a49_optionalFile optionalFile, _s_b83d5a49_optionalLine optionalLine, _s_b83d5a49_optionalUserData optionalUserData, _s_b83d5a49_rteParameters rteParameters) {
  return redRteGpuWaitIdle(rteContext.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteQueueWaitIdle redRteQueueWaitIdle
#define _e5c46d25_rteContext(value) value
#define _e5c46d25_queue(value) value
#define _e5c46d25_optionalFile(value) value
#define _e5c46d25_optionalLine(value) value
#define _e5c46d25_optionalUserData(value) value
#define _e5c46d25_rteParameters(value) value
#else
typedef struct _s_e5c46d25_rteContext { RedRteHandleContext value; } _s_e5c46d25_rteContext;
typedef struct _s_e5c46d25_queue { RedHandleQueue value; } _s_e5c46d25_queue;
typedef struct _s_e5c46d25_optionalFile { char* value; } _s_e5c46d25_optionalFile;
typedef struct _s_e5c46d25_optionalLine { int value; } _s_e5c46d25_optionalLine;
typedef struct _s_e5c46d25_optionalUserData { void* value; } _s_e5c46d25_optionalUserData;
typedef struct _s_e5c46d25_rteParameters { void* value; } _s_e5c46d25_rteParameters;
static inline _s_e5c46d25_rteContext _e5c46d25_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_e5c46d25_rteContext){value}; }
static inline _s_e5c46d25_queue _e5c46d25_queue(RedHandleQueue value) { return REDGPU_NP_STRUCT_INIT(_s_e5c46d25_queue){value}; }
static inline _s_e5c46d25_optionalFile _e5c46d25_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e5c46d25_optionalFile){value}; }
static inline _s_e5c46d25_optionalLine _e5c46d25_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e5c46d25_optionalLine){value}; }
static inline _s_e5c46d25_optionalUserData _e5c46d25_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e5c46d25_optionalUserData){value}; }
static inline _s_e5c46d25_rteParameters _e5c46d25_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e5c46d25_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteQueueWaitIdle(_s_e5c46d25_rteContext rteContext, _s_e5c46d25_queue queue, _s_e5c46d25_optionalFile optionalFile, _s_e5c46d25_optionalLine optionalLine, _s_e5c46d25_optionalUserData optionalUserData, _s_e5c46d25_rteParameters rteParameters) {
  return redRteQueueWaitIdle(rteContext.value, queue.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteArrayGetMemoryRequirements redRteArrayGetMemoryRequirements
#define _c4294edd_rteContext(value) value
#define _c4294edd_inoutArray(value) value
#define _c4294edd_optionalFile(value) value
#define _c4294edd_optionalLine(value) value
#define _c4294edd_optionalUserData(value) value
#define _c4294edd_rteParameters(value) value
#else
typedef struct _s_c4294edd_rteContext { RedRteHandleContext value; } _s_c4294edd_rteContext;
typedef struct _s_c4294edd_inoutArray { RedArray* value; } _s_c4294edd_inoutArray;
typedef struct _s_c4294edd_optionalFile { char* value; } _s_c4294edd_optionalFile;
typedef struct _s_c4294edd_optionalLine { int value; } _s_c4294edd_optionalLine;
typedef struct _s_c4294edd_optionalUserData { void* value; } _s_c4294edd_optionalUserData;
typedef struct _s_c4294edd_rteParameters { void* value; } _s_c4294edd_rteParameters;
static inline _s_c4294edd_rteContext _c4294edd_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_c4294edd_rteContext){value}; }
static inline _s_c4294edd_inoutArray _c4294edd_inoutArray(RedArray* value) { return REDGPU_NP_STRUCT_INIT(_s_c4294edd_inoutArray){value}; }
static inline _s_c4294edd_optionalFile _c4294edd_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c4294edd_optionalFile){value}; }
static inline _s_c4294edd_optionalLine _c4294edd_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c4294edd_optionalLine){value}; }
static inline _s_c4294edd_optionalUserData _c4294edd_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c4294edd_optionalUserData){value}; }
static inline _s_c4294edd_rteParameters _c4294edd_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c4294edd_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteArrayGetMemoryRequirements(_s_c4294edd_rteContext rteContext, _s_c4294edd_inoutArray inoutArray, _s_c4294edd_optionalFile optionalFile, _s_c4294edd_optionalLine optionalLine, _s_c4294edd_optionalUserData optionalUserData, _s_c4294edd_rteParameters rteParameters) {
  return redRteArrayGetMemoryRequirements(rteContext.value, inoutArray.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteImageGetMemoryRequirements redRteImageGetMemoryRequirements
#define _a8ee680e_rteContext(value) value
#define _a8ee680e_inoutImage(value) value
#define _a8ee680e_optionalFile(value) value
#define _a8ee680e_optionalLine(value) value
#define _a8ee680e_optionalUserData(value) value
#define _a8ee680e_rteParameters(value) value
#else
typedef struct _s_a8ee680e_rteContext { RedRteHandleContext value; } _s_a8ee680e_rteContext;
typedef struct _s_a8ee680e_inoutImage { RedImage* value; } _s_a8ee680e_inoutImage;
typedef struct _s_a8ee680e_optionalFile { char* value; } _s_a8ee680e_optionalFile;
typedef struct _s_a8ee680e_optionalLine { int value; } _s_a8ee680e_optionalLine;
typedef struct _s_a8ee680e_optionalUserData { void* value; } _s_a8ee680e_optionalUserData;
typedef struct _s_a8ee680e_rteParameters { void* value; } _s_a8ee680e_rteParameters;
static inline _s_a8ee680e_rteContext _a8ee680e_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_a8ee680e_rteContext){value}; }
static inline _s_a8ee680e_inoutImage _a8ee680e_inoutImage(RedImage* value) { return REDGPU_NP_STRUCT_INIT(_s_a8ee680e_inoutImage){value}; }
static inline _s_a8ee680e_optionalFile _a8ee680e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a8ee680e_optionalFile){value}; }
static inline _s_a8ee680e_optionalLine _a8ee680e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a8ee680e_optionalLine){value}; }
static inline _s_a8ee680e_optionalUserData _a8ee680e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a8ee680e_optionalUserData){value}; }
static inline _s_a8ee680e_rteParameters _a8ee680e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a8ee680e_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteImageGetMemoryRequirements(_s_a8ee680e_rteContext rteContext, _s_a8ee680e_inoutImage inoutImage, _s_a8ee680e_optionalFile optionalFile, _s_a8ee680e_optionalLine optionalLine, _s_a8ee680e_optionalUserData optionalUserData, _s_a8ee680e_rteParameters rteParameters) {
  return redRteImageGetMemoryRequirements(rteContext.value, inoutImage.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallUsageAliasOrderBarrier redRteCallUsageAliasOrderBarrier
#define _16fa6bd9_calls(value) value
#define _16fa6bd9_rteContext(value) value
#define _16fa6bd9_arrayUsagesCount(value) value
#define _16fa6bd9_arrayUsages(value) value
#define _16fa6bd9_imageUsagesCount(value) value
#define _16fa6bd9_imageUsages(value) value
#define _16fa6bd9_aliasesCount(value) value
#define _16fa6bd9_aliases(value) value
#define _16fa6bd9_ordersCount(value) value
#define _16fa6bd9_orders(value) value
#define _16fa6bd9_dependencyFlags(value) value
#else
typedef struct _s_16fa6bd9_calls { RedHandleCalls value; } _s_16fa6bd9_calls;
typedef struct _s_16fa6bd9_rteContext { RedRteHandleContext value; } _s_16fa6bd9_rteContext;
typedef struct _s_16fa6bd9_arrayUsagesCount { unsigned value; } _s_16fa6bd9_arrayUsagesCount;
typedef struct _s_16fa6bd9_arrayUsages { RedRteUsageArray* value; } _s_16fa6bd9_arrayUsages;
typedef struct _s_16fa6bd9_imageUsagesCount { unsigned value; } _s_16fa6bd9_imageUsagesCount;
typedef struct _s_16fa6bd9_imageUsages { RedRteUsageImage* value; } _s_16fa6bd9_imageUsages;
typedef struct _s_16fa6bd9_aliasesCount { unsigned value; } _s_16fa6bd9_aliasesCount;
typedef struct _s_16fa6bd9_aliases { RedAlias* value; } _s_16fa6bd9_aliases;
typedef struct _s_16fa6bd9_ordersCount { unsigned value; } _s_16fa6bd9_ordersCount;
typedef struct _s_16fa6bd9_orders { RedOrder* value; } _s_16fa6bd9_orders;
typedef struct _s_16fa6bd9_dependencyFlags { unsigned value; } _s_16fa6bd9_dependencyFlags;
static inline _s_16fa6bd9_calls _16fa6bd9_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_16fa6bd9_calls){value}; }
static inline _s_16fa6bd9_rteContext _16fa6bd9_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_16fa6bd9_rteContext){value}; }
static inline _s_16fa6bd9_arrayUsagesCount _16fa6bd9_arrayUsagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_16fa6bd9_arrayUsagesCount){value}; }
static inline _s_16fa6bd9_arrayUsages _16fa6bd9_arrayUsages(RedRteUsageArray* value) { return REDGPU_NP_STRUCT_INIT(_s_16fa6bd9_arrayUsages){value}; }
static inline _s_16fa6bd9_imageUsagesCount _16fa6bd9_imageUsagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_16fa6bd9_imageUsagesCount){value}; }
static inline _s_16fa6bd9_imageUsages _16fa6bd9_imageUsages(RedRteUsageImage* value) { return REDGPU_NP_STRUCT_INIT(_s_16fa6bd9_imageUsages){value}; }
static inline _s_16fa6bd9_aliasesCount _16fa6bd9_aliasesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_16fa6bd9_aliasesCount){value}; }
static inline _s_16fa6bd9_aliases _16fa6bd9_aliases(RedAlias* value) { return REDGPU_NP_STRUCT_INIT(_s_16fa6bd9_aliases){value}; }
static inline _s_16fa6bd9_ordersCount _16fa6bd9_ordersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_16fa6bd9_ordersCount){value}; }
static inline _s_16fa6bd9_orders _16fa6bd9_orders(RedOrder* value) { return REDGPU_NP_STRUCT_INIT(_s_16fa6bd9_orders){value}; }
static inline _s_16fa6bd9_dependencyFlags _16fa6bd9_dependencyFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_16fa6bd9_dependencyFlags){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallUsageAliasOrderBarrier(_s_16fa6bd9_calls calls, _s_16fa6bd9_rteContext rteContext, _s_16fa6bd9_arrayUsagesCount arrayUsagesCount, _s_16fa6bd9_arrayUsages arrayUsages, _s_16fa6bd9_imageUsagesCount imageUsagesCount, _s_16fa6bd9_imageUsages imageUsages, _s_16fa6bd9_aliasesCount aliasesCount, _s_16fa6bd9_aliases aliases, _s_16fa6bd9_ordersCount ordersCount, _s_16fa6bd9_orders orders, _s_16fa6bd9_dependencyFlags dependencyFlags) {
  return redRteCallUsageAliasOrderBarrier(calls.value, rteContext.value, arrayUsagesCount.value, arrayUsages.value, imageUsagesCount.value, imageUsages.value, aliasesCount.value, aliases.value, ordersCount.value, orders.value, dependencyFlags.value);
}
#endif

