#if defined(_WIN32) && !defined(__GNUC__)
#define REDGPU_2_DECLSPEC __declspec(dllexport)
#else
#define REDGPU_2_DECLSPEC __attribute__((visibility("default")))
#endif

#if defined(_WIN32)
#include "C:/RedGpuSDK/redgpu.h"
#include "C:/RedGpuSDK/redgpu_wsi.h"
#else
#include "/opt/RedGpuSDK/redgpu.h"
#include "/opt/RedGpuSDK/redgpu_wsi.h"
#endif
#ifdef REDGPU_USE_REDGPU_X
#include "C:/RedGpuSDK/redgpu_x.h"
#endif
#include "redgpu_2.h"
#include <vector>   // For std::vector
#include "redgpu_2_internal_types.h"
#include <string.h> // For memcpy
#include <mutex>    // For std::mutex
#include <new>      // For std::nothrow

void red2CreateStructDeclaration(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned structDeclarationMembersCount, const RedStructDeclarationMember * structDeclarationMembers, unsigned structDeclarationMembersArrayROCount, const RedStructDeclarationMemberArrayRO * structDeclarationMembersArrayRO, RedBool32 procedureParametersHandlesDeclaration, Red2HandleStructDeclaration * outStructDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeStructDeclaration * handle = new(std::nothrow) Red2InternalTypeStructDeclaration();
  if (handle == NULL) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = RED_PROCEDURE_ID_UNDEFINED;
        outStatuses->statusErrorFile           = optionalFile;
        outStatuses->statusErrorLine           = optionalLine;
        outStatuses->statusErrorDescription[0] = 0;
      }
    }
    outStructDeclaration[0] = NULL;
    return;
  }
  handle->structDeclarationMembers = new(std::nothrow) Red2StructDeclarationMember[structDeclarationMembersCount];
  if (handle->structDeclarationMembers == NULL) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = RED_PROCEDURE_ID_UNDEFINED;
        outStatuses->statusErrorFile           = optionalFile;
        outStatuses->statusErrorLine           = optionalLine;
        outStatuses->statusErrorDescription[0] = 0;
      }
    }
    delete handle;
    outStructDeclaration[0] = NULL;
    return;
  }
  handle->structDeclarationMembersCount = structDeclarationMembersCount;

  // NOTE(Constantine): Copy all members and sort inline samplers to the back of the array.
  {
    unsigned sortingIndex = 0;
    for (unsigned i = 0; i < structDeclarationMembersCount; i += 1) {
      if (structDeclarationMembers[i].type == RED_STRUCT_MEMBER_TYPE_SAMPLER && structDeclarationMembers[i].inlineSampler != NULL) {
        continue;
      }
      memcpy(&handle->structDeclarationMembers[sortingIndex], &structDeclarationMembers[i], sizeof(RedStructDeclarationMember));
      sortingIndex += 1;
    }
    handle->structDeclarationMembersCountWithoutInlineSamplers = sortingIndex;
    for (unsigned i = 0; i < structDeclarationMembersCount; i += 1) {
      if (structDeclarationMembers[i].type == RED_STRUCT_MEMBER_TYPE_SAMPLER && structDeclarationMembers[i].inlineSampler != NULL) {
        memcpy(&handle->structDeclarationMembers[sortingIndex], &structDeclarationMembers[i], sizeof(RedStructDeclarationMember));
        sortingIndex += 1;
      }
    }
  }

  // NOTE(Constantine): inlineSampler will have a junk array pointer, so iterate over handle->structDeclarationMembers and set handle->structDeclarationMembers[i].inlineSampler to handle->structDeclarationMembers[i].inlineSampler[0].
  for (unsigned i = 0; i < structDeclarationMembersCount; i += 1) {
    if (handle->structDeclarationMembers[i].type == RED_STRUCT_MEMBER_TYPE_SAMPLER && handle->structDeclarationMembers[i].inlineSampler != NULL) {
      RedHandleSampler s = ((RedHandleSampler *)(void *)(handle->structDeclarationMembers[i].inlineSampler))[0];
      handle->structDeclarationMembers[i].inlineSampler = s;
    }
  }

  // NOTE(Constantine): Count all member types.
  for (unsigned i = 0; i < structDeclarationMembersCount; i += 1) {
    unsigned count = structDeclarationMembers[i].count;
    if (structDeclarationMembers[i].type == RED_STRUCT_MEMBER_TYPE_ARRAY_RO_CONSTANT) {
      handle->membersOfTypeArrayROConstantCount  += count;
    } else if (structDeclarationMembers[i].type == RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW) {
      handle->membersOfTypeArrayROOrArrayRWCount += count;
    } else if (structDeclarationMembers[i].type == RED_STRUCT_MEMBER_TYPE_TEXTURE_RO) {
      handle->membersOfTypeTextureROCount        += count;
    } else if (structDeclarationMembers[i].type == RED_STRUCT_MEMBER_TYPE_TEXTURE_RW) {
      handle->membersOfTypeTextureRWCount        += count;
    } else if (structDeclarationMembers[i].type == RED_STRUCT_MEMBER_TYPE_SAMPLER && structDeclarationMembers[i].inlineSampler != NULL) {
      handle->membersOfTypeInlineSamplerCount    += count;
    } else if (structDeclarationMembers[i].type == RED_STRUCT_MEMBER_TYPE_SAMPLER && structDeclarationMembers[i].inlineSampler == NULL) {
      handle->membersOfTypeSamplerCount          += count;
    }
#ifdef REDGPU_USE_REDGPU_X
      else if (structDeclarationMembers[i].type == REDX_STRUCT_MEMBER_TYPE_ARRAY_RO) {
      handle->membersOfTypeArrayROOrArrayRWCount += count;
    }
#endif
  }

  redCreateStructDeclaration(context, gpu, handleName, structDeclarationMembersCount, structDeclarationMembers, structDeclarationMembersArrayROCount, structDeclarationMembersArrayRO, procedureParametersHandlesDeclaration, &handle->handle, outStatuses, optionalFile, optionalLine, optionalUserData);

  outStructDeclaration[0] = (Red2HandleStructDeclaration)(void *)handle;
}

void red2CreateProcedureParameters(RedContext context, RedHandleGpu gpu, const char * handleName, const Red2ProcedureParametersDeclaration * procedureParametersDeclaration, Red2HandleProcedureParameters * outProcedureParameters, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeProcedureParameters * handle = new(std::nothrow) Red2InternalTypeProcedureParameters();
  if (handle == NULL) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = RED_PROCEDURE_ID_UNDEFINED;
        outStatuses->statusErrorFile           = optionalFile;
        outStatuses->statusErrorLine           = optionalLine;
        outStatuses->statusErrorDescription[0] = 0;
      }
    }
    outProcedureParameters[0] = NULL;
    return;
  }
  RedProcedureParametersDeclaration   declaration        = {};
  RedProcedureParametersDeclaration * declarationPointer = NULL;
  if (procedureParametersDeclaration != NULL) {
    declarationPointer = &declaration;
    declaration.variablesSlot            = procedureParametersDeclaration->variablesSlot;
    declaration.variablesVisibleToStages = procedureParametersDeclaration->variablesVisibleToStages;
    declaration.variablesBytesCount      = procedureParametersDeclaration->variablesBytesCount;
    declaration.structsDeclarationsCount = procedureParametersDeclaration->structsDeclarationsCount;
    for (unsigned i = 0; i < procedureParametersDeclaration->structsDeclarationsCount; i += 1) {
      Red2HandleStructDeclaration declarationHandle = procedureParametersDeclaration->structsDeclarations[i];
      Red2InternalTypeStructDeclaration * declarationHandleInternal = (Red2InternalTypeStructDeclaration *)(void *)declarationHandle;
      if (declarationHandleInternal == NULL) {
        declaration.structsDeclarations[i] = NULL;
      } else {
        declaration.structsDeclarations[i] = declarationHandleInternal->handle;
      }
    }
    declaration.handlesDeclaration = procedureParametersDeclaration->handlesDeclaration;
  }
  redCreateProcedureParameters(context, gpu, handleName, declarationPointer, &handle->handle, outStatuses, optionalFile, optionalLine, optionalUserData);
  if (procedureParametersDeclaration != NULL) {
    for (unsigned i = 0; i < procedureParametersDeclaration->structsDeclarationsCount; i += 1) {
      handle->structsDeclarations[i] = procedureParametersDeclaration->structsDeclarations[i];
    }
  }
  outProcedureParameters[0] = (Red2HandleProcedureParameters)(void *)handle;
}

void red2CreateCalls(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, Red2Calls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeCalls * handle = new(std::nothrow) Red2InternalTypeCalls();
  if (handle == NULL) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = RED_PROCEDURE_ID_UNDEFINED;
        outStatuses->statusErrorFile           = optionalFile;
        outStatuses->statusErrorLine           = optionalLine;
        outStatuses->statusErrorDescription[0] = 0;
      }
    }
    outCalls = {};
    return;
  }
  redCreateCalls(context, gpu, handleName, queueFamilyIndex, (RedCalls *)(void *)outCalls, outStatuses, optionalFile, optionalLine, optionalUserData);
  handle->handle  = outCalls->handle;
  handle->memory  = outCalls->memory;
  handle->context = context;
  handle->gpu     = gpu;
  outCalls->handle2 = (Red2HandleCalls)(void *)handle;
}

void red2CreateCallsReusable(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, Red2Calls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeCalls * handle = new(std::nothrow) Red2InternalTypeCalls();
  if (handle == NULL) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = RED_PROCEDURE_ID_UNDEFINED;
        outStatuses->statusErrorFile           = optionalFile;
        outStatuses->statusErrorLine           = optionalLine;
        outStatuses->statusErrorDescription[0] = 0;
      }
    }
    outCalls = {};
    return;
  }
  redCreateCallsReusable(context, gpu, handleName, queueFamilyIndex, (RedCalls *)(void *)outCalls, outStatuses, optionalFile, optionalLine, optionalUserData);
  handle->handle  = outCalls->handle;
  handle->memory  = outCalls->memory;
  handle->context = context;
  handle->gpu     = gpu;
  outCalls->handle2 = (Red2HandleCalls)(void *)handle;
}

void red2DestroyStructDeclaration(RedContext context, RedHandleGpu gpu, Red2HandleStructDeclaration structDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeStructDeclaration * handle = (Red2InternalTypeStructDeclaration *)(void *)structDeclaration;
  if (handle != NULL) {
    delete[] handle->structDeclarationMembers;
    delete handle;
  }
}

void red2DestroyProcedureParameters(RedContext context, RedHandleGpu gpu, Red2HandleProcedureParameters procedureParameters, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeProcedureParameters * handle = (Red2InternalTypeProcedureParameters *)(void *)procedureParameters;
  if (handle != NULL) {
    delete handle;
  }
}

void red2DestroyCalls(RedContext context, RedHandleGpu gpu, Red2HandleCalls calls, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  if (handle != NULL) {
    RedHandleCalls       calls       = handle->handle;
    RedHandleCallsMemory callsMemory = handle->memory;
    for (size_t i = 0, count = handle->structsMemorys.size(); i < count; i += 1) {
      redStructsMemoryFree(context, gpu, handle->structsMemorys[i].handle, optionalFile, optionalLine, optionalUserData);
    }
    for (size_t i = 0, count = handle->structsMemorysSamplers.size(); i < count; i += 1) {
      redStructsMemoryFree(context, gpu, handle->structsMemorysSamplers[i].handle, optionalFile, optionalLine, optionalUserData);
    }
    delete handle;
    redDestroyCalls(context, gpu, calls, callsMemory, optionalFile, optionalLine, optionalUserData);
  }
}

RedHandleStructDeclaration red2StructDeclarationGetRedHandle(Red2HandleStructDeclaration structDeclaration) {
  Red2InternalTypeStructDeclaration * handle = (Red2InternalTypeStructDeclaration *)(void *)structDeclaration;
  return handle->handle;
}

Red2StructDeclarationMember * red2StructDeclarationGetMembersPointer(Red2HandleStructDeclaration structDeclaration) {
  Red2InternalTypeStructDeclaration * handle = (Red2InternalTypeStructDeclaration *)(void *)structDeclaration;
  return handle->structDeclarationMembers;
}

void red2StructDeclarationGetMembersCounts(Red2HandleStructDeclaration structDeclaration, unsigned * outMembersOfTypeArrayROConstantCount, unsigned * outMembersOfTypeArrayROOrArrayRWCount, unsigned * outMembersOfTypeTextureROCount, unsigned * outMembersOfTypeTextureRWCount, unsigned * outMembersOfTypeInlineSamplerCount, unsigned * outMembersOfTypeSamplerCount) {
  Red2InternalTypeStructDeclaration * handle = (Red2InternalTypeStructDeclaration *)(void *)structDeclaration;
  if (outMembersOfTypeArrayROConstantCount  != NULL) { outMembersOfTypeArrayROConstantCount[0]  = handle->membersOfTypeArrayROConstantCount;  }
  if (outMembersOfTypeArrayROOrArrayRWCount != NULL) { outMembersOfTypeArrayROOrArrayRWCount[0] = handle->membersOfTypeArrayROOrArrayRWCount; }
  if (outMembersOfTypeTextureROCount        != NULL) { outMembersOfTypeTextureROCount[0]        = handle->membersOfTypeTextureROCount;        }
  if (outMembersOfTypeTextureRWCount        != NULL) { outMembersOfTypeTextureRWCount[0]        = handle->membersOfTypeTextureRWCount;        }
  if (outMembersOfTypeInlineSamplerCount    != NULL) { outMembersOfTypeInlineSamplerCount[0]    = handle->membersOfTypeInlineSamplerCount;    }
  if (outMembersOfTypeSamplerCount          != NULL) { outMembersOfTypeSamplerCount[0]          = handle->membersOfTypeSamplerCount;          }
}

RedHandleProcedureParameters red2ProcedureParametersGetRedHandle(Red2HandleProcedureParameters procedureParameters) {
  Red2InternalTypeProcedureParameters * handle = (Red2InternalTypeProcedureParameters *)(void *)procedureParameters;
  return handle->handle;
}

Red2HandleStructDeclaration red2ProcedureParametersGetStructDeclaration(Red2HandleProcedureParameters procedureParameters, unsigned structIndex) {
  Red2InternalTypeProcedureParameters * handle = (Red2InternalTypeProcedureParameters *)(void *)procedureParameters;
  return handle->structsDeclarations[structIndex];
}

void red2CallsSet(
  RedContext context,
  RedHandleGpu gpu,
  Red2HandleCalls calls,
  RedHandleCallsMemory callsMemory,
  RedBool32 callsReusable,
  RedStatuses * outStatuses,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
)
{
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  handle->currentStructsMemoryIndex         = 0;
  handle->currentStructsMemorySamplersIndex = 0;
  for (size_t i = 0, count = handle->structsMemorys.size(); i < count; i += 1) {
#ifndef REDGPU_USE_REDGPU_X
    redStructsMemoryReset(context, gpu, handle->structsMemorys[i].handle, outStatuses, optionalFile, optionalLine, optionalUserData);
#endif
    handle->structsMemorys[i].availableDescriptors                               = handle->structsMemorys[i].capacityDescriptors;
    handle->structsMemorys[i].availableStructsCount                              = handle->structsMemorys[i].capacityStructsCount;
    handle->structsMemorys[i].availableStructsMembersOfTypeArrayROConstantCount  = handle->structsMemorys[i].capacityStructsMembersOfTypeArrayROConstantCount;
    handle->structsMemorys[i].availableStructsMembersOfTypeArrayROOrArrayRWCount = handle->structsMemorys[i].capacityStructsMembersOfTypeArrayROOrArrayRWCount;
    handle->structsMemorys[i].availableStructsMembersOfTypeTextureROCount        = handle->structsMemorys[i].capacityStructsMembersOfTypeTextureROCount;
    handle->structsMemorys[i].availableStructsMembersOfTypeTextureRWCount        = handle->structsMemorys[i].capacityStructsMembersOfTypeTextureRWCount;
    handle->structsMemorys[i].availableStructsMembersOfTypeInlineSamplerCount    = handle->structsMemorys[i].capacityStructsMembersOfTypeInlineSamplerCount;
    handle->structsMemorys[i].availableStructsMembersOfTypeSamplerCount          = handle->structsMemorys[i].capacityStructsMembersOfTypeSamplerCount;
  }
  for (size_t i = 0, count = handle->structsMemorysSamplers.size(); i < count; i += 1) {
#ifndef REDGPU_USE_REDGPU_X
    redStructsMemoryReset(context, gpu, handle->structsMemorysSamplers[i].handle, outStatuses, optionalFile, optionalLine, optionalUserData);
#endif
    handle->structsMemorysSamplers[i].availableDescriptors                               = handle->structsMemorysSamplers[i].capacityDescriptors;
    handle->structsMemorysSamplers[i].availableStructsCount                              = handle->structsMemorysSamplers[i].capacityStructsCount;
    handle->structsMemorysSamplers[i].availableStructsMembersOfTypeArrayROConstantCount  = handle->structsMemorysSamplers[i].capacityStructsMembersOfTypeArrayROConstantCount;
    handle->structsMemorysSamplers[i].availableStructsMembersOfTypeArrayROOrArrayRWCount = handle->structsMemorysSamplers[i].capacityStructsMembersOfTypeArrayROOrArrayRWCount;
    handle->structsMemorysSamplers[i].availableStructsMembersOfTypeTextureROCount        = handle->structsMemorysSamplers[i].capacityStructsMembersOfTypeTextureROCount;
    handle->structsMemorysSamplers[i].availableStructsMembersOfTypeTextureRWCount        = handle->structsMemorysSamplers[i].capacityStructsMembersOfTypeTextureRWCount;
    handle->structsMemorysSamplers[i].availableStructsMembersOfTypeInlineSamplerCount    = handle->structsMemorysSamplers[i].capacityStructsMembersOfTypeInlineSamplerCount;
    handle->structsMemorysSamplers[i].availableStructsMembersOfTypeSamplerCount          = handle->structsMemorysSamplers[i].capacityStructsMembersOfTypeSamplerCount;
  }
  redCallsSet(context, gpu, handle->handle, callsMemory, callsReusable, outStatuses, optionalFile, optionalLine, optionalUserData);
}

void red2CallsEnd(
  RedContext context,
  RedHandleGpu gpu,
  Red2HandleCalls calls,
  RedHandleCallsMemory callsMemory,
  RedStatuses * outStatuses,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
)
{
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  redCallsEnd(context, gpu, handle->handle, callsMemory, outStatuses, optionalFile, optionalLine, optionalUserData);
}

void red2CallsFreeAllInlineStructsMemorys(
  RedContext context,
  RedHandleGpu gpu,
  Red2HandleCalls calls,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
)
{
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  for (size_t i = 0, count = handle->structsMemorys.size(); i < count; i += 1) {
    redStructsMemoryFree(context, gpu, handle->structsMemorys[i].handle, optionalFile, optionalLine, optionalUserData);
  }
  for (size_t i = 0, count = handle->structsMemorysSamplers.size(); i < count; i += 1) {
    redStructsMemoryFree(context, gpu, handle->structsMemorysSamplers[i].handle, optionalFile, optionalLine, optionalUserData);
  }
  handle->currentStructsMemoryIndex         = 0;
  handle->currentStructsMemorySamplersIndex = 0;
  handle->structsMemorys                    = {};
  handle->structsMemorysSamplers            = {};
}

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
)
{
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;

  RedHandleStructsMemory structsMemory         = NULL;
  RedHandleStructsMemory structsMemorySamplers = NULL;

  RedCallProceduresAndAddresses pas = {};
  redGetCallProceduresAndAddresses(handle->context, handle->gpu, &pas, outStatuses, optionalFile, optionalLine, optionalUserData);

  if (maxStructsCount == 0 && maxStructsOfTypeSamplerCount == 0) {
    redCallSetStructsMemory(pas.redCallSetStructsMemory, handle->handle, NULL, NULL);
    return;
  }

  if (maxStructsMembersOfTypeArrayROConstantCount  == 0 &&
      maxStructsMembersOfTypeArrayROOrArrayRWCount == 0 &&
      maxStructsMembersOfTypeTextureROCount        == 0 &&
      maxStructsMembersOfTypeTextureRWCount        == 0 &&
      maxStructsMembersOfTypeInlineSamplerCount    == 0 &&
      maxStructsMembersOfTypeSamplerCount          == 0)
  {
    redCallSetStructsMemory(pas.redCallSetStructsMemory, handle->handle, NULL, NULL);
    return;
  }

  // NOTE(Constantine):
  // Check which structs memory types should be allocated.
  RedBool32 requestedStructsMemory         = 0;
  RedBool32 requestedStructsMemorySamplers = 0;
  if (maxStructsMembersOfTypeArrayROConstantCount  > 0 ||
      maxStructsMembersOfTypeArrayROOrArrayRWCount > 0 ||
      maxStructsMembersOfTypeTextureROCount        > 0 ||
      maxStructsMembersOfTypeTextureRWCount        > 0 ||
      maxStructsMembersOfTypeInlineSamplerCount    > 0)
  {
    requestedStructsMemory = 1;
  }
  if (maxStructsMembersOfTypeSamplerCount > 0) {
    requestedStructsMemorySamplers = 1;
  }

#ifdef REDGPU_USE_REDGPU_X
  unsigned maxDescriptorsOfTypeCbvSrvUav = maxStructsMembersOfTypeArrayROConstantCount + maxStructsMembersOfTypeArrayROOrArrayRWCount + maxStructsMembersOfTypeTextureROCount + maxStructsMembersOfTypeTextureRWCount;
  unsigned maxDescriptorsOfTypeSampler   = maxStructsMembersOfTypeSamplerCount;
#endif

  // NOTE(Constantine):
  // Check from the current structs memory indexes if the requested structs allocations can fit in the current structs memorys.
  RedBool32 requestedStructsAllocationsCanFitInTheCurrentStructsMemory         = 0;
  RedBool32 requestedStructsAllocationsCanFitInTheCurrentStructsMemorySamplers = 0;
  if (requestedStructsMemory == 1) {
    for (size_t i = handle->currentStructsMemoryIndex, count = handle->structsMemorys.size(); i < count; i += 1) {
      Red2InternalTypeStructsMemory memory = handle->structsMemorys[i];
#ifdef REDGPU_USE_REDGPU_X
      unsigned memoryAvailableDescriptorsOfTypeCbvSrvUav = memory.availableStructsMembersOfTypeArrayROConstantCount + memory.availableStructsMembersOfTypeArrayROOrArrayRWCount + memory.availableStructsMembersOfTypeTextureROCount + memory.availableStructsMembersOfTypeTextureRWCount;
      if (maxDescriptorsOfTypeCbvSrvUav <= memoryAvailableDescriptorsOfTypeCbvSrvUav)
#else
      if (maxStructsCount                              <= memory.availableStructsCount                              &&
          maxStructsMembersOfTypeArrayROConstantCount  <= memory.availableStructsMembersOfTypeArrayROConstantCount  &&
          maxStructsMembersOfTypeArrayROOrArrayRWCount <= memory.availableStructsMembersOfTypeArrayROOrArrayRWCount &&
          maxStructsMembersOfTypeTextureROCount        <= memory.availableStructsMembersOfTypeTextureROCount        &&
          maxStructsMembersOfTypeTextureRWCount        <= memory.availableStructsMembersOfTypeTextureRWCount        &&
          maxStructsMembersOfTypeInlineSamplerCount    <= memory.availableStructsMembersOfTypeInlineSamplerCount)
#endif
      {
        requestedStructsAllocationsCanFitInTheCurrentStructsMemory = 1;
        structsMemory = memory.handle;
        handle->currentStructsMemoryIndex = i;
        break;
      }
    }
  }
  if (requestedStructsMemorySamplers == 1) {
    for (size_t i = handle->currentStructsMemorySamplersIndex, count = handle->structsMemorysSamplers.size(); i < count; i += 1) {
      Red2InternalTypeStructsMemory memory = handle->structsMemorysSamplers[i];
#ifdef REDGPU_USE_REDGPU_X
      unsigned memoryAvailableDescriptorsOfTypeSampler = memory.availableStructsMembersOfTypeSamplerCount;
      if (maxDescriptorsOfTypeSampler <= memoryAvailableDescriptorsOfTypeSampler)
#else
      if (maxStructsOfTypeSamplerCount        <= memory.availableStructsCount &&
          maxStructsMembersOfTypeSamplerCount <= memory.availableStructsMembersOfTypeSamplerCount)
#endif
      {
        requestedStructsAllocationsCanFitInTheCurrentStructsMemorySamplers = 1;
        structsMemorySamplers = memory.handle;
        handle->currentStructsMemorySamplersIndex = i;
        break;
      }
    }
  }

  // NOTE(Constantine):
  // If the requested structs allocations can't fit in the current structs memorys, allocate them and set the current structs memorys indexes to the new allocations.
  if (requestedStructsAllocationsCanFitInTheCurrentStructsMemory == 0) {
    Red2InternalTypeStructsMemory memory = {};
    redStructsMemoryAllocateWithInlineSamplers(
      handle->context,
      handle->gpu,
      structsMemoryHandleName,
      maxStructsCount,
      maxStructsMembersOfTypeArrayROConstantCount,
      maxStructsMembersOfTypeArrayROOrArrayRWCount,
      maxStructsMembersOfTypeTextureROCount,
      maxStructsMembersOfTypeTextureRWCount,
      maxStructsMembersOfTypeInlineSamplerCount,
      &memory.handle,
      outStatuses,
      optionalFile,
      optionalLine,
      optionalUserData
    );
    memory.capacityDescriptors                                = maxStructsMembersOfTypeArrayROConstantCount + maxStructsMembersOfTypeArrayROOrArrayRWCount + maxStructsMembersOfTypeTextureROCount + maxStructsMembersOfTypeTextureRWCount;
    memory.capacityStructsCount                               = maxStructsCount;
    memory.capacityStructsMembersOfTypeArrayROConstantCount   = maxStructsMembersOfTypeArrayROConstantCount;
    memory.capacityStructsMembersOfTypeArrayROOrArrayRWCount  = maxStructsMembersOfTypeArrayROOrArrayRWCount;
    memory.capacityStructsMembersOfTypeTextureROCount         = maxStructsMembersOfTypeTextureROCount;
    memory.capacityStructsMembersOfTypeTextureRWCount         = maxStructsMembersOfTypeTextureRWCount;
    memory.capacityStructsMembersOfTypeInlineSamplerCount     = maxStructsMembersOfTypeInlineSamplerCount;
    memory.capacityStructsMembersOfTypeSamplerCount           = 0;
    memory.availableDescriptors                               = maxStructsMembersOfTypeArrayROConstantCount + maxStructsMembersOfTypeArrayROOrArrayRWCount + maxStructsMembersOfTypeTextureROCount + maxStructsMembersOfTypeTextureRWCount;
    memory.availableStructsCount                              = maxStructsCount;
    memory.availableStructsMembersOfTypeArrayROConstantCount  = maxStructsMembersOfTypeArrayROConstantCount;
    memory.availableStructsMembersOfTypeArrayROOrArrayRWCount = maxStructsMembersOfTypeArrayROOrArrayRWCount;
    memory.availableStructsMembersOfTypeTextureROCount        = maxStructsMembersOfTypeTextureROCount;
    memory.availableStructsMembersOfTypeTextureRWCount        = maxStructsMembersOfTypeTextureRWCount;
    memory.availableStructsMembersOfTypeInlineSamplerCount    = maxStructsMembersOfTypeInlineSamplerCount;
    memory.availableStructsMembersOfTypeSamplerCount          = 0;

    handle->structsMemorys.push_back(memory);

    requestedStructsAllocationsCanFitInTheCurrentStructsMemory = 1;
    structsMemory = memory.handle;
    handle->currentStructsMemoryIndex = handle->structsMemorys.size() - 1;
  }
  if (requestedStructsAllocationsCanFitInTheCurrentStructsMemorySamplers == 0) {
    Red2InternalTypeStructsMemory memory = {};
    redStructsMemoryAllocateSamplers(
      handle->context,
      handle->gpu,
      structsMemoryHandleName,
      maxStructsOfTypeSamplerCount,
      maxStructsMembersOfTypeSamplerCount,
      &memory.handle,
      outStatuses,
      optionalFile,
      optionalLine,
      optionalUserData
    );
    memory.capacityDescriptors                                = maxStructsMembersOfTypeSamplerCount;
    memory.capacityStructsCount                               = maxStructsOfTypeSamplerCount;
    memory.capacityStructsMembersOfTypeArrayROConstantCount   = 0;
    memory.capacityStructsMembersOfTypeArrayROOrArrayRWCount  = 0;
    memory.capacityStructsMembersOfTypeTextureROCount         = 0;
    memory.capacityStructsMembersOfTypeTextureRWCount         = 0;
    memory.capacityStructsMembersOfTypeInlineSamplerCount     = 0;
    memory.capacityStructsMembersOfTypeSamplerCount           = maxStructsMembersOfTypeSamplerCount;
    memory.availableDescriptors                               = maxStructsMembersOfTypeSamplerCount;
    memory.availableStructsCount                              = maxStructsOfTypeSamplerCount;
    memory.availableStructsMembersOfTypeArrayROConstantCount  = 0;
    memory.availableStructsMembersOfTypeArrayROOrArrayRWCount = 0;
    memory.availableStructsMembersOfTypeTextureROCount        = 0;
    memory.availableStructsMembersOfTypeTextureRWCount        = 0;
    memory.availableStructsMembersOfTypeInlineSamplerCount    = 0;
    memory.availableStructsMembersOfTypeSamplerCount          = maxStructsMembersOfTypeSamplerCount;

    handle->structsMemorysSamplers.push_back(memory);

    requestedStructsAllocationsCanFitInTheCurrentStructsMemorySamplers = 1;
    structsMemorySamplers = memory.handle;
    handle->currentStructsMemorySamplersIndex = handle->structsMemorysSamplers.size() - 1;
  }

  redCallSetStructsMemory(pas.redCallSetStructsMemory, handle->handle, structsMemory, structsMemorySamplers);
}

REDGPU_2_DECLSPEC void REDGPU_2_API red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters(
  Red2HandleCalls calls,
  const char * structsMemoryHandleName,
  unsigned procedureParametersCount,
  const Red2InlineStructsMemoryFromProcedureParameters * procedureParameters,
  RedStatuses * outStatuses,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
)
{
  unsigned maxStructsCount                              = 0;
  unsigned maxStructsOfTypeSamplerCount                 = 0;
  unsigned maxStructsMembersOfTypeArrayROConstantCount  = 0;
  unsigned maxStructsMembersOfTypeArrayROOrArrayRWCount = 0;
  unsigned maxStructsMembersOfTypeTextureROCount        = 0;
  unsigned maxStructsMembersOfTypeTextureRWCount        = 0;
  unsigned maxStructsMembersOfTypeInlineSamplerCount    = 0;
  unsigned maxStructsMembersOfTypeSamplerCount          = 0;
  for (unsigned i = 0; i < procedureParametersCount; i += 1) {
    Red2HandleProcedureParameters parameters = procedureParameters[i].procedureParameters;
    Red2InternalTypeProcedureParameters * parametersHandle = (Red2InternalTypeProcedureParameters *)(void *)parameters;
    for (unsigned k = 0; k < procedureParameters[i].procedureParametersAllocationsCount; k += 1) {
      for (unsigned j = 0; j < 7; j += 1) {
        unsigned multiplier = procedureParameters[i].procedureParametersStructsOptionalAllocationsCount[j];
        if (multiplier == 0) { multiplier = 1; }
        Red2HandleStructDeclaration structDeclaration = parametersHandle->structsDeclarations[j];
        Red2InternalTypeStructDeclaration * structDeclarationHandle = (Red2InternalTypeStructDeclaration *)(void *)structDeclaration;
        if (structDeclarationHandle != NULL) {
          if (structDeclarationHandle->structDeclarationMembersCount > 0) {
            if (structDeclarationHandle->membersOfTypeSamplerCount == 0) {
              maxStructsCount += multiplier;
            } else {
              maxStructsOfTypeSamplerCount += multiplier;
            }
            maxStructsMembersOfTypeArrayROConstantCount  += structDeclarationHandle->membersOfTypeArrayROConstantCount  * multiplier;
            maxStructsMembersOfTypeArrayROOrArrayRWCount += structDeclarationHandle->membersOfTypeArrayROOrArrayRWCount * multiplier;
            maxStructsMembersOfTypeTextureROCount        += structDeclarationHandle->membersOfTypeTextureROCount        * multiplier;
            maxStructsMembersOfTypeTextureRWCount        += structDeclarationHandle->membersOfTypeTextureRWCount        * multiplier;
            maxStructsMembersOfTypeInlineSamplerCount    += structDeclarationHandle->membersOfTypeInlineSamplerCount    * multiplier;
            maxStructsMembersOfTypeSamplerCount          += structDeclarationHandle->membersOfTypeSamplerCount          * multiplier;
          }
        } else {
          break; // NOTE(Constantine): Using this implementation's guarantee that if struct declaration handle is NULL, then all the following handles are NULL too, so breaking early then.
        }
      }
    }
  }
  red2CallAllocateAndSetInlineStructsMemory(
    calls,
    structsMemoryHandleName,
    maxStructsCount,
    maxStructsOfTypeSamplerCount,
    maxStructsMembersOfTypeArrayROConstantCount,
    maxStructsMembersOfTypeArrayROOrArrayRWCount,
    maxStructsMembersOfTypeTextureROCount,
    maxStructsMembersOfTypeTextureRWCount,
    maxStructsMembersOfTypeInlineSamplerCount,
    maxStructsMembersOfTypeSamplerCount,
    outStatuses,
    optionalFile,
    optionalLine,
    optionalUserData
  );
}

REDGPU_2_DECLSPEC void REDGPU_2_API red2CallSuballocateAndSetProcedureParametersInlineStruct(
  Red2HandleCalls calls,
  RedProcedureType procedureType,
  Red2HandleProcedureParameters procedureParameters,
  unsigned structIndex,
  void ** structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers,
  RedStatuses * outStatuses,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
)
{
  Red2InternalTypeCalls *               handle     = (Red2InternalTypeCalls *)(void *)calls;
  Red2InternalTypeProcedureParameters * parameters = (Red2InternalTypeProcedureParameters *)(void *)procedureParameters;

  RedCallProceduresAndAddresses pas = {};
  redGetCallProceduresAndAddresses(handle->context, handle->gpu, &pas, outStatuses, optionalFile, optionalLine, optionalUserData);

  Red2HandleStructDeclaration structDeclaration = parameters->structsDeclarations[structIndex];
  Red2InternalTypeStructDeclaration * structDeclarationHandle = (Red2InternalTypeStructDeclaration *)(void *)structDeclaration;

  RedBool32 isStructOfTypeSamplers = 0;
  if (structDeclarationHandle->membersOfTypeSamplerCount > 0) {
    isStructOfTypeSamplers = 1;
  }

  Red2InternalTypeStructsMemory memory;
  RedHandleStructsMemory structsMemory;
  if (isStructOfTypeSamplers == 0) {
    memory        = handle->structsMemorys[handle->currentStructsMemoryIndex];
    structsMemory = memory.handle;
  } else {
    memory        = handle->structsMemorysSamplers[handle->currentStructsMemorySamplersIndex];
    structsMemory = memory.handle;
  }

  unsigned structDeclarationDescriptorsCount = structDeclarationHandle->membersOfTypeArrayROConstantCount + structDeclarationHandle->membersOfTypeArrayROOrArrayRWCount + structDeclarationHandle->membersOfTypeTextureROCount + structDeclarationHandle->membersOfTypeTextureRWCount + structDeclarationHandle->membersOfTypeSamplerCount; // NOTE(Constantine): Adding structDeclarationHandle->membersOfTypeSamplerCount is intentional here, since it's equal to 0 for CbvSrvUav descriptor heaps.

#ifdef REDGPU_USE_REDGPU_X

  unsigned structsMemoryDescriptorsOffsetStart = memory.availableDescriptors - structDeclarationDescriptorsCount;

  unsigned memberGlobalIndex = 0;
  for (unsigned i = 0; i < structDeclarationHandle->structDeclarationMembersCountWithoutInlineSamplers; i += 1) {
    Red2StructDeclarationMember m = structDeclarationHandle->structDeclarationMembers[i];
    for (unsigned j = 0; j < m.count; j += 1) {
      void * h = structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers[memberGlobalIndex];
      unsigned oneCopy[1] = {1};
      RedXMemoryAddress rAddress = {0};
      RedXMemoryAddress wAddress = {redXGetMemoryAddressStructMember(handle->context, handle->gpu, structsMemory, structsMemoryDescriptorsOffsetStart + memberGlobalIndex)};
      if      (m.type == RED_STRUCT_MEMBER_TYPE_ARRAY_RO_CONSTANT) { rAddress.memoryAddress = redXGetMemoryAddressArray(handle->context, handle->gpu, (RedHandleArray)h);       }
      else if (m.type == RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW)       { rAddress.memoryAddress = redXGetMemoryAddressArray(handle->context, handle->gpu, (RedHandleArray)h);       }
      else if (m.type == RED_STRUCT_MEMBER_TYPE_SAMPLER)           { rAddress.memoryAddress = redXGetMemoryAddressSampler(handle->context, handle->gpu, (RedHandleSampler)h);   }
      else if (m.type == RED_STRUCT_MEMBER_TYPE_TEXTURE_RO)        { rAddress.memoryAddress = redXGetMemoryAddressTextureRO(handle->context, handle->gpu, (RedHandleTexture)h); }
      else if (m.type == RED_STRUCT_MEMBER_TYPE_TEXTURE_RW)        { rAddress.memoryAddress = redXGetMemoryAddressTextureRW(handle->context, handle->gpu, (RedHandleTexture)h); }
      else if (m.type == REDX_STRUCT_MEMBER_TYPE_ARRAY_RO)         { rAddress.memoryAddress = redXGetMemoryAddressArray(handle->context, handle->gpu, (RedHandleArray)h);       }
      redXStructsMemorySet(
        handle->context,
        handle->gpu,
        1,               // copyingSamplers
        1,               // sourceCopiesCount
        &rAddress,       // sourceCopiesAddressFirst
        oneCopy,         // sourceCopiesAddressCount
        1,               // targetCopiesCount
        &wAddress,       // targetCopiesAddressFirst
        oneCopy,         // targetCopiesAddressCount
        outStatuses,
        optionalFile,
        optionalLine,
        optionalUserData
      );
      memberGlobalIndex += 1;
    }
  }

  RedHandleStruct structHandle = redXGetHandleStruct(handle->context, handle->gpu, structsMemory, structsMemoryDescriptorsOffsetStart);

#else

  RedHandleStruct structHandle = NULL;
  redStructsMemorySuballocateStructs(
    handle->context,
    handle->gpu,
    NULL,
    structsMemory,
    1,
    &structDeclarationHandle->handle,
    &structHandle,
    outStatuses,
    optionalFile,
    optionalLine,
    optionalUserData
  );
  if (structHandle == NULL) {
    return;
  }

  unsigned memberGlobalIndex = 0;
  for (unsigned i = 0; i < structDeclarationHandle->structDeclarationMembersCountWithoutInlineSamplers; i += 1) {
    Red2StructDeclarationMember m = structDeclarationHandle->structDeclarationMembers[i];
    for (unsigned j = 0; j < m.count; j += 1) {
      void * h = structAllRedHandlesInParameterArrayOrderOfRed2CreateStructDeclarationStructDeclarationMembers[memberGlobalIndex];
      RedStructMemberTexture texture;
      texture.sampler = m.type == RED_STRUCT_MEMBER_TYPE_SAMPLER ? (RedHandleSampler)h : NULL;
      texture.texture = m.type == RED_STRUCT_MEMBER_TYPE_SAMPLER ? NULL : (RedHandleTexture)h;
      texture.setTo1  = 1;
      RedStructMemberArray array;
      array.array                = (RedHandleArray)h;
      array.arrayRangeBytesFirst = 0;
      array.arrayRangeBytesCount = -1;
      RedStructMember member;
      member.setTo35   = 35;
      member.setTo0    = 0;
      member.structure = structHandle;
      member.slot      = m.slot;
      member.first     = j;
      member.count     = 1;
      member.type      = m.type;
      member.textures  = &texture;
      member.arrays    = &array;
      member.setTo00   = 0;
      redStructsSet(
        handle->context,
        handle->gpu,
        1,
        &member,
        optionalFile,
        optionalLine,
        optionalUserData
      );
      memberGlobalIndex += 1;
    }
  }

#endif // #ifdef REDGPU_USE_REDGPU_X

  // NOTE(Constantine): Subtract from available struct member counts.
  memory.availableDescriptors                               -= structDeclarationDescriptorsCount;
  memory.availableStructsCount                              -= 1;
  memory.availableStructsMembersOfTypeArrayROConstantCount  -= structDeclarationHandle->membersOfTypeArrayROConstantCount;
  memory.availableStructsMembersOfTypeArrayROOrArrayRWCount -= structDeclarationHandle->membersOfTypeArrayROOrArrayRWCount;
  memory.availableStructsMembersOfTypeTextureROCount        -= structDeclarationHandle->membersOfTypeTextureROCount;
  memory.availableStructsMembersOfTypeTextureRWCount        -= structDeclarationHandle->membersOfTypeTextureRWCount;
  memory.availableStructsMembersOfTypeInlineSamplerCount    -= structDeclarationHandle->membersOfTypeInlineSamplerCount;
  memory.availableStructsMembersOfTypeSamplerCount          -= structDeclarationHandle->membersOfTypeSamplerCount;

  pas.redCallSetProcedureParametersStructs(handle->handle, procedureType, parameters->handle, structIndex, 1, &structHandle, 0, 0);
}

typedef struct Red2InternalSelfDestroyableCallsBatch {
  RedContext                   context;
  RedHandleGpu                 gpu;
  RedHandleCpuSignal           cpuSignal;
  std::vector<RedCalls>        callsToDestroyWhenFinished;
  std::vector<Red2HandleCalls> calls2ToDestroyWhenFinished;
} Red2InternalSelfDestroyableCallsBatch;

static std::mutex                                         __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatchesMutex;
static std::vector<Red2InternalSelfDestroyableCallsBatch> __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches;
static std::vector<RedBool32>                             __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatchesIsElementFree;

static void red2InternalSelfDestroyableCallsBatchesFreeFinishedBatches_Locking(RedContext context, RedHandleGpu gpu, RedBool32 waitForAllAndFreeAllBatches, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  std::lock_guard<std::mutex> __selfDestroyableCallsBatchesMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatchesMutex);
  for (size_t i = 0, count = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches.size(); i < count; i += 1) {
    if (__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatchesIsElementFree[i] == 0) {
      if (__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches[i].context == context &&
          __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches[i].gpu     == gpu)
      {
        RedHandleCpuSignal cpuSignal = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches[i].cpuSignal;
        if (waitForAllAndFreeAllBatches == 1) {
          redCpuSignalWait(context, gpu, 1, &cpuSignal, 1, outStatuses, optionalFile, optionalLine, optionalUserData);
        }
        RedStatus status = RED_STATUS_SUCCESS;
        redCpuSignalGetStatus(context, gpu, cpuSignal, &status, optionalFile, optionalLine, optionalUserData);
        if (status == RED_STATUS_SUCCESS) {
          redDestroyCpuSignal(context, gpu, cpuSignal, optionalFile, optionalLine, optionalUserData);
          for (RedCalls calls : __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches[i].callsToDestroyWhenFinished) {
            redDestroyCalls(context, gpu, calls.handle, calls.memory, optionalFile, optionalLine, optionalUserData);
          }
          for (Red2HandleCalls calls2 : __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches[i].calls2ToDestroyWhenFinished) {
            red2DestroyCalls(context, gpu, calls2, optionalFile, optionalLine, optionalUserData);
          }
          __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatchesIsElementFree[i] = 1;
        }
      }
    }
  }
}

static size_t red2InternalSelfDestroyableCallsBatchesGetFreeElementIndex_NonLocking() {
  size_t index = -1;
  for (size_t i = 0, count = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatchesIsElementFree.size(); i < count; i += 1) {
    if (__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatchesIsElementFree[i] == 1) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    Red2InternalSelfDestroyableCallsBatch emptyElement = {};
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches.push_back(emptyElement);
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatchesIsElementFree.push_back(1);
    index = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches.size() - 1;
  }
  return index;
}

void red2DestroyContext(RedContext context, const char * optionalFile, int optionalLine, void * optionalUserData) {
  for (unsigned gpuIndex = 0; gpuIndex < context->gpusCount; gpuIndex += 1) {
    const RedGpuInfo * gpuInfo = &context->gpus[gpuIndex];
    for (unsigned queueIndex = 0; queueIndex < gpuInfo->queuesCount; queueIndex += 1) {
      redQueuePresent(context, gpuInfo->gpu, gpuInfo->queues[queueIndex], 0, NULL, 0, NULL, NULL, NULL, NULL, optionalFile, optionalLine, optionalUserData);
    }
    red2InternalSelfDestroyableCallsBatchesFreeFinishedBatches_Locking(context, gpuInfo->gpu, 1, NULL, optionalFile, optionalLine, optionalUserData);
  }
  redDestroyContext(context, optionalFile, optionalLine, optionalUserData);
}

void red2QueueSubmitGpuTimelinesWithSelfDestroyableCalls(RedContext context, RedHandleGpu gpu, RedHandleQueue queue, unsigned timelinesCount, const RedGpuTimeline * timelines, unsigned callsToDestroyWhenFinishedCount, RedCalls * callsToDestroyWhenFinished, unsigned calls2ToDestroyWhenFinishedCount, Red2HandleCalls * calls2ToDestroyWhenFinished, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  red2InternalSelfDestroyableCallsBatchesFreeFinishedBatches_Locking(context, gpu, 0, outStatuses, optionalFile, optionalLine, optionalUserData);
  RedHandleCpuSignal cpuSignal = NULL;
  redCreateCpuSignal(context, gpu, NULL, 0, &cpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
  redQueueSubmit(context, gpu, queue, timelinesCount, timelines, cpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
  if (cpuSignal != NULL) {
    std::lock_guard<std::mutex> __selfDestroyableCallsBatchesMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatchesMutex);
    size_t i = red2InternalSelfDestroyableCallsBatchesGetFreeElementIndex_NonLocking();
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches[i].context                     = context;
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches[i].gpu                         = gpu;
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches[i].cpuSignal                   = cpuSignal;
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches[i].callsToDestroyWhenFinished  = std::vector<RedCalls>(callsToDestroyWhenFinished, callsToDestroyWhenFinished + callsToDestroyWhenFinishedCount);
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatches[i].calls2ToDestroyWhenFinished = std::vector<Red2HandleCalls>(calls2ToDestroyWhenFinished, calls2ToDestroyWhenFinished + calls2ToDestroyWhenFinishedCount);
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableCallsBatchesIsElementFree[i]                = 0;
  }
}
