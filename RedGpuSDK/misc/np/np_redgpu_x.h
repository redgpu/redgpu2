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
#define np_redXMemoryCallbackBudgetChangeRegister redXMemoryCallbackBudgetChangeRegister
#define _d1c66028_context(value) value
#define _d1c66028_gpu(value) value
#define _d1c66028_eventHandle(value) value
#define _d1c66028_outMemoryCallbackBudgetChange(value) value
#define _d1c66028_outStatuses(value) value
#define _d1c66028_optionalFile(value) value
#define _d1c66028_optionalLine(value) value
#define _d1c66028_optionalUserData(value) value
#else
typedef struct _s_d1c66028_context { RedContext value; } _s_d1c66028_context;
typedef struct _s_d1c66028_gpu { RedHandleGpu value; } _s_d1c66028_gpu;
typedef struct _s_d1c66028_eventHandle { void* value; } _s_d1c66028_eventHandle;
typedef struct _s_d1c66028_outMemoryCallbackBudgetChange { RedXHandleMemoryCallbackBudgetChange* value; } _s_d1c66028_outMemoryCallbackBudgetChange;
typedef struct _s_d1c66028_outStatuses { RedStatuses* value; } _s_d1c66028_outStatuses;
typedef struct _s_d1c66028_optionalFile { char* value; } _s_d1c66028_optionalFile;
typedef struct _s_d1c66028_optionalLine { int value; } _s_d1c66028_optionalLine;
typedef struct _s_d1c66028_optionalUserData { void* value; } _s_d1c66028_optionalUserData;
static inline _s_d1c66028_context _d1c66028_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_d1c66028_context){value}; }
static inline _s_d1c66028_gpu _d1c66028_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_d1c66028_gpu){value}; }
static inline _s_d1c66028_eventHandle _d1c66028_eventHandle(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d1c66028_eventHandle){value}; }
static inline _s_d1c66028_outMemoryCallbackBudgetChange _d1c66028_outMemoryCallbackBudgetChange(RedXHandleMemoryCallbackBudgetChange* value) { return REDGPU_NP_STRUCT_INIT(_s_d1c66028_outMemoryCallbackBudgetChange){value}; }
static inline _s_d1c66028_outStatuses _d1c66028_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_d1c66028_outStatuses){value}; }
static inline _s_d1c66028_optionalFile _d1c66028_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d1c66028_optionalFile){value}; }
static inline _s_d1c66028_optionalLine _d1c66028_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d1c66028_optionalLine){value}; }
static inline _s_d1c66028_optionalUserData _d1c66028_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d1c66028_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXMemoryCallbackBudgetChangeRegister(_s_d1c66028_context context, _s_d1c66028_gpu gpu, _s_d1c66028_eventHandle eventHandle, _s_d1c66028_outMemoryCallbackBudgetChange outMemoryCallbackBudgetChange, _s_d1c66028_outStatuses outStatuses, _s_d1c66028_optionalFile optionalFile, _s_d1c66028_optionalLine optionalLine, _s_d1c66028_optionalUserData optionalUserData) {
  redXMemoryCallbackBudgetChangeRegister(context.value, gpu.value, eventHandle.value, outMemoryCallbackBudgetChange.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXMemoryCallbackBudgetChangeUnregister redXMemoryCallbackBudgetChangeUnregister
#define _56a79324_context(value) value
#define _56a79324_gpu(value) value
#define _56a79324_memoryCallbackBudgetChange(value) value
#define _56a79324_optionalFile(value) value
#define _56a79324_optionalLine(value) value
#define _56a79324_optionalUserData(value) value
#else
typedef struct _s_56a79324_context { RedContext value; } _s_56a79324_context;
typedef struct _s_56a79324_gpu { RedHandleGpu value; } _s_56a79324_gpu;
typedef struct _s_56a79324_memoryCallbackBudgetChange { RedXHandleMemoryCallbackBudgetChange value; } _s_56a79324_memoryCallbackBudgetChange;
typedef struct _s_56a79324_optionalFile { char* value; } _s_56a79324_optionalFile;
typedef struct _s_56a79324_optionalLine { int value; } _s_56a79324_optionalLine;
typedef struct _s_56a79324_optionalUserData { void* value; } _s_56a79324_optionalUserData;
static inline _s_56a79324_context _56a79324_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_56a79324_context){value}; }
static inline _s_56a79324_gpu _56a79324_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_56a79324_gpu){value}; }
static inline _s_56a79324_memoryCallbackBudgetChange _56a79324_memoryCallbackBudgetChange(RedXHandleMemoryCallbackBudgetChange value) { return REDGPU_NP_STRUCT_INIT(_s_56a79324_memoryCallbackBudgetChange){value}; }
static inline _s_56a79324_optionalFile _56a79324_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_56a79324_optionalFile){value}; }
static inline _s_56a79324_optionalLine _56a79324_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_56a79324_optionalLine){value}; }
static inline _s_56a79324_optionalUserData _56a79324_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_56a79324_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXMemoryCallbackBudgetChangeUnregister(_s_56a79324_context context, _s_56a79324_gpu gpu, _s_56a79324_memoryCallbackBudgetChange memoryCallbackBudgetChange, _s_56a79324_optionalFile optionalFile, _s_56a79324_optionalLine optionalLine, _s_56a79324_optionalUserData optionalUserData) {
  redXMemoryCallbackBudgetChangeUnregister(context.value, gpu.value, memoryCallbackBudgetChange.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXMemoryReserve redXMemoryReserve
#define _11967dfc_context(value) value
#define _11967dfc_gpu(value) value
#define _11967dfc_sharedMemory(value) value
#define _11967dfc_bytesCount(value) value
#define _11967dfc_outStatuses(value) value
#define _11967dfc_optionalFile(value) value
#define _11967dfc_optionalLine(value) value
#define _11967dfc_optionalUserData(value) value
#else
typedef struct _s_11967dfc_context { RedContext value; } _s_11967dfc_context;
typedef struct _s_11967dfc_gpu { RedHandleGpu value; } _s_11967dfc_gpu;
typedef struct _s_11967dfc_sharedMemory { RedBool32 value; } _s_11967dfc_sharedMemory;
typedef struct _s_11967dfc_bytesCount { uint64_t value; } _s_11967dfc_bytesCount;
typedef struct _s_11967dfc_outStatuses { RedStatuses* value; } _s_11967dfc_outStatuses;
typedef struct _s_11967dfc_optionalFile { char* value; } _s_11967dfc_optionalFile;
typedef struct _s_11967dfc_optionalLine { int value; } _s_11967dfc_optionalLine;
typedef struct _s_11967dfc_optionalUserData { void* value; } _s_11967dfc_optionalUserData;
static inline _s_11967dfc_context _11967dfc_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_11967dfc_context){value}; }
static inline _s_11967dfc_gpu _11967dfc_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_11967dfc_gpu){value}; }
static inline _s_11967dfc_sharedMemory _11967dfc_sharedMemory(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_11967dfc_sharedMemory){value}; }
static inline _s_11967dfc_bytesCount _11967dfc_bytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_11967dfc_bytesCount){value}; }
static inline _s_11967dfc_outStatuses _11967dfc_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_11967dfc_outStatuses){value}; }
static inline _s_11967dfc_optionalFile _11967dfc_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_11967dfc_optionalFile){value}; }
static inline _s_11967dfc_optionalLine _11967dfc_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_11967dfc_optionalLine){value}; }
static inline _s_11967dfc_optionalUserData _11967dfc_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_11967dfc_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXMemoryReserve(_s_11967dfc_context context, _s_11967dfc_gpu gpu, _s_11967dfc_sharedMemory sharedMemory, _s_11967dfc_bytesCount bytesCount, _s_11967dfc_outStatuses outStatuses, _s_11967dfc_optionalFile optionalFile, _s_11967dfc_optionalLine optionalLine, _s_11967dfc_optionalUserData optionalUserData) {
  redXMemoryReserve(context.value, gpu.value, sharedMemory.value, bytesCount.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetMemoryAddressArray redXGetMemoryAddressArray
#define _c3a4a9ac_context(value) value
#define _c3a4a9ac_gpu(value) value
#define _c3a4a9ac_array(value) value
#else
typedef struct _s_c3a4a9ac_context { RedContext value; } _s_c3a4a9ac_context;
typedef struct _s_c3a4a9ac_gpu { RedHandleGpu value; } _s_c3a4a9ac_gpu;
typedef struct _s_c3a4a9ac_array { RedHandleArray value; } _s_c3a4a9ac_array;
static inline _s_c3a4a9ac_context _c3a4a9ac_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_c3a4a9ac_context){value}; }
static inline _s_c3a4a9ac_gpu _c3a4a9ac_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_c3a4a9ac_gpu){value}; }
static inline _s_c3a4a9ac_array _c3a4a9ac_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_c3a4a9ac_array){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redXGetMemoryAddressArray(_s_c3a4a9ac_context context, _s_c3a4a9ac_gpu gpu, _s_c3a4a9ac_array array) {
  return redXGetMemoryAddressArray(context.value, gpu.value, array.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetMemoryAddressSampler redXGetMemoryAddressSampler
#define _5f0744a2_context(value) value
#define _5f0744a2_gpu(value) value
#define _5f0744a2_sampler(value) value
#else
typedef struct _s_5f0744a2_context { RedContext value; } _s_5f0744a2_context;
typedef struct _s_5f0744a2_gpu { RedHandleGpu value; } _s_5f0744a2_gpu;
typedef struct _s_5f0744a2_sampler { RedHandleSampler value; } _s_5f0744a2_sampler;
static inline _s_5f0744a2_context _5f0744a2_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_5f0744a2_context){value}; }
static inline _s_5f0744a2_gpu _5f0744a2_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_5f0744a2_gpu){value}; }
static inline _s_5f0744a2_sampler _5f0744a2_sampler(RedHandleSampler value) { return REDGPU_NP_STRUCT_INIT(_s_5f0744a2_sampler){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redXGetMemoryAddressSampler(_s_5f0744a2_context context, _s_5f0744a2_gpu gpu, _s_5f0744a2_sampler sampler) {
  return redXGetMemoryAddressSampler(context.value, gpu.value, sampler.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetMemoryAddressTextureRO redXGetMemoryAddressTextureRO
#define _fd279291_context(value) value
#define _fd279291_gpu(value) value
#define _fd279291_texture(value) value
#else
typedef struct _s_fd279291_context { RedContext value; } _s_fd279291_context;
typedef struct _s_fd279291_gpu { RedHandleGpu value; } _s_fd279291_gpu;
typedef struct _s_fd279291_texture { RedHandleTexture value; } _s_fd279291_texture;
static inline _s_fd279291_context _fd279291_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_fd279291_context){value}; }
static inline _s_fd279291_gpu _fd279291_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_fd279291_gpu){value}; }
static inline _s_fd279291_texture _fd279291_texture(RedHandleTexture value) { return REDGPU_NP_STRUCT_INIT(_s_fd279291_texture){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redXGetMemoryAddressTextureRO(_s_fd279291_context context, _s_fd279291_gpu gpu, _s_fd279291_texture texture) {
  return redXGetMemoryAddressTextureRO(context.value, gpu.value, texture.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetMemoryAddressTextureRW redXGetMemoryAddressTextureRW
#define _09e23832_context(value) value
#define _09e23832_gpu(value) value
#define _09e23832_texture(value) value
#else
typedef struct _s_09e23832_context { RedContext value; } _s_09e23832_context;
typedef struct _s_09e23832_gpu { RedHandleGpu value; } _s_09e23832_gpu;
typedef struct _s_09e23832_texture { RedHandleTexture value; } _s_09e23832_texture;
static inline _s_09e23832_context _09e23832_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_09e23832_context){value}; }
static inline _s_09e23832_gpu _09e23832_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_09e23832_gpu){value}; }
static inline _s_09e23832_texture _09e23832_texture(RedHandleTexture value) { return REDGPU_NP_STRUCT_INIT(_s_09e23832_texture){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redXGetMemoryAddressTextureRW(_s_09e23832_context context, _s_09e23832_gpu gpu, _s_09e23832_texture texture) {
  return redXGetMemoryAddressTextureRW(context.value, gpu.value, texture.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetMemoryAddressStructMember redXGetMemoryAddressStructMember
#define _3519c0ae_context(value) value
#define _3519c0ae_gpu(value) value
#define _3519c0ae_structsMemory(value) value
#define _3519c0ae_structMemberIndex(value) value
#else
typedef struct _s_3519c0ae_context { RedContext value; } _s_3519c0ae_context;
typedef struct _s_3519c0ae_gpu { RedHandleGpu value; } _s_3519c0ae_gpu;
typedef struct _s_3519c0ae_structsMemory { RedHandleStructsMemory value; } _s_3519c0ae_structsMemory;
typedef struct _s_3519c0ae_structMemberIndex { unsigned value; } _s_3519c0ae_structMemberIndex;
static inline _s_3519c0ae_context _3519c0ae_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_3519c0ae_context){value}; }
static inline _s_3519c0ae_gpu _3519c0ae_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_3519c0ae_gpu){value}; }
static inline _s_3519c0ae_structsMemory _3519c0ae_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_3519c0ae_structsMemory){value}; }
static inline _s_3519c0ae_structMemberIndex _3519c0ae_structMemberIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3519c0ae_structMemberIndex){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redXGetMemoryAddressStructMember(_s_3519c0ae_context context, _s_3519c0ae_gpu gpu, _s_3519c0ae_structsMemory structsMemory, _s_3519c0ae_structMemberIndex structMemberIndex) {
  return redXGetMemoryAddressStructMember(context.value, gpu.value, structsMemory.value, structMemberIndex.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXStructsMemorySet redXStructsMemorySet
#define _63008855_context(value) value
#define _63008855_gpu(value) value
#define _63008855_copyingSamplers(value) value
#define _63008855_sourceCopiesCount(value) value
#define _63008855_sourceCopiesAddressFirst(value) value
#define _63008855_sourceCopiesAddressCount(value) value
#define _63008855_targetCopiesCount(value) value
#define _63008855_targetCopiesAddressFirst(value) value
#define _63008855_targetCopiesAddressCount(value) value
#define _63008855_outStatuses(value) value
#define _63008855_optionalFile(value) value
#define _63008855_optionalLine(value) value
#define _63008855_optionalUserData(value) value
#else
typedef struct _s_63008855_context { RedContext value; } _s_63008855_context;
typedef struct _s_63008855_gpu { RedHandleGpu value; } _s_63008855_gpu;
typedef struct _s_63008855_copyingSamplers { RedBool32 value; } _s_63008855_copyingSamplers;
typedef struct _s_63008855_sourceCopiesCount { unsigned value; } _s_63008855_sourceCopiesCount;
typedef struct _s_63008855_sourceCopiesAddressFirst { RedXMemoryAddress* value; } _s_63008855_sourceCopiesAddressFirst;
typedef struct _s_63008855_sourceCopiesAddressCount { unsigned* value; } _s_63008855_sourceCopiesAddressCount;
typedef struct _s_63008855_targetCopiesCount { unsigned value; } _s_63008855_targetCopiesCount;
typedef struct _s_63008855_targetCopiesAddressFirst { RedXMemoryAddress* value; } _s_63008855_targetCopiesAddressFirst;
typedef struct _s_63008855_targetCopiesAddressCount { unsigned* value; } _s_63008855_targetCopiesAddressCount;
typedef struct _s_63008855_outStatuses { RedStatuses* value; } _s_63008855_outStatuses;
typedef struct _s_63008855_optionalFile { char* value; } _s_63008855_optionalFile;
typedef struct _s_63008855_optionalLine { int value; } _s_63008855_optionalLine;
typedef struct _s_63008855_optionalUserData { void* value; } _s_63008855_optionalUserData;
static inline _s_63008855_context _63008855_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_context){value}; }
static inline _s_63008855_gpu _63008855_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_gpu){value}; }
static inline _s_63008855_copyingSamplers _63008855_copyingSamplers(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_copyingSamplers){value}; }
static inline _s_63008855_sourceCopiesCount _63008855_sourceCopiesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_sourceCopiesCount){value}; }
static inline _s_63008855_sourceCopiesAddressFirst _63008855_sourceCopiesAddressFirst(RedXMemoryAddress* value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_sourceCopiesAddressFirst){value}; }
static inline _s_63008855_sourceCopiesAddressCount _63008855_sourceCopiesAddressCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_sourceCopiesAddressCount){value}; }
static inline _s_63008855_targetCopiesCount _63008855_targetCopiesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_targetCopiesCount){value}; }
static inline _s_63008855_targetCopiesAddressFirst _63008855_targetCopiesAddressFirst(RedXMemoryAddress* value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_targetCopiesAddressFirst){value}; }
static inline _s_63008855_targetCopiesAddressCount _63008855_targetCopiesAddressCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_targetCopiesAddressCount){value}; }
static inline _s_63008855_outStatuses _63008855_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_outStatuses){value}; }
static inline _s_63008855_optionalFile _63008855_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_optionalFile){value}; }
static inline _s_63008855_optionalLine _63008855_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_optionalLine){value}; }
static inline _s_63008855_optionalUserData _63008855_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_63008855_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXStructsMemorySet(_s_63008855_context context, _s_63008855_gpu gpu, _s_63008855_copyingSamplers copyingSamplers, _s_63008855_sourceCopiesCount sourceCopiesCount, _s_63008855_sourceCopiesAddressFirst sourceCopiesAddressFirst, _s_63008855_sourceCopiesAddressCount sourceCopiesAddressCount, _s_63008855_targetCopiesCount targetCopiesCount, _s_63008855_targetCopiesAddressFirst targetCopiesAddressFirst, _s_63008855_targetCopiesAddressCount targetCopiesAddressCount, _s_63008855_outStatuses outStatuses, _s_63008855_optionalFile optionalFile, _s_63008855_optionalLine optionalLine, _s_63008855_optionalUserData optionalUserData) {
  redXStructsMemorySet(context.value, gpu.value, copyingSamplers.value, sourceCopiesCount.value, sourceCopiesAddressFirst.value, sourceCopiesAddressCount.value, targetCopiesCount.value, targetCopiesAddressFirst.value, targetCopiesAddressCount.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetHandleStruct redXGetHandleStruct
#define _cc2292cb_context(value) value
#define _cc2292cb_gpu(value) value
#define _cc2292cb_structsMemory(value) value
#define _cc2292cb_structMemberIndex(value) value
#else
typedef struct _s_cc2292cb_context { RedContext value; } _s_cc2292cb_context;
typedef struct _s_cc2292cb_gpu { RedHandleGpu value; } _s_cc2292cb_gpu;
typedef struct _s_cc2292cb_structsMemory { RedHandleStructsMemory value; } _s_cc2292cb_structsMemory;
typedef struct _s_cc2292cb_structMemberIndex { unsigned value; } _s_cc2292cb_structMemberIndex;
static inline _s_cc2292cb_context _cc2292cb_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_cc2292cb_context){value}; }
static inline _s_cc2292cb_gpu _cc2292cb_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_cc2292cb_gpu){value}; }
static inline _s_cc2292cb_structsMemory _cc2292cb_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_cc2292cb_structsMemory){value}; }
static inline _s_cc2292cb_structMemberIndex _cc2292cb_structMemberIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cc2292cb_structMemberIndex){value}; }
REDGPU_NP_DECLSPEC RedHandleStruct REDGPU_NP_API np_redXGetHandleStruct(_s_cc2292cb_context context, _s_cc2292cb_gpu gpu, _s_cc2292cb_structsMemory structsMemory, _s_cc2292cb_structMemberIndex structMemberIndex) {
  return redXGetHandleStruct(context.value, gpu.value, structsMemory.value, structMemberIndex.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCreateQueue redXCreateQueue
#define _cc3b86d6_context(value) value
#define _cc3b86d6_gpu(value) value
#define _cc3b86d6_handleName(value) value
#define _cc3b86d6_canCopy(value) value
#define _cc3b86d6_canDraw(value) value
#define _cc3b86d6_canCompute(value) value
#define _cc3b86d6_priority(value) value
#define _cc3b86d6_disableGpuTimeout(value) value
#define _cc3b86d6_outStatuses(value) value
#define _cc3b86d6_optionalFile(value) value
#define _cc3b86d6_optionalLine(value) value
#define _cc3b86d6_optionalUserData(value) value
#else
typedef struct _s_cc3b86d6_context { RedContext value; } _s_cc3b86d6_context;
typedef struct _s_cc3b86d6_gpu { RedHandleGpu value; } _s_cc3b86d6_gpu;
typedef struct _s_cc3b86d6_handleName { char* value; } _s_cc3b86d6_handleName;
typedef struct _s_cc3b86d6_canCopy { RedBool32 value; } _s_cc3b86d6_canCopy;
typedef struct _s_cc3b86d6_canDraw { RedBool32 value; } _s_cc3b86d6_canDraw;
typedef struct _s_cc3b86d6_canCompute { RedBool32 value; } _s_cc3b86d6_canCompute;
typedef struct _s_cc3b86d6_priority { unsigned value; } _s_cc3b86d6_priority;
typedef struct _s_cc3b86d6_disableGpuTimeout { RedBool32 value; } _s_cc3b86d6_disableGpuTimeout;
typedef struct _s_cc3b86d6_outStatuses { RedStatuses* value; } _s_cc3b86d6_outStatuses;
typedef struct _s_cc3b86d6_optionalFile { char* value; } _s_cc3b86d6_optionalFile;
typedef struct _s_cc3b86d6_optionalLine { int value; } _s_cc3b86d6_optionalLine;
typedef struct _s_cc3b86d6_optionalUserData { void* value; } _s_cc3b86d6_optionalUserData;
static inline _s_cc3b86d6_context _cc3b86d6_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_cc3b86d6_context){value}; }
static inline _s_cc3b86d6_gpu _cc3b86d6_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_cc3b86d6_gpu){value}; }
static inline _s_cc3b86d6_handleName _cc3b86d6_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cc3b86d6_handleName){value}; }
static inline _s_cc3b86d6_canCopy _cc3b86d6_canCopy(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_cc3b86d6_canCopy){value}; }
static inline _s_cc3b86d6_canDraw _cc3b86d6_canDraw(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_cc3b86d6_canDraw){value}; }
static inline _s_cc3b86d6_canCompute _cc3b86d6_canCompute(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_cc3b86d6_canCompute){value}; }
static inline _s_cc3b86d6_priority _cc3b86d6_priority(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cc3b86d6_priority){value}; }
static inline _s_cc3b86d6_disableGpuTimeout _cc3b86d6_disableGpuTimeout(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_cc3b86d6_disableGpuTimeout){value}; }
static inline _s_cc3b86d6_outStatuses _cc3b86d6_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_cc3b86d6_outStatuses){value}; }
static inline _s_cc3b86d6_optionalFile _cc3b86d6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cc3b86d6_optionalFile){value}; }
static inline _s_cc3b86d6_optionalLine _cc3b86d6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cc3b86d6_optionalLine){value}; }
static inline _s_cc3b86d6_optionalUserData _cc3b86d6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cc3b86d6_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCreateQueue(_s_cc3b86d6_context context, _s_cc3b86d6_gpu gpu, _s_cc3b86d6_handleName handleName, _s_cc3b86d6_canCopy canCopy, _s_cc3b86d6_canDraw canDraw, _s_cc3b86d6_canCompute canCompute, _s_cc3b86d6_priority priority, _s_cc3b86d6_disableGpuTimeout disableGpuTimeout, _s_cc3b86d6_outStatuses outStatuses, _s_cc3b86d6_optionalFile optionalFile, _s_cc3b86d6_optionalLine optionalLine, _s_cc3b86d6_optionalUserData optionalUserData) {
  redXCreateQueue(context.value, gpu.value, handleName.value, canCopy.value, canDraw.value, canCompute.value, priority.value, disableGpuTimeout.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCreateImage redXCreateImage
#define _033c3ca1_context(value) value
#define _033c3ca1_gpu(value) value
#define _033c3ca1_handleName(value) value
#define _033c3ca1_dimensions(value) value
#define _033c3ca1_format(value) value
#define _033c3ca1_xformat(value) value
#define _033c3ca1_width(value) value
#define _033c3ca1_height(value) value
#define _033c3ca1_depth(value) value
#define _033c3ca1_levelsCount(value) value
#define _033c3ca1_layersCount(value) value
#define _033c3ca1_multisampleCount(value) value
#define _033c3ca1_restrictToAccess(value) value
#define _033c3ca1_initialAccess(value) value
#define _033c3ca1_initialQueueFamilyIndex(value) value
#define _033c3ca1_dedicate(value) value
#define _033c3ca1_outImage(value) value
#define _033c3ca1_outStatuses(value) value
#define _033c3ca1_optionalFile(value) value
#define _033c3ca1_optionalLine(value) value
#define _033c3ca1_optionalUserData(value) value
#else
typedef struct _s_033c3ca1_context { RedContext value; } _s_033c3ca1_context;
typedef struct _s_033c3ca1_gpu { RedHandleGpu value; } _s_033c3ca1_gpu;
typedef struct _s_033c3ca1_handleName { char* value; } _s_033c3ca1_handleName;
typedef struct _s_033c3ca1_dimensions { RedImageDimensions value; } _s_033c3ca1_dimensions;
typedef struct _s_033c3ca1_format { RedFormat value; } _s_033c3ca1_format;
typedef struct _s_033c3ca1_xformat { unsigned value; } _s_033c3ca1_xformat;
typedef struct _s_033c3ca1_width { unsigned value; } _s_033c3ca1_width;
typedef struct _s_033c3ca1_height { unsigned value; } _s_033c3ca1_height;
typedef struct _s_033c3ca1_depth { unsigned value; } _s_033c3ca1_depth;
typedef struct _s_033c3ca1_levelsCount { unsigned value; } _s_033c3ca1_levelsCount;
typedef struct _s_033c3ca1_layersCount { unsigned value; } _s_033c3ca1_layersCount;
typedef struct _s_033c3ca1_multisampleCount { RedMultisampleCountBitflag value; } _s_033c3ca1_multisampleCount;
typedef struct _s_033c3ca1_restrictToAccess { RedAccessBitflags value; } _s_033c3ca1_restrictToAccess;
typedef struct _s_033c3ca1_initialAccess { RedAccessBitflags value; } _s_033c3ca1_initialAccess;
typedef struct _s_033c3ca1_initialQueueFamilyIndex { unsigned value; } _s_033c3ca1_initialQueueFamilyIndex;
typedef struct _s_033c3ca1_dedicate { RedBool32 value; } _s_033c3ca1_dedicate;
typedef struct _s_033c3ca1_outImage { RedImage* value; } _s_033c3ca1_outImage;
typedef struct _s_033c3ca1_outStatuses { RedStatuses* value; } _s_033c3ca1_outStatuses;
typedef struct _s_033c3ca1_optionalFile { char* value; } _s_033c3ca1_optionalFile;
typedef struct _s_033c3ca1_optionalLine { int value; } _s_033c3ca1_optionalLine;
typedef struct _s_033c3ca1_optionalUserData { void* value; } _s_033c3ca1_optionalUserData;
static inline _s_033c3ca1_context _033c3ca1_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_context){value}; }
static inline _s_033c3ca1_gpu _033c3ca1_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_gpu){value}; }
static inline _s_033c3ca1_handleName _033c3ca1_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_handleName){value}; }
static inline _s_033c3ca1_dimensions _033c3ca1_dimensions(RedImageDimensions value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_dimensions){value}; }
static inline _s_033c3ca1_format _033c3ca1_format(RedFormat value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_format){value}; }
static inline _s_033c3ca1_xformat _033c3ca1_xformat(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_xformat){value}; }
static inline _s_033c3ca1_width _033c3ca1_width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_width){value}; }
static inline _s_033c3ca1_height _033c3ca1_height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_height){value}; }
static inline _s_033c3ca1_depth _033c3ca1_depth(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_depth){value}; }
static inline _s_033c3ca1_levelsCount _033c3ca1_levelsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_levelsCount){value}; }
static inline _s_033c3ca1_layersCount _033c3ca1_layersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_layersCount){value}; }
static inline _s_033c3ca1_multisampleCount _033c3ca1_multisampleCount(RedMultisampleCountBitflag value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_multisampleCount){value}; }
static inline _s_033c3ca1_restrictToAccess _033c3ca1_restrictToAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_restrictToAccess){value}; }
static inline _s_033c3ca1_initialAccess _033c3ca1_initialAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_initialAccess){value}; }
static inline _s_033c3ca1_initialQueueFamilyIndex _033c3ca1_initialQueueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_initialQueueFamilyIndex){value}; }
static inline _s_033c3ca1_dedicate _033c3ca1_dedicate(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_dedicate){value}; }
static inline _s_033c3ca1_outImage _033c3ca1_outImage(RedImage* value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_outImage){value}; }
static inline _s_033c3ca1_outStatuses _033c3ca1_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_outStatuses){value}; }
static inline _s_033c3ca1_optionalFile _033c3ca1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_optionalFile){value}; }
static inline _s_033c3ca1_optionalLine _033c3ca1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_optionalLine){value}; }
static inline _s_033c3ca1_optionalUserData _033c3ca1_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_033c3ca1_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCreateImage(_s_033c3ca1_context context, _s_033c3ca1_gpu gpu, _s_033c3ca1_handleName handleName, _s_033c3ca1_dimensions dimensions, _s_033c3ca1_format format, _s_033c3ca1_xformat xformat, _s_033c3ca1_width width, _s_033c3ca1_height height, _s_033c3ca1_depth depth, _s_033c3ca1_levelsCount levelsCount, _s_033c3ca1_layersCount layersCount, _s_033c3ca1_multisampleCount multisampleCount, _s_033c3ca1_restrictToAccess restrictToAccess, _s_033c3ca1_initialAccess initialAccess, _s_033c3ca1_initialQueueFamilyIndex initialQueueFamilyIndex, _s_033c3ca1_dedicate dedicate, _s_033c3ca1_outImage outImage, _s_033c3ca1_outStatuses outStatuses, _s_033c3ca1_optionalFile optionalFile, _s_033c3ca1_optionalLine optionalLine, _s_033c3ca1_optionalUserData optionalUserData) {
  redXCreateImage(context.value, gpu.value, handleName.value, dimensions.value, format.value, xformat.value, width.value, height.value, depth.value, levelsCount.value, layersCount.value, multisampleCount.value, restrictToAccess.value, initialAccess.value, initialQueueFamilyIndex.value, dedicate.value, outImage.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCreateTexture redXCreateTexture
#define _855b929b_context(value) value
#define _855b929b_gpu(value) value
#define _855b929b_handleName(value) value
#define _855b929b_image(value) value
#define _855b929b_parts(value) value
#define _855b929b_dimensions(value) value
#define _855b929b_format(value) value
#define _855b929b_xformat(value) value
#define _855b929b_levelsFirst(value) value
#define _855b929b_levelsCount(value) value
#define _855b929b_layersFirst(value) value
#define _855b929b_layersCount(value) value
#define _855b929b_restrictToAccess(value) value
#define _855b929b_outTexture(value) value
#define _855b929b_outStatuses(value) value
#define _855b929b_optionalFile(value) value
#define _855b929b_optionalLine(value) value
#define _855b929b_optionalUserData(value) value
#else
typedef struct _s_855b929b_context { RedContext value; } _s_855b929b_context;
typedef struct _s_855b929b_gpu { RedHandleGpu value; } _s_855b929b_gpu;
typedef struct _s_855b929b_handleName { char* value; } _s_855b929b_handleName;
typedef struct _s_855b929b_image { RedHandleImage value; } _s_855b929b_image;
typedef struct _s_855b929b_parts { RedImagePartBitflags value; } _s_855b929b_parts;
typedef struct _s_855b929b_dimensions { RedTextureDimensions value; } _s_855b929b_dimensions;
typedef struct _s_855b929b_format { RedFormat value; } _s_855b929b_format;
typedef struct _s_855b929b_xformat { unsigned value; } _s_855b929b_xformat;
typedef struct _s_855b929b_levelsFirst { unsigned value; } _s_855b929b_levelsFirst;
typedef struct _s_855b929b_levelsCount { unsigned value; } _s_855b929b_levelsCount;
typedef struct _s_855b929b_layersFirst { unsigned value; } _s_855b929b_layersFirst;
typedef struct _s_855b929b_layersCount { unsigned value; } _s_855b929b_layersCount;
typedef struct _s_855b929b_restrictToAccess { RedAccessBitflags value; } _s_855b929b_restrictToAccess;
typedef struct _s_855b929b_outTexture { RedHandleTexture* value; } _s_855b929b_outTexture;
typedef struct _s_855b929b_outStatuses { RedStatuses* value; } _s_855b929b_outStatuses;
typedef struct _s_855b929b_optionalFile { char* value; } _s_855b929b_optionalFile;
typedef struct _s_855b929b_optionalLine { int value; } _s_855b929b_optionalLine;
typedef struct _s_855b929b_optionalUserData { void* value; } _s_855b929b_optionalUserData;
static inline _s_855b929b_context _855b929b_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_context){value}; }
static inline _s_855b929b_gpu _855b929b_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_gpu){value}; }
static inline _s_855b929b_handleName _855b929b_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_handleName){value}; }
static inline _s_855b929b_image _855b929b_image(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_image){value}; }
static inline _s_855b929b_parts _855b929b_parts(RedImagePartBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_parts){value}; }
static inline _s_855b929b_dimensions _855b929b_dimensions(RedTextureDimensions value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_dimensions){value}; }
static inline _s_855b929b_format _855b929b_format(RedFormat value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_format){value}; }
static inline _s_855b929b_xformat _855b929b_xformat(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_xformat){value}; }
static inline _s_855b929b_levelsFirst _855b929b_levelsFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_levelsFirst){value}; }
static inline _s_855b929b_levelsCount _855b929b_levelsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_levelsCount){value}; }
static inline _s_855b929b_layersFirst _855b929b_layersFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_layersFirst){value}; }
static inline _s_855b929b_layersCount _855b929b_layersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_layersCount){value}; }
static inline _s_855b929b_restrictToAccess _855b929b_restrictToAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_restrictToAccess){value}; }
static inline _s_855b929b_outTexture _855b929b_outTexture(RedHandleTexture* value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_outTexture){value}; }
static inline _s_855b929b_outStatuses _855b929b_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_outStatuses){value}; }
static inline _s_855b929b_optionalFile _855b929b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_optionalFile){value}; }
static inline _s_855b929b_optionalLine _855b929b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_optionalLine){value}; }
static inline _s_855b929b_optionalUserData _855b929b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_855b929b_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCreateTexture(_s_855b929b_context context, _s_855b929b_gpu gpu, _s_855b929b_handleName handleName, _s_855b929b_image image, _s_855b929b_parts parts, _s_855b929b_dimensions dimensions, _s_855b929b_format format, _s_855b929b_xformat xformat, _s_855b929b_levelsFirst levelsFirst, _s_855b929b_levelsCount levelsCount, _s_855b929b_layersFirst layersFirst, _s_855b929b_layersCount layersCount, _s_855b929b_restrictToAccess restrictToAccess, _s_855b929b_outTexture outTexture, _s_855b929b_outStatuses outStatuses, _s_855b929b_optionalFile optionalFile, _s_855b929b_optionalLine optionalLine, _s_855b929b_optionalUserData optionalUserData) {
  redXCreateTexture(context.value, gpu.value, handleName.value, image.value, parts.value, dimensions.value, format.value, xformat.value, levelsFirst.value, levelsCount.value, layersFirst.value, layersCount.value, restrictToAccess.value, outTexture.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetHandlePageableMemory redXGetHandlePageableMemory
#define _4b10fc38_context(value) value
#define _4b10fc38_gpu(value) value
#define _4b10fc38_memory(value) value
#else
typedef struct _s_4b10fc38_context { RedContext value; } _s_4b10fc38_context;
typedef struct _s_4b10fc38_gpu { RedHandleGpu value; } _s_4b10fc38_gpu;
typedef struct _s_4b10fc38_memory { RedHandleMemory value; } _s_4b10fc38_memory;
static inline _s_4b10fc38_context _4b10fc38_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_4b10fc38_context){value}; }
static inline _s_4b10fc38_gpu _4b10fc38_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_4b10fc38_gpu){value}; }
static inline _s_4b10fc38_memory _4b10fc38_memory(RedHandleMemory value) { return REDGPU_NP_STRUCT_INIT(_s_4b10fc38_memory){value}; }
REDGPU_NP_DECLSPEC RedXHandlePageable REDGPU_NP_API np_redXGetHandlePageableMemory(_s_4b10fc38_context context, _s_4b10fc38_gpu gpu, _s_4b10fc38_memory memory) {
  return redXGetHandlePageableMemory(context.value, gpu.value, memory.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetHandlePageableStructsMemory redXGetHandlePageableStructsMemory
#define _d029ff5f_context(value) value
#define _d029ff5f_gpu(value) value
#define _d029ff5f_structsMemory(value) value
#else
typedef struct _s_d029ff5f_context { RedContext value; } _s_d029ff5f_context;
typedef struct _s_d029ff5f_gpu { RedHandleGpu value; } _s_d029ff5f_gpu;
typedef struct _s_d029ff5f_structsMemory { RedHandleStructsMemory value; } _s_d029ff5f_structsMemory;
static inline _s_d029ff5f_context _d029ff5f_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_d029ff5f_context){value}; }
static inline _s_d029ff5f_gpu _d029ff5f_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_d029ff5f_gpu){value}; }
static inline _s_d029ff5f_structsMemory _d029ff5f_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_d029ff5f_structsMemory){value}; }
REDGPU_NP_DECLSPEC RedXHandlePageable REDGPU_NP_API np_redXGetHandlePageableStructsMemory(_s_d029ff5f_context context, _s_d029ff5f_gpu gpu, _s_d029ff5f_structsMemory structsMemory) {
  return redXGetHandlePageableStructsMemory(context.value, gpu.value, structsMemory.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXPageableSetResidencyPriority redXPageableSetResidencyPriority
#define _c596452b_context(value) value
#define _c596452b_gpu(value) value
#define _c596452b_pageablesCount(value) value
#define _c596452b_pageables(value) value
#define _c596452b_pageablesResidencyPriority(value) value
#define _c596452b_outStatuses(value) value
#define _c596452b_optionalFile(value) value
#define _c596452b_optionalLine(value) value
#define _c596452b_optionalUserData(value) value
#else
typedef struct _s_c596452b_context { RedContext value; } _s_c596452b_context;
typedef struct _s_c596452b_gpu { RedHandleGpu value; } _s_c596452b_gpu;
typedef struct _s_c596452b_pageablesCount { unsigned value; } _s_c596452b_pageablesCount;
typedef struct _s_c596452b_pageables { RedXHandlePageable* value; } _s_c596452b_pageables;
typedef struct _s_c596452b_pageablesResidencyPriority { RedXPageableResidencyPriorityBitflags* value; } _s_c596452b_pageablesResidencyPriority;
typedef struct _s_c596452b_outStatuses { RedStatuses* value; } _s_c596452b_outStatuses;
typedef struct _s_c596452b_optionalFile { char* value; } _s_c596452b_optionalFile;
typedef struct _s_c596452b_optionalLine { int value; } _s_c596452b_optionalLine;
typedef struct _s_c596452b_optionalUserData { void* value; } _s_c596452b_optionalUserData;
static inline _s_c596452b_context _c596452b_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_c596452b_context){value}; }
static inline _s_c596452b_gpu _c596452b_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_c596452b_gpu){value}; }
static inline _s_c596452b_pageablesCount _c596452b_pageablesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c596452b_pageablesCount){value}; }
static inline _s_c596452b_pageables _c596452b_pageables(RedXHandlePageable* value) { return REDGPU_NP_STRUCT_INIT(_s_c596452b_pageables){value}; }
static inline _s_c596452b_pageablesResidencyPriority _c596452b_pageablesResidencyPriority(RedXPageableResidencyPriorityBitflags* value) { return REDGPU_NP_STRUCT_INIT(_s_c596452b_pageablesResidencyPriority){value}; }
static inline _s_c596452b_outStatuses _c596452b_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_c596452b_outStatuses){value}; }
static inline _s_c596452b_optionalFile _c596452b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c596452b_optionalFile){value}; }
static inline _s_c596452b_optionalLine _c596452b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c596452b_optionalLine){value}; }
static inline _s_c596452b_optionalUserData _c596452b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c596452b_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXPageableSetResidencyPriority(_s_c596452b_context context, _s_c596452b_gpu gpu, _s_c596452b_pageablesCount pageablesCount, _s_c596452b_pageables pageables, _s_c596452b_pageablesResidencyPriority pageablesResidencyPriority, _s_c596452b_outStatuses outStatuses, _s_c596452b_optionalFile optionalFile, _s_c596452b_optionalLine optionalLine, _s_c596452b_optionalUserData optionalUserData) {
  redXPageableSetResidencyPriority(context.value, gpu.value, pageablesCount.value, pageables.value, pageablesResidencyPriority.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXPageableMakeResident redXPageableMakeResident
#define _1e8e0dfa_context(value) value
#define _1e8e0dfa_gpu(value) value
#define _1e8e0dfa_pageablesCount(value) value
#define _1e8e0dfa_pageables(value) value
#define _1e8e0dfa_denyOverbudget(value) value
#define _1e8e0dfa_signalCpuSignal(value) value
#define _1e8e0dfa_outStatuses(value) value
#define _1e8e0dfa_optionalFile(value) value
#define _1e8e0dfa_optionalLine(value) value
#define _1e8e0dfa_optionalUserData(value) value
#else
typedef struct _s_1e8e0dfa_context { RedContext value; } _s_1e8e0dfa_context;
typedef struct _s_1e8e0dfa_gpu { RedHandleGpu value; } _s_1e8e0dfa_gpu;
typedef struct _s_1e8e0dfa_pageablesCount { unsigned value; } _s_1e8e0dfa_pageablesCount;
typedef struct _s_1e8e0dfa_pageables { RedXHandlePageable* value; } _s_1e8e0dfa_pageables;
typedef struct _s_1e8e0dfa_denyOverbudget { RedBool32 value; } _s_1e8e0dfa_denyOverbudget;
typedef struct _s_1e8e0dfa_signalCpuSignal { RedHandleCpuSignal value; } _s_1e8e0dfa_signalCpuSignal;
typedef struct _s_1e8e0dfa_outStatuses { RedStatuses* value; } _s_1e8e0dfa_outStatuses;
typedef struct _s_1e8e0dfa_optionalFile { char* value; } _s_1e8e0dfa_optionalFile;
typedef struct _s_1e8e0dfa_optionalLine { int value; } _s_1e8e0dfa_optionalLine;
typedef struct _s_1e8e0dfa_optionalUserData { void* value; } _s_1e8e0dfa_optionalUserData;
static inline _s_1e8e0dfa_context _1e8e0dfa_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_1e8e0dfa_context){value}; }
static inline _s_1e8e0dfa_gpu _1e8e0dfa_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_1e8e0dfa_gpu){value}; }
static inline _s_1e8e0dfa_pageablesCount _1e8e0dfa_pageablesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1e8e0dfa_pageablesCount){value}; }
static inline _s_1e8e0dfa_pageables _1e8e0dfa_pageables(RedXHandlePageable* value) { return REDGPU_NP_STRUCT_INIT(_s_1e8e0dfa_pageables){value}; }
static inline _s_1e8e0dfa_denyOverbudget _1e8e0dfa_denyOverbudget(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_1e8e0dfa_denyOverbudget){value}; }
static inline _s_1e8e0dfa_signalCpuSignal _1e8e0dfa_signalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_1e8e0dfa_signalCpuSignal){value}; }
static inline _s_1e8e0dfa_outStatuses _1e8e0dfa_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_1e8e0dfa_outStatuses){value}; }
static inline _s_1e8e0dfa_optionalFile _1e8e0dfa_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1e8e0dfa_optionalFile){value}; }
static inline _s_1e8e0dfa_optionalLine _1e8e0dfa_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1e8e0dfa_optionalLine){value}; }
static inline _s_1e8e0dfa_optionalUserData _1e8e0dfa_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1e8e0dfa_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXPageableMakeResident(_s_1e8e0dfa_context context, _s_1e8e0dfa_gpu gpu, _s_1e8e0dfa_pageablesCount pageablesCount, _s_1e8e0dfa_pageables pageables, _s_1e8e0dfa_denyOverbudget denyOverbudget, _s_1e8e0dfa_signalCpuSignal signalCpuSignal, _s_1e8e0dfa_outStatuses outStatuses, _s_1e8e0dfa_optionalFile optionalFile, _s_1e8e0dfa_optionalLine optionalLine, _s_1e8e0dfa_optionalUserData optionalUserData) {
  redXPageableMakeResident(context.value, gpu.value, pageablesCount.value, pageables.value, denyOverbudget.value, signalCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXPageableEvict redXPageableEvict
#define _e2796761_context(value) value
#define _e2796761_gpu(value) value
#define _e2796761_pageablesCount(value) value
#define _e2796761_pageables(value) value
#define _e2796761_outStatuses(value) value
#define _e2796761_optionalFile(value) value
#define _e2796761_optionalLine(value) value
#define _e2796761_optionalUserData(value) value
#else
typedef struct _s_e2796761_context { RedContext value; } _s_e2796761_context;
typedef struct _s_e2796761_gpu { RedHandleGpu value; } _s_e2796761_gpu;
typedef struct _s_e2796761_pageablesCount { unsigned value; } _s_e2796761_pageablesCount;
typedef struct _s_e2796761_pageables { RedXHandlePageable* value; } _s_e2796761_pageables;
typedef struct _s_e2796761_outStatuses { RedStatuses* value; } _s_e2796761_outStatuses;
typedef struct _s_e2796761_optionalFile { char* value; } _s_e2796761_optionalFile;
typedef struct _s_e2796761_optionalLine { int value; } _s_e2796761_optionalLine;
typedef struct _s_e2796761_optionalUserData { void* value; } _s_e2796761_optionalUserData;
static inline _s_e2796761_context _e2796761_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_e2796761_context){value}; }
static inline _s_e2796761_gpu _e2796761_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_e2796761_gpu){value}; }
static inline _s_e2796761_pageablesCount _e2796761_pageablesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e2796761_pageablesCount){value}; }
static inline _s_e2796761_pageables _e2796761_pageables(RedXHandlePageable* value) { return REDGPU_NP_STRUCT_INIT(_s_e2796761_pageables){value}; }
static inline _s_e2796761_outStatuses _e2796761_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_e2796761_outStatuses){value}; }
static inline _s_e2796761_optionalFile _e2796761_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e2796761_optionalFile){value}; }
static inline _s_e2796761_optionalLine _e2796761_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e2796761_optionalLine){value}; }
static inline _s_e2796761_optionalUserData _e2796761_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e2796761_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXPageableEvict(_s_e2796761_context context, _s_e2796761_gpu gpu, _s_e2796761_pageablesCount pageablesCount, _s_e2796761_pageables pageables, _s_e2796761_outStatuses outStatuses, _s_e2796761_optionalFile optionalFile, _s_e2796761_optionalLine optionalLine, _s_e2796761_optionalUserData optionalUserData) {
  redXPageableEvict(context.value, gpu.value, pageablesCount.value, pageables.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetHandleResourceArray redXGetHandleResourceArray
#define _af230c46_context(value) value
#define _af230c46_gpu(value) value
#define _af230c46_array(value) value
#else
typedef struct _s_af230c46_context { RedContext value; } _s_af230c46_context;
typedef struct _s_af230c46_gpu { RedHandleGpu value; } _s_af230c46_gpu;
typedef struct _s_af230c46_array { RedHandleArray value; } _s_af230c46_array;
static inline _s_af230c46_context _af230c46_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_af230c46_context){value}; }
static inline _s_af230c46_gpu _af230c46_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_af230c46_gpu){value}; }
static inline _s_af230c46_array _af230c46_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_af230c46_array){value}; }
REDGPU_NP_DECLSPEC RedXHandleResource REDGPU_NP_API np_redXGetHandleResourceArray(_s_af230c46_context context, _s_af230c46_gpu gpu, _s_af230c46_array array) {
  return redXGetHandleResourceArray(context.value, gpu.value, array.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetHandleResourceImage redXGetHandleResourceImage
#define _f49f94b5_context(value) value
#define _f49f94b5_gpu(value) value
#define _f49f94b5_image(value) value
#else
typedef struct _s_f49f94b5_context { RedContext value; } _s_f49f94b5_context;
typedef struct _s_f49f94b5_gpu { RedHandleGpu value; } _s_f49f94b5_gpu;
typedef struct _s_f49f94b5_image { RedHandleImage value; } _s_f49f94b5_image;
static inline _s_f49f94b5_context _f49f94b5_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_f49f94b5_context){value}; }
static inline _s_f49f94b5_gpu _f49f94b5_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_f49f94b5_gpu){value}; }
static inline _s_f49f94b5_image _f49f94b5_image(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_f49f94b5_image){value}; }
REDGPU_NP_DECLSPEC RedXHandleResource REDGPU_NP_API np_redXGetHandleResourceImage(_s_f49f94b5_context context, _s_f49f94b5_gpu gpu, _s_f49f94b5_image image) {
  return redXGetHandleResourceImage(context.value, gpu.value, image.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCallSetProcedureOutput redXCallSetProcedureOutput
#define _c5f24e0c_calls(value) value
#define _c5f24e0c_depthStencil(value) value
#define _c5f24e0c_colorsCount(value) value
#define _c5f24e0c_colors(value) value
#define _c5f24e0c_depthSetProcedureOutputOp(value) value
#define _c5f24e0c_stencilSetProcedureOutputOp(value) value
#define _c5f24e0c_colorsSetProcedureOutputOp(value) value
#define _c5f24e0c_depthClearValue(value) value
#define _c5f24e0c_stencilClearValue(value) value
#define _c5f24e0c_colorsClearValuesFloat(value) value
#else
typedef struct _s_c5f24e0c_calls { RedHandleCalls value; } _s_c5f24e0c_calls;
typedef struct _s_c5f24e0c_depthStencil { RedHandleTexture value; } _s_c5f24e0c_depthStencil;
typedef struct _s_c5f24e0c_colorsCount { unsigned value; } _s_c5f24e0c_colorsCount;
typedef struct _s_c5f24e0c_colors { RedHandleTexture* value; } _s_c5f24e0c_colors;
typedef struct _s_c5f24e0c_depthSetProcedureOutputOp { RedSetProcedureOutputOp value; } _s_c5f24e0c_depthSetProcedureOutputOp;
typedef struct _s_c5f24e0c_stencilSetProcedureOutputOp { RedSetProcedureOutputOp value; } _s_c5f24e0c_stencilSetProcedureOutputOp;
typedef struct _s_c5f24e0c_colorsSetProcedureOutputOp { RedSetProcedureOutputOp* value; } _s_c5f24e0c_colorsSetProcedureOutputOp;
typedef struct _s_c5f24e0c_depthClearValue { float value; } _s_c5f24e0c_depthClearValue;
typedef struct _s_c5f24e0c_stencilClearValue { unsigned value; } _s_c5f24e0c_stencilClearValue;
typedef struct _s_c5f24e0c_colorsClearValuesFloat { RedColorsClearValuesFloat* value; } _s_c5f24e0c_colorsClearValuesFloat;
static inline _s_c5f24e0c_calls _c5f24e0c_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_c5f24e0c_calls){value}; }
static inline _s_c5f24e0c_depthStencil _c5f24e0c_depthStencil(RedHandleTexture value) { return REDGPU_NP_STRUCT_INIT(_s_c5f24e0c_depthStencil){value}; }
static inline _s_c5f24e0c_colorsCount _c5f24e0c_colorsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c5f24e0c_colorsCount){value}; }
static inline _s_c5f24e0c_colors _c5f24e0c_colors(RedHandleTexture* value) { return REDGPU_NP_STRUCT_INIT(_s_c5f24e0c_colors){value}; }
static inline _s_c5f24e0c_depthSetProcedureOutputOp _c5f24e0c_depthSetProcedureOutputOp(RedSetProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_c5f24e0c_depthSetProcedureOutputOp){value}; }
static inline _s_c5f24e0c_stencilSetProcedureOutputOp _c5f24e0c_stencilSetProcedureOutputOp(RedSetProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_c5f24e0c_stencilSetProcedureOutputOp){value}; }
static inline _s_c5f24e0c_colorsSetProcedureOutputOp _c5f24e0c_colorsSetProcedureOutputOp(RedSetProcedureOutputOp* value) { return REDGPU_NP_STRUCT_INIT(_s_c5f24e0c_colorsSetProcedureOutputOp){value}; }
static inline _s_c5f24e0c_depthClearValue _c5f24e0c_depthClearValue(float value) { return REDGPU_NP_STRUCT_INIT(_s_c5f24e0c_depthClearValue){value}; }
static inline _s_c5f24e0c_stencilClearValue _c5f24e0c_stencilClearValue(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c5f24e0c_stencilClearValue){value}; }
static inline _s_c5f24e0c_colorsClearValuesFloat _c5f24e0c_colorsClearValuesFloat(RedColorsClearValuesFloat* value) { return REDGPU_NP_STRUCT_INIT(_s_c5f24e0c_colorsClearValuesFloat){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCallSetProcedureOutput(_s_c5f24e0c_calls calls, _s_c5f24e0c_depthStencil depthStencil, _s_c5f24e0c_colorsCount colorsCount, _s_c5f24e0c_colors colors, _s_c5f24e0c_depthSetProcedureOutputOp depthSetProcedureOutputOp, _s_c5f24e0c_stencilSetProcedureOutputOp stencilSetProcedureOutputOp, _s_c5f24e0c_colorsSetProcedureOutputOp colorsSetProcedureOutputOp, _s_c5f24e0c_depthClearValue depthClearValue, _s_c5f24e0c_stencilClearValue stencilClearValue, _s_c5f24e0c_colorsClearValuesFloat colorsClearValuesFloat) {
  redXCallSetProcedureOutput(calls.value, depthStencil.value, colorsCount.value, colors.value, depthSetProcedureOutputOp.value, stencilSetProcedureOutputOp.value, colorsSetProcedureOutputOp.value, depthClearValue.value, stencilClearValue.value, colorsClearValuesFloat.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCallEndProcedureOutput redXCallEndProcedureOutput
#define _3ac44cde_calls(value) value
#define _3ac44cde_resolveTargetColors(value) value
#define _3ac44cde_resolveTargetColorsFormat(value) value
#define _3ac44cde_depthEndProcedureOutputOp(value) value
#define _3ac44cde_stencilEndProcedureOutputOp(value) value
#define _3ac44cde_colorsEndProcedureOutputOp(value) value
#else
typedef struct _s_3ac44cde_calls { RedHandleCalls value; } _s_3ac44cde_calls;
typedef struct _s_3ac44cde_resolveTargetColors { RedHandleTexture* value; } _s_3ac44cde_resolveTargetColors;
typedef struct _s_3ac44cde_resolveTargetColorsFormat { unsigned* value; } _s_3ac44cde_resolveTargetColorsFormat;
typedef struct _s_3ac44cde_depthEndProcedureOutputOp { RedEndProcedureOutputOp value; } _s_3ac44cde_depthEndProcedureOutputOp;
typedef struct _s_3ac44cde_stencilEndProcedureOutputOp { RedEndProcedureOutputOp value; } _s_3ac44cde_stencilEndProcedureOutputOp;
typedef struct _s_3ac44cde_colorsEndProcedureOutputOp { RedEndProcedureOutputOp* value; } _s_3ac44cde_colorsEndProcedureOutputOp;
static inline _s_3ac44cde_calls _3ac44cde_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_3ac44cde_calls){value}; }
static inline _s_3ac44cde_resolveTargetColors _3ac44cde_resolveTargetColors(RedHandleTexture* value) { return REDGPU_NP_STRUCT_INIT(_s_3ac44cde_resolveTargetColors){value}; }
static inline _s_3ac44cde_resolveTargetColorsFormat _3ac44cde_resolveTargetColorsFormat(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_3ac44cde_resolveTargetColorsFormat){value}; }
static inline _s_3ac44cde_depthEndProcedureOutputOp _3ac44cde_depthEndProcedureOutputOp(RedEndProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_3ac44cde_depthEndProcedureOutputOp){value}; }
static inline _s_3ac44cde_stencilEndProcedureOutputOp _3ac44cde_stencilEndProcedureOutputOp(RedEndProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_3ac44cde_stencilEndProcedureOutputOp){value}; }
static inline _s_3ac44cde_colorsEndProcedureOutputOp _3ac44cde_colorsEndProcedureOutputOp(RedEndProcedureOutputOp* value) { return REDGPU_NP_STRUCT_INIT(_s_3ac44cde_colorsEndProcedureOutputOp){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCallEndProcedureOutput(_s_3ac44cde_calls calls, _s_3ac44cde_resolveTargetColors resolveTargetColors, _s_3ac44cde_resolveTargetColorsFormat resolveTargetColorsFormat, _s_3ac44cde_depthEndProcedureOutputOp depthEndProcedureOutputOp, _s_3ac44cde_stencilEndProcedureOutputOp stencilEndProcedureOutputOp, _s_3ac44cde_colorsEndProcedureOutputOp colorsEndProcedureOutputOp) {
  redXCallEndProcedureOutput(calls.value, resolveTargetColors.value, resolveTargetColorsFormat.value, depthEndProcedureOutputOp.value, stencilEndProcedureOutputOp.value, colorsEndProcedureOutputOp.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCallUsageAliasOrderBarrier redXCallUsageAliasOrderBarrier
#define _c0b32403_calls(value) value
#define _c0b32403_barriersCount(value) value
#define _c0b32403_barriers(value) value
#else
typedef struct _s_c0b32403_calls { RedHandleCalls value; } _s_c0b32403_calls;
typedef struct _s_c0b32403_barriersCount { unsigned value; } _s_c0b32403_barriersCount;
typedef struct _s_c0b32403_barriers { void* value; } _s_c0b32403_barriers;
static inline _s_c0b32403_calls _c0b32403_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_c0b32403_calls){value}; }
static inline _s_c0b32403_barriersCount _c0b32403_barriersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c0b32403_barriersCount){value}; }
static inline _s_c0b32403_barriers _c0b32403_barriers(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c0b32403_barriers){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCallUsageAliasOrderBarrier(_s_c0b32403_calls calls, _s_c0b32403_barriersCount barriersCount, _s_c0b32403_barriers barriers) {
  redXCallUsageAliasOrderBarrier(calls.value, barriersCount.value, barriers.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCallCopyImageRegion redXCallCopyImageRegion
#define _a52b038b_calls(value) value
#define _a52b038b_copiesCount(value) value
#define _a52b038b_copies(value) value
#else
typedef struct _s_a52b038b_calls { RedHandleCalls value; } _s_a52b038b_calls;
typedef struct _s_a52b038b_copiesCount { unsigned value; } _s_a52b038b_copiesCount;
typedef struct _s_a52b038b_copies { void* value; } _s_a52b038b_copies;
static inline _s_a52b038b_calls _a52b038b_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_a52b038b_calls){value}; }
static inline _s_a52b038b_copiesCount _a52b038b_copiesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a52b038b_copiesCount){value}; }
static inline _s_a52b038b_copies _a52b038b_copies(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a52b038b_copies){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCallCopyImageRegion(_s_a52b038b_calls calls, _s_a52b038b_copiesCount copiesCount, _s_a52b038b_copies copies) {
  redXCallCopyImageRegion(calls.value, copiesCount.value, copies.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCreateSurfaceWinRT redXCreateSurfaceWinRT
#define _07dfa0b7_context(value) value
#define _07dfa0b7_gpu(value) value
#define _07dfa0b7_handleName(value) value
#define _07dfa0b7_winrtIUnknownPointerCoreWindow(value) value
#define _07dfa0b7_outSurface(value) value
#define _07dfa0b7_outStatuses(value) value
#define _07dfa0b7_optionalFile(value) value
#define _07dfa0b7_optionalLine(value) value
#define _07dfa0b7_optionalUserData(value) value
#else
typedef struct _s_07dfa0b7_context { RedContext value; } _s_07dfa0b7_context;
typedef struct _s_07dfa0b7_gpu { RedHandleGpu value; } _s_07dfa0b7_gpu;
typedef struct _s_07dfa0b7_handleName { char* value; } _s_07dfa0b7_handleName;
typedef struct _s_07dfa0b7_winrtIUnknownPointerCoreWindow { void* value; } _s_07dfa0b7_winrtIUnknownPointerCoreWindow;
typedef struct _s_07dfa0b7_outSurface { RedHandleSurface* value; } _s_07dfa0b7_outSurface;
typedef struct _s_07dfa0b7_outStatuses { RedStatuses* value; } _s_07dfa0b7_outStatuses;
typedef struct _s_07dfa0b7_optionalFile { char* value; } _s_07dfa0b7_optionalFile;
typedef struct _s_07dfa0b7_optionalLine { int value; } _s_07dfa0b7_optionalLine;
typedef struct _s_07dfa0b7_optionalUserData { void* value; } _s_07dfa0b7_optionalUserData;
static inline _s_07dfa0b7_context _07dfa0b7_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_07dfa0b7_context){value}; }
static inline _s_07dfa0b7_gpu _07dfa0b7_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_07dfa0b7_gpu){value}; }
static inline _s_07dfa0b7_handleName _07dfa0b7_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_07dfa0b7_handleName){value}; }
static inline _s_07dfa0b7_winrtIUnknownPointerCoreWindow _07dfa0b7_winrtIUnknownPointerCoreWindow(void* value) { return REDGPU_NP_STRUCT_INIT(_s_07dfa0b7_winrtIUnknownPointerCoreWindow){value}; }
static inline _s_07dfa0b7_outSurface _07dfa0b7_outSurface(RedHandleSurface* value) { return REDGPU_NP_STRUCT_INIT(_s_07dfa0b7_outSurface){value}; }
static inline _s_07dfa0b7_outStatuses _07dfa0b7_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_07dfa0b7_outStatuses){value}; }
static inline _s_07dfa0b7_optionalFile _07dfa0b7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_07dfa0b7_optionalFile){value}; }
static inline _s_07dfa0b7_optionalLine _07dfa0b7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_07dfa0b7_optionalLine){value}; }
static inline _s_07dfa0b7_optionalUserData _07dfa0b7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_07dfa0b7_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCreateSurfaceWinRT(_s_07dfa0b7_context context, _s_07dfa0b7_gpu gpu, _s_07dfa0b7_handleName handleName, _s_07dfa0b7_winrtIUnknownPointerCoreWindow winrtIUnknownPointerCoreWindow, _s_07dfa0b7_outSurface outSurface, _s_07dfa0b7_outStatuses outStatuses, _s_07dfa0b7_optionalFile optionalFile, _s_07dfa0b7_optionalLine optionalLine, _s_07dfa0b7_optionalUserData optionalUserData) {
  redXCreateSurfaceWinRT(context.value, gpu.value, handleName.value, winrtIUnknownPointerCoreWindow.value, outSurface.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

