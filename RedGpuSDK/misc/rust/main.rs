#![allow(dead_code, mutable_transmutes, non_camel_case_types, non_snake_case, non_upper_case_globals, unused_assignments, unused_mut)]
#![register_tool(c2rust)]
#![feature(extern_types, register_tool)]
extern "C" {
  pub type RedTypeHandleContext;
  pub type RedTypeHandleQueue;
  pub type RedTypeHandleGpuDevice;
  pub type RedTypeHandleGpu;
}
pub type size_t = usize;
pub type uint8_t = u8;
pub type uint64_t = u64;
pub type RedBool32 = libc::c_uint;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct RedTypeContext {
  pub gpusCount: libc::c_uint,
  pub gpus: *const RedGpuInfo,
  pub gpusStatuses: *const RedStatuses,
  pub handle: RedHandleContext,
  pub userData: *mut libc::c_void,
}
pub type RedHandleContext = *mut RedTypeHandleContext;
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
  pub statusErrorDescription: [uint8_t; 512],
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
  pub gpuName: [uint8_t; 256],
  pub gpuType: RedGpuType,
  pub gpuVendorId: libc::c_uint,
  pub gpuDeviceId: libc::c_uint,
  pub gpuDriverVersion: libc::c_uint,
  pub gpuProcedureCacheUuid: [libc::c_uchar; 16],
  pub memoryTypesCount: libc::c_uint,
  pub memoryTypes: *const RedMemoryType,
  pub memoryTypesDescription: *mut *const libc::c_char,
  pub memoryHeapsCount: libc::c_uint,
  pub memoryHeaps: *const RedMemoryHeap,
  pub memoryHeapsDescription: *mut *const libc::c_char,
  pub queuesCount: libc::c_uint,
  pub queues: *const RedHandleQueue,
  pub queuesDescription: *mut *const libc::c_char,
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
pub type RedHandleQueue = *mut RedTypeHandleQueue;
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
pub type RedHandleGpuDevice = *mut RedTypeHandleGpuDevice;
pub type RedHandleGpu = *mut RedTypeHandleGpu;
pub type RedContext = *mut RedTypeContext;
pub type RedSdkVersion = libc::c_uint;
pub const RED_SDK_VERSION_1_0_135: RedSdkVersion = 0;
pub type RedDebugCallbackSeverity = libc::c_uint;
pub const RED_DEBUG_CALLBACK_SEVERITY_ERROR: RedDebugCallbackSeverity = 1;
pub const RED_DEBUG_CALLBACK_SEVERITY_WARNING: RedDebugCallbackSeverity = 0;
pub type RedDebugCallbackTypeBitflags = libc::c_uint;
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
  pub tag: [uint8_t; 512],
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

#[link(name = "C:/RedGpuSDK/redgpudll")]
extern "C" {
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
}

fn main() {
  let mut ctx: RedContext = std::ptr::null_mut();
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
      &mut ctx,
      &mut statuses,
      std::ptr::null(),
      0,
      std::ptr::null_mut()
    );
  }
  if ctx.is_null() == false {
    let gpusCount = unsafe { (*ctx).gpusCount };
    let gpus = unsafe { (*ctx).gpus };
    for i in 0..gpusCount as usize {
      let gpu0 = gpus;
      let gpu = unsafe { *gpu0.add(i) };
      let _gpuName = std::str::from_utf8(&gpu.gpuName).unwrap();
      let _ = 1 + 1;
    }
  }
}