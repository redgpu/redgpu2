#pragma once

#ifndef REDGPU_NP_STRUCT_INIT
#ifdef __cplusplus
#define REDGPU_NP_STRUCT_INIT(x) x
#else
#define REDGPU_NP_STRUCT_INIT(x) (x)
#endif
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_greenCreateStructDeclaration greenCreateStructDeclaration
#define _977b9202_context(value) value
#define _977b9202_gpu(value) value
#define _977b9202_handleName(value) value
#define _977b9202_outStructDeclaration(value) value
#define _977b9202_outStatuses(value) value
#define _977b9202_optionalFile(value) value
#define _977b9202_optionalLine(value) value
#define _977b9202_optionalUserData(value) value
#else
typedef struct _s_977b9202_context { RedContext value; } _s_977b9202_context;
typedef struct _s_977b9202_gpu { RedHandleGpu value; } _s_977b9202_gpu;
typedef struct _s_977b9202_handleName { char* value; } _s_977b9202_handleName;
typedef struct _s_977b9202_outStructDeclaration { GreenStructDeclaration* value; } _s_977b9202_outStructDeclaration;
typedef struct _s_977b9202_outStatuses { RedStatuses* value; } _s_977b9202_outStatuses;
typedef struct _s_977b9202_optionalFile { char* value; } _s_977b9202_optionalFile;
typedef struct _s_977b9202_optionalLine { int value; } _s_977b9202_optionalLine;
typedef struct _s_977b9202_optionalUserData { void* value; } _s_977b9202_optionalUserData;
static inline _s_977b9202_context _977b9202_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_977b9202_context){value}; }
static inline _s_977b9202_gpu _977b9202_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_977b9202_gpu){value}; }
static inline _s_977b9202_handleName _977b9202_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_977b9202_handleName){value}; }
static inline _s_977b9202_outStructDeclaration _977b9202_outStructDeclaration(GreenStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_977b9202_outStructDeclaration){value}; }
static inline _s_977b9202_outStatuses _977b9202_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_977b9202_outStatuses){value}; }
static inline _s_977b9202_optionalFile _977b9202_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_977b9202_optionalFile){value}; }
static inline _s_977b9202_optionalLine _977b9202_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_977b9202_optionalLine){value}; }
static inline _s_977b9202_optionalUserData _977b9202_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_977b9202_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenCreateStructDeclaration(_s_977b9202_context context, _s_977b9202_gpu gpu, _s_977b9202_handleName handleName, _s_977b9202_outStructDeclaration outStructDeclaration, _s_977b9202_outStatuses outStatuses, _s_977b9202_optionalFile optionalFile, _s_977b9202_optionalLine optionalLine, _s_977b9202_optionalUserData optionalUserData) {
  greenCreateStructDeclaration(context.value, gpu.value, handleName.value, outStructDeclaration.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_greenStructHeapAllocate greenStructHeapAllocate
#define _99ed7aae_context(value) value
#define _99ed7aae_gpu(value) value
#define _99ed7aae_handleName(value) value
#define _99ed7aae_structDeclarationsCount(value) value
#define _99ed7aae_structDeclarations(value) value
#define _99ed7aae_outStructHeap(value) value
#define _99ed7aae_outStatuses(value) value
#define _99ed7aae_optionalFile(value) value
#define _99ed7aae_optionalLine(value) value
#define _99ed7aae_optionalUserData(value) value
#else
typedef struct _s_99ed7aae_context { RedContext value; } _s_99ed7aae_context;
typedef struct _s_99ed7aae_gpu { RedHandleGpu value; } _s_99ed7aae_gpu;
typedef struct _s_99ed7aae_handleName { char* value; } _s_99ed7aae_handleName;
typedef struct _s_99ed7aae_structDeclarationsCount { unsigned value; } _s_99ed7aae_structDeclarationsCount;
typedef struct _s_99ed7aae_structDeclarations { GreenStructDeclaration* value; } _s_99ed7aae_structDeclarations;
typedef struct _s_99ed7aae_outStructHeap { GreenStructHeap* value; } _s_99ed7aae_outStructHeap;
typedef struct _s_99ed7aae_outStatuses { RedStatuses* value; } _s_99ed7aae_outStatuses;
typedef struct _s_99ed7aae_optionalFile { char* value; } _s_99ed7aae_optionalFile;
typedef struct _s_99ed7aae_optionalLine { int value; } _s_99ed7aae_optionalLine;
typedef struct _s_99ed7aae_optionalUserData { void* value; } _s_99ed7aae_optionalUserData;
static inline _s_99ed7aae_context _99ed7aae_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_99ed7aae_context){value}; }
static inline _s_99ed7aae_gpu _99ed7aae_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_99ed7aae_gpu){value}; }
static inline _s_99ed7aae_handleName _99ed7aae_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_99ed7aae_handleName){value}; }
static inline _s_99ed7aae_structDeclarationsCount _99ed7aae_structDeclarationsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_99ed7aae_structDeclarationsCount){value}; }
static inline _s_99ed7aae_structDeclarations _99ed7aae_structDeclarations(GreenStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_99ed7aae_structDeclarations){value}; }
static inline _s_99ed7aae_outStructHeap _99ed7aae_outStructHeap(GreenStructHeap* value) { return REDGPU_NP_STRUCT_INIT(_s_99ed7aae_outStructHeap){value}; }
static inline _s_99ed7aae_outStatuses _99ed7aae_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_99ed7aae_outStatuses){value}; }
static inline _s_99ed7aae_optionalFile _99ed7aae_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_99ed7aae_optionalFile){value}; }
static inline _s_99ed7aae_optionalLine _99ed7aae_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_99ed7aae_optionalLine){value}; }
static inline _s_99ed7aae_optionalUserData _99ed7aae_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_99ed7aae_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenStructHeapAllocate(_s_99ed7aae_context context, _s_99ed7aae_gpu gpu, _s_99ed7aae_handleName handleName, _s_99ed7aae_structDeclarationsCount structDeclarationsCount, _s_99ed7aae_structDeclarations structDeclarations, _s_99ed7aae_outStructHeap outStructHeap, _s_99ed7aae_outStatuses outStatuses, _s_99ed7aae_optionalFile optionalFile, _s_99ed7aae_optionalLine optionalLine, _s_99ed7aae_optionalUserData optionalUserData) {
  greenStructHeapAllocate(context.value, gpu.value, handleName.value, structDeclarationsCount.value, structDeclarations.value, outStructHeap.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_greenStructHeapReset greenStructHeapReset
#define _681f67ed_context(value) value
#define _681f67ed_gpu(value) value
#define _681f67ed_structDeclarationsCount(value) value
#define _681f67ed_structDeclarations(value) value
#define _681f67ed_outStructHeap(value) value
#define _681f67ed_outStatuses(value) value
#define _681f67ed_optionalFile(value) value
#define _681f67ed_optionalLine(value) value
#define _681f67ed_optionalUserData(value) value
#else
typedef struct _s_681f67ed_context { RedContext value; } _s_681f67ed_context;
typedef struct _s_681f67ed_gpu { RedHandleGpu value; } _s_681f67ed_gpu;
typedef struct _s_681f67ed_structDeclarationsCount { unsigned value; } _s_681f67ed_structDeclarationsCount;
typedef struct _s_681f67ed_structDeclarations { GreenStructDeclaration* value; } _s_681f67ed_structDeclarations;
typedef struct _s_681f67ed_outStructHeap { GreenStructHeap* value; } _s_681f67ed_outStructHeap;
typedef struct _s_681f67ed_outStatuses { RedStatuses* value; } _s_681f67ed_outStatuses;
typedef struct _s_681f67ed_optionalFile { char* value; } _s_681f67ed_optionalFile;
typedef struct _s_681f67ed_optionalLine { int value; } _s_681f67ed_optionalLine;
typedef struct _s_681f67ed_optionalUserData { void* value; } _s_681f67ed_optionalUserData;
static inline _s_681f67ed_context _681f67ed_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_681f67ed_context){value}; }
static inline _s_681f67ed_gpu _681f67ed_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_681f67ed_gpu){value}; }
static inline _s_681f67ed_structDeclarationsCount _681f67ed_structDeclarationsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_681f67ed_structDeclarationsCount){value}; }
static inline _s_681f67ed_structDeclarations _681f67ed_structDeclarations(GreenStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_681f67ed_structDeclarations){value}; }
static inline _s_681f67ed_outStructHeap _681f67ed_outStructHeap(GreenStructHeap* value) { return REDGPU_NP_STRUCT_INIT(_s_681f67ed_outStructHeap){value}; }
static inline _s_681f67ed_outStatuses _681f67ed_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_681f67ed_outStatuses){value}; }
static inline _s_681f67ed_optionalFile _681f67ed_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_681f67ed_optionalFile){value}; }
static inline _s_681f67ed_optionalLine _681f67ed_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_681f67ed_optionalLine){value}; }
static inline _s_681f67ed_optionalUserData _681f67ed_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_681f67ed_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenStructHeapReset(_s_681f67ed_context context, _s_681f67ed_gpu gpu, _s_681f67ed_structDeclarationsCount structDeclarationsCount, _s_681f67ed_structDeclarations structDeclarations, _s_681f67ed_outStructHeap outStructHeap, _s_681f67ed_outStatuses outStatuses, _s_681f67ed_optionalFile optionalFile, _s_681f67ed_optionalLine optionalLine, _s_681f67ed_optionalUserData optionalUserData) {
  greenStructHeapReset(context.value, gpu.value, structDeclarationsCount.value, structDeclarations.value, outStructHeap.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_greenStructHeapsSet greenStructHeapsSet
#define _4f8a622f_context(value) value
#define _4f8a622f_gpu(value) value
#define _4f8a622f_structHeapsSetsCount(value) value
#define _4f8a622f_structHeapsSets(value) value
#define _4f8a622f_optionalFile(value) value
#define _4f8a622f_optionalLine(value) value
#define _4f8a622f_optionalUserData(value) value
#else
typedef struct _s_4f8a622f_context { RedContext value; } _s_4f8a622f_context;
typedef struct _s_4f8a622f_gpu { RedHandleGpu value; } _s_4f8a622f_gpu;
typedef struct _s_4f8a622f_structHeapsSetsCount { unsigned value; } _s_4f8a622f_structHeapsSetsCount;
typedef struct _s_4f8a622f_structHeapsSets { GreenStructHeapSet* value; } _s_4f8a622f_structHeapsSets;
typedef struct _s_4f8a622f_optionalFile { char* value; } _s_4f8a622f_optionalFile;
typedef struct _s_4f8a622f_optionalLine { int value; } _s_4f8a622f_optionalLine;
typedef struct _s_4f8a622f_optionalUserData { void* value; } _s_4f8a622f_optionalUserData;
static inline _s_4f8a622f_context _4f8a622f_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_4f8a622f_context){value}; }
static inline _s_4f8a622f_gpu _4f8a622f_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_4f8a622f_gpu){value}; }
static inline _s_4f8a622f_structHeapsSetsCount _4f8a622f_structHeapsSetsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4f8a622f_structHeapsSetsCount){value}; }
static inline _s_4f8a622f_structHeapsSets _4f8a622f_structHeapsSets(GreenStructHeapSet* value) { return REDGPU_NP_STRUCT_INIT(_s_4f8a622f_structHeapsSets){value}; }
static inline _s_4f8a622f_optionalFile _4f8a622f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4f8a622f_optionalFile){value}; }
static inline _s_4f8a622f_optionalLine _4f8a622f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4f8a622f_optionalLine){value}; }
static inline _s_4f8a622f_optionalUserData _4f8a622f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4f8a622f_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenStructHeapsSet(_s_4f8a622f_context context, _s_4f8a622f_gpu gpu, _s_4f8a622f_structHeapsSetsCount structHeapsSetsCount, _s_4f8a622f_structHeapsSets structHeapsSets, _s_4f8a622f_optionalFile optionalFile, _s_4f8a622f_optionalLine optionalLine, _s_4f8a622f_optionalUserData optionalUserData) {
  greenStructHeapsSet(context.value, gpu.value, structHeapsSetsCount.value, structHeapsSets.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_greenStructHeapFree greenStructHeapFree
#define _99a2ca55_context(value) value
#define _99a2ca55_gpu(value) value
#define _99a2ca55_structHeap(value) value
#define _99a2ca55_optionalFile(value) value
#define _99a2ca55_optionalLine(value) value
#define _99a2ca55_optionalUserData(value) value
#else
typedef struct _s_99a2ca55_context { RedContext value; } _s_99a2ca55_context;
typedef struct _s_99a2ca55_gpu { RedHandleGpu value; } _s_99a2ca55_gpu;
typedef struct _s_99a2ca55_structHeap { GreenStructHeap* value; } _s_99a2ca55_structHeap;
typedef struct _s_99a2ca55_optionalFile { char* value; } _s_99a2ca55_optionalFile;
typedef struct _s_99a2ca55_optionalLine { int value; } _s_99a2ca55_optionalLine;
typedef struct _s_99a2ca55_optionalUserData { void* value; } _s_99a2ca55_optionalUserData;
static inline _s_99a2ca55_context _99a2ca55_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_99a2ca55_context){value}; }
static inline _s_99a2ca55_gpu _99a2ca55_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_99a2ca55_gpu){value}; }
static inline _s_99a2ca55_structHeap _99a2ca55_structHeap(GreenStructHeap* value) { return REDGPU_NP_STRUCT_INIT(_s_99a2ca55_structHeap){value}; }
static inline _s_99a2ca55_optionalFile _99a2ca55_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_99a2ca55_optionalFile){value}; }
static inline _s_99a2ca55_optionalLine _99a2ca55_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_99a2ca55_optionalLine){value}; }
static inline _s_99a2ca55_optionalUserData _99a2ca55_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_99a2ca55_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenStructHeapFree(_s_99a2ca55_context context, _s_99a2ca55_gpu gpu, _s_99a2ca55_structHeap structHeap, _s_99a2ca55_optionalFile optionalFile, _s_99a2ca55_optionalLine optionalLine, _s_99a2ca55_optionalUserData optionalUserData) {
  greenStructHeapFree(context.value, gpu.value, structHeap.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

