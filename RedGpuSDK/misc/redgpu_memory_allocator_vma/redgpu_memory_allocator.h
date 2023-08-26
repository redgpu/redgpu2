#pragma once

#ifdef _WIN32
#include "C:/RedGpuSDK/redgpu.h"
#endif
#ifdef __linux__
#include "/opt/RedGpuSDK/redgpu.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef VMA_STATS_STRING_ENABLED
#define VMA_STATS_STRING_ENABLED 1
#endif

#ifndef VMA_RECORDING_ENABLED
#define VMA_RECORDING_ENABLED 0
#endif

typedef struct VmaAllocator_T *              VmaAllocator;
typedef struct VmaPool_T *                   VmaPool;
typedef struct VmaAllocation_T *             VmaAllocation;
typedef struct VmaDefragmentationContext_T * VmaDefragmentationContext;

typedef void (*PFN_vmaAllocateDeviceMemoryFunction) (VmaAllocator allocator, unsigned memoryType, RedHandleMemory memory, uint64_t size, void * pUserData);
typedef void (*PFN_vmaFreeDeviceMemoryFunction)     (VmaAllocator allocator, unsigned memoryType, RedHandleMemory memory, uint64_t size, void * pUserData);

typedef struct VmaDeviceMemoryCallbacks {
  PFN_vmaAllocateDeviceMemoryFunction pfnAllocate;
  PFN_vmaFreeDeviceMemoryFunction     pfnFree;
  void *                              pUserData;
} VmaDeviceMemoryCallbacks;

typedef unsigned VmaAllocatorCreateFlags;
typedef enum VmaAllocatorCreateFlagBits {
  VMA_ALLOCATOR_CREATE_EXTERNALLY_SYNCHRONIZED_BIT    = 0x00000001,
  VMA_ALLOCATOR_CREATE_KHR_DEDICATED_ALLOCATION_BIT   = 0x00000002,
  VMA_ALLOCATOR_CREATE_KHR_BIND_MEMORY2_BIT           = 0x00000004,
  VMA_ALLOCATOR_CREATE_EXT_MEMORY_BUDGET_BIT          = 0x00000008,
  VMA_ALLOCATOR_CREATE_AMD_DEVICE_COHERENT_MEMORY_BIT = 0x00000010,
  VMA_ALLOCATOR_CREATE_BUFFER_DEVICE_ADDRESS_BIT      = 0x00000020,
  VMA_ALLOCATOR_CREATE_EXT_MEMORY_PRIORITY_BIT        = 0x00000040,
  VMA_ALLOCATOR_CREATE_FLAG_BITS_MAX_ENUM             = 0x7FFFFFFF,
} VmaAllocatorCreateFlagBits;

typedef unsigned VmaRecordFlags;
typedef enum VmaRecordFlagBits {
  VMA_RECORD_FLUSH_AFTER_CALL_BIT = 0x00000001,
  VMA_RECORD_FLAG_BITS_MAX_ENUM   = 0x7FFFFFFF,
} VmaRecordFlagBits;

typedef struct VmaRecordSettings {
  VmaRecordFlags flags;
  const char *   pFilePath;
} VmaRecordSettings;

typedef struct VmaRedGpuFunctions {
  void      (*redgpuVkGetPhysicalDeviceProperties)       (RedContext context, unsigned gpuIndex, RedHandleGpuDevice physicalDevice, void * pVkPhysicalDeviceProperties);
  void      (*redgpuVkGetPhysicalDeviceMemoryProperties) (RedContext context, unsigned gpuIndex, RedHandleGpuDevice physicalDevice, void * pVkPhysicalDeviceMemoryProperties);
  RedStatus (*redgpuVkAllocateMemory)                    (RedContext context, unsigned gpuIndex, RedHandleGpu device, const void * pVkMemoryAllocateInfo, const void * pVkAllocationCallbacks, RedHandleMemory * pMemory);
  void      (*redgpuVkFreeMemory)                        (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleMemory memory, const void * pVkAllocationCallbacks);
  RedStatus (*redgpuVkMapMemory)                         (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleMemory memory, uint64_t offset, uint64_t size, unsigned vkMemoryMapFlags, void ** ppData);
  void      (*redgpuVkUnmapMemory)                       (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleMemory memory);
  RedStatus (*redgpuVkFlushMappedMemoryRanges)           (RedContext context, unsigned gpuIndex, RedHandleGpu device, unsigned memoryRangeCount, const void * pVkMappedMemoryRange);
  RedStatus (*redgpuVkInvalidateMappedMemoryRanges)      (RedContext context, unsigned gpuIndex, RedHandleGpu device, unsigned memoryRangeCount, const void * pVkMappedMemoryRange);
  RedStatus (*redgpuVkBindBufferMemory)                  (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleArray buffer, RedHandleMemory memory, uint64_t memoryOffset);
  RedStatus (*redgpuVkBindImageMemory)                   (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleImage image, RedHandleMemory memory, uint64_t memoryOffset);
  void      (*redgpuVkGetBufferMemoryRequirements)       (RedContext context, unsigned gpuIndex, RedHandleGpu device, const RedArray * buffer, void * pVkMemoryRequirements);
  void      (*redgpuVkGetImageMemoryRequirements)        (RedContext context, unsigned gpuIndex, RedHandleGpu device, const RedImage * image, void * pVkMemoryRequirements);
  RedStatus (*redgpuVkCreateBuffer)                      (RedContext context, unsigned gpuIndex, RedHandleGpu device, const void * pVkBufferCreateInfo, const void * pVkAllocationCallbacks, RedArray * pBuffer);
  void      (*redgpuVkDestroyBuffer)                     (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleArray buffer, const void * pVkAllocationCallbacks);
  RedStatus (*redgpuVkCreateImage)                       (RedContext context, unsigned gpuIndex, RedHandleGpu device, const void * pVkImageCreateInfo, const void * pVkAllocationCallbacks, RedImage * pImage);
  void      (*redgpuVkDestroyImage)                      (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleImage image, const void * pVkAllocationCallbacks);
  void      (*redgpuVkCmdCopyBuffer)                     (RedContext context, unsigned gpuIndex, RedHandleCalls commandBuffer, RedHandleArray srcBuffer, RedHandleArray dstBuffer, unsigned regionCount, const void * pVkBufferCopy);
} VmaRedGpuFunctions;

typedef struct VmaAllocatorCreateInfo {
  VmaAllocatorCreateFlags          flags;
  RedHandleGpuDevice               physicalDevice;              // Required
  RedHandleGpu                     device;                      // Required
  uint64_t                         preferredLargeHeapBlockSize;
  const void *                     pAllocationCallbacks;
  const VmaDeviceMemoryCallbacks * pDeviceMemoryCallbacks;
  unsigned                         frameInUseCount;
  const uint64_t *                 pHeapSizeLimit;
  const VmaRedGpuFunctions *       pRedGpuFunctions;            // Required
  const VmaRecordSettings *        pRecordSettings;
  RedHandleContext                 instance;                    // Required
  unsigned                         vulkanApiVersion;
  RedContext                       redgpuContext;               // Required
  unsigned                         redgpuContextGpuIndex;       // Required
} VmaAllocatorCreateInfo;

typedef struct VmaAllocatorInfo {
  RedHandleContext   instance;
  RedHandleGpuDevice physicalDevice;
  RedHandleGpu       device;
  RedContext         redgpuContext;
  unsigned           redgpuContextGpuIndex;
} VmaAllocatorInfo;

typedef struct VmaStatInfo {
  unsigned blockCount;
  unsigned allocationCount;
  unsigned unusedRangeCount;
  uint64_t usedBytes;
  uint64_t unusedBytes;
  uint64_t allocationSizeMin;
  uint64_t allocationSizeAvg;
  uint64_t allocationSizeMax;
  uint64_t unusedRangeSizeMin;
  uint64_t unusedRangeSizeAvg;
  uint64_t unusedRangeSizeMax;
} VmaStatInfo;

typedef struct VmaStats {
  VmaStatInfo memoryType[32];
  VmaStatInfo memoryHeap[16];
  VmaStatInfo total;
} VmaStats;

typedef struct VmaBudget {
  uint64_t blockBytes;
  uint64_t allocationBytes;
  uint64_t usage;
  uint64_t budget;
} VmaBudget;

typedef enum VmaMemoryUsage {
  VMA_MEMORY_USAGE_UNKNOWN              = 0,
  VMA_MEMORY_USAGE_GPU_ONLY             = 1,
  VMA_MEMORY_USAGE_CPU_ONLY             = 2,
  VMA_MEMORY_USAGE_CPU_TO_GPU           = 3,
  VMA_MEMORY_USAGE_GPU_TO_CPU           = 4,
  VMA_MEMORY_USAGE_CPU_COPY             = 5,
  VMA_MEMORY_USAGE_GPU_LAZILY_ALLOCATED = 6,
  VMA_MEMORY_USAGE_MAX_ENUM             = 0x7FFFFFFF,
} VmaMemoryUsage;

typedef unsigned VmaAllocationCreateFlags;
typedef enum VmaAllocationCreateFlagBits {
  VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT           = 0x00000001,
  VMA_ALLOCATION_CREATE_NEVER_ALLOCATE_BIT             = 0x00000002,
  VMA_ALLOCATION_CREATE_MAPPED_BIT                     = 0x00000004,
  VMA_ALLOCATION_CREATE_CAN_BECOME_LOST_BIT            = 0x00000008,
  VMA_ALLOCATION_CREATE_CAN_MAKE_OTHER_LOST_BIT        = 0x00000010,
  VMA_ALLOCATION_CREATE_USER_DATA_COPY_STRING_BIT      = 0x00000020,
  VMA_ALLOCATION_CREATE_UPPER_ADDRESS_BIT              = 0x00000040,
  VMA_ALLOCATION_CREATE_DONT_BIND_BIT                  = 0x00000080,
  VMA_ALLOCATION_CREATE_WITHIN_BUDGET_BIT              = 0x00000100,
  VMA_ALLOCATION_CREATE_STRATEGY_BEST_FIT_BIT          = 0x00010000,
  VMA_ALLOCATION_CREATE_STRATEGY_WORST_FIT_BIT         = 0x00020000,
  VMA_ALLOCATION_CREATE_STRATEGY_FIRST_FIT_BIT         = 0x00040000,
  VMA_ALLOCATION_CREATE_STRATEGY_MIN_MEMORY_BIT        = VMA_ALLOCATION_CREATE_STRATEGY_BEST_FIT_BIT,
  VMA_ALLOCATION_CREATE_STRATEGY_MIN_TIME_BIT          = VMA_ALLOCATION_CREATE_STRATEGY_FIRST_FIT_BIT,
  VMA_ALLOCATION_CREATE_STRATEGY_MIN_FRAGMENTATION_BIT = VMA_ALLOCATION_CREATE_STRATEGY_WORST_FIT_BIT,
  VMA_ALLOCATION_CREATE_STRATEGY_MASK                  = VMA_ALLOCATION_CREATE_STRATEGY_BEST_FIT_BIT | VMA_ALLOCATION_CREATE_STRATEGY_WORST_FIT_BIT | VMA_ALLOCATION_CREATE_STRATEGY_FIRST_FIT_BIT,
  VMA_ALLOCATION_CREATE_FLAG_BITS_MAX_ENUM             = 0x7FFFFFFF,
} VmaAllocationCreateFlagBits;

typedef struct VmaAllocationCreateInfo {
  VmaAllocationCreateFlags flags;
  VmaMemoryUsage           usage;
  unsigned                 requiredFlags;
  unsigned                 preferredFlags;
  unsigned                 memoryTypeBits;
  VmaPool                  pool;
  void *                   pUserData;
  float                    priority;
} VmaAllocationCreateInfo;

typedef unsigned VmaPoolCreateFlags;
typedef enum VmaPoolCreateFlagBits {
  VMA_POOL_CREATE_IGNORE_BUFFER_IMAGE_GRANULARITY_BIT = 0x00000002,
  VMA_POOL_CREATE_LINEAR_ALGORITHM_BIT                = 0x00000004,
  VMA_POOL_CREATE_BUDDY_ALGORITHM_BIT                 = 0x00000008,
  VMA_POOL_CREATE_ALGORITHM_MASK                      = VMA_POOL_CREATE_LINEAR_ALGORITHM_BIT | VMA_POOL_CREATE_BUDDY_ALGORITHM_BIT,
  VMA_POOL_CREATE_FLAG_BITS_MAX_ENUM                  = 0x7FFFFFFF,
} VmaPoolCreateFlagBits;

typedef struct VmaPoolCreateInfo {
  unsigned           memoryTypeIndex;
  VmaPoolCreateFlags flags;
  uint64_t           blockSize;
  size_t             minBlockCount;
  size_t             maxBlockCount;
  unsigned           frameInUseCount;
  float              priority;
  uint64_t           minAllocationAlignment;
  void *             pMemoryAllocateNext;
} VmaPoolCreateInfo;

typedef struct VmaPoolStats {
  uint64_t size;
  uint64_t unusedSize;
  size_t   allocationCount;
  size_t   unusedRangeCount;
  uint64_t unusedRangeSizeMax;
  size_t   blockCount;
} VmaPoolStats;

typedef struct VmaAllocationInfo {
  unsigned        memoryType;
  RedHandleMemory deviceMemory;
  uint64_t        offset;
  uint64_t        size;
  void *          pMappedData;
  void *          pUserData;
} VmaAllocationInfo;

typedef unsigned VmaDefragmentationFlags;
typedef enum VmaDefragmentationFlagBits {
  VMA_DEFRAGMENTATION_FLAG_INCREMENTAL   = 0x1,
  VMA_DEFRAGMENTATION_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF,
} VmaDefragmentationFlagBits;

typedef struct VmaDefragmentationInfo2 {
  VmaDefragmentationFlags flags;
  unsigned                allocationCount;
  const VmaAllocation *   pAllocations;
  RedBool32 *             pAllocationsChanged;
  unsigned                poolCount;
  const VmaPool *         pPools;
  uint64_t                maxCpuBytesToMove;
  unsigned                maxCpuAllocationsToMove;
  uint64_t                maxGpuBytesToMove;
  unsigned                maxGpuAllocationsToMove;
  RedHandleCalls          commandBuffer;
} VmaDefragmentationInfo2;

typedef struct VmaDefragmentationPassMoveInfo {
  VmaAllocation   allocation;
  RedHandleMemory memory;
  uint64_t        offset;
} VmaDefragmentationPassMoveInfo;

typedef struct VmaDefragmentationPassInfo {
  unsigned                         moveCount;
  VmaDefragmentationPassMoveInfo * pMoves;
} VmaDefragmentationPassInfo;

typedef struct VmaDefragmentationInfo {
  uint64_t maxBytesToMove;
  unsigned maxAllocationsToMove;
} VmaDefragmentationInfo;

typedef struct VmaDefragmentationStats {
  uint64_t bytesMoved;
  uint64_t bytesFreed;
  unsigned allocationsMoved;
  unsigned deviceMemoryBlocksFreed;
} VmaDefragmentationStats;

typedef enum VmaSharingMode {
  VMA_SHARING_MODE_EXCLUSIVE  = 0,
  VMA_SHARING_MODE_CONCURRENT = 1,
} VmaSharingMode;

typedef struct VmaBufferCreateInfo {
  unsigned            setTo12;
  size_t              setTo0;
  unsigned            setTo00;
  uint64_t            size;
  RedArrayType        type;
  VmaSharingMode      sharingMode;
  unsigned            queueFamilyIndexCount;
  const unsigned *    pQueueFamilyIndices;
} VmaBufferCreateInfo;

typedef unsigned VmaImageCreateFlags;
typedef enum VmaImageCreateFlagBits {
  VMA_IMAGE_CREATE_CUBE_COMPATIBLE_BIT     = 0x00000010,
  VMA_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT = 0x00000020,
} VmaImageCreateFlagBits;

typedef enum VmaImageType {
  VMA_IMAGE_TYPE_1D = 0,
  VMA_IMAGE_TYPE_2D = 1,
  VMA_IMAGE_TYPE_3D = 2,
} VmaImageType;

typedef struct VmaExtent3D {
  unsigned width;
  unsigned height;
  unsigned depth;
} VmaExtent3D;

typedef unsigned VmaImageUsageFlags;
typedef enum VmaImageUsageFlagBits {
  VMA_IMAGE_USAGE_TRANSFER_SRC_BIT             = 0x00000001,
  VMA_IMAGE_USAGE_TRANSFER_DST_BIT             = 0x00000002,
  VMA_IMAGE_USAGE_SAMPLED_BIT                  = 0x00000004,
  VMA_IMAGE_USAGE_STORAGE_BIT                  = 0x00000008,
  VMA_IMAGE_USAGE_COLOR_ATTACHMENT_BIT         = 0x00000010,
  VMA_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT = 0x00000020,
} VmaImageUsageFlagBits;

typedef struct VmaImageCreateInfo {
  unsigned                   setTo14;
  size_t                     setTo0;
  VmaImageCreateFlags        flags;
  VmaImageType               imageType;
  RedFormat                  format;
  VmaExtent3D                extent;
  unsigned                   mipLevels;
  unsigned                   arrayLayers;
  RedMultisampleCountBitflag samples;
  unsigned                   setTo00;
  VmaImageUsageFlags         usage;
  VmaSharingMode             sharingMode;
  unsigned                   queueFamilyIndexCount;
  const unsigned *           pQueueFamilyIndices;
  unsigned                   setTo000;
} VmaImageCreateInfo;

typedef struct VmaMemoryRequirements {
  uint64_t memoryBytesCount;
  uint64_t memoryBytesAlignment;
  unsigned memoryTypesSupported;
} VmaMemoryRequirements;

#ifndef VMA_CALL_PRE
#define VMA_CALL_PRE
#endif

#ifndef VMA_CALL_POST
#define VMA_CALL_POST
#endif

#ifndef VMA_NO_PROTOTYPES
#if VMA_STATS_STRING_ENABLED
VMA_CALL_PRE void      VMA_CALL_POST vmaBuildStatsString                 (VmaAllocator allocator, char ** ppStatsString, RedBool32 detailedMap);
VMA_CALL_PRE void      VMA_CALL_POST vmaFreeStatsString                  (VmaAllocator allocator, char * pStatsString);
#endif
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaCreateAllocator                  (const VmaAllocatorCreateInfo * pCreateInfo, VmaAllocator * pAllocator);
VMA_CALL_PRE void      VMA_CALL_POST vmaDestroyAllocator                 (VmaAllocator allocator);
VMA_CALL_PRE void      VMA_CALL_POST vmaGetAllocatorInfo                 (VmaAllocator allocator, VmaAllocatorInfo * pAllocatorInfo);
VMA_CALL_PRE void      VMA_CALL_POST vmaGetPhysicalDeviceProperties      (VmaAllocator allocator, const void ** ppVkPhysicalDeviceProperties);
VMA_CALL_PRE void      VMA_CALL_POST vmaGetMemoryProperties              (VmaAllocator allocator, const void ** ppVkPhysicalDeviceMemoryProperties);
VMA_CALL_PRE void      VMA_CALL_POST vmaGetMemoryTypeProperties          (VmaAllocator allocator, unsigned memoryTypeIndex, unsigned * pFlags);
VMA_CALL_PRE void      VMA_CALL_POST vmaSetCurrentFrameIndex             (VmaAllocator allocator, unsigned frameIndex);
VMA_CALL_PRE void      VMA_CALL_POST vmaCalculateStats                   (VmaAllocator allocator, VmaStats * pStats);
VMA_CALL_PRE void      VMA_CALL_POST vmaGetBudget                        (VmaAllocator allocator, VmaBudget * pBudget);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaFindMemoryTypeIndex              (VmaAllocator allocator, unsigned memoryTypeBits, const VmaAllocationCreateInfo * pAllocationCreateInfo, unsigned * pMemoryTypeIndex);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaFindMemoryTypeIndexForBufferInfo (VmaAllocator allocator, const VmaBufferCreateInfo * pBufferCreateInfo, const VmaAllocationCreateInfo * pAllocationCreateInfo, unsigned * pMemoryTypeIndex);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaFindMemoryTypeIndexForImageInfo  (VmaAllocator allocator, const VmaImageCreateInfo * pImageCreateInfo, const VmaAllocationCreateInfo * pAllocationCreateInfo, unsigned * pMemoryTypeIndex);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaCreatePool                       (VmaAllocator allocator, const VmaPoolCreateInfo * pCreateInfo, VmaPool * pPool);
VMA_CALL_PRE void      VMA_CALL_POST vmaDestroyPool                      (VmaAllocator allocator, VmaPool pool);
VMA_CALL_PRE void      VMA_CALL_POST vmaGetPoolStats                     (VmaAllocator allocator, VmaPool pool, VmaPoolStats * pPoolStats);
VMA_CALL_PRE void      VMA_CALL_POST vmaMakePoolAllocationsLost          (VmaAllocator allocator, VmaPool pool, size_t * pLostAllocationCount);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaCheckPoolCorruption              (VmaAllocator allocator, VmaPool pool);
VMA_CALL_PRE void      VMA_CALL_POST vmaGetPoolName                      (VmaAllocator allocator, VmaPool pool, const char ** ppName);
VMA_CALL_PRE void      VMA_CALL_POST vmaSetPoolName                      (VmaAllocator allocator, VmaPool pool, const char * pName);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaAllocateMemory                   (VmaAllocator allocator, const VmaMemoryRequirements * pVkMemoryRequirements, const VmaAllocationCreateInfo * pCreateInfo, VmaAllocation * pAllocation, VmaAllocationInfo * pAllocationInfo);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaAllocateMemoryPages              (VmaAllocator allocator, const VmaMemoryRequirements * pVkMemoryRequirements, const VmaAllocationCreateInfo * pCreateInfo, size_t allocationCount, VmaAllocation * pAllocations, VmaAllocationInfo * pAllocationInfo);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaAllocateMemoryForBuffer          (VmaAllocator allocator, const RedArray * buffer, const VmaAllocationCreateInfo * pCreateInfo, VmaAllocation * pAllocation, VmaAllocationInfo * pAllocationInfo);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaAllocateMemoryForImage           (VmaAllocator allocator, const RedImage * image, const VmaAllocationCreateInfo * pCreateInfo, VmaAllocation * pAllocation, VmaAllocationInfo * pAllocationInfo);
VMA_CALL_PRE void      VMA_CALL_POST vmaFreeMemory                       (VmaAllocator allocator, const VmaAllocation allocation);
VMA_CALL_PRE void      VMA_CALL_POST vmaFreeMemoryPages                  (VmaAllocator allocator, size_t allocationCount, const VmaAllocation * pAllocations);
VMA_CALL_PRE void      VMA_CALL_POST vmaGetAllocationInfo                (VmaAllocator allocator, VmaAllocation allocation, VmaAllocationInfo * pAllocationInfo);
VMA_CALL_PRE RedBool32 VMA_CALL_POST vmaTouchAllocation                  (VmaAllocator allocator, VmaAllocation allocation);
VMA_CALL_PRE void      VMA_CALL_POST vmaSetAllocationUserData            (VmaAllocator allocator, VmaAllocation allocation, void * pUserData);
VMA_CALL_PRE void      VMA_CALL_POST vmaCreateLostAllocation             (VmaAllocator allocator, VmaAllocation * pAllocation);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaMapMemory                        (VmaAllocator allocator, VmaAllocation allocation, void ** ppData);
VMA_CALL_PRE void      VMA_CALL_POST vmaUnmapMemory                      (VmaAllocator allocator, VmaAllocation allocation);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaFlushAllocation                  (VmaAllocator allocator, VmaAllocation allocation, uint64_t offset, uint64_t size);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaInvalidateAllocation             (VmaAllocator allocator, VmaAllocation allocation, uint64_t offset, uint64_t size);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaFlushAllocations                 (VmaAllocator allocator, unsigned allocationCount, const VmaAllocation * allocations, const uint64_t * offsets, const uint64_t * sizes);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaInvalidateAllocations            (VmaAllocator allocator, unsigned allocationCount, const VmaAllocation * allocations, const uint64_t * offsets, const uint64_t * sizes);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaCheckCorruption                  (VmaAllocator allocator, unsigned memoryTypeBits);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaDefragmentationBegin             (VmaAllocator allocator, const VmaDefragmentationInfo2 * pInfo, VmaDefragmentationStats * pStats, VmaDefragmentationContext * pContext);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaDefragmentationEnd               (VmaAllocator allocator, VmaDefragmentationContext context);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaBeginDefragmentationPass         (VmaAllocator allocator, VmaDefragmentationContext context, VmaDefragmentationPassInfo * pInfo);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaEndDefragmentationPass           (VmaAllocator allocator, VmaDefragmentationContext context);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaDefragment                       (VmaAllocator allocator, const VmaAllocation * pAllocations, size_t allocationCount, RedBool32 * pAllocationsChanged, const VmaDefragmentationInfo * pDefragmentationInfo, VmaDefragmentationStats * pDefragmentationStats);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaBindBufferMemory                 (VmaAllocator allocator, VmaAllocation allocation, RedHandleArray buffer);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaBindBufferMemory2                (VmaAllocator allocator, VmaAllocation allocation, uint64_t allocationLocalOffset, RedHandleArray buffer, const void * pNext);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaBindImageMemory                  (VmaAllocator allocator, VmaAllocation allocation, RedHandleImage image);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaBindImageMemory2                 (VmaAllocator allocator, VmaAllocation allocation, uint64_t allocationLocalOffset, RedHandleImage image, const void * pNext);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaCreateBuffer                     (VmaAllocator allocator, const VmaBufferCreateInfo * pBufferCreateInfo, const VmaAllocationCreateInfo * pAllocationCreateInfo, RedArray * pBuffer, VmaAllocation * pAllocation, VmaAllocationInfo * pAllocationInfo);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaCreateBufferWithAlignment        (VmaAllocator allocator, const VmaBufferCreateInfo * pBufferCreateInfo, const VmaAllocationCreateInfo * pAllocationCreateInfo, uint64_t minAlignment, RedArray * pBuffer, VmaAllocation * pAllocation, VmaAllocationInfo * pAllocationInfo);
VMA_CALL_PRE void      VMA_CALL_POST vmaDestroyBuffer                    (VmaAllocator allocator, RedHandleArray buffer, VmaAllocation allocation);
VMA_CALL_PRE RedStatus VMA_CALL_POST vmaCreateImage                      (VmaAllocator allocator, const VmaImageCreateInfo * pImageCreateInfo, const VmaAllocationCreateInfo * pAllocationCreateInfo, RedImage * pImage, VmaAllocation * pAllocation, VmaAllocationInfo * pAllocationInfo);
VMA_CALL_PRE void      VMA_CALL_POST vmaDestroyImage                     (VmaAllocator allocator, RedHandleImage image, VmaAllocation allocation);
#endif

#ifdef __cplusplus
}
#endif
