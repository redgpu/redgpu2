# This CMakeLists.txt project is for Ubuntu only
project(redgpu_memory_allocator_dma)
cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_CXX_STANDARD 14)
link_libraries(
  /opt/RedGpuSDK/libredgpu.so
)
add_library(redgpu_memory_allocator_dma SHARED
  debug_util_vk.cpp
  error_vk.cpp
  memallocator_vk.cpp
  memorymanagement_vk.cpp
  nvprint.cpp
  redgpu_memory_allocator_functions.cpp
)
