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
#define np_redMemoryGetBudget redMemoryGetBudget
#define _9b481c8c_context(value) value
#define _9b481c8c_gpu(value) value
#define _9b481c8c_outMemoryBudget(value) value
#define _9b481c8c_outStatuses(value) value
#define _9b481c8c_optionalFile(value) value
#define _9b481c8c_optionalLine(value) value
#define _9b481c8c_optionalUserData(value) value
#else
typedef struct _s_9b481c8c_context { RedContext value; } _s_9b481c8c_context;
typedef struct _s_9b481c8c_gpu { RedHandleGpu value; } _s_9b481c8c_gpu;
typedef struct _s_9b481c8c_outMemoryBudget { RedMemoryBudget* value; } _s_9b481c8c_outMemoryBudget;
typedef struct _s_9b481c8c_outStatuses { RedStatuses* value; } _s_9b481c8c_outStatuses;
typedef struct _s_9b481c8c_optionalFile { char* value; } _s_9b481c8c_optionalFile;
typedef struct _s_9b481c8c_optionalLine { int value; } _s_9b481c8c_optionalLine;
typedef struct _s_9b481c8c_optionalUserData { void* value; } _s_9b481c8c_optionalUserData;
static inline _s_9b481c8c_context _9b481c8c_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_9b481c8c_context){value}; }
static inline _s_9b481c8c_gpu _9b481c8c_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_9b481c8c_gpu){value}; }
static inline _s_9b481c8c_outMemoryBudget _9b481c8c_outMemoryBudget(RedMemoryBudget* value) { return REDGPU_NP_STRUCT_INIT(_s_9b481c8c_outMemoryBudget){value}; }
static inline _s_9b481c8c_outStatuses _9b481c8c_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_9b481c8c_outStatuses){value}; }
static inline _s_9b481c8c_optionalFile _9b481c8c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9b481c8c_optionalFile){value}; }
static inline _s_9b481c8c_optionalLine _9b481c8c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9b481c8c_optionalLine){value}; }
static inline _s_9b481c8c_optionalUserData _9b481c8c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9b481c8c_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryGetBudget(_s_9b481c8c_context context, _s_9b481c8c_gpu gpu, _s_9b481c8c_outMemoryBudget outMemoryBudget, _s_9b481c8c_outStatuses outStatuses, _s_9b481c8c_optionalFile optionalFile, _s_9b481c8c_optionalLine optionalLine, _s_9b481c8c_optionalUserData optionalUserData) {
  redMemoryGetBudget(context.value, gpu.value, outMemoryBudget.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryAllocate redMemoryAllocate
#define _66d6050d_context(value) value
#define _66d6050d_gpu(value) value
#define _66d6050d_handleName(value) value
#define _66d6050d_bytesCount(value) value
#define _66d6050d_memoryTypeIndex(value) value
#define _66d6050d_dedicateToArray(value) value
#define _66d6050d_dedicateToImage(value) value
#define _66d6050d_memoryBitflags(value) value
#define _66d6050d_outMemory(value) value
#define _66d6050d_outStatuses(value) value
#define _66d6050d_optionalFile(value) value
#define _66d6050d_optionalLine(value) value
#define _66d6050d_optionalUserData(value) value
#else
typedef struct _s_66d6050d_context { RedContext value; } _s_66d6050d_context;
typedef struct _s_66d6050d_gpu { RedHandleGpu value; } _s_66d6050d_gpu;
typedef struct _s_66d6050d_handleName { char* value; } _s_66d6050d_handleName;
typedef struct _s_66d6050d_bytesCount { uint64_t value; } _s_66d6050d_bytesCount;
typedef struct _s_66d6050d_memoryTypeIndex { unsigned value; } _s_66d6050d_memoryTypeIndex;
typedef struct _s_66d6050d_dedicateToArray { RedHandleArray value; } _s_66d6050d_dedicateToArray;
typedef struct _s_66d6050d_dedicateToImage { RedHandleImage value; } _s_66d6050d_dedicateToImage;
typedef struct _s_66d6050d_memoryBitflags { unsigned value; } _s_66d6050d_memoryBitflags;
typedef struct _s_66d6050d_outMemory { RedHandleMemory* value; } _s_66d6050d_outMemory;
typedef struct _s_66d6050d_outStatuses { RedStatuses* value; } _s_66d6050d_outStatuses;
typedef struct _s_66d6050d_optionalFile { char* value; } _s_66d6050d_optionalFile;
typedef struct _s_66d6050d_optionalLine { int value; } _s_66d6050d_optionalLine;
typedef struct _s_66d6050d_optionalUserData { void* value; } _s_66d6050d_optionalUserData;
static inline _s_66d6050d_context _66d6050d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_context){value}; }
static inline _s_66d6050d_gpu _66d6050d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_gpu){value}; }
static inline _s_66d6050d_handleName _66d6050d_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_handleName){value}; }
static inline _s_66d6050d_bytesCount _66d6050d_bytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_bytesCount){value}; }
static inline _s_66d6050d_memoryTypeIndex _66d6050d_memoryTypeIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_memoryTypeIndex){value}; }
static inline _s_66d6050d_dedicateToArray _66d6050d_dedicateToArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_dedicateToArray){value}; }
static inline _s_66d6050d_dedicateToImage _66d6050d_dedicateToImage(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_dedicateToImage){value}; }
static inline _s_66d6050d_memoryBitflags _66d6050d_memoryBitflags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_memoryBitflags){value}; }
static inline _s_66d6050d_outMemory _66d6050d_outMemory(RedHandleMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_outMemory){value}; }
static inline _s_66d6050d_outStatuses _66d6050d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_outStatuses){value}; }
static inline _s_66d6050d_optionalFile _66d6050d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_optionalFile){value}; }
static inline _s_66d6050d_optionalLine _66d6050d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_optionalLine){value}; }
static inline _s_66d6050d_optionalUserData _66d6050d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_66d6050d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryAllocate(_s_66d6050d_context context, _s_66d6050d_gpu gpu, _s_66d6050d_handleName handleName, _s_66d6050d_bytesCount bytesCount, _s_66d6050d_memoryTypeIndex memoryTypeIndex, _s_66d6050d_dedicateToArray dedicateToArray, _s_66d6050d_dedicateToImage dedicateToImage, _s_66d6050d_memoryBitflags memoryBitflags, _s_66d6050d_outMemory outMemory, _s_66d6050d_outStatuses outStatuses, _s_66d6050d_optionalFile optionalFile, _s_66d6050d_optionalLine optionalLine, _s_66d6050d_optionalUserData optionalUserData) {
  redMemoryAllocate(context.value, gpu.value, handleName.value, bytesCount.value, memoryTypeIndex.value, dedicateToArray.value, dedicateToImage.value, memoryBitflags.value, outMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryAllocateMappable redMemoryAllocateMappable
#define _6d4c9126_context(value) value
#define _6d4c9126_gpu(value) value
#define _6d4c9126_handleName(value) value
#define _6d4c9126_dedicate(value) value
#define _6d4c9126_array(value) value
#define _6d4c9126_arrayMemoryBytesCount(value) value
#define _6d4c9126_memoryTypeIndex(value) value
#define _6d4c9126_memoryBitflags(value) value
#define _6d4c9126_outMemory(value) value
#define _6d4c9126_outStatuses(value) value
#define _6d4c9126_optionalFile(value) value
#define _6d4c9126_optionalLine(value) value
#define _6d4c9126_optionalUserData(value) value
#else
typedef struct _s_6d4c9126_context { RedContext value; } _s_6d4c9126_context;
typedef struct _s_6d4c9126_gpu { RedHandleGpu value; } _s_6d4c9126_gpu;
typedef struct _s_6d4c9126_handleName { char* value; } _s_6d4c9126_handleName;
typedef struct _s_6d4c9126_dedicate { RedBool32 value; } _s_6d4c9126_dedicate;
typedef struct _s_6d4c9126_array { RedHandleArray value; } _s_6d4c9126_array;
typedef struct _s_6d4c9126_arrayMemoryBytesCount { uint64_t value; } _s_6d4c9126_arrayMemoryBytesCount;
typedef struct _s_6d4c9126_memoryTypeIndex { unsigned value; } _s_6d4c9126_memoryTypeIndex;
typedef struct _s_6d4c9126_memoryBitflags { unsigned value; } _s_6d4c9126_memoryBitflags;
typedef struct _s_6d4c9126_outMemory { RedHandleMemory* value; } _s_6d4c9126_outMemory;
typedef struct _s_6d4c9126_outStatuses { RedStatuses* value; } _s_6d4c9126_outStatuses;
typedef struct _s_6d4c9126_optionalFile { char* value; } _s_6d4c9126_optionalFile;
typedef struct _s_6d4c9126_optionalLine { int value; } _s_6d4c9126_optionalLine;
typedef struct _s_6d4c9126_optionalUserData { void* value; } _s_6d4c9126_optionalUserData;
static inline _s_6d4c9126_context _6d4c9126_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_context){value}; }
static inline _s_6d4c9126_gpu _6d4c9126_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_gpu){value}; }
static inline _s_6d4c9126_handleName _6d4c9126_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_handleName){value}; }
static inline _s_6d4c9126_dedicate _6d4c9126_dedicate(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_dedicate){value}; }
static inline _s_6d4c9126_array _6d4c9126_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_array){value}; }
static inline _s_6d4c9126_arrayMemoryBytesCount _6d4c9126_arrayMemoryBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_arrayMemoryBytesCount){value}; }
static inline _s_6d4c9126_memoryTypeIndex _6d4c9126_memoryTypeIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_memoryTypeIndex){value}; }
static inline _s_6d4c9126_memoryBitflags _6d4c9126_memoryBitflags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_memoryBitflags){value}; }
static inline _s_6d4c9126_outMemory _6d4c9126_outMemory(RedHandleMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_outMemory){value}; }
static inline _s_6d4c9126_outStatuses _6d4c9126_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_outStatuses){value}; }
static inline _s_6d4c9126_optionalFile _6d4c9126_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_optionalFile){value}; }
static inline _s_6d4c9126_optionalLine _6d4c9126_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_optionalLine){value}; }
static inline _s_6d4c9126_optionalUserData _6d4c9126_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6d4c9126_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryAllocateMappable(_s_6d4c9126_context context, _s_6d4c9126_gpu gpu, _s_6d4c9126_handleName handleName, _s_6d4c9126_dedicate dedicate, _s_6d4c9126_array array, _s_6d4c9126_arrayMemoryBytesCount arrayMemoryBytesCount, _s_6d4c9126_memoryTypeIndex memoryTypeIndex, _s_6d4c9126_memoryBitflags memoryBitflags, _s_6d4c9126_outMemory outMemory, _s_6d4c9126_outStatuses outStatuses, _s_6d4c9126_optionalFile optionalFile, _s_6d4c9126_optionalLine optionalLine, _s_6d4c9126_optionalUserData optionalUserData) {
  redMemoryAllocateMappable(context.value, gpu.value, handleName.value, dedicate.value, array.value, arrayMemoryBytesCount.value, memoryTypeIndex.value, memoryBitflags.value, outMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryFree redMemoryFree
#define _23089e5d_context(value) value
#define _23089e5d_gpu(value) value
#define _23089e5d_memory(value) value
#define _23089e5d_optionalFile(value) value
#define _23089e5d_optionalLine(value) value
#define _23089e5d_optionalUserData(value) value
#else
typedef struct _s_23089e5d_context { RedContext value; } _s_23089e5d_context;
typedef struct _s_23089e5d_gpu { RedHandleGpu value; } _s_23089e5d_gpu;
typedef struct _s_23089e5d_memory { RedHandleMemory value; } _s_23089e5d_memory;
typedef struct _s_23089e5d_optionalFile { char* value; } _s_23089e5d_optionalFile;
typedef struct _s_23089e5d_optionalLine { int value; } _s_23089e5d_optionalLine;
typedef struct _s_23089e5d_optionalUserData { void* value; } _s_23089e5d_optionalUserData;
static inline _s_23089e5d_context _23089e5d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_23089e5d_context){value}; }
static inline _s_23089e5d_gpu _23089e5d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_23089e5d_gpu){value}; }
static inline _s_23089e5d_memory _23089e5d_memory(RedHandleMemory value) { return REDGPU_NP_STRUCT_INIT(_s_23089e5d_memory){value}; }
static inline _s_23089e5d_optionalFile _23089e5d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_23089e5d_optionalFile){value}; }
static inline _s_23089e5d_optionalLine _23089e5d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_23089e5d_optionalLine){value}; }
static inline _s_23089e5d_optionalUserData _23089e5d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_23089e5d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryFree(_s_23089e5d_context context, _s_23089e5d_gpu gpu, _s_23089e5d_memory memory, _s_23089e5d_optionalFile optionalFile, _s_23089e5d_optionalLine optionalLine, _s_23089e5d_optionalUserData optionalUserData) {
  redMemoryFree(context.value, gpu.value, memory.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemorySet redMemorySet
#define _81c7fc7d_context(value) value
#define _81c7fc7d_gpu(value) value
#define _81c7fc7d_memoryArraysCount(value) value
#define _81c7fc7d_memoryArrays(value) value
#define _81c7fc7d_memoryImagesCount(value) value
#define _81c7fc7d_memoryImages(value) value
#define _81c7fc7d_outStatuses(value) value
#define _81c7fc7d_optionalFile(value) value
#define _81c7fc7d_optionalLine(value) value
#define _81c7fc7d_optionalUserData(value) value
#else
typedef struct _s_81c7fc7d_context { RedContext value; } _s_81c7fc7d_context;
typedef struct _s_81c7fc7d_gpu { RedHandleGpu value; } _s_81c7fc7d_gpu;
typedef struct _s_81c7fc7d_memoryArraysCount { unsigned value; } _s_81c7fc7d_memoryArraysCount;
typedef struct _s_81c7fc7d_memoryArrays { RedMemoryArray* value; } _s_81c7fc7d_memoryArrays;
typedef struct _s_81c7fc7d_memoryImagesCount { unsigned value; } _s_81c7fc7d_memoryImagesCount;
typedef struct _s_81c7fc7d_memoryImages { RedMemoryImage* value; } _s_81c7fc7d_memoryImages;
typedef struct _s_81c7fc7d_outStatuses { RedStatuses* value; } _s_81c7fc7d_outStatuses;
typedef struct _s_81c7fc7d_optionalFile { char* value; } _s_81c7fc7d_optionalFile;
typedef struct _s_81c7fc7d_optionalLine { int value; } _s_81c7fc7d_optionalLine;
typedef struct _s_81c7fc7d_optionalUserData { void* value; } _s_81c7fc7d_optionalUserData;
static inline _s_81c7fc7d_context _81c7fc7d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_81c7fc7d_context){value}; }
static inline _s_81c7fc7d_gpu _81c7fc7d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_81c7fc7d_gpu){value}; }
static inline _s_81c7fc7d_memoryArraysCount _81c7fc7d_memoryArraysCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_81c7fc7d_memoryArraysCount){value}; }
static inline _s_81c7fc7d_memoryArrays _81c7fc7d_memoryArrays(RedMemoryArray* value) { return REDGPU_NP_STRUCT_INIT(_s_81c7fc7d_memoryArrays){value}; }
static inline _s_81c7fc7d_memoryImagesCount _81c7fc7d_memoryImagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_81c7fc7d_memoryImagesCount){value}; }
static inline _s_81c7fc7d_memoryImages _81c7fc7d_memoryImages(RedMemoryImage* value) { return REDGPU_NP_STRUCT_INIT(_s_81c7fc7d_memoryImages){value}; }
static inline _s_81c7fc7d_outStatuses _81c7fc7d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_81c7fc7d_outStatuses){value}; }
static inline _s_81c7fc7d_optionalFile _81c7fc7d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_81c7fc7d_optionalFile){value}; }
static inline _s_81c7fc7d_optionalLine _81c7fc7d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_81c7fc7d_optionalLine){value}; }
static inline _s_81c7fc7d_optionalUserData _81c7fc7d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_81c7fc7d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemorySet(_s_81c7fc7d_context context, _s_81c7fc7d_gpu gpu, _s_81c7fc7d_memoryArraysCount memoryArraysCount, _s_81c7fc7d_memoryArrays memoryArrays, _s_81c7fc7d_memoryImagesCount memoryImagesCount, _s_81c7fc7d_memoryImages memoryImages, _s_81c7fc7d_outStatuses outStatuses, _s_81c7fc7d_optionalFile optionalFile, _s_81c7fc7d_optionalLine optionalLine, _s_81c7fc7d_optionalUserData optionalUserData) {
  redMemorySet(context.value, gpu.value, memoryArraysCount.value, memoryArrays.value, memoryImagesCount.value, memoryImages.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryMap redMemoryMap
#define _9060f292_context(value) value
#define _9060f292_gpu(value) value
#define _9060f292_mappableMemory(value) value
#define _9060f292_mappableMemoryBytesFirst(value) value
#define _9060f292_mappableMemoryBytesCount(value) value
#define _9060f292_outVolatilePointer(value) value
#define _9060f292_outStatuses(value) value
#define _9060f292_optionalFile(value) value
#define _9060f292_optionalLine(value) value
#define _9060f292_optionalUserData(value) value
#else
typedef struct _s_9060f292_context { RedContext value; } _s_9060f292_context;
typedef struct _s_9060f292_gpu { RedHandleGpu value; } _s_9060f292_gpu;
typedef struct _s_9060f292_mappableMemory { RedHandleMemory value; } _s_9060f292_mappableMemory;
typedef struct _s_9060f292_mappableMemoryBytesFirst { uint64_t value; } _s_9060f292_mappableMemoryBytesFirst;
typedef struct _s_9060f292_mappableMemoryBytesCount { uint64_t value; } _s_9060f292_mappableMemoryBytesCount;
typedef struct _s_9060f292_outVolatilePointer { void** value; } _s_9060f292_outVolatilePointer;
typedef struct _s_9060f292_outStatuses { RedStatuses* value; } _s_9060f292_outStatuses;
typedef struct _s_9060f292_optionalFile { char* value; } _s_9060f292_optionalFile;
typedef struct _s_9060f292_optionalLine { int value; } _s_9060f292_optionalLine;
typedef struct _s_9060f292_optionalUserData { void* value; } _s_9060f292_optionalUserData;
static inline _s_9060f292_context _9060f292_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_9060f292_context){value}; }
static inline _s_9060f292_gpu _9060f292_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_9060f292_gpu){value}; }
static inline _s_9060f292_mappableMemory _9060f292_mappableMemory(RedHandleMemory value) { return REDGPU_NP_STRUCT_INIT(_s_9060f292_mappableMemory){value}; }
static inline _s_9060f292_mappableMemoryBytesFirst _9060f292_mappableMemoryBytesFirst(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_9060f292_mappableMemoryBytesFirst){value}; }
static inline _s_9060f292_mappableMemoryBytesCount _9060f292_mappableMemoryBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_9060f292_mappableMemoryBytesCount){value}; }
static inline _s_9060f292_outVolatilePointer _9060f292_outVolatilePointer(void** value) { return REDGPU_NP_STRUCT_INIT(_s_9060f292_outVolatilePointer){value}; }
static inline _s_9060f292_outStatuses _9060f292_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_9060f292_outStatuses){value}; }
static inline _s_9060f292_optionalFile _9060f292_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9060f292_optionalFile){value}; }
static inline _s_9060f292_optionalLine _9060f292_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9060f292_optionalLine){value}; }
static inline _s_9060f292_optionalUserData _9060f292_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9060f292_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryMap(_s_9060f292_context context, _s_9060f292_gpu gpu, _s_9060f292_mappableMemory mappableMemory, _s_9060f292_mappableMemoryBytesFirst mappableMemoryBytesFirst, _s_9060f292_mappableMemoryBytesCount mappableMemoryBytesCount, _s_9060f292_outVolatilePointer outVolatilePointer, _s_9060f292_outStatuses outStatuses, _s_9060f292_optionalFile optionalFile, _s_9060f292_optionalLine optionalLine, _s_9060f292_optionalUserData optionalUserData) {
  redMemoryMap(context.value, gpu.value, mappableMemory.value, mappableMemoryBytesFirst.value, mappableMemoryBytesCount.value, outVolatilePointer.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryUnmap redMemoryUnmap
#define _b02908e0_context(value) value
#define _b02908e0_gpu(value) value
#define _b02908e0_mappableMemory(value) value
#define _b02908e0_optionalFile(value) value
#define _b02908e0_optionalLine(value) value
#define _b02908e0_optionalUserData(value) value
#else
typedef struct _s_b02908e0_context { RedContext value; } _s_b02908e0_context;
typedef struct _s_b02908e0_gpu { RedHandleGpu value; } _s_b02908e0_gpu;
typedef struct _s_b02908e0_mappableMemory { RedHandleMemory value; } _s_b02908e0_mappableMemory;
typedef struct _s_b02908e0_optionalFile { char* value; } _s_b02908e0_optionalFile;
typedef struct _s_b02908e0_optionalLine { int value; } _s_b02908e0_optionalLine;
typedef struct _s_b02908e0_optionalUserData { void* value; } _s_b02908e0_optionalUserData;
static inline _s_b02908e0_context _b02908e0_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b02908e0_context){value}; }
static inline _s_b02908e0_gpu _b02908e0_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b02908e0_gpu){value}; }
static inline _s_b02908e0_mappableMemory _b02908e0_mappableMemory(RedHandleMemory value) { return REDGPU_NP_STRUCT_INIT(_s_b02908e0_mappableMemory){value}; }
static inline _s_b02908e0_optionalFile _b02908e0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b02908e0_optionalFile){value}; }
static inline _s_b02908e0_optionalLine _b02908e0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b02908e0_optionalLine){value}; }
static inline _s_b02908e0_optionalUserData _b02908e0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b02908e0_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryUnmap(_s_b02908e0_context context, _s_b02908e0_gpu gpu, _s_b02908e0_mappableMemory mappableMemory, _s_b02908e0_optionalFile optionalFile, _s_b02908e0_optionalLine optionalLine, _s_b02908e0_optionalUserData optionalUserData) {
  redMemoryUnmap(context.value, gpu.value, mappableMemory.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryNonCoherentFlush redMemoryNonCoherentFlush
#define _8550ea0d_context(value) value
#define _8550ea0d_gpu(value) value
#define _8550ea0d_mappableMemoryRangesCount(value) value
#define _8550ea0d_mappableMemoryRanges(value) value
#define _8550ea0d_outStatuses(value) value
#define _8550ea0d_optionalFile(value) value
#define _8550ea0d_optionalLine(value) value
#define _8550ea0d_optionalUserData(value) value
#else
typedef struct _s_8550ea0d_context { RedContext value; } _s_8550ea0d_context;
typedef struct _s_8550ea0d_gpu { RedHandleGpu value; } _s_8550ea0d_gpu;
typedef struct _s_8550ea0d_mappableMemoryRangesCount { unsigned value; } _s_8550ea0d_mappableMemoryRangesCount;
typedef struct _s_8550ea0d_mappableMemoryRanges { RedMappableMemoryRange* value; } _s_8550ea0d_mappableMemoryRanges;
typedef struct _s_8550ea0d_outStatuses { RedStatuses* value; } _s_8550ea0d_outStatuses;
typedef struct _s_8550ea0d_optionalFile { char* value; } _s_8550ea0d_optionalFile;
typedef struct _s_8550ea0d_optionalLine { int value; } _s_8550ea0d_optionalLine;
typedef struct _s_8550ea0d_optionalUserData { void* value; } _s_8550ea0d_optionalUserData;
static inline _s_8550ea0d_context _8550ea0d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_8550ea0d_context){value}; }
static inline _s_8550ea0d_gpu _8550ea0d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_8550ea0d_gpu){value}; }
static inline _s_8550ea0d_mappableMemoryRangesCount _8550ea0d_mappableMemoryRangesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8550ea0d_mappableMemoryRangesCount){value}; }
static inline _s_8550ea0d_mappableMemoryRanges _8550ea0d_mappableMemoryRanges(RedMappableMemoryRange* value) { return REDGPU_NP_STRUCT_INIT(_s_8550ea0d_mappableMemoryRanges){value}; }
static inline _s_8550ea0d_outStatuses _8550ea0d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_8550ea0d_outStatuses){value}; }
static inline _s_8550ea0d_optionalFile _8550ea0d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8550ea0d_optionalFile){value}; }
static inline _s_8550ea0d_optionalLine _8550ea0d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8550ea0d_optionalLine){value}; }
static inline _s_8550ea0d_optionalUserData _8550ea0d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8550ea0d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryNonCoherentFlush(_s_8550ea0d_context context, _s_8550ea0d_gpu gpu, _s_8550ea0d_mappableMemoryRangesCount mappableMemoryRangesCount, _s_8550ea0d_mappableMemoryRanges mappableMemoryRanges, _s_8550ea0d_outStatuses outStatuses, _s_8550ea0d_optionalFile optionalFile, _s_8550ea0d_optionalLine optionalLine, _s_8550ea0d_optionalUserData optionalUserData) {
  redMemoryNonCoherentFlush(context.value, gpu.value, mappableMemoryRangesCount.value, mappableMemoryRanges.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryNonCoherentInvalidate redMemoryNonCoherentInvalidate
#define _d4a38ba3_context(value) value
#define _d4a38ba3_gpu(value) value
#define _d4a38ba3_mappableMemoryRangesCount(value) value
#define _d4a38ba3_mappableMemoryRanges(value) value
#define _d4a38ba3_outStatuses(value) value
#define _d4a38ba3_optionalFile(value) value
#define _d4a38ba3_optionalLine(value) value
#define _d4a38ba3_optionalUserData(value) value
#else
typedef struct _s_d4a38ba3_context { RedContext value; } _s_d4a38ba3_context;
typedef struct _s_d4a38ba3_gpu { RedHandleGpu value; } _s_d4a38ba3_gpu;
typedef struct _s_d4a38ba3_mappableMemoryRangesCount { unsigned value; } _s_d4a38ba3_mappableMemoryRangesCount;
typedef struct _s_d4a38ba3_mappableMemoryRanges { RedMappableMemoryRange* value; } _s_d4a38ba3_mappableMemoryRanges;
typedef struct _s_d4a38ba3_outStatuses { RedStatuses* value; } _s_d4a38ba3_outStatuses;
typedef struct _s_d4a38ba3_optionalFile { char* value; } _s_d4a38ba3_optionalFile;
typedef struct _s_d4a38ba3_optionalLine { int value; } _s_d4a38ba3_optionalLine;
typedef struct _s_d4a38ba3_optionalUserData { void* value; } _s_d4a38ba3_optionalUserData;
static inline _s_d4a38ba3_context _d4a38ba3_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_d4a38ba3_context){value}; }
static inline _s_d4a38ba3_gpu _d4a38ba3_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_d4a38ba3_gpu){value}; }
static inline _s_d4a38ba3_mappableMemoryRangesCount _d4a38ba3_mappableMemoryRangesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_d4a38ba3_mappableMemoryRangesCount){value}; }
static inline _s_d4a38ba3_mappableMemoryRanges _d4a38ba3_mappableMemoryRanges(RedMappableMemoryRange* value) { return REDGPU_NP_STRUCT_INIT(_s_d4a38ba3_mappableMemoryRanges){value}; }
static inline _s_d4a38ba3_outStatuses _d4a38ba3_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_d4a38ba3_outStatuses){value}; }
static inline _s_d4a38ba3_optionalFile _d4a38ba3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d4a38ba3_optionalFile){value}; }
static inline _s_d4a38ba3_optionalLine _d4a38ba3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d4a38ba3_optionalLine){value}; }
static inline _s_d4a38ba3_optionalUserData _d4a38ba3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d4a38ba3_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryNonCoherentInvalidate(_s_d4a38ba3_context context, _s_d4a38ba3_gpu gpu, _s_d4a38ba3_mappableMemoryRangesCount mappableMemoryRangesCount, _s_d4a38ba3_mappableMemoryRanges mappableMemoryRanges, _s_d4a38ba3_outStatuses outStatuses, _s_d4a38ba3_optionalFile optionalFile, _s_d4a38ba3_optionalLine optionalLine, _s_d4a38ba3_optionalUserData optionalUserData) {
  redMemoryNonCoherentInvalidate(context.value, gpu.value, mappableMemoryRangesCount.value, mappableMemoryRanges.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemoryAllocate redStructsMemoryAllocate
#define _ca1830ff_context(value) value
#define _ca1830ff_gpu(value) value
#define _ca1830ff_handleName(value) value
#define _ca1830ff_maxStructsCount(value) value
#define _ca1830ff_maxStructsMembersOfTypeArrayROConstantCount(value) value
#define _ca1830ff_maxStructsMembersOfTypeArrayROOrArrayRWCount(value) value
#define _ca1830ff_maxStructsMembersOfTypeTextureROCount(value) value
#define _ca1830ff_maxStructsMembersOfTypeTextureRWCount(value) value
#define _ca1830ff_outStructsMemory(value) value
#define _ca1830ff_outStatuses(value) value
#define _ca1830ff_optionalFile(value) value
#define _ca1830ff_optionalLine(value) value
#define _ca1830ff_optionalUserData(value) value
#else
typedef struct _s_ca1830ff_context { RedContext value; } _s_ca1830ff_context;
typedef struct _s_ca1830ff_gpu { RedHandleGpu value; } _s_ca1830ff_gpu;
typedef struct _s_ca1830ff_handleName { char* value; } _s_ca1830ff_handleName;
typedef struct _s_ca1830ff_maxStructsCount { unsigned value; } _s_ca1830ff_maxStructsCount;
typedef struct _s_ca1830ff_maxStructsMembersOfTypeArrayROConstantCount { unsigned value; } _s_ca1830ff_maxStructsMembersOfTypeArrayROConstantCount;
typedef struct _s_ca1830ff_maxStructsMembersOfTypeArrayROOrArrayRWCount { unsigned value; } _s_ca1830ff_maxStructsMembersOfTypeArrayROOrArrayRWCount;
typedef struct _s_ca1830ff_maxStructsMembersOfTypeTextureROCount { unsigned value; } _s_ca1830ff_maxStructsMembersOfTypeTextureROCount;
typedef struct _s_ca1830ff_maxStructsMembersOfTypeTextureRWCount { unsigned value; } _s_ca1830ff_maxStructsMembersOfTypeTextureRWCount;
typedef struct _s_ca1830ff_outStructsMemory { RedHandleStructsMemory* value; } _s_ca1830ff_outStructsMemory;
typedef struct _s_ca1830ff_outStatuses { RedStatuses* value; } _s_ca1830ff_outStatuses;
typedef struct _s_ca1830ff_optionalFile { char* value; } _s_ca1830ff_optionalFile;
typedef struct _s_ca1830ff_optionalLine { int value; } _s_ca1830ff_optionalLine;
typedef struct _s_ca1830ff_optionalUserData { void* value; } _s_ca1830ff_optionalUserData;
static inline _s_ca1830ff_context _ca1830ff_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_context){value}; }
static inline _s_ca1830ff_gpu _ca1830ff_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_gpu){value}; }
static inline _s_ca1830ff_handleName _ca1830ff_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_handleName){value}; }
static inline _s_ca1830ff_maxStructsCount _ca1830ff_maxStructsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_maxStructsCount){value}; }
static inline _s_ca1830ff_maxStructsMembersOfTypeArrayROConstantCount _ca1830ff_maxStructsMembersOfTypeArrayROConstantCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_maxStructsMembersOfTypeArrayROConstantCount){value}; }
static inline _s_ca1830ff_maxStructsMembersOfTypeArrayROOrArrayRWCount _ca1830ff_maxStructsMembersOfTypeArrayROOrArrayRWCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_maxStructsMembersOfTypeArrayROOrArrayRWCount){value}; }
static inline _s_ca1830ff_maxStructsMembersOfTypeTextureROCount _ca1830ff_maxStructsMembersOfTypeTextureROCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_maxStructsMembersOfTypeTextureROCount){value}; }
static inline _s_ca1830ff_maxStructsMembersOfTypeTextureRWCount _ca1830ff_maxStructsMembersOfTypeTextureRWCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_maxStructsMembersOfTypeTextureRWCount){value}; }
static inline _s_ca1830ff_outStructsMemory _ca1830ff_outStructsMemory(RedHandleStructsMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_outStructsMemory){value}; }
static inline _s_ca1830ff_outStatuses _ca1830ff_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_outStatuses){value}; }
static inline _s_ca1830ff_optionalFile _ca1830ff_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_optionalFile){value}; }
static inline _s_ca1830ff_optionalLine _ca1830ff_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_optionalLine){value}; }
static inline _s_ca1830ff_optionalUserData _ca1830ff_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ca1830ff_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemoryAllocate(_s_ca1830ff_context context, _s_ca1830ff_gpu gpu, _s_ca1830ff_handleName handleName, _s_ca1830ff_maxStructsCount maxStructsCount, _s_ca1830ff_maxStructsMembersOfTypeArrayROConstantCount maxStructsMembersOfTypeArrayROConstantCount, _s_ca1830ff_maxStructsMembersOfTypeArrayROOrArrayRWCount maxStructsMembersOfTypeArrayROOrArrayRWCount, _s_ca1830ff_maxStructsMembersOfTypeTextureROCount maxStructsMembersOfTypeTextureROCount, _s_ca1830ff_maxStructsMembersOfTypeTextureRWCount maxStructsMembersOfTypeTextureRWCount, _s_ca1830ff_outStructsMemory outStructsMemory, _s_ca1830ff_outStatuses outStatuses, _s_ca1830ff_optionalFile optionalFile, _s_ca1830ff_optionalLine optionalLine, _s_ca1830ff_optionalUserData optionalUserData) {
  redStructsMemoryAllocate(context.value, gpu.value, handleName.value, maxStructsCount.value, maxStructsMembersOfTypeArrayROConstantCount.value, maxStructsMembersOfTypeArrayROOrArrayRWCount.value, maxStructsMembersOfTypeTextureROCount.value, maxStructsMembersOfTypeTextureRWCount.value, outStructsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemoryAllocateSamplers redStructsMemoryAllocateSamplers
#define _a6a65124_context(value) value
#define _a6a65124_gpu(value) value
#define _a6a65124_handleName(value) value
#define _a6a65124_maxStructsCount(value) value
#define _a6a65124_maxStructsMembersOfTypeSamplerCount(value) value
#define _a6a65124_outStructsMemory(value) value
#define _a6a65124_outStatuses(value) value
#define _a6a65124_optionalFile(value) value
#define _a6a65124_optionalLine(value) value
#define _a6a65124_optionalUserData(value) value
#else
typedef struct _s_a6a65124_context { RedContext value; } _s_a6a65124_context;
typedef struct _s_a6a65124_gpu { RedHandleGpu value; } _s_a6a65124_gpu;
typedef struct _s_a6a65124_handleName { char* value; } _s_a6a65124_handleName;
typedef struct _s_a6a65124_maxStructsCount { unsigned value; } _s_a6a65124_maxStructsCount;
typedef struct _s_a6a65124_maxStructsMembersOfTypeSamplerCount { unsigned value; } _s_a6a65124_maxStructsMembersOfTypeSamplerCount;
typedef struct _s_a6a65124_outStructsMemory { RedHandleStructsMemory* value; } _s_a6a65124_outStructsMemory;
typedef struct _s_a6a65124_outStatuses { RedStatuses* value; } _s_a6a65124_outStatuses;
typedef struct _s_a6a65124_optionalFile { char* value; } _s_a6a65124_optionalFile;
typedef struct _s_a6a65124_optionalLine { int value; } _s_a6a65124_optionalLine;
typedef struct _s_a6a65124_optionalUserData { void* value; } _s_a6a65124_optionalUserData;
static inline _s_a6a65124_context _a6a65124_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_a6a65124_context){value}; }
static inline _s_a6a65124_gpu _a6a65124_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_a6a65124_gpu){value}; }
static inline _s_a6a65124_handleName _a6a65124_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a6a65124_handleName){value}; }
static inline _s_a6a65124_maxStructsCount _a6a65124_maxStructsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a6a65124_maxStructsCount){value}; }
static inline _s_a6a65124_maxStructsMembersOfTypeSamplerCount _a6a65124_maxStructsMembersOfTypeSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a6a65124_maxStructsMembersOfTypeSamplerCount){value}; }
static inline _s_a6a65124_outStructsMemory _a6a65124_outStructsMemory(RedHandleStructsMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_a6a65124_outStructsMemory){value}; }
static inline _s_a6a65124_outStatuses _a6a65124_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_a6a65124_outStatuses){value}; }
static inline _s_a6a65124_optionalFile _a6a65124_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a6a65124_optionalFile){value}; }
static inline _s_a6a65124_optionalLine _a6a65124_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a6a65124_optionalLine){value}; }
static inline _s_a6a65124_optionalUserData _a6a65124_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a6a65124_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemoryAllocateSamplers(_s_a6a65124_context context, _s_a6a65124_gpu gpu, _s_a6a65124_handleName handleName, _s_a6a65124_maxStructsCount maxStructsCount, _s_a6a65124_maxStructsMembersOfTypeSamplerCount maxStructsMembersOfTypeSamplerCount, _s_a6a65124_outStructsMemory outStructsMemory, _s_a6a65124_outStatuses outStatuses, _s_a6a65124_optionalFile optionalFile, _s_a6a65124_optionalLine optionalLine, _s_a6a65124_optionalUserData optionalUserData) {
  redStructsMemoryAllocateSamplers(context.value, gpu.value, handleName.value, maxStructsCount.value, maxStructsMembersOfTypeSamplerCount.value, outStructsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemorySuballocateStructs redStructsMemorySuballocateStructs
#define _2aeabcb8_context(value) value
#define _2aeabcb8_gpu(value) value
#define _2aeabcb8_handleNames(value) value
#define _2aeabcb8_structsMemory(value) value
#define _2aeabcb8_structsDeclarationsCount(value) value
#define _2aeabcb8_structsDeclarations(value) value
#define _2aeabcb8_outStructs(value) value
#define _2aeabcb8_outStatuses(value) value
#define _2aeabcb8_optionalFile(value) value
#define _2aeabcb8_optionalLine(value) value
#define _2aeabcb8_optionalUserData(value) value
#else
typedef struct _s_2aeabcb8_context { RedContext value; } _s_2aeabcb8_context;
typedef struct _s_2aeabcb8_gpu { RedHandleGpu value; } _s_2aeabcb8_gpu;
typedef struct _s_2aeabcb8_handleNames { const char** value; } _s_2aeabcb8_handleNames;
typedef struct _s_2aeabcb8_structsMemory { RedHandleStructsMemory value; } _s_2aeabcb8_structsMemory;
typedef struct _s_2aeabcb8_structsDeclarationsCount { unsigned value; } _s_2aeabcb8_structsDeclarationsCount;
typedef struct _s_2aeabcb8_structsDeclarations { RedHandleStructDeclaration* value; } _s_2aeabcb8_structsDeclarations;
typedef struct _s_2aeabcb8_outStructs { RedHandleStruct* value; } _s_2aeabcb8_outStructs;
typedef struct _s_2aeabcb8_outStatuses { RedStatuses* value; } _s_2aeabcb8_outStatuses;
typedef struct _s_2aeabcb8_optionalFile { char* value; } _s_2aeabcb8_optionalFile;
typedef struct _s_2aeabcb8_optionalLine { int value; } _s_2aeabcb8_optionalLine;
typedef struct _s_2aeabcb8_optionalUserData { void* value; } _s_2aeabcb8_optionalUserData;
static inline _s_2aeabcb8_context _2aeabcb8_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_2aeabcb8_context){value}; }
static inline _s_2aeabcb8_gpu _2aeabcb8_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_2aeabcb8_gpu){value}; }
static inline _s_2aeabcb8_handleNames _2aeabcb8_handleNames(const char** value) { return REDGPU_NP_STRUCT_INIT(_s_2aeabcb8_handleNames){value}; }
static inline _s_2aeabcb8_structsMemory _2aeabcb8_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_2aeabcb8_structsMemory){value}; }
static inline _s_2aeabcb8_structsDeclarationsCount _2aeabcb8_structsDeclarationsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_2aeabcb8_structsDeclarationsCount){value}; }
static inline _s_2aeabcb8_structsDeclarations _2aeabcb8_structsDeclarations(RedHandleStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_2aeabcb8_structsDeclarations){value}; }
static inline _s_2aeabcb8_outStructs _2aeabcb8_outStructs(RedHandleStruct* value) { return REDGPU_NP_STRUCT_INIT(_s_2aeabcb8_outStructs){value}; }
static inline _s_2aeabcb8_outStatuses _2aeabcb8_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_2aeabcb8_outStatuses){value}; }
static inline _s_2aeabcb8_optionalFile _2aeabcb8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2aeabcb8_optionalFile){value}; }
static inline _s_2aeabcb8_optionalLine _2aeabcb8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2aeabcb8_optionalLine){value}; }
static inline _s_2aeabcb8_optionalUserData _2aeabcb8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2aeabcb8_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemorySuballocateStructs(_s_2aeabcb8_context context, _s_2aeabcb8_gpu gpu, _s_2aeabcb8_handleNames handleNames, _s_2aeabcb8_structsMemory structsMemory, _s_2aeabcb8_structsDeclarationsCount structsDeclarationsCount, _s_2aeabcb8_structsDeclarations structsDeclarations, _s_2aeabcb8_outStructs outStructs, _s_2aeabcb8_outStatuses outStatuses, _s_2aeabcb8_optionalFile optionalFile, _s_2aeabcb8_optionalLine optionalLine, _s_2aeabcb8_optionalUserData optionalUserData) {
  redStructsMemorySuballocateStructs(context.value, gpu.value, handleNames.value, structsMemory.value, structsDeclarationsCount.value, structsDeclarations.value, outStructs.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemoryReset redStructsMemoryReset
#define _0d734196_context(value) value
#define _0d734196_gpu(value) value
#define _0d734196_structsMemory(value) value
#define _0d734196_outStatuses(value) value
#define _0d734196_optionalFile(value) value
#define _0d734196_optionalLine(value) value
#define _0d734196_optionalUserData(value) value
#else
typedef struct _s_0d734196_context { RedContext value; } _s_0d734196_context;
typedef struct _s_0d734196_gpu { RedHandleGpu value; } _s_0d734196_gpu;
typedef struct _s_0d734196_structsMemory { RedHandleStructsMemory value; } _s_0d734196_structsMemory;
typedef struct _s_0d734196_outStatuses { RedStatuses* value; } _s_0d734196_outStatuses;
typedef struct _s_0d734196_optionalFile { char* value; } _s_0d734196_optionalFile;
typedef struct _s_0d734196_optionalLine { int value; } _s_0d734196_optionalLine;
typedef struct _s_0d734196_optionalUserData { void* value; } _s_0d734196_optionalUserData;
static inline _s_0d734196_context _0d734196_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_0d734196_context){value}; }
static inline _s_0d734196_gpu _0d734196_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_0d734196_gpu){value}; }
static inline _s_0d734196_structsMemory _0d734196_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_0d734196_structsMemory){value}; }
static inline _s_0d734196_outStatuses _0d734196_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_0d734196_outStatuses){value}; }
static inline _s_0d734196_optionalFile _0d734196_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0d734196_optionalFile){value}; }
static inline _s_0d734196_optionalLine _0d734196_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0d734196_optionalLine){value}; }
static inline _s_0d734196_optionalUserData _0d734196_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0d734196_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemoryReset(_s_0d734196_context context, _s_0d734196_gpu gpu, _s_0d734196_structsMemory structsMemory, _s_0d734196_outStatuses outStatuses, _s_0d734196_optionalFile optionalFile, _s_0d734196_optionalLine optionalLine, _s_0d734196_optionalUserData optionalUserData) {
  redStructsMemoryReset(context.value, gpu.value, structsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemoryFree redStructsMemoryFree
#define _7c3647ab_context(value) value
#define _7c3647ab_gpu(value) value
#define _7c3647ab_structsMemory(value) value
#define _7c3647ab_optionalFile(value) value
#define _7c3647ab_optionalLine(value) value
#define _7c3647ab_optionalUserData(value) value
#else
typedef struct _s_7c3647ab_context { RedContext value; } _s_7c3647ab_context;
typedef struct _s_7c3647ab_gpu { RedHandleGpu value; } _s_7c3647ab_gpu;
typedef struct _s_7c3647ab_structsMemory { RedHandleStructsMemory value; } _s_7c3647ab_structsMemory;
typedef struct _s_7c3647ab_optionalFile { char* value; } _s_7c3647ab_optionalFile;
typedef struct _s_7c3647ab_optionalLine { int value; } _s_7c3647ab_optionalLine;
typedef struct _s_7c3647ab_optionalUserData { void* value; } _s_7c3647ab_optionalUserData;
static inline _s_7c3647ab_context _7c3647ab_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_7c3647ab_context){value}; }
static inline _s_7c3647ab_gpu _7c3647ab_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_7c3647ab_gpu){value}; }
static inline _s_7c3647ab_structsMemory _7c3647ab_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_7c3647ab_structsMemory){value}; }
static inline _s_7c3647ab_optionalFile _7c3647ab_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7c3647ab_optionalFile){value}; }
static inline _s_7c3647ab_optionalLine _7c3647ab_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7c3647ab_optionalLine){value}; }
static inline _s_7c3647ab_optionalUserData _7c3647ab_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7c3647ab_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemoryFree(_s_7c3647ab_context context, _s_7c3647ab_gpu gpu, _s_7c3647ab_structsMemory structsMemory, _s_7c3647ab_optionalFile optionalFile, _s_7c3647ab_optionalLine optionalLine, _s_7c3647ab_optionalUserData optionalUserData) {
  redStructsMemoryFree(context.value, gpu.value, structsMemory.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsSet redStructsSet
#define _b55b2659_context(value) value
#define _b55b2659_gpu(value) value
#define _b55b2659_structsMembersCount(value) value
#define _b55b2659_structsMembers(value) value
#define _b55b2659_optionalFile(value) value
#define _b55b2659_optionalLine(value) value
#define _b55b2659_optionalUserData(value) value
#else
typedef struct _s_b55b2659_context { RedContext value; } _s_b55b2659_context;
typedef struct _s_b55b2659_gpu { RedHandleGpu value; } _s_b55b2659_gpu;
typedef struct _s_b55b2659_structsMembersCount { unsigned value; } _s_b55b2659_structsMembersCount;
typedef struct _s_b55b2659_structsMembers { RedStructMember* value; } _s_b55b2659_structsMembers;
typedef struct _s_b55b2659_optionalFile { char* value; } _s_b55b2659_optionalFile;
typedef struct _s_b55b2659_optionalLine { int value; } _s_b55b2659_optionalLine;
typedef struct _s_b55b2659_optionalUserData { void* value; } _s_b55b2659_optionalUserData;
static inline _s_b55b2659_context _b55b2659_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b55b2659_context){value}; }
static inline _s_b55b2659_gpu _b55b2659_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b55b2659_gpu){value}; }
static inline _s_b55b2659_structsMembersCount _b55b2659_structsMembersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b55b2659_structsMembersCount){value}; }
static inline _s_b55b2659_structsMembers _b55b2659_structsMembers(RedStructMember* value) { return REDGPU_NP_STRUCT_INIT(_s_b55b2659_structsMembers){value}; }
static inline _s_b55b2659_optionalFile _b55b2659_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b55b2659_optionalFile){value}; }
static inline _s_b55b2659_optionalLine _b55b2659_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b55b2659_optionalLine){value}; }
static inline _s_b55b2659_optionalUserData _b55b2659_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b55b2659_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsSet(_s_b55b2659_context context, _s_b55b2659_gpu gpu, _s_b55b2659_structsMembersCount structsMembersCount, _s_b55b2659_structsMembers structsMembers, _s_b55b2659_optionalFile optionalFile, _s_b55b2659_optionalLine optionalLine, _s_b55b2659_optionalUserData optionalUserData) {
  redStructsSet(context.value, gpu.value, structsMembersCount.value, structsMembers.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateContext redCreateContext
#define _8b4eaa17_malloc(value) value
#define _8b4eaa17_free(value) value
#define _8b4eaa17_optionalMallocTagged(value) value
#define _8b4eaa17_optionalFreeTagged(value) value
#define _8b4eaa17_debugCallback(value) value
#define _8b4eaa17_sdkVersion(value) value
#define _8b4eaa17_sdkExtensionsCount(value) value
#define _8b4eaa17_sdkExtensions(value) value
#define _8b4eaa17_optionalProgramName(value) value
#define _8b4eaa17_optionalProgramVersion(value) value
#define _8b4eaa17_optionalEngineName(value) value
#define _8b4eaa17_optionalEngineVersion(value) value
#define _8b4eaa17_optionalSettings(value) value
#define _8b4eaa17_outContext(value) value
#define _8b4eaa17_outStatuses(value) value
#define _8b4eaa17_optionalFile(value) value
#define _8b4eaa17_optionalLine(value) value
#define _8b4eaa17_optionalUserData(value) value
#else
typedef struct _s_8b4eaa17_malloc { RedTypeProcedureMalloc value; } _s_8b4eaa17_malloc;
typedef struct _s_8b4eaa17_free { RedTypeProcedureFree value; } _s_8b4eaa17_free;
typedef struct _s_8b4eaa17_optionalMallocTagged { RedTypeProcedureMallocTagged value; } _s_8b4eaa17_optionalMallocTagged;
typedef struct _s_8b4eaa17_optionalFreeTagged { RedTypeProcedureFreeTagged value; } _s_8b4eaa17_optionalFreeTagged;
typedef struct _s_8b4eaa17_debugCallback { RedTypeProcedureDebugCallback value; } _s_8b4eaa17_debugCallback;
typedef struct _s_8b4eaa17_sdkVersion { RedSdkVersion value; } _s_8b4eaa17_sdkVersion;
typedef struct _s_8b4eaa17_sdkExtensionsCount { unsigned value; } _s_8b4eaa17_sdkExtensionsCount;
typedef struct _s_8b4eaa17_sdkExtensions { unsigned* value; } _s_8b4eaa17_sdkExtensions;
typedef struct _s_8b4eaa17_optionalProgramName { char* value; } _s_8b4eaa17_optionalProgramName;
typedef struct _s_8b4eaa17_optionalProgramVersion { unsigned value; } _s_8b4eaa17_optionalProgramVersion;
typedef struct _s_8b4eaa17_optionalEngineName { char* value; } _s_8b4eaa17_optionalEngineName;
typedef struct _s_8b4eaa17_optionalEngineVersion { unsigned value; } _s_8b4eaa17_optionalEngineVersion;
typedef struct _s_8b4eaa17_optionalSettings { void* value; } _s_8b4eaa17_optionalSettings;
typedef struct _s_8b4eaa17_outContext { RedContext* value; } _s_8b4eaa17_outContext;
typedef struct _s_8b4eaa17_outStatuses { RedStatuses* value; } _s_8b4eaa17_outStatuses;
typedef struct _s_8b4eaa17_optionalFile { char* value; } _s_8b4eaa17_optionalFile;
typedef struct _s_8b4eaa17_optionalLine { int value; } _s_8b4eaa17_optionalLine;
typedef struct _s_8b4eaa17_optionalUserData { void* value; } _s_8b4eaa17_optionalUserData;
static inline _s_8b4eaa17_malloc _8b4eaa17_malloc(RedTypeProcedureMalloc value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_malloc){value}; }
static inline _s_8b4eaa17_free _8b4eaa17_free(RedTypeProcedureFree value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_free){value}; }
static inline _s_8b4eaa17_optionalMallocTagged _8b4eaa17_optionalMallocTagged(RedTypeProcedureMallocTagged value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_optionalMallocTagged){value}; }
static inline _s_8b4eaa17_optionalFreeTagged _8b4eaa17_optionalFreeTagged(RedTypeProcedureFreeTagged value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_optionalFreeTagged){value}; }
static inline _s_8b4eaa17_debugCallback _8b4eaa17_debugCallback(RedTypeProcedureDebugCallback value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_debugCallback){value}; }
static inline _s_8b4eaa17_sdkVersion _8b4eaa17_sdkVersion(RedSdkVersion value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_sdkVersion){value}; }
static inline _s_8b4eaa17_sdkExtensionsCount _8b4eaa17_sdkExtensionsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_sdkExtensionsCount){value}; }
static inline _s_8b4eaa17_sdkExtensions _8b4eaa17_sdkExtensions(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_sdkExtensions){value}; }
static inline _s_8b4eaa17_optionalProgramName _8b4eaa17_optionalProgramName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_optionalProgramName){value}; }
static inline _s_8b4eaa17_optionalProgramVersion _8b4eaa17_optionalProgramVersion(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_optionalProgramVersion){value}; }
static inline _s_8b4eaa17_optionalEngineName _8b4eaa17_optionalEngineName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_optionalEngineName){value}; }
static inline _s_8b4eaa17_optionalEngineVersion _8b4eaa17_optionalEngineVersion(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_optionalEngineVersion){value}; }
static inline _s_8b4eaa17_optionalSettings _8b4eaa17_optionalSettings(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_optionalSettings){value}; }
static inline _s_8b4eaa17_outContext _8b4eaa17_outContext(RedContext* value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_outContext){value}; }
static inline _s_8b4eaa17_outStatuses _8b4eaa17_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_outStatuses){value}; }
static inline _s_8b4eaa17_optionalFile _8b4eaa17_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_optionalFile){value}; }
static inline _s_8b4eaa17_optionalLine _8b4eaa17_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_optionalLine){value}; }
static inline _s_8b4eaa17_optionalUserData _8b4eaa17_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8b4eaa17_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateContext(_s_8b4eaa17_malloc malloc, _s_8b4eaa17_free free, _s_8b4eaa17_optionalMallocTagged optionalMallocTagged, _s_8b4eaa17_optionalFreeTagged optionalFreeTagged, _s_8b4eaa17_debugCallback debugCallback, _s_8b4eaa17_sdkVersion sdkVersion, _s_8b4eaa17_sdkExtensionsCount sdkExtensionsCount, _s_8b4eaa17_sdkExtensions sdkExtensions, _s_8b4eaa17_optionalProgramName optionalProgramName, _s_8b4eaa17_optionalProgramVersion optionalProgramVersion, _s_8b4eaa17_optionalEngineName optionalEngineName, _s_8b4eaa17_optionalEngineVersion optionalEngineVersion, _s_8b4eaa17_optionalSettings optionalSettings, _s_8b4eaa17_outContext outContext, _s_8b4eaa17_outStatuses outStatuses, _s_8b4eaa17_optionalFile optionalFile, _s_8b4eaa17_optionalLine optionalLine, _s_8b4eaa17_optionalUserData optionalUserData) {
  redCreateContext(malloc.value, free.value, optionalMallocTagged.value, optionalFreeTagged.value, debugCallback.value, sdkVersion.value, sdkExtensionsCount.value, sdkExtensions.value, optionalProgramName.value, optionalProgramVersion.value, optionalEngineName.value, optionalEngineVersion.value, optionalSettings.value, outContext.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateArray redCreateArray
#define _95a0b6be_context(value) value
#define _95a0b6be_gpu(value) value
#define _95a0b6be_handleName(value) value
#define _95a0b6be_type(value) value
#define _95a0b6be_bytesCount(value) value
#define _95a0b6be_structuredBufferElementBytesCount(value) value
#define _95a0b6be_initialAccess(value) value
#define _95a0b6be_initialQueueFamilyIndex(value) value
#define _95a0b6be_dedicate(value) value
#define _95a0b6be_outArray(value) value
#define _95a0b6be_outStatuses(value) value
#define _95a0b6be_optionalFile(value) value
#define _95a0b6be_optionalLine(value) value
#define _95a0b6be_optionalUserData(value) value
#else
typedef struct _s_95a0b6be_context { RedContext value; } _s_95a0b6be_context;
typedef struct _s_95a0b6be_gpu { RedHandleGpu value; } _s_95a0b6be_gpu;
typedef struct _s_95a0b6be_handleName { char* value; } _s_95a0b6be_handleName;
typedef struct _s_95a0b6be_type { RedArrayType value; } _s_95a0b6be_type;
typedef struct _s_95a0b6be_bytesCount { uint64_t value; } _s_95a0b6be_bytesCount;
typedef struct _s_95a0b6be_structuredBufferElementBytesCount { uint64_t value; } _s_95a0b6be_structuredBufferElementBytesCount;
typedef struct _s_95a0b6be_initialAccess { RedAccessBitflags value; } _s_95a0b6be_initialAccess;
typedef struct _s_95a0b6be_initialQueueFamilyIndex { unsigned value; } _s_95a0b6be_initialQueueFamilyIndex;
typedef struct _s_95a0b6be_dedicate { RedBool32 value; } _s_95a0b6be_dedicate;
typedef struct _s_95a0b6be_outArray { RedArray* value; } _s_95a0b6be_outArray;
typedef struct _s_95a0b6be_outStatuses { RedStatuses* value; } _s_95a0b6be_outStatuses;
typedef struct _s_95a0b6be_optionalFile { char* value; } _s_95a0b6be_optionalFile;
typedef struct _s_95a0b6be_optionalLine { int value; } _s_95a0b6be_optionalLine;
typedef struct _s_95a0b6be_optionalUserData { void* value; } _s_95a0b6be_optionalUserData;
static inline _s_95a0b6be_context _95a0b6be_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_context){value}; }
static inline _s_95a0b6be_gpu _95a0b6be_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_gpu){value}; }
static inline _s_95a0b6be_handleName _95a0b6be_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_handleName){value}; }
static inline _s_95a0b6be_type _95a0b6be_type(RedArrayType value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_type){value}; }
static inline _s_95a0b6be_bytesCount _95a0b6be_bytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_bytesCount){value}; }
static inline _s_95a0b6be_structuredBufferElementBytesCount _95a0b6be_structuredBufferElementBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_structuredBufferElementBytesCount){value}; }
static inline _s_95a0b6be_initialAccess _95a0b6be_initialAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_initialAccess){value}; }
static inline _s_95a0b6be_initialQueueFamilyIndex _95a0b6be_initialQueueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_initialQueueFamilyIndex){value}; }
static inline _s_95a0b6be_dedicate _95a0b6be_dedicate(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_dedicate){value}; }
static inline _s_95a0b6be_outArray _95a0b6be_outArray(RedArray* value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_outArray){value}; }
static inline _s_95a0b6be_outStatuses _95a0b6be_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_outStatuses){value}; }
static inline _s_95a0b6be_optionalFile _95a0b6be_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_optionalFile){value}; }
static inline _s_95a0b6be_optionalLine _95a0b6be_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_optionalLine){value}; }
static inline _s_95a0b6be_optionalUserData _95a0b6be_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_95a0b6be_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateArray(_s_95a0b6be_context context, _s_95a0b6be_gpu gpu, _s_95a0b6be_handleName handleName, _s_95a0b6be_type type, _s_95a0b6be_bytesCount bytesCount, _s_95a0b6be_structuredBufferElementBytesCount structuredBufferElementBytesCount, _s_95a0b6be_initialAccess initialAccess, _s_95a0b6be_initialQueueFamilyIndex initialQueueFamilyIndex, _s_95a0b6be_dedicate dedicate, _s_95a0b6be_outArray outArray, _s_95a0b6be_outStatuses outStatuses, _s_95a0b6be_optionalFile optionalFile, _s_95a0b6be_optionalLine optionalLine, _s_95a0b6be_optionalUserData optionalUserData) {
  redCreateArray(context.value, gpu.value, handleName.value, type.value, bytesCount.value, structuredBufferElementBytesCount.value, initialAccess.value, initialQueueFamilyIndex.value, dedicate.value, outArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateImage redCreateImage
#define _1e73af3e_context(value) value
#define _1e73af3e_gpu(value) value
#define _1e73af3e_handleName(value) value
#define _1e73af3e_dimensions(value) value
#define _1e73af3e_format(value) value
#define _1e73af3e_width(value) value
#define _1e73af3e_height(value) value
#define _1e73af3e_depth(value) value
#define _1e73af3e_levelsCount(value) value
#define _1e73af3e_layersCount(value) value
#define _1e73af3e_multisampleCount(value) value
#define _1e73af3e_restrictToAccess(value) value
#define _1e73af3e_initialAccess(value) value
#define _1e73af3e_initialQueueFamilyIndex(value) value
#define _1e73af3e_dedicate(value) value
#define _1e73af3e_outImage(value) value
#define _1e73af3e_outStatuses(value) value
#define _1e73af3e_optionalFile(value) value
#define _1e73af3e_optionalLine(value) value
#define _1e73af3e_optionalUserData(value) value
#else
typedef struct _s_1e73af3e_context { RedContext value; } _s_1e73af3e_context;
typedef struct _s_1e73af3e_gpu { RedHandleGpu value; } _s_1e73af3e_gpu;
typedef struct _s_1e73af3e_handleName { char* value; } _s_1e73af3e_handleName;
typedef struct _s_1e73af3e_dimensions { RedImageDimensions value; } _s_1e73af3e_dimensions;
typedef struct _s_1e73af3e_format { RedFormat value; } _s_1e73af3e_format;
typedef struct _s_1e73af3e_width { unsigned value; } _s_1e73af3e_width;
typedef struct _s_1e73af3e_height { unsigned value; } _s_1e73af3e_height;
typedef struct _s_1e73af3e_depth { unsigned value; } _s_1e73af3e_depth;
typedef struct _s_1e73af3e_levelsCount { unsigned value; } _s_1e73af3e_levelsCount;
typedef struct _s_1e73af3e_layersCount { unsigned value; } _s_1e73af3e_layersCount;
typedef struct _s_1e73af3e_multisampleCount { RedMultisampleCountBitflag value; } _s_1e73af3e_multisampleCount;
typedef struct _s_1e73af3e_restrictToAccess { RedAccessBitflags value; } _s_1e73af3e_restrictToAccess;
typedef struct _s_1e73af3e_initialAccess { RedAccessBitflags value; } _s_1e73af3e_initialAccess;
typedef struct _s_1e73af3e_initialQueueFamilyIndex { unsigned value; } _s_1e73af3e_initialQueueFamilyIndex;
typedef struct _s_1e73af3e_dedicate { RedBool32 value; } _s_1e73af3e_dedicate;
typedef struct _s_1e73af3e_outImage { RedImage* value; } _s_1e73af3e_outImage;
typedef struct _s_1e73af3e_outStatuses { RedStatuses* value; } _s_1e73af3e_outStatuses;
typedef struct _s_1e73af3e_optionalFile { char* value; } _s_1e73af3e_optionalFile;
typedef struct _s_1e73af3e_optionalLine { int value; } _s_1e73af3e_optionalLine;
typedef struct _s_1e73af3e_optionalUserData { void* value; } _s_1e73af3e_optionalUserData;
static inline _s_1e73af3e_context _1e73af3e_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_context){value}; }
static inline _s_1e73af3e_gpu _1e73af3e_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_gpu){value}; }
static inline _s_1e73af3e_handleName _1e73af3e_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_handleName){value}; }
static inline _s_1e73af3e_dimensions _1e73af3e_dimensions(RedImageDimensions value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_dimensions){value}; }
static inline _s_1e73af3e_format _1e73af3e_format(RedFormat value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_format){value}; }
static inline _s_1e73af3e_width _1e73af3e_width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_width){value}; }
static inline _s_1e73af3e_height _1e73af3e_height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_height){value}; }
static inline _s_1e73af3e_depth _1e73af3e_depth(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_depth){value}; }
static inline _s_1e73af3e_levelsCount _1e73af3e_levelsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_levelsCount){value}; }
static inline _s_1e73af3e_layersCount _1e73af3e_layersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_layersCount){value}; }
static inline _s_1e73af3e_multisampleCount _1e73af3e_multisampleCount(RedMultisampleCountBitflag value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_multisampleCount){value}; }
static inline _s_1e73af3e_restrictToAccess _1e73af3e_restrictToAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_restrictToAccess){value}; }
static inline _s_1e73af3e_initialAccess _1e73af3e_initialAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_initialAccess){value}; }
static inline _s_1e73af3e_initialQueueFamilyIndex _1e73af3e_initialQueueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_initialQueueFamilyIndex){value}; }
static inline _s_1e73af3e_dedicate _1e73af3e_dedicate(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_dedicate){value}; }
static inline _s_1e73af3e_outImage _1e73af3e_outImage(RedImage* value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_outImage){value}; }
static inline _s_1e73af3e_outStatuses _1e73af3e_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_outStatuses){value}; }
static inline _s_1e73af3e_optionalFile _1e73af3e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_optionalFile){value}; }
static inline _s_1e73af3e_optionalLine _1e73af3e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_optionalLine){value}; }
static inline _s_1e73af3e_optionalUserData _1e73af3e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1e73af3e_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateImage(_s_1e73af3e_context context, _s_1e73af3e_gpu gpu, _s_1e73af3e_handleName handleName, _s_1e73af3e_dimensions dimensions, _s_1e73af3e_format format, _s_1e73af3e_width width, _s_1e73af3e_height height, _s_1e73af3e_depth depth, _s_1e73af3e_levelsCount levelsCount, _s_1e73af3e_layersCount layersCount, _s_1e73af3e_multisampleCount multisampleCount, _s_1e73af3e_restrictToAccess restrictToAccess, _s_1e73af3e_initialAccess initialAccess, _s_1e73af3e_initialQueueFamilyIndex initialQueueFamilyIndex, _s_1e73af3e_dedicate dedicate, _s_1e73af3e_outImage outImage, _s_1e73af3e_outStatuses outStatuses, _s_1e73af3e_optionalFile optionalFile, _s_1e73af3e_optionalLine optionalLine, _s_1e73af3e_optionalUserData optionalUserData) {
  redCreateImage(context.value, gpu.value, handleName.value, dimensions.value, format.value, width.value, height.value, depth.value, levelsCount.value, layersCount.value, multisampleCount.value, restrictToAccess.value, initialAccess.value, initialQueueFamilyIndex.value, dedicate.value, outImage.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateSampler redCreateSampler
#define _66b1ed07_context(value) value
#define _66b1ed07_gpu(value) value
#define _66b1ed07_handleName(value) value
#define _66b1ed07_filteringMag(value) value
#define _66b1ed07_filteringMin(value) value
#define _66b1ed07_filteringMip(value) value
#define _66b1ed07_behaviorOutsideTextureCoordinateU(value) value
#define _66b1ed07_behaviorOutsideTextureCoordinateV(value) value
#define _66b1ed07_behaviorOutsideTextureCoordinateW(value) value
#define _66b1ed07_mipLodBias(value) value
#define _66b1ed07_enableAnisotropy(value) value
#define _66b1ed07_maxAnisotropy(value) value
#define _66b1ed07_enableCompare(value) value
#define _66b1ed07_compareOp(value) value
#define _66b1ed07_minLod(value) value
#define _66b1ed07_maxLod(value) value
#define _66b1ed07_outSampler(value) value
#define _66b1ed07_outStatuses(value) value
#define _66b1ed07_optionalFile(value) value
#define _66b1ed07_optionalLine(value) value
#define _66b1ed07_optionalUserData(value) value
#else
typedef struct _s_66b1ed07_context { RedContext value; } _s_66b1ed07_context;
typedef struct _s_66b1ed07_gpu { RedHandleGpu value; } _s_66b1ed07_gpu;
typedef struct _s_66b1ed07_handleName { char* value; } _s_66b1ed07_handleName;
typedef struct _s_66b1ed07_filteringMag { RedSamplerFiltering value; } _s_66b1ed07_filteringMag;
typedef struct _s_66b1ed07_filteringMin { RedSamplerFiltering value; } _s_66b1ed07_filteringMin;
typedef struct _s_66b1ed07_filteringMip { RedSamplerFilteringMip value; } _s_66b1ed07_filteringMip;
typedef struct _s_66b1ed07_behaviorOutsideTextureCoordinateU { RedSamplerBehaviorOutsideTextureCoordinate value; } _s_66b1ed07_behaviorOutsideTextureCoordinateU;
typedef struct _s_66b1ed07_behaviorOutsideTextureCoordinateV { RedSamplerBehaviorOutsideTextureCoordinate value; } _s_66b1ed07_behaviorOutsideTextureCoordinateV;
typedef struct _s_66b1ed07_behaviorOutsideTextureCoordinateW { RedSamplerBehaviorOutsideTextureCoordinate value; } _s_66b1ed07_behaviorOutsideTextureCoordinateW;
typedef struct _s_66b1ed07_mipLodBias { float value; } _s_66b1ed07_mipLodBias;
typedef struct _s_66b1ed07_enableAnisotropy { RedBool32 value; } _s_66b1ed07_enableAnisotropy;
typedef struct _s_66b1ed07_maxAnisotropy { float value; } _s_66b1ed07_maxAnisotropy;
typedef struct _s_66b1ed07_enableCompare { RedBool32 value; } _s_66b1ed07_enableCompare;
typedef struct _s_66b1ed07_compareOp { RedCompareOp value; } _s_66b1ed07_compareOp;
typedef struct _s_66b1ed07_minLod { float value; } _s_66b1ed07_minLod;
typedef struct _s_66b1ed07_maxLod { float value; } _s_66b1ed07_maxLod;
typedef struct _s_66b1ed07_outSampler { RedHandleSampler* value; } _s_66b1ed07_outSampler;
typedef struct _s_66b1ed07_outStatuses { RedStatuses* value; } _s_66b1ed07_outStatuses;
typedef struct _s_66b1ed07_optionalFile { char* value; } _s_66b1ed07_optionalFile;
typedef struct _s_66b1ed07_optionalLine { int value; } _s_66b1ed07_optionalLine;
typedef struct _s_66b1ed07_optionalUserData { void* value; } _s_66b1ed07_optionalUserData;
static inline _s_66b1ed07_context _66b1ed07_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_context){value}; }
static inline _s_66b1ed07_gpu _66b1ed07_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_gpu){value}; }
static inline _s_66b1ed07_handleName _66b1ed07_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_handleName){value}; }
static inline _s_66b1ed07_filteringMag _66b1ed07_filteringMag(RedSamplerFiltering value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_filteringMag){value}; }
static inline _s_66b1ed07_filteringMin _66b1ed07_filteringMin(RedSamplerFiltering value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_filteringMin){value}; }
static inline _s_66b1ed07_filteringMip _66b1ed07_filteringMip(RedSamplerFilteringMip value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_filteringMip){value}; }
static inline _s_66b1ed07_behaviorOutsideTextureCoordinateU _66b1ed07_behaviorOutsideTextureCoordinateU(RedSamplerBehaviorOutsideTextureCoordinate value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_behaviorOutsideTextureCoordinateU){value}; }
static inline _s_66b1ed07_behaviorOutsideTextureCoordinateV _66b1ed07_behaviorOutsideTextureCoordinateV(RedSamplerBehaviorOutsideTextureCoordinate value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_behaviorOutsideTextureCoordinateV){value}; }
static inline _s_66b1ed07_behaviorOutsideTextureCoordinateW _66b1ed07_behaviorOutsideTextureCoordinateW(RedSamplerBehaviorOutsideTextureCoordinate value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_behaviorOutsideTextureCoordinateW){value}; }
static inline _s_66b1ed07_mipLodBias _66b1ed07_mipLodBias(float value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_mipLodBias){value}; }
static inline _s_66b1ed07_enableAnisotropy _66b1ed07_enableAnisotropy(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_enableAnisotropy){value}; }
static inline _s_66b1ed07_maxAnisotropy _66b1ed07_maxAnisotropy(float value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_maxAnisotropy){value}; }
static inline _s_66b1ed07_enableCompare _66b1ed07_enableCompare(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_enableCompare){value}; }
static inline _s_66b1ed07_compareOp _66b1ed07_compareOp(RedCompareOp value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_compareOp){value}; }
static inline _s_66b1ed07_minLod _66b1ed07_minLod(float value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_minLod){value}; }
static inline _s_66b1ed07_maxLod _66b1ed07_maxLod(float value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_maxLod){value}; }
static inline _s_66b1ed07_outSampler _66b1ed07_outSampler(RedHandleSampler* value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_outSampler){value}; }
static inline _s_66b1ed07_outStatuses _66b1ed07_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_outStatuses){value}; }
static inline _s_66b1ed07_optionalFile _66b1ed07_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_optionalFile){value}; }
static inline _s_66b1ed07_optionalLine _66b1ed07_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_optionalLine){value}; }
static inline _s_66b1ed07_optionalUserData _66b1ed07_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_66b1ed07_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateSampler(_s_66b1ed07_context context, _s_66b1ed07_gpu gpu, _s_66b1ed07_handleName handleName, _s_66b1ed07_filteringMag filteringMag, _s_66b1ed07_filteringMin filteringMin, _s_66b1ed07_filteringMip filteringMip, _s_66b1ed07_behaviorOutsideTextureCoordinateU behaviorOutsideTextureCoordinateU, _s_66b1ed07_behaviorOutsideTextureCoordinateV behaviorOutsideTextureCoordinateV, _s_66b1ed07_behaviorOutsideTextureCoordinateW behaviorOutsideTextureCoordinateW, _s_66b1ed07_mipLodBias mipLodBias, _s_66b1ed07_enableAnisotropy enableAnisotropy, _s_66b1ed07_maxAnisotropy maxAnisotropy, _s_66b1ed07_enableCompare enableCompare, _s_66b1ed07_compareOp compareOp, _s_66b1ed07_minLod minLod, _s_66b1ed07_maxLod maxLod, _s_66b1ed07_outSampler outSampler, _s_66b1ed07_outStatuses outStatuses, _s_66b1ed07_optionalFile optionalFile, _s_66b1ed07_optionalLine optionalLine, _s_66b1ed07_optionalUserData optionalUserData) {
  redCreateSampler(context.value, gpu.value, handleName.value, filteringMag.value, filteringMin.value, filteringMip.value, behaviorOutsideTextureCoordinateU.value, behaviorOutsideTextureCoordinateV.value, behaviorOutsideTextureCoordinateW.value, mipLodBias.value, enableAnisotropy.value, maxAnisotropy.value, enableCompare.value, compareOp.value, minLod.value, maxLod.value, outSampler.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateTexture redCreateTexture
#define _1ff52d80_context(value) value
#define _1ff52d80_gpu(value) value
#define _1ff52d80_handleName(value) value
#define _1ff52d80_image(value) value
#define _1ff52d80_parts(value) value
#define _1ff52d80_dimensions(value) value
#define _1ff52d80_format(value) value
#define _1ff52d80_levelsFirst(value) value
#define _1ff52d80_levelsCount(value) value
#define _1ff52d80_layersFirst(value) value
#define _1ff52d80_layersCount(value) value
#define _1ff52d80_restrictToAccess(value) value
#define _1ff52d80_outTexture(value) value
#define _1ff52d80_outStatuses(value) value
#define _1ff52d80_optionalFile(value) value
#define _1ff52d80_optionalLine(value) value
#define _1ff52d80_optionalUserData(value) value
#else
typedef struct _s_1ff52d80_context { RedContext value; } _s_1ff52d80_context;
typedef struct _s_1ff52d80_gpu { RedHandleGpu value; } _s_1ff52d80_gpu;
typedef struct _s_1ff52d80_handleName { char* value; } _s_1ff52d80_handleName;
typedef struct _s_1ff52d80_image { RedHandleImage value; } _s_1ff52d80_image;
typedef struct _s_1ff52d80_parts { RedImagePartBitflags value; } _s_1ff52d80_parts;
typedef struct _s_1ff52d80_dimensions { RedTextureDimensions value; } _s_1ff52d80_dimensions;
typedef struct _s_1ff52d80_format { RedFormat value; } _s_1ff52d80_format;
typedef struct _s_1ff52d80_levelsFirst { unsigned value; } _s_1ff52d80_levelsFirst;
typedef struct _s_1ff52d80_levelsCount { unsigned value; } _s_1ff52d80_levelsCount;
typedef struct _s_1ff52d80_layersFirst { unsigned value; } _s_1ff52d80_layersFirst;
typedef struct _s_1ff52d80_layersCount { unsigned value; } _s_1ff52d80_layersCount;
typedef struct _s_1ff52d80_restrictToAccess { RedAccessBitflags value; } _s_1ff52d80_restrictToAccess;
typedef struct _s_1ff52d80_outTexture { RedHandleTexture* value; } _s_1ff52d80_outTexture;
typedef struct _s_1ff52d80_outStatuses { RedStatuses* value; } _s_1ff52d80_outStatuses;
typedef struct _s_1ff52d80_optionalFile { char* value; } _s_1ff52d80_optionalFile;
typedef struct _s_1ff52d80_optionalLine { int value; } _s_1ff52d80_optionalLine;
typedef struct _s_1ff52d80_optionalUserData { void* value; } _s_1ff52d80_optionalUserData;
static inline _s_1ff52d80_context _1ff52d80_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_context){value}; }
static inline _s_1ff52d80_gpu _1ff52d80_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_gpu){value}; }
static inline _s_1ff52d80_handleName _1ff52d80_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_handleName){value}; }
static inline _s_1ff52d80_image _1ff52d80_image(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_image){value}; }
static inline _s_1ff52d80_parts _1ff52d80_parts(RedImagePartBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_parts){value}; }
static inline _s_1ff52d80_dimensions _1ff52d80_dimensions(RedTextureDimensions value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_dimensions){value}; }
static inline _s_1ff52d80_format _1ff52d80_format(RedFormat value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_format){value}; }
static inline _s_1ff52d80_levelsFirst _1ff52d80_levelsFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_levelsFirst){value}; }
static inline _s_1ff52d80_levelsCount _1ff52d80_levelsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_levelsCount){value}; }
static inline _s_1ff52d80_layersFirst _1ff52d80_layersFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_layersFirst){value}; }
static inline _s_1ff52d80_layersCount _1ff52d80_layersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_layersCount){value}; }
static inline _s_1ff52d80_restrictToAccess _1ff52d80_restrictToAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_restrictToAccess){value}; }
static inline _s_1ff52d80_outTexture _1ff52d80_outTexture(RedHandleTexture* value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_outTexture){value}; }
static inline _s_1ff52d80_outStatuses _1ff52d80_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_outStatuses){value}; }
static inline _s_1ff52d80_optionalFile _1ff52d80_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_optionalFile){value}; }
static inline _s_1ff52d80_optionalLine _1ff52d80_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_optionalLine){value}; }
static inline _s_1ff52d80_optionalUserData _1ff52d80_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1ff52d80_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateTexture(_s_1ff52d80_context context, _s_1ff52d80_gpu gpu, _s_1ff52d80_handleName handleName, _s_1ff52d80_image image, _s_1ff52d80_parts parts, _s_1ff52d80_dimensions dimensions, _s_1ff52d80_format format, _s_1ff52d80_levelsFirst levelsFirst, _s_1ff52d80_levelsCount levelsCount, _s_1ff52d80_layersFirst layersFirst, _s_1ff52d80_layersCount layersCount, _s_1ff52d80_restrictToAccess restrictToAccess, _s_1ff52d80_outTexture outTexture, _s_1ff52d80_outStatuses outStatuses, _s_1ff52d80_optionalFile optionalFile, _s_1ff52d80_optionalLine optionalLine, _s_1ff52d80_optionalUserData optionalUserData) {
  redCreateTexture(context.value, gpu.value, handleName.value, image.value, parts.value, dimensions.value, format.value, levelsFirst.value, levelsCount.value, layersFirst.value, layersCount.value, restrictToAccess.value, outTexture.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateGpuCode redCreateGpuCode
#define _01c06284_context(value) value
#define _01c06284_gpu(value) value
#define _01c06284_handleName(value) value
#define _01c06284_irBytesCount(value) value
#define _01c06284_ir(value) value
#define _01c06284_outGpuCode(value) value
#define _01c06284_outStatuses(value) value
#define _01c06284_optionalFile(value) value
#define _01c06284_optionalLine(value) value
#define _01c06284_optionalUserData(value) value
#else
typedef struct _s_01c06284_context { RedContext value; } _s_01c06284_context;
typedef struct _s_01c06284_gpu { RedHandleGpu value; } _s_01c06284_gpu;
typedef struct _s_01c06284_handleName { char* value; } _s_01c06284_handleName;
typedef struct _s_01c06284_irBytesCount { uint64_t value; } _s_01c06284_irBytesCount;
typedef struct _s_01c06284_ir { void* value; } _s_01c06284_ir;
typedef struct _s_01c06284_outGpuCode { RedHandleGpuCode* value; } _s_01c06284_outGpuCode;
typedef struct _s_01c06284_outStatuses { RedStatuses* value; } _s_01c06284_outStatuses;
typedef struct _s_01c06284_optionalFile { char* value; } _s_01c06284_optionalFile;
typedef struct _s_01c06284_optionalLine { int value; } _s_01c06284_optionalLine;
typedef struct _s_01c06284_optionalUserData { void* value; } _s_01c06284_optionalUserData;
static inline _s_01c06284_context _01c06284_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_01c06284_context){value}; }
static inline _s_01c06284_gpu _01c06284_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_01c06284_gpu){value}; }
static inline _s_01c06284_handleName _01c06284_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_01c06284_handleName){value}; }
static inline _s_01c06284_irBytesCount _01c06284_irBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_01c06284_irBytesCount){value}; }
static inline _s_01c06284_ir _01c06284_ir(void* value) { return REDGPU_NP_STRUCT_INIT(_s_01c06284_ir){value}; }
static inline _s_01c06284_outGpuCode _01c06284_outGpuCode(RedHandleGpuCode* value) { return REDGPU_NP_STRUCT_INIT(_s_01c06284_outGpuCode){value}; }
static inline _s_01c06284_outStatuses _01c06284_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_01c06284_outStatuses){value}; }
static inline _s_01c06284_optionalFile _01c06284_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_01c06284_optionalFile){value}; }
static inline _s_01c06284_optionalLine _01c06284_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_01c06284_optionalLine){value}; }
static inline _s_01c06284_optionalUserData _01c06284_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_01c06284_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateGpuCode(_s_01c06284_context context, _s_01c06284_gpu gpu, _s_01c06284_handleName handleName, _s_01c06284_irBytesCount irBytesCount, _s_01c06284_ir ir, _s_01c06284_outGpuCode outGpuCode, _s_01c06284_outStatuses outStatuses, _s_01c06284_optionalFile optionalFile, _s_01c06284_optionalLine optionalLine, _s_01c06284_optionalUserData optionalUserData) {
  redCreateGpuCode(context.value, gpu.value, handleName.value, irBytesCount.value, ir.value, outGpuCode.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateOutputDeclaration redCreateOutputDeclaration
#define _4726df20_context(value) value
#define _4726df20_gpu(value) value
#define _4726df20_handleName(value) value
#define _4726df20_outputDeclarationMembers(value) value
#define _4726df20_outputDeclarationMembersResolveSources(value) value
#define _4726df20_dependencyByRegion(value) value
#define _4726df20_dependencyByRegionAllowUsageAliasOrderBarriers(value) value
#define _4726df20_outOutputDeclaration(value) value
#define _4726df20_outStatuses(value) value
#define _4726df20_optionalFile(value) value
#define _4726df20_optionalLine(value) value
#define _4726df20_optionalUserData(value) value
#else
typedef struct _s_4726df20_context { RedContext value; } _s_4726df20_context;
typedef struct _s_4726df20_gpu { RedHandleGpu value; } _s_4726df20_gpu;
typedef struct _s_4726df20_handleName { char* value; } _s_4726df20_handleName;
typedef struct _s_4726df20_outputDeclarationMembers { RedOutputDeclarationMembers* value; } _s_4726df20_outputDeclarationMembers;
typedef struct _s_4726df20_outputDeclarationMembersResolveSources { RedOutputDeclarationMembersResolveSources* value; } _s_4726df20_outputDeclarationMembersResolveSources;
typedef struct _s_4726df20_dependencyByRegion { RedBool32 value; } _s_4726df20_dependencyByRegion;
typedef struct _s_4726df20_dependencyByRegionAllowUsageAliasOrderBarriers { RedBool32 value; } _s_4726df20_dependencyByRegionAllowUsageAliasOrderBarriers;
typedef struct _s_4726df20_outOutputDeclaration { RedHandleOutputDeclaration* value; } _s_4726df20_outOutputDeclaration;
typedef struct _s_4726df20_outStatuses { RedStatuses* value; } _s_4726df20_outStatuses;
typedef struct _s_4726df20_optionalFile { char* value; } _s_4726df20_optionalFile;
typedef struct _s_4726df20_optionalLine { int value; } _s_4726df20_optionalLine;
typedef struct _s_4726df20_optionalUserData { void* value; } _s_4726df20_optionalUserData;
static inline _s_4726df20_context _4726df20_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_4726df20_context){value}; }
static inline _s_4726df20_gpu _4726df20_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_4726df20_gpu){value}; }
static inline _s_4726df20_handleName _4726df20_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4726df20_handleName){value}; }
static inline _s_4726df20_outputDeclarationMembers _4726df20_outputDeclarationMembers(RedOutputDeclarationMembers* value) { return REDGPU_NP_STRUCT_INIT(_s_4726df20_outputDeclarationMembers){value}; }
static inline _s_4726df20_outputDeclarationMembersResolveSources _4726df20_outputDeclarationMembersResolveSources(RedOutputDeclarationMembersResolveSources* value) { return REDGPU_NP_STRUCT_INIT(_s_4726df20_outputDeclarationMembersResolveSources){value}; }
static inline _s_4726df20_dependencyByRegion _4726df20_dependencyByRegion(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_4726df20_dependencyByRegion){value}; }
static inline _s_4726df20_dependencyByRegionAllowUsageAliasOrderBarriers _4726df20_dependencyByRegionAllowUsageAliasOrderBarriers(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_4726df20_dependencyByRegionAllowUsageAliasOrderBarriers){value}; }
static inline _s_4726df20_outOutputDeclaration _4726df20_outOutputDeclaration(RedHandleOutputDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_4726df20_outOutputDeclaration){value}; }
static inline _s_4726df20_outStatuses _4726df20_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_4726df20_outStatuses){value}; }
static inline _s_4726df20_optionalFile _4726df20_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4726df20_optionalFile){value}; }
static inline _s_4726df20_optionalLine _4726df20_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4726df20_optionalLine){value}; }
static inline _s_4726df20_optionalUserData _4726df20_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4726df20_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateOutputDeclaration(_s_4726df20_context context, _s_4726df20_gpu gpu, _s_4726df20_handleName handleName, _s_4726df20_outputDeclarationMembers outputDeclarationMembers, _s_4726df20_outputDeclarationMembersResolveSources outputDeclarationMembersResolveSources, _s_4726df20_dependencyByRegion dependencyByRegion, _s_4726df20_dependencyByRegionAllowUsageAliasOrderBarriers dependencyByRegionAllowUsageAliasOrderBarriers, _s_4726df20_outOutputDeclaration outOutputDeclaration, _s_4726df20_outStatuses outStatuses, _s_4726df20_optionalFile optionalFile, _s_4726df20_optionalLine optionalLine, _s_4726df20_optionalUserData optionalUserData) {
  redCreateOutputDeclaration(context.value, gpu.value, handleName.value, outputDeclarationMembers.value, outputDeclarationMembersResolveSources.value, dependencyByRegion.value, dependencyByRegionAllowUsageAliasOrderBarriers.value, outOutputDeclaration.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateStructDeclaration redCreateStructDeclaration
#define _413f0fa7_context(value) value
#define _413f0fa7_gpu(value) value
#define _413f0fa7_handleName(value) value
#define _413f0fa7_structDeclarationMembersCount(value) value
#define _413f0fa7_structDeclarationMembers(value) value
#define _413f0fa7_structDeclarationMembersArrayROCount(value) value
#define _413f0fa7_structDeclarationMembersArrayRO(value) value
#define _413f0fa7_procedureParametersHandlesDeclaration(value) value
#define _413f0fa7_outStructDeclaration(value) value
#define _413f0fa7_outStatuses(value) value
#define _413f0fa7_optionalFile(value) value
#define _413f0fa7_optionalLine(value) value
#define _413f0fa7_optionalUserData(value) value
#else
typedef struct _s_413f0fa7_context { RedContext value; } _s_413f0fa7_context;
typedef struct _s_413f0fa7_gpu { RedHandleGpu value; } _s_413f0fa7_gpu;
typedef struct _s_413f0fa7_handleName { char* value; } _s_413f0fa7_handleName;
typedef struct _s_413f0fa7_structDeclarationMembersCount { unsigned value; } _s_413f0fa7_structDeclarationMembersCount;
typedef struct _s_413f0fa7_structDeclarationMembers { RedStructDeclarationMember* value; } _s_413f0fa7_structDeclarationMembers;
typedef struct _s_413f0fa7_structDeclarationMembersArrayROCount { unsigned value; } _s_413f0fa7_structDeclarationMembersArrayROCount;
typedef struct _s_413f0fa7_structDeclarationMembersArrayRO { RedStructDeclarationMemberArrayRO* value; } _s_413f0fa7_structDeclarationMembersArrayRO;
typedef struct _s_413f0fa7_procedureParametersHandlesDeclaration { RedBool32 value; } _s_413f0fa7_procedureParametersHandlesDeclaration;
typedef struct _s_413f0fa7_outStructDeclaration { RedHandleStructDeclaration* value; } _s_413f0fa7_outStructDeclaration;
typedef struct _s_413f0fa7_outStatuses { RedStatuses* value; } _s_413f0fa7_outStatuses;
typedef struct _s_413f0fa7_optionalFile { char* value; } _s_413f0fa7_optionalFile;
typedef struct _s_413f0fa7_optionalLine { int value; } _s_413f0fa7_optionalLine;
typedef struct _s_413f0fa7_optionalUserData { void* value; } _s_413f0fa7_optionalUserData;
static inline _s_413f0fa7_context _413f0fa7_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_context){value}; }
static inline _s_413f0fa7_gpu _413f0fa7_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_gpu){value}; }
static inline _s_413f0fa7_handleName _413f0fa7_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_handleName){value}; }
static inline _s_413f0fa7_structDeclarationMembersCount _413f0fa7_structDeclarationMembersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_structDeclarationMembersCount){value}; }
static inline _s_413f0fa7_structDeclarationMembers _413f0fa7_structDeclarationMembers(RedStructDeclarationMember* value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_structDeclarationMembers){value}; }
static inline _s_413f0fa7_structDeclarationMembersArrayROCount _413f0fa7_structDeclarationMembersArrayROCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_structDeclarationMembersArrayROCount){value}; }
static inline _s_413f0fa7_structDeclarationMembersArrayRO _413f0fa7_structDeclarationMembersArrayRO(RedStructDeclarationMemberArrayRO* value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_structDeclarationMembersArrayRO){value}; }
static inline _s_413f0fa7_procedureParametersHandlesDeclaration _413f0fa7_procedureParametersHandlesDeclaration(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_procedureParametersHandlesDeclaration){value}; }
static inline _s_413f0fa7_outStructDeclaration _413f0fa7_outStructDeclaration(RedHandleStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_outStructDeclaration){value}; }
static inline _s_413f0fa7_outStatuses _413f0fa7_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_outStatuses){value}; }
static inline _s_413f0fa7_optionalFile _413f0fa7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_optionalFile){value}; }
static inline _s_413f0fa7_optionalLine _413f0fa7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_optionalLine){value}; }
static inline _s_413f0fa7_optionalUserData _413f0fa7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_413f0fa7_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateStructDeclaration(_s_413f0fa7_context context, _s_413f0fa7_gpu gpu, _s_413f0fa7_handleName handleName, _s_413f0fa7_structDeclarationMembersCount structDeclarationMembersCount, _s_413f0fa7_structDeclarationMembers structDeclarationMembers, _s_413f0fa7_structDeclarationMembersArrayROCount structDeclarationMembersArrayROCount, _s_413f0fa7_structDeclarationMembersArrayRO structDeclarationMembersArrayRO, _s_413f0fa7_procedureParametersHandlesDeclaration procedureParametersHandlesDeclaration, _s_413f0fa7_outStructDeclaration outStructDeclaration, _s_413f0fa7_outStatuses outStatuses, _s_413f0fa7_optionalFile optionalFile, _s_413f0fa7_optionalLine optionalLine, _s_413f0fa7_optionalUserData optionalUserData) {
  redCreateStructDeclaration(context.value, gpu.value, handleName.value, structDeclarationMembersCount.value, structDeclarationMembers.value, structDeclarationMembersArrayROCount.value, structDeclarationMembersArrayRO.value, procedureParametersHandlesDeclaration.value, outStructDeclaration.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateProcedureParameters redCreateProcedureParameters
#define _7067ad8e_context(value) value
#define _7067ad8e_gpu(value) value
#define _7067ad8e_handleName(value) value
#define _7067ad8e_procedureParametersDeclaration(value) value
#define _7067ad8e_outProcedureParameters(value) value
#define _7067ad8e_outStatuses(value) value
#define _7067ad8e_optionalFile(value) value
#define _7067ad8e_optionalLine(value) value
#define _7067ad8e_optionalUserData(value) value
#else
typedef struct _s_7067ad8e_context { RedContext value; } _s_7067ad8e_context;
typedef struct _s_7067ad8e_gpu { RedHandleGpu value; } _s_7067ad8e_gpu;
typedef struct _s_7067ad8e_handleName { char* value; } _s_7067ad8e_handleName;
typedef struct _s_7067ad8e_procedureParametersDeclaration { RedProcedureParametersDeclaration* value; } _s_7067ad8e_procedureParametersDeclaration;
typedef struct _s_7067ad8e_outProcedureParameters { RedHandleProcedureParameters* value; } _s_7067ad8e_outProcedureParameters;
typedef struct _s_7067ad8e_outStatuses { RedStatuses* value; } _s_7067ad8e_outStatuses;
typedef struct _s_7067ad8e_optionalFile { char* value; } _s_7067ad8e_optionalFile;
typedef struct _s_7067ad8e_optionalLine { int value; } _s_7067ad8e_optionalLine;
typedef struct _s_7067ad8e_optionalUserData { void* value; } _s_7067ad8e_optionalUserData;
static inline _s_7067ad8e_context _7067ad8e_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_7067ad8e_context){value}; }
static inline _s_7067ad8e_gpu _7067ad8e_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_7067ad8e_gpu){value}; }
static inline _s_7067ad8e_handleName _7067ad8e_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7067ad8e_handleName){value}; }
static inline _s_7067ad8e_procedureParametersDeclaration _7067ad8e_procedureParametersDeclaration(RedProcedureParametersDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_7067ad8e_procedureParametersDeclaration){value}; }
static inline _s_7067ad8e_outProcedureParameters _7067ad8e_outProcedureParameters(RedHandleProcedureParameters* value) { return REDGPU_NP_STRUCT_INIT(_s_7067ad8e_outProcedureParameters){value}; }
static inline _s_7067ad8e_outStatuses _7067ad8e_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_7067ad8e_outStatuses){value}; }
static inline _s_7067ad8e_optionalFile _7067ad8e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7067ad8e_optionalFile){value}; }
static inline _s_7067ad8e_optionalLine _7067ad8e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7067ad8e_optionalLine){value}; }
static inline _s_7067ad8e_optionalUserData _7067ad8e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7067ad8e_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateProcedureParameters(_s_7067ad8e_context context, _s_7067ad8e_gpu gpu, _s_7067ad8e_handleName handleName, _s_7067ad8e_procedureParametersDeclaration procedureParametersDeclaration, _s_7067ad8e_outProcedureParameters outProcedureParameters, _s_7067ad8e_outStatuses outStatuses, _s_7067ad8e_optionalFile optionalFile, _s_7067ad8e_optionalLine optionalLine, _s_7067ad8e_optionalUserData optionalUserData) {
  redCreateProcedureParameters(context.value, gpu.value, handleName.value, procedureParametersDeclaration.value, outProcedureParameters.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateProcedureCache redCreateProcedureCache
#define _ec5dbc9f_context(value) value
#define _ec5dbc9f_gpu(value) value
#define _ec5dbc9f_handleName(value) value
#define _ec5dbc9f_fromBlobBytesCount(value) value
#define _ec5dbc9f_fromBlob(value) value
#define _ec5dbc9f_outProcedureCache(value) value
#define _ec5dbc9f_outStatuses(value) value
#define _ec5dbc9f_optionalFile(value) value
#define _ec5dbc9f_optionalLine(value) value
#define _ec5dbc9f_optionalUserData(value) value
#else
typedef struct _s_ec5dbc9f_context { RedContext value; } _s_ec5dbc9f_context;
typedef struct _s_ec5dbc9f_gpu { RedHandleGpu value; } _s_ec5dbc9f_gpu;
typedef struct _s_ec5dbc9f_handleName { char* value; } _s_ec5dbc9f_handleName;
typedef struct _s_ec5dbc9f_fromBlobBytesCount { uint64_t value; } _s_ec5dbc9f_fromBlobBytesCount;
typedef struct _s_ec5dbc9f_fromBlob { void* value; } _s_ec5dbc9f_fromBlob;
typedef struct _s_ec5dbc9f_outProcedureCache { RedHandleProcedureCache* value; } _s_ec5dbc9f_outProcedureCache;
typedef struct _s_ec5dbc9f_outStatuses { RedStatuses* value; } _s_ec5dbc9f_outStatuses;
typedef struct _s_ec5dbc9f_optionalFile { char* value; } _s_ec5dbc9f_optionalFile;
typedef struct _s_ec5dbc9f_optionalLine { int value; } _s_ec5dbc9f_optionalLine;
typedef struct _s_ec5dbc9f_optionalUserData { void* value; } _s_ec5dbc9f_optionalUserData;
static inline _s_ec5dbc9f_context _ec5dbc9f_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_ec5dbc9f_context){value}; }
static inline _s_ec5dbc9f_gpu _ec5dbc9f_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_ec5dbc9f_gpu){value}; }
static inline _s_ec5dbc9f_handleName _ec5dbc9f_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ec5dbc9f_handleName){value}; }
static inline _s_ec5dbc9f_fromBlobBytesCount _ec5dbc9f_fromBlobBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_ec5dbc9f_fromBlobBytesCount){value}; }
static inline _s_ec5dbc9f_fromBlob _ec5dbc9f_fromBlob(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ec5dbc9f_fromBlob){value}; }
static inline _s_ec5dbc9f_outProcedureCache _ec5dbc9f_outProcedureCache(RedHandleProcedureCache* value) { return REDGPU_NP_STRUCT_INIT(_s_ec5dbc9f_outProcedureCache){value}; }
static inline _s_ec5dbc9f_outStatuses _ec5dbc9f_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_ec5dbc9f_outStatuses){value}; }
static inline _s_ec5dbc9f_optionalFile _ec5dbc9f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ec5dbc9f_optionalFile){value}; }
static inline _s_ec5dbc9f_optionalLine _ec5dbc9f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ec5dbc9f_optionalLine){value}; }
static inline _s_ec5dbc9f_optionalUserData _ec5dbc9f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ec5dbc9f_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateProcedureCache(_s_ec5dbc9f_context context, _s_ec5dbc9f_gpu gpu, _s_ec5dbc9f_handleName handleName, _s_ec5dbc9f_fromBlobBytesCount fromBlobBytesCount, _s_ec5dbc9f_fromBlob fromBlob, _s_ec5dbc9f_outProcedureCache outProcedureCache, _s_ec5dbc9f_outStatuses outStatuses, _s_ec5dbc9f_optionalFile optionalFile, _s_ec5dbc9f_optionalLine optionalLine, _s_ec5dbc9f_optionalUserData optionalUserData) {
  redCreateProcedureCache(context.value, gpu.value, handleName.value, fromBlobBytesCount.value, fromBlob.value, outProcedureCache.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateProcedure redCreateProcedure
#define _81f861ea_context(value) value
#define _81f861ea_gpu(value) value
#define _81f861ea_handleName(value) value
#define _81f861ea_procedureCache(value) value
#define _81f861ea_outputDeclaration(value) value
#define _81f861ea_procedureParameters(value) value
#define _81f861ea_gpuCodeVertexMainProcedureName(value) value
#define _81f861ea_gpuCodeVertex(value) value
#define _81f861ea_gpuCodeFragmentMainProcedureName(value) value
#define _81f861ea_gpuCodeFragment(value) value
#define _81f861ea_state(value) value
#define _81f861ea_stateExtension(value) value
#define _81f861ea_deriveBase(value) value
#define _81f861ea_deriveFrom(value) value
#define _81f861ea_outProcedure(value) value
#define _81f861ea_outStatuses(value) value
#define _81f861ea_optionalFile(value) value
#define _81f861ea_optionalLine(value) value
#define _81f861ea_optionalUserData(value) value
#else
typedef struct _s_81f861ea_context { RedContext value; } _s_81f861ea_context;
typedef struct _s_81f861ea_gpu { RedHandleGpu value; } _s_81f861ea_gpu;
typedef struct _s_81f861ea_handleName { char* value; } _s_81f861ea_handleName;
typedef struct _s_81f861ea_procedureCache { RedHandleProcedureCache value; } _s_81f861ea_procedureCache;
typedef struct _s_81f861ea_outputDeclaration { RedHandleOutputDeclaration value; } _s_81f861ea_outputDeclaration;
typedef struct _s_81f861ea_procedureParameters { RedHandleProcedureParameters value; } _s_81f861ea_procedureParameters;
typedef struct _s_81f861ea_gpuCodeVertexMainProcedureName { char* value; } _s_81f861ea_gpuCodeVertexMainProcedureName;
typedef struct _s_81f861ea_gpuCodeVertex { RedHandleGpuCode value; } _s_81f861ea_gpuCodeVertex;
typedef struct _s_81f861ea_gpuCodeFragmentMainProcedureName { char* value; } _s_81f861ea_gpuCodeFragmentMainProcedureName;
typedef struct _s_81f861ea_gpuCodeFragment { RedHandleGpuCode value; } _s_81f861ea_gpuCodeFragment;
typedef struct _s_81f861ea_state { RedProcedureState* value; } _s_81f861ea_state;
typedef struct _s_81f861ea_stateExtension { void* value; } _s_81f861ea_stateExtension;
typedef struct _s_81f861ea_deriveBase { RedBool32 value; } _s_81f861ea_deriveBase;
typedef struct _s_81f861ea_deriveFrom { RedHandleProcedure value; } _s_81f861ea_deriveFrom;
typedef struct _s_81f861ea_outProcedure { RedHandleProcedure* value; } _s_81f861ea_outProcedure;
typedef struct _s_81f861ea_outStatuses { RedStatuses* value; } _s_81f861ea_outStatuses;
typedef struct _s_81f861ea_optionalFile { char* value; } _s_81f861ea_optionalFile;
typedef struct _s_81f861ea_optionalLine { int value; } _s_81f861ea_optionalLine;
typedef struct _s_81f861ea_optionalUserData { void* value; } _s_81f861ea_optionalUserData;
static inline _s_81f861ea_context _81f861ea_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_context){value}; }
static inline _s_81f861ea_gpu _81f861ea_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_gpu){value}; }
static inline _s_81f861ea_handleName _81f861ea_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_handleName){value}; }
static inline _s_81f861ea_procedureCache _81f861ea_procedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_procedureCache){value}; }
static inline _s_81f861ea_outputDeclaration _81f861ea_outputDeclaration(RedHandleOutputDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_outputDeclaration){value}; }
static inline _s_81f861ea_procedureParameters _81f861ea_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_procedureParameters){value}; }
static inline _s_81f861ea_gpuCodeVertexMainProcedureName _81f861ea_gpuCodeVertexMainProcedureName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_gpuCodeVertexMainProcedureName){value}; }
static inline _s_81f861ea_gpuCodeVertex _81f861ea_gpuCodeVertex(RedHandleGpuCode value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_gpuCodeVertex){value}; }
static inline _s_81f861ea_gpuCodeFragmentMainProcedureName _81f861ea_gpuCodeFragmentMainProcedureName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_gpuCodeFragmentMainProcedureName){value}; }
static inline _s_81f861ea_gpuCodeFragment _81f861ea_gpuCodeFragment(RedHandleGpuCode value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_gpuCodeFragment){value}; }
static inline _s_81f861ea_state _81f861ea_state(RedProcedureState* value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_state){value}; }
static inline _s_81f861ea_stateExtension _81f861ea_stateExtension(void* value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_stateExtension){value}; }
static inline _s_81f861ea_deriveBase _81f861ea_deriveBase(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_deriveBase){value}; }
static inline _s_81f861ea_deriveFrom _81f861ea_deriveFrom(RedHandleProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_deriveFrom){value}; }
static inline _s_81f861ea_outProcedure _81f861ea_outProcedure(RedHandleProcedure* value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_outProcedure){value}; }
static inline _s_81f861ea_outStatuses _81f861ea_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_outStatuses){value}; }
static inline _s_81f861ea_optionalFile _81f861ea_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_optionalFile){value}; }
static inline _s_81f861ea_optionalLine _81f861ea_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_optionalLine){value}; }
static inline _s_81f861ea_optionalUserData _81f861ea_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_81f861ea_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateProcedure(_s_81f861ea_context context, _s_81f861ea_gpu gpu, _s_81f861ea_handleName handleName, _s_81f861ea_procedureCache procedureCache, _s_81f861ea_outputDeclaration outputDeclaration, _s_81f861ea_procedureParameters procedureParameters, _s_81f861ea_gpuCodeVertexMainProcedureName gpuCodeVertexMainProcedureName, _s_81f861ea_gpuCodeVertex gpuCodeVertex, _s_81f861ea_gpuCodeFragmentMainProcedureName gpuCodeFragmentMainProcedureName, _s_81f861ea_gpuCodeFragment gpuCodeFragment, _s_81f861ea_state state, _s_81f861ea_stateExtension stateExtension, _s_81f861ea_deriveBase deriveBase, _s_81f861ea_deriveFrom deriveFrom, _s_81f861ea_outProcedure outProcedure, _s_81f861ea_outStatuses outStatuses, _s_81f861ea_optionalFile optionalFile, _s_81f861ea_optionalLine optionalLine, _s_81f861ea_optionalUserData optionalUserData) {
  redCreateProcedure(context.value, gpu.value, handleName.value, procedureCache.value, outputDeclaration.value, procedureParameters.value, gpuCodeVertexMainProcedureName.value, gpuCodeVertex.value, gpuCodeFragmentMainProcedureName.value, gpuCodeFragment.value, state.value, stateExtension.value, deriveBase.value, deriveFrom.value, outProcedure.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateProcedureCompute redCreateProcedureCompute
#define _bd6d24cf_context(value) value
#define _bd6d24cf_gpu(value) value
#define _bd6d24cf_handleName(value) value
#define _bd6d24cf_procedureCache(value) value
#define _bd6d24cf_procedureParameters(value) value
#define _bd6d24cf_gpuCodeMainProcedureName(value) value
#define _bd6d24cf_gpuCode(value) value
#define _bd6d24cf_outProcedure(value) value
#define _bd6d24cf_outStatuses(value) value
#define _bd6d24cf_optionalFile(value) value
#define _bd6d24cf_optionalLine(value) value
#define _bd6d24cf_optionalUserData(value) value
#else
typedef struct _s_bd6d24cf_context { RedContext value; } _s_bd6d24cf_context;
typedef struct _s_bd6d24cf_gpu { RedHandleGpu value; } _s_bd6d24cf_gpu;
typedef struct _s_bd6d24cf_handleName { char* value; } _s_bd6d24cf_handleName;
typedef struct _s_bd6d24cf_procedureCache { RedHandleProcedureCache value; } _s_bd6d24cf_procedureCache;
typedef struct _s_bd6d24cf_procedureParameters { RedHandleProcedureParameters value; } _s_bd6d24cf_procedureParameters;
typedef struct _s_bd6d24cf_gpuCodeMainProcedureName { char* value; } _s_bd6d24cf_gpuCodeMainProcedureName;
typedef struct _s_bd6d24cf_gpuCode { RedHandleGpuCode value; } _s_bd6d24cf_gpuCode;
typedef struct _s_bd6d24cf_outProcedure { RedHandleProcedure* value; } _s_bd6d24cf_outProcedure;
typedef struct _s_bd6d24cf_outStatuses { RedStatuses* value; } _s_bd6d24cf_outStatuses;
typedef struct _s_bd6d24cf_optionalFile { char* value; } _s_bd6d24cf_optionalFile;
typedef struct _s_bd6d24cf_optionalLine { int value; } _s_bd6d24cf_optionalLine;
typedef struct _s_bd6d24cf_optionalUserData { void* value; } _s_bd6d24cf_optionalUserData;
static inline _s_bd6d24cf_context _bd6d24cf_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_bd6d24cf_context){value}; }
static inline _s_bd6d24cf_gpu _bd6d24cf_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_bd6d24cf_gpu){value}; }
static inline _s_bd6d24cf_handleName _bd6d24cf_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bd6d24cf_handleName){value}; }
static inline _s_bd6d24cf_procedureCache _bd6d24cf_procedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_bd6d24cf_procedureCache){value}; }
static inline _s_bd6d24cf_procedureParameters _bd6d24cf_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_bd6d24cf_procedureParameters){value}; }
static inline _s_bd6d24cf_gpuCodeMainProcedureName _bd6d24cf_gpuCodeMainProcedureName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bd6d24cf_gpuCodeMainProcedureName){value}; }
static inline _s_bd6d24cf_gpuCode _bd6d24cf_gpuCode(RedHandleGpuCode value) { return REDGPU_NP_STRUCT_INIT(_s_bd6d24cf_gpuCode){value}; }
static inline _s_bd6d24cf_outProcedure _bd6d24cf_outProcedure(RedHandleProcedure* value) { return REDGPU_NP_STRUCT_INIT(_s_bd6d24cf_outProcedure){value}; }
static inline _s_bd6d24cf_outStatuses _bd6d24cf_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_bd6d24cf_outStatuses){value}; }
static inline _s_bd6d24cf_optionalFile _bd6d24cf_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bd6d24cf_optionalFile){value}; }
static inline _s_bd6d24cf_optionalLine _bd6d24cf_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bd6d24cf_optionalLine){value}; }
static inline _s_bd6d24cf_optionalUserData _bd6d24cf_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bd6d24cf_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateProcedureCompute(_s_bd6d24cf_context context, _s_bd6d24cf_gpu gpu, _s_bd6d24cf_handleName handleName, _s_bd6d24cf_procedureCache procedureCache, _s_bd6d24cf_procedureParameters procedureParameters, _s_bd6d24cf_gpuCodeMainProcedureName gpuCodeMainProcedureName, _s_bd6d24cf_gpuCode gpuCode, _s_bd6d24cf_outProcedure outProcedure, _s_bd6d24cf_outStatuses outStatuses, _s_bd6d24cf_optionalFile optionalFile, _s_bd6d24cf_optionalLine optionalLine, _s_bd6d24cf_optionalUserData optionalUserData) {
  redCreateProcedureCompute(context.value, gpu.value, handleName.value, procedureCache.value, procedureParameters.value, gpuCodeMainProcedureName.value, gpuCode.value, outProcedure.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateOutput redCreateOutput
#define _242ac2a6_context(value) value
#define _242ac2a6_gpu(value) value
#define _242ac2a6_handleName(value) value
#define _242ac2a6_outputDeclaration(value) value
#define _242ac2a6_outputMembers(value) value
#define _242ac2a6_outputMembersResolveTargets(value) value
#define _242ac2a6_width(value) value
#define _242ac2a6_height(value) value
#define _242ac2a6_outOutput(value) value
#define _242ac2a6_outStatuses(value) value
#define _242ac2a6_optionalFile(value) value
#define _242ac2a6_optionalLine(value) value
#define _242ac2a6_optionalUserData(value) value
#else
typedef struct _s_242ac2a6_context { RedContext value; } _s_242ac2a6_context;
typedef struct _s_242ac2a6_gpu { RedHandleGpu value; } _s_242ac2a6_gpu;
typedef struct _s_242ac2a6_handleName { char* value; } _s_242ac2a6_handleName;
typedef struct _s_242ac2a6_outputDeclaration { RedHandleOutputDeclaration value; } _s_242ac2a6_outputDeclaration;
typedef struct _s_242ac2a6_outputMembers { RedOutputMembers* value; } _s_242ac2a6_outputMembers;
typedef struct _s_242ac2a6_outputMembersResolveTargets { RedOutputMembersResolveTargets* value; } _s_242ac2a6_outputMembersResolveTargets;
typedef struct _s_242ac2a6_width { unsigned value; } _s_242ac2a6_width;
typedef struct _s_242ac2a6_height { unsigned value; } _s_242ac2a6_height;
typedef struct _s_242ac2a6_outOutput { RedOutput* value; } _s_242ac2a6_outOutput;
typedef struct _s_242ac2a6_outStatuses { RedStatuses* value; } _s_242ac2a6_outStatuses;
typedef struct _s_242ac2a6_optionalFile { char* value; } _s_242ac2a6_optionalFile;
typedef struct _s_242ac2a6_optionalLine { int value; } _s_242ac2a6_optionalLine;
typedef struct _s_242ac2a6_optionalUserData { void* value; } _s_242ac2a6_optionalUserData;
static inline _s_242ac2a6_context _242ac2a6_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_context){value}; }
static inline _s_242ac2a6_gpu _242ac2a6_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_gpu){value}; }
static inline _s_242ac2a6_handleName _242ac2a6_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_handleName){value}; }
static inline _s_242ac2a6_outputDeclaration _242ac2a6_outputDeclaration(RedHandleOutputDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_outputDeclaration){value}; }
static inline _s_242ac2a6_outputMembers _242ac2a6_outputMembers(RedOutputMembers* value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_outputMembers){value}; }
static inline _s_242ac2a6_outputMembersResolveTargets _242ac2a6_outputMembersResolveTargets(RedOutputMembersResolveTargets* value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_outputMembersResolveTargets){value}; }
static inline _s_242ac2a6_width _242ac2a6_width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_width){value}; }
static inline _s_242ac2a6_height _242ac2a6_height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_height){value}; }
static inline _s_242ac2a6_outOutput _242ac2a6_outOutput(RedOutput* value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_outOutput){value}; }
static inline _s_242ac2a6_outStatuses _242ac2a6_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_outStatuses){value}; }
static inline _s_242ac2a6_optionalFile _242ac2a6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_optionalFile){value}; }
static inline _s_242ac2a6_optionalLine _242ac2a6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_optionalLine){value}; }
static inline _s_242ac2a6_optionalUserData _242ac2a6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_242ac2a6_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateOutput(_s_242ac2a6_context context, _s_242ac2a6_gpu gpu, _s_242ac2a6_handleName handleName, _s_242ac2a6_outputDeclaration outputDeclaration, _s_242ac2a6_outputMembers outputMembers, _s_242ac2a6_outputMembersResolveTargets outputMembersResolveTargets, _s_242ac2a6_width width, _s_242ac2a6_height height, _s_242ac2a6_outOutput outOutput, _s_242ac2a6_outStatuses outStatuses, _s_242ac2a6_optionalFile optionalFile, _s_242ac2a6_optionalLine optionalLine, _s_242ac2a6_optionalUserData optionalUserData) {
  redCreateOutput(context.value, gpu.value, handleName.value, outputDeclaration.value, outputMembers.value, outputMembersResolveTargets.value, width.value, height.value, outOutput.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateCpuSignal redCreateCpuSignal
#define _9dcf3e68_context(value) value
#define _9dcf3e68_gpu(value) value
#define _9dcf3e68_handleName(value) value
#define _9dcf3e68_createSignaled(value) value
#define _9dcf3e68_outCpuSignal(value) value
#define _9dcf3e68_outStatuses(value) value
#define _9dcf3e68_optionalFile(value) value
#define _9dcf3e68_optionalLine(value) value
#define _9dcf3e68_optionalUserData(value) value
#else
typedef struct _s_9dcf3e68_context { RedContext value; } _s_9dcf3e68_context;
typedef struct _s_9dcf3e68_gpu { RedHandleGpu value; } _s_9dcf3e68_gpu;
typedef struct _s_9dcf3e68_handleName { char* value; } _s_9dcf3e68_handleName;
typedef struct _s_9dcf3e68_createSignaled { RedBool32 value; } _s_9dcf3e68_createSignaled;
typedef struct _s_9dcf3e68_outCpuSignal { RedHandleCpuSignal* value; } _s_9dcf3e68_outCpuSignal;
typedef struct _s_9dcf3e68_outStatuses { RedStatuses* value; } _s_9dcf3e68_outStatuses;
typedef struct _s_9dcf3e68_optionalFile { char* value; } _s_9dcf3e68_optionalFile;
typedef struct _s_9dcf3e68_optionalLine { int value; } _s_9dcf3e68_optionalLine;
typedef struct _s_9dcf3e68_optionalUserData { void* value; } _s_9dcf3e68_optionalUserData;
static inline _s_9dcf3e68_context _9dcf3e68_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_9dcf3e68_context){value}; }
static inline _s_9dcf3e68_gpu _9dcf3e68_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_9dcf3e68_gpu){value}; }
static inline _s_9dcf3e68_handleName _9dcf3e68_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9dcf3e68_handleName){value}; }
static inline _s_9dcf3e68_createSignaled _9dcf3e68_createSignaled(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_9dcf3e68_createSignaled){value}; }
static inline _s_9dcf3e68_outCpuSignal _9dcf3e68_outCpuSignal(RedHandleCpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_9dcf3e68_outCpuSignal){value}; }
static inline _s_9dcf3e68_outStatuses _9dcf3e68_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_9dcf3e68_outStatuses){value}; }
static inline _s_9dcf3e68_optionalFile _9dcf3e68_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9dcf3e68_optionalFile){value}; }
static inline _s_9dcf3e68_optionalLine _9dcf3e68_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9dcf3e68_optionalLine){value}; }
static inline _s_9dcf3e68_optionalUserData _9dcf3e68_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9dcf3e68_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateCpuSignal(_s_9dcf3e68_context context, _s_9dcf3e68_gpu gpu, _s_9dcf3e68_handleName handleName, _s_9dcf3e68_createSignaled createSignaled, _s_9dcf3e68_outCpuSignal outCpuSignal, _s_9dcf3e68_outStatuses outStatuses, _s_9dcf3e68_optionalFile optionalFile, _s_9dcf3e68_optionalLine optionalLine, _s_9dcf3e68_optionalUserData optionalUserData) {
  redCreateCpuSignal(context.value, gpu.value, handleName.value, createSignaled.value, outCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateGpuSignal redCreateGpuSignal
#define _324fbb03_context(value) value
#define _324fbb03_gpu(value) value
#define _324fbb03_handleName(value) value
#define _324fbb03_outGpuSignal(value) value
#define _324fbb03_outStatuses(value) value
#define _324fbb03_optionalFile(value) value
#define _324fbb03_optionalLine(value) value
#define _324fbb03_optionalUserData(value) value
#else
typedef struct _s_324fbb03_context { RedContext value; } _s_324fbb03_context;
typedef struct _s_324fbb03_gpu { RedHandleGpu value; } _s_324fbb03_gpu;
typedef struct _s_324fbb03_handleName { char* value; } _s_324fbb03_handleName;
typedef struct _s_324fbb03_outGpuSignal { RedHandleGpuSignal* value; } _s_324fbb03_outGpuSignal;
typedef struct _s_324fbb03_outStatuses { RedStatuses* value; } _s_324fbb03_outStatuses;
typedef struct _s_324fbb03_optionalFile { char* value; } _s_324fbb03_optionalFile;
typedef struct _s_324fbb03_optionalLine { int value; } _s_324fbb03_optionalLine;
typedef struct _s_324fbb03_optionalUserData { void* value; } _s_324fbb03_optionalUserData;
static inline _s_324fbb03_context _324fbb03_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_324fbb03_context){value}; }
static inline _s_324fbb03_gpu _324fbb03_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_324fbb03_gpu){value}; }
static inline _s_324fbb03_handleName _324fbb03_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_324fbb03_handleName){value}; }
static inline _s_324fbb03_outGpuSignal _324fbb03_outGpuSignal(RedHandleGpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_324fbb03_outGpuSignal){value}; }
static inline _s_324fbb03_outStatuses _324fbb03_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_324fbb03_outStatuses){value}; }
static inline _s_324fbb03_optionalFile _324fbb03_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_324fbb03_optionalFile){value}; }
static inline _s_324fbb03_optionalLine _324fbb03_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_324fbb03_optionalLine){value}; }
static inline _s_324fbb03_optionalUserData _324fbb03_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_324fbb03_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateGpuSignal(_s_324fbb03_context context, _s_324fbb03_gpu gpu, _s_324fbb03_handleName handleName, _s_324fbb03_outGpuSignal outGpuSignal, _s_324fbb03_outStatuses outStatuses, _s_324fbb03_optionalFile optionalFile, _s_324fbb03_optionalLine optionalLine, _s_324fbb03_optionalUserData optionalUserData) {
  redCreateGpuSignal(context.value, gpu.value, handleName.value, outGpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateGpuToCpuSignal redCreateGpuToCpuSignal
#define _43b4b3d9_context(value) value
#define _43b4b3d9_gpu(value) value
#define _43b4b3d9_handleName(value) value
#define _43b4b3d9_outGpuToCpuSignal(value) value
#define _43b4b3d9_outStatuses(value) value
#define _43b4b3d9_optionalFile(value) value
#define _43b4b3d9_optionalLine(value) value
#define _43b4b3d9_optionalUserData(value) value
#else
typedef struct _s_43b4b3d9_context { RedContext value; } _s_43b4b3d9_context;
typedef struct _s_43b4b3d9_gpu { RedHandleGpu value; } _s_43b4b3d9_gpu;
typedef struct _s_43b4b3d9_handleName { char* value; } _s_43b4b3d9_handleName;
typedef struct _s_43b4b3d9_outGpuToCpuSignal { RedHandleGpuToCpuSignal* value; } _s_43b4b3d9_outGpuToCpuSignal;
typedef struct _s_43b4b3d9_outStatuses { RedStatuses* value; } _s_43b4b3d9_outStatuses;
typedef struct _s_43b4b3d9_optionalFile { char* value; } _s_43b4b3d9_optionalFile;
typedef struct _s_43b4b3d9_optionalLine { int value; } _s_43b4b3d9_optionalLine;
typedef struct _s_43b4b3d9_optionalUserData { void* value; } _s_43b4b3d9_optionalUserData;
static inline _s_43b4b3d9_context _43b4b3d9_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_43b4b3d9_context){value}; }
static inline _s_43b4b3d9_gpu _43b4b3d9_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_43b4b3d9_gpu){value}; }
static inline _s_43b4b3d9_handleName _43b4b3d9_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_43b4b3d9_handleName){value}; }
static inline _s_43b4b3d9_outGpuToCpuSignal _43b4b3d9_outGpuToCpuSignal(RedHandleGpuToCpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_43b4b3d9_outGpuToCpuSignal){value}; }
static inline _s_43b4b3d9_outStatuses _43b4b3d9_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_43b4b3d9_outStatuses){value}; }
static inline _s_43b4b3d9_optionalFile _43b4b3d9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_43b4b3d9_optionalFile){value}; }
static inline _s_43b4b3d9_optionalLine _43b4b3d9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_43b4b3d9_optionalLine){value}; }
static inline _s_43b4b3d9_optionalUserData _43b4b3d9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_43b4b3d9_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateGpuToCpuSignal(_s_43b4b3d9_context context, _s_43b4b3d9_gpu gpu, _s_43b4b3d9_handleName handleName, _s_43b4b3d9_outGpuToCpuSignal outGpuToCpuSignal, _s_43b4b3d9_outStatuses outStatuses, _s_43b4b3d9_optionalFile optionalFile, _s_43b4b3d9_optionalLine optionalLine, _s_43b4b3d9_optionalUserData optionalUserData) {
  redCreateGpuToCpuSignal(context.value, gpu.value, handleName.value, outGpuToCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateCalls redCreateCalls
#define _84a8f462_context(value) value
#define _84a8f462_gpu(value) value
#define _84a8f462_handleName(value) value
#define _84a8f462_queueFamilyIndex(value) value
#define _84a8f462_outCalls(value) value
#define _84a8f462_outStatuses(value) value
#define _84a8f462_optionalFile(value) value
#define _84a8f462_optionalLine(value) value
#define _84a8f462_optionalUserData(value) value
#else
typedef struct _s_84a8f462_context { RedContext value; } _s_84a8f462_context;
typedef struct _s_84a8f462_gpu { RedHandleGpu value; } _s_84a8f462_gpu;
typedef struct _s_84a8f462_handleName { char* value; } _s_84a8f462_handleName;
typedef struct _s_84a8f462_queueFamilyIndex { unsigned value; } _s_84a8f462_queueFamilyIndex;
typedef struct _s_84a8f462_outCalls { RedCalls* value; } _s_84a8f462_outCalls;
typedef struct _s_84a8f462_outStatuses { RedStatuses* value; } _s_84a8f462_outStatuses;
typedef struct _s_84a8f462_optionalFile { char* value; } _s_84a8f462_optionalFile;
typedef struct _s_84a8f462_optionalLine { int value; } _s_84a8f462_optionalLine;
typedef struct _s_84a8f462_optionalUserData { void* value; } _s_84a8f462_optionalUserData;
static inline _s_84a8f462_context _84a8f462_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_84a8f462_context){value}; }
static inline _s_84a8f462_gpu _84a8f462_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_84a8f462_gpu){value}; }
static inline _s_84a8f462_handleName _84a8f462_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_84a8f462_handleName){value}; }
static inline _s_84a8f462_queueFamilyIndex _84a8f462_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_84a8f462_queueFamilyIndex){value}; }
static inline _s_84a8f462_outCalls _84a8f462_outCalls(RedCalls* value) { return REDGPU_NP_STRUCT_INIT(_s_84a8f462_outCalls){value}; }
static inline _s_84a8f462_outStatuses _84a8f462_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_84a8f462_outStatuses){value}; }
static inline _s_84a8f462_optionalFile _84a8f462_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_84a8f462_optionalFile){value}; }
static inline _s_84a8f462_optionalLine _84a8f462_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_84a8f462_optionalLine){value}; }
static inline _s_84a8f462_optionalUserData _84a8f462_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_84a8f462_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateCalls(_s_84a8f462_context context, _s_84a8f462_gpu gpu, _s_84a8f462_handleName handleName, _s_84a8f462_queueFamilyIndex queueFamilyIndex, _s_84a8f462_outCalls outCalls, _s_84a8f462_outStatuses outStatuses, _s_84a8f462_optionalFile optionalFile, _s_84a8f462_optionalLine optionalLine, _s_84a8f462_optionalUserData optionalUserData) {
  redCreateCalls(context.value, gpu.value, handleName.value, queueFamilyIndex.value, outCalls.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateCallsReusable redCreateCallsReusable
#define _abac7e66_context(value) value
#define _abac7e66_gpu(value) value
#define _abac7e66_handleName(value) value
#define _abac7e66_queueFamilyIndex(value) value
#define _abac7e66_outCalls(value) value
#define _abac7e66_outStatuses(value) value
#define _abac7e66_optionalFile(value) value
#define _abac7e66_optionalLine(value) value
#define _abac7e66_optionalUserData(value) value
#else
typedef struct _s_abac7e66_context { RedContext value; } _s_abac7e66_context;
typedef struct _s_abac7e66_gpu { RedHandleGpu value; } _s_abac7e66_gpu;
typedef struct _s_abac7e66_handleName { char* value; } _s_abac7e66_handleName;
typedef struct _s_abac7e66_queueFamilyIndex { unsigned value; } _s_abac7e66_queueFamilyIndex;
typedef struct _s_abac7e66_outCalls { RedCalls* value; } _s_abac7e66_outCalls;
typedef struct _s_abac7e66_outStatuses { RedStatuses* value; } _s_abac7e66_outStatuses;
typedef struct _s_abac7e66_optionalFile { char* value; } _s_abac7e66_optionalFile;
typedef struct _s_abac7e66_optionalLine { int value; } _s_abac7e66_optionalLine;
typedef struct _s_abac7e66_optionalUserData { void* value; } _s_abac7e66_optionalUserData;
static inline _s_abac7e66_context _abac7e66_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_abac7e66_context){value}; }
static inline _s_abac7e66_gpu _abac7e66_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_abac7e66_gpu){value}; }
static inline _s_abac7e66_handleName _abac7e66_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_abac7e66_handleName){value}; }
static inline _s_abac7e66_queueFamilyIndex _abac7e66_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_abac7e66_queueFamilyIndex){value}; }
static inline _s_abac7e66_outCalls _abac7e66_outCalls(RedCalls* value) { return REDGPU_NP_STRUCT_INIT(_s_abac7e66_outCalls){value}; }
static inline _s_abac7e66_outStatuses _abac7e66_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_abac7e66_outStatuses){value}; }
static inline _s_abac7e66_optionalFile _abac7e66_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_abac7e66_optionalFile){value}; }
static inline _s_abac7e66_optionalLine _abac7e66_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_abac7e66_optionalLine){value}; }
static inline _s_abac7e66_optionalUserData _abac7e66_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_abac7e66_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateCallsReusable(_s_abac7e66_context context, _s_abac7e66_gpu gpu, _s_abac7e66_handleName handleName, _s_abac7e66_queueFamilyIndex queueFamilyIndex, _s_abac7e66_outCalls outCalls, _s_abac7e66_outStatuses outStatuses, _s_abac7e66_optionalFile optionalFile, _s_abac7e66_optionalLine optionalLine, _s_abac7e66_optionalUserData optionalUserData) {
  redCreateCallsReusable(context.value, gpu.value, handleName.value, queueFamilyIndex.value, outCalls.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyContext redDestroyContext
#define _e3956603_context(value) value
#define _e3956603_optionalFile(value) value
#define _e3956603_optionalLine(value) value
#define _e3956603_optionalUserData(value) value
#else
typedef struct _s_e3956603_context { RedContext value; } _s_e3956603_context;
typedef struct _s_e3956603_optionalFile { char* value; } _s_e3956603_optionalFile;
typedef struct _s_e3956603_optionalLine { int value; } _s_e3956603_optionalLine;
typedef struct _s_e3956603_optionalUserData { void* value; } _s_e3956603_optionalUserData;
static inline _s_e3956603_context _e3956603_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_e3956603_context){value}; }
static inline _s_e3956603_optionalFile _e3956603_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e3956603_optionalFile){value}; }
static inline _s_e3956603_optionalLine _e3956603_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e3956603_optionalLine){value}; }
static inline _s_e3956603_optionalUserData _e3956603_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e3956603_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyContext(_s_e3956603_context context, _s_e3956603_optionalFile optionalFile, _s_e3956603_optionalLine optionalLine, _s_e3956603_optionalUserData optionalUserData) {
  redDestroyContext(context.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyArray redDestroyArray
#define _8cba366d_context(value) value
#define _8cba366d_gpu(value) value
#define _8cba366d_array(value) value
#define _8cba366d_optionalFile(value) value
#define _8cba366d_optionalLine(value) value
#define _8cba366d_optionalUserData(value) value
#else
typedef struct _s_8cba366d_context { RedContext value; } _s_8cba366d_context;
typedef struct _s_8cba366d_gpu { RedHandleGpu value; } _s_8cba366d_gpu;
typedef struct _s_8cba366d_array { RedHandleArray value; } _s_8cba366d_array;
typedef struct _s_8cba366d_optionalFile { char* value; } _s_8cba366d_optionalFile;
typedef struct _s_8cba366d_optionalLine { int value; } _s_8cba366d_optionalLine;
typedef struct _s_8cba366d_optionalUserData { void* value; } _s_8cba366d_optionalUserData;
static inline _s_8cba366d_context _8cba366d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_8cba366d_context){value}; }
static inline _s_8cba366d_gpu _8cba366d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_8cba366d_gpu){value}; }
static inline _s_8cba366d_array _8cba366d_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_8cba366d_array){value}; }
static inline _s_8cba366d_optionalFile _8cba366d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8cba366d_optionalFile){value}; }
static inline _s_8cba366d_optionalLine _8cba366d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8cba366d_optionalLine){value}; }
static inline _s_8cba366d_optionalUserData _8cba366d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8cba366d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyArray(_s_8cba366d_context context, _s_8cba366d_gpu gpu, _s_8cba366d_array array, _s_8cba366d_optionalFile optionalFile, _s_8cba366d_optionalLine optionalLine, _s_8cba366d_optionalUserData optionalUserData) {
  redDestroyArray(context.value, gpu.value, array.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyImage redDestroyImage
#define _2878ba39_context(value) value
#define _2878ba39_gpu(value) value
#define _2878ba39_image(value) value
#define _2878ba39_optionalFile(value) value
#define _2878ba39_optionalLine(value) value
#define _2878ba39_optionalUserData(value) value
#else
typedef struct _s_2878ba39_context { RedContext value; } _s_2878ba39_context;
typedef struct _s_2878ba39_gpu { RedHandleGpu value; } _s_2878ba39_gpu;
typedef struct _s_2878ba39_image { RedHandleImage value; } _s_2878ba39_image;
typedef struct _s_2878ba39_optionalFile { char* value; } _s_2878ba39_optionalFile;
typedef struct _s_2878ba39_optionalLine { int value; } _s_2878ba39_optionalLine;
typedef struct _s_2878ba39_optionalUserData { void* value; } _s_2878ba39_optionalUserData;
static inline _s_2878ba39_context _2878ba39_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_2878ba39_context){value}; }
static inline _s_2878ba39_gpu _2878ba39_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_2878ba39_gpu){value}; }
static inline _s_2878ba39_image _2878ba39_image(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_2878ba39_image){value}; }
static inline _s_2878ba39_optionalFile _2878ba39_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2878ba39_optionalFile){value}; }
static inline _s_2878ba39_optionalLine _2878ba39_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2878ba39_optionalLine){value}; }
static inline _s_2878ba39_optionalUserData _2878ba39_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2878ba39_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyImage(_s_2878ba39_context context, _s_2878ba39_gpu gpu, _s_2878ba39_image image, _s_2878ba39_optionalFile optionalFile, _s_2878ba39_optionalLine optionalLine, _s_2878ba39_optionalUserData optionalUserData) {
  redDestroyImage(context.value, gpu.value, image.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroySampler redDestroySampler
#define _af6ed521_context(value) value
#define _af6ed521_gpu(value) value
#define _af6ed521_sampler(value) value
#define _af6ed521_optionalFile(value) value
#define _af6ed521_optionalLine(value) value
#define _af6ed521_optionalUserData(value) value
#else
typedef struct _s_af6ed521_context { RedContext value; } _s_af6ed521_context;
typedef struct _s_af6ed521_gpu { RedHandleGpu value; } _s_af6ed521_gpu;
typedef struct _s_af6ed521_sampler { RedHandleSampler value; } _s_af6ed521_sampler;
typedef struct _s_af6ed521_optionalFile { char* value; } _s_af6ed521_optionalFile;
typedef struct _s_af6ed521_optionalLine { int value; } _s_af6ed521_optionalLine;
typedef struct _s_af6ed521_optionalUserData { void* value; } _s_af6ed521_optionalUserData;
static inline _s_af6ed521_context _af6ed521_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_af6ed521_context){value}; }
static inline _s_af6ed521_gpu _af6ed521_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_af6ed521_gpu){value}; }
static inline _s_af6ed521_sampler _af6ed521_sampler(RedHandleSampler value) { return REDGPU_NP_STRUCT_INIT(_s_af6ed521_sampler){value}; }
static inline _s_af6ed521_optionalFile _af6ed521_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_af6ed521_optionalFile){value}; }
static inline _s_af6ed521_optionalLine _af6ed521_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_af6ed521_optionalLine){value}; }
static inline _s_af6ed521_optionalUserData _af6ed521_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_af6ed521_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroySampler(_s_af6ed521_context context, _s_af6ed521_gpu gpu, _s_af6ed521_sampler sampler, _s_af6ed521_optionalFile optionalFile, _s_af6ed521_optionalLine optionalLine, _s_af6ed521_optionalUserData optionalUserData) {
  redDestroySampler(context.value, gpu.value, sampler.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyTexture redDestroyTexture
#define _1c72da53_context(value) value
#define _1c72da53_gpu(value) value
#define _1c72da53_texture(value) value
#define _1c72da53_optionalFile(value) value
#define _1c72da53_optionalLine(value) value
#define _1c72da53_optionalUserData(value) value
#else
typedef struct _s_1c72da53_context { RedContext value; } _s_1c72da53_context;
typedef struct _s_1c72da53_gpu { RedHandleGpu value; } _s_1c72da53_gpu;
typedef struct _s_1c72da53_texture { RedHandleTexture value; } _s_1c72da53_texture;
typedef struct _s_1c72da53_optionalFile { char* value; } _s_1c72da53_optionalFile;
typedef struct _s_1c72da53_optionalLine { int value; } _s_1c72da53_optionalLine;
typedef struct _s_1c72da53_optionalUserData { void* value; } _s_1c72da53_optionalUserData;
static inline _s_1c72da53_context _1c72da53_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_1c72da53_context){value}; }
static inline _s_1c72da53_gpu _1c72da53_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_1c72da53_gpu){value}; }
static inline _s_1c72da53_texture _1c72da53_texture(RedHandleTexture value) { return REDGPU_NP_STRUCT_INIT(_s_1c72da53_texture){value}; }
static inline _s_1c72da53_optionalFile _1c72da53_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1c72da53_optionalFile){value}; }
static inline _s_1c72da53_optionalLine _1c72da53_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1c72da53_optionalLine){value}; }
static inline _s_1c72da53_optionalUserData _1c72da53_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1c72da53_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyTexture(_s_1c72da53_context context, _s_1c72da53_gpu gpu, _s_1c72da53_texture texture, _s_1c72da53_optionalFile optionalFile, _s_1c72da53_optionalLine optionalLine, _s_1c72da53_optionalUserData optionalUserData) {
  redDestroyTexture(context.value, gpu.value, texture.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyGpuCode redDestroyGpuCode
#define _deea23f2_context(value) value
#define _deea23f2_gpu(value) value
#define _deea23f2_gpuCode(value) value
#define _deea23f2_optionalFile(value) value
#define _deea23f2_optionalLine(value) value
#define _deea23f2_optionalUserData(value) value
#else
typedef struct _s_deea23f2_context { RedContext value; } _s_deea23f2_context;
typedef struct _s_deea23f2_gpu { RedHandleGpu value; } _s_deea23f2_gpu;
typedef struct _s_deea23f2_gpuCode { RedHandleGpuCode value; } _s_deea23f2_gpuCode;
typedef struct _s_deea23f2_optionalFile { char* value; } _s_deea23f2_optionalFile;
typedef struct _s_deea23f2_optionalLine { int value; } _s_deea23f2_optionalLine;
typedef struct _s_deea23f2_optionalUserData { void* value; } _s_deea23f2_optionalUserData;
static inline _s_deea23f2_context _deea23f2_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_deea23f2_context){value}; }
static inline _s_deea23f2_gpu _deea23f2_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_deea23f2_gpu){value}; }
static inline _s_deea23f2_gpuCode _deea23f2_gpuCode(RedHandleGpuCode value) { return REDGPU_NP_STRUCT_INIT(_s_deea23f2_gpuCode){value}; }
static inline _s_deea23f2_optionalFile _deea23f2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_deea23f2_optionalFile){value}; }
static inline _s_deea23f2_optionalLine _deea23f2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_deea23f2_optionalLine){value}; }
static inline _s_deea23f2_optionalUserData _deea23f2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_deea23f2_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyGpuCode(_s_deea23f2_context context, _s_deea23f2_gpu gpu, _s_deea23f2_gpuCode gpuCode, _s_deea23f2_optionalFile optionalFile, _s_deea23f2_optionalLine optionalLine, _s_deea23f2_optionalUserData optionalUserData) {
  redDestroyGpuCode(context.value, gpu.value, gpuCode.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyOutputDeclaration redDestroyOutputDeclaration
#define _88038ea3_context(value) value
#define _88038ea3_gpu(value) value
#define _88038ea3_outputDeclaration(value) value
#define _88038ea3_optionalFile(value) value
#define _88038ea3_optionalLine(value) value
#define _88038ea3_optionalUserData(value) value
#else
typedef struct _s_88038ea3_context { RedContext value; } _s_88038ea3_context;
typedef struct _s_88038ea3_gpu { RedHandleGpu value; } _s_88038ea3_gpu;
typedef struct _s_88038ea3_outputDeclaration { RedHandleOutputDeclaration value; } _s_88038ea3_outputDeclaration;
typedef struct _s_88038ea3_optionalFile { char* value; } _s_88038ea3_optionalFile;
typedef struct _s_88038ea3_optionalLine { int value; } _s_88038ea3_optionalLine;
typedef struct _s_88038ea3_optionalUserData { void* value; } _s_88038ea3_optionalUserData;
static inline _s_88038ea3_context _88038ea3_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_88038ea3_context){value}; }
static inline _s_88038ea3_gpu _88038ea3_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_88038ea3_gpu){value}; }
static inline _s_88038ea3_outputDeclaration _88038ea3_outputDeclaration(RedHandleOutputDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_88038ea3_outputDeclaration){value}; }
static inline _s_88038ea3_optionalFile _88038ea3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_88038ea3_optionalFile){value}; }
static inline _s_88038ea3_optionalLine _88038ea3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_88038ea3_optionalLine){value}; }
static inline _s_88038ea3_optionalUserData _88038ea3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_88038ea3_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyOutputDeclaration(_s_88038ea3_context context, _s_88038ea3_gpu gpu, _s_88038ea3_outputDeclaration outputDeclaration, _s_88038ea3_optionalFile optionalFile, _s_88038ea3_optionalLine optionalLine, _s_88038ea3_optionalUserData optionalUserData) {
  redDestroyOutputDeclaration(context.value, gpu.value, outputDeclaration.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyStructDeclaration redDestroyStructDeclaration
#define _f18dfa11_context(value) value
#define _f18dfa11_gpu(value) value
#define _f18dfa11_structDeclaration(value) value
#define _f18dfa11_optionalFile(value) value
#define _f18dfa11_optionalLine(value) value
#define _f18dfa11_optionalUserData(value) value
#else
typedef struct _s_f18dfa11_context { RedContext value; } _s_f18dfa11_context;
typedef struct _s_f18dfa11_gpu { RedHandleGpu value; } _s_f18dfa11_gpu;
typedef struct _s_f18dfa11_structDeclaration { RedHandleStructDeclaration value; } _s_f18dfa11_structDeclaration;
typedef struct _s_f18dfa11_optionalFile { char* value; } _s_f18dfa11_optionalFile;
typedef struct _s_f18dfa11_optionalLine { int value; } _s_f18dfa11_optionalLine;
typedef struct _s_f18dfa11_optionalUserData { void* value; } _s_f18dfa11_optionalUserData;
static inline _s_f18dfa11_context _f18dfa11_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_f18dfa11_context){value}; }
static inline _s_f18dfa11_gpu _f18dfa11_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_f18dfa11_gpu){value}; }
static inline _s_f18dfa11_structDeclaration _f18dfa11_structDeclaration(RedHandleStructDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_f18dfa11_structDeclaration){value}; }
static inline _s_f18dfa11_optionalFile _f18dfa11_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f18dfa11_optionalFile){value}; }
static inline _s_f18dfa11_optionalLine _f18dfa11_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f18dfa11_optionalLine){value}; }
static inline _s_f18dfa11_optionalUserData _f18dfa11_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f18dfa11_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyStructDeclaration(_s_f18dfa11_context context, _s_f18dfa11_gpu gpu, _s_f18dfa11_structDeclaration structDeclaration, _s_f18dfa11_optionalFile optionalFile, _s_f18dfa11_optionalLine optionalLine, _s_f18dfa11_optionalUserData optionalUserData) {
  redDestroyStructDeclaration(context.value, gpu.value, structDeclaration.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyProcedureParameters redDestroyProcedureParameters
#define _446caf7a_context(value) value
#define _446caf7a_gpu(value) value
#define _446caf7a_procedureParameters(value) value
#define _446caf7a_optionalFile(value) value
#define _446caf7a_optionalLine(value) value
#define _446caf7a_optionalUserData(value) value
#else
typedef struct _s_446caf7a_context { RedContext value; } _s_446caf7a_context;
typedef struct _s_446caf7a_gpu { RedHandleGpu value; } _s_446caf7a_gpu;
typedef struct _s_446caf7a_procedureParameters { RedHandleProcedureParameters value; } _s_446caf7a_procedureParameters;
typedef struct _s_446caf7a_optionalFile { char* value; } _s_446caf7a_optionalFile;
typedef struct _s_446caf7a_optionalLine { int value; } _s_446caf7a_optionalLine;
typedef struct _s_446caf7a_optionalUserData { void* value; } _s_446caf7a_optionalUserData;
static inline _s_446caf7a_context _446caf7a_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_446caf7a_context){value}; }
static inline _s_446caf7a_gpu _446caf7a_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_446caf7a_gpu){value}; }
static inline _s_446caf7a_procedureParameters _446caf7a_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_446caf7a_procedureParameters){value}; }
static inline _s_446caf7a_optionalFile _446caf7a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_446caf7a_optionalFile){value}; }
static inline _s_446caf7a_optionalLine _446caf7a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_446caf7a_optionalLine){value}; }
static inline _s_446caf7a_optionalUserData _446caf7a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_446caf7a_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyProcedureParameters(_s_446caf7a_context context, _s_446caf7a_gpu gpu, _s_446caf7a_procedureParameters procedureParameters, _s_446caf7a_optionalFile optionalFile, _s_446caf7a_optionalLine optionalLine, _s_446caf7a_optionalUserData optionalUserData) {
  redDestroyProcedureParameters(context.value, gpu.value, procedureParameters.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyProcedureCache redDestroyProcedureCache
#define _d2b903f0_context(value) value
#define _d2b903f0_gpu(value) value
#define _d2b903f0_procedureCache(value) value
#define _d2b903f0_optionalFile(value) value
#define _d2b903f0_optionalLine(value) value
#define _d2b903f0_optionalUserData(value) value
#else
typedef struct _s_d2b903f0_context { RedContext value; } _s_d2b903f0_context;
typedef struct _s_d2b903f0_gpu { RedHandleGpu value; } _s_d2b903f0_gpu;
typedef struct _s_d2b903f0_procedureCache { RedHandleProcedureCache value; } _s_d2b903f0_procedureCache;
typedef struct _s_d2b903f0_optionalFile { char* value; } _s_d2b903f0_optionalFile;
typedef struct _s_d2b903f0_optionalLine { int value; } _s_d2b903f0_optionalLine;
typedef struct _s_d2b903f0_optionalUserData { void* value; } _s_d2b903f0_optionalUserData;
static inline _s_d2b903f0_context _d2b903f0_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_d2b903f0_context){value}; }
static inline _s_d2b903f0_gpu _d2b903f0_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_d2b903f0_gpu){value}; }
static inline _s_d2b903f0_procedureCache _d2b903f0_procedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_d2b903f0_procedureCache){value}; }
static inline _s_d2b903f0_optionalFile _d2b903f0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d2b903f0_optionalFile){value}; }
static inline _s_d2b903f0_optionalLine _d2b903f0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d2b903f0_optionalLine){value}; }
static inline _s_d2b903f0_optionalUserData _d2b903f0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d2b903f0_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyProcedureCache(_s_d2b903f0_context context, _s_d2b903f0_gpu gpu, _s_d2b903f0_procedureCache procedureCache, _s_d2b903f0_optionalFile optionalFile, _s_d2b903f0_optionalLine optionalLine, _s_d2b903f0_optionalUserData optionalUserData) {
  redDestroyProcedureCache(context.value, gpu.value, procedureCache.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyProcedure redDestroyProcedure
#define _2beff629_context(value) value
#define _2beff629_gpu(value) value
#define _2beff629_procedure(value) value
#define _2beff629_optionalFile(value) value
#define _2beff629_optionalLine(value) value
#define _2beff629_optionalUserData(value) value
#else
typedef struct _s_2beff629_context { RedContext value; } _s_2beff629_context;
typedef struct _s_2beff629_gpu { RedHandleGpu value; } _s_2beff629_gpu;
typedef struct _s_2beff629_procedure { RedHandleProcedure value; } _s_2beff629_procedure;
typedef struct _s_2beff629_optionalFile { char* value; } _s_2beff629_optionalFile;
typedef struct _s_2beff629_optionalLine { int value; } _s_2beff629_optionalLine;
typedef struct _s_2beff629_optionalUserData { void* value; } _s_2beff629_optionalUserData;
static inline _s_2beff629_context _2beff629_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_2beff629_context){value}; }
static inline _s_2beff629_gpu _2beff629_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_2beff629_gpu){value}; }
static inline _s_2beff629_procedure _2beff629_procedure(RedHandleProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_2beff629_procedure){value}; }
static inline _s_2beff629_optionalFile _2beff629_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2beff629_optionalFile){value}; }
static inline _s_2beff629_optionalLine _2beff629_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2beff629_optionalLine){value}; }
static inline _s_2beff629_optionalUserData _2beff629_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2beff629_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyProcedure(_s_2beff629_context context, _s_2beff629_gpu gpu, _s_2beff629_procedure procedure, _s_2beff629_optionalFile optionalFile, _s_2beff629_optionalLine optionalLine, _s_2beff629_optionalUserData optionalUserData) {
  redDestroyProcedure(context.value, gpu.value, procedure.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyOutput redDestroyOutput
#define _39af47cf_context(value) value
#define _39af47cf_gpu(value) value
#define _39af47cf_output(value) value
#define _39af47cf_optionalFile(value) value
#define _39af47cf_optionalLine(value) value
#define _39af47cf_optionalUserData(value) value
#else
typedef struct _s_39af47cf_context { RedContext value; } _s_39af47cf_context;
typedef struct _s_39af47cf_gpu { RedHandleGpu value; } _s_39af47cf_gpu;
typedef struct _s_39af47cf_output { RedHandleOutput value; } _s_39af47cf_output;
typedef struct _s_39af47cf_optionalFile { char* value; } _s_39af47cf_optionalFile;
typedef struct _s_39af47cf_optionalLine { int value; } _s_39af47cf_optionalLine;
typedef struct _s_39af47cf_optionalUserData { void* value; } _s_39af47cf_optionalUserData;
static inline _s_39af47cf_context _39af47cf_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_39af47cf_context){value}; }
static inline _s_39af47cf_gpu _39af47cf_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_39af47cf_gpu){value}; }
static inline _s_39af47cf_output _39af47cf_output(RedHandleOutput value) { return REDGPU_NP_STRUCT_INIT(_s_39af47cf_output){value}; }
static inline _s_39af47cf_optionalFile _39af47cf_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_39af47cf_optionalFile){value}; }
static inline _s_39af47cf_optionalLine _39af47cf_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_39af47cf_optionalLine){value}; }
static inline _s_39af47cf_optionalUserData _39af47cf_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_39af47cf_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyOutput(_s_39af47cf_context context, _s_39af47cf_gpu gpu, _s_39af47cf_output output, _s_39af47cf_optionalFile optionalFile, _s_39af47cf_optionalLine optionalLine, _s_39af47cf_optionalUserData optionalUserData) {
  redDestroyOutput(context.value, gpu.value, output.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyCpuSignal redDestroyCpuSignal
#define _05dd4cf0_context(value) value
#define _05dd4cf0_gpu(value) value
#define _05dd4cf0_cpuSignal(value) value
#define _05dd4cf0_optionalFile(value) value
#define _05dd4cf0_optionalLine(value) value
#define _05dd4cf0_optionalUserData(value) value
#else
typedef struct _s_05dd4cf0_context { RedContext value; } _s_05dd4cf0_context;
typedef struct _s_05dd4cf0_gpu { RedHandleGpu value; } _s_05dd4cf0_gpu;
typedef struct _s_05dd4cf0_cpuSignal { RedHandleCpuSignal value; } _s_05dd4cf0_cpuSignal;
typedef struct _s_05dd4cf0_optionalFile { char* value; } _s_05dd4cf0_optionalFile;
typedef struct _s_05dd4cf0_optionalLine { int value; } _s_05dd4cf0_optionalLine;
typedef struct _s_05dd4cf0_optionalUserData { void* value; } _s_05dd4cf0_optionalUserData;
static inline _s_05dd4cf0_context _05dd4cf0_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_05dd4cf0_context){value}; }
static inline _s_05dd4cf0_gpu _05dd4cf0_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_05dd4cf0_gpu){value}; }
static inline _s_05dd4cf0_cpuSignal _05dd4cf0_cpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_05dd4cf0_cpuSignal){value}; }
static inline _s_05dd4cf0_optionalFile _05dd4cf0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_05dd4cf0_optionalFile){value}; }
static inline _s_05dd4cf0_optionalLine _05dd4cf0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_05dd4cf0_optionalLine){value}; }
static inline _s_05dd4cf0_optionalUserData _05dd4cf0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_05dd4cf0_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyCpuSignal(_s_05dd4cf0_context context, _s_05dd4cf0_gpu gpu, _s_05dd4cf0_cpuSignal cpuSignal, _s_05dd4cf0_optionalFile optionalFile, _s_05dd4cf0_optionalLine optionalLine, _s_05dd4cf0_optionalUserData optionalUserData) {
  redDestroyCpuSignal(context.value, gpu.value, cpuSignal.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyGpuSignal redDestroyGpuSignal
#define _efa16eff_context(value) value
#define _efa16eff_gpu(value) value
#define _efa16eff_gpuSignal(value) value
#define _efa16eff_optionalFile(value) value
#define _efa16eff_optionalLine(value) value
#define _efa16eff_optionalUserData(value) value
#else
typedef struct _s_efa16eff_context { RedContext value; } _s_efa16eff_context;
typedef struct _s_efa16eff_gpu { RedHandleGpu value; } _s_efa16eff_gpu;
typedef struct _s_efa16eff_gpuSignal { RedHandleGpuSignal value; } _s_efa16eff_gpuSignal;
typedef struct _s_efa16eff_optionalFile { char* value; } _s_efa16eff_optionalFile;
typedef struct _s_efa16eff_optionalLine { int value; } _s_efa16eff_optionalLine;
typedef struct _s_efa16eff_optionalUserData { void* value; } _s_efa16eff_optionalUserData;
static inline _s_efa16eff_context _efa16eff_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_efa16eff_context){value}; }
static inline _s_efa16eff_gpu _efa16eff_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_efa16eff_gpu){value}; }
static inline _s_efa16eff_gpuSignal _efa16eff_gpuSignal(RedHandleGpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_efa16eff_gpuSignal){value}; }
static inline _s_efa16eff_optionalFile _efa16eff_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_efa16eff_optionalFile){value}; }
static inline _s_efa16eff_optionalLine _efa16eff_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_efa16eff_optionalLine){value}; }
static inline _s_efa16eff_optionalUserData _efa16eff_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_efa16eff_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyGpuSignal(_s_efa16eff_context context, _s_efa16eff_gpu gpu, _s_efa16eff_gpuSignal gpuSignal, _s_efa16eff_optionalFile optionalFile, _s_efa16eff_optionalLine optionalLine, _s_efa16eff_optionalUserData optionalUserData) {
  redDestroyGpuSignal(context.value, gpu.value, gpuSignal.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyGpuToCpuSignal redDestroyGpuToCpuSignal
#define _9b866b42_context(value) value
#define _9b866b42_gpu(value) value
#define _9b866b42_gpuToCpuSignal(value) value
#define _9b866b42_optionalFile(value) value
#define _9b866b42_optionalLine(value) value
#define _9b866b42_optionalUserData(value) value
#else
typedef struct _s_9b866b42_context { RedContext value; } _s_9b866b42_context;
typedef struct _s_9b866b42_gpu { RedHandleGpu value; } _s_9b866b42_gpu;
typedef struct _s_9b866b42_gpuToCpuSignal { RedHandleGpuToCpuSignal value; } _s_9b866b42_gpuToCpuSignal;
typedef struct _s_9b866b42_optionalFile { char* value; } _s_9b866b42_optionalFile;
typedef struct _s_9b866b42_optionalLine { int value; } _s_9b866b42_optionalLine;
typedef struct _s_9b866b42_optionalUserData { void* value; } _s_9b866b42_optionalUserData;
static inline _s_9b866b42_context _9b866b42_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_9b866b42_context){value}; }
static inline _s_9b866b42_gpu _9b866b42_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_9b866b42_gpu){value}; }
static inline _s_9b866b42_gpuToCpuSignal _9b866b42_gpuToCpuSignal(RedHandleGpuToCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_9b866b42_gpuToCpuSignal){value}; }
static inline _s_9b866b42_optionalFile _9b866b42_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9b866b42_optionalFile){value}; }
static inline _s_9b866b42_optionalLine _9b866b42_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9b866b42_optionalLine){value}; }
static inline _s_9b866b42_optionalUserData _9b866b42_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9b866b42_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyGpuToCpuSignal(_s_9b866b42_context context, _s_9b866b42_gpu gpu, _s_9b866b42_gpuToCpuSignal gpuToCpuSignal, _s_9b866b42_optionalFile optionalFile, _s_9b866b42_optionalLine optionalLine, _s_9b866b42_optionalUserData optionalUserData) {
  redDestroyGpuToCpuSignal(context.value, gpu.value, gpuToCpuSignal.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyCalls redDestroyCalls
#define _de2e32b2_context(value) value
#define _de2e32b2_gpu(value) value
#define _de2e32b2_calls(value) value
#define _de2e32b2_callsMemory(value) value
#define _de2e32b2_optionalFile(value) value
#define _de2e32b2_optionalLine(value) value
#define _de2e32b2_optionalUserData(value) value
#else
typedef struct _s_de2e32b2_context { RedContext value; } _s_de2e32b2_context;
typedef struct _s_de2e32b2_gpu { RedHandleGpu value; } _s_de2e32b2_gpu;
typedef struct _s_de2e32b2_calls { RedHandleCalls value; } _s_de2e32b2_calls;
typedef struct _s_de2e32b2_callsMemory { RedHandleCallsMemory value; } _s_de2e32b2_callsMemory;
typedef struct _s_de2e32b2_optionalFile { char* value; } _s_de2e32b2_optionalFile;
typedef struct _s_de2e32b2_optionalLine { int value; } _s_de2e32b2_optionalLine;
typedef struct _s_de2e32b2_optionalUserData { void* value; } _s_de2e32b2_optionalUserData;
static inline _s_de2e32b2_context _de2e32b2_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_de2e32b2_context){value}; }
static inline _s_de2e32b2_gpu _de2e32b2_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_de2e32b2_gpu){value}; }
static inline _s_de2e32b2_calls _de2e32b2_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_de2e32b2_calls){value}; }
static inline _s_de2e32b2_callsMemory _de2e32b2_callsMemory(RedHandleCallsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_de2e32b2_callsMemory){value}; }
static inline _s_de2e32b2_optionalFile _de2e32b2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_de2e32b2_optionalFile){value}; }
static inline _s_de2e32b2_optionalLine _de2e32b2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_de2e32b2_optionalLine){value}; }
static inline _s_de2e32b2_optionalUserData _de2e32b2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_de2e32b2_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyCalls(_s_de2e32b2_context context, _s_de2e32b2_gpu gpu, _s_de2e32b2_calls calls, _s_de2e32b2_callsMemory callsMemory, _s_de2e32b2_optionalFile optionalFile, _s_de2e32b2_optionalLine optionalLine, _s_de2e32b2_optionalUserData optionalUserData) {
  redDestroyCalls(context.value, gpu.value, calls.value, callsMemory.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redProcedureCacheGetBlob redProcedureCacheGetBlob
#define _b55c2a5e_context(value) value
#define _b55c2a5e_gpu(value) value
#define _b55c2a5e_procedureCache(value) value
#define _b55c2a5e_outBlobBytesCount(value) value
#define _b55c2a5e_outBlob(value) value
#define _b55c2a5e_outStatuses(value) value
#define _b55c2a5e_optionalFile(value) value
#define _b55c2a5e_optionalLine(value) value
#define _b55c2a5e_optionalUserData(value) value
#else
typedef struct _s_b55c2a5e_context { RedContext value; } _s_b55c2a5e_context;
typedef struct _s_b55c2a5e_gpu { RedHandleGpu value; } _s_b55c2a5e_gpu;
typedef struct _s_b55c2a5e_procedureCache { RedHandleProcedureCache value; } _s_b55c2a5e_procedureCache;
typedef struct _s_b55c2a5e_outBlobBytesCount { uint64_t* value; } _s_b55c2a5e_outBlobBytesCount;
typedef struct _s_b55c2a5e_outBlob { void* value; } _s_b55c2a5e_outBlob;
typedef struct _s_b55c2a5e_outStatuses { RedStatuses* value; } _s_b55c2a5e_outStatuses;
typedef struct _s_b55c2a5e_optionalFile { char* value; } _s_b55c2a5e_optionalFile;
typedef struct _s_b55c2a5e_optionalLine { int value; } _s_b55c2a5e_optionalLine;
typedef struct _s_b55c2a5e_optionalUserData { void* value; } _s_b55c2a5e_optionalUserData;
static inline _s_b55c2a5e_context _b55c2a5e_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b55c2a5e_context){value}; }
static inline _s_b55c2a5e_gpu _b55c2a5e_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b55c2a5e_gpu){value}; }
static inline _s_b55c2a5e_procedureCache _b55c2a5e_procedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_b55c2a5e_procedureCache){value}; }
static inline _s_b55c2a5e_outBlobBytesCount _b55c2a5e_outBlobBytesCount(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_b55c2a5e_outBlobBytesCount){value}; }
static inline _s_b55c2a5e_outBlob _b55c2a5e_outBlob(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b55c2a5e_outBlob){value}; }
static inline _s_b55c2a5e_outStatuses _b55c2a5e_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b55c2a5e_outStatuses){value}; }
static inline _s_b55c2a5e_optionalFile _b55c2a5e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b55c2a5e_optionalFile){value}; }
static inline _s_b55c2a5e_optionalLine _b55c2a5e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b55c2a5e_optionalLine){value}; }
static inline _s_b55c2a5e_optionalUserData _b55c2a5e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b55c2a5e_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redProcedureCacheGetBlob(_s_b55c2a5e_context context, _s_b55c2a5e_gpu gpu, _s_b55c2a5e_procedureCache procedureCache, _s_b55c2a5e_outBlobBytesCount outBlobBytesCount, _s_b55c2a5e_outBlob outBlob, _s_b55c2a5e_outStatuses outStatuses, _s_b55c2a5e_optionalFile optionalFile, _s_b55c2a5e_optionalLine optionalLine, _s_b55c2a5e_optionalUserData optionalUserData) {
  redProcedureCacheGetBlob(context.value, gpu.value, procedureCache.value, outBlobBytesCount.value, outBlob.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redProcedureCacheMergeCaches redProcedureCacheMergeCaches
#define _af49ac68_context(value) value
#define _af49ac68_gpu(value) value
#define _af49ac68_sourceProcedureCachesCount(value) value
#define _af49ac68_sourceProcedureCaches(value) value
#define _af49ac68_targetProcedureCache(value) value
#define _af49ac68_outStatuses(value) value
#define _af49ac68_optionalFile(value) value
#define _af49ac68_optionalLine(value) value
#define _af49ac68_optionalUserData(value) value
#else
typedef struct _s_af49ac68_context { RedContext value; } _s_af49ac68_context;
typedef struct _s_af49ac68_gpu { RedHandleGpu value; } _s_af49ac68_gpu;
typedef struct _s_af49ac68_sourceProcedureCachesCount { unsigned value; } _s_af49ac68_sourceProcedureCachesCount;
typedef struct _s_af49ac68_sourceProcedureCaches { RedHandleProcedureCache* value; } _s_af49ac68_sourceProcedureCaches;
typedef struct _s_af49ac68_targetProcedureCache { RedHandleProcedureCache value; } _s_af49ac68_targetProcedureCache;
typedef struct _s_af49ac68_outStatuses { RedStatuses* value; } _s_af49ac68_outStatuses;
typedef struct _s_af49ac68_optionalFile { char* value; } _s_af49ac68_optionalFile;
typedef struct _s_af49ac68_optionalLine { int value; } _s_af49ac68_optionalLine;
typedef struct _s_af49ac68_optionalUserData { void* value; } _s_af49ac68_optionalUserData;
static inline _s_af49ac68_context _af49ac68_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_af49ac68_context){value}; }
static inline _s_af49ac68_gpu _af49ac68_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_af49ac68_gpu){value}; }
static inline _s_af49ac68_sourceProcedureCachesCount _af49ac68_sourceProcedureCachesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_af49ac68_sourceProcedureCachesCount){value}; }
static inline _s_af49ac68_sourceProcedureCaches _af49ac68_sourceProcedureCaches(RedHandleProcedureCache* value) { return REDGPU_NP_STRUCT_INIT(_s_af49ac68_sourceProcedureCaches){value}; }
static inline _s_af49ac68_targetProcedureCache _af49ac68_targetProcedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_af49ac68_targetProcedureCache){value}; }
static inline _s_af49ac68_outStatuses _af49ac68_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_af49ac68_outStatuses){value}; }
static inline _s_af49ac68_optionalFile _af49ac68_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_af49ac68_optionalFile){value}; }
static inline _s_af49ac68_optionalLine _af49ac68_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_af49ac68_optionalLine){value}; }
static inline _s_af49ac68_optionalUserData _af49ac68_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_af49ac68_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redProcedureCacheMergeCaches(_s_af49ac68_context context, _s_af49ac68_gpu gpu, _s_af49ac68_sourceProcedureCachesCount sourceProcedureCachesCount, _s_af49ac68_sourceProcedureCaches sourceProcedureCaches, _s_af49ac68_targetProcedureCache targetProcedureCache, _s_af49ac68_outStatuses outStatuses, _s_af49ac68_optionalFile optionalFile, _s_af49ac68_optionalLine optionalLine, _s_af49ac68_optionalUserData optionalUserData) {
  redProcedureCacheMergeCaches(context.value, gpu.value, sourceProcedureCachesCount.value, sourceProcedureCaches.value, targetProcedureCache.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCpuSignalGetStatus redCpuSignalGetStatus
#define _3e706476_context(value) value
#define _3e706476_gpu(value) value
#define _3e706476_cpuSignal(value) value
#define _3e706476_outStatus(value) value
#define _3e706476_optionalFile(value) value
#define _3e706476_optionalLine(value) value
#define _3e706476_optionalUserData(value) value
#else
typedef struct _s_3e706476_context { RedContext value; } _s_3e706476_context;
typedef struct _s_3e706476_gpu { RedHandleGpu value; } _s_3e706476_gpu;
typedef struct _s_3e706476_cpuSignal { RedHandleCpuSignal value; } _s_3e706476_cpuSignal;
typedef struct _s_3e706476_outStatus { RedStatus* value; } _s_3e706476_outStatus;
typedef struct _s_3e706476_optionalFile { char* value; } _s_3e706476_optionalFile;
typedef struct _s_3e706476_optionalLine { int value; } _s_3e706476_optionalLine;
typedef struct _s_3e706476_optionalUserData { void* value; } _s_3e706476_optionalUserData;
static inline _s_3e706476_context _3e706476_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_3e706476_context){value}; }
static inline _s_3e706476_gpu _3e706476_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_3e706476_gpu){value}; }
static inline _s_3e706476_cpuSignal _3e706476_cpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_3e706476_cpuSignal){value}; }
static inline _s_3e706476_outStatus _3e706476_outStatus(RedStatus* value) { return REDGPU_NP_STRUCT_INIT(_s_3e706476_outStatus){value}; }
static inline _s_3e706476_optionalFile _3e706476_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3e706476_optionalFile){value}; }
static inline _s_3e706476_optionalLine _3e706476_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3e706476_optionalLine){value}; }
static inline _s_3e706476_optionalUserData _3e706476_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3e706476_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCpuSignalGetStatus(_s_3e706476_context context, _s_3e706476_gpu gpu, _s_3e706476_cpuSignal cpuSignal, _s_3e706476_outStatus outStatus, _s_3e706476_optionalFile optionalFile, _s_3e706476_optionalLine optionalLine, _s_3e706476_optionalUserData optionalUserData) {
  redCpuSignalGetStatus(context.value, gpu.value, cpuSignal.value, outStatus.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCpuSignalWait redCpuSignalWait
#define _4a826452_context(value) value
#define _4a826452_gpu(value) value
#define _4a826452_cpuSignalsCount(value) value
#define _4a826452_cpuSignals(value) value
#define _4a826452_waitAll(value) value
#define _4a826452_outStatuses(value) value
#define _4a826452_optionalFile(value) value
#define _4a826452_optionalLine(value) value
#define _4a826452_optionalUserData(value) value
#else
typedef struct _s_4a826452_context { RedContext value; } _s_4a826452_context;
typedef struct _s_4a826452_gpu { RedHandleGpu value; } _s_4a826452_gpu;
typedef struct _s_4a826452_cpuSignalsCount { unsigned value; } _s_4a826452_cpuSignalsCount;
typedef struct _s_4a826452_cpuSignals { RedHandleCpuSignal* value; } _s_4a826452_cpuSignals;
typedef struct _s_4a826452_waitAll { RedBool32 value; } _s_4a826452_waitAll;
typedef struct _s_4a826452_outStatuses { RedStatuses* value; } _s_4a826452_outStatuses;
typedef struct _s_4a826452_optionalFile { char* value; } _s_4a826452_optionalFile;
typedef struct _s_4a826452_optionalLine { int value; } _s_4a826452_optionalLine;
typedef struct _s_4a826452_optionalUserData { void* value; } _s_4a826452_optionalUserData;
static inline _s_4a826452_context _4a826452_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_4a826452_context){value}; }
static inline _s_4a826452_gpu _4a826452_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_4a826452_gpu){value}; }
static inline _s_4a826452_cpuSignalsCount _4a826452_cpuSignalsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4a826452_cpuSignalsCount){value}; }
static inline _s_4a826452_cpuSignals _4a826452_cpuSignals(RedHandleCpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_4a826452_cpuSignals){value}; }
static inline _s_4a826452_waitAll _4a826452_waitAll(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_4a826452_waitAll){value}; }
static inline _s_4a826452_outStatuses _4a826452_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_4a826452_outStatuses){value}; }
static inline _s_4a826452_optionalFile _4a826452_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4a826452_optionalFile){value}; }
static inline _s_4a826452_optionalLine _4a826452_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4a826452_optionalLine){value}; }
static inline _s_4a826452_optionalUserData _4a826452_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4a826452_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCpuSignalWait(_s_4a826452_context context, _s_4a826452_gpu gpu, _s_4a826452_cpuSignalsCount cpuSignalsCount, _s_4a826452_cpuSignals cpuSignals, _s_4a826452_waitAll waitAll, _s_4a826452_outStatuses outStatuses, _s_4a826452_optionalFile optionalFile, _s_4a826452_optionalLine optionalLine, _s_4a826452_optionalUserData optionalUserData) {
  redCpuSignalWait(context.value, gpu.value, cpuSignalsCount.value, cpuSignals.value, waitAll.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCpuSignalUnsignal redCpuSignalUnsignal
#define _fd52e10b_context(value) value
#define _fd52e10b_gpu(value) value
#define _fd52e10b_cpuSignalsCount(value) value
#define _fd52e10b_cpuSignals(value) value
#define _fd52e10b_outStatuses(value) value
#define _fd52e10b_optionalFile(value) value
#define _fd52e10b_optionalLine(value) value
#define _fd52e10b_optionalUserData(value) value
#else
typedef struct _s_fd52e10b_context { RedContext value; } _s_fd52e10b_context;
typedef struct _s_fd52e10b_gpu { RedHandleGpu value; } _s_fd52e10b_gpu;
typedef struct _s_fd52e10b_cpuSignalsCount { unsigned value; } _s_fd52e10b_cpuSignalsCount;
typedef struct _s_fd52e10b_cpuSignals { RedHandleCpuSignal* value; } _s_fd52e10b_cpuSignals;
typedef struct _s_fd52e10b_outStatuses { RedStatuses* value; } _s_fd52e10b_outStatuses;
typedef struct _s_fd52e10b_optionalFile { char* value; } _s_fd52e10b_optionalFile;
typedef struct _s_fd52e10b_optionalLine { int value; } _s_fd52e10b_optionalLine;
typedef struct _s_fd52e10b_optionalUserData { void* value; } _s_fd52e10b_optionalUserData;
static inline _s_fd52e10b_context _fd52e10b_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_fd52e10b_context){value}; }
static inline _s_fd52e10b_gpu _fd52e10b_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_fd52e10b_gpu){value}; }
static inline _s_fd52e10b_cpuSignalsCount _fd52e10b_cpuSignalsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_fd52e10b_cpuSignalsCount){value}; }
static inline _s_fd52e10b_cpuSignals _fd52e10b_cpuSignals(RedHandleCpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_fd52e10b_cpuSignals){value}; }
static inline _s_fd52e10b_outStatuses _fd52e10b_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_fd52e10b_outStatuses){value}; }
static inline _s_fd52e10b_optionalFile _fd52e10b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fd52e10b_optionalFile){value}; }
static inline _s_fd52e10b_optionalLine _fd52e10b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fd52e10b_optionalLine){value}; }
static inline _s_fd52e10b_optionalUserData _fd52e10b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fd52e10b_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCpuSignalUnsignal(_s_fd52e10b_context context, _s_fd52e10b_gpu gpu, _s_fd52e10b_cpuSignalsCount cpuSignalsCount, _s_fd52e10b_cpuSignals cpuSignals, _s_fd52e10b_outStatuses outStatuses, _s_fd52e10b_optionalFile optionalFile, _s_fd52e10b_optionalLine optionalLine, _s_fd52e10b_optionalUserData optionalUserData) {
  redCpuSignalUnsignal(context.value, gpu.value, cpuSignalsCount.value, cpuSignals.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redGpuToCpuSignalGetStatus redGpuToCpuSignalGetStatus
#define _881955d2_context(value) value
#define _881955d2_gpu(value) value
#define _881955d2_gpuToCpuSignal(value) value
#define _881955d2_outStatus(value) value
#define _881955d2_optionalFile(value) value
#define _881955d2_optionalLine(value) value
#define _881955d2_optionalUserData(value) value
#else
typedef struct _s_881955d2_context { RedContext value; } _s_881955d2_context;
typedef struct _s_881955d2_gpu { RedHandleGpu value; } _s_881955d2_gpu;
typedef struct _s_881955d2_gpuToCpuSignal { RedHandleGpuToCpuSignal value; } _s_881955d2_gpuToCpuSignal;
typedef struct _s_881955d2_outStatus { RedStatus* value; } _s_881955d2_outStatus;
typedef struct _s_881955d2_optionalFile { char* value; } _s_881955d2_optionalFile;
typedef struct _s_881955d2_optionalLine { int value; } _s_881955d2_optionalLine;
typedef struct _s_881955d2_optionalUserData { void* value; } _s_881955d2_optionalUserData;
static inline _s_881955d2_context _881955d2_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_881955d2_context){value}; }
static inline _s_881955d2_gpu _881955d2_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_881955d2_gpu){value}; }
static inline _s_881955d2_gpuToCpuSignal _881955d2_gpuToCpuSignal(RedHandleGpuToCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_881955d2_gpuToCpuSignal){value}; }
static inline _s_881955d2_outStatus _881955d2_outStatus(RedStatus* value) { return REDGPU_NP_STRUCT_INIT(_s_881955d2_outStatus){value}; }
static inline _s_881955d2_optionalFile _881955d2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_881955d2_optionalFile){value}; }
static inline _s_881955d2_optionalLine _881955d2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_881955d2_optionalLine){value}; }
static inline _s_881955d2_optionalUserData _881955d2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_881955d2_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redGpuToCpuSignalGetStatus(_s_881955d2_context context, _s_881955d2_gpu gpu, _s_881955d2_gpuToCpuSignal gpuToCpuSignal, _s_881955d2_outStatus outStatus, _s_881955d2_optionalFile optionalFile, _s_881955d2_optionalLine optionalLine, _s_881955d2_optionalUserData optionalUserData) {
  redGpuToCpuSignalGetStatus(context.value, gpu.value, gpuToCpuSignal.value, outStatus.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redGpuToCpuSignalUnsignal redGpuToCpuSignalUnsignal
#define _ad347b4d_context(value) value
#define _ad347b4d_gpu(value) value
#define _ad347b4d_gpuToCpuSignal(value) value
#define _ad347b4d_outStatuses(value) value
#define _ad347b4d_optionalFile(value) value
#define _ad347b4d_optionalLine(value) value
#define _ad347b4d_optionalUserData(value) value
#else
typedef struct _s_ad347b4d_context { RedContext value; } _s_ad347b4d_context;
typedef struct _s_ad347b4d_gpu { RedHandleGpu value; } _s_ad347b4d_gpu;
typedef struct _s_ad347b4d_gpuToCpuSignal { RedHandleGpuToCpuSignal value; } _s_ad347b4d_gpuToCpuSignal;
typedef struct _s_ad347b4d_outStatuses { RedStatuses* value; } _s_ad347b4d_outStatuses;
typedef struct _s_ad347b4d_optionalFile { char* value; } _s_ad347b4d_optionalFile;
typedef struct _s_ad347b4d_optionalLine { int value; } _s_ad347b4d_optionalLine;
typedef struct _s_ad347b4d_optionalUserData { void* value; } _s_ad347b4d_optionalUserData;
static inline _s_ad347b4d_context _ad347b4d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_ad347b4d_context){value}; }
static inline _s_ad347b4d_gpu _ad347b4d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_ad347b4d_gpu){value}; }
static inline _s_ad347b4d_gpuToCpuSignal _ad347b4d_gpuToCpuSignal(RedHandleGpuToCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_ad347b4d_gpuToCpuSignal){value}; }
static inline _s_ad347b4d_outStatuses _ad347b4d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_ad347b4d_outStatuses){value}; }
static inline _s_ad347b4d_optionalFile _ad347b4d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ad347b4d_optionalFile){value}; }
static inline _s_ad347b4d_optionalLine _ad347b4d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ad347b4d_optionalLine){value}; }
static inline _s_ad347b4d_optionalUserData _ad347b4d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ad347b4d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redGpuToCpuSignalUnsignal(_s_ad347b4d_context context, _s_ad347b4d_gpu gpu, _s_ad347b4d_gpuToCpuSignal gpuToCpuSignal, _s_ad347b4d_outStatuses outStatuses, _s_ad347b4d_optionalFile optionalFile, _s_ad347b4d_optionalLine optionalLine, _s_ad347b4d_optionalUserData optionalUserData) {
  redGpuToCpuSignalUnsignal(context.value, gpu.value, gpuToCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallsSet redCallsSet
#define _23514538_context(value) value
#define _23514538_gpu(value) value
#define _23514538_calls(value) value
#define _23514538_callsMemory(value) value
#define _23514538_callsReusable(value) value
#define _23514538_outStatuses(value) value
#define _23514538_optionalFile(value) value
#define _23514538_optionalLine(value) value
#define _23514538_optionalUserData(value) value
#else
typedef struct _s_23514538_context { RedContext value; } _s_23514538_context;
typedef struct _s_23514538_gpu { RedHandleGpu value; } _s_23514538_gpu;
typedef struct _s_23514538_calls { RedHandleCalls value; } _s_23514538_calls;
typedef struct _s_23514538_callsMemory { RedHandleCallsMemory value; } _s_23514538_callsMemory;
typedef struct _s_23514538_callsReusable { RedBool32 value; } _s_23514538_callsReusable;
typedef struct _s_23514538_outStatuses { RedStatuses* value; } _s_23514538_outStatuses;
typedef struct _s_23514538_optionalFile { char* value; } _s_23514538_optionalFile;
typedef struct _s_23514538_optionalLine { int value; } _s_23514538_optionalLine;
typedef struct _s_23514538_optionalUserData { void* value; } _s_23514538_optionalUserData;
static inline _s_23514538_context _23514538_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_23514538_context){value}; }
static inline _s_23514538_gpu _23514538_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_23514538_gpu){value}; }
static inline _s_23514538_calls _23514538_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_23514538_calls){value}; }
static inline _s_23514538_callsMemory _23514538_callsMemory(RedHandleCallsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_23514538_callsMemory){value}; }
static inline _s_23514538_callsReusable _23514538_callsReusable(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_23514538_callsReusable){value}; }
static inline _s_23514538_outStatuses _23514538_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_23514538_outStatuses){value}; }
static inline _s_23514538_optionalFile _23514538_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_23514538_optionalFile){value}; }
static inline _s_23514538_optionalLine _23514538_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_23514538_optionalLine){value}; }
static inline _s_23514538_optionalUserData _23514538_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_23514538_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallsSet(_s_23514538_context context, _s_23514538_gpu gpu, _s_23514538_calls calls, _s_23514538_callsMemory callsMemory, _s_23514538_callsReusable callsReusable, _s_23514538_outStatuses outStatuses, _s_23514538_optionalFile optionalFile, _s_23514538_optionalLine optionalLine, _s_23514538_optionalUserData optionalUserData) {
  redCallsSet(context.value, gpu.value, calls.value, callsMemory.value, callsReusable.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallsEnd redCallsEnd
#define _2566f99f_context(value) value
#define _2566f99f_gpu(value) value
#define _2566f99f_calls(value) value
#define _2566f99f_callsMemory(value) value
#define _2566f99f_outStatuses(value) value
#define _2566f99f_optionalFile(value) value
#define _2566f99f_optionalLine(value) value
#define _2566f99f_optionalUserData(value) value
#else
typedef struct _s_2566f99f_context { RedContext value; } _s_2566f99f_context;
typedef struct _s_2566f99f_gpu { RedHandleGpu value; } _s_2566f99f_gpu;
typedef struct _s_2566f99f_calls { RedHandleCalls value; } _s_2566f99f_calls;
typedef struct _s_2566f99f_callsMemory { RedHandleCallsMemory value; } _s_2566f99f_callsMemory;
typedef struct _s_2566f99f_outStatuses { RedStatuses* value; } _s_2566f99f_outStatuses;
typedef struct _s_2566f99f_optionalFile { char* value; } _s_2566f99f_optionalFile;
typedef struct _s_2566f99f_optionalLine { int value; } _s_2566f99f_optionalLine;
typedef struct _s_2566f99f_optionalUserData { void* value; } _s_2566f99f_optionalUserData;
static inline _s_2566f99f_context _2566f99f_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_2566f99f_context){value}; }
static inline _s_2566f99f_gpu _2566f99f_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_2566f99f_gpu){value}; }
static inline _s_2566f99f_calls _2566f99f_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_2566f99f_calls){value}; }
static inline _s_2566f99f_callsMemory _2566f99f_callsMemory(RedHandleCallsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_2566f99f_callsMemory){value}; }
static inline _s_2566f99f_outStatuses _2566f99f_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_2566f99f_outStatuses){value}; }
static inline _s_2566f99f_optionalFile _2566f99f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2566f99f_optionalFile){value}; }
static inline _s_2566f99f_optionalLine _2566f99f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2566f99f_optionalLine){value}; }
static inline _s_2566f99f_optionalUserData _2566f99f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2566f99f_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallsEnd(_s_2566f99f_context context, _s_2566f99f_gpu gpu, _s_2566f99f_calls calls, _s_2566f99f_callsMemory callsMemory, _s_2566f99f_outStatuses outStatuses, _s_2566f99f_optionalFile optionalFile, _s_2566f99f_optionalLine optionalLine, _s_2566f99f_optionalUserData optionalUserData) {
  redCallsEnd(context.value, gpu.value, calls.value, callsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redGetCallProceduresAndAddresses redGetCallProceduresAndAddresses
#define _038a00b5_context(value) value
#define _038a00b5_gpu(value) value
#define _038a00b5_outCallProceduresAndAddresses(value) value
#define _038a00b5_outStatuses(value) value
#define _038a00b5_optionalFile(value) value
#define _038a00b5_optionalLine(value) value
#define _038a00b5_optionalUserData(value) value
#else
typedef struct _s_038a00b5_context { RedContext value; } _s_038a00b5_context;
typedef struct _s_038a00b5_gpu { RedHandleGpu value; } _s_038a00b5_gpu;
typedef struct _s_038a00b5_outCallProceduresAndAddresses { RedCallProceduresAndAddresses* value; } _s_038a00b5_outCallProceduresAndAddresses;
typedef struct _s_038a00b5_outStatuses { RedStatuses* value; } _s_038a00b5_outStatuses;
typedef struct _s_038a00b5_optionalFile { char* value; } _s_038a00b5_optionalFile;
typedef struct _s_038a00b5_optionalLine { int value; } _s_038a00b5_optionalLine;
typedef struct _s_038a00b5_optionalUserData { void* value; } _s_038a00b5_optionalUserData;
static inline _s_038a00b5_context _038a00b5_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_038a00b5_context){value}; }
static inline _s_038a00b5_gpu _038a00b5_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_038a00b5_gpu){value}; }
static inline _s_038a00b5_outCallProceduresAndAddresses _038a00b5_outCallProceduresAndAddresses(RedCallProceduresAndAddresses* value) { return REDGPU_NP_STRUCT_INIT(_s_038a00b5_outCallProceduresAndAddresses){value}; }
static inline _s_038a00b5_outStatuses _038a00b5_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_038a00b5_outStatuses){value}; }
static inline _s_038a00b5_optionalFile _038a00b5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_038a00b5_optionalFile){value}; }
static inline _s_038a00b5_optionalLine _038a00b5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_038a00b5_optionalLine){value}; }
static inline _s_038a00b5_optionalUserData _038a00b5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_038a00b5_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redGetCallProceduresAndAddresses(_s_038a00b5_context context, _s_038a00b5_gpu gpu, _s_038a00b5_outCallProceduresAndAddresses outCallProceduresAndAddresses, _s_038a00b5_outStatuses outStatuses, _s_038a00b5_optionalFile optionalFile, _s_038a00b5_optionalLine optionalLine, _s_038a00b5_optionalUserData optionalUserData) {
  redGetCallProceduresAndAddresses(context.value, gpu.value, outCallProceduresAndAddresses.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallGpuToCpuSignalSignal(_0, _1, _2, _3) _0(_1, _2, _3)
#define _87338edd_address(value) value
#define _87338edd_calls(value) value
#define _87338edd_signalGpuToCpuSignal(value) value
#define _87338edd_setTo8192(value) value
#else
typedef struct _s_87338edd_address { RedTypeProcedureCallGpuToCpuSignalSignal value; } _s_87338edd_address;
typedef struct _s_87338edd_calls { RedHandleCalls value; } _s_87338edd_calls;
typedef struct _s_87338edd_signalGpuToCpuSignal { RedHandleGpuToCpuSignal value; } _s_87338edd_signalGpuToCpuSignal;
typedef struct _s_87338edd_setTo8192 { unsigned value; } _s_87338edd_setTo8192;
static inline _s_87338edd_address _87338edd_address(RedTypeProcedureCallGpuToCpuSignalSignal value) { return REDGPU_NP_STRUCT_INIT(_s_87338edd_address){value}; }
static inline _s_87338edd_calls _87338edd_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_87338edd_calls){value}; }
static inline _s_87338edd_signalGpuToCpuSignal _87338edd_signalGpuToCpuSignal(RedHandleGpuToCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_87338edd_signalGpuToCpuSignal){value}; }
static inline _s_87338edd_setTo8192 _87338edd_setTo8192(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_87338edd_setTo8192){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallGpuToCpuSignalSignal(_s_87338edd_address address, _s_87338edd_calls calls, _s_87338edd_signalGpuToCpuSignal signalGpuToCpuSignal, _s_87338edd_setTo8192 setTo8192) {
  address.value(calls.value, signalGpuToCpuSignal.value, setTo8192.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallCopyArrayToArray(_0, _1, _2, _3, _4, _5) _0(_1, _2, _3, _4, _5)
#define _60652b4b_address(value) value
#define _60652b4b_calls(value) value
#define _60652b4b_arrayR(value) value
#define _60652b4b_arrayW(value) value
#define _60652b4b_rangesCount(value) value
#define _60652b4b_ranges(value) value
#else
typedef struct _s_60652b4b_address { RedTypeProcedureCallCopyArrayToArray value; } _s_60652b4b_address;
typedef struct _s_60652b4b_calls { RedHandleCalls value; } _s_60652b4b_calls;
typedef struct _s_60652b4b_arrayR { RedHandleArray value; } _s_60652b4b_arrayR;
typedef struct _s_60652b4b_arrayW { RedHandleArray value; } _s_60652b4b_arrayW;
typedef struct _s_60652b4b_rangesCount { unsigned value; } _s_60652b4b_rangesCount;
typedef struct _s_60652b4b_ranges { RedCopyArrayRange* value; } _s_60652b4b_ranges;
static inline _s_60652b4b_address _60652b4b_address(RedTypeProcedureCallCopyArrayToArray value) { return REDGPU_NP_STRUCT_INIT(_s_60652b4b_address){value}; }
static inline _s_60652b4b_calls _60652b4b_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_60652b4b_calls){value}; }
static inline _s_60652b4b_arrayR _60652b4b_arrayR(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_60652b4b_arrayR){value}; }
static inline _s_60652b4b_arrayW _60652b4b_arrayW(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_60652b4b_arrayW){value}; }
static inline _s_60652b4b_rangesCount _60652b4b_rangesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_60652b4b_rangesCount){value}; }
static inline _s_60652b4b_ranges _60652b4b_ranges(RedCopyArrayRange* value) { return REDGPU_NP_STRUCT_INIT(_s_60652b4b_ranges){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallCopyArrayToArray(_s_60652b4b_address address, _s_60652b4b_calls calls, _s_60652b4b_arrayR arrayR, _s_60652b4b_arrayW arrayW, _s_60652b4b_rangesCount rangesCount, _s_60652b4b_ranges ranges) {
  address.value(calls.value, arrayR.value, arrayW.value, rangesCount.value, ranges.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallCopyImageToImage(_0, _1, _2, _3, _4, _5, _6, _7) _0(_1, _2, _3, _4, _5, _6, _7)
#define _14b4d8f4_address(value) value
#define _14b4d8f4_calls(value) value
#define _14b4d8f4_imageR(value) value
#define _14b4d8f4_setTo1(value) value
#define _14b4d8f4_imageW(value) value
#define _14b4d8f4_setTo01(value) value
#define _14b4d8f4_rangesCount(value) value
#define _14b4d8f4_ranges(value) value
#else
typedef struct _s_14b4d8f4_address { RedTypeProcedureCallCopyImageToImage value; } _s_14b4d8f4_address;
typedef struct _s_14b4d8f4_calls { RedHandleCalls value; } _s_14b4d8f4_calls;
typedef struct _s_14b4d8f4_imageR { RedHandleImage value; } _s_14b4d8f4_imageR;
typedef struct _s_14b4d8f4_setTo1 { unsigned value; } _s_14b4d8f4_setTo1;
typedef struct _s_14b4d8f4_imageW { RedHandleImage value; } _s_14b4d8f4_imageW;
typedef struct _s_14b4d8f4_setTo01 { unsigned value; } _s_14b4d8f4_setTo01;
typedef struct _s_14b4d8f4_rangesCount { unsigned value; } _s_14b4d8f4_rangesCount;
typedef struct _s_14b4d8f4_ranges { RedCopyImageRange* value; } _s_14b4d8f4_ranges;
static inline _s_14b4d8f4_address _14b4d8f4_address(RedTypeProcedureCallCopyImageToImage value) { return REDGPU_NP_STRUCT_INIT(_s_14b4d8f4_address){value}; }
static inline _s_14b4d8f4_calls _14b4d8f4_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_14b4d8f4_calls){value}; }
static inline _s_14b4d8f4_imageR _14b4d8f4_imageR(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_14b4d8f4_imageR){value}; }
static inline _s_14b4d8f4_setTo1 _14b4d8f4_setTo1(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_14b4d8f4_setTo1){value}; }
static inline _s_14b4d8f4_imageW _14b4d8f4_imageW(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_14b4d8f4_imageW){value}; }
static inline _s_14b4d8f4_setTo01 _14b4d8f4_setTo01(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_14b4d8f4_setTo01){value}; }
static inline _s_14b4d8f4_rangesCount _14b4d8f4_rangesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_14b4d8f4_rangesCount){value}; }
static inline _s_14b4d8f4_ranges _14b4d8f4_ranges(RedCopyImageRange* value) { return REDGPU_NP_STRUCT_INIT(_s_14b4d8f4_ranges){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallCopyImageToImage(_s_14b4d8f4_address address, _s_14b4d8f4_calls calls, _s_14b4d8f4_imageR imageR, _s_14b4d8f4_setTo1 setTo1, _s_14b4d8f4_imageW imageW, _s_14b4d8f4_setTo01 setTo01, _s_14b4d8f4_rangesCount rangesCount, _s_14b4d8f4_ranges ranges) {
  address.value(calls.value, imageR.value, setTo1.value, imageW.value, setTo01.value, rangesCount.value, ranges.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallCopyArrayToImage(_0, _1, _2, _3, _4, _5, _6) _0(_1, _2, _3, _4, _5, _6)
#define _e68e8cba_address(value) value
#define _e68e8cba_calls(value) value
#define _e68e8cba_arrayR(value) value
#define _e68e8cba_imageW(value) value
#define _e68e8cba_setTo1(value) value
#define _e68e8cba_rangesCount(value) value
#define _e68e8cba_ranges(value) value
#else
typedef struct _s_e68e8cba_address { RedTypeProcedureCallCopyArrayToImage value; } _s_e68e8cba_address;
typedef struct _s_e68e8cba_calls { RedHandleCalls value; } _s_e68e8cba_calls;
typedef struct _s_e68e8cba_arrayR { RedHandleArray value; } _s_e68e8cba_arrayR;
typedef struct _s_e68e8cba_imageW { RedHandleImage value; } _s_e68e8cba_imageW;
typedef struct _s_e68e8cba_setTo1 { unsigned value; } _s_e68e8cba_setTo1;
typedef struct _s_e68e8cba_rangesCount { unsigned value; } _s_e68e8cba_rangesCount;
typedef struct _s_e68e8cba_ranges { RedCopyArrayImageRange* value; } _s_e68e8cba_ranges;
static inline _s_e68e8cba_address _e68e8cba_address(RedTypeProcedureCallCopyArrayToImage value) { return REDGPU_NP_STRUCT_INIT(_s_e68e8cba_address){value}; }
static inline _s_e68e8cba_calls _e68e8cba_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_e68e8cba_calls){value}; }
static inline _s_e68e8cba_arrayR _e68e8cba_arrayR(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_e68e8cba_arrayR){value}; }
static inline _s_e68e8cba_imageW _e68e8cba_imageW(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_e68e8cba_imageW){value}; }
static inline _s_e68e8cba_setTo1 _e68e8cba_setTo1(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e68e8cba_setTo1){value}; }
static inline _s_e68e8cba_rangesCount _e68e8cba_rangesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e68e8cba_rangesCount){value}; }
static inline _s_e68e8cba_ranges _e68e8cba_ranges(RedCopyArrayImageRange* value) { return REDGPU_NP_STRUCT_INIT(_s_e68e8cba_ranges){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallCopyArrayToImage(_s_e68e8cba_address address, _s_e68e8cba_calls calls, _s_e68e8cba_arrayR arrayR, _s_e68e8cba_imageW imageW, _s_e68e8cba_setTo1 setTo1, _s_e68e8cba_rangesCount rangesCount, _s_e68e8cba_ranges ranges) {
  address.value(calls.value, arrayR.value, imageW.value, setTo1.value, rangesCount.value, ranges.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallCopyImageToArray(_0, _1, _2, _3, _4, _5, _6) _0(_1, _2, _3, _4, _5, _6)
#define _4f794fd6_address(value) value
#define _4f794fd6_calls(value) value
#define _4f794fd6_imageR(value) value
#define _4f794fd6_setTo1(value) value
#define _4f794fd6_arrayW(value) value
#define _4f794fd6_rangesCount(value) value
#define _4f794fd6_ranges(value) value
#else
typedef struct _s_4f794fd6_address { RedTypeProcedureCallCopyImageToArray value; } _s_4f794fd6_address;
typedef struct _s_4f794fd6_calls { RedHandleCalls value; } _s_4f794fd6_calls;
typedef struct _s_4f794fd6_imageR { RedHandleImage value; } _s_4f794fd6_imageR;
typedef struct _s_4f794fd6_setTo1 { unsigned value; } _s_4f794fd6_setTo1;
typedef struct _s_4f794fd6_arrayW { RedHandleArray value; } _s_4f794fd6_arrayW;
typedef struct _s_4f794fd6_rangesCount { unsigned value; } _s_4f794fd6_rangesCount;
typedef struct _s_4f794fd6_ranges { RedCopyArrayImageRange* value; } _s_4f794fd6_ranges;
static inline _s_4f794fd6_address _4f794fd6_address(RedTypeProcedureCallCopyImageToArray value) { return REDGPU_NP_STRUCT_INIT(_s_4f794fd6_address){value}; }
static inline _s_4f794fd6_calls _4f794fd6_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_4f794fd6_calls){value}; }
static inline _s_4f794fd6_imageR _4f794fd6_imageR(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_4f794fd6_imageR){value}; }
static inline _s_4f794fd6_setTo1 _4f794fd6_setTo1(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4f794fd6_setTo1){value}; }
static inline _s_4f794fd6_arrayW _4f794fd6_arrayW(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_4f794fd6_arrayW){value}; }
static inline _s_4f794fd6_rangesCount _4f794fd6_rangesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4f794fd6_rangesCount){value}; }
static inline _s_4f794fd6_ranges _4f794fd6_ranges(RedCopyArrayImageRange* value) { return REDGPU_NP_STRUCT_INIT(_s_4f794fd6_ranges){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallCopyImageToArray(_s_4f794fd6_address address, _s_4f794fd6_calls calls, _s_4f794fd6_imageR imageR, _s_4f794fd6_setTo1 setTo1, _s_4f794fd6_arrayW arrayW, _s_4f794fd6_rangesCount rangesCount, _s_4f794fd6_ranges ranges) {
  address.value(calls.value, imageR.value, setTo1.value, arrayW.value, rangesCount.value, ranges.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallProcedure(_0, _1, _2, _3, _4, _5) _0(_1, _2, _3, _4, _5)
#define _1a3e7fa1_address(value) value
#define _1a3e7fa1_calls(value) value
#define _1a3e7fa1_vertexCount(value) value
#define _1a3e7fa1_instanceCount(value) value
#define _1a3e7fa1_vertexFirst(value) value
#define _1a3e7fa1_instanceFirst(value) value
#else
typedef struct _s_1a3e7fa1_address { RedTypeProcedureCallProcedure value; } _s_1a3e7fa1_address;
typedef struct _s_1a3e7fa1_calls { RedHandleCalls value; } _s_1a3e7fa1_calls;
typedef struct _s_1a3e7fa1_vertexCount { unsigned value; } _s_1a3e7fa1_vertexCount;
typedef struct _s_1a3e7fa1_instanceCount { unsigned value; } _s_1a3e7fa1_instanceCount;
typedef struct _s_1a3e7fa1_vertexFirst { unsigned value; } _s_1a3e7fa1_vertexFirst;
typedef struct _s_1a3e7fa1_instanceFirst { unsigned value; } _s_1a3e7fa1_instanceFirst;
static inline _s_1a3e7fa1_address _1a3e7fa1_address(RedTypeProcedureCallProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_1a3e7fa1_address){value}; }
static inline _s_1a3e7fa1_calls _1a3e7fa1_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_1a3e7fa1_calls){value}; }
static inline _s_1a3e7fa1_vertexCount _1a3e7fa1_vertexCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1a3e7fa1_vertexCount){value}; }
static inline _s_1a3e7fa1_instanceCount _1a3e7fa1_instanceCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1a3e7fa1_instanceCount){value}; }
static inline _s_1a3e7fa1_vertexFirst _1a3e7fa1_vertexFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1a3e7fa1_vertexFirst){value}; }
static inline _s_1a3e7fa1_instanceFirst _1a3e7fa1_instanceFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1a3e7fa1_instanceFirst){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallProcedure(_s_1a3e7fa1_address address, _s_1a3e7fa1_calls calls, _s_1a3e7fa1_vertexCount vertexCount, _s_1a3e7fa1_instanceCount instanceCount, _s_1a3e7fa1_vertexFirst vertexFirst, _s_1a3e7fa1_instanceFirst instanceFirst) {
  address.value(calls.value, vertexCount.value, instanceCount.value, vertexFirst.value, instanceFirst.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallProcedureIndexed(_0, _1, _2, _3, _4, _5, _6) _0(_1, _2, _3, _4, _5, _6)
#define _46f9defa_address(value) value
#define _46f9defa_calls(value) value
#define _46f9defa_indexCount(value) value
#define _46f9defa_instanceCount(value) value
#define _46f9defa_indexFirst(value) value
#define _46f9defa_vertexBase(value) value
#define _46f9defa_instanceFirst(value) value
#else
typedef struct _s_46f9defa_address { RedTypeProcedureCallProcedureIndexed value; } _s_46f9defa_address;
typedef struct _s_46f9defa_calls { RedHandleCalls value; } _s_46f9defa_calls;
typedef struct _s_46f9defa_indexCount { unsigned value; } _s_46f9defa_indexCount;
typedef struct _s_46f9defa_instanceCount { unsigned value; } _s_46f9defa_instanceCount;
typedef struct _s_46f9defa_indexFirst { unsigned value; } _s_46f9defa_indexFirst;
typedef struct _s_46f9defa_vertexBase { int value; } _s_46f9defa_vertexBase;
typedef struct _s_46f9defa_instanceFirst { unsigned value; } _s_46f9defa_instanceFirst;
static inline _s_46f9defa_address _46f9defa_address(RedTypeProcedureCallProcedureIndexed value) { return REDGPU_NP_STRUCT_INIT(_s_46f9defa_address){value}; }
static inline _s_46f9defa_calls _46f9defa_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_46f9defa_calls){value}; }
static inline _s_46f9defa_indexCount _46f9defa_indexCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_46f9defa_indexCount){value}; }
static inline _s_46f9defa_instanceCount _46f9defa_instanceCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_46f9defa_instanceCount){value}; }
static inline _s_46f9defa_indexFirst _46f9defa_indexFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_46f9defa_indexFirst){value}; }
static inline _s_46f9defa_vertexBase _46f9defa_vertexBase(int value) { return REDGPU_NP_STRUCT_INIT(_s_46f9defa_vertexBase){value}; }
static inline _s_46f9defa_instanceFirst _46f9defa_instanceFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_46f9defa_instanceFirst){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallProcedureIndexed(_s_46f9defa_address address, _s_46f9defa_calls calls, _s_46f9defa_indexCount indexCount, _s_46f9defa_instanceCount instanceCount, _s_46f9defa_indexFirst indexFirst, _s_46f9defa_vertexBase vertexBase, _s_46f9defa_instanceFirst instanceFirst) {
  address.value(calls.value, indexCount.value, instanceCount.value, indexFirst.value, vertexBase.value, instanceFirst.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallProcedureCompute(_0, _1, _2, _3, _4) _0(_1, _2, _3, _4)
#define _17fa22b3_address(value) value
#define _17fa22b3_calls(value) value
#define _17fa22b3_workgroupsCountX(value) value
#define _17fa22b3_workgroupsCountY(value) value
#define _17fa22b3_workgroupsCountZ(value) value
#else
typedef struct _s_17fa22b3_address { RedTypeProcedureCallProcedureCompute value; } _s_17fa22b3_address;
typedef struct _s_17fa22b3_calls { RedHandleCalls value; } _s_17fa22b3_calls;
typedef struct _s_17fa22b3_workgroupsCountX { unsigned value; } _s_17fa22b3_workgroupsCountX;
typedef struct _s_17fa22b3_workgroupsCountY { unsigned value; } _s_17fa22b3_workgroupsCountY;
typedef struct _s_17fa22b3_workgroupsCountZ { unsigned value; } _s_17fa22b3_workgroupsCountZ;
static inline _s_17fa22b3_address _17fa22b3_address(RedTypeProcedureCallProcedureCompute value) { return REDGPU_NP_STRUCT_INIT(_s_17fa22b3_address){value}; }
static inline _s_17fa22b3_calls _17fa22b3_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_17fa22b3_calls){value}; }
static inline _s_17fa22b3_workgroupsCountX _17fa22b3_workgroupsCountX(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_17fa22b3_workgroupsCountX){value}; }
static inline _s_17fa22b3_workgroupsCountY _17fa22b3_workgroupsCountY(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_17fa22b3_workgroupsCountY){value}; }
static inline _s_17fa22b3_workgroupsCountZ _17fa22b3_workgroupsCountZ(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_17fa22b3_workgroupsCountZ){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallProcedureCompute(_s_17fa22b3_address address, _s_17fa22b3_calls calls, _s_17fa22b3_workgroupsCountX workgroupsCountX, _s_17fa22b3_workgroupsCountY workgroupsCountY, _s_17fa22b3_workgroupsCountZ workgroupsCountZ) {
  address.value(calls.value, workgroupsCountX.value, workgroupsCountY.value, workgroupsCountZ.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetProcedure(_0, _1, _2, _3) _0(_1, _2, _3)
#define _16d79404_address(value) value
#define _16d79404_calls(value) value
#define _16d79404_procedureType(value) value
#define _16d79404_procedure(value) value
#else
typedef struct _s_16d79404_address { RedTypeProcedureCallSetProcedure value; } _s_16d79404_address;
typedef struct _s_16d79404_calls { RedHandleCalls value; } _s_16d79404_calls;
typedef struct _s_16d79404_procedureType { RedProcedureType value; } _s_16d79404_procedureType;
typedef struct _s_16d79404_procedure { RedHandleProcedure value; } _s_16d79404_procedure;
static inline _s_16d79404_address _16d79404_address(RedTypeProcedureCallSetProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_16d79404_address){value}; }
static inline _s_16d79404_calls _16d79404_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_16d79404_calls){value}; }
static inline _s_16d79404_procedureType _16d79404_procedureType(RedProcedureType value) { return REDGPU_NP_STRUCT_INIT(_s_16d79404_procedureType){value}; }
static inline _s_16d79404_procedure _16d79404_procedure(RedHandleProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_16d79404_procedure){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetProcedure(_s_16d79404_address address, _s_16d79404_calls calls, _s_16d79404_procedureType procedureType, _s_16d79404_procedure procedure) {
  address.value(calls.value, procedureType.value, procedure.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetProcedureIndices(_0, _1, _2, _3, _4) _0(_1, _2, _3, _4)
#define _fc588166_address(value) value
#define _fc588166_calls(value) value
#define _fc588166_array(value) value
#define _fc588166_setTo0(value) value
#define _fc588166_setTo1(value) value
#else
typedef struct _s_fc588166_address { RedTypeProcedureCallSetProcedureIndices value; } _s_fc588166_address;
typedef struct _s_fc588166_calls { RedHandleCalls value; } _s_fc588166_calls;
typedef struct _s_fc588166_array { RedHandleArray value; } _s_fc588166_array;
typedef struct _s_fc588166_setTo0 { uint64_t value; } _s_fc588166_setTo0;
typedef struct _s_fc588166_setTo1 { unsigned value; } _s_fc588166_setTo1;
static inline _s_fc588166_address _fc588166_address(RedTypeProcedureCallSetProcedureIndices value) { return REDGPU_NP_STRUCT_INIT(_s_fc588166_address){value}; }
static inline _s_fc588166_calls _fc588166_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_fc588166_calls){value}; }
static inline _s_fc588166_array _fc588166_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_fc588166_array){value}; }
static inline _s_fc588166_setTo0 _fc588166_setTo0(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_fc588166_setTo0){value}; }
static inline _s_fc588166_setTo1 _fc588166_setTo1(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_fc588166_setTo1){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetProcedureIndices(_s_fc588166_address address, _s_fc588166_calls calls, _s_fc588166_array array, _s_fc588166_setTo0 setTo0, _s_fc588166_setTo1 setTo1) {
  address.value(calls.value, array.value, setTo0.value, setTo1.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetProcedureParametersVariables(_0, _1, _2, _3, _4, _5, _6) _0(_1, _2, _3, _4, _5, _6)
#define _cba9ac89_address(value) value
#define _cba9ac89_calls(value) value
#define _cba9ac89_procedureParameters(value) value
#define _cba9ac89_visibleToStages(value) value
#define _cba9ac89_variablesBytesFirst(value) value
#define _cba9ac89_dataBytesCount(value) value
#define _cba9ac89_data(value) value
#else
typedef struct _s_cba9ac89_address { RedTypeProcedureCallSetProcedureParametersVariables value; } _s_cba9ac89_address;
typedef struct _s_cba9ac89_calls { RedHandleCalls value; } _s_cba9ac89_calls;
typedef struct _s_cba9ac89_procedureParameters { RedHandleProcedureParameters value; } _s_cba9ac89_procedureParameters;
typedef struct _s_cba9ac89_visibleToStages { RedVisibleToStageBitflags value; } _s_cba9ac89_visibleToStages;
typedef struct _s_cba9ac89_variablesBytesFirst { unsigned value; } _s_cba9ac89_variablesBytesFirst;
typedef struct _s_cba9ac89_dataBytesCount { unsigned value; } _s_cba9ac89_dataBytesCount;
typedef struct _s_cba9ac89_data { void* value; } _s_cba9ac89_data;
static inline _s_cba9ac89_address _cba9ac89_address(RedTypeProcedureCallSetProcedureParametersVariables value) { return REDGPU_NP_STRUCT_INIT(_s_cba9ac89_address){value}; }
static inline _s_cba9ac89_calls _cba9ac89_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_cba9ac89_calls){value}; }
static inline _s_cba9ac89_procedureParameters _cba9ac89_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_cba9ac89_procedureParameters){value}; }
static inline _s_cba9ac89_visibleToStages _cba9ac89_visibleToStages(RedVisibleToStageBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_cba9ac89_visibleToStages){value}; }
static inline _s_cba9ac89_variablesBytesFirst _cba9ac89_variablesBytesFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cba9ac89_variablesBytesFirst){value}; }
static inline _s_cba9ac89_dataBytesCount _cba9ac89_dataBytesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cba9ac89_dataBytesCount){value}; }
static inline _s_cba9ac89_data _cba9ac89_data(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cba9ac89_data){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetProcedureParametersVariables(_s_cba9ac89_address address, _s_cba9ac89_calls calls, _s_cba9ac89_procedureParameters procedureParameters, _s_cba9ac89_visibleToStages visibleToStages, _s_cba9ac89_variablesBytesFirst variablesBytesFirst, _s_cba9ac89_dataBytesCount dataBytesCount, _s_cba9ac89_data data) {
  address.value(calls.value, procedureParameters.value, visibleToStages.value, variablesBytesFirst.value, dataBytesCount.value, data.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetProcedureParametersStructs(_0, _1, _2, _3, _4, _5, _6, _7, _8) _0(_1, _2, _3, _4, _5, _6, _7, _8)
#define _b6fcba5e_address(value) value
#define _b6fcba5e_calls(value) value
#define _b6fcba5e_procedureType(value) value
#define _b6fcba5e_procedureParameters(value) value
#define _b6fcba5e_procedureParametersDeclarationStructsDeclarationsFirst(value) value
#define _b6fcba5e_structsCount(value) value
#define _b6fcba5e_structs(value) value
#define _b6fcba5e_setTo0(value) value
#define _b6fcba5e_setTo00(value) value
#else
typedef struct _s_b6fcba5e_address { RedTypeProcedureCallSetProcedureParametersStructs value; } _s_b6fcba5e_address;
typedef struct _s_b6fcba5e_calls { RedHandleCalls value; } _s_b6fcba5e_calls;
typedef struct _s_b6fcba5e_procedureType { RedProcedureType value; } _s_b6fcba5e_procedureType;
typedef struct _s_b6fcba5e_procedureParameters { RedHandleProcedureParameters value; } _s_b6fcba5e_procedureParameters;
typedef struct _s_b6fcba5e_procedureParametersDeclarationStructsDeclarationsFirst { unsigned value; } _s_b6fcba5e_procedureParametersDeclarationStructsDeclarationsFirst;
typedef struct _s_b6fcba5e_structsCount { unsigned value; } _s_b6fcba5e_structsCount;
typedef struct _s_b6fcba5e_structs { RedHandleStruct* value; } _s_b6fcba5e_structs;
typedef struct _s_b6fcba5e_setTo0 { unsigned value; } _s_b6fcba5e_setTo0;
typedef struct _s_b6fcba5e_setTo00 { size_t value; } _s_b6fcba5e_setTo00;
static inline _s_b6fcba5e_address _b6fcba5e_address(RedTypeProcedureCallSetProcedureParametersStructs value) { return REDGPU_NP_STRUCT_INIT(_s_b6fcba5e_address){value}; }
static inline _s_b6fcba5e_calls _b6fcba5e_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_b6fcba5e_calls){value}; }
static inline _s_b6fcba5e_procedureType _b6fcba5e_procedureType(RedProcedureType value) { return REDGPU_NP_STRUCT_INIT(_s_b6fcba5e_procedureType){value}; }
static inline _s_b6fcba5e_procedureParameters _b6fcba5e_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_b6fcba5e_procedureParameters){value}; }
static inline _s_b6fcba5e_procedureParametersDeclarationStructsDeclarationsFirst _b6fcba5e_procedureParametersDeclarationStructsDeclarationsFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b6fcba5e_procedureParametersDeclarationStructsDeclarationsFirst){value}; }
static inline _s_b6fcba5e_structsCount _b6fcba5e_structsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b6fcba5e_structsCount){value}; }
static inline _s_b6fcba5e_structs _b6fcba5e_structs(RedHandleStruct* value) { return REDGPU_NP_STRUCT_INIT(_s_b6fcba5e_structs){value}; }
static inline _s_b6fcba5e_setTo0 _b6fcba5e_setTo0(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b6fcba5e_setTo0){value}; }
static inline _s_b6fcba5e_setTo00 _b6fcba5e_setTo00(size_t value) { return REDGPU_NP_STRUCT_INIT(_s_b6fcba5e_setTo00){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetProcedureParametersStructs(_s_b6fcba5e_address address, _s_b6fcba5e_calls calls, _s_b6fcba5e_procedureType procedureType, _s_b6fcba5e_procedureParameters procedureParameters, _s_b6fcba5e_procedureParametersDeclarationStructsDeclarationsFirst procedureParametersDeclarationStructsDeclarationsFirst, _s_b6fcba5e_structsCount structsCount, _s_b6fcba5e_structs structs, _s_b6fcba5e_setTo0 setTo0, _s_b6fcba5e_setTo00 setTo00) {
  address.value(calls.value, procedureType.value, procedureParameters.value, procedureParametersDeclarationStructsDeclarationsFirst.value, structsCount.value, structs.value, setTo0.value, setTo00.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetProcedureParametersHandles(_0, _1, _2, _3, _4, _5, _6) _0(_1, _2, _3, _4, _5, _6)
#define _63e4f50e_address(value) value
#define _63e4f50e_calls(value) value
#define _63e4f50e_procedureType(value) value
#define _63e4f50e_procedureParameters(value) value
#define _63e4f50e_procedureParametersDeclarationStructsDeclarationsCount(value) value
#define _63e4f50e_handlesCount(value) value
#define _63e4f50e_handles(value) value
#else
typedef struct _s_63e4f50e_address { RedTypeProcedureCallSetProcedureParametersHandles value; } _s_63e4f50e_address;
typedef struct _s_63e4f50e_calls { RedHandleCalls value; } _s_63e4f50e_calls;
typedef struct _s_63e4f50e_procedureType { RedProcedureType value; } _s_63e4f50e_procedureType;
typedef struct _s_63e4f50e_procedureParameters { RedHandleProcedureParameters value; } _s_63e4f50e_procedureParameters;
typedef struct _s_63e4f50e_procedureParametersDeclarationStructsDeclarationsCount { unsigned value; } _s_63e4f50e_procedureParametersDeclarationStructsDeclarationsCount;
typedef struct _s_63e4f50e_handlesCount { unsigned value; } _s_63e4f50e_handlesCount;
typedef struct _s_63e4f50e_handles { RedProcedureParametersHandle* value; } _s_63e4f50e_handles;
static inline _s_63e4f50e_address _63e4f50e_address(RedTypeProcedureCallSetProcedureParametersHandles value) { return REDGPU_NP_STRUCT_INIT(_s_63e4f50e_address){value}; }
static inline _s_63e4f50e_calls _63e4f50e_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_63e4f50e_calls){value}; }
static inline _s_63e4f50e_procedureType _63e4f50e_procedureType(RedProcedureType value) { return REDGPU_NP_STRUCT_INIT(_s_63e4f50e_procedureType){value}; }
static inline _s_63e4f50e_procedureParameters _63e4f50e_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_63e4f50e_procedureParameters){value}; }
static inline _s_63e4f50e_procedureParametersDeclarationStructsDeclarationsCount _63e4f50e_procedureParametersDeclarationStructsDeclarationsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_63e4f50e_procedureParametersDeclarationStructsDeclarationsCount){value}; }
static inline _s_63e4f50e_handlesCount _63e4f50e_handlesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_63e4f50e_handlesCount){value}; }
static inline _s_63e4f50e_handles _63e4f50e_handles(RedProcedureParametersHandle* value) { return REDGPU_NP_STRUCT_INIT(_s_63e4f50e_handles){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetProcedureParametersHandles(_s_63e4f50e_address address, _s_63e4f50e_calls calls, _s_63e4f50e_procedureType procedureType, _s_63e4f50e_procedureParameters procedureParameters, _s_63e4f50e_procedureParametersDeclarationStructsDeclarationsCount procedureParametersDeclarationStructsDeclarationsCount, _s_63e4f50e_handlesCount handlesCount, _s_63e4f50e_handles handles) {
  address.value(calls.value, procedureType.value, procedureParameters.value, procedureParametersDeclarationStructsDeclarationsCount.value, handlesCount.value, handles.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetDynamicDepthBias(_0, _1, _2, _3, _4) _0(_1, _2, _3, _4)
#define _704bca01_address(value) value
#define _704bca01_calls(value) value
#define _704bca01_constantFactor(value) value
#define _704bca01_clamp(value) value
#define _704bca01_slopeFactor(value) value
#else
typedef struct _s_704bca01_address { RedTypeProcedureCallSetDynamicDepthBias value; } _s_704bca01_address;
typedef struct _s_704bca01_calls { RedHandleCalls value; } _s_704bca01_calls;
typedef struct _s_704bca01_constantFactor { float value; } _s_704bca01_constantFactor;
typedef struct _s_704bca01_clamp { float value; } _s_704bca01_clamp;
typedef struct _s_704bca01_slopeFactor { float value; } _s_704bca01_slopeFactor;
static inline _s_704bca01_address _704bca01_address(RedTypeProcedureCallSetDynamicDepthBias value) { return REDGPU_NP_STRUCT_INIT(_s_704bca01_address){value}; }
static inline _s_704bca01_calls _704bca01_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_704bca01_calls){value}; }
static inline _s_704bca01_constantFactor _704bca01_constantFactor(float value) { return REDGPU_NP_STRUCT_INIT(_s_704bca01_constantFactor){value}; }
static inline _s_704bca01_clamp _704bca01_clamp(float value) { return REDGPU_NP_STRUCT_INIT(_s_704bca01_clamp){value}; }
static inline _s_704bca01_slopeFactor _704bca01_slopeFactor(float value) { return REDGPU_NP_STRUCT_INIT(_s_704bca01_slopeFactor){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetDynamicDepthBias(_s_704bca01_address address, _s_704bca01_calls calls, _s_704bca01_constantFactor constantFactor, _s_704bca01_clamp clamp, _s_704bca01_slopeFactor slopeFactor) {
  address.value(calls.value, constantFactor.value, clamp.value, slopeFactor.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetDynamicDepthBounds(_0, _1, _2, _3) _0(_1, _2, _3)
#define _0b3dca08_address(value) value
#define _0b3dca08_calls(value) value
#define _0b3dca08_min(value) value
#define _0b3dca08_max(value) value
#else
typedef struct _s_0b3dca08_address { RedTypeProcedureCallSetDynamicDepthBounds value; } _s_0b3dca08_address;
typedef struct _s_0b3dca08_calls { RedHandleCalls value; } _s_0b3dca08_calls;
typedef struct _s_0b3dca08_min { float value; } _s_0b3dca08_min;
typedef struct _s_0b3dca08_max { float value; } _s_0b3dca08_max;
static inline _s_0b3dca08_address _0b3dca08_address(RedTypeProcedureCallSetDynamicDepthBounds value) { return REDGPU_NP_STRUCT_INIT(_s_0b3dca08_address){value}; }
static inline _s_0b3dca08_calls _0b3dca08_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_0b3dca08_calls){value}; }
static inline _s_0b3dca08_min _0b3dca08_min(float value) { return REDGPU_NP_STRUCT_INIT(_s_0b3dca08_min){value}; }
static inline _s_0b3dca08_max _0b3dca08_max(float value) { return REDGPU_NP_STRUCT_INIT(_s_0b3dca08_max){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetDynamicDepthBounds(_s_0b3dca08_address address, _s_0b3dca08_calls calls, _s_0b3dca08_min min, _s_0b3dca08_max max) {
  address.value(calls.value, min.value, max.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetDynamicStencilCompareMask(_0, _1, _2, _3) _0(_1, _2, _3)
#define _49fbcd04_address(value) value
#define _49fbcd04_calls(value) value
#define _49fbcd04_face(value) value
#define _49fbcd04_compareMask(value) value
#else
typedef struct _s_49fbcd04_address { RedTypeProcedureCallSetDynamicStencilCompareMask value; } _s_49fbcd04_address;
typedef struct _s_49fbcd04_calls { RedHandleCalls value; } _s_49fbcd04_calls;
typedef struct _s_49fbcd04_face { RedStencilFace value; } _s_49fbcd04_face;
typedef struct _s_49fbcd04_compareMask { unsigned value; } _s_49fbcd04_compareMask;
static inline _s_49fbcd04_address _49fbcd04_address(RedTypeProcedureCallSetDynamicStencilCompareMask value) { return REDGPU_NP_STRUCT_INIT(_s_49fbcd04_address){value}; }
static inline _s_49fbcd04_calls _49fbcd04_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_49fbcd04_calls){value}; }
static inline _s_49fbcd04_face _49fbcd04_face(RedStencilFace value) { return REDGPU_NP_STRUCT_INIT(_s_49fbcd04_face){value}; }
static inline _s_49fbcd04_compareMask _49fbcd04_compareMask(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_49fbcd04_compareMask){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetDynamicStencilCompareMask(_s_49fbcd04_address address, _s_49fbcd04_calls calls, _s_49fbcd04_face face, _s_49fbcd04_compareMask compareMask) {
  address.value(calls.value, face.value, compareMask.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetDynamicStencilWriteMask(_0, _1, _2, _3) _0(_1, _2, _3)
#define _b029fa3c_address(value) value
#define _b029fa3c_calls(value) value
#define _b029fa3c_face(value) value
#define _b029fa3c_writeMask(value) value
#else
typedef struct _s_b029fa3c_address { RedTypeProcedureCallSetDynamicStencilWriteMask value; } _s_b029fa3c_address;
typedef struct _s_b029fa3c_calls { RedHandleCalls value; } _s_b029fa3c_calls;
typedef struct _s_b029fa3c_face { RedStencilFace value; } _s_b029fa3c_face;
typedef struct _s_b029fa3c_writeMask { unsigned value; } _s_b029fa3c_writeMask;
static inline _s_b029fa3c_address _b029fa3c_address(RedTypeProcedureCallSetDynamicStencilWriteMask value) { return REDGPU_NP_STRUCT_INIT(_s_b029fa3c_address){value}; }
static inline _s_b029fa3c_calls _b029fa3c_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_b029fa3c_calls){value}; }
static inline _s_b029fa3c_face _b029fa3c_face(RedStencilFace value) { return REDGPU_NP_STRUCT_INIT(_s_b029fa3c_face){value}; }
static inline _s_b029fa3c_writeMask _b029fa3c_writeMask(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b029fa3c_writeMask){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetDynamicStencilWriteMask(_s_b029fa3c_address address, _s_b029fa3c_calls calls, _s_b029fa3c_face face, _s_b029fa3c_writeMask writeMask) {
  address.value(calls.value, face.value, writeMask.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetDynamicStencilReference(_0, _1, _2, _3) _0(_1, _2, _3)
#define _2d80c0fb_address(value) value
#define _2d80c0fb_calls(value) value
#define _2d80c0fb_face(value) value
#define _2d80c0fb_reference(value) value
#else
typedef struct _s_2d80c0fb_address { RedTypeProcedureCallSetDynamicStencilReference value; } _s_2d80c0fb_address;
typedef struct _s_2d80c0fb_calls { RedHandleCalls value; } _s_2d80c0fb_calls;
typedef struct _s_2d80c0fb_face { RedStencilFace value; } _s_2d80c0fb_face;
typedef struct _s_2d80c0fb_reference { unsigned value; } _s_2d80c0fb_reference;
static inline _s_2d80c0fb_address _2d80c0fb_address(RedTypeProcedureCallSetDynamicStencilReference value) { return REDGPU_NP_STRUCT_INIT(_s_2d80c0fb_address){value}; }
static inline _s_2d80c0fb_calls _2d80c0fb_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_2d80c0fb_calls){value}; }
static inline _s_2d80c0fb_face _2d80c0fb_face(RedStencilFace value) { return REDGPU_NP_STRUCT_INIT(_s_2d80c0fb_face){value}; }
static inline _s_2d80c0fb_reference _2d80c0fb_reference(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_2d80c0fb_reference){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetDynamicStencilReference(_s_2d80c0fb_address address, _s_2d80c0fb_calls calls, _s_2d80c0fb_face face, _s_2d80c0fb_reference reference) {
  address.value(calls.value, face.value, reference.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetDynamicBlendConstants(_0, _1, _2) _0(_1, _2)
#define _8f3db010_address(value) value
#define _8f3db010_calls(value) value
#define _8f3db010_blendConstants(value) value
#else
typedef struct _s_8f3db010_address { RedTypeProcedureCallSetDynamicBlendConstants value; } _s_8f3db010_address;
typedef struct _s_8f3db010_calls { RedHandleCalls value; } _s_8f3db010_calls;
typedef struct _s_8f3db010_blendConstants { float* value; } _s_8f3db010_blendConstants;
static inline _s_8f3db010_address _8f3db010_address(RedTypeProcedureCallSetDynamicBlendConstants value) { return REDGPU_NP_STRUCT_INIT(_s_8f3db010_address){value}; }
static inline _s_8f3db010_calls _8f3db010_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_8f3db010_calls){value}; }
static inline _s_8f3db010_blendConstants _8f3db010_blendConstants(float* value) { return REDGPU_NP_STRUCT_INIT(_s_8f3db010_blendConstants){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetDynamicBlendConstants(_s_8f3db010_address address, _s_8f3db010_calls calls, _s_8f3db010_blendConstants blendConstants) {
  address.value(calls.value, blendConstants.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetDynamicViewport redCallSetDynamicViewport
#define _4f3a2630_address(value) value
#define _4f3a2630_calls(value) value
#define _4f3a2630_x(value) value
#define _4f3a2630_y(value) value
#define _4f3a2630_width(value) value
#define _4f3a2630_height(value) value
#define _4f3a2630_depthMin(value) value
#define _4f3a2630_depthMax(value) value
#else
typedef struct _s_4f3a2630_address { RedTypeProcedureAddressCallSetDynamicViewport value; } _s_4f3a2630_address;
typedef struct _s_4f3a2630_calls { RedHandleCalls value; } _s_4f3a2630_calls;
typedef struct _s_4f3a2630_x { float value; } _s_4f3a2630_x;
typedef struct _s_4f3a2630_y { float value; } _s_4f3a2630_y;
typedef struct _s_4f3a2630_width { float value; } _s_4f3a2630_width;
typedef struct _s_4f3a2630_height { float value; } _s_4f3a2630_height;
typedef struct _s_4f3a2630_depthMin { float value; } _s_4f3a2630_depthMin;
typedef struct _s_4f3a2630_depthMax { float value; } _s_4f3a2630_depthMax;
static inline _s_4f3a2630_address _4f3a2630_address(RedTypeProcedureAddressCallSetDynamicViewport value) { return REDGPU_NP_STRUCT_INIT(_s_4f3a2630_address){value}; }
static inline _s_4f3a2630_calls _4f3a2630_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_4f3a2630_calls){value}; }
static inline _s_4f3a2630_x _4f3a2630_x(float value) { return REDGPU_NP_STRUCT_INIT(_s_4f3a2630_x){value}; }
static inline _s_4f3a2630_y _4f3a2630_y(float value) { return REDGPU_NP_STRUCT_INIT(_s_4f3a2630_y){value}; }
static inline _s_4f3a2630_width _4f3a2630_width(float value) { return REDGPU_NP_STRUCT_INIT(_s_4f3a2630_width){value}; }
static inline _s_4f3a2630_height _4f3a2630_height(float value) { return REDGPU_NP_STRUCT_INIT(_s_4f3a2630_height){value}; }
static inline _s_4f3a2630_depthMin _4f3a2630_depthMin(float value) { return REDGPU_NP_STRUCT_INIT(_s_4f3a2630_depthMin){value}; }
static inline _s_4f3a2630_depthMax _4f3a2630_depthMax(float value) { return REDGPU_NP_STRUCT_INIT(_s_4f3a2630_depthMax){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetDynamicViewport(_s_4f3a2630_address address, _s_4f3a2630_calls calls, _s_4f3a2630_x x, _s_4f3a2630_y y, _s_4f3a2630_width width, _s_4f3a2630_height height, _s_4f3a2630_depthMin depthMin, _s_4f3a2630_depthMax depthMax) {
  redCallSetDynamicViewport(address.value, calls.value, x.value, y.value, width.value, height.value, depthMin.value, depthMax.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetDynamicScissor redCallSetDynamicScissor
#define _e2155dcb_address(value) value
#define _e2155dcb_calls(value) value
#define _e2155dcb_x(value) value
#define _e2155dcb_y(value) value
#define _e2155dcb_width(value) value
#define _e2155dcb_height(value) value
#else
typedef struct _s_e2155dcb_address { RedTypeProcedureAddressCallSetDynamicScissor value; } _s_e2155dcb_address;
typedef struct _s_e2155dcb_calls { RedHandleCalls value; } _s_e2155dcb_calls;
typedef struct _s_e2155dcb_x { int value; } _s_e2155dcb_x;
typedef struct _s_e2155dcb_y { int value; } _s_e2155dcb_y;
typedef struct _s_e2155dcb_width { unsigned value; } _s_e2155dcb_width;
typedef struct _s_e2155dcb_height { unsigned value; } _s_e2155dcb_height;
static inline _s_e2155dcb_address _e2155dcb_address(RedTypeProcedureAddressCallSetDynamicScissor value) { return REDGPU_NP_STRUCT_INIT(_s_e2155dcb_address){value}; }
static inline _s_e2155dcb_calls _e2155dcb_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_e2155dcb_calls){value}; }
static inline _s_e2155dcb_x _e2155dcb_x(int value) { return REDGPU_NP_STRUCT_INIT(_s_e2155dcb_x){value}; }
static inline _s_e2155dcb_y _e2155dcb_y(int value) { return REDGPU_NP_STRUCT_INIT(_s_e2155dcb_y){value}; }
static inline _s_e2155dcb_width _e2155dcb_width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e2155dcb_width){value}; }
static inline _s_e2155dcb_height _e2155dcb_height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e2155dcb_height){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetDynamicScissor(_s_e2155dcb_address address, _s_e2155dcb_calls calls, _s_e2155dcb_x x, _s_e2155dcb_y y, _s_e2155dcb_width width, _s_e2155dcb_height height) {
  redCallSetDynamicScissor(address.value, calls.value, x.value, y.value, width.value, height.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetStructsMemory redCallSetStructsMemory
#define _e5f0da72_address(value) value
#define _e5f0da72_calls(value) value
#define _e5f0da72_structsMemory(value) value
#define _e5f0da72_structsMemorySamplers(value) value
#else
typedef struct _s_e5f0da72_address { RedTypeProcedureAddressCallSetStructsMemory value; } _s_e5f0da72_address;
typedef struct _s_e5f0da72_calls { RedHandleCalls value; } _s_e5f0da72_calls;
typedef struct _s_e5f0da72_structsMemory { RedHandleStructsMemory value; } _s_e5f0da72_structsMemory;
typedef struct _s_e5f0da72_structsMemorySamplers { RedHandleStructsMemory value; } _s_e5f0da72_structsMemorySamplers;
static inline _s_e5f0da72_address _e5f0da72_address(RedTypeProcedureAddressCallSetStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_e5f0da72_address){value}; }
static inline _s_e5f0da72_calls _e5f0da72_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_e5f0da72_calls){value}; }
static inline _s_e5f0da72_structsMemory _e5f0da72_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_e5f0da72_structsMemory){value}; }
static inline _s_e5f0da72_structsMemorySamplers _e5f0da72_structsMemorySamplers(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_e5f0da72_structsMemorySamplers){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetStructsMemory(_s_e5f0da72_address address, _s_e5f0da72_calls calls, _s_e5f0da72_structsMemory structsMemory, _s_e5f0da72_structsMemorySamplers structsMemorySamplers) {
  redCallSetStructsMemory(address.value, calls.value, structsMemory.value, structsMemorySamplers.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetProcedureParameters redCallSetProcedureParameters
#define _a823169a_address(value) value
#define _a823169a_calls(value) value
#define _a823169a_procedureType(value) value
#define _a823169a_procedureParameters(value) value
#else
typedef struct _s_a823169a_address { RedTypeProcedureAddressCallSetProcedureParameters value; } _s_a823169a_address;
typedef struct _s_a823169a_calls { RedHandleCalls value; } _s_a823169a_calls;
typedef struct _s_a823169a_procedureType { RedProcedureType value; } _s_a823169a_procedureType;
typedef struct _s_a823169a_procedureParameters { RedHandleProcedureParameters value; } _s_a823169a_procedureParameters;
static inline _s_a823169a_address _a823169a_address(RedTypeProcedureAddressCallSetProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_a823169a_address){value}; }
static inline _s_a823169a_calls _a823169a_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_a823169a_calls){value}; }
static inline _s_a823169a_procedureType _a823169a_procedureType(RedProcedureType value) { return REDGPU_NP_STRUCT_INIT(_s_a823169a_procedureType){value}; }
static inline _s_a823169a_procedureParameters _a823169a_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_a823169a_procedureParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetProcedureParameters(_s_a823169a_address address, _s_a823169a_calls calls, _s_a823169a_procedureType procedureType, _s_a823169a_procedureParameters procedureParameters) {
  redCallSetProcedureParameters(address.value, calls.value, procedureType.value, procedureParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetProcedureOutput redCallSetProcedureOutput
#define _be0adeb6_address(value) value
#define _be0adeb6_calls(value) value
#define _be0adeb6_outputDeclaration(value) value
#define _be0adeb6_output(value) value
#define _be0adeb6_inlineOutput(value) value
#define _be0adeb6_outputWidth(value) value
#define _be0adeb6_outputHeight(value) value
#define _be0adeb6_outputDepthStencilEnable(value) value
#define _be0adeb6_outputColorsCount(value) value
#define _be0adeb6_depthClearValue(value) value
#define _be0adeb6_stencilClearValue(value) value
#define _be0adeb6_colorsClearValuesFloat(value) value
#define _be0adeb6_colorsClearValuesSint(value) value
#define _be0adeb6_colorsClearValuesUint(value) value
#else
typedef struct _s_be0adeb6_address { RedTypeProcedureAddressCallSetProcedureOutput value; } _s_be0adeb6_address;
typedef struct _s_be0adeb6_calls { RedHandleCalls value; } _s_be0adeb6_calls;
typedef struct _s_be0adeb6_outputDeclaration { RedHandleOutputDeclaration value; } _s_be0adeb6_outputDeclaration;
typedef struct _s_be0adeb6_output { RedHandleOutput value; } _s_be0adeb6_output;
typedef struct _s_be0adeb6_inlineOutput { RedInlineOutput* value; } _s_be0adeb6_inlineOutput;
typedef struct _s_be0adeb6_outputWidth { unsigned value; } _s_be0adeb6_outputWidth;
typedef struct _s_be0adeb6_outputHeight { unsigned value; } _s_be0adeb6_outputHeight;
typedef struct _s_be0adeb6_outputDepthStencilEnable { RedBool32 value; } _s_be0adeb6_outputDepthStencilEnable;
typedef struct _s_be0adeb6_outputColorsCount { unsigned value; } _s_be0adeb6_outputColorsCount;
typedef struct _s_be0adeb6_depthClearValue { float value; } _s_be0adeb6_depthClearValue;
typedef struct _s_be0adeb6_stencilClearValue { unsigned value; } _s_be0adeb6_stencilClearValue;
typedef struct _s_be0adeb6_colorsClearValuesFloat { RedColorsClearValuesFloat* value; } _s_be0adeb6_colorsClearValuesFloat;
typedef struct _s_be0adeb6_colorsClearValuesSint { RedColorsClearValuesSint* value; } _s_be0adeb6_colorsClearValuesSint;
typedef struct _s_be0adeb6_colorsClearValuesUint { RedColorsClearValuesUint* value; } _s_be0adeb6_colorsClearValuesUint;
static inline _s_be0adeb6_address _be0adeb6_address(RedTypeProcedureAddressCallSetProcedureOutput value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_address){value}; }
static inline _s_be0adeb6_calls _be0adeb6_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_calls){value}; }
static inline _s_be0adeb6_outputDeclaration _be0adeb6_outputDeclaration(RedHandleOutputDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_outputDeclaration){value}; }
static inline _s_be0adeb6_output _be0adeb6_output(RedHandleOutput value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_output){value}; }
static inline _s_be0adeb6_inlineOutput _be0adeb6_inlineOutput(RedInlineOutput* value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_inlineOutput){value}; }
static inline _s_be0adeb6_outputWidth _be0adeb6_outputWidth(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_outputWidth){value}; }
static inline _s_be0adeb6_outputHeight _be0adeb6_outputHeight(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_outputHeight){value}; }
static inline _s_be0adeb6_outputDepthStencilEnable _be0adeb6_outputDepthStencilEnable(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_outputDepthStencilEnable){value}; }
static inline _s_be0adeb6_outputColorsCount _be0adeb6_outputColorsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_outputColorsCount){value}; }
static inline _s_be0adeb6_depthClearValue _be0adeb6_depthClearValue(float value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_depthClearValue){value}; }
static inline _s_be0adeb6_stencilClearValue _be0adeb6_stencilClearValue(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_stencilClearValue){value}; }
static inline _s_be0adeb6_colorsClearValuesFloat _be0adeb6_colorsClearValuesFloat(RedColorsClearValuesFloat* value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_colorsClearValuesFloat){value}; }
static inline _s_be0adeb6_colorsClearValuesSint _be0adeb6_colorsClearValuesSint(RedColorsClearValuesSint* value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_colorsClearValuesSint){value}; }
static inline _s_be0adeb6_colorsClearValuesUint _be0adeb6_colorsClearValuesUint(RedColorsClearValuesUint* value) { return REDGPU_NP_STRUCT_INIT(_s_be0adeb6_colorsClearValuesUint){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetProcedureOutput(_s_be0adeb6_address address, _s_be0adeb6_calls calls, _s_be0adeb6_outputDeclaration outputDeclaration, _s_be0adeb6_output output, _s_be0adeb6_inlineOutput inlineOutput, _s_be0adeb6_outputWidth outputWidth, _s_be0adeb6_outputHeight outputHeight, _s_be0adeb6_outputDepthStencilEnable outputDepthStencilEnable, _s_be0adeb6_outputColorsCount outputColorsCount, _s_be0adeb6_depthClearValue depthClearValue, _s_be0adeb6_stencilClearValue stencilClearValue, _s_be0adeb6_colorsClearValuesFloat colorsClearValuesFloat, _s_be0adeb6_colorsClearValuesSint colorsClearValuesSint, _s_be0adeb6_colorsClearValuesUint colorsClearValuesUint) {
  redCallSetProcedureOutput(address.value, calls.value, outputDeclaration.value, output.value, inlineOutput.value, outputWidth.value, outputHeight.value, outputDepthStencilEnable.value, outputColorsCount.value, depthClearValue.value, stencilClearValue.value, colorsClearValuesFloat.value, colorsClearValuesSint.value, colorsClearValuesUint.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallEndProcedureOutput redCallEndProcedureOutput
#define _0e351483_address(value) value
#define _0e351483_calls(value) value
#else
typedef struct _s_0e351483_address { RedTypeProcedureAddressCallEndProcedureOutput value; } _s_0e351483_address;
typedef struct _s_0e351483_calls { RedHandleCalls value; } _s_0e351483_calls;
static inline _s_0e351483_address _0e351483_address(RedTypeProcedureAddressCallEndProcedureOutput value) { return REDGPU_NP_STRUCT_INIT(_s_0e351483_address){value}; }
static inline _s_0e351483_calls _0e351483_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_0e351483_calls){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallEndProcedureOutput(_s_0e351483_address address, _s_0e351483_calls calls) {
  redCallEndProcedureOutput(address.value, calls.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallUsageAliasOrderBarrier redCallUsageAliasOrderBarrier
#define _94990c3d_address(value) value
#define _94990c3d_calls(value) value
#define _94990c3d_context(value) value
#define _94990c3d_arrayUsagesCount(value) value
#define _94990c3d_arrayUsages(value) value
#define _94990c3d_imageUsagesCount(value) value
#define _94990c3d_imageUsages(value) value
#define _94990c3d_aliasesCount(value) value
#define _94990c3d_aliases(value) value
#define _94990c3d_ordersCount(value) value
#define _94990c3d_orders(value) value
#define _94990c3d_dependencyByRegion(value) value
#else
typedef struct _s_94990c3d_address { RedTypeProcedureAddressCallUsageAliasOrderBarrier value; } _s_94990c3d_address;
typedef struct _s_94990c3d_calls { RedHandleCalls value; } _s_94990c3d_calls;
typedef struct _s_94990c3d_context { RedContext value; } _s_94990c3d_context;
typedef struct _s_94990c3d_arrayUsagesCount { unsigned value; } _s_94990c3d_arrayUsagesCount;
typedef struct _s_94990c3d_arrayUsages { RedUsageArray* value; } _s_94990c3d_arrayUsages;
typedef struct _s_94990c3d_imageUsagesCount { unsigned value; } _s_94990c3d_imageUsagesCount;
typedef struct _s_94990c3d_imageUsages { RedUsageImage* value; } _s_94990c3d_imageUsages;
typedef struct _s_94990c3d_aliasesCount { unsigned value; } _s_94990c3d_aliasesCount;
typedef struct _s_94990c3d_aliases { RedAlias* value; } _s_94990c3d_aliases;
typedef struct _s_94990c3d_ordersCount { unsigned value; } _s_94990c3d_ordersCount;
typedef struct _s_94990c3d_orders { RedOrder* value; } _s_94990c3d_orders;
typedef struct _s_94990c3d_dependencyByRegion { RedBool32 value; } _s_94990c3d_dependencyByRegion;
static inline _s_94990c3d_address _94990c3d_address(RedTypeProcedureAddressCallUsageAliasOrderBarrier value) { return REDGPU_NP_STRUCT_INIT(_s_94990c3d_address){value}; }
static inline _s_94990c3d_calls _94990c3d_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_94990c3d_calls){value}; }
static inline _s_94990c3d_context _94990c3d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_94990c3d_context){value}; }
static inline _s_94990c3d_arrayUsagesCount _94990c3d_arrayUsagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_94990c3d_arrayUsagesCount){value}; }
static inline _s_94990c3d_arrayUsages _94990c3d_arrayUsages(RedUsageArray* value) { return REDGPU_NP_STRUCT_INIT(_s_94990c3d_arrayUsages){value}; }
static inline _s_94990c3d_imageUsagesCount _94990c3d_imageUsagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_94990c3d_imageUsagesCount){value}; }
static inline _s_94990c3d_imageUsages _94990c3d_imageUsages(RedUsageImage* value) { return REDGPU_NP_STRUCT_INIT(_s_94990c3d_imageUsages){value}; }
static inline _s_94990c3d_aliasesCount _94990c3d_aliasesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_94990c3d_aliasesCount){value}; }
static inline _s_94990c3d_aliases _94990c3d_aliases(RedAlias* value) { return REDGPU_NP_STRUCT_INIT(_s_94990c3d_aliases){value}; }
static inline _s_94990c3d_ordersCount _94990c3d_ordersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_94990c3d_ordersCount){value}; }
static inline _s_94990c3d_orders _94990c3d_orders(RedOrder* value) { return REDGPU_NP_STRUCT_INIT(_s_94990c3d_orders){value}; }
static inline _s_94990c3d_dependencyByRegion _94990c3d_dependencyByRegion(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_94990c3d_dependencyByRegion){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallUsageAliasOrderBarrier(_s_94990c3d_address address, _s_94990c3d_calls calls, _s_94990c3d_context context, _s_94990c3d_arrayUsagesCount arrayUsagesCount, _s_94990c3d_arrayUsages arrayUsages, _s_94990c3d_imageUsagesCount imageUsagesCount, _s_94990c3d_imageUsages imageUsages, _s_94990c3d_aliasesCount aliasesCount, _s_94990c3d_aliases aliases, _s_94990c3d_ordersCount ordersCount, _s_94990c3d_orders orders, _s_94990c3d_dependencyByRegion dependencyByRegion) {
  redCallUsageAliasOrderBarrier(address.value, calls.value, context.value, arrayUsagesCount.value, arrayUsages.value, imageUsagesCount.value, imageUsages.value, aliasesCount.value, aliases.value, ordersCount.value, orders.value, dependencyByRegion.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallMark redCallMark
#define _df7c2ff8_address(value) value
#define _df7c2ff8_calls(value) value
#define _df7c2ff8_mark(value) value
#else
typedef struct _s_df7c2ff8_address { RedTypeProcedureAddressCallMark value; } _s_df7c2ff8_address;
typedef struct _s_df7c2ff8_calls { RedHandleCalls value; } _s_df7c2ff8_calls;
typedef struct _s_df7c2ff8_mark { char* value; } _s_df7c2ff8_mark;
static inline _s_df7c2ff8_address _df7c2ff8_address(RedTypeProcedureAddressCallMark value) { return REDGPU_NP_STRUCT_INIT(_s_df7c2ff8_address){value}; }
static inline _s_df7c2ff8_calls _df7c2ff8_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_df7c2ff8_calls){value}; }
static inline _s_df7c2ff8_mark _df7c2ff8_mark(char* value) { return REDGPU_NP_STRUCT_INIT(_s_df7c2ff8_mark){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallMark(_s_df7c2ff8_address address, _s_df7c2ff8_calls calls, _s_df7c2ff8_mark mark) {
  redCallMark(address.value, calls.value, mark.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallMarkSet redCallMarkSet
#define _601d2b48_address(value) value
#define _601d2b48_calls(value) value
#define _601d2b48_mark(value) value
#else
typedef struct _s_601d2b48_address { RedTypeProcedureAddressCallMarkSet value; } _s_601d2b48_address;
typedef struct _s_601d2b48_calls { RedHandleCalls value; } _s_601d2b48_calls;
typedef struct _s_601d2b48_mark { char* value; } _s_601d2b48_mark;
static inline _s_601d2b48_address _601d2b48_address(RedTypeProcedureAddressCallMarkSet value) { return REDGPU_NP_STRUCT_INIT(_s_601d2b48_address){value}; }
static inline _s_601d2b48_calls _601d2b48_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_601d2b48_calls){value}; }
static inline _s_601d2b48_mark _601d2b48_mark(char* value) { return REDGPU_NP_STRUCT_INIT(_s_601d2b48_mark){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallMarkSet(_s_601d2b48_address address, _s_601d2b48_calls calls, _s_601d2b48_mark mark) {
  redCallMarkSet(address.value, calls.value, mark.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallMarkEnd redCallMarkEnd
#define _013a0119_address(value) value
#define _013a0119_calls(value) value
#else
typedef struct _s_013a0119_address { RedTypeProcedureAddressCallMarkEnd value; } _s_013a0119_address;
typedef struct _s_013a0119_calls { RedHandleCalls value; } _s_013a0119_calls;
static inline _s_013a0119_address _013a0119_address(RedTypeProcedureAddressCallMarkEnd value) { return REDGPU_NP_STRUCT_INIT(_s_013a0119_address){value}; }
static inline _s_013a0119_calls _013a0119_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_013a0119_calls){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallMarkEnd(_s_013a0119_address address, _s_013a0119_calls calls) {
  redCallMarkEnd(address.value, calls.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redQueueSubmit redQueueSubmit
#define _dcc70647_context(value) value
#define _dcc70647_gpu(value) value
#define _dcc70647_queue(value) value
#define _dcc70647_timelinesCount(value) value
#define _dcc70647_timelines(value) value
#define _dcc70647_signalCpuSignal(value) value
#define _dcc70647_outStatuses(value) value
#define _dcc70647_optionalFile(value) value
#define _dcc70647_optionalLine(value) value
#define _dcc70647_optionalUserData(value) value
#else
typedef struct _s_dcc70647_context { RedContext value; } _s_dcc70647_context;
typedef struct _s_dcc70647_gpu { RedHandleGpu value; } _s_dcc70647_gpu;
typedef struct _s_dcc70647_queue { RedHandleQueue value; } _s_dcc70647_queue;
typedef struct _s_dcc70647_timelinesCount { unsigned value; } _s_dcc70647_timelinesCount;
typedef struct _s_dcc70647_timelines { RedGpuTimeline* value; } _s_dcc70647_timelines;
typedef struct _s_dcc70647_signalCpuSignal { RedHandleCpuSignal value; } _s_dcc70647_signalCpuSignal;
typedef struct _s_dcc70647_outStatuses { RedStatuses* value; } _s_dcc70647_outStatuses;
typedef struct _s_dcc70647_optionalFile { char* value; } _s_dcc70647_optionalFile;
typedef struct _s_dcc70647_optionalLine { int value; } _s_dcc70647_optionalLine;
typedef struct _s_dcc70647_optionalUserData { void* value; } _s_dcc70647_optionalUserData;
static inline _s_dcc70647_context _dcc70647_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_dcc70647_context){value}; }
static inline _s_dcc70647_gpu _dcc70647_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_dcc70647_gpu){value}; }
static inline _s_dcc70647_queue _dcc70647_queue(RedHandleQueue value) { return REDGPU_NP_STRUCT_INIT(_s_dcc70647_queue){value}; }
static inline _s_dcc70647_timelinesCount _dcc70647_timelinesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_dcc70647_timelinesCount){value}; }
static inline _s_dcc70647_timelines _dcc70647_timelines(RedGpuTimeline* value) { return REDGPU_NP_STRUCT_INIT(_s_dcc70647_timelines){value}; }
static inline _s_dcc70647_signalCpuSignal _dcc70647_signalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_dcc70647_signalCpuSignal){value}; }
static inline _s_dcc70647_outStatuses _dcc70647_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_dcc70647_outStatuses){value}; }
static inline _s_dcc70647_optionalFile _dcc70647_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_dcc70647_optionalFile){value}; }
static inline _s_dcc70647_optionalLine _dcc70647_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_dcc70647_optionalLine){value}; }
static inline _s_dcc70647_optionalUserData _dcc70647_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_dcc70647_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redQueueSubmit(_s_dcc70647_context context, _s_dcc70647_gpu gpu, _s_dcc70647_queue queue, _s_dcc70647_timelinesCount timelinesCount, _s_dcc70647_timelines timelines, _s_dcc70647_signalCpuSignal signalCpuSignal, _s_dcc70647_outStatuses outStatuses, _s_dcc70647_optionalFile optionalFile, _s_dcc70647_optionalLine optionalLine, _s_dcc70647_optionalUserData optionalUserData) {
  redQueueSubmit(context.value, gpu.value, queue.value, timelinesCount.value, timelines.value, signalCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMark redMark
#define _3fee9347_mark(value) value
#define _3fee9347_optionalFile(value) value
#define _3fee9347_optionalLine(value) value
#define _3fee9347_optionalUserData(value) value
#else
typedef struct _s_3fee9347_mark { char* value; } _s_3fee9347_mark;
typedef struct _s_3fee9347_optionalFile { char* value; } _s_3fee9347_optionalFile;
typedef struct _s_3fee9347_optionalLine { int value; } _s_3fee9347_optionalLine;
typedef struct _s_3fee9347_optionalUserData { void* value; } _s_3fee9347_optionalUserData;
static inline _s_3fee9347_mark _3fee9347_mark(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3fee9347_mark){value}; }
static inline _s_3fee9347_optionalFile _3fee9347_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3fee9347_optionalFile){value}; }
static inline _s_3fee9347_optionalLine _3fee9347_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3fee9347_optionalLine){value}; }
static inline _s_3fee9347_optionalUserData _3fee9347_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3fee9347_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMark(_s_3fee9347_mark mark, _s_3fee9347_optionalFile optionalFile, _s_3fee9347_optionalLine optionalLine, _s_3fee9347_optionalUserData optionalUserData) {
  redMark(mark.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMarkSet redMarkSet
#define _cffa758d_mark(value) value
#define _cffa758d_optionalFile(value) value
#define _cffa758d_optionalLine(value) value
#define _cffa758d_optionalUserData(value) value
#else
typedef struct _s_cffa758d_mark { char* value; } _s_cffa758d_mark;
typedef struct _s_cffa758d_optionalFile { char* value; } _s_cffa758d_optionalFile;
typedef struct _s_cffa758d_optionalLine { int value; } _s_cffa758d_optionalLine;
typedef struct _s_cffa758d_optionalUserData { void* value; } _s_cffa758d_optionalUserData;
static inline _s_cffa758d_mark _cffa758d_mark(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cffa758d_mark){value}; }
static inline _s_cffa758d_optionalFile _cffa758d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cffa758d_optionalFile){value}; }
static inline _s_cffa758d_optionalLine _cffa758d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cffa758d_optionalLine){value}; }
static inline _s_cffa758d_optionalUserData _cffa758d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cffa758d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMarkSet(_s_cffa758d_mark mark, _s_cffa758d_optionalFile optionalFile, _s_cffa758d_optionalLine optionalLine, _s_cffa758d_optionalUserData optionalUserData) {
  redMarkSet(mark.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMarkEnd redMarkEnd
#define _62baadd3_optionalFile(value) value
#define _62baadd3_optionalLine(value) value
#define _62baadd3_optionalUserData(value) value
#else
typedef struct _s_62baadd3_optionalFile { char* value; } _s_62baadd3_optionalFile;
typedef struct _s_62baadd3_optionalLine { int value; } _s_62baadd3_optionalLine;
typedef struct _s_62baadd3_optionalUserData { void* value; } _s_62baadd3_optionalUserData;
static inline _s_62baadd3_optionalFile _62baadd3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_62baadd3_optionalFile){value}; }
static inline _s_62baadd3_optionalLine _62baadd3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_62baadd3_optionalLine){value}; }
static inline _s_62baadd3_optionalUserData _62baadd3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_62baadd3_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMarkEnd(_s_62baadd3_optionalFile optionalFile, _s_62baadd3_optionalLine optionalLine, _s_62baadd3_optionalUserData optionalUserData) {
  redMarkEnd(optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemoryAllocateWithInlineSamplers redStructsMemoryAllocateWithInlineSamplers
#define _27d7343d_context(value) value
#define _27d7343d_gpu(value) value
#define _27d7343d_handleName(value) value
#define _27d7343d_maxStructsCount(value) value
#define _27d7343d_maxStructsMembersOfTypeArrayROConstantCount(value) value
#define _27d7343d_maxStructsMembersOfTypeArrayROOrArrayRWCount(value) value
#define _27d7343d_maxStructsMembersOfTypeTextureROCount(value) value
#define _27d7343d_maxStructsMembersOfTypeTextureRWCount(value) value
#define _27d7343d_maxStructsMembersOfTypeInlineSamplerCount(value) value
#define _27d7343d_outStructsMemory(value) value
#define _27d7343d_outStatuses(value) value
#define _27d7343d_optionalFile(value) value
#define _27d7343d_optionalLine(value) value
#define _27d7343d_optionalUserData(value) value
#else
typedef struct _s_27d7343d_context { RedContext value; } _s_27d7343d_context;
typedef struct _s_27d7343d_gpu { RedHandleGpu value; } _s_27d7343d_gpu;
typedef struct _s_27d7343d_handleName { char* value; } _s_27d7343d_handleName;
typedef struct _s_27d7343d_maxStructsCount { unsigned value; } _s_27d7343d_maxStructsCount;
typedef struct _s_27d7343d_maxStructsMembersOfTypeArrayROConstantCount { unsigned value; } _s_27d7343d_maxStructsMembersOfTypeArrayROConstantCount;
typedef struct _s_27d7343d_maxStructsMembersOfTypeArrayROOrArrayRWCount { unsigned value; } _s_27d7343d_maxStructsMembersOfTypeArrayROOrArrayRWCount;
typedef struct _s_27d7343d_maxStructsMembersOfTypeTextureROCount { unsigned value; } _s_27d7343d_maxStructsMembersOfTypeTextureROCount;
typedef struct _s_27d7343d_maxStructsMembersOfTypeTextureRWCount { unsigned value; } _s_27d7343d_maxStructsMembersOfTypeTextureRWCount;
typedef struct _s_27d7343d_maxStructsMembersOfTypeInlineSamplerCount { unsigned value; } _s_27d7343d_maxStructsMembersOfTypeInlineSamplerCount;
typedef struct _s_27d7343d_outStructsMemory { RedHandleStructsMemory* value; } _s_27d7343d_outStructsMemory;
typedef struct _s_27d7343d_outStatuses { RedStatuses* value; } _s_27d7343d_outStatuses;
typedef struct _s_27d7343d_optionalFile { char* value; } _s_27d7343d_optionalFile;
typedef struct _s_27d7343d_optionalLine { int value; } _s_27d7343d_optionalLine;
typedef struct _s_27d7343d_optionalUserData { void* value; } _s_27d7343d_optionalUserData;
static inline _s_27d7343d_context _27d7343d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_context){value}; }
static inline _s_27d7343d_gpu _27d7343d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_gpu){value}; }
static inline _s_27d7343d_handleName _27d7343d_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_handleName){value}; }
static inline _s_27d7343d_maxStructsCount _27d7343d_maxStructsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_maxStructsCount){value}; }
static inline _s_27d7343d_maxStructsMembersOfTypeArrayROConstantCount _27d7343d_maxStructsMembersOfTypeArrayROConstantCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_maxStructsMembersOfTypeArrayROConstantCount){value}; }
static inline _s_27d7343d_maxStructsMembersOfTypeArrayROOrArrayRWCount _27d7343d_maxStructsMembersOfTypeArrayROOrArrayRWCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_maxStructsMembersOfTypeArrayROOrArrayRWCount){value}; }
static inline _s_27d7343d_maxStructsMembersOfTypeTextureROCount _27d7343d_maxStructsMembersOfTypeTextureROCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_maxStructsMembersOfTypeTextureROCount){value}; }
static inline _s_27d7343d_maxStructsMembersOfTypeTextureRWCount _27d7343d_maxStructsMembersOfTypeTextureRWCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_maxStructsMembersOfTypeTextureRWCount){value}; }
static inline _s_27d7343d_maxStructsMembersOfTypeInlineSamplerCount _27d7343d_maxStructsMembersOfTypeInlineSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_maxStructsMembersOfTypeInlineSamplerCount){value}; }
static inline _s_27d7343d_outStructsMemory _27d7343d_outStructsMemory(RedHandleStructsMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_outStructsMemory){value}; }
static inline _s_27d7343d_outStatuses _27d7343d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_outStatuses){value}; }
static inline _s_27d7343d_optionalFile _27d7343d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_optionalFile){value}; }
static inline _s_27d7343d_optionalLine _27d7343d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_optionalLine){value}; }
static inline _s_27d7343d_optionalUserData _27d7343d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_27d7343d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemoryAllocateWithInlineSamplers(_s_27d7343d_context context, _s_27d7343d_gpu gpu, _s_27d7343d_handleName handleName, _s_27d7343d_maxStructsCount maxStructsCount, _s_27d7343d_maxStructsMembersOfTypeArrayROConstantCount maxStructsMembersOfTypeArrayROConstantCount, _s_27d7343d_maxStructsMembersOfTypeArrayROOrArrayRWCount maxStructsMembersOfTypeArrayROOrArrayRWCount, _s_27d7343d_maxStructsMembersOfTypeTextureROCount maxStructsMembersOfTypeTextureROCount, _s_27d7343d_maxStructsMembersOfTypeTextureRWCount maxStructsMembersOfTypeTextureRWCount, _s_27d7343d_maxStructsMembersOfTypeInlineSamplerCount maxStructsMembersOfTypeInlineSamplerCount, _s_27d7343d_outStructsMemory outStructsMemory, _s_27d7343d_outStatuses outStatuses, _s_27d7343d_optionalFile optionalFile, _s_27d7343d_optionalLine optionalLine, _s_27d7343d_optionalUserData optionalUserData) {
  redStructsMemoryAllocateWithInlineSamplers(context.value, gpu.value, handleName.value, maxStructsCount.value, maxStructsMembersOfTypeArrayROConstantCount.value, maxStructsMembersOfTypeArrayROOrArrayRWCount.value, maxStructsMembersOfTypeTextureROCount.value, maxStructsMembersOfTypeTextureRWCount.value, maxStructsMembersOfTypeInlineSamplerCount.value, outStructsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemoryAllocateSamplersWithInlineSamplers redStructsMemoryAllocateSamplersWithInlineSamplers
#define _cba9611e_context(value) value
#define _cba9611e_gpu(value) value
#define _cba9611e_handleName(value) value
#define _cba9611e_maxStructsCount(value) value
#define _cba9611e_maxStructsMembersOfTypeSamplerCount(value) value
#define _cba9611e_maxStructsMembersOfTypeInlineSamplerCount(value) value
#define _cba9611e_outStructsMemory(value) value
#define _cba9611e_outStatuses(value) value
#define _cba9611e_optionalFile(value) value
#define _cba9611e_optionalLine(value) value
#define _cba9611e_optionalUserData(value) value
#else
typedef struct _s_cba9611e_context { RedContext value; } _s_cba9611e_context;
typedef struct _s_cba9611e_gpu { RedHandleGpu value; } _s_cba9611e_gpu;
typedef struct _s_cba9611e_handleName { char* value; } _s_cba9611e_handleName;
typedef struct _s_cba9611e_maxStructsCount { unsigned value; } _s_cba9611e_maxStructsCount;
typedef struct _s_cba9611e_maxStructsMembersOfTypeSamplerCount { unsigned value; } _s_cba9611e_maxStructsMembersOfTypeSamplerCount;
typedef struct _s_cba9611e_maxStructsMembersOfTypeInlineSamplerCount { unsigned value; } _s_cba9611e_maxStructsMembersOfTypeInlineSamplerCount;
typedef struct _s_cba9611e_outStructsMemory { RedHandleStructsMemory* value; } _s_cba9611e_outStructsMemory;
typedef struct _s_cba9611e_outStatuses { RedStatuses* value; } _s_cba9611e_outStatuses;
typedef struct _s_cba9611e_optionalFile { char* value; } _s_cba9611e_optionalFile;
typedef struct _s_cba9611e_optionalLine { int value; } _s_cba9611e_optionalLine;
typedef struct _s_cba9611e_optionalUserData { void* value; } _s_cba9611e_optionalUserData;
static inline _s_cba9611e_context _cba9611e_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_cba9611e_context){value}; }
static inline _s_cba9611e_gpu _cba9611e_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_cba9611e_gpu){value}; }
static inline _s_cba9611e_handleName _cba9611e_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cba9611e_handleName){value}; }
static inline _s_cba9611e_maxStructsCount _cba9611e_maxStructsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cba9611e_maxStructsCount){value}; }
static inline _s_cba9611e_maxStructsMembersOfTypeSamplerCount _cba9611e_maxStructsMembersOfTypeSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cba9611e_maxStructsMembersOfTypeSamplerCount){value}; }
static inline _s_cba9611e_maxStructsMembersOfTypeInlineSamplerCount _cba9611e_maxStructsMembersOfTypeInlineSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cba9611e_maxStructsMembersOfTypeInlineSamplerCount){value}; }
static inline _s_cba9611e_outStructsMemory _cba9611e_outStructsMemory(RedHandleStructsMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_cba9611e_outStructsMemory){value}; }
static inline _s_cba9611e_outStatuses _cba9611e_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_cba9611e_outStatuses){value}; }
static inline _s_cba9611e_optionalFile _cba9611e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cba9611e_optionalFile){value}; }
static inline _s_cba9611e_optionalLine _cba9611e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cba9611e_optionalLine){value}; }
static inline _s_cba9611e_optionalUserData _cba9611e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cba9611e_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemoryAllocateSamplersWithInlineSamplers(_s_cba9611e_context context, _s_cba9611e_gpu gpu, _s_cba9611e_handleName handleName, _s_cba9611e_maxStructsCount maxStructsCount, _s_cba9611e_maxStructsMembersOfTypeSamplerCount maxStructsMembersOfTypeSamplerCount, _s_cba9611e_maxStructsMembersOfTypeInlineSamplerCount maxStructsMembersOfTypeInlineSamplerCount, _s_cba9611e_outStructsMemory outStructsMemory, _s_cba9611e_outStatuses outStatuses, _s_cba9611e_optionalFile optionalFile, _s_cba9611e_optionalLine optionalLine, _s_cba9611e_optionalUserData optionalUserData) {
  redStructsMemoryAllocateSamplersWithInlineSamplers(context.value, gpu.value, handleName.value, maxStructsCount.value, maxStructsMembersOfTypeSamplerCount.value, maxStructsMembersOfTypeInlineSamplerCount.value, outStructsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

