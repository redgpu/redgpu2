#pragma once

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
typedef struct _bcda7434_context { _bcda7434_context(RedContext value): value(value) {}; RedContext value; _bcda7434_context(const _bcda7434_context &) = delete; } _bcda7434_context;
typedef struct _bcda7434_gpu { _bcda7434_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _bcda7434_gpu(const _bcda7434_gpu &) = delete; } _bcda7434_gpu;
typedef struct _bcda7434_handleName { _bcda7434_handleName(char* value): value(value) {}; char* value; _bcda7434_handleName(const _bcda7434_handleName &) = delete; } _bcda7434_handleName;
typedef struct _bcda7434_structDeclarationMembersCount { _bcda7434_structDeclarationMembersCount(unsigned value): value(value) {}; unsigned value; _bcda7434_structDeclarationMembersCount(const _bcda7434_structDeclarationMembersCount &) = delete; } _bcda7434_structDeclarationMembersCount;
typedef struct _bcda7434_structDeclarationMembers { _bcda7434_structDeclarationMembers(RedStructDeclarationMember* value): value(value) {}; RedStructDeclarationMember* value; _bcda7434_structDeclarationMembers(const _bcda7434_structDeclarationMembers &) = delete; } _bcda7434_structDeclarationMembers;
typedef struct _bcda7434_structDeclarationMembersArrayROCount { _bcda7434_structDeclarationMembersArrayROCount(unsigned value): value(value) {}; unsigned value; _bcda7434_structDeclarationMembersArrayROCount(const _bcda7434_structDeclarationMembersArrayROCount &) = delete; } _bcda7434_structDeclarationMembersArrayROCount;
typedef struct _bcda7434_structDeclarationMembersArrayRO { _bcda7434_structDeclarationMembersArrayRO(RedStructDeclarationMemberArrayRO* value): value(value) {}; RedStructDeclarationMemberArrayRO* value; _bcda7434_structDeclarationMembersArrayRO(const _bcda7434_structDeclarationMembersArrayRO &) = delete; } _bcda7434_structDeclarationMembersArrayRO;
typedef struct _bcda7434_procedureParametersHandlesDeclaration { _bcda7434_procedureParametersHandlesDeclaration(RedBool32 value): value(value) {}; RedBool32 value; _bcda7434_procedureParametersHandlesDeclaration(const _bcda7434_procedureParametersHandlesDeclaration &) = delete; } _bcda7434_procedureParametersHandlesDeclaration;
typedef struct _bcda7434_outStructDeclaration { _bcda7434_outStructDeclaration(Red2HandleStructDeclaration* value): value(value) {}; Red2HandleStructDeclaration* value; _bcda7434_outStructDeclaration(const _bcda7434_outStructDeclaration &) = delete; } _bcda7434_outStructDeclaration;
typedef struct _bcda7434_outStatuses { _bcda7434_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _bcda7434_outStatuses(const _bcda7434_outStatuses &) = delete; } _bcda7434_outStatuses;
typedef struct _bcda7434_optionalFile { _bcda7434_optionalFile(char* value): value(value) {}; char* value; _bcda7434_optionalFile(const _bcda7434_optionalFile &) = delete; } _bcda7434_optionalFile;
typedef struct _bcda7434_optionalLine { _bcda7434_optionalLine(int value): value(value) {}; int value; _bcda7434_optionalLine(const _bcda7434_optionalLine &) = delete; } _bcda7434_optionalLine;
typedef struct _bcda7434_optionalUserData { _bcda7434_optionalUserData(void* value): value(value) {}; void* value; _bcda7434_optionalUserData(const _bcda7434_optionalUserData &) = delete; } _bcda7434_optionalUserData;
void np_red2CreateStructDeclaration(_bcda7434_context & context, _bcda7434_gpu & gpu, _bcda7434_handleName & handleName, _bcda7434_structDeclarationMembersCount & structDeclarationMembersCount, _bcda7434_structDeclarationMembers & structDeclarationMembers, _bcda7434_structDeclarationMembersArrayROCount & structDeclarationMembersArrayROCount, _bcda7434_structDeclarationMembersArrayRO & structDeclarationMembersArrayRO, _bcda7434_procedureParametersHandlesDeclaration & procedureParametersHandlesDeclaration, _bcda7434_outStructDeclaration & outStructDeclaration, _bcda7434_outStatuses & outStatuses, _bcda7434_optionalFile & optionalFile, _bcda7434_optionalLine & optionalLine, _bcda7434_optionalUserData & optionalUserData) {
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
typedef struct _4d4b0ee3_context { _4d4b0ee3_context(RedContext value): value(value) {}; RedContext value; _4d4b0ee3_context(const _4d4b0ee3_context &) = delete; } _4d4b0ee3_context;
typedef struct _4d4b0ee3_gpu { _4d4b0ee3_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _4d4b0ee3_gpu(const _4d4b0ee3_gpu &) = delete; } _4d4b0ee3_gpu;
typedef struct _4d4b0ee3_handleName { _4d4b0ee3_handleName(char* value): value(value) {}; char* value; _4d4b0ee3_handleName(const _4d4b0ee3_handleName &) = delete; } _4d4b0ee3_handleName;
typedef struct _4d4b0ee3_procedureParametersDeclaration { _4d4b0ee3_procedureParametersDeclaration(Red2ProcedureParametersDeclaration* value): value(value) {}; Red2ProcedureParametersDeclaration* value; _4d4b0ee3_procedureParametersDeclaration(const _4d4b0ee3_procedureParametersDeclaration &) = delete; } _4d4b0ee3_procedureParametersDeclaration;
typedef struct _4d4b0ee3_outProcedureParameters { _4d4b0ee3_outProcedureParameters(Red2HandleProcedureParameters* value): value(value) {}; Red2HandleProcedureParameters* value; _4d4b0ee3_outProcedureParameters(const _4d4b0ee3_outProcedureParameters &) = delete; } _4d4b0ee3_outProcedureParameters;
typedef struct _4d4b0ee3_outStatuses { _4d4b0ee3_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _4d4b0ee3_outStatuses(const _4d4b0ee3_outStatuses &) = delete; } _4d4b0ee3_outStatuses;
typedef struct _4d4b0ee3_optionalFile { _4d4b0ee3_optionalFile(char* value): value(value) {}; char* value; _4d4b0ee3_optionalFile(const _4d4b0ee3_optionalFile &) = delete; } _4d4b0ee3_optionalFile;
typedef struct _4d4b0ee3_optionalLine { _4d4b0ee3_optionalLine(int value): value(value) {}; int value; _4d4b0ee3_optionalLine(const _4d4b0ee3_optionalLine &) = delete; } _4d4b0ee3_optionalLine;
typedef struct _4d4b0ee3_optionalUserData { _4d4b0ee3_optionalUserData(void* value): value(value) {}; void* value; _4d4b0ee3_optionalUserData(const _4d4b0ee3_optionalUserData &) = delete; } _4d4b0ee3_optionalUserData;
void np_red2CreateProcedureParameters(_4d4b0ee3_context & context, _4d4b0ee3_gpu & gpu, _4d4b0ee3_handleName & handleName, _4d4b0ee3_procedureParametersDeclaration & procedureParametersDeclaration, _4d4b0ee3_outProcedureParameters & outProcedureParameters, _4d4b0ee3_outStatuses & outStatuses, _4d4b0ee3_optionalFile & optionalFile, _4d4b0ee3_optionalLine & optionalLine, _4d4b0ee3_optionalUserData & optionalUserData) {
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
typedef struct _5b6ebab2_context { _5b6ebab2_context(RedContext value): value(value) {}; RedContext value; _5b6ebab2_context(const _5b6ebab2_context &) = delete; } _5b6ebab2_context;
typedef struct _5b6ebab2_gpu { _5b6ebab2_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _5b6ebab2_gpu(const _5b6ebab2_gpu &) = delete; } _5b6ebab2_gpu;
typedef struct _5b6ebab2_handleName { _5b6ebab2_handleName(char* value): value(value) {}; char* value; _5b6ebab2_handleName(const _5b6ebab2_handleName &) = delete; } _5b6ebab2_handleName;
typedef struct _5b6ebab2_queueFamilyIndex { _5b6ebab2_queueFamilyIndex(unsigned value): value(value) {}; unsigned value; _5b6ebab2_queueFamilyIndex(const _5b6ebab2_queueFamilyIndex &) = delete; } _5b6ebab2_queueFamilyIndex;
typedef struct _5b6ebab2_outCalls { _5b6ebab2_outCalls(Red2HandleCalls* value): value(value) {}; Red2HandleCalls* value; _5b6ebab2_outCalls(const _5b6ebab2_outCalls &) = delete; } _5b6ebab2_outCalls;
typedef struct _5b6ebab2_outStatuses { _5b6ebab2_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _5b6ebab2_outStatuses(const _5b6ebab2_outStatuses &) = delete; } _5b6ebab2_outStatuses;
typedef struct _5b6ebab2_optionalFile { _5b6ebab2_optionalFile(char* value): value(value) {}; char* value; _5b6ebab2_optionalFile(const _5b6ebab2_optionalFile &) = delete; } _5b6ebab2_optionalFile;
typedef struct _5b6ebab2_optionalLine { _5b6ebab2_optionalLine(int value): value(value) {}; int value; _5b6ebab2_optionalLine(const _5b6ebab2_optionalLine &) = delete; } _5b6ebab2_optionalLine;
typedef struct _5b6ebab2_optionalUserData { _5b6ebab2_optionalUserData(void* value): value(value) {}; void* value; _5b6ebab2_optionalUserData(const _5b6ebab2_optionalUserData &) = delete; } _5b6ebab2_optionalUserData;
void np_red2CreateCalls(_5b6ebab2_context & context, _5b6ebab2_gpu & gpu, _5b6ebab2_handleName & handleName, _5b6ebab2_queueFamilyIndex & queueFamilyIndex, _5b6ebab2_outCalls & outCalls, _5b6ebab2_outStatuses & outStatuses, _5b6ebab2_optionalFile & optionalFile, _5b6ebab2_optionalLine & optionalLine, _5b6ebab2_optionalUserData & optionalUserData) {
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
typedef struct _e66e174d_context { _e66e174d_context(RedContext value): value(value) {}; RedContext value; _e66e174d_context(const _e66e174d_context &) = delete; } _e66e174d_context;
typedef struct _e66e174d_gpu { _e66e174d_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _e66e174d_gpu(const _e66e174d_gpu &) = delete; } _e66e174d_gpu;
typedef struct _e66e174d_handleName { _e66e174d_handleName(char* value): value(value) {}; char* value; _e66e174d_handleName(const _e66e174d_handleName &) = delete; } _e66e174d_handleName;
typedef struct _e66e174d_queueFamilyIndex { _e66e174d_queueFamilyIndex(unsigned value): value(value) {}; unsigned value; _e66e174d_queueFamilyIndex(const _e66e174d_queueFamilyIndex &) = delete; } _e66e174d_queueFamilyIndex;
typedef struct _e66e174d_outCalls { _e66e174d_outCalls(Red2HandleCalls* value): value(value) {}; Red2HandleCalls* value; _e66e174d_outCalls(const _e66e174d_outCalls &) = delete; } _e66e174d_outCalls;
typedef struct _e66e174d_outStatuses { _e66e174d_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _e66e174d_outStatuses(const _e66e174d_outStatuses &) = delete; } _e66e174d_outStatuses;
typedef struct _e66e174d_optionalFile { _e66e174d_optionalFile(char* value): value(value) {}; char* value; _e66e174d_optionalFile(const _e66e174d_optionalFile &) = delete; } _e66e174d_optionalFile;
typedef struct _e66e174d_optionalLine { _e66e174d_optionalLine(int value): value(value) {}; int value; _e66e174d_optionalLine(const _e66e174d_optionalLine &) = delete; } _e66e174d_optionalLine;
typedef struct _e66e174d_optionalUserData { _e66e174d_optionalUserData(void* value): value(value) {}; void* value; _e66e174d_optionalUserData(const _e66e174d_optionalUserData &) = delete; } _e66e174d_optionalUserData;
void np_red2CreateCallsReusable(_e66e174d_context & context, _e66e174d_gpu & gpu, _e66e174d_handleName & handleName, _e66e174d_queueFamilyIndex & queueFamilyIndex, _e66e174d_outCalls & outCalls, _e66e174d_outStatuses & outStatuses, _e66e174d_optionalFile & optionalFile, _e66e174d_optionalLine & optionalLine, _e66e174d_optionalUserData & optionalUserData) {
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
typedef struct _227c0da9_context { _227c0da9_context(RedContext value): value(value) {}; RedContext value; _227c0da9_context(const _227c0da9_context &) = delete; } _227c0da9_context;
typedef struct _227c0da9_gpu { _227c0da9_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _227c0da9_gpu(const _227c0da9_gpu &) = delete; } _227c0da9_gpu;
typedef struct _227c0da9_present { _227c0da9_present(RedHandlePresent value): value(value) {}; RedHandlePresent value; _227c0da9_present(const _227c0da9_present &) = delete; } _227c0da9_present;
typedef struct _227c0da9_presentImageIndex { _227c0da9_presentImageIndex(unsigned value): value(value) {}; unsigned value; _227c0da9_presentImageIndex(const _227c0da9_presentImageIndex &) = delete; } _227c0da9_presentImageIndex;
typedef struct _227c0da9_outGpuSignal { _227c0da9_outGpuSignal(RedHandleGpuSignal* value): value(value) {}; RedHandleGpuSignal* value; _227c0da9_outGpuSignal(const _227c0da9_outGpuSignal &) = delete; } _227c0da9_outGpuSignal;
typedef struct _227c0da9_outStatuses { _227c0da9_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _227c0da9_outStatuses(const _227c0da9_outStatuses &) = delete; } _227c0da9_outStatuses;
typedef struct _227c0da9_optionalFile { _227c0da9_optionalFile(char* value): value(value) {}; char* value; _227c0da9_optionalFile(const _227c0da9_optionalFile &) = delete; } _227c0da9_optionalFile;
typedef struct _227c0da9_optionalLine { _227c0da9_optionalLine(int value): value(value) {}; int value; _227c0da9_optionalLine(const _227c0da9_optionalLine &) = delete; } _227c0da9_optionalLine;
typedef struct _227c0da9_optionalUserData { _227c0da9_optionalUserData(void* value): value(value) {}; void* value; _227c0da9_optionalUserData(const _227c0da9_optionalUserData &) = delete; } _227c0da9_optionalUserData;
void np_red2CreateWsiTransientGpuSignal(_227c0da9_context & context, _227c0da9_gpu & gpu, _227c0da9_present & present, _227c0da9_presentImageIndex & presentImageIndex, _227c0da9_outGpuSignal & outGpuSignal, _227c0da9_outStatuses & outStatuses, _227c0da9_optionalFile & optionalFile, _227c0da9_optionalLine & optionalLine, _227c0da9_optionalUserData & optionalUserData) {
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
typedef struct _b64db4eb_context { _b64db4eb_context(RedContext value): value(value) {}; RedContext value; _b64db4eb_context(const _b64db4eb_context &) = delete; } _b64db4eb_context;
typedef struct _b64db4eb_optionalFile { _b64db4eb_optionalFile(char* value): value(value) {}; char* value; _b64db4eb_optionalFile(const _b64db4eb_optionalFile &) = delete; } _b64db4eb_optionalFile;
typedef struct _b64db4eb_optionalLine { _b64db4eb_optionalLine(int value): value(value) {}; int value; _b64db4eb_optionalLine(const _b64db4eb_optionalLine &) = delete; } _b64db4eb_optionalLine;
typedef struct _b64db4eb_optionalUserData { _b64db4eb_optionalUserData(void* value): value(value) {}; void* value; _b64db4eb_optionalUserData(const _b64db4eb_optionalUserData &) = delete; } _b64db4eb_optionalUserData;
void np_red2DestroyContext(_b64db4eb_context & context, _b64db4eb_optionalFile & optionalFile, _b64db4eb_optionalLine & optionalLine, _b64db4eb_optionalUserData & optionalUserData) {
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
typedef struct _3e897b9f_context { _3e897b9f_context(RedContext value): value(value) {}; RedContext value; _3e897b9f_context(const _3e897b9f_context &) = delete; } _3e897b9f_context;
typedef struct _3e897b9f_gpu { _3e897b9f_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _3e897b9f_gpu(const _3e897b9f_gpu &) = delete; } _3e897b9f_gpu;
typedef struct _3e897b9f_structDeclaration { _3e897b9f_structDeclaration(Red2HandleStructDeclaration value): value(value) {}; Red2HandleStructDeclaration value; _3e897b9f_structDeclaration(const _3e897b9f_structDeclaration &) = delete; } _3e897b9f_structDeclaration;
typedef struct _3e897b9f_optionalFile { _3e897b9f_optionalFile(char* value): value(value) {}; char* value; _3e897b9f_optionalFile(const _3e897b9f_optionalFile &) = delete; } _3e897b9f_optionalFile;
typedef struct _3e897b9f_optionalLine { _3e897b9f_optionalLine(int value): value(value) {}; int value; _3e897b9f_optionalLine(const _3e897b9f_optionalLine &) = delete; } _3e897b9f_optionalLine;
typedef struct _3e897b9f_optionalUserData { _3e897b9f_optionalUserData(void* value): value(value) {}; void* value; _3e897b9f_optionalUserData(const _3e897b9f_optionalUserData &) = delete; } _3e897b9f_optionalUserData;
void np_red2DestroyStructDeclaration(_3e897b9f_context & context, _3e897b9f_gpu & gpu, _3e897b9f_structDeclaration & structDeclaration, _3e897b9f_optionalFile & optionalFile, _3e897b9f_optionalLine & optionalLine, _3e897b9f_optionalUserData & optionalUserData) {
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
typedef struct _ca6ef253_context { _ca6ef253_context(RedContext value): value(value) {}; RedContext value; _ca6ef253_context(const _ca6ef253_context &) = delete; } _ca6ef253_context;
typedef struct _ca6ef253_gpu { _ca6ef253_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _ca6ef253_gpu(const _ca6ef253_gpu &) = delete; } _ca6ef253_gpu;
typedef struct _ca6ef253_procedureParameters { _ca6ef253_procedureParameters(Red2HandleProcedureParameters value): value(value) {}; Red2HandleProcedureParameters value; _ca6ef253_procedureParameters(const _ca6ef253_procedureParameters &) = delete; } _ca6ef253_procedureParameters;
typedef struct _ca6ef253_optionalFile { _ca6ef253_optionalFile(char* value): value(value) {}; char* value; _ca6ef253_optionalFile(const _ca6ef253_optionalFile &) = delete; } _ca6ef253_optionalFile;
typedef struct _ca6ef253_optionalLine { _ca6ef253_optionalLine(int value): value(value) {}; int value; _ca6ef253_optionalLine(const _ca6ef253_optionalLine &) = delete; } _ca6ef253_optionalLine;
typedef struct _ca6ef253_optionalUserData { _ca6ef253_optionalUserData(void* value): value(value) {}; void* value; _ca6ef253_optionalUserData(const _ca6ef253_optionalUserData &) = delete; } _ca6ef253_optionalUserData;
void np_red2DestroyProcedureParameters(_ca6ef253_context & context, _ca6ef253_gpu & gpu, _ca6ef253_procedureParameters & procedureParameters, _ca6ef253_optionalFile & optionalFile, _ca6ef253_optionalLine & optionalLine, _ca6ef253_optionalUserData & optionalUserData) {
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
typedef struct _8c2b0029_context { _8c2b0029_context(RedContext value): value(value) {}; RedContext value; _8c2b0029_context(const _8c2b0029_context &) = delete; } _8c2b0029_context;
typedef struct _8c2b0029_gpu { _8c2b0029_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _8c2b0029_gpu(const _8c2b0029_gpu &) = delete; } _8c2b0029_gpu;
typedef struct _8c2b0029_calls { _8c2b0029_calls(Red2HandleCalls value): value(value) {}; Red2HandleCalls value; _8c2b0029_calls(const _8c2b0029_calls &) = delete; } _8c2b0029_calls;
typedef struct _8c2b0029_optionalFile { _8c2b0029_optionalFile(char* value): value(value) {}; char* value; _8c2b0029_optionalFile(const _8c2b0029_optionalFile &) = delete; } _8c2b0029_optionalFile;
typedef struct _8c2b0029_optionalLine { _8c2b0029_optionalLine(int value): value(value) {}; int value; _8c2b0029_optionalLine(const _8c2b0029_optionalLine &) = delete; } _8c2b0029_optionalLine;
typedef struct _8c2b0029_optionalUserData { _8c2b0029_optionalUserData(void* value): value(value) {}; void* value; _8c2b0029_optionalUserData(const _8c2b0029_optionalUserData &) = delete; } _8c2b0029_optionalUserData;
void np_red2DestroyCalls(_8c2b0029_context & context, _8c2b0029_gpu & gpu, _8c2b0029_calls & calls, _8c2b0029_optionalFile & optionalFile, _8c2b0029_optionalLine & optionalLine, _8c2b0029_optionalUserData & optionalUserData) {
  red2DestroyCalls(context.value, gpu.value, calls.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2StructDeclarationGetRedHandle red2StructDeclarationGetRedHandle
#define _2e66ef28_structDeclaration(value) value
#else
typedef struct _2e66ef28_structDeclaration { _2e66ef28_structDeclaration(Red2HandleStructDeclaration value): value(value) {}; Red2HandleStructDeclaration value; _2e66ef28_structDeclaration(const _2e66ef28_structDeclaration &) = delete; } _2e66ef28_structDeclaration;
RedHandleStructDeclaration np_red2StructDeclarationGetRedHandle(_2e66ef28_structDeclaration & structDeclaration) {
  return red2StructDeclarationGetRedHandle(structDeclaration.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2StructDeclarationGetMembersPointer red2StructDeclarationGetMembersPointer
#define _3af6eadb_structDeclaration(value) value
#else
typedef struct _3af6eadb_structDeclaration { _3af6eadb_structDeclaration(Red2HandleStructDeclaration value): value(value) {}; Red2HandleStructDeclaration value; _3af6eadb_structDeclaration(const _3af6eadb_structDeclaration &) = delete; } _3af6eadb_structDeclaration;
Red2StructDeclarationMember* np_red2StructDeclarationGetMembersPointer(_3af6eadb_structDeclaration & structDeclaration) {
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
typedef struct _e0daa6e1_structDeclaration { _e0daa6e1_structDeclaration(Red2HandleStructDeclaration value): value(value) {}; Red2HandleStructDeclaration value; _e0daa6e1_structDeclaration(const _e0daa6e1_structDeclaration &) = delete; } _e0daa6e1_structDeclaration;
typedef struct _e0daa6e1_outStructDeclarationMembersCount { _e0daa6e1_outStructDeclarationMembersCount(unsigned* value): value(value) {}; unsigned* value; _e0daa6e1_outStructDeclarationMembersCount(const _e0daa6e1_outStructDeclarationMembersCount &) = delete; } _e0daa6e1_outStructDeclarationMembersCount;
typedef struct _e0daa6e1_outMembersOfTypeArrayROConstantCount { _e0daa6e1_outMembersOfTypeArrayROConstantCount(unsigned* value): value(value) {}; unsigned* value; _e0daa6e1_outMembersOfTypeArrayROConstantCount(const _e0daa6e1_outMembersOfTypeArrayROConstantCount &) = delete; } _e0daa6e1_outMembersOfTypeArrayROConstantCount;
typedef struct _e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount { _e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount(unsigned* value): value(value) {}; unsigned* value; _e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount(const _e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount &) = delete; } _e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount;
typedef struct _e0daa6e1_outMembersOfTypeTextureROCount { _e0daa6e1_outMembersOfTypeTextureROCount(unsigned* value): value(value) {}; unsigned* value; _e0daa6e1_outMembersOfTypeTextureROCount(const _e0daa6e1_outMembersOfTypeTextureROCount &) = delete; } _e0daa6e1_outMembersOfTypeTextureROCount;
typedef struct _e0daa6e1_outMembersOfTypeTextureRWCount { _e0daa6e1_outMembersOfTypeTextureRWCount(unsigned* value): value(value) {}; unsigned* value; _e0daa6e1_outMembersOfTypeTextureRWCount(const _e0daa6e1_outMembersOfTypeTextureRWCount &) = delete; } _e0daa6e1_outMembersOfTypeTextureRWCount;
typedef struct _e0daa6e1_outMembersOfTypeInlineSamplerCount { _e0daa6e1_outMembersOfTypeInlineSamplerCount(unsigned* value): value(value) {}; unsigned* value; _e0daa6e1_outMembersOfTypeInlineSamplerCount(const _e0daa6e1_outMembersOfTypeInlineSamplerCount &) = delete; } _e0daa6e1_outMembersOfTypeInlineSamplerCount;
typedef struct _e0daa6e1_outMembersOfTypeSamplerCount { _e0daa6e1_outMembersOfTypeSamplerCount(unsigned* value): value(value) {}; unsigned* value; _e0daa6e1_outMembersOfTypeSamplerCount(const _e0daa6e1_outMembersOfTypeSamplerCount &) = delete; } _e0daa6e1_outMembersOfTypeSamplerCount;
void np_red2StructDeclarationGetMembersCounts(_e0daa6e1_structDeclaration & structDeclaration, _e0daa6e1_outStructDeclarationMembersCount & outStructDeclarationMembersCount, _e0daa6e1_outMembersOfTypeArrayROConstantCount & outMembersOfTypeArrayROConstantCount, _e0daa6e1_outMembersOfTypeArrayROOrArrayRWCount & outMembersOfTypeArrayROOrArrayRWCount, _e0daa6e1_outMembersOfTypeTextureROCount & outMembersOfTypeTextureROCount, _e0daa6e1_outMembersOfTypeTextureRWCount & outMembersOfTypeTextureRWCount, _e0daa6e1_outMembersOfTypeInlineSamplerCount & outMembersOfTypeInlineSamplerCount, _e0daa6e1_outMembersOfTypeSamplerCount & outMembersOfTypeSamplerCount) {
  red2StructDeclarationGetMembersCounts(structDeclaration.value, outStructDeclarationMembersCount.value, outMembersOfTypeArrayROConstantCount.value, outMembersOfTypeArrayROOrArrayRWCount.value, outMembersOfTypeTextureROCount.value, outMembersOfTypeTextureRWCount.value, outMembersOfTypeInlineSamplerCount.value, outMembersOfTypeSamplerCount.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2ProcedureParametersGetRedHandle red2ProcedureParametersGetRedHandle
#define _5460064b_procedureParameters(value) value
#else
typedef struct _5460064b_procedureParameters { _5460064b_procedureParameters(Red2HandleProcedureParameters value): value(value) {}; Red2HandleProcedureParameters value; _5460064b_procedureParameters(const _5460064b_procedureParameters &) = delete; } _5460064b_procedureParameters;
RedHandleProcedureParameters np_red2ProcedureParametersGetRedHandle(_5460064b_procedureParameters & procedureParameters) {
  return red2ProcedureParametersGetRedHandle(procedureParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_red2ProcedureParametersGetStructDeclaration red2ProcedureParametersGetStructDeclaration
#define _1d3e3522_procedureParameters(value) value
#define _1d3e3522_structIndex(value) value
#else
typedef struct _1d3e3522_procedureParameters { _1d3e3522_procedureParameters(Red2HandleProcedureParameters value): value(value) {}; Red2HandleProcedureParameters value; _1d3e3522_procedureParameters(const _1d3e3522_procedureParameters &) = delete; } _1d3e3522_procedureParameters;
typedef struct _1d3e3522_structIndex { _1d3e3522_structIndex(unsigned value): value(value) {}; unsigned value; _1d3e3522_structIndex(const _1d3e3522_structIndex &) = delete; } _1d3e3522_structIndex;
Red2HandleStructDeclaration np_red2ProcedureParametersGetStructDeclaration(_1d3e3522_procedureParameters & procedureParameters, _1d3e3522_structIndex & structIndex) {
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
typedef struct _e72d80fe_calls { _e72d80fe_calls(Red2HandleCalls value): value(value) {}; Red2HandleCalls value; _e72d80fe_calls(const _e72d80fe_calls &) = delete; } _e72d80fe_calls;
typedef struct _e72d80fe_outContext { _e72d80fe_outContext(RedContext* value): value(value) {}; RedContext* value; _e72d80fe_outContext(const _e72d80fe_outContext &) = delete; } _e72d80fe_outContext;
typedef struct _e72d80fe_outGpu { _e72d80fe_outGpu(RedHandleGpu* value): value(value) {}; RedHandleGpu* value; _e72d80fe_outGpu(const _e72d80fe_outGpu &) = delete; } _e72d80fe_outGpu;
typedef struct _e72d80fe_outCalls { _e72d80fe_outCalls(RedCalls* value): value(value) {}; RedCalls* value; _e72d80fe_outCalls(const _e72d80fe_outCalls &) = delete; } _e72d80fe_outCalls;
void np_red2CallsGetRedHandles(_e72d80fe_calls & calls, _e72d80fe_outContext & outContext, _e72d80fe_outGpu & outGpu, _e72d80fe_outCalls & outCalls) {
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
typedef struct _c239a97f_context { _c239a97f_context(RedContext value): value(value) {}; RedContext value; _c239a97f_context(const _c239a97f_context &) = delete; } _c239a97f_context;
typedef struct _c239a97f_gpu { _c239a97f_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _c239a97f_gpu(const _c239a97f_gpu &) = delete; } _c239a97f_gpu;
typedef struct _c239a97f_calls { _c239a97f_calls(Red2HandleCalls value): value(value) {}; Red2HandleCalls value; _c239a97f_calls(const _c239a97f_calls &) = delete; } _c239a97f_calls;
typedef struct _c239a97f_callsMemory { _c239a97f_callsMemory(RedHandleCallsMemory value): value(value) {}; RedHandleCallsMemory value; _c239a97f_callsMemory(const _c239a97f_callsMemory &) = delete; } _c239a97f_callsMemory;
typedef struct _c239a97f_callsReusable { _c239a97f_callsReusable(RedBool32 value): value(value) {}; RedBool32 value; _c239a97f_callsReusable(const _c239a97f_callsReusable &) = delete; } _c239a97f_callsReusable;
typedef struct _c239a97f_outStatuses { _c239a97f_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _c239a97f_outStatuses(const _c239a97f_outStatuses &) = delete; } _c239a97f_outStatuses;
typedef struct _c239a97f_optionalFile { _c239a97f_optionalFile(char* value): value(value) {}; char* value; _c239a97f_optionalFile(const _c239a97f_optionalFile &) = delete; } _c239a97f_optionalFile;
typedef struct _c239a97f_optionalLine { _c239a97f_optionalLine(int value): value(value) {}; int value; _c239a97f_optionalLine(const _c239a97f_optionalLine &) = delete; } _c239a97f_optionalLine;
typedef struct _c239a97f_optionalUserData { _c239a97f_optionalUserData(void* value): value(value) {}; void* value; _c239a97f_optionalUserData(const _c239a97f_optionalUserData &) = delete; } _c239a97f_optionalUserData;
void np_red2CallsSet(_c239a97f_context & context, _c239a97f_gpu & gpu, _c239a97f_calls & calls, _c239a97f_callsMemory & callsMemory, _c239a97f_callsReusable & callsReusable, _c239a97f_outStatuses & outStatuses, _c239a97f_optionalFile & optionalFile, _c239a97f_optionalLine & optionalLine, _c239a97f_optionalUserData & optionalUserData) {
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
typedef struct _f0b37588_context { _f0b37588_context(RedContext value): value(value) {}; RedContext value; _f0b37588_context(const _f0b37588_context &) = delete; } _f0b37588_context;
typedef struct _f0b37588_gpu { _f0b37588_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _f0b37588_gpu(const _f0b37588_gpu &) = delete; } _f0b37588_gpu;
typedef struct _f0b37588_calls { _f0b37588_calls(Red2HandleCalls value): value(value) {}; Red2HandleCalls value; _f0b37588_calls(const _f0b37588_calls &) = delete; } _f0b37588_calls;
typedef struct _f0b37588_callsMemory { _f0b37588_callsMemory(RedHandleCallsMemory value): value(value) {}; RedHandleCallsMemory value; _f0b37588_callsMemory(const _f0b37588_callsMemory &) = delete; } _f0b37588_callsMemory;
typedef struct _f0b37588_outStatuses { _f0b37588_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _f0b37588_outStatuses(const _f0b37588_outStatuses &) = delete; } _f0b37588_outStatuses;
typedef struct _f0b37588_optionalFile { _f0b37588_optionalFile(char* value): value(value) {}; char* value; _f0b37588_optionalFile(const _f0b37588_optionalFile &) = delete; } _f0b37588_optionalFile;
typedef struct _f0b37588_optionalLine { _f0b37588_optionalLine(int value): value(value) {}; int value; _f0b37588_optionalLine(const _f0b37588_optionalLine &) = delete; } _f0b37588_optionalLine;
typedef struct _f0b37588_optionalUserData { _f0b37588_optionalUserData(void* value): value(value) {}; void* value; _f0b37588_optionalUserData(const _f0b37588_optionalUserData &) = delete; } _f0b37588_optionalUserData;
void np_red2CallsEnd(_f0b37588_context & context, _f0b37588_gpu & gpu, _f0b37588_calls & calls, _f0b37588_callsMemory & callsMemory, _f0b37588_outStatuses & outStatuses, _f0b37588_optionalFile & optionalFile, _f0b37588_optionalLine & optionalLine, _f0b37588_optionalUserData & optionalUserData) {
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
typedef struct _0b3f1f5f_context { _0b3f1f5f_context(RedContext value): value(value) {}; RedContext value; _0b3f1f5f_context(const _0b3f1f5f_context &) = delete; } _0b3f1f5f_context;
typedef struct _0b3f1f5f_gpu { _0b3f1f5f_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _0b3f1f5f_gpu(const _0b3f1f5f_gpu &) = delete; } _0b3f1f5f_gpu;
typedef struct _0b3f1f5f_calls { _0b3f1f5f_calls(Red2HandleCalls value): value(value) {}; Red2HandleCalls value; _0b3f1f5f_calls(const _0b3f1f5f_calls &) = delete; } _0b3f1f5f_calls;
typedef struct _0b3f1f5f_optionalFile { _0b3f1f5f_optionalFile(char* value): value(value) {}; char* value; _0b3f1f5f_optionalFile(const _0b3f1f5f_optionalFile &) = delete; } _0b3f1f5f_optionalFile;
typedef struct _0b3f1f5f_optionalLine { _0b3f1f5f_optionalLine(int value): value(value) {}; int value; _0b3f1f5f_optionalLine(const _0b3f1f5f_optionalLine &) = delete; } _0b3f1f5f_optionalLine;
typedef struct _0b3f1f5f_optionalUserData { _0b3f1f5f_optionalUserData(void* value): value(value) {}; void* value; _0b3f1f5f_optionalUserData(const _0b3f1f5f_optionalUserData &) = delete; } _0b3f1f5f_optionalUserData;
void np_red2CallsFreeAllInlineStructsMemorys(_0b3f1f5f_context & context, _0b3f1f5f_gpu & gpu, _0b3f1f5f_calls & calls, _0b3f1f5f_optionalFile & optionalFile, _0b3f1f5f_optionalLine & optionalLine, _0b3f1f5f_optionalUserData & optionalUserData) {
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
typedef struct _ada5e37f_calls { _ada5e37f_calls(Red2HandleCalls value): value(value) {}; Red2HandleCalls value; _ada5e37f_calls(const _ada5e37f_calls &) = delete; } _ada5e37f_calls;
typedef struct _ada5e37f_structsMemoryHandleName { _ada5e37f_structsMemoryHandleName(char* value): value(value) {}; char* value; _ada5e37f_structsMemoryHandleName(const _ada5e37f_structsMemoryHandleName &) = delete; } _ada5e37f_structsMemoryHandleName;
typedef struct _ada5e37f_maxStructsCount { _ada5e37f_maxStructsCount(unsigned value): value(value) {}; unsigned value; _ada5e37f_maxStructsCount(const _ada5e37f_maxStructsCount &) = delete; } _ada5e37f_maxStructsCount;
typedef struct _ada5e37f_maxStructsOfTypeSamplerCount { _ada5e37f_maxStructsOfTypeSamplerCount(unsigned value): value(value) {}; unsigned value; _ada5e37f_maxStructsOfTypeSamplerCount(const _ada5e37f_maxStructsOfTypeSamplerCount &) = delete; } _ada5e37f_maxStructsOfTypeSamplerCount;
typedef struct _ada5e37f_maxStructsMembersOfTypeArrayROConstantCount { _ada5e37f_maxStructsMembersOfTypeArrayROConstantCount(unsigned value): value(value) {}; unsigned value; _ada5e37f_maxStructsMembersOfTypeArrayROConstantCount(const _ada5e37f_maxStructsMembersOfTypeArrayROConstantCount &) = delete; } _ada5e37f_maxStructsMembersOfTypeArrayROConstantCount;
typedef struct _ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount { _ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount(unsigned value): value(value) {}; unsigned value; _ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount(const _ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount &) = delete; } _ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount;
typedef struct _ada5e37f_maxStructsMembersOfTypeTextureROCount { _ada5e37f_maxStructsMembersOfTypeTextureROCount(unsigned value): value(value) {}; unsigned value; _ada5e37f_maxStructsMembersOfTypeTextureROCount(const _ada5e37f_maxStructsMembersOfTypeTextureROCount &) = delete; } _ada5e37f_maxStructsMembersOfTypeTextureROCount;
typedef struct _ada5e37f_maxStructsMembersOfTypeTextureRWCount { _ada5e37f_maxStructsMembersOfTypeTextureRWCount(unsigned value): value(value) {}; unsigned value; _ada5e37f_maxStructsMembersOfTypeTextureRWCount(const _ada5e37f_maxStructsMembersOfTypeTextureRWCount &) = delete; } _ada5e37f_maxStructsMembersOfTypeTextureRWCount;
typedef struct _ada5e37f_maxStructsMembersOfTypeInlineSamplerCount { _ada5e37f_maxStructsMembersOfTypeInlineSamplerCount(unsigned value): value(value) {}; unsigned value; _ada5e37f_maxStructsMembersOfTypeInlineSamplerCount(const _ada5e37f_maxStructsMembersOfTypeInlineSamplerCount &) = delete; } _ada5e37f_maxStructsMembersOfTypeInlineSamplerCount;
typedef struct _ada5e37f_maxStructsMembersOfTypeSamplerCount { _ada5e37f_maxStructsMembersOfTypeSamplerCount(unsigned value): value(value) {}; unsigned value; _ada5e37f_maxStructsMembersOfTypeSamplerCount(const _ada5e37f_maxStructsMembersOfTypeSamplerCount &) = delete; } _ada5e37f_maxStructsMembersOfTypeSamplerCount;
typedef struct _ada5e37f_outStatuses { _ada5e37f_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _ada5e37f_outStatuses(const _ada5e37f_outStatuses &) = delete; } _ada5e37f_outStatuses;
typedef struct _ada5e37f_optionalFile { _ada5e37f_optionalFile(char* value): value(value) {}; char* value; _ada5e37f_optionalFile(const _ada5e37f_optionalFile &) = delete; } _ada5e37f_optionalFile;
typedef struct _ada5e37f_optionalLine { _ada5e37f_optionalLine(int value): value(value) {}; int value; _ada5e37f_optionalLine(const _ada5e37f_optionalLine &) = delete; } _ada5e37f_optionalLine;
typedef struct _ada5e37f_optionalUserData { _ada5e37f_optionalUserData(void* value): value(value) {}; void* value; _ada5e37f_optionalUserData(const _ada5e37f_optionalUserData &) = delete; } _ada5e37f_optionalUserData;
void np_red2CallAllocateAndSetInlineStructsMemory(_ada5e37f_calls & calls, _ada5e37f_structsMemoryHandleName & structsMemoryHandleName, _ada5e37f_maxStructsCount & maxStructsCount, _ada5e37f_maxStructsOfTypeSamplerCount & maxStructsOfTypeSamplerCount, _ada5e37f_maxStructsMembersOfTypeArrayROConstantCount & maxStructsMembersOfTypeArrayROConstantCount, _ada5e37f_maxStructsMembersOfTypeArrayROOrArrayRWCount & maxStructsMembersOfTypeArrayROOrArrayRWCount, _ada5e37f_maxStructsMembersOfTypeTextureROCount & maxStructsMembersOfTypeTextureROCount, _ada5e37f_maxStructsMembersOfTypeTextureRWCount & maxStructsMembersOfTypeTextureRWCount, _ada5e37f_maxStructsMembersOfTypeInlineSamplerCount & maxStructsMembersOfTypeInlineSamplerCount, _ada5e37f_maxStructsMembersOfTypeSamplerCount & maxStructsMembersOfTypeSamplerCount, _ada5e37f_outStatuses & outStatuses, _ada5e37f_optionalFile & optionalFile, _ada5e37f_optionalLine & optionalLine, _ada5e37f_optionalUserData & optionalUserData) {
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
typedef struct _e6f48477_calls { _e6f48477_calls(Red2HandleCalls value): value(value) {}; Red2HandleCalls value; _e6f48477_calls(const _e6f48477_calls &) = delete; } _e6f48477_calls;
typedef struct _e6f48477_structsMemoryHandleName { _e6f48477_structsMemoryHandleName(char* value): value(value) {}; char* value; _e6f48477_structsMemoryHandleName(const _e6f48477_structsMemoryHandleName &) = delete; } _e6f48477_structsMemoryHandleName;
typedef struct _e6f48477_procedureParametersCount { _e6f48477_procedureParametersCount(unsigned value): value(value) {}; unsigned value; _e6f48477_procedureParametersCount(const _e6f48477_procedureParametersCount &) = delete; } _e6f48477_procedureParametersCount;
typedef struct _e6f48477_procedureParameters { _e6f48477_procedureParameters(Red2InlineStructsMemoryFromProcedureParameters* value): value(value) {}; Red2InlineStructsMemoryFromProcedureParameters* value; _e6f48477_procedureParameters(const _e6f48477_procedureParameters &) = delete; } _e6f48477_procedureParameters;
typedef struct _e6f48477_outStatuses { _e6f48477_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _e6f48477_outStatuses(const _e6f48477_outStatuses &) = delete; } _e6f48477_outStatuses;
typedef struct _e6f48477_optionalFile { _e6f48477_optionalFile(char* value): value(value) {}; char* value; _e6f48477_optionalFile(const _e6f48477_optionalFile &) = delete; } _e6f48477_optionalFile;
typedef struct _e6f48477_optionalLine { _e6f48477_optionalLine(int value): value(value) {}; int value; _e6f48477_optionalLine(const _e6f48477_optionalLine &) = delete; } _e6f48477_optionalLine;
typedef struct _e6f48477_optionalUserData { _e6f48477_optionalUserData(void* value): value(value) {}; void* value; _e6f48477_optionalUserData(const _e6f48477_optionalUserData &) = delete; } _e6f48477_optionalUserData;
void np_red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters(_e6f48477_calls & calls, _e6f48477_structsMemoryHandleName & structsMemoryHandleName, _e6f48477_procedureParametersCount & procedureParametersCount, _e6f48477_procedureParameters & procedureParameters, _e6f48477_outStatuses & outStatuses, _e6f48477_optionalFile & optionalFile, _e6f48477_optionalLine & optionalLine, _e6f48477_optionalUserData & optionalUserData) {
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
typedef struct _0a8bd758_calls { _0a8bd758_calls(Red2HandleCalls value): value(value) {}; Red2HandleCalls value; _0a8bd758_calls(const _0a8bd758_calls &) = delete; } _0a8bd758_calls;
typedef struct _0a8bd758_procedureType { _0a8bd758_procedureType(RedProcedureType value): value(value) {}; RedProcedureType value; _0a8bd758_procedureType(const _0a8bd758_procedureType &) = delete; } _0a8bd758_procedureType;
typedef struct _0a8bd758_procedureParameters { _0a8bd758_procedureParameters(Red2HandleProcedureParameters value): value(value) {}; Red2HandleProcedureParameters value; _0a8bd758_procedureParameters(const _0a8bd758_procedureParameters &) = delete; } _0a8bd758_procedureParameters;
typedef struct _0a8bd758_structIndex { _0a8bd758_structIndex(unsigned value): value(value) {}; unsigned value; _0a8bd758_structIndex(const _0a8bd758_structIndex &) = delete; } _0a8bd758_structIndex;
typedef struct _0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers { _0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers(void** value): value(value) {}; void** value; _0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers(const _0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers &) = delete; } _0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers;
typedef struct _0a8bd758_outStatuses { _0a8bd758_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _0a8bd758_outStatuses(const _0a8bd758_outStatuses &) = delete; } _0a8bd758_outStatuses;
typedef struct _0a8bd758_optionalFile { _0a8bd758_optionalFile(char* value): value(value) {}; char* value; _0a8bd758_optionalFile(const _0a8bd758_optionalFile &) = delete; } _0a8bd758_optionalFile;
typedef struct _0a8bd758_optionalLine { _0a8bd758_optionalLine(int value): value(value) {}; int value; _0a8bd758_optionalLine(const _0a8bd758_optionalLine &) = delete; } _0a8bd758_optionalLine;
typedef struct _0a8bd758_optionalUserData { _0a8bd758_optionalUserData(void* value): value(value) {}; void* value; _0a8bd758_optionalUserData(const _0a8bd758_optionalUserData &) = delete; } _0a8bd758_optionalUserData;
RedStatus np_red2CallSuballocateAndSetProcedureParametersInlineStruct(_0a8bd758_calls & calls, _0a8bd758_procedureType & procedureType, _0a8bd758_procedureParameters & procedureParameters, _0a8bd758_structIndex & structIndex, _0a8bd758_structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers & structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers, _0a8bd758_outStatuses & outStatuses, _0a8bd758_optionalFile & optionalFile, _0a8bd758_optionalLine & optionalLine, _0a8bd758_optionalUserData & optionalUserData) {
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
typedef struct _80ee055a_context { _80ee055a_context(RedContext value): value(value) {}; RedContext value; _80ee055a_context(const _80ee055a_context &) = delete; } _80ee055a_context;
typedef struct _80ee055a_gpu { _80ee055a_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _80ee055a_gpu(const _80ee055a_gpu &) = delete; } _80ee055a_gpu;
typedef struct _80ee055a_present { _80ee055a_present(RedHandlePresent value): value(value) {}; RedHandlePresent value; _80ee055a_present(const _80ee055a_present &) = delete; } _80ee055a_present;
typedef struct _80ee055a_signalCpuSignal { _80ee055a_signalCpuSignal(RedHandleCpuSignal value): value(value) {}; RedHandleCpuSignal value; _80ee055a_signalCpuSignal(const _80ee055a_signalCpuSignal &) = delete; } _80ee055a_signalCpuSignal;
typedef struct _80ee055a_signalGpuSignal { _80ee055a_signalGpuSignal(RedHandleGpuSignal value): value(value) {}; RedHandleGpuSignal value; _80ee055a_signalGpuSignal(const _80ee055a_signalGpuSignal &) = delete; } _80ee055a_signalGpuSignal;
typedef struct _80ee055a_outImageIndex { _80ee055a_outImageIndex(unsigned* value): value(value) {}; unsigned* value; _80ee055a_outImageIndex(const _80ee055a_outImageIndex &) = delete; } _80ee055a_outImageIndex;
typedef struct _80ee055a_outStatuses { _80ee055a_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _80ee055a_outStatuses(const _80ee055a_outStatuses &) = delete; } _80ee055a_outStatuses;
typedef struct _80ee055a_optionalFile { _80ee055a_optionalFile(char* value): value(value) {}; char* value; _80ee055a_optionalFile(const _80ee055a_optionalFile &) = delete; } _80ee055a_optionalFile;
typedef struct _80ee055a_optionalLine { _80ee055a_optionalLine(int value): value(value) {}; int value; _80ee055a_optionalLine(const _80ee055a_optionalLine &) = delete; } _80ee055a_optionalLine;
typedef struct _80ee055a_optionalUserData { _80ee055a_optionalUserData(void* value): value(value) {}; void* value; _80ee055a_optionalUserData(const _80ee055a_optionalUserData &) = delete; } _80ee055a_optionalUserData;
void np_red2PresentGetImageIndex(_80ee055a_context & context, _80ee055a_gpu & gpu, _80ee055a_present & present, _80ee055a_signalCpuSignal & signalCpuSignal, _80ee055a_signalGpuSignal & signalGpuSignal, _80ee055a_outImageIndex & outImageIndex, _80ee055a_outStatuses & outStatuses, _80ee055a_optionalFile & optionalFile, _80ee055a_optionalLine & optionalLine, _80ee055a_optionalUserData & optionalUserData) {
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
#define _24f77dc7_outStatuses(value) value
#define _24f77dc7_optionalFile(value) value
#define _24f77dc7_optionalLine(value) value
#define _24f77dc7_optionalUserData(value) value
#else
typedef struct _24f77dc7_context { _24f77dc7_context(RedContext value): value(value) {}; RedContext value; _24f77dc7_context(const _24f77dc7_context &) = delete; } _24f77dc7_context;
typedef struct _24f77dc7_gpu { _24f77dc7_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _24f77dc7_gpu(const _24f77dc7_gpu &) = delete; } _24f77dc7_gpu;
typedef struct _24f77dc7_queue { _24f77dc7_queue(RedHandleQueue value): value(value) {}; RedHandleQueue value; _24f77dc7_queue(const _24f77dc7_queue &) = delete; } _24f77dc7_queue;
typedef struct _24f77dc7_timelinesCount { _24f77dc7_timelinesCount(unsigned value): value(value) {}; unsigned value; _24f77dc7_timelinesCount(const _24f77dc7_timelinesCount &) = delete; } _24f77dc7_timelinesCount;
typedef struct _24f77dc7_timelines { _24f77dc7_timelines(RedGpuTimeline* value): value(value) {}; RedGpuTimeline* value; _24f77dc7_timelines(const _24f77dc7_timelines &) = delete; } _24f77dc7_timelines;
typedef struct _24f77dc7_outQueueSubmissionTicketArrayIndex { _24f77dc7_outQueueSubmissionTicketArrayIndex(uint64_t* value): value(value) {}; uint64_t* value; _24f77dc7_outQueueSubmissionTicketArrayIndex(const _24f77dc7_outQueueSubmissionTicketArrayIndex &) = delete; } _24f77dc7_outQueueSubmissionTicketArrayIndex;
typedef struct _24f77dc7_outQueueSubmissionTicket { _24f77dc7_outQueueSubmissionTicket(uint64_t* value): value(value) {}; uint64_t* value; _24f77dc7_outQueueSubmissionTicket(const _24f77dc7_outQueueSubmissionTicket &) = delete; } _24f77dc7_outQueueSubmissionTicket;
typedef struct _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount { _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount(uint64_t value): value(value) {}; uint64_t value; _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount(const _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount &) = delete; } _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount;
typedef struct _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles { _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles(void** value): value(value) {}; void** value; _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles(const _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles &) = delete; } _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles;
typedef struct _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType { _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType(unsigned* value): value(value) {}; unsigned* value; _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType(const _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType &) = delete; } _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType;
typedef struct _24f77dc7_outStatuses { _24f77dc7_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _24f77dc7_outStatuses(const _24f77dc7_outStatuses &) = delete; } _24f77dc7_outStatuses;
typedef struct _24f77dc7_optionalFile { _24f77dc7_optionalFile(char* value): value(value) {}; char* value; _24f77dc7_optionalFile(const _24f77dc7_optionalFile &) = delete; } _24f77dc7_optionalFile;
typedef struct _24f77dc7_optionalLine { _24f77dc7_optionalLine(int value): value(value) {}; int value; _24f77dc7_optionalLine(const _24f77dc7_optionalLine &) = delete; } _24f77dc7_optionalLine;
typedef struct _24f77dc7_optionalUserData { _24f77dc7_optionalUserData(void* value): value(value) {}; void* value; _24f77dc7_optionalUserData(const _24f77dc7_optionalUserData &) = delete; } _24f77dc7_optionalUserData;
void np_red2QueueSubmit(_24f77dc7_context & context, _24f77dc7_gpu & gpu, _24f77dc7_queue & queue, _24f77dc7_timelinesCount & timelinesCount, _24f77dc7_timelines & timelines, _24f77dc7_outQueueSubmissionTicketArrayIndex & outQueueSubmissionTicketArrayIndex, _24f77dc7_outQueueSubmissionTicket & outQueueSubmissionTicket, _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesCount & whenQueueSubmissionIsFinishedDestroyHandlesCount, _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandles & whenQueueSubmissionIsFinishedDestroyHandles, _24f77dc7_whenQueueSubmissionIsFinishedDestroyHandlesHandleType & whenQueueSubmissionIsFinishedDestroyHandlesHandleType, _24f77dc7_outStatuses & outStatuses, _24f77dc7_optionalFile & optionalFile, _24f77dc7_optionalLine & optionalLine, _24f77dc7_optionalUserData & optionalUserData) {
  red2QueueSubmit(context.value, gpu.value, queue.value, timelinesCount.value, timelines.value, outQueueSubmissionTicketArrayIndex.value, outQueueSubmissionTicket.value, whenQueueSubmissionIsFinishedDestroyHandlesCount.value, whenQueueSubmissionIsFinishedDestroyHandles.value, whenQueueSubmissionIsFinishedDestroyHandlesHandleType.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
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
typedef struct _d6a2b07e_queueSubmissionTicketArrayIndex { _d6a2b07e_queueSubmissionTicketArrayIndex(uint64_t value): value(value) {}; uint64_t value; _d6a2b07e_queueSubmissionTicketArrayIndex(const _d6a2b07e_queueSubmissionTicketArrayIndex &) = delete; } _d6a2b07e_queueSubmissionTicketArrayIndex;
typedef struct _d6a2b07e_queueSubmissionTicket { _d6a2b07e_queueSubmissionTicket(uint64_t value): value(value) {}; uint64_t value; _d6a2b07e_queueSubmissionTicket(const _d6a2b07e_queueSubmissionTicket &) = delete; } _d6a2b07e_queueSubmissionTicket;
typedef struct _d6a2b07e_optionalFile { _d6a2b07e_optionalFile(char* value): value(value) {}; char* value; _d6a2b07e_optionalFile(const _d6a2b07e_optionalFile &) = delete; } _d6a2b07e_optionalFile;
typedef struct _d6a2b07e_optionalLine { _d6a2b07e_optionalLine(int value): value(value) {}; int value; _d6a2b07e_optionalLine(const _d6a2b07e_optionalLine &) = delete; } _d6a2b07e_optionalLine;
typedef struct _d6a2b07e_optionalUserData { _d6a2b07e_optionalUserData(void* value): value(value) {}; void* value; _d6a2b07e_optionalUserData(const _d6a2b07e_optionalUserData &) = delete; } _d6a2b07e_optionalUserData;
RedBool32 np_red2IsQueueSubmissionFinished(_d6a2b07e_queueSubmissionTicketArrayIndex & queueSubmissionTicketArrayIndex, _d6a2b07e_queueSubmissionTicket & queueSubmissionTicket, _d6a2b07e_optionalFile & optionalFile, _d6a2b07e_optionalLine & optionalLine, _d6a2b07e_optionalUserData & optionalUserData) {
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
typedef struct _f960b352_queueSubmissionTicket { _f960b352_queueSubmissionTicket(uint64_t value): value(value) {}; uint64_t value; _f960b352_queueSubmissionTicket(const _f960b352_queueSubmissionTicket &) = delete; } _f960b352_queueSubmissionTicket;
typedef struct _f960b352_optionalFile { _f960b352_optionalFile(char* value): value(value) {}; char* value; _f960b352_optionalFile(const _f960b352_optionalFile &) = delete; } _f960b352_optionalFile;
typedef struct _f960b352_optionalLine { _f960b352_optionalLine(int value): value(value) {}; int value; _f960b352_optionalLine(const _f960b352_optionalLine &) = delete; } _f960b352_optionalLine;
typedef struct _f960b352_optionalUserData { _f960b352_optionalUserData(void* value): value(value) {}; void* value; _f960b352_optionalUserData(const _f960b352_optionalUserData &) = delete; } _f960b352_optionalUserData;
RedBool32 np_red2IsQueueSubmissionFinishedByTicketAlone(_f960b352_queueSubmissionTicket & queueSubmissionTicket, _f960b352_optionalFile & optionalFile, _f960b352_optionalLine & optionalLine, _f960b352_optionalUserData & optionalUserData) {
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
typedef struct _05c69089_context { _05c69089_context(RedContext value): value(value) {}; RedContext value; _05c69089_context(const _05c69089_context &) = delete; } _05c69089_context;
typedef struct _05c69089_gpu { _05c69089_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _05c69089_gpu(const _05c69089_gpu &) = delete; } _05c69089_gpu;
typedef struct _05c69089_queueSubmissionTicket { _05c69089_queueSubmissionTicket(uint64_t value): value(value) {}; uint64_t value; _05c69089_queueSubmissionTicket(const _05c69089_queueSubmissionTicket &) = delete; } _05c69089_queueSubmissionTicket;
typedef struct _05c69089_outStatuses { _05c69089_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _05c69089_outStatuses(const _05c69089_outStatuses &) = delete; } _05c69089_outStatuses;
typedef struct _05c69089_optionalFile { _05c69089_optionalFile(char* value): value(value) {}; char* value; _05c69089_optionalFile(const _05c69089_optionalFile &) = delete; } _05c69089_optionalFile;
typedef struct _05c69089_optionalLine { _05c69089_optionalLine(int value): value(value) {}; int value; _05c69089_optionalLine(const _05c69089_optionalLine &) = delete; } _05c69089_optionalLine;
typedef struct _05c69089_optionalUserData { _05c69089_optionalUserData(void* value): value(value) {}; void* value; _05c69089_optionalUserData(const _05c69089_optionalUserData &) = delete; } _05c69089_optionalUserData;
RedBool32 np_red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket(_05c69089_context & context, _05c69089_gpu & gpu, _05c69089_queueSubmissionTicket & queueSubmissionTicket, _05c69089_outStatuses & outStatuses, _05c69089_optionalFile & optionalFile, _05c69089_optionalLine & optionalLine, _05c69089_optionalUserData & optionalUserData) {
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
typedef struct _b58bb58e_queueSubmissionTicketArrayIndex { _b58bb58e_queueSubmissionTicketArrayIndex(uint64_t value): value(value) {}; uint64_t value; _b58bb58e_queueSubmissionTicketArrayIndex(const _b58bb58e_queueSubmissionTicketArrayIndex &) = delete; } _b58bb58e_queueSubmissionTicketArrayIndex;
typedef struct _b58bb58e_queueSubmissionTicket { _b58bb58e_queueSubmissionTicket(uint64_t value): value(value) {}; uint64_t value; _b58bb58e_queueSubmissionTicket(const _b58bb58e_queueSubmissionTicket &) = delete; } _b58bb58e_queueSubmissionTicket;
typedef struct _b58bb58e_outStatuses { _b58bb58e_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _b58bb58e_outStatuses(const _b58bb58e_outStatuses &) = delete; } _b58bb58e_outStatuses;
typedef struct _b58bb58e_optionalFile { _b58bb58e_optionalFile(char* value): value(value) {}; char* value; _b58bb58e_optionalFile(const _b58bb58e_optionalFile &) = delete; } _b58bb58e_optionalFile;
typedef struct _b58bb58e_optionalLine { _b58bb58e_optionalLine(int value): value(value) {}; int value; _b58bb58e_optionalLine(const _b58bb58e_optionalLine &) = delete; } _b58bb58e_optionalLine;
typedef struct _b58bb58e_optionalUserData { _b58bb58e_optionalUserData(void* value): value(value) {}; void* value; _b58bb58e_optionalUserData(const _b58bb58e_optionalUserData &) = delete; } _b58bb58e_optionalUserData;
void np_red2WaitForQueueSubmissionToFinish(_b58bb58e_queueSubmissionTicketArrayIndex & queueSubmissionTicketArrayIndex, _b58bb58e_queueSubmissionTicket & queueSubmissionTicket, _b58bb58e_outStatuses & outStatuses, _b58bb58e_optionalFile & optionalFile, _b58bb58e_optionalLine & optionalLine, _b58bb58e_optionalUserData & optionalUserData) {
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
typedef struct _19ddb3ff_queueSubmissionTicket { _19ddb3ff_queueSubmissionTicket(uint64_t value): value(value) {}; uint64_t value; _19ddb3ff_queueSubmissionTicket(const _19ddb3ff_queueSubmissionTicket &) = delete; } _19ddb3ff_queueSubmissionTicket;
typedef struct _19ddb3ff_outStatuses { _19ddb3ff_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _19ddb3ff_outStatuses(const _19ddb3ff_outStatuses &) = delete; } _19ddb3ff_outStatuses;
typedef struct _19ddb3ff_optionalFile { _19ddb3ff_optionalFile(char* value): value(value) {}; char* value; _19ddb3ff_optionalFile(const _19ddb3ff_optionalFile &) = delete; } _19ddb3ff_optionalFile;
typedef struct _19ddb3ff_optionalLine { _19ddb3ff_optionalLine(int value): value(value) {}; int value; _19ddb3ff_optionalLine(const _19ddb3ff_optionalLine &) = delete; } _19ddb3ff_optionalLine;
typedef struct _19ddb3ff_optionalUserData { _19ddb3ff_optionalUserData(void* value): value(value) {}; void* value; _19ddb3ff_optionalUserData(const _19ddb3ff_optionalUserData &) = delete; } _19ddb3ff_optionalUserData;
void np_red2WaitForQueueSubmissionToFinishByTicketAlone(_19ddb3ff_queueSubmissionTicket & queueSubmissionTicket, _19ddb3ff_outStatuses & outStatuses, _19ddb3ff_optionalFile & optionalFile, _19ddb3ff_optionalLine & optionalLine, _19ddb3ff_optionalUserData & optionalUserData) {
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
typedef struct _55ec80ef_context { _55ec80ef_context(RedContext value): value(value) {}; RedContext value; _55ec80ef_context(const _55ec80ef_context &) = delete; } _55ec80ef_context;
typedef struct _55ec80ef_gpu { _55ec80ef_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _55ec80ef_gpu(const _55ec80ef_gpu &) = delete; } _55ec80ef_gpu;
typedef struct _55ec80ef_queueSubmissionTicket { _55ec80ef_queueSubmissionTicket(uint64_t value): value(value) {}; uint64_t value; _55ec80ef_queueSubmissionTicket(const _55ec80ef_queueSubmissionTicket &) = delete; } _55ec80ef_queueSubmissionTicket;
typedef struct _55ec80ef_outStatuses { _55ec80ef_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _55ec80ef_outStatuses(const _55ec80ef_outStatuses &) = delete; } _55ec80ef_outStatuses;
typedef struct _55ec80ef_optionalFile { _55ec80ef_optionalFile(char* value): value(value) {}; char* value; _55ec80ef_optionalFile(const _55ec80ef_optionalFile &) = delete; } _55ec80ef_optionalFile;
typedef struct _55ec80ef_optionalLine { _55ec80ef_optionalLine(int value): value(value) {}; int value; _55ec80ef_optionalLine(const _55ec80ef_optionalLine &) = delete; } _55ec80ef_optionalLine;
typedef struct _55ec80ef_optionalUserData { _55ec80ef_optionalUserData(void* value): value(value) {}; void* value; _55ec80ef_optionalUserData(const _55ec80ef_optionalUserData &) = delete; } _55ec80ef_optionalUserData;
void np_red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket(_55ec80ef_context & context, _55ec80ef_gpu & gpu, _55ec80ef_queueSubmissionTicket & queueSubmissionTicket, _55ec80ef_outStatuses & outStatuses, _55ec80ef_optionalFile & optionalFile, _55ec80ef_optionalLine & optionalLine, _55ec80ef_optionalUserData & optionalUserData) {
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
typedef struct _005c3675_context { _005c3675_context(RedContext value): value(value) {}; RedContext value; _005c3675_context(const _005c3675_context &) = delete; } _005c3675_context;
typedef struct _005c3675_gpu { _005c3675_gpu(RedHandleGpu value): value(value) {}; RedHandleGpu value; _005c3675_gpu(const _005c3675_gpu &) = delete; } _005c3675_gpu;
typedef struct _005c3675_outStatuses { _005c3675_outStatuses(RedStatuses* value): value(value) {}; RedStatuses* value; _005c3675_outStatuses(const _005c3675_outStatuses &) = delete; } _005c3675_outStatuses;
typedef struct _005c3675_optionalFile { _005c3675_optionalFile(char* value): value(value) {}; char* value; _005c3675_optionalFile(const _005c3675_optionalFile &) = delete; } _005c3675_optionalFile;
typedef struct _005c3675_optionalLine { _005c3675_optionalLine(int value): value(value) {}; int value; _005c3675_optionalLine(const _005c3675_optionalLine &) = delete; } _005c3675_optionalLine;
typedef struct _005c3675_optionalUserData { _005c3675_optionalUserData(void* value): value(value) {}; void* value; _005c3675_optionalUserData(const _005c3675_optionalUserData &) = delete; } _005c3675_optionalUserData;
void np_red2WaitForAllQueueSubmissionsToFinish(_005c3675_context & context, _005c3675_gpu & gpu, _005c3675_outStatuses & outStatuses, _005c3675_optionalFile & optionalFile, _005c3675_optionalLine & optionalLine, _005c3675_optionalUserData & optionalUserData) {
  red2WaitForAllQueueSubmissionsToFinish(context.value, gpu.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

