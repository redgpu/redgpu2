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
  RedHandleCalls                             handle;
  RedHandleCallsMemory                       memory;
  RedBool32                                  reusable;
  RedContext                                 context;
  RedHandleGpu                               gpu;
  unsigned                                   currentStructsMemoryIndex;
  unsigned                                   currentStructsMemorySamplersIndex;
  uint64_t                                   lastQueueSubmitTrackableTicketArrayIndex;
  uint64_t                                   lastQueueSubmitTrackableTicket;
  void *                                     handlesToDestroyWhenCallsAreResetCustomCallback;
  std::vector<unsigned>                      handlesToDestroyWhenCallsAreResetType;
  std::vector<uint64_t>                      handlesToDestroyWhenCallsAreReset;
  std::vector<Red2InternalTypeStructsMemory> structsMemorys;
  std::vector<Red2InternalTypeStructsMemory> structsMemorysSamplers;
} Red2InternalTypeCalls;

typedef struct Red2InternalTypeStream {
  unsigned                     value65536;
  unsigned                     queueFamilyIndex;
  RedHandleGpuSignal           gpuSignalForSerialDependencyBetweenStreamSubmissions; // NOTE(Constantine): Always assumed to be in a signaled state.
  std::vector<Red2HandleCalls> streamCallsToGet;
  std::vector<RedBool32>       streamCallsToGetTaken;
  std::vector<RedHandleCalls>  streamCallsToSubmit;          // NOTE(Constantine): Cleared on flush.
  std::vector<Red2HandleCalls> streamCallsToSubmitType2;     // NOTE(Constantine): Cleared on flush.
  std::vector<size_t>          streamCallsToSubmitFirst;     // NOTE(Constantine): Cleared on flush. Array of count streamCallsToSubmitTimelines.
  std::vector<RedGpuTimeline>  streamCallsToSubmitTimelines; // NOTE(Constantine): Cleared on flush.
} Red2InternalTypeStream;
