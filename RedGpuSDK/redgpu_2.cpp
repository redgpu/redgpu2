// cl /LD /EHsc /std:c++17 redgpu_2.cpp C:/RedGpuSDK/redgpudll.lib
// cl /LD /EHsc /std:c++17 /DREDGPU_USE_REDGPU_X redgpu_2_x.cpp C:/RedGpuSDK/redgpu_x.lib

#if defined(_WIN32) && !defined(__GNUC__)
#define REDGPU_2_DECLSPEC __declspec(dllexport)
#else
#define REDGPU_2_DECLSPEC __attribute__((visibility("default")))
#endif

#include <string> // For redgpu_x_internal_types.h
#include <vector> // For redgpu_2_internal_types.h

#if defined(_WIN32)
#include "C:/RedGpuSDK/redgpu.h"
#include "C:/RedGpuSDK/redgpu_wsi.h"
#include "C:/RedGpuSDK/redgpu_x.h"
#include "C:/RedGpuSDK/redgpu_x12.h"
#include "C:/RedGpuSDK/redgpu_x_internal_types.h"
#else
#include "/opt/RedGpuSDK/redgpu.h"
#include "/opt/RedGpuSDK/redgpu_wsi.h"
#include "/opt/RedGpuSDK/redgpu_x.h"
#include "/opt/RedGpuSDK/redgpu_x12.h"
#include "/opt/RedGpuSDK/redgpu_x_internal_types.h"
#endif
#include "redgpu_2.h"
#include "redgpu_2_internal_types.h"

#include <string.h> // For memcpy
#include <mutex>    // For std::mutex
#include <new>      // For std::nothrow
#include <map>      // For std::map

typedef struct Red2InternalTransientGpuSignalsPresentImageIndexData {
  uint64_t                        gpuSignalsCurrentFreeIndex;
  std::vector<RedHandleGpuSignal> gpuSignals;
} Red2InternalTransientGpuSignalsPresentImageIndexData;

typedef struct Red2InternalTransientGpuSignalsPresentData {
  std::map<unsigned, Red2InternalTransientGpuSignalsPresentImageIndexData> map;
  unsigned char init;
} Red2InternalTransientGpuSignalsPresentData;

typedef struct Red2InternalHandlesToDestroyBatch {
  RedHandleCpuSignal    cpuSignal;
  uint64_t              cpuSignalIsWaitedOnCounter;                            // NOTE(Constantine): 26 Feb 2024, this counter is added to handle the case when other threads can wait on a CPU signal without locking the global mutex and be sure the CPU signal is not destroyed yet by other threads.
  void *                optionalCustomHandleAndHandleTypeDestroyCallback;
  std::vector<uint64_t> whenQueueSubmissionIsFinishedDestroyHandles;
  std::vector<unsigned> whenQueueSubmissionIsFinishedDestroyHandlesHandleType;
} Red2InternalHandlesToDestroyBatch;

typedef struct Red2GpuInternalData {
  std::mutex                                                             transientGpuSignalsDataMutex;
  std::map<RedHandlePresent, Red2InternalTransientGpuSignalsPresentData> transientGpuSignalsData;

  std::mutex                                     handlesToDestroyBatchesMutex;
  std::vector<Red2InternalHandlesToDestroyBatch> handlesToDestroyBatches;
  std::vector<uint64_t>                          handlesToDestroyBatchesTicket;        // NOTE(Constantine): Ticket == 0 means the array slot is free to use for other greater tickets.
  uint64_t                                       handlesToDestroyBatchesCurrentTicket; // NOTE(Constantine): Starts with 0.

  unsigned char init;
} Red2GpuInternalData;

typedef struct Red2ContextInternalData {
  std::map<RedHandleGpu, Red2GpuInternalData> gpus;
} Red2ContextInternalData;

void red2CreateContext(RedTypeProcedureMalloc malloc, RedTypeProcedureFree free, RedTypeProcedureMallocTagged optionalMallocTagged, RedTypeProcedureFreeTagged optionalFreeTagged, RedTypeProcedureDebugCallback debugCallback, RedSdkVersion sdkVersion, unsigned sdkExtensionsCount, const unsigned * sdkExtensions, const char * optionalProgramName, unsigned optionalProgramVersion, const char * optionalEngineName, unsigned optionalEngineVersion, const void * optionalSettings, Red2Context * outContext2, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2TypeContext * context2 = new(std::nothrow) Red2TypeContext();
  if (context2 == NULL) {
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
    outContext2[0] = NULL;
    return;
  }
  Red2ContextInternalData * context2Data = new(std::nothrow) Red2ContextInternalData();
  if (context2Data == NULL) {
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
    outContext2[0] = NULL;
    return;
  }
  redCreateContext(malloc, free, optionalMallocTagged, optionalFreeTagged, debugCallback, sdkVersion, sdkExtensionsCount, sdkExtensions, optionalProgramName, optionalProgramVersion, optionalEngineName, optionalEngineVersion, optionalSettings, &context2->context, outStatuses, optionalFile, optionalLine, optionalUserData);
  context2->redgpu2InternalData = context2Data;
  outContext2[0] = context2;
  for (unsigned i = 0; i < context2->context->gpusCount; i += 1) {
    RedHandleGpu gpu = context2->context->gpus[i].gpu;
    context2Data->gpus[gpu].init = 1;
  }
}

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

void red2CreateWsiTransientGpuSignal(Red2Context context2, RedHandleGpu gpu, RedHandlePresent present, unsigned presentImageIndex, RedHandleGpuSignal * outGpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  RedHandleGpuSignal gpuSignal = NULL;
  {
    std::lock_guard<std::mutex> __transientGpuSignalsDataMutexLockGuard(context2GpuData->transientGpuSignalsDataMutex);

    // NOTE(Constantine): This line initializes the [present] map element if it doesn't exist in the map.
    context2GpuData->transientGpuSignalsData[present].init = 1;

    // NOTE(Constantine): This line initializes the [presentImageIndex] map element if it doesn't exist in the map.
    uint64_t index = context2GpuData->transientGpuSignalsData[present].map[presentImageIndex].gpuSignalsCurrentFreeIndex;

    // NOTE(Constantine): Caching the pointer to the [presentImageIndex] map element.
    Red2InternalTransientGpuSignalsPresentImageIndexData * data = &context2GpuData->transientGpuSignalsData[present].map[presentImageIndex];

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
  redCallsSet(context, gpu, handle->handle, handle->memory, handle->reusable, outStatuses, optionalFile, optionalLine, optionalUserData);
}

void red2CallsEnd(
  RedContext context,
  RedHandleGpu gpu,
  Red2HandleCalls calls,
  RedStatuses * outStatuses,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
)
{
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  redCallsEnd(context, gpu, handle->handle, handle->memory, outStatuses, optionalFile, optionalLine, optionalUserData);
}

void red2CallsFreeAllInlineStructsMemorys(
  Red2HandleCalls calls,
  const char * optionalFile,
  int optionalLine,
  void * optionalUserData
)
{
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  for (size_t i = 0, count = handle->structsMemorys.size(); i < count; i += 1) {
    redStructsMemoryFree(handle->context, handle->gpu, handle->structsMemorys[i].handle, optionalFile, optionalLine, optionalUserData);
  }
  for (size_t i = 0, count = handle->structsMemorysSamplers.size(); i < count; i += 1) {
    redStructsMemoryFree(handle->context, handle->gpu, handle->structsMemorysSamplers[i].handle, optionalFile, optionalLine, optionalUserData);
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

static void red2InternalHandlesToDestroyBatchesFreeFinishedBatch_NonLocking(Red2Context context2, RedHandleGpu gpu, uint64_t index, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  RedHandleCpuSignal cpuSignal                  = context2GpuData->handlesToDestroyBatches[index].cpuSignal;
  uint64_t           cpuSignalIsWaitedOnCounter = context2GpuData->handlesToDestroyBatches[index].cpuSignalIsWaitedOnCounter;
  RedStatus status = RED_STATUS_SUCCESS;
  redCpuSignalGetStatus(context, gpu, cpuSignal, &status, optionalFile, optionalLine, optionalUserData);
  if (status == RED_STATUS_SUCCESS && cpuSignalIsWaitedOnCounter == 0) {
    redDestroyCpuSignal(context, gpu, cpuSignal, optionalFile, optionalLine, optionalUserData);
    void * optionalCustomHandleAndHandleTypeDestroyCallback = context2GpuData->handlesToDestroyBatches[index].optionalCustomHandleAndHandleTypeDestroyCallback;
    for (size_t i = 0, count = context2GpuData->handlesToDestroyBatches[index].whenQueueSubmissionIsFinishedDestroyHandles.size(); i < count; i += 1) {
      uint64_t handle     = context2GpuData->handlesToDestroyBatches[index].whenQueueSubmissionIsFinishedDestroyHandles[i];
      unsigned handleType = context2GpuData->handlesToDestroyBatches[index].whenQueueSubmissionIsFinishedDestroyHandlesHandleType[i];
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
      else if (optionalCustomHandleAndHandleTypeDestroyCallback != NULL) {
        void (*customHandleAndHandleTypeDestroyCallback)(uint64_t handle, unsigned handleType) = (void (*)(uint64_t, unsigned handleType))optionalCustomHandleAndHandleTypeDestroyCallback;
        customHandleAndHandleTypeDestroyCallback(handle, handleType);
      } else {
        redMark("[REDGPU 2][TODO(Constantine)] The handle is not destroyed, need to implement destruction of the handle type here, in this part of REDGPU 2 code.", optionalFile, optionalLine, optionalUserData);
      }
    }
    context2GpuData->handlesToDestroyBatchesTicket[index] = 0;
  }
}

static void red2InternalHandlesToDestroyBatchesFreeFinishedBatches_NonLocking(Red2Context context2, RedHandleGpu gpu, RedBool32 waitForAllAndFreeAllBatches, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  for (size_t i = 0, count = context2GpuData->handlesToDestroyBatches.size(); i < count; i += 1) {
    if (context2GpuData->handlesToDestroyBatchesTicket[i] != 0) {
      if (waitForAllAndFreeAllBatches == 1) {
        RedHandleCpuSignal cpuSignal = context2GpuData->handlesToDestroyBatches[i].cpuSignal;
        redCpuSignalWait(context, gpu, 1, &cpuSignal, 1, outStatuses, optionalFile, optionalLine, optionalUserData);
        context2GpuData->handlesToDestroyBatches[i].cpuSignalIsWaitedOnCounter = 0; // NOTE(Constantine): Force setting the counter to 0 since it is the job of the user to make sure all threads are finished using the context's handles before calling the red2DestroyContext procedure. waitForAllAndFreeAllBatches == 1 is true only for red2DestroyContext procedure.
      }
      red2InternalHandlesToDestroyBatchesFreeFinishedBatch_NonLocking(context2, gpu, i, optionalFile, optionalLine, optionalUserData);
    }
  }
}

static size_t red2InternalHandlesToDestroyBatchesGetFreeElementIndex_NonLocking(Red2Context context2, RedHandleGpu gpu) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  size_t index = -1;
  for (size_t i = 0, count = context2GpuData->handlesToDestroyBatchesTicket.size(); i < count; i += 1) {
    if (context2GpuData->handlesToDestroyBatchesTicket[i] == 0) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    Red2InternalHandlesToDestroyBatch emptyElement = {};
    context2GpuData->handlesToDestroyBatches.push_back(emptyElement);
    context2GpuData->handlesToDestroyBatchesTicket.push_back(0);
    index = context2GpuData->handlesToDestroyBatches.size() - 1;
  }
  return index;
}

void red2DestroyContext(Red2Context context2, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;

  for (auto & [gpuHandle, context2GpuData] : context2Data->gpus) { // NOTE(Constantine): This style of loop requires C++17.
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData.handlesToDestroyBatchesMutex);
    for (unsigned gpuIndex = 0; gpuIndex < context->gpusCount; gpuIndex += 1) {
      red2InternalHandlesToDestroyBatchesFreeFinishedBatches_NonLocking(context2, context->gpus[gpuIndex].gpu, 1, NULL, optionalFile, optionalLine, optionalUserData);
    }
  }
  for (auto & [gpuHandle, context2GpuData] : context2Data->gpus) { // NOTE(Constantine): This style of loop requires C++17.
    std::lock_guard<std::mutex> __transientGpuSignalsDataMutexLockGuard(context2GpuData.transientGpuSignalsDataMutex);
    for (auto & [presentHandle, presentData] : context2GpuData.transientGpuSignalsData) { // NOTE(Constantine): This style of loop requires C++17.
      for (const auto & [dataKey, data] : presentData.map) {
        for (const auto & gpuSignal : data.gpuSignals) {
          redDestroyGpuSignal(context, gpuHandle, gpuSignal, optionalFile, optionalLine, optionalUserData);
        }
      }
      presentData = {};
    }
  }
  redDestroyContext(context, optionalFile, optionalLine, optionalUserData);
  {
    Red2ContextInternalData * context2Data = (Red2ContextInternalData *)context2->redgpu2InternalData;
    delete context2Data;
    delete context2;
  }
}

void red2PresentGetImageIndex(Red2Context context2, RedHandleGpu gpu, RedHandlePresent present, RedHandleCpuSignal signalCpuSignal, RedHandleGpuSignal signalGpuSignal, unsigned * outImageIndex, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  redPresentGetImageIndex(context, gpu, present, signalCpuSignal, signalGpuSignal, outImageIndex, outStatuses, optionalFile, optionalLine, optionalUserData);
  // NOTE(Constantine): Assuming redPresentGetImageIndex blocks CPU here until a new image index is returned to outImageIndex.
  {
    std::lock_guard<std::mutex> __transientGpuSignalsDataMutexLockGuard(context2GpuData->transientGpuSignalsDataMutex);
    context2GpuData->transientGpuSignalsData[present].map[outImageIndex[0]].gpuSignalsCurrentFreeIndex = 0;
  }
}

void red2QueueSubmit(Red2Context context2, RedHandleGpu gpu, RedHandleQueue queue, unsigned timelinesCount, const RedGpuTimeline * timelines, uint64_t * outQueueSubmissionTicketArrayIndex, uint64_t * outQueueSubmissionTicket, uint64_t whenQueueSubmissionIsFinishedDestroyHandlesCount, const uint64_t * whenQueueSubmissionIsFinishedDestroyHandles, const unsigned * whenQueueSubmissionIsFinishedDestroyHandlesHandleType, void * optionalCustomHandleAndHandleTypeDestroyCallback, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    red2InternalHandlesToDestroyBatchesFreeFinishedBatches_NonLocking(context2, gpu, 0, outStatuses, optionalFile, optionalLine, optionalUserData);
  }
  RedHandleCpuSignal cpuSignal = NULL;
  redCreateCpuSignal(context, gpu, NULL, 0, &cpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData); // NOTE(Constantine): Intentionally creating one CPU signal per queue submit, even if the user didn't request a ticket for that queue submit.
  redQueueSubmit(context, gpu, queue, timelinesCount, timelines, cpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
  if (cpuSignal != NULL) {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    size_t i = red2InternalHandlesToDestroyBatchesGetFreeElementIndex_NonLocking(context2, gpu);
    context2GpuData->handlesToDestroyBatches[i].cpuSignal                                             = cpuSignal;
    context2GpuData->handlesToDestroyBatches[i].optionalCustomHandleAndHandleTypeDestroyCallback      = optionalCustomHandleAndHandleTypeDestroyCallback;
    context2GpuData->handlesToDestroyBatches[i].whenQueueSubmissionIsFinishedDestroyHandles           = std::vector<uint64_t>(whenQueueSubmissionIsFinishedDestroyHandles, whenQueueSubmissionIsFinishedDestroyHandles + whenQueueSubmissionIsFinishedDestroyHandlesCount);
    context2GpuData->handlesToDestroyBatches[i].whenQueueSubmissionIsFinishedDestroyHandlesHandleType = std::vector<unsigned>(whenQueueSubmissionIsFinishedDestroyHandlesHandleType, whenQueueSubmissionIsFinishedDestroyHandlesHandleType + whenQueueSubmissionIsFinishedDestroyHandlesCount);
    context2GpuData->handlesToDestroyBatchesCurrentTicket += 1; // NOTE(Constantine): Assuming u64 will not overflow during the lifetime of a program.
    context2GpuData->handlesToDestroyBatchesTicket[i]      = context2GpuData->handlesToDestroyBatchesCurrentTicket;
    if (outQueueSubmissionTicketArrayIndex != NULL) { outQueueSubmissionTicketArrayIndex[0] = i; }
    if (outQueueSubmissionTicket           != NULL) { outQueueSubmissionTicket[0]           = context2GpuData->handlesToDestroyBatchesCurrentTicket; }
  }
}

RedBool32 red2IsQueueSubmissionFinished(Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  if (queueSubmissionTicket == 0) {
    return 1;
  }
  uint64_t ticket = 0;
  {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    if (context2GpuData->handlesToDestroyBatchesTicket[queueSubmissionTicketArrayIndex] == queueSubmissionTicket) {
      red2InternalHandlesToDestroyBatchesFreeFinishedBatch_NonLocking(context2, gpu, queueSubmissionTicketArrayIndex, optionalFile, optionalLine, optionalUserData);
      ticket = context2GpuData->handlesToDestroyBatchesTicket[queueSubmissionTicketArrayIndex];
    }
  }
  return ticket == queueSubmissionTicket ? 0 : 1; // NOTE(Constantine): Alternatively, (ticket == 0 || ticket > queueSubmissionTicket) ? 1 : 0.
}

RedBool32 red2IsQueueSubmissionFinishedByTicketAlone(Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  if (queueSubmissionTicket == 0) {
    return 1;
  }
  uint64_t ticket = 0;
  {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    for (size_t i = 0, count = context2GpuData->handlesToDestroyBatches.size(); i < count; i += 1) {
      if (context2GpuData->handlesToDestroyBatchesTicket[i] == queueSubmissionTicket) {
        red2InternalHandlesToDestroyBatchesFreeFinishedBatch_NonLocking(context2, gpu, i, optionalFile, optionalLine, optionalUserData);
        ticket = context2GpuData->handlesToDestroyBatchesTicket[i];
        break;
      }
    }
  }
  return ticket == queueSubmissionTicket ? 0 : 1; // NOTE(Constantine): Alternatively, (ticket == 0 || ticket > queueSubmissionTicket) ? 1 : 0.
}

RedBool32 red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket(Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  RedBool32 allQueueSubmissionsAreFinished = 1;
  {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    for (size_t i = 0, count = context2GpuData->handlesToDestroyBatches.size(); i < count; i += 1) {
      uint64_t t = context2GpuData->handlesToDestroyBatchesTicket[i];
      if (t != 0 && t <= queueSubmissionTicket) {
        red2InternalHandlesToDestroyBatchesFreeFinishedBatch_NonLocking(context2, gpu, i, optionalFile, optionalLine, optionalUserData);
        uint64_t ticket = context2GpuData->handlesToDestroyBatchesTicket[i];
        if (ticket != 0 && ticket <= queueSubmissionTicket) {
          allQueueSubmissionsAreFinished = 0;
          break;
        }
      }
    }
  }
  return allQueueSubmissionsAreFinished;
}

void red2WaitForQueueSubmissionToFinish(Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  if (queueSubmissionTicket == 0) {
    return;
  }
  RedHandleCpuSignal cpuSignal = NULL;
  {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    uint64_t ticket = context2GpuData->handlesToDestroyBatchesTicket[queueSubmissionTicketArrayIndex];
    if (ticket == queueSubmissionTicket) {
      cpuSignal = context2GpuData->handlesToDestroyBatches[queueSubmissionTicketArrayIndex].cpuSignal;
      context2GpuData->handlesToDestroyBatches[queueSubmissionTicketArrayIndex].cpuSignalIsWaitedOnCounter += 1;
    }
  }
  if (cpuSignal != NULL) {
    redCpuSignalWait(context, gpu, 1, &cpuSignal, 1, outStatuses, optionalFile, optionalLine, optionalUserData);
  }
  if (cpuSignal != NULL) {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    context2GpuData->handlesToDestroyBatches[queueSubmissionTicketArrayIndex].cpuSignalIsWaitedOnCounter -= 1;
    red2InternalHandlesToDestroyBatchesFreeFinishedBatch_NonLocking(context2, gpu, queueSubmissionTicketArrayIndex, optionalFile, optionalLine, optionalUserData);
  }
}

void red2WaitForQueueSubmissionToFinishByTicketAlone(Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  if (queueSubmissionTicket == 0) {
    return;
  }
  uint64_t           queueSubmissionTicketArrayIndex = 0;
  RedHandleCpuSignal cpuSignal = NULL;
  {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    for (size_t i = 0, count = context2GpuData->handlesToDestroyBatches.size(); i < count; i += 1) {
      uint64_t ticket = context2GpuData->handlesToDestroyBatchesTicket[i];
      if (ticket == queueSubmissionTicket) {
        queueSubmissionTicketArrayIndex = i;
        cpuSignal = context2GpuData->handlesToDestroyBatches[queueSubmissionTicketArrayIndex].cpuSignal;
        context2GpuData->handlesToDestroyBatches[queueSubmissionTicketArrayIndex].cpuSignalIsWaitedOnCounter += 1;
        break;
      }
    }
  }
  if (cpuSignal != NULL) {
    redCpuSignalWait(context, gpu, 1, &cpuSignal, 1, outStatuses, optionalFile, optionalLine, optionalUserData);
  }
  if (cpuSignal != NULL) {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    context2GpuData->handlesToDestroyBatches[queueSubmissionTicketArrayIndex].cpuSignalIsWaitedOnCounter -= 1;
    red2InternalHandlesToDestroyBatchesFreeFinishedBatch_NonLocking(context2, gpu, queueSubmissionTicketArrayIndex, optionalFile, optionalLine, optionalUserData);
  }
}

void red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket(Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  std::vector<uint64_t>           queueSubmissionTicketArrayIndex;
  std::vector<RedHandleCpuSignal> cpuSignal;
  {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    for (size_t i = 0, count = context2GpuData->handlesToDestroyBatches.size(); i < count; i += 1) {
      uint64_t ticket = context2GpuData->handlesToDestroyBatchesTicket[i];
      if (ticket != 0) {
        if (ticket <= queueSubmissionTicket) {
          queueSubmissionTicketArrayIndex.push_back(i);
          cpuSignal.push_back(context2GpuData->handlesToDestroyBatches[i].cpuSignal);
          context2GpuData->handlesToDestroyBatches[i].cpuSignalIsWaitedOnCounter += 1;
        }
      }
    }
  }
  if (cpuSignal.size() > 0) {
    redCpuSignalWait(context, gpu, (unsigned)cpuSignal.size(), cpuSignal.data(), 1, outStatuses, optionalFile, optionalLine, optionalUserData);
  }
  if (cpuSignal.size() > 0) {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    for (uint64_t i : queueSubmissionTicketArrayIndex) {
      context2GpuData->handlesToDestroyBatches[i].cpuSignalIsWaitedOnCounter -= 1;
      red2InternalHandlesToDestroyBatchesFreeFinishedBatch_NonLocking(context2, gpu, i, optionalFile, optionalLine, optionalUserData);
    }
  }
}

void red2WaitForAllQueueSubmissionsToFinish(Red2Context context2, RedHandleGpu gpu, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  std::vector<uint64_t>           queueSubmissionTicketArrayIndex;
  std::vector<RedHandleCpuSignal> cpuSignal;
  {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    for (size_t i = 0, count = context2GpuData->handlesToDestroyBatches.size(); i < count; i += 1) {
      uint64_t ticket = context2GpuData->handlesToDestroyBatchesTicket[i];
      if (ticket != 0) {
        queueSubmissionTicketArrayIndex.push_back(i);
        cpuSignal.push_back(context2GpuData->handlesToDestroyBatches[i].cpuSignal);
        context2GpuData->handlesToDestroyBatches[i].cpuSignalIsWaitedOnCounter += 1;
      }
    }
  }
  if (cpuSignal.size() > 0) {
    redCpuSignalWait(context, gpu, (unsigned)cpuSignal.size(), cpuSignal.data(), 1, outStatuses, optionalFile, optionalLine, optionalUserData);
  }
  if (cpuSignal.size() > 0) {
    std::lock_guard<std::mutex> __handlesToDestroyBatchesMutexLockGuard(context2GpuData->handlesToDestroyBatchesMutex);
    for (uint64_t i : queueSubmissionTicketArrayIndex) {
      context2GpuData->handlesToDestroyBatches[i].cpuSignalIsWaitedOnCounter -= 1;
      red2InternalHandlesToDestroyBatchesFreeFinishedBatch_NonLocking(context2, gpu, i, optionalFile, optionalLine, optionalUserData);
    }
  }
}

// REDGPU 2 new procedures from 28 Nov 2024:

RedXAccessBitflags red2RedXOnlyGetRedXAccessBitflagsFromRed(RedAccessBitflags access) {
  if (access == 0) {
    return REDX_ACCESS_BITFLAG_COMMON;
  }
  RedXAccessBitflags out = 0;
  if ((access & RED_ACCESS_BITFLAG_COPY_R)                               == RED_ACCESS_BITFLAG_COPY_R)                               { out |= REDX_ACCESS_BITFLAG_COPY_R;                               }
  if ((access & RED_ACCESS_BITFLAG_COPY_W)                               == RED_ACCESS_BITFLAG_COPY_W)                               { out |= REDX_ACCESS_BITFLAG_COPY_W;                               }
  if ((access & RED_ACCESS_BITFLAG_INDEX_R)                              == RED_ACCESS_BITFLAG_INDEX_R)                              { out |= REDX_ACCESS_BITFLAG_INDEX_R;                              }
  if ((access & RED_ACCESS_BITFLAG_STRUCT_ARRAY_RO_CONSTANT_R)           == RED_ACCESS_BITFLAG_STRUCT_ARRAY_RO_CONSTANT_R)           { out |= REDX_ACCESS_BITFLAG_STRUCT_ARRAY_RO_CONSTANT_R;           }
  if ((access & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) { out |= REDX_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R; }
  if ((access & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R)     == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R)     { out |= REDX_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R;     }
  if ((access & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W)                    == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W)                    { out |= REDX_ACCESS_BITFLAG_STRUCT_RESOURCE_RW;                   }
  if ((access & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R)                       == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R)                       { out |= REDX_ACCESS_BITFLAG_OUTPUT_DEPTH_STENCIL_R;               }
  if ((access & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW)                      == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW)                      { out |= REDX_ACCESS_BITFLAG_OUTPUT_DEPTH_STENCIL_RW;              }
  if ((access & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R)                     == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R)                     { out |= REDX_ACCESS_BITFLAG_OUTPUT_DEPTH_STENCIL_R;               }
  if ((access & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW)                    == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW)                    { out |= REDX_ACCESS_BITFLAG_OUTPUT_DEPTH_STENCIL_RW;              }
  if ((access & RED_ACCESS_BITFLAG_OUTPUT_COLOR_W)                       == RED_ACCESS_BITFLAG_OUTPUT_COLOR_W)                       { out |= REDX_ACCESS_BITFLAG_OUTPUT_COLOR_W;                       }
  if ((access & RED_ACCESS_BITFLAG_RESOLVE_SOURCE_R)                     == RED_ACCESS_BITFLAG_RESOLVE_SOURCE_R)                     { out |= REDX_ACCESS_BITFLAG_RESOLVE_SOURCE_R;                     }
  if ((access & RED_ACCESS_BITFLAG_RESOLVE_TARGET_W)                     == RED_ACCESS_BITFLAG_RESOLVE_TARGET_W)                     { out |= REDX_ACCESS_BITFLAG_RESOLVE_TARGET_W;                     }
  return out;
}

unsigned red2RedXOnlyArrayGetMemoryTypeIndex(RedHandleArray array) {
#ifdef REDGPU_USE_REDGPU_X
  RedXInternalTypeArray * handle = (RedXInternalTypeArray *)(void *)array;
  return handle->memoryTypeIndex;
#else
  return 0;
#endif
}

unsigned red2RedXOnlyImageGetLevelsCount(RedHandleImage image) {
#ifdef REDGPU_USE_REDGPU_X
  RedXInternalTypeImage * handle = (RedXInternalTypeImage *)(void *)image;
  return handle->levelsCount;
#else
  return 0;
#endif
}

unsigned red2RedXOnlyImageGetLayersCount(RedHandleImage image) {
#ifdef REDGPU_USE_REDGPU_X
  RedXInternalTypeImage * handle = (RedXInternalTypeImage *)(void *)image;
  return handle->layersCount;
#else
  return 0;
#endif
}

// NOTE(Constantine): Does nothing on REDGPU X.
void red2RedOnlyCallUsageAliasOrderBarrier(RedTypeProcedureAddressCallUsageAliasOrderBarrier address, RedHandleCalls calls, RedContext context, unsigned arrayUsagesCount, const RedUsageArray * arrayUsages, unsigned imageUsagesCount, const RedUsageImage * imageUsages, RedBool32 dependencyByRegion) {
#ifndef REDGPU_USE_REDGPU_X
  redCallUsageAliasOrderBarrier(address, calls, context, arrayUsagesCount, arrayUsages, imageUsagesCount, imageUsages, 0, NULL, 0, NULL, dependencyByRegion);
#endif
  volatile int nothing = 0;
}

// NOTE(Constantine): Does nothing on REDGPU.
void red2RedXOnlyCallUsageAliasOrderBarrier(RedHandleCalls calls, unsigned barriersCount, const void * barriers) {
#ifdef REDGPU_USE_REDGPU_X
  RedXCallUsageAliasOrderBarrier(calls, barriersCount, barriers);
#endif
  volatile int nothing = 0;
}

// NOTE(Constantine): Does nothing on REDGPU X.
void red2RedOnlyQueueWaitIdle(RedContext context, RedHandleGpu gpu, RedHandleQueue queue, const char * optionalFile, int optionalLine, void * optionalUserData) {
#ifndef REDGPU_USE_REDGPU_X
  redQueuePresent(context, gpu, queue, 0, NULL, 0, NULL, NULL, NULL, NULL, optionalFile, optionalLine, optionalUserData);
#endif
  volatile int nothing = 0;
}

#ifndef REDGPU_USE_REDGPU_X
#include "redgpu_vk.h"
#endif

// NOTE(Constantine): Does nothing on REDGPU X.
void red2RedOnlyCallBarrierFinishCpuUpload(RedTypeProcedureAddressCallUsageAliasOrderBarrier address, RedHandleCalls calls, uint64_t arraysCount, const RedHandleArray * arrays) {
  if (arraysCount == 0) { return; }
#ifndef REDGPU_USE_REDGPU_X
  VkBufferMemoryBarrier * bufferBarriers = new(std::nothrow) VkBufferMemoryBarrier [arraysCount]();
  for (uint64_t i = 0; i < arraysCount; i += 1) {
    bufferBarriers[i].sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
    bufferBarriers[i].pNext               = NULL;
    bufferBarriers[i].srcAccessMask       = VK_ACCESS_HOST_WRITE_BIT;
    bufferBarriers[i].dstAccessMask       = VK_ACCESS_MEMORY_READ_BIT; // NOTE(Constantine): On REDGPU X, CPU arrays cannot be written to from GPU, only read.
    bufferBarriers[i].srcQueueFamilyIndex =-1;
    bufferBarriers[i].dstQueueFamilyIndex =-1;
    bufferBarriers[i].buffer              = (VkBuffer)arrays[i];
    bufferBarriers[i].offset              = 0;
    bufferBarriers[i].size                =-1;
  }
  ((PFN_vkCmdPipelineBarrier)((void *)address))((VkCommandBuffer)calls, VK_PIPELINE_STAGE_HOST_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, 0, 0, NULL, arraysCount, bufferBarriers, 0, NULL);
  delete[] bufferBarriers;
#endif
  volatile int nothing = 0;
}

// NOTE(Constantine): Does nothing on REDGPU X.
void red2RedOnlyCallBarrierFinishCpuReadback(RedTypeProcedureAddressCallUsageAliasOrderBarrier address, RedHandleCalls calls, uint64_t arraysCount, const RedHandleArray * arrays) {
  if (arraysCount == 0) { return; }
#ifndef REDGPU_USE_REDGPU_X
  VkBufferMemoryBarrier * bufferBarriers = new(std::nothrow) VkBufferMemoryBarrier [arraysCount]();
  for (uint64_t i = 0; i < arraysCount; i += 1) {
    bufferBarriers[i].sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
    bufferBarriers[i].pNext               = NULL;
    bufferBarriers[i].srcAccessMask       = VK_ACCESS_MEMORY_WRITE_BIT;
    bufferBarriers[i].dstAccessMask       = VK_ACCESS_HOST_READ_BIT;
    bufferBarriers[i].srcQueueFamilyIndex =-1;
    bufferBarriers[i].dstQueueFamilyIndex =-1;
    bufferBarriers[i].buffer              = (VkBuffer)arrays[i];
    bufferBarriers[i].offset              = 0;
    bufferBarriers[i].size                =-1;
  }
  ((PFN_vkCmdPipelineBarrier)((void *)address))((VkCommandBuffer)calls, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_PIPELINE_STAGE_HOST_BIT, 0, 0, NULL, arraysCount, bufferBarriers, 0, NULL);
  delete[] bufferBarriers;
#endif
  volatile int nothing = 0;
}

// NOTE(Constantine): Does nothing on REDGPU X.
void red2RedOnlyCallGlobalMemoryBarrier(RedTypeProcedureAddressCallUsageAliasOrderBarrier address, RedHandleCalls calls) {
#ifndef REDGPU_USE_REDGPU_X
  VkMemoryBarrier globalBarrier;
  globalBarrier.sType         = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
  globalBarrier.pNext         = NULL;
  globalBarrier.srcAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
  globalBarrier.dstAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
  ((PFN_vkCmdPipelineBarrier)((void *)address))((VkCommandBuffer)calls, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, 0, 1, &globalBarrier, 0, NULL, 0, NULL);
#endif
  volatile int nothing = 0;
}
