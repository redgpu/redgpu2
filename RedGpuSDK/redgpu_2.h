#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Red2TypeHandleStructDeclaration *   Red2HandleStructDeclaration;
typedef struct Red2TypeHandleProcedureParameters * Red2HandleProcedureParameters;
typedef struct Red2TypeHandleCalls *               Red2HandleCalls;

typedef struct Red2Calls {
  RedHandleCalls       handle;
  RedHandleCallsMemory memory;
  RedBool32            reusable;
  Red2HandleCalls      handle2;
} Red2Calls;

// red2CreateProcedureParameters

typedef struct Red2ProcedureParametersDeclaration {
  unsigned                    variablesSlot;
  RedVisibleToStageBitflags   variablesVisibleToStages;
  unsigned                    variablesBytesCount;
  unsigned                    structsDeclarationsCount; // Max: 7
  Red2HandleStructDeclaration structsDeclarations[7];
  RedHandleStructDeclaration  handlesDeclaration;
} Red2ProcedureParametersDeclaration;

// red2StructDeclarationGetMembersPointer

typedef struct Red2StructDeclarationMember {
  unsigned                  slot;
  RedStructMemberType       type;
  unsigned                  count;
  RedVisibleToStageBitflags visibleToStages;
  RedHandleSampler          inlineSampler;
} Red2StructDeclarationMember;

// red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters

typedef struct Red2InlineStructsMemoryFromProcedureParameters {
  Red2HandleProcedureParameters procedureParameters;
  unsigned                      procedureParametersAllocationsCount;
  unsigned                      procedureParametersStructsOptionalAllocationsCount[7];
} Red2InlineStructsMemoryFromProcedureParameters;

#ifndef REDGPU_2_DECLSPEC
#define REDGPU_2_DECLSPEC
#endif

#ifndef REDGPU_2_API
#define REDGPU_2_API
#endif

REDGPU_2_DECLSPEC void REDGPU_2_API red2CreateStructDeclaration    (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned structDeclarationMembersCount, const RedStructDeclarationMember * structDeclarationMembers, unsigned structDeclarationMembersArrayROCount, const RedStructDeclarationMemberArrayRO * structDeclarationMembersArrayRO, RedBool32 procedureParametersHandlesDeclaration, Red2HandleStructDeclaration * outStructDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2CreateProcedureParameters  (RedContext context, RedHandleGpu gpu, const char * handleName, const Red2ProcedureParametersDeclaration * procedureParametersDeclaration, Red2HandleProcedureParameters * outProcedureParameters, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2CreateCalls                (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, Red2Calls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2CreateCallsReusable        (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, Red2Calls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);

REDGPU_2_DECLSPEC void REDGPU_2_API red2DestroyContext             (RedContext context, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2DestroyStructDeclaration   (RedContext context, RedHandleGpu gpu, Red2HandleStructDeclaration structDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2DestroyProcedureParameters (RedContext context, RedHandleGpu gpu, Red2HandleProcedureParameters procedureParameters, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2DestroyCalls               (RedContext context, RedHandleGpu gpu, Red2HandleCalls calls, const char * optionalFile, int optionalLine, void * optionalUserData);

REDGPU_2_DECLSPEC RedHandleStructDeclaration    REDGPU_2_API red2StructDeclarationGetRedHandle      (Red2HandleStructDeclaration structDeclaration);
REDGPU_2_DECLSPEC Red2StructDeclarationMember * REDGPU_2_API red2StructDeclarationGetMembersPointer (Red2HandleStructDeclaration structDeclaration);
REDGPU_2_DECLSPEC void                          REDGPU_2_API red2StructDeclarationGetMembersCounts  (Red2HandleStructDeclaration structDeclaration, unsigned * outStructDeclarationMembersCount, unsigned * outMembersOfTypeArrayROConstantCount, unsigned * outMembersOfTypeArrayROOrArrayRWCount, unsigned * outMembersOfTypeTextureROCount, unsigned * outMembersOfTypeTextureRWCount, unsigned * outMembersOfTypeInlineSamplerCount, unsigned * outMembersOfTypeSamplerCount);

REDGPU_2_DECLSPEC RedHandleProcedureParameters  REDGPU_2_API red2ProcedureParametersGetRedHandle         (Red2HandleProcedureParameters procedureParameters);
REDGPU_2_DECLSPEC Red2HandleStructDeclaration   REDGPU_2_API red2ProcedureParametersGetStructDeclaration (Red2HandleProcedureParameters procedureParameters, unsigned structIndex);

REDGPU_2_DECLSPEC void REDGPU_2_API red2CallsSet(
  RedContext context,
  RedHandleGpu gpu,
  Red2HandleCalls calls,
  RedHandleCallsMemory callsMemory,
  RedBool32 callsReusable,
  RedStatuses * outStatuses,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
);

REDGPU_2_DECLSPEC void REDGPU_2_API red2CallsEnd(
  RedContext context,
  RedHandleGpu gpu,
  Red2HandleCalls calls,
  RedHandleCallsMemory callsMemory,
  RedStatuses * outStatuses,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
);

REDGPU_2_DECLSPEC void REDGPU_2_API red2CallsFreeAllInlineStructsMemorys(
  RedContext context,
  RedHandleGpu gpu,
  Red2HandleCalls calls,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
);

REDGPU_2_DECLSPEC void REDGPU_2_API red2CallAllocateAndSetInlineStructsMemory(
  Red2HandleCalls calls,
  const char * structsMemoryHandleName,
  unsigned maxStructsCount,
  unsigned maxStructsOfTypeSamplerCount,
  unsigned maxStructsMembersOfTypeArrayROConstantCount,
  unsigned maxStructsMembersOfTypeArrayROOrArrayRWCount,
  unsigned maxStructsMembersOfTypeTextureROCount,
  unsigned maxStructsMembersOfTypeTextureRWCount,
  unsigned maxStructsMembersOfTypeInlineSamplerCount,
  unsigned maxStructsMembersOfTypeSamplerCount,
  RedStatuses * outStatuses,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
);

REDGPU_2_DECLSPEC void REDGPU_2_API red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters(
  Red2HandleCalls calls,
  const char * structsMemoryHandleName,
  unsigned procedureParametersCount,
  const Red2InlineStructsMemoryFromProcedureParameters * procedureParameters,
  RedStatuses * outStatuses,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
);

REDGPU_2_DECLSPEC RedStatus REDGPU_2_API red2CallSuballocateAndSetProcedureParametersInlineStruct(
  Red2HandleCalls calls,
  RedProcedureType procedureType,
  Red2HandleProcedureParameters procedureParameters,
  unsigned structIndex,
  void ** structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers,
  RedStatuses * outStatuses,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
);

REDGPU_2_DECLSPEC void REDGPU_2_API red2QueueSubmit (RedContext context, RedHandleGpu gpu, RedHandleQueue queue, unsigned timelinesCount, const RedGpuTimeline * timelines, unsigned callsToDestroyWhenFinishedCount, RedCalls * callsToDestroyWhenFinished, unsigned calls2ToDestroyWhenFinishedCount, Red2HandleCalls * calls2ToDestroyWhenFinished, uint64_t * outQueueSubmissionTicketArrayIndex, uint64_t * outQueueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);

REDGPU_2_DECLSPEC RedBool32 REDGPU_2_API red2IsQueueSubmissionFinished                                (uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC RedBool32 REDGPU_2_API red2IsQueueSubmissionFinishedByTicketAlone                   (uint64_t queueSubmissionTicket, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2WaitForQueueSubmissionToFinish                           (uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2WaitForQueueSubmissionToFinishByTicketAlone              (uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket (RedContext context, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2WaitForAllQueueSubmissionsToFinish                       (RedContext context, RedHandleGpu gpu, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);

#ifdef __cplusplus
}
#endif
