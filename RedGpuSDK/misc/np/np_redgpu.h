#pragma once

#ifndef REDGPU_NP_STRUCT_INIT
#ifdef __cplusplus
#define REDGPU_NP_STRUCT_INIT(x) x
#else
#define REDGPU_NP_STRUCT_INIT(x) (x)
#endif
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryGetBudget redMemoryGetBudget
#define _628a89a9_context(value) value
#define _628a89a9_gpu(value) value
#define _628a89a9_outMemoryBudget(value) value
#define _628a89a9_outStatuses(value) value
#define _628a89a9_optionalFile(value) value
#define _628a89a9_optionalLine(value) value
#define _628a89a9_optionalUserData(value) value
#else
typedef struct _s_628a89a9_context { RedContext value; } _s_628a89a9_context;
typedef struct _s_628a89a9_gpu { RedHandleGpu value; } _s_628a89a9_gpu;
typedef struct _s_628a89a9_outMemoryBudget { RedMemoryBudget* value; } _s_628a89a9_outMemoryBudget;
typedef struct _s_628a89a9_outStatuses { RedStatuses* value; } _s_628a89a9_outStatuses;
typedef struct _s_628a89a9_optionalFile { char* value; } _s_628a89a9_optionalFile;
typedef struct _s_628a89a9_optionalLine { int value; } _s_628a89a9_optionalLine;
typedef struct _s_628a89a9_optionalUserData { void* value; } _s_628a89a9_optionalUserData;
static inline _s_628a89a9_context _628a89a9_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_628a89a9_context){value}; }
static inline _s_628a89a9_gpu _628a89a9_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_628a89a9_gpu){value}; }
static inline _s_628a89a9_outMemoryBudget _628a89a9_outMemoryBudget(RedMemoryBudget* value) { return REDGPU_NP_STRUCT_INIT(_s_628a89a9_outMemoryBudget){value}; }
static inline _s_628a89a9_outStatuses _628a89a9_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_628a89a9_outStatuses){value}; }
static inline _s_628a89a9_optionalFile _628a89a9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_628a89a9_optionalFile){value}; }
static inline _s_628a89a9_optionalLine _628a89a9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_628a89a9_optionalLine){value}; }
static inline _s_628a89a9_optionalUserData _628a89a9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_628a89a9_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryGetBudget(_s_628a89a9_context context, _s_628a89a9_gpu gpu, _s_628a89a9_outMemoryBudget outMemoryBudget, _s_628a89a9_outStatuses outStatuses, _s_628a89a9_optionalFile optionalFile, _s_628a89a9_optionalLine optionalLine, _s_628a89a9_optionalUserData optionalUserData) {
  redMemoryGetBudget(context.value, gpu.value, outMemoryBudget.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryAllocate redMemoryAllocate
#define _b17132b0_context(value) value
#define _b17132b0_gpu(value) value
#define _b17132b0_handleName(value) value
#define _b17132b0_bytesCount(value) value
#define _b17132b0_memoryTypeIndex(value) value
#define _b17132b0_dedicateToArray(value) value
#define _b17132b0_dedicateToImage(value) value
#define _b17132b0_memoryBitflags(value) value
#define _b17132b0_outMemory(value) value
#define _b17132b0_outStatuses(value) value
#define _b17132b0_optionalFile(value) value
#define _b17132b0_optionalLine(value) value
#define _b17132b0_optionalUserData(value) value
#else
typedef struct _s_b17132b0_context { RedContext value; } _s_b17132b0_context;
typedef struct _s_b17132b0_gpu { RedHandleGpu value; } _s_b17132b0_gpu;
typedef struct _s_b17132b0_handleName { char* value; } _s_b17132b0_handleName;
typedef struct _s_b17132b0_bytesCount { uint64_t value; } _s_b17132b0_bytesCount;
typedef struct _s_b17132b0_memoryTypeIndex { unsigned value; } _s_b17132b0_memoryTypeIndex;
typedef struct _s_b17132b0_dedicateToArray { RedHandleArray value; } _s_b17132b0_dedicateToArray;
typedef struct _s_b17132b0_dedicateToImage { RedHandleImage value; } _s_b17132b0_dedicateToImage;
typedef struct _s_b17132b0_memoryBitflags { unsigned value; } _s_b17132b0_memoryBitflags;
typedef struct _s_b17132b0_outMemory { RedHandleMemory* value; } _s_b17132b0_outMemory;
typedef struct _s_b17132b0_outStatuses { RedStatuses* value; } _s_b17132b0_outStatuses;
typedef struct _s_b17132b0_optionalFile { char* value; } _s_b17132b0_optionalFile;
typedef struct _s_b17132b0_optionalLine { int value; } _s_b17132b0_optionalLine;
typedef struct _s_b17132b0_optionalUserData { void* value; } _s_b17132b0_optionalUserData;
static inline _s_b17132b0_context _b17132b0_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_context){value}; }
static inline _s_b17132b0_gpu _b17132b0_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_gpu){value}; }
static inline _s_b17132b0_handleName _b17132b0_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_handleName){value}; }
static inline _s_b17132b0_bytesCount _b17132b0_bytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_bytesCount){value}; }
static inline _s_b17132b0_memoryTypeIndex _b17132b0_memoryTypeIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_memoryTypeIndex){value}; }
static inline _s_b17132b0_dedicateToArray _b17132b0_dedicateToArray(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_dedicateToArray){value}; }
static inline _s_b17132b0_dedicateToImage _b17132b0_dedicateToImage(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_dedicateToImage){value}; }
static inline _s_b17132b0_memoryBitflags _b17132b0_memoryBitflags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_memoryBitflags){value}; }
static inline _s_b17132b0_outMemory _b17132b0_outMemory(RedHandleMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_outMemory){value}; }
static inline _s_b17132b0_outStatuses _b17132b0_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_outStatuses){value}; }
static inline _s_b17132b0_optionalFile _b17132b0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_optionalFile){value}; }
static inline _s_b17132b0_optionalLine _b17132b0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_optionalLine){value}; }
static inline _s_b17132b0_optionalUserData _b17132b0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b17132b0_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryAllocate(_s_b17132b0_context context, _s_b17132b0_gpu gpu, _s_b17132b0_handleName handleName, _s_b17132b0_bytesCount bytesCount, _s_b17132b0_memoryTypeIndex memoryTypeIndex, _s_b17132b0_dedicateToArray dedicateToArray, _s_b17132b0_dedicateToImage dedicateToImage, _s_b17132b0_memoryBitflags memoryBitflags, _s_b17132b0_outMemory outMemory, _s_b17132b0_outStatuses outStatuses, _s_b17132b0_optionalFile optionalFile, _s_b17132b0_optionalLine optionalLine, _s_b17132b0_optionalUserData optionalUserData) {
  redMemoryAllocate(context.value, gpu.value, handleName.value, bytesCount.value, memoryTypeIndex.value, dedicateToArray.value, dedicateToImage.value, memoryBitflags.value, outMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryAllocateMappable redMemoryAllocateMappable
#define _c00a86b2_context(value) value
#define _c00a86b2_gpu(value) value
#define _c00a86b2_handleName(value) value
#define _c00a86b2_dedicate(value) value
#define _c00a86b2_array(value) value
#define _c00a86b2_arrayMemoryBytesCount(value) value
#define _c00a86b2_memoryTypeIndex(value) value
#define _c00a86b2_memoryBitflags(value) value
#define _c00a86b2_outMemory(value) value
#define _c00a86b2_outStatuses(value) value
#define _c00a86b2_optionalFile(value) value
#define _c00a86b2_optionalLine(value) value
#define _c00a86b2_optionalUserData(value) value
#else
typedef struct _s_c00a86b2_context { RedContext value; } _s_c00a86b2_context;
typedef struct _s_c00a86b2_gpu { RedHandleGpu value; } _s_c00a86b2_gpu;
typedef struct _s_c00a86b2_handleName { char* value; } _s_c00a86b2_handleName;
typedef struct _s_c00a86b2_dedicate { RedBool32 value; } _s_c00a86b2_dedicate;
typedef struct _s_c00a86b2_array { RedHandleArray value; } _s_c00a86b2_array;
typedef struct _s_c00a86b2_arrayMemoryBytesCount { uint64_t value; } _s_c00a86b2_arrayMemoryBytesCount;
typedef struct _s_c00a86b2_memoryTypeIndex { unsigned value; } _s_c00a86b2_memoryTypeIndex;
typedef struct _s_c00a86b2_memoryBitflags { unsigned value; } _s_c00a86b2_memoryBitflags;
typedef struct _s_c00a86b2_outMemory { RedHandleMemory* value; } _s_c00a86b2_outMemory;
typedef struct _s_c00a86b2_outStatuses { RedStatuses* value; } _s_c00a86b2_outStatuses;
typedef struct _s_c00a86b2_optionalFile { char* value; } _s_c00a86b2_optionalFile;
typedef struct _s_c00a86b2_optionalLine { int value; } _s_c00a86b2_optionalLine;
typedef struct _s_c00a86b2_optionalUserData { void* value; } _s_c00a86b2_optionalUserData;
static inline _s_c00a86b2_context _c00a86b2_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_context){value}; }
static inline _s_c00a86b2_gpu _c00a86b2_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_gpu){value}; }
static inline _s_c00a86b2_handleName _c00a86b2_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_handleName){value}; }
static inline _s_c00a86b2_dedicate _c00a86b2_dedicate(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_dedicate){value}; }
static inline _s_c00a86b2_array _c00a86b2_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_array){value}; }
static inline _s_c00a86b2_arrayMemoryBytesCount _c00a86b2_arrayMemoryBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_arrayMemoryBytesCount){value}; }
static inline _s_c00a86b2_memoryTypeIndex _c00a86b2_memoryTypeIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_memoryTypeIndex){value}; }
static inline _s_c00a86b2_memoryBitflags _c00a86b2_memoryBitflags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_memoryBitflags){value}; }
static inline _s_c00a86b2_outMemory _c00a86b2_outMemory(RedHandleMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_outMemory){value}; }
static inline _s_c00a86b2_outStatuses _c00a86b2_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_outStatuses){value}; }
static inline _s_c00a86b2_optionalFile _c00a86b2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_optionalFile){value}; }
static inline _s_c00a86b2_optionalLine _c00a86b2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_optionalLine){value}; }
static inline _s_c00a86b2_optionalUserData _c00a86b2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c00a86b2_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryAllocateMappable(_s_c00a86b2_context context, _s_c00a86b2_gpu gpu, _s_c00a86b2_handleName handleName, _s_c00a86b2_dedicate dedicate, _s_c00a86b2_array array, _s_c00a86b2_arrayMemoryBytesCount arrayMemoryBytesCount, _s_c00a86b2_memoryTypeIndex memoryTypeIndex, _s_c00a86b2_memoryBitflags memoryBitflags, _s_c00a86b2_outMemory outMemory, _s_c00a86b2_outStatuses outStatuses, _s_c00a86b2_optionalFile optionalFile, _s_c00a86b2_optionalLine optionalLine, _s_c00a86b2_optionalUserData optionalUserData) {
  redMemoryAllocateMappable(context.value, gpu.value, handleName.value, dedicate.value, array.value, arrayMemoryBytesCount.value, memoryTypeIndex.value, memoryBitflags.value, outMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryFree redMemoryFree
#define _6e5f12c7_context(value) value
#define _6e5f12c7_gpu(value) value
#define _6e5f12c7_memory(value) value
#define _6e5f12c7_optionalFile(value) value
#define _6e5f12c7_optionalLine(value) value
#define _6e5f12c7_optionalUserData(value) value
#else
typedef struct _s_6e5f12c7_context { RedContext value; } _s_6e5f12c7_context;
typedef struct _s_6e5f12c7_gpu { RedHandleGpu value; } _s_6e5f12c7_gpu;
typedef struct _s_6e5f12c7_memory { RedHandleMemory value; } _s_6e5f12c7_memory;
typedef struct _s_6e5f12c7_optionalFile { char* value; } _s_6e5f12c7_optionalFile;
typedef struct _s_6e5f12c7_optionalLine { int value; } _s_6e5f12c7_optionalLine;
typedef struct _s_6e5f12c7_optionalUserData { void* value; } _s_6e5f12c7_optionalUserData;
static inline _s_6e5f12c7_context _6e5f12c7_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_6e5f12c7_context){value}; }
static inline _s_6e5f12c7_gpu _6e5f12c7_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_6e5f12c7_gpu){value}; }
static inline _s_6e5f12c7_memory _6e5f12c7_memory(RedHandleMemory value) { return REDGPU_NP_STRUCT_INIT(_s_6e5f12c7_memory){value}; }
static inline _s_6e5f12c7_optionalFile _6e5f12c7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6e5f12c7_optionalFile){value}; }
static inline _s_6e5f12c7_optionalLine _6e5f12c7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6e5f12c7_optionalLine){value}; }
static inline _s_6e5f12c7_optionalUserData _6e5f12c7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6e5f12c7_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryFree(_s_6e5f12c7_context context, _s_6e5f12c7_gpu gpu, _s_6e5f12c7_memory memory, _s_6e5f12c7_optionalFile optionalFile, _s_6e5f12c7_optionalLine optionalLine, _s_6e5f12c7_optionalUserData optionalUserData) {
  redMemoryFree(context.value, gpu.value, memory.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemorySet redMemorySet
#define _451ceb5a_context(value) value
#define _451ceb5a_gpu(value) value
#define _451ceb5a_memoryArraysCount(value) value
#define _451ceb5a_memoryArrays(value) value
#define _451ceb5a_memoryImagesCount(value) value
#define _451ceb5a_memoryImages(value) value
#define _451ceb5a_outStatuses(value) value
#define _451ceb5a_optionalFile(value) value
#define _451ceb5a_optionalLine(value) value
#define _451ceb5a_optionalUserData(value) value
#else
typedef struct _s_451ceb5a_context { RedContext value; } _s_451ceb5a_context;
typedef struct _s_451ceb5a_gpu { RedHandleGpu value; } _s_451ceb5a_gpu;
typedef struct _s_451ceb5a_memoryArraysCount { unsigned value; } _s_451ceb5a_memoryArraysCount;
typedef struct _s_451ceb5a_memoryArrays { RedMemoryArray* value; } _s_451ceb5a_memoryArrays;
typedef struct _s_451ceb5a_memoryImagesCount { unsigned value; } _s_451ceb5a_memoryImagesCount;
typedef struct _s_451ceb5a_memoryImages { RedMemoryImage* value; } _s_451ceb5a_memoryImages;
typedef struct _s_451ceb5a_outStatuses { RedStatuses* value; } _s_451ceb5a_outStatuses;
typedef struct _s_451ceb5a_optionalFile { char* value; } _s_451ceb5a_optionalFile;
typedef struct _s_451ceb5a_optionalLine { int value; } _s_451ceb5a_optionalLine;
typedef struct _s_451ceb5a_optionalUserData { void* value; } _s_451ceb5a_optionalUserData;
static inline _s_451ceb5a_context _451ceb5a_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_451ceb5a_context){value}; }
static inline _s_451ceb5a_gpu _451ceb5a_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_451ceb5a_gpu){value}; }
static inline _s_451ceb5a_memoryArraysCount _451ceb5a_memoryArraysCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_451ceb5a_memoryArraysCount){value}; }
static inline _s_451ceb5a_memoryArrays _451ceb5a_memoryArrays(RedMemoryArray* value) { return REDGPU_NP_STRUCT_INIT(_s_451ceb5a_memoryArrays){value}; }
static inline _s_451ceb5a_memoryImagesCount _451ceb5a_memoryImagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_451ceb5a_memoryImagesCount){value}; }
static inline _s_451ceb5a_memoryImages _451ceb5a_memoryImages(RedMemoryImage* value) { return REDGPU_NP_STRUCT_INIT(_s_451ceb5a_memoryImages){value}; }
static inline _s_451ceb5a_outStatuses _451ceb5a_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_451ceb5a_outStatuses){value}; }
static inline _s_451ceb5a_optionalFile _451ceb5a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_451ceb5a_optionalFile){value}; }
static inline _s_451ceb5a_optionalLine _451ceb5a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_451ceb5a_optionalLine){value}; }
static inline _s_451ceb5a_optionalUserData _451ceb5a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_451ceb5a_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemorySet(_s_451ceb5a_context context, _s_451ceb5a_gpu gpu, _s_451ceb5a_memoryArraysCount memoryArraysCount, _s_451ceb5a_memoryArrays memoryArrays, _s_451ceb5a_memoryImagesCount memoryImagesCount, _s_451ceb5a_memoryImages memoryImages, _s_451ceb5a_outStatuses outStatuses, _s_451ceb5a_optionalFile optionalFile, _s_451ceb5a_optionalLine optionalLine, _s_451ceb5a_optionalUserData optionalUserData) {
  redMemorySet(context.value, gpu.value, memoryArraysCount.value, memoryArrays.value, memoryImagesCount.value, memoryImages.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryMap redMemoryMap
#define _ccbff60b_context(value) value
#define _ccbff60b_gpu(value) value
#define _ccbff60b_mappableMemory(value) value
#define _ccbff60b_mappableMemoryBytesFirst(value) value
#define _ccbff60b_mappableMemoryBytesCount(value) value
#define _ccbff60b_outVolatilePointer(value) value
#define _ccbff60b_outStatuses(value) value
#define _ccbff60b_optionalFile(value) value
#define _ccbff60b_optionalLine(value) value
#define _ccbff60b_optionalUserData(value) value
#else
typedef struct _s_ccbff60b_context { RedContext value; } _s_ccbff60b_context;
typedef struct _s_ccbff60b_gpu { RedHandleGpu value; } _s_ccbff60b_gpu;
typedef struct _s_ccbff60b_mappableMemory { RedHandleMemory value; } _s_ccbff60b_mappableMemory;
typedef struct _s_ccbff60b_mappableMemoryBytesFirst { uint64_t value; } _s_ccbff60b_mappableMemoryBytesFirst;
typedef struct _s_ccbff60b_mappableMemoryBytesCount { uint64_t value; } _s_ccbff60b_mappableMemoryBytesCount;
typedef struct _s_ccbff60b_outVolatilePointer { void** value; } _s_ccbff60b_outVolatilePointer;
typedef struct _s_ccbff60b_outStatuses { RedStatuses* value; } _s_ccbff60b_outStatuses;
typedef struct _s_ccbff60b_optionalFile { char* value; } _s_ccbff60b_optionalFile;
typedef struct _s_ccbff60b_optionalLine { int value; } _s_ccbff60b_optionalLine;
typedef struct _s_ccbff60b_optionalUserData { void* value; } _s_ccbff60b_optionalUserData;
static inline _s_ccbff60b_context _ccbff60b_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_ccbff60b_context){value}; }
static inline _s_ccbff60b_gpu _ccbff60b_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_ccbff60b_gpu){value}; }
static inline _s_ccbff60b_mappableMemory _ccbff60b_mappableMemory(RedHandleMemory value) { return REDGPU_NP_STRUCT_INIT(_s_ccbff60b_mappableMemory){value}; }
static inline _s_ccbff60b_mappableMemoryBytesFirst _ccbff60b_mappableMemoryBytesFirst(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_ccbff60b_mappableMemoryBytesFirst){value}; }
static inline _s_ccbff60b_mappableMemoryBytesCount _ccbff60b_mappableMemoryBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_ccbff60b_mappableMemoryBytesCount){value}; }
static inline _s_ccbff60b_outVolatilePointer _ccbff60b_outVolatilePointer(void** value) { return REDGPU_NP_STRUCT_INIT(_s_ccbff60b_outVolatilePointer){value}; }
static inline _s_ccbff60b_outStatuses _ccbff60b_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_ccbff60b_outStatuses){value}; }
static inline _s_ccbff60b_optionalFile _ccbff60b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ccbff60b_optionalFile){value}; }
static inline _s_ccbff60b_optionalLine _ccbff60b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ccbff60b_optionalLine){value}; }
static inline _s_ccbff60b_optionalUserData _ccbff60b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ccbff60b_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryMap(_s_ccbff60b_context context, _s_ccbff60b_gpu gpu, _s_ccbff60b_mappableMemory mappableMemory, _s_ccbff60b_mappableMemoryBytesFirst mappableMemoryBytesFirst, _s_ccbff60b_mappableMemoryBytesCount mappableMemoryBytesCount, _s_ccbff60b_outVolatilePointer outVolatilePointer, _s_ccbff60b_outStatuses outStatuses, _s_ccbff60b_optionalFile optionalFile, _s_ccbff60b_optionalLine optionalLine, _s_ccbff60b_optionalUserData optionalUserData) {
  redMemoryMap(context.value, gpu.value, mappableMemory.value, mappableMemoryBytesFirst.value, mappableMemoryBytesCount.value, outVolatilePointer.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryUnmap redMemoryUnmap
#define _605f711d_context(value) value
#define _605f711d_gpu(value) value
#define _605f711d_mappableMemory(value) value
#define _605f711d_optionalFile(value) value
#define _605f711d_optionalLine(value) value
#define _605f711d_optionalUserData(value) value
#else
typedef struct _s_605f711d_context { RedContext value; } _s_605f711d_context;
typedef struct _s_605f711d_gpu { RedHandleGpu value; } _s_605f711d_gpu;
typedef struct _s_605f711d_mappableMemory { RedHandleMemory value; } _s_605f711d_mappableMemory;
typedef struct _s_605f711d_optionalFile { char* value; } _s_605f711d_optionalFile;
typedef struct _s_605f711d_optionalLine { int value; } _s_605f711d_optionalLine;
typedef struct _s_605f711d_optionalUserData { void* value; } _s_605f711d_optionalUserData;
static inline _s_605f711d_context _605f711d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_605f711d_context){value}; }
static inline _s_605f711d_gpu _605f711d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_605f711d_gpu){value}; }
static inline _s_605f711d_mappableMemory _605f711d_mappableMemory(RedHandleMemory value) { return REDGPU_NP_STRUCT_INIT(_s_605f711d_mappableMemory){value}; }
static inline _s_605f711d_optionalFile _605f711d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_605f711d_optionalFile){value}; }
static inline _s_605f711d_optionalLine _605f711d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_605f711d_optionalLine){value}; }
static inline _s_605f711d_optionalUserData _605f711d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_605f711d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryUnmap(_s_605f711d_context context, _s_605f711d_gpu gpu, _s_605f711d_mappableMemory mappableMemory, _s_605f711d_optionalFile optionalFile, _s_605f711d_optionalLine optionalLine, _s_605f711d_optionalUserData optionalUserData) {
  redMemoryUnmap(context.value, gpu.value, mappableMemory.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryNonCoherentFlush redMemoryNonCoherentFlush
#define _f6c0897c_context(value) value
#define _f6c0897c_gpu(value) value
#define _f6c0897c_mappableMemoryRangesCount(value) value
#define _f6c0897c_mappableMemoryRanges(value) value
#define _f6c0897c_outStatuses(value) value
#define _f6c0897c_optionalFile(value) value
#define _f6c0897c_optionalLine(value) value
#define _f6c0897c_optionalUserData(value) value
#else
typedef struct _s_f6c0897c_context { RedContext value; } _s_f6c0897c_context;
typedef struct _s_f6c0897c_gpu { RedHandleGpu value; } _s_f6c0897c_gpu;
typedef struct _s_f6c0897c_mappableMemoryRangesCount { unsigned value; } _s_f6c0897c_mappableMemoryRangesCount;
typedef struct _s_f6c0897c_mappableMemoryRanges { RedMappableMemoryRange* value; } _s_f6c0897c_mappableMemoryRanges;
typedef struct _s_f6c0897c_outStatuses { RedStatuses* value; } _s_f6c0897c_outStatuses;
typedef struct _s_f6c0897c_optionalFile { char* value; } _s_f6c0897c_optionalFile;
typedef struct _s_f6c0897c_optionalLine { int value; } _s_f6c0897c_optionalLine;
typedef struct _s_f6c0897c_optionalUserData { void* value; } _s_f6c0897c_optionalUserData;
static inline _s_f6c0897c_context _f6c0897c_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_f6c0897c_context){value}; }
static inline _s_f6c0897c_gpu _f6c0897c_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_f6c0897c_gpu){value}; }
static inline _s_f6c0897c_mappableMemoryRangesCount _f6c0897c_mappableMemoryRangesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f6c0897c_mappableMemoryRangesCount){value}; }
static inline _s_f6c0897c_mappableMemoryRanges _f6c0897c_mappableMemoryRanges(RedMappableMemoryRange* value) { return REDGPU_NP_STRUCT_INIT(_s_f6c0897c_mappableMemoryRanges){value}; }
static inline _s_f6c0897c_outStatuses _f6c0897c_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_f6c0897c_outStatuses){value}; }
static inline _s_f6c0897c_optionalFile _f6c0897c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f6c0897c_optionalFile){value}; }
static inline _s_f6c0897c_optionalLine _f6c0897c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f6c0897c_optionalLine){value}; }
static inline _s_f6c0897c_optionalUserData _f6c0897c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f6c0897c_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryNonCoherentFlush(_s_f6c0897c_context context, _s_f6c0897c_gpu gpu, _s_f6c0897c_mappableMemoryRangesCount mappableMemoryRangesCount, _s_f6c0897c_mappableMemoryRanges mappableMemoryRanges, _s_f6c0897c_outStatuses outStatuses, _s_f6c0897c_optionalFile optionalFile, _s_f6c0897c_optionalLine optionalLine, _s_f6c0897c_optionalUserData optionalUserData) {
  redMemoryNonCoherentFlush(context.value, gpu.value, mappableMemoryRangesCount.value, mappableMemoryRanges.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMemoryNonCoherentInvalidate redMemoryNonCoherentInvalidate
#define _e89c3e6f_context(value) value
#define _e89c3e6f_gpu(value) value
#define _e89c3e6f_mappableMemoryRangesCount(value) value
#define _e89c3e6f_mappableMemoryRanges(value) value
#define _e89c3e6f_outStatuses(value) value
#define _e89c3e6f_optionalFile(value) value
#define _e89c3e6f_optionalLine(value) value
#define _e89c3e6f_optionalUserData(value) value
#else
typedef struct _s_e89c3e6f_context { RedContext value; } _s_e89c3e6f_context;
typedef struct _s_e89c3e6f_gpu { RedHandleGpu value; } _s_e89c3e6f_gpu;
typedef struct _s_e89c3e6f_mappableMemoryRangesCount { unsigned value; } _s_e89c3e6f_mappableMemoryRangesCount;
typedef struct _s_e89c3e6f_mappableMemoryRanges { RedMappableMemoryRange* value; } _s_e89c3e6f_mappableMemoryRanges;
typedef struct _s_e89c3e6f_outStatuses { RedStatuses* value; } _s_e89c3e6f_outStatuses;
typedef struct _s_e89c3e6f_optionalFile { char* value; } _s_e89c3e6f_optionalFile;
typedef struct _s_e89c3e6f_optionalLine { int value; } _s_e89c3e6f_optionalLine;
typedef struct _s_e89c3e6f_optionalUserData { void* value; } _s_e89c3e6f_optionalUserData;
static inline _s_e89c3e6f_context _e89c3e6f_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_e89c3e6f_context){value}; }
static inline _s_e89c3e6f_gpu _e89c3e6f_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_e89c3e6f_gpu){value}; }
static inline _s_e89c3e6f_mappableMemoryRangesCount _e89c3e6f_mappableMemoryRangesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e89c3e6f_mappableMemoryRangesCount){value}; }
static inline _s_e89c3e6f_mappableMemoryRanges _e89c3e6f_mappableMemoryRanges(RedMappableMemoryRange* value) { return REDGPU_NP_STRUCT_INIT(_s_e89c3e6f_mappableMemoryRanges){value}; }
static inline _s_e89c3e6f_outStatuses _e89c3e6f_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_e89c3e6f_outStatuses){value}; }
static inline _s_e89c3e6f_optionalFile _e89c3e6f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e89c3e6f_optionalFile){value}; }
static inline _s_e89c3e6f_optionalLine _e89c3e6f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e89c3e6f_optionalLine){value}; }
static inline _s_e89c3e6f_optionalUserData _e89c3e6f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e89c3e6f_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMemoryNonCoherentInvalidate(_s_e89c3e6f_context context, _s_e89c3e6f_gpu gpu, _s_e89c3e6f_mappableMemoryRangesCount mappableMemoryRangesCount, _s_e89c3e6f_mappableMemoryRanges mappableMemoryRanges, _s_e89c3e6f_outStatuses outStatuses, _s_e89c3e6f_optionalFile optionalFile, _s_e89c3e6f_optionalLine optionalLine, _s_e89c3e6f_optionalUserData optionalUserData) {
  redMemoryNonCoherentInvalidate(context.value, gpu.value, mappableMemoryRangesCount.value, mappableMemoryRanges.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemoryAllocate redStructsMemoryAllocate
#define _b1ea8e5e_context(value) value
#define _b1ea8e5e_gpu(value) value
#define _b1ea8e5e_handleName(value) value
#define _b1ea8e5e_maxStructsCount(value) value
#define _b1ea8e5e_maxStructsMembersOfTypeArrayROConstantCount(value) value
#define _b1ea8e5e_maxStructsMembersOfTypeArrayROOrArrayRWCount(value) value
#define _b1ea8e5e_maxStructsMembersOfTypeTextureROCount(value) value
#define _b1ea8e5e_maxStructsMembersOfTypeTextureRWCount(value) value
#define _b1ea8e5e_outStructsMemory(value) value
#define _b1ea8e5e_outStatuses(value) value
#define _b1ea8e5e_optionalFile(value) value
#define _b1ea8e5e_optionalLine(value) value
#define _b1ea8e5e_optionalUserData(value) value
#else
typedef struct _s_b1ea8e5e_context { RedContext value; } _s_b1ea8e5e_context;
typedef struct _s_b1ea8e5e_gpu { RedHandleGpu value; } _s_b1ea8e5e_gpu;
typedef struct _s_b1ea8e5e_handleName { char* value; } _s_b1ea8e5e_handleName;
typedef struct _s_b1ea8e5e_maxStructsCount { unsigned value; } _s_b1ea8e5e_maxStructsCount;
typedef struct _s_b1ea8e5e_maxStructsMembersOfTypeArrayROConstantCount { unsigned value; } _s_b1ea8e5e_maxStructsMembersOfTypeArrayROConstantCount;
typedef struct _s_b1ea8e5e_maxStructsMembersOfTypeArrayROOrArrayRWCount { unsigned value; } _s_b1ea8e5e_maxStructsMembersOfTypeArrayROOrArrayRWCount;
typedef struct _s_b1ea8e5e_maxStructsMembersOfTypeTextureROCount { unsigned value; } _s_b1ea8e5e_maxStructsMembersOfTypeTextureROCount;
typedef struct _s_b1ea8e5e_maxStructsMembersOfTypeTextureRWCount { unsigned value; } _s_b1ea8e5e_maxStructsMembersOfTypeTextureRWCount;
typedef struct _s_b1ea8e5e_outStructsMemory { RedHandleStructsMemory* value; } _s_b1ea8e5e_outStructsMemory;
typedef struct _s_b1ea8e5e_outStatuses { RedStatuses* value; } _s_b1ea8e5e_outStatuses;
typedef struct _s_b1ea8e5e_optionalFile { char* value; } _s_b1ea8e5e_optionalFile;
typedef struct _s_b1ea8e5e_optionalLine { int value; } _s_b1ea8e5e_optionalLine;
typedef struct _s_b1ea8e5e_optionalUserData { void* value; } _s_b1ea8e5e_optionalUserData;
static inline _s_b1ea8e5e_context _b1ea8e5e_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_context){value}; }
static inline _s_b1ea8e5e_gpu _b1ea8e5e_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_gpu){value}; }
static inline _s_b1ea8e5e_handleName _b1ea8e5e_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_handleName){value}; }
static inline _s_b1ea8e5e_maxStructsCount _b1ea8e5e_maxStructsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_maxStructsCount){value}; }
static inline _s_b1ea8e5e_maxStructsMembersOfTypeArrayROConstantCount _b1ea8e5e_maxStructsMembersOfTypeArrayROConstantCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_maxStructsMembersOfTypeArrayROConstantCount){value}; }
static inline _s_b1ea8e5e_maxStructsMembersOfTypeArrayROOrArrayRWCount _b1ea8e5e_maxStructsMembersOfTypeArrayROOrArrayRWCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_maxStructsMembersOfTypeArrayROOrArrayRWCount){value}; }
static inline _s_b1ea8e5e_maxStructsMembersOfTypeTextureROCount _b1ea8e5e_maxStructsMembersOfTypeTextureROCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_maxStructsMembersOfTypeTextureROCount){value}; }
static inline _s_b1ea8e5e_maxStructsMembersOfTypeTextureRWCount _b1ea8e5e_maxStructsMembersOfTypeTextureRWCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_maxStructsMembersOfTypeTextureRWCount){value}; }
static inline _s_b1ea8e5e_outStructsMemory _b1ea8e5e_outStructsMemory(RedHandleStructsMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_outStructsMemory){value}; }
static inline _s_b1ea8e5e_outStatuses _b1ea8e5e_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_outStatuses){value}; }
static inline _s_b1ea8e5e_optionalFile _b1ea8e5e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_optionalFile){value}; }
static inline _s_b1ea8e5e_optionalLine _b1ea8e5e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_optionalLine){value}; }
static inline _s_b1ea8e5e_optionalUserData _b1ea8e5e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b1ea8e5e_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemoryAllocate(_s_b1ea8e5e_context context, _s_b1ea8e5e_gpu gpu, _s_b1ea8e5e_handleName handleName, _s_b1ea8e5e_maxStructsCount maxStructsCount, _s_b1ea8e5e_maxStructsMembersOfTypeArrayROConstantCount maxStructsMembersOfTypeArrayROConstantCount, _s_b1ea8e5e_maxStructsMembersOfTypeArrayROOrArrayRWCount maxStructsMembersOfTypeArrayROOrArrayRWCount, _s_b1ea8e5e_maxStructsMembersOfTypeTextureROCount maxStructsMembersOfTypeTextureROCount, _s_b1ea8e5e_maxStructsMembersOfTypeTextureRWCount maxStructsMembersOfTypeTextureRWCount, _s_b1ea8e5e_outStructsMemory outStructsMemory, _s_b1ea8e5e_outStatuses outStatuses, _s_b1ea8e5e_optionalFile optionalFile, _s_b1ea8e5e_optionalLine optionalLine, _s_b1ea8e5e_optionalUserData optionalUserData) {
  redStructsMemoryAllocate(context.value, gpu.value, handleName.value, maxStructsCount.value, maxStructsMembersOfTypeArrayROConstantCount.value, maxStructsMembersOfTypeArrayROOrArrayRWCount.value, maxStructsMembersOfTypeTextureROCount.value, maxStructsMembersOfTypeTextureRWCount.value, outStructsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemoryAllocateSamplers redStructsMemoryAllocateSamplers
#define _fbd6ce3b_context(value) value
#define _fbd6ce3b_gpu(value) value
#define _fbd6ce3b_handleName(value) value
#define _fbd6ce3b_maxStructsCount(value) value
#define _fbd6ce3b_maxStructsMembersOfTypeSamplerCount(value) value
#define _fbd6ce3b_outStructsMemory(value) value
#define _fbd6ce3b_outStatuses(value) value
#define _fbd6ce3b_optionalFile(value) value
#define _fbd6ce3b_optionalLine(value) value
#define _fbd6ce3b_optionalUserData(value) value
#else
typedef struct _s_fbd6ce3b_context { RedContext value; } _s_fbd6ce3b_context;
typedef struct _s_fbd6ce3b_gpu { RedHandleGpu value; } _s_fbd6ce3b_gpu;
typedef struct _s_fbd6ce3b_handleName { char* value; } _s_fbd6ce3b_handleName;
typedef struct _s_fbd6ce3b_maxStructsCount { unsigned value; } _s_fbd6ce3b_maxStructsCount;
typedef struct _s_fbd6ce3b_maxStructsMembersOfTypeSamplerCount { unsigned value; } _s_fbd6ce3b_maxStructsMembersOfTypeSamplerCount;
typedef struct _s_fbd6ce3b_outStructsMemory { RedHandleStructsMemory* value; } _s_fbd6ce3b_outStructsMemory;
typedef struct _s_fbd6ce3b_outStatuses { RedStatuses* value; } _s_fbd6ce3b_outStatuses;
typedef struct _s_fbd6ce3b_optionalFile { char* value; } _s_fbd6ce3b_optionalFile;
typedef struct _s_fbd6ce3b_optionalLine { int value; } _s_fbd6ce3b_optionalLine;
typedef struct _s_fbd6ce3b_optionalUserData { void* value; } _s_fbd6ce3b_optionalUserData;
static inline _s_fbd6ce3b_context _fbd6ce3b_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_fbd6ce3b_context){value}; }
static inline _s_fbd6ce3b_gpu _fbd6ce3b_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_fbd6ce3b_gpu){value}; }
static inline _s_fbd6ce3b_handleName _fbd6ce3b_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fbd6ce3b_handleName){value}; }
static inline _s_fbd6ce3b_maxStructsCount _fbd6ce3b_maxStructsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_fbd6ce3b_maxStructsCount){value}; }
static inline _s_fbd6ce3b_maxStructsMembersOfTypeSamplerCount _fbd6ce3b_maxStructsMembersOfTypeSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_fbd6ce3b_maxStructsMembersOfTypeSamplerCount){value}; }
static inline _s_fbd6ce3b_outStructsMemory _fbd6ce3b_outStructsMemory(RedHandleStructsMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_fbd6ce3b_outStructsMemory){value}; }
static inline _s_fbd6ce3b_outStatuses _fbd6ce3b_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_fbd6ce3b_outStatuses){value}; }
static inline _s_fbd6ce3b_optionalFile _fbd6ce3b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fbd6ce3b_optionalFile){value}; }
static inline _s_fbd6ce3b_optionalLine _fbd6ce3b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fbd6ce3b_optionalLine){value}; }
static inline _s_fbd6ce3b_optionalUserData _fbd6ce3b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fbd6ce3b_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemoryAllocateSamplers(_s_fbd6ce3b_context context, _s_fbd6ce3b_gpu gpu, _s_fbd6ce3b_handleName handleName, _s_fbd6ce3b_maxStructsCount maxStructsCount, _s_fbd6ce3b_maxStructsMembersOfTypeSamplerCount maxStructsMembersOfTypeSamplerCount, _s_fbd6ce3b_outStructsMemory outStructsMemory, _s_fbd6ce3b_outStatuses outStatuses, _s_fbd6ce3b_optionalFile optionalFile, _s_fbd6ce3b_optionalLine optionalLine, _s_fbd6ce3b_optionalUserData optionalUserData) {
  redStructsMemoryAllocateSamplers(context.value, gpu.value, handleName.value, maxStructsCount.value, maxStructsMembersOfTypeSamplerCount.value, outStructsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemorySuballocateStructs redStructsMemorySuballocateStructs
#define _50bd92a7_context(value) value
#define _50bd92a7_gpu(value) value
#define _50bd92a7_handleNames(value) value
#define _50bd92a7_structsMemory(value) value
#define _50bd92a7_structsDeclarationsCount(value) value
#define _50bd92a7_structsDeclarations(value) value
#define _50bd92a7_outStructs(value) value
#define _50bd92a7_outStatuses(value) value
#define _50bd92a7_optionalFile(value) value
#define _50bd92a7_optionalLine(value) value
#define _50bd92a7_optionalUserData(value) value
#else
typedef struct _s_50bd92a7_context { RedContext value; } _s_50bd92a7_context;
typedef struct _s_50bd92a7_gpu { RedHandleGpu value; } _s_50bd92a7_gpu;
typedef struct _s_50bd92a7_handleNames { const char** value; } _s_50bd92a7_handleNames;
typedef struct _s_50bd92a7_structsMemory { RedHandleStructsMemory value; } _s_50bd92a7_structsMemory;
typedef struct _s_50bd92a7_structsDeclarationsCount { unsigned value; } _s_50bd92a7_structsDeclarationsCount;
typedef struct _s_50bd92a7_structsDeclarations { RedHandleStructDeclaration* value; } _s_50bd92a7_structsDeclarations;
typedef struct _s_50bd92a7_outStructs { RedHandleStruct* value; } _s_50bd92a7_outStructs;
typedef struct _s_50bd92a7_outStatuses { RedStatuses* value; } _s_50bd92a7_outStatuses;
typedef struct _s_50bd92a7_optionalFile { char* value; } _s_50bd92a7_optionalFile;
typedef struct _s_50bd92a7_optionalLine { int value; } _s_50bd92a7_optionalLine;
typedef struct _s_50bd92a7_optionalUserData { void* value; } _s_50bd92a7_optionalUserData;
static inline _s_50bd92a7_context _50bd92a7_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_50bd92a7_context){value}; }
static inline _s_50bd92a7_gpu _50bd92a7_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_50bd92a7_gpu){value}; }
static inline _s_50bd92a7_handleNames _50bd92a7_handleNames(const char** value) { return REDGPU_NP_STRUCT_INIT(_s_50bd92a7_handleNames){value}; }
static inline _s_50bd92a7_structsMemory _50bd92a7_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_50bd92a7_structsMemory){value}; }
static inline _s_50bd92a7_structsDeclarationsCount _50bd92a7_structsDeclarationsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_50bd92a7_structsDeclarationsCount){value}; }
static inline _s_50bd92a7_structsDeclarations _50bd92a7_structsDeclarations(RedHandleStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_50bd92a7_structsDeclarations){value}; }
static inline _s_50bd92a7_outStructs _50bd92a7_outStructs(RedHandleStruct* value) { return REDGPU_NP_STRUCT_INIT(_s_50bd92a7_outStructs){value}; }
static inline _s_50bd92a7_outStatuses _50bd92a7_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_50bd92a7_outStatuses){value}; }
static inline _s_50bd92a7_optionalFile _50bd92a7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_50bd92a7_optionalFile){value}; }
static inline _s_50bd92a7_optionalLine _50bd92a7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_50bd92a7_optionalLine){value}; }
static inline _s_50bd92a7_optionalUserData _50bd92a7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_50bd92a7_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemorySuballocateStructs(_s_50bd92a7_context context, _s_50bd92a7_gpu gpu, _s_50bd92a7_handleNames handleNames, _s_50bd92a7_structsMemory structsMemory, _s_50bd92a7_structsDeclarationsCount structsDeclarationsCount, _s_50bd92a7_structsDeclarations structsDeclarations, _s_50bd92a7_outStructs outStructs, _s_50bd92a7_outStatuses outStatuses, _s_50bd92a7_optionalFile optionalFile, _s_50bd92a7_optionalLine optionalLine, _s_50bd92a7_optionalUserData optionalUserData) {
  redStructsMemorySuballocateStructs(context.value, gpu.value, handleNames.value, structsMemory.value, structsDeclarationsCount.value, structsDeclarations.value, outStructs.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemoryReset redStructsMemoryReset
#define _a33d1acc_context(value) value
#define _a33d1acc_gpu(value) value
#define _a33d1acc_structsMemory(value) value
#define _a33d1acc_outStatuses(value) value
#define _a33d1acc_optionalFile(value) value
#define _a33d1acc_optionalLine(value) value
#define _a33d1acc_optionalUserData(value) value
#else
typedef struct _s_a33d1acc_context { RedContext value; } _s_a33d1acc_context;
typedef struct _s_a33d1acc_gpu { RedHandleGpu value; } _s_a33d1acc_gpu;
typedef struct _s_a33d1acc_structsMemory { RedHandleStructsMemory value; } _s_a33d1acc_structsMemory;
typedef struct _s_a33d1acc_outStatuses { RedStatuses* value; } _s_a33d1acc_outStatuses;
typedef struct _s_a33d1acc_optionalFile { char* value; } _s_a33d1acc_optionalFile;
typedef struct _s_a33d1acc_optionalLine { int value; } _s_a33d1acc_optionalLine;
typedef struct _s_a33d1acc_optionalUserData { void* value; } _s_a33d1acc_optionalUserData;
static inline _s_a33d1acc_context _a33d1acc_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_a33d1acc_context){value}; }
static inline _s_a33d1acc_gpu _a33d1acc_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_a33d1acc_gpu){value}; }
static inline _s_a33d1acc_structsMemory _a33d1acc_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_a33d1acc_structsMemory){value}; }
static inline _s_a33d1acc_outStatuses _a33d1acc_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_a33d1acc_outStatuses){value}; }
static inline _s_a33d1acc_optionalFile _a33d1acc_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a33d1acc_optionalFile){value}; }
static inline _s_a33d1acc_optionalLine _a33d1acc_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a33d1acc_optionalLine){value}; }
static inline _s_a33d1acc_optionalUserData _a33d1acc_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a33d1acc_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemoryReset(_s_a33d1acc_context context, _s_a33d1acc_gpu gpu, _s_a33d1acc_structsMemory structsMemory, _s_a33d1acc_outStatuses outStatuses, _s_a33d1acc_optionalFile optionalFile, _s_a33d1acc_optionalLine optionalLine, _s_a33d1acc_optionalUserData optionalUserData) {
  redStructsMemoryReset(context.value, gpu.value, structsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemoryFree redStructsMemoryFree
#define _ba639c28_context(value) value
#define _ba639c28_gpu(value) value
#define _ba639c28_structsMemory(value) value
#define _ba639c28_optionalFile(value) value
#define _ba639c28_optionalLine(value) value
#define _ba639c28_optionalUserData(value) value
#else
typedef struct _s_ba639c28_context { RedContext value; } _s_ba639c28_context;
typedef struct _s_ba639c28_gpu { RedHandleGpu value; } _s_ba639c28_gpu;
typedef struct _s_ba639c28_structsMemory { RedHandleStructsMemory value; } _s_ba639c28_structsMemory;
typedef struct _s_ba639c28_optionalFile { char* value; } _s_ba639c28_optionalFile;
typedef struct _s_ba639c28_optionalLine { int value; } _s_ba639c28_optionalLine;
typedef struct _s_ba639c28_optionalUserData { void* value; } _s_ba639c28_optionalUserData;
static inline _s_ba639c28_context _ba639c28_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_ba639c28_context){value}; }
static inline _s_ba639c28_gpu _ba639c28_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_ba639c28_gpu){value}; }
static inline _s_ba639c28_structsMemory _ba639c28_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_ba639c28_structsMemory){value}; }
static inline _s_ba639c28_optionalFile _ba639c28_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ba639c28_optionalFile){value}; }
static inline _s_ba639c28_optionalLine _ba639c28_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ba639c28_optionalLine){value}; }
static inline _s_ba639c28_optionalUserData _ba639c28_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ba639c28_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemoryFree(_s_ba639c28_context context, _s_ba639c28_gpu gpu, _s_ba639c28_structsMemory structsMemory, _s_ba639c28_optionalFile optionalFile, _s_ba639c28_optionalLine optionalLine, _s_ba639c28_optionalUserData optionalUserData) {
  redStructsMemoryFree(context.value, gpu.value, structsMemory.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsSet redStructsSet
#define _7fe3e1e3_context(value) value
#define _7fe3e1e3_gpu(value) value
#define _7fe3e1e3_structsMembersCount(value) value
#define _7fe3e1e3_structsMembers(value) value
#define _7fe3e1e3_optionalFile(value) value
#define _7fe3e1e3_optionalLine(value) value
#define _7fe3e1e3_optionalUserData(value) value
#else
typedef struct _s_7fe3e1e3_context { RedContext value; } _s_7fe3e1e3_context;
typedef struct _s_7fe3e1e3_gpu { RedHandleGpu value; } _s_7fe3e1e3_gpu;
typedef struct _s_7fe3e1e3_structsMembersCount { unsigned value; } _s_7fe3e1e3_structsMembersCount;
typedef struct _s_7fe3e1e3_structsMembers { RedStructMember* value; } _s_7fe3e1e3_structsMembers;
typedef struct _s_7fe3e1e3_optionalFile { char* value; } _s_7fe3e1e3_optionalFile;
typedef struct _s_7fe3e1e3_optionalLine { int value; } _s_7fe3e1e3_optionalLine;
typedef struct _s_7fe3e1e3_optionalUserData { void* value; } _s_7fe3e1e3_optionalUserData;
static inline _s_7fe3e1e3_context _7fe3e1e3_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_7fe3e1e3_context){value}; }
static inline _s_7fe3e1e3_gpu _7fe3e1e3_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_7fe3e1e3_gpu){value}; }
static inline _s_7fe3e1e3_structsMembersCount _7fe3e1e3_structsMembersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_7fe3e1e3_structsMembersCount){value}; }
static inline _s_7fe3e1e3_structsMembers _7fe3e1e3_structsMembers(RedStructMember* value) { return REDGPU_NP_STRUCT_INIT(_s_7fe3e1e3_structsMembers){value}; }
static inline _s_7fe3e1e3_optionalFile _7fe3e1e3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7fe3e1e3_optionalFile){value}; }
static inline _s_7fe3e1e3_optionalLine _7fe3e1e3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7fe3e1e3_optionalLine){value}; }
static inline _s_7fe3e1e3_optionalUserData _7fe3e1e3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7fe3e1e3_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsSet(_s_7fe3e1e3_context context, _s_7fe3e1e3_gpu gpu, _s_7fe3e1e3_structsMembersCount structsMembersCount, _s_7fe3e1e3_structsMembers structsMembers, _s_7fe3e1e3_optionalFile optionalFile, _s_7fe3e1e3_optionalLine optionalLine, _s_7fe3e1e3_optionalUserData optionalUserData) {
  redStructsSet(context.value, gpu.value, structsMembersCount.value, structsMembers.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateContext redCreateContext
#define _190aba15_malloc(value) value
#define _190aba15_free(value) value
#define _190aba15_optionalMallocTagged(value) value
#define _190aba15_optionalFreeTagged(value) value
#define _190aba15_debugCallback(value) value
#define _190aba15_sdkVersion(value) value
#define _190aba15_sdkExtensionsCount(value) value
#define _190aba15_sdkExtensions(value) value
#define _190aba15_optionalProgramName(value) value
#define _190aba15_optionalProgramVersion(value) value
#define _190aba15_optionalEngineName(value) value
#define _190aba15_optionalEngineVersion(value) value
#define _190aba15_optionalSettings(value) value
#define _190aba15_outContext(value) value
#define _190aba15_outStatuses(value) value
#define _190aba15_optionalFile(value) value
#define _190aba15_optionalLine(value) value
#define _190aba15_optionalUserData(value) value
#else
typedef struct _s_190aba15_malloc { RedTypeProcedureMalloc value; } _s_190aba15_malloc;
typedef struct _s_190aba15_free { RedTypeProcedureFree value; } _s_190aba15_free;
typedef struct _s_190aba15_optionalMallocTagged { RedTypeProcedureMallocTagged value; } _s_190aba15_optionalMallocTagged;
typedef struct _s_190aba15_optionalFreeTagged { RedTypeProcedureFreeTagged value; } _s_190aba15_optionalFreeTagged;
typedef struct _s_190aba15_debugCallback { RedTypeProcedureDebugCallback value; } _s_190aba15_debugCallback;
typedef struct _s_190aba15_sdkVersion { RedSdkVersion value; } _s_190aba15_sdkVersion;
typedef struct _s_190aba15_sdkExtensionsCount { unsigned value; } _s_190aba15_sdkExtensionsCount;
typedef struct _s_190aba15_sdkExtensions { unsigned* value; } _s_190aba15_sdkExtensions;
typedef struct _s_190aba15_optionalProgramName { char* value; } _s_190aba15_optionalProgramName;
typedef struct _s_190aba15_optionalProgramVersion { unsigned value; } _s_190aba15_optionalProgramVersion;
typedef struct _s_190aba15_optionalEngineName { char* value; } _s_190aba15_optionalEngineName;
typedef struct _s_190aba15_optionalEngineVersion { unsigned value; } _s_190aba15_optionalEngineVersion;
typedef struct _s_190aba15_optionalSettings { void* value; } _s_190aba15_optionalSettings;
typedef struct _s_190aba15_outContext { RedContext* value; } _s_190aba15_outContext;
typedef struct _s_190aba15_outStatuses { RedStatuses* value; } _s_190aba15_outStatuses;
typedef struct _s_190aba15_optionalFile { char* value; } _s_190aba15_optionalFile;
typedef struct _s_190aba15_optionalLine { int value; } _s_190aba15_optionalLine;
typedef struct _s_190aba15_optionalUserData { void* value; } _s_190aba15_optionalUserData;
static inline _s_190aba15_malloc _190aba15_malloc(RedTypeProcedureMalloc value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_malloc){value}; }
static inline _s_190aba15_free _190aba15_free(RedTypeProcedureFree value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_free){value}; }
static inline _s_190aba15_optionalMallocTagged _190aba15_optionalMallocTagged(RedTypeProcedureMallocTagged value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_optionalMallocTagged){value}; }
static inline _s_190aba15_optionalFreeTagged _190aba15_optionalFreeTagged(RedTypeProcedureFreeTagged value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_optionalFreeTagged){value}; }
static inline _s_190aba15_debugCallback _190aba15_debugCallback(RedTypeProcedureDebugCallback value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_debugCallback){value}; }
static inline _s_190aba15_sdkVersion _190aba15_sdkVersion(RedSdkVersion value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_sdkVersion){value}; }
static inline _s_190aba15_sdkExtensionsCount _190aba15_sdkExtensionsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_sdkExtensionsCount){value}; }
static inline _s_190aba15_sdkExtensions _190aba15_sdkExtensions(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_sdkExtensions){value}; }
static inline _s_190aba15_optionalProgramName _190aba15_optionalProgramName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_optionalProgramName){value}; }
static inline _s_190aba15_optionalProgramVersion _190aba15_optionalProgramVersion(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_optionalProgramVersion){value}; }
static inline _s_190aba15_optionalEngineName _190aba15_optionalEngineName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_optionalEngineName){value}; }
static inline _s_190aba15_optionalEngineVersion _190aba15_optionalEngineVersion(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_optionalEngineVersion){value}; }
static inline _s_190aba15_optionalSettings _190aba15_optionalSettings(void* value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_optionalSettings){value}; }
static inline _s_190aba15_outContext _190aba15_outContext(RedContext* value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_outContext){value}; }
static inline _s_190aba15_outStatuses _190aba15_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_outStatuses){value}; }
static inline _s_190aba15_optionalFile _190aba15_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_optionalFile){value}; }
static inline _s_190aba15_optionalLine _190aba15_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_optionalLine){value}; }
static inline _s_190aba15_optionalUserData _190aba15_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_190aba15_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateContext(_s_190aba15_malloc malloc, _s_190aba15_free free, _s_190aba15_optionalMallocTagged optionalMallocTagged, _s_190aba15_optionalFreeTagged optionalFreeTagged, _s_190aba15_debugCallback debugCallback, _s_190aba15_sdkVersion sdkVersion, _s_190aba15_sdkExtensionsCount sdkExtensionsCount, _s_190aba15_sdkExtensions sdkExtensions, _s_190aba15_optionalProgramName optionalProgramName, _s_190aba15_optionalProgramVersion optionalProgramVersion, _s_190aba15_optionalEngineName optionalEngineName, _s_190aba15_optionalEngineVersion optionalEngineVersion, _s_190aba15_optionalSettings optionalSettings, _s_190aba15_outContext outContext, _s_190aba15_outStatuses outStatuses, _s_190aba15_optionalFile optionalFile, _s_190aba15_optionalLine optionalLine, _s_190aba15_optionalUserData optionalUserData) {
  redCreateContext(malloc.value, free.value, optionalMallocTagged.value, optionalFreeTagged.value, debugCallback.value, sdkVersion.value, sdkExtensionsCount.value, sdkExtensions.value, optionalProgramName.value, optionalProgramVersion.value, optionalEngineName.value, optionalEngineVersion.value, optionalSettings.value, outContext.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateArray redCreateArray
#define _d52ffeba_context(value) value
#define _d52ffeba_gpu(value) value
#define _d52ffeba_handleName(value) value
#define _d52ffeba_type(value) value
#define _d52ffeba_bytesCount(value) value
#define _d52ffeba_structuredBufferElementBytesCount(value) value
#define _d52ffeba_initialAccess(value) value
#define _d52ffeba_initialQueueFamilyIndex(value) value
#define _d52ffeba_dedicate(value) value
#define _d52ffeba_outArray(value) value
#define _d52ffeba_outStatuses(value) value
#define _d52ffeba_optionalFile(value) value
#define _d52ffeba_optionalLine(value) value
#define _d52ffeba_optionalUserData(value) value
#else
typedef struct _s_d52ffeba_context { RedContext value; } _s_d52ffeba_context;
typedef struct _s_d52ffeba_gpu { RedHandleGpu value; } _s_d52ffeba_gpu;
typedef struct _s_d52ffeba_handleName { char* value; } _s_d52ffeba_handleName;
typedef struct _s_d52ffeba_type { RedArrayType value; } _s_d52ffeba_type;
typedef struct _s_d52ffeba_bytesCount { uint64_t value; } _s_d52ffeba_bytesCount;
typedef struct _s_d52ffeba_structuredBufferElementBytesCount { uint64_t value; } _s_d52ffeba_structuredBufferElementBytesCount;
typedef struct _s_d52ffeba_initialAccess { RedAccessBitflags value; } _s_d52ffeba_initialAccess;
typedef struct _s_d52ffeba_initialQueueFamilyIndex { unsigned value; } _s_d52ffeba_initialQueueFamilyIndex;
typedef struct _s_d52ffeba_dedicate { RedBool32 value; } _s_d52ffeba_dedicate;
typedef struct _s_d52ffeba_outArray { RedArray* value; } _s_d52ffeba_outArray;
typedef struct _s_d52ffeba_outStatuses { RedStatuses* value; } _s_d52ffeba_outStatuses;
typedef struct _s_d52ffeba_optionalFile { char* value; } _s_d52ffeba_optionalFile;
typedef struct _s_d52ffeba_optionalLine { int value; } _s_d52ffeba_optionalLine;
typedef struct _s_d52ffeba_optionalUserData { void* value; } _s_d52ffeba_optionalUserData;
static inline _s_d52ffeba_context _d52ffeba_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_context){value}; }
static inline _s_d52ffeba_gpu _d52ffeba_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_gpu){value}; }
static inline _s_d52ffeba_handleName _d52ffeba_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_handleName){value}; }
static inline _s_d52ffeba_type _d52ffeba_type(RedArrayType value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_type){value}; }
static inline _s_d52ffeba_bytesCount _d52ffeba_bytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_bytesCount){value}; }
static inline _s_d52ffeba_structuredBufferElementBytesCount _d52ffeba_structuredBufferElementBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_structuredBufferElementBytesCount){value}; }
static inline _s_d52ffeba_initialAccess _d52ffeba_initialAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_initialAccess){value}; }
static inline _s_d52ffeba_initialQueueFamilyIndex _d52ffeba_initialQueueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_initialQueueFamilyIndex){value}; }
static inline _s_d52ffeba_dedicate _d52ffeba_dedicate(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_dedicate){value}; }
static inline _s_d52ffeba_outArray _d52ffeba_outArray(RedArray* value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_outArray){value}; }
static inline _s_d52ffeba_outStatuses _d52ffeba_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_outStatuses){value}; }
static inline _s_d52ffeba_optionalFile _d52ffeba_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_optionalFile){value}; }
static inline _s_d52ffeba_optionalLine _d52ffeba_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_optionalLine){value}; }
static inline _s_d52ffeba_optionalUserData _d52ffeba_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d52ffeba_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateArray(_s_d52ffeba_context context, _s_d52ffeba_gpu gpu, _s_d52ffeba_handleName handleName, _s_d52ffeba_type type, _s_d52ffeba_bytesCount bytesCount, _s_d52ffeba_structuredBufferElementBytesCount structuredBufferElementBytesCount, _s_d52ffeba_initialAccess initialAccess, _s_d52ffeba_initialQueueFamilyIndex initialQueueFamilyIndex, _s_d52ffeba_dedicate dedicate, _s_d52ffeba_outArray outArray, _s_d52ffeba_outStatuses outStatuses, _s_d52ffeba_optionalFile optionalFile, _s_d52ffeba_optionalLine optionalLine, _s_d52ffeba_optionalUserData optionalUserData) {
  redCreateArray(context.value, gpu.value, handleName.value, type.value, bytesCount.value, structuredBufferElementBytesCount.value, initialAccess.value, initialQueueFamilyIndex.value, dedicate.value, outArray.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateImage redCreateImage
#define _82e1e095_context(value) value
#define _82e1e095_gpu(value) value
#define _82e1e095_handleName(value) value
#define _82e1e095_dimensions(value) value
#define _82e1e095_format(value) value
#define _82e1e095_width(value) value
#define _82e1e095_height(value) value
#define _82e1e095_depth(value) value
#define _82e1e095_levelsCount(value) value
#define _82e1e095_layersCount(value) value
#define _82e1e095_multisampleCount(value) value
#define _82e1e095_restrictToAccess(value) value
#define _82e1e095_initialAccess(value) value
#define _82e1e095_initialQueueFamilyIndex(value) value
#define _82e1e095_dedicate(value) value
#define _82e1e095_outImage(value) value
#define _82e1e095_outStatuses(value) value
#define _82e1e095_optionalFile(value) value
#define _82e1e095_optionalLine(value) value
#define _82e1e095_optionalUserData(value) value
#else
typedef struct _s_82e1e095_context { RedContext value; } _s_82e1e095_context;
typedef struct _s_82e1e095_gpu { RedHandleGpu value; } _s_82e1e095_gpu;
typedef struct _s_82e1e095_handleName { char* value; } _s_82e1e095_handleName;
typedef struct _s_82e1e095_dimensions { RedImageDimensions value; } _s_82e1e095_dimensions;
typedef struct _s_82e1e095_format { RedFormat value; } _s_82e1e095_format;
typedef struct _s_82e1e095_width { unsigned value; } _s_82e1e095_width;
typedef struct _s_82e1e095_height { unsigned value; } _s_82e1e095_height;
typedef struct _s_82e1e095_depth { unsigned value; } _s_82e1e095_depth;
typedef struct _s_82e1e095_levelsCount { unsigned value; } _s_82e1e095_levelsCount;
typedef struct _s_82e1e095_layersCount { unsigned value; } _s_82e1e095_layersCount;
typedef struct _s_82e1e095_multisampleCount { RedMultisampleCountBitflag value; } _s_82e1e095_multisampleCount;
typedef struct _s_82e1e095_restrictToAccess { RedAccessBitflags value; } _s_82e1e095_restrictToAccess;
typedef struct _s_82e1e095_initialAccess { RedAccessBitflags value; } _s_82e1e095_initialAccess;
typedef struct _s_82e1e095_initialQueueFamilyIndex { unsigned value; } _s_82e1e095_initialQueueFamilyIndex;
typedef struct _s_82e1e095_dedicate { RedBool32 value; } _s_82e1e095_dedicate;
typedef struct _s_82e1e095_outImage { RedImage* value; } _s_82e1e095_outImage;
typedef struct _s_82e1e095_outStatuses { RedStatuses* value; } _s_82e1e095_outStatuses;
typedef struct _s_82e1e095_optionalFile { char* value; } _s_82e1e095_optionalFile;
typedef struct _s_82e1e095_optionalLine { int value; } _s_82e1e095_optionalLine;
typedef struct _s_82e1e095_optionalUserData { void* value; } _s_82e1e095_optionalUserData;
static inline _s_82e1e095_context _82e1e095_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_context){value}; }
static inline _s_82e1e095_gpu _82e1e095_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_gpu){value}; }
static inline _s_82e1e095_handleName _82e1e095_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_handleName){value}; }
static inline _s_82e1e095_dimensions _82e1e095_dimensions(RedImageDimensions value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_dimensions){value}; }
static inline _s_82e1e095_format _82e1e095_format(RedFormat value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_format){value}; }
static inline _s_82e1e095_width _82e1e095_width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_width){value}; }
static inline _s_82e1e095_height _82e1e095_height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_height){value}; }
static inline _s_82e1e095_depth _82e1e095_depth(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_depth){value}; }
static inline _s_82e1e095_levelsCount _82e1e095_levelsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_levelsCount){value}; }
static inline _s_82e1e095_layersCount _82e1e095_layersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_layersCount){value}; }
static inline _s_82e1e095_multisampleCount _82e1e095_multisampleCount(RedMultisampleCountBitflag value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_multisampleCount){value}; }
static inline _s_82e1e095_restrictToAccess _82e1e095_restrictToAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_restrictToAccess){value}; }
static inline _s_82e1e095_initialAccess _82e1e095_initialAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_initialAccess){value}; }
static inline _s_82e1e095_initialQueueFamilyIndex _82e1e095_initialQueueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_initialQueueFamilyIndex){value}; }
static inline _s_82e1e095_dedicate _82e1e095_dedicate(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_dedicate){value}; }
static inline _s_82e1e095_outImage _82e1e095_outImage(RedImage* value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_outImage){value}; }
static inline _s_82e1e095_outStatuses _82e1e095_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_outStatuses){value}; }
static inline _s_82e1e095_optionalFile _82e1e095_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_optionalFile){value}; }
static inline _s_82e1e095_optionalLine _82e1e095_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_optionalLine){value}; }
static inline _s_82e1e095_optionalUserData _82e1e095_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_82e1e095_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateImage(_s_82e1e095_context context, _s_82e1e095_gpu gpu, _s_82e1e095_handleName handleName, _s_82e1e095_dimensions dimensions, _s_82e1e095_format format, _s_82e1e095_width width, _s_82e1e095_height height, _s_82e1e095_depth depth, _s_82e1e095_levelsCount levelsCount, _s_82e1e095_layersCount layersCount, _s_82e1e095_multisampleCount multisampleCount, _s_82e1e095_restrictToAccess restrictToAccess, _s_82e1e095_initialAccess initialAccess, _s_82e1e095_initialQueueFamilyIndex initialQueueFamilyIndex, _s_82e1e095_dedicate dedicate, _s_82e1e095_outImage outImage, _s_82e1e095_outStatuses outStatuses, _s_82e1e095_optionalFile optionalFile, _s_82e1e095_optionalLine optionalLine, _s_82e1e095_optionalUserData optionalUserData) {
  redCreateImage(context.value, gpu.value, handleName.value, dimensions.value, format.value, width.value, height.value, depth.value, levelsCount.value, layersCount.value, multisampleCount.value, restrictToAccess.value, initialAccess.value, initialQueueFamilyIndex.value, dedicate.value, outImage.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateSampler redCreateSampler
#define _f78d960a_context(value) value
#define _f78d960a_gpu(value) value
#define _f78d960a_handleName(value) value
#define _f78d960a_filteringMag(value) value
#define _f78d960a_filteringMin(value) value
#define _f78d960a_filteringMip(value) value
#define _f78d960a_behaviorOutsideTextureCoordinateU(value) value
#define _f78d960a_behaviorOutsideTextureCoordinateV(value) value
#define _f78d960a_behaviorOutsideTextureCoordinateW(value) value
#define _f78d960a_mipLodBias(value) value
#define _f78d960a_enableAnisotropy(value) value
#define _f78d960a_maxAnisotropy(value) value
#define _f78d960a_enableCompare(value) value
#define _f78d960a_compareOp(value) value
#define _f78d960a_minLod(value) value
#define _f78d960a_maxLod(value) value
#define _f78d960a_outSampler(value) value
#define _f78d960a_outStatuses(value) value
#define _f78d960a_optionalFile(value) value
#define _f78d960a_optionalLine(value) value
#define _f78d960a_optionalUserData(value) value
#else
typedef struct _s_f78d960a_context { RedContext value; } _s_f78d960a_context;
typedef struct _s_f78d960a_gpu { RedHandleGpu value; } _s_f78d960a_gpu;
typedef struct _s_f78d960a_handleName { char* value; } _s_f78d960a_handleName;
typedef struct _s_f78d960a_filteringMag { RedSamplerFiltering value; } _s_f78d960a_filteringMag;
typedef struct _s_f78d960a_filteringMin { RedSamplerFiltering value; } _s_f78d960a_filteringMin;
typedef struct _s_f78d960a_filteringMip { RedSamplerFilteringMip value; } _s_f78d960a_filteringMip;
typedef struct _s_f78d960a_behaviorOutsideTextureCoordinateU { RedSamplerBehaviorOutsideTextureCoordinate value; } _s_f78d960a_behaviorOutsideTextureCoordinateU;
typedef struct _s_f78d960a_behaviorOutsideTextureCoordinateV { RedSamplerBehaviorOutsideTextureCoordinate value; } _s_f78d960a_behaviorOutsideTextureCoordinateV;
typedef struct _s_f78d960a_behaviorOutsideTextureCoordinateW { RedSamplerBehaviorOutsideTextureCoordinate value; } _s_f78d960a_behaviorOutsideTextureCoordinateW;
typedef struct _s_f78d960a_mipLodBias { float value; } _s_f78d960a_mipLodBias;
typedef struct _s_f78d960a_enableAnisotropy { RedBool32 value; } _s_f78d960a_enableAnisotropy;
typedef struct _s_f78d960a_maxAnisotropy { float value; } _s_f78d960a_maxAnisotropy;
typedef struct _s_f78d960a_enableCompare { RedBool32 value; } _s_f78d960a_enableCompare;
typedef struct _s_f78d960a_compareOp { RedCompareOp value; } _s_f78d960a_compareOp;
typedef struct _s_f78d960a_minLod { float value; } _s_f78d960a_minLod;
typedef struct _s_f78d960a_maxLod { float value; } _s_f78d960a_maxLod;
typedef struct _s_f78d960a_outSampler { RedHandleSampler* value; } _s_f78d960a_outSampler;
typedef struct _s_f78d960a_outStatuses { RedStatuses* value; } _s_f78d960a_outStatuses;
typedef struct _s_f78d960a_optionalFile { char* value; } _s_f78d960a_optionalFile;
typedef struct _s_f78d960a_optionalLine { int value; } _s_f78d960a_optionalLine;
typedef struct _s_f78d960a_optionalUserData { void* value; } _s_f78d960a_optionalUserData;
static inline _s_f78d960a_context _f78d960a_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_context){value}; }
static inline _s_f78d960a_gpu _f78d960a_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_gpu){value}; }
static inline _s_f78d960a_handleName _f78d960a_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_handleName){value}; }
static inline _s_f78d960a_filteringMag _f78d960a_filteringMag(RedSamplerFiltering value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_filteringMag){value}; }
static inline _s_f78d960a_filteringMin _f78d960a_filteringMin(RedSamplerFiltering value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_filteringMin){value}; }
static inline _s_f78d960a_filteringMip _f78d960a_filteringMip(RedSamplerFilteringMip value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_filteringMip){value}; }
static inline _s_f78d960a_behaviorOutsideTextureCoordinateU _f78d960a_behaviorOutsideTextureCoordinateU(RedSamplerBehaviorOutsideTextureCoordinate value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_behaviorOutsideTextureCoordinateU){value}; }
static inline _s_f78d960a_behaviorOutsideTextureCoordinateV _f78d960a_behaviorOutsideTextureCoordinateV(RedSamplerBehaviorOutsideTextureCoordinate value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_behaviorOutsideTextureCoordinateV){value}; }
static inline _s_f78d960a_behaviorOutsideTextureCoordinateW _f78d960a_behaviorOutsideTextureCoordinateW(RedSamplerBehaviorOutsideTextureCoordinate value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_behaviorOutsideTextureCoordinateW){value}; }
static inline _s_f78d960a_mipLodBias _f78d960a_mipLodBias(float value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_mipLodBias){value}; }
static inline _s_f78d960a_enableAnisotropy _f78d960a_enableAnisotropy(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_enableAnisotropy){value}; }
static inline _s_f78d960a_maxAnisotropy _f78d960a_maxAnisotropy(float value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_maxAnisotropy){value}; }
static inline _s_f78d960a_enableCompare _f78d960a_enableCompare(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_enableCompare){value}; }
static inline _s_f78d960a_compareOp _f78d960a_compareOp(RedCompareOp value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_compareOp){value}; }
static inline _s_f78d960a_minLod _f78d960a_minLod(float value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_minLod){value}; }
static inline _s_f78d960a_maxLod _f78d960a_maxLod(float value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_maxLod){value}; }
static inline _s_f78d960a_outSampler _f78d960a_outSampler(RedHandleSampler* value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_outSampler){value}; }
static inline _s_f78d960a_outStatuses _f78d960a_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_outStatuses){value}; }
static inline _s_f78d960a_optionalFile _f78d960a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_optionalFile){value}; }
static inline _s_f78d960a_optionalLine _f78d960a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_optionalLine){value}; }
static inline _s_f78d960a_optionalUserData _f78d960a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f78d960a_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateSampler(_s_f78d960a_context context, _s_f78d960a_gpu gpu, _s_f78d960a_handleName handleName, _s_f78d960a_filteringMag filteringMag, _s_f78d960a_filteringMin filteringMin, _s_f78d960a_filteringMip filteringMip, _s_f78d960a_behaviorOutsideTextureCoordinateU behaviorOutsideTextureCoordinateU, _s_f78d960a_behaviorOutsideTextureCoordinateV behaviorOutsideTextureCoordinateV, _s_f78d960a_behaviorOutsideTextureCoordinateW behaviorOutsideTextureCoordinateW, _s_f78d960a_mipLodBias mipLodBias, _s_f78d960a_enableAnisotropy enableAnisotropy, _s_f78d960a_maxAnisotropy maxAnisotropy, _s_f78d960a_enableCompare enableCompare, _s_f78d960a_compareOp compareOp, _s_f78d960a_minLod minLod, _s_f78d960a_maxLod maxLod, _s_f78d960a_outSampler outSampler, _s_f78d960a_outStatuses outStatuses, _s_f78d960a_optionalFile optionalFile, _s_f78d960a_optionalLine optionalLine, _s_f78d960a_optionalUserData optionalUserData) {
  redCreateSampler(context.value, gpu.value, handleName.value, filteringMag.value, filteringMin.value, filteringMip.value, behaviorOutsideTextureCoordinateU.value, behaviorOutsideTextureCoordinateV.value, behaviorOutsideTextureCoordinateW.value, mipLodBias.value, enableAnisotropy.value, maxAnisotropy.value, enableCompare.value, compareOp.value, minLod.value, maxLod.value, outSampler.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateTexture redCreateTexture
#define _f15ab6f9_context(value) value
#define _f15ab6f9_gpu(value) value
#define _f15ab6f9_handleName(value) value
#define _f15ab6f9_image(value) value
#define _f15ab6f9_parts(value) value
#define _f15ab6f9_dimensions(value) value
#define _f15ab6f9_format(value) value
#define _f15ab6f9_levelsFirst(value) value
#define _f15ab6f9_levelsCount(value) value
#define _f15ab6f9_layersFirst(value) value
#define _f15ab6f9_layersCount(value) value
#define _f15ab6f9_restrictToAccess(value) value
#define _f15ab6f9_outTexture(value) value
#define _f15ab6f9_outStatuses(value) value
#define _f15ab6f9_optionalFile(value) value
#define _f15ab6f9_optionalLine(value) value
#define _f15ab6f9_optionalUserData(value) value
#else
typedef struct _s_f15ab6f9_context { RedContext value; } _s_f15ab6f9_context;
typedef struct _s_f15ab6f9_gpu { RedHandleGpu value; } _s_f15ab6f9_gpu;
typedef struct _s_f15ab6f9_handleName { char* value; } _s_f15ab6f9_handleName;
typedef struct _s_f15ab6f9_image { RedHandleImage value; } _s_f15ab6f9_image;
typedef struct _s_f15ab6f9_parts { RedImagePartBitflags value; } _s_f15ab6f9_parts;
typedef struct _s_f15ab6f9_dimensions { RedTextureDimensions value; } _s_f15ab6f9_dimensions;
typedef struct _s_f15ab6f9_format { RedFormat value; } _s_f15ab6f9_format;
typedef struct _s_f15ab6f9_levelsFirst { unsigned value; } _s_f15ab6f9_levelsFirst;
typedef struct _s_f15ab6f9_levelsCount { unsigned value; } _s_f15ab6f9_levelsCount;
typedef struct _s_f15ab6f9_layersFirst { unsigned value; } _s_f15ab6f9_layersFirst;
typedef struct _s_f15ab6f9_layersCount { unsigned value; } _s_f15ab6f9_layersCount;
typedef struct _s_f15ab6f9_restrictToAccess { RedAccessBitflags value; } _s_f15ab6f9_restrictToAccess;
typedef struct _s_f15ab6f9_outTexture { RedHandleTexture* value; } _s_f15ab6f9_outTexture;
typedef struct _s_f15ab6f9_outStatuses { RedStatuses* value; } _s_f15ab6f9_outStatuses;
typedef struct _s_f15ab6f9_optionalFile { char* value; } _s_f15ab6f9_optionalFile;
typedef struct _s_f15ab6f9_optionalLine { int value; } _s_f15ab6f9_optionalLine;
typedef struct _s_f15ab6f9_optionalUserData { void* value; } _s_f15ab6f9_optionalUserData;
static inline _s_f15ab6f9_context _f15ab6f9_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_context){value}; }
static inline _s_f15ab6f9_gpu _f15ab6f9_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_gpu){value}; }
static inline _s_f15ab6f9_handleName _f15ab6f9_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_handleName){value}; }
static inline _s_f15ab6f9_image _f15ab6f9_image(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_image){value}; }
static inline _s_f15ab6f9_parts _f15ab6f9_parts(RedImagePartBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_parts){value}; }
static inline _s_f15ab6f9_dimensions _f15ab6f9_dimensions(RedTextureDimensions value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_dimensions){value}; }
static inline _s_f15ab6f9_format _f15ab6f9_format(RedFormat value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_format){value}; }
static inline _s_f15ab6f9_levelsFirst _f15ab6f9_levelsFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_levelsFirst){value}; }
static inline _s_f15ab6f9_levelsCount _f15ab6f9_levelsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_levelsCount){value}; }
static inline _s_f15ab6f9_layersFirst _f15ab6f9_layersFirst(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_layersFirst){value}; }
static inline _s_f15ab6f9_layersCount _f15ab6f9_layersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_layersCount){value}; }
static inline _s_f15ab6f9_restrictToAccess _f15ab6f9_restrictToAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_restrictToAccess){value}; }
static inline _s_f15ab6f9_outTexture _f15ab6f9_outTexture(RedHandleTexture* value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_outTexture){value}; }
static inline _s_f15ab6f9_outStatuses _f15ab6f9_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_outStatuses){value}; }
static inline _s_f15ab6f9_optionalFile _f15ab6f9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_optionalFile){value}; }
static inline _s_f15ab6f9_optionalLine _f15ab6f9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_optionalLine){value}; }
static inline _s_f15ab6f9_optionalUserData _f15ab6f9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f15ab6f9_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateTexture(_s_f15ab6f9_context context, _s_f15ab6f9_gpu gpu, _s_f15ab6f9_handleName handleName, _s_f15ab6f9_image image, _s_f15ab6f9_parts parts, _s_f15ab6f9_dimensions dimensions, _s_f15ab6f9_format format, _s_f15ab6f9_levelsFirst levelsFirst, _s_f15ab6f9_levelsCount levelsCount, _s_f15ab6f9_layersFirst layersFirst, _s_f15ab6f9_layersCount layersCount, _s_f15ab6f9_restrictToAccess restrictToAccess, _s_f15ab6f9_outTexture outTexture, _s_f15ab6f9_outStatuses outStatuses, _s_f15ab6f9_optionalFile optionalFile, _s_f15ab6f9_optionalLine optionalLine, _s_f15ab6f9_optionalUserData optionalUserData) {
  redCreateTexture(context.value, gpu.value, handleName.value, image.value, parts.value, dimensions.value, format.value, levelsFirst.value, levelsCount.value, layersFirst.value, layersCount.value, restrictToAccess.value, outTexture.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateGpuCode redCreateGpuCode
#define _b18af357_context(value) value
#define _b18af357_gpu(value) value
#define _b18af357_handleName(value) value
#define _b18af357_irBytesCount(value) value
#define _b18af357_ir(value) value
#define _b18af357_outGpuCode(value) value
#define _b18af357_outStatuses(value) value
#define _b18af357_optionalFile(value) value
#define _b18af357_optionalLine(value) value
#define _b18af357_optionalUserData(value) value
#else
typedef struct _s_b18af357_context { RedContext value; } _s_b18af357_context;
typedef struct _s_b18af357_gpu { RedHandleGpu value; } _s_b18af357_gpu;
typedef struct _s_b18af357_handleName { char* value; } _s_b18af357_handleName;
typedef struct _s_b18af357_irBytesCount { uint64_t value; } _s_b18af357_irBytesCount;
typedef struct _s_b18af357_ir { void* value; } _s_b18af357_ir;
typedef struct _s_b18af357_outGpuCode { RedHandleGpuCode* value; } _s_b18af357_outGpuCode;
typedef struct _s_b18af357_outStatuses { RedStatuses* value; } _s_b18af357_outStatuses;
typedef struct _s_b18af357_optionalFile { char* value; } _s_b18af357_optionalFile;
typedef struct _s_b18af357_optionalLine { int value; } _s_b18af357_optionalLine;
typedef struct _s_b18af357_optionalUserData { void* value; } _s_b18af357_optionalUserData;
static inline _s_b18af357_context _b18af357_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b18af357_context){value}; }
static inline _s_b18af357_gpu _b18af357_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b18af357_gpu){value}; }
static inline _s_b18af357_handleName _b18af357_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b18af357_handleName){value}; }
static inline _s_b18af357_irBytesCount _b18af357_irBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_b18af357_irBytesCount){value}; }
static inline _s_b18af357_ir _b18af357_ir(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b18af357_ir){value}; }
static inline _s_b18af357_outGpuCode _b18af357_outGpuCode(RedHandleGpuCode* value) { return REDGPU_NP_STRUCT_INIT(_s_b18af357_outGpuCode){value}; }
static inline _s_b18af357_outStatuses _b18af357_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b18af357_outStatuses){value}; }
static inline _s_b18af357_optionalFile _b18af357_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b18af357_optionalFile){value}; }
static inline _s_b18af357_optionalLine _b18af357_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b18af357_optionalLine){value}; }
static inline _s_b18af357_optionalUserData _b18af357_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b18af357_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateGpuCode(_s_b18af357_context context, _s_b18af357_gpu gpu, _s_b18af357_handleName handleName, _s_b18af357_irBytesCount irBytesCount, _s_b18af357_ir ir, _s_b18af357_outGpuCode outGpuCode, _s_b18af357_outStatuses outStatuses, _s_b18af357_optionalFile optionalFile, _s_b18af357_optionalLine optionalLine, _s_b18af357_optionalUserData optionalUserData) {
  redCreateGpuCode(context.value, gpu.value, handleName.value, irBytesCount.value, ir.value, outGpuCode.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateOutputDeclaration redCreateOutputDeclaration
#define _53933282_context(value) value
#define _53933282_gpu(value) value
#define _53933282_handleName(value) value
#define _53933282_outputDeclarationMembers(value) value
#define _53933282_outputDeclarationMembersResolveSources(value) value
#define _53933282_dependencyByRegion(value) value
#define _53933282_dependencyByRegionAllowUsageAliasOrderBarriers(value) value
#define _53933282_outOutputDeclaration(value) value
#define _53933282_outStatuses(value) value
#define _53933282_optionalFile(value) value
#define _53933282_optionalLine(value) value
#define _53933282_optionalUserData(value) value
#else
typedef struct _s_53933282_context { RedContext value; } _s_53933282_context;
typedef struct _s_53933282_gpu { RedHandleGpu value; } _s_53933282_gpu;
typedef struct _s_53933282_handleName { char* value; } _s_53933282_handleName;
typedef struct _s_53933282_outputDeclarationMembers { RedOutputDeclarationMembers* value; } _s_53933282_outputDeclarationMembers;
typedef struct _s_53933282_outputDeclarationMembersResolveSources { RedOutputDeclarationMembersResolveSources* value; } _s_53933282_outputDeclarationMembersResolveSources;
typedef struct _s_53933282_dependencyByRegion { RedBool32 value; } _s_53933282_dependencyByRegion;
typedef struct _s_53933282_dependencyByRegionAllowUsageAliasOrderBarriers { RedBool32 value; } _s_53933282_dependencyByRegionAllowUsageAliasOrderBarriers;
typedef struct _s_53933282_outOutputDeclaration { RedHandleOutputDeclaration* value; } _s_53933282_outOutputDeclaration;
typedef struct _s_53933282_outStatuses { RedStatuses* value; } _s_53933282_outStatuses;
typedef struct _s_53933282_optionalFile { char* value; } _s_53933282_optionalFile;
typedef struct _s_53933282_optionalLine { int value; } _s_53933282_optionalLine;
typedef struct _s_53933282_optionalUserData { void* value; } _s_53933282_optionalUserData;
static inline _s_53933282_context _53933282_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_53933282_context){value}; }
static inline _s_53933282_gpu _53933282_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_53933282_gpu){value}; }
static inline _s_53933282_handleName _53933282_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_53933282_handleName){value}; }
static inline _s_53933282_outputDeclarationMembers _53933282_outputDeclarationMembers(RedOutputDeclarationMembers* value) { return REDGPU_NP_STRUCT_INIT(_s_53933282_outputDeclarationMembers){value}; }
static inline _s_53933282_outputDeclarationMembersResolveSources _53933282_outputDeclarationMembersResolveSources(RedOutputDeclarationMembersResolveSources* value) { return REDGPU_NP_STRUCT_INIT(_s_53933282_outputDeclarationMembersResolveSources){value}; }
static inline _s_53933282_dependencyByRegion _53933282_dependencyByRegion(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_53933282_dependencyByRegion){value}; }
static inline _s_53933282_dependencyByRegionAllowUsageAliasOrderBarriers _53933282_dependencyByRegionAllowUsageAliasOrderBarriers(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_53933282_dependencyByRegionAllowUsageAliasOrderBarriers){value}; }
static inline _s_53933282_outOutputDeclaration _53933282_outOutputDeclaration(RedHandleOutputDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_53933282_outOutputDeclaration){value}; }
static inline _s_53933282_outStatuses _53933282_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_53933282_outStatuses){value}; }
static inline _s_53933282_optionalFile _53933282_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_53933282_optionalFile){value}; }
static inline _s_53933282_optionalLine _53933282_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_53933282_optionalLine){value}; }
static inline _s_53933282_optionalUserData _53933282_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_53933282_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateOutputDeclaration(_s_53933282_context context, _s_53933282_gpu gpu, _s_53933282_handleName handleName, _s_53933282_outputDeclarationMembers outputDeclarationMembers, _s_53933282_outputDeclarationMembersResolveSources outputDeclarationMembersResolveSources, _s_53933282_dependencyByRegion dependencyByRegion, _s_53933282_dependencyByRegionAllowUsageAliasOrderBarriers dependencyByRegionAllowUsageAliasOrderBarriers, _s_53933282_outOutputDeclaration outOutputDeclaration, _s_53933282_outStatuses outStatuses, _s_53933282_optionalFile optionalFile, _s_53933282_optionalLine optionalLine, _s_53933282_optionalUserData optionalUserData) {
  redCreateOutputDeclaration(context.value, gpu.value, handleName.value, outputDeclarationMembers.value, outputDeclarationMembersResolveSources.value, dependencyByRegion.value, dependencyByRegionAllowUsageAliasOrderBarriers.value, outOutputDeclaration.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateStructDeclaration redCreateStructDeclaration
#define _a00360d5_context(value) value
#define _a00360d5_gpu(value) value
#define _a00360d5_handleName(value) value
#define _a00360d5_structDeclarationMembersCount(value) value
#define _a00360d5_structDeclarationMembers(value) value
#define _a00360d5_structDeclarationMembersArrayROCount(value) value
#define _a00360d5_structDeclarationMembersArrayRO(value) value
#define _a00360d5_procedureParametersHandlesDeclaration(value) value
#define _a00360d5_outStructDeclaration(value) value
#define _a00360d5_outStatuses(value) value
#define _a00360d5_optionalFile(value) value
#define _a00360d5_optionalLine(value) value
#define _a00360d5_optionalUserData(value) value
#else
typedef struct _s_a00360d5_context { RedContext value; } _s_a00360d5_context;
typedef struct _s_a00360d5_gpu { RedHandleGpu value; } _s_a00360d5_gpu;
typedef struct _s_a00360d5_handleName { char* value; } _s_a00360d5_handleName;
typedef struct _s_a00360d5_structDeclarationMembersCount { unsigned value; } _s_a00360d5_structDeclarationMembersCount;
typedef struct _s_a00360d5_structDeclarationMembers { RedStructDeclarationMember* value; } _s_a00360d5_structDeclarationMembers;
typedef struct _s_a00360d5_structDeclarationMembersArrayROCount { unsigned value; } _s_a00360d5_structDeclarationMembersArrayROCount;
typedef struct _s_a00360d5_structDeclarationMembersArrayRO { RedStructDeclarationMemberArrayRO* value; } _s_a00360d5_structDeclarationMembersArrayRO;
typedef struct _s_a00360d5_procedureParametersHandlesDeclaration { RedBool32 value; } _s_a00360d5_procedureParametersHandlesDeclaration;
typedef struct _s_a00360d5_outStructDeclaration { RedHandleStructDeclaration* value; } _s_a00360d5_outStructDeclaration;
typedef struct _s_a00360d5_outStatuses { RedStatuses* value; } _s_a00360d5_outStatuses;
typedef struct _s_a00360d5_optionalFile { char* value; } _s_a00360d5_optionalFile;
typedef struct _s_a00360d5_optionalLine { int value; } _s_a00360d5_optionalLine;
typedef struct _s_a00360d5_optionalUserData { void* value; } _s_a00360d5_optionalUserData;
static inline _s_a00360d5_context _a00360d5_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_context){value}; }
static inline _s_a00360d5_gpu _a00360d5_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_gpu){value}; }
static inline _s_a00360d5_handleName _a00360d5_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_handleName){value}; }
static inline _s_a00360d5_structDeclarationMembersCount _a00360d5_structDeclarationMembersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_structDeclarationMembersCount){value}; }
static inline _s_a00360d5_structDeclarationMembers _a00360d5_structDeclarationMembers(RedStructDeclarationMember* value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_structDeclarationMembers){value}; }
static inline _s_a00360d5_structDeclarationMembersArrayROCount _a00360d5_structDeclarationMembersArrayROCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_structDeclarationMembersArrayROCount){value}; }
static inline _s_a00360d5_structDeclarationMembersArrayRO _a00360d5_structDeclarationMembersArrayRO(RedStructDeclarationMemberArrayRO* value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_structDeclarationMembersArrayRO){value}; }
static inline _s_a00360d5_procedureParametersHandlesDeclaration _a00360d5_procedureParametersHandlesDeclaration(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_procedureParametersHandlesDeclaration){value}; }
static inline _s_a00360d5_outStructDeclaration _a00360d5_outStructDeclaration(RedHandleStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_outStructDeclaration){value}; }
static inline _s_a00360d5_outStatuses _a00360d5_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_outStatuses){value}; }
static inline _s_a00360d5_optionalFile _a00360d5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_optionalFile){value}; }
static inline _s_a00360d5_optionalLine _a00360d5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_optionalLine){value}; }
static inline _s_a00360d5_optionalUserData _a00360d5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a00360d5_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateStructDeclaration(_s_a00360d5_context context, _s_a00360d5_gpu gpu, _s_a00360d5_handleName handleName, _s_a00360d5_structDeclarationMembersCount structDeclarationMembersCount, _s_a00360d5_structDeclarationMembers structDeclarationMembers, _s_a00360d5_structDeclarationMembersArrayROCount structDeclarationMembersArrayROCount, _s_a00360d5_structDeclarationMembersArrayRO structDeclarationMembersArrayRO, _s_a00360d5_procedureParametersHandlesDeclaration procedureParametersHandlesDeclaration, _s_a00360d5_outStructDeclaration outStructDeclaration, _s_a00360d5_outStatuses outStatuses, _s_a00360d5_optionalFile optionalFile, _s_a00360d5_optionalLine optionalLine, _s_a00360d5_optionalUserData optionalUserData) {
  redCreateStructDeclaration(context.value, gpu.value, handleName.value, structDeclarationMembersCount.value, structDeclarationMembers.value, structDeclarationMembersArrayROCount.value, structDeclarationMembersArrayRO.value, procedureParametersHandlesDeclaration.value, outStructDeclaration.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateProcedureParameters redCreateProcedureParameters
#define _12fd9e64_context(value) value
#define _12fd9e64_gpu(value) value
#define _12fd9e64_handleName(value) value
#define _12fd9e64_procedureParametersDeclaration(value) value
#define _12fd9e64_outProcedureParameters(value) value
#define _12fd9e64_outStatuses(value) value
#define _12fd9e64_optionalFile(value) value
#define _12fd9e64_optionalLine(value) value
#define _12fd9e64_optionalUserData(value) value
#else
typedef struct _s_12fd9e64_context { RedContext value; } _s_12fd9e64_context;
typedef struct _s_12fd9e64_gpu { RedHandleGpu value; } _s_12fd9e64_gpu;
typedef struct _s_12fd9e64_handleName { char* value; } _s_12fd9e64_handleName;
typedef struct _s_12fd9e64_procedureParametersDeclaration { RedProcedureParametersDeclaration* value; } _s_12fd9e64_procedureParametersDeclaration;
typedef struct _s_12fd9e64_outProcedureParameters { RedHandleProcedureParameters* value; } _s_12fd9e64_outProcedureParameters;
typedef struct _s_12fd9e64_outStatuses { RedStatuses* value; } _s_12fd9e64_outStatuses;
typedef struct _s_12fd9e64_optionalFile { char* value; } _s_12fd9e64_optionalFile;
typedef struct _s_12fd9e64_optionalLine { int value; } _s_12fd9e64_optionalLine;
typedef struct _s_12fd9e64_optionalUserData { void* value; } _s_12fd9e64_optionalUserData;
static inline _s_12fd9e64_context _12fd9e64_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_12fd9e64_context){value}; }
static inline _s_12fd9e64_gpu _12fd9e64_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_12fd9e64_gpu){value}; }
static inline _s_12fd9e64_handleName _12fd9e64_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_12fd9e64_handleName){value}; }
static inline _s_12fd9e64_procedureParametersDeclaration _12fd9e64_procedureParametersDeclaration(RedProcedureParametersDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_12fd9e64_procedureParametersDeclaration){value}; }
static inline _s_12fd9e64_outProcedureParameters _12fd9e64_outProcedureParameters(RedHandleProcedureParameters* value) { return REDGPU_NP_STRUCT_INIT(_s_12fd9e64_outProcedureParameters){value}; }
static inline _s_12fd9e64_outStatuses _12fd9e64_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_12fd9e64_outStatuses){value}; }
static inline _s_12fd9e64_optionalFile _12fd9e64_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_12fd9e64_optionalFile){value}; }
static inline _s_12fd9e64_optionalLine _12fd9e64_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_12fd9e64_optionalLine){value}; }
static inline _s_12fd9e64_optionalUserData _12fd9e64_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_12fd9e64_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateProcedureParameters(_s_12fd9e64_context context, _s_12fd9e64_gpu gpu, _s_12fd9e64_handleName handleName, _s_12fd9e64_procedureParametersDeclaration procedureParametersDeclaration, _s_12fd9e64_outProcedureParameters outProcedureParameters, _s_12fd9e64_outStatuses outStatuses, _s_12fd9e64_optionalFile optionalFile, _s_12fd9e64_optionalLine optionalLine, _s_12fd9e64_optionalUserData optionalUserData) {
  redCreateProcedureParameters(context.value, gpu.value, handleName.value, procedureParametersDeclaration.value, outProcedureParameters.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateProcedureCache redCreateProcedureCache
#define _fefe1467_context(value) value
#define _fefe1467_gpu(value) value
#define _fefe1467_handleName(value) value
#define _fefe1467_fromBlobBytesCount(value) value
#define _fefe1467_fromBlob(value) value
#define _fefe1467_outProcedureCache(value) value
#define _fefe1467_outStatuses(value) value
#define _fefe1467_optionalFile(value) value
#define _fefe1467_optionalLine(value) value
#define _fefe1467_optionalUserData(value) value
#else
typedef struct _s_fefe1467_context { RedContext value; } _s_fefe1467_context;
typedef struct _s_fefe1467_gpu { RedHandleGpu value; } _s_fefe1467_gpu;
typedef struct _s_fefe1467_handleName { char* value; } _s_fefe1467_handleName;
typedef struct _s_fefe1467_fromBlobBytesCount { uint64_t value; } _s_fefe1467_fromBlobBytesCount;
typedef struct _s_fefe1467_fromBlob { void* value; } _s_fefe1467_fromBlob;
typedef struct _s_fefe1467_outProcedureCache { RedHandleProcedureCache* value; } _s_fefe1467_outProcedureCache;
typedef struct _s_fefe1467_outStatuses { RedStatuses* value; } _s_fefe1467_outStatuses;
typedef struct _s_fefe1467_optionalFile { char* value; } _s_fefe1467_optionalFile;
typedef struct _s_fefe1467_optionalLine { int value; } _s_fefe1467_optionalLine;
typedef struct _s_fefe1467_optionalUserData { void* value; } _s_fefe1467_optionalUserData;
static inline _s_fefe1467_context _fefe1467_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_fefe1467_context){value}; }
static inline _s_fefe1467_gpu _fefe1467_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_fefe1467_gpu){value}; }
static inline _s_fefe1467_handleName _fefe1467_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fefe1467_handleName){value}; }
static inline _s_fefe1467_fromBlobBytesCount _fefe1467_fromBlobBytesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_fefe1467_fromBlobBytesCount){value}; }
static inline _s_fefe1467_fromBlob _fefe1467_fromBlob(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fefe1467_fromBlob){value}; }
static inline _s_fefe1467_outProcedureCache _fefe1467_outProcedureCache(RedHandleProcedureCache* value) { return REDGPU_NP_STRUCT_INIT(_s_fefe1467_outProcedureCache){value}; }
static inline _s_fefe1467_outStatuses _fefe1467_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_fefe1467_outStatuses){value}; }
static inline _s_fefe1467_optionalFile _fefe1467_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fefe1467_optionalFile){value}; }
static inline _s_fefe1467_optionalLine _fefe1467_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fefe1467_optionalLine){value}; }
static inline _s_fefe1467_optionalUserData _fefe1467_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fefe1467_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateProcedureCache(_s_fefe1467_context context, _s_fefe1467_gpu gpu, _s_fefe1467_handleName handleName, _s_fefe1467_fromBlobBytesCount fromBlobBytesCount, _s_fefe1467_fromBlob fromBlob, _s_fefe1467_outProcedureCache outProcedureCache, _s_fefe1467_outStatuses outStatuses, _s_fefe1467_optionalFile optionalFile, _s_fefe1467_optionalLine optionalLine, _s_fefe1467_optionalUserData optionalUserData) {
  redCreateProcedureCache(context.value, gpu.value, handleName.value, fromBlobBytesCount.value, fromBlob.value, outProcedureCache.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateProcedure redCreateProcedure
#define _7faa13cb_context(value) value
#define _7faa13cb_gpu(value) value
#define _7faa13cb_handleName(value) value
#define _7faa13cb_procedureCache(value) value
#define _7faa13cb_outputDeclaration(value) value
#define _7faa13cb_procedureParameters(value) value
#define _7faa13cb_gpuCodeVertexMainProcedureName(value) value
#define _7faa13cb_gpuCodeVertex(value) value
#define _7faa13cb_gpuCodeFragmentMainProcedureName(value) value
#define _7faa13cb_gpuCodeFragment(value) value
#define _7faa13cb_state(value) value
#define _7faa13cb_stateExtension(value) value
#define _7faa13cb_deriveBase(value) value
#define _7faa13cb_deriveFrom(value) value
#define _7faa13cb_outProcedure(value) value
#define _7faa13cb_outStatuses(value) value
#define _7faa13cb_optionalFile(value) value
#define _7faa13cb_optionalLine(value) value
#define _7faa13cb_optionalUserData(value) value
#else
typedef struct _s_7faa13cb_context { RedContext value; } _s_7faa13cb_context;
typedef struct _s_7faa13cb_gpu { RedHandleGpu value; } _s_7faa13cb_gpu;
typedef struct _s_7faa13cb_handleName { char* value; } _s_7faa13cb_handleName;
typedef struct _s_7faa13cb_procedureCache { RedHandleProcedureCache value; } _s_7faa13cb_procedureCache;
typedef struct _s_7faa13cb_outputDeclaration { RedHandleOutputDeclaration value; } _s_7faa13cb_outputDeclaration;
typedef struct _s_7faa13cb_procedureParameters { RedHandleProcedureParameters value; } _s_7faa13cb_procedureParameters;
typedef struct _s_7faa13cb_gpuCodeVertexMainProcedureName { char* value; } _s_7faa13cb_gpuCodeVertexMainProcedureName;
typedef struct _s_7faa13cb_gpuCodeVertex { RedHandleGpuCode value; } _s_7faa13cb_gpuCodeVertex;
typedef struct _s_7faa13cb_gpuCodeFragmentMainProcedureName { char* value; } _s_7faa13cb_gpuCodeFragmentMainProcedureName;
typedef struct _s_7faa13cb_gpuCodeFragment { RedHandleGpuCode value; } _s_7faa13cb_gpuCodeFragment;
typedef struct _s_7faa13cb_state { RedProcedureState* value; } _s_7faa13cb_state;
typedef struct _s_7faa13cb_stateExtension { void* value; } _s_7faa13cb_stateExtension;
typedef struct _s_7faa13cb_deriveBase { RedBool32 value; } _s_7faa13cb_deriveBase;
typedef struct _s_7faa13cb_deriveFrom { RedHandleProcedure value; } _s_7faa13cb_deriveFrom;
typedef struct _s_7faa13cb_outProcedure { RedHandleProcedure* value; } _s_7faa13cb_outProcedure;
typedef struct _s_7faa13cb_outStatuses { RedStatuses* value; } _s_7faa13cb_outStatuses;
typedef struct _s_7faa13cb_optionalFile { char* value; } _s_7faa13cb_optionalFile;
typedef struct _s_7faa13cb_optionalLine { int value; } _s_7faa13cb_optionalLine;
typedef struct _s_7faa13cb_optionalUserData { void* value; } _s_7faa13cb_optionalUserData;
static inline _s_7faa13cb_context _7faa13cb_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_context){value}; }
static inline _s_7faa13cb_gpu _7faa13cb_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_gpu){value}; }
static inline _s_7faa13cb_handleName _7faa13cb_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_handleName){value}; }
static inline _s_7faa13cb_procedureCache _7faa13cb_procedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_procedureCache){value}; }
static inline _s_7faa13cb_outputDeclaration _7faa13cb_outputDeclaration(RedHandleOutputDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_outputDeclaration){value}; }
static inline _s_7faa13cb_procedureParameters _7faa13cb_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_procedureParameters){value}; }
static inline _s_7faa13cb_gpuCodeVertexMainProcedureName _7faa13cb_gpuCodeVertexMainProcedureName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_gpuCodeVertexMainProcedureName){value}; }
static inline _s_7faa13cb_gpuCodeVertex _7faa13cb_gpuCodeVertex(RedHandleGpuCode value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_gpuCodeVertex){value}; }
static inline _s_7faa13cb_gpuCodeFragmentMainProcedureName _7faa13cb_gpuCodeFragmentMainProcedureName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_gpuCodeFragmentMainProcedureName){value}; }
static inline _s_7faa13cb_gpuCodeFragment _7faa13cb_gpuCodeFragment(RedHandleGpuCode value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_gpuCodeFragment){value}; }
static inline _s_7faa13cb_state _7faa13cb_state(RedProcedureState* value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_state){value}; }
static inline _s_7faa13cb_stateExtension _7faa13cb_stateExtension(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_stateExtension){value}; }
static inline _s_7faa13cb_deriveBase _7faa13cb_deriveBase(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_deriveBase){value}; }
static inline _s_7faa13cb_deriveFrom _7faa13cb_deriveFrom(RedHandleProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_deriveFrom){value}; }
static inline _s_7faa13cb_outProcedure _7faa13cb_outProcedure(RedHandleProcedure* value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_outProcedure){value}; }
static inline _s_7faa13cb_outStatuses _7faa13cb_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_outStatuses){value}; }
static inline _s_7faa13cb_optionalFile _7faa13cb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_optionalFile){value}; }
static inline _s_7faa13cb_optionalLine _7faa13cb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_optionalLine){value}; }
static inline _s_7faa13cb_optionalUserData _7faa13cb_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7faa13cb_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateProcedure(_s_7faa13cb_context context, _s_7faa13cb_gpu gpu, _s_7faa13cb_handleName handleName, _s_7faa13cb_procedureCache procedureCache, _s_7faa13cb_outputDeclaration outputDeclaration, _s_7faa13cb_procedureParameters procedureParameters, _s_7faa13cb_gpuCodeVertexMainProcedureName gpuCodeVertexMainProcedureName, _s_7faa13cb_gpuCodeVertex gpuCodeVertex, _s_7faa13cb_gpuCodeFragmentMainProcedureName gpuCodeFragmentMainProcedureName, _s_7faa13cb_gpuCodeFragment gpuCodeFragment, _s_7faa13cb_state state, _s_7faa13cb_stateExtension stateExtension, _s_7faa13cb_deriveBase deriveBase, _s_7faa13cb_deriveFrom deriveFrom, _s_7faa13cb_outProcedure outProcedure, _s_7faa13cb_outStatuses outStatuses, _s_7faa13cb_optionalFile optionalFile, _s_7faa13cb_optionalLine optionalLine, _s_7faa13cb_optionalUserData optionalUserData) {
  redCreateProcedure(context.value, gpu.value, handleName.value, procedureCache.value, outputDeclaration.value, procedureParameters.value, gpuCodeVertexMainProcedureName.value, gpuCodeVertex.value, gpuCodeFragmentMainProcedureName.value, gpuCodeFragment.value, state.value, stateExtension.value, deriveBase.value, deriveFrom.value, outProcedure.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateProcedureCompute redCreateProcedureCompute
#define _3ceadcfe_context(value) value
#define _3ceadcfe_gpu(value) value
#define _3ceadcfe_handleName(value) value
#define _3ceadcfe_procedureCache(value) value
#define _3ceadcfe_procedureParameters(value) value
#define _3ceadcfe_gpuCodeMainProcedureName(value) value
#define _3ceadcfe_gpuCode(value) value
#define _3ceadcfe_outProcedure(value) value
#define _3ceadcfe_outStatuses(value) value
#define _3ceadcfe_optionalFile(value) value
#define _3ceadcfe_optionalLine(value) value
#define _3ceadcfe_optionalUserData(value) value
#else
typedef struct _s_3ceadcfe_context { RedContext value; } _s_3ceadcfe_context;
typedef struct _s_3ceadcfe_gpu { RedHandleGpu value; } _s_3ceadcfe_gpu;
typedef struct _s_3ceadcfe_handleName { char* value; } _s_3ceadcfe_handleName;
typedef struct _s_3ceadcfe_procedureCache { RedHandleProcedureCache value; } _s_3ceadcfe_procedureCache;
typedef struct _s_3ceadcfe_procedureParameters { RedHandleProcedureParameters value; } _s_3ceadcfe_procedureParameters;
typedef struct _s_3ceadcfe_gpuCodeMainProcedureName { char* value; } _s_3ceadcfe_gpuCodeMainProcedureName;
typedef struct _s_3ceadcfe_gpuCode { RedHandleGpuCode value; } _s_3ceadcfe_gpuCode;
typedef struct _s_3ceadcfe_outProcedure { RedHandleProcedure* value; } _s_3ceadcfe_outProcedure;
typedef struct _s_3ceadcfe_outStatuses { RedStatuses* value; } _s_3ceadcfe_outStatuses;
typedef struct _s_3ceadcfe_optionalFile { char* value; } _s_3ceadcfe_optionalFile;
typedef struct _s_3ceadcfe_optionalLine { int value; } _s_3ceadcfe_optionalLine;
typedef struct _s_3ceadcfe_optionalUserData { void* value; } _s_3ceadcfe_optionalUserData;
static inline _s_3ceadcfe_context _3ceadcfe_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_3ceadcfe_context){value}; }
static inline _s_3ceadcfe_gpu _3ceadcfe_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_3ceadcfe_gpu){value}; }
static inline _s_3ceadcfe_handleName _3ceadcfe_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3ceadcfe_handleName){value}; }
static inline _s_3ceadcfe_procedureCache _3ceadcfe_procedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_3ceadcfe_procedureCache){value}; }
static inline _s_3ceadcfe_procedureParameters _3ceadcfe_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_3ceadcfe_procedureParameters){value}; }
static inline _s_3ceadcfe_gpuCodeMainProcedureName _3ceadcfe_gpuCodeMainProcedureName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3ceadcfe_gpuCodeMainProcedureName){value}; }
static inline _s_3ceadcfe_gpuCode _3ceadcfe_gpuCode(RedHandleGpuCode value) { return REDGPU_NP_STRUCT_INIT(_s_3ceadcfe_gpuCode){value}; }
static inline _s_3ceadcfe_outProcedure _3ceadcfe_outProcedure(RedHandleProcedure* value) { return REDGPU_NP_STRUCT_INIT(_s_3ceadcfe_outProcedure){value}; }
static inline _s_3ceadcfe_outStatuses _3ceadcfe_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_3ceadcfe_outStatuses){value}; }
static inline _s_3ceadcfe_optionalFile _3ceadcfe_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3ceadcfe_optionalFile){value}; }
static inline _s_3ceadcfe_optionalLine _3ceadcfe_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3ceadcfe_optionalLine){value}; }
static inline _s_3ceadcfe_optionalUserData _3ceadcfe_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3ceadcfe_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateProcedureCompute(_s_3ceadcfe_context context, _s_3ceadcfe_gpu gpu, _s_3ceadcfe_handleName handleName, _s_3ceadcfe_procedureCache procedureCache, _s_3ceadcfe_procedureParameters procedureParameters, _s_3ceadcfe_gpuCodeMainProcedureName gpuCodeMainProcedureName, _s_3ceadcfe_gpuCode gpuCode, _s_3ceadcfe_outProcedure outProcedure, _s_3ceadcfe_outStatuses outStatuses, _s_3ceadcfe_optionalFile optionalFile, _s_3ceadcfe_optionalLine optionalLine, _s_3ceadcfe_optionalUserData optionalUserData) {
  redCreateProcedureCompute(context.value, gpu.value, handleName.value, procedureCache.value, procedureParameters.value, gpuCodeMainProcedureName.value, gpuCode.value, outProcedure.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateOutput redCreateOutput
#define _efb7d1cd_context(value) value
#define _efb7d1cd_gpu(value) value
#define _efb7d1cd_handleName(value) value
#define _efb7d1cd_outputDeclaration(value) value
#define _efb7d1cd_outputMembers(value) value
#define _efb7d1cd_outputMembersResolveTargets(value) value
#define _efb7d1cd_width(value) value
#define _efb7d1cd_height(value) value
#define _efb7d1cd_outOutput(value) value
#define _efb7d1cd_outStatuses(value) value
#define _efb7d1cd_optionalFile(value) value
#define _efb7d1cd_optionalLine(value) value
#define _efb7d1cd_optionalUserData(value) value
#else
typedef struct _s_efb7d1cd_context { RedContext value; } _s_efb7d1cd_context;
typedef struct _s_efb7d1cd_gpu { RedHandleGpu value; } _s_efb7d1cd_gpu;
typedef struct _s_efb7d1cd_handleName { char* value; } _s_efb7d1cd_handleName;
typedef struct _s_efb7d1cd_outputDeclaration { RedHandleOutputDeclaration value; } _s_efb7d1cd_outputDeclaration;
typedef struct _s_efb7d1cd_outputMembers { RedOutputMembers* value; } _s_efb7d1cd_outputMembers;
typedef struct _s_efb7d1cd_outputMembersResolveTargets { RedOutputMembersResolveTargets* value; } _s_efb7d1cd_outputMembersResolveTargets;
typedef struct _s_efb7d1cd_width { unsigned value; } _s_efb7d1cd_width;
typedef struct _s_efb7d1cd_height { unsigned value; } _s_efb7d1cd_height;
typedef struct _s_efb7d1cd_outOutput { RedOutput* value; } _s_efb7d1cd_outOutput;
typedef struct _s_efb7d1cd_outStatuses { RedStatuses* value; } _s_efb7d1cd_outStatuses;
typedef struct _s_efb7d1cd_optionalFile { char* value; } _s_efb7d1cd_optionalFile;
typedef struct _s_efb7d1cd_optionalLine { int value; } _s_efb7d1cd_optionalLine;
typedef struct _s_efb7d1cd_optionalUserData { void* value; } _s_efb7d1cd_optionalUserData;
static inline _s_efb7d1cd_context _efb7d1cd_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_context){value}; }
static inline _s_efb7d1cd_gpu _efb7d1cd_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_gpu){value}; }
static inline _s_efb7d1cd_handleName _efb7d1cd_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_handleName){value}; }
static inline _s_efb7d1cd_outputDeclaration _efb7d1cd_outputDeclaration(RedHandleOutputDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_outputDeclaration){value}; }
static inline _s_efb7d1cd_outputMembers _efb7d1cd_outputMembers(RedOutputMembers* value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_outputMembers){value}; }
static inline _s_efb7d1cd_outputMembersResolveTargets _efb7d1cd_outputMembersResolveTargets(RedOutputMembersResolveTargets* value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_outputMembersResolveTargets){value}; }
static inline _s_efb7d1cd_width _efb7d1cd_width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_width){value}; }
static inline _s_efb7d1cd_height _efb7d1cd_height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_height){value}; }
static inline _s_efb7d1cd_outOutput _efb7d1cd_outOutput(RedOutput* value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_outOutput){value}; }
static inline _s_efb7d1cd_outStatuses _efb7d1cd_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_outStatuses){value}; }
static inline _s_efb7d1cd_optionalFile _efb7d1cd_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_optionalFile){value}; }
static inline _s_efb7d1cd_optionalLine _efb7d1cd_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_optionalLine){value}; }
static inline _s_efb7d1cd_optionalUserData _efb7d1cd_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_efb7d1cd_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateOutput(_s_efb7d1cd_context context, _s_efb7d1cd_gpu gpu, _s_efb7d1cd_handleName handleName, _s_efb7d1cd_outputDeclaration outputDeclaration, _s_efb7d1cd_outputMembers outputMembers, _s_efb7d1cd_outputMembersResolveTargets outputMembersResolveTargets, _s_efb7d1cd_width width, _s_efb7d1cd_height height, _s_efb7d1cd_outOutput outOutput, _s_efb7d1cd_outStatuses outStatuses, _s_efb7d1cd_optionalFile optionalFile, _s_efb7d1cd_optionalLine optionalLine, _s_efb7d1cd_optionalUserData optionalUserData) {
  redCreateOutput(context.value, gpu.value, handleName.value, outputDeclaration.value, outputMembers.value, outputMembersResolveTargets.value, width.value, height.value, outOutput.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateCpuSignal redCreateCpuSignal
#define _fbb1f186_context(value) value
#define _fbb1f186_gpu(value) value
#define _fbb1f186_handleName(value) value
#define _fbb1f186_createSignaled(value) value
#define _fbb1f186_outCpuSignal(value) value
#define _fbb1f186_outStatuses(value) value
#define _fbb1f186_optionalFile(value) value
#define _fbb1f186_optionalLine(value) value
#define _fbb1f186_optionalUserData(value) value
#else
typedef struct _s_fbb1f186_context { RedContext value; } _s_fbb1f186_context;
typedef struct _s_fbb1f186_gpu { RedHandleGpu value; } _s_fbb1f186_gpu;
typedef struct _s_fbb1f186_handleName { char* value; } _s_fbb1f186_handleName;
typedef struct _s_fbb1f186_createSignaled { RedBool32 value; } _s_fbb1f186_createSignaled;
typedef struct _s_fbb1f186_outCpuSignal { RedHandleCpuSignal* value; } _s_fbb1f186_outCpuSignal;
typedef struct _s_fbb1f186_outStatuses { RedStatuses* value; } _s_fbb1f186_outStatuses;
typedef struct _s_fbb1f186_optionalFile { char* value; } _s_fbb1f186_optionalFile;
typedef struct _s_fbb1f186_optionalLine { int value; } _s_fbb1f186_optionalLine;
typedef struct _s_fbb1f186_optionalUserData { void* value; } _s_fbb1f186_optionalUserData;
static inline _s_fbb1f186_context _fbb1f186_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_fbb1f186_context){value}; }
static inline _s_fbb1f186_gpu _fbb1f186_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_fbb1f186_gpu){value}; }
static inline _s_fbb1f186_handleName _fbb1f186_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fbb1f186_handleName){value}; }
static inline _s_fbb1f186_createSignaled _fbb1f186_createSignaled(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_fbb1f186_createSignaled){value}; }
static inline _s_fbb1f186_outCpuSignal _fbb1f186_outCpuSignal(RedHandleCpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_fbb1f186_outCpuSignal){value}; }
static inline _s_fbb1f186_outStatuses _fbb1f186_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_fbb1f186_outStatuses){value}; }
static inline _s_fbb1f186_optionalFile _fbb1f186_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fbb1f186_optionalFile){value}; }
static inline _s_fbb1f186_optionalLine _fbb1f186_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fbb1f186_optionalLine){value}; }
static inline _s_fbb1f186_optionalUserData _fbb1f186_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fbb1f186_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateCpuSignal(_s_fbb1f186_context context, _s_fbb1f186_gpu gpu, _s_fbb1f186_handleName handleName, _s_fbb1f186_createSignaled createSignaled, _s_fbb1f186_outCpuSignal outCpuSignal, _s_fbb1f186_outStatuses outStatuses, _s_fbb1f186_optionalFile optionalFile, _s_fbb1f186_optionalLine optionalLine, _s_fbb1f186_optionalUserData optionalUserData) {
  redCreateCpuSignal(context.value, gpu.value, handleName.value, createSignaled.value, outCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateGpuSignal redCreateGpuSignal
#define _02025cd9_context(value) value
#define _02025cd9_gpu(value) value
#define _02025cd9_handleName(value) value
#define _02025cd9_outGpuSignal(value) value
#define _02025cd9_outStatuses(value) value
#define _02025cd9_optionalFile(value) value
#define _02025cd9_optionalLine(value) value
#define _02025cd9_optionalUserData(value) value
#else
typedef struct _s_02025cd9_context { RedContext value; } _s_02025cd9_context;
typedef struct _s_02025cd9_gpu { RedHandleGpu value; } _s_02025cd9_gpu;
typedef struct _s_02025cd9_handleName { char* value; } _s_02025cd9_handleName;
typedef struct _s_02025cd9_outGpuSignal { RedHandleGpuSignal* value; } _s_02025cd9_outGpuSignal;
typedef struct _s_02025cd9_outStatuses { RedStatuses* value; } _s_02025cd9_outStatuses;
typedef struct _s_02025cd9_optionalFile { char* value; } _s_02025cd9_optionalFile;
typedef struct _s_02025cd9_optionalLine { int value; } _s_02025cd9_optionalLine;
typedef struct _s_02025cd9_optionalUserData { void* value; } _s_02025cd9_optionalUserData;
static inline _s_02025cd9_context _02025cd9_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_02025cd9_context){value}; }
static inline _s_02025cd9_gpu _02025cd9_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_02025cd9_gpu){value}; }
static inline _s_02025cd9_handleName _02025cd9_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_02025cd9_handleName){value}; }
static inline _s_02025cd9_outGpuSignal _02025cd9_outGpuSignal(RedHandleGpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_02025cd9_outGpuSignal){value}; }
static inline _s_02025cd9_outStatuses _02025cd9_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_02025cd9_outStatuses){value}; }
static inline _s_02025cd9_optionalFile _02025cd9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_02025cd9_optionalFile){value}; }
static inline _s_02025cd9_optionalLine _02025cd9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_02025cd9_optionalLine){value}; }
static inline _s_02025cd9_optionalUserData _02025cd9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_02025cd9_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateGpuSignal(_s_02025cd9_context context, _s_02025cd9_gpu gpu, _s_02025cd9_handleName handleName, _s_02025cd9_outGpuSignal outGpuSignal, _s_02025cd9_outStatuses outStatuses, _s_02025cd9_optionalFile optionalFile, _s_02025cd9_optionalLine optionalLine, _s_02025cd9_optionalUserData optionalUserData) {
  redCreateGpuSignal(context.value, gpu.value, handleName.value, outGpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateGpuToCpuSignal redCreateGpuToCpuSignal
#define _9c368246_context(value) value
#define _9c368246_gpu(value) value
#define _9c368246_handleName(value) value
#define _9c368246_outGpuToCpuSignal(value) value
#define _9c368246_outStatuses(value) value
#define _9c368246_optionalFile(value) value
#define _9c368246_optionalLine(value) value
#define _9c368246_optionalUserData(value) value
#else
typedef struct _s_9c368246_context { RedContext value; } _s_9c368246_context;
typedef struct _s_9c368246_gpu { RedHandleGpu value; } _s_9c368246_gpu;
typedef struct _s_9c368246_handleName { char* value; } _s_9c368246_handleName;
typedef struct _s_9c368246_outGpuToCpuSignal { RedHandleGpuToCpuSignal* value; } _s_9c368246_outGpuToCpuSignal;
typedef struct _s_9c368246_outStatuses { RedStatuses* value; } _s_9c368246_outStatuses;
typedef struct _s_9c368246_optionalFile { char* value; } _s_9c368246_optionalFile;
typedef struct _s_9c368246_optionalLine { int value; } _s_9c368246_optionalLine;
typedef struct _s_9c368246_optionalUserData { void* value; } _s_9c368246_optionalUserData;
static inline _s_9c368246_context _9c368246_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_9c368246_context){value}; }
static inline _s_9c368246_gpu _9c368246_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_9c368246_gpu){value}; }
static inline _s_9c368246_handleName _9c368246_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9c368246_handleName){value}; }
static inline _s_9c368246_outGpuToCpuSignal _9c368246_outGpuToCpuSignal(RedHandleGpuToCpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_9c368246_outGpuToCpuSignal){value}; }
static inline _s_9c368246_outStatuses _9c368246_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_9c368246_outStatuses){value}; }
static inline _s_9c368246_optionalFile _9c368246_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9c368246_optionalFile){value}; }
static inline _s_9c368246_optionalLine _9c368246_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9c368246_optionalLine){value}; }
static inline _s_9c368246_optionalUserData _9c368246_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9c368246_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateGpuToCpuSignal(_s_9c368246_context context, _s_9c368246_gpu gpu, _s_9c368246_handleName handleName, _s_9c368246_outGpuToCpuSignal outGpuToCpuSignal, _s_9c368246_outStatuses outStatuses, _s_9c368246_optionalFile optionalFile, _s_9c368246_optionalLine optionalLine, _s_9c368246_optionalUserData optionalUserData) {
  redCreateGpuToCpuSignal(context.value, gpu.value, handleName.value, outGpuToCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateCalls redCreateCalls
#define _10ef1ac1_context(value) value
#define _10ef1ac1_gpu(value) value
#define _10ef1ac1_handleName(value) value
#define _10ef1ac1_queueFamilyIndex(value) value
#define _10ef1ac1_outCalls(value) value
#define _10ef1ac1_outStatuses(value) value
#define _10ef1ac1_optionalFile(value) value
#define _10ef1ac1_optionalLine(value) value
#define _10ef1ac1_optionalUserData(value) value
#else
typedef struct _s_10ef1ac1_context { RedContext value; } _s_10ef1ac1_context;
typedef struct _s_10ef1ac1_gpu { RedHandleGpu value; } _s_10ef1ac1_gpu;
typedef struct _s_10ef1ac1_handleName { char* value; } _s_10ef1ac1_handleName;
typedef struct _s_10ef1ac1_queueFamilyIndex { unsigned value; } _s_10ef1ac1_queueFamilyIndex;
typedef struct _s_10ef1ac1_outCalls { RedCalls* value; } _s_10ef1ac1_outCalls;
typedef struct _s_10ef1ac1_outStatuses { RedStatuses* value; } _s_10ef1ac1_outStatuses;
typedef struct _s_10ef1ac1_optionalFile { char* value; } _s_10ef1ac1_optionalFile;
typedef struct _s_10ef1ac1_optionalLine { int value; } _s_10ef1ac1_optionalLine;
typedef struct _s_10ef1ac1_optionalUserData { void* value; } _s_10ef1ac1_optionalUserData;
static inline _s_10ef1ac1_context _10ef1ac1_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_10ef1ac1_context){value}; }
static inline _s_10ef1ac1_gpu _10ef1ac1_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_10ef1ac1_gpu){value}; }
static inline _s_10ef1ac1_handleName _10ef1ac1_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_10ef1ac1_handleName){value}; }
static inline _s_10ef1ac1_queueFamilyIndex _10ef1ac1_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_10ef1ac1_queueFamilyIndex){value}; }
static inline _s_10ef1ac1_outCalls _10ef1ac1_outCalls(RedCalls* value) { return REDGPU_NP_STRUCT_INIT(_s_10ef1ac1_outCalls){value}; }
static inline _s_10ef1ac1_outStatuses _10ef1ac1_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_10ef1ac1_outStatuses){value}; }
static inline _s_10ef1ac1_optionalFile _10ef1ac1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_10ef1ac1_optionalFile){value}; }
static inline _s_10ef1ac1_optionalLine _10ef1ac1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_10ef1ac1_optionalLine){value}; }
static inline _s_10ef1ac1_optionalUserData _10ef1ac1_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_10ef1ac1_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateCalls(_s_10ef1ac1_context context, _s_10ef1ac1_gpu gpu, _s_10ef1ac1_handleName handleName, _s_10ef1ac1_queueFamilyIndex queueFamilyIndex, _s_10ef1ac1_outCalls outCalls, _s_10ef1ac1_outStatuses outStatuses, _s_10ef1ac1_optionalFile optionalFile, _s_10ef1ac1_optionalLine optionalLine, _s_10ef1ac1_optionalUserData optionalUserData) {
  redCreateCalls(context.value, gpu.value, handleName.value, queueFamilyIndex.value, outCalls.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateCallsReusable redCreateCallsReusable
#define _57249aa9_context(value) value
#define _57249aa9_gpu(value) value
#define _57249aa9_handleName(value) value
#define _57249aa9_queueFamilyIndex(value) value
#define _57249aa9_outCalls(value) value
#define _57249aa9_outStatuses(value) value
#define _57249aa9_optionalFile(value) value
#define _57249aa9_optionalLine(value) value
#define _57249aa9_optionalUserData(value) value
#else
typedef struct _s_57249aa9_context { RedContext value; } _s_57249aa9_context;
typedef struct _s_57249aa9_gpu { RedHandleGpu value; } _s_57249aa9_gpu;
typedef struct _s_57249aa9_handleName { char* value; } _s_57249aa9_handleName;
typedef struct _s_57249aa9_queueFamilyIndex { unsigned value; } _s_57249aa9_queueFamilyIndex;
typedef struct _s_57249aa9_outCalls { RedCalls* value; } _s_57249aa9_outCalls;
typedef struct _s_57249aa9_outStatuses { RedStatuses* value; } _s_57249aa9_outStatuses;
typedef struct _s_57249aa9_optionalFile { char* value; } _s_57249aa9_optionalFile;
typedef struct _s_57249aa9_optionalLine { int value; } _s_57249aa9_optionalLine;
typedef struct _s_57249aa9_optionalUserData { void* value; } _s_57249aa9_optionalUserData;
static inline _s_57249aa9_context _57249aa9_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_57249aa9_context){value}; }
static inline _s_57249aa9_gpu _57249aa9_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_57249aa9_gpu){value}; }
static inline _s_57249aa9_handleName _57249aa9_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_57249aa9_handleName){value}; }
static inline _s_57249aa9_queueFamilyIndex _57249aa9_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_57249aa9_queueFamilyIndex){value}; }
static inline _s_57249aa9_outCalls _57249aa9_outCalls(RedCalls* value) { return REDGPU_NP_STRUCT_INIT(_s_57249aa9_outCalls){value}; }
static inline _s_57249aa9_outStatuses _57249aa9_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_57249aa9_outStatuses){value}; }
static inline _s_57249aa9_optionalFile _57249aa9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_57249aa9_optionalFile){value}; }
static inline _s_57249aa9_optionalLine _57249aa9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_57249aa9_optionalLine){value}; }
static inline _s_57249aa9_optionalUserData _57249aa9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_57249aa9_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateCallsReusable(_s_57249aa9_context context, _s_57249aa9_gpu gpu, _s_57249aa9_handleName handleName, _s_57249aa9_queueFamilyIndex queueFamilyIndex, _s_57249aa9_outCalls outCalls, _s_57249aa9_outStatuses outStatuses, _s_57249aa9_optionalFile optionalFile, _s_57249aa9_optionalLine optionalLine, _s_57249aa9_optionalUserData optionalUserData) {
  redCreateCallsReusable(context.value, gpu.value, handleName.value, queueFamilyIndex.value, outCalls.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyContext redDestroyContext
#define _cab269bf_context(value) value
#define _cab269bf_optionalFile(value) value
#define _cab269bf_optionalLine(value) value
#define _cab269bf_optionalUserData(value) value
#else
typedef struct _s_cab269bf_context { RedContext value; } _s_cab269bf_context;
typedef struct _s_cab269bf_optionalFile { char* value; } _s_cab269bf_optionalFile;
typedef struct _s_cab269bf_optionalLine { int value; } _s_cab269bf_optionalLine;
typedef struct _s_cab269bf_optionalUserData { void* value; } _s_cab269bf_optionalUserData;
static inline _s_cab269bf_context _cab269bf_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_cab269bf_context){value}; }
static inline _s_cab269bf_optionalFile _cab269bf_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cab269bf_optionalFile){value}; }
static inline _s_cab269bf_optionalLine _cab269bf_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cab269bf_optionalLine){value}; }
static inline _s_cab269bf_optionalUserData _cab269bf_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cab269bf_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyContext(_s_cab269bf_context context, _s_cab269bf_optionalFile optionalFile, _s_cab269bf_optionalLine optionalLine, _s_cab269bf_optionalUserData optionalUserData) {
  redDestroyContext(context.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyArray redDestroyArray
#define _5e5d0a32_context(value) value
#define _5e5d0a32_gpu(value) value
#define _5e5d0a32_array(value) value
#define _5e5d0a32_optionalFile(value) value
#define _5e5d0a32_optionalLine(value) value
#define _5e5d0a32_optionalUserData(value) value
#else
typedef struct _s_5e5d0a32_context { RedContext value; } _s_5e5d0a32_context;
typedef struct _s_5e5d0a32_gpu { RedHandleGpu value; } _s_5e5d0a32_gpu;
typedef struct _s_5e5d0a32_array { RedHandleArray value; } _s_5e5d0a32_array;
typedef struct _s_5e5d0a32_optionalFile { char* value; } _s_5e5d0a32_optionalFile;
typedef struct _s_5e5d0a32_optionalLine { int value; } _s_5e5d0a32_optionalLine;
typedef struct _s_5e5d0a32_optionalUserData { void* value; } _s_5e5d0a32_optionalUserData;
static inline _s_5e5d0a32_context _5e5d0a32_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_5e5d0a32_context){value}; }
static inline _s_5e5d0a32_gpu _5e5d0a32_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_5e5d0a32_gpu){value}; }
static inline _s_5e5d0a32_array _5e5d0a32_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_5e5d0a32_array){value}; }
static inline _s_5e5d0a32_optionalFile _5e5d0a32_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5e5d0a32_optionalFile){value}; }
static inline _s_5e5d0a32_optionalLine _5e5d0a32_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5e5d0a32_optionalLine){value}; }
static inline _s_5e5d0a32_optionalUserData _5e5d0a32_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5e5d0a32_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyArray(_s_5e5d0a32_context context, _s_5e5d0a32_gpu gpu, _s_5e5d0a32_array array, _s_5e5d0a32_optionalFile optionalFile, _s_5e5d0a32_optionalLine optionalLine, _s_5e5d0a32_optionalUserData optionalUserData) {
  redDestroyArray(context.value, gpu.value, array.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyImage redDestroyImage
#define _a11bbdc0_context(value) value
#define _a11bbdc0_gpu(value) value
#define _a11bbdc0_image(value) value
#define _a11bbdc0_optionalFile(value) value
#define _a11bbdc0_optionalLine(value) value
#define _a11bbdc0_optionalUserData(value) value
#else
typedef struct _s_a11bbdc0_context { RedContext value; } _s_a11bbdc0_context;
typedef struct _s_a11bbdc0_gpu { RedHandleGpu value; } _s_a11bbdc0_gpu;
typedef struct _s_a11bbdc0_image { RedHandleImage value; } _s_a11bbdc0_image;
typedef struct _s_a11bbdc0_optionalFile { char* value; } _s_a11bbdc0_optionalFile;
typedef struct _s_a11bbdc0_optionalLine { int value; } _s_a11bbdc0_optionalLine;
typedef struct _s_a11bbdc0_optionalUserData { void* value; } _s_a11bbdc0_optionalUserData;
static inline _s_a11bbdc0_context _a11bbdc0_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_a11bbdc0_context){value}; }
static inline _s_a11bbdc0_gpu _a11bbdc0_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_a11bbdc0_gpu){value}; }
static inline _s_a11bbdc0_image _a11bbdc0_image(RedHandleImage value) { return REDGPU_NP_STRUCT_INIT(_s_a11bbdc0_image){value}; }
static inline _s_a11bbdc0_optionalFile _a11bbdc0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a11bbdc0_optionalFile){value}; }
static inline _s_a11bbdc0_optionalLine _a11bbdc0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a11bbdc0_optionalLine){value}; }
static inline _s_a11bbdc0_optionalUserData _a11bbdc0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a11bbdc0_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyImage(_s_a11bbdc0_context context, _s_a11bbdc0_gpu gpu, _s_a11bbdc0_image image, _s_a11bbdc0_optionalFile optionalFile, _s_a11bbdc0_optionalLine optionalLine, _s_a11bbdc0_optionalUserData optionalUserData) {
  redDestroyImage(context.value, gpu.value, image.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroySampler redDestroySampler
#define _4e4d8e75_context(value) value
#define _4e4d8e75_gpu(value) value
#define _4e4d8e75_sampler(value) value
#define _4e4d8e75_optionalFile(value) value
#define _4e4d8e75_optionalLine(value) value
#define _4e4d8e75_optionalUserData(value) value
#else
typedef struct _s_4e4d8e75_context { RedContext value; } _s_4e4d8e75_context;
typedef struct _s_4e4d8e75_gpu { RedHandleGpu value; } _s_4e4d8e75_gpu;
typedef struct _s_4e4d8e75_sampler { RedHandleSampler value; } _s_4e4d8e75_sampler;
typedef struct _s_4e4d8e75_optionalFile { char* value; } _s_4e4d8e75_optionalFile;
typedef struct _s_4e4d8e75_optionalLine { int value; } _s_4e4d8e75_optionalLine;
typedef struct _s_4e4d8e75_optionalUserData { void* value; } _s_4e4d8e75_optionalUserData;
static inline _s_4e4d8e75_context _4e4d8e75_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_4e4d8e75_context){value}; }
static inline _s_4e4d8e75_gpu _4e4d8e75_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_4e4d8e75_gpu){value}; }
static inline _s_4e4d8e75_sampler _4e4d8e75_sampler(RedHandleSampler value) { return REDGPU_NP_STRUCT_INIT(_s_4e4d8e75_sampler){value}; }
static inline _s_4e4d8e75_optionalFile _4e4d8e75_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4e4d8e75_optionalFile){value}; }
static inline _s_4e4d8e75_optionalLine _4e4d8e75_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4e4d8e75_optionalLine){value}; }
static inline _s_4e4d8e75_optionalUserData _4e4d8e75_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4e4d8e75_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroySampler(_s_4e4d8e75_context context, _s_4e4d8e75_gpu gpu, _s_4e4d8e75_sampler sampler, _s_4e4d8e75_optionalFile optionalFile, _s_4e4d8e75_optionalLine optionalLine, _s_4e4d8e75_optionalUserData optionalUserData) {
  redDestroySampler(context.value, gpu.value, sampler.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyTexture redDestroyTexture
#define _827fb2e0_context(value) value
#define _827fb2e0_gpu(value) value
#define _827fb2e0_texture(value) value
#define _827fb2e0_optionalFile(value) value
#define _827fb2e0_optionalLine(value) value
#define _827fb2e0_optionalUserData(value) value
#else
typedef struct _s_827fb2e0_context { RedContext value; } _s_827fb2e0_context;
typedef struct _s_827fb2e0_gpu { RedHandleGpu value; } _s_827fb2e0_gpu;
typedef struct _s_827fb2e0_texture { RedHandleTexture value; } _s_827fb2e0_texture;
typedef struct _s_827fb2e0_optionalFile { char* value; } _s_827fb2e0_optionalFile;
typedef struct _s_827fb2e0_optionalLine { int value; } _s_827fb2e0_optionalLine;
typedef struct _s_827fb2e0_optionalUserData { void* value; } _s_827fb2e0_optionalUserData;
static inline _s_827fb2e0_context _827fb2e0_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_827fb2e0_context){value}; }
static inline _s_827fb2e0_gpu _827fb2e0_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_827fb2e0_gpu){value}; }
static inline _s_827fb2e0_texture _827fb2e0_texture(RedHandleTexture value) { return REDGPU_NP_STRUCT_INIT(_s_827fb2e0_texture){value}; }
static inline _s_827fb2e0_optionalFile _827fb2e0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_827fb2e0_optionalFile){value}; }
static inline _s_827fb2e0_optionalLine _827fb2e0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_827fb2e0_optionalLine){value}; }
static inline _s_827fb2e0_optionalUserData _827fb2e0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_827fb2e0_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyTexture(_s_827fb2e0_context context, _s_827fb2e0_gpu gpu, _s_827fb2e0_texture texture, _s_827fb2e0_optionalFile optionalFile, _s_827fb2e0_optionalLine optionalLine, _s_827fb2e0_optionalUserData optionalUserData) {
  redDestroyTexture(context.value, gpu.value, texture.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyGpuCode redDestroyGpuCode
#define _04d0e128_context(value) value
#define _04d0e128_gpu(value) value
#define _04d0e128_gpuCode(value) value
#define _04d0e128_optionalFile(value) value
#define _04d0e128_optionalLine(value) value
#define _04d0e128_optionalUserData(value) value
#else
typedef struct _s_04d0e128_context { RedContext value; } _s_04d0e128_context;
typedef struct _s_04d0e128_gpu { RedHandleGpu value; } _s_04d0e128_gpu;
typedef struct _s_04d0e128_gpuCode { RedHandleGpuCode value; } _s_04d0e128_gpuCode;
typedef struct _s_04d0e128_optionalFile { char* value; } _s_04d0e128_optionalFile;
typedef struct _s_04d0e128_optionalLine { int value; } _s_04d0e128_optionalLine;
typedef struct _s_04d0e128_optionalUserData { void* value; } _s_04d0e128_optionalUserData;
static inline _s_04d0e128_context _04d0e128_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_04d0e128_context){value}; }
static inline _s_04d0e128_gpu _04d0e128_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_04d0e128_gpu){value}; }
static inline _s_04d0e128_gpuCode _04d0e128_gpuCode(RedHandleGpuCode value) { return REDGPU_NP_STRUCT_INIT(_s_04d0e128_gpuCode){value}; }
static inline _s_04d0e128_optionalFile _04d0e128_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_04d0e128_optionalFile){value}; }
static inline _s_04d0e128_optionalLine _04d0e128_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_04d0e128_optionalLine){value}; }
static inline _s_04d0e128_optionalUserData _04d0e128_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_04d0e128_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyGpuCode(_s_04d0e128_context context, _s_04d0e128_gpu gpu, _s_04d0e128_gpuCode gpuCode, _s_04d0e128_optionalFile optionalFile, _s_04d0e128_optionalLine optionalLine, _s_04d0e128_optionalUserData optionalUserData) {
  redDestroyGpuCode(context.value, gpu.value, gpuCode.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyOutputDeclaration redDestroyOutputDeclaration
#define _233e00e5_context(value) value
#define _233e00e5_gpu(value) value
#define _233e00e5_outputDeclaration(value) value
#define _233e00e5_optionalFile(value) value
#define _233e00e5_optionalLine(value) value
#define _233e00e5_optionalUserData(value) value
#else
typedef struct _s_233e00e5_context { RedContext value; } _s_233e00e5_context;
typedef struct _s_233e00e5_gpu { RedHandleGpu value; } _s_233e00e5_gpu;
typedef struct _s_233e00e5_outputDeclaration { RedHandleOutputDeclaration value; } _s_233e00e5_outputDeclaration;
typedef struct _s_233e00e5_optionalFile { char* value; } _s_233e00e5_optionalFile;
typedef struct _s_233e00e5_optionalLine { int value; } _s_233e00e5_optionalLine;
typedef struct _s_233e00e5_optionalUserData { void* value; } _s_233e00e5_optionalUserData;
static inline _s_233e00e5_context _233e00e5_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_233e00e5_context){value}; }
static inline _s_233e00e5_gpu _233e00e5_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_233e00e5_gpu){value}; }
static inline _s_233e00e5_outputDeclaration _233e00e5_outputDeclaration(RedHandleOutputDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_233e00e5_outputDeclaration){value}; }
static inline _s_233e00e5_optionalFile _233e00e5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_233e00e5_optionalFile){value}; }
static inline _s_233e00e5_optionalLine _233e00e5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_233e00e5_optionalLine){value}; }
static inline _s_233e00e5_optionalUserData _233e00e5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_233e00e5_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyOutputDeclaration(_s_233e00e5_context context, _s_233e00e5_gpu gpu, _s_233e00e5_outputDeclaration outputDeclaration, _s_233e00e5_optionalFile optionalFile, _s_233e00e5_optionalLine optionalLine, _s_233e00e5_optionalUserData optionalUserData) {
  redDestroyOutputDeclaration(context.value, gpu.value, outputDeclaration.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyStructDeclaration redDestroyStructDeclaration
#define _e32719ca_context(value) value
#define _e32719ca_gpu(value) value
#define _e32719ca_structDeclaration(value) value
#define _e32719ca_optionalFile(value) value
#define _e32719ca_optionalLine(value) value
#define _e32719ca_optionalUserData(value) value
#else
typedef struct _s_e32719ca_context { RedContext value; } _s_e32719ca_context;
typedef struct _s_e32719ca_gpu { RedHandleGpu value; } _s_e32719ca_gpu;
typedef struct _s_e32719ca_structDeclaration { RedHandleStructDeclaration value; } _s_e32719ca_structDeclaration;
typedef struct _s_e32719ca_optionalFile { char* value; } _s_e32719ca_optionalFile;
typedef struct _s_e32719ca_optionalLine { int value; } _s_e32719ca_optionalLine;
typedef struct _s_e32719ca_optionalUserData { void* value; } _s_e32719ca_optionalUserData;
static inline _s_e32719ca_context _e32719ca_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_e32719ca_context){value}; }
static inline _s_e32719ca_gpu _e32719ca_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_e32719ca_gpu){value}; }
static inline _s_e32719ca_structDeclaration _e32719ca_structDeclaration(RedHandleStructDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_e32719ca_structDeclaration){value}; }
static inline _s_e32719ca_optionalFile _e32719ca_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e32719ca_optionalFile){value}; }
static inline _s_e32719ca_optionalLine _e32719ca_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e32719ca_optionalLine){value}; }
static inline _s_e32719ca_optionalUserData _e32719ca_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e32719ca_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyStructDeclaration(_s_e32719ca_context context, _s_e32719ca_gpu gpu, _s_e32719ca_structDeclaration structDeclaration, _s_e32719ca_optionalFile optionalFile, _s_e32719ca_optionalLine optionalLine, _s_e32719ca_optionalUserData optionalUserData) {
  redDestroyStructDeclaration(context.value, gpu.value, structDeclaration.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyProcedureParameters redDestroyProcedureParameters
#define _c3975785_context(value) value
#define _c3975785_gpu(value) value
#define _c3975785_procedureParameters(value) value
#define _c3975785_optionalFile(value) value
#define _c3975785_optionalLine(value) value
#define _c3975785_optionalUserData(value) value
#else
typedef struct _s_c3975785_context { RedContext value; } _s_c3975785_context;
typedef struct _s_c3975785_gpu { RedHandleGpu value; } _s_c3975785_gpu;
typedef struct _s_c3975785_procedureParameters { RedHandleProcedureParameters value; } _s_c3975785_procedureParameters;
typedef struct _s_c3975785_optionalFile { char* value; } _s_c3975785_optionalFile;
typedef struct _s_c3975785_optionalLine { int value; } _s_c3975785_optionalLine;
typedef struct _s_c3975785_optionalUserData { void* value; } _s_c3975785_optionalUserData;
static inline _s_c3975785_context _c3975785_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_c3975785_context){value}; }
static inline _s_c3975785_gpu _c3975785_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_c3975785_gpu){value}; }
static inline _s_c3975785_procedureParameters _c3975785_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_c3975785_procedureParameters){value}; }
static inline _s_c3975785_optionalFile _c3975785_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c3975785_optionalFile){value}; }
static inline _s_c3975785_optionalLine _c3975785_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c3975785_optionalLine){value}; }
static inline _s_c3975785_optionalUserData _c3975785_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c3975785_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyProcedureParameters(_s_c3975785_context context, _s_c3975785_gpu gpu, _s_c3975785_procedureParameters procedureParameters, _s_c3975785_optionalFile optionalFile, _s_c3975785_optionalLine optionalLine, _s_c3975785_optionalUserData optionalUserData) {
  redDestroyProcedureParameters(context.value, gpu.value, procedureParameters.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyProcedureCache redDestroyProcedureCache
#define _b5596819_context(value) value
#define _b5596819_gpu(value) value
#define _b5596819_procedureCache(value) value
#define _b5596819_optionalFile(value) value
#define _b5596819_optionalLine(value) value
#define _b5596819_optionalUserData(value) value
#else
typedef struct _s_b5596819_context { RedContext value; } _s_b5596819_context;
typedef struct _s_b5596819_gpu { RedHandleGpu value; } _s_b5596819_gpu;
typedef struct _s_b5596819_procedureCache { RedHandleProcedureCache value; } _s_b5596819_procedureCache;
typedef struct _s_b5596819_optionalFile { char* value; } _s_b5596819_optionalFile;
typedef struct _s_b5596819_optionalLine { int value; } _s_b5596819_optionalLine;
typedef struct _s_b5596819_optionalUserData { void* value; } _s_b5596819_optionalUserData;
static inline _s_b5596819_context _b5596819_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b5596819_context){value}; }
static inline _s_b5596819_gpu _b5596819_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b5596819_gpu){value}; }
static inline _s_b5596819_procedureCache _b5596819_procedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_b5596819_procedureCache){value}; }
static inline _s_b5596819_optionalFile _b5596819_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b5596819_optionalFile){value}; }
static inline _s_b5596819_optionalLine _b5596819_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b5596819_optionalLine){value}; }
static inline _s_b5596819_optionalUserData _b5596819_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b5596819_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyProcedureCache(_s_b5596819_context context, _s_b5596819_gpu gpu, _s_b5596819_procedureCache procedureCache, _s_b5596819_optionalFile optionalFile, _s_b5596819_optionalLine optionalLine, _s_b5596819_optionalUserData optionalUserData) {
  redDestroyProcedureCache(context.value, gpu.value, procedureCache.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyProcedure redDestroyProcedure
#define _b57c5513_context(value) value
#define _b57c5513_gpu(value) value
#define _b57c5513_procedure(value) value
#define _b57c5513_optionalFile(value) value
#define _b57c5513_optionalLine(value) value
#define _b57c5513_optionalUserData(value) value
#else
typedef struct _s_b57c5513_context { RedContext value; } _s_b57c5513_context;
typedef struct _s_b57c5513_gpu { RedHandleGpu value; } _s_b57c5513_gpu;
typedef struct _s_b57c5513_procedure { RedHandleProcedure value; } _s_b57c5513_procedure;
typedef struct _s_b57c5513_optionalFile { char* value; } _s_b57c5513_optionalFile;
typedef struct _s_b57c5513_optionalLine { int value; } _s_b57c5513_optionalLine;
typedef struct _s_b57c5513_optionalUserData { void* value; } _s_b57c5513_optionalUserData;
static inline _s_b57c5513_context _b57c5513_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b57c5513_context){value}; }
static inline _s_b57c5513_gpu _b57c5513_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b57c5513_gpu){value}; }
static inline _s_b57c5513_procedure _b57c5513_procedure(RedHandleProcedure value) { return REDGPU_NP_STRUCT_INIT(_s_b57c5513_procedure){value}; }
static inline _s_b57c5513_optionalFile _b57c5513_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b57c5513_optionalFile){value}; }
static inline _s_b57c5513_optionalLine _b57c5513_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b57c5513_optionalLine){value}; }
static inline _s_b57c5513_optionalUserData _b57c5513_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b57c5513_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyProcedure(_s_b57c5513_context context, _s_b57c5513_gpu gpu, _s_b57c5513_procedure procedure, _s_b57c5513_optionalFile optionalFile, _s_b57c5513_optionalLine optionalLine, _s_b57c5513_optionalUserData optionalUserData) {
  redDestroyProcedure(context.value, gpu.value, procedure.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyOutput redDestroyOutput
#define _83aad649_context(value) value
#define _83aad649_gpu(value) value
#define _83aad649_output(value) value
#define _83aad649_optionalFile(value) value
#define _83aad649_optionalLine(value) value
#define _83aad649_optionalUserData(value) value
#else
typedef struct _s_83aad649_context { RedContext value; } _s_83aad649_context;
typedef struct _s_83aad649_gpu { RedHandleGpu value; } _s_83aad649_gpu;
typedef struct _s_83aad649_output { RedHandleOutput value; } _s_83aad649_output;
typedef struct _s_83aad649_optionalFile { char* value; } _s_83aad649_optionalFile;
typedef struct _s_83aad649_optionalLine { int value; } _s_83aad649_optionalLine;
typedef struct _s_83aad649_optionalUserData { void* value; } _s_83aad649_optionalUserData;
static inline _s_83aad649_context _83aad649_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_83aad649_context){value}; }
static inline _s_83aad649_gpu _83aad649_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_83aad649_gpu){value}; }
static inline _s_83aad649_output _83aad649_output(RedHandleOutput value) { return REDGPU_NP_STRUCT_INIT(_s_83aad649_output){value}; }
static inline _s_83aad649_optionalFile _83aad649_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_83aad649_optionalFile){value}; }
static inline _s_83aad649_optionalLine _83aad649_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_83aad649_optionalLine){value}; }
static inline _s_83aad649_optionalUserData _83aad649_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_83aad649_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyOutput(_s_83aad649_context context, _s_83aad649_gpu gpu, _s_83aad649_output output, _s_83aad649_optionalFile optionalFile, _s_83aad649_optionalLine optionalLine, _s_83aad649_optionalUserData optionalUserData) {
  redDestroyOutput(context.value, gpu.value, output.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyCpuSignal redDestroyCpuSignal
#define _9d0e4830_context(value) value
#define _9d0e4830_gpu(value) value
#define _9d0e4830_cpuSignal(value) value
#define _9d0e4830_optionalFile(value) value
#define _9d0e4830_optionalLine(value) value
#define _9d0e4830_optionalUserData(value) value
#else
typedef struct _s_9d0e4830_context { RedContext value; } _s_9d0e4830_context;
typedef struct _s_9d0e4830_gpu { RedHandleGpu value; } _s_9d0e4830_gpu;
typedef struct _s_9d0e4830_cpuSignal { RedHandleCpuSignal value; } _s_9d0e4830_cpuSignal;
typedef struct _s_9d0e4830_optionalFile { char* value; } _s_9d0e4830_optionalFile;
typedef struct _s_9d0e4830_optionalLine { int value; } _s_9d0e4830_optionalLine;
typedef struct _s_9d0e4830_optionalUserData { void* value; } _s_9d0e4830_optionalUserData;
static inline _s_9d0e4830_context _9d0e4830_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_9d0e4830_context){value}; }
static inline _s_9d0e4830_gpu _9d0e4830_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_9d0e4830_gpu){value}; }
static inline _s_9d0e4830_cpuSignal _9d0e4830_cpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_9d0e4830_cpuSignal){value}; }
static inline _s_9d0e4830_optionalFile _9d0e4830_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9d0e4830_optionalFile){value}; }
static inline _s_9d0e4830_optionalLine _9d0e4830_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9d0e4830_optionalLine){value}; }
static inline _s_9d0e4830_optionalUserData _9d0e4830_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9d0e4830_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyCpuSignal(_s_9d0e4830_context context, _s_9d0e4830_gpu gpu, _s_9d0e4830_cpuSignal cpuSignal, _s_9d0e4830_optionalFile optionalFile, _s_9d0e4830_optionalLine optionalLine, _s_9d0e4830_optionalUserData optionalUserData) {
  redDestroyCpuSignal(context.value, gpu.value, cpuSignal.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyGpuSignal redDestroyGpuSignal
#define _e9941bdc_context(value) value
#define _e9941bdc_gpu(value) value
#define _e9941bdc_gpuSignal(value) value
#define _e9941bdc_optionalFile(value) value
#define _e9941bdc_optionalLine(value) value
#define _e9941bdc_optionalUserData(value) value
#else
typedef struct _s_e9941bdc_context { RedContext value; } _s_e9941bdc_context;
typedef struct _s_e9941bdc_gpu { RedHandleGpu value; } _s_e9941bdc_gpu;
typedef struct _s_e9941bdc_gpuSignal { RedHandleGpuSignal value; } _s_e9941bdc_gpuSignal;
typedef struct _s_e9941bdc_optionalFile { char* value; } _s_e9941bdc_optionalFile;
typedef struct _s_e9941bdc_optionalLine { int value; } _s_e9941bdc_optionalLine;
typedef struct _s_e9941bdc_optionalUserData { void* value; } _s_e9941bdc_optionalUserData;
static inline _s_e9941bdc_context _e9941bdc_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_e9941bdc_context){value}; }
static inline _s_e9941bdc_gpu _e9941bdc_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_e9941bdc_gpu){value}; }
static inline _s_e9941bdc_gpuSignal _e9941bdc_gpuSignal(RedHandleGpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_e9941bdc_gpuSignal){value}; }
static inline _s_e9941bdc_optionalFile _e9941bdc_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e9941bdc_optionalFile){value}; }
static inline _s_e9941bdc_optionalLine _e9941bdc_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e9941bdc_optionalLine){value}; }
static inline _s_e9941bdc_optionalUserData _e9941bdc_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e9941bdc_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyGpuSignal(_s_e9941bdc_context context, _s_e9941bdc_gpu gpu, _s_e9941bdc_gpuSignal gpuSignal, _s_e9941bdc_optionalFile optionalFile, _s_e9941bdc_optionalLine optionalLine, _s_e9941bdc_optionalUserData optionalUserData) {
  redDestroyGpuSignal(context.value, gpu.value, gpuSignal.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyGpuToCpuSignal redDestroyGpuToCpuSignal
#define _0485a982_context(value) value
#define _0485a982_gpu(value) value
#define _0485a982_gpuToCpuSignal(value) value
#define _0485a982_optionalFile(value) value
#define _0485a982_optionalLine(value) value
#define _0485a982_optionalUserData(value) value
#else
typedef struct _s_0485a982_context { RedContext value; } _s_0485a982_context;
typedef struct _s_0485a982_gpu { RedHandleGpu value; } _s_0485a982_gpu;
typedef struct _s_0485a982_gpuToCpuSignal { RedHandleGpuToCpuSignal value; } _s_0485a982_gpuToCpuSignal;
typedef struct _s_0485a982_optionalFile { char* value; } _s_0485a982_optionalFile;
typedef struct _s_0485a982_optionalLine { int value; } _s_0485a982_optionalLine;
typedef struct _s_0485a982_optionalUserData { void* value; } _s_0485a982_optionalUserData;
static inline _s_0485a982_context _0485a982_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_0485a982_context){value}; }
static inline _s_0485a982_gpu _0485a982_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_0485a982_gpu){value}; }
static inline _s_0485a982_gpuToCpuSignal _0485a982_gpuToCpuSignal(RedHandleGpuToCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_0485a982_gpuToCpuSignal){value}; }
static inline _s_0485a982_optionalFile _0485a982_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0485a982_optionalFile){value}; }
static inline _s_0485a982_optionalLine _0485a982_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0485a982_optionalLine){value}; }
static inline _s_0485a982_optionalUserData _0485a982_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0485a982_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyGpuToCpuSignal(_s_0485a982_context context, _s_0485a982_gpu gpu, _s_0485a982_gpuToCpuSignal gpuToCpuSignal, _s_0485a982_optionalFile optionalFile, _s_0485a982_optionalLine optionalLine, _s_0485a982_optionalUserData optionalUserData) {
  redDestroyGpuToCpuSignal(context.value, gpu.value, gpuToCpuSignal.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyCalls redDestroyCalls
#define _d3ca9033_context(value) value
#define _d3ca9033_gpu(value) value
#define _d3ca9033_calls(value) value
#define _d3ca9033_callsMemory(value) value
#define _d3ca9033_optionalFile(value) value
#define _d3ca9033_optionalLine(value) value
#define _d3ca9033_optionalUserData(value) value
#else
typedef struct _s_d3ca9033_context { RedContext value; } _s_d3ca9033_context;
typedef struct _s_d3ca9033_gpu { RedHandleGpu value; } _s_d3ca9033_gpu;
typedef struct _s_d3ca9033_calls { RedHandleCalls value; } _s_d3ca9033_calls;
typedef struct _s_d3ca9033_callsMemory { RedHandleCallsMemory value; } _s_d3ca9033_callsMemory;
typedef struct _s_d3ca9033_optionalFile { char* value; } _s_d3ca9033_optionalFile;
typedef struct _s_d3ca9033_optionalLine { int value; } _s_d3ca9033_optionalLine;
typedef struct _s_d3ca9033_optionalUserData { void* value; } _s_d3ca9033_optionalUserData;
static inline _s_d3ca9033_context _d3ca9033_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_d3ca9033_context){value}; }
static inline _s_d3ca9033_gpu _d3ca9033_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_d3ca9033_gpu){value}; }
static inline _s_d3ca9033_calls _d3ca9033_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_d3ca9033_calls){value}; }
static inline _s_d3ca9033_callsMemory _d3ca9033_callsMemory(RedHandleCallsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_d3ca9033_callsMemory){value}; }
static inline _s_d3ca9033_optionalFile _d3ca9033_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d3ca9033_optionalFile){value}; }
static inline _s_d3ca9033_optionalLine _d3ca9033_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d3ca9033_optionalLine){value}; }
static inline _s_d3ca9033_optionalUserData _d3ca9033_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d3ca9033_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyCalls(_s_d3ca9033_context context, _s_d3ca9033_gpu gpu, _s_d3ca9033_calls calls, _s_d3ca9033_callsMemory callsMemory, _s_d3ca9033_optionalFile optionalFile, _s_d3ca9033_optionalLine optionalLine, _s_d3ca9033_optionalUserData optionalUserData) {
  redDestroyCalls(context.value, gpu.value, calls.value, callsMemory.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redProcedureCacheGetBlob redProcedureCacheGetBlob
#define _d312c52a_context(value) value
#define _d312c52a_gpu(value) value
#define _d312c52a_procedureCache(value) value
#define _d312c52a_outBlobBytesCount(value) value
#define _d312c52a_outBlob(value) value
#define _d312c52a_outStatuses(value) value
#define _d312c52a_optionalFile(value) value
#define _d312c52a_optionalLine(value) value
#define _d312c52a_optionalUserData(value) value
#else
typedef struct _s_d312c52a_context { RedContext value; } _s_d312c52a_context;
typedef struct _s_d312c52a_gpu { RedHandleGpu value; } _s_d312c52a_gpu;
typedef struct _s_d312c52a_procedureCache { RedHandleProcedureCache value; } _s_d312c52a_procedureCache;
typedef struct _s_d312c52a_outBlobBytesCount { uint64_t* value; } _s_d312c52a_outBlobBytesCount;
typedef struct _s_d312c52a_outBlob { void* value; } _s_d312c52a_outBlob;
typedef struct _s_d312c52a_outStatuses { RedStatuses* value; } _s_d312c52a_outStatuses;
typedef struct _s_d312c52a_optionalFile { char* value; } _s_d312c52a_optionalFile;
typedef struct _s_d312c52a_optionalLine { int value; } _s_d312c52a_optionalLine;
typedef struct _s_d312c52a_optionalUserData { void* value; } _s_d312c52a_optionalUserData;
static inline _s_d312c52a_context _d312c52a_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_d312c52a_context){value}; }
static inline _s_d312c52a_gpu _d312c52a_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_d312c52a_gpu){value}; }
static inline _s_d312c52a_procedureCache _d312c52a_procedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_d312c52a_procedureCache){value}; }
static inline _s_d312c52a_outBlobBytesCount _d312c52a_outBlobBytesCount(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_d312c52a_outBlobBytesCount){value}; }
static inline _s_d312c52a_outBlob _d312c52a_outBlob(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d312c52a_outBlob){value}; }
static inline _s_d312c52a_outStatuses _d312c52a_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_d312c52a_outStatuses){value}; }
static inline _s_d312c52a_optionalFile _d312c52a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d312c52a_optionalFile){value}; }
static inline _s_d312c52a_optionalLine _d312c52a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d312c52a_optionalLine){value}; }
static inline _s_d312c52a_optionalUserData _d312c52a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d312c52a_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redProcedureCacheGetBlob(_s_d312c52a_context context, _s_d312c52a_gpu gpu, _s_d312c52a_procedureCache procedureCache, _s_d312c52a_outBlobBytesCount outBlobBytesCount, _s_d312c52a_outBlob outBlob, _s_d312c52a_outStatuses outStatuses, _s_d312c52a_optionalFile optionalFile, _s_d312c52a_optionalLine optionalLine, _s_d312c52a_optionalUserData optionalUserData) {
  redProcedureCacheGetBlob(context.value, gpu.value, procedureCache.value, outBlobBytesCount.value, outBlob.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redProcedureCacheMergeCaches redProcedureCacheMergeCaches
#define _ebef6cb6_context(value) value
#define _ebef6cb6_gpu(value) value
#define _ebef6cb6_sourceProcedureCachesCount(value) value
#define _ebef6cb6_sourceProcedureCaches(value) value
#define _ebef6cb6_targetProcedureCache(value) value
#define _ebef6cb6_outStatuses(value) value
#define _ebef6cb6_optionalFile(value) value
#define _ebef6cb6_optionalLine(value) value
#define _ebef6cb6_optionalUserData(value) value
#else
typedef struct _s_ebef6cb6_context { RedContext value; } _s_ebef6cb6_context;
typedef struct _s_ebef6cb6_gpu { RedHandleGpu value; } _s_ebef6cb6_gpu;
typedef struct _s_ebef6cb6_sourceProcedureCachesCount { unsigned value; } _s_ebef6cb6_sourceProcedureCachesCount;
typedef struct _s_ebef6cb6_sourceProcedureCaches { RedHandleProcedureCache* value; } _s_ebef6cb6_sourceProcedureCaches;
typedef struct _s_ebef6cb6_targetProcedureCache { RedHandleProcedureCache value; } _s_ebef6cb6_targetProcedureCache;
typedef struct _s_ebef6cb6_outStatuses { RedStatuses* value; } _s_ebef6cb6_outStatuses;
typedef struct _s_ebef6cb6_optionalFile { char* value; } _s_ebef6cb6_optionalFile;
typedef struct _s_ebef6cb6_optionalLine { int value; } _s_ebef6cb6_optionalLine;
typedef struct _s_ebef6cb6_optionalUserData { void* value; } _s_ebef6cb6_optionalUserData;
static inline _s_ebef6cb6_context _ebef6cb6_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_ebef6cb6_context){value}; }
static inline _s_ebef6cb6_gpu _ebef6cb6_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_ebef6cb6_gpu){value}; }
static inline _s_ebef6cb6_sourceProcedureCachesCount _ebef6cb6_sourceProcedureCachesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ebef6cb6_sourceProcedureCachesCount){value}; }
static inline _s_ebef6cb6_sourceProcedureCaches _ebef6cb6_sourceProcedureCaches(RedHandleProcedureCache* value) { return REDGPU_NP_STRUCT_INIT(_s_ebef6cb6_sourceProcedureCaches){value}; }
static inline _s_ebef6cb6_targetProcedureCache _ebef6cb6_targetProcedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_ebef6cb6_targetProcedureCache){value}; }
static inline _s_ebef6cb6_outStatuses _ebef6cb6_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_ebef6cb6_outStatuses){value}; }
static inline _s_ebef6cb6_optionalFile _ebef6cb6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ebef6cb6_optionalFile){value}; }
static inline _s_ebef6cb6_optionalLine _ebef6cb6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ebef6cb6_optionalLine){value}; }
static inline _s_ebef6cb6_optionalUserData _ebef6cb6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ebef6cb6_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redProcedureCacheMergeCaches(_s_ebef6cb6_context context, _s_ebef6cb6_gpu gpu, _s_ebef6cb6_sourceProcedureCachesCount sourceProcedureCachesCount, _s_ebef6cb6_sourceProcedureCaches sourceProcedureCaches, _s_ebef6cb6_targetProcedureCache targetProcedureCache, _s_ebef6cb6_outStatuses outStatuses, _s_ebef6cb6_optionalFile optionalFile, _s_ebef6cb6_optionalLine optionalLine, _s_ebef6cb6_optionalUserData optionalUserData) {
  redProcedureCacheMergeCaches(context.value, gpu.value, sourceProcedureCachesCount.value, sourceProcedureCaches.value, targetProcedureCache.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCpuSignalGetStatus redCpuSignalGetStatus
#define _04bad4da_context(value) value
#define _04bad4da_gpu(value) value
#define _04bad4da_cpuSignal(value) value
#define _04bad4da_outStatus(value) value
#define _04bad4da_optionalFile(value) value
#define _04bad4da_optionalLine(value) value
#define _04bad4da_optionalUserData(value) value
#else
typedef struct _s_04bad4da_context { RedContext value; } _s_04bad4da_context;
typedef struct _s_04bad4da_gpu { RedHandleGpu value; } _s_04bad4da_gpu;
typedef struct _s_04bad4da_cpuSignal { RedHandleCpuSignal value; } _s_04bad4da_cpuSignal;
typedef struct _s_04bad4da_outStatus { RedStatus* value; } _s_04bad4da_outStatus;
typedef struct _s_04bad4da_optionalFile { char* value; } _s_04bad4da_optionalFile;
typedef struct _s_04bad4da_optionalLine { int value; } _s_04bad4da_optionalLine;
typedef struct _s_04bad4da_optionalUserData { void* value; } _s_04bad4da_optionalUserData;
static inline _s_04bad4da_context _04bad4da_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_04bad4da_context){value}; }
static inline _s_04bad4da_gpu _04bad4da_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_04bad4da_gpu){value}; }
static inline _s_04bad4da_cpuSignal _04bad4da_cpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_04bad4da_cpuSignal){value}; }
static inline _s_04bad4da_outStatus _04bad4da_outStatus(RedStatus* value) { return REDGPU_NP_STRUCT_INIT(_s_04bad4da_outStatus){value}; }
static inline _s_04bad4da_optionalFile _04bad4da_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_04bad4da_optionalFile){value}; }
static inline _s_04bad4da_optionalLine _04bad4da_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_04bad4da_optionalLine){value}; }
static inline _s_04bad4da_optionalUserData _04bad4da_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_04bad4da_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCpuSignalGetStatus(_s_04bad4da_context context, _s_04bad4da_gpu gpu, _s_04bad4da_cpuSignal cpuSignal, _s_04bad4da_outStatus outStatus, _s_04bad4da_optionalFile optionalFile, _s_04bad4da_optionalLine optionalLine, _s_04bad4da_optionalUserData optionalUserData) {
  redCpuSignalGetStatus(context.value, gpu.value, cpuSignal.value, outStatus.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCpuSignalWait redCpuSignalWait
#define _7940a737_context(value) value
#define _7940a737_gpu(value) value
#define _7940a737_cpuSignalsCount(value) value
#define _7940a737_cpuSignals(value) value
#define _7940a737_waitAll(value) value
#define _7940a737_outStatuses(value) value
#define _7940a737_optionalFile(value) value
#define _7940a737_optionalLine(value) value
#define _7940a737_optionalUserData(value) value
#else
typedef struct _s_7940a737_context { RedContext value; } _s_7940a737_context;
typedef struct _s_7940a737_gpu { RedHandleGpu value; } _s_7940a737_gpu;
typedef struct _s_7940a737_cpuSignalsCount { unsigned value; } _s_7940a737_cpuSignalsCount;
typedef struct _s_7940a737_cpuSignals { RedHandleCpuSignal* value; } _s_7940a737_cpuSignals;
typedef struct _s_7940a737_waitAll { RedBool32 value; } _s_7940a737_waitAll;
typedef struct _s_7940a737_outStatuses { RedStatuses* value; } _s_7940a737_outStatuses;
typedef struct _s_7940a737_optionalFile { char* value; } _s_7940a737_optionalFile;
typedef struct _s_7940a737_optionalLine { int value; } _s_7940a737_optionalLine;
typedef struct _s_7940a737_optionalUserData { void* value; } _s_7940a737_optionalUserData;
static inline _s_7940a737_context _7940a737_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_7940a737_context){value}; }
static inline _s_7940a737_gpu _7940a737_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_7940a737_gpu){value}; }
static inline _s_7940a737_cpuSignalsCount _7940a737_cpuSignalsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_7940a737_cpuSignalsCount){value}; }
static inline _s_7940a737_cpuSignals _7940a737_cpuSignals(RedHandleCpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_7940a737_cpuSignals){value}; }
static inline _s_7940a737_waitAll _7940a737_waitAll(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_7940a737_waitAll){value}; }
static inline _s_7940a737_outStatuses _7940a737_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_7940a737_outStatuses){value}; }
static inline _s_7940a737_optionalFile _7940a737_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7940a737_optionalFile){value}; }
static inline _s_7940a737_optionalLine _7940a737_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7940a737_optionalLine){value}; }
static inline _s_7940a737_optionalUserData _7940a737_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7940a737_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCpuSignalWait(_s_7940a737_context context, _s_7940a737_gpu gpu, _s_7940a737_cpuSignalsCount cpuSignalsCount, _s_7940a737_cpuSignals cpuSignals, _s_7940a737_waitAll waitAll, _s_7940a737_outStatuses outStatuses, _s_7940a737_optionalFile optionalFile, _s_7940a737_optionalLine optionalLine, _s_7940a737_optionalUserData optionalUserData) {
  redCpuSignalWait(context.value, gpu.value, cpuSignalsCount.value, cpuSignals.value, waitAll.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCpuSignalUnsignal redCpuSignalUnsignal
#define _b597ab18_context(value) value
#define _b597ab18_gpu(value) value
#define _b597ab18_cpuSignalsCount(value) value
#define _b597ab18_cpuSignals(value) value
#define _b597ab18_outStatuses(value) value
#define _b597ab18_optionalFile(value) value
#define _b597ab18_optionalLine(value) value
#define _b597ab18_optionalUserData(value) value
#else
typedef struct _s_b597ab18_context { RedContext value; } _s_b597ab18_context;
typedef struct _s_b597ab18_gpu { RedHandleGpu value; } _s_b597ab18_gpu;
typedef struct _s_b597ab18_cpuSignalsCount { unsigned value; } _s_b597ab18_cpuSignalsCount;
typedef struct _s_b597ab18_cpuSignals { RedHandleCpuSignal* value; } _s_b597ab18_cpuSignals;
typedef struct _s_b597ab18_outStatuses { RedStatuses* value; } _s_b597ab18_outStatuses;
typedef struct _s_b597ab18_optionalFile { char* value; } _s_b597ab18_optionalFile;
typedef struct _s_b597ab18_optionalLine { int value; } _s_b597ab18_optionalLine;
typedef struct _s_b597ab18_optionalUserData { void* value; } _s_b597ab18_optionalUserData;
static inline _s_b597ab18_context _b597ab18_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b597ab18_context){value}; }
static inline _s_b597ab18_gpu _b597ab18_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b597ab18_gpu){value}; }
static inline _s_b597ab18_cpuSignalsCount _b597ab18_cpuSignalsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b597ab18_cpuSignalsCount){value}; }
static inline _s_b597ab18_cpuSignals _b597ab18_cpuSignals(RedHandleCpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_b597ab18_cpuSignals){value}; }
static inline _s_b597ab18_outStatuses _b597ab18_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b597ab18_outStatuses){value}; }
static inline _s_b597ab18_optionalFile _b597ab18_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b597ab18_optionalFile){value}; }
static inline _s_b597ab18_optionalLine _b597ab18_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b597ab18_optionalLine){value}; }
static inline _s_b597ab18_optionalUserData _b597ab18_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b597ab18_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCpuSignalUnsignal(_s_b597ab18_context context, _s_b597ab18_gpu gpu, _s_b597ab18_cpuSignalsCount cpuSignalsCount, _s_b597ab18_cpuSignals cpuSignals, _s_b597ab18_outStatuses outStatuses, _s_b597ab18_optionalFile optionalFile, _s_b597ab18_optionalLine optionalLine, _s_b597ab18_optionalUserData optionalUserData) {
  redCpuSignalUnsignal(context.value, gpu.value, cpuSignalsCount.value, cpuSignals.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redGpuToCpuSignalGetStatus redGpuToCpuSignalGetStatus
#define _7f7db24c_context(value) value
#define _7f7db24c_gpu(value) value
#define _7f7db24c_gpuToCpuSignal(value) value
#define _7f7db24c_outStatus(value) value
#define _7f7db24c_optionalFile(value) value
#define _7f7db24c_optionalLine(value) value
#define _7f7db24c_optionalUserData(value) value
#else
typedef struct _s_7f7db24c_context { RedContext value; } _s_7f7db24c_context;
typedef struct _s_7f7db24c_gpu { RedHandleGpu value; } _s_7f7db24c_gpu;
typedef struct _s_7f7db24c_gpuToCpuSignal { RedHandleGpuToCpuSignal value; } _s_7f7db24c_gpuToCpuSignal;
typedef struct _s_7f7db24c_outStatus { RedStatus* value; } _s_7f7db24c_outStatus;
typedef struct _s_7f7db24c_optionalFile { char* value; } _s_7f7db24c_optionalFile;
typedef struct _s_7f7db24c_optionalLine { int value; } _s_7f7db24c_optionalLine;
typedef struct _s_7f7db24c_optionalUserData { void* value; } _s_7f7db24c_optionalUserData;
static inline _s_7f7db24c_context _7f7db24c_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_7f7db24c_context){value}; }
static inline _s_7f7db24c_gpu _7f7db24c_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_7f7db24c_gpu){value}; }
static inline _s_7f7db24c_gpuToCpuSignal _7f7db24c_gpuToCpuSignal(RedHandleGpuToCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_7f7db24c_gpuToCpuSignal){value}; }
static inline _s_7f7db24c_outStatus _7f7db24c_outStatus(RedStatus* value) { return REDGPU_NP_STRUCT_INIT(_s_7f7db24c_outStatus){value}; }
static inline _s_7f7db24c_optionalFile _7f7db24c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7f7db24c_optionalFile){value}; }
static inline _s_7f7db24c_optionalLine _7f7db24c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7f7db24c_optionalLine){value}; }
static inline _s_7f7db24c_optionalUserData _7f7db24c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7f7db24c_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redGpuToCpuSignalGetStatus(_s_7f7db24c_context context, _s_7f7db24c_gpu gpu, _s_7f7db24c_gpuToCpuSignal gpuToCpuSignal, _s_7f7db24c_outStatus outStatus, _s_7f7db24c_optionalFile optionalFile, _s_7f7db24c_optionalLine optionalLine, _s_7f7db24c_optionalUserData optionalUserData) {
  redGpuToCpuSignalGetStatus(context.value, gpu.value, gpuToCpuSignal.value, outStatus.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redGpuToCpuSignalUnsignal redGpuToCpuSignalUnsignal
#define _6f6433ea_context(value) value
#define _6f6433ea_gpu(value) value
#define _6f6433ea_gpuToCpuSignal(value) value
#define _6f6433ea_outStatuses(value) value
#define _6f6433ea_optionalFile(value) value
#define _6f6433ea_optionalLine(value) value
#define _6f6433ea_optionalUserData(value) value
#else
typedef struct _s_6f6433ea_context { RedContext value; } _s_6f6433ea_context;
typedef struct _s_6f6433ea_gpu { RedHandleGpu value; } _s_6f6433ea_gpu;
typedef struct _s_6f6433ea_gpuToCpuSignal { RedHandleGpuToCpuSignal value; } _s_6f6433ea_gpuToCpuSignal;
typedef struct _s_6f6433ea_outStatuses { RedStatuses* value; } _s_6f6433ea_outStatuses;
typedef struct _s_6f6433ea_optionalFile { char* value; } _s_6f6433ea_optionalFile;
typedef struct _s_6f6433ea_optionalLine { int value; } _s_6f6433ea_optionalLine;
typedef struct _s_6f6433ea_optionalUserData { void* value; } _s_6f6433ea_optionalUserData;
static inline _s_6f6433ea_context _6f6433ea_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_6f6433ea_context){value}; }
static inline _s_6f6433ea_gpu _6f6433ea_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_6f6433ea_gpu){value}; }
static inline _s_6f6433ea_gpuToCpuSignal _6f6433ea_gpuToCpuSignal(RedHandleGpuToCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_6f6433ea_gpuToCpuSignal){value}; }
static inline _s_6f6433ea_outStatuses _6f6433ea_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_6f6433ea_outStatuses){value}; }
static inline _s_6f6433ea_optionalFile _6f6433ea_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6f6433ea_optionalFile){value}; }
static inline _s_6f6433ea_optionalLine _6f6433ea_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6f6433ea_optionalLine){value}; }
static inline _s_6f6433ea_optionalUserData _6f6433ea_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6f6433ea_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redGpuToCpuSignalUnsignal(_s_6f6433ea_context context, _s_6f6433ea_gpu gpu, _s_6f6433ea_gpuToCpuSignal gpuToCpuSignal, _s_6f6433ea_outStatuses outStatuses, _s_6f6433ea_optionalFile optionalFile, _s_6f6433ea_optionalLine optionalLine, _s_6f6433ea_optionalUserData optionalUserData) {
  redGpuToCpuSignalUnsignal(context.value, gpu.value, gpuToCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallsSet redCallsSet
#define _d3b7aee5_context(value) value
#define _d3b7aee5_gpu(value) value
#define _d3b7aee5_calls(value) value
#define _d3b7aee5_callsMemory(value) value
#define _d3b7aee5_callsReusable(value) value
#define _d3b7aee5_outStatuses(value) value
#define _d3b7aee5_optionalFile(value) value
#define _d3b7aee5_optionalLine(value) value
#define _d3b7aee5_optionalUserData(value) value
#else
typedef struct _s_d3b7aee5_context { RedContext value; } _s_d3b7aee5_context;
typedef struct _s_d3b7aee5_gpu { RedHandleGpu value; } _s_d3b7aee5_gpu;
typedef struct _s_d3b7aee5_calls { RedHandleCalls value; } _s_d3b7aee5_calls;
typedef struct _s_d3b7aee5_callsMemory { RedHandleCallsMemory value; } _s_d3b7aee5_callsMemory;
typedef struct _s_d3b7aee5_callsReusable { RedBool32 value; } _s_d3b7aee5_callsReusable;
typedef struct _s_d3b7aee5_outStatuses { RedStatuses* value; } _s_d3b7aee5_outStatuses;
typedef struct _s_d3b7aee5_optionalFile { char* value; } _s_d3b7aee5_optionalFile;
typedef struct _s_d3b7aee5_optionalLine { int value; } _s_d3b7aee5_optionalLine;
typedef struct _s_d3b7aee5_optionalUserData { void* value; } _s_d3b7aee5_optionalUserData;
static inline _s_d3b7aee5_context _d3b7aee5_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_d3b7aee5_context){value}; }
static inline _s_d3b7aee5_gpu _d3b7aee5_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_d3b7aee5_gpu){value}; }
static inline _s_d3b7aee5_calls _d3b7aee5_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_d3b7aee5_calls){value}; }
static inline _s_d3b7aee5_callsMemory _d3b7aee5_callsMemory(RedHandleCallsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_d3b7aee5_callsMemory){value}; }
static inline _s_d3b7aee5_callsReusable _d3b7aee5_callsReusable(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_d3b7aee5_callsReusable){value}; }
static inline _s_d3b7aee5_outStatuses _d3b7aee5_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_d3b7aee5_outStatuses){value}; }
static inline _s_d3b7aee5_optionalFile _d3b7aee5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d3b7aee5_optionalFile){value}; }
static inline _s_d3b7aee5_optionalLine _d3b7aee5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d3b7aee5_optionalLine){value}; }
static inline _s_d3b7aee5_optionalUserData _d3b7aee5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d3b7aee5_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallsSet(_s_d3b7aee5_context context, _s_d3b7aee5_gpu gpu, _s_d3b7aee5_calls calls, _s_d3b7aee5_callsMemory callsMemory, _s_d3b7aee5_callsReusable callsReusable, _s_d3b7aee5_outStatuses outStatuses, _s_d3b7aee5_optionalFile optionalFile, _s_d3b7aee5_optionalLine optionalLine, _s_d3b7aee5_optionalUserData optionalUserData) {
  redCallsSet(context.value, gpu.value, calls.value, callsMemory.value, callsReusable.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallsEnd redCallsEnd
#define _38cd3d5a_context(value) value
#define _38cd3d5a_gpu(value) value
#define _38cd3d5a_calls(value) value
#define _38cd3d5a_callsMemory(value) value
#define _38cd3d5a_outStatuses(value) value
#define _38cd3d5a_optionalFile(value) value
#define _38cd3d5a_optionalLine(value) value
#define _38cd3d5a_optionalUserData(value) value
#else
typedef struct _s_38cd3d5a_context { RedContext value; } _s_38cd3d5a_context;
typedef struct _s_38cd3d5a_gpu { RedHandleGpu value; } _s_38cd3d5a_gpu;
typedef struct _s_38cd3d5a_calls { RedHandleCalls value; } _s_38cd3d5a_calls;
typedef struct _s_38cd3d5a_callsMemory { RedHandleCallsMemory value; } _s_38cd3d5a_callsMemory;
typedef struct _s_38cd3d5a_outStatuses { RedStatuses* value; } _s_38cd3d5a_outStatuses;
typedef struct _s_38cd3d5a_optionalFile { char* value; } _s_38cd3d5a_optionalFile;
typedef struct _s_38cd3d5a_optionalLine { int value; } _s_38cd3d5a_optionalLine;
typedef struct _s_38cd3d5a_optionalUserData { void* value; } _s_38cd3d5a_optionalUserData;
static inline _s_38cd3d5a_context _38cd3d5a_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_38cd3d5a_context){value}; }
static inline _s_38cd3d5a_gpu _38cd3d5a_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_38cd3d5a_gpu){value}; }
static inline _s_38cd3d5a_calls _38cd3d5a_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_38cd3d5a_calls){value}; }
static inline _s_38cd3d5a_callsMemory _38cd3d5a_callsMemory(RedHandleCallsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_38cd3d5a_callsMemory){value}; }
static inline _s_38cd3d5a_outStatuses _38cd3d5a_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_38cd3d5a_outStatuses){value}; }
static inline _s_38cd3d5a_optionalFile _38cd3d5a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_38cd3d5a_optionalFile){value}; }
static inline _s_38cd3d5a_optionalLine _38cd3d5a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_38cd3d5a_optionalLine){value}; }
static inline _s_38cd3d5a_optionalUserData _38cd3d5a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_38cd3d5a_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallsEnd(_s_38cd3d5a_context context, _s_38cd3d5a_gpu gpu, _s_38cd3d5a_calls calls, _s_38cd3d5a_callsMemory callsMemory, _s_38cd3d5a_outStatuses outStatuses, _s_38cd3d5a_optionalFile optionalFile, _s_38cd3d5a_optionalLine optionalLine, _s_38cd3d5a_optionalUserData optionalUserData) {
  redCallsEnd(context.value, gpu.value, calls.value, callsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redGetCallProceduresAndAddresses redGetCallProceduresAndAddresses
#define _dc88fc45_context(value) value
#define _dc88fc45_gpu(value) value
#define _dc88fc45_outCallProceduresAndAddresses(value) value
#define _dc88fc45_outStatuses(value) value
#define _dc88fc45_optionalFile(value) value
#define _dc88fc45_optionalLine(value) value
#define _dc88fc45_optionalUserData(value) value
#else
typedef struct _s_dc88fc45_context { RedContext value; } _s_dc88fc45_context;
typedef struct _s_dc88fc45_gpu { RedHandleGpu value; } _s_dc88fc45_gpu;
typedef struct _s_dc88fc45_outCallProceduresAndAddresses { RedCallProceduresAndAddresses* value; } _s_dc88fc45_outCallProceduresAndAddresses;
typedef struct _s_dc88fc45_outStatuses { RedStatuses* value; } _s_dc88fc45_outStatuses;
typedef struct _s_dc88fc45_optionalFile { char* value; } _s_dc88fc45_optionalFile;
typedef struct _s_dc88fc45_optionalLine { int value; } _s_dc88fc45_optionalLine;
typedef struct _s_dc88fc45_optionalUserData { void* value; } _s_dc88fc45_optionalUserData;
static inline _s_dc88fc45_context _dc88fc45_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_dc88fc45_context){value}; }
static inline _s_dc88fc45_gpu _dc88fc45_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_dc88fc45_gpu){value}; }
static inline _s_dc88fc45_outCallProceduresAndAddresses _dc88fc45_outCallProceduresAndAddresses(RedCallProceduresAndAddresses* value) { return REDGPU_NP_STRUCT_INIT(_s_dc88fc45_outCallProceduresAndAddresses){value}; }
static inline _s_dc88fc45_outStatuses _dc88fc45_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_dc88fc45_outStatuses){value}; }
static inline _s_dc88fc45_optionalFile _dc88fc45_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_dc88fc45_optionalFile){value}; }
static inline _s_dc88fc45_optionalLine _dc88fc45_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_dc88fc45_optionalLine){value}; }
static inline _s_dc88fc45_optionalUserData _dc88fc45_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_dc88fc45_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redGetCallProceduresAndAddresses(_s_dc88fc45_context context, _s_dc88fc45_gpu gpu, _s_dc88fc45_outCallProceduresAndAddresses outCallProceduresAndAddresses, _s_dc88fc45_outStatuses outStatuses, _s_dc88fc45_optionalFile optionalFile, _s_dc88fc45_optionalLine optionalLine, _s_dc88fc45_optionalUserData optionalUserData) {
  redGetCallProceduresAndAddresses(context.value, gpu.value, outCallProceduresAndAddresses.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetDynamicViewport redCallSetDynamicViewport
#define _bb9fe89b_address(value) value
#define _bb9fe89b_calls(value) value
#define _bb9fe89b_x(value) value
#define _bb9fe89b_y(value) value
#define _bb9fe89b_width(value) value
#define _bb9fe89b_height(value) value
#define _bb9fe89b_depthMin(value) value
#define _bb9fe89b_depthMax(value) value
#else
typedef struct _s_bb9fe89b_address { RedTypeProcedureAddressCallSetDynamicViewport value; } _s_bb9fe89b_address;
typedef struct _s_bb9fe89b_calls { RedHandleCalls value; } _s_bb9fe89b_calls;
typedef struct _s_bb9fe89b_x { float value; } _s_bb9fe89b_x;
typedef struct _s_bb9fe89b_y { float value; } _s_bb9fe89b_y;
typedef struct _s_bb9fe89b_width { float value; } _s_bb9fe89b_width;
typedef struct _s_bb9fe89b_height { float value; } _s_bb9fe89b_height;
typedef struct _s_bb9fe89b_depthMin { float value; } _s_bb9fe89b_depthMin;
typedef struct _s_bb9fe89b_depthMax { float value; } _s_bb9fe89b_depthMax;
static inline _s_bb9fe89b_address _bb9fe89b_address(RedTypeProcedureAddressCallSetDynamicViewport value) { return REDGPU_NP_STRUCT_INIT(_s_bb9fe89b_address){value}; }
static inline _s_bb9fe89b_calls _bb9fe89b_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_bb9fe89b_calls){value}; }
static inline _s_bb9fe89b_x _bb9fe89b_x(float value) { return REDGPU_NP_STRUCT_INIT(_s_bb9fe89b_x){value}; }
static inline _s_bb9fe89b_y _bb9fe89b_y(float value) { return REDGPU_NP_STRUCT_INIT(_s_bb9fe89b_y){value}; }
static inline _s_bb9fe89b_width _bb9fe89b_width(float value) { return REDGPU_NP_STRUCT_INIT(_s_bb9fe89b_width){value}; }
static inline _s_bb9fe89b_height _bb9fe89b_height(float value) { return REDGPU_NP_STRUCT_INIT(_s_bb9fe89b_height){value}; }
static inline _s_bb9fe89b_depthMin _bb9fe89b_depthMin(float value) { return REDGPU_NP_STRUCT_INIT(_s_bb9fe89b_depthMin){value}; }
static inline _s_bb9fe89b_depthMax _bb9fe89b_depthMax(float value) { return REDGPU_NP_STRUCT_INIT(_s_bb9fe89b_depthMax){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetDynamicViewport(_s_bb9fe89b_address address, _s_bb9fe89b_calls calls, _s_bb9fe89b_x x, _s_bb9fe89b_y y, _s_bb9fe89b_width width, _s_bb9fe89b_height height, _s_bb9fe89b_depthMin depthMin, _s_bb9fe89b_depthMax depthMax) {
  redCallSetDynamicViewport(address.value, calls.value, x.value, y.value, width.value, height.value, depthMin.value, depthMax.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetDynamicScissor redCallSetDynamicScissor
#define _b42531b6_address(value) value
#define _b42531b6_calls(value) value
#define _b42531b6_x(value) value
#define _b42531b6_y(value) value
#define _b42531b6_width(value) value
#define _b42531b6_height(value) value
#else
typedef struct _s_b42531b6_address { RedTypeProcedureAddressCallSetDynamicScissor value; } _s_b42531b6_address;
typedef struct _s_b42531b6_calls { RedHandleCalls value; } _s_b42531b6_calls;
typedef struct _s_b42531b6_x { int value; } _s_b42531b6_x;
typedef struct _s_b42531b6_y { int value; } _s_b42531b6_y;
typedef struct _s_b42531b6_width { unsigned value; } _s_b42531b6_width;
typedef struct _s_b42531b6_height { unsigned value; } _s_b42531b6_height;
static inline _s_b42531b6_address _b42531b6_address(RedTypeProcedureAddressCallSetDynamicScissor value) { return REDGPU_NP_STRUCT_INIT(_s_b42531b6_address){value}; }
static inline _s_b42531b6_calls _b42531b6_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_b42531b6_calls){value}; }
static inline _s_b42531b6_x _b42531b6_x(int value) { return REDGPU_NP_STRUCT_INIT(_s_b42531b6_x){value}; }
static inline _s_b42531b6_y _b42531b6_y(int value) { return REDGPU_NP_STRUCT_INIT(_s_b42531b6_y){value}; }
static inline _s_b42531b6_width _b42531b6_width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b42531b6_width){value}; }
static inline _s_b42531b6_height _b42531b6_height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b42531b6_height){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetDynamicScissor(_s_b42531b6_address address, _s_b42531b6_calls calls, _s_b42531b6_x x, _s_b42531b6_y y, _s_b42531b6_width width, _s_b42531b6_height height) {
  redCallSetDynamicScissor(address.value, calls.value, x.value, y.value, width.value, height.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetStructsMemory redCallSetStructsMemory
#define _974c5972_address(value) value
#define _974c5972_calls(value) value
#define _974c5972_structsMemory(value) value
#define _974c5972_structsMemorySamplers(value) value
#else
typedef struct _s_974c5972_address { RedTypeProcedureAddressCallSetStructsMemory value; } _s_974c5972_address;
typedef struct _s_974c5972_calls { RedHandleCalls value; } _s_974c5972_calls;
typedef struct _s_974c5972_structsMemory { RedHandleStructsMemory value; } _s_974c5972_structsMemory;
typedef struct _s_974c5972_structsMemorySamplers { RedHandleStructsMemory value; } _s_974c5972_structsMemorySamplers;
static inline _s_974c5972_address _974c5972_address(RedTypeProcedureAddressCallSetStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_974c5972_address){value}; }
static inline _s_974c5972_calls _974c5972_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_974c5972_calls){value}; }
static inline _s_974c5972_structsMemory _974c5972_structsMemory(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_974c5972_structsMemory){value}; }
static inline _s_974c5972_structsMemorySamplers _974c5972_structsMemorySamplers(RedHandleStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_974c5972_structsMemorySamplers){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetStructsMemory(_s_974c5972_address address, _s_974c5972_calls calls, _s_974c5972_structsMemory structsMemory, _s_974c5972_structsMemorySamplers structsMemorySamplers) {
  redCallSetStructsMemory(address.value, calls.value, structsMemory.value, structsMemorySamplers.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetProcedureParameters redCallSetProcedureParameters
#define _6fa5bfa6_address(value) value
#define _6fa5bfa6_calls(value) value
#define _6fa5bfa6_procedureType(value) value
#define _6fa5bfa6_procedureParameters(value) value
#else
typedef struct _s_6fa5bfa6_address { RedTypeProcedureAddressCallSetProcedureParameters value; } _s_6fa5bfa6_address;
typedef struct _s_6fa5bfa6_calls { RedHandleCalls value; } _s_6fa5bfa6_calls;
typedef struct _s_6fa5bfa6_procedureType { RedProcedureType value; } _s_6fa5bfa6_procedureType;
typedef struct _s_6fa5bfa6_procedureParameters { RedHandleProcedureParameters value; } _s_6fa5bfa6_procedureParameters;
static inline _s_6fa5bfa6_address _6fa5bfa6_address(RedTypeProcedureAddressCallSetProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_6fa5bfa6_address){value}; }
static inline _s_6fa5bfa6_calls _6fa5bfa6_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_6fa5bfa6_calls){value}; }
static inline _s_6fa5bfa6_procedureType _6fa5bfa6_procedureType(RedProcedureType value) { return REDGPU_NP_STRUCT_INIT(_s_6fa5bfa6_procedureType){value}; }
static inline _s_6fa5bfa6_procedureParameters _6fa5bfa6_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_6fa5bfa6_procedureParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetProcedureParameters(_s_6fa5bfa6_address address, _s_6fa5bfa6_calls calls, _s_6fa5bfa6_procedureType procedureType, _s_6fa5bfa6_procedureParameters procedureParameters) {
  redCallSetProcedureParameters(address.value, calls.value, procedureType.value, procedureParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallSetProcedureOutput redCallSetProcedureOutput
#define _a458cf47_address(value) value
#define _a458cf47_calls(value) value
#define _a458cf47_outputDeclaration(value) value
#define _a458cf47_output(value) value
#define _a458cf47_inlineOutput(value) value
#define _a458cf47_outputWidth(value) value
#define _a458cf47_outputHeight(value) value
#define _a458cf47_outputDepthStencilEnable(value) value
#define _a458cf47_outputColorsCount(value) value
#define _a458cf47_depthClearValue(value) value
#define _a458cf47_stencilClearValue(value) value
#define _a458cf47_colorsClearValuesFloat(value) value
#define _a458cf47_colorsClearValuesSint(value) value
#define _a458cf47_colorsClearValuesUint(value) value
#else
typedef struct _s_a458cf47_address { RedTypeProcedureAddressCallSetProcedureOutput value; } _s_a458cf47_address;
typedef struct _s_a458cf47_calls { RedHandleCalls value; } _s_a458cf47_calls;
typedef struct _s_a458cf47_outputDeclaration { RedHandleOutputDeclaration value; } _s_a458cf47_outputDeclaration;
typedef struct _s_a458cf47_output { RedHandleOutput value; } _s_a458cf47_output;
typedef struct _s_a458cf47_inlineOutput { RedInlineOutput* value; } _s_a458cf47_inlineOutput;
typedef struct _s_a458cf47_outputWidth { unsigned value; } _s_a458cf47_outputWidth;
typedef struct _s_a458cf47_outputHeight { unsigned value; } _s_a458cf47_outputHeight;
typedef struct _s_a458cf47_outputDepthStencilEnable { RedBool32 value; } _s_a458cf47_outputDepthStencilEnable;
typedef struct _s_a458cf47_outputColorsCount { unsigned value; } _s_a458cf47_outputColorsCount;
typedef struct _s_a458cf47_depthClearValue { float value; } _s_a458cf47_depthClearValue;
typedef struct _s_a458cf47_stencilClearValue { unsigned value; } _s_a458cf47_stencilClearValue;
typedef struct _s_a458cf47_colorsClearValuesFloat { RedColorsClearValuesFloat* value; } _s_a458cf47_colorsClearValuesFloat;
typedef struct _s_a458cf47_colorsClearValuesSint { RedColorsClearValuesSint* value; } _s_a458cf47_colorsClearValuesSint;
typedef struct _s_a458cf47_colorsClearValuesUint { RedColorsClearValuesUint* value; } _s_a458cf47_colorsClearValuesUint;
static inline _s_a458cf47_address _a458cf47_address(RedTypeProcedureAddressCallSetProcedureOutput value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_address){value}; }
static inline _s_a458cf47_calls _a458cf47_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_calls){value}; }
static inline _s_a458cf47_outputDeclaration _a458cf47_outputDeclaration(RedHandleOutputDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_outputDeclaration){value}; }
static inline _s_a458cf47_output _a458cf47_output(RedHandleOutput value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_output){value}; }
static inline _s_a458cf47_inlineOutput _a458cf47_inlineOutput(RedInlineOutput* value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_inlineOutput){value}; }
static inline _s_a458cf47_outputWidth _a458cf47_outputWidth(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_outputWidth){value}; }
static inline _s_a458cf47_outputHeight _a458cf47_outputHeight(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_outputHeight){value}; }
static inline _s_a458cf47_outputDepthStencilEnable _a458cf47_outputDepthStencilEnable(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_outputDepthStencilEnable){value}; }
static inline _s_a458cf47_outputColorsCount _a458cf47_outputColorsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_outputColorsCount){value}; }
static inline _s_a458cf47_depthClearValue _a458cf47_depthClearValue(float value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_depthClearValue){value}; }
static inline _s_a458cf47_stencilClearValue _a458cf47_stencilClearValue(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_stencilClearValue){value}; }
static inline _s_a458cf47_colorsClearValuesFloat _a458cf47_colorsClearValuesFloat(RedColorsClearValuesFloat* value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_colorsClearValuesFloat){value}; }
static inline _s_a458cf47_colorsClearValuesSint _a458cf47_colorsClearValuesSint(RedColorsClearValuesSint* value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_colorsClearValuesSint){value}; }
static inline _s_a458cf47_colorsClearValuesUint _a458cf47_colorsClearValuesUint(RedColorsClearValuesUint* value) { return REDGPU_NP_STRUCT_INIT(_s_a458cf47_colorsClearValuesUint){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallSetProcedureOutput(_s_a458cf47_address address, _s_a458cf47_calls calls, _s_a458cf47_outputDeclaration outputDeclaration, _s_a458cf47_output output, _s_a458cf47_inlineOutput inlineOutput, _s_a458cf47_outputWidth outputWidth, _s_a458cf47_outputHeight outputHeight, _s_a458cf47_outputDepthStencilEnable outputDepthStencilEnable, _s_a458cf47_outputColorsCount outputColorsCount, _s_a458cf47_depthClearValue depthClearValue, _s_a458cf47_stencilClearValue stencilClearValue, _s_a458cf47_colorsClearValuesFloat colorsClearValuesFloat, _s_a458cf47_colorsClearValuesSint colorsClearValuesSint, _s_a458cf47_colorsClearValuesUint colorsClearValuesUint) {
  redCallSetProcedureOutput(address.value, calls.value, outputDeclaration.value, output.value, inlineOutput.value, outputWidth.value, outputHeight.value, outputDepthStencilEnable.value, outputColorsCount.value, depthClearValue.value, stencilClearValue.value, colorsClearValuesFloat.value, colorsClearValuesSint.value, colorsClearValuesUint.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallEndProcedureOutput redCallEndProcedureOutput
#define _36c677d0_address(value) value
#define _36c677d0_calls(value) value
#else
typedef struct _s_36c677d0_address { RedTypeProcedureAddressCallEndProcedureOutput value; } _s_36c677d0_address;
typedef struct _s_36c677d0_calls { RedHandleCalls value; } _s_36c677d0_calls;
static inline _s_36c677d0_address _36c677d0_address(RedTypeProcedureAddressCallEndProcedureOutput value) { return REDGPU_NP_STRUCT_INIT(_s_36c677d0_address){value}; }
static inline _s_36c677d0_calls _36c677d0_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_36c677d0_calls){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallEndProcedureOutput(_s_36c677d0_address address, _s_36c677d0_calls calls) {
  redCallEndProcedureOutput(address.value, calls.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallUsageAliasOrderBarrier redCallUsageAliasOrderBarrier
#define _f1d4a460_address(value) value
#define _f1d4a460_calls(value) value
#define _f1d4a460_context(value) value
#define _f1d4a460_arrayUsagesCount(value) value
#define _f1d4a460_arrayUsages(value) value
#define _f1d4a460_imageUsagesCount(value) value
#define _f1d4a460_imageUsages(value) value
#define _f1d4a460_aliasesCount(value) value
#define _f1d4a460_aliases(value) value
#define _f1d4a460_ordersCount(value) value
#define _f1d4a460_orders(value) value
#define _f1d4a460_dependencyByRegion(value) value
#else
typedef struct _s_f1d4a460_address { RedTypeProcedureAddressCallUsageAliasOrderBarrier value; } _s_f1d4a460_address;
typedef struct _s_f1d4a460_calls { RedHandleCalls value; } _s_f1d4a460_calls;
typedef struct _s_f1d4a460_context { RedContext value; } _s_f1d4a460_context;
typedef struct _s_f1d4a460_arrayUsagesCount { unsigned value; } _s_f1d4a460_arrayUsagesCount;
typedef struct _s_f1d4a460_arrayUsages { RedUsageArray* value; } _s_f1d4a460_arrayUsages;
typedef struct _s_f1d4a460_imageUsagesCount { unsigned value; } _s_f1d4a460_imageUsagesCount;
typedef struct _s_f1d4a460_imageUsages { RedUsageImage* value; } _s_f1d4a460_imageUsages;
typedef struct _s_f1d4a460_aliasesCount { unsigned value; } _s_f1d4a460_aliasesCount;
typedef struct _s_f1d4a460_aliases { RedAlias* value; } _s_f1d4a460_aliases;
typedef struct _s_f1d4a460_ordersCount { unsigned value; } _s_f1d4a460_ordersCount;
typedef struct _s_f1d4a460_orders { RedOrder* value; } _s_f1d4a460_orders;
typedef struct _s_f1d4a460_dependencyByRegion { RedBool32 value; } _s_f1d4a460_dependencyByRegion;
static inline _s_f1d4a460_address _f1d4a460_address(RedTypeProcedureAddressCallUsageAliasOrderBarrier value) { return REDGPU_NP_STRUCT_INIT(_s_f1d4a460_address){value}; }
static inline _s_f1d4a460_calls _f1d4a460_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_f1d4a460_calls){value}; }
static inline _s_f1d4a460_context _f1d4a460_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_f1d4a460_context){value}; }
static inline _s_f1d4a460_arrayUsagesCount _f1d4a460_arrayUsagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f1d4a460_arrayUsagesCount){value}; }
static inline _s_f1d4a460_arrayUsages _f1d4a460_arrayUsages(RedUsageArray* value) { return REDGPU_NP_STRUCT_INIT(_s_f1d4a460_arrayUsages){value}; }
static inline _s_f1d4a460_imageUsagesCount _f1d4a460_imageUsagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f1d4a460_imageUsagesCount){value}; }
static inline _s_f1d4a460_imageUsages _f1d4a460_imageUsages(RedUsageImage* value) { return REDGPU_NP_STRUCT_INIT(_s_f1d4a460_imageUsages){value}; }
static inline _s_f1d4a460_aliasesCount _f1d4a460_aliasesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f1d4a460_aliasesCount){value}; }
static inline _s_f1d4a460_aliases _f1d4a460_aliases(RedAlias* value) { return REDGPU_NP_STRUCT_INIT(_s_f1d4a460_aliases){value}; }
static inline _s_f1d4a460_ordersCount _f1d4a460_ordersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f1d4a460_ordersCount){value}; }
static inline _s_f1d4a460_orders _f1d4a460_orders(RedOrder* value) { return REDGPU_NP_STRUCT_INIT(_s_f1d4a460_orders){value}; }
static inline _s_f1d4a460_dependencyByRegion _f1d4a460_dependencyByRegion(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_f1d4a460_dependencyByRegion){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallUsageAliasOrderBarrier(_s_f1d4a460_address address, _s_f1d4a460_calls calls, _s_f1d4a460_context context, _s_f1d4a460_arrayUsagesCount arrayUsagesCount, _s_f1d4a460_arrayUsages arrayUsages, _s_f1d4a460_imageUsagesCount imageUsagesCount, _s_f1d4a460_imageUsages imageUsages, _s_f1d4a460_aliasesCount aliasesCount, _s_f1d4a460_aliases aliases, _s_f1d4a460_ordersCount ordersCount, _s_f1d4a460_orders orders, _s_f1d4a460_dependencyByRegion dependencyByRegion) {
  redCallUsageAliasOrderBarrier(address.value, calls.value, context.value, arrayUsagesCount.value, arrayUsages.value, imageUsagesCount.value, imageUsages.value, aliasesCount.value, aliases.value, ordersCount.value, orders.value, dependencyByRegion.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallMark redCallMark
#define _305ef049_address(value) value
#define _305ef049_calls(value) value
#define _305ef049_mark(value) value
#else
typedef struct _s_305ef049_address { RedTypeProcedureAddressCallMark value; } _s_305ef049_address;
typedef struct _s_305ef049_calls { RedHandleCalls value; } _s_305ef049_calls;
typedef struct _s_305ef049_mark { char* value; } _s_305ef049_mark;
static inline _s_305ef049_address _305ef049_address(RedTypeProcedureAddressCallMark value) { return REDGPU_NP_STRUCT_INIT(_s_305ef049_address){value}; }
static inline _s_305ef049_calls _305ef049_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_305ef049_calls){value}; }
static inline _s_305ef049_mark _305ef049_mark(char* value) { return REDGPU_NP_STRUCT_INIT(_s_305ef049_mark){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallMark(_s_305ef049_address address, _s_305ef049_calls calls, _s_305ef049_mark mark) {
  redCallMark(address.value, calls.value, mark.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallMarkSet redCallMarkSet
#define _4a20967c_address(value) value
#define _4a20967c_calls(value) value
#define _4a20967c_mark(value) value
#else
typedef struct _s_4a20967c_address { RedTypeProcedureAddressCallMarkSet value; } _s_4a20967c_address;
typedef struct _s_4a20967c_calls { RedHandleCalls value; } _s_4a20967c_calls;
typedef struct _s_4a20967c_mark { char* value; } _s_4a20967c_mark;
static inline _s_4a20967c_address _4a20967c_address(RedTypeProcedureAddressCallMarkSet value) { return REDGPU_NP_STRUCT_INIT(_s_4a20967c_address){value}; }
static inline _s_4a20967c_calls _4a20967c_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_4a20967c_calls){value}; }
static inline _s_4a20967c_mark _4a20967c_mark(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4a20967c_mark){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallMarkSet(_s_4a20967c_address address, _s_4a20967c_calls calls, _s_4a20967c_mark mark) {
  redCallMarkSet(address.value, calls.value, mark.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCallMarkEnd redCallMarkEnd
#define _c334b04a_address(value) value
#define _c334b04a_calls(value) value
#else
typedef struct _s_c334b04a_address { RedTypeProcedureAddressCallMarkEnd value; } _s_c334b04a_address;
typedef struct _s_c334b04a_calls { RedHandleCalls value; } _s_c334b04a_calls;
static inline _s_c334b04a_address _c334b04a_address(RedTypeProcedureAddressCallMarkEnd value) { return REDGPU_NP_STRUCT_INIT(_s_c334b04a_address){value}; }
static inline _s_c334b04a_calls _c334b04a_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_c334b04a_calls){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCallMarkEnd(_s_c334b04a_address address, _s_c334b04a_calls calls) {
  redCallMarkEnd(address.value, calls.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redQueueSubmit redQueueSubmit
#define _11eb54c8_context(value) value
#define _11eb54c8_gpu(value) value
#define _11eb54c8_queue(value) value
#define _11eb54c8_timelinesCount(value) value
#define _11eb54c8_timelines(value) value
#define _11eb54c8_signalCpuSignal(value) value
#define _11eb54c8_outStatuses(value) value
#define _11eb54c8_optionalFile(value) value
#define _11eb54c8_optionalLine(value) value
#define _11eb54c8_optionalUserData(value) value
#else
typedef struct _s_11eb54c8_context { RedContext value; } _s_11eb54c8_context;
typedef struct _s_11eb54c8_gpu { RedHandleGpu value; } _s_11eb54c8_gpu;
typedef struct _s_11eb54c8_queue { RedHandleQueue value; } _s_11eb54c8_queue;
typedef struct _s_11eb54c8_timelinesCount { unsigned value; } _s_11eb54c8_timelinesCount;
typedef struct _s_11eb54c8_timelines { RedGpuTimeline* value; } _s_11eb54c8_timelines;
typedef struct _s_11eb54c8_signalCpuSignal { RedHandleCpuSignal value; } _s_11eb54c8_signalCpuSignal;
typedef struct _s_11eb54c8_outStatuses { RedStatuses* value; } _s_11eb54c8_outStatuses;
typedef struct _s_11eb54c8_optionalFile { char* value; } _s_11eb54c8_optionalFile;
typedef struct _s_11eb54c8_optionalLine { int value; } _s_11eb54c8_optionalLine;
typedef struct _s_11eb54c8_optionalUserData { void* value; } _s_11eb54c8_optionalUserData;
static inline _s_11eb54c8_context _11eb54c8_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_11eb54c8_context){value}; }
static inline _s_11eb54c8_gpu _11eb54c8_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_11eb54c8_gpu){value}; }
static inline _s_11eb54c8_queue _11eb54c8_queue(RedHandleQueue value) { return REDGPU_NP_STRUCT_INIT(_s_11eb54c8_queue){value}; }
static inline _s_11eb54c8_timelinesCount _11eb54c8_timelinesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_11eb54c8_timelinesCount){value}; }
static inline _s_11eb54c8_timelines _11eb54c8_timelines(RedGpuTimeline* value) { return REDGPU_NP_STRUCT_INIT(_s_11eb54c8_timelines){value}; }
static inline _s_11eb54c8_signalCpuSignal _11eb54c8_signalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_11eb54c8_signalCpuSignal){value}; }
static inline _s_11eb54c8_outStatuses _11eb54c8_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_11eb54c8_outStatuses){value}; }
static inline _s_11eb54c8_optionalFile _11eb54c8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_11eb54c8_optionalFile){value}; }
static inline _s_11eb54c8_optionalLine _11eb54c8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_11eb54c8_optionalLine){value}; }
static inline _s_11eb54c8_optionalUserData _11eb54c8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_11eb54c8_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redQueueSubmit(_s_11eb54c8_context context, _s_11eb54c8_gpu gpu, _s_11eb54c8_queue queue, _s_11eb54c8_timelinesCount timelinesCount, _s_11eb54c8_timelines timelines, _s_11eb54c8_signalCpuSignal signalCpuSignal, _s_11eb54c8_outStatuses outStatuses, _s_11eb54c8_optionalFile optionalFile, _s_11eb54c8_optionalLine optionalLine, _s_11eb54c8_optionalUserData optionalUserData) {
  redQueueSubmit(context.value, gpu.value, queue.value, timelinesCount.value, timelines.value, signalCpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMark redMark
#define _41641bd5_mark(value) value
#define _41641bd5_optionalFile(value) value
#define _41641bd5_optionalLine(value) value
#define _41641bd5_optionalUserData(value) value
#else
typedef struct _s_41641bd5_mark { char* value; } _s_41641bd5_mark;
typedef struct _s_41641bd5_optionalFile { char* value; } _s_41641bd5_optionalFile;
typedef struct _s_41641bd5_optionalLine { int value; } _s_41641bd5_optionalLine;
typedef struct _s_41641bd5_optionalUserData { void* value; } _s_41641bd5_optionalUserData;
static inline _s_41641bd5_mark _41641bd5_mark(char* value) { return REDGPU_NP_STRUCT_INIT(_s_41641bd5_mark){value}; }
static inline _s_41641bd5_optionalFile _41641bd5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_41641bd5_optionalFile){value}; }
static inline _s_41641bd5_optionalLine _41641bd5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_41641bd5_optionalLine){value}; }
static inline _s_41641bd5_optionalUserData _41641bd5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_41641bd5_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMark(_s_41641bd5_mark mark, _s_41641bd5_optionalFile optionalFile, _s_41641bd5_optionalLine optionalLine, _s_41641bd5_optionalUserData optionalUserData) {
  redMark(mark.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMarkSet redMarkSet
#define _5f5e5ca2_mark(value) value
#define _5f5e5ca2_optionalFile(value) value
#define _5f5e5ca2_optionalLine(value) value
#define _5f5e5ca2_optionalUserData(value) value
#else
typedef struct _s_5f5e5ca2_mark { char* value; } _s_5f5e5ca2_mark;
typedef struct _s_5f5e5ca2_optionalFile { char* value; } _s_5f5e5ca2_optionalFile;
typedef struct _s_5f5e5ca2_optionalLine { int value; } _s_5f5e5ca2_optionalLine;
typedef struct _s_5f5e5ca2_optionalUserData { void* value; } _s_5f5e5ca2_optionalUserData;
static inline _s_5f5e5ca2_mark _5f5e5ca2_mark(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5f5e5ca2_mark){value}; }
static inline _s_5f5e5ca2_optionalFile _5f5e5ca2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5f5e5ca2_optionalFile){value}; }
static inline _s_5f5e5ca2_optionalLine _5f5e5ca2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5f5e5ca2_optionalLine){value}; }
static inline _s_5f5e5ca2_optionalUserData _5f5e5ca2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5f5e5ca2_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMarkSet(_s_5f5e5ca2_mark mark, _s_5f5e5ca2_optionalFile optionalFile, _s_5f5e5ca2_optionalLine optionalLine, _s_5f5e5ca2_optionalUserData optionalUserData) {
  redMarkSet(mark.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redMarkEnd redMarkEnd
#define _0d6bda5e_optionalFile(value) value
#define _0d6bda5e_optionalLine(value) value
#define _0d6bda5e_optionalUserData(value) value
#else
typedef struct _s_0d6bda5e_optionalFile { char* value; } _s_0d6bda5e_optionalFile;
typedef struct _s_0d6bda5e_optionalLine { int value; } _s_0d6bda5e_optionalLine;
typedef struct _s_0d6bda5e_optionalUserData { void* value; } _s_0d6bda5e_optionalUserData;
static inline _s_0d6bda5e_optionalFile _0d6bda5e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0d6bda5e_optionalFile){value}; }
static inline _s_0d6bda5e_optionalLine _0d6bda5e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0d6bda5e_optionalLine){value}; }
static inline _s_0d6bda5e_optionalUserData _0d6bda5e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0d6bda5e_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redMarkEnd(_s_0d6bda5e_optionalFile optionalFile, _s_0d6bda5e_optionalLine optionalLine, _s_0d6bda5e_optionalUserData optionalUserData) {
  redMarkEnd(optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemoryAllocateWithInlineSamplers redStructsMemoryAllocateWithInlineSamplers
#define _c3a176ab_context(value) value
#define _c3a176ab_gpu(value) value
#define _c3a176ab_handleName(value) value
#define _c3a176ab_maxStructsCount(value) value
#define _c3a176ab_maxStructsMembersOfTypeArrayROConstantCount(value) value
#define _c3a176ab_maxStructsMembersOfTypeArrayROOrArrayRWCount(value) value
#define _c3a176ab_maxStructsMembersOfTypeTextureROCount(value) value
#define _c3a176ab_maxStructsMembersOfTypeTextureRWCount(value) value
#define _c3a176ab_maxStructsMembersOfTypeInlineSamplerCount(value) value
#define _c3a176ab_outStructsMemory(value) value
#define _c3a176ab_outStatuses(value) value
#define _c3a176ab_optionalFile(value) value
#define _c3a176ab_optionalLine(value) value
#define _c3a176ab_optionalUserData(value) value
#else
typedef struct _s_c3a176ab_context { RedContext value; } _s_c3a176ab_context;
typedef struct _s_c3a176ab_gpu { RedHandleGpu value; } _s_c3a176ab_gpu;
typedef struct _s_c3a176ab_handleName { char* value; } _s_c3a176ab_handleName;
typedef struct _s_c3a176ab_maxStructsCount { unsigned value; } _s_c3a176ab_maxStructsCount;
typedef struct _s_c3a176ab_maxStructsMembersOfTypeArrayROConstantCount { unsigned value; } _s_c3a176ab_maxStructsMembersOfTypeArrayROConstantCount;
typedef struct _s_c3a176ab_maxStructsMembersOfTypeArrayROOrArrayRWCount { unsigned value; } _s_c3a176ab_maxStructsMembersOfTypeArrayROOrArrayRWCount;
typedef struct _s_c3a176ab_maxStructsMembersOfTypeTextureROCount { unsigned value; } _s_c3a176ab_maxStructsMembersOfTypeTextureROCount;
typedef struct _s_c3a176ab_maxStructsMembersOfTypeTextureRWCount { unsigned value; } _s_c3a176ab_maxStructsMembersOfTypeTextureRWCount;
typedef struct _s_c3a176ab_maxStructsMembersOfTypeInlineSamplerCount { unsigned value; } _s_c3a176ab_maxStructsMembersOfTypeInlineSamplerCount;
typedef struct _s_c3a176ab_outStructsMemory { RedHandleStructsMemory* value; } _s_c3a176ab_outStructsMemory;
typedef struct _s_c3a176ab_outStatuses { RedStatuses* value; } _s_c3a176ab_outStatuses;
typedef struct _s_c3a176ab_optionalFile { char* value; } _s_c3a176ab_optionalFile;
typedef struct _s_c3a176ab_optionalLine { int value; } _s_c3a176ab_optionalLine;
typedef struct _s_c3a176ab_optionalUserData { void* value; } _s_c3a176ab_optionalUserData;
static inline _s_c3a176ab_context _c3a176ab_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_context){value}; }
static inline _s_c3a176ab_gpu _c3a176ab_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_gpu){value}; }
static inline _s_c3a176ab_handleName _c3a176ab_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_handleName){value}; }
static inline _s_c3a176ab_maxStructsCount _c3a176ab_maxStructsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_maxStructsCount){value}; }
static inline _s_c3a176ab_maxStructsMembersOfTypeArrayROConstantCount _c3a176ab_maxStructsMembersOfTypeArrayROConstantCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_maxStructsMembersOfTypeArrayROConstantCount){value}; }
static inline _s_c3a176ab_maxStructsMembersOfTypeArrayROOrArrayRWCount _c3a176ab_maxStructsMembersOfTypeArrayROOrArrayRWCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_maxStructsMembersOfTypeArrayROOrArrayRWCount){value}; }
static inline _s_c3a176ab_maxStructsMembersOfTypeTextureROCount _c3a176ab_maxStructsMembersOfTypeTextureROCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_maxStructsMembersOfTypeTextureROCount){value}; }
static inline _s_c3a176ab_maxStructsMembersOfTypeTextureRWCount _c3a176ab_maxStructsMembersOfTypeTextureRWCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_maxStructsMembersOfTypeTextureRWCount){value}; }
static inline _s_c3a176ab_maxStructsMembersOfTypeInlineSamplerCount _c3a176ab_maxStructsMembersOfTypeInlineSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_maxStructsMembersOfTypeInlineSamplerCount){value}; }
static inline _s_c3a176ab_outStructsMemory _c3a176ab_outStructsMemory(RedHandleStructsMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_outStructsMemory){value}; }
static inline _s_c3a176ab_outStatuses _c3a176ab_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_outStatuses){value}; }
static inline _s_c3a176ab_optionalFile _c3a176ab_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_optionalFile){value}; }
static inline _s_c3a176ab_optionalLine _c3a176ab_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_optionalLine){value}; }
static inline _s_c3a176ab_optionalUserData _c3a176ab_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c3a176ab_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemoryAllocateWithInlineSamplers(_s_c3a176ab_context context, _s_c3a176ab_gpu gpu, _s_c3a176ab_handleName handleName, _s_c3a176ab_maxStructsCount maxStructsCount, _s_c3a176ab_maxStructsMembersOfTypeArrayROConstantCount maxStructsMembersOfTypeArrayROConstantCount, _s_c3a176ab_maxStructsMembersOfTypeArrayROOrArrayRWCount maxStructsMembersOfTypeArrayROOrArrayRWCount, _s_c3a176ab_maxStructsMembersOfTypeTextureROCount maxStructsMembersOfTypeTextureROCount, _s_c3a176ab_maxStructsMembersOfTypeTextureRWCount maxStructsMembersOfTypeTextureRWCount, _s_c3a176ab_maxStructsMembersOfTypeInlineSamplerCount maxStructsMembersOfTypeInlineSamplerCount, _s_c3a176ab_outStructsMemory outStructsMemory, _s_c3a176ab_outStatuses outStatuses, _s_c3a176ab_optionalFile optionalFile, _s_c3a176ab_optionalLine optionalLine, _s_c3a176ab_optionalUserData optionalUserData) {
  redStructsMemoryAllocateWithInlineSamplers(context.value, gpu.value, handleName.value, maxStructsCount.value, maxStructsMembersOfTypeArrayROConstantCount.value, maxStructsMembersOfTypeArrayROOrArrayRWCount.value, maxStructsMembersOfTypeTextureROCount.value, maxStructsMembersOfTypeTextureRWCount.value, maxStructsMembersOfTypeInlineSamplerCount.value, outStructsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redStructsMemoryAllocateSamplersWithInlineSamplers redStructsMemoryAllocateSamplersWithInlineSamplers
#define _70f9bde0_context(value) value
#define _70f9bde0_gpu(value) value
#define _70f9bde0_handleName(value) value
#define _70f9bde0_maxStructsCount(value) value
#define _70f9bde0_maxStructsMembersOfTypeSamplerCount(value) value
#define _70f9bde0_maxStructsMembersOfTypeInlineSamplerCount(value) value
#define _70f9bde0_outStructsMemory(value) value
#define _70f9bde0_outStatuses(value) value
#define _70f9bde0_optionalFile(value) value
#define _70f9bde0_optionalLine(value) value
#define _70f9bde0_optionalUserData(value) value
#else
typedef struct _s_70f9bde0_context { RedContext value; } _s_70f9bde0_context;
typedef struct _s_70f9bde0_gpu { RedHandleGpu value; } _s_70f9bde0_gpu;
typedef struct _s_70f9bde0_handleName { char* value; } _s_70f9bde0_handleName;
typedef struct _s_70f9bde0_maxStructsCount { unsigned value; } _s_70f9bde0_maxStructsCount;
typedef struct _s_70f9bde0_maxStructsMembersOfTypeSamplerCount { unsigned value; } _s_70f9bde0_maxStructsMembersOfTypeSamplerCount;
typedef struct _s_70f9bde0_maxStructsMembersOfTypeInlineSamplerCount { unsigned value; } _s_70f9bde0_maxStructsMembersOfTypeInlineSamplerCount;
typedef struct _s_70f9bde0_outStructsMemory { RedHandleStructsMemory* value; } _s_70f9bde0_outStructsMemory;
typedef struct _s_70f9bde0_outStatuses { RedStatuses* value; } _s_70f9bde0_outStatuses;
typedef struct _s_70f9bde0_optionalFile { char* value; } _s_70f9bde0_optionalFile;
typedef struct _s_70f9bde0_optionalLine { int value; } _s_70f9bde0_optionalLine;
typedef struct _s_70f9bde0_optionalUserData { void* value; } _s_70f9bde0_optionalUserData;
static inline _s_70f9bde0_context _70f9bde0_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_70f9bde0_context){value}; }
static inline _s_70f9bde0_gpu _70f9bde0_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_70f9bde0_gpu){value}; }
static inline _s_70f9bde0_handleName _70f9bde0_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_70f9bde0_handleName){value}; }
static inline _s_70f9bde0_maxStructsCount _70f9bde0_maxStructsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_70f9bde0_maxStructsCount){value}; }
static inline _s_70f9bde0_maxStructsMembersOfTypeSamplerCount _70f9bde0_maxStructsMembersOfTypeSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_70f9bde0_maxStructsMembersOfTypeSamplerCount){value}; }
static inline _s_70f9bde0_maxStructsMembersOfTypeInlineSamplerCount _70f9bde0_maxStructsMembersOfTypeInlineSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_70f9bde0_maxStructsMembersOfTypeInlineSamplerCount){value}; }
static inline _s_70f9bde0_outStructsMemory _70f9bde0_outStructsMemory(RedHandleStructsMemory* value) { return REDGPU_NP_STRUCT_INIT(_s_70f9bde0_outStructsMemory){value}; }
static inline _s_70f9bde0_outStatuses _70f9bde0_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_70f9bde0_outStatuses){value}; }
static inline _s_70f9bde0_optionalFile _70f9bde0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_70f9bde0_optionalFile){value}; }
static inline _s_70f9bde0_optionalLine _70f9bde0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_70f9bde0_optionalLine){value}; }
static inline _s_70f9bde0_optionalUserData _70f9bde0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_70f9bde0_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redStructsMemoryAllocateSamplersWithInlineSamplers(_s_70f9bde0_context context, _s_70f9bde0_gpu gpu, _s_70f9bde0_handleName handleName, _s_70f9bde0_maxStructsCount maxStructsCount, _s_70f9bde0_maxStructsMembersOfTypeSamplerCount maxStructsMembersOfTypeSamplerCount, _s_70f9bde0_maxStructsMembersOfTypeInlineSamplerCount maxStructsMembersOfTypeInlineSamplerCount, _s_70f9bde0_outStructsMemory outStructsMemory, _s_70f9bde0_outStatuses outStatuses, _s_70f9bde0_optionalFile optionalFile, _s_70f9bde0_optionalLine optionalLine, _s_70f9bde0_optionalUserData optionalUserData) {
  redStructsMemoryAllocateSamplersWithInlineSamplers(context.value, gpu.value, handleName.value, maxStructsCount.value, maxStructsMembersOfTypeSamplerCount.value, maxStructsMembersOfTypeInlineSamplerCount.value, outStructsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

