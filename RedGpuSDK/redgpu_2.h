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

// red2CreateProcedure

typedef struct Red2ProcedureDependencyOnRenderTargets {
  unsigned                   colorsTextureFormat[8];              // RedFormat or RedXFormat
  unsigned                   depthStencilTextureFormat;           // RedFormat or RedXFormat
  RedMultisampleCountBitflag colorsTextureMultisampleCount[8];
  RedMultisampleCountBitflag depthStencilTextureMultisampleCount;
} Red2ProcedureDependencyOnRenderTargets;

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

// REDGPU 2 use-instead procedures

REDGPU_2_DECLSPEC void      REDGPU_2_API red2CreateContext                    (RedTypeProcedureMalloc malloc, RedTypeProcedureFree free, RedTypeProcedureMallocTagged optionalMallocTagged, RedTypeProcedureFreeTagged optionalFreeTagged, RedTypeProcedureDebugCallback debugCallback, RedSdkVersion sdkVersion, unsigned sdkExtensionsCount, const unsigned * sdkExtensions, const char * optionalProgramName, unsigned optionalProgramVersion, const char * optionalEngineName, unsigned optionalEngineVersion, const void * optionalSettings, Red2Context * outContext2, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CreateImage                      (RedContext context, RedHandleGpu gpu, const char * handleName, RedImageDimensions dimensions, RedFormat format, unsigned xformat, unsigned width, unsigned height, unsigned depth, unsigned levelsCount, unsigned layersCount, RedMultisampleCountBitflag multisampleCount, RedAccessBitflags restrictToAccess, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedImage * outImage, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CreateTexture                    (RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleImage image, RedImagePartBitflags parts, RedTextureDimensions dimensions, RedFormat format, unsigned xformat, unsigned levelsFirst, unsigned levelsCount, unsigned layersFirst, unsigned layersCount, RedAccessBitflags restrictToAccess, RedHandleTexture * outTexture, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CreateStructDeclaration          (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned structDeclarationMembersCount, const RedStructDeclarationMember * structDeclarationMembers, unsigned structDeclarationMembersArrayROCount, const RedStructDeclarationMemberArrayRO * structDeclarationMembersArrayRO, RedBool32 procedureParametersHandlesDeclaration, Red2HandleStructDeclaration * outStructDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CreateProcedureParameters        (RedContext context, RedHandleGpu gpu, const char * handleName, const Red2ProcedureParametersDeclaration * procedureParametersDeclaration, Red2HandleProcedureParameters * outProcedureParameters, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CreateProcedure                  (RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, const Red2ProcedureDependencyOnRenderTargets * procedureDependencyOnRenderTargets, RedHandleProcedureParameters procedureParameters, const char * gpuCodeVertexMainProcedureName, RedHandleGpuCode gpuCodeVertex, const char * gpuCodeFragmentMainProcedureName, RedHandleGpuCode gpuCodeFragment, const RedProcedureState * state, const void * stateExtension, RedBool32 deriveBase, RedHandleProcedure deriveFrom, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CreateCalls                      (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, Red2HandleCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CreateCallsReusable              (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, Red2HandleCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);

REDGPU_2_DECLSPEC void      REDGPU_2_API red2DestroyContext                   (Red2Context context2, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2DestroyStructDeclaration         (RedContext context, RedHandleGpu gpu, Red2HandleStructDeclaration structDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2DestroyProcedureParameters       (RedContext context, RedHandleGpu gpu, Red2HandleProcedureParameters procedureParameters, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2DestroyCalls                     (RedContext context, RedHandleGpu gpu, Red2HandleCalls calls, const char * optionalFile, int optionalLine, void * optionalUserData);

REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallsSet                         (Red2HandleCalls calls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallsEnd                         (Red2HandleCalls calls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallsAppendHandleToDestroy       (Red2HandleCalls calls, uint64_t handleToDestroyWhenCallsAreReset, unsigned handleToDestroyWhenCallsAreResetType);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallsFreeAllInlineStructsMemorys (Red2HandleCalls calls, const char * optionalFile, int optionalLine, void * optionalUserData);

REDGPU_2_DECLSPEC void      REDGPU_2_API red2PresentGetImageIndex             (Red2Context context2, RedHandleGpu gpu, RedHandlePresent present, RedHandleCpuSignal signalCpuSignal, RedHandleGpuSignal signalGpuSignal, unsigned * outImageIndex, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2GetWsiStoredGpuSignal            (Red2Context context2, RedHandleGpu gpu, RedHandlePresent present, unsigned presentImageIndex, RedHandleGpuSignal * outGpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2QueueSubmit                      (Red2Context context2, RedHandleGpu gpu, RedHandleQueue queue, unsigned timelinesCount, const RedGpuTimeline * timelines, uint64_t * outQueueSubmissionTicketArrayIndex, uint64_t * outQueueSubmissionTicket, uint64_t handlesToDestroyWhenQueueSubmissionIsFinishedCount, const uint64_t * handlesToDestroyWhenQueueSubmissionIsFinished, const unsigned * handlesToDestroyWhenQueueSubmissionIsFinishedType, void * optionalCustomHandleAndHandleTypeDestroyCallback, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2QueueSubmitTrackableSimple       (Red2Context context2, RedHandleGpu gpu, RedHandleQueue queue, unsigned callsCount, Red2HandleCalls * calls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);

REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedXOnlyCreateQueue              (RedContext context, RedHandleGpu gpu, const char * handleName, RedBool32 canCopy, RedBool32 canDraw, RedBool32 canCompute, unsigned priority, RedBool32 disableGpuTimeout, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedOnlyPresentQueueWaitIdle      (RedContext context, RedHandleGpu gpu, RedHandleQueue presentQueue, const char * optionalFile, int optionalLine, void * optionalUserData);

// REDGPU 2 queue submission state procedures

REDGPU_2_DECLSPEC void      REDGPU_2_API red2DestroyHandlesToDestroyIfTheirQueueSubmissionIsFinished      (Red2Context context2, RedHandleGpu gpu, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC RedBool32 REDGPU_2_API red2IsQueueSubmissionFinished                                    (Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC RedBool32 REDGPU_2_API red2IsQueueSubmissionFinishedByTicketAlone                       (Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC RedBool32 REDGPU_2_API red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket         (Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2WaitForQueueSubmissionToFinish                               (Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2WaitForQueueSubmissionToFinishByTicketAlone                  (Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket     (Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2WaitForAllQueueSubmissionsToFinish                           (Red2Context context2, RedHandleGpu gpu, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);

// REDGPU 2 get and set handle data procedures

REDGPU_2_DECLSPEC RedHandleStructDeclaration    REDGPU_2_API red2StructDeclarationGetRedHandle            (Red2HandleStructDeclaration structDeclaration);
REDGPU_2_DECLSPEC Red2StructDeclarationMember * REDGPU_2_API red2StructDeclarationGetMembersPointer       (Red2HandleStructDeclaration structDeclaration);
REDGPU_2_DECLSPEC void                          REDGPU_2_API red2StructDeclarationGetMembersCounts        (Red2HandleStructDeclaration structDeclaration, unsigned * outStructDeclarationMembersCount, unsigned * outMembersOfTypeArrayROConstantCount, unsigned * outMembersOfTypeArrayROOrArrayRWCount, unsigned * outMembersOfTypeTextureROCount, unsigned * outMembersOfTypeTextureRWCount, unsigned * outMembersOfTypeInlineSamplerCount, unsigned * outMembersOfTypeSamplerCount);
REDGPU_2_DECLSPEC RedHandleProcedureParameters  REDGPU_2_API red2ProcedureParametersGetRedHandle          (Red2HandleProcedureParameters procedureParameters);
REDGPU_2_DECLSPEC Red2HandleStructDeclaration   REDGPU_2_API red2ProcedureParametersGetStructDeclaration  (Red2HandleProcedureParameters procedureParameters, unsigned structIndex);
REDGPU_2_DECLSPEC void                          REDGPU_2_API red2CallsGetRedHandles                       (Red2HandleCalls calls, RedContext * outContext, RedHandleGpu * outGpu, RedCalls * outCalls);
REDGPU_2_DECLSPEC uint64_t *                    REDGPU_2_API red2CallsGetHandlesToDestroy                 (Red2HandleCalls calls, uint64_t * outHandlesToDestroyWhenCallsAreResetCount);
REDGPU_2_DECLSPEC unsigned *                    REDGPU_2_API red2CallsGetHandlesToDestroyType             (Red2HandleCalls calls, uint64_t * outHandlesToDestroyWhenCallsAreResetTypeCount);
REDGPU_2_DECLSPEC void                          REDGPU_2_API red2CallsSetHandlesToDestroyCustomCallback   (Red2HandleCalls calls, void * optionalCustomHandleAndHandleTypeDestroyWhenCallsAreResetCallback);
REDGPU_2_DECLSPEC void                          REDGPU_2_API red2CallsGetQueueSubmitTrackableTicket       (Red2HandleCalls calls, uint64_t * outQueueSubmissionTicketArrayIndex, uint64_t * outQueueSubmissionTicket);
REDGPU_2_DECLSPEC void                          REDGPU_2_API red2CallsSetQueueSubmitTrackableTicket       (Red2HandleCalls calls, uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket);

// REDGPU 2 calls recording

// REDGPU 2
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetRenderTargets                                         (const RedCallProceduresAndAddresses * addresses, Red2HandleCalls calls, unsigned width, unsigned height, RedHandleTexture depthStencilTexture, unsigned depthStencilTextureFormat, RedMultisampleCountBitflag depthStencilTextureMultisampleCount, unsigned colorsTextureCountMax8, const RedHandleTexture * colorsTexture, const unsigned * colorsTextureFormat, const RedMultisampleCountBitflag * colorsTextureMultisampleCount, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallEndRenderTargets                                         (const RedCallProceduresAndAddresses * addresses, Red2HandleCalls calls);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallAllocateAndSetInlineStructsMemory                        (Red2HandleCalls calls, const char * structsMemoryHandleName, unsigned maxStructsCount, unsigned maxStructsOfTypeSamplerCount, unsigned maxStructsMembersOfTypeArrayROConstantCount, unsigned maxStructsMembersOfTypeArrayROOrArrayRWCount, unsigned maxStructsMembersOfTypeTextureROCount, unsigned maxStructsMembersOfTypeTextureRWCount, unsigned maxStructsMembersOfTypeInlineSamplerCount, unsigned maxStructsMembersOfTypeSamplerCount, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters (Red2HandleCalls calls, const char * structsMemoryHandleName, unsigned procedureParametersCount, const Red2InlineStructsMemoryFromProcedureParameters * procedureParameters, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
REDGPU_2_DECLSPEC RedStatus REDGPU_2_API red2CallSuballocateAndSetProcedureParametersInlineStruct         (Red2HandleCalls calls, RedProcedureType procedureType, Red2HandleProcedureParameters procedureParameters, unsigned structIndex, void ** structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
// REDGPU
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallGpuToCpuSignalSignal             (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleGpuToCpuSignal signalGpuToCpuSignal, unsigned setTo8192);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallCopyArrayToArray                 (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleArray arrayR, RedHandleArray arrayW, unsigned rangesCount, const RedCopyArrayRange * ranges);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallProcedure                        (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, unsigned vertexCount, unsigned instanceCount, unsigned vertexFirst, unsigned instanceFirst);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallProcedureIndexed                 (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, unsigned indexCount, unsigned instanceCount, unsigned indexFirst, int vertexBase, unsigned instanceFirst);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallProcedureCompute                 (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, unsigned workgroupsCountX, unsigned workgroupsCountY, unsigned workgroupsCountZ);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetProcedure                     (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedure procedure);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetProcedureIndices              (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleArray array, uint64_t setTo0, unsigned setTo1);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetProcedureParametersVariables  (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleProcedureParameters procedureParameters, RedVisibleToStageBitflags visibleToStages, unsigned variablesBytesFirst, unsigned dataBytesCount, const void * data);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetProcedureParametersStructs    (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedureParameters procedureParameters, unsigned procedureParametersDeclarationStructsDeclarationsFirst, unsigned structsCount, const RedHandleStruct * structs, unsigned setTo0, size_t setTo00);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetProcedureParametersHandles    (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedureParameters procedureParameters, unsigned procedureParametersDeclarationStructsDeclarationsCount, unsigned handlesCount, const RedProcedureParametersHandle * handles);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetDynamicStencilReference       (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedStencilFace face, unsigned reference);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetDynamicBlendConstants         (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, const float * blendConstants);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetDynamicViewport               (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, float x, float y, float width, float height, float depthMin, float depthMax);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetDynamicScissor                (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, int x, int y, unsigned width, unsigned height);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetStructsMemory                 (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleStructsMemory structsMemory, RedHandleStructsMemory structsMemorySamplers);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallSetProcedureParameters           (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedureParameters procedureParameters);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallMark                             (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, const char * mark);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallMarkSet                          (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, const char * mark);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2CallMarkEnd                          (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls);
// Backend-specific
REDGPU_2_DECLSPEC RedStatus REDGPU_2_API red2RedOnlyCallSetImageStateUsable       (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedContext context, unsigned imagesCount, const RedHandleImage * images, RedImagePartBitflags imagesAllParts);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedOnlyCallCopyImageToImage          (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleImage imageR, unsigned setTo1, RedHandleImage imageW, unsigned setTo01, unsigned rangesCount, const RedCopyImageRange * ranges);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedOnlyCallCopyArrayToImage          (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleArray arrayR, RedHandleImage imageW, unsigned setTo1, unsigned rangesCount, const RedCopyArrayImageRange * ranges);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedOnlyCallCopyImageToArray          (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleImage imageR, unsigned setTo1, RedHandleArray arrayW, unsigned rangesCount, const RedCopyArrayImageRange * ranges);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedXOnlyCallCopyImageRegion          (RedHandleCalls calls, unsigned copiesCount, const void * copies);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedOnlyCallBarrierGlobalMemory       (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls);
REDGPU_2_DECLSPEC RedStatus REDGPU_2_API red2RedOnlyCallBarrierFinishCpuUpload    (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, unsigned arraysCount, const RedHandleArray * arrays);
REDGPU_2_DECLSPEC RedStatus REDGPU_2_API red2RedOnlyCallBarrierFinishCpuReadback  (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, unsigned arraysCount, const RedHandleArray * arrays);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedOnlyCallBarrierUsageAliasOrder    (const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedContext context, unsigned arrayUsagesCount, const RedUsageArray * arrayUsages, unsigned imageUsagesCount, const RedUsageImage * imageUsages, RedBool32 dependencyByRegion);
REDGPU_2_DECLSPEC void      REDGPU_2_API red2RedXOnlyCallBarrierUsageAliasOrder   (RedHandleCalls calls, unsigned barriersCount, const void * barriers);

REDGPU_2_DECLSPEC unsigned  REDGPU_2_API red2RedXOnlyGetRedXAccessBitflagsFromRed (RedAccessBitflags access); // For red2RedXOnlyCallBarrierUsageAliasOrder
REDGPU_2_DECLSPEC unsigned  REDGPU_2_API red2RedXOnlyArrayGetMemoryTypeIndex      (RedHandleArray array);     // For red2RedXOnlyCallBarrierUsageAliasOrder
REDGPU_2_DECLSPEC unsigned  REDGPU_2_API red2RedXOnlyImageGetLevelsCount          (RedHandleImage image);     // For red2RedXOnlyCallBarrierUsageAliasOrder
REDGPU_2_DECLSPEC unsigned  REDGPU_2_API red2RedXOnlyImageGetLayersCount          (RedHandleImage image);     // For red2RedXOnlyCallBarrierUsageAliasOrder
REDGPU_2_DECLSPEC void *    REDGPU_2_API red2RedXOnlyArrayGetHandleResource       (RedHandleArray array);     // For red2RedXOnlyCallBarrierUsageAliasOrder
REDGPU_2_DECLSPEC void *    REDGPU_2_API red2RedXOnlyImageGetHandleResource       (RedHandleImage image);     // For red2RedXOnlyCallBarrierUsageAliasOrder

// REDGPU 2 changes from 28 Nov 2024:

#ifndef red2CallUsageAliasOrderBarrier
#define red2CallUsageAliasOrderBarrier REDGPU_2_COMPILE_TIME_ERROR_red2CallUsageAliasOrderBarrier_was_removed_on_28_Nov_2024_use_both_red2RedOnlyCallBarrierUsageAliasOrder_and_red2RedXOnlyCallBarrierUsageAliasOrder_instead
#endif

#ifdef __cplusplus
}
#endif
