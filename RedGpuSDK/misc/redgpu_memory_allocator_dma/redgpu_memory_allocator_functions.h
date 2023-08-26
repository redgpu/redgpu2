#pragma once

#define VK_NO_PROTOTYPES
#ifdef _WIN32
#include "C:/VulkanSDK/1.2.135.0/Include/vulkan/vulkan_core.h"
#endif
#ifdef __linux__
#include "/opt/RedGpuSDK/sdk/1.2.135.0/x86_64/include/vulkan/vulkan_core.h"
#endif
#undef  VK_NV_ray_tracing
#define VK_NV_ray_tracing 0

#ifdef _WIN32
#include "C:/RedGpuSDK/redgpu.h"
#endif
#ifdef __linux__
#include "/opt/RedGpuSDK/redgpu.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RedVkBuffer {
  VkBuffer handle;
  uint64_t memoryBytesAlignment;
  uint64_t memoryBytesCount;
  unsigned memoryTypesSupported;
} RedVkBuffer;

typedef struct RedVkImage {
  VkImage  handle;
  uint64_t memoryBytesAlignment;
  uint64_t memoryBytesCount;
  unsigned memoryTypesSupported;
} RedVkImage;

REDGPU_DECLSPEC void     REDGPU_API rmaDmaVkGetPhysicalDeviceProperties2      (RedContext context, unsigned gpuIndex, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2 * pProperties);
REDGPU_DECLSPEC void     REDGPU_API rmaDmaVkGetPhysicalDeviceMemoryProperties (RedContext context, unsigned gpuIndex, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties * pMemoryProperties);
REDGPU_DECLSPEC VkResult REDGPU_API rmaDmaVkAllocateMemory                    (RedContext context, unsigned gpuIndex, VkDevice device, const VkMemoryAllocateInfo * pAllocateInfo, const VkAllocationCallbacks * pAllocator, VkDeviceMemory * pMemory, const char * name);
REDGPU_DECLSPEC void     REDGPU_API rmaDmaVkFreeMemory                        (RedContext context, unsigned gpuIndex, VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks * pAllocator);
REDGPU_DECLSPEC VkResult REDGPU_API rmaDmaVkMapMemory                         (RedContext context, unsigned gpuIndex, VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void ** ppData);
REDGPU_DECLSPEC void     REDGPU_API rmaDmaVkUnmapMemory                       (RedContext context, unsigned gpuIndex, VkDevice device, VkDeviceMemory memory);
REDGPU_DECLSPEC VkResult REDGPU_API rmaDmaVkBindBufferMemory2                 (RedContext context, unsigned gpuIndex, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo * pBindInfos);
REDGPU_DECLSPEC VkResult REDGPU_API rmaDmaVkBindImageMemory2                  (RedContext context, unsigned gpuIndex, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo * pBindInfos);
REDGPU_DECLSPEC void     REDGPU_API rmaDmaVkGetBufferMemoryRequirements2      (RedContext context, unsigned gpuIndex, VkDevice device, const RedVkBuffer * pInfo, VkMemoryRequirements2 * pMemoryRequirements);
REDGPU_DECLSPEC void     REDGPU_API rmaDmaVkGetImageMemoryRequirements2       (RedContext context, unsigned gpuIndex, VkDevice device, const RedVkImage * pInfo, VkMemoryRequirements2 * pMemoryRequirements);
REDGPU_DECLSPEC VkResult REDGPU_API rmaDmaVkCreateBuffer                      (RedContext context, unsigned gpuIndex, VkDevice device, const VkBufferCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, RedVkBuffer * pBuffer);
REDGPU_DECLSPEC void     REDGPU_API rmaDmaVkDestroyBuffer                     (RedContext context, unsigned gpuIndex, VkDevice device, VkBuffer buffer, const VkAllocationCallbacks * pAllocator);
REDGPU_DECLSPEC VkResult REDGPU_API rmaDmaVkCreateImage                       (RedContext context, unsigned gpuIndex, VkDevice device, const VkImageCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, RedVkImage * pImage);
REDGPU_DECLSPEC void     REDGPU_API rmaDmaVkDestroyImage                      (RedContext context, unsigned gpuIndex, VkDevice device, VkImage image, const VkAllocationCallbacks * pAllocator);
REDGPU_DECLSPEC void     REDGPU_API rmaDmaVkCmdInsertDebugUtilsLabelEXT       (RedContext context, unsigned gpuIndex, VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT * pLabelInfo);
REDGPU_DECLSPEC void     REDGPU_API rmaDmaVkCmdBeginDebugUtilsLabelEXT        (RedContext context, unsigned gpuIndex, VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT * pLabelInfo);
REDGPU_DECLSPEC void     REDGPU_API rmaDmaVkCmdEndDebugUtilsLabelEXT          (RedContext context, unsigned gpuIndex, VkCommandBuffer commandBuffer);

#ifdef __cplusplus
}
#endif
