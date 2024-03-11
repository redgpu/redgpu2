#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals)]
pub type size_t = usize;
pub type uint64_t = u64;
pub type RedBool32 = libc::c_uint;
#[repr(C)]
pub struct RedTypeContext {
  pub gpusCount: libc::c_uint,
  pub gpus: *const RedGpuInfo,
  pub gpusStatuses: *const RedStatuses,
  pub handle: RedHandleContext,
  pub userData: *mut libc::c_void,
}
pub type RedHandleContext = *const libc::c_void;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedStatuses {
  pub status: RedStatus,
  pub statusCode: libc::c_uint,
  pub statusHresult: libc::c_int,
  pub statusProcedureId: RedProcedureId,
  pub statusFile: *const libc::c_char,
  pub statusLine: libc::c_int,
  pub statusError: RedStatus,
  pub statusErrorCode: libc::c_uint,
  pub statusErrorHresult: libc::c_int,
  pub statusErrorProcedureId: RedProcedureId,
  pub statusErrorFile: *const libc::c_char,
  pub statusErrorLine: libc::c_int,
  pub statusErrorDescription: [libc::c_uchar; 512],
}
pub type RedProcedureId = libc::c_uint;
pub const RED_PROCEDURE_ID_redStructsMemoryAllocateSamplersWithInlineSamplers: RedProcedureId = 81;
pub const RED_PROCEDURE_ID_redStructsMemoryAllocateWithInlineSamplers: RedProcedureId = 80;
pub const RED_PROCEDURE_ID_redDebugArrayCallPrint: RedProcedureId = 75;
pub const RED_PROCEDURE_ID_redDebugArrayGetHandle: RedProcedureId = 74;
pub const RED_PROCEDURE_ID_redQueuePresent: RedProcedureId = 73;
pub const RED_PROCEDURE_ID_redPresentGetImageIndex: RedProcedureId = 72;
pub const RED_PROCEDURE_ID_redSurfaceGetCurrentPropertiesAndPresentLimits: RedProcedureId = 71;
pub const RED_PROCEDURE_ID_redSurfaceGetPresentFeatures: RedProcedureId = 70;
pub const RED_PROCEDURE_ID_redQueueFamilyIndexGetSupportsPresent: RedProcedureId = 69;
pub const RED_PROCEDURE_ID_redDestroyPresent: RedProcedureId = 68;
pub const RED_PROCEDURE_ID_redDestroySurface: RedProcedureId = 67;
pub const RED_PROCEDURE_ID_redCreatePresent: RedProcedureId = 66;
pub const RED_PROCEDURE_ID_redCreateSurfaceXlibOrXcb: RedProcedureId = 65;
pub const RED_PROCEDURE_ID_redCreateSurfaceWin32: RedProcedureId = 64;
pub const RED_PROCEDURE_ID_redMarkEnd: RedProcedureId = 63;
pub const RED_PROCEDURE_ID_redMarkSet: RedProcedureId = 62;
pub const RED_PROCEDURE_ID_redMark: RedProcedureId = 61;
pub const RED_PROCEDURE_ID_redQueueSubmit: RedProcedureId = 60;
pub const RED_PROCEDURE_ID_redGetCallProceduresAndAddresses: RedProcedureId = 59;
pub const RED_PROCEDURE_ID_redCallsEnd: RedProcedureId = 58;
pub const RED_PROCEDURE_ID_redCallsSet: RedProcedureId = 57;
pub const RED_PROCEDURE_ID_redGpuToCpuSignalUnsignal: RedProcedureId = 56;
pub const RED_PROCEDURE_ID_redGpuToCpuSignalGetStatus: RedProcedureId = 55;
pub const RED_PROCEDURE_ID_redCpuSignalUnsignal: RedProcedureId = 54;
pub const RED_PROCEDURE_ID_redCpuSignalWait: RedProcedureId = 53;
pub const RED_PROCEDURE_ID_redCpuSignalGetStatus: RedProcedureId = 52;
pub const RED_PROCEDURE_ID_redProcedureCacheMergeCaches: RedProcedureId = 51;
pub const RED_PROCEDURE_ID_redProcedureCacheGetBlob: RedProcedureId = 50;
pub const RED_PROCEDURE_ID_redDestroyCalls: RedProcedureId = 49;
pub const RED_PROCEDURE_ID_redDestroyGpuToCpuSignal: RedProcedureId = 48;
pub const RED_PROCEDURE_ID_redDestroyGpuSignal: RedProcedureId = 47;
pub const RED_PROCEDURE_ID_redDestroyCpuSignal: RedProcedureId = 46;
pub const RED_PROCEDURE_ID_redDestroyOutput: RedProcedureId = 45;
pub const RED_PROCEDURE_ID_redDestroyProcedure: RedProcedureId = 44;
pub const RED_PROCEDURE_ID_redDestroyProcedureCache: RedProcedureId = 43;
pub const RED_PROCEDURE_ID_redDestroyProcedureParameters: RedProcedureId = 42;
pub const RED_PROCEDURE_ID_redDestroyStructDeclaration: RedProcedureId = 41;
pub const RED_PROCEDURE_ID_redDestroyOutputDeclaration: RedProcedureId = 40;
pub const RED_PROCEDURE_ID_redDestroyGpuCode: RedProcedureId = 39;
pub const RED_PROCEDURE_ID_redDestroyTexture: RedProcedureId = 38;
pub const RED_PROCEDURE_ID_redDestroySampler: RedProcedureId = 37;
pub const RED_PROCEDURE_ID_redDestroyImage: RedProcedureId = 36;
pub const RED_PROCEDURE_ID_redDestroyArray: RedProcedureId = 35;
pub const RED_PROCEDURE_ID_redDestroyContext: RedProcedureId = 34;
pub const RED_PROCEDURE_ID_redCreateCallsReusable: RedProcedureId = 33;
pub const RED_PROCEDURE_ID_redCreateCalls: RedProcedureId = 32;
pub const RED_PROCEDURE_ID_redCreateGpuToCpuSignal: RedProcedureId = 31;
pub const RED_PROCEDURE_ID_redCreateGpuSignal: RedProcedureId = 30;
pub const RED_PROCEDURE_ID_redCreateCpuSignal: RedProcedureId = 29;
pub const RED_PROCEDURE_ID_redCreateOutput: RedProcedureId = 28;
pub const RED_PROCEDURE_ID_redCreateProcedureCompute: RedProcedureId = 27;
pub const RED_PROCEDURE_ID_redCreateProcedure: RedProcedureId = 26;
pub const RED_PROCEDURE_ID_redCreateProcedureCache: RedProcedureId = 25;
pub const RED_PROCEDURE_ID_redCreateProcedureParameters: RedProcedureId = 24;
pub const RED_PROCEDURE_ID_redCreateStructDeclaration: RedProcedureId = 23;
pub const RED_PROCEDURE_ID_redCreateOutputDeclaration: RedProcedureId = 22;
pub const RED_PROCEDURE_ID_redCreateGpuCode: RedProcedureId = 21;
pub const RED_PROCEDURE_ID_redCreateTexture: RedProcedureId = 20;
pub const RED_PROCEDURE_ID_redCreateSampler: RedProcedureId = 19;
pub const RED_PROCEDURE_ID_redCreateImage: RedProcedureId = 18;
pub const RED_PROCEDURE_ID_redCreateArray: RedProcedureId = 17;
pub const RED_PROCEDURE_ID_redCreateContext: RedProcedureId = 16;
pub const RED_PROCEDURE_ID_redStructsSet: RedProcedureId = 15;
pub const RED_PROCEDURE_ID_redStructsMemoryFree: RedProcedureId = 14;
pub const RED_PROCEDURE_ID_redStructsMemoryReset: RedProcedureId = 13;
pub const RED_PROCEDURE_ID_redStructsMemorySuballocateStructs: RedProcedureId = 12;
pub const RED_PROCEDURE_ID_redStructsMemoryAllocateSamplers: RedProcedureId = 11;
pub const RED_PROCEDURE_ID_redStructsMemoryAllocate: RedProcedureId = 10;
pub const RED_PROCEDURE_ID_redMemoryNonCoherentInvalidate: RedProcedureId = 9;
pub const RED_PROCEDURE_ID_redMemoryNonCoherentFlush: RedProcedureId = 8;
pub const RED_PROCEDURE_ID_redMemoryUnmap: RedProcedureId = 7;
pub const RED_PROCEDURE_ID_redMemoryMap: RedProcedureId = 6;
pub const RED_PROCEDURE_ID_redMemorySet: RedProcedureId = 5;
pub const RED_PROCEDURE_ID_redMemoryFree: RedProcedureId = 4;
pub const RED_PROCEDURE_ID_redMemoryAllocateMappable: RedProcedureId = 3;
pub const RED_PROCEDURE_ID_redMemoryAllocate: RedProcedureId = 2;
pub const RED_PROCEDURE_ID_redMemoryGetBudget: RedProcedureId = 1;
pub const RED_PROCEDURE_ID_UNDEFINED: RedProcedureId = 0;
pub type RedStatus = libc::c_int;
pub const RED_STATUS_ERROR_INVALID_GPU_CODE: RedStatus = -1000012000;
pub const RED_STATUS_ERROR_VALIDATION_FAILED: RedStatus = -1000011001;
pub const RED_STATUS_ERROR_PRESENT_IS_OUT_OF_DATE: RedStatus = -1000001004;
pub const RED_STATUS_ERROR_SURFACE_IS_LOST: RedStatus = -1000000000;
pub const RED_STATUS_ERROR_WINDOW_IS_ALREADY_USED: RedStatus = -1000000001;
pub const RED_STATUS_ERROR_MEMORY_OVERFLOW: RedStatus = -1000069000;
pub const RED_STATUS_ERROR_MEMORY_IS_FRAGMENTED: RedStatus = -12;
pub const RED_STATUS_ERROR_FORMAT_IS_NOT_SUPPORTED: RedStatus = -11;
pub const RED_STATUS_ERROR_TOO_MANY_HANDLES: RedStatus = -10;
pub const RED_STATUS_ERROR_INCOMPATIBLE_DRIVER: RedStatus = -9;
pub const RED_STATUS_ERROR_FEATURE_IS_NOT_FOUND: RedStatus = -8;
pub const RED_STATUS_ERROR_EXTENSION_IS_NOT_FOUND: RedStatus = -7;
pub const RED_STATUS_ERROR_LAYER_IS_NOT_FOUND: RedStatus = -6;
pub const RED_STATUS_ERROR_MEMORY_MAPPING_FAILED: RedStatus = -5;
pub const RED_STATUS_ERROR_GPU_IS_LOST: RedStatus = -4;
pub const RED_STATUS_ERROR_INITIALIZATION_FAILED: RedStatus = -3;
pub const RED_STATUS_ERROR_OUT_OF_GPU_MEMORY: RedStatus = -2;
pub const RED_STATUS_ERROR_OUT_OF_CPU_MEMORY: RedStatus = -1;
pub const RED_STATUS_PRESENT_IS_SUBOPTIMAL: RedStatus = 1000001003;
pub const RED_STATUS_INCOMPLETE: RedStatus = 5;
pub const RED_STATUS_GPU_TO_CPU_SIGNAL_UNSIGNALED: RedStatus = 4;
pub const RED_STATUS_GPU_TO_CPU_SIGNAL_SIGNALED: RedStatus = 3;
pub const RED_STATUS_TIMEOUT: RedStatus = 2;
pub const RED_STATUS_NOT_READY: RedStatus = 1;
pub const RED_STATUS_SUCCESS: RedStatus = 0;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedGpuInfo {
  pub gpu: RedHandleGpu,
  pub gpuDevice: RedHandleGpuDevice,
  pub gpuName: [libc::c_uchar; 256],
  pub gpuType: RedGpuType,
  pub gpuVendorId: libc::c_uint,
  pub gpuDeviceId: libc::c_uint,
  pub gpuDriverVersion: libc::c_uint,
  pub gpuProcedureCacheUuid: [libc::c_uchar; 16],
  pub memoryTypesCount: libc::c_uint,
  pub memoryTypes: *const RedMemoryType,
  pub memoryTypesDescription: *const *const libc::c_char,
  pub memoryHeapsCount: libc::c_uint,
  pub memoryHeaps: *const RedMemoryHeap,
  pub memoryHeapsDescription: *const *const libc::c_char,
  pub queuesCount: libc::c_uint,
  pub queues: *const RedHandleQueue,
  pub queuesDescription: *const *const libc::c_char,
  pub queuesFamilyIndex: *const libc::c_uint,
  pub queuesCanCopy: *const RedBool32,
  pub queuesCanDraw: *const RedBool32,
  pub queuesCanCompute: *const RedBool32,
  pub queuesCopyLimits: *const RedQueueCopyLimits,
  pub maxMemoryAllocateCount: libc::c_uint,
  pub minMemoryAllocateBytesAlignment: uint64_t,
  pub maxMemoryAllocateBytesCount: uint64_t,
  pub minMemoryNonCoherentBlockBytesCount: uint64_t,
  pub maxCreateSamplerCount: libc::c_uint,
  pub minMemoryPageSeparationArrayImageBytesCount: uint64_t,
  pub minArrayROCStructMemberRangeBytesAlignment: uint64_t,
  pub maxArrayROCStructMemberRangeBytesCount: uint64_t,
  pub minArrayRORWStructMemberRangeBytesAlignment: uint64_t,
  pub maxArrayRORWStructMemberRangeBytesCount: uint64_t,
  pub maxArrayIndexUint32Value: libc::c_uint,
  pub maxImageDimensions1D: libc::c_uint,
  pub maxImageDimensions2D: libc::c_uint,
  pub maxImageDimensions3D: libc::c_uint,
  pub maxImageDimensionsCube: libc::c_uint,
  pub maxImageLayersCount: libc::c_uint,
  pub maxSamplerMipLodBias: libc::c_float,
  pub maxSamplerAnisotropy: libc::c_float,
  pub precisionBitsSamplerFilteringMagMin: libc::c_uint,
  pub precisionBitsSamplerFilteringMip: libc::c_uint,
  pub maxOutputWidth: libc::c_uint,
  pub maxOutputHeight: libc::c_uint,
  pub maxOutputColorsCount: libc::c_uint,
  pub supportedMultisampleCountsForOutputDepth: RedMultisampleCountBitflags,
  pub supportedMultisampleCountsForOutputStencil: RedMultisampleCountBitflags,
  pub supportedMultisampleCountsForOutputColor: RedMultisampleCountBitflags,
  pub supportedMultisampleCountsForEmptyOutput: RedMultisampleCountBitflags,
  pub maxStructSlotsCount: libc::c_uint,
  pub maxStructPerStageArrayROCsCount: libc::c_uint,
  pub maxStructPerStageArrayRORWsCount: libc::c_uint,
  pub maxStructPerStageSamplersCount: libc::c_uint,
  pub maxStructPerStageTextureROsCount: libc::c_uint,
  pub maxStructPerStageTextureRWsCount: libc::c_uint,
  pub maxStructPerStageAllResourcesCount: libc::c_uint,
  pub maxStructArrayROCsCount: libc::c_uint,
  pub maxStructArrayRORWsCount: libc::c_uint,
  pub maxStructSamplersCount: libc::c_uint,
  pub maxStructTextureROsCount: libc::c_uint,
  pub maxStructTextureRWsCount: libc::c_uint,
  pub maxProcedureParametersVariablesBytesCount: libc::c_uint,
  pub maxViewportDimensions: [libc::c_uint; 2],
  pub minViewportBoundsRange: libc::c_float,
  pub maxViewportBoundsRange: libc::c_float,
  pub precisionBitsViewportCoordinates: libc::c_uint,
  pub precisionBitsViewportBounds: libc::c_uint,
  pub maxPerStageClipDistances: libc::c_uint,
  pub maxPerStageCullDistances: libc::c_uint,
  pub maxPerStageClipAndCullDistances: libc::c_uint,
  pub maxVertexOutputLocationsCount: libc::c_uint,
  pub maxFragmentInputLocationsCount: libc::c_uint,
  pub maxFragmentOutputColorsCount: libc::c_uint,
  pub maxFragmentOutputColorsCountBlendDualSource: libc::c_uint,
  pub maxFragmentOutputResourcesCount: libc::c_uint,
  pub maxComputeSharedMemoryBytesCount: libc::c_uint,
  pub maxComputeWorkgroupsCount: [libc::c_uint; 3],
  pub maxComputeWorkgroupInvocationsCount: libc::c_uint,
  pub maxComputeWorkgroupDimensions: [libc::c_uint; 3],
  pub minImageSampleImageFetchOffset: libc::c_int,
  pub maxImageSampleImageFetchOffset: libc::c_uint,
  pub minImageGatherOffset: libc::c_int,
  pub maxImageGatherOffset: libc::c_uint,
  pub minInterpolateAtOffset: libc::c_float,
  pub maxInterpolateAtOffset: libc::c_float,
  pub precisionBitsInterpolateAtOffset: libc::c_uint,
  pub optimalCopyArrayImageRangeArrayBytesFirstBytesAlignment: uint64_t,
  pub optimalCopyArrayImageRangeArrayTexelsCountToNextRowBytesAlignment: uint64_t,
  pub supportsWsi: RedBool32,
  pub supportsMemoryGetBudget: RedBool32,
  pub supportsFullArrayIndexUint32Value: RedBool32,
  pub supportsSamplerAnisotropy: RedBool32,
  pub supportsTextureDimensionsCubeLayered: RedBool32,
  pub supportsProcedureStateRasterizationDepthClamp: RedBool32,
  pub supportsProcedureStateRasterizationDepthBiasDynamic: RedBool32,
  pub supportsProcedureStateRasterizationDepthBiasClamp: RedBool32,
  pub supportsProcedureStateMultisampleSampleShading: RedBool32,
  pub supportsProcedureStateMultisampleAlphaToOne: RedBool32,
  pub supportsProcedureStateDepthTestBoundsTest: RedBool32,
  pub supportsProcedureStateDepthTestBoundsTestDynamic: RedBool32,
  pub supportsProcedureStateStencilTestFrontAndBackDynamicCompareMask: RedBool32,
  pub supportsProcedureStateStencilTestFrontAndBackDynamicWriteMask: RedBool32,
  pub supportsProcedureStateBlendLogicOp: RedBool32,
  pub supportsProcedureStateOutputColorsBlendVaryingPerColor: RedBool32,
  pub supportsProcedureStateOutputColorsBlendDualSource: RedBool32,
  pub supportsMultisampleEmptyOutputVariableMultisampleCount: RedBool32,
  pub supportsMultisampleStandardSampleLocations: RedBool32,
  pub supportsGpuCodeWritesAndAtomicsInStageVertex: RedBool32,
  pub supportsGpuCodeWritesAndAtomicsInStageFragment: RedBool32,
  pub supportsGpuCodeImageGatherExtended: RedBool32,
  pub supportsGpuCodeTextureRWExtendedFormats: RedBool32,
  pub supportsGpuCodeTextureRWMultisample: RedBool32,
  pub supportsGpuCodeTextureRWReadWithoutFormat: RedBool32,
  pub supportsGpuCodeTextureRWWriteWithoutFormat: RedBool32,
  pub supportsGpuCodeDynamicallyIndexableArraysOfArrayROCs: RedBool32,
  pub supportsGpuCodeDynamicallyIndexableArraysOfArrayRORWs: RedBool32,
  pub supportsGpuCodeDynamicallyIndexableArraysOfSamplers: RedBool32,
  pub supportsGpuCodeDynamicallyIndexableArraysOfTextureROs: RedBool32,
  pub supportsGpuCodeDynamicallyIndexableArraysOfTextureRWs: RedBool32,
  pub supportsGpuCodeClipDistance: RedBool32,
  pub supportsGpuCodeCullDistance: RedBool32,
  pub supportsGpuCodeInt64: RedBool32,
  pub supportsGpuCodeFloat64: RedBool32,
  pub supportsGpuCodeMinLod: RedBool32,
  pub imageFormatsLimitsImageDimensions1D: *const RedImageFormatLimits,
  pub imageFormatsLimitsImageDimensions2D: *const RedImageFormatLimits,
  pub imageFormatsLimitsImageDimensions2DMultisample: *const RedImageFormatLimits,
  pub imageFormatsLimitsImageDimensions2DWithTextureDimensionsCubeAndCubeLayered: *const RedImageFormatLimits,
  pub imageFormatsLimitsImageDimensions3D: *const RedImageFormatLimits,
  pub imageFormatsLimitsImageDimensions3DWithTextureDimensions2DAnd2DLayered: *const RedImageFormatLimits,
  pub imageFormatsFeatures: *const RedImageFormatFeatures,
  pub optionalInfo: *const libc::c_void,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedImageFormatFeatures {
  pub supportsCopyR: RedBool32,
  pub supportsCopyW: RedBool32,
  pub supportsTextureRO: RedBool32,
  pub supportsTextureRW: RedBool32,
  pub supportsOutputDepthStencil: RedBool32,
  pub supportsOutputColor: RedBool32,
  pub supportsTextureROFilteringLinear: RedBool32,
  pub supportsTextureRWAtomics: RedBool32,
  pub supportsOutputColorBlend: RedBool32,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedImageFormatLimits {
  pub maxDimensions: RedImageFormatLimitsDimensions,
  pub maxLevelsCount: libc::c_uint,
  pub maxLayersCount: libc::c_uint,
  pub supportedMultisampleCounts: RedMultisampleCountBitflags,
  pub maxBytesCount: uint64_t,
  pub status: RedStatus,
}
pub type RedMultisampleCountBitflags = libc::c_uint;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedImageFormatLimitsDimensions {
  pub maxWidth: libc::c_uint,
  pub maxHeight: libc::c_uint,
  pub maxDepth: libc::c_uint,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedQueueCopyLimits {
  pub copyBlockTexelsCountWidth: libc::c_uint,
  pub copyBlockTexelsCountHeight: libc::c_uint,
  pub copyBlockTexelsCountDepth: libc::c_uint,
}
pub type RedHandleQueue = *const libc::c_void;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedMemoryHeap {
  pub memoryBytesCount: uint64_t,
  pub isGpuVram: RedBool32,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedMemoryType {
  pub memoryHeapIndex: libc::c_uint,
  pub isGpuVram: RedBool32,
  pub isCpuMappable: RedBool32,
  pub isCpuCoherent: RedBool32,
  pub isCpuCached: RedBool32,
}
pub type RedGpuType = libc::c_uint;
pub const RED_GPU_TYPE_CPU: RedGpuType = 4;
pub const RED_GPU_TYPE_VIRTUAL: RedGpuType = 3;
pub const RED_GPU_TYPE_DISCRETE: RedGpuType = 2;
pub const RED_GPU_TYPE_INTEGRATED: RedGpuType = 1;
pub const RED_GPU_TYPE_OTHER: RedGpuType = 0;
pub type RedHandleGpuDevice = *const libc::c_void;
pub type RedHandleGpu = *const libc::c_void;
pub type RedContext = *const RedTypeContext;
pub type RedHandleMemory = *const libc::c_void;
pub type RedHandleArray = *const libc::c_void;
pub type RedHandleImage = *const libc::c_void;
pub type RedHandleSampler = *const libc::c_void;
pub type RedHandleTexture = *const libc::c_void;
pub type RedHandleGpuCode = *const libc::c_void;
pub type RedHandleOutputDeclaration = *const libc::c_void;
pub type RedHandleStructDeclaration = *const libc::c_void;
pub type RedHandleProcedureParameters = *const libc::c_void;
pub type RedHandleProcedureCache = *const libc::c_void;
pub type RedHandleProcedure = *const libc::c_void;
pub type RedHandleOutput = *const libc::c_void;
pub type RedHandleStruct = *const libc::c_void;
pub type RedHandleStructsMemory = *const libc::c_void;
pub type RedHandleCalls = *const libc::c_void;
pub type RedHandleCallsMemory = *const libc::c_void;
pub type RedHandleCpuSignal = *const libc::c_void;
pub type RedHandleGpuSignal = *const libc::c_void;
pub type RedHandleGpuToCpuSignal = *const libc::c_void;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedArray {
  pub handle: RedHandleArray,
  pub memoryBytesAlignment: uint64_t,
  pub memoryBytesCount: uint64_t,
  pub memoryTypesSupported: libc::c_uint,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedImage {
  pub handle: RedHandleImage,
  pub memoryBytesAlignment: uint64_t,
  pub memoryBytesCount: uint64_t,
  pub memoryTypesSupported: libc::c_uint,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedOutput {
  pub handle: RedHandleOutput,
  pub width: libc::c_uint,
  pub height: libc::c_uint,
  pub depthStencilEnable: RedBool32,
  pub colorsCount: libc::c_uint,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedCalls {
  pub handle: RedHandleCalls,
  pub memory: RedHandleCallsMemory,
  pub reusable: RedBool32,
}
pub type RedMultisampleCountBitflag = libc::c_uint;
pub const RED_MULTISAMPLE_COUNT_BITFLAG_16: RedMultisampleCountBitflag = 16;
pub const RED_MULTISAMPLE_COUNT_BITFLAG_8: RedMultisampleCountBitflag = 8;
pub const RED_MULTISAMPLE_COUNT_BITFLAG_4: RedMultisampleCountBitflag = 4;
pub const RED_MULTISAMPLE_COUNT_BITFLAG_2: RedMultisampleCountBitflag = 2;
pub const RED_MULTISAMPLE_COUNT_BITFLAG_1: RedMultisampleCountBitflag = 1;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedMemoryBudget {
  pub setTo1000237000: libc::c_uint,
  pub setTo0: size_t,
  pub memoryHeapsBudget: [uint64_t; 16],
  pub memoryHeapsUsage: [uint64_t; 16],
}
pub type RedMemoryBitflags = libc::c_uint;
pub type RedMemoryBitflag = libc::c_uint;
pub const RED_MEMORY_BITFLAG_ALLOW_ATOMICS: RedMemoryBitflag = 1;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedMemoryArray {
  pub setTo1000157000: libc::c_uint,
  pub setTo0: size_t,
  pub array: RedHandleArray,
  pub memory: RedHandleMemory,
  pub memoryBytesFirst: uint64_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedMemoryImage {
  pub setTo1000157001: libc::c_uint,
  pub setTo0: size_t,
  pub image: RedHandleImage,
  pub memory: RedHandleMemory,
  pub memoryBytesFirst: uint64_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedMappableMemoryRange {
  pub setTo6: libc::c_uint,
  pub setTo0: size_t,
  pub mappableMemory: RedHandleMemory,
  pub mappableMemoryRangeBytesFirst: uint64_t,
  pub mappableMemoryRangeBytesCount: uint64_t,
}
pub type RedStructMemberType = libc::c_uint;
pub const RED_STRUCT_MEMBER_TYPE_TEXTURE_RW: RedStructMemberType = 3;
pub const RED_STRUCT_MEMBER_TYPE_TEXTURE_RO: RedStructMemberType = 2;
pub const RED_STRUCT_MEMBER_TYPE_SAMPLER: RedStructMemberType = 0;
pub const RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW: RedStructMemberType = 7;
pub const RED_STRUCT_MEMBER_TYPE_ARRAY_RO_CONSTANT: RedStructMemberType = 6;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedStructMemberTexture {
  pub sampler: RedHandleSampler,
  pub texture: RedHandleTexture,
  pub setTo1: libc::c_uint,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedStructMemberArray {
  pub array: RedHandleArray,
  pub arrayRangeBytesFirst: uint64_t,
  pub arrayRangeBytesCount: uint64_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedStructMember {
  pub setTo35: libc::c_uint,
  pub setTo0: size_t,
  pub structure: RedHandleStruct,
  pub slot: libc::c_uint,
  pub first: libc::c_uint,
  pub count: libc::c_uint,
  pub type_0: RedStructMemberType,
  pub textures: *const RedStructMemberTexture,
  pub arrays: *const RedStructMemberArray,
  pub setTo00: size_t,
}
pub type RedSdkVersion = libc::c_uint;
pub const RED_SDK_VERSION_1_0_135: RedSdkVersion = 0;
pub type RedDebugCallbackSeverity = libc::c_uint;
pub const RED_DEBUG_CALLBACK_SEVERITY_ERROR: RedDebugCallbackSeverity = 4096;
pub const RED_DEBUG_CALLBACK_SEVERITY_WARNING: RedDebugCallbackSeverity = 256;
pub type RedDebugCallbackTypeBitflags = libc::c_uint;
pub type RedDebugCallbackTypeBitflag = libc::c_uint;
pub const RED_DEBUG_CALLBACK_TYPE_BITFLAG_VALIDATION: RedDebugCallbackTypeBitflag = 2;
pub const RED_DEBUG_CALLBACK_TYPE_BITFLAG_GENERAL: RedDebugCallbackTypeBitflag = 1;
pub type RedHandleType = libc::c_uint;
pub const RED_HANDLE_TYPE_PRESENT: RedHandleType = 1000001000;
pub const RED_HANDLE_TYPE_SURFACE: RedHandleType = 1000000000;
pub const RED_HANDLE_TYPE_GPU_TO_CPU_SIGNAL: RedHandleType = 11;
pub const RED_HANDLE_TYPE_GPU_SIGNAL: RedHandleType = 5;
pub const RED_HANDLE_TYPE_CPU_SIGNAL: RedHandleType = 7;
pub const RED_HANDLE_TYPE_CALLS_MEMORY: RedHandleType = 25;
pub const RED_HANDLE_TYPE_CALLS: RedHandleType = 6;
pub const RED_HANDLE_TYPE_STRUCTS_MEMORY: RedHandleType = 22;
pub const RED_HANDLE_TYPE_STRUCT: RedHandleType = 23;
pub const RED_HANDLE_TYPE_OUTPUT: RedHandleType = 24;
pub const RED_HANDLE_TYPE_PROCEDURE: RedHandleType = 19;
pub const RED_HANDLE_TYPE_PROCEDURE_CACHE: RedHandleType = 16;
pub const RED_HANDLE_TYPE_PROCEDURE_PARAMETERS: RedHandleType = 17;
pub const RED_HANDLE_TYPE_STRUCT_DECLARATION: RedHandleType = 20;
pub const RED_HANDLE_TYPE_OUTPUT_DECLARATION: RedHandleType = 18;
pub const RED_HANDLE_TYPE_GPU_CODE: RedHandleType = 15;
pub const RED_HANDLE_TYPE_TEXTURE: RedHandleType = 14;
pub const RED_HANDLE_TYPE_SAMPLER: RedHandleType = 21;
pub const RED_HANDLE_TYPE_IMAGE: RedHandleType = 10;
pub const RED_HANDLE_TYPE_ARRAY: RedHandleType = 9;
pub const RED_HANDLE_TYPE_MEMORY: RedHandleType = 8;
pub const RED_HANDLE_TYPE_QUEUE: RedHandleType = 4;
pub const RED_HANDLE_TYPE_GPU_DEVICE: RedHandleType = 2;
pub const RED_HANDLE_TYPE_GPU: RedHandleType = 3;
pub const RED_HANDLE_TYPE_CONTEXT: RedHandleType = 1;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedHandleInfo {
  pub _0: libc::c_uint,
  pub _1: *const libc::c_void,
  pub handleType: RedHandleType,
  pub handle: *const libc::c_void,
  pub handleName: *const libc::c_char,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedDebugCallbackData {
  pub _0: libc::c_uint,
  pub _1: *const libc::c_void,
  pub statusCode: libc::c_uint,
  pub messageIdName: *const libc::c_char,
  pub statusHresult: libc::c_int,
  pub message: *const libc::c_char,
  pub _2: libc::c_uint,
  pub _3: *const libc::c_void,
  pub _4: libc::c_uint,
  pub _5: *const libc::c_void,
  pub handleInfosCount: libc::c_uint,
  pub handleInfos: *const RedHandleInfo,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedMemoryAllocationTag {
  pub tag: [libc::c_uchar; 512],
}
pub type RedTypeProcedureMalloc = Option::<
  unsafe extern "C" fn(size_t) -> *mut libc::c_void,
>;
pub type RedTypeProcedureFree = Option::<unsafe extern "C" fn(*mut libc::c_void) -> ()>;
pub type RedTypeProcedureMallocTagged = Option::<
  unsafe extern "C" fn(
    size_t,
    libc::c_uint,
    uint64_t,
    *const RedMemoryAllocationTag,
    *const libc::c_char,
    libc::c_int,
    *mut libc::c_void,
  ) -> *mut libc::c_void,
>;
pub type RedTypeProcedureFreeTagged = Option::<
  unsafe extern "C" fn(
    *mut libc::c_void,
    libc::c_uint,
    uint64_t,
    *const RedMemoryAllocationTag,
    *const libc::c_char,
    libc::c_int,
    *mut libc::c_void,
  ) -> (),
>;
pub type RedTypeProcedureDebugCallback = Option::<
  unsafe extern "C" fn(
    RedDebugCallbackSeverity,
    RedDebugCallbackTypeBitflags,
    *const RedDebugCallbackData,
    RedContext,
  ) -> RedBool32,
>;
pub type RedArrayType = libc::c_uint;
pub const RED_ARRAY_TYPE_INDEX_RO: RedArrayType = 66;
pub const RED_ARRAY_TYPE_ARRAY_RO_CONSTANT: RedArrayType = 18;
pub const RED_ARRAY_TYPE_ARRAY_RO: RedArrayType = 2147483648;
pub const RED_ARRAY_TYPE_ARRAY_RW: RedArrayType = 35;
pub type RedImageDimensions = libc::c_uint;
pub const RED_IMAGE_DIMENSIONS_3D_WITH_TEXTURE_DIMENSIONS_2D_AND_2D_LAYERED: RedImageDimensions = 4;
pub const RED_IMAGE_DIMENSIONS_3D: RedImageDimensions = 2;
pub const RED_IMAGE_DIMENSIONS_2D_WITH_TEXTURE_DIMENSIONS_CUBE_AND_CUBE_LAYERED: RedImageDimensions = 3;
pub const RED_IMAGE_DIMENSIONS_2D: RedImageDimensions = 1;
pub const RED_IMAGE_DIMENSIONS_1D: RedImageDimensions = 0;
pub type RedFormat = libc::c_uint;
pub const RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT: RedFormat = 130;
pub const RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT: RedFormat = 129;
pub const RED_FORMAT_DEPTH_32_FLOAT: RedFormat = 126;
pub const RED_FORMAT_DEPTH_16_UINT_TO_FLOAT_0_1: RedFormat = 124;
pub const RED_FORMAT_RGBA_32_32_32_32_FLOAT: RedFormat = 109;
pub const RED_FORMAT_RGBA_32_32_32_32_SINT: RedFormat = 108;
pub const RED_FORMAT_RGBA_32_32_32_32_UINT: RedFormat = 107;
pub const RED_FORMAT_R_32_FLOAT: RedFormat = 100;
pub const RED_FORMAT_R_32_SINT: RedFormat = 99;
pub const RED_FORMAT_R_32_UINT: RedFormat = 98;
pub const RED_FORMAT_RGBA_16_16_16_16_FLOAT: RedFormat = 97;
pub const RED_FORMAT_RGBA_16_16_16_16_SINT: RedFormat = 96;
pub const RED_FORMAT_RGBA_16_16_16_16_UINT: RedFormat = 95;
pub const RED_FORMAT_R_16_FLOAT: RedFormat = 76;
pub const RED_FORMAT_R_16_SINT: RedFormat = 75;
pub const RED_FORMAT_R_16_UINT: RedFormat = 74;
pub const RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1: RedFormat = 50;
pub const RED_FORMAT_RGBA_8_8_8_8_SINT: RedFormat = 42;
pub const RED_FORMAT_RGBA_8_8_8_8_UINT: RedFormat = 41;
pub const RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED: RedFormat = 43;
pub const RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1: RedFormat = 37;
pub const RED_FORMAT_R_8_SINT: RedFormat = 14;
pub const RED_FORMAT_R_8_UINT: RedFormat = 13;
pub const RED_FORMAT_R_8_UINT_TO_FLOAT_0_1: RedFormat = 9;
pub const RED_FORMAT_UNDEFINED: RedFormat = 0;
pub type RedSamplerFiltering = libc::c_uint;
pub const RED_SAMPLER_FILTERING_LINEAR: RedSamplerFiltering = 1;
pub const RED_SAMPLER_FILTERING_NEAREST: RedSamplerFiltering = 0;
pub type RedSamplerFilteringMip = libc::c_uint;
pub const RED_SAMPLER_FILTERING_MIP_LINEAR: RedSamplerFilteringMip = 1;
pub const RED_SAMPLER_FILTERING_MIP_NEAREST: RedSamplerFilteringMip = 0;
pub type RedSamplerBehaviorOutsideTextureCoordinate = libc::c_uint;
pub const RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_CLAMP_TO_EDGE_VALUE: RedSamplerBehaviorOutsideTextureCoordinate = 2;
pub const RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT_MIRRORED: RedSamplerBehaviorOutsideTextureCoordinate = 1;
pub const RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT: RedSamplerBehaviorOutsideTextureCoordinate = 0;
pub type RedImagePartBitflags = libc::c_uint;
pub type RedImagePartBitflag = libc::c_uint;
pub const RED_IMAGE_PART_BITFLAG_STENCIL: RedImagePartBitflag = 4;
pub const RED_IMAGE_PART_BITFLAG_DEPTH: RedImagePartBitflag = 2;
pub const RED_IMAGE_PART_BITFLAG_COLOR: RedImagePartBitflag = 1;
pub type RedTextureDimensions = libc::c_uint;
pub const RED_TEXTURE_DIMENSIONS_CUBE_LAYERED: RedTextureDimensions = 6;
pub const RED_TEXTURE_DIMENSIONS_CUBE: RedTextureDimensions = 3;
pub const RED_TEXTURE_DIMENSIONS_3D: RedTextureDimensions = 2;
pub const RED_TEXTURE_DIMENSIONS_2D_LAYERED: RedTextureDimensions = 5;
pub const RED_TEXTURE_DIMENSIONS_2D: RedTextureDimensions = 1;
pub const RED_TEXTURE_DIMENSIONS_1D_LAYERED: RedTextureDimensions = 4;
pub const RED_TEXTURE_DIMENSIONS_1D: RedTextureDimensions = 0;
pub type RedSetProcedureOutputOp = libc::c_uint;
pub const RED_SET_PROCEDURE_OUTPUT_OP_DISCARD: RedSetProcedureOutputOp = 2;
pub const RED_SET_PROCEDURE_OUTPUT_OP_CLEAR: RedSetProcedureOutputOp = 1;
pub const RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE: RedSetProcedureOutputOp = 0;
pub type RedEndProcedureOutputOp = libc::c_uint;
pub const RED_END_PROCEDURE_OUTPUT_OP_DISCARD: RedEndProcedureOutputOp = 1;
pub const RED_END_PROCEDURE_OUTPUT_OP_PRESERVE: RedEndProcedureOutputOp = 0;
pub type RedResolveMode = libc::c_uint;
pub const RED_RESOLVE_MODE_MAX: RedResolveMode = 8;
pub const RED_RESOLVE_MODE_MIN: RedResolveMode = 4;
pub const RED_RESOLVE_MODE_AVERAGE: RedResolveMode = 2;
pub const RED_RESOLVE_MODE_SAMPLE_INDEX_ZERO: RedResolveMode = 1;
pub const RED_RESOLVE_MODE_NONE: RedResolveMode = 0;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedOutputDeclarationMembers {
  pub depthStencilEnable: RedBool32,
  pub depthStencilFormat: RedFormat,
  pub depthStencilMultisampleCount: RedMultisampleCountBitflag,
  pub depthStencilDepthSetProcedureOutputOp: RedSetProcedureOutputOp,
  pub depthStencilDepthEndProcedureOutputOp: RedEndProcedureOutputOp,
  pub depthStencilStencilSetProcedureOutputOp: RedSetProcedureOutputOp,
  pub depthStencilStencilEndProcedureOutputOp: RedEndProcedureOutputOp,
  pub depthStencilSharesMemoryWithAnotherMember: RedBool32,
  pub colorsCount: libc::c_uint,
  pub colorsFormat: [RedFormat; 8],
  pub colorsMultisampleCount: [RedMultisampleCountBitflag; 8],
  pub colorsSetProcedureOutputOp: [RedSetProcedureOutputOp; 8],
  pub colorsEndProcedureOutputOp: [RedEndProcedureOutputOp; 8],
  pub colorsSharesMemoryWithAnotherMember: [RedBool32; 8],
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedOutputDeclarationMembersResolveSources {
  pub resolveModeDepth: RedResolveMode,
  pub resolveModeStencil: RedResolveMode,
  pub resolveDepthStencil: RedBool32,
  pub resolveColors: RedBool32,
}
pub type RedVisibleToStageBitflags = libc::c_uint;
pub type RedVisibleToStageBitflag = libc::c_uint;
pub const RED_VISIBLE_TO_STAGE_BITFLAG_COMPUTE: RedVisibleToStageBitflag = 32;
pub const RED_VISIBLE_TO_STAGE_BITFLAG_FRAGMENT: RedVisibleToStageBitflag = 16;
pub const RED_VISIBLE_TO_STAGE_BITFLAG_VERTEX: RedVisibleToStageBitflag = 1;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedStructDeclarationMember {
  pub slot: libc::c_uint,
  pub type_0: RedStructMemberType,
  pub count: libc::c_uint,
  pub visibleToStages: RedVisibleToStageBitflags,
  pub inlineSampler: *const RedHandleSampler,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedStructDeclarationMemberArrayRO {
  pub slot: libc::c_uint,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedProcedureParametersDeclaration {
  pub variablesSlot: libc::c_uint,
  pub variablesVisibleToStages: RedVisibleToStageBitflags,
  pub variablesBytesCount: libc::c_uint,
  pub structsDeclarationsCount: libc::c_uint,
  pub structsDeclarations: [RedHandleStructDeclaration; 7],
  pub handlesDeclaration: RedHandleStructDeclaration,
}
pub type RedPrimitiveTopology = libc::c_uint;
pub const RED_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP: RedPrimitiveTopology = 4;
pub const RED_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST: RedPrimitiveTopology = 3;
pub type RedCullMode = libc::c_uint;
pub const RED_CULL_MODE_BACK: RedCullMode = 2;
pub const RED_CULL_MODE_FRONT: RedCullMode = 1;
pub const RED_CULL_MODE_NONE: RedCullMode = 0;
pub type RedFrontFace = libc::c_uint;
pub const RED_FRONT_FACE_CLOCKWISE: RedFrontFace = 1;
pub const RED_FRONT_FACE_COUNTER_CLOCKWISE: RedFrontFace = 0;
pub type RedCompareOp = libc::c_uint;
pub const RED_COMPARE_OP_ALWAYS: RedCompareOp = 7;
pub const RED_COMPARE_OP_GREATER_OR_EQUAL: RedCompareOp = 6;
pub const RED_COMPARE_OP_NOT_EQUAL: RedCompareOp = 5;
pub const RED_COMPARE_OP_GREATER: RedCompareOp = 4;
pub const RED_COMPARE_OP_LESS_OR_EQUAL: RedCompareOp = 3;
pub const RED_COMPARE_OP_EQUAL: RedCompareOp = 2;
pub const RED_COMPARE_OP_LESS: RedCompareOp = 1;
pub const RED_COMPARE_OP_NEVER: RedCompareOp = 0;
pub type RedStencilOp = libc::c_uint;
pub const RED_STENCIL_OP_DECREMENT_AND_WRAP: RedStencilOp = 7;
pub const RED_STENCIL_OP_INCREMENT_AND_WRAP: RedStencilOp = 6;
pub const RED_STENCIL_OP_INVERT: RedStencilOp = 5;
pub const RED_STENCIL_OP_DECREMENT_AND_CLAMP: RedStencilOp = 4;
pub const RED_STENCIL_OP_INCREMENT_AND_CLAMP: RedStencilOp = 3;
pub const RED_STENCIL_OP_REPLACE: RedStencilOp = 2;
pub const RED_STENCIL_OP_ZERO: RedStencilOp = 1;
pub const RED_STENCIL_OP_KEEP: RedStencilOp = 0;
pub type RedLogicOp = libc::c_uint;
pub const RED_LOGIC_OP_SET: RedLogicOp = 15;
pub const RED_LOGIC_OP_NAND: RedLogicOp = 14;
pub const RED_LOGIC_OP_OR_INVERTED: RedLogicOp = 13;
pub const RED_LOGIC_OP_COPY_INVERTED: RedLogicOp = 12;
pub const RED_LOGIC_OP_OR_REVERSE: RedLogicOp = 11;
pub const RED_LOGIC_OP_INVERT: RedLogicOp = 10;
pub const RED_LOGIC_OP_EQUIVALENT: RedLogicOp = 9;
pub const RED_LOGIC_OP_NOR: RedLogicOp = 8;
pub const RED_LOGIC_OP_OR: RedLogicOp = 7;
pub const RED_LOGIC_OP_XOR: RedLogicOp = 6;
pub const RED_LOGIC_OP_NO_OP: RedLogicOp = 5;
pub const RED_LOGIC_OP_AND_INVERTED: RedLogicOp = 4;
pub const RED_LOGIC_OP_COPY: RedLogicOp = 3;
pub const RED_LOGIC_OP_AND_REVERSE: RedLogicOp = 2;
pub const RED_LOGIC_OP_AND: RedLogicOp = 1;
pub const RED_LOGIC_OP_CLEAR: RedLogicOp = 0;
pub type RedColorComponentBitflags = libc::c_uint;
pub type RedColorComponentBitflag = libc::c_uint;
pub const RED_COLOR_COMPONENT_BITFLAG_A: RedColorComponentBitflag = 8;
pub const RED_COLOR_COMPONENT_BITFLAG_B: RedColorComponentBitflag = 4;
pub const RED_COLOR_COMPONENT_BITFLAG_G: RedColorComponentBitflag = 2;
pub const RED_COLOR_COMPONENT_BITFLAG_R: RedColorComponentBitflag = 1;
pub type RedBlendFactor = libc::c_uint;
pub const RED_BLEND_FACTOR_ONE_MINUS_SOURCE1_ALPHA: RedBlendFactor = 18;
pub const RED_BLEND_FACTOR_SOURCE1_ALPHA: RedBlendFactor = 17;
pub const RED_BLEND_FACTOR_ONE_MINUS_SOURCE1_COLOR: RedBlendFactor = 16;
pub const RED_BLEND_FACTOR_SOURCE1_COLOR: RedBlendFactor = 15;
pub const RED_BLEND_FACTOR_SOURCE_ALPHA_SATURATE: RedBlendFactor = 14;
pub const RED_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR: RedBlendFactor = 11;
pub const RED_BLEND_FACTOR_CONSTANT_COLOR: RedBlendFactor = 10;
pub const RED_BLEND_FACTOR_ONE_MINUS_TARGET_ALPHA: RedBlendFactor = 9;
pub const RED_BLEND_FACTOR_TARGET_ALPHA: RedBlendFactor = 8;
pub const RED_BLEND_FACTOR_ONE_MINUS_SOURCE_ALPHA: RedBlendFactor = 7;
pub const RED_BLEND_FACTOR_SOURCE_ALPHA: RedBlendFactor = 6;
pub const RED_BLEND_FACTOR_ONE_MINUS_TARGET_COLOR: RedBlendFactor = 5;
pub const RED_BLEND_FACTOR_TARGET_COLOR: RedBlendFactor = 4;
pub const RED_BLEND_FACTOR_ONE_MINUS_SOURCE_COLOR: RedBlendFactor = 3;
pub const RED_BLEND_FACTOR_SOURCE_COLOR: RedBlendFactor = 2;
pub const RED_BLEND_FACTOR_ONE: RedBlendFactor = 1;
pub const RED_BLEND_FACTOR_ZERO: RedBlendFactor = 0;
pub type RedBlendOp = libc::c_uint;
pub const RED_BLEND_OP_MAX: RedBlendOp = 4;
pub const RED_BLEND_OP_MIN: RedBlendOp = 3;
pub const RED_BLEND_OP_REVERSE_SUBTRACT: RedBlendOp = 2;
pub const RED_BLEND_OP_SUBTRACT: RedBlendOp = 1;
pub const RED_BLEND_OP_ADD: RedBlendOp = 0;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedProcedureState {
  pub inputAssemblyTopology: RedPrimitiveTopology,
  pub inputAssemblyPrimitiveRestartEnable: RedBool32,
  pub viewportDynamic: RedBool32,
  pub viewportStaticX: libc::c_float,
  pub viewportStaticY: libc::c_float,
  pub viewportStaticWidth: libc::c_float,
  pub viewportStaticHeight: libc::c_float,
  pub viewportStaticDepthMin: libc::c_float,
  pub viewportStaticDepthMax: libc::c_float,
  pub scissorDynamic: RedBool32,
  pub scissorStaticX: libc::c_int,
  pub scissorStaticY: libc::c_int,
  pub scissorStaticWidth: libc::c_uint,
  pub scissorStaticHeight: libc::c_uint,
  pub rasterizationDepthClampEnable: RedBool32,
  pub rasterizationDiscardAllPrimitivesEnable: RedBool32,
  pub rasterizationCullMode: RedCullMode,
  pub rasterizationFrontFace: RedFrontFace,
  pub rasterizationDepthBiasEnable: RedBool32,
  pub rasterizationDepthBiasDynamic: RedBool32,
  pub rasterizationDepthBiasStaticConstantFactor: libc::c_float,
  pub rasterizationDepthBiasStaticClamp: libc::c_float,
  pub rasterizationDepthBiasStaticSlopeFactor: libc::c_float,
  pub multisampleCount: RedMultisampleCountBitflag,
  pub multisampleSampleMask: *const libc::c_uint,
  pub multisampleSampleShadingEnable: RedBool32,
  pub multisampleSampleShadingMin: libc::c_float,
  pub multisampleAlphaToCoverageEnable: RedBool32,
  pub multisampleAlphaToOneEnable: RedBool32,
  pub depthTestEnable: RedBool32,
  pub depthTestDepthWriteEnable: RedBool32,
  pub depthTestDepthCompareOp: RedCompareOp,
  pub depthTestBoundsTestEnable: RedBool32,
  pub depthTestBoundsTestDynamic: RedBool32,
  pub depthTestBoundsTestStaticMin: libc::c_float,
  pub depthTestBoundsTestStaticMax: libc::c_float,
  pub stencilTestEnable: RedBool32,
  pub stencilTestFrontStencilTestFailOp: RedStencilOp,
  pub stencilTestFrontStencilTestPassDepthTestPassOp: RedStencilOp,
  pub stencilTestFrontStencilTestPassDepthTestFailOp: RedStencilOp,
  pub stencilTestFrontCompareOp: RedCompareOp,
  pub stencilTestBackStencilTestFailOp: RedStencilOp,
  pub stencilTestBackStencilTestPassDepthTestPassOp: RedStencilOp,
  pub stencilTestBackStencilTestPassDepthTestFailOp: RedStencilOp,
  pub stencilTestBackCompareOp: RedCompareOp,
  pub stencilTestFrontAndBackDynamicCompareMask: RedBool32,
  pub stencilTestFrontAndBackDynamicWriteMask: RedBool32,
  pub stencilTestFrontAndBackDynamicReference: RedBool32,
  pub stencilTestFrontAndBackStaticCompareMask: libc::c_uint,
  pub stencilTestFrontAndBackStaticWriteMask: libc::c_uint,
  pub stencilTestFrontAndBackStaticReference: libc::c_uint,
  pub blendLogicOpEnable: RedBool32,
  pub blendLogicOp: RedLogicOp,
  pub blendConstantsDynamic: RedBool32,
  pub blendConstantsStatic: [libc::c_float; 4],
  pub outputColorsCount: libc::c_uint,
  pub outputColorsWriteMask: [RedColorComponentBitflags; 8],
  pub outputColorsBlendEnable: [RedBool32; 8],
  pub outputColorsBlendColorFactorSource: [RedBlendFactor; 8],
  pub outputColorsBlendColorFactorTarget: [RedBlendFactor; 8],
  pub outputColorsBlendColorOp: [RedBlendOp; 8],
  pub outputColorsBlendAlphaFactorSource: [RedBlendFactor; 8],
  pub outputColorsBlendAlphaFactorTarget: [RedBlendFactor; 8],
  pub outputColorsBlendAlphaOp: [RedBlendOp; 8],
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedOutputMembers {
  pub depthStencil: RedHandleTexture,
  pub colorsCount: libc::c_uint,
  pub colors: [RedHandleTexture; 8],
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedOutputMembersResolveTargets {
  pub depthStencil: RedHandleTexture,
  pub colors: [RedHandleTexture; 8],
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedCopyArrayRange {
  pub arrayRBytesFirst: uint64_t,
  pub arrayWBytesFirst: uint64_t,
  pub bytesCount: uint64_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedCopyImageParts {
  pub allParts: RedImagePartBitflags,
  pub level: libc::c_uint,
  pub layersFirst: libc::c_uint,
  pub layersCount: libc::c_uint,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedCopyImageOffset {
  pub texelX: libc::c_int,
  pub texelY: libc::c_int,
  pub texelZ: libc::c_int,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedCopyImageExtent {
  pub texelsCountWidth: libc::c_uint,
  pub texelsCountHeight: libc::c_uint,
  pub texelsCountDepth: libc::c_uint,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedCopyImageRange {
  pub imageRParts: RedCopyImageParts,
  pub imageROffset: RedCopyImageOffset,
  pub imageWParts: RedCopyImageParts,
  pub imageWOffset: RedCopyImageOffset,
  pub extent: RedCopyImageExtent,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedCopyArrayImageRange {
  pub arrayBytesFirst: uint64_t,
  pub arrayTexelsCountToNextRow: libc::c_uint,
  pub arrayTexelsCountToNextLayerOr3DDepthSliceDividedByTexelsCountToNextRow: libc::c_uint,
  pub imageParts: RedCopyImageParts,
  pub imageOffset: RedCopyImageOffset,
  pub imageExtent: RedCopyImageExtent,
}
pub type RedProcedureType = libc::c_uint;
pub const RED_PROCEDURE_TYPE_COMPUTE: RedProcedureType = 1;
pub const RED_PROCEDURE_TYPE_DRAW: RedProcedureType = 0;
pub type RedProcedureParametersHandleType = libc::c_uint;
pub const RED_PROCEDURE_PARAMETERS_HANDLE_TYPE_ARRAY_RO_RW: RedProcedureParametersHandleType = 7;
pub const RED_PROCEDURE_PARAMETERS_HANDLE_TYPE_ARRAY_RO_CONSTANT: RedProcedureParametersHandleType = 6;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedProcedureParametersHandleArray {
  pub array: RedHandleArray,
  pub setTo0: uint64_t,
  pub setToMaxValue: uint64_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedProcedureParametersHandle {
  pub setTo35: libc::c_uint,
  pub setTo0: size_t,
  pub setTo00: uint64_t,
  pub slot: libc::c_uint,
  pub setTo000: libc::c_uint,
  pub setTo1: libc::c_uint,
  pub type_0: RedProcedureParametersHandleType,
  pub setTo0000: size_t,
  pub array: *const RedProcedureParametersHandleArray,
  pub setTo00000: size_t,
}
pub type RedStencilFace = libc::c_uint;
pub const RED_STENCIL_FACE_FRONT_AND_BACK: RedStencilFace = 3;
pub type RedTypeProcedureCallGpuToCpuSignalSignal = Option::<
  unsafe extern "C" fn(RedHandleCalls, RedHandleGpuToCpuSignal, libc::c_uint) -> (),
>;
pub type RedTypeProcedureCallCopyArrayToArray = Option::<
  unsafe extern "C" fn(
    RedHandleCalls,
    RedHandleArray,
    RedHandleArray,
    libc::c_uint,
    *const RedCopyArrayRange,
  ) -> (),
>;
pub type RedTypeProcedureCallCopyImageToImage = Option::<
  unsafe extern "C" fn(
    RedHandleCalls,
    RedHandleImage,
    libc::c_uint,
    RedHandleImage,
    libc::c_uint,
    libc::c_uint,
    *const RedCopyImageRange,
  ) -> (),
>;
pub type RedTypeProcedureCallCopyArrayToImage = Option::<
  unsafe extern "C" fn(
    RedHandleCalls,
    RedHandleArray,
    RedHandleImage,
    libc::c_uint,
    libc::c_uint,
    *const RedCopyArrayImageRange,
  ) -> (),
>;
pub type RedTypeProcedureCallCopyImageToArray = Option::<
  unsafe extern "C" fn(
    RedHandleCalls,
    RedHandleImage,
    libc::c_uint,
    RedHandleArray,
    libc::c_uint,
    *const RedCopyArrayImageRange,
  ) -> (),
>;
pub type RedTypeProcedureCallProcedure = Option::<
  unsafe extern "C" fn(
    RedHandleCalls,
    libc::c_uint,
    libc::c_uint,
    libc::c_uint,
    libc::c_uint,
  ) -> (),
>;
pub type RedTypeProcedureCallProcedureIndexed = Option::<
  unsafe extern "C" fn(
    RedHandleCalls,
    libc::c_uint,
    libc::c_uint,
    libc::c_uint,
    libc::c_int,
    libc::c_uint,
  ) -> (),
>;
pub type RedTypeProcedureCallProcedureCompute = Option::<
  unsafe extern "C" fn(RedHandleCalls, libc::c_uint, libc::c_uint, libc::c_uint) -> (),
>;
pub type RedTypeProcedureCallSetProcedure = Option::<
  unsafe extern "C" fn(RedHandleCalls, RedProcedureType, RedHandleProcedure) -> (),
>;
pub type RedTypeProcedureCallSetProcedureIndices = Option::<
  unsafe extern "C" fn(RedHandleCalls, RedHandleArray, uint64_t, libc::c_uint) -> (),
>;
pub type RedTypeProcedureCallSetProcedureParametersVariables = Option::<
  unsafe extern "C" fn(
    RedHandleCalls,
    RedHandleProcedureParameters,
    RedVisibleToStageBitflags,
    libc::c_uint,
    libc::c_uint,
    *const libc::c_void,
  ) -> (),
>;
pub type RedTypeProcedureCallSetProcedureParametersStructs = Option::<
  unsafe extern "C" fn(
    RedHandleCalls,
    RedProcedureType,
    RedHandleProcedureParameters,
    libc::c_uint,
    libc::c_uint,
    *const RedHandleStruct,
    libc::c_uint,
    size_t,
  ) -> (),
>;
pub type RedTypeProcedureCallSetProcedureParametersHandles = Option::<
  unsafe extern "C" fn(
    RedHandleCalls,
    RedProcedureType,
    RedHandleProcedureParameters,
    libc::c_uint,
    libc::c_uint,
    *const RedProcedureParametersHandle,
  ) -> (),
>;
pub type RedTypeProcedureCallSetDynamicDepthBias = Option::<
  unsafe extern "C" fn(
    RedHandleCalls,
    libc::c_float,
    libc::c_float,
    libc::c_float,
  ) -> (),
>;
pub type RedTypeProcedureCallSetDynamicDepthBounds = Option::<
  unsafe extern "C" fn(RedHandleCalls, libc::c_float, libc::c_float) -> (),
>;
pub type RedTypeProcedureCallSetDynamicStencilCompareMask = Option::<
  unsafe extern "C" fn(RedHandleCalls, RedStencilFace, libc::c_uint) -> (),
>;
pub type RedTypeProcedureCallSetDynamicStencilWriteMask = Option::<
  unsafe extern "C" fn(RedHandleCalls, RedStencilFace, libc::c_uint) -> (),
>;
pub type RedTypeProcedureCallSetDynamicStencilReference = Option::<
  unsafe extern "C" fn(RedHandleCalls, RedStencilFace, libc::c_uint) -> (),
>;
pub type RedTypeProcedureCallSetDynamicBlendConstants = Option::<
  unsafe extern "C" fn(RedHandleCalls, *const libc::c_float) -> (),
>;
pub type RedTypeProcedureAddressCallSetDynamicViewport = *const libc::c_void;
pub type RedTypeProcedureAddressCallSetDynamicScissor = *const libc::c_void;
pub type RedTypeProcedureAddressCallSetStructsMemory = *const libc::c_void;
pub type RedTypeProcedureAddressCallSetProcedureParameters = *const libc::c_void;
pub type RedTypeProcedureAddressCallSetProcedureOutput = *const libc::c_void;
pub type RedTypeProcedureAddressCallEndProcedureOutput = *const libc::c_void;
pub type RedTypeProcedureAddressCallUsageAliasOrderBarrier = *const libc::c_void;
pub type RedTypeProcedureAddressCallMark = *const libc::c_void;
pub type RedTypeProcedureAddressCallMarkSet = *const libc::c_void;
pub type RedTypeProcedureAddressCallMarkEnd = *const libc::c_void;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedCallProceduresAndAddresses {
  pub redCallGpuToCpuSignalSignal: RedTypeProcedureCallGpuToCpuSignalSignal,
  pub redCallCopyArrayToArray: RedTypeProcedureCallCopyArrayToArray,
  pub redCallCopyImageToImage: RedTypeProcedureCallCopyImageToImage,
  pub redCallCopyArrayToImage: RedTypeProcedureCallCopyArrayToImage,
  pub redCallCopyImageToArray: RedTypeProcedureCallCopyImageToArray,
  pub redCallProcedure: RedTypeProcedureCallProcedure,
  pub redCallProcedureIndexed: RedTypeProcedureCallProcedureIndexed,
  pub redCallProcedureCompute: RedTypeProcedureCallProcedureCompute,
  pub redCallSetProcedure: RedTypeProcedureCallSetProcedure,
  pub redCallSetProcedureIndices: RedTypeProcedureCallSetProcedureIndices,
  pub redCallSetProcedureParametersVariables: RedTypeProcedureCallSetProcedureParametersVariables,
  pub redCallSetProcedureParametersStructs: RedTypeProcedureCallSetProcedureParametersStructs,
  pub redCallSetProcedureParametersHandles: RedTypeProcedureCallSetProcedureParametersHandles,
  pub redCallSetDynamicDepthBias: RedTypeProcedureCallSetDynamicDepthBias,
  pub redCallSetDynamicDepthBounds: RedTypeProcedureCallSetDynamicDepthBounds,
  pub redCallSetDynamicStencilCompareMask: RedTypeProcedureCallSetDynamicStencilCompareMask,
  pub redCallSetDynamicStencilWriteMask: RedTypeProcedureCallSetDynamicStencilWriteMask,
  pub redCallSetDynamicStencilReference: RedTypeProcedureCallSetDynamicStencilReference,
  pub redCallSetDynamicBlendConstants: RedTypeProcedureCallSetDynamicBlendConstants,
  pub redCallSetDynamicViewport: RedTypeProcedureAddressCallSetDynamicViewport,
  pub redCallSetDynamicScissor: RedTypeProcedureAddressCallSetDynamicScissor,
  pub redCallSetStructsMemory: RedTypeProcedureAddressCallSetStructsMemory,
  pub redCallSetProcedureParameters: RedTypeProcedureAddressCallSetProcedureParameters,
  pub redCallSetProcedureOutput: RedTypeProcedureAddressCallSetProcedureOutput,
  pub redCallEndProcedureOutput: RedTypeProcedureAddressCallEndProcedureOutput,
  pub redCallUsageAliasOrderBarrier: RedTypeProcedureAddressCallUsageAliasOrderBarrier,
  pub redCallMark: RedTypeProcedureAddressCallMark,
  pub redCallMarkSet: RedTypeProcedureAddressCallMarkSet,
  pub redCallMarkEnd: RedTypeProcedureAddressCallMarkEnd,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedInlineOutput {
  pub outputMembers: *const RedOutputMembers,
  pub outputMembersResolveTargets: *const RedOutputMembersResolveTargets,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedColorsClearValuesFloat {
  pub r: [libc::c_float; 8],
  pub g: [libc::c_float; 8],
  pub b: [libc::c_float; 8],
  pub a: [libc::c_float; 8],
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedColorsClearValuesSint {
  pub r: [libc::c_int; 8],
  pub g: [libc::c_int; 8],
  pub b: [libc::c_int; 8],
  pub a: [libc::c_int; 8],
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedColorsClearValuesUint {
  pub r: [libc::c_uint; 8],
  pub g: [libc::c_uint; 8],
  pub b: [libc::c_uint; 8],
  pub a: [libc::c_uint; 8],
}
pub type RedBarrierSplit = libc::c_uint;
pub const RED_BARRIER_SPLIT_END: RedBarrierSplit = 2;
pub const RED_BARRIER_SPLIT_SET: RedBarrierSplit = 1;
pub const RED_BARRIER_SPLIT_NONE: RedBarrierSplit = 0;
pub type RedAccessStageBitflags = libc::c_uint;
pub type RedAccessStageBitflag = libc::c_uint;
pub const RED_ACCESS_STAGE_BITFLAG_CPU: RedAccessStageBitflag = 256;
pub const RED_ACCESS_STAGE_BITFLAG_RESOLVE: RedAccessStageBitflag = 128;
pub const RED_ACCESS_STAGE_BITFLAG_OUTPUT_COLOR: RedAccessStageBitflag = 64;
pub const RED_ACCESS_STAGE_BITFLAG_OUTPUT_DEPTH_STENCIL: RedAccessStageBitflag = 32;
pub const RED_ACCESS_STAGE_BITFLAG_FRAGMENT: RedAccessStageBitflag = 16;
pub const RED_ACCESS_STAGE_BITFLAG_VERTEX: RedAccessStageBitflag = 8;
pub const RED_ACCESS_STAGE_BITFLAG_INDEX: RedAccessStageBitflag = 4;
pub const RED_ACCESS_STAGE_BITFLAG_COMPUTE: RedAccessStageBitflag = 2;
pub const RED_ACCESS_STAGE_BITFLAG_COPY: RedAccessStageBitflag = 1;
pub type RedAccessBitflags = libc::c_uint;
pub type RedAccessBitflag = libc::c_uint;
pub const RED_ACCESS_BITFLAG_CPU_RW: RedAccessBitflag = 16384;
pub const RED_ACCESS_BITFLAG_RESOLVE_TARGET_W: RedAccessBitflag = 8192;
pub const RED_ACCESS_BITFLAG_RESOLVE_SOURCE_R: RedAccessBitflag = 4096;
pub const RED_ACCESS_BITFLAG_OUTPUT_COLOR_W: RedAccessBitflag = 2048;
pub const RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW: RedAccessBitflag = 1024;
pub const RED_ACCESS_BITFLAG_OUTPUT_STENCIL_R: RedAccessBitflag = 512;
pub const RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW: RedAccessBitflag = 256;
pub const RED_ACCESS_BITFLAG_OUTPUT_DEPTH_R: RedAccessBitflag = 128;
pub const RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W: RedAccessBitflag = 64;
pub const RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R: RedAccessBitflag = 32;
pub const RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R: RedAccessBitflag = 16;
pub const RED_ACCESS_BITFLAG_STRUCT_ARRAY_RO_CONSTANT_R: RedAccessBitflag = 8;
pub const RED_ACCESS_BITFLAG_INDEX_R: RedAccessBitflag = 4;
pub const RED_ACCESS_BITFLAG_COPY_W: RedAccessBitflag = 2;
pub const RED_ACCESS_BITFLAG_COPY_R: RedAccessBitflag = 1;
pub type RedState = libc::c_uint;
pub const RED_STATE_PRESENT: RedState = 1000001002;
pub const RED_STATE_USABLE: RedState = 1;
pub const RED_STATE_UNUSABLE: RedState = 0;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedUsageArray {
  pub barrierSplit: RedBarrierSplit,
  pub oldAccessStages: RedAccessStageBitflags,
  pub newAccessStages: RedAccessStageBitflags,
  pub oldAccess: RedAccessBitflags,
  pub newAccess: RedAccessBitflags,
  pub queueFamilyIndexSource: libc::c_uint,
  pub queueFamilyIndexTarget: libc::c_uint,
  pub array: RedHandleArray,
  pub arrayBytesFirst: uint64_t,
  pub arrayBytesCount: uint64_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedUsageImage {
  pub barrierSplit: RedBarrierSplit,
  pub oldAccessStages: RedAccessStageBitflags,
  pub newAccessStages: RedAccessStageBitflags,
  pub oldAccess: RedAccessBitflags,
  pub newAccess: RedAccessBitflags,
  pub oldState: RedState,
  pub newState: RedState,
  pub queueFamilyIndexSource: libc::c_uint,
  pub queueFamilyIndexTarget: libc::c_uint,
  pub image: RedHandleImage,
  pub imageAllParts: RedImagePartBitflags,
  pub imageLevelsFirst: libc::c_uint,
  pub imageLevelsCount: libc::c_uint,
  pub imageLayersFirst: libc::c_uint,
  pub imageLayersCount: libc::c_uint,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedAlias {
  pub barrierSplit: RedBarrierSplit,
  pub oldResourceHandle: uint64_t,
  pub newResourceHandle: uint64_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedOrder {
  pub barrierSplit: RedBarrierSplit,
  pub resourceHandle: uint64_t,
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedGpuTimeline {
  pub setTo4: libc::c_uint,
  pub setTo0: size_t,
  pub waitForAndUnsignalGpuSignalsCount: libc::c_uint,
  pub waitForAndUnsignalGpuSignals: *const RedHandleGpuSignal,
  pub setTo65536: *const libc::c_uint,
  pub callsCount: libc::c_uint,
  pub calls: *const RedHandleCalls,
  pub signalGpuSignalsCount: libc::c_uint,
  pub signalGpuSignals: *const RedHandleGpuSignal,
}

#[link(name = "C:/RedGpuSDK/redgpudll")]
extern "C" {
  pub fn redMemoryGetBudget(
    context: RedContext,
    gpu: RedHandleGpu,
    outMemoryBudget: *mut RedMemoryBudget,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redMemoryAllocate(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    bytesCount: uint64_t,
    memoryTypeIndex: libc::c_uint,
    dedicateToArray: RedHandleArray,
    dedicateToImage: RedHandleImage,
    memoryBitflags: libc::c_uint,
    outMemory: *mut RedHandleMemory,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redMemoryAllocateMappable(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    dedicate: RedBool32,
    array: RedHandleArray,
    arrayMemoryBytesCount: uint64_t,
    memoryTypeIndex: libc::c_uint,
    memoryBitflags: libc::c_uint,
    outMemory: *mut RedHandleMemory,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redMemoryFree(
    context: RedContext,
    gpu: RedHandleGpu,
    memory: RedHandleMemory,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redMemorySet(
    context: RedContext,
    gpu: RedHandleGpu,
    memoryArraysCount: libc::c_uint,
    memoryArrays: *const RedMemoryArray,
    memoryImagesCount: libc::c_uint,
    memoryImages: *const RedMemoryImage,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redMemoryMap(
    context: RedContext,
    gpu: RedHandleGpu,
    mappableMemory: RedHandleMemory,
    mappableMemoryBytesFirst: uint64_t,
    mappableMemoryBytesCount: uint64_t,
    outVolatilePointer: *mut *mut libc::c_void,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redMemoryUnmap(
    context: RedContext,
    gpu: RedHandleGpu,
    mappableMemory: RedHandleMemory,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redMemoryNonCoherentFlush(
    context: RedContext,
    gpu: RedHandleGpu,
    mappableMemoryRangesCount: libc::c_uint,
    mappableMemoryRanges: *const RedMappableMemoryRange,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redMemoryNonCoherentInvalidate(
    context: RedContext,
    gpu: RedHandleGpu,
    mappableMemoryRangesCount: libc::c_uint,
    mappableMemoryRanges: *const RedMappableMemoryRange,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redStructsMemoryAllocate(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    maxStructsCount: libc::c_uint,
    maxStructsMembersOfTypeArrayROConstantCount: libc::c_uint,
    maxStructsMembersOfTypeArrayROOrArrayRWCount: libc::c_uint,
    maxStructsMembersOfTypeTextureROCount: libc::c_uint,
    maxStructsMembersOfTypeTextureRWCount: libc::c_uint,
    outStructsMemory: *mut RedHandleStructsMemory,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redStructsMemoryAllocateSamplers(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    maxStructsCount: libc::c_uint,
    maxStructsMembersOfTypeSamplerCount: libc::c_uint,
    outStructsMemory: *mut RedHandleStructsMemory,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redStructsMemorySuballocateStructs(
    context: RedContext,
    gpu: RedHandleGpu,
    handleNames: *const *const libc::c_char,
    structsMemory: RedHandleStructsMemory,
    structsDeclarationsCount: libc::c_uint,
    structsDeclarations: *const RedHandleStructDeclaration,
    outStructs: *mut RedHandleStruct,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redStructsMemoryReset(
    context: RedContext,
    gpu: RedHandleGpu,
    structsMemory: RedHandleStructsMemory,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redStructsMemoryFree(
    context: RedContext,
    gpu: RedHandleGpu,
    structsMemory: RedHandleStructsMemory,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redStructsSet(
    context: RedContext,
    gpu: RedHandleGpu,
    structsMembersCount: libc::c_uint,
    structsMembers: *const RedStructMember,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateContext(
    malloc: RedTypeProcedureMalloc,
    free: RedTypeProcedureFree,
    optionalMallocTagged: RedTypeProcedureMallocTagged,
    optionalFreeTagged: RedTypeProcedureFreeTagged,
    debugCallback: RedTypeProcedureDebugCallback,
    sdkVersion: RedSdkVersion,
    sdkExtensionsCount: libc::c_uint,
    sdkExtensions: *const libc::c_uint,
    optionalProgramName: *const libc::c_char,
    optionalProgramVersion: libc::c_uint,
    optionalEngineName: *const libc::c_char,
    optionalEngineVersion: libc::c_uint,
    optionalSettings: *const libc::c_void,
    outContext: *mut RedContext,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateArray(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    type_0: RedArrayType,
    bytesCount: uint64_t,
    structuredBufferElementBytesCount: uint64_t,
    initialAccess: libc::c_int,
    initialQueueFamilyIndex: libc::c_uint,
    dedicate: RedBool32,
    outArray: *mut RedArray,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateImage(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    dimensions: RedImageDimensions,
    format: RedFormat,
    width: libc::c_uint,
    height: libc::c_uint,
    depth: libc::c_uint,
    levelsCount: libc::c_uint,
    layersCount: libc::c_uint,
    multisampleCount: RedMultisampleCountBitflag,
    restrictToAccess: libc::c_int,
    initialAccess: libc::c_int,
    initialQueueFamilyIndex: libc::c_uint,
    dedicate: RedBool32,
    outImage: *mut RedImage,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateSampler(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    filteringMag: RedSamplerFiltering,
    filteringMin: RedSamplerFiltering,
    filteringMip: RedSamplerFilteringMip,
    behaviorOutsideTextureCoordinateU: RedSamplerBehaviorOutsideTextureCoordinate,
    behaviorOutsideTextureCoordinateV: RedSamplerBehaviorOutsideTextureCoordinate,
    behaviorOutsideTextureCoordinateW: RedSamplerBehaviorOutsideTextureCoordinate,
    mipLodBias: libc::c_float,
    enableAnisotropy: RedBool32,
    maxAnisotropy: libc::c_float,
    enableCompare: RedBool32,
    compareOp: RedCompareOp,
    minLod: libc::c_float,
    maxLod: libc::c_float,
    outSampler: *mut RedHandleSampler,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateTexture(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    image: RedHandleImage,
    parts: RedImagePartBitflags,
    dimensions: RedTextureDimensions,
    format: RedFormat,
    levelsFirst: libc::c_uint,
    levelsCount: libc::c_uint,
    layersFirst: libc::c_uint,
    layersCount: libc::c_uint,
    restrictToAccess: libc::c_int,
    outTexture: *mut RedHandleTexture,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateGpuCode(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    irBytesCount: uint64_t,
    ir: *const libc::c_void,
    outGpuCode: *mut RedHandleGpuCode,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateOutputDeclaration(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    outputDeclarationMembers: *const RedOutputDeclarationMembers,
    outputDeclarationMembersResolveSources: *const RedOutputDeclarationMembersResolveSources,
    dependencyByRegion: RedBool32,
    dependencyByRegionAllowUsageAliasOrderBarriers: RedBool32,
    outOutputDeclaration: *mut RedHandleOutputDeclaration,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateStructDeclaration(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    structDeclarationMembersCount: libc::c_uint,
    structDeclarationMembers: *const RedStructDeclarationMember,
    structDeclarationMembersArrayROCount: libc::c_uint,
    structDeclarationMembersArrayRO: *const RedStructDeclarationMemberArrayRO,
    procedureParametersHandlesDeclaration: RedBool32,
    outStructDeclaration: *mut RedHandleStructDeclaration,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateProcedureParameters(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    procedureParametersDeclaration: *const RedProcedureParametersDeclaration,
    outProcedureParameters: *mut RedHandleProcedureParameters,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateProcedureCache(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    fromBlobBytesCount: uint64_t,
    fromBlob: *const libc::c_void,
    outProcedureCache: *mut RedHandleProcedureCache,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateProcedure(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    procedureCache: RedHandleProcedureCache,
    outputDeclaration: RedHandleOutputDeclaration,
    procedureParameters: RedHandleProcedureParameters,
    gpuCodeVertexMainProcedureName: *const libc::c_char,
    gpuCodeVertex: RedHandleGpuCode,
    gpuCodeFragmentMainProcedureName: *const libc::c_char,
    gpuCodeFragment: RedHandleGpuCode,
    state: *const RedProcedureState,
    stateExtension: *const libc::c_void,
    deriveBase: RedBool32,
    deriveFrom: RedHandleProcedure,
    outProcedure: *mut RedHandleProcedure,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateProcedureCompute(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    procedureCache: RedHandleProcedureCache,
    procedureParameters: RedHandleProcedureParameters,
    gpuCodeMainProcedureName: *const libc::c_char,
    gpuCode: RedHandleGpuCode,
    outProcedure: *mut RedHandleProcedure,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateOutput(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    outputDeclaration: RedHandleOutputDeclaration,
    outputMembers: *const RedOutputMembers,
    outputMembersResolveTargets: *const RedOutputMembersResolveTargets,
    width: libc::c_uint,
    height: libc::c_uint,
    outOutput: *mut RedOutput,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateCpuSignal(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    createSignaled: RedBool32,
    outCpuSignal: *mut RedHandleCpuSignal,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateGpuSignal(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    outGpuSignal: *mut RedHandleGpuSignal,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateGpuToCpuSignal(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    outGpuToCpuSignal: *mut RedHandleGpuToCpuSignal,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateCalls(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    queueFamilyIndex: libc::c_uint,
    outCalls: *mut RedCalls,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCreateCallsReusable(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    queueFamilyIndex: libc::c_uint,
    outCalls: *mut RedCalls,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyContext(
    context: RedContext,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyArray(
    context: RedContext,
    gpu: RedHandleGpu,
    array: RedHandleArray,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyImage(
    context: RedContext,
    gpu: RedHandleGpu,
    image: RedHandleImage,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroySampler(
    context: RedContext,
    gpu: RedHandleGpu,
    sampler: RedHandleSampler,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyTexture(
    context: RedContext,
    gpu: RedHandleGpu,
    texture: RedHandleTexture,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyGpuCode(
    context: RedContext,
    gpu: RedHandleGpu,
    gpuCode: RedHandleGpuCode,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyOutputDeclaration(
    context: RedContext,
    gpu: RedHandleGpu,
    outputDeclaration: RedHandleOutputDeclaration,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyStructDeclaration(
    context: RedContext,
    gpu: RedHandleGpu,
    structDeclaration: RedHandleStructDeclaration,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyProcedureParameters(
    context: RedContext,
    gpu: RedHandleGpu,
    procedureParameters: RedHandleProcedureParameters,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyProcedureCache(
    context: RedContext,
    gpu: RedHandleGpu,
    procedureCache: RedHandleProcedureCache,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyProcedure(
    context: RedContext,
    gpu: RedHandleGpu,
    procedure: RedHandleProcedure,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyOutput(
    context: RedContext,
    gpu: RedHandleGpu,
    output: RedHandleOutput,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyCpuSignal(
    context: RedContext,
    gpu: RedHandleGpu,
    cpuSignal: RedHandleCpuSignal,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyGpuSignal(
    context: RedContext,
    gpu: RedHandleGpu,
    gpuSignal: RedHandleGpuSignal,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyGpuToCpuSignal(
    context: RedContext,
    gpu: RedHandleGpu,
    gpuToCpuSignal: RedHandleGpuToCpuSignal,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redDestroyCalls(
    context: RedContext,
    gpu: RedHandleGpu,
    calls: RedHandleCalls,
    callsMemory: RedHandleCallsMemory,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redProcedureCacheGetBlob(
    context: RedContext,
    gpu: RedHandleGpu,
    procedureCache: RedHandleProcedureCache,
    outBlobBytesCount: *mut uint64_t,
    outBlob: *mut libc::c_void,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redProcedureCacheMergeCaches(
    context: RedContext,
    gpu: RedHandleGpu,
    sourceProcedureCachesCount: libc::c_uint,
    sourceProcedureCaches: *const RedHandleProcedureCache,
    targetProcedureCache: RedHandleProcedureCache,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCpuSignalGetStatus(
    context: RedContext,
    gpu: RedHandleGpu,
    cpuSignal: RedHandleCpuSignal,
    outStatus: *mut RedStatus,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCpuSignalWait(
    context: RedContext,
    gpu: RedHandleGpu,
    cpuSignalsCount: libc::c_uint,
    cpuSignals: *const RedHandleCpuSignal,
    waitAll: RedBool32,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCpuSignalUnsignal(
    context: RedContext,
    gpu: RedHandleGpu,
    cpuSignalsCount: libc::c_uint,
    cpuSignals: *const RedHandleCpuSignal,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redGpuToCpuSignalGetStatus(
    context: RedContext,
    gpu: RedHandleGpu,
    gpuToCpuSignal: RedHandleGpuToCpuSignal,
    outStatus: *mut RedStatus,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redGpuToCpuSignalUnsignal(
    context: RedContext,
    gpu: RedHandleGpu,
    gpuToCpuSignal: RedHandleGpuToCpuSignal,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCallsSet(
    context: RedContext,
    gpu: RedHandleGpu,
    calls: RedHandleCalls,
    callsMemory: RedHandleCallsMemory,
    callsReusable: RedBool32,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCallsEnd(
    context: RedContext,
    gpu: RedHandleGpu,
    calls: RedHandleCalls,
    callsMemory: RedHandleCallsMemory,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redGetCallProceduresAndAddresses(
    context: RedContext,
    gpu: RedHandleGpu,
    outCallProceduresAndAddresses: *mut RedCallProceduresAndAddresses,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redCallSetDynamicViewport(
    address: RedTypeProcedureAddressCallSetDynamicViewport,
    calls: RedHandleCalls,
    x: libc::c_float,
    y: libc::c_float,
    width: libc::c_float,
    height: libc::c_float,
    depthMin: libc::c_float,
    depthMax: libc::c_float,
  );
  pub fn redCallSetDynamicScissor(
    address: RedTypeProcedureAddressCallSetDynamicScissor,
    calls: RedHandleCalls,
    x: libc::c_int,
    y: libc::c_int,
    width: libc::c_uint,
    height: libc::c_uint,
  );
  pub fn redCallSetStructsMemory(
    address: RedTypeProcedureAddressCallSetStructsMemory,
    calls: RedHandleCalls,
    structsMemory: RedHandleStructsMemory,
    structsMemorySamplers: RedHandleStructsMemory,
  );
  pub fn redCallSetProcedureParameters(
    address: RedTypeProcedureAddressCallSetProcedureParameters,
    calls: RedHandleCalls,
    procedureType: RedProcedureType,
    procedureParameters: RedHandleProcedureParameters,
  );
  pub fn redCallSetProcedureOutput(
    address: RedTypeProcedureAddressCallSetProcedureOutput,
    calls: RedHandleCalls,
    outputDeclaration: RedHandleOutputDeclaration,
    output: RedHandleOutput,
    inlineOutput: *const RedInlineOutput,
    outputWidth: libc::c_uint,
    outputHeight: libc::c_uint,
    outputDepthStencilEnable: RedBool32,
    outputColorsCount: libc::c_uint,
    depthClearValue: libc::c_float,
    stencilClearValue: libc::c_uint,
    colorsClearValuesFloat: *const RedColorsClearValuesFloat,
    colorsClearValuesSint: *const RedColorsClearValuesSint,
    colorsClearValuesUint: *const RedColorsClearValuesUint,
  );
  pub fn redCallEndProcedureOutput(
    address: RedTypeProcedureAddressCallEndProcedureOutput,
    calls: RedHandleCalls,
  );
  pub fn redCallUsageAliasOrderBarrier(
    address: RedTypeProcedureAddressCallUsageAliasOrderBarrier,
    calls: RedHandleCalls,
    context: RedContext,
    arrayUsagesCount: libc::c_uint,
    arrayUsages: *const RedUsageArray,
    imageUsagesCount: libc::c_uint,
    imageUsages: *const RedUsageImage,
    aliasesCount: libc::c_uint,
    aliases: *const RedAlias,
    ordersCount: libc::c_uint,
    orders: *const RedOrder,
    dependencyByRegion: RedBool32,
  );
  pub fn redCallMark(
    address: RedTypeProcedureAddressCallMark,
    calls: RedHandleCalls,
    mark: *const libc::c_char,
  );
  pub fn redCallMarkSet(
    address: RedTypeProcedureAddressCallMarkSet,
    calls: RedHandleCalls,
    mark: *const libc::c_char,
  );
  pub fn redCallMarkEnd(
    address: RedTypeProcedureAddressCallMarkEnd,
    calls: RedHandleCalls,
  );
  pub fn redQueueSubmit(
    context: RedContext,
    gpu: RedHandleGpu,
    queue: RedHandleQueue,
    timelinesCount: libc::c_uint,
    timelines: *const RedGpuTimeline,
    signalCpuSignal: RedHandleCpuSignal,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redMark(
    mark: *const libc::c_char,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redMarkSet(
    mark: *const libc::c_char,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redMarkEnd(
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redStructsMemoryAllocateWithInlineSamplers(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    maxStructsCount: libc::c_uint,
    maxStructsMembersOfTypeArrayROConstantCount: libc::c_uint,
    maxStructsMembersOfTypeArrayROOrArrayRWCount: libc::c_uint,
    maxStructsMembersOfTypeTextureROCount: libc::c_uint,
    maxStructsMembersOfTypeTextureRWCount: libc::c_uint,
    maxStructsMembersOfTypeInlineSamplerCount: libc::c_uint,
    outStructsMemory: *mut RedHandleStructsMemory,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
  pub fn redStructsMemoryAllocateSamplersWithInlineSamplers(
    context: RedContext,
    gpu: RedHandleGpu,
    handleName: *const libc::c_char,
    maxStructsCount: libc::c_uint,
    maxStructsMembersOfTypeSamplerCount: libc::c_uint,
    maxStructsMembersOfTypeInlineSamplerCount: libc::c_uint,
    outStructsMemory: *mut RedHandleStructsMemory,
    outStatuses: *mut RedStatuses,
    optionalFile: *const libc::c_char,
    optionalLine: libc::c_int,
    optionalUserData: *mut libc::c_void,
  );
}

// NOTE(Constantine): https://github.com/rust-lang/libs-team/issues/350
pub const unsafe fn slice_from_raw_parts_or_empty<'a, T>(data: *const T, len: usize) -> &'a [T] {
  if len == 0 { &[] } else { std::slice::from_raw_parts(data, len) }
}

// NOTE(Constantine): https://github.com/rust-lang/libs-team/issues/350
pub unsafe fn slice_from_raw_parts_mut_or_empty<'a, T>(data: *mut T, len: usize) -> &'a mut [T] {
  if len == 0 { &mut [] } else { std::slice::from_raw_parts_mut(data, len) }
}

fn main() {
  let mut redcontext: RedContext = std::ptr::null();
  let mut statuses = RedStatuses {
    status: RED_STATUS_SUCCESS,
    statusCode: 0,
    statusHresult: 0,
    statusProcedureId: RED_PROCEDURE_ID_redCreateContext,
    statusFile: std::ptr::null(),
    statusLine: 0,
    statusError: RED_STATUS_SUCCESS,
    statusErrorCode: 0,
    statusErrorHresult: 0,
    statusErrorProcedureId: RED_PROCEDURE_ID_redCreateContext,
    statusErrorFile: std::ptr::null(),
    statusErrorLine: 0,
    statusErrorDescription: [0; 512]
  };
  unsafe {
    redCreateContext(
      Some(libc::malloc),
      Some(libc::free),
      None,
      None,
      None,
      RED_SDK_VERSION_1_0_135,
      0,
      std::ptr::null(),
      std::ptr::null(),
      0,
      std::ptr::null(),
      0,
      std::ptr::null(),
      &mut redcontext,
      &mut statuses,
      std::ptr::null(),
      0,
      std::ptr::null_mut()
    );
  }

  let ctx = unsafe { redcontext.as_ref().unwrap() };
  assert!(ctx.gpusCount > 0);

  let mut gpu: RedHandleGpu = std::ptr::null();

  let gpus = unsafe { slice_from_raw_parts_or_empty(ctx.gpus, ctx.gpusCount as usize) };
  for _gpu in gpus {
    let _gpuName = std::str::from_utf8(&_gpu.gpuName).unwrap();
    let _ = 1 + 1;
    if _gpu.gpu.is_null() == false {
      // Pick the first valid GPU.
      gpu = _gpu.gpu;
      break;
    }
  }

  let mut memoryBudget = RedMemoryBudget{
    setTo1000237000: 1000237000,
    setTo0: 0,
    memoryHeapsBudget: [0; 16],
    memoryHeapsUsage: [0; 16]
  };

  unsafe {
    redMemoryGetBudget(
      ctx,
      gpu,
      &mut memoryBudget,
      std::ptr::null_mut(),
      std::ptr::null(),
      0,
      std::ptr::null_mut()
    );
  }

  {
    let _ = 1 + 1;
  }

  unsafe {
    redDestroyContext(
      ctx,
      std::ptr::null(),
      0,
      std::ptr::null_mut()
    );
  }
}