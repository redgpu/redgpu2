#pragma once

#ifndef REDGPU_NP_STRUCT_INIT
#ifdef __cplusplus
#define REDGPU_NP_STRUCT_INIT(x) x
#else
#define REDGPU_NP_STRUCT_INIT(x) (x)
#endif
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateContext redRteCreateContext
#define _8eb9ebb1_mallocFn(value) value
#define _8eb9ebb1_freeFn(value) value
#define _8eb9ebb1_optionalMallocTagged(value) value
#define _8eb9ebb1_optionalFreeTagged(value) value
#define _8eb9ebb1_debugCallback(value) value
#define _8eb9ebb1_sdkVersion(value) value
#define _8eb9ebb1_sdkExtensionsCount(value) value
#define _8eb9ebb1_sdkExtensions(value) value
#define _8eb9ebb1_optionalProgramName(value) value
#define _8eb9ebb1_optionalProgramVersion(value) value
#define _8eb9ebb1_optionalEngineName(value) value
#define _8eb9ebb1_optionalEngineVersion(value) value
#define _8eb9ebb1_optionalSettings(value) value
#define _8eb9ebb1_outContext(value) value
#define _8eb9ebb1_outStatuses(value) value
#define _8eb9ebb1_optionalFile(value) value
#define _8eb9ebb1_optionalLine(value) value
#define _8eb9ebb1_optionalUserData(value) value
#define _8eb9ebb1_rteParameters(value) value
#else
typedef struct _s_8eb9ebb1_mallocFn { RedTypeProcedureMalloc value; } _s_8eb9ebb1_mallocFn;
typedef struct _s_8eb9ebb1_freeFn { RedTypeProcedureFree value; } _s_8eb9ebb1_freeFn;
typedef struct _s_8eb9ebb1_optionalMallocTagged { RedTypeProcedureMallocTagged value; } _s_8eb9ebb1_optionalMallocTagged;
typedef struct _s_8eb9ebb1_optionalFreeTagged { RedTypeProcedureFreeTagged value; } _s_8eb9ebb1_optionalFreeTagged;
typedef struct _s_8eb9ebb1_debugCallback { RedTypeProcedureDebugCallback value; } _s_8eb9ebb1_debugCallback;
typedef struct _s_8eb9ebb1_sdkVersion { RedSdkVersion value; } _s_8eb9ebb1_sdkVersion;
typedef struct _s_8eb9ebb1_sdkExtensionsCount { unsigned value; } _s_8eb9ebb1_sdkExtensionsCount;
typedef struct _s_8eb9ebb1_sdkExtensions { unsigned* value; } _s_8eb9ebb1_sdkExtensions;
typedef struct _s_8eb9ebb1_optionalProgramName { char* value; } _s_8eb9ebb1_optionalProgramName;
typedef struct _s_8eb9ebb1_optionalProgramVersion { unsigned value; } _s_8eb9ebb1_optionalProgramVersion;
typedef struct _s_8eb9ebb1_optionalEngineName { char* value; } _s_8eb9ebb1_optionalEngineName;
typedef struct _s_8eb9ebb1_optionalEngineVersion { unsigned value; } _s_8eb9ebb1_optionalEngineVersion;
typedef struct _s_8eb9ebb1_optionalSettings { void* value; } _s_8eb9ebb1_optionalSettings;
typedef struct _s_8eb9ebb1_outContext { RedContext* value; } _s_8eb9ebb1_outContext;
typedef struct _s_8eb9ebb1_outStatuses { RedStatuses* value; } _s_8eb9ebb1_outStatuses;
typedef struct _s_8eb9ebb1_optionalFile { char* value; } _s_8eb9ebb1_optionalFile;
typedef struct _s_8eb9ebb1_optionalLine { int value; } _s_8eb9ebb1_optionalLine;
typedef struct _s_8eb9ebb1_optionalUserData { void* value; } _s_8eb9ebb1_optionalUserData;
typedef struct _s_8eb9ebb1_rteParameters { RedRteCreateContextParameters* value; } _s_8eb9ebb1_rteParameters;
static inline _s_8eb9ebb1_mallocFn _8eb9ebb1_mallocFn(RedTypeProcedureMalloc value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_mallocFn){value}; }
static inline _s_8eb9ebb1_freeFn _8eb9ebb1_freeFn(RedTypeProcedureFree value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_freeFn){value}; }
static inline _s_8eb9ebb1_optionalMallocTagged _8eb9ebb1_optionalMallocTagged(RedTypeProcedureMallocTagged value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_optionalMallocTagged){value}; }
static inline _s_8eb9ebb1_optionalFreeTagged _8eb9ebb1_optionalFreeTagged(RedTypeProcedureFreeTagged value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_optionalFreeTagged){value}; }
static inline _s_8eb9ebb1_debugCallback _8eb9ebb1_debugCallback(RedTypeProcedureDebugCallback value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_debugCallback){value}; }
static inline _s_8eb9ebb1_sdkVersion _8eb9ebb1_sdkVersion(RedSdkVersion value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_sdkVersion){value}; }
static inline _s_8eb9ebb1_sdkExtensionsCount _8eb9ebb1_sdkExtensionsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_sdkExtensionsCount){value}; }
static inline _s_8eb9ebb1_sdkExtensions _8eb9ebb1_sdkExtensions(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_sdkExtensions){value}; }
static inline _s_8eb9ebb1_optionalProgramName _8eb9ebb1_optionalProgramName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_optionalProgramName){value}; }
static inline _s_8eb9ebb1_optionalProgramVersion _8eb9ebb1_optionalProgramVersion(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_optionalProgramVersion){value}; }
static inline _s_8eb9ebb1_optionalEngineName _8eb9ebb1_optionalEngineName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_optionalEngineName){value}; }
static inline _s_8eb9ebb1_optionalEngineVersion _8eb9ebb1_optionalEngineVersion(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_optionalEngineVersion){value}; }
static inline _s_8eb9ebb1_optionalSettings _8eb9ebb1_optionalSettings(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_optionalSettings){value}; }
static inline _s_8eb9ebb1_outContext _8eb9ebb1_outContext(RedContext* value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_outContext){value}; }
static inline _s_8eb9ebb1_outStatuses _8eb9ebb1_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_outStatuses){value}; }
static inline _s_8eb9ebb1_optionalFile _8eb9ebb1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_optionalFile){value}; }
static inline _s_8eb9ebb1_optionalLine _8eb9ebb1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_optionalLine){value}; }
static inline _s_8eb9ebb1_optionalUserData _8eb9ebb1_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_optionalUserData){value}; }
static inline _s_8eb9ebb1_rteParameters _8eb9ebb1_rteParameters(RedRteCreateContextParameters* value) { return REDGPU_NP_STRUCT_INIT(_s_8eb9ebb1_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateContext(_s_8eb9ebb1_mallocFn mallocFn, _s_8eb9ebb1_freeFn freeFn, _s_8eb9ebb1_optionalMallocTagged optionalMallocTagged, _s_8eb9ebb1_optionalFreeTagged optionalFreeTagged, _s_8eb9ebb1_debugCallback debugCallback, _s_8eb9ebb1_sdkVersion sdkVersion, _s_8eb9ebb1_sdkExtensionsCount sdkExtensionsCount, _s_8eb9ebb1_sdkExtensions sdkExtensions, _s_8eb9ebb1_optionalProgramName optionalProgramName, _s_8eb9ebb1_optionalProgramVersion optionalProgramVersion, _s_8eb9ebb1_optionalEngineName optionalEngineName, _s_8eb9ebb1_optionalEngineVersion optionalEngineVersion, _s_8eb9ebb1_optionalSettings optionalSettings, _s_8eb9ebb1_outContext outContext, _s_8eb9ebb1_outStatuses outStatuses, _s_8eb9ebb1_optionalFile optionalFile, _s_8eb9ebb1_optionalLine optionalLine, _s_8eb9ebb1_optionalUserData optionalUserData, _s_8eb9ebb1_rteParameters rteParameters) {
  return redRteCreateContext(mallocFn.value, freeFn.value, optionalMallocTagged.value, optionalFreeTagged.value, debugCallback.value, sdkVersion.value, sdkExtensionsCount.value, sdkExtensions.value, optionalProgramName.value, optionalProgramVersion.value, optionalEngineName.value, optionalEngineVersion.value, optionalSettings.value, outContext.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyContext redRteDestroyContext
#define _62900beb_context(value) value
#define _62900beb_optionalFile(value) value
#define _62900beb_optionalLine(value) value
#define _62900beb_optionalUserData(value) value
#define _62900beb_rteParameters(value) value
#else
typedef struct _s_62900beb_context { RedContext value; } _s_62900beb_context;
typedef struct _s_62900beb_optionalFile { char* value; } _s_62900beb_optionalFile;
typedef struct _s_62900beb_optionalLine { int value; } _s_62900beb_optionalLine;
typedef struct _s_62900beb_optionalUserData { void* value; } _s_62900beb_optionalUserData;
typedef struct _s_62900beb_rteParameters { RedRteDestroyContextParameters* value; } _s_62900beb_rteParameters;
static inline _s_62900beb_context _62900beb_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_62900beb_context){value}; }
static inline _s_62900beb_optionalFile _62900beb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_62900beb_optionalFile){value}; }
static inline _s_62900beb_optionalLine _62900beb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_62900beb_optionalLine){value}; }
static inline _s_62900beb_optionalUserData _62900beb_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_62900beb_optionalUserData){value}; }
static inline _s_62900beb_rteParameters _62900beb_rteParameters(RedRteDestroyContextParameters* value) { return REDGPU_NP_STRUCT_INIT(_s_62900beb_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyContext(_s_62900beb_context context, _s_62900beb_optionalFile optionalFile, _s_62900beb_optionalLine optionalLine, _s_62900beb_optionalUserData optionalUserData, _s_62900beb_rteParameters rteParameters) {
  return redRteDestroyContext(context.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateQueue redRteCreateQueue
#define _e7f2ae67_rteContext(value) value
#define _e7f2ae67_handleName(value) value
#define _e7f2ae67_queueFlags(value) value
#define _e7f2ae67_queuePriority(value) value
#define _e7f2ae67_outRteQueue(value) value
#define _e7f2ae67_outStatuses(value) value
#define _e7f2ae67_optionalFile(value) value
#define _e7f2ae67_optionalLine(value) value
#define _e7f2ae67_optionalUserData(value) value
#define _e7f2ae67_rteParameters(value) value
#else
typedef struct _s_e7f2ae67_rteContext { RedRteHandleContext value; } _s_e7f2ae67_rteContext;
typedef struct _s_e7f2ae67_handleName { char* value; } _s_e7f2ae67_handleName;
typedef struct _s_e7f2ae67_queueFlags { RedRteQueueBitflags value; } _s_e7f2ae67_queueFlags;
typedef struct _s_e7f2ae67_queuePriority { float value; } _s_e7f2ae67_queuePriority;
typedef struct _s_e7f2ae67_outRteQueue { RedRteQueue* value; } _s_e7f2ae67_outRteQueue;
typedef struct _s_e7f2ae67_outStatuses { RedStatuses* value; } _s_e7f2ae67_outStatuses;
typedef struct _s_e7f2ae67_optionalFile { char* value; } _s_e7f2ae67_optionalFile;
typedef struct _s_e7f2ae67_optionalLine { int value; } _s_e7f2ae67_optionalLine;
typedef struct _s_e7f2ae67_optionalUserData { void* value; } _s_e7f2ae67_optionalUserData;
typedef struct _s_e7f2ae67_rteParameters { void* value; } _s_e7f2ae67_rteParameters;
static inline _s_e7f2ae67_rteContext _e7f2ae67_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_e7f2ae67_rteContext){value}; }
static inline _s_e7f2ae67_handleName _e7f2ae67_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e7f2ae67_handleName){value}; }
static inline _s_e7f2ae67_queueFlags _e7f2ae67_queueFlags(RedRteQueueBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_e7f2ae67_queueFlags){value}; }
static inline _s_e7f2ae67_queuePriority _e7f2ae67_queuePriority(float value) { return REDGPU_NP_STRUCT_INIT(_s_e7f2ae67_queuePriority){value}; }
static inline _s_e7f2ae67_outRteQueue _e7f2ae67_outRteQueue(RedRteQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_e7f2ae67_outRteQueue){value}; }
static inline _s_e7f2ae67_outStatuses _e7f2ae67_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_e7f2ae67_outStatuses){value}; }
static inline _s_e7f2ae67_optionalFile _e7f2ae67_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e7f2ae67_optionalFile){value}; }
static inline _s_e7f2ae67_optionalLine _e7f2ae67_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e7f2ae67_optionalLine){value}; }
static inline _s_e7f2ae67_optionalUserData _e7f2ae67_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e7f2ae67_optionalUserData){value}; }
static inline _s_e7f2ae67_rteParameters _e7f2ae67_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e7f2ae67_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateQueue(_s_e7f2ae67_rteContext rteContext, _s_e7f2ae67_handleName handleName, _s_e7f2ae67_queueFlags queueFlags, _s_e7f2ae67_queuePriority queuePriority, _s_e7f2ae67_outRteQueue outRteQueue, _s_e7f2ae67_outStatuses outStatuses, _s_e7f2ae67_optionalFile optionalFile, _s_e7f2ae67_optionalLine optionalLine, _s_e7f2ae67_optionalUserData optionalUserData, _s_e7f2ae67_rteParameters rteParameters) {
  return redRteCreateQueue(rteContext.value, handleName.value, queueFlags.value, queuePriority.value, outRteQueue.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteArrayGetGpuAddress redRteArrayGetGpuAddress
#define _b26a51cd_rteContext(value) value
#define _b26a51cd_gpu(value) value
#define _b26a51cd_array(value) value
#define _b26a51cd_optionalFile(value) value
#define _b26a51cd_optionalLine(value) value
#define _b26a51cd_optionalUserData(value) value
#define _b26a51cd_rteParameters(value) value
#else
typedef struct _s_b26a51cd_rteContext { RedRteHandleContext value; } _s_b26a51cd_rteContext;
typedef struct _s_b26a51cd_gpu { RedHandleGpu value; } _s_b26a51cd_gpu;
typedef struct _s_b26a51cd_array { RedHandleArray value; } _s_b26a51cd_array;
typedef struct _s_b26a51cd_optionalFile { char* value; } _s_b26a51cd_optionalFile;
typedef struct _s_b26a51cd_optionalLine { int value; } _s_b26a51cd_optionalLine;
typedef struct _s_b26a51cd_optionalUserData { void* value; } _s_b26a51cd_optionalUserData;
typedef struct _s_b26a51cd_rteParameters { void* value; } _s_b26a51cd_rteParameters;
static inline _s_b26a51cd_rteContext _b26a51cd_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_b26a51cd_rteContext){value}; }
static inline _s_b26a51cd_gpu _b26a51cd_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b26a51cd_gpu){value}; }
static inline _s_b26a51cd_array _b26a51cd_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_b26a51cd_array){value}; }
static inline _s_b26a51cd_optionalFile _b26a51cd_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b26a51cd_optionalFile){value}; }
static inline _s_b26a51cd_optionalLine _b26a51cd_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b26a51cd_optionalLine){value}; }
static inline _s_b26a51cd_optionalUserData _b26a51cd_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b26a51cd_optionalUserData){value}; }
static inline _s_b26a51cd_rteParameters _b26a51cd_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b26a51cd_rteParameters){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redRteArrayGetGpuAddress(_s_b26a51cd_rteContext rteContext, _s_b26a51cd_gpu gpu, _s_b26a51cd_array array, _s_b26a51cd_optionalFile optionalFile, _s_b26a51cd_optionalLine optionalLine, _s_b26a51cd_optionalUserData optionalUserData, _s_b26a51cd_rteParameters rteParameters) {
  return redRteArrayGetGpuAddress(rteContext.value, gpu.value, array.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateHelperAllocatorDma redRteCreateHelperAllocatorDma
#define _f87e32fa_rteContext(value) value
#define _f87e32fa_outHelperAllocatorDma(value) value
#define _f87e32fa_outStatuses(value) value
#define _f87e32fa_optionalFile(value) value
#define _f87e32fa_optionalLine(value) value
#define _f87e32fa_optionalUserData(value) value
#define _f87e32fa_rteParameters(value) value
#else
typedef struct _s_f87e32fa_rteContext { RedRteHandleContext value; } _s_f87e32fa_rteContext;
typedef struct _s_f87e32fa_outHelperAllocatorDma { RedRteHandleHelperAllocatorDma* value; } _s_f87e32fa_outHelperAllocatorDma;
typedef struct _s_f87e32fa_outStatuses { RedStatuses* value; } _s_f87e32fa_outStatuses;
typedef struct _s_f87e32fa_optionalFile { char* value; } _s_f87e32fa_optionalFile;
typedef struct _s_f87e32fa_optionalLine { int value; } _s_f87e32fa_optionalLine;
typedef struct _s_f87e32fa_optionalUserData { void* value; } _s_f87e32fa_optionalUserData;
typedef struct _s_f87e32fa_rteParameters { void* value; } _s_f87e32fa_rteParameters;
static inline _s_f87e32fa_rteContext _f87e32fa_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_f87e32fa_rteContext){value}; }
static inline _s_f87e32fa_outHelperAllocatorDma _f87e32fa_outHelperAllocatorDma(RedRteHandleHelperAllocatorDma* value) { return REDGPU_NP_STRUCT_INIT(_s_f87e32fa_outHelperAllocatorDma){value}; }
static inline _s_f87e32fa_outStatuses _f87e32fa_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_f87e32fa_outStatuses){value}; }
static inline _s_f87e32fa_optionalFile _f87e32fa_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f87e32fa_optionalFile){value}; }
static inline _s_f87e32fa_optionalLine _f87e32fa_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f87e32fa_optionalLine){value}; }
static inline _s_f87e32fa_optionalUserData _f87e32fa_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f87e32fa_optionalUserData){value}; }
static inline _s_f87e32fa_rteParameters _f87e32fa_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f87e32fa_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateHelperAllocatorDma(_s_f87e32fa_rteContext rteContext, _s_f87e32fa_outHelperAllocatorDma outHelperAllocatorDma, _s_f87e32fa_outStatuses outStatuses, _s_f87e32fa_optionalFile optionalFile, _s_f87e32fa_optionalLine optionalLine, _s_f87e32fa_optionalUserData optionalUserData, _s_f87e32fa_rteParameters rteParameters) {
  return redRteCreateHelperAllocatorDma(rteContext.value, outHelperAllocatorDma.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyHelperAllocatorDma redRteDestroyHelperAllocatorDma
#define _48a43801_helperAllocatorDma(value) value
#define _48a43801_optionalFile(value) value
#define _48a43801_optionalLine(value) value
#define _48a43801_optionalUserData(value) value
#define _48a43801_rteParameters(value) value
#else
typedef struct _s_48a43801_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_48a43801_helperAllocatorDma;
typedef struct _s_48a43801_optionalFile { char* value; } _s_48a43801_optionalFile;
typedef struct _s_48a43801_optionalLine { int value; } _s_48a43801_optionalLine;
typedef struct _s_48a43801_optionalUserData { void* value; } _s_48a43801_optionalUserData;
typedef struct _s_48a43801_rteParameters { void* value; } _s_48a43801_rteParameters;
static inline _s_48a43801_helperAllocatorDma _48a43801_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_48a43801_helperAllocatorDma){value}; }
static inline _s_48a43801_optionalFile _48a43801_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_48a43801_optionalFile){value}; }
static inline _s_48a43801_optionalLine _48a43801_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_48a43801_optionalLine){value}; }
static inline _s_48a43801_optionalUserData _48a43801_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_48a43801_optionalUserData){value}; }
static inline _s_48a43801_rteParameters _48a43801_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_48a43801_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyHelperAllocatorDma(_s_48a43801_helperAllocatorDma helperAllocatorDma, _s_48a43801_optionalFile optionalFile, _s_48a43801_optionalLine optionalLine, _s_48a43801_optionalUserData optionalUserData, _s_48a43801_rteParameters rteParameters) {
  return redRteDestroyHelperAllocatorDma(helperAllocatorDma.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaCreateArray redRteHelperAllocatorDmaCreateArray
#define _ff39da19_helperAllocatorDma(value) value
#define _ff39da19_arrayInfo(value) value
#define _ff39da19_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _ff39da19_outRteHelperArray(value) value
#define _ff39da19_outStatuses(value) value
#define _ff39da19_optionalFile(value) value
#define _ff39da19_optionalLine(value) value
#define _ff39da19_optionalUserData(value) value
#define _ff39da19_rteParameters(value) value
#else
typedef struct _s_ff39da19_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_ff39da19_helperAllocatorDma;
typedef struct _s_ff39da19_arrayInfo { RedRteHelperCreateArrayInfo* value; } _s_ff39da19_arrayInfo;
typedef struct _s_ff39da19_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_ff39da19_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_ff39da19_outRteHelperArray { RedRteHelperArray* value; } _s_ff39da19_outRteHelperArray;
typedef struct _s_ff39da19_outStatuses { RedStatuses* value; } _s_ff39da19_outStatuses;
typedef struct _s_ff39da19_optionalFile { char* value; } _s_ff39da19_optionalFile;
typedef struct _s_ff39da19_optionalLine { int value; } _s_ff39da19_optionalLine;
typedef struct _s_ff39da19_optionalUserData { void* value; } _s_ff39da19_optionalUserData;
typedef struct _s_ff39da19_rteParameters { void* value; } _s_ff39da19_rteParameters;
static inline _s_ff39da19_helperAllocatorDma _ff39da19_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_ff39da19_helperAllocatorDma){value}; }
static inline _s_ff39da19_arrayInfo _ff39da19_arrayInfo(RedRteHelperCreateArrayInfo* value) { return REDGPU_NP_STRUCT_INIT(_s_ff39da19_arrayInfo){value}; }
static inline _s_ff39da19_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _ff39da19_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ff39da19_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_ff39da19_outRteHelperArray _ff39da19_outRteHelperArray(RedRteHelperArray* value) { return REDGPU_NP_STRUCT_INIT(_s_ff39da19_outRteHelperArray){value}; }
static inline _s_ff39da19_outStatuses _ff39da19_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_ff39da19_outStatuses){value}; }
static inline _s_ff39da19_optionalFile _ff39da19_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ff39da19_optionalFile){value}; }
static inline _s_ff39da19_optionalLine _ff39da19_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ff39da19_optionalLine){value}; }
static inline _s_ff39da19_optionalUserData _ff39da19_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ff39da19_optionalUserData){value}; }
static inline _s_ff39da19_rteParameters _ff39da19_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ff39da19_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaCreateArray(_s_ff39da19_helperAllocatorDma helperAllocatorDma, _s_ff39da19_arrayInfo arrayInfo, _s_ff39da19_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_ff39da19_outRteHelperArray outRteHelperArray, _s_ff39da19_outStatuses outStatuses, _s_ff39da19_optionalFile optionalFile, _s_ff39da19_optionalLine optionalLine, _s_ff39da19_optionalUserData optionalUserData, _s_ff39da19_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaCreateArray(helperAllocatorDma.value, arrayInfo.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaCreateImage redRteHelperAllocatorDmaCreateImage
#define _c7318ff7_helperAllocatorDma(value) value
#define _c7318ff7_imageInfo(value) value
#define _c7318ff7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _c7318ff7_outRteHelperImage(value) value
#define _c7318ff7_outStatuses(value) value
#define _c7318ff7_optionalFile(value) value
#define _c7318ff7_optionalLine(value) value
#define _c7318ff7_optionalUserData(value) value
#define _c7318ff7_rteParameters(value) value
#else
typedef struct _s_c7318ff7_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_c7318ff7_helperAllocatorDma;
typedef struct _s_c7318ff7_imageInfo { RedRteHelperCreateImageInfo* value; } _s_c7318ff7_imageInfo;
typedef struct _s_c7318ff7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_c7318ff7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_c7318ff7_outRteHelperImage { RedRteHelperImage* value; } _s_c7318ff7_outRteHelperImage;
typedef struct _s_c7318ff7_outStatuses { RedStatuses* value; } _s_c7318ff7_outStatuses;
typedef struct _s_c7318ff7_optionalFile { char* value; } _s_c7318ff7_optionalFile;
typedef struct _s_c7318ff7_optionalLine { int value; } _s_c7318ff7_optionalLine;
typedef struct _s_c7318ff7_optionalUserData { void* value; } _s_c7318ff7_optionalUserData;
typedef struct _s_c7318ff7_rteParameters { void* value; } _s_c7318ff7_rteParameters;
static inline _s_c7318ff7_helperAllocatorDma _c7318ff7_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_c7318ff7_helperAllocatorDma){value}; }
static inline _s_c7318ff7_imageInfo _c7318ff7_imageInfo(RedRteHelperCreateImageInfo* value) { return REDGPU_NP_STRUCT_INIT(_s_c7318ff7_imageInfo){value}; }
static inline _s_c7318ff7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _c7318ff7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c7318ff7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_c7318ff7_outRteHelperImage _c7318ff7_outRteHelperImage(RedRteHelperImage* value) { return REDGPU_NP_STRUCT_INIT(_s_c7318ff7_outRteHelperImage){value}; }
static inline _s_c7318ff7_outStatuses _c7318ff7_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_c7318ff7_outStatuses){value}; }
static inline _s_c7318ff7_optionalFile _c7318ff7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c7318ff7_optionalFile){value}; }
static inline _s_c7318ff7_optionalLine _c7318ff7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c7318ff7_optionalLine){value}; }
static inline _s_c7318ff7_optionalUserData _c7318ff7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c7318ff7_optionalUserData){value}; }
static inline _s_c7318ff7_rteParameters _c7318ff7_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c7318ff7_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaCreateImage(_s_c7318ff7_helperAllocatorDma helperAllocatorDma, _s_c7318ff7_imageInfo imageInfo, _s_c7318ff7_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_c7318ff7_outRteHelperImage outRteHelperImage, _s_c7318ff7_outStatuses outStatuses, _s_c7318ff7_optionalFile optionalFile, _s_c7318ff7_optionalLine optionalLine, _s_c7318ff7_optionalUserData optionalUserData, _s_c7318ff7_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaCreateImage(helperAllocatorDma.value, imageInfo.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperImage.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaCreateArraySimple redRteHelperAllocatorDmaCreateArraySimple
#define _765b845c_helperAllocatorDma(value) value
#define _765b845c_arrayBytesCount(value) value
#define _765b845c_arrayUsageFlags(value) value
#define _765b845c_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _765b845c_outRteHelperArray(value) value
#define _765b845c_outStatuses(value) value
#define _765b845c_optionalFile(value) value
#define _765b845c_optionalLine(value) value
#define _765b845c_optionalUserData(value) value
#define _765b845c_rteParameters(value) value
#else
typedef struct _s_765b845c_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_765b845c_helperAllocatorDma;
typedef struct _s_765b845c_arrayBytesCount { uint64_t value; } _s_765b845c_arrayBytesCount;
typedef struct _s_765b845c_arrayUsageFlags { unsigned value; } _s_765b845c_arrayUsageFlags;
typedef struct _s_765b845c_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_765b845c_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_765b845c_outRteHelperArray { RedRteHelperArray* value; } _s_765b845c_outRteHelperArray;
typedef struct _s_765b845c_outStatuses { RedStatuses* value; } _s_765b845c_outStatuses;
typedef struct _s_765b845c_optionalFile { char* value; } _s_765b845c_optionalFile;
typedef struct _s_765b845c_optionalLine { int value; } _s_765b845c_optionalLine;
typedef struct _s_765b845c_optionalUserData { void* value; } _s_765b845c_optionalUserData;
typedef struct _s_765b845c_rteParameters { void* value; } _s_765b845c_rteParameters;
static inline _s_765b845c_helperAllocatorDma _765b845c_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_765b845c_helperAllocatorDma){value}; }
static inline _s_765b845c_arrayBytesCount _765b845c_arrayBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_765b845c_arrayBytesCount){value}; }
static inline _s_765b845c_arrayUsageFlags _765b845c_arrayUsageFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_765b845c_arrayUsageFlags){value}; }
static inline _s_765b845c_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _765b845c_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_765b845c_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_765b845c_outRteHelperArray _765b845c_outRteHelperArray(RedRteHelperArray* value) { return REDGPU_NP_STRUCT_INIT(_s_765b845c_outRteHelperArray){value}; }
static inline _s_765b845c_outStatuses _765b845c_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_765b845c_outStatuses){value}; }
static inline _s_765b845c_optionalFile _765b845c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_765b845c_optionalFile){value}; }
static inline _s_765b845c_optionalLine _765b845c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_765b845c_optionalLine){value}; }
static inline _s_765b845c_optionalUserData _765b845c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_765b845c_optionalUserData){value}; }
static inline _s_765b845c_rteParameters _765b845c_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_765b845c_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaCreateArraySimple(_s_765b845c_helperAllocatorDma helperAllocatorDma, _s_765b845c_arrayBytesCount arrayBytesCount, _s_765b845c_arrayUsageFlags arrayUsageFlags, _s_765b845c_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_765b845c_outRteHelperArray outRteHelperArray, _s_765b845c_outStatuses outStatuses, _s_765b845c_optionalFile optionalFile, _s_765b845c_optionalLine optionalLine, _s_765b845c_optionalUserData optionalUserData, _s_765b845c_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaCreateArraySimple(helperAllocatorDma.value, arrayBytesCount.value, arrayUsageFlags.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaCreateArraySimpleWithData redRteHelperAllocatorDmaCreateArraySimpleWithData
#define _cf008017_helperAllocatorDma(value) value
#define _cf008017_callsSetToUploadArrayData(value) value
#define _cf008017_arrayDataBytesCount(value) value
#define _cf008017_arrayData(value) value
#define _cf008017_arrayUsageFlags(value) value
#define _cf008017_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _cf008017_outRteHelperArray(value) value
#define _cf008017_outStatuses(value) value
#define _cf008017_optionalFile(value) value
#define _cf008017_optionalLine(value) value
#define _cf008017_optionalUserData(value) value
#define _cf008017_rteParameters(value) value
#else
typedef struct _s_cf008017_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_cf008017_helperAllocatorDma;
typedef struct _s_cf008017_callsSetToUploadArrayData { RedHandleCalls value; } _s_cf008017_callsSetToUploadArrayData;
typedef struct _s_cf008017_arrayDataBytesCount { uint64_t value; } _s_cf008017_arrayDataBytesCount;
typedef struct _s_cf008017_arrayData { void* value; } _s_cf008017_arrayData;
typedef struct _s_cf008017_arrayUsageFlags { unsigned value; } _s_cf008017_arrayUsageFlags;
typedef struct _s_cf008017_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_cf008017_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_cf008017_outRteHelperArray { RedRteHelperArray* value; } _s_cf008017_outRteHelperArray;
typedef struct _s_cf008017_outStatuses { RedStatuses* value; } _s_cf008017_outStatuses;
typedef struct _s_cf008017_optionalFile { char* value; } _s_cf008017_optionalFile;
typedef struct _s_cf008017_optionalLine { int value; } _s_cf008017_optionalLine;
typedef struct _s_cf008017_optionalUserData { void* value; } _s_cf008017_optionalUserData;
typedef struct _s_cf008017_rteParameters { void* value; } _s_cf008017_rteParameters;
static inline _s_cf008017_helperAllocatorDma _cf008017_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_cf008017_helperAllocatorDma){value}; }
static inline _s_cf008017_callsSetToUploadArrayData _cf008017_callsSetToUploadArrayData(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_cf008017_callsSetToUploadArrayData){value}; }
static inline _s_cf008017_arrayDataBytesCount _cf008017_arrayDataBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_cf008017_arrayDataBytesCount){value}; }
static inline _s_cf008017_arrayData _cf008017_arrayData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cf008017_arrayData){value}; }
static inline _s_cf008017_arrayUsageFlags _cf008017_arrayUsageFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cf008017_arrayUsageFlags){value}; }
static inline _s_cf008017_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _cf008017_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cf008017_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_cf008017_outRteHelperArray _cf008017_outRteHelperArray(RedRteHelperArray* value) { return REDGPU_NP_STRUCT_INIT(_s_cf008017_outRteHelperArray){value}; }
static inline _s_cf008017_outStatuses _cf008017_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_cf008017_outStatuses){value}; }
static inline _s_cf008017_optionalFile _cf008017_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cf008017_optionalFile){value}; }
static inline _s_cf008017_optionalLine _cf008017_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cf008017_optionalLine){value}; }
static inline _s_cf008017_optionalUserData _cf008017_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cf008017_optionalUserData){value}; }
static inline _s_cf008017_rteParameters _cf008017_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cf008017_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaCreateArraySimpleWithData(_s_cf008017_helperAllocatorDma helperAllocatorDma, _s_cf008017_callsSetToUploadArrayData callsSetToUploadArrayData, _s_cf008017_arrayDataBytesCount arrayDataBytesCount, _s_cf008017_arrayData arrayData, _s_cf008017_arrayUsageFlags arrayUsageFlags, _s_cf008017_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_cf008017_outRteHelperArray outRteHelperArray, _s_cf008017_outStatuses outStatuses, _s_cf008017_optionalFile optionalFile, _s_cf008017_optionalLine optionalLine, _s_cf008017_optionalUserData optionalUserData, _s_cf008017_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaCreateArraySimpleWithData(helperAllocatorDma.value, callsSetToUploadArrayData.value, arrayDataBytesCount.value, arrayData.value, arrayUsageFlags.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaCreateImageSimpleWithData redRteHelperAllocatorDmaCreateImageSimpleWithData
#define _051df26b_helperAllocatorDma(value) value
#define _051df26b_callsSetToUploadImageData(value) value
#define _051df26b_imageDataBytesCount(value) value
#define _051df26b_imageData(value) value
#define _051df26b_imageInfo(value) value
#define _051df26b_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral(value) value
#define _051df26b_outRteHelperImage(value) value
#define _051df26b_outStatuses(value) value
#define _051df26b_optionalFile(value) value
#define _051df26b_optionalLine(value) value
#define _051df26b_optionalUserData(value) value
#define _051df26b_rteParameters(value) value
#else
typedef struct _s_051df26b_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_051df26b_helperAllocatorDma;
typedef struct _s_051df26b_callsSetToUploadImageData { RedHandleCalls value; } _s_051df26b_callsSetToUploadImageData;
typedef struct _s_051df26b_imageDataBytesCount { uint64_t value; } _s_051df26b_imageDataBytesCount;
typedef struct _s_051df26b_imageData { void* value; } _s_051df26b_imageData;
typedef struct _s_051df26b_imageInfo { RedRteHelperCreateImageInfo* value; } _s_051df26b_imageInfo;
typedef struct _s_051df26b_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral { unsigned value; } _s_051df26b_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral;
typedef struct _s_051df26b_outRteHelperImage { RedRteHelperImage* value; } _s_051df26b_outRteHelperImage;
typedef struct _s_051df26b_outStatuses { RedStatuses* value; } _s_051df26b_outStatuses;
typedef struct _s_051df26b_optionalFile { char* value; } _s_051df26b_optionalFile;
typedef struct _s_051df26b_optionalLine { int value; } _s_051df26b_optionalLine;
typedef struct _s_051df26b_optionalUserData { void* value; } _s_051df26b_optionalUserData;
typedef struct _s_051df26b_rteParameters { void* value; } _s_051df26b_rteParameters;
static inline _s_051df26b_helperAllocatorDma _051df26b_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_051df26b_helperAllocatorDma){value}; }
static inline _s_051df26b_callsSetToUploadImageData _051df26b_callsSetToUploadImageData(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_051df26b_callsSetToUploadImageData){value}; }
static inline _s_051df26b_imageDataBytesCount _051df26b_imageDataBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_051df26b_imageDataBytesCount){value}; }
static inline _s_051df26b_imageData _051df26b_imageData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_051df26b_imageData){value}; }
static inline _s_051df26b_imageInfo _051df26b_imageInfo(RedRteHelperCreateImageInfo* value) { return REDGPU_NP_STRUCT_INIT(_s_051df26b_imageInfo){value}; }
static inline _s_051df26b_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral _051df26b_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_051df26b_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral){value}; }
static inline _s_051df26b_outRteHelperImage _051df26b_outRteHelperImage(RedRteHelperImage* value) { return REDGPU_NP_STRUCT_INIT(_s_051df26b_outRteHelperImage){value}; }
static inline _s_051df26b_outStatuses _051df26b_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_051df26b_outStatuses){value}; }
static inline _s_051df26b_optionalFile _051df26b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_051df26b_optionalFile){value}; }
static inline _s_051df26b_optionalLine _051df26b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_051df26b_optionalLine){value}; }
static inline _s_051df26b_optionalUserData _051df26b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_051df26b_optionalUserData){value}; }
static inline _s_051df26b_rteParameters _051df26b_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_051df26b_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaCreateImageSimpleWithData(_s_051df26b_helperAllocatorDma helperAllocatorDma, _s_051df26b_callsSetToUploadImageData callsSetToUploadImageData, _s_051df26b_imageDataBytesCount imageDataBytesCount, _s_051df26b_imageData imageData, _s_051df26b_imageInfo imageInfo, _s_051df26b_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral imageLayoutSuggestedDefaultValueIsImageLayoutGeneral, _s_051df26b_outRteHelperImage outRteHelperImage, _s_051df26b_outStatuses outStatuses, _s_051df26b_optionalFile optionalFile, _s_051df26b_optionalLine optionalLine, _s_051df26b_optionalUserData optionalUserData, _s_051df26b_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaCreateImageSimpleWithData(helperAllocatorDma.value, callsSetToUploadImageData.value, imageDataBytesCount.value, imageData.value, imageInfo.value, imageLayoutSuggestedDefaultValueIsImageLayoutGeneral.value, outRteHelperImage.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaDestroyArray redRteHelperAllocatorDmaDestroyArray
#define _99d19c80_helperAllocatorDma(value) value
#define _99d19c80_rteHelperArray(value) value
#define _99d19c80_rteHelperAllocatorResourceMemory(value) value
#define _99d19c80_outStatuses(value) value
#define _99d19c80_optionalFile(value) value
#define _99d19c80_optionalLine(value) value
#define _99d19c80_optionalUserData(value) value
#define _99d19c80_rteParameters(value) value
#else
typedef struct _s_99d19c80_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_99d19c80_helperAllocatorDma;
typedef struct _s_99d19c80_rteHelperArray { RedHandleArray value; } _s_99d19c80_rteHelperArray;
typedef struct _s_99d19c80_rteHelperAllocatorResourceMemory { void* value; } _s_99d19c80_rteHelperAllocatorResourceMemory;
typedef struct _s_99d19c80_outStatuses { RedStatuses* value; } _s_99d19c80_outStatuses;
typedef struct _s_99d19c80_optionalFile { char* value; } _s_99d19c80_optionalFile;
typedef struct _s_99d19c80_optionalLine { int value; } _s_99d19c80_optionalLine;
typedef struct _s_99d19c80_optionalUserData { void* value; } _s_99d19c80_optionalUserData;
typedef struct _s_99d19c80_rteParameters { void* value; } _s_99d19c80_rteParameters;
static inline _s_99d19c80_helperAllocatorDma _99d19c80_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_99d19c80_helperAllocatorDma){value}; }
static inline _s_99d19c80_rteHelperArray _99d19c80_rteHelperArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_99d19c80_rteHelperArray){value}; }
static inline _s_99d19c80_rteHelperAllocatorResourceMemory _99d19c80_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_99d19c80_rteHelperAllocatorResourceMemory){value}; }
static inline _s_99d19c80_outStatuses _99d19c80_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_99d19c80_outStatuses){value}; }
static inline _s_99d19c80_optionalFile _99d19c80_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_99d19c80_optionalFile){value}; }
static inline _s_99d19c80_optionalLine _99d19c80_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_99d19c80_optionalLine){value}; }
static inline _s_99d19c80_optionalUserData _99d19c80_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_99d19c80_optionalUserData){value}; }
static inline _s_99d19c80_rteParameters _99d19c80_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_99d19c80_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaDestroyArray(_s_99d19c80_helperAllocatorDma helperAllocatorDma, _s_99d19c80_rteHelperArray rteHelperArray, _s_99d19c80_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_99d19c80_outStatuses outStatuses, _s_99d19c80_optionalFile optionalFile, _s_99d19c80_optionalLine optionalLine, _s_99d19c80_optionalUserData optionalUserData, _s_99d19c80_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaDestroyArray(helperAllocatorDma.value, rteHelperArray.value, rteHelperAllocatorResourceMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaDestroyImage redRteHelperAllocatorDmaDestroyImage
#define _2eba206f_helperAllocatorDma(value) value
#define _2eba206f_rteHelperImage(value) value
#define _2eba206f_rteHelperAllocatorResourceMemory(value) value
#define _2eba206f_outStatuses(value) value
#define _2eba206f_optionalFile(value) value
#define _2eba206f_optionalLine(value) value
#define _2eba206f_optionalUserData(value) value
#define _2eba206f_rteParameters(value) value
#else
typedef struct _s_2eba206f_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_2eba206f_helperAllocatorDma;
typedef struct _s_2eba206f_rteHelperImage { RedHandleImage value; } _s_2eba206f_rteHelperImage;
typedef struct _s_2eba206f_rteHelperAllocatorResourceMemory { void* value; } _s_2eba206f_rteHelperAllocatorResourceMemory;
typedef struct _s_2eba206f_outStatuses { RedStatuses* value; } _s_2eba206f_outStatuses;
typedef struct _s_2eba206f_optionalFile { char* value; } _s_2eba206f_optionalFile;
typedef struct _s_2eba206f_optionalLine { int value; } _s_2eba206f_optionalLine;
typedef struct _s_2eba206f_optionalUserData { void* value; } _s_2eba206f_optionalUserData;
typedef struct _s_2eba206f_rteParameters { void* value; } _s_2eba206f_rteParameters;
static inline _s_2eba206f_helperAllocatorDma _2eba206f_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_2eba206f_helperAllocatorDma){value}; }
static inline _s_2eba206f_rteHelperImage _2eba206f_rteHelperImage(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_2eba206f_rteHelperImage){value}; }
static inline _s_2eba206f_rteHelperAllocatorResourceMemory _2eba206f_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2eba206f_rteHelperAllocatorResourceMemory){value}; }
static inline _s_2eba206f_outStatuses _2eba206f_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_2eba206f_outStatuses){value}; }
static inline _s_2eba206f_optionalFile _2eba206f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2eba206f_optionalFile){value}; }
static inline _s_2eba206f_optionalLine _2eba206f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2eba206f_optionalLine){value}; }
static inline _s_2eba206f_optionalUserData _2eba206f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2eba206f_optionalUserData){value}; }
static inline _s_2eba206f_rteParameters _2eba206f_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2eba206f_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaDestroyImage(_s_2eba206f_helperAllocatorDma helperAllocatorDma, _s_2eba206f_rteHelperImage rteHelperImage, _s_2eba206f_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_2eba206f_outStatuses outStatuses, _s_2eba206f_optionalFile optionalFile, _s_2eba206f_optionalLine optionalLine, _s_2eba206f_optionalUserData optionalUserData, _s_2eba206f_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaDestroyImage(helperAllocatorDma.value, rteHelperImage.value, rteHelperAllocatorResourceMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaFinalizeAndReleaseStagingMemory redRteHelperAllocatorDmaFinalizeAndReleaseStagingMemory
#define _06f870f7_helperAllocatorDma(value) value
#define _06f870f7_optionalCpuSignal(value) value
#define _06f870f7_outStatuses(value) value
#define _06f870f7_optionalFile(value) value
#define _06f870f7_optionalLine(value) value
#define _06f870f7_optionalUserData(value) value
#define _06f870f7_rteParameters(value) value
#else
typedef struct _s_06f870f7_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_06f870f7_helperAllocatorDma;
typedef struct _s_06f870f7_optionalCpuSignal { RedHandleCpuSignal value; } _s_06f870f7_optionalCpuSignal;
typedef struct _s_06f870f7_outStatuses { RedStatuses* value; } _s_06f870f7_outStatuses;
typedef struct _s_06f870f7_optionalFile { char* value; } _s_06f870f7_optionalFile;
typedef struct _s_06f870f7_optionalLine { int value; } _s_06f870f7_optionalLine;
typedef struct _s_06f870f7_optionalUserData { void* value; } _s_06f870f7_optionalUserData;
typedef struct _s_06f870f7_rteParameters { void* value; } _s_06f870f7_rteParameters;
static inline _s_06f870f7_helperAllocatorDma _06f870f7_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_06f870f7_helperAllocatorDma){value}; }
static inline _s_06f870f7_optionalCpuSignal _06f870f7_optionalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_06f870f7_optionalCpuSignal){value}; }
static inline _s_06f870f7_outStatuses _06f870f7_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_06f870f7_outStatuses){value}; }
static inline _s_06f870f7_optionalFile _06f870f7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_06f870f7_optionalFile){value}; }
static inline _s_06f870f7_optionalLine _06f870f7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_06f870f7_optionalLine){value}; }
static inline _s_06f870f7_optionalUserData _06f870f7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_06f870f7_optionalUserData){value}; }
static inline _s_06f870f7_rteParameters _06f870f7_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_06f870f7_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaFinalizeAndReleaseStagingMemory(_s_06f870f7_helperAllocatorDma helperAllocatorDma, _s_06f870f7_optionalCpuSignal optionalCpuSignal, _s_06f870f7_outStatuses outStatuses, _s_06f870f7_optionalFile optionalFile, _s_06f870f7_optionalLine optionalLine, _s_06f870f7_optionalUserData optionalUserData, _s_06f870f7_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaFinalizeAndReleaseStagingMemory(helperAllocatorDma.value, optionalCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaFinalizeStagingMemory redRteHelperAllocatorDmaFinalizeStagingMemory
#define _50442b0b_helperAllocatorDma(value) value
#define _50442b0b_optionalCpuSignal(value) value
#define _50442b0b_outStatuses(value) value
#define _50442b0b_optionalFile(value) value
#define _50442b0b_optionalLine(value) value
#define _50442b0b_optionalUserData(value) value
#define _50442b0b_rteParameters(value) value
#else
typedef struct _s_50442b0b_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_50442b0b_helperAllocatorDma;
typedef struct _s_50442b0b_optionalCpuSignal { RedHandleCpuSignal value; } _s_50442b0b_optionalCpuSignal;
typedef struct _s_50442b0b_outStatuses { RedStatuses* value; } _s_50442b0b_outStatuses;
typedef struct _s_50442b0b_optionalFile { char* value; } _s_50442b0b_optionalFile;
typedef struct _s_50442b0b_optionalLine { int value; } _s_50442b0b_optionalLine;
typedef struct _s_50442b0b_optionalUserData { void* value; } _s_50442b0b_optionalUserData;
typedef struct _s_50442b0b_rteParameters { void* value; } _s_50442b0b_rteParameters;
static inline _s_50442b0b_helperAllocatorDma _50442b0b_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_50442b0b_helperAllocatorDma){value}; }
static inline _s_50442b0b_optionalCpuSignal _50442b0b_optionalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_50442b0b_optionalCpuSignal){value}; }
static inline _s_50442b0b_outStatuses _50442b0b_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_50442b0b_outStatuses){value}; }
static inline _s_50442b0b_optionalFile _50442b0b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_50442b0b_optionalFile){value}; }
static inline _s_50442b0b_optionalLine _50442b0b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_50442b0b_optionalLine){value}; }
static inline _s_50442b0b_optionalUserData _50442b0b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_50442b0b_optionalUserData){value}; }
static inline _s_50442b0b_rteParameters _50442b0b_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_50442b0b_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaFinalizeStagingMemory(_s_50442b0b_helperAllocatorDma helperAllocatorDma, _s_50442b0b_optionalCpuSignal optionalCpuSignal, _s_50442b0b_outStatuses outStatuses, _s_50442b0b_optionalFile optionalFile, _s_50442b0b_optionalLine optionalLine, _s_50442b0b_optionalUserData optionalUserData, _s_50442b0b_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaFinalizeStagingMemory(helperAllocatorDma.value, optionalCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaReleaseStagingMemory redRteHelperAllocatorDmaReleaseStagingMemory
#define _4dcd95eb_helperAllocatorDma(value) value
#define _4dcd95eb_outStatuses(value) value
#define _4dcd95eb_optionalFile(value) value
#define _4dcd95eb_optionalLine(value) value
#define _4dcd95eb_optionalUserData(value) value
#define _4dcd95eb_rteParameters(value) value
#else
typedef struct _s_4dcd95eb_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_4dcd95eb_helperAllocatorDma;
typedef struct _s_4dcd95eb_outStatuses { RedStatuses* value; } _s_4dcd95eb_outStatuses;
typedef struct _s_4dcd95eb_optionalFile { char* value; } _s_4dcd95eb_optionalFile;
typedef struct _s_4dcd95eb_optionalLine { int value; } _s_4dcd95eb_optionalLine;
typedef struct _s_4dcd95eb_optionalUserData { void* value; } _s_4dcd95eb_optionalUserData;
typedef struct _s_4dcd95eb_rteParameters { void* value; } _s_4dcd95eb_rteParameters;
static inline _s_4dcd95eb_helperAllocatorDma _4dcd95eb_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_4dcd95eb_helperAllocatorDma){value}; }
static inline _s_4dcd95eb_outStatuses _4dcd95eb_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_4dcd95eb_outStatuses){value}; }
static inline _s_4dcd95eb_optionalFile _4dcd95eb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4dcd95eb_optionalFile){value}; }
static inline _s_4dcd95eb_optionalLine _4dcd95eb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4dcd95eb_optionalLine){value}; }
static inline _s_4dcd95eb_optionalUserData _4dcd95eb_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4dcd95eb_optionalUserData){value}; }
static inline _s_4dcd95eb_rteParameters _4dcd95eb_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4dcd95eb_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaReleaseStagingMemory(_s_4dcd95eb_helperAllocatorDma helperAllocatorDma, _s_4dcd95eb_outStatuses outStatuses, _s_4dcd95eb_optionalFile optionalFile, _s_4dcd95eb_optionalLine optionalLine, _s_4dcd95eb_optionalUserData optionalUserData, _s_4dcd95eb_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaReleaseStagingMemory(helperAllocatorDma.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaMapArray redRteHelperAllocatorDmaMapArray
#define _3955ab4a_helperAllocatorDma(value) value
#define _3955ab4a_rteHelperArray(value) value
#define _3955ab4a_rteHelperAllocatorResourceMemory(value) value
#define _3955ab4a_outVolatilePointer(value) value
#define _3955ab4a_outStatuses(value) value
#define _3955ab4a_optionalFile(value) value
#define _3955ab4a_optionalLine(value) value
#define _3955ab4a_optionalUserData(value) value
#define _3955ab4a_rteParameters(value) value
#else
typedef struct _s_3955ab4a_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_3955ab4a_helperAllocatorDma;
typedef struct _s_3955ab4a_rteHelperArray { RedHandleArray value; } _s_3955ab4a_rteHelperArray;
typedef struct _s_3955ab4a_rteHelperAllocatorResourceMemory { void* value; } _s_3955ab4a_rteHelperAllocatorResourceMemory;
typedef struct _s_3955ab4a_outVolatilePointer { void** value; } _s_3955ab4a_outVolatilePointer;
typedef struct _s_3955ab4a_outStatuses { RedStatuses* value; } _s_3955ab4a_outStatuses;
typedef struct _s_3955ab4a_optionalFile { char* value; } _s_3955ab4a_optionalFile;
typedef struct _s_3955ab4a_optionalLine { int value; } _s_3955ab4a_optionalLine;
typedef struct _s_3955ab4a_optionalUserData { void* value; } _s_3955ab4a_optionalUserData;
typedef struct _s_3955ab4a_rteParameters { void* value; } _s_3955ab4a_rteParameters;
static inline _s_3955ab4a_helperAllocatorDma _3955ab4a_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_3955ab4a_helperAllocatorDma){value}; }
static inline _s_3955ab4a_rteHelperArray _3955ab4a_rteHelperArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_3955ab4a_rteHelperArray){value}; }
static inline _s_3955ab4a_rteHelperAllocatorResourceMemory _3955ab4a_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3955ab4a_rteHelperAllocatorResourceMemory){value}; }
static inline _s_3955ab4a_outVolatilePointer _3955ab4a_outVolatilePointer(void** value) { return REDGPU_NP_STRUCT_INIT(_s_3955ab4a_outVolatilePointer){value}; }
static inline _s_3955ab4a_outStatuses _3955ab4a_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_3955ab4a_outStatuses){value}; }
static inline _s_3955ab4a_optionalFile _3955ab4a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3955ab4a_optionalFile){value}; }
static inline _s_3955ab4a_optionalLine _3955ab4a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3955ab4a_optionalLine){value}; }
static inline _s_3955ab4a_optionalUserData _3955ab4a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3955ab4a_optionalUserData){value}; }
static inline _s_3955ab4a_rteParameters _3955ab4a_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3955ab4a_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaMapArray(_s_3955ab4a_helperAllocatorDma helperAllocatorDma, _s_3955ab4a_rteHelperArray rteHelperArray, _s_3955ab4a_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_3955ab4a_outVolatilePointer outVolatilePointer, _s_3955ab4a_outStatuses outStatuses, _s_3955ab4a_optionalFile optionalFile, _s_3955ab4a_optionalLine optionalLine, _s_3955ab4a_optionalUserData optionalUserData, _s_3955ab4a_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaMapArray(helperAllocatorDma.value, rteHelperArray.value, rteHelperAllocatorResourceMemory.value, outVolatilePointer.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorDmaUnmapArray redRteHelperAllocatorDmaUnmapArray
#define _132841f9_helperAllocatorDma(value) value
#define _132841f9_rteHelperArray(value) value
#define _132841f9_rteHelperAllocatorResourceMemory(value) value
#define _132841f9_outStatuses(value) value
#define _132841f9_optionalFile(value) value
#define _132841f9_optionalLine(value) value
#define _132841f9_optionalUserData(value) value
#define _132841f9_rteParameters(value) value
#else
typedef struct _s_132841f9_helperAllocatorDma { RedRteHandleHelperAllocatorDma value; } _s_132841f9_helperAllocatorDma;
typedef struct _s_132841f9_rteHelperArray { RedHandleArray value; } _s_132841f9_rteHelperArray;
typedef struct _s_132841f9_rteHelperAllocatorResourceMemory { void* value; } _s_132841f9_rteHelperAllocatorResourceMemory;
typedef struct _s_132841f9_outStatuses { RedStatuses* value; } _s_132841f9_outStatuses;
typedef struct _s_132841f9_optionalFile { char* value; } _s_132841f9_optionalFile;
typedef struct _s_132841f9_optionalLine { int value; } _s_132841f9_optionalLine;
typedef struct _s_132841f9_optionalUserData { void* value; } _s_132841f9_optionalUserData;
typedef struct _s_132841f9_rteParameters { void* value; } _s_132841f9_rteParameters;
static inline _s_132841f9_helperAllocatorDma _132841f9_helperAllocatorDma(RedRteHandleHelperAllocatorDma value) { return REDGPU_NP_STRUCT_INIT(_s_132841f9_helperAllocatorDma){value}; }
static inline _s_132841f9_rteHelperArray _132841f9_rteHelperArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_132841f9_rteHelperArray){value}; }
static inline _s_132841f9_rteHelperAllocatorResourceMemory _132841f9_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_132841f9_rteHelperAllocatorResourceMemory){value}; }
static inline _s_132841f9_outStatuses _132841f9_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_132841f9_outStatuses){value}; }
static inline _s_132841f9_optionalFile _132841f9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_132841f9_optionalFile){value}; }
static inline _s_132841f9_optionalLine _132841f9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_132841f9_optionalLine){value}; }
static inline _s_132841f9_optionalUserData _132841f9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_132841f9_optionalUserData){value}; }
static inline _s_132841f9_rteParameters _132841f9_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_132841f9_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorDmaUnmapArray(_s_132841f9_helperAllocatorDma helperAllocatorDma, _s_132841f9_rteHelperArray rteHelperArray, _s_132841f9_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_132841f9_outStatuses outStatuses, _s_132841f9_optionalFile optionalFile, _s_132841f9_optionalLine optionalLine, _s_132841f9_optionalUserData optionalUserData, _s_132841f9_rteParameters rteParameters) {
  return redRteHelperAllocatorDmaUnmapArray(helperAllocatorDma.value, rteHelperArray.value, rteHelperAllocatorResourceMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateHelperAllocatorVma redRteCreateHelperAllocatorVma
#define _24e4fe03_rteContext(value) value
#define _24e4fe03_outHelperAllocatorVma(value) value
#define _24e4fe03_outStatuses(value) value
#define _24e4fe03_optionalFile(value) value
#define _24e4fe03_optionalLine(value) value
#define _24e4fe03_optionalUserData(value) value
#define _24e4fe03_rteParameters(value) value
#else
typedef struct _s_24e4fe03_rteContext { RedRteHandleContext value; } _s_24e4fe03_rteContext;
typedef struct _s_24e4fe03_outHelperAllocatorVma { RedRteHandleHelperAllocatorVma* value; } _s_24e4fe03_outHelperAllocatorVma;
typedef struct _s_24e4fe03_outStatuses { RedStatuses* value; } _s_24e4fe03_outStatuses;
typedef struct _s_24e4fe03_optionalFile { char* value; } _s_24e4fe03_optionalFile;
typedef struct _s_24e4fe03_optionalLine { int value; } _s_24e4fe03_optionalLine;
typedef struct _s_24e4fe03_optionalUserData { void* value; } _s_24e4fe03_optionalUserData;
typedef struct _s_24e4fe03_rteParameters { void* value; } _s_24e4fe03_rteParameters;
static inline _s_24e4fe03_rteContext _24e4fe03_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_24e4fe03_rteContext){value}; }
static inline _s_24e4fe03_outHelperAllocatorVma _24e4fe03_outHelperAllocatorVma(RedRteHandleHelperAllocatorVma* value) { return REDGPU_NP_STRUCT_INIT(_s_24e4fe03_outHelperAllocatorVma){value}; }
static inline _s_24e4fe03_outStatuses _24e4fe03_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_24e4fe03_outStatuses){value}; }
static inline _s_24e4fe03_optionalFile _24e4fe03_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_24e4fe03_optionalFile){value}; }
static inline _s_24e4fe03_optionalLine _24e4fe03_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_24e4fe03_optionalLine){value}; }
static inline _s_24e4fe03_optionalUserData _24e4fe03_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_24e4fe03_optionalUserData){value}; }
static inline _s_24e4fe03_rteParameters _24e4fe03_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_24e4fe03_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateHelperAllocatorVma(_s_24e4fe03_rteContext rteContext, _s_24e4fe03_outHelperAllocatorVma outHelperAllocatorVma, _s_24e4fe03_outStatuses outStatuses, _s_24e4fe03_optionalFile optionalFile, _s_24e4fe03_optionalLine optionalLine, _s_24e4fe03_optionalUserData optionalUserData, _s_24e4fe03_rteParameters rteParameters) {
  return redRteCreateHelperAllocatorVma(rteContext.value, outHelperAllocatorVma.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyHelperAllocatorVma redRteDestroyHelperAllocatorVma
#define _bc141ff4_helperAllocatorVma(value) value
#define _bc141ff4_optionalFile(value) value
#define _bc141ff4_optionalLine(value) value
#define _bc141ff4_optionalUserData(value) value
#define _bc141ff4_rteParameters(value) value
#else
typedef struct _s_bc141ff4_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_bc141ff4_helperAllocatorVma;
typedef struct _s_bc141ff4_optionalFile { char* value; } _s_bc141ff4_optionalFile;
typedef struct _s_bc141ff4_optionalLine { int value; } _s_bc141ff4_optionalLine;
typedef struct _s_bc141ff4_optionalUserData { void* value; } _s_bc141ff4_optionalUserData;
typedef struct _s_bc141ff4_rteParameters { void* value; } _s_bc141ff4_rteParameters;
static inline _s_bc141ff4_helperAllocatorVma _bc141ff4_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_bc141ff4_helperAllocatorVma){value}; }
static inline _s_bc141ff4_optionalFile _bc141ff4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bc141ff4_optionalFile){value}; }
static inline _s_bc141ff4_optionalLine _bc141ff4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bc141ff4_optionalLine){value}; }
static inline _s_bc141ff4_optionalUserData _bc141ff4_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bc141ff4_optionalUserData){value}; }
static inline _s_bc141ff4_rteParameters _bc141ff4_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bc141ff4_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyHelperAllocatorVma(_s_bc141ff4_helperAllocatorVma helperAllocatorVma, _s_bc141ff4_optionalFile optionalFile, _s_bc141ff4_optionalLine optionalLine, _s_bc141ff4_optionalUserData optionalUserData, _s_bc141ff4_rteParameters rteParameters) {
  return redRteDestroyHelperAllocatorVma(helperAllocatorVma.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaCreateArray redRteHelperAllocatorVmaCreateArray
#define _84a2fec0_helperAllocatorVma(value) value
#define _84a2fec0_arrayInfo(value) value
#define _84a2fec0_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _84a2fec0_outRteHelperArray(value) value
#define _84a2fec0_outStatuses(value) value
#define _84a2fec0_optionalFile(value) value
#define _84a2fec0_optionalLine(value) value
#define _84a2fec0_optionalUserData(value) value
#define _84a2fec0_rteParameters(value) value
#else
typedef struct _s_84a2fec0_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_84a2fec0_helperAllocatorVma;
typedef struct _s_84a2fec0_arrayInfo { RedRteHelperCreateArrayInfo* value; } _s_84a2fec0_arrayInfo;
typedef struct _s_84a2fec0_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_84a2fec0_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_84a2fec0_outRteHelperArray { RedRteHelperArray* value; } _s_84a2fec0_outRteHelperArray;
typedef struct _s_84a2fec0_outStatuses { RedStatuses* value; } _s_84a2fec0_outStatuses;
typedef struct _s_84a2fec0_optionalFile { char* value; } _s_84a2fec0_optionalFile;
typedef struct _s_84a2fec0_optionalLine { int value; } _s_84a2fec0_optionalLine;
typedef struct _s_84a2fec0_optionalUserData { void* value; } _s_84a2fec0_optionalUserData;
typedef struct _s_84a2fec0_rteParameters { void* value; } _s_84a2fec0_rteParameters;
static inline _s_84a2fec0_helperAllocatorVma _84a2fec0_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_84a2fec0_helperAllocatorVma){value}; }
static inline _s_84a2fec0_arrayInfo _84a2fec0_arrayInfo(RedRteHelperCreateArrayInfo* value) { return REDGPU_NP_STRUCT_INIT(_s_84a2fec0_arrayInfo){value}; }
static inline _s_84a2fec0_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _84a2fec0_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_84a2fec0_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_84a2fec0_outRteHelperArray _84a2fec0_outRteHelperArray(RedRteHelperArray* value) { return REDGPU_NP_STRUCT_INIT(_s_84a2fec0_outRteHelperArray){value}; }
static inline _s_84a2fec0_outStatuses _84a2fec0_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_84a2fec0_outStatuses){value}; }
static inline _s_84a2fec0_optionalFile _84a2fec0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_84a2fec0_optionalFile){value}; }
static inline _s_84a2fec0_optionalLine _84a2fec0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_84a2fec0_optionalLine){value}; }
static inline _s_84a2fec0_optionalUserData _84a2fec0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_84a2fec0_optionalUserData){value}; }
static inline _s_84a2fec0_rteParameters _84a2fec0_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_84a2fec0_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaCreateArray(_s_84a2fec0_helperAllocatorVma helperAllocatorVma, _s_84a2fec0_arrayInfo arrayInfo, _s_84a2fec0_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_84a2fec0_outRteHelperArray outRteHelperArray, _s_84a2fec0_outStatuses outStatuses, _s_84a2fec0_optionalFile optionalFile, _s_84a2fec0_optionalLine optionalLine, _s_84a2fec0_optionalUserData optionalUserData, _s_84a2fec0_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaCreateArray(helperAllocatorVma.value, arrayInfo.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaCreateImage redRteHelperAllocatorVmaCreateImage
#define _2e9608f2_helperAllocatorVma(value) value
#define _2e9608f2_imageInfo(value) value
#define _2e9608f2_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _2e9608f2_outRteHelperImage(value) value
#define _2e9608f2_outStatuses(value) value
#define _2e9608f2_optionalFile(value) value
#define _2e9608f2_optionalLine(value) value
#define _2e9608f2_optionalUserData(value) value
#define _2e9608f2_rteParameters(value) value
#else
typedef struct _s_2e9608f2_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_2e9608f2_helperAllocatorVma;
typedef struct _s_2e9608f2_imageInfo { RedRteHelperCreateImageInfo* value; } _s_2e9608f2_imageInfo;
typedef struct _s_2e9608f2_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_2e9608f2_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_2e9608f2_outRteHelperImage { RedRteHelperImage* value; } _s_2e9608f2_outRteHelperImage;
typedef struct _s_2e9608f2_outStatuses { RedStatuses* value; } _s_2e9608f2_outStatuses;
typedef struct _s_2e9608f2_optionalFile { char* value; } _s_2e9608f2_optionalFile;
typedef struct _s_2e9608f2_optionalLine { int value; } _s_2e9608f2_optionalLine;
typedef struct _s_2e9608f2_optionalUserData { void* value; } _s_2e9608f2_optionalUserData;
typedef struct _s_2e9608f2_rteParameters { void* value; } _s_2e9608f2_rteParameters;
static inline _s_2e9608f2_helperAllocatorVma _2e9608f2_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_2e9608f2_helperAllocatorVma){value}; }
static inline _s_2e9608f2_imageInfo _2e9608f2_imageInfo(RedRteHelperCreateImageInfo* value) { return REDGPU_NP_STRUCT_INIT(_s_2e9608f2_imageInfo){value}; }
static inline _s_2e9608f2_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _2e9608f2_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_2e9608f2_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_2e9608f2_outRteHelperImage _2e9608f2_outRteHelperImage(RedRteHelperImage* value) { return REDGPU_NP_STRUCT_INIT(_s_2e9608f2_outRteHelperImage){value}; }
static inline _s_2e9608f2_outStatuses _2e9608f2_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_2e9608f2_outStatuses){value}; }
static inline _s_2e9608f2_optionalFile _2e9608f2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2e9608f2_optionalFile){value}; }
static inline _s_2e9608f2_optionalLine _2e9608f2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2e9608f2_optionalLine){value}; }
static inline _s_2e9608f2_optionalUserData _2e9608f2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2e9608f2_optionalUserData){value}; }
static inline _s_2e9608f2_rteParameters _2e9608f2_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2e9608f2_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaCreateImage(_s_2e9608f2_helperAllocatorVma helperAllocatorVma, _s_2e9608f2_imageInfo imageInfo, _s_2e9608f2_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_2e9608f2_outRteHelperImage outRteHelperImage, _s_2e9608f2_outStatuses outStatuses, _s_2e9608f2_optionalFile optionalFile, _s_2e9608f2_optionalLine optionalLine, _s_2e9608f2_optionalUserData optionalUserData, _s_2e9608f2_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaCreateImage(helperAllocatorVma.value, imageInfo.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperImage.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaCreateArraySimple redRteHelperAllocatorVmaCreateArraySimple
#define _cd6bb6f6_helperAllocatorVma(value) value
#define _cd6bb6f6_arrayBytesCount(value) value
#define _cd6bb6f6_arrayUsageFlags(value) value
#define _cd6bb6f6_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _cd6bb6f6_outRteHelperArray(value) value
#define _cd6bb6f6_outStatuses(value) value
#define _cd6bb6f6_optionalFile(value) value
#define _cd6bb6f6_optionalLine(value) value
#define _cd6bb6f6_optionalUserData(value) value
#define _cd6bb6f6_rteParameters(value) value
#else
typedef struct _s_cd6bb6f6_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_cd6bb6f6_helperAllocatorVma;
typedef struct _s_cd6bb6f6_arrayBytesCount { uint64_t value; } _s_cd6bb6f6_arrayBytesCount;
typedef struct _s_cd6bb6f6_arrayUsageFlags { unsigned value; } _s_cd6bb6f6_arrayUsageFlags;
typedef struct _s_cd6bb6f6_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_cd6bb6f6_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_cd6bb6f6_outRteHelperArray { RedRteHelperArray* value; } _s_cd6bb6f6_outRteHelperArray;
typedef struct _s_cd6bb6f6_outStatuses { RedStatuses* value; } _s_cd6bb6f6_outStatuses;
typedef struct _s_cd6bb6f6_optionalFile { char* value; } _s_cd6bb6f6_optionalFile;
typedef struct _s_cd6bb6f6_optionalLine { int value; } _s_cd6bb6f6_optionalLine;
typedef struct _s_cd6bb6f6_optionalUserData { void* value; } _s_cd6bb6f6_optionalUserData;
typedef struct _s_cd6bb6f6_rteParameters { void* value; } _s_cd6bb6f6_rteParameters;
static inline _s_cd6bb6f6_helperAllocatorVma _cd6bb6f6_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_cd6bb6f6_helperAllocatorVma){value}; }
static inline _s_cd6bb6f6_arrayBytesCount _cd6bb6f6_arrayBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_cd6bb6f6_arrayBytesCount){value}; }
static inline _s_cd6bb6f6_arrayUsageFlags _cd6bb6f6_arrayUsageFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cd6bb6f6_arrayUsageFlags){value}; }
static inline _s_cd6bb6f6_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _cd6bb6f6_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cd6bb6f6_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_cd6bb6f6_outRteHelperArray _cd6bb6f6_outRteHelperArray(RedRteHelperArray* value) { return REDGPU_NP_STRUCT_INIT(_s_cd6bb6f6_outRteHelperArray){value}; }
static inline _s_cd6bb6f6_outStatuses _cd6bb6f6_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_cd6bb6f6_outStatuses){value}; }
static inline _s_cd6bb6f6_optionalFile _cd6bb6f6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cd6bb6f6_optionalFile){value}; }
static inline _s_cd6bb6f6_optionalLine _cd6bb6f6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cd6bb6f6_optionalLine){value}; }
static inline _s_cd6bb6f6_optionalUserData _cd6bb6f6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cd6bb6f6_optionalUserData){value}; }
static inline _s_cd6bb6f6_rteParameters _cd6bb6f6_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cd6bb6f6_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaCreateArraySimple(_s_cd6bb6f6_helperAllocatorVma helperAllocatorVma, _s_cd6bb6f6_arrayBytesCount arrayBytesCount, _s_cd6bb6f6_arrayUsageFlags arrayUsageFlags, _s_cd6bb6f6_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_cd6bb6f6_outRteHelperArray outRteHelperArray, _s_cd6bb6f6_outStatuses outStatuses, _s_cd6bb6f6_optionalFile optionalFile, _s_cd6bb6f6_optionalLine optionalLine, _s_cd6bb6f6_optionalUserData optionalUserData, _s_cd6bb6f6_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaCreateArraySimple(helperAllocatorVma.value, arrayBytesCount.value, arrayUsageFlags.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaCreateArraySimpleWithData redRteHelperAllocatorVmaCreateArraySimpleWithData
#define _30a4f997_helperAllocatorVma(value) value
#define _30a4f997_callsSetToUploadArrayData(value) value
#define _30a4f997_arrayDataBytesCount(value) value
#define _30a4f997_arrayData(value) value
#define _30a4f997_arrayUsageFlags(value) value
#define _30a4f997_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(value) value
#define _30a4f997_outRteHelperArray(value) value
#define _30a4f997_outStatuses(value) value
#define _30a4f997_optionalFile(value) value
#define _30a4f997_optionalLine(value) value
#define _30a4f997_optionalUserData(value) value
#define _30a4f997_rteParameters(value) value
#else
typedef struct _s_30a4f997_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_30a4f997_helperAllocatorVma;
typedef struct _s_30a4f997_callsSetToUploadArrayData { RedHandleCalls value; } _s_30a4f997_callsSetToUploadArrayData;
typedef struct _s_30a4f997_arrayDataBytesCount { uint64_t value; } _s_30a4f997_arrayDataBytesCount;
typedef struct _s_30a4f997_arrayData { void* value; } _s_30a4f997_arrayData;
typedef struct _s_30a4f997_arrayUsageFlags { unsigned value; } _s_30a4f997_arrayUsageFlags;
typedef struct _s_30a4f997_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit { unsigned value; } _s_30a4f997_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit;
typedef struct _s_30a4f997_outRteHelperArray { RedRteHelperArray* value; } _s_30a4f997_outRteHelperArray;
typedef struct _s_30a4f997_outStatuses { RedStatuses* value; } _s_30a4f997_outStatuses;
typedef struct _s_30a4f997_optionalFile { char* value; } _s_30a4f997_optionalFile;
typedef struct _s_30a4f997_optionalLine { int value; } _s_30a4f997_optionalLine;
typedef struct _s_30a4f997_optionalUserData { void* value; } _s_30a4f997_optionalUserData;
typedef struct _s_30a4f997_rteParameters { void* value; } _s_30a4f997_rteParameters;
static inline _s_30a4f997_helperAllocatorVma _30a4f997_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_30a4f997_helperAllocatorVma){value}; }
static inline _s_30a4f997_callsSetToUploadArrayData _30a4f997_callsSetToUploadArrayData(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_30a4f997_callsSetToUploadArrayData){value}; }
static inline _s_30a4f997_arrayDataBytesCount _30a4f997_arrayDataBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_30a4f997_arrayDataBytesCount){value}; }
static inline _s_30a4f997_arrayData _30a4f997_arrayData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_30a4f997_arrayData){value}; }
static inline _s_30a4f997_arrayUsageFlags _30a4f997_arrayUsageFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_30a4f997_arrayUsageFlags){value}; }
static inline _s_30a4f997_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit _30a4f997_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_30a4f997_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit){value}; }
static inline _s_30a4f997_outRteHelperArray _30a4f997_outRteHelperArray(RedRteHelperArray* value) { return REDGPU_NP_STRUCT_INIT(_s_30a4f997_outRteHelperArray){value}; }
static inline _s_30a4f997_outStatuses _30a4f997_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_30a4f997_outStatuses){value}; }
static inline _s_30a4f997_optionalFile _30a4f997_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_30a4f997_optionalFile){value}; }
static inline _s_30a4f997_optionalLine _30a4f997_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_30a4f997_optionalLine){value}; }
static inline _s_30a4f997_optionalUserData _30a4f997_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_30a4f997_optionalUserData){value}; }
static inline _s_30a4f997_rteParameters _30a4f997_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_30a4f997_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaCreateArraySimpleWithData(_s_30a4f997_helperAllocatorVma helperAllocatorVma, _s_30a4f997_callsSetToUploadArrayData callsSetToUploadArrayData, _s_30a4f997_arrayDataBytesCount arrayDataBytesCount, _s_30a4f997_arrayData arrayData, _s_30a4f997_arrayUsageFlags arrayUsageFlags, _s_30a4f997_memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit, _s_30a4f997_outRteHelperArray outRteHelperArray, _s_30a4f997_outStatuses outStatuses, _s_30a4f997_optionalFile optionalFile, _s_30a4f997_optionalLine optionalLine, _s_30a4f997_optionalUserData optionalUserData, _s_30a4f997_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaCreateArraySimpleWithData(helperAllocatorVma.value, callsSetToUploadArrayData.value, arrayDataBytesCount.value, arrayData.value, arrayUsageFlags.value, memoryPropertyFlagsSuggestedDefaultValueIsMemoryPropertyDeviceLocalBit.value, outRteHelperArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaCreateImageSimpleWithData redRteHelperAllocatorVmaCreateImageSimpleWithData
#define _d3ac16d3_helperAllocatorVma(value) value
#define _d3ac16d3_callsSetToUploadImageData(value) value
#define _d3ac16d3_imageDataBytesCount(value) value
#define _d3ac16d3_imageData(value) value
#define _d3ac16d3_imageInfo(value) value
#define _d3ac16d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral(value) value
#define _d3ac16d3_outRteHelperImage(value) value
#define _d3ac16d3_outStatuses(value) value
#define _d3ac16d3_optionalFile(value) value
#define _d3ac16d3_optionalLine(value) value
#define _d3ac16d3_optionalUserData(value) value
#define _d3ac16d3_rteParameters(value) value
#else
typedef struct _s_d3ac16d3_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_d3ac16d3_helperAllocatorVma;
typedef struct _s_d3ac16d3_callsSetToUploadImageData { RedHandleCalls value; } _s_d3ac16d3_callsSetToUploadImageData;
typedef struct _s_d3ac16d3_imageDataBytesCount { uint64_t value; } _s_d3ac16d3_imageDataBytesCount;
typedef struct _s_d3ac16d3_imageData { void* value; } _s_d3ac16d3_imageData;
typedef struct _s_d3ac16d3_imageInfo { RedRteHelperCreateImageInfo* value; } _s_d3ac16d3_imageInfo;
typedef struct _s_d3ac16d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral { unsigned value; } _s_d3ac16d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral;
typedef struct _s_d3ac16d3_outRteHelperImage { RedRteHelperImage* value; } _s_d3ac16d3_outRteHelperImage;
typedef struct _s_d3ac16d3_outStatuses { RedStatuses* value; } _s_d3ac16d3_outStatuses;
typedef struct _s_d3ac16d3_optionalFile { char* value; } _s_d3ac16d3_optionalFile;
typedef struct _s_d3ac16d3_optionalLine { int value; } _s_d3ac16d3_optionalLine;
typedef struct _s_d3ac16d3_optionalUserData { void* value; } _s_d3ac16d3_optionalUserData;
typedef struct _s_d3ac16d3_rteParameters { void* value; } _s_d3ac16d3_rteParameters;
static inline _s_d3ac16d3_helperAllocatorVma _d3ac16d3_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_d3ac16d3_helperAllocatorVma){value}; }
static inline _s_d3ac16d3_callsSetToUploadImageData _d3ac16d3_callsSetToUploadImageData(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_d3ac16d3_callsSetToUploadImageData){value}; }
static inline _s_d3ac16d3_imageDataBytesCount _d3ac16d3_imageDataBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_d3ac16d3_imageDataBytesCount){value}; }
static inline _s_d3ac16d3_imageData _d3ac16d3_imageData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d3ac16d3_imageData){value}; }
static inline _s_d3ac16d3_imageInfo _d3ac16d3_imageInfo(RedRteHelperCreateImageInfo* value) { return REDGPU_NP_STRUCT_INIT(_s_d3ac16d3_imageInfo){value}; }
static inline _s_d3ac16d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral _d3ac16d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_d3ac16d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral){value}; }
static inline _s_d3ac16d3_outRteHelperImage _d3ac16d3_outRteHelperImage(RedRteHelperImage* value) { return REDGPU_NP_STRUCT_INIT(_s_d3ac16d3_outRteHelperImage){value}; }
static inline _s_d3ac16d3_outStatuses _d3ac16d3_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_d3ac16d3_outStatuses){value}; }
static inline _s_d3ac16d3_optionalFile _d3ac16d3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d3ac16d3_optionalFile){value}; }
static inline _s_d3ac16d3_optionalLine _d3ac16d3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d3ac16d3_optionalLine){value}; }
static inline _s_d3ac16d3_optionalUserData _d3ac16d3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d3ac16d3_optionalUserData){value}; }
static inline _s_d3ac16d3_rteParameters _d3ac16d3_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d3ac16d3_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaCreateImageSimpleWithData(_s_d3ac16d3_helperAllocatorVma helperAllocatorVma, _s_d3ac16d3_callsSetToUploadImageData callsSetToUploadImageData, _s_d3ac16d3_imageDataBytesCount imageDataBytesCount, _s_d3ac16d3_imageData imageData, _s_d3ac16d3_imageInfo imageInfo, _s_d3ac16d3_imageLayoutSuggestedDefaultValueIsImageLayoutGeneral imageLayoutSuggestedDefaultValueIsImageLayoutGeneral, _s_d3ac16d3_outRteHelperImage outRteHelperImage, _s_d3ac16d3_outStatuses outStatuses, _s_d3ac16d3_optionalFile optionalFile, _s_d3ac16d3_optionalLine optionalLine, _s_d3ac16d3_optionalUserData optionalUserData, _s_d3ac16d3_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaCreateImageSimpleWithData(helperAllocatorVma.value, callsSetToUploadImageData.value, imageDataBytesCount.value, imageData.value, imageInfo.value, imageLayoutSuggestedDefaultValueIsImageLayoutGeneral.value, outRteHelperImage.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaDestroyArray redRteHelperAllocatorVmaDestroyArray
#define _5695e97b_helperAllocatorVma(value) value
#define _5695e97b_rteHelperArray(value) value
#define _5695e97b_rteHelperAllocatorResourceMemory(value) value
#define _5695e97b_outStatuses(value) value
#define _5695e97b_optionalFile(value) value
#define _5695e97b_optionalLine(value) value
#define _5695e97b_optionalUserData(value) value
#define _5695e97b_rteParameters(value) value
#else
typedef struct _s_5695e97b_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_5695e97b_helperAllocatorVma;
typedef struct _s_5695e97b_rteHelperArray { RedHandleArray value; } _s_5695e97b_rteHelperArray;
typedef struct _s_5695e97b_rteHelperAllocatorResourceMemory { void* value; } _s_5695e97b_rteHelperAllocatorResourceMemory;
typedef struct _s_5695e97b_outStatuses { RedStatuses* value; } _s_5695e97b_outStatuses;
typedef struct _s_5695e97b_optionalFile { char* value; } _s_5695e97b_optionalFile;
typedef struct _s_5695e97b_optionalLine { int value; } _s_5695e97b_optionalLine;
typedef struct _s_5695e97b_optionalUserData { void* value; } _s_5695e97b_optionalUserData;
typedef struct _s_5695e97b_rteParameters { void* value; } _s_5695e97b_rteParameters;
static inline _s_5695e97b_helperAllocatorVma _5695e97b_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_5695e97b_helperAllocatorVma){value}; }
static inline _s_5695e97b_rteHelperArray _5695e97b_rteHelperArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_5695e97b_rteHelperArray){value}; }
static inline _s_5695e97b_rteHelperAllocatorResourceMemory _5695e97b_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5695e97b_rteHelperAllocatorResourceMemory){value}; }
static inline _s_5695e97b_outStatuses _5695e97b_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_5695e97b_outStatuses){value}; }
static inline _s_5695e97b_optionalFile _5695e97b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5695e97b_optionalFile){value}; }
static inline _s_5695e97b_optionalLine _5695e97b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5695e97b_optionalLine){value}; }
static inline _s_5695e97b_optionalUserData _5695e97b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5695e97b_optionalUserData){value}; }
static inline _s_5695e97b_rteParameters _5695e97b_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5695e97b_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaDestroyArray(_s_5695e97b_helperAllocatorVma helperAllocatorVma, _s_5695e97b_rteHelperArray rteHelperArray, _s_5695e97b_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_5695e97b_outStatuses outStatuses, _s_5695e97b_optionalFile optionalFile, _s_5695e97b_optionalLine optionalLine, _s_5695e97b_optionalUserData optionalUserData, _s_5695e97b_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaDestroyArray(helperAllocatorVma.value, rteHelperArray.value, rteHelperAllocatorResourceMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaDestroyImage redRteHelperAllocatorVmaDestroyImage
#define _6d624587_helperAllocatorVma(value) value
#define _6d624587_rteHelperImage(value) value
#define _6d624587_rteHelperAllocatorResourceMemory(value) value
#define _6d624587_outStatuses(value) value
#define _6d624587_optionalFile(value) value
#define _6d624587_optionalLine(value) value
#define _6d624587_optionalUserData(value) value
#define _6d624587_rteParameters(value) value
#else
typedef struct _s_6d624587_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_6d624587_helperAllocatorVma;
typedef struct _s_6d624587_rteHelperImage { RedHandleImage value; } _s_6d624587_rteHelperImage;
typedef struct _s_6d624587_rteHelperAllocatorResourceMemory { void* value; } _s_6d624587_rteHelperAllocatorResourceMemory;
typedef struct _s_6d624587_outStatuses { RedStatuses* value; } _s_6d624587_outStatuses;
typedef struct _s_6d624587_optionalFile { char* value; } _s_6d624587_optionalFile;
typedef struct _s_6d624587_optionalLine { int value; } _s_6d624587_optionalLine;
typedef struct _s_6d624587_optionalUserData { void* value; } _s_6d624587_optionalUserData;
typedef struct _s_6d624587_rteParameters { void* value; } _s_6d624587_rteParameters;
static inline _s_6d624587_helperAllocatorVma _6d624587_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_6d624587_helperAllocatorVma){value}; }
static inline _s_6d624587_rteHelperImage _6d624587_rteHelperImage(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_6d624587_rteHelperImage){value}; }
static inline _s_6d624587_rteHelperAllocatorResourceMemory _6d624587_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6d624587_rteHelperAllocatorResourceMemory){value}; }
static inline _s_6d624587_outStatuses _6d624587_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_6d624587_outStatuses){value}; }
static inline _s_6d624587_optionalFile _6d624587_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6d624587_optionalFile){value}; }
static inline _s_6d624587_optionalLine _6d624587_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6d624587_optionalLine){value}; }
static inline _s_6d624587_optionalUserData _6d624587_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6d624587_optionalUserData){value}; }
static inline _s_6d624587_rteParameters _6d624587_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6d624587_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaDestroyImage(_s_6d624587_helperAllocatorVma helperAllocatorVma, _s_6d624587_rteHelperImage rteHelperImage, _s_6d624587_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_6d624587_outStatuses outStatuses, _s_6d624587_optionalFile optionalFile, _s_6d624587_optionalLine optionalLine, _s_6d624587_optionalUserData optionalUserData, _s_6d624587_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaDestroyImage(helperAllocatorVma.value, rteHelperImage.value, rteHelperAllocatorResourceMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaFinalizeAndReleaseStagingMemory redRteHelperAllocatorVmaFinalizeAndReleaseStagingMemory
#define _53b4c4ca_helperAllocatorVma(value) value
#define _53b4c4ca_optionalCpuSignal(value) value
#define _53b4c4ca_outStatuses(value) value
#define _53b4c4ca_optionalFile(value) value
#define _53b4c4ca_optionalLine(value) value
#define _53b4c4ca_optionalUserData(value) value
#define _53b4c4ca_rteParameters(value) value
#else
typedef struct _s_53b4c4ca_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_53b4c4ca_helperAllocatorVma;
typedef struct _s_53b4c4ca_optionalCpuSignal { RedHandleCpuSignal value; } _s_53b4c4ca_optionalCpuSignal;
typedef struct _s_53b4c4ca_outStatuses { RedStatuses* value; } _s_53b4c4ca_outStatuses;
typedef struct _s_53b4c4ca_optionalFile { char* value; } _s_53b4c4ca_optionalFile;
typedef struct _s_53b4c4ca_optionalLine { int value; } _s_53b4c4ca_optionalLine;
typedef struct _s_53b4c4ca_optionalUserData { void* value; } _s_53b4c4ca_optionalUserData;
typedef struct _s_53b4c4ca_rteParameters { void* value; } _s_53b4c4ca_rteParameters;
static inline _s_53b4c4ca_helperAllocatorVma _53b4c4ca_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_53b4c4ca_helperAllocatorVma){value}; }
static inline _s_53b4c4ca_optionalCpuSignal _53b4c4ca_optionalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_53b4c4ca_optionalCpuSignal){value}; }
static inline _s_53b4c4ca_outStatuses _53b4c4ca_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_53b4c4ca_outStatuses){value}; }
static inline _s_53b4c4ca_optionalFile _53b4c4ca_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_53b4c4ca_optionalFile){value}; }
static inline _s_53b4c4ca_optionalLine _53b4c4ca_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_53b4c4ca_optionalLine){value}; }
static inline _s_53b4c4ca_optionalUserData _53b4c4ca_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_53b4c4ca_optionalUserData){value}; }
static inline _s_53b4c4ca_rteParameters _53b4c4ca_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_53b4c4ca_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaFinalizeAndReleaseStagingMemory(_s_53b4c4ca_helperAllocatorVma helperAllocatorVma, _s_53b4c4ca_optionalCpuSignal optionalCpuSignal, _s_53b4c4ca_outStatuses outStatuses, _s_53b4c4ca_optionalFile optionalFile, _s_53b4c4ca_optionalLine optionalLine, _s_53b4c4ca_optionalUserData optionalUserData, _s_53b4c4ca_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaFinalizeAndReleaseStagingMemory(helperAllocatorVma.value, optionalCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaFinalizeStagingMemory redRteHelperAllocatorVmaFinalizeStagingMemory
#define _7669c3c1_helperAllocatorVma(value) value
#define _7669c3c1_optionalCpuSignal(value) value
#define _7669c3c1_outStatuses(value) value
#define _7669c3c1_optionalFile(value) value
#define _7669c3c1_optionalLine(value) value
#define _7669c3c1_optionalUserData(value) value
#define _7669c3c1_rteParameters(value) value
#else
typedef struct _s_7669c3c1_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_7669c3c1_helperAllocatorVma;
typedef struct _s_7669c3c1_optionalCpuSignal { RedHandleCpuSignal value; } _s_7669c3c1_optionalCpuSignal;
typedef struct _s_7669c3c1_outStatuses { RedStatuses* value; } _s_7669c3c1_outStatuses;
typedef struct _s_7669c3c1_optionalFile { char* value; } _s_7669c3c1_optionalFile;
typedef struct _s_7669c3c1_optionalLine { int value; } _s_7669c3c1_optionalLine;
typedef struct _s_7669c3c1_optionalUserData { void* value; } _s_7669c3c1_optionalUserData;
typedef struct _s_7669c3c1_rteParameters { void* value; } _s_7669c3c1_rteParameters;
static inline _s_7669c3c1_helperAllocatorVma _7669c3c1_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_7669c3c1_helperAllocatorVma){value}; }
static inline _s_7669c3c1_optionalCpuSignal _7669c3c1_optionalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_7669c3c1_optionalCpuSignal){value}; }
static inline _s_7669c3c1_outStatuses _7669c3c1_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_7669c3c1_outStatuses){value}; }
static inline _s_7669c3c1_optionalFile _7669c3c1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7669c3c1_optionalFile){value}; }
static inline _s_7669c3c1_optionalLine _7669c3c1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7669c3c1_optionalLine){value}; }
static inline _s_7669c3c1_optionalUserData _7669c3c1_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7669c3c1_optionalUserData){value}; }
static inline _s_7669c3c1_rteParameters _7669c3c1_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7669c3c1_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaFinalizeStagingMemory(_s_7669c3c1_helperAllocatorVma helperAllocatorVma, _s_7669c3c1_optionalCpuSignal optionalCpuSignal, _s_7669c3c1_outStatuses outStatuses, _s_7669c3c1_optionalFile optionalFile, _s_7669c3c1_optionalLine optionalLine, _s_7669c3c1_optionalUserData optionalUserData, _s_7669c3c1_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaFinalizeStagingMemory(helperAllocatorVma.value, optionalCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaReleaseStagingMemory redRteHelperAllocatorVmaReleaseStagingMemory
#define _9668fd35_helperAllocatorVma(value) value
#define _9668fd35_outStatuses(value) value
#define _9668fd35_optionalFile(value) value
#define _9668fd35_optionalLine(value) value
#define _9668fd35_optionalUserData(value) value
#define _9668fd35_rteParameters(value) value
#else
typedef struct _s_9668fd35_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_9668fd35_helperAllocatorVma;
typedef struct _s_9668fd35_outStatuses { RedStatuses* value; } _s_9668fd35_outStatuses;
typedef struct _s_9668fd35_optionalFile { char* value; } _s_9668fd35_optionalFile;
typedef struct _s_9668fd35_optionalLine { int value; } _s_9668fd35_optionalLine;
typedef struct _s_9668fd35_optionalUserData { void* value; } _s_9668fd35_optionalUserData;
typedef struct _s_9668fd35_rteParameters { void* value; } _s_9668fd35_rteParameters;
static inline _s_9668fd35_helperAllocatorVma _9668fd35_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_9668fd35_helperAllocatorVma){value}; }
static inline _s_9668fd35_outStatuses _9668fd35_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_9668fd35_outStatuses){value}; }
static inline _s_9668fd35_optionalFile _9668fd35_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9668fd35_optionalFile){value}; }
static inline _s_9668fd35_optionalLine _9668fd35_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9668fd35_optionalLine){value}; }
static inline _s_9668fd35_optionalUserData _9668fd35_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9668fd35_optionalUserData){value}; }
static inline _s_9668fd35_rteParameters _9668fd35_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9668fd35_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaReleaseStagingMemory(_s_9668fd35_helperAllocatorVma helperAllocatorVma, _s_9668fd35_outStatuses outStatuses, _s_9668fd35_optionalFile optionalFile, _s_9668fd35_optionalLine optionalLine, _s_9668fd35_optionalUserData optionalUserData, _s_9668fd35_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaReleaseStagingMemory(helperAllocatorVma.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaMapArray redRteHelperAllocatorVmaMapArray
#define _b97ff064_helperAllocatorVma(value) value
#define _b97ff064_rteHelperArray(value) value
#define _b97ff064_rteHelperAllocatorResourceMemory(value) value
#define _b97ff064_outVolatilePointer(value) value
#define _b97ff064_outStatuses(value) value
#define _b97ff064_optionalFile(value) value
#define _b97ff064_optionalLine(value) value
#define _b97ff064_optionalUserData(value) value
#define _b97ff064_rteParameters(value) value
#else
typedef struct _s_b97ff064_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_b97ff064_helperAllocatorVma;
typedef struct _s_b97ff064_rteHelperArray { RedHandleArray value; } _s_b97ff064_rteHelperArray;
typedef struct _s_b97ff064_rteHelperAllocatorResourceMemory { void* value; } _s_b97ff064_rteHelperAllocatorResourceMemory;
typedef struct _s_b97ff064_outVolatilePointer { void** value; } _s_b97ff064_outVolatilePointer;
typedef struct _s_b97ff064_outStatuses { RedStatuses* value; } _s_b97ff064_outStatuses;
typedef struct _s_b97ff064_optionalFile { char* value; } _s_b97ff064_optionalFile;
typedef struct _s_b97ff064_optionalLine { int value; } _s_b97ff064_optionalLine;
typedef struct _s_b97ff064_optionalUserData { void* value; } _s_b97ff064_optionalUserData;
typedef struct _s_b97ff064_rteParameters { void* value; } _s_b97ff064_rteParameters;
static inline _s_b97ff064_helperAllocatorVma _b97ff064_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_b97ff064_helperAllocatorVma){value}; }
static inline _s_b97ff064_rteHelperArray _b97ff064_rteHelperArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_b97ff064_rteHelperArray){value}; }
static inline _s_b97ff064_rteHelperAllocatorResourceMemory _b97ff064_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b97ff064_rteHelperAllocatorResourceMemory){value}; }
static inline _s_b97ff064_outVolatilePointer _b97ff064_outVolatilePointer(void** value) { return REDGPU_NP_STRUCT_INIT(_s_b97ff064_outVolatilePointer){value}; }
static inline _s_b97ff064_outStatuses _b97ff064_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b97ff064_outStatuses){value}; }
static inline _s_b97ff064_optionalFile _b97ff064_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b97ff064_optionalFile){value}; }
static inline _s_b97ff064_optionalLine _b97ff064_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b97ff064_optionalLine){value}; }
static inline _s_b97ff064_optionalUserData _b97ff064_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b97ff064_optionalUserData){value}; }
static inline _s_b97ff064_rteParameters _b97ff064_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b97ff064_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaMapArray(_s_b97ff064_helperAllocatorVma helperAllocatorVma, _s_b97ff064_rteHelperArray rteHelperArray, _s_b97ff064_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_b97ff064_outVolatilePointer outVolatilePointer, _s_b97ff064_outStatuses outStatuses, _s_b97ff064_optionalFile optionalFile, _s_b97ff064_optionalLine optionalLine, _s_b97ff064_optionalUserData optionalUserData, _s_b97ff064_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaMapArray(helperAllocatorVma.value, rteHelperArray.value, rteHelperAllocatorResourceMemory.value, outVolatilePointer.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAllocatorVmaUnmapArray redRteHelperAllocatorVmaUnmapArray
#define _319f659d_helperAllocatorVma(value) value
#define _319f659d_rteHelperArray(value) value
#define _319f659d_rteHelperAllocatorResourceMemory(value) value
#define _319f659d_outStatuses(value) value
#define _319f659d_optionalFile(value) value
#define _319f659d_optionalLine(value) value
#define _319f659d_optionalUserData(value) value
#define _319f659d_rteParameters(value) value
#else
typedef struct _s_319f659d_helperAllocatorVma { RedRteHandleHelperAllocatorVma value; } _s_319f659d_helperAllocatorVma;
typedef struct _s_319f659d_rteHelperArray { RedHandleArray value; } _s_319f659d_rteHelperArray;
typedef struct _s_319f659d_rteHelperAllocatorResourceMemory { void* value; } _s_319f659d_rteHelperAllocatorResourceMemory;
typedef struct _s_319f659d_outStatuses { RedStatuses* value; } _s_319f659d_outStatuses;
typedef struct _s_319f659d_optionalFile { char* value; } _s_319f659d_optionalFile;
typedef struct _s_319f659d_optionalLine { int value; } _s_319f659d_optionalLine;
typedef struct _s_319f659d_optionalUserData { void* value; } _s_319f659d_optionalUserData;
typedef struct _s_319f659d_rteParameters { void* value; } _s_319f659d_rteParameters;
static inline _s_319f659d_helperAllocatorVma _319f659d_helperAllocatorVma(RedRteHandleHelperAllocatorVma value) { return REDGPU_NP_STRUCT_INIT(_s_319f659d_helperAllocatorVma){value}; }
static inline _s_319f659d_rteHelperArray _319f659d_rteHelperArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_319f659d_rteHelperArray){value}; }
static inline _s_319f659d_rteHelperAllocatorResourceMemory _319f659d_rteHelperAllocatorResourceMemory(void* value) { return REDGPU_NP_STRUCT_INIT(_s_319f659d_rteHelperAllocatorResourceMemory){value}; }
static inline _s_319f659d_outStatuses _319f659d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_319f659d_outStatuses){value}; }
static inline _s_319f659d_optionalFile _319f659d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_319f659d_optionalFile){value}; }
static inline _s_319f659d_optionalLine _319f659d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_319f659d_optionalLine){value}; }
static inline _s_319f659d_optionalUserData _319f659d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_319f659d_optionalUserData){value}; }
static inline _s_319f659d_rteParameters _319f659d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_319f659d_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAllocatorVmaUnmapArray(_s_319f659d_helperAllocatorVma helperAllocatorVma, _s_319f659d_rteHelperArray rteHelperArray, _s_319f659d_rteHelperAllocatorResourceMemory rteHelperAllocatorResourceMemory, _s_319f659d_outStatuses outStatuses, _s_319f659d_optionalFile optionalFile, _s_319f659d_optionalLine optionalLine, _s_319f659d_optionalUserData optionalUserData, _s_319f659d_rteParameters rteParameters) {
  return redRteHelperAllocatorVmaUnmapArray(helperAllocatorVma.value, rteHelperArray.value, rteHelperAllocatorResourceMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateHelperStructs redRteCreateHelperStructs
#define _b067339d_rteContext(value) value
#define _b067339d_outHelperStructs(value) value
#define _b067339d_outStatuses(value) value
#define _b067339d_optionalFile(value) value
#define _b067339d_optionalLine(value) value
#define _b067339d_optionalUserData(value) value
#define _b067339d_rteParameters(value) value
#else
typedef struct _s_b067339d_rteContext { RedRteHandleContext value; } _s_b067339d_rteContext;
typedef struct _s_b067339d_outHelperStructs { RedRteHandleHelperStructs* value; } _s_b067339d_outHelperStructs;
typedef struct _s_b067339d_outStatuses { RedStatuses* value; } _s_b067339d_outStatuses;
typedef struct _s_b067339d_optionalFile { char* value; } _s_b067339d_optionalFile;
typedef struct _s_b067339d_optionalLine { int value; } _s_b067339d_optionalLine;
typedef struct _s_b067339d_optionalUserData { void* value; } _s_b067339d_optionalUserData;
typedef struct _s_b067339d_rteParameters { void* value; } _s_b067339d_rteParameters;
static inline _s_b067339d_rteContext _b067339d_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_b067339d_rteContext){value}; }
static inline _s_b067339d_outHelperStructs _b067339d_outHelperStructs(RedRteHandleHelperStructs* value) { return REDGPU_NP_STRUCT_INIT(_s_b067339d_outHelperStructs){value}; }
static inline _s_b067339d_outStatuses _b067339d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b067339d_outStatuses){value}; }
static inline _s_b067339d_optionalFile _b067339d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b067339d_optionalFile){value}; }
static inline _s_b067339d_optionalLine _b067339d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b067339d_optionalLine){value}; }
static inline _s_b067339d_optionalUserData _b067339d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b067339d_optionalUserData){value}; }
static inline _s_b067339d_rteParameters _b067339d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b067339d_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateHelperStructs(_s_b067339d_rteContext rteContext, _s_b067339d_outHelperStructs outHelperStructs, _s_b067339d_outStatuses outStatuses, _s_b067339d_optionalFile optionalFile, _s_b067339d_optionalLine optionalLine, _s_b067339d_optionalUserData optionalUserData, _s_b067339d_rteParameters rteParameters) {
  return redRteCreateHelperStructs(rteContext.value, outHelperStructs.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyHelperStructs redRteDestroyHelperStructs
#define _9f58d8d8_helperStructs(value) value
#define _9f58d8d8_optionalFile(value) value
#define _9f58d8d8_optionalLine(value) value
#define _9f58d8d8_optionalUserData(value) value
#define _9f58d8d8_rteParameters(value) value
#else
typedef struct _s_9f58d8d8_helperStructs { RedRteHandleHelperStructs value; } _s_9f58d8d8_helperStructs;
typedef struct _s_9f58d8d8_optionalFile { char* value; } _s_9f58d8d8_optionalFile;
typedef struct _s_9f58d8d8_optionalLine { int value; } _s_9f58d8d8_optionalLine;
typedef struct _s_9f58d8d8_optionalUserData { void* value; } _s_9f58d8d8_optionalUserData;
typedef struct _s_9f58d8d8_rteParameters { void* value; } _s_9f58d8d8_rteParameters;
static inline _s_9f58d8d8_helperStructs _9f58d8d8_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_9f58d8d8_helperStructs){value}; }
static inline _s_9f58d8d8_optionalFile _9f58d8d8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9f58d8d8_optionalFile){value}; }
static inline _s_9f58d8d8_optionalLine _9f58d8d8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9f58d8d8_optionalLine){value}; }
static inline _s_9f58d8d8_optionalUserData _9f58d8d8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9f58d8d8_optionalUserData){value}; }
static inline _s_9f58d8d8_rteParameters _9f58d8d8_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9f58d8d8_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyHelperStructs(_s_9f58d8d8_helperStructs helperStructs, _s_9f58d8d8_optionalFile optionalFile, _s_9f58d8d8_optionalLine optionalLine, _s_9f58d8d8_optionalUserData optionalUserData, _s_9f58d8d8_rteParameters rteParameters) {
  return redRteDestroyHelperStructs(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsSetStructDeclarationMembers redRteHelperStructsSetStructDeclarationMembers
#define _15705d58_helperStructs(value) value
#define _15705d58_structDeclarationMembersCount(value) value
#define _15705d58_structDeclarationMembers(value) value
#define _15705d58_structDeclarationMembersArrayROCount(value) value
#define _15705d58_structDeclarationMembersArrayRO(value) value
#define _15705d58_optionalFile(value) value
#define _15705d58_optionalLine(value) value
#define _15705d58_optionalUserData(value) value
#define _15705d58_rteParameters(value) value
#else
typedef struct _s_15705d58_helperStructs { RedRteHandleHelperStructs value; } _s_15705d58_helperStructs;
typedef struct _s_15705d58_structDeclarationMembersCount { unsigned value; } _s_15705d58_structDeclarationMembersCount;
typedef struct _s_15705d58_structDeclarationMembers { RedStructDeclarationMember* value; } _s_15705d58_structDeclarationMembers;
typedef struct _s_15705d58_structDeclarationMembersArrayROCount { unsigned value; } _s_15705d58_structDeclarationMembersArrayROCount;
typedef struct _s_15705d58_structDeclarationMembersArrayRO { RedStructDeclarationMemberArrayRO* value; } _s_15705d58_structDeclarationMembersArrayRO;
typedef struct _s_15705d58_optionalFile { char* value; } _s_15705d58_optionalFile;
typedef struct _s_15705d58_optionalLine { int value; } _s_15705d58_optionalLine;
typedef struct _s_15705d58_optionalUserData { void* value; } _s_15705d58_optionalUserData;
typedef struct _s_15705d58_rteParameters { void* value; } _s_15705d58_rteParameters;
static inline _s_15705d58_helperStructs _15705d58_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_15705d58_helperStructs){value}; }
static inline _s_15705d58_structDeclarationMembersCount _15705d58_structDeclarationMembersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_15705d58_structDeclarationMembersCount){value}; }
static inline _s_15705d58_structDeclarationMembers _15705d58_structDeclarationMembers(RedStructDeclarationMember* value) { return REDGPU_NP_STRUCT_INIT(_s_15705d58_structDeclarationMembers){value}; }
static inline _s_15705d58_structDeclarationMembersArrayROCount _15705d58_structDeclarationMembersArrayROCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_15705d58_structDeclarationMembersArrayROCount){value}; }
static inline _s_15705d58_structDeclarationMembersArrayRO _15705d58_structDeclarationMembersArrayRO(RedStructDeclarationMemberArrayRO* value) { return REDGPU_NP_STRUCT_INIT(_s_15705d58_structDeclarationMembersArrayRO){value}; }
static inline _s_15705d58_optionalFile _15705d58_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_15705d58_optionalFile){value}; }
static inline _s_15705d58_optionalLine _15705d58_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_15705d58_optionalLine){value}; }
static inline _s_15705d58_optionalUserData _15705d58_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_15705d58_optionalUserData){value}; }
static inline _s_15705d58_rteParameters _15705d58_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_15705d58_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsSetStructDeclarationMembers(_s_15705d58_helperStructs helperStructs, _s_15705d58_structDeclarationMembersCount structDeclarationMembersCount, _s_15705d58_structDeclarationMembers structDeclarationMembers, _s_15705d58_structDeclarationMembersArrayROCount structDeclarationMembersArrayROCount, _s_15705d58_structDeclarationMembersArrayRO structDeclarationMembersArrayRO, _s_15705d58_optionalFile optionalFile, _s_15705d58_optionalLine optionalLine, _s_15705d58_optionalUserData optionalUserData, _s_15705d58_rteParameters rteParameters) {
  return redRteHelperStructsSetStructDeclarationMembers(helperStructs.value, structDeclarationMembersCount.value, structDeclarationMembers.value, structDeclarationMembersArrayROCount.value, structDeclarationMembersArrayRO.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsAddStructDeclarationMember redRteHelperStructsAddStructDeclarationMember
#define _ee74312e_helperStructs(value) value
#define _ee74312e_slot(value) value
#define _ee74312e_type(value) value
#define _ee74312e_count(value) value
#define _ee74312e_visibleToStages(value) value
#define _ee74312e_inlineSampler(value) value
#define _ee74312e_slotTypeIsArrayRO(value) value
#define _ee74312e_optionalFile(value) value
#define _ee74312e_optionalLine(value) value
#define _ee74312e_optionalUserData(value) value
#define _ee74312e_rteParameters(value) value
#else
typedef struct _s_ee74312e_helperStructs { RedRteHandleHelperStructs value; } _s_ee74312e_helperStructs;
typedef struct _s_ee74312e_slot { unsigned value; } _s_ee74312e_slot;
typedef struct _s_ee74312e_type { unsigned value; } _s_ee74312e_type;
typedef struct _s_ee74312e_count { unsigned value; } _s_ee74312e_count;
typedef struct _s_ee74312e_visibleToStages { unsigned value; } _s_ee74312e_visibleToStages;
typedef struct _s_ee74312e_inlineSampler { RedHandleSampler* value; } _s_ee74312e_inlineSampler;
typedef struct _s_ee74312e_slotTypeIsArrayRO { RedBool32 value; } _s_ee74312e_slotTypeIsArrayRO;
typedef struct _s_ee74312e_optionalFile { char* value; } _s_ee74312e_optionalFile;
typedef struct _s_ee74312e_optionalLine { int value; } _s_ee74312e_optionalLine;
typedef struct _s_ee74312e_optionalUserData { void* value; } _s_ee74312e_optionalUserData;
typedef struct _s_ee74312e_rteParameters { void* value; } _s_ee74312e_rteParameters;
static inline _s_ee74312e_helperStructs _ee74312e_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_ee74312e_helperStructs){value}; }
static inline _s_ee74312e_slot _ee74312e_slot(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ee74312e_slot){value}; }
static inline _s_ee74312e_type _ee74312e_type(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ee74312e_type){value}; }
static inline _s_ee74312e_count _ee74312e_count(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ee74312e_count){value}; }
static inline _s_ee74312e_visibleToStages _ee74312e_visibleToStages(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ee74312e_visibleToStages){value}; }
static inline _s_ee74312e_inlineSampler _ee74312e_inlineSampler(RedHandleSampler* value) { return REDGPU_NP_STRUCT_INIT(_s_ee74312e_inlineSampler){value}; }
static inline _s_ee74312e_slotTypeIsArrayRO _ee74312e_slotTypeIsArrayRO(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_ee74312e_slotTypeIsArrayRO){value}; }
static inline _s_ee74312e_optionalFile _ee74312e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ee74312e_optionalFile){value}; }
static inline _s_ee74312e_optionalLine _ee74312e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ee74312e_optionalLine){value}; }
static inline _s_ee74312e_optionalUserData _ee74312e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ee74312e_optionalUserData){value}; }
static inline _s_ee74312e_rteParameters _ee74312e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ee74312e_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsAddStructDeclarationMember(_s_ee74312e_helperStructs helperStructs, _s_ee74312e_slot slot, _s_ee74312e_type type, _s_ee74312e_count count, _s_ee74312e_visibleToStages visibleToStages, _s_ee74312e_inlineSampler inlineSampler, _s_ee74312e_slotTypeIsArrayRO slotTypeIsArrayRO, _s_ee74312e_optionalFile optionalFile, _s_ee74312e_optionalLine optionalLine, _s_ee74312e_optionalUserData optionalUserData, _s_ee74312e_rteParameters rteParameters) {
  return redRteHelperStructsAddStructDeclarationMember(helperStructs.value, slot.value, type.value, count.value, visibleToStages.value, inlineSampler.value, slotTypeIsArrayRO.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsSetStructDeclarationMemberFlags redRteHelperStructsSetStructDeclarationMemberFlags
#define _1854be14_helperStructs(value) value
#define _1854be14_slot(value) value
#define _1854be14_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10(value) value
#define _1854be14_optionalFile(value) value
#define _1854be14_optionalLine(value) value
#define _1854be14_optionalUserData(value) value
#define _1854be14_rteParameters(value) value
#else
typedef struct _s_1854be14_helperStructs { RedRteHandleHelperStructs value; } _s_1854be14_helperStructs;
typedef struct _s_1854be14_slot { unsigned value; } _s_1854be14_slot;
typedef struct _s_1854be14_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10 { unsigned value; } _s_1854be14_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10;
typedef struct _s_1854be14_optionalFile { char* value; } _s_1854be14_optionalFile;
typedef struct _s_1854be14_optionalLine { int value; } _s_1854be14_optionalLine;
typedef struct _s_1854be14_optionalUserData { void* value; } _s_1854be14_optionalUserData;
typedef struct _s_1854be14_rteParameters { void* value; } _s_1854be14_rteParameters;
static inline _s_1854be14_helperStructs _1854be14_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_1854be14_helperStructs){value}; }
static inline _s_1854be14_slot _1854be14_slot(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1854be14_slot){value}; }
static inline _s_1854be14_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10 _1854be14_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1854be14_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10){value}; }
static inline _s_1854be14_optionalFile _1854be14_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1854be14_optionalFile){value}; }
static inline _s_1854be14_optionalLine _1854be14_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1854be14_optionalLine){value}; }
static inline _s_1854be14_optionalUserData _1854be14_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1854be14_optionalUserData){value}; }
static inline _s_1854be14_rteParameters _1854be14_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1854be14_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsSetStructDeclarationMemberFlags(_s_1854be14_helperStructs helperStructs, _s_1854be14_slot slot, _s_1854be14_descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10 descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10, _s_1854be14_optionalFile optionalFile, _s_1854be14_optionalLine optionalLine, _s_1854be14_optionalUserData optionalUserData, _s_1854be14_rteParameters rteParameters) {
  return redRteHelperStructsSetStructDeclarationMemberFlags(helperStructs.value, slot.value, descriptorBindingFlags_RequiresApiSupportGreaterThanVkVersion10.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsCreateStructDeclaration redRteHelperStructsCreateStructDeclaration
#define _e6cbea30_helperStructs(value) value
#define _e6cbea30_descriptorSetLayoutCreateFlags(value) value
#define _e6cbea30_apiSupport(value) value
#define _e6cbea30_outStructDeclaration(value) value
#define _e6cbea30_outStatuses(value) value
#define _e6cbea30_optionalFile(value) value
#define _e6cbea30_optionalLine(value) value
#define _e6cbea30_optionalUserData(value) value
#define _e6cbea30_rteParameters(value) value
#else
typedef struct _s_e6cbea30_helperStructs { RedRteHandleHelperStructs value; } _s_e6cbea30_helperStructs;
typedef struct _s_e6cbea30_descriptorSetLayoutCreateFlags { unsigned value; } _s_e6cbea30_descriptorSetLayoutCreateFlags;
typedef struct _s_e6cbea30_apiSupport { RedRteHelperStructsApiSupport value; } _s_e6cbea30_apiSupport;
typedef struct _s_e6cbea30_outStructDeclaration { RedHandleStructDeclaration* value; } _s_e6cbea30_outStructDeclaration;
typedef struct _s_e6cbea30_outStatuses { RedStatuses* value; } _s_e6cbea30_outStatuses;
typedef struct _s_e6cbea30_optionalFile { char* value; } _s_e6cbea30_optionalFile;
typedef struct _s_e6cbea30_optionalLine { int value; } _s_e6cbea30_optionalLine;
typedef struct _s_e6cbea30_optionalUserData { void* value; } _s_e6cbea30_optionalUserData;
typedef struct _s_e6cbea30_rteParameters { void* value; } _s_e6cbea30_rteParameters;
static inline _s_e6cbea30_helperStructs _e6cbea30_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_e6cbea30_helperStructs){value}; }
static inline _s_e6cbea30_descriptorSetLayoutCreateFlags _e6cbea30_descriptorSetLayoutCreateFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e6cbea30_descriptorSetLayoutCreateFlags){value}; }
static inline _s_e6cbea30_apiSupport _e6cbea30_apiSupport(RedRteHelperStructsApiSupport value) { return REDGPU_NP_STRUCT_INIT(_s_e6cbea30_apiSupport){value}; }
static inline _s_e6cbea30_outStructDeclaration _e6cbea30_outStructDeclaration(RedHandleStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_e6cbea30_outStructDeclaration){value}; }
static inline _s_e6cbea30_outStatuses _e6cbea30_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_e6cbea30_outStatuses){value}; }
static inline _s_e6cbea30_optionalFile _e6cbea30_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e6cbea30_optionalFile){value}; }
static inline _s_e6cbea30_optionalLine _e6cbea30_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e6cbea30_optionalLine){value}; }
static inline _s_e6cbea30_optionalUserData _e6cbea30_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e6cbea30_optionalUserData){value}; }
static inline _s_e6cbea30_rteParameters _e6cbea30_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e6cbea30_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsCreateStructDeclaration(_s_e6cbea30_helperStructs helperStructs, _s_e6cbea30_descriptorSetLayoutCreateFlags descriptorSetLayoutCreateFlags, _s_e6cbea30_apiSupport apiSupport, _s_e6cbea30_outStructDeclaration outStructDeclaration, _s_e6cbea30_outStatuses outStatuses, _s_e6cbea30_optionalFile optionalFile, _s_e6cbea30_optionalLine optionalLine, _s_e6cbea30_optionalUserData optionalUserData, _s_e6cbea30_rteParameters rteParameters) {
  return redRteHelperStructsCreateStructDeclaration(helperStructs.value, descriptorSetLayoutCreateFlags.value, apiSupport.value, outStructDeclaration.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsCreateStructsMemory redRteHelperStructsCreateStructsMemory
#define _fa0475c5_helperStructs(value) value
#define _fa0475c5_allocateStructsCount(value) value
#define _fa0475c5_outStructsMemory(value) value
#define _fa0475c5_outStatuses(value) value
#define _fa0475c5_optionalFile(value) value
#define _fa0475c5_optionalLine(value) value
#define _fa0475c5_optionalUserData(value) value
#define _fa0475c5_rteParameters(value) value
#else
typedef struct _s_fa0475c5_helperStructs { RedRteHandleHelperStructs value; } _s_fa0475c5_helperStructs;
typedef struct _s_fa0475c5_allocateStructsCount { unsigned value; } _s_fa0475c5_allocateStructsCount;
typedef struct _s_fa0475c5_outStructsMemory { RedHandleStructsMemory* value; } _s_fa0475c5_outStructsMemory;
typedef struct _s_fa0475c5_outStatuses { RedStatuses* value; } _s_fa0475c5_outStatuses;
typedef struct _s_fa0475c5_optionalFile { char* value; } _s_fa0475c5_optionalFile;
typedef struct _s_fa0475c5_optionalLine { int value; } _s_fa0475c5_optionalLine;
typedef struct _s_fa0475c5_optionalUserData { void* value; } _s_fa0475c5_optionalUserData;
typedef struct _s_fa0475c5_rteParameters { void* value; } _s_fa0475c5_rteParameters;
static inline _s_fa0475c5_helperStructs _fa0475c5_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_fa0475c5_helperStructs){value}; }
static inline _s_fa0475c5_allocateStructsCount _fa0475c5_allocateStructsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_fa0475c5_allocateStructsCount){value}; }
static inline _s_fa0475c5_outStructsMemory _fa0475c5_outStructsMemory(RedHandleStructsMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_fa0475c5_outStructsMemory){value}; }
static inline _s_fa0475c5_outStatuses _fa0475c5_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_fa0475c5_outStatuses){value}; }
static inline _s_fa0475c5_optionalFile _fa0475c5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fa0475c5_optionalFile){value}; }
static inline _s_fa0475c5_optionalLine _fa0475c5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fa0475c5_optionalLine){value}; }
static inline _s_fa0475c5_optionalUserData _fa0475c5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fa0475c5_optionalUserData){value}; }
static inline _s_fa0475c5_rteParameters _fa0475c5_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fa0475c5_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsCreateStructsMemory(_s_fa0475c5_helperStructs helperStructs, _s_fa0475c5_allocateStructsCount allocateStructsCount, _s_fa0475c5_outStructsMemory outStructsMemory, _s_fa0475c5_outStatuses outStatuses, _s_fa0475c5_optionalFile optionalFile, _s_fa0475c5_optionalLine optionalLine, _s_fa0475c5_optionalUserData optionalUserData, _s_fa0475c5_rteParameters rteParameters) {
  return redRteHelperStructsCreateStructsMemory(helperStructs.value, allocateStructsCount.value, outStructsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsGetStruct redRteHelperStructsGetStruct
#define _33a64c45_helperStructs(value) value
#define _33a64c45_structIndex(value) value
#define _33a64c45_optionalFile(value) value
#define _33a64c45_optionalLine(value) value
#define _33a64c45_optionalUserData(value) value
#define _33a64c45_rteParameters(value) value
#else
typedef struct _s_33a64c45_helperStructs { RedRteHandleHelperStructs value; } _s_33a64c45_helperStructs;
typedef struct _s_33a64c45_structIndex { unsigned value; } _s_33a64c45_structIndex;
typedef struct _s_33a64c45_optionalFile { char* value; } _s_33a64c45_optionalFile;
typedef struct _s_33a64c45_optionalLine { int value; } _s_33a64c45_optionalLine;
typedef struct _s_33a64c45_optionalUserData { void* value; } _s_33a64c45_optionalUserData;
typedef struct _s_33a64c45_rteParameters { void* value; } _s_33a64c45_rteParameters;
static inline _s_33a64c45_helperStructs _33a64c45_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_33a64c45_helperStructs){value}; }
static inline _s_33a64c45_structIndex _33a64c45_structIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_33a64c45_structIndex){value}; }
static inline _s_33a64c45_optionalFile _33a64c45_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_33a64c45_optionalFile){value}; }
static inline _s_33a64c45_optionalLine _33a64c45_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_33a64c45_optionalLine){value}; }
static inline _s_33a64c45_optionalUserData _33a64c45_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_33a64c45_optionalUserData){value}; }
static inline _s_33a64c45_rteParameters _33a64c45_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_33a64c45_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleStruct REDGPU_NP_API np_redRteHelperStructsGetStruct(_s_33a64c45_helperStructs helperStructs, _s_33a64c45_structIndex structIndex, _s_33a64c45_optionalFile optionalFile, _s_33a64c45_optionalLine optionalLine, _s_33a64c45_optionalUserData optionalUserData, _s_33a64c45_rteParameters rteParameters) {
  return redRteHelperStructsGetStruct(helperStructs.value, structIndex.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsGetStructsCount redRteHelperStructsGetStructsCount
#define _4aa08b46_helperStructs(value) value
#define _4aa08b46_optionalFile(value) value
#define _4aa08b46_optionalLine(value) value
#define _4aa08b46_optionalUserData(value) value
#define _4aa08b46_rteParameters(value) value
#else
typedef struct _s_4aa08b46_helperStructs { RedRteHandleHelperStructs value; } _s_4aa08b46_helperStructs;
typedef struct _s_4aa08b46_optionalFile { char* value; } _s_4aa08b46_optionalFile;
typedef struct _s_4aa08b46_optionalLine { int value; } _s_4aa08b46_optionalLine;
typedef struct _s_4aa08b46_optionalUserData { void* value; } _s_4aa08b46_optionalUserData;
typedef struct _s_4aa08b46_rteParameters { void* value; } _s_4aa08b46_rteParameters;
static inline _s_4aa08b46_helperStructs _4aa08b46_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_4aa08b46_helperStructs){value}; }
static inline _s_4aa08b46_optionalFile _4aa08b46_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4aa08b46_optionalFile){value}; }
static inline _s_4aa08b46_optionalLine _4aa08b46_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4aa08b46_optionalLine){value}; }
static inline _s_4aa08b46_optionalUserData _4aa08b46_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4aa08b46_optionalUserData){value}; }
static inline _s_4aa08b46_rteParameters _4aa08b46_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4aa08b46_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redRteHelperStructsGetStructsCount(_s_4aa08b46_helperStructs helperStructs, _s_4aa08b46_optionalFile optionalFile, _s_4aa08b46_optionalLine optionalLine, _s_4aa08b46_optionalUserData optionalUserData, _s_4aa08b46_rteParameters rteParameters) {
  return redRteHelperStructsGetStructsCount(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsGetStructs redRteHelperStructsGetStructs
#define _2110b40a_helperStructs(value) value
#define _2110b40a_optionalFile(value) value
#define _2110b40a_optionalLine(value) value
#define _2110b40a_optionalUserData(value) value
#define _2110b40a_rteParameters(value) value
#else
typedef struct _s_2110b40a_helperStructs { RedRteHandleHelperStructs value; } _s_2110b40a_helperStructs;
typedef struct _s_2110b40a_optionalFile { char* value; } _s_2110b40a_optionalFile;
typedef struct _s_2110b40a_optionalLine { int value; } _s_2110b40a_optionalLine;
typedef struct _s_2110b40a_optionalUserData { void* value; } _s_2110b40a_optionalUserData;
typedef struct _s_2110b40a_rteParameters { void* value; } _s_2110b40a_rteParameters;
static inline _s_2110b40a_helperStructs _2110b40a_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_2110b40a_helperStructs){value}; }
static inline _s_2110b40a_optionalFile _2110b40a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2110b40a_optionalFile){value}; }
static inline _s_2110b40a_optionalLine _2110b40a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2110b40a_optionalLine){value}; }
static inline _s_2110b40a_optionalUserData _2110b40a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2110b40a_optionalUserData){value}; }
static inline _s_2110b40a_rteParameters _2110b40a_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2110b40a_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleStruct* REDGPU_NP_API np_redRteHelperStructsGetStructs(_s_2110b40a_helperStructs helperStructs, _s_2110b40a_optionalFile optionalFile, _s_2110b40a_optionalLine optionalLine, _s_2110b40a_optionalUserData optionalUserData, _s_2110b40a_rteParameters rteParameters) {
  return redRteHelperStructsGetStructs(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsGetStructDeclarationMembersCount redRteHelperStructsGetStructDeclarationMembersCount
#define _e1e56aba_helperStructs(value) value
#define _e1e56aba_optionalFile(value) value
#define _e1e56aba_optionalLine(value) value
#define _e1e56aba_optionalUserData(value) value
#define _e1e56aba_rteParameters(value) value
#else
typedef struct _s_e1e56aba_helperStructs { RedRteHandleHelperStructs value; } _s_e1e56aba_helperStructs;
typedef struct _s_e1e56aba_optionalFile { char* value; } _s_e1e56aba_optionalFile;
typedef struct _s_e1e56aba_optionalLine { int value; } _s_e1e56aba_optionalLine;
typedef struct _s_e1e56aba_optionalUserData { void* value; } _s_e1e56aba_optionalUserData;
typedef struct _s_e1e56aba_rteParameters { void* value; } _s_e1e56aba_rteParameters;
static inline _s_e1e56aba_helperStructs _e1e56aba_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_e1e56aba_helperStructs){value}; }
static inline _s_e1e56aba_optionalFile _e1e56aba_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e1e56aba_optionalFile){value}; }
static inline _s_e1e56aba_optionalLine _e1e56aba_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e1e56aba_optionalLine){value}; }
static inline _s_e1e56aba_optionalUserData _e1e56aba_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e1e56aba_optionalUserData){value}; }
static inline _s_e1e56aba_rteParameters _e1e56aba_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e1e56aba_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redRteHelperStructsGetStructDeclarationMembersCount(_s_e1e56aba_helperStructs helperStructs, _s_e1e56aba_optionalFile optionalFile, _s_e1e56aba_optionalLine optionalLine, _s_e1e56aba_optionalUserData optionalUserData, _s_e1e56aba_rteParameters rteParameters) {
  return redRteHelperStructsGetStructDeclarationMembersCount(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsGetStructDeclarationMembers redRteHelperStructsGetStructDeclarationMembers
#define _d5021575_helperStructs(value) value
#define _d5021575_optionalFile(value) value
#define _d5021575_optionalLine(value) value
#define _d5021575_optionalUserData(value) value
#define _d5021575_rteParameters(value) value
#else
typedef struct _s_d5021575_helperStructs { RedRteHandleHelperStructs value; } _s_d5021575_helperStructs;
typedef struct _s_d5021575_optionalFile { char* value; } _s_d5021575_optionalFile;
typedef struct _s_d5021575_optionalLine { int value; } _s_d5021575_optionalLine;
typedef struct _s_d5021575_optionalUserData { void* value; } _s_d5021575_optionalUserData;
typedef struct _s_d5021575_rteParameters { void* value; } _s_d5021575_rteParameters;
static inline _s_d5021575_helperStructs _d5021575_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_d5021575_helperStructs){value}; }
static inline _s_d5021575_optionalFile _d5021575_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d5021575_optionalFile){value}; }
static inline _s_d5021575_optionalLine _d5021575_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d5021575_optionalLine){value}; }
static inline _s_d5021575_optionalUserData _d5021575_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d5021575_optionalUserData){value}; }
static inline _s_d5021575_rteParameters _d5021575_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d5021575_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedStructDeclarationMember* REDGPU_NP_API np_redRteHelperStructsGetStructDeclarationMembers(_s_d5021575_helperStructs helperStructs, _s_d5021575_optionalFile optionalFile, _s_d5021575_optionalLine optionalLine, _s_d5021575_optionalUserData optionalUserData, _s_d5021575_rteParameters rteParameters) {
  return redRteHelperStructsGetStructDeclarationMembers(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsDestroyStructDeclaration redRteHelperStructsDestroyStructDeclaration
#define _f157daef_helperStructs(value) value
#define _f157daef_optionalFile(value) value
#define _f157daef_optionalLine(value) value
#define _f157daef_optionalUserData(value) value
#define _f157daef_rteParameters(value) value
#else
typedef struct _s_f157daef_helperStructs { RedRteHandleHelperStructs value; } _s_f157daef_helperStructs;
typedef struct _s_f157daef_optionalFile { char* value; } _s_f157daef_optionalFile;
typedef struct _s_f157daef_optionalLine { int value; } _s_f157daef_optionalLine;
typedef struct _s_f157daef_optionalUserData { void* value; } _s_f157daef_optionalUserData;
typedef struct _s_f157daef_rteParameters { void* value; } _s_f157daef_rteParameters;
static inline _s_f157daef_helperStructs _f157daef_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_f157daef_helperStructs){value}; }
static inline _s_f157daef_optionalFile _f157daef_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f157daef_optionalFile){value}; }
static inline _s_f157daef_optionalLine _f157daef_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f157daef_optionalLine){value}; }
static inline _s_f157daef_optionalUserData _f157daef_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f157daef_optionalUserData){value}; }
static inline _s_f157daef_rteParameters _f157daef_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f157daef_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsDestroyStructDeclaration(_s_f157daef_helperStructs helperStructs, _s_f157daef_optionalFile optionalFile, _s_f157daef_optionalLine optionalLine, _s_f157daef_optionalUserData optionalUserData, _s_f157daef_rteParameters rteParameters) {
  return redRteHelperStructsDestroyStructDeclaration(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsDestroyStructsMemory redRteHelperStructsDestroyStructsMemory
#define _bff64002_helperStructs(value) value
#define _bff64002_optionalFile(value) value
#define _bff64002_optionalLine(value) value
#define _bff64002_optionalUserData(value) value
#define _bff64002_rteParameters(value) value
#else
typedef struct _s_bff64002_helperStructs { RedRteHandleHelperStructs value; } _s_bff64002_helperStructs;
typedef struct _s_bff64002_optionalFile { char* value; } _s_bff64002_optionalFile;
typedef struct _s_bff64002_optionalLine { int value; } _s_bff64002_optionalLine;
typedef struct _s_bff64002_optionalUserData { void* value; } _s_bff64002_optionalUserData;
typedef struct _s_bff64002_rteParameters { void* value; } _s_bff64002_rteParameters;
static inline _s_bff64002_helperStructs _bff64002_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_bff64002_helperStructs){value}; }
static inline _s_bff64002_optionalFile _bff64002_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bff64002_optionalFile){value}; }
static inline _s_bff64002_optionalLine _bff64002_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bff64002_optionalLine){value}; }
static inline _s_bff64002_optionalUserData _bff64002_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bff64002_optionalUserData){value}; }
static inline _s_bff64002_rteParameters _bff64002_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bff64002_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsDestroyStructsMemory(_s_bff64002_helperStructs helperStructs, _s_bff64002_optionalFile optionalFile, _s_bff64002_optionalLine optionalLine, _s_bff64002_optionalUserData optionalUserData, _s_bff64002_rteParameters rteParameters) {
  return redRteHelperStructsDestroyStructsMemory(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperStructsClear redRteHelperStructsClear
#define _1e878315_helperStructs(value) value
#define _1e878315_optionalFile(value) value
#define _1e878315_optionalLine(value) value
#define _1e878315_optionalUserData(value) value
#define _1e878315_rteParameters(value) value
#else
typedef struct _s_1e878315_helperStructs { RedRteHandleHelperStructs value; } _s_1e878315_helperStructs;
typedef struct _s_1e878315_optionalFile { char* value; } _s_1e878315_optionalFile;
typedef struct _s_1e878315_optionalLine { int value; } _s_1e878315_optionalLine;
typedef struct _s_1e878315_optionalUserData { void* value; } _s_1e878315_optionalUserData;
typedef struct _s_1e878315_rteParameters { void* value; } _s_1e878315_rteParameters;
static inline _s_1e878315_helperStructs _1e878315_helperStructs(RedRteHandleHelperStructs value) { return REDGPU_NP_STRUCT_INIT(_s_1e878315_helperStructs){value}; }
static inline _s_1e878315_optionalFile _1e878315_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1e878315_optionalFile){value}; }
static inline _s_1e878315_optionalLine _1e878315_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1e878315_optionalLine){value}; }
static inline _s_1e878315_optionalUserData _1e878315_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1e878315_optionalUserData){value}; }
static inline _s_1e878315_rteParameters _1e878315_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1e878315_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperStructsClear(_s_1e878315_helperStructs helperStructs, _s_1e878315_optionalFile optionalFile, _s_1e878315_optionalLine optionalLine, _s_1e878315_optionalUserData optionalUserData, _s_1e878315_rteParameters rteParameters) {
  return redRteHelperStructsClear(helperStructs.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateRayTracingBuilder redRteCreateRayTracingBuilder
#define _82797fe6_rteContext(value) value
#define _82797fe6_rteHandleHelperAllocator(value) value
#define _82797fe6_queueFamilyIndex(value) value
#define _82797fe6_outRayTracingBuilder(value) value
#define _82797fe6_outStatuses(value) value
#define _82797fe6_optionalFile(value) value
#define _82797fe6_optionalLine(value) value
#define _82797fe6_optionalUserData(value) value
#define _82797fe6_rteParameters(value) value
#else
typedef struct _s_82797fe6_rteContext { RedRteHandleContext value; } _s_82797fe6_rteContext;
typedef struct _s_82797fe6_rteHandleHelperAllocator { void* value; } _s_82797fe6_rteHandleHelperAllocator;
typedef struct _s_82797fe6_queueFamilyIndex { unsigned value; } _s_82797fe6_queueFamilyIndex;
typedef struct _s_82797fe6_outRayTracingBuilder { RedRteHandleRayTracingBuilder* value; } _s_82797fe6_outRayTracingBuilder;
typedef struct _s_82797fe6_outStatuses { RedStatuses* value; } _s_82797fe6_outStatuses;
typedef struct _s_82797fe6_optionalFile { char* value; } _s_82797fe6_optionalFile;
typedef struct _s_82797fe6_optionalLine { int value; } _s_82797fe6_optionalLine;
typedef struct _s_82797fe6_optionalUserData { void* value; } _s_82797fe6_optionalUserData;
typedef struct _s_82797fe6_rteParameters { void* value; } _s_82797fe6_rteParameters;
static inline _s_82797fe6_rteContext _82797fe6_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_82797fe6_rteContext){value}; }
static inline _s_82797fe6_rteHandleHelperAllocator _82797fe6_rteHandleHelperAllocator(void* value) { return REDGPU_NP_STRUCT_INIT(_s_82797fe6_rteHandleHelperAllocator){value}; }
static inline _s_82797fe6_queueFamilyIndex _82797fe6_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_82797fe6_queueFamilyIndex){value}; }
static inline _s_82797fe6_outRayTracingBuilder _82797fe6_outRayTracingBuilder(RedRteHandleRayTracingBuilder* value) { return REDGPU_NP_STRUCT_INIT(_s_82797fe6_outRayTracingBuilder){value}; }
static inline _s_82797fe6_outStatuses _82797fe6_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_82797fe6_outStatuses){value}; }
static inline _s_82797fe6_optionalFile _82797fe6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_82797fe6_optionalFile){value}; }
static inline _s_82797fe6_optionalLine _82797fe6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_82797fe6_optionalLine){value}; }
static inline _s_82797fe6_optionalUserData _82797fe6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_82797fe6_optionalUserData){value}; }
static inline _s_82797fe6_rteParameters _82797fe6_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_82797fe6_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateRayTracingBuilder(_s_82797fe6_rteContext rteContext, _s_82797fe6_rteHandleHelperAllocator rteHandleHelperAllocator, _s_82797fe6_queueFamilyIndex queueFamilyIndex, _s_82797fe6_outRayTracingBuilder outRayTracingBuilder, _s_82797fe6_outStatuses outStatuses, _s_82797fe6_optionalFile optionalFile, _s_82797fe6_optionalLine optionalLine, _s_82797fe6_optionalUserData optionalUserData, _s_82797fe6_rteParameters rteParameters) {
  return redRteCreateRayTracingBuilder(rteContext.value, rteHandleHelperAllocator.value, queueFamilyIndex.value, outRayTracingBuilder.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyRayTracingBuilder redRteDestroyRayTracingBuilder
#define _04ddebc9_rayTracingBuilder(value) value
#define _04ddebc9_optionalFile(value) value
#define _04ddebc9_optionalLine(value) value
#define _04ddebc9_optionalUserData(value) value
#define _04ddebc9_rteParameters(value) value
#else
typedef struct _s_04ddebc9_rayTracingBuilder { RedRteHandleRayTracingBuilder value; } _s_04ddebc9_rayTracingBuilder;
typedef struct _s_04ddebc9_optionalFile { char* value; } _s_04ddebc9_optionalFile;
typedef struct _s_04ddebc9_optionalLine { int value; } _s_04ddebc9_optionalLine;
typedef struct _s_04ddebc9_optionalUserData { void* value; } _s_04ddebc9_optionalUserData;
typedef struct _s_04ddebc9_rteParameters { void* value; } _s_04ddebc9_rteParameters;
static inline _s_04ddebc9_rayTracingBuilder _04ddebc9_rayTracingBuilder(RedRteHandleRayTracingBuilder value) { return REDGPU_NP_STRUCT_INIT(_s_04ddebc9_rayTracingBuilder){value}; }
static inline _s_04ddebc9_optionalFile _04ddebc9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_04ddebc9_optionalFile){value}; }
static inline _s_04ddebc9_optionalLine _04ddebc9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_04ddebc9_optionalLine){value}; }
static inline _s_04ddebc9_optionalUserData _04ddebc9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_04ddebc9_optionalUserData){value}; }
static inline _s_04ddebc9_rteParameters _04ddebc9_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_04ddebc9_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyRayTracingBuilder(_s_04ddebc9_rayTracingBuilder rayTracingBuilder, _s_04ddebc9_optionalFile optionalFile, _s_04ddebc9_optionalLine optionalLine, _s_04ddebc9_optionalUserData optionalUserData, _s_04ddebc9_rteParameters rteParameters) {
  return redRteDestroyRayTracingBuilder(rayTracingBuilder.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteRayTracingBuilderBuildBlas redRteRayTracingBuilderBuildBlas
#define _bcffcf1d_rayTracingBuilder(value) value
#define _bcffcf1d_blasInputsCount(value) value
#define _bcffcf1d_blasInputs(value) value
#define _bcffcf1d_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit(value) value
#define _bcffcf1d_outStatuses(value) value
#define _bcffcf1d_optionalFile(value) value
#define _bcffcf1d_optionalLine(value) value
#define _bcffcf1d_optionalUserData(value) value
#define _bcffcf1d_rteParameters(value) value
#else
typedef struct _s_bcffcf1d_rayTracingBuilder { RedRteHandleRayTracingBuilder value; } _s_bcffcf1d_rayTracingBuilder;
typedef struct _s_bcffcf1d_blasInputsCount { unsigned value; } _s_bcffcf1d_blasInputsCount;
typedef struct _s_bcffcf1d_blasInputs { RedRteRayTracingBuilderBlasInput* value; } _s_bcffcf1d_blasInputs;
typedef struct _s_bcffcf1d_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit { unsigned value; } _s_bcffcf1d_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit;
typedef struct _s_bcffcf1d_outStatuses { RedStatuses* value; } _s_bcffcf1d_outStatuses;
typedef struct _s_bcffcf1d_optionalFile { char* value; } _s_bcffcf1d_optionalFile;
typedef struct _s_bcffcf1d_optionalLine { int value; } _s_bcffcf1d_optionalLine;
typedef struct _s_bcffcf1d_optionalUserData { void* value; } _s_bcffcf1d_optionalUserData;
typedef struct _s_bcffcf1d_rteParameters { void* value; } _s_bcffcf1d_rteParameters;
static inline _s_bcffcf1d_rayTracingBuilder _bcffcf1d_rayTracingBuilder(RedRteHandleRayTracingBuilder value) { return REDGPU_NP_STRUCT_INIT(_s_bcffcf1d_rayTracingBuilder){value}; }
static inline _s_bcffcf1d_blasInputsCount _bcffcf1d_blasInputsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bcffcf1d_blasInputsCount){value}; }
static inline _s_bcffcf1d_blasInputs _bcffcf1d_blasInputs(RedRteRayTracingBuilderBlasInput* value) { return REDGPU_NP_STRUCT_INIT(_s_bcffcf1d_blasInputs){value}; }
static inline _s_bcffcf1d_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit _bcffcf1d_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bcffcf1d_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit){value}; }
static inline _s_bcffcf1d_outStatuses _bcffcf1d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_bcffcf1d_outStatuses){value}; }
static inline _s_bcffcf1d_optionalFile _bcffcf1d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bcffcf1d_optionalFile){value}; }
static inline _s_bcffcf1d_optionalLine _bcffcf1d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bcffcf1d_optionalLine){value}; }
static inline _s_bcffcf1d_optionalUserData _bcffcf1d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bcffcf1d_optionalUserData){value}; }
static inline _s_bcffcf1d_rteParameters _bcffcf1d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bcffcf1d_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteRayTracingBuilderBuildBlas(_s_bcffcf1d_rayTracingBuilder rayTracingBuilder, _s_bcffcf1d_blasInputsCount blasInputsCount, _s_bcffcf1d_blasInputs blasInputs, _s_bcffcf1d_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit, _s_bcffcf1d_outStatuses outStatuses, _s_bcffcf1d_optionalFile optionalFile, _s_bcffcf1d_optionalLine optionalLine, _s_bcffcf1d_optionalUserData optionalUserData, _s_bcffcf1d_rteParameters rteParameters) {
  return redRteRayTracingBuilderBuildBlas(rayTracingBuilder.value, blasInputsCount.value, blasInputs.value, buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteRayTracingBuilderGetBlasGpuAddress redRteRayTracingBuilderGetBlasGpuAddress
#define _d945c6a4_rayTracingBuilder(value) value
#define _d945c6a4_blasIndex(value) value
#define _d945c6a4_optionalFile(value) value
#define _d945c6a4_optionalLine(value) value
#define _d945c6a4_optionalUserData(value) value
#define _d945c6a4_rteParameters(value) value
#else
typedef struct _s_d945c6a4_rayTracingBuilder { RedRteHandleRayTracingBuilder value; } _s_d945c6a4_rayTracingBuilder;
typedef struct _s_d945c6a4_blasIndex { unsigned value; } _s_d945c6a4_blasIndex;
typedef struct _s_d945c6a4_optionalFile { char* value; } _s_d945c6a4_optionalFile;
typedef struct _s_d945c6a4_optionalLine { int value; } _s_d945c6a4_optionalLine;
typedef struct _s_d945c6a4_optionalUserData { void* value; } _s_d945c6a4_optionalUserData;
typedef struct _s_d945c6a4_rteParameters { void* value; } _s_d945c6a4_rteParameters;
static inline _s_d945c6a4_rayTracingBuilder _d945c6a4_rayTracingBuilder(RedRteHandleRayTracingBuilder value) { return REDGPU_NP_STRUCT_INIT(_s_d945c6a4_rayTracingBuilder){value}; }
static inline _s_d945c6a4_blasIndex _d945c6a4_blasIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_d945c6a4_blasIndex){value}; }
static inline _s_d945c6a4_optionalFile _d945c6a4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d945c6a4_optionalFile){value}; }
static inline _s_d945c6a4_optionalLine _d945c6a4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d945c6a4_optionalLine){value}; }
static inline _s_d945c6a4_optionalUserData _d945c6a4_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d945c6a4_optionalUserData){value}; }
static inline _s_d945c6a4_rteParameters _d945c6a4_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d945c6a4_rteParameters){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redRteRayTracingBuilderGetBlasGpuAddress(_s_d945c6a4_rayTracingBuilder rayTracingBuilder, _s_d945c6a4_blasIndex blasIndex, _s_d945c6a4_optionalFile optionalFile, _s_d945c6a4_optionalLine optionalLine, _s_d945c6a4_optionalUserData optionalUserData, _s_d945c6a4_rteParameters rteParameters) {
  return redRteRayTracingBuilderGetBlasGpuAddress(rayTracingBuilder.value, blasIndex.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteRayTracingBuilderBuildTlas redRteRayTracingBuilderBuildTlas
#define _82df1c51_rayTracingBuilder(value) value
#define _82df1c51_instancesCount(value) value
#define _82df1c51_instances(value) value
#define _82df1c51_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit(value) value
#define _82df1c51_update(value) value
#define _82df1c51_outStatuses(value) value
#define _82df1c51_optionalFile(value) value
#define _82df1c51_optionalLine(value) value
#define _82df1c51_optionalUserData(value) value
#define _82df1c51_rteParameters(value) value
#else
typedef struct _s_82df1c51_rayTracingBuilder { RedRteHandleRayTracingBuilder value; } _s_82df1c51_rayTracingBuilder;
typedef struct _s_82df1c51_instancesCount { unsigned value; } _s_82df1c51_instancesCount;
typedef struct _s_82df1c51_instances { RedRteRayTracingAccelerationStructureInstance* value; } _s_82df1c51_instances;
typedef struct _s_82df1c51_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit { unsigned value; } _s_82df1c51_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit;
typedef struct _s_82df1c51_update { RedBool32 value; } _s_82df1c51_update;
typedef struct _s_82df1c51_outStatuses { RedStatuses* value; } _s_82df1c51_outStatuses;
typedef struct _s_82df1c51_optionalFile { char* value; } _s_82df1c51_optionalFile;
typedef struct _s_82df1c51_optionalLine { int value; } _s_82df1c51_optionalLine;
typedef struct _s_82df1c51_optionalUserData { void* value; } _s_82df1c51_optionalUserData;
typedef struct _s_82df1c51_rteParameters { void* value; } _s_82df1c51_rteParameters;
static inline _s_82df1c51_rayTracingBuilder _82df1c51_rayTracingBuilder(RedRteHandleRayTracingBuilder value) { return REDGPU_NP_STRUCT_INIT(_s_82df1c51_rayTracingBuilder){value}; }
static inline _s_82df1c51_instancesCount _82df1c51_instancesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_82df1c51_instancesCount){value}; }
static inline _s_82df1c51_instances _82df1c51_instances(RedRteRayTracingAccelerationStructureInstance* value) { return REDGPU_NP_STRUCT_INIT(_s_82df1c51_instances){value}; }
static inline _s_82df1c51_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit _82df1c51_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_82df1c51_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit){value}; }
static inline _s_82df1c51_update _82df1c51_update(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_82df1c51_update){value}; }
static inline _s_82df1c51_outStatuses _82df1c51_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_82df1c51_outStatuses){value}; }
static inline _s_82df1c51_optionalFile _82df1c51_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_82df1c51_optionalFile){value}; }
static inline _s_82df1c51_optionalLine _82df1c51_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_82df1c51_optionalLine){value}; }
static inline _s_82df1c51_optionalUserData _82df1c51_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_82df1c51_optionalUserData){value}; }
static inline _s_82df1c51_rteParameters _82df1c51_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_82df1c51_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteRayTracingBuilderBuildTlas(_s_82df1c51_rayTracingBuilder rayTracingBuilder, _s_82df1c51_instancesCount instancesCount, _s_82df1c51_instances instances, _s_82df1c51_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit, _s_82df1c51_update update, _s_82df1c51_outStatuses outStatuses, _s_82df1c51_optionalFile optionalFile, _s_82df1c51_optionalLine optionalLine, _s_82df1c51_optionalUserData optionalUserData, _s_82df1c51_rteParameters rteParameters) {
  return redRteRayTracingBuilderBuildTlas(rayTracingBuilder.value, instancesCount.value, instances.value, buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit.value, update.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteRayTracingBuilderGetTlas redRteRayTracingBuilderGetTlas
#define _02feeb79_rayTracingBuilder(value) value
#define _02feeb79_optionalFile(value) value
#define _02feeb79_optionalLine(value) value
#define _02feeb79_optionalUserData(value) value
#define _02feeb79_rteParameters(value) value
#else
typedef struct _s_02feeb79_rayTracingBuilder { RedRteHandleRayTracingBuilder value; } _s_02feeb79_rayTracingBuilder;
typedef struct _s_02feeb79_optionalFile { char* value; } _s_02feeb79_optionalFile;
typedef struct _s_02feeb79_optionalLine { int value; } _s_02feeb79_optionalLine;
typedef struct _s_02feeb79_optionalUserData { void* value; } _s_02feeb79_optionalUserData;
typedef struct _s_02feeb79_rteParameters { void* value; } _s_02feeb79_rteParameters;
static inline _s_02feeb79_rayTracingBuilder _02feeb79_rayTracingBuilder(RedRteHandleRayTracingBuilder value) { return REDGPU_NP_STRUCT_INIT(_s_02feeb79_rayTracingBuilder){value}; }
static inline _s_02feeb79_optionalFile _02feeb79_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_02feeb79_optionalFile){value}; }
static inline _s_02feeb79_optionalLine _02feeb79_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_02feeb79_optionalLine){value}; }
static inline _s_02feeb79_optionalUserData _02feeb79_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_02feeb79_optionalUserData){value}; }
static inline _s_02feeb79_rteParameters _02feeb79_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_02feeb79_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedRteHandleRayTracingAccelerationStructure REDGPU_NP_API np_redRteRayTracingBuilderGetTlas(_s_02feeb79_rayTracingBuilder rayTracingBuilder, _s_02feeb79_optionalFile optionalFile, _s_02feeb79_optionalLine optionalLine, _s_02feeb79_optionalUserData optionalUserData, _s_02feeb79_rteParameters rteParameters) {
  return redRteRayTracingBuilderGetTlas(rayTracingBuilder.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteRayTracingBuilderUpdateBlas redRteRayTracingBuilderUpdateBlas
#define _76835902_rayTracingBuilder(value) value
#define _76835902_blasIndex(value) value
#define _76835902_blasInput(value) value
#define _76835902_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit(value) value
#define _76835902_outStatuses(value) value
#define _76835902_optionalFile(value) value
#define _76835902_optionalLine(value) value
#define _76835902_optionalUserData(value) value
#define _76835902_rteParameters(value) value
#else
typedef struct _s_76835902_rayTracingBuilder { RedRteHandleRayTracingBuilder value; } _s_76835902_rayTracingBuilder;
typedef struct _s_76835902_blasIndex { unsigned value; } _s_76835902_blasIndex;
typedef struct _s_76835902_blasInput { RedRteRayTracingBuilderBlasInput* value; } _s_76835902_blasInput;
typedef struct _s_76835902_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit { unsigned value; } _s_76835902_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit;
typedef struct _s_76835902_outStatuses { RedStatuses* value; } _s_76835902_outStatuses;
typedef struct _s_76835902_optionalFile { char* value; } _s_76835902_optionalFile;
typedef struct _s_76835902_optionalLine { int value; } _s_76835902_optionalLine;
typedef struct _s_76835902_optionalUserData { void* value; } _s_76835902_optionalUserData;
typedef struct _s_76835902_rteParameters { void* value; } _s_76835902_rteParameters;
static inline _s_76835902_rayTracingBuilder _76835902_rayTracingBuilder(RedRteHandleRayTracingBuilder value) { return REDGPU_NP_STRUCT_INIT(_s_76835902_rayTracingBuilder){value}; }
static inline _s_76835902_blasIndex _76835902_blasIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_76835902_blasIndex){value}; }
static inline _s_76835902_blasInput _76835902_blasInput(RedRteRayTracingBuilderBlasInput* value) { return REDGPU_NP_STRUCT_INIT(_s_76835902_blasInput){value}; }
static inline _s_76835902_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit _76835902_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_76835902_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit){value}; }
static inline _s_76835902_outStatuses _76835902_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_76835902_outStatuses){value}; }
static inline _s_76835902_optionalFile _76835902_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_76835902_optionalFile){value}; }
static inline _s_76835902_optionalLine _76835902_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_76835902_optionalLine){value}; }
static inline _s_76835902_optionalUserData _76835902_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_76835902_optionalUserData){value}; }
static inline _s_76835902_rteParameters _76835902_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_76835902_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteRayTracingBuilderUpdateBlas(_s_76835902_rayTracingBuilder rayTracingBuilder, _s_76835902_blasIndex blasIndex, _s_76835902_blasInput blasInput, _s_76835902_buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit, _s_76835902_outStatuses outStatuses, _s_76835902_optionalFile optionalFile, _s_76835902_optionalLine optionalLine, _s_76835902_optionalUserData optionalUserData, _s_76835902_rteParameters rteParameters) {
  return redRteRayTracingBuilderUpdateBlas(rayTracingBuilder.value, blasIndex.value, blasInput.value, buildAccelerationStructureFlagsSuggestedDefaultValueIsBuildAccelerationStructurePreferFastTraceBit.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateDeferredOperation redRteCreateDeferredOperation
#define _357fb143_rteContext(value) value
#define _357fb143_outDeferredOperation(value) value
#define _357fb143_outStatuses(value) value
#define _357fb143_optionalFile(value) value
#define _357fb143_optionalLine(value) value
#define _357fb143_optionalUserData(value) value
#define _357fb143_rteParameters(value) value
#else
typedef struct _s_357fb143_rteContext { RedRteHandleContext value; } _s_357fb143_rteContext;
typedef struct _s_357fb143_outDeferredOperation { RedRteHandleDeferredOperation* value; } _s_357fb143_outDeferredOperation;
typedef struct _s_357fb143_outStatuses { RedStatuses* value; } _s_357fb143_outStatuses;
typedef struct _s_357fb143_optionalFile { char* value; } _s_357fb143_optionalFile;
typedef struct _s_357fb143_optionalLine { int value; } _s_357fb143_optionalLine;
typedef struct _s_357fb143_optionalUserData { void* value; } _s_357fb143_optionalUserData;
typedef struct _s_357fb143_rteParameters { void* value; } _s_357fb143_rteParameters;
static inline _s_357fb143_rteContext _357fb143_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_357fb143_rteContext){value}; }
static inline _s_357fb143_outDeferredOperation _357fb143_outDeferredOperation(RedRteHandleDeferredOperation* value) { return REDGPU_NP_STRUCT_INIT(_s_357fb143_outDeferredOperation){value}; }
static inline _s_357fb143_outStatuses _357fb143_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_357fb143_outStatuses){value}; }
static inline _s_357fb143_optionalFile _357fb143_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_357fb143_optionalFile){value}; }
static inline _s_357fb143_optionalLine _357fb143_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_357fb143_optionalLine){value}; }
static inline _s_357fb143_optionalUserData _357fb143_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_357fb143_optionalUserData){value}; }
static inline _s_357fb143_rteParameters _357fb143_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_357fb143_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateDeferredOperation(_s_357fb143_rteContext rteContext, _s_357fb143_outDeferredOperation outDeferredOperation, _s_357fb143_outStatuses outStatuses, _s_357fb143_optionalFile optionalFile, _s_357fb143_optionalLine optionalLine, _s_357fb143_optionalUserData optionalUserData, _s_357fb143_rteParameters rteParameters) {
  return redRteCreateDeferredOperation(rteContext.value, outDeferredOperation.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyDeferredOperation redRteDestroyDeferredOperation
#define _3124d76d_rteContext(value) value
#define _3124d76d_deferredOperation(value) value
#define _3124d76d_optionalFile(value) value
#define _3124d76d_optionalLine(value) value
#define _3124d76d_optionalUserData(value) value
#define _3124d76d_rteParameters(value) value
#else
typedef struct _s_3124d76d_rteContext { RedRteHandleContext value; } _s_3124d76d_rteContext;
typedef struct _s_3124d76d_deferredOperation { RedRteHandleDeferredOperation value; } _s_3124d76d_deferredOperation;
typedef struct _s_3124d76d_optionalFile { char* value; } _s_3124d76d_optionalFile;
typedef struct _s_3124d76d_optionalLine { int value; } _s_3124d76d_optionalLine;
typedef struct _s_3124d76d_optionalUserData { void* value; } _s_3124d76d_optionalUserData;
typedef struct _s_3124d76d_rteParameters { void* value; } _s_3124d76d_rteParameters;
static inline _s_3124d76d_rteContext _3124d76d_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_3124d76d_rteContext){value}; }
static inline _s_3124d76d_deferredOperation _3124d76d_deferredOperation(RedRteHandleDeferredOperation value) { return REDGPU_NP_STRUCT_INIT(_s_3124d76d_deferredOperation){value}; }
static inline _s_3124d76d_optionalFile _3124d76d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3124d76d_optionalFile){value}; }
static inline _s_3124d76d_optionalLine _3124d76d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3124d76d_optionalLine){value}; }
static inline _s_3124d76d_optionalUserData _3124d76d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3124d76d_optionalUserData){value}; }
static inline _s_3124d76d_rteParameters _3124d76d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3124d76d_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyDeferredOperation(_s_3124d76d_rteContext rteContext, _s_3124d76d_deferredOperation deferredOperation, _s_3124d76d_optionalFile optionalFile, _s_3124d76d_optionalLine optionalLine, _s_3124d76d_optionalUserData optionalUserData, _s_3124d76d_rteParameters rteParameters) {
  return redRteDestroyDeferredOperation(rteContext.value, deferredOperation.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDeferredOperationGetMaxConcurrency redRteDeferredOperationGetMaxConcurrency
#define _95b70208_rteContext(value) value
#define _95b70208_deferredOperation(value) value
#define _95b70208_optionalFile(value) value
#define _95b70208_optionalLine(value) value
#define _95b70208_optionalUserData(value) value
#define _95b70208_rteParameters(value) value
#else
typedef struct _s_95b70208_rteContext { RedRteHandleContext value; } _s_95b70208_rteContext;
typedef struct _s_95b70208_deferredOperation { RedRteHandleDeferredOperation value; } _s_95b70208_deferredOperation;
typedef struct _s_95b70208_optionalFile { char* value; } _s_95b70208_optionalFile;
typedef struct _s_95b70208_optionalLine { int value; } _s_95b70208_optionalLine;
typedef struct _s_95b70208_optionalUserData { void* value; } _s_95b70208_optionalUserData;
typedef struct _s_95b70208_rteParameters { void* value; } _s_95b70208_rteParameters;
static inline _s_95b70208_rteContext _95b70208_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_95b70208_rteContext){value}; }
static inline _s_95b70208_deferredOperation _95b70208_deferredOperation(RedRteHandleDeferredOperation value) { return REDGPU_NP_STRUCT_INIT(_s_95b70208_deferredOperation){value}; }
static inline _s_95b70208_optionalFile _95b70208_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_95b70208_optionalFile){value}; }
static inline _s_95b70208_optionalLine _95b70208_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_95b70208_optionalLine){value}; }
static inline _s_95b70208_optionalUserData _95b70208_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_95b70208_optionalUserData){value}; }
static inline _s_95b70208_rteParameters _95b70208_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_95b70208_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDeferredOperationGetMaxConcurrency(_s_95b70208_rteContext rteContext, _s_95b70208_deferredOperation deferredOperation, _s_95b70208_optionalFile optionalFile, _s_95b70208_optionalLine optionalLine, _s_95b70208_optionalUserData optionalUserData, _s_95b70208_rteParameters rteParameters) {
  return redRteDeferredOperationGetMaxConcurrency(rteContext.value, deferredOperation.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDeferredOperationGetStatus redRteDeferredOperationGetStatus
#define _88bd2cf5_rteContext(value) value
#define _88bd2cf5_deferredOperation(value) value
#define _88bd2cf5_optionalFile(value) value
#define _88bd2cf5_optionalLine(value) value
#define _88bd2cf5_optionalUserData(value) value
#define _88bd2cf5_rteParameters(value) value
#else
typedef struct _s_88bd2cf5_rteContext { RedRteHandleContext value; } _s_88bd2cf5_rteContext;
typedef struct _s_88bd2cf5_deferredOperation { RedRteHandleDeferredOperation value; } _s_88bd2cf5_deferredOperation;
typedef struct _s_88bd2cf5_optionalFile { char* value; } _s_88bd2cf5_optionalFile;
typedef struct _s_88bd2cf5_optionalLine { int value; } _s_88bd2cf5_optionalLine;
typedef struct _s_88bd2cf5_optionalUserData { void* value; } _s_88bd2cf5_optionalUserData;
typedef struct _s_88bd2cf5_rteParameters { void* value; } _s_88bd2cf5_rteParameters;
static inline _s_88bd2cf5_rteContext _88bd2cf5_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_88bd2cf5_rteContext){value}; }
static inline _s_88bd2cf5_deferredOperation _88bd2cf5_deferredOperation(RedRteHandleDeferredOperation value) { return REDGPU_NP_STRUCT_INIT(_s_88bd2cf5_deferredOperation){value}; }
static inline _s_88bd2cf5_optionalFile _88bd2cf5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_88bd2cf5_optionalFile){value}; }
static inline _s_88bd2cf5_optionalLine _88bd2cf5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_88bd2cf5_optionalLine){value}; }
static inline _s_88bd2cf5_optionalUserData _88bd2cf5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_88bd2cf5_optionalUserData){value}; }
static inline _s_88bd2cf5_rteParameters _88bd2cf5_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_88bd2cf5_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDeferredOperationGetStatus(_s_88bd2cf5_rteContext rteContext, _s_88bd2cf5_deferredOperation deferredOperation, _s_88bd2cf5_optionalFile optionalFile, _s_88bd2cf5_optionalLine optionalLine, _s_88bd2cf5_optionalUserData optionalUserData, _s_88bd2cf5_rteParameters rteParameters) {
  return redRteDeferredOperationGetStatus(rteContext.value, deferredOperation.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDeferredOperationJoin redRteDeferredOperationJoin
#define _164c88fb_rteContext(value) value
#define _164c88fb_deferredOperation(value) value
#define _164c88fb_optionalFile(value) value
#define _164c88fb_optionalLine(value) value
#define _164c88fb_optionalUserData(value) value
#define _164c88fb_rteParameters(value) value
#else
typedef struct _s_164c88fb_rteContext { RedRteHandleContext value; } _s_164c88fb_rteContext;
typedef struct _s_164c88fb_deferredOperation { RedRteHandleDeferredOperation value; } _s_164c88fb_deferredOperation;
typedef struct _s_164c88fb_optionalFile { char* value; } _s_164c88fb_optionalFile;
typedef struct _s_164c88fb_optionalLine { int value; } _s_164c88fb_optionalLine;
typedef struct _s_164c88fb_optionalUserData { void* value; } _s_164c88fb_optionalUserData;
typedef struct _s_164c88fb_rteParameters { void* value; } _s_164c88fb_rteParameters;
static inline _s_164c88fb_rteContext _164c88fb_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_164c88fb_rteContext){value}; }
static inline _s_164c88fb_deferredOperation _164c88fb_deferredOperation(RedRteHandleDeferredOperation value) { return REDGPU_NP_STRUCT_INIT(_s_164c88fb_deferredOperation){value}; }
static inline _s_164c88fb_optionalFile _164c88fb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_164c88fb_optionalFile){value}; }
static inline _s_164c88fb_optionalLine _164c88fb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_164c88fb_optionalLine){value}; }
static inline _s_164c88fb_optionalUserData _164c88fb_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_164c88fb_optionalUserData){value}; }
static inline _s_164c88fb_rteParameters _164c88fb_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_164c88fb_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDeferredOperationJoin(_s_164c88fb_rteContext rteContext, _s_164c88fb_deferredOperation deferredOperation, _s_164c88fb_optionalFile optionalFile, _s_164c88fb_optionalLine optionalLine, _s_164c88fb_optionalUserData optionalUserData, _s_164c88fb_rteParameters rteParameters) {
  return redRteDeferredOperationJoin(rteContext.value, deferredOperation.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateProcedureRayTracing redRteCreateProcedureRayTracing
#define _a1078651_rteContext(value) value
#define _a1078651_deferredOperation(value) value
#define _a1078651_procedureCache(value) value
#define _a1078651_state(value) value
#define _a1078651_outProcedure(value) value
#define _a1078651_outStatuses(value) value
#define _a1078651_optionalFile(value) value
#define _a1078651_optionalLine(value) value
#define _a1078651_optionalUserData(value) value
#define _a1078651_rteParameters(value) value
#else
typedef struct _s_a1078651_rteContext { RedRteHandleContext value; } _s_a1078651_rteContext;
typedef struct _s_a1078651_deferredOperation { RedRteHandleDeferredOperation value; } _s_a1078651_deferredOperation;
typedef struct _s_a1078651_procedureCache { RedHandleProcedureCache value; } _s_a1078651_procedureCache;
typedef struct _s_a1078651_state { RedRteProcedureRayTracingState* value; } _s_a1078651_state;
typedef struct _s_a1078651_outProcedure { RedHandleProcedure* value; } _s_a1078651_outProcedure;
typedef struct _s_a1078651_outStatuses { RedStatuses* value; } _s_a1078651_outStatuses;
typedef struct _s_a1078651_optionalFile { char* value; } _s_a1078651_optionalFile;
typedef struct _s_a1078651_optionalLine { int value; } _s_a1078651_optionalLine;
typedef struct _s_a1078651_optionalUserData { void* value; } _s_a1078651_optionalUserData;
typedef struct _s_a1078651_rteParameters { void* value; } _s_a1078651_rteParameters;
static inline _s_a1078651_rteContext _a1078651_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_a1078651_rteContext){value}; }
static inline _s_a1078651_deferredOperation _a1078651_deferredOperation(RedRteHandleDeferredOperation value) { return REDGPU_NP_STRUCT_INIT(_s_a1078651_deferredOperation){value}; }
static inline _s_a1078651_procedureCache _a1078651_procedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_a1078651_procedureCache){value}; }
static inline _s_a1078651_state _a1078651_state(RedRteProcedureRayTracingState* value) { return REDGPU_NP_STRUCT_INIT(_s_a1078651_state){value}; }
static inline _s_a1078651_outProcedure _a1078651_outProcedure(RedHandleProcedure* value) { return REDGPU_NP_STRUCT_INIT(_s_a1078651_outProcedure){value}; }
static inline _s_a1078651_outStatuses _a1078651_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_a1078651_outStatuses){value}; }
static inline _s_a1078651_optionalFile _a1078651_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a1078651_optionalFile){value}; }
static inline _s_a1078651_optionalLine _a1078651_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a1078651_optionalLine){value}; }
static inline _s_a1078651_optionalUserData _a1078651_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a1078651_optionalUserData){value}; }
static inline _s_a1078651_rteParameters _a1078651_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a1078651_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateProcedureRayTracing(_s_a1078651_rteContext rteContext, _s_a1078651_deferredOperation deferredOperation, _s_a1078651_procedureCache procedureCache, _s_a1078651_state state, _s_a1078651_outProcedure outProcedure, _s_a1078651_outStatuses outStatuses, _s_a1078651_optionalFile optionalFile, _s_a1078651_optionalLine optionalLine, _s_a1078651_optionalUserData optionalUserData, _s_a1078651_rteParameters rteParameters) {
  return redRteCreateProcedureRayTracing(rteContext.value, deferredOperation.value, procedureCache.value, state.value, outProcedure.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteProcedureRayTracingGetGroupCaptureReplayHandles redRteProcedureRayTracingGetGroupCaptureReplayHandles
#define _b09b393b_rteContext(value) value
#define _b09b393b_procedureRayTracing(value) value
#define _b09b393b_groupIndexFirst(value) value
#define _b09b393b_groupIndexCount(value) value
#define _b09b393b_dataBytesCount(value) value
#define _b09b393b_data(value) value
#define _b09b393b_optionalFile(value) value
#define _b09b393b_optionalLine(value) value
#define _b09b393b_optionalUserData(value) value
#define _b09b393b_rteParameters(value) value
#else
typedef struct _s_b09b393b_rteContext { RedRteHandleContext value; } _s_b09b393b_rteContext;
typedef struct _s_b09b393b_procedureRayTracing { RedHandleProcedure value; } _s_b09b393b_procedureRayTracing;
typedef struct _s_b09b393b_groupIndexFirst { unsigned value; } _s_b09b393b_groupIndexFirst;
typedef struct _s_b09b393b_groupIndexCount { unsigned value; } _s_b09b393b_groupIndexCount;
typedef struct _s_b09b393b_dataBytesCount { uint64_t value; } _s_b09b393b_dataBytesCount;
typedef struct _s_b09b393b_data { void* value; } _s_b09b393b_data;
typedef struct _s_b09b393b_optionalFile { char* value; } _s_b09b393b_optionalFile;
typedef struct _s_b09b393b_optionalLine { int value; } _s_b09b393b_optionalLine;
typedef struct _s_b09b393b_optionalUserData { void* value; } _s_b09b393b_optionalUserData;
typedef struct _s_b09b393b_rteParameters { void* value; } _s_b09b393b_rteParameters;
static inline _s_b09b393b_rteContext _b09b393b_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_b09b393b_rteContext){value}; }
static inline _s_b09b393b_procedureRayTracing _b09b393b_procedureRayTracing(RedHandleProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_b09b393b_procedureRayTracing){value}; }
static inline _s_b09b393b_groupIndexFirst _b09b393b_groupIndexFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b09b393b_groupIndexFirst){value}; }
static inline _s_b09b393b_groupIndexCount _b09b393b_groupIndexCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b09b393b_groupIndexCount){value}; }
static inline _s_b09b393b_dataBytesCount _b09b393b_dataBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_b09b393b_dataBytesCount){value}; }
static inline _s_b09b393b_data _b09b393b_data(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b09b393b_data){value}; }
static inline _s_b09b393b_optionalFile _b09b393b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b09b393b_optionalFile){value}; }
static inline _s_b09b393b_optionalLine _b09b393b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b09b393b_optionalLine){value}; }
static inline _s_b09b393b_optionalUserData _b09b393b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b09b393b_optionalUserData){value}; }
static inline _s_b09b393b_rteParameters _b09b393b_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b09b393b_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteProcedureRayTracingGetGroupCaptureReplayHandles(_s_b09b393b_rteContext rteContext, _s_b09b393b_procedureRayTracing procedureRayTracing, _s_b09b393b_groupIndexFirst groupIndexFirst, _s_b09b393b_groupIndexCount groupIndexCount, _s_b09b393b_dataBytesCount dataBytesCount, _s_b09b393b_data data, _s_b09b393b_optionalFile optionalFile, _s_b09b393b_optionalLine optionalLine, _s_b09b393b_optionalUserData optionalUserData, _s_b09b393b_rteParameters rteParameters) {
  return redRteProcedureRayTracingGetGroupCaptureReplayHandles(rteContext.value, procedureRayTracing.value, groupIndexFirst.value, groupIndexCount.value, dataBytesCount.value, data.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteProcedureRayTracingGetGroupStackBytesCount redRteProcedureRayTracingGetGroupStackBytesCount
#define _2f94b89c_rteContext(value) value
#define _2f94b89c_procedureRayTracing(value) value
#define _2f94b89c_groupIndex(value) value
#define _2f94b89c_groupStage(value) value
#define _2f94b89c_optionalFile(value) value
#define _2f94b89c_optionalLine(value) value
#define _2f94b89c_optionalUserData(value) value
#define _2f94b89c_rteParameters(value) value
#else
typedef struct _s_2f94b89c_rteContext { RedRteHandleContext value; } _s_2f94b89c_rteContext;
typedef struct _s_2f94b89c_procedureRayTracing { RedHandleProcedure value; } _s_2f94b89c_procedureRayTracing;
typedef struct _s_2f94b89c_groupIndex { unsigned value; } _s_2f94b89c_groupIndex;
typedef struct _s_2f94b89c_groupStage { RedRteProcedureRayTracingGroupStage value; } _s_2f94b89c_groupStage;
typedef struct _s_2f94b89c_optionalFile { char* value; } _s_2f94b89c_optionalFile;
typedef struct _s_2f94b89c_optionalLine { int value; } _s_2f94b89c_optionalLine;
typedef struct _s_2f94b89c_optionalUserData { void* value; } _s_2f94b89c_optionalUserData;
typedef struct _s_2f94b89c_rteParameters { void* value; } _s_2f94b89c_rteParameters;
static inline _s_2f94b89c_rteContext _2f94b89c_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_2f94b89c_rteContext){value}; }
static inline _s_2f94b89c_procedureRayTracing _2f94b89c_procedureRayTracing(RedHandleProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_2f94b89c_procedureRayTracing){value}; }
static inline _s_2f94b89c_groupIndex _2f94b89c_groupIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_2f94b89c_groupIndex){value}; }
static inline _s_2f94b89c_groupStage _2f94b89c_groupStage(RedRteProcedureRayTracingGroupStage value) { return REDGPU_NP_STRUCT_INIT(_s_2f94b89c_groupStage){value}; }
static inline _s_2f94b89c_optionalFile _2f94b89c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2f94b89c_optionalFile){value}; }
static inline _s_2f94b89c_optionalLine _2f94b89c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2f94b89c_optionalLine){value}; }
static inline _s_2f94b89c_optionalUserData _2f94b89c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2f94b89c_optionalUserData){value}; }
static inline _s_2f94b89c_rteParameters _2f94b89c_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2f94b89c_rteParameters){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redRteProcedureRayTracingGetGroupStackBytesCount(_s_2f94b89c_rteContext rteContext, _s_2f94b89c_procedureRayTracing procedureRayTracing, _s_2f94b89c_groupIndex groupIndex, _s_2f94b89c_groupStage groupStage, _s_2f94b89c_optionalFile optionalFile, _s_2f94b89c_optionalLine optionalLine, _s_2f94b89c_optionalUserData optionalUserData, _s_2f94b89c_rteParameters rteParameters) {
  return redRteProcedureRayTracingGetGroupStackBytesCount(rteContext.value, procedureRayTracing.value, groupIndex.value, groupStage.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallProcedureRayTracing redRteCallProcedureRayTracing
#define _fd876720_calls(value) value
#define _fd876720_rteContext(value) value
#define _fd876720_shaderBindingTableRayGeneration(value) value
#define _fd876720_shaderBindingTableMiss(value) value
#define _fd876720_shaderBindingTableHit(value) value
#define _fd876720_shaderBindingTableCallable(value) value
#define _fd876720_threadsCountX(value) value
#define _fd876720_threadsCountY(value) value
#define _fd876720_threadsCountZ(value) value
#define _fd876720_optionalFile(value) value
#define _fd876720_optionalLine(value) value
#define _fd876720_optionalUserData(value) value
#define _fd876720_rteParameters(value) value
#else
typedef struct _s_fd876720_calls { RedHandleCalls value; } _s_fd876720_calls;
typedef struct _s_fd876720_rteContext { RedRteHandleContext value; } _s_fd876720_rteContext;
typedef struct _s_fd876720_shaderBindingTableRayGeneration { RedRteGpuAddressStrideAndRange* value; } _s_fd876720_shaderBindingTableRayGeneration;
typedef struct _s_fd876720_shaderBindingTableMiss { RedRteGpuAddressStrideAndRange* value; } _s_fd876720_shaderBindingTableMiss;
typedef struct _s_fd876720_shaderBindingTableHit { RedRteGpuAddressStrideAndRange* value; } _s_fd876720_shaderBindingTableHit;
typedef struct _s_fd876720_shaderBindingTableCallable { RedRteGpuAddressStrideAndRange* value; } _s_fd876720_shaderBindingTableCallable;
typedef struct _s_fd876720_threadsCountX { unsigned value; } _s_fd876720_threadsCountX;
typedef struct _s_fd876720_threadsCountY { unsigned value; } _s_fd876720_threadsCountY;
typedef struct _s_fd876720_threadsCountZ { unsigned value; } _s_fd876720_threadsCountZ;
typedef struct _s_fd876720_optionalFile { char* value; } _s_fd876720_optionalFile;
typedef struct _s_fd876720_optionalLine { int value; } _s_fd876720_optionalLine;
typedef struct _s_fd876720_optionalUserData { void* value; } _s_fd876720_optionalUserData;
typedef struct _s_fd876720_rteParameters { void* value; } _s_fd876720_rteParameters;
static inline _s_fd876720_calls _fd876720_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_calls){value}; }
static inline _s_fd876720_rteContext _fd876720_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_rteContext){value}; }
static inline _s_fd876720_shaderBindingTableRayGeneration _fd876720_shaderBindingTableRayGeneration(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_shaderBindingTableRayGeneration){value}; }
static inline _s_fd876720_shaderBindingTableMiss _fd876720_shaderBindingTableMiss(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_shaderBindingTableMiss){value}; }
static inline _s_fd876720_shaderBindingTableHit _fd876720_shaderBindingTableHit(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_shaderBindingTableHit){value}; }
static inline _s_fd876720_shaderBindingTableCallable _fd876720_shaderBindingTableCallable(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_shaderBindingTableCallable){value}; }
static inline _s_fd876720_threadsCountX _fd876720_threadsCountX(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_threadsCountX){value}; }
static inline _s_fd876720_threadsCountY _fd876720_threadsCountY(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_threadsCountY){value}; }
static inline _s_fd876720_threadsCountZ _fd876720_threadsCountZ(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_threadsCountZ){value}; }
static inline _s_fd876720_optionalFile _fd876720_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_optionalFile){value}; }
static inline _s_fd876720_optionalLine _fd876720_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_optionalLine){value}; }
static inline _s_fd876720_optionalUserData _fd876720_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_optionalUserData){value}; }
static inline _s_fd876720_rteParameters _fd876720_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fd876720_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallProcedureRayTracing(_s_fd876720_calls calls, _s_fd876720_rteContext rteContext, _s_fd876720_shaderBindingTableRayGeneration shaderBindingTableRayGeneration, _s_fd876720_shaderBindingTableMiss shaderBindingTableMiss, _s_fd876720_shaderBindingTableHit shaderBindingTableHit, _s_fd876720_shaderBindingTableCallable shaderBindingTableCallable, _s_fd876720_threadsCountX threadsCountX, _s_fd876720_threadsCountY threadsCountY, _s_fd876720_threadsCountZ threadsCountZ, _s_fd876720_optionalFile optionalFile, _s_fd876720_optionalLine optionalLine, _s_fd876720_optionalUserData optionalUserData, _s_fd876720_rteParameters rteParameters) {
  return redRteCallProcedureRayTracing(calls.value, rteContext.value, shaderBindingTableRayGeneration.value, shaderBindingTableMiss.value, shaderBindingTableHit.value, shaderBindingTableCallable.value, threadsCountX.value, threadsCountY.value, threadsCountZ.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallProcedureIndirect redRteCallProcedureIndirect
#define _82708c13_calls(value) value
#define _82708c13_rteContext(value) value
#define _82708c13_array(value) value
#define _82708c13_arrayBytesFirst(value) value
#define _82708c13_count(value) value
#define _82708c13_bytesStride(value) value
#define _82708c13_optionalFile(value) value
#define _82708c13_optionalLine(value) value
#define _82708c13_optionalUserData(value) value
#define _82708c13_rteParameters(value) value
#else
typedef struct _s_82708c13_calls { RedHandleCalls value; } _s_82708c13_calls;
typedef struct _s_82708c13_rteContext { RedRteHandleContext value; } _s_82708c13_rteContext;
typedef struct _s_82708c13_array { RedHandleArray value; } _s_82708c13_array;
typedef struct _s_82708c13_arrayBytesFirst { uint64_t value; } _s_82708c13_arrayBytesFirst;
typedef struct _s_82708c13_count { unsigned value; } _s_82708c13_count;
typedef struct _s_82708c13_bytesStride { unsigned value; } _s_82708c13_bytesStride;
typedef struct _s_82708c13_optionalFile { char* value; } _s_82708c13_optionalFile;
typedef struct _s_82708c13_optionalLine { int value; } _s_82708c13_optionalLine;
typedef struct _s_82708c13_optionalUserData { void* value; } _s_82708c13_optionalUserData;
typedef struct _s_82708c13_rteParameters { void* value; } _s_82708c13_rteParameters;
static inline _s_82708c13_calls _82708c13_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_82708c13_calls){value}; }
static inline _s_82708c13_rteContext _82708c13_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_82708c13_rteContext){value}; }
static inline _s_82708c13_array _82708c13_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_82708c13_array){value}; }
static inline _s_82708c13_arrayBytesFirst _82708c13_arrayBytesFirst(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_82708c13_arrayBytesFirst){value}; }
static inline _s_82708c13_count _82708c13_count(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_82708c13_count){value}; }
static inline _s_82708c13_bytesStride _82708c13_bytesStride(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_82708c13_bytesStride){value}; }
static inline _s_82708c13_optionalFile _82708c13_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_82708c13_optionalFile){value}; }
static inline _s_82708c13_optionalLine _82708c13_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_82708c13_optionalLine){value}; }
static inline _s_82708c13_optionalUserData _82708c13_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_82708c13_optionalUserData){value}; }
static inline _s_82708c13_rteParameters _82708c13_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_82708c13_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallProcedureIndirect(_s_82708c13_calls calls, _s_82708c13_rteContext rteContext, _s_82708c13_array array, _s_82708c13_arrayBytesFirst arrayBytesFirst, _s_82708c13_count count, _s_82708c13_bytesStride bytesStride, _s_82708c13_optionalFile optionalFile, _s_82708c13_optionalLine optionalLine, _s_82708c13_optionalUserData optionalUserData, _s_82708c13_rteParameters rteParameters) {
  return redRteCallProcedureIndirect(calls.value, rteContext.value, array.value, arrayBytesFirst.value, count.value, bytesStride.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallProcedureIndexedIndirect redRteCallProcedureIndexedIndirect
#define _daf042b6_calls(value) value
#define _daf042b6_rteContext(value) value
#define _daf042b6_array(value) value
#define _daf042b6_arrayBytesFirst(value) value
#define _daf042b6_count(value) value
#define _daf042b6_bytesStride(value) value
#define _daf042b6_optionalFile(value) value
#define _daf042b6_optionalLine(value) value
#define _daf042b6_optionalUserData(value) value
#define _daf042b6_rteParameters(value) value
#else
typedef struct _s_daf042b6_calls { RedHandleCalls value; } _s_daf042b6_calls;
typedef struct _s_daf042b6_rteContext { RedRteHandleContext value; } _s_daf042b6_rteContext;
typedef struct _s_daf042b6_array { RedHandleArray value; } _s_daf042b6_array;
typedef struct _s_daf042b6_arrayBytesFirst { uint64_t value; } _s_daf042b6_arrayBytesFirst;
typedef struct _s_daf042b6_count { unsigned value; } _s_daf042b6_count;
typedef struct _s_daf042b6_bytesStride { unsigned value; } _s_daf042b6_bytesStride;
typedef struct _s_daf042b6_optionalFile { char* value; } _s_daf042b6_optionalFile;
typedef struct _s_daf042b6_optionalLine { int value; } _s_daf042b6_optionalLine;
typedef struct _s_daf042b6_optionalUserData { void* value; } _s_daf042b6_optionalUserData;
typedef struct _s_daf042b6_rteParameters { void* value; } _s_daf042b6_rteParameters;
static inline _s_daf042b6_calls _daf042b6_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_daf042b6_calls){value}; }
static inline _s_daf042b6_rteContext _daf042b6_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_daf042b6_rteContext){value}; }
static inline _s_daf042b6_array _daf042b6_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_daf042b6_array){value}; }
static inline _s_daf042b6_arrayBytesFirst _daf042b6_arrayBytesFirst(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_daf042b6_arrayBytesFirst){value}; }
static inline _s_daf042b6_count _daf042b6_count(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_daf042b6_count){value}; }
static inline _s_daf042b6_bytesStride _daf042b6_bytesStride(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_daf042b6_bytesStride){value}; }
static inline _s_daf042b6_optionalFile _daf042b6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_daf042b6_optionalFile){value}; }
static inline _s_daf042b6_optionalLine _daf042b6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_daf042b6_optionalLine){value}; }
static inline _s_daf042b6_optionalUserData _daf042b6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_daf042b6_optionalUserData){value}; }
static inline _s_daf042b6_rteParameters _daf042b6_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_daf042b6_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallProcedureIndexedIndirect(_s_daf042b6_calls calls, _s_daf042b6_rteContext rteContext, _s_daf042b6_array array, _s_daf042b6_arrayBytesFirst arrayBytesFirst, _s_daf042b6_count count, _s_daf042b6_bytesStride bytesStride, _s_daf042b6_optionalFile optionalFile, _s_daf042b6_optionalLine optionalLine, _s_daf042b6_optionalUserData optionalUserData, _s_daf042b6_rteParameters rteParameters) {
  return redRteCallProcedureIndexedIndirect(calls.value, rteContext.value, array.value, arrayBytesFirst.value, count.value, bytesStride.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallProcedureComputeIndirect redRteCallProcedureComputeIndirect
#define _14acd38c_calls(value) value
#define _14acd38c_rteContext(value) value
#define _14acd38c_array(value) value
#define _14acd38c_arrayBytesFirst(value) value
#define _14acd38c_optionalFile(value) value
#define _14acd38c_optionalLine(value) value
#define _14acd38c_optionalUserData(value) value
#define _14acd38c_rteParameters(value) value
#else
typedef struct _s_14acd38c_calls { RedHandleCalls value; } _s_14acd38c_calls;
typedef struct _s_14acd38c_rteContext { RedRteHandleContext value; } _s_14acd38c_rteContext;
typedef struct _s_14acd38c_array { RedHandleArray value; } _s_14acd38c_array;
typedef struct _s_14acd38c_arrayBytesFirst { uint64_t value; } _s_14acd38c_arrayBytesFirst;
typedef struct _s_14acd38c_optionalFile { char* value; } _s_14acd38c_optionalFile;
typedef struct _s_14acd38c_optionalLine { int value; } _s_14acd38c_optionalLine;
typedef struct _s_14acd38c_optionalUserData { void* value; } _s_14acd38c_optionalUserData;
typedef struct _s_14acd38c_rteParameters { void* value; } _s_14acd38c_rteParameters;
static inline _s_14acd38c_calls _14acd38c_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_14acd38c_calls){value}; }
static inline _s_14acd38c_rteContext _14acd38c_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_14acd38c_rteContext){value}; }
static inline _s_14acd38c_array _14acd38c_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_14acd38c_array){value}; }
static inline _s_14acd38c_arrayBytesFirst _14acd38c_arrayBytesFirst(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_14acd38c_arrayBytesFirst){value}; }
static inline _s_14acd38c_optionalFile _14acd38c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_14acd38c_optionalFile){value}; }
static inline _s_14acd38c_optionalLine _14acd38c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_14acd38c_optionalLine){value}; }
static inline _s_14acd38c_optionalUserData _14acd38c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_14acd38c_optionalUserData){value}; }
static inline _s_14acd38c_rteParameters _14acd38c_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_14acd38c_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallProcedureComputeIndirect(_s_14acd38c_calls calls, _s_14acd38c_rteContext rteContext, _s_14acd38c_array array, _s_14acd38c_arrayBytesFirst arrayBytesFirst, _s_14acd38c_optionalFile optionalFile, _s_14acd38c_optionalLine optionalLine, _s_14acd38c_optionalUserData optionalUserData, _s_14acd38c_rteParameters rteParameters) {
  return redRteCallProcedureComputeIndirect(calls.value, rteContext.value, array.value, arrayBytesFirst.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallProcedureRayTracingIndirect redRteCallProcedureRayTracingIndirect
#define _0036756f_calls(value) value
#define _0036756f_rteContext(value) value
#define _0036756f_shaderBindingTableRayGeneration(value) value
#define _0036756f_shaderBindingTableMiss(value) value
#define _0036756f_shaderBindingTableHit(value) value
#define _0036756f_shaderBindingTableCallable(value) value
#define _0036756f_gpuAddress(value) value
#define _0036756f_optionalFile(value) value
#define _0036756f_optionalLine(value) value
#define _0036756f_optionalUserData(value) value
#define _0036756f_rteParameters(value) value
#else
typedef struct _s_0036756f_calls { RedHandleCalls value; } _s_0036756f_calls;
typedef struct _s_0036756f_rteContext { RedRteHandleContext value; } _s_0036756f_rteContext;
typedef struct _s_0036756f_shaderBindingTableRayGeneration { RedRteGpuAddressStrideAndRange* value; } _s_0036756f_shaderBindingTableRayGeneration;
typedef struct _s_0036756f_shaderBindingTableMiss { RedRteGpuAddressStrideAndRange* value; } _s_0036756f_shaderBindingTableMiss;
typedef struct _s_0036756f_shaderBindingTableHit { RedRteGpuAddressStrideAndRange* value; } _s_0036756f_shaderBindingTableHit;
typedef struct _s_0036756f_shaderBindingTableCallable { RedRteGpuAddressStrideAndRange* value; } _s_0036756f_shaderBindingTableCallable;
typedef struct _s_0036756f_gpuAddress { uint64_t value; } _s_0036756f_gpuAddress;
typedef struct _s_0036756f_optionalFile { char* value; } _s_0036756f_optionalFile;
typedef struct _s_0036756f_optionalLine { int value; } _s_0036756f_optionalLine;
typedef struct _s_0036756f_optionalUserData { void* value; } _s_0036756f_optionalUserData;
typedef struct _s_0036756f_rteParameters { void* value; } _s_0036756f_rteParameters;
static inline _s_0036756f_calls _0036756f_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_0036756f_calls){value}; }
static inline _s_0036756f_rteContext _0036756f_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_0036756f_rteContext){value}; }
static inline _s_0036756f_shaderBindingTableRayGeneration _0036756f_shaderBindingTableRayGeneration(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_0036756f_shaderBindingTableRayGeneration){value}; }
static inline _s_0036756f_shaderBindingTableMiss _0036756f_shaderBindingTableMiss(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_0036756f_shaderBindingTableMiss){value}; }
static inline _s_0036756f_shaderBindingTableHit _0036756f_shaderBindingTableHit(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_0036756f_shaderBindingTableHit){value}; }
static inline _s_0036756f_shaderBindingTableCallable _0036756f_shaderBindingTableCallable(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_0036756f_shaderBindingTableCallable){value}; }
static inline _s_0036756f_gpuAddress _0036756f_gpuAddress(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_0036756f_gpuAddress){value}; }
static inline _s_0036756f_optionalFile _0036756f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0036756f_optionalFile){value}; }
static inline _s_0036756f_optionalLine _0036756f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0036756f_optionalLine){value}; }
static inline _s_0036756f_optionalUserData _0036756f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0036756f_optionalUserData){value}; }
static inline _s_0036756f_rteParameters _0036756f_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0036756f_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallProcedureRayTracingIndirect(_s_0036756f_calls calls, _s_0036756f_rteContext rteContext, _s_0036756f_shaderBindingTableRayGeneration shaderBindingTableRayGeneration, _s_0036756f_shaderBindingTableMiss shaderBindingTableMiss, _s_0036756f_shaderBindingTableHit shaderBindingTableHit, _s_0036756f_shaderBindingTableCallable shaderBindingTableCallable, _s_0036756f_gpuAddress gpuAddress, _s_0036756f_optionalFile optionalFile, _s_0036756f_optionalLine optionalLine, _s_0036756f_optionalUserData optionalUserData, _s_0036756f_rteParameters rteParameters) {
  return redRteCallProcedureRayTracingIndirect(calls.value, rteContext.value, shaderBindingTableRayGeneration.value, shaderBindingTableMiss.value, shaderBindingTableHit.value, shaderBindingTableCallable.value, gpuAddress.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallSetProcedureRayTracingStackBytesCount redRteCallSetProcedureRayTracingStackBytesCount
#define _8ef0a147_calls(value) value
#define _8ef0a147_rteContext(value) value
#define _8ef0a147_stackBytesCount(value) value
#define _8ef0a147_optionalFile(value) value
#define _8ef0a147_optionalLine(value) value
#define _8ef0a147_optionalUserData(value) value
#define _8ef0a147_rteParameters(value) value
#else
typedef struct _s_8ef0a147_calls { RedHandleCalls value; } _s_8ef0a147_calls;
typedef struct _s_8ef0a147_rteContext { RedRteHandleContext value; } _s_8ef0a147_rteContext;
typedef struct _s_8ef0a147_stackBytesCount { unsigned value; } _s_8ef0a147_stackBytesCount;
typedef struct _s_8ef0a147_optionalFile { char* value; } _s_8ef0a147_optionalFile;
typedef struct _s_8ef0a147_optionalLine { int value; } _s_8ef0a147_optionalLine;
typedef struct _s_8ef0a147_optionalUserData { void* value; } _s_8ef0a147_optionalUserData;
typedef struct _s_8ef0a147_rteParameters { void* value; } _s_8ef0a147_rteParameters;
static inline _s_8ef0a147_calls _8ef0a147_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_8ef0a147_calls){value}; }
static inline _s_8ef0a147_rteContext _8ef0a147_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_8ef0a147_rteContext){value}; }
static inline _s_8ef0a147_stackBytesCount _8ef0a147_stackBytesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8ef0a147_stackBytesCount){value}; }
static inline _s_8ef0a147_optionalFile _8ef0a147_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8ef0a147_optionalFile){value}; }
static inline _s_8ef0a147_optionalLine _8ef0a147_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8ef0a147_optionalLine){value}; }
static inline _s_8ef0a147_optionalUserData _8ef0a147_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8ef0a147_optionalUserData){value}; }
static inline _s_8ef0a147_rteParameters _8ef0a147_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8ef0a147_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallSetProcedureRayTracingStackBytesCount(_s_8ef0a147_calls calls, _s_8ef0a147_rteContext rteContext, _s_8ef0a147_stackBytesCount stackBytesCount, _s_8ef0a147_optionalFile optionalFile, _s_8ef0a147_optionalLine optionalLine, _s_8ef0a147_optionalUserData optionalUserData, _s_8ef0a147_rteParameters rteParameters) {
  return redRteCallSetProcedureRayTracingStackBytesCount(calls.value, rteContext.value, stackBytesCount.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateHelperShaderBindingTable redRteCreateHelperShaderBindingTable
#define _b37f5357_rteContext(value) value
#define _b37f5357_rteHandleHelperAllocator(value) value
#define _b37f5357_queueFamilyIndex(value) value
#define _b37f5357_outHelperShaderBindingTable(value) value
#define _b37f5357_outStatuses(value) value
#define _b37f5357_optionalFile(value) value
#define _b37f5357_optionalLine(value) value
#define _b37f5357_optionalUserData(value) value
#define _b37f5357_rteParameters(value) value
#else
typedef struct _s_b37f5357_rteContext { RedRteHandleContext value; } _s_b37f5357_rteContext;
typedef struct _s_b37f5357_rteHandleHelperAllocator { void* value; } _s_b37f5357_rteHandleHelperAllocator;
typedef struct _s_b37f5357_queueFamilyIndex { unsigned value; } _s_b37f5357_queueFamilyIndex;
typedef struct _s_b37f5357_outHelperShaderBindingTable { RedRteHandleHelperShaderBindingTable* value; } _s_b37f5357_outHelperShaderBindingTable;
typedef struct _s_b37f5357_outStatuses { RedStatuses* value; } _s_b37f5357_outStatuses;
typedef struct _s_b37f5357_optionalFile { char* value; } _s_b37f5357_optionalFile;
typedef struct _s_b37f5357_optionalLine { int value; } _s_b37f5357_optionalLine;
typedef struct _s_b37f5357_optionalUserData { void* value; } _s_b37f5357_optionalUserData;
typedef struct _s_b37f5357_rteParameters { void* value; } _s_b37f5357_rteParameters;
static inline _s_b37f5357_rteContext _b37f5357_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_b37f5357_rteContext){value}; }
static inline _s_b37f5357_rteHandleHelperAllocator _b37f5357_rteHandleHelperAllocator(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b37f5357_rteHandleHelperAllocator){value}; }
static inline _s_b37f5357_queueFamilyIndex _b37f5357_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b37f5357_queueFamilyIndex){value}; }
static inline _s_b37f5357_outHelperShaderBindingTable _b37f5357_outHelperShaderBindingTable(RedRteHandleHelperShaderBindingTable* value) { return REDGPU_NP_STRUCT_INIT(_s_b37f5357_outHelperShaderBindingTable){value}; }
static inline _s_b37f5357_outStatuses _b37f5357_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b37f5357_outStatuses){value}; }
static inline _s_b37f5357_optionalFile _b37f5357_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b37f5357_optionalFile){value}; }
static inline _s_b37f5357_optionalLine _b37f5357_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b37f5357_optionalLine){value}; }
static inline _s_b37f5357_optionalUserData _b37f5357_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b37f5357_optionalUserData){value}; }
static inline _s_b37f5357_rteParameters _b37f5357_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b37f5357_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateHelperShaderBindingTable(_s_b37f5357_rteContext rteContext, _s_b37f5357_rteHandleHelperAllocator rteHandleHelperAllocator, _s_b37f5357_queueFamilyIndex queueFamilyIndex, _s_b37f5357_outHelperShaderBindingTable outHelperShaderBindingTable, _s_b37f5357_outStatuses outStatuses, _s_b37f5357_optionalFile optionalFile, _s_b37f5357_optionalLine optionalLine, _s_b37f5357_optionalUserData optionalUserData, _s_b37f5357_rteParameters rteParameters) {
  return redRteCreateHelperShaderBindingTable(rteContext.value, rteHandleHelperAllocator.value, queueFamilyIndex.value, outHelperShaderBindingTable.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyHelperShaderBindingTable redRteDestroyHelperShaderBindingTable
#define _7f342c03_helperShaderBindingTable(value) value
#define _7f342c03_optionalFile(value) value
#define _7f342c03_optionalLine(value) value
#define _7f342c03_optionalUserData(value) value
#define _7f342c03_rteParameters(value) value
#else
typedef struct _s_7f342c03_helperShaderBindingTable { RedRteHandleHelperShaderBindingTable value; } _s_7f342c03_helperShaderBindingTable;
typedef struct _s_7f342c03_optionalFile { char* value; } _s_7f342c03_optionalFile;
typedef struct _s_7f342c03_optionalLine { int value; } _s_7f342c03_optionalLine;
typedef struct _s_7f342c03_optionalUserData { void* value; } _s_7f342c03_optionalUserData;
typedef struct _s_7f342c03_rteParameters { void* value; } _s_7f342c03_rteParameters;
static inline _s_7f342c03_helperShaderBindingTable _7f342c03_helperShaderBindingTable(RedRteHandleHelperShaderBindingTable value) { return REDGPU_NP_STRUCT_INIT(_s_7f342c03_helperShaderBindingTable){value}; }
static inline _s_7f342c03_optionalFile _7f342c03_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7f342c03_optionalFile){value}; }
static inline _s_7f342c03_optionalLine _7f342c03_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7f342c03_optionalLine){value}; }
static inline _s_7f342c03_optionalUserData _7f342c03_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7f342c03_optionalUserData){value}; }
static inline _s_7f342c03_rteParameters _7f342c03_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7f342c03_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyHelperShaderBindingTable(_s_7f342c03_helperShaderBindingTable helperShaderBindingTable, _s_7f342c03_optionalFile optionalFile, _s_7f342c03_optionalLine optionalLine, _s_7f342c03_optionalUserData optionalUserData, _s_7f342c03_rteParameters rteParameters) {
  return redRteDestroyHelperShaderBindingTable(helperShaderBindingTable.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperShaderBindingTableCreate redRteHelperShaderBindingTableCreate
#define _c3949031_helperShaderBindingTable(value) value
#define _c3949031_procedureRayTracing(value) value
#define _c3949031_procedureRayTracingState(value) value
#define _c3949031_optionalFile(value) value
#define _c3949031_optionalLine(value) value
#define _c3949031_optionalUserData(value) value
#define _c3949031_rteParameters(value) value
#else
typedef struct _s_c3949031_helperShaderBindingTable { RedRteHandleHelperShaderBindingTable value; } _s_c3949031_helperShaderBindingTable;
typedef struct _s_c3949031_procedureRayTracing { RedHandleProcedure value; } _s_c3949031_procedureRayTracing;
typedef struct _s_c3949031_procedureRayTracingState { RedRteProcedureRayTracingState* value; } _s_c3949031_procedureRayTracingState;
typedef struct _s_c3949031_optionalFile { char* value; } _s_c3949031_optionalFile;
typedef struct _s_c3949031_optionalLine { int value; } _s_c3949031_optionalLine;
typedef struct _s_c3949031_optionalUserData { void* value; } _s_c3949031_optionalUserData;
typedef struct _s_c3949031_rteParameters { void* value; } _s_c3949031_rteParameters;
static inline _s_c3949031_helperShaderBindingTable _c3949031_helperShaderBindingTable(RedRteHandleHelperShaderBindingTable value) { return REDGPU_NP_STRUCT_INIT(_s_c3949031_helperShaderBindingTable){value}; }
static inline _s_c3949031_procedureRayTracing _c3949031_procedureRayTracing(RedHandleProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_c3949031_procedureRayTracing){value}; }
static inline _s_c3949031_procedureRayTracingState _c3949031_procedureRayTracingState(RedRteProcedureRayTracingState* value) { return REDGPU_NP_STRUCT_INIT(_s_c3949031_procedureRayTracingState){value}; }
static inline _s_c3949031_optionalFile _c3949031_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c3949031_optionalFile){value}; }
static inline _s_c3949031_optionalLine _c3949031_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c3949031_optionalLine){value}; }
static inline _s_c3949031_optionalUserData _c3949031_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c3949031_optionalUserData){value}; }
static inline _s_c3949031_rteParameters _c3949031_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c3949031_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperShaderBindingTableCreate(_s_c3949031_helperShaderBindingTable helperShaderBindingTable, _s_c3949031_procedureRayTracing procedureRayTracing, _s_c3949031_procedureRayTracingState procedureRayTracingState, _s_c3949031_optionalFile optionalFile, _s_c3949031_optionalLine optionalLine, _s_c3949031_optionalUserData optionalUserData, _s_c3949031_rteParameters rteParameters) {
  return redRteHelperShaderBindingTableCreate(helperShaderBindingTable.value, procedureRayTracing.value, procedureRayTracingState.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperShaderBindingTableGetGpuAddressStrideAndRange redRteHelperShaderBindingTableGetGpuAddressStrideAndRange
#define _e318450f_helperShaderBindingTable(value) value
#define _e318450f_outShaderBindingTableRayGeneration(value) value
#define _e318450f_outShaderBindingTableMiss(value) value
#define _e318450f_outShaderBindingTableHit(value) value
#define _e318450f_outShaderBindingTableCallable(value) value
#define _e318450f_optionalFile(value) value
#define _e318450f_optionalLine(value) value
#define _e318450f_optionalUserData(value) value
#define _e318450f_rteParameters(value) value
#else
typedef struct _s_e318450f_helperShaderBindingTable { RedRteHandleHelperShaderBindingTable value; } _s_e318450f_helperShaderBindingTable;
typedef struct _s_e318450f_outShaderBindingTableRayGeneration { RedRteGpuAddressStrideAndRange* value; } _s_e318450f_outShaderBindingTableRayGeneration;
typedef struct _s_e318450f_outShaderBindingTableMiss { RedRteGpuAddressStrideAndRange* value; } _s_e318450f_outShaderBindingTableMiss;
typedef struct _s_e318450f_outShaderBindingTableHit { RedRteGpuAddressStrideAndRange* value; } _s_e318450f_outShaderBindingTableHit;
typedef struct _s_e318450f_outShaderBindingTableCallable { RedRteGpuAddressStrideAndRange* value; } _s_e318450f_outShaderBindingTableCallable;
typedef struct _s_e318450f_optionalFile { char* value; } _s_e318450f_optionalFile;
typedef struct _s_e318450f_optionalLine { int value; } _s_e318450f_optionalLine;
typedef struct _s_e318450f_optionalUserData { void* value; } _s_e318450f_optionalUserData;
typedef struct _s_e318450f_rteParameters { void* value; } _s_e318450f_rteParameters;
static inline _s_e318450f_helperShaderBindingTable _e318450f_helperShaderBindingTable(RedRteHandleHelperShaderBindingTable value) { return REDGPU_NP_STRUCT_INIT(_s_e318450f_helperShaderBindingTable){value}; }
static inline _s_e318450f_outShaderBindingTableRayGeneration _e318450f_outShaderBindingTableRayGeneration(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_e318450f_outShaderBindingTableRayGeneration){value}; }
static inline _s_e318450f_outShaderBindingTableMiss _e318450f_outShaderBindingTableMiss(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_e318450f_outShaderBindingTableMiss){value}; }
static inline _s_e318450f_outShaderBindingTableHit _e318450f_outShaderBindingTableHit(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_e318450f_outShaderBindingTableHit){value}; }
static inline _s_e318450f_outShaderBindingTableCallable _e318450f_outShaderBindingTableCallable(RedRteGpuAddressStrideAndRange* value) { return REDGPU_NP_STRUCT_INIT(_s_e318450f_outShaderBindingTableCallable){value}; }
static inline _s_e318450f_optionalFile _e318450f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e318450f_optionalFile){value}; }
static inline _s_e318450f_optionalLine _e318450f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e318450f_optionalLine){value}; }
static inline _s_e318450f_optionalUserData _e318450f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e318450f_optionalUserData){value}; }
static inline _s_e318450f_rteParameters _e318450f_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e318450f_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperShaderBindingTableGetGpuAddressStrideAndRange(_s_e318450f_helperShaderBindingTable helperShaderBindingTable, _s_e318450f_outShaderBindingTableRayGeneration outShaderBindingTableRayGeneration, _s_e318450f_outShaderBindingTableMiss outShaderBindingTableMiss, _s_e318450f_outShaderBindingTableHit outShaderBindingTableHit, _s_e318450f_outShaderBindingTableCallable outShaderBindingTableCallable, _s_e318450f_optionalFile optionalFile, _s_e318450f_optionalLine optionalLine, _s_e318450f_optionalUserData optionalUserData, _s_e318450f_rteParameters rteParameters) {
  return redRteHelperShaderBindingTableGetGpuAddressStrideAndRange(helperShaderBindingTable.value, outShaderBindingTableRayGeneration.value, outShaderBindingTableMiss.value, outShaderBindingTableHit.value, outShaderBindingTableCallable.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteGetInstanceProcAddr redRteGetInstanceProcAddr
#define _87fea452_optionalFile(value) value
#define _87fea452_optionalLine(value) value
#define _87fea452_optionalUserData(value) value
#define _87fea452_rteParameters(value) value
#else
typedef struct _s_87fea452_optionalFile { char* value; } _s_87fea452_optionalFile;
typedef struct _s_87fea452_optionalLine { int value; } _s_87fea452_optionalLine;
typedef struct _s_87fea452_optionalUserData { void* value; } _s_87fea452_optionalUserData;
typedef struct _s_87fea452_rteParameters { void* value; } _s_87fea452_rteParameters;
static inline _s_87fea452_optionalFile _87fea452_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_87fea452_optionalFile){value}; }
static inline _s_87fea452_optionalLine _87fea452_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_87fea452_optionalLine){value}; }
static inline _s_87fea452_optionalUserData _87fea452_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_87fea452_optionalUserData){value}; }
static inline _s_87fea452_rteParameters _87fea452_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_87fea452_rteParameters){value}; }
REDGPU_NP_DECLSPEC void* REDGPU_NP_API np_redRteGetInstanceProcAddr(_s_87fea452_optionalFile optionalFile, _s_87fea452_optionalLine optionalLine, _s_87fea452_optionalUserData optionalUserData, _s_87fea452_rteParameters rteParameters) {
  return redRteGetInstanceProcAddr(optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateContextFromRteContext redRteCreateContextFromRteContext
#define _48664791_rteContext(value) value
#define _48664791_malloc(value) value
#define _48664791_free(value) value
#define _48664791_optionalMallocTagged(value) value
#define _48664791_optionalFreeTagged(value) value
#define _48664791_debugCallback(value) value
#define _48664791_sdkVersion(value) value
#define _48664791_sdkExtensionsCount(value) value
#define _48664791_sdkExtensions(value) value
#define _48664791_optionalProgramName(value) value
#define _48664791_optionalProgramVersion(value) value
#define _48664791_optionalEngineName(value) value
#define _48664791_optionalEngineVersion(value) value
#define _48664791_optionalSettings(value) value
#define _48664791_outContext(value) value
#define _48664791_outStatuses(value) value
#define _48664791_optionalFile(value) value
#define _48664791_optionalLine(value) value
#define _48664791_optionalUserData(value) value
#define _48664791_rteParameters(value) value
#else
typedef struct _s_48664791_rteContext { RedRteHandleContext value; } _s_48664791_rteContext;
typedef struct _s_48664791_malloc { RedTypeProcedureMalloc value; } _s_48664791_malloc;
typedef struct _s_48664791_free { RedTypeProcedureFree value; } _s_48664791_free;
typedef struct _s_48664791_optionalMallocTagged { RedTypeProcedureMallocTagged value; } _s_48664791_optionalMallocTagged;
typedef struct _s_48664791_optionalFreeTagged { RedTypeProcedureFreeTagged value; } _s_48664791_optionalFreeTagged;
typedef struct _s_48664791_debugCallback { RedTypeProcedureDebugCallback value; } _s_48664791_debugCallback;
typedef struct _s_48664791_sdkVersion { RedSdkVersion value; } _s_48664791_sdkVersion;
typedef struct _s_48664791_sdkExtensionsCount { unsigned value; } _s_48664791_sdkExtensionsCount;
typedef struct _s_48664791_sdkExtensions { unsigned* value; } _s_48664791_sdkExtensions;
typedef struct _s_48664791_optionalProgramName { char* value; } _s_48664791_optionalProgramName;
typedef struct _s_48664791_optionalProgramVersion { unsigned value; } _s_48664791_optionalProgramVersion;
typedef struct _s_48664791_optionalEngineName { char* value; } _s_48664791_optionalEngineName;
typedef struct _s_48664791_optionalEngineVersion { unsigned value; } _s_48664791_optionalEngineVersion;
typedef struct _s_48664791_optionalSettings { void* value; } _s_48664791_optionalSettings;
typedef struct _s_48664791_outContext { RedContext* value; } _s_48664791_outContext;
typedef struct _s_48664791_outStatuses { RedStatuses* value; } _s_48664791_outStatuses;
typedef struct _s_48664791_optionalFile { char* value; } _s_48664791_optionalFile;
typedef struct _s_48664791_optionalLine { int value; } _s_48664791_optionalLine;
typedef struct _s_48664791_optionalUserData { void* value; } _s_48664791_optionalUserData;
typedef struct _s_48664791_rteParameters { void* value; } _s_48664791_rteParameters;
static inline _s_48664791_rteContext _48664791_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_rteContext){value}; }
static inline _s_48664791_malloc _48664791_malloc(RedTypeProcedureMalloc value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_malloc){value}; }
static inline _s_48664791_free _48664791_free(RedTypeProcedureFree value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_free){value}; }
static inline _s_48664791_optionalMallocTagged _48664791_optionalMallocTagged(RedTypeProcedureMallocTagged value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_optionalMallocTagged){value}; }
static inline _s_48664791_optionalFreeTagged _48664791_optionalFreeTagged(RedTypeProcedureFreeTagged value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_optionalFreeTagged){value}; }
static inline _s_48664791_debugCallback _48664791_debugCallback(RedTypeProcedureDebugCallback value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_debugCallback){value}; }
static inline _s_48664791_sdkVersion _48664791_sdkVersion(RedSdkVersion value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_sdkVersion){value}; }
static inline _s_48664791_sdkExtensionsCount _48664791_sdkExtensionsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_sdkExtensionsCount){value}; }
static inline _s_48664791_sdkExtensions _48664791_sdkExtensions(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_sdkExtensions){value}; }
static inline _s_48664791_optionalProgramName _48664791_optionalProgramName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_optionalProgramName){value}; }
static inline _s_48664791_optionalProgramVersion _48664791_optionalProgramVersion(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_optionalProgramVersion){value}; }
static inline _s_48664791_optionalEngineName _48664791_optionalEngineName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_optionalEngineName){value}; }
static inline _s_48664791_optionalEngineVersion _48664791_optionalEngineVersion(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_optionalEngineVersion){value}; }
static inline _s_48664791_optionalSettings _48664791_optionalSettings(void* value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_optionalSettings){value}; }
static inline _s_48664791_outContext _48664791_outContext(RedContext* value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_outContext){value}; }
static inline _s_48664791_outStatuses _48664791_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_outStatuses){value}; }
static inline _s_48664791_optionalFile _48664791_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_optionalFile){value}; }
static inline _s_48664791_optionalLine _48664791_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_optionalLine){value}; }
static inline _s_48664791_optionalUserData _48664791_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_optionalUserData){value}; }
static inline _s_48664791_rteParameters _48664791_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_48664791_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateContextFromRteContext(_s_48664791_rteContext rteContext, _s_48664791_malloc malloc, _s_48664791_free free, _s_48664791_optionalMallocTagged optionalMallocTagged, _s_48664791_optionalFreeTagged optionalFreeTagged, _s_48664791_debugCallback debugCallback, _s_48664791_sdkVersion sdkVersion, _s_48664791_sdkExtensionsCount sdkExtensionsCount, _s_48664791_sdkExtensions sdkExtensions, _s_48664791_optionalProgramName optionalProgramName, _s_48664791_optionalProgramVersion optionalProgramVersion, _s_48664791_optionalEngineName optionalEngineName, _s_48664791_optionalEngineVersion optionalEngineVersion, _s_48664791_optionalSettings optionalSettings, _s_48664791_outContext outContext, _s_48664791_outStatuses outStatuses, _s_48664791_optionalFile optionalFile, _s_48664791_optionalLine optionalLine, _s_48664791_optionalUserData optionalUserData, _s_48664791_rteParameters rteParameters) {
  return redRteCreateContextFromRteContext(rteContext.value, malloc.value, free.value, optionalMallocTagged.value, optionalFreeTagged.value, debugCallback.value, sdkVersion.value, sdkExtensionsCount.value, sdkExtensions.value, optionalProgramName.value, optionalProgramVersion.value, optionalEngineName.value, optionalEngineVersion.value, optionalSettings.value, outContext.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateHelperAppWindow redRteCreateHelperAppWindow
#define _a3533841_callbacks(value) value
#define _a3533841_initialWindowWidth(value) value
#define _a3533841_initialWindowHeight(value) value
#define _a3533841_initialIsVsyncEnabled(value) value
#define _a3533841_initialViewportClearColorR(value) value
#define _a3533841_initialViewportClearColorG(value) value
#define _a3533841_initialViewportClearColorB(value) value
#define _a3533841_initialViewportClearColorA(value) value
#define _a3533841_optionalProgramName(value) value
#define _a3533841_optionalEngineName(value) value
#define _a3533841_rteCreateContextParameters(value) value
#define _a3533841_outHelperAppWindow(value) value
#define _a3533841_outStatuses(value) value
#define _a3533841_optionalFile(value) value
#define _a3533841_optionalLine(value) value
#define _a3533841_optionalUserData(value) value
#define _a3533841_rteParameters(value) value
#else
typedef struct _s_a3533841_callbacks { RedRteHelperAppCallbacks* value; } _s_a3533841_callbacks;
typedef struct _s_a3533841_initialWindowWidth { int value; } _s_a3533841_initialWindowWidth;
typedef struct _s_a3533841_initialWindowHeight { int value; } _s_a3533841_initialWindowHeight;
typedef struct _s_a3533841_initialIsVsyncEnabled { RedBool32 value; } _s_a3533841_initialIsVsyncEnabled;
typedef struct _s_a3533841_initialViewportClearColorR { float value; } _s_a3533841_initialViewportClearColorR;
typedef struct _s_a3533841_initialViewportClearColorG { float value; } _s_a3533841_initialViewportClearColorG;
typedef struct _s_a3533841_initialViewportClearColorB { float value; } _s_a3533841_initialViewportClearColorB;
typedef struct _s_a3533841_initialViewportClearColorA { float value; } _s_a3533841_initialViewportClearColorA;
typedef struct _s_a3533841_optionalProgramName { char* value; } _s_a3533841_optionalProgramName;
typedef struct _s_a3533841_optionalEngineName { char* value; } _s_a3533841_optionalEngineName;
typedef struct _s_a3533841_rteCreateContextParameters { RedRteCreateContextParameters* value; } _s_a3533841_rteCreateContextParameters;
typedef struct _s_a3533841_outHelperAppWindow { RedRteHandleHelperAppWindow* value; } _s_a3533841_outHelperAppWindow;
typedef struct _s_a3533841_outStatuses { RedStatuses* value; } _s_a3533841_outStatuses;
typedef struct _s_a3533841_optionalFile { char* value; } _s_a3533841_optionalFile;
typedef struct _s_a3533841_optionalLine { int value; } _s_a3533841_optionalLine;
typedef struct _s_a3533841_optionalUserData { void* value; } _s_a3533841_optionalUserData;
typedef struct _s_a3533841_rteParameters { void* value; } _s_a3533841_rteParameters;
static inline _s_a3533841_callbacks _a3533841_callbacks(RedRteHelperAppCallbacks* value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_callbacks){value}; }
static inline _s_a3533841_initialWindowWidth _a3533841_initialWindowWidth(int value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_initialWindowWidth){value}; }
static inline _s_a3533841_initialWindowHeight _a3533841_initialWindowHeight(int value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_initialWindowHeight){value}; }
static inline _s_a3533841_initialIsVsyncEnabled _a3533841_initialIsVsyncEnabled(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_initialIsVsyncEnabled){value}; }
static inline _s_a3533841_initialViewportClearColorR _a3533841_initialViewportClearColorR(float value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_initialViewportClearColorR){value}; }
static inline _s_a3533841_initialViewportClearColorG _a3533841_initialViewportClearColorG(float value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_initialViewportClearColorG){value}; }
static inline _s_a3533841_initialViewportClearColorB _a3533841_initialViewportClearColorB(float value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_initialViewportClearColorB){value}; }
static inline _s_a3533841_initialViewportClearColorA _a3533841_initialViewportClearColorA(float value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_initialViewportClearColorA){value}; }
static inline _s_a3533841_optionalProgramName _a3533841_optionalProgramName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_optionalProgramName){value}; }
static inline _s_a3533841_optionalEngineName _a3533841_optionalEngineName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_optionalEngineName){value}; }
static inline _s_a3533841_rteCreateContextParameters _a3533841_rteCreateContextParameters(RedRteCreateContextParameters* value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_rteCreateContextParameters){value}; }
static inline _s_a3533841_outHelperAppWindow _a3533841_outHelperAppWindow(RedRteHandleHelperAppWindow* value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_outHelperAppWindow){value}; }
static inline _s_a3533841_outStatuses _a3533841_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_outStatuses){value}; }
static inline _s_a3533841_optionalFile _a3533841_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_optionalFile){value}; }
static inline _s_a3533841_optionalLine _a3533841_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_optionalLine){value}; }
static inline _s_a3533841_optionalUserData _a3533841_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_optionalUserData){value}; }
static inline _s_a3533841_rteParameters _a3533841_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a3533841_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateHelperAppWindow(_s_a3533841_callbacks callbacks, _s_a3533841_initialWindowWidth initialWindowWidth, _s_a3533841_initialWindowHeight initialWindowHeight, _s_a3533841_initialIsVsyncEnabled initialIsVsyncEnabled, _s_a3533841_initialViewportClearColorR initialViewportClearColorR, _s_a3533841_initialViewportClearColorG initialViewportClearColorG, _s_a3533841_initialViewportClearColorB initialViewportClearColorB, _s_a3533841_initialViewportClearColorA initialViewportClearColorA, _s_a3533841_optionalProgramName optionalProgramName, _s_a3533841_optionalEngineName optionalEngineName, _s_a3533841_rteCreateContextParameters rteCreateContextParameters, _s_a3533841_outHelperAppWindow outHelperAppWindow, _s_a3533841_outStatuses outStatuses, _s_a3533841_optionalFile optionalFile, _s_a3533841_optionalLine optionalLine, _s_a3533841_optionalUserData optionalUserData, _s_a3533841_rteParameters rteParameters) {
  return redRteCreateHelperAppWindow(callbacks.value, initialWindowWidth.value, initialWindowHeight.value, initialIsVsyncEnabled.value, initialViewportClearColorR.value, initialViewportClearColorG.value, initialViewportClearColorB.value, initialViewportClearColorA.value, optionalProgramName.value, optionalEngineName.value, rteCreateContextParameters.value, outHelperAppWindow.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyHelperAppWindow redRteDestroyHelperAppWindow
#define _b69fb9f4_helperAppWindow(value) value
#define _b69fb9f4_optionalFile(value) value
#define _b69fb9f4_optionalLine(value) value
#define _b69fb9f4_optionalUserData(value) value
#define _b69fb9f4_rteParameters(value) value
#else
typedef struct _s_b69fb9f4_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_b69fb9f4_helperAppWindow;
typedef struct _s_b69fb9f4_optionalFile { char* value; } _s_b69fb9f4_optionalFile;
typedef struct _s_b69fb9f4_optionalLine { int value; } _s_b69fb9f4_optionalLine;
typedef struct _s_b69fb9f4_optionalUserData { void* value; } _s_b69fb9f4_optionalUserData;
typedef struct _s_b69fb9f4_rteParameters { void* value; } _s_b69fb9f4_rteParameters;
static inline _s_b69fb9f4_helperAppWindow _b69fb9f4_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_b69fb9f4_helperAppWindow){value}; }
static inline _s_b69fb9f4_optionalFile _b69fb9f4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b69fb9f4_optionalFile){value}; }
static inline _s_b69fb9f4_optionalLine _b69fb9f4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b69fb9f4_optionalLine){value}; }
static inline _s_b69fb9f4_optionalUserData _b69fb9f4_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b69fb9f4_optionalUserData){value}; }
static inline _s_b69fb9f4_rteParameters _b69fb9f4_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b69fb9f4_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyHelperAppWindow(_s_b69fb9f4_helperAppWindow helperAppWindow, _s_b69fb9f4_optionalFile optionalFile, _s_b69fb9f4_optionalLine optionalLine, _s_b69fb9f4_optionalUserData optionalUserData, _s_b69fb9f4_rteParameters rteParameters) {
  return redRteDestroyHelperAppWindow(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowRun redRteHelperAppWindowRun
#define _1e2b27d6_helperAppWindow(value) value
#define _1e2b27d6_optionalFile(value) value
#define _1e2b27d6_optionalLine(value) value
#define _1e2b27d6_optionalUserData(value) value
#define _1e2b27d6_rteParameters(value) value
#else
typedef struct _s_1e2b27d6_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_1e2b27d6_helperAppWindow;
typedef struct _s_1e2b27d6_optionalFile { char* value; } _s_1e2b27d6_optionalFile;
typedef struct _s_1e2b27d6_optionalLine { int value; } _s_1e2b27d6_optionalLine;
typedef struct _s_1e2b27d6_optionalUserData { void* value; } _s_1e2b27d6_optionalUserData;
typedef struct _s_1e2b27d6_rteParameters { void* value; } _s_1e2b27d6_rteParameters;
static inline _s_1e2b27d6_helperAppWindow _1e2b27d6_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_1e2b27d6_helperAppWindow){value}; }
static inline _s_1e2b27d6_optionalFile _1e2b27d6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1e2b27d6_optionalFile){value}; }
static inline _s_1e2b27d6_optionalLine _1e2b27d6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1e2b27d6_optionalLine){value}; }
static inline _s_1e2b27d6_optionalUserData _1e2b27d6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1e2b27d6_optionalUserData){value}; }
static inline _s_1e2b27d6_rteParameters _1e2b27d6_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1e2b27d6_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowRun(_s_1e2b27d6_helperAppWindow helperAppWindow, _s_1e2b27d6_optionalFile optionalFile, _s_1e2b27d6_optionalLine optionalLine, _s_1e2b27d6_optionalUserData optionalUserData, _s_1e2b27d6_rteParameters rteParameters) {
  return redRteHelperAppWindowRun(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowClose redRteHelperAppWindowClose
#define _f4d4b655_helperAppWindow(value) value
#define _f4d4b655_optionalFile(value) value
#define _f4d4b655_optionalLine(value) value
#define _f4d4b655_optionalUserData(value) value
#define _f4d4b655_rteParameters(value) value
#else
typedef struct _s_f4d4b655_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_f4d4b655_helperAppWindow;
typedef struct _s_f4d4b655_optionalFile { char* value; } _s_f4d4b655_optionalFile;
typedef struct _s_f4d4b655_optionalLine { int value; } _s_f4d4b655_optionalLine;
typedef struct _s_f4d4b655_optionalUserData { void* value; } _s_f4d4b655_optionalUserData;
typedef struct _s_f4d4b655_rteParameters { void* value; } _s_f4d4b655_rteParameters;
static inline _s_f4d4b655_helperAppWindow _f4d4b655_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_f4d4b655_helperAppWindow){value}; }
static inline _s_f4d4b655_optionalFile _f4d4b655_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f4d4b655_optionalFile){value}; }
static inline _s_f4d4b655_optionalLine _f4d4b655_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f4d4b655_optionalLine){value}; }
static inline _s_f4d4b655_optionalUserData _f4d4b655_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f4d4b655_optionalUserData){value}; }
static inline _s_f4d4b655_rteParameters _f4d4b655_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f4d4b655_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowClose(_s_f4d4b655_helperAppWindow helperAppWindow, _s_f4d4b655_optionalFile optionalFile, _s_f4d4b655_optionalLine optionalLine, _s_f4d4b655_optionalUserData optionalUserData, _s_f4d4b655_rteParameters rteParameters) {
  return redRteHelperAppWindowClose(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowSetViewport redRteHelperAppWindowSetViewport
#define _9a9c2dde_helperAppWindow(value) value
#define _9a9c2dde_calls(value) value
#define _9a9c2dde_optionalFile(value) value
#define _9a9c2dde_optionalLine(value) value
#define _9a9c2dde_optionalUserData(value) value
#define _9a9c2dde_rteParameters(value) value
#else
typedef struct _s_9a9c2dde_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_9a9c2dde_helperAppWindow;
typedef struct _s_9a9c2dde_calls { RedHandleCalls value; } _s_9a9c2dde_calls;
typedef struct _s_9a9c2dde_optionalFile { char* value; } _s_9a9c2dde_optionalFile;
typedef struct _s_9a9c2dde_optionalLine { int value; } _s_9a9c2dde_optionalLine;
typedef struct _s_9a9c2dde_optionalUserData { void* value; } _s_9a9c2dde_optionalUserData;
typedef struct _s_9a9c2dde_rteParameters { void* value; } _s_9a9c2dde_rteParameters;
static inline _s_9a9c2dde_helperAppWindow _9a9c2dde_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_9a9c2dde_helperAppWindow){value}; }
static inline _s_9a9c2dde_calls _9a9c2dde_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_9a9c2dde_calls){value}; }
static inline _s_9a9c2dde_optionalFile _9a9c2dde_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9a9c2dde_optionalFile){value}; }
static inline _s_9a9c2dde_optionalLine _9a9c2dde_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9a9c2dde_optionalLine){value}; }
static inline _s_9a9c2dde_optionalUserData _9a9c2dde_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9a9c2dde_optionalUserData){value}; }
static inline _s_9a9c2dde_rteParameters _9a9c2dde_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9a9c2dde_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowSetViewport(_s_9a9c2dde_helperAppWindow helperAppWindow, _s_9a9c2dde_calls calls, _s_9a9c2dde_optionalFile optionalFile, _s_9a9c2dde_optionalLine optionalLine, _s_9a9c2dde_optionalUserData optionalUserData, _s_9a9c2dde_rteParameters rteParameters) {
  return redRteHelperAppWindowSetViewport(helperAppWindow.value, calls.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowIsVsyncEnabled redRteHelperAppWindowIsVsyncEnabled
#define _37df0c31_helperAppWindow(value) value
#define _37df0c31_optionalFile(value) value
#define _37df0c31_optionalLine(value) value
#define _37df0c31_optionalUserData(value) value
#define _37df0c31_rteParameters(value) value
#else
typedef struct _s_37df0c31_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_37df0c31_helperAppWindow;
typedef struct _s_37df0c31_optionalFile { char* value; } _s_37df0c31_optionalFile;
typedef struct _s_37df0c31_optionalLine { int value; } _s_37df0c31_optionalLine;
typedef struct _s_37df0c31_optionalUserData { void* value; } _s_37df0c31_optionalUserData;
typedef struct _s_37df0c31_rteParameters { void* value; } _s_37df0c31_rteParameters;
static inline _s_37df0c31_helperAppWindow _37df0c31_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_37df0c31_helperAppWindow){value}; }
static inline _s_37df0c31_optionalFile _37df0c31_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_37df0c31_optionalFile){value}; }
static inline _s_37df0c31_optionalLine _37df0c31_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_37df0c31_optionalLine){value}; }
static inline _s_37df0c31_optionalUserData _37df0c31_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_37df0c31_optionalUserData){value}; }
static inline _s_37df0c31_rteParameters _37df0c31_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_37df0c31_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedBool32 REDGPU_NP_API np_redRteHelperAppWindowIsVsyncEnabled(_s_37df0c31_helperAppWindow helperAppWindow, _s_37df0c31_optionalFile optionalFile, _s_37df0c31_optionalLine optionalLine, _s_37df0c31_optionalUserData optionalUserData, _s_37df0c31_rteParameters rteParameters) {
  return redRteHelperAppWindowIsVsyncEnabled(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowSetVsyncEnabled redRteHelperAppWindowSetVsyncEnabled
#define _a5ddca3b_helperAppWindow(value) value
#define _a5ddca3b_enableVsync(value) value
#define _a5ddca3b_optionalFile(value) value
#define _a5ddca3b_optionalLine(value) value
#define _a5ddca3b_optionalUserData(value) value
#define _a5ddca3b_rteParameters(value) value
#else
typedef struct _s_a5ddca3b_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_a5ddca3b_helperAppWindow;
typedef struct _s_a5ddca3b_enableVsync { RedBool32 value; } _s_a5ddca3b_enableVsync;
typedef struct _s_a5ddca3b_optionalFile { char* value; } _s_a5ddca3b_optionalFile;
typedef struct _s_a5ddca3b_optionalLine { int value; } _s_a5ddca3b_optionalLine;
typedef struct _s_a5ddca3b_optionalUserData { void* value; } _s_a5ddca3b_optionalUserData;
typedef struct _s_a5ddca3b_rteParameters { void* value; } _s_a5ddca3b_rteParameters;
static inline _s_a5ddca3b_helperAppWindow _a5ddca3b_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_a5ddca3b_helperAppWindow){value}; }
static inline _s_a5ddca3b_enableVsync _a5ddca3b_enableVsync(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_a5ddca3b_enableVsync){value}; }
static inline _s_a5ddca3b_optionalFile _a5ddca3b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a5ddca3b_optionalFile){value}; }
static inline _s_a5ddca3b_optionalLine _a5ddca3b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a5ddca3b_optionalLine){value}; }
static inline _s_a5ddca3b_optionalUserData _a5ddca3b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a5ddca3b_optionalUserData){value}; }
static inline _s_a5ddca3b_rteParameters _a5ddca3b_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a5ddca3b_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowSetVsyncEnabled(_s_a5ddca3b_helperAppWindow helperAppWindow, _s_a5ddca3b_enableVsync enableVsync, _s_a5ddca3b_optionalFile optionalFile, _s_a5ddca3b_optionalLine optionalLine, _s_a5ddca3b_optionalUserData optionalUserData, _s_a5ddca3b_rteParameters rteParameters) {
  return redRteHelperAppWindowSetVsyncEnabled(helperAppWindow.value, enableVsync.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowSetViewportClearColor redRteHelperAppWindowSetViewportClearColor
#define _e0f974f0_helperAppWindow(value) value
#define _e0f974f0_viewportClearColorR(value) value
#define _e0f974f0_viewportClearColorG(value) value
#define _e0f974f0_viewportClearColorB(value) value
#define _e0f974f0_viewportClearColorA(value) value
#define _e0f974f0_optionalFile(value) value
#define _e0f974f0_optionalLine(value) value
#define _e0f974f0_optionalUserData(value) value
#define _e0f974f0_rteParameters(value) value
#else
typedef struct _s_e0f974f0_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_e0f974f0_helperAppWindow;
typedef struct _s_e0f974f0_viewportClearColorR { float value; } _s_e0f974f0_viewportClearColorR;
typedef struct _s_e0f974f0_viewportClearColorG { float value; } _s_e0f974f0_viewportClearColorG;
typedef struct _s_e0f974f0_viewportClearColorB { float value; } _s_e0f974f0_viewportClearColorB;
typedef struct _s_e0f974f0_viewportClearColorA { float value; } _s_e0f974f0_viewportClearColorA;
typedef struct _s_e0f974f0_optionalFile { char* value; } _s_e0f974f0_optionalFile;
typedef struct _s_e0f974f0_optionalLine { int value; } _s_e0f974f0_optionalLine;
typedef struct _s_e0f974f0_optionalUserData { void* value; } _s_e0f974f0_optionalUserData;
typedef struct _s_e0f974f0_rteParameters { void* value; } _s_e0f974f0_rteParameters;
static inline _s_e0f974f0_helperAppWindow _e0f974f0_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_e0f974f0_helperAppWindow){value}; }
static inline _s_e0f974f0_viewportClearColorR _e0f974f0_viewportClearColorR(float value) { return REDGPU_NP_STRUCT_INIT(_s_e0f974f0_viewportClearColorR){value}; }
static inline _s_e0f974f0_viewportClearColorG _e0f974f0_viewportClearColorG(float value) { return REDGPU_NP_STRUCT_INIT(_s_e0f974f0_viewportClearColorG){value}; }
static inline _s_e0f974f0_viewportClearColorB _e0f974f0_viewportClearColorB(float value) { return REDGPU_NP_STRUCT_INIT(_s_e0f974f0_viewportClearColorB){value}; }
static inline _s_e0f974f0_viewportClearColorA _e0f974f0_viewportClearColorA(float value) { return REDGPU_NP_STRUCT_INIT(_s_e0f974f0_viewportClearColorA){value}; }
static inline _s_e0f974f0_optionalFile _e0f974f0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e0f974f0_optionalFile){value}; }
static inline _s_e0f974f0_optionalLine _e0f974f0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e0f974f0_optionalLine){value}; }
static inline _s_e0f974f0_optionalUserData _e0f974f0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e0f974f0_optionalUserData){value}; }
static inline _s_e0f974f0_rteParameters _e0f974f0_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e0f974f0_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowSetViewportClearColor(_s_e0f974f0_helperAppWindow helperAppWindow, _s_e0f974f0_viewportClearColorR viewportClearColorR, _s_e0f974f0_viewportClearColorG viewportClearColorG, _s_e0f974f0_viewportClearColorB viewportClearColorB, _s_e0f974f0_viewportClearColorA viewportClearColorA, _s_e0f974f0_optionalFile optionalFile, _s_e0f974f0_optionalLine optionalLine, _s_e0f974f0_optionalUserData optionalUserData, _s_e0f974f0_rteParameters rteParameters) {
  return redRteHelperAppWindowSetViewportClearColor(helperAppWindow.value, viewportClearColorR.value, viewportClearColorG.value, viewportClearColorB.value, viewportClearColorA.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowAddWaitSemaphore redRteHelperAppWindowAddWaitSemaphore
#define _e8d15af9_helperAppWindow(value) value
#define _e8d15af9_vkSemaphoreSubmitInfoKHR(value) value
#define _e8d15af9_optionalFile(value) value
#define _e8d15af9_optionalLine(value) value
#define _e8d15af9_optionalUserData(value) value
#define _e8d15af9_rteParameters(value) value
#else
typedef struct _s_e8d15af9_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_e8d15af9_helperAppWindow;
typedef struct _s_e8d15af9_vkSemaphoreSubmitInfoKHR { void* value; } _s_e8d15af9_vkSemaphoreSubmitInfoKHR;
typedef struct _s_e8d15af9_optionalFile { char* value; } _s_e8d15af9_optionalFile;
typedef struct _s_e8d15af9_optionalLine { int value; } _s_e8d15af9_optionalLine;
typedef struct _s_e8d15af9_optionalUserData { void* value; } _s_e8d15af9_optionalUserData;
typedef struct _s_e8d15af9_rteParameters { void* value; } _s_e8d15af9_rteParameters;
static inline _s_e8d15af9_helperAppWindow _e8d15af9_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_e8d15af9_helperAppWindow){value}; }
static inline _s_e8d15af9_vkSemaphoreSubmitInfoKHR _e8d15af9_vkSemaphoreSubmitInfoKHR(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e8d15af9_vkSemaphoreSubmitInfoKHR){value}; }
static inline _s_e8d15af9_optionalFile _e8d15af9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e8d15af9_optionalFile){value}; }
static inline _s_e8d15af9_optionalLine _e8d15af9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e8d15af9_optionalLine){value}; }
static inline _s_e8d15af9_optionalUserData _e8d15af9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e8d15af9_optionalUserData){value}; }
static inline _s_e8d15af9_rteParameters _e8d15af9_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e8d15af9_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowAddWaitSemaphore(_s_e8d15af9_helperAppWindow helperAppWindow, _s_e8d15af9_vkSemaphoreSubmitInfoKHR vkSemaphoreSubmitInfoKHR, _s_e8d15af9_optionalFile optionalFile, _s_e8d15af9_optionalLine optionalLine, _s_e8d15af9_optionalUserData optionalUserData, _s_e8d15af9_rteParameters rteParameters) {
  return redRteHelperAppWindowAddWaitSemaphore(helperAppWindow.value, vkSemaphoreSubmitInfoKHR.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowTempCallsCreateAndSet redRteHelperAppWindowTempCallsCreateAndSet
#define _1c829b33_helperAppWindow(value) value
#define _1c829b33_optionalFile(value) value
#define _1c829b33_optionalLine(value) value
#define _1c829b33_optionalUserData(value) value
#define _1c829b33_rteParameters(value) value
#else
typedef struct _s_1c829b33_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_1c829b33_helperAppWindow;
typedef struct _s_1c829b33_optionalFile { char* value; } _s_1c829b33_optionalFile;
typedef struct _s_1c829b33_optionalLine { int value; } _s_1c829b33_optionalLine;
typedef struct _s_1c829b33_optionalUserData { void* value; } _s_1c829b33_optionalUserData;
typedef struct _s_1c829b33_rteParameters { void* value; } _s_1c829b33_rteParameters;
static inline _s_1c829b33_helperAppWindow _1c829b33_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_1c829b33_helperAppWindow){value}; }
static inline _s_1c829b33_optionalFile _1c829b33_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1c829b33_optionalFile){value}; }
static inline _s_1c829b33_optionalLine _1c829b33_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1c829b33_optionalLine){value}; }
static inline _s_1c829b33_optionalUserData _1c829b33_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1c829b33_optionalUserData){value}; }
static inline _s_1c829b33_rteParameters _1c829b33_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1c829b33_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleCalls REDGPU_NP_API np_redRteHelperAppWindowTempCallsCreateAndSet(_s_1c829b33_helperAppWindow helperAppWindow, _s_1c829b33_optionalFile optionalFile, _s_1c829b33_optionalLine optionalLine, _s_1c829b33_optionalUserData optionalUserData, _s_1c829b33_rteParameters rteParameters) {
  return redRteHelperAppWindowTempCallsCreateAndSet(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowTempCallsEndSubmitWaitAndDestroy redRteHelperAppWindowTempCallsEndSubmitWaitAndDestroy
#define _000cb479_helperAppWindow(value) value
#define _000cb479_tempCalls(value) value
#define _000cb479_optionalFile(value) value
#define _000cb479_optionalLine(value) value
#define _000cb479_optionalUserData(value) value
#define _000cb479_rteParameters(value) value
#else
typedef struct _s_000cb479_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_000cb479_helperAppWindow;
typedef struct _s_000cb479_tempCalls { RedHandleCalls value; } _s_000cb479_tempCalls;
typedef struct _s_000cb479_optionalFile { char* value; } _s_000cb479_optionalFile;
typedef struct _s_000cb479_optionalLine { int value; } _s_000cb479_optionalLine;
typedef struct _s_000cb479_optionalUserData { void* value; } _s_000cb479_optionalUserData;
typedef struct _s_000cb479_rteParameters { void* value; } _s_000cb479_rteParameters;
static inline _s_000cb479_helperAppWindow _000cb479_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_000cb479_helperAppWindow){value}; }
static inline _s_000cb479_tempCalls _000cb479_tempCalls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_000cb479_tempCalls){value}; }
static inline _s_000cb479_optionalFile _000cb479_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_000cb479_optionalFile){value}; }
static inline _s_000cb479_optionalLine _000cb479_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_000cb479_optionalLine){value}; }
static inline _s_000cb479_optionalUserData _000cb479_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_000cb479_optionalUserData){value}; }
static inline _s_000cb479_rteParameters _000cb479_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_000cb479_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowTempCallsEndSubmitWaitAndDestroy(_s_000cb479_helperAppWindow helperAppWindow, _s_000cb479_tempCalls tempCalls, _s_000cb479_optionalFile optionalFile, _s_000cb479_optionalLine optionalLine, _s_000cb479_optionalUserData optionalUserData, _s_000cb479_rteParameters rteParameters) {
  return redRteHelperAppWindowTempCallsEndSubmitWaitAndDestroy(helperAppWindow.value, tempCalls.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowOnFileDrop redRteHelperAppWindowOnFileDrop
#define _473bb2ca_helperAppWindow(value) value
#define _473bb2ca_filename(value) value
#define _473bb2ca_optionalFile(value) value
#define _473bb2ca_optionalLine(value) value
#define _473bb2ca_optionalUserData(value) value
#define _473bb2ca_rteParameters(value) value
#else
typedef struct _s_473bb2ca_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_473bb2ca_helperAppWindow;
typedef struct _s_473bb2ca_filename { char* value; } _s_473bb2ca_filename;
typedef struct _s_473bb2ca_optionalFile { char* value; } _s_473bb2ca_optionalFile;
typedef struct _s_473bb2ca_optionalLine { int value; } _s_473bb2ca_optionalLine;
typedef struct _s_473bb2ca_optionalUserData { void* value; } _s_473bb2ca_optionalUserData;
typedef struct _s_473bb2ca_rteParameters { void* value; } _s_473bb2ca_rteParameters;
static inline _s_473bb2ca_helperAppWindow _473bb2ca_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_473bb2ca_helperAppWindow){value}; }
static inline _s_473bb2ca_filename _473bb2ca_filename(char* value) { return REDGPU_NP_STRUCT_INIT(_s_473bb2ca_filename){value}; }
static inline _s_473bb2ca_optionalFile _473bb2ca_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_473bb2ca_optionalFile){value}; }
static inline _s_473bb2ca_optionalLine _473bb2ca_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_473bb2ca_optionalLine){value}; }
static inline _s_473bb2ca_optionalUserData _473bb2ca_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_473bb2ca_optionalUserData){value}; }
static inline _s_473bb2ca_rteParameters _473bb2ca_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_473bb2ca_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowOnFileDrop(_s_473bb2ca_helperAppWindow helperAppWindow, _s_473bb2ca_filename filename, _s_473bb2ca_optionalFile optionalFile, _s_473bb2ca_optionalLine optionalLine, _s_473bb2ca_optionalUserData optionalUserData, _s_473bb2ca_rteParameters rteParameters) {
  return redRteHelperAppWindowOnFileDrop(helperAppWindow.value, filename.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetRteContext redRteHelperAppWindowGetRteContext
#define _a9bf3a85_helperAppWindow(value) value
#define _a9bf3a85_optionalFile(value) value
#define _a9bf3a85_optionalLine(value) value
#define _a9bf3a85_optionalUserData(value) value
#define _a9bf3a85_rteParameters(value) value
#else
typedef struct _s_a9bf3a85_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_a9bf3a85_helperAppWindow;
typedef struct _s_a9bf3a85_optionalFile { char* value; } _s_a9bf3a85_optionalFile;
typedef struct _s_a9bf3a85_optionalLine { int value; } _s_a9bf3a85_optionalLine;
typedef struct _s_a9bf3a85_optionalUserData { void* value; } _s_a9bf3a85_optionalUserData;
typedef struct _s_a9bf3a85_rteParameters { void* value; } _s_a9bf3a85_rteParameters;
static inline _s_a9bf3a85_helperAppWindow _a9bf3a85_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_a9bf3a85_helperAppWindow){value}; }
static inline _s_a9bf3a85_optionalFile _a9bf3a85_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a9bf3a85_optionalFile){value}; }
static inline _s_a9bf3a85_optionalLine _a9bf3a85_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a9bf3a85_optionalLine){value}; }
static inline _s_a9bf3a85_optionalUserData _a9bf3a85_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a9bf3a85_optionalUserData){value}; }
static inline _s_a9bf3a85_rteParameters _a9bf3a85_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a9bf3a85_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedRteHandleContext REDGPU_NP_API np_redRteHelperAppWindowGetRteContext(_s_a9bf3a85_helperAppWindow helperAppWindow, _s_a9bf3a85_optionalFile optionalFile, _s_a9bf3a85_optionalLine optionalLine, _s_a9bf3a85_optionalUserData optionalUserData, _s_a9bf3a85_rteParameters rteParameters) {
  return redRteHelperAppWindowGetRteContext(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetGlfwWindow redRteHelperAppWindowGetGlfwWindow
#define _607fba3b_helperAppWindow(value) value
#define _607fba3b_optionalFile(value) value
#define _607fba3b_optionalLine(value) value
#define _607fba3b_optionalUserData(value) value
#define _607fba3b_rteParameters(value) value
#else
typedef struct _s_607fba3b_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_607fba3b_helperAppWindow;
typedef struct _s_607fba3b_optionalFile { char* value; } _s_607fba3b_optionalFile;
typedef struct _s_607fba3b_optionalLine { int value; } _s_607fba3b_optionalLine;
typedef struct _s_607fba3b_optionalUserData { void* value; } _s_607fba3b_optionalUserData;
typedef struct _s_607fba3b_rteParameters { void* value; } _s_607fba3b_rteParameters;
static inline _s_607fba3b_helperAppWindow _607fba3b_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_607fba3b_helperAppWindow){value}; }
static inline _s_607fba3b_optionalFile _607fba3b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_607fba3b_optionalFile){value}; }
static inline _s_607fba3b_optionalLine _607fba3b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_607fba3b_optionalLine){value}; }
static inline _s_607fba3b_optionalUserData _607fba3b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_607fba3b_optionalUserData){value}; }
static inline _s_607fba3b_rteParameters _607fba3b_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_607fba3b_rteParameters){value}; }
REDGPU_NP_DECLSPEC void* REDGPU_NP_API np_redRteHelperAppWindowGetGlfwWindow(_s_607fba3b_helperAppWindow helperAppWindow, _s_607fba3b_optionalFile optionalFile, _s_607fba3b_optionalLine optionalLine, _s_607fba3b_optionalUserData optionalUserData, _s_607fba3b_rteParameters rteParameters) {
  return redRteHelperAppWindowGetGlfwWindow(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetViewportWidth redRteHelperAppWindowGetViewportWidth
#define _b3767ffc_helperAppWindow(value) value
#define _b3767ffc_optionalFile(value) value
#define _b3767ffc_optionalLine(value) value
#define _b3767ffc_optionalUserData(value) value
#define _b3767ffc_rteParameters(value) value
#else
typedef struct _s_b3767ffc_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_b3767ffc_helperAppWindow;
typedef struct _s_b3767ffc_optionalFile { char* value; } _s_b3767ffc_optionalFile;
typedef struct _s_b3767ffc_optionalLine { int value; } _s_b3767ffc_optionalLine;
typedef struct _s_b3767ffc_optionalUserData { void* value; } _s_b3767ffc_optionalUserData;
typedef struct _s_b3767ffc_rteParameters { void* value; } _s_b3767ffc_rteParameters;
static inline _s_b3767ffc_helperAppWindow _b3767ffc_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_b3767ffc_helperAppWindow){value}; }
static inline _s_b3767ffc_optionalFile _b3767ffc_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b3767ffc_optionalFile){value}; }
static inline _s_b3767ffc_optionalLine _b3767ffc_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b3767ffc_optionalLine){value}; }
static inline _s_b3767ffc_optionalUserData _b3767ffc_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b3767ffc_optionalUserData){value}; }
static inline _s_b3767ffc_rteParameters _b3767ffc_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b3767ffc_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowGetViewportWidth(_s_b3767ffc_helperAppWindow helperAppWindow, _s_b3767ffc_optionalFile optionalFile, _s_b3767ffc_optionalLine optionalLine, _s_b3767ffc_optionalUserData optionalUserData, _s_b3767ffc_rteParameters rteParameters) {
  return redRteHelperAppWindowGetViewportWidth(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetViewportHeight redRteHelperAppWindowGetViewportHeight
#define _627143be_helperAppWindow(value) value
#define _627143be_optionalFile(value) value
#define _627143be_optionalLine(value) value
#define _627143be_optionalUserData(value) value
#define _627143be_rteParameters(value) value
#else
typedef struct _s_627143be_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_627143be_helperAppWindow;
typedef struct _s_627143be_optionalFile { char* value; } _s_627143be_optionalFile;
typedef struct _s_627143be_optionalLine { int value; } _s_627143be_optionalLine;
typedef struct _s_627143be_optionalUserData { void* value; } _s_627143be_optionalUserData;
typedef struct _s_627143be_rteParameters { void* value; } _s_627143be_rteParameters;
static inline _s_627143be_helperAppWindow _627143be_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_627143be_helperAppWindow){value}; }
static inline _s_627143be_optionalFile _627143be_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_627143be_optionalFile){value}; }
static inline _s_627143be_optionalLine _627143be_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_627143be_optionalLine){value}; }
static inline _s_627143be_optionalUserData _627143be_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_627143be_optionalUserData){value}; }
static inline _s_627143be_rteParameters _627143be_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_627143be_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowGetViewportHeight(_s_627143be_helperAppWindow helperAppWindow, _s_627143be_optionalFile optionalFile, _s_627143be_optionalLine optionalLine, _s_627143be_optionalUserData optionalUserData, _s_627143be_rteParameters rteParameters) {
  return redRteHelperAppWindowGetViewportHeight(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetWindowWidth redRteHelperAppWindowGetWindowWidth
#define _c6e00657_helperAppWindow(value) value
#define _c6e00657_optionalFile(value) value
#define _c6e00657_optionalLine(value) value
#define _c6e00657_optionalUserData(value) value
#define _c6e00657_rteParameters(value) value
#else
typedef struct _s_c6e00657_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_c6e00657_helperAppWindow;
typedef struct _s_c6e00657_optionalFile { char* value; } _s_c6e00657_optionalFile;
typedef struct _s_c6e00657_optionalLine { int value; } _s_c6e00657_optionalLine;
typedef struct _s_c6e00657_optionalUserData { void* value; } _s_c6e00657_optionalUserData;
typedef struct _s_c6e00657_rteParameters { void* value; } _s_c6e00657_rteParameters;
static inline _s_c6e00657_helperAppWindow _c6e00657_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_c6e00657_helperAppWindow){value}; }
static inline _s_c6e00657_optionalFile _c6e00657_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c6e00657_optionalFile){value}; }
static inline _s_c6e00657_optionalLine _c6e00657_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c6e00657_optionalLine){value}; }
static inline _s_c6e00657_optionalUserData _c6e00657_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c6e00657_optionalUserData){value}; }
static inline _s_c6e00657_rteParameters _c6e00657_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c6e00657_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowGetWindowWidth(_s_c6e00657_helperAppWindow helperAppWindow, _s_c6e00657_optionalFile optionalFile, _s_c6e00657_optionalLine optionalLine, _s_c6e00657_optionalUserData optionalUserData, _s_c6e00657_rteParameters rteParameters) {
  return redRteHelperAppWindowGetWindowWidth(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetWindowHeight redRteHelperAppWindowGetWindowHeight
#define _7c6269e1_helperAppWindow(value) value
#define _7c6269e1_optionalFile(value) value
#define _7c6269e1_optionalLine(value) value
#define _7c6269e1_optionalUserData(value) value
#define _7c6269e1_rteParameters(value) value
#else
typedef struct _s_7c6269e1_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_7c6269e1_helperAppWindow;
typedef struct _s_7c6269e1_optionalFile { char* value; } _s_7c6269e1_optionalFile;
typedef struct _s_7c6269e1_optionalLine { int value; } _s_7c6269e1_optionalLine;
typedef struct _s_7c6269e1_optionalUserData { void* value; } _s_7c6269e1_optionalUserData;
typedef struct _s_7c6269e1_rteParameters { void* value; } _s_7c6269e1_rteParameters;
static inline _s_7c6269e1_helperAppWindow _7c6269e1_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_7c6269e1_helperAppWindow){value}; }
static inline _s_7c6269e1_optionalFile _7c6269e1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7c6269e1_optionalFile){value}; }
static inline _s_7c6269e1_optionalLine _7c6269e1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7c6269e1_optionalLine){value}; }
static inline _s_7c6269e1_optionalUserData _7c6269e1_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7c6269e1_optionalUserData){value}; }
static inline _s_7c6269e1_rteParameters _7c6269e1_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7c6269e1_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperAppWindowGetWindowHeight(_s_7c6269e1_helperAppWindow helperAppWindow, _s_7c6269e1_optionalFile optionalFile, _s_7c6269e1_optionalLine optionalLine, _s_7c6269e1_optionalUserData optionalUserData, _s_7c6269e1_rteParameters rteParameters) {
  return redRteHelperAppWindowGetWindowHeight(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperAppWindowGetImGuiImplVulkanHWindowData redRteHelperAppWindowGetImGuiImplVulkanHWindowData
#define _d574470a_helperAppWindow(value) value
#define _d574470a_optionalFile(value) value
#define _d574470a_optionalLine(value) value
#define _d574470a_optionalUserData(value) value
#define _d574470a_rteParameters(value) value
#else
typedef struct _s_d574470a_helperAppWindow { RedRteHandleHelperAppWindow value; } _s_d574470a_helperAppWindow;
typedef struct _s_d574470a_optionalFile { char* value; } _s_d574470a_optionalFile;
typedef struct _s_d574470a_optionalLine { int value; } _s_d574470a_optionalLine;
typedef struct _s_d574470a_optionalUserData { void* value; } _s_d574470a_optionalUserData;
typedef struct _s_d574470a_rteParameters { void* value; } _s_d574470a_rteParameters;
static inline _s_d574470a_helperAppWindow _d574470a_helperAppWindow(RedRteHandleHelperAppWindow value) { return REDGPU_NP_STRUCT_INIT(_s_d574470a_helperAppWindow){value}; }
static inline _s_d574470a_optionalFile _d574470a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d574470a_optionalFile){value}; }
static inline _s_d574470a_optionalLine _d574470a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d574470a_optionalLine){value}; }
static inline _s_d574470a_optionalUserData _d574470a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d574470a_optionalUserData){value}; }
static inline _s_d574470a_rteParameters _d574470a_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d574470a_rteParameters){value}; }
REDGPU_NP_DECLSPEC void* REDGPU_NP_API np_redRteHelperAppWindowGetImGuiImplVulkanHWindowData(_s_d574470a_helperAppWindow helperAppWindow, _s_d574470a_optionalFile optionalFile, _s_d574470a_optionalLine optionalLine, _s_d574470a_optionalUserData optionalUserData, _s_d574470a_rteParameters rteParameters) {
  return redRteHelperAppWindowGetImGuiImplVulkanHWindowData(helperAppWindow.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCreateHelperGBuffer redRteCreateHelperGBuffer
#define _98ceb7c8_rteContext(value) value
#define _98ceb7c8_rteHandleHelperAllocator(value) value
#define _98ceb7c8_width(value) value
#define _98ceb7c8_height(value) value
#define _98ceb7c8_colorFormatsCount(value) value
#define _98ceb7c8_colorFormats(value) value
#define _98ceb7c8_depthFormat(value) value
#define _98ceb7c8_outHelperGBuffer(value) value
#define _98ceb7c8_outStatuses(value) value
#define _98ceb7c8_optionalFile(value) value
#define _98ceb7c8_optionalLine(value) value
#define _98ceb7c8_optionalUserData(value) value
#define _98ceb7c8_rteParameters(value) value
#else
typedef struct _s_98ceb7c8_rteContext { RedRteHandleContext value; } _s_98ceb7c8_rteContext;
typedef struct _s_98ceb7c8_rteHandleHelperAllocator { void* value; } _s_98ceb7c8_rteHandleHelperAllocator;
typedef struct _s_98ceb7c8_width { unsigned value; } _s_98ceb7c8_width;
typedef struct _s_98ceb7c8_height { unsigned value; } _s_98ceb7c8_height;
typedef struct _s_98ceb7c8_colorFormatsCount { unsigned value; } _s_98ceb7c8_colorFormatsCount;
typedef struct _s_98ceb7c8_colorFormats { unsigned* value; } _s_98ceb7c8_colorFormats;
typedef struct _s_98ceb7c8_depthFormat { unsigned value; } _s_98ceb7c8_depthFormat;
typedef struct _s_98ceb7c8_outHelperGBuffer { RedRteHandleHelperGBuffer* value; } _s_98ceb7c8_outHelperGBuffer;
typedef struct _s_98ceb7c8_outStatuses { RedStatuses* value; } _s_98ceb7c8_outStatuses;
typedef struct _s_98ceb7c8_optionalFile { char* value; } _s_98ceb7c8_optionalFile;
typedef struct _s_98ceb7c8_optionalLine { int value; } _s_98ceb7c8_optionalLine;
typedef struct _s_98ceb7c8_optionalUserData { void* value; } _s_98ceb7c8_optionalUserData;
typedef struct _s_98ceb7c8_rteParameters { void* value; } _s_98ceb7c8_rteParameters;
static inline _s_98ceb7c8_rteContext _98ceb7c8_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_rteContext){value}; }
static inline _s_98ceb7c8_rteHandleHelperAllocator _98ceb7c8_rteHandleHelperAllocator(void* value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_rteHandleHelperAllocator){value}; }
static inline _s_98ceb7c8_width _98ceb7c8_width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_width){value}; }
static inline _s_98ceb7c8_height _98ceb7c8_height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_height){value}; }
static inline _s_98ceb7c8_colorFormatsCount _98ceb7c8_colorFormatsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_colorFormatsCount){value}; }
static inline _s_98ceb7c8_colorFormats _98ceb7c8_colorFormats(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_colorFormats){value}; }
static inline _s_98ceb7c8_depthFormat _98ceb7c8_depthFormat(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_depthFormat){value}; }
static inline _s_98ceb7c8_outHelperGBuffer _98ceb7c8_outHelperGBuffer(RedRteHandleHelperGBuffer* value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_outHelperGBuffer){value}; }
static inline _s_98ceb7c8_outStatuses _98ceb7c8_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_outStatuses){value}; }
static inline _s_98ceb7c8_optionalFile _98ceb7c8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_optionalFile){value}; }
static inline _s_98ceb7c8_optionalLine _98ceb7c8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_optionalLine){value}; }
static inline _s_98ceb7c8_optionalUserData _98ceb7c8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_optionalUserData){value}; }
static inline _s_98ceb7c8_rteParameters _98ceb7c8_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_98ceb7c8_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCreateHelperGBuffer(_s_98ceb7c8_rteContext rteContext, _s_98ceb7c8_rteHandleHelperAllocator rteHandleHelperAllocator, _s_98ceb7c8_width width, _s_98ceb7c8_height height, _s_98ceb7c8_colorFormatsCount colorFormatsCount, _s_98ceb7c8_colorFormats colorFormats, _s_98ceb7c8_depthFormat depthFormat, _s_98ceb7c8_outHelperGBuffer outHelperGBuffer, _s_98ceb7c8_outStatuses outStatuses, _s_98ceb7c8_optionalFile optionalFile, _s_98ceb7c8_optionalLine optionalLine, _s_98ceb7c8_optionalUserData optionalUserData, _s_98ceb7c8_rteParameters rteParameters) {
  return redRteCreateHelperGBuffer(rteContext.value, rteHandleHelperAllocator.value, width.value, height.value, colorFormatsCount.value, colorFormats.value, depthFormat.value, outHelperGBuffer.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteDestroyHelperGBuffer redRteDestroyHelperGBuffer
#define _ea8e1d58_helperGBuffer(value) value
#define _ea8e1d58_optionalFile(value) value
#define _ea8e1d58_optionalLine(value) value
#define _ea8e1d58_optionalUserData(value) value
#define _ea8e1d58_rteParameters(value) value
#else
typedef struct _s_ea8e1d58_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_ea8e1d58_helperGBuffer;
typedef struct _s_ea8e1d58_optionalFile { char* value; } _s_ea8e1d58_optionalFile;
typedef struct _s_ea8e1d58_optionalLine { int value; } _s_ea8e1d58_optionalLine;
typedef struct _s_ea8e1d58_optionalUserData { void* value; } _s_ea8e1d58_optionalUserData;
typedef struct _s_ea8e1d58_rteParameters { void* value; } _s_ea8e1d58_rteParameters;
static inline _s_ea8e1d58_helperGBuffer _ea8e1d58_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_ea8e1d58_helperGBuffer){value}; }
static inline _s_ea8e1d58_optionalFile _ea8e1d58_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ea8e1d58_optionalFile){value}; }
static inline _s_ea8e1d58_optionalLine _ea8e1d58_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ea8e1d58_optionalLine){value}; }
static inline _s_ea8e1d58_optionalUserData _ea8e1d58_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ea8e1d58_optionalUserData){value}; }
static inline _s_ea8e1d58_rteParameters _ea8e1d58_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ea8e1d58_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteDestroyHelperGBuffer(_s_ea8e1d58_helperGBuffer helperGBuffer, _s_ea8e1d58_optionalFile optionalFile, _s_ea8e1d58_optionalLine optionalLine, _s_ea8e1d58_optionalUserData optionalUserData, _s_ea8e1d58_rteParameters rteParameters) {
  return redRteDestroyHelperGBuffer(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetStruct redRteHelperGBufferGetStruct
#define _9caf5812_helperGBuffer(value) value
#define _9caf5812_index(value) value
#define _9caf5812_optionalFile(value) value
#define _9caf5812_optionalLine(value) value
#define _9caf5812_optionalUserData(value) value
#define _9caf5812_rteParameters(value) value
#else
typedef struct _s_9caf5812_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_9caf5812_helperGBuffer;
typedef struct _s_9caf5812_index { unsigned value; } _s_9caf5812_index;
typedef struct _s_9caf5812_optionalFile { char* value; } _s_9caf5812_optionalFile;
typedef struct _s_9caf5812_optionalLine { int value; } _s_9caf5812_optionalLine;
typedef struct _s_9caf5812_optionalUserData { void* value; } _s_9caf5812_optionalUserData;
typedef struct _s_9caf5812_rteParameters { void* value; } _s_9caf5812_rteParameters;
static inline _s_9caf5812_helperGBuffer _9caf5812_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_9caf5812_helperGBuffer){value}; }
static inline _s_9caf5812_index _9caf5812_index(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9caf5812_index){value}; }
static inline _s_9caf5812_optionalFile _9caf5812_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9caf5812_optionalFile){value}; }
static inline _s_9caf5812_optionalLine _9caf5812_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9caf5812_optionalLine){value}; }
static inline _s_9caf5812_optionalUserData _9caf5812_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9caf5812_optionalUserData){value}; }
static inline _s_9caf5812_rteParameters _9caf5812_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9caf5812_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleStruct REDGPU_NP_API np_redRteHelperGBufferGetStruct(_s_9caf5812_helperGBuffer helperGBuffer, _s_9caf5812_index index, _s_9caf5812_optionalFile optionalFile, _s_9caf5812_optionalLine optionalLine, _s_9caf5812_optionalUserData optionalUserData, _s_9caf5812_rteParameters rteParameters) {
  return redRteHelperGBufferGetStruct(helperGBuffer.value, index.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetWidth redRteHelperGBufferGetWidth
#define _e872f7d9_helperGBuffer(value) value
#define _e872f7d9_optionalFile(value) value
#define _e872f7d9_optionalLine(value) value
#define _e872f7d9_optionalUserData(value) value
#define _e872f7d9_rteParameters(value) value
#else
typedef struct _s_e872f7d9_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_e872f7d9_helperGBuffer;
typedef struct _s_e872f7d9_optionalFile { char* value; } _s_e872f7d9_optionalFile;
typedef struct _s_e872f7d9_optionalLine { int value; } _s_e872f7d9_optionalLine;
typedef struct _s_e872f7d9_optionalUserData { void* value; } _s_e872f7d9_optionalUserData;
typedef struct _s_e872f7d9_rteParameters { void* value; } _s_e872f7d9_rteParameters;
static inline _s_e872f7d9_helperGBuffer _e872f7d9_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_e872f7d9_helperGBuffer){value}; }
static inline _s_e872f7d9_optionalFile _e872f7d9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e872f7d9_optionalFile){value}; }
static inline _s_e872f7d9_optionalLine _e872f7d9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e872f7d9_optionalLine){value}; }
static inline _s_e872f7d9_optionalUserData _e872f7d9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e872f7d9_optionalUserData){value}; }
static inline _s_e872f7d9_rteParameters _e872f7d9_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e872f7d9_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperGBufferGetWidth(_s_e872f7d9_helperGBuffer helperGBuffer, _s_e872f7d9_optionalFile optionalFile, _s_e872f7d9_optionalLine optionalLine, _s_e872f7d9_optionalUserData optionalUserData, _s_e872f7d9_rteParameters rteParameters) {
  return redRteHelperGBufferGetWidth(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetHeight redRteHelperGBufferGetHeight
#define _f97b033e_helperGBuffer(value) value
#define _f97b033e_optionalFile(value) value
#define _f97b033e_optionalLine(value) value
#define _f97b033e_optionalUserData(value) value
#define _f97b033e_rteParameters(value) value
#else
typedef struct _s_f97b033e_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_f97b033e_helperGBuffer;
typedef struct _s_f97b033e_optionalFile { char* value; } _s_f97b033e_optionalFile;
typedef struct _s_f97b033e_optionalLine { int value; } _s_f97b033e_optionalLine;
typedef struct _s_f97b033e_optionalUserData { void* value; } _s_f97b033e_optionalUserData;
typedef struct _s_f97b033e_rteParameters { void* value; } _s_f97b033e_rteParameters;
static inline _s_f97b033e_helperGBuffer _f97b033e_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_f97b033e_helperGBuffer){value}; }
static inline _s_f97b033e_optionalFile _f97b033e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f97b033e_optionalFile){value}; }
static inline _s_f97b033e_optionalLine _f97b033e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f97b033e_optionalLine){value}; }
static inline _s_f97b033e_optionalUserData _f97b033e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f97b033e_optionalUserData){value}; }
static inline _s_f97b033e_rteParameters _f97b033e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f97b033e_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperGBufferGetHeight(_s_f97b033e_helperGBuffer helperGBuffer, _s_f97b033e_optionalFile optionalFile, _s_f97b033e_optionalLine optionalLine, _s_f97b033e_optionalUserData optionalUserData, _s_f97b033e_rteParameters rteParameters) {
  return redRteHelperGBufferGetHeight(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetColorImage redRteHelperGBufferGetColorImage
#define _ebdf8271_helperGBuffer(value) value
#define _ebdf8271_index(value) value
#define _ebdf8271_optionalFile(value) value
#define _ebdf8271_optionalLine(value) value
#define _ebdf8271_optionalUserData(value) value
#define _ebdf8271_rteParameters(value) value
#else
typedef struct _s_ebdf8271_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_ebdf8271_helperGBuffer;
typedef struct _s_ebdf8271_index { unsigned value; } _s_ebdf8271_index;
typedef struct _s_ebdf8271_optionalFile { char* value; } _s_ebdf8271_optionalFile;
typedef struct _s_ebdf8271_optionalLine { int value; } _s_ebdf8271_optionalLine;
typedef struct _s_ebdf8271_optionalUserData { void* value; } _s_ebdf8271_optionalUserData;
typedef struct _s_ebdf8271_rteParameters { void* value; } _s_ebdf8271_rteParameters;
static inline _s_ebdf8271_helperGBuffer _ebdf8271_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_ebdf8271_helperGBuffer){value}; }
static inline _s_ebdf8271_index _ebdf8271_index(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ebdf8271_index){value}; }
static inline _s_ebdf8271_optionalFile _ebdf8271_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ebdf8271_optionalFile){value}; }
static inline _s_ebdf8271_optionalLine _ebdf8271_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ebdf8271_optionalLine){value}; }
static inline _s_ebdf8271_optionalUserData _ebdf8271_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ebdf8271_optionalUserData){value}; }
static inline _s_ebdf8271_rteParameters _ebdf8271_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ebdf8271_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleImage REDGPU_NP_API np_redRteHelperGBufferGetColorImage(_s_ebdf8271_helperGBuffer helperGBuffer, _s_ebdf8271_index index, _s_ebdf8271_optionalFile optionalFile, _s_ebdf8271_optionalLine optionalLine, _s_ebdf8271_optionalUserData optionalUserData, _s_ebdf8271_rteParameters rteParameters) {
  return redRteHelperGBufferGetColorImage(helperGBuffer.value, index.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetDepthImage redRteHelperGBufferGetDepthImage
#define _e104a168_helperGBuffer(value) value
#define _e104a168_optionalFile(value) value
#define _e104a168_optionalLine(value) value
#define _e104a168_optionalUserData(value) value
#define _e104a168_rteParameters(value) value
#else
typedef struct _s_e104a168_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_e104a168_helperGBuffer;
typedef struct _s_e104a168_optionalFile { char* value; } _s_e104a168_optionalFile;
typedef struct _s_e104a168_optionalLine { int value; } _s_e104a168_optionalLine;
typedef struct _s_e104a168_optionalUserData { void* value; } _s_e104a168_optionalUserData;
typedef struct _s_e104a168_rteParameters { void* value; } _s_e104a168_rteParameters;
static inline _s_e104a168_helperGBuffer _e104a168_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_e104a168_helperGBuffer){value}; }
static inline _s_e104a168_optionalFile _e104a168_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e104a168_optionalFile){value}; }
static inline _s_e104a168_optionalLine _e104a168_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e104a168_optionalLine){value}; }
static inline _s_e104a168_optionalUserData _e104a168_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e104a168_optionalUserData){value}; }
static inline _s_e104a168_rteParameters _e104a168_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e104a168_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleImage REDGPU_NP_API np_redRteHelperGBufferGetDepthImage(_s_e104a168_helperGBuffer helperGBuffer, _s_e104a168_optionalFile optionalFile, _s_e104a168_optionalLine optionalLine, _s_e104a168_optionalUserData optionalUserData, _s_e104a168_rteParameters rteParameters) {
  return redRteHelperGBufferGetDepthImage(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetStructMemberTexture redRteHelperGBufferGetStructMemberTexture
#define _ada95724_helperGBuffer(value) value
#define _ada95724_index(value) value
#define _ada95724_outStructMemberTexture(value) value
#define _ada95724_optionalFile(value) value
#define _ada95724_optionalLine(value) value
#define _ada95724_optionalUserData(value) value
#define _ada95724_rteParameters(value) value
#else
typedef struct _s_ada95724_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_ada95724_helperGBuffer;
typedef struct _s_ada95724_index { unsigned value; } _s_ada95724_index;
typedef struct _s_ada95724_outStructMemberTexture { RedStructMemberTexture* value; } _s_ada95724_outStructMemberTexture;
typedef struct _s_ada95724_optionalFile { char* value; } _s_ada95724_optionalFile;
typedef struct _s_ada95724_optionalLine { int value; } _s_ada95724_optionalLine;
typedef struct _s_ada95724_optionalUserData { void* value; } _s_ada95724_optionalUserData;
typedef struct _s_ada95724_rteParameters { void* value; } _s_ada95724_rteParameters;
static inline _s_ada95724_helperGBuffer _ada95724_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_ada95724_helperGBuffer){value}; }
static inline _s_ada95724_index _ada95724_index(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ada95724_index){value}; }
static inline _s_ada95724_outStructMemberTexture _ada95724_outStructMemberTexture(RedStructMemberTexture* value) { return REDGPU_NP_STRUCT_INIT(_s_ada95724_outStructMemberTexture){value}; }
static inline _s_ada95724_optionalFile _ada95724_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ada95724_optionalFile){value}; }
static inline _s_ada95724_optionalLine _ada95724_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ada95724_optionalLine){value}; }
static inline _s_ada95724_optionalUserData _ada95724_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ada95724_optionalUserData){value}; }
static inline _s_ada95724_rteParameters _ada95724_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ada95724_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteHelperGBufferGetStructMemberTexture(_s_ada95724_helperGBuffer helperGBuffer, _s_ada95724_index index, _s_ada95724_outStructMemberTexture outStructMemberTexture, _s_ada95724_optionalFile optionalFile, _s_ada95724_optionalLine optionalLine, _s_ada95724_optionalUserData optionalUserData, _s_ada95724_rteParameters rteParameters) {
  return redRteHelperGBufferGetStructMemberTexture(helperGBuffer.value, index.value, outStructMemberTexture.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetColorTexture redRteHelperGBufferGetColorTexture
#define _09f1d2fb_helperGBuffer(value) value
#define _09f1d2fb_index(value) value
#define _09f1d2fb_optionalFile(value) value
#define _09f1d2fb_optionalLine(value) value
#define _09f1d2fb_optionalUserData(value) value
#define _09f1d2fb_rteParameters(value) value
#else
typedef struct _s_09f1d2fb_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_09f1d2fb_helperGBuffer;
typedef struct _s_09f1d2fb_index { unsigned value; } _s_09f1d2fb_index;
typedef struct _s_09f1d2fb_optionalFile { char* value; } _s_09f1d2fb_optionalFile;
typedef struct _s_09f1d2fb_optionalLine { int value; } _s_09f1d2fb_optionalLine;
typedef struct _s_09f1d2fb_optionalUserData { void* value; } _s_09f1d2fb_optionalUserData;
typedef struct _s_09f1d2fb_rteParameters { void* value; } _s_09f1d2fb_rteParameters;
static inline _s_09f1d2fb_helperGBuffer _09f1d2fb_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_09f1d2fb_helperGBuffer){value}; }
static inline _s_09f1d2fb_index _09f1d2fb_index(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_09f1d2fb_index){value}; }
static inline _s_09f1d2fb_optionalFile _09f1d2fb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_09f1d2fb_optionalFile){value}; }
static inline _s_09f1d2fb_optionalLine _09f1d2fb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_09f1d2fb_optionalLine){value}; }
static inline _s_09f1d2fb_optionalUserData _09f1d2fb_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_09f1d2fb_optionalUserData){value}; }
static inline _s_09f1d2fb_rteParameters _09f1d2fb_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_09f1d2fb_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleTexture REDGPU_NP_API np_redRteHelperGBufferGetColorTexture(_s_09f1d2fb_helperGBuffer helperGBuffer, _s_09f1d2fb_index index, _s_09f1d2fb_optionalFile optionalFile, _s_09f1d2fb_optionalLine optionalLine, _s_09f1d2fb_optionalUserData optionalUserData, _s_09f1d2fb_rteParameters rteParameters) {
  return redRteHelperGBufferGetColorTexture(helperGBuffer.value, index.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetDepthTexture redRteHelperGBufferGetDepthTexture
#define _dca5f16d_helperGBuffer(value) value
#define _dca5f16d_optionalFile(value) value
#define _dca5f16d_optionalLine(value) value
#define _dca5f16d_optionalUserData(value) value
#define _dca5f16d_rteParameters(value) value
#else
typedef struct _s_dca5f16d_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_dca5f16d_helperGBuffer;
typedef struct _s_dca5f16d_optionalFile { char* value; } _s_dca5f16d_optionalFile;
typedef struct _s_dca5f16d_optionalLine { int value; } _s_dca5f16d_optionalLine;
typedef struct _s_dca5f16d_optionalUserData { void* value; } _s_dca5f16d_optionalUserData;
typedef struct _s_dca5f16d_rteParameters { void* value; } _s_dca5f16d_rteParameters;
static inline _s_dca5f16d_helperGBuffer _dca5f16d_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_dca5f16d_helperGBuffer){value}; }
static inline _s_dca5f16d_optionalFile _dca5f16d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_dca5f16d_optionalFile){value}; }
static inline _s_dca5f16d_optionalLine _dca5f16d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_dca5f16d_optionalLine){value}; }
static inline _s_dca5f16d_optionalUserData _dca5f16d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_dca5f16d_optionalUserData){value}; }
static inline _s_dca5f16d_rteParameters _dca5f16d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_dca5f16d_rteParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleTexture REDGPU_NP_API np_redRteHelperGBufferGetDepthTexture(_s_dca5f16d_helperGBuffer helperGBuffer, _s_dca5f16d_optionalFile optionalFile, _s_dca5f16d_optionalLine optionalLine, _s_dca5f16d_optionalUserData optionalUserData, _s_dca5f16d_rteParameters rteParameters) {
  return redRteHelperGBufferGetDepthTexture(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetColorFormat redRteHelperGBufferGetColorFormat
#define _271c8842_helperGBuffer(value) value
#define _271c8842_index(value) value
#define _271c8842_optionalFile(value) value
#define _271c8842_optionalLine(value) value
#define _271c8842_optionalUserData(value) value
#define _271c8842_rteParameters(value) value
#else
typedef struct _s_271c8842_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_271c8842_helperGBuffer;
typedef struct _s_271c8842_index { unsigned value; } _s_271c8842_index;
typedef struct _s_271c8842_optionalFile { char* value; } _s_271c8842_optionalFile;
typedef struct _s_271c8842_optionalLine { int value; } _s_271c8842_optionalLine;
typedef struct _s_271c8842_optionalUserData { void* value; } _s_271c8842_optionalUserData;
typedef struct _s_271c8842_rteParameters { void* value; } _s_271c8842_rteParameters;
static inline _s_271c8842_helperGBuffer _271c8842_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_271c8842_helperGBuffer){value}; }
static inline _s_271c8842_index _271c8842_index(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_271c8842_index){value}; }
static inline _s_271c8842_optionalFile _271c8842_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_271c8842_optionalFile){value}; }
static inline _s_271c8842_optionalLine _271c8842_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_271c8842_optionalLine){value}; }
static inline _s_271c8842_optionalUserData _271c8842_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_271c8842_optionalUserData){value}; }
static inline _s_271c8842_rteParameters _271c8842_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_271c8842_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redRteHelperGBufferGetColorFormat(_s_271c8842_helperGBuffer helperGBuffer, _s_271c8842_index index, _s_271c8842_optionalFile optionalFile, _s_271c8842_optionalLine optionalLine, _s_271c8842_optionalUserData optionalUserData, _s_271c8842_rteParameters rteParameters) {
  return redRteHelperGBufferGetColorFormat(helperGBuffer.value, index.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetDepthFormat redRteHelperGBufferGetDepthFormat
#define _5fca6ef7_helperGBuffer(value) value
#define _5fca6ef7_optionalFile(value) value
#define _5fca6ef7_optionalLine(value) value
#define _5fca6ef7_optionalUserData(value) value
#define _5fca6ef7_rteParameters(value) value
#else
typedef struct _s_5fca6ef7_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_5fca6ef7_helperGBuffer;
typedef struct _s_5fca6ef7_optionalFile { char* value; } _s_5fca6ef7_optionalFile;
typedef struct _s_5fca6ef7_optionalLine { int value; } _s_5fca6ef7_optionalLine;
typedef struct _s_5fca6ef7_optionalUserData { void* value; } _s_5fca6ef7_optionalUserData;
typedef struct _s_5fca6ef7_rteParameters { void* value; } _s_5fca6ef7_rteParameters;
static inline _s_5fca6ef7_helperGBuffer _5fca6ef7_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_5fca6ef7_helperGBuffer){value}; }
static inline _s_5fca6ef7_optionalFile _5fca6ef7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5fca6ef7_optionalFile){value}; }
static inline _s_5fca6ef7_optionalLine _5fca6ef7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5fca6ef7_optionalLine){value}; }
static inline _s_5fca6ef7_optionalUserData _5fca6ef7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5fca6ef7_optionalUserData){value}; }
static inline _s_5fca6ef7_rteParameters _5fca6ef7_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5fca6ef7_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redRteHelperGBufferGetDepthFormat(_s_5fca6ef7_helperGBuffer helperGBuffer, _s_5fca6ef7_optionalFile optionalFile, _s_5fca6ef7_optionalLine optionalLine, _s_5fca6ef7_optionalUserData optionalUserData, _s_5fca6ef7_rteParameters rteParameters) {
  return redRteHelperGBufferGetDepthFormat(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteHelperGBufferGetAspectRatio redRteHelperGBufferGetAspectRatio
#define _8e85170e_helperGBuffer(value) value
#define _8e85170e_optionalFile(value) value
#define _8e85170e_optionalLine(value) value
#define _8e85170e_optionalUserData(value) value
#define _8e85170e_rteParameters(value) value
#else
typedef struct _s_8e85170e_helperGBuffer { RedRteHandleHelperGBuffer value; } _s_8e85170e_helperGBuffer;
typedef struct _s_8e85170e_optionalFile { char* value; } _s_8e85170e_optionalFile;
typedef struct _s_8e85170e_optionalLine { int value; } _s_8e85170e_optionalLine;
typedef struct _s_8e85170e_optionalUserData { void* value; } _s_8e85170e_optionalUserData;
typedef struct _s_8e85170e_rteParameters { void* value; } _s_8e85170e_rteParameters;
static inline _s_8e85170e_helperGBuffer _8e85170e_helperGBuffer(RedRteHandleHelperGBuffer value) { return REDGPU_NP_STRUCT_INIT(_s_8e85170e_helperGBuffer){value}; }
static inline _s_8e85170e_optionalFile _8e85170e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8e85170e_optionalFile){value}; }
static inline _s_8e85170e_optionalLine _8e85170e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8e85170e_optionalLine){value}; }
static inline _s_8e85170e_optionalUserData _8e85170e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8e85170e_optionalUserData){value}; }
static inline _s_8e85170e_rteParameters _8e85170e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8e85170e_rteParameters){value}; }
REDGPU_NP_DECLSPEC float REDGPU_NP_API np_redRteHelperGBufferGetAspectRatio(_s_8e85170e_helperGBuffer helperGBuffer, _s_8e85170e_optionalFile optionalFile, _s_8e85170e_optionalLine optionalLine, _s_8e85170e_optionalUserData optionalUserData, _s_8e85170e_rteParameters rteParameters) {
  return redRteHelperGBufferGetAspectRatio(helperGBuffer.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteGpuWaitIdle redRteGpuWaitIdle
#define _4a43ba0d_rteContext(value) value
#define _4a43ba0d_optionalFile(value) value
#define _4a43ba0d_optionalLine(value) value
#define _4a43ba0d_optionalUserData(value) value
#define _4a43ba0d_rteParameters(value) value
#else
typedef struct _s_4a43ba0d_rteContext { RedRteHandleContext value; } _s_4a43ba0d_rteContext;
typedef struct _s_4a43ba0d_optionalFile { char* value; } _s_4a43ba0d_optionalFile;
typedef struct _s_4a43ba0d_optionalLine { int value; } _s_4a43ba0d_optionalLine;
typedef struct _s_4a43ba0d_optionalUserData { void* value; } _s_4a43ba0d_optionalUserData;
typedef struct _s_4a43ba0d_rteParameters { void* value; } _s_4a43ba0d_rteParameters;
static inline _s_4a43ba0d_rteContext _4a43ba0d_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_4a43ba0d_rteContext){value}; }
static inline _s_4a43ba0d_optionalFile _4a43ba0d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4a43ba0d_optionalFile){value}; }
static inline _s_4a43ba0d_optionalLine _4a43ba0d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4a43ba0d_optionalLine){value}; }
static inline _s_4a43ba0d_optionalUserData _4a43ba0d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4a43ba0d_optionalUserData){value}; }
static inline _s_4a43ba0d_rteParameters _4a43ba0d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4a43ba0d_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteGpuWaitIdle(_s_4a43ba0d_rteContext rteContext, _s_4a43ba0d_optionalFile optionalFile, _s_4a43ba0d_optionalLine optionalLine, _s_4a43ba0d_optionalUserData optionalUserData, _s_4a43ba0d_rteParameters rteParameters) {
  return redRteGpuWaitIdle(rteContext.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteQueueWaitIdle redRteQueueWaitIdle
#define _12aaaecf_rteContext(value) value
#define _12aaaecf_queue(value) value
#define _12aaaecf_optionalFile(value) value
#define _12aaaecf_optionalLine(value) value
#define _12aaaecf_optionalUserData(value) value
#define _12aaaecf_rteParameters(value) value
#else
typedef struct _s_12aaaecf_rteContext { RedRteHandleContext value; } _s_12aaaecf_rteContext;
typedef struct _s_12aaaecf_queue { RedHandleQueue value; } _s_12aaaecf_queue;
typedef struct _s_12aaaecf_optionalFile { char* value; } _s_12aaaecf_optionalFile;
typedef struct _s_12aaaecf_optionalLine { int value; } _s_12aaaecf_optionalLine;
typedef struct _s_12aaaecf_optionalUserData { void* value; } _s_12aaaecf_optionalUserData;
typedef struct _s_12aaaecf_rteParameters { void* value; } _s_12aaaecf_rteParameters;
static inline _s_12aaaecf_rteContext _12aaaecf_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_12aaaecf_rteContext){value}; }
static inline _s_12aaaecf_queue _12aaaecf_queue(RedHandleQueue value) { return REDGPU_NP_STRUCT_INIT(_s_12aaaecf_queue){value}; }
static inline _s_12aaaecf_optionalFile _12aaaecf_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_12aaaecf_optionalFile){value}; }
static inline _s_12aaaecf_optionalLine _12aaaecf_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_12aaaecf_optionalLine){value}; }
static inline _s_12aaaecf_optionalUserData _12aaaecf_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_12aaaecf_optionalUserData){value}; }
static inline _s_12aaaecf_rteParameters _12aaaecf_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_12aaaecf_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteQueueWaitIdle(_s_12aaaecf_rteContext rteContext, _s_12aaaecf_queue queue, _s_12aaaecf_optionalFile optionalFile, _s_12aaaecf_optionalLine optionalLine, _s_12aaaecf_optionalUserData optionalUserData, _s_12aaaecf_rteParameters rteParameters) {
  return redRteQueueWaitIdle(rteContext.value, queue.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteArrayGetMemoryRequirements redRteArrayGetMemoryRequirements
#define _d8a479bf_rteContext(value) value
#define _d8a479bf_inoutArray(value) value
#define _d8a479bf_optionalFile(value) value
#define _d8a479bf_optionalLine(value) value
#define _d8a479bf_optionalUserData(value) value
#define _d8a479bf_rteParameters(value) value
#else
typedef struct _s_d8a479bf_rteContext { RedRteHandleContext value; } _s_d8a479bf_rteContext;
typedef struct _s_d8a479bf_inoutArray { RedArray* value; } _s_d8a479bf_inoutArray;
typedef struct _s_d8a479bf_optionalFile { char* value; } _s_d8a479bf_optionalFile;
typedef struct _s_d8a479bf_optionalLine { int value; } _s_d8a479bf_optionalLine;
typedef struct _s_d8a479bf_optionalUserData { void* value; } _s_d8a479bf_optionalUserData;
typedef struct _s_d8a479bf_rteParameters { void* value; } _s_d8a479bf_rteParameters;
static inline _s_d8a479bf_rteContext _d8a479bf_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_d8a479bf_rteContext){value}; }
static inline _s_d8a479bf_inoutArray _d8a479bf_inoutArray(RedArray* value) { return REDGPU_NP_STRUCT_INIT(_s_d8a479bf_inoutArray){value}; }
static inline _s_d8a479bf_optionalFile _d8a479bf_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d8a479bf_optionalFile){value}; }
static inline _s_d8a479bf_optionalLine _d8a479bf_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d8a479bf_optionalLine){value}; }
static inline _s_d8a479bf_optionalUserData _d8a479bf_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d8a479bf_optionalUserData){value}; }
static inline _s_d8a479bf_rteParameters _d8a479bf_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d8a479bf_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteArrayGetMemoryRequirements(_s_d8a479bf_rteContext rteContext, _s_d8a479bf_inoutArray inoutArray, _s_d8a479bf_optionalFile optionalFile, _s_d8a479bf_optionalLine optionalLine, _s_d8a479bf_optionalUserData optionalUserData, _s_d8a479bf_rteParameters rteParameters) {
  return redRteArrayGetMemoryRequirements(rteContext.value, inoutArray.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteImageGetMemoryRequirements redRteImageGetMemoryRequirements
#define _7348a47e_rteContext(value) value
#define _7348a47e_inoutImage(value) value
#define _7348a47e_optionalFile(value) value
#define _7348a47e_optionalLine(value) value
#define _7348a47e_optionalUserData(value) value
#define _7348a47e_rteParameters(value) value
#else
typedef struct _s_7348a47e_rteContext { RedRteHandleContext value; } _s_7348a47e_rteContext;
typedef struct _s_7348a47e_inoutImage { RedImage* value; } _s_7348a47e_inoutImage;
typedef struct _s_7348a47e_optionalFile { char* value; } _s_7348a47e_optionalFile;
typedef struct _s_7348a47e_optionalLine { int value; } _s_7348a47e_optionalLine;
typedef struct _s_7348a47e_optionalUserData { void* value; } _s_7348a47e_optionalUserData;
typedef struct _s_7348a47e_rteParameters { void* value; } _s_7348a47e_rteParameters;
static inline _s_7348a47e_rteContext _7348a47e_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_7348a47e_rteContext){value}; }
static inline _s_7348a47e_inoutImage _7348a47e_inoutImage(RedImage* value) { return REDGPU_NP_STRUCT_INIT(_s_7348a47e_inoutImage){value}; }
static inline _s_7348a47e_optionalFile _7348a47e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7348a47e_optionalFile){value}; }
static inline _s_7348a47e_optionalLine _7348a47e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7348a47e_optionalLine){value}; }
static inline _s_7348a47e_optionalUserData _7348a47e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7348a47e_optionalUserData){value}; }
static inline _s_7348a47e_rteParameters _7348a47e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7348a47e_rteParameters){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteImageGetMemoryRequirements(_s_7348a47e_rteContext rteContext, _s_7348a47e_inoutImage inoutImage, _s_7348a47e_optionalFile optionalFile, _s_7348a47e_optionalLine optionalLine, _s_7348a47e_optionalUserData optionalUserData, _s_7348a47e_rteParameters rteParameters) {
  return redRteImageGetMemoryRequirements(rteContext.value, inoutImage.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redRteCallUsageAliasOrderBarrier redRteCallUsageAliasOrderBarrier
#define _eb195267_calls(value) value
#define _eb195267_rteContext(value) value
#define _eb195267_arrayUsagesCount(value) value
#define _eb195267_arrayUsages(value) value
#define _eb195267_imageUsagesCount(value) value
#define _eb195267_imageUsages(value) value
#define _eb195267_aliasesCount(value) value
#define _eb195267_aliases(value) value
#define _eb195267_ordersCount(value) value
#define _eb195267_orders(value) value
#define _eb195267_dependencyFlags(value) value
#else
typedef struct _s_eb195267_calls { RedHandleCalls value; } _s_eb195267_calls;
typedef struct _s_eb195267_rteContext { RedRteHandleContext value; } _s_eb195267_rteContext;
typedef struct _s_eb195267_arrayUsagesCount { unsigned value; } _s_eb195267_arrayUsagesCount;
typedef struct _s_eb195267_arrayUsages { RedRteUsageArray* value; } _s_eb195267_arrayUsages;
typedef struct _s_eb195267_imageUsagesCount { unsigned value; } _s_eb195267_imageUsagesCount;
typedef struct _s_eb195267_imageUsages { RedRteUsageImage* value; } _s_eb195267_imageUsages;
typedef struct _s_eb195267_aliasesCount { unsigned value; } _s_eb195267_aliasesCount;
typedef struct _s_eb195267_aliases { RedAlias* value; } _s_eb195267_aliases;
typedef struct _s_eb195267_ordersCount { unsigned value; } _s_eb195267_ordersCount;
typedef struct _s_eb195267_orders { RedOrder* value; } _s_eb195267_orders;
typedef struct _s_eb195267_dependencyFlags { unsigned value; } _s_eb195267_dependencyFlags;
static inline _s_eb195267_calls _eb195267_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_eb195267_calls){value}; }
static inline _s_eb195267_rteContext _eb195267_rteContext(RedRteHandleContext value) { return REDGPU_NP_STRUCT_INIT(_s_eb195267_rteContext){value}; }
static inline _s_eb195267_arrayUsagesCount _eb195267_arrayUsagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_eb195267_arrayUsagesCount){value}; }
static inline _s_eb195267_arrayUsages _eb195267_arrayUsages(RedRteUsageArray* value) { return REDGPU_NP_STRUCT_INIT(_s_eb195267_arrayUsages){value}; }
static inline _s_eb195267_imageUsagesCount _eb195267_imageUsagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_eb195267_imageUsagesCount){value}; }
static inline _s_eb195267_imageUsages _eb195267_imageUsages(RedRteUsageImage* value) { return REDGPU_NP_STRUCT_INIT(_s_eb195267_imageUsages){value}; }
static inline _s_eb195267_aliasesCount _eb195267_aliasesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_eb195267_aliasesCount){value}; }
static inline _s_eb195267_aliases _eb195267_aliases(RedAlias* value) { return REDGPU_NP_STRUCT_INIT(_s_eb195267_aliases){value}; }
static inline _s_eb195267_ordersCount _eb195267_ordersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_eb195267_ordersCount){value}; }
static inline _s_eb195267_orders _eb195267_orders(RedOrder* value) { return REDGPU_NP_STRUCT_INIT(_s_eb195267_orders){value}; }
static inline _s_eb195267_dependencyFlags _eb195267_dependencyFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_eb195267_dependencyFlags){value}; }
REDGPU_NP_DECLSPEC int64_t REDGPU_NP_API np_redRteCallUsageAliasOrderBarrier(_s_eb195267_calls calls, _s_eb195267_rteContext rteContext, _s_eb195267_arrayUsagesCount arrayUsagesCount, _s_eb195267_arrayUsages arrayUsages, _s_eb195267_imageUsagesCount imageUsagesCount, _s_eb195267_imageUsages imageUsages, _s_eb195267_aliasesCount aliasesCount, _s_eb195267_aliases aliases, _s_eb195267_ordersCount ordersCount, _s_eb195267_orders orders, _s_eb195267_dependencyFlags dependencyFlags) {
  return redRteCallUsageAliasOrderBarrier(calls.value, rteContext.value, arrayUsagesCount.value, arrayUsages.value, imageUsagesCount.value, imageUsages.value, aliasesCount.value, aliases.value, ordersCount.value, orders.value, dependencyFlags.value);
}
#endif

