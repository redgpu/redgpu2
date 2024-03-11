// pub type size_t = usize;
// pub type uint64_t = u64;

#include <stddef.h> // For size_t
#include <stdint.h> // For uint64_t

typedef unsigned RedBool32;

typedef const struct RedTypeContext                   * RedContext;
typedef const struct RedTypeHandleContext             * RedHandleContext;
typedef const struct RedTypeHandleGpu                 * RedHandleGpu;
typedef const struct RedTypeHandleGpuDevice           * RedHandleGpuDevice;
typedef const struct RedTypeHandleQueue               * RedHandleQueue;
typedef const struct RedTypeHandleMemory              * RedHandleMemory;
typedef const struct RedTypeHandleArray               * RedHandleArray;
typedef const struct RedTypeHandleImage               * RedHandleImage;
typedef const struct RedTypeHandleSampler             * RedHandleSampler;
typedef const struct RedTypeHandleTexture             * RedHandleTexture;
typedef const struct RedTypeHandleGpuCode             * RedHandleGpuCode;
typedef const struct RedTypeHandleOutputDeclaration   * RedHandleOutputDeclaration;
typedef const struct RedTypeHandleStructDeclaration   * RedHandleStructDeclaration;
typedef const struct RedTypeHandleProcedureParameters * RedHandleProcedureParameters;
typedef const struct RedTypeHandleProcedureCache      * RedHandleProcedureCache;
typedef const struct RedTypeHandleProcedure           * RedHandleProcedure;
typedef const struct RedTypeHandleOutput              * RedHandleOutput;
typedef const struct RedTypeHandleStruct              * RedHandleStruct;
typedef const struct RedTypeHandleStructsMemory       * RedHandleStructsMemory;
typedef const struct RedTypeHandleCalls               * RedHandleCalls;
typedef const struct RedTypeHandleCallsMemory         * RedHandleCallsMemory;
typedef const struct RedTypeHandleCpuSignal           * RedHandleCpuSignal;
typedef const struct RedTypeHandleGpuSignal           * RedHandleGpuSignal;
typedef const struct RedTypeHandleGpuToCpuSignal      * RedHandleGpuToCpuSignal;

typedef struct RedArray {
  RedHandleArray       handle;
  uint64_t             memoryBytesAlignment;
  uint64_t             memoryBytesCount;
  unsigned             memoryTypesSupported; // Bitflags
} RedArray;

typedef struct RedImage {
  RedHandleImage       handle;
  uint64_t             memoryBytesAlignment;
  uint64_t             memoryBytesCount;
  unsigned             memoryTypesSupported; // Bitflags
} RedImage;

typedef struct RedOutput {
  RedHandleOutput      handle;
  unsigned             width;
  unsigned             height;
  RedBool32            depthStencilEnable;
  unsigned             colorsCount;          // Max: 8
} RedOutput;

typedef struct RedCalls {
  RedHandleCalls       handle;
  RedHandleCallsMemory memory;
  RedBool32            reusable;
} RedCalls;

typedef enum RedStatus {
  RED_STATUS_SUCCESS                       = 0,
  RED_STATUS_NOT_READY                     = 1,
  RED_STATUS_TIMEOUT                       = 2,
  RED_STATUS_GPU_TO_CPU_SIGNAL_SIGNALED    = 3,
  RED_STATUS_GPU_TO_CPU_SIGNAL_UNSIGNALED  = 4,
  RED_STATUS_INCOMPLETE                    = 5,
  RED_STATUS_PRESENT_IS_SUBOPTIMAL         = 1000001003, // WSI specific
  RED_STATUS_ERROR_OUT_OF_CPU_MEMORY       = -1,
  RED_STATUS_ERROR_OUT_OF_GPU_MEMORY       = -2,
  RED_STATUS_ERROR_INITIALIZATION_FAILED   = -3,
  RED_STATUS_ERROR_GPU_IS_LOST             = -4,
  RED_STATUS_ERROR_MEMORY_MAPPING_FAILED   = -5, // Memory mapping will fail if the implementation is unable to allocate an appropriately sized contiguous virtual address range, e.g. due to virtual address space fragmentation or platform limits. The program can improve the likelihood of success by reducing the size of the mapped range and/or remove unneeded mappings using redMemoryUnmap
  RED_STATUS_ERROR_LAYER_IS_NOT_FOUND      = -6,
  RED_STATUS_ERROR_EXTENSION_IS_NOT_FOUND  = -7,
  RED_STATUS_ERROR_FEATURE_IS_NOT_FOUND    = -8,
  RED_STATUS_ERROR_INCOMPATIBLE_DRIVER     = -9,
  RED_STATUS_ERROR_TOO_MANY_HANDLES        = -10,
  RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED = -11,
  RED_STATUS_ERROR_MEMORY_IS_FRAGMENTED    = -12,
  RED_STATUS_ERROR_MEMORY_OVERFLOW         = -1000069000,
  RED_STATUS_ERROR_WINDOW_IS_ALREADY_USED  = -1000000001, // WSI specific
  RED_STATUS_ERROR_SURFACE_IS_LOST         = -1000000000, // WSI specific
  RED_STATUS_ERROR_PRESENT_IS_OUT_OF_DATE  = -1000001004, // WSI specific
  RED_STATUS_ERROR_VALIDATION_FAILED       = -1000011001,
  RED_STATUS_ERROR_INVALID_GPU_CODE        = -1000012000,
} RedStatus;

typedef enum RedProcedureId {
  RED_PROCEDURE_ID_UNDEFINED                                      = 0,
  RED_PROCEDURE_ID_redMemoryGetBudget                             = 1,
  RED_PROCEDURE_ID_redMemoryAllocate                              = 2,
  RED_PROCEDURE_ID_redMemoryAllocateMappable                      = 3,
  RED_PROCEDURE_ID_redMemoryFree                                  = 4,
  RED_PROCEDURE_ID_redMemorySet                                   = 5,
  RED_PROCEDURE_ID_redMemoryMap                                   = 6,
  RED_PROCEDURE_ID_redMemoryUnmap                                 = 7,
  RED_PROCEDURE_ID_redMemoryNonCoherentFlush                      = 8,
  RED_PROCEDURE_ID_redMemoryNonCoherentInvalidate                 = 9,
  RED_PROCEDURE_ID_redStructsMemoryAllocate                       = 10,
  RED_PROCEDURE_ID_redStructsMemoryAllocateSamplers               = 11,
  RED_PROCEDURE_ID_redStructsMemorySuballocateStructs             = 12,
  RED_PROCEDURE_ID_redStructsMemoryReset                          = 13,
  RED_PROCEDURE_ID_redStructsMemoryFree                           = 14,
  RED_PROCEDURE_ID_redStructsSet                                  = 15,
  RED_PROCEDURE_ID_redCreateContext                               = 16,
  RED_PROCEDURE_ID_redCreateArray                                 = 17,
  RED_PROCEDURE_ID_redCreateImage                                 = 18,
  RED_PROCEDURE_ID_redCreateSampler                               = 19,
  RED_PROCEDURE_ID_redCreateTexture                               = 20,
  RED_PROCEDURE_ID_redCreateGpuCode                               = 21,
  RED_PROCEDURE_ID_redCreateOutputDeclaration                     = 22,
  RED_PROCEDURE_ID_redCreateStructDeclaration                     = 23,
  RED_PROCEDURE_ID_redCreateProcedureParameters                   = 24,
  RED_PROCEDURE_ID_redCreateProcedureCache                        = 25,
  RED_PROCEDURE_ID_redCreateProcedure                             = 26,
  RED_PROCEDURE_ID_redCreateProcedureCompute                      = 27,
  RED_PROCEDURE_ID_redCreateOutput                                = 28,
  RED_PROCEDURE_ID_redCreateCpuSignal                             = 29,
  RED_PROCEDURE_ID_redCreateGpuSignal                             = 30,
  RED_PROCEDURE_ID_redCreateGpuToCpuSignal                        = 31,
  RED_PROCEDURE_ID_redCreateCalls                                 = 32,
  RED_PROCEDURE_ID_redCreateCallsReusable                         = 33,
  RED_PROCEDURE_ID_redDestroyContext                              = 34,
  RED_PROCEDURE_ID_redDestroyArray                                = 35,
  RED_PROCEDURE_ID_redDestroyImage                                = 36,
  RED_PROCEDURE_ID_redDestroySampler                              = 37,
  RED_PROCEDURE_ID_redDestroyTexture                              = 38,
  RED_PROCEDURE_ID_redDestroyGpuCode                              = 39,
  RED_PROCEDURE_ID_redDestroyOutputDeclaration                    = 40,
  RED_PROCEDURE_ID_redDestroyStructDeclaration                    = 41,
  RED_PROCEDURE_ID_redDestroyProcedureParameters                  = 42,
  RED_PROCEDURE_ID_redDestroyProcedureCache                       = 43,
  RED_PROCEDURE_ID_redDestroyProcedure                            = 44,
  RED_PROCEDURE_ID_redDestroyOutput                               = 45,
  RED_PROCEDURE_ID_redDestroyCpuSignal                            = 46,
  RED_PROCEDURE_ID_redDestroyGpuSignal                            = 47,
  RED_PROCEDURE_ID_redDestroyGpuToCpuSignal                       = 48,
  RED_PROCEDURE_ID_redDestroyCalls                                = 49,
  RED_PROCEDURE_ID_redProcedureCacheGetBlob                       = 50,
  RED_PROCEDURE_ID_redProcedureCacheMergeCaches                   = 51,
  RED_PROCEDURE_ID_redCpuSignalGetStatus                          = 52,
  RED_PROCEDURE_ID_redCpuSignalWait                               = 53,
  RED_PROCEDURE_ID_redCpuSignalUnsignal                           = 54,
  RED_PROCEDURE_ID_redGpuToCpuSignalGetStatus                     = 55,
  RED_PROCEDURE_ID_redGpuToCpuSignalUnsignal                      = 56,
  RED_PROCEDURE_ID_redCallsSet                                    = 57,
  RED_PROCEDURE_ID_redCallsEnd                                    = 58,
  RED_PROCEDURE_ID_redGetCallProceduresAndAddresses               = 59,
  RED_PROCEDURE_ID_redQueueSubmit                                 = 60,
  RED_PROCEDURE_ID_redMark                                        = 61,
  RED_PROCEDURE_ID_redMarkSet                                     = 62,
  RED_PROCEDURE_ID_redMarkEnd                                     = 63,
  RED_PROCEDURE_ID_redCreateSurfaceWin32                          = 64, // WSI specific
  RED_PROCEDURE_ID_redCreateSurfaceXlibOrXcb                      = 65, // WSI specific
  RED_PROCEDURE_ID_redCreatePresent                               = 66, // WSI specific
  RED_PROCEDURE_ID_redDestroySurface                              = 67, // WSI specific
  RED_PROCEDURE_ID_redDestroyPresent                              = 68, // WSI specific
  RED_PROCEDURE_ID_redQueueFamilyIndexGetSupportsPresent          = 69, // WSI specific
  RED_PROCEDURE_ID_redSurfaceGetPresentFeatures                   = 70, // WSI specific
  RED_PROCEDURE_ID_redSurfaceGetCurrentPropertiesAndPresentLimits = 71, // WSI specific
  RED_PROCEDURE_ID_redPresentGetImageIndex                        = 72, // WSI specific
  RED_PROCEDURE_ID_redQueuePresent                                = 73, // WSI specific
  RED_PROCEDURE_ID_redDebugArrayGetHandle                         = 74, // Debug specific
  RED_PROCEDURE_ID_redDebugArrayCallPrint                         = 75, // Debug specific
  RED_PROCEDURE_ID_redStructsMemoryAllocateWithInlineSamplers         = 80,
  RED_PROCEDURE_ID_redStructsMemoryAllocateSamplersWithInlineSamplers = 81,
} RedProcedureId;

typedef unsigned RedMultisampleCountBitflags;
typedef enum RedMultisampleCountBitflag {
  RED_MULTISAMPLE_COUNT_BITFLAG_1  = 0b00000000000000000000000000000001,
  RED_MULTISAMPLE_COUNT_BITFLAG_2  = 0b00000000000000000000000000000010,
  RED_MULTISAMPLE_COUNT_BITFLAG_4  = 0b00000000000000000000000000000100,
  RED_MULTISAMPLE_COUNT_BITFLAG_8  = 0b00000000000000000000000000001000,
  RED_MULTISAMPLE_COUNT_BITFLAG_16 = 0b00000000000000000000000000010000,
} RedMultisampleCountBitflag;

typedef enum RedGpuType {
  RED_GPU_TYPE_OTHER      = 0,
  RED_GPU_TYPE_INTEGRATED = 1,
  RED_GPU_TYPE_DISCRETE   = 2,
  RED_GPU_TYPE_VIRTUAL    = 3,
  RED_GPU_TYPE_CPU        = 4,
} RedGpuType;

typedef struct RedMemoryType {
  unsigned  memoryHeapIndex;
  RedBool32 isGpuVram;
  RedBool32 isCpuMappable;
  RedBool32 isCpuCoherent;
  RedBool32 isCpuCached;
} RedMemoryType;

typedef struct RedMemoryHeap {
  uint64_t  memoryBytesCount;
  RedBool32 isGpuVram;
} RedMemoryHeap;

typedef struct RedQueueCopyLimits {    // Draw and compute queues will always report (1, 1, 1)
  unsigned copyBlockTexelsCountWidth;  // x and width  parameters must be integer multiples of this limit
  unsigned copyBlockTexelsCountHeight; // y and height parameters must be integer multiples of this limit
  unsigned copyBlockTexelsCountDepth;  // z and depth  parameters must be integer multiples of this limit
} RedQueueCopyLimits;                  // Copy queues are only required to report (0, 0, 0) which indicates that only whole mip levels must be copied

typedef struct RedImageFormatLimitsDimensions {
  unsigned maxWidth;
  unsigned maxHeight;
  unsigned maxDepth;
} RedImageFormatLimitsDimensions;

typedef struct RedImageFormatLimits {
  RedImageFormatLimitsDimensions maxDimensions;
  unsigned                       maxLevelsCount;
  unsigned                       maxLayersCount;
  RedMultisampleCountBitflags    supportedMultisampleCounts;
  uint64_t                       maxBytesCount;              // Min: 2^31. An upper bound on the total image bytes count, inclusive of all levels and layers. Implementations may have an address space limit on total size of an image, which is advertized by this limit
  RedStatus                      status;
} RedImageFormatLimits;

typedef struct RedImageFormatFeatures {
  RedBool32 supportsCopyR;
  RedBool32 supportsCopyW;
  RedBool32 supportsTextureRO;
  RedBool32 supportsTextureRW;                // Multisample RW textures depend on RedGpuInfo::supportsGpuCodeTextureRWMultisample
  RedBool32 supportsOutputDepthStencil;
  RedBool32 supportsOutputColor;
  RedBool32 supportsTextureROFilteringLinear; // Format can be used for RO textures with RED_SAMPLER_FILTERING_LINEAR, RED_SAMPLER_FILTERING_MIP_LINEAR sampling
  RedBool32 supportsTextureRWAtomics;         // Format can be used for RW textures with atomic operations
  RedBool32 supportsOutputColorBlend;         // Format can be used for output colors with the corresponding RedProcedureState::outputColorsBlendEnable set to 1
} RedImageFormatFeatures;

typedef struct RedGpuInfo {
  RedHandleGpu                   gpu;
  RedHandleGpuDevice             gpuDevice;
  unsigned char                  gpuName[256];
  RedGpuType                     gpuType;
  unsigned                       gpuVendorId;
  unsigned                       gpuDeviceId;
  unsigned                       gpuDriverVersion;
  unsigned char                  gpuProcedureCacheUuid[16];
  // Memory
  unsigned                       memoryTypesCount;
  const RedMemoryType *          memoryTypes;            // Array of memoryTypesCount
  const char * const *           memoryTypesDescription; // Array of memoryTypesCount, can be NULL
  unsigned                       memoryHeapsCount;
  const RedMemoryHeap *          memoryHeaps;            // Array of memoryHeapsCount
  const char * const *           memoryHeapsDescription; // Array of memoryHeapsCount, can be NULL
  // Queues
  unsigned                       queuesCount;
  const RedHandleQueue *         queues;
  const char * const *           queuesDescription; // Array of queuesCount, can be NULL
  const unsigned *               queuesFamilyIndex; // Array of queuesCount
  const RedBool32 *              queuesCanCopy;     // Array of queuesCount
  const RedBool32 *              queuesCanDraw;     // Array of queuesCount
  const RedBool32 *              queuesCanCompute;  // Array of queuesCount
  // Limits: Queues
  const RedQueueCopyLimits *     queuesCopyLimits;  // Array of queuesCount
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
  unsigned                       maxStructPerStageSamplersCount;              // Min: 16                  // Max number of samplers           allowed per-stage in a struct
  unsigned                       maxStructPerStageTextureROsCount;            // Min: 16                  // Max number of RO textures        allowed per-stage in a struct
  unsigned                       maxStructPerStageTextureRWsCount;            // Min: 4                   // Max number of RW textures        allowed per-stage in a struct
  unsigned                       maxStructPerStageAllResourcesCount;          // Min: 128                 // Max number of all resources      allowed per-stage in a struct
  unsigned                       maxStructArrayROCsCount;                     // Min: 12 * stages count   // Max number of RO constant arrays allowed in all stages in a struct
  unsigned                       maxStructArrayRORWsCount;                    // Min: 4  * stages count   // Max number of RO or RW    arrays allowed in all stages in a struct
  unsigned                       maxStructSamplersCount;                      // Min: 16 * stages count   // Max number of samplers           allowed in all stages in a struct
  unsigned                       maxStructTextureROsCount;                    // Min: 16 * stages count   // Max number of RO textures        allowed in all stages in a struct
  unsigned                       maxStructTextureRWsCount;                    // Min: 4  * stages count   // Max number of RW textures        allowed in all stages in a struct
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
  RedBool32                      supportsWsi;                                                     // WSI specific functionality is supported by the GPU.                                                 If this feature is not available, the GPU handle should not be passed to WSI specific procedures
  RedBool32                      supportsMemoryGetBudget;                                         // redMemoryGetBudget can return memory budget values.                                                 If this feature is not available, redMemoryGetBudget::outMemoryBudget values won't be set and redMemoryGetBudget::outStatuses will return RED_STATUS_ERROR_FEATURE_IS_NOT_FOUND
  RedBool32                      supportsFullArrayIndexUint32Value;                               // Full 32-bit range of indices is supported.                                                          If this feature is available,     maxArrayIndexUint32Value must be (2^32)-1. -1 excludes the primitive restart index value of 0xFFFFFFFF
  RedBool32                      supportsSamplerAnisotropy;                                       // Anisotropic filtering is supported.                                                                 If this feature is not available, the redCreateSampler::enableAnisotropy must be set to 0 and the redCreateSampler::maxAnisotropy is ignored
  RedBool32                      supportsTextureDimensionsCubeLayered;                            // Specifies whether RED_TEXTURE_DIMENSIONS_CUBE_LAYERED textures can be created.                      If this feature is available,     the SampledCubeArray and ImageCubeArray IR capabilities can be used
  RedBool32                      supportsProcedureStateRasterizationDepthClamp;                   // Depth clamping is supported.                                                                        If this feature is not available, the RedProcedureState::rasterizationDepthClampEnable             must be set to 0
  RedBool32                      supportsProcedureStateRasterizationDepthBiasDynamic;             // Dynamic depth bias is supported.                                                                    If this feature is not available, the RedProcedureState::rasterizationDepthBiasDynamic             must be set to 0 and redCallSetDynamicDepthBias          must not be called
  RedBool32                      supportsProcedureStateRasterizationDepthBiasClamp;               // Depth bias clamping is supported.                                                                   If this feature is not available, the RedProcedureState::rasterizationDepthBiasStaticClamp         must be set to 0 and if RedProcedureState::rasterizationDepthBiasDynamic is available redCallSetDynamicDepthBias::clamp must be set to 0
  RedBool32                      supportsProcedureStateMultisampleSampleShading;                  // Specifies whether sample shading and multisample interpolation are supported.                       If this feature is not available, the RedProcedureState::multisampleSampleShadingEnable            must be set to 0 and the RedProcedureState::multisampleSampleShadingMin is ignored. This also specifies whether IR can declare the SampleRateShading capability
  RedBool32                      supportsProcedureStateMultisampleAlphaToOne;                     // The fragment alpha component can be forced to maximum representable alpha value.                    If this feature is not available, the RedProcedureState::multisampleAlphaToOneEnable               must be set to 0
  RedBool32                      supportsProcedureStateDepthTestBoundsTest;                       // Depth bounds test is supported.                                                                     If this feature is not available, the RedProcedureState::depthTestBoundsTestEnable                 must be set to 0 and the RedProcedureState::depthTestBoundsTestStaticMin, RedProcedureState::depthTestBoundsTestStaticMax, redCallSetDynamicDepthBounds::min and redCallSetDynamicDepthBounds::max are ignored
  RedBool32                      supportsProcedureStateDepthTestBoundsTestDynamic;                // Dynamic depth bounds test is supported.                                                             If this feature is not available, the RedProcedureState::depthTestBoundsTestDynamic                must be set to 0 and redCallSetDynamicDepthBounds        must not be called
  RedBool32                      supportsProcedureStateStencilTestFrontAndBackDynamicCompareMask; // Dynamic compare mask is supported.                                                                  If this feature is not available, the RedProcedureState::stencilTestFrontAndBackDynamicCompareMask must be set to 0 and redCallSetDynamicStencilCompareMask must not be called
  RedBool32                      supportsProcedureStateStencilTestFrontAndBackDynamicWriteMask;   // Dynamic write mask is supported.                                                                    If this feature is not available, the RedProcedureState::stencilTestFrontAndBackDynamicWriteMask   must be set to 0 and redCallSetDynamicStencilWriteMask   must not be called
  RedBool32                      supportsProcedureStateBlendLogicOp;                              // Logic operations are supported.                                                                     If this feature is not available, the RedProcedureState::blendLogicOpEnable                        must be set to 0 and the RedProcedureState::blendLogicOp is ignored
  RedBool32                      supportsProcedureStateOutputColorsBlendVaryingPerColor;          // Blend operations are controlled per output color.                                                   If this feature is not available, the RedProcedureState::outputColorsBlend* values for all output colors must be identical. Otherwise, different RedProcedureState::outputColorsBlend* values can be provided for output colors
  RedBool32                      supportsProcedureStateOutputColorsBlendDualSource;               // Blend operations which take two sources are supported.                                              If this feature is not available, the RED_BLEND_FACTOR_SOURCE1_COLOR, RED_BLEND_FACTOR_ONE_MINUS_SOURCE1_COLOR, RED_BLEND_FACTOR_SOURCE1_ALPHA or RED_BLEND_FACTOR_ONE_MINUS_SOURCE1_ALPHA must not be used as source or target blend factors
  RedBool32                      supportsMultisampleEmptyOutputVariableMultisampleCount;          // Multisample rate can be different for all procedure calls in an empty output.                       If this feature is not available, the current output is empty, and this is not the first procedure call for the current output, then the multisample count specified by this procedure must match that set in the previous procedure
  RedBool32                      supportsMultisampleStandardSampleLocations;                      // Specifies whether rasterization uses the standard sample locations.                                 If this feature is available,     the implementation uses the documented sample locations. Otherwise, the implementation may use different sample locations
  RedBool32                      supportsGpuCodeWritesAndAtomicsInStageVertex;                    // Writes and atomic operations on RW textures are supported in the vertex   stage.                    If this feature is not available, all RW texture variables used by the vertex   stage in GPU code must be decorated with the NonWritable decoration in IR
  RedBool32                      supportsGpuCodeWritesAndAtomicsInStageFragment;                  // Writes and atomic operations on RW textures are supported in the fragment stage.                    If this feature is not available, all RW texture variables used by the fragment stage in GPU code must be decorated with the NonWritable decoration in IR
  RedBool32                      supportsGpuCodeImageGatherExtended;                              // The extended set of texture gather IR instructions are available in GPU code.                       If this feature is not available, the OpImage*Gather IR instructions do not support the Offset and ConstOffsets operands. This also specifies whether IR can declare the ImageGatherExtended capability
  RedBool32                      supportsGpuCodeTextureRWExtendedFormats;                         // All the extended RW texture formats are available in GPU code.                                      See StorageImageExtendedFormats in IR specification (internal issue 1273, 0a7a04f32bd473bc7428efdbbbe132f33afad68c)
  RedBool32                      supportsGpuCodeTextureRWMultisample;                             // Multisample RW textures are supported.                                                              If this feature is not available, images set as RED_STRUCT_MEMBER_TYPE_TEXTURE_RW must be created with multisample count equal to RED_MULTISAMPLE_COUNT_BITFLAG_1. This also specifies whether IR can declare the StorageImageMultisample capability
  RedBool32                      supportsGpuCodeTextureRWReadWithoutFormat;                       // RW textures don't require a format qualifier to be specified when reading from  RW textures.        If this feature is not available, the OpImageRead  IR instruction must not have an OpTypeImage of Unknown. This also specifies whether IR can declare the StorageImageReadWithoutFormat  capability
  RedBool32                      supportsGpuCodeTextureRWWriteWithoutFormat;                      // RW textures don't require a format qualifier to be specified when writing to    RW textures.        If this feature is not available, the OpImageWrite IR instruction must not have an OpTypeImage of Unknown. This also specifies whether IR can declare the StorageImageWriteWithoutFormat capability
  RedBool32                      supportsGpuCodeDynamicallyIndexableArraysOfArrayROCs;            // Arrays of RO constant arrays can be indexed by dynamically uniform integer expressions in GPU code. If this feature is not available, resources with a struct member type of RED_STRUCT_MEMBER_TYPE_ARRAY_RO_CONSTANT must be indexed only by constant integral expressions when aggregated into arrays in GPU code. This also specifies whether IR can declare the UniformBufferArrayDynamicIndexing capability
  RedBool32                      supportsGpuCodeDynamicallyIndexableArraysOfArrayRORWs;           // Arrays of RO or RW    arrays can be indexed by dynamically uniform integer expressions in GPU code. If this feature is not available, resources with a struct member type of RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW       must be indexed only by constant integral expressions when aggregated into arrays in GPU code. This also indicates whether IR can declare the StorageBufferArrayDynamicIndexing capability
  RedBool32                      supportsGpuCodeDynamicallyIndexableArraysOfSamplers;             // Arrays of samplers           can be indexed by dynamically uniform integer expressions in GPU code. If this feature is not available, resources with a struct member type of RED_STRUCT_MEMBER_TYPE_SAMPLER           must be indexed only by constant integral expressions when aggregated into arrays in GPU code. This also specifies whether IR can declare the SampledImageArrayDynamicIndexing  capability
  RedBool32                      supportsGpuCodeDynamicallyIndexableArraysOfTextureROs;           // Arrays of RO textures        can be indexed by dynamically uniform integer expressions in GPU code. If this feature is not available, resources with a struct member type of RED_STRUCT_MEMBER_TYPE_TEXTURE_RO        must be indexed only by constant integral expressions when aggregated into arrays in GPU code. This also specifies whether IR can declare the SampledImageArrayDynamicIndexing  capability
  RedBool32                      supportsGpuCodeDynamicallyIndexableArraysOfTextureRWs;           // Arrays of RW textures        can be indexed by dynamically uniform integer expressions in GPU code. If this feature is not available, resources with a struct member type of RED_STRUCT_MEMBER_TYPE_TEXTURE_RW        must be indexed only by constant integral expressions when aggregated into arrays in GPU code. This also specifies whether IR can declare the StorageImageArrayDynamicIndexing  capability
  RedBool32                      supportsGpuCodeClipDistance;                                     // Clip distances are supported in GPU code.                                                           If this feature is not available, any members decorated with the ClipDistance built-in decoration must not be read from or written to in GPU code. This also specifies whether IR can declare the ClipDistance capability
  RedBool32                      supportsGpuCodeCullDistance;                                     // Cull distances are supported in GPU code.                                                           If this feature is not available, any members decorated with the CullDistance built-in decoration must not be read from or written to in GPU code. This also specifies whether IR can declare the CullDistance capability
  RedBool32                      supportsGpuCodeInt64;                                            // 64-bit integers (signed and unsigned) are supported in GPU code.                                    If this feature is not available, 64-bit integer        types must not be used in GPU code. This also specifies whether IR can declare the Int64   capability
  RedBool32                      supportsGpuCodeFloat64;                                          // 64-bit floats   (doubles)             are supported in GPU code.                                    If this feature is not available, 64-bit floating-point types must not be used in GPU code. This also specifies whether IR can declare the Float64 capability
  RedBool32                      supportsGpuCodeMinLod;                                           // Image operations that specify the minimum resource LOD are supported in GPU code.                   If this feature is not available, the    MinLod image operand must not be used in GPU code. This also specifies whether IR can declare the MinLod  capability
  // Image formats
  const RedImageFormatLimits *   imageFormatsLimitsImageDimensions1D;                                        // Count: 131, indexable with RedFormat values
  const RedImageFormatLimits *   imageFormatsLimitsImageDimensions2D;                                        // Count: 131, indexable with RedFormat values
  const RedImageFormatLimits *   imageFormatsLimitsImageDimensions2DMultisample;                             // Count: 131, indexable with RedFormat values
  const RedImageFormatLimits *   imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered; // Count: 131, indexable with RedFormat values
  const RedImageFormatLimits *   imageFormatsLimitsImageDimensions3D;                                        // Count: 131, indexable with RedFormat values
  const RedImageFormatLimits *   imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered;     // Count: 131, indexable with RedFormat values
  const RedImageFormatFeatures * imageFormatsFeatures;                                                       // Count: 131, indexable with RedFormat values
  const void *                   optionalInfo;                                                               // A NULL or a pointer to a singly linked list of RedGpuInfoOptionalInfo* structs
} RedGpuInfo;

typedef struct RedStatuses {
  RedStatus      status;
  unsigned       statusCode;
  int            statusHresult;
  RedProcedureId statusProcedureId;
  const char *   statusFile;
  int            statusLine;
  RedStatus      statusError;
  unsigned       statusErrorCode;
  int            statusErrorHresult;
  RedProcedureId statusErrorProcedureId;
  const char *   statusErrorFile;
  int            statusErrorLine;
  unsigned char  statusErrorDescription[512];
} RedStatuses;

struct RedTypeContext {
  unsigned            gpusCount;
  const RedGpuInfo *  gpus;
  const RedStatuses * gpusStatuses; // Array of gpusCount
  RedHandleContext    handle;
  void *              userData;
};

typedef enum RedSdkExtension {
  RED_SDK_EXTENSION_NONE                                      = 0,
  RED_SDK_EXTENSION_ADDITIONAL_INFO_0                         = 1,
  RED_SDK_EXTENSION_WSI_WIN32                                 = 2,  // WSI specific
  RED_SDK_EXTENSION_WSI_XLIB                                  = 3,  // WSI specific
  RED_SDK_EXTENSION_WSI_XCB                                   = 4,  // WSI specific
  RED_SDK_EXTENSION_TREAT_ALL_MAPPABLE_MEMORY_AS_NON_COHERENT = 5,
  RED_SDK_EXTENSION_DRIVER_PROPERTIES                         = 6,
  RED_SDK_EXTENSION_RESOLVE_DEPTH_STENCIL                     = 7,
  RED_SDK_EXTENSION_DEDICATE_MEMORY                           = 8,
  RED_SDK_EXTENSION_PROCEDURE_PARAMETERS_HANDLES              = 9,
  RED_SDK_EXTENSION_BATCH_MEMORY_SET                          = 10,
  RED_SDK_EXTENSION_RASTERIZATION_MODE                        = 11,
  RED_SDK_EXTENSION_FORMAL_MEMORY_MODEL                       = 12,
  RED_SDK_EXTENSION_RAY_TRACING                               = 13,
} RedSdkExtension;

typedef enum RedGpuInfoOptionalInfo {
  RED_GPU_INFO_OPTIONAL_INFO_NONE                                      = 0,
  RED_GPU_INFO_OPTIONAL_INFO_ADDITIONAL_INFO_0                         = 1,
  RED_GPU_INFO_OPTIONAL_INFO_WSI_WIN32                                 = 2,  // WSI specific
  RED_GPU_INFO_OPTIONAL_INFO_WSI_XLIB                                  = 3,  // WSI specific
  RED_GPU_INFO_OPTIONAL_INFO_WSI_XCB                                   = 4,  // WSI specific
  RED_GPU_INFO_OPTIONAL_INFO_TREAT_ALL_MAPPABLE_MEMORY_AS_NON_COHERENT = 5,
  RED_GPU_INFO_OPTIONAL_INFO_DRIVER_PROPERTIES                         = 6,
  RED_GPU_INFO_OPTIONAL_INFO_RESOLVE_DEPTH_STENCIL                     = 7,
  RED_GPU_INFO_OPTIONAL_INFO_DEDICATE_MEMORY                           = 8,
  RED_GPU_INFO_OPTIONAL_INFO_PROCEDURE_PARAMETERS_HANDLES              = 9,
  RED_GPU_INFO_OPTIONAL_INFO_BATCH_MEMORY_SET                          = 10,
  RED_GPU_INFO_OPTIONAL_INFO_RASTERIZATION_MODE                        = 11,
  RED_GPU_INFO_OPTIONAL_INFO_FORMAL_MEMORY_MODEL                       = 12,
  RED_GPU_INFO_OPTIONAL_INFO_RAY_TRACING                               = 13,
} RedGpuInfoOptionalInfo;

typedef enum RedDriverId {
  RED_DRIVER_ID_UNKNOWN                   = 0,
  RED_DRIVER_ID_AMD_PROPRIETARY           = 1,
  RED_DRIVER_ID_AMD_OPEN_SOURCE           = 2,
  RED_DRIVER_ID_MESA_RADV                 = 3,
  RED_DRIVER_ID_NVIDIA_PROPRIETARY        = 4,
  RED_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS = 5,
  RED_DRIVER_ID_INTEL_OPEN_SOURCE_MESA    = 6,
  RED_DRIVER_ID_IMAGINATION_PROPRIETARY   = 7,
  RED_DRIVER_ID_QUALCOMM_PROPRIETARY      = 8,
  RED_DRIVER_ID_ARM_PROPRIETARY           = 9,
  RED_DRIVER_ID_GOOGLE_SWIFTSHADER        = 10,
  RED_DRIVER_ID_GGP_PROPRIETARY           = 11,
  RED_DRIVER_ID_BROADCOM_PROPRIETARY      = 12,
} RedDriverId;

typedef struct RedGpuInfoOptionalInfoIterator {
  unsigned     optionalInfo;
  const void * next;
} RedGpuInfoOptionalInfoIterator;

typedef struct RedGpuInfoOptionalInfoAdditionalInfo0 {
  RedGpuInfoOptionalInfo optionalInfo;
  const void *           next;
  RedBool32              supportsArraysImagesUsageBeforeMemorySet;
  RedBool32              supportsInitialQueueFamilyIndexSetToMaxValueForSimultaneousQueueAccessOfArrays;
  RedBool32              supportsInitialQueueFamilyIndexSetToMaxValueForSimultaneousQueueAccessOfImages;
  RedBool32              supportsInitialQueueFamilyIndexSetToMaxValueForSimultaneousQueueAccessOfImagesMultisample;
  RedBool32              supportsInitialQueueFamilyIndexSetToMaxValueForSimultaneousQueueAccessOfImagesDepthStencil;
} RedGpuInfoOptionalInfoAdditionalInfo0;

typedef struct RedGpuInfoOptionalInfoDriverProperties {
  RedGpuInfoOptionalInfo optionalInfo;
  const void *           next;
  RedDriverId            id;
  unsigned char          name[256];
  unsigned char          info[256];
  unsigned char          compliantWithConformanceTestSuiteVersionMajor;
  unsigned char          compliantWithConformanceTestSuiteVersionMinor;
  unsigned char          compliantWithConformanceTestSuiteVersionSubminor;
  unsigned char          compliantWithConformanceTestSuiteVersionPatch;
} RedGpuInfoOptionalInfoDriverProperties;

typedef struct RedGpuInfoOptionalInfoResolveDepthStencil {
  RedGpuInfoOptionalInfo optionalInfo;
  const void *           next;
  RedBool32              supportsResolveDepthStencil;
  RedBool32              supportsResolveModeDepthSampleIndexZero;
  RedBool32              supportsResolveModeDepthAverage;
  RedBool32              supportsResolveModeDepthMin;
  RedBool32              supportsResolveModeDepthMax;
  RedBool32              supportsResolveModeStencilSampleIndexZero;
  RedBool32              supportsResolveModeStencilAverage;
  RedBool32              supportsResolveModeStencilMin;
  RedBool32              supportsResolveModeStencilMax;
  RedBool32              supportsResolveIndependentNone;
  RedBool32              supportsResolveIndependent;
} RedGpuInfoOptionalInfoResolveDepthStencil;

typedef struct RedGpuInfoOptionalInfoProcedureParametersHandles {
  RedGpuInfoOptionalInfo optionalInfo;
  const void *           next;
  RedBool32              supportsProcedureParametersHandles;
  unsigned               maxProcedureParametersHandlesCount;
} RedGpuInfoOptionalInfoProcedureParametersHandles;

typedef struct RedGpuInfoOptionalInfoRasterizationMode {
  RedGpuInfoOptionalInfo optionalInfo;
  const void *           next;
  RedBool32              supportsRasterizationModeOverestimate;
  RedBool32              supportsRasterizationModeUnderestimate;
  RedBool32              supportsGuaranteedZeroAreaBackFacingTriangles;
  RedBool32              supportsGpuCodeFullyCoveredEXT;
} RedGpuInfoOptionalInfoRasterizationMode;

typedef struct RedGpuInfoOptionalInfoFormalMemoryModel {
  RedGpuInfoOptionalInfo optionalInfo;
  const void *           next;
  RedBool32              supportsFormalMemoryModel;
  RedBool32              supportsFormalMemoryModelGpuScopeSynchronization;
  RedBool32              supportsFormalMemoryModelAvailabilityAndVisibilityChains;
} RedGpuInfoOptionalInfoFormalMemoryModel;

typedef struct RedGpuInfoOptionalInfoRayTracing {
  RedGpuInfoOptionalInfo optionalInfo;
  const void *           next;
  RedBool32              supportsRayTracing;
} RedGpuInfoOptionalInfoRayTracing;

// redMemoryGetBudget

typedef struct RedMemoryBudget {
  unsigned setTo1000237000;
  size_t   setTo0;
  uint64_t memoryHeapsBudget[16]; // Array of RedGpuInfo::memoryHeapsCount
  uint64_t memoryHeapsUsage[16];  // Array of RedGpuInfo::memoryHeapsCount
} RedMemoryBudget;

// redMemoryAllocate
// redMemoryAllocateMappable

typedef unsigned RedMemoryBitflags;
typedef enum RedMemoryBitflag {
  RED_MEMORY_BITFLAG_ALLOW_ATOMICS = 0b00000000000000000000000000000001,
} RedMemoryBitflag;

// redMemorySet

typedef struct RedMemoryArray {
  unsigned        setTo1000157000;
  size_t          setTo0;
  RedHandleArray  array;
  RedHandleMemory memory;
  uint64_t        memoryBytesFirst;
} RedMemoryArray;

typedef struct RedMemoryImage {
  unsigned        setTo1000157001;
  size_t          setTo0;
  RedHandleImage  image;
  RedHandleMemory memory;
  uint64_t        memoryBytesFirst;
} RedMemoryImage;

// redMemoryNonCoherentFlush
// redMemoryNonCoherentInvalidate

typedef struct RedMappableMemoryRange {
  unsigned        setTo6;
  size_t          setTo0;
  RedHandleMemory mappableMemory;
  uint64_t        mappableMemoryRangeBytesFirst;
  uint64_t        mappableMemoryRangeBytesCount;
} RedMappableMemoryRange;

// redStructsSet

typedef enum RedStructMemberType {
  RED_STRUCT_MEMBER_TYPE_ARRAY_RO_CONSTANT = 6,
  RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW       = 7,
  RED_STRUCT_MEMBER_TYPE_SAMPLER           = 0,
  RED_STRUCT_MEMBER_TYPE_TEXTURE_RO        = 2,
  RED_STRUCT_MEMBER_TYPE_TEXTURE_RW        = 3,
} RedStructMemberType;

typedef struct RedStructMemberTexture {
  RedHandleSampler sampler;
  RedHandleTexture texture;
  unsigned         setTo1;
} RedStructMemberTexture;

typedef struct RedStructMemberArray {
  RedHandleArray   array;
  uint64_t         arrayRangeBytesFirst;
  uint64_t         arrayRangeBytesCount;
} RedStructMemberArray;

typedef struct RedStructMember {
  unsigned                       setTo35;
  size_t                         setTo0;
  RedHandleStruct                structure;
  unsigned                       slot;
  unsigned                       first;
  unsigned                       count;
  RedStructMemberType            type;
  const RedStructMemberTexture * textures; // Array of count
  const RedStructMemberArray *   arrays;   // Array of count
  size_t                         setTo00;
} RedStructMember;

// redCreateContext

typedef enum RedSdkVersion {
  RED_SDK_VERSION_1_0_135 = 0,
} RedSdkVersion;

typedef enum RedContextOptionalSettings {
  RED_CONTEXT_OPTIONAL_SETTINGS_0           = 0,
  RED_CONTEXT_OPTIONAL_SETTINGS_DEBUG_ARRAY = 1, // Debug specific
  RED_CONTEXT_OPTIONAL_SETTINGS_CREATE_CONTEXT_PERFORMANCE = 4,
} RedContextOptionalSettings;

typedef struct RedContextOptionalSettingsIterator {
  unsigned     settings;
  const void * next;
} RedContextOptionalSettingsIterator;

typedef struct RedContextOptionalSettings0 {
  RedContextOptionalSettings settings;
  const void *               next;
  RedBool32                  skipCheckingContextLayers;
  RedBool32                  skipCheckingContextExtensions;
  RedBool32                  gpusExposeOnlyOneQueue;
} RedContextOptionalSettings0;

typedef struct RedContextOptionalSettingsCreateContextPerformance {
  RedContextOptionalSettings settings;
  void *                     next;
  RedBool32                  exposeOnlyOneGpu;
} RedContextOptionalSettingsCreateContextPerformance;

typedef enum RedDebugCallbackSeverity {
  RED_DEBUG_CALLBACK_SEVERITY_WARNING = 0b00000000000000000000000100000000,
  RED_DEBUG_CALLBACK_SEVERITY_ERROR   = 0b00000000000000000001000000000000,
} RedDebugCallbackSeverity;

typedef unsigned RedDebugCallbackTypeBitflags;
typedef enum RedDebugCallbackTypeBitflag {
  RED_DEBUG_CALLBACK_TYPE_BITFLAG_GENERAL    = 0b00000000000000000000000000000001,
  RED_DEBUG_CALLBACK_TYPE_BITFLAG_VALIDATION = 0b00000000000000000000000000000010,
} RedDebugCallbackTypeBitflag;

typedef enum RedHandleType {
  RED_HANDLE_TYPE_CONTEXT              = 1,
  RED_HANDLE_TYPE_GPU                  = 3,
  RED_HANDLE_TYPE_GPU_DEVICE           = 2,
  RED_HANDLE_TYPE_QUEUE                = 4,
  RED_HANDLE_TYPE_MEMORY               = 8,
  RED_HANDLE_TYPE_ARRAY                = 9,
  RED_HANDLE_TYPE_IMAGE                = 10,
  RED_HANDLE_TYPE_SAMPLER              = 21,
  RED_HANDLE_TYPE_TEXTURE              = 14,
  RED_HANDLE_TYPE_GPU_CODE             = 15,
  RED_HANDLE_TYPE_OUTPUT_DECLARATION   = 18,
  RED_HANDLE_TYPE_STRUCT_DECLARATION   = 20,
  RED_HANDLE_TYPE_PROCEDURE_PARAMETERS = 17,
  RED_HANDLE_TYPE_PROCEDURE_CACHE      = 16,
  RED_HANDLE_TYPE_PROCEDURE            = 19,
  RED_HANDLE_TYPE_OUTPUT               = 24,
  RED_HANDLE_TYPE_STRUCT               = 23,
  RED_HANDLE_TYPE_STRUCTS_MEMORY       = 22,
  RED_HANDLE_TYPE_CALLS                = 6,
  RED_HANDLE_TYPE_CALLS_MEMORY         = 25,
  RED_HANDLE_TYPE_CPU_SIGNAL           = 7,
  RED_HANDLE_TYPE_GPU_SIGNAL           = 5,
  RED_HANDLE_TYPE_GPU_TO_CPU_SIGNAL    = 11,
  RED_HANDLE_TYPE_SURFACE              = 1000000000, // WSI specific
  RED_HANDLE_TYPE_PRESENT              = 1000001000, // WSI specific
} RedHandleType;

typedef struct RedHandleInfo {
  unsigned      _0;
  const void *  _1;
  RedHandleType handleType;
  const void *  handle;
  const char *  handleName;
} RedHandleInfo;

typedef struct RedDebugCallbackData {
  unsigned              _0;
  const void *          _1;
  unsigned              statusCode;
  const char *          messageIdName;
  int                   statusHresult;
  const char *          message;
  unsigned              _2;
  const void *          _3;
  unsigned              _4;
  const void *          _5;
  unsigned              handleInfosCount;
  const RedHandleInfo * handleInfos;
} RedDebugCallbackData;

typedef struct RedMemoryAllocationTag {
  unsigned char tag[512];
} RedMemoryAllocationTag;

typedef void * (*RedTypeProcedureMalloc)       (size_t bytesCount);
typedef void   (*RedTypeProcedureFree)         (void * pointer);
typedef void * (*RedTypeProcedureMallocTagged) (size_t bytesCount, unsigned procedureId, uint64_t memoryAllocationCode, const RedMemoryAllocationTag * optionalMemoryAllocationTag, const char * optionalFile, int optionalLine, void * optionalUserData);
typedef void   (*RedTypeProcedureFreeTagged)   (void * pointer, unsigned procedureId, uint64_t memoryAllocationCode, const RedMemoryAllocationTag * optionalMemoryAllocationTag, const char * optionalFile, int optionalLine, void * optionalUserData);
typedef RedBool32 (*RedTypeProcedureDebugCallback) (RedDebugCallbackSeverity severity, RedDebugCallbackTypeBitflags types, const RedDebugCallbackData * data, RedContext context);

// redCreateArray

typedef enum RedArrayType {
  RED_ARRAY_TYPE_ARRAY_RW          = 0b00000000000000000000000000100011, // GPU code: RWByteAddressBuffer (RW), RWStructuredBuffer<T> (RW). RWByteAddressBuffer's Load() method expects a byte offset and returns uint value that can be casted to a float with asfloat() procedure. Structured buffer elements cannot be larger than 2048 bytes
  RED_ARRAY_TYPE_ARRAY_RO          = 0b10000000000000000000000000000000, // GPU code: ByteAddressBuffer   (RO), StructuredBuffer<T>   (RO). ByteAddressBuffer's   Load() method expects a byte offset and returns uint value that can be casted to a float with asfloat() procedure. Structured buffer elements cannot be larger than 2048 bytes
  RED_ARRAY_TYPE_ARRAY_RO_CONSTANT = 0b00000000000000000000000000010010, // GPU code: ConstantBuffer<T>   (RO)
  RED_ARRAY_TYPE_INDEX_RO          = 0b00000000000000000000000001000010,
} RedArrayType;

// redCreateImage

typedef enum RedImageDimensions {
  RED_IMAGE_DIMENSIONS_1D                                               = 0,
  RED_IMAGE_DIMENSIONS_2D                                               = 1,
  RED_IMAGE_DIMENSIONS_2D_WITH_TEXTURE_DIMENSIONS_CUBE_AND_CUBE_LAYERED = 3,
  RED_IMAGE_DIMENSIONS_3D                                               = 2,
  RED_IMAGE_DIMENSIONS_3D_WITH_TEXTURE_DIMENSIONS_2D_AND_2D_LAYERED     = 4,
} RedImageDimensions;

typedef enum RedFormat {
  RED_FORMAT_UNDEFINED                                      = 0,
  RED_FORMAT_R_8_UINT_TO_FLOAT_0_1                          = 9,   // UINT_TO_FLOAT_0_1: The components are unsigned integer values that get converted to normalized floating-point values in the range [0.f, 1.f]
  RED_FORMAT_R_8_UINT                                       = 13,
  RED_FORMAT_R_8_SINT                                       = 14,
  RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1                 = 37,
  RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED = 43,
  RED_FORMAT_RGBA_8_8_8_8_UINT                              = 41,
  RED_FORMAT_RGBA_8_8_8_8_SINT                              = 42,
  RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1         = 50,  // WSI specific
  RED_FORMAT_R_16_UINT                                      = 74,
  RED_FORMAT_R_16_SINT                                      = 75,
  RED_FORMAT_R_16_FLOAT                                     = 76,
  RED_FORMAT_RGBA_16_16_16_16_UINT                          = 95,
  RED_FORMAT_RGBA_16_16_16_16_SINT                          = 96,
  RED_FORMAT_RGBA_16_16_16_16_FLOAT                         = 97,
  RED_FORMAT_R_32_UINT                                      = 98,
  RED_FORMAT_R_32_SINT                                      = 99,
  RED_FORMAT_R_32_FLOAT                                     = 100,
  RED_FORMAT_RGBA_32_32_32_32_UINT                          = 107,
  RED_FORMAT_RGBA_32_32_32_32_SINT                          = 108,
  RED_FORMAT_RGBA_32_32_32_32_FLOAT                         = 109,
  RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1                     = 124, // RED_IMAGE_PART_BITFLAG_DEPTH
  RED_FORMAT_DEPTH_32_FLOAT                                 = 126, // RED_IMAGE_PART_BITFLAG_DEPTH
  RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT      = 129, // RED_IMAGE_PART_BITFLAG_DEPTH | RED_IMAGE_PART_BITFLAG_STENCIL
  RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT                  = 130, // RED_IMAGE_PART_BITFLAG_DEPTH | RED_IMAGE_PART_BITFLAG_STENCIL
} RedFormat;

// redCreateSampler

typedef enum RedSamplerFiltering {
  RED_SAMPLER_FILTERING_NEAREST = 0,
  RED_SAMPLER_FILTERING_LINEAR  = 1,
} RedSamplerFiltering;

typedef enum RedSamplerFilteringMip {
  RED_SAMPLER_FILTERING_MIP_NEAREST = 0,
  RED_SAMPLER_FILTERING_MIP_LINEAR  = 1,
} RedSamplerFilteringMip;

typedef enum RedSamplerBehaviorOutsideTextureCoordinate {
  RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT              = 0,
  RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT_MIRRORED     = 1,
  RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_CLAMP_TO_EDGE_VALUE = 2,
} RedSamplerBehaviorOutsideTextureCoordinate;

// redCreateTexture

typedef unsigned RedImagePartBitflags;
typedef enum RedImagePartBitflag {
  RED_IMAGE_PART_BITFLAG_COLOR   = 0b00000000000000000000000000000001,
  RED_IMAGE_PART_BITFLAG_DEPTH   = 0b00000000000000000000000000000010, // GPU code: R float channel
  RED_IMAGE_PART_BITFLAG_STENCIL = 0b00000000000000000000000000000100, // GPU code: G uint  channel
} RedImagePartBitflag;

typedef enum RedTextureDimensions {
  RED_TEXTURE_DIMENSIONS_1D           = 0, // GPU code: {RW}Texture1D<T>
  RED_TEXTURE_DIMENSIONS_1D_LAYERED   = 4, // GPU code: {RW}Texture1DArray<T>
  RED_TEXTURE_DIMENSIONS_2D           = 1, // GPU code: {RW}Texture{2D,2DMS}<T>
  RED_TEXTURE_DIMENSIONS_2D_LAYERED   = 5, // GPU code: {RW}Texture{2DArray,2DMSArray}<T>
  RED_TEXTURE_DIMENSIONS_3D           = 2, // GPU code: {RW}Texture3D<T>
  RED_TEXTURE_DIMENSIONS_CUBE         = 3, // GPU code: TextureCube<T>
  RED_TEXTURE_DIMENSIONS_CUBE_LAYERED = 6, // GPU code: TextureCubeArray<T> // Depends on RedGpuInfo::supportsTextureDimensionsCubeLayered
} RedTextureDimensions;

// redCreateOutputDeclaration

typedef enum RedSetProcedureOutputOp {
  RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE = 0,
  RED_SET_PROCEDURE_OUTPUT_OP_CLEAR    = 1,
  RED_SET_PROCEDURE_OUTPUT_OP_DISCARD  = 2,
} RedSetProcedureOutputOp;

typedef enum RedEndProcedureOutputOp {
  RED_END_PROCEDURE_OUTPUT_OP_PRESERVE = 0,
  RED_END_PROCEDURE_OUTPUT_OP_DISCARD  = 1,
} RedEndProcedureOutputOp;

typedef enum RedResolveMode {
  RED_RESOLVE_MODE_NONE              = 0b00000000000000000000000000000000,
  RED_RESOLVE_MODE_SAMPLE_INDEX_ZERO = 0b00000000000000000000000000000001,
  RED_RESOLVE_MODE_AVERAGE           = 0b00000000000000000000000000000010,
  RED_RESOLVE_MODE_MIN               = 0b00000000000000000000000000000100,
  RED_RESOLVE_MODE_MAX               = 0b00000000000000000000000000001000,
} RedResolveMode;

typedef struct RedOutputDeclarationMembers {
  RedBool32                  depthStencilEnable;
  RedFormat                  depthStencilFormat;
  RedMultisampleCountBitflag depthStencilMultisampleCount;
  RedSetProcedureOutputOp    depthStencilDepthSetProcedureOutputOp;
  RedEndProcedureOutputOp    depthStencilDepthEndProcedureOutputOp;
  RedSetProcedureOutputOp    depthStencilStencilSetProcedureOutputOp;
  RedEndProcedureOutputOp    depthStencilStencilEndProcedureOutputOp;
  RedBool32                  depthStencilSharesMemoryWithAnotherMember;
  unsigned                   colorsCount;                               // Max: 8
  RedFormat                  colorsFormat[8];
  RedMultisampleCountBitflag colorsMultisampleCount[8];
  RedSetProcedureOutputOp    colorsSetProcedureOutputOp[8];
  RedEndProcedureOutputOp    colorsEndProcedureOutputOp[8];
  RedBool32                  colorsSharesMemoryWithAnotherMember[8];
} RedOutputDeclarationMembers;

typedef struct RedOutputDeclarationMembersResolveSources {
  RedResolveMode resolveModeDepth;
  RedResolveMode resolveModeStencil;
  RedBool32      resolveDepthStencil;
  RedBool32      resolveColors;
} RedOutputDeclarationMembersResolveSources;

// redCreateStructDeclaration

typedef unsigned RedVisibleToStageBitflags;
typedef enum RedVisibleToStageBitflag {
  RED_VISIBLE_TO_STAGE_BITFLAG_VERTEX   = 0b00000000000000000000000000000001),
  RED_VISIBLE_TO_STAGE_BITFLAG_FRAGMENT = 0b00000000000000000000000000010000),
  RED_VISIBLE_TO_STAGE_BITFLAG_COMPUTE  = 0b00000000000000000000000000100000),
} RedVisibleToStageBitflag;

typedef struct RedStructDeclarationMember {
  unsigned                  slot;
  RedStructMemberType       type;            // RED_SDK_EXTENSION_PROCEDURE_PARAMETERS_HANDLES supported types: RED_STRUCT_MEMBER_TYPE_ARRAY_RO_CONSTANT, RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW
  unsigned                  count;           // RED_SDK_EXTENSION_PROCEDURE_PARAMETERS_HANDLES supported count: 1, RedStructDeclarationMember::inlineSampler supported count: 1
  RedVisibleToStageBitflags visibleToStages;
  const RedHandleSampler *  inlineSampler;   // Array of 1
} RedStructDeclarationMember;

typedef struct RedStructDeclarationMemberArrayRO {
  unsigned                  slot;
} RedStructDeclarationMemberArrayRO;

// redCreateProcedureParameters

typedef struct RedProcedureParametersDeclaration {
  unsigned                   variablesSlot;
  RedVisibleToStageBitflags  variablesVisibleToStages;
  unsigned                   variablesBytesCount;
  unsigned                   structsDeclarationsCount; // Max: 7
  RedHandleStructDeclaration structsDeclarations[7];
  RedHandleStructDeclaration handlesDeclaration;
} RedProcedureParametersDeclaration;

// redCreateProcedure

typedef enum RedPrimitiveTopology {
  RED_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST  = 3,
  RED_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP = 4,
} RedPrimitiveTopology;

typedef enum RedCullMode {
  RED_CULL_MODE_NONE  = 0b00000000000000000000000000000000,
  RED_CULL_MODE_FRONT = 0b00000000000000000000000000000001,
  RED_CULL_MODE_BACK  = 0b00000000000000000000000000000010,
} RedCullMode;

typedef enum RedFrontFace {
  RED_FRONT_FACE_COUNTER_CLOCKWISE = 0,
  RED_FRONT_FACE_CLOCKWISE         = 1,
} RedFrontFace;

typedef enum RedCompareOp {
  RED_COMPARE_OP_NEVER            = 0,
  RED_COMPARE_OP_LESS             = 1,
  RED_COMPARE_OP_EQUAL            = 2,
  RED_COMPARE_OP_LESS_OR_EQUAL    = 3,
  RED_COMPARE_OP_GREATER          = 4,
  RED_COMPARE_OP_NOT_EQUAL        = 5,
  RED_COMPARE_OP_GREATER_OR_EQUAL = 6,
  RED_COMPARE_OP_ALWAYS           = 7,
} RedCompareOp;

typedef enum RedStencilOp {
  RED_STENCIL_OP_KEEP                = 0,
  RED_STENCIL_OP_ZERO                = 1,
  RED_STENCIL_OP_REPLACE             = 2,
  RED_STENCIL_OP_INCREMENT_AND_CLAMP = 3,
  RED_STENCIL_OP_DECREMENT_AND_CLAMP = 4,
  RED_STENCIL_OP_INVERT              = 5,
  RED_STENCIL_OP_INCREMENT_AND_WRAP  = 6,
  RED_STENCIL_OP_DECREMENT_AND_WRAP  = 7,
} RedStencilOp;

typedef enum RedLogicOp {
  RED_LOGIC_OP_CLEAR         = 0,
  RED_LOGIC_OP_AND           = 1,
  RED_LOGIC_OP_AND_REVERSE   = 2,
  RED_LOGIC_OP_COPY          = 3,
  RED_LOGIC_OP_AND_INVERTED  = 4,
  RED_LOGIC_OP_NO_OP         = 5,
  RED_LOGIC_OP_XOR           = 6,
  RED_LOGIC_OP_OR            = 7,
  RED_LOGIC_OP_NOR           = 8,
  RED_LOGIC_OP_EQUIVALENT    = 9,
  RED_LOGIC_OP_INVERT        = 10,
  RED_LOGIC_OP_OR_REVERSE    = 11,
  RED_LOGIC_OP_COPY_INVERTED = 12,
  RED_LOGIC_OP_OR_INVERTED   = 13,
  RED_LOGIC_OP_NAND          = 14,
  RED_LOGIC_OP_SET           = 15,
} RedLogicOp;

typedef unsigned RedColorComponentBitflags;
typedef enum RedColorComponentBitflag {
  RED_COLOR_COMPONENT_BITFLAG_R = 0b00000000000000000000000000000001,
  RED_COLOR_COMPONENT_BITFLAG_G = 0b00000000000000000000000000000010,
  RED_COLOR_COMPONENT_BITFLAG_B = 0b00000000000000000000000000000100,
  RED_COLOR_COMPONENT_BITFLAG_A = 0b00000000000000000000000000001000,
} RedColorComponentBitflag;

typedef enum RedBlendFactor {
  RED_BLEND_FACTOR_ZERO                     = 0,
  RED_BLEND_FACTOR_ONE                      = 1,
  RED_BLEND_FACTOR_SOURCE_COLOR             = 2,
  RED_BLEND_FACTOR_ONE_MINUS_SOURCE_COLOR   = 3,
  RED_BLEND_FACTOR_TARGET_COLOR             = 4,
  RED_BLEND_FACTOR_ONE_MINUS_TARGET_COLOR   = 5,
  RED_BLEND_FACTOR_SOURCE_ALPHA             = 6,
  RED_BLEND_FACTOR_ONE_MINUS_SOURCE_ALPHA   = 7,
  RED_BLEND_FACTOR_TARGET_ALPHA             = 8,
  RED_BLEND_FACTOR_ONE_MINUS_TARGET_ALPHA   = 9,
  RED_BLEND_FACTOR_CONSTANT_COLOR           = 10,
  RED_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR = 11,
  RED_BLEND_FACTOR_SOURCE_ALPHA_SATURATE    = 14,
  RED_BLEND_FACTOR_SOURCE1_COLOR            = 15, // Depends on RedGpuInfo::supportsProcedureStateOutputColorsBlendDualSource
  RED_BLEND_FACTOR_ONE_MINUS_SOURCE1_COLOR  = 16, // Depends on RedGpuInfo::supportsProcedureStateOutputColorsBlendDualSource
  RED_BLEND_FACTOR_SOURCE1_ALPHA            = 17, // Depends on RedGpuInfo::supportsProcedureStateOutputColorsBlendDualSource
  RED_BLEND_FACTOR_ONE_MINUS_SOURCE1_ALPHA  = 18, // Depends on RedGpuInfo::supportsProcedureStateOutputColorsBlendDualSource
} RedBlendFactor;

typedef enum RedBlendOp {
  RED_BLEND_OP_ADD              = 0,
  RED_BLEND_OP_SUBTRACT         = 1,
  RED_BLEND_OP_REVERSE_SUBTRACT = 2,
  RED_BLEND_OP_MIN              = 3,
  RED_BLEND_OP_MAX              = 4,
} RedBlendOp;

typedef struct RedProcedureState {
  RedPrimitiveTopology       inputAssemblyTopology;
  RedBool32                  inputAssemblyPrimitiveRestartEnable;
  RedBool32                  viewportDynamic;
  float                      viewportStaticX;
  float                      viewportStaticY;
  float                      viewportStaticWidth;
  float                      viewportStaticHeight;
  float                      viewportStaticDepthMin;
  float                      viewportStaticDepthMax;
  RedBool32                  scissorDynamic;
  int                        scissorStaticX;
  int                        scissorStaticY;
  unsigned                   scissorStaticWidth;
  unsigned                   scissorStaticHeight;
  RedBool32                  rasterizationDepthClampEnable;                  // Depends on RedGpuInfo::supportsProcedureStateRasterizationDepthClamp
  RedBool32                  rasterizationDiscardAllPrimitivesEnable;
  RedCullMode                rasterizationCullMode;
  RedFrontFace               rasterizationFrontFace;
  RedBool32                  rasterizationDepthBiasEnable;
  RedBool32                  rasterizationDepthBiasDynamic;                  // Depends on RedGpuInfo::supportsProcedureStateRasterizationDepthBiasDynamic
  float                      rasterizationDepthBiasStaticConstantFactor;
  float                      rasterizationDepthBiasStaticClamp;              // Depends on RedGpuInfo::supportsProcedureStateRasterizationDepthBiasClamp
  float                      rasterizationDepthBiasStaticSlopeFactor;
  RedMultisampleCountBitflag multisampleCount;
  const unsigned *           multisampleSampleMask;                          // Array of 1
  RedBool32                  multisampleSampleShadingEnable;                 // Depends on RedGpuInfo::supportsProcedureStateMultisampleSampleShading
  float                      multisampleSampleShadingMin;                    // Depends on RedGpuInfo::supportsProcedureStateMultisampleSampleShading
  RedBool32                  multisampleAlphaToCoverageEnable;
  RedBool32                  multisampleAlphaToOneEnable;                    // Depends on RedGpuInfo::supportsProcedureStateMultisampleAlphaToOne
  RedBool32                  depthTestEnable;
  RedBool32                  depthTestDepthWriteEnable;
  RedCompareOp               depthTestDepthCompareOp;
  RedBool32                  depthTestBoundsTestEnable;                      // Depends on RedGpuInfo::supportsProcedureStateDepthTestBoundsTest
  RedBool32                  depthTestBoundsTestDynamic;                     // Depends on RedGpuInfo::supportsProcedureStateDepthTestBoundsTest and RedGpuInfo::supportsProcedureStateDepthTestBoundsTestDynamic
  float                      depthTestBoundsTestStaticMin;                   // Depends on RedGpuInfo::supportsProcedureStateDepthTestBoundsTest
  float                      depthTestBoundsTestStaticMax;                   // Depends on RedGpuInfo::supportsProcedureStateDepthTestBoundsTest
  RedBool32                  stencilTestEnable;
  RedStencilOp               stencilTestFrontStencilTestFailOp;
  RedStencilOp               stencilTestFrontStencilTestPassDepthTestPassOp;
  RedStencilOp               stencilTestFrontStencilTestPassDepthTestFailOp;
  RedCompareOp               stencilTestFrontCompareOp;
  RedStencilOp               stencilTestBackStencilTestFailOp;
  RedStencilOp               stencilTestBackStencilTestPassDepthTestPassOp;
  RedStencilOp               stencilTestBackStencilTestPassDepthTestFailOp;
  RedCompareOp               stencilTestBackCompareOp;
  RedBool32                  stencilTestFrontAndBackDynamicCompareMask;      // Depends on RedGpuInfo::supportsProcedureStateStencilTestFrontAndBackDynamicCompareMask
  RedBool32                  stencilTestFrontAndBackDynamicWriteMask;        // Depends on RedGpuInfo::supportsProcedureStateStencilTestFrontAndBackDynamicWriteMask
  RedBool32                  stencilTestFrontAndBackDynamicReference;
  unsigned                   stencilTestFrontAndBackStaticCompareMask;
  unsigned                   stencilTestFrontAndBackStaticWriteMask;
  unsigned                   stencilTestFrontAndBackStaticReference;
  RedBool32                  blendLogicOpEnable;                             // Depends on RedGpuInfo::supportsProcedureStateBlendLogicOp
  RedLogicOp                 blendLogicOp;                                   // Depends on RedGpuInfo::supportsProcedureStateBlendLogicOp
  RedBool32                  blendConstantsDynamic;
  float                      blendConstantsStatic[4];
  unsigned                   outputColorsCount;                              // Max: 8
  RedColorComponentBitflags  outputColorsWriteMask[8];                       // Depends on RedGpuInfo::supportsProcedureStateOutputColorsBlendVaryingPerColor
  RedBool32                  outputColorsBlendEnable[8];                     // Depends on RedGpuInfo::supportsProcedureStateOutputColorsBlendVaryingPerColor
  RedBlendFactor             outputColorsBlendColorFactorSource[8];          // Depends on RedGpuInfo::supportsProcedureStateOutputColorsBlendVaryingPerColor
  RedBlendFactor             outputColorsBlendColorFactorTarget[8];          // Depends on RedGpuInfo::supportsProcedureStateOutputColorsBlendVaryingPerColor
  RedBlendOp                 outputColorsBlendColorOp[8];                    // Depends on RedGpuInfo::supportsProcedureStateOutputColorsBlendVaryingPerColor
  RedBlendFactor             outputColorsBlendAlphaFactorSource[8];          // Depends on RedGpuInfo::supportsProcedureStateOutputColorsBlendVaryingPerColor
  RedBlendFactor             outputColorsBlendAlphaFactorTarget[8];          // Depends on RedGpuInfo::supportsProcedureStateOutputColorsBlendVaryingPerColor
  RedBlendOp                 outputColorsBlendAlphaOp[8];                    // Depends on RedGpuInfo::supportsProcedureStateOutputColorsBlendVaryingPerColor
} RedProcedureState;

typedef enum RedProcedureStateExtension {
  RED_PROCEDURE_STATE_EXTENSION_UNDEFINED          = 0,
  RED_PROCEDURE_STATE_EXTENSION_RASTERIZATION_MODE = 1,
} RedProcedureStateExtension;

typedef enum RedRasterizationMode {
  RED_RASTERIZATION_MODE_DEFAULT       = 0,
  RED_RASTERIZATION_MODE_OVERESTIMATE  = 1, // Depends on RedGpuInfoOptionalInfoRasterizationMode::supportsRasterizationModeOverestimate
  RED_RASTERIZATION_MODE_UNDERESTIMATE = 2, // Depends on RedGpuInfoOptionalInfoRasterizationMode::supportsRasterizationModeUnderestimate
} RedRasterizationMode;

typedef struct RedProcedureStateExtensionIterator {
  unsigned     extension;
  const void * next;
} RedProcedureStateExtensionIterator;

typedef struct RedProcedureStateExtensionRasterizationMode {
  RedProcedureStateExtension extension;
  const void *               next;
  RedRasterizationMode       rasterizationMode;
} RedProcedureStateExtensionRasterizationMode;

// redCreateOutput

typedef struct RedOutputMembers {
  RedHandleTexture depthStencil;
  unsigned         colorsCount;  // Max: 8
  RedHandleTexture colors[8];
} RedOutputMembers;

typedef struct RedOutputMembersResolveTargets {
  RedHandleTexture depthStencil;
  RedHandleTexture colors[8];
} RedOutputMembersResolveTargets;

// Memory

void redMemoryGetBudget                 (RedContext context, RedHandleGpu gpu, RedMemoryBudget * outMemoryBudget, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redMemoryAllocate                  (RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t bytesCount, unsigned memoryTypeIndex, RedHandleArray dedicateToArray, RedHandleImage dedicateToImage, unsigned memoryBitflags, RedHandleMemory * outMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redMemoryAllocateMappable          (RedContext context, RedHandleGpu gpu, const char * handleName, RedBool32 dedicate, RedHandleArray array, uint64_t arrayMemoryBytesCount, unsigned memoryTypeIndex, unsigned memoryBitflags, RedHandleMemory * outMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redMemoryFree                      (RedContext context, RedHandleGpu gpu, RedHandleMemory memory, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redMemorySet                       (RedContext context, RedHandleGpu gpu, unsigned memoryArraysCount, const RedMemoryArray * memoryArrays, unsigned memoryImagesCount, const RedMemoryImage * memoryImages, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redMemoryMap                       (RedContext context, RedHandleGpu gpu, RedHandleMemory mappableMemory, uint64_t mappableMemoryBytesFirst, uint64_t mappableMemoryBytesCount, void ** outVolatilePointer, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redMemoryUnmap                     (RedContext context, RedHandleGpu gpu, RedHandleMemory mappableMemory, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redMemoryNonCoherentFlush          (RedContext context, RedHandleGpu gpu, unsigned mappableMemoryRangesCount, const RedMappableMemoryRange * mappableMemoryRanges, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redMemoryNonCoherentInvalidate     (RedContext context, RedHandleGpu gpu, unsigned mappableMemoryRangesCount, const RedMappableMemoryRange * mappableMemoryRanges, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}

// Struct

void redStructsMemoryAllocate           (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned maxStructsCount, unsigned maxStructsMembersOfTypeArrayROConstantCount, unsigned maxStructsMembersOfTypeArrayROOrArrayRWCount, unsigned maxStructsMembersOfTypeTextureROCount, unsigned maxStructsMembersOfTypeTextureRWCount, RedHandleStructsMemory * outStructsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redStructsMemoryAllocateSamplers   (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned maxStructsCount, unsigned maxStructsMembersOfTypeSamplerCount, RedHandleStructsMemory * outStructsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redStructsMemorySuballocateStructs (RedContext context, RedHandleGpu gpu, const char * const * handleNames, RedHandleStructsMemory structsMemory, unsigned structsDeclarationsCount, const RedHandleStructDeclaration * structsDeclarations, RedHandleStruct * outStructs, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redStructsMemoryReset              (RedContext context, RedHandleGpu gpu, RedHandleStructsMemory structsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redStructsMemoryFree               (RedContext context, RedHandleGpu gpu, RedHandleStructsMemory structsMemory, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redStructsSet                      (RedContext context, RedHandleGpu gpu, unsigned structsMembersCount, const RedStructMember * structsMembers, const char * optionalFile, int optionalLine, void * optionalUserData) {}

// Create

void redCreateContext                   (RedTypeProcedureMalloc malloc, RedTypeProcedureFree free, RedTypeProcedureMallocTagged optionalMallocTagged, RedTypeProcedureFreeTagged optionalFreeTagged, RedTypeProcedureDebugCallback debugCallback, RedSdkVersion sdkVersion, unsigned sdkExtensionsCount, const unsigned * sdkExtensions, const char * optionalProgramName, unsigned optionalProgramVersion, const char * optionalEngineName, unsigned optionalEngineVersion, const void * optionalSettings, RedContext * outContext, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateArray                     (RedContext context, RedHandleGpu gpu, const char * handleName, RedArrayType type, uint64_t bytesCount, uint64_t structuredBufferElementBytesCount, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedArray * outArray, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateImage                     (RedContext context, RedHandleGpu gpu, const char * handleName, RedImageDimensions dimensions, RedFormat format, unsigned width, unsigned height, unsigned depth, unsigned levelsCount, unsigned layersCount, RedMultisampleCountBitflag multisampleCount, RedAccessBitflags restrictToAccess, RedAccessBitflags initialAccess, unsigned initialQueueFamilyIndex, RedBool32 dedicate, RedImage * outImage, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateSampler                   (RedContext context, RedHandleGpu gpu, const char * handleName, RedSamplerFiltering filteringMag, RedSamplerFiltering filteringMin, RedSamplerFilteringMip filteringMip, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateU, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateV, RedSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateW, float mipLodBias, RedBool32 enableAnisotropy, float maxAnisotropy, RedBool32 enableCompare, RedCompareOp compareOp, float minLod, float maxLod, RedHandleSampler * outSampler, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateTexture                   (RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleImage image, RedImagePartBitflags parts, RedTextureDimensions dimensions, RedFormat format, unsigned levelsFirst, unsigned levelsCount, unsigned layersFirst, unsigned layersCount, RedAccessBitflags restrictToAccess, RedHandleTexture * outTexture, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateGpuCode                   (RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t irBytesCount, const void * ir, RedHandleGpuCode * outGpuCode, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateOutputDeclaration         (RedContext context, RedHandleGpu gpu, const char * handleName, const RedOutputDeclarationMembers * outputDeclarationMembers, const RedOutputDeclarationMembersResolveSources * outputDeclarationMembersResolveSources, RedBool32 dependencyByRegion, RedBool32 dependencyByRegionAllowUsageAliasOrderBarriers, RedHandleOutputDeclaration * outOutputDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateStructDeclaration         (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned structDeclarationMembersCount, const RedStructDeclarationMember * structDeclarationMembers, unsigned structDeclarationMembersArrayROCount, const RedStructDeclarationMemberArrayRO * structDeclarationMembersArrayRO, RedBool32 procedureParametersHandlesDeclaration, RedHandleStructDeclaration * outStructDeclaration, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateProcedureParameters       (RedContext context, RedHandleGpu gpu, const char * handleName, const RedProcedureParametersDeclaration * procedureParametersDeclaration, RedHandleProcedureParameters * outProcedureParameters, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateProcedureCache            (RedContext context, RedHandleGpu gpu, const char * handleName, uint64_t fromBlobBytesCount, const void * fromBlob, RedHandleProcedureCache * outProcedureCache, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateProcedure                 (RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, RedHandleOutputDeclaration outputDeclaration, RedHandleProcedureParameters procedureParameters, const char * gpuCodeVertexMainProcedureName, RedHandleGpuCode gpuCodeVertex, const char * gpuCodeFragmentMainProcedureName, RedHandleGpuCode gpuCodeFragment, const RedProcedureState * state, const void * stateExtension, RedBool32 deriveBase, RedHandleProcedure deriveFrom, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateProcedureCompute          (RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleProcedureCache procedureCache, RedHandleProcedureParameters procedureParameters, const char * gpuCodeMainProcedureName, RedHandleGpuCode gpuCode, RedHandleProcedure * outProcedure, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateOutput                    (RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleOutputDeclaration outputDeclaration, const RedOutputMembers * outputMembers, const RedOutputMembersResolveTargets * outputMembersResolveTargets, unsigned width, unsigned height, RedOutput * outOutput, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateCpuSignal                 (RedContext context, RedHandleGpu gpu, const char * handleName, RedBool32 createSignaled, RedHandleCpuSignal * outCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateGpuSignal                 (RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleGpuSignal * outGpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateGpuToCpuSignal            (RedContext context, RedHandleGpu gpu, const char * handleName, RedHandleGpuToCpuSignal * outGpuToCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateCalls                     (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, RedCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCreateCallsReusable             (RedContext context, RedHandleGpu gpu, const char * handleName, unsigned queueFamilyIndex, RedCalls * outCalls, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}

// Destroy

void redDestroyContext                  (RedContext context, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyArray                    (RedContext context, RedHandleGpu gpu, RedHandleArray array, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyImage                    (RedContext context, RedHandleGpu gpu, RedHandleImage image, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroySampler                  (RedContext context, RedHandleGpu gpu, RedHandleSampler sampler, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyTexture                  (RedContext context, RedHandleGpu gpu, RedHandleTexture texture, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyGpuCode                  (RedContext context, RedHandleGpu gpu, RedHandleGpuCode gpuCode, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyOutputDeclaration        (RedContext context, RedHandleGpu gpu, RedHandleOutputDeclaration outputDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyStructDeclaration        (RedContext context, RedHandleGpu gpu, RedHandleStructDeclaration structDeclaration, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyProcedureParameters      (RedContext context, RedHandleGpu gpu, RedHandleProcedureParameters procedureParameters, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyProcedureCache           (RedContext context, RedHandleGpu gpu, RedHandleProcedureCache procedureCache, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyProcedure                (RedContext context, RedHandleGpu gpu, RedHandleProcedure procedure, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyOutput                   (RedContext context, RedHandleGpu gpu, RedHandleOutput output, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyCpuSignal                (RedContext context, RedHandleGpu gpu, RedHandleCpuSignal cpuSignal, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyGpuSignal                (RedContext context, RedHandleGpu gpu, RedHandleGpuSignal gpuSignal, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyGpuToCpuSignal           (RedContext context, RedHandleGpu gpu, RedHandleGpuToCpuSignal gpuToCpuSignal, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redDestroyCalls                    (RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedHandleCallsMemory callsMemory, const char * optionalFile, int optionalLine, void * optionalUserData) {}

// Procedure cache

void redProcedureCacheGetBlob           (RedContext context, RedHandleGpu gpu, RedHandleProcedureCache procedureCache, uint64_t * outBlobBytesCount, void * outBlob, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redProcedureCacheMergeCaches       (RedContext context, RedHandleGpu gpu, unsigned sourceProcedureCachesCount, const RedHandleProcedureCache * sourceProcedureCaches, RedHandleProcedureCache targetProcedureCache, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}

// CPU signal

void redCpuSignalGetStatus              (RedContext context, RedHandleGpu gpu, RedHandleCpuSignal cpuSignal, RedStatus * outStatus, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCpuSignalWait                   (RedContext context, RedHandleGpu gpu, unsigned cpuSignalsCount, const RedHandleCpuSignal * cpuSignals, RedBool32 waitAll, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCpuSignalUnsignal               (RedContext context, RedHandleGpu gpu, unsigned cpuSignalsCount, const RedHandleCpuSignal * cpuSignals, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}

// GPU to CPU signal

void redGpuToCpuSignalGetStatus         (RedContext context, RedHandleGpu gpu, RedHandleGpuToCpuSignal gpuToCpuSignal, RedStatus * outStatus, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redGpuToCpuSignalUnsignal          (RedContext context, RedHandleGpu gpu, RedHandleGpuToCpuSignal gpuToCpuSignal, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}

// Calls

void redCallsSet                        (RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedHandleCallsMemory callsMemory, RedBool32 callsReusable, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
void redCallsEnd                        (RedContext context, RedHandleGpu gpu, RedHandleCalls calls, RedHandleCallsMemory callsMemory, RedStatuses * outStatuses, const char * optionalFile, int optionalLine, void * optionalUserData) {}
