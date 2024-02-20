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
#define _071cccc6_context(value) value
#define _071cccc6_gpu(value) value
#define _071cccc6_eventHandle(value) value
#define _071cccc6_outMemoryCallbackBudgetChange(value) value
#define _071cccc6_outStatuses(value) value
#define _071cccc6_optionalFile(value) value
#define _071cccc6_optionalLine(value) value
#define _071cccc6_optionalUserData(value) value
#else
typedef struct _s_071cccc6_context { RedContext value; } _s_071cccc6_context;
typedef struct _s_071cccc6_gpu { RedHandleGpu value; } _s_071cccc6_gpu;
typedef struct _s_071cccc6_eventHandle { void* value; } _s_071cccc6_eventHandle;
typedef struct _s_071cccc6_outMemoryCallbackBudgetChange { RedXHandleMemoryCallbackBudgetChange* value; } _s_071cccc6_outMemoryCallbackBudgetChange;
typedef struct _s_071cccc6_outStatuses { RedStatuses* value; } _s_071cccc6_outStatuses;
typedef struct _s_071cccc6_optionalFile { char* value; } _s_071cccc6_optionalFile;
typedef struct _s_071cccc6_optionalLine { int value; } _s_071cccc6_optionalLine;
typedef struct _s_071cccc6_optionalUserData { void* value; } _s_071cccc6_optionalUserData;
static inline _s_071cccc6_context _071cccc6_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_071cccc6_context){value}; }
static inline _s_071cccc6_gpu _071cccc6_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_071cccc6_gpu){value}; }
static inline _s_071cccc6_eventHandle _071cccc6_eventHandle(void* value) { return REDGPU_NP_STRUCT_INIT(_s_071cccc6_eventHandle){value}; }
static inline _s_071cccc6_outMemoryCallbackBudgetChange _071cccc6_outMemoryCallbackBudgetChange(RedXHandleMemoryCallbackBudgetChange* value) { return REDGPU_NP_STRUCT_INIT(_s_071cccc6_outMemoryCallbackBudgetChange){value}; }
static inline _s_071cccc6_outStatuses _071cccc6_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_071cccc6_outStatuses){value}; }
static inline _s_071cccc6_optionalFile _071cccc6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_071cccc6_optionalFile){value}; }
static inline _s_071cccc6_optionalLine _071cccc6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_071cccc6_optionalLine){value}; }
static inline _s_071cccc6_optionalUserData _071cccc6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_071cccc6_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXMemoryCallbackBudgetChangeRegister(_s_071cccc6_context context, _s_071cccc6_gpu gpu, _s_071cccc6_eventHandle eventHandle, _s_071cccc6_outMemoryCallbackBudgetChange outMemoryCallbackBudgetChange, _s_071cccc6_outStatuses outStatuses, _s_071cccc6_optionalFile optionalFile, _s_071cccc6_optionalLine optionalLine, _s_071cccc6_optionalUserData optionalUserData) {
  redXMemoryCallbackBudgetChangeRegister(context.value, gpu.value, eventHandle.value, outMemoryCallbackBudgetChange.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXMemoryCallbackBudgetChangeUnregister redXMemoryCallbackBudgetChangeUnregister
#define _ef987d6d_context(value) value
#define _ef987d6d_gpu(value) value
#define _ef987d6d_memoryCallbackBudgetChange(value) value
#define _ef987d6d_optionalFile(value) value
#define _ef987d6d_optionalLine(value) value
#define _ef987d6d_optionalUserData(value) value
#else
typedef struct _s_ef987d6d_context { RedContext value; } _s_ef987d6d_context;
typedef struct _s_ef987d6d_gpu { RedHandleGpu value; } _s_ef987d6d_gpu;
typedef struct _s_ef987d6d_memoryCallbackBudgetChange { RedXHandleMemoryCallbackBudgetChange value; } _s_ef987d6d_memoryCallbackBudgetChange;
typedef struct _s_ef987d6d_optionalFile { char* value; } _s_ef987d6d_optionalFile;
typedef struct _s_ef987d6d_optionalLine { int value; } _s_ef987d6d_optionalLine;
typedef struct _s_ef987d6d_optionalUserData { void* value; } _s_ef987d6d_optionalUserData;
static inline _s_ef987d6d_context _ef987d6d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_ef987d6d_context){value}; }
static inline _s_ef987d6d_gpu _ef987d6d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_ef987d6d_gpu){value}; }
static inline _s_ef987d6d_memoryCallbackBudgetChange _ef987d6d_memoryCallbackBudgetChange(RedXHandleMemoryCallbackBudgetChange value) { return REDGPU_NP_STRUCT_INIT(_s_ef987d6d_memoryCallbackBudgetChange){value}; }
static inline _s_ef987d6d_optionalFile _ef987d6d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ef987d6d_optionalFile){value}; }
static inline _s_ef987d6d_optionalLine _ef987d6d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ef987d6d_optionalLine){value}; }
static inline _s_ef987d6d_optionalUserData _ef987d6d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ef987d6d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXMemoryCallbackBudgetChangeUnregister(_s_ef987d6d_context context, _s_ef987d6d_gpu gpu, _s_ef987d6d_memoryCallbackBudgetChange memoryCallbackBudgetChange, _s_ef987d6d_optionalFile optionalFile, _s_ef987d6d_optionalLine optionalLine, _s_ef987d6d_optionalUserData optionalUserData) {
  redXMemoryCallbackBudgetChangeUnregister(context.value, gpu.value, memoryCallbackBudgetChange.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXMemoryReserve redXMemoryReserve
#define _aba70d38_context(value) value
#define _aba70d38_gpu(value) value
#define _aba70d38_sharedMemory(value) value
#define _aba70d38_bytesCount(value) value
#define _aba70d38_outStatuses(value) value
#define _aba70d38_optionalFile(value) value
#define _aba70d38_optionalLine(value) value
#define _aba70d38_optionalUserData(value) value
#else
typedef struct _s_aba70d38_context { RedContext value; } _s_aba70d38_context;
typedef struct _s_aba70d38_gpu { RedHandleGpu value; } _s_aba70d38_gpu;
typedef struct _s_aba70d38_sharedMemory { RedBool32 value; } _s_aba70d38_sharedMemory;
typedef struct _s_aba70d38_bytesCount { uint64_t value; } _s_aba70d38_bytesCount;
typedef struct _s_aba70d38_outStatuses { RedStatuses* value; } _s_aba70d38_outStatuses;
typedef struct _s_aba70d38_optionalFile { char* value; } _s_aba70d38_optionalFile;
typedef struct _s_aba70d38_optionalLine { int value; } _s_aba70d38_optionalLine;
typedef struct _s_aba70d38_optionalUserData { void* value; } _s_aba70d38_optionalUserData;
static inline _s_aba70d38_context _aba70d38_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_aba70d38_context){value}; }
static inline _s_aba70d38_gpu _aba70d38_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_aba70d38_gpu){value}; }
static inline _s_aba70d38_sharedMemory _aba70d38_sharedMemory(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_aba70d38_sharedMemory){value}; }
static inline _s_aba70d38_bytesCount _aba70d38_bytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_aba70d38_bytesCount){value}; }
static inline _s_aba70d38_outStatuses _aba70d38_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_aba70d38_outStatuses){value}; }
static inline _s_aba70d38_optionalFile _aba70d38_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_aba70d38_optionalFile){value}; }
static inline _s_aba70d38_optionalLine _aba70d38_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_aba70d38_optionalLine){value}; }
static inline _s_aba70d38_optionalUserData _aba70d38_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_aba70d38_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXMemoryReserve(_s_aba70d38_context context, _s_aba70d38_gpu gpu, _s_aba70d38_sharedMemory sharedMemory, _s_aba70d38_bytesCount bytesCount, _s_aba70d38_outStatuses outStatuses, _s_aba70d38_optionalFile optionalFile, _s_aba70d38_optionalLine optionalLine, _s_aba70d38_optionalUserData optionalUserData) {
  redXMemoryReserve(context.value, gpu.value, sharedMemory.value, bytesCount.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetMemoryAddressArray redXGetMemoryAddressArray
#define _1ffb68d7_context(value) value
#define _1ffb68d7_gpu(value) value
#define _1ffb68d7_array(value) value
#else
typedef struct _s_1ffb68d7_context { RedContext value; } _s_1ffb68d7_context;
typedef struct _s_1ffb68d7_gpu { RedHandleGpu value; } _s_1ffb68d7_gpu;
typedef struct _s_1ffb68d7_array { RedHandleArray value; } _s_1ffb68d7_array;
static inline _s_1ffb68d7_context _1ffb68d7_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_1ffb68d7_context){value}; }
static inline _s_1ffb68d7_gpu _1ffb68d7_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_1ffb68d7_gpu){value}; }
static inline _s_1ffb68d7_array _1ffb68d7_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_1ffb68d7_array){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redXGetMemoryAddressArray(_s_1ffb68d7_context context, _s_1ffb68d7_gpu gpu, _s_1ffb68d7_array array) {
  return redXGetMemoryAddressArray(context.value, gpu.value, array.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetMemoryAddressSampler redXGetMemoryAddressSampler
#define _fe3baf28_context(value) value
#define _fe3baf28_gpu(value) value
#define _fe3baf28_sampler(value) value
#else
typedef struct _s_fe3baf28_context { RedContext value; } _s_fe3baf28_context;
typedef struct _s_fe3baf28_gpu { RedHandleGpu value; } _s_fe3baf28_gpu;
typedef struct _s_fe3baf28_sampler { RedHandleSampler value; } _s_fe3baf28_sampler;
static inline _s_fe3baf28_context _fe3baf28_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_fe3baf28_context){value}; }
static inline _s_fe3baf28_gpu _fe3baf28_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_fe3baf28_gpu){value}; }
static inline _s_fe3baf28_sampler _fe3baf28_sampler(RedHandleSampler value) { return REDGPU_NP_STRUCT_INIT(_s_fe3baf28_sampler){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redXGetMemoryAddressSampler(_s_fe3baf28_context context, _s_fe3baf28_gpu gpu, _s_fe3baf28_sampler sampler) {
  return redXGetMemoryAddressSampler(context.value, gpu.value, sampler.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetMemoryAddressTextureRO redXGetMemoryAddressTextureRO
#define _eb058632_context(value) value
#define _eb058632_gpu(value) value
#define _eb058632_texture(value) value
#else
typedef struct _s_eb058632_context { RedContext value; } _s_eb058632_context;
typedef struct _s_eb058632_gpu { RedHandleGpu value; } _s_eb058632_gpu;
typedef struct _s_eb058632_texture { RedHandleTexture value; } _s_eb058632_texture;
static inline _s_eb058632_context _eb058632_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_eb058632_context){value}; }
static inline _s_eb058632_gpu _eb058632_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_eb058632_gpu){value}; }
static inline _s_eb058632_texture _eb058632_texture(RedHandleTexture value) { return REDGPU_NP_STRUCT_INIT(_s_eb058632_texture){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redXGetMemoryAddressTextureRO(_s_eb058632_context context, _s_eb058632_gpu gpu, _s_eb058632_texture texture) {
  return redXGetMemoryAddressTextureRO(context.value, gpu.value, texture.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetMemoryAddressTextureRW redXGetMemoryAddressTextureRW
#define _1da2bdac_context(value) value
#define _1da2bdac_gpu(value) value
#define _1da2bdac_texture(value) value
#else
typedef struct _s_1da2bdac_context { RedContext value; } _s_1da2bdac_context;
typedef struct _s_1da2bdac_gpu { RedHandleGpu value; } _s_1da2bdac_gpu;
typedef struct _s_1da2bdac_texture { RedHandleTexture value; } _s_1da2bdac_texture;
static inline _s_1da2bdac_context _1da2bdac_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_1da2bdac_context){value}; }
static inline _s_1da2bdac_gpu _1da2bdac_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_1da2bdac_gpu){value}; }
static inline _s_1da2bdac_texture _1da2bdac_texture(RedHandleTexture value) { return REDGPU_NP_STRUCT_INIT(_s_1da2bdac_texture){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redXGetMemoryAddressTextureRW(_s_1da2bdac_context context, _s_1da2bdac_gpu gpu, _s_1da2bdac_texture texture) {
  return redXGetMemoryAddressTextureRW(context.value, gpu.value, texture.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetMemoryAddressStructMember redXGetMemoryAddressStructMember
#define _c97314a1_context(value) value
#define _c97314a1_gpu(value) value
#define _c97314a1_structsMemory(value) value
#define _c97314a1_structMemberIndex(value) value
#else
typedef struct _s_c97314a1_context { RedContext value; } _s_c97314a1_context;
typedef struct _s_c97314a1_gpu { RedHandleGpu value; } _s_c97314a1_gpu;
typedef struct _s_c97314a1_structsMemory { RedHandleStructsMemory value; } _s_c97314a1_structsMemory;
typedef struct _s_c97314a1_structMemberIndex { unsigned value; } _s_c97314a1_structMemberIndex;
static inline _s_c97314a1_context _c97314a1_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_c97314a1_context){value}; }
static inline _s_c97314a1_gpu _c97314a1_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_c97314a1_gpu){value}; }
static inline _s_c97314a1_structsMemory _c97314a1_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_c97314a1_structsMemory){value}; }
static inline _s_c97314a1_structMemberIndex _c97314a1_structMemberIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c97314a1_structMemberIndex){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redXGetMemoryAddressStructMember(_s_c97314a1_context context, _s_c97314a1_gpu gpu, _s_c97314a1_structsMemory structsMemory, _s_c97314a1_structMemberIndex structMemberIndex) {
  return redXGetMemoryAddressStructMember(context.value, gpu.value, structsMemory.value, structMemberIndex.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXStructsMemorySet redXStructsMemorySet
#define _3dcdce6b_context(value) value
#define _3dcdce6b_gpu(value) value
#define _3dcdce6b_copyingSamplers(value) value
#define _3dcdce6b_sourceCopiesCount(value) value
#define _3dcdce6b_sourceCopiesAddressFirst(value) value
#define _3dcdce6b_sourceCopiesAddressCount(value) value
#define _3dcdce6b_targetCopiesCount(value) value
#define _3dcdce6b_targetCopiesAddressFirst(value) value
#define _3dcdce6b_targetCopiesAddressCount(value) value
#define _3dcdce6b_outStatuses(value) value
#define _3dcdce6b_optionalFile(value) value
#define _3dcdce6b_optionalLine(value) value
#define _3dcdce6b_optionalUserData(value) value
#else
typedef struct _s_3dcdce6b_context { RedContext value; } _s_3dcdce6b_context;
typedef struct _s_3dcdce6b_gpu { RedHandleGpu value; } _s_3dcdce6b_gpu;
typedef struct _s_3dcdce6b_copyingSamplers { RedBool32 value; } _s_3dcdce6b_copyingSamplers;
typedef struct _s_3dcdce6b_sourceCopiesCount { unsigned value; } _s_3dcdce6b_sourceCopiesCount;
typedef struct _s_3dcdce6b_sourceCopiesAddressFirst { RedXMemoryAddress* value; } _s_3dcdce6b_sourceCopiesAddressFirst;
typedef struct _s_3dcdce6b_sourceCopiesAddressCount { unsigned* value; } _s_3dcdce6b_sourceCopiesAddressCount;
typedef struct _s_3dcdce6b_targetCopiesCount { unsigned value; } _s_3dcdce6b_targetCopiesCount;
typedef struct _s_3dcdce6b_targetCopiesAddressFirst { RedXMemoryAddress* value; } _s_3dcdce6b_targetCopiesAddressFirst;
typedef struct _s_3dcdce6b_targetCopiesAddressCount { unsigned* value; } _s_3dcdce6b_targetCopiesAddressCount;
typedef struct _s_3dcdce6b_outStatuses { RedStatuses* value; } _s_3dcdce6b_outStatuses;
typedef struct _s_3dcdce6b_optionalFile { char* value; } _s_3dcdce6b_optionalFile;
typedef struct _s_3dcdce6b_optionalLine { int value; } _s_3dcdce6b_optionalLine;
typedef struct _s_3dcdce6b_optionalUserData { void* value; } _s_3dcdce6b_optionalUserData;
static inline _s_3dcdce6b_context _3dcdce6b_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_context){value}; }
static inline _s_3dcdce6b_gpu _3dcdce6b_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_gpu){value}; }
static inline _s_3dcdce6b_copyingSamplers _3dcdce6b_copyingSamplers(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_copyingSamplers){value}; }
static inline _s_3dcdce6b_sourceCopiesCount _3dcdce6b_sourceCopiesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_sourceCopiesCount){value}; }
static inline _s_3dcdce6b_sourceCopiesAddressFirst _3dcdce6b_sourceCopiesAddressFirst(RedXMemoryAddress* value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_sourceCopiesAddressFirst){value}; }
static inline _s_3dcdce6b_sourceCopiesAddressCount _3dcdce6b_sourceCopiesAddressCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_sourceCopiesAddressCount){value}; }
static inline _s_3dcdce6b_targetCopiesCount _3dcdce6b_targetCopiesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_targetCopiesCount){value}; }
static inline _s_3dcdce6b_targetCopiesAddressFirst _3dcdce6b_targetCopiesAddressFirst(RedXMemoryAddress* value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_targetCopiesAddressFirst){value}; }
static inline _s_3dcdce6b_targetCopiesAddressCount _3dcdce6b_targetCopiesAddressCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_targetCopiesAddressCount){value}; }
static inline _s_3dcdce6b_outStatuses _3dcdce6b_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_outStatuses){value}; }
static inline _s_3dcdce6b_optionalFile _3dcdce6b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_optionalFile){value}; }
static inline _s_3dcdce6b_optionalLine _3dcdce6b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_optionalLine){value}; }
static inline _s_3dcdce6b_optionalUserData _3dcdce6b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3dcdce6b_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXStructsMemorySet(_s_3dcdce6b_context context, _s_3dcdce6b_gpu gpu, _s_3dcdce6b_copyingSamplers copyingSamplers, _s_3dcdce6b_sourceCopiesCount sourceCopiesCount, _s_3dcdce6b_sourceCopiesAddressFirst sourceCopiesAddressFirst, _s_3dcdce6b_sourceCopiesAddressCount sourceCopiesAddressCount, _s_3dcdce6b_targetCopiesCount targetCopiesCount, _s_3dcdce6b_targetCopiesAddressFirst targetCopiesAddressFirst, _s_3dcdce6b_targetCopiesAddressCount targetCopiesAddressCount, _s_3dcdce6b_outStatuses outStatuses, _s_3dcdce6b_optionalFile optionalFile, _s_3dcdce6b_optionalLine optionalLine, _s_3dcdce6b_optionalUserData optionalUserData) {
  redXStructsMemorySet(context.value, gpu.value, copyingSamplers.value, sourceCopiesCount.value, sourceCopiesAddressFirst.value, sourceCopiesAddressCount.value, targetCopiesCount.value, targetCopiesAddressFirst.value, targetCopiesAddressCount.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetHandleStruct redXGetHandleStruct
#define _9602d34e_context(value) value
#define _9602d34e_gpu(value) value
#define _9602d34e_structsMemory(value) value
#define _9602d34e_structMemberIndex(value) value
#else
typedef struct _s_9602d34e_context { RedContext value; } _s_9602d34e_context;
typedef struct _s_9602d34e_gpu { RedHandleGpu value; } _s_9602d34e_gpu;
typedef struct _s_9602d34e_structsMemory { RedHandleStructsMemory value; } _s_9602d34e_structsMemory;
typedef struct _s_9602d34e_structMemberIndex { unsigned value; } _s_9602d34e_structMemberIndex;
static inline _s_9602d34e_context _9602d34e_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_9602d34e_context){value}; }
static inline _s_9602d34e_gpu _9602d34e_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_9602d34e_gpu){value}; }
static inline _s_9602d34e_structsMemory _9602d34e_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_9602d34e_structsMemory){value}; }
static inline _s_9602d34e_structMemberIndex _9602d34e_structMemberIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9602d34e_structMemberIndex){value}; }
REDGPU_NP_DECLSPEC RedHandleStruct REDGPU_NP_API np_redXGetHandleStruct(_s_9602d34e_context context, _s_9602d34e_gpu gpu, _s_9602d34e_structsMemory structsMemory, _s_9602d34e_structMemberIndex structMemberIndex) {
  return redXGetHandleStruct(context.value, gpu.value, structsMemory.value, structMemberIndex.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCreateQueue redXCreateQueue
#define _1e0cca88_context(value) value
#define _1e0cca88_gpu(value) value
#define _1e0cca88_handleName(value) value
#define _1e0cca88_canCopy(value) value
#define _1e0cca88_canDraw(value) value
#define _1e0cca88_canCompute(value) value
#define _1e0cca88_priority(value) value
#define _1e0cca88_disableGpuTimeout(value) value
#define _1e0cca88_outStatuses(value) value
#define _1e0cca88_optionalFile(value) value
#define _1e0cca88_optionalLine(value) value
#define _1e0cca88_optionalUserData(value) value
#else
typedef struct _s_1e0cca88_context { RedContext value; } _s_1e0cca88_context;
typedef struct _s_1e0cca88_gpu { RedHandleGpu value; } _s_1e0cca88_gpu;
typedef struct _s_1e0cca88_handleName { char* value; } _s_1e0cca88_handleName;
typedef struct _s_1e0cca88_canCopy { RedBool32 value; } _s_1e0cca88_canCopy;
typedef struct _s_1e0cca88_canDraw { RedBool32 value; } _s_1e0cca88_canDraw;
typedef struct _s_1e0cca88_canCompute { RedBool32 value; } _s_1e0cca88_canCompute;
typedef struct _s_1e0cca88_priority { unsigned value; } _s_1e0cca88_priority;
typedef struct _s_1e0cca88_disableGpuTimeout { RedBool32 value; } _s_1e0cca88_disableGpuTimeout;
typedef struct _s_1e0cca88_outStatuses { RedStatuses* value; } _s_1e0cca88_outStatuses;
typedef struct _s_1e0cca88_optionalFile { char* value; } _s_1e0cca88_optionalFile;
typedef struct _s_1e0cca88_optionalLine { int value; } _s_1e0cca88_optionalLine;
typedef struct _s_1e0cca88_optionalUserData { void* value; } _s_1e0cca88_optionalUserData;
static inline _s_1e0cca88_context _1e0cca88_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_1e0cca88_context){value}; }
static inline _s_1e0cca88_gpu _1e0cca88_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_1e0cca88_gpu){value}; }
static inline _s_1e0cca88_handleName _1e0cca88_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1e0cca88_handleName){value}; }
static inline _s_1e0cca88_canCopy _1e0cca88_canCopy(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_1e0cca88_canCopy){value}; }
static inline _s_1e0cca88_canDraw _1e0cca88_canDraw(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_1e0cca88_canDraw){value}; }
static inline _s_1e0cca88_canCompute _1e0cca88_canCompute(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_1e0cca88_canCompute){value}; }
static inline _s_1e0cca88_priority _1e0cca88_priority(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1e0cca88_priority){value}; }
static inline _s_1e0cca88_disableGpuTimeout _1e0cca88_disableGpuTimeout(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_1e0cca88_disableGpuTimeout){value}; }
static inline _s_1e0cca88_outStatuses _1e0cca88_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_1e0cca88_outStatuses){value}; }
static inline _s_1e0cca88_optionalFile _1e0cca88_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1e0cca88_optionalFile){value}; }
static inline _s_1e0cca88_optionalLine _1e0cca88_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1e0cca88_optionalLine){value}; }
static inline _s_1e0cca88_optionalUserData _1e0cca88_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1e0cca88_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCreateQueue(_s_1e0cca88_context context, _s_1e0cca88_gpu gpu, _s_1e0cca88_handleName handleName, _s_1e0cca88_canCopy canCopy, _s_1e0cca88_canDraw canDraw, _s_1e0cca88_canCompute canCompute, _s_1e0cca88_priority priority, _s_1e0cca88_disableGpuTimeout disableGpuTimeout, _s_1e0cca88_outStatuses outStatuses, _s_1e0cca88_optionalFile optionalFile, _s_1e0cca88_optionalLine optionalLine, _s_1e0cca88_optionalUserData optionalUserData) {
  redXCreateQueue(context.value, gpu.value, handleName.value, canCopy.value, canDraw.value, canCompute.value, priority.value, disableGpuTimeout.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCreateImage redXCreateImage
#define _4fb53566_context(value) value
#define _4fb53566_gpu(value) value
#define _4fb53566_handleName(value) value
#define _4fb53566_dimensions(value) value
#define _4fb53566_format(value) value
#define _4fb53566_xformat(value) value
#define _4fb53566_width(value) value
#define _4fb53566_height(value) value
#define _4fb53566_depth(value) value
#define _4fb53566_levelsCount(value) value
#define _4fb53566_layersCount(value) value
#define _4fb53566_multisampleCount(value) value
#define _4fb53566_restrictToAccess(value) value
#define _4fb53566_initialAccess(value) value
#define _4fb53566_initialQueueFamilyIndex(value) value
#define _4fb53566_dedicate(value) value
#define _4fb53566_outImage(value) value
#define _4fb53566_outStatuses(value) value
#define _4fb53566_optionalFile(value) value
#define _4fb53566_optionalLine(value) value
#define _4fb53566_optionalUserData(value) value
#else
typedef struct _s_4fb53566_context { RedContext value; } _s_4fb53566_context;
typedef struct _s_4fb53566_gpu { RedHandleGpu value; } _s_4fb53566_gpu;
typedef struct _s_4fb53566_handleName { char* value; } _s_4fb53566_handleName;
typedef struct _s_4fb53566_dimensions { RedImageDimensions value; } _s_4fb53566_dimensions;
typedef struct _s_4fb53566_format { RedFormat value; } _s_4fb53566_format;
typedef struct _s_4fb53566_xformat { unsigned value; } _s_4fb53566_xformat;
typedef struct _s_4fb53566_width { unsigned value; } _s_4fb53566_width;
typedef struct _s_4fb53566_height { unsigned value; } _s_4fb53566_height;
typedef struct _s_4fb53566_depth { unsigned value; } _s_4fb53566_depth;
typedef struct _s_4fb53566_levelsCount { unsigned value; } _s_4fb53566_levelsCount;
typedef struct _s_4fb53566_layersCount { unsigned value; } _s_4fb53566_layersCount;
typedef struct _s_4fb53566_multisampleCount { RedMultisampleCountBitflag value; } _s_4fb53566_multisampleCount;
typedef struct _s_4fb53566_restrictToAccess { RedAccessBitflags value; } _s_4fb53566_restrictToAccess;
typedef struct _s_4fb53566_initialAccess { RedAccessBitflags value; } _s_4fb53566_initialAccess;
typedef struct _s_4fb53566_initialQueueFamilyIndex { unsigned value; } _s_4fb53566_initialQueueFamilyIndex;
typedef struct _s_4fb53566_dedicate { RedBool32 value; } _s_4fb53566_dedicate;
typedef struct _s_4fb53566_outImage { RedImage* value; } _s_4fb53566_outImage;
typedef struct _s_4fb53566_outStatuses { RedStatuses* value; } _s_4fb53566_outStatuses;
typedef struct _s_4fb53566_optionalFile { char* value; } _s_4fb53566_optionalFile;
typedef struct _s_4fb53566_optionalLine { int value; } _s_4fb53566_optionalLine;
typedef struct _s_4fb53566_optionalUserData { void* value; } _s_4fb53566_optionalUserData;
static inline _s_4fb53566_context _4fb53566_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_context){value}; }
static inline _s_4fb53566_gpu _4fb53566_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_gpu){value}; }
static inline _s_4fb53566_handleName _4fb53566_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_handleName){value}; }
static inline _s_4fb53566_dimensions _4fb53566_dimensions(RedImageDimensions value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_dimensions){value}; }
static inline _s_4fb53566_format _4fb53566_format(RedFormat value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_format){value}; }
static inline _s_4fb53566_xformat _4fb53566_xformat(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_xformat){value}; }
static inline _s_4fb53566_width _4fb53566_width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_width){value}; }
static inline _s_4fb53566_height _4fb53566_height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_height){value}; }
static inline _s_4fb53566_depth _4fb53566_depth(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_depth){value}; }
static inline _s_4fb53566_levelsCount _4fb53566_levelsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_levelsCount){value}; }
static inline _s_4fb53566_layersCount _4fb53566_layersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_layersCount){value}; }
static inline _s_4fb53566_multisampleCount _4fb53566_multisampleCount(RedMultisampleCountBitflag value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_multisampleCount){value}; }
static inline _s_4fb53566_restrictToAccess _4fb53566_restrictToAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_restrictToAccess){value}; }
static inline _s_4fb53566_initialAccess _4fb53566_initialAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_initialAccess){value}; }
static inline _s_4fb53566_initialQueueFamilyIndex _4fb53566_initialQueueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_initialQueueFamilyIndex){value}; }
static inline _s_4fb53566_dedicate _4fb53566_dedicate(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_dedicate){value}; }
static inline _s_4fb53566_outImage _4fb53566_outImage(RedImage* value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_outImage){value}; }
static inline _s_4fb53566_outStatuses _4fb53566_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_outStatuses){value}; }
static inline _s_4fb53566_optionalFile _4fb53566_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_optionalFile){value}; }
static inline _s_4fb53566_optionalLine _4fb53566_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_optionalLine){value}; }
static inline _s_4fb53566_optionalUserData _4fb53566_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4fb53566_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCreateImage(_s_4fb53566_context context, _s_4fb53566_gpu gpu, _s_4fb53566_handleName handleName, _s_4fb53566_dimensions dimensions, _s_4fb53566_format format, _s_4fb53566_xformat xformat, _s_4fb53566_width width, _s_4fb53566_height height, _s_4fb53566_depth depth, _s_4fb53566_levelsCount levelsCount, _s_4fb53566_layersCount layersCount, _s_4fb53566_multisampleCount multisampleCount, _s_4fb53566_restrictToAccess restrictToAccess, _s_4fb53566_initialAccess initialAccess, _s_4fb53566_initialQueueFamilyIndex initialQueueFamilyIndex, _s_4fb53566_dedicate dedicate, _s_4fb53566_outImage outImage, _s_4fb53566_outStatuses outStatuses, _s_4fb53566_optionalFile optionalFile, _s_4fb53566_optionalLine optionalLine, _s_4fb53566_optionalUserData optionalUserData) {
  redXCreateImage(context.value, gpu.value, handleName.value, dimensions.value, format.value, xformat.value, width.value, height.value, depth.value, levelsCount.value, layersCount.value, multisampleCount.value, restrictToAccess.value, initialAccess.value, initialQueueFamilyIndex.value, dedicate.value, outImage.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCreateTexture redXCreateTexture
#define _234f1aab_context(value) value
#define _234f1aab_gpu(value) value
#define _234f1aab_handleName(value) value
#define _234f1aab_image(value) value
#define _234f1aab_parts(value) value
#define _234f1aab_dimensions(value) value
#define _234f1aab_format(value) value
#define _234f1aab_xformat(value) value
#define _234f1aab_levelsFirst(value) value
#define _234f1aab_levelsCount(value) value
#define _234f1aab_layersFirst(value) value
#define _234f1aab_layersCount(value) value
#define _234f1aab_restrictToAccess(value) value
#define _234f1aab_outTexture(value) value
#define _234f1aab_outStatuses(value) value
#define _234f1aab_optionalFile(value) value
#define _234f1aab_optionalLine(value) value
#define _234f1aab_optionalUserData(value) value
#else
typedef struct _s_234f1aab_context { RedContext value; } _s_234f1aab_context;
typedef struct _s_234f1aab_gpu { RedHandleGpu value; } _s_234f1aab_gpu;
typedef struct _s_234f1aab_handleName { char* value; } _s_234f1aab_handleName;
typedef struct _s_234f1aab_image { RedHandleImage value; } _s_234f1aab_image;
typedef struct _s_234f1aab_parts { RedImagePartBitflags value; } _s_234f1aab_parts;
typedef struct _s_234f1aab_dimensions { RedTextureDimensions value; } _s_234f1aab_dimensions;
typedef struct _s_234f1aab_format { RedFormat value; } _s_234f1aab_format;
typedef struct _s_234f1aab_xformat { unsigned value; } _s_234f1aab_xformat;
typedef struct _s_234f1aab_levelsFirst { unsigned value; } _s_234f1aab_levelsFirst;
typedef struct _s_234f1aab_levelsCount { unsigned value; } _s_234f1aab_levelsCount;
typedef struct _s_234f1aab_layersFirst { unsigned value; } _s_234f1aab_layersFirst;
typedef struct _s_234f1aab_layersCount { unsigned value; } _s_234f1aab_layersCount;
typedef struct _s_234f1aab_restrictToAccess { RedAccessBitflags value; } _s_234f1aab_restrictToAccess;
typedef struct _s_234f1aab_outTexture { RedHandleTexture* value; } _s_234f1aab_outTexture;
typedef struct _s_234f1aab_outStatuses { RedStatuses* value; } _s_234f1aab_outStatuses;
typedef struct _s_234f1aab_optionalFile { char* value; } _s_234f1aab_optionalFile;
typedef struct _s_234f1aab_optionalLine { int value; } _s_234f1aab_optionalLine;
typedef struct _s_234f1aab_optionalUserData { void* value; } _s_234f1aab_optionalUserData;
static inline _s_234f1aab_context _234f1aab_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_context){value}; }
static inline _s_234f1aab_gpu _234f1aab_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_gpu){value}; }
static inline _s_234f1aab_handleName _234f1aab_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_handleName){value}; }
static inline _s_234f1aab_image _234f1aab_image(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_image){value}; }
static inline _s_234f1aab_parts _234f1aab_parts(RedImagePartBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_parts){value}; }
static inline _s_234f1aab_dimensions _234f1aab_dimensions(RedTextureDimensions value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_dimensions){value}; }
static inline _s_234f1aab_format _234f1aab_format(RedFormat value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_format){value}; }
static inline _s_234f1aab_xformat _234f1aab_xformat(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_xformat){value}; }
static inline _s_234f1aab_levelsFirst _234f1aab_levelsFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_levelsFirst){value}; }
static inline _s_234f1aab_levelsCount _234f1aab_levelsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_levelsCount){value}; }
static inline _s_234f1aab_layersFirst _234f1aab_layersFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_layersFirst){value}; }
static inline _s_234f1aab_layersCount _234f1aab_layersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_layersCount){value}; }
static inline _s_234f1aab_restrictToAccess _234f1aab_restrictToAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_restrictToAccess){value}; }
static inline _s_234f1aab_outTexture _234f1aab_outTexture(RedHandleTexture* value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_outTexture){value}; }
static inline _s_234f1aab_outStatuses _234f1aab_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_outStatuses){value}; }
static inline _s_234f1aab_optionalFile _234f1aab_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_optionalFile){value}; }
static inline _s_234f1aab_optionalLine _234f1aab_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_optionalLine){value}; }
static inline _s_234f1aab_optionalUserData _234f1aab_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_234f1aab_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCreateTexture(_s_234f1aab_context context, _s_234f1aab_gpu gpu, _s_234f1aab_handleName handleName, _s_234f1aab_image image, _s_234f1aab_parts parts, _s_234f1aab_dimensions dimensions, _s_234f1aab_format format, _s_234f1aab_xformat xformat, _s_234f1aab_levelsFirst levelsFirst, _s_234f1aab_levelsCount levelsCount, _s_234f1aab_layersFirst layersFirst, _s_234f1aab_layersCount layersCount, _s_234f1aab_restrictToAccess restrictToAccess, _s_234f1aab_outTexture outTexture, _s_234f1aab_outStatuses outStatuses, _s_234f1aab_optionalFile optionalFile, _s_234f1aab_optionalLine optionalLine, _s_234f1aab_optionalUserData optionalUserData) {
  redXCreateTexture(context.value, gpu.value, handleName.value, image.value, parts.value, dimensions.value, format.value, xformat.value, levelsFirst.value, levelsCount.value, layersFirst.value, layersCount.value, restrictToAccess.value, outTexture.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetHandlePageableMemory redXGetHandlePageableMemory
#define _0adde1cf_context(value) value
#define _0adde1cf_gpu(value) value
#define _0adde1cf_memory(value) value
#else
typedef struct _s_0adde1cf_context { RedContext value; } _s_0adde1cf_context;
typedef struct _s_0adde1cf_gpu { RedHandleGpu value; } _s_0adde1cf_gpu;
typedef struct _s_0adde1cf_memory { RedHandleMemory value; } _s_0adde1cf_memory;
static inline _s_0adde1cf_context _0adde1cf_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_0adde1cf_context){value}; }
static inline _s_0adde1cf_gpu _0adde1cf_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_0adde1cf_gpu){value}; }
static inline _s_0adde1cf_memory _0adde1cf_memory(RedHandleMemory value) { return REDGPU_NP_STRUCT_INIT(_s_0adde1cf_memory){value}; }
REDGPU_NP_DECLSPEC RedXHandlePageable REDGPU_NP_API np_redXGetHandlePageableMemory(_s_0adde1cf_context context, _s_0adde1cf_gpu gpu, _s_0adde1cf_memory memory) {
  return redXGetHandlePageableMemory(context.value, gpu.value, memory.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetHandlePageableStructsMemory redXGetHandlePageableStructsMemory
#define _0cbc734b_context(value) value
#define _0cbc734b_gpu(value) value
#define _0cbc734b_structsMemory(value) value
#else
typedef struct _s_0cbc734b_context { RedContext value; } _s_0cbc734b_context;
typedef struct _s_0cbc734b_gpu { RedHandleGpu value; } _s_0cbc734b_gpu;
typedef struct _s_0cbc734b_structsMemory { RedHandleStructsMemory value; } _s_0cbc734b_structsMemory;
static inline _s_0cbc734b_context _0cbc734b_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_0cbc734b_context){value}; }
static inline _s_0cbc734b_gpu _0cbc734b_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_0cbc734b_gpu){value}; }
static inline _s_0cbc734b_structsMemory _0cbc734b_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_0cbc734b_structsMemory){value}; }
REDGPU_NP_DECLSPEC RedXHandlePageable REDGPU_NP_API np_redXGetHandlePageableStructsMemory(_s_0cbc734b_context context, _s_0cbc734b_gpu gpu, _s_0cbc734b_structsMemory structsMemory) {
  return redXGetHandlePageableStructsMemory(context.value, gpu.value, structsMemory.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXPageableSetResidencyPriority redXPageableSetResidencyPriority
#define _200557c8_context(value) value
#define _200557c8_gpu(value) value
#define _200557c8_pageablesCount(value) value
#define _200557c8_pageables(value) value
#define _200557c8_pageablesResidencyPriority(value) value
#define _200557c8_outStatuses(value) value
#define _200557c8_optionalFile(value) value
#define _200557c8_optionalLine(value) value
#define _200557c8_optionalUserData(value) value
#else
typedef struct _s_200557c8_context { RedContext value; } _s_200557c8_context;
typedef struct _s_200557c8_gpu { RedHandleGpu value; } _s_200557c8_gpu;
typedef struct _s_200557c8_pageablesCount { unsigned value; } _s_200557c8_pageablesCount;
typedef struct _s_200557c8_pageables { RedXHandlePageable* value; } _s_200557c8_pageables;
typedef struct _s_200557c8_pageablesResidencyPriority { RedXPageableResidencyPriorityBitflags* value; } _s_200557c8_pageablesResidencyPriority;
typedef struct _s_200557c8_outStatuses { RedStatuses* value; } _s_200557c8_outStatuses;
typedef struct _s_200557c8_optionalFile { char* value; } _s_200557c8_optionalFile;
typedef struct _s_200557c8_optionalLine { int value; } _s_200557c8_optionalLine;
typedef struct _s_200557c8_optionalUserData { void* value; } _s_200557c8_optionalUserData;
static inline _s_200557c8_context _200557c8_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_200557c8_context){value}; }
static inline _s_200557c8_gpu _200557c8_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_200557c8_gpu){value}; }
static inline _s_200557c8_pageablesCount _200557c8_pageablesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_200557c8_pageablesCount){value}; }
static inline _s_200557c8_pageables _200557c8_pageables(RedXHandlePageable* value) { return REDGPU_NP_STRUCT_INIT(_s_200557c8_pageables){value}; }
static inline _s_200557c8_pageablesResidencyPriority _200557c8_pageablesResidencyPriority(RedXPageableResidencyPriorityBitflags* value) { return REDGPU_NP_STRUCT_INIT(_s_200557c8_pageablesResidencyPriority){value}; }
static inline _s_200557c8_outStatuses _200557c8_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_200557c8_outStatuses){value}; }
static inline _s_200557c8_optionalFile _200557c8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_200557c8_optionalFile){value}; }
static inline _s_200557c8_optionalLine _200557c8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_200557c8_optionalLine){value}; }
static inline _s_200557c8_optionalUserData _200557c8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_200557c8_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXPageableSetResidencyPriority(_s_200557c8_context context, _s_200557c8_gpu gpu, _s_200557c8_pageablesCount pageablesCount, _s_200557c8_pageables pageables, _s_200557c8_pageablesResidencyPriority pageablesResidencyPriority, _s_200557c8_outStatuses outStatuses, _s_200557c8_optionalFile optionalFile, _s_200557c8_optionalLine optionalLine, _s_200557c8_optionalUserData optionalUserData) {
  redXPageableSetResidencyPriority(context.value, gpu.value, pageablesCount.value, pageables.value, pageablesResidencyPriority.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXPageableMakeResident redXPageableMakeResident
#define _a07ba16a_context(value) value
#define _a07ba16a_gpu(value) value
#define _a07ba16a_pageablesCount(value) value
#define _a07ba16a_pageables(value) value
#define _a07ba16a_denyOverbudget(value) value
#define _a07ba16a_signalCpuSignal(value) value
#define _a07ba16a_outStatuses(value) value
#define _a07ba16a_optionalFile(value) value
#define _a07ba16a_optionalLine(value) value
#define _a07ba16a_optionalUserData(value) value
#else
typedef struct _s_a07ba16a_context { RedContext value; } _s_a07ba16a_context;
typedef struct _s_a07ba16a_gpu { RedHandleGpu value; } _s_a07ba16a_gpu;
typedef struct _s_a07ba16a_pageablesCount { unsigned value; } _s_a07ba16a_pageablesCount;
typedef struct _s_a07ba16a_pageables { RedXHandlePageable* value; } _s_a07ba16a_pageables;
typedef struct _s_a07ba16a_denyOverbudget { RedBool32 value; } _s_a07ba16a_denyOverbudget;
typedef struct _s_a07ba16a_signalCpuSignal { RedHandleCpuSignal value; } _s_a07ba16a_signalCpuSignal;
typedef struct _s_a07ba16a_outStatuses { RedStatuses* value; } _s_a07ba16a_outStatuses;
typedef struct _s_a07ba16a_optionalFile { char* value; } _s_a07ba16a_optionalFile;
typedef struct _s_a07ba16a_optionalLine { int value; } _s_a07ba16a_optionalLine;
typedef struct _s_a07ba16a_optionalUserData { void* value; } _s_a07ba16a_optionalUserData;
static inline _s_a07ba16a_context _a07ba16a_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_a07ba16a_context){value}; }
static inline _s_a07ba16a_gpu _a07ba16a_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_a07ba16a_gpu){value}; }
static inline _s_a07ba16a_pageablesCount _a07ba16a_pageablesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a07ba16a_pageablesCount){value}; }
static inline _s_a07ba16a_pageables _a07ba16a_pageables(RedXHandlePageable* value) { return REDGPU_NP_STRUCT_INIT(_s_a07ba16a_pageables){value}; }
static inline _s_a07ba16a_denyOverbudget _a07ba16a_denyOverbudget(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_a07ba16a_denyOverbudget){value}; }
static inline _s_a07ba16a_signalCpuSignal _a07ba16a_signalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_a07ba16a_signalCpuSignal){value}; }
static inline _s_a07ba16a_outStatuses _a07ba16a_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_a07ba16a_outStatuses){value}; }
static inline _s_a07ba16a_optionalFile _a07ba16a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a07ba16a_optionalFile){value}; }
static inline _s_a07ba16a_optionalLine _a07ba16a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a07ba16a_optionalLine){value}; }
static inline _s_a07ba16a_optionalUserData _a07ba16a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a07ba16a_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXPageableMakeResident(_s_a07ba16a_context context, _s_a07ba16a_gpu gpu, _s_a07ba16a_pageablesCount pageablesCount, _s_a07ba16a_pageables pageables, _s_a07ba16a_denyOverbudget denyOverbudget, _s_a07ba16a_signalCpuSignal signalCpuSignal, _s_a07ba16a_outStatuses outStatuses, _s_a07ba16a_optionalFile optionalFile, _s_a07ba16a_optionalLine optionalLine, _s_a07ba16a_optionalUserData optionalUserData) {
  redXPageableMakeResident(context.value, gpu.value, pageablesCount.value, pageables.value, denyOverbudget.value, signalCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXPageableEvict redXPageableEvict
#define _b3895485_context(value) value
#define _b3895485_gpu(value) value
#define _b3895485_pageablesCount(value) value
#define _b3895485_pageables(value) value
#define _b3895485_outStatuses(value) value
#define _b3895485_optionalFile(value) value
#define _b3895485_optionalLine(value) value
#define _b3895485_optionalUserData(value) value
#else
typedef struct _s_b3895485_context { RedContext value; } _s_b3895485_context;
typedef struct _s_b3895485_gpu { RedHandleGpu value; } _s_b3895485_gpu;
typedef struct _s_b3895485_pageablesCount { unsigned value; } _s_b3895485_pageablesCount;
typedef struct _s_b3895485_pageables { RedXHandlePageable* value; } _s_b3895485_pageables;
typedef struct _s_b3895485_outStatuses { RedStatuses* value; } _s_b3895485_outStatuses;
typedef struct _s_b3895485_optionalFile { char* value; } _s_b3895485_optionalFile;
typedef struct _s_b3895485_optionalLine { int value; } _s_b3895485_optionalLine;
typedef struct _s_b3895485_optionalUserData { void* value; } _s_b3895485_optionalUserData;
static inline _s_b3895485_context _b3895485_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b3895485_context){value}; }
static inline _s_b3895485_gpu _b3895485_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b3895485_gpu){value}; }
static inline _s_b3895485_pageablesCount _b3895485_pageablesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b3895485_pageablesCount){value}; }
static inline _s_b3895485_pageables _b3895485_pageables(RedXHandlePageable* value) { return REDGPU_NP_STRUCT_INIT(_s_b3895485_pageables){value}; }
static inline _s_b3895485_outStatuses _b3895485_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b3895485_outStatuses){value}; }
static inline _s_b3895485_optionalFile _b3895485_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b3895485_optionalFile){value}; }
static inline _s_b3895485_optionalLine _b3895485_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b3895485_optionalLine){value}; }
static inline _s_b3895485_optionalUserData _b3895485_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b3895485_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXPageableEvict(_s_b3895485_context context, _s_b3895485_gpu gpu, _s_b3895485_pageablesCount pageablesCount, _s_b3895485_pageables pageables, _s_b3895485_outStatuses outStatuses, _s_b3895485_optionalFile optionalFile, _s_b3895485_optionalLine optionalLine, _s_b3895485_optionalUserData optionalUserData) {
  redXPageableEvict(context.value, gpu.value, pageablesCount.value, pageables.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetHandleResourceArray redXGetHandleResourceArray
#define _03176528_context(value) value
#define _03176528_gpu(value) value
#define _03176528_array(value) value
#else
typedef struct _s_03176528_context { RedContext value; } _s_03176528_context;
typedef struct _s_03176528_gpu { RedHandleGpu value; } _s_03176528_gpu;
typedef struct _s_03176528_array { RedHandleArray value; } _s_03176528_array;
static inline _s_03176528_context _03176528_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_03176528_context){value}; }
static inline _s_03176528_gpu _03176528_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_03176528_gpu){value}; }
static inline _s_03176528_array _03176528_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_03176528_array){value}; }
REDGPU_NP_DECLSPEC RedXHandleResource REDGPU_NP_API np_redXGetHandleResourceArray(_s_03176528_context context, _s_03176528_gpu gpu, _s_03176528_array array) {
  return redXGetHandleResourceArray(context.value, gpu.value, array.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXGetHandleResourceImage redXGetHandleResourceImage
#define _53ebaa34_context(value) value
#define _53ebaa34_gpu(value) value
#define _53ebaa34_image(value) value
#else
typedef struct _s_53ebaa34_context { RedContext value; } _s_53ebaa34_context;
typedef struct _s_53ebaa34_gpu { RedHandleGpu value; } _s_53ebaa34_gpu;
typedef struct _s_53ebaa34_image { RedHandleImage value; } _s_53ebaa34_image;
static inline _s_53ebaa34_context _53ebaa34_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_53ebaa34_context){value}; }
static inline _s_53ebaa34_gpu _53ebaa34_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_53ebaa34_gpu){value}; }
static inline _s_53ebaa34_image _53ebaa34_image(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_53ebaa34_image){value}; }
REDGPU_NP_DECLSPEC RedXHandleResource REDGPU_NP_API np_redXGetHandleResourceImage(_s_53ebaa34_context context, _s_53ebaa34_gpu gpu, _s_53ebaa34_image image) {
  return redXGetHandleResourceImage(context.value, gpu.value, image.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCallSetProcedureOutput redXCallSetProcedureOutput
#define _aaf4b6e6_calls(value) value
#define _aaf4b6e6_depthStencil(value) value
#define _aaf4b6e6_colorsCount(value) value
#define _aaf4b6e6_colors(value) value
#define _aaf4b6e6_depthSetProcedureOutputOp(value) value
#define _aaf4b6e6_stencilSetProcedureOutputOp(value) value
#define _aaf4b6e6_colorsSetProcedureOutputOp(value) value
#define _aaf4b6e6_depthClearValue(value) value
#define _aaf4b6e6_stencilClearValue(value) value
#define _aaf4b6e6_colorsClearValuesFloat(value) value
#else
typedef struct _s_aaf4b6e6_calls { RedHandleCalls value; } _s_aaf4b6e6_calls;
typedef struct _s_aaf4b6e6_depthStencil { RedHandleTexture value; } _s_aaf4b6e6_depthStencil;
typedef struct _s_aaf4b6e6_colorsCount { unsigned value; } _s_aaf4b6e6_colorsCount;
typedef struct _s_aaf4b6e6_colors { RedHandleTexture* value; } _s_aaf4b6e6_colors;
typedef struct _s_aaf4b6e6_depthSetProcedureOutputOp { RedSetProcedureOutputOp value; } _s_aaf4b6e6_depthSetProcedureOutputOp;
typedef struct _s_aaf4b6e6_stencilSetProcedureOutputOp { RedSetProcedureOutputOp value; } _s_aaf4b6e6_stencilSetProcedureOutputOp;
typedef struct _s_aaf4b6e6_colorsSetProcedureOutputOp { RedSetProcedureOutputOp* value; } _s_aaf4b6e6_colorsSetProcedureOutputOp;
typedef struct _s_aaf4b6e6_depthClearValue { float value; } _s_aaf4b6e6_depthClearValue;
typedef struct _s_aaf4b6e6_stencilClearValue { unsigned value; } _s_aaf4b6e6_stencilClearValue;
typedef struct _s_aaf4b6e6_colorsClearValuesFloat { RedColorsClearValuesFloat* value; } _s_aaf4b6e6_colorsClearValuesFloat;
static inline _s_aaf4b6e6_calls _aaf4b6e6_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_aaf4b6e6_calls){value}; }
static inline _s_aaf4b6e6_depthStencil _aaf4b6e6_depthStencil(RedHandleTexture value) { return REDGPU_NP_STRUCT_INIT(_s_aaf4b6e6_depthStencil){value}; }
static inline _s_aaf4b6e6_colorsCount _aaf4b6e6_colorsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_aaf4b6e6_colorsCount){value}; }
static inline _s_aaf4b6e6_colors _aaf4b6e6_colors(RedHandleTexture* value) { return REDGPU_NP_STRUCT_INIT(_s_aaf4b6e6_colors){value}; }
static inline _s_aaf4b6e6_depthSetProcedureOutputOp _aaf4b6e6_depthSetProcedureOutputOp(RedSetProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_aaf4b6e6_depthSetProcedureOutputOp){value}; }
static inline _s_aaf4b6e6_stencilSetProcedureOutputOp _aaf4b6e6_stencilSetProcedureOutputOp(RedSetProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_aaf4b6e6_stencilSetProcedureOutputOp){value}; }
static inline _s_aaf4b6e6_colorsSetProcedureOutputOp _aaf4b6e6_colorsSetProcedureOutputOp(RedSetProcedureOutputOp* value) { return REDGPU_NP_STRUCT_INIT(_s_aaf4b6e6_colorsSetProcedureOutputOp){value}; }
static inline _s_aaf4b6e6_depthClearValue _aaf4b6e6_depthClearValue(float value) { return REDGPU_NP_STRUCT_INIT(_s_aaf4b6e6_depthClearValue){value}; }
static inline _s_aaf4b6e6_stencilClearValue _aaf4b6e6_stencilClearValue(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_aaf4b6e6_stencilClearValue){value}; }
static inline _s_aaf4b6e6_colorsClearValuesFloat _aaf4b6e6_colorsClearValuesFloat(RedColorsClearValuesFloat* value) { return REDGPU_NP_STRUCT_INIT(_s_aaf4b6e6_colorsClearValuesFloat){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCallSetProcedureOutput(_s_aaf4b6e6_calls calls, _s_aaf4b6e6_depthStencil depthStencil, _s_aaf4b6e6_colorsCount colorsCount, _s_aaf4b6e6_colors colors, _s_aaf4b6e6_depthSetProcedureOutputOp depthSetProcedureOutputOp, _s_aaf4b6e6_stencilSetProcedureOutputOp stencilSetProcedureOutputOp, _s_aaf4b6e6_colorsSetProcedureOutputOp colorsSetProcedureOutputOp, _s_aaf4b6e6_depthClearValue depthClearValue, _s_aaf4b6e6_stencilClearValue stencilClearValue, _s_aaf4b6e6_colorsClearValuesFloat colorsClearValuesFloat) {
  redXCallSetProcedureOutput(calls.value, depthStencil.value, colorsCount.value, colors.value, depthSetProcedureOutputOp.value, stencilSetProcedureOutputOp.value, colorsSetProcedureOutputOp.value, depthClearValue.value, stencilClearValue.value, colorsClearValuesFloat.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCallEndProcedureOutput redXCallEndProcedureOutput
#define _960ea83b_calls(value) value
#define _960ea83b_resolveTargetColors(value) value
#define _960ea83b_resolveTargetColorsFormat(value) value
#define _960ea83b_depthEndProcedureOutputOp(value) value
#define _960ea83b_stencilEndProcedureOutputOp(value) value
#define _960ea83b_colorsEndProcedureOutputOp(value) value
#else
typedef struct _s_960ea83b_calls { RedHandleCalls value; } _s_960ea83b_calls;
typedef struct _s_960ea83b_resolveTargetColors { RedHandleTexture* value; } _s_960ea83b_resolveTargetColors;
typedef struct _s_960ea83b_resolveTargetColorsFormat { unsigned* value; } _s_960ea83b_resolveTargetColorsFormat;
typedef struct _s_960ea83b_depthEndProcedureOutputOp { RedEndProcedureOutputOp value; } _s_960ea83b_depthEndProcedureOutputOp;
typedef struct _s_960ea83b_stencilEndProcedureOutputOp { RedEndProcedureOutputOp value; } _s_960ea83b_stencilEndProcedureOutputOp;
typedef struct _s_960ea83b_colorsEndProcedureOutputOp { RedEndProcedureOutputOp* value; } _s_960ea83b_colorsEndProcedureOutputOp;
static inline _s_960ea83b_calls _960ea83b_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_960ea83b_calls){value}; }
static inline _s_960ea83b_resolveTargetColors _960ea83b_resolveTargetColors(RedHandleTexture* value) { return REDGPU_NP_STRUCT_INIT(_s_960ea83b_resolveTargetColors){value}; }
static inline _s_960ea83b_resolveTargetColorsFormat _960ea83b_resolveTargetColorsFormat(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_960ea83b_resolveTargetColorsFormat){value}; }
static inline _s_960ea83b_depthEndProcedureOutputOp _960ea83b_depthEndProcedureOutputOp(RedEndProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_960ea83b_depthEndProcedureOutputOp){value}; }
static inline _s_960ea83b_stencilEndProcedureOutputOp _960ea83b_stencilEndProcedureOutputOp(RedEndProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_960ea83b_stencilEndProcedureOutputOp){value}; }
static inline _s_960ea83b_colorsEndProcedureOutputOp _960ea83b_colorsEndProcedureOutputOp(RedEndProcedureOutputOp* value) { return REDGPU_NP_STRUCT_INIT(_s_960ea83b_colorsEndProcedureOutputOp){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCallEndProcedureOutput(_s_960ea83b_calls calls, _s_960ea83b_resolveTargetColors resolveTargetColors, _s_960ea83b_resolveTargetColorsFormat resolveTargetColorsFormat, _s_960ea83b_depthEndProcedureOutputOp depthEndProcedureOutputOp, _s_960ea83b_stencilEndProcedureOutputOp stencilEndProcedureOutputOp, _s_960ea83b_colorsEndProcedureOutputOp colorsEndProcedureOutputOp) {
  redXCallEndProcedureOutput(calls.value, resolveTargetColors.value, resolveTargetColorsFormat.value, depthEndProcedureOutputOp.value, stencilEndProcedureOutputOp.value, colorsEndProcedureOutputOp.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCallUsageAliasOrderBarrier redXCallUsageAliasOrderBarrier
#define _c422a5bf_calls(value) value
#define _c422a5bf_barriersCount(value) value
#define _c422a5bf_barriers(value) value
#else
typedef struct _s_c422a5bf_calls { RedHandleCalls value; } _s_c422a5bf_calls;
typedef struct _s_c422a5bf_barriersCount { unsigned value; } _s_c422a5bf_barriersCount;
typedef struct _s_c422a5bf_barriers { void* value; } _s_c422a5bf_barriers;
static inline _s_c422a5bf_calls _c422a5bf_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_c422a5bf_calls){value}; }
static inline _s_c422a5bf_barriersCount _c422a5bf_barriersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c422a5bf_barriersCount){value}; }
static inline _s_c422a5bf_barriers _c422a5bf_barriers(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c422a5bf_barriers){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCallUsageAliasOrderBarrier(_s_c422a5bf_calls calls, _s_c422a5bf_barriersCount barriersCount, _s_c422a5bf_barriers barriers) {
  redXCallUsageAliasOrderBarrier(calls.value, barriersCount.value, barriers.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCallCopyImageRegion redXCallCopyImageRegion
#define _89a23d6d_calls(value) value
#define _89a23d6d_copiesCount(value) value
#define _89a23d6d_copies(value) value
#else
typedef struct _s_89a23d6d_calls { RedHandleCalls value; } _s_89a23d6d_calls;
typedef struct _s_89a23d6d_copiesCount { unsigned value; } _s_89a23d6d_copiesCount;
typedef struct _s_89a23d6d_copies { void* value; } _s_89a23d6d_copies;
static inline _s_89a23d6d_calls _89a23d6d_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_89a23d6d_calls){value}; }
static inline _s_89a23d6d_copiesCount _89a23d6d_copiesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_89a23d6d_copiesCount){value}; }
static inline _s_89a23d6d_copies _89a23d6d_copies(void* value) { return REDGPU_NP_STRUCT_INIT(_s_89a23d6d_copies){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCallCopyImageRegion(_s_89a23d6d_calls calls, _s_89a23d6d_copiesCount copiesCount, _s_89a23d6d_copies copies) {
  redXCallCopyImageRegion(calls.value, copiesCount.value, copies.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXCreateSurfaceWinRT redXCreateSurfaceWinRT
#define _7512bf95_context(value) value
#define _7512bf95_gpu(value) value
#define _7512bf95_handleName(value) value
#define _7512bf95_winrtIUnknownPointerCoreWindow(value) value
#define _7512bf95_outSurface(value) value
#define _7512bf95_outStatuses(value) value
#define _7512bf95_optionalFile(value) value
#define _7512bf95_optionalLine(value) value
#define _7512bf95_optionalUserData(value) value
#else
typedef struct _s_7512bf95_context { RedContext value; } _s_7512bf95_context;
typedef struct _s_7512bf95_gpu { RedHandleGpu value; } _s_7512bf95_gpu;
typedef struct _s_7512bf95_handleName { char* value; } _s_7512bf95_handleName;
typedef struct _s_7512bf95_winrtIUnknownPointerCoreWindow { void* value; } _s_7512bf95_winrtIUnknownPointerCoreWindow;
typedef struct _s_7512bf95_outSurface { RedHandleSurface* value; } _s_7512bf95_outSurface;
typedef struct _s_7512bf95_outStatuses { RedStatuses* value; } _s_7512bf95_outStatuses;
typedef struct _s_7512bf95_optionalFile { char* value; } _s_7512bf95_optionalFile;
typedef struct _s_7512bf95_optionalLine { int value; } _s_7512bf95_optionalLine;
typedef struct _s_7512bf95_optionalUserData { void* value; } _s_7512bf95_optionalUserData;
static inline _s_7512bf95_context _7512bf95_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_7512bf95_context){value}; }
static inline _s_7512bf95_gpu _7512bf95_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_7512bf95_gpu){value}; }
static inline _s_7512bf95_handleName _7512bf95_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7512bf95_handleName){value}; }
static inline _s_7512bf95_winrtIUnknownPointerCoreWindow _7512bf95_winrtIUnknownPointerCoreWindow(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7512bf95_winrtIUnknownPointerCoreWindow){value}; }
static inline _s_7512bf95_outSurface _7512bf95_outSurface(RedHandleSurface* value) { return REDGPU_NP_STRUCT_INIT(_s_7512bf95_outSurface){value}; }
static inline _s_7512bf95_outStatuses _7512bf95_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_7512bf95_outStatuses){value}; }
static inline _s_7512bf95_optionalFile _7512bf95_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7512bf95_optionalFile){value}; }
static inline _s_7512bf95_optionalLine _7512bf95_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7512bf95_optionalLine){value}; }
static inline _s_7512bf95_optionalUserData _7512bf95_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7512bf95_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXCreateSurfaceWinRT(_s_7512bf95_context context, _s_7512bf95_gpu gpu, _s_7512bf95_handleName handleName, _s_7512bf95_winrtIUnknownPointerCoreWindow winrtIUnknownPointerCoreWindow, _s_7512bf95_outSurface outSurface, _s_7512bf95_outStatuses outStatuses, _s_7512bf95_optionalFile optionalFile, _s_7512bf95_optionalLine optionalLine, _s_7512bf95_optionalUserData optionalUserData) {
  redXCreateSurfaceWinRT(context.value, gpu.value, handleName.value, winrtIUnknownPointerCoreWindow.value, outSurface.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

