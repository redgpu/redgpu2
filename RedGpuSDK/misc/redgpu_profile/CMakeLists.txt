# This CMakeLists.txt project is for Ubuntu only
project(redgpu_profile C)
cmake_minimum_required(VERSION 2.8.12)
add_library(redgpu_profile SHARED
  redgpu_profile.c
)
