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
#define np_greenCreateStructDeclaration greenCreateStructDeclaration
#define _0a8a30e6_context(value) value
#define _0a8a30e6_gpu(value) value
#define _0a8a30e6_handleName(value) value
#define _0a8a30e6_outStructDeclaration(value) value
#define _0a8a30e6_outStatuses(value) value
#define _0a8a30e6_optionalFile(value) value
#define _0a8a30e6_optionalLine(value) value
#define _0a8a30e6_optionalUserData(value) value
#else
typedef struct _s_0a8a30e6_context { RedContext value; } _s_0a8a30e6_context;
typedef struct _s_0a8a30e6_gpu { RedHandleGpu value; } _s_0a8a30e6_gpu;
typedef struct _s_0a8a30e6_handleName { char* value; } _s_0a8a30e6_handleName;
typedef struct _s_0a8a30e6_outStructDeclaration { GreenStructDeclaration* value; } _s_0a8a30e6_outStructDeclaration;
typedef struct _s_0a8a30e6_outStatuses { RedStatuses* value; } _s_0a8a30e6_outStatuses;
typedef struct _s_0a8a30e6_optionalFile { char* value; } _s_0a8a30e6_optionalFile;
typedef struct _s_0a8a30e6_optionalLine { int value; } _s_0a8a30e6_optionalLine;
typedef struct _s_0a8a30e6_optionalUserData { void* value; } _s_0a8a30e6_optionalUserData;
static inline _s_0a8a30e6_context _0a8a30e6_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_0a8a30e6_context){value}; }
static inline _s_0a8a30e6_gpu _0a8a30e6_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_0a8a30e6_gpu){value}; }
static inline _s_0a8a30e6_handleName _0a8a30e6_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0a8a30e6_handleName){value}; }
static inline _s_0a8a30e6_outStructDeclaration _0a8a30e6_outStructDeclaration(GreenStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_0a8a30e6_outStructDeclaration){value}; }
static inline _s_0a8a30e6_outStatuses _0a8a30e6_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_0a8a30e6_outStatuses){value}; }
static inline _s_0a8a30e6_optionalFile _0a8a30e6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0a8a30e6_optionalFile){value}; }
static inline _s_0a8a30e6_optionalLine _0a8a30e6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0a8a30e6_optionalLine){value}; }
static inline _s_0a8a30e6_optionalUserData _0a8a30e6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0a8a30e6_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenCreateStructDeclaration(_s_0a8a30e6_context context, _s_0a8a30e6_gpu gpu, _s_0a8a30e6_handleName handleName, _s_0a8a30e6_outStructDeclaration outStructDeclaration, _s_0a8a30e6_outStatuses outStatuses, _s_0a8a30e6_optionalFile optionalFile, _s_0a8a30e6_optionalLine optionalLine, _s_0a8a30e6_optionalUserData optionalUserData) {
  greenCreateStructDeclaration(context.value, gpu.value, handleName.value, outStructDeclaration.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_greenStructHeapAllocate greenStructHeapAllocate
#define _9ceb9cf5_context(value) value
#define _9ceb9cf5_gpu(value) value
#define _9ceb9cf5_handleName(value) value
#define _9ceb9cf5_structDeclarationsCount(value) value
#define _9ceb9cf5_structDeclarations(value) value
#define _9ceb9cf5_outStructHeap(value) value
#define _9ceb9cf5_outStatuses(value) value
#define _9ceb9cf5_optionalFile(value) value
#define _9ceb9cf5_optionalLine(value) value
#define _9ceb9cf5_optionalUserData(value) value
#else
typedef struct _s_9ceb9cf5_context { RedContext value; } _s_9ceb9cf5_context;
typedef struct _s_9ceb9cf5_gpu { RedHandleGpu value; } _s_9ceb9cf5_gpu;
typedef struct _s_9ceb9cf5_handleName { char* value; } _s_9ceb9cf5_handleName;
typedef struct _s_9ceb9cf5_structDeclarationsCount { unsigned value; } _s_9ceb9cf5_structDeclarationsCount;
typedef struct _s_9ceb9cf5_structDeclarations { GreenStructDeclaration* value; } _s_9ceb9cf5_structDeclarations;
typedef struct _s_9ceb9cf5_outStructHeap { GreenStructHeap* value; } _s_9ceb9cf5_outStructHeap;
typedef struct _s_9ceb9cf5_outStatuses { RedStatuses* value; } _s_9ceb9cf5_outStatuses;
typedef struct _s_9ceb9cf5_optionalFile { char* value; } _s_9ceb9cf5_optionalFile;
typedef struct _s_9ceb9cf5_optionalLine { int value; } _s_9ceb9cf5_optionalLine;
typedef struct _s_9ceb9cf5_optionalUserData { void* value; } _s_9ceb9cf5_optionalUserData;
static inline _s_9ceb9cf5_context _9ceb9cf5_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_9ceb9cf5_context){value}; }
static inline _s_9ceb9cf5_gpu _9ceb9cf5_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_9ceb9cf5_gpu){value}; }
static inline _s_9ceb9cf5_handleName _9ceb9cf5_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9ceb9cf5_handleName){value}; }
static inline _s_9ceb9cf5_structDeclarationsCount _9ceb9cf5_structDeclarationsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9ceb9cf5_structDeclarationsCount){value}; }
static inline _s_9ceb9cf5_structDeclarations _9ceb9cf5_structDeclarations(GreenStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_9ceb9cf5_structDeclarations){value}; }
static inline _s_9ceb9cf5_outStructHeap _9ceb9cf5_outStructHeap(GreenStructHeap* value) { return REDGPU_NP_STRUCT_INIT(_s_9ceb9cf5_outStructHeap){value}; }
static inline _s_9ceb9cf5_outStatuses _9ceb9cf5_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_9ceb9cf5_outStatuses){value}; }
static inline _s_9ceb9cf5_optionalFile _9ceb9cf5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9ceb9cf5_optionalFile){value}; }
static inline _s_9ceb9cf5_optionalLine _9ceb9cf5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9ceb9cf5_optionalLine){value}; }
static inline _s_9ceb9cf5_optionalUserData _9ceb9cf5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9ceb9cf5_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenStructHeapAllocate(_s_9ceb9cf5_context context, _s_9ceb9cf5_gpu gpu, _s_9ceb9cf5_handleName handleName, _s_9ceb9cf5_structDeclarationsCount structDeclarationsCount, _s_9ceb9cf5_structDeclarations structDeclarations, _s_9ceb9cf5_outStructHeap outStructHeap, _s_9ceb9cf5_outStatuses outStatuses, _s_9ceb9cf5_optionalFile optionalFile, _s_9ceb9cf5_optionalLine optionalLine, _s_9ceb9cf5_optionalUserData optionalUserData) {
  greenStructHeapAllocate(context.value, gpu.value, handleName.value, structDeclarationsCount.value, structDeclarations.value, outStructHeap.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_greenStructHeapReset greenStructHeapReset
#define _fa1824e1_context(value) value
#define _fa1824e1_gpu(value) value
#define _fa1824e1_structDeclarationsCount(value) value
#define _fa1824e1_structDeclarations(value) value
#define _fa1824e1_outStructHeap(value) value
#define _fa1824e1_outStatuses(value) value
#define _fa1824e1_optionalFile(value) value
#define _fa1824e1_optionalLine(value) value
#define _fa1824e1_optionalUserData(value) value
#else
typedef struct _s_fa1824e1_context { RedContext value; } _s_fa1824e1_context;
typedef struct _s_fa1824e1_gpu { RedHandleGpu value; } _s_fa1824e1_gpu;
typedef struct _s_fa1824e1_structDeclarationsCount { unsigned value; } _s_fa1824e1_structDeclarationsCount;
typedef struct _s_fa1824e1_structDeclarations { GreenStructDeclaration* value; } _s_fa1824e1_structDeclarations;
typedef struct _s_fa1824e1_outStructHeap { GreenStructHeap* value; } _s_fa1824e1_outStructHeap;
typedef struct _s_fa1824e1_outStatuses { RedStatuses* value; } _s_fa1824e1_outStatuses;
typedef struct _s_fa1824e1_optionalFile { char* value; } _s_fa1824e1_optionalFile;
typedef struct _s_fa1824e1_optionalLine { int value; } _s_fa1824e1_optionalLine;
typedef struct _s_fa1824e1_optionalUserData { void* value; } _s_fa1824e1_optionalUserData;
static inline _s_fa1824e1_context _fa1824e1_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_fa1824e1_context){value}; }
static inline _s_fa1824e1_gpu _fa1824e1_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_fa1824e1_gpu){value}; }
static inline _s_fa1824e1_structDeclarationsCount _fa1824e1_structDeclarationsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_fa1824e1_structDeclarationsCount){value}; }
static inline _s_fa1824e1_structDeclarations _fa1824e1_structDeclarations(GreenStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_fa1824e1_structDeclarations){value}; }
static inline _s_fa1824e1_outStructHeap _fa1824e1_outStructHeap(GreenStructHeap* value) { return REDGPU_NP_STRUCT_INIT(_s_fa1824e1_outStructHeap){value}; }
static inline _s_fa1824e1_outStatuses _fa1824e1_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_fa1824e1_outStatuses){value}; }
static inline _s_fa1824e1_optionalFile _fa1824e1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fa1824e1_optionalFile){value}; }
static inline _s_fa1824e1_optionalLine _fa1824e1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fa1824e1_optionalLine){value}; }
static inline _s_fa1824e1_optionalUserData _fa1824e1_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fa1824e1_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenStructHeapReset(_s_fa1824e1_context context, _s_fa1824e1_gpu gpu, _s_fa1824e1_structDeclarationsCount structDeclarationsCount, _s_fa1824e1_structDeclarations structDeclarations, _s_fa1824e1_outStructHeap outStructHeap, _s_fa1824e1_outStatuses outStatuses, _s_fa1824e1_optionalFile optionalFile, _s_fa1824e1_optionalLine optionalLine, _s_fa1824e1_optionalUserData optionalUserData) {
  greenStructHeapReset(context.value, gpu.value, structDeclarationsCount.value, structDeclarations.value, outStructHeap.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_greenStructHeapsSet greenStructHeapsSet
#define _6a2e38c0_context(value) value
#define _6a2e38c0_gpu(value) value
#define _6a2e38c0_structHeapsSetsCount(value) value
#define _6a2e38c0_structHeapsSets(value) value
#define _6a2e38c0_optionalFile(value) value
#define _6a2e38c0_optionalLine(value) value
#define _6a2e38c0_optionalUserData(value) value
#else
typedef struct _s_6a2e38c0_context { RedContext value; } _s_6a2e38c0_context;
typedef struct _s_6a2e38c0_gpu { RedHandleGpu value; } _s_6a2e38c0_gpu;
typedef struct _s_6a2e38c0_structHeapsSetsCount { unsigned value; } _s_6a2e38c0_structHeapsSetsCount;
typedef struct _s_6a2e38c0_structHeapsSets { GreenStructHeapSet* value; } _s_6a2e38c0_structHeapsSets;
typedef struct _s_6a2e38c0_optionalFile { char* value; } _s_6a2e38c0_optionalFile;
typedef struct _s_6a2e38c0_optionalLine { int value; } _s_6a2e38c0_optionalLine;
typedef struct _s_6a2e38c0_optionalUserData { void* value; } _s_6a2e38c0_optionalUserData;
static inline _s_6a2e38c0_context _6a2e38c0_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_6a2e38c0_context){value}; }
static inline _s_6a2e38c0_gpu _6a2e38c0_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_6a2e38c0_gpu){value}; }
static inline _s_6a2e38c0_structHeapsSetsCount _6a2e38c0_structHeapsSetsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6a2e38c0_structHeapsSetsCount){value}; }
static inline _s_6a2e38c0_structHeapsSets _6a2e38c0_structHeapsSets(GreenStructHeapSet* value) { return REDGPU_NP_STRUCT_INIT(_s_6a2e38c0_structHeapsSets){value}; }
static inline _s_6a2e38c0_optionalFile _6a2e38c0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6a2e38c0_optionalFile){value}; }
static inline _s_6a2e38c0_optionalLine _6a2e38c0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6a2e38c0_optionalLine){value}; }
static inline _s_6a2e38c0_optionalUserData _6a2e38c0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6a2e38c0_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenStructHeapsSet(_s_6a2e38c0_context context, _s_6a2e38c0_gpu gpu, _s_6a2e38c0_structHeapsSetsCount structHeapsSetsCount, _s_6a2e38c0_structHeapsSets structHeapsSets, _s_6a2e38c0_optionalFile optionalFile, _s_6a2e38c0_optionalLine optionalLine, _s_6a2e38c0_optionalUserData optionalUserData) {
  greenStructHeapsSet(context.value, gpu.value, structHeapsSetsCount.value, structHeapsSets.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_greenStructHeapFree greenStructHeapFree
#define _56605c20_context(value) value
#define _56605c20_gpu(value) value
#define _56605c20_structHeap(value) value
#define _56605c20_optionalFile(value) value
#define _56605c20_optionalLine(value) value
#define _56605c20_optionalUserData(value) value
#else
typedef struct _s_56605c20_context { RedContext value; } _s_56605c20_context;
typedef struct _s_56605c20_gpu { RedHandleGpu value; } _s_56605c20_gpu;
typedef struct _s_56605c20_structHeap { GreenStructHeap* value; } _s_56605c20_structHeap;
typedef struct _s_56605c20_optionalFile { char* value; } _s_56605c20_optionalFile;
typedef struct _s_56605c20_optionalLine { int value; } _s_56605c20_optionalLine;
typedef struct _s_56605c20_optionalUserData { void* value; } _s_56605c20_optionalUserData;
static inline _s_56605c20_context _56605c20_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_56605c20_context){value}; }
static inline _s_56605c20_gpu _56605c20_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_56605c20_gpu){value}; }
static inline _s_56605c20_structHeap _56605c20_structHeap(GreenStructHeap* value) { return REDGPU_NP_STRUCT_INIT(_s_56605c20_structHeap){value}; }
static inline _s_56605c20_optionalFile _56605c20_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_56605c20_optionalFile){value}; }
static inline _s_56605c20_optionalLine _56605c20_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_56605c20_optionalLine){value}; }
static inline _s_56605c20_optionalUserData _56605c20_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_56605c20_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenStructHeapFree(_s_56605c20_context context, _s_56605c20_gpu gpu, _s_56605c20_structHeap structHeap, _s_56605c20_optionalFile optionalFile, _s_56605c20_optionalLine optionalLine, _s_56605c20_optionalUserData optionalUserData) {
  greenStructHeapFree(context.value, gpu.value, structHeap.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

