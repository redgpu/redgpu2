#pragma once

#ifndef REDGPU_NP_DECLSPEC
#define REDGPU_NP_DECLSPEC
#endif

#ifndef REDGPU_NP_API
#define REDGPU_NP_API
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
typedef struct _0a8a30e6_context { _0a8a30e6_context(RedContext value): value(value) {}; RedContext value; _0a8a30e6_context(const _0a8a30e6_context &) = delete; } _0a8a30e6_context;
typedef struct _0a8a30e6_gpu { _0a8a30e6_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _0a8a30e6_gpu(const _0a8a30e6_gpu &) = delete; } _0a8a30e6_gpu;
typedef struct _0a8a30e6_handleName { _0a8a30e6_handleName(char* value): value(value) {}; char* value; _0a8a30e6_handleName(const _0a8a30e6_handleName &) = delete; } _0a8a30e6_handleName;
typedef struct _0a8a30e6_outStructDeclaration { _0a8a30e6_outStructDeclaration(GreenStructDeclaration* value): value(value) {}; GreenStructDeclaration* value; _0a8a30e6_outStructDeclaration(const _0a8a30e6_outStructDeclaration &) = delete; } _0a8a30e6_outStructDeclaration;
typedef struct _0a8a30e6_outStatuses { _0a8a30e6_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _0a8a30e6_outStatuses(const _0a8a30e6_outStatuses &) = delete; } _0a8a30e6_outStatuses;
typedef struct _0a8a30e6_optionalFile { _0a8a30e6_optionalFile(char* value): value(value) {}; char* value; _0a8a30e6_optionalFile(const _0a8a30e6_optionalFile &) = delete; } _0a8a30e6_optionalFile;
typedef struct _0a8a30e6_optionalLine { _0a8a30e6_optionalLine(int value): value(value) {}; int value; _0a8a30e6_optionalLine(const _0a8a30e6_optionalLine &) = delete; } _0a8a30e6_optionalLine;
typedef struct _0a8a30e6_optionalUserData { _0a8a30e6_optionalUserData(void* value): value(value) {}; void* value; _0a8a30e6_optionalUserData(const _0a8a30e6_optionalUserData &) = delete; } _0a8a30e6_optionalUserData;
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenCreateStructDeclaration(_0a8a30e6_context & context, _0a8a30e6_gpu & gpu, _0a8a30e6_handleName & handleName, _0a8a30e6_outStructDeclaration & outStructDeclaration, _0a8a30e6_outStatuses & outStatuses, _0a8a30e6_optionalFile & optionalFile, _0a8a30e6_optionalLine & optionalLine, _0a8a30e6_optionalUserData & optionalUserData) {
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
typedef struct _9ceb9cf5_context { _9ceb9cf5_context(RedContext value): value(value) {}; RedContext value; _9ceb9cf5_context(const _9ceb9cf5_context &) = delete; } _9ceb9cf5_context;
typedef struct _9ceb9cf5_gpu { _9ceb9cf5_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _9ceb9cf5_gpu(const _9ceb9cf5_gpu &) = delete; } _9ceb9cf5_gpu;
typedef struct _9ceb9cf5_handleName { _9ceb9cf5_handleName(char* value): value(value) {}; char* value; _9ceb9cf5_handleName(const _9ceb9cf5_handleName &) = delete; } _9ceb9cf5_handleName;
typedef struct _9ceb9cf5_structDeclarationsCount { _9ceb9cf5_structDeclarationsCount(unsigned value): value(value) {}; unsigned value; _9ceb9cf5_structDeclarationsCount(const _9ceb9cf5_structDeclarationsCount &) = delete; } _9ceb9cf5_structDeclarationsCount;
typedef struct _9ceb9cf5_structDeclarations { _9ceb9cf5_structDeclarations(GreenStructDeclaration* value): value(value) {}; GreenStructDeclaration* value; _9ceb9cf5_structDeclarations(const _9ceb9cf5_structDeclarations &) = delete; } _9ceb9cf5_structDeclarations;
typedef struct _9ceb9cf5_outStructHeap { _9ceb9cf5_outStructHeap(GreenStructHeap* value): value(value) {}; GreenStructHeap* value; _9ceb9cf5_outStructHeap(const _9ceb9cf5_outStructHeap &) = delete; } _9ceb9cf5_outStructHeap;
typedef struct _9ceb9cf5_outStatuses { _9ceb9cf5_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _9ceb9cf5_outStatuses(const _9ceb9cf5_outStatuses &) = delete; } _9ceb9cf5_outStatuses;
typedef struct _9ceb9cf5_optionalFile { _9ceb9cf5_optionalFile(char* value): value(value) {}; char* value; _9ceb9cf5_optionalFile(const _9ceb9cf5_optionalFile &) = delete; } _9ceb9cf5_optionalFile;
typedef struct _9ceb9cf5_optionalLine { _9ceb9cf5_optionalLine(int value): value(value) {}; int value; _9ceb9cf5_optionalLine(const _9ceb9cf5_optionalLine &) = delete; } _9ceb9cf5_optionalLine;
typedef struct _9ceb9cf5_optionalUserData { _9ceb9cf5_optionalUserData(void* value): value(value) {}; void* value; _9ceb9cf5_optionalUserData(const _9ceb9cf5_optionalUserData &) = delete; } _9ceb9cf5_optionalUserData;
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenStructHeapAllocate(_9ceb9cf5_context & context, _9ceb9cf5_gpu & gpu, _9ceb9cf5_handleName & handleName, _9ceb9cf5_structDeclarationsCount & structDeclarationsCount, _9ceb9cf5_structDeclarations & structDeclarations, _9ceb9cf5_outStructHeap & outStructHeap, _9ceb9cf5_outStatuses & outStatuses, _9ceb9cf5_optionalFile & optionalFile, _9ceb9cf5_optionalLine & optionalLine, _9ceb9cf5_optionalUserData & optionalUserData) {
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
typedef struct _fa1824e1_context { _fa1824e1_context(RedContext value): value(value) {}; RedContext value; _fa1824e1_context(const _fa1824e1_context &) = delete; } _fa1824e1_context;
typedef struct _fa1824e1_gpu { _fa1824e1_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _fa1824e1_gpu(const _fa1824e1_gpu &) = delete; } _fa1824e1_gpu;
typedef struct _fa1824e1_structDeclarationsCount { _fa1824e1_structDeclarationsCount(unsigned value): value(value) {}; unsigned value; _fa1824e1_structDeclarationsCount(const _fa1824e1_structDeclarationsCount &) = delete; } _fa1824e1_structDeclarationsCount;
typedef struct _fa1824e1_structDeclarations { _fa1824e1_structDeclarations(GreenStructDeclaration* value): value(value) {}; GreenStructDeclaration* value; _fa1824e1_structDeclarations(const _fa1824e1_structDeclarations &) = delete; } _fa1824e1_structDeclarations;
typedef struct _fa1824e1_outStructHeap { _fa1824e1_outStructHeap(GreenStructHeap* value): value(value) {}; GreenStructHeap* value; _fa1824e1_outStructHeap(const _fa1824e1_outStructHeap &) = delete; } _fa1824e1_outStructHeap;
typedef struct _fa1824e1_outStatuses { _fa1824e1_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _fa1824e1_outStatuses(const _fa1824e1_outStatuses &) = delete; } _fa1824e1_outStatuses;
typedef struct _fa1824e1_optionalFile { _fa1824e1_optionalFile(char* value): value(value) {}; char* value; _fa1824e1_optionalFile(const _fa1824e1_optionalFile &) = delete; } _fa1824e1_optionalFile;
typedef struct _fa1824e1_optionalLine { _fa1824e1_optionalLine(int value): value(value) {}; int value; _fa1824e1_optionalLine(const _fa1824e1_optionalLine &) = delete; } _fa1824e1_optionalLine;
typedef struct _fa1824e1_optionalUserData { _fa1824e1_optionalUserData(void* value): value(value) {}; void* value; _fa1824e1_optionalUserData(const _fa1824e1_optionalUserData &) = delete; } _fa1824e1_optionalUserData;
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenStructHeapReset(_fa1824e1_context & context, _fa1824e1_gpu & gpu, _fa1824e1_structDeclarationsCount & structDeclarationsCount, _fa1824e1_structDeclarations & structDeclarations, _fa1824e1_outStructHeap & outStructHeap, _fa1824e1_outStatuses & outStatuses, _fa1824e1_optionalFile & optionalFile, _fa1824e1_optionalLine & optionalLine, _fa1824e1_optionalUserData & optionalUserData) {
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
typedef struct _6a2e38c0_context { _6a2e38c0_context(RedContext value): value(value) {}; RedContext value; _6a2e38c0_context(const _6a2e38c0_context &) = delete; } _6a2e38c0_context;
typedef struct _6a2e38c0_gpu { _6a2e38c0_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _6a2e38c0_gpu(const _6a2e38c0_gpu &) = delete; } _6a2e38c0_gpu;
typedef struct _6a2e38c0_structHeapsSetsCount { _6a2e38c0_structHeapsSetsCount(unsigned value): value(value) {}; unsigned value; _6a2e38c0_structHeapsSetsCount(const _6a2e38c0_structHeapsSetsCount &) = delete; } _6a2e38c0_structHeapsSetsCount;
typedef struct _6a2e38c0_structHeapsSets { _6a2e38c0_structHeapsSets(GreenStructHeapSet* value): value(value) {}; GreenStructHeapSet* value; _6a2e38c0_structHeapsSets(const _6a2e38c0_structHeapsSets &) = delete; } _6a2e38c0_structHeapsSets;
typedef struct _6a2e38c0_optionalFile { _6a2e38c0_optionalFile(char* value): value(value) {}; char* value; _6a2e38c0_optionalFile(const _6a2e38c0_optionalFile &) = delete; } _6a2e38c0_optionalFile;
typedef struct _6a2e38c0_optionalLine { _6a2e38c0_optionalLine(int value): value(value) {}; int value; _6a2e38c0_optionalLine(const _6a2e38c0_optionalLine &) = delete; } _6a2e38c0_optionalLine;
typedef struct _6a2e38c0_optionalUserData { _6a2e38c0_optionalUserData(void* value): value(value) {}; void* value; _6a2e38c0_optionalUserData(const _6a2e38c0_optionalUserData &) = delete; } _6a2e38c0_optionalUserData;
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenStructHeapsSet(_6a2e38c0_context & context, _6a2e38c0_gpu & gpu, _6a2e38c0_structHeapsSetsCount & structHeapsSetsCount, _6a2e38c0_structHeapsSets & structHeapsSets, _6a2e38c0_optionalFile & optionalFile, _6a2e38c0_optionalLine & optionalLine, _6a2e38c0_optionalUserData & optionalUserData) {
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
typedef struct _56605c20_context { _56605c20_context(RedContext value): value(value) {}; RedContext value; _56605c20_context(const _56605c20_context &) = delete; } _56605c20_context;
typedef struct _56605c20_gpu { _56605c20_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _56605c20_gpu(const _56605c20_gpu &) = delete; } _56605c20_gpu;
typedef struct _56605c20_structHeap { _56605c20_structHeap(GreenStructHeap* value): value(value) {}; GreenStructHeap* value; _56605c20_structHeap(const _56605c20_structHeap &) = delete; } _56605c20_structHeap;
typedef struct _56605c20_optionalFile { _56605c20_optionalFile(char* value): value(value) {}; char* value; _56605c20_optionalFile(const _56605c20_optionalFile &) = delete; } _56605c20_optionalFile;
typedef struct _56605c20_optionalLine { _56605c20_optionalLine(int value): value(value) {}; int value; _56605c20_optionalLine(const _56605c20_optionalLine &) = delete; } _56605c20_optionalLine;
typedef struct _56605c20_optionalUserData { _56605c20_optionalUserData(void* value): value(value) {}; void* value; _56605c20_optionalUserData(const _56605c20_optionalUserData &) = delete; } _56605c20_optionalUserData;
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_greenStructHeapFree(_56605c20_context & context, _56605c20_gpu & gpu, _56605c20_structHeap & structHeap, _56605c20_optionalFile & optionalFile, _56605c20_optionalLine & optionalLine, _56605c20_optionalUserData & optionalUserData) {
  greenStructHeapFree(context.value, gpu.value, structHeap.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

