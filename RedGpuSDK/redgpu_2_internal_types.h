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
  RedContext                                 context;
  RedHandleGpu                               gpu;
  RedBool32                                  reusable;
  unsigned                                   currentStructsMemoryIndex;
  unsigned                                   currentStructsMemorySamplersIndex;
  std::vector<Red2InternalTypeStructsMemory> structsMemorys;
  std::vector<Red2InternalTypeStructsMemory> structsMemorysSamplers;
} Red2InternalTypeCalls;
