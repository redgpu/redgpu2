#if 0
rm -f libredgpu_profile.so
cc -fvisibility=hidden -fPIC -shared redgpu_profile.c -o libredgpu_profile.so
exit
#endif
// cl /LD redgpu_profile.c

#ifdef __linux__
#define REDGPU_DECLSPEC __attribute__((visibility("default")))
#include "/opt/RedGpuSDK/redgpu.h"
#include "/opt/RedGpuSDK/redgpu_wsi.h"
#include "/opt/RedGpuSDK/redgpu_array_timestamp.h"
#include "/opt/github/procedural/profile/profile.h"
#include <dlfcn.h>
#endif
#ifdef _WIN32
#define REDGPU_DECLSPEC __declspec(dllexport)
#include "C:/RedGpuSDK/redgpu.h"
#include "C:/RedGpuSDK/redgpu_wsi.h"
#include "C:/RedGpuSDK/redgpu_array_timestamp.h"
#include "C:/github/procedural/profile/profile.h"
#include <Windows.h>
#pragma comment(lib, "C:/github/procedural/profile/profiledll.lib")
#endif

typedef struct RedProfileInternalRedGpuProcedureAddresses {
  void (*redMemoryGetBudget)(RedContext context, RedHandleGpu gpu, RedMemoryBudget * outMemoryBudget, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redMemoryAllocate)(RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t bytesCount, unsigned memoryTypeIndex, RedHandleArray dedicateToArray, RedHandleImage dedicateToImage, unsigned memoryBitflags, RedHandleMemory * outMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redMemoryAllocateMappable)(RedContext context, RedHandleGpu gpu, const char * handleName, RedBool32 dedicate, RedHandleArray array, uint64_t arrayMemoryBytesCount, unsigned memoryTypeIndex, unsigned memoryBitflags, RedHandleMemory * outMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redMemoryFree)(RedContext context, RedHandleGpu gpu, RedHandleMemory memory, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redMemorySet)(RedContext context, RedHandleGpu gpu, unsigned memoryArraysCount, const RedMemoryArray * memoryArrays, unsigned memoryImagesCount, const RedMemoryImage * memoryImages, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redMemoryMap)(RedContext context, RedHandleGpu gpu, RedHandleMemory mappableMemory, uint64_t mappableMemoryBytesFirst, uint64_t mappableMemoryBytesCount, void ** outVolatilePointer, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redMemoryUnmap)(RedContext context, RedHandleGpu gpu, RedHandleMemory mappableMemory, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redMemoryNonCoherentFlush)(RedContext context, RedHandleGpu gpu, unsigned mappableMemoryRangesCount, const RedMappableMemoryRange * mappableMemoryRanges, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redMemoryNonCoherentInvalidate)(RedContext context, RedHandleGpu gpu, unsigned mappableMemoryRangesCount, const RedMappableMemoryRange * mappableMemoryRanges, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redStructsMemoryAllocate)(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned maxStructsCount, unsigned maxStructsMembersOfTypeArrayROConstantCount, unsigned maxStructsMembersOfTypeArrayROOrArrayRWCount, unsigned maxStructsMembersOfTypeTextureROCount, unsigned maxStructsMembersOfTypeTextureRWCount, RedHandleStructsMemory * outStructsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redStructsMemoryAllocateSamplers)(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned maxStructsCount, unsigned maxStructsMembersOfTypeSamplerCount, RedHandleStructsMemory * outStructsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redStructsMemorySuballocateStructs)(RedContext context, RedHandleGpu gpu, const char ** handleNames, RedHandleStructsMemory structsMemory, unsigned structsDeclarationsCount, const RedHandleStructDeclaration * structsDeclarations, RedHandleStruct * outStructs, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redStructsMemoryReset)(RedContext context, RedHandleGpu gpu, RedHandleStructsMemory structsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redStructsMemoryFree)(RedContext context, RedHandleGpu gpu, RedHandleStructsMemory structsMemory, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redStructsSet)(RedContext context, RedHandleGpu gpu, unsigned structsMembersCount, const RedStructMember * structsMembers, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateContext)(RedTypeProcedureMalloc malloc, RedTypeProcedureFree free, RedTypeProcedureMallocTagged optionalMallocTagged, RedTypeProcedureFreeTagged optionalFreeTagged, RedTypeProcedureDebugCallback debugCallback, RedSdkVersion sdkVersion, unsigned sdkExtensionsCount, const unsigned * sdkExtensions, const char * optionalProgramName, unsigned optionalProgramVersion, const char * optionalEngineName, unsigned optionalEngineVersion, const void * optionalSettings, RedContext * outContext, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateArray)(RedContext context, RedHandleGpu gpu, const char * handleName, RedArrayType type, uint64_t bytesCount, uint64_t structuredBufferElementBytesCount, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedArray * outArray, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateImage)(RedContext context, RedHandleGpu gpu, const char * handleName, RedImageDimensions dimensions, RedFormat format, unsigned width, unsigned height, unsigned depth, unsigned levelsCount, unsigned layersCount, RedMultisampleCountBitflag multisampleCount, RedAccessBitflags restrictToAccess, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedImage * outImage, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateSampler)(RedContext context, RedHandleGpu gpu, const char * handleName, RedSamplerFiltering filteringMag, RedSamplerFiltering filteringMin, RedSamplerFilteringMip filteringMip, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateU, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateV, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateW, float mipLodBias, RedBool32 enableAnisotropy, float maxAnisotropy, RedBool32 enableCompare, RedCompareOp compareOp, float minLod, float maxLod, RedHandleSampler * outSampler, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateTexture)(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleImage image, RedImagePartBitflags parts, RedTextureDimensions dimensions, RedFormat format, unsigned levelsFirst, unsigned levelsCount, unsigned layersFirst, unsigned layersCount, RedAccessBitflags restrictToAccess, RedHandleTexture * outTexture, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateGpuCode)(RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t irBytesCount, const void * ir, RedHandleGpuCode * outGpuCode, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateOutputDeclaration)(RedContext context, RedHandleGpu gpu, const char * handleName, const RedOutputDeclarationMembers * outputDeclarationMembers, const RedOutputDeclarationMembersResolveSources * outputDeclarationMembersResolveSources, RedBool32 dependencyByRegion, RedBool32 dependencyByRegionAllowUsageAliasOrderBarriers, RedHandleOutputDeclaration * outOutputDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateStructDeclaration)(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned structDeclarationMembersCount, const RedStructDeclarationMember * structDeclarationMembers, unsigned structDeclarationMembersArrayROCount, const RedStructDeclarationMemberArrayRO * structDeclarationMembersArrayRO, RedBool32 procedureParametersHandlesDeclaration, RedHandleStructDeclaration * outStructDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateProcedureParameters)(RedContext context, RedHandleGpu gpu, const char * handleName, const RedProcedureParametersDeclaration * procedureParametersDeclaration, RedHandleProcedureParameters * outProcedureParameters, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateProcedureCache)(RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t fromBlobBytesCount, const void * fromBlob, RedHandleProcedureCache * outProcedureCache, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateProcedure)(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, RedHandleOutputDeclaration outputDeclaration, RedHandleProcedureParameters procedureParameters, const char * gpuCodeVertexMainProcedureName, RedHandleGpuCode gpuCodeVertex, const char * gpuCodeFragmentMainProcedureName, RedHandleGpuCode gpuCodeFragment, const RedProcedureState * state, const void * stateExtension, RedBool32 deriveBase, RedHandleProcedure deriveFrom, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateProcedureCompute)(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, RedHandleProcedureParameters procedureParameters, const char * gpuCodeMainProcedureName, RedHandleGpuCode gpuCode, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateOutput)(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleOutputDeclaration outputDeclaration, const RedOutputMembers * outputMembers, const RedOutputMembersResolveTargets * outputMembersResolveTargets, unsigned width, unsigned height, RedOutput * outOutput, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateCpuSignal)(RedContext context, RedHandleGpu gpu, const char * handleName, RedBool32 createSignaled, RedHandleCpuSignal * outCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateGpuSignal)(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleGpuSignal * outGpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateGpuToCpuSignal)(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleGpuToCpuSignal * outGpuToCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateCalls)(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, RedCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateCallsReusable)(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, RedCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyContext)(RedContext context, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyArray)(RedContext context, RedHandleGpu gpu, RedHandleArray array, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyImage)(RedContext context, RedHandleGpu gpu, RedHandleImage image, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroySampler)(RedContext context, RedHandleGpu gpu, RedHandleSampler sampler, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyTexture)(RedContext context, RedHandleGpu gpu, RedHandleTexture texture, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyGpuCode)(RedContext context, RedHandleGpu gpu, RedHandleGpuCode gpuCode, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyOutputDeclaration)(RedContext context, RedHandleGpu gpu, RedHandleOutputDeclaration outputDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyStructDeclaration)(RedContext context, RedHandleGpu gpu, RedHandleStructDeclaration structDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyProcedureParameters)(RedContext context, RedHandleGpu gpu, RedHandleProcedureParameters procedureParameters, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyProcedureCache)(RedContext context, RedHandleGpu gpu, RedHandleProcedureCache procedureCache, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyProcedure)(RedContext context, RedHandleGpu gpu, RedHandleProcedure procedure, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyOutput)(RedContext context, RedHandleGpu gpu, RedHandleOutput output, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyCpuSignal)(RedContext context, RedHandleGpu gpu, RedHandleCpuSignal cpuSignal, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyGpuSignal)(RedContext context, RedHandleGpu gpu, RedHandleGpuSignal gpuSignal, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyGpuToCpuSignal)(RedContext context, RedHandleGpu gpu, RedHandleGpuToCpuSignal gpuToCpuSignal, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyCalls)(RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedHandleCallsMemory callsMemory, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redProcedureCacheGetBlob)(RedContext context, RedHandleGpu gpu, RedHandleProcedureCache procedureCache, uint64_t * outBlobBytesCount, void * outBlob, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redProcedureCacheMergeCaches)(RedContext context, RedHandleGpu gpu, unsigned sourceProcedureCachesCount, const RedHandleProcedureCache * sourceProcedureCaches, RedHandleProcedureCache targetProcedureCache, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCpuSignalGetStatus)(RedContext context, RedHandleGpu gpu, RedHandleCpuSignal cpuSignal, RedStatus * outStatus, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCpuSignalWait)(RedContext context, RedHandleGpu gpu, unsigned cpuSignalsCount, const RedHandleCpuSignal * cpuSignals, RedBool32 waitAll, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCpuSignalUnsignal)(RedContext context, RedHandleGpu gpu, unsigned cpuSignalsCount, const RedHandleCpuSignal * cpuSignals, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redGpuToCpuSignalGetStatus)(RedContext context, RedHandleGpu gpu, RedHandleGpuToCpuSignal gpuToCpuSignal, RedStatus * outStatus, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redGpuToCpuSignalUnsignal)(RedContext context, RedHandleGpu gpu, RedHandleGpuToCpuSignal gpuToCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCallsSet)(RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedHandleCallsMemory callsMemory, RedBool32 callsReusable, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCallsEnd)(RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedHandleCallsMemory callsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redGetCallProceduresAndAddresses)(RedContext context, RedHandleGpu gpu, RedCallProceduresAndAddresses * outCallProceduresAndAddresses, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCallSetDynamicViewport)(RedTypeProcedureAddressCallSetDynamicViewport address, RedHandleCalls calls, float x, float y, float width, float height, float depthMin, float depthMax);
  void (*redCallSetDynamicScissor)(RedTypeProcedureAddressCallSetDynamicScissor address, RedHandleCalls calls, int x, int y, unsigned width, unsigned height);
  void (*redCallSetStructsMemory)(RedTypeProcedureAddressCallSetStructsMemory address, RedHandleCalls calls, RedHandleStructsMemory structsMemory, RedHandleStructsMemory structsMemorySamplers);
  void (*redCallSetProcedureParameters)(RedTypeProcedureAddressCallSetProcedureParameters address, RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedureParameters procedureParameters);
  void (*redCallSetProcedureOutput)(RedTypeProcedureAddressCallSetProcedureOutput address, RedHandleCalls calls, RedHandleOutputDeclaration outputDeclaration, RedHandleOutput output, RedInlineOutput * inlineOutput, unsigned outputWidth, unsigned outputHeight, RedBool32 outputDepthStencilEnable, unsigned outputColorsCount, float depthClearValue, unsigned stencilClearValue, const RedColorsClearValuesFloat * colorsClearValuesFloat, const RedColorsClearValuesSint * colorsClearValuesSint, const RedColorsClearValuesUint * colorsClearValuesUint);
  void (*redCallEndProcedureOutput)(RedTypeProcedureAddressCallEndProcedureOutput address, RedHandleCalls calls);
  void (*redCallUsageAliasOrderBarrier)(RedTypeProcedureAddressCallUsageAliasOrderBarrier address, RedHandleCalls calls, RedContext context, unsigned arrayUsagesCount, const RedUsageArray * arrayUsages, unsigned imageUsagesCount, const RedUsageImage * imageUsages, unsigned aliasesCount, const RedAlias * aliases, unsigned ordersCount, const RedOrder * orders, RedBool32 dependencyByRegion);
  void (*redCallMark)(RedTypeProcedureAddressCallMark address, RedHandleCalls calls, const char * mark);
  void (*redCallMarkSet)(RedTypeProcedureAddressCallMarkSet address, RedHandleCalls calls, const char * mark);
  void (*redCallMarkEnd)(RedTypeProcedureAddressCallMarkEnd address, RedHandleCalls calls);
  void (*redQueueSubmit)(RedContext context, RedHandleGpu gpu, RedHandleQueue queue, unsigned timelinesCount, const RedGpuTimeline * timelines, RedHandleCpuSignal signalCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redMark)(const char * mark, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redMarkSet)(const char * mark, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redMarkEnd)(const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateSurfaceWin32)(RedContext context, RedHandleGpu gpu, const char * handleName, const void * win32Hinstance, const void * win32Hwnd, RedHandleSurface * outSurface, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateSurfaceXlibOrXcb)(RedContext context, RedHandleGpu gpu, const char * handleName, const void * xlibDisplay, unsigned long xlibWindow, const void * xcbConnection, unsigned xcbWindow, RedHandleSurface * outSurface, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreatePresent)(RedContext context, RedHandleGpu gpu, RedHandleQueue queue, const char * handleName, RedHandleSurface surface, unsigned imagesCount, unsigned imagesWidth, unsigned imagesHeight, unsigned imagesLayersCount, RedAccessBitflags imagesRestrictToAccess, RedSurfaceTransformBitflag transform, RedSurfaceCompositeAlphaBitflag compositeAlpha, RedPresentVsyncMode vsyncMode, RedBool32 clipped, RedBool32 discardAfterPresent, RedHandlePresent oldPresent, RedHandlePresent * outPresent, RedHandleImage * outImages, RedHandleTexture * outTextures, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroySurface)(RedContext context, RedHandleGpu gpu, RedHandleSurface surface, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyPresent)(RedContext context, RedHandleGpu gpu, RedHandlePresent present, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redQueueFamilyIndexGetSupportsPresent)(RedContext context, RedHandleGpu gpu, unsigned queueFamilyIndex, RedQueueFamilyIndexGetSupportsPresentOnWin32 * supportsPresentOnWin32, RedQueueFamilyIndexGetSupportsPresentOnXlib * supportsPresentOnXlib, RedQueueFamilyIndexGetSupportsPresentOnXcb * supportsPresentOnXcb, RedQueueFamilyIndexGetSupportsPresentOnSurface * supportsPresentOnSurface, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redSurfaceGetPresentFeatures)(RedContext context, RedHandleGpu gpu, RedHandleSurface surface, RedSurfacePresentFeatures * outSurfacePresentFeatures, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redSurfaceGetCurrentPropertiesAndPresentLimits)(RedContext context, RedHandleGpu gpu, RedHandleSurface surface, RedSurfaceCurrentPropertiesAndPresentLimits * outSurfaceCurrentPropertiesAndPresentLimits, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redPresentGetImageIndex)(RedContext context, RedHandleGpu gpu, RedHandlePresent present, RedHandleCpuSignal signalCpuSignal, RedHandleGpuSignal signalGpuSignal, unsigned * outImageIndex, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redQueuePresent)(RedContext context, RedHandleGpu gpu, RedHandleQueue queue, unsigned waitForAndUnsignalGpuSignalsCount, const RedHandleGpuSignal * waitForAndUnsignalGpuSignals, unsigned presentsCount, const RedHandlePresent * presents, const unsigned * presentsImageIndex, RedStatus * outPresentsStatus, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redGpuVisTracingStart)(const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redGpuVisTracingCapture)(const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redGpuVisTracingStop)(const char * optionalFile, int optionalLine, void * optionalUserData);
  RedHandleArray (*redDebugArrayGetHandle)(RedContext context, RedHandleGpu gpu, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDebugArrayCallPrint)(RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateProcedureComputingLanguage)(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, RedHandleProcedureParameters procedureParameters, const char * gpuCodeMainProcedureName, RedHandleGpuCode gpuCode, const void * stateExtension, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCreateArrayTimestamp)(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned count, RedHandleArrayTimestamp * outArrayTimestamp, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redDestroyArrayTimestamp)(RedContext context, RedHandleGpu gpu, RedHandleArrayTimestamp arrayTimestamp, const char * optionalFile, int optionalLine, void * optionalUserData);
  void (*redCallArrayTimestampWrite)(RedHandleCalls calls, RedContext context, RedHandleArrayTimestamp arrayTimestamp, unsigned index);
  void (*redArrayTimestampRead)(RedContext context, RedHandleGpu gpu, RedHandleArrayTimestamp arrayTimestamp, unsigned rangeFirst, unsigned rangeCount, void * out64BitTicksCounts, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData);
} RedProfileInternalRedGpuProcedureAddresses;

int                                        __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_isInitialized = 0;
RedProfileInternalRedGpuProcedureAddresses __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu     = {0};

static void redProfileInternalInitializeProcedurePointers(void) {
#ifdef _WIN32
  HMODULE libredgpu = 0;
#endif
  if (__REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_isInitialized == 0) {
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_isInitialized = 1;
#ifdef _WIN32
    libredgpu = LoadLibrary("C:/RedGpuSDK/redgpu.dll");
#define REDGPU_PROFILE_LOAD_PROC GetProcAddress
#endif
#ifdef __linux__
    void * libredgpu = dlopen("/opt/RedGpuSDK/libredgpu.so", RTLD_NOW);
#define REDGPU_PROFILE_LOAD_PROC dlsym
#endif
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryGetBudget = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redMemoryGetBudget");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryAllocate = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redMemoryAllocate");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryAllocateMappable = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redMemoryAllocateMappable");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryFree = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redMemoryFree");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemorySet = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redMemorySet");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryMap = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redMemoryMap");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryUnmap = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redMemoryUnmap");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryNonCoherentFlush = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redMemoryNonCoherentFlush");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryNonCoherentInvalidate = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redMemoryNonCoherentInvalidate");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redStructsMemoryAllocate = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redStructsMemoryAllocate");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redStructsMemoryAllocateSamplers = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redStructsMemoryAllocateSamplers");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redStructsMemorySuballocateStructs = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redStructsMemorySuballocateStructs");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redStructsMemoryReset = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redStructsMemoryReset");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redStructsMemoryFree = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redStructsMemoryFree");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redStructsSet = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redStructsSet");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateContext = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateContext");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateArray = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateArray");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateImage = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateImage");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateSampler = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateSampler");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateTexture = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateTexture");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateGpuCode = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateGpuCode");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateOutputDeclaration = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateOutputDeclaration");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateStructDeclaration = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateStructDeclaration");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateProcedureParameters = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateProcedureParameters");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateProcedureCache = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateProcedureCache");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateProcedure = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateProcedure");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateProcedureCompute = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateProcedureCompute");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateOutput = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateOutput");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateCpuSignal = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateCpuSignal");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateGpuSignal = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateGpuSignal");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateGpuToCpuSignal = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateGpuToCpuSignal");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateCalls = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateCalls");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateCallsReusable = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateCallsReusable");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyContext = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyContext");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyArray = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyArray");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyImage = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyImage");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroySampler = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroySampler");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyTexture = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyTexture");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyGpuCode = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyGpuCode");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyOutputDeclaration = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyOutputDeclaration");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyStructDeclaration = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyStructDeclaration");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyProcedureParameters = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyProcedureParameters");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyProcedureCache = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyProcedureCache");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyProcedure = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyProcedure");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyOutput = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyOutput");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyCpuSignal = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyCpuSignal");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyGpuSignal = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyGpuSignal");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyGpuToCpuSignal = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyGpuToCpuSignal");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyCalls = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyCalls");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redProcedureCacheGetBlob = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redProcedureCacheGetBlob");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redProcedureCacheMergeCaches = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redProcedureCacheMergeCaches");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCpuSignalGetStatus = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCpuSignalGetStatus");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCpuSignalWait = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCpuSignalWait");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCpuSignalUnsignal = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCpuSignalUnsignal");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redGpuToCpuSignalGetStatus = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redGpuToCpuSignalGetStatus");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redGpuToCpuSignalUnsignal = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redGpuToCpuSignalUnsignal");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallsSet = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallsSet");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallsEnd = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallsEnd");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redGetCallProceduresAndAddresses = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redGetCallProceduresAndAddresses");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallSetDynamicViewport = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallSetDynamicViewport");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallSetDynamicScissor = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallSetDynamicScissor");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallSetStructsMemory = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallSetStructsMemory");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallSetProcedureParameters = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallSetProcedureParameters");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallSetProcedureOutput = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallSetProcedureOutput");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallEndProcedureOutput = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallEndProcedureOutput");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallUsageAliasOrderBarrier = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallUsageAliasOrderBarrier");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallMark = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallMark");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallMarkSet = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallMarkSet");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallMarkEnd = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallMarkEnd");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redQueueSubmit = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redQueueSubmit");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMark = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redMark");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMarkSet = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redMarkSet");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMarkEnd = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redMarkEnd");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateSurfaceWin32 = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateSurfaceWin32");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateSurfaceXlibOrXcb = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateSurfaceXlibOrXcb");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreatePresent = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreatePresent");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroySurface = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroySurface");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyPresent = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyPresent");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redQueueFamilyIndexGetSupportsPresent = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redQueueFamilyIndexGetSupportsPresent");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redSurfaceGetPresentFeatures = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redSurfaceGetPresentFeatures");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redSurfaceGetCurrentPropertiesAndPresentLimits = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redSurfaceGetCurrentPropertiesAndPresentLimits");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redPresentGetImageIndex = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redPresentGetImageIndex");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redQueuePresent = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redQueuePresent");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redGpuVisTracingStart = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redGpuVisTracingStart");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redGpuVisTracingCapture = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redGpuVisTracingCapture");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redGpuVisTracingStop = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redGpuVisTracingStop");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDebugArrayGetHandle = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDebugArrayGetHandle");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDebugArrayCallPrint = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDebugArrayCallPrint");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateProcedureComputingLanguage = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateProcedureComputingLanguage");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateArrayTimestamp = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCreateArrayTimestamp");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyArrayTimestamp = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redDestroyArrayTimestamp");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallArrayTimestampWrite = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redCallArrayTimestampWrite");
    __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redArrayTimestampRead = REDGPU_PROFILE_LOAD_PROC(libredgpu, "redArrayTimestampRead");
#undef REDGPU_PROFILE_LOAD_PROC
  }
}

REDGPU_DECLSPEC void REDGPU_API redMemoryGetBudget(RedContext context, RedHandleGpu gpu, RedMemoryBudget * outMemoryBudget, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryGetBudget(context, gpu, outMemoryBudget, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redMemoryAllocate(RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t bytesCount, unsigned memoryTypeIndex, RedHandleArray dedicateToArray, RedHandleImage dedicateToImage, unsigned memoryBitflags, RedHandleMemory * outMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryAllocate(context, gpu, handleName, bytesCount, memoryTypeIndex, dedicateToArray, dedicateToImage, memoryBitflags, outMemory, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redMemoryAllocateMappable(RedContext context, RedHandleGpu gpu, const char * handleName, RedBool32 dedicate, RedHandleArray array, uint64_t arrayMemoryBytesCount, unsigned memoryTypeIndex, unsigned memoryBitflags, RedHandleMemory * outMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryAllocateMappable(context, gpu, handleName, dedicate, array, arrayMemoryBytesCount, memoryTypeIndex, memoryBitflags, outMemory, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redMemoryFree(RedContext context, RedHandleGpu gpu, RedHandleMemory memory, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryFree(context, gpu, memory, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redMemorySet(RedContext context, RedHandleGpu gpu, unsigned memoryArraysCount, const RedMemoryArray * memoryArrays, unsigned memoryImagesCount, const RedMemoryImage * memoryImages, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemorySet(context, gpu, memoryArraysCount, memoryArrays, memoryImagesCount, memoryImages, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redMemoryMap(RedContext context, RedHandleGpu gpu, RedHandleMemory mappableMemory, uint64_t mappableMemoryBytesFirst, uint64_t mappableMemoryBytesCount, void ** outVolatilePointer, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryMap(context, gpu, mappableMemory, mappableMemoryBytesFirst, mappableMemoryBytesCount, outVolatilePointer, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redMemoryUnmap(RedContext context, RedHandleGpu gpu, RedHandleMemory mappableMemory, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryUnmap(context, gpu, mappableMemory, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redMemoryNonCoherentFlush(RedContext context, RedHandleGpu gpu, unsigned mappableMemoryRangesCount, const RedMappableMemoryRange * mappableMemoryRanges, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryNonCoherentFlush(context, gpu, mappableMemoryRangesCount, mappableMemoryRanges, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redMemoryNonCoherentInvalidate(RedContext context, RedHandleGpu gpu, unsigned mappableMemoryRangesCount, const RedMappableMemoryRange * mappableMemoryRanges, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMemoryNonCoherentInvalidate(context, gpu, mappableMemoryRangesCount, mappableMemoryRanges, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redStructsMemoryAllocate(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned maxStructsCount, unsigned maxStructsMembersOfTypeArrayROConstantCount, unsigned maxStructsMembersOfTypeArrayROOrArrayRWCount, unsigned maxStructsMembersOfTypeTextureROCount, unsigned maxStructsMembersOfTypeTextureRWCount, RedHandleStructsMemory * outStructsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redStructsMemoryAllocate(context, gpu, handleName, maxStructsCount, maxStructsMembersOfTypeArrayROConstantCount, maxStructsMembersOfTypeArrayROOrArrayRWCount, maxStructsMembersOfTypeTextureROCount, maxStructsMembersOfTypeTextureRWCount, outStructsMemory, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redStructsMemoryAllocateSamplers(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned maxStructsCount, unsigned maxStructsMembersOfTypeSamplerCount, RedHandleStructsMemory * outStructsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redStructsMemoryAllocateSamplers(context, gpu, handleName, maxStructsCount, maxStructsMembersOfTypeSamplerCount, outStructsMemory, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redStructsMemorySuballocateStructs(RedContext context, RedHandleGpu gpu, const char ** handleNames, RedHandleStructsMemory structsMemory, unsigned structsDeclarationsCount, const RedHandleStructDeclaration * structsDeclarations, RedHandleStruct * outStructs, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redStructsMemorySuballocateStructs(context, gpu, handleNames, structsMemory, structsDeclarationsCount, structsDeclarations, outStructs, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redStructsMemoryReset(RedContext context, RedHandleGpu gpu, RedHandleStructsMemory structsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redStructsMemoryReset(context, gpu, structsMemory, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redStructsMemoryFree(RedContext context, RedHandleGpu gpu, RedHandleStructsMemory structsMemory, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redStructsMemoryFree(context, gpu, structsMemory, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redStructsSet(RedContext context, RedHandleGpu gpu, unsigned structsMembersCount, const RedStructMember * structsMembers, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redStructsSet(context, gpu, structsMembersCount, structsMembers, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateContext(RedTypeProcedureMalloc malloc, RedTypeProcedureFree free, RedTypeProcedureMallocTagged optionalMallocTagged, RedTypeProcedureFreeTagged optionalFreeTagged, RedTypeProcedureDebugCallback debugCallback, RedSdkVersion sdkVersion, unsigned sdkExtensionsCount, const unsigned * sdkExtensions, const char * optionalProgramName, unsigned optionalProgramVersion, const char * optionalEngineName, unsigned optionalEngineVersion, const void * optionalSettings, RedContext * outContext, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  redProfileInternalInitializeProcedurePointers();
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateContext(malloc, free, optionalMallocTagged, optionalFreeTagged, debugCallback, sdkVersion, sdkExtensionsCount, sdkExtensions, optionalProgramName, optionalProgramVersion, optionalEngineName, optionalEngineVersion, optionalSettings, outContext, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateArray(RedContext context, RedHandleGpu gpu, const char * handleName, RedArrayType type, uint64_t bytesCount, uint64_t structuredBufferElementBytesCount, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedArray * outArray, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateArray(context, gpu, handleName, type, bytesCount, structuredBufferElementBytesCount, initialAccess, initialQueueFamilyIndex, dedicate, outArray, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateImage(RedContext context, RedHandleGpu gpu, const char * handleName, RedImageDimensions dimensions, RedFormat format, unsigned width, unsigned height, unsigned depth, unsigned levelsCount, unsigned layersCount, RedMultisampleCountBitflag multisampleCount, RedAccessBitflags restrictToAccess, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedImage * outImage, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateImage(context, gpu, handleName, dimensions, format, width, height, depth, levelsCount, layersCount, multisampleCount, restrictToAccess, initialAccess, initialQueueFamilyIndex, dedicate, outImage, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateSampler(RedContext context, RedHandleGpu gpu, const char * handleName, RedSamplerFiltering filteringMag, RedSamplerFiltering filteringMin, RedSamplerFilteringMip filteringMip, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateU, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateV, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateW, float mipLodBias, RedBool32 enableAnisotropy, float maxAnisotropy, RedBool32 enableCompare, RedCompareOp compareOp, float minLod, float maxLod, RedHandleSampler * outSampler, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateSampler(context, gpu, handleName, filteringMag, filteringMin, filteringMip, behaviorOutsideTextureCoordinateU, behaviorOutsideTextureCoordinateV, behaviorOutsideTextureCoordinateW, mipLodBias, enableAnisotropy, maxAnisotropy, enableCompare, compareOp, minLod, maxLod, outSampler, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateTexture(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleImage image, RedImagePartBitflags parts, RedTextureDimensions dimensions, RedFormat format, unsigned levelsFirst, unsigned levelsCount, unsigned layersFirst, unsigned layersCount, RedAccessBitflags restrictToAccess, RedHandleTexture * outTexture, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateTexture(context, gpu, handleName, image, parts, dimensions, format, levelsFirst, levelsCount, layersFirst, layersCount, restrictToAccess, outTexture, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateGpuCode(RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t irBytesCount, const void * ir, RedHandleGpuCode * outGpuCode, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateGpuCode(context, gpu, handleName, irBytesCount, ir, outGpuCode, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateOutputDeclaration(RedContext context, RedHandleGpu gpu, const char * handleName, const RedOutputDeclarationMembers * outputDeclarationMembers, const RedOutputDeclarationMembersResolveSources * outputDeclarationMembersResolveSources, RedBool32 dependencyByRegion, RedBool32 dependencyByRegionAllowUsageAliasOrderBarriers, RedHandleOutputDeclaration * outOutputDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateOutputDeclaration(context, gpu, handleName, outputDeclarationMembers, outputDeclarationMembersResolveSources, dependencyByRegion, dependencyByRegionAllowUsageAliasOrderBarriers, outOutputDeclaration, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateStructDeclaration(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned structDeclarationMembersCount, const RedStructDeclarationMember * structDeclarationMembers, unsigned structDeclarationMembersArrayROCount, const RedStructDeclarationMemberArrayRO * structDeclarationMembersArrayRO, RedBool32 procedureParametersHandlesDeclaration, RedHandleStructDeclaration * outStructDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateStructDeclaration(context, gpu, handleName, structDeclarationMembersCount, structDeclarationMembers, structDeclarationMembersArrayROCount, structDeclarationMembersArrayRO, procedureParametersHandlesDeclaration, outStructDeclaration, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateProcedureParameters(RedContext context, RedHandleGpu gpu, const char * handleName, const RedProcedureParametersDeclaration * procedureParametersDeclaration, RedHandleProcedureParameters * outProcedureParameters, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateProcedureParameters(context, gpu, handleName, procedureParametersDeclaration, outProcedureParameters, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateProcedureCache(RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t fromBlobBytesCount, const void * fromBlob, RedHandleProcedureCache * outProcedureCache, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateProcedureCache(context, gpu, handleName, fromBlobBytesCount, fromBlob, outProcedureCache, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateProcedure(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, RedHandleOutputDeclaration outputDeclaration, RedHandleProcedureParameters procedureParameters, const char * gpuCodeVertexMainProcedureName, RedHandleGpuCode gpuCodeVertex, const char * gpuCodeFragmentMainProcedureName, RedHandleGpuCode gpuCodeFragment, const RedProcedureState * state, const void * stateExtension, RedBool32 deriveBase, RedHandleProcedure deriveFrom, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateProcedure(context, gpu, handleName, procedureCache, outputDeclaration, procedureParameters, gpuCodeVertexMainProcedureName, gpuCodeVertex, gpuCodeFragmentMainProcedureName, gpuCodeFragment, state, stateExtension, deriveBase, deriveFrom, outProcedure, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateProcedureCompute(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, RedHandleProcedureParameters procedureParameters, const char * gpuCodeMainProcedureName, RedHandleGpuCode gpuCode, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateProcedureCompute(context, gpu, handleName, procedureCache, procedureParameters, gpuCodeMainProcedureName, gpuCode, outProcedure, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateOutput(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleOutputDeclaration outputDeclaration, const RedOutputMembers * outputMembers, const RedOutputMembersResolveTargets * outputMembersResolveTargets, unsigned width, unsigned height, RedOutput * outOutput, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateOutput(context, gpu, handleName, outputDeclaration, outputMembers, outputMembersResolveTargets, width, height, outOutput, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateCpuSignal(RedContext context, RedHandleGpu gpu, const char * handleName, RedBool32 createSignaled, RedHandleCpuSignal * outCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateCpuSignal(context, gpu, handleName, createSignaled, outCpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateGpuSignal(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleGpuSignal * outGpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateGpuSignal(context, gpu, handleName, outGpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateGpuToCpuSignal(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleGpuToCpuSignal * outGpuToCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateGpuToCpuSignal(context, gpu, handleName, outGpuToCpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateCalls(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, RedCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateCalls(context, gpu, handleName, queueFamilyIndex, outCalls, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateCallsReusable(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, RedCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateCallsReusable(context, gpu, handleName, queueFamilyIndex, outCalls, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyContext(RedContext context, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyContext(context, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyArray(RedContext context, RedHandleGpu gpu, RedHandleArray array, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyArray(context, gpu, array, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyImage(RedContext context, RedHandleGpu gpu, RedHandleImage image, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyImage(context, gpu, image, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroySampler(RedContext context, RedHandleGpu gpu, RedHandleSampler sampler, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroySampler(context, gpu, sampler, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyTexture(RedContext context, RedHandleGpu gpu, RedHandleTexture texture, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyTexture(context, gpu, texture, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyGpuCode(RedContext context, RedHandleGpu gpu, RedHandleGpuCode gpuCode, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyGpuCode(context, gpu, gpuCode, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyOutputDeclaration(RedContext context, RedHandleGpu gpu, RedHandleOutputDeclaration outputDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyOutputDeclaration(context, gpu, outputDeclaration, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyStructDeclaration(RedContext context, RedHandleGpu gpu, RedHandleStructDeclaration structDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyStructDeclaration(context, gpu, structDeclaration, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyProcedureParameters(RedContext context, RedHandleGpu gpu, RedHandleProcedureParameters procedureParameters, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyProcedureParameters(context, gpu, procedureParameters, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyProcedureCache(RedContext context, RedHandleGpu gpu, RedHandleProcedureCache procedureCache, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyProcedureCache(context, gpu, procedureCache, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyProcedure(RedContext context, RedHandleGpu gpu, RedHandleProcedure procedure, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyProcedure(context, gpu, procedure, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyOutput(RedContext context, RedHandleGpu gpu, RedHandleOutput output, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyOutput(context, gpu, output, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyCpuSignal(RedContext context, RedHandleGpu gpu, RedHandleCpuSignal cpuSignal, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyCpuSignal(context, gpu, cpuSignal, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyGpuSignal(RedContext context, RedHandleGpu gpu, RedHandleGpuSignal gpuSignal, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyGpuSignal(context, gpu, gpuSignal, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyGpuToCpuSignal(RedContext context, RedHandleGpu gpu, RedHandleGpuToCpuSignal gpuToCpuSignal, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyGpuToCpuSignal(context, gpu, gpuToCpuSignal, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyCalls(RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedHandleCallsMemory callsMemory, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyCalls(context, gpu, calls, callsMemory, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redProcedureCacheGetBlob(RedContext context, RedHandleGpu gpu, RedHandleProcedureCache procedureCache, uint64_t * outBlobBytesCount, void * outBlob, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redProcedureCacheGetBlob(context, gpu, procedureCache, outBlobBytesCount, outBlob, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redProcedureCacheMergeCaches(RedContext context, RedHandleGpu gpu, unsigned sourceProcedureCachesCount, const RedHandleProcedureCache * sourceProcedureCaches, RedHandleProcedureCache targetProcedureCache, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redProcedureCacheMergeCaches(context, gpu, sourceProcedureCachesCount, sourceProcedureCaches, targetProcedureCache, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCpuSignalGetStatus(RedContext context, RedHandleGpu gpu, RedHandleCpuSignal cpuSignal, RedStatus * outStatus, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCpuSignalGetStatus(context, gpu, cpuSignal, outStatus, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCpuSignalWait(RedContext context, RedHandleGpu gpu, unsigned cpuSignalsCount, const RedHandleCpuSignal * cpuSignals, RedBool32 waitAll, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCpuSignalWait(context, gpu, cpuSignalsCount, cpuSignals, waitAll, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCpuSignalUnsignal(RedContext context, RedHandleGpu gpu, unsigned cpuSignalsCount, const RedHandleCpuSignal * cpuSignals, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCpuSignalUnsignal(context, gpu, cpuSignalsCount, cpuSignals, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redGpuToCpuSignalGetStatus(RedContext context, RedHandleGpu gpu, RedHandleGpuToCpuSignal gpuToCpuSignal, RedStatus * outStatus, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redGpuToCpuSignalGetStatus(context, gpu, gpuToCpuSignal, outStatus, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redGpuToCpuSignalUnsignal(RedContext context, RedHandleGpu gpu, RedHandleGpuToCpuSignal gpuToCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redGpuToCpuSignalUnsignal(context, gpu, gpuToCpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCallsSet(RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedHandleCallsMemory callsMemory, RedBool32 callsReusable, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallsSet(context, gpu, calls, callsMemory, callsReusable, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCallsEnd(RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedHandleCallsMemory callsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallsEnd(context, gpu, calls, callsMemory, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redGetCallProceduresAndAddresses(RedContext context, RedHandleGpu gpu, RedCallProceduresAndAddresses * outCallProceduresAndAddresses, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redGetCallProceduresAndAddresses(context, gpu, outCallProceduresAndAddresses, outStatuses, optionalFile, optionalLine, optionalUserData);
}

REDGPU_DECLSPEC void REDGPU_API redCallSetDynamicViewport(RedTypeProcedureAddressCallSetDynamicViewport address, RedHandleCalls calls, float x, float y, float width, float height, float depthMin, float depthMax) {
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallSetDynamicViewport(address, calls, x, y, width, height, depthMin, depthMax);
}

REDGPU_DECLSPEC void REDGPU_API redCallSetDynamicScissor(RedTypeProcedureAddressCallSetDynamicScissor address, RedHandleCalls calls, int x, int y, unsigned width, unsigned height) {
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallSetDynamicScissor(address, calls, x, y, width, height);
}

REDGPU_DECLSPEC void REDGPU_API redCallSetStructsMemory(RedTypeProcedureAddressCallSetStructsMemory address, RedHandleCalls calls, RedHandleStructsMemory structsMemory, RedHandleStructsMemory structsMemorySamplers) {
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallSetStructsMemory(address, calls, structsMemory, structsMemorySamplers);
}

REDGPU_DECLSPEC void REDGPU_API redCallSetProcedureParameters(RedTypeProcedureAddressCallSetProcedureParameters address, RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedureParameters procedureParameters) {
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallSetProcedureParameters(address, calls, procedureType, procedureParameters);
}

REDGPU_DECLSPEC void REDGPU_API redCallSetProcedureOutput(RedTypeProcedureAddressCallSetProcedureOutput address, RedHandleCalls calls, RedHandleOutputDeclaration outputDeclaration, RedHandleOutput output, RedInlineOutput * inlineOutput, unsigned outputWidth, unsigned outputHeight, RedBool32 outputDepthStencilEnable, unsigned outputColorsCount, float depthClearValue, unsigned stencilClearValue, const RedColorsClearValuesFloat * colorsClearValuesFloat, const RedColorsClearValuesSint * colorsClearValuesSint, const RedColorsClearValuesUint * colorsClearValuesUint) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallSetProcedureOutput(address, calls, outputDeclaration, output, inlineOutput, outputWidth, outputHeight, outputDepthStencilEnable, outputColorsCount, depthClearValue, stencilClearValue, colorsClearValuesFloat, colorsClearValuesSint, colorsClearValuesUint);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCallEndProcedureOutput(RedTypeProcedureAddressCallEndProcedureOutput address, RedHandleCalls calls) {
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallEndProcedureOutput(address, calls);
}

REDGPU_DECLSPEC void REDGPU_API redCallUsageAliasOrderBarrier(RedTypeProcedureAddressCallUsageAliasOrderBarrier address, RedHandleCalls calls, RedContext context, unsigned arrayUsagesCount, const RedUsageArray * arrayUsages, unsigned imageUsagesCount, const RedUsageImage * imageUsages, unsigned aliasesCount, const RedAlias * aliases, unsigned ordersCount, const RedOrder * orders, RedBool32 dependencyByRegion) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallUsageAliasOrderBarrier(address, calls, context, arrayUsagesCount, arrayUsages, imageUsagesCount, imageUsages, aliasesCount, aliases, ordersCount, orders, dependencyByRegion);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCallMark(RedTypeProcedureAddressCallMark address, RedHandleCalls calls, const char * mark) {
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallMark(address, calls, mark);
}

REDGPU_DECLSPEC void REDGPU_API redCallMarkSet(RedTypeProcedureAddressCallMarkSet address, RedHandleCalls calls, const char * mark) {
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallMarkSet(address, calls, mark);
}

REDGPU_DECLSPEC void REDGPU_API redCallMarkEnd(RedTypeProcedureAddressCallMarkEnd address, RedHandleCalls calls) {
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallMarkEnd(address, calls);
}

REDGPU_DECLSPEC void REDGPU_API redQueueSubmit(RedContext context, RedHandleGpu gpu, RedHandleQueue queue, unsigned timelinesCount, const RedGpuTimeline * timelines, RedHandleCpuSignal signalCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redQueueSubmit(context, gpu, queue, timelinesCount, timelines, signalCpuSignal, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redMark(const char * mark, const char * optionalFile, int optionalLine, void * optionalUserData) {
  redProfileInternalInitializeProcedurePointers();
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMark(mark, optionalFile, optionalLine, optionalUserData);
}

REDGPU_DECLSPEC void REDGPU_API redMarkSet(const char * mark, const char * optionalFile, int optionalLine, void * optionalUserData) {
  redProfileInternalInitializeProcedurePointers();
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMarkSet(mark, optionalFile, optionalLine, optionalUserData);
}

REDGPU_DECLSPEC void REDGPU_API redMarkEnd(const char * optionalFile, int optionalLine, void * optionalUserData) {
  redProfileInternalInitializeProcedurePointers();
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redMarkEnd(optionalFile, optionalLine, optionalUserData);
}

REDGPU_DECLSPEC void REDGPU_API redCreateSurfaceWin32(RedContext context, RedHandleGpu gpu, const char * handleName, const void * win32Hinstance, const void * win32Hwnd, RedHandleSurface * outSurface, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateSurfaceWin32(context, gpu, handleName, win32Hinstance, win32Hwnd, outSurface, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateSurfaceXlibOrXcb(RedContext context, RedHandleGpu gpu, const char * handleName, const void * xlibDisplay, unsigned long xlibWindow, const void * xcbConnection, unsigned xcbWindow, RedHandleSurface * outSurface, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateSurfaceXlibOrXcb(context, gpu, handleName, xlibDisplay, xlibWindow, xcbConnection, xcbWindow, outSurface, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreatePresent(RedContext context, RedHandleGpu gpu, RedHandleQueue queue, const char * handleName, RedHandleSurface surface, unsigned imagesCount, unsigned imagesWidth, unsigned imagesHeight, unsigned imagesLayersCount, RedAccessBitflags imagesRestrictToAccess, RedSurfaceTransformBitflag transform, RedSurfaceCompositeAlphaBitflag compositeAlpha, RedPresentVsyncMode vsyncMode, RedBool32 clipped, RedBool32 discardAfterPresent, RedHandlePresent oldPresent, RedHandlePresent * outPresent, RedHandleImage * outImages, RedHandleTexture * outTextures, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreatePresent(context, gpu, queue, handleName, surface, imagesCount, imagesWidth, imagesHeight, imagesLayersCount, imagesRestrictToAccess, transform, compositeAlpha, vsyncMode, clipped, discardAfterPresent, oldPresent, outPresent, outImages, outTextures, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroySurface(RedContext context, RedHandleGpu gpu, RedHandleSurface surface, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroySurface(context, gpu, surface, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyPresent(RedContext context, RedHandleGpu gpu, RedHandlePresent present, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyPresent(context, gpu, present, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redQueueFamilyIndexGetSupportsPresent(RedContext context, RedHandleGpu gpu, unsigned queueFamilyIndex, RedQueueFamilyIndexGetSupportsPresentOnWin32 * supportsPresentOnWin32, RedQueueFamilyIndexGetSupportsPresentOnXlib * supportsPresentOnXlib, RedQueueFamilyIndexGetSupportsPresentOnXcb * supportsPresentOnXcb, RedQueueFamilyIndexGetSupportsPresentOnSurface * supportsPresentOnSurface, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redQueueFamilyIndexGetSupportsPresent(context, gpu, queueFamilyIndex, supportsPresentOnWin32, supportsPresentOnXlib, supportsPresentOnXcb, supportsPresentOnSurface, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redSurfaceGetPresentFeatures(RedContext context, RedHandleGpu gpu, RedHandleSurface surface, RedSurfacePresentFeatures * outSurfacePresentFeatures, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redSurfaceGetPresentFeatures(context, gpu, surface, outSurfacePresentFeatures, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redSurfaceGetCurrentPropertiesAndPresentLimits(RedContext context, RedHandleGpu gpu, RedHandleSurface surface, RedSurfaceCurrentPropertiesAndPresentLimits * outSurfaceCurrentPropertiesAndPresentLimits, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redSurfaceGetCurrentPropertiesAndPresentLimits(context, gpu, surface, outSurfaceCurrentPropertiesAndPresentLimits, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redPresentGetImageIndex(RedContext context, RedHandleGpu gpu, RedHandlePresent present, RedHandleCpuSignal signalCpuSignal, RedHandleGpuSignal signalGpuSignal, unsigned * outImageIndex, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redPresentGetImageIndex(context, gpu, present, signalCpuSignal, signalGpuSignal, outImageIndex, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redQueuePresent(RedContext context, RedHandleGpu gpu, RedHandleQueue queue, unsigned waitForAndUnsignalGpuSignalsCount, const RedHandleGpuSignal * waitForAndUnsignalGpuSignals, unsigned presentsCount, const RedHandlePresent * presents, const unsigned * presentsImageIndex, RedStatus * outPresentsStatus, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redQueuePresent(context, gpu, queue, waitForAndUnsignalGpuSignalsCount, waitForAndUnsignalGpuSignals, presentsCount, presents, presentsImageIndex, outPresentsStatus, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redGpuVisTracingStart(const char * optionalFile, int optionalLine, void * optionalUserData) {
  redProfileInternalInitializeProcedurePointers();
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redGpuVisTracingStart(optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redGpuVisTracingCapture(const char * optionalFile, int optionalLine, void * optionalUserData) {
  redProfileInternalInitializeProcedurePointers();
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redGpuVisTracingCapture(optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redGpuVisTracingStop(const char * optionalFile, int optionalLine, void * optionalUserData) {
  redProfileInternalInitializeProcedurePointers();
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redGpuVisTracingStop(optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC RedHandleArray REDGPU_API redDebugArrayGetHandle(RedContext context, RedHandleGpu gpu, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  return __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDebugArrayGetHandle(context, gpu, outStatuses, optionalFile, optionalLine, optionalUserData);
}

REDGPU_DECLSPEC void REDGPU_API redDebugArrayCallPrint(RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDebugArrayCallPrint(context, gpu, calls, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateProcedureComputingLanguage(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, RedHandleProcedureParameters procedureParameters, const char * gpuCodeMainProcedureName, RedHandleGpuCode gpuCode, const void * stateExtension, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateProcedureComputingLanguage(context, gpu, handleName, procedureCache, procedureParameters, gpuCodeMainProcedureName, gpuCode, stateExtension, outProcedure, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCreateArrayTimestamp(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned count, RedHandleArrayTimestamp * outArrayTimestamp, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCreateArrayTimestamp(context, gpu, handleName, count, outArrayTimestamp, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redDestroyArrayTimestamp(RedContext context, RedHandleGpu gpu, RedHandleArrayTimestamp arrayTimestamp, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redDestroyArrayTimestamp(context, gpu, arrayTimestamp, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redCallArrayTimestampWrite(RedHandleCalls calls, RedContext context, RedHandleArrayTimestamp arrayTimestamp, unsigned index) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redCallArrayTimestampWrite(calls, context, arrayTimestamp, index);
  profileEnd(__FUNCTION__);
}

REDGPU_DECLSPEC void REDGPU_API redArrayTimestampRead(RedContext context, RedHandleGpu gpu, RedHandleArrayTimestamp arrayTimestamp, unsigned rangeFirst, unsigned rangeCount, void * out64BitTicksCounts, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  profileBegin(__FUNCTION__);
  __REDGPU_PROFILE_GLOBAL_cc96723e4dced66dd20eb710df8bf9075add8685d19d3ec3942c99212941b1ea_libredgpu.redArrayTimestampRead(context, gpu, arrayTimestamp, rangeFirst, rangeCount, out64BitTicksCounts, outStatuses, optionalFile, optionalLine, optionalUserData);
  profileEnd(__FUNCTION__);
}
