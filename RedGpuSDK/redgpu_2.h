#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Red2TypeContext *                   Red2Context;
typedef struct Red2TypeHandleStructDeclaration *   Red2HandleStructDeclaration;
typedef struct Red2TypeHandleProcedureParameters * Red2HandleProcedureParameters;
typedef struct Red2TypeHandleCalls *               Red2HandleCalls;

typedef enum Red2HandleType {
  RED2_HANDLE_TYPE_STRUCT_DECLARATION   = 20020,
  RED2_HANDLE_TYPE_PROCEDURE_PARAMETERS = 20017,
  RED2_HANDLE_TYPE_CALLS                = 20006,
} Red2HandleType;

// red2CreateContext

typedef struct Red2TypeContext {
  RedContext context;
  void *     redgpu2InternalData;
} Red2TypeContext;

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

// REDGPU use-instead procedures

REDGPU_2_DECLSPEC void REDGPU_2_API red2CreateContext              (RedTypeProcedureMalloc malloc, RedTypeProcedureFree free, RedTypeProcedureMallocTagged optionalMallocTagged, RedTypeProcedureFreeTagged optionalFreeTagged, RedTypeProcedureDebugCallback debugCallback, RedSdkVersion sdkVersion, unsigned sdkExtensionsCount, const unsigned * sdkExtensions, const char * optionalProgramName, unsigned optionalProgramVersion, const char * optionalEngineName, unsigned optionalEngineVersion, const void * optionalSettings, Red2Context * outContext2, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2CreateStructDeclaration    (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned structDeclarationMembersCount, const RedStructDeclarationMember * structDeclarationMembers, unsigned structDeclarationMembersArrayROCount, const RedStructDeclarationMemberArrayRO * structDeclarationMembersArrayRO, RedBool32 procedureParametersHandlesDeclaration, Red2HandleStructDeclaration * outStructDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2CreateProcedureParameters  (RedContext context, RedHandleGpu gpu, const char * handleName, const Red2ProcedureParametersDeclaration * procedureParametersDeclaration, Red2HandleProcedureParameters * outProcedureParameters, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2CreateCalls                (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, Red2HandleCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2CreateCallsReusable        (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, Red2HandleCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);

REDGPU_2_DECLSPEC void REDGPU_2_API red2DestroyContext             (Red2Context context2, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2DestroyStructDeclaration   (RedContext context, RedHandleGpu gpu, Red2HandleStructDeclaration structDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2DestroyProcedureParameters (RedContext context, RedHandleGpu gpu, Red2HandleProcedureParameters procedureParameters, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2DestroyCalls               (RedContext context, RedHandleGpu gpu, Red2HandleCalls calls, const char * optionalFile, int optionalLine, void * optionalUserData);

REDGPU_2_DECLSPEC void REDGPU_2_API red2CallsSet                   (Red2HandleCalls calls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2CallsEnd                   (Red2HandleCalls calls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);

REDGPU_2_DECLSPEC void REDGPU_2_API red2CallsAppendHandleToDestroy       (Red2HandleCalls calls, uint64_t handleToDestroyWhenCallsAreReset, unsigned handleToDestroyWhenCallsAreResetType);
REDGPU_2_DECLSPEC void REDGPU_2_API red2CallsFreeAllInlineStructsMemorys (Red2HandleCalls calls, const char * optionalFile, int optionalLine, void * optionalUserData);

REDGPU_2_DECLSPEC void REDGPU_2_API red2PresentGetImageIndex       (Red2Context context2, RedHandleGpu gpu, RedHandlePresent present, RedHandleCpuSignal signalCpuSignal, RedHandleGpuSignal signalGpuSignal, unsigned * outImageIndex, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2GetWsiTransientGpuSignal   (Red2Context context2, RedHandleGpu gpu, RedHandlePresent present, unsigned presentImageIndex, RedHandleGpuSignal * outGpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2QueueSubmit                (Red2Context context2, RedHandleGpu gpu, RedHandleQueue queue, unsigned timelinesCount, const RedGpuTimeline * timelines, uint64_t * outQueueSubmissionTicketArrayIndex, uint64_t * outQueueSubmissionTicket, uint64_t handlesToDestroyWhenQueueSubmissionIsFinishedCount, const uint64_t * handlesToDestroyWhenQueueSubmissionIsFinished, const unsigned * handlesToDestroyWhenQueueSubmissionIsFinishedType, void * optionalCustomHandleAndHandleTypeDestroyCallback, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void REDGPU_2_API red2QueueSubmitTrackableSimple (Red2Context context2, RedHandleGpu gpu, RedHandleQueue queue, unsigned callsCount, Red2HandleCalls * calls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);

// REDGPU 2 queue submission state procedures

REDGPU_2_DECLSPEC void      REDGPU_2_API red2DestroyHandlesToDestroyIfTheirQueueSubmissionIsFinished  (Red2Context context2, RedHandleGpu gpu, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC RedBool32 REDGPU_2_API red2IsQueueSubmissionFinished                                (Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC RedBool32 REDGPU_2_API red2IsQueueSubmissionFinishedByTicketAlone                   (Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC RedBool32 REDGPU_2_API red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket     (Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2WaitForQueueSubmissionToFinish                           (Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2WaitForQueueSubmissionToFinishByTicketAlone              (Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket (Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2WaitForAllQueueSubmissionsToFinish                       (Red2Context context2, RedHandleGpu gpu, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);

// REDGPU 2 get and set handle data procedures

REDGPU_2_DECLSPEC RedHandleStructDeclaration    REDGPU_2_API red2StructDeclarationGetRedHandle           (Red2HandleStructDeclaration structDeclaration);
REDGPU_2_DECLSPEC Red2StructDeclarationMember * REDGPU_2_API red2StructDeclarationGetMembersPointer      (Red2HandleStructDeclaration structDeclaration);
REDGPU_2_DECLSPEC void                          REDGPU_2_API red2StructDeclarationGetMembersCounts       (Red2HandleStructDeclaration structDeclaration, unsigned * outStructDeclarationMembersCount, unsigned * outMembersOfTypeArrayROConstantCount, unsigned * outMembersOfTypeArrayROOrArrayRWCount, unsigned * outMembersOfTypeTextureROCount, unsigned * outMembersOfTypeTextureRWCount, unsigned * outMembersOfTypeInlineSamplerCount, unsigned * outMembersOfTypeSamplerCount);
REDGPU_2_DECLSPEC RedHandleProcedureParameters  REDGPU_2_API red2ProcedureParametersGetRedHandle         (Red2HandleProcedureParameters procedureParameters);
REDGPU_2_DECLSPEC Red2HandleStructDeclaration   REDGPU_2_API red2ProcedureParametersGetStructDeclaration (Red2HandleProcedureParameters procedureParameters, unsigned structIndex);
REDGPU_2_DECLSPEC void                          REDGPU_2_API red2CallsGetRedHandles                      (Red2HandleCalls calls, RedContext * outContext, RedHandleGpu * outGpu, RedCalls * outCalls);
REDGPU_2_DECLSPEC void                          REDGPU_2_API red2CallsSetHandlesToDestroyCustomCallback  (Red2HandleCalls calls, void * optionalCustomHandleAndHandleTypeDestroyWhenCallsAreResetCallback);
REDGPU_2_DECLSPEC uint64_t *                    REDGPU_2_API red2CallsGetHandlesToDestroy                (Red2HandleCalls calls, uint64_t * outHandlesToDestroyWhenCallsAreResetCount);
REDGPU_2_DECLSPEC unsigned *                    REDGPU_2_API red2CallsGetHandlesToDestroyType            (Red2HandleCalls calls, uint64_t * outHandlesToDestroyWhenCallsAreResetTypeCount);
REDGPU_2_DECLSPEC void                          REDGPU_2_API red2CallsGetQueueSubmitTrackableTicket      (Red2HandleCalls calls, uint64_t * outQueueSubmissionTicketArrayIndex, uint64_t * outQueueSubmissionTicket);

// REDGPU 2 calls recording

REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetRenderTargets                                         (Red2HandleCalls calls, RedTypeProcedureAddressCallSetProcedureOutput address, unsigned width, unsigned height, RedHandleTexture depthStencilTexture, RedFormat depthStencilTextureFormat, RedMultisampleCountBitflag depthStencilTextureMultisampleCount, unsigned colorTexturesCountMax8, const RedHandleTexture * colorTextures, const RedFormat * colorTexturesFormat, const RedMultisampleCountBitflag * colorTexturesMultisampleCount, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallEndRenderTargets                                         (Red2HandleCalls calls, RedTypeProcedureAddressCallEndProcedureOutput address);

REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallAllocateAndSetInlineStructsMemory                        (Red2HandleCalls calls, const char * structsMemoryHandleName, unsigned maxStructsCount, unsigned maxStructsOfTypeSamplerCount, unsigned maxStructsMembersOfTypeArrayROConstantCount, unsigned maxStructsMembersOfTypeArrayROOrArrayRWCount, unsigned maxStructsMembersOfTypeTextureROCount, unsigned maxStructsMembersOfTypeTextureRWCount, unsigned maxStructsMembersOfTypeInlineSamplerCount, unsigned maxStructsMembersOfTypeSamplerCount, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters (Red2HandleCalls calls, const char * structsMemoryHandleName, unsigned procedureParametersCount, const Red2InlineStructsMemoryFromProcedureParameters * procedureParameters, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC RedStatus REDGPU_2_API red2CallSuballocateAndSetProcedureParametersInlineStruct         (Red2HandleCalls calls, RedProcedureType procedureType, Red2HandleProcedureParameters procedureParameters, unsigned structIndex, void ** structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);

// REDGPU 2 backend-exclusive procedures

REDGPU_2_DECLSPEC unsigned  REDGPU_2_API red2RedXOnlyGetRedXAccessBitflagsFromRed (RedAccessBitflags access); // For red2RedXOnlyCallUsageAliasOrderBarrier
REDGPU_2_DECLSPEC unsigned  REDGPU_2_API red2RedXOnlyArrayGetMemoryTypeIndex      (RedHandleArray array);     // For red2RedXOnlyCallUsageAliasOrderBarrier
REDGPU_2_DECLSPEC unsigned  REDGPU_2_API red2RedXOnlyImageGetLevelsCount          (RedHandleImage image);     // For red2RedXOnlyCallUsageAliasOrderBarrier
REDGPU_2_DECLSPEC unsigned  REDGPU_2_API red2RedXOnlyImageGetLayersCount          (RedHandleImage image);     // For red2RedXOnlyCallUsageAliasOrderBarrier

REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedOnlyCallUsageAliasOrderBarrier    (RedTypeProcedureAddressCallUsageAliasOrderBarrier address, RedHandleCalls calls, RedContext context, unsigned arrayUsagesCount, const RedUsageArray * arrayUsages, unsigned imageUsagesCount, const RedUsageImage * imageUsages, RedBool32 dependencyByRegion);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedXOnlyCallUsageAliasOrderBarrier   (RedTypeProcedureAddressCallUsageAliasOrderBarrier address, RedHandleCalls calls, unsigned barriersCount, const void * barriers);
REDGPU_2_DECLSPEC RedStatus REDGPU_2_API red2RedOnlyCallBarrierFinishCpuUpload    (RedTypeProcedureAddressCallUsageAliasOrderBarrier address, RedHandleCalls calls, uint64_t arraysCount, const RedHandleArray * arrays);
REDGPU_2_DECLSPEC RedStatus REDGPU_2_API red2RedOnlyCallBarrierFinishCpuReadback  (RedTypeProcedureAddressCallUsageAliasOrderBarrier address, RedHandleCalls calls, uint64_t arraysCount, const RedHandleArray * arrays);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedOnlyCallGlobalMemoryBarrier       (RedTypeProcedureAddressCallUsageAliasOrderBarrier address, RedHandleCalls calls);
REDGPU_2_DECLSPEC RedStatus REDGPU_2_API red2RedOnlyCallSetImageStateUsable       (RedTypeProcedureAddressCallUsageAliasOrderBarrier address, RedHandleCalls calls, RedContext context, uint64_t imagesCount, const RedHandleImage * images, RedImagePartBitflags imagesAllParts);

REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedOnlyPresentQueueWaitIdle          (RedContext context, RedHandleGpu gpu, RedHandleQueue presentQueue, const char * optionalFile, int optionalLine, void * optionalUserData);

// REDGPU 2 changes from 28 Nov 2024:

#ifndef red2CallUsageAliasOrderBarrier
#define red2CallUsageAliasOrderBarrier REDGPU_2_COMPILE_TIME_ERROR_red2CallUsageAliasOrderBarrier_was_removed_on_28_Nov_2024_use_both_red2RedOnlyCallUsageAliasOrderBarrier_and_red2RedXOnlyCallUsageAliasOrderBarrier_instead
#endif

#ifdef __cplusplus
}
#endif
