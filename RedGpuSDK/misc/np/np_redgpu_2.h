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
#define np_red2CreateStructDeclaration red2CreateStructDeclaration
#define _bb034666_context(value) value
#define _bb034666_gpu(value) value
#define _bb034666_handleName(value) value
#define _bb034666_structDeclarationMembersCount(value) value
#define _bb034666_structDeclarationMembers(value) value
#define _bb034666_structDeclarationMembersArrayROCount(value) value
#define _bb034666_structDeclarationMembersArrayRO(value) value
#define _bb034666_procedureParametersHandlesDeclaration(value) value
#define _bb034666_outStructDeclaration(value) value
#define _bb034666_outStatuses(value) value
#define _bb034666_optionalFile(value) value
#define _bb034666_optionalLine(value) value
#define _bb034666_optionalUserData(value) value
#else
typedef struct _s_bb034666_context { RedContext value; } _s_bb034666_context;
typedef struct _s_bb034666_gpu { RedHandleGpu value; } _s_bb034666_gpu;
typedef struct _s_bb034666_handleName { char* value; } _s_bb034666_handleName;
typedef struct _s_bb034666_structDeclarationMembersCount { unsigned value; } _s_bb034666_structDeclarationMembersCount;
typedef struct _s_bb034666_structDeclarationMembers { RedStructDeclarationMember* value; } _s_bb034666_structDeclarationMembers;
typedef struct _s_bb034666_structDeclarationMembersArrayROCount { unsigned value; } _s_bb034666_structDeclarationMembersArrayROCount;
typedef struct _s_bb034666_structDeclarationMembersArrayRO { RedStructDeclarationMemberArrayRO* value; } _s_bb034666_structDeclarationMembersArrayRO;
typedef struct _s_bb034666_procedureParametersHandlesDeclaration { RedBool32 value; } _s_bb034666_procedureParametersHandlesDeclaration;
typedef struct _s_bb034666_outStructDeclaration { Red2HandleStructDeclaration* value; } _s_bb034666_outStructDeclaration;
typedef struct _s_bb034666_outStatuses { RedStatuses* value; } _s_bb034666_outStatuses;
typedef struct _s_bb034666_optionalFile { char* value; } _s_bb034666_optionalFile;
typedef struct _s_bb034666_optionalLine { int value; } _s_bb034666_optionalLine;
typedef struct _s_bb034666_optionalUserData { void* value; } _s_bb034666_optionalUserData;
static inline _s_bb034666_context _bb034666_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_context){value}; }
static inline _s_bb034666_gpu _bb034666_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_gpu){value}; }
static inline _s_bb034666_handleName _bb034666_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_handleName){value}; }
static inline _s_bb034666_structDeclarationMembersCount _bb034666_structDeclarationMembersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_structDeclarationMembersCount){value}; }
static inline _s_bb034666_structDeclarationMembers _bb034666_structDeclarationMembers(RedStructDeclarationMember* value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_structDeclarationMembers){value}; }
static inline _s_bb034666_structDeclarationMembersArrayROCount _bb034666_structDeclarationMembersArrayROCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_structDeclarationMembersArrayROCount){value}; }
static inline _s_bb034666_structDeclarationMembersArrayRO _bb034666_structDeclarationMembersArrayRO(RedStructDeclarationMemberArrayRO* value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_structDeclarationMembersArrayRO){value}; }
static inline _s_bb034666_procedureParametersHandlesDeclaration _bb034666_procedureParametersHandlesDeclaration(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_procedureParametersHandlesDeclaration){value}; }
static inline _s_bb034666_outStructDeclaration _bb034666_outStructDeclaration(Red2HandleStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_outStructDeclaration){value}; }
static inline _s_bb034666_outStatuses _bb034666_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_outStatuses){value}; }
static inline _s_bb034666_optionalFile _bb034666_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_optionalFile){value}; }
static inline _s_bb034666_optionalLine _bb034666_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_optionalLine){value}; }
static inline _s_bb034666_optionalUserData _bb034666_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bb034666_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CreateStructDeclaration(_s_bb034666_context context, _s_bb034666_gpu gpu, _s_bb034666_handleName handleName, _s_bb034666_structDeclarationMembersCount structDeclarationMembersCount, _s_bb034666_structDeclarationMembers structDeclarationMembers, _s_bb034666_structDeclarationMembersArrayROCount structDeclarationMembersArrayROCount, _s_bb034666_structDeclarationMembersArrayRO structDeclarationMembersArrayRO, _s_bb034666_procedureParametersHandlesDeclaration procedureParametersHandlesDeclaration, _s_bb034666_outStructDeclaration outStructDeclaration, _s_bb034666_outStatuses outStatuses, _s_bb034666_optionalFile optionalFile, _s_bb034666_optionalLine optionalLine, _s_bb034666_optionalUserData optionalUserData) {
  red2CreateStructDeclaration(context.value, gpu.value, handleName.value, structDeclarationMembersCount.value, structDeclarationMembers.value, structDeclarationMembersArrayROCount.value, structDeclarationMembersArrayRO.value, procedureParametersHandlesDeclaration.value, outStructDeclaration.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CreateProcedureParameters red2CreateProcedureParameters
#define _17a23de7_context(value) value
#define _17a23de7_gpu(value) value
#define _17a23de7_handleName(value) value
#define _17a23de7_procedureParametersDeclaration(value) value
#define _17a23de7_outProcedureParameters(value) value
#define _17a23de7_outStatuses(value) value
#define _17a23de7_optionalFile(value) value
#define _17a23de7_optionalLine(value) value
#define _17a23de7_optionalUserData(value) value
#else
typedef struct _s_17a23de7_context { RedContext value; } _s_17a23de7_context;
typedef struct _s_17a23de7_gpu { RedHandleGpu value; } _s_17a23de7_gpu;
typedef struct _s_17a23de7_handleName { char* value; } _s_17a23de7_handleName;
typedef struct _s_17a23de7_procedureParametersDeclaration { Red2ProcedureParametersDeclaration* value; } _s_17a23de7_procedureParametersDeclaration;
typedef struct _s_17a23de7_outProcedureParameters { Red2HandleProcedureParameters* value; } _s_17a23de7_outProcedureParameters;
typedef struct _s_17a23de7_outStatuses { RedStatuses* value; } _s_17a23de7_outStatuses;
typedef struct _s_17a23de7_optionalFile { char* value; } _s_17a23de7_optionalFile;
typedef struct _s_17a23de7_optionalLine { int value; } _s_17a23de7_optionalLine;
typedef struct _s_17a23de7_optionalUserData { void* value; } _s_17a23de7_optionalUserData;
static inline _s_17a23de7_context _17a23de7_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_17a23de7_context){value}; }
static inline _s_17a23de7_gpu _17a23de7_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_17a23de7_gpu){value}; }
static inline _s_17a23de7_handleName _17a23de7_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_17a23de7_handleName){value}; }
static inline _s_17a23de7_procedureParametersDeclaration _17a23de7_procedureParametersDeclaration(Red2ProcedureParametersDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_17a23de7_procedureParametersDeclaration){value}; }
static inline _s_17a23de7_outProcedureParameters _17a23de7_outProcedureParameters(Red2HandleProcedureParameters* value) { return REDGPU_NP_STRUCT_INIT(_s_17a23de7_outProcedureParameters){value}; }
static inline _s_17a23de7_outStatuses _17a23de7_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_17a23de7_outStatuses){value}; }
static inline _s_17a23de7_optionalFile _17a23de7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_17a23de7_optionalFile){value}; }
static inline _s_17a23de7_optionalLine _17a23de7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_17a23de7_optionalLine){value}; }
static inline _s_17a23de7_optionalUserData _17a23de7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_17a23de7_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CreateProcedureParameters(_s_17a23de7_context context, _s_17a23de7_gpu gpu, _s_17a23de7_handleName handleName, _s_17a23de7_procedureParametersDeclaration procedureParametersDeclaration, _s_17a23de7_outProcedureParameters outProcedureParameters, _s_17a23de7_outStatuses outStatuses, _s_17a23de7_optionalFile optionalFile, _s_17a23de7_optionalLine optionalLine, _s_17a23de7_optionalUserData optionalUserData) {
  red2CreateProcedureParameters(context.value, gpu.value, handleName.value, procedureParametersDeclaration.value, outProcedureParameters.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CreateCalls red2CreateCalls
#define _753703ab_context(value) value
#define _753703ab_gpu(value) value
#define _753703ab_handleName(value) value
#define _753703ab_queueFamilyIndex(value) value
#define _753703ab_outCalls(value) value
#define _753703ab_outStatuses(value) value
#define _753703ab_optionalFile(value) value
#define _753703ab_optionalLine(value) value
#define _753703ab_optionalUserData(value) value
#else
typedef struct _s_753703ab_context { RedContext value; } _s_753703ab_context;
typedef struct _s_753703ab_gpu { RedHandleGpu value; } _s_753703ab_gpu;
typedef struct _s_753703ab_handleName { char* value; } _s_753703ab_handleName;
typedef struct _s_753703ab_queueFamilyIndex { unsigned value; } _s_753703ab_queueFamilyIndex;
typedef struct _s_753703ab_outCalls { Red2HandleCalls* value; } _s_753703ab_outCalls;
typedef struct _s_753703ab_outStatuses { RedStatuses* value; } _s_753703ab_outStatuses;
typedef struct _s_753703ab_optionalFile { char* value; } _s_753703ab_optionalFile;
typedef struct _s_753703ab_optionalLine { int value; } _s_753703ab_optionalLine;
typedef struct _s_753703ab_optionalUserData { void* value; } _s_753703ab_optionalUserData;
static inline _s_753703ab_context _753703ab_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_753703ab_context){value}; }
static inline _s_753703ab_gpu _753703ab_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_753703ab_gpu){value}; }
static inline _s_753703ab_handleName _753703ab_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_753703ab_handleName){value}; }
static inline _s_753703ab_queueFamilyIndex _753703ab_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_753703ab_queueFamilyIndex){value}; }
static inline _s_753703ab_outCalls _753703ab_outCalls(Red2HandleCalls* value) { return REDGPU_NP_STRUCT_INIT(_s_753703ab_outCalls){value}; }
static inline _s_753703ab_outStatuses _753703ab_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_753703ab_outStatuses){value}; }
static inline _s_753703ab_optionalFile _753703ab_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_753703ab_optionalFile){value}; }
static inline _s_753703ab_optionalLine _753703ab_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_753703ab_optionalLine){value}; }
static inline _s_753703ab_optionalUserData _753703ab_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_753703ab_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CreateCalls(_s_753703ab_context context, _s_753703ab_gpu gpu, _s_753703ab_handleName handleName, _s_753703ab_queueFamilyIndex queueFamilyIndex, _s_753703ab_outCalls outCalls, _s_753703ab_outStatuses outStatuses, _s_753703ab_optionalFile optionalFile, _s_753703ab_optionalLine optionalLine, _s_753703ab_optionalUserData optionalUserData) {
  red2CreateCalls(context.value, gpu.value, handleName.value, queueFamilyIndex.value, outCalls.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CreateCallsReusable red2CreateCallsReusable
#define _332a5351_context(value) value
#define _332a5351_gpu(value) value
#define _332a5351_handleName(value) value
#define _332a5351_queueFamilyIndex(value) value
#define _332a5351_outCalls(value) value
#define _332a5351_outStatuses(value) value
#define _332a5351_optionalFile(value) value
#define _332a5351_optionalLine(value) value
#define _332a5351_optionalUserData(value) value
#else
typedef struct _s_332a5351_context { RedContext value; } _s_332a5351_context;
typedef struct _s_332a5351_gpu { RedHandleGpu value; } _s_332a5351_gpu;
typedef struct _s_332a5351_handleName { char* value; } _s_332a5351_handleName;
typedef struct _s_332a5351_queueFamilyIndex { unsigned value; } _s_332a5351_queueFamilyIndex;
typedef struct _s_332a5351_outCalls { Red2HandleCalls* value; } _s_332a5351_outCalls;
typedef struct _s_332a5351_outStatuses { RedStatuses* value; } _s_332a5351_outStatuses;
typedef struct _s_332a5351_optionalFile { char* value; } _s_332a5351_optionalFile;
typedef struct _s_332a5351_optionalLine { int value; } _s_332a5351_optionalLine;
typedef struct _s_332a5351_optionalUserData { void* value; } _s_332a5351_optionalUserData;
static inline _s_332a5351_context _332a5351_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_332a5351_context){value}; }
static inline _s_332a5351_gpu _332a5351_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_332a5351_gpu){value}; }
static inline _s_332a5351_handleName _332a5351_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_332a5351_handleName){value}; }
static inline _s_332a5351_queueFamilyIndex _332a5351_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_332a5351_queueFamilyIndex){value}; }
static inline _s_332a5351_outCalls _332a5351_outCalls(Red2HandleCalls* value) { return REDGPU_NP_STRUCT_INIT(_s_332a5351_outCalls){value}; }
static inline _s_332a5351_outStatuses _332a5351_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_332a5351_outStatuses){value}; }
static inline _s_332a5351_optionalFile _332a5351_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_332a5351_optionalFile){value}; }
static inline _s_332a5351_optionalLine _332a5351_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_332a5351_optionalLine){value}; }
static inline _s_332a5351_optionalUserData _332a5351_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_332a5351_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CreateCallsReusable(_s_332a5351_context context, _s_332a5351_gpu gpu, _s_332a5351_handleName handleName, _s_332a5351_queueFamilyIndex queueFamilyIndex, _s_332a5351_outCalls outCalls, _s_332a5351_outStatuses outStatuses, _s_332a5351_optionalFile optionalFile, _s_332a5351_optionalLine optionalLine, _s_332a5351_optionalUserData optionalUserData) {
  red2CreateCallsReusable(context.value, gpu.value, handleName.value, queueFamilyIndex.value, outCalls.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CreateWsiTransientGpuSignal red2CreateWsiTransientGpuSignal
#define _e543ba9d_context(value) value
#define _e543ba9d_gpu(value) value
#define _e543ba9d_present(value) value
#define _e543ba9d_presentImageIndex(value) value
#define _e543ba9d_outGpuSignal(value) value
#define _e543ba9d_outStatuses(value) value
#define _e543ba9d_optionalFile(value) value
#define _e543ba9d_optionalLine(value) value
#define _e543ba9d_optionalUserData(value) value
#else
typedef struct _s_e543ba9d_context { RedContext value; } _s_e543ba9d_context;
typedef struct _s_e543ba9d_gpu { RedHandleGpu value; } _s_e543ba9d_gpu;
typedef struct _s_e543ba9d_present { RedHandlePresent value; } _s_e543ba9d_present;
typedef struct _s_e543ba9d_presentImageIndex { unsigned value; } _s_e543ba9d_presentImageIndex;
typedef struct _s_e543ba9d_outGpuSignal { RedHandleGpuSignal* value; } _s_e543ba9d_outGpuSignal;
typedef struct _s_e543ba9d_outStatuses { RedStatuses* value; } _s_e543ba9d_outStatuses;
typedef struct _s_e543ba9d_optionalFile { char* value; } _s_e543ba9d_optionalFile;
typedef struct _s_e543ba9d_optionalLine { int value; } _s_e543ba9d_optionalLine;
typedef struct _s_e543ba9d_optionalUserData { void* value; } _s_e543ba9d_optionalUserData;
static inline _s_e543ba9d_context _e543ba9d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_e543ba9d_context){value}; }
static inline _s_e543ba9d_gpu _e543ba9d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_e543ba9d_gpu){value}; }
static inline _s_e543ba9d_present _e543ba9d_present(RedHandlePresent value) { return REDGPU_NP_STRUCT_INIT(_s_e543ba9d_present){value}; }
static inline _s_e543ba9d_presentImageIndex _e543ba9d_presentImageIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e543ba9d_presentImageIndex){value}; }
static inline _s_e543ba9d_outGpuSignal _e543ba9d_outGpuSignal(RedHandleGpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_e543ba9d_outGpuSignal){value}; }
static inline _s_e543ba9d_outStatuses _e543ba9d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_e543ba9d_outStatuses){value}; }
static inline _s_e543ba9d_optionalFile _e543ba9d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e543ba9d_optionalFile){value}; }
static inline _s_e543ba9d_optionalLine _e543ba9d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e543ba9d_optionalLine){value}; }
static inline _s_e543ba9d_optionalUserData _e543ba9d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e543ba9d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CreateWsiTransientGpuSignal(_s_e543ba9d_context context, _s_e543ba9d_gpu gpu, _s_e543ba9d_present present, _s_e543ba9d_presentImageIndex presentImageIndex, _s_e543ba9d_outGpuSignal outGpuSignal, _s_e543ba9d_outStatuses outStatuses, _s_e543ba9d_optionalFile optionalFile, _s_e543ba9d_optionalLine optionalLine, _s_e543ba9d_optionalUserData optionalUserData) {
  red2CreateWsiTransientGpuSignal(context.value, gpu.value, present.value, presentImageIndex.value, outGpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2DestroyContext red2DestroyContext
#define _13f40eb7_context(value) value
#define _13f40eb7_optionalFile(value) value
#define _13f40eb7_optionalLine(value) value
#define _13f40eb7_optionalUserData(value) value
#else
typedef struct _s_13f40eb7_context { RedContext value; } _s_13f40eb7_context;
typedef struct _s_13f40eb7_optionalFile { char* value; } _s_13f40eb7_optionalFile;
typedef struct _s_13f40eb7_optionalLine { int value; } _s_13f40eb7_optionalLine;
typedef struct _s_13f40eb7_optionalUserData { void* value; } _s_13f40eb7_optionalUserData;
static inline _s_13f40eb7_context _13f40eb7_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_13f40eb7_context){value}; }
static inline _s_13f40eb7_optionalFile _13f40eb7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_13f40eb7_optionalFile){value}; }
static inline _s_13f40eb7_optionalLine _13f40eb7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_13f40eb7_optionalLine){value}; }
static inline _s_13f40eb7_optionalUserData _13f40eb7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_13f40eb7_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2DestroyContext(_s_13f40eb7_context context, _s_13f40eb7_optionalFile optionalFile, _s_13f40eb7_optionalLine optionalLine, _s_13f40eb7_optionalUserData optionalUserData) {
  red2DestroyContext(context.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2DestroyStructDeclaration red2DestroyStructDeclaration
#define _3fe428f5_context(value) value
#define _3fe428f5_gpu(value) value
#define _3fe428f5_structDeclaration(value) value
#define _3fe428f5_optionalFile(value) value
#define _3fe428f5_optionalLine(value) value
#define _3fe428f5_optionalUserData(value) value
#else
typedef struct _s_3fe428f5_context { RedContext value; } _s_3fe428f5_context;
typedef struct _s_3fe428f5_gpu { RedHandleGpu value; } _s_3fe428f5_gpu;
typedef struct _s_3fe428f5_structDeclaration { Red2HandleStructDeclaration value; } _s_3fe428f5_structDeclaration;
typedef struct _s_3fe428f5_optionalFile { char* value; } _s_3fe428f5_optionalFile;
typedef struct _s_3fe428f5_optionalLine { int value; } _s_3fe428f5_optionalLine;
typedef struct _s_3fe428f5_optionalUserData { void* value; } _s_3fe428f5_optionalUserData;
static inline _s_3fe428f5_context _3fe428f5_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_3fe428f5_context){value}; }
static inline _s_3fe428f5_gpu _3fe428f5_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_3fe428f5_gpu){value}; }
static inline _s_3fe428f5_structDeclaration _3fe428f5_structDeclaration(Red2HandleStructDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_3fe428f5_structDeclaration){value}; }
static inline _s_3fe428f5_optionalFile _3fe428f5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3fe428f5_optionalFile){value}; }
static inline _s_3fe428f5_optionalLine _3fe428f5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3fe428f5_optionalLine){value}; }
static inline _s_3fe428f5_optionalUserData _3fe428f5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3fe428f5_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2DestroyStructDeclaration(_s_3fe428f5_context context, _s_3fe428f5_gpu gpu, _s_3fe428f5_structDeclaration structDeclaration, _s_3fe428f5_optionalFile optionalFile, _s_3fe428f5_optionalLine optionalLine, _s_3fe428f5_optionalUserData optionalUserData) {
  red2DestroyStructDeclaration(context.value, gpu.value, structDeclaration.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2DestroyProcedureParameters red2DestroyProcedureParameters
#define _b1f14423_context(value) value
#define _b1f14423_gpu(value) value
#define _b1f14423_procedureParameters(value) value
#define _b1f14423_optionalFile(value) value
#define _b1f14423_optionalLine(value) value
#define _b1f14423_optionalUserData(value) value
#else
typedef struct _s_b1f14423_context { RedContext value; } _s_b1f14423_context;
typedef struct _s_b1f14423_gpu { RedHandleGpu value; } _s_b1f14423_gpu;
typedef struct _s_b1f14423_procedureParameters { Red2HandleProcedureParameters value; } _s_b1f14423_procedureParameters;
typedef struct _s_b1f14423_optionalFile { char* value; } _s_b1f14423_optionalFile;
typedef struct _s_b1f14423_optionalLine { int value; } _s_b1f14423_optionalLine;
typedef struct _s_b1f14423_optionalUserData { void* value; } _s_b1f14423_optionalUserData;
static inline _s_b1f14423_context _b1f14423_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b1f14423_context){value}; }
static inline _s_b1f14423_gpu _b1f14423_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b1f14423_gpu){value}; }
static inline _s_b1f14423_procedureParameters _b1f14423_procedureParameters(Red2HandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_b1f14423_procedureParameters){value}; }
static inline _s_b1f14423_optionalFile _b1f14423_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b1f14423_optionalFile){value}; }
static inline _s_b1f14423_optionalLine _b1f14423_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b1f14423_optionalLine){value}; }
static inline _s_b1f14423_optionalUserData _b1f14423_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b1f14423_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2DestroyProcedureParameters(_s_b1f14423_context context, _s_b1f14423_gpu gpu, _s_b1f14423_procedureParameters procedureParameters, _s_b1f14423_optionalFile optionalFile, _s_b1f14423_optionalLine optionalLine, _s_b1f14423_optionalUserData optionalUserData) {
  red2DestroyProcedureParameters(context.value, gpu.value, procedureParameters.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2DestroyCalls red2DestroyCalls
#define _96650f21_context(value) value
#define _96650f21_gpu(value) value
#define _96650f21_calls(value) value
#define _96650f21_optionalFile(value) value
#define _96650f21_optionalLine(value) value
#define _96650f21_optionalUserData(value) value
#else
typedef struct _s_96650f21_context { RedContext value; } _s_96650f21_context;
typedef struct _s_96650f21_gpu { RedHandleGpu value; } _s_96650f21_gpu;
typedef struct _s_96650f21_calls { Red2HandleCalls value; } _s_96650f21_calls;
typedef struct _s_96650f21_optionalFile { char* value; } _s_96650f21_optionalFile;
typedef struct _s_96650f21_optionalLine { int value; } _s_96650f21_optionalLine;
typedef struct _s_96650f21_optionalUserData { void* value; } _s_96650f21_optionalUserData;
static inline _s_96650f21_context _96650f21_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_96650f21_context){value}; }
static inline _s_96650f21_gpu _96650f21_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_96650f21_gpu){value}; }
static inline _s_96650f21_calls _96650f21_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_96650f21_calls){value}; }
static inline _s_96650f21_optionalFile _96650f21_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_96650f21_optionalFile){value}; }
static inline _s_96650f21_optionalLine _96650f21_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_96650f21_optionalLine){value}; }
static inline _s_96650f21_optionalUserData _96650f21_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_96650f21_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2DestroyCalls(_s_96650f21_context context, _s_96650f21_gpu gpu, _s_96650f21_calls calls, _s_96650f21_optionalFile optionalFile, _s_96650f21_optionalLine optionalLine, _s_96650f21_optionalUserData optionalUserData) {
  red2DestroyCalls(context.value, gpu.value, calls.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2StructDeclarationGetRedHandle red2StructDeclarationGetRedHandle
#define _2153f1a3_structDeclaration(value) value
#else
typedef struct _s_2153f1a3_structDeclaration { Red2HandleStructDeclaration value; } _s_2153f1a3_structDeclaration;
static inline _s_2153f1a3_structDeclaration _2153f1a3_structDeclaration(Red2HandleStructDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_2153f1a3_structDeclaration){value}; }
REDGPU_NP_DECLSPEC RedHandleStructDeclaration REDGPU_NP_API np_red2StructDeclarationGetRedHandle(_s_2153f1a3_structDeclaration structDeclaration) {
  return red2StructDeclarationGetRedHandle(structDeclaration.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2StructDeclarationGetMembersPointer red2StructDeclarationGetMembersPointer
#define _0972167d_structDeclaration(value) value
#else
typedef struct _s_0972167d_structDeclaration { Red2HandleStructDeclaration value; } _s_0972167d_structDeclaration;
static inline _s_0972167d_structDeclaration _0972167d_structDeclaration(Red2HandleStructDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_0972167d_structDeclaration){value}; }
REDGPU_NP_DECLSPEC Red2StructDeclarationMember* REDGPU_NP_API np_red2StructDeclarationGetMembersPointer(_s_0972167d_structDeclaration structDeclaration) {
  return red2StructDeclarationGetMembersPointer(structDeclaration.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2StructDeclarationGetMembersCounts red2StructDeclarationGetMembersCounts
#define _76eca0f3_structDeclaration(value) value
#define _76eca0f3_outStructDeclarationMembersCount(value) value
#define _76eca0f3_outMembersOfTypeArrayROConstantCount(value) value
#define _76eca0f3_outMembersOfTypeArrayROOrArrayRWCount(value) value
#define _76eca0f3_outMembersOfTypeTextureROCount(value) value
#define _76eca0f3_outMembersOfTypeTextureRWCount(value) value
#define _76eca0f3_outMembersOfTypeInlineSamplerCount(value) value
#define _76eca0f3_outMembersOfTypeSamplerCount(value) value
#else
typedef struct _s_76eca0f3_structDeclaration { Red2HandleStructDeclaration value; } _s_76eca0f3_structDeclaration;
typedef struct _s_76eca0f3_outStructDeclarationMembersCount { unsigned* value; } _s_76eca0f3_outStructDeclarationMembersCount;
typedef struct _s_76eca0f3_outMembersOfTypeArrayROConstantCount { unsigned* value; } _s_76eca0f3_outMembersOfTypeArrayROConstantCount;
typedef struct _s_76eca0f3_outMembersOfTypeArrayROOrArrayRWCount { unsigned* value; } _s_76eca0f3_outMembersOfTypeArrayROOrArrayRWCount;
typedef struct _s_76eca0f3_outMembersOfTypeTextureROCount { unsigned* value; } _s_76eca0f3_outMembersOfTypeTextureROCount;
typedef struct _s_76eca0f3_outMembersOfTypeTextureRWCount { unsigned* value; } _s_76eca0f3_outMembersOfTypeTextureRWCount;
typedef struct _s_76eca0f3_outMembersOfTypeInlineSamplerCount { unsigned* value; } _s_76eca0f3_outMembersOfTypeInlineSamplerCount;
typedef struct _s_76eca0f3_outMembersOfTypeSamplerCount { unsigned* value; } _s_76eca0f3_outMembersOfTypeSamplerCount;
static inline _s_76eca0f3_structDeclaration _76eca0f3_structDeclaration(Red2HandleStructDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_76eca0f3_structDeclaration){value}; }
static inline _s_76eca0f3_outStructDeclarationMembersCount _76eca0f3_outStructDeclarationMembersCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_76eca0f3_outStructDeclarationMembersCount){value}; }
static inline _s_76eca0f3_outMembersOfTypeArrayROConstantCount _76eca0f3_outMembersOfTypeArrayROConstantCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_76eca0f3_outMembersOfTypeArrayROConstantCount){value}; }
static inline _s_76eca0f3_outMembersOfTypeArrayROOrArrayRWCount _76eca0f3_outMembersOfTypeArrayROOrArrayRWCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_76eca0f3_outMembersOfTypeArrayROOrArrayRWCount){value}; }
static inline _s_76eca0f3_outMembersOfTypeTextureROCount _76eca0f3_outMembersOfTypeTextureROCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_76eca0f3_outMembersOfTypeTextureROCount){value}; }
static inline _s_76eca0f3_outMembersOfTypeTextureRWCount _76eca0f3_outMembersOfTypeTextureRWCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_76eca0f3_outMembersOfTypeTextureRWCount){value}; }
static inline _s_76eca0f3_outMembersOfTypeInlineSamplerCount _76eca0f3_outMembersOfTypeInlineSamplerCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_76eca0f3_outMembersOfTypeInlineSamplerCount){value}; }
static inline _s_76eca0f3_outMembersOfTypeSamplerCount _76eca0f3_outMembersOfTypeSamplerCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_76eca0f3_outMembersOfTypeSamplerCount){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2StructDeclarationGetMembersCounts(_s_76eca0f3_structDeclaration structDeclaration, _s_76eca0f3_outStructDeclarationMembersCount outStructDeclarationMembersCount, _s_76eca0f3_outMembersOfTypeArrayROConstantCount outMembersOfTypeArrayROConstantCount, _s_76eca0f3_outMembersOfTypeArrayROOrArrayRWCount outMembersOfTypeArrayROOrArrayRWCount, _s_76eca0f3_outMembersOfTypeTextureROCount outMembersOfTypeTextureROCount, _s_76eca0f3_outMembersOfTypeTextureRWCount outMembersOfTypeTextureRWCount, _s_76eca0f3_outMembersOfTypeInlineSamplerCount outMembersOfTypeInlineSamplerCount, _s_76eca0f3_outMembersOfTypeSamplerCount outMembersOfTypeSamplerCount) {
  red2StructDeclarationGetMembersCounts(structDeclaration.value, outStructDeclarationMembersCount.value, outMembersOfTypeArrayROConstantCount.value, outMembersOfTypeArrayROOrArrayRWCount.value, outMembersOfTypeTextureROCount.value, outMembersOfTypeTextureRWCount.value, outMembersOfTypeInlineSamplerCount.value, outMembersOfTypeSamplerCount.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2ProcedureParametersGetRedHandle red2ProcedureParametersGetRedHandle
#define _65864a76_procedureParameters(value) value
#else
typedef struct _s_65864a76_procedureParameters { Red2HandleProcedureParameters value; } _s_65864a76_procedureParameters;
static inline _s_65864a76_procedureParameters _65864a76_procedureParameters(Red2HandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_65864a76_procedureParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleProcedureParameters REDGPU_NP_API np_red2ProcedureParametersGetRedHandle(_s_65864a76_procedureParameters procedureParameters) {
  return red2ProcedureParametersGetRedHandle(procedureParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2ProcedureParametersGetStructDeclaration red2ProcedureParametersGetStructDeclaration
#define _cc9bd4ed_procedureParameters(value) value
#define _cc9bd4ed_structIndex(value) value
#else
typedef struct _s_cc9bd4ed_procedureParameters { Red2HandleProcedureParameters value; } _s_cc9bd4ed_procedureParameters;
typedef struct _s_cc9bd4ed_structIndex { unsigned value; } _s_cc9bd4ed_structIndex;
static inline _s_cc9bd4ed_procedureParameters _cc9bd4ed_procedureParameters(Red2HandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_cc9bd4ed_procedureParameters){value}; }
static inline _s_cc9bd4ed_structIndex _cc9bd4ed_structIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cc9bd4ed_structIndex){value}; }
REDGPU_NP_DECLSPEC Red2HandleStructDeclaration REDGPU_NP_API np_red2ProcedureParametersGetStructDeclaration(_s_cc9bd4ed_procedureParameters procedureParameters, _s_cc9bd4ed_structIndex structIndex) {
  return red2ProcedureParametersGetStructDeclaration(procedureParameters.value, structIndex.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallsGetRedHandles red2CallsGetRedHandles
#define _d5feb6b3_calls(value) value
#define _d5feb6b3_outContext(value) value
#define _d5feb6b3_outGpu(value) value
#define _d5feb6b3_outCalls(value) value
#else
typedef struct _s_d5feb6b3_calls { Red2HandleCalls value; } _s_d5feb6b3_calls;
typedef struct _s_d5feb6b3_outContext { RedContext* value; } _s_d5feb6b3_outContext;
typedef struct _s_d5feb6b3_outGpu { RedHandleGpu* value; } _s_d5feb6b3_outGpu;
typedef struct _s_d5feb6b3_outCalls { RedCalls* value; } _s_d5feb6b3_outCalls;
static inline _s_d5feb6b3_calls _d5feb6b3_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_d5feb6b3_calls){value}; }
static inline _s_d5feb6b3_outContext _d5feb6b3_outContext(RedContext* value) { return REDGPU_NP_STRUCT_INIT(_s_d5feb6b3_outContext){value}; }
static inline _s_d5feb6b3_outGpu _d5feb6b3_outGpu(RedHandleGpu* value) { return REDGPU_NP_STRUCT_INIT(_s_d5feb6b3_outGpu){value}; }
static inline _s_d5feb6b3_outCalls _d5feb6b3_outCalls(RedCalls* value) { return REDGPU_NP_STRUCT_INIT(_s_d5feb6b3_outCalls){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallsGetRedHandles(_s_d5feb6b3_calls calls, _s_d5feb6b3_outContext outContext, _s_d5feb6b3_outGpu outGpu, _s_d5feb6b3_outCalls outCalls) {
  red2CallsGetRedHandles(calls.value, outContext.value, outGpu.value, outCalls.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallsSet red2CallsSet
#define _c9f69eaf_context(value) value
#define _c9f69eaf_gpu(value) value
#define _c9f69eaf_calls(value) value
#define _c9f69eaf_callsMemory(value) value
#define _c9f69eaf_callsReusable(value) value
#define _c9f69eaf_outStatuses(value) value
#define _c9f69eaf_optionalFile(value) value
#define _c9f69eaf_optionalLine(value) value
#define _c9f69eaf_optionalUserData(value) value
#else
typedef struct _s_c9f69eaf_context { RedContext value; } _s_c9f69eaf_context;
typedef struct _s_c9f69eaf_gpu { RedHandleGpu value; } _s_c9f69eaf_gpu;
typedef struct _s_c9f69eaf_calls { Red2HandleCalls value; } _s_c9f69eaf_calls;
typedef struct _s_c9f69eaf_callsMemory { RedHandleCallsMemory value; } _s_c9f69eaf_callsMemory;
typedef struct _s_c9f69eaf_callsReusable { RedBool32 value; } _s_c9f69eaf_callsReusable;
typedef struct _s_c9f69eaf_outStatuses { RedStatuses* value; } _s_c9f69eaf_outStatuses;
typedef struct _s_c9f69eaf_optionalFile { char* value; } _s_c9f69eaf_optionalFile;
typedef struct _s_c9f69eaf_optionalLine { int value; } _s_c9f69eaf_optionalLine;
typedef struct _s_c9f69eaf_optionalUserData { void* value; } _s_c9f69eaf_optionalUserData;
static inline _s_c9f69eaf_context _c9f69eaf_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_c9f69eaf_context){value}; }
static inline _s_c9f69eaf_gpu _c9f69eaf_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_c9f69eaf_gpu){value}; }
static inline _s_c9f69eaf_calls _c9f69eaf_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_c9f69eaf_calls){value}; }
static inline _s_c9f69eaf_callsMemory _c9f69eaf_callsMemory(RedHandleCallsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_c9f69eaf_callsMemory){value}; }
static inline _s_c9f69eaf_callsReusable _c9f69eaf_callsReusable(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_c9f69eaf_callsReusable){value}; }
static inline _s_c9f69eaf_outStatuses _c9f69eaf_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_c9f69eaf_outStatuses){value}; }
static inline _s_c9f69eaf_optionalFile _c9f69eaf_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c9f69eaf_optionalFile){value}; }
static inline _s_c9f69eaf_optionalLine _c9f69eaf_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c9f69eaf_optionalLine){value}; }
static inline _s_c9f69eaf_optionalUserData _c9f69eaf_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c9f69eaf_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallsSet(_s_c9f69eaf_context context, _s_c9f69eaf_gpu gpu, _s_c9f69eaf_calls calls, _s_c9f69eaf_callsMemory callsMemory, _s_c9f69eaf_callsReusable callsReusable, _s_c9f69eaf_outStatuses outStatuses, _s_c9f69eaf_optionalFile optionalFile, _s_c9f69eaf_optionalLine optionalLine, _s_c9f69eaf_optionalUserData optionalUserData) {
  red2CallsSet(context.value, gpu.value, calls.value, callsMemory.value, callsReusable.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallsEnd red2CallsEnd
#define _3257dcd9_context(value) value
#define _3257dcd9_gpu(value) value
#define _3257dcd9_calls(value) value
#define _3257dcd9_callsMemory(value) value
#define _3257dcd9_outStatuses(value) value
#define _3257dcd9_optionalFile(value) value
#define _3257dcd9_optionalLine(value) value
#define _3257dcd9_optionalUserData(value) value
#else
typedef struct _s_3257dcd9_context { RedContext value; } _s_3257dcd9_context;
typedef struct _s_3257dcd9_gpu { RedHandleGpu value; } _s_3257dcd9_gpu;
typedef struct _s_3257dcd9_calls { Red2HandleCalls value; } _s_3257dcd9_calls;
typedef struct _s_3257dcd9_callsMemory { RedHandleCallsMemory value; } _s_3257dcd9_callsMemory;
typedef struct _s_3257dcd9_outStatuses { RedStatuses* value; } _s_3257dcd9_outStatuses;
typedef struct _s_3257dcd9_optionalFile { char* value; } _s_3257dcd9_optionalFile;
typedef struct _s_3257dcd9_optionalLine { int value; } _s_3257dcd9_optionalLine;
typedef struct _s_3257dcd9_optionalUserData { void* value; } _s_3257dcd9_optionalUserData;
static inline _s_3257dcd9_context _3257dcd9_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_3257dcd9_context){value}; }
static inline _s_3257dcd9_gpu _3257dcd9_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_3257dcd9_gpu){value}; }
static inline _s_3257dcd9_calls _3257dcd9_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_3257dcd9_calls){value}; }
static inline _s_3257dcd9_callsMemory _3257dcd9_callsMemory(RedHandleCallsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_3257dcd9_callsMemory){value}; }
static inline _s_3257dcd9_outStatuses _3257dcd9_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_3257dcd9_outStatuses){value}; }
static inline _s_3257dcd9_optionalFile _3257dcd9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3257dcd9_optionalFile){value}; }
static inline _s_3257dcd9_optionalLine _3257dcd9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3257dcd9_optionalLine){value}; }
static inline _s_3257dcd9_optionalUserData _3257dcd9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3257dcd9_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallsEnd(_s_3257dcd9_context context, _s_3257dcd9_gpu gpu, _s_3257dcd9_calls calls, _s_3257dcd9_callsMemory callsMemory, _s_3257dcd9_outStatuses outStatuses, _s_3257dcd9_optionalFile optionalFile, _s_3257dcd9_optionalLine optionalLine, _s_3257dcd9_optionalUserData optionalUserData) {
  red2CallsEnd(context.value, gpu.value, calls.value, callsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallsFreeAllInlineStructsMemorys red2CallsFreeAllInlineStructsMemorys
#define _9746b348_context(value) value
#define _9746b348_gpu(value) value
#define _9746b348_calls(value) value
#define _9746b348_optionalFile(value) value
#define _9746b348_optionalLine(value) value
#define _9746b348_optionalUserData(value) value
#else
typedef struct _s_9746b348_context { RedContext value; } _s_9746b348_context;
typedef struct _s_9746b348_gpu { RedHandleGpu value; } _s_9746b348_gpu;
typedef struct _s_9746b348_calls { Red2HandleCalls value; } _s_9746b348_calls;
typedef struct _s_9746b348_optionalFile { char* value; } _s_9746b348_optionalFile;
typedef struct _s_9746b348_optionalLine { int value; } _s_9746b348_optionalLine;
typedef struct _s_9746b348_optionalUserData { void* value; } _s_9746b348_optionalUserData;
static inline _s_9746b348_context _9746b348_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_9746b348_context){value}; }
static inline _s_9746b348_gpu _9746b348_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_9746b348_gpu){value}; }
static inline _s_9746b348_calls _9746b348_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_9746b348_calls){value}; }
static inline _s_9746b348_optionalFile _9746b348_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9746b348_optionalFile){value}; }
static inline _s_9746b348_optionalLine _9746b348_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9746b348_optionalLine){value}; }
static inline _s_9746b348_optionalUserData _9746b348_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9746b348_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallsFreeAllInlineStructsMemorys(_s_9746b348_context context, _s_9746b348_gpu gpu, _s_9746b348_calls calls, _s_9746b348_optionalFile optionalFile, _s_9746b348_optionalLine optionalLine, _s_9746b348_optionalUserData optionalUserData) {
  red2CallsFreeAllInlineStructsMemorys(context.value, gpu.value, calls.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallAllocateAndSetInlineStructsMemory red2CallAllocateAndSetInlineStructsMemory
#define _8364a276_calls(value) value
#define _8364a276_structsMemoryHandleName(value) value
#define _8364a276_maxStructsCount(value) value
#define _8364a276_maxStructsOfTypeSamplerCount(value) value
#define _8364a276_maxStructsMembersOfTypeArrayROConstantCount(value) value
#define _8364a276_maxStructsMembersOfTypeArrayROOrArrayRWCount(value) value
#define _8364a276_maxStructsMembersOfTypeTextureROCount(value) value
#define _8364a276_maxStructsMembersOfTypeTextureRWCount(value) value
#define _8364a276_maxStructsMembersOfTypeInlineSamplerCount(value) value
#define _8364a276_maxStructsMembersOfTypeSamplerCount(value) value
#define _8364a276_outStatuses(value) value
#define _8364a276_optionalFile(value) value
#define _8364a276_optionalLine(value) value
#define _8364a276_optionalUserData(value) value
#else
typedef struct _s_8364a276_calls { Red2HandleCalls value; } _s_8364a276_calls;
typedef struct _s_8364a276_structsMemoryHandleName { char* value; } _s_8364a276_structsMemoryHandleName;
typedef struct _s_8364a276_maxStructsCount { unsigned value; } _s_8364a276_maxStructsCount;
typedef struct _s_8364a276_maxStructsOfTypeSamplerCount { unsigned value; } _s_8364a276_maxStructsOfTypeSamplerCount;
typedef struct _s_8364a276_maxStructsMembersOfTypeArrayROConstantCount { unsigned value; } _s_8364a276_maxStructsMembersOfTypeArrayROConstantCount;
typedef struct _s_8364a276_maxStructsMembersOfTypeArrayROOrArrayRWCount { unsigned value; } _s_8364a276_maxStructsMembersOfTypeArrayROOrArrayRWCount;
typedef struct _s_8364a276_maxStructsMembersOfTypeTextureROCount { unsigned value; } _s_8364a276_maxStructsMembersOfTypeTextureROCount;
typedef struct _s_8364a276_maxStructsMembersOfTypeTextureRWCount { unsigned value; } _s_8364a276_maxStructsMembersOfTypeTextureRWCount;
typedef struct _s_8364a276_maxStructsMembersOfTypeInlineSamplerCount { unsigned value; } _s_8364a276_maxStructsMembersOfTypeInlineSamplerCount;
typedef struct _s_8364a276_maxStructsMembersOfTypeSamplerCount { unsigned value; } _s_8364a276_maxStructsMembersOfTypeSamplerCount;
typedef struct _s_8364a276_outStatuses { RedStatuses* value; } _s_8364a276_outStatuses;
typedef struct _s_8364a276_optionalFile { char* value; } _s_8364a276_optionalFile;
typedef struct _s_8364a276_optionalLine { int value; } _s_8364a276_optionalLine;
typedef struct _s_8364a276_optionalUserData { void* value; } _s_8364a276_optionalUserData;
static inline _s_8364a276_calls _8364a276_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_calls){value}; }
static inline _s_8364a276_structsMemoryHandleName _8364a276_structsMemoryHandleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_structsMemoryHandleName){value}; }
static inline _s_8364a276_maxStructsCount _8364a276_maxStructsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_maxStructsCount){value}; }
static inline _s_8364a276_maxStructsOfTypeSamplerCount _8364a276_maxStructsOfTypeSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_maxStructsOfTypeSamplerCount){value}; }
static inline _s_8364a276_maxStructsMembersOfTypeArrayROConstantCount _8364a276_maxStructsMembersOfTypeArrayROConstantCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_maxStructsMembersOfTypeArrayROConstantCount){value}; }
static inline _s_8364a276_maxStructsMembersOfTypeArrayROOrArrayRWCount _8364a276_maxStructsMembersOfTypeArrayROOrArrayRWCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_maxStructsMembersOfTypeArrayROOrArrayRWCount){value}; }
static inline _s_8364a276_maxStructsMembersOfTypeTextureROCount _8364a276_maxStructsMembersOfTypeTextureROCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_maxStructsMembersOfTypeTextureROCount){value}; }
static inline _s_8364a276_maxStructsMembersOfTypeTextureRWCount _8364a276_maxStructsMembersOfTypeTextureRWCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_maxStructsMembersOfTypeTextureRWCount){value}; }
static inline _s_8364a276_maxStructsMembersOfTypeInlineSamplerCount _8364a276_maxStructsMembersOfTypeInlineSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_maxStructsMembersOfTypeInlineSamplerCount){value}; }
static inline _s_8364a276_maxStructsMembersOfTypeSamplerCount _8364a276_maxStructsMembersOfTypeSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_maxStructsMembersOfTypeSamplerCount){value}; }
static inline _s_8364a276_outStatuses _8364a276_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_outStatuses){value}; }
static inline _s_8364a276_optionalFile _8364a276_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_optionalFile){value}; }
static inline _s_8364a276_optionalLine _8364a276_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_optionalLine){value}; }
static inline _s_8364a276_optionalUserData _8364a276_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8364a276_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallAllocateAndSetInlineStructsMemory(_s_8364a276_calls calls, _s_8364a276_structsMemoryHandleName structsMemoryHandleName, _s_8364a276_maxStructsCount maxStructsCount, _s_8364a276_maxStructsOfTypeSamplerCount maxStructsOfTypeSamplerCount, _s_8364a276_maxStructsMembersOfTypeArrayROConstantCount maxStructsMembersOfTypeArrayROConstantCount, _s_8364a276_maxStructsMembersOfTypeArrayROOrArrayRWCount maxStructsMembersOfTypeArrayROOrArrayRWCount, _s_8364a276_maxStructsMembersOfTypeTextureROCount maxStructsMembersOfTypeTextureROCount, _s_8364a276_maxStructsMembersOfTypeTextureRWCount maxStructsMembersOfTypeTextureRWCount, _s_8364a276_maxStructsMembersOfTypeInlineSamplerCount maxStructsMembersOfTypeInlineSamplerCount, _s_8364a276_maxStructsMembersOfTypeSamplerCount maxStructsMembersOfTypeSamplerCount, _s_8364a276_outStatuses outStatuses, _s_8364a276_optionalFile optionalFile, _s_8364a276_optionalLine optionalLine, _s_8364a276_optionalUserData optionalUserData) {
  red2CallAllocateAndSetInlineStructsMemory(calls.value, structsMemoryHandleName.value, maxStructsCount.value, maxStructsOfTypeSamplerCount.value, maxStructsMembersOfTypeArrayROConstantCount.value, maxStructsMembersOfTypeArrayROOrArrayRWCount.value, maxStructsMembersOfTypeTextureROCount.value, maxStructsMembersOfTypeTextureRWCount.value, maxStructsMembersOfTypeInlineSamplerCount.value, maxStructsMembersOfTypeSamplerCount.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters
#define _b6d54747_calls(value) value
#define _b6d54747_structsMemoryHandleName(value) value
#define _b6d54747_procedureParametersCount(value) value
#define _b6d54747_procedureParameters(value) value
#define _b6d54747_outStatuses(value) value
#define _b6d54747_optionalFile(value) value
#define _b6d54747_optionalLine(value) value
#define _b6d54747_optionalUserData(value) value
#else
typedef struct _s_b6d54747_calls { Red2HandleCalls value; } _s_b6d54747_calls;
typedef struct _s_b6d54747_structsMemoryHandleName { char* value; } _s_b6d54747_structsMemoryHandleName;
typedef struct _s_b6d54747_procedureParametersCount { unsigned value; } _s_b6d54747_procedureParametersCount;
typedef struct _s_b6d54747_procedureParameters { Red2InlineStructsMemoryFromProcedureParameters* value; } _s_b6d54747_procedureParameters;
typedef struct _s_b6d54747_outStatuses { RedStatuses* value; } _s_b6d54747_outStatuses;
typedef struct _s_b6d54747_optionalFile { char* value; } _s_b6d54747_optionalFile;
typedef struct _s_b6d54747_optionalLine { int value; } _s_b6d54747_optionalLine;
typedef struct _s_b6d54747_optionalUserData { void* value; } _s_b6d54747_optionalUserData;
static inline _s_b6d54747_calls _b6d54747_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_b6d54747_calls){value}; }
static inline _s_b6d54747_structsMemoryHandleName _b6d54747_structsMemoryHandleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b6d54747_structsMemoryHandleName){value}; }
static inline _s_b6d54747_procedureParametersCount _b6d54747_procedureParametersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b6d54747_procedureParametersCount){value}; }
static inline _s_b6d54747_procedureParameters _b6d54747_procedureParameters(Red2InlineStructsMemoryFromProcedureParameters* value) { return REDGPU_NP_STRUCT_INIT(_s_b6d54747_procedureParameters){value}; }
static inline _s_b6d54747_outStatuses _b6d54747_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b6d54747_outStatuses){value}; }
static inline _s_b6d54747_optionalFile _b6d54747_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b6d54747_optionalFile){value}; }
static inline _s_b6d54747_optionalLine _b6d54747_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b6d54747_optionalLine){value}; }
static inline _s_b6d54747_optionalUserData _b6d54747_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b6d54747_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters(_s_b6d54747_calls calls, _s_b6d54747_structsMemoryHandleName structsMemoryHandleName, _s_b6d54747_procedureParametersCount procedureParametersCount, _s_b6d54747_procedureParameters procedureParameters, _s_b6d54747_outStatuses outStatuses, _s_b6d54747_optionalFile optionalFile, _s_b6d54747_optionalLine optionalLine, _s_b6d54747_optionalUserData optionalUserData) {
  red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters(calls.value, structsMemoryHandleName.value, procedureParametersCount.value, procedureParameters.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallSuballocateAndSetProcedureParametersInlineStruct red2CallSuballocateAndSetProcedureParametersInlineStruct
#define _9ae66bff_calls(value) value
#define _9ae66bff_procedureType(value) value
#define _9ae66bff_procedureParameters(value) value
#define _9ae66bff_structIndex(value) value
#define _9ae66bff_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers(value) value
#define _9ae66bff_outStatuses(value) value
#define _9ae66bff_optionalFile(value) value
#define _9ae66bff_optionalLine(value) value
#define _9ae66bff_optionalUserData(value) value
#else
typedef struct _s_9ae66bff_calls { Red2HandleCalls value; } _s_9ae66bff_calls;
typedef struct _s_9ae66bff_procedureType { RedProcedureType value; } _s_9ae66bff_procedureType;
typedef struct _s_9ae66bff_procedureParameters { Red2HandleProcedureParameters value; } _s_9ae66bff_procedureParameters;
typedef struct _s_9ae66bff_structIndex { unsigned value; } _s_9ae66bff_structIndex;
typedef struct _s_9ae66bff_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers { void** value; } _s_9ae66bff_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers;
typedef struct _s_9ae66bff_outStatuses { RedStatuses* value; } _s_9ae66bff_outStatuses;
typedef struct _s_9ae66bff_optionalFile { char* value; } _s_9ae66bff_optionalFile;
typedef struct _s_9ae66bff_optionalLine { int value; } _s_9ae66bff_optionalLine;
typedef struct _s_9ae66bff_optionalUserData { void* value; } _s_9ae66bff_optionalUserData;
static inline _s_9ae66bff_calls _9ae66bff_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_9ae66bff_calls){value}; }
static inline _s_9ae66bff_procedureType _9ae66bff_procedureType(RedProcedureType value) { return REDGPU_NP_STRUCT_INIT(_s_9ae66bff_procedureType){value}; }
static inline _s_9ae66bff_procedureParameters _9ae66bff_procedureParameters(Red2HandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_9ae66bff_procedureParameters){value}; }
static inline _s_9ae66bff_structIndex _9ae66bff_structIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9ae66bff_structIndex){value}; }
static inline _s_9ae66bff_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers _9ae66bff_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers(void** value) { return REDGPU_NP_STRUCT_INIT(_s_9ae66bff_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers){value}; }
static inline _s_9ae66bff_outStatuses _9ae66bff_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_9ae66bff_outStatuses){value}; }
static inline _s_9ae66bff_optionalFile _9ae66bff_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9ae66bff_optionalFile){value}; }
static inline _s_9ae66bff_optionalLine _9ae66bff_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9ae66bff_optionalLine){value}; }
static inline _s_9ae66bff_optionalUserData _9ae66bff_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9ae66bff_optionalUserData){value}; }
REDGPU_NP_DECLSPEC RedStatus REDGPU_NP_API np_red2CallSuballocateAndSetProcedureParametersInlineStruct(_s_9ae66bff_calls calls, _s_9ae66bff_procedureType procedureType, _s_9ae66bff_procedureParameters procedureParameters, _s_9ae66bff_structIndex structIndex, _s_9ae66bff_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers, _s_9ae66bff_outStatuses outStatuses, _s_9ae66bff_optionalFile optionalFile, _s_9ae66bff_optionalLine optionalLine, _s_9ae66bff_optionalUserData optionalUserData) {
  return red2CallSuballocateAndSetProcedureParametersInlineStruct(calls.value, procedureType.value, procedureParameters.value, structIndex.value, structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2PresentGetImageIndex red2PresentGetImageIndex
#define _246d7a5f_context(value) value
#define _246d7a5f_gpu(value) value
#define _246d7a5f_present(value) value
#define _246d7a5f_signalCpuSignal(value) value
#define _246d7a5f_signalGpuSignal(value) value
#define _246d7a5f_outImageIndex(value) value
#define _246d7a5f_outStatuses(value) value
#define _246d7a5f_optionalFile(value) value
#define _246d7a5f_optionalLine(value) value
#define _246d7a5f_optionalUserData(value) value
#else
typedef struct _s_246d7a5f_context { RedContext value; } _s_246d7a5f_context;
typedef struct _s_246d7a5f_gpu { RedHandleGpu value; } _s_246d7a5f_gpu;
typedef struct _s_246d7a5f_present { RedHandlePresent value; } _s_246d7a5f_present;
typedef struct _s_246d7a5f_signalCpuSignal { RedHandleCpuSignal value; } _s_246d7a5f_signalCpuSignal;
typedef struct _s_246d7a5f_signalGpuSignal { RedHandleGpuSignal value; } _s_246d7a5f_signalGpuSignal;
typedef struct _s_246d7a5f_outImageIndex { unsigned* value; } _s_246d7a5f_outImageIndex;
typedef struct _s_246d7a5f_outStatuses { RedStatuses* value; } _s_246d7a5f_outStatuses;
typedef struct _s_246d7a5f_optionalFile { char* value; } _s_246d7a5f_optionalFile;
typedef struct _s_246d7a5f_optionalLine { int value; } _s_246d7a5f_optionalLine;
typedef struct _s_246d7a5f_optionalUserData { void* value; } _s_246d7a5f_optionalUserData;
static inline _s_246d7a5f_context _246d7a5f_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_246d7a5f_context){value}; }
static inline _s_246d7a5f_gpu _246d7a5f_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_246d7a5f_gpu){value}; }
static inline _s_246d7a5f_present _246d7a5f_present(RedHandlePresent value) { return REDGPU_NP_STRUCT_INIT(_s_246d7a5f_present){value}; }
static inline _s_246d7a5f_signalCpuSignal _246d7a5f_signalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_246d7a5f_signalCpuSignal){value}; }
static inline _s_246d7a5f_signalGpuSignal _246d7a5f_signalGpuSignal(RedHandleGpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_246d7a5f_signalGpuSignal){value}; }
static inline _s_246d7a5f_outImageIndex _246d7a5f_outImageIndex(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_246d7a5f_outImageIndex){value}; }
static inline _s_246d7a5f_outStatuses _246d7a5f_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_246d7a5f_outStatuses){value}; }
static inline _s_246d7a5f_optionalFile _246d7a5f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_246d7a5f_optionalFile){value}; }
static inline _s_246d7a5f_optionalLine _246d7a5f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_246d7a5f_optionalLine){value}; }
static inline _s_246d7a5f_optionalUserData _246d7a5f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_246d7a5f_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2PresentGetImageIndex(_s_246d7a5f_context context, _s_246d7a5f_gpu gpu, _s_246d7a5f_present present, _s_246d7a5f_signalCpuSignal signalCpuSignal, _s_246d7a5f_signalGpuSignal signalGpuSignal, _s_246d7a5f_outImageIndex outImageIndex, _s_246d7a5f_outStatuses outStatuses, _s_246d7a5f_optionalFile optionalFile, _s_246d7a5f_optionalLine optionalLine, _s_246d7a5f_optionalUserData optionalUserData) {
  red2PresentGetImageIndex(context.value, gpu.value, present.value, signalCpuSignal.value, signalGpuSignal.value, outImageIndex.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2QueueSubmit red2QueueSubmit
#define _dc37eae9_context(value) value
#define _dc37eae9_gpu(value) value
#define _dc37eae9_queue(value) value
#define _dc37eae9_timelinesCount(value) value
#define _dc37eae9_timelines(value) value
#define _dc37eae9_outQueueSubmissionTicketArrayIndex(value) value
#define _dc37eae9_outQueueSubmissionTicket(value) value
#define _dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesCount(value) value
#define _dc37eae9_whenQueueSubmissionIsFinishedDestroyHandles(value) value
#define _dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesHandleType(value) value
#define _dc37eae9_optionalCustomHandleTypeDestroyCallback(value) value
#define _dc37eae9_outStatuses(value) value
#define _dc37eae9_optionalFile(value) value
#define _dc37eae9_optionalLine(value) value
#define _dc37eae9_optionalUserData(value) value
#else
typedef struct _s_dc37eae9_context { RedContext value; } _s_dc37eae9_context;
typedef struct _s_dc37eae9_gpu { RedHandleGpu value; } _s_dc37eae9_gpu;
typedef struct _s_dc37eae9_queue { RedHandleQueue value; } _s_dc37eae9_queue;
typedef struct _s_dc37eae9_timelinesCount { unsigned value; } _s_dc37eae9_timelinesCount;
typedef struct _s_dc37eae9_timelines { RedGpuTimeline* value; } _s_dc37eae9_timelines;
typedef struct _s_dc37eae9_outQueueSubmissionTicketArrayIndex { uint64_t* value; } _s_dc37eae9_outQueueSubmissionTicketArrayIndex;
typedef struct _s_dc37eae9_outQueueSubmissionTicket { uint64_t* value; } _s_dc37eae9_outQueueSubmissionTicket;
typedef struct _s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesCount { uint64_t value; } _s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesCount;
typedef struct _s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandles { void** value; } _s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandles;
typedef struct _s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesHandleType { unsigned* value; } _s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesHandleType;
typedef struct _s_dc37eae9_optionalCustomHandleTypeDestroyCallback { void* value; } _s_dc37eae9_optionalCustomHandleTypeDestroyCallback;
typedef struct _s_dc37eae9_outStatuses { RedStatuses* value; } _s_dc37eae9_outStatuses;
typedef struct _s_dc37eae9_optionalFile { char* value; } _s_dc37eae9_optionalFile;
typedef struct _s_dc37eae9_optionalLine { int value; } _s_dc37eae9_optionalLine;
typedef struct _s_dc37eae9_optionalUserData { void* value; } _s_dc37eae9_optionalUserData;
static inline _s_dc37eae9_context _dc37eae9_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_context){value}; }
static inline _s_dc37eae9_gpu _dc37eae9_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_gpu){value}; }
static inline _s_dc37eae9_queue _dc37eae9_queue(RedHandleQueue value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_queue){value}; }
static inline _s_dc37eae9_timelinesCount _dc37eae9_timelinesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_timelinesCount){value}; }
static inline _s_dc37eae9_timelines _dc37eae9_timelines(RedGpuTimeline* value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_timelines){value}; }
static inline _s_dc37eae9_outQueueSubmissionTicketArrayIndex _dc37eae9_outQueueSubmissionTicketArrayIndex(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_outQueueSubmissionTicketArrayIndex){value}; }
static inline _s_dc37eae9_outQueueSubmissionTicket _dc37eae9_outQueueSubmissionTicket(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_outQueueSubmissionTicket){value}; }
static inline _s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesCount _dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesCount){value}; }
static inline _s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandles _dc37eae9_whenQueueSubmissionIsFinishedDestroyHandles(void** value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandles){value}; }
static inline _s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesHandleType _dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesHandleType(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesHandleType){value}; }
static inline _s_dc37eae9_optionalCustomHandleTypeDestroyCallback _dc37eae9_optionalCustomHandleTypeDestroyCallback(void* value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_optionalCustomHandleTypeDestroyCallback){value}; }
static inline _s_dc37eae9_outStatuses _dc37eae9_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_outStatuses){value}; }
static inline _s_dc37eae9_optionalFile _dc37eae9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_optionalFile){value}; }
static inline _s_dc37eae9_optionalLine _dc37eae9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_optionalLine){value}; }
static inline _s_dc37eae9_optionalUserData _dc37eae9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_dc37eae9_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2QueueSubmit(_s_dc37eae9_context context, _s_dc37eae9_gpu gpu, _s_dc37eae9_queue queue, _s_dc37eae9_timelinesCount timelinesCount, _s_dc37eae9_timelines timelines, _s_dc37eae9_outQueueSubmissionTicketArrayIndex outQueueSubmissionTicketArrayIndex, _s_dc37eae9_outQueueSubmissionTicket outQueueSubmissionTicket, _s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesCount whenQueueSubmissionIsFinishedDestroyHandlesCount, _s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandles whenQueueSubmissionIsFinishedDestroyHandles, _s_dc37eae9_whenQueueSubmissionIsFinishedDestroyHandlesHandleType whenQueueSubmissionIsFinishedDestroyHandlesHandleType, _s_dc37eae9_optionalCustomHandleTypeDestroyCallback optionalCustomHandleTypeDestroyCallback, _s_dc37eae9_outStatuses outStatuses, _s_dc37eae9_optionalFile optionalFile, _s_dc37eae9_optionalLine optionalLine, _s_dc37eae9_optionalUserData optionalUserData) {
  red2QueueSubmit(context.value, gpu.value, queue.value, timelinesCount.value, timelines.value, outQueueSubmissionTicketArrayIndex.value, outQueueSubmissionTicket.value, whenQueueSubmissionIsFinishedDestroyHandlesCount.value, whenQueueSubmissionIsFinishedDestroyHandles.value, whenQueueSubmissionIsFinishedDestroyHandlesHandleType.value, optionalCustomHandleTypeDestroyCallback.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2IsQueueSubmissionFinished red2IsQueueSubmissionFinished
#define _0be423bb_queueSubmissionTicketArrayIndex(value) value
#define _0be423bb_queueSubmissionTicket(value) value
#define _0be423bb_optionalFile(value) value
#define _0be423bb_optionalLine(value) value
#define _0be423bb_optionalUserData(value) value
#else
typedef struct _s_0be423bb_queueSubmissionTicketArrayIndex { uint64_t value; } _s_0be423bb_queueSubmissionTicketArrayIndex;
typedef struct _s_0be423bb_queueSubmissionTicket { uint64_t value; } _s_0be423bb_queueSubmissionTicket;
typedef struct _s_0be423bb_optionalFile { char* value; } _s_0be423bb_optionalFile;
typedef struct _s_0be423bb_optionalLine { int value; } _s_0be423bb_optionalLine;
typedef struct _s_0be423bb_optionalUserData { void* value; } _s_0be423bb_optionalUserData;
static inline _s_0be423bb_queueSubmissionTicketArrayIndex _0be423bb_queueSubmissionTicketArrayIndex(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_0be423bb_queueSubmissionTicketArrayIndex){value}; }
static inline _s_0be423bb_queueSubmissionTicket _0be423bb_queueSubmissionTicket(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_0be423bb_queueSubmissionTicket){value}; }
static inline _s_0be423bb_optionalFile _0be423bb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0be423bb_optionalFile){value}; }
static inline _s_0be423bb_optionalLine _0be423bb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0be423bb_optionalLine){value}; }
static inline _s_0be423bb_optionalUserData _0be423bb_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0be423bb_optionalUserData){value}; }
REDGPU_NP_DECLSPEC RedBool32 REDGPU_NP_API np_red2IsQueueSubmissionFinished(_s_0be423bb_queueSubmissionTicketArrayIndex queueSubmissionTicketArrayIndex, _s_0be423bb_queueSubmissionTicket queueSubmissionTicket, _s_0be423bb_optionalFile optionalFile, _s_0be423bb_optionalLine optionalLine, _s_0be423bb_optionalUserData optionalUserData) {
  return red2IsQueueSubmissionFinished(queueSubmissionTicketArrayIndex.value, queueSubmissionTicket.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2IsQueueSubmissionFinishedByTicketAlone red2IsQueueSubmissionFinishedByTicketAlone
#define _d9235137_queueSubmissionTicket(value) value
#define _d9235137_optionalFile(value) value
#define _d9235137_optionalLine(value) value
#define _d9235137_optionalUserData(value) value
#else
typedef struct _s_d9235137_queueSubmissionTicket { uint64_t value; } _s_d9235137_queueSubmissionTicket;
typedef struct _s_d9235137_optionalFile { char* value; } _s_d9235137_optionalFile;
typedef struct _s_d9235137_optionalLine { int value; } _s_d9235137_optionalLine;
typedef struct _s_d9235137_optionalUserData { void* value; } _s_d9235137_optionalUserData;
static inline _s_d9235137_queueSubmissionTicket _d9235137_queueSubmissionTicket(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_d9235137_queueSubmissionTicket){value}; }
static inline _s_d9235137_optionalFile _d9235137_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d9235137_optionalFile){value}; }
static inline _s_d9235137_optionalLine _d9235137_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d9235137_optionalLine){value}; }
static inline _s_d9235137_optionalUserData _d9235137_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d9235137_optionalUserData){value}; }
REDGPU_NP_DECLSPEC RedBool32 REDGPU_NP_API np_red2IsQueueSubmissionFinishedByTicketAlone(_s_d9235137_queueSubmissionTicket queueSubmissionTicket, _s_d9235137_optionalFile optionalFile, _s_d9235137_optionalLine optionalLine, _s_d9235137_optionalUserData optionalUserData) {
  return red2IsQueueSubmissionFinishedByTicketAlone(queueSubmissionTicket.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket
#define _595c3ac0_context(value) value
#define _595c3ac0_gpu(value) value
#define _595c3ac0_queueSubmissionTicket(value) value
#define _595c3ac0_outStatuses(value) value
#define _595c3ac0_optionalFile(value) value
#define _595c3ac0_optionalLine(value) value
#define _595c3ac0_optionalUserData(value) value
#else
typedef struct _s_595c3ac0_context { RedContext value; } _s_595c3ac0_context;
typedef struct _s_595c3ac0_gpu { RedHandleGpu value; } _s_595c3ac0_gpu;
typedef struct _s_595c3ac0_queueSubmissionTicket { uint64_t value; } _s_595c3ac0_queueSubmissionTicket;
typedef struct _s_595c3ac0_outStatuses { RedStatuses* value; } _s_595c3ac0_outStatuses;
typedef struct _s_595c3ac0_optionalFile { char* value; } _s_595c3ac0_optionalFile;
typedef struct _s_595c3ac0_optionalLine { int value; } _s_595c3ac0_optionalLine;
typedef struct _s_595c3ac0_optionalUserData { void* value; } _s_595c3ac0_optionalUserData;
static inline _s_595c3ac0_context _595c3ac0_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_595c3ac0_context){value}; }
static inline _s_595c3ac0_gpu _595c3ac0_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_595c3ac0_gpu){value}; }
static inline _s_595c3ac0_queueSubmissionTicket _595c3ac0_queueSubmissionTicket(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_595c3ac0_queueSubmissionTicket){value}; }
static inline _s_595c3ac0_outStatuses _595c3ac0_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_595c3ac0_outStatuses){value}; }
static inline _s_595c3ac0_optionalFile _595c3ac0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_595c3ac0_optionalFile){value}; }
static inline _s_595c3ac0_optionalLine _595c3ac0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_595c3ac0_optionalLine){value}; }
static inline _s_595c3ac0_optionalUserData _595c3ac0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_595c3ac0_optionalUserData){value}; }
REDGPU_NP_DECLSPEC RedBool32 REDGPU_NP_API np_red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket(_s_595c3ac0_context context, _s_595c3ac0_gpu gpu, _s_595c3ac0_queueSubmissionTicket queueSubmissionTicket, _s_595c3ac0_outStatuses outStatuses, _s_595c3ac0_optionalFile optionalFile, _s_595c3ac0_optionalLine optionalLine, _s_595c3ac0_optionalUserData optionalUserData) {
  return red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket(context.value, gpu.value, queueSubmissionTicket.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2WaitForQueueSubmissionToFinish red2WaitForQueueSubmissionToFinish
#define _6f84a6ea_queueSubmissionTicketArrayIndex(value) value
#define _6f84a6ea_queueSubmissionTicket(value) value
#define _6f84a6ea_outStatuses(value) value
#define _6f84a6ea_optionalFile(value) value
#define _6f84a6ea_optionalLine(value) value
#define _6f84a6ea_optionalUserData(value) value
#else
typedef struct _s_6f84a6ea_queueSubmissionTicketArrayIndex { uint64_t value; } _s_6f84a6ea_queueSubmissionTicketArrayIndex;
typedef struct _s_6f84a6ea_queueSubmissionTicket { uint64_t value; } _s_6f84a6ea_queueSubmissionTicket;
typedef struct _s_6f84a6ea_outStatuses { RedStatuses* value; } _s_6f84a6ea_outStatuses;
typedef struct _s_6f84a6ea_optionalFile { char* value; } _s_6f84a6ea_optionalFile;
typedef struct _s_6f84a6ea_optionalLine { int value; } _s_6f84a6ea_optionalLine;
typedef struct _s_6f84a6ea_optionalUserData { void* value; } _s_6f84a6ea_optionalUserData;
static inline _s_6f84a6ea_queueSubmissionTicketArrayIndex _6f84a6ea_queueSubmissionTicketArrayIndex(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_6f84a6ea_queueSubmissionTicketArrayIndex){value}; }
static inline _s_6f84a6ea_queueSubmissionTicket _6f84a6ea_queueSubmissionTicket(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_6f84a6ea_queueSubmissionTicket){value}; }
static inline _s_6f84a6ea_outStatuses _6f84a6ea_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_6f84a6ea_outStatuses){value}; }
static inline _s_6f84a6ea_optionalFile _6f84a6ea_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6f84a6ea_optionalFile){value}; }
static inline _s_6f84a6ea_optionalLine _6f84a6ea_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6f84a6ea_optionalLine){value}; }
static inline _s_6f84a6ea_optionalUserData _6f84a6ea_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6f84a6ea_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2WaitForQueueSubmissionToFinish(_s_6f84a6ea_queueSubmissionTicketArrayIndex queueSubmissionTicketArrayIndex, _s_6f84a6ea_queueSubmissionTicket queueSubmissionTicket, _s_6f84a6ea_outStatuses outStatuses, _s_6f84a6ea_optionalFile optionalFile, _s_6f84a6ea_optionalLine optionalLine, _s_6f84a6ea_optionalUserData optionalUserData) {
  red2WaitForQueueSubmissionToFinish(queueSubmissionTicketArrayIndex.value, queueSubmissionTicket.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2WaitForQueueSubmissionToFinishByTicketAlone red2WaitForQueueSubmissionToFinishByTicketAlone
#define _1cf3faec_queueSubmissionTicket(value) value
#define _1cf3faec_outStatuses(value) value
#define _1cf3faec_optionalFile(value) value
#define _1cf3faec_optionalLine(value) value
#define _1cf3faec_optionalUserData(value) value
#else
typedef struct _s_1cf3faec_queueSubmissionTicket { uint64_t value; } _s_1cf3faec_queueSubmissionTicket;
typedef struct _s_1cf3faec_outStatuses { RedStatuses* value; } _s_1cf3faec_outStatuses;
typedef struct _s_1cf3faec_optionalFile { char* value; } _s_1cf3faec_optionalFile;
typedef struct _s_1cf3faec_optionalLine { int value; } _s_1cf3faec_optionalLine;
typedef struct _s_1cf3faec_optionalUserData { void* value; } _s_1cf3faec_optionalUserData;
static inline _s_1cf3faec_queueSubmissionTicket _1cf3faec_queueSubmissionTicket(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_1cf3faec_queueSubmissionTicket){value}; }
static inline _s_1cf3faec_outStatuses _1cf3faec_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_1cf3faec_outStatuses){value}; }
static inline _s_1cf3faec_optionalFile _1cf3faec_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1cf3faec_optionalFile){value}; }
static inline _s_1cf3faec_optionalLine _1cf3faec_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1cf3faec_optionalLine){value}; }
static inline _s_1cf3faec_optionalUserData _1cf3faec_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1cf3faec_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2WaitForQueueSubmissionToFinishByTicketAlone(_s_1cf3faec_queueSubmissionTicket queueSubmissionTicket, _s_1cf3faec_outStatuses outStatuses, _s_1cf3faec_optionalFile optionalFile, _s_1cf3faec_optionalLine optionalLine, _s_1cf3faec_optionalUserData optionalUserData) {
  red2WaitForQueueSubmissionToFinishByTicketAlone(queueSubmissionTicket.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket
#define _40092307_context(value) value
#define _40092307_gpu(value) value
#define _40092307_queueSubmissionTicket(value) value
#define _40092307_outStatuses(value) value
#define _40092307_optionalFile(value) value
#define _40092307_optionalLine(value) value
#define _40092307_optionalUserData(value) value
#else
typedef struct _s_40092307_context { RedContext value; } _s_40092307_context;
typedef struct _s_40092307_gpu { RedHandleGpu value; } _s_40092307_gpu;
typedef struct _s_40092307_queueSubmissionTicket { uint64_t value; } _s_40092307_queueSubmissionTicket;
typedef struct _s_40092307_outStatuses { RedStatuses* value; } _s_40092307_outStatuses;
typedef struct _s_40092307_optionalFile { char* value; } _s_40092307_optionalFile;
typedef struct _s_40092307_optionalLine { int value; } _s_40092307_optionalLine;
typedef struct _s_40092307_optionalUserData { void* value; } _s_40092307_optionalUserData;
static inline _s_40092307_context _40092307_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_40092307_context){value}; }
static inline _s_40092307_gpu _40092307_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_40092307_gpu){value}; }
static inline _s_40092307_queueSubmissionTicket _40092307_queueSubmissionTicket(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_40092307_queueSubmissionTicket){value}; }
static inline _s_40092307_outStatuses _40092307_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_40092307_outStatuses){value}; }
static inline _s_40092307_optionalFile _40092307_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_40092307_optionalFile){value}; }
static inline _s_40092307_optionalLine _40092307_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_40092307_optionalLine){value}; }
static inline _s_40092307_optionalUserData _40092307_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_40092307_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket(_s_40092307_context context, _s_40092307_gpu gpu, _s_40092307_queueSubmissionTicket queueSubmissionTicket, _s_40092307_outStatuses outStatuses, _s_40092307_optionalFile optionalFile, _s_40092307_optionalLine optionalLine, _s_40092307_optionalUserData optionalUserData) {
  red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket(context.value, gpu.value, queueSubmissionTicket.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2WaitForAllQueueSubmissionsToFinish red2WaitForAllQueueSubmissionsToFinish
#define _c54f00f6_context(value) value
#define _c54f00f6_gpu(value) value
#define _c54f00f6_outStatuses(value) value
#define _c54f00f6_optionalFile(value) value
#define _c54f00f6_optionalLine(value) value
#define _c54f00f6_optionalUserData(value) value
#else
typedef struct _s_c54f00f6_context { RedContext value; } _s_c54f00f6_context;
typedef struct _s_c54f00f6_gpu { RedHandleGpu value; } _s_c54f00f6_gpu;
typedef struct _s_c54f00f6_outStatuses { RedStatuses* value; } _s_c54f00f6_outStatuses;
typedef struct _s_c54f00f6_optionalFile { char* value; } _s_c54f00f6_optionalFile;
typedef struct _s_c54f00f6_optionalLine { int value; } _s_c54f00f6_optionalLine;
typedef struct _s_c54f00f6_optionalUserData { void* value; } _s_c54f00f6_optionalUserData;
static inline _s_c54f00f6_context _c54f00f6_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_c54f00f6_context){value}; }
static inline _s_c54f00f6_gpu _c54f00f6_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_c54f00f6_gpu){value}; }
static inline _s_c54f00f6_outStatuses _c54f00f6_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_c54f00f6_outStatuses){value}; }
static inline _s_c54f00f6_optionalFile _c54f00f6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c54f00f6_optionalFile){value}; }
static inline _s_c54f00f6_optionalLine _c54f00f6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c54f00f6_optionalLine){value}; }
static inline _s_c54f00f6_optionalUserData _c54f00f6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c54f00f6_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2WaitForAllQueueSubmissionsToFinish(_s_c54f00f6_context context, _s_c54f00f6_gpu gpu, _s_c54f00f6_outStatuses outStatuses, _s_c54f00f6_optionalFile optionalFile, _s_c54f00f6_optionalLine optionalLine, _s_c54f00f6_optionalUserData optionalUserData) {
  red2WaitForAllQueueSubmissionsToFinish(context.value, gpu.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallUsageAliasOrderBarrier red2CallUsageAliasOrderBarrier
#define _f7b9d94e_address(value) value
#define _f7b9d94e_calls(value) value
#define _f7b9d94e_context(value) value
#define _f7b9d94e_gpu(value) value
#define _f7b9d94e_arrayUsagesCount(value) value
#define _f7b9d94e_arrayUsages(value) value
#define _f7b9d94e_imageUsagesCount(value) value
#define _f7b9d94e_imageUsages(value) value
#define _f7b9d94e_aliasesCount(value) value
#define _f7b9d94e_aliases(value) value
#define _f7b9d94e_ordersCount(value) value
#define _f7b9d94e_orders(value) value
#define _f7b9d94e_dependencyByRegion(value) value
#else
typedef struct _s_f7b9d94e_address { RedTypeProcedureAddressCallUsageAliasOrderBarrier value; } _s_f7b9d94e_address;
typedef struct _s_f7b9d94e_calls { RedHandleCalls value; } _s_f7b9d94e_calls;
typedef struct _s_f7b9d94e_context { RedContext value; } _s_f7b9d94e_context;
typedef struct _s_f7b9d94e_gpu { RedHandleGpu value; } _s_f7b9d94e_gpu;
typedef struct _s_f7b9d94e_arrayUsagesCount { unsigned value; } _s_f7b9d94e_arrayUsagesCount;
typedef struct _s_f7b9d94e_arrayUsages { RedUsageArray* value; } _s_f7b9d94e_arrayUsages;
typedef struct _s_f7b9d94e_imageUsagesCount { unsigned value; } _s_f7b9d94e_imageUsagesCount;
typedef struct _s_f7b9d94e_imageUsages { RedUsageImage* value; } _s_f7b9d94e_imageUsages;
typedef struct _s_f7b9d94e_aliasesCount { unsigned value; } _s_f7b9d94e_aliasesCount;
typedef struct _s_f7b9d94e_aliases { RedAlias* value; } _s_f7b9d94e_aliases;
typedef struct _s_f7b9d94e_ordersCount { unsigned value; } _s_f7b9d94e_ordersCount;
typedef struct _s_f7b9d94e_orders { RedOrder* value; } _s_f7b9d94e_orders;
typedef struct _s_f7b9d94e_dependencyByRegion { RedBool32 value; } _s_f7b9d94e_dependencyByRegion;
static inline _s_f7b9d94e_address _f7b9d94e_address(RedTypeProcedureAddressCallUsageAliasOrderBarrier value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_address){value}; }
static inline _s_f7b9d94e_calls _f7b9d94e_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_calls){value}; }
static inline _s_f7b9d94e_context _f7b9d94e_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_context){value}; }
static inline _s_f7b9d94e_gpu _f7b9d94e_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_gpu){value}; }
static inline _s_f7b9d94e_arrayUsagesCount _f7b9d94e_arrayUsagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_arrayUsagesCount){value}; }
static inline _s_f7b9d94e_arrayUsages _f7b9d94e_arrayUsages(RedUsageArray* value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_arrayUsages){value}; }
static inline _s_f7b9d94e_imageUsagesCount _f7b9d94e_imageUsagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_imageUsagesCount){value}; }
static inline _s_f7b9d94e_imageUsages _f7b9d94e_imageUsages(RedUsageImage* value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_imageUsages){value}; }
static inline _s_f7b9d94e_aliasesCount _f7b9d94e_aliasesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_aliasesCount){value}; }
static inline _s_f7b9d94e_aliases _f7b9d94e_aliases(RedAlias* value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_aliases){value}; }
static inline _s_f7b9d94e_ordersCount _f7b9d94e_ordersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_ordersCount){value}; }
static inline _s_f7b9d94e_orders _f7b9d94e_orders(RedOrder* value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_orders){value}; }
static inline _s_f7b9d94e_dependencyByRegion _f7b9d94e_dependencyByRegion(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_f7b9d94e_dependencyByRegion){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallUsageAliasOrderBarrier(_s_f7b9d94e_address address, _s_f7b9d94e_calls calls, _s_f7b9d94e_context context, _s_f7b9d94e_gpu gpu, _s_f7b9d94e_arrayUsagesCount arrayUsagesCount, _s_f7b9d94e_arrayUsages arrayUsages, _s_f7b9d94e_imageUsagesCount imageUsagesCount, _s_f7b9d94e_imageUsages imageUsages, _s_f7b9d94e_aliasesCount aliasesCount, _s_f7b9d94e_aliases aliases, _s_f7b9d94e_ordersCount ordersCount, _s_f7b9d94e_orders orders, _s_f7b9d94e_dependencyByRegion dependencyByRegion) {
  red2CallUsageAliasOrderBarrier(address.value, calls.value, context.value, gpu.value, arrayUsagesCount.value, arrayUsages.value, imageUsagesCount.value, imageUsages.value, aliasesCount.value, aliases.value, ordersCount.value, orders.value, dependencyByRegion.value);
}
#endif

