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
#include <map>      // For std::map

#include "misc/np/np_redgpu_2.h" // NOTE(Constantine): np_redgpu_2.h is included here just to check if it compiles correctly.

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

void red2CreateCalls(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, Red2HandleCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
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
  RedCalls calls = {};
  redCreateCalls(context, gpu, handleName, queueFamilyIndex, &calls, outStatuses, optionalFile, optionalLine, optionalUserData);
  handle->handle   = calls.handle;
  handle->memory   = calls.memory;
  handle->context  = context;
  handle->gpu      = gpu;
  handle->reusable = calls.reusable;
  outCalls[0] = (Red2HandleCalls)(void *)handle;
}

void red2CreateCallsReusable(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, Red2HandleCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
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
  RedCalls calls = {};
  redCreateCallsReusable(context, gpu, handleName, queueFamilyIndex, &calls, outStatuses, optionalFile, optionalLine, optionalUserData);
  handle->handle   = calls.handle;
  handle->memory   = calls.memory;
  handle->context  = context;
  handle->gpu      = gpu;
  handle->reusable = calls.reusable;
  outCalls[0] = (Red2HandleCalls)(void *)handle;
}

typedef struct Red2InternalTransientGpuSignalsPresentImageIndexData {
  uint64_t                        gpuSignalsCurrentFreeIndex;
  std::vector<RedHandleGpuSignal> gpuSignals;
} Red2InternalTransientGpuSignalsPresentImageIndexData;

typedef struct Red2InternalTransientGpuSignalsPresentData {
  RedContext   context;
  RedHandleGpu gpu;
  std::map<unsigned, Red2InternalTransientGpuSignalsPresentImageIndexData> map;
} Red2InternalTransientGpuSignalsPresentData;

static std::mutex                                                             __REDGPU_2_GLOBAL_6c1b3b6a_transientGpuSignalsDataMutex;
static std::map<RedHandlePresent, Red2InternalTransientGpuSignalsPresentData> __REDGPU_2_GLOBAL_6c1b3b6a_transientGpuSignalsData;

void red2CreateWsiTransientGpuSignal(RedContext context, RedHandleGpu gpu, RedHandlePresent present, unsigned presentImageIndex, RedHandleGpuSignal * outGpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedHandleGpuSignal gpuSignal = NULL;
  {
    std::lock_guard<std::mutex> __transientGpuSignalsDataMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_transientGpuSignalsDataMutex);

    // NOTE(Constantine): These lines initialize the [present] map element if it doesn't exist in the map.
    __REDGPU_2_GLOBAL_6c1b3b6a_transientGpuSignalsData[present].context = context;
    __REDGPU_2_GLOBAL_6c1b3b6a_transientGpuSignalsData[present].gpu     = gpu;

    // NOTE(Constantine): This line initializes the [presentImageIndex] map element if it doesn't exist in the map.
    uint64_t index = __REDGPU_2_GLOBAL_6c1b3b6a_transientGpuSignalsData[present].map[presentImageIndex].gpuSignalsCurrentFreeIndex;

    // NOTE(Constantine): Caching the pointer to the [presentImageIndex] map element.
    Red2InternalTransientGpuSignalsPresentImageIndexData * data = &__REDGPU_2_GLOBAL_6c1b3b6a_transientGpuSignalsData[present].map[presentImageIndex];

    if (data->gpuSignals.size() < (index + 1)) {
      RedHandleGpuSignal handle = NULL;
      redCreateGpuSignal(context, gpu, NULL, &handle, outStatuses, optionalFile, optionalLine, optionalUserData);
      data->gpuSignals.push_back(handle);
    }

    gpuSignal = data->gpuSignals[index];

    data->gpuSignalsCurrentFreeIndex += 1;
  }
  outGpuSignal[0] = gpuSignal;
}

void red2DestroyStructDeclaration(RedContext context, RedHandleGpu gpu, Red2HandleStructDeclaration structDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeStructDeclaration * handle = (Red2InternalTypeStructDeclaration *)(void *)structDeclaration;
  if (handle != NULL) {
    redDestroyStructDeclaration(context, gpu, handle->handle, optionalFile, optionalLine, optionalUserData);
    delete[] handle->structDeclarationMembers;
    delete handle;
  }
}

void red2DestroyProcedureParameters(RedContext context, RedHandleGpu gpu, Red2HandleProcedureParameters procedureParameters, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeProcedureParameters * handle = (Red2InternalTypeProcedureParameters *)(void *)procedureParameters;
  if (handle != NULL) {
    redDestroyProcedureParameters(context, gpu, handle->handle, optionalFile, optionalLine, optionalUserData);
    delete handle;
  }
}

void red2DestroyCalls(RedContext context, RedHandleGpu gpu, Red2HandleCalls calls, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  if (handle != NULL) {
    for (size_t i = 0, count = handle->structsMemorys.size(); i < count; i += 1) {
      redStructsMemoryFree(context, gpu, handle->structsMemorys[i].handle, optionalFile, optionalLine, optionalUserData);
    }
    for (size_t i = 0, count = handle->structsMemorysSamplers.size(); i < count; i += 1) {
      redStructsMemoryFree(context, gpu, handle->structsMemorysSamplers[i].handle, optionalFile, optionalLine, optionalUserData);
    }
    redDestroyCalls(context, gpu, handle->handle, handle->memory, optionalFile, optionalLine, optionalUserData);
    delete handle;
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

void red2StructDeclarationGetMembersCounts(Red2HandleStructDeclaration structDeclaration, unsigned * outStructDeclarationMembersCount, unsigned * outMembersOfTypeArrayROConstantCount, unsigned * outMembersOfTypeArrayROOrArrayRWCount, unsigned * outMembersOfTypeTextureROCount, unsigned * outMembersOfTypeTextureRWCount, unsigned * outMembersOfTypeInlineSamplerCount, unsigned * outMembersOfTypeSamplerCount) {
  Red2InternalTypeStructDeclaration * handle = (Red2InternalTypeStructDeclaration *)(void *)structDeclaration;
  if (outStructDeclarationMembersCount      != NULL) { outStructDeclarationMembersCount[0]      = handle->structDeclarationMembersCount;      }
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

void red2CallsGetRedHandles(Red2HandleCalls calls, RedContext * outContext, RedHandleGpu * outGpu, RedCalls * outCalls) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  if (outContext != 0) { outContext[0] = handle->context; }
  if (outGpu     != 0) { outGpu[0]     = handle->gpu;     }
  if (outCalls   != 0) {
    outCalls->handle   = handle->handle;
    outCalls->memory   = handle->memory;
    outCalls->reusable = handle->reusable;
  }
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
  if (requestedStructsMemory == 1 && requestedStructsAllocationsCanFitInTheCurrentStructsMemory == 0) {
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
  if (requestedStructsMemorySamplers == 1 && requestedStructsAllocationsCanFitInTheCurrentStructsMemorySamplers == 0) {
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

  int64_t structsMemoryDescriptorsOffsetStartSigned = (int64_t)memory.availableDescriptors - (int64_t)structDeclarationDescriptorsCount;
  if (structsMemoryDescriptorsOffsetStartSigned < 0) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_MEMORY_OVERFLOW;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = RED_PROCEDURE_ID_UNDEFINED;
        outStatuses->statusErrorFile           = optionalFile;
        outStatuses->statusErrorLine           = optionalLine;
        outStatuses->statusErrorDescription[0] = 0;
      }
    }
    return RED_STATUS_ERROR_MEMORY_OVERFLOW;
  }
  unsigned structsMemoryDescriptorsOffsetStart = (unsigned)structsMemoryDescriptorsOffsetStartSigned;

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
        isStructOfTypeSamplers, // copyingSamplers
        1,                      // sourceCopiesCount
        &rAddress,              // sourceCopiesAddressFirst
        oneCopy,                // sourceCopiesAddressCount
        1,                      // targetCopiesCount
        &wAddress,              // targetCopiesAddressFirst
        oneCopy,                // targetCopiesAddressCount
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
    return RED_STATUS_ERROR_MEMORY_OVERFLOW;
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

  return RED_STATUS_SUCCESS;
}

typedef struct Red2InternalSelfDestroyableHandlesBatch {
  RedContext            context;
  RedHandleGpu          gpu;
  RedHandleCpuSignal    cpuSignal;
  std::vector<void *>   whenQueueSubmissionIsFinishedDestroyHandles;
  std::vector<unsigned> whenQueueSubmissionIsFinishedDestroyHandlesHandleType;
} Red2InternalSelfDestroyableHandlesBatch;

static std::mutex                                           __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesMutex;
static std::vector<Red2InternalSelfDestroyableHandlesBatch> __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches;
static std::vector<uint64_t>                                __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket;            // NOTE(Constantine): Ticket == 0 means the array slot is free to use for other greater tickets.
static uint64_t                                             __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesCurrentTicket = 0;

static void red2InternalSelfDestroyableHandlesBatchesFreeFinishedBatch_NonLocking(RedContext context, RedHandleGpu gpu, uint64_t index, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedHandleCpuSignal cpuSignal = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[index].cpuSignal;
  RedStatus status = RED_STATUS_SUCCESS;
  redCpuSignalGetStatus(context, gpu, cpuSignal, &status, optionalFile, optionalLine, optionalUserData);
  if (status == RED_STATUS_SUCCESS) {
    redDestroyCpuSignal(context, gpu, cpuSignal, optionalFile, optionalLine, optionalUserData);
    for (size_t i = 0, count = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[index].whenQueueSubmissionIsFinishedDestroyHandles.size(); i < count; i += 1) {
      void *   handle     = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[index].whenQueueSubmissionIsFinishedDestroyHandles[i];
      unsigned handleType = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[index].whenQueueSubmissionIsFinishedDestroyHandlesHandleType[i];
      if      (handleType == 0)                                     { continue; }
      else if (handleType == RED_HANDLE_TYPE_MEMORY)                { redMemoryFree(context, gpu, (RedHandleMemory)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_ARRAY)                 { redDestroyArray(context, gpu, (RedHandleArray)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_IMAGE)                 { redDestroyImage(context, gpu, (RedHandleImage)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_SAMPLER)               { redDestroySampler(context, gpu, (RedHandleSampler)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_TEXTURE)               { redDestroyTexture(context, gpu, (RedHandleTexture)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_GPU_CODE)              { redDestroyGpuCode(context, gpu, (RedHandleGpuCode)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_OUTPUT_DECLARATION)    { redDestroyOutputDeclaration(context, gpu, (RedHandleOutputDeclaration)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_STRUCT_DECLARATION)    { redDestroyStructDeclaration(context, gpu, (RedHandleStructDeclaration)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_PROCEDURE_PARAMETERS)  { redDestroyProcedureParameters(context, gpu, (RedHandleProcedureParameters)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_PROCEDURE_CACHE)       { redDestroyProcedureCache(context, gpu, (RedHandleProcedureCache)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_PROCEDURE)             { redDestroyProcedure(context, gpu, (RedHandleProcedure)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_OUTPUT)                { redDestroyOutput(context, gpu, (RedHandleOutput)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_STRUCTS_MEMORY)        { redStructsMemoryFree(context, gpu, (RedHandleStructsMemory)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_CPU_SIGNAL)            { redDestroyCpuSignal(context, gpu, (RedHandleCpuSignal)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_GPU_SIGNAL)            { redDestroyGpuSignal(context, gpu, (RedHandleGpuSignal)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_GPU_TO_CPU_SIGNAL)     { redDestroyGpuToCpuSignal(context, gpu, (RedHandleGpuToCpuSignal)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_SURFACE)               { redDestroySurface(context, gpu, (RedHandleSurface)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED_HANDLE_TYPE_PRESENT)               { redDestroyPresent(context, gpu, (RedHandlePresent)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED2_HANDLE_TYPE_STRUCT_DECLARATION)   { red2DestroyStructDeclaration(context, gpu, (Red2HandleStructDeclaration)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED2_HANDLE_TYPE_PROCEDURE_PARAMETERS) { red2DestroyProcedureParameters(context, gpu, (Red2HandleProcedureParameters)handle, optionalFile, optionalLine, optionalUserData); }
      else if (handleType == RED2_HANDLE_TYPE_CALLS)                { red2DestroyCalls(context, gpu, (Red2HandleCalls)handle, optionalFile, optionalLine, optionalUserData); }
      else {
        redMark("[REDGPU 2][TODO(Constantine)] The handle is not destroyed, need to implement destruction of the handle type here, in this part of REDGPU 2 code.", optionalFile, optionalLine, optionalUserData);
      }
    }
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[index] = 0;
  }
}

static void red2InternalSelfDestroyableHandlesBatchesFreeFinishedBatches_NonLocking(RedContext context, RedHandleGpu gpu, RedBool32 waitForAllAndFreeAllBatches, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  for (size_t i = 0, count = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches.size(); i < count; i += 1) {
    if (__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[i] != 0) {
      if (__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].context == context &&
          __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].gpu     == gpu)
      {
        if (waitForAllAndFreeAllBatches == 1) {
          RedHandleCpuSignal cpuSignal = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].cpuSignal;
          redCpuSignalWait(context, gpu, 1, &cpuSignal, 1, outStatuses, optionalFile, optionalLine, optionalUserData);
        }
        red2InternalSelfDestroyableHandlesBatchesFreeFinishedBatch_NonLocking(context, gpu, i, optionalFile, optionalLine, optionalUserData);
      }
    }
  }
}

static size_t red2InternalSelfDestroyableHandlesBatchesGetFreeElementIndex_NonLocking() {
  size_t index = -1;
  for (size_t i = 0, count = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket.size(); i < count; i += 1) {
    if (__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[i] == 0) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    Red2InternalSelfDestroyableHandlesBatch emptyElement = {};
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches.push_back(emptyElement);
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket.push_back(0);
    index = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches.size() - 1;
  }
  return index;
}

void red2DestroyContext(RedContext context, const char * optionalFile, int optionalLine, void * optionalUserData) {
  {
    std::lock_guard<std::mutex> __selfDestroyableHandlesBatchesMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesMutex);
    for (unsigned gpuIndex = 0; gpuIndex < context->gpusCount; gpuIndex += 1) {
      red2InternalSelfDestroyableHandlesBatchesFreeFinishedBatches_NonLocking(context, context->gpus[gpuIndex].gpu, 1, NULL, optionalFile, optionalLine, optionalUserData);
    }
  }
  {
    std::lock_guard<std::mutex> __transientGpuSignalsDataMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_transientGpuSignalsDataMutex);
    for (auto & [key, value] : __REDGPU_2_GLOBAL_6c1b3b6a_transientGpuSignalsData) { // NOTE(Constantine): This style of loop requires C++17.
      if (value.context == context) {
        RedHandleGpu gpu = value.gpu;
        for (const auto & [dataKey, data] : value.map) {
          for (const auto & gpuSignal : data.gpuSignals) {
            redDestroyGpuSignal(context, gpu, gpuSignal, optionalFile, optionalLine, optionalUserData);
          }
        }
        value = {};
      }
    }
  }
  redDestroyContext(context, optionalFile, optionalLine, optionalUserData);
}

void red2PresentGetImageIndex(RedContext context, RedHandleGpu gpu, RedHandlePresent present, RedHandleCpuSignal signalCpuSignal, RedHandleGpuSignal signalGpuSignal, unsigned * outImageIndex, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  redPresentGetImageIndex(context, gpu, present, signalCpuSignal, signalGpuSignal, outImageIndex, outStatuses, optionalFile, optionalLine, optionalUserData);
  // NOTE(Constantine): Assuming redPresentGetImageIndex blocks CPU here until a new image index is returned to outImageIndex.
  {
    std::lock_guard<std::mutex> __transientGpuSignalsDataMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_transientGpuSignalsDataMutex);
    __REDGPU_2_GLOBAL_6c1b3b6a_transientGpuSignalsData[present].map[outImageIndex[0]].gpuSignalsCurrentFreeIndex = 0;
  }
}

void red2QueueSubmit(RedContext context, RedHandleGpu gpu, RedHandleQueue queue, unsigned timelinesCount, const RedGpuTimeline * timelines, uint64_t * outQueueSubmissionTicketArrayIndex, uint64_t * outQueueSubmissionTicket, uint64_t whenQueueSubmissionIsFinishedDestroyHandlesCount, void ** whenQueueSubmissionIsFinishedDestroyHandles, unsigned * whenQueueSubmissionIsFinishedDestroyHandlesHandleType, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  {
    std::lock_guard<std::mutex> __selfDestroyableHandlesBatchesMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesMutex);
    red2InternalSelfDestroyableHandlesBatchesFreeFinishedBatches_NonLocking(context, gpu, 0, outStatuses, optionalFile, optionalLine, optionalUserData);
  }
  RedHandleCpuSignal cpuSignal = NULL;
  redCreateCpuSignal(context, gpu, NULL, 0, &cpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
  redQueueSubmit(context, gpu, queue, timelinesCount, timelines, cpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
  if (cpuSignal != NULL) {
    std::lock_guard<std::mutex> __selfDestroyableHandlesBatchesMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesMutex);
    size_t i = red2InternalSelfDestroyableHandlesBatchesGetFreeElementIndex_NonLocking();
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].context                                               = context;
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].gpu                                                   = gpu;
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].cpuSignal                                             = cpuSignal;
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].whenQueueSubmissionIsFinishedDestroyHandles           = std::vector<void *>(whenQueueSubmissionIsFinishedDestroyHandles, whenQueueSubmissionIsFinishedDestroyHandles + whenQueueSubmissionIsFinishedDestroyHandlesCount);
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].whenQueueSubmissionIsFinishedDestroyHandlesHandleType = std::vector<unsigned>(whenQueueSubmissionIsFinishedDestroyHandlesHandleType, whenQueueSubmissionIsFinishedDestroyHandlesHandleType + whenQueueSubmissionIsFinishedDestroyHandlesCount);
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesCurrentTicket += 1; // NOTE(Constantine): Assuming u64 will not overflow during the lifetime of a program.
    __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[i]                       = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesCurrentTicket;
    if (outQueueSubmissionTicketArrayIndex != NULL) { outQueueSubmissionTicketArrayIndex[0] = i; }
    if (outQueueSubmissionTicket           != NULL) { outQueueSubmissionTicket[0]           = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesCurrentTicket; }
  }
}

RedBool32 red2IsQueueSubmissionFinished(uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket, const char * optionalFile, int optionalLine, void * optionalUserData) {
  uint64_t ticket = 0;
  {
    std::lock_guard<std::mutex> __selfDestroyableHandlesBatchesMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesMutex);
    RedContext   context = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[queueSubmissionTicketArrayIndex].context;
    RedHandleGpu gpu     = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[queueSubmissionTicketArrayIndex].gpu;
    red2InternalSelfDestroyableHandlesBatchesFreeFinishedBatch_NonLocking(context, gpu, queueSubmissionTicketArrayIndex, optionalFile, optionalLine, optionalUserData);
    ticket = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[queueSubmissionTicketArrayIndex];
  }
  return ticket == queueSubmissionTicket ? 0 : 1; // NOTE(Constantine): Alternatively, (ticket == 0 || ticket > queueSubmissionTicket) ? 1 : 0.
}

RedBool32 red2IsQueueSubmissionFinishedByTicketAlone(uint64_t queueSubmissionTicket, const char * optionalFile, int optionalLine, void * optionalUserData) {
  uint64_t ticket = 0;
  {
    std::lock_guard<std::mutex> __selfDestroyableHandlesBatchesMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesMutex);
    for (size_t i = 0, count = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches.size(); i < count; i += 1) {
      if (__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[i] == queueSubmissionTicket) {
        RedContext   context = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].context;
        RedHandleGpu gpu     = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].gpu;
        red2InternalSelfDestroyableHandlesBatchesFreeFinishedBatch_NonLocking(context, gpu, i, optionalFile, optionalLine, optionalUserData);
        ticket = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[i];
        break;
      }
    }
  }
  return ticket == queueSubmissionTicket ? 0 : 1; // NOTE(Constantine): Alternatively, (ticket == 0 || ticket > queueSubmissionTicket) ? 1 : 0.
}

RedBool32 red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket(RedContext context, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedBool32 allQueueSubmissionsAreFinished = 1;
  {
    std::lock_guard<std::mutex> __selfDestroyableHandlesBatchesMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesMutex);
    for (size_t i = 0, count = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches.size(); i < count; i += 1) {
      uint64_t t = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[i];
      if (t != 0 && t <= queueSubmissionTicket) {
        if (__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].context == context &&
            __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].gpu     == gpu)
        {
          red2InternalSelfDestroyableHandlesBatchesFreeFinishedBatch_NonLocking(context, gpu, i, optionalFile, optionalLine, optionalUserData);
          uint64_t ticket = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[i];
          if (ticket != 0 && ticket <= queueSubmissionTicket) {
            allQueueSubmissionsAreFinished = 0;
            break;
          }
        }
      }
    }
  }
  return allQueueSubmissionsAreFinished;
}

void red2WaitForQueueSubmissionToFinish(uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  std::lock_guard<std::mutex> __selfDestroyableHandlesBatchesMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesMutex);
  uint64_t ticket = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[queueSubmissionTicketArrayIndex];
  if (ticket == queueSubmissionTicket) {
    RedContext         context   = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[queueSubmissionTicketArrayIndex].context;
    RedHandleGpu       gpu       = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[queueSubmissionTicketArrayIndex].gpu;
    RedHandleCpuSignal cpuSignal = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[queueSubmissionTicketArrayIndex].cpuSignal;
    redCpuSignalWait(context, gpu, 1, &cpuSignal, 1, outStatuses, optionalFile, optionalLine, optionalUserData);
    red2InternalSelfDestroyableHandlesBatchesFreeFinishedBatch_NonLocking(context, gpu, queueSubmissionTicketArrayIndex, optionalFile, optionalLine, optionalUserData);
  }
}

void red2WaitForQueueSubmissionToFinishByTicketAlone(uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  std::lock_guard<std::mutex> __selfDestroyableHandlesBatchesMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesMutex);
  for (size_t i = 0, count = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches.size(); i < count; i += 1) {
    uint64_t ticket = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[i];
    if (ticket == queueSubmissionTicket) {
      RedContext         context   = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].context;
      RedHandleGpu       gpu       = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].gpu;
      RedHandleCpuSignal cpuSignal = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].cpuSignal;
      redCpuSignalWait(context, gpu, 1, &cpuSignal, 1, outStatuses, optionalFile, optionalLine, optionalUserData);
      red2InternalSelfDestroyableHandlesBatchesFreeFinishedBatch_NonLocking(context, gpu, i, optionalFile, optionalLine, optionalUserData);
      break;
    }
  }
}

void red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket(RedContext context, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  std::lock_guard<std::mutex> __selfDestroyableHandlesBatchesMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesMutex);
  for (size_t i = 0, count = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches.size(); i < count; i += 1) {
    uint64_t ticket = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[i];
    if (ticket != 0) {
      if (__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].context == context &&
          __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].gpu     == gpu)
      {
        if (ticket <= queueSubmissionTicket) {
          RedHandleCpuSignal cpuSignal = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].cpuSignal;
          redCpuSignalWait(context, gpu, 1, &cpuSignal, 1, outStatuses, optionalFile, optionalLine, optionalUserData);
          red2InternalSelfDestroyableHandlesBatchesFreeFinishedBatch_NonLocking(context, gpu, i, optionalFile, optionalLine, optionalUserData);
        }
      }
    }
  }
}

void red2WaitForAllQueueSubmissionsToFinish(RedContext context, RedHandleGpu gpu, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  std::lock_guard<std::mutex> __selfDestroyableHandlesBatchesMutexLockGuard(__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesMutex);
  for (size_t i = 0, count = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches.size(); i < count; i += 1) {
    uint64_t ticket = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatchesTicket[i];
    if (ticket != 0) {
      if (__REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].context == context &&
          __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].gpu     == gpu)
      {
        RedHandleCpuSignal cpuSignal = __REDGPU_2_GLOBAL_6c1b3b6a_selfDestroyableHandlesBatches[i].cpuSignal;
        redCpuSignalWait(context, gpu, 1, &cpuSignal, 1, outStatuses, optionalFile, optionalLine, optionalUserData);
        red2InternalSelfDestroyableHandlesBatchesFreeFinishedBatch_NonLocking(context, gpu, i, optionalFile, optionalLine, optionalUserData);
      }
    }
  }
}
