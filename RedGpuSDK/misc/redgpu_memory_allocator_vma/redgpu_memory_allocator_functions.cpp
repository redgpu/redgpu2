#include "redgpu_memory_allocator_functions.h"

#define VK_NO_PROTOTYPES
#ifdef _WIN32
#include <vulkan/vulkan.h>
#endif
#ifdef __linux__
#include "/opt/RedGpuSDK/sdk/1.2.135.0/x86_64/include/vulkan/vulkan.h"
#endif

#include "redgpu_memory_allocator_internal.h"

REDGPU_DECLSPEC void REDGPU_API rmaVmaVkGetPhysicalDeviceProperties(RedContext context, unsigned gpuIndex, RedHandleGpuDevice physicalDevice, void * pVkPhysicalDeviceProperties) {
  RmaPhysicalDeviceProperties properties = {};
  properties.deviceType                      = (VkPhysicalDeviceType)context->gpus[gpuIndex].gpuType;
  properties.limits.maxMemoryAllocationCount = context->gpus[gpuIndex].maxMemoryAllocateCount;
  properties.limits.bufferImageGranularity   = context->gpus[gpuIndex].minMemoryPageSeparationArrayImageBytesCount;
  properties.limits.nonCoherentAtomSize      = context->gpus[gpuIndex].minMemoryNonCoherentBlockBytesCount;
  RmaPhysicalDeviceProperties * out = (RmaPhysicalDeviceProperties *)pVkPhysicalDeviceProperties;
  out[0] = properties;
}

REDGPU_DECLSPEC void REDGPU_API rmaVmaVkGetPhysicalDeviceMemoryProperties(RedContext context, unsigned gpuIndex, RedHandleGpuDevice physicalDevice, void * pVkPhysicalDeviceMemoryProperties) {
  VkPhysicalDeviceMemoryProperties properties = {};
  properties.memoryTypeCount = context->gpus[gpuIndex].memoryTypesCount;
  properties.memoryHeapCount = context->gpus[gpuIndex].memoryHeapsCount;
  for (unsigned i = 0; i < context->gpus[gpuIndex].memoryTypesCount; i += 1) {
    RedMemoryType memoryType = context->gpus[gpuIndex].memoryTypes[i];
    properties.memoryTypes[i].heapIndex = memoryType.memoryHeapIndex;
    if (memoryType.isGpuVram == 1) {
      properties.memoryTypes[i].propertyFlags |= VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
    }
    if (memoryType.isCpuMappable == 1) {
      properties.memoryTypes[i].propertyFlags |= VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT;
    }
    if (memoryType.isCpuCoherent == 1) {
      properties.memoryTypes[i].propertyFlags |= VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
    }
    if (memoryType.isCpuCached == 1) {
      properties.memoryTypes[i].propertyFlags |= VK_MEMORY_PROPERTY_HOST_CACHED_BIT;
    }
  }
  for (unsigned i = 0; i < context->gpus[gpuIndex].memoryHeapsCount; i += 1) {
    RedMemoryHeap memoryHeap = context->gpus[gpuIndex].memoryHeaps[i];
    properties.memoryHeaps[i].size = memoryHeap.memoryBytesCount;
    if (memoryHeap.isGpuVram == 1) {
      properties.memoryHeaps[i].flags |= VK_MEMORY_HEAP_DEVICE_LOCAL_BIT;
    }
  }
  VkPhysicalDeviceMemoryProperties * out = (VkPhysicalDeviceMemoryProperties *)pVkPhysicalDeviceMemoryProperties;
  out[0] = properties;
}

#include <mutex>
#include <map>

static std::mutex                                __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArrayMutex;
static std::map<RedHandleMemory, RedHandleArray> __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArray;
static std::map<RedHandleMemory, uint64_t>       __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArrayBytesCount;

REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkAllocateMemory(RedContext context, unsigned gpuIndex, RedHandleGpu device, const void * pVkMemoryAllocateInfo, const void * pVkAllocationCallbacks, RedHandleMemory * pMemory) {
  const VkMemoryAllocateInfo * memoryAllocateInfo = (const VkMemoryAllocateInfo *)pVkMemoryAllocateInfo;
  RedStatuses statuses = {};
  if (context->gpus[gpuIndex].memoryTypes[memoryAllocateInfo->memoryTypeIndex].isCpuMappable == 1) {
    // NOTE(Constantine): Pass array from VMA to RMA in future.
#ifdef REDGPU_USE_REDGPU_X
    RedArray array = {};
    redCreateArray(context, device, "REDGPU Memory Allocator VMA", RED_ARRAY_TYPE_ARRAY_RO, memoryAllocateInfo->allocationSize, 0, 0, 0, 0, &array, &statuses, 0, 0, 0);
    uint64_t memoryBytesCount = memoryAllocateInfo->allocationSize;
    if (array.memoryBytesCount > memoryAllocateInfo->allocationSize) {
      memoryBytesCount = array.memoryBytesCount;
    }
    pMemory[0] = 0;
    if (array.handle != 0) {
      redMemoryAllocateMappable(context, device, "REDGPU Memory Allocator VMA", 0, array.handle, memoryBytesCount, memoryAllocateInfo->memoryTypeIndex, 0, pMemory, &statuses, 0, 0, 0);
    }
    if (pMemory[0] != 0) {
      RedMemoryArray memoryArray = {};
      memoryArray.setTo1000157000  = 1000157000;
      memoryArray.setTo0           = 0;
      memoryArray.array            = array.handle;
      memoryArray.memory           = pMemory[0];
      memoryArray.memoryBytesFirst = 0;
      redMemorySet(context, device, 1, &memoryArray, 0, 0, &statuses, 0, 0, 0);
    }
    if (pMemory[0] != 0) {
      std::lock_guard<std::mutex> __mappableMemoryArrayMutexLockGuard(__REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArrayMutex);
      __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArray[pMemory[0]]           = array.handle;
      __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArrayBytesCount[pMemory[0]] = memoryAllocateInfo->allocationSize;
    }
#else
    RedHandleArray array = 0;
    redMemoryAllocateMappable(context, device, "REDGPU Memory Allocator VMA", 0, array, memoryAllocateInfo->allocationSize, memoryAllocateInfo->memoryTypeIndex, 0, pMemory, &statuses, 0, 0, 0);
#endif
  } else {
    redMemoryAllocate(context, device, "REDGPU Memory Allocator VMA", memoryAllocateInfo->allocationSize, memoryAllocateInfo->memoryTypeIndex, 0, 0, 0, pMemory, &statuses, 0, 0, 0);
  }
  return statuses.statusError;
}

REDGPU_DECLSPEC void REDGPU_API rmaVmaVkFreeMemory(RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleMemory memory, const void * pVkAllocationCallbacks) {
#ifdef REDGPU_USE_REDGPU_X
  {
    std::lock_guard<std::mutex> __mappableMemoryArrayMutexLockGuard(__REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArrayMutex);
    std::map<RedHandleMemory, RedHandleArray>::iterator it1 = __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArray.find(memory);
    std::map<RedHandleMemory, uint64_t>::iterator       it2 = __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArrayBytesCount.find(memory);
    if (it1 != __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArray.end()) {
      RedHandleArray array = __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArray[memory];
      redDestroyArray(context, device, array, 0, 0, 0);
      __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArray.erase(it1);
    }
    if (it2 != __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArrayBytesCount.end()) {
      __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArrayBytesCount.erase(it2);
    }
  }
#endif
  redMemoryFree(context, device, memory, 0, 0, 0);
}

REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkMapMemory(RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleMemory memory, uint64_t offset, uint64_t size, unsigned vkMemoryMapFlags, void ** ppData) {
  RedStatuses statuses = {};
#ifdef REDGPU_USE_REDGPU_X
  if (size == VK_WHOLE_SIZE) {
    std::lock_guard<std::mutex> __mappableMemoryArrayMutexLockGuard(__REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArrayMutex);
    std::map<RedHandleMemory, uint64_t>::iterator it = __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArrayBytesCount.find(memory);
    if (it != __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArrayBytesCount.end()) {
      size = __REDGPU_RMA_VMA_GLOBAL_ec8b2cdd_mappableMemoryArrayBytesCount[memory];
    }
  }
#endif
  redMemoryMap(context, device, memory, offset, size, ppData, &statuses, 0, 0, 0);
  return statuses.statusError;
}

REDGPU_DECLSPEC void REDGPU_API rmaVmaVkUnmapMemory(RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleMemory memory) {
  redMemoryUnmap(context, device, memory, 0, 0, 0);
}

REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkFlushMappedMemoryRanges(RedContext context, unsigned gpuIndex, RedHandleGpu device, unsigned memoryRangeCount, const void * pVkMappedMemoryRange) {
  RedStatuses statuses = {};
  redMemoryNonCoherentFlush(context, device, memoryRangeCount, (const RedMappableMemoryRange *)pVkMappedMemoryRange, &statuses, 0, 0, 0);
  return statuses.statusError;
}

REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkInvalidateMappedMemoryRanges(RedContext context, unsigned gpuIndex, RedHandleGpu device, unsigned memoryRangeCount, const void * pVkMappedMemoryRange) {
  RedStatuses statuses = {};
  redMemoryNonCoherentInvalidate(context, device, memoryRangeCount, (const RedMappableMemoryRange *)pVkMappedMemoryRange, &statuses, 0, 0, 0);
  return statuses.statusError;
}

REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkBindBufferMemory(RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleArray buffer, RedHandleMemory memory, uint64_t memoryOffset) {
  RedStatuses statuses = {};
  RedMemoryArray memoryArray = {};
  memoryArray.setTo1000157000  = 1000157000;
  memoryArray.setTo0           = 0;
  memoryArray.array            = buffer;
  memoryArray.memory           = memory;
  memoryArray.memoryBytesFirst = memoryOffset;
  redMemorySet(context, device, 1, &memoryArray, 0, 0, &statuses, 0, 0, 0);
  return statuses.statusError;
}

REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkBindImageMemory(RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleImage image, RedHandleMemory memory, uint64_t memoryOffset) {
  RedStatuses statuses = {};
  RedMemoryImage memoryImage = {};
  memoryImage.setTo1000157001  = 1000157001;
  memoryImage.setTo0           = 0;
  memoryImage.image            = image;
  memoryImage.memory           = memory;
  memoryImage.memoryBytesFirst = memoryOffset;
  redMemorySet(context, device, 0, 0, 1, &memoryImage, &statuses, 0, 0, 0);
  return statuses.statusError;
}

REDGPU_DECLSPEC void REDGPU_API rmaVmaVkGetBufferMemoryRequirements(RedContext context, unsigned gpuIndex, RedHandleGpu device, const RedArray * buffer, void * pVkMemoryRequirements) {
  VkMemoryRequirements * out = (VkMemoryRequirements *)pVkMemoryRequirements;
  out->size           = buffer->memoryBytesCount;
  out->alignment      = buffer->memoryBytesAlignment;
  out->memoryTypeBits = buffer->memoryTypesSupported;
}

REDGPU_DECLSPEC void REDGPU_API rmaVmaVkGetImageMemoryRequirements(RedContext context, unsigned gpuIndex, RedHandleGpu device, const RedImage * image, void * pVkMemoryRequirements) {
  VkMemoryRequirements * out = (VkMemoryRequirements *)pVkMemoryRequirements;
  out->size           = image->memoryBytesCount;
  out->alignment      = image->memoryBytesAlignment;
  out->memoryTypeBits = image->memoryTypesSupported;
}

REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkCreateBuffer(RedContext context, unsigned gpuIndex, RedHandleGpu device, const void * pVkBufferCreateInfo, const void * pVkAllocationCallbacks, RedArray * pBuffer) {
  const VkBufferCreateInfo * createInfo = (const VkBufferCreateInfo *)pVkBufferCreateInfo;
  RedStatuses statuses = {};
  // NOTE(Constantine): Pass structuredBufferElementBytesCount from VMA to RMA in future.
  uint64_t structuredBufferElementBytesCount = 0;
  // NOTE(Constantine): Pass initialAccess from VMA to RMA in future.
  RedAccessBitflags initialAccess = 0;
  RedArray array = {};
  redCreateArray(context, device, "REDGPU Memory Allocator VMA", (RedArrayType)createInfo->usage, createInfo->size, structuredBufferElementBytesCount, initialAccess, (createInfo->sharingMode == VK_SHARING_MODE_CONCURRENT || createInfo->queueFamilyIndexCount == 0) ? -1 : createInfo->pQueueFamilyIndices[0], 0, &array, &statuses, 0, 0, 0);
  pBuffer[0] = array;
  return statuses.statusError;
}

REDGPU_DECLSPEC void REDGPU_API rmaVmaVkDestroyBuffer(RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleArray buffer, const void * pVkAllocationCallbacks) {
  redDestroyArray(context, device, buffer, 0, 0, 0);
}

REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkCreateImage(RedContext context, unsigned gpuIndex, RedHandleGpu device, const void * pVkImageCreateInfo, const void * pVkAllocationCallbacks, RedImage * pImage) {
  const VkImageCreateInfo * createInfo = (const VkImageCreateInfo *)pVkImageCreateInfo;
  RedStatuses statuses = {};
  RedImageDimensions imageDimensions = RED_IMAGE_DIMENSIONS_2D;
  if (createInfo->imageType == VK_IMAGE_TYPE_1D) {
    imageDimensions = RED_IMAGE_DIMENSIONS_1D;
  } else if (createInfo->imageType == VK_IMAGE_TYPE_2D && ((createInfo->flags & VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT) == VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT)) {
    imageDimensions = RED_IMAGE_DIMENSIONS_2D_WITH_TEXTURE_DIMENSIONS_CUBE_AND_CUBE_LAYERED;
  } else if (createInfo->imageType == VK_IMAGE_TYPE_2D) {
    imageDimensions = RED_IMAGE_DIMENSIONS_2D;
  } else if (createInfo->imageType == VK_IMAGE_TYPE_3D && ((createInfo->flags & VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT) == VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT)) {
    imageDimensions = RED_IMAGE_DIMENSIONS_3D_WITH_TEXTURE_DIMENSIONS_2D_AND_2D_LAYERED;
  } else if (createInfo->imageType == VK_IMAGE_TYPE_3D) {
    imageDimensions = RED_IMAGE_DIMENSIONS_3D;
  }
  RedAccessBitflags restrictToAccess = 0;
  if ((createInfo->usage & VK_IMAGE_USAGE_TRANSFER_SRC_BIT) == VK_IMAGE_USAGE_TRANSFER_SRC_BIT) {
    restrictToAccess |= RED_ACCESS_BITFLAG_COPY_R;
  }
  if ((createInfo->usage & VK_IMAGE_USAGE_TRANSFER_DST_BIT) == VK_IMAGE_USAGE_TRANSFER_DST_BIT) {
    restrictToAccess |= RED_ACCESS_BITFLAG_COPY_W;
  }
  if ((createInfo->usage & VK_IMAGE_USAGE_SAMPLED_BIT) == VK_IMAGE_USAGE_SAMPLED_BIT) {
    restrictToAccess |= RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R | RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R;
  }
  if ((createInfo->usage & VK_IMAGE_USAGE_STORAGE_BIT) == VK_IMAGE_USAGE_STORAGE_BIT) {
    restrictToAccess |= RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W;
  }
  if ((createInfo->usage & VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT) == VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT) {
    restrictToAccess |= RED_ACCESS_BITFLAG_OUTPUT_COLOR_W;
  }
  if ((createInfo->usage & VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT) == VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT) {
    restrictToAccess |= RED_ACCESS_BITFLAG_OUTPUT_DEPTH_RW;
    if ((RedFormat)createInfo->format == RED_FORMAT_DEPTH_24_UINT_TO_FLOAT_0_1_STENCIL_8_UINT ||
        (RedFormat)createInfo->format == RED_FORMAT_DEPTH_32_FLOAT_STENCIL_8_UINT)
    {
      restrictToAccess |= RED_ACCESS_BITFLAG_OUTPUT_STENCIL_RW;
    }
  }
  // NOTE(Constantine): Pass initialAccess from VMA to RMA in future.
  RedAccessBitflags initialAccess = 0;
  RedImage image = {};
  redCreateImage(context, device, "REDGPU Memory Allocator VMA", imageDimensions, (RedFormat)createInfo->format, createInfo->extent.width, createInfo->extent.height, createInfo->extent.depth, createInfo->mipLevels, createInfo->arrayLayers, (RedMultisampleCountBitflag)createInfo->samples, restrictToAccess, initialAccess, (createInfo->sharingMode == VK_SHARING_MODE_CONCURRENT || createInfo->queueFamilyIndexCount == 0) ? -1 : createInfo->pQueueFamilyIndices[0], 0, &image, &statuses, 0, 0, 0);
  pImage[0] = image;
  return statuses.statusError;
}

REDGPU_DECLSPEC void REDGPU_API rmaVmaVkDestroyImage(RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleImage image, const void * pVkAllocationCallbacks) {
  redDestroyImage(context, device, image, 0, 0, 0);
}

REDGPU_DECLSPEC void REDGPU_API rmaVmaVkCmdCopyBuffer(RedContext context, unsigned gpuIndex, RedHandleCalls commandBuffer, RedHandleArray srcBuffer, RedHandleArray dstBuffer, unsigned regionCount, const void * pVkBufferCopy) {
  RedCallProceduresAndAddresses callPAs;
  redGetCallProceduresAndAddresses(context, context->gpus[gpuIndex].gpu, &callPAs, 0, 0, 0, 0);
  callPAs.redCallCopyArrayToArray(commandBuffer, srcBuffer, dstBuffer, regionCount, (const RedCopyArrayRange *)pVkBufferCopy);
}