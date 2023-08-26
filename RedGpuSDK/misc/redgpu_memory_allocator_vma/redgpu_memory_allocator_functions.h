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

REDGPU_DECLSPEC void      REDGPU_API rmaVmaVkGetPhysicalDeviceProperties       (RedContext context, unsigned gpuIndex, RedHandleGpuDevice physicalDevice, void * pVkPhysicalDeviceProperties);
REDGPU_DECLSPEC void      REDGPU_API rmaVmaVkGetPhysicalDeviceMemoryProperties (RedContext context, unsigned gpuIndex, RedHandleGpuDevice physicalDevice, void * pVkPhysicalDeviceMemoryProperties);
REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkAllocateMemory                    (RedContext context, unsigned gpuIndex, RedHandleGpu device, const void * pVkMemoryAllocateInfo, const void * pVkAllocationCallbacks, RedHandleMemory * pMemory);
REDGPU_DECLSPEC void      REDGPU_API rmaVmaVkFreeMemory                        (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleMemory memory, const void * pVkAllocationCallbacks);
REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkMapMemory                         (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleMemory memory, uint64_t offset, uint64_t size, unsigned vkMemoryMapFlags, void ** ppData);
REDGPU_DECLSPEC void      REDGPU_API rmaVmaVkUnmapMemory                       (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleMemory memory);
REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkFlushMappedMemoryRanges           (RedContext context, unsigned gpuIndex, RedHandleGpu device, unsigned memoryRangeCount, const void * pVkMappedMemoryRange);
REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkInvalidateMappedMemoryRanges      (RedContext context, unsigned gpuIndex, RedHandleGpu device, unsigned memoryRangeCount, const void * pVkMappedMemoryRange);
REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkBindBufferMemory                  (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleArray buffer, RedHandleMemory memory, uint64_t memoryOffset);
REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkBindImageMemory                   (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleImage image, RedHandleMemory memory, uint64_t memoryOffset);
REDGPU_DECLSPEC void      REDGPU_API rmaVmaVkGetBufferMemoryRequirements       (RedContext context, unsigned gpuIndex, RedHandleGpu device, const RedArray * buffer, void * pVkMemoryRequirements);
REDGPU_DECLSPEC void      REDGPU_API rmaVmaVkGetImageMemoryRequirements        (RedContext context, unsigned gpuIndex, RedHandleGpu device, const RedImage * image, void * pVkMemoryRequirements);
REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkCreateBuffer                      (RedContext context, unsigned gpuIndex, RedHandleGpu device, const void * pVkBufferCreateInfo, const void * pVkAllocationCallbacks, RedArray * pBuffer);
REDGPU_DECLSPEC void      REDGPU_API rmaVmaVkDestroyBuffer                     (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleArray buffer, const void * pVkAllocationCallbacks);
REDGPU_DECLSPEC RedStatus REDGPU_API rmaVmaVkCreateImage                       (RedContext context, unsigned gpuIndex, RedHandleGpu device, const void * pVkImageCreateInfo, const void * pVkAllocationCallbacks, RedImage * pImage);
REDGPU_DECLSPEC void      REDGPU_API rmaVmaVkDestroyImage                      (RedContext context, unsigned gpuIndex, RedHandleGpu device, RedHandleImage image, const void * pVkAllocationCallbacks);
REDGPU_DECLSPEC void      REDGPU_API rmaVmaVkCmdCopyBuffer                     (RedContext context, unsigned gpuIndex, RedHandleCalls commandBuffer, RedHandleArray srcBuffer, RedHandleArray dstBuffer, unsigned regionCount, const void * pVkBufferCopy);

#ifdef __cplusplus
}
#endif