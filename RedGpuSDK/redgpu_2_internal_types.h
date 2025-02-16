#pragma once

typedef struct Red2InternalTypeStructDeclaration {
  RedHandleStructDeclaration    handle;
  unsigned                      structDeclarationMembersCount;
  unsigned                      structDeclarationMembersCountWithoutInlineSamplers;
  Red2StructDeclarationMember * structDeclarationMembers;
  unsigned                      membersOfTypeArrayROConstantCount;
  unsigned                      membersOfTypeArrayROOrArrayRWCount;
  unsigned                      membersOfTypeTextureROCount;
  unsigned                      membersOfTypeTextureRWCount;
  unsigned                      membersOfTypeInlineSamplerCount;
  unsigned                      membersOfTypeSamplerCount;
} Red2InternalTypeStructDeclaration;

typedef struct Red2InternalTypeProcedureParameters {
  RedHandleProcedureParameters handle;
  Red2HandleStructDeclaration  structsDeclarations[7];
} Red2InternalTypeProcedureParameters;

typedef struct Red2InternalTypeStructsMemory {
  RedHandleStructsMemory handle;
  unsigned capacityDescriptors;
  unsigned capacityStructsCount;
  unsigned capacityStructsMembersOfTypeArrayROConstantCount;
  unsigned capacityStructsMembersOfTypeArrayROOrArrayRWCount;
  unsigned capacityStructsMembersOfTypeTextureROCount;
  unsigned capacityStructsMembersOfTypeTextureRWCount;
  unsigned capacityStructsMembersOfTypeInlineSamplerCount;
  unsigned capacityStructsMembersOfTypeSamplerCount;
  unsigned availableDescriptors;
  unsigned availableStructsCount;
  unsigned availableStructsMembersOfTypeArrayROConstantCount;
  unsigned availableStructsMembersOfTypeArrayROOrArrayRWCount;
  unsigned availableStructsMembersOfTypeTextureROCount;
  unsigned availableStructsMembersOfTypeTextureRWCount;
  unsigned availableStructsMembersOfTypeInlineSamplerCount;
  unsigned availableStructsMembersOfTypeSamplerCount;
} Red2InternalTypeStructsMemory;

typedef struct Red2InternalTypeCalls {
  RedHandleCalls                               handle;
  RedHandleCallsMemory                         memory;
  RedBool32                                    reusable;
  RedContext                                   context;
  RedHandleGpu                                 gpu;
  unsigned                                     currentStructsMemoryIndex;
  unsigned                                     currentStructsMemorySamplersIndex;
  uint64_t                                     lastQueueSubmitTrackableTicketArrayIndex;
  uint64_t                                     lastQueueSubmitTrackableTicket;
  void *                                       handlesToDestroyWhenCallsAreResetCustomCallback;
  REDGPU_VECTOR<unsigned>                      handlesToDestroyWhenCallsAreResetType;
  REDGPU_VECTOR<uint64_t>                      handlesToDestroyWhenCallsAreReset;
  REDGPU_VECTOR<Red2InternalTypeStructsMemory> structsMemorys;
  REDGPU_VECTOR<Red2InternalTypeStructsMemory> structsMemorysSamplers;
} Red2InternalTypeCalls;

typedef struct Red2InternalTypeStream {
  unsigned                       value65536;
  unsigned                       queueFamilyIndex;
  RedHandleGpuSignal             gpuSignalForSerialDependencyBetweenStreamSubmissions; // NOTE(Constantine): Always assumed to be in a signaled state.
  RedHandleGpuSignal             streamCallsToSubmitGpuSignals[2];                     // NOTE(Constantine): Element [1] is cleared on flush. Element [0] is constant and never changed.
  REDGPU_VECTOR<Red2HandleCalls> streamCallsToGet;
  REDGPU_VECTOR<RedBool32>       streamCallsToGetTaken;
  REDGPU_VECTOR<RedHandleCalls>  streamCallsToSubmit;          // NOTE(Constantine): Cleared on flush.
  REDGPU_VECTOR<Red2HandleCalls> streamCallsToSubmitType2;     // NOTE(Constantine): Cleared on flush.
  REDGPU_VECTOR<size_t>          streamCallsToSubmitFirst;     // NOTE(Constantine): Cleared on flush. Array of count streamCallsToSubmitTimelines.
  REDGPU_VECTOR<RedGpuTimeline>  streamCallsToSubmitTimelines; // NOTE(Constantine): Cleared on flush.
} Red2InternalTypeStream;
