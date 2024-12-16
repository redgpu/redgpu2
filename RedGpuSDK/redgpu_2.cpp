// cl /LD /EHsc /GR- /std:c++17 redgpu_2.cpp C:/RedGpuSDK/redgpudll.lib
// cl /LD /EHsc /GR- /std:c++17 /DREDGPU_USE_REDGPU_X redgpu_2_x.cpp C:/RedGpuSDK/redgpu_x.lib C:/RedGpuSDK/redgpu_x12.lib

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

typedef struct Red2InternalWsiStoredGpuSignalsPresentImageIndexData {
  uint64_t                        gpuSignalsCurrentFreeIndex;
  std::vector<RedHandleGpuSignal> gpuSignals;
} Red2InternalWsiStoredGpuSignalsPresentImageIndexData;

typedef struct Red2InternalWsiStoredGpuSignalsPresentData {
  std::map<unsigned, Red2InternalWsiStoredGpuSignalsPresentImageIndexData> map;
  volatile unsigned char init;
} Red2InternalWsiStoredGpuSignalsPresentData;

typedef struct Red2InternalQueueSubmissionData {
  RedHandleCpuSignal cpuSignal;
  uint64_t           cpuSignalIsWaitedOnCounter; // NOTE(Constantine): 26 Feb 2024, this counter is added to handle the case when other threads can wait on a CPU signal without locking the global mutex and be sure the CPU signal is not destroyed yet by other threads.
} Red2InternalQueueSubmissionData;

typedef struct Red2GpuInternalData {
  std::mutex                                                             wsiStoredGpuSignalsDataMutex;
  std::map<RedHandlePresent, Red2InternalWsiStoredGpuSignalsPresentData> wsiStoredGpuSignalsData;

  std::mutex                                   queueSubmissionsMutex;
  std::vector<Red2InternalQueueSubmissionData> queueSubmissions;
  std::vector<uint64_t>                        queueSubmissionsTicket;        // NOTE(Constantine): Ticket == 0 means the array slot is free to use for other greater tickets.
  uint64_t                                     queueSubmissionsCurrentTicket; // NOTE(Constantine): Starts with 0.

  volatile unsigned char init;
} Red2GpuInternalData;

typedef struct Red2ContextInternalData {
  std::map<RedHandleGpu, Red2GpuInternalData> gpus;
} Red2ContextInternalData;

// NOTE(Constantine):
// The REDGPU 2 wrapper around redCreateContext() that carries RedContext pointer and internal REDGPU 2 context data pointer.
// 
// The following functions depend on this function:
// * Any function that expects a parameter of type Red2Context
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2CreateContext(RedTypeProcedureMalloc malloc, RedTypeProcedureFree free, RedTypeProcedureMallocTagged optionalMallocTagged, RedTypeProcedureFreeTagged optionalFreeTagged, RedTypeProcedureDebugCallback debugCallback, RedSdkVersion sdkVersion, unsigned sdkExtensionsCount, const unsigned * sdkExtensions, const char * optionalProgramName, unsigned optionalProgramVersion, const char * optionalEngineName, unsigned optionalEngineVersion, const void * optionalSettings, Red2Context * outContext2, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_UNDEFINED; // TODO(Constantine): Assign a RED2_PROCEDURE_ID.

  Red2TypeContext * context2 = new(std::nothrow) Red2TypeContext();
  if (context2 == NULL) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = (RedProcedureId)procedureId;
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
        outStatuses->statusErrorProcedureId    = (RedProcedureId)procedureId;
        outStatuses->statusErrorFile           = optionalFile;
        outStatuses->statusErrorLine           = optionalLine;
        outStatuses->statusErrorDescription[0] = 0;
      }
    }
    delete context2;
    outContext2[0] = NULL;
    return;
  }

  redCreateContext(malloc, free, optionalMallocTagged, optionalFreeTagged, debugCallback, sdkVersion, sdkExtensionsCount, sdkExtensions, optionalProgramName, optionalProgramVersion, optionalEngineName, optionalEngineVersion, optionalSettings, &context2->context, outStatuses, optionalFile, optionalLine, optionalUserData);
  context2->redgpu2InternalData = context2Data;

  for (unsigned i = 0; i < context2->context->gpusCount; i += 1) {
    RedHandleGpu gpu = context2->context->gpus[i].gpu;
    context2Data->gpus[gpu].init = 1;
  }

  outContext2[0] = context2;
}

// NOTE(Constantine):
// The REDGPU 2 wrapper around redDestroyContext() that destroys and frees internal to REDGPU 2 context handles and pointers.
// 
// The following functions depend on this function:
// * red2CreateContext()
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2DestroyContext(Red2Context context2, const char * optionalFile, int optionalLine, void * optionalUserData) {
  if (context2 == NULL) {
    return;
  }

  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;

  for (const auto & [gpuHandle, context2GpuData] : context2Data->gpus) { // NOTE(Constantine): This style of loop requires C++17.
    for (const auto & queueSubmission : context2GpuData.queueSubmissions) {
      redDestroyCpuSignal(context, gpuHandle, queueSubmission.cpuSignal, optionalFile, optionalLine, optionalUserData);
    }
  }
  for (auto & [gpuHandle, context2GpuData] : context2Data->gpus) { // NOTE(Constantine): This style of loop requires C++17.
    std::lock_guard<std::mutex> wsiStoredGpuSignalsDataMutexLockGuard(context2GpuData.wsiStoredGpuSignalsDataMutex);
    for (const auto & [presentHandle, presentData] : context2GpuData.wsiStoredGpuSignalsData) { // NOTE(Constantine): This style of loop requires C++17.
      for (const auto & [dataKey, data] : presentData.map) { // NOTE(Constantine): This style of loop requires C++17.
        for (const auto & gpuSignal : data.gpuSignals) {
          redDestroyGpuSignal(context, gpuHandle, gpuSignal, optionalFile, optionalLine, optionalUserData);
        }
      }
    }
  }
  redDestroyContext(context, optionalFile, optionalLine, optionalUserData);
  {
    Red2ContextInternalData * context2Data = (Red2ContextInternalData *)context2->redgpu2InternalData;
    delete context2Data;
    delete context2;
  }
}

// NOTE(Constantine):
// redXCreateImage() is available only in REDGPU X, so this function wraps it to eliminate #ifdef's on user side.
// 
// This function is optional.
void red2CreateImage(RedContext context, RedHandleGpu gpu, const char * handleName, RedImageDimensions dimensions, RedFormat format, unsigned xformat, unsigned width, unsigned height, unsigned depth, unsigned levelsCount, unsigned layersCount, RedMultisampleCountBitflag multisampleCount, RedAccessBitflags restrictToAccess, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedImage * outImage, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
#ifdef REDGPU_USE_REDGPU_X
  redXCreateImage(context, gpu, handleName, dimensions, format, xformat, width, height, depth, levelsCount, layersCount, multisampleCount, restrictToAccess, initialAccess, initialQueueFamilyIndex, dedicate, outImage, outStatuses, optionalFile, optionalLine, optionalUserData);
#else
  redCreateImage(context, gpu, handleName, dimensions, format, width, height, depth, levelsCount, layersCount, multisampleCount, restrictToAccess, initialAccess, initialQueueFamilyIndex, dedicate, outImage, outStatuses, optionalFile, optionalLine, optionalUserData);
#endif
}

// NOTE(Constantine):
// redXCreateTexture() is available only in REDGPU X, so this function wraps it to eliminate #ifdef's on user side.
// 
// This function is optional.
void red2CreateTexture(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleImage image, RedImagePartBitflags parts, RedTextureDimensions dimensions, RedFormat format, unsigned xformat, unsigned levelsFirst, unsigned levelsCount, unsigned layersFirst, unsigned layersCount, RedAccessBitflags restrictToAccess, RedHandleTexture * outTexture, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
#ifdef REDGPU_USE_REDGPU_X
  redXCreateTexture(context, gpu, handleName, image, parts, dimensions, format, xformat, levelsFirst, levelsCount, layersFirst, layersCount, restrictToAccess, outTexture, outStatuses, optionalFile, optionalLine, optionalUserData);
#else
  redCreateTexture(context, gpu, handleName, image, parts, dimensions, format, levelsFirst, levelsCount, layersFirst, layersCount, restrictToAccess, outTexture, outStatuses, optionalFile, optionalLine, optionalUserData);
#endif
}

// NOTE(Constantine):
// The REDGPU 2 wrapper around redCreateStructDeclaration() that carries local copies of struct declaration members structs.
// 
// The following functions depend on this function:
// * red2CreateProcedureParameters()
// * red2DestroyStructDeclaration()
// * red2StructDeclarationGet*()
// * red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters()
// * red2CallSuballocateAndSetProcedureParametersInlineStruct()
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2CreateStructDeclaration(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned structDeclarationMembersCount, const RedStructDeclarationMember * structDeclarationMembers, unsigned structDeclarationMembersArrayROCount, const RedStructDeclarationMemberArrayRO * structDeclarationMembersArrayRO, RedBool32 procedureParametersHandlesDeclaration, Red2HandleStructDeclaration * outStructDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_UNDEFINED; // TODO(Constantine): Assign a RED2_PROCEDURE_ID.

  Red2InternalTypeStructDeclaration * handle = new(std::nothrow) Red2InternalTypeStructDeclaration();
  if (handle == NULL) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = (RedProcedureId)procedureId;
        outStatuses->statusErrorFile           = optionalFile;
        outStatuses->statusErrorLine           = optionalLine;
        outStatuses->statusErrorDescription[0] = 0;
      }
    }
    outStructDeclaration[0] = NULL;
    return;
  }
  handle->structDeclarationMembers = NULL;
  if (structDeclarationMembersCount > 0) {
    handle->structDeclarationMembers = new(std::nothrow) Red2StructDeclarationMember[structDeclarationMembersCount] /*---*/;
    if (handle->structDeclarationMembers == NULL) {
      if (outStatuses != NULL) {
        if (outStatuses->statusError == RED_STATUS_SUCCESS) {
          outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
          outStatuses->statusErrorCode           = 0;
          outStatuses->statusErrorHresult        = 0;
          outStatuses->statusErrorProcedureId    = (RedProcedureId)procedureId;
          outStatuses->statusErrorFile           = optionalFile;
          outStatuses->statusErrorLine           = optionalLine;
          outStatuses->statusErrorDescription[0] = 0;
        }
      }
      delete handle;
      outStructDeclaration[0] = NULL;
      return;
    }
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
  // NOTE(Constantine): Essentially, converting RedStructDeclarationMember::inlineSampler array of 1 to Red2StructDeclarationMember::inlineSampler non-array value.
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

// NOTE(Constantine):
// The REDGPU 2 wrapper around redDestroyStructDeclaration() that frees internal to REDGPU 2 struct declaration pointers.
// 
// The following functions depend on this function:
// * red2CreateStructDeclaration()
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2DestroyStructDeclaration(RedContext context, RedHandleGpu gpu, Red2HandleStructDeclaration structDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData) {
  if (structDeclaration == NULL) {
    return;
  }
  Red2InternalTypeStructDeclaration * handle = (Red2InternalTypeStructDeclaration *)(void *)structDeclaration;
  redDestroyStructDeclaration(context, gpu, handle->handle, optionalFile, optionalLine, optionalUserData);
  delete[] handle->structDeclarationMembers;
  delete handle;
}

// NOTE(Constantine):
// The REDGPU 2 wrapper around redCreateProcedureParameters() that carries local copies of REDGPU 2 struct declaration handles.
// 
// The following functions depend on this function:
// * red2DestroyProcedureParameters()
// * red2ProcedureParametersGet*()
// * red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters()
// * red2CallSuballocateAndSetProcedureParametersInlineStruct()
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2CreateProcedureParameters(RedContext context, RedHandleGpu gpu, const char * handleName, const Red2ProcedureParametersDeclaration * procedureParametersDeclaration, Red2HandleProcedureParameters * outProcedureParameters, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_UNDEFINED; // TODO(Constantine): Assign a RED2_PROCEDURE_ID.

  Red2InternalTypeProcedureParameters * handle = new(std::nothrow) Red2InternalTypeProcedureParameters();
  if (handle == NULL) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = (RedProcedureId)procedureId;
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

// NOTE(Constantine):
// The REDGPU 2 wrapper around redDestroyProcedureParameters() that frees internal to REDGPU 2 procedure parameters pointers.
// 
// The following functions depend on this function:
// * red2CreateProcedureParameters()
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2DestroyProcedureParameters(RedContext context, RedHandleGpu gpu, Red2HandleProcedureParameters procedureParameters, const char * optionalFile, int optionalLine, void * optionalUserData) {
  if (procedureParameters == NULL) {
    return;
  }
  Red2InternalTypeProcedureParameters * handle = (Red2InternalTypeProcedureParameters *)(void *)procedureParameters;
  redDestroyProcedureParameters(context, gpu, handle->handle, optionalFile, optionalLine, optionalUserData);
  delete handle;
}

// NOTE(Constantine):
// The REDGPU 2 wrapper around redCreateProcedure() that creates and destroys a temporary output declaration handle that is needed to create the procedure.
// 
// This function is optional.
void red2CreateProcedure(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, const Red2ProcedureDependencyOnRenderTargets * procedureDependencyOnRenderTargets, RedHandleProcedureParameters procedureParameters, const char * gpuCodeVertexMainProcedureName, RedHandleGpuCode gpuCodeVertex, const char * gpuCodeFragmentMainProcedureName, RedHandleGpuCode gpuCodeFragment, const RedProcedureState * state, const void * stateExtension, RedBool32 deriveBase, RedHandleProcedure deriveFrom, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  // NOTE(Constantine): The line below gets 9 RedFormat or RedXFormat values from the start of procedureDependencyOnRenderTargets struct for REDGPU X.
  RedHandleOutputDeclaration outputDeclaration = (RedHandleOutputDeclaration)(void *)(&procedureDependencyOnRenderTargets->colorsTextureFormat[0]);
#ifndef REDGPU_USE_REDGPU_X
  {
    RedOutputDeclarationMembers members /*---*/;
    members.depthStencilEnable                        = state->depthTestEnable;
    members.depthStencilFormat                        = (RedFormat)procedureDependencyOnRenderTargets->depthStencilTextureFormat;
    members.depthStencilMultisampleCount              = procedureDependencyOnRenderTargets->depthStencilTextureMultisampleCount;
    members.depthStencilDepthSetProcedureOutputOp     = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilDepthEndProcedureOutputOp     = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilStencilSetProcedureOutputOp   = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilStencilEndProcedureOutputOp   = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilSharesMemoryWithAnotherMember = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsCount                               = state->outputColorsCount;
    members.colorsFormat[0]                           = (RedFormat)procedureDependencyOnRenderTargets->colorsTextureFormat[0];
    members.colorsFormat[1]                           = (RedFormat)procedureDependencyOnRenderTargets->colorsTextureFormat[1];
    members.colorsFormat[2]                           = (RedFormat)procedureDependencyOnRenderTargets->colorsTextureFormat[2];
    members.colorsFormat[3]                           = (RedFormat)procedureDependencyOnRenderTargets->colorsTextureFormat[3];
    members.colorsFormat[4]                           = (RedFormat)procedureDependencyOnRenderTargets->colorsTextureFormat[4];
    members.colorsFormat[5]                           = (RedFormat)procedureDependencyOnRenderTargets->colorsTextureFormat[5];
    members.colorsFormat[6]                           = (RedFormat)procedureDependencyOnRenderTargets->colorsTextureFormat[6];
    members.colorsFormat[7]                           = (RedFormat)procedureDependencyOnRenderTargets->colorsTextureFormat[7];
    members.colorsMultisampleCount[0]                 = procedureDependencyOnRenderTargets->colorsTextureMultisampleCount[0];
    members.colorsMultisampleCount[1]                 = procedureDependencyOnRenderTargets->colorsTextureMultisampleCount[1];
    members.colorsMultisampleCount[2]                 = procedureDependencyOnRenderTargets->colorsTextureMultisampleCount[2];
    members.colorsMultisampleCount[3]                 = procedureDependencyOnRenderTargets->colorsTextureMultisampleCount[3];
    members.colorsMultisampleCount[4]                 = procedureDependencyOnRenderTargets->colorsTextureMultisampleCount[4];
    members.colorsMultisampleCount[5]                 = procedureDependencyOnRenderTargets->colorsTextureMultisampleCount[5];
    members.colorsMultisampleCount[6]                 = procedureDependencyOnRenderTargets->colorsTextureMultisampleCount[6];
    members.colorsMultisampleCount[7]                 = procedureDependencyOnRenderTargets->colorsTextureMultisampleCount[7];
    members.colorsSetProcedureOutputOp[0]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[1]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[2]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[3]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[4]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[5]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[6]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[7]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[0]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[1]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[2]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[3]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[4]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[5]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[6]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[7]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSharesMemoryWithAnotherMember[0]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[1]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[2]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[3]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[4]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[5]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[6]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[7]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    RedBool32 dependencyByRegion = 0;
    RedBool32 dependencyByRegionAllowUsageAliasOrderBarriers = 0;
    redCreateOutputDeclaration(context, gpu, NULL, &members, NULL, dependencyByRegion, dependencyByRegionAllowUsageAliasOrderBarriers, &outputDeclaration, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (outputDeclaration == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      return;
    }
  }
#endif
  redCreateProcedure(context, gpu, handleName, procedureCache, outputDeclaration, procedureParameters, gpuCodeVertexMainProcedureName, gpuCodeVertex, gpuCodeFragmentMainProcedureName, gpuCodeFragment, state, stateExtension, deriveBase, deriveFrom, outProcedure, outStatuses, optionalFile, optionalLine, optionalUserData);
#ifndef REDGPU_USE_REDGPU_X
  // https://github.com/KhronosGroup/Vulkan-Docs/issues/516
  redDestroyOutputDeclaration(context, gpu, outputDeclaration, optionalFile, optionalLine, optionalUserData);
#endif
}

// NOTE(Constantine):
// The wrapper around redCreateCalls() that carries internal REDGPU 2 calls data.
// 
// The following functions depend on this function:
// * Any function that expects a parameter of type Red2HandleCalls
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2CreateCalls(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, Red2HandleCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_UNDEFINED; // TODO(Constantine): Assign a RED2_PROCEDURE_ID.

  Red2InternalTypeCalls * handle = new(std::nothrow) Red2InternalTypeCalls();
  if (handle == NULL) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = (RedProcedureId)procedureId;
        outStatuses->statusErrorFile           = optionalFile;
        outStatuses->statusErrorLine           = optionalLine;
        outStatuses->statusErrorDescription[0] = 0;
      }
    }
    outCalls[0] = NULL;
    return;
  }
  redCreateCalls(context, gpu, handleName, queueFamilyIndex, (RedCalls *)(void *)handle, outStatuses, optionalFile, optionalLine, optionalUserData);
  handle->context = context;
  handle->gpu     = gpu;
  outCalls[0] = (Red2HandleCalls)(void *)handle;
}

// NOTE(Constantine):
// The wrapper around redCreateCallsReusable() that carries internal REDGPU 2 calls data.
// 
// The following functions depend on this function:
// * Any function that expects a parameter of type Red2HandleCalls
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2CreateCallsReusable(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, Red2HandleCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_UNDEFINED; // TODO(Constantine): Assign a RED2_PROCEDURE_ID.

  Red2InternalTypeCalls * handle = new(std::nothrow) Red2InternalTypeCalls();
  if (handle == NULL) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = (RedProcedureId)procedureId;
        outStatuses->statusErrorFile           = optionalFile;
        outStatuses->statusErrorLine           = optionalLine;
        outStatuses->statusErrorDescription[0] = 0;
      }
    }
    outCalls[0] = NULL;
    return;
  }
  redCreateCallsReusable(context, gpu, handleName, queueFamilyIndex, (RedCalls *)(void *)handle, outStatuses, optionalFile, optionalLine, optionalUserData);
  handle->context = context;
  handle->gpu     = gpu;
  outCalls[0] = (Red2HandleCalls)(void *)handle;
}

static void red2InternalDestroyHandleByHandleType(RedContext context, RedHandleGpu gpu, uint64_t handle, unsigned handleType, void * optionalCustomHandleAndHandleTypeDestroyCallback, const char * optionalFile, int optionalLine, void * optionalUserData) {
  if      (handleType == 0)                                     { }
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
    redMark("[REDGPU 2][TODO(Constantine)] The handle is not destroyed, and no custom destroy callback was set, need to implement destruction of the handle type here, in this part of REDGPU 2 code.", optionalFile, optionalLine, optionalUserData);
  }
}

// NOTE(Constantine):
// The REDGPU 2 wrapper around redDestroyCalls() that destroys and frees internal to REDGPU 2 calls handles and pointers.
// 
// The following functions depend on this function:
// * red2CreateCalls()
// * red2CreateCallsReusable()
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2DestroyCalls(RedContext context, RedHandleGpu gpu, Red2HandleCalls calls, const char * optionalFile, int optionalLine, void * optionalUserData) {
  if (calls == NULL) {
    return;
  }
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  for (size_t i = 0, count = handle->structsMemorys.size(); i < count; i += 1) {
    redStructsMemoryFree(context, gpu, handle->structsMemorys[i].handle, optionalFile, optionalLine, optionalUserData);
  }
  for (size_t i = 0, count = handle->structsMemorysSamplers.size(); i < count; i += 1) {
    redStructsMemoryFree(context, gpu, handle->structsMemorysSamplers[i].handle, optionalFile, optionalLine, optionalUserData);
  }
  for (uint64_t i = 0, count = handle->handlesToDestroyWhenCallsAreReset.size(); i < count; i += 1) {
    uint64_t h     = handle->handlesToDestroyWhenCallsAreReset[i];
    unsigned htype = handle->handlesToDestroyWhenCallsAreResetType[i];
    red2InternalDestroyHandleByHandleType(handle->context, handle->gpu, h, htype, handle->handlesToDestroyWhenCallsAreResetCustomCallback, optionalFile, optionalLine, optionalUserData);
  }
  redDestroyCalls(context, gpu, handle->handle, handle->memory, optionalFile, optionalLine, optionalUserData);
  delete handle;
}

// NOTE(Constantine):
// The REDGPU 2 wrapper around redCallsSet() that destroys and resets internal to REDGPU 2 calls handles.
// 
// The following functions depend on this function:
// * Any function that expects a parameter of type Red2HandleCalls
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2CallsSet(Red2HandleCalls calls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;

  redCallsSet(handle->context, handle->gpu, handle->handle, handle->memory, handle->reusable, outStatuses, optionalFile, optionalLine, optionalUserData);

  handle->currentStructsMemoryIndex         = 0;
  handle->currentStructsMemorySamplersIndex = 0;
  for (size_t i = 0, count = handle->structsMemorys.size(); i < count; i += 1) {
#ifndef REDGPU_USE_REDGPU_X
    redStructsMemoryReset(handle->context, handle->gpu, handle->structsMemorys[i].handle, outStatuses, optionalFile, optionalLine, optionalUserData);
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
    redStructsMemoryReset(handle->context, handle->gpu, handle->structsMemorysSamplers[i].handle, outStatuses, optionalFile, optionalLine, optionalUserData);
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
  {
    for (uint64_t i = 0, count = handle->handlesToDestroyWhenCallsAreReset.size(); i < count; i += 1) {
      uint64_t h     = handle->handlesToDestroyWhenCallsAreReset[i];
      unsigned htype = handle->handlesToDestroyWhenCallsAreResetType[i];
      red2InternalDestroyHandleByHandleType(handle->context, handle->gpu, h, htype, handle->handlesToDestroyWhenCallsAreResetCustomCallback, optionalFile, optionalLine, optionalUserData);
    }
    handle->handlesToDestroyWhenCallsAreReset.clear();
    handle->handlesToDestroyWhenCallsAreResetType.clear();
  }
}

// NOTE(Constantine):
// The REDGPU 2 wrapper around redCallsEnd().
// 
// The following functions depend on this function:
// * red2CallsSet()
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2CallsEnd(Red2HandleCalls calls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  redCallsEnd(handle->context, handle->gpu, handle->handle, handle->memory, outStatuses, optionalFile, optionalLine, optionalUserData);
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
void red2CallsAppendHandleToDestroy(Red2HandleCalls calls, uint64_t handleToDestroyWhenCallsAreReset, unsigned handleToDestroyWhenCallsAreResetType) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  handle->handlesToDestroyWhenCallsAreReset.push_back(handleToDestroyWhenCallsAreReset);
  handle->handlesToDestroyWhenCallsAreResetType.push_back(handleToDestroyWhenCallsAreResetType);
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
void red2CallsFreeAllInlineStructsMemorys(Red2HandleCalls calls, const char * optionalFile, int optionalLine, void * optionalUserData) {
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

// NOTE(Constantine):
// The REDGPU 2 wrapper around redPresentGetImageIndex() that prepares WSI stored GPU signals for reuse.
// 
// The following functions depend on this function:
// * red2GetWsiStoredGpuSignal()
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2PresentGetImageIndex(Red2Context context2, RedHandleGpu gpu, RedHandlePresent present, RedHandleCpuSignal signalCpuSignal, RedHandleGpuSignal signalGpuSignal, unsigned * outImageIndex, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  redPresentGetImageIndex(context, gpu, present, signalCpuSignal, signalGpuSignal, outImageIndex, outStatuses, optionalFile, optionalLine, optionalUserData);
  // NOTE(Constantine): Assuming redPresentGetImageIndex blocks CPU here until a new image index is returned to outImageIndex.
  {
    std::lock_guard<std::mutex> wsiStoredGpuSignalsDataMutexLockGuard(context2GpuData->wsiStoredGpuSignalsDataMutex);
    context2GpuData->wsiStoredGpuSignalsData[present].map[outImageIndex[0]].gpuSignalsCurrentFreeIndex = 0;
  }
}

// NOTE(Constantine):
// A new REDGPU 2 procedure. Each returned GPU signal is assumed to be in an unsignaled state.
// 
// This function is optional.
void red2GetWsiStoredGpuSignal(Red2Context context2, RedHandleGpu gpu, RedHandlePresent present, unsigned presentImageIndex, RedHandleGpuSignal * outGpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  RedHandleGpuSignal gpuSignal = NULL;
  {
    std::lock_guard<std::mutex> wsiStoredGpuSignalsDataMutexLockGuard(context2GpuData->wsiStoredGpuSignalsDataMutex);

    // NOTE(Constantine): This line initializes the [present] map element if it doesn't exist in the map.
    context2GpuData->wsiStoredGpuSignalsData[present].init = 1;

    // NOTE(Constantine): This line initializes the [presentImageIndex] map element if it doesn't exist in the map.
    uint64_t index = context2GpuData->wsiStoredGpuSignalsData[present].map[presentImageIndex].gpuSignalsCurrentFreeIndex;

    // NOTE(Constantine): Caching the pointer to the [presentImageIndex] map element.
    Red2InternalWsiStoredGpuSignalsPresentImageIndexData * data = &context2GpuData->wsiStoredGpuSignalsData[present].map[presentImageIndex];

    if (data->gpuSignals.size() < (index + 1)) {
      RedHandleGpuSignal handle = NULL;
      redCreateGpuSignal(context, gpu, NULL, &handle, outStatuses, optionalFile, optionalLine, optionalUserData);
      data->gpuSignals.push_back(handle);
    }

    // NOTE(Constantine):
    // Assumes all the available GPU signals are in unsignaled state.
    // For example, all WSI stored GPU signals can be unsignaled via redQueuePresent::waitForAndUnsignalGpuSignals parameter.
    gpuSignal = data->gpuSignals[index];

    data->gpuSignalsCurrentFreeIndex += 1;
  }
  outGpuSignal[0] = gpuSignal;
}

static size_t red2InternalQueueSubmissionsGetFreeElementIndex_NonLocking(Red2Context context2, RedHandleGpu gpu) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  size_t index = -1;
  for (size_t i = 0, count = context2GpuData->queueSubmissionsTicket.size(); i < count; i += 1) {
    if (context2GpuData->queueSubmissionsTicket[i] == 0) {
      index = i;
      break;
    }
  }
  return index;
}

// NOTE(Constantine):
// The REDGPU 2 wrapper around redQueueSubmit() that replaces manual management of CPU signals with free-to-use-however-you-want plain ticket values.
// 
// The following functions depend on this function:
// * red2IsQueueSubmissionFinished()
// * red2IsQueueSubmissionFinishedByTicketAlone()
// * red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket()
// * red2WaitForQueueSubmissionToFinish()
// * red2WaitForQueueSubmissionToFinishByTicketAlone()
// * red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket()
// * red2WaitForAllQueueSubmissionsToFinish()
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2QueueSubmit(Red2Context context2, RedHandleGpu gpu, RedHandleQueue queue, unsigned timelinesCount, const RedGpuTimeline * timelines, uint64_t * outQueueSubmissionTicketArrayIndex, uint64_t * outQueueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  RedHandleCpuSignal cpuSignal = NULL;
  size_t i = -1;
  {
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    i = red2InternalQueueSubmissionsGetFreeElementIndex_NonLocking(context2, gpu);
    if (i != -1) {
      cpuSignal = context2GpuData->queueSubmissions[i].cpuSignal;
      context2GpuData->queueSubmissionsCurrentTicket += 1; // NOTE(Constantine): Assuming u64 will not overflow during the lifetime of a program.
      context2GpuData->queueSubmissionsTicket[i]      = context2GpuData->queueSubmissionsCurrentTicket;
    }
  }
  if (i == -1) {
    redCreateCpuSignal(context, gpu, NULL, 0, &cpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (cpuSignal == NULL) { // NOTE(Constantine): Assuming cpuSignal is always NULL and not a garbage value on any fail of redCreateCpuSignal(). Maybe need to check for outStatuses error too?
      if (outQueueSubmissionTicketArrayIndex != NULL) { outQueueSubmissionTicketArrayIndex[0] = 0; }
      if (outQueueSubmissionTicket           != NULL) { outQueueSubmissionTicket[0]           = 0; }
      return;
    }
  }
  // NOTE(Constantine):
  // What happens when both vkQueueSubmit() and vkGetFenceStatus() execute on the same VkFence at the same time from different threads?
  redQueueSubmit(context, gpu, queue, timelinesCount, timelines, cpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
  if (i == -1) {
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    {
      Red2InternalQueueSubmissionData emptyElement = {};
      context2GpuData->queueSubmissions.push_back(emptyElement);
      context2GpuData->queueSubmissionsTicket.push_back(0);
      i = context2GpuData->queueSubmissions.size() - 1;
      context2GpuData->queueSubmissions[i].cpuSignal = cpuSignal;
    }
    context2GpuData->queueSubmissionsCurrentTicket += 1; // NOTE(Constantine): Assuming u64 will not overflow during the lifetime of a program.
    context2GpuData->queueSubmissionsTicket[i]      = context2GpuData->queueSubmissionsCurrentTicket;
  }
  if (outQueueSubmissionTicketArrayIndex != NULL) { outQueueSubmissionTicketArrayIndex[0] = i; }
  if (outQueueSubmissionTicket           != NULL) { outQueueSubmissionTicket[0]           = context2GpuData->queueSubmissionsCurrentTicket; }
}

// NOTE(Constantine):
// The REDGPU 2 wrapper around red2QueueSubmit() that stores the queue submission tickets in each REDGPU 2 calls that were submitted.
// 
// The following functions depend on this function:
// * red2IsQueueSubmissionFinished()
// * red2IsQueueSubmissionFinishedByTicketAlone()
// * red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket()
// * red2WaitForQueueSubmissionToFinish()
// * red2WaitForQueueSubmissionToFinishByTicketAlone()
// * red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket()
// * red2WaitForAllQueueSubmissionsToFinish()
// * red2CallsGetQueueSubmitTrackableTicket()
// * red2CallsSetQueueSubmitTrackableTicket()
// 
// If you don't plan to use the functions listed above, then this function becomes optional.
void red2QueueSubmitTrackableSimple(Red2Context context2, RedHandleGpu gpu, RedHandleQueue queue, unsigned callsCount, Red2HandleCalls * calls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_UNDEFINED; // TODO(Constantine): Assign a RED2_PROCEDURE_ID.

  unsigned         callsHandlesCount = callsCount;
  RedHandleCalls * callsHandles      = NULL;

  if (callsHandlesCount > 0) {
    callsHandles = new(std::nothrow) RedHandleCalls [callsHandlesCount] /*---*/;
    if (callsHandles == NULL) {
      if (outStatuses != NULL) {
        if (outStatuses->statusError == RED_STATUS_SUCCESS) {
          outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
          outStatuses->statusErrorCode           = 0;
          outStatuses->statusErrorHresult        = 0;
          outStatuses->statusErrorProcedureId    = (RedProcedureId)procedureId;
          outStatuses->statusErrorFile           = optionalFile;
          outStatuses->statusErrorLine           = optionalLine;
          outStatuses->statusErrorDescription[0] = 0;
        }
      }
      return;
    }
  }
  
  for (unsigned i = 0; i < callsHandlesCount; i += 1) {
    RedCalls redcalls /*---*/;
    red2CallsGetRedHandles(calls[i], NULL, NULL, &redcalls);
    callsHandles[i] = redcalls.handle;
  }

  RedGpuTimeline timeline /*---*/;
  timeline.setTo4                            = 4;
  timeline.setTo0                            = 0;
  timeline.waitForAndUnsignalGpuSignalsCount = 0;
  timeline.waitForAndUnsignalGpuSignals      = NULL;
  timeline.setTo65536                        = NULL;
  timeline.callsCount                        = callsHandlesCount;
  timeline.calls                             = callsHandles;
  timeline.signalGpuSignalsCount             = 0;
  timeline.signalGpuSignals                  = NULL;

  uint64_t queueSubmitTrackableTicketArrayIndex = 0;
  uint64_t queueSubmitTrackableTicket           = 0;
  red2QueueSubmit(context2, gpu, queue, 1, &timeline, &queueSubmitTrackableTicketArrayIndex, &queueSubmitTrackableTicket, outStatuses, optionalFile, optionalLine, optionalUserData);

  if (callsHandles != NULL) { delete[] callsHandles; }

  for (unsigned i = 0; i < callsCount; i += 1) {
    Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls[i];
    // NOTE(Constantine):
    // D3D12 doesn't allow to submit the same command list that was already submitted until that
    // previous submission is finished, so having only one trackable queue submit ticket is fine.
    // > A direct command list can be submitted for execution multiple times, but the app is
    //   responsible for ensuring that the direct command list has finished executing on the GPU
    //   before submitting it again.
    //   https://learn.microsoft.com/en-us/windows/win32/direct3d12/design-philosophy-of-command-queues-and-command-lists
    handle->lastQueueSubmitTrackableTicketArrayIndex = queueSubmitTrackableTicketArrayIndex;
    handle->lastQueueSubmitTrackableTicket           = queueSubmitTrackableTicket;
  }
}

// NOTE(Constantine):
// redXCreateQueue() is available only in REDGPU X, so this function wraps it to eliminate #ifdef's on user side.
// 
// This function is optional.
void red2RedXOnlyCreateQueue(RedContext context, RedHandleGpu gpu, const char * handleName, RedBool32 canCopy, RedBool32 canDraw, RedBool32 canCompute, unsigned priority, RedBool32 disableGpuTimeout, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
#ifdef REDGPU_USE_REDGPU_X
  redXCreateQueue(context, gpu, handleName, canCopy, canDraw, canCompute, priority, disableGpuTimeout, outStatuses, optionalFile, optionalLine, optionalUserData);
#endif
  volatile int nothing = 0;
}

// NOTE(Constantine):
// A new REDGPU 2 procedure that waits on CPU until a queue of a GPU is finished doing work. In REDGPU and REDGPU X, sometimes you need to wait for, say, a present queue to finish before destroying WSI resources that were submitted to it. See redgpu_wsi.h comment from Dec 01, 2022.
// 
// This function is optional.
void red2QueueWaitIdle(RedContext context, RedHandleGpu gpu, RedHandleQueue presentQueue, const char * optionalFile, int optionalLine, void * optionalUserData) {
  // NOTE(Constantine): This function depends on the particular current REDGPU and REDGPU X implementations which allow to wait on any type of queue, not only present ones.
  redQueuePresent(context, gpu, presentQueue, 0, NULL, 0, NULL, NULL, NULL, NULL, optionalFile, optionalLine, optionalUserData);
}

// NOTE(Constantine):
// A new REDGPU 2 procedure that waits on CPU until all the queues of a GPU are finished doing work.
// 
// This function is optional.
void red2GpuWaitIdle(RedContext context, const RedGpuInfo * gpuInfo, const char * optionalFile, int optionalLine, void * optionalUserData) {
  for (unsigned i = 0; i < gpuInfo->queuesCount; i += 1) {
    red2QueueWaitIdle(context, gpuInfo->gpu, gpuInfo->queues[i], optionalFile, optionalLine, optionalUserData);
  }
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
unsigned red2PickResourceMemoryTypeIndex(const RedGpuInfo * gpuInfo, RedBool32 requireMappableMemoryCoherency, Red2ResourceDesiredMemoryType resourceDesiredMemoryType, unsigned resourceMemoryTypesSupported) {
  const unsigned        memoryTypesCount = gpuInfo->memoryTypesCount;
  const RedMemoryType * memoryTypes      = gpuInfo->memoryTypes;

  unsigned char memoryTypeIsSupported[32] /*---*/;
  memoryTypeIsSupported[0]  = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0001)) == 0 ? 0 : 1;
  memoryTypeIsSupported[1]  = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0010)) == 0 ? 0 : 1;
  memoryTypeIsSupported[2]  = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0100)) == 0 ? 0 : 1;
  memoryTypeIsSupported[3]  = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,1000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[4]  = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0001,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[5]  = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0010,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[6]  = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0100,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[7]  = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,1000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[8]  = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0001,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[9]  = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0010,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[10] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0100,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[11] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,1000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[12] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0001,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[13] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0010,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[14] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0100,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[15] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,1000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[16] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0001,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[17] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0010,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[18] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,0100,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[19] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0000,1000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[20] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0001,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[21] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0010,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[22] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,0100,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[23] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0000,1000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[24] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0001,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[25] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0010,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[26] = (resourceMemoryTypesSupported & REDGPU_B32(0000,0100,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[27] = (resourceMemoryTypesSupported & REDGPU_B32(0000,1000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[28] = (resourceMemoryTypesSupported & REDGPU_B32(0001,0000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[29] = (resourceMemoryTypesSupported & REDGPU_B32(0010,0000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[30] = (resourceMemoryTypesSupported & REDGPU_B32(0100,0000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[31] = (resourceMemoryTypesSupported & REDGPU_B32(1000,0000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;

  if (resourceDesiredMemoryType == RED2_RESOURCE_DESIRED_MEMORY_TYPE_VRAM) {
    for (unsigned i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isGpuVram == 1 && memoryTypeIsSupported[i] == 1 && gpuInfo->memoryHeaps[type->memoryHeapIndex].memoryBytesCount > 0) {
        return i;
      }
    }
  } else if (resourceDesiredMemoryType == RED2_RESOURCE_DESIRED_MEMORY_TYPE_UPLOAD) {
    for (unsigned i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isCpuMappable == 1 &&
          type->isCpuCoherent == requireMappableMemoryCoherency &&
          type->isCpuCached   == 0 && memoryTypeIsSupported[i] == 1 && gpuInfo->memoryHeaps[type->memoryHeapIndex].memoryBytesCount > 0)
      {
        return i;
      }
    }
    for (unsigned i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isCpuMappable == 1 &&
          type->isCpuCoherent == requireMappableMemoryCoherency && memoryTypeIsSupported[i] == 1 && gpuInfo->memoryHeaps[type->memoryHeapIndex].memoryBytesCount > 0)
      {
        return i;
      }
    }
    // NOTE(Constantine): Falling back to coherent mappable memory types here in case requireMappableMemoryCoherency == 0 are not found.
    if (requireMappableMemoryCoherency == 0) {
      for (unsigned i = 0; i < memoryTypesCount; i += 1) {
        const RedMemoryType * type = &memoryTypes[i];
        if (type->isCpuMappable == 1 &&
            type->isCpuCoherent == 1 &&
            type->isCpuCached   == 0 && memoryTypeIsSupported[i] == 1 && gpuInfo->memoryHeaps[type->memoryHeapIndex].memoryBytesCount > 0)
        {
          return i;
        }
      }
      for (unsigned i = 0; i < memoryTypesCount; i += 1) {
        const RedMemoryType * type = &memoryTypes[i];
        if (type->isCpuMappable == 1 &&
            type->isCpuCoherent == 1 && memoryTypeIsSupported[i] == 1 && gpuInfo->memoryHeaps[type->memoryHeapIndex].memoryBytesCount > 0)
        {
          return i;
        }
      }
    }
  } else if (resourceDesiredMemoryType == RED2_RESOURCE_DESIRED_MEMORY_TYPE_READBACK) {
    for (unsigned i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isCpuMappable == 1 &&
          type->isCpuCoherent == requireMappableMemoryCoherency &&
          type->isCpuCached   == 1 && memoryTypeIsSupported[i] == 1 && gpuInfo->memoryHeaps[type->memoryHeapIndex].memoryBytesCount > 0)
      {
        return i;
      }
    }
    for (unsigned i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isCpuMappable == 1 &&
          type->isCpuCoherent == requireMappableMemoryCoherency && memoryTypeIsSupported[i] == 1 && gpuInfo->memoryHeaps[type->memoryHeapIndex].memoryBytesCount > 0)
      {
        return i;
      }
    }
    // NOTE(Constantine): Falling back to coherent mappable memory types here in case requireMappableMemoryCoherency == 0 are not found.
    if (requireMappableMemoryCoherency == 0) {
      for (unsigned i = 0; i < memoryTypesCount; i += 1) {
        const RedMemoryType * type = &memoryTypes[i];
        if (type->isCpuMappable == 1 &&
            type->isCpuCoherent == 1 &&
            type->isCpuCached   == 1 && memoryTypeIsSupported[i] == 1 && gpuInfo->memoryHeaps[type->memoryHeapIndex].memoryBytesCount > 0)
        {
          return i;
        }
      }
      for (unsigned i = 0; i < memoryTypesCount; i += 1) {
        const RedMemoryType * type = &memoryTypes[i];
        if (type->isCpuMappable == 1 &&
            type->isCpuCoherent == 1 && memoryTypeIsSupported[i] == 1 && gpuInfo->memoryHeaps[type->memoryHeapIndex].memoryBytesCount > 0)
        {
          return i;
        }
      }
    }
  }

  return -1;
}

static void red2InternalQueueSubmissionsFreeFinishedCpuSignals_NonLocking(Red2Context context2, RedHandleGpu gpu, uint64_t index, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  RedHandleCpuSignal cpuSignal                  = context2GpuData->queueSubmissions[index].cpuSignal;
  uint64_t           cpuSignalIsWaitedOnCounter = context2GpuData->queueSubmissions[index].cpuSignalIsWaitedOnCounter;
  RedStatus status = RED_STATUS_SUCCESS;
  redCpuSignalGetStatus(context, gpu, cpuSignal, &status, optionalFile, optionalLine, optionalUserData);   // NOTE(Constantine): Assuming redCpuSignalGetStatus() never errors.
  if (status == RED_STATUS_SUCCESS && cpuSignalIsWaitedOnCounter == 0) {
    // > If any member of pFences is already in the unsignaled state when vkResetFences is executed, then vkResetFences has no effect on that fence.
    //   https://registry.khronos.org/vulkan/specs/1.0/man/html/vkResetFences.html
    redCpuSignalUnsignal(context, gpu, 1, &cpuSignal, NULL, optionalFile, optionalLine, optionalUserData); // NOTE(Constantine): Assuming redCpuSignalUnsignal()  never errors.
    context2GpuData->queueSubmissionsTicket[index] = 0;
  }
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
RedBool32 red2IsQueueSubmissionFinished(Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  if (queueSubmissionTicket == 0) {
    return 1;
  }
  uint64_t ticket = 0;
  {
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    if (context2GpuData->queueSubmissionsTicket[queueSubmissionTicketArrayIndex] == queueSubmissionTicket) {
      red2InternalQueueSubmissionsFreeFinishedCpuSignals_NonLocking(context2, gpu, queueSubmissionTicketArrayIndex, optionalFile, optionalLine, optionalUserData);
      ticket = context2GpuData->queueSubmissionsTicket[queueSubmissionTicketArrayIndex];
    }
  }
  return ticket == queueSubmissionTicket ? 0 : 1; // NOTE(Constantine): Alternatively, (ticket == 0 || ticket > queueSubmissionTicket) ? 1 : 0.
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
RedBool32 red2IsQueueSubmissionFinishedByTicketAlone(Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  if (queueSubmissionTicket == 0) {
    return 1;
  }
  uint64_t ticket = 0;
  {
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    for (size_t i = 0, count = context2GpuData->queueSubmissions.size(); i < count; i += 1) {
      if (context2GpuData->queueSubmissionsTicket[i] == queueSubmissionTicket) {
        red2InternalQueueSubmissionsFreeFinishedCpuSignals_NonLocking(context2, gpu, i, optionalFile, optionalLine, optionalUserData);
        ticket = context2GpuData->queueSubmissionsTicket[i];
        break;
      }
    }
  }
  return ticket == queueSubmissionTicket ? 0 : 1; // NOTE(Constantine): Alternatively, (ticket == 0 || ticket > queueSubmissionTicket) ? 1 : 0.
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
RedBool32 red2AreAllQueueSubmissionsFinishedUpToAndIncludingTicket(Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  RedBool32 allQueueSubmissionsAreFinished = 1;
  {
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    for (size_t i = 0, count = context2GpuData->queueSubmissions.size(); i < count; i += 1) {
      uint64_t t = context2GpuData->queueSubmissionsTicket[i];
      if (t != 0 && t <= queueSubmissionTicket) {
        red2InternalQueueSubmissionsFreeFinishedCpuSignals_NonLocking(context2, gpu, i, optionalFile, optionalLine, optionalUserData);
        uint64_t ticket = context2GpuData->queueSubmissionsTicket[i];
        if (ticket != 0 && ticket <= queueSubmissionTicket) {
          allQueueSubmissionsAreFinished = 0;
          break;
        }
      }
    }
  }
  return allQueueSubmissionsAreFinished;
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
void red2WaitForQueueSubmissionToFinish(Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  if (queueSubmissionTicket == 0) {
    return;
  }
  RedHandleCpuSignal cpuSignal = NULL;
  {
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    uint64_t ticket = context2GpuData->queueSubmissionsTicket[queueSubmissionTicketArrayIndex];
    if (ticket == queueSubmissionTicket) {
      cpuSignal = context2GpuData->queueSubmissions[queueSubmissionTicketArrayIndex].cpuSignal;
      context2GpuData->queueSubmissions[queueSubmissionTicketArrayIndex].cpuSignalIsWaitedOnCounter += 1;
    }
  }
  if (cpuSignal != NULL) {
    redCpuSignalWait(context, gpu, 1, &cpuSignal, 1, outStatuses, optionalFile, optionalLine, optionalUserData);
  }
  if (cpuSignal != NULL) {
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    context2GpuData->queueSubmissions[queueSubmissionTicketArrayIndex].cpuSignalIsWaitedOnCounter -= 1;
    red2InternalQueueSubmissionsFreeFinishedCpuSignals_NonLocking(context2, gpu, queueSubmissionTicketArrayIndex, optionalFile, optionalLine, optionalUserData);
  }
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
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
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    for (size_t i = 0, count = context2GpuData->queueSubmissions.size(); i < count; i += 1) {
      uint64_t ticket = context2GpuData->queueSubmissionsTicket[i];
      if (ticket == queueSubmissionTicket) {
        queueSubmissionTicketArrayIndex = i;
        cpuSignal = context2GpuData->queueSubmissions[queueSubmissionTicketArrayIndex].cpuSignal;
        context2GpuData->queueSubmissions[queueSubmissionTicketArrayIndex].cpuSignalIsWaitedOnCounter += 1;
        break;
      }
    }
  }
  if (cpuSignal != NULL) {
    redCpuSignalWait(context, gpu, 1, &cpuSignal, 1, outStatuses, optionalFile, optionalLine, optionalUserData);
  }
  if (cpuSignal != NULL) {
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    context2GpuData->queueSubmissions[queueSubmissionTicketArrayIndex].cpuSignalIsWaitedOnCounter -= 1;
    red2InternalQueueSubmissionsFreeFinishedCpuSignals_NonLocking(context2, gpu, queueSubmissionTicketArrayIndex, optionalFile, optionalLine, optionalUserData);
  }
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
void red2WaitForAllQueueSubmissionsToFinishUpToAndIncludingTicket(Red2Context context2, RedHandleGpu gpu, uint64_t queueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  std::vector<uint64_t>           queueSubmissionTicketArrayIndex;
  std::vector<RedHandleCpuSignal> cpuSignal;
  {
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    for (size_t i = 0, count = context2GpuData->queueSubmissions.size(); i < count; i += 1) {
      uint64_t ticket = context2GpuData->queueSubmissionsTicket[i];
      if (ticket != 0 && ticket <= queueSubmissionTicket) {
        queueSubmissionTicketArrayIndex.push_back(i);
        cpuSignal.push_back(context2GpuData->queueSubmissions[i].cpuSignal);
        context2GpuData->queueSubmissions[i].cpuSignalIsWaitedOnCounter += 1;
      }
    }
  }
  if (cpuSignal.size() > 0) {
    redCpuSignalWait(context, gpu, (unsigned)cpuSignal.size(), cpuSignal.data(), 1, outStatuses, optionalFile, optionalLine, optionalUserData);
  }
  if (cpuSignal.size() > 0) {
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    for (uint64_t i : queueSubmissionTicketArrayIndex) {
      context2GpuData->queueSubmissions[i].cpuSignalIsWaitedOnCounter -= 1;
      red2InternalQueueSubmissionsFreeFinishedCpuSignals_NonLocking(context2, gpu, i, optionalFile, optionalLine, optionalUserData);
    }
  }
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
void red2WaitForAllQueueSubmissionsToFinish(Red2Context context2, RedHandleGpu gpu, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  RedContext                context         = context2->context;
  Red2ContextInternalData * context2Data    = (Red2ContextInternalData *)context2->redgpu2InternalData;
  Red2GpuInternalData *     context2GpuData = (Red2GpuInternalData *)&context2Data->gpus[gpu];

  std::vector<uint64_t>           queueSubmissionTicketArrayIndex;
  std::vector<RedHandleCpuSignal> cpuSignal;
  {
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    for (size_t i = 0, count = context2GpuData->queueSubmissions.size(); i < count; i += 1) {
      uint64_t ticket = context2GpuData->queueSubmissionsTicket[i];
      if (ticket != 0) {
        queueSubmissionTicketArrayIndex.push_back(i);
        cpuSignal.push_back(context2GpuData->queueSubmissions[i].cpuSignal);
        context2GpuData->queueSubmissions[i].cpuSignalIsWaitedOnCounter += 1;
      }
    }
  }
  if (cpuSignal.size() > 0) {
    redCpuSignalWait(context, gpu, (unsigned)cpuSignal.size(), cpuSignal.data(), 1, outStatuses, optionalFile, optionalLine, optionalUserData);
  }
  if (cpuSignal.size() > 0) {
    std::lock_guard<std::mutex> queueSubmissionsMutexLockGuard(context2GpuData->queueSubmissionsMutex);
    for (uint64_t i : queueSubmissionTicketArrayIndex) {
      context2GpuData->queueSubmissions[i].cpuSignalIsWaitedOnCounter -= 1;
      red2InternalQueueSubmissionsFreeFinishedCpuSignals_NonLocking(context2, gpu, i, optionalFile, optionalLine, optionalUserData);
    }
  }
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
RedHandleStructDeclaration red2StructDeclarationGetRedHandle(Red2HandleStructDeclaration structDeclaration) {
  Red2InternalTypeStructDeclaration * handle = (Red2InternalTypeStructDeclaration *)(void *)structDeclaration;
  return handle->handle;
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
Red2StructDeclarationMember * red2StructDeclarationGetMembersPointer(Red2HandleStructDeclaration structDeclaration) {
  Red2InternalTypeStructDeclaration * handle = (Red2InternalTypeStructDeclaration *)(void *)structDeclaration;
  return handle->structDeclarationMembers;
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
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

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
RedHandleProcedureParameters red2ProcedureParametersGetRedHandle(Red2HandleProcedureParameters procedureParameters) {
  Red2InternalTypeProcedureParameters * handle = (Red2InternalTypeProcedureParameters *)(void *)procedureParameters;
  return handle->handle;
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
Red2HandleStructDeclaration red2ProcedureParametersGetStructDeclaration(Red2HandleProcedureParameters procedureParameters, unsigned structIndex) {
  Red2InternalTypeProcedureParameters * handle = (Red2InternalTypeProcedureParameters *)(void *)procedureParameters;
  return handle->structsDeclarations[structIndex];
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
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

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
uint64_t * red2CallsGetHandlesToDestroy(Red2HandleCalls calls, uint64_t * outHandlesToDestroyWhenCallsAreResetCount) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  if (outHandlesToDestroyWhenCallsAreResetCount != NULL) {
    outHandlesToDestroyWhenCallsAreResetCount[0] = (uint64_t)handle->handlesToDestroyWhenCallsAreReset.size();
  }
  return handle->handlesToDestroyWhenCallsAreReset.data(); // NOTE(Constantine): Do not store this returned pointer on user side, it's not stable after each append.
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
unsigned * red2CallsGetHandlesToDestroyType(Red2HandleCalls calls, uint64_t * outHandlesToDestroyWhenCallsAreResetTypeCount) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  if (outHandlesToDestroyWhenCallsAreResetTypeCount != NULL) {
    outHandlesToDestroyWhenCallsAreResetTypeCount[0] = (uint64_t)handle->handlesToDestroyWhenCallsAreResetType.size();
  }
  return handle->handlesToDestroyWhenCallsAreResetType.data(); // NOTE(Constantine): Do not store this returned pointer on user side, it's not stable after each append.
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
void red2CallsSetHandlesToDestroyCustomCallback(Red2HandleCalls calls, void * optionalCustomHandleAndHandleTypeDestroyWhenCallsAreResetCallback) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  handle->handlesToDestroyWhenCallsAreResetCustomCallback = optionalCustomHandleAndHandleTypeDestroyWhenCallsAreResetCallback;
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
void red2CallsGetQueueSubmitTrackableTicket(Red2HandleCalls calls, uint64_t * outQueueSubmissionTicketArrayIndex, uint64_t * outQueueSubmissionTicket) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  if (outQueueSubmissionTicketArrayIndex != NULL) { outQueueSubmissionTicketArrayIndex[0] = handle->lastQueueSubmitTrackableTicketArrayIndex; }
  if (outQueueSubmissionTicket           != NULL) { outQueueSubmissionTicket[0]           = handle->lastQueueSubmitTrackableTicket;           }
}

// NOTE(Constantine):
// A new REDGPU 2 procedure.
// 
// This function is optional.
void red2CallsSetQueueSubmitTrackableTicket(Red2HandleCalls calls, uint64_t queueSubmissionTicketArrayIndex, uint64_t queueSubmissionTicket) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  handle->lastQueueSubmitTrackableTicketArrayIndex = queueSubmissionTicketArrayIndex;
  handle->lastQueueSubmitTrackableTicket           = queueSubmissionTicket;
}

void red2CallResolveDepthStencilTexture(const RedCallProceduresAndAddresses * addresses, Red2HandleCalls calls, unsigned width, unsigned height, RedHandleTexture sourceDepthStencilTexture, RedFormat sourceDepthStencilTextureFormatRedOnly, RedMultisampleCountBitflag sourceDepthStencilTextureMultisampleCount, RedHandleTexture targetDepthStencilTexture, unsigned targetDepthStencilTextureFormatRedXOnly, RedResolveMode depthResolveModeRedOnly, RedResolveMode stencilResolveModeRedOnly, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
#ifdef REDGPU_USE_REDGPU_X
  RedSetProcedureOutputOp colorsSetOps[8] /*---*/;
  colorsSetOps[0] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[1] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[2] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[3] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[4] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[5] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[6] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[7] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  // NOTE(Constantine):
  // For REDGPU X, as of 28 Nov 2024, need to pass depth stencil
  // texture via color render target slot to resolve them.
  redXCallSetProcedureOutput(handle->handle, NULL, 1, (RedHandleTexture *)&sourceDepthStencilTexture, RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE, RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE, colorsSetOps, 0, 0, NULL);
#else
  RedHandleOutputDeclaration  outputDeclaration = NULL;
  RedOutputDeclarationMembers members /*---*/;
  {
    members.depthStencilEnable                        = 1;
    members.depthStencilFormat                        = sourceDepthStencilTextureFormatRedOnly;
    members.depthStencilMultisampleCount              = sourceDepthStencilTextureMultisampleCount;
    members.depthStencilDepthSetProcedureOutputOp     = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilDepthEndProcedureOutputOp     = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilStencilSetProcedureOutputOp   = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilStencilEndProcedureOutputOp   = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilSharesMemoryWithAnotherMember = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsCount                               = 0;
    members.colorsFormat[0]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[1]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[2]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[3]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[4]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[5]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[6]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[7]                           = RED_FORMAT_UNDEFINED;
    members.colorsMultisampleCount[0]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[1]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[2]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[3]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[4]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[5]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[6]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[7]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsSetProcedureOutputOp[0]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[1]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[2]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[3]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[4]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[5]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[6]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[7]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[0]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[1]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[2]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[3]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[4]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[5]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[6]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[7]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSharesMemoryWithAnotherMember[0]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[1]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[2]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[3]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[4]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[5]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[6]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[7]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    RedBool32 dependencyByRegion = 0;
    RedBool32 dependencyByRegionAllowUsageAliasOrderBarriers = 0;
    RedOutputDeclarationMembersResolveSources resolveSources /*---*/;
    resolveSources.resolveModeDepth    = depthResolveModeRedOnly;
    resolveSources.resolveModeStencil  = stencilResolveModeRedOnly;
    resolveSources.resolveDepthStencil = 1;
    resolveSources.resolveColors       = 0;
    redCreateOutputDeclaration(handle->context, handle->gpu, NULL, &members, &resolveSources, dependencyByRegion, dependencyByRegionAllowUsageAliasOrderBarriers, &outputDeclaration, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (outputDeclaration == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      return;
    }
    red2CallsAppendHandleToDestroy(calls, (uint64_t)outputDeclaration, RED_HANDLE_TYPE_OUTPUT_DECLARATION);
  }

  RedOutput output = {};
  {
    RedOutputMembers outputMembers /*---*/;
    outputMembers.depthStencil = sourceDepthStencilTexture;
    outputMembers.colorsCount  = 0;
    outputMembers.colors[0]    = NULL;
    outputMembers.colors[1]    = NULL;
    outputMembers.colors[2]    = NULL;
    outputMembers.colors[3]    = NULL;
    outputMembers.colors[4]    = NULL;
    outputMembers.colors[5]    = NULL;
    outputMembers.colors[6]    = NULL;
    outputMembers.colors[7]    = NULL;
    RedOutputMembersResolveTargets resolveTargets /*---*/;
    resolveTargets.depthStencil = targetDepthStencilTexture;
    resolveTargets.colors[0]    = NULL;
    resolveTargets.colors[1]    = NULL;
    resolveTargets.colors[2]    = NULL;
    resolveTargets.colors[3]    = NULL;
    resolveTargets.colors[4]    = NULL;
    resolveTargets.colors[5]    = NULL;
    resolveTargets.colors[6]    = NULL;
    resolveTargets.colors[7]    = NULL;
    redCreateOutput(handle->context, handle->gpu, NULL, outputDeclaration, &outputMembers, &resolveTargets, width, height, &output, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (output.handle == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      return;
    }
    red2CallsAppendHandleToDestroy(calls, (uint64_t)output.handle, RED_HANDLE_TYPE_OUTPUT);
  }

  redCallSetProcedureOutput(addresses->redCallSetProcedureOutput, handle->handle, outputDeclaration, output.handle, NULL, output.width, output.height, members.depthStencilEnable, members.colorsCount, 0, 0, NULL, NULL, NULL);
#endif

#ifdef REDGPU_USE_REDGPU_X
  RedEndProcedureOutputOp colorsEndOps[8] /*---*/;
  colorsEndOps[0] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[1] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[2] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[3] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[4] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[5] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[6] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[7] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  // NOTE(Constantine):
  // For REDGPU X, as of 28 Nov 2024, need to pass depth stencil
  // texture via color render target slot to resolve them.
  redXCallEndProcedureOutput(handle->handle, &targetDepthStencilTexture, &targetDepthStencilTextureFormatRedXOnly, RED_END_PROCEDURE_OUTPUT_OP_PRESERVE, RED_END_PROCEDURE_OUTPUT_OP_PRESERVE, colorsEndOps);
#else
  redCallEndProcedureOutput(addresses->redCallEndProcedureOutput, handle->handle);
#endif
}

void red2CallResolveColorTexture(const RedCallProceduresAndAddresses * addresses, Red2HandleCalls calls, unsigned width, unsigned height, RedHandleTexture sourceColorTexture, RedFormat sourceColorTextureFormatRedOnly, RedMultisampleCountBitflag sourceColorTextureMultisampleCount, RedHandleTexture targetColorTexture, unsigned targetColorTextureFormatRedXOnly, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
#ifdef REDGPU_USE_REDGPU_X
  RedSetProcedureOutputOp colorsSetOps[8] /*---*/;
  colorsSetOps[0] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[1] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[2] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[3] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[4] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[5] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[6] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[7] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  redXCallSetProcedureOutput(handle->handle, NULL, 1, (RedHandleTexture *)sourceColorTexture, RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE, RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE, colorsSetOps, 0, 0, NULL);
#else
  RedHandleOutputDeclaration  outputDeclaration = NULL;
  RedOutputDeclarationMembers members /*---*/;
  {
    members.depthStencilEnable                        = 0;
    members.depthStencilFormat                        = RED_FORMAT_UNDEFINED;
    members.depthStencilMultisampleCount              = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.depthStencilDepthSetProcedureOutputOp     = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilDepthEndProcedureOutputOp     = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilStencilSetProcedureOutputOp   = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilStencilEndProcedureOutputOp   = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilSharesMemoryWithAnotherMember = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsCount                               = 1;
    members.colorsFormat[0]                           = sourceColorTextureFormatRedOnly;
    members.colorsFormat[1]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[2]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[3]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[4]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[5]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[6]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[7]                           = RED_FORMAT_UNDEFINED;
    members.colorsMultisampleCount[0]                 = sourceColorTextureMultisampleCount;
    members.colorsMultisampleCount[1]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[2]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[3]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[4]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[5]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[6]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[7]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsSetProcedureOutputOp[0]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[1]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[2]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[3]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[4]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[5]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[6]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[7]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[0]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[1]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[2]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[3]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[4]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[5]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[6]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[7]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSharesMemoryWithAnotherMember[0]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[1]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[2]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[3]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[4]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[5]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[6]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[7]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    RedBool32 dependencyByRegion = 0;
    RedBool32 dependencyByRegionAllowUsageAliasOrderBarriers = 0;
    RedOutputDeclarationMembersResolveSources resolveSources /*---*/;
    resolveSources.resolveModeDepth    = RED_RESOLVE_MODE_NONE;
    resolveSources.resolveModeStencil  = RED_RESOLVE_MODE_NONE;
    resolveSources.resolveDepthStencil = 0;
    resolveSources.resolveColors       = 1;
    redCreateOutputDeclaration(handle->context, handle->gpu, NULL, &members, &resolveSources, dependencyByRegion, dependencyByRegionAllowUsageAliasOrderBarriers, &outputDeclaration, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (outputDeclaration == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      return;
    }
    red2CallsAppendHandleToDestroy(calls, (uint64_t)outputDeclaration, RED_HANDLE_TYPE_OUTPUT_DECLARATION);
  }

  RedOutput output = {};
  {
    RedOutputMembers outputMembers /*---*/;
    outputMembers.depthStencil = NULL;
    outputMembers.colorsCount  = 1;
    outputMembers.colors[0]    = sourceColorTexture;
    outputMembers.colors[1]    = NULL;
    outputMembers.colors[2]    = NULL;
    outputMembers.colors[3]    = NULL;
    outputMembers.colors[4]    = NULL;
    outputMembers.colors[5]    = NULL;
    outputMembers.colors[6]    = NULL;
    outputMembers.colors[7]    = NULL;
    RedOutputMembersResolveTargets resolveTargets /*---*/;
    resolveTargets.depthStencil = NULL;
    resolveTargets.colors[0]    = targetColorTexture;
    resolveTargets.colors[1]    = NULL;
    resolveTargets.colors[2]    = NULL;
    resolveTargets.colors[3]    = NULL;
    resolveTargets.colors[4]    = NULL;
    resolveTargets.colors[5]    = NULL;
    resolveTargets.colors[6]    = NULL;
    resolveTargets.colors[7]    = NULL;
    redCreateOutput(handle->context, handle->gpu, NULL, outputDeclaration, &outputMembers, &resolveTargets, width, height, &output, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (output.handle == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      return;
    }
    red2CallsAppendHandleToDestroy(calls, (uint64_t)output.handle, RED_HANDLE_TYPE_OUTPUT);
  }

  redCallSetProcedureOutput(addresses->redCallSetProcedureOutput, handle->handle, outputDeclaration, output.handle, NULL, output.width, output.height, members.depthStencilEnable, members.colorsCount, 0, 0, NULL, NULL, NULL);
#endif

#ifdef REDGPU_USE_REDGPU_X
  RedEndProcedureOutputOp colorsEndOps[8] /*---*/;
  colorsEndOps[0] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[1] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[2] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[3] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[4] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[5] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[6] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[7] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  redXCallEndProcedureOutput(handle->handle, &targetColorTexture, &targetColorTextureFormatRedXOnly, RED_END_PROCEDURE_OUTPUT_OP_PRESERVE, RED_END_PROCEDURE_OUTPUT_OP_PRESERVE, colorsEndOps);
#else
  redCallEndProcedureOutput(addresses->redCallEndProcedureOutput, handle->handle);
#endif
}

void red2CallClearDepthStencilTexture(const RedCallProceduresAndAddresses * addresses, Red2HandleCalls calls, unsigned width, unsigned height, RedHandleTexture depthStencilTexture, RedFormat depthStencilTextureFormatRedOnly, RedMultisampleCountBitflag depthStencilTextureMultisampleCount, RedBool32 clearDepth, float depthClearValue, RedBool32 clearStencil, unsigned stencilClearValue, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
#ifdef REDGPU_USE_REDGPU_X
  RedSetProcedureOutputOp colorsSetOps[8] /*---*/;
  colorsSetOps[0] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[1] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[2] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[3] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[4] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[5] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[6] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[7] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  redXCallSetProcedureOutput(handle->handle, depthStencilTexture, 0, NULL, clearDepth == 1 ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE, clearStencil == 1 ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE, colorsSetOps, depthClearValue, stencilClearValue, NULL);
#else
  RedHandleOutputDeclaration  outputDeclaration = NULL;
  RedOutputDeclarationMembers members /*---*/;
  {
    members.depthStencilEnable                        = 1;
    members.depthStencilFormat                        = depthStencilTextureFormatRedOnly;
    members.depthStencilMultisampleCount              = depthStencilTextureMultisampleCount;
    members.depthStencilDepthSetProcedureOutputOp     = clearDepth   == 1 ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilDepthEndProcedureOutputOp     = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilStencilSetProcedureOutputOp   = clearStencil == 1 ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilStencilEndProcedureOutputOp   = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilSharesMemoryWithAnotherMember = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsCount                               = 0;
    members.colorsFormat[0]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[1]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[2]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[3]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[4]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[5]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[6]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[7]                           = RED_FORMAT_UNDEFINED;
    members.colorsMultisampleCount[0]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[1]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[2]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[3]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[4]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[5]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[6]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[7]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsSetProcedureOutputOp[0]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[1]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[2]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[3]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[4]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[5]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[6]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSetProcedureOutputOp[7]             = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[0]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[1]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[2]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[3]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[4]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[5]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[6]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[7]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSharesMemoryWithAnotherMember[0]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[1]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[2]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[3]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[4]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[5]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[6]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[7]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    RedBool32 dependencyByRegion = 0;
    RedBool32 dependencyByRegionAllowUsageAliasOrderBarriers = 0;
    redCreateOutputDeclaration(handle->context, handle->gpu, NULL, &members, NULL, dependencyByRegion, dependencyByRegionAllowUsageAliasOrderBarriers, &outputDeclaration, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (outputDeclaration == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      return;
    }
    red2CallsAppendHandleToDestroy(calls, (uint64_t)outputDeclaration, RED_HANDLE_TYPE_OUTPUT_DECLARATION);
  }

  RedOutput output = {};
  {
    RedOutputMembers outputMembers /*---*/;
    outputMembers.depthStencil = depthStencilTexture;
    outputMembers.colorsCount  = members.colorsCount;
    outputMembers.colors[0]    = NULL;
    outputMembers.colors[1]    = NULL;
    outputMembers.colors[2]    = NULL;
    outputMembers.colors[3]    = NULL;
    outputMembers.colors[4]    = NULL;
    outputMembers.colors[5]    = NULL;
    outputMembers.colors[6]    = NULL;
    outputMembers.colors[7]    = NULL;
    redCreateOutput(handle->context, handle->gpu, NULL, outputDeclaration, &outputMembers, NULL, width, height, &output, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (output.handle == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      return;
    }
    red2CallsAppendHandleToDestroy(calls, (uint64_t)output.handle, RED_HANDLE_TYPE_OUTPUT);
  }

  redCallSetProcedureOutput(addresses->redCallSetProcedureOutput, handle->handle, outputDeclaration, output.handle, NULL, output.width, output.height, members.depthStencilEnable, members.colorsCount, depthClearValue, stencilClearValue, NULL, NULL, NULL);
#endif

#ifdef REDGPU_USE_REDGPU_X
  RedEndProcedureOutputOp colorsEndOps[8] /*---*/;
  colorsEndOps[0] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[1] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[2] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[3] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[4] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[5] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[6] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[7] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  redXCallEndProcedureOutput(handle->handle, NULL, NULL, RED_END_PROCEDURE_OUTPUT_OP_PRESERVE, RED_END_PROCEDURE_OUTPUT_OP_PRESERVE, colorsEndOps);
#else
  redCallEndProcedureOutput(addresses->redCallEndProcedureOutput, handle->handle);
#endif
}

void red2CallClearColorTexture(const RedCallProceduresAndAddresses * addresses, Red2HandleCalls calls, unsigned width, unsigned height, RedHandleTexture colorTexture, RedFormat colorTextureFormatRedOnly, RedMultisampleCountBitflag colorTextureMultisampleCount, float colorClearValueR, float colorClearValueG, float colorClearValueB, float colorClearValueA, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
  RedColorsClearValuesFloat colorsClearValuesFloat /*---*/;
  colorsClearValuesFloat.r[0] = colorClearValueR;
  colorsClearValuesFloat.g[0] = colorClearValueG;
  colorsClearValuesFloat.b[0] = colorClearValueB;
  colorsClearValuesFloat.a[0] = colorClearValueA;
  // NOTE(Constantine): Not setting clear values for other render targets.
#ifdef REDGPU_USE_REDGPU_X
  RedSetProcedureOutputOp colorsSetOps[8] /*---*/;
  colorsSetOps[0] = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
  colorsSetOps[1] = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
  colorsSetOps[2] = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
  colorsSetOps[3] = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
  colorsSetOps[4] = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
  colorsSetOps[5] = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
  colorsSetOps[6] = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
  colorsSetOps[7] = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
  redXCallSetProcedureOutput(handle->handle, NULL, 1, (RedHandleTexture *)&colorTexture, RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE, RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE, colorsSetOps, 0, 0, &colorsClearValuesFloat);
#else
  RedHandleOutputDeclaration  outputDeclaration = NULL;
  RedOutputDeclarationMembers members /*---*/;
  {
    members.depthStencilEnable                        = 0;
    members.depthStencilFormat                        = RED_FORMAT_UNDEFINED;
    members.depthStencilMultisampleCount              = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.depthStencilDepthSetProcedureOutputOp     = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilDepthEndProcedureOutputOp     = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilStencilSetProcedureOutputOp   = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilStencilEndProcedureOutputOp   = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.depthStencilSharesMemoryWithAnotherMember = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsCount                               = 1;
    members.colorsFormat[0]                           = colorTextureFormatRedOnly;
    members.colorsFormat[1]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[2]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[3]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[4]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[5]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[6]                           = RED_FORMAT_UNDEFINED;
    members.colorsFormat[7]                           = RED_FORMAT_UNDEFINED;
    members.colorsMultisampleCount[0]                 = colorTextureMultisampleCount;
    members.colorsMultisampleCount[1]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[2]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[3]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[4]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[5]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[6]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[7]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsSetProcedureOutputOp[0]             = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
    members.colorsSetProcedureOutputOp[1]             = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
    members.colorsSetProcedureOutputOp[2]             = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
    members.colorsSetProcedureOutputOp[3]             = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
    members.colorsSetProcedureOutputOp[4]             = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
    members.colorsSetProcedureOutputOp[5]             = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
    members.colorsSetProcedureOutputOp[6]             = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
    members.colorsSetProcedureOutputOp[7]             = RED_SET_PROCEDURE_OUTPUT_OP_CLEAR;
    members.colorsEndProcedureOutputOp[0]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[1]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[2]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[3]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[4]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[5]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[6]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsEndProcedureOutputOp[7]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    members.colorsSharesMemoryWithAnotherMember[0]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[1]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[2]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[3]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[4]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[5]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[6]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[7]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    RedBool32 dependencyByRegion = 0;
    RedBool32 dependencyByRegionAllowUsageAliasOrderBarriers = 0;
    redCreateOutputDeclaration(handle->context, handle->gpu, NULL, &members, NULL, dependencyByRegion, dependencyByRegionAllowUsageAliasOrderBarriers, &outputDeclaration, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (outputDeclaration == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      return;
    }
    red2CallsAppendHandleToDestroy(calls, (uint64_t)outputDeclaration, RED_HANDLE_TYPE_OUTPUT_DECLARATION);
  }

  RedOutput output = {};
  {
    RedOutputMembers outputMembers /*---*/;
    outputMembers.depthStencil = NULL;
    outputMembers.colorsCount  = members.colorsCount;
    outputMembers.colors[0]    = colorTexture;
    outputMembers.colors[1]    = NULL;
    outputMembers.colors[2]    = NULL;
    outputMembers.colors[3]    = NULL;
    outputMembers.colors[4]    = NULL;
    outputMembers.colors[5]    = NULL;
    outputMembers.colors[6]    = NULL;
    outputMembers.colors[7]    = NULL;
    redCreateOutput(handle->context, handle->gpu, NULL, outputDeclaration, &outputMembers, NULL, width, height, &output, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (output.handle == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      return;
    }
    red2CallsAppendHandleToDestroy(calls, (uint64_t)output.handle, RED_HANDLE_TYPE_OUTPUT);
  }

  redCallSetProcedureOutput(addresses->redCallSetProcedureOutput, handle->handle, outputDeclaration, output.handle, NULL, output.width, output.height, members.depthStencilEnable, members.colorsCount, 0, 0, &colorsClearValuesFloat, NULL, NULL);
#endif

#ifdef REDGPU_USE_REDGPU_X
  RedEndProcedureOutputOp colorsEndOps[8] /*---*/;
  colorsEndOps[0] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[1] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[2] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[3] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[4] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[5] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[6] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[7] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  redXCallEndProcedureOutput(handle->handle, NULL, NULL, RED_END_PROCEDURE_OUTPUT_OP_PRESERVE, RED_END_PROCEDURE_OUTPUT_OP_PRESERVE, colorsEndOps);
#else
  redCallEndProcedureOutput(addresses->redCallEndProcedureOutput, handle->handle);
#endif
}

void red2RedXOnlyCallDiscardResource(const RedCallProceduresAndAddresses * addresses, Red2HandleCalls calls, void * handleResource, const void * optionalDiscardRegion) {
#ifdef REDGPU_USE_REDGPU_X
  // NOTE(Constantine):
  // https://learn.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-discardresource
  RedXInternalTypeCalls * handle = (RedXInternalTypeCalls *)calls;
  x12CommandListDiscardResource(handle->handle, (X12Resource *)handleResource, (const D3D12_DISCARD_REGION *)optionalDiscardRegion);
#endif
  volatile int nothing = 0;
}

void red2CallSetRenderTargets(const RedCallProceduresAndAddresses * addresses, Red2HandleCalls calls, unsigned width, unsigned height, RedHandleTexture depthStencilTexture, RedFormat depthStencilTextureFormatRedOnly, RedMultisampleCountBitflag depthStencilTextureMultisampleCount, unsigned colorsTextureCountMax8, const RedHandleTexture * colorsTexture, const RedFormat * colorsTextureFormatRedOnly, const RedMultisampleCountBitflag * colorsTextureMultisampleCount, const Red2RenderTargetsDiscard * optionalDiscardRedOnly, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
#ifdef REDGPU_USE_REDGPU_X
  RedSetProcedureOutputOp colorsSetOps[8] /*---*/;
  colorsSetOps[0] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[1] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[2] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[3] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[4] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[5] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[6] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsSetOps[7] = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  redXCallSetProcedureOutput(handle->handle, depthStencilTexture, colorsTextureCountMax8, (RedHandleTexture *)colorsTexture, RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE, RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE, colorsSetOps, 0, 0, NULL);
#else
  RedSetProcedureOutputOp setRenderTargetsColorsOp[8] = {
    RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE,
  };
  RedSetProcedureOutputOp setRenderTargetsDepthOp   = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
  RedSetProcedureOutputOp setRenderTargetsStencilOp = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;

  RedEndProcedureOutputOp endRenderTargetsColorsOp[8] = {
    RED_END_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_END_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_END_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_END_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_END_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_END_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_END_PROCEDURE_OUTPUT_OP_PRESERVE,
    RED_END_PROCEDURE_OUTPUT_OP_PRESERVE,
  };
  RedEndProcedureOutputOp endRenderTargetsDepthOp   = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  RedEndProcedureOutputOp endRenderTargetsStencilOp = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;

  if (optionalDiscardRedOnly != NULL) {
    if (optionalDiscardRedOnly->discardSetRenderTargetsColors[0] == 1) { setRenderTargetsColorsOp[0] = RED_SET_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardSetRenderTargetsColors[1] == 1) { setRenderTargetsColorsOp[1] = RED_SET_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardSetRenderTargetsColors[2] == 1) { setRenderTargetsColorsOp[2] = RED_SET_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardSetRenderTargetsColors[3] == 1) { setRenderTargetsColorsOp[3] = RED_SET_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardSetRenderTargetsColors[4] == 1) { setRenderTargetsColorsOp[4] = RED_SET_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardSetRenderTargetsColors[5] == 1) { setRenderTargetsColorsOp[5] = RED_SET_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardSetRenderTargetsColors[6] == 1) { setRenderTargetsColorsOp[6] = RED_SET_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardSetRenderTargetsColors[7] == 1) { setRenderTargetsColorsOp[7] = RED_SET_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardSetRenderTargetsDepth     == 1) { setRenderTargetsDepthOp     = RED_SET_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardSetRenderTargetsStencil   == 1) { setRenderTargetsStencilOp   = RED_SET_PROCEDURE_OUTPUT_OP_DISCARD; }

    if (optionalDiscardRedOnly->discardEndRenderTargetsColors[0] == 1) { endRenderTargetsColorsOp[0] = RED_END_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardEndRenderTargetsColors[1] == 1) { endRenderTargetsColorsOp[1] = RED_END_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardEndRenderTargetsColors[2] == 1) { endRenderTargetsColorsOp[2] = RED_END_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardEndRenderTargetsColors[3] == 1) { endRenderTargetsColorsOp[3] = RED_END_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardEndRenderTargetsColors[4] == 1) { endRenderTargetsColorsOp[4] = RED_END_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardEndRenderTargetsColors[5] == 1) { endRenderTargetsColorsOp[5] = RED_END_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardEndRenderTargetsColors[6] == 1) { endRenderTargetsColorsOp[6] = RED_END_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardEndRenderTargetsColors[7] == 1) { endRenderTargetsColorsOp[7] = RED_END_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardEndRenderTargetsDepth     == 1) { endRenderTargetsDepthOp     = RED_END_PROCEDURE_OUTPUT_OP_DISCARD; }
    if (optionalDiscardRedOnly->discardEndRenderTargetsStencil   == 1) { endRenderTargetsStencilOp   = RED_END_PROCEDURE_OUTPUT_OP_DISCARD; }
  }

  RedHandleOutputDeclaration outputDeclaration = NULL;
  {
    RedOutputDeclarationMembers members /*---*/;
    members.depthStencilEnable                        = depthStencilTexture == NULL ? 0 : 1;
    members.depthStencilFormat                        = depthStencilTextureFormatRedOnly;
    members.depthStencilMultisampleCount              = depthStencilTextureMultisampleCount;
    members.depthStencilDepthSetProcedureOutputOp     = setRenderTargetsDepthOp;
    members.depthStencilDepthEndProcedureOutputOp     = endRenderTargetsDepthOp;
    members.depthStencilStencilSetProcedureOutputOp   = setRenderTargetsStencilOp;
    members.depthStencilStencilEndProcedureOutputOp   = endRenderTargetsStencilOp;
    members.depthStencilSharesMemoryWithAnotherMember = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsCount                               = colorsTextureCountMax8;
    members.colorsFormat[0]                           = colorsTextureCountMax8 > 0 ? colorsTextureFormatRedOnly[0] : RED_FORMAT_UNDEFINED;
    members.colorsFormat[1]                           = colorsTextureCountMax8 > 1 ? colorsTextureFormatRedOnly[1] : RED_FORMAT_UNDEFINED;
    members.colorsFormat[2]                           = colorsTextureCountMax8 > 2 ? colorsTextureFormatRedOnly[2] : RED_FORMAT_UNDEFINED;
    members.colorsFormat[3]                           = colorsTextureCountMax8 > 3 ? colorsTextureFormatRedOnly[3] : RED_FORMAT_UNDEFINED;
    members.colorsFormat[4]                           = colorsTextureCountMax8 > 4 ? colorsTextureFormatRedOnly[4] : RED_FORMAT_UNDEFINED;
    members.colorsFormat[5]                           = colorsTextureCountMax8 > 5 ? colorsTextureFormatRedOnly[5] : RED_FORMAT_UNDEFINED;
    members.colorsFormat[6]                           = colorsTextureCountMax8 > 6 ? colorsTextureFormatRedOnly[6] : RED_FORMAT_UNDEFINED;
    members.colorsFormat[7]                           = colorsTextureCountMax8 > 7 ? colorsTextureFormatRedOnly[7] : RED_FORMAT_UNDEFINED;
    members.colorsMultisampleCount[0]                 = colorsTextureCountMax8 > 0 ? colorsTextureMultisampleCount[0] : RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[1]                 = colorsTextureCountMax8 > 1 ? colorsTextureMultisampleCount[1] : RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[2]                 = colorsTextureCountMax8 > 2 ? colorsTextureMultisampleCount[2] : RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[3]                 = colorsTextureCountMax8 > 3 ? colorsTextureMultisampleCount[3] : RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[4]                 = colorsTextureCountMax8 > 4 ? colorsTextureMultisampleCount[4] : RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[5]                 = colorsTextureCountMax8 > 5 ? colorsTextureMultisampleCount[5] : RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[6]                 = colorsTextureCountMax8 > 6 ? colorsTextureMultisampleCount[6] : RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsMultisampleCount[7]                 = colorsTextureCountMax8 > 7 ? colorsTextureMultisampleCount[7] : RED_MULTISAMPLE_COUNT_BITFLAG_1;
    members.colorsSetProcedureOutputOp[0]             = setRenderTargetsColorsOp[0];
    members.colorsSetProcedureOutputOp[1]             = setRenderTargetsColorsOp[1];
    members.colorsSetProcedureOutputOp[2]             = setRenderTargetsColorsOp[2];
    members.colorsSetProcedureOutputOp[3]             = setRenderTargetsColorsOp[3];
    members.colorsSetProcedureOutputOp[4]             = setRenderTargetsColorsOp[4];
    members.colorsSetProcedureOutputOp[5]             = setRenderTargetsColorsOp[5];
    members.colorsSetProcedureOutputOp[6]             = setRenderTargetsColorsOp[6];
    members.colorsSetProcedureOutputOp[7]             = setRenderTargetsColorsOp[7];
    members.colorsEndProcedureOutputOp[0]             = endRenderTargetsColorsOp[0];
    members.colorsEndProcedureOutputOp[1]             = endRenderTargetsColorsOp[1];
    members.colorsEndProcedureOutputOp[2]             = endRenderTargetsColorsOp[2];
    members.colorsEndProcedureOutputOp[3]             = endRenderTargetsColorsOp[3];
    members.colorsEndProcedureOutputOp[4]             = endRenderTargetsColorsOp[4];
    members.colorsEndProcedureOutputOp[5]             = endRenderTargetsColorsOp[5];
    members.colorsEndProcedureOutputOp[6]             = endRenderTargetsColorsOp[6];
    members.colorsEndProcedureOutputOp[7]             = endRenderTargetsColorsOp[7];
    members.colorsSharesMemoryWithAnotherMember[0]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[1]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[2]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[3]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[4]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[5]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[6]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    members.colorsSharesMemoryWithAnotherMember[7]    = 0; // NOTE(Constantine): Render targets are not allowed to alias for now.
    RedBool32 dependencyByRegion = 0;
    RedBool32 dependencyByRegionAllowUsageAliasOrderBarriers = 0;
    redCreateOutputDeclaration(handle->context, handle->gpu, NULL, &members, NULL, dependencyByRegion, dependencyByRegionAllowUsageAliasOrderBarriers, &outputDeclaration, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (outputDeclaration == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      return;
    }
    red2CallsAppendHandleToDestroy(calls, (uint64_t)outputDeclaration, RED_HANDLE_TYPE_OUTPUT_DECLARATION);
  }

  RedOutput output = {};
  {
    RedOutputMembers outputMembers /*---*/;
    outputMembers.depthStencil = depthStencilTexture;
    outputMembers.colorsCount  = colorsTextureCountMax8;
    outputMembers.colors[0]    = colorsTextureCountMax8 > 0 ? colorsTexture[0] : NULL;
    outputMembers.colors[1]    = colorsTextureCountMax8 > 1 ? colorsTexture[1] : NULL;
    outputMembers.colors[2]    = colorsTextureCountMax8 > 2 ? colorsTexture[2] : NULL;
    outputMembers.colors[3]    = colorsTextureCountMax8 > 3 ? colorsTexture[3] : NULL;
    outputMembers.colors[4]    = colorsTextureCountMax8 > 4 ? colorsTexture[4] : NULL;
    outputMembers.colors[5]    = colorsTextureCountMax8 > 5 ? colorsTexture[5] : NULL;
    outputMembers.colors[6]    = colorsTextureCountMax8 > 6 ? colorsTexture[6] : NULL;
    outputMembers.colors[7]    = colorsTextureCountMax8 > 7 ? colorsTexture[7] : NULL;
    redCreateOutput(handle->context, handle->gpu, NULL, outputDeclaration, &outputMembers, NULL, width, height, &output, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (output.handle == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      return;
    }
    red2CallsAppendHandleToDestroy(calls, (uint64_t)output.handle, RED_HANDLE_TYPE_OUTPUT);
  }

  redCallSetProcedureOutput(addresses->redCallSetProcedureOutput, handle->handle, outputDeclaration, output.handle, NULL, output.width, output.height, depthStencilTexture == NULL ? 0 : 1, colorsTextureCountMax8, 0, 0, NULL, NULL, NULL);
#endif
}

void red2CallEndRenderTargets(const RedCallProceduresAndAddresses * addresses, Red2HandleCalls calls) {
  Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
#ifdef REDGPU_USE_REDGPU_X
  RedEndProcedureOutputOp colorsEndOps[8] /*---*/;
  colorsEndOps[0] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[1] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[2] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[3] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[4] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[5] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[6] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  colorsEndOps[7] = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
  redXCallEndProcedureOutput(handle->handle, NULL, NULL, RED_END_PROCEDURE_OUTPUT_OP_PRESERVE, RED_END_PROCEDURE_OUTPUT_OP_PRESERVE, colorsEndOps);
#else
  redCallEndProcedureOutput(addresses->redCallEndProcedureOutput, handle->handle);
#endif
}

REDGPU_2_DECLSPEC void REDGPU_2_API red2CallAllocateAndSetInlineStructsMemory(
  const RedCallProceduresAndAddresses * addresses,
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

  if (maxStructsCount == 0 && maxStructsOfTypeSamplerCount == 0) {
    redCallSetStructsMemory(addresses->redCallSetStructsMemory, handle->handle, NULL, NULL);
    return;
  }

  if (maxStructsMembersOfTypeArrayROConstantCount  == 0 &&
      maxStructsMembersOfTypeArrayROOrArrayRWCount == 0 &&
      maxStructsMembersOfTypeTextureROCount        == 0 &&
      maxStructsMembersOfTypeTextureRWCount        == 0 &&
      maxStructsMembersOfTypeInlineSamplerCount    == 0 &&
      maxStructsMembersOfTypeSamplerCount          == 0)
  {
    redCallSetStructsMemory(addresses->redCallSetStructsMemory, handle->handle, NULL, NULL);
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

  redCallSetStructsMemory(addresses->redCallSetStructsMemory, handle->handle, structsMemory, structsMemorySamplers);
}

REDGPU_2_DECLSPEC void REDGPU_2_API red2CallAllocateAndSetInlineStructsMemoryFromProcedureParameters(
  const RedCallProceduresAndAddresses * addresses,
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
    addresses, 
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
  const RedCallProceduresAndAddresses * addresses,
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
  const RedProcedureId procedureId = RED_PROCEDURE_ID_UNDEFINED; // TODO(Constantine): Assign a RED2_PROCEDURE_ID.

  Red2InternalTypeCalls *               handle     = (Red2InternalTypeCalls *)(void *)calls;
  Red2InternalTypeProcedureParameters * parameters = (Red2InternalTypeProcedureParameters *)(void *)procedureParameters;

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
        outStatuses->statusErrorProcedureId    = (RedProcedureId)procedureId;
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
  if (structHandle == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
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

  addresses->redCallSetProcedureParametersStructs(handle->handle, procedureType, parameters->handle, structIndex, 1, &structHandle, 0, 0);

  return RED_STATUS_SUCCESS;
}

// REDGPU 2 new procedures from 28 Nov 2024:

RedXAccessBitflags red2RedXOnlyGetRedXAccessBitflagsFromRed(RedAccessBitflags access) {
  RedXAccessBitflags out = REDX_ACCESS_BITFLAG_COMMON;
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

void * red2RedXOnlyArrayGetHandleResource(RedHandleArray array) {
#ifdef REDGPU_USE_REDGPU_X
  return (void *)redXGetHandleResourceArray(NULL, NULL, array);
#else
  return 0;
#endif
}

void * red2RedXOnlyImageGetHandleResource(RedHandleImage image) {
#ifdef REDGPU_USE_REDGPU_X
  return (void *)redXGetHandleResourceImage(NULL, NULL, image);
#else
  return 0;
#endif
}

void red2CallGpuToCpuSignalSignal(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleGpuToCpuSignal signalGpuToCpuSignal, unsigned setTo8192) {
  addresses->redCallGpuToCpuSignalSignal(calls, signalGpuToCpuSignal, setTo8192);
}

void red2CallCopyArrayToArray(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleArray arrayR, RedHandleArray arrayW, unsigned rangesCount, const RedCopyArrayRange * ranges) {
  addresses->redCallCopyArrayToArray(calls, arrayR, arrayW, rangesCount, ranges);
}

void red2CallProcedure(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, unsigned vertexCount, unsigned instanceCount, unsigned vertexFirst, unsigned instanceFirst) {
  addresses->redCallProcedure(calls, vertexCount, instanceCount, vertexFirst, instanceFirst);
}

void red2CallProcedureIndexed(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, unsigned indexCount, unsigned instanceCount, unsigned indexFirst, int vertexBase, unsigned instanceFirst) {
  addresses->redCallProcedureIndexed(calls, indexCount, instanceCount, indexFirst, vertexBase, instanceFirst);
}

void red2CallProcedureCompute(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, unsigned workgroupsCountX, unsigned workgroupsCountY, unsigned workgroupsCountZ) {
  addresses->redCallProcedureCompute(calls, workgroupsCountX, workgroupsCountY, workgroupsCountZ);
}

void red2CallSetProcedure(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedure procedure) {
  addresses->redCallSetProcedure(calls, procedureType, procedure);
}

void red2CallSetProcedureIndices(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleArray array, uint64_t setTo0, unsigned setTo1) {
  addresses->redCallSetProcedureIndices(calls, array, setTo0, setTo1);
}

void red2CallSetProcedureParametersVariables(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleProcedureParameters procedureParameters, RedVisibleToStageBitflags visibleToStages, unsigned variablesBytesFirst, unsigned dataBytesCount, const void * data) {
  addresses->redCallSetProcedureParametersVariables(calls, procedureParameters, visibleToStages, variablesBytesFirst, dataBytesCount, data);
}

void red2CallSetProcedureParametersStructs(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedureParameters procedureParameters, unsigned procedureParametersDeclarationStructsDeclarationsFirst, unsigned structsCount, const RedHandleStruct * structs, unsigned setTo0, size_t setTo00) {
  addresses->redCallSetProcedureParametersStructs(calls, procedureType, procedureParameters, procedureParametersDeclarationStructsDeclarationsFirst, structsCount, structs, setTo0, setTo00);
}

void red2CallSetProcedureParametersHandles(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedureParameters procedureParameters, unsigned procedureParametersDeclarationStructsDeclarationsCount, unsigned handlesCount, const RedProcedureParametersHandle * handles) {
  addresses->redCallSetProcedureParametersHandles(calls, procedureType, procedureParameters, procedureParametersDeclarationStructsDeclarationsCount, handlesCount, handles);
}

void red2CallSetDynamicStencilReference(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedStencilFace face, unsigned reference) {
  addresses->redCallSetDynamicStencilReference(calls, face, reference);
}

void red2CallSetDynamicBlendConstants(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, const float * blendConstants) {
  addresses->redCallSetDynamicBlendConstants(calls, blendConstants);
}

void red2CallSetDynamicViewport(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, float x, float y, float width, float height, float depthMin, float depthMax) {
  redCallSetDynamicViewport(addresses->redCallSetDynamicViewport, calls, x, y, width, height, depthMin, depthMax);
}

void red2CallSetDynamicScissor(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, int x, int y, unsigned width, unsigned height) {
  redCallSetDynamicScissor(addresses->redCallSetDynamicScissor, calls, x, y, width, height);
}

void red2CallSetStructsMemory(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleStructsMemory structsMemory, RedHandleStructsMemory structsMemorySamplers) {
  redCallSetStructsMemory(addresses->redCallSetStructsMemory, calls, structsMemory, structsMemorySamplers);
}

void red2CallSetProcedureParameters(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedureParameters procedureParameters) {
  redCallSetProcedureParameters(addresses->redCallSetProcedureParameters, calls, procedureType, procedureParameters);
}

void red2CallMark(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, const char * mark) {
  redCallMark(addresses->redCallMark, calls, mark);
}

void red2CallMarkSet(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, const char * mark) {
  redCallMarkSet(addresses->redCallMarkSet, calls, mark);
}

void red2CallMarkEnd(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls) {
  redCallMarkEnd(addresses->redCallMarkEnd, calls);
}

void red2RedOnlyCallCopyImageToImage(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleImage imageR, unsigned setTo1, RedHandleImage imageW, unsigned setTo01, unsigned rangesCount, const RedCopyImageRange * ranges) {
#ifndef REDGPU_USE_REDGPU_X
  addresses->redCallCopyImageToImage(calls, imageR, setTo1, imageW, setTo01, rangesCount, ranges);
#endif
  volatile int nothing = 0;
}

void red2RedOnlyCallCopyArrayToImage(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleArray arrayR, RedHandleImage imageW, unsigned setTo1, unsigned rangesCount, const RedCopyArrayImageRange * ranges) {
#ifndef REDGPU_USE_REDGPU_X
  addresses->redCallCopyArrayToImage(calls, arrayR, imageW, setTo1, rangesCount, ranges);
#endif
  volatile int nothing = 0;
}

void red2RedOnlyCallCopyImageToArray(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedHandleImage imageR, unsigned setTo1, RedHandleArray arrayW, unsigned rangesCount, const RedCopyArrayImageRange * ranges) {
#ifndef REDGPU_USE_REDGPU_X
  addresses->redCallCopyImageToArray(calls, imageR, setTo1, arrayW, rangesCount, ranges);
#endif
  volatile int nothing = 0;
}

void red2RedXOnlyCallCopyImageRegion(RedHandleCalls calls, unsigned copiesCount, const void * copies) {
#ifdef REDGPU_USE_REDGPU_X
  redXCallCopyImageRegion(calls, copiesCount, copies);
#endif
  volatile int nothing = 0;
}

void red2RedOnlyCallBarrierUsageAliasOrder(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedContext context, unsigned arrayUsagesCount, const RedUsageArray * arrayUsages, unsigned imageUsagesCount, const RedUsageImage * imageUsages, RedBool32 dependencyByRegion) {
#ifndef REDGPU_USE_REDGPU_X
  redCallUsageAliasOrderBarrier(addresses->redCallUsageAliasOrderBarrier, calls, context, arrayUsagesCount, arrayUsages, imageUsagesCount, imageUsages, 0, NULL, 0, NULL, dependencyByRegion);
#endif
  volatile int nothing = 0;
}

void red2RedXOnlyCallBarrierUsageAliasOrder(RedHandleCalls calls, unsigned barriersCount, const void * barriers) {
#ifdef REDGPU_USE_REDGPU_X
  redXCallUsageAliasOrderBarrier(calls, barriersCount, barriers);
#endif
  volatile int nothing = 0;
}

RedStatus red2RedOnlyCallDiscardImageAndSetState(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedContext context, unsigned imagesCount, const RedHandleImage * images, RedImagePartBitflags imagesAllParts, RedState state) {
#ifndef REDGPU_USE_REDGPU_X
  RedUsageImage * imageUsages = NULL;
  if (imagesCount > 0) {
    imageUsages = new(std::nothrow) RedUsageImage[imagesCount] /*---*/;
    if (imageUsages == NULL) {
      return RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
    }
  }
  for (unsigned i = 0; i < imagesCount; i += 1) {
    imageUsages[i].barrierSplit           = RED_BARRIER_SPLIT_NONE;
    imageUsages[i].oldAccessStages        = 0;
    imageUsages[i].newAccessStages        = 0;
    imageUsages[i].oldAccess              = 0;
    imageUsages[i].newAccess              = 0;
    imageUsages[i].oldState               = RED_STATE_UNUSABLE;
    imageUsages[i].newState               = state;
    imageUsages[i].queueFamilyIndexSource =-1;
    imageUsages[i].queueFamilyIndexTarget =-1;
    imageUsages[i].image                  = images[i];
    imageUsages[i].imageAllParts          = imagesAllParts;
    imageUsages[i].imageLevelsFirst       = 0;
    imageUsages[i].imageLevelsCount       =-1;
    imageUsages[i].imageLayersFirst       = 0;
    imageUsages[i].imageLayersCount       =-1;
  }
  redCallUsageAliasOrderBarrier(addresses->redCallUsageAliasOrderBarrier, calls, context, 0, NULL, imagesCount, imageUsages, 0, NULL, 0, NULL, 0);
  if (imageUsages != NULL) { delete[] imageUsages; }
#endif
  return RED_STATUS_SUCCESS;
}

#ifndef REDGPU_USE_REDGPU_X
#include "redgpu_vk.h"
#endif

RedStatus red2RedOnlyCallBarrierFinishCpuUpload(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, unsigned arraysCount, const RedHandleArray * arrays) {
#ifndef REDGPU_USE_REDGPU_X
  unsigned                bufferBarriersCount = arraysCount;
  VkBufferMemoryBarrier * bufferBarriers      = NULL;
  if (bufferBarriersCount > 0) {
    bufferBarriers = new(std::nothrow) VkBufferMemoryBarrier [bufferBarriersCount] /*---*/;
    if (bufferBarriers == NULL) {
      return RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
    }
  }
  for (unsigned i = 0; i < bufferBarriersCount; i += 1) {
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
  ((PFN_vkCmdPipelineBarrier)((void *)addresses->redCallUsageAliasOrderBarrier))((VkCommandBuffer)calls, VK_PIPELINE_STAGE_HOST_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, 0, 0, NULL, bufferBarriersCount, bufferBarriers, 0, NULL);
  if (bufferBarriers != NULL) { delete[] bufferBarriers; }
#endif
  return RED_STATUS_SUCCESS;
}

RedStatus red2RedOnlyCallBarrierFinishCpuReadback(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, unsigned arraysCount, const RedHandleArray * arrays) {
#ifndef REDGPU_USE_REDGPU_X
  unsigned                bufferBarriersCount = arraysCount;
  VkBufferMemoryBarrier * bufferBarriers      = NULL;
  if (bufferBarriersCount > 0) {
    bufferBarriers = new(std::nothrow) VkBufferMemoryBarrier [bufferBarriersCount] /*---*/;
    if (bufferBarriers == NULL) {
      return RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
    }
  }
  for (unsigned i = 0; i < bufferBarriersCount; i += 1) {
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
  ((PFN_vkCmdPipelineBarrier)((void *)addresses->redCallUsageAliasOrderBarrier))((VkCommandBuffer)calls, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_PIPELINE_STAGE_HOST_BIT, 0, 0, NULL, bufferBarriersCount, bufferBarriers, 0, NULL);
  if (bufferBarriers != NULL) { delete[] bufferBarriers; }
#endif
  return RED_STATUS_SUCCESS;
}

void red2CallBarrierOrderGlobalMemory(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls) {
#ifdef REDGPU_USE_REDGPU_X
  RedXBarrier barrier = {};
  barrier.order.setTo2   = 2;
  barrier.order.split    = RED_BARRIER_SPLIT_NONE;
  barrier.order.resource = NULL;
  redXCallUsageAliasOrderBarrier(calls, 1, &barrier);
#else
  VkMemoryBarrier globalBarrier /*---*/;
  globalBarrier.sType         = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
  globalBarrier.pNext         = NULL;
  globalBarrier.srcAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
  globalBarrier.dstAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
  ((PFN_vkCmdPipelineBarrier)((void *)addresses->redCallUsageAliasOrderBarrier))((VkCommandBuffer)calls, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, 0, 1, &globalBarrier, 0, NULL, 0, NULL);
#endif
}

RedStatus red2CallBarrierOrderResourceMemory(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, unsigned arraysCount, const RedHandleArray * arrays, unsigned imagesCount, const RedHandleImage * images, const RedImagePartBitflags * imagesAllParts) {
#ifdef REDGPU_USE_REDGPU_X
  unsigned      bufferBarriersCount = arraysCount;
  RedXBarrier * bufferBarriers      = NULL;
  unsigned      imageBarriersCount  = imagesCount;
  RedXBarrier * imageBarriers       = NULL;
  if (bufferBarriersCount > 0) {
    bufferBarriers = new(std::nothrow) RedXBarrier [bufferBarriersCount]();
    if (bufferBarriers == NULL) {
      return RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
    }
  }
  if (imageBarriersCount > 0) {
    imageBarriers = new(std::nothrow) RedXBarrier [imageBarriersCount]();
    if (imageBarriers == NULL) {
      if (bufferBarriers != NULL) { delete[] bufferBarriers; }
      return RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
    }
  }
  for (unsigned i = 0; i < bufferBarriersCount; i += 1) {
    bufferBarriers[i].order.setTo2   = 2;
    bufferBarriers[i].order.split    = RED_BARRIER_SPLIT_NONE;
    bufferBarriers[i].order.resource = redXGetHandleResourceArray(NULL, NULL, arrays[i]);
  }
  for (unsigned i = 0; i < imageBarriersCount; i += 1) {
    imageBarriers[i].order.setTo2    = 2;
    imageBarriers[i].order.split     = RED_BARRIER_SPLIT_NONE;
    imageBarriers[i].order.resource  = redXGetHandleResourceImage(NULL, NULL, images[i]);
  }
  if (bufferBarriersCount > 0) { redXCallUsageAliasOrderBarrier(calls, bufferBarriersCount, bufferBarriers); }
  if (imageBarriersCount  > 0) { redXCallUsageAliasOrderBarrier(calls, imageBarriersCount,  imageBarriers);  }
  if (bufferBarriers != NULL) { delete[] bufferBarriers; }
  if (imageBarriers  != NULL) { delete[] imageBarriers;  }
#else
  unsigned                bufferBarriersCount = arraysCount;
  VkBufferMemoryBarrier * bufferBarriers      = NULL;
  unsigned                imageBarriersCount  = imagesCount;
  VkImageMemoryBarrier *  imageBarriers       = NULL;
  if (bufferBarriersCount > 0) {
    bufferBarriers = new(std::nothrow) VkBufferMemoryBarrier [bufferBarriersCount] /*---*/;
    if (bufferBarriers == NULL) {
      return RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
    }
  }
  if (imageBarriersCount > 0) {
    imageBarriers = new(std::nothrow) VkImageMemoryBarrier [imageBarriersCount] /*---*/;
    if (imageBarriers == NULL) {
      if (bufferBarriers != NULL) { delete[] bufferBarriers; }
      return RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
    }
  }
  for (unsigned i = 0; i < bufferBarriersCount; i += 1) {
    bufferBarriers[i].sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
    bufferBarriers[i].pNext               = NULL;
    bufferBarriers[i].srcAccessMask       = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    bufferBarriers[i].dstAccessMask       = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    bufferBarriers[i].srcQueueFamilyIndex =-1;
    bufferBarriers[i].dstQueueFamilyIndex =-1;
    bufferBarriers[i].buffer              = (VkBuffer)arrays[i];
    bufferBarriers[i].offset              = 0;
    bufferBarriers[i].size                =-1;
  }
  for (unsigned i = 0; i < imageBarriersCount; i += 1) {
    imageBarriers[i].sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    imageBarriers[i].pNext                           = NULL;
    imageBarriers[i].srcAccessMask                   = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    imageBarriers[i].dstAccessMask                   = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    imageBarriers[i].oldLayout                       = VK_IMAGE_LAYOUT_GENERAL;
    imageBarriers[i].newLayout                       = VK_IMAGE_LAYOUT_GENERAL;
    imageBarriers[i].srcQueueFamilyIndex             =-1;
    imageBarriers[i].dstQueueFamilyIndex             =-1;
    imageBarriers[i].image                           = (VkImage)images[i];
    imageBarriers[i].subresourceRange.aspectMask     = (VkImageAspectFlags)imagesAllParts[i];
    imageBarriers[i].subresourceRange.baseMipLevel   = 0;
    imageBarriers[i].subresourceRange.levelCount     =-1;
    imageBarriers[i].subresourceRange.baseArrayLayer = 0;
    imageBarriers[i].subresourceRange.layerCount     =-1;
  }
  ((PFN_vkCmdPipelineBarrier)((void *)addresses->redCallUsageAliasOrderBarrier))((VkCommandBuffer)calls, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, 0, 0, NULL, bufferBarriersCount, bufferBarriers, imageBarriersCount, imageBarriers);
  if (bufferBarriers != NULL) { delete[] bufferBarriers; }
  if (imageBarriers  != NULL) { delete[] imageBarriers;  }
#endif
  return RED_STATUS_SUCCESS;
}

void red2CallBarrierUsagePresentToImage(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedContext context, RedHandleImage presentImage, RedAccessStageBitflags newAccessStages, RedAccessBitflags newAccess, RedBool32 presentImageDiscardPreviousContent) {
#ifdef REDGPU_USE_REDGPU_X
  RedXBarrier imageUsage = {};
  imageUsage.usage.setTo0      = 0;
  imageUsage.usage.split       = RED_BARRIER_SPLIT_NONE;
  imageUsage.usage.resource    = redXGetHandleResourceImage(NULL, NULL, presentImage);
  imageUsage.usage.level       =-1;
  imageUsage.usage.oldAccesses = REDX_ACCESS_BITFLAG_PRESENT;
  imageUsage.usage.newAccesses = red2RedXOnlyGetRedXAccessBitflagsFromRed(newAccess);
  redXCallUsageAliasOrderBarrier(calls, 1, &imageUsage);
#else
  RedUsageImage imageUsage = {};
  imageUsage.barrierSplit           = RED_BARRIER_SPLIT_NONE;
  imageUsage.oldAccessStages        = 0;
  imageUsage.newAccessStages        = newAccessStages;
  imageUsage.oldAccess              = 0;
  imageUsage.newAccess              = newAccess;
  imageUsage.oldState               = presentImageDiscardPreviousContent == 1 ? RED_STATE_UNUSABLE : RED_STATE_PRESENT;
  imageUsage.newState               = RED_STATE_USABLE;
  imageUsage.queueFamilyIndexSource =-1;
  imageUsage.queueFamilyIndexTarget =-1;
  imageUsage.image                  = presentImage;
  imageUsage.imageAllParts          = RED_IMAGE_PART_BITFLAG_COLOR;
  imageUsage.imageLevelsFirst       = 0;
  imageUsage.imageLevelsCount       =-1;
  imageUsage.imageLayersFirst       = 0;
  imageUsage.imageLayersCount       =-1;
  redCallUsageAliasOrderBarrier(addresses->redCallUsageAliasOrderBarrier, calls, context, 0, NULL, 1, &imageUsage, 0, NULL, 0, NULL, 0);
#endif
}

void red2CallBarrierUsageImageToPresent(const RedCallProceduresAndAddresses * addresses, RedHandleCalls calls, RedContext context, RedHandleImage presentImage, RedAccessStageBitflags oldAccessStages, RedAccessBitflags oldAccess) {
#ifdef REDGPU_USE_REDGPU_X
  RedXBarrier imageUsage = {};
  imageUsage.usage.setTo0      = 0;
  imageUsage.usage.split       = RED_BARRIER_SPLIT_NONE;
  imageUsage.usage.resource    = redXGetHandleResourceImage(NULL, NULL, presentImage);
  imageUsage.usage.level       =-1;
  imageUsage.usage.oldAccesses = red2RedXOnlyGetRedXAccessBitflagsFromRed(oldAccess);
  imageUsage.usage.newAccesses = REDX_ACCESS_BITFLAG_PRESENT;
  redXCallUsageAliasOrderBarrier(calls, 1, &imageUsage);
#else
  RedUsageImage imageUsage = {};
  imageUsage.barrierSplit           = RED_BARRIER_SPLIT_NONE;
  imageUsage.oldAccessStages        = oldAccessStages;
  imageUsage.newAccessStages        = 0;
  imageUsage.oldAccess              = oldAccess;
  imageUsage.newAccess              = 0;
  imageUsage.oldState               = RED_STATE_USABLE;
  imageUsage.newState               = RED_STATE_PRESENT;
  imageUsage.queueFamilyIndexSource =-1;
  imageUsage.queueFamilyIndexTarget =-1;
  imageUsage.image                  = presentImage;
  imageUsage.imageAllParts          = RED_IMAGE_PART_BITFLAG_COLOR;
  imageUsage.imageLevelsFirst       = 0;
  imageUsage.imageLevelsCount       =-1;
  imageUsage.imageLayersFirst       = 0;
  imageUsage.imageLayersCount       =-1;
  redCallUsageAliasOrderBarrier(addresses->redCallUsageAliasOrderBarrier, calls, context, 0, NULL, 1, &imageUsage, 0, NULL, 0, NULL, 0);
#endif
}

void red2CreateStream(Red2Context context2, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, RedHandleQueue gpuSignalSignaledOnQueue, Red2HandleStream * outStream, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_UNDEFINED; // TODO(Constantine): Assign a RED2_PROCEDURE_ID.

  Red2InternalTypeStream * handle = new(std::nothrow) Red2InternalTypeStream();
  if (handle == NULL) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = (RedProcedureId)procedureId;
        outStatuses->statusErrorFile           = optionalFile;
        outStatuses->statusErrorLine           = optionalLine;
        outStatuses->statusErrorDescription[0] = 0;
      }
    }
    outStream[0] = NULL;
    return;
  }

  // Create GPU signal in signaled state.
  RedHandleGpuSignal gpuSignal = NULL;
  {
    redCreateGpuSignal(context2->context, gpu, handleName, &gpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (gpuSignal == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      delete handle;
      outStream[0] = NULL;
      return;
    }

    RedGpuTimeline timeline /*---*/;
    timeline.setTo4                            = 4;
    timeline.setTo0                            = 0;
    timeline.waitForAndUnsignalGpuSignalsCount = 0;
    timeline.waitForAndUnsignalGpuSignals      = NULL;
    timeline.setTo65536                        = NULL;
    timeline.callsCount                        = 0;
    timeline.calls                             = NULL; // NOTE(Constantine): Should I submit a dummy calls handle to signal GPU signals? Assuming not for now.
    timeline.signalGpuSignalsCount             = 1;
    timeline.signalGpuSignals                  = &gpuSignal;
    uint64_t ticketArrayIndex = 0;
    uint64_t ticket           = 0;
    red2QueueSubmit(context2, gpu, gpuSignalSignaledOnQueue, 1, &timeline, &ticketArrayIndex, &ticket, outStatuses, optionalFile, optionalLine, optionalUserData);
    red2WaitForQueueSubmissionToFinish(context2, gpu, ticketArrayIndex, ticket, outStatuses, optionalFile, optionalLine, optionalUserData);
  }

  handle->value65536       = 65536;
  handle->queueFamilyIndex = queueFamilyIndex;
  handle->gpuSignalForSerialDependencyBetweenStreamSubmissions = gpuSignal;
  handle->streamCallsToSubmitGpuSignals[0]                     = gpuSignal; // NOTE(Constantine): Element [0] is constant and never changed.

  outStream[0] = (Red2HandleStream)(void *)handle;
}

void red2DestroyStream(Red2Context context2, RedHandleGpu gpu, Red2HandleStream stream, const char * optionalFile, int optionalLine, void * optionalUserData) {
  if (stream == NULL) {
    return;
  }

  Red2InternalTypeStream * handle = (Red2InternalTypeStream *)(void *)stream;

  redDestroyGpuSignal(context2->context, gpu, handle->gpuSignalForSerialDependencyBetweenStreamSubmissions, optionalFile, optionalLine, optionalUserData);
  
  for (Red2HandleCalls streamCalls : handle->streamCallsToGet) {
    // NOTE(Constantine): The user should wait for all the stream calls to finish before destroying the stream.
    red2DestroyCalls(context2->context, gpu, streamCalls, optionalFile, optionalLine, optionalUserData);
  }

  delete handle;
}

// NOTE(Constantine):
// This procedure is not thread-safe and should be called from one thread at a time.
// The returned different calls handles can still be recorded on different threads, though.
// The returned calls are queue submit trackable.
void red2StreamGetCalls(Red2Context context2, RedHandleGpu gpu, Red2HandleStream stream, Red2HandleCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeStream * handle = (Red2InternalTypeStream *)(void *)stream;

  Red2HandleCalls calls = NULL;
  for (size_t i = 0, icount = handle->streamCallsToGet.size(); i < icount; i += 1) {
    if (handle->streamCallsToGetTaken[i] == 1) { continue; }
    uint64_t ticketArrayIndex = 0;
    uint64_t ticket           = 0;
    red2CallsGetQueueSubmitTrackableTicket(handle->streamCallsToGet[i], &ticketArrayIndex, &ticket);
    RedBool32 isFinished = red2IsQueueSubmissionFinished(context2, gpu, ticketArrayIndex, ticket, optionalFile, optionalLine, optionalUserData);
    if (isFinished == 1) {
      calls = handle->streamCallsToGet[i];
      handle->streamCallsToGetTaken[i] = 1;
      break;
    }
  }
  if (calls == NULL) {
    red2CreateCalls(context2->context, gpu, NULL, handle->queueFamilyIndex, &calls, outStatuses, optionalFile, optionalLine, optionalUserData);
    if (calls == NULL) { // NOTE(Constantine): Maybe need to check for outStatuses error too?
      outCalls[0] = NULL;
      return;
    }
    handle->streamCallsToGet.push_back(calls);
    handle->streamCallsToGetTaken.push_back(1);
  }

  outCalls[0] = calls;
}

// NOTE(Constantine):
// The submitted to the stream calls won't be submitted to the GPU yet, for that the whole stream must be flushed with a red2StreamFlushToQueue() call.
// The submitted calls within a stream submission will be executed asynchronously relative to each other.
void red2StreamSubmitCalls(Red2Context context2, RedHandleGpu gpu, Red2HandleStream stream, unsigned callsCount, Red2HandleCalls * calls, const char * optionalFile, int optionalLine, void * optionalUserData) {
  Red2InternalTypeStream * handle = (Red2InternalTypeStream *)(void *)stream;

  // NOTE(Constantine): Intentionally placed here, before the push_back's. Do not move this line.
  size_t firstCallsToSubmitInATimeline = handle->streamCallsToSubmit.size();

  for (unsigned i = 0; i < callsCount; i += 1) {
    RedCalls redcalls /*---*/;
    red2CallsGetRedHandles(calls[i], NULL, NULL, &redcalls);
    handle->streamCallsToSubmit.push_back(redcalls.handle);
    handle->streamCallsToSubmitType2.push_back(calls[i]);
  }

  handle->streamCallsToSubmitFirst.push_back(firstCallsToSubmitInATimeline); // NOTE(Constantine): streamCallsToSubmitFirst is an array of count streamCallsToSubmitTimelines.

  RedGpuTimeline timeline /*---*/;
  timeline.setTo4                            = 4;
  timeline.setTo0                            = 0;
  timeline.waitForAndUnsignalGpuSignalsCount = 1;
  timeline.waitForAndUnsignalGpuSignals      = &handle->streamCallsToSubmitGpuSignals[0];
  timeline.setTo65536                        = &handle->value65536;
  timeline.callsCount                        = callsCount;
  timeline.calls                             = NULL; // NOTE(Constantine): Set on flush. Calls are not set here since std::vector may change elements addresses when grown further.
  timeline.signalGpuSignalsCount             = 1;
  timeline.signalGpuSignals                  = &handle->streamCallsToSubmitGpuSignals[0];
  handle->streamCallsToSubmitTimelines.push_back(timeline);
}

void red2StreamFlushToQueue(Red2Context context2, RedHandleGpu gpu, RedHandleQueue queue, const Red2StreamsHighway * highway, unsigned streamsCount, const Red2HandleStream * streams, uint64_t * outQueueSubmissionTicketArrayIndex, uint64_t * outQueueSubmissionTicket, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  // NOTE(Constantine):
  //
  // NULL synchronization streams and GPU signal 'highway lanes' feature idea description:
  //
  // For streams S with timelines T:
  //
  // [ S0[T0, T1, T2], S1[T0, T1], S2[T0], S3[T0], ...]
  //
  // Linearized to a flat array of 'std::vector<RedGpuTimeline> timelines':
  //
  // [ S0T0, S0T1, S0T2, S1T0, S1T1, S2T0, S3T0, ...]
  //
  // With a NULL synchronization stream inserted:
  //
  // [ S0[T0, T1, T2], S1[T0, T1], NULL, S2[T0], S3[T0], ...]
  // [ S0T0, S0T1, S0T2, S1T0, S1T1, NULL, S2T0, S3T0, ...]
  //
  // That NULL stream takes separately provided extra 'highway lanes' GPU signals that weave into every stream:
  //
  // S0T0,S0T1,S0T2,S1T0,S1T1
  //   |   |    |    |   |
  //   |   |    |    |   |
  //    \  \    |    /  /
  //     \  \   |   /  /
  //      \  \  |  /  /
  //       \  \ | /  /
  //         \ \|/ /    <--- Wait for all the extra 'highway lanes' GPU signals and unsignal them.
  //           NULL
  //         / /|\ \    <--- Signal all the extra 'highway lanes' GPU signals back.
  //       /  / | \  \
  //      /  /  |  \  \
  //     /  /   |   \  \
  //    /  /    |    \  \
  //   |   |    |    |   |  <--- NOTE: This is the maximum number of streams allowed before another NULL stream
  //   |   |    |    |   |             (in this example, 5 streams max, 1 'highway lane' GPU signal per stream).
  //   |   |    |    |   |             Provide more 'highway lane' GPU signals to increase this maximum number.
  // S2T0,S3T0  |    |   |
  //   |   |    |    |   |
  //   |   |    |    |   |
  //

  std::vector<RedGpuTimeline> timelines;
  unsigned                    timelinesCount = 0;
  RedGpuTimeline *            timelinesArray = NULL;
  {
    {
      unsigned highwayLaneIndex = 0;
      for (unsigned i = 0; i < streamsCount; i += 1) {
        Red2InternalTypeStream * stream = (Red2InternalTypeStream *)(void *)streams[i];
        if (stream == NULL) {
          timelinesCount  += 1; // NOTE(Constantine): NULL synchronization stream's timeline struct.
          highwayLaneIndex = 0; // NOTE(Constantine): NULL synchronization stream is encountered, resetting highway lane index back to 0. 
        } else {
          unsigned streamTimelinesCount = (unsigned)stream->streamCallsToSubmitTimelines.size();
          timelinesCount += streamTimelinesCount;

          // NOTE(Constantine): Patching stream's first and last timeline structs with stream's 'highway lane' GPU signal.
          if (streamTimelinesCount > 0) {
            RedGpuTimeline * timeline = NULL;
            timeline = &stream->streamCallsToSubmitTimelines[0];
            {
              timeline->waitForAndUnsignalGpuSignalsCount = 2;
              timeline->signalGpuSignalsCount             = 2;
              RedHandleGpuSignal * waitForAndUnsignalGpuSignals = (RedHandleGpuSignal *)&timeline->waitForAndUnsignalGpuSignals[0];
              RedHandleGpuSignal * signalGpuSignals             = (RedHandleGpuSignal *)&timeline->signalGpuSignals[0];
              waitForAndUnsignalGpuSignals[1] = highway->perStreamsBeforeNullSignaledGpuSignal[highwayLaneIndex];
              signalGpuSignals[1]             = highway->perStreamsBeforeNullSignaledGpuSignal[highwayLaneIndex];
            }
            timeline = &stream->streamCallsToSubmitTimelines[streamTimelinesCount - 1];
            {
              timeline->waitForAndUnsignalGpuSignalsCount = 2;
              timeline->signalGpuSignalsCount             = 2;
              RedHandleGpuSignal * waitForAndUnsignalGpuSignals = (RedHandleGpuSignal *)&timeline->waitForAndUnsignalGpuSignals[0];
              RedHandleGpuSignal * signalGpuSignals             = (RedHandleGpuSignal *)&timeline->signalGpuSignals[0];
              waitForAndUnsignalGpuSignals[1] = highway->perStreamsBeforeNullSignaledGpuSignal[highwayLaneIndex];
              signalGpuSignals[1]             = highway->perStreamsBeforeNullSignaledGpuSignal[highwayLaneIndex];
            }
          }
          highwayLaneIndex += 1;
        }
      }
    }
    timelines.resize(timelinesCount);
    timelinesArray = timelines.data();
    // NOTE(Constantine): Copy all timelines from all streams into one array.
    {
      uint64_t timelineArrayIndex = 0;
      for (unsigned i = 0; i < streamsCount; i += 1) {
        Red2InternalTypeStream * stream = (Red2InternalTypeStream *)(void *)streams[i];
        if (stream != NULL) {
          for (const RedGpuTimeline & timeline : stream->streamCallsToSubmitTimelines) {
            timelinesArray[timelineArrayIndex] = timeline;
            timelineArrayIndex += 1;
          }
        } else {
          // NOTE(Constantine): NULL synchronization stream.

          timelinesArray[timelineArrayIndex].setTo4                            = 4;
          timelinesArray[timelineArrayIndex].setTo0                            = 0;
          timelinesArray[timelineArrayIndex].waitForAndUnsignalGpuSignalsCount = highway->maxStreamsBeforeNullCount;
          timelinesArray[timelineArrayIndex].waitForAndUnsignalGpuSignals      = highway->perStreamsBeforeNullSignaledGpuSignal;
          timelinesArray[timelineArrayIndex].setTo65536                        = highway->arrayOf65536;
          timelinesArray[timelineArrayIndex].callsCount                        = 0;
          timelinesArray[timelineArrayIndex].calls                             = NULL; // NOTE(Constantine): Should I submit a dummy calls handle to signal GPU signals? Assuming not for now.
          timelinesArray[timelineArrayIndex].signalGpuSignalsCount             = highway->maxStreamsBeforeNullCount;
          timelinesArray[timelineArrayIndex].signalGpuSignals                  = highway->perStreamsBeforeNullSignaledGpuSignal;

          timelineArrayIndex += 1;
        }
      }
    }
  }

  // NOTE(Constantine): Patch all timeline structs with correct calls array start addresses.
  {
    uint64_t timelineArrayIndex = 0;
    for (unsigned i = 0; i < streamsCount; i += 1) {
      Red2InternalTypeStream * stream = (Red2InternalTypeStream *)(void *)streams[i];
      if (stream == NULL) { continue; }
      RedHandleCalls * streamCallsToSubmit = stream->streamCallsToSubmit.data();
      for (size_t streamCallsToSubmitFirst : stream->streamCallsToSubmitFirst) {
        timelinesArray[timelineArrayIndex].calls = &streamCallsToSubmit[streamCallsToSubmitFirst];
        timelineArrayIndex += 1;
      }
    }
  }

  uint64_t ticketArrayIndex = 0;
  uint64_t ticket           = 0;
  red2QueueSubmit(context2, gpu, queue, timelinesCount, timelinesArray, &ticketArrayIndex, &ticket, outStatuses, optionalFile, optionalLine, optionalUserData);

  for (unsigned i = 0; i < streamsCount; i += 1) {
    Red2InternalTypeStream * stream = (Red2InternalTypeStream *)(void *)streams[i];
    if (stream == NULL) { continue; }
    for (Red2HandleCalls calls : stream->streamCallsToSubmitType2) {
      Red2InternalTypeCalls * handle = (Red2InternalTypeCalls *)(void *)calls;
      handle->lastQueueSubmitTrackableTicketArrayIndex = ticketArrayIndex;
      handle->lastQueueSubmitTrackableTicket           = ticket;
    }
  }

  for (unsigned i = 0; i < streamsCount; i += 1) {
    Red2InternalTypeStream * stream = (Red2InternalTypeStream *)(void *)streams[i];
    if (stream == NULL) { continue; }
    for (size_t i = 0, icount = stream->streamCallsToGetTaken.size(); i < icount; i += 1) {
      stream->streamCallsToGetTaken[i] = 0;
    }
    stream->streamCallsToSubmit.clear();
    stream->streamCallsToSubmitType2.clear();
    stream->streamCallsToSubmitFirst.clear();
    stream->streamCallsToSubmitTimelines.clear();
    stream->streamCallsToSubmitGpuSignals[1] = NULL;
  }

  if (outQueueSubmissionTicketArrayIndex != NULL) { outQueueSubmissionTicketArrayIndex[0] = ticketArrayIndex; }
  if (outQueueSubmissionTicket           != NULL) { outQueueSubmissionTicket[0]           = ticket;           }
}
