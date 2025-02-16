#pragma once

typedef enum RedXInternalTypeMemoryKind {
  REDX_INTERNAL_TYPE_MEMORY_KIND_UNDEFINED = 0,
  REDX_INTERNAL_TYPE_MEMORY_KIND_PLACED    = 1,
  REDX_INTERNAL_TYPE_MEMORY_KIND_DEDICATED = 2,
} RedXInternalTypeMemoryKind;

typedef enum RedXInternalTypeSurfaceType {
  REDX_INTERNAL_TYPE_SURFACE_TYPE_UNDEFINED = 0,
  REDX_INTERNAL_TYPE_SURFACE_TYPE_WIN32     = 1,
  REDX_INTERNAL_TYPE_SURFACE_TYPE_WINRT     = 2,
} RedXInternalTypeSurfaceType;

typedef struct RedXInternalTypeCpuDescriptorCBVSRVUAV {
  X12DescriptorHeap *         cpuDescriptorHeapCBVSRVUAV;
  D3D12_CPU_DESCRIPTOR_HANDLE cpuDescriptorCBVSRVUAV;
} RedXInternalTypeCpuDescriptorCBVSRVUAV;

typedef struct RedXInternalTypeCpuDescriptorSampler {
  X12DescriptorHeap *         cpuDescriptorHeapSampler;
  D3D12_CPU_DESCRIPTOR_HANDLE cpuDescriptorSampler;
} RedXInternalTypeCpuDescriptorSampler;

typedef struct RedXInternalTypeCpuDescriptorRTV {
  X12DescriptorHeap *         cpuDescriptorHeapRTV;
  D3D12_CPU_DESCRIPTOR_HANDLE cpuDescriptorRTV;
} RedXInternalTypeCpuDescriptorRTV;

typedef struct RedXInternalTypeCpuDescriptorDSV {
  X12DescriptorHeap *         cpuDescriptorHeapDSV;
  D3D12_CPU_DESCRIPTOR_HANDLE cpuDescriptorDSV;
} RedXInternalTypeCpuDescriptorDSV;

typedef struct RedXInternalTypeMemory {
  X12Heap *                  handle;
  X12Resource *              resource;
  RedContext                 context;
  unsigned                   gpuIndex;
  uint64_t                   bytesCount;
  unsigned                   memoryTypeIndex;
  RedBool32                  mapMemory;
  RedHandleArray             dedicateToArray;
  RedHandleImage             dedicateToImage;
  uint64_t                   mappedPointerRangeBytesFirst;
  uint64_t                   mappedPointerRangeBytesCount;
  void *                     mappedPointer;
  RedXInternalTypeMemoryKind kind;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string                handleName;
#endif
} RedXInternalTypeMemory;

typedef struct RedXInternalTypeStructsMemory {
  X12DescriptorHeap * handle;
  RedContext          context;
  unsigned            gpuIndex;
  unsigned            maxStructsCount;
  unsigned            maxStructsMembersOfTypeArrayROConstantCount;
  unsigned            maxStructsMembersOfTypeArrayROOrArrayRWCount;
  unsigned            maxStructsMembersOfTypeSamplerCount;
  unsigned            maxStructsMembersOfTypeTextureROCount;
  unsigned            maxStructsMembersOfTypeTextureRWCount;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string         handleName;
#endif
} RedXInternalTypeStructsMemory;

typedef struct RedXInternalTypeArray {
  X12Resource *                          handle;
  RedContext                             context;
  unsigned                               gpuIndex;
  RedArrayType                           type;
  uint64_t                               bytesCount;
  uint64_t                               structuredBufferElementBytesCount;
  RedAccessBitflags                      initialAccess;
  unsigned                               initialQueueFamilyIndex;
  RedBool32                              dedicate;
  uint64_t                               memoryBytesAlignment;
  uint64_t                               memoryBytesCount;
  unsigned                               memoryTypesSupported;
  RedXInternalTypeMemoryKind             memoryKind;
  unsigned                               memoryTypeIndex;
  RedMemoryArray                         memoryArray;
  D3D12_RESOURCE_DESC                    resourceDescription;
  RedXInternalTypeCpuDescriptorCBVSRVUAV cpuDescriptor;
  RedBool32                              destroyHandle;
  uint64_t                               mappedMemoryBytesFirst;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string                            handleName;
#endif
} RedXInternalTypeArray;

typedef struct RedXInternalTypeImage {
  X12Resource *              handle;
  RedContext                 context;
  unsigned                   gpuIndex;
  RedImageDimensions         dimensions;
  RedFormat                  format;
  unsigned                   xformat;
  unsigned                   width;
  unsigned                   height;
  unsigned                   depth;
  unsigned                   levelsCount;
  unsigned                   layersCount;
  RedMultisampleCountBitflag multisampleCount;
  RedAccessBitflags          restrictToAccess;
  RedAccessBitflags          restrictToAccessFinal;
  RedAccessBitflags          initialAccess;
  unsigned                   initialQueueFamilyIndex;
  RedBool32                  dedicate;
  uint64_t                   memoryBytesAlignment;
  uint64_t                   memoryBytesCount;
  unsigned                   memoryTypesSupported;
  RedXInternalTypeMemoryKind memoryKind;
  RedMemoryImage             memoryImage;
  D3D12_RESOURCE_DESC        resourceDescription;
  void *                     ownedByPresent;
  RedBool32                  destroyHandle;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string                handleName;
#endif
} RedXInternalTypeImage;

typedef struct RedXInternalTypeSampler {
  RedContext                                 context;
  unsigned                                   gpuIndex;
  RedSamplerFiltering                        filteringMag;
  RedSamplerFiltering                        filteringMin;
  RedSamplerFilteringMip                     filteringMip;
  RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateU;
  RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateV;
  RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateW;
  float                                      mipLodBias;
  RedBool32                                  enableAnisotropy;
  float                                      maxAnisotropy;
  RedBool32                                  enableCompare;
  RedCompareOp                               compareOp;
  float                                      minLod;
  float                                      maxLod;
  D3D12_SAMPLER_DESC                         samplerDescription;
  RedXInternalTypeCpuDescriptorSampler       cpuDescriptor;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string                                handleName;
#endif
} RedXInternalTypeSampler;

typedef struct RedXInternalTypeTexture {
  RedContext                             context;
  unsigned                               gpuIndex;
  RedXInternalTypeImage *                image;
  RedImagePartBitflags                   parts;
  RedTextureDimensions                   dimensions;
  RedFormat                              format;
  unsigned                               xformat;
  unsigned                               levelsFirst;
  unsigned                               levelsCount;
  unsigned                               layersFirst;
  unsigned                               layersCount;
  RedAccessBitflags                      restrictToAccess;
  RedXInternalTypeCpuDescriptorCBVSRVUAV cpuDescriptorSRV;
  RedXInternalTypeCpuDescriptorCBVSRVUAV cpuDescriptorUAV;
  RedXInternalTypeCpuDescriptorDSV       cpuDescriptorDSV;
  RedXInternalTypeCpuDescriptorRTV       cpuDescriptorRTV;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string                            handleName;
#endif
} RedXInternalTypeTexture;

typedef struct RedXInternalTypeStructDeclaration {
  RedContext                                context;
  unsigned                                  gpuIndex;
  RedBool32                                 procedureParametersHandlesDeclaration;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_VECTOR
  REDGPU_VECTOR<RedStructDeclarationMember> structDeclarationMembers;
#endif
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string                               handleName;
#endif
} RedXInternalTypeStructDeclaration;

typedef struct RedXInternalTypeProcedureParameters {
  X12RootSignature *                handle;
  RedContext                        context;
  unsigned                          gpuIndex;
  RedProcedureParametersDeclaration procedureParametersDeclaration;
  X12Blob *                         blob;
  X12Blob *                         blobError;
  unsigned                          rootParameterIndexStartVariables;
  unsigned                          rootParameterIndexStartHandles;
  unsigned                          rootParameterIndexStartStructs;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string                       handleName;
#endif
} RedXInternalTypeProcedureParameters;

typedef struct RedXInternalTypeProcedure {
  X12PipelineState *           handle;
  RedContext                   context;
  unsigned                     gpuIndex;
  RedBool32                    isCompute;
  RedHandleProcedureCache      procedureCache;
  RedHandleOutputDeclaration   outputDeclaration;
  RedHandleProcedureParameters procedureParameters;
  RedHandleGpuCode             gpuCodeVertex;
  RedHandleGpuCode             gpuCodeFragment;
  RedHandleGpuCode             gpuCodeCompute;
  RedProcedureState            state;
  RedBool32                    deriveBase;
  RedHandleProcedure           deriveFrom;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string                  gpuCodeVertexMainProcedureName;
  std::string                  gpuCodeFragmentMainProcedureName;
  std::string                  gpuCodeComputeMainProcedureName;
  std::string                  handleName;
#endif
} RedXInternalTypeProcedure;

typedef struct RedXInternalTypeQueue {
  X12CommandQueue * handle;
  RedContext        context;
  unsigned          gpuIndex;
  unsigned          queueFamilyIndex;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string       handleName;
#endif
} RedXInternalTypeQueue;

typedef struct RedXInternalTypeSignal {
  X12Fence *  handle;
  uint64_t    value;
  RedContext  context;
  unsigned    gpuIndex;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string handleName;
#endif
} RedXInternalTypeSignal;

typedef struct RedXInternalTypeCalls {
  X12CommandList *                       handle;
  X12CommandAllocator *                  memory;
  RedContext                             context;
  unsigned                               gpuIndex;
  RedBool32                              reusable;
  RedProcedureType                       currentProcedureTypeContext;
  RedXInternalTypeTexture *              currentDepthStencil;
  unsigned                               currentColorsCount;
  RedXInternalTypeTexture *              currentColors[8];
  RedStatuses                            statuses;
  size_t                                 gpuToCpuSignalsToSignalCount;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_VECTOR
  REDGPU_VECTOR<RedHandleGpuToCpuSignal> gpuToCpuSignalsToSignal;
#endif
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string                            handleName;
#endif
} RedXInternalTypeCalls;

typedef struct RedXInternalTypeSurface {
  const void *                window;
  RedContext                  context;
  unsigned                    gpuIndex;
  RedXInternalTypeSurfaceType type;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string                 handleName;
#endif
} RedXInternalTypeSurface;

typedef struct RedXInternalTypePresent {
  X12SwapChain3 *           handle;
  RedContext                context;
  unsigned                  gpuIndex;
  RedXInternalTypeQueue *   queue;
  RedXInternalTypeSurface * surface;
  RedXInternalTypeImage *   images[2];
  RedPresentVsyncMode       vsyncMode;
#ifndef REDGPU_X_INTERNAL_TYPES_EXCLUDE_STD_STRING
  std::string               handleName;
#endif
} RedXInternalTypePresent;
