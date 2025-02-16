// Copyright(C) 2019-2024 Constantine Tarasenkov (iamvfx@gmail.com). All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// cl /LD /EHsc /GR- /DREDGPU_X_INTERNAL_USE_STD_VECTOR redgpu_x.cpp
// cl /LD /EHsc /GR- /DREDGPU_X_INTERNAL_USE_EASTL_VECTOR /IEABase/include/Common /IEASTL/include redgpu_x.cpp

#if !defined(REDGPU_X_INTERNAL_USE_STD_VECTOR) && !defined(REDGPU_X_INTERNAL_USE_EASTL_VECTOR)
#error
#endif
#if  defined(REDGPU_X_INTERNAL_USE_STD_VECTOR) &&  defined(REDGPU_X_INTERNAL_USE_EASTL_VECTOR)
#error
#endif

#define X12_DECLSPEC static
#include "redgpu_x12.cpp"

#define REDGPU_DECLSPEC __declspec(dllexport)
#define REDGPU_X_DECLSPEC __declspec(dllexport)
#include "C:/RedGpuSDK/redgpu.h"
#include "C:/RedGpuSDK/redgpu_wsi.h"
#include "C:/RedGpuSDK/redgpu_x.h"
#include "C:/RedGpuSDK/redgpu_array_timestamp.h"
#include "C:/RedGpuSDK/redgpu_computing_language.h"

#include <pix.h>

#include <string>
#if defined(REDGPU_X_INTERNAL_USE_STD_VECTOR)
#include <vector> // For std::vector
#define REDGPU_VECTOR std::vector
#endif
#if defined(REDGPU_X_INTERNAL_USE_EASTL_VECTOR)
#include <EASTL/vector.h> // For eastl::vector, needs to include EABase/include/Common and EASTL/include folders.
#define REDGPU_VECTOR eastl::vector

// https://github.com/electronicarts/EASTL/issues/497

void * __cdecl operator new[](size_t size, const char * name, int flags, unsigned debugFlags, const char * file, int line) {
  return new uint8_t[size];
}

void * __cdecl operator new[](unsigned __int64 size, unsigned __int64 alignment, unsigned __int64 offset, char const * pName, int flags, unsigned int debugFlags, char const * file, int line) {
  return new uint8_t[size];
}

#endif

#define                  X12Factory4 IDXGIFactory4
#define                  X12Adapter3 IDXGIAdapter3
#define                   X12Device3 ID3D12Device3
#define                      X12Heap ID3D12Heap
#define                  X12Resource ID3D12Resource
#define            X12DescriptorHeap ID3D12DescriptorHeap
#define                  X12Pageable ID3D12Pageable
#define                      X12Blob ID3D10Blob
#define             X12RootSignature ID3D12RootSignature
#define X12RootSignatureDeserializer ID3D12RootSignatureDeserializer
#define             X12PipelineState ID3D12PipelineState
#define                     X12Fence ID3D12Fence
#define              X12CommandQueue ID3D12CommandQueue
#define          X12CommandAllocator ID3D12CommandAllocator
#define               X12CommandList ID3D12GraphicsCommandList
#define                X12SwapChain3 IDXGISwapChain3
#define                   X12Output4 IDXGIOutput4

#include "redgpu_x_internal_types.h"

typedef struct RedXInternalMemoryTypesArray {
  RedMemoryType memoryTypes[6];
} RedXInternalMemoryTypesArray;

typedef struct RedXInternalMemoryTypesDescriptionArray {
  const char * memoryTypesDescription[6];
} RedXInternalMemoryTypesDescriptionArray;

typedef struct RedXInternalMemoryTypesDescriptionStringArray {
  std::string memoryTypesDescriptionString[6];
} RedXInternalMemoryTypesDescriptionStringArray;

typedef struct RedXInternalMemoryHeapsArray {
  RedMemoryHeap memoryHeaps[2];
} RedXInternalMemoryHeapsArray;

typedef struct RedXInternalImageFormatsLimitsArray {
  RedImageFormatLimits imageFormatsLimits[131];
} RedXInternalImageFormatsLimitsArray;

typedef struct RedXInternalImageFormatsFeaturesArray {
  RedImageFormatFeatures imageFormatsFeatures[131];
} RedXInternalImageFormatsFeaturesArray;

typedef struct RedXInternalImageXFormatsLimitsArray {
  RedImageFormatLimits imageXFormatsLimits[14];
} RedXInternalImageXFormatsLimitsArray;

typedef struct RedXInternalImageXFormatsFeaturesArray {
  RedImageFormatFeatures  imageXFormatsFeatures[14];
  RedXImageFormatFeatures imageFormatsFeatures1[131];
  RedXImageFormatFeatures imageXFormatsFeatures1[14];
} RedXInternalImageXFormatsFeaturesArray;

typedef struct RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT {
  HRESULT               hresult;
  D3D12_FORMAT_SUPPORT1 Support1;
  D3D12_FORMAT_SUPPORT2 Support2;
} RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT;

typedef struct RedXInternalImageD3D12FormatsFeaturesArray {
  RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT imageD3D12FormatsFeatures[116];
} RedXInternalImageD3D12FormatsFeaturesArray;

typedef struct RED_INTERNAL_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS {
  RedMultisampleCountBitflags supportedMultisampleCounts;
} RED_INTERNAL_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS;

typedef struct RedXInternalImageD3D12FormatsMultisampleFeaturesArray {
  RED_INTERNAL_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS imageD3D12FormatsMultisampleFeatures[116];
} RedXInternalImageD3D12FormatsMultisampleFeaturesArray;

// NOTE(Constantine): Copy of RedGpuInfo without const's.
typedef struct RedXInternalTypeGpuInfo {
  RedHandleGpu                   gpu;
  RedHandleGpuDevice             gpuDevice;
  char                           gpuName[256];
  RedGpuType                     gpuType;
  unsigned                       gpuVendorId;
  unsigned                       gpuDeviceId;
  unsigned                       gpuDriverVersion;
  unsigned char                  gpuProcedureCacheUuid[16];
  // Memory
  unsigned                       memoryTypesCount;
  RedMemoryType *                memoryTypes;            // Array of memoryTypesCount
  char **                        memoryTypesDescription; // Array of memoryTypesCount, can be 0
  unsigned                       memoryHeapsCount;
  RedMemoryHeap *                memoryHeaps;            // Array of memoryHeapsCount
  char **                        memoryHeapsDescription; // Array of memoryHeapsCount, can be 0
  // Queues
  unsigned                       queuesCount;
  RedHandleQueue *               queues;
  char **                        queuesDescription; // Array of queuesCount, can be 0
  unsigned *                     queuesFamilyIndex; // Array of queuesCount
  RedBool32 *                    queuesCanCopy;     // Array of queuesCount
  RedBool32 *                    queuesCanDraw;     // Array of queuesCount
  RedBool32 *                    queuesCanCompute;  // Array of queuesCount
  // Limits: Queues
  RedQueueCopyLimits *           queuesCopyLimits;  // Array of queuesCount
  // Limits: Memory                                                           // Guaranteed limits:       // Limits descriptions:
  unsigned                       maxMemoryAllocateCount;                      // Min: 4096                // Max number of allocations redMemoryAllocate* can make
  uint64_t                       minMemoryAllocateBytesAlignment;             // Min: 64                  // Min alignment bytes for redMemoryAllocate*::bytesCount
  uint64_t                       maxMemoryAllocateBytesCount;                 // Min: 2^30                // Max number of bytes for redMemoryAllocate*::bytesCount, even if there is more space available in the heap
  uint64_t                       minMemoryNonCoherentBlockBytesCount;         // Max: 256                 // Min bytes count and alignment bytes for non-coherent memory blocks. Non-coherent memory must operate only on blocks of this size. The end of non-coherent memory must be aligned to this limit (internal issue 611)
  unsigned                       maxCreateSamplerCount;                       // Min: 4000                // Max number of samplers redCreateSampler can allocate
  uint64_t                       minMemoryPageSeparationArrayImageBytesCount; // Min: 1, max: 2 * 65536   // Page separation in bytes between an array and an image to not alias each other, and vice versa. That is, the end of one resource and the beginning of the next resource with a different resource type must be on separate "pages" of size minMemoryPageSeparationArrayImageBytesCount
  // Limits: Arrays
  uint64_t                       minArrayROCStructMemberRangeBytesAlignment;  // Min: 1, max: 256         // Min alignment bytes for RedStructMemberArray::arrayRangeBytesFirst and RedStructMemberArray::arrayRangeBytesCount for RO constant arrays
  uint64_t                       maxArrayROCStructMemberRangeBytesCount;      // Min: 16384, on PC: 65536 // Max number of bytes for RedStructMemberArray::arrayRangeBytesCount                                                for RO constant arrays
  uint64_t                       minArrayRORWStructMemberRangeBytesAlignment; // Min: 1, max: 256         // Min alignment bytes for RedStructMemberArray::arrayRangeBytesFirst and RedStructMemberArray::arrayRangeBytesCount for RO or RW    arrays
  uint64_t                       maxArrayRORWStructMemberRangeBytesCount;     // Min: 2^27 (2048 * 65536) // Max number of bytes for RedStructMemberArray::arrayRangeBytesCount                                                for RO or RW    arrays
  unsigned                       maxArrayIndexUint32Value;                    // Min: (2^24)-1            // Max index value that can be used for indexed procedure calls. -1 excludes the primitive restart index value of 0xFFFFFFFF
  // Limits: Images
  unsigned                       maxImageDimensions1D;                        // Min: 4096                // Max dimension (width)                    supported for RED_IMAGE_DIMENSIONS_1D images
  unsigned                       maxImageDimensions2D;                        // Min: 4096                // Max dimension (width or height)          supported for RED_IMAGE_DIMENSIONS_2D images
  unsigned                       maxImageDimensions3D;                        // Min: 256                 // Max dimension (width or height or depth) supported for RED_IMAGE_DIMENSIONS_3D and RED_IMAGE_DIMENSIONS_3D_WITH_TEXTURE_DIMENSIONS_2D_AND_2D_LAYERED images
  unsigned                       maxImageDimensionsCube;                      // Min: 4096                // Max dimension (width or height)          supported for RED_IMAGE_DIMENSIONS_2D_WITH_TEXTURE_DIMENSIONS_CUBE_AND_CUBE_LAYERED images
  unsigned                       maxImageLayersCount;                         // Min: 256                 // Max number of layers for a layered image
  // Limits: Samplers
  float                          maxSamplerMipLodBias;                        // Min: 2.f                 // Max absolute sampler LOD bias. The sum of the redCreateSampler::mipLodBias and the Bias operand of image sampling operations in GPU code (or 0 if no Bias operand is provided to an image sampling operation) are clamped to the range [-maxSamplerMipLodBias,+maxSamplerMipLodBias]
  float                          maxSamplerAnisotropy;                        // Min: 16.f                // Max degree of sampler anisotropy. The maximum degree of anisotropic filtering used for an image sampling operation is the minimum of the redCreateSampler::maxAnisotropy and this limit
  unsigned                       precisionBitsSamplerFilteringMagMin;         // Min: 4                   // The number of bits of precision in the division along an axis of an image used for magnification and minification filters. 2^precisionBitsSamplerFilteringMagMin is the actual number of divisions along each axis of the image represented. Sub-texel values calculated during image sampling will snap to these locations when generating the filtered results
  unsigned                       precisionBitsSamplerFilteringMip;            // Min: 4                   // The number of bits of precision in the division that the LOD calculation for mip fetching get snapped to when determining the contribution from each mip level to the mip filtered results. 2^precisionBitsSamplerFilteringMip is the actual number of divisions. For example, if this value is 2 bits then when linearly filtering between two levels, each level could contribute 0%, 33%, 66%, or 100% (this is just an example and the amount of contribution should be covered by different equations)
  // Limits: Output declarations and outputs
  unsigned                       maxOutputWidth;                              // Min: 4096                // Max width  for an output
  unsigned                       maxOutputHeight;                             // Min: 4096                // Max height for an output
  unsigned                       maxOutputColorsCount;                        // Min: 4, max: 8           // Max number of colors an output can have
  RedMultisampleCountBitflags    supportedMultisampleCountsForOutputDepth;    // Min: 1 | 4               // Supported multisample counts for output depth
  RedMultisampleCountBitflags    supportedMultisampleCountsForOutputStencil;  // Min: 1 | 4               // Supported multisample counts for output stencil
  RedMultisampleCountBitflags    supportedMultisampleCountsForOutputColor;    // Min: 1 | 4               // Supported multisample counts for output color with floating-point formats. Does not cover integer formats (internal issue 550, c8c0862dee6ba9ed861e87648c59fcdf8a032f3a)
  RedMultisampleCountBitflags    supportedMultisampleCountsForEmptyOutput;    // Min: 1 | 4               // Supported multisample counts for empty output
  // Limits: Struct declarations and structs
  unsigned                       maxStructSlotsCount;                         // Min: 1024                // Max number of slots a struct can have
  unsigned                       maxStructPerStageArrayROCsCount;             // Min: 12                  // Max number of RO constant arrays allowed per-stage in a struct
  unsigned                       maxStructPerStageArrayRORWsCount;            // Min: 4                   // Max number of RO or RW    arrays allowed per-stage in a struct
  unsigned                       maxStructPerStageSamplersCount;              // Min: 16                  // Max number of samplers      allowed per-stage in a struct
  unsigned                       maxStructPerStageTextureROsCount;            // Min: 16                  // Max number of RO textures   allowed per-stage in a struct
  unsigned                       maxStructPerStageTextureRWsCount;            // Min: 4                   // Max number of RW textures   allowed per-stage in a struct
  unsigned                       maxStructPerStageAllResourcesCount;          // Min: 128                 // Max number of all resources allowed per-stage in a struct
  unsigned                       maxStructArrayROCsCount;                     // Min: 12 * stages count   // Max number of RO constant arrays allowed in all stages in a struct
  unsigned                       maxStructArrayRORWsCount;                    // Min: 4  * stages count   // Max number of RO or RW    arrays allowed in all stages in a struct
  unsigned                       maxStructSamplersCount;                      // Min: 16 * stages count   // Max number of samplers      allowed in all stages in a struct
  unsigned                       maxStructTextureROsCount;                    // Min: 16 * stages count   // Max number of RO textures   allowed in all stages in a struct
  unsigned                       maxStructTextureRWsCount;                    // Min: 4  * stages count   // Max number of RW textures   allowed in all stages in a struct
  // Limits: Procedure parameters
  unsigned                       maxProcedureParametersVariablesBytesCount;   // Min: 128                 // Max number of bytes for procedure parameters variables in all stages
  // Limits: Viewport
  unsigned                       maxViewportDimensions[2];                    // Min: 4096, 4096          // Max viewport dimensions (width, height)
  float                          minViewportBoundsRange;                      // Max: -8192.f             // Min viewport bounds range that the corners of a viewport must be contained in
  float                          maxViewportBoundsRange;                      // Min: 8191.f              // Max Viewport bounds range that the corners of a viewport must be contained in
  unsigned                       precisionBitsViewportCoordinates;            // Min: 4                   // The number of bits of subpixel precision in  viewport coordinates x and y
  unsigned                       precisionBitsViewportBounds;                 // Min: 0                   // The number of bits of subpixel precision for viewport bounds. The subpixel precision that floating-point viewport bounds are interpreted at is given by this limit
  // Limits: Vertex stage and fragment stage
  unsigned                       maxPerStageClipDistances;                    // Min: 8                   // Max number of clip distances allowed per-stage
  unsigned                       maxPerStageCullDistances;                    // Min: 8                   // Max number of cull distances allowed per-stage
  unsigned                       maxPerStageClipAndCullDistances;             // Min: 8                   // Max number of clip and cull distances combined allowed per-stage. The sum of the sizes of any pair of arrays declared with the ClipDistance and CullDistance built-in decoration used by a single stage must be less than or equal to this limit
  // Limits: Vertex stage
  unsigned                       maxVertexOutputLocationsCount;               // Min: 64                  // Max number of output locations in the vertex   stage. All location values used in GPU code must be below this limit
  // Limits: Fragment stage
  unsigned                       maxFragmentInputLocationsCount;              // Min: 64                  // Max number of input  locations in the fragment stage. All location values used in GPU code must be below this limit
  unsigned                       maxFragmentOutputColorsCount;                // Min: 4, max: 8           // Max number of output colors in the fragment stage
  unsigned                       maxFragmentOutputColorsCountBlendDualSource; // Min: 1, max: 8           // Max number of output colors in the fragment stage when using dual-source blend
  unsigned                       maxFragmentOutputResourcesCount;             // Min: 4                   // Max number of RW arrays, RW textures and output colors combined
  // Limits: Compute stage
  unsigned                       maxComputeSharedMemoryBytesCount;            // Min: 16384, on PC: 32768 // Max number of bytes for shared memory
  unsigned                       maxComputeWorkgroupsCount[3];                // Min: 65535, 65535, 65535 // Max number of compute workgroups (workgroupsCountX, workgroupsCountY, workgroupsCountZ) that may be dispatched by a single redCallProcedureCompute call
  unsigned                       maxComputeWorkgroupInvocationsCount;         // Min: 128                 // Max number of compute invocations in a single workgroup
  unsigned                       maxComputeWorkgroupDimensions[3];            // Min: 128, 128, 64        // Max workgroup dimensions (x, y, z)
  // Limits: OpImageSample*, OpImageFetch*
  int                            minImageSampleImageFetchOffset;              // Max: -8                  // The minimum offset value for the ConstOffset image operand of any of the OpImageSample* or OpImageFetch* image IR instructions
  unsigned                       maxImageSampleImageFetchOffset;              // Min: 7                   // The maximum offset value for the ConstOffset image operand of any of the OpImageSample* or OpImageFetch* image IR instructions
  // Limits: OpImage*Gather
  int                            minImageGatherOffset;                        // Max: -8                  // The minimum offset value for the Offset or ConstOffsets image operands of any of the OpImage*Gather image IR instructions
  unsigned                       maxImageGatherOffset;                        // Min: 7                   // The maximum offset value for the Offset or ConstOffsets image operands of any of the OpImage*Gather image IR instructions
  // Limits: interpolateAtOffset
  float                          minInterpolateAtOffset;                      // Max: -0.5f                                               // The minimum negative offset value for the offset operand of the InterpolateAtOffset extended IR instruction. The value describes the closed interval of supported interpolation offsets
  float                          maxInterpolateAtOffset;                      // Min: 0.5f - (1.f / 2.f^precisionBitsInterpolateAtOffset) // The maximum positive offset value for the offset operand of the InterpolateAtOffset extended IR instruction. The value describes the closed interval of supported interpolation offsets
  unsigned                       precisionBitsInterpolateAtOffset;            // Min: 4                                                   // The number of subpixel fractional bits that the x and y offsets to the InterpolateAtOffset extended IR instruction may be rounded to as fixed-point values. If precisionBitsInterpolateAtOffset is 4, this provides increments of (1.f / 2.f^4) = 0.0625, and thus the range of supported interpolation offsets would be [-0.5, 0.4375]
  // Limits: Copy calls
  uint64_t                       optimalCopyArrayImageRangeArrayBytesFirstBytesAlignment;
  uint64_t                       optimalCopyArrayImageRangeArrayTexelsCountToNextRowBytesAlignment;
  // Features
  RedBool32                      supportsWsi;                                            // WSI specific functionality is supported by the GPU.                                          If this feature is not available, the GPU handle should not be passed to WSI specific procedures
  RedBool32                      supportsMemoryGetBudget;                                // redMemoryGetBudget can return memory budget values.                                          If this feature is not available, redMemoryGetBudget::outMemoryBudget values won't be set and redMemoryGetBudget::outStatuses will return RED_STATUS_ERROR_FEATURE_IS_NOT_FOUND
  RedBool32                      supportsFullArrayIndexUint32Value;                      // Full 32-bit range of indices is supported.                                                   If this feature is available,     maxArrayIndexUint32Value must be (2^32)-1. -1 excludes the primitive restart index value of 0xFFFFFFFF
  RedBool32                      supportsSamplerAnisotropy;                              // Anisotropic filtering is supported.                                                          If this feature is not available, the redCreateSampler::enableAnisotropy must be set to 0 and the redCreateSampler::maxAnisotropy is ignored
  RedBool32                      supportsTextureDimensionsCubeLayered;                   // Specifies whether RED_TEXTURE_DIMENSIONS_CUBE_LAYERED textures can be created.               If this feature is available,     the SampledCubeArray and ImageCubeArray IR capabilities can be used
  RedBool32                      supportsProcedureStateRasterizationDepthClamp;          // Depth clamping is supported.                                                                 If this feature is not available, the RedProcedureState::rasterizationDepthClampEnable     must be set to 0
  RedBool32                      supportsProcedureStateRasterizationDepthBiasDynamic;    // Dynamic depth bias is supported.                                                             If this feature is not available, the RedProcedureState::rasterizationDepthBiasDynamic     must be set to 0 and redCallSetDynamicDepthBias          must not be called
  RedBool32                      supportsProcedureStateRasterizationDepthBiasClamp;      // Depth bias clamping is supported.                                                            If this feature is not available, the RedProcedureState::rasterizationDepthBiasStaticClamp must be set to 0 and if RedProcedureState::rasterizationDepthBiasDynamic is available redCallSetDynamicDepthBias::clamp must be set to 0
  RedBool32                      supportsProcedureStateMultisampleSampleShading;         // Specifies whether sample shading and multisample interpolation are supported.                If this feature is not available, the RedProcedureState::multisampleSampleShadingEnable    must be set to 0 and the RedProcedureState::multisampleSampleShadingMin is ignored. This also specifies whether IR can declare the SampleRateShading capability
  RedBool32                      supportsProcedureStateMultisampleAlphaToOne;            // The fragment alpha component can be forced to maximum representable alpha value.             If this feature is not available, the RedProcedureState::multisampleAlphaToOneEnable       must be set to 0
  RedBool32                      supportsProcedureStateDepthTestBoundsTest;              // Depth bounds test is supported.                                                              If this feature is not available, the RedProcedureState::depthTestBoundsTestEnable         must be set to 0 and the RedProcedureState::depthTestBoundsTestStaticMin, RedProcedureState::depthTestBoundsTestStaticMax, redCallSetDynamicDepthBounds::min and redCallSetDynamicDepthBounds::max are ignored
  RedBool32                      supportsProcedureStateDepthTestBoundsTestDynamic;       // Dynamic depth bounds test is supported.                                                      If this feature is not available, the RedProcedureState::depthTestBoundsTestDynamic        must be set to 0 and redCallSetDynamicDepthBounds        must not be called
  RedBool32                      supportsProcedureStateStencilTestFrontAndBackDynamicCompareMask; // Dynamic compare mask is supported.                                                  If this feature is not available, the RedProcedureState::stencilTestFrontAndBackDynamicCompareMask must be set to 0 and redCallSetDynamicStencilCompareMask must not be called
  RedBool32                      supportsProcedureStateStencilTestFrontAndBackDynamicWriteMask;   // Dynamic write mask is supported.                                                    If this feature is not available, the RedProcedureState::stencilTestFrontAndBackDynamicWriteMask   must be set to 0 and redCallSetDynamicStencilWriteMask   must not be called
  RedBool32                      supportsProcedureStateBlendLogicOp;                     // Logic operations are supported.                                                              If this feature is not available, the RedProcedureState::blendLogicOpEnable                must be set to 0 and the RedProcedureState::blendLogicOp is ignored
  RedBool32                      supportsProcedureStateOutputColorsBlendVaryingPerColor; // Blend operations are controlled per output color.                                            If this feature is not available, the RedProcedureState::outputColorsBlend* values for all output colors must be identical. Otherwise, different RedProcedureState::outputColorsBlend* values can be provided for output colors
  RedBool32                      supportsProcedureStateOutputColorsBlendDualSource;      // Blend operations which take two sources are supported.                                       If this feature is not available, the RED_BLEND_FACTOR_SOURCE1_COLOR, RED_BLEND_FACTOR_ONE_MINUS_SOURCE1_COLOR, RED_BLEND_FACTOR_SOURCE1_ALPHA or RED_BLEND_FACTOR_ONE_MINUS_SOURCE1_ALPHA must not be used as source or target blend factors
  RedBool32                      supportsMultisampleEmptyOutputVariableMultisampleCount; // Multisample rate can be different for all procedure calls in an empty output.                If this feature is not available, the current output is empty, and this is not the first procedure call for the current output, then the multisample count specified by this procedure must match that set in the previous procedure
  RedBool32                      supportsMultisampleStandardSampleLocations;             // Specifies whether rasterization uses the standard sample locations.                          If this feature is available,     the implementation uses the documented sample locations. Otherwise, the implementation may use different sample locations
  RedBool32                      supportsGpuCodeWritesAndAtomicsInStageVertex;           // Writes and atomic operations on RW textures are supported in the vertex   stage.             If this feature is not available, all RW texture variables used by the vertex   stage in GPU code must be decorated with the NonWritable decoration in IR
  RedBool32                      supportsGpuCodeWritesAndAtomicsInStageFragment;         // Writes and atomic operations on RW textures are supported in the fragment stage.             If this feature is not available, all RW texture variables used by the fragment stage in GPU code must be decorated with the NonWritable decoration in IR
  RedBool32                      supportsGpuCodeImageGatherExtended;                     // The extended set of texture gather IR instructions are available in GPU code.                If this feature is not available, the OpImage*Gather IR instructions do not support the Offset and ConstOffsets operands. This also specifies whether IR can declare the ImageGatherExtended capability
  RedBool32                      supportsGpuCodeTextureRWExtendedFormats;                // All the extended RW texture formats are available in GPU code.                               See StorageImageExtendedFormats in IR specification (internal issue 1273, 0a7a04f32bd473bc7428efdbbbe132f33afad68c)
  RedBool32                      supportsGpuCodeTextureRWMultisample;                    // Multisample RW textures are supported.                                                       If this feature is not available, images set as RED_STRUCT_MEMBER_TYPE_TEXTURE_RW must be created with multisample count equal to RED_MULTISAMPLE_COUNT_BITFLAG_1. This also specifies whether IR can declare the StorageImageMultisample capability
  RedBool32                      supportsGpuCodeTextureRWReadWithoutFormat;              // RW textures don't require a format qualifier to be specified when reading from  RW textures. If this feature is not available, the OpImageRead  IR instruction must not have an OpTypeImage of Unknown. This also specifies whether IR can declare the StorageImageReadWithoutFormat  capability
  RedBool32                      supportsGpuCodeTextureRWWriteWithoutFormat;             // RW textures don't require a format qualifier to be specified when writing to    RW textures. If this feature is not available, the OpImageWrite IR instruction must not have an OpTypeImage of Unknown. This also specifies whether IR can declare the StorageImageWriteWithoutFormat capability
  RedBool32                      supportsGpuCodeDynamicallyIndexableArraysOfArrayROCs;   // Arrays of RO constant arrays can be indexed by dynamically uniform integer expressions in GPU code. If this feature is not available, resources with a struct member type of RED_STRUCT_MEMBER_TYPE_ARRAY_RO_CONSTANT must be indexed only by constant integral expressions when aggregated into arrays in GPU code. This also specifies whether IR can declare the UniformBufferArrayDynamicIndexing capability
  RedBool32                      supportsGpuCodeDynamicallyIndexableArraysOfArrayRORWs;  // Arrays of RO or RW    arrays can be indexed by dynamically uniform integer expressions in GPU code. If this feature is not available, resources with a struct member type of RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW       must be indexed only by constant integral expressions when aggregated into arrays in GPU code. This also indicates whether IR can declare the StorageBufferArrayDynamicIndexing capability
  RedBool32                      supportsGpuCodeDynamicallyIndexableArraysOfSamplers;    // Arrays of samplers           can be indexed by dynamically uniform integer expressions in GPU code. If this feature is not available, resources with a struct member type of RED_STRUCT_MEMBER_TYPE_SAMPLER           must be indexed only by constant integral expressions when aggregated into arrays in GPU code. This also specifies whether IR can declare the SampledImageArrayDynamicIndexing  capability
  RedBool32                      supportsGpuCodeDynamicallyIndexableArraysOfTextureROs;  // Arrays of RO textures        can be indexed by dynamically uniform integer expressions in GPU code. If this feature is not available, resources with a struct member type of RED_STRUCT_MEMBER_TYPE_TEXTURE_RO        must be indexed only by constant integral expressions when aggregated into arrays in GPU code. This also specifies whether IR can declare the SampledImageArrayDynamicIndexing  capability
  RedBool32                      supportsGpuCodeDynamicallyIndexableArraysOfTextureRWs;  // Arrays of RW textures        can be indexed by dynamically uniform integer expressions in GPU code. If this feature is not available, resources with a struct member type of RED_STRUCT_MEMBER_TYPE_TEXTURE_RW        must be indexed only by constant integral expressions when aggregated into arrays in GPU code. This also specifies whether IR can declare the StorageImageArrayDynamicIndexing  capability
  RedBool32                      supportsGpuCodeClipDistance;                            // Clip distances are supported in GPU code.                                                    If this feature is not available, any members decorated with the ClipDistance built-in decoration must not be read from or written to in GPU code. This also specifies whether IR can declare the ClipDistance capability
  RedBool32                      supportsGpuCodeCullDistance;                            // Cull distances are supported in GPU code.                                                    If this feature is not available, any members decorated with the CullDistance built-in decoration must not be read from or written to in GPU code. This also specifies whether IR can declare the CullDistance capability
  RedBool32                      supportsGpuCodeInt64;                                   // 64-bit integers (signed and unsigned) are supported in GPU code.                             If this feature is not available, 64-bit integer        types must not be used in GPU code. This also specifies whether IR can declare the Int64   capability
  RedBool32                      supportsGpuCodeFloat64;                                 // 64-bit floats   (doubles)             are supported in GPU code.                             If this feature is not available, 64-bit floating-point types must not be used in GPU code. This also specifies whether IR can declare the Float64 capability
  RedBool32                      supportsGpuCodeMinLod;                                  // Image operations that specify the minimum resource LOD are supported in GPU code.            If this feature is not available, the    MinLod image operand must not be used in GPU code. This also specifies whether IR can declare the MinLod  capability
  // Image formats
  RedImageFormatLimits *         imageFormatsLimitsImageDimensions1D;                                        // Count: 131, indexable with RedFormat values
  RedImageFormatLimits *         imageFormatsLimitsImageDimensions2D;                                        // Count: 131, indexable with RedFormat values
  RedImageFormatLimits *         imageFormatsLimitsImageDimensions2DMultisample;                             // Count: 131, indexable with RedFormat values
  RedImageFormatLimits *         imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered; // Count: 131, indexable with RedFormat values
  RedImageFormatLimits *         imageFormatsLimitsImageDimensions3D;                                        // Count: 131, indexable with RedFormat values
  RedImageFormatLimits *         imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered;     // Count: 131, indexable with RedFormat values
  RedImageFormatFeatures *       imageFormatsFeatures;                                                       // Count: 131, indexable with RedFormat values
  void *                         optionalInfo;                                                               // A 0 or a pointer to a singly linked list of RedGpuInfoOptionalInfo* structs
} RedXInternalTypeGpuInfo;

typedef struct RedXInternalTypeContext {
  unsigned                                                               gpusCount;
  RedXInternalTypeGpuInfo *                                              gpus;
  RedStatuses *                                                          gpusStatuses;
  RedHandleContext                                                       contextHandle;
  void *                                                                 userData;
  struct {
    RedTypeProcedureDebugCallback                                        debugCallback;
    void *                                                               debugContext;
    D3D_FEATURE_LEVEL                                                    d3dFeatureLevel;
    RedBool32                                                            requestedExtensions[16];
    RedBool32                                                            memoryAllocateZeroed;
    REDGPU_VECTOR<IDXGIAdapter3 *>                                       adapters;
    REDGPU_VECTOR<RedXInternalMemoryTypesArray>                          adaptersMemoryTypes;
    REDGPU_VECTOR<RedXInternalMemoryTypesDescriptionArray>               adaptersMemoryTypesDescription;
    REDGPU_VECTOR<RedXInternalMemoryTypesDescriptionStringArray>         adaptersMemoryTypesDescriptionString;
    REDGPU_VECTOR<RedXInternalMemoryHeapsArray>                          adaptersMemoryHeaps;
    REDGPU_VECTOR<REDGPU_VECTOR<RedHandleQueue>>                         adaptersQueues;
    REDGPU_VECTOR<REDGPU_VECTOR<unsigned>>                               adaptersQueuesFamilyIndex;
    REDGPU_VECTOR<REDGPU_VECTOR<RedBool32>>                              adaptersQueuesCanCopy;
    REDGPU_VECTOR<REDGPU_VECTOR<RedBool32>>                              adaptersQueuesCanDraw;
    REDGPU_VECTOR<REDGPU_VECTOR<RedBool32>>                              adaptersQueuesCanCompute;
    REDGPU_VECTOR<REDGPU_VECTOR<RedQueueCopyLimits>>                     adaptersQueuesCopyLimits;
    REDGPU_VECTOR<RedXInternalImageD3D12FormatsFeaturesArray>            adaptersImageD3D12FormatsFeatures;
    REDGPU_VECTOR<RedXInternalImageD3D12FormatsMultisampleFeaturesArray> adaptersImageD3D12FormatsMultisampleFeatures;
    REDGPU_VECTOR<RedXInternalImageFormatsLimitsArray>                   adaptersImageFormatsLimitsImageDimensions1D;
    REDGPU_VECTOR<RedXInternalImageFormatsLimitsArray>                   adaptersImageFormatsLimitsImageDimensions2D;
    REDGPU_VECTOR<RedXInternalImageFormatsLimitsArray>                   adaptersImageFormatsLimitsImageDimensions2DMultisample;
    REDGPU_VECTOR<RedXInternalImageFormatsLimitsArray>                   adaptersImageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered;
    REDGPU_VECTOR<RedXInternalImageFormatsLimitsArray>                   adaptersImageFormatsLimitsImageDimensions3D;
    REDGPU_VECTOR<RedXInternalImageFormatsLimitsArray>                   adaptersImageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered;
    REDGPU_VECTOR<RedXInternalImageFormatsFeaturesArray>                 adaptersImageFormatsFeatures;
    REDGPU_VECTOR<RedXInternalImageXFormatsLimitsArray>                  adaptersImageXFormatsLimitsImageDimensions1D;
    REDGPU_VECTOR<RedXInternalImageXFormatsLimitsArray>                  adaptersImageXFormatsLimitsImageDimensions2D;
    REDGPU_VECTOR<RedXInternalImageXFormatsLimitsArray>                  adaptersImageXFormatsLimitsImageDimensions2DMultisample;
    REDGPU_VECTOR<RedXInternalImageXFormatsLimitsArray>                  adaptersImageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered;
    REDGPU_VECTOR<RedXInternalImageXFormatsLimitsArray>                  adaptersImageXFormatsLimitsImageDimensions3D;
    REDGPU_VECTOR<RedXInternalImageXFormatsLimitsArray>                  adaptersImageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered;
    REDGPU_VECTOR<RedXInternalImageXFormatsFeaturesArray>                adaptersImageXFormatsFeatures;
    REDGPU_VECTOR<RedGpuInfoOptionalInfoImageXFormatsLimitsAndFeatures>  adaptersOptionalInfoImageXFormatsLimitsAndFeatures;
    REDGPU_VECTOR<unsigned>                                              adaptersDescriptorHandleIncrementSizesCBVSRVUAV;
    REDGPU_VECTOR<unsigned>                                              adaptersDescriptorHandleIncrementSizesSampler;
    REDGPU_VECTOR<RedGpuInfoOptionalInfoArrayTimestamp>                  adaptersGpuInfoOptionalInfoArrayTimestamp;
    REDGPU_VECTOR<RedGpuInfoOptionalInfoComputingLanguageFeatureLevel1>  adaptersGpuInfoOptionalInfoComputingLanguageFeatureLevel1;
    REDGPU_VECTOR<RedGpuInfoOptionalInfoRayTracing>                      adaptersGpuInfoOptionalInfoRayTracing;
    REDGPU_VECTOR<RedGpuInfoOptionalInfoDriverProperties>                adaptersGpuInfoOptionalInfoDriverProperties;
    REDGPU_VECTOR<RedGpuInfoOptionalInfoResolveDepthStencil>             adaptersGpuInfoOptionalInfoResolveDepthStencil;
    REDGPU_VECTOR<RedGpuInfoOptionalInfoProcedureParametersHandles>      adaptersGpuInfoOptionalInfoProcedureParametersHandles;
    REDGPU_VECTOR<RedGpuInfoOptionalInfoRasterizationMode>               adaptersGpuInfoOptionalInfoRasterizationMode;
    REDGPU_VECTOR<RedGpuInfoOptionalInfoFormalMemoryModel>               adaptersGpuInfoOptionalInfoFormalMemoryModel;
    REDGPU_VECTOR<RedGpuInfoOptionalInfoAdditionalInfo0>                 adaptersGpuInfoOptionalInfoAdditionalInfo0;
  }                                                                      internal;
} RedXInternalTypeContext;

static void redInternalSetStatus(RedXInternalTypeContext * context, RedHandleGpu gpu, RedStatuses * outStatuses, unsigned statusIndex, RedStatus status, RedProcedureId procedureId, const char * optionalFile, int optionalLine, HRESULT hresult, const char * errorMessage) {
  if (status == RED_STATUS_SUCCESS) {
    return;
  }

  if (status < 0) {
    if (context != 0) {
      if (context->internal.debugCallback != 0) {
        RedHandleInfo info;
        info._0         = 1000128000;
        info._1         = 0;
        info.handleType = RED_HANDLE_TYPE_GPU;
        info.handle     = (void *)gpu;
        info.handleName = "";
        RedDebugCallbackData data;
        data._0               = 1000128003;
        data._1               = 0;
        data.statusCode       = statusIndex;
        data.messageIdName    = "";
        data.statusHresult    = hresult;
        data.message          = errorMessage;
        data._2               = 0;
        data._3               = 0;
        data._4               = 0;
        data._5               = 0;
        data.handleInfosCount = gpu == 0 ? 0    : 1;
        data.handleInfos      = gpu == 0 ? 0 : &info;
        context->internal.debugCallback(RED_DEBUG_CALLBACK_SEVERITY_ERROR, RED_DEBUG_CALLBACK_TYPE_BITFLAG_GENERAL, &data, (RedContext)context);
      }
    }
  }

  if (outStatuses == 0) {
    return;
  }

  if (status > 0) {
    if (outStatuses->status == RED_STATUS_SUCCESS) {
      outStatuses->status            = (RedStatus)status;
      outStatuses->statusCode        = statusIndex;
      outStatuses->statusHresult     = hresult;
      outStatuses->statusProcedureId = procedureId;
      outStatuses->statusFile        = optionalFile;
      outStatuses->statusLine        = optionalLine;
    }
  } else {
    if (outStatuses->statusError == RED_STATUS_SUCCESS) {
      outStatuses->statusError            = (RedStatus)status;
      outStatuses->statusErrorCode        = statusIndex;
      outStatuses->statusErrorHresult     = hresult;
      outStatuses->statusErrorProcedureId = procedureId;
      outStatuses->statusErrorFile        = optionalFile;
      outStatuses->statusErrorLine        = optionalLine;
      for (int i = 0; i < 512; i += 1) {
        outStatuses->statusErrorDescription[i] = 0;
      }
      if (errorMessage != 0) {
        for (int i = 0; i < 512; i += 1) {
          char c = errorMessage[i];
          outStatuses->statusErrorDescription[i] = c;
          if (c == 0) {
            break;
          }
        }
      }
    }
  }
}

// Internal utils

static unsigned redInternalGetGpuIndex(RedContext context, RedHandleGpu gpu) {
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  unsigned gpuIndex = (unsigned)-1;
  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpus[i].gpu == gpu) {
      gpuIndex = i;
      break;
    }
  }
  return gpuIndex;
}

static RedBool32 redInternalFormatIndexIsValid(unsigned format) {
  if      (format == RED_FORMAT_R_8_UINT_TO_FLOAT_0_1)                          { return 1; }
  else if (format == RED_FORMAT_R_8_UINT)                                       { return 1; }
  else if (format == RED_FORMAT_R_8_SINT)                                       { return 1; }
  else if (format == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1)                 { return 1; }
  else if (format == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED) { return 1; }
  else if (format == RED_FORMAT_RGBA_8_8_8_8_UINT)                              { return 1; }
  else if (format == RED_FORMAT_RGBA_8_8_8_8_SINT)                              { return 1; }
  else if (format == RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1)         { return 1; }
  else if (format == RED_FORMAT_R_16_UINT)                                      { return 1; }
  else if (format == RED_FORMAT_R_16_SINT)                                      { return 1; }
  else if (format == RED_FORMAT_R_16_FLOAT)                                     { return 1; }
  else if (format == RED_FORMAT_RGBA_16_16_16_16_UINT)                          { return 1; }
  else if (format == RED_FORMAT_RGBA_16_16_16_16_SINT)                          { return 1; }
  else if (format == RED_FORMAT_RGBA_16_16_16_16_FLOAT)                         { return 1; }
  else if (format == RED_FORMAT_R_32_UINT)                                      { return 1; }
  else if (format == RED_FORMAT_R_32_SINT)                                      { return 1; }
  else if (format == RED_FORMAT_R_32_FLOAT)                                     { return 1; }
  else if (format == RED_FORMAT_RGBA_32_32_32_32_UINT)                          { return 1; }
  else if (format == RED_FORMAT_RGBA_32_32_32_32_SINT)                          { return 1; }
  else if (format == RED_FORMAT_RGBA_32_32_32_32_FLOAT)                         { return 1; }
  else if (format == RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1)                     { return 1; }
  else if (format == RED_FORMAT_DEPTH_32_FLOAT)                                 { return 1; }
  else if (format == RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT)      { return 1; }
  else if (format == RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT)                  { return 1; }
  return 0;
}

static DXGI_FORMAT redInternalREDGPUFormatToD3D12Format(unsigned format) {
  if      (format == RED_FORMAT_UNDEFINED)                                      { return DXGI_FORMAT_UNKNOWN;                  }
  else if (format == RED_FORMAT_R_8_UINT_TO_FLOAT_0_1)                          { return DXGI_FORMAT_R8_UNORM;                 }
  else if (format == RED_FORMAT_R_8_UINT)                                       { return DXGI_FORMAT_R8_UINT;                  }
  else if (format == RED_FORMAT_R_8_SINT)                                       { return DXGI_FORMAT_R8_SINT;                  }
  else if (format == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1)                 { return DXGI_FORMAT_R8G8B8A8_UNORM;           }
  else if (format == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED) { return DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;      }
  else if (format == RED_FORMAT_RGBA_8_8_8_8_UINT)                              { return DXGI_FORMAT_R8G8B8A8_UINT;            }
  else if (format == RED_FORMAT_RGBA_8_8_8_8_SINT)                              { return DXGI_FORMAT_R8G8B8A8_SINT;            }
  else if (format == RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1)         { return DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;      }
  else if (format == RED_FORMAT_R_16_UINT)                                      { return DXGI_FORMAT_R16_UINT;                 }
  else if (format == RED_FORMAT_R_16_SINT)                                      { return DXGI_FORMAT_R16_SINT;                 }
  else if (format == RED_FORMAT_R_16_FLOAT)                                     { return DXGI_FORMAT_R16_FLOAT;                }
  else if (format == RED_FORMAT_RGBA_16_16_16_16_UINT)                          { return DXGI_FORMAT_R16G16B16A16_UINT;        }
  else if (format == RED_FORMAT_RGBA_16_16_16_16_SINT)                          { return DXGI_FORMAT_R16G16B16A16_SINT;        }
  else if (format == RED_FORMAT_RGBA_16_16_16_16_FLOAT)                         { return DXGI_FORMAT_R16G16B16A16_FLOAT;       }
  else if (format == RED_FORMAT_R_32_UINT)                                      { return DXGI_FORMAT_R32_UINT;                 }
  else if (format == RED_FORMAT_R_32_SINT)                                      { return DXGI_FORMAT_R32_SINT;                 }
  else if (format == RED_FORMAT_R_32_FLOAT)                                     { return DXGI_FORMAT_R32_FLOAT;                }
  else if (format == RED_FORMAT_RGBA_32_32_32_32_UINT)                          { return DXGI_FORMAT_R32G32B32A32_UINT;        }
  else if (format == RED_FORMAT_RGBA_32_32_32_32_SINT)                          { return DXGI_FORMAT_R32G32B32A32_SINT;        }
  else if (format == RED_FORMAT_RGBA_32_32_32_32_FLOAT)                         { return DXGI_FORMAT_R32G32B32A32_FLOAT;       }
  else if (format == RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1)                     { return DXGI_FORMAT_D16_UNORM;                }
  else if (format == RED_FORMAT_DEPTH_32_FLOAT)                                 { return DXGI_FORMAT_D32_FLOAT;                }
  else if (format == RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT)      { return DXGI_FORMAT_D24_UNORM_S8_UINT;        }
  else if (format == RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT)                  { return DXGI_FORMAT_D32_FLOAT_S8X24_UINT;     }
  else if (format == REDX_FORMAT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1)                { return DXGI_FORMAT_B8G8R8A8_UNORM;           }
  else if (format == REDX_FORMAT_R_16_UINT_TO_FLOAT_0_1)                        { return DXGI_FORMAT_R16_UNORM;                }
  else if (format == REDX_FORMAT_R_8_GENERIC)                                   { return DXGI_FORMAT_R8_TYPELESS;              }
  else if (format == REDX_FORMAT_R_16_GENERIC)                                  { return DXGI_FORMAT_R16_TYPELESS;             }
  else if (format == REDX_FORMAT_R_32_GENERIC)                                  { return DXGI_FORMAT_R32_TYPELESS;             }
  else if (format == REDX_FORMAT_RGBA_8_8_8_8_GENERIC)                          { return DXGI_FORMAT_R8G8B8A8_TYPELESS;        }
  else if (format == REDX_FORMAT_RGBA_16_16_16_16_GENERIC)                      { return DXGI_FORMAT_R16G16B16A16_TYPELESS;    }
  else if (format == REDX_FORMAT_RGBA_32_32_32_32_GENERIC)                      { return DXGI_FORMAT_R32G32B32A32_TYPELESS;    }
  else if (format == REDX_FORMAT_RG_24_8_GENERIC)                               { return DXGI_FORMAT_R24G8_TYPELESS;           }
  else if (format == REDX_FORMAT_RX_24_8_UINT_TO_FLOAT_0_1)                     { return DXGI_FORMAT_R24_UNORM_X8_TYPELESS;    }
  else if (format == REDX_FORMAT_XG_24_8_UINT)                                  { return DXGI_FORMAT_X24_TYPELESS_G8_UINT;     }
  else if (format == REDX_FORMAT_R_32_GX_8_24_GENERIC)                          { return DXGI_FORMAT_R32G8X24_TYPELESS;        }
  else if (format == REDX_FORMAT_R_32_XX_8_24_FLOAT)                            { return DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS; }
  else if (format == REDX_FORMAT_X_32_GX_8_24_UINT)                             { return DXGI_FORMAT_X32_TYPELESS_G8X24_UINT;  }
  return (DXGI_FORMAT)-1;
}

static unsigned redInternalREDGPUFormatIndexToD3D12FormatIndex(unsigned index) {
  if      (index == RED_FORMAT_UNDEFINED)                                      { return (unsigned)DXGI_FORMAT_UNKNOWN;              }
  else if (index == RED_FORMAT_R_8_UINT_TO_FLOAT_0_1)                          { return (unsigned)DXGI_FORMAT_R8_UNORM;             }
  else if (index == RED_FORMAT_R_8_UINT)                                       { return (unsigned)DXGI_FORMAT_R8_UINT;              }
  else if (index == RED_FORMAT_R_8_SINT)                                       { return (unsigned)DXGI_FORMAT_R8_SINT;              }
  else if (index == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1)                 { return (unsigned)DXGI_FORMAT_R8G8B8A8_UNORM;       }
  else if (index == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED) { return (unsigned)DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;  }
  else if (index == RED_FORMAT_RGBA_8_8_8_8_UINT)                              { return (unsigned)DXGI_FORMAT_R8G8B8A8_UINT;        }
  else if (index == RED_FORMAT_RGBA_8_8_8_8_SINT)                              { return (unsigned)DXGI_FORMAT_R8G8B8A8_SINT;        }
  else if (index == RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1)         { return (unsigned)DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;  }
  else if (index == RED_FORMAT_R_16_UINT)                                      { return (unsigned)DXGI_FORMAT_R16_UINT;             }
  else if (index == RED_FORMAT_R_16_SINT)                                      { return (unsigned)DXGI_FORMAT_R16_SINT;             }
  else if (index == RED_FORMAT_R_16_FLOAT)                                     { return (unsigned)DXGI_FORMAT_R16_FLOAT;            }
  else if (index == RED_FORMAT_RGBA_16_16_16_16_UINT)                          { return (unsigned)DXGI_FORMAT_R16G16B16A16_UINT;    }
  else if (index == RED_FORMAT_RGBA_16_16_16_16_SINT)                          { return (unsigned)DXGI_FORMAT_R16G16B16A16_SINT;    }
  else if (index == RED_FORMAT_RGBA_16_16_16_16_FLOAT)                         { return (unsigned)DXGI_FORMAT_R16G16B16A16_FLOAT;   }
  else if (index == RED_FORMAT_R_32_UINT)                                      { return (unsigned)DXGI_FORMAT_R32_UINT;             }
  else if (index == RED_FORMAT_R_32_SINT)                                      { return (unsigned)DXGI_FORMAT_R32_SINT;             }
  else if (index == RED_FORMAT_R_32_FLOAT)                                     { return (unsigned)DXGI_FORMAT_R32_FLOAT;            }
  else if (index == RED_FORMAT_RGBA_32_32_32_32_UINT)                          { return (unsigned)DXGI_FORMAT_R32G32B32A32_UINT;    }
  else if (index == RED_FORMAT_RGBA_32_32_32_32_SINT)                          { return (unsigned)DXGI_FORMAT_R32G32B32A32_SINT;    }
  else if (index == RED_FORMAT_RGBA_32_32_32_32_FLOAT)                         { return (unsigned)DXGI_FORMAT_R32G32B32A32_FLOAT;   }
  else if (index == RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1)                     { return (unsigned)DXGI_FORMAT_D16_UNORM;            }
  else if (index == RED_FORMAT_DEPTH_32_FLOAT)                                 { return (unsigned)DXGI_FORMAT_D32_FLOAT;            }
  else if (index == RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT)      { return (unsigned)DXGI_FORMAT_D24_UNORM_S8_UINT;    }
  else if (index == RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT)                  { return (unsigned)DXGI_FORMAT_D32_FLOAT_S8X24_UINT; }
  return (unsigned)-1;
}

static unsigned redInternalREDGPUXFormatIndexToD3D12FormatIndex(unsigned index) {
  if      (index == REDX_FORMAT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1)                { return (unsigned)DXGI_FORMAT_B8G8R8A8_UNORM;           }
  else if (index == REDX_FORMAT_R_16_UINT_TO_FLOAT_0_1)                        { return (unsigned)DXGI_FORMAT_R16_UNORM;                }
  else if (index == REDX_FORMAT_R_8_GENERIC)                                   { return (unsigned)DXGI_FORMAT_R8_TYPELESS;              }
  else if (index == REDX_FORMAT_R_16_GENERIC)                                  { return (unsigned)DXGI_FORMAT_R16_TYPELESS;             }
  else if (index == REDX_FORMAT_R_32_GENERIC)                                  { return (unsigned)DXGI_FORMAT_R32_TYPELESS;             }
  else if (index == REDX_FORMAT_RGBA_8_8_8_8_GENERIC)                          { return (unsigned)DXGI_FORMAT_R8G8B8A8_TYPELESS;        }
  else if (index == REDX_FORMAT_RGBA_16_16_16_16_GENERIC)                      { return (unsigned)DXGI_FORMAT_R16G16B16A16_TYPELESS;    }
  else if (index == REDX_FORMAT_RGBA_32_32_32_32_GENERIC)                      { return (unsigned)DXGI_FORMAT_R32G32B32A32_TYPELESS;    }
  else if (index == REDX_FORMAT_RG_24_8_GENERIC)                               { return (unsigned)DXGI_FORMAT_R24G8_TYPELESS;           }
  else if (index == REDX_FORMAT_RX_24_8_UINT_TO_FLOAT_0_1)                     { return (unsigned)DXGI_FORMAT_R24_UNORM_X8_TYPELESS;    }
  else if (index == REDX_FORMAT_XG_24_8_UINT)                                  { return (unsigned)DXGI_FORMAT_X24_TYPELESS_G8_UINT;     }
  else if (index == REDX_FORMAT_R_32_GX_8_24_GENERIC)                          { return (unsigned)DXGI_FORMAT_R32G8X24_TYPELESS;        }
  else if (index == REDX_FORMAT_R_32_XX_8_24_FLOAT)                            { return (unsigned)DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS; }
  else if (index == REDX_FORMAT_X_32_GX_8_24_UINT)                             { return (unsigned)DXGI_FORMAT_X32_TYPELESS_G8X24_UINT;  }
  return (unsigned)-1;
}

static D3D12_RESOURCE_DIMENSION redInternalREDGPUImageDimensionsToD3D12ResourceDimension(RedImageDimensions dimensions) {
  if (dimensions == RED_IMAGE_DIMENSIONS_1D) {
    return D3D12_RESOURCE_DIMENSION_TEXTURE1D;
  } else if (dimensions == RED_IMAGE_DIMENSIONS_2D || dimensions == RED_IMAGE_DIMENSIONS_2D_WITH_TEXTURE_DIMENSIONS_CUBE_AND_CUBE_LAYERED) {
    return D3D12_RESOURCE_DIMENSION_TEXTURE2D;
  } else if (dimensions == RED_IMAGE_DIMENSIONS_3D || dimensions == RED_IMAGE_DIMENSIONS_3D_WITH_TEXTURE_DIMENSIONS_2D_AND_2D_LAYERED) {
    return D3D12_RESOURCE_DIMENSION_TEXTURE3D;
  }
  return (D3D12_RESOURCE_DIMENSION)-1;
}

static unsigned redInternalREDGPUMultisampleCountToUnsignedValue(RedMultisampleCountBitflag multisampleCount) {
  if (multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_1) {
    return 1;
  } else if (multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_2) {
    return 2;
  } else if (multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_4) {
    return 4;
  } else if (multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_8) {
    return 8;
  } else if (multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_16) {
    return 16;
  }
  return (unsigned)-1;
}

static D3D12_BLEND redInternalREDGPUBlendFactorToD3D12Blend(RedBlendFactor blendFactor) {
  if (blendFactor == RED_BLEND_FACTOR_ZERO) {
    return D3D12_BLEND_ZERO;
  } else if (blendFactor == RED_BLEND_FACTOR_ONE) {
    return D3D12_BLEND_ONE;
  } else if (blendFactor == RED_BLEND_FACTOR_SOURCE_COLOR) {
    return D3D12_BLEND_SRC_COLOR;
  } else if (blendFactor == RED_BLEND_FACTOR_ONE_MINUS_SOURCE_COLOR) {
    return D3D12_BLEND_INV_SRC_COLOR;
  } else if (blendFactor == RED_BLEND_FACTOR_TARGET_COLOR) {
    return D3D12_BLEND_DEST_COLOR;
  } else if (blendFactor == RED_BLEND_FACTOR_ONE_MINUS_TARGET_COLOR) {
    return D3D12_BLEND_INV_DEST_COLOR;
  } else if (blendFactor == RED_BLEND_FACTOR_SOURCE_ALPHA) {
    return D3D12_BLEND_SRC_ALPHA;
  } else if (blendFactor == RED_BLEND_FACTOR_ONE_MINUS_SOURCE_ALPHA) {
    return D3D12_BLEND_INV_SRC_ALPHA;
  } else if (blendFactor == RED_BLEND_FACTOR_TARGET_ALPHA) {
    return D3D12_BLEND_DEST_ALPHA;
  } else if (blendFactor == RED_BLEND_FACTOR_ONE_MINUS_TARGET_ALPHA) {
    return D3D12_BLEND_INV_DEST_ALPHA;
  } else if (blendFactor == RED_BLEND_FACTOR_CONSTANT_COLOR) {
    return D3D12_BLEND_BLEND_FACTOR;
  } else if (blendFactor == RED_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR) {
    return D3D12_BLEND_INV_BLEND_FACTOR;
  } else if (blendFactor == RED_BLEND_FACTOR_SOURCE_ALPHA_SATURATE) {
    return D3D12_BLEND_SRC_ALPHA_SAT;
  } else if (blendFactor == RED_BLEND_FACTOR_SOURCE1_COLOR) {
    return D3D12_BLEND_SRC1_COLOR;
  } else if (blendFactor == RED_BLEND_FACTOR_ONE_MINUS_SOURCE1_COLOR) {
    return D3D12_BLEND_INV_SRC1_COLOR;
  } else if (blendFactor == RED_BLEND_FACTOR_SOURCE1_ALPHA) {
    return D3D12_BLEND_SRC1_ALPHA;
  } else if (blendFactor == RED_BLEND_FACTOR_ONE_MINUS_SOURCE1_ALPHA) {
    return D3D12_BLEND_INV_SRC1_ALPHA;
  }
  return (D3D12_BLEND)-1;
}

static D3D12_BLEND_OP redInternalREDGPUBlendOpToD3D12BlendOp(RedBlendOp blendOp) {
  if (blendOp == RED_BLEND_OP_ADD) {
    return D3D12_BLEND_OP_ADD;
  } else if (blendOp == RED_BLEND_OP_SUBTRACT) {
    return D3D12_BLEND_OP_SUBTRACT;
  } else if (blendOp == RED_BLEND_OP_REVERSE_SUBTRACT) {
    return D3D12_BLEND_OP_REV_SUBTRACT;
  } else if (blendOp == RED_BLEND_OP_MIN) {
    return D3D12_BLEND_OP_MIN;
  } else if (blendOp == RED_BLEND_OP_MAX) {
    return D3D12_BLEND_OP_MAX;
  }
  return (D3D12_BLEND_OP)-1;
}

static D3D12_LOGIC_OP redInternalREDGPULogicOpToD3D12LogicOp(RedLogicOp logicOp) {
  if (logicOp == RED_LOGIC_OP_CLEAR) {
    return D3D12_LOGIC_OP_CLEAR;
  } else if (logicOp == RED_LOGIC_OP_AND) {
    return D3D12_LOGIC_OP_AND;
  } else if (logicOp == RED_LOGIC_OP_AND_REVERSE) {
    return D3D12_LOGIC_OP_AND_REVERSE;
  } else if (logicOp == RED_LOGIC_OP_COPY) {
    return D3D12_LOGIC_OP_COPY;
  } else if (logicOp == RED_LOGIC_OP_AND_INVERTED) {
    return D3D12_LOGIC_OP_AND_INVERTED;
  } else if (logicOp == RED_LOGIC_OP_NO_OP) {
    return D3D12_LOGIC_OP_NOOP;
  } else if (logicOp == RED_LOGIC_OP_XOR) {
    return D3D12_LOGIC_OP_XOR;
  } else if (logicOp == RED_LOGIC_OP_OR) {
    return D3D12_LOGIC_OP_OR;
  } else if (logicOp == RED_LOGIC_OP_NOR) {
    return D3D12_LOGIC_OP_NOR;
  } else if (logicOp == RED_LOGIC_OP_EQUIVALENT) {
    return D3D12_LOGIC_OP_EQUIV;
  } else if (logicOp == RED_LOGIC_OP_INVERT) {
    return D3D12_LOGIC_OP_INVERT;
  } else if (logicOp == RED_LOGIC_OP_OR_REVERSE) {
    return D3D12_LOGIC_OP_OR_REVERSE;
  } else if (logicOp == RED_LOGIC_OP_COPY_INVERTED) {
    return D3D12_LOGIC_OP_COPY_INVERTED;
  } else if (logicOp == RED_LOGIC_OP_OR_INVERTED) {
    return D3D12_LOGIC_OP_OR_INVERTED;
  } else if (logicOp == RED_LOGIC_OP_NAND) {
    return D3D12_LOGIC_OP_NAND;
  } else if (logicOp == RED_LOGIC_OP_SET) {
    return D3D12_LOGIC_OP_SET;
  }
  return (D3D12_LOGIC_OP)-1;
}

static D3D12_CULL_MODE redInternalREDGPUCullModeToD3D12CullMode(RedCullMode cullMode) {
  if (cullMode == RED_CULL_MODE_NONE) {
    return D3D12_CULL_MODE_NONE;
  } else if (cullMode == RED_CULL_MODE_FRONT) {
    return D3D12_CULL_MODE_FRONT;
  } else if (cullMode == RED_CULL_MODE_BACK) {
    return D3D12_CULL_MODE_BACK;
  }
  return (D3D12_CULL_MODE)-1;
}

static D3D12_STENCIL_OP redInternalREDGPUStencilOpToD3D12StencilOp(RedStencilOp stencilOp) {
  if (stencilOp == RED_STENCIL_OP_KEEP) {
    return D3D12_STENCIL_OP_KEEP;
  } else if (stencilOp == RED_STENCIL_OP_ZERO) {
    return D3D12_STENCIL_OP_ZERO;
  } else if (stencilOp == RED_STENCIL_OP_REPLACE) {
    return D3D12_STENCIL_OP_REPLACE;
  } else if (stencilOp == RED_STENCIL_OP_INCREMENT_AND_CLAMP) {
    return D3D12_STENCIL_OP_INCR_SAT;
  } else if (stencilOp == RED_STENCIL_OP_DECREMENT_AND_CLAMP) {
    return D3D12_STENCIL_OP_DECR_SAT;
  } else if (stencilOp == RED_STENCIL_OP_INVERT) {
    return D3D12_STENCIL_OP_INVERT;
  } else if (stencilOp == RED_STENCIL_OP_INCREMENT_AND_WRAP) {
    return D3D12_STENCIL_OP_INCR;
  } else if (stencilOp == RED_STENCIL_OP_DECREMENT_AND_WRAP) {
    return D3D12_STENCIL_OP_DECR;
  }
  return (D3D12_STENCIL_OP)-1;
}

static D3D12_PRIMITIVE_TOPOLOGY_TYPE redInternalREDGPUPrimitiveTopologyToD3D12PrimitiveTopologyType(RedPrimitiveTopology primitiveTopology) {
  if (primitiveTopology == RED_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST) {
    return D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
  } else if (primitiveTopology == RED_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP) {
    return D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
  }
  return (D3D12_PRIMITIVE_TOPOLOGY_TYPE)-1;
}

static D3D12_COMPARISON_FUNC redInternalREDGPUCompareOpToD3D12ComparisonFunc(RedCompareOp op) {
  if (op == RED_COMPARE_OP_NEVER) {
    return D3D12_COMPARISON_FUNC_NEVER;
  } else if (op == RED_COMPARE_OP_LESS) {
    return D3D12_COMPARISON_FUNC_LESS;
  } else if (op == RED_COMPARE_OP_EQUAL) {
    return D3D12_COMPARISON_FUNC_EQUAL;
  } else if (op == RED_COMPARE_OP_LESS_OR_EQUAL) {
    return D3D12_COMPARISON_FUNC_LESS_EQUAL;
  } else if (op == RED_COMPARE_OP_GREATER) {
    return D3D12_COMPARISON_FUNC_GREATER;
  } else if (op == RED_COMPARE_OP_NOT_EQUAL) {
    return D3D12_COMPARISON_FUNC_NOT_EQUAL;
  } else if (op == RED_COMPARE_OP_GREATER_OR_EQUAL) {
    return D3D12_COMPARISON_FUNC_GREATER_EQUAL;
  } else if (op == RED_COMPARE_OP_ALWAYS) {
    return D3D12_COMPARISON_FUNC_ALWAYS;
  }
  return (D3D12_COMPARISON_FUNC)-1;
}

static D3D12_HEAP_TYPE redInternalREDGPUMemoryTypeIndexToD3D12HeapType(RedXInternalTypeContext * context, unsigned gpuIndex, unsigned memoryTypeIndex) {
  const unsigned memoryType0OnlyBuffers          = 0;
  const unsigned memoryType1OnlyTextures         = 1;
  const unsigned memoryType2OnlyRtDsTextures     = 2;
  const unsigned memoryType3OnlyRtDsTexturesMsaa = 3;
  const unsigned memoryType4Upload               = 4;
  const unsigned memoryType5Readback             = 5;

  if (memoryTypeIndex == memoryType0OnlyBuffers) {
    return D3D12_HEAP_TYPE_DEFAULT;
  } else if (memoryTypeIndex == memoryType1OnlyTextures) {
    return D3D12_HEAP_TYPE_DEFAULT;
  } else if (memoryTypeIndex == memoryType2OnlyRtDsTextures) {
    return D3D12_HEAP_TYPE_DEFAULT;
  } else if (memoryTypeIndex == memoryType3OnlyRtDsTexturesMsaa) {
    return D3D12_HEAP_TYPE_DEFAULT;
  } else if (memoryTypeIndex == memoryType4Upload) {
    return D3D12_HEAP_TYPE_UPLOAD;
  } else if (memoryTypeIndex == memoryType5Readback) {
    return D3D12_HEAP_TYPE_READBACK;
  }

  return (D3D12_HEAP_TYPE)(unsigned)-1;
}

static D3D12_CPU_PAGE_PROPERTY redInternalREDGPUMemoryTypeIndexToD3D12CpuPageProperty(RedXInternalTypeContext * context, unsigned gpuIndex, unsigned memoryTypeIndex) {
  return D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
}

static D3D12_MEMORY_POOL redInternalREDGPUMemoryTypeIndexToD3D12MemoryPool(RedXInternalTypeContext * context, unsigned gpuIndex, unsigned memoryTypeIndex) {
  return D3D12_MEMORY_POOL_UNKNOWN;
}

static D3D12_HEAP_FLAGS redInternalREDGPUMemoryTypeIndexToD3D12HeapFlags(RedXInternalTypeContext * context, unsigned gpuIndex, unsigned memoryTypeIndex) {
  const unsigned memoryType0OnlyBuffers          = 0;
  const unsigned memoryType1OnlyTextures         = 1;
  const unsigned memoryType2OnlyRtDsTextures     = 2;
  const unsigned memoryType3OnlyRtDsTexturesMsaa = 3;
  const unsigned memoryType4Upload               = 4;
  const unsigned memoryType5Readback             = 5;

  if (memoryTypeIndex == memoryType0OnlyBuffers) {
    return D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS;
  } else if (memoryTypeIndex == memoryType1OnlyTextures) {
    return D3D12_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES;
  } else if (memoryTypeIndex == memoryType2OnlyRtDsTextures) {
    return D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES;
  } else if (memoryTypeIndex == memoryType3OnlyRtDsTexturesMsaa) {
    return D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES;
  } else if (memoryTypeIndex == memoryType4Upload) {
    return D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS;
  } else if (memoryTypeIndex == memoryType5Readback) {
    return D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS;
  }

  return (D3D12_HEAP_FLAGS)-1;
}

static D3D12_RESOURCE_STATES redInternalREDGPUInitialD3D12ResourceStates(unsigned memoryTypeIndex) {
  const unsigned memoryType0OnlyBuffers          = 0;
  const unsigned memoryType1OnlyTextures         = 1;
  const unsigned memoryType2OnlyRtDsTextures     = 2;
  const unsigned memoryType3OnlyRtDsTexturesMsaa = 3;
  const unsigned memoryType4Upload               = 4;
  const unsigned memoryType5Readback             = 5;

  if (memoryTypeIndex == memoryType0OnlyBuffers) {
    return D3D12_RESOURCE_STATE_COMMON;
  } else if (memoryTypeIndex == memoryType1OnlyTextures) {
    return D3D12_RESOURCE_STATE_COMMON;
  } else if (memoryTypeIndex == memoryType2OnlyRtDsTextures) {
    return D3D12_RESOURCE_STATE_COMMON;
  } else if (memoryTypeIndex == memoryType3OnlyRtDsTexturesMsaa) {
    return D3D12_RESOURCE_STATE_COMMON;
  } else if (memoryTypeIndex == memoryType4Upload) {
    return D3D12_RESOURCE_STATE_GENERIC_READ;
  } else if (memoryTypeIndex == memoryType5Readback) {
    return D3D12_RESOURCE_STATE_COPY_DEST;
  }

  return (D3D12_RESOURCE_STATES)-1;
}

static D3D12_RESOURCE_STATES redInternalREDGPUAccessBitflagsToD3D12ResourceStates(RedAccessBitflags access) {
  D3D12_RESOURCE_STATES state = D3D12_RESOURCE_STATE_COMMON;
  if ((access & RED_ACCESS_BITFLAG_STRUCT_ARRAY_RO_CONSTANT_R)           == RED_ACCESS_BITFLAG_STRUCT_ARRAY_RO_CONSTANT_R)           { state |= D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER; }
  if ((access & RED_ACCESS_BITFLAG_INDEX_R)                              == RED_ACCESS_BITFLAG_INDEX_R)                              { state |= D3D12_RESOURCE_STATE_INDEX_BUFFER; }
  if ((access & RED_ACCESS_BITFLAG_OUTPUT_COLOR_W)                       == RED_ACCESS_BITFLAG_OUTPUT_COLOR_W)                       { state |= D3D12_RESOURCE_STATE_RENDER_TARGET; }
  if ((access & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W)                    == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W)                    { state |= D3D12_RESOURCE_STATE_UNORDERED_ACCESS; }
  if ((access & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW)                      == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW)                      { state |= D3D12_RESOURCE_STATE_DEPTH_WRITE; }
  if ((access & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW)                    == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW)                    { state |= D3D12_RESOURCE_STATE_DEPTH_WRITE; }
  if ((access & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R)                       == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R)                       { state |= D3D12_RESOURCE_STATE_DEPTH_READ; }
  if ((access & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R)                     == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R)                     { state |= D3D12_RESOURCE_STATE_DEPTH_READ; }
  if ((access & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) { state |= D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE; }
  if ((access & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R)     == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R)     { state |= D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE; }
  if ((access & RED_ACCESS_BITFLAG_COPY_W)                               == RED_ACCESS_BITFLAG_COPY_W)                               { state |= D3D12_RESOURCE_STATE_COPY_DEST; }
  if ((access & RED_ACCESS_BITFLAG_COPY_R)                               == RED_ACCESS_BITFLAG_COPY_R)                               { state |= D3D12_RESOURCE_STATE_COPY_SOURCE; }
  if ((access & RED_ACCESS_BITFLAG_RESOLVE_TARGET_W)                     == RED_ACCESS_BITFLAG_RESOLVE_TARGET_W)                     { state |= D3D12_RESOURCE_STATE_RESOLVE_DEST; }
  if ((access & RED_ACCESS_BITFLAG_RESOLVE_SOURCE_R)                     == RED_ACCESS_BITFLAG_RESOLVE_SOURCE_R)                     { state |= D3D12_RESOURCE_STATE_RESOLVE_SOURCE; }
  if ((access & RED_ACCESS_BITFLAG_CPU_RW)                               == RED_ACCESS_BITFLAG_CPU_RW)                               { state |= D3D12_RESOURCE_STATE_GENERIC_READ; }
  return state;
}

static void redInternalDestroyContext(RedContext context, RedBool32 reportLiveObjects, const char * optionalFile, int optionalLine) {
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;

  if (ctx == 0) {
    return;
  }

  if (1) {
    for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
      for (unsigned j = 0; j < ctx->gpus[i].queuesCount; j += 1) {
        if (ctx->gpus[i].queues[j] != 0) {
          RedXInternalTypeQueue * ih = (RedXInternalTypeQueue *)ctx->gpus[i].queues[j];
          ih->handle->Release();
          delete ih;
          ctx->gpus[i].queues[j] = 0;
        }
      }
    }
  }

  if (1) {
    for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
      if (ctx->gpus[i].gpu != 0) {
        ID3D12Device3 * h = (ID3D12Device3 *)ctx->gpus[i].gpu;
        h->Release();
        ctx->gpus[i].gpu = 0;
      }
    }
  }

  if (1) {
    for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
      if (ctx->gpus[i].gpuDevice != 0) {
        IDXGIAdapter3 * h = (IDXGIAdapter3 *)ctx->gpus[i].gpuDevice;
        h->Release();
        ctx->gpus[i].gpuDevice = 0;
      }
    }
  }

  if (1) {
    {
      if (ctx->contextHandle != 0) {
        IDXGIFactory4 * h = (IDXGIFactory4 *)ctx->contextHandle;
        h->Release();
        ctx->contextHandle = 0;
      }
    }
  }

  if (ctx->internal.debugCallback != 0 && reportLiveObjects == 1) {
    x12DebugReport(ctx->internal.debugContext, optionalFile, optionalLine);
  }

  delete[] ctx->gpusStatuses;
  delete[] ctx->gpus;
  delete ctx;
}

static RedXInternalTypeMemory * redInternalTypeMemoryAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, uint64_t bytesCount, unsigned memoryTypeIndex, RedBool32 mapMemory, RedHandleArray dedicateToArray, RedHandleImage dedicateToImage, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  RedXInternalTypeMemory * ih = new(std::nothrow) RedXInternalTypeMemory();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->handle                       = 0;
  ih->resource                     = 0;
  ih->context                      = (RedContext)context;
  ih->gpuIndex                     = gpuIndex;
  ih->bytesCount                   = bytesCount;
  ih->memoryTypeIndex              = memoryTypeIndex;
  ih->mapMemory                    = mapMemory;
  ih->dedicateToArray              = dedicateToArray;
  ih->dedicateToImage              = dedicateToImage;
  ih->mappedPointerRangeBytesFirst = 0;
  ih->mappedPointerRangeBytesCount = 0;
  ih->mappedPointer                = 0;
  ih->kind                         = REDX_INTERNAL_TYPE_MEMORY_KIND_UNDEFINED;
  ih->handleName                   = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroyMemory(RedHandleMemory memory, const char * optionalFile, int optionalLine) {
  RedXInternalTypeMemory * ih = (RedXInternalTypeMemory *)memory;

  if (ih == 0) {
    return;
  }

  if (ih->resource != 0) {
    ih->resource->Release();
  }
  if (ih->handle != 0) {
    ih->handle->Release();
  }

  delete ih;
}

static RedXInternalTypeStructsMemory * redInternalTypeStructsMemoryAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, unsigned maxStructsCount, unsigned maxStructsMembersOfTypeArrayROConstantCount, unsigned maxStructsMembersOfTypeArrayROOrArrayRWCount, unsigned maxStructsMembersOfTypeSamplerCount, unsigned maxStructsMembersOfTypeTextureROCount, unsigned maxStructsMembersOfTypeTextureRWCount, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  RedXInternalTypeStructsMemory * ih = new(std::nothrow) RedXInternalTypeStructsMemory();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->handle                                       = 0;
  ih->context                                      = (RedContext)context;
  ih->gpuIndex                                     = gpuIndex;
  ih->maxStructsCount                              = maxStructsCount;
  ih->maxStructsMembersOfTypeArrayROConstantCount  = maxStructsMembersOfTypeArrayROConstantCount;
  ih->maxStructsMembersOfTypeArrayROOrArrayRWCount = maxStructsMembersOfTypeArrayROOrArrayRWCount;
  ih->maxStructsMembersOfTypeSamplerCount          = maxStructsMembersOfTypeSamplerCount;
  ih->maxStructsMembersOfTypeTextureROCount        = maxStructsMembersOfTypeTextureROCount;
  ih->maxStructsMembersOfTypeTextureRWCount        = maxStructsMembersOfTypeTextureRWCount;
  ih->handleName                                   = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroyStructsMemory(RedHandleStructsMemory structsMemory, const char * optionalFile, int optionalLine) {
  RedXInternalTypeStructsMemory * ih = (RedXInternalTypeStructsMemory *)structsMemory;

  if (ih == 0) {
    return;
  }

  if (ih->handle != 0) {
    ih->handle->Release();
  }

  delete ih;
}

static RedXInternalTypeArray * redInternalTypeArrayAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, RedArrayType type, uint64_t bytesCount, uint64_t structuredBufferElementBytesCount, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  const RedMemoryArray                         _0 = {};
  const D3D12_RESOURCE_DESC                    _1 = {};
  const RedXInternalTypeCpuDescriptorCBVSRVUAV _2 = {};
  RedXInternalTypeArray * ih = new(std::nothrow) RedXInternalTypeArray();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->handle                  = 0;
  ih->context                 = (RedContext)context;
  ih->gpuIndex                = gpuIndex;
  ih->type                    = type;
  ih->bytesCount              = bytesCount;
  ih->structuredBufferElementBytesCount = structuredBufferElementBytesCount;
  ih->initialAccess           = initialAccess;
  ih->initialQueueFamilyIndex = initialQueueFamilyIndex;
  ih->dedicate                = dedicate;
  ih->memoryBytesAlignment    = 0;
  ih->memoryBytesCount        = 0;
  ih->memoryTypesSupported    = 0;
  ih->memoryKind              = REDX_INTERNAL_TYPE_MEMORY_KIND_UNDEFINED;
  ih->memoryTypeIndex         = 0;
  ih->memoryArray             = _0;
  ih->resourceDescription     = _1;
  ih->cpuDescriptor           = _2;
  ih->destroyHandle           = 1;
  ih->mappedMemoryBytesFirst  = 0;
  ih->handleName              = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroyArray(RedHandleArray array, const char * optionalFile, int optionalLine) {
  RedXInternalTypeArray * ih = (RedXInternalTypeArray *)array;

  if (ih == 0) {
    return;
  }

  if (ih->cpuDescriptor.cpuDescriptorHeapCBVSRVUAV != 0) {
    ih->cpuDescriptor.cpuDescriptorHeapCBVSRVUAV->Release();
  }

  if (ih->destroyHandle == 1 && ih->handle != 0) {
    ih->handle->Release();
  }

  delete ih;
}

static RedXInternalTypeImage * redInternalTypeImageAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, RedImageDimensions dimensions, RedFormat format, unsigned xformat, unsigned width, unsigned height, unsigned depth, unsigned levelsCount, unsigned layersCount, RedMultisampleCountBitflag multisampleCount, RedAccessBitflags restrictToAccess, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  const RedMemoryImage      _0 = {};
  const D3D12_RESOURCE_DESC _1 = {};
  RedXInternalTypeImage * ih = new(std::nothrow) RedXInternalTypeImage();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->handle                  = 0;
  ih->context                 = (RedContext)context;
  ih->gpuIndex                = gpuIndex;
  ih->dimensions              = dimensions;
  ih->format                  = format;
  ih->xformat                 = xformat;
  ih->width                   = width;
  ih->height                  = height;
  ih->depth                   = depth;
  ih->levelsCount             = levelsCount;
  ih->layersCount             = layersCount;
  ih->multisampleCount        = multisampleCount;
  ih->restrictToAccess        = restrictToAccess;
  ih->restrictToAccessFinal   = 0;
  ih->initialAccess           = initialAccess;
  ih->initialQueueFamilyIndex = initialQueueFamilyIndex;
  ih->dedicate                = dedicate;
  ih->memoryBytesAlignment    = 0;
  ih->memoryBytesCount        = 0;
  ih->memoryTypesSupported    = 0;
  ih->memoryKind              = REDX_INTERNAL_TYPE_MEMORY_KIND_UNDEFINED;
  ih->memoryImage             = _0;
  ih->resourceDescription     = _1;
  ih->ownedByPresent          = 0;
  ih->destroyHandle           = 1;
  ih->handleName              = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroyImage(RedHandleImage image, const char * optionalFile, int optionalLine) {
  RedXInternalTypeImage * ih = (RedXInternalTypeImage *)image;

  if (ih == 0) {
    return;
  }

  if (ih->destroyHandle == 1 && ih->handle != 0) {
    ih->handle->Release();
  }

  delete ih;
}

static RedXInternalTypeSampler * redInternalTypeSamplerAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, RedSamplerFiltering filteringMag, RedSamplerFiltering filteringMin, RedSamplerFilteringMip filteringMip, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateU, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateV, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateW, float mipLodBias, RedBool32 enableAnisotropy, float maxAnisotropy, RedBool32 enableCompare, RedCompareOp compareOp, float minLod, float maxLod, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  const D3D12_SAMPLER_DESC                   _0 = {};
  const RedXInternalTypeCpuDescriptorSampler _1 = {};
  RedXInternalTypeSampler * ih = new(std::nothrow) RedXInternalTypeSampler();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->context                           = (RedContext)context;
  ih->gpuIndex                          = gpuIndex;
  ih->filteringMag                      = filteringMag;
  ih->filteringMin                      = filteringMin;
  ih->filteringMip                      = filteringMip;
  ih->behaviorOutsideTextureCoordinateU = behaviorOutsideTextureCoordinateU;
  ih->behaviorOutsideTextureCoordinateV = behaviorOutsideTextureCoordinateV;
  ih->behaviorOutsideTextureCoordinateW = behaviorOutsideTextureCoordinateW;
  ih->mipLodBias                        = mipLodBias;
  ih->enableAnisotropy                  = enableAnisotropy;
  ih->maxAnisotropy                     = maxAnisotropy;
  ih->enableCompare                     = enableCompare;
  ih->compareOp                         = compareOp;
  ih->minLod                            = minLod;
  ih->maxLod                            = maxLod;
  ih->samplerDescription                = _0;
  ih->cpuDescriptor                     = _1;
  ih->handleName                        = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroySampler(RedHandleSampler sampler, const char * optionalFile, int optionalLine) {
  RedXInternalTypeSampler * ih = (RedXInternalTypeSampler *)sampler;

  if (ih == 0) {
    return;
  }

  if (ih->cpuDescriptor.cpuDescriptorHeapSampler != 0) {
    ih->cpuDescriptor.cpuDescriptorHeapSampler->Release();
  }

  delete ih;
}

static RedXInternalTypeTexture * redInternalTypeTextureAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, RedHandleImage image, RedImagePartBitflags parts, RedTextureDimensions dimensions, RedFormat format, unsigned xformat, unsigned levelsFirst, unsigned levelsCount, unsigned layersFirst, unsigned layersCount, RedAccessBitflags restrictToAccess, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  const RedXInternalTypeCpuDescriptorCBVSRVUAV _0 = {};
  const RedXInternalTypeCpuDescriptorCBVSRVUAV _1 = {};
  const RedXInternalTypeCpuDescriptorDSV       _2 = {};
  const RedXInternalTypeCpuDescriptorRTV       _3 = {};
  RedXInternalTypeTexture * ih = new(std::nothrow) RedXInternalTypeTexture();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->context          = (RedContext)context;
  ih->gpuIndex         = gpuIndex;
  ih->image            = (RedXInternalTypeImage *)image;
  ih->parts            = parts;
  ih->dimensions       = dimensions;
  ih->format           = format;
  ih->xformat          = xformat;
  ih->levelsFirst      = levelsFirst;
  ih->levelsCount      = levelsCount;
  ih->layersFirst      = layersFirst;
  ih->layersCount      = layersCount;
  ih->restrictToAccess = restrictToAccess;
  ih->cpuDescriptorSRV = _0;
  ih->cpuDescriptorUAV = _1;
  ih->cpuDescriptorDSV = _2;
  ih->cpuDescriptorRTV = _3;
  ih->handleName       = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroyTexture(RedHandleTexture texture, const char * optionalFile, int optionalLine) {
  RedXInternalTypeTexture * ih = (RedXInternalTypeTexture *)texture;

  if (ih == 0) {
    return;
  }

  if (ih->cpuDescriptorRTV.cpuDescriptorHeapRTV != 0) {
    ih->cpuDescriptorRTV.cpuDescriptorHeapRTV->Release();
  }
  if (ih->cpuDescriptorDSV.cpuDescriptorHeapDSV != 0) {
    ih->cpuDescriptorDSV.cpuDescriptorHeapDSV->Release();
  }
  if (ih->cpuDescriptorUAV.cpuDescriptorHeapCBVSRVUAV != 0) {
    ih->cpuDescriptorUAV.cpuDescriptorHeapCBVSRVUAV->Release();
  }
  if (ih->cpuDescriptorSRV.cpuDescriptorHeapCBVSRVUAV != 0) {
    ih->cpuDescriptorSRV.cpuDescriptorHeapCBVSRVUAV->Release();
  }

  delete ih;
}

static void redInternalDestroyGpuCode(RedHandleGpuCode gpuCode, const char * optionalFile, int optionalLine) {
  unsigned char * ih = (unsigned char *)gpuCode;

  if (ih == 0) {
    return;
  }

  delete[] ih;
}

static void redInternalDestroyOutputDeclaration(RedHandleOutputDeclaration outputDeclaration, const char * optionalFile, int optionalLine) {
  unsigned * ih = (unsigned *)outputDeclaration;

  if (ih == 0) {
    return;
  }

  delete[] ih;
}

static RedXInternalTypeStructDeclaration * redInternalTypeStructDeclarationAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, unsigned structDeclarationMembersCount, const RedStructDeclarationMember * structDeclarationMembers, RedBool32 procedureParametersHandlesDeclaration, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  RedXInternalTypeStructDeclaration * ih = new(std::nothrow) RedXInternalTypeStructDeclaration();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->context                               = (RedContext)context;
  ih->gpuIndex                              = gpuIndex;
  try {
    ih->structDeclarationMembers.resize(structDeclarationMembersCount);
  } catch (...) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
  }
  for (unsigned i = 0; i < structDeclarationMembersCount; i += 1) {
    ih->structDeclarationMembers[i]         = structDeclarationMembers[i];
  }
  ih->procedureParametersHandlesDeclaration = procedureParametersHandlesDeclaration;
  ih->handleName                            = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroyStructDeclaration(RedHandleStructDeclaration structDeclaration, const char * optionalFile, int optionalLine) {
  RedXInternalTypeStructDeclaration * ih = (RedXInternalTypeStructDeclaration *)structDeclaration;

  if (ih == 0) {
    return;
  }

  delete ih;
}

static RedXInternalTypeProcedureParameters * redInternalTypeProcedureParametersAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, const RedProcedureParametersDeclaration * procedureParametersDeclaration, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  RedXInternalTypeProcedureParameters * ih = new(std::nothrow) RedXInternalTypeProcedureParameters();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->handle                           = 0;
  ih->context                          = (RedContext)context;
  ih->gpuIndex                         = gpuIndex;
  if (procedureParametersDeclaration != 0) {
    ih->procedureParametersDeclaration = procedureParametersDeclaration[0];
  }
  ih->blob                             = 0;
  ih->blobError                        = 0;
  ih->rootParameterIndexStartVariables = 0;
  ih->rootParameterIndexStartHandles   = 0;
  ih->rootParameterIndexStartStructs   = 0;
  ih->handleName                       = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroyProcedureParameters(RedHandleProcedureParameters procedureParameters, const char * optionalFile, int optionalLine) {
  RedXInternalTypeProcedureParameters * ih = (RedXInternalTypeProcedureParameters *)procedureParameters;

  if (ih == 0) {
    return;
  }

  if (ih->handle != 0) {
    ih->handle->Release();
  }

  delete ih;
}

static RedXInternalTypeProcedure * redInternalTypeProcedureAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, RedHandleProcedureCache procedureCache, RedHandleOutputDeclaration outputDeclaration, RedHandleProcedureParameters procedureParameters, const char * gpuCodeVertexMainProcedureName, RedHandleGpuCode gpuCodeVertex, const char * gpuCodeFragmentMainProcedureName, RedHandleGpuCode gpuCodeFragment, const char * gpuCodeComputeMainProcedureName, RedHandleGpuCode gpuCodeCompute, const RedProcedureState * state, const void * stateExtension, RedBool32 deriveBase, RedHandleProcedure deriveFrom, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  RedXInternalTypeProcedure * ih = new(std::nothrow) RedXInternalTypeProcedure();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->handle                           = 0;
  ih->context                          = (RedContext)context;
  ih->gpuIndex                         = gpuIndex;
  ih->isCompute                        = procedureId == RED_PROCEDURE_ID_redCreateProcedureCompute ? 1 : 0;
  ih->procedureCache                   = procedureCache;
  ih->outputDeclaration                = outputDeclaration;
  ih->procedureParameters              = procedureParameters;
  ih->gpuCodeVertex                    = gpuCodeVertex;
  ih->gpuCodeFragment                  = gpuCodeFragment;
  ih->gpuCodeCompute                   = gpuCodeCompute;
  if (state != 0) {
    ih->state                          = state[0];
  }
  ih->deriveBase                       = deriveBase;
  ih->deriveFrom                       = deriveFrom;
  ih->gpuCodeVertexMainProcedureName   = gpuCodeVertexMainProcedureName;
  ih->gpuCodeFragmentMainProcedureName = gpuCodeFragmentMainProcedureName;
  ih->gpuCodeComputeMainProcedureName  = gpuCodeComputeMainProcedureName;
  ih->handleName                       = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroyProcedure(RedHandleProcedure procedure, const char * optionalFile, int optionalLine) {
  RedXInternalTypeProcedure * ih = (RedXInternalTypeProcedure *)procedure;

  if (ih == 0) {
    return;
  }

  if (ih->handle != 0) {
    ih->handle->Release();
  }

  delete ih;
}

static RedXInternalTypeSignal * redInternalTypeSignalAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, uint64_t value, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  RedXInternalTypeSignal * ih = new(std::nothrow) RedXInternalTypeSignal();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->handle     = 0;
  ih->value      = value;
  ih->context    = (RedContext)context;
  ih->gpuIndex   = gpuIndex;
  ih->handleName = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroyCpuSignal(RedHandleCpuSignal cpuSignal, const char * optionalFile, int optionalLine) {
  RedXInternalTypeSignal * ih = (RedXInternalTypeSignal *)cpuSignal;

  if (ih == 0) {
    return;
  }

  if (ih->handle != 0) {
    ih->handle->Release();
  }

  delete ih;
}

static void redInternalDestroyGpuSignal(RedHandleGpuSignal gpuSignal, const char * optionalFile, int optionalLine) {
  RedXInternalTypeSignal * ih = (RedXInternalTypeSignal *)gpuSignal;

  if (ih == 0) {
    return;
  }

  if (ih->handle != 0) {
    ih->handle->Release();
  }

  delete ih;
}

static void redInternalDestroyGpuToCpuSignal(RedHandleGpuToCpuSignal gpuToCpuSignal, const char * optionalFile, int optionalLine) {
  RedXInternalTypeSignal * ih = (RedXInternalTypeSignal *)gpuToCpuSignal;

  if (ih == 0) {
    return;
  }

  if (ih->handle != 0) {
    ih->handle->Release();
  }

  delete ih;
}

static RedXInternalTypeQueue * redInternalTypeQueueAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, unsigned queueFamilyIndex, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  RedXInternalTypeQueue * ih = new(std::nothrow) RedXInternalTypeQueue();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->handle           = 0;
  ih->context          = (RedContext)context;
  ih->gpuIndex         = gpuIndex;
  ih->queueFamilyIndex = queueFamilyIndex;
  ih->handleName       = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroyQueue(RedHandleQueue queue, const char * optionalFile, int optionalLine) {
  RedXInternalTypeQueue * ih = (RedXInternalTypeQueue *)queue;

  if (ih == 0) {
    return;
  }

  if (ih->handle != 0) {
    ih->handle->Release();
  }

  delete ih;
}

static RedXInternalTypeCalls * redInternalTypeCallsAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  const RedStatuses _0 = {};
  RedXInternalTypeCalls * ih = new(std::nothrow) RedXInternalTypeCalls();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->handle                       = 0;
  ih->memory                       = 0;
  ih->context                      = (RedContext)context;
  ih->gpuIndex                     = gpuIndex;
  ih->reusable                     = 0;
  ih->currentProcedureTypeContext  = RED_PROCEDURE_TYPE_COMPUTE;
  ih->currentDepthStencil          = 0;
  ih->currentColorsCount           = 0;
  ih->currentColors[0]             = 0;
  ih->currentColors[1]             = 0;
  ih->currentColors[2]             = 0;
  ih->currentColors[3]             = 0;
  ih->currentColors[4]             = 0;
  ih->currentColors[5]             = 0;
  ih->currentColors[6]             = 0;
  ih->currentColors[7]             = 0;
  ih->statuses                     = _0;
  ih->gpuToCpuSignalsToSignalCount = 0;
  ih->handleName                   = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroyCalls(RedHandleCallsMemory callsMemory, const char * optionalFile, int optionalLine) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)callsMemory;

  if (ih == 0) {
    return;
  }

  if (ih->handle != 0) {
    ih->handle->Release();
  }
  if (ih->memory != 0) {
    ih->memory->Release();
  }

  delete ih;
}

static RedXInternalTypeSurface * redInternalTypeSurfaceAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, RedXInternalTypeSurfaceType type, const void * window, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  RedXInternalTypeSurface * ih = new(std::nothrow) RedXInternalTypeSurface();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->window     = window;
  ih->context    = (RedContext)context;
  ih->gpuIndex   = gpuIndex;
  ih->type       = type;
  ih->handleName = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroySurface(RedHandleSurface surface, const char * optionalFile, int optionalLine) {
  RedXInternalTypeSurface * ih = (RedXInternalTypeSurface *)surface;

  if (ih == 0) {
    return;
  }

  delete ih;
}

static RedXInternalTypePresent * redInternalTypePresentAllocate(RedXInternalTypeContext * context, unsigned gpuIndex, const char * handleName, RedXInternalTypeQueue * queue, RedXInternalTypeSurface * surface, unsigned imagesWidth, unsigned imagesHeight, unsigned imagesLayersCount, RedPresentVsyncMode vsyncMode, RedStatuses * outStatuses, RedProcedureId procedureId, int procedureCallIndex, const char * optionalFile, int optionalLine) {
  RedXInternalTypePresent * ih = new(std::nothrow) RedXInternalTypePresent();
  if (ih == 0) {
    redInternalSetStatus(context, context->gpus[gpuIndex].gpu, outStatuses, procedureCallIndex, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return 0;
  }
  ih->handle     = 0;
  ih->context    = (RedContext)context;
  ih->gpuIndex   = gpuIndex;
  ih->queue      = queue;
  ih->surface    = surface;
  ih->images[0]  = redInternalTypeImageAllocate(context, gpuIndex, handleName, RED_IMAGE_DIMENSIONS_2D, RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1, RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1, imagesWidth, imagesHeight, 1, 1, imagesLayersCount, RED_MULTISAMPLE_COUNT_BITFLAG_1, RED_ACCESS_BITFLAG_OUTPUT_COLOR_W, RED_ACCESS_BITFLAG_OUTPUT_COLOR_W, queue->queueFamilyIndex, 0, outStatuses, procedureId, procedureCallIndex, optionalFile, optionalLine);
  ih->images[1]  = redInternalTypeImageAllocate(context, gpuIndex, handleName, RED_IMAGE_DIMENSIONS_2D, RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1, RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1, imagesWidth, imagesHeight, 1, 1, imagesLayersCount, RED_MULTISAMPLE_COUNT_BITFLAG_1, RED_ACCESS_BITFLAG_OUTPUT_COLOR_W, RED_ACCESS_BITFLAG_OUTPUT_COLOR_W, queue->queueFamilyIndex, 0, outStatuses, procedureId, procedureCallIndex, optionalFile, optionalLine);
  ih->vsyncMode  = vsyncMode;
  ih->handleName = handleName == 0 ? "" : handleName;
  return ih;
}

static void redInternalDestroyPresent(RedHandlePresent present, const char * optionalFile, int optionalLine) {
  RedXInternalTypePresent * ih = (RedXInternalTypePresent *)present;

  if (ih == 0) {
    return;
  }

  if (ih->handle != 0) {
    ih->handle->Release();
  }
  redInternalDestroyImage((RedHandleImage)ih->images[0], optionalFile, optionalLine);
  redInternalDestroyImage((RedHandleImage)ih->images[1], optionalFile, optionalLine);

  delete ih;
}

// REDGPU and REDGPU X APIs

__declspec(dllexport) void redCreateContext(RedTypeProcedureMalloc malloc, RedTypeProcedureFree free, RedTypeProcedureMallocTagged optionalMallocTagged, RedTypeProcedureFreeTagged optionalFreeTagged, RedTypeProcedureDebugCallback debugCallback, RedSdkVersion sdkVersion, unsigned sdkExtensionsCount, const unsigned * sdkExtensions, const char * optionalProgramName, unsigned optionalProgramVersion, const char * optionalEngineName, unsigned optionalEngineVersion, const void * optionalSettings, RedContext * outContext, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateContext;

  PIXBeginEvent(0, __FUNCTION__);

  HRESULT hr = S_OK;

  D3D_FEATURE_LEVEL d3dFeatureLevel         = D3D_FEATURE_LEVEL_12_0;
  RedBool32         d3dMemoryAllocateZeroed = 0;

  if (optionalSettings != 0) {
    struct SettingsD3DFeatureLevel {
      unsigned settings;
      void *   next;
      unsigned d3dFeatureLevel;
    };
    struct SettingsD3DFeatureLevel * settings0 = (struct SettingsD3DFeatureLevel *)optionalSettings;
    if (settings0->settings == 12000) {
      d3dFeatureLevel = (D3D_FEATURE_LEVEL)settings0->d3dFeatureLevel;

      if (settings0->next != 0) {
        struct SettingsMemoryAllocateZeroed {
          unsigned  settings;
          void *    next;
          RedBool32 memoryAllocateZeroed;
        };
        struct SettingsMemoryAllocateZeroed * settings1 = (struct SettingsMemoryAllocateZeroed *)settings0->next;
        if (settings1->settings == 12001) {
          d3dMemoryAllocateZeroed = settings1->memoryAllocateZeroed;
        }
      }
    }
  }

  RedXInternalTypeContext * ctx = new(std::nothrow) RedXInternalTypeContext();
  if (ctx == 0) {
    redInternalSetStatus(ctx, 0, outStatuses, 0, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    outContext[0] = 0;
    PIXEndEvent();
    return;
  }
  ctx->internal.debugCallback   = debugCallback;
  ctx->internal.d3dFeatureLevel = d3dFeatureLevel;

  for (unsigned i = 0; i < sdkExtensionsCount; i += 1) {
    unsigned ext = (unsigned)sdkExtensions[i];
    if (ext < 16) {
      ctx->internal.requestedExtensions[ext] = 1;
    }
  }

  if (debugCallback != 0) {
    ctx->internal.debugContext = x12DebugEnable(optionalFile, optionalLine);
  }

  hr = x12CreateFactory2(debugCallback != 0 ? DXGI_CREATE_FACTORY_DEBUG : 0, (IDXGIFactory4 **)&ctx->contextHandle, optionalFile, optionalLine);
  if (hr < 0) {
    redInternalDestroyContext((RedContext)ctx, 0, optionalFile, optionalLine);
    ctx = 0;
    outContext[0] = 0;
    PIXEndEvent();
    return;
  }

  {
    unsigned        adapterIndex = 0;
    unsigned        gpuIndex     = 0;
    IDXGIAdapter3 * adapter      = 0;
    while (x12FactoryEnumAdapters1((IDXGIFactory4 *)ctx->contextHandle, adapterIndex, &adapter, optionalFile, optionalLine) != /*DXGI_ERROR_NOT_FOUND*/MAKE_HRESULT(1, 0x87a, 2)) {
      if (x12CreateDevice(adapter, d3dFeatureLevel, 0, optionalFile, optionalLine) >= 0) {
        try {
          ctx->internal.adapters.push_back(adapter);
        } catch (...) {
          redInternalSetStatus(ctx, 0, outStatuses, 16, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
        }
        gpuIndex += 1;
      } else {
        adapter->Release();
      }
      adapterIndex += 1;
    }
  }

  ctx->gpusCount = (unsigned)ctx->internal.adapters.size();

  if (ctx->gpusCount == 0) {
    outContext[0] = 0;
    PIXEndEvent();
    return;
  }

  try {
    ctx->internal.adaptersMemoryTypes.resize(ctx->gpusCount);
    ctx->internal.adaptersMemoryTypesDescription.resize(ctx->gpusCount);
    ctx->internal.adaptersMemoryTypesDescriptionString.resize(ctx->gpusCount);
    ctx->internal.adaptersMemoryHeaps.resize(ctx->gpusCount);
    ctx->internal.adaptersQueues.resize(ctx->gpusCount);
    ctx->internal.adaptersQueuesFamilyIndex.resize(ctx->gpusCount);
    ctx->internal.adaptersQueuesCanCopy.resize(ctx->gpusCount);
    ctx->internal.adaptersQueuesCanDraw.resize(ctx->gpusCount);
    ctx->internal.adaptersQueuesCanCompute.resize(ctx->gpusCount);
    ctx->internal.adaptersQueuesCopyLimits.resize(ctx->gpusCount);
    ctx->internal.adaptersImageD3D12FormatsFeatures.resize(ctx->gpusCount);
    ctx->internal.adaptersImageD3D12FormatsMultisampleFeatures.resize(ctx->gpusCount);
    ctx->internal.adaptersImageFormatsLimitsImageDimensions1D.resize(ctx->gpusCount);
    ctx->internal.adaptersImageFormatsLimitsImageDimensions2D.resize(ctx->gpusCount);
    ctx->internal.adaptersImageFormatsLimitsImageDimensions2DMultisample.resize(ctx->gpusCount);
    ctx->internal.adaptersImageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered.resize(ctx->gpusCount);
    ctx->internal.adaptersImageFormatsLimitsImageDimensions3D.resize(ctx->gpusCount);
    ctx->internal.adaptersImageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered.resize(ctx->gpusCount);
    ctx->internal.adaptersImageFormatsFeatures.resize(ctx->gpusCount);
    ctx->internal.adaptersImageXFormatsLimitsImageDimensions1D.resize(ctx->gpusCount);
    ctx->internal.adaptersImageXFormatsLimitsImageDimensions2D.resize(ctx->gpusCount);
    ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DMultisample.resize(ctx->gpusCount);
    ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered.resize(ctx->gpusCount);
    ctx->internal.adaptersImageXFormatsLimitsImageDimensions3D.resize(ctx->gpusCount);
    ctx->internal.adaptersImageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered.resize(ctx->gpusCount);
    ctx->internal.adaptersImageXFormatsFeatures.resize(ctx->gpusCount);
    ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures.resize(ctx->gpusCount);
    ctx->internal.adaptersDescriptorHandleIncrementSizesCBVSRVUAV.resize(ctx->gpusCount);
    ctx->internal.adaptersDescriptorHandleIncrementSizesSampler.resize(ctx->gpusCount);
    ctx->internal.adaptersGpuInfoOptionalInfoArrayTimestamp.resize(ctx->gpusCount);
    ctx->internal.adaptersGpuInfoOptionalInfoComputingLanguageFeatureLevel1.resize(ctx->gpusCount);
    ctx->internal.adaptersGpuInfoOptionalInfoRayTracing.resize(ctx->gpusCount);
    ctx->internal.adaptersGpuInfoOptionalInfoDriverProperties.resize(ctx->gpusCount);
    ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil.resize(ctx->gpusCount);
    ctx->internal.adaptersGpuInfoOptionalInfoProcedureParametersHandles.resize(ctx->gpusCount);
    ctx->internal.adaptersGpuInfoOptionalInfoRasterizationMode.resize(ctx->gpusCount);
    ctx->internal.adaptersGpuInfoOptionalInfoFormalMemoryModel.resize(ctx->gpusCount);
    ctx->internal.adaptersGpuInfoOptionalInfoAdditionalInfo0.resize(ctx->gpusCount);
  } catch (...) {
    redInternalSetStatus(ctx, 0, outStatuses, 17, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    redInternalDestroyContext((RedContext)ctx, 0, optionalFile, optionalLine);
    ctx = 0;
    outContext[0] = 0;
    PIXEndEvent();
    return;
  }

  ctx->gpus = new(std::nothrow) RedXInternalTypeGpuInfo[ctx->gpusCount]();
  if (ctx->gpus == 0) {
    redInternalSetStatus(ctx, 0, outStatuses, 18, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    redInternalDestroyContext((RedContext)ctx, 0, optionalFile, optionalLine);
    ctx = 0;
    outContext[0] = 0;
    PIXEndEvent();
    return;
  }

  ctx->gpusStatuses = new(std::nothrow) RedStatuses[ctx->gpusCount]();
  if (ctx->gpusStatuses == 0) {
    redInternalSetStatus(ctx, 0, outStatuses, 19, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    redInternalDestroyContext((RedContext)ctx, 0, optionalFile, optionalLine);
    ctx = 0;
    outContext[0] = 0;
    PIXEndEvent();
    return;
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }
    ctx->gpus[i].gpuDevice = (RedHandleGpuDevice)ctx->internal.adapters[i];
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }
    if (ctx->internal.d3dFeatureLevel >= 0xc100) { // D3D_FEATURE_LEVEL_12_1
      x12CreateDevice5((IDXGIAdapter3 *)ctx->gpus[i].gpuDevice, d3dFeatureLevel, (ID3D12Device5 **)&ctx->gpus[i].gpu, optionalFile, optionalLine);
    } else {
      x12CreateDevice((IDXGIAdapter3 *)ctx->gpus[i].gpuDevice, d3dFeatureLevel, (ID3D12Device3 **)&ctx->gpus[i].gpu, optionalFile, optionalLine);
    }
    if (debugCallback != 0) {
      if (ctx->gpus[i].gpu != 0) {
        x12ObjectSetName((ID3D12Object *)ctx->gpus[i].gpu, L"[REDGPU X Context Internal Handle] gpu", optionalFile, optionalLine);
      }
    }
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }
    D3D12_FEATURE_DATA_ARCHITECTURE arch = {};
    x12DeviceCheckFeatureSupport((ID3D12Device3 *)ctx->gpus[i].gpu, D3D12_FEATURE_ARCHITECTURE, &arch, sizeof(arch), optionalFile, optionalLine);
    DXGI_ADAPTER_DESC2 desc = {};
    x12AdapterGetDesc2((IDXGIAdapter3 *)ctx->gpus[i].gpuDevice, &desc, optionalFile, optionalLine);
    for (unsigned j = 0; j < 128; j += 1) {
      ctx->gpus[i].gpuName[j] = (char)desc.Description[j];
    }
    if ((desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) == DXGI_ADAPTER_FLAG_SOFTWARE) {
      ctx->gpus[i].gpuType = RED_GPU_TYPE_CPU;
    } else if (arch.CacheCoherentUMA == 1) {
      ctx->gpus[i].gpuType = RED_GPU_TYPE_INTEGRATED;
    } else {
      ctx->gpus[i].gpuType = RED_GPU_TYPE_DISCRETE;
    }
    ctx->gpus[i].gpuVendorId = desc.VendorId;
    ctx->gpus[i].gpuDeviceId = desc.DeviceId;
    ctx->gpus[i].gpuDriverVersion = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[0]  = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[1]  = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[2]  = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[3]  = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[4]  = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[5]  = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[6]  = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[7]  = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[8]  = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[9]  = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[10] = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[11] = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[12] = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[13] = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[14] = 0;
    ctx->gpus[i].gpuProcedureCacheUuid[15] = 0;
    ctx->internal.adaptersMemoryTypesDescriptionString[i].memoryTypesDescriptionString[0] = "D3D12_HEAP_TYPE_DEFAULT | D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS";
    ctx->internal.adaptersMemoryTypesDescriptionString[i].memoryTypesDescriptionString[1] = "D3D12_HEAP_TYPE_DEFAULT | D3D12_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES";
    ctx->internal.adaptersMemoryTypesDescriptionString[i].memoryTypesDescriptionString[2] = "D3D12_HEAP_TYPE_DEFAULT | D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES | D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT";
    ctx->internal.adaptersMemoryTypesDescriptionString[i].memoryTypesDescriptionString[3] = "D3D12_HEAP_TYPE_DEFAULT | D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES | D3D12_DEFAULT_MSAA_RESOURCE_PLACEMENT_ALIGNMENT";
    ctx->internal.adaptersMemoryTypesDescriptionString[i].memoryTypesDescriptionString[4] = "D3D12_HEAP_TYPE_UPLOAD";
    ctx->internal.adaptersMemoryTypesDescriptionString[i].memoryTypesDescriptionString[5] = "D3D12_HEAP_TYPE_READBACK";
    ctx->internal.adaptersMemoryTypesDescription[i].memoryTypesDescription[0] = &ctx->internal.adaptersMemoryTypesDescriptionString[i].memoryTypesDescriptionString[0][0];
    ctx->internal.adaptersMemoryTypesDescription[i].memoryTypesDescription[1] = &ctx->internal.adaptersMemoryTypesDescriptionString[i].memoryTypesDescriptionString[1][0];
    ctx->internal.adaptersMemoryTypesDescription[i].memoryTypesDescription[2] = &ctx->internal.adaptersMemoryTypesDescriptionString[i].memoryTypesDescriptionString[2][0];
    ctx->internal.adaptersMemoryTypesDescription[i].memoryTypesDescription[3] = &ctx->internal.adaptersMemoryTypesDescriptionString[i].memoryTypesDescriptionString[3][0];
    ctx->internal.adaptersMemoryTypesDescription[i].memoryTypesDescription[4] = &ctx->internal.adaptersMemoryTypesDescriptionString[i].memoryTypesDescriptionString[4][0];
    ctx->internal.adaptersMemoryTypesDescription[i].memoryTypesDescription[5] = &ctx->internal.adaptersMemoryTypesDescriptionString[i].memoryTypesDescriptionString[5][0];
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[0].isCpuMappable = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[0].isCpuCoherent = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[0].isCpuCached   = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[1].isCpuMappable = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[1].isCpuCoherent = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[1].isCpuCached   = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[2].isCpuMappable = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[2].isCpuCoherent = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[2].isCpuCached   = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[3].isCpuMappable = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[3].isCpuCoherent = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[3].isCpuCached   = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[4].isCpuMappable = 1;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[4].isCpuCoherent = 1;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[4].isCpuCached   = 0;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[5].isCpuMappable = 1;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[5].isCpuCoherent = 1;
    ctx->internal.adaptersMemoryTypes[i].memoryTypes[5].isCpuCached   = 1;
    ctx->gpus[i].memoryTypesCount       = 6;
    ctx->gpus[i].memoryTypes            = ctx->internal.adaptersMemoryTypes[i].memoryTypes;
    ctx->gpus[i].memoryTypesDescription = (char **)ctx->internal.adaptersMemoryTypesDescription[i].memoryTypesDescription;
    if (ctx->gpus[i].gpuType == RED_GPU_TYPE_DISCRETE) {
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[0].memoryHeapIndex  = 0;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[1].memoryHeapIndex  = 0;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[2].memoryHeapIndex  = 0;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[3].memoryHeapIndex  = 0;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[4].memoryHeapIndex  = 1;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[5].memoryHeapIndex  = 1;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[0].isGpuVram        = 1;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[1].isGpuVram        = 1;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[2].isGpuVram        = 1;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[3].isGpuVram        = 1;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[4].isGpuVram        = 0;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[5].isGpuVram        = 0;
      ctx->internal.adaptersMemoryHeaps[i].memoryHeaps[0].memoryBytesCount = desc.DedicatedVideoMemory;
      ctx->internal.adaptersMemoryHeaps[i].memoryHeaps[0].isGpuVram        = 1;
      ctx->internal.adaptersMemoryHeaps[i].memoryHeaps[1].memoryBytesCount = desc.SharedSystemMemory;
      ctx->internal.adaptersMemoryHeaps[i].memoryHeaps[1].isGpuVram        = 0;
      ctx->gpus[i].memoryHeapsCount       = 2;
      ctx->gpus[i].memoryHeaps            = ctx->internal.adaptersMemoryHeaps[i].memoryHeaps;
      ctx->gpus[i].memoryHeapsDescription = 0;
    } else {
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[0].memoryHeapIndex  = 0;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[1].memoryHeapIndex  = 0;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[2].memoryHeapIndex  = 0;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[3].memoryHeapIndex  = 0;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[4].memoryHeapIndex  = 0;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[5].memoryHeapIndex  = 0;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[0].isGpuVram        = 1;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[1].isGpuVram        = 1;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[2].isGpuVram        = 1;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[3].isGpuVram        = 1;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[4].isGpuVram        = 1;
      ctx->internal.adaptersMemoryTypes[i].memoryTypes[5].isGpuVram        = 1;
      ctx->internal.adaptersMemoryHeaps[i].memoryHeaps[0].memoryBytesCount = desc.SharedSystemMemory;
      ctx->internal.adaptersMemoryHeaps[i].memoryHeaps[0].isGpuVram        = 1;
      ctx->gpus[i].memoryHeapsCount       = 1;
      ctx->gpus[i].memoryHeaps            = ctx->internal.adaptersMemoryHeaps[i].memoryHeaps;
      ctx->gpus[i].memoryHeapsDescription = 0;
    }
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }

    const unsigned queueFamilyIndex0Direct  = 0;
    const unsigned queueFamilyIndex1Compute = 1;
    const unsigned queueFamilyIndex2Copy    = 2;

    D3D12_COMMAND_QUEUE_DESC desc = {};
    desc.Type     = D3D12_COMMAND_LIST_TYPE_DIRECT;
    desc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
    desc.Flags    = D3D12_COMMAND_QUEUE_FLAG_NONE;
    desc.NodeMask = 0;
    RedXInternalTypeQueue * queue = redInternalTypeQueueAllocate(ctx, i, "[REDGPU X Context Internal Handle] the first queue", queueFamilyIndex0Direct, &ctx->gpusStatuses[i], procedureId, 25, optionalFile, optionalLine);
    if (queue == 0) {
      continue;
    }
    HRESULT hr = x12DeviceCreateCommandQueue((ID3D12Device3 *)ctx->gpus[i].gpu, &desc, &queue->handle, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyQueue((RedHandleQueue)queue, optionalFile, optionalLine);
      queue = 0;
      continue;
    }
    if (debugCallback != 0) {
      if (queue->handle != 0) {
        std::wstring handleNameW(queue->handleName.begin(), queue->handleName.end());
        x12ObjectSetName((ID3D12Object *)queue->handle, &handleNameW[0], optionalFile, optionalLine);
      }
    }
    RedQueueCopyLimits queueCopyLimits = {};
    queueCopyLimits.copyBlockTexelsCountWidth  = 1;
    queueCopyLimits.copyBlockTexelsCountHeight = 1;
    queueCopyLimits.copyBlockTexelsCountDepth  = 1;
    try {
      ctx->internal.adaptersQueues[i].push_back((RedHandleQueue)queue);
      ctx->internal.adaptersQueuesFamilyIndex[i].push_back(queueFamilyIndex0Direct);
      ctx->internal.adaptersQueuesCanCopy[i].push_back(1);
      ctx->internal.adaptersQueuesCanDraw[i].push_back(1);
      ctx->internal.adaptersQueuesCanCompute[i].push_back(1);
      ctx->internal.adaptersQueuesCopyLimits[i].push_back(queueCopyLimits);
    } catch (...) {
      redInternalSetStatus(ctx, ctx->gpus[i].gpu, &ctx->gpusStatuses[i], 28, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
      redInternalDestroyQueue((RedHandleQueue)queue, optionalFile, optionalLine);
      queue = 0;
      continue;
    }
    ctx->gpus[i].queuesCount       = 1;
    ctx->gpus[i].queues            = &ctx->internal.adaptersQueues[i][0];
    ctx->gpus[i].queuesDescription = 0;
    ctx->gpus[i].queuesFamilyIndex = &ctx->internal.adaptersQueuesFamilyIndex[i][0];
    ctx->gpus[i].queuesCanCopy     = &ctx->internal.adaptersQueuesCanCopy[i][0];
    ctx->gpus[i].queuesCanDraw     = &ctx->internal.adaptersQueuesCanDraw[i][0];
    ctx->gpus[i].queuesCanCompute  = &ctx->internal.adaptersQueuesCanCompute[i][0];
    ctx->gpus[i].queuesCopyLimits  = &ctx->internal.adaptersQueuesCopyLimits[i][0];
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }
    ctx->gpus[i].maxMemoryAllocateCount                      = 0xFFFFFFFF;
    ctx->gpus[i].minMemoryAllocateBytesAlignment             = 64;
    ctx->gpus[i].maxMemoryAllocateBytesCount                 = 0x80000000;
    ctx->gpus[i].minMemoryNonCoherentBlockBytesCount         = 256;
    ctx->gpus[i].maxCreateSamplerCount                       = 4000;
    ctx->gpus[i].minMemoryPageSeparationArrayImageBytesCount = D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT;
    ctx->gpus[i].minArrayROCStructMemberRangeBytesAlignment  = D3D12_CONSTANT_BUFFER_DATA_PLACEMENT_ALIGNMENT;
    ctx->gpus[i].maxArrayROCStructMemberRangeBytesCount      = D3D12_REQ_CONSTANT_BUFFER_ELEMENT_COUNT * 16;
    ctx->gpus[i].minArrayRORWStructMemberRangeBytesAlignment = D3D12_RAW_UAV_SRV_BYTE_ALIGNMENT;
    ctx->gpus[i].maxArrayRORWStructMemberRangeBytesCount     = 0xFFFFFFFF;
    ctx->gpus[i].maxArrayIndexUint32Value                    = 0xFFFFFFFF;
    ctx->gpus[i].maxImageDimensions1D                        = D3D12_REQ_TEXTURE1D_U_DIMENSION;
    ctx->gpus[i].maxImageDimensions2D                        = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    ctx->gpus[i].maxImageDimensions3D                        = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
    ctx->gpus[i].maxImageDimensionsCube                      = D3D12_REQ_TEXTURECUBE_DIMENSION;
    ctx->gpus[i].maxImageLayersCount                         = D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION;
    ctx->gpus[i].maxSamplerMipLodBias                        = D3D12_MIP_LOD_BIAS_MAX;
    ctx->gpus[i].maxSamplerAnisotropy                        = D3D12_MAX_MAXANISOTROPY;
    ctx->gpus[i].precisionBitsSamplerFilteringMagMin         = D3D12_SUBTEXEL_FRACTIONAL_BIT_COUNT;
    ctx->gpus[i].precisionBitsSamplerFilteringMip            = D3D12_MIP_LOD_FRACTIONAL_BIT_COUNT;
    ctx->gpus[i].maxOutputWidth                              = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    ctx->gpus[i].maxOutputHeight                             = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    ctx->gpus[i].maxOutputColorsCount                        = D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT;
    ctx->gpus[i].supportedMultisampleCountsForOutputDepth    = RED_MULTISAMPLE_COUNT_BITFLAG_1 | RED_MULTISAMPLE_COUNT_BITFLAG_4;
    ctx->gpus[i].supportedMultisampleCountsForOutputStencil  = RED_MULTISAMPLE_COUNT_BITFLAG_1 | RED_MULTISAMPLE_COUNT_BITFLAG_4;
    ctx->gpus[i].supportedMultisampleCountsForOutputColor    = RED_MULTISAMPLE_COUNT_BITFLAG_1 | RED_MULTISAMPLE_COUNT_BITFLAG_4;
    ctx->gpus[i].supportedMultisampleCountsForEmptyOutput    = RED_MULTISAMPLE_COUNT_BITFLAG_1 | RED_MULTISAMPLE_COUNT_BITFLAG_4;
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }
    D3D12_FEATURE_DATA_D3D12_OPTIONS features = {};
    HRESULT hr = x12DeviceCheckFeatureSupport((ID3D12Device3 *)ctx->gpus[i].gpu, D3D12_FEATURE_D3D12_OPTIONS, &features, sizeof(features), optionalFile, optionalLine);
    if (hr < 0) {
      continue;
    }
    unsigned maxStructPerStageArrayROsCount = 0;
    if (features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_1 || features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_2) {
      maxStructPerStageArrayROsCount = 12;
    } else if (features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_3) {
      maxStructPerStageArrayROsCount = 1000000;
    }
    unsigned maxStructPerStageArrayRWsCount = 0;
    if (features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_1 || features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_2) {
      maxStructPerStageArrayRWsCount = 64;
    } else if (features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_3) {
      maxStructPerStageArrayRWsCount = 1000000;
    }
    unsigned maxStructPerStageSamplersCount = 0;
    if (features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_1) {
      maxStructPerStageSamplersCount = 16;
    } else if (features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_2 || features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_3) {
      maxStructPerStageSamplersCount = 2000;
    }
    unsigned maxStructPerStageTextureROsCount = 0;
    if (features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_1) {
      maxStructPerStageTextureROsCount = 128;
    } else if (features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_2 || features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_3) {
      maxStructPerStageTextureROsCount = 1000000;
    }
    unsigned maxStructPerStageTextureRWsCount = 0;
    if (features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_1 || features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_2) {
      maxStructPerStageTextureRWsCount = 64;
    } else if (features.ResourceBindingTier == D3D12_RESOURCE_BINDING_TIER_3) {
      maxStructPerStageTextureRWsCount = 1000000;
    }
    ctx->gpus[i].maxStructSlotsCount                       = 0xFFFFFFF0;
    ctx->gpus[i].maxStructPerStageArrayROCsCount           = maxStructPerStageArrayROsCount;
    ctx->gpus[i].maxStructPerStageArrayRORWsCount          = maxStructPerStageArrayRWsCount;
    ctx->gpus[i].maxStructPerStageSamplersCount            = maxStructPerStageSamplersCount;
    ctx->gpus[i].maxStructPerStageTextureROsCount          = maxStructPerStageTextureROsCount;
    ctx->gpus[i].maxStructPerStageTextureRWsCount          = maxStructPerStageTextureRWsCount;
    ctx->gpus[i].maxStructPerStageAllResourcesCount        = 0xFFFFFFFF;
    ctx->gpus[i].maxStructArrayROCsCount                   = maxStructPerStageArrayROsCount;
    ctx->gpus[i].maxStructArrayRORWsCount                  = maxStructPerStageArrayRWsCount;
    ctx->gpus[i].maxStructSamplersCount                    = maxStructPerStageSamplersCount;
    ctx->gpus[i].maxStructTextureROsCount                  = maxStructPerStageTextureROsCount;
    ctx->gpus[i].maxStructTextureRWsCount                  = maxStructPerStageTextureRWsCount;
    ctx->gpus[i].maxProcedureParametersVariablesBytesCount = 128;
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }
    ctx->gpus[i].maxViewportDimensions[0]                                          = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    ctx->gpus[i].maxViewportDimensions[1]                                          = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
    ctx->gpus[i].minViewportBoundsRange                                            = D3D12_VIEWPORT_BOUNDS_MIN;
    ctx->gpus[i].maxViewportBoundsRange                                            = D3D12_VIEWPORT_BOUNDS_MAX;
    ctx->gpus[i].precisionBitsViewportCoordinates                                  = D3D12_SUBPIXEL_FRACTIONAL_BIT_COUNT;
    ctx->gpus[i].precisionBitsViewportBounds                                       = D3D12_SUBPIXEL_FRACTIONAL_BIT_COUNT;
    ctx->gpus[i].maxPerStageClipDistances                                          = D3D12_CLIP_OR_CULL_DISTANCE_COUNT;
    ctx->gpus[i].maxPerStageCullDistances                                          = D3D12_CLIP_OR_CULL_DISTANCE_COUNT;
    ctx->gpus[i].maxPerStageClipAndCullDistances                                   = D3D12_CLIP_OR_CULL_DISTANCE_COUNT;
    ctx->gpus[i].maxVertexOutputLocationsCount                                     = D3D12_VS_INPUT_REGISTER_COUNT * D3D12_VS_INPUT_REGISTER_COMPONENTS;
    ctx->gpus[i].maxFragmentInputLocationsCount                                    = D3D12_PS_INPUT_REGISTER_COUNT * D3D12_PS_INPUT_REGISTER_COMPONENTS;
    ctx->gpus[i].maxFragmentOutputColorsCount                                      = D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT;
    ctx->gpus[i].maxFragmentOutputColorsCountBlendDualSource                       = 1;
    ctx->gpus[i].maxFragmentOutputResourcesCount                                   = D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT + D3D12_PS_CS_UAV_REGISTER_COUNT;
    ctx->gpus[i].maxComputeSharedMemoryBytesCount                                  = D3D12_CS_THREAD_LOCAL_TEMP_REGISTER_POOL;
    ctx->gpus[i].maxComputeWorkgroupsCount[0]                                      = D3D12_CS_DISPATCH_MAX_THREAD_GROUPS_PER_DIMENSION;
    ctx->gpus[i].maxComputeWorkgroupsCount[1]                                      = D3D12_CS_DISPATCH_MAX_THREAD_GROUPS_PER_DIMENSION;
    ctx->gpus[i].maxComputeWorkgroupsCount[2]                                      = D3D12_CS_DISPATCH_MAX_THREAD_GROUPS_PER_DIMENSION;
    ctx->gpus[i].maxComputeWorkgroupInvocationsCount                               = D3D12_CS_THREAD_GROUP_MAX_THREADS_PER_GROUP;
    ctx->gpus[i].maxComputeWorkgroupDimensions[0]                                  = D3D12_CS_THREAD_GROUP_MAX_X;
    ctx->gpus[i].maxComputeWorkgroupDimensions[1]                                  = D3D12_CS_THREAD_GROUP_MAX_Y;
    ctx->gpus[i].maxComputeWorkgroupDimensions[2]                                  = D3D12_CS_THREAD_GROUP_MAX_Z;
    ctx->gpus[i].minImageSampleImageFetchOffset                                    = D3D12_COMMONSHADER_TEXEL_OFFSET_MAX_NEGATIVE;
    ctx->gpus[i].maxImageSampleImageFetchOffset                                    = D3D12_COMMONSHADER_TEXEL_OFFSET_MAX_POSITIVE;
    ctx->gpus[i].minImageGatherOffset                                              = D3D12_COMMONSHADER_TEXEL_OFFSET_MAX_NEGATIVE;
    ctx->gpus[i].maxImageGatherOffset                                              = D3D12_COMMONSHADER_TEXEL_OFFSET_MAX_POSITIVE;
    ctx->gpus[i].minInterpolateAtOffset                                            = -0.5f;
    ctx->gpus[i].maxInterpolateAtOffset                                            = 0.4375f;
    ctx->gpus[i].precisionBitsInterpolateAtOffset                                  = 4;
    ctx->gpus[i].optimalCopyArrayImageRangeArrayBytesFirstBytesAlignment           = D3D12_TEXTURE_DATA_PLACEMENT_ALIGNMENT;
    ctx->gpus[i].optimalCopyArrayImageRangeArrayTexelsCountToNextRowBytesAlignment = D3D12_TEXTURE_DATA_PITCH_ALIGNMENT;
    ctx->gpus[i].supportsWsi                                                       = 1;
    ctx->gpus[i].supportsMemoryGetBudget                                           = 1;
    ctx->gpus[i].supportsFullArrayIndexUint32Value                                 = 1;
    ctx->gpus[i].supportsSamplerAnisotropy                                         = 1;
    ctx->gpus[i].supportsTextureDimensionsCubeLayered                              = 1;
    ctx->gpus[i].supportsProcedureStateRasterizationDepthClamp                     = 1;
    ctx->gpus[i].supportsProcedureStateRasterizationDepthBiasDynamic               = 0;
    ctx->gpus[i].supportsProcedureStateRasterizationDepthBiasClamp                 = 1;
    ctx->gpus[i].supportsProcedureStateMultisampleSampleShading                    = 0;
    ctx->gpus[i].supportsProcedureStateMultisampleAlphaToOne                       = 0;
    ctx->gpus[i].supportsProcedureStateDepthTestBoundsTest                         = 0;
    ctx->gpus[i].supportsProcedureStateDepthTestBoundsTestDynamic                  = 0;
    ctx->gpus[i].supportsProcedureStateStencilTestFrontAndBackDynamicCompareMask   = 0;
    ctx->gpus[i].supportsProcedureStateStencilTestFrontAndBackDynamicWriteMask     = 0;
    ctx->gpus[i].supportsProcedureStateBlendLogicOp                                = 1;
    ctx->gpus[i].supportsProcedureStateOutputColorsBlendVaryingPerColor            = 1;
    ctx->gpus[i].supportsProcedureStateOutputColorsBlendDualSource                 = 1;
    ctx->gpus[i].supportsMultisampleEmptyOutputVariableMultisampleCount            = 1;
    ctx->gpus[i].supportsMultisampleStandardSampleLocations                        = 1;
    ctx->gpus[i].supportsGpuCodeWritesAndAtomicsInStageVertex                      = 1;
    ctx->gpus[i].supportsGpuCodeWritesAndAtomicsInStageFragment                    = 1;
    ctx->gpus[i].supportsGpuCodeImageGatherExtended                                = 1;
    ctx->gpus[i].supportsGpuCodeTextureRWExtendedFormats                           = 1;
    ctx->gpus[i].supportsGpuCodeTextureRWMultisample                               = 0;
    ctx->gpus[i].supportsGpuCodeTextureRWReadWithoutFormat                         = 1;
    ctx->gpus[i].supportsGpuCodeTextureRWWriteWithoutFormat                        = 1;
    ctx->gpus[i].supportsGpuCodeDynamicallyIndexableArraysOfArrayROCs              = 1;
    ctx->gpus[i].supportsGpuCodeDynamicallyIndexableArraysOfArrayRORWs             = 1;
    ctx->gpus[i].supportsGpuCodeDynamicallyIndexableArraysOfSamplers               = 1;
    ctx->gpus[i].supportsGpuCodeDynamicallyIndexableArraysOfTextureROs             = 1;
    ctx->gpus[i].supportsGpuCodeDynamicallyIndexableArraysOfTextureRWs             = 1;
    ctx->gpus[i].supportsGpuCodeClipDistance                                       = 1;
    ctx->gpus[i].supportsGpuCodeCullDistance                                       = 1;
    ctx->gpus[i].supportsGpuCodeInt64                                              = 1;
    ctx->gpus[i].supportsGpuCodeFloat64                                            = 1;
    ctx->gpus[i].supportsGpuCodeMinLod                                             = 1;
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }
    for (unsigned j = 0; j < 116; j += 1) {
      D3D12_FEATURE_DATA_FORMAT_SUPPORT features = {};
      features.Format = (DXGI_FORMAT)j;
      HRESULT hr = x12DeviceCheckFeatureSupport((ID3D12Device3 *)ctx->gpus[i].gpu, D3D12_FEATURE_FORMAT_SUPPORT, &features, sizeof(features), optionalFile, optionalLine);
      ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[j].hresult = hr;
      if (hr < 0) {
        continue;
      }
      ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[j].Support1 = features.Support1;
      ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[j].Support2 = features.Support2;
    }
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }
    for (unsigned j = 1; j < 116; j += 1) {
      D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS features = {};
      features.Format = (DXGI_FORMAT)j;
      features.Flags  = D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_NONE;
      HRESULT hr = S_OK;
      {
        const RedMultisampleCountBitflag multisampleCount = RED_MULTISAMPLE_COUNT_BITFLAG_1;
        features.SampleCount = 1;
        hr = x12DeviceCheckFeatureSupport((ID3D12Device3 *)ctx->gpus[i].gpu, D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS, &features, sizeof(features), optionalFile, optionalLine);
        if (hr < 0) {
          continue;
        }
        if (features.NumQualityLevels > 0) {
          ctx->internal.adaptersImageD3D12FormatsMultisampleFeatures[i].imageD3D12FormatsMultisampleFeatures[j].supportedMultisampleCounts |= multisampleCount;
        }
        features.NumQualityLevels = 0;
      }
      {
        const RedMultisampleCountBitflag multisampleCount = RED_MULTISAMPLE_COUNT_BITFLAG_2;
        features.SampleCount = 2;
        hr = x12DeviceCheckFeatureSupport((ID3D12Device3 *)ctx->gpus[i].gpu, D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS, &features, sizeof(features), optionalFile, optionalLine);
        if (hr < 0) {
          continue;
        }
        if (features.NumQualityLevels > 0) {
          ctx->internal.adaptersImageD3D12FormatsMultisampleFeatures[i].imageD3D12FormatsMultisampleFeatures[j].supportedMultisampleCounts |= multisampleCount;
        }
        features.NumQualityLevels = 0;
      }
      {
        const RedMultisampleCountBitflag multisampleCount = RED_MULTISAMPLE_COUNT_BITFLAG_4;
        features.SampleCount = 4;
        hr = x12DeviceCheckFeatureSupport((ID3D12Device3 *)ctx->gpus[i].gpu, D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS, &features, sizeof(features), optionalFile, optionalLine);
        if (hr < 0) {
          continue;
        }
        if (features.NumQualityLevels > 0) {
          ctx->internal.adaptersImageD3D12FormatsMultisampleFeatures[i].imageD3D12FormatsMultisampleFeatures[j].supportedMultisampleCounts |= multisampleCount;
        }
        features.NumQualityLevels = 0;
      }
      {
        const RedMultisampleCountBitflag multisampleCount = RED_MULTISAMPLE_COUNT_BITFLAG_8;
        features.SampleCount = 8;
        hr = x12DeviceCheckFeatureSupport((ID3D12Device3 *)ctx->gpus[i].gpu, D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS, &features, sizeof(features), optionalFile, optionalLine);
        if (hr < 0) {
          continue;
        }
        if (features.NumQualityLevels > 0) {
          ctx->internal.adaptersImageD3D12FormatsMultisampleFeatures[i].imageD3D12FormatsMultisampleFeatures[j].supportedMultisampleCounts |= multisampleCount;
        }
        features.NumQualityLevels = 0;
      }
      {
        const RedMultisampleCountBitflag multisampleCount = RED_MULTISAMPLE_COUNT_BITFLAG_16;
        features.SampleCount = 16;
        hr = x12DeviceCheckFeatureSupport((ID3D12Device3 *)ctx->gpus[i].gpu, D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS, &features, sizeof(features), optionalFile, optionalLine);
        if (hr < 0) {
          continue;
        }
        if (features.NumQualityLevels > 0) {
          ctx->internal.adaptersImageD3D12FormatsMultisampleFeatures[i].imageD3D12FormatsMultisampleFeatures[j].supportedMultisampleCounts |= multisampleCount;
        }
        features.NumQualityLevels = 0;
      }
    }
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }
    ctx->gpus[i].imageFormatsLimitsImageDimensions1D                                        = ctx->internal.adaptersImageFormatsLimitsImageDimensions1D[i].imageFormatsLimits;
    ctx->gpus[i].imageFormatsLimitsImageDimensions2D                                        = ctx->internal.adaptersImageFormatsLimitsImageDimensions2D[i].imageFormatsLimits;
    ctx->gpus[i].imageFormatsLimitsImageDimensions2DMultisample                             = ctx->internal.adaptersImageFormatsLimitsImageDimensions2DMultisample[i].imageFormatsLimits;
    ctx->gpus[i].imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered = ctx->internal.adaptersImageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[i].imageFormatsLimits;
    ctx->gpus[i].imageFormatsLimitsImageDimensions3D                                        = ctx->internal.adaptersImageFormatsLimitsImageDimensions3D[i].imageFormatsLimits;
    ctx->gpus[i].imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered     = ctx->internal.adaptersImageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[i].imageFormatsLimits;
    ctx->gpus[i].imageFormatsFeatures                                                       = ctx->internal.adaptersImageFormatsFeatures[i].imageFormatsFeatures;
    for (unsigned j = 0; j < 131; j += 1) {
      ctx->gpus[i].imageFormatsLimitsImageDimensions1D[j].status                                        = RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2D[j].status                                        = RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DMultisample[j].status                             = RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[j].status = RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3D[j].status                                        = RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[j].status     = RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED;
    }
    for (unsigned j = 0; j < 131; j += 1) {
      if        (j == RED_FORMAT_R_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_8_UINT) {
      } else if (j == RED_FORMAT_R_8_SINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_SINT) {
      } else if (j == RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_16_UINT) {
      } else if (j == RED_FORMAT_R_16_SINT) {
      } else if (j == RED_FORMAT_R_16_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_UINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_SINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_FLOAT) {
      } else if (j == RED_FORMAT_R_32_UINT) {
      } else if (j == RED_FORMAT_R_32_SINT) {
      } else if (j == RED_FORMAT_R_32_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_UINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_SINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT) {
      } else {
        continue;
      }
      const unsigned d3d12j = redInternalREDGPUFormatIndexToD3D12FormatIndex(j);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      if ((features.Support1 & D3D12_FORMAT_SUPPORT1_TEXTURE1D) != D3D12_FORMAT_SUPPORT1_TEXTURE1D) {
        continue;
      }
      ctx->gpus[i].imageFormatsLimitsImageDimensions1D[j].maxDimensions.maxWidth     = D3D12_REQ_TEXTURE1D_U_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions1D[j].maxDimensions.maxHeight    = 1;
      ctx->gpus[i].imageFormatsLimitsImageDimensions1D[j].maxDimensions.maxDepth     = 1;
      ctx->gpus[i].imageFormatsLimitsImageDimensions1D[j].maxLevelsCount             = D3D12_REQ_MIP_LEVELS;
      ctx->gpus[i].imageFormatsLimitsImageDimensions1D[j].maxLayersCount             = D3D12_REQ_TEXTURE1D_ARRAY_AXIS_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions1D[j].supportedMultisampleCounts = RED_MULTISAMPLE_COUNT_BITFLAG_1;
      ctx->gpus[i].imageFormatsLimitsImageDimensions1D[j].maxBytesCount              = 0x80000000;
      ctx->gpus[i].imageFormatsLimitsImageDimensions1D[j].status                     = RED_STATUS_SUCCESS;
    }
    for (unsigned j = 0; j < 131; j += 1) {
      if        (j == RED_FORMAT_R_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_8_UINT) {
      } else if (j == RED_FORMAT_R_8_SINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_SINT) {
      } else if (j == RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_16_UINT) {
      } else if (j == RED_FORMAT_R_16_SINT) {
      } else if (j == RED_FORMAT_R_16_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_UINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_SINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_FLOAT) {
      } else if (j == RED_FORMAT_R_32_UINT) {
      } else if (j == RED_FORMAT_R_32_SINT) {
      } else if (j == RED_FORMAT_R_32_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_UINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_SINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT) {
      } else {
        continue;
      }
      const unsigned d3d12j = redInternalREDGPUFormatIndexToD3D12FormatIndex(j);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      if ((features.Support1 & D3D12_FORMAT_SUPPORT1_TEXTURE2D) != D3D12_FORMAT_SUPPORT1_TEXTURE2D) {
        continue;
      }
      ctx->gpus[i].imageFormatsLimitsImageDimensions2D[j].maxDimensions.maxWidth     = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2D[j].maxDimensions.maxHeight    = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2D[j].maxDimensions.maxDepth     = 1;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2D[j].maxLevelsCount             = D3D12_REQ_MIP_LEVELS;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2D[j].maxLayersCount             = D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2D[j].supportedMultisampleCounts = ctx->internal.adaptersImageD3D12FormatsMultisampleFeatures[i].imageD3D12FormatsMultisampleFeatures[d3d12j].supportedMultisampleCounts;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2D[j].maxBytesCount              = 0x80000000;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2D[j].status                     = RED_STATUS_SUCCESS;
    }
    for (unsigned j = 0; j < 131; j += 1) {
      if        (j == RED_FORMAT_R_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_8_UINT) {
      } else if (j == RED_FORMAT_R_8_SINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_SINT) {
      } else if (j == RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_16_UINT) {
      } else if (j == RED_FORMAT_R_16_SINT) {
      } else if (j == RED_FORMAT_R_16_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_UINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_SINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_FLOAT) {
      } else if (j == RED_FORMAT_R_32_UINT) {
      } else if (j == RED_FORMAT_R_32_SINT) {
      } else if (j == RED_FORMAT_R_32_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_UINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_SINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT) {
      } else {
        continue;
      }
      const unsigned d3d12j = redInternalREDGPUFormatIndexToD3D12FormatIndex(j);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      if ((features.Support1 & D3D12_FORMAT_SUPPORT1_TEXTURE2D) != D3D12_FORMAT_SUPPORT1_TEXTURE2D) {
        continue;
      }
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DMultisample[j].maxDimensions.maxWidth     = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DMultisample[j].maxDimensions.maxHeight    = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DMultisample[j].maxDimensions.maxDepth     = 1;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DMultisample[j].maxLevelsCount             = D3D12_REQ_MIP_LEVELS;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DMultisample[j].maxLayersCount             = D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DMultisample[j].supportedMultisampleCounts = ctx->internal.adaptersImageD3D12FormatsMultisampleFeatures[i].imageD3D12FormatsMultisampleFeatures[d3d12j].supportedMultisampleCounts;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DMultisample[j].maxBytesCount              = 0x80000000;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DMultisample[j].status                     = RED_STATUS_SUCCESS;
    }
    for (unsigned j = 0; j < 131; j += 1) {
      if        (j == RED_FORMAT_R_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_8_UINT) {
      } else if (j == RED_FORMAT_R_8_SINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_SINT) {
      } else if (j == RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_16_UINT) {
      } else if (j == RED_FORMAT_R_16_SINT) {
      } else if (j == RED_FORMAT_R_16_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_UINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_SINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_FLOAT) {
      } else if (j == RED_FORMAT_R_32_UINT) {
      } else if (j == RED_FORMAT_R_32_SINT) {
      } else if (j == RED_FORMAT_R_32_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_UINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_SINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT) {
      } else {
        continue;
      }
      const unsigned d3d12j = redInternalREDGPUFormatIndexToD3D12FormatIndex(j);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      if ((features.Support1 & D3D12_FORMAT_SUPPORT1_TEXTURECUBE) != D3D12_FORMAT_SUPPORT1_TEXTURECUBE) {
        continue;
      }
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[j].maxDimensions.maxWidth     = D3D12_REQ_TEXTURECUBE_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[j].maxDimensions.maxHeight    = D3D12_REQ_TEXTURECUBE_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[j].maxDimensions.maxDepth     = 1;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[j].maxLevelsCount             = D3D12_REQ_MIP_LEVELS;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[j].maxLayersCount             = D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[j].supportedMultisampleCounts = RED_MULTISAMPLE_COUNT_BITFLAG_1;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[j].maxBytesCount              = 0x80000000;
      ctx->gpus[i].imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[j].status                     = RED_STATUS_SUCCESS;
    }
    for (unsigned j = 0; j < 131; j += 1) {
      if        (j == RED_FORMAT_R_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_8_UINT) {
      } else if (j == RED_FORMAT_R_8_SINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_SINT) {
      } else if (j == RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_16_UINT) {
      } else if (j == RED_FORMAT_R_16_SINT) {
      } else if (j == RED_FORMAT_R_16_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_UINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_SINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_FLOAT) {
      } else if (j == RED_FORMAT_R_32_UINT) {
      } else if (j == RED_FORMAT_R_32_SINT) {
      } else if (j == RED_FORMAT_R_32_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_UINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_SINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT) {
      } else {
        continue;
      }
      const unsigned d3d12j = redInternalREDGPUFormatIndexToD3D12FormatIndex(j);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      if ((features.Support1 & D3D12_FORMAT_SUPPORT1_TEXTURE3D) != D3D12_FORMAT_SUPPORT1_TEXTURE3D) {
        continue;
      }
      ctx->gpus[i].imageFormatsLimitsImageDimensions3D[j].maxDimensions.maxWidth     = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3D[j].maxDimensions.maxHeight    = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3D[j].maxDimensions.maxDepth     = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3D[j].maxLevelsCount             = D3D12_REQ_MIP_LEVELS;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3D[j].maxLayersCount             = 1;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3D[j].supportedMultisampleCounts = RED_MULTISAMPLE_COUNT_BITFLAG_1;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3D[j].maxBytesCount              = 0x80000000;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3D[j].status                     = RED_STATUS_SUCCESS;
    }
    for (unsigned j = 0; j < 131; j += 1) {
      if        (j == RED_FORMAT_R_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_8_UINT) {
      } else if (j == RED_FORMAT_R_8_SINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_SINT) {
      } else if (j == RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_16_UINT) {
      } else if (j == RED_FORMAT_R_16_SINT) {
      } else if (j == RED_FORMAT_R_16_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_UINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_SINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_FLOAT) {
      } else if (j == RED_FORMAT_R_32_UINT) {
      } else if (j == RED_FORMAT_R_32_SINT) {
      } else if (j == RED_FORMAT_R_32_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_UINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_SINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT) {
      } else {
        continue;
      }
      const unsigned d3d12j = redInternalREDGPUFormatIndexToD3D12FormatIndex(j);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      if ((features.Support1 & D3D12_FORMAT_SUPPORT1_TEXTURE3D) != D3D12_FORMAT_SUPPORT1_TEXTURE3D) {
        continue;
      }
      ctx->gpus[i].imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[j].maxDimensions.maxWidth     = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[j].maxDimensions.maxHeight    = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[j].maxDimensions.maxDepth     = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[j].maxLevelsCount             = D3D12_REQ_MIP_LEVELS;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[j].maxLayersCount             = 1;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[j].supportedMultisampleCounts = RED_MULTISAMPLE_COUNT_BITFLAG_1;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[j].maxBytesCount              = 0x80000000;
      ctx->gpus[i].imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[j].status                     = RED_STATUS_SUCCESS;
    }
    for (unsigned j = 0; j < 131; j += 1) {
      if        (j == RED_FORMAT_R_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_8_UINT) {
      } else if (j == RED_FORMAT_R_8_SINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_SINT) {
      } else if (j == RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_16_UINT) {
      } else if (j == RED_FORMAT_R_16_SINT) {
      } else if (j == RED_FORMAT_R_16_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_UINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_SINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_FLOAT) {
      } else if (j == RED_FORMAT_R_32_UINT) {
      } else if (j == RED_FORMAT_R_32_SINT) {
      } else if (j == RED_FORMAT_R_32_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_UINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_SINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT) {
      } else {
        continue;
      }
      const unsigned d3d12j = redInternalREDGPUFormatIndexToD3D12FormatIndex(j);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      ctx->gpus[i].imageFormatsFeatures[j].supportsCopyR                    = 1;
      ctx->gpus[i].imageFormatsFeatures[j].supportsCopyW                    = 1;
      ctx->gpus[i].imageFormatsFeatures[j].supportsTextureRO                = ((features.Support1 & D3D12_FORMAT_SUPPORT1_SHADER_LOAD)                 == D3D12_FORMAT_SUPPORT1_SHADER_LOAD)                 ? 1 : 0;
      ctx->gpus[i].imageFormatsFeatures[j].supportsTextureRW                = ((features.Support1 & D3D12_FORMAT_SUPPORT1_TYPED_UNORDERED_ACCESS_VIEW) == D3D12_FORMAT_SUPPORT1_TYPED_UNORDERED_ACCESS_VIEW) ? 1 : 0;
      ctx->gpus[i].imageFormatsFeatures[j].supportsOutputDepthStencil       = ((features.Support1 & D3D12_FORMAT_SUPPORT1_DEPTH_STENCIL)               == D3D12_FORMAT_SUPPORT1_DEPTH_STENCIL)               ? 1 : 0;
      ctx->gpus[i].imageFormatsFeatures[j].supportsOutputColor              = ((features.Support1 & D3D12_FORMAT_SUPPORT1_RENDER_TARGET)               == D3D12_FORMAT_SUPPORT1_RENDER_TARGET)               ? 1 : 0;
      ctx->gpus[i].imageFormatsFeatures[j].supportsTextureROFilteringLinear = ((features.Support1 & D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE)               == D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE)               ? 1 : 0;
      ctx->gpus[i].imageFormatsFeatures[j].supportsTextureRWAtomics         = (
                                                                              ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_ADD)                               == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_ADD)                               ||
                                                                              ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS)                       == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS)                       ||
                                                                              ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE) == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE) ||
                                                                              ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE)                          == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE)                          ||
                                                                              ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX)                 == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX)                 ||
                                                                              ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX)               == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX)
                                                                              ) ? 1 : 0;
      ctx->gpus[i].imageFormatsFeatures[j].supportsOutputColorBlend         = ((features.Support1 & D3D12_FORMAT_SUPPORT1_BLENDABLE) == D3D12_FORMAT_SUPPORT1_BLENDABLE) ? 1 : 0;
    }
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }
    for (unsigned j = 0; j < 14; j += 1) {
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions1D[i].imageXFormatsLimits[j].status                                        = RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2D[i].imageXFormatsLimits[j].status                                        = RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DMultisample[i].imageXFormatsLimits[j].status                             = RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[i].imageXFormatsLimits[j].status = RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3D[i].imageXFormatsLimits[j].status                                        = RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[i].imageXFormatsLimits[j].status     = RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED;
    }

    for (unsigned j = 0; j < 14; j += 1) {
      const unsigned d3d12j = redInternalREDGPUXFormatIndexToD3D12FormatIndex(j + 12000);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      if ((features.Support1 & D3D12_FORMAT_SUPPORT1_TEXTURE1D) != D3D12_FORMAT_SUPPORT1_TEXTURE1D) {
        continue;
      }
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions1D[i].imageXFormatsLimits[j].maxDimensions.maxWidth     = D3D12_REQ_TEXTURE1D_U_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions1D[i].imageXFormatsLimits[j].maxDimensions.maxHeight    = 1;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions1D[i].imageXFormatsLimits[j].maxDimensions.maxDepth     = 1;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions1D[i].imageXFormatsLimits[j].maxLevelsCount             = D3D12_REQ_MIP_LEVELS;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions1D[i].imageXFormatsLimits[j].maxLayersCount             = D3D12_REQ_TEXTURE1D_ARRAY_AXIS_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions1D[i].imageXFormatsLimits[j].supportedMultisampleCounts = RED_MULTISAMPLE_COUNT_BITFLAG_1;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions1D[i].imageXFormatsLimits[j].maxBytesCount              = 0x80000000;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions1D[i].imageXFormatsLimits[j].status                     = RED_STATUS_SUCCESS;
    }
    for (unsigned j = 0; j < 14; j += 1) {
      const unsigned d3d12j = redInternalREDGPUXFormatIndexToD3D12FormatIndex(j + 12000);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      if ((features.Support1 & D3D12_FORMAT_SUPPORT1_TEXTURE2D) != D3D12_FORMAT_SUPPORT1_TEXTURE2D) {
        continue;
      }
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2D[i].imageXFormatsLimits[j].maxDimensions.maxWidth     = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2D[i].imageXFormatsLimits[j].maxDimensions.maxHeight    = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2D[i].imageXFormatsLimits[j].maxDimensions.maxDepth     = 1;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2D[i].imageXFormatsLimits[j].maxLevelsCount             = D3D12_REQ_MIP_LEVELS;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2D[i].imageXFormatsLimits[j].maxLayersCount             = D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2D[i].imageXFormatsLimits[j].supportedMultisampleCounts = ctx->internal.adaptersImageD3D12FormatsMultisampleFeatures[i].imageD3D12FormatsMultisampleFeatures[d3d12j].supportedMultisampleCounts;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2D[i].imageXFormatsLimits[j].maxBytesCount              = 0x80000000;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2D[i].imageXFormatsLimits[j].status                     = RED_STATUS_SUCCESS;
    }
    for (unsigned j = 0; j < 14; j += 1) {
      const unsigned d3d12j = redInternalREDGPUXFormatIndexToD3D12FormatIndex(j + 12000);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      if ((features.Support1 & D3D12_FORMAT_SUPPORT1_TEXTURE2D) != D3D12_FORMAT_SUPPORT1_TEXTURE2D) {
        continue;
      }
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DMultisample[i].imageXFormatsLimits[j].maxDimensions.maxWidth     = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DMultisample[i].imageXFormatsLimits[j].maxDimensions.maxHeight    = D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DMultisample[i].imageXFormatsLimits[j].maxDimensions.maxDepth     = 1;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DMultisample[i].imageXFormatsLimits[j].maxLevelsCount             = D3D12_REQ_MIP_LEVELS;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DMultisample[i].imageXFormatsLimits[j].maxLayersCount             = D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DMultisample[i].imageXFormatsLimits[j].supportedMultisampleCounts = ctx->internal.adaptersImageD3D12FormatsMultisampleFeatures[i].imageD3D12FormatsMultisampleFeatures[d3d12j].supportedMultisampleCounts;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DMultisample[i].imageXFormatsLimits[j].maxBytesCount              = 0x80000000;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DMultisample[i].imageXFormatsLimits[j].status                     = RED_STATUS_SUCCESS;
    }
    for (unsigned j = 0; j < 14; j += 1) {
      const unsigned d3d12j = redInternalREDGPUXFormatIndexToD3D12FormatIndex(j + 12000);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      if ((features.Support1 & D3D12_FORMAT_SUPPORT1_TEXTURECUBE) != D3D12_FORMAT_SUPPORT1_TEXTURECUBE) {
        continue;
      }
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[i].imageXFormatsLimits[j].maxDimensions.maxWidth     = D3D12_REQ_TEXTURECUBE_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[i].imageXFormatsLimits[j].maxDimensions.maxHeight    = D3D12_REQ_TEXTURECUBE_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[i].imageXFormatsLimits[j].maxDimensions.maxDepth     = 1;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[i].imageXFormatsLimits[j].maxLevelsCount             = D3D12_REQ_MIP_LEVELS;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[i].imageXFormatsLimits[j].maxLayersCount             = D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[i].imageXFormatsLimits[j].supportedMultisampleCounts = RED_MULTISAMPLE_COUNT_BITFLAG_1;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[i].imageXFormatsLimits[j].maxBytesCount              = 0x80000000;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[i].imageXFormatsLimits[j].status                     = RED_STATUS_SUCCESS;
    }
    for (unsigned j = 0; j < 14; j += 1) {
      const unsigned d3d12j = redInternalREDGPUXFormatIndexToD3D12FormatIndex(j + 12000);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      if ((features.Support1 & D3D12_FORMAT_SUPPORT1_TEXTURE3D) != D3D12_FORMAT_SUPPORT1_TEXTURE3D) {
        continue;
      }
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3D[i].imageXFormatsLimits[j].maxDimensions.maxWidth     = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3D[i].imageXFormatsLimits[j].maxDimensions.maxHeight    = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3D[i].imageXFormatsLimits[j].maxDimensions.maxDepth     = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3D[i].imageXFormatsLimits[j].maxLevelsCount             = D3D12_REQ_MIP_LEVELS;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3D[i].imageXFormatsLimits[j].maxLayersCount             = 1;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3D[i].imageXFormatsLimits[j].supportedMultisampleCounts = RED_MULTISAMPLE_COUNT_BITFLAG_1;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3D[i].imageXFormatsLimits[j].maxBytesCount              = 0x80000000;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3D[i].imageXFormatsLimits[j].status                     = RED_STATUS_SUCCESS;
    }
    for (unsigned j = 0; j < 14; j += 1) {
      const unsigned d3d12j = redInternalREDGPUXFormatIndexToD3D12FormatIndex(j + 12000);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      if ((features.Support1 & D3D12_FORMAT_SUPPORT1_TEXTURE3D) != D3D12_FORMAT_SUPPORT1_TEXTURE3D) {
        continue;
      }
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[i].imageXFormatsLimits[j].maxDimensions.maxWidth     = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[i].imageXFormatsLimits[j].maxDimensions.maxHeight    = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[i].imageXFormatsLimits[j].maxDimensions.maxDepth     = D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[i].imageXFormatsLimits[j].maxLevelsCount             = D3D12_REQ_MIP_LEVELS;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[i].imageXFormatsLimits[j].maxLayersCount             = 1;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[i].imageXFormatsLimits[j].supportedMultisampleCounts = RED_MULTISAMPLE_COUNT_BITFLAG_1;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[i].imageXFormatsLimits[j].maxBytesCount              = 0x80000000;
      ctx->internal.adaptersImageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[i].imageXFormatsLimits[j].status                     = RED_STATUS_SUCCESS;
    }
    for (unsigned j = 0; j < 14; j += 1) {
      const unsigned d3d12j = redInternalREDGPUXFormatIndexToD3D12FormatIndex(j + 12000);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures[j].supportsCopyR                    = 1;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures[j].supportsCopyW                    = 1;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures[j].supportsTextureRO                = ((features.Support1 & D3D12_FORMAT_SUPPORT1_SHADER_LOAD)                 == D3D12_FORMAT_SUPPORT1_SHADER_LOAD)                 ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures[j].supportsTextureRW                = ((features.Support1 & D3D12_FORMAT_SUPPORT1_TYPED_UNORDERED_ACCESS_VIEW) == D3D12_FORMAT_SUPPORT1_TYPED_UNORDERED_ACCESS_VIEW) ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures[j].supportsOutputDepthStencil       = ((features.Support1 & D3D12_FORMAT_SUPPORT1_DEPTH_STENCIL)               == D3D12_FORMAT_SUPPORT1_DEPTH_STENCIL)               ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures[j].supportsOutputColor              = ((features.Support1 & D3D12_FORMAT_SUPPORT1_RENDER_TARGET)               == D3D12_FORMAT_SUPPORT1_RENDER_TARGET)               ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures[j].supportsTextureROFilteringLinear = ((features.Support1 & D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE)               == D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE)               ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures[j].supportsTextureRWAtomics         = (
                                                                                                                 ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_ADD)                               == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_ADD)                               ||
                                                                                                                 ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS)                       == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS)                       ||
                                                                                                                 ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE) == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE) ||
                                                                                                                 ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE)                          == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE)                          ||
                                                                                                                 ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX)                 == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX)                 ||
                                                                                                                 ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX)               == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX)
                                                                                                                 ) ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures[j].supportsOutputColorBlend         = ((features.Support1 & D3D12_FORMAT_SUPPORT1_BLENDABLE) == D3D12_FORMAT_SUPPORT1_BLENDABLE) ? 1 : 0;
    }
    for (unsigned j = 0; j < 131; j += 1) {
      if        (j == RED_FORMAT_R_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_8_UINT) {
      } else if (j == RED_FORMAT_R_8_SINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_UINT) {
      } else if (j == RED_FORMAT_RGBA_8_8_8_8_SINT) {
      } else if (j == RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_R_16_UINT) {
      } else if (j == RED_FORMAT_R_16_SINT) {
      } else if (j == RED_FORMAT_R_16_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_UINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_SINT) {
      } else if (j == RED_FORMAT_RGBA_16_16_16_16_FLOAT) {
      } else if (j == RED_FORMAT_R_32_UINT) {
      } else if (j == RED_FORMAT_R_32_SINT) {
      } else if (j == RED_FORMAT_R_32_FLOAT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_UINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_SINT) {
      } else if (j == RED_FORMAT_RGBA_32_32_32_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT) {
      } else if (j == RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT) {
      } else if (j == RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT) {
      } else {
        continue;
      }
      const unsigned d3d12j = redInternalREDGPUFormatIndexToD3D12FormatIndex(j);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsGpuCodeSampleCmpAndSampleCmpLevelZero        = ((features.Support1 & D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE_COMPARISON)                     == D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE_COMPARISON)                     ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsMip                                          = ((features.Support1 & D3D12_FORMAT_SUPPORT1_MIP)                                          == D3D12_FORMAT_SUPPORT1_MIP)                                          ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsResolveTarget                                = ((features.Support1 & D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RESOLVE)                          == D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RESOLVE)                          ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsResolveSource                                = ((features.Support1 & D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RENDERTARGET)                     == D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RENDERTARGET)                     ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsGpuCodeMultisampleLoad                       = ((features.Support1 & D3D12_FORMAT_SUPPORT1_MULTISAMPLE_LOAD)                             == D3D12_FORMAT_SUPPORT1_MULTISAMPLE_LOAD)                             ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsGpuCodeGather                                = ((features.Support1 & D3D12_FORMAT_SUPPORT1_SHADER_GATHER)                                == D3D12_FORMAT_SUPPORT1_SHADER_GATHER)                                ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsGpuCodeGatherComparison                      = ((features.Support1 & D3D12_FORMAT_SUPPORT1_SHADER_GATHER_COMPARISON)                     == D3D12_FORMAT_SUPPORT1_SHADER_GATHER_COMPARISON)                     ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsTextureRWAtomicAdd                           = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_ADD)                               == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_ADD)                               ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsTextureRWAtomicBitwiseOps                    = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS)                       == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS)                       ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsTextureRWAtomicCompareStoreOrCompareExchange = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE) == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE) ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsTextureRWAtomicExchange                      = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE)                          == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE)                          ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsTextureRWAtomicMinOrMaxSigned                = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX)                 == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX)                 ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsTextureRWAtomicMinOrMaxUnsigned              = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX)               == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX)               ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsTextureRWTypedLoad                           = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_TYPED_LOAD)                               == D3D12_FORMAT_SUPPORT2_UAV_TYPED_LOAD)                               ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsTextureRWTypedStore                          = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_TYPED_STORE)                              == D3D12_FORMAT_SUPPORT2_UAV_TYPED_STORE)                              ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1[j].supportsProcedureStateBlendLogicOp                   = ((features.Support2 & D3D12_FORMAT_SUPPORT2_OUTPUT_MERGER_LOGIC_OP)                       == D3D12_FORMAT_SUPPORT2_OUTPUT_MERGER_LOGIC_OP)                       ? 1 : 0;
    }
    for (unsigned j = 0; j < 14; j += 1) {
      const unsigned d3d12j = redInternalREDGPUXFormatIndexToD3D12FormatIndex(j + 12000);
      if (ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j].hresult < 0) {
        continue;
      }
      const RED_INTERNAL_D3D12_FEATURE_DATA_FORMAT_SUPPORT features = ctx->internal.adaptersImageD3D12FormatsFeatures[i].imageD3D12FormatsFeatures[d3d12j];
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsGpuCodeSampleCmpAndSampleCmpLevelZero        = ((features.Support1 & D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE_COMPARISON)                     == D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE_COMPARISON)                     ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsMip                                          = ((features.Support1 & D3D12_FORMAT_SUPPORT1_MIP)                                          == D3D12_FORMAT_SUPPORT1_MIP)                                          ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsResolveTarget                                = ((features.Support1 & D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RESOLVE)                          == D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RESOLVE)                          ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsResolveSource                                = ((features.Support1 & D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RENDERTARGET)                     == D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RENDERTARGET)                     ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsGpuCodeMultisampleLoad                       = ((features.Support1 & D3D12_FORMAT_SUPPORT1_MULTISAMPLE_LOAD)                             == D3D12_FORMAT_SUPPORT1_MULTISAMPLE_LOAD)                             ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsGpuCodeGather                                = ((features.Support1 & D3D12_FORMAT_SUPPORT1_SHADER_GATHER)                                == D3D12_FORMAT_SUPPORT1_SHADER_GATHER)                                ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsGpuCodeGatherComparison                      = ((features.Support1 & D3D12_FORMAT_SUPPORT1_SHADER_GATHER_COMPARISON)                     == D3D12_FORMAT_SUPPORT1_SHADER_GATHER_COMPARISON)                     ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsTextureRWAtomicAdd                           = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_ADD)                               == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_ADD)                               ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsTextureRWAtomicBitwiseOps                    = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS)                       == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS)                       ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsTextureRWAtomicCompareStoreOrCompareExchange = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE) == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE) ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsTextureRWAtomicExchange                      = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE)                          == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE)                          ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsTextureRWAtomicMinOrMaxSigned                = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX)                 == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX)                 ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsTextureRWAtomicMinOrMaxUnsigned              = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX)               == D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX)               ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsTextureRWTypedLoad                           = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_TYPED_LOAD)                               == D3D12_FORMAT_SUPPORT2_UAV_TYPED_LOAD)                               ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsTextureRWTypedStore                          = ((features.Support2 & D3D12_FORMAT_SUPPORT2_UAV_TYPED_STORE)                              == D3D12_FORMAT_SUPPORT2_UAV_TYPED_STORE)                              ? 1 : 0;
      ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1[j].supportsProcedureStateBlendLogicOp                   = ((features.Support2 & D3D12_FORMAT_SUPPORT2_OUTPUT_MERGER_LOGIC_OP)                       == D3D12_FORMAT_SUPPORT2_OUTPUT_MERGER_LOGIC_OP)                       ? 1 : 0;
    }
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }

    void * optionalInfoNext = 0;

    if (ctx->internal.requestedExtensions[RED_SDK_EXTENSION_ARRAY_TIMESTAMP] == 1) {
      ctx->internal.adaptersGpuInfoOptionalInfoArrayTimestamp[i].optionalInfo = RED_GPU_INFO_OPTIONAL_INFO_ARRAY_TIMESTAMP;
      ctx->internal.adaptersGpuInfoOptionalInfoArrayTimestamp[i].next = optionalInfoNext;
      ctx->internal.adaptersGpuInfoOptionalInfoArrayTimestamp[i].supportsArrayTimestamp = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoArrayTimestamp[i].queuesPrecisionBits64BitTicksCount = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoArrayTimestamp[i].nanosecondsPerTick = 0;
      optionalInfoNext = &ctx->internal.adaptersGpuInfoOptionalInfoArrayTimestamp[i];
    }

    if (ctx->internal.requestedExtensions[RED_SDK_EXTENSION_COMPUTING_LANGUAGE_FEATURE_LEVEL_1] == 1) {
      ctx->internal.adaptersGpuInfoOptionalInfoComputingLanguageFeatureLevel1[i].optionalInfo = RED_GPU_INFO_OPTIONAL_INFO_COMPUTING_LANGUAGE_FEATURE_LEVEL_1;
      ctx->internal.adaptersGpuInfoOptionalInfoComputingLanguageFeatureLevel1[i].next = optionalInfoNext;
      ctx->internal.adaptersGpuInfoOptionalInfoComputingLanguageFeatureLevel1[i].supportsComputingLanguageFeatureLevel1 = 0;
      optionalInfoNext = &ctx->internal.adaptersGpuInfoOptionalInfoComputingLanguageFeatureLevel1[i];
    }

    if (ctx->internal.requestedExtensions[RED_SDK_EXTENSION_RAY_TRACING] == 1) {
      ctx->internal.adaptersGpuInfoOptionalInfoRayTracing[i].optionalInfo = RED_GPU_INFO_OPTIONAL_INFO_RAY_TRACING;
      ctx->internal.adaptersGpuInfoOptionalInfoRayTracing[i].next = optionalInfoNext;
      ctx->internal.adaptersGpuInfoOptionalInfoRayTracing[i].supportsRayTracing = 0;
      optionalInfoNext = &ctx->internal.adaptersGpuInfoOptionalInfoRayTracing[i];
    }

    if (ctx->internal.requestedExtensions[RED_SDK_EXTENSION_DRIVER_PROPERTIES] == 1) {
      ctx->internal.adaptersGpuInfoOptionalInfoDriverProperties[i].optionalInfo = RED_GPU_INFO_OPTIONAL_INFO_DRIVER_PROPERTIES;
      ctx->internal.adaptersGpuInfoOptionalInfoDriverProperties[i].next = optionalInfoNext;
      ctx->internal.adaptersGpuInfoOptionalInfoDriverProperties[i].id = (RedDriverId)0;
      for (unsigned j = 0; j < 256; j += 1) {
        ctx->internal.adaptersGpuInfoOptionalInfoDriverProperties[i].name[j] = 0;
      }
      for (unsigned j = 0; j < 256; j += 1) {
        ctx->internal.adaptersGpuInfoOptionalInfoDriverProperties[i].info[j] = 0;
      }
      ctx->internal.adaptersGpuInfoOptionalInfoDriverProperties[i].compliantWithConformanceTestSuiteVersionMajor = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoDriverProperties[i].compliantWithConformanceTestSuiteVersionMinor = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoDriverProperties[i].compliantWithConformanceTestSuiteVersionSubminor = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoDriverProperties[i].compliantWithConformanceTestSuiteVersionPatch = 0;
      optionalInfoNext = &ctx->internal.adaptersGpuInfoOptionalInfoDriverProperties[i];
    }

    if (ctx->internal.requestedExtensions[RED_SDK_EXTENSION_RESOLVE_DEPTH_STENCIL] == 1) {
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].optionalInfo = RED_GPU_INFO_OPTIONAL_INFO_RESOLVE_DEPTH_STENCIL;
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].next = optionalInfoNext;
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].supportsResolveDepthStencil = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].supportsResolveModeDepthSampleIndexZero = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].supportsResolveModeDepthAverage = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].supportsResolveModeDepthMin = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].supportsResolveModeDepthMax = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].supportsResolveModeStencilSampleIndexZero = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].supportsResolveModeStencilAverage = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].supportsResolveModeStencilMin = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].supportsResolveModeStencilMax = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].supportsResolveIndependentNone = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i].supportsResolveIndependent = 0;
      optionalInfoNext = &ctx->internal.adaptersGpuInfoOptionalInfoResolveDepthStencil[i];
    }

    if (ctx->internal.requestedExtensions[RED_SDK_EXTENSION_PROCEDURE_PARAMETERS_HANDLES] == 1) {
      ctx->internal.adaptersGpuInfoOptionalInfoProcedureParametersHandles[i].optionalInfo = RED_GPU_INFO_OPTIONAL_INFO_PROCEDURE_PARAMETERS_HANDLES;
      ctx->internal.adaptersGpuInfoOptionalInfoProcedureParametersHandles[i].next = optionalInfoNext;
      ctx->internal.adaptersGpuInfoOptionalInfoProcedureParametersHandles[i].supportsProcedureParametersHandles = 1;
      ctx->internal.adaptersGpuInfoOptionalInfoProcedureParametersHandles[i].maxProcedureParametersHandlesCount = 8;
      optionalInfoNext = &ctx->internal.adaptersGpuInfoOptionalInfoProcedureParametersHandles[i];
    }

    if (ctx->internal.requestedExtensions[RED_SDK_EXTENSION_RASTERIZATION_MODE] == 1) {
      ctx->internal.adaptersGpuInfoOptionalInfoRasterizationMode[i].optionalInfo = RED_GPU_INFO_OPTIONAL_INFO_RASTERIZATION_MODE;
      ctx->internal.adaptersGpuInfoOptionalInfoRasterizationMode[i].next = optionalInfoNext;
      ctx->internal.adaptersGpuInfoOptionalInfoRasterizationMode[i].supportsRasterizationModeOverestimate = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoRasterizationMode[i].supportsRasterizationModeUnderestimate = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoRasterizationMode[i].supportsGuaranteedZeroAreaBackFacingTriangles = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoRasterizationMode[i].supportsGpuCodeFullyCoveredEXT = 0;
      optionalInfoNext = &ctx->internal.adaptersGpuInfoOptionalInfoRasterizationMode[i];
    }

    if (ctx->internal.requestedExtensions[RED_SDK_EXTENSION_FORMAL_MEMORY_MODEL] == 1) {
      ctx->internal.adaptersGpuInfoOptionalInfoFormalMemoryModel[i].optionalInfo = RED_GPU_INFO_OPTIONAL_INFO_FORMAL_MEMORY_MODEL;
      ctx->internal.adaptersGpuInfoOptionalInfoFormalMemoryModel[i].next = optionalInfoNext;
      ctx->internal.adaptersGpuInfoOptionalInfoFormalMemoryModel[i].supportsFormalMemoryModel = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoFormalMemoryModel[i].supportsFormalMemoryModelGpuScopeSynchronization = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoFormalMemoryModel[i].supportsFormalMemoryModelAvailabilityAndVisibilityChains = 0;
      optionalInfoNext = &ctx->internal.adaptersGpuInfoOptionalInfoFormalMemoryModel[i];
    }

    if (ctx->internal.requestedExtensions[RED_SDK_EXTENSION_ADDITIONAL_INFO_0] == 1) {
      ctx->internal.adaptersGpuInfoOptionalInfoAdditionalInfo0[i].optionalInfo = RED_GPU_INFO_OPTIONAL_INFO_ADDITIONAL_INFO_0;
      ctx->internal.adaptersGpuInfoOptionalInfoAdditionalInfo0[i].next = optionalInfoNext;
      ctx->internal.adaptersGpuInfoOptionalInfoAdditionalInfo0[i].supportsArraysImagesUsageBeforeMemorySet = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoAdditionalInfo0[i].supportsInitialQueueFamilyIndexSetToMaxValueForSimultaneousQueueAccessOfArrays = 1;
      ctx->internal.adaptersGpuInfoOptionalInfoAdditionalInfo0[i].supportsInitialQueueFamilyIndexSetToMaxValueForSimultaneousQueueAccessOfImages = 1;
      ctx->internal.adaptersGpuInfoOptionalInfoAdditionalInfo0[i].supportsInitialQueueFamilyIndexSetToMaxValueForSimultaneousQueueAccessOfImagesMultisample = 0;
      ctx->internal.adaptersGpuInfoOptionalInfoAdditionalInfo0[i].supportsInitialQueueFamilyIndexSetToMaxValueForSimultaneousQueueAccessOfImagesDepthStencil = 0;
      optionalInfoNext = &ctx->internal.adaptersGpuInfoOptionalInfoAdditionalInfo0[i];
    }

    ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures[i].optionalInfo                                                                = RED_GPU_INFO_OPTIONAL_INFO_IMAGE_X_FORMATS_LIMITS_AND_FEATURES;
    ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures[i].next                                                                        = optionalInfoNext;
    ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures[i].imageXFormatsLimitsImageDimensions1D                                        = ctx->internal.adaptersImageXFormatsLimitsImageDimensions1D[i].imageXFormatsLimits;
    ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures[i].imageXFormatsLimitsImageDimensions2D                                        = ctx->internal.adaptersImageXFormatsLimitsImageDimensions2D[i].imageXFormatsLimits;
    ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures[i].imageXFormatsLimitsImageDimensions2DMultisample                             = ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DMultisample[i].imageXFormatsLimits;
    ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures[i].imageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered = ctx->internal.adaptersImageXFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered[i].imageXFormatsLimits;
    ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures[i].imageXFormatsLimitsImageDimensions3D                                        = ctx->internal.adaptersImageXFormatsLimitsImageDimensions3D[i].imageXFormatsLimits;
    ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures[i].imageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered     = ctx->internal.adaptersImageXFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered[i].imageXFormatsLimits;
    ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures[i].imageXFormatsFeatures                                                       = ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures;
    ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures[i].imageFormatsFeatures1                                                       = ctx->internal.adaptersImageXFormatsFeatures[i].imageFormatsFeatures1;
    ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures[i].imageXFormatsFeatures1                                                      = ctx->internal.adaptersImageXFormatsFeatures[i].imageXFormatsFeatures1;
    optionalInfoNext = &ctx->internal.adaptersOptionalInfoImageXFormatsLimitsAndFeatures[i];

    ctx->gpus[i].optionalInfo = optionalInfoNext;
  }

  for (unsigned i = 0; i < ctx->gpusCount; i += 1) {
    if (ctx->gpusStatuses[i].statusError != RED_STATUS_SUCCESS) {
      continue;
    }
    ctx->internal.adaptersDescriptorHandleIncrementSizesCBVSRVUAV[i] = x12DeviceGetDescriptorHandleIncrementSize((ID3D12Device3 *)ctx->gpus[i].gpu, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, optionalFile, optionalLine);
    ctx->internal.adaptersDescriptorHandleIncrementSizesSampler[i]   = x12DeviceGetDescriptorHandleIncrementSize((ID3D12Device3 *)ctx->gpus[i].gpu, D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER,     optionalFile, optionalLine);
  }

  ctx->internal.memoryAllocateZeroed = d3dMemoryAllocateZeroed;

  outContext[0] = (RedContext)ctx;

  PIXEndEvent();
}

__declspec(dllexport) void redDestroyContext(RedContext context, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyContext;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyContext(context, 1, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redMemoryGetBudget(RedContext context, RedHandleGpu gpu, RedMemoryBudget * outMemoryBudget, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redMemoryGetBudget;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    PIXEndEvent();
    return;
  }

  if (ctx->gpus[gpuIndex].gpuType == RED_GPU_TYPE_DISCRETE) {
    DXGI_QUERY_VIDEO_MEMORY_INFO l1info = {};
    DXGI_QUERY_VIDEO_MEMORY_INFO l0info = {};
    x12AdapterQueryVideoMemoryInfo((IDXGIAdapter3 *)ctx->gpus[gpuIndex].gpuDevice, 0, DXGI_MEMORY_SEGMENT_GROUP_LOCAL,     &l1info, optionalFile, optionalLine);
    x12AdapterQueryVideoMemoryInfo((IDXGIAdapter3 *)ctx->gpus[gpuIndex].gpuDevice, 0, DXGI_MEMORY_SEGMENT_GROUP_NON_LOCAL, &l0info, optionalFile, optionalLine);
    outMemoryBudget[0].memoryHeapsBudget[0] = l1info.Budget;
    outMemoryBudget[0].memoryHeapsUsage[0]  = l1info.CurrentUsage;
    outMemoryBudget[0].memoryHeapsBudget[1] = l0info.Budget;
    outMemoryBudget[0].memoryHeapsUsage[1]  = l0info.CurrentUsage;
  } else {
    DXGI_QUERY_VIDEO_MEMORY_INFO l0info = {};
    x12AdapterQueryVideoMemoryInfo((IDXGIAdapter3 *)ctx->gpus[gpuIndex].gpuDevice, 0, DXGI_MEMORY_SEGMENT_GROUP_LOCAL,     &l0info, optionalFile, optionalLine);
    outMemoryBudget[0].memoryHeapsBudget[0] = l0info.Budget;
    outMemoryBudget[0].memoryHeapsUsage[0]  = l0info.CurrentUsage;
  }

  PIXEndEvent();
}

__declspec(dllexport) void redXMemoryCallbackBudgetChangeRegister(RedContext context, RedHandleGpu gpu, void * eventHandle, RedXHandleMemoryCallbackBudgetChange * outMemoryCallbackBudgetChange, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXMemoryCallbackBudgetChangeRegister;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  DWORD                     h   = 0;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, (RedProcedureId)procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outMemoryCallbackBudgetChange[0] = 0;
    PIXEndEvent();
    return;
  }

  x12AdapterRegisterVideoMemoryBudgetChangeNotificationEvent((IDXGIAdapter3 *)ctx->gpus[gpuIndex].gpuDevice, eventHandle, &h, optionalFile, optionalLine);

  outMemoryCallbackBudgetChange[0] = (RedXHandleMemoryCallbackBudgetChange)(uint64_t)h;

  PIXEndEvent();
}

__declspec(dllexport) void redXMemoryCallbackBudgetChangeUnregister(RedContext context, RedHandleGpu gpu, RedXHandleMemoryCallbackBudgetChange memoryCallbackBudgetChange, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXMemoryCallbackBudgetChangeUnregister;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, 0, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, (RedProcedureId)procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    PIXEndEvent();
    return;
  }

  x12AdapterUnregisterVideoMemoryBudgetChangeNotification((IDXGIAdapter3 *)ctx->gpus[gpuIndex].gpuDevice, (DWORD)(uint64_t)memoryCallbackBudgetChange, optionalFile, optionalLine);

  PIXEndEvent();
}

__declspec(dllexport) void redXMemoryReserve(RedContext context, RedHandleGpu gpu, RedBool32 sharedMemory, uint64_t bytesCount, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXMemoryReserve;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, (RedProcedureId)procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    PIXEndEvent();
    return;
  }

  x12AdapterSetVideoMemoryReservation((IDXGIAdapter3 *)ctx->gpus[gpuIndex].gpuDevice, 0, (DXGI_MEMORY_SEGMENT_GROUP)sharedMemory, bytesCount, optionalFile, optionalLine);

  PIXEndEvent();
}

static void redInternalMemoryAllocate(RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t bytesCount, unsigned memoryTypeIndex, RedBool32 mapMemory, RedHandleArray mapMemoryArray, RedHandleArray dedicateToArray, RedHandleImage dedicateToImage, RedXMemoryBitflags optionalMemoryBitflags, RedHandleMemory * outMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, const RedProcedureId procedureId) {
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeMemory *  ih  = 0;

  const unsigned memoryType0OnlyBuffers          = 0;
  const unsigned memoryType1OnlyTextures         = 1;
  const unsigned memoryType2OnlyRtDsTextures     = 2;
  const unsigned memoryType3OnlyRtDsTexturesMsaa = 3;
  const unsigned memoryType4Upload               = 4;
  const unsigned memoryType5Readback             = 5;

  D3D12_HEAP_PROPERTIES props = {};
  D3D12_HEAP_FLAGS      flags = D3D12_HEAP_FLAG_NONE;
  D3D12_RESOURCE_DESC   rdesc = {};

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outMemory[0] = 0;
    return;
  }

  if (dedicateToArray != 0 && dedicateToImage != 0) {
    redInternalSetStatus(ctx, gpu, outStatuses, 1, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
    outMemory[0] = 0;
    return;
  }

  ih = redInternalTypeMemoryAllocate(ctx, gpuIndex, handleName, bytesCount, memoryTypeIndex, mapMemory, dedicateToArray, dedicateToImage, outStatuses, procedureId, 2, optionalFile, optionalLine);
  if (ih == 0) {
    outMemory[0] = 0;
    return;
  }

  props.Type                 = redInternalREDGPUMemoryTypeIndexToD3D12HeapType(ctx, gpuIndex, memoryTypeIndex);
  props.CPUPageProperty      = redInternalREDGPUMemoryTypeIndexToD3D12CpuPageProperty(ctx, gpuIndex, memoryTypeIndex);
  props.MemoryPoolPreference = redInternalREDGPUMemoryTypeIndexToD3D12MemoryPool(ctx, gpuIndex, memoryTypeIndex);
  props.CreationNodeMask     = 0;
  props.VisibleNodeMask      = 0;

  flags = (dedicateToArray != 0 || dedicateToImage != 0) ? D3D12_HEAP_FLAG_NONE : redInternalREDGPUMemoryTypeIndexToD3D12HeapFlags(ctx, gpuIndex, memoryTypeIndex);
  if (ctx->internal.memoryAllocateZeroed == 0) {
    flags |= D3D12_HEAP_FLAG_CREATE_NOT_ZEROED;
  }
  if (optionalMemoryBitflags != 0) {
    if ((optionalMemoryBitflags & RED_MEMORY_BITFLAG_ALLOW_ATOMICS) == RED_MEMORY_BITFLAG_ALLOW_ATOMICS) {
      flags |= D3D12_HEAP_FLAG_ALLOW_SHADER_ATOMICS;
    }
    if ((optionalMemoryBitflags & REDX_MEMORY_BITFLAG_NOT_RESIDENT) == REDX_MEMORY_BITFLAG_NOT_RESIDENT) {
      flags |= D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT;
    }
  }

  if (dedicateToArray != 0) {
    RedXInternalTypeArray * iharray = (RedXInternalTypeArray *)dedicateToArray;

    rdesc = iharray->resourceDescription;
    D3D12_RESOURCE_STATES initstates = redInternalREDGPUInitialD3D12ResourceStates(memoryTypeIndex);
    if (iharray->type == REDX_ARRAY_TYPE_RAYTRACING_ACCELERATION_STRUCTURE) {
      initstates = D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE;
    }
    if (mapMemory == 0) {
      if (iharray->initialAccess != 0) {
        initstates = redInternalREDGPUAccessBitflagsToD3D12ResourceStates(iharray->initialAccess);
        if (iharray->type == REDX_ARRAY_TYPE_RAYTRACING_ACCELERATION_STRUCTURE) {
          initstates = D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE;
        }
      }
    }
    D3D12_CLEAR_VALUE * nil = 0;
    HRESULT hr = x12DeviceCreateCommittedResource((ID3D12Device3 *)gpu, &props, flags, &rdesc, initstates, nil, &ih->resource, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyMemory((RedHandleMemory)ih, optionalFile, optionalLine);
      ih = 0;
      outMemory[0] = 0;
      return;
    }

    if (ctx->internal.debugCallback != 0 && handleName != 0) {
      if (ih->resource != 0) {
        std::string  HandleNameA = handleName;
        std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
        x12ObjectSetName((ID3D12Object *)ih->resource, &handleNameW[0], optionalFile, optionalLine);
      }
    }

    ih->kind = REDX_INTERNAL_TYPE_MEMORY_KIND_DEDICATED;

  } else if (dedicateToImage != 0) {
    RedXInternalTypeImage * ihimage = (RedXInternalTypeImage *)dedicateToImage;

    rdesc = ihimage->resourceDescription;
    D3D12_RESOURCE_STATES initstates = redInternalREDGPUInitialD3D12ResourceStates(memoryTypeIndex);
    if (ihimage->initialAccess != 0) {
      initstates = redInternalREDGPUAccessBitflagsToD3D12ResourceStates(ihimage->initialAccess);
    }
    D3D12_CLEAR_VALUE * nil = 0;
    HRESULT hr = x12DeviceCreateCommittedResource((ID3D12Device3 *)gpu, &props, flags, &rdesc, initstates, nil, &ih->resource, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyMemory((RedHandleMemory)ih, optionalFile, optionalLine);
      ih = 0;
      outMemory[0] = 0;
      return;
    }

    if (ctx->internal.debugCallback != 0 && handleName != 0) {
      if (ih->resource != 0) {
        std::string  HandleNameA = handleName;
        std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
        x12ObjectSetName((ID3D12Object *)ih->resource, &handleNameW[0], optionalFile, optionalLine);
      }
    }

    ih->kind = REDX_INTERNAL_TYPE_MEMORY_KIND_DEDICATED;

  } else {
    uint64_t alignment = D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT;
    if (memoryTypeIndex == memoryType3OnlyRtDsTexturesMsaa) {
      alignment = D3D12_DEFAULT_MSAA_RESOURCE_PLACEMENT_ALIGNMENT;
    }

    D3D12_HEAP_DESC desc = {};
    desc.SizeInBytes = bytesCount;
    desc.Properties  = props;
    desc.Alignment   = alignment;
    desc.Flags       = flags;
    HRESULT hr = x12DeviceCreateHeap((ID3D12Device3 *)gpu, &desc, &ih->handle, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyMemory((RedHandleMemory)ih, optionalFile, optionalLine);
      ih = 0;
      outMemory[0] = 0;
      return;
    }

    if (ctx->internal.debugCallback != 0 && handleName != 0) {
      if (ih->handle != 0) {
        std::string  HandleNameA = handleName;
        std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
        x12ObjectSetName((ID3D12Object *)ih->handle, &handleNameW[0], optionalFile, optionalLine);
      }
    }

    if (mapMemory == 1) {
      RedXInternalTypeArray * iharray = (RedXInternalTypeArray *)mapMemoryArray;
      D3D12_RESOURCE_STATES initstates = redInternalREDGPUInitialD3D12ResourceStates(memoryTypeIndex);
      hr = x12DeviceCreatePlacedResource((ID3D12Device3 *)gpu, ih->handle, 0, &iharray->resourceDescription, initstates, 0, &ih->resource, optionalFile, optionalLine);
      if (hr < 0) {
        redInternalDestroyMemory((RedHandleMemory)ih, optionalFile, optionalLine);
        ih = 0;
        outMemory[0] = 0;
        return;
      }

      if (ctx->internal.debugCallback != 0 && handleName != 0) {
        if (ih->resource != 0) {
          std::string  HandleNameA = handleName;
          std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
          x12ObjectSetName((ID3D12Object *)ih->resource, &handleNameW[0], optionalFile, optionalLine);
        }
      }
    }

    ih->kind = REDX_INTERNAL_TYPE_MEMORY_KIND_PLACED;
  }

  outMemory[0] = (RedHandleMemory)ih;
}

__declspec(dllexport) void redMemoryAllocate(RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t bytesCount, unsigned memoryTypeIndex, RedHandleArray dedicateToArray, RedHandleImage dedicateToImage, unsigned memoryBitflags, RedHandleMemory * outMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redMemoryAllocate;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalMemoryAllocate(context, gpu, handleName, bytesCount, memoryTypeIndex, 0, 0, dedicateToArray, dedicateToImage, memoryBitflags, outMemory, outStatuses, optionalFile, optionalLine, procedureId);
  PIXEndEvent();
}

__declspec(dllexport) void redMemoryAllocateMappable(RedContext context, RedHandleGpu gpu, const char * handleName, RedBool32 dedicate, RedHandleArray array, uint64_t arrayMemoryBytesCount, unsigned memoryTypeIndex, unsigned memoryBitflags, RedHandleMemory * outMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redMemoryAllocateMappable;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalMemoryAllocate(context, gpu, handleName, arrayMemoryBytesCount, memoryTypeIndex, 1, array, dedicate == 1 ? array : 0, 0, memoryBitflags, outMemory, outStatuses, optionalFile, optionalLine, procedureId);
  PIXEndEvent();
}

__declspec(dllexport) void redMemoryFree(RedContext context, RedHandleGpu gpu, RedHandleMemory memory, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redMemoryFree;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyMemory(memory, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redMemorySet(RedContext context, RedHandleGpu gpu, unsigned memoryArraysCount, const RedMemoryArray * memoryArrays, unsigned memoryImagesCount, const RedMemoryImage * memoryImages, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redMemorySet;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;

  const unsigned memoryType0OnlyBuffers          = 0;
  const unsigned memoryType1OnlyTextures         = 1;
  const unsigned memoryType2OnlyRtDsTextures     = 2;
  const unsigned memoryType3OnlyRtDsTexturesMsaa = 3;
  const unsigned memoryType4Upload               = 4;
  const unsigned memoryType5Readback             = 5;

  for (unsigned i = 0; i < memoryArraysCount; i += 1) {
    const RedMemoryArray set = memoryArrays[i];
    RedXInternalTypeArray *  iharray  = (RedXInternalTypeArray *)set.array;
    RedXInternalTypeMemory * ihmemory = (RedXInternalTypeMemory *)set.memory;

    HRESULT hr = S_OK;

    if (ihmemory->kind == REDX_INTERNAL_TYPE_MEMORY_KIND_DEDICATED) {
      iharray->handle        = ihmemory->resource;
      iharray->destroyHandle = 0;
    } else if (ihmemory->kind == REDX_INTERNAL_TYPE_MEMORY_KIND_PLACED) {
      if (ihmemory->memoryTypeIndex == memoryType4Upload || ihmemory->memoryTypeIndex == memoryType5Readback) {
        iharray->handle                 = ihmemory->resource;
        iharray->destroyHandle          = 0;
        iharray->mappedMemoryBytesFirst = set.memoryBytesFirst;
      } else {
        D3D12_RESOURCE_DESC desc = iharray->resourceDescription;
        D3D12_RESOURCE_STATES initstates = redInternalREDGPUInitialD3D12ResourceStates(ihmemory->memoryTypeIndex);
        if (iharray->type == REDX_ARRAY_TYPE_RAYTRACING_ACCELERATION_STRUCTURE) {
          initstates = D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE;
        }
        if (iharray->initialAccess != 0) {
          initstates = redInternalREDGPUAccessBitflagsToD3D12ResourceStates(iharray->initialAccess);
          if (iharray->type == REDX_ARRAY_TYPE_RAYTRACING_ACCELERATION_STRUCTURE) {
            initstates = D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE;
          }
        }
        hr = x12DeviceCreatePlacedResource((ID3D12Device3 *)gpu, ihmemory->handle, set.memoryBytesFirst, &desc, initstates, 0, &iharray->handle, optionalFile, optionalLine);
      }
    } else {
      redInternalSetStatus(ctx, gpu, outStatuses, 1, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
      continue;
    }

    RedXInternalTypeCpuDescriptorCBVSRVUAV cpuDescriptor = {};
    if (hr >= 0) {
      if (iharray->type != RED_ARRAY_TYPE_INDEX_RO) {
        D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
        descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
        descriptorHeapDesc.NumDescriptors = 1;
        descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        descriptorHeapDesc.NodeMask       = 0;
        hr = x12DeviceCreateDescriptorHeap((ID3D12Device3 *)gpu, &descriptorHeapDesc, &cpuDescriptor.cpuDescriptorHeapCBVSRVUAV, optionalFile, optionalLine);
        if (hr >= 0) {
          if (ctx->internal.debugCallback != 0 && iharray->handleName.empty() == false) {
            if (cpuDescriptor.cpuDescriptorHeapCBVSRVUAV != 0) {
              std::wstring handleNameW(iharray->handleName.begin(), iharray->handleName.end());
              x12ObjectSetName((ID3D12Object *)cpuDescriptor.cpuDescriptorHeapCBVSRVUAV, &handleNameW[0], optionalFile, optionalLine);
            }
          }
          x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(cpuDescriptor.cpuDescriptorHeapCBVSRVUAV, &cpuDescriptor.cpuDescriptorCBVSRVUAV);
          if (iharray->type == RED_ARRAY_TYPE_ARRAY_RO_CONSTANT) {
            D3D12_CONSTANT_BUFFER_VIEW_DESC cbvDesc = {};
            cbvDesc.BufferLocation = x12ResourceGetGPUVirtualAddress(iharray->handle);
            cbvDesc.SizeInBytes    = (unsigned)iharray->bytesCount;
            x12DeviceCreateConstantBufferView((ID3D12Device3 *)gpu, &cbvDesc, cpuDescriptor.cpuDescriptorCBVSRVUAV, optionalFile, optionalLine);
          } else if (iharray->type == REDX_ARRAY_TYPE_RAYTRACING_ACCELERATION_STRUCTURE) {
            D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
            srvDesc.Format                                   = DXGI_FORMAT_UNKNOWN;
            srvDesc.ViewDimension                            = D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE;
            srvDesc.Shader4ComponentMapping                  = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
            srvDesc.RaytracingAccelerationStructure.Location = x12ResourceGetGPUVirtualAddress(iharray->handle);
            x12DeviceCreateShaderResourceView((ID3D12Device3 *)gpu, 0, &srvDesc, cpuDescriptor.cpuDescriptorCBVSRVUAV, optionalFile, optionalLine);
          } else if (iharray->type == RED_ARRAY_TYPE_ARRAY_RO || iharray->type == RED_ARRAY_TYPE_ARRAY_RW) {
            if (iharray->structuredBufferElementBytesCount == 0) {
              if (iharray->type == RED_ARRAY_TYPE_ARRAY_RO) {
                D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
                srvDesc.Format                     = DXGI_FORMAT_R32_TYPELESS;
                srvDesc.ViewDimension              = D3D12_SRV_DIMENSION_BUFFER;
                srvDesc.Shader4ComponentMapping    = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
                srvDesc.Buffer.FirstElement        = (unsigned)0;
                srvDesc.Buffer.NumElements         = (unsigned)(iharray->bytesCount / 4);
                srvDesc.Buffer.StructureByteStride = 0;
                srvDesc.Buffer.Flags               = D3D12_BUFFER_SRV_FLAG_RAW;
                x12DeviceCreateShaderResourceView((ID3D12Device3 *)gpu, iharray->handle, &srvDesc, cpuDescriptor.cpuDescriptorCBVSRVUAV, optionalFile, optionalLine);
              } else {
                D3D12_UNORDERED_ACCESS_VIEW_DESC uavDesc = {};
                uavDesc.Format                      = DXGI_FORMAT_R32_TYPELESS;
                uavDesc.ViewDimension               = D3D12_UAV_DIMENSION_BUFFER;
                uavDesc.Buffer.FirstElement         = (unsigned)0;
                uavDesc.Buffer.NumElements          = (unsigned)(iharray->bytesCount / 4);
                uavDesc.Buffer.StructureByteStride  = 0;
                uavDesc.Buffer.CounterOffsetInBytes = 0;
                uavDesc.Buffer.Flags                = D3D12_BUFFER_UAV_FLAG_RAW;
                x12DeviceCreateUnorderedAccessView((ID3D12Device3 *)gpu, iharray->handle, 0, &uavDesc, cpuDescriptor.cpuDescriptorCBVSRVUAV, optionalFile, optionalLine);
              }
            } else {
              if (iharray->type == RED_ARRAY_TYPE_ARRAY_RO) {
                D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
                srvDesc.Format                     = DXGI_FORMAT_UNKNOWN;
                srvDesc.ViewDimension              = D3D12_SRV_DIMENSION_BUFFER;
                srvDesc.Shader4ComponentMapping    = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
                srvDesc.Buffer.FirstElement        = (unsigned)0;
                srvDesc.Buffer.NumElements         = (unsigned)(iharray->bytesCount / iharray->structuredBufferElementBytesCount);
                srvDesc.Buffer.StructureByteStride = (unsigned)iharray->structuredBufferElementBytesCount;
                srvDesc.Buffer.Flags               = D3D12_BUFFER_SRV_FLAG_NONE;
                x12DeviceCreateShaderResourceView((ID3D12Device3 *)gpu, iharray->handle, &srvDesc, cpuDescriptor.cpuDescriptorCBVSRVUAV, optionalFile, optionalLine);
              } else {
                D3D12_UNORDERED_ACCESS_VIEW_DESC uavDesc = {};
                uavDesc.Format                      = DXGI_FORMAT_UNKNOWN;
                uavDesc.ViewDimension               = D3D12_UAV_DIMENSION_BUFFER;
                uavDesc.Buffer.FirstElement         = (unsigned)0;
                uavDesc.Buffer.NumElements          = (unsigned)(iharray->bytesCount / iharray->structuredBufferElementBytesCount);
                uavDesc.Buffer.StructureByteStride  = (unsigned)iharray->structuredBufferElementBytesCount;
                uavDesc.Buffer.CounterOffsetInBytes = 0;
                uavDesc.Buffer.Flags                = D3D12_BUFFER_UAV_FLAG_NONE;
                x12DeviceCreateUnorderedAccessView((ID3D12Device3 *)gpu, iharray->handle, 0, &uavDesc, cpuDescriptor.cpuDescriptorCBVSRVUAV, optionalFile, optionalLine);
              }
            }
          }
        }
      }
    }

    iharray->memoryKind      = ihmemory->kind;
    iharray->memoryTypeIndex = ihmemory->memoryTypeIndex;
    iharray->memoryArray     = set;
    iharray->cpuDescriptor   = cpuDescriptor;
  }

  for (unsigned i = 0; i < memoryImagesCount; i += 1) {
    const RedMemoryImage set = memoryImages[i];
    RedXInternalTypeImage *  ihimage  = (RedXInternalTypeImage *)set.image;
    RedXInternalTypeMemory * ihmemory = (RedXInternalTypeMemory *)set.memory;

    if (ihmemory->kind == REDX_INTERNAL_TYPE_MEMORY_KIND_DEDICATED) {
      ihimage->handle        = ihmemory->resource;
      ihimage->destroyHandle = 0;
    } else if (ihmemory->kind == REDX_INTERNAL_TYPE_MEMORY_KIND_PLACED) {
      D3D12_RESOURCE_DESC desc = ihimage->resourceDescription;
      D3D12_RESOURCE_STATES initstates = redInternalREDGPUInitialD3D12ResourceStates(ihmemory->memoryTypeIndex);
      if (ihimage->initialAccess != 0) {
        initstates = redInternalREDGPUAccessBitflagsToD3D12ResourceStates(ihimage->initialAccess);
      }
      D3D12_CLEAR_VALUE * nil = 0;
      x12DeviceCreatePlacedResource((ID3D12Device3 *)gpu, ihmemory->handle, set.memoryBytesFirst, &desc, initstates, nil, &ihimage->handle, optionalFile, optionalLine);
    } else {
      redInternalSetStatus(ctx, gpu, outStatuses, 10, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
      continue;
    }

    ihimage->memoryKind  = ihmemory->kind;
    ihimage->memoryImage = set;
  }

  PIXEndEvent();
}

__declspec(dllexport) void redMemoryMap(RedContext context, RedHandleGpu gpu, RedHandleMemory mappableMemory, uint64_t mappableMemoryBytesFirst, uint64_t mappableMemoryBytesCount, void ** outVolatilePointer, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redMemoryMap;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeMemory *  ih  = (RedXInternalTypeMemory *)mappableMemory;

  D3D12_RANGE range = {};
  range.Begin = mappableMemoryBytesFirst;
  range.End   = mappableMemoryBytesCount;
  x12ResourceMap(ih->resource, 0, &range, &ih->mappedPointer, optionalFile, optionalLine);
  ih->mappedPointerRangeBytesFirst = mappableMemoryBytesFirst;
  ih->mappedPointerRangeBytesCount = mappableMemoryBytesCount;

  outVolatilePointer[0] = ih->mappedPointer;

  PIXEndEvent();
}

__declspec(dllexport) void redMemoryUnmap(RedContext context, RedHandleGpu gpu, RedHandleMemory mappableMemory, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redMemoryUnmap;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeMemory *  ih  = (RedXInternalTypeMemory *)mappableMemory;

  D3D12_RANGE range = {};
  range.Begin = 0;
  range.End   = 0;
  x12ResourceUnmap(ih->resource, 0, &range, optionalFile, optionalLine);
  ih->mappedPointerRangeBytesFirst = 0;
  ih->mappedPointerRangeBytesCount = 0;
  ih->mappedPointer = 0;

  PIXEndEvent();
}

__declspec(dllexport) void redMemoryNonCoherentFlush(RedContext context, RedHandleGpu gpu, unsigned mappableMemoryRangesCount, const RedMappableMemoryRange * mappableMemoryRanges, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redMemoryNonCoherentFlush;
  volatile int x = 0;
}

__declspec(dllexport) void redMemoryNonCoherentInvalidate(RedContext context, RedHandleGpu gpu, unsigned mappableMemoryRangesCount, const RedMappableMemoryRange * mappableMemoryRanges, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redMemoryNonCoherentInvalidate;
  volatile int x = 0;
}

static void redInternalStructsMemoryAllocate(RedContext context, RedHandleGpu gpu, const char * handleName, RedBool32 createDescriptorHeapDescCBVSRVUAV, RedBool32 createDescriptorHeapDescSampler, unsigned maxStructsCount, unsigned maxStructsMembersOfTypeArrayROConstantCount, unsigned maxStructsMembersOfTypeArrayROOrArrayRWCount, unsigned maxStructsMembersOfTypeSamplerCount, unsigned maxStructsMembersOfTypeTextureROCount, unsigned maxStructsMembersOfTypeTextureRWCount, RedHandleStructsMemory * outStructsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData, const RedProcedureId procedureId) {
  RedXInternalTypeContext *       ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeStructsMemory * ih  = 0;

  D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDescCBVSRVUAV = {};
  D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDescSampler   = {};

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outStructsMemory[0] = 0;
    return;
  }

  ih = redInternalTypeStructsMemoryAllocate(ctx, gpuIndex, handleName, maxStructsCount, maxStructsMembersOfTypeArrayROConstantCount, maxStructsMembersOfTypeArrayROOrArrayRWCount, maxStructsMembersOfTypeSamplerCount, maxStructsMembersOfTypeTextureROCount, maxStructsMembersOfTypeTextureRWCount, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outStructsMemory[0] = 0;
    return;
  }

  if (createDescriptorHeapDescCBVSRVUAV == 1) {
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDescCBVSRVUAV = {};
    descriptorHeapDescCBVSRVUAV.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    descriptorHeapDescCBVSRVUAV.NumDescriptors = maxStructsMembersOfTypeArrayROConstantCount + maxStructsMembersOfTypeArrayROOrArrayRWCount + maxStructsMembersOfTypeTextureROCount + maxStructsMembersOfTypeTextureRWCount;
    descriptorHeapDescCBVSRVUAV.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
    descriptorHeapDescCBVSRVUAV.NodeMask       = 0;
    HRESULT hr = x12DeviceCreateDescriptorHeap((ID3D12Device3 *)gpu, &descriptorHeapDescCBVSRVUAV, &ih->handle, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyStructsMemory((RedHandleStructsMemory)ih, optionalFile, optionalLine);
      ih = 0;
      outStructsMemory[0] = 0;
      return;
    }
    if (ctx->internal.debugCallback != 0 && handleName != 0) {
      if (ih->handle != 0) {
        std::string  HandleNameA = handleName;
        std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
        x12ObjectSetName((ID3D12Object *)ih->handle, &handleNameW[0], optionalFile, optionalLine);
      }
    }
  } else if (createDescriptorHeapDescSampler == 1) {
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDescSampler = {};
    descriptorHeapDescSampler.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
    descriptorHeapDescSampler.NumDescriptors = maxStructsMembersOfTypeSamplerCount;
    descriptorHeapDescSampler.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
    descriptorHeapDescSampler.NodeMask       = 0;
    HRESULT hr = x12DeviceCreateDescriptorHeap((ID3D12Device3 *)gpu, &descriptorHeapDescSampler, &ih->handle, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyStructsMemory((RedHandleStructsMemory)ih, optionalFile, optionalLine);
      ih = 0;
      outStructsMemory[0] = 0;
      return;
    }
    if (ctx->internal.debugCallback != 0 && handleName != 0) {
      if (ih->handle != 0) {
        std::string  HandleNameA = handleName;
        std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
        x12ObjectSetName((ID3D12Object *)ih->handle, &handleNameW[0], optionalFile, optionalLine);
      }
    }
  }

  outStructsMemory[0] = (RedHandleStructsMemory)ih;
}

__declspec(dllexport) void redStructsMemoryAllocate(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned maxStructsCount, unsigned maxStructsMembersOfTypeArrayROConstantCount, unsigned maxStructsMembersOfTypeArrayROOrArrayRWCount, unsigned maxStructsMembersOfTypeTextureROCount, unsigned maxStructsMembersOfTypeTextureRWCount, RedHandleStructsMemory * outStructsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redStructsMemoryAllocate;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalStructsMemoryAllocate(context, gpu, handleName, 1, 0, maxStructsCount, maxStructsMembersOfTypeArrayROConstantCount, maxStructsMembersOfTypeArrayROOrArrayRWCount, 0, maxStructsMembersOfTypeTextureROCount, maxStructsMembersOfTypeTextureRWCount, outStructsMemory, outStatuses, optionalFile, optionalLine, optionalUserData, procedureId);
  PIXEndEvent();
}

__declspec(dllexport) void redStructsMemoryAllocateSamplers(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned maxStructsCount, unsigned maxStructsMembersOfTypeSamplerCount, RedHandleStructsMemory * outStructsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redStructsMemoryAllocateSamplers;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalStructsMemoryAllocate(context, gpu, handleName, 0, 1, maxStructsCount, 0, 0, maxStructsMembersOfTypeSamplerCount, 0, 0, outStructsMemory, outStatuses, optionalFile, optionalLine, optionalUserData, procedureId);
  PIXEndEvent();
}

__declspec(dllexport) void redStructsMemoryAllocateWithInlineSamplers(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned maxStructsCount, unsigned maxStructsMembersOfTypeArrayROConstantCount, unsigned maxStructsMembersOfTypeArrayROOrArrayRWCount, unsigned maxStructsMembersOfTypeTextureROCount, unsigned maxStructsMembersOfTypeTextureRWCount, unsigned maxStructsMembersOfTypeInlineSamplerCount, RedHandleStructsMemory * outStructsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redStructsMemoryAllocateWithInlineSamplers;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalStructsMemoryAllocate(context, gpu, handleName, 1, 0, maxStructsCount, maxStructsMembersOfTypeArrayROConstantCount, maxStructsMembersOfTypeArrayROOrArrayRWCount, 0, maxStructsMembersOfTypeTextureROCount, maxStructsMembersOfTypeTextureRWCount, outStructsMemory, outStatuses, optionalFile, optionalLine, optionalUserData, procedureId);
  PIXEndEvent();
}

__declspec(dllexport) void redStructsMemoryAllocateSamplersWithInlineSamplers(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned maxStructsCount, unsigned maxStructsMembersOfTypeSamplerCount, unsigned maxStructsMembersOfTypeInlineSamplerCount, RedHandleStructsMemory * outStructsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redStructsMemoryAllocateSamplersWithInlineSamplers;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalStructsMemoryAllocate(context, gpu, handleName, 0, 1, maxStructsCount, 0, 0, maxStructsMembersOfTypeSamplerCount, 0, 0, outStructsMemory, outStatuses, optionalFile, optionalLine, optionalUserData, procedureId);
  PIXEndEvent();
}

__declspec(dllexport) void redStructsMemoryFree(RedContext context, RedHandleGpu gpu, RedHandleStructsMemory structsMemory, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redStructsMemoryFree;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyStructsMemory(structsMemory, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) uint64_t redXGetMemoryAddressArray(RedContext context, RedHandleGpu gpu, RedHandleArray array) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXGetMemoryAddressArray;
  RedXInternalTypeArray * ih = (RedXInternalTypeArray *)array;
  uint64_t memoryAddress = (uint64_t)ih->cpuDescriptor.cpuDescriptorCBVSRVUAV.ptr;
  return memoryAddress;
}

__declspec(dllexport) uint64_t redXGetMemoryAddressSampler(RedContext context, RedHandleGpu gpu, RedHandleSampler sampler) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXGetMemoryAddressSampler;
  RedXInternalTypeSampler * ih = (RedXInternalTypeSampler *)sampler;
  uint64_t memoryAddress = (uint64_t)ih->cpuDescriptor.cpuDescriptorSampler.ptr;
  return memoryAddress;
}

__declspec(dllexport) uint64_t redXGetMemoryAddressTextureRO(RedContext context, RedHandleGpu gpu, RedHandleTexture texture) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXGetMemoryAddressTextureRO;
  RedXInternalTypeTexture * ih = (RedXInternalTypeTexture *)texture;
  uint64_t memoryAddress = (uint64_t)ih->cpuDescriptorSRV.cpuDescriptorCBVSRVUAV.ptr;
  return memoryAddress;
}

__declspec(dllexport) uint64_t redXGetMemoryAddressTextureRW(RedContext context, RedHandleGpu gpu, RedHandleTexture texture) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXGetMemoryAddressTextureRW;
  RedXInternalTypeTexture * ih = (RedXInternalTypeTexture *)texture;
  uint64_t memoryAddress = (uint64_t)ih->cpuDescriptorUAV.cpuDescriptorCBVSRVUAV.ptr;
  return memoryAddress;
}

__declspec(dllexport) uint64_t redXGetMemoryAddressStructMember(RedContext context, RedHandleGpu gpu, RedHandleStructsMemory structsMemory, unsigned structMemberIndex) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXGetMemoryAddressStructMember;

  RedXInternalTypeContext *       ctx           = (RedXInternalTypeContext *)context;
  RedXInternalTypeStructsMemory * ih            = (RedXInternalTypeStructsMemory *)structsMemory;
  D3D12_CPU_DESCRIPTOR_HANDLE     cpuDescriptor = {};

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, 0, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, (RedProcedureId)procedureId, 0, 0, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    return 0;
  }

  if (ih->maxStructsMembersOfTypeSamplerCount > 0) {
    x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(ih->handle, &cpuDescriptor);
    cpuDescriptor.ptr += structMemberIndex * ctx->internal.adaptersDescriptorHandleIncrementSizesSampler[gpuIndex];
  } else {
    x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(ih->handle, &cpuDescriptor);
    cpuDescriptor.ptr += structMemberIndex * ctx->internal.adaptersDescriptorHandleIncrementSizesCBVSRVUAV[gpuIndex];
  }

  return (uint64_t)cpuDescriptor.ptr;
}

__declspec(dllexport) void redXStructsMemorySet(RedContext context, RedHandleGpu gpu, RedBool32 copyingSamplers, unsigned sourceCopiesCount, const RedXMemoryAddress * sourceCopiesAddressFirst, const unsigned * sourceCopiesAddressCount, unsigned targetCopiesCount, const RedXMemoryAddress * targetCopiesAddressFirst, const unsigned * targetCopiesAddressCount, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXStructsMemorySet;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  x12DeviceCopyDescriptors((ID3D12Device3 *)gpu, targetCopiesCount, (const D3D12_CPU_DESCRIPTOR_HANDLE *)targetCopiesAddressFirst, targetCopiesAddressCount, sourceCopiesCount, (const D3D12_CPU_DESCRIPTOR_HANDLE *)sourceCopiesAddressFirst, sourceCopiesAddressCount, copyingSamplers == 1 ? D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER : D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) RedHandleStruct redXGetHandleStruct(RedContext context, RedHandleGpu gpu, RedHandleStructsMemory structsMemory, unsigned structMemberIndex) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXGetHandleStruct;

  RedXInternalTypeContext *       ctx           = (RedXInternalTypeContext *)context;
  RedXInternalTypeStructsMemory * ih            = (RedXInternalTypeStructsMemory *)structsMemory;
  D3D12_GPU_DESCRIPTOR_HANDLE     gpuDescriptor = {};

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, 0, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, (RedProcedureId)procedureId, 0, 0, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    return 0;
  }

  if (ih->maxStructsMembersOfTypeSamplerCount > 0) {
    x12DescriptorHeapGetGPUDescriptorHandleForHeapStart(ih->handle, &gpuDescriptor);
    gpuDescriptor.ptr += structMemberIndex * ctx->internal.adaptersDescriptorHandleIncrementSizesSampler[gpuIndex];
  } else {
    x12DescriptorHeapGetGPUDescriptorHandleForHeapStart(ih->handle, &gpuDescriptor);
    gpuDescriptor.ptr += structMemberIndex * ctx->internal.adaptersDescriptorHandleIncrementSizesCBVSRVUAV[gpuIndex];
  }

  return (RedHandleStruct)gpuDescriptor.ptr;
}

__declspec(dllexport) void redXCreateQueue(RedContext context, RedHandleGpu gpu, const char * handleName, RedBool32 canCopy, RedBool32 canDraw, RedBool32 canCompute, unsigned priority, RedBool32 disableGpuTimeout, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXCreateQueue;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeQueue *   ih  = 0;

  const unsigned queueFamilyIndex0Direct  = 0;
  const unsigned queueFamilyIndex1Compute = 1;
  const unsigned queueFamilyIndex2Copy    = 2;

  unsigned                queueFamilyIndex   = queueFamilyIndex0Direct;
  D3D12_COMMAND_LIST_TYPE type               = D3D12_COMMAND_LIST_TYPE_DIRECT;
  RedBool32               actuallyCanCopy    = 1;
  RedBool32               actuallyCanDraw    = 1;
  RedBool32               actuallyCanCompute = 1;
  if (canDraw == 0 && canCompute == 1) {
    queueFamilyIndex   = queueFamilyIndex1Compute;
    type               = D3D12_COMMAND_LIST_TYPE_COMPUTE;
    actuallyCanCopy    = 1;
    actuallyCanDraw    = 0;
    actuallyCanCompute = 1;
  } else if (canCopy == 1 && canDraw == 0 && canCompute == 0) {
    queueFamilyIndex   = queueFamilyIndex2Copy;
    type               = D3D12_COMMAND_LIST_TYPE_COPY;
    actuallyCanCopy    = 1;
    actuallyCanDraw    = 0;
    actuallyCanCompute = 0;
  }

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, (RedProcedureId)procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeQueueAllocate(ctx, gpuIndex, handleName, queueFamilyIndex, outStatuses, (RedProcedureId)procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    PIXEndEvent();
    return;
  }

  {
    D3D12_COMMAND_QUEUE_DESC desc = {};
    desc.Type     = type;
    desc.Priority = priority;
    desc.Flags    = disableGpuTimeout == 1 ? D3D12_COMMAND_QUEUE_FLAG_DISABLE_GPU_TIMEOUT : D3D12_COMMAND_QUEUE_FLAG_NONE;
    desc.NodeMask = 0;
    HRESULT hr = x12DeviceCreateCommandQueue((ID3D12Device3 *)gpu, &desc, &ih->handle, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyQueue((RedHandleQueue)ih, optionalFile, optionalLine);
      ih = 0;
      PIXEndEvent();
      return;
    }

    if (ctx->internal.debugCallback != 0 && handleName != 0) {
      if (ih->handle != 0) {
        std::string  HandleNameA = handleName;
        std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
        x12ObjectSetName((ID3D12Object *)ih->handle, &handleNameW[0], optionalFile, optionalLine);
      }
    }

    RedQueueCopyLimits queueCopyLimits = {};
    queueCopyLimits.copyBlockTexelsCountWidth  = 1;
    queueCopyLimits.copyBlockTexelsCountHeight = 1;
    queueCopyLimits.copyBlockTexelsCountDepth  = 1;
    try {
      ctx->internal.adaptersQueues[gpuIndex].push_back((RedHandleQueue)ih);
      ctx->internal.adaptersQueuesFamilyIndex[gpuIndex].push_back(queueFamilyIndex);
      ctx->internal.adaptersQueuesCanCopy[gpuIndex].push_back(actuallyCanCopy);
      ctx->internal.adaptersQueuesCanDraw[gpuIndex].push_back(actuallyCanDraw);
      ctx->internal.adaptersQueuesCanCompute[gpuIndex].push_back(actuallyCanCompute);
      ctx->internal.adaptersQueuesCopyLimits[gpuIndex].push_back(queueCopyLimits);
    } catch (...) {
      redInternalSetStatus(ctx, gpu, outStatuses, 4, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, (RedProcedureId)procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
      redInternalDestroyQueue((RedHandleQueue)ih, optionalFile, optionalLine);
      ih = 0;
      PIXEndEvent();
      return;
    }
    ctx->gpus[gpuIndex].queuesCount      += 1;
    ctx->gpus[gpuIndex].queues            = &ctx->internal.adaptersQueues[gpuIndex][0];
    ctx->gpus[gpuIndex].queuesFamilyIndex = &ctx->internal.adaptersQueuesFamilyIndex[gpuIndex][0];
    ctx->gpus[gpuIndex].queuesCanCopy     = &ctx->internal.adaptersQueuesCanCopy[gpuIndex][0];
    ctx->gpus[gpuIndex].queuesCanDraw     = &ctx->internal.adaptersQueuesCanDraw[gpuIndex][0];
    ctx->gpus[gpuIndex].queuesCanCompute  = &ctx->internal.adaptersQueuesCanCompute[gpuIndex][0];
    ctx->gpus[gpuIndex].queuesCopyLimits  = &ctx->internal.adaptersQueuesCopyLimits[gpuIndex][0];
  }

  PIXEndEvent();
}

static void redInternalCreateArray(RedContext context, RedHandleGpu gpu, const char * handleName, RedArrayType type, uint64_t bytesCount, uint64_t structuredBufferElementBytesCount, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedArray * outArray, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, const RedProcedureId procedureId) {
  RedXInternalTypeContext * ctx  = (RedXInternalTypeContext *)context;
  RedXInternalTypeArray *   ih   = 0;
  uint64_t memoryBytesAlignment = 0;
  uint64_t memoryBytesCount     = 0;
  unsigned memoryTypesSupported = 0;

  const unsigned memoryTypeSupported0OnlyBuffers          = REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0001);
  const unsigned memoryTypeSupported1OnlyTextures         = REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0010);
  const unsigned memoryTypeSupported2OnlyRtDsTextures     = REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0100);
  const unsigned memoryTypeSupported3OnlyRtDsTexturesMsaa = REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,1000);
  const unsigned memoryTypeSupported4Upload               = REDGPU_B32(0000,0000,0000,0000,0000,0000,0001,0000);
  const unsigned memoryTypeSupported5Readback             = REDGPU_B32(0000,0000,0000,0000,0000,0000,0010,0000);

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outArray[0].handle               = 0;
    outArray[0].memoryBytesAlignment = 0;
    outArray[0].memoryBytesCount     = 0;
    outArray[0].memoryTypesSupported = 0;
    return;
  }

  ih = redInternalTypeArrayAllocate(ctx, gpuIndex, handleName, type, bytesCount, structuredBufferElementBytesCount, initialAccess, initialQueueFamilyIndex, dedicate, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outArray[0].handle               = 0;
    outArray[0].memoryBytesAlignment = 0;
    outArray[0].memoryBytesCount     = 0;
    outArray[0].memoryTypesSupported = 0;
    return;
  }

  {
    memoryTypesSupported = memoryTypeSupported0OnlyBuffers;
    if (type == RED_ARRAY_TYPE_ARRAY_RO_CONSTANT) {
      memoryTypesSupported = memoryTypeSupported0OnlyBuffers | memoryTypeSupported4Upload;
    } else if (type == RED_ARRAY_TYPE_ARRAY_RO) {
      memoryTypesSupported = memoryTypeSupported0OnlyBuffers | memoryTypeSupported4Upload | memoryTypeSupported5Readback;
    } else if (type == RED_ARRAY_TYPE_ARRAY_RW) {
      memoryTypesSupported = memoryTypeSupported0OnlyBuffers | memoryTypeSupported4Upload | memoryTypeSupported5Readback;
    } else if (type == RED_ARRAY_TYPE_INDEX_RO) {
      memoryTypesSupported = memoryTypeSupported0OnlyBuffers | memoryTypeSupported4Upload;
    }

    D3D12_RESOURCE_FLAGS flags = D3D12_RESOURCE_FLAG_NONE;
    if (type == RED_ARRAY_TYPE_ARRAY_RW || type == REDX_ARRAY_TYPE_RAYTRACING_ACCELERATION_STRUCTURE) {
      flags |= D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS;
    }

    ih->resourceDescription.Dimension          = D3D12_RESOURCE_DIMENSION_BUFFER;
    ih->resourceDescription.Alignment          = 0;
    ih->resourceDescription.Width              = bytesCount;
    ih->resourceDescription.Height             = 1;
    ih->resourceDescription.DepthOrArraySize   = 1;
    ih->resourceDescription.MipLevels          = 1;
    ih->resourceDescription.Format             = DXGI_FORMAT_UNKNOWN;
    ih->resourceDescription.SampleDesc.Count   = 1;
    ih->resourceDescription.SampleDesc.Quality = 0;
    ih->resourceDescription.Layout             = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    ih->resourceDescription.Flags              = flags;
    D3D12_RESOURCE_ALLOCATION_INFO info = {};
    x12DeviceGetResourceAllocationInfo((ID3D12Device3 *)gpu, 0, 1, &ih->resourceDescription, &info, optionalFile, optionalLine);
    memoryBytesAlignment = info.Alignment;
    memoryBytesCount     = info.SizeInBytes;
  }

  outArray[0].handle               = (RedHandleArray)ih;
  outArray[0].memoryBytesAlignment = memoryBytesAlignment;
  outArray[0].memoryBytesCount     = memoryBytesCount;
  outArray[0].memoryTypesSupported = memoryTypesSupported;
}

__declspec(dllexport) void redCreateArray(RedContext context, RedHandleGpu gpu, const char * handleName, RedArrayType type, uint64_t bytesCount, uint64_t structuredBufferElementBytesCount, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedArray * outArray, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateArray;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalCreateArray(context, gpu, handleName, type, bytesCount, structuredBufferElementBytesCount, initialAccess, initialQueueFamilyIndex, dedicate, outArray, outStatuses, optionalFile, optionalLine, procedureId);
  PIXEndEvent();
}

static void redInternalCreateImage(RedContext context, RedHandleGpu gpu, const char * handleName, RedImageDimensions dimensions, RedFormat format, unsigned xformat, unsigned width, unsigned height, unsigned depth, unsigned levelsCount, unsigned layersCount, RedMultisampleCountBitflag multisampleCount, RedAccessBitflags restrictToAccess, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedImage * outImage, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData, const RedProcedureId procedureId) {
  RedXInternalTypeContext * ctx  = (RedXInternalTypeContext *)context;
  RedXInternalTypeImage *   ih   = 0;
  uint64_t memoryBytesAlignment = 0;
  uint64_t memoryBytesCount     = 0;
  unsigned memoryTypesSupported = 0;

  const unsigned memoryTypeSupported0OnlyBuffers          = REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0001);
  const unsigned memoryTypeSupported1OnlyTextures         = REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0010);
  const unsigned memoryTypeSupported2OnlyRtDsTextures     = REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0100);
  const unsigned memoryTypeSupported3OnlyRtDsTexturesMsaa = REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,1000);
  const unsigned memoryTypeSupported4Upload               = REDGPU_B32(0000,0000,0000,0000,0000,0000,0001,0000);
  const unsigned memoryTypeSupported5Readback             = REDGPU_B32(0000,0000,0000,0000,0000,0000,0010,0000);

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outImage[0].handle               = 0;
    outImage[0].memoryBytesAlignment = 0;
    outImage[0].memoryBytesCount     = 0;
    outImage[0].memoryTypesSupported = 0;
    return;
  }

  ih = redInternalTypeImageAllocate(ctx, gpuIndex, handleName, dimensions, format, xformat, width, height, depth, levelsCount, layersCount, multisampleCount, restrictToAccess, initialAccess, initialQueueFamilyIndex, dedicate, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outImage[0].handle               = 0;
    outImage[0].memoryBytesAlignment = 0;
    outImage[0].memoryBytesCount     = 0;
    outImage[0].memoryTypesSupported = 0;
    return;
  }

  {
    RedAccessBitflags imageUsage = 0;
    if (restrictToAccess == 0) {
      imageUsage |= RED_ACCESS_BITFLAG_COPY_R;
      imageUsage |= RED_ACCESS_BITFLAG_COPY_W;
      imageUsage |= RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R;
      imageUsage |= RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R;
    }
    if ((restrictToAccess & RED_ACCESS_BITFLAG_COPY_R)                               == RED_ACCESS_BITFLAG_COPY_R)                               { imageUsage |= RED_ACCESS_BITFLAG_COPY_R; }
    if ((restrictToAccess & RED_ACCESS_BITFLAG_COPY_W)                               == RED_ACCESS_BITFLAG_COPY_W)                               { imageUsage |= RED_ACCESS_BITFLAG_COPY_W; }
    if ((restrictToAccess & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) { imageUsage |= RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R; }
    if ((restrictToAccess & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R)     == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R)     { imageUsage |= RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R; }
    if ((restrictToAccess & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W)                    == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W)                    { imageUsage |= RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W; }
    if ((restrictToAccess & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R)                       == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R)                       { imageUsage |= RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R; }
    if ((restrictToAccess & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW)                      == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW)                      { imageUsage |= RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW; }
    if ((restrictToAccess & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R)                     == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R)                     { imageUsage |= RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R; }
    if ((restrictToAccess & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW)                    == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW)                    { imageUsage |= RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW; }
    if ((restrictToAccess & RED_ACCESS_BITFLAG_OUTPUT_COLOR_W)                       == RED_ACCESS_BITFLAG_OUTPUT_COLOR_W)                       { imageUsage |= RED_ACCESS_BITFLAG_OUTPUT_COLOR_W; }
    ih->restrictToAccessFinal = imageUsage;

    memoryTypesSupported = memoryTypeSupported1OnlyTextures;
    if (((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R)    == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R)    ||
        ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW)   == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW)   ||
        ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R)  == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R)  ||
        ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW) == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW) ||
        ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_COLOR_W)    == RED_ACCESS_BITFLAG_OUTPUT_COLOR_W))
    {
      if (multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_1) {
        memoryTypesSupported = memoryTypeSupported2OnlyRtDsTextures;
      } else {
        memoryTypesSupported = memoryTypeSupported3OnlyRtDsTexturesMsaa;
      }
    }

    D3D12_RESOURCE_FLAGS flags = D3D12_RESOURCE_FLAG_NONE;
    if (((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R)    == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R)   ||
        ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW)   == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW)  ||
        ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R)  == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R) ||
        ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW) == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW))
    {
      flags |= D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;
      if (((imageUsage & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) == 0) &&
          ((imageUsage & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R)     == 0) &&
          ((imageUsage & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W)                    == 0))
      {
        flags |= D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE;
      }
    }
    if ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_COLOR_W) == RED_ACCESS_BITFLAG_OUTPUT_COLOR_W) {
      flags |= D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;
    }
    if ((imageUsage & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W) {
      flags |= D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS;
    }
    if (initialQueueFamilyIndex == (unsigned)-1) {
      if ((multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_1)      &&
          ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R)    == 0) &&
          ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW)   == 0) &&
          ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R)  == 0) &&
          ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW) == 0))
      {
        flags |= D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS;
      }
    }

    DXGI_FORMAT x12format = redInternalREDGPUFormatToD3D12Format(xformat);

    ih->resourceDescription.Dimension          = redInternalREDGPUImageDimensionsToD3D12ResourceDimension(dimensions);
    ih->resourceDescription.Alignment          = 0;
    ih->resourceDescription.Width              = width;
    ih->resourceDescription.Height             = height;
    ih->resourceDescription.DepthOrArraySize   = depth > 1 ? depth : layersCount;
    ih->resourceDescription.MipLevels          = levelsCount;
    ih->resourceDescription.Format             = x12format;
    ih->resourceDescription.SampleDesc.Count   = redInternalREDGPUMultisampleCountToUnsignedValue(multisampleCount);
    ih->resourceDescription.SampleDesc.Quality = 0;
    ih->resourceDescription.Layout             = D3D12_TEXTURE_LAYOUT_UNKNOWN;
    ih->resourceDescription.Flags              = flags;
    D3D12_RESOURCE_ALLOCATION_INFO info = {};
    x12DeviceGetResourceAllocationInfo((ID3D12Device3 *)gpu, 0, 1, &ih->resourceDescription, &info, optionalFile, optionalLine);
    memoryBytesAlignment = info.Alignment;
    memoryBytesCount     = info.SizeInBytes;
  }

  outImage[0].handle               = (RedHandleImage)ih;
  outImage[0].memoryBytesAlignment = memoryBytesAlignment;
  outImage[0].memoryBytesCount     = memoryBytesCount;
  outImage[0].memoryTypesSupported = memoryTypesSupported;
}

__declspec(dllexport) void redCreateImage(RedContext context, RedHandleGpu gpu, const char * handleName, RedImageDimensions dimensions, RedFormat format, unsigned width, unsigned height, unsigned depth, unsigned levelsCount, unsigned layersCount, RedMultisampleCountBitflag multisampleCount, RedAccessBitflags restrictToAccess, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedImage * outImage, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateImage;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalCreateImage(context, gpu, handleName, dimensions, format, format, width, height, depth, levelsCount, layersCount, multisampleCount, restrictToAccess, initialAccess, initialQueueFamilyIndex, dedicate, outImage, outStatuses, optionalFile, optionalLine, optionalUserData, procedureId);
  PIXEndEvent();
}

__declspec(dllexport) void redXCreateImage(RedContext context, RedHandleGpu gpu, const char * handleName, RedImageDimensions dimensions, RedFormat format, unsigned xformat, unsigned width, unsigned height, unsigned depth, unsigned levelsCount, unsigned layersCount, RedMultisampleCountBitflag multisampleCount, RedAccessBitflags restrictToAccess, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedImage * outImage, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXCreateImage;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalCreateImage(context, gpu, handleName, dimensions, format, xformat, width, height, depth, levelsCount, layersCount, multisampleCount, restrictToAccess, initialAccess, initialQueueFamilyIndex, dedicate, outImage, outStatuses, optionalFile, optionalLine, optionalUserData, (const RedProcedureId)procedureId);
  PIXEndEvent();
}

__declspec(dllexport) void redCreateSampler(RedContext context, RedHandleGpu gpu, const char * handleName, RedSamplerFiltering filteringMag, RedSamplerFiltering filteringMin, RedSamplerFilteringMip filteringMip, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateU, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateV, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateW, float mipLodBias, RedBool32 enableAnisotropy, float maxAnisotropy, RedBool32 enableCompare, RedCompareOp compareOp, float minLod, float maxLod, RedHandleSampler * outSampler, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateSampler;
  PIXBeginEvent(0, __FUNCTION__);

  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeSampler * ih  = 0;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outSampler[0] = 0;
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeSamplerAllocate(ctx, gpuIndex, handleName, filteringMag, filteringMin, filteringMip, behaviorOutsideTextureCoordinateU, behaviorOutsideTextureCoordinateV, behaviorOutsideTextureCoordinateW, mipLodBias, enableAnisotropy, maxAnisotropy, enableCompare, compareOp, minLod, maxLod, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outSampler[0] = 0;
    PIXEndEvent();
    return;
  }

  {
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
    descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
    descriptorHeapDesc.NumDescriptors = 1;
    descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    descriptorHeapDesc.NodeMask       = 0;
    HRESULT hr = x12DeviceCreateDescriptorHeap((ID3D12Device3 *)gpu, &descriptorHeapDesc, &ih->cpuDescriptor.cpuDescriptorHeapSampler, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroySampler((RedHandleSampler)ih, optionalFile, optionalLine);
      ih = 0;
      outSampler[0] = 0;
      PIXEndEvent();
      return;
    }
    if (ctx->internal.debugCallback != 0 && ih->handleName.empty() == false) {
      if (ih->cpuDescriptor.cpuDescriptorHeapSampler != 0) {
        std::wstring handleNameW(ih->handleName.begin(), ih->handleName.end());
        x12ObjectSetName((ID3D12Object *)ih->cpuDescriptor.cpuDescriptorHeapSampler, &handleNameW[0], optionalFile, optionalLine);
      }
    }
    x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(ih->cpuDescriptor.cpuDescriptorHeapSampler, &ih->cpuDescriptor.cpuDescriptorSampler);

    D3D12_FILTER_TYPE d3d12FilterMag = (D3D12_FILTER_TYPE)-1;
    if (filteringMag == RED_SAMPLER_FILTERING_NEAREST) {
      d3d12FilterMag = D3D12_FILTER_TYPE_POINT;
    } else if (filteringMag == RED_SAMPLER_FILTERING_LINEAR) {
      d3d12FilterMag = D3D12_FILTER_TYPE_LINEAR;
    }

    D3D12_FILTER_TYPE d3d12FilterMin = (D3D12_FILTER_TYPE)-1;
    if (filteringMin == RED_SAMPLER_FILTERING_NEAREST) {
      d3d12FilterMin = D3D12_FILTER_TYPE_POINT;
    } else if (filteringMin == RED_SAMPLER_FILTERING_LINEAR) {
      d3d12FilterMin = D3D12_FILTER_TYPE_LINEAR;
    }

    D3D12_FILTER_TYPE d3d12FilterMip = (D3D12_FILTER_TYPE)-1;
    if (filteringMip == RED_SAMPLER_FILTERING_MIP_NEAREST) {
      d3d12FilterMip = D3D12_FILTER_TYPE_POINT;
    } else if (filteringMip == RED_SAMPLER_FILTERING_MIP_LINEAR) {
      d3d12FilterMip = D3D12_FILTER_TYPE_LINEAR;
    }

    D3D12_FILTER_REDUCTION_TYPE d3d12Reduction = enableCompare == 0 ? D3D12_FILTER_REDUCTION_TYPE_STANDARD : D3D12_FILTER_REDUCTION_TYPE_COMPARISON;

    D3D12_FILTER d3d12Filter = enableAnisotropy ? D3D12_ENCODE_ANISOTROPIC_FILTER(d3d12Reduction) : D3D12_ENCODE_BASIC_FILTER(d3d12FilterMin, d3d12FilterMag, d3d12FilterMip, d3d12Reduction);

    D3D12_TEXTURE_ADDRESS_MODE d3d12AddressU = (D3D12_TEXTURE_ADDRESS_MODE)-1;
    if (behaviorOutsideTextureCoordinateU == RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT) {
      d3d12AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
    } else if (behaviorOutsideTextureCoordinateU == RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT_MIRRORED) {
      d3d12AddressU = D3D12_TEXTURE_ADDRESS_MODE_MIRROR;
    } else if (behaviorOutsideTextureCoordinateU == RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_CLAMP_TO_EDGE_VALUE) {
      d3d12AddressU = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    }

    D3D12_TEXTURE_ADDRESS_MODE d3d12AddressV = (D3D12_TEXTURE_ADDRESS_MODE)-1;
    if (behaviorOutsideTextureCoordinateV == RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT) {
      d3d12AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
    } else if (behaviorOutsideTextureCoordinateV == RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT_MIRRORED) {
      d3d12AddressV = D3D12_TEXTURE_ADDRESS_MODE_MIRROR;
    } else if (behaviorOutsideTextureCoordinateV == RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_CLAMP_TO_EDGE_VALUE) {
      d3d12AddressV = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    }

    D3D12_TEXTURE_ADDRESS_MODE d3d12AddressW = (D3D12_TEXTURE_ADDRESS_MODE)-1;
    if (behaviorOutsideTextureCoordinateW == RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT) {
      d3d12AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
    } else if (behaviorOutsideTextureCoordinateW == RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT_MIRRORED) {
      d3d12AddressW = D3D12_TEXTURE_ADDRESS_MODE_MIRROR;
    } else if (behaviorOutsideTextureCoordinateW == RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_CLAMP_TO_EDGE_VALUE) {
      d3d12AddressW = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    }

    ih->samplerDescription.Filter         = d3d12Filter;
    ih->samplerDescription.AddressU       = d3d12AddressU;
    ih->samplerDescription.AddressV       = d3d12AddressV;
    ih->samplerDescription.AddressW       = d3d12AddressW;
    ih->samplerDescription.MipLODBias     = mipLodBias;
    ih->samplerDescription.MaxAnisotropy  = (unsigned)maxAnisotropy;
    ih->samplerDescription.ComparisonFunc = redInternalREDGPUCompareOpToD3D12ComparisonFunc(compareOp);
    ih->samplerDescription.BorderColor[0] = 0;
    ih->samplerDescription.BorderColor[1] = 0;
    ih->samplerDescription.BorderColor[2] = 0;
    ih->samplerDescription.BorderColor[3] = 0;
    ih->samplerDescription.MinLOD         = minLod;
    ih->samplerDescription.MaxLOD         = maxLod;
    x12DeviceCreateSampler((ID3D12Device3 *)gpu, &ih->samplerDescription, ih->cpuDescriptor.cpuDescriptorSampler, optionalFile, optionalLine);
  }

  outSampler[0] = (RedHandleSampler)ih;

  PIXEndEvent();
}

static void redInternalCreateTexture(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleImage image, RedImagePartBitflags parts, RedTextureDimensions dimensions, RedFormat format, unsigned xformat, unsigned levelsFirst, unsigned levelsCount, unsigned layersFirst, unsigned layersCount, RedAccessBitflags restrictToAccess, RedHandleTexture * outTexture, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, const RedProcedureId procedureId, unsigned statusIndexOffset) {
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeTexture * ih  = 0;

  HRESULT hr = S_OK;

  const RedXInternalTypeImage * ihimage = (const RedXInternalTypeImage *)image;

  RedBool32 createSRV = 0;
  RedBool32 createUAV = 0;
  RedBool32 createDSV = 0;
  RedBool32 createRTV = 0;

  RedBool32 outputDepthRO   = 0;
  RedBool32 outputStencilRO = 0;

  DXGI_FORMAT x12format = redInternalREDGPUFormatToD3D12Format(xformat);

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, statusIndexOffset + 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outTexture[0] = 0;
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeTextureAllocate(ctx, gpuIndex, handleName, image, parts, dimensions, format, xformat, levelsFirst, levelsCount, layersFirst, layersCount, restrictToAccess, outStatuses, procedureId, statusIndexOffset + 1, optionalFile, optionalLine);
  if (ih == 0) {
    outTexture[0] = 0;
    PIXEndEvent();
    return;
  }

  {
    if (restrictToAccess != 0) {
      const RedAccessBitflags imageUsage = ihimage->restrictToAccessFinal;

      if ((restrictToAccess & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) {
        if ((imageUsage     & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) {
          createSRV = 1;
        }
      }
      if ((restrictToAccess & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R) {
        if ((imageUsage     & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R) {
          createSRV = 1;
        }
      }
      if ((restrictToAccess & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W) {
        if ((imageUsage     & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W) {
          createUAV = 1;
        }
      }
      if ((restrictToAccess & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R) == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R) {
        if ((imageUsage     & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R) == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R) {
          createDSV = 1;
          outputDepthRO = 1;
        }
      }
      if ((restrictToAccess & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW) == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW) {
        if ((imageUsage     & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW) == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW) {
          createDSV = 1;
          outputDepthRO = 0;
        }
      }
      if ((restrictToAccess & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R) == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R) {
        if ((imageUsage     & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R) == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R) {
          createDSV = 1;
          outputStencilRO = 1;
        }
      }
      if ((restrictToAccess & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW) == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW) {
        if ((imageUsage     & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW) == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW) {
          createDSV = 1;
          outputStencilRO = 0;
        }
      }
      if ((restrictToAccess & RED_ACCESS_BITFLAG_OUTPUT_COLOR_W) == RED_ACCESS_BITFLAG_OUTPUT_COLOR_W) {
        if ((imageUsage     & RED_ACCESS_BITFLAG_OUTPUT_COLOR_W) == RED_ACCESS_BITFLAG_OUTPUT_COLOR_W) {
          createRTV = 1;
        }
      }
    } else {
      const RedAccessBitflags imageUsage = ihimage->restrictToAccessFinal;

      if ((imageUsage & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R) {
        createSRV = 1;
      }
      if ((imageUsage & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R) {
        createSRV = 1;
      }
      if ((imageUsage & RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W) == RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W) {
        createUAV = 1;
      }
      if ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R) == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R) {
        createDSV = 1;
        outputDepthRO = 1;
      }
      if ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW) == RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW) {
        createDSV = 1;
        outputDepthRO = 0;
      }
      if ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R) == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R) {
        createDSV = 1;
        outputStencilRO = 1;
      }
      if ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW) == RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW) {
        createDSV = 1;
        outputStencilRO = 0;
      }
      if ((imageUsage & RED_ACCESS_BITFLAG_OUTPUT_COLOR_W) == RED_ACCESS_BITFLAG_OUTPUT_COLOR_W) {
        createRTV = 1;
      }
    }

    if (ihimage->ownedByPresent != 0) {
      createSRV = 0;
      createUAV = 0;
      createDSV = 0;
      createRTV = 1;
    }

    if (createSRV == 1) {
      D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
      descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
      descriptorHeapDesc.NumDescriptors = 1;
      descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
      descriptorHeapDesc.NodeMask       = 0;
      hr = x12DeviceCreateDescriptorHeap((ID3D12Device3 *)gpu, &descriptorHeapDesc, &ih->cpuDescriptorSRV.cpuDescriptorHeapCBVSRVUAV, optionalFile, optionalLine);
      if (hr < 0) {
        redInternalDestroyTexture((RedHandleTexture)ih, optionalFile, optionalLine);
        ih = 0;
        outTexture[0] = 0;
        PIXEndEvent();
        return;
      }
      if (ctx->internal.debugCallback != 0 && ih->handleName.empty() == false) {
        if (ih->cpuDescriptorSRV.cpuDescriptorHeapCBVSRVUAV != 0) {
          std::wstring handleNameW(ih->handleName.begin(), ih->handleName.end());
          x12ObjectSetName((ID3D12Object *)ih->cpuDescriptorSRV.cpuDescriptorHeapCBVSRVUAV, &handleNameW[0], optionalFile, optionalLine);
        }
      }
      x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(ih->cpuDescriptorSRV.cpuDescriptorHeapCBVSRVUAV, &ih->cpuDescriptorSRV.cpuDescriptorCBVSRVUAV);
      D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
      srvDesc.Format                  = x12format;
      srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
      if (dimensions == RED_TEXTURE_DIMENSIONS_1D) {
        srvDesc.ViewDimension                 = D3D12_SRV_DIMENSION_TEXTURE1D;
        srvDesc.Texture1D.MostDetailedMip     = levelsFirst;
        srvDesc.Texture1D.MipLevels           = levelsCount;
        srvDesc.Texture1D.ResourceMinLODClamp = 0;
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_1D_LAYERED) {
        srvDesc.ViewDimension                 = D3D12_SRV_DIMENSION_TEXTURE1DARRAY;
        srvDesc.Texture1DArray.MostDetailedMip     = levelsFirst;
        srvDesc.Texture1DArray.MipLevels           = levelsCount;
        srvDesc.Texture1DArray.FirstArraySlice     = layersFirst;
        srvDesc.Texture1DArray.ArraySize           = layersCount;
        srvDesc.Texture1DArray.ResourceMinLODClamp = 0;
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_2D) {
        if (ihimage->multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_1) {
          srvDesc.ViewDimension                 = D3D12_SRV_DIMENSION_TEXTURE2D;
          srvDesc.Texture2D.MostDetailedMip     = levelsFirst;
          srvDesc.Texture2D.MipLevels           = levelsCount;
          srvDesc.Texture2D.PlaneSlice          = 0;
          srvDesc.Texture2D.ResourceMinLODClamp = 0;
        } else {
          srvDesc.ViewDimension                           = D3D12_SRV_DIMENSION_TEXTURE2DMS;
          srvDesc.Texture2DMS.UnusedField_NothingToDefine = 0;
        }
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_2D_LAYERED) {
        if (ihimage->multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_1) {
          srvDesc.ViewDimension                      = D3D12_SRV_DIMENSION_TEXTURE2DARRAY;
          srvDesc.Texture2DArray.MostDetailedMip     = levelsFirst;
          srvDesc.Texture2DArray.MipLevels           = levelsCount;
          srvDesc.Texture2DArray.FirstArraySlice     = layersFirst;
          srvDesc.Texture2DArray.ArraySize           = layersCount;
          srvDesc.Texture2DArray.PlaneSlice          = 0;
          srvDesc.Texture2DArray.ResourceMinLODClamp = 0;
        } else {
          srvDesc.ViewDimension                    = D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY;
          srvDesc.Texture2DMSArray.FirstArraySlice = layersFirst;
          srvDesc.Texture2DMSArray.ArraySize       = layersCount;
        }
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_3D) {
        srvDesc.ViewDimension                 = D3D12_SRV_DIMENSION_TEXTURE3D;
        srvDesc.Texture3D.MostDetailedMip     = levelsFirst;
        srvDesc.Texture3D.MipLevels           = levelsCount;
        srvDesc.Texture3D.ResourceMinLODClamp = 0;
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_CUBE) {
        srvDesc.ViewDimension                   = D3D12_SRV_DIMENSION_TEXTURECUBE;
        srvDesc.TextureCube.MostDetailedMip     = levelsFirst;
        srvDesc.TextureCube.MipLevels           = levelsCount;
        srvDesc.TextureCube.ResourceMinLODClamp = 0;
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_CUBE_LAYERED) {
        srvDesc.ViewDimension                        = D3D12_SRV_DIMENSION_TEXTURECUBEARRAY;
        srvDesc.TextureCubeArray.MostDetailedMip     = levelsFirst;
        srvDesc.TextureCubeArray.MipLevels           = levelsCount;
        srvDesc.TextureCubeArray.First2DArrayFace    = layersFirst;
        srvDesc.TextureCubeArray.NumCubes            = layersCount / 6;
        srvDesc.TextureCubeArray.ResourceMinLODClamp = 0;
      }
      x12DeviceCreateShaderResourceView((ID3D12Device3 *)gpu, ihimage->handle, &srvDesc, ih->cpuDescriptorSRV.cpuDescriptorCBVSRVUAV, optionalFile, optionalLine);
    }

    if (createUAV == 1) {
      D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
      descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
      descriptorHeapDesc.NumDescriptors = 1;
      descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
      descriptorHeapDesc.NodeMask       = 0;
      hr = x12DeviceCreateDescriptorHeap((ID3D12Device3 *)gpu, &descriptorHeapDesc, &ih->cpuDescriptorUAV.cpuDescriptorHeapCBVSRVUAV, optionalFile, optionalLine);
      if (hr < 0) {
        redInternalDestroyTexture((RedHandleTexture)ih, optionalFile, optionalLine);
        ih = 0;
        outTexture[0] = 0;
        PIXEndEvent();
        return;
      }
      if (ctx->internal.debugCallback != 0 && ih->handleName.empty() == false) {
        if (ih->cpuDescriptorUAV.cpuDescriptorHeapCBVSRVUAV != 0) {
          std::wstring handleNameW(ih->handleName.begin(), ih->handleName.end());
          x12ObjectSetName((ID3D12Object *)ih->cpuDescriptorUAV.cpuDescriptorHeapCBVSRVUAV, &handleNameW[0], optionalFile, optionalLine);
        }
      }
      x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(ih->cpuDescriptorUAV.cpuDescriptorHeapCBVSRVUAV, &ih->cpuDescriptorUAV.cpuDescriptorCBVSRVUAV);
      D3D12_UNORDERED_ACCESS_VIEW_DESC uavDesc = {};
      uavDesc.Format = x12format;
      if (dimensions == RED_TEXTURE_DIMENSIONS_1D) {
        uavDesc.ViewDimension      = D3D12_UAV_DIMENSION_TEXTURE1D;
        uavDesc.Texture1D.MipSlice = levelsFirst;
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_1D_LAYERED) {
        uavDesc.ViewDimension                  = D3D12_UAV_DIMENSION_TEXTURE1DARRAY;
        uavDesc.Texture1DArray.MipSlice        = levelsFirst;
        uavDesc.Texture1DArray.FirstArraySlice = layersFirst;
        uavDesc.Texture1DArray.ArraySize       = layersCount;
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_2D) {
        uavDesc.ViewDimension        = D3D12_UAV_DIMENSION_TEXTURE2D;
        uavDesc.Texture2D.MipSlice   = levelsFirst;
        uavDesc.Texture2D.PlaneSlice = 0;
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_2D_LAYERED) {
        uavDesc.ViewDimension                  = D3D12_UAV_DIMENSION_TEXTURE2DARRAY;
        uavDesc.Texture2DArray.MipSlice        = levelsFirst;
        uavDesc.Texture2DArray.FirstArraySlice = layersFirst;
        uavDesc.Texture2DArray.ArraySize       = layersCount;
        uavDesc.Texture2DArray.PlaneSlice      = 0;
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_3D) {
        uavDesc.ViewDimension         = D3D12_UAV_DIMENSION_TEXTURE3D;
        uavDesc.Texture3D.MipSlice    = levelsFirst;
        uavDesc.Texture3D.FirstWSlice = layersFirst;
        uavDesc.Texture3D.WSize       = layersCount;
      } else {
      }
      x12DeviceCreateUnorderedAccessView((ID3D12Device3 *)gpu, ihimage->handle, 0, &uavDesc, ih->cpuDescriptorUAV.cpuDescriptorCBVSRVUAV, optionalFile, optionalLine);
    }

    if (createDSV == 1) {
      D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
      descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
      descriptorHeapDesc.NumDescriptors = 1;
      descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
      descriptorHeapDesc.NodeMask       = 0;
      hr = x12DeviceCreateDescriptorHeap((ID3D12Device3 *)gpu, &descriptorHeapDesc, &ih->cpuDescriptorDSV.cpuDescriptorHeapDSV, optionalFile, optionalLine);
      if (hr < 0) {
        redInternalDestroyTexture((RedHandleTexture)ih, optionalFile, optionalLine);
        ih = 0;
        outTexture[0] = 0;
        PIXEndEvent();
        return;
      }
      if (ctx->internal.debugCallback != 0 && ih->handleName.empty() == false) {
        if (ih->cpuDescriptorDSV.cpuDescriptorHeapDSV != 0) {
          std::wstring handleNameW(ih->handleName.begin(), ih->handleName.end());
          x12ObjectSetName((ID3D12Object *)ih->cpuDescriptorDSV.cpuDescriptorHeapDSV, &handleNameW[0], optionalFile, optionalLine);
        }
      }
      x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(ih->cpuDescriptorDSV.cpuDescriptorHeapDSV, &ih->cpuDescriptorDSV.cpuDescriptorDSV);
      D3D12_DEPTH_STENCIL_VIEW_DESC dsvDesc = {};
      dsvDesc.Format = x12format;
      if (outputDepthRO == 1) {
        dsvDesc.Flags |= D3D12_DSV_FLAG_READ_ONLY_DEPTH;
      }
      if (outputStencilRO == 1) {
        dsvDesc.Flags |= D3D12_DSV_FLAG_READ_ONLY_STENCIL;
      }
      if (dimensions == RED_TEXTURE_DIMENSIONS_1D) {
        dsvDesc.ViewDimension      = D3D12_DSV_DIMENSION_TEXTURE1D;
        dsvDesc.Texture1D.MipSlice = levelsFirst;
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_1D_LAYERED) {
        dsvDesc.ViewDimension                  = D3D12_DSV_DIMENSION_TEXTURE1DARRAY;
        dsvDesc.Texture1DArray.MipSlice        = levelsFirst;
        dsvDesc.Texture1DArray.FirstArraySlice = layersFirst;
        dsvDesc.Texture1DArray.ArraySize       = layersCount;
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_2D) {
        if (ihimage->multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_1) {
          dsvDesc.ViewDimension      = D3D12_DSV_DIMENSION_TEXTURE2D;
          dsvDesc.Texture2D.MipSlice = levelsFirst;
        } else {
          dsvDesc.ViewDimension                           = D3D12_DSV_DIMENSION_TEXTURE2DMS;
          dsvDesc.Texture2DMS.UnusedField_NothingToDefine = 0;
        }
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_2D_LAYERED) {
        if (ihimage->multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_1) {
          dsvDesc.ViewDimension                  = D3D12_DSV_DIMENSION_TEXTURE2DARRAY;
          dsvDesc.Texture2DArray.MipSlice        = levelsFirst;
          dsvDesc.Texture2DArray.FirstArraySlice = layersFirst;
          dsvDesc.Texture2DArray.ArraySize       = layersCount;
        } else {
          dsvDesc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY;
          dsvDesc.Texture2DMSArray.FirstArraySlice = layersFirst;
          dsvDesc.Texture2DMSArray.ArraySize       = layersCount;
        }
      } else {
      }
      x12DeviceCreateDepthStencilView((ID3D12Device3 *)gpu, ihimage->handle, &dsvDesc, ih->cpuDescriptorDSV.cpuDescriptorDSV, optionalFile, optionalLine);
    }

    if (createRTV == 1) {
      D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
      descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
      descriptorHeapDesc.NumDescriptors = 1;
      descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
      descriptorHeapDesc.NodeMask       = 0;
      hr = x12DeviceCreateDescriptorHeap((ID3D12Device3 *)gpu, &descriptorHeapDesc, &ih->cpuDescriptorRTV.cpuDescriptorHeapRTV, optionalFile, optionalLine);
      if (hr < 0) {
        redInternalDestroyTexture((RedHandleTexture)ih, optionalFile, optionalLine);
        ih = 0;
        outTexture[0] = 0;
        PIXEndEvent();
        return;
      }
      if (ctx->internal.debugCallback != 0 && ih->handleName.empty() == false) {
        if (ih->cpuDescriptorRTV.cpuDescriptorHeapRTV != 0) {
          std::wstring handleNameW(ih->handleName.begin(), ih->handleName.end());
          x12ObjectSetName((ID3D12Object *)ih->cpuDescriptorRTV.cpuDescriptorHeapRTV, &handleNameW[0], optionalFile, optionalLine);
        }
      }
      x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(ih->cpuDescriptorRTV.cpuDescriptorHeapRTV, &ih->cpuDescriptorRTV.cpuDescriptorRTV);
      D3D12_RENDER_TARGET_VIEW_DESC rtvDesc = {};
      rtvDesc.Format = x12format;
      if (dimensions == RED_TEXTURE_DIMENSIONS_1D) {
        rtvDesc.ViewDimension      = D3D12_RTV_DIMENSION_TEXTURE1D;
        rtvDesc.Texture1D.MipSlice = levelsFirst;
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_1D_LAYERED) {
        rtvDesc.ViewDimension                  = D3D12_RTV_DIMENSION_TEXTURE1DARRAY;
        rtvDesc.Texture1DArray.MipSlice        = levelsFirst;
        rtvDesc.Texture1DArray.FirstArraySlice = layersFirst;
        rtvDesc.Texture1DArray.ArraySize       = layersCount;
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_2D) {
        if (ihimage->multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_1) {
          rtvDesc.ViewDimension        = D3D12_RTV_DIMENSION_TEXTURE2D;
          rtvDesc.Texture2D.MipSlice   = levelsFirst;
          rtvDesc.Texture2D.PlaneSlice = 0;
        } else {
          rtvDesc.ViewDimension                           = D3D12_RTV_DIMENSION_TEXTURE2DMS;
          rtvDesc.Texture2DMS.UnusedField_NothingToDefine = 0;
        }
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_2D_LAYERED) {
        if (ihimage->multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_1) {
          rtvDesc.ViewDimension                  = D3D12_RTV_DIMENSION_TEXTURE2DARRAY;
          rtvDesc.Texture2DArray.MipSlice        = levelsFirst;
          rtvDesc.Texture2DArray.FirstArraySlice = layersFirst;
          rtvDesc.Texture2DArray.ArraySize       = layersCount;
          rtvDesc.Texture2DArray.PlaneSlice      = 0;
        } else {
          rtvDesc.ViewDimension                    = D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY;
          rtvDesc.Texture2DMSArray.FirstArraySlice = layersFirst;
          rtvDesc.Texture2DMSArray.ArraySize       = layersCount;
        }
      } else if (dimensions == RED_TEXTURE_DIMENSIONS_3D) {
        rtvDesc.ViewDimension         = D3D12_RTV_DIMENSION_TEXTURE3D;
        rtvDesc.Texture3D.MipSlice    = levelsFirst;
        rtvDesc.Texture3D.FirstWSlice = layersFirst;
        rtvDesc.Texture3D.WSize       = layersCount;
      } else {
      }
      x12DeviceCreateRenderTargetView((ID3D12Device3 *)gpu, ihimage->handle, &rtvDesc, ih->cpuDescriptorRTV.cpuDescriptorRTV, optionalFile, optionalLine);
    }
  }

  outTexture[0] = (RedHandleTexture)ih;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateTexture(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleImage image, RedImagePartBitflags parts, RedTextureDimensions dimensions, RedFormat format, unsigned levelsFirst, unsigned levelsCount, unsigned layersFirst, unsigned layersCount, RedAccessBitflags restrictToAccess, RedHandleTexture * outTexture, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateTexture;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalCreateTexture(context, gpu, handleName, image, parts, dimensions, format, format, levelsFirst, levelsCount, layersFirst, layersCount, restrictToAccess, outTexture, outStatuses, optionalFile, optionalLine, procedureId, 0);
  PIXEndEvent();
}

__declspec(dllexport) void redXCreateTexture(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleImage image, RedImagePartBitflags parts, RedTextureDimensions dimensions, RedFormat format, unsigned xformat, unsigned levelsFirst, unsigned levelsCount, unsigned layersFirst, unsigned layersCount, RedAccessBitflags restrictToAccess, RedHandleTexture * outTexture, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXCreateTexture;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalCreateTexture(context, gpu, handleName, image, parts, dimensions, format, xformat, levelsFirst, levelsCount, layersFirst, layersCount, restrictToAccess, outTexture, outStatuses, optionalFile, optionalLine, (RedProcedureId)procedureId, 0);
  PIXEndEvent();
}

__declspec(dllexport) void redCreateGpuCode(RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t irBytesCount, const void * ir, RedHandleGpuCode * outGpuCode, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateGpuCode;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx             = (RedXInternalTypeContext *)context;
  unsigned char *           pointer         = 0;
  uint64_t *                pointerAsUInt64 = 0;

  pointer = new(std::nothrow) unsigned char[sizeof(uint64_t) + irBytesCount];
  if (pointer == 0) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    outGpuCode[0] = 0;
    PIXEndEvent();
    return;
  }

  {
    pointerAsUInt64    = (uint64_t *)pointer;
    pointerAsUInt64[0] = irBytesCount;
    uint64_t * pointerToIr = &pointerAsUInt64[1];
    pointer = (unsigned char *)pointerToIr;

    memcpy(pointer, ir, irBytesCount);
  }

  outGpuCode[0] = (RedHandleGpuCode)pointerAsUInt64;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateOutputDeclaration(RedContext context, RedHandleGpu gpu, const char * handleName, const RedOutputDeclarationMembers * outputDeclarationMembers, const RedOutputDeclarationMembersResolveSources * outputDeclarationMembersResolveSources, RedBool32 dependencyByRegion, RedBool32 dependencyByRegionAllowUsageAliasOrderBarriers, RedHandleOutputDeclaration * outOutputDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateOutputDeclaration;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx     = (RedXInternalTypeContext *)context;
  unsigned *                pointer = 0;

  pointer = new(std::nothrow) unsigned[9]();
  if (pointer == 0) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    outOutputDeclaration[0] = 0;
    PIXEndEvent();
    return;
  }

  if (outputDeclarationMembers != 0) {
    pointer[0] = outputDeclarationMembers->colorsCount > 0 ? outputDeclarationMembers->colorsFormat[0] : RED_FORMAT_UNDEFINED;
    pointer[1] = outputDeclarationMembers->colorsCount > 1 ? outputDeclarationMembers->colorsFormat[1] : RED_FORMAT_UNDEFINED;
    pointer[2] = outputDeclarationMembers->colorsCount > 2 ? outputDeclarationMembers->colorsFormat[2] : RED_FORMAT_UNDEFINED;
    pointer[3] = outputDeclarationMembers->colorsCount > 3 ? outputDeclarationMembers->colorsFormat[3] : RED_FORMAT_UNDEFINED;
    pointer[4] = outputDeclarationMembers->colorsCount > 4 ? outputDeclarationMembers->colorsFormat[4] : RED_FORMAT_UNDEFINED;
    pointer[5] = outputDeclarationMembers->colorsCount > 5 ? outputDeclarationMembers->colorsFormat[5] : RED_FORMAT_UNDEFINED;
    pointer[6] = outputDeclarationMembers->colorsCount > 6 ? outputDeclarationMembers->colorsFormat[6] : RED_FORMAT_UNDEFINED;
    pointer[7] = outputDeclarationMembers->colorsCount > 7 ? outputDeclarationMembers->colorsFormat[7] : RED_FORMAT_UNDEFINED;
    pointer[8] = outputDeclarationMembers->depthStencilEnable == 1 ? outputDeclarationMembers->depthStencilFormat : RED_FORMAT_UNDEFINED;
  }

  outOutputDeclaration[0] = (RedHandleOutputDeclaration)pointer;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateStructDeclaration(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned structDeclarationMembersCount, const RedStructDeclarationMember * structDeclarationMembers, unsigned structDeclarationMembersArrayROCount, const RedStructDeclarationMemberArrayRO * structDeclarationMembersArrayRO, RedBool32 procedureParametersHandlesDeclaration, RedHandleStructDeclaration * outStructDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateStructDeclaration;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext *           ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeStructDeclaration * ih  = 0;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outStructDeclaration[0] = 0;
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeStructDeclarationAllocate(ctx, gpuIndex, handleName, structDeclarationMembersCount, structDeclarationMembers, procedureParametersHandlesDeclaration, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outStructDeclaration[0] = 0;
    PIXEndEvent();
    return;
  }

  outStructDeclaration[0] = (RedHandleStructDeclaration)ih;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateProcedureParameters(RedContext context, RedHandleGpu gpu, const char * handleName, const RedProcedureParametersDeclaration * procedureParametersDeclaration, RedHandleProcedureParameters * outProcedureParameters, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateProcedureParameters;
  PIXBeginEvent(0, __FUNCTION__);

  RedXInternalTypeContext *             ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeProcedureParameters * ih  = 0;

  RedProcedureParametersDeclaration declaration = {};
  if (procedureParametersDeclaration != 0) {
    declaration = procedureParametersDeclaration[0];
  }

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outProcedureParameters[0] = 0;
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeProcedureParametersAllocate(ctx, gpuIndex, handleName, &declaration, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outProcedureParameters[0] = 0;
    PIXEndEvent();
    return;
  }

  {
    RedBool32 theEntireProcedureParametersIsComputeOnly  = 1;
    RedBool32 theEntireProcedureParametersIsVertexOnly   = 1;
    RedBool32 theEntireProcedureParametersIsFragmentOnly = 1;
    RedBool32 variablesVisibleOnlyToStageVertex          = 1;
    RedBool32 variablesVisibleOnlyToStageFragment        = 1;
    unsigned  variablesTotalBytesCount                   = 0;
    RedBool32 structsVisibleOnlyToStageVertex[7]         = {1, 1, 1, 1, 1, 1, 1};
    RedBool32 structsVisibleOnlyToStageFragment[7]       = {1, 1, 1, 1, 1, 1, 1};
    size_t    staticSamplersCount                        = 0;
    size_t    structsMembersCount[7]                     = {};

    {
      const RedVisibleToStageBitflags visibleToStages = declaration.variablesVisibleToStages;
      if (visibleToStages != RED_VISIBLE_TO_STAGE_BITFLAG_COMPUTE) {
        theEntireProcedureParametersIsComputeOnly = 0;
      }
      if (visibleToStages != RED_VISIBLE_TO_STAGE_BITFLAG_VERTEX) {
        theEntireProcedureParametersIsVertexOnly = 0;
        variablesVisibleOnlyToStageVertex        = 0;
      }
      if (visibleToStages != RED_VISIBLE_TO_STAGE_BITFLAG_FRAGMENT) {
        theEntireProcedureParametersIsFragmentOnly = 0;
        variablesVisibleOnlyToStageFragment        = 0;
      }
      variablesTotalBytesCount += declaration.variablesBytesCount;
    }

    for (unsigned i = 0; i < declaration.structsDeclarationsCount; i += 1) {
      const RedXInternalTypeStructDeclaration * ihstructDeclaration = (const RedXInternalTypeStructDeclaration *)declaration.structsDeclarations[i];
      const size_t membersCount = ihstructDeclaration->structDeclarationMembers.size();
      for (size_t j = 0; j < membersCount; j += 1) {
        const RedStructDeclarationMember * member = &ihstructDeclaration->structDeclarationMembers[j];
        if (member->visibleToStages != RED_VISIBLE_TO_STAGE_BITFLAG_COMPUTE) {
          theEntireProcedureParametersIsComputeOnly = 0;
        }
        if (member->visibleToStages != RED_VISIBLE_TO_STAGE_BITFLAG_VERTEX) {
          theEntireProcedureParametersIsVertexOnly = 0;
          structsVisibleOnlyToStageVertex[i]       = 0;
        }
        if (member->visibleToStages != RED_VISIBLE_TO_STAGE_BITFLAG_FRAGMENT) {
          theEntireProcedureParametersIsFragmentOnly = 0;
          structsVisibleOnlyToStageFragment[i]       = 0;
        }
        if (member->type == RED_STRUCT_MEMBER_TYPE_SAMPLER && member->inlineSampler != 0) {
          staticSamplersCount += member->count;
        } else {
          structsMembersCount[i] += 1;
        }
      }
    }

    RedXInternalTypeStructDeclaration * ihhandlesDeclaration = (RedXInternalTypeStructDeclaration *)declaration.handlesDeclaration;
    size_t handlesCount = 0;
    if (ihhandlesDeclaration != 0) {
      handlesCount = ihhandlesDeclaration->structDeclarationMembers.size();

      for (size_t j = 0; j < handlesCount; j += 1) {
        const RedStructDeclarationMember * member = &ihhandlesDeclaration->structDeclarationMembers[j];
        if (member->visibleToStages != RED_VISIBLE_TO_STAGE_BITFLAG_COMPUTE) {
          theEntireProcedureParametersIsComputeOnly = 0;
        }
        if (member->visibleToStages != RED_VISIBLE_TO_STAGE_BITFLAG_VERTEX) {
          theEntireProcedureParametersIsVertexOnly = 0;
        }
        if (member->visibleToStages != RED_VISIBLE_TO_STAGE_BITFLAG_FRAGMENT) {
          theEntireProcedureParametersIsFragmentOnly = 0;
         }
      }
    }

    REDGPU_VECTOR<D3D12_ROOT_PARAMETER>      handles;
    REDGPU_VECTOR<D3D12_DESCRIPTOR_RANGE>    structs0Members;
    REDGPU_VECTOR<D3D12_DESCRIPTOR_RANGE>    structs1Members;
    REDGPU_VECTOR<D3D12_DESCRIPTOR_RANGE>    structs2Members;
    REDGPU_VECTOR<D3D12_DESCRIPTOR_RANGE>    structs3Members;
    REDGPU_VECTOR<D3D12_DESCRIPTOR_RANGE>    structs4Members;
    REDGPU_VECTOR<D3D12_DESCRIPTOR_RANGE>    structs5Members;
    REDGPU_VECTOR<D3D12_DESCRIPTOR_RANGE>    structs6Members;
    REDGPU_VECTOR<D3D12_STATIC_SAMPLER_DESC> staticSamplers;

    try {
      handles.resize(handlesCount);
      structs0Members.resize(structsMembersCount[0]);
      structs1Members.resize(structsMembersCount[1]);
      structs2Members.resize(structsMembersCount[2]);
      structs3Members.resize(structsMembersCount[3]);
      structs4Members.resize(structsMembersCount[4]);
      structs5Members.resize(structsMembersCount[5]);
      structs6Members.resize(structsMembersCount[6]);
      staticSamplers.resize(staticSamplersCount);
    } catch (...) {
      redInternalSetStatus(ctx, gpu, outStatuses, 2, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
      redInternalDestroyProcedureParameters((RedHandleProcedureParameters)ih, optionalFile, optionalLine);
      ih = 0;
      outProcedureParameters[0] = 0;
      PIXEndEvent();
      return;
    }

    D3D12_ROOT_PARAMETER variables = {};
    variables.ParameterType            = D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS;
    variables.Constants.ShaderRegister = 0;
    variables.Constants.RegisterSpace  = declaration.variablesSlot;
    variables.Constants.Num32BitValues = variablesTotalBytesCount / 4;
    variables.ShaderVisibility         = variablesVisibleOnlyToStageVertex == 1 ? D3D12_SHADER_VISIBILITY_VERTEX : (variablesVisibleOnlyToStageFragment == 1 ? D3D12_SHADER_VISIBILITY_PIXEL : D3D12_SHADER_VISIBILITY_ALL);

    if (ihhandlesDeclaration != 0) {
      for (unsigned i = 0; i < handlesCount; i += 1) {
        const RedStructDeclarationMember member = ihhandlesDeclaration->structDeclarationMembers[i];
        handles[i].ParameterType             = member.type == RED_STRUCT_MEMBER_TYPE_ARRAY_RO_CONSTANT ? D3D12_ROOT_PARAMETER_TYPE_CBV : (member.type == REDX_STRUCT_MEMBER_TYPE_ARRAY_RO ? D3D12_ROOT_PARAMETER_TYPE_SRV : D3D12_ROOT_PARAMETER_TYPE_UAV);
        handles[i].Descriptor.ShaderRegister = 0;
        handles[i].Descriptor.RegisterSpace  = member.slot;
        handles[i].ShaderVisibility          = member.visibleToStages == RED_VISIBLE_TO_STAGE_BITFLAG_VERTEX ? D3D12_SHADER_VISIBILITY_VERTEX : (member.visibleToStages == RED_VISIBLE_TO_STAGE_BITFLAG_FRAGMENT ? D3D12_SHADER_VISIBILITY_PIXEL : D3D12_SHADER_VISIBILITY_ALL);
      }
    }

    size_t staticSamplerIndex = 0;
    for (unsigned i = 0; i < declaration.structsDeclarationsCount; i += 1) {
      const RedXInternalTypeStructDeclaration * ihstructDeclaration = (const RedXInternalTypeStructDeclaration *)declaration.structsDeclarations[i];
      const size_t membersCount = ihstructDeclaration->structDeclarationMembers.size();
      size_t structMemberIndex = 0;
      for (size_t j = 0; j < membersCount; j += 1) {
        const RedStructDeclarationMember * member = &ihstructDeclaration->structDeclarationMembers[j];
        if (member->type == RED_STRUCT_MEMBER_TYPE_SAMPLER && member->inlineSampler != 0) {
          for (unsigned k = 0, kcount = member->count; k < kcount; k += 1) {
            const RedXInternalTypeSampler * ihsampler = (const RedXInternalTypeSampler *)member->inlineSampler[k];
            staticSamplers[staticSamplerIndex].Filter           = ihsampler->samplerDescription.Filter;
            staticSamplers[staticSamplerIndex].AddressU         = ihsampler->samplerDescription.AddressU;
            staticSamplers[staticSamplerIndex].AddressV         = ihsampler->samplerDescription.AddressV;
            staticSamplers[staticSamplerIndex].AddressW         = ihsampler->samplerDescription.AddressW;
            staticSamplers[staticSamplerIndex].MipLODBias       = ihsampler->samplerDescription.MipLODBias;
            staticSamplers[staticSamplerIndex].MaxAnisotropy    = ihsampler->samplerDescription.MaxAnisotropy;
            staticSamplers[staticSamplerIndex].ComparisonFunc   = ihsampler->samplerDescription.ComparisonFunc;
            staticSamplers[staticSamplerIndex].BorderColor      = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;
            staticSamplers[staticSamplerIndex].MinLOD           = ihsampler->samplerDescription.MinLOD;
            staticSamplers[staticSamplerIndex].MaxLOD           = ihsampler->samplerDescription.MaxLOD;
            staticSamplers[staticSamplerIndex].ShaderRegister   = k;
            staticSamplers[staticSamplerIndex].RegisterSpace    = member->slot;
            staticSamplers[staticSamplerIndex].ShaderVisibility = member->visibleToStages == RED_VISIBLE_TO_STAGE_BITFLAG_VERTEX ? D3D12_SHADER_VISIBILITY_VERTEX : (member->visibleToStages == RED_VISIBLE_TO_STAGE_BITFLAG_FRAGMENT ? D3D12_SHADER_VISIBILITY_PIXEL : D3D12_SHADER_VISIBILITY_ALL);
            staticSamplerIndex += 1;
          }
        } else {
          D3D12_DESCRIPTOR_RANGE_TYPE descriptorRangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
          if (member->type == RED_STRUCT_MEMBER_TYPE_ARRAY_RO_CONSTANT) {
            descriptorRangeType = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
          } else if (member->type == REDX_STRUCT_MEMBER_TYPE_ARRAY_RO) {
            descriptorRangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
          } else if (member->type == RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW) {
            descriptorRangeType = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
          } else if (member->type == RED_STRUCT_MEMBER_TYPE_SAMPLER) {
            descriptorRangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER;
          } else if (member->type == RED_STRUCT_MEMBER_TYPE_TEXTURE_RO) {
            descriptorRangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
          } else if (member->type == RED_STRUCT_MEMBER_TYPE_TEXTURE_RW) {
            descriptorRangeType = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
          }
          if (i == 0) {
            structs0Members[structMemberIndex].RangeType                         = descriptorRangeType;
            structs0Members[structMemberIndex].NumDescriptors                    = member->count;
            structs0Members[structMemberIndex].BaseShaderRegister                = 0;
            structs0Members[structMemberIndex].RegisterSpace                     = member->slot;
            structs0Members[structMemberIndex].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
          } else if (i == 1) {
            structs1Members[structMemberIndex].RangeType                         = descriptorRangeType;
            structs1Members[structMemberIndex].NumDescriptors                    = member->count;
            structs1Members[structMemberIndex].BaseShaderRegister                = 0;
            structs1Members[structMemberIndex].RegisterSpace                     = member->slot;
            structs1Members[structMemberIndex].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
          } else if (i == 2) {
            structs2Members[structMemberIndex].RangeType                         = descriptorRangeType;
            structs2Members[structMemberIndex].NumDescriptors                    = member->count;
            structs2Members[structMemberIndex].BaseShaderRegister                = 0;
            structs2Members[structMemberIndex].RegisterSpace                     = member->slot;
            structs2Members[structMemberIndex].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
          } else if (i == 3) {
            structs3Members[structMemberIndex].RangeType                         = descriptorRangeType;
            structs3Members[structMemberIndex].NumDescriptors                    = member->count;
            structs3Members[structMemberIndex].BaseShaderRegister                = 0;
            structs3Members[structMemberIndex].RegisterSpace                     = member->slot;
            structs3Members[structMemberIndex].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
          } else if (i == 4) {
            structs4Members[structMemberIndex].RangeType                         = descriptorRangeType;
            structs4Members[structMemberIndex].NumDescriptors                    = member->count;
            structs4Members[structMemberIndex].BaseShaderRegister                = 0;
            structs4Members[structMemberIndex].RegisterSpace                     = member->slot;
            structs4Members[structMemberIndex].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
          } else if (i == 5) {
            structs5Members[structMemberIndex].RangeType                         = descriptorRangeType;
            structs5Members[structMemberIndex].NumDescriptors                    = member->count;
            structs5Members[structMemberIndex].BaseShaderRegister                = 0;
            structs5Members[structMemberIndex].RegisterSpace                     = member->slot;
            structs5Members[structMemberIndex].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
          } else if (i == 6) {
            structs6Members[structMemberIndex].RangeType                         = descriptorRangeType;
            structs6Members[structMemberIndex].NumDescriptors                    = member->count;
            structs6Members[structMemberIndex].BaseShaderRegister                = 0;
            structs6Members[structMemberIndex].RegisterSpace                     = member->slot;
            structs6Members[structMemberIndex].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
          }
          structMemberIndex += 1;
        }
      }
    }

    D3D12_ROOT_PARAMETER structs0 = {};
    D3D12_ROOT_PARAMETER structs1 = {};
    D3D12_ROOT_PARAMETER structs2 = {};
    D3D12_ROOT_PARAMETER structs3 = {};
    D3D12_ROOT_PARAMETER structs4 = {};
    D3D12_ROOT_PARAMETER structs5 = {};
    D3D12_ROOT_PARAMETER structs6 = {};
    structs0.ParameterType                       = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    structs1.ParameterType                       = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    structs2.ParameterType                       = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    structs3.ParameterType                       = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    structs4.ParameterType                       = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    structs5.ParameterType                       = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    structs6.ParameterType                       = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    structs0.DescriptorTable.NumDescriptorRanges = (unsigned)structsMembersCount[0];
    structs1.DescriptorTable.NumDescriptorRanges = (unsigned)structsMembersCount[1];
    structs2.DescriptorTable.NumDescriptorRanges = (unsigned)structsMembersCount[2];
    structs3.DescriptorTable.NumDescriptorRanges = (unsigned)structsMembersCount[3];
    structs4.DescriptorTable.NumDescriptorRanges = (unsigned)structsMembersCount[4];
    structs5.DescriptorTable.NumDescriptorRanges = (unsigned)structsMembersCount[5];
    structs6.DescriptorTable.NumDescriptorRanges = (unsigned)structsMembersCount[6];
    structs0.DescriptorTable.pDescriptorRanges   = structsMembersCount[0] == 0 ? 0 : &structs0Members[0];
    structs1.DescriptorTable.pDescriptorRanges   = structsMembersCount[1] == 0 ? 0 : &structs1Members[0];
    structs2.DescriptorTable.pDescriptorRanges   = structsMembersCount[2] == 0 ? 0 : &structs2Members[0];
    structs3.DescriptorTable.pDescriptorRanges   = structsMembersCount[3] == 0 ? 0 : &structs3Members[0];
    structs4.DescriptorTable.pDescriptorRanges   = structsMembersCount[4] == 0 ? 0 : &structs4Members[0];
    structs5.DescriptorTable.pDescriptorRanges   = structsMembersCount[5] == 0 ? 0 : &structs5Members[0];
    structs6.DescriptorTable.pDescriptorRanges   = structsMembersCount[6] == 0 ? 0 : &structs6Members[0];
    structs0.ShaderVisibility                    = structsVisibleOnlyToStageVertex[0] == 1 ? D3D12_SHADER_VISIBILITY_VERTEX : (structsVisibleOnlyToStageFragment[0] == 1 ? D3D12_SHADER_VISIBILITY_PIXEL : D3D12_SHADER_VISIBILITY_ALL);
    structs1.ShaderVisibility                    = structsVisibleOnlyToStageVertex[1] == 1 ? D3D12_SHADER_VISIBILITY_VERTEX : (structsVisibleOnlyToStageFragment[1] == 1 ? D3D12_SHADER_VISIBILITY_PIXEL : D3D12_SHADER_VISIBILITY_ALL);
    structs2.ShaderVisibility                    = structsVisibleOnlyToStageVertex[2] == 1 ? D3D12_SHADER_VISIBILITY_VERTEX : (structsVisibleOnlyToStageFragment[2] == 1 ? D3D12_SHADER_VISIBILITY_PIXEL : D3D12_SHADER_VISIBILITY_ALL);
    structs3.ShaderVisibility                    = structsVisibleOnlyToStageVertex[3] == 1 ? D3D12_SHADER_VISIBILITY_VERTEX : (structsVisibleOnlyToStageFragment[3] == 1 ? D3D12_SHADER_VISIBILITY_PIXEL : D3D12_SHADER_VISIBILITY_ALL);
    structs4.ShaderVisibility                    = structsVisibleOnlyToStageVertex[4] == 1 ? D3D12_SHADER_VISIBILITY_VERTEX : (structsVisibleOnlyToStageFragment[4] == 1 ? D3D12_SHADER_VISIBILITY_PIXEL : D3D12_SHADER_VISIBILITY_ALL);
    structs5.ShaderVisibility                    = structsVisibleOnlyToStageVertex[5] == 1 ? D3D12_SHADER_VISIBILITY_VERTEX : (structsVisibleOnlyToStageFragment[5] == 1 ? D3D12_SHADER_VISIBILITY_PIXEL : D3D12_SHADER_VISIBILITY_ALL);
    structs6.ShaderVisibility                    = structsVisibleOnlyToStageVertex[6] == 1 ? D3D12_SHADER_VISIBILITY_VERTEX : (structsVisibleOnlyToStageFragment[6] == 1 ? D3D12_SHADER_VISIBILITY_PIXEL : D3D12_SHADER_VISIBILITY_ALL);

    unsigned               rootParametersCount = 0;
    D3D12_ROOT_PARAMETER * rootParameters      = new(std::nothrow) D3D12_ROOT_PARAMETER [1 + handlesCount + 7]();
    if (variablesTotalBytesCount != 0) {
      ih->rootParameterIndexStartVariables = rootParametersCount;
    }
    if (variablesTotalBytesCount != 0) {
      rootParameters[rootParametersCount] = variables;
      rootParametersCount += 1;
    }
    if (handlesCount > 0) {
      ih->rootParameterIndexStartHandles = rootParametersCount;
    }
    for (unsigned i = 0; i < handlesCount; i += 1) {
      rootParameters[rootParametersCount] = handles[i];
      rootParametersCount += 1;
    }
    if (declaration.structsDeclarationsCount > 0) {
      ih->rootParameterIndexStartStructs = rootParametersCount;
    }
    if (declaration.structsDeclarationsCount >= 1) {
      rootParameters[rootParametersCount] = structs0;
      rootParametersCount += 1;
    }
    if (declaration.structsDeclarationsCount >= 2) {
      rootParameters[rootParametersCount] = structs1;
      rootParametersCount += 1;
    }
    if (declaration.structsDeclarationsCount >= 3) {
      rootParameters[rootParametersCount] = structs2;
      rootParametersCount += 1;
    }
    if (declaration.structsDeclarationsCount >= 4) {
      rootParameters[rootParametersCount] = structs3;
      rootParametersCount += 1;
    }
    if (declaration.structsDeclarationsCount >= 5) {
      rootParameters[rootParametersCount] = structs4;
      rootParametersCount += 1;
    }
    if (declaration.structsDeclarationsCount >= 6) {
      rootParameters[rootParametersCount] = structs5;
      rootParametersCount += 1;
    }
    if (declaration.structsDeclarationsCount >= 7) {
      rootParameters[rootParametersCount] = structs6;
      rootParametersCount += 1;
    }

    D3D12_ROOT_SIGNATURE_FLAGS flags = D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS     |
                                       D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS   |
                                       D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS;
    if (theEntireProcedureParametersIsComputeOnly  == 1 &&
        theEntireProcedureParametersIsVertexOnly   == 1 &&
        theEntireProcedureParametersIsFragmentOnly == 1)
    {
    } else if (theEntireProcedureParametersIsComputeOnly == 1) {
      flags = D3D12_ROOT_SIGNATURE_FLAG_DENY_VERTEX_SHADER_ROOT_ACCESS   |
              D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS     |
              D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS   |
              D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS |
              D3D12_ROOT_SIGNATURE_FLAG_DENY_PIXEL_SHADER_ROOT_ACCESS;
    } else if (theEntireProcedureParametersIsVertexOnly == 1) {
      flags = D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS     |
              D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS   |
              D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS |
              D3D12_ROOT_SIGNATURE_FLAG_DENY_PIXEL_SHADER_ROOT_ACCESS;
    } else if (theEntireProcedureParametersIsFragmentOnly == 1) {
      flags = D3D12_ROOT_SIGNATURE_FLAG_DENY_VERTEX_SHADER_ROOT_ACCESS   |
              D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS     |
              D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS   |
              D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS;
    }

    D3D12_ROOT_SIGNATURE_DESC desc = {};
    desc.NumParameters     = rootParametersCount;
    desc.pParameters       = rootParameters;
    desc.NumStaticSamplers = (unsigned)staticSamplersCount;
    desc.pStaticSamplers   = &staticSamplers[0];
    desc.Flags             = flags;
    x12SerializeRootSignature(&desc, D3D_ROOT_SIGNATURE_VERSION_1, &ih->blob, &ih->blobError, optionalFile, optionalLine);

    delete[] rootParameters;
    rootParameters = 0;

    void * blobPointer    = x12BlobGetBufferPointer(ih->blob);
    size_t blobBytesCount = x12BlobGetBufferSize(ih->blob);
    x12DeviceCreateRootSignature((ID3D12Device3 *)gpu, 0, blobPointer, blobBytesCount, &ih->handle, optionalFile, optionalLine);
    if (ctx->internal.debugCallback != 0 && handleName != 0) {
      if (ih->handle != 0) {
        std::string  HandleNameA = handleName;
        std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
        x12ObjectSetName((ID3D12Object *)ih->handle, &handleNameW[0], optionalFile, optionalLine);
      }
    }
  }

  outProcedureParameters[0] = (RedHandleProcedureParameters)ih;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateProcedureCache(RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t fromBlobBytesCount, const void * fromBlob, RedHandleProcedureCache * outProcedureCache, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateProcedureCache;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;

  // TODO(Constantine): Implement procedure caching.
  outProcedureCache[0] = 0;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateProcedure(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, RedHandleOutputDeclaration outputDeclaration, RedHandleProcedureParameters procedureParameters, const char * gpuCodeVertexMainProcedureName, RedHandleGpuCode gpuCodeVertex, const char * gpuCodeFragmentMainProcedureName, RedHandleGpuCode gpuCodeFragment, const RedProcedureState * state, const void * stateExtension, RedBool32 deriveBase, RedHandleProcedure deriveFrom, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateProcedure;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext *   ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeProcedure * ih  = 0;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outProcedure[0] = 0;
    PIXEndEvent();
    return;
  }

  if (state->rasterizationDepthBiasDynamic != 0) {
    redInternalSetStatus(ctx, gpu, outStatuses, 4, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
  }

  if (state->depthTestBoundsTestDynamic != 0) {
    redInternalSetStatus(ctx, gpu, outStatuses, 5, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
  }

  if (state->stencilTestFrontAndBackDynamicCompareMask != 0) {
    redInternalSetStatus(ctx, gpu, outStatuses, 6, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
  }

  if (state->stencilTestFrontAndBackDynamicWriteMask != 0) {
    redInternalSetStatus(ctx, gpu, outStatuses, 7, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
  }

  ih = redInternalTypeProcedureAllocate(ctx, gpuIndex, handleName, procedureCache, outputDeclaration, procedureParameters, gpuCodeVertexMainProcedureName, gpuCodeVertex, gpuCodeFragmentMainProcedureName, gpuCodeFragment, "", 0, state, stateExtension, deriveBase, deriveFrom, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outProcedure[0] = 0;
    PIXEndEvent();
    return;
  }

  {
    RedXInternalTypeProcedureParameters * ihparameters             = (RedXInternalTypeProcedureParameters *)procedureParameters;
    unsigned *                            outputDeclarationFormats = (unsigned *)outputDeclaration;

    void *     vsPointer         = 0;
    uint64_t * vsPointerAsUInt64 = (uint64_t *)gpuCodeVertex;
    uint64_t   vsBytesCount      = vsPointerAsUInt64[0];
    vsPointerAsUInt64 += 1;
    vsPointer = (void *)vsPointerAsUInt64;

    void *   fsPointer    = 0;
    uint64_t fsBytesCount = 0;
    if (gpuCodeFragment != 0) {
      uint64_t * fsPointerAsUInt64 = (uint64_t *)gpuCodeFragment;
      fsBytesCount = fsPointerAsUInt64[0];
      fsPointerAsUInt64 += 1;
      fsPointer = (void *)fsPointerAsUInt64;
    }

    D3D12_GRAPHICS_PIPELINE_STATE_DESC desc = {};
    desc.pRootSignature                                   = ihparameters->handle;
    desc.VS.pShaderBytecode                               = vsPointer;
    desc.VS.BytecodeLength                                = vsBytesCount;
    desc.PS.pShaderBytecode                               = fsPointer;
    desc.PS.BytecodeLength                                = fsBytesCount;
    desc.BlendState.AlphaToCoverageEnable                 = state->multisampleAlphaToCoverageEnable;
    desc.BlendState.IndependentBlendEnable                = (
                                                            (state->outputColorsBlendEnable[0] == 1) ||
                                                            (state->outputColorsBlendEnable[1] == 1) ||
                                                            (state->outputColorsBlendEnable[2] == 1) ||
                                                            (state->outputColorsBlendEnable[3] == 1) ||
                                                            (state->outputColorsBlendEnable[4] == 1) ||
                                                            (state->outputColorsBlendEnable[5] == 1) ||
                                                            (state->outputColorsBlendEnable[6] == 1) ||
                                                            (state->outputColorsBlendEnable[7] == 1)
                                                            ) ? 1 : 0;
    for (unsigned i = 0; i < 8; i += 1) {
    desc.BlendState.RenderTarget[i].BlendEnable           = state->outputColorsBlendEnable[i];
    desc.BlendState.RenderTarget[i].LogicOpEnable         = state->blendLogicOpEnable;
    desc.BlendState.RenderTarget[i].SrcBlend              = redInternalREDGPUBlendFactorToD3D12Blend(state->outputColorsBlendColorFactorSource[i]);
    desc.BlendState.RenderTarget[i].DestBlend             = redInternalREDGPUBlendFactorToD3D12Blend(state->outputColorsBlendColorFactorTarget[i]);
    desc.BlendState.RenderTarget[i].BlendOp               = redInternalREDGPUBlendOpToD3D12BlendOp(state->outputColorsBlendColorOp[i]);
    desc.BlendState.RenderTarget[i].SrcBlendAlpha         = redInternalREDGPUBlendFactorToD3D12Blend(state->outputColorsBlendAlphaFactorSource[i]);
    desc.BlendState.RenderTarget[i].DestBlendAlpha        = redInternalREDGPUBlendFactorToD3D12Blend(state->outputColorsBlendAlphaFactorTarget[i]);
    desc.BlendState.RenderTarget[i].BlendOpAlpha          = redInternalREDGPUBlendOpToD3D12BlendOp(state->outputColorsBlendAlphaOp[i]);
    desc.BlendState.RenderTarget[i].LogicOp               = redInternalREDGPULogicOpToD3D12LogicOp(state->blendLogicOp);
    desc.BlendState.RenderTarget[i].RenderTargetWriteMask = (D3D12_COLOR_WRITE_ENABLE)state->outputColorsWriteMask[i];
    }
    desc.SampleMask                                       = state->multisampleSampleMask != 0 ? state->multisampleSampleMask[0] : UINT_MAX;
    desc.RasterizerState.FillMode                         = D3D12_FILL_MODE_SOLID;
    desc.RasterizerState.CullMode                         = redInternalREDGPUCullModeToD3D12CullMode(state->rasterizationCullMode);
    desc.RasterizerState.FrontCounterClockwise            = state->rasterizationFrontFace == RED_FRONT_FACE_COUNTER_CLOCKWISE ? 1 : 0;
    desc.RasterizerState.DepthBias                        = state->rasterizationDepthBiasEnable == 1 ? (INT)state->rasterizationDepthBiasStaticConstantFactor : 0;
    desc.RasterizerState.DepthBiasClamp                   = state->rasterizationDepthBiasEnable == 1 ? state->rasterizationDepthBiasStaticClamp : 0;
    desc.RasterizerState.SlopeScaledDepthBias             = state->rasterizationDepthBiasEnable == 1 ? state->rasterizationDepthBiasStaticSlopeFactor : 0;
    desc.RasterizerState.DepthClipEnable                  = state->rasterizationDepthClampEnable == 1 ? 0 : 1;
    desc.RasterizerState.MultisampleEnable                = state->multisampleCount == RED_MULTISAMPLE_COUNT_BITFLAG_1 ? 0 : 1;
    desc.RasterizerState.AntialiasedLineEnable            = 0;
    desc.RasterizerState.ForcedSampleCount                = 0;
    desc.RasterizerState.ConservativeRaster               = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
    desc.DepthStencilState.DepthEnable                    = state->depthTestEnable;
    desc.DepthStencilState.DepthWriteMask                 = state->depthTestDepthWriteEnable == 1 ? D3D12_DEPTH_WRITE_MASK_ALL : D3D12_DEPTH_WRITE_MASK_ZERO;
    desc.DepthStencilState.DepthFunc                      = redInternalREDGPUCompareOpToD3D12ComparisonFunc(state->depthTestDepthCompareOp);
    desc.DepthStencilState.StencilEnable                  = state->stencilTestEnable;
    desc.DepthStencilState.StencilReadMask                = (UINT8)state->stencilTestFrontAndBackStaticCompareMask;
    desc.DepthStencilState.StencilWriteMask               = (UINT8)state->stencilTestFrontAndBackStaticWriteMask;
    desc.DepthStencilState.FrontFace.StencilFailOp        = redInternalREDGPUStencilOpToD3D12StencilOp(state->stencilTestFrontStencilTestFailOp);
    desc.DepthStencilState.FrontFace.StencilDepthFailOp   = redInternalREDGPUStencilOpToD3D12StencilOp(state->stencilTestFrontStencilTestPassDepthTestFailOp);
    desc.DepthStencilState.FrontFace.StencilPassOp        = redInternalREDGPUStencilOpToD3D12StencilOp(state->stencilTestFrontStencilTestPassDepthTestPassOp);
    desc.DepthStencilState.FrontFace.StencilFunc          = redInternalREDGPUCompareOpToD3D12ComparisonFunc(state->stencilTestFrontCompareOp);
    desc.DepthStencilState.BackFace.StencilFailOp         = redInternalREDGPUStencilOpToD3D12StencilOp(state->stencilTestBackStencilTestFailOp);
    desc.DepthStencilState.BackFace.StencilDepthFailOp    = redInternalREDGPUStencilOpToD3D12StencilOp(state->stencilTestBackStencilTestPassDepthTestFailOp);
    desc.DepthStencilState.BackFace.StencilPassOp         = redInternalREDGPUStencilOpToD3D12StencilOp(state->stencilTestBackStencilTestPassDepthTestPassOp);
    desc.DepthStencilState.BackFace.StencilFunc           = redInternalREDGPUCompareOpToD3D12ComparisonFunc(state->stencilTestBackCompareOp);
    desc.IBStripCutValue                                  = state->inputAssemblyPrimitiveRestartEnable == 1 ? D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFFFFFF : D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED;
    desc.PrimitiveTopologyType                            = redInternalREDGPUPrimitiveTopologyToD3D12PrimitiveTopologyType(state->inputAssemblyTopology);
    desc.NumRenderTargets                                 = state->outputColorsCount;
    desc.RTVFormats[0]                                    = redInternalREDGPUFormatToD3D12Format(outputDeclarationFormats[0]);
    desc.RTVFormats[1]                                    = redInternalREDGPUFormatToD3D12Format(outputDeclarationFormats[1]);
    desc.RTVFormats[2]                                    = redInternalREDGPUFormatToD3D12Format(outputDeclarationFormats[2]);
    desc.RTVFormats[3]                                    = redInternalREDGPUFormatToD3D12Format(outputDeclarationFormats[3]);
    desc.RTVFormats[4]                                    = redInternalREDGPUFormatToD3D12Format(outputDeclarationFormats[4]);
    desc.RTVFormats[5]                                    = redInternalREDGPUFormatToD3D12Format(outputDeclarationFormats[5]);
    desc.RTVFormats[6]                                    = redInternalREDGPUFormatToD3D12Format(outputDeclarationFormats[6]);
    desc.RTVFormats[7]                                    = redInternalREDGPUFormatToD3D12Format(outputDeclarationFormats[7]);
    desc.DSVFormat                                        = redInternalREDGPUFormatToD3D12Format(outputDeclarationFormats[8]);
    desc.SampleDesc.Count                                 = redInternalREDGPUMultisampleCountToUnsignedValue(state->multisampleCount);
    desc.SampleDesc.Quality                               = 0;
    desc.NodeMask                                         = 0;
    desc.CachedPSO.pCachedBlob                            = 0; // TODO(Constantine): Implement procedure caching.
    desc.CachedPSO.CachedBlobSizeInBytes                  = 0; // TODO(Constantine): Implement procedure caching.
    desc.Flags                                            = D3D12_PIPELINE_STATE_FLAG_NONE;
    HRESULT hr = x12DeviceCreateGraphicsPipelineState((ID3D12Device3 *)gpu, &desc, &ih->handle, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyProcedure((RedHandleProcedure)ih, optionalFile, optionalLine);
      ih = 0;
      outProcedure[0] = 0;
      PIXEndEvent();
      return;
    }
    if (ctx->internal.debugCallback != 0 && handleName != 0) {
      if (ih->handle != 0) {
        std::string  HandleNameA = handleName;
        std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
        x12ObjectSetName((ID3D12Object *)ih->handle, &handleNameW[0], optionalFile, optionalLine);
      }
    }
  }

  outProcedure[0] = (RedHandleProcedure)ih;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateProcedureCompute(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, RedHandleProcedureParameters procedureParameters, const char * gpuCodeMainProcedureName, RedHandleGpuCode gpuCode, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateProcedureCompute;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext *   ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeProcedure * ih  = 0;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outProcedure[0] = 0;
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeProcedureAllocate(ctx, gpuIndex, handleName, procedureCache, 0, procedureParameters, "", 0, "", 0, gpuCodeMainProcedureName, gpuCode, 0, 0, 0, 0, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outProcedure[0] = 0;
    PIXEndEvent();
    return;
  }

  {
    RedXInternalTypeProcedureParameters * ihparameters = (RedXInternalTypeProcedureParameters *)procedureParameters;

    void *     csPointer         = 0;
    uint64_t * csPointerAsUInt64 = (uint64_t *)gpuCode;
    uint64_t   csBytesCount      = csPointerAsUInt64[0];
    csPointerAsUInt64 += 1;
    csPointer = (void *)csPointerAsUInt64;

    D3D12_COMPUTE_PIPELINE_STATE_DESC desc = {};
    desc.pRootSignature                  = ihparameters->handle;
    desc.CS.pShaderBytecode              = csPointer;
    desc.CS.BytecodeLength               = csBytesCount;
    desc.NodeMask                        = 0;
    desc.CachedPSO.pCachedBlob           = 0; // TODO(Constantine): Implement procedure caching.
    desc.CachedPSO.CachedBlobSizeInBytes = 0; // TODO(Constantine): Implement procedure caching.
    desc.Flags                           = D3D12_PIPELINE_STATE_FLAG_NONE;
    HRESULT hr = x12DeviceCreateComputePipelineState((ID3D12Device3 *)gpu, &desc, &ih->handle, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyProcedure((RedHandleProcedure)ih, optionalFile, optionalLine);
      ih = 0;
      outProcedure[0] = 0;
      PIXEndEvent();
      return;
    }
    if (ctx->internal.debugCallback != 0 && handleName != 0) {
      if (ih->handle != 0) {
        std::string  HandleNameA = handleName;
        std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
        x12ObjectSetName((ID3D12Object *)ih->handle, &handleNameW[0], optionalFile, optionalLine);
      }
    }
  }

  outProcedure[0] = (RedHandleProcedure)ih;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateOutput(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleOutputDeclaration outputDeclaration, const RedOutputMembers * outputMembers, const RedOutputMembersResolveTargets * outputMembersResolveTargets, unsigned width, unsigned height, RedOutput * outOutput, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateOutput;
  PIXBeginEvent(0, __FUNCTION__);

  unsigned * ihoutputDeclaration = (unsigned *)outputDeclaration;
  RedBool32  depthStencilEnable  = 0;
  unsigned   colorsCount         = 0;

  if (ihoutputDeclaration != 0) {
    if        (ihoutputDeclaration[8] != RED_FORMAT_UNDEFINED) {
      depthStencilEnable = 1;
    }
    if        (ihoutputDeclaration[7] != RED_FORMAT_UNDEFINED) {
      colorsCount = 8;
    } else if (ihoutputDeclaration[6] != RED_FORMAT_UNDEFINED) {
      colorsCount = 7;
    } else if (ihoutputDeclaration[5] != RED_FORMAT_UNDEFINED) {
      colorsCount = 6;
    } else if (ihoutputDeclaration[4] != RED_FORMAT_UNDEFINED) {
      colorsCount = 5;
    } else if (ihoutputDeclaration[3] != RED_FORMAT_UNDEFINED) {
      colorsCount = 4;
    } else if (ihoutputDeclaration[2] != RED_FORMAT_UNDEFINED) {
      colorsCount = 3;
    } else if (ihoutputDeclaration[1] != RED_FORMAT_UNDEFINED) {
      colorsCount = 2;
    } else if (ihoutputDeclaration[0] != RED_FORMAT_UNDEFINED) {
      colorsCount = 1;
    }
  }

  outOutput[0].handle             = (RedHandleOutput)0x1;
  outOutput[0].width              = width;
  outOutput[0].height             = height;
  outOutput[0].depthStencilEnable = depthStencilEnable;
  outOutput[0].colorsCount        = colorsCount;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateCpuSignal(RedContext context, RedHandleGpu gpu, const char * handleName, RedBool32 createSignaled, RedHandleCpuSignal * outCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateCpuSignal;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeSignal *  ih  = 0;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outCpuSignal[0] = 0;
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeSignalAllocate(ctx, gpuIndex, handleName, 0, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outCpuSignal[0] = 0;
    PIXEndEvent();
    return;
  }

  x12DeviceCreateFence((ID3D12Device3 *)gpu, 0, D3D12_FENCE_FLAG_NONE, &ih->handle, optionalFile, optionalLine);

  if (ctx->internal.debugCallback != 0 && handleName != 0) {
    if (ih->handle != 0) {
      std::string  HandleNameA = handleName;
      std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
      x12ObjectSetName((ID3D12Object *)ih->handle, &handleNameW[0], optionalFile, optionalLine);
    }
  }

  outCpuSignal[0] = (RedHandleCpuSignal)ih;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateGpuSignal(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleGpuSignal * outGpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateGpuSignal;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeSignal *  ih  = 0;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outGpuSignal[0] = 0;
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeSignalAllocate(ctx, gpuIndex, handleName, 0, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outGpuSignal[0] = 0;
    PIXEndEvent();
    return;
  }

  x12DeviceCreateFence((ID3D12Device3 *)gpu, 0, D3D12_FENCE_FLAG_NONE, &ih->handle, optionalFile, optionalLine);

  if (ctx->internal.debugCallback != 0 && handleName != 0) {
    if (ih->handle != 0) {
      std::string  HandleNameA = handleName;
      std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
      x12ObjectSetName((ID3D12Object *)ih->handle, &handleNameW[0], optionalFile, optionalLine);
    }
  }

  outGpuSignal[0] = (RedHandleGpuSignal)ih;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateGpuToCpuSignal(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleGpuToCpuSignal * outGpuToCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateGpuToCpuSignal;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeSignal *  ih  = 0;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outGpuToCpuSignal[0] = 0;
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeSignalAllocate(ctx, gpuIndex, handleName, 0, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outGpuToCpuSignal[0] = 0;
    PIXEndEvent();
    return;
  }

  x12DeviceCreateFence((ID3D12Device3 *)gpu, 0, D3D12_FENCE_FLAG_NONE, &ih->handle, optionalFile, optionalLine);

  if (ctx->internal.debugCallback != 0 && handleName != 0) {
    if (ih->handle != 0) {
      std::string  HandleNameA = handleName;
      std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
      x12ObjectSetName((ID3D12Object *)ih->handle, &handleNameW[0], optionalFile, optionalLine);
    }
  }

  outGpuToCpuSignal[0] = (RedHandleGpuToCpuSignal)ih;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateCalls(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, RedCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateCalls;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeCalls *   ih  = 0;

  const unsigned queueFamilyIndex0Direct  = 0;
  const unsigned queueFamilyIndex1Compute = 1;
  const unsigned queueFamilyIndex2Copy    = 2;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outCalls[0].handle   = 0;
    outCalls[0].memory   = 0;
    outCalls[0].reusable = 0;
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeCallsAllocate(ctx, gpuIndex, handleName, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outCalls[0].handle   = 0;
    outCalls[0].memory   = 0;
    outCalls[0].reusable = 0;
    PIXEndEvent();
    return;
  }

  {
    D3D12_COMMAND_LIST_TYPE x12listType = D3D12_COMMAND_LIST_TYPE_DIRECT;
    if (queueFamilyIndex == queueFamilyIndex0Direct) {
      x12listType = D3D12_COMMAND_LIST_TYPE_DIRECT;
    } else if (queueFamilyIndex == queueFamilyIndex1Compute) {
      x12listType = D3D12_COMMAND_LIST_TYPE_COMPUTE;
    } else if (queueFamilyIndex == queueFamilyIndex2Copy) {
      x12listType = D3D12_COMMAND_LIST_TYPE_COPY;
    }

    HRESULT hr = S_OK;
    hr = x12DeviceCreateCommandAllocator((ID3D12Device3 *)gpu, x12listType, &ih->memory, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyCalls((RedHandleCallsMemory)ih, optionalFile, optionalLine);
      ih = 0;
      outCalls[0].handle   = 0;
      outCalls[0].memory   = 0;
      outCalls[0].reusable = 0;
      PIXEndEvent();
      return;
    }
    if (ctx->internal.d3dFeatureLevel >= 0xc100) { // D3D_FEATURE_LEVEL_12_1
      hr = x12DeviceCreateCommandList4((ID3D12Device5 *)gpu, 0, x12listType, ih->memory, 0, (ID3D12GraphicsCommandList4 **)&ih->handle, optionalFile, optionalLine);
    } else {
      hr = x12DeviceCreateCommandList((ID3D12Device3 *)gpu, 0, x12listType, ih->memory, 0, (ID3D12GraphicsCommandList **)&ih->handle, optionalFile, optionalLine);
    }
    if (hr < 0) {
      redInternalDestroyCalls((RedHandleCallsMemory)ih, optionalFile, optionalLine);
      ih = 0;
      outCalls[0].handle   = 0;
      outCalls[0].memory   = 0;
      outCalls[0].reusable = 0;
      PIXEndEvent();
      return;
    }
    hr = x12CommandListClose(ih->handle, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyCalls((RedHandleCallsMemory)ih, optionalFile, optionalLine);
      ih = 0;
      outCalls[0].handle   = 0;
      outCalls[0].memory   = 0;
      outCalls[0].reusable = 0;
      PIXEndEvent();
      return;
    }

    if (ctx->internal.debugCallback != 0 && handleName != 0) {
      std::string  HandleNameA = handleName;
      std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
      if (ih->memory != 0) { x12ObjectSetName((ID3D12Object *)ih->memory, &handleNameW[0], optionalFile, optionalLine); }
      if (ih->handle != 0) { x12ObjectSetName((ID3D12Object *)ih->handle, &handleNameW[0], optionalFile, optionalLine); }
    }
  }

  outCalls[0].handle   = (RedHandleCalls)ih;
  outCalls[0].memory   = (RedHandleCallsMemory)ih;
  outCalls[0].reusable = 0;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateCallsReusable(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, RedCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateCallsReusable;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeCalls *   ih  = 0;

  const unsigned queueFamilyIndex0Direct  = 0;
  const unsigned queueFamilyIndex1Compute = 1;
  const unsigned queueFamilyIndex2Copy    = 2;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outCalls[0].handle   = 0;
    outCalls[0].memory   = 0;
    outCalls[0].reusable = 1;
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeCallsAllocate(ctx, gpuIndex, handleName, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outCalls[0].handle   = 0;
    outCalls[0].memory   = 0;
    outCalls[0].reusable = 1;
    PIXEndEvent();
    return;
  }

  {
    D3D12_COMMAND_LIST_TYPE x12listType = D3D12_COMMAND_LIST_TYPE_DIRECT;
    if (queueFamilyIndex == queueFamilyIndex0Direct) {
      x12listType = D3D12_COMMAND_LIST_TYPE_DIRECT;
    } else if (queueFamilyIndex == queueFamilyIndex1Compute) {
      x12listType = D3D12_COMMAND_LIST_TYPE_COMPUTE;
    } else if (queueFamilyIndex == queueFamilyIndex2Copy) {
      x12listType = D3D12_COMMAND_LIST_TYPE_COPY;
    }

    HRESULT hr = S_OK;
    hr = x12DeviceCreateCommandAllocator((ID3D12Device3 *)gpu, x12listType, &ih->memory, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyCalls((RedHandleCallsMemory)ih, optionalFile, optionalLine);
      ih = 0;
      outCalls[0].handle   = 0;
      outCalls[0].memory   = 0;
      outCalls[0].reusable = 1;
      PIXEndEvent();
      return;
    }
    if (ctx->internal.d3dFeatureLevel >= 0xc100) { // D3D_FEATURE_LEVEL_12_1
      hr = x12DeviceCreateCommandList4((ID3D12Device5 *)gpu, 0, x12listType, ih->memory, 0, (ID3D12GraphicsCommandList4 **)&ih->handle, optionalFile, optionalLine);
    } else {
      hr = x12DeviceCreateCommandList((ID3D12Device3 *)gpu, 0, x12listType, ih->memory, 0, (ID3D12GraphicsCommandList **)&ih->handle, optionalFile, optionalLine);
    }
    if (hr < 0) {
      redInternalDestroyCalls((RedHandleCallsMemory)ih, optionalFile, optionalLine);
      ih = 0;
      outCalls[0].handle   = 0;
      outCalls[0].memory   = 0;
      outCalls[0].reusable = 1;
      PIXEndEvent();
      return;
    }
    hr = x12CommandListClose(ih->handle, optionalFile, optionalLine);
    if (hr < 0) {
      redInternalDestroyCalls((RedHandleCallsMemory)ih, optionalFile, optionalLine);
      ih = 0;
      outCalls[0].handle   = 0;
      outCalls[0].memory   = 0;
      outCalls[0].reusable = 1;
      PIXEndEvent();
      return;
    }

    if (ctx->internal.debugCallback != 0 && handleName != 0) {
      std::string  HandleNameA = handleName;
      std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
      if (ih->memory != 0) { x12ObjectSetName((ID3D12Object *)ih->memory, &handleNameW[0], optionalFile, optionalLine); }
      if (ih->handle != 0) { x12ObjectSetName((ID3D12Object *)ih->handle, &handleNameW[0], optionalFile, optionalLine); }
    }
  }

  outCalls[0].handle   = (RedHandleCalls)ih;
  outCalls[0].memory   = (RedHandleCallsMemory)ih;
  outCalls[0].reusable = 1;

  PIXEndEvent();
}

__declspec(dllexport) void redDestroyArray(RedContext context, RedHandleGpu gpu, RedHandleArray array, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyArray;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyArray(array, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyImage(RedContext context, RedHandleGpu gpu, RedHandleImage image, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyImage;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyImage(image, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroySampler(RedContext context, RedHandleGpu gpu, RedHandleSampler sampler, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroySampler;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroySampler(sampler, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyTexture(RedContext context, RedHandleGpu gpu, RedHandleTexture texture, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyTexture;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyTexture(texture, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyGpuCode(RedContext context, RedHandleGpu gpu, RedHandleGpuCode gpuCode, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyGpuCode;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyGpuCode(gpuCode, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyOutputDeclaration(RedContext context, RedHandleGpu gpu, RedHandleOutputDeclaration outputDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyOutputDeclaration;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyOutputDeclaration(outputDeclaration, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyStructDeclaration(RedContext context, RedHandleGpu gpu, RedHandleStructDeclaration structDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyStructDeclaration;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyStructDeclaration(structDeclaration, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyProcedureParameters(RedContext context, RedHandleGpu gpu, RedHandleProcedureParameters procedureParameters, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyProcedureParameters;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyProcedureParameters(procedureParameters, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyProcedureCache(RedContext context, RedHandleGpu gpu, RedHandleProcedureCache procedureCache, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyProcedureCache;
  PIXBeginEvent(0, __FUNCTION__);
  // TODO(Constantine): Implement procedure caching.
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyProcedure(RedContext context, RedHandleGpu gpu, RedHandleProcedure procedure, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyProcedure;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyProcedure(procedure, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyOutput(RedContext context, RedHandleGpu gpu, RedHandleOutput output, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyOutput;
  PIXBeginEvent(0, __FUNCTION__);
  volatile int x = 0;
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyCpuSignal(RedContext context, RedHandleGpu gpu, RedHandleCpuSignal cpuSignal, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyCpuSignal;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyCpuSignal(cpuSignal, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyGpuSignal(RedContext context, RedHandleGpu gpu, RedHandleGpuSignal gpuSignal, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyGpuSignal;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyGpuSignal(gpuSignal, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyGpuToCpuSignal(RedContext context, RedHandleGpu gpu, RedHandleGpuToCpuSignal gpuToCpuSignal, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyGpuToCpuSignal;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyGpuToCpuSignal(gpuToCpuSignal, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyCalls(RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedHandleCallsMemory callsMemory, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyCalls;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyCalls(callsMemory, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redProcedureCacheGetBlob(RedContext context, RedHandleGpu gpu, RedHandleProcedureCache procedureCache, uint64_t * outBlobBytesCount, void * outBlob, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redProcedureCacheGetBlob;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;

  // TODO(Constantine): Implement procedure caching.
  if (outBlobBytesCount != 0) {
    outBlobBytesCount[0] = 0;
  }

  PIXEndEvent();
}

__declspec(dllexport) void redProcedureCacheMergeCaches(RedContext context, RedHandleGpu gpu, unsigned sourceProcedureCachesCount, const RedHandleProcedureCache * sourceProcedureCaches, RedHandleProcedureCache targetProcedureCache, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redProcedureCacheMergeCaches;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  // TODO(Constantine): Implement procedure caching.
  PIXEndEvent();
}

__declspec(dllexport) void redCpuSignalGetStatus(RedContext context, RedHandleGpu gpu, RedHandleCpuSignal cpuSignal, RedStatus * outStatus, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCpuSignalGetStatus;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeSignal *  ih  = (RedXInternalTypeSignal *)cpuSignal;
  uint64_t value = x12FenceGetCompletedValue(ih->handle, optionalFile, optionalLine);
  outStatus[0] = value < ih->value ? RED_STATUS_NOT_READY : RED_STATUS_SUCCESS;
  PIXEndEvent();
}

__declspec(dllexport) void redCpuSignalWait(RedContext context, RedHandleGpu gpu, unsigned cpuSignalsCount, const RedHandleCpuSignal * cpuSignals, RedBool32 waitAll, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCpuSignalWait;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeSignal ** ihs = (RedXInternalTypeSignal **)cpuSignals;

  if (cpuSignalsCount == 0) {
    PIXEndEvent();
    return;
  }

  if (cpuSignalsCount <= 32) {
    ID3D12Fence * signals[32] = {};
    uint64_t      waitfor[32] = {};
    for (unsigned i = 0; i < cpuSignalsCount; i += 1) {
      signals[i] = ihs[i]->handle;
      waitfor[i] = ihs[i]->value;
    }
    x12DeviceSetEventOnMultipleFenceCompletion((ID3D12Device3 *)gpu, signals, waitfor, cpuSignalsCount, waitAll == 0 ? D3D12_MULTIPLE_FENCE_WAIT_FLAG_ANY : D3D12_MULTIPLE_FENCE_WAIT_FLAG_ALL, 0, optionalFile, optionalLine);
  } else {
    REDGPU_VECTOR<ID3D12Fence *> signals;
    REDGPU_VECTOR<uint64_t>      waitfor;
    try {
      waitfor.resize(cpuSignalsCount);
    } catch (...) {
      redInternalSetStatus(ctx, gpu, outStatuses, 1, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
      PIXEndEvent();
      return;
    }
    for (unsigned i = 0; i < cpuSignalsCount; i += 1) {
      signals[i] = ihs[i]->handle;
      waitfor[i] = ihs[i]->value;
    }
    x12DeviceSetEventOnMultipleFenceCompletion((ID3D12Device3 *)gpu, &signals[0], &waitfor[0], cpuSignalsCount, waitAll == 0 ? D3D12_MULTIPLE_FENCE_WAIT_FLAG_ANY : D3D12_MULTIPLE_FENCE_WAIT_FLAG_ALL, 0, optionalFile, optionalLine);
  }

  PIXEndEvent();
}

__declspec(dllexport) void redCpuSignalUnsignal(RedContext context, RedHandleGpu gpu, unsigned cpuSignalsCount, const RedHandleCpuSignal * cpuSignals, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCpuSignalUnsignal;
  PIXBeginEvent(0, __FUNCTION__);
  PIXEndEvent();
}

__declspec(dllexport) void redGpuToCpuSignalGetStatus(RedContext context, RedHandleGpu gpu, RedHandleGpuToCpuSignal gpuToCpuSignal, RedStatus * outStatus, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redGpuToCpuSignalGetStatus;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeSignal *  ih  = (RedXInternalTypeSignal *)gpuToCpuSignal;
  uint64_t value = x12FenceGetCompletedValue(ih->handle, optionalFile, optionalLine);
  outStatus[0] = value < ih->value ? RED_STATUS_NOT_READY : RED_STATUS_SUCCESS;
  PIXEndEvent();
}

__declspec(dllexport) void redGpuToCpuSignalUnsignal(RedContext context, RedHandleGpu gpu, RedHandleGpuToCpuSignal gpuToCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redGpuToCpuSignalUnsignal;
  PIXBeginEvent(0, __FUNCTION__);
  PIXEndEvent();
}

__declspec(dllexport) RedXHandlePageable redXGetHandlePageableMemory(RedContext context, RedHandleGpu gpu, RedHandleMemory memory) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXGetHandlePageableMemory;
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeMemory *  ih  = (RedXInternalTypeMemory *)memory;
  return (RedXHandlePageable)ih->handle;
}

__declspec(dllexport) RedXHandlePageable redXGetHandlePageableStructsMemory(RedContext context, RedHandleGpu gpu, RedHandleStructsMemory structsMemory) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXGetHandlePageableStructsMemory;
  RedXInternalTypeContext *       ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeStructsMemory * ih  = (RedXInternalTypeStructsMemory *)structsMemory;
  return (RedXHandlePageable)ih->handle;
}

__declspec(dllexport) void redXPageableSetResidencyPriority(RedContext context, RedHandleGpu gpu, unsigned pageablesCount, const RedXHandlePageable * pageables, const RedXPageableResidencyPriorityBitflags * pageablesResidencyPriority, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXPageableSetResidencyPriority;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  x12DeviceSetResidencyPriority((ID3D12Device3 *)gpu, pageablesCount, (ID3D12Pageable * const *)pageables, (const UINT *)pageablesResidencyPriority, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redXPageableMakeResident(RedContext context, RedHandleGpu gpu, unsigned pageablesCount, const RedXHandlePageable * pageables, RedBool32 denyOverbudget, RedHandleCpuSignal signalCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXPageableMakeResident;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeSignal *  ih  = (RedXInternalTypeSignal *)signalCpuSignal;
  if (signalCpuSignal == 0) {
    x12DeviceMakeResident((ID3D12Device3 *)gpu, pageablesCount, (ID3D12Pageable * const *)pageables, optionalFile, optionalLine);
  } else {
    ih->value += 1;
    x12DeviceEnqueueMakeResident((ID3D12Device3 *)gpu, denyOverbudget == 1 ? D3D12_RESIDENCY_FLAG_DENY_OVERBUDGET : D3D12_RESIDENCY_FLAG_NONE, pageablesCount, (ID3D12Pageable * const *)pageables, ih->handle, ih->value, optionalFile, optionalLine);
  }
  PIXEndEvent();
}

__declspec(dllexport) void redXPageableEvict(RedContext context, RedHandleGpu gpu, unsigned pageablesCount, const RedXHandlePageable * pageables, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXPageableEvict;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  x12DeviceEvict((ID3D12Device3 *)gpu, pageablesCount, (ID3D12Pageable * const *)pageables, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) RedXHandleResource redXGetHandleResourceArray(RedContext context, RedHandleGpu gpu, RedHandleArray array) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXGetHandleResourceArray;
  RedXInternalTypeArray * ih = (RedXInternalTypeArray *)array;
  RedXHandleResource      h  = (RedXHandleResource)ih->handle;
  return h;
}

__declspec(dllexport) RedXHandleResource redXGetHandleResourceImage(RedContext context, RedHandleGpu gpu, RedHandleImage image) {
  const RedXProcedureId procedureId = REDX_PROCEDURE_ID_redXGetHandleResourceImage;
  RedXInternalTypeImage * ih = (RedXInternalTypeImage *)image;
  RedXHandleResource      h  = (RedXHandleResource)ih->handle;
  return h;
}

__declspec(dllexport) void redCallsSet(RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedHandleCallsMemory callsMemory, RedBool32 callsReusable, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCallsSet;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeCalls *   ih  = (RedXInternalTypeCalls *)callsMemory;
  const RedStatuses _0 = {};
  ih->statuses = _0;
  if (ih->gpuToCpuSignalsToSignalCount > 0) {
    try {
      ih->gpuToCpuSignalsToSignal.clear();
    } catch (...) {
      redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    }
    ih->gpuToCpuSignalsToSignalCount = 0;
  }
  x12CommandAllocatorReset(ih->memory, optionalFile, optionalLine);
  x12CommandListReset(ih->handle, ih->memory, 0, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redCallsEnd(RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedHandleCallsMemory callsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCallsEnd;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeCalls *   ih  = (RedXInternalTypeCalls *)calls;
  redInternalSetStatus(ctx, gpu, outStatuses, ih->statuses.statusErrorCode, ih->statuses.statusError, ih->statuses.statusErrorProcedureId, optionalFile, optionalLine, ih->statuses.statusErrorHresult, ih->statuses.statusErrorDescription);
  x12CommandListClose(ih->handle, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redCallSetStructsMemory(RedTypeProcedureAddressCallSetStructsMemory address, RedHandleCalls calls, RedHandleStructsMemory structsMemory, RedHandleStructsMemory structsMemorySamplers) {
  RedXInternalTypeCalls *         ih                      = (RedXInternalTypeCalls *)calls;
  RedXInternalTypeStructsMemory * ihstructsMemory         = (RedXInternalTypeStructsMemory *)structsMemory;
  RedXInternalTypeStructsMemory * ihstructsMemorySamplers = (RedXInternalTypeStructsMemory *)structsMemorySamplers;

  unsigned               heapsCount = 0;
  ID3D12DescriptorHeap * heaps[2];

  if (ihstructsMemory != 0) {
    if (ihstructsMemory->handle != 0) {
      heaps[heapsCount] = ihstructsMemory->handle;
      heapsCount += 1;
    }
  }

  if (ihstructsMemorySamplers != 0) {
    if (ihstructsMemorySamplers->handle != 0) {
      heaps[heapsCount] = ihstructsMemorySamplers->handle;
      heapsCount += 1;
    }
  }

  x12CommandListSetDescriptorHeaps(ih->handle, heapsCount, heaps);
}

__declspec(dllexport) void redCallSetProcedureParameters(RedTypeProcedureAddressCallSetProcedureParameters address, RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedureParameters procedureParameters) {
  RedXInternalTypeCalls *               ih                    = (RedXInternalTypeCalls *)calls;
  RedXInternalTypeProcedureParameters * ihprocedureParameters = (RedXInternalTypeProcedureParameters *)procedureParameters;
  if (procedureType == RED_PROCEDURE_TYPE_DRAW) {
    x12CommandListSetGraphicsRootSignature(ih->handle, ihprocedureParameters->handle);
  } else {
    x12CommandListSetComputeRootSignature(ih->handle, ihprocedureParameters->handle);
  }
}

__declspec(dllexport) void redXCallSetProcedureOutput(RedHandleCalls calls, RedHandleTexture depthStencil, unsigned colorsCount, RedHandleTexture * colors, RedSetProcedureOutputOp depthSetProcedureOutputOp, RedSetProcedureOutputOp stencilSetProcedureOutputOp, RedSetProcedureOutputOp * colorsSetProcedureOutputOp, float depthClearValue, unsigned stencilClearValue, const RedColorsClearValuesFloat * colorsClearValuesFloat) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)calls;
  ih->currentProcedureTypeContext = RED_PROCEDURE_TYPE_DRAW;

  ih->currentDepthStencil = (RedXInternalTypeTexture *)depthStencil;
  ih->currentColorsCount  = colorsCount;
  for (unsigned i = 0; i < colorsCount; i += 1) {
    ih->currentColors[i]  = (RedXInternalTypeTexture *)colors[i];
  }

  D3D12_CPU_DESCRIPTOR_HANDLE colorsRTVs[8];
  for (unsigned i = 0; i < colorsCount; i += 1) {
    RedXInternalTypeTexture * ihcolor = (RedXInternalTypeTexture *)colors[i];
    colorsRTVs[i] = ihcolor->cpuDescriptorRTV.cpuDescriptorRTV;
  }

  RedXInternalTypeTexture * ihdepthStencil = (RedXInternalTypeTexture *)depthStencil;
  x12CommandListOMSetRenderTargets(ih->handle, colorsCount, colorsCount == 0 ? 0 : colorsRTVs, 0, ihdepthStencil == 0 ? 0 : &ihdepthStencil->cpuDescriptorDSV.cpuDescriptorDSV);

  if (ihdepthStencil != 0) {
    const D3D12_CPU_DESCRIPTOR_HANDLE depthStencilDSV = ihdepthStencil->cpuDescriptorDSV.cpuDescriptorDSV;
    if (depthSetProcedureOutputOp == RED_SET_PROCEDURE_OUTPUT_OP_CLEAR && stencilSetProcedureOutputOp == RED_SET_PROCEDURE_OUTPUT_OP_CLEAR) {
      x12CommandListClearDepthStencilView(ih->handle, depthStencilDSV, D3D12_CLEAR_FLAG_DEPTH | D3D12_CLEAR_FLAG_STENCIL, depthClearValue, (UINT8)stencilClearValue, 0, 0);
    } else if (depthSetProcedureOutputOp == RED_SET_PROCEDURE_OUTPUT_OP_DISCARD && stencilSetProcedureOutputOp == RED_SET_PROCEDURE_OUTPUT_OP_DISCARD) {
      x12CommandListDiscardResource(ih->handle, ihdepthStencil->image->handle, 0);
    } else {
      if (depthSetProcedureOutputOp == RED_SET_PROCEDURE_OUTPUT_OP_CLEAR || depthSetProcedureOutputOp == RED_SET_PROCEDURE_OUTPUT_OP_DISCARD) {
        x12CommandListClearDepthStencilView(ih->handle, depthStencilDSV, D3D12_CLEAR_FLAG_DEPTH, depthClearValue, (UINT8)stencilClearValue, 0, 0);
      }
      if (stencilSetProcedureOutputOp == RED_SET_PROCEDURE_OUTPUT_OP_CLEAR || stencilSetProcedureOutputOp == RED_SET_PROCEDURE_OUTPUT_OP_DISCARD) {
        x12CommandListClearDepthStencilView(ih->handle, depthStencilDSV, D3D12_CLEAR_FLAG_STENCIL, depthClearValue, (UINT8)stencilClearValue, 0, 0);
      }
    }
  }

  float colorRGBA[4];
  for (unsigned i = 0; i < colorsCount; i += 1) {
    RedXInternalTypeTexture * ihcolor = (RedXInternalTypeTexture *)colors[i];
    if (colorsSetProcedureOutputOp[i] == RED_SET_PROCEDURE_OUTPUT_OP_CLEAR) {
      if (colorsClearValuesFloat != 0) {
        colorRGBA[0] = colorsClearValuesFloat->r[i];
        colorRGBA[1] = colorsClearValuesFloat->g[i];
        colorRGBA[2] = colorsClearValuesFloat->b[i];
        colorRGBA[3] = colorsClearValuesFloat->a[i];
      } else {
        colorRGBA[0] = 0.f;
        colorRGBA[1] = 0.f;
        colorRGBA[2] = 0.f;
        colorRGBA[3] = 0.f;
      }
      x12CommandListClearRenderTargetView(ih->handle, ihcolor->cpuDescriptorRTV.cpuDescriptorRTV, colorRGBA, 0, 0);
    } else if (colorsSetProcedureOutputOp[i] == RED_SET_PROCEDURE_OUTPUT_OP_DISCARD) {
      x12CommandListDiscardResource(ih->handle, ihcolor->image->handle, 0);
    }
  }
}

__declspec(dllexport) void redXCallEndProcedureOutput(RedHandleCalls calls, RedHandleTexture * resolveTargetColors, unsigned * resolveTargetColorsFormat, RedEndProcedureOutputOp depthEndProcedureOutputOp, RedEndProcedureOutputOp stencilEndProcedureOutputOp, RedEndProcedureOutputOp * colorsEndProcedureOutputOp) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)calls;
  ih->currentProcedureTypeContext = RED_PROCEDURE_TYPE_COMPUTE;

  if (resolveTargetColors != 0) {
    for (unsigned i = 0; i < ih->currentColorsCount; i += 1) {
      RedXInternalTypeTexture * sourceColor = ih->currentColors[i];
      RedXInternalTypeTexture * targetColor = (RedXInternalTypeTexture *)resolveTargetColors[i];
      unsigned sourceSubresource = (sourceColor->layersFirst * sourceColor->levelsCount) + sourceColor->levelsFirst;
      unsigned targetSubresource = (targetColor->layersFirst * targetColor->levelsCount) + targetColor->levelsFirst;
      x12CommandListResolveSubresource(ih->handle, targetColor->image->handle, targetSubresource, sourceColor->image->handle, sourceSubresource, redInternalREDGPUFormatToD3D12Format(resolveTargetColorsFormat[i]));
    }
  }

  if (ih->currentDepthStencil != 0) {
    if (depthEndProcedureOutputOp == RED_END_PROCEDURE_OUTPUT_OP_DISCARD && stencilEndProcedureOutputOp == RED_END_PROCEDURE_OUTPUT_OP_DISCARD) {
      x12CommandListDiscardResource(ih->handle, ih->currentDepthStencil->image->handle, 0);
    } else {
      if (depthEndProcedureOutputOp == RED_END_PROCEDURE_OUTPUT_OP_DISCARD) {
        x12CommandListClearDepthStencilView(ih->handle, ih->currentDepthStencil->cpuDescriptorDSV.cpuDescriptorDSV, D3D12_CLEAR_FLAG_DEPTH, 0, 0, 0, 0);
      }
      if (stencilEndProcedureOutputOp == RED_END_PROCEDURE_OUTPUT_OP_DISCARD) {
        x12CommandListClearDepthStencilView(ih->handle, ih->currentDepthStencil->cpuDescriptorDSV.cpuDescriptorDSV, D3D12_CLEAR_FLAG_STENCIL, 0, 0, 0, 0);
      }
    }
  }

  for (unsigned i = 0; i < ih->currentColorsCount; i += 1) {
    if (colorsEndProcedureOutputOp[i] == RED_END_PROCEDURE_OUTPUT_OP_DISCARD) {
      x12CommandListDiscardResource(ih->handle, ih->currentColors[i]->image->handle, 0);
    }
  }
}

__declspec(dllexport) void redXCallUsageAliasOrderBarrier(RedHandleCalls calls, unsigned barriersCount, const void * barriers) {
  RedXInternalTypeCalls * ih  = (RedXInternalTypeCalls *)calls;
  x12CommandListResourceBarrier(ih->handle, barriersCount, (const D3D12_RESOURCE_BARRIER *)barriers);
}

__declspec(dllexport) void redXCallCopyImageRegion(RedHandleCalls calls, unsigned copiesCount, const void * copies) {
  RedXInternalTypeCalls * ih  = (RedXInternalTypeCalls *)calls;
  struct CopyTextureRegionParameters {
    const D3D12_TEXTURE_COPY_LOCATION * pDst;
    unsigned                            DstX;
    unsigned                            DstY;
    unsigned                            DstZ;
    const D3D12_TEXTURE_COPY_LOCATION * pSrc;
    const D3D12_BOX                   * pSrcBox;
  };
  struct CopyTextureRegionParameters * parameters = (struct CopyTextureRegionParameters *)copies;
  for (unsigned i = 0; i < copiesCount; i += 1) {
    x12CommandListCopyTextureRegion(ih->handle, parameters[i].pDst, parameters[i].DstX, parameters[i].DstY, parameters[i].DstZ, parameters[i].pSrc, parameters[i].pSrcBox);
  }
}

static void redCallGpuToCpuSignalSignal(RedHandleCalls calls, RedHandleGpuToCpuSignal signalGpuToCpuSignal, unsigned setTo8192) {
  RedXInternalTypeCalls * ih  = (RedXInternalTypeCalls *)calls;
  try {
    ih->gpuToCpuSignalsToSignal.push_back(signalGpuToCpuSignal);
  } catch (...) {
    redInternalSetStatus((RedXInternalTypeContext *)(ih->context), ih->context->gpus[ih->gpuIndex].gpu, &ih->statuses, 1, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, RED_PROCEDURE_ID_redCallsEnd, 0, 0, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
    return;
  }
  ih->gpuToCpuSignalsToSignalCount += 1;
}

static void redCallCopyArrayToArray(RedHandleCalls calls, RedHandleArray arrayR, RedHandleArray arrayW, unsigned rangesCount, const RedCopyArrayRange * ranges) {
  RedXInternalTypeCalls * ih       = (RedXInternalTypeCalls *)calls;
  RedXInternalTypeArray * ihArrayR = (RedXInternalTypeArray *)arrayR;
  RedXInternalTypeArray * ihArrayW = (RedXInternalTypeArray *)arrayW;
  for (unsigned i = 0; i < rangesCount; i += 1) {
    const RedCopyArrayRange range = ranges[i];
    x12CommandListCopyBufferRegion(ih->handle, ihArrayW->handle, ihArrayW->mappedMemoryBytesFirst + range.arrayWBytesFirst, ihArrayR->handle, ihArrayR->mappedMemoryBytesFirst + range.arrayRBytesFirst, range.bytesCount);
  }
}

static void redCallProcedure(RedHandleCalls calls, unsigned vertexCount, unsigned instanceCount, unsigned vertexFirst, unsigned instanceFirst) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)calls;
  x12CommandListDrawInstanced(ih->handle, vertexCount, instanceCount, vertexFirst, instanceFirst);
}

static void redCallProcedureIndexed(RedHandleCalls calls, unsigned indexCount, unsigned instanceCount, unsigned indexFirst, int vertexBase, unsigned instanceFirst) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)calls;
  x12CommandListDrawIndexedInstanced(ih->handle, indexCount, instanceCount, indexFirst, vertexBase, instanceFirst);
}

static void redCallProcedureCompute(RedHandleCalls calls, unsigned workgroupsCountX, unsigned workgroupsCountY, unsigned workgroupsCountZ) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)calls;
  x12CommandListDispatch(ih->handle, workgroupsCountX, workgroupsCountY, workgroupsCountZ);
}

static void redCallSetDynamicStencilReference (RedHandleCalls calls, RedStencilFace face, unsigned reference);
static void redCallSetDynamicBlendConstants   (RedHandleCalls calls, const float * blendConstants);

static void redCallSetProcedure(RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedure procedure) {
  RedXInternalTypeCalls *     ih          = (RedXInternalTypeCalls *)calls;
  RedXInternalTypeProcedure * ihprocedure = (RedXInternalTypeProcedure *)procedure;
  x12CommandListSetPipelineState(ih->handle, ihprocedure->handle);
  x12CommandListIASetPrimitiveTopology(ih->handle, ihprocedure->state.inputAssemblyTopology == RED_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP ? D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP : D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
  if (ihprocedure->state.viewportDynamic == 0) {
    redCallSetDynamicViewport(0, calls, ihprocedure->state.viewportStaticX, ihprocedure->state.viewportStaticY, ihprocedure->state.viewportStaticWidth, ihprocedure->state.viewportStaticHeight, ihprocedure->state.viewportStaticDepthMin, ihprocedure->state.viewportStaticDepthMax);
  }
  if (ihprocedure->state.scissorDynamic == 0) {
    redCallSetDynamicScissor(0, calls, ihprocedure->state.scissorStaticX, ihprocedure->state.scissorStaticY, ihprocedure->state.scissorStaticWidth, ihprocedure->state.scissorStaticHeight);
  }
  if (ihprocedure->state.stencilTestFrontAndBackDynamicReference == 0) {
    redCallSetDynamicStencilReference(calls, RED_STENCIL_FACE_FRONT_AND_BACK, ihprocedure->state.stencilTestFrontAndBackStaticReference);
  }
  if (ihprocedure->state.blendConstantsDynamic == 0) {
    redCallSetDynamicBlendConstants(calls, ihprocedure->state.blendConstantsStatic);
  }
}

static void redCallSetProcedureIndices(RedHandleCalls calls, RedHandleArray array, uint64_t setTo0, unsigned setTo1) {
  RedXInternalTypeCalls * ih      = (RedXInternalTypeCalls *)calls;
  RedXInternalTypeArray * iharray = (RedXInternalTypeArray *)array;
  D3D12_INDEX_BUFFER_VIEW view;
  view.BufferLocation = x12ResourceGetGPUVirtualAddress(iharray->handle);
  view.SizeInBytes    = (unsigned)iharray->bytesCount;
  view.Format         = DXGI_FORMAT_R32_UINT;
  x12CommandListIASetIndexBuffer(ih->handle, &view);
}

static void redCallSetProcedureParametersStructs(RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedureParameters procedureParameters, unsigned procedureParametersDeclarationStructsDeclarationsFirst, unsigned structsCount, const RedHandleStruct * structs, unsigned setTo0, size_t setTo00) {
  RedXInternalTypeCalls *               ih                    = (RedXInternalTypeCalls *)calls;
  RedXInternalTypeProcedureParameters * ihprocedureParameters = (RedXInternalTypeProcedureParameters *)procedureParameters;
  D3D12_GPU_DESCRIPTOR_HANDLE gpuDescriptor;
  if (procedureType == RED_PROCEDURE_TYPE_DRAW) {
    for (unsigned i = 0; i < structsCount; i += 1) {
      gpuDescriptor.ptr = (uint64_t)structs[i];
      x12CommandListSetGraphicsRootDescriptorTable(ih->handle, ihprocedureParameters->rootParameterIndexStartStructs + procedureParametersDeclarationStructsDeclarationsFirst + i, gpuDescriptor);
    }
  } else {
    for (unsigned i = 0; i < structsCount; i += 1) {
      gpuDescriptor.ptr = (uint64_t)structs[i];
      x12CommandListSetComputeRootDescriptorTable(ih->handle, ihprocedureParameters->rootParameterIndexStartStructs + procedureParametersDeclarationStructsDeclarationsFirst + i, gpuDescriptor);
    }
  }
}

static void redCallSetProcedureParametersHandles(RedHandleCalls calls, RedProcedureType procedureType, RedHandleProcedureParameters procedureParameters, unsigned procedureParametersDeclarationStructsDeclarationsCount, unsigned handlesCount, const RedProcedureParametersHandle * handles) {
  RedXInternalTypeCalls *               ih                    = (RedXInternalTypeCalls *)calls;
  RedXInternalTypeProcedureParameters * ihprocedureParameters = (RedXInternalTypeProcedureParameters *)procedureParameters;
  if (procedureType == RED_PROCEDURE_TYPE_DRAW) {
    for (unsigned i = 0; i < handlesCount; i += 1) {
      RedProcedureParametersHandle handle  = handles[i];
      RedXInternalTypeArray *      iharray = (RedXInternalTypeArray *)handle.array->array;
      if (iharray->type == RED_ARRAY_TYPE_ARRAY_RO_CONSTANT) {
        x12CommandListSetGraphicsRootConstantBufferView(ih->handle, ihprocedureParameters->rootParameterIndexStartHandles + i, x12ResourceGetGPUVirtualAddress(iharray->handle));
      } else if (iharray->type == RED_ARRAY_TYPE_ARRAY_RO) {
        x12CommandListSetGraphicsRootShaderResourceView(ih->handle, ihprocedureParameters->rootParameterIndexStartHandles + i, x12ResourceGetGPUVirtualAddress(iharray->handle));
      } else {
        x12CommandListSetGraphicsRootUnorderedAccessView(ih->handle, ihprocedureParameters->rootParameterIndexStartHandles + i, x12ResourceGetGPUVirtualAddress(iharray->handle));
      }
    }
  } else {
    for (unsigned i = 0; i < handlesCount; i += 1) {
      RedProcedureParametersHandle handle  = handles[i];
      RedXInternalTypeArray *      iharray = (RedXInternalTypeArray *)handle.array->array;
      if (iharray->type == RED_ARRAY_TYPE_ARRAY_RO_CONSTANT) {
        x12CommandListSetComputeRootConstantBufferView(ih->handle, ihprocedureParameters->rootParameterIndexStartHandles + i, x12ResourceGetGPUVirtualAddress(iharray->handle));
      } else if (iharray->type == RED_ARRAY_TYPE_ARRAY_RO) {
        x12CommandListSetComputeRootShaderResourceView(ih->handle, ihprocedureParameters->rootParameterIndexStartHandles + i, x12ResourceGetGPUVirtualAddress(iharray->handle));
      } else {
        x12CommandListSetComputeRootUnorderedAccessView(ih->handle, ihprocedureParameters->rootParameterIndexStartHandles + i, x12ResourceGetGPUVirtualAddress(iharray->handle));
      }
    }
  }
}

static void redCallSetProcedureParametersVariables(RedHandleCalls calls, RedHandleProcedureParameters procedureParameters, RedVisibleToStageBitflags visibleToStages, unsigned variablesBytesFirst, unsigned dataBytesCount, const void * data) {
  RedXInternalTypeCalls *               ih                    = (RedXInternalTypeCalls *)calls;
  RedXInternalTypeProcedureParameters * ihprocedureParameters = (RedXInternalTypeProcedureParameters *)procedureParameters;
  if (ih->currentProcedureTypeContext == RED_PROCEDURE_TYPE_DRAW) {
    x12CommandListSetGraphicsRoot32BitConstants(ih->handle, ihprocedureParameters->rootParameterIndexStartVariables, dataBytesCount / 4, data, variablesBytesFirst / 4);
  } else {
    x12CommandListSetComputeRoot32BitConstants(ih->handle, ihprocedureParameters->rootParameterIndexStartVariables, dataBytesCount / 4, data, variablesBytesFirst / 4);
  }
}

static void redCallSetDynamicStencilReference(RedHandleCalls calls, RedStencilFace face, unsigned reference) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)calls;
  x12CommandListOMSetStencilRef(ih->handle, reference);
}

static void redCallSetDynamicBlendConstants(RedHandleCalls calls, const float * blendConstants) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)calls;
  x12CommandListOMSetBlendFactor(ih->handle, blendConstants);
}

__declspec(dllexport) void redCallSetDynamicViewport(RedTypeProcedureAddressCallSetDynamicViewport address, RedHandleCalls calls, float x, float y, float width, float height, float depthMin, float depthMax) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)calls;
  D3D12_VIEWPORT viewport;
  viewport.TopLeftX = x;
  viewport.TopLeftY = y;
  viewport.Width    = width;
  viewport.Height   = height;
  viewport.MinDepth = depthMin;
  viewport.MaxDepth = depthMax;
  x12CommandListRSSetViewports(ih->handle, 1, &viewport);
}

__declspec(dllexport) void redCallSetDynamicScissor(RedTypeProcedureAddressCallSetDynamicScissor address, RedHandleCalls calls, int x, int y, unsigned width, unsigned height) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)calls;
  D3D12_RECT scissor;
  scissor.left   = x;
  scissor.top    = y;
  scissor.right  = x + width;
  scissor.bottom = y + height;
  x12CommandListRSSetScissorRects(ih->handle, 1, &scissor);
}

__declspec(dllexport) void redCallMark(RedTypeProcedureAddressCallMark address, RedHandleCalls calls, const char * mark) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)calls;
  PIXSetMarker(ih->handle, 0, mark);
}

__declspec(dllexport) void redCallMarkSet(RedTypeProcedureAddressCallMarkSet address, RedHandleCalls calls, const char * mark) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)calls;
  PIXBeginEvent(ih->handle, 0, mark);
}

__declspec(dllexport) void redCallMarkEnd(RedTypeProcedureAddressCallMarkEnd address, RedHandleCalls calls) {
  RedXInternalTypeCalls * ih = (RedXInternalTypeCalls *)calls;
  PIXEndEvent(ih->handle);
}

__declspec(dllexport) void redGetCallProceduresAndAddresses(RedContext context, RedHandleGpu gpu, RedCallProceduresAndAddresses * outCallProceduresAndAddresses, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redGetCallProceduresAndAddresses;
  PIXBeginEvent(0, __FUNCTION__);
  outCallProceduresAndAddresses->redCallGpuToCpuSignalSignal            = (RedTypeProcedureCallGpuToCpuSignalSignal)&redCallGpuToCpuSignalSignal;
  outCallProceduresAndAddresses->redCallCopyArrayToArray                = (RedTypeProcedureCallCopyArrayToArray)&redCallCopyArrayToArray;
  outCallProceduresAndAddresses->redCallCopyImageToImage                = 0;
  outCallProceduresAndAddresses->redCallCopyArrayToImage                = 0;
  outCallProceduresAndAddresses->redCallCopyImageToArray                = 0;
  outCallProceduresAndAddresses->redCallProcedure                       = (RedTypeProcedureCallProcedure)&redCallProcedure;
  outCallProceduresAndAddresses->redCallProcedureIndexed                = (RedTypeProcedureCallProcedureIndexed)&redCallProcedureIndexed;
  outCallProceduresAndAddresses->redCallProcedureCompute                = (RedTypeProcedureCallProcedureCompute)&redCallProcedureCompute;
  outCallProceduresAndAddresses->redCallSetProcedure                    = (RedTypeProcedureCallSetProcedure)&redCallSetProcedure;
  outCallProceduresAndAddresses->redCallSetProcedureIndices             = (RedTypeProcedureCallSetProcedureIndices)&redCallSetProcedureIndices;
  outCallProceduresAndAddresses->redCallSetProcedureParametersStructs   = (RedTypeProcedureCallSetProcedureParametersStructs)&redCallSetProcedureParametersStructs;
  outCallProceduresAndAddresses->redCallSetProcedureParametersHandles   = (RedTypeProcedureCallSetProcedureParametersHandles)&redCallSetProcedureParametersHandles;
  outCallProceduresAndAddresses->redCallSetProcedureParametersVariables = (RedTypeProcedureCallSetProcedureParametersVariables)&redCallSetProcedureParametersVariables;
  outCallProceduresAndAddresses->redCallSetDynamicDepthBias             = 0;
  outCallProceduresAndAddresses->redCallSetDynamicDepthBounds           = 0;
  outCallProceduresAndAddresses->redCallSetDynamicStencilCompareMask    = 0;
  outCallProceduresAndAddresses->redCallSetDynamicStencilWriteMask      = 0;
  outCallProceduresAndAddresses->redCallSetDynamicStencilReference      = (RedTypeProcedureCallSetDynamicStencilReference)&redCallSetDynamicStencilReference;
  outCallProceduresAndAddresses->redCallSetDynamicBlendConstants        = (RedTypeProcedureCallSetDynamicBlendConstants)&redCallSetDynamicBlendConstants;
  outCallProceduresAndAddresses->redCallSetDynamicViewport              = (RedTypeProcedureAddressCallSetDynamicViewport)&redCallSetDynamicViewport;
  outCallProceduresAndAddresses->redCallSetDynamicScissor               = (RedTypeProcedureAddressCallSetDynamicScissor)&redCallSetDynamicScissor;
  outCallProceduresAndAddresses->redCallSetStructsMemory                = (RedTypeProcedureAddressCallSetStructsMemory)0x1;
  outCallProceduresAndAddresses->redCallSetProcedureParameters          = (RedTypeProcedureAddressCallSetProcedureParameters)0x1;
  outCallProceduresAndAddresses->redCallSetProcedureOutput              = 0;
  outCallProceduresAndAddresses->redCallEndProcedureOutput              = 0;
  outCallProceduresAndAddresses->redCallUsageAliasOrderBarrier          = 0;
  outCallProceduresAndAddresses->redCallMark                            = (RedTypeProcedureAddressCallMark)&redCallMark;
  outCallProceduresAndAddresses->redCallMarkSet                         = (RedTypeProcedureAddressCallMarkSet)&redCallMarkSet;
  outCallProceduresAndAddresses->redCallMarkEnd                         = (RedTypeProcedureAddressCallMarkEnd)&redCallMarkEnd;
  PIXEndEvent();
}

__declspec(dllexport) void redQueueSubmit(RedContext context, RedHandleGpu gpu, RedHandleQueue queue, unsigned timelinesCount, const RedGpuTimeline * timelines, RedHandleCpuSignal signalCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redQueueSubmit;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeQueue *   ih  = (RedXInternalTypeQueue *)queue;
  for (unsigned i = 0; i < timelinesCount; i += 1) {
    const RedGpuTimeline timeline = timelines[i];
    REDGPU_VECTOR<ID3D12CommandList *> commandLists;
    if (timeline.callsCount > 32) {
      try {
        commandLists.resize(timeline.callsCount);
      } catch (...) {
        redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_OUT_OF_CPU_MEMORY, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_OUT_OF_CPU_MEMORY");
        continue;
      }
    }
    for (unsigned j = 0; j < timeline.waitForAndUnsignalGpuSignalsCount; j += 1) {
      RedXInternalTypeSignal * h = (RedXInternalTypeSignal *)timeline.waitForAndUnsignalGpuSignals[j];
      x12CommandQueueWait(ih->handle, h->handle, h->value, optionalFile, optionalLine);
    }
    if (timeline.callsCount <= 32) {
      ID3D12CommandList * commandLists32[32];
      for (unsigned j = 0; j < timeline.callsCount; j += 1) {
        commandLists32[j] = (ID3D12CommandList *)(((RedXInternalTypeCalls *)timeline.calls[j])->handle);
      }
      x12CommandQueueExecuteCommandLists(ih->handle, timeline.callsCount, commandLists32, optionalFile, optionalLine);
    } else {
      for (unsigned j = 0; j < timeline.callsCount; j += 1) {
        commandLists[j] = (ID3D12CommandList *)(((RedXInternalTypeCalls *)timeline.calls[j])->handle);
      }
      x12CommandQueueExecuteCommandLists(ih->handle, timeline.callsCount, &commandLists[0], optionalFile, optionalLine);
    }
    for (unsigned j = 0; j < timeline.signalGpuSignalsCount; j += 1) {
      RedXInternalTypeSignal * h = (RedXInternalTypeSignal *)timeline.signalGpuSignals[j];
      h->value += 1;
      x12CommandQueueSignal(ih->handle, h->handle, h->value, optionalFile, optionalLine);
    }
    for (unsigned j = 0; j < timeline.callsCount; j += 1) {
      const RedXInternalTypeCalls * ihcalls = (const RedXInternalTypeCalls *)timeline.calls[j];
      for (unsigned k = 0; k < ihcalls->gpuToCpuSignalsToSignalCount; k += 1) {
        RedXInternalTypeSignal * h = (RedXInternalTypeSignal *)ihcalls->gpuToCpuSignalsToSignal[k];
        h->value += 1;
        x12CommandQueueSignal(ih->handle, h->handle, h->value, optionalFile, optionalLine);
      }
    }
  }
  if (signalCpuSignal != 0) {
    RedXInternalTypeSignal * h = (RedXInternalTypeSignal *)signalCpuSignal;
    h->value += 1;
    x12CommandQueueSignal(ih->handle, h->handle, h->value, optionalFile, optionalLine);
  }
  PIXEndEvent();
}

__declspec(dllexport) void redMark(const char * mark, const char * optionalFile, int optionalLine, void * optionalUserData) {
  PIXSetMarker(0, mark);
}

__declspec(dllexport) void redMarkSet(const char * mark, const char * optionalFile, int optionalLine, void * optionalUserData) {
  PIXBeginEvent(0, mark);
}

__declspec(dllexport) void redMarkEnd(const char * optionalFile, int optionalLine, void * optionalUserData) {
  PIXEndEvent();
}

__declspec(dllexport) void redCreatePresent(RedContext context, RedHandleGpu gpu, RedHandleQueue queue, const char * handleName, RedHandleSurface surface, unsigned imagesCount, unsigned imagesWidth, unsigned imagesHeight, unsigned imagesLayersCount, RedAccessBitflags imagesRestrictToAccess, RedSurfaceTransformBitflag transform, RedSurfaceCompositeAlphaBitflag compositeAlpha, RedPresentVsyncMode vsyncMode, RedBool32 clipped, RedBool32 discardAfterPresent, RedHandlePresent oldPresent, RedHandlePresent * outPresent, RedHandleImage * outImages, RedHandleTexture * outTextures, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreatePresent;
  PIXBeginEvent(0, __FUNCTION__);

  RedXInternalTypeContext * ctx       = (RedXInternalTypeContext *)context;
  RedXInternalTypeSurface * ihsurface = (RedXInternalTypeSurface *)surface;
  RedXInternalTypeQueue   * ihqueue   = (RedXInternalTypeQueue   *)queue;
  RedXInternalTypePresent * ih        = 0;

  RedHandleTexture texture0 = 0;
  RedHandleTexture texture1 = 0;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outPresent[0] = 0;
    outImages[0] = 0;
    outImages[1] = 0;
    if (outTextures != 0) {
      outTextures[0] = 0;
      outTextures[1] = 0;
    }
    PIXEndEvent();
    return;
  }

  if (imagesCount == 2 || imagesCount == (unsigned)-1) {
  } else {
    redInternalSetStatus(ctx, gpu, outStatuses, 37, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
    outPresent[0] = 0;
    outImages[0] = 0;
    outImages[1] = 0;
    if (outTextures != 0) {
      outTextures[0] = 0;
      outTextures[1] = 0;
    }
    PIXEndEvent();
    return;
  }

  if (imagesCount == (unsigned)-1) {
    imagesCount = 2;
  }

  if (imagesLayersCount != 1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 38, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
    outPresent[0] = 0;
    outImages[0] = 0;
    outImages[1] = 0;
    if (outTextures != 0) {
      outTextures[0] = 0;
      outTextures[1] = 0;
    }
    PIXEndEvent();
    return;
  }

  if (imagesRestrictToAccess != RED_ACCESS_BITFLAG_OUTPUT_COLOR_W) {
    redInternalSetStatus(ctx, gpu, outStatuses, 39, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
    outPresent[0] = 0;
    outImages[0] = 0;
    outImages[1] = 0;
    if (outTextures != 0) {
      outTextures[0] = 0;
      outTextures[1] = 0;
    }
    PIXEndEvent();
    return;
  }

  if (transform != RED_SURFACE_TRANSFORM_BITFLAG_IDENTITY) {
    redInternalSetStatus(ctx, gpu, outStatuses, 40, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
    outPresent[0] = 0;
    outImages[0] = 0;
    outImages[1] = 0;
    if (outTextures != 0) {
      outTextures[0] = 0;
      outTextures[1] = 0;
    }
    PIXEndEvent();
    return;
  }

  if (compositeAlpha != RED_SURFACE_COMPOSITE_ALPHA_BITFLAG_OPAQUE) {
    redInternalSetStatus(ctx, gpu, outStatuses, 41, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
    outPresent[0] = 0;
    outImages[0] = 0;
    outImages[1] = 0;
    if (outTextures != 0) {
      outTextures[0] = 0;
      outTextures[1] = 0;
    }
    PIXEndEvent();
    return;
  }

  if (vsyncMode != RED_PRESENT_VSYNC_MODE_ON && vsyncMode != RED_PRESENT_VSYNC_MODE_OFF) {
    redInternalSetStatus(ctx, gpu, outStatuses, 42, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
    outPresent[0] = 0;
    outImages[0] = 0;
    outImages[1] = 0;
    if (outTextures != 0) {
      outTextures[0] = 0;
      outTextures[1] = 0;
    }
    PIXEndEvent();
    return;
  }

  ih = redInternalTypePresentAllocate(ctx, gpuIndex, handleName, ihqueue, ihsurface, imagesWidth, imagesHeight, imagesLayersCount, vsyncMode, outStatuses, procedureId, 1, optionalFile, optionalLine);
  if (ih == 0) {
    outPresent[0] = 0;
    outImages[0] = 0;
    outImages[1] = 0;
    if (outTextures != 0) {
      outTextures[0] = 0;
      outTextures[1] = 0;
    }
    PIXEndEvent();
    return;
  }
  if (ih->images[0] == 0) {
    redInternalDestroyPresent((RedHandlePresent)ih, optionalFile, optionalLine);
    ih = 0;
    outPresent[0] = 0;
    outImages[0] = 0;
    outImages[1] = 0;
    if (outTextures != 0) {
      outTextures[0] = 0;
      outTextures[1] = 0;
    }
    PIXEndEvent();
    return;
  }
  if (ih->images[1] == 0) {
    redInternalDestroyPresent((RedHandlePresent)ih, optionalFile, optionalLine);
    ih = 0;
    outPresent[0] = 0;
    outImages[0] = 0;
    outImages[1] = 0;
    if (outTextures != 0) {
      outTextures[0] = 0;
      outTextures[1] = 0;
    }
    PIXEndEvent();
    return;
  }

  ih->images[0]->ownedByPresent = ih;
  ih->images[1]->ownedByPresent = ih;

  {
    DXGI_SWAP_CHAIN_DESC1 swapchainDesc = {};
    swapchainDesc.Width              = imagesWidth;
    swapchainDesc.Height             = imagesHeight;
    swapchainDesc.Format             = DXGI_FORMAT_B8G8R8A8_UNORM;
    swapchainDesc.Stereo             = 0;
    swapchainDesc.SampleDesc.Count   = 1;
    swapchainDesc.SampleDesc.Quality = 0;
    swapchainDesc.BufferUsage        = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapchainDesc.BufferCount        = imagesCount;
    swapchainDesc.Scaling            = DXGI_SCALING_NONE;
    swapchainDesc.SwapEffect         = discardAfterPresent == 1 ? DXGI_SWAP_EFFECT_FLIP_DISCARD : DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
    swapchainDesc.AlphaMode          = DXGI_ALPHA_MODE_IGNORE;
    swapchainDesc.Flags              = 0;
    if (ihsurface->type == REDX_INTERNAL_TYPE_SURFACE_TYPE_WIN32) {
      HRESULT hr = x12FactoryCreateSwapChainForHwnd((IDXGIFactory4 *)ctx->contextHandle, ihqueue->handle, (HWND)ihsurface->window, &swapchainDesc, 0, 0, &ih->handle, optionalFile, optionalLine);
      if (hr < 0) {
        redInternalDestroyPresent((RedHandlePresent)ih, optionalFile, optionalLine);
        ih = 0;
        outPresent[0] = 0;
        outImages[0] = 0;
        outImages[1] = 0;
        if (outTextures != 0) {
          outTextures[0] = 0;
          outTextures[1] = 0;
        }
        PIXEndEvent();
        return;
      }
    } else if (ihsurface->type == REDX_INTERNAL_TYPE_SURFACE_TYPE_WINRT) {
      HRESULT hr = x12FactoryCreateSwapChainForCoreWindow((IDXGIFactory4 *)ctx->contextHandle, ihqueue->handle, ihsurface->window, &swapchainDesc, 0, &ih->handle, optionalFile, optionalLine);
      if (hr < 0) {
        redInternalDestroyPresent((RedHandlePresent)ih, optionalFile, optionalLine);
        ih = 0;
        outPresent[0] = 0;
        outImages[0] = 0;
        outImages[1] = 0;
        if (outTextures != 0) {
          outTextures[0] = 0;
          outTextures[1] = 0;
        }
        PIXEndEvent();
        return;
      }
    } else {
      redInternalSetStatus(ctx, gpu, outStatuses, 4, RED_STATUS_ERROR_VALIDATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_VALIDATION_FAILED");
      redInternalDestroyPresent((RedHandlePresent)ih, optionalFile, optionalLine);
      ih = 0;
      outPresent[0] = 0;
      outImages[0] = 0;
      outImages[1] = 0;
      if (outTextures != 0) {
        outTextures[0] = 0;
        outTextures[1] = 0;
      }
      PIXEndEvent();
      return;
    }

    {
      HRESULT hr = S_OK;
      hr = x12SwapChainGetBuffer(ih->handle, 0, &ih->images[0]->handle, optionalFile, optionalLine);
      if (hr < 0) {
        redInternalDestroyPresent((RedHandlePresent)ih, optionalFile, optionalLine);
        ih = 0;
        outPresent[0] = 0;
        outImages[0] = 0;
        outImages[1] = 0;
        if (outTextures != 0) {
          outTextures[0] = 0;
          outTextures[1] = 0;
        }
        PIXEndEvent();
        return;
      }
      hr = x12SwapChainGetBuffer(ih->handle, 1, &ih->images[1]->handle, optionalFile, optionalLine);
      if (hr < 0) {
        redInternalDestroyPresent((RedHandlePresent)ih, optionalFile, optionalLine);
        ih = 0;
        outPresent[0] = 0;
        outImages[0] = 0;
        outImages[1] = 0;
        if (outTextures != 0) {
          outTextures[0] = 0;
          outTextures[1] = 0;
        }
        PIXEndEvent();
        return;
      }
    }

    if (ctx->internal.debugCallback != 0 && handleName != 0) {
      std::string  HandleNameA = handleName;
      std::wstring handleNameW(HandleNameA.begin(), HandleNameA.end());
      if (ih->images[0]->handle != 0) { x12ObjectSetName((ID3D12Object *)ih->images[0]->handle, &handleNameW[0], optionalFile, optionalLine); }
      if (ih->images[1]->handle != 0) { x12ObjectSetName((ID3D12Object *)ih->images[1]->handle, &handleNameW[0], optionalFile, optionalLine); }
    }

    if (outTextures != 0) {
      if (ih->images[0]->handle != 0) { redInternalCreateTexture(context, gpu, handleName, (RedHandleImage)ih->images[0], RED_IMAGE_PART_BITFLAG_COLOR, RED_TEXTURE_DIMENSIONS_2D, RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1, RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1, 0, 1, 0, 1, RED_ACCESS_BITFLAG_OUTPUT_COLOR_W, &texture0, outStatuses, optionalFile, optionalLine, procedureId, 9);  }
      if (ih->images[1]->handle != 0) { redInternalCreateTexture(context, gpu, handleName, (RedHandleImage)ih->images[1], RED_IMAGE_PART_BITFLAG_COLOR, RED_TEXTURE_DIMENSIONS_2D, RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1, RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1, 0, 1, 0, 1, RED_ACCESS_BITFLAG_OUTPUT_COLOR_W, &texture1, outStatuses, optionalFile, optionalLine, procedureId, 23); }
    }
  }

  outPresent[0] = (RedHandlePresent)ih;

  if (ih != 0) {
    outImages[0] = (RedHandleImage)ih->images[0];
    outImages[1] = (RedHandleImage)ih->images[1];
  } else {
    outImages[0] = 0;
    outImages[1] = 0;
  }

  if (outTextures != 0) {
    outTextures[0] = texture0;
    outTextures[1] = texture1;
  }

  PIXEndEvent();
}

__declspec(dllexport) void redDestroySurface(RedContext context, RedHandleGpu gpu, RedHandleSurface surface, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroySurface;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroySurface(surface, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyPresent(RedContext context, RedHandleGpu gpu, RedHandlePresent present, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redDestroyPresent;
  PIXBeginEvent(0, __FUNCTION__);
  redInternalDestroyPresent(present, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redQueueFamilyIndexGetSupportsPresent(RedContext context, RedHandleGpu gpu, unsigned queueFamilyIndex, RedQueueFamilyIndexGetSupportsPresentOnWin32 * supportsPresentOnWin32, RedQueueFamilyIndexGetSupportsPresentOnXlib * supportsPresentOnXlib, RedQueueFamilyIndexGetSupportsPresentOnXcb * supportsPresentOnXcb, RedQueueFamilyIndexGetSupportsPresentOnSurface * supportsPresentOnSurface, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redQueueFamilyIndexGetSupportsPresent;
  PIXBeginEvent(0, __FUNCTION__);

  const unsigned queueFamilyIndex0Direct  = 0;
  const unsigned queueFamilyIndex1Compute = 1;
  const unsigned queueFamilyIndex2Copy    = 2;

  if (supportsPresentOnWin32 != 0) {
    if (queueFamilyIndex == queueFamilyIndex0Direct) {
      supportsPresentOnWin32->outQueueFamilyIndexSupportsPresentOnWin32 = 1;
    } else {
      supportsPresentOnWin32->outQueueFamilyIndexSupportsPresentOnWin32 = 0;
    }
  }

  if (supportsPresentOnXlib != 0) {
    supportsPresentOnXlib->outQueueFamilyIndexSupportsPresentOnXlib = 0;
  }

  if (supportsPresentOnXcb != 0) {
    supportsPresentOnXcb->outQueueFamilyIndexSupportsPresentOnXcb = 0;
  }

  if (supportsPresentOnSurface != 0) {
    supportsPresentOnSurface->outQueueFamilyIndexSupportsPresentOnSurface = 1;
  }

  PIXEndEvent();
}

__declspec(dllexport) void redSurfaceGetPresentFeatures(RedContext context, RedHandleGpu gpu, RedHandleSurface surface, RedSurfacePresentFeatures * outSurfacePresentFeatures, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redSurfaceGetPresentFeatures;
  PIXBeginEvent(0, __FUNCTION__);

  outSurfacePresentFeatures->supportsPresentVsyncModeOff       = 1;
  outSurfacePresentFeatures->supportsPresentVsyncModeOn        = 1;
  outSurfacePresentFeatures->supportsPresentVsyncModeOnRelaxed = 0;

  PIXEndEvent();
}

__declspec(dllexport) void redSurfaceGetCurrentPropertiesAndPresentLimits(RedContext context, RedHandleGpu gpu, RedHandleSurface surface, RedSurfaceCurrentPropertiesAndPresentLimits * outSurfaceCurrentPropertiesAndPresentLimits, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redSurfaceGetCurrentPropertiesAndPresentLimits;
  PIXBeginEvent(0, __FUNCTION__);

  outSurfaceCurrentPropertiesAndPresentLimits->currentSurfaceWidth                           = 0xFFFFFFFF;
  outSurfaceCurrentPropertiesAndPresentLimits->currentSurfaceHeight                          = 0xFFFFFFFF;
  outSurfaceCurrentPropertiesAndPresentLimits->currentSurfaceTransform                       = RED_SURFACE_TRANSFORM_BITFLAG_IDENTITY;
  outSurfaceCurrentPropertiesAndPresentLimits->minPresentImagesCount                         = 2;
  outSurfaceCurrentPropertiesAndPresentLimits->maxPresentImagesCount                         = 2;
  outSurfaceCurrentPropertiesAndPresentLimits->minPresentImagesWidth                         = 0xFFFFFFFF;
  outSurfaceCurrentPropertiesAndPresentLimits->maxPresentImagesWidth                         = 0xFFFFFFFF;
  outSurfaceCurrentPropertiesAndPresentLimits->minPresentImagesHeight                        = 0xFFFFFFFF;
  outSurfaceCurrentPropertiesAndPresentLimits->maxPresentImagesHeight                        = 0xFFFFFFFF;
  outSurfaceCurrentPropertiesAndPresentLimits->maxPresentImagesLayersCount                   = 1;
  outSurfaceCurrentPropertiesAndPresentLimits->supportsPresentImagesAccessCopyR              = 0;
  outSurfaceCurrentPropertiesAndPresentLimits->supportsPresentImagesAccessCopyW              = 0;
  outSurfaceCurrentPropertiesAndPresentLimits->supportsPresentImagesAccessTextureRO          = 0;
  outSurfaceCurrentPropertiesAndPresentLimits->supportsPresentImagesAccessTextureRW          = 0;
  outSurfaceCurrentPropertiesAndPresentLimits->supportsPresentImagesAccessOutputDepthStencil = 0;
  outSurfaceCurrentPropertiesAndPresentLimits->supportsPresentImagesAccessOutputColor        = 1;
  outSurfaceCurrentPropertiesAndPresentLimits->supportedPresentTransforms                    = RED_SURFACE_TRANSFORM_BITFLAG_IDENTITY;
  outSurfaceCurrentPropertiesAndPresentLimits->supportedPresentCompositeAlphas               = RED_SURFACE_COMPOSITE_ALPHA_BITFLAG_OPAQUE;

  PIXEndEvent();
}

__declspec(dllexport) void redPresentGetImageIndex(RedContext context, RedHandleGpu gpu, RedHandlePresent present, RedHandleCpuSignal signalCpuSignal, RedHandleGpuSignal signalGpuSignal, unsigned * outImageIndex, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redPresentGetImageIndex;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypePresent * ih  = (RedXInternalTypePresent *)present;
  outImageIndex[0] = x12SwapChainGetCurrentBackBufferIndex(ih->handle, optionalFile, optionalLine);
  PIXEndEvent();
}

__declspec(dllexport) void redQueuePresent(RedContext context, RedHandleGpu gpu, RedHandleQueue queue, unsigned waitForAndUnsignalGpuSignalsCount, const RedHandleGpuSignal * waitForAndUnsignalGpuSignals, unsigned presentsCount, const RedHandlePresent * presents, const unsigned * presentsImageIndex, RedStatus * outPresentsStatus, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redQueuePresent;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeQueue   * iq  = (RedXInternalTypeQueue *)queue;
  if (waitForAndUnsignalGpuSignalsCount == 0 && presentsCount == 0) {
    RedHandleGpuSignal waitForQueuePresentGpuSignal = 0;
    RedHandleCpuSignal waitForQueuePresentCpuSignal = 0;
    redCreateGpuSignal(
      context,
      gpu,
      0,
      &waitForQueuePresentGpuSignal,
      outStatuses,
      optionalFile,
      optionalLine,
      optionalUserData
    );
    redCreateCpuSignal(
      context,
      gpu,
      0,
      0,
      &waitForQueuePresentCpuSignal,
      outStatuses,
      optionalFile,
      optionalLine,
      optionalUserData
    );
    RedXInternalTypeSignal * sgpu = (RedXInternalTypeSignal *)waitForQueuePresentGpuSignal;
    RedXInternalTypeSignal * scpu = (RedXInternalTypeSignal *)waitForQueuePresentCpuSignal;
    x12CommandQueueSignal(iq->handle, sgpu->handle, 1, optionalFile, optionalLine);
    x12CommandQueueWait(iq->handle, sgpu->handle, 1, optionalFile, optionalLine);
    x12CommandQueueSignal(iq->handle, scpu->handle, 1, optionalFile, optionalLine);
    x12FenceSetEventOnCompletion(scpu->handle, 1, 0, optionalFile, optionalLine);
    redDestroyGpuSignal(context, gpu, waitForQueuePresentGpuSignal, optionalFile, optionalLine, optionalUserData);
    redDestroyCpuSignal(context, gpu, waitForQueuePresentCpuSignal, optionalFile, optionalLine, optionalUserData);
  }
  const DXGI_PRESENT_PARAMETERS params = {};
  for (unsigned i = 0; i < presentsCount; i += 1) {
    RedXInternalTypePresent * ih = (RedXInternalTypePresent *)presents[i];
    HRESULT hr = x12SwapChainPresent1(ih->handle, ih->vsyncMode == RED_PRESENT_VSYNC_MODE_ON ? 1 : 0, 0, &params, optionalFile, optionalLine);
    if (outPresentsStatus != 0) {
      outPresentsStatus[i] = (RedStatus)hr;
    }
  }
  PIXEndEvent();
}

__declspec(dllexport) void redCreateSurfaceWin32(RedContext context, RedHandleGpu gpu, const char * handleName, const void * win32Hinstance, const void * win32Hwnd, RedHandleSurface * outSurface, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = RED_PROCEDURE_ID_redCreateSurfaceWin32;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeSurface * ih  = 0;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outSurface[0] = 0;
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeSurfaceAllocate(ctx, gpuIndex, handleName, REDX_INTERNAL_TYPE_SURFACE_TYPE_WIN32, win32Hwnd, outStatuses, procedureId, 1, optionalFile, optionalLine);

  outSurface[0] = (RedHandleSurface)ih;

  PIXEndEvent();
}

__declspec(dllexport) void redCreateSurfaceXlibOrXcb(RedContext context, RedHandleGpu gpu, const char * handleName, const void * xlibDisplay, unsigned long xlibWindow, const void * xcbConnection, unsigned xcbWindow, RedHandleSurface * outSurface, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  PIXBeginEvent(0, __FUNCTION__);
  outSurface[0] = 0;
  PIXEndEvent();
}

__declspec(dllexport) void redCreateProcedureComputingLanguage(RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, RedHandleProcedureParameters procedureParameters, const char * gpuCodeMainProcedureName, RedHandleGpuCode gpuCode, const void * stateExtension, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  PIXBeginEvent(0, __FUNCTION__);
  outProcedure[0] = 0;
  PIXEndEvent();
}

__declspec(dllexport) void redCreateArrayTimestamp(RedContext context, RedHandleGpu gpu, const char * handleName, unsigned count, RedHandleArrayTimestamp * outArrayTimestamp, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  PIXBeginEvent(0, __FUNCTION__);
  outArrayTimestamp[0] = 0;
  PIXEndEvent();
}

__declspec(dllexport) void redDestroyArrayTimestamp(RedContext context, RedHandleGpu gpu, RedHandleArrayTimestamp arrayTimestamp, const char * optionalFile, int optionalLine, void * optionalUserData) {
  PIXBeginEvent(0, __FUNCTION__);
  PIXEndEvent();
}

__declspec(dllexport) void redCallArrayTimestampWrite(RedHandleCalls calls, RedContext context, RedHandleArrayTimestamp arrayTimestamp, unsigned index) {
  PIXBeginEvent(0, __FUNCTION__);
  PIXEndEvent();
}

__declspec(dllexport) void redArrayTimestampRead(RedContext context, RedHandleGpu gpu, RedHandleArrayTimestamp arrayTimestamp, unsigned rangeFirst, unsigned rangeCount, void * out64BitTicksCounts, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  PIXBeginEvent(0, __FUNCTION__);
  PIXEndEvent();
}

__declspec(dllexport) void redXCreateSurfaceWinRT(RedContext context, RedHandleGpu gpu, const char * handleName, const void * winrtIUnknownPointerCoreWindow, RedHandleSurface * outSurface, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {
  const RedProcedureId procedureId = (RedProcedureId)REDX_PROCEDURE_ID_redXCreateSurfaceWinRT;
  PIXBeginEvent(0, __FUNCTION__);
  RedXInternalTypeContext * ctx = (RedXInternalTypeContext *)context;
  RedXInternalTypeSurface * ih  = 0;

  unsigned gpuIndex = redInternalGetGpuIndex(context, gpu);
  if (gpuIndex == (unsigned)-1) {
    redInternalSetStatus(ctx, gpu, outStatuses, 0, RED_STATUS_ERROR_INITIALIZATION_FAILED, procedureId, optionalFile, optionalLine, E_FAIL, "RED_STATUS_ERROR_INITIALIZATION_FAILED");
    outSurface[0] = 0;
    PIXEndEvent();
    return;
  }

  ih = redInternalTypeSurfaceAllocate(ctx, gpuIndex, handleName, REDX_INTERNAL_TYPE_SURFACE_TYPE_WINRT, winrtIUnknownPointerCoreWindow, outStatuses, procedureId, 1, optionalFile, optionalLine);

  outSurface[0] = (RedHandleSurface)ih;

  PIXEndEvent();
}
