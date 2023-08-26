/*
 * Copyright (c) 2019-2021, NVIDIA CORPORATION.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-FileCopyrightText: Copyright (c) 2019-2021 NVIDIA CORPORATION
 * SPDX-License-Identifier: Apache-2.0
 */


/// \class DebugUtil
/// This is a companion utility to add debug information to an application
/// See https://vulkan.lunarg.com/doc/sdk/1.1.114.0/windows/chunked_spec/chap39.html
/// - User defined name to objects
/// - Logically annotate region of command buffers
/// - Scoped command buffer label to make thing simpler

#pragma once

#include <algorithm>
#include <string.h>
#include <string>

#include "redgpu_memory_allocator_functions.h"

namespace nvvk {

class DebugUtil
{
public:
  DebugUtil() = default;
  DebugUtil(RedContext context, unsigned gpuIndex, VkDevice device)
      : m_context(context)
      , m_gpuIndex(gpuIndex)
      , m_device(device)
  {
  }

  static void setEnabled(bool state) { s_enabled = state; }

  void setup(RedContext context, unsigned gpuIndex, VkDevice device) { m_context = context; m_gpuIndex = gpuIndex; m_device = device; }

  //
  //---------------------------------------------------------------------------
  //
  void beginLabel(VkCommandBuffer cmdBuf, const std::string& label)
  {
    if(s_enabled)
    {
      VkDebugUtilsLabelEXT s{VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, nullptr, label.c_str(), {1.0f, 1.0f, 1.0f, 1.0f}};
      rmaDmaVkCmdBeginDebugUtilsLabelEXT(m_context, m_gpuIndex, cmdBuf, &s);
    }
  }
  void endLabel(VkCommandBuffer cmdBuf)
  {
    if(s_enabled)
    {
      rmaDmaVkCmdEndDebugUtilsLabelEXT(m_context, m_gpuIndex, cmdBuf);
    }
  }
  void insertLabel(VkCommandBuffer cmdBuf, const std::string& label)
  {
    if(s_enabled)
    {
      VkDebugUtilsLabelEXT s{VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, nullptr, label.c_str(), {1.0f, 1.0f, 1.0f, 1.0f}};
      rmaDmaVkCmdInsertDebugUtilsLabelEXT(m_context, m_gpuIndex, cmdBuf, &s);
    }
  }
  //
  // Begin and End Command Label MUST be balanced, this helps as it will always close the opened label
  //
  struct ScopedCmdLabel
  {
    ScopedCmdLabel(RedContext context, unsigned gpuIndex, VkCommandBuffer cmdBuf, const std::string& label)
        : m_context(context)
        , m_gpuIndex(gpuIndex)
        , m_cmdBuf(cmdBuf)
    {
      if(s_enabled)
      {
        VkDebugUtilsLabelEXT s{VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, nullptr, label.c_str(), {1.0f, 1.0f, 1.0f, 1.0f}};
        rmaDmaVkCmdBeginDebugUtilsLabelEXT(context, gpuIndex, cmdBuf, &s);
      }
    }
    ~ScopedCmdLabel()
    {
      if(s_enabled)
      {
        rmaDmaVkCmdEndDebugUtilsLabelEXT(m_context, m_gpuIndex, m_cmdBuf);
      }
    }
    void setLabel(const std::string& label)
    {
      if(s_enabled)
      {
        VkDebugUtilsLabelEXT s{VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, nullptr, label.c_str(), {1.0f, 1.0f, 1.0f, 1.0f}};
        rmaDmaVkCmdInsertDebugUtilsLabelEXT(m_context, m_gpuIndex, m_cmdBuf, &s);
      }
    }

  private:
    RedContext      m_context;
    unsigned        m_gpuIndex;
    VkCommandBuffer m_cmdBuf;
  };

  ScopedCmdLabel scopeLabel(RedContext context, unsigned gpuIndex, VkCommandBuffer cmdBuf, const std::string& label) { return ScopedCmdLabel(context, gpuIndex, cmdBuf, label); }

private:
  RedContext  m_context{NULL};
  unsigned    m_gpuIndex{0};
  VkDevice    m_device{VK_NULL_HANDLE};
  static bool s_enabled;
};

//////////////////////////////////////////////////////////////////////////
/// Macros to help automatically naming variables.
/// Names will be in the form of MyClass::m_myBuffer (in example.cpp:123)
///
/// To use:
/// - Debug member class MUST be named 'm_debug'
/// - Individual name: NAME_VK(m_myBuffer.buffer) or with and index NAME_IDX_VK(m_texture.image, i)
/// - Create/associate and name, instead of
///     pipeline = createPipeline();
///     NAME_VK(pipeline)
///   call
///     CREATE_NAMED_VK(pipeline , createPipeline());
/// - Scope functions can also be automatically named, at the beginning of a function
///   call LABEL_SCOPE_VK( commandBuffer )
///
///
// clang-format off
inline const char* fileNameSplitter(const char* n) { return std::max<const char*>(n, std::max(strrchr(n, '\\') + 1, strrchr(n, '/') + 1)); }
inline const char* upToLastSpace(const char* n) { return std::max<const char*>(n, strrchr(n, ' ') + 1); }
#define CLASS_NAME nvvk::upToLastSpace(typeid(*this).name())
#define NAME_FILE_LOCATION  std::string(" in ") + std::string(nvvk::fileNameSplitter(__FILE__)) + std::string(":" S__LINE__ ")")

// Individual naming
#define NAME_VK(_x) m_debug.setObjectName(_x, (std::string(CLASS_NAME) + std::string("::") + std::string(#_x " (") + NAME_FILE_LOCATION).c_str())
#define NAME_IDX_VK(_x, _i) m_debug.setObjectName(_x, \
                            (std::string(CLASS_NAME) + std::string("::") + std::string(#_x " (" #_i "=") + std::to_string(_i) + std::string(", ") + NAME_FILE_LOCATION).c_str())

// Name in creation
#define CREATE_NAMED_VK(_x, _c)              \
  _x = _c;                                   \
  NAME_VK(_x);
#define CREATE_NAMED_IDX_VK(_x, _i, _c)      \
  _x = _c;                                   \
  NAME_IDX_VK(_x, _i);

// Running scope
#define LABEL_SCOPE_VK(_cmd)                                                                                                                \
  auto _scopeLabel =  m_debug.scopeLabel(_cmd, std::string(CLASS_NAME) + std::string("::") + std::string(__func__) + std::string(", in ")   \
                                   + std::string(nvvk::fileNameSplitter(__FILE__)) + std::string(":" S__LINE__ ")"))

// clang-format on
}  // namespace nvvk
