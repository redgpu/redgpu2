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
#define _bcda7434_context(value) value
#define _bcda7434_gpu(value) value
#define _bcda7434_handleName(value) value
#define _bcda7434_structDeclarationMembersCount(value) value
#define _bcda7434_structDeclarationMembers(value) value
#define _bcda7434_structDeclarationMembersArrayROCount(value) value
#define _bcda7434_structDeclarationMembersArrayRO(value) value
#define _bcda7434_procedureParametersHandlesDeclaration(value) value
#define _bcda7434_outStructDeclaration(value) value
#define _bcda7434_outStatuses(value) value
#define _bcda7434_optionalFile(value) value
#define _bcda7434_optionalLine(value) value
#define _bcda7434_optionalUserData(value) value
#else
typedef struct _s_bcda7434_context { RedContext value; } _s_bcda7434_context;
typedef struct _s_bcda7434_gpu { RedHandleGpu value; } _s_bcda7434_gpu;
typedef struct _s_bcda7434_handleName { char* value; } _s_bcda7434_handleName;
typedef struct _s_bcda7434_structDeclarationMembersCount { unsigned value; } _s_bcda7434_structDeclarationMembersCount;
typedef struct _s_bcda7434_structDeclarationMembers { RedStructDeclarationMember* value; } _s_bcda7434_structDeclarationMembers;
typedef struct _s_bcda7434_structDeclarationMembersArrayROCount { unsigned value; } _s_bcda7434_structDeclarationMembersArrayROCount;
typedef struct _s_bcda7434_structDeclarationMembersArrayRO { RedStructDeclarationMemberArrayRO* value; } _s_bcda7434_structDeclarationMembersArrayRO;
typedef struct _s_bcda7434_procedureParametersHandlesDeclaration { RedBool32 value; } _s_bcda7434_procedureParametersHandlesDeclaration;
typedef struct _s_bcda7434_outStructDeclaration { Red2HandleStructDeclaration* value; } _s_bcda7434_outStructDeclaration;
typedef struct _s_bcda7434_outStatuses { RedStatuses* value; } _s_bcda7434_outStatuses;
typedef struct _s_bcda7434_optionalFile { char* value; } _s_bcda7434_optionalFile;
typedef struct _s_bcda7434_optionalLine { int value; } _s_bcda7434_optionalLine;
typedef struct _s_bcda7434_optionalUserData { void* value; } _s_bcda7434_optionalUserData;
static inline _s_bcda7434_context _bcda7434_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_context){value}; }
static inline _s_bcda7434_gpu _bcda7434_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_gpu){value}; }
static inline _s_bcda7434_handleName _bcda7434_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_handleName){value}; }
static inline _s_bcda7434_structDeclarationMembersCount _bcda7434_structDeclarationMembersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_structDeclarationMembersCount){value}; }
static inline _s_bcda7434_structDeclarationMembers _bcda7434_structDeclarationMembers(RedStructDeclarationMember* value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_structDeclarationMembers){value}; }
static inline _s_bcda7434_structDeclarationMembersArrayROCount _bcda7434_structDeclarationMembersArrayROCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_structDeclarationMembersArrayROCount){value}; }
static inline _s_bcda7434_structDeclarationMembersArrayRO _bcda7434_structDeclarationMembersArrayRO(RedStructDeclarationMemberArrayRO* value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_structDeclarationMembersArrayRO){value}; }
static inline _s_bcda7434_procedureParametersHandlesDeclaration _bcda7434_procedureParametersHandlesDeclaration(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_procedureParametersHandlesDeclaration){value}; }
static inline _s_bcda7434_outStructDeclaration _bcda7434_outStructDeclaration(Red2HandleStructDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_outStructDeclaration){value}; }
static inline _s_bcda7434_outStatuses _bcda7434_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_outStatuses){value}; }
static inline _s_bcda7434_optionalFile _bcda7434_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_optionalFile){value}; }
static inline _s_bcda7434_optionalLine _bcda7434_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_optionalLine){value}; }
static inline _s_bcda7434_optionalUserData _bcda7434_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bcda7434_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CreateStructDeclaration(_s_bcda7434_context context, _s_bcda7434_gpu gpu, _s_bcda7434_handleName handleName, _s_bcda7434_structDeclarationMembersCount structDeclarationMembersCount, _s_bcda7434_structDeclarationMembers structDeclarationMembers, _s_bcda7434_structDeclarationMembersArrayROCount structDeclarationMembersArrayROCount, _s_bcda7434_structDeclarationMembersArrayRO structDeclarationMembersArrayRO, _s_bcda7434_procedureParametersHandlesDeclaration procedureParametersHandlesDeclaration, _s_bcda7434_outStructDeclaration outStructDeclaration, _s_bcda7434_outStatuses outStatuses, _s_bcda7434_optionalFile optionalFile, _s_bcda7434_optionalLine optionalLine, _s_bcda7434_optionalUserData optionalUserData) {
  red2CreateStructDeclaration(context.value, gpu.value, handleName.value, structDeclarationMembersCount.value, structDeclarationMembers.value, structDeclarationMembersArrayROCount.value, structDeclarationMembersArrayRO.value, procedureParametersHandlesDeclaration.value, outStructDeclaration.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CreateProcedureParameters red2CreateProcedureParameters
#define _4d4b0ee3_context(value) value
#define _4d4b0ee3_gpu(value) value
#define _4d4b0ee3_handleName(value) value
#define _4d4b0ee3_procedureParametersDeclaration(value) value
#define _4d4b0ee3_outProcedureParameters(value) value
#define _4d4b0ee3_outStatuses(value) value
#define _4d4b0ee3_optionalFile(value) value
#define _4d4b0ee3_optionalLine(value) value
#define _4d4b0ee3_optionalUserData(value) value
#else
typedef struct _s_4d4b0ee3_context { RedContext value; } _s_4d4b0ee3_context;
typedef struct _s_4d4b0ee3_gpu { RedHandleGpu value; } _s_4d4b0ee3_gpu;
typedef struct _s_4d4b0ee3_handleName { char* value; } _s_4d4b0ee3_handleName;
typedef struct _s_4d4b0ee3_procedureParametersDeclaration { Red2ProcedureParametersDeclaration* value; } _s_4d4b0ee3_procedureParametersDeclaration;
typedef struct _s_4d4b0ee3_outProcedureParameters { Red2HandleProcedureParameters* value; } _s_4d4b0ee3_outProcedureParameters;
typedef struct _s_4d4b0ee3_outStatuses { RedStatuses* value; } _s_4d4b0ee3_outStatuses;
typedef struct _s_4d4b0ee3_optionalFile { char* value; } _s_4d4b0ee3_optionalFile;
typedef struct _s_4d4b0ee3_optionalLine { int value; } _s_4d4b0ee3_optionalLine;
typedef struct _s_4d4b0ee3_optionalUserData { void* value; } _s_4d4b0ee3_optionalUserData;
static inline _s_4d4b0ee3_context _4d4b0ee3_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_4d4b0ee3_context){value}; }
static inline _s_4d4b0ee3_gpu _4d4b0ee3_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_4d4b0ee3_gpu){value}; }
static inline _s_4d4b0ee3_handleName _4d4b0ee3_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4d4b0ee3_handleName){value}; }
static inline _s_4d4b0ee3_procedureParametersDeclaration _4d4b0ee3_procedureParametersDeclaration(Red2ProcedureParametersDeclaration* value) { return REDGPU_NP_STRUCT_INIT(_s_4d4b0ee3_procedureParametersDeclaration){value}; }
static inline _s_4d4b0ee3_outProcedureParameters _4d4b0ee3_outProcedureParameters(Red2HandleProcedureParameters* value) { return REDGPU_NP_STRUCT_INIT(_s_4d4b0ee3_outProcedureParameters){value}; }
static inline _s_4d4b0ee3_outStatuses _4d4b0ee3_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_4d4b0ee3_outStatuses){value}; }
static inline _s_4d4b0ee3_optionalFile _4d4b0ee3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4d4b0ee3_optionalFile){value}; }
static inline _s_4d4b0ee3_optionalLine _4d4b0ee3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4d4b0ee3_optionalLine){value}; }
static inline _s_4d4b0ee3_optionalUserData _4d4b0ee3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4d4b0ee3_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CreateProcedureParameters(_s_4d4b0ee3_context context, _s_4d4b0ee3_gpu gpu, _s_4d4b0ee3_handleName handleName, _s_4d4b0ee3_procedureParametersDeclaration procedureParametersDeclaration, _s_4d4b0ee3_outProcedureParameters outProcedureParameters, _s_4d4b0ee3_outStatuses outStatuses, _s_4d4b0ee3_optionalFile optionalFile, _s_4d4b0ee3_optionalLine optionalLine, _s_4d4b0ee3_optionalUserData optionalUserData) {
  red2CreateProcedureParameters(context.value, gpu.value, handleName.value, procedureParametersDeclaration.value, outProcedureParameters.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CreateCalls red2CreateCalls
#define _5b6ebab2_context(value) value
#define _5b6ebab2_gpu(value) value
#define _5b6ebab2_handleName(value) value
#define _5b6ebab2_queueFamilyIndex(value) value
#define _5b6ebab2_outCalls(value) value
#define _5b6ebab2_outStatuses(value) value
#define _5b6ebab2_optionalFile(value) value
#define _5b6ebab2_optionalLine(value) value
#define _5b6ebab2_optionalUserData(value) value
#else
typedef struct _s_5b6ebab2_context { RedContext value; } _s_5b6ebab2_context;
typedef struct _s_5b6ebab2_gpu { RedHandleGpu value; } _s_5b6ebab2_gpu;
typedef struct _s_5b6ebab2_handleName { char* value; } _s_5b6ebab2_handleName;
typedef struct _s_5b6ebab2_queueFamilyIndex { unsigned value; } _s_5b6ebab2_queueFamilyIndex;
typedef struct _s_5b6ebab2_outCalls { Red2HandleCalls* value; } _s_5b6ebab2_outCalls;
typedef struct _s_5b6ebab2_outStatuses { RedStatuses* value; } _s_5b6ebab2_outStatuses;
typedef struct _s_5b6ebab2_optionalFile { char* value; } _s_5b6ebab2_optionalFile;
typedef struct _s_5b6ebab2_optionalLine { int value; } _s_5b6ebab2_optionalLine;
typedef struct _s_5b6ebab2_optionalUserData { void* value; } _s_5b6ebab2_optionalUserData;
static inline _s_5b6ebab2_context _5b6ebab2_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_5b6ebab2_context){value}; }
static inline _s_5b6ebab2_gpu _5b6ebab2_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_5b6ebab2_gpu){value}; }
static inline _s_5b6ebab2_handleName _5b6ebab2_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5b6ebab2_handleName){value}; }
static inline _s_5b6ebab2_queueFamilyIndex _5b6ebab2_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_5b6ebab2_queueFamilyIndex){value}; }
static inline _s_5b6ebab2_outCalls _5b6ebab2_outCalls(Red2HandleCalls* value) { return REDGPU_NP_STRUCT_INIT(_s_5b6ebab2_outCalls){value}; }
static inline _s_5b6ebab2_outStatuses _5b6ebab2_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_5b6ebab2_outStatuses){value}; }
static inline _s_5b6ebab2_optionalFile _5b6ebab2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5b6ebab2_optionalFile){value}; }
static inline _s_5b6ebab2_optionalLine _5b6ebab2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5b6ebab2_optionalLine){value}; }
static inline _s_5b6ebab2_optionalUserData _5b6ebab2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5b6ebab2_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CreateCalls(_s_5b6ebab2_context context, _s_5b6ebab2_gpu gpu, _s_5b6ebab2_handleName handleName, _s_5b6ebab2_queueFamilyIndex queueFamilyIndex, _s_5b6ebab2_outCalls outCalls, _s_5b6ebab2_outStatuses outStatuses, _s_5b6ebab2_optionalFile optionalFile, _s_5b6ebab2_optionalLine optionalLine, _s_5b6ebab2_optionalUserData optionalUserData) {
  red2CreateCalls(context.value, gpu.value, handleName.value, queueFamilyIndex.value, outCalls.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CreateCallsReusable red2CreateCallsReusable
#define _e66e174d_context(value) value
#define _e66e174d_gpu(value) value
#define _e66e174d_handleName(value) value
#define _e66e174d_queueFamilyIndex(value) value
#define _e66e174d_outCalls(value) value
#define _e66e174d_outStatuses(value) value
#define _e66e174d_optionalFile(value) value
#define _e66e174d_optionalLine(value) value
#define _e66e174d_optionalUserData(value) value
#else
typedef struct _s_e66e174d_context { RedContext value; } _s_e66e174d_context;
typedef struct _s_e66e174d_gpu { RedHandleGpu value; } _s_e66e174d_gpu;
typedef struct _s_e66e174d_handleName { char* value; } _s_e66e174d_handleName;
typedef struct _s_e66e174d_queueFamilyIndex { unsigned value; } _s_e66e174d_queueFamilyIndex;
typedef struct _s_e66e174d_outCalls { Red2HandleCalls* value; } _s_e66e174d_outCalls;
typedef struct _s_e66e174d_outStatuses { RedStatuses* value; } _s_e66e174d_outStatuses;
typedef struct _s_e66e174d_optionalFile { char* value; } _s_e66e174d_optionalFile;
typedef struct _s_e66e174d_optionalLine { int value; } _s_e66e174d_optionalLine;
typedef struct _s_e66e174d_optionalUserData { void* value; } _s_e66e174d_optionalUserData;
static inline _s_e66e174d_context _e66e174d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_e66e174d_context){value}; }
static inline _s_e66e174d_gpu _e66e174d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_e66e174d_gpu){value}; }
static inline _s_e66e174d_handleName _e66e174d_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e66e174d_handleName){value}; }
static inline _s_e66e174d_queueFamilyIndex _e66e174d_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e66e174d_queueFamilyIndex){value}; }
static inline _s_e66e174d_outCalls _e66e174d_outCalls(Red2HandleCalls* value) { return REDGPU_NP_STRUCT_INIT(_s_e66e174d_outCalls){value}; }
static inline _s_e66e174d_outStatuses _e66e174d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_e66e174d_outStatuses){value}; }
static inline _s_e66e174d_optionalFile _e66e174d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e66e174d_optionalFile){value}; }
static inline _s_e66e174d_optionalLine _e66e174d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e66e174d_optionalLine){value}; }
static inline _s_e66e174d_optionalUserData _e66e174d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e66e174d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CreateCallsReusable(_s_e66e174d_context context, _s_e66e174d_gpu gpu, _s_e66e174d_handleName handleName, _s_e66e174d_queueFamilyIndex queueFamilyIndex, _s_e66e174d_outCalls outCalls, _s_e66e174d_outStatuses outStatuses, _s_e66e174d_optionalFile optionalFile, _s_e66e174d_optionalLine optionalLine, _s_e66e174d_optionalUserData optionalUserData) {
  red2CreateCallsReusable(context.value, gpu.value, handleName.value, queueFamilyIndex.value, outCalls.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CreateWsiTransientGpuSignal red2CreateWsiTransientGpuSignal
#define _227c0da9_context(value) value
#define _227c0da9_gpu(value) value
#define _227c0da9_present(value) value
#define _227c0da9_presentImageIndex(value) value
#define _227c0da9_outGpuSignal(value) value
#define _227c0da9_outStatuses(value) value
#define _227c0da9_optionalFile(value) value
#define _227c0da9_optionalLine(value) value
#define _227c0da9_optionalUserData(value) value
#else
typedef struct _s_227c0da9_context { RedContext value; } _s_227c0da9_context;
typedef struct _s_227c0da9_gpu { RedHandleGpu value; } _s_227c0da9_gpu;
typedef struct _s_227c0da9_present { RedHandlePresent value; } _s_227c0da9_present;
typedef struct _s_227c0da9_presentImageIndex { unsigned value; } _s_227c0da9_presentImageIndex;
typedef struct _s_227c0da9_outGpuSignal { RedHandleGpuSignal* value; } _s_227c0da9_outGpuSignal;
typedef struct _s_227c0da9_outStatuses { RedStatuses* value; } _s_227c0da9_outStatuses;
typedef struct _s_227c0da9_optionalFile { char* value; } _s_227c0da9_optionalFile;
typedef struct _s_227c0da9_optionalLine { int value; } _s_227c0da9_optionalLine;
typedef struct _s_227c0da9_optionalUserData { void* value; } _s_227c0da9_optionalUserData;
static inline _s_227c0da9_context _227c0da9_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_227c0da9_context){value}; }
static inline _s_227c0da9_gpu _227c0da9_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_227c0da9_gpu){value}; }
static inline _s_227c0da9_present _227c0da9_present(RedHandlePresent value) { return REDGPU_NP_STRUCT_INIT(_s_227c0da9_present){value}; }
static inline _s_227c0da9_presentImageIndex _227c0da9_presentImageIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_227c0da9_presentImageIndex){value}; }
static inline _s_227c0da9_outGpuSignal _227c0da9_outGpuSignal(RedHandleGpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_227c0da9_outGpuSignal){value}; }
static inline _s_227c0da9_outStatuses _227c0da9_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_227c0da9_outStatuses){value}; }
static inline _s_227c0da9_optionalFile _227c0da9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_227c0da9_optionalFile){value}; }
static inline _s_227c0da9_optionalLine _227c0da9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_227c0da9_optionalLine){value}; }
static inline _s_227c0da9_optionalUserData _227c0da9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_227c0da9_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CreateWsiTransientGpuSignal(_s_227c0da9_context context, _s_227c0da9_gpu gpu, _s_227c0da9_present present, _s_227c0da9_presentImageIndex presentImageIndex, _s_227c0da9_outGpuSignal outGpuSignal, _s_227c0da9_outStatuses outStatuses, _s_227c0da9_optionalFile optionalFile, _s_227c0da9_optionalLine optionalLine, _s_227c0da9_optionalUserData optionalUserData) {
  red2CreateWsiTransientGpuSignal(context.value, gpu.value, present.value, presentImageIndex.value, outGpuSignal.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2DestroyContext red2DestroyContext
#define _b64db4eb_context(value) value
#define _b64db4eb_optionalFile(value) value
#define _b64db4eb_optionalLine(value) value
#define _b64db4eb_optionalUserData(value) value
#else
typedef struct _s_b64db4eb_context { RedContext value; } _s_b64db4eb_context;
typedef struct _s_b64db4eb_optionalFile { char* value; } _s_b64db4eb_optionalFile;
typedef struct _s_b64db4eb_optionalLine { int value; } _s_b64db4eb_optionalLine;
typedef struct _s_b64db4eb_optionalUserData { void* value; } _s_b64db4eb_optionalUserData;
static inline _s_b64db4eb_context _b64db4eb_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b64db4eb_context){value}; }
static inline _s_b64db4eb_optionalFile _b64db4eb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b64db4eb_optionalFile){value}; }
static inline _s_b64db4eb_optionalLine _b64db4eb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b64db4eb_optionalLine){value}; }
static inline _s_b64db4eb_optionalUserData _b64db4eb_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b64db4eb_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2DestroyContext(_s_b64db4eb_context context, _s_b64db4eb_optionalFile optionalFile, _s_b64db4eb_optionalLine optionalLine, _s_b64db4eb_optionalUserData optionalUserData) {
  red2DestroyContext(context.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2DestroyStructDeclaration red2DestroyStructDeclaration
#define _3e897b9f_context(value) value
#define _3e897b9f_gpu(value) value
#define _3e897b9f_structDeclaration(value) value
#define _3e897b9f_optionalFile(value) value
#define _3e897b9f_optionalLine(value) value
#define _3e897b9f_optionalUserData(value) value
#else
typedef struct _s_3e897b9f_context { RedContext value; } _s_3e897b9f_context;
typedef struct _s_3e897b9f_gpu { RedHandleGpu value; } _s_3e897b9f_gpu;
typedef struct _s_3e897b9f_structDeclaration { Red2HandleStructDeclaration value; } _s_3e897b9f_structDeclaration;
typedef struct _s_3e897b9f_optionalFile { char* value; } _s_3e897b9f_optionalFile;
typedef struct _s_3e897b9f_optionalLine { int value; } _s_3e897b9f_optionalLine;
typedef struct _s_3e897b9f_optionalUserData { void* value; } _s_3e897b9f_optionalUserData;
static inline _s_3e897b9f_context _3e897b9f_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_3e897b9f_context){value}; }
static inline _s_3e897b9f_gpu _3e897b9f_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_3e897b9f_gpu){value}; }
static inline _s_3e897b9f_structDeclaration _3e897b9f_structDeclaration(Red2HandleStructDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_3e897b9f_structDeclaration){value}; }
static inline _s_3e897b9f_optionalFile _3e897b9f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3e897b9f_optionalFile){value}; }
static inline _s_3e897b9f_optionalLine _3e897b9f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3e897b9f_optionalLine){value}; }
static inline _s_3e897b9f_optionalUserData _3e897b9f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3e897b9f_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2DestroyStructDeclaration(_s_3e897b9f_context context, _s_3e897b9f_gpu gpu, _s_3e897b9f_structDeclaration structDeclaration, _s_3e897b9f_optionalFile optionalFile, _s_3e897b9f_optionalLine optionalLine, _s_3e897b9f_optionalUserData optionalUserData) {
  red2DestroyStructDeclaration(context.value, gpu.value, structDeclaration.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2DestroyProcedureParameters red2DestroyProcedureParameters
#define _ca6ef253_context(value) value
#define _ca6ef253_gpu(value) value
#define _ca6ef253_procedureParameters(value) value
#define _ca6ef253_optionalFile(value) value
#define _ca6ef253_optionalLine(value) value
#define _ca6ef253_optionalUserData(value) value
#else
typedef struct _s_ca6ef253_context { RedContext value; } _s_ca6ef253_context;
typedef struct _s_ca6ef253_gpu { RedHandleGpu value; } _s_ca6ef253_gpu;
typedef struct _s_ca6ef253_procedureParameters { Red2HandleProcedureParameters value; } _s_ca6ef253_procedureParameters;
typedef struct _s_ca6ef253_optionalFile { char* value; } _s_ca6ef253_optionalFile;
typedef struct _s_ca6ef253_optionalLine { int value; } _s_ca6ef253_optionalLine;
typedef struct _s_ca6ef253_optionalUserData { void* value; } _s_ca6ef253_optionalUserData;
static inline _s_ca6ef253_context _ca6ef253_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_ca6ef253_context){value}; }
static inline _s_ca6ef253_gpu _ca6ef253_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_ca6ef253_gpu){value}; }
static inline _s_ca6ef253_procedureParameters _ca6ef253_procedureParameters(Red2HandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_ca6ef253_procedureParameters){value}; }
static inline _s_ca6ef253_optionalFile _ca6ef253_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ca6ef253_optionalFile){value}; }
static inline _s_ca6ef253_optionalLine _ca6ef253_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ca6ef253_optionalLine){value}; }
static inline _s_ca6ef253_optionalUserData _ca6ef253_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ca6ef253_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2DestroyProcedureParameters(_s_ca6ef253_context context, _s_ca6ef253_gpu gpu, _s_ca6ef253_procedureParameters procedureParameters, _s_ca6ef253_optionalFile optionalFile, _s_ca6ef253_optionalLine optionalLine, _s_ca6ef253_optionalUserData optionalUserData) {
  red2DestroyProcedureParameters(context.value, gpu.value, procedureParameters.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2DestroyCalls red2DestroyCalls
#define _8c2b0029_context(value) value
#define _8c2b0029_gpu(value) value
#define _8c2b0029_calls(value) value
#define _8c2b0029_optionalFile(value) value
#define _8c2b0029_optionalLine(value) value
#define _8c2b0029_optionalUserData(value) value
#else
typedef struct _s_8c2b0029_context { RedContext value; } _s_8c2b0029_context;
typedef struct _s_8c2b0029_gpu { RedHandleGpu value; } _s_8c2b0029_gpu;
typedef struct _s_8c2b0029_calls { Red2HandleCalls value; } _s_8c2b0029_calls;
typedef struct _s_8c2b0029_optionalFile { char* value; } _s_8c2b0029_optionalFile;
typedef struct _s_8c2b0029_optionalLine { int value; } _s_8c2b0029_optionalLine;
typedef struct _s_8c2b0029_optionalUserData { void* value; } _s_8c2b0029_optionalUserData;
static inline _s_8c2b0029_context _8c2b0029_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_8c2b0029_context){value}; }
static inline _s_8c2b0029_gpu _8c2b0029_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_8c2b0029_gpu){value}; }
static inline _s_8c2b0029_calls _8c2b0029_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_8c2b0029_calls){value}; }
static inline _s_8c2b0029_optionalFile _8c2b0029_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8c2b0029_optionalFile){value}; }
static inline _s_8c2b0029_optionalLine _8c2b0029_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8c2b0029_optionalLine){value}; }
static inline _s_8c2b0029_optionalUserData _8c2b0029_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8c2b0029_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2DestroyCalls(_s_8c2b0029_context context, _s_8c2b0029_gpu gpu, _s_8c2b0029_calls calls, _s_8c2b0029_optionalFile optionalFile, _s_8c2b0029_optionalLine optionalLine, _s_8c2b0029_optionalUserData optionalUserData) {
  red2DestroyCalls(context.value, gpu.value, calls.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2StructDeclarationGetRedHandle red2StructDeclarationGetRedHandle
#define _2e66ef28_structDeclaration(value) value
#else
typedef struct _s_2e66ef28_structDeclaration { Red2HandleStructDeclaration value; } _s_2e66ef28_structDeclaration;
static inline _s_2e66ef28_structDeclaration _2e66ef28_structDeclaration(Red2HandleStructDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_2e66ef28_structDeclaration){value}; }
REDGPU_NP_DECLSPEC RedHandleStructDeclaration REDGPU_NP_API np_red2StructDeclarationGetRedHandle(_s_2e66ef28_structDeclaration structDeclaration) {
  return red2StructDeclarationGetRedHandle(structDeclaration.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2StructDeclarationGetMembersPointer red2StructDeclarationGetMembersPointer
#define _3af6eadb_structDeclaration(value) value
#else
typedef struct _s_3af6eadb_structDeclaration { Red2HandleStructDeclaration value; } _s_3af6eadb_structDeclaration;
static inline _s_3af6eadb_structDeclaration _3af6eadb_structDeclaration(Red2HandleStructDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_3af6eadb_structDeclaration){value}; }
REDGPU_NP_DECLSPEC Red2StructDeclarationMember* REDGPU_NP_API np_red2StructDeclarationGetMembersPointer(_s_3af6eadb_structDeclaration structDeclaration) {
  return red2StructDeclarationGetMembersPointer(structDeclaration.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2StructDeclarationGetMembersCounts red2StructDeclarationGetMembersCounts
#define _e0daa6e1_structDeclaration(value) value
#define _e0daa6e1_outStructDeclarationMembersCount(value) value
#define _e0daa6e1_outMembersOfTypeArrayROConstantCount(value) value
#define _e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount(value) value
#define _e0daa6e1_outMembersOfTypeTextureROCount(value) value
#define _e0daa6e1_outMembersOfTypeTextureRWCount(value) value
#define _e0daa6e1_outMembersOfTypeInlineSamplerCount(value) value
#define _e0daa6e1_outMembersOfTypeSamplerCount(value) value
#else
typedef struct _s_e0daa6e1_structDeclaration { Red2HandleStructDeclaration value; } _s_e0daa6e1_structDeclaration;
typedef struct _s_e0daa6e1_outStructDeclarationMembersCount { unsigned* value; } _s_e0daa6e1_outStructDeclarationMembersCount;
typedef struct _s_e0daa6e1_outMembersOfTypeArrayROConstantCount { unsigned* value; } _s_e0daa6e1_outMembersOfTypeArrayROConstantCount;
typedef struct _s_e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount { unsigned* value; } _s_e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount;
typedef struct _s_e0daa6e1_outMembersOfTypeTextureROCount { unsigned* value; } _s_e0daa6e1_outMembersOfTypeTextureROCount;
typedef struct _s_e0daa6e1_outMembersOfTypeTextureRWCount { unsigned* value; } _s_e0daa6e1_outMembersOfTypeTextureRWCount;
typedef struct _s_e0daa6e1_outMembersOfTypeInlineSamplerCount { unsigned* value; } _s_e0daa6e1_outMembersOfTypeInlineSamplerCount;
typedef struct _s_e0daa6e1_outMembersOfTypeSamplerCount { unsigned* value; } _s_e0daa6e1_outMembersOfTypeSamplerCount;
static inline _s_e0daa6e1_structDeclaration _e0daa6e1_structDeclaration(Red2HandleStructDeclaration value) { return REDGPU_NP_STRUCT_INIT(_s_e0daa6e1_structDeclaration){value}; }
static inline _s_e0daa6e1_outStructDeclarationMembersCount _e0daa6e1_outStructDeclarationMembersCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_e0daa6e1_outStructDeclarationMembersCount){value}; }
static inline _s_e0daa6e1_outMembersOfTypeArrayROConstantCount _e0daa6e1_outMembersOfTypeArrayROConstantCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_e0daa6e1_outMembersOfTypeArrayROConstantCount){value}; }
static inline _s_e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount _e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount){value}; }
static inline _s_e0daa6e1_outMembersOfTypeTextureROCount _e0daa6e1_outMembersOfTypeTextureROCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_e0daa6e1_outMembersOfTypeTextureROCount){value}; }
static inline _s_e0daa6e1_outMembersOfTypeTextureRWCount _e0daa6e1_outMembersOfTypeTextureRWCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_e0daa6e1_outMembersOfTypeTextureRWCount){value}; }
static inline _s_e0daa6e1_outMembersOfTypeInlineSamplerCount _e0daa6e1_outMembersOfTypeInlineSamplerCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_e0daa6e1_outMembersOfTypeInlineSamplerCount){value}; }
static inline _s_e0daa6e1_outMembersOfTypeSamplerCount _e0daa6e1_outMembersOfTypeSamplerCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_e0daa6e1_outMembersOfTypeSamplerCount){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2StructDeclarationGetMembersCounts(_s_e0daa6e1_structDeclaration structDeclaration, _s_e0daa6e1_outStructDeclarationMembersCount outStructDeclarationMembersCount, _s_e0daa6e1_outMembersOfTypeArrayROConstantCount outMembersOfTypeArrayROConstantCount, _s_e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount outMembersOfTypeArrayROOrArrayRWCount, _s_e0daa6e1_outMembersOfTypeTextureROCount outMembersOfTypeTextureROCount, _s_e0daa6e1_outMembersOfTypeTextureRWCount outMembersOfTypeTextureRWCount, _s_e0daa6e1_outMembersOfTypeInlineSamplerCount outMembersOfTypeInlineSamplerCount, _s_e0daa6e1_outMembersOfTypeSamplerCount outMembersOfTypeSamplerCount) {
  red2StructDeclarationGetMembersCounts(structDeclaration.value, outStructDeclarationMembersCount.value, outMembersOfTypeArrayROConstantCount.value, outMembersOfTypeArrayROOrArrayRWCount.value, outMembersOfTypeTextureROCount.value, outMembersOfTypeTextureRWCount.value, outMembersOfTypeInlineSamplerCount.value, outMembersOfTypeSamplerCount.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2ProcedureParametersGetRedHandle red2ProcedureParametersGetRedHandle
#define _5460064b_procedureParameters(value) value
#else
typedef struct _s_5460064b_procedureParameters { Red2HandleProcedureParameters value; } _s_5460064b_procedureParameters;
static inline _s_5460064b_procedureParameters _5460064b_procedureParameters(Red2HandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_5460064b_procedureParameters){value}; }
REDGPU_NP_DECLSPEC RedHandleProcedureParameters REDGPU_NP_API np_red2ProcedureParametersGetRedHandle(_s_5460064b_procedureParameters procedureParameters) {
  return red2ProcedureParametersGetRedHandle(procedureParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2ProcedureParametersGetStructDeclaration red2ProcedureParametersGetStructDeclaration
#define _1d3e3522_procedureParameters(value) value
#define _1d3e3522_structIndex(value) value
#else
typedef struct _s_1d3e3522_procedureParameters { Red2HandleProcedureParameters value; } _s_1d3e3522_procedureParameters;
typedef struct _s_1d3e3522_structIndex { unsigned value; } _s_1d3e3522_structIndex;
static inline _s_1d3e3522_procedureParameters _1d3e3522_procedureParameters(Red2HandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_1d3e3522_procedureParameters){value}; }
static inline _s_1d3e3522_structIndex _1d3e3522_structIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1d3e3522_structIndex){value}; }
REDGPU_NP_DECLSPEC Red2HandleStructDeclaration REDGPU_NP_API np_red2ProcedureParametersGetStructDeclaration(_s_1d3e3522_procedureParameters procedureParameters, _s_1d3e3522_structIndex structIndex) {
  return red2ProcedureParametersGetStructDeclaration(procedureParameters.value, structIndex.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallsGetRedHandles red2CallsGetRedHandles
#define _e72d80fe_calls(value) value
#define _e72d80fe_outContext(value) value
#define _e72d80fe_outGpu(value) value
#define _e72d80fe_outCalls(value) value
#else
typedef struct _s_e72d80fe_calls { Red2HandleCalls value; } _s_e72d80fe_calls;
typedef struct _s_e72d80fe_outContext { RedContext* value; } _s_e72d80fe_outContext;
typedef struct _s_e72d80fe_outGpu { RedHandleGpu* value; } _s_e72d80fe_outGpu;
typedef struct _s_e72d80fe_outCalls { RedCalls* value; } _s_e72d80fe_outCalls;
static inline _s_e72d80fe_calls _e72d80fe_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_e72d80fe_calls){value}; }
static inline _s_e72d80fe_outContext _e72d80fe_outContext(RedContext* value) { return REDGPU_NP_STRUCT_INIT(_s_e72d80fe_outContext){value}; }
static inline _s_e72d80fe_outGpu _e72d80fe_outGpu(RedHandleGpu* value) { return REDGPU_NP_STRUCT_INIT(_s_e72d80fe_outGpu){value}; }
static inline _s_e72d80fe_outCalls _e72d80fe_outCalls(RedCalls* value) { return REDGPU_NP_STRUCT_INIT(_s_e72d80fe_outCalls){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallsGetRedHandles(_s_e72d80fe_calls calls, _s_e72d80fe_outContext outContext, _s_e72d80fe_outGpu outGpu, _s_e72d80fe_outCalls outCalls) {
  red2CallsGetRedHandles(calls.value, outContext.value, outGpu.value, outCalls.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallsSet red2CallsSet
#define _c239a97f_context(value) value
#define _c239a97f_gpu(value) value
#define _c239a97f_calls(value) value
#define _c239a97f_callsMemory(value) value
#define _c239a97f_callsReusable(value) value
#define _c239a97f_outStatuses(value) value
#define _c239a97f_optionalFile(value) value
#define _c239a97f_optionalLine(value) value
#define _c239a97f_optionalUserData(value) value
#else
typedef struct _s_c239a97f_context { RedContext value; } _s_c239a97f_context;
typedef struct _s_c239a97f_gpu { RedHandleGpu value; } _s_c239a97f_gpu;
typedef struct _s_c239a97f_calls { Red2HandleCalls value; } _s_c239a97f_calls;
typedef struct _s_c239a97f_callsMemory { RedHandleCallsMemory value; } _s_c239a97f_callsMemory;
typedef struct _s_c239a97f_callsReusable { RedBool32 value; } _s_c239a97f_callsReusable;
typedef struct _s_c239a97f_outStatuses { RedStatuses* value; } _s_c239a97f_outStatuses;
typedef struct _s_c239a97f_optionalFile { char* value; } _s_c239a97f_optionalFile;
typedef struct _s_c239a97f_optionalLine { int value; } _s_c239a97f_optionalLine;
typedef struct _s_c239a97f_optionalUserData { void* value; } _s_c239a97f_optionalUserData;
static inline _s_c239a97f_context _c239a97f_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_c239a97f_context){value}; }
static inline _s_c239a97f_gpu _c239a97f_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_c239a97f_gpu){value}; }
static inline _s_c239a97f_calls _c239a97f_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_c239a97f_calls){value}; }
static inline _s_c239a97f_callsMemory _c239a97f_callsMemory(RedHandleCallsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_c239a97f_callsMemory){value}; }
static inline _s_c239a97f_callsReusable _c239a97f_callsReusable(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_c239a97f_callsReusable){value}; }
static inline _s_c239a97f_outStatuses _c239a97f_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_c239a97f_outStatuses){value}; }
static inline _s_c239a97f_optionalFile _c239a97f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c239a97f_optionalFile){value}; }
static inline _s_c239a97f_optionalLine _c239a97f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c239a97f_optionalLine){value}; }
static inline _s_c239a97f_optionalUserData _c239a97f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c239a97f_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallsSet(_s_c239a97f_context context, _s_c239a97f_gpu gpu, _s_c239a97f_calls calls, _s_c239a97f_callsMemory callsMemory, _s_c239a97f_callsReusable callsReusable, _s_c239a97f_outStatuses outStatuses, _s_c239a97f_optionalFile optionalFile, _s_c239a97f_optionalLine optionalLine, _s_c239a97f_optionalUserData optionalUserData) {
  red2CallsSet(context.value, gpu.value, calls.value, callsMemory.value, callsReusable.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallsEnd red2CallsEnd
#define _f0b37588_context(value) value
#define _f0b37588_gpu(value) value
#define _f0b37588_calls(value) value
#define _f0b37588_callsMemory(value) value
#define _f0b37588_outStatuses(value) value
#define _f0b37588_optionalFile(value) value
#define _f0b37588_optionalLine(value) value
#define _f0b37588_optionalUserData(value) value
#else
typedef struct _s_f0b37588_context { RedContext value; } _s_f0b37588_context;
typedef struct _s_f0b37588_gpu { RedHandleGpu value; } _s_f0b37588_gpu;
typedef struct _s_f0b37588_calls { Red2HandleCalls value; } _s_f0b37588_calls;
typedef struct _s_f0b37588_callsMemory { RedHandleCallsMemory value; } _s_f0b37588_callsMemory;
typedef struct _s_f0b37588_outStatuses { RedStatuses* value; } _s_f0b37588_outStatuses;
typedef struct _s_f0b37588_optionalFile { char* value; } _s_f0b37588_optionalFile;
typedef struct _s_f0b37588_optionalLine { int value; } _s_f0b37588_optionalLine;
typedef struct _s_f0b37588_optionalUserData { void* value; } _s_f0b37588_optionalUserData;
static inline _s_f0b37588_context _f0b37588_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_f0b37588_context){value}; }
static inline _s_f0b37588_gpu _f0b37588_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_f0b37588_gpu){value}; }
static inline _s_f0b37588_calls _f0b37588_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_f0b37588_calls){value}; }
static inline _s_f0b37588_callsMemory _f0b37588_callsMemory(RedHandleCallsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_f0b37588_callsMemory){value}; }
static inline _s_f0b37588_outStatuses _f0b37588_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_f0b37588_outStatuses){value}; }
static inline _s_f0b37588_optionalFile _f0b37588_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f0b37588_optionalFile){value}; }
static inline _s_f0b37588_optionalLine _f0b37588_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f0b37588_optionalLine){value}; }
static inline _s_f0b37588_optionalUserData _f0b37588_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f0b37588_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallsEnd(_s_f0b37588_context context, _s_f0b37588_gpu gpu, _s_f0b37588_calls calls, _s_f0b37588_callsMemory callsMemory, _s_f0b37588_outStatuses outStatuses, _s_f0b37588_optionalFile optionalFile, _s_f0b37588_optionalLine optionalLine, _s_f0b37588_optionalUserData optionalUserData) {
  red2CallsEnd(context.value, gpu.value, calls.value, callsMemory.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallsFreeAllInlineStructsMemorys red2CallsFreeAllInlineStructsMemorys
#define _0b3f1f5f_context(value) value
#define _0b3f1f5f_gpu(value) value
#define _0b3f1f5f_calls(value) value
#define _0b3f1f5f_optionalFile(value) value
#define _0b3f1f5f_optionalLine(value) value
#define _0b3f1f5f_optionalUserData(value) value
#else
typedef struct _s_0b3f1f5f_context { RedContext value; } _s_0b3f1f5f_context;
typedef struct _s_0b3f1f5f_gpu { RedHandleGpu value; } _s_0b3f1f5f_gpu;
typedef struct _s_0b3f1f5f_calls { Red2HandleCalls value; } _s_0b3f1f5f_calls;
typedef struct _s_0b3f1f5f_optionalFile { char* value; } _s_0b3f1f5f_optionalFile;
typedef struct _s_0b3f1f5f_optionalLine { int value; } _s_0b3f1f5f_optionalLine;
typedef struct _s_0b3f1f5f_optionalUserData { void* value; } _s_0b3f1f5f_optionalUserData;
static inline _s_0b3f1f5f_context _0b3f1f5f_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_0b3f1f5f_context){value}; }
static inline _s_0b3f1f5f_gpu _0b3f1f5f_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_0b3f1f5f_gpu){value}; }
static inline _s_0b3f1f5f_calls _0b3f1f5f_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_0b3f1f5f_calls){value}; }
static inline _s_0b3f1f5f_optionalFile _0b3f1f5f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0b3f1f5f_optionalFile){value}; }
static inline _s_0b3f1f5f_optionalLine _0b3f1f5f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0b3f1f5f_optionalLine){value}; }
static inline _s_0b3f1f5f_optionalUserData _0b3f1f5f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0b3f1f5f_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallsFreeAllInlineStructsMemorys(_s_0b3f1f5f_context context, _s_0b3f1f5f_gpu gpu, _s_0b3f1f5f_calls calls, _s_0b3f1f5f_optionalFile optionalFile, _s_0b3f1f5f_optionalLine optionalLine, _s_0b3f1f5f_optionalUserData optionalUserData) {
  red2CallsFreeAllInlineStructsMemorys(context.value, gpu.value, calls.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallAllocateAndSetInlineStructsMemory red2CallAllocateAndSetInlineStructsMemory
#define _ada5e37f_calls(value) value
#define _ada5e37f_structsMemoryHandleName(value) value
#define _ada5e37f_maxStructsCount(value) value
#define _ada5e37f_maxStructsOfTypeSamplerCount(value) value
#define _ada5e37f_maxStructsMembersOfTypeArrayROConstantCount(value) value
#define _ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount(value) value
#define _ada5e37f_maxStructsMembersOfTypeTextureROCount(value) value
#define _ada5e37f_maxStructsMembersOfTypeTextureRWCount(value) value
#define _ada5e37f_maxStructsMembersOfTypeInlineSamplerCount(value) value
#define _ada5e37f_maxStructsMembersOfTypeSamplerCount(value) value
#define _ada5e37f_outStatuses(value) value
#define _ada5e37f_optionalFile(value) value
#define _ada5e37f_optionalLine(value) value
#define _ada5e37f_optionalUserData(value) value
#else
typedef struct _s_ada5e37f_calls { Red2HandleCalls value; } _s_ada5e37f_calls;
typedef struct _s_ada5e37f_structsMemoryHandleName { char* value; } _s_ada5e37f_structsMemoryHandleName;
typedef struct _s_ada5e37f_maxStructsCount { unsigned value; } _s_ada5e37f_maxStructsCount;
typedef struct _s_ada5e37f_maxStructsOfTypeSamplerCount { unsigned value; } _s_ada5e37f_maxStructsOfTypeSamplerCount;
typedef struct _s_ada5e37f_maxStructsMembersOfTypeArrayROConstantCount { unsigned value; } _s_ada5e37f_maxStructsMembersOfTypeArrayROConstantCount;
typedef struct _s_ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount { unsigned value; } _s_ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount;
typedef struct _s_ada5e37f_maxStructsMembersOfTypeTextureROCount { unsigned value; } _s_ada5e37f_maxStructsMembersOfTypeTextureROCount;
typedef struct _s_ada5e37f_maxStructsMembersOfTypeTextureRWCount { unsigned value; } _s_ada5e37f_maxStructsMembersOfTypeTextureRWCount;
typedef struct _s_ada5e37f_maxStructsMembersOfTypeInlineSamplerCount { unsigned value; } _s_ada5e37f_maxStructsMembersOfTypeInlineSamplerCount;
typedef struct _s_ada5e37f_maxStructsMembersOfTypeSamplerCount { unsigned value; } _s_ada5e37f_maxStructsMembersOfTypeSamplerCount;
typedef struct _s_ada5e37f_outStatuses { RedStatuses* value; } _s_ada5e37f_outStatuses;
typedef struct _s_ada5e37f_optionalFile { char* value; } _s_ada5e37f_optionalFile;
typedef struct _s_ada5e37f_optionalLine { int value; } _s_ada5e37f_optionalLine;
typedef struct _s_ada5e37f_optionalUserData { void* value; } _s_ada5e37f_optionalUserData;
static inline _s_ada5e37f_calls _ada5e37f_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_calls){value}; }
static inline _s_ada5e37f_structsMemoryHandleName _ada5e37f_structsMemoryHandleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_structsMemoryHandleName){value}; }
static inline _s_ada5e37f_maxStructsCount _ada5e37f_maxStructsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_maxStructsCount){value}; }
static inline _s_ada5e37f_maxStructsOfTypeSamplerCount _ada5e37f_maxStructsOfTypeSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_maxStructsOfTypeSamplerCount){value}; }
static inline _s_ada5e37f_maxStructsMembersOfTypeArrayROConstantCount _ada5e37f_maxStructsMembersOfTypeArrayROConstantCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_maxStructsMembersOfTypeArrayROConstantCount){value}; }
static inline _s_ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount _ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount){value}; }
static inline _s_ada5e37f_maxStructsMembersOfTypeTextureROCount _ada5e37f_maxStructsMembersOfTypeTextureROCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_maxStructsMembersOfTypeTextureROCount){value}; }
static inline _s_ada5e37f_maxStructsMembersOfTypeTextureRWCount _ada5e37f_maxStructsMembersOfTypeTextureRWCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_maxStructsMembersOfTypeTextureRWCount){value}; }
static inline _s_ada5e37f_maxStructsMembersOfTypeInlineSamplerCount _ada5e37f_maxStructsMembersOfTypeInlineSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_maxStructsMembersOfTypeInlineSamplerCount){value}; }
static inline _s_ada5e37f_maxStructsMembersOfTypeSamplerCount _ada5e37f_maxStructsMembersOfTypeSamplerCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_maxStructsMembersOfTypeSamplerCount){value}; }
static inline _s_ada5e37f_outStatuses _ada5e37f_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_outStatuses){value}; }
static inline _s_ada5e37f_optionalFile _ada5e37f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_optionalFile){value}; }
static inline _s_ada5e37f_optionalLine _ada5e37f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_optionalLine){value}; }
static inline _s_ada5e37f_optionalUserData _ada5e37f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ada5e37f_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallAllocateAndSetInlineStructsMemory(_s_ada5e37f_calls calls, _s_ada5e37f_structsMemoryHandleName structsMemoryHandleName, _s_ada5e37f_maxStructsCount maxStructsCount, _s_ada5e37f_maxStructsOfTypeSamplerCount maxStructsOfTypeSamplerCount, _s_ada5e37f_maxStructsMembersOfTypeArrayROConstantCount maxStructsMembersOfTypeArrayROConstantCount, _s_ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount maxStructsMembersOfTypeArrayROOrArrayRWCount, _s_ada5e37f_maxStructsMembersOfTypeTextureROCount maxStructsMembersOfTypeTextureROCount, _s_ada5e37f_maxStructsMembersOfTypeTextureRWCount maxStructsMembersOfTypeTextureRWCount, _s_ada5e37f_maxStructsMembersOfTypeInlineSamplerCount maxStructsMembersOfTypeInlineSamplerCount, _s_ada5e37f_maxStructsMembersOfTypeSamplerCount maxStructsMembersOfTypeSamplerCount, _s_ada5e37f_outStatuses outStatuses, _s_ada5e37f_optionalFile optionalFile, _s_ada5e37f_optionalLine optionalLine, _s_ada5e37f_optionalUserData optionalUserData) {
  red2CallAllocateAndSetInlineStructsMemory(calls.value, structsMemoryHandleName.value, maxStructsCount.value, maxStructsOfTypeSamplerCount.value, maxStructsMembersOfTypeArrayROConstantCount.value, maxStructsMembersOfTypeArrayROOrArrayRWCount.value, maxStructsMembersOfTypeTextureROCount.value, maxStructsMembersOfTypeTextureRWCount.value, maxStructsMembersOfTypeInlineSamplerCount.value, maxStructsMembersOfTypeSamplerCount.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters
#define _e6f48477_calls(value) value
#define _e6f48477_structsMemoryHandleName(value) value
#define _e6f48477_procedureParametersCount(value) value
#define _e6f48477_procedureParameters(value) value
#define _e6f48477_outStatuses(value) value
#define _e6f48477_optionalFile(value) value
#define _e6f48477_optionalLine(value) value
#define _e6f48477_optionalUserData(value) value
#else
typedef struct _s_e6f48477_calls { Red2HandleCalls value; } _s_e6f48477_calls;
typedef struct _s_e6f48477_structsMemoryHandleName { char* value; } _s_e6f48477_structsMemoryHandleName;
typedef struct _s_e6f48477_procedureParametersCount { unsigned value; } _s_e6f48477_procedureParametersCount;
typedef struct _s_e6f48477_procedureParameters { Red2InlineStructsMemoryFromProcedureParameters* value; } _s_e6f48477_procedureParameters;
typedef struct _s_e6f48477_outStatuses { RedStatuses* value; } _s_e6f48477_outStatuses;
typedef struct _s_e6f48477_optionalFile { char* value; } _s_e6f48477_optionalFile;
typedef struct _s_e6f48477_optionalLine { int value; } _s_e6f48477_optionalLine;
typedef struct _s_e6f48477_optionalUserData { void* value; } _s_e6f48477_optionalUserData;
static inline _s_e6f48477_calls _e6f48477_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_e6f48477_calls){value}; }
static inline _s_e6f48477_structsMemoryHandleName _e6f48477_structsMemoryHandleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e6f48477_structsMemoryHandleName){value}; }
static inline _s_e6f48477_procedureParametersCount _e6f48477_procedureParametersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e6f48477_procedureParametersCount){value}; }
static inline _s_e6f48477_procedureParameters _e6f48477_procedureParameters(Red2InlineStructsMemoryFromProcedureParameters* value) { return REDGPU_NP_STRUCT_INIT(_s_e6f48477_procedureParameters){value}; }
static inline _s_e6f48477_outStatuses _e6f48477_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_e6f48477_outStatuses){value}; }
static inline _s_e6f48477_optionalFile _e6f48477_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e6f48477_optionalFile){value}; }
static inline _s_e6f48477_optionalLine _e6f48477_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e6f48477_optionalLine){value}; }
static inline _s_e6f48477_optionalUserData _e6f48477_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e6f48477_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters(_s_e6f48477_calls calls, _s_e6f48477_structsMemoryHandleName structsMemoryHandleName, _s_e6f48477_procedureParametersCount procedureParametersCount, _s_e6f48477_procedureParameters procedureParameters, _s_e6f48477_outStatuses outStatuses, _s_e6f48477_optionalFile optionalFile, _s_e6f48477_optionalLine optionalLine, _s_e6f48477_optionalUserData optionalUserData) {
  red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters(calls.value, structsMemoryHandleName.value, procedureParametersCount.value, procedureParameters.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallSuballocateAndSetProcedureParametersInlineStruct red2CallSuballocateAndSetProcedureParametersInlineStruct
#define _0a8bd758_calls(value) value
#define _0a8bd758_procedureType(value) value
#define _0a8bd758_procedureParameters(value) value
#define _0a8bd758_structIndex(value) value
#define _0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers(value) value
#define _0a8bd758_outStatuses(value) value
#define _0a8bd758_optionalFile(value) value
#define _0a8bd758_optionalLine(value) value
#define _0a8bd758_optionalUserData(value) value
#else
typedef struct _s_0a8bd758_calls { Red2HandleCalls value; } _s_0a8bd758_calls;
typedef struct _s_0a8bd758_procedureType { RedProcedureType value; } _s_0a8bd758_procedureType;
typedef struct _s_0a8bd758_procedureParameters { Red2HandleProcedureParameters value; } _s_0a8bd758_procedureParameters;
typedef struct _s_0a8bd758_structIndex { unsigned value; } _s_0a8bd758_structIndex;
typedef struct _s_0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers { void** value; } _s_0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers;
typedef struct _s_0a8bd758_outStatuses { RedStatuses* value; } _s_0a8bd758_outStatuses;
typedef struct _s_0a8bd758_optionalFile { char* value; } _s_0a8bd758_optionalFile;
typedef struct _s_0a8bd758_optionalLine { int value; } _s_0a8bd758_optionalLine;
typedef struct _s_0a8bd758_optionalUserData { void* value; } _s_0a8bd758_optionalUserData;
static inline _s_0a8bd758_calls _0a8bd758_calls(Red2HandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_0a8bd758_calls){value}; }
static inline _s_0a8bd758_procedureType _0a8bd758_procedureType(RedProcedureType value) { return REDGPU_NP_STRUCT_INIT(_s_0a8bd758_procedureType){value}; }
static inline _s_0a8bd758_procedureParameters _0a8bd758_procedureParameters(Red2HandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_0a8bd758_procedureParameters){value}; }
static inline _s_0a8bd758_structIndex _0a8bd758_structIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_0a8bd758_structIndex){value}; }
static inline _s_0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers _0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers(void** value) { return REDGPU_NP_STRUCT_INIT(_s_0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers){value}; }
static inline _s_0a8bd758_outStatuses _0a8bd758_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_0a8bd758_outStatuses){value}; }
static inline _s_0a8bd758_optionalFile _0a8bd758_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0a8bd758_optionalFile){value}; }
static inline _s_0a8bd758_optionalLine _0a8bd758_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0a8bd758_optionalLine){value}; }
static inline _s_0a8bd758_optionalUserData _0a8bd758_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0a8bd758_optionalUserData){value}; }
REDGPU_NP_DECLSPEC RedStatus REDGPU_NP_API np_red2CallSuballocateAndSetProcedureParametersInlineStruct(_s_0a8bd758_calls calls, _s_0a8bd758_procedureType procedureType, _s_0a8bd758_procedureParameters procedureParameters, _s_0a8bd758_structIndex structIndex, _s_0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers, _s_0a8bd758_outStatuses outStatuses, _s_0a8bd758_optionalFile optionalFile, _s_0a8bd758_optionalLine optionalLine, _s_0a8bd758_optionalUserData optionalUserData) {
  return red2CallSuballocateAndSetProcedureParametersInlineStruct(calls.value, procedureType.value, procedureParameters.value, structIndex.value, structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2PresentGetImageIndex red2PresentGetImageIndex
#define _80ee055a_context(value) value
#define _80ee055a_gpu(value) value
#define _80ee055a_present(value) value
#define _80ee055a_signalCpuSignal(value) value
#define _80ee055a_signalGpuSignal(value) value
#define _80ee055a_outImageIndex(value) value
#define _80ee055a_outStatuses(value) value
#define _80ee055a_optionalFile(value) value
#define _80ee055a_optionalLine(value) value
#define _80ee055a_optionalUserData(value) value
#else
typedef struct _s_80ee055a_context { RedContext value; } _s_80ee055a_context;
typedef struct _s_80ee055a_gpu { RedHandleGpu value; } _s_80ee055a_gpu;
typedef struct _s_80ee055a_present { RedHandlePresent value; } _s_80ee055a_present;
typedef struct _s_80ee055a_signalCpuSignal { RedHandleCpuSignal value; } _s_80ee055a_signalCpuSignal;
typedef struct _s_80ee055a_signalGpuSignal { RedHandleGpuSignal value; } _s_80ee055a_signalGpuSignal;
typedef struct _s_80ee055a_outImageIndex { unsigned* value; } _s_80ee055a_outImageIndex;
typedef struct _s_80ee055a_outStatuses { RedStatuses* value; } _s_80ee055a_outStatuses;
typedef struct _s_80ee055a_optionalFile { char* value; } _s_80ee055a_optionalFile;
typedef struct _s_80ee055a_optionalLine { int value; } _s_80ee055a_optionalLine;
typedef struct _s_80ee055a_optionalUserData { void* value; } _s_80ee055a_optionalUserData;
static inline _s_80ee055a_context _80ee055a_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_80ee055a_context){value}; }
static inline _s_80ee055a_gpu _80ee055a_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_80ee055a_gpu){value}; }
static inline _s_80ee055a_present _80ee055a_present(RedHandlePresent value) { return REDGPU_NP_STRUCT_INIT(_s_80ee055a_present){value}; }
static inline _s_80ee055a_signalCpuSignal _80ee055a_signalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_80ee055a_signalCpuSignal){value}; }
static inline _s_80ee055a_signalGpuSignal _80ee055a_signalGpuSignal(RedHandleGpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_80ee055a_signalGpuSignal){value}; }
static inline _s_80ee055a_outImageIndex _80ee055a_outImageIndex(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_80ee055a_outImageIndex){value}; }
static inline _s_80ee055a_outStatuses _80ee055a_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_80ee055a_outStatuses){value}; }
static inline _s_80ee055a_optionalFile _80ee055a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_80ee055a_optionalFile){value}; }
static inline _s_80ee055a_optionalLine _80ee055a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_80ee055a_optionalLine){value}; }
static inline _s_80ee055a_optionalUserData _80ee055a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_80ee055a_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2PresentGetImageIndex(_s_80ee055a_context context, _s_80ee055a_gpu gpu, _s_80ee055a_present present, _s_80ee055a_signalCpuSignal signalCpuSignal, _s_80ee055a_signalGpuSignal signalGpuSignal, _s_80ee055a_outImageIndex outImageIndex, _s_80ee055a_outStatuses outStatuses, _s_80ee055a_optionalFile optionalFile, _s_80ee055a_optionalLine optionalLine, _s_80ee055a_optionalUserData optionalUserData) {
  red2PresentGetImageIndex(context.value, gpu.value, present.value, signalCpuSignal.value, signalGpuSignal.value, outImageIndex.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2QueueSubmit red2QueueSubmit
#define _24f77dc7_context(value) value
#define _24f77dc7_gpu(value) value
#define _24f77dc7_queue(value) value
#define _24f77dc7_timelinesCount(value) value
#define _24f77dc7_timelines(value) value
#define _24f77dc7_outQueueSubmissionTicketArrayIndex(value) value
#define _24f77dc7_outQueueSubmissionTicket(value) value
#define _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount(value) value
#define _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles(value) value
#define _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType(value) value
#define _24f77dc7_optionalCustomHandleTypeDestroyCallback(value) value
#define _24f77dc7_outStatuses(value) value
#define _24f77dc7_optionalFile(value) value
#define _24f77dc7_optionalLine(value) value
#define _24f77dc7_optionalUserData(value) value
#else
typedef struct _s_24f77dc7_context { RedContext value; } _s_24f77dc7_context;
typedef struct _s_24f77dc7_gpu { RedHandleGpu value; } _s_24f77dc7_gpu;
typedef struct _s_24f77dc7_queue { RedHandleQueue value; } _s_24f77dc7_queue;
typedef struct _s_24f77dc7_timelinesCount { unsigned value; } _s_24f77dc7_timelinesCount;
typedef struct _s_24f77dc7_timelines { RedGpuTimeline* value; } _s_24f77dc7_timelines;
typedef struct _s_24f77dc7_outQueueSubmissionTicketArrayIndex { uint64_t* value; } _s_24f77dc7_outQueueSubmissionTicketArrayIndex;
typedef struct _s_24f77dc7_outQueueSubmissionTicket { uint64_t* value; } _s_24f77dc7_outQueueSubmissionTicket;
typedef struct _s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount { uint64_t value; } _s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount;
typedef struct _s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles { void** value; } _s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles;
typedef struct _s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType { unsigned* value; } _s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType;
typedef struct _s_24f77dc7_optionalCustomHandleTypeDestroyCallback { void* value; } _s_24f77dc7_optionalCustomHandleTypeDestroyCallback;
typedef struct _s_24f77dc7_outStatuses { RedStatuses* value; } _s_24f77dc7_outStatuses;
typedef struct _s_24f77dc7_optionalFile { char* value; } _s_24f77dc7_optionalFile;
typedef struct _s_24f77dc7_optionalLine { int value; } _s_24f77dc7_optionalLine;
typedef struct _s_24f77dc7_optionalUserData { void* value; } _s_24f77dc7_optionalUserData;
static inline _s_24f77dc7_context _24f77dc7_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_context){value}; }
static inline _s_24f77dc7_gpu _24f77dc7_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_gpu){value}; }
static inline _s_24f77dc7_queue _24f77dc7_queue(RedHandleQueue value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_queue){value}; }
static inline _s_24f77dc7_timelinesCount _24f77dc7_timelinesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_timelinesCount){value}; }
static inline _s_24f77dc7_timelines _24f77dc7_timelines(RedGpuTimeline* value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_timelines){value}; }
static inline _s_24f77dc7_outQueueSubmissionTicketArrayIndex _24f77dc7_outQueueSubmissionTicketArrayIndex(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_outQueueSubmissionTicketArrayIndex){value}; }
static inline _s_24f77dc7_outQueueSubmissionTicket _24f77dc7_outQueueSubmissionTicket(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_outQueueSubmissionTicket){value}; }
static inline _s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount){value}; }
static inline _s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles(void** value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles){value}; }
static inline _s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType){value}; }
static inline _s_24f77dc7_optionalCustomHandleTypeDestroyCallback _24f77dc7_optionalCustomHandleTypeDestroyCallback(void* value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_optionalCustomHandleTypeDestroyCallback){value}; }
static inline _s_24f77dc7_outStatuses _24f77dc7_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_outStatuses){value}; }
static inline _s_24f77dc7_optionalFile _24f77dc7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_optionalFile){value}; }
static inline _s_24f77dc7_optionalLine _24f77dc7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_optionalLine){value}; }
static inline _s_24f77dc7_optionalUserData _24f77dc7_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_24f77dc7_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2QueueSubmit(_s_24f77dc7_context context, _s_24f77dc7_gpu gpu, _s_24f77dc7_queue queue, _s_24f77dc7_timelinesCount timelinesCount, _s_24f77dc7_timelines timelines, _s_24f77dc7_outQueueSubmissionTicketArrayIndex outQueueSubmissionTicketArrayIndex, _s_24f77dc7_outQueueSubmissionTicket outQueueSubmissionTicket, _s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount whenQueueSubmissionIsFinishedDestroyHandlesCount, _s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles whenQueueSubmissionIsFinishedDestroyHandles, _s_24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType whenQueueSubmissionIsFinishedDestroyHandlesHandleType, _s_24f77dc7_optionalCustomHandleTypeDestroyCallback optionalCustomHandleTypeDestroyCallback, _s_24f77dc7_outStatuses outStatuses, _s_24f77dc7_optionalFile optionalFile, _s_24f77dc7_optionalLine optionalLine, _s_24f77dc7_optionalUserData optionalUserData) {
  red2QueueSubmit(context.value, gpu.value, queue.value, timelinesCount.value, timelines.value, outQueueSubmissionTicketArrayIndex.value, outQueueSubmissionTicket.value, whenQueueSubmissionIsFinishedDestroyHandlesCount.value, whenQueueSubmissionIsFinishedDestroyHandles.value, whenQueueSubmissionIsFinishedDestroyHandlesHandleType.value, optionalCustomHandleTypeDestroyCallback.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2IsQueueSubmissionFinished red2IsQueueSubmissionFinished
#define _d6a2b07e_queueSubmissionTicketArrayIndex(value) value
#define _d6a2b07e_queueSubmissionTicket(value) value
#define _d6a2b07e_optionalFile(value) value
#define _d6a2b07e_optionalLine(value) value
#define _d6a2b07e_optionalUserData(value) value
#else
typedef struct _s_d6a2b07e_queueSubmissionTicketArrayIndex { uint64_t value; } _s_d6a2b07e_queueSubmissionTicketArrayIndex;
typedef struct _s_d6a2b07e_queueSubmissionTicket { uint64_t value; } _s_d6a2b07e_queueSubmissionTicket;
typedef struct _s_d6a2b07e_optionalFile { char* value; } _s_d6a2b07e_optionalFile;
typedef struct _s_d6a2b07e_optionalLine { int value; } _s_d6a2b07e_optionalLine;
typedef struct _s_d6a2b07e_optionalUserData { void* value; } _s_d6a2b07e_optionalUserData;
static inline _s_d6a2b07e_queueSubmissionTicketArrayIndex _d6a2b07e_queueSubmissionTicketArrayIndex(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_d6a2b07e_queueSubmissionTicketArrayIndex){value}; }
static inline _s_d6a2b07e_queueSubmissionTicket _d6a2b07e_queueSubmissionTicket(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_d6a2b07e_queueSubmissionTicket){value}; }
static inline _s_d6a2b07e_optionalFile _d6a2b07e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d6a2b07e_optionalFile){value}; }
static inline _s_d6a2b07e_optionalLine _d6a2b07e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d6a2b07e_optionalLine){value}; }
static inline _s_d6a2b07e_optionalUserData _d6a2b07e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d6a2b07e_optionalUserData){value}; }
REDGPU_NP_DECLSPEC RedBool32 REDGPU_NP_API np_red2IsQueueSubmissionFinished(_s_d6a2b07e_queueSubmissionTicketArrayIndex queueSubmissionTicketArrayIndex, _s_d6a2b07e_queueSubmissionTicket queueSubmissionTicket, _s_d6a2b07e_optionalFile optionalFile, _s_d6a2b07e_optionalLine optionalLine, _s_d6a2b07e_optionalUserData optionalUserData) {
  return red2IsQueueSubmissionFinished(queueSubmissionTicketArrayIndex.value, queueSubmissionTicket.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2IsQueueSubmissionFinishedByTicketAlone red2IsQueueSubmissionFinishedByTicketAlone
#define _f960b352_queueSubmissionTicket(value) value
#define _f960b352_optionalFile(value) value
#define _f960b352_optionalLine(value) value
#define _f960b352_optionalUserData(value) value
#else
typedef struct _s_f960b352_queueSubmissionTicket { uint64_t value; } _s_f960b352_queueSubmissionTicket;
typedef struct _s_f960b352_optionalFile { char* value; } _s_f960b352_optionalFile;
typedef struct _s_f960b352_optionalLine { int value; } _s_f960b352_optionalLine;
typedef struct _s_f960b352_optionalUserData { void* value; } _s_f960b352_optionalUserData;
static inline _s_f960b352_queueSubmissionTicket _f960b352_queueSubmissionTicket(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_f960b352_queueSubmissionTicket){value}; }
static inline _s_f960b352_optionalFile _f960b352_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f960b352_optionalFile){value}; }
static inline _s_f960b352_optionalLine _f960b352_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f960b352_optionalLine){value}; }
static inline _s_f960b352_optionalUserData _f960b352_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f960b352_optionalUserData){value}; }
REDGPU_NP_DECLSPEC RedBool32 REDGPU_NP_API np_red2IsQueueSubmissionFinishedByTicketAlone(_s_f960b352_queueSubmissionTicket queueSubmissionTicket, _s_f960b352_optionalFile optionalFile, _s_f960b352_optionalLine optionalLine, _s_f960b352_optionalUserData optionalUserData) {
  return red2IsQueueSubmissionFinishedByTicketAlone(queueSubmissionTicket.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket
#define _05c69089_context(value) value
#define _05c69089_gpu(value) value
#define _05c69089_queueSubmissionTicket(value) value
#define _05c69089_outStatuses(value) value
#define _05c69089_optionalFile(value) value
#define _05c69089_optionalLine(value) value
#define _05c69089_optionalUserData(value) value
#else
typedef struct _s_05c69089_context { RedContext value; } _s_05c69089_context;
typedef struct _s_05c69089_gpu { RedHandleGpu value; } _s_05c69089_gpu;
typedef struct _s_05c69089_queueSubmissionTicket { uint64_t value; } _s_05c69089_queueSubmissionTicket;
typedef struct _s_05c69089_outStatuses { RedStatuses* value; } _s_05c69089_outStatuses;
typedef struct _s_05c69089_optionalFile { char* value; } _s_05c69089_optionalFile;
typedef struct _s_05c69089_optionalLine { int value; } _s_05c69089_optionalLine;
typedef struct _s_05c69089_optionalUserData { void* value; } _s_05c69089_optionalUserData;
static inline _s_05c69089_context _05c69089_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_05c69089_context){value}; }
static inline _s_05c69089_gpu _05c69089_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_05c69089_gpu){value}; }
static inline _s_05c69089_queueSubmissionTicket _05c69089_queueSubmissionTicket(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_05c69089_queueSubmissionTicket){value}; }
static inline _s_05c69089_outStatuses _05c69089_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_05c69089_outStatuses){value}; }
static inline _s_05c69089_optionalFile _05c69089_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_05c69089_optionalFile){value}; }
static inline _s_05c69089_optionalLine _05c69089_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_05c69089_optionalLine){value}; }
static inline _s_05c69089_optionalUserData _05c69089_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_05c69089_optionalUserData){value}; }
REDGPU_NP_DECLSPEC RedBool32 REDGPU_NP_API np_red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket(_s_05c69089_context context, _s_05c69089_gpu gpu, _s_05c69089_queueSubmissionTicket queueSubmissionTicket, _s_05c69089_outStatuses outStatuses, _s_05c69089_optionalFile optionalFile, _s_05c69089_optionalLine optionalLine, _s_05c69089_optionalUserData optionalUserData) {
  return red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket(context.value, gpu.value, queueSubmissionTicket.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2WaitForQueueSubmissionToFinish red2WaitForQueueSubmissionToFinish
#define _b58bb58e_queueSubmissionTicketArrayIndex(value) value
#define _b58bb58e_queueSubmissionTicket(value) value
#define _b58bb58e_outStatuses(value) value
#define _b58bb58e_optionalFile(value) value
#define _b58bb58e_optionalLine(value) value
#define _b58bb58e_optionalUserData(value) value
#else
typedef struct _s_b58bb58e_queueSubmissionTicketArrayIndex { uint64_t value; } _s_b58bb58e_queueSubmissionTicketArrayIndex;
typedef struct _s_b58bb58e_queueSubmissionTicket { uint64_t value; } _s_b58bb58e_queueSubmissionTicket;
typedef struct _s_b58bb58e_outStatuses { RedStatuses* value; } _s_b58bb58e_outStatuses;
typedef struct _s_b58bb58e_optionalFile { char* value; } _s_b58bb58e_optionalFile;
typedef struct _s_b58bb58e_optionalLine { int value; } _s_b58bb58e_optionalLine;
typedef struct _s_b58bb58e_optionalUserData { void* value; } _s_b58bb58e_optionalUserData;
static inline _s_b58bb58e_queueSubmissionTicketArrayIndex _b58bb58e_queueSubmissionTicketArrayIndex(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_b58bb58e_queueSubmissionTicketArrayIndex){value}; }
static inline _s_b58bb58e_queueSubmissionTicket _b58bb58e_queueSubmissionTicket(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_b58bb58e_queueSubmissionTicket){value}; }
static inline _s_b58bb58e_outStatuses _b58bb58e_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b58bb58e_outStatuses){value}; }
static inline _s_b58bb58e_optionalFile _b58bb58e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b58bb58e_optionalFile){value}; }
static inline _s_b58bb58e_optionalLine _b58bb58e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b58bb58e_optionalLine){value}; }
static inline _s_b58bb58e_optionalUserData _b58bb58e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b58bb58e_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2WaitForQueueSubmissionToFinish(_s_b58bb58e_queueSubmissionTicketArrayIndex queueSubmissionTicketArrayIndex, _s_b58bb58e_queueSubmissionTicket queueSubmissionTicket, _s_b58bb58e_outStatuses outStatuses, _s_b58bb58e_optionalFile optionalFile, _s_b58bb58e_optionalLine optionalLine, _s_b58bb58e_optionalUserData optionalUserData) {
  red2WaitForQueueSubmissionToFinish(queueSubmissionTicketArrayIndex.value, queueSubmissionTicket.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2WaitForQueueSubmissionToFinishByTicketAlone red2WaitForQueueSubmissionToFinishByTicketAlone
#define _19ddb3ff_queueSubmissionTicket(value) value
#define _19ddb3ff_outStatuses(value) value
#define _19ddb3ff_optionalFile(value) value
#define _19ddb3ff_optionalLine(value) value
#define _19ddb3ff_optionalUserData(value) value
#else
typedef struct _s_19ddb3ff_queueSubmissionTicket { uint64_t value; } _s_19ddb3ff_queueSubmissionTicket;
typedef struct _s_19ddb3ff_outStatuses { RedStatuses* value; } _s_19ddb3ff_outStatuses;
typedef struct _s_19ddb3ff_optionalFile { char* value; } _s_19ddb3ff_optionalFile;
typedef struct _s_19ddb3ff_optionalLine { int value; } _s_19ddb3ff_optionalLine;
typedef struct _s_19ddb3ff_optionalUserData { void* value; } _s_19ddb3ff_optionalUserData;
static inline _s_19ddb3ff_queueSubmissionTicket _19ddb3ff_queueSubmissionTicket(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_19ddb3ff_queueSubmissionTicket){value}; }
static inline _s_19ddb3ff_outStatuses _19ddb3ff_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_19ddb3ff_outStatuses){value}; }
static inline _s_19ddb3ff_optionalFile _19ddb3ff_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_19ddb3ff_optionalFile){value}; }
static inline _s_19ddb3ff_optionalLine _19ddb3ff_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_19ddb3ff_optionalLine){value}; }
static inline _s_19ddb3ff_optionalUserData _19ddb3ff_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_19ddb3ff_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2WaitForQueueSubmissionToFinishByTicketAlone(_s_19ddb3ff_queueSubmissionTicket queueSubmissionTicket, _s_19ddb3ff_outStatuses outStatuses, _s_19ddb3ff_optionalFile optionalFile, _s_19ddb3ff_optionalLine optionalLine, _s_19ddb3ff_optionalUserData optionalUserData) {
  red2WaitForQueueSubmissionToFinishByTicketAlone(queueSubmissionTicket.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket
#define _55ec80ef_context(value) value
#define _55ec80ef_gpu(value) value
#define _55ec80ef_queueSubmissionTicket(value) value
#define _55ec80ef_outStatuses(value) value
#define _55ec80ef_optionalFile(value) value
#define _55ec80ef_optionalLine(value) value
#define _55ec80ef_optionalUserData(value) value
#else
typedef struct _s_55ec80ef_context { RedContext value; } _s_55ec80ef_context;
typedef struct _s_55ec80ef_gpu { RedHandleGpu value; } _s_55ec80ef_gpu;
typedef struct _s_55ec80ef_queueSubmissionTicket { uint64_t value; } _s_55ec80ef_queueSubmissionTicket;
typedef struct _s_55ec80ef_outStatuses { RedStatuses* value; } _s_55ec80ef_outStatuses;
typedef struct _s_55ec80ef_optionalFile { char* value; } _s_55ec80ef_optionalFile;
typedef struct _s_55ec80ef_optionalLine { int value; } _s_55ec80ef_optionalLine;
typedef struct _s_55ec80ef_optionalUserData { void* value; } _s_55ec80ef_optionalUserData;
static inline _s_55ec80ef_context _55ec80ef_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_55ec80ef_context){value}; }
static inline _s_55ec80ef_gpu _55ec80ef_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_55ec80ef_gpu){value}; }
static inline _s_55ec80ef_queueSubmissionTicket _55ec80ef_queueSubmissionTicket(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_55ec80ef_queueSubmissionTicket){value}; }
static inline _s_55ec80ef_outStatuses _55ec80ef_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_55ec80ef_outStatuses){value}; }
static inline _s_55ec80ef_optionalFile _55ec80ef_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_55ec80ef_optionalFile){value}; }
static inline _s_55ec80ef_optionalLine _55ec80ef_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_55ec80ef_optionalLine){value}; }
static inline _s_55ec80ef_optionalUserData _55ec80ef_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_55ec80ef_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket(_s_55ec80ef_context context, _s_55ec80ef_gpu gpu, _s_55ec80ef_queueSubmissionTicket queueSubmissionTicket, _s_55ec80ef_outStatuses outStatuses, _s_55ec80ef_optionalFile optionalFile, _s_55ec80ef_optionalLine optionalLine, _s_55ec80ef_optionalUserData optionalUserData) {
  red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket(context.value, gpu.value, queueSubmissionTicket.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2WaitForAllQueueSubmissionsToFinish red2WaitForAllQueueSubmissionsToFinish
#define _005c3675_context(value) value
#define _005c3675_gpu(value) value
#define _005c3675_outStatuses(value) value
#define _005c3675_optionalFile(value) value
#define _005c3675_optionalLine(value) value
#define _005c3675_optionalUserData(value) value
#else
typedef struct _s_005c3675_context { RedContext value; } _s_005c3675_context;
typedef struct _s_005c3675_gpu { RedHandleGpu value; } _s_005c3675_gpu;
typedef struct _s_005c3675_outStatuses { RedStatuses* value; } _s_005c3675_outStatuses;
typedef struct _s_005c3675_optionalFile { char* value; } _s_005c3675_optionalFile;
typedef struct _s_005c3675_optionalLine { int value; } _s_005c3675_optionalLine;
typedef struct _s_005c3675_optionalUserData { void* value; } _s_005c3675_optionalUserData;
static inline _s_005c3675_context _005c3675_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_005c3675_context){value}; }
static inline _s_005c3675_gpu _005c3675_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_005c3675_gpu){value}; }
static inline _s_005c3675_outStatuses _005c3675_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_005c3675_outStatuses){value}; }
static inline _s_005c3675_optionalFile _005c3675_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_005c3675_optionalFile){value}; }
static inline _s_005c3675_optionalLine _005c3675_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_005c3675_optionalLine){value}; }
static inline _s_005c3675_optionalUserData _005c3675_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_005c3675_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2WaitForAllQueueSubmissionsToFinish(_s_005c3675_context context, _s_005c3675_gpu gpu, _s_005c3675_outStatuses outStatuses, _s_005c3675_optionalFile optionalFile, _s_005c3675_optionalLine optionalLine, _s_005c3675_optionalUserData optionalUserData) {
  red2WaitForAllQueueSubmissionsToFinish(context.value, gpu.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2CallUsageAliasOrderBarrier red2CallUsageAliasOrderBarrier
#define _8d323fdd_address(value) value
#define _8d323fdd_calls(value) value
#define _8d323fdd_context(value) value
#define _8d323fdd_gpu(value) value
#define _8d323fdd_arrayUsagesCount(value) value
#define _8d323fdd_arrayUsages(value) value
#define _8d323fdd_imageUsagesCount(value) value
#define _8d323fdd_imageUsages(value) value
#define _8d323fdd_aliasesCount(value) value
#define _8d323fdd_aliases(value) value
#define _8d323fdd_ordersCount(value) value
#define _8d323fdd_orders(value) value
#define _8d323fdd_dependencyByRegion(value) value
#else
typedef struct _s_8d323fdd_address { RedTypeProcedureAddressCallUsageAliasOrderBarrier value; } _s_8d323fdd_address;
typedef struct _s_8d323fdd_calls { RedHandleCalls value; } _s_8d323fdd_calls;
typedef struct _s_8d323fdd_context { RedContext value; } _s_8d323fdd_context;
typedef struct _s_8d323fdd_gpu { RedHandleGpu value; } _s_8d323fdd_gpu;
typedef struct _s_8d323fdd_arrayUsagesCount { unsigned value; } _s_8d323fdd_arrayUsagesCount;
typedef struct _s_8d323fdd_arrayUsages { RedUsageArray* value; } _s_8d323fdd_arrayUsages;
typedef struct _s_8d323fdd_imageUsagesCount { unsigned value; } _s_8d323fdd_imageUsagesCount;
typedef struct _s_8d323fdd_imageUsages { RedUsageImage* value; } _s_8d323fdd_imageUsages;
typedef struct _s_8d323fdd_aliasesCount { unsigned value; } _s_8d323fdd_aliasesCount;
typedef struct _s_8d323fdd_aliases { RedAlias* value; } _s_8d323fdd_aliases;
typedef struct _s_8d323fdd_ordersCount { unsigned value; } _s_8d323fdd_ordersCount;
typedef struct _s_8d323fdd_orders { RedOrder* value; } _s_8d323fdd_orders;
typedef struct _s_8d323fdd_dependencyByRegion { RedBool32 value; } _s_8d323fdd_dependencyByRegion;
static inline _s_8d323fdd_address _8d323fdd_address(RedTypeProcedureAddressCallUsageAliasOrderBarrier value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_address){value}; }
static inline _s_8d323fdd_calls _8d323fdd_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_calls){value}; }
static inline _s_8d323fdd_context _8d323fdd_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_context){value}; }
static inline _s_8d323fdd_gpu _8d323fdd_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_gpu){value}; }
static inline _s_8d323fdd_arrayUsagesCount _8d323fdd_arrayUsagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_arrayUsagesCount){value}; }
static inline _s_8d323fdd_arrayUsages _8d323fdd_arrayUsages(RedUsageArray* value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_arrayUsages){value}; }
static inline _s_8d323fdd_imageUsagesCount _8d323fdd_imageUsagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_imageUsagesCount){value}; }
static inline _s_8d323fdd_imageUsages _8d323fdd_imageUsages(RedUsageImage* value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_imageUsages){value}; }
static inline _s_8d323fdd_aliasesCount _8d323fdd_aliasesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_aliasesCount){value}; }
static inline _s_8d323fdd_aliases _8d323fdd_aliases(RedAlias* value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_aliases){value}; }
static inline _s_8d323fdd_ordersCount _8d323fdd_ordersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_ordersCount){value}; }
static inline _s_8d323fdd_orders _8d323fdd_orders(RedOrder* value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_orders){value}; }
static inline _s_8d323fdd_dependencyByRegion _8d323fdd_dependencyByRegion(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_8d323fdd_dependencyByRegion){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_red2CallUsageAliasOrderBarrier(_s_8d323fdd_address address, _s_8d323fdd_calls calls, _s_8d323fdd_context context, _s_8d323fdd_gpu gpu, _s_8d323fdd_arrayUsagesCount arrayUsagesCount, _s_8d323fdd_arrayUsages arrayUsages, _s_8d323fdd_imageUsagesCount imageUsagesCount, _s_8d323fdd_imageUsages imageUsages, _s_8d323fdd_aliasesCount aliasesCount, _s_8d323fdd_aliases aliases, _s_8d323fdd_ordersCount ordersCount, _s_8d323fdd_orders orders, _s_8d323fdd_dependencyByRegion dependencyByRegion) {
  red2CallUsageAliasOrderBarrier(address.value, calls.value, context.value, gpu.value, arrayUsagesCount.value, arrayUsages.value, imageUsagesCount.value, imageUsages.value, aliasesCount.value, aliases.value, ordersCount.value, orders.value, dependencyByRegion.value);
}
#endif

