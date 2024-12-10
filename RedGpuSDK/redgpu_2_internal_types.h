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
