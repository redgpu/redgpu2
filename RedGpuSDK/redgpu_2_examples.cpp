//#define REDGPU_2_EXAMPLE_NUMBER_0
//#define REDGPU_2_EXAMPLE_NUMBER_1
//#define REDGPU_2_EXAMPLE_NUMBER_2

#if defined(REDGPU_2_EXAMPLE_NUMBER_0) || defined(REDGPU_2_EXAMPLE_NUMBER_1)

// FILE(Constantine): imgui_impl_redgpu.h

// dear imgui: Renderer Backend for REDGPU
// This needs to be used along with a Platform Backend (e.g. GLFW, SDL, Win32, custom..)

// Important: on 32-bit systems, user texture binding is only supported if your imconfig file has '#define ImTextureID ImU64'.
// See imgui_impl_redgpu.cpp file for details.

// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"      // IMGUI_IMPL_API

// REDGPU includes
#ifdef _WIN32
#include "C:/RedGpuSDK/redgpu.h"
#include "C:/RedGpuSDK/redgpu_wsi.h"
#include "C:/RedGpuSDK/redgpu_array_timestamp.h"
#else
#include "/opt/RedGpuSDK/redgpu.h"
#include "/opt/RedGpuSDK/redgpu_wsi.h"
#include "/opt/RedGpuSDK/redgpu_array_timestamp.h"
#endif
#ifdef REDGPU_USE_REDGPU_X
#include "C:/RedGpuSDK/redgpu_x.h"
#include "C:/RedGpuSDK/redgpu_x12.h"
#else
#define REDX_STRUCT_MEMBER_TYPE_ARRAY_RO RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW
#endif

// Initialization data, for ImGui_ImplRedGpu_Init()
// [Please zero-clear before use!]
struct ImGui_ImplRedGpu_InitInfo
{
    RedContext                      Instance;
    RedHandleGpuDevice              PhysicalDevice;
    RedHandleGpu                    Device;
    uint32_t                        DeviceIndex;
    uint32_t                        QueueFamily;
    RedHandleProcedureCache         PipelineCache;
    RedHandleStructsMemory          DescriptorPool;
    RedHandleStructsMemory          DescriptorPoolSamplers;
    uint32_t                        Subpass;
    uint32_t                        MinImageCount;          // >= 2
    uint32_t                        ImageCount;             // >= MinImageCount
    RedMultisampleCountBitflag      MSAASamples;            // >= RED_MULTISAMPLE_COUNT_BITFLAG_1 (0 -> default to RED_MULTISAMPLE_COUNT_BITFLAG_1)
};

// Called by user code
IMGUI_IMPL_API bool         ImGui_ImplRedGpu_Init(ImGui_ImplRedGpu_InitInfo* info, RedHandleOutputDeclaration render_pass);
IMGUI_IMPL_API void         ImGui_ImplRedGpu_Shutdown();
IMGUI_IMPL_API void         ImGui_ImplRedGpu_NewFrame();
IMGUI_IMPL_API void         ImGui_ImplRedGpu_RenderDrawData(ImDrawData* draw_data, RedHandleCalls command_buffer, RedHandleProcedure pipeline = NULL);
IMGUI_IMPL_API bool         ImGui_ImplRedGpu_CreateFontsTexture(RedHandleCalls command_buffer);
IMGUI_IMPL_API void         ImGui_ImplRedGpu_DestroyFontUploadObjects();

// Register a texture (RedHandleStruct == ImTextureID)
// FIXME: This is experimental in the sense that we are unsure how to best design/tackle this problem, please post to https://github.com/ocornut/imgui/pull/914 if you have suggestions.
IMGUI_IMPL_API RedHandleStruct ImGui_ImplRedGpu_AddTexture(RedHandleSampler sampler, RedHandleTexture image_view);

//-------------------------------------------------------------------------
// Internal / Miscellaneous RedGpu Helpers
// (Used by example's main.cpp. Used by multi-viewport features. PROBABLY NOT used by your own engine/app.)
//-------------------------------------------------------------------------
// You probably do NOT need to use or care about those functions.
// Those functions only exist because:
//   1) they facilitate the readability and maintenance of the multiple main.cpp examples files.
//   2) the upcoming multi-viewport feature will need them internally.
// Generally we avoid exposing any kind of superfluous high-level helpers in the backends,
// but it is too much code to duplicate everywhere so we exceptionally expose them.
//
// Your engine/app will likely _already_ have code to setup all that stuff (swap chain, render pass, frame buffers, etc.).
// You may read this code to learn about RedGpu, but it is recommended you use you own custom tailored code to do equivalent work.
// (The ImGui_ImplRedGpuH_XXX functions do not interact with any of the state used by the regular ImGui_ImplRedGpu_XXX functions)
//-------------------------------------------------------------------------

struct ImGui_ImplRedGpuH_Frame;
struct ImGui_ImplRedGpuH_Window;

IMGUI_IMPL_API void                 ImGui_ImplRedGpu_SetMinImageCount(uint32_t min_image_count, ImGui_ImplRedGpuH_Window* wd); // To override MinImageCount after initialization (e.g. if swap chain is recreated)

// Helpers
IMGUI_IMPL_API void                 ImGui_ImplRedGpuH_CreateOrResizeWindow(RedContext instance, uint32_t deviceIndex, RedHandleGpuDevice physical_device, RedHandleGpu device, RedHandleQueue present_queue, ImGui_ImplRedGpuH_Window* wnd, uint32_t queue_family, int w, int h, uint32_t min_image_count, void * windowHandle, int screenW, int screenH);
IMGUI_IMPL_API void                 ImGui_ImplRedGpuH_DestroyWindow(RedContext instance, uint32_t deviceIndex, RedHandleGpu device, RedHandleQueue present_queue, ImGui_ImplRedGpuH_Window* wnd);
IMGUI_IMPL_API RedFormat            ImGui_ImplRedGpuH_SelectSurfaceFormat();
IMGUI_IMPL_API int                  ImGui_ImplRedGpuH_GetMinImageCountFromPresentMode(RedPresentVsyncMode present_mode);

// Helper structure to hold the data needed by one rendering frame
// (Used by example's main.cpp. Used by multi-viewport features. Probably NOT used by your own engine/app.)
// [Please zero-clear before use!]
struct ImGui_ImplRedGpuH_Frame
{
    RedCalls            CommandBuffer;
    RedHandleCpuSignal  Fence;
    RedHandleImage      Backbuffer;
    RedHandleTexture    BackbufferView;
    RedOutput           Framebuffer;
};

struct ImGui_ImplRedGpuH_FrameSemaphores
{
    RedHandleGpuSignal  ImageAcquiredSemaphore;
    RedHandleGpuSignal  RenderCompleteSemaphore;
};

// Helper structure to hold the data needed by one rendering context into one OS window
// (Used by example's main.cpp. Used by multi-viewport features. Probably NOT used by your own engine/app.)
struct ImGui_ImplRedGpuH_Window
{
    int                 Width;
    int                 Height;
    RedHandlePresent    Swapchain;
    RedHandleSurface    Surface;
    RedFormat           SurfaceFormat;
    RedPresentVsyncMode PresentMode;
    RedHandleOutputDeclaration RenderPass;
    RedHandleProcedure  Pipeline;               // The window pipeline may uses a different VkRenderPass than the one passed in ImGui_ImplRedGpu_InitInfo
    bool                ClearEnable;
    float               ClearValues[4];
    uint32_t            FrameIndex;             // Current frame being rendered to (0 <= FrameIndex < FrameInFlightCount)
    uint32_t            ImageCount;             // Number of simultaneous in-flight frames (returned by vkGetSwapchainImagesKHR, usually derived from min_image_count)
    uint32_t            SemaphoreIndex;         // Current set of swapchain wait semaphores we're using (needs to be distinct from per frame data)
    ImGui_ImplRedGpuH_Frame*            Frames;
    ImGui_ImplRedGpuH_FrameSemaphores*  FrameSemaphores;

    ImGui_ImplRedGpuH_Window()
    {
        memset((void*)this, 0, sizeof(*this));
        PresentMode = (RedPresentVsyncMode)~0;     // Ensure we get an error if user doesn't set this.
        ClearEnable = true;
    }
};

#endif // #if defined(REDGPU_2_EXAMPLE_NUMBER_0) || defined(REDGPU_2_EXAMPLE_NUMBER_1)

#if defined(REDGPU_2_EXAMPLE_NUMBER_0)

// DEPENDENCY(Constantine): Dear ImGui docking branch v1.89.6, commit 823a1385a269d923d35b82b2f470f3ae1fa8b5a3
// DEPENDENCY(Constantine): GLFW 3.3.2, commit 0a49ef0a00baa3ab520ddc452f0e3b1e099c5589

// COMPILE(Constantine):
// g++.exe -c -DREDGPU_2_EXAMPLE_NUMBER_0 -DREDGPU_USE_REDGPU_X -DImTextureID=ImU64 -DImDrawIdx=unsigned -Iimgui/ -Iglfw-3.3.2.bin.WIN64/include/ redgpu_2_examples.cpp -o imgui_impl_redgpu.o

// FILE(Constantine): imgui_impl_redgpu.cpp

// dear imgui: Renderer Backend for REDGPU
// This needs to be used along with a Platform Backend (e.g. GLFW, SDL, Win32, custom..)

// Important: on 32-bit systems, user texture binding is only supported if your imconfig file has '#define ImTextureID ImU64'.
// This is because we need ImTextureID to carry a 64-bit value and by default ImTextureID is defined as void*.
// To build this on 32-bit systems and support texture changes:
// - [Solution 1] IDE/msbuild: in "Properties/C++/Preprocessor Definitions" add 'ImTextureID=ImU64' (this is what we do in our .vcxproj files)
// - [Solution 2] IDE/msbuild: in "Properties/C++/Preprocessor Definitions" add 'IMGUI_USER_CONFIG="my_imgui_config.h"' and inside 'my_imgui_config.h' add '#define ImTextureID ImU64' and as many other options as you like.
// - [Solution 3] IDE/msbuild: edit imconfig.h and add '#define ImTextureID ImU64' (prefer solution 2 to create your own config file!)
// - [Solution 4] command-line: add '/D ImTextureID=ImU64' to your cl.exe command-line (this is what we do in our batch files)

// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include <stdio.h>

// Visual Studio warnings
#ifdef _MSC_VER
#pragma warning (disable: 4127) // condition expression is constant
#endif

// Reusable buffers used for rendering 1 current in-flight frame, for ImGui_ImplRedGpu_RenderDrawData()
// [Please zero-clear before use!]
struct ImGui_ImplRedGpuH_FrameRenderBuffers
{
    RedHandleMemory     VertexBufferMemory;
    RedHandleMemory     IndexBufferMemory;
    uint64_t            VertexBufferSize;
    uint64_t            IndexBufferSize;
    RedArray            VertexBuffer;
    RedArray            IndexBuffer;
};

// Each viewport will hold 1 ImGui_ImplRedGpuH_WindowRenderBuffers
// [Please zero-clear before use!]
struct ImGui_ImplRedGpuH_WindowRenderBuffers
{
    uint32_t            Index;
    uint32_t            Count;
    ImGui_ImplRedGpuH_FrameRenderBuffers*   FrameRenderBuffers;
};

// RedGpu data
struct ImGui_ImplRedGpu_Data
{
    ImGui_ImplRedGpu_InitInfo   RedGpuInitInfo;
    RedHandleOutputDeclaration  RenderPass;
    uint64_t                    BufferMemoryAlignment;
    RedHandleStructDeclaration  SamplerDescriptorSetLayout;
    RedHandleStructDeclaration  DescriptorSetLayout;
    RedHandleStructDeclaration  ImdrawvertsDescriptorSetLayout;
    RedHandleProcedureParameters PipelineLayout;
    RedHandleProcedure          Pipeline;
    uint32_t                    Subpass;
    RedHandleGpuCode            ShaderModuleVert;
    RedHandleGpuCode            ShaderModuleFrag;

    // Font data
    RedHandleSampler            FontSampler;
    RedHandleMemory             FontMemory;
    RedImage                    FontImage;
    RedHandleTexture            FontView;
    RedHandleStruct             FontSamplerDescriptorSet;
    RedHandleStruct             FontDescriptorSet;
    RedHandleMemory             UploadBufferMemory;
    RedArray                    UploadBuffer;

    // Render buffers
    ImGui_ImplRedGpuH_WindowRenderBuffers MainWindowRenderBuffers;

    ImGui_ImplRedGpu_Data()
    {
        memset((void*)this, 0, sizeof(*this));
        BufferMemoryAlignment = 256;
    }
};

// Forward Declarations
bool ImGui_ImplRedGpu_CreateDeviceObjects();
void ImGui_ImplRedGpu_DestroyDeviceObjects();
void ImGui_ImplRedGpuH_DestroyFrame(RedContext instance, uint32_t deviceIndex, RedHandleGpu device, ImGui_ImplRedGpuH_Frame* fd);
void ImGui_ImplRedGpuH_DestroyFrameSemaphores(RedContext instance, uint32_t deviceIndex, RedHandleGpu device, ImGui_ImplRedGpuH_FrameSemaphores* fsd);
void ImGui_ImplRedGpuH_DestroyFrameRenderBuffers(RedContext instance, uint32_t deviceIndex, RedHandleGpu device, ImGui_ImplRedGpuH_FrameRenderBuffers* buffers);
void ImGui_ImplRedGpuH_DestroyWindowRenderBuffers(RedContext instance, uint32_t deviceIndex, RedHandleGpu device, ImGui_ImplRedGpuH_WindowRenderBuffers* buffers);
void ImGui_ImplRedGpuH_CreateWindowSwapChain(RedContext instance, uint32_t deviceIndex, RedHandleGpuDevice physical_device, RedHandleGpu device, RedHandleQueue present_queue, ImGui_ImplRedGpuH_Window* wd, int w, int h, uint32_t min_image_count, void * windowHandle, int screenW, int screenH);
void ImGui_ImplRedGpuH_CreateWindowCommandBuffers(RedContext instance, uint32_t deviceIndex, RedHandleGpuDevice physical_device, RedHandleGpu device, ImGui_ImplRedGpuH_Window* wd, uint32_t queue_family);

//-----------------------------------------------------------------------------
// SHADERS
//-----------------------------------------------------------------------------

// https://github.com/gpuweb/gpuweb/issues/901

/*
// dxc.exe hlsl_shader.vs -T vs_6_0 -Fh hlsl_shader.vs.h
// dxc.exe hlsl_shader.vs -T vs_6_0 -Fh hlsl_shader.vs.h -spirv

struct RootSignatureConstants {
  float2 scale;
  float2 translate;
  int2   offsets;
};
[[vk::push_constant]] ConstantBuffer<RootSignatureConstants> variables: register(b0, space3);

[[vk::binding(2, 1)]] ByteAddressBuffer imdrawverts: register(t0, space2);

float4 ColorConvertU32ToFloat4(uint v) {
  const float s = 1.0f / 255.0f;
  uint4 c = uint4(v & 0xff, (v >> 8) & 0xff, (v >> 16) & 0xff, v >> 24);
  return float4(c) * s;
}

struct interpolated {
  float4 pos: SV_Position;
  float4 col: Color;
  float2 uv: Uv;
};

interpolated main(uint vid: SV_VertexID, uint iid: SV_InstanceID) {
  float2 pos;
  float2 uv;
  uint   col;
  pos.x = asfloat(imdrawverts.Load((variables.offsets.y * 5 * 4) + ((vid * 5 + 0) * 4)));
  pos.y = asfloat(imdrawverts.Load((variables.offsets.y * 5 * 4) + ((vid * 5 + 1) * 4)));
  uv.x  = asfloat(imdrawverts.Load((variables.offsets.y * 5 * 4) + ((vid * 5 + 2) * 4)));
  uv.y  = asfloat(imdrawverts.Load((variables.offsets.y * 5 * 4) + ((vid * 5 + 3) * 4)));
  col   =         imdrawverts.Load((variables.offsets.y * 5 * 4) + ((vid * 5 + 4) * 4));
  interpolated output;
  output.pos = float4(pos * variables.scale + variables.translate, 0, 1);
  output.pos.y *= -1.0f;
  output.col = ColorConvertU32ToFloat4(col);
  output.uv  = uv;
  return output;
}
*/
#ifdef REDGPU_USE_REDGPU_X
static unsigned char __hlsl_shader_vs_spv[] = {
  0x44, 0x58, 0x42, 0x43, 0xd3, 0xf4, 0x33, 0x13, 0x4f, 0xc8, 0x93, 0xdb,
  0x7f, 0x52, 0x16, 0x27, 0xfb, 0xea, 0x2a, 0xd0, 0x01, 0x00, 0x00, 0x00,
  0x03, 0x12, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00,
  0x4c, 0x00, 0x00, 0x00, 0xb6, 0x00, 0x00, 0x00, 0x3b, 0x01, 0x00, 0x00,
  0x1f, 0x02, 0x00, 0x00, 0xc7, 0x09, 0x00, 0x00, 0xe3, 0x09, 0x00, 0x00,
  0x53, 0x46, 0x49, 0x30, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x31, 0x62, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x53, 0x56, 0x5f, 0x56, 0x65, 0x72, 0x74, 0x65, 0x78, 0x49, 0x44, 0x00,
  0x53, 0x56, 0x5f, 0x49, 0x6e, 0x73, 0x74, 0x61, 0x6e, 0x63, 0x65, 0x49,
  0x44, 0x00, 0x4f, 0x53, 0x47, 0x31, 0x7d, 0x00, 0x00, 0x00, 0x03, 0x00,
  0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x7a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x0c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x6f, 0x73,
  0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00,
  0x55, 0x76, 0x00, 0x50, 0x53, 0x56, 0x30, 0xdc, 0x00, 0x00, 0x00, 0x24,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
  0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x02, 0x03, 0x00, 0x02, 0x03,
  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00,
  0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x55, 0x76, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x41, 0x01, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x41, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x44, 0x03, 0x03, 0x04, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x44, 0x00, 0x03,
  0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x02, 0x42, 0x00, 0x03, 0x02, 0x00, 0x00, 0xf3, 0x03, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x53, 0x54, 0x41, 0x54, 0xa0, 0x07, 0x00, 0x00, 0x60,
  0x00, 0x01, 0x00, 0xe8, 0x01, 0x00, 0x00, 0x44, 0x58, 0x49, 0x4c, 0x00,
  0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x88, 0x07, 0x00, 0x00, 0x42,
  0x43, 0xc0, 0xde, 0x21, 0x0c, 0x00, 0x00, 0xdf, 0x01, 0x00, 0x00, 0x0b,
  0x82, 0x20, 0x00, 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x07,
  0x81, 0x23, 0x91, 0x41, 0xc8, 0x04, 0x49, 0x06, 0x10, 0x32, 0x39, 0x92,
  0x01, 0x84, 0x0c, 0x25, 0x05, 0x08, 0x19, 0x1e, 0x04, 0x8b, 0x62, 0x80,
  0x18, 0x45, 0x02, 0x42, 0x92, 0x0b, 0x42, 0xc4, 0x10, 0x32, 0x14, 0x38,
  0x08, 0x18, 0x4b, 0x0a, 0x32, 0x62, 0x88, 0x48, 0x90, 0x14, 0x20, 0x43,
  0x46, 0x88, 0xa5, 0x00, 0x19, 0x32, 0x42, 0xe4, 0x48, 0x0e, 0x90, 0x11,
  0x23, 0xc4, 0x50, 0x41, 0x51, 0x81, 0x8c, 0xe1, 0x83, 0xe5, 0x8a, 0x04,
  0x31, 0x46, 0x06, 0x51, 0x18, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x1b,
  0x8c, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x07, 0x40, 0x02, 0xa8, 0x0d, 0x84,
  0xf0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x20, 0x6d, 0x30, 0x86, 0xff, 0xff,
  0xff, 0xff, 0x1f, 0x00, 0x09, 0xa8, 0x00, 0x49, 0x18, 0x00, 0x00, 0x03,
  0x00, 0x00, 0x00, 0x13, 0x82, 0x60, 0x42, 0x20, 0x4c, 0x08, 0x06, 0x00,
  0x00, 0x00, 0x00, 0x89, 0x20, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x32,
  0x22, 0x88, 0x09, 0x20, 0x64, 0x85, 0x04, 0x13, 0x23, 0xa4, 0x84, 0x04,
  0x13, 0x23, 0xe3, 0x84, 0xa1, 0x90, 0x14, 0x12, 0x4c, 0x8c, 0x8c, 0x0b,
  0x84, 0xc4, 0x4c, 0x10, 0x90, 0xc1, 0x1c, 0x01, 0x18, 0x1c, 0x26, 0x4d,
  0x11, 0x25, 0x4c, 0xfe, 0x86, 0x4d, 0x84, 0x36, 0x0c, 0x11, 0x21, 0x49,
  0x1b, 0x55, 0x14, 0x44, 0x84, 0x02, 0x80, 0x82, 0x19, 0x80, 0x61, 0x04,
  0x61, 0x18, 0x46, 0x10, 0x80, 0xeb, 0xa4, 0x29, 0xa2, 0x84, 0xc9, 0x5f,
  0x1d, 0x67, 0x62, 0x11, 0xa3, 0x01, 0x26, 0x2a, 0x22, 0x38, 0xa7, 0x91,
  0x26, 0xa0, 0x99, 0x24, 0x34, 0x10, 0x44, 0x71, 0x49, 0x05, 0x44, 0x08,
  0x10, 0x2c, 0x84, 0x84, 0x02, 0x83, 0x8e, 0x11, 0x80, 0x12, 0x24, 0xa4,
  0xcc, 0x11, 0x20, 0xc5, 0x00, 0x00, 0x00, 0x60, 0x00, 0x6a, 0x8a, 0x91,
  0x00, 0x00, 0xc0, 0x0c, 0xf4, 0x1c, 0x35, 0x5c, 0xfe, 0x84, 0x3d, 0x84,
  0xe4, 0x73, 0x1b, 0x55, 0xac, 0xc4, 0xe4, 0x17, 0xb7, 0x8d, 0x88, 0x61,
  0x18, 0x06, 0x62, 0xee, 0x19, 0x2e, 0x7f, 0xc2, 0x1e, 0x42, 0xf2, 0x43,
  0xa0, 0x19, 0x16, 0x02, 0x05, 0x52, 0x21, 0x22, 0x60, 0x02, 0x88, 0x3a,
  0x6a, 0xb8, 0xfc, 0x09, 0x7b, 0x08, 0xc9, 0xe7, 0x36, 0xaa, 0x58, 0x89,
  0xc9, 0x47, 0x6e, 0x1b, 0x11, 0x00, 0x00, 0x00, 0x85, 0xb0, 0x80, 0x09,
  0xa0, 0x6b, 0x8e, 0x20, 0x28, 0xc6, 0x04, 0x30, 0x00, 0x90, 0x91, 0x76,
  0xd3, 0x70, 0xf9, 0x13, 0xf6, 0x10, 0x92, 0xbf, 0x12, 0xd2, 0x4a, 0x4c,
  0x3e, 0x72, 0xdb, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x4a, 0xc1, 0x01, 0x13,
  0x00, 0x50, 0x37, 0x10, 0x30, 0x8c, 0x40, 0x0c, 0x37, 0x49, 0x53, 0x44,
  0x09, 0x93, 0x8f, 0x34, 0x13, 0x11, 0x3d, 0xce, 0x02, 0x4c, 0xc4, 0x80,
  0x06, 0x10, 0x24, 0xf2, 0x00, 0x98, 0x23, 0x00, 0x05, 0x00, 0x00, 0x13,
  0x14, 0x72, 0xc0, 0x87, 0x74, 0x60, 0x87, 0x36, 0x68, 0x87, 0x79, 0x68,
  0x03, 0x72, 0xc0, 0x87, 0x0d, 0xaf, 0x50, 0x0e, 0x6d, 0xd0, 0x0e, 0x7a,
  0x50, 0x0e, 0x6d, 0x00, 0x0f, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x73,
  0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d,
  0x90, 0x0e, 0x78, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71,
  0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe9, 0x30, 0x07, 0x72,
  0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x76, 0x40, 0x07, 0x7a,
  0x60, 0x07, 0x74, 0xd0, 0x06, 0xe6, 0x10, 0x07, 0x76, 0xa0, 0x07, 0x73,
  0x20, 0x07, 0x6d, 0x60, 0x0e, 0x73, 0x20, 0x07, 0x7a, 0x30, 0x07, 0x72,
  0xd0, 0x06, 0xe6, 0x60, 0x07, 0x74, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x6d,
  0xe0, 0x0e, 0x78, 0xa0, 0x07, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72,
  0xa0, 0x07, 0x76, 0x40, 0x07, 0x3a, 0x0f, 0x64, 0x90, 0x21, 0x23, 0x45,
  0x44, 0x00, 0x66, 0x00, 0xc0, 0xfc, 0x00, 0x00, 0x86, 0x3c, 0x0a, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x79, 0x1a,
  0x20, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xf2,
  0x3c, 0x40, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
  0xe4, 0xa1, 0x80, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x60, 0xc8, 0x73, 0x01, 0x01, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xc0, 0x90, 0x47, 0x03, 0x02, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x80, 0x21, 0x4f, 0x07, 0x04, 0xc0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x59, 0x20, 0x00, 0x15, 0x00, 0x00, 0x00, 0x32,
  0x1e, 0x98, 0x18, 0x19, 0x11, 0x4c, 0x90, 0x8c, 0x09, 0x26, 0x47, 0xc6,
  0x04, 0x43, 0x02, 0x4a, 0x60, 0x04, 0xa0, 0x18, 0x8a, 0xa0, 0x2c, 0xca,
  0xa0, 0x60, 0xca, 0xa1, 0x24, 0x0a, 0xa2, 0x40, 0x0a, 0xa1, 0xa0, 0x0a,
  0xa8, 0x3c, 0x68, 0x2c, 0x10, 0x62, 0x0a, 0xa1, 0x0c, 0x4a, 0xa2, 0x08,
  0x4a, 0xa1, 0x04, 0x46, 0x00, 0x08, 0x99, 0x01, 0xa0, 0x63, 0x06, 0x80,
  0x8c, 0x19, 0x00, 0x12, 0x66, 0x00, 0x28, 0x9c, 0x01, 0x20, 0x71, 0xac,
  0xa3, 0x50, 0xe6, 0x0f, 0x00, 0x00, 0x80, 0x82, 0x19, 0x00, 0x00, 0x79,
  0x18, 0x00, 0x00, 0xa6, 0x00, 0x00, 0x00, 0x1a, 0x03, 0x4c, 0x90, 0x46,
  0x02, 0x13, 0xc4, 0x83, 0x0c, 0x6f, 0x0c, 0x24, 0xc6, 0x45, 0x66, 0x43,
  0x10, 0x4c, 0x10, 0x80, 0x64, 0x82, 0x00, 0x28, 0x1b, 0x84, 0x81, 0xd8,
  0x20, 0x10, 0x04, 0x05, 0xbb, 0xb9, 0x09, 0x02, 0xb0, 0x6c, 0x18, 0x0e,
  0x84, 0x98, 0x20, 0x08, 0x63, 0xc0, 0x25, 0xad, 0x8d, 0x4c, 0x2e, 0xec,
  0xce, 0xae, 0x4c, 0x8e, 0x6e, 0x6e, 0x82, 0x00, 0x30, 0x13, 0x04, 0xa0,
  0xd9, 0x90, 0x10, 0xca, 0xc2, 0x10, 0x43, 0x43, 0x00, 0x1b, 0x02, 0x67,
  0x82, 0x80, 0x80, 0x01, 0x13, 0xbb, 0x30, 0xb9, 0xb4, 0x30, 0x31, 0xb6,
  0xb2, 0xb9, 0x09, 0x02, 0xe0, 0x4c, 0x10, 0x80, 0x67, 0x03, 0x42, 0x40,
  0x91, 0x44, 0x0c, 0x13, 0xb0, 0x21, 0xa0, 0x36, 0x10, 0x0f, 0x50, 0x01,
  0x13, 0x04, 0x43, 0x0c, 0x58, 0xcc, 0x8d, 0x85, 0xb1, 0x95, 0x4d, 0x10,
  0x00, 0x68, 0x82, 0x00, 0x44, 0x1b, 0x0c, 0x04, 0x93, 0x88, 0x4c, 0x63,
  0x42, 0x27, 0x17, 0xe6, 0x36, 0xc7, 0x16, 0x46, 0x57, 0x36, 0x41, 0x00,
  0xa4, 0x0d, 0x06, 0xc2, 0x49, 0x5d, 0xa6, 0xf1, 0x78, 0x33, 0x33, 0x9b,
  0x2b, 0xa3, 0x9b, 0x9b, 0x20, 0x00, 0xd3, 0x04, 0x01, 0xa0, 0x36, 0x18,
  0xc8, 0x27, 0x81, 0x41, 0x16, 0x06, 0x1b, 0x88, 0x69, 0xf3, 0xc4, 0x60,
  0x82, 0x10, 0x98, 0x01, 0x03, 0xb4, 0x0d, 0x06, 0x52, 0x06, 0x12, 0x91,
  0x85, 0xc1, 0x06, 0x21, 0x0c, 0xcc, 0x60, 0x82, 0x10, 0x06, 0x64, 0x30,
  0x41, 0x00, 0x2a, 0x0e, 0x70, 0x6f, 0x73, 0x5c, 0xa6, 0xac, 0xbe, 0xa0,
  0xde, 0xe6, 0xd2, 0xe8, 0xd2, 0xde, 0xdc, 0x36, 0x20, 0x88, 0x1a, 0x48,
  0x44, 0x18, 0xac, 0x41, 0xa6, 0x71, 0x18, 0x7b, 0x63, 0x63, 0x31, 0xf4,
  0xc6, 0xf6, 0x26, 0xb7, 0x01, 0x41, 0xda, 0x40, 0x02, 0x83, 0x30, 0x70,
  0x83, 0x4c, 0xa3, 0x50, 0x67, 0x37, 0x41, 0x00, 0x2c, 0x0a, 0x55, 0x76,
  0x1b, 0x10, 0x04, 0x0e, 0xa4, 0x38, 0x08, 0x03, 0x39, 0xc8, 0xb4, 0x0d,
  0x44, 0x1a, 0xb0, 0xc1, 0x1b, 0xcc, 0xc1, 0x04, 0xe1, 0x08, 0x83, 0x0d,
  0x04, 0x12, 0x49, 0xc4, 0x06, 0x61, 0xb2, 0x83, 0x0d, 0x09, 0x71, 0x8d,
  0x01, 0x19, 0x9c, 0x01, 0x1a, 0xd0, 0x41, 0x1d, 0xdc, 0xc1, 0x04, 0x61,
  0x11, 0x36, 0x00, 0x1b, 0x06, 0x42, 0x0f, 0xf4, 0x60, 0x43, 0xb0, 0x07,
  0x1b, 0x86, 0x21, 0x0f, 0xf8, 0x60, 0x82, 0x20, 0x06, 0x65, 0xb0, 0x21,
  0xf0, 0x03, 0x12, 0x6d, 0x61, 0x69, 0x6e, 0x5c, 0xa6, 0xac, 0xbe, 0xac,
  0xca, 0xe4, 0xe8, 0xca, 0xf0, 0x92, 0x88, 0x26, 0x08, 0x4c, 0x37, 0x41,
  0x60, 0xbc, 0x0d, 0x01, 0x31, 0x41, 0x60, 0xbe, 0x0d, 0x82, 0x34, 0x6c,
  0x58, 0x88, 0x50, 0x10, 0x85, 0x51, 0x20, 0x85, 0x52, 0x18, 0x46, 0x81,
  0x28, 0x05, 0x53, 0x60, 0x33, 0x65, 0xf5, 0x95, 0xe4, 0x36, 0x47, 0x17,
  0xe6, 0x36, 0x56, 0x96, 0x44, 0x34, 0x41, 0x60, 0xb8, 0x0d, 0xcb, 0x80,
  0x0a, 0xa2, 0x90, 0x0a, 0xa4, 0x50, 0x0a, 0xc3, 0x28, 0x0c, 0xa5, 0x00,
  0x6c, 0x10, 0x4e, 0x41, 0x15, 0x26, 0x08, 0xcc, 0x36, 0x41, 0x60, 0xb4,
  0x09, 0x02, 0x93, 0x4d, 0x10, 0x80, 0x6b, 0x83, 0x20, 0xbd, 0xc2, 0x86,
  0x85, 0x58, 0x03, 0x56, 0x68, 0x05, 0x52, 0x70, 0x85, 0xc1, 0x15, 0x88,
  0x52, 0x80, 0x85, 0x0d, 0xcb, 0xe0, 0x06, 0xac, 0x50, 0x0a, 0xa4, 0x90,
  0x0a, 0x83, 0x2b, 0x0c, 0xa5, 0x00, 0x0b, 0x1b, 0x04, 0x49, 0xda, 0xb0,
  0x30, 0x72, 0xc0, 0x0a, 0xa5, 0x40, 0x0a, 0xa9, 0x30, 0xa4, 0x02, 0x53,
  0x0a, 0xb3, 0xb0, 0x61, 0x88, 0x05, 0x59, 0xa0, 0x85, 0x0d, 0xc3, 0x2a,
  0xd4, 0x02, 0x30, 0x41, 0x18, 0x03, 0x6c, 0x83, 0x40, 0xdc, 0xc2, 0x86,
  0x22, 0x0f, 0x40, 0xc1, 0x16, 0x2c, 0x5c, 0xa8, 0xc2, 0xc6, 0x66, 0xd7,
  0xe6, 0x92, 0x46, 0x56, 0xe6, 0x46, 0x37, 0x25, 0x08, 0xaa, 0x90, 0xe1,
  0xb9, 0xd8, 0x95, 0xc9, 0xcd, 0xa5, 0xbd, 0xb9, 0x4d, 0x09, 0x88, 0x26,
  0x64, 0x78, 0x2e, 0x76, 0x61, 0x6c, 0x76, 0x65, 0x72, 0x53, 0x82, 0xa2,
  0x0e, 0x19, 0x9e, 0xcb, 0x1c, 0x5a, 0x18, 0x59, 0x99, 0x5c, 0xd3, 0x1b,
  0x59, 0x19, 0xdb, 0x94, 0x00, 0x29, 0x43, 0x86, 0xe7, 0x22, 0x57, 0x36,
  0xf7, 0x56, 0x27, 0x37, 0x56, 0x36, 0x37, 0x25, 0xa8, 0x2a, 0x91, 0xe1,
  0xb9, 0xd0, 0xe5, 0xc1, 0x95, 0x05, 0xb9, 0xb9, 0xbd, 0xd1, 0x85, 0xd1,
  0xa5, 0xbd, 0xb9, 0xcd, 0x4d, 0x11, 0xee, 0x80, 0x0f, 0xea, 0x90, 0xe1,
  0xb9, 0xd8, 0xa5, 0x95, 0xdd, 0x25, 0x91, 0x4d, 0xd1, 0x85, 0xd1, 0x95,
  0x4d, 0x09, 0xfc, 0xa0, 0x0e, 0x19, 0x9e, 0x4b, 0x99, 0x1b, 0x9d, 0x5c,
  0x1e, 0xd4, 0x5b, 0x9a, 0x1b, 0xdd, 0xdc, 0x94, 0x00, 0x17, 0x00, 0x79,
  0x18, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x33, 0x08, 0x80, 0x1c, 0xc4,
  0xe1, 0x1c, 0x66, 0x14, 0x01, 0x3d, 0x88, 0x43, 0x38, 0x84, 0xc3, 0x8c,
  0x42, 0x80, 0x07, 0x79, 0x78, 0x07, 0x73, 0x98, 0x71, 0x0c, 0xe6, 0x00,
  0x0f, 0xed, 0x10, 0x0e, 0xf4, 0x80, 0x0e, 0x33, 0x0c, 0x42, 0x1e, 0xc2,
  0xc1, 0x1d, 0xce, 0xa1, 0x1c, 0x66, 0x30, 0x05, 0x3d, 0x88, 0x43, 0x38,
  0x84, 0x83, 0x1b, 0xcc, 0x03, 0x3d, 0xc8, 0x43, 0x3d, 0x8c, 0x03, 0x3d,
  0xcc, 0x78, 0x8c, 0x74, 0x70, 0x07, 0x7b, 0x08, 0x07, 0x79, 0x48, 0x87,
  0x70, 0x70, 0x07, 0x7a, 0x70, 0x03, 0x76, 0x78, 0x87, 0x70, 0x20, 0x87,
  0x19, 0xcc, 0x11, 0x0e, 0xec, 0x90, 0x0e, 0xe1, 0x30, 0x0f, 0x6e, 0x30,
  0x0f, 0xe3, 0xf0, 0x0e, 0xf0, 0x50, 0x0e, 0x33, 0x10, 0xc4, 0x1d, 0xde,
  0x21, 0x1c, 0xd8, 0x21, 0x1d, 0xc2, 0x61, 0x1e, 0x66, 0x30, 0x89, 0x3b,
  0xbc, 0x83, 0x3b, 0xd0, 0x43, 0x39, 0xb4, 0x03, 0x3c, 0xbc, 0x83, 0x3c,
  0x84, 0x03, 0x3b, 0xcc, 0xf0, 0x14, 0x76, 0x60, 0x07, 0x7b, 0x68, 0x07,
  0x37, 0x68, 0x87, 0x72, 0x68, 0x07, 0x37, 0x80, 0x87, 0x70, 0x90, 0x87,
  0x70, 0x60, 0x07, 0x76, 0x28, 0x07, 0x76, 0xf8, 0x05, 0x76, 0x78, 0x87,
  0x77, 0x80, 0x87, 0x5f, 0x08, 0x87, 0x71, 0x18, 0x87, 0x72, 0x98, 0x87,
  0x79, 0x98, 0x81, 0x2c, 0xee, 0xf0, 0x0e, 0xee, 0xe0, 0x0e, 0xf5, 0xc0,
  0x0e, 0xec, 0x30, 0x03, 0x62, 0xc8, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xcc,
  0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xdc, 0x61, 0x1c, 0xca, 0x21, 0x1c, 0xc4,
  0x81, 0x1d, 0xca, 0x61, 0x06, 0xd6, 0x90, 0x43, 0x39, 0xc8, 0x43, 0x39,
  0x98, 0x43, 0x39, 0xc8, 0x43, 0x39, 0xb8, 0xc3, 0x38, 0x94, 0x43, 0x38,
  0x88, 0x03, 0x3b, 0x94, 0xc3, 0x2f, 0xbc, 0x83, 0x3c, 0xfc, 0x82, 0x3b,
  0xd4, 0x03, 0x3b, 0xb0, 0xc3, 0x8c, 0xcc, 0x21, 0x07, 0x7c, 0x70, 0x03,
  0x74, 0x60, 0x07, 0x37, 0x90, 0x87, 0x72, 0x98, 0x87, 0x77, 0xa8, 0x07,
  0x79, 0x18, 0x87, 0x72, 0x70, 0x83, 0x70, 0xa0, 0x07, 0x7a, 0x90, 0x87,
  0x74, 0x10, 0x87, 0x7a, 0xa0, 0x87, 0x72, 0x00, 0x00, 0x00, 0x00, 0x71,
  0x20, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0x05, 0x50, 0x06, 0x81, 0x5f,
  0xba, 0x4d, 0x96, 0x87, 0xef, 0xf6, 0xb2, 0x9c, 0x3e, 0x07, 0x02, 0x67,
  0x55, 0x61, 0x9e, 0x5e, 0x0e, 0x92, 0xc9, 0xf2, 0xf2, 0x7c, 0x2e, 0xac,
  0x9b, 0xcd, 0x65, 0x39, 0x10, 0x18, 0x34, 0x04, 0x6a, 0xb8, 0x7c, 0xe7,
  0xf1, 0x03, 0xaa, 0x28, 0x88, 0xa8, 0x74, 0x80, 0xc1, 0x47, 0x6e, 0xdb,
  0x0a, 0xb6, 0xe1, 0xf2, 0x9d, 0xc7, 0x17, 0x02, 0xaa, 0x28, 0x88, 0xa8,
  0x74, 0x80, 0xa1, 0x24, 0x0c, 0x40, 0xc0, 0xfc, 0xe2, 0xb6, 0xcd, 0x60,
  0x1b, 0x2e, 0xdf, 0x79, 0x7c, 0x21, 0xa0, 0x8a, 0x82, 0x88, 0x4a, 0x07,
  0x18, 0x4a, 0xc2, 0x00, 0x04, 0xcc, 0x47, 0x6e, 0xdb, 0x0e, 0xa4, 0xe1,
  0xf2, 0x9d, 0xc7, 0x17, 0x22, 0x02, 0x98, 0x88, 0x10, 0x68, 0x86, 0x85,
  0xb0, 0x81, 0x69, 0xb8, 0x7c, 0xe7, 0xf1, 0x17, 0x07, 0x18, 0xc4, 0xe6,
  0xa1, 0x26, 0x1f, 0xb9, 0x6d, 0x23, 0xa8, 0x86, 0xcb, 0x77, 0x1e, 0x5f,
  0x9a, 0x9c, 0x88, 0x40, 0xa9, 0xe9, 0xa1, 0x26, 0xbf, 0xb8, 0x6d, 0x13,
  0x20, 0x18, 0x00, 0x69, 0x2c, 0x20, 0xa9, 0x80, 0x08, 0x01, 0x82, 0x85,
  0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x41, 0x53, 0x48, 0x14,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x2a, 0x3e, 0xb0, 0x38,
  0x84, 0xcc, 0xa2, 0x59, 0xd8, 0x92, 0x45, 0xe2, 0x35, 0x2b, 0xec, 0x44,
  0x58, 0x49, 0x4c, 0x18, 0x08, 0x00, 0x00, 0x60, 0x00, 0x01, 0x00, 0x06,
  0x02, 0x00, 0x00, 0x44, 0x58, 0x49, 0x4c, 0x00, 0x01, 0x00, 0x00, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x42, 0x43, 0xc0, 0xde, 0x21,
  0x0c, 0x00, 0x00, 0xfd, 0x01, 0x00, 0x00, 0x0b, 0x82, 0x20, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x07, 0x81, 0x23, 0x91, 0x41,
  0xc8, 0x04, 0x49, 0x06, 0x10, 0x32, 0x39, 0x92, 0x01, 0x84, 0x0c, 0x25,
  0x05, 0x08, 0x19, 0x1e, 0x04, 0x8b, 0x62, 0x80, 0x18, 0x45, 0x02, 0x42,
  0x92, 0x0b, 0x42, 0xc4, 0x10, 0x32, 0x14, 0x38, 0x08, 0x18, 0x4b, 0x0a,
  0x32, 0x62, 0x88, 0x48, 0x90, 0x14, 0x20, 0x43, 0x46, 0x88, 0xa5, 0x00,
  0x19, 0x32, 0x42, 0xe4, 0x48, 0x0e, 0x90, 0x11, 0x23, 0xc4, 0x50, 0x41,
  0x51, 0x81, 0x8c, 0xe1, 0x83, 0xe5, 0x8a, 0x04, 0x31, 0x46, 0x06, 0x51,
  0x18, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x1b, 0x8c, 0xe0, 0xff, 0xff,
  0xff, 0xff, 0x07, 0x40, 0x02, 0xa8, 0x0d, 0x84, 0xf0, 0xff, 0xff, 0xff,
  0xff, 0x03, 0x20, 0x6d, 0x30, 0x86, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00,
  0x09, 0xa8, 0x00, 0x49, 0x18, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x13,
  0x82, 0x60, 0x42, 0x20, 0x4c, 0x08, 0x06, 0x00, 0x00, 0x00, 0x00, 0x89,
  0x20, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x32, 0x22, 0x88, 0x09, 0x20,
  0x64, 0x85, 0x04, 0x13, 0x23, 0xa4, 0x84, 0x04, 0x13, 0x23, 0xe3, 0x84,
  0xa1, 0x90, 0x14, 0x12, 0x4c, 0x8c, 0x8c, 0x0b, 0x84, 0xc4, 0x4c, 0x10,
  0x88, 0xc1, 0x08, 0x40, 0x09, 0x00, 0x0a, 0xe6, 0x08, 0xc0, 0x60, 0x8e,
  0x00, 0x29, 0xc6, 0x30, 0x0c, 0x03, 0x31, 0x50, 0x31, 0x03, 0x50, 0x0c,
  0x60, 0x18, 0x06, 0xe2, 0x20, 0xe4, 0xa8, 0xe1, 0xf2, 0x27, 0xec, 0x21,
  0x24, 0x9f, 0xdb, 0xa8, 0x62, 0x25, 0x26, 0xbf, 0xb8, 0x6d, 0x44, 0x1c,
  0xc7, 0x71, 0x10, 0x71, 0xcf, 0x70, 0xf9, 0x13, 0xf6, 0x10, 0x92, 0x1f,
  0x02, 0xcd, 0xb0, 0x10, 0x28, 0x58, 0x0a, 0xa1, 0x0c, 0xcc, 0x40, 0xcd,
  0x51, 0xc3, 0xe5, 0x4f, 0xd8, 0x43, 0x48, 0x3e, 0xb7, 0x51, 0xc5, 0x4a,
  0x4c, 0x3e, 0x72, 0xdb, 0x88, 0x18, 0x86, 0x61, 0x28, 0xc4, 0x33, 0x30,
  0x03, 0x41, 0x73, 0x04, 0x41, 0x31, 0x98, 0x81, 0x18, 0x06, 0x89, 0xa6,
  0x9b, 0x86, 0xcb, 0x9f, 0xb0, 0x87, 0x90, 0xfc, 0x95, 0x90, 0x56, 0x62,
  0xf2, 0x91, 0xdb, 0x46, 0xc5, 0x30, 0x0c, 0xc3, 0x50, 0x8a, 0x6a, 0x60,
  0x86, 0x81, 0xac, 0x81, 0x80, 0xc3, 0xa4, 0x29, 0xa2, 0x84, 0xc9, 0xdf,
  0xb0, 0x89, 0xd0, 0x86, 0x21, 0x22, 0x24, 0x69, 0xa3, 0x8a, 0x82, 0x88,
  0x50, 0x30, 0x50, 0x36, 0x8c, 0x20, 0x1c, 0xc3, 0x08, 0xc2, 0x70, 0x9d,
  0x34, 0x45, 0x94, 0x30, 0xf9, 0xab, 0xe3, 0x4c, 0x2c, 0x62, 0x34, 0xc0,
  0x44, 0x45, 0x04, 0xe7, 0x34, 0xd2, 0x04, 0x34, 0x93, 0x84, 0x86, 0x6d,
  0xe3, 0x2e, 0xa9, 0x80, 0x08, 0x01, 0x82, 0x85, 0x90, 0x50, 0xd0, 0x91,
  0x97, 0x07, 0xc3, 0x1c, 0x01, 0x28, 0x00, 0x13, 0x14, 0x72, 0xc0, 0x87,
  0x74, 0x60, 0x87, 0x36, 0x68, 0x87, 0x79, 0x68, 0x03, 0x72, 0xc0, 0x87,
  0x0d, 0xaf, 0x50, 0x0e, 0x6d, 0xd0, 0x0e, 0x7a, 0x50, 0x0e, 0x6d, 0x00,
  0x0f, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90,
  0x0e, 0x71, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x78, 0xa0,
  0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0x60, 0x07, 0x7a, 0x30,
  0x07, 0x72, 0xd0, 0x06, 0xe9, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x73, 0x20,
  0x07, 0x6d, 0x90, 0x0e, 0x76, 0x40, 0x07, 0x7a, 0x60, 0x07, 0x74, 0xd0,
  0x06, 0xe6, 0x10, 0x07, 0x76, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x60,
  0x0e, 0x73, 0x20, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe6, 0x60,
  0x07, 0x74, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x6d, 0xe0, 0x0e, 0x78, 0xa0,
  0x07, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x76, 0x40,
  0x07, 0x43, 0x9e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x86, 0x3c, 0x05, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0c, 0x79, 0x10, 0x20, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x18, 0xf2, 0x34, 0x40, 0x00, 0x0c, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xe4, 0x81, 0x80, 0x00, 0x18, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xc8, 0x33, 0x01, 0x01, 0x30,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x90, 0xc7, 0x02, 0x02,
  0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x2c, 0x10, 0x10,
  0x00, 0x00, 0x00, 0x32, 0x1e, 0x98, 0x14, 0x19, 0x11, 0x4c, 0x90, 0x8c,
  0x09, 0x26, 0x47, 0xc6, 0x04, 0x43, 0x1a, 0x4a, 0x60, 0x04, 0xa0, 0x14,
  0x8a, 0xa1, 0x08, 0xca, 0xa2, 0x0c, 0x0a, 0xa6, 0x3c, 0x88, 0x28, 0x85,
  0x12, 0x18, 0x01, 0x28, 0x82, 0x92, 0x28, 0x83, 0x42, 0xa0, 0xb0, 0x40,
  0xe8, 0x9b, 0x01, 0x20, 0x70, 0xac, 0xa3, 0x50, 0xe6, 0x0f, 0x00, 0x00,
  0x80, 0xb4, 0x19, 0x00, 0x00, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00, 0x66,
  0x00, 0x00, 0x00, 0x1a, 0x03, 0x4c, 0x90, 0x46, 0x02, 0x13, 0xc4, 0x83,
  0x0c, 0x6f, 0x0c, 0x24, 0xc6, 0x45, 0x66, 0x43, 0x10, 0x4c, 0x10, 0x86,
  0x63, 0x82, 0x30, 0x20, 0x1b, 0x84, 0x81, 0x98, 0x20, 0x0c, 0xc9, 0x06,
  0x61, 0x30, 0x28, 0xd8, 0xcd, 0x4d, 0x10, 0x06, 0x65, 0xc3, 0x80, 0x24,
  0xc4, 0x04, 0x41, 0xd3, 0x08, 0x4c, 0x10, 0x86, 0x65, 0x82, 0x30, 0x30,
  0x1b, 0x12, 0x62, 0x61, 0x1a, 0x62, 0x70, 0x08, 0x60, 0x43, 0xf0, 0x4c,
  0x10, 0x3e, 0x6c, 0x82, 0x30, 0x34, 0x13, 0x84, 0xc1, 0xd9, 0x80, 0x10,
  0x11, 0x23, 0x11, 0xc3, 0x04, 0x6c, 0x08, 0xa8, 0x0d, 0x04, 0x04, 0x54,
  0xc0, 0x04, 0x01, 0x0c, 0xb2, 0x0d, 0xc1, 0x35, 0x41, 0x10, 0x00, 0x12,
  0x6d, 0x61, 0x69, 0x6e, 0x5c, 0xa6, 0xac, 0xbe, 0xac, 0xca, 0xe4, 0xe8,
  0xca, 0xf0, 0x92, 0x88, 0x26, 0x08, 0x04, 0x34, 0x41, 0x20, 0xa2, 0x0d,
  0x01, 0x31, 0x41, 0x20, 0xa4, 0x0d, 0x82, 0x34, 0x6c, 0x58, 0x88, 0x8d,
  0xeb, 0xbc, 0x6f, 0xe8, 0x88, 0x0f, 0x0c, 0xd8, 0x4c, 0x59, 0x7d, 0x25,
  0xb9, 0xcd, 0xd1, 0x85, 0xb9, 0x8d, 0x95, 0x25, 0x11, 0x4d, 0x10, 0x88,
  0x69, 0xc3, 0x32, 0x88, 0x01, 0x37, 0x06, 0xde, 0x37, 0x74, 0xc3, 0x07,
  0x6c, 0x10, 0xc2, 0x80, 0x0c, 0xb8, 0x4c, 0x59, 0x7d, 0x41, 0xbd, 0xcd,
  0xa5, 0xd1, 0xa5, 0xbd, 0xb9, 0x4d, 0x10, 0x08, 0x6a, 0x82, 0x40, 0x54,
  0x13, 0x04, 0xc2, 0x9a, 0x20, 0x0c, 0xcf, 0x06, 0x41, 0x52, 0x83, 0x0d,
  0x0b, 0x61, 0x06, 0x67, 0x80, 0x06, 0x5e, 0x1a, 0x0c, 0x69, 0x40, 0x7c,
  0x6b, 0xc0, 0x62, 0xe8, 0x8d, 0xed, 0x4d, 0x6e, 0xc3, 0x32, 0xb4, 0xc1,
  0x19, 0x7c, 0xde, 0x18, 0x0c, 0x69, 0x30, 0x7c, 0x6b, 0x40, 0xa1, 0xca,
  0x6e, 0x83, 0x20, 0x49, 0x1b, 0x96, 0xe6, 0x0d, 0xce, 0xe0, 0xf3, 0xc6,
  0x60, 0x18, 0x83, 0xe6, 0x83, 0x83, 0x0d, 0x03, 0x1b, 0xb8, 0x41, 0x1c,
  0x6c, 0x18, 0xca, 0x40, 0x0e, 0x80, 0x09, 0x42, 0x18, 0x5c, 0x1b, 0x04,
  0x82, 0x0e, 0x36, 0x14, 0x99, 0x36, 0x07, 0x56, 0x1d, 0x54, 0x61, 0x63,
  0xb3, 0x6b, 0x73, 0x49, 0x23, 0x2b, 0x73, 0xa3, 0x9b, 0x12, 0x04, 0x55,
  0xc8, 0xf0, 0x5c, 0xec, 0xca, 0xe4, 0xe6, 0xd2, 0xde, 0xdc, 0xa6, 0x04,
  0x44, 0x13, 0x32, 0x3c, 0x17, 0xbb, 0x30, 0x36, 0xbb, 0x32, 0xb9, 0x29,
  0x81, 0x51, 0x87, 0x0c, 0xcf, 0x65, 0x0e, 0x2d, 0x8c, 0xac, 0x4c, 0xae,
  0xe9, 0x8d, 0xac, 0x8c, 0x6d, 0x4a, 0x90, 0x94, 0x21, 0xc3, 0x73, 0x91,
  0x2b, 0x9b, 0x7b, 0xab, 0x93, 0x1b, 0x2b, 0x9b, 0x9b, 0x12, 0x54, 0x75,
  0xc8, 0xf0, 0x5c, 0xec, 0xd2, 0xca, 0xee, 0x92, 0xc8, 0xa6, 0xe8, 0xc2,
  0xe8, 0xca, 0xa6, 0x04, 0x57, 0x1d, 0x32, 0x3c, 0x97, 0x32, 0x37, 0x3a,
  0xb9, 0x3c, 0xa8, 0xb7, 0x34, 0x37, 0xba, 0xb9, 0x29, 0x41, 0x1d, 0x00,
  0x00, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x33,
  0x08, 0x80, 0x1c, 0xc4, 0xe1, 0x1c, 0x66, 0x14, 0x01, 0x3d, 0x88, 0x43,
  0x38, 0x84, 0xc3, 0x8c, 0x42, 0x80, 0x07, 0x79, 0x78, 0x07, 0x73, 0x98,
  0x71, 0x0c, 0xe6, 0x00, 0x0f, 0xed, 0x10, 0x0e, 0xf4, 0x80, 0x0e, 0x33,
  0x0c, 0x42, 0x1e, 0xc2, 0xc1, 0x1d, 0xce, 0xa1, 0x1c, 0x66, 0x30, 0x05,
  0x3d, 0x88, 0x43, 0x38, 0x84, 0x83, 0x1b, 0xcc, 0x03, 0x3d, 0xc8, 0x43,
  0x3d, 0x8c, 0x03, 0x3d, 0xcc, 0x78, 0x8c, 0x74, 0x70, 0x07, 0x7b, 0x08,
  0x07, 0x79, 0x48, 0x87, 0x70, 0x70, 0x07, 0x7a, 0x70, 0x03, 0x76, 0x78,
  0x87, 0x70, 0x20, 0x87, 0x19, 0xcc, 0x11, 0x0e, 0xec, 0x90, 0x0e, 0xe1,
  0x30, 0x0f, 0x6e, 0x30, 0x0f, 0xe3, 0xf0, 0x0e, 0xf0, 0x50, 0x0e, 0x33,
  0x10, 0xc4, 0x1d, 0xde, 0x21, 0x1c, 0xd8, 0x21, 0x1d, 0xc2, 0x61, 0x1e,
  0x66, 0x30, 0x89, 0x3b, 0xbc, 0x83, 0x3b, 0xd0, 0x43, 0x39, 0xb4, 0x03,
  0x3c, 0xbc, 0x83, 0x3c, 0x84, 0x03, 0x3b, 0xcc, 0xf0, 0x14, 0x76, 0x60,
  0x07, 0x7b, 0x68, 0x07, 0x37, 0x68, 0x87, 0x72, 0x68, 0x07, 0x37, 0x80,
  0x87, 0x70, 0x90, 0x87, 0x70, 0x60, 0x07, 0x76, 0x28, 0x07, 0x76, 0xf8,
  0x05, 0x76, 0x78, 0x87, 0x77, 0x80, 0x87, 0x5f, 0x08, 0x87, 0x71, 0x18,
  0x87, 0x72, 0x98, 0x87, 0x79, 0x98, 0x81, 0x2c, 0xee, 0xf0, 0x0e, 0xee,
  0xe0, 0x0e, 0xf5, 0xc0, 0x0e, 0xec, 0x30, 0x03, 0x62, 0xc8, 0xa1, 0x1c,
  0xe4, 0xa1, 0x1c, 0xcc, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xdc, 0x61, 0x1c,
  0xca, 0x21, 0x1c, 0xc4, 0x81, 0x1d, 0xca, 0x61, 0x06, 0xd6, 0x90, 0x43,
  0x39, 0xc8, 0x43, 0x39, 0x98, 0x43, 0x39, 0xc8, 0x43, 0x39, 0xb8, 0xc3,
  0x38, 0x94, 0x43, 0x38, 0x88, 0x03, 0x3b, 0x94, 0xc3, 0x2f, 0xbc, 0x83,
  0x3c, 0xfc, 0x82, 0x3b, 0xd4, 0x03, 0x3b, 0xb0, 0xc3, 0x8c, 0xcc, 0x21,
  0x07, 0x7c, 0x70, 0x03, 0x74, 0x60, 0x07, 0x37, 0x90, 0x87, 0x72, 0x98,
  0x87, 0x77, 0xa8, 0x07, 0x79, 0x18, 0x87, 0x72, 0x70, 0x83, 0x70, 0xa0,
  0x07, 0x7a, 0x90, 0x87, 0x74, 0x10, 0x87, 0x7a, 0xa0, 0x87, 0x72, 0x00,
  0x00, 0x00, 0x00, 0x71, 0x20, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x66,
  0x40, 0x0d, 0x97, 0xef, 0x3c, 0x7e, 0x40, 0x15, 0x05, 0x11, 0x95, 0x0e,
  0x30, 0xf8, 0xc8, 0x6d, 0xdb, 0xc0, 0x36, 0x5c, 0xbe, 0xf3, 0xf8, 0x42,
  0x40, 0x15, 0x05, 0x11, 0x95, 0x0e, 0x30, 0x94, 0x84, 0x01, 0x08, 0x98,
  0x5f, 0xdc, 0xb6, 0x11, 0x6c, 0xc3, 0xe5, 0x3b, 0x8f, 0x2f, 0x04, 0x54,
  0x51, 0x10, 0x51, 0xe9, 0x00, 0x43, 0x49, 0x18, 0x80, 0x80, 0xf9, 0xc8,
  0x6d, 0x5b, 0x81, 0x34, 0x5c, 0xbe, 0xf3, 0xf8, 0x42, 0x44, 0x00, 0x13,
  0x11, 0x02, 0xcd, 0xb0, 0x10, 0x16, 0x30, 0x0d, 0x97, 0xef, 0x3c, 0xfe,
  0xe2, 0x00, 0x83, 0xd8, 0x3c, 0xd4, 0xe4, 0x23, 0xb7, 0x6d, 0x02, 0xd5,
  0x70, 0xf9, 0xce, 0xe3, 0x4b, 0x93, 0x13, 0x11, 0x28, 0x35, 0x3d, 0xd4,
  0xe4, 0x17, 0xb7, 0x6d, 0x00, 0x04, 0x03, 0x20, 0x0d, 0x00, 0x00, 0x61,
  0x20, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x13, 0x04, 0x41, 0x2c, 0x10,
  0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x34, 0xcc, 0x00, 0x14, 0x62,
  0x40, 0xf9, 0x0f, 0x94, 0x5c, 0x21, 0x94, 0x5d, 0x41, 0x14, 0x48, 0xa1,
  0x14, 0x06, 0x49, 0x23, 0x00, 0x74, 0x8c, 0x11, 0x80, 0x20, 0x08, 0x82,
  0xa0, 0x30, 0x02, 0x30, 0x46, 0x00, 0x82, 0x20, 0x88, 0x7f, 0x63, 0x04,
  0x21, 0x09, 0x86, 0x78, 0x07, 0x00, 0x00, 0x23, 0x06, 0x09, 0x00, 0x82,
  0x60, 0x30, 0x95, 0x01, 0x83, 0x89, 0x81, 0x18, 0x14, 0x23, 0x06, 0x09,
  0x00, 0x82, 0x60, 0x30, 0x99, 0x41, 0x83, 0x8d, 0xc1, 0x18, 0x18, 0x23,
  0x06, 0x09, 0x00, 0x82, 0x60, 0x50, 0xac, 0x41, 0x43, 0x06, 0x64, 0xa0,
  0x45, 0x23, 0x06, 0x07, 0x00, 0x82, 0x60, 0x00, 0xa5, 0x41, 0x23, 0x98,
  0xc1, 0x68, 0x42, 0x10, 0x54, 0x30, 0x40, 0x05, 0x8d, 0x8c, 0x18, 0x20,
  0x00, 0x08, 0x82, 0x81, 0xb5, 0x06, 0xd5, 0x11, 0x58, 0xa3, 0x09, 0x01,
  0x70, 0xc1, 0xb1, 0x45, 0x54, 0x30, 0x62, 0x80, 0x00, 0x20, 0x08, 0x06,
  0xd6, 0x1b, 0x64, 0x4b, 0xa0, 0x8d, 0x26, 0x04, 0xc0, 0x05, 0xc7, 0x16,
  0x72, 0xc1, 0x88, 0x01, 0x02, 0x80, 0x20, 0x18, 0x58, 0x73, 0xd0, 0x3d,
  0x81, 0x37, 0x9a, 0x10, 0x00, 0x17, 0x1c, 0x5b, 0x0c, 0x06, 0x23, 0x06,
  0x08, 0x00, 0x82, 0x60, 0x60, 0xdd, 0x41, 0x18, 0x4c, 0x81, 0x18, 0x8c,
  0x26, 0x04, 0xc0, 0x05, 0xc7, 0x16, 0xe4, 0xc1, 0x88, 0x01, 0x02, 0x80,
  0x20, 0x18, 0x58, 0x7b, 0x50, 0x06, 0x57, 0x60, 0x06, 0xa3, 0x09, 0x01,
  0x30, 0x62, 0x70, 0x00, 0x20, 0x08, 0x06, 0x0d, 0x28, 0x8c, 0x01, 0xb6,
  0x07, 0xa3, 0x09, 0x01, 0x30, 0x9a, 0x20, 0x04, 0x26, 0x4c, 0xf2, 0x31,
  0x01, 0x92, 0xcf, 0x68, 0x42, 0x21, 0x8c, 0x26, 0x18, 0x83, 0x11, 0x02,
  0x7c, 0x8c, 0x10, 0xe0, 0x63, 0x66, 0x10, 0xc4, 0xa7, 0x16, 0x38, 0xd0,
  0x62, 0xda, 0x00, 0x2b, 0x90, 0x03, 0x2d, 0xc7, 0x0d, 0xb0, 0x02, 0x3a,
  0xd0, 0x82, 0x48, 0x01, 0xcf, 0x38, 0xea, 0x8a, 0xa3, 0x8e, 0x38, 0xea,
  0x88, 0xa3, 0x8c, 0x70, 0x03, 0xf9, 0x18, 0xf1, 0x06, 0xf2, 0x31, 0x02,
  0x0e, 0xe4, 0x63, 0x44, 0x1c, 0xc8, 0x67, 0xc4, 0x20, 0x01, 0x40, 0x10,
  0x0c, 0x90, 0x5c, 0x90, 0x05, 0x5a, 0x98, 0x85, 0x54, 0x20, 0x46, 0x0c,
  0x12, 0x00, 0x04, 0xc1, 0x00, 0xc9, 0x05, 0x59, 0xa0, 0x85, 0x59, 0x50,
  0x85, 0x61, 0xc4, 0x20, 0x01, 0x40, 0x10, 0x0c, 0x90, 0x5c, 0x90, 0x05,
  0x5a, 0x98, 0x05, 0x54, 0x10, 0x46, 0x0c, 0x12, 0x00, 0x04, 0xc1, 0x00,
  0xc9, 0x05, 0x59, 0xa0, 0x85, 0x59, 0x30, 0x85, 0x60, 0xc4, 0x20, 0x01,
  0x40, 0x10, 0x0c, 0x90, 0x5c, 0x90, 0x05, 0x58, 0x98, 0x85, 0x54, 0x00,
  0x83, 0x11, 0x83, 0x04, 0x00, 0x41, 0x30, 0x40, 0x72, 0x41, 0x16, 0x60,
  0x61, 0x16, 0x54, 0x81, 0x1b, 0x31, 0x48, 0x00, 0x10, 0x04, 0x03, 0x24,
  0x17, 0x64, 0x61, 0x16, 0x66, 0x21, 0x15, 0xa2, 0x11, 0x83, 0x04, 0x00,
  0x41, 0x30, 0x40, 0x72, 0x41, 0x16, 0x66, 0x61, 0x16, 0x54, 0xe1, 0x19,
  0x31, 0x48, 0x00, 0x10, 0x04, 0x03, 0x24, 0x17, 0x64, 0x61, 0x16, 0x66,
  0x01, 0x15, 0xe8, 0x60, 0xc4, 0x20, 0x01, 0x40, 0x10, 0x0c, 0x90, 0x5c,
  0x90, 0x85, 0x59, 0x98, 0x05, 0x53, 0x98, 0x03, 0x04, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00
};
#else
static unsigned char __hlsl_shader_vs_spv[] = {
  0x03, 0x02, 0x23, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x47, 0x4c, 0x53, 0x4c, 0x2e, 0x73, 0x74, 0x64, 0x2e, 0x34, 0x35, 0x30,
  0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
  0x06, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00,
  0x58, 0x02, 0x00, 0x00, 0x05, 0x00, 0x0d, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x74, 0x79, 0x70, 0x65, 0x2e, 0x50, 0x75, 0x73, 0x68, 0x43, 0x6f, 0x6e,
  0x73, 0x74, 0x61, 0x6e, 0x74, 0x2e, 0x52, 0x6f, 0x6f, 0x74, 0x53, 0x69,
  0x67, 0x6e, 0x61, 0x74, 0x75, 0x72, 0x65, 0x43, 0x6f, 0x6e, 0x73, 0x74,
  0x61, 0x6e, 0x74, 0x73, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x05, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x63, 0x61, 0x6c,
  0x65, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x74, 0x72, 0x61, 0x6e, 0x73, 0x6c, 0x61, 0x74,
  0x65, 0x00, 0x00, 0x00, 0x06, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x6f, 0x66, 0x66, 0x73, 0x65, 0x74, 0x73, 0x00,
  0x05, 0x00, 0x05, 0x00, 0x08, 0x00, 0x00, 0x00, 0x76, 0x61, 0x72, 0x69,
  0x61, 0x62, 0x6c, 0x65, 0x73, 0x00, 0x00, 0x00, 0x05, 0x00, 0x08, 0x00,
  0x09, 0x00, 0x00, 0x00, 0x74, 0x79, 0x70, 0x65, 0x2e, 0x42, 0x79, 0x74,
  0x65, 0x41, 0x64, 0x64, 0x72, 0x65, 0x73, 0x73, 0x42, 0x75, 0x66, 0x66,
  0x65, 0x72, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x0a, 0x00, 0x00, 0x00,
  0x69, 0x6d, 0x64, 0x72, 0x61, 0x77, 0x76, 0x65, 0x72, 0x74, 0x73, 0x00,
  0x05, 0x00, 0x06, 0x00, 0x05, 0x00, 0x00, 0x00, 0x6f, 0x75, 0x74, 0x2e,
  0x76, 0x61, 0x72, 0x2e, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x00, 0x6f, 0x75, 0x74, 0x2e,
  0x76, 0x61, 0x72, 0x2e, 0x55, 0x76, 0x00, 0x00, 0x05, 0x00, 0x04, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00,
  0x47, 0x00, 0x04, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
  0x2a, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x47, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x0a, 0x00, 0x00, 0x00,
  0x22, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x48, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x47, 0x00, 0x03, 0x00, 0x07, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x47, 0x00, 0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x48, 0x00, 0x04, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x00, 0x00, 0x00, 0x47, 0x00, 0x03, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x15, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x2b, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x15, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
  0x2b, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x12, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x2b, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x15, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x16, 0x00, 0x03, 0x00, 0x17, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
  0x2b, 0x00, 0x04, 0x00, 0x17, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x17, 0x00, 0x00, 0x00,
  0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x2b, 0x00, 0x04, 0x00,
  0x17, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x00, 0x81, 0x80, 0x80, 0x3b,
  0x2b, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00,
  0xff, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x1c, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x2b, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00,
  0x18, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x1f, 0x00, 0x00, 0x00,
  0x17, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x1e, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00,
  0x1f, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
  0x21, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x1d, 0x00, 0x03, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x1e, 0x00, 0x03, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x04, 0x00, 0x22, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x09, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x23, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00,
  0x24, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x04, 0x00, 0x25, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x24, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x26, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x13, 0x00, 0x02, 0x00,
  0x27, 0x00, 0x00, 0x00, 0x21, 0x00, 0x03, 0x00, 0x28, 0x00, 0x00, 0x00,
  0x27, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x29, 0x00, 0x00, 0x00,
  0x09, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
  0x2a, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x04, 0x00, 0x2b, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x1f, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x2c, 0x00, 0x00, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00,
  0x21, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x3b, 0x00, 0x04, 0x00, 0x22, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x23, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00,
  0x25, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x3b, 0x00, 0x04, 0x00, 0x25, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x26, 0x00, 0x00, 0x00,
  0x06, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00,
  0x17, 0x00, 0x00, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf,
  0x2b, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x2e, 0x00, 0x00, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x2f, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x36, 0x00, 0x05, 0x00,
  0x27, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x28, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x30, 0x00, 0x00, 0x00,
  0x3d, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x41, 0x00, 0x06, 0x00, 0x29, 0x00, 0x00, 0x00,
  0x32, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00,
  0x0e, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x33, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x84, 0x00, 0x05, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00,
  0x2e, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x35, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x84, 0x00, 0x05, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x84, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x37, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, 0x00,
  0x80, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00,
  0x35, 0x00, 0x00, 0x00, 0x37, 0x00, 0x00, 0x00, 0xc2, 0x00, 0x05, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x39, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x41, 0x00, 0x06, 0x00, 0x2a, 0x00, 0x00, 0x00,
  0x3a, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
  0x39, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x3b, 0x00, 0x00, 0x00, 0x3a, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x04, 0x00,
  0x17, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x00, 0x00,
  0x80, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x00, 0x00,
  0x36, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x84, 0x00, 0x05, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x00, 0x00,
  0x12, 0x00, 0x00, 0x00, 0x80, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x3f, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00,
  0xc2, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
  0x3f, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x41, 0x00, 0x06, 0x00,
  0x2a, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00,
  0x11, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00,
  0x7c, 0x00, 0x04, 0x00, 0x17, 0x00, 0x00, 0x00, 0x43, 0x00, 0x00, 0x00,
  0x42, 0x00, 0x00, 0x00, 0x50, 0x00, 0x05, 0x00, 0x1f, 0x00, 0x00, 0x00,
  0x44, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x43, 0x00, 0x00, 0x00,
  0x80, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00, 0x00,
  0x36, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x84, 0x00, 0x05, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00, 0x00,
  0x12, 0x00, 0x00, 0x00, 0x80, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x47, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00,
  0xc2, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00,
  0x47, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x41, 0x00, 0x06, 0x00,
  0x2a, 0x00, 0x00, 0x00, 0x49, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00,
  0x11, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x49, 0x00, 0x00, 0x00,
  0x7c, 0x00, 0x04, 0x00, 0x17, 0x00, 0x00, 0x00, 0x4b, 0x00, 0x00, 0x00,
  0x4a, 0x00, 0x00, 0x00, 0x80, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x4c, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00,
  0x84, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x4d, 0x00, 0x00, 0x00,
  0x4c, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x80, 0x00, 0x05, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x4e, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00,
  0x4d, 0x00, 0x00, 0x00, 0xc2, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x4f, 0x00, 0x00, 0x00, 0x4e, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
  0x41, 0x00, 0x06, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x00,
  0x3d, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x51, 0x00, 0x00, 0x00,
  0x50, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x04, 0x00, 0x17, 0x00, 0x00, 0x00,
  0x52, 0x00, 0x00, 0x00, 0x51, 0x00, 0x00, 0x00, 0x50, 0x00, 0x05, 0x00,
  0x1f, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00, 0x4b, 0x00, 0x00, 0x00,
  0x52, 0x00, 0x00, 0x00, 0x80, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x54, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00,
  0x84, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00,
  0x54, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x80, 0x00, 0x05, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x56, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00,
  0x55, 0x00, 0x00, 0x00, 0xc2, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x57, 0x00, 0x00, 0x00, 0x56, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
  0x41, 0x00, 0x06, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x57, 0x00, 0x00, 0x00,
  0x3d, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00, 0x00,
  0x58, 0x00, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00, 0x2b, 0x00, 0x00, 0x00,
  0x5a, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x3d, 0x00, 0x04, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x5b, 0x00, 0x00, 0x00,
  0x5a, 0x00, 0x00, 0x00, 0x41, 0x00, 0x05, 0x00, 0x2b, 0x00, 0x00, 0x00,
  0x5c, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x3d, 0x00, 0x04, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x5d, 0x00, 0x00, 0x00,
  0x5c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x1f, 0x00, 0x00, 0x00,
  0x5e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00,
  0x44, 0x00, 0x00, 0x00, 0x5b, 0x00, 0x00, 0x00, 0x5d, 0x00, 0x00, 0x00,
  0x51, 0x00, 0x05, 0x00, 0x17, 0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x00,
  0x5e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00,
  0x17, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x5e, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x50, 0x00, 0x07, 0x00, 0x24, 0x00, 0x00, 0x00,
  0x61, 0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
  0x18, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00,
  0x17, 0x00, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
  0x2d, 0x00, 0x00, 0x00, 0x52, 0x00, 0x06, 0x00, 0x24, 0x00, 0x00, 0x00,
  0x63, 0x00, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x61, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x64, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00,
  0xc2, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00,
  0x59, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x05, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00,
  0x1b, 0x00, 0x00, 0x00, 0xc2, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x67, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00,
  0xc7, 0x00, 0x05, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00,
  0x67, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 0xc2, 0x00, 0x05, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x69, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00, 0x00,
  0x1e, 0x00, 0x00, 0x00, 0x50, 0x00, 0x07, 0x00, 0x2c, 0x00, 0x00, 0x00,
  0x6a, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00,
  0x68, 0x00, 0x00, 0x00, 0x69, 0x00, 0x00, 0x00, 0x70, 0x00, 0x04, 0x00,
  0x24, 0x00, 0x00, 0x00, 0x6b, 0x00, 0x00, 0x00, 0x6a, 0x00, 0x00, 0x00,
  0x8e, 0x00, 0x05, 0x00, 0x24, 0x00, 0x00, 0x00, 0x6c, 0x00, 0x00, 0x00,
  0x6b, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x63, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x6c, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00,
  0x06, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x01, 0x00,
  0x38, 0x00, 0x01, 0x00
};
#endif

/*
// dxc.exe hlsl_shader.ps -T ps_6_0 -Fh hlsl_shader.ps.h
// dxc.exe hlsl_shader.ps -T ps_6_0 -Fh hlsl_shader.ps.h -spirv

struct interpolated {
  float4 pos: SV_Position;
  float4 col: Color;
  float2 uv: Uv;
};

struct render {
  float4 color: SV_Target0;
};

[[vk::binding(0, 0)]] SamplerState sampler0: register(s0, space0);
[[vk::binding(1, 0)]] Texture2D    texture0: register(t0, space1);

render main(interpolated input) {
  render output;
  float4 col = input.col;
  col.rgb *= col.rgb;
  output.color = col * texture0.Sample(sampler0, input.uv);
  return output;
}
*/
#ifdef REDGPU_USE_REDGPU_X
static unsigned char __hlsl_shader_ps_spv[] = {
  0x44, 0x58, 0x42, 0x43, 0x1a, 0xf6, 0x58, 0x96, 0x38, 0x60, 0x0c, 0xd4,
  0x58, 0xba, 0x5b, 0xd8, 0x5b, 0x8b, 0x4a, 0xf5, 0x01, 0x00, 0x00, 0x00,
  0x5f, 0x10, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00,
  0x4c, 0x00, 0x00, 0x00, 0xd1, 0x00, 0x00, 0x00, 0x0b, 0x01, 0x00, 0x00,
  0xef, 0x01, 0x00, 0x00, 0x67, 0x09, 0x00, 0x00, 0x83, 0x09, 0x00, 0x00,
  0x53, 0x46, 0x49, 0x30, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x31, 0x7d, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x7a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50,
  0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x43, 0x6f, 0x6c, 0x6f,
  0x72, 0x00, 0x55, 0x76, 0x00, 0x4f, 0x53, 0x47, 0x31, 0x32, 0x00, 0x00,
  0x00, 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
  0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x54, 0x61, 0x72, 0x67,
  0x65, 0x74, 0x00, 0x50, 0x53, 0x56, 0x30, 0xdc, 0x00, 0x00, 0x00, 0x24,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
  0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x00, 0x03, 0x01,
  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00,
  0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x55, 0x76, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x44, 0x03, 0x03,
  0x04, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x44, 0x00, 0x03, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x02, 0x42, 0x00, 0x03, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x44, 0x10, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0f,
  0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x53, 0x54, 0x41, 0x54, 0x70, 0x07, 0x00, 0x00, 0x60,
  0x00, 0x00, 0x00, 0xdc, 0x01, 0x00, 0x00, 0x44, 0x58, 0x49, 0x4c, 0x00,
  0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x58, 0x07, 0x00, 0x00, 0x42,
  0x43, 0xc0, 0xde, 0x21, 0x0c, 0x00, 0x00, 0xd3, 0x01, 0x00, 0x00, 0x0b,
  0x82, 0x20, 0x00, 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x07,
  0x81, 0x23, 0x91, 0x41, 0xc8, 0x04, 0x49, 0x06, 0x10, 0x32, 0x39, 0x92,
  0x01, 0x84, 0x0c, 0x25, 0x05, 0x08, 0x19, 0x1e, 0x04, 0x8b, 0x62, 0x80,
  0x14, 0x45, 0x02, 0x42, 0x92, 0x0b, 0x42, 0xa4, 0x10, 0x32, 0x14, 0x38,
  0x08, 0x18, 0x4b, 0x0a, 0x32, 0x52, 0x88, 0x48, 0x90, 0x14, 0x20, 0x43,
  0x46, 0x88, 0xa5, 0x00, 0x19, 0x32, 0x42, 0xe4, 0x48, 0x0e, 0x90, 0x91,
  0x22, 0xc4, 0x50, 0x41, 0x51, 0x81, 0x8c, 0xe1, 0x83, 0xe5, 0x8a, 0x04,
  0x29, 0x46, 0x06, 0x51, 0x18, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x1b,
  0x8c, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x07, 0x40, 0x02, 0xa8, 0x0d, 0x84,
  0xf0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x20, 0x6d, 0x30, 0x86, 0xff, 0xff,
  0xff, 0xff, 0x1f, 0x00, 0x09, 0xa8, 0x00, 0x49, 0x18, 0x00, 0x00, 0x03,
  0x00, 0x00, 0x00, 0x13, 0x82, 0x60, 0x42, 0x20, 0x4c, 0x08, 0x06, 0x00,
  0x00, 0x00, 0x00, 0x89, 0x20, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x32,
  0x22, 0x48, 0x09, 0x20, 0x64, 0x85, 0x04, 0x93, 0x22, 0xa4, 0x84, 0x04,
  0x93, 0x22, 0xe3, 0x84, 0xa1, 0x90, 0x14, 0x12, 0x4c, 0x8a, 0x8c, 0x0b,
  0x84, 0xa4, 0x4c, 0x10, 0x74, 0x73, 0x04, 0x60, 0x70, 0x93, 0x34, 0x45,
  0x94, 0x30, 0xf9, 0x2c, 0xc0, 0x3c, 0x0b, 0x11, 0xb1, 0x13, 0x30, 0x11,
  0x28, 0x00, 0x14, 0x66, 0x00, 0x86, 0x11, 0x88, 0x61, 0xa6, 0x36, 0x18,
  0x07, 0x76, 0x08, 0x87, 0x79, 0x98, 0x07, 0x37, 0xa0, 0x85, 0x72, 0xc0,
  0x07, 0x7a, 0xa8, 0x07, 0x79, 0x28, 0x07, 0x39, 0x20, 0x05, 0x3e, 0xb0,
  0x87, 0x72, 0x18, 0x07, 0x7a, 0x78, 0x07, 0x79, 0xe0, 0x03, 0x73, 0x60,
  0x87, 0x77, 0x08, 0x07, 0x7a, 0x60, 0x03, 0x30, 0xa0, 0x03, 0x3f, 0x00,
  0x03, 0x3f, 0xd0, 0x03, 0x3d, 0x68, 0x87, 0x74, 0x80, 0x87, 0x79, 0xf8,
  0x05, 0x7a, 0xc8, 0x07, 0x78, 0x28, 0x07, 0x14, 0x80, 0x99, 0xc4, 0x60,
  0x1c, 0xd8, 0x21, 0x1c, 0xe6, 0x61, 0x1e, 0xdc, 0x80, 0x16, 0xca, 0x01,
  0x1f, 0xe8, 0xa1, 0x1e, 0xe4, 0xa1, 0x1c, 0xe4, 0x80, 0x14, 0xf8, 0xc0,
  0x1e, 0xca, 0x61, 0x1c, 0xe8, 0xe1, 0x1d, 0xe4, 0x81, 0x0f, 0xcc, 0x81,
  0x1d, 0xde, 0x21, 0x1c, 0xe8, 0x81, 0x0d, 0xc0, 0x80, 0x0e, 0xfc, 0x00,
  0x0c, 0xfc, 0x00, 0x09, 0xa4, 0x90, 0x19, 0x01, 0x28, 0x01, 0xa2, 0x34,
  0x47, 0x80, 0x14, 0x63, 0x00, 0x00, 0x16, 0x20, 0x56, 0x0c, 0x04, 0x00,
  0x58, 0x83, 0xdc, 0x4d, 0xc3, 0xe5, 0x4f, 0xd8, 0x43, 0x48, 0xfe, 0x4a,
  0x48, 0x2b, 0x31, 0xf9, 0xc5, 0x6d, 0xa3, 0x62, 0x8c, 0x31, 0x00, 0xad,
  0x7b, 0x86, 0xcb, 0x9f, 0xb0, 0x87, 0x90, 0xfc, 0x10, 0x68, 0x86, 0x85,
  0x40, 0x41, 0x2c, 0x0c, 0x04, 0x52, 0x8e, 0x31, 0x06, 0x00, 0x60, 0xd0,
  0x9c, 0x23, 0x08, 0x8a, 0x21, 0xc1, 0x02, 0xa0, 0x92, 0x1d, 0x08, 0xb8,
  0x46, 0x9a, 0x22, 0x4a, 0x98, 0xfc, 0x88, 0x68, 0x06, 0x22, 0x42, 0x01,
  0x19, 0x46, 0x10, 0x86, 0x9b, 0xa4, 0x29, 0xa2, 0x84, 0xc9, 0x47, 0x9a,
  0x89, 0x88, 0x1e, 0x67, 0x01, 0x26, 0x62, 0x40, 0x03, 0x21, 0x3a, 0x19,
  0x00, 0x00, 0x00, 0x13, 0x14, 0x72, 0xc0, 0x87, 0x74, 0x60, 0x87, 0x36,
  0x68, 0x87, 0x79, 0x68, 0x03, 0x72, 0xc0, 0x87, 0x0d, 0xaf, 0x50, 0x0e,
  0x6d, 0xd0, 0x0e, 0x7a, 0x50, 0x0e, 0x6d, 0x00, 0x0f, 0x7a, 0x30, 0x07,
  0x72, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0xa0, 0x07,
  0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x78, 0xa0, 0x07, 0x73, 0x20, 0x07,
  0x6d, 0x90, 0x0e, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06,
  0xe9, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e,
  0x76, 0x40, 0x07, 0x7a, 0x60, 0x07, 0x74, 0xd0, 0x06, 0xe6, 0x10, 0x07,
  0x76, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x60, 0x0e, 0x73, 0x20, 0x07,
  0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe6, 0x60, 0x07, 0x74, 0xa0, 0x07,
  0x76, 0x40, 0x07, 0x6d, 0xe0, 0x0e, 0x78, 0xa0, 0x07, 0x71, 0x60, 0x07,
  0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x3a, 0x0f, 0x64,
  0x90, 0x21, 0x23, 0x45, 0x44, 0x00, 0x66, 0x00, 0xc0, 0xf4, 0x00, 0x80,
  0x87, 0x3c, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0c, 0x79, 0x18, 0x20, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x18, 0xf2, 0x38, 0x40, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x30, 0xe4, 0x99, 0x80, 0x00, 0x18, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x60, 0xc8, 0x63, 0x01, 0x01, 0x30, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x16, 0x08, 0x00, 0x00, 0x00, 0x15,
  0x00, 0x00, 0x00, 0x32, 0x1e, 0x98, 0x18, 0x19, 0x11, 0x4c, 0x90, 0x8c,
  0x09, 0x26, 0x47, 0xc6, 0x04, 0x43, 0x02, 0x25, 0x30, 0x02, 0x50, 0x0c,
  0x45, 0x50, 0x12, 0x85, 0x52, 0x06, 0xe5, 0x50, 0x20, 0x85, 0x50, 0x0a,
  0x05, 0x55, 0x40, 0xe5, 0x41, 0xab, 0x40, 0x8a, 0x60, 0x04, 0xa0, 0x10,
  0xca, 0xa0, 0x24, 0xe8, 0xcc, 0x00, 0x90, 0x99, 0x01, 0xa0, 0x32, 0x03,
  0x40, 0x64, 0x06, 0x80, 0xc4, 0x0c, 0x00, 0xe5, 0x19, 0x00, 0xda, 0x33,
  0x00, 0xc4, 0xc7, 0x62, 0x14, 0x02, 0x00, 0x00, 0x20, 0x10, 0x08, 0xe4,
  0x79, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00, 0x9b, 0x00, 0x00, 0x00, 0x1a,
  0x03, 0x4c, 0x90, 0x46, 0x02, 0x13, 0xc4, 0x83, 0x0c, 0x6f, 0x0c, 0x24,
  0xc6, 0x45, 0x66, 0x43, 0x10, 0x4c, 0x10, 0x80, 0x63, 0x82, 0x00, 0x20,
  0x1b, 0x84, 0x81, 0xd8, 0x20, 0x10, 0x04, 0x05, 0xb8, 0xb9, 0x09, 0x02,
  0x90, 0x6c, 0x18, 0x0e, 0x84, 0x98, 0x20, 0x1c, 0x1b, 0x11, 0xba, 0x32,
  0x3c, 0xba, 0x3a, 0xb9, 0x32, 0x98, 0x09, 0x02, 0xa0, 0x4c, 0x10, 0x80,
  0x65, 0x83, 0x40, 0x34, 0x1b, 0x12, 0x42, 0x59, 0x06, 0x62, 0x60, 0x08,
  0x67, 0x43, 0xf0, 0x4c, 0x10, 0x84, 0x8f, 0xc8, 0x5c, 0x58, 0x1b, 0x1c,
  0x5b, 0x99, 0x1c, 0xcc, 0x06, 0x84, 0x88, 0x24, 0x82, 0x18, 0x08, 0x60,
  0x43, 0x30, 0x6d, 0x20, 0x20, 0x00, 0xa0, 0x26, 0x08, 0x06, 0x37, 0x41,
  0x00, 0x18, 0x06, 0x68, 0x13, 0x04, 0xa0, 0x99, 0x20, 0x00, 0xce, 0x06,
  0x03, 0xc1, 0x32, 0x42, 0x6b, 0x48, 0xb4, 0xa5, 0xc1, 0xcd, 0x4d, 0x10,
  0x80, 0x67, 0x03, 0x81, 0x70, 0x59, 0x37, 0x41, 0x20, 0xbc, 0x0d, 0x02,
  0xf1, 0x6d, 0x08, 0xc0, 0x60, 0x83, 0x40, 0x84, 0xc1, 0x06, 0xe2, 0xda,
  0x3c, 0x31, 0x98, 0x20, 0x14, 0xdd, 0x04, 0x01, 0x80, 0x68, 0xa0, 0x85,
  0xb9, 0x91, 0xb1, 0x95, 0x4d, 0x10, 0x80, 0x68, 0x83, 0x81, 0x98, 0x41,
  0x46, 0x68, 0x67, 0xb0, 0x41, 0x28, 0x03, 0x34, 0x98, 0x20, 0x64, 0x60,
  0xc0, 0x62, 0xec, 0x8d, 0xed, 0x4d, 0x8e, 0xca, 0x94, 0xd5, 0x17, 0x55,
  0x98, 0xdc, 0x59, 0x19, 0x1d, 0xcc, 0x06, 0x04, 0x59, 0x83, 0x8c, 0x28,
  0x03, 0x36, 0xd0, 0x9a, 0x0d, 0x42, 0xd7, 0x06, 0x13, 0x84, 0x2d, 0x0c,
  0x26, 0x08, 0x80, 0xc4, 0x01, 0xee, 0x6d, 0x8e, 0xcb, 0x94, 0xd5, 0x17,
  0xd4, 0xdb, 0x5c, 0x1a, 0x5d, 0xda, 0x9b, 0xdb, 0x06, 0x04, 0x89, 0x83,
  0x8c, 0x28, 0x03, 0x39, 0xd0, 0x1a, 0x0e, 0x63, 0x6f, 0x6c, 0x2c, 0x86,
  0xde, 0xd8, 0xde, 0xe4, 0x36, 0x20, 0x08, 0x1d, 0x64, 0x5d, 0x19, 0xd4,
  0x81, 0xd6, 0x50, 0xa8, 0xb3, 0x9b, 0x20, 0x00, 0x13, 0x85, 0x2a, 0xbb,
  0x0d, 0x08, 0x72, 0x07, 0x19, 0x1e, 0x94, 0x41, 0x1e, 0x68, 0xcd, 0x06,
  0x02, 0x0e, 0xe6, 0xc0, 0x0e, 0xf4, 0x60, 0x43, 0x42, 0x58, 0x63, 0x40,
  0x06, 0x69, 0xa0, 0x06, 0x6e, 0xf0, 0x06, 0x7b, 0x30, 0x41, 0x50, 0x84,
  0x0d, 0xc0, 0x86, 0x81, 0xf0, 0x03, 0x3f, 0xd8, 0x10, 0xfc, 0xc1, 0x86,
  0x61, 0xe8, 0x03, 0x50, 0x98, 0x20, 0x70, 0x62, 0xb0, 0x21, 0x10, 0x05,
  0x12, 0x6d, 0x61, 0x69, 0x6e, 0x13, 0x84, 0x45, 0x9b, 0x20, 0x2c, 0xd9,
  0x86, 0x80, 0x98, 0x20, 0x2c, 0xd8, 0x04, 0x61, 0xb9, 0x36, 0x2c, 0x84,
  0x1c, 0x94, 0x82, 0x29, 0x9c, 0x02, 0x2a, 0x0c, 0xa8, 0x40, 0xa4, 0x02,
  0x30, 0x41, 0x58, 0xac, 0x09, 0x02, 0x40, 0x6d, 0x10, 0x32, 0x56, 0xd8,
  0xb0, 0x0c, 0x75, 0x50, 0x0a, 0xa9, 0x70, 0x0a, 0xab, 0x30, 0xa0, 0xc2,
  0x90, 0x0a, 0xad, 0xb0, 0x41, 0xc8, 0xb2, 0x0d, 0x0b, 0x93, 0x07, 0xa5,
  0x90, 0x0a, 0xa7, 0xb0, 0x0a, 0xc3, 0x2a, 0x30, 0xa9, 0xf0, 0x0a, 0x1b,
  0x06, 0x55, 0x70, 0x05, 0x58, 0x60, 0x32, 0x65, 0xf5, 0x45, 0x15, 0x26,
  0x77, 0x56, 0x46, 0x37, 0x41, 0x58, 0xaa, 0x0d, 0x0b, 0x21, 0x0b, 0xa5,
  0x30, 0x0b, 0xa7, 0x90, 0x0a, 0x03, 0x2a, 0x10, 0xa9, 0xd0, 0x0a, 0x1b,
  0x02, 0x5a, 0xd8, 0x30, 0xc4, 0x42, 0x2d, 0x00, 0x1b, 0x8a, 0x3e, 0x20,
  0x05, 0x5b, 0xa8, 0x80, 0x2a, 0x6c, 0x6c, 0x76, 0x6d, 0x2e, 0x69, 0x64,
  0x65, 0x6e, 0x74, 0x53, 0x82, 0xa0, 0x0a, 0x19, 0x9e, 0x8b, 0x5d, 0x99,
  0xdc, 0x5c, 0xda, 0x9b, 0xdb, 0x94, 0x80, 0x68, 0x42, 0x86, 0xe7, 0x62,
  0x17, 0xc6, 0x66, 0x57, 0x26, 0x37, 0x25, 0x28, 0xea, 0x90, 0xe1, 0xb9,
  0xcc, 0xa1, 0x85, 0x91, 0x95, 0xc9, 0x35, 0xbd, 0x91, 0x95, 0xb1, 0x4d,
  0x09, 0x90, 0x32, 0x64, 0x78, 0x2e, 0x72, 0x65, 0x73, 0x6f, 0x75, 0x72,
  0x63, 0x65, 0x73, 0x53, 0x02, 0xaa, 0x12, 0x19, 0x9e, 0x0b, 0x5d, 0x1e,
  0x5c, 0x59, 0x90, 0x9b, 0xdb, 0x1b, 0x5d, 0x18, 0x5d, 0xda, 0x9b, 0xdb,
  0xdc, 0x14, 0x61, 0x0f, 0x40, 0xa1, 0x0e, 0x19, 0x9e, 0x8b, 0x5d, 0x5a,
  0xd9, 0x5d, 0x12, 0xd9, 0x14, 0x5d, 0x18, 0x5d, 0xd9, 0x94, 0x40, 0x14,
  0xea, 0x90, 0xe1, 0xb9, 0x94, 0xb9, 0xd1, 0xc9, 0xe5, 0x41, 0xbd, 0xa5,
  0xb9, 0xd1, 0xcd, 0x4d, 0x09, 0x6c, 0x01, 0x79, 0x18, 0x00, 0x00, 0x4c,
  0x00, 0x00, 0x00, 0x33, 0x08, 0x80, 0x1c, 0xc4, 0xe1, 0x1c, 0x66, 0x14,
  0x01, 0x3d, 0x88, 0x43, 0x38, 0x84, 0xc3, 0x8c, 0x42, 0x80, 0x07, 0x79,
  0x78, 0x07, 0x73, 0x98, 0x71, 0x0c, 0xe6, 0x00, 0x0f, 0xed, 0x10, 0x0e,
  0xf4, 0x80, 0x0e, 0x33, 0x0c, 0x42, 0x1e, 0xc2, 0xc1, 0x1d, 0xce, 0xa1,
  0x1c, 0x66, 0x30, 0x05, 0x3d, 0x88, 0x43, 0x38, 0x84, 0x83, 0x1b, 0xcc,
  0x03, 0x3d, 0xc8, 0x43, 0x3d, 0x8c, 0x03, 0x3d, 0xcc, 0x78, 0x8c, 0x74,
  0x70, 0x07, 0x7b, 0x08, 0x07, 0x79, 0x48, 0x87, 0x70, 0x70, 0x07, 0x7a,
  0x70, 0x03, 0x76, 0x78, 0x87, 0x70, 0x20, 0x87, 0x19, 0xcc, 0x11, 0x0e,
  0xec, 0x90, 0x0e, 0xe1, 0x30, 0x0f, 0x6e, 0x30, 0x0f, 0xe3, 0xf0, 0x0e,
  0xf0, 0x50, 0x0e, 0x33, 0x10, 0xc4, 0x1d, 0xde, 0x21, 0x1c, 0xd8, 0x21,
  0x1d, 0xc2, 0x61, 0x1e, 0x66, 0x30, 0x89, 0x3b, 0xbc, 0x83, 0x3b, 0xd0,
  0x43, 0x39, 0xb4, 0x03, 0x3c, 0xbc, 0x83, 0x3c, 0x84, 0x03, 0x3b, 0xcc,
  0xf0, 0x14, 0x76, 0x60, 0x07, 0x7b, 0x68, 0x07, 0x37, 0x68, 0x87, 0x72,
  0x68, 0x07, 0x37, 0x80, 0x87, 0x70, 0x90, 0x87, 0x70, 0x60, 0x07, 0x76,
  0x28, 0x07, 0x76, 0xf8, 0x05, 0x76, 0x78, 0x87, 0x77, 0x80, 0x87, 0x5f,
  0x08, 0x87, 0x71, 0x18, 0x87, 0x72, 0x98, 0x87, 0x79, 0x98, 0x81, 0x2c,
  0xee, 0xf0, 0x0e, 0xee, 0xe0, 0x0e, 0xf5, 0xc0, 0x0e, 0xec, 0x30, 0x03,
  0x62, 0xc8, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xcc, 0xa1, 0x1c, 0xe4, 0xa1,
  0x1c, 0xdc, 0x61, 0x1c, 0xca, 0x21, 0x1c, 0xc4, 0x81, 0x1d, 0xca, 0x61,
  0x06, 0xd6, 0x90, 0x43, 0x39, 0xc8, 0x43, 0x39, 0x98, 0x43, 0x39, 0xc8,
  0x43, 0x39, 0xb8, 0xc3, 0x38, 0x94, 0x43, 0x38, 0x88, 0x03, 0x3b, 0x94,
  0xc3, 0x2f, 0xbc, 0x83, 0x3c, 0xfc, 0x82, 0x3b, 0xd4, 0x03, 0x3b, 0xb0,
  0xc3, 0x8c, 0xcc, 0x21, 0x07, 0x7c, 0x70, 0x03, 0x74, 0x60, 0x07, 0x37,
  0x90, 0x87, 0x72, 0x98, 0x87, 0x77, 0xa8, 0x07, 0x79, 0x18, 0x87, 0x72,
  0x70, 0x83, 0x70, 0xa0, 0x07, 0x7a, 0x90, 0x87, 0x74, 0x10, 0x87, 0x7a,
  0xa0, 0x87, 0x72, 0x00, 0x00, 0x00, 0x00, 0x71, 0x20, 0x00, 0x00, 0x24,
  0x00, 0x00, 0x00, 0x05, 0xd0, 0x05, 0x7e, 0xf3, 0x70, 0x1b, 0xce, 0x2e,
  0xcb, 0x61, 0x40, 0xe0, 0xac, 0x3a, 0x0d, 0xb7, 0xe1, 0xec, 0xb2, 0x7c,
  0x4a, 0x0f, 0xd3, 0xcb, 0x40, 0x60, 0xb0, 0x02, 0xda, 0x20, 0xf0, 0xa3,
  0x97, 0xf1, 0xf4, 0xba, 0xbc, 0x0c, 0x03, 0x02, 0x67, 0xd6, 0x1f, 0x89,
  0x5a, 0xc6, 0xd3, 0xeb, 0xf2, 0xb2, 0x8c, 0x08, 0xb4, 0xfe, 0x48, 0xf6,
  0xf2, 0x98, 0xfe, 0x96, 0x03, 0x9b, 0x24, 0xd8, 0x0c, 0x08, 0x04, 0x02,
  0x83, 0x66, 0x20, 0x0d, 0x97, 0xef, 0x3c, 0xbe, 0x10, 0x11, 0xc0, 0x44,
  0x84, 0x40, 0x33, 0x2c, 0x84, 0x0d, 0x4c, 0xc3, 0xe5, 0x3b, 0x8f, 0xbf,
  0x38, 0xc0, 0x20, 0x36, 0x0f, 0x35, 0xf9, 0xc5, 0x6d, 0x5b, 0x01, 0x34,
  0x5c, 0xbe, 0xf3, 0xf8, 0x12, 0xc0, 0x3c, 0x0b, 0xe1, 0x17, 0xb7, 0x6d,
  0x04, 0xd5, 0x70, 0xf9, 0xce, 0xe3, 0x4b, 0x93, 0x13, 0x11, 0x28, 0x35,
  0x3d, 0xd4, 0xe4, 0x17, 0xb7, 0x6d, 0x02, 0x04, 0x03, 0x20, 0x0d, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x41, 0x53, 0x48, 0x14,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x41, 0x3b, 0x82, 0x45,
  0x0c, 0x43, 0x1b, 0xc1, 0x6a, 0x0c, 0x7b, 0x8f, 0x92, 0x5e, 0xee, 0x44,
  0x58, 0x49, 0x4c, 0xd4, 0x06, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0xb5,
  0x01, 0x00, 0x00, 0x44, 0x58, 0x49, 0x4c, 0x00, 0x01, 0x00, 0x00, 0x10,
  0x00, 0x00, 0x00, 0xbc, 0x06, 0x00, 0x00, 0x42, 0x43, 0xc0, 0xde, 0x21,
  0x0c, 0x00, 0x00, 0xac, 0x01, 0x00, 0x00, 0x0b, 0x82, 0x20, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x07, 0x81, 0x23, 0x91, 0x41,
  0xc8, 0x04, 0x49, 0x06, 0x10, 0x32, 0x39, 0x92, 0x01, 0x84, 0x0c, 0x25,
  0x05, 0x08, 0x19, 0x1e, 0x04, 0x8b, 0x62, 0x80, 0x14, 0x45, 0x02, 0x42,
  0x92, 0x0b, 0x42, 0xa4, 0x10, 0x32, 0x14, 0x38, 0x08, 0x18, 0x4b, 0x0a,
  0x32, 0x52, 0x88, 0x48, 0x90, 0x14, 0x20, 0x43, 0x46, 0x88, 0xa5, 0x00,
  0x19, 0x32, 0x42, 0xe4, 0x48, 0x0e, 0x90, 0x91, 0x22, 0xc4, 0x50, 0x41,
  0x51, 0x81, 0x8c, 0xe1, 0x83, 0xe5, 0x8a, 0x04, 0x29, 0x46, 0x06, 0x51,
  0x18, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x1b, 0x8c, 0xe0, 0xff, 0xff,
  0xff, 0xff, 0x07, 0x40, 0x02, 0xa8, 0x0d, 0x84, 0xf0, 0xff, 0xff, 0xff,
  0xff, 0x03, 0x20, 0x6d, 0x30, 0x86, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00,
  0x09, 0xa8, 0x00, 0x49, 0x18, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x13,
  0x82, 0x60, 0x42, 0x20, 0x4c, 0x08, 0x06, 0x00, 0x00, 0x00, 0x00, 0x89,
  0x20, 0x00, 0x00, 0x43, 0x00, 0x00, 0x00, 0x32, 0x22, 0x48, 0x09, 0x20,
  0x64, 0x85, 0x04, 0x93, 0x22, 0xa4, 0x84, 0x04, 0x93, 0x22, 0xe3, 0x84,
  0xa1, 0x90, 0x14, 0x12, 0x4c, 0x8a, 0x8c, 0x0b, 0x84, 0xa4, 0x4c, 0x10,
  0x68, 0x23, 0x00, 0x25, 0x00, 0x14, 0x66, 0x00, 0xe6, 0x08, 0xc0, 0x60,
  0x8e, 0x00, 0x29, 0xc6, 0x20, 0x84, 0x14, 0x42, 0xa6, 0x18, 0x80, 0x10,
  0x52, 0x06, 0xa1, 0x9b, 0x86, 0xcb, 0x9f, 0xb0, 0x87, 0x90, 0xfc, 0x95,
  0x90, 0x56, 0x62, 0xf2, 0x8b, 0xdb, 0x46, 0xc5, 0x18, 0x63, 0x10, 0x2a,
  0xf7, 0x0c, 0x97, 0x3f, 0x61, 0x0f, 0x21, 0xf9, 0x21, 0xd0, 0x0c, 0x0b,
  0x81, 0x82, 0x55, 0x18, 0x45, 0x18, 0x1b, 0x63, 0x0c, 0x42, 0xc8, 0xa0,
  0x36, 0x47, 0x10, 0x14, 0x83, 0x91, 0x42, 0xc8, 0x23, 0x38, 0x10, 0x30,
  0x8c, 0x40, 0x0c, 0x33, 0xb5, 0xc1, 0x38, 0xb0, 0x43, 0x38, 0xcc, 0xc3,
  0x3c, 0xb8, 0x01, 0x2d, 0x94, 0x03, 0x3e, 0xd0, 0x43, 0x3d, 0xc8, 0x43,
  0x39, 0xc8, 0x01, 0x29, 0xf0, 0x81, 0x3d, 0x94, 0xc3, 0x38, 0xd0, 0xc3,
  0x3b, 0xc8, 0x03, 0x1f, 0x98, 0x03, 0x3b, 0xbc, 0x43, 0x38, 0xd0, 0x03,
  0x1b, 0x80, 0x01, 0x1d, 0xf8, 0x01, 0x18, 0xf8, 0x81, 0x1e, 0xe8, 0x41,
  0x3b, 0xa4, 0x03, 0x3c, 0xcc, 0xc3, 0x2f, 0xd0, 0x43, 0x3e, 0xc0, 0x43,
  0x39, 0xa0, 0x80, 0xcc, 0x24, 0x06, 0xe3, 0xc0, 0x0e, 0xe1, 0x30, 0x0f,
  0xf3, 0xe0, 0x06, 0xb4, 0x50, 0x0e, 0xf8, 0x40, 0x0f, 0xf5, 0x20, 0x0f,
  0xe5, 0x20, 0x07, 0xa4, 0xc0, 0x07, 0xf6, 0x50, 0x0e, 0xe3, 0x40, 0x0f,
  0xef, 0x20, 0x0f, 0x7c, 0x60, 0x0e, 0xec, 0xf0, 0x0e, 0xe1, 0x40, 0x0f,
  0x6c, 0x00, 0x06, 0x74, 0xe0, 0x07, 0x60, 0xe0, 0x07, 0x48, 0x98, 0x94,
  0xea, 0x4d, 0xd2, 0x14, 0x51, 0xc2, 0xe4, 0xb3, 0x00, 0xf3, 0x2c, 0x44,
  0xc4, 0x4e, 0xc0, 0x44, 0xa0, 0x80, 0xd0, 0x4d, 0x06, 0x02, 0x00, 0x13,
  0x14, 0x72, 0xc0, 0x87, 0x74, 0x60, 0x87, 0x36, 0x68, 0x87, 0x79, 0x68,
  0x03, 0x72, 0xc0, 0x87, 0x0d, 0xaf, 0x50, 0x0e, 0x6d, 0xd0, 0x0e, 0x7a,
  0x50, 0x0e, 0x6d, 0x00, 0x0f, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x73,
  0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d,
  0x90, 0x0e, 0x78, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71,
  0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe9, 0x30, 0x07, 0x72,
  0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x76, 0x40, 0x07, 0x7a,
  0x60, 0x07, 0x74, 0xd0, 0x06, 0xe6, 0x10, 0x07, 0x76, 0xa0, 0x07, 0x73,
  0x20, 0x07, 0x6d, 0x60, 0x0e, 0x73, 0x20, 0x07, 0x7a, 0x30, 0x07, 0x72,
  0xd0, 0x06, 0xe6, 0x60, 0x07, 0x74, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x6d,
  0xe0, 0x0e, 0x78, 0xa0, 0x07, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72,
  0xa0, 0x07, 0x76, 0x40, 0x07, 0x43, 0x9e, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x3c, 0x06, 0x10, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x79, 0x10, 0x20, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xf2, 0x34, 0x40,
  0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xe4, 0x81,
  0x80, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x0b,
  0x04, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x32, 0x1e, 0x98, 0x14, 0x19,
  0x11, 0x4c, 0x90, 0x8c, 0x09, 0x26, 0x47, 0xc6, 0x04, 0x43, 0x22, 0x25,
  0x30, 0x02, 0x50, 0x0a, 0xc5, 0x50, 0x04, 0x25, 0x51, 0x06, 0xe5, 0x41,
  0xa5, 0x24, 0xca, 0xa0, 0x10, 0x46, 0x00, 0x8a, 0xa0, 0x40, 0xc8, 0xce,
  0x00, 0x10, 0x9e, 0x01, 0xa0, 0x3c, 0x16, 0xa3, 0x10, 0x00, 0x00, 0x00,
  0x81, 0x40, 0x20, 0xcf, 0x03, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00, 0x59,
  0x00, 0x00, 0x00, 0x1a, 0x03, 0x4c, 0x90, 0x46, 0x02, 0x13, 0xc4, 0x83,
  0x0c, 0x6f, 0x0c, 0x24, 0xc6, 0x45, 0x66, 0x43, 0x10, 0x4c, 0x10, 0x88,
  0x62, 0x82, 0x40, 0x18, 0x1b, 0x84, 0x81, 0x98, 0x20, 0x10, 0xc7, 0x06,
  0x61, 0x30, 0x28, 0xc0, 0xcd, 0x4d, 0x10, 0x08, 0x64, 0xc3, 0x80, 0x24,
  0xc4, 0x04, 0xc1, 0x9a, 0x08, 0x4c, 0x10, 0x88, 0x64, 0x82, 0x40, 0x28,
  0x1b, 0x04, 0xc2, 0xd9, 0x90, 0x10, 0x0b, 0x33, 0x10, 0x43, 0x43, 0x3c,
  0x1b, 0x02, 0x68, 0x82, 0x80, 0x51, 0x1b, 0x10, 0x42, 0x62, 0x08, 0x62,
  0x20, 0x80, 0x0d, 0xc1, 0xb4, 0x81, 0x88, 0x00, 0x80, 0x9a, 0x20, 0x64,
  0xd5, 0x86, 0xc0, 0x9a, 0x20, 0x08, 0x00, 0x89, 0xb6, 0xb0, 0x34, 0x37,
  0x2e, 0x53, 0x56, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e,
  0x13, 0x84, 0xa2, 0x99, 0x20, 0x14, 0xce, 0x86, 0x80, 0x98, 0x20, 0x14,
  0xcf, 0x04, 0xa1, 0x80, 0x36, 0x2c, 0x84, 0xb6, 0x71, 0x9d, 0x37, 0x78,
  0xc4, 0x07, 0xb0, 0x18, 0x7a, 0x63, 0x7b, 0x93, 0x9b, 0x20, 0x14, 0xd1,
  0x04, 0x81, 0x58, 0x26, 0x08, 0x04, 0xb3, 0x41, 0x18, 0x03, 0x32, 0xd8,
  0xb0, 0x0c, 0x61, 0xb0, 0x7d, 0x9d, 0x18, 0x0c, 0xde, 0xf0, 0x95, 0x01,
  0x85, 0x2a, 0xbb, 0x0d, 0xc2, 0x18, 0x8c, 0xc1, 0x86, 0xa5, 0x39, 0x83,
  0xed, 0xeb, 0xc4, 0x60, 0x10, 0x83, 0xe6, 0x43, 0x83, 0x0d, 0x03, 0x18,
  0x98, 0x41, 0x1a, 0x30, 0x99, 0xb2, 0xfa, 0xa2, 0x0a, 0x93, 0x3b, 0x2b,
  0xa3, 0x9b, 0x20, 0x14, 0xd2, 0x86, 0x85, 0x58, 0x83, 0x8d, 0x0d, 0xba,
  0x6f, 0xf0, 0x88, 0xaf, 0x0c, 0x36, 0x04, 0x6d, 0xb0, 0x61, 0x50, 0x03,
  0x37, 0x00, 0x36, 0x14, 0x58, 0xf6, 0x06, 0x15, 0x50, 0x85, 0x8d, 0xcd,
  0xae, 0xcd, 0x25, 0x8d, 0xac, 0xcc, 0x8d, 0x6e, 0x4a, 0x10, 0x54, 0x21,
  0xc3, 0x73, 0xb1, 0x2b, 0x93, 0x9b, 0x4b, 0x7b, 0x73, 0x9b, 0x12, 0x10,
  0x4d, 0xc8, 0xf0, 0x5c, 0xec, 0xc2, 0xd8, 0xec, 0xca, 0xe4, 0xa6, 0x04,
  0x46, 0x1d, 0x32, 0x3c, 0x97, 0x39, 0xb4, 0x30, 0xb2, 0x32, 0xb9, 0xa6,
  0x37, 0xb2, 0x32, 0xb6, 0x29, 0x41, 0x52, 0x86, 0x0c, 0xcf, 0x45, 0xae,
  0x6c, 0xee, 0xad, 0x4e, 0x6e, 0xac, 0x6c, 0x6e, 0x4a, 0x40, 0xd5, 0x21,
  0xc3, 0x73, 0xb1, 0x4b, 0x2b, 0xbb, 0x4b, 0x22, 0x9b, 0xa2, 0x0b, 0xa3,
  0x2b, 0x9b, 0x12, 0x58, 0x75, 0xc8, 0xf0, 0x5c, 0xca, 0xdc, 0xe8, 0xe4,
  0xf2, 0xa0, 0xde, 0xd2, 0xdc, 0xe8, 0xe6, 0xa6, 0x04, 0x6f, 0x00, 0x79,
  0x18, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x33, 0x08, 0x80, 0x1c, 0xc4,
  0xe1, 0x1c, 0x66, 0x14, 0x01, 0x3d, 0x88, 0x43, 0x38, 0x84, 0xc3, 0x8c,
  0x42, 0x80, 0x07, 0x79, 0x78, 0x07, 0x73, 0x98, 0x71, 0x0c, 0xe6, 0x00,
  0x0f, 0xed, 0x10, 0x0e, 0xf4, 0x80, 0x0e, 0x33, 0x0c, 0x42, 0x1e, 0xc2,
  0xc1, 0x1d, 0xce, 0xa1, 0x1c, 0x66, 0x30, 0x05, 0x3d, 0x88, 0x43, 0x38,
  0x84, 0x83, 0x1b, 0xcc, 0x03, 0x3d, 0xc8, 0x43, 0x3d, 0x8c, 0x03, 0x3d,
  0xcc, 0x78, 0x8c, 0x74, 0x70, 0x07, 0x7b, 0x08, 0x07, 0x79, 0x48, 0x87,
  0x70, 0x70, 0x07, 0x7a, 0x70, 0x03, 0x76, 0x78, 0x87, 0x70, 0x20, 0x87,
  0x19, 0xcc, 0x11, 0x0e, 0xec, 0x90, 0x0e, 0xe1, 0x30, 0x0f, 0x6e, 0x30,
  0x0f, 0xe3, 0xf0, 0x0e, 0xf0, 0x50, 0x0e, 0x33, 0x10, 0xc4, 0x1d, 0xde,
  0x21, 0x1c, 0xd8, 0x21, 0x1d, 0xc2, 0x61, 0x1e, 0x66, 0x30, 0x89, 0x3b,
  0xbc, 0x83, 0x3b, 0xd0, 0x43, 0x39, 0xb4, 0x03, 0x3c, 0xbc, 0x83, 0x3c,
  0x84, 0x03, 0x3b, 0xcc, 0xf0, 0x14, 0x76, 0x60, 0x07, 0x7b, 0x68, 0x07,
  0x37, 0x68, 0x87, 0x72, 0x68, 0x07, 0x37, 0x80, 0x87, 0x70, 0x90, 0x87,
  0x70, 0x60, 0x07, 0x76, 0x28, 0x07, 0x76, 0xf8, 0x05, 0x76, 0x78, 0x87,
  0x77, 0x80, 0x87, 0x5f, 0x08, 0x87, 0x71, 0x18, 0x87, 0x72, 0x98, 0x87,
  0x79, 0x98, 0x81, 0x2c, 0xee, 0xf0, 0x0e, 0xee, 0xe0, 0x0e, 0xf5, 0xc0,
  0x0e, 0xec, 0x30, 0x03, 0x62, 0xc8, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xcc,
  0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xdc, 0x61, 0x1c, 0xca, 0x21, 0x1c, 0xc4,
  0x81, 0x1d, 0xca, 0x61, 0x06, 0xd6, 0x90, 0x43, 0x39, 0xc8, 0x43, 0x39,
  0x98, 0x43, 0x39, 0xc8, 0x43, 0x39, 0xb8, 0xc3, 0x38, 0x94, 0x43, 0x38,
  0x88, 0x03, 0x3b, 0x94, 0xc3, 0x2f, 0xbc, 0x83, 0x3c, 0xfc, 0x82, 0x3b,
  0xd4, 0x03, 0x3b, 0xb0, 0xc3, 0x8c, 0xcc, 0x21, 0x07, 0x7c, 0x70, 0x03,
  0x74, 0x60, 0x07, 0x37, 0x90, 0x87, 0x72, 0x98, 0x87, 0x77, 0xa8, 0x07,
  0x79, 0x18, 0x87, 0x72, 0x70, 0x83, 0x70, 0xa0, 0x07, 0x7a, 0x90, 0x87,
  0x74, 0x10, 0x87, 0x7a, 0xa0, 0x87, 0x72, 0x00, 0x00, 0x00, 0x00, 0x71,
  0x20, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x46, 0x20, 0x0d, 0x97, 0xef,
  0x3c, 0xbe, 0x10, 0x11, 0xc0, 0x44, 0x84, 0x40, 0x33, 0x2c, 0x84, 0x05,
  0x4c, 0xc3, 0xe5, 0x3b, 0x8f, 0xbf, 0x38, 0xc0, 0x20, 0x36, 0x0f, 0x35,
  0xf9, 0xc5, 0x6d, 0xdb, 0x00, 0x34, 0x5c, 0xbe, 0xf3, 0xf8, 0x12, 0xc0,
  0x3c, 0x0b, 0xe1, 0x17, 0xb7, 0x6d, 0x02, 0xd5, 0x70, 0xf9, 0xce, 0xe3,
  0x4b, 0x93, 0x13, 0x11, 0x28, 0x35, 0x3d, 0xd4, 0xe4, 0x17, 0xb7, 0x6d,
  0x00, 0x04, 0x03, 0x20, 0x0d, 0x00, 0x00, 0x61, 0x20, 0x00, 0x00, 0x3e,
  0x00, 0x00, 0x00, 0x13, 0x04, 0x41, 0x2c, 0x10, 0x00, 0x00, 0x00, 0x05,
  0x00, 0x00, 0x00, 0xf4, 0x46, 0x00, 0x88, 0xcc, 0x00, 0x14, 0x42, 0xc9,
  0x15, 0x1e, 0x95, 0x12, 0xa0, 0x31, 0x03, 0x00, 0x00, 0x00, 0x00, 0x23,
  0x06, 0x09, 0x00, 0x82, 0x60, 0x00, 0x65, 0x44, 0x73, 0x5d, 0xc7, 0x88,
  0x41, 0x02, 0x80, 0x20, 0x18, 0x40, 0x5a, 0x01, 0x61, 0x18, 0x32, 0x62,
  0x90, 0x00, 0x20, 0x08, 0x06, 0x86, 0x77, 0x58, 0xd9, 0x83, 0x8c, 0x18,
  0x24, 0x00, 0x08, 0x82, 0x81, 0xf1, 0x21, 0x97, 0x56, 0x24, 0x23, 0x06,
  0x09, 0x00, 0x82, 0x60, 0x60, 0x80, 0x41, 0xc2, 0x6d, 0x91, 0x32, 0x62,
  0x90, 0x00, 0x20, 0x08, 0x06, 0x46, 0x18, 0x28, 0x1d, 0x77, 0x2c, 0x23,
  0x06, 0x09, 0x00, 0x82, 0x60, 0x60, 0x88, 0xc1, 0xe2, 0x75, 0x12, 0x33,
  0x62, 0x90, 0x00, 0x20, 0x08, 0x06, 0xc6, 0x18, 0x30, 0x9f, 0x67, 0x35,
  0x46, 0x10, 0xf2, 0x31, 0x82, 0x90, 0x8f, 0x11, 0x84, 0x7c, 0x46, 0x0c,
  0x1e, 0x00, 0x04, 0xc1, 0xa0, 0x29, 0x03, 0x67, 0x51, 0x12, 0x84, 0x61,
  0xc4, 0x40, 0x0c, 0x22, 0x66, 0x34, 0x21, 0x00, 0x46, 0x13, 0x84, 0x60,
  0x34, 0x61, 0x10, 0x46, 0x13, 0x88, 0xc1, 0x10, 0x42, 0x3e, 0x86, 0x10,
  0xf2, 0x31, 0x84, 0x90, 0x8f, 0x11, 0x8c, 0x7c, 0x46, 0x0c, 0x12, 0x00,
  0x04, 0xc1, 0x00, 0x79, 0x03, 0x35, 0x58, 0x83, 0x35, 0x08, 0x03, 0x62,
  0xc4, 0x20, 0x01, 0x40, 0x10, 0x0c, 0x90, 0x37, 0x50, 0x83, 0x35, 0x58,
  0x03, 0x6b, 0x18, 0x31, 0x48, 0x00, 0x10, 0x04, 0x03, 0xe4, 0x0d, 0xd4,
  0x60, 0x0d, 0xd6, 0x00, 0x0c, 0x84, 0x11, 0x83, 0x04, 0x00, 0x41, 0x30,
  0x40, 0xde, 0x40, 0x0d, 0xd6, 0x60, 0x0d, 0xc6, 0x20, 0x40, 0x00, 0x00,
  0x00, 0x00, 0x00
};
#else
static unsigned char __hlsl_shader_ps_spv[] = {
  0x03, 0x02, 0x23, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x08, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0x58, 0x02, 0x00, 0x00,
  0x05, 0x00, 0x06, 0x00, 0x05, 0x00, 0x00, 0x00, 0x74, 0x79, 0x70, 0x65,
  0x2e, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x00, 0x73, 0x61, 0x6d, 0x70,
  0x6c, 0x65, 0x72, 0x30, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x06, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x74, 0x79, 0x70, 0x65, 0x2e, 0x32, 0x64, 0x2e,
  0x69, 0x6d, 0x61, 0x67, 0x65, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x30,
  0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x06, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x69, 0x6e, 0x2e, 0x76, 0x61, 0x72, 0x2e, 0x43, 0x6f, 0x6c, 0x6f, 0x72,
  0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x69, 0x6e, 0x2e, 0x76, 0x61, 0x72, 0x2e, 0x55, 0x76, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x07, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6f, 0x75, 0x74, 0x2e,
  0x76, 0x61, 0x72, 0x2e, 0x53, 0x56, 0x5f, 0x54, 0x61, 0x72, 0x67, 0x65,
  0x74, 0x30, 0x00, 0x00, 0x05, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x07, 0x00,
  0x09, 0x00, 0x00, 0x00, 0x74, 0x79, 0x70, 0x65, 0x2e, 0x73, 0x61, 0x6d,
  0x70, 0x6c, 0x65, 0x64, 0x2e, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x00, 0x00,
  0x47, 0x00, 0x04, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x1e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x47, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x47, 0x00, 0x04, 0x00, 0x08, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x02, 0x00, 0x05, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x04, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x16, 0x00, 0x03, 0x00, 0x0b, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x19, 0x00, 0x09, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x0b, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x0b, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x04, 0x00, 0x11, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x13, 0x00, 0x02, 0x00, 0x12, 0x00, 0x00, 0x00,
  0x21, 0x00, 0x03, 0x00, 0x13, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00,
  0x17, 0x00, 0x04, 0x00, 0x14, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x03, 0x00, 0x09, 0x00, 0x00, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x0a, 0x00, 0x00, 0x00,
  0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x3b, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00,
  0x11, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x36, 0x00, 0x05, 0x00, 0x12, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00,
  0x15, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00,
  0x16, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x4f, 0x00, 0x08, 0x00, 0x14, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
  0x16, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
  0x18, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x09, 0x00, 0x0d, 0x00, 0x00, 0x00,
  0x1a, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x1b, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x56, 0x00, 0x05, 0x00, 0x09, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00,
  0x1b, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x57, 0x00, 0x06, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00,
  0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x00, 0x05, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x00,
  0x1e, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x1f, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x01, 0x00, 0x38, 0x00, 0x01, 0x00
};
#endif

//-----------------------------------------------------------------------------
// FUNCTIONS
//-----------------------------------------------------------------------------

// Backend data stored in io.BackendRendererUserData to allow support for multiple Dear ImGui contexts
// It is STRONGLY preferred that you use docking branch with multi-viewports (== single Dear ImGui context + multiple windows) instead of multiple Dear ImGui contexts.
// FIXME: multi-context support is not tested and probably dysfunctional in this backend.
static ImGui_ImplRedGpu_Data* ImGui_ImplRedGpu_GetBackendData()
{
    return ImGui::GetCurrentContext() ? (ImGui_ImplRedGpu_Data*)ImGui::GetIO().BackendRendererUserData : NULL;
}

typedef enum RedHelperMemoryType {
  RED_HELPER_MEMORY_TYPE_VRAM     = 0,
  RED_HELPER_MEMORY_TYPE_UPLOAD   = 1,
  RED_HELPER_MEMORY_TYPE_READBACK = 2,
} RedHelperMemoryType;

static uint32_t ImGui_ImplRedGpu_MemoryType(const RedGpuInfo * gpuInfo, RedHelperMemoryType memoryType, uint32_t memoryTypesSupported)
{
  const uint32_t        memoryTypesCount = gpuInfo->memoryTypesCount;
  const RedMemoryType * memoryTypes      = gpuInfo->memoryTypes;

  uint32_t memoryTypeIsSupported[32];
  memoryTypeIsSupported[0]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0001)) == 0 ? 0 : 1;
  memoryTypeIsSupported[1]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0010)) == 0 ? 0 : 1;
  memoryTypeIsSupported[2]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0100)) == 0 ? 0 : 1;
  memoryTypeIsSupported[3]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,1000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[4]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0001,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[5]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0010,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[6]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0100,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[7]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,1000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[8]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0001,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[9]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0010,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[10] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0100,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[11] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,1000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[12] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0001,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[13] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0010,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[14] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0100,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[15] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,1000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[16] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0001,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[17] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0010,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[18] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0100,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[19] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,1000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[20] = (memoryTypesSupported & REDGPU_B32(0000,0000,0001,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[21] = (memoryTypesSupported & REDGPU_B32(0000,0000,0010,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[22] = (memoryTypesSupported & REDGPU_B32(0000,0000,0100,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[23] = (memoryTypesSupported & REDGPU_B32(0000,0000,1000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[24] = (memoryTypesSupported & REDGPU_B32(0000,0001,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[25] = (memoryTypesSupported & REDGPU_B32(0000,0010,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[26] = (memoryTypesSupported & REDGPU_B32(0000,0100,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[27] = (memoryTypesSupported & REDGPU_B32(0000,1000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[28] = (memoryTypesSupported & REDGPU_B32(0001,0000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[29] = (memoryTypesSupported & REDGPU_B32(0010,0000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[30] = (memoryTypesSupported & REDGPU_B32(0100,0000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[31] = (memoryTypesSupported & REDGPU_B32(1000,0000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;

  if (memoryType == RED_HELPER_MEMORY_TYPE_VRAM) {
    for (uint32_t i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isGpuVram == 1 && memoryTypeIsSupported[i] == 1) {
        return i;
      }
    }
  } else if (memoryType == RED_HELPER_MEMORY_TYPE_UPLOAD) {
    for (uint32_t i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isCpuMappable == 1 &&
          type->isCpuCoherent == 1 &&
          type->isCpuCached   == 0 && memoryTypeIsSupported[i] == 1)
      {
        return i;
      }
    }
    for (uint32_t i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isCpuMappable == 1 &&
          type->isCpuCoherent == 1 && memoryTypeIsSupported[i] == 1)
      {
        return i;
      }
    }
  } else if (memoryType == RED_HELPER_MEMORY_TYPE_READBACK) {
    for (uint32_t i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isCpuMappable == 1 &&
          type->isCpuCoherent == 1 &&
          type->isCpuCached   == 1 && memoryTypeIsSupported[i] == 1)
      {
        return i;
      }
    }
    for (uint32_t i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isCpuMappable == 1 &&
          type->isCpuCoherent == 1 && memoryTypeIsSupported[i] == 1)
      {
        return i;
      }
    }
  }

  return -1;
}

static void CreateOrResizeBuffer(RedArray * buffer_ptr, RedHandleMemory * buffer_memory_ptr, size_t new_size, bool isIndexBuffer)
{
    IM_ASSERT(buffer_ptr != NULL);
    IM_ASSERT(buffer_memory_ptr != NULL);

    RedArray buffer = buffer_ptr[0];
    RedHandleMemory buffer_memory = buffer_memory_ptr[0];

    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    ImGui_ImplRedGpu_InitInfo* v = &bd->RedGpuInitInfo;

    if (buffer.handle != NULL)
    {
        redDestroyArray(v->Instance, v->Device, buffer.handle, __FILE__, __LINE__, NULL);
        RedArray defaults = {};
        buffer = defaults;
    }
    if (buffer_memory != NULL)
    {
        redMemoryFree(v->Instance, v->Device, buffer_memory, __FILE__, __LINE__, NULL);
        buffer_memory = NULL;
    }

    uint64_t buffer_size_aligned = ((new_size - 1) / bd->BufferMemoryAlignment + 1) * bd->BufferMemoryAlignment;

    redCreateArray(v->Instance, v->Device, NULL, isIndexBuffer == true ? RED_ARRAY_TYPE_INDEX_RO : RED_ARRAY_TYPE_ARRAY_RO, buffer_size_aligned, 0, 0, 0, 0, &buffer, NULL, __FILE__, __LINE__, NULL);

    bd->BufferMemoryAlignment = (bd->BufferMemoryAlignment > buffer.memoryBytesAlignment) ? bd->BufferMemoryAlignment : buffer.memoryBytesAlignment;

    redMemoryAllocateMappable(v->Instance, v->Device, NULL, 0, buffer.handle, buffer.memoryBytesCount, ImGui_ImplRedGpu_MemoryType(&v->Instance->gpus[v->DeviceIndex], RED_HELPER_MEMORY_TYPE_UPLOAD, buffer.memoryTypesSupported), 0, &buffer_memory, NULL, __FILE__, __LINE__, NULL);

    RedMemoryArray memoryArray = {};
    memoryArray.setTo1000157000  = 1000157000;
    memoryArray.setTo0           = 0;
    memoryArray.array            = buffer.handle;
    memoryArray.memory           = buffer_memory;
    memoryArray.memoryBytesFirst = 0;
    redMemorySet(v->Instance, v->Device, 1, &memoryArray, 0, NULL, NULL, __FILE__, __LINE__, NULL);

    buffer_ptr[0] = buffer;
    buffer_memory_ptr[0] = buffer_memory;
}

static void ImGui_ImplRedGpu_SetupRenderState(ImDrawData* draw_data, RedHandleProcedure pipeline, RedHandleCalls command_buffer, ImGui_ImplRedGpuH_FrameRenderBuffers* rb, int fb_width, int fb_height)
{
    IM_ASSERT(sizeof(ImDrawIdx) == 4);

    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    ImGui_ImplRedGpu_InitInfo* v = &bd->RedGpuInitInfo;

    RedCallProceduresAndAddresses cpa;
    redGetCallProceduresAndAddresses(v->Instance, v->Device, &cpa, NULL, __FILE__, __LINE__, NULL);

    // Bind pipeline:
    {
        cpa.redCallSetProcedure(command_buffer, RED_PROCEDURE_TYPE_DRAW, pipeline);
        redCallSetProcedureParameters(cpa.redCallSetProcedureParameters, command_buffer, RED_PROCEDURE_TYPE_DRAW, bd->PipelineLayout);
    }

    // Bind Vertex And Index Buffer:
    if (draw_data->TotalVtxCount > 0)
    {
        RedProcedureParametersHandleArray parametersHandleArray = {};
        parametersHandleArray.array         = rb->VertexBuffer.handle;
        parametersHandleArray.setTo0        = 0;
        parametersHandleArray.setToMaxValue = -1;
        RedProcedureParametersHandle parametersHandle = {};
        parametersHandle.setTo35    = 35;
        parametersHandle.setTo0     = 0;
        parametersHandle.setTo00    = 0;
        parametersHandle.slot       = 2;
        parametersHandle.setTo000   = 0;
        parametersHandle.setTo1     = 1;
        parametersHandle.type       = RED_PROCEDURE_PARAMETERS_HANDLE_TYPE_ARRAY_RO_RW;
        parametersHandle.setTo0000  = 0;
        parametersHandle.array      = &parametersHandleArray;
        parametersHandle.setTo00000 = 0;
        cpa.redCallSetProcedureParametersHandles(command_buffer, RED_PROCEDURE_TYPE_DRAW, bd->PipelineLayout, 1, 1, &parametersHandle);
        cpa.redCallSetProcedureIndices(command_buffer, rb->IndexBuffer.handle, 0, 1);
    }

    // Setup viewport:
    {
        redCallSetDynamicViewport(cpa.redCallSetDynamicViewport, command_buffer, 0, 0, (float)fb_width, (float)fb_height, 0.0f, 1.0f);
    }

    // Setup scale and translation:
    // Our visible imgui space lies from draw_data->DisplayPos (top left) to draw_data->DisplayPos+data_data->DisplaySize (bottom right). DisplayPos is (0,0) for single viewport apps.
    {
        float scale[2];
        scale[0] = 2.0f / draw_data->DisplaySize.x;
        scale[1] = 2.0f / draw_data->DisplaySize.y;
        float translate[2];
        translate[0] = -1.0f - draw_data->DisplayPos.x * scale[0];
        translate[1] = -1.0f - draw_data->DisplayPos.y * scale[1];
        cpa.redCallSetProcedureParametersVariables(command_buffer, bd->PipelineLayout, RED_VISIBLE_TO_STAGE_BITFLAG_VERTEX, sizeof(float) * 0, sizeof(float) * 2, scale);
        cpa.redCallSetProcedureParametersVariables(command_buffer, bd->PipelineLayout, RED_VISIBLE_TO_STAGE_BITFLAG_VERTEX, sizeof(float) * 2, sizeof(float) * 2, translate);
    }
}

// Render function
void ImGui_ImplRedGpu_RenderDrawData(ImDrawData* draw_data, RedHandleCalls command_buffer, RedHandleProcedure pipeline)
{
    // Avoid rendering when minimized, scale coordinates for retina displays (screen coordinates != framebuffer coordinates)
    int fb_width  = (int)(draw_data->DisplaySize.x * draw_data->FramebufferScale.x);
    int fb_height = (int)(draw_data->DisplaySize.y * draw_data->FramebufferScale.y);
    if (fb_width <= 0 || fb_height <= 0)
        return;

    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    ImGui_ImplRedGpu_InitInfo* v = &bd->RedGpuInitInfo;
    if (pipeline == NULL)
        pipeline = bd->Pipeline;

    // Allocate array to store enough vertex/index buffers
    ImGui_ImplRedGpuH_WindowRenderBuffers* wrb = &bd->MainWindowRenderBuffers;
    if (wrb->FrameRenderBuffers == NULL)
    {
        wrb->Index = 0;
        wrb->Count = v->ImageCount;
        wrb->FrameRenderBuffers = (ImGui_ImplRedGpuH_FrameRenderBuffers*)IM_ALLOC(sizeof(ImGui_ImplRedGpuH_FrameRenderBuffers) * wrb->Count);
        memset(wrb->FrameRenderBuffers, 0, sizeof(ImGui_ImplRedGpuH_FrameRenderBuffers) * wrb->Count);
    }
    IM_ASSERT(wrb->Count == v->ImageCount);
    wrb->Index = (wrb->Index + 1) % wrb->Count;
    ImGui_ImplRedGpuH_FrameRenderBuffers* rb = &wrb->FrameRenderBuffers[wrb->Index];

    if (draw_data->TotalVtxCount > 0)
    {
        // Create or resize the vertex/index buffers
        size_t vertex_size = draw_data->TotalVtxCount * sizeof(ImDrawVert);
        size_t index_size  = draw_data->TotalIdxCount * sizeof(ImDrawIdx);
        if (rb->VertexBuffer.handle == NULL || rb->VertexBuffer.memoryBytesCount < vertex_size)
            CreateOrResizeBuffer(&rb->VertexBuffer, &rb->VertexBufferMemory, vertex_size, false);
        if (rb->IndexBuffer.handle == NULL || rb->IndexBuffer.memoryBytesCount < index_size)
            CreateOrResizeBuffer(&rb->IndexBuffer, &rb->IndexBufferMemory, index_size, true);

        // Upload vertex/index data into a single contiguous GPU buffer
        volatile ImDrawVert* vtx_dst = NULL;
        volatile ImDrawIdx*  idx_dst = NULL;
        redMemoryMap(v->Instance, v->Device, rb->VertexBufferMemory, 0, rb->VertexBuffer.memoryBytesCount, (void **)&vtx_dst, NULL, __FILE__, __LINE__, NULL);
        redMemoryMap(v->Instance, v->Device, rb->IndexBufferMemory,  0, rb->IndexBuffer.memoryBytesCount,  (void **)&idx_dst, NULL, __FILE__, __LINE__, NULL);
        for (int n = 0; n < draw_data->CmdListsCount; n++)
        {
            const ImDrawList* cmd_list = draw_data->CmdLists[n];
            memcpy((void *)vtx_dst, cmd_list->VtxBuffer.Data, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert));
            memcpy((void *)idx_dst, cmd_list->IdxBuffer.Data, cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx));
            vtx_dst += cmd_list->VtxBuffer.Size;
            idx_dst += cmd_list->IdxBuffer.Size;
        }
        RedMappableMemoryRange ranges[2] = {};
        ranges[0].setTo6                        = 6;
        ranges[0].setTo0                        = 0;
        ranges[0].mappableMemory                = rb->VertexBufferMemory;
        ranges[0].mappableMemoryRangeBytesFirst = 0;
        ranges[0].mappableMemoryRangeBytesCount = -1;
        ranges[1].setTo6                        = 6;
        ranges[1].setTo0                        = 0;
        ranges[1].mappableMemory                = rb->IndexBufferMemory;
        ranges[1].mappableMemoryRangeBytesFirst = 0;
        ranges[1].mappableMemoryRangeBytesCount = -1;
        redMemoryNonCoherentFlush(v->Instance, v->Device, 2, ranges, NULL, __FILE__, __LINE__, NULL);
        redMemoryUnmap(v->Instance, v->Device, rb->VertexBufferMemory, __FILE__, __LINE__, NULL);
        redMemoryUnmap(v->Instance, v->Device, rb->IndexBufferMemory,  __FILE__, __LINE__, NULL);
        vtx_dst = NULL;
        idx_dst = NULL;
    }

    // Setup desired RedGpu state
    ImGui_ImplRedGpu_SetupRenderState(draw_data, pipeline, command_buffer, rb, fb_width, fb_height);

    // Will project scissor/clipping rectangles into framebuffer space
    ImVec2 clip_off   = draw_data->DisplayPos;       // (0,0) unless using multi-viewports
    ImVec2 clip_scale = draw_data->FramebufferScale; // (1,1) unless using retina display which are often (2,2)

    RedCallProceduresAndAddresses cpa;
    redGetCallProceduresAndAddresses(v->Instance, v->Device, &cpa, NULL, __FILE__, __LINE__, NULL);

    // Render command lists
    // (Because we merged all buffers into a single one, we maintain our own offset into them)
    int global_vtx_offset = 0;
    int global_idx_offset = 0;
    for (int n = 0; n < draw_data->CmdListsCount; n++)
    {
        const ImDrawList* cmd_list = draw_data->CmdLists[n];
        for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++)
        {
            const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
            if (pcmd->UserCallback != NULL)
            {
                // User callback, registered via ImDrawList::AddCallback()
                // (ImDrawCallback_ResetRenderState is a special callback value used by the user to request the renderer to reset render state.)
                if (pcmd->UserCallback == ImDrawCallback_ResetRenderState)
                    ImGui_ImplRedGpu_SetupRenderState(draw_data, pipeline, command_buffer, rb, fb_width, fb_height);
                else
                    pcmd->UserCallback(cmd_list, pcmd);
            }
            else
            {
                // Project scissor/clipping rectangles into framebuffer space
                ImVec2 clip_min((pcmd->ClipRect.x - clip_off.x) * clip_scale.x, (pcmd->ClipRect.y - clip_off.y) * clip_scale.y);
                ImVec2 clip_max((pcmd->ClipRect.z - clip_off.x) * clip_scale.x, (pcmd->ClipRect.w - clip_off.y) * clip_scale.y);

                // Clamp to viewport as redCallSetDynamicScissor() won't accept values that are off bounds
                if (clip_min.x < 0.0f) { clip_min.x = 0.0f; }
                if (clip_min.y < 0.0f) { clip_min.y = 0.0f; }
                if (clip_max.x > fb_width)  { clip_max.x = (float)fb_width;  }
                if (clip_max.y > fb_height) { clip_max.y = (float)fb_height; }
                if (clip_max.x <= clip_min.x || clip_max.y <= clip_min.y)
                    continue;

                // Apply scissor/clipping rectangle
                redCallSetDynamicScissor(cpa.redCallSetDynamicScissor, command_buffer, (int32_t)(clip_min.x), (int32_t)(clip_min.y), (uint32_t)(clip_max.x - clip_min.x), (uint32_t)(clip_max.y - clip_min.y));

                // Bind DescriptorSet with font or user texture
                RedHandleStruct desc_sets[1] = { (RedHandleStruct)pcmd->TextureId };
                if (sizeof(ImTextureID) < sizeof(ImU64))
                {
                    // We don't support texture switches if ImTextureID hasn't been redefined to be 64-bit. Do a flaky check that other textures haven't been used.
                    IM_ASSERT(pcmd->TextureId == (ImTextureID)bd->FontDescriptorSet);
                    desc_sets[0] = bd->FontDescriptorSet;
                }
                redCallSetStructsMemory(cpa.redCallSetStructsMemory, command_buffer, v->DescriptorPool, v->DescriptorPoolSamplers);
                cpa.redCallSetProcedureParametersStructs(command_buffer, RED_PROCEDURE_TYPE_DRAW, bd->PipelineLayout, 0, 1, desc_sets, 0, 0);

                // Draw
                int offsets[2];
                offsets[0] = pcmd->IdxOffset + global_idx_offset;
                offsets[1] = pcmd->VtxOffset + global_vtx_offset;
                cpa.redCallSetProcedureParametersVariables(command_buffer, bd->PipelineLayout, RED_VISIBLE_TO_STAGE_BITFLAG_VERTEX, sizeof(float) * 4, sizeof(int) * 2, offsets);
                cpa.redCallProcedureIndexed(command_buffer, pcmd->ElemCount, 1, pcmd->IdxOffset + global_idx_offset, 0, 0);
            }
        }
        global_idx_offset += cmd_list->IdxBuffer.Size;
        global_vtx_offset += cmd_list->VtxBuffer.Size;
    }

    // Note: at this point both redCallSetDynamicViewport() and redCallSetDynamicScissor() have been called.
    // Our last values will leak into user/application rendering IF:
    // - Your app uses a pipeline with RedProcedureState::viewportDynamic or RedProcedureState::scissorDynamic dynamic state
    // - And you forgot to call redCallSetDynamicViewport() and redCallSetDynamicScissor() yourself to explicitely set that state.
    // If you use RedProcedureState::viewportDynamic or RedProcedureState::scissorDynamic you are responsible for setting the values before rendering.
    // In theory we should aim to backup/restore those values but I am not sure this is possible.
    // We perform a call to redCallSetDynamicScissor() to set back a full viewport which is likely to fix things for 99% users but technically this is not perfect. (See github #4644)
    redCallSetDynamicScissor(cpa.redCallSetDynamicScissor, command_buffer, 0, 0, (uint32_t)fb_width, (uint32_t)fb_height);
}

bool ImGui_ImplRedGpu_CreateFontsTexture(RedHandleCalls command_buffer)
{
    ImGuiIO& io = ImGui::GetIO();
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    ImGui_ImplRedGpu_InitInfo* v = &bd->RedGpuInitInfo;

    RedCallProceduresAndAddresses cpa;
    redGetCallProceduresAndAddresses(v->Instance, v->Device, &cpa, NULL, __FILE__, __LINE__, NULL);

    unsigned char* pixels;
    int width, height;
    io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
    size_t upload_size = width * height * 4 * sizeof(char);

    // Destroy previous image view, image and image memory:
    {
        if (bd->FontView != NULL) {
            redDestroyTexture(v->Instance, v->Device, bd->FontView, __FILE__, __LINE__, NULL);
            bd->FontView = NULL;
        }
        if (bd->FontImage.handle != NULL) {
            redDestroyImage(v->Instance, v->Device, bd->FontImage.handle, __FILE__, __LINE__, NULL);
            RedImage defaults = {};
            bd->FontImage = defaults;
        }
        if (bd->FontMemory != NULL) {
            redMemoryFree(v->Instance, v->Device, bd->FontMemory, __FILE__, __LINE__, NULL);
            bd->FontMemory = NULL;
        }
    }

    // Create the Image:
    {
#ifdef REDGPU_USE_REDGPU_X
        redXCreateImage(v->Instance, v->Device, NULL, RED_IMAGE_DIMENSIONS_2D, RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED, RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1, width, height, 1, 1, 1, RED_MULTISAMPLE_COUNT_BITFLAG_1, 0, 0, 0, 0, &bd->FontImage, NULL, __FILE__, __LINE__, NULL);
#else
        redCreateImage(v->Instance, v->Device, NULL, RED_IMAGE_DIMENSIONS_2D, RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED, width, height, 1, 1, 1, RED_MULTISAMPLE_COUNT_BITFLAG_1, 0, 0, 0, 0, &bd->FontImage, NULL, __FILE__, __LINE__, NULL);
#endif
        redMemoryAllocate(v->Instance, v->Device, NULL, bd->FontImage.memoryBytesCount, ImGui_ImplRedGpu_MemoryType(&v->Instance->gpus[v->DeviceIndex], RED_HELPER_MEMORY_TYPE_VRAM, bd->FontImage.memoryTypesSupported), 0, 0, 0, &bd->FontMemory, NULL, __FILE__, __LINE__, NULL);
        RedMemoryImage memoryImage = {};
        memoryImage.setTo1000157001  = 1000157001;
        memoryImage.setTo0           = 0;
        memoryImage.image            = bd->FontImage.handle;
        memoryImage.memory           = bd->FontMemory;
        memoryImage.memoryBytesFirst = 0;
        redMemorySet(v->Instance, v->Device, 0, NULL, 1, &memoryImage, NULL, __FILE__, __LINE__, NULL);
    }

    // Create the Image View:
    {
        redCreateTexture(v->Instance, v->Device, NULL, bd->FontImage.handle, RED_IMAGE_PART_BITFLAG_COLOR, RED_TEXTURE_DIMENSIONS_2D, RED_FORMAT_RGBA_8_8_8_8_UINT_TO_FLOAT_0_1_GAMMA_CORRECTED, 0, 1, 0, 1, 0, &bd->FontView, NULL, __FILE__, __LINE__, NULL);
    }

    // Create the Descriptor Set:
    bd->FontDescriptorSet = (RedHandleStruct)ImGui_ImplRedGpu_AddTexture(bd->FontSampler, bd->FontView);

    // Create the Upload Buffer:
    {
        redCreateArray(v->Instance, v->Device, NULL, RED_ARRAY_TYPE_ARRAY_RO, upload_size, 0, 0, 0, 0, &bd->UploadBuffer, NULL, __FILE__, __LINE__, NULL);

        bd->BufferMemoryAlignment = (bd->BufferMemoryAlignment > bd->UploadBuffer.memoryBytesAlignment) ? bd->BufferMemoryAlignment : bd->UploadBuffer.memoryBytesAlignment;

        redMemoryAllocateMappable(v->Instance, v->Device, NULL, 0, bd->UploadBuffer.handle, bd->UploadBuffer.memoryBytesCount, ImGui_ImplRedGpu_MemoryType(&v->Instance->gpus[v->DeviceIndex], RED_HELPER_MEMORY_TYPE_UPLOAD, bd->UploadBuffer.memoryTypesSupported), 0, &bd->UploadBufferMemory, NULL, __FILE__, __LINE__, NULL);

        RedMemoryArray memoryArray = {};
        memoryArray.setTo1000157000  = 1000157000;
        memoryArray.setTo0           = 0;
        memoryArray.array            = bd->UploadBuffer.handle;
        memoryArray.memory           = bd->UploadBufferMemory;
        memoryArray.memoryBytesFirst = 0;
        redMemorySet(v->Instance, v->Device, 1, &memoryArray, 0, NULL, NULL, __FILE__, __LINE__, NULL);
    }

    // Upload to Buffer:
    {
        char* map = NULL;
        redMemoryMap(v->Instance, v->Device, bd->UploadBufferMemory, 0, upload_size, (void **)&map, NULL, __FILE__, __LINE__, NULL);

        memcpy(map, pixels, upload_size);

        RedMappableMemoryRange ranges[1] = {};
        ranges[0].setTo6                        = 6;
        ranges[0].setTo0                        = 0;
        ranges[0].mappableMemory                = bd->UploadBufferMemory;
        ranges[0].mappableMemoryRangeBytesFirst = 0;
        ranges[0].mappableMemoryRangeBytesCount = -1;
        redMemoryNonCoherentFlush(v->Instance, v->Device, 1, ranges, NULL, __FILE__, __LINE__, NULL);

        redMemoryUnmap(v->Instance, v->Device, bd->UploadBufferMemory, __FILE__, __LINE__, NULL);
        map = NULL;
    }

    // Copy to Image:
    {
#ifdef REDGPU_USE_REDGPU_X
        RedXBarrier copy_barrier[1] = {};
        copy_barrier[0].usage.setTo0      = 0;
        copy_barrier[0].usage.split       = RED_BARRIER_SPLIT_NONE;
        copy_barrier[0].usage.resource    = redXGetHandleResourceImage(v->Instance, v->Device, bd->FontImage.handle);
        copy_barrier[0].usage.level       = -1;
        copy_barrier[0].usage.oldAccesses = REDX_ACCESS_BITFLAG_COMMON;
        copy_barrier[0].usage.newAccesses = REDX_ACCESS_BITFLAG_COPY_W;
        redXCallUsageAliasOrderBarrier(command_buffer, 1, copy_barrier);
#else
        RedUsageImage copy_barrier[1] = {};
        copy_barrier[0].barrierSplit           = RED_BARRIER_SPLIT_NONE;
        copy_barrier[0].oldAccessStages        = 0;
        copy_barrier[0].newAccessStages        = RED_ACCESS_STAGE_BITFLAG_COPY;
        copy_barrier[0].oldAccess              = 0;
        copy_barrier[0].newAccess              = RED_ACCESS_BITFLAG_COPY_W;
        copy_barrier[0].oldState               = RED_STATE_UNUSABLE;
        copy_barrier[0].newState               = RED_STATE_USABLE;
        copy_barrier[0].queueFamilyIndexSource = -1;
        copy_barrier[0].queueFamilyIndexTarget = -1;
        copy_barrier[0].image                  = bd->FontImage.handle;
        copy_barrier[0].imageAllParts          = RED_IMAGE_PART_BITFLAG_COLOR;
        copy_barrier[0].imageLevelsFirst       = 0;
        copy_barrier[0].imageLevelsCount       = 1;
        copy_barrier[0].imageLayersFirst       = 0;
        copy_barrier[0].imageLayersCount       = 1;
        redCallUsageAliasOrderBarrier(cpa.redCallUsageAliasOrderBarrier, command_buffer, v->Instance, 0, NULL, 1, copy_barrier, 0, NULL, 0, NULL, 0);
#endif

#ifdef REDGPU_USE_REDGPU_X
        {
          struct SubresourceFootprint {
            unsigned xformat;
            unsigned width;
            unsigned height;
            unsigned depth;
            unsigned rowPitch;
          };
          struct PlacedSubresourceFootprint {
            uint64_t                    offset;
            struct SubresourceFootprint footprint;
          };
          struct CopyImageLocation {
            void *   resource;
            unsigned typeSubresourceIndexOrPlacedFootprint;
            union {
              struct PlacedSubresourceFootprint placedFootprint;
              unsigned                          subresourceIndex;
            };
          };
          struct CopyImageRegionBox {
            unsigned left;
            unsigned top;
            unsigned front;
            unsigned right;
            unsigned bottom;
            unsigned back;
          };
          struct CopyImageRegion {
            const CopyImageLocation *  target;
            unsigned                   targetX;
            unsigned                   targetY;
            unsigned                   targetZ;
            const CopyImageLocation *  source;
            const CopyImageRegionBox * sourceBox;
          };
          struct CopyImageRegion   copy       = {};
          struct CopyImageLocation copyTarget = {};
          struct CopyImageLocation copySource = {};
          copyTarget.resource                              = redXGetHandleResourceImage(v->Instance, v->Device, bd->FontImage.handle);
          copyTarget.typeSubresourceIndexOrPlacedFootprint = 0;
          copyTarget.subresourceIndex                      = 0;
          copySource.resource                              = redXGetHandleResourceArray(v->Instance, v->Device, bd->UploadBuffer.handle);
          copySource.typeSubresourceIndexOrPlacedFootprint = 1;
          copySource.placedFootprint.offset                = 0;
          copySource.placedFootprint.footprint.xformat     = 28; // DXGI_FORMAT_R8G8B8A8_UNORM
          copySource.placedFootprint.footprint.width       = width;
          copySource.placedFootprint.footprint.height      = height;
          copySource.placedFootprint.footprint.depth       = 1;
          copySource.placedFootprint.footprint.rowPitch    = upload_size / height;
          copy.target    = &copyTarget;
          copy.targetX   = 0;
          copy.targetY   = 0;
          copy.targetZ   = 0;
          copy.source    = &copySource;
          copy.sourceBox = NULL;
          redXCallCopyImageRegion(command_buffer, 1, &copy);
        }
#else
        RedCopyArrayImageRange copyRange        = {};
        copyRange.arrayBytesFirst               = 0;
        copyRange.arrayTexelsCountToNextRow     = 0;
        copyRange.arrayTexelsCountToNextLayerOr3DDepthSliceDividedByTexelsCountToNextRow = 0;
        copyRange.imageParts.allParts           = RED_IMAGE_PART_BITFLAG_COLOR;
        copyRange.imageParts.level              = 0;
        copyRange.imageParts.layersFirst        = 0;
        copyRange.imageParts.layersCount        = 1;
        copyRange.imageOffset.texelX            = 0;
        copyRange.imageOffset.texelY            = 0;
        copyRange.imageOffset.texelZ            = 0;
        copyRange.imageExtent.texelsCountWidth  = width;
        copyRange.imageExtent.texelsCountHeight = height;
        copyRange.imageExtent.texelsCountDepth  = 1;
        cpa.redCallCopyArrayToImage(command_buffer, bd->UploadBuffer.handle, bd->FontImage.handle, 1, 1, &copyRange);
#endif

#ifdef REDGPU_USE_REDGPU_X
        RedXBarrier use_barrier[1] = {};
        use_barrier[0].usage.setTo0      = 0;
        use_barrier[0].usage.split       = RED_BARRIER_SPLIT_NONE;
        use_barrier[0].usage.resource    = redXGetHandleResourceImage(v->Instance, v->Device, bd->FontImage.handle);
        use_barrier[0].usage.level       = -1;
        use_barrier[0].usage.oldAccesses = REDX_ACCESS_BITFLAG_COPY_W;
        use_barrier[0].usage.newAccesses = REDX_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R;
        redXCallUsageAliasOrderBarrier(command_buffer, 1, use_barrier);
#else
        RedUsageImage use_barrier[1] = {};
        use_barrier[0].barrierSplit           = RED_BARRIER_SPLIT_NONE;
        use_barrier[0].oldAccessStages        = RED_ACCESS_STAGE_BITFLAG_COPY;
        use_barrier[0].newAccessStages        = RED_ACCESS_STAGE_BITFLAG_FRAGMENT;
        use_barrier[0].oldAccess              = RED_ACCESS_BITFLAG_COPY_W;
        use_barrier[0].newAccess              = RED_ACCESS_BITFLAG_STRUCT_RESOURCE_FRAGMENT_STAGE_R;
        use_barrier[0].oldState               = RED_STATE_USABLE;
        use_barrier[0].newState               = RED_STATE_USABLE;
        use_barrier[0].queueFamilyIndexSource = -1;
        use_barrier[0].queueFamilyIndexTarget = -1;
        use_barrier[0].image                  = bd->FontImage.handle;
        use_barrier[0].imageAllParts          = RED_IMAGE_PART_BITFLAG_COLOR;
        use_barrier[0].imageLevelsFirst       = 0;
        use_barrier[0].imageLevelsCount       = 1;
        use_barrier[0].imageLayersFirst       = 0;
        use_barrier[0].imageLayersCount       = 1;
        redCallUsageAliasOrderBarrier(cpa.redCallUsageAliasOrderBarrier, command_buffer, v->Instance, 0, NULL, 1, use_barrier, 0, NULL, 0, NULL, 0);
#endif
    }

    // Store our identifier
    io.Fonts->SetTexID((ImTextureID)bd->FontDescriptorSet);

    return true;
}

static void ImGui_ImplRedGpu_CreateShaderModules(RedContext instance, uint32_t deviceIndex, RedHandleGpu device)
{
    // Create the shader modules
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    if (bd->ShaderModuleVert == NULL)
    {
        redCreateGpuCode(instance, device, NULL,  sizeof(__hlsl_shader_vs_spv), __hlsl_shader_vs_spv, &bd->ShaderModuleVert, NULL, __FILE__, __LINE__, NULL);
    }
    if (bd->ShaderModuleFrag == NULL)
    {
        redCreateGpuCode(instance, device, NULL,  sizeof(__hlsl_shader_ps_spv), __hlsl_shader_ps_spv, &bd->ShaderModuleFrag, NULL, __FILE__, __LINE__, NULL);
    }
}

static void ImGui_ImplRedGpu_CreateFontSampler(RedContext instance, uint32_t deviceIndex, RedHandleGpu device)
{
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    if (bd->FontSampler)
        return;

    // Bilinear sampling is required by default. Set 'io.Fonts->Flags |= ImFontAtlasFlags_NoBakedLines' or 'style.AntiAliasedLinesUseTex = false' to allow point/nearest sampling.
    redCreateSampler(instance, device, NULL, RED_SAMPLER_FILTERING_LINEAR, RED_SAMPLER_FILTERING_LINEAR, RED_SAMPLER_FILTERING_MIP_LINEAR, RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT, RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT, RED_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT, 0.0f, 0, 1.0f, 0, RED_COMPARE_OP_NEVER, -1000.0f, 1000.0f, &bd->FontSampler, NULL, __FILE__, __LINE__, NULL);
}

static void ImGui_ImplRedGpu_CreateDescriptorSetLayouts(RedContext instance, uint32_t deviceIndex, RedHandleGpu device)
{
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    if (bd->SamplerDescriptorSetLayout == NULL)
    {
    }
    if (bd->DescriptorSetLayout == NULL)
    {
        RedStructDeclarationMember members[2];
        members[0].slot            = 0;
        members[0].type            = RED_STRUCT_MEMBER_TYPE_SAMPLER;
        members[0].count           = 1;
        members[0].visibleToStages = RED_VISIBLE_TO_STAGE_BITFLAG_FRAGMENT;
        members[0].inlineSampler   = &bd->FontSampler; // NOTE(Constantine): Using a static sampler.
        members[1].slot            = 1;
        members[1].type            = RED_STRUCT_MEMBER_TYPE_TEXTURE_RO;
        members[1].count           = 1;
        members[1].visibleToStages = RED_VISIBLE_TO_STAGE_BITFLAG_FRAGMENT;
        members[1].inlineSampler   = NULL;
        redCreateStructDeclaration(instance, device, NULL, 2, members, 0, NULL, 0, &bd->DescriptorSetLayout, NULL, __FILE__, __LINE__, NULL);
    }
    if (bd->ImdrawvertsDescriptorSetLayout == NULL)
    {
        RedStructDeclarationMember member;
        member.slot            = 2;
        member.type            = REDX_STRUCT_MEMBER_TYPE_ARRAY_RO;
        member.count           = 1;
        member.visibleToStages = RED_VISIBLE_TO_STAGE_BITFLAG_VERTEX;
        member.inlineSampler   = NULL;
        RedStructDeclarationMemberArrayRO memberRO;
        memberRO.slot = 2;
        redCreateStructDeclaration(instance, device, NULL, 1, &member, 1, &memberRO, 1, &bd->ImdrawvertsDescriptorSetLayout, NULL, __FILE__, __LINE__, NULL);
    }
}

static void ImGui_ImplRedGpu_CreatePipelineLayout(RedContext instance, uint32_t deviceIndex, RedHandleGpu device)
{
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    if (bd->PipelineLayout)
        return;

    // Constants: we are using 'vec2 offset' and 'vec2 scale' instead of a full 3d projection matrix
    ImGui_ImplRedGpu_CreateDescriptorSetLayouts(instance, deviceIndex, device);

    RedProcedureParametersDeclaration parametersDeclaration = {};
    parametersDeclaration.variablesSlot            = 3;
    parametersDeclaration.variablesVisibleToStages = RED_VISIBLE_TO_STAGE_BITFLAG_VERTEX;
    parametersDeclaration.variablesBytesCount      = sizeof(float) * 6;
    parametersDeclaration.structsDeclarationsCount = 1;
    parametersDeclaration.structsDeclarations[0]   = bd->DescriptorSetLayout;
    parametersDeclaration.structsDeclarations[1]   = NULL;
    parametersDeclaration.structsDeclarations[2]   = NULL;
    parametersDeclaration.structsDeclarations[3]   = NULL;
    parametersDeclaration.structsDeclarations[4]   = NULL;
    parametersDeclaration.structsDeclarations[5]   = NULL;
    parametersDeclaration.structsDeclarations[6]   = NULL;
    parametersDeclaration.handlesDeclaration       = bd->ImdrawvertsDescriptorSetLayout;
    redCreateProcedureParameters(instance, device, NULL, &parametersDeclaration, &bd->PipelineLayout, NULL, __FILE__, __LINE__, NULL);
}

static void ImGui_ImplRedGpu_CreatePipeline(RedContext instance, uint32_t deviceIndex, RedHandleGpu device, RedHandleProcedureCache pipelineCache, RedHandleOutputDeclaration renderPass, RedMultisampleCountBitflag MSAASamples, RedHandleProcedure * pipeline, uint32_t subpass)
{
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    ImGui_ImplRedGpu_CreateShaderModules(instance, deviceIndex, device);

    ImGui_ImplRedGpu_CreatePipelineLayout(instance, deviceIndex, device);

    RedProcedureState state = {};
    state.inputAssemblyTopology                          = RED_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
    state.inputAssemblyPrimitiveRestartEnable            = 0;
    state.viewportDynamic                                = 1;
    state.viewportStaticX                                = 0;
    state.viewportStaticY                                = 0;
    state.viewportStaticWidth                            = 0;
    state.viewportStaticHeight                           = 0;
    state.viewportStaticDepthMin                         = 0;
    state.viewportStaticDepthMax                         = 0;
    state.scissorDynamic                                 = 1;
    state.scissorStaticX                                 = 0;
    state.scissorStaticY                                 = 0;
    state.scissorStaticWidth                             = 0;
    state.scissorStaticHeight                            = 0;
    state.rasterizationDepthClampEnable                  = 0;
    state.rasterizationDiscardAllPrimitivesEnable        = 0;
    state.rasterizationCullMode                          = RED_CULL_MODE_NONE;
    state.rasterizationFrontFace                         = RED_FRONT_FACE_COUNTER_CLOCKWISE;
    state.rasterizationDepthBiasEnable                   = 0;
    state.rasterizationDepthBiasDynamic                  = 0;
    state.rasterizationDepthBiasStaticConstantFactor     = 0;
    state.rasterizationDepthBiasStaticClamp              = 0;
    state.rasterizationDepthBiasStaticSlopeFactor        = 0;
    state.multisampleCount                               = (MSAASamples != 0) ? MSAASamples : RED_MULTISAMPLE_COUNT_BITFLAG_1;
    state.multisampleSampleMask                          = NULL;
    state.multisampleSampleShadingEnable                 = 0;
    state.multisampleSampleShadingMin                    = 0;
    state.multisampleAlphaToCoverageEnable               = 0;
    state.multisampleAlphaToOneEnable                    = 0;
    state.depthTestEnable                                = 0;
    state.depthTestDepthWriteEnable                      = 0;
    state.depthTestDepthCompareOp                        = RED_COMPARE_OP_GREATER_OR_EQUAL;
    state.depthTestBoundsTestEnable                      = 0;
    state.depthTestBoundsTestDynamic                     = 0;
    state.depthTestBoundsTestStaticMin                   = 0;
    state.depthTestBoundsTestStaticMax                   = 1;
    state.stencilTestEnable                              = 0;
    state.stencilTestFrontAndBackDynamicCompareMask      = 0;
    state.stencilTestFrontAndBackDynamicWriteMask        = 0;
    state.stencilTestFrontAndBackDynamicReference        = 0;
    state.stencilTestFrontStencilTestFailOp              = RED_STENCIL_OP_KEEP;
    state.stencilTestFrontStencilTestPassDepthTestPassOp = RED_STENCIL_OP_KEEP;
    state.stencilTestFrontStencilTestPassDepthTestFailOp = RED_STENCIL_OP_KEEP;
    state.stencilTestFrontCompareOp                      = RED_COMPARE_OP_NEVER;
    state.stencilTestBackStencilTestFailOp               = RED_STENCIL_OP_KEEP;
    state.stencilTestBackStencilTestPassDepthTestPassOp  = RED_STENCIL_OP_KEEP;
    state.stencilTestBackStencilTestPassDepthTestFailOp  = RED_STENCIL_OP_KEEP;
    state.stencilTestBackCompareOp                       = RED_COMPARE_OP_NEVER;
    state.stencilTestFrontAndBackStaticCompareMask       = 0;
    state.stencilTestFrontAndBackStaticWriteMask         = 0;
    state.stencilTestFrontAndBackStaticReference         = 0;
    state.blendLogicOpEnable                             = 0;
    state.blendLogicOp                                   = RED_LOGIC_OP_CLEAR;
    state.blendConstantsDynamic                          = 0;
    state.blendConstantsStatic[0]                        = 0;
    state.blendConstantsStatic[1]                        = 0;
    state.blendConstantsStatic[2]                        = 0;
    state.blendConstantsStatic[3]                        = 0;
    state.outputColorsCount                              = 1;
    state.outputColorsWriteMask[0]                       = RED_COLOR_COMPONENT_BITFLAG_R | RED_COLOR_COMPONENT_BITFLAG_G | RED_COLOR_COMPONENT_BITFLAG_B | RED_COLOR_COMPONENT_BITFLAG_A;
    state.outputColorsWriteMask[1]                       = RED_COLOR_COMPONENT_BITFLAG_R | RED_COLOR_COMPONENT_BITFLAG_G | RED_COLOR_COMPONENT_BITFLAG_B | RED_COLOR_COMPONENT_BITFLAG_A;
    state.outputColorsWriteMask[2]                       = RED_COLOR_COMPONENT_BITFLAG_R | RED_COLOR_COMPONENT_BITFLAG_G | RED_COLOR_COMPONENT_BITFLAG_B | RED_COLOR_COMPONENT_BITFLAG_A;
    state.outputColorsWriteMask[3]                       = RED_COLOR_COMPONENT_BITFLAG_R | RED_COLOR_COMPONENT_BITFLAG_G | RED_COLOR_COMPONENT_BITFLAG_B | RED_COLOR_COMPONENT_BITFLAG_A;
    state.outputColorsWriteMask[4]                       = RED_COLOR_COMPONENT_BITFLAG_R | RED_COLOR_COMPONENT_BITFLAG_G | RED_COLOR_COMPONENT_BITFLAG_B | RED_COLOR_COMPONENT_BITFLAG_A;
    state.outputColorsWriteMask[5]                       = RED_COLOR_COMPONENT_BITFLAG_R | RED_COLOR_COMPONENT_BITFLAG_G | RED_COLOR_COMPONENT_BITFLAG_B | RED_COLOR_COMPONENT_BITFLAG_A;
    state.outputColorsWriteMask[6]                       = RED_COLOR_COMPONENT_BITFLAG_R | RED_COLOR_COMPONENT_BITFLAG_G | RED_COLOR_COMPONENT_BITFLAG_B | RED_COLOR_COMPONENT_BITFLAG_A;
    state.outputColorsWriteMask[7]                       = RED_COLOR_COMPONENT_BITFLAG_R | RED_COLOR_COMPONENT_BITFLAG_G | RED_COLOR_COMPONENT_BITFLAG_B | RED_COLOR_COMPONENT_BITFLAG_A;
    for (unsigned i = 0; i < 8; i += 1) {
      state.outputColorsBlendEnable[i]                   = 1;
      state.outputColorsBlendColorFactorSource[i]        = RED_BLEND_FACTOR_SOURCE_ALPHA;
      state.outputColorsBlendColorFactorTarget[i]        = RED_BLEND_FACTOR_ONE_MINUS_SOURCE_ALPHA;
      state.outputColorsBlendColorOp[i]                  = RED_BLEND_OP_ADD;
      state.outputColorsBlendAlphaFactorSource[i]        = RED_BLEND_FACTOR_ONE;
      state.outputColorsBlendAlphaFactorTarget[i]        = RED_BLEND_FACTOR_ONE_MINUS_SOURCE_ALPHA;
      state.outputColorsBlendAlphaOp[i]                  = RED_BLEND_OP_ADD;
    }
    redCreateProcedure(instance, device, NULL, pipelineCache, renderPass, bd->PipelineLayout, "main", bd->ShaderModuleVert, "main", bd->ShaderModuleFrag, &state, NULL, 0, NULL, pipeline, NULL, __FILE__, __LINE__, NULL);
}

bool ImGui_ImplRedGpu_CreateDeviceObjects()
{
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    ImGui_ImplRedGpu_InitInfo* v = &bd->RedGpuInitInfo;

    ImGui_ImplRedGpu_CreateFontSampler(v->Instance, v->DeviceIndex, v->Device);
    ImGui_ImplRedGpu_CreateDescriptorSetLayouts(v->Instance, v->DeviceIndex, v->Device);
    ImGui_ImplRedGpu_CreatePipelineLayout(v->Instance, v->DeviceIndex, v->Device);
    ImGui_ImplRedGpu_CreatePipeline(v->Instance, v->DeviceIndex, v->Device, v->PipelineCache, bd->RenderPass, v->MSAASamples, &bd->Pipeline, bd->Subpass);

    return true;
}

void    ImGui_ImplRedGpu_DestroyFontUploadObjects()
{
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    ImGui_ImplRedGpu_InitInfo* v = &bd->RedGpuInitInfo;
    if (bd->UploadBuffer.handle)
    {
        redDestroyArray(v->Instance, v->Device, bd->UploadBuffer.handle, __FILE__, __LINE__, NULL);
        RedArray defaults = {};
        bd->UploadBuffer = defaults;
    }
    if (bd->UploadBufferMemory)
    {
        redMemoryFree(v->Instance, v->Device, bd->UploadBufferMemory, __FILE__, __LINE__, NULL);
        bd->UploadBufferMemory = NULL;
    }
}

void    ImGui_ImplRedGpu_DestroyDeviceObjects()
{
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    ImGui_ImplRedGpu_InitInfo* v = &bd->RedGpuInitInfo;
    ImGui_ImplRedGpuH_DestroyWindowRenderBuffers(v->Instance, v->DeviceIndex, v->Device, &bd->MainWindowRenderBuffers);
    ImGui_ImplRedGpu_DestroyFontUploadObjects();

    if (bd->ShaderModuleVert)               { redDestroyGpuCode(v->Instance, v->Device, bd->ShaderModuleVert, __FILE__, __LINE__, NULL); bd->ShaderModuleVert = NULL; }
    if (bd->ShaderModuleFrag)               { redDestroyGpuCode(v->Instance, v->Device, bd->ShaderModuleFrag, __FILE__, __LINE__, NULL); bd->ShaderModuleFrag = NULL; }
    if (bd->FontView)                       { redDestroyTexture(v->Instance, v->Device, bd->FontView, __FILE__, __LINE__, NULL); bd->FontView = NULL; }
    if (bd->FontImage.handle)               { redDestroyImage(v->Instance, v->Device, bd->FontImage.handle, __FILE__, __LINE__, NULL); RedImage defaults = {}; bd->FontImage = defaults; }
    if (bd->FontMemory)                     { redMemoryFree(v->Instance, v->Device, bd->FontMemory, __FILE__, __LINE__, NULL); bd->FontMemory = NULL; }
    if (bd->FontSampler)                    { redDestroySampler(v->Instance, v->Device, bd->FontSampler, __FILE__, __LINE__, NULL); bd->FontSampler = NULL; }
    if (bd->SamplerDescriptorSetLayout)     {  }
    if (bd->DescriptorSetLayout)            { redDestroyStructDeclaration(v->Instance, v->Device, bd->DescriptorSetLayout, __FILE__, __LINE__, NULL); bd->DescriptorSetLayout = NULL; }
    if (bd->ImdrawvertsDescriptorSetLayout) { redDestroyStructDeclaration(v->Instance, v->Device, bd->ImdrawvertsDescriptorSetLayout, __FILE__, __LINE__, NULL); bd->ImdrawvertsDescriptorSetLayout = NULL; }
    if (bd->PipelineLayout)                 { redDestroyProcedureParameters(v->Instance, v->Device, bd->PipelineLayout, __FILE__, __LINE__, NULL); bd->PipelineLayout = NULL; }
    if (bd->Pipeline)                       { redDestroyProcedure(v->Instance, v->Device, bd->Pipeline, __FILE__, __LINE__, NULL); bd->Pipeline = NULL; }
}

bool    ImGui_ImplRedGpu_Init(ImGui_ImplRedGpu_InitInfo* info, RedHandleOutputDeclaration render_pass)
{
    ImGuiIO& io = ImGui::GetIO();
    IM_ASSERT(io.BackendRendererUserData == NULL && "Already initialized a renderer backend!");

    // Setup backend capabilities flags
    ImGui_ImplRedGpu_Data* bd = IM_NEW(ImGui_ImplRedGpu_Data)();
    io.BackendRendererUserData = (void*)bd;
    io.BackendRendererName = "imgui_impl_redgpu";
    io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;  // We can honor the ImDrawCmd::VtxOffset field, allowing for large meshes.

    IM_ASSERT(info->Instance != NULL);
    IM_ASSERT(info->PhysicalDevice != NULL);
    IM_ASSERT(info->Device != NULL);
    IM_ASSERT(info->DescriptorPool != NULL);
    //IM_ASSERT(info->DescriptorPoolSamplers != NULL);
    IM_ASSERT(info->MinImageCount >= 2);
    IM_ASSERT(info->ImageCount >= info->MinImageCount);
    IM_ASSERT(render_pass != NULL);

    bd->RedGpuInitInfo = *info;
    bd->RenderPass = render_pass;
    bd->Subpass = info->Subpass;

    ImGui_ImplRedGpu_CreateDeviceObjects();

    return true;
}

void ImGui_ImplRedGpu_Shutdown()
{
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    IM_ASSERT(bd != NULL && "No renderer backend to shutdown, or already shutdown?");
    ImGuiIO& io = ImGui::GetIO();

    ImGui_ImplRedGpu_DestroyDeviceObjects();
    io.BackendRendererName = NULL;
    io.BackendRendererUserData = NULL;
    IM_DELETE(bd);
}

void ImGui_ImplRedGpu_NewFrame()
{
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    IM_ASSERT(bd != NULL && "Did you call ImGui_ImplRedGpu_Init()?");
    IM_UNUSED(bd);
}

void ImGui_ImplRedGpu_SetMinImageCount(uint32_t min_image_count, ImGui_ImplRedGpuH_Window* wd)
{
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    IM_ASSERT(min_image_count >= 2);
    if (bd->RedGpuInitInfo.MinImageCount == min_image_count)
        return;

    ImGui_ImplRedGpu_InitInfo* v = &bd->RedGpuInitInfo;
    //DeviceWaitIdle(v->Instance, v->DeviceIndex, v->Device);
    for (uint32_t i = 0; i < wd->ImageCount; i++)
    {
        redCpuSignalWait(v->Instance, v->Device, 1, &wd->Frames[i].Fence, 1, NULL, __FILE__, __LINE__, NULL);
    }
    ImGui_ImplRedGpuH_DestroyWindowRenderBuffers(v->Instance, v->DeviceIndex, v->Device, &bd->MainWindowRenderBuffers);
    bd->RedGpuInitInfo.MinImageCount = min_image_count;
}

// Register a texture
// FIXME: This is experimental in the sense that we are unsure how to best design/tackle this problem, please post to https://github.com/ocornut/imgui/pull/914 if you have suggestions.
RedHandleStruct ImGui_ImplRedGpu_AddTexture(RedHandleSampler sampler, RedHandleTexture image_view)
{
    ImGui_ImplRedGpu_Data* bd = ImGui_ImplRedGpu_GetBackendData();
    ImGui_ImplRedGpu_InitInfo* v = &bd->RedGpuInitInfo;

    // Create Sampler Descriptor Set:
    RedHandleStruct sampler_descriptor_set;
    {
    }

    // Create Descriptor Set:
    RedHandleStruct descriptor_set;
    {
#ifdef REDGPU_USE_REDGPU_X
        descriptor_set = redXGetHandleStruct(v->Instance, v->Device, v->DescriptorPool, 0);
#else
        redStructsMemoryReset(v->Instance, v->Device, v->DescriptorPool, NULL, __FILE__, __LINE__, NULL);
        redStructsMemorySuballocateStructs(v->Instance, v->Device, NULL, v->DescriptorPool, 1, &bd->DescriptorSetLayout, &descriptor_set, NULL, __FILE__, __LINE__, NULL);
#endif
    }

    // Update the Descriptor Set:
    {
        RedStructMember members[1] = {};
        // NOTE(Constantine): Using a static sampler for slot 0.
        RedStructMemberTexture texture0 = {};
        texture0.sampler = NULL;
        texture0.texture = image_view;
        texture0.setTo1  = 1;
        members[0].setTo35   = 35;
        members[0].setTo0    = 0;
        members[0].structure = descriptor_set;
        members[0].slot      = 1;
        members[0].first     = 0;
        members[0].count     = 1;
        members[0].type      = RED_STRUCT_MEMBER_TYPE_TEXTURE_RO;
        members[0].textures  = &texture0;
        members[0].arrays    = NULL;
        members[0].setTo00   = 0;
#ifdef REDGPU_USE_REDGPU_X
        {
          unsigned one = 1;
          RedXMemoryAddress texture0address    = {redXGetMemoryAddressTextureRO(v->Instance, v->Device, image_view)};
          RedXMemoryAddress structSlot0Address = {redXGetMemoryAddressStructMember(v->Instance, v->Device, v->DescriptorPool, 0)};
          redXStructsMemorySet(v->Instance, v->Device, 0, 1, &texture0address, &one, 1, &structSlot0Address, &one, NULL, __FILE__, __LINE__, NULL);
        }
#else
        redStructsSet(v->Instance, v->Device, 1, members, __FILE__, __LINE__, NULL);
#endif
    }

    // Setting bd->FontSamplerDescriptorSet:
    {
    }

    return descriptor_set;
}

//-------------------------------------------------------------------------
// Internal / Miscellaneous REDGPU Helpers
// (Used by example's main.cpp. Used by multi-viewport features. PROBABLY NOT used by your own app.)
//-------------------------------------------------------------------------

RedFormat ImGui_ImplRedGpuH_SelectSurfaceFormat()
{
    return RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1;
}

void ImGui_ImplRedGpuH_CreateWindowCommandBuffers(RedContext instance, uint32_t deviceIndex, RedHandleGpuDevice physical_device, RedHandleGpu device, ImGui_ImplRedGpuH_Window* wd, uint32_t queue_family)
{
    IM_ASSERT(physical_device != NULL && device != NULL);

    // Create Command Buffers
    for (uint32_t i = 0; i < wd->ImageCount; i++)
    {
        ImGui_ImplRedGpuH_Frame* fd = &wd->Frames[i];
        ImGui_ImplRedGpuH_FrameSemaphores* fsd = &wd->FrameSemaphores[i];
        {
            redCreateCallsReusable(instance, device, NULL, queue_family, &fd->CommandBuffer, NULL, __FILE__, __LINE__, NULL);
        }
        {
            redCreateCpuSignal(instance, device, NULL, 1, &fd->Fence, NULL, __FILE__, __LINE__, NULL);
        }
        {
            redCreateGpuSignal(instance, device, NULL, &fsd->ImageAcquiredSemaphore,  NULL, __FILE__, __LINE__, NULL);
            redCreateGpuSignal(instance, device, NULL, &fsd->RenderCompleteSemaphore, NULL, __FILE__, __LINE__, NULL);
        }
    }
}

int ImGui_ImplRedGpuH_GetMinImageCountFromPresentMode(RedPresentVsyncMode present_mode)
{
    return 2;
}

// Also destroy old swap chain and in-flight frames data, if any.
void ImGui_ImplRedGpuH_CreateWindowSwapChain(RedContext instance, uint32_t deviceIndex, RedHandleGpuDevice physical_device, RedHandleGpu device, RedHandleQueue present_queue, ImGui_ImplRedGpuH_Window* wd, int w, int h, uint32_t min_image_count, void * windowHandle, int screenW, int screenH)
{
    RedHandlePresent old_swapchain = wd->Swapchain;
    wd->Swapchain = NULL;
    //DeviceWaitIdle(instance, deviceIndex, device);
    redQueuePresent(instance, device, present_queue, 0, NULL, 0, NULL, NULL, NULL, NULL, __FILE__, __LINE__, NULL);
    for (uint32_t i = 0; i < wd->ImageCount; i++)
    {
        redCpuSignalWait(instance, device, 1, &wd->Frames[i].Fence, 1, NULL, __FILE__, __LINE__, NULL);
    }

    // We don't use ImGui_ImplRedGpuH_DestroyWindow() because we want to preserve the old swapchain to create the new one.
    // Destroy old Framebuffer
    for (uint32_t i = 0; i < wd->ImageCount; i++)
    {
        ImGui_ImplRedGpuH_DestroyFrame(instance, deviceIndex, device, &wd->Frames[i]);
        ImGui_ImplRedGpuH_DestroyFrameSemaphores(instance, deviceIndex, device, &wd->FrameSemaphores[i]);
    }
    IM_FREE(wd->Frames);
    IM_FREE(wd->FrameSemaphores);
    wd->Frames = NULL;
    wd->FrameSemaphores = NULL;
    wd->ImageCount = 2;
    if (wd->RenderPass)
    {
        redDestroyOutputDeclaration(instance, device, wd->RenderPass, __FILE__, __LINE__, NULL);
    }
    if (wd->Pipeline)
    {
        redDestroyProcedure(instance, device, wd->Pipeline, __FILE__, __LINE__, NULL);
    }

    // If min image count was not specified, request different count of images dependent on selected present mode
    if (min_image_count == 0)
        min_image_count = ImGui_ImplRedGpuH_GetMinImageCountFromPresentMode(wd->PresentMode);

    // Create Swapchain
    {
        RedQueueFamilyIndexGetSupportsPresentOnSurface queueFamilyIndexSupportsPresentOnSurface = {};
        queueFamilyIndexSupportsPresentOnSurface.surface = wd->Surface;
        redQueueFamilyIndexGetSupportsPresent(instance, device, 0, NULL, NULL, NULL, &queueFamilyIndexSupportsPresentOnSurface, NULL, __FILE__, __LINE__, NULL);
        RedSurfaceCurrentPropertiesAndPresentLimits surfaceCurrentPropertiesAndPresentLimits = {};
        redSurfaceGetCurrentPropertiesAndPresentLimits(instance, device, wd->Surface, &surfaceCurrentPropertiesAndPresentLimits, NULL, __FILE__, __LINE__, NULL);
        if (surfaceCurrentPropertiesAndPresentLimits.currentSurfaceWidth  != -1) { w = surfaceCurrentPropertiesAndPresentLimits.currentSurfaceWidth;  }
        if (surfaceCurrentPropertiesAndPresentLimits.currentSurfaceHeight != -1) { h = surfaceCurrentPropertiesAndPresentLimits.currentSurfaceHeight; }
        wd->Width  = w;
        wd->Height = h;
        RedHandleImage   backbuffers[2]      = {};
        RedHandleTexture backbuffers_view[2] = {};
#ifdef REDGPU_USE_REDGPU_X
        // NOTE(Constantine): Assumes all secondary computer monitors don't have a higher pixel resolution than the primary monitor.
        redCreatePresent(instance, device, present_queue, NULL, wd->Surface, 2, screenW, screenH, 1, RED_ACCESS_BITFLAG_OUTPUT_COLOR_W, RED_SURFACE_TRANSFORM_BITFLAG_IDENTITY, RED_SURFACE_COMPOSITE_ALPHA_BITFLAG_OPAQUE, RED_PRESENT_VSYNC_MODE_ON, 1, 0, old_swapchain, &wd->Swapchain, backbuffers, backbuffers_view, NULL, __FILE__, __LINE__, NULL);
        x12FactoryMakeWindowAssociation((X12Factory4 *)instance->handle, windowHandle, 0x2/*DXGI_MWA_NO_ALT_ENTER*/, __FILE__, __LINE__);
#else
        redCreatePresent(instance, device, present_queue, NULL, wd->Surface, 2, w, h, 1, RED_ACCESS_BITFLAG_OUTPUT_COLOR_W, RED_SURFACE_TRANSFORM_BITFLAG_IDENTITY, RED_SURFACE_COMPOSITE_ALPHA_BITFLAG_OPAQUE, wd->PresentMode, 1, 0, old_swapchain, &wd->Swapchain, backbuffers, backbuffers_view, NULL, __FILE__, __LINE__, NULL);
#endif

        IM_ASSERT(wd->ImageCount == 2);
        IM_ASSERT(wd->Frames == NULL);
        wd->Frames = (ImGui_ImplRedGpuH_Frame*)IM_ALLOC(sizeof(ImGui_ImplRedGpuH_Frame) * wd->ImageCount);
        wd->FrameSemaphores = (ImGui_ImplRedGpuH_FrameSemaphores*)IM_ALLOC(sizeof(ImGui_ImplRedGpuH_FrameSemaphores) * wd->ImageCount);
        memset(wd->Frames, 0, sizeof(wd->Frames[0]) * wd->ImageCount);
        memset(wd->FrameSemaphores, 0, sizeof(wd->FrameSemaphores[0]) * wd->ImageCount);
        for (uint32_t i = 0; i < wd->ImageCount; i++)
        {
            wd->Frames[i].Backbuffer     = backbuffers[i];
            wd->Frames[i].BackbufferView = backbuffers_view[i];
        }
    }
    if (old_swapchain)
    {
        redDestroyPresent(instance, device, old_swapchain, __FILE__, __LINE__, NULL);
    }

    // Create the Render Pass
    {
        RedOutputDeclarationMembers members = {};
        members.depthStencilEnable                        = 0;
        members.depthStencilFormat                        = RED_FORMAT_UNDEFINED;
        members.depthStencilMultisampleCount              = RED_MULTISAMPLE_COUNT_BITFLAG_1;
        members.depthStencilDepthSetProcedureOutputOp     = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.depthStencilDepthEndProcedureOutputOp     = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.depthStencilStencilSetProcedureOutputOp   = RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.depthStencilStencilEndProcedureOutputOp   = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.depthStencilSharesMemoryWithAnotherMember = 0;
        members.colorsCount                               = 1;
        members.colorsFormat[0]                           = RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1;
        members.colorsFormat[1]                           = RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1;
        members.colorsFormat[2]                           = RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1;
        members.colorsFormat[3]                           = RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1;
        members.colorsFormat[4]                           = RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1;
        members.colorsFormat[5]                           = RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1;
        members.colorsFormat[6]                           = RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1;
        members.colorsFormat[7]                           = RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1;
        members.colorsMultisampleCount[0]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
        members.colorsMultisampleCount[1]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
        members.colorsMultisampleCount[2]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
        members.colorsMultisampleCount[3]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
        members.colorsMultisampleCount[4]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
        members.colorsMultisampleCount[5]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
        members.colorsMultisampleCount[6]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
        members.colorsMultisampleCount[7]                 = RED_MULTISAMPLE_COUNT_BITFLAG_1;
        members.colorsSetProcedureOutputOp[0]             = wd->ClearEnable ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsSetProcedureOutputOp[1]             = wd->ClearEnable ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsSetProcedureOutputOp[2]             = wd->ClearEnable ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsSetProcedureOutputOp[3]             = wd->ClearEnable ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsSetProcedureOutputOp[4]             = wd->ClearEnable ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsSetProcedureOutputOp[5]             = wd->ClearEnable ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsSetProcedureOutputOp[6]             = wd->ClearEnable ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsSetProcedureOutputOp[7]             = wd->ClearEnable ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsEndProcedureOutputOp[0]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsEndProcedureOutputOp[1]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsEndProcedureOutputOp[2]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsEndProcedureOutputOp[3]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsEndProcedureOutputOp[4]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsEndProcedureOutputOp[5]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsEndProcedureOutputOp[6]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsEndProcedureOutputOp[7]             = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
        members.colorsSharesMemoryWithAnotherMember[0]    = 0;
        members.colorsSharesMemoryWithAnotherMember[1]    = 0;
        members.colorsSharesMemoryWithAnotherMember[2]    = 0;
        members.colorsSharesMemoryWithAnotherMember[3]    = 0;
        members.colorsSharesMemoryWithAnotherMember[4]    = 0;
        members.colorsSharesMemoryWithAnotherMember[5]    = 0;
        members.colorsSharesMemoryWithAnotherMember[6]    = 0;
        members.colorsSharesMemoryWithAnotherMember[7]    = 0;
        redCreateOutputDeclaration(instance, device, NULL, &members, NULL, 0, 0, &wd->RenderPass, NULL, __FILE__, __LINE__, NULL);

        // We do not create a pipeline by default as this is also used by examples' main.cpp,
        // but secondary viewport in multi-viewport mode may want to create one with:
        //ImGui_ImplRedGpu_CreatePipeline(instance, deviceIndex, device, NULL, wd->RenderPass, RED_MULTISAMPLE_COUNT_BITFLAG_1, &wd->Pipeline, bd->Subpass);
    }

    // Create Framebuffer
    {
        for (uint32_t i = 0; i < wd->ImageCount; i++)
        {
            ImGui_ImplRedGpuH_Frame* fd = &wd->Frames[i];

            RedOutputMembers outputMembers = {};
            outputMembers.depthStencil = NULL;
            outputMembers.colorsCount  = 1;
            outputMembers.colors[0]    = fd->BackbufferView;
            outputMembers.colors[1]    = NULL;
            outputMembers.colors[2]    = NULL;
            outputMembers.colors[3]    = NULL;
            outputMembers.colors[4]    = NULL;
            outputMembers.colors[5]    = NULL;
            outputMembers.colors[6]    = NULL;
            outputMembers.colors[7]    = NULL;
            redCreateOutput(instance, device, NULL, wd->RenderPass, &outputMembers, NULL, wd->Width, wd->Height, &fd->Framebuffer, NULL, __FILE__, __LINE__, NULL);
        }
    }
}

// Create or resize window
void ImGui_ImplRedGpuH_CreateOrResizeWindow(RedContext instance, uint32_t deviceIndex, RedHandleGpuDevice physical_device, RedHandleGpu device, RedHandleQueue present_queue, ImGui_ImplRedGpuH_Window* wd, uint32_t queue_family, int width, int height, uint32_t min_image_count, void * windowHandle, int screenW, int screenH)
{
    ImGui_ImplRedGpuH_CreateWindowSwapChain(instance, deviceIndex, physical_device, device, present_queue, wd, width, height, min_image_count, windowHandle, screenW, screenH);
    ImGui_ImplRedGpuH_CreateWindowCommandBuffers(instance, deviceIndex, physical_device, device, wd, queue_family);
}

void ImGui_ImplRedGpuH_DestroyWindow(RedContext instance, uint32_t deviceIndex, RedHandleGpu device, RedHandleQueue present_queue, ImGui_ImplRedGpuH_Window* wd)
{
    //DeviceWaitIdle(instance, deviceIndex, device);
    redQueuePresent(instance, device, present_queue, 0, NULL, 0, NULL, NULL, NULL, NULL, __FILE__, __LINE__, NULL);
    for (uint32_t i = 0; i < wd->ImageCount; i++)
    {
        redCpuSignalWait(instance, device, 1, &wd->Frames[i].Fence, 1, NULL, __FILE__, __LINE__, NULL);
    }

    for (uint32_t i = 0; i < wd->ImageCount; i++)
    {
        ImGui_ImplRedGpuH_DestroyFrame(instance, deviceIndex, device, &wd->Frames[i]);
        ImGui_ImplRedGpuH_DestroyFrameSemaphores(instance, deviceIndex, device, &wd->FrameSemaphores[i]);
    }
    IM_FREE(wd->Frames);
    IM_FREE(wd->FrameSemaphores);
    wd->Frames = NULL;
    wd->FrameSemaphores = NULL;
    redDestroyProcedure(instance, device, wd->Pipeline, __FILE__, __LINE__, NULL);
    redDestroyOutputDeclaration(instance, device, wd->RenderPass, __FILE__, __LINE__, NULL);
    redDestroyPresent(instance, device, wd->Swapchain, __FILE__, __LINE__, NULL);
    redDestroySurface(instance, device, wd->Surface, __FILE__, __LINE__, NULL);

    *wd = ImGui_ImplRedGpuH_Window();
}

void ImGui_ImplRedGpuH_DestroyFrame(RedContext instance, uint32_t deviceIndex, RedHandleGpu device, ImGui_ImplRedGpuH_Frame* fd)
{
    redDestroyCpuSignal(instance, device, fd->Fence, __FILE__, __LINE__, NULL);
    redDestroyCalls(instance, device, fd->CommandBuffer.handle, fd->CommandBuffer.memory, __FILE__, __LINE__, NULL);
    fd->Fence = NULL;
    RedCalls defaults = {};
    fd->CommandBuffer = defaults;

    redDestroyTexture(instance, device, fd->BackbufferView, __FILE__, __LINE__, NULL);
    redDestroyOutput(instance, device, fd->Framebuffer.handle, __FILE__, __LINE__, NULL);
}

void ImGui_ImplRedGpuH_DestroyFrameSemaphores(RedContext instance, uint32_t deviceIndex, RedHandleGpu device, ImGui_ImplRedGpuH_FrameSemaphores* fsd)
{
    redDestroyGpuSignal(instance, device, fsd->ImageAcquiredSemaphore,  __FILE__, __LINE__, NULL);
    redDestroyGpuSignal(instance, device, fsd->RenderCompleteSemaphore, __FILE__, __LINE__, NULL);
    fsd->ImageAcquiredSemaphore  = NULL;
    fsd->RenderCompleteSemaphore = NULL;
}

void ImGui_ImplRedGpuH_DestroyFrameRenderBuffers(RedContext instance, uint32_t deviceIndex, RedHandleGpu device, ImGui_ImplRedGpuH_FrameRenderBuffers* buffers)
{
    if (buffers->VertexBuffer.handle) { redDestroyArray(instance, device, buffers->VertexBuffer.handle, __FILE__, __LINE__, NULL); RedArray defaults = {}; buffers->VertexBuffer = defaults; }
    if (buffers->VertexBufferMemory)  { redMemoryFree(instance, device, buffers->VertexBufferMemory, __FILE__, __LINE__, NULL); buffers->VertexBufferMemory = NULL; }
    if (buffers->IndexBuffer.handle)  { redDestroyArray(instance, device, buffers->IndexBuffer.handle, __FILE__, __LINE__, NULL); RedArray defaults = {}; buffers->IndexBuffer = defaults; }
    if (buffers->IndexBufferMemory)   { redMemoryFree(instance, device, buffers->IndexBufferMemory, __FILE__, __LINE__, NULL); buffers->IndexBufferMemory = NULL; }
    buffers->VertexBufferSize = 0;
    buffers->IndexBufferSize  = 0;
}

void ImGui_ImplRedGpuH_DestroyWindowRenderBuffers(RedContext instance, uint32_t deviceIndex, RedHandleGpu device, ImGui_ImplRedGpuH_WindowRenderBuffers* buffers)
{
    for (uint32_t n = 0; n < buffers->Count; n++)
        ImGui_ImplRedGpuH_DestroyFrameRenderBuffers(instance, deviceIndex, device, &buffers->FrameRenderBuffers[n]);
    IM_FREE(buffers->FrameRenderBuffers);
    buffers->FrameRenderBuffers = NULL;
    buffers->Index = 0;
    buffers->Count = 0;
}

#endif // #if defined(REDGPU_2_EXAMPLE_NUMBER_0)

#if defined(REDGPU_2_EXAMPLE_NUMBER_1)

// DEPENDENCY(Constantine): Dear ImGui docking branch v1.89.6, commit 823a1385a269d923d35b82b2f470f3ae1fa8b5a3
// DEPENDENCY(Constantine): GLFW 3.3.2, commit 0a49ef0a00baa3ab520ddc452f0e3b1e099c5589

// COMPILE(Constantine):
// g++.exe -fpermissive -DREDGPU_2_EXAMPLE_NUMBER_0 -DREDGPU_2_EXAMPLE_NUMBER_1 -DREDGPU_USE_REDGPU_X -DImTextureID=ImU64 -DImDrawIdx=unsigned -Iimgui/ -Iglfw-3.3.2.bin.WIN64/include/ redgpu_2_examples.cpp imgui/imgui.cpp imgui/imgui_demo.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/backends/imgui_impl_glfw.cpp C:/RedGpuSDK/redgpu_x.lib C:/RedGpuSDK/redgpu_x12.lib glfw-3.3.2.bin.WIN64/lib-vc2019/glfw3dll.lib

// FILE(Constantine): main.cpp

#include "C:/RedGpuSDK/redgpu_x.h"

#define REDGPU_DISABLE_NAMED_PARAMETERS
#include "C:/RedGpuSDK/misc/np/np_redgpu.h"
#include "C:/RedGpuSDK/misc/np/np_redgpu_x.h"
#include "C:/RedGpuSDK/misc/np/np_redgpu_wsi.h"

#define GLFW_INCLUDE_NONE
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include "imgui/backends/imgui_impl_glfw.h"

#include <stdio.h>  // For printf
#include <stdlib.h> // For malloc, free
#include <assert.h> // For assert
#define expect(x) assert(x)
#define panic(x) assert(!(x))

extern "C" size_t                gDroidSansMonoFontGetBytesCount();
extern "C" unsigned char         gDroidSansMonoFont[];

static GLFWwindow *              g_window                 = NULL;
static bool                      g_windowIsHoldingCtrlKey = false;
static bool                      g_windowIsIconified      = false;
static const int                 g_frameCount             = 2;
static RedContext                g_redcontext             = NULL;
static RedHandleStructsMemory    g_imguiStructsMemory     = NULL;
static ImGui_ImplRedGpuH_Window  g_imguiWindowData        = {};
static ImGui_ImplRedGpu_InitInfo g_imguiRedGpuInitInfo    = {};
static float                     g_imguiUiScale           = 1.0f;

void uiRebuildFont(bool waitForAllFramesToFinish, float scale) {
  ImGuiIO & io = ImGui::GetIO();

  if (waitForAllFramesToFinish == true) {
    for (int i = 0; i < g_imguiWindowData.ImageCount; i += 1) {
      np_redCpuSignalWait(
        _4a826452_context(g_redcontext),
        _4a826452_gpu(g_redcontext->gpus[0].gpu),
        _4a826452_cpuSignalsCount(1),
        _4a826452_cpuSignals(&g_imguiWindowData.Frames[i].Fence),
        _4a826452_waitAll(1),
        _4a826452_outStatuses(NULL),
        _4a826452_optionalFile(__FILE__),
        _4a826452_optionalLine(__LINE__),
        _4a826452_optionalUserData(NULL)
      );
    }
  }

  io.Fonts->Clear();

  {
    size_t fontDataBytesCount = gDroidSansMonoFontGetBytesCount();
    char * fontData = new char[fontDataBytesCount];
    if (fontData != 0) {
      memcpy(fontData, gDroidSansMonoFont, fontDataBytesCount);
      ImFont * imfont = io.Fonts->AddFontFromMemoryTTF(fontData, fontDataBytesCount, 22.0f * scale, NULL, io.Fonts->GetGlyphRangesCyrillic());
      // delete[] fontData; // NOTE(Constantine): Commented out intentionally, "ownership of font_data is transfered by Dear ImGui by default".
    }
  }

  // Font upload
  {
    RedCalls calls = g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].CommandBuffer;

    np_redCallsSet(
      _23514538_context(g_redcontext),
      _23514538_gpu(g_redcontext->gpus[0].gpu),
      _23514538_calls(calls.handle),
      _23514538_callsMemory(calls.memory),
      _23514538_callsReusable(calls.reusable),
      _23514538_outStatuses(NULL),
      _23514538_optionalFile(__FILE__),
      _23514538_optionalLine(__LINE__),
      _23514538_optionalUserData(NULL)
    );

    ImGui_ImplRedGpu_CreateFontsTexture(calls.handle);

    np_redCallsEnd(
      _2566f99f_context(g_redcontext),
      _2566f99f_gpu(g_redcontext->gpus[0].gpu),
      _2566f99f_calls(calls.handle),
      _2566f99f_callsMemory(calls.memory),
      _2566f99f_outStatuses(NULL),
      _2566f99f_optionalFile(__FILE__),
      _2566f99f_optionalLine(__LINE__),
      _2566f99f_optionalUserData(NULL)
    );

    {
      RedGpuTimeline timeline = {};
      timeline.setTo4                            = 4;
      timeline.setTo0                            = 0;
      timeline.waitForAndUnsignalGpuSignalsCount = 0;
      timeline.waitForAndUnsignalGpuSignals      = NULL;
      timeline.setTo65536                        = NULL;
      timeline.callsCount                        = 1;
      timeline.calls                             = &calls.handle;
      timeline.signalGpuSignalsCount             = 0;
      timeline.signalGpuSignals                  = NULL;
      RedHandleCpuSignal cpuSignal = NULL;
      np_redCreateCpuSignal(
        _9dcf3e68_context(g_redcontext),
        _9dcf3e68_gpu(g_redcontext->gpus[0].gpu),
        _9dcf3e68_handleName(NULL),
        _9dcf3e68_createSignaled(0),
        _9dcf3e68_outCpuSignal(&cpuSignal),
        _9dcf3e68_outStatuses(NULL),
        _9dcf3e68_optionalFile(__FILE__),
        _9dcf3e68_optionalLine(__LINE__),
        _9dcf3e68_optionalUserData(NULL)
      );
      np_redQueueSubmit(
        _dcc70647_context(g_redcontext),
        _dcc70647_gpu(g_redcontext->gpus[0].gpu),
        _dcc70647_queue(g_redcontext->gpus[0].queues[0]),
        _dcc70647_timelinesCount(1),
        _dcc70647_timelines(&timeline),
        _dcc70647_signalCpuSignal(cpuSignal),
        _dcc70647_outStatuses(NULL),
        _dcc70647_optionalFile(__FILE__),
        _dcc70647_optionalLine(__LINE__),
        _dcc70647_optionalUserData(NULL)
      );
      np_redCpuSignalWait(
        _4a826452_context(g_redcontext),
        _4a826452_gpu(g_redcontext->gpus[0].gpu),
        _4a826452_cpuSignalsCount(1),
        _4a826452_cpuSignals(&cpuSignal),
        _4a826452_waitAll(1),
        _4a826452_outStatuses(NULL),
        _4a826452_optionalFile(__FILE__),
        _4a826452_optionalLine(__LINE__),
        _4a826452_optionalUserData(NULL)
      );
      np_redDestroyCpuSignal(
        _05dd4cf0_context(g_redcontext),
        _05dd4cf0_gpu(g_redcontext->gpus[0].gpu),
        _05dd4cf0_cpuSignal(cpuSignal),
        _05dd4cf0_optionalFile(__FILE__),
        _05dd4cf0_optionalLine(__LINE__),
        _05dd4cf0_optionalUserData(NULL)
      );
    }
  }

  ImGui_ImplRedGpu_DestroyFontUploadObjects();
}

void keyCallback(GLFWwindow * window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_LEFT_CONTROL  && action == GLFW_PRESS ||
      key == GLFW_KEY_RIGHT_CONTROL && action == GLFW_PRESS)
  {
    g_windowIsHoldingCtrlKey = true;
  }
  if (key == GLFW_KEY_LEFT_CONTROL  && action == GLFW_RELEASE ||
      key == GLFW_KEY_RIGHT_CONTROL && action == GLFW_RELEASE)
  {
    g_windowIsHoldingCtrlKey = false;
  }
}

void mouseScrollCallback(GLFWwindow * window, double xoffset, double yoffset) {
  if (g_windowIsHoldingCtrlKey == true) {
    float newUiScale = g_imguiUiScale + (yoffset * 0.1f);
    if (newUiScale < 1.0f) {
      newUiScale = 1.0f;
    }
    if (newUiScale > 100.0f) {
      newUiScale = 100.0f;
    }
    g_imguiUiScale = newUiScale;
    uiRebuildFont(true, g_imguiUiScale);
  }
}

void windowIconifyCallback(GLFWwindow * window, int iconified) {
  g_windowIsIconified = iconified == 1;
}

int main() {
  RedXContextOptionalSettingsD3DMemoryAllocateZeroed settingsD3DMemoryAllocateZeroed = {};
  settingsD3DMemoryAllocateZeroed.settings                = REDX_CONTEXT_OPTIONAL_SETTINGS_D3D_MEMORY_ALLOCATE_ZEROED;
  settingsD3DMemoryAllocateZeroed.next                    = NULL;
  settingsD3DMemoryAllocateZeroed.d3dMemoryAllocateZeroed = 1;
  RedXContextOptionalSettingsD3DFeatureLevel settingsD3DFeatureLevel = {};
  settingsD3DFeatureLevel.settings        = REDX_CONTEXT_OPTIONAL_SETTINGS_D3D_FEATURE_LEVEL;
  settingsD3DFeatureLevel.next            = &settingsD3DMemoryAllocateZeroed;
  settingsD3DFeatureLevel.d3dFeatureLevel = 0xc000; // D3D_FEATURE_LEVEL_12_0 // 0xc100; // D3D_FEATURE_LEVEL_12_1
  np_redCreateContext(
    _8b4eaa17_malloc(malloc),
    _8b4eaa17_free(free),
    _8b4eaa17_optionalMallocTagged(NULL),
    _8b4eaa17_optionalFreeTagged(NULL),
    _8b4eaa17_debugCallback(NULL),
    _8b4eaa17_sdkVersion(RED_SDK_VERSION_1_0_135),
    _8b4eaa17_sdkExtensionsCount(0),
    _8b4eaa17_sdkExtensions(NULL),
    _8b4eaa17_optionalProgramName(NULL),
    _8b4eaa17_optionalProgramVersion(0),
    _8b4eaa17_optionalEngineName(NULL),
    _8b4eaa17_optionalEngineVersion(0),
    _8b4eaa17_optionalSettings(&settingsD3DFeatureLevel),
    _8b4eaa17_outContext(&g_redcontext),
    _8b4eaa17_outStatuses(NULL),
    _8b4eaa17_optionalFile(__FILE__),
    _8b4eaa17_optionalLine(__LINE__),
    _8b4eaa17_optionalUserData(NULL)
  );

  panic(g_redcontext == NULL);
  panic(g_redcontext->gpusCount == 0);

  int windowWidth  = 800;
  int windowHeight = 800;

  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  g_window = glfwCreateWindow(windowWidth, windowHeight, "REDGPU X App", NULL, NULL);
  glfwSetKeyCallback(g_window, keyCallback);
  glfwSetScrollCallback(g_window, mouseScrollCallback);
  glfwSetWindowIconifyCallback(g_window, windowIconifyCallback);

  glfwGetFramebufferSize(g_window, &windowWidth, &windowHeight);
  const GLFWvidmode * vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

  int screenWidth  = vidmode->width;
  int screenHeight = vidmode->height;

  RedHandleSurface surface = NULL;
  np_redCreateSurfaceWin32(
    _976dd369_context(g_redcontext),
    _976dd369_gpu(g_redcontext->gpus[0].gpu),
    _976dd369_handleName(NULL),
    _976dd369_win32Hinstance(GetModuleHandleA(NULL)),
    _976dd369_win32Hwnd(glfwGetWin32Window(g_window)),
    _976dd369_outSurface(&surface),
    _976dd369_outStatuses(NULL),
    _976dd369_optionalFile(__FILE__),
    _976dd369_optionalLine(__LINE__),
    _976dd369_optionalUserData(NULL)
  );

  // Dear ImGui setup

  g_imguiWindowData.Width           = 0;
  g_imguiWindowData.Height          = 0;
  g_imguiWindowData.Swapchain       = 0;
  g_imguiWindowData.Surface         = surface;
  g_imguiWindowData.SurfaceFormat   = RED_FORMAT_PRESENT_BGRA_8_8_8_8_UINT_TO_FLOAT_0_1;
  g_imguiWindowData.PresentMode     = RED_PRESENT_VSYNC_MODE_ON;
  g_imguiWindowData.RenderPass      = NULL;
  g_imguiWindowData.Pipeline        = NULL;
  g_imguiWindowData.ClearEnable     = 1;
  g_imguiWindowData.ClearValues[0]  = 1.f;
  g_imguiWindowData.ClearValues[1]  = 1.f;
  g_imguiWindowData.ClearValues[2]  = 1.f;
  g_imguiWindowData.ClearValues[3]  = 1.f;
  g_imguiWindowData.FrameIndex      = 0;
  g_imguiWindowData.ImageCount      = 0;
  g_imguiWindowData.SemaphoreIndex  = 0;
  g_imguiWindowData.Frames          = 0;
  g_imguiWindowData.FrameSemaphores = 0;
  void * windowHandle = glfwGetWin32Window(g_window);
  ImGui_ImplRedGpuH_CreateOrResizeWindow(g_redcontext, 0, g_redcontext->gpus[0].gpuDevice, g_redcontext->gpus[0].gpu, g_redcontext->gpus[0].queues[0], &g_imguiWindowData, g_redcontext->gpus[0].queuesFamilyIndex[0], windowWidth, windowHeight, g_frameCount, windowHandle, screenWidth, screenHeight);

  ImGui::CreateContext();
  ImGuiIO & io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

  ImGui::StyleColorsDark();
  ImGuiStyle & style = ImGui::GetStyle();
  style.Colors[ImGuiCol_WindowBg].w = 0.995f;
  //ImGui::StyleColorsClassic();

  np_redStructsMemoryAllocateWithInlineSamplers(
    _27d7343d_context(g_redcontext),
    _27d7343d_gpu(g_redcontext->gpus[0].gpu),
    _27d7343d_handleName(NULL),
    _27d7343d_maxStructsCount(g_frameCount),
    _27d7343d_maxStructsMembersOfTypeArrayROConstantCount(0),
    _27d7343d_maxStructsMembersOfTypeArrayROOrArrayRWCount(0),
    _27d7343d_maxStructsMembersOfTypeTextureROCount(1 * g_frameCount),
    _27d7343d_maxStructsMembersOfTypeTextureRWCount(0),
    _27d7343d_maxStructsMembersOfTypeInlineSamplerCount(1 * g_frameCount),
    _27d7343d_outStructsMemory(&g_imguiStructsMemory),
    _27d7343d_outStatuses(NULL),
    _27d7343d_optionalFile(__FILE__),
    _27d7343d_optionalLine(__LINE__),
    _27d7343d_optionalUserData(NULL)
  );

  ImGui_ImplGlfw_InitForVulkan(g_window, true);
  g_imguiRedGpuInitInfo.Instance               = g_redcontext;
  g_imguiRedGpuInitInfo.PhysicalDevice         = g_redcontext->gpus[0].gpuDevice;
  g_imguiRedGpuInitInfo.Device                 = g_redcontext->gpus[0].gpu;
  g_imguiRedGpuInitInfo.QueueFamily            = g_redcontext->gpus[0].queuesFamilyIndex[0];
  g_imguiRedGpuInitInfo.PipelineCache          = NULL;
  g_imguiRedGpuInitInfo.DescriptorPool         = g_imguiStructsMemory;
  g_imguiRedGpuInitInfo.DescriptorPoolSamplers = NULL;
  g_imguiRedGpuInitInfo.Subpass                = 0;
  g_imguiRedGpuInitInfo.MinImageCount          = g_frameCount;
  g_imguiRedGpuInitInfo.ImageCount             = g_imguiWindowData.ImageCount;
  g_imguiRedGpuInitInfo.MSAASamples            = RED_MULTISAMPLE_COUNT_BITFLAG_1;
  ImGui_ImplRedGpu_Init(&g_imguiRedGpuInitInfo, g_imguiWindowData.RenderPass);

  uiRebuildFont(false, g_imguiUiScale);

  while (!glfwWindowShouldClose(g_window)) {
    if (g_windowIsIconified) {
      glfwWaitEvents();
      continue;
    } else {
      glfwPollEvents();
    }

    np_redCpuSignalWait(
      _4a826452_context(g_redcontext),
      _4a826452_gpu(g_redcontext->gpus[0].gpu),
      _4a826452_cpuSignalsCount(1),
      _4a826452_cpuSignals(&g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].Fence),
      _4a826452_waitAll(1),
      _4a826452_outStatuses(NULL),
      _4a826452_optionalFile(__FILE__),
      _4a826452_optionalLine(__LINE__),
      _4a826452_optionalUserData(NULL)
    );
    np_redCpuSignalUnsignal(
      _fd52e10b_context(g_redcontext),
      _fd52e10b_gpu(g_redcontext->gpus[0].gpu),
      _fd52e10b_cpuSignalsCount(1),
      _fd52e10b_cpuSignals(&g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].Fence),
      _fd52e10b_outStatuses(NULL),
      _fd52e10b_optionalFile(__FILE__),
      _fd52e10b_optionalLine(__LINE__),
      _fd52e10b_optionalUserData(NULL)
    );

    np_redPresentGetImageIndex(
      _0850d50a_context(g_redcontext),
      _0850d50a_gpu(g_redcontext->gpus[0].gpu),
      _0850d50a_present(g_imguiWindowData.Swapchain),
      _0850d50a_signalCpuSignal(NULL),
      _0850d50a_signalGpuSignal(g_imguiWindowData.FrameSemaphores[g_imguiWindowData.SemaphoreIndex].ImageAcquiredSemaphore),
      _0850d50a_outImageIndex(&g_imguiWindowData.FrameIndex),
      _0850d50a_outStatuses(NULL),
      _0850d50a_optionalFile(__FILE__),
      _0850d50a_optionalLine(__LINE__),
      _0850d50a_optionalUserData(NULL)
    );

    ImGui_ImplRedGpu_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::ShowDemoWindow();

    ImGui::Render();

    np_redCallsSet(
      _23514538_context(g_redcontext),
      _23514538_gpu(g_redcontext->gpus[0].gpu),
      _23514538_calls(g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].CommandBuffer.handle),
      _23514538_callsMemory(g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].CommandBuffer.memory),
      _23514538_callsReusable(g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].CommandBuffer.reusable),
      _23514538_outStatuses(NULL),
      _23514538_optionalFile(__FILE__),
      _23514538_optionalLine(__LINE__),
      _23514538_optionalUserData(NULL)
    );

    {
      RedXBarrier imageUsage = {};
      imageUsage.usage.setTo0      = 0;
      imageUsage.usage.split       = RED_BARRIER_SPLIT_NONE;
      imageUsage.usage.resource    = redXGetHandleResourceImage(g_redcontext, g_redcontext->gpus[0].gpu, g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].Backbuffer);
      imageUsage.usage.level       = -1;
      imageUsage.usage.oldAccesses = REDX_ACCESS_BITFLAG_PRESENT;
      imageUsage.usage.newAccesses = REDX_ACCESS_BITFLAG_OUTPUT_COLOR_W;
      np_redXCallUsageAliasOrderBarrier(
        _c0b32403_calls(g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].CommandBuffer.handle),
        _c0b32403_barriersCount(1),
        _c0b32403_barriers(&imageUsage)
      );
    }

    RedColorsClearValuesFloat clearValues = {};
    clearValues.r[0] = g_imguiWindowData.ClearValues[0];
    clearValues.g[0] = g_imguiWindowData.ClearValues[1];
    clearValues.b[0] = g_imguiWindowData.ClearValues[2];
    clearValues.a[0] = g_imguiWindowData.ClearValues[3];
    RedSetProcedureOutputOp color0SetOp = g_imguiWindowData.ClearEnable ? RED_SET_PROCEDURE_OUTPUT_OP_CLEAR : RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE;
    np_redXCallSetProcedureOutput(
      _c5f24e0c_calls(g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].CommandBuffer.handle),
      _c5f24e0c_depthStencil(NULL),
      _c5f24e0c_colorsCount(1),
      _c5f24e0c_colors(&g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].BackbufferView),
      _c5f24e0c_depthSetProcedureOutputOp(RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE),
      _c5f24e0c_stencilSetProcedureOutputOp(RED_SET_PROCEDURE_OUTPUT_OP_PRESERVE),
      _c5f24e0c_colorsSetProcedureOutputOp(&color0SetOp),
      _c5f24e0c_depthClearValue(0.f),
      _c5f24e0c_stencilClearValue(0),
      _c5f24e0c_colorsClearValuesFloat(&clearValues)
    );

    ImGui_ImplRedGpu_RenderDrawData(ImGui::GetDrawData(), g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].CommandBuffer.handle, NULL);

    RedEndProcedureOutputOp color0EndOp = RED_END_PROCEDURE_OUTPUT_OP_PRESERVE;
    np_redXCallEndProcedureOutput(
      _3ac44cde_calls(g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].CommandBuffer.handle),
      _3ac44cde_resolveTargetColors(NULL),
      _3ac44cde_resolveTargetColorsFormat(NULL),
      _3ac44cde_depthEndProcedureOutputOp(RED_END_PROCEDURE_OUTPUT_OP_PRESERVE),
      _3ac44cde_stencilEndProcedureOutputOp(RED_END_PROCEDURE_OUTPUT_OP_PRESERVE),
      _3ac44cde_colorsEndProcedureOutputOp(&color0EndOp)
    );

    {
      RedXBarrier imageUsage = {};
      imageUsage.usage.setTo0      = 0;
      imageUsage.usage.split       = RED_BARRIER_SPLIT_NONE;
      imageUsage.usage.resource    = redXGetHandleResourceImage(g_redcontext, g_redcontext->gpus[0].gpu, g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].Backbuffer);
      imageUsage.usage.level       = -1;
      imageUsage.usage.oldAccesses = REDX_ACCESS_BITFLAG_OUTPUT_COLOR_W;
      imageUsage.usage.newAccesses = REDX_ACCESS_BITFLAG_PRESENT;
      np_redXCallUsageAliasOrderBarrier(
        _c0b32403_calls(g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].CommandBuffer.handle),
        _c0b32403_barriersCount(1),
        _c0b32403_barriers(&imageUsage)
      );
    }

    np_redCallsEnd(
      _2566f99f_context(g_redcontext),
      _2566f99f_gpu(g_redcontext->gpus[0].gpu),
      _2566f99f_calls(g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].CommandBuffer.handle),
      _2566f99f_callsMemory(g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].CommandBuffer.memory),
      _2566f99f_outStatuses(NULL),
      _2566f99f_optionalFile(__FILE__),
      _2566f99f_optionalLine(__LINE__),
      _2566f99f_optionalUserData(NULL)
    );

    {
      RedGpuTimeline timelines[1] = {};
      unsigned array65536[1] = {65536};
      timelines[0].setTo4                            = 4;
      timelines[0].setTo0                            = 0;
      timelines[0].waitForAndUnsignalGpuSignalsCount = 1;
      timelines[0].waitForAndUnsignalGpuSignals      = &g_imguiWindowData.FrameSemaphores[g_imguiWindowData.SemaphoreIndex].ImageAcquiredSemaphore;
      timelines[0].setTo65536                        = array65536;
      timelines[0].callsCount                        = 1;
      timelines[0].calls                             = &g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].CommandBuffer.handle;
      timelines[0].signalGpuSignalsCount             = 1;
      timelines[0].signalGpuSignals                  = &g_imguiWindowData.FrameSemaphores[g_imguiWindowData.SemaphoreIndex].RenderCompleteSemaphore;
      np_redQueueSubmit(
        _dcc70647_context(g_redcontext),
        _dcc70647_gpu(g_redcontext->gpus[0].gpu),
        _dcc70647_queue(g_redcontext->gpus[0].queues[0]),
        _dcc70647_timelinesCount(1),
        _dcc70647_timelines(timelines),
        _dcc70647_signalCpuSignal(g_imguiWindowData.Frames[g_imguiWindowData.FrameIndex].Fence),
        _dcc70647_outStatuses(NULL),
        _dcc70647_optionalFile(__FILE__),
        _dcc70647_optionalLine(__LINE__),
        _dcc70647_optionalUserData(NULL)
      );
    }

    np_redQueuePresent(
      _e942825c_context(g_redcontext),
      _e942825c_gpu(g_redcontext->gpus[0].gpu),
      _e942825c_queue(g_redcontext->gpus[0].queues[0]),
      _e942825c_waitForAndUnsignalGpuSignalsCount(1),
      _e942825c_waitForAndUnsignalGpuSignals(&g_imguiWindowData.FrameSemaphores[g_imguiWindowData.SemaphoreIndex].RenderCompleteSemaphore),
      _e942825c_presentsCount(1),
      _e942825c_presents(&g_imguiWindowData.Swapchain),
      _e942825c_presentsImageIndex(&g_imguiWindowData.FrameIndex),
      _e942825c_outPresentsStatus(NULL),
      _e942825c_outStatuses(NULL),
      _e942825c_optionalFile(__FILE__),
      _e942825c_optionalLine(__LINE__),
      _e942825c_optionalUserData(NULL)
    );

    g_imguiWindowData.SemaphoreIndex = (g_imguiWindowData.SemaphoreIndex + 1) % g_imguiWindowData.ImageCount;
  }

  glfwDestroyWindow(g_window);
}

// FILE(Constantine): droid_sans_mono.c

#include <stddef.h>

#ifdef __cplusplus
extern "C"
#endif
size_t gDroidSansMonoFontGetBytesCount() {
  return 117072;
}

#ifdef __cplusplus
extern "C"
#endif
unsigned char gDroidSansMonoFont[] = {
  0, 1, 0, 0, 0, 14, 0, 128, 0, 3, 0, 96, 79, 83, 47, 50, 161, 19, 150, 198, 0,
  0, 1, 104, 0, 0, 0, 96, 99, 109, 97, 112, 233, 125, 86, 20, 0, 0, 8, 208, 0,
  0, 7, 54, 99, 118, 116, 32, 68, 157, 77, 114, 0, 0, 25, 144, 0, 0, 2, 16, 102,
  112, 103, 109, 115, 211, 35, 176, 0, 0, 16, 8, 0, 0, 7, 5, 103, 97, 115, 112,
  0, 4, 0, 7, 0, 1, 201, 68, 0, 0, 0, 12, 103, 108, 121, 102, 251, 142, 20, 149,
  0, 0, 34, 168, 0, 1, 130, 142, 104, 101, 97, 100, 237, 46, 186, 243, 0, 0, 0,
  236, 0, 0, 0, 54, 104, 104, 101, 97, 12, 97, 2, 78, 0, 0, 1, 36, 0, 0, 0, 36,
  104, 109, 116, 120, 248, 204, 244, 91, 0, 0, 1, 200, 0, 0, 7, 6, 108, 111, 99,
  97, 245, 66, 148, 216, 0, 0, 27, 160, 0, 0, 7, 6, 109, 97, 120, 112, 5, 235,
  2, 119, 0, 0, 1, 72, 0, 0, 0, 32, 110, 97, 109, 101, 123, 244, 226, 39, 0, 1,
  165, 56, 0, 0, 6, 204, 112, 111, 115, 116, 216, 80, 169, 40, 0, 1, 172, 4, 0,
  0, 29, 63, 112, 114, 101, 112, 65, 189, 218, 130, 0, 0, 23, 16, 0, 0, 2, 126,
  0, 1, 0, 0, 0, 1, 0, 0, 127, 144, 68, 186, 95, 15, 60, 245, 0, 11, 8, 0, 0, 0,
  0, 0, 193, 199, 233, 84, 0, 0, 0, 0, 200, 92, 134, 89, 254, 200, 253, 213, 5,
  35, 8, 115, 0, 0, 0, 9, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 8, 115, 253, 213,
  0, 0, 4, 205, 254, 200, 255, 170, 5, 35, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 3, 130, 0, 144, 0, 18, 0, 82, 0, 5, 0, 2, 0, 16,
  0, 47, 0, 90, 0, 0, 1, 228, 1, 99, 0, 3, 0, 1, 0, 3, 4, 205, 1, 144, 0, 5, 0,
  8, 5, 154, 5, 51, 0, 0, 1, 30, 5, 154, 5, 51, 0, 0, 3, 208, 0, 102, 1, 242, 0,
  0, 2, 11, 6, 9, 3, 8, 4, 2, 2, 4, 224, 0, 2, 239, 64, 0, 32, 91, 0, 0, 0, 40,
  0, 0, 0, 0, 49, 65, 83, 67, 0, 64, 0, 32, 255, 253, 6, 31, 254, 20, 0, 132, 8,
  115, 2, 43, 32, 0, 1, 159, 0, 0, 0, 0, 4, 74, 5, 182, 0, 0, 0, 32, 0, 0, 4,
  205, 0, 193, 0, 0, 0, 0, 0, 0, 1, 231, 1, 29, 0, 45, 0, 182, 0, 0, 0, 61, 1,
  240, 1, 39, 1, 41, 0, 133, 0, 152, 1, 184, 1, 29, 1, 207, 0, 211, 0, 147, 0,
  225, 0, 158, 0, 131, 0, 61, 0, 172, 0, 154, 0, 143, 0, 156, 0, 154, 1, 231, 1,
  154, 0, 152, 0, 152, 0, 152, 0, 168, 0, 31, 0, 33, 0, 135, 0, 129, 0, 135, 0,
  217, 0, 244, 0, 117, 0, 135, 0, 225, 0, 137, 0, 211, 0, 233, 0, 113, 0, 135,
  0, 84, 0, 176, 0, 84, 0, 186, 0, 141, 0, 102, 0, 125, 0, 33, 0, 2, 0, 53, 0,
  33, 0, 102, 1, 156, 0, 211, 1, 33, 0, 111, 255, 240, 1, 162, 0, 135, 0, 158,
  0, 172, 0, 137, 0, 133, 0, 156, 0, 102, 0, 160, 0, 197, 0, 135, 0, 215, 0,
  188, 0, 92, 0, 160, 0, 115, 0, 158, 0, 137, 1, 8, 0, 203, 0, 139, 0, 160, 0,
  82, 255, 252, 0, 96, 0, 82, 0, 182, 0, 225, 2, 27, 0, 227, 0, 152, 0, 0, 1,
  231, 0, 172, 0, 119, 0, 174, 0, 78, 2, 27, 0, 244, 1, 74, 0, 6, 1, 20, 0, 197,
  0, 152, 1, 29, 0, 6, 255, 236, 1, 43, 0, 152, 1, 92, 1, 86, 1, 162, 0, 180, 0,
  66, 1, 231, 1, 172, 1, 111, 1, 25, 0, 197, 0, 22, 0, 3, 0, 21, 0, 168, 0, 33,
  0, 33, 0, 33, 0, 33, 0, 33, 0, 33, 0, 0, 0, 129, 0, 217, 0, 217, 0, 217, 0,
  217, 0, 225, 0, 225, 0, 225, 0, 225, 0, 0, 0, 135, 0, 84, 0, 84, 0, 84, 0, 84,
  0, 84, 0, 190, 0, 80, 0, 125, 0, 125, 0, 125, 0, 125, 0, 33, 0, 176, 0, 164,
  0, 135, 0, 135, 0, 135, 0, 135, 0, 135, 0, 135, 0, 45, 0, 172, 0, 133, 0, 133,
  0, 133, 0, 133, 0, 197, 0, 197, 0, 197, 0, 197, 0, 135, 0, 160, 0, 115, 0,
  115, 0, 115, 0, 115, 0, 115, 0, 152, 0, 115, 0, 160, 0, 160, 0, 160, 0, 160,
  0, 82, 0, 158, 0, 82, 0, 33, 0, 135, 0, 33, 0, 135, 0, 33, 0, 135, 0, 129, 0,
  172, 0, 129, 0, 172, 0, 129, 0, 172, 0, 129, 0, 172, 0, 135, 0, 79, 0, 0, 0,
  137, 0, 217, 0, 133, 0, 217, 0, 133, 0, 217, 0, 133, 0, 217, 0, 133, 0, 217,
  0, 133, 0, 117, 0, 102, 0, 117, 0, 102, 0, 117, 0, 102, 0, 117, 0, 102, 0,
  135, 0, 160, 0, 0, 0, 4, 0, 225, 0, 197, 0, 225, 0, 197, 0, 225, 0, 197, 0,
  225, 0, 197, 0, 225, 0, 197, 0, 156, 0, 188, 0, 137, 0, 135, 0, 211, 0, 215,
  0, 215, 0, 233, 0, 188, 0, 233, 0, 188, 0, 233, 0, 188, 0, 233, 0, 188, 0, 72,
  0, 188, 0, 135, 0, 160, 0, 135, 0, 160, 0, 135, 0, 160, 255, 240, 0, 135, 0,
  160, 0, 84, 0, 115, 0, 84, 0, 115, 0, 84, 0, 115, 0, 20, 0, 57, 0, 186, 1, 8,
  0, 186, 0, 187, 0, 186, 1, 8, 0, 141, 0, 203, 0, 141, 0, 203, 0, 141, 0, 203,
  0, 141, 0, 203, 0, 102, 0, 139, 0, 102, 0, 139, 0, 102, 0, 139, 0, 125, 0,
  160, 0, 125, 0, 160, 0, 125, 0, 160, 0, 125, 0, 160, 0, 125, 0, 160, 0, 125,
  0, 160, 0, 2, 255, 252, 0, 33, 0, 82, 0, 33, 0, 102, 0, 182, 0, 102, 0, 182,
  0, 102, 0, 182, 1, 100, 0, 215, 0, 33, 0, 135, 0, 0, 0, 45, 0, 80, 0, 115, 0,
  141, 0, 203, 1, 27, 1, 27, 1, 70, 1, 57, 1, 252, 1, 131, 1, 158, 0, 254, 0,
  246, 1, 223, 1, 43, 0, 33, 1, 231, 255, 142, 255, 101, 255, 163, 255, 124,
  255, 19, 255, 122, 0, 241, 0, 33, 0, 135, 0, 246, 0, 68, 0, 217, 0, 102, 0,
  135, 0, 84, 0, 225, 0, 211, 0, 33, 0, 113, 0, 135, 0, 111, 0, 84, 0, 135, 0,
  176, 0, 131, 0, 102, 0, 33, 0, 27, 0, 53, 0, 57, 0, 74, 0, 225, 0, 33, 0, 121,
  0, 201, 0, 160, 1, 172, 0, 160, 0, 121, 0, 158, 0, 82, 0, 135, 0, 201, 0, 162,
  0, 160, 0, 147, 1, 172, 0, 215, 0, 61, 0, 160, 0, 61, 0, 172, 0, 115, 0, 14,
  0, 158, 0, 172, 0, 129, 0, 106, 0, 160, 0, 74, 0, 43, 0, 80, 0, 90, 1, 3, 0,
  160, 0, 115, 0, 160, 0, 90, 0, 217, 0, 23, 0, 246, 0, 129, 0, 141, 0, 225, 0,
  225, 0, 137, 0, 0, 0, 66, 0, 23, 0, 211, 0, 27, 0, 135, 0, 33, 0, 135, 0, 135,
  0, 246, 0, 6, 0, 217, 0, 0, 0, 139, 0, 137, 0, 137, 0, 211, 0, 4, 0, 113, 0,
  135, 0, 84, 0, 135, 0, 176, 0, 129, 0, 102, 0, 27, 0, 27, 0, 53, 0, 135, 0,
  135, 0, 121, 0, 61, 0, 27, 0, 96, 0, 176, 0, 68, 0, 98, 0, 57, 0, 135, 0, 143,
  0, 176, 1, 35, 0, 33, 0, 133, 0, 0, 0, 201, 0, 160, 0, 160, 0, 215, 0, 31, 0,
  115, 0, 160, 0, 115, 0, 160, 0, 158, 0, 172, 0, 121, 0, 82, 0, 74, 0, 96, 0,
  152, 0, 152, 0, 125, 0, 109, 0, 43, 0, 113, 0, 217, 0, 184, 0, 123, 0, 115, 0,
  133, 0, 4, 1, 35, 0, 172, 0, 203, 0, 197, 0, 197, 0, 135, 0, 0, 0, 106, 0, 4,
  0, 215, 0, 82, 0, 160, 0, 246, 1, 35, 0, 2, 255, 252, 0, 2, 255, 252, 0, 2,
  255, 252, 0, 33, 0, 82, 0, 184, 255, 250, 255, 250, 255, 236, 1, 190, 1, 190,
  1, 201, 1, 190, 0, 233, 0, 233, 0, 244, 0, 240, 0, 229, 1, 123, 0, 78, 0, 4,
  1, 240, 1, 29, 1, 145, 1, 145, 0, 255, 0, 170, 1, 61, 0, 129, 0, 119, 0, 82,
  0, 96, 0, 8, 0, 227, 0, 25, 0, 0, 0, 74, 0, 82, 0, 18, 0, 11, 0, 24, 0, 28, 0,
  121, 0, 74, 0, 156, 0, 74, 0, 152, 0, 23, 0, 70, 0, 236, 0, 152, 0, 152, 0,
  152, 0, 152, 0, 125, 0, 49, 0, 49, 0, 231, 0, 135, 1, 238, 1, 227, 1, 227, 1,
  57, 1, 37, 1, 80, 1, 57, 1, 111, 1, 49, 1, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55, 0, 4, 0, 135, 1, 190,
  0, 10, 0, 31, 0, 18, 0, 113, 0, 92, 0, 33, 0, 135, 254, 200, 1, 131, 1, 45, 0,
  66, 0, 66, 0, 84, 0, 115, 0, 125, 0, 160, 1, 162, 1, 162, 0, 254, 1, 172, 1,
  252, 0, 217, 0, 137, 0, 133, 0, 160, 0, 82, 255, 252, 0, 20, 0, 20, 0, 98, 0,
  160, 0, 0, 0, 61, 0, 98, 0, 123, 0, 0, 0, 10, 0, 92, 0, 123, 0, 117, 0, 143,
  0, 57, 0, 80, 0, 84, 0, 115, 0, 63, 0, 82, 0, 63, 0, 82, 0, 70, 0, 80, 0, 84,
  0, 115, 0, 82, 0, 88, 0, 82, 255, 252, 0, 129, 0, 172, 0, 94, 0, 242, 0, 242,
  1, 225, 1, 225, 0, 41, 0, 41, 0, 137, 0, 178, 0, 47, 0, 61, 0, 176, 0, 158, 0,
  147, 0, 135, 0, 160, 0, 215, 0, 0, 0, 0, 0, 139, 0, 201, 0, 211, 0, 215, 0,
  211, 0, 215, 0, 59, 0, 59, 0, 23, 0, 43, 0, 135, 0, 160, 0, 135, 0, 160, 0,
  106, 0, 127, 0, 84, 0, 115, 0, 129, 0, 172, 0, 102, 0, 121, 0, 33, 0, 82, 0,
  33, 0, 82, 0, 53, 0, 96, 0, 23, 0, 20, 0, 135, 0, 152, 0, 135, 0, 152, 0, 135,
  0, 168, 255, 248, 255, 213, 255, 248, 255, 213, 0, 225, 0, 0, 0, 0, 0, 135, 0,
  215, 0, 4, 0, 31, 0, 135, 0, 160, 0, 135, 0, 160, 0, 135, 0, 152, 0, 113, 0,
  115, 0, 225, 0, 33, 0, 135, 0, 33, 0, 135, 0, 0, 0, 45, 0, 217, 0, 133, 0, 84,
  0, 133, 0, 84, 0, 133, 0, 0, 0, 0, 0, 139, 0, 201, 0, 158, 0, 170, 0, 137, 0,
  160, 0, 137, 0, 160, 0, 84, 0, 115, 0, 84, 0, 115, 0, 84, 0, 115, 0, 68, 0,
  184, 0, 27, 0, 82, 0, 27, 0, 82, 0, 27, 0, 82, 0, 135, 0, 152, 1, 43, 1, 35,
  0, 96, 0, 113, 0, 147, 0, 135, 0, 53, 0, 96, 0, 53, 0, 96, 0, 137, 0, 137, 0,
  49, 0, 49, 0, 35, 0, 43, 0, 39, 0, 80, 0, 0, 0, 0, 0, 121, 0, 123, 0, 117, 0,
  113, 0, 20, 0, 41, 0, 166, 0, 201, 0, 4, 0, 31, 0, 33, 0, 135, 0, 33, 0, 135,
  0, 33, 0, 135, 0, 33, 0, 85, 0, 33, 0, 135, 0, 33, 0, 135, 0, 33, 0, 135, 0,
  33, 0, 135, 0, 33, 0, 135, 0, 33, 0, 135, 0, 33, 0, 135, 0, 33, 0, 135, 0,
  217, 0, 133, 0, 217, 0, 133, 0, 217, 0, 133, 0, 217, 0, 133, 0, 89, 0, 76, 0,
  217, 0, 133, 0, 217, 0, 133, 0, 217, 0, 133, 0, 225, 0, 197, 0, 225, 0, 197,
  0, 84, 0, 115, 0, 84, 0, 115, 0, 84, 0, 115, 0, 74, 0, 74, 0, 84, 0, 115, 0,
  84, 0, 115, 0, 84, 0, 115, 0, 84, 0, 115, 0, 84, 0, 115, 0, 84, 0, 115, 0, 84,
  0, 115, 0, 84, 0, 115, 0, 125, 0, 160, 0, 125, 0, 160, 0, 125, 0, 160, 0, 125,
  0, 160, 0, 125, 0, 160, 0, 125, 0, 160, 0, 125, 0, 160, 0, 33, 0, 82, 0, 33,
  0, 82, 0, 33, 0, 82, 0, 137, 0, 205, 0, 188, 0, 188, 0, 221, 1, 35, 1, 57, 1,
  57, 1, 57, 1, 35, 1, 199, 1, 178, 1, 178, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0,
  0, 28, 0, 1, 0, 0, 0, 0, 5, 42, 0, 3, 0, 1, 0, 0, 0, 28, 0, 4, 5, 14, 0, 0, 0,
  134, 0, 128, 0, 6, 0, 6, 0, 126, 1, 127, 1, 146, 1, 161, 1, 176, 1, 240, 1,
  255, 2, 25, 2, 188, 2, 199, 2, 201, 2, 221, 2, 243, 3, 1, 3, 3, 3, 9, 3, 15,
  3, 35, 3, 138, 3, 140, 3, 161, 3, 206, 3, 210, 3, 214, 4, 134, 5, 19, 30, 1,
  30, 63, 30, 133, 30, 249, 31, 77, 32, 11, 32, 21, 32, 30, 32, 34, 32, 38, 32,
  48, 32, 51, 32, 58, 32, 60, 32, 68, 32, 127, 32, 164, 32, 167, 32, 172, 33, 5,
  33, 19, 33, 22, 33, 34, 33, 38, 33, 46, 33, 94, 34, 2, 34, 6, 34, 15, 34, 18,
  34, 26, 34, 30, 34, 43, 34, 72, 34, 96, 34, 101, 37, 202, 251, 4, 254, 255,
  255, 253, 255, 255, 0, 0, 0, 32, 0, 160, 1, 146, 1, 160, 1, 175, 1, 240, 1,
  250, 2, 24, 2, 188, 2, 198, 2, 201, 2, 216, 2, 243, 3, 0, 3, 3, 3, 9, 3, 15,
  3, 35, 3, 132, 3, 140, 3, 142, 3, 163, 3, 209, 3, 214, 4, 0, 4, 136, 30, 0,
  30, 62, 30, 128, 30, 160, 31, 77, 32, 0, 32, 19, 32, 23, 32, 32, 32, 38, 32,
  48, 32, 50, 32, 57, 32, 60, 32, 68, 32, 127, 32, 163, 32, 167, 32, 171, 33, 5,
  33, 19, 33, 22, 33, 34, 33, 38, 33, 46, 33, 91, 34, 2, 34, 6, 34, 15, 34, 17,
  34, 26, 34, 30, 34, 43, 34, 72, 34, 96, 34, 100, 37, 202, 251, 1, 254, 255,
  255, 252, 255, 255, 255, 227, 255, 194, 255, 176, 0, 191, 0, 178, 0, 97, 255,
  73, 255, 49, 255, 150, 254, 133, 254, 132, 254, 118, 255, 104, 255, 99, 255,
  98, 255, 93, 0, 103, 255, 68, 253, 208, 253, 207, 253, 206, 253, 205, 254,
  130, 254, 127, 0, 0, 0, 0, 228, 88, 228, 24, 227, 122, 0, 0, 227, 13, 226, 66,
  225, 239, 225, 238, 225, 237, 225, 234, 225, 225, 225, 224, 225, 219, 225,
  218, 225, 211, 225, 153, 225, 118, 225, 116, 0, 0, 225, 24, 225, 11, 225, 9,
  224, 254, 224, 251, 224, 244, 224, 200, 224, 37, 224, 34, 224, 26, 224, 25,
  224, 18, 224, 15, 224, 3, 223, 231, 223, 208, 223, 205, 220, 105, 0, 0, 3, 79,
  2, 83, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 86, 1, 98, 0, 0, 0, 0, 0, 0, 2, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 2, 230, 0, 0, 0, 0, 0, 0, 2, 104, 1, 156, 1, 157, 1, 158, 1, 159, 1, 160,
  1, 161, 1, 162, 1, 163, 1, 164, 1, 165, 1, 166, 1, 167, 2, 105, 1, 168, 1,
  169, 1, 170, 1, 171, 1, 172, 1, 173, 1, 174, 1, 175, 1, 176, 1, 177, 1, 178,
  1, 179, 1, 180, 1, 181, 1, 182, 1, 183, 1, 184, 1, 185, 1, 186, 1, 187, 1,
  188, 1, 189, 1, 190, 1, 191, 1, 192, 1, 193, 1, 194, 1, 195, 1, 196, 1, 197,
  1, 198, 1, 199, 1, 200, 1, 201, 1, 202, 1, 203, 1, 204, 1, 205, 1, 206, 1,
  207, 1, 208, 1, 209, 1, 210, 1, 211, 1, 212, 1, 213, 1, 214, 1, 215, 1, 216,
  1, 217, 1, 218, 1, 219, 1, 220, 1, 221, 1, 222, 1, 223, 1, 224, 1, 225, 1,
  226, 1, 227, 1, 228, 1, 229, 1, 230, 1, 231, 1, 232, 1, 233, 2, 106, 1, 234,
  1, 235, 1, 236, 1, 237, 1, 238, 1, 239, 1, 240, 1, 241, 1, 242, 1, 243, 1,
  244, 1, 245, 2, 107, 1, 246, 1, 247, 2, 108, 2, 109, 2, 110, 2, 111, 2, 112,
  2, 113, 2, 114, 2, 115, 2, 116, 2, 117, 2, 118, 2, 119, 2, 120, 2, 121, 2,
  122, 2, 123, 2, 124, 2, 125, 2, 126, 2, 127, 2, 128, 2, 129, 2, 130, 2, 131,
  2, 132, 2, 133, 2, 134, 2, 135, 2, 136, 2, 137, 2, 138, 2, 139, 2, 140, 2,
  141, 2, 142, 2, 143, 2, 144, 2, 145, 2, 146, 2, 147, 2, 148, 2, 149, 2, 150,
  2, 151, 2, 152, 2, 153, 2, 154, 1, 248, 1, 249, 2, 155, 2, 156, 2, 157, 2,
  158, 2, 159, 2, 160, 2, 161, 2, 162, 2, 163, 2, 164, 2, 165, 2, 166, 2, 167,
  2, 168, 2, 169, 2, 170, 2, 171, 2, 172, 2, 173, 2, 174, 2, 175, 2, 176, 2,
  177, 2, 178, 2, 179, 2, 180, 2, 181, 2, 182, 2, 183, 2, 184, 2, 185, 2, 186,
  2, 187, 2, 188, 2, 189, 2, 190, 2, 191, 2, 192, 2, 193, 2, 194, 2, 195, 2,
  196, 2, 197, 2, 198, 2, 199, 2, 200, 2, 201, 2, 202, 2, 203, 2, 204, 2, 205,
  2, 206, 2, 207, 2, 208, 2, 209, 2, 210, 2, 211, 2, 212, 2, 213, 2, 214, 2,
  215, 2, 216, 2, 217, 2, 218, 2, 219, 2, 220, 2, 221, 2, 222, 2, 223, 2, 224,
  2, 225, 2, 226, 2, 227, 2, 228, 2, 229, 2, 230, 2, 231, 2, 232, 2, 233, 2,
  234, 2, 235, 2, 236, 2, 237, 2, 238, 2, 239, 2, 240, 2, 241, 2, 242, 2, 243,
  2, 244, 2, 245, 2, 246, 2, 247, 2, 248, 2, 249, 2, 250, 2, 251, 2, 252, 2,
  253, 2, 254, 2, 255, 3, 0, 3, 1, 3, 2, 3, 3, 3, 4, 3, 5, 3, 6, 3, 7, 3, 8, 3,
  9, 3, 10, 3, 11, 3, 12, 3, 13, 3, 14, 3, 15, 3, 16, 3, 17, 3, 18, 3, 19, 3,
  20, 3, 21, 3, 22, 3, 23, 3, 24, 3, 25, 3, 26, 3, 27, 3, 28, 3, 29, 3, 30, 3,
  31, 3, 32, 3, 33, 3, 34, 3, 35, 3, 36, 3, 37, 3, 38, 3, 39, 3, 40, 3, 41, 3,
  42, 3, 43, 3, 44, 3, 45, 3, 46, 3, 47, 3, 48, 3, 49, 3, 50, 3, 51, 3, 52, 3,
  53, 3, 54, 3, 55, 3, 56, 3, 57, 3, 58, 3, 59, 3, 60, 3, 61, 3, 62, 3, 63, 3,
  64, 3, 65, 3, 66, 3, 67, 3, 68, 3, 69, 3, 70, 3, 71, 3, 72, 3, 73, 3, 74, 3,
  75, 3, 76, 3, 77, 3, 78, 3, 79, 3, 80, 3, 81, 3, 82, 3, 83, 3, 84, 3, 85, 3,
  86, 3, 87, 3, 88, 3, 89, 3, 90, 3, 91, 3, 92, 3, 93, 3, 94, 3, 95, 3, 96, 3,
  97, 3, 98, 3, 99, 3, 100, 3, 101, 3, 102, 3, 103, 3, 104, 3, 105, 3, 106, 3,
  107, 3, 108, 3, 109, 3, 110, 2, 0, 2, 1, 3, 111, 3, 112, 3, 113, 3, 114, 3,
  115, 3, 116, 3, 117, 2, 28, 2, 52, 2, 53, 2, 93, 2, 94, 0, 6, 2, 12, 0, 0, 0,
  0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0,
  0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0,
  8, 0, 9, 0, 10, 0, 11, 0, 12, 0, 13, 0, 14, 0, 15, 0, 16, 0, 17, 0, 18, 0, 19,
  0, 20, 0, 21, 0, 22, 0, 23, 0, 24, 0, 25, 0, 26, 0, 27, 0, 28, 0, 29, 0, 30,
  0, 31, 0, 32, 0, 33, 0, 34, 0, 35, 0, 36, 0, 37, 0, 38, 0, 39, 0, 40, 0, 41,
  0, 42, 0, 43, 0, 44, 0, 45, 0, 46, 0, 47, 0, 48, 0, 49, 0, 50, 0, 51, 0, 52,
  0, 53, 0, 54, 0, 55, 0, 56, 0, 57, 0, 58, 0, 59, 0, 60, 0, 61, 0, 62, 0, 63,
  0, 64, 0, 65, 0, 66, 0, 67, 0, 68, 0, 69, 0, 70, 0, 71, 0, 72, 0, 73, 0, 74,
  0, 75, 0, 76, 0, 77, 0, 78, 0, 79, 0, 80, 0, 81, 0, 82, 0, 83, 0, 84, 0, 85,
  0, 86, 0, 87, 0, 88, 0, 89, 0, 90, 0, 91, 0, 92, 0, 93, 0, 94, 0, 95, 0, 96,
  0, 97, 0, 0, 0, 134, 0, 135, 0, 137, 0, 139, 0, 147, 0, 152, 0, 158, 0, 163,
  0, 162, 0, 164, 0, 166, 0, 165, 0, 167, 0, 169, 0, 171, 0, 170, 0, 172, 0,
  173, 0, 175, 0, 174, 0, 176, 0, 177, 0, 179, 0, 181, 0, 180, 0, 182, 0, 184,
  0, 183, 0, 188, 0, 187, 0, 189, 0, 190, 2, 13, 0, 114, 0, 100, 0, 101, 0, 105,
  2, 15, 0, 120, 0, 161, 0, 112, 0, 107, 2, 32, 0, 118, 0, 106, 2, 48, 0, 136,
  0, 154, 2, 45, 0, 115, 2, 49, 2, 50, 0, 103, 0, 119, 2, 39, 2, 42, 2, 41, 1,
  141, 2, 46, 0, 108, 0, 124, 2, 33, 0, 168, 0, 186, 0, 129, 0, 99, 0, 110, 2,
  44, 1, 66, 2, 47, 2, 40, 0, 109, 0, 125, 2, 16, 0, 3, 0, 130, 0, 133, 0, 151,
  1, 20, 1, 21, 2, 2, 2, 3, 2, 10, 2, 11, 2, 6, 2, 7, 0, 185, 2, 51, 0, 193, 1,
  58, 2, 23, 0, 102, 2, 20, 2, 21, 2, 52, 2, 53, 2, 14, 0, 121, 2, 8, 2, 12, 2,
  17, 0, 132, 0, 140, 0, 131, 0, 141, 0, 138, 0, 143, 0, 144, 0, 145, 0, 142, 0,
  149, 0, 150, 0, 0, 0, 148, 0, 156, 0, 157, 0, 155, 0, 243, 1, 75, 1, 82, 0,
  113, 1, 78, 1, 79, 1, 80, 0, 122, 1, 83, 1, 81, 1, 76, 0, 0, 0, 0, 64, 69, 89,
  88, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68,
  67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 49, 48, 47, 46,
  45, 44, 40, 39, 38, 37, 36, 35, 34, 33, 31, 24, 20, 17, 16, 15, 14, 13, 11,
  10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 44, 69, 35, 70, 96, 32, 176, 38, 96, 176, 4,
  38, 35, 72, 72, 45, 44, 69, 35, 70, 35, 97, 32, 176, 38, 97, 176, 4, 38, 35,
  72, 72, 45, 44, 69, 35, 70, 96, 176, 32, 97, 32, 176, 70, 96, 176, 4, 38, 35,
  72, 72, 45, 44, 69, 35, 70, 35, 97, 176, 32, 96, 32, 176, 38, 97, 176, 32, 97,
  176, 4, 38, 35, 72, 72, 45, 44, 69, 35, 70, 96, 176, 64, 97, 32, 176, 102, 96,
  176, 4, 38, 35, 72, 72, 45, 44, 69, 35, 70, 35, 97, 176, 64, 96, 32, 176, 38,
  97, 176, 64, 97, 176, 4, 38, 35, 72, 72, 45, 44, 1, 16, 32, 60, 0, 60, 45, 44,
  32, 69, 35, 32, 176, 205, 68, 35, 32, 184, 1, 90, 81, 88, 35, 32, 176, 141,
  68, 35, 89, 32, 176, 237, 81, 88, 35, 32, 176, 77, 68, 35, 89, 32, 176, 4, 38,
  81, 88, 35, 32, 176, 13, 68, 35, 89, 33, 33, 45, 44, 32, 32, 69, 24, 104, 68,
  32, 176, 1, 96, 32, 69, 176, 70, 118, 104, 138, 69, 96, 68, 45, 44, 1, 177,
  11, 10, 67, 35, 67, 101, 10, 45, 44, 0, 177, 10, 11, 67, 35, 67, 11, 45, 44,
  0, 176, 40, 35, 112, 177, 1, 40, 62, 1, 176, 40, 35, 112, 177, 2, 40, 69, 58,
  177, 2, 0, 8, 13, 45, 44, 32, 69, 176, 3, 37, 69, 97, 100, 176, 80, 81, 88,
  69, 68, 27, 33, 33, 89, 45, 44, 73, 176, 14, 35, 68, 45, 44, 32, 69, 176, 0,
  67, 96, 68, 45, 44, 1, 176, 6, 67, 176, 7, 67, 101, 10, 45, 44, 32, 105, 176,
  64, 97, 176, 0, 139, 32, 177, 44, 192, 138, 140, 184, 16, 0, 98, 96, 43, 12,
  100, 35, 100, 97, 92, 88, 176, 3, 97, 89, 45, 44, 138, 3, 69, 138, 138, 135,
  176, 17, 43, 176, 41, 35, 68, 176, 41, 122, 228, 24, 45, 44, 69, 101, 176, 44,
  35, 68, 69, 176, 43, 35, 68, 45, 44, 75, 82, 88, 69, 68, 27, 33, 33, 89, 45,
  44, 75, 81, 88, 69, 68, 27, 33, 33, 89, 45, 44, 1, 176, 5, 37, 16, 35, 32,
  138, 245, 0, 176, 1, 96, 35, 237, 236, 45, 44, 1, 176, 5, 37, 16, 35, 32, 138,
  245, 0, 176, 1, 97, 35, 237, 236, 45, 44, 1, 176, 6, 37, 16, 245, 0, 237, 236,
  45, 44, 70, 35, 70, 96, 138, 138, 70, 35, 32, 70, 138, 96, 138, 97, 184, 255,
  128, 98, 35, 32, 16, 35, 138, 177, 12, 12, 138, 112, 69, 96, 32, 176, 0, 80,
  88, 176, 1, 97, 184, 255, 186, 139, 27, 176, 70, 140, 89, 176, 16, 96, 104, 1,
  58, 45, 44, 32, 69, 176, 3, 37, 70, 82, 75, 176, 19, 81, 91, 88, 176, 2, 37,
  70, 32, 104, 97, 176, 3, 37, 176, 3, 37, 63, 35, 33, 56, 27, 33, 17, 89, 45,
  44, 32, 69, 176, 3, 37, 70, 80, 88, 176, 2, 37, 70, 32, 104, 97, 176, 3, 37,
  176, 3, 37, 63, 35, 33, 56, 27, 33, 17, 89, 45, 44, 0, 176, 7, 67, 176, 6, 67,
  11, 45, 44, 33, 33, 12, 100, 35, 100, 139, 184, 64, 0, 98, 45, 44, 33, 176,
  128, 81, 88, 12, 100, 35, 100, 139, 184, 32, 0, 98, 27, 178, 0, 64, 47, 43,
  89, 176, 2, 96, 45, 44, 33, 176, 192, 81, 88, 12, 100, 35, 100, 139, 184, 21,
  85, 98, 27, 178, 0, 128, 47, 43, 89, 176, 2, 96, 45, 44, 12, 100, 35, 100,
  139, 184, 64, 0, 98, 96, 35, 33, 45, 44, 75, 83, 88, 138, 176, 4, 37, 73, 100,
  35, 69, 105, 176, 64, 139, 97, 176, 128, 98, 176, 32, 97, 106, 176, 14, 35,
  68, 35, 16, 176, 14, 246, 27, 33, 35, 138, 18, 17, 32, 57, 47, 89, 45, 44, 75,
  83, 88, 32, 176, 3, 37, 73, 100, 105, 32, 176, 5, 38, 176, 6, 37, 73, 100, 35,
  97, 176, 128, 98, 176, 32, 97, 106, 176, 14, 35, 68, 176, 4, 38, 16, 176, 14,
  246, 138, 16, 176, 14, 35, 68, 176, 14, 246, 176, 14, 35, 68, 176, 14, 237,
  27, 138, 176, 4, 38, 17, 18, 32, 57, 35, 32, 57, 47, 47, 89, 45, 44, 69, 35,
  69, 96, 35, 69, 96, 35, 69, 96, 35, 118, 104, 24, 176, 128, 98, 32, 45, 44,
  176, 72, 43, 45, 44, 32, 69, 176, 0, 84, 88, 176, 64, 68, 32, 69, 176, 64, 97,
  68, 27, 33, 33, 89, 45, 44, 69, 177, 48, 47, 69, 35, 69, 97, 96, 176, 1, 96,
  105, 68, 45, 44, 75, 81, 88, 176, 47, 35, 112, 176, 20, 35, 66, 27, 33, 33,
  89, 45, 44, 75, 81, 88, 32, 176, 3, 37, 69, 105, 83, 88, 68, 27, 33, 33, 89,
  27, 33, 33, 89, 45, 44, 69, 176, 20, 67, 176, 0, 96, 99, 176, 1, 96, 105, 68,
  45, 44, 176, 47, 69, 68, 45, 44, 69, 35, 32, 69, 138, 96, 68, 45, 44, 69, 35,
  69, 96, 68, 45, 44, 75, 35, 81, 88, 185, 0, 51, 255, 224, 177, 52, 32, 27,
  179, 51, 0, 52, 0, 89, 68, 68, 45, 44, 176, 22, 67, 88, 176, 3, 38, 69, 138,
  88, 100, 102, 176, 31, 96, 27, 100, 176, 32, 96, 102, 32, 88, 27, 33, 176, 64,
  89, 176, 1, 97, 89, 35, 88, 101, 89, 176, 41, 35, 68, 35, 16, 176, 41, 224,
  27, 33, 33, 33, 33, 33, 89, 45, 44, 176, 2, 67, 84, 88, 75, 83, 35, 75, 81,
  90, 88, 56, 27, 33, 33, 89, 27, 33, 33, 33, 33, 89, 45, 44, 176, 22, 67, 88,
  176, 4, 37, 69, 100, 176, 32, 96, 102, 32, 88, 27, 33, 176, 64, 89, 176, 1,
  97, 35, 88, 27, 101, 89, 176, 41, 35, 68, 176, 5, 37, 176, 8, 37, 8, 32, 88,
  2, 27, 3, 89, 176, 4, 37, 16, 176, 5, 37, 32, 70, 176, 4, 37, 35, 66, 60, 176,
  4, 37, 176, 7, 37, 8, 176, 7, 37, 16, 176, 6, 37, 32, 70, 176, 4, 37, 176, 1,
  96, 35, 66, 60, 32, 88, 1, 27, 0, 89, 176, 4, 37, 16, 176, 5, 37, 176, 41,
  224, 176, 41, 32, 69, 101, 68, 176, 7, 37, 16, 176, 6, 37, 176, 41, 224, 176,
  5, 37, 176, 8, 37, 8, 32, 88, 2, 27, 3, 89, 176, 5, 37, 176, 3, 37, 67, 72,
  176, 4, 37, 176, 7, 37, 8, 176, 6, 37, 176, 3, 37, 176, 1, 96, 67, 72, 27, 33,
  89, 33, 33, 33, 33, 33, 33, 33, 45, 44, 2, 176, 4, 37, 32, 32, 70, 176, 4, 37,
  35, 66, 176, 5, 37, 8, 176, 3, 37, 69, 72, 33, 33, 33, 33, 45, 44, 2, 176, 3,
  37, 32, 176, 4, 37, 8, 176, 2, 37, 67, 72, 33, 33, 33, 45, 44, 69, 35, 32, 69,
  24, 32, 176, 0, 80, 32, 88, 35, 101, 35, 89, 35, 104, 32, 176, 64, 80, 88, 33,
  176, 64, 89, 35, 88, 101, 89, 138, 96, 68, 45, 44, 75, 83, 35, 75, 81, 90, 88,
  32, 69, 138, 96, 68, 27, 33, 33, 89, 45, 44, 75, 84, 88, 32, 69, 138, 96, 68,
  27, 33, 33, 89, 45, 44, 75, 83, 35, 75, 81, 90, 88, 56, 27, 33, 33, 89, 45,
  44, 176, 0, 33, 75, 84, 88, 56, 27, 33, 33, 89, 45, 44, 176, 2, 67, 84, 88,
  176, 70, 43, 27, 33, 33, 33, 33, 89, 45, 44, 176, 2, 67, 84, 88, 176, 71, 43,
  27, 33, 33, 33, 89, 45, 44, 176, 2, 67, 84, 88, 176, 72, 43, 27, 33, 33, 33,
  33, 89, 45, 44, 176, 2, 67, 84, 88, 176, 73, 43, 27, 33, 33, 33, 89, 45, 44,
  32, 138, 8, 35, 75, 83, 138, 75, 81, 90, 88, 35, 56, 27, 33, 33, 89, 45, 44,
  0, 176, 2, 37, 73, 176, 0, 83, 88, 32, 176, 64, 56, 17, 27, 33, 89, 45, 44, 1,
  70, 35, 70, 96, 35, 70, 97, 35, 32, 16, 32, 70, 138, 97, 184, 255, 128, 98,
  138, 177, 64, 64, 138, 112, 69, 96, 104, 58, 45, 44, 32, 138, 35, 73, 100,
  138, 35, 83, 88, 60, 27, 33, 89, 45, 44, 75, 82, 88, 125, 27, 122, 89, 45, 44,
  176, 18, 0, 75, 1, 75, 84, 66, 45, 44, 177, 2, 0, 66, 177, 35, 1, 136, 81,
  177, 64, 1, 136, 83, 90, 88, 185, 16, 0, 0, 32, 136, 84, 88, 178, 2, 1, 2, 67,
  96, 66, 89, 177, 36, 1, 136, 81, 88, 185, 32, 0, 0, 64, 136, 84, 88, 178, 2,
  2, 2, 67, 96, 66, 177, 36, 1, 136, 84, 88, 178, 2, 32, 2, 67, 96, 66, 0, 75,
  1, 75, 82, 88, 178, 2, 8, 2, 67, 96, 66, 89, 27, 185, 64, 0, 0, 128, 136, 84,
  88, 178, 2, 4, 2, 67, 96, 66, 89, 185, 64, 0, 0, 128, 99, 184, 1, 0, 136, 84,
  88, 178, 2, 8, 2, 67, 96, 66, 89, 185, 64, 0, 1, 0, 99, 184, 2, 0, 136, 84,
  88, 178, 2, 16, 2, 67, 96, 66, 89, 185, 64, 0, 2, 0, 99, 184, 4, 0, 136, 84,
  88, 178, 2, 64, 2, 67, 96, 66, 89, 89, 89, 89, 89, 45, 44, 69, 24, 104, 35,
  75, 81, 88, 35, 32, 69, 32, 100, 176, 64, 80, 88, 124, 89, 104, 138, 96, 89,
  68, 45, 44, 176, 0, 22, 176, 2, 37, 176, 2, 37, 1, 176, 1, 35, 62, 0, 176, 2,
  35, 62, 177, 1, 2, 6, 12, 176, 10, 35, 101, 66, 176, 11, 35, 66, 1, 176, 1,
  35, 63, 0, 176, 2, 35, 63, 177, 1, 2, 6, 12, 176, 6, 35, 101, 66, 176, 7, 35,
  66, 176, 1, 22, 1, 45, 44, 122, 138, 16, 69, 35, 245, 24, 45, 0, 0, 0, 64, 21,
  248, 3, 255, 31, 241, 111, 26, 31, 47, 239, 111, 239, 2, 230, 228, 51, 31,
  229, 228, 25, 31, 184, 1, 0, 64, 16, 51, 255, 85, 223, 51, 221, 85, 222, 51,
  3, 85, 176, 255, 208, 255, 2, 184, 255, 192, 64, 104, 255, 9, 17, 70, 0, 221,
  32, 221, 112, 221, 3, 221, 1, 3, 85, 220, 3, 255, 31, 214, 213, 51, 31, 211,
  210, 25, 31, 135, 210, 1, 254, 194, 25, 31, 6, 186, 22, 186, 230, 186, 246,
  186, 4, 15, 178, 31, 178, 47, 178, 3, 64, 178, 15, 19, 70, 167, 177, 1, 175,
  83, 25, 31, 174, 173, 25, 31, 172, 74, 25, 31, 171, 170, 25, 31, 169, 3, 255,
  31, 158, 157, 25, 31, 31, 157, 1, 112, 156, 128, 156, 144, 156, 208, 156, 224,
  156, 240, 156, 6, 15, 153, 1, 151, 152, 1, 184, 255, 248, 64, 56, 152, 9, 15,
  70, 32, 151, 128, 151, 144, 151, 240, 151, 4, 169, 150, 185, 150, 2, 56, 150,
  1, 240, 149, 1, 191, 149, 1, 32, 149, 48, 149, 64, 149, 128, 149, 144, 149,
  160, 149, 6, 148, 146, 25, 31, 147, 83, 25, 31, 15, 146, 1, 133, 71, 25, 31,
  197, 189, 1, 7, 0, 1, 0, 166, 1, 7, 0, 182, 1, 7, 178, 2, 3, 128, 186, 1, 7,
  0, 144, 1, 7, 64, 168, 2, 118, 117, 25, 31, 116, 80, 25, 31, 115, 80, 25, 31,
  111, 72, 25, 31, 110, 71, 25, 31, 26, 1, 24, 85, 25, 19, 255, 31, 7, 4, 255,
  31, 6, 3, 255, 31, 97, 96, 25, 31, 101, 96, 1, 100, 95, 1, 255, 251, 1, 239,
  251, 1, 121, 251, 1, 63, 251, 79, 251, 2, 24, 250, 18, 24, 70, 79, 250, 95,
  250, 111, 250, 3, 212, 91, 228, 91, 2, 91, 90, 16, 31, 57, 90, 1, 6, 90, 1, 6,
  19, 51, 18, 85, 5, 1, 3, 85, 4, 51, 3, 85, 15, 3, 127, 3, 239, 3, 3, 224, 253,
  1, 223, 253, 1, 81, 80, 25, 31, 15, 252, 191, 252, 207, 252, 223, 252, 4, 3,
  64, 252, 12, 16, 70, 73, 70, 25, 31, 96, 72, 1, 59, 71, 1, 6, 28, 27, 255, 31,
  22, 51, 21, 85, 17, 1, 15, 85, 16, 51, 15, 85, 2, 1, 0, 85, 1, 71, 0, 85, 184,
  1, 6, 64, 30, 27, 18, 31, 159, 15, 223, 15, 2, 207, 15, 239, 15, 2, 111, 0,
  127, 0, 175, 0, 239, 0, 4, 16, 0, 1, 128, 22, 1, 5, 1, 184, 1, 144, 177, 84,
  83, 43, 43, 75, 184, 7, 255, 82, 75, 176, 9, 80, 91, 176, 1, 136, 176, 37, 83,
  176, 1, 136, 176, 64, 81, 90, 176, 6, 136, 176, 0, 85, 90, 91, 88, 177, 1, 1,
  142, 89, 133, 141, 141, 0, 66, 29, 75, 176, 50, 83, 88, 176, 96, 29, 89, 75,
  176, 100, 83, 88, 176, 64, 29, 89, 75, 176, 128, 83, 88, 176, 16, 29, 177, 22,
  0, 66, 89, 115, 115, 115, 116, 43, 43, 43, 43, 43, 43, 43, 1, 95, 115, 115,
  43, 43, 95, 115, 0, 43, 115, 115, 115, 43, 43, 43, 1, 95, 115, 115, 43, 115,
  115, 43, 115, 115, 115, 115, 0, 115, 115, 43, 43, 43, 43, 43, 1, 43, 43, 0,
  43, 43, 43, 115, 95, 115, 115, 1, 43, 0, 115, 43, 43, 1, 115, 115, 115, 115,
  115, 115, 43, 115, 115, 0, 115, 115, 43, 43, 1, 43, 43, 0, 43, 43, 1, 115, 0,
  43, 115, 115, 43, 1, 115, 43, 0, 43, 43, 43, 115, 43, 115, 43, 43, 43, 43, 43,
  115, 1, 43, 0, 43, 24, 0, 0, 6, 20, 0, 11, 0, 81, 5, 182, 0, 23, 0, 117, 5,
  182, 5, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 74, 0, 20, 0, 143,
  0, 0, 255, 236, 0, 0, 0, 0, 255, 236, 0, 0, 0, 0, 255, 236, 0, 0, 254, 20,
  254, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 8, 0, 8, 115, 0, 0, 0, 178, 0, 182, 0, 188, 0, 156, 0, 213, 0, 0, 0, 0, 0,
  0, 0, 143, 0, 131, 0, 151, 0, 159, 0, 125, 0, 229, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 186, 0, 197, 0, 186, 0, 0, 0, 0, 0, 164, 0, 159, 0, 143, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 176, 0, 185,
  0, 138, 0, 0, 0, 0, 0, 155, 0, 166, 0, 143, 0, 119, 0, 85, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 105, 0, 110, 0, 144, 0, 192, 1,
  137, 0, 219, 0, 172, 0, 0, 0, 0, 0, 0, 0, 102, 0, 111, 0, 120, 0, 150, 0, 192,
  0, 213, 1, 72, 0, 205, 1, 21, 2, 151, 0, 254, 1, 47, 0, 237, 1, 78, 0, 121, 1,
  22, 1, 76, 1, 245, 2, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 255, 226, 5, 182, 0, 150, 0, 140, 0, 229, 0, 150, 0, 137, 0, 250, 0, 0, 1,
  24, 1, 12, 3, 29, 0, 153, 2, 74, 0, 120, 2, 182, 0, 141, 0, 168, 0, 140, 0, 0,
  0, 0, 2, 121, 0, 217, 0, 180, 0, 0, 0, 0, 1, 90, 0, 109, 0, 127, 0, 160, 0, 0,
  0, 0, 0, 109, 0, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 140,
  0, 160, 0, 0, 0, 130, 0, 137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 182, 252, 234,
  0, 17, 255, 235, 0, 150, 0, 0, 0, 0, 0, 0, 0, 115, 0, 101, 0, 120, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 188, 1, 170, 3, 84, 1, 170, 2, 29, 0, 188, 0, 182, 0, 0, 0, 0,
  0, 0, 0, 150, 0, 0, 0, 0, 5, 182, 254, 188, 0, 152, 0, 172, 1, 57, 1, 245, 1,
  131, 3, 29, 255, 243, 0, 131, 0, 122, 0, 134, 0, 0, 0, 0, 254, 111, 0, 137, 0,
  0, 0, 40, 0, 40, 0, 40, 0, 40, 0, 90, 0, 135, 1, 28, 1, 193, 2, 108, 3, 39, 3,
  66, 3, 111, 3, 156, 3, 210, 3, 250, 4, 45, 4, 74, 4, 105, 4, 135, 4, 205, 4,
  250, 5, 77, 5, 178, 6, 2, 6, 85, 6, 179, 6, 233, 7, 103, 7, 196, 7, 245, 8,
  52, 8, 122, 8, 174, 8, 243, 9, 75, 9, 234, 10, 97, 10, 190, 10, 255, 11, 55,
  11, 111, 11, 175, 11, 252, 12, 51, 12, 110, 12, 156, 13, 28, 13, 66, 13, 194,
  14, 26, 14, 85, 14, 147, 14, 238, 15, 79, 15, 156, 15, 204, 15, 254, 16, 101,
  17, 71, 17, 196, 18, 54, 18, 111, 18, 156, 18, 186, 18, 231, 19, 22, 19, 45,
  19, 79, 19, 164, 19, 241, 20, 44, 20, 122, 20, 201, 21, 17, 21, 159, 21, 221,
  22, 25, 22, 93, 22, 185, 22, 231, 23, 77, 23, 134, 23, 192, 24, 16, 24, 95,
  24, 149, 24, 226, 25, 49, 25, 104, 25, 189, 26, 130, 26, 246, 27, 87, 27, 145,
  27, 237, 28, 5, 28, 96, 28, 149, 28, 149, 28, 191, 29, 15, 29, 98, 29, 208,
  30, 87, 30, 123, 31, 4, 31, 58, 31, 194, 32, 22, 32, 94, 32, 132, 32, 140, 33,
  41, 33, 62, 33, 169, 33, 221, 34, 40, 34, 150, 34, 184, 34, 250, 35, 61, 35,
  95, 35, 156, 35, 196, 35, 252, 36, 68, 36, 115, 36, 166, 36, 211, 37, 51, 37,
  75, 37, 98, 37, 121, 37, 145, 37, 171, 37, 209, 38, 58, 38, 76, 38, 100, 38,
  123, 38, 146, 38, 171, 38, 195, 38, 218, 38, 241, 39, 10, 39, 90, 39, 113, 39,
  137, 39, 160, 39, 184, 39, 207, 39, 232, 40, 55, 40, 165, 40, 189, 40, 212,
  40, 235, 41, 4, 41, 27, 41, 93, 41, 211, 41, 234, 42, 2, 42, 26, 42, 54, 42,
  84, 42, 108, 42, 237, 42, 255, 43, 22, 43, 50, 43, 72, 43, 96, 43, 119, 43,
  141, 43, 164, 43, 189, 44, 53, 44, 75, 44, 98, 44, 120, 44, 143, 44, 165, 44,
  190, 45, 9, 45, 127, 45, 150, 45, 172, 45, 194, 45, 218, 45, 240, 46, 65, 46,
  89, 46, 113, 46, 135, 46, 159, 46, 181, 46, 206, 46, 237, 47, 4, 47, 27, 47,
  60, 47, 82, 47, 105, 47, 127, 47, 150, 47, 172, 47, 196, 47, 224, 47, 232, 48,
  78, 48, 102, 48, 124, 48, 147, 48, 169, 48, 192, 48, 214, 48, 234, 48, 254,
  49, 21, 49, 43, 49, 66, 49, 89, 49, 116, 49, 139, 49, 162, 49, 184, 49, 206,
  49, 228, 49, 251, 50, 18, 50, 100, 50, 182, 50, 205, 50, 228, 50, 251, 51, 18,
  51, 41, 51, 63, 51, 82, 51, 101, 51, 124, 51, 168, 51, 230, 52, 75, 52, 98,
  52, 121, 52, 144, 52, 167, 53, 4, 53, 28, 53, 51, 53, 74, 53, 97, 53, 117, 53,
  139, 53, 159, 53, 183, 54, 18, 54, 124, 54, 147, 54, 169, 54, 192, 54, 215,
  54, 239, 55, 5, 55, 78, 55, 168, 55, 238, 56, 5, 56, 27, 56, 51, 56, 73, 56,
  98, 56, 122, 56, 208, 57, 73, 57, 97, 57, 119, 57, 142, 57, 174, 57, 198, 57,
  221, 57, 244, 58, 10, 58, 33, 58, 55, 58, 74, 58, 95, 58, 118, 58, 140, 58,
  163, 58, 185, 58, 208, 58, 230, 59, 48, 59, 147, 59, 170, 59, 192, 59, 216,
  59, 238, 60, 6, 60, 28, 60, 53, 60, 78, 60, 103, 60, 127, 60, 146, 60, 171,
  60, 194, 60, 217, 60, 240, 61, 6, 61, 31, 61, 54, 61, 76, 61, 99, 61, 121, 61,
  144, 61, 166, 61, 215, 62, 47, 62, 104, 62, 156, 62, 179, 62, 201, 62, 224,
  62, 246, 63, 12, 63, 35, 63, 87, 63, 139, 63, 185, 63, 248, 64, 46, 64, 154,
  64, 208, 65, 9, 65, 73, 65, 110, 65, 193, 65, 218, 65, 252, 66, 26, 66, 56,
  66, 81, 66, 104, 66, 127, 66, 150, 66, 171, 66, 179, 66, 187, 66, 232, 67,
  111, 67, 119, 67, 127, 67, 135, 67, 231, 67, 239, 67, 247, 68, 111, 68, 119,
  68, 127, 68, 190, 68, 198, 68, 235, 68, 243, 69, 78, 69, 86, 69, 94, 69, 241,
  69, 249, 70, 95, 70, 201, 70, 226, 70, 251, 71, 18, 71, 40, 71, 62, 71, 84,
  71, 109, 71, 199, 72, 43, 72, 129, 72, 226, 73, 57, 73, 176, 73, 232, 74, 65,
  74, 108, 74, 116, 74, 211, 75, 20, 75, 107, 75, 248, 76, 0, 76, 94, 76, 167,
  77, 4, 77, 71, 77, 143, 77, 200, 78, 42, 78, 211, 79, 51, 79, 187, 79, 211,
  79, 236, 80, 2, 80, 24, 80, 46, 80, 71, 80, 175, 80, 198, 81, 19, 81, 27, 81,
  35, 81, 60, 81, 68, 81, 188, 82, 8, 82, 93, 82, 116, 82, 139, 82, 196, 82,
  204, 83, 9, 83, 17, 83, 25, 83, 128, 83, 136, 84, 21, 84, 116, 84, 197, 84,
  221, 85, 55, 85, 141, 85, 149, 85, 157, 85, 165, 85, 173, 85, 181, 85, 189,
  85, 197, 86, 66, 86, 74, 86, 82, 86, 135, 86, 188, 87, 1, 87, 93, 87, 159, 87,
  239, 88, 44, 88, 124, 88, 232, 89, 71, 89, 79, 89, 166, 90, 5, 90, 45, 90,
  139, 90, 147, 91, 62, 91, 153, 91, 246, 92, 18, 92, 113, 92, 246, 93, 128, 93,
  184, 93, 192, 93, 231, 93, 239, 93, 247, 94, 40, 94, 48, 94, 144, 94, 152, 94,
  204, 95, 1, 95, 69, 95, 152, 95, 220, 96, 52, 96, 115, 96, 209, 97, 51, 97,
  142, 97, 166, 98, 10, 98, 32, 98, 121, 98, 129, 98, 137, 98, 162, 98, 170, 99,
  26, 99, 112, 99, 120, 99, 142, 99, 164, 99, 222, 100, 16, 100, 58, 100, 82,
  100, 105, 100, 128, 100, 150, 100, 175, 100, 200, 100, 224, 100, 247, 101, 16,
  101, 38, 101, 60, 101, 110, 101, 150, 101, 197, 101, 249, 102, 32, 102, 99,
  102, 176, 102, 253, 103, 49, 103, 122, 103, 164, 103, 246, 104, 185, 104, 193,
  104, 201, 104, 254, 105, 38, 105, 68, 105, 100, 105, 162, 105, 242, 106, 103,
  106, 221, 107, 80, 107, 228, 108, 79, 109, 10, 109, 109, 109, 117, 109, 195,
  109, 254, 110, 53, 110, 110, 110, 167, 110, 250, 111, 124, 111, 168, 112, 1,
  112, 27, 112, 72, 112, 178, 112, 232, 113, 65, 113, 157, 113, 235, 114, 55,
  114, 118, 114, 212, 115, 31, 115, 78, 115, 130, 115, 162, 115, 195, 115, 228,
  116, 22, 116, 97, 116, 182, 116, 255, 117, 45, 117, 161, 117, 239, 117, 239,
  117, 239, 117, 239, 117, 239, 117, 239, 117, 239, 117, 239, 117, 239, 117,
  239, 117, 239, 117, 239, 117, 239, 117, 239, 119, 67, 119, 192, 119, 210, 119,
  218, 120, 119, 120, 241, 121, 122, 121, 145, 121, 167, 121, 191, 121, 215,
  121, 252, 122, 83, 122, 157, 123, 25, 123, 148, 123, 253, 124, 89, 124, 173,
  125, 17, 125, 25, 125, 33, 125, 41, 125, 108, 125, 140, 125, 164, 125, 188,
  125, 211, 125, 234, 126, 126, 127, 2, 127, 86, 127, 172, 128, 27, 128, 136,
  129, 6, 129, 155, 130, 81, 130, 235, 131, 85, 131, 208, 132, 81, 132, 226,
  133, 190, 134, 162, 134, 170, 134, 178, 135, 13, 135, 89, 135, 179, 136, 18,
  136, 44, 136, 69, 136, 233, 137, 144, 138, 28, 138, 155, 139, 132, 140, 86,
  141, 26, 141, 219, 142, 45, 142, 120, 142, 249, 143, 41, 143, 90, 143, 138,
  143, 188, 144, 100, 145, 13, 145, 135, 146, 22, 146, 104, 146, 192, 147, 48,
  147, 193, 147, 244, 148, 38, 148, 125, 148, 213, 149, 58, 149, 151, 149, 170,
  149, 191, 150, 25, 150, 95, 150, 199, 151, 43, 151, 138, 151, 241, 152, 63,
  152, 138, 152, 206, 153, 21, 153, 85, 153, 140, 153, 229, 154, 74, 154, 245,
  155, 170, 155, 190, 155, 209, 156, 13, 156, 63, 156, 71, 156, 158, 157, 36,
  157, 148, 158, 8, 158, 139, 158, 196, 159, 0, 159, 71, 159, 146, 159, 233,
  160, 70, 160, 125, 160, 192, 161, 60, 161, 185, 162, 67, 162, 204, 162, 212,
  162, 235, 163, 1, 163, 104, 163, 199, 164, 37, 164, 112, 164, 196, 165, 21,
  165, 93, 165, 159, 165, 235, 166, 60, 166, 220, 167, 126, 167, 134, 167, 158,
  167, 180, 167, 206, 167, 230, 167, 238, 167, 246, 168, 14, 168, 36, 168, 133,
  168, 230, 168, 255, 169, 23, 169, 49, 169, 74, 169, 100, 169, 125, 169, 212,
  170, 46, 170, 69, 170, 91, 170, 116, 170, 140, 170, 165, 170, 190, 170, 198,
  170, 206, 170, 231, 171, 0, 171, 26, 171, 51, 171, 74, 171, 96, 171, 122, 171,
  146, 171, 171, 171, 195, 171, 220, 171, 244, 172, 37, 172, 81, 172, 106, 172,
  130, 172, 212, 173, 37, 173, 62, 173, 90, 173, 212, 174, 93, 174, 156, 174,
  164, 175, 9, 175, 127, 175, 246, 176, 105, 176, 213, 177, 62, 177, 175, 178,
  18, 178, 100, 178, 186, 179, 28, 179, 120, 179, 193, 180, 10, 180, 127, 180,
  135, 180, 143, 180, 151, 180, 173, 180, 195, 180, 218, 180, 240, 181, 9, 181,
  33, 181, 59, 181, 84, 181, 109, 181, 133, 181, 158, 181, 182, 181, 215, 181,
  247, 182, 16, 182, 40, 182, 65, 182, 89, 182, 114, 182, 138, 182, 164, 182,
  188, 182, 223, 182, 255, 183, 21, 183, 43, 183, 66, 183, 88, 183, 111, 183,
  133, 183, 158, 183, 182, 183, 208, 183, 233, 184, 2, 184, 26, 184, 52, 184,
  76, 184, 109, 184, 141, 184, 164, 184, 186, 184, 208, 184, 231, 184, 254, 185,
  20, 185, 43, 185, 65, 185, 90, 185, 114, 185, 140, 185, 165, 185, 190, 185,
  214, 185, 239, 186, 7, 186, 43, 186, 75, 186, 98, 186, 117, 186, 141, 186,
  162, 186, 186, 186, 209, 186, 233, 186, 254, 187, 21, 187, 44, 187, 66, 187,
  88, 187, 111, 187, 133, 187, 157, 187, 178, 187, 202, 187, 224, 187, 248, 188,
  15, 188, 38, 188, 57, 188, 80, 188, 103, 188, 125, 188, 147, 188, 170, 188,
  192, 188, 215, 188, 237, 189, 126, 189, 195, 190, 21, 190, 103, 190, 216, 191,
  79, 191, 152, 191, 225, 192, 77, 192, 190, 192, 241, 193, 28, 193, 71, 0, 0,
  0, 2, 0, 193, 0, 0, 4, 10, 5, 182, 0, 3, 0, 7, 0, 39, 64, 21, 5, 96, 2, 1, 2,
  2, 9, 4, 0, 3, 112, 3, 128, 3, 3, 3, 4, 3, 7, 0, 3, 0, 63, 50, 47, 51, 1, 47,
  93, 51, 17, 51, 47, 93, 51, 49, 48, 19, 33, 17, 33, 55, 33, 17, 33, 193, 3,
  73, 252, 183, 104, 2, 121, 253, 135, 5, 182, 250, 74, 104, 4, 230, 0, 2, 1,
  231, 255, 227, 2, 229, 5, 182, 0, 3, 0, 11, 0, 52, 64, 28, 1, 0, 3, 6, 150, 2,
  10, 10, 12, 13, 47, 0, 1, 0, 0, 2, 21, 4, 1, 6, 4, 1, 4, 155, 8, 168, 2, 3, 0,
  63, 63, 225, 93, 93, 17, 57, 47, 93, 17, 18, 1, 57, 47, 51, 225, 50, 57, 57,
  49, 48, 1, 35, 3, 51, 3, 50, 21, 20, 35, 34, 53, 52, 2, 164, 121, 51, 223,
  113, 127, 127, 127, 1, 158, 4, 24, 251, 68, 139, 140, 140, 139, 0, 0, 2, 1,
  29, 3, 166, 3, 176, 5, 182, 0, 3, 0, 7, 0, 46, 64, 28, 4, 207, 7, 1, 160, 7,
  1, 79, 7, 1, 7, 0, 32, 3, 48, 3, 144, 3, 160, 3, 4, 3, 6, 1, 158, 7, 0, 3, 0,
  63, 50, 237, 50, 1, 47, 93, 193, 47, 93, 93, 93, 193, 49, 48, 1, 3, 35, 3, 33,
  3, 35, 3, 2, 10, 41, 155, 41, 2, 147, 41, 155, 41, 5, 182, 253, 240, 2, 16,
  253, 240, 2, 16, 0, 2, 0, 45, 0, 0, 4, 160, 5, 182, 0, 27, 0, 31, 0, 184, 64,
  115, 28, 8, 20, 9, 171, 10, 18, 15, 14, 11, 4, 10, 19, 170, 20, 4, 1, 0, 25,
  4, 24, 5, 170, 6, 22, 30, 29, 7, 4, 6, 23, 171, 24, 31, 21, 10, 20, 64, 2, 80,
  2, 2, 16, 10, 20, 6, 24, 2, 2, 24, 6, 20, 10, 16, 6, 208, 26, 240, 26, 2, 127,
  26, 159, 26, 2, 26, 224, 12, 240, 12, 2, 12, 8, 4, 12, 174, 13, 28, 1, 13, 31,
  0, 16, 174, 17, 25, 21, 17, 63, 17, 79, 17, 127, 17, 143, 17, 159, 17, 5, 63,
  13, 79, 13, 2, 13, 17, 13, 17, 5, 23, 19, 3, 10, 5, 18, 0, 63, 51, 63, 51, 18,
  57, 57, 47, 47, 93, 93, 17, 51, 51, 16, 225, 50, 50, 17, 51, 51, 16, 225, 50,
  50, 1, 47, 93, 47, 93, 93, 23, 57, 47, 47, 47, 47, 47, 47, 93, 17, 18, 57, 57,
  16, 225, 17, 23, 57, 16, 225, 17, 23, 57, 16, 225, 17, 23, 57, 16, 225, 17,
  57, 57, 49, 48, 1, 3, 51, 21, 33, 3, 35, 19, 33, 3, 35, 19, 35, 53, 51, 19,
  35, 53, 33, 19, 51, 3, 33, 19, 51, 3, 51, 21, 1, 33, 19, 33, 3, 168, 64, 240,
  254, 246, 82, 148, 84, 254, 222, 82, 144, 78, 217, 244, 65, 233, 1, 2, 82,
  147, 82, 1, 37, 84, 144, 84, 221, 253, 20, 1, 35, 64, 254, 221, 3, 125, 254,
  184, 137, 254, 84, 1, 172, 254, 84, 1, 172, 137, 1, 72, 137, 1, 176, 254, 80,
  1, 176, 254, 80, 137, 254, 184, 1, 72, 0, 3, 0, 182, 255, 137, 4, 20, 6, 18,
  0, 28, 0, 34, 0, 39, 0, 205, 64, 134, 19, 36, 1, 4, 36, 1, 19, 35, 1, 4, 35,
  1, 19, 9, 1, 6, 9, 1, 3, 8, 19, 8, 2, 2, 3, 18, 3, 2, 2, 2, 18, 2, 2, 4, 1,
  20, 1, 2, 4, 0, 20, 0, 2, 36, 24, 18, 1, 112, 29, 15, 8, 2, 2, 5, 72, 38, 88,
  38, 120, 38, 3, 38, 110, 20, 27, 64, 17, 20, 72, 64, 27, 80, 27, 2, 27, 41, 5,
  5, 32, 110, 0, 12, 144, 12, 160, 12, 208, 12, 4, 12, 23, 30, 115, 15, 38, 35,
  9, 24, 29, 32, 6, 3, 21, 18, 15, 95, 16, 111, 16, 127, 16, 3, 16, 16, 15, 15,
  47, 15, 63, 15, 95, 15, 4, 15, 36, 8, 115, 3, 6, 3, 2, 2, 0, 3, 184, 255, 192,
  179, 10, 14, 72, 3, 0, 47, 43, 51, 51, 47, 17, 51, 16, 225, 50, 47, 93, 51,
  47, 93, 17, 51, 51, 18, 23, 57, 16, 225, 50, 1, 47, 93, 225, 51, 47, 16, 222,
  93, 43, 50, 225, 93, 17, 57, 47, 51, 51, 51, 225, 50, 50, 50, 49, 48, 93, 93,
  93, 93, 93, 93, 93, 93, 93, 93, 93, 37, 21, 35, 53, 34, 39, 53, 22, 51, 17,
  38, 38, 53, 52, 54, 55, 53, 51, 21, 22, 23, 7, 38, 39, 17, 22, 22, 21, 16, 1,
  17, 6, 21, 20, 22, 23, 17, 54, 53, 52, 2, 172, 137, 228, 137, 196, 169, 193,
  155, 184, 164, 137, 187, 149, 66, 140, 130, 199, 161, 254, 15, 172, 81, 228,
  184, 111, 230, 221, 70, 172, 92, 1, 178, 64, 163, 138, 131, 172, 20, 180, 176,
  9, 69, 145, 62, 10, 254, 90, 68, 161, 130, 254, 232, 2, 176, 1, 113, 29, 145,
  78, 86, 250, 254, 139, 28, 156, 127, 0, 5, 0, 0, 255, 238, 4, 205, 5, 199, 0,
  11, 0, 19, 0, 23, 0, 35, 0, 43, 0, 207, 185, 0, 34, 255, 224, 179, 9, 13, 72,
  32, 184, 255, 224, 64, 14, 9, 13, 72, 28, 32, 9, 13, 72, 26, 32, 9, 13, 72,
  10, 184, 255, 224, 179, 9, 13, 72, 8, 184, 255, 224, 64, 33, 9, 13, 72, 4, 32,
  9, 13, 72, 2, 32, 9, 13, 72, 103, 42, 151, 42, 167, 42, 3, 42, 180, 27, 181,
  33, 21, 22, 23, 20, 0, 22, 1, 22, 184, 255, 192, 64, 26, 21, 24, 72, 15, 20,
  1, 20, 64, 21, 24, 72, 22, 20, 22, 20, 3, 104, 38, 152, 38, 168, 38, 3, 38,
  180, 33, 184, 255, 192, 64, 46, 21, 24, 72, 33, 45, 104, 14, 152, 14, 168, 14,
  3, 14, 180, 9, 181, 103, 18, 151, 18, 167, 18, 3, 18, 180, 3, 40, 182, 30,
  183, 36, 182, 24, 25, 23, 6, 21, 24, 12, 182, 0, 183, 16, 182, 6, 7, 0, 63,
  225, 244, 225, 63, 63, 63, 225, 244, 225, 1, 47, 225, 93, 244, 225, 93, 16,
  212, 43, 225, 93, 18, 57, 57, 47, 47, 43, 93, 43, 93, 17, 51, 17, 51, 16, 244,
  225, 93, 49, 48, 43, 43, 43, 43, 43, 43, 43, 43, 1, 34, 38, 53, 52, 54, 51,
  50, 22, 21, 20, 6, 39, 50, 53, 52, 35, 34, 21, 20, 1, 1, 35, 1, 19, 34, 38,
  53, 52, 54, 51, 50, 22, 21, 20, 6, 39, 50, 53, 52, 35, 34, 21, 20, 1, 35, 131,
  160, 158, 137, 129, 162, 157, 136, 139, 139, 141, 3, 137, 253, 39, 158, 2,
  217, 35, 130, 161, 158, 137, 129, 162, 157, 136, 139, 139, 141, 3, 16, 189,
  160, 164, 182, 186, 160, 162, 187, 119, 230, 225, 225, 230, 2, 47, 250, 74, 5,
  182, 250, 56, 189, 159, 164, 182, 186, 160, 161, 187, 118, 230, 225, 225, 230,
  0, 0, 3, 0, 61, 255, 236, 4, 203, 5, 205, 0, 26, 0, 37, 0, 45, 0, 229, 64, 15,
  17, 39, 38, 9, 4, 8, 19, 8, 27, 0, 1, 6, 4, 7, 36, 184, 255, 240, 64, 48, 14,
  17, 72, 64, 36, 1, 52, 36, 1, 36, 71, 19, 30, 16, 14, 17, 72, 79, 30, 1, 59,
  30, 1, 6, 30, 71, 25, 32, 19, 48, 19, 2, 192, 25, 208, 25, 2, 19, 25, 19, 25,
  14, 121, 3, 1, 3, 71, 4, 184, 255, 192, 64, 28, 9, 18, 72, 4, 4, 7, 7, 47, 41,
  72, 14, 64, 10, 16, 72, 14, 70, 6, 1, 70, 1, 86, 1, 2, 55, 1, 1, 27, 184, 255,
  248, 64, 55, 11, 14, 72, 27, 0, 1, 6, 4, 8, 33, 80, 22, 88, 9, 1, 88, 38, 1,
  56, 39, 88, 39, 2, 41, 39, 1, 40, 17, 1, 17, 39, 38, 9, 4, 8, 22, 15, 3, 31,
  3, 79, 3, 127, 3, 4, 3, 3, 22, 4, 44, 81, 11, 22, 8, 21, 0, 63, 63, 225, 63,
  57, 47, 93, 17, 18, 23, 57, 93, 93, 93, 93, 93, 16, 225, 17, 23, 57, 43, 93,
  93, 93, 1, 47, 43, 225, 17, 51, 47, 51, 47, 43, 225, 93, 18, 57, 57, 47, 47,
  93, 93, 16, 225, 95, 93, 93, 43, 16, 225, 93, 93, 43, 17, 23, 57, 51, 17, 18,
  23, 57, 49, 48, 1, 1, 54, 55, 51, 6, 7, 19, 35, 39, 6, 35, 34, 38, 53, 52, 54,
  55, 38, 53, 52, 54, 51, 50, 22, 21, 20, 5, 54, 54, 53, 52, 38, 35, 34, 6, 21,
  20, 1, 1, 6, 21, 20, 22, 51, 50, 2, 90, 1, 25, 71, 33, 184, 53, 125, 234, 217,
  131, 174, 238, 189, 217, 127, 172, 163, 191, 179, 168, 185, 254, 100, 134, 99,
  99, 81, 87, 99, 1, 147, 254, 189, 203, 134, 93, 160, 3, 8, 254, 164, 121, 145,
  234, 169, 254, 221, 166, 186, 214, 187, 131, 195, 102, 192, 164, 148, 172,
  171, 149, 203, 65, 79, 119, 74, 74, 92, 89, 81, 118, 253, 8, 1, 145, 123, 178,
  105, 141, 0, 0, 1, 1, 240, 3, 166, 2, 221, 5, 182, 0, 3, 0, 24, 64, 13, 0,
  160, 3, 224, 3, 240, 3, 3, 3, 1, 158, 0, 3, 0, 63, 237, 1, 47, 93, 193, 49,
  48, 1, 3, 35, 3, 2, 221, 41, 155, 41, 5, 182, 253, 240, 2, 16, 0, 0, 1, 1, 39,
  254, 188, 3, 164, 5, 182, 0, 9, 0, 39, 64, 21, 6, 5, 5, 0, 1, 1, 11, 3, 240,
  31, 8, 127, 8, 143, 8, 3, 8, 6, 249, 0, 248, 0, 63, 63, 1, 47, 93, 225, 17,
  51, 47, 51, 51, 17, 51, 49, 48, 1, 51, 0, 17, 16, 1, 35, 0, 17, 16, 2, 227,
  193, 254, 63, 1, 191, 191, 254, 68, 5, 182, 254, 136, 253, 251, 253, 247, 254,
  140, 1, 97, 2, 26, 2, 20, 0, 0, 1, 1, 41, 254, 188, 3, 166, 5, 182, 0, 9, 0,
  39, 64, 21, 3, 240, 16, 8, 112, 8, 128, 8, 3, 8, 8, 11, 0, 1, 1, 6, 5, 6, 248,
  0, 249, 0, 63, 63, 1, 47, 51, 51, 17, 51, 17, 51, 47, 93, 225, 49, 48, 1, 35,
  0, 17, 16, 1, 51, 0, 17, 16, 1, 233, 190, 1, 190, 254, 64, 192, 1, 189, 254,
  188, 1, 115, 2, 10, 2, 6, 1, 119, 254, 151, 253, 234, 253, 228, 0, 0, 1, 0,
  133, 2, 119, 4, 72, 6, 20, 0, 14, 0, 36, 64, 21, 244, 7, 1, 7, 5, 9, 7, 4, 10,
  3, 11, 1, 13, 2, 12, 11, 8, 6, 6, 0, 0, 0, 63, 50, 47, 51, 23, 57, 1, 25, 47,
  93, 49, 48, 1, 3, 37, 23, 5, 19, 7, 3, 3, 39, 19, 37, 55, 5, 3, 2, 203, 43, 1,
  141, 27, 254, 133, 246, 179, 176, 157, 185, 242, 254, 137, 29, 1, 135, 43, 6,
  20, 254, 119, 111, 193, 28, 254, 186, 96, 1, 102, 254, 154, 96, 1, 70, 28,
  193, 111, 1, 137, 0, 0, 1, 0, 152, 1, 6, 4, 51, 4, 162, 0, 11, 0, 31, 64, 16,
  9, 6, 170, 0, 192, 3, 208, 3, 2, 3, 9, 0, 173, 6, 3, 179, 0, 63, 51, 225, 50,
  1, 47, 93, 51, 225, 50, 49, 48, 1, 33, 53, 33, 17, 51, 17, 33, 21, 33, 17, 35,
  2, 27, 254, 125, 1, 131, 149, 1, 131, 254, 125, 149, 2, 135, 150, 1, 133, 254,
  123, 150, 254, 127, 0, 0, 1, 1, 184, 254, 223, 3, 18, 1, 6, 0, 6, 0, 63, 64,
  25, 25, 6, 41, 6, 233, 6, 249, 6, 4, 6, 152, 1, 153, 112, 4, 128, 4, 208, 4,
  224, 4, 240, 4, 5, 4, 184, 255, 192, 64, 15, 9, 12, 72, 4, 4, 7, 8, 3, 158,
  31, 6, 47, 6, 2, 6, 0, 47, 93, 237, 17, 18, 1, 57, 47, 43, 93, 253, 225, 93,
  49, 48, 1, 23, 6, 3, 35, 18, 55, 3, 2, 16, 57, 137, 152, 76, 35, 1, 6, 24,
  224, 254, 209, 1, 67, 228, 0, 0, 1, 1, 29, 1, 209, 3, 176, 2, 121, 0, 3, 0,
  32, 64, 18, 128, 2, 144, 2, 2, 2, 2, 5, 32, 0, 48, 0, 2, 0, 0, 185, 1, 189, 0,
  63, 225, 1, 47, 93, 17, 51, 47, 93, 49, 48, 1, 53, 33, 21, 1, 29, 2, 147, 1,
  209, 168, 168, 0, 1, 1, 207, 255, 225, 2, 254, 1, 45, 0, 7, 0, 29, 64, 15, 2,
  151, 48, 6, 176, 6, 2, 6, 6, 8, 9, 0, 156, 4, 168, 0, 63, 237, 17, 18, 1, 57,
  47, 93, 237, 49, 48, 1, 50, 21, 20, 35, 34, 53, 52, 2, 102, 152, 152, 151, 1,
  45, 166, 166, 166, 166, 0, 1, 0, 211, 0, 0, 3, 248, 5, 182, 0, 3, 0, 28, 64,
  12, 3, 0, 0, 5, 1, 2, 2, 4, 3, 3, 1, 18, 0, 63, 63, 17, 1, 51, 47, 51, 17, 51,
  47, 50, 49, 48, 1, 1, 35, 1, 3, 248, 253, 141, 178, 2, 115, 5, 182, 250, 74,
  5, 182, 0, 0, 2, 0, 147, 255, 236, 4, 57, 5, 205, 0, 9, 0, 21, 0, 54, 64, 18,
  13, 111, 208, 8, 1, 8, 23, 19, 111, 0, 3, 16, 3, 32, 3, 3, 7, 3, 184, 255,
  192, 64, 12, 21, 24, 72, 3, 16, 115, 5, 7, 10, 115, 0, 25, 0, 63, 225, 63,
  225, 1, 47, 43, 94, 93, 225, 16, 222, 93, 225, 49, 48, 5, 34, 2, 17, 16, 33,
  50, 18, 17, 16, 37, 50, 18, 17, 16, 2, 35, 34, 2, 17, 16, 18, 2, 100, 229,
  236, 1, 209, 232, 237, 254, 43, 147, 138, 138, 147, 145, 135, 135, 20, 1, 131,
  1, 110, 2, 240, 254, 125, 254, 147, 253, 15, 155, 1, 25, 1, 61, 1, 59, 1, 25,
  254, 233, 254, 195, 254, 194, 254, 232, 0, 0, 1, 0, 225, 0, 0, 2, 246, 5, 182,
  0, 10, 0, 43, 64, 22, 9, 1, 8, 8, 0, 110, 0, 1, 16, 1, 2, 6, 1, 1, 12, 11, 4,
  7, 9, 6, 0, 24, 0, 63, 63, 205, 57, 17, 18, 1, 57, 47, 94, 93, 225, 51, 47,
  17, 51, 49, 48, 33, 35, 17, 52, 55, 6, 7, 7, 39, 1, 51, 2, 246, 176, 8, 39,
  82, 147, 97, 1, 127, 150, 3, 145, 122, 239, 43, 70, 121, 123, 1, 43, 0, 0, 1,
  0, 158, 0, 0, 4, 45, 5, 203, 0, 23, 0, 85, 64, 29, 144, 23, 160, 23, 176, 23,
  3, 23, 23, 6, 111, 255, 17, 1, 17, 64, 15, 19, 72, 17, 25, 213, 22, 229, 22,
  245, 22, 3, 22, 184, 255, 232, 64, 23, 9, 12, 72, 22, 12, 0, 1, 176, 1, 2, 1,
  6, 1, 11, 9, 115, 14, 7, 2, 22, 116, 1, 24, 0, 63, 225, 50, 63, 225, 51, 18,
  57, 1, 47, 93, 50, 50, 43, 93, 16, 222, 43, 93, 225, 51, 47, 93, 49, 48, 33,
  33, 53, 1, 54, 54, 53, 52, 38, 35, 34, 7, 39, 54, 51, 50, 22, 21, 20, 6, 7, 1,
  21, 33, 4, 45, 252, 113, 1, 94, 195, 124, 127, 108, 160, 158, 102, 192, 230,
  194, 224, 118, 232, 254, 231, 2, 176, 156, 1, 125, 213, 209, 126, 113, 131,
  137, 119, 172, 212, 179, 119, 250, 250, 254, 213, 8, 0, 0, 1, 0, 131, 255,
  236, 4, 31, 5, 203, 0, 34, 0, 95, 64, 58, 11, 19, 27, 19, 2, 0, 16, 21, 111,
  32, 32, 3, 95, 16, 1, 16, 16, 8, 13, 111, 159, 3, 175, 3, 2, 3, 36, 27, 207,
  8, 223, 8, 239, 8, 3, 0, 8, 1, 8, 0, 16, 115, 104, 17, 1, 17, 17, 11, 26, 24,
  115, 29, 7, 11, 115, 9, 6, 25, 0, 63, 51, 225, 63, 225, 51, 18, 57, 47, 93,
  225, 57, 1, 47, 93, 93, 51, 16, 222, 93, 225, 17, 57, 47, 93, 17, 51, 47, 225,
  18, 57, 49, 48, 93, 1, 21, 4, 17, 20, 4, 33, 34, 39, 53, 22, 51, 32, 17, 16,
  33, 35, 53, 51, 50, 54, 53, 52, 38, 35, 34, 7, 39, 54, 51, 50, 22, 21, 20, 6,
  2, 182, 1, 105, 254, 236, 254, 251, 242, 145, 184, 199, 1, 98, 254, 131, 133,
  133, 160, 176, 136, 114, 178, 166, 92, 187, 249, 206, 231, 164, 3, 2, 6, 47,
  254, 211, 203, 233, 79, 170, 96, 1, 33, 1, 2, 151, 152, 125, 102, 119, 121,
  125, 150, 198, 165, 138, 186, 0, 0, 2, 0, 61, 0, 0, 4, 102, 5, 190, 0, 10, 0,
  18, 0, 86, 64, 24, 7, 16, 9, 15, 72, 11, 7, 3, 110, 9, 0, 2, 64, 16, 19, 72,
  0, 2, 1, 2, 2, 19, 20, 18, 184, 255, 240, 64, 24, 11, 15, 72, 18, 5, 64, 10,
  16, 72, 5, 1, 4, 116, 9, 6, 14, 7, 11, 11, 2, 7, 6, 2, 24, 0, 63, 63, 18, 57,
  47, 18, 57, 51, 51, 225, 50, 1, 47, 43, 51, 43, 17, 18, 57, 47, 93, 43, 51,
  51, 225, 50, 50, 49, 48, 43, 1, 35, 17, 35, 17, 33, 53, 1, 51, 17, 51, 33, 17,
  52, 19, 35, 6, 7, 1, 4, 102, 213, 176, 253, 92, 2, 152, 188, 213, 254, 123,
  13, 9, 36, 54, 254, 101, 1, 72, 254, 184, 1, 72, 159, 3, 215, 252, 48, 1, 100,
  176, 1, 0, 102, 78, 253, 160, 0, 0, 1, 0, 172, 255, 236, 4, 31, 5, 182, 0, 24,
  0, 82, 64, 49, 13, 64, 11, 15, 72, 13, 13, 0, 5, 111, 159, 20, 175, 20, 2, 20,
  26, 14, 15, 15, 11, 9, 10, 10, 0, 0, 144, 0, 160, 0, 176, 0, 4, 0, 9, 7, 115,
  17, 17, 11, 3, 115, 1, 23, 25, 14, 116, 11, 6, 0, 63, 225, 63, 51, 225, 17,
  57, 47, 225, 51, 1, 47, 93, 51, 47, 51, 51, 51, 17, 51, 16, 222, 93, 225, 18,
  57, 47, 43, 49, 48, 55, 53, 22, 51, 32, 17, 16, 33, 34, 7, 39, 19, 33, 21, 33,
  3, 54, 51, 50, 4, 21, 20, 4, 35, 34, 172, 144, 216, 1, 80, 254, 168, 89, 142,
  90, 55, 2, 178, 253, 236, 39, 107, 102, 210, 1, 3, 254, 236, 251, 224, 59,
  172, 96, 1, 58, 1, 38, 26, 57, 2, 176, 166, 254, 93, 20, 229, 199, 234, 255,
  0, 0, 2, 0, 154, 255, 236, 4, 51, 5, 203, 0, 21, 0, 33, 0, 79, 64, 22, 1, 64,
  11, 15, 72, 1, 1, 18, 22, 110, 191, 12, 1, 12, 35, 6, 28, 111, 0, 18, 1, 18,
  184, 255, 192, 64, 22, 20, 24, 72, 18, 6, 25, 117, 127, 9, 1, 9, 9, 31, 3,
  115, 1, 20, 7, 31, 115, 15, 25, 0, 63, 225, 63, 51, 225, 18, 57, 47, 93, 225,
  50, 1, 47, 43, 93, 225, 50, 16, 222, 93, 225, 18, 57, 47, 43, 49, 48, 1, 21,
  38, 35, 34, 2, 3, 51, 54, 51, 50, 22, 21, 20, 2, 35, 34, 0, 17, 16, 33, 50,
  19, 52, 38, 35, 34, 6, 21, 20, 22, 51, 50, 54, 3, 197, 71, 95, 224, 225, 10,
  12, 95, 212, 195, 221, 241, 203, 218, 254, 253, 2, 127, 104, 2, 137, 127, 127,
  172, 162, 131, 127, 143, 5, 184, 155, 24, 254, 230, 254, 206, 170, 238, 206,
  228, 254, 249, 1, 81, 1, 52, 3, 90, 252, 12, 145, 156, 162, 104, 152, 221,
  176, 0, 0, 1, 0, 143, 0, 0, 4, 59, 5, 182, 0, 6, 0, 71, 64, 48, 121, 6, 137,
  6, 2, 71, 6, 87, 6, 2, 7, 6, 23, 6, 39, 6, 3, 6, 0, 0, 2, 8, 1, 24, 1, 40, 1,
  3, 1, 5, 8, 0, 2, 208, 2, 224, 2, 240, 2, 4, 2, 5, 2, 116, 3, 6, 0, 24, 0, 63,
  63, 225, 50, 1, 47, 93, 16, 206, 50, 93, 17, 57, 47, 51, 93, 49, 48, 93, 93,
  33, 1, 33, 53, 33, 21, 1, 1, 78, 2, 51, 253, 14, 3, 172, 253, 213, 5, 16, 166,
  145, 250, 219, 0, 3, 0, 156, 255, 236, 4, 49, 5, 205, 0, 19, 0, 30, 0, 41, 0,
  124, 64, 31, 10, 31, 12, 38, 110, 2, 20, 0, 2, 28, 110, 12, 22, 110, 18, 12,
  18, 12, 18, 8, 191, 2, 1, 2, 43, 33, 110, 0, 8, 1, 8, 184, 255, 192, 183, 20,
  24, 72, 8, 215, 20, 1, 20, 184, 255, 240, 64, 34, 12, 15, 72, 7, 20, 23, 20,
  2, 57, 31, 89, 31, 105, 31, 121, 31, 4, 42, 31, 1, 31, 10, 0, 20, 4, 35, 25,
  115, 15, 7, 35, 115, 5, 25, 0, 63, 225, 63, 225, 18, 23, 57, 93, 93, 93, 43,
  93, 1, 47, 43, 93, 225, 16, 206, 93, 17, 57, 57, 47, 47, 16, 225, 16, 225, 17,
  57, 57, 16, 225, 17, 57, 57, 49, 48, 1, 4, 21, 20, 6, 35, 34, 38, 53, 16, 37,
  38, 53, 52, 54, 51, 50, 22, 21, 20, 5, 54, 53, 52, 38, 35, 34, 6, 21, 20, 22,
  23, 6, 21, 20, 33, 50, 54, 53, 52, 38, 39, 2, 252, 1, 53, 252, 207, 216, 242,
  1, 26, 235, 233, 178, 184, 228, 254, 102, 232, 126, 110, 106, 125, 99, 108,
  254, 1, 20, 136, 149, 126, 151, 3, 6, 160, 233, 181, 220, 207, 186, 1, 1, 136,
  146, 223, 161, 189, 190, 162, 230, 55, 103, 175, 101, 106, 106, 101, 90, 125,
  215, 121, 204, 240, 131, 117, 90, 139, 74, 0, 0, 2, 0, 154, 255, 236, 4, 51,
  5, 203, 0, 21, 0, 33, 0, 78, 185, 0, 1, 255, 192, 64, 20, 11, 15, 72, 1, 1,
  12, 6, 28, 111, 191, 18, 1, 18, 35, 22, 110, 0, 12, 1, 12, 184, 255, 192, 64,
  19, 20, 24, 72, 12, 6, 25, 117, 9, 9, 15, 3, 117, 1, 20, 25, 31, 115, 15, 7,
  0, 63, 225, 63, 51, 225, 17, 57, 47, 225, 50, 1, 47, 43, 93, 225, 16, 222, 93,
  225, 50, 18, 57, 47, 43, 49, 48, 5, 53, 22, 51, 50, 18, 19, 35, 6, 35, 34, 38,
  53, 52, 18, 51, 50, 0, 17, 16, 33, 34, 3, 20, 22, 51, 50, 54, 53, 52, 38, 35,
  34, 6, 1, 8, 67, 99, 224, 225, 10, 12, 96, 212, 194, 221, 241, 203, 220, 1, 1,
  253, 129, 105, 1, 137, 127, 127, 172, 160, 133, 128, 142, 2, 156, 25, 1, 26,
  1, 50, 170, 236, 208, 228, 1, 8, 254, 170, 254, 209, 252, 166, 3, 243, 145,
  156, 163, 103, 151, 222, 174, 0, 0, 2, 1, 231, 255, 227, 2, 229, 4, 102, 0, 7,
  0, 15, 0, 45, 64, 27, 10, 2, 150, 14, 48, 6, 96, 6, 176, 6, 224, 6, 240, 6, 5,
  6, 6, 16, 17, 8, 155, 12, 168, 4, 155, 0, 16, 0, 63, 237, 63, 237, 17, 18, 1,
  57, 47, 93, 51, 237, 50, 49, 48, 1, 50, 21, 20, 35, 34, 53, 52, 19, 50, 21,
  20, 35, 34, 53, 52, 2, 102, 127, 127, 127, 127, 127, 127, 127, 4, 102, 139,
  139, 139, 139, 252, 148, 139, 140, 140, 139, 0, 2, 1, 154, 254, 248, 2, 236,
  4, 102, 0, 7, 0, 14, 0, 68, 64, 46, 25, 14, 41, 14, 233, 14, 249, 14, 4, 14,
  152, 12, 153, 9, 9, 2, 150, 48, 6, 96, 6, 176, 6, 224, 6, 240, 6, 5, 6, 6, 15,
  16, 11, 157, 31, 14, 47, 14, 63, 14, 3, 14, 4, 155, 0, 16, 0, 63, 237, 47, 93,
  237, 17, 18, 1, 57, 47, 93, 237, 50, 47, 237, 225, 93, 49, 48, 1, 50, 21, 20,
  35, 34, 53, 52, 19, 23, 6, 3, 35, 54, 55, 2, 109, 127, 127, 127, 215, 14, 51,
  125, 137, 62, 38, 4, 102, 139, 139, 139, 139, 252, 136, 23, 197, 254, 230,
  255, 247, 0, 0, 1, 0, 152, 0, 221, 4, 51, 4, 201, 0, 6, 0, 97, 64, 61, 103, 6,
  119, 6, 135, 6, 3, 104, 4, 120, 4, 136, 4, 3, 118, 5, 134, 5, 2, 5, 4, 1, 4,
  0, 8, 1, 1, 7, 2, 1, 5, 5, 3, 6, 224, 0, 1, 223, 0, 1, 64, 0, 1, 63, 0, 1, 0,
  0, 1, 0, 0, 4, 32, 3, 192, 3, 2, 15, 3, 1, 3, 0, 47, 93, 93, 51, 51, 47, 93,
  93, 93, 93, 93, 50, 18, 57, 17, 51, 51, 17, 1, 51, 47, 16, 206, 50, 17, 18,
  57, 93, 49, 48, 0, 93, 93, 37, 1, 53, 1, 21, 1, 1, 4, 51, 252, 101, 3, 155,
  253, 53, 2, 203, 221, 1, 195, 102, 1, 195, 160, 254, 170, 254, 170, 0, 0, 2,
  0, 152, 1, 186, 4, 51, 3, 233, 0, 3, 0, 7, 0, 64, 64, 39, 7, 2, 9, 4, 0, 1, 1,
  1, 1, 8, 5, 173, 112, 4, 1, 79, 4, 95, 4, 111, 4, 3, 0, 4, 1, 4, 4, 0, 173,
  143, 1, 1, 80, 1, 1, 15, 1, 1, 1, 0, 47, 93, 93, 93, 225, 51, 47, 93, 93, 93,
  225, 17, 1, 51, 47, 93, 51, 16, 206, 50, 49, 48, 19, 53, 33, 21, 1, 53, 33,
  21, 152, 3, 155, 252, 101, 3, 155, 3, 84, 149, 149, 254, 102, 150, 150, 0, 0,
  1, 0, 152, 0, 221, 4, 51, 4, 201, 0, 6, 0, 95, 64, 60, 104, 2, 120, 2, 136, 2,
  3, 103, 0, 119, 0, 135, 0, 3, 121, 1, 137, 1, 2, 1, 6, 4, 8, 2, 6, 6, 7, 5, 4,
  1, 1, 3, 0, 224, 6, 1, 223, 6, 1, 64, 6, 1, 63, 6, 1, 0, 6, 1, 6, 6, 2, 32, 3,
  192, 3, 2, 15, 3, 1, 3, 0, 47, 93, 93, 51, 51, 47, 93, 93, 93, 93, 93, 51, 18,
  57, 17, 51, 51, 17, 1, 51, 47, 51, 16, 206, 17, 57, 93, 49, 48, 0, 93, 93, 19,
  1, 1, 53, 1, 21, 1, 152, 2, 202, 253, 54, 3, 155, 252, 101, 1, 125, 1, 86, 1,
  86, 160, 254, 61, 102, 254, 61, 0, 0, 2, 0, 168, 255, 227, 4, 35, 5, 203, 0,
  25, 0, 33, 0, 74, 64, 42, 25, 0, 0, 28, 150, 32, 32, 13, 7, 71, 18, 35, 32,
  35, 1, 0, 13, 1, 13, 7, 15, 47, 0, 1, 0, 0, 15, 21, 26, 1, 6, 26, 1, 26, 155,
  30, 168, 12, 10, 81, 15, 4, 0, 63, 225, 51, 63, 225, 93, 93, 17, 57, 47, 93,
  18, 57, 1, 47, 93, 93, 16, 222, 225, 17, 57, 47, 229, 51, 17, 51, 49, 48, 1,
  53, 52, 54, 55, 54, 54, 53, 52, 38, 35, 34, 7, 39, 54, 51, 50, 22, 21, 20, 6,
  7, 6, 6, 21, 21, 7, 50, 21, 20, 35, 34, 53, 52, 1, 209, 92, 115, 130, 83, 149,
  132, 174, 197, 65, 209, 217, 214, 251, 107, 143, 118, 66, 72, 127, 127, 127,
  1, 158, 37, 120, 150, 82, 97, 116, 100, 92, 115, 90, 153, 97, 195, 164, 133,
  166, 108, 87, 108, 90, 18, 164, 139, 140, 140, 139, 0, 0, 2, 0, 31, 255, 74,
  4, 174, 5, 182, 0, 46, 0, 56, 0, 143, 64, 90, 22, 52, 1, 52, 211, 6, 0, 47,
  24, 56, 1, 56, 211, 14, 11, 30, 14, 28, 6, 1, 212, 14, 1, 96, 14, 1, 25, 14,
  1, 4, 14, 1, 6, 14, 6, 14, 36, 9, 19, 1, 19, 210, 42, 58, 6, 25, 1, 25, 210,
  36, 17, 54, 213, 3, 45, 3, 49, 213, 9, 63, 3, 79, 3, 143, 3, 207, 3, 223, 3,
  5, 48, 9, 64, 9, 208, 9, 3, 3, 9, 3, 9, 28, 22, 214, 39, 3, 28, 214, 30, 33,
  0, 47, 51, 225, 63, 225, 18, 57, 57, 47, 47, 93, 93, 16, 225, 17, 51, 16, 225,
  50, 1, 47, 225, 93, 16, 214, 225, 93, 17, 57, 57, 47, 47, 93, 93, 93, 93, 93,
  17, 57, 51, 16, 225, 93, 50, 57, 16, 225, 93, 49, 48, 1, 35, 6, 35, 34, 38,
  53, 52, 54, 51, 50, 23, 3, 6, 21, 21, 20, 51, 50, 17, 16, 2, 35, 34, 2, 17,
  16, 0, 51, 50, 55, 21, 6, 35, 32, 0, 17, 16, 0, 33, 50, 0, 17, 20, 2, 35, 34,
  3, 38, 35, 34, 6, 21, 20, 51, 50, 19, 3, 31, 4, 74, 156, 120, 140, 194, 158,
  137, 119, 22, 2, 72, 100, 222, 188, 226, 253, 1, 3, 239, 181, 165, 158, 194,
  254, 214, 254, 177, 1, 78, 1, 32, 248, 1, 41, 128, 114, 128, 76, 54, 49, 89,
  95, 127, 131, 14, 1, 145, 180, 209, 176, 206, 253, 47, 254, 96, 38, 31, 7,
  176, 1, 127, 1, 22, 1, 60, 254, 128, 254, 177, 254, 200, 254, 171, 78, 133,
  82, 1, 158, 1, 114, 1, 141, 1, 207, 254, 120, 254, 173, 231, 254, 233, 2, 182,
  21, 187, 147, 252, 1, 56, 0, 2, 0, 33, 0, 0, 4, 172, 5, 188, 0, 7, 0, 14, 0,
  168, 64, 10, 2, 14, 3, 8, 1, 0, 183, 6, 1, 6, 184, 255, 248, 64, 98, 14, 17,
  72, 71, 6, 1, 38, 6, 1, 23, 6, 1, 6, 6, 1, 6, 184, 5, 1, 5, 8, 14, 17, 72, 72,
  5, 1, 41, 5, 1, 24, 5, 1, 9, 5, 1, 5, 11, 11, 4, 88, 0, 1, 72, 0, 1, 42, 0, 1,
  9, 0, 25, 0, 2, 0, 7, 7, 16, 87, 3, 1, 71, 3, 1, 37, 3, 1, 6, 3, 22, 3, 2, 3,
  4, 2, 95, 11, 16, 17, 20, 72, 11, 16, 11, 14, 72, 29, 11, 1, 11, 5, 14, 14, 5,
  3, 4, 0, 18, 0, 63, 50, 63, 57, 47, 18, 57, 93, 43, 43, 225, 1, 47, 51, 93,
  93, 93, 93, 17, 51, 47, 51, 93, 93, 93, 93, 18, 57, 61, 47, 51, 93, 93, 93,
  93, 43, 93, 51, 93, 93, 93, 93, 43, 93, 18, 57, 57, 18, 57, 57, 49, 48, 33, 3,
  33, 3, 35, 1, 51, 1, 1, 3, 38, 39, 6, 7, 3, 3, 236, 144, 254, 21, 146, 190, 1,
  227, 195, 1, 229, 254, 123, 133, 39, 23, 20, 26, 144, 1, 197, 254, 59, 5, 188,
  250, 68, 2, 106, 1, 168, 124, 102, 99, 84, 254, 45, 0, 0, 3, 0, 135, 0, 0, 4,
  113, 5, 182, 0, 14, 0, 23, 0, 30, 0, 82, 64, 50, 19, 91, 20, 7, 36, 7, 2, 7,
  4, 4, 14, 28, 91, 10, 32, 15, 25, 90, 0, 14, 1, 0, 14, 16, 14, 240, 14, 3, 8,
  14, 7, 24, 96, 159, 15, 1, 104, 15, 1, 15, 15, 0, 25, 96, 14, 18, 23, 96, 0,
  3, 0, 63, 225, 63, 225, 17, 57, 47, 93, 93, 225, 57, 1, 47, 94, 93, 113, 225,
  50, 16, 222, 225, 18, 57, 47, 57, 93, 225, 49, 48, 19, 33, 32, 22, 21, 20, 6,
  7, 21, 4, 17, 20, 6, 35, 33, 19, 33, 50, 54, 53, 52, 38, 35, 33, 17, 17, 33,
  32, 17, 52, 33, 135, 1, 184, 1, 18, 247, 157, 134, 1, 76, 255, 220, 253, 241,
  187, 1, 28, 156, 143, 153, 166, 254, 248, 1, 51, 1, 55, 254, 188, 5, 182, 175,
  195, 128, 170, 18, 10, 54, 254, 224, 198, 226, 3, 74, 110, 127, 120, 104, 253,
  151, 253, 240, 1, 18, 254, 0, 1, 0, 129, 255, 236, 4, 156, 5, 203, 0, 21, 0,
  49, 64, 28, 1, 64, 20, 24, 72, 1, 1, 6, 11, 23, 17, 91, 0, 6, 240, 6, 2, 6,
  12, 14, 95, 9, 4, 0, 20, 95, 3, 19, 0, 63, 225, 50, 63, 225, 50, 1, 47, 93,
  225, 16, 206, 17, 57, 47, 43, 49, 48, 37, 21, 6, 35, 32, 0, 17, 16, 0, 33, 50,
  23, 7, 38, 35, 34, 0, 17, 16, 18, 51, 50, 4, 100, 146, 212, 254, 203, 254,
  184, 1, 102, 1, 54, 220, 163, 78, 154, 151, 215, 255, 0, 240, 231, 130, 201,
  162, 59, 1, 136, 1, 105, 1, 90, 1, 148, 86, 156, 78, 254, 195, 254, 241, 254,
  225, 254, 211, 0, 2, 0, 135, 0, 0, 4, 123, 5, 182, 0, 8, 0, 15, 0, 44, 64, 26,
  13, 91, 5, 17, 10, 90, 0, 0, 1, 0, 0, 16, 0, 240, 0, 3, 8, 0, 9, 96, 1, 3, 10,
  96, 0, 18, 0, 63, 225, 63, 225, 1, 47, 94, 93, 113, 225, 16, 222, 225, 49, 48,
  51, 17, 33, 32, 0, 17, 16, 0, 33, 3, 17, 51, 32, 17, 16, 33, 135, 1, 86, 1,
  61, 1, 97, 254, 146, 254, 167, 114, 96, 2, 20, 254, 19, 5, 182, 254, 134, 254,
  173, 254, 151, 254, 128, 5, 23, 251, 137, 2, 67, 2, 52, 0, 0, 1, 0, 217, 0, 0,
  4, 35, 5, 182, 0, 11, 0, 64, 64, 37, 8, 8, 1, 4, 0, 64, 18, 22, 72, 0, 13, 6,
  10, 90, 240, 1, 1, 0, 1, 1, 1, 9, 95, 104, 6, 1, 6, 6, 10, 5, 95, 2, 3, 10,
  95, 1, 18, 0, 63, 225, 63, 225, 18, 57, 47, 93, 225, 1, 47, 93, 93, 225, 50,
  16, 206, 43, 50, 17, 57, 47, 49, 48, 33, 33, 17, 33, 21, 33, 17, 33, 21, 33,
  17, 33, 4, 35, 252, 182, 3, 74, 253, 112, 2, 105, 253, 151, 2, 144, 5, 182,
  164, 254, 60, 162, 253, 248, 0, 1, 0, 244, 0, 0, 4, 61, 5, 182, 0, 9, 0, 87,
  64, 22, 8, 8, 1, 223, 3, 1, 192, 3, 1, 3, 11, 6, 0, 90, 0, 1, 64, 1, 80, 1, 3,
  1, 184, 255, 192, 64, 32, 21, 24, 72, 1, 9, 95, 104, 6, 1, 47, 6, 95, 6, 239,
  6, 255, 6, 4, 6, 64, 16, 21, 72, 6, 6, 0, 5, 95, 2, 3, 0, 18, 0, 63, 63, 225,
  18, 57, 47, 43, 93, 93, 225, 1, 47, 43, 93, 225, 50, 16, 206, 93, 93, 17, 57,
  47, 48, 49, 33, 35, 17, 33, 21, 33, 17, 33, 21, 33, 1, 174, 186, 3, 73, 253,
  113, 2, 105, 253, 151, 5, 182, 164, 253, 252, 164, 0, 1, 0, 117, 255, 236, 4,
  70, 5, 203, 0, 24, 0, 63, 64, 37, 0, 7, 22, 90, 12, 2, 26, 18, 91, 0, 7, 1, 7,
  24, 95, 47, 0, 95, 0, 2, 0, 64, 16, 24, 72, 0, 0, 20, 15, 95, 13, 10, 4, 20,
  95, 4, 19, 0, 63, 225, 63, 51, 225, 18, 57, 47, 43, 93, 225, 1, 47, 93, 225,
  16, 222, 50, 225, 18, 57, 49, 48, 1, 33, 17, 6, 35, 32, 0, 17, 16, 0, 33, 50,
  23, 7, 38, 35, 34, 2, 17, 16, 33, 50, 55, 17, 35, 2, 160, 1, 166, 195, 225,
  254, 250, 254, 217, 1, 68, 1, 28, 192, 154, 72, 146, 134, 192, 214, 1, 138,
  97, 105, 237, 3, 4, 253, 51, 75, 1, 143, 1, 98, 1, 95, 1, 143, 86, 162, 84,
  254, 201, 254, 235, 253, 180, 29, 1, 180, 0, 0, 1, 0, 135, 0, 0, 4, 70, 5,
  182, 0, 11, 0, 63, 64, 38, 9, 1, 90, 0, 13, 8, 4, 90, 16, 5, 32, 5, 2, 32, 5,
  48, 5, 2, 5, 3, 95, 152, 8, 1, 15, 8, 47, 8, 2, 6, 8, 8, 10, 6, 3, 5, 0, 18,
  0, 63, 50, 63, 51, 57, 47, 94, 93, 93, 225, 1, 47, 93, 113, 225, 50, 16, 222,
  225, 50, 49, 48, 33, 35, 17, 33, 17, 35, 17, 51, 17, 33, 17, 51, 4, 70, 187,
  253, 183, 187, 187, 2, 73, 187, 2, 170, 253, 86, 5, 182, 253, 152, 2, 104, 0,
  0, 1, 0, 225, 0, 0, 3, 233, 5, 182, 0, 11, 0, 67, 64, 40, 11, 8, 10, 90, 5, 2,
  208, 3, 1, 162, 3, 1, 147, 3, 1, 3, 142, 3, 1, 4, 99, 3, 1, 5, 16, 3, 80, 3,
  2, 3, 9, 4, 97, 6, 3, 3, 10, 97, 0, 18, 0, 63, 225, 50, 63, 225, 50, 1, 47,
  93, 95, 93, 95, 93, 95, 93, 93, 93, 51, 51, 225, 50, 50, 49, 48, 33, 33, 53,
  37, 17, 37, 53, 33, 21, 5, 17, 5, 3, 233, 252, 248, 1, 39, 254, 217, 3, 8,
  254, 218, 1, 38, 123, 20, 4, 152, 20, 123, 123, 20, 251, 104, 20, 0, 1, 0,
  137, 255, 236, 3, 211, 5, 182, 0, 13, 0, 43, 178, 6, 90, 9, 184, 255, 192, 64,
  20, 9, 12, 72, 9, 15, 0, 0, 224, 0, 240, 0, 3, 0, 3, 95, 1, 12, 19, 7, 3, 0,
  63, 63, 51, 225, 1, 47, 93, 16, 222, 43, 225, 49, 48, 55, 53, 22, 51, 50, 54,
  53, 17, 51, 17, 20, 4, 35, 34, 137, 162, 147, 161, 186, 186, 254, 231, 237,
  217, 39, 166, 62, 159, 147, 3, 245, 252, 13, 216, 255, 0, 1, 0, 211, 0, 0, 4,
  174, 5, 182, 0, 12, 0, 201, 183, 38, 12, 54, 12, 70, 12, 3, 12, 184, 255, 240,
  64, 137, 16, 24, 72, 248, 10, 1, 217, 10, 233, 10, 2, 200, 10, 1, 185, 10, 1,
  168, 10, 1, 137, 10, 1, 10, 8, 12, 16, 72, 121, 9, 1, 88, 9, 1, 25, 9, 1, 10,
  9, 1, 136, 1, 1, 1, 8, 20, 24, 72, 1, 8, 12, 15, 72, 232, 2, 1, 2, 16, 11, 22,
  72, 71, 2, 1, 2, 12, 0, 8, 4, 90, 0, 5, 96, 5, 112, 5, 128, 5, 4, 5, 11, 16,
  11, 11, 208, 0, 240, 0, 2, 127, 0, 1, 0, 0, 16, 0, 64, 0, 96, 0, 4, 0, 16, 0,
  166, 8, 182, 8, 198, 8, 3, 119, 8, 135, 8, 2, 38, 8, 54, 8, 86, 8, 102, 8, 4,
  3, 2, 8, 12, 4, 5, 10, 6, 3, 5, 0, 18, 0, 63, 50, 63, 51, 18, 23, 57, 93, 93,
  93, 1, 47, 56, 93, 93, 93, 51, 47, 56, 47, 93, 225, 50, 17, 57, 57, 93, 49,
  48, 0, 43, 93, 1, 43, 43, 93, 93, 93, 93, 93, 43, 93, 93, 93, 93, 93, 93, 43,
  93, 33, 35, 1, 7, 17, 35, 17, 51, 17, 55, 1, 51, 1, 4, 174, 211, 254, 62, 140,
  186, 186, 121, 1, 197, 209, 253, 247, 2, 186, 114, 253, 184, 5, 182, 253, 37,
  168, 2, 51, 253, 131, 0, 1, 0, 233, 0, 0, 4, 31, 5, 182, 0, 5, 0, 46, 64, 31,
  5, 64, 18, 22, 72, 5, 7, 3, 90, 0, 0, 80, 0, 96, 0, 112, 0, 208, 0, 224, 0,
  240, 0, 7, 0, 1, 3, 3, 95, 0, 18, 0, 63, 225, 63, 1, 47, 93, 225, 16, 206, 43,
  49, 48, 51, 17, 51, 17, 33, 21, 233, 187, 2, 123, 5, 182, 250, 240, 166, 0, 0,
  1, 0, 113, 0, 0, 4, 92, 5, 182, 0, 19, 0, 182, 64, 12, 247, 19, 1, 182, 19, 1,
  151, 19, 167, 19, 2, 19, 184, 255, 240, 64, 37, 13, 17, 72, 39, 19, 1, 6, 19,
  22, 19, 2, 233, 11, 249, 11, 2, 11, 32, 13, 22, 72, 58, 11, 1, 9, 11, 25, 11,
  41, 11, 3, 230, 8, 246, 8, 2, 8, 184, 255, 224, 64, 77, 13, 22, 72, 53, 8, 1,
  6, 8, 22, 8, 38, 8, 3, 248, 0, 1, 185, 0, 1, 152, 0, 168, 0, 2, 0, 16, 13, 17,
  72, 40, 0, 1, 9, 0, 25, 0, 2, 17, 14, 250, 224, 13, 240, 13, 2, 15, 13, 1, 13,
  21, 2, 5, 250, 0, 6, 16, 6, 64, 6, 80, 6, 4, 6, 11, 1, 7, 3, 18, 2, 14, 89, 9,
  1, 9, 6, 0, 18, 0, 63, 50, 50, 93, 50, 46, 51, 63, 51, 51, 1, 47, 93, 225, 50,
  16, 222, 93, 93, 225, 50, 49, 48, 93, 93, 43, 93, 93, 93, 93, 93, 43, 93, 93,
  93, 43, 93, 93, 93, 43, 93, 93, 93, 33, 1, 35, 18, 21, 17, 35, 17, 51, 19, 51,
  19, 51, 17, 35, 17, 52, 19, 35, 1, 2, 20, 254, 234, 8, 18, 151, 247, 248, 6,
  250, 252, 153, 14, 8, 254, 229, 5, 0, 254, 246, 140, 252, 150, 5, 182, 251,
  88, 4, 168, 250, 74, 3, 119, 102, 1, 33, 251, 2, 0, 0, 1, 0, 135, 0, 0, 4, 68,
  5, 182, 0, 15, 0, 115, 185, 0, 9, 255, 240, 64, 78, 16, 24, 72, 69, 9, 85, 9,
  101, 9, 3, 52, 9, 1, 21, 9, 37, 9, 2, 6, 9, 1, 1, 16, 16, 24, 72, 74, 1, 90,
  1, 106, 1, 3, 59, 1, 1, 26, 1, 42, 1, 2, 9, 1, 1, 1, 14, 251, 15, 17, 9, 6,
  251, 0, 7, 224, 7, 240, 7, 3, 7, 14, 73, 2, 89, 2, 2, 2, 8, 3, 70, 10, 86, 10,
  2, 10, 7, 0, 18, 0, 63, 50, 50, 93, 63, 51, 93, 51, 1, 47, 93, 225, 50, 16,
  222, 225, 50, 49, 48, 93, 93, 93, 93, 43, 93, 93, 93, 93, 43, 33, 35, 1, 35,
  18, 21, 17, 35, 17, 51, 1, 51, 2, 53, 17, 51, 4, 68, 215, 253, 188, 8, 18,
  172, 213, 2, 66, 6, 14, 174, 4, 186, 254, 235, 140, 252, 231, 5, 182, 251, 76,
  1, 47, 101, 3, 32, 0, 0, 2, 0, 84, 255, 236, 4, 123, 5, 205, 0, 9, 0, 19, 0,
  36, 64, 20, 13, 91, 7, 21, 18, 91, 31, 2, 47, 2, 2, 2, 16, 95, 4, 4, 10, 95,
  0, 19, 0, 63, 225, 63, 225, 1, 47, 93, 225, 16, 222, 225, 49, 48, 5, 32, 17,
  16, 33, 32, 0, 17, 16, 0, 39, 50, 18, 17, 16, 2, 35, 32, 17, 16, 2, 104, 253,
  236, 2, 22, 1, 0, 1, 17, 254, 236, 255, 173, 161, 163, 169, 254, 175, 20, 2,
  243, 2, 238, 254, 121, 254, 151, 254, 151, 254, 120, 163, 1, 34, 1, 44, 1, 47,
  1, 29, 253, 180, 253, 178, 0, 0, 2, 0, 176, 0, 0, 4, 70, 5, 182, 0, 9, 0, 17,
  0, 56, 64, 34, 14, 91, 239, 6, 255, 6, 2, 6, 19, 10, 1, 90, 0, 2, 144, 2, 160,
  2, 3, 2, 0, 96, 159, 10, 1, 10, 10, 1, 17, 96, 3, 3, 1, 18, 0, 63, 63, 225,
  18, 57, 47, 93, 225, 1, 47, 93, 225, 50, 16, 222, 93, 225, 49, 48, 1, 17, 35,
  17, 33, 32, 17, 20, 4, 33, 39, 51, 50, 54, 53, 16, 33, 35, 1, 106, 186, 1,
  148, 2, 2, 254, 235, 254, 248, 191, 170, 198, 171, 254, 174, 201, 2, 57, 253,
  199, 5, 182, 254, 84, 219, 246, 158, 144, 153, 1, 23, 0, 0, 2, 0, 84, 254, 98,
  4, 123, 5, 205, 0, 15, 0, 25, 0, 85, 185, 0, 0, 255, 240, 64, 48, 13, 17, 72,
  5, 0, 9, 19, 91, 14, 108, 3, 124, 3, 140, 3, 3, 3, 24, 11, 14, 72, 3, 2, 2,
  14, 27, 24, 91, 31, 9, 47, 9, 2, 9, 22, 95, 11, 4, 16, 95, 7, 5, 7, 3, 3, 0,
  7, 19, 0, 63, 51, 51, 47, 17, 51, 16, 225, 63, 225, 1, 47, 93, 225, 16, 206,
  50, 47, 51, 43, 93, 16, 225, 18, 57, 57, 49, 48, 43, 37, 22, 23, 7, 38, 39, 6,
  35, 32, 17, 16, 33, 32, 0, 17, 16, 5, 50, 18, 17, 16, 2, 35, 32, 17, 16, 3,
  94, 85, 194, 121, 236, 92, 36, 40, 253, 236, 2, 22, 1, 0, 1, 17, 253, 237,
  173, 161, 163, 169, 254, 175, 39, 180, 131, 142, 171, 229, 6, 2, 243, 2, 238,
  254, 121, 254, 151, 253, 242, 64, 1, 34, 1, 44, 1, 47, 1, 29, 253, 180, 253,
  178, 0, 2, 0, 186, 0, 0, 4, 147, 5, 182, 0, 11, 0, 20, 0, 115, 64, 75, 43, 14,
  1, 26, 14, 1, 11, 8, 16, 24, 72, 41, 11, 1, 24, 11, 1, 10, 8, 18, 24, 72, 41,
  10, 1, 8, 10, 1, 10, 9, 16, 9, 9, 70, 8, 1, 11, 8, 1, 16, 91, 6, 64, 19, 22,
  72, 6, 22, 12, 1, 90, 0, 2, 128, 2, 144, 2, 160, 2, 4, 2, 8, 3, 0, 96, 12, 12,
  1, 20, 96, 3, 3, 10, 1, 18, 0, 63, 51, 63, 225, 18, 57, 47, 225, 17, 57, 1,
  47, 93, 225, 50, 16, 222, 43, 225, 18, 57, 57, 93, 51, 47, 56, 51, 49, 48, 93,
  93, 43, 93, 93, 43, 93, 93, 1, 17, 35, 17, 33, 32, 17, 16, 5, 1, 35, 1, 39,
  51, 50, 54, 53, 52, 38, 35, 35, 1, 117, 187, 1, 101, 2, 8, 254, 223, 1, 141,
  219, 254, 162, 229, 164, 171, 162, 160, 178, 159, 2, 92, 253, 164, 5, 182,
  254, 97, 254, 225, 105, 253, 113, 2, 92, 158, 132, 144, 141, 124, 0, 0, 1, 0,
  141, 255, 236, 4, 63, 5, 203, 0, 31, 0, 56, 64, 31, 16, 16, 5, 90, 176, 27,
  192, 27, 2, 27, 33, 21, 90, 11, 0, 0, 0, 11, 1, 11, 21, 5, 14, 3, 96, 30, 19,
  19, 95, 14, 4, 0, 63, 225, 63, 225, 18, 57, 57, 1, 47, 93, 51, 47, 16, 225,
  16, 222, 93, 225, 51, 47, 49, 48, 55, 53, 22, 51, 32, 53, 52, 38, 39, 38, 38,
  53, 52, 36, 51, 50, 23, 7, 38, 35, 32, 21, 20, 22, 23, 22, 22, 21, 20, 4, 35,
  32, 141, 211, 203, 1, 94, 141, 215, 208, 181, 1, 1, 224, 229, 187, 64, 193,
  167, 254, 219, 131, 205, 246, 165, 254, 235, 255, 254, 247, 49, 178, 86, 240,
  104, 112, 77, 73, 203, 162, 174, 197, 78, 164, 78, 209, 102, 124, 71, 88, 187,
  147, 192, 219, 0, 1, 0, 102, 0, 0, 4, 100, 5, 182, 0, 7, 0, 60, 64, 36, 6, 6,
  0, 90, 3, 208, 1, 1, 162, 1, 1, 147, 1, 1, 3, 142, 1, 1, 4, 99, 1, 1, 5, 16,
  1, 80, 1, 2, 1, 7, 3, 95, 4, 3, 0, 18, 0, 63, 63, 225, 50, 1, 47, 93, 95, 93,
  95, 93, 95, 93, 93, 93, 198, 241, 194, 47, 49, 48, 33, 35, 17, 33, 53, 33, 21,
  33, 2, 195, 187, 254, 94, 3, 254, 254, 95, 5, 18, 164, 164, 0, 0, 1, 0, 125,
  255, 236, 4, 80, 5, 184, 0, 14, 0, 39, 64, 22, 13, 90, 224, 1, 240, 1, 2, 1,
  16, 9, 90, 0, 6, 1, 6, 11, 95, 4, 19, 7, 0, 3, 0, 63, 50, 63, 225, 1, 47, 93,
  225, 16, 222, 93, 225, 49, 48, 1, 17, 16, 2, 35, 32, 17, 17, 51, 17, 16, 33,
  32, 19, 17, 4, 80, 252, 244, 254, 29, 186, 1, 51, 1, 39, 5, 5, 184, 252, 76,
  254, 252, 254, 236, 2, 28, 3, 174, 252, 92, 254, 125, 1, 133, 3, 164, 0, 1, 0,
  33, 0, 0, 4, 172, 5, 182, 0, 10, 0, 153, 64, 24, 103, 5, 1, 184, 3, 1, 3, 8,
  13, 17, 72, 41, 3, 1, 24, 3, 1, 9, 3, 1, 183, 2, 1, 2, 184, 255, 248, 64, 59,
  13, 17, 72, 38, 2, 1, 23, 2, 1, 6, 2, 1, 104, 0, 1, 232, 3, 1, 3, 231, 2, 1,
  2, 8, 8, 4, 72, 0, 88, 0, 2, 42, 0, 1, 9, 0, 25, 0, 2, 0, 1, 1, 12, 71, 5, 87,
  5, 2, 37, 5, 1, 6, 5, 22, 5, 2, 5, 4, 8, 184, 255, 240, 64, 14, 11, 24, 72,
  18, 8, 1, 8, 3, 1, 4, 3, 2, 3, 18, 0, 63, 51, 63, 51, 18, 57, 93, 43, 1, 47,
  51, 93, 93, 93, 17, 51, 47, 51, 93, 93, 93, 18, 57, 61, 47, 51, 93, 51, 93,
  49, 48, 93, 93, 93, 93, 43, 93, 93, 93, 93, 43, 93, 93, 1, 51, 1, 35, 1, 51,
  1, 22, 23, 54, 55, 3, 229, 199, 254, 23, 187, 254, 25, 196, 1, 39, 41, 47, 31,
  62, 5, 182, 250, 74, 5, 182, 252, 97, 127, 207, 145, 195, 0, 0, 1, 0, 2, 0, 0,
  4, 203, 5, 182, 0, 25, 1, 99, 64, 84, 41, 25, 57, 25, 2, 8, 25, 24, 25, 2, 39,
  21, 1, 21, 21, 1, 6, 21, 1, 7, 20, 23, 20, 39, 20, 3, 38, 16, 54, 16, 2, 41,
  10, 57, 10, 2, 40, 6, 1, 25, 6, 1, 8, 6, 1, 38, 2, 54, 2, 2, 7, 2, 23, 2, 2,
  72, 17, 104, 17, 168, 17, 184, 17, 4, 41, 17, 57, 17, 2, 17, 231, 16, 247, 16,
  2, 198, 16, 214, 16, 2, 180, 16, 1, 16, 184, 255, 240, 64, 33, 15, 19, 72, 84,
  16, 1, 69, 16, 1, 16, 23, 230, 1, 1, 199, 1, 215, 1, 2, 165, 1, 181, 1, 2,
  150, 1, 1, 119, 1, 135, 1, 2, 1, 184, 255, 240, 64, 140, 9, 15, 72, 1, 233, 0,
  1, 200, 0, 216, 0, 2, 170, 0, 186, 0, 2, 153, 0, 1, 120, 0, 136, 0, 2, 0, 16,
  9, 15, 72, 0, 13, 232, 10, 248, 10, 2, 201, 10, 217, 10, 2, 187, 10, 1, 136,
  10, 168, 10, 2, 105, 10, 121, 10, 2, 91, 10, 1, 74, 10, 1, 10, 103, 9, 167, 9,
  183, 9, 3, 38, 9, 54, 9, 70, 9, 3, 9, 4, 36, 23, 52, 23, 148, 23, 164, 23, 4,
  4, 4, 20, 4, 100, 4, 196, 4, 212, 4, 5, 23, 13, 4, 4, 13, 23, 3, 18, 40, 7, 1,
  7, 16, 8, 1, 8, 8, 27, 39, 19, 1, 19, 18, 4, 23, 75, 13, 91, 13, 2, 13, 23,
  17, 0, 0, 7, 10, 17, 18, 18, 7, 3, 0, 63, 51, 63, 51, 18, 57, 47, 18, 57, 57,
  93, 17, 51, 1, 47, 51, 93, 17, 51, 47, 93, 51, 93, 18, 23, 57, 61, 47, 47, 47,
  93, 93, 17, 51, 93, 93, 51, 93, 93, 93, 93, 93, 93, 93, 17, 51, 43, 93, 93,
  93, 93, 93, 51, 43, 93, 93, 93, 93, 93, 17, 51, 93, 93, 43, 93, 93, 93, 51,
  93, 93, 49, 48, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 1, 51, 19,
  22, 23, 54, 19, 19, 51, 3, 35, 3, 38, 39, 6, 7, 3, 35, 3, 51, 19, 22, 18, 21,
  54, 55, 2, 16, 177, 145, 61, 11, 2, 63, 70, 170, 187, 190, 168, 40, 26, 32,
  33, 156, 190, 203, 170, 88, 23, 34, 24, 46, 3, 240, 253, 247, 219, 88, 53, 2,
  54, 2, 151, 250, 74, 2, 68, 138, 144, 173, 111, 253, 190, 5, 182, 253, 105,
  176, 254, 108, 39, 151, 161, 0, 1, 0, 53, 0, 0, 4, 150, 5, 182, 0, 11, 0, 190,
  64, 36, 8, 8, 9, 11, 11, 10, 0, 7, 0, 5, 5, 4, 2, 2, 3, 1, 6, 1, 8, 8, 7, 5,
  5, 6, 4, 9, 4, 11, 11, 0, 2, 2, 1, 3, 10, 7, 184, 255, 248, 64, 23, 12, 15,
  72, 6, 7, 22, 7, 38, 7, 3, 9, 8, 12, 15, 72, 9, 9, 25, 9, 41, 9, 3, 3, 184,
  255, 248, 64, 60, 12, 15, 72, 6, 3, 22, 3, 38, 3, 3, 1, 8, 12, 15, 72, 9, 1,
  25, 1, 41, 1, 3, 11, 8, 2, 5, 4, 4, 9, 10, 1, 10, 175, 0, 1, 0, 0, 13, 7, 6,
  3, 6, 4, 2, 5, 11, 8, 4, 7, 9, 10, 3, 6, 3, 1, 3, 4, 3, 0, 18, 0, 63, 23, 50,
  63, 23, 51, 23, 57, 1, 47, 51, 51, 47, 51, 17, 51, 47, 93, 50, 50, 47, 51, 17,
  23, 57, 93, 43, 93, 43, 93, 43, 93, 43, 49, 48, 135, 8, 192, 8, 192, 16, 135,
  8, 192, 8, 192, 16, 135, 8, 192, 8, 192, 16, 135, 8, 192, 8, 192, 33, 35, 1,
  1, 35, 1, 1, 51, 1, 1, 51, 1, 4, 150, 211, 254, 157, 254, 146, 189, 1, 197,
  254, 90, 199, 1, 75, 1, 78, 191, 254, 90, 2, 123, 253, 133, 2, 252, 2, 186,
  253, 209, 2, 47, 253, 76, 0, 1, 0, 33, 0, 0, 4, 170, 5, 182, 0, 8, 0, 181,
  185, 0, 8, 255, 248, 64, 36, 13, 16, 72, 38, 8, 54, 8, 2, 23, 8, 1, 104, 1,
  120, 1, 2, 90, 1, 1, 72, 1, 1, 41, 1, 57, 1, 2, 24, 1, 1, 39, 0, 183, 0, 2, 0,
  184, 255, 248, 179, 13, 17, 72, 8, 184, 255, 248, 64, 74, 20, 24, 72, 8, 175,
  7, 255, 7, 2, 89, 7, 1, 7, 5, 1, 8, 20, 24, 72, 1, 224, 2, 240, 2, 2, 123, 2,
  1, 80, 2, 1, 2, 2, 0, 4, 90, 208, 5, 1, 162, 5, 1, 147, 5, 1, 3, 142, 5, 1, 4,
  99, 5, 1, 5, 16, 5, 80, 5, 2, 5, 6, 6, 52, 0, 1, 0, 3, 3, 1, 4, 18, 7, 1, 3,
  0, 63, 51, 63, 18, 57, 47, 51, 93, 51, 47, 1, 47, 93, 95, 93, 95, 93, 95, 93,
  93, 93, 241, 57, 194, 47, 93, 93, 93, 50, 43, 16, 198, 93, 93, 50, 43, 49, 48,
  0, 43, 93, 1, 93, 93, 93, 93, 93, 93, 93, 43, 1, 1, 51, 1, 17, 35, 17, 1, 51,
  2, 100, 1, 125, 201, 254, 25, 187, 254, 25, 203, 2, 211, 2, 227, 252, 131,
  253, 199, 2, 47, 3, 135, 0, 0, 1, 0, 102, 0, 0, 4, 100, 5, 182, 0, 9, 0, 68,
  64, 40, 38, 8, 1, 7, 8, 23, 8, 2, 41, 3, 1, 8, 3, 24, 3, 2, 3, 7, 7, 0, 0, 1,
  0, 0, 11, 8, 2, 4, 4, 2, 7, 4, 95, 5, 3, 2, 8, 95, 1, 18, 0, 63, 225, 50, 63,
  225, 50, 1, 47, 51, 47, 17, 51, 17, 51, 47, 93, 51, 47, 51, 49, 48, 93, 93,
  93, 93, 33, 33, 53, 1, 33, 53, 33, 21, 1, 33, 4, 100, 252, 2, 3, 25, 252, 252,
  3, 213, 252, 231, 3, 45, 145, 4, 127, 166, 145, 251, 129, 0, 0, 1, 1, 156,
  254, 188, 3, 172, 5, 182, 0, 7, 0, 51, 64, 32, 4, 0, 0, 1, 0, 0, 9, 6, 241,
  127, 1, 143, 1, 191, 1, 207, 1, 223, 1, 5, 0, 1, 1, 1, 5, 245, 2, 248, 6, 245,
  1, 249, 0, 63, 225, 63, 225, 1, 47, 93, 93, 225, 17, 51, 47, 93, 51, 49, 48,
  1, 33, 17, 33, 21, 33, 17, 33, 3, 172, 253, 240, 2, 16, 254, 166, 1, 90, 254,
  188, 6, 250, 149, 250, 49, 0, 1, 0, 211, 0, 0, 3, 248, 5, 182, 0, 3, 0, 28,
  64, 12, 2, 1, 1, 5, 0, 3, 3, 4, 2, 18, 0, 3, 0, 63, 63, 17, 1, 51, 47, 51, 17,
  51, 47, 51, 49, 48, 1, 1, 35, 1, 1, 133, 2, 115, 178, 253, 141, 5, 182, 250,
  74, 5, 182, 0, 0, 1, 1, 33, 254, 188, 3, 49, 5, 182, 0, 7, 0, 52, 183, 1, 241,
  112, 6, 128, 6, 2, 6, 184, 255, 192, 64, 21, 20, 24, 72, 6, 6, 9, 3, 224, 0,
  240, 0, 2, 0, 1, 245, 6, 249, 2, 245, 5, 248, 0, 63, 225, 63, 225, 1, 47, 93,
  51, 17, 51, 47, 43, 93, 225, 49, 48, 5, 33, 17, 33, 53, 33, 17, 33, 1, 33, 1,
  90, 254, 166, 2, 16, 253, 240, 174, 5, 207, 149, 249, 6, 0, 1, 0, 111, 2, 37,
  4, 94, 5, 193, 0, 6, 0, 51, 64, 25, 2, 1, 5, 32, 20, 24, 72, 5, 5, 0, 4, 3, 8,
  6, 0, 0, 7, 4, 0, 0, 5, 15, 1, 1, 1, 0, 47, 93, 51, 51, 47, 50, 17, 1, 51, 47,
  50, 16, 206, 50, 17, 57, 61, 47, 43, 51, 51, 49, 48, 19, 1, 51, 1, 35, 1, 1,
  111, 1, 168, 102, 1, 225, 162, 254, 144, 254, 194, 2, 37, 3, 156, 252, 100, 2,
  223, 253, 33, 0, 0, 1, 255, 240, 254, 188, 4, 219, 255, 72, 0, 3, 0, 18, 182,
  0, 0, 5, 1, 1, 186, 2, 0, 47, 225, 1, 47, 17, 51, 47, 49, 48, 1, 33, 53, 33,
  4, 219, 251, 21, 4, 235, 254, 188, 140, 0, 0, 1, 1, 162, 4, 217, 3, 43, 6, 33,
  0, 7, 0, 31, 64, 16, 5, 135, 4, 134, 1, 0, 0, 9, 5, 146, 15, 1, 95, 1, 2, 1,
  0, 47, 93, 237, 17, 1, 51, 47, 51, 253, 225, 49, 48, 1, 35, 38, 39, 53, 51,
  22, 23, 3, 43, 121, 166, 106, 219, 86, 88, 4, 217, 142, 165, 21, 178, 123, 0,
  2, 0, 135, 255, 236, 4, 2, 4, 94, 0, 23, 0, 33, 0, 66, 64, 38, 11, 1, 33, 71,
  143, 23, 159, 23, 2, 23, 35, 28, 72, 17, 0, 8, 16, 8, 2, 8, 8, 24, 82, 11, 11,
  30, 16, 14, 80, 19, 16, 1, 30, 78, 5, 22, 0, 21, 0, 63, 63, 225, 50, 63, 225,
  51, 18, 57, 47, 225, 1, 47, 94, 93, 51, 225, 16, 222, 93, 225, 50, 50, 49, 48,
  33, 39, 35, 6, 6, 35, 34, 38, 53, 16, 37, 55, 53, 52, 35, 34, 7, 39, 54, 51,
  50, 22, 21, 17, 3, 7, 6, 6, 21, 20, 51, 50, 54, 53, 3, 127, 37, 8, 77, 162,
  128, 163, 185, 1, 254, 203, 244, 147, 181, 63, 196, 187, 227, 203, 180, 162,
  196, 164, 200, 147, 175, 152, 97, 75, 172, 155, 1, 76, 16, 7, 69, 236, 82,
  137, 96, 174, 192, 253, 16, 2, 25, 7, 8, 107, 110, 178, 163, 148, 0, 2, 0,
  158, 255, 236, 4, 68, 6, 20, 0, 18, 0, 28, 0, 58, 64, 34, 24, 72, 239, 14,
  255, 14, 2, 14, 30, 1, 8, 6, 19, 71, 0, 3, 176, 3, 2, 3, 1, 22, 80, 17, 22, 8,
  26, 80, 11, 16, 4, 0, 3, 21, 0, 63, 63, 63, 225, 50, 63, 225, 50, 1, 47, 93,
  225, 50, 50, 57, 16, 222, 93, 225, 49, 48, 37, 35, 7, 35, 17, 51, 17, 20, 7,
  51, 54, 51, 50, 18, 17, 16, 2, 35, 34, 3, 20, 22, 51, 32, 17, 16, 33, 34, 6,
  1, 84, 12, 37, 133, 182, 8, 8, 107, 215, 201, 229, 230, 200, 207, 115, 139,
  152, 1, 16, 254, 238, 155, 134, 139, 139, 6, 20, 254, 136, 81, 145, 164, 254,
  213, 254, 244, 254, 242, 254, 211, 2, 59, 227, 193, 1, 166, 1, 158, 188, 0, 0,
  1, 0, 172, 255, 236, 4, 37, 4, 94, 0, 19, 0, 43, 64, 23, 0, 0, 143, 9, 1, 9,
  21, 5, 72, 0, 15, 1, 15, 3, 81, 1, 18, 16, 9, 7, 81, 12, 22, 0, 63, 225, 51,
  63, 51, 225, 1, 47, 93, 225, 16, 206, 93, 50, 47, 49, 48, 1, 7, 38, 35, 32,
  17, 16, 33, 50, 55, 21, 6, 35, 32, 0, 17, 16, 0, 33, 50, 4, 37, 62, 150, 118,
  254, 141, 1, 105, 157, 164, 134, 195, 254, 255, 254, 228, 1, 34, 1, 7, 178, 4,
  35, 158, 57, 254, 99, 254, 106, 62, 160, 61, 1, 35, 1, 16, 1, 25, 1, 38, 0, 2,
  0, 137, 255, 236, 4, 47, 6, 20, 0, 18, 0, 29, 0, 58, 64, 35, 20, 0, 14, 71,
  144, 17, 160, 17, 2, 17, 31, 25, 72, 0, 6, 224, 6, 240, 6, 3, 6, 15, 0, 11,
  23, 80, 9, 16, 1, 27, 80, 3, 22, 18, 21, 0, 63, 63, 225, 50, 63, 225, 50, 63,
  1, 47, 93, 225, 16, 222, 93, 225, 50, 50, 49, 48, 37, 35, 6, 35, 34, 2, 17,
  16, 18, 51, 50, 23, 51, 38, 53, 17, 51, 17, 35, 3, 53, 52, 38, 35, 32, 17, 16,
  33, 50, 54, 3, 129, 8, 113, 209, 201, 229, 230, 200, 206, 116, 12, 12, 182,
  147, 35, 139, 152, 254, 240, 1, 18, 152, 133, 147, 167, 1, 43, 1, 12, 1, 14,
  1, 45, 160, 129, 33, 1, 180, 249, 236, 1, 250, 41, 227, 193, 254, 90, 254, 98,
  177, 0, 0, 2, 0, 133, 255, 236, 4, 72, 4, 94, 0, 17, 0, 22, 0, 71, 64, 44, 19,
  72, 5, 15, 0, 31, 0, 2, 0, 24, 18, 1, 72, 0, 11, 16, 11, 2, 16, 11, 32, 11, 2,
  11, 1, 80, 15, 18, 31, 18, 2, 7, 18, 18, 3, 21, 80, 14, 16, 3, 81, 5, 8, 22,
  0, 63, 51, 225, 63, 225, 18, 57, 47, 94, 93, 225, 1, 47, 93, 113, 225, 50, 16,
  222, 113, 50, 225, 49, 48, 1, 33, 18, 33, 50, 55, 21, 6, 35, 34, 0, 17, 16, 0,
  51, 50, 18, 21, 37, 33, 16, 33, 32, 4, 72, 252, 250, 8, 1, 80, 195, 175, 166,
  198, 245, 254, 218, 1, 15, 227, 212, 253, 252, 254, 2, 61, 254, 240, 254, 237,
  2, 2, 254, 137, 76, 160, 75, 1, 43, 1, 6, 1, 10, 1, 55, 254, 244, 223, 35, 1,
  49, 0, 1, 0, 156, 0, 0, 4, 90, 6, 31, 0, 21, 0, 70, 64, 40, 0, 0, 13, 13, 23,
  20, 2, 71, 3, 7, 3, 143, 5, 239, 5, 2, 5, 5, 0, 3, 176, 3, 240, 3, 3, 3, 4, 1,
  78, 7, 6, 20, 15, 16, 80, 14, 11, 1, 2, 21, 0, 63, 63, 51, 225, 63, 51, 51,
  225, 50, 1, 47, 93, 51, 47, 93, 17, 51, 16, 225, 50, 17, 51, 47, 57, 47, 49,
  48, 1, 33, 17, 35, 17, 33, 53, 37, 53, 52, 54, 51, 50, 23, 7, 38, 35, 34, 6,
  21, 21, 33, 4, 20, 254, 123, 182, 254, 195, 1, 61, 180, 209, 129, 123, 41,
  104, 103, 123, 88, 1, 133, 3, 193, 252, 63, 3, 193, 110, 33, 96, 193, 174, 35,
  143, 28, 100, 115, 104, 0, 0, 3, 0, 102, 254, 20, 4, 102, 4, 94, 0, 36, 0, 44,
  0, 54, 0, 128, 64, 47, 52, 17, 17, 2, 36, 9, 28, 4, 31, 39, 70, 1, 95, 4, 223,
  4, 239, 4, 255, 4, 4, 4, 56, 11, 26, 26, 31, 48, 63, 22, 79, 22, 95, 22, 3,
  22, 22, 43, 70, 128, 31, 144, 31, 160, 31, 3, 31, 184, 255, 192, 64, 29, 6, 9,
  72, 31, 28, 4, 34, 37, 82, 7, 7, 46, 41, 79, 34, 24, 46, 81, 13, 13, 34, 16,
  50, 78, 19, 27, 2, 0, 15, 0, 63, 50, 63, 225, 63, 57, 47, 225, 50, 16, 225,
  17, 57, 47, 225, 18, 57, 57, 1, 47, 43, 93, 225, 51, 47, 93, 193, 17, 51, 47,
  193, 16, 222, 93, 50, 225, 18, 23, 57, 51, 47, 193, 49, 48, 1, 21, 7, 22, 21,
  20, 6, 35, 34, 39, 6, 21, 20, 51, 51, 50, 22, 21, 16, 33, 34, 38, 53, 52, 55,
  38, 53, 52, 55, 38, 38, 53, 52, 54, 51, 50, 23, 3, 50, 53, 52, 35, 34, 21, 20,
  1, 35, 34, 21, 20, 33, 32, 53, 52, 38, 4, 102, 196, 65, 213, 190, 55, 31, 100,
  161, 187, 174, 184, 253, 203, 218, 227, 240, 96, 133, 89, 102, 213, 197, 86,
  64, 154, 223, 225, 225, 1, 69, 188, 230, 1, 15, 1, 139, 100, 4, 74, 113, 27,
  85, 128, 161, 191, 6, 56, 77, 84, 154, 143, 254, 135, 161, 145, 212, 58, 47,
  107, 112, 80, 37, 171, 101, 182, 197, 20, 253, 188, 230, 239, 242, 227, 254,
  12, 198, 174, 223, 88, 61, 0, 0, 1, 0, 160, 0, 0, 4, 45, 6, 20, 0, 17, 0, 60,
  64, 38, 36, 15, 52, 15, 2, 0, 71, 176, 17, 192, 17, 2, 17, 19, 10, 6, 71, 0,
  7, 16, 7, 32, 7, 208, 7, 4, 7, 7, 4, 3, 80, 14, 16, 8, 0, 7, 0, 21, 0, 63, 50,
  63, 63, 225, 50, 1, 47, 94, 93, 225, 50, 16, 222, 93, 225, 49, 48, 93, 33, 17,
  16, 35, 32, 17, 17, 35, 17, 51, 17, 7, 51, 54, 51, 32, 17, 17, 3, 119, 238,
  254, 205, 182, 182, 8, 10, 103, 233, 1, 133, 2, 195, 1, 4, 254, 114, 253, 199,
  6, 20, 254, 50, 144, 168, 254, 111, 253, 51, 0, 0, 2, 0, 197, 0, 0, 4, 51, 6,
  14, 0, 8, 0, 18, 0, 51, 64, 28, 14, 2, 13, 71, 7, 10, 17, 3, 86, 18, 1, 18,
  18, 20, 19, 13, 18, 78, 16, 21, 9, 78, 11, 15, 5, 83, 0, 0, 0, 63, 237, 63,
  225, 63, 225, 50, 17, 18, 1, 57, 47, 93, 23, 51, 225, 50, 50, 49, 48, 1, 50,
  21, 20, 6, 35, 34, 53, 52, 19, 37, 53, 33, 17, 5, 21, 33, 53, 37, 2, 121, 106,
  63, 43, 107, 15, 254, 243, 1, 195, 1, 96, 252, 146, 1, 88, 6, 14, 114, 58, 57,
  115, 114, 253, 172, 21, 123, 252, 69, 20, 123, 123, 20, 0, 2, 0, 135, 254, 20,
  3, 86, 6, 14, 0, 7, 0, 23, 0, 57, 64, 32, 16, 8, 6, 14, 71, 2, 144, 19, 160,
  19, 2, 19, 19, 25, 24, 0, 8, 1, 8, 11, 80, 9, 22, 27, 15, 78, 18, 15, 4, 83,
  0, 0, 0, 63, 229, 63, 225, 63, 51, 225, 1, 47, 93, 17, 18, 57, 47, 93, 51,
  225, 50, 17, 57, 49, 48, 1, 50, 21, 20, 35, 34, 53, 52, 1, 53, 22, 51, 50, 54,
  53, 17, 37, 53, 33, 17, 20, 6, 35, 34, 2, 231, 107, 107, 106, 254, 10, 134,
  155, 117, 131, 254, 92, 2, 90, 226, 206, 164, 6, 14, 114, 115, 115, 114, 248,
  41, 154, 39, 114, 101, 4, 57, 21, 123, 251, 65, 180, 195, 0, 0, 1, 0, 215, 0,
  0, 4, 139, 6, 20, 0, 14, 0, 118, 64, 11, 25, 6, 41, 6, 57, 6, 3, 8, 6, 1, 4,
  184, 255, 224, 64, 62, 16, 20, 72, 70, 4, 86, 4, 2, 9, 2, 1, 9, 1, 1, 27, 7,
  43, 7, 59, 7, 3, 4, 7, 2, 3, 3, 6, 5, 32, 16, 19, 72, 0, 5, 96, 5, 2, 5, 5,
  16, 12, 0, 9, 71, 0, 10, 96, 10, 2, 10, 11, 0, 4, 7, 0, 7, 2, 10, 5, 21, 2,
  15, 0, 63, 63, 51, 18, 57, 57, 17, 51, 63, 1, 47, 93, 225, 50, 50, 17, 51, 47,
  93, 43, 51, 51, 47, 51, 57, 57, 49, 48, 0, 93, 1, 93, 93, 93, 43, 93, 93, 1,
  55, 1, 51, 1, 1, 35, 1, 7, 17, 35, 17, 51, 17, 3, 1, 127, 135, 1, 139, 222,
  254, 18, 2, 10, 213, 254, 86, 129, 180, 180, 16, 2, 41, 152, 1, 137, 254, 37,
  253, 145, 1, 248, 82, 254, 90, 6, 20, 253, 54, 254, 223, 0, 1, 0, 188, 0, 0,
  4, 43, 6, 20, 0, 9, 0, 45, 64, 24, 5, 4, 71, 8, 1, 93, 9, 1, 79, 9, 1, 9, 9,
  11, 10, 9, 4, 78, 6, 21, 0, 78, 2, 0, 0, 63, 225, 63, 225, 50, 17, 18, 1, 57,
  47, 93, 93, 51, 51, 225, 50, 49, 48, 1, 37, 53, 33, 17, 5, 21, 33, 53, 37, 2,
  20, 254, 244, 1, 195, 1, 96, 252, 145, 1, 88, 5, 133, 21, 122, 250, 123, 20,
  123, 123, 20, 0, 0, 1, 0, 92, 0, 0, 4, 115, 4, 94, 0, 32, 0, 107, 64, 69, 25,
  133, 8, 1, 118, 8, 1, 101, 8, 1, 86, 8, 1, 55, 8, 71, 8, 2, 8, 71, 139, 9, 1,
  122, 9, 1, 9, 9, 17, 0, 71, 144, 32, 160, 32, 192, 32, 208, 32, 4, 15, 32, 1,
  32, 34, 20, 16, 71, 64, 17, 80, 17, 2, 17, 26, 20, 17, 4, 12, 80, 28, 23, 16,
  18, 15, 17, 9, 0, 21, 0, 63, 50, 50, 63, 63, 51, 225, 50, 18, 57, 57, 1, 47,
  93, 225, 50, 16, 222, 93, 93, 225, 17, 57, 47, 93, 93, 225, 93, 93, 93, 93,
  93, 50, 49, 48, 33, 17, 52, 38, 35, 34, 6, 21, 17, 35, 17, 16, 35, 34, 6, 21,
  17, 35, 17, 51, 23, 51, 54, 51, 50, 23, 51, 54, 51, 50, 22, 21, 17, 3, 209,
  53, 62, 87, 79, 161, 125, 84, 72, 162, 127, 27, 10, 67, 134, 163, 50, 6, 76,
  143, 128, 116, 2, 195, 146, 114, 166, 195, 253, 162, 2, 195, 1, 4, 159, 239,
  253, 199, 4, 74, 148, 168, 182, 182, 185, 216, 253, 51, 0, 0, 1, 0, 160, 0, 0,
  4, 45, 4, 94, 0, 16, 0, 54, 64, 33, 0, 71, 176, 16, 192, 16, 2, 16, 18, 10, 6,
  71, 0, 7, 16, 7, 32, 7, 208, 7, 4, 7, 7, 11, 3, 80, 13, 16, 8, 15, 7, 0, 21,
  0, 63, 50, 63, 63, 225, 50, 1, 47, 94, 93, 225, 50, 16, 222, 93, 225, 49, 48,
  33, 17, 16, 35, 32, 17, 17, 35, 17, 51, 23, 51, 54, 51, 32, 17, 17, 3, 119,
  238, 254, 205, 182, 147, 27, 10, 103, 233, 1, 133, 2, 195, 1, 4, 254, 114,
  253, 199, 4, 74, 148, 168, 254, 111, 253, 51, 0, 2, 0, 115, 255, 236, 4, 88,
  4, 94, 0, 11, 0, 19, 0, 34, 64, 18, 14, 72, 9, 21, 18, 72, 0, 3, 1, 3, 16, 80,
  6, 16, 12, 80, 0, 22, 0, 63, 225, 63, 225, 1, 47, 93, 225, 16, 222, 225, 49,
  48, 5, 34, 0, 17, 16, 0, 51, 50, 0, 17, 16, 0, 39, 32, 17, 16, 33, 32, 17, 16,
  2, 98, 216, 254, 233, 1, 15, 230, 218, 1, 22, 254, 238, 224, 1, 54, 254, 200,
  254, 203, 20, 1, 55, 1, 4, 1, 7, 1, 48, 254, 202, 254, 255, 254, 247, 254,
  206, 151, 1, 164, 1, 160, 254, 96, 254, 92, 0, 2, 0, 158, 254, 20, 4, 68, 4,
  94, 0, 18, 0, 29, 0, 62, 64, 38, 25, 72, 15, 14, 31, 14, 2, 14, 31, 20, 1, 4,
  71, 0, 5, 16, 5, 32, 5, 208, 5, 4, 7, 5, 0, 23, 80, 17, 22, 8, 27, 80, 11, 16,
  6, 15, 4, 27, 0, 63, 63, 63, 225, 50, 63, 225, 50, 1, 47, 94, 93, 225, 50, 50,
  16, 222, 113, 225, 49, 48, 37, 35, 22, 21, 17, 35, 17, 51, 23, 51, 54, 51, 50,
  18, 17, 16, 2, 35, 34, 3, 21, 20, 22, 51, 32, 17, 16, 33, 34, 6, 1, 84, 12,
  12, 182, 147, 27, 8, 110, 212, 201, 229, 230, 200, 207, 115, 139, 152, 1, 16,
  254, 238, 152, 133, 139, 129, 33, 254, 43, 6, 54, 148, 168, 254, 213, 254,
  244, 254, 242, 254, 211, 2, 100, 41, 227, 193, 1, 166, 1, 158, 176, 0, 0, 2,
  0, 137, 254, 20, 4, 47, 4, 94, 0, 18, 0, 29, 0, 60, 64, 37, 1, 8, 19, 3, 5,
  71, 144, 4, 160, 4, 2, 4, 31, 25, 72, 0, 14, 224, 14, 240, 14, 3, 14, 8, 27,
  80, 11, 22, 4, 27, 1, 23, 80, 17, 16, 2, 15, 0, 63, 63, 225, 50, 63, 63, 225,
  50, 1, 47, 93, 225, 16, 222, 93, 225, 23, 50, 49, 48, 1, 51, 55, 51, 17, 35,
  17, 52, 55, 35, 6, 35, 34, 2, 17, 16, 18, 51, 50, 19, 53, 52, 38, 35, 32, 17,
  16, 33, 50, 54, 3, 121, 8, 27, 147, 182, 12, 12, 113, 209, 201, 229, 230, 200,
  207, 115, 139, 152, 254, 240, 1, 18, 152, 133, 3, 182, 148, 249, 202, 1, 213,
  41, 129, 167, 1, 43, 1, 12, 1, 14, 1, 45, 253, 156, 41, 227, 193, 254, 90,
  254, 98, 177, 0, 1, 1, 8, 0, 0, 4, 35, 4, 94, 0, 16, 0, 49, 64, 27, 144, 0, 1,
  0, 0, 18, 11, 7, 71, 47, 8, 1, 0, 8, 1, 8, 11, 7, 3, 81, 1, 15, 16, 9, 15, 7,
  21, 0, 63, 63, 63, 51, 225, 18, 57, 1, 47, 93, 93, 225, 50, 17, 51, 47, 93,
  49, 48, 1, 7, 38, 35, 34, 6, 21, 17, 35, 17, 51, 23, 51, 54, 54, 51, 50, 4,
  35, 49, 123, 101, 163, 177, 182, 148, 22, 8, 76, 174, 127, 118, 4, 49, 166,
  45, 185, 175, 253, 176, 4, 74, 201, 119, 102, 0, 1, 0, 203, 255, 236, 4, 2, 4,
  94, 0, 31, 0, 60, 64, 34, 16, 16, 5, 70, 27, 33, 21, 70, 11, 0, 0, 0, 11, 80,
  11, 96, 11, 240, 11, 4, 11, 21, 5, 14, 3, 80, 1, 30, 22, 19, 80, 17, 14, 16,
  0, 63, 51, 225, 63, 51, 225, 18, 57, 57, 1, 47, 93, 51, 47, 16, 225, 16, 222,
  225, 51, 47, 49, 48, 55, 53, 22, 51, 32, 53, 52, 38, 39, 38, 38, 53, 52, 54,
  51, 50, 23, 7, 38, 35, 34, 21, 20, 22, 23, 22, 22, 21, 20, 6, 35, 34, 203,
  193, 177, 1, 19, 98, 177, 233, 121, 223, 197, 198, 171, 60, 182, 137, 236,
  101, 182, 211, 139, 234, 214, 248, 49, 166, 86, 162, 57, 84, 64, 87, 145, 99,
  136, 155, 74, 149, 72, 133, 61, 73, 65, 77, 149, 108, 150, 171, 0, 1, 0, 139,
  255, 236, 4, 2, 5, 111, 0, 19, 0, 89, 64, 55, 12, 16, 71, 5, 9, 5, 32, 7, 1,
  7, 7, 47, 5, 63, 5, 127, 5, 143, 5, 207, 5, 223, 5, 6, 0, 5, 1, 5, 5, 20, 21,
  14, 14, 127, 1, 143, 1, 175, 1, 3, 1, 21, 6, 15, 78, 11, 9, 8, 12, 15, 18, 80,
  0, 3, 22, 0, 63, 51, 225, 63, 51, 51, 51, 225, 50, 1, 16, 206, 93, 50, 47, 17,
  18, 57, 47, 93, 93, 51, 47, 93, 17, 51, 16, 225, 50, 49, 48, 37, 21, 6, 35,
  32, 17, 17, 33, 53, 37, 19, 51, 17, 33, 21, 33, 17, 20, 51, 50, 3, 252, 130,
  122, 254, 150, 254, 245, 1, 11, 77, 105, 1, 182, 254, 74, 192, 93, 150, 138,
  32, 1, 88, 2, 125, 94, 49, 1, 31, 254, 219, 137, 253, 131, 195, 0, 1, 0, 160,
  255, 236, 4, 45, 4, 74, 0, 17, 0, 48, 64, 28, 1, 14, 71, 144, 17, 160, 17, 2,
  17, 19, 9, 71, 0, 6, 176, 6, 2, 6, 15, 7, 15, 1, 11, 80, 4, 22, 0, 21, 0, 63,
  63, 225, 50, 63, 51, 1, 47, 93, 225, 16, 222, 93, 225, 50, 49, 48, 33, 39, 35,
  6, 35, 32, 17, 17, 51, 17, 16, 51, 50, 54, 53, 17, 51, 17, 3, 154, 27, 10,
  105, 229, 254, 121, 182, 236, 161, 148, 182, 147, 167, 1, 145, 2, 205, 253,
  61, 254, 252, 185, 212, 2, 58, 251, 182, 0, 0, 1, 0, 82, 0, 0, 4, 121, 4, 74,
  0, 11, 0, 115, 64, 56, 38, 11, 1, 41, 0, 1, 55, 11, 103, 11, 231, 11, 247, 11,
  4, 6, 11, 22, 11, 2, 11, 56, 0, 104, 0, 232, 0, 248, 0, 4, 9, 0, 25, 0, 2, 0,
  5, 5, 1, 9, 8, 9, 12, 72, 9, 16, 10, 32, 10, 48, 10, 3, 10, 10, 13, 2, 184,
  255, 248, 64, 21, 9, 12, 72, 2, 47, 1, 63, 1, 2, 1, 70, 5, 86, 5, 2, 5, 9, 1,
  15, 0, 21, 0, 63, 63, 51, 57, 93, 1, 47, 93, 51, 43, 17, 51, 47, 93, 51, 43,
  18, 57, 61, 47, 51, 93, 93, 51, 93, 93, 49, 48, 93, 93, 33, 1, 51, 19, 22, 23,
  51, 54, 19, 19, 51, 1, 1, 242, 254, 96, 188, 240, 85, 15, 6, 7, 94, 239, 189,
  254, 96, 4, 74, 253, 116, 231, 94, 44, 1, 25, 2, 140, 251, 182, 0, 0, 1, 255,
  252, 0, 0, 4, 209, 4, 74, 0, 25, 1, 43, 185, 0, 25, 255, 240, 182, 20, 24, 72,
  167, 25, 1, 25, 184, 255, 240, 64, 24, 13, 18, 72, 9, 22, 25, 22, 41, 22, 3,
  41, 21, 1, 39, 17, 87, 17, 2, 6, 17, 22, 17, 2, 16, 184, 255, 240, 64, 66, 13,
  24, 72, 39, 16, 55, 16, 2, 15, 16, 13, 24, 72, 40, 15, 56, 15, 2, 40, 14, 88,
  14, 2, 9, 14, 25, 14, 2, 40, 13, 1, 38, 10, 1, 6, 9, 22, 9, 38, 9, 3, 6, 16,
  20, 24, 72, 168, 6, 1, 121, 6, 137, 6, 153, 6, 3, 40, 6, 72, 6, 88, 6, 104, 6,
  4, 5, 184, 255, 240, 64, 10, 20, 24, 72, 167, 5, 1, 38, 5, 1, 5, 184, 255,
  240, 64, 42, 13, 18, 72, 7, 5, 1, 0, 16, 20, 24, 72, 168, 0, 1, 41, 0, 1, 0,
  16, 13, 18, 72, 8, 0, 1, 6, 5, 11, 16, 15, 2, 25, 0, 20, 148, 11, 164, 11,
  180, 11, 3, 11, 184, 255, 224, 64, 48, 11, 14, 72, 155, 20, 171, 20, 187, 20,
  3, 20, 32, 11, 14, 72, 11, 2, 20, 20, 2, 11, 3, 7, 23, 16, 24, 1, 24, 8, 7,
  20, 11, 91, 2, 1, 84, 11, 1, 2, 11, 6, 23, 15, 7, 15, 0, 6, 21, 0, 63, 51, 63,
  51, 51, 18, 57, 57, 93, 93, 17, 51, 1, 47, 51, 47, 93, 51, 18, 23, 57, 61, 47,
  47, 47, 43, 93, 43, 93, 17, 51, 51, 17, 51, 51, 17, 51, 51, 49, 48, 93, 43,
  93, 93, 43, 93, 43, 93, 93, 43, 93, 93, 93, 43, 93, 93, 93, 93, 93, 93, 43,
  93, 43, 93, 93, 93, 93, 43, 93, 43, 33, 3, 3, 35, 3, 3, 35, 3, 51, 19, 22, 23,
  51, 54, 55, 19, 51, 19, 22, 23, 51, 54, 55, 19, 51, 3, 3, 45, 131, 68, 6, 65,
  135, 189, 223, 162, 98, 34, 23, 6, 31, 37, 133, 193, 127, 43, 24, 6, 31, 29,
  102, 158, 225, 2, 84, 1, 74, 254, 178, 253, 176, 4, 74, 253, 225, 186, 207,
  185, 173, 2, 66, 253, 190, 195, 163, 242, 151, 2, 31, 251, 182, 0, 1, 0, 96,
  0, 0, 4, 106, 4, 74, 0, 11, 0, 169, 183, 196, 10, 212, 10, 228, 10, 3, 10,
  184, 255, 240, 64, 36, 11, 14, 72, 203, 8, 219, 8, 235, 8, 3, 8, 16, 11, 14,
  72, 203, 4, 219, 4, 235, 4, 3, 4, 16, 11, 14, 72, 196, 2, 212, 2, 228, 2, 3,
  6, 2, 184, 255, 240, 64, 20, 11, 14, 72, 73, 9, 1, 9, 16, 18, 23, 72, 10, 9,
  26, 9, 2, 70, 3, 1, 3, 184, 255, 240, 64, 45, 18, 23, 72, 5, 3, 21, 3, 2, 4,
  5, 5, 6, 3, 9, 0, 4, 11, 8, 0, 7, 16, 7, 2, 7, 7, 13, 2, 1, 10, 31, 11, 1, 11,
  9, 6, 0, 3, 4, 1, 11, 7, 21, 4, 1, 15, 0, 63, 51, 63, 51, 18, 23, 57, 1, 47,
  93, 51, 51, 50, 17, 51, 47, 93, 51, 18, 23, 57, 51, 17, 51, 49, 48, 0, 93, 43,
  93, 93, 43, 93, 1, 43, 95, 93, 43, 93, 43, 93, 43, 93, 1, 1, 51, 1, 1, 51, 1,
  1, 35, 1, 1, 35, 1, 254, 254, 119, 207, 1, 34, 1, 35, 207, 254, 117, 1, 157,
  206, 254, 202, 254, 201, 207, 2, 51, 2, 23, 254, 102, 1, 154, 253, 233, 253,
  205, 1, 180, 254, 76, 0, 0, 1, 0, 82, 254, 20, 4, 121, 4, 74, 0, 22, 0, 113,
  64, 30, 56, 8, 1, 9, 8, 25, 8, 41, 8, 3, 55, 1, 1, 6, 1, 22, 1, 38, 1, 3, 22,
  16, 9, 12, 72, 22, 4, 4, 8, 9, 184, 255, 192, 64, 18, 9, 12, 72, 9, 9, 24, 15,
  15, 1, 31, 0, 47, 0, 63, 0, 3, 0, 4, 184, 255, 240, 64, 20, 11, 14, 72, 4, 4,
  20, 4, 2, 4, 0, 22, 22, 18, 80, 16, 13, 27, 8, 0, 15, 0, 63, 50, 63, 51, 225,
  63, 18, 57, 93, 43, 1, 47, 93, 50, 50, 47, 17, 51, 47, 43, 51, 57, 61, 47, 51,
  43, 49, 48, 93, 93, 93, 93, 19, 51, 1, 22, 23, 51, 54, 55, 19, 51, 1, 6, 6,
  35, 34, 39, 53, 22, 51, 50, 54, 55, 55, 82, 188, 1, 6, 82, 7, 6, 23, 67, 239,
  189, 254, 37, 67, 178, 157, 86, 82, 62, 74, 96, 107, 42, 58, 4, 74, 253, 114,
  205, 85, 112, 180, 2, 140, 251, 39, 174, 175, 17, 145, 12, 82, 100, 150, 0, 1,
  0, 182, 0, 0, 4, 20, 4, 74, 0, 9, 0, 70, 64, 14, 3, 8, 9, 12, 72, 3, 7, 7,
  112, 0, 1, 0, 11, 8, 184, 255, 248, 64, 24, 9, 12, 72, 8, 2, 4, 4, 127, 2, 1,
  0, 2, 1, 2, 7, 4, 78, 5, 15, 2, 8, 78, 1, 21, 0, 63, 225, 50, 63, 225, 50, 1,
  47, 93, 93, 51, 47, 17, 51, 43, 16, 206, 93, 50, 47, 51, 43, 49, 48, 33, 33,
  53, 1, 33, 53, 33, 21, 1, 33, 4, 20, 252, 162, 2, 148, 253, 141, 3, 43, 253,
  121, 2, 153, 125, 3, 68, 137, 146, 252, 209, 0, 0, 1, 0, 225, 254, 188, 3,
  233, 5, 182, 0, 25, 0, 98, 64, 63, 20, 0, 241, 12, 22, 9, 112, 6, 128, 6, 2,
  6, 6, 9, 16, 95, 3, 1, 64, 3, 1, 3, 27, 224, 9, 240, 9, 2, 31, 9, 1, 9, 22, 9,
  245, 239, 10, 255, 10, 2, 217, 10, 1, 15, 10, 47, 10, 175, 10, 191, 10, 4, 10,
  10, 3, 16, 245, 15, 248, 3, 245, 4, 249, 0, 63, 225, 63, 225, 18, 57, 47, 93,
  93, 93, 225, 57, 1, 47, 93, 93, 16, 206, 93, 93, 50, 17, 57, 47, 93, 18, 57,
  51, 225, 50, 49, 48, 5, 20, 22, 23, 21, 36, 17, 17, 52, 33, 53, 32, 53, 17,
  16, 37, 21, 6, 6, 21, 17, 20, 7, 21, 22, 21, 2, 233, 112, 144, 254, 74, 254,
  174, 1, 82, 1, 182, 144, 112, 233, 233, 16, 81, 75, 2, 150, 6, 1, 31, 1, 78,
  189, 155, 189, 1, 77, 1, 31, 6, 149, 2, 75, 81, 254, 180, 207, 41, 12, 41,
  207, 0, 0, 1, 2, 27, 254, 20, 2, 176, 6, 20, 0, 3, 0, 21, 64, 10, 2, 170, 79,
  3, 1, 3, 2, 27, 0, 0, 0, 63, 63, 1, 47, 93, 225, 49, 48, 1, 51, 17, 35, 2, 27,
  149, 149, 6, 20, 248, 0, 0, 0, 1, 0, 227, 254, 188, 3, 236, 5, 182, 0, 25, 0,
  96, 64, 62, 5, 25, 241, 13, 3, 127, 19, 143, 19, 2, 19, 19, 9, 239, 15, 255,
  15, 2, 16, 15, 1, 15, 27, 21, 80, 9, 1, 79, 9, 1, 9, 3, 16, 245, 239, 15, 255,
  15, 2, 217, 15, 1, 15, 15, 47, 15, 175, 15, 191, 15, 4, 15, 15, 10, 22, 245,
  21, 249, 9, 245, 10, 248, 0, 63, 225, 63, 225, 17, 57, 47, 93, 93, 93, 225,
  57, 1, 47, 93, 93, 51, 16, 206, 93, 93, 17, 57, 47, 93, 57, 51, 225, 50, 49,
  48, 1, 52, 55, 53, 38, 53, 17, 52, 38, 39, 53, 4, 17, 17, 20, 33, 21, 32, 21,
  17, 16, 5, 53, 54, 54, 53, 1, 227, 234, 234, 113, 143, 1, 183, 1, 82, 254,
  174, 254, 73, 143, 113, 1, 59, 207, 41, 12, 41, 207, 1, 76, 81, 76, 1, 149, 6,
  254, 225, 254, 179, 189, 155, 189, 254, 178, 254, 225, 6, 150, 1, 76, 81, 0,
  1, 0, 152, 2, 74, 4, 51, 3, 90, 0, 17, 0, 47, 64, 26, 9, 19, 0, 0, 1, 0, 0,
  18, 16, 173, 9, 3, 178, 7, 173, 0, 223, 12, 1, 112, 12, 1, 63, 12, 1, 12, 0,
  47, 93, 93, 93, 51, 225, 253, 50, 225, 17, 1, 51, 47, 93, 16, 206, 49, 48, 19,
  53, 54, 51, 50, 23, 22, 51, 50, 55, 21, 6, 35, 34, 39, 38, 35, 34, 152, 99,
  148, 100, 148, 130, 71, 108, 119, 99, 149, 100, 147, 131, 70, 108, 2, 74, 162,
  108, 63, 56, 121, 162, 108, 63, 56, 0, 2, 1, 231, 254, 139, 2, 229, 4, 94, 0,
  7, 0, 11, 0, 37, 64, 17, 8, 9, 10, 6, 150, 11, 2, 2, 12, 13, 8, 8, 10, 0, 155,
  4, 16, 0, 63, 237, 47, 57, 47, 17, 18, 1, 57, 47, 51, 225, 50, 57, 57, 49, 48,
  1, 34, 53, 52, 51, 50, 21, 20, 7, 51, 19, 35, 2, 102, 127, 127, 127, 188, 121,
  51, 223, 3, 72, 139, 139, 139, 139, 164, 251, 231, 0, 0, 1, 0, 172, 255, 236,
  4, 37, 5, 203, 0, 23, 0, 78, 64, 24, 0, 14, 70, 21, 32, 17, 48, 17, 2, 17, 17,
  19, 2, 143, 12, 1, 12, 25, 7, 72, 0, 19, 1, 19, 184, 255, 192, 64, 18, 21, 24,
  72, 19, 5, 80, 0, 21, 21, 22, 7, 17, 9, 81, 14, 14, 15, 22, 0, 63, 51, 47,
  225, 51, 63, 51, 47, 51, 225, 1, 47, 43, 93, 225, 16, 206, 93, 50, 17, 57, 47,
  93, 51, 225, 50, 49, 48, 1, 22, 23, 7, 38, 35, 32, 17, 16, 33, 50, 55, 21, 6,
  7, 21, 35, 53, 36, 17, 16, 37, 53, 51, 2, 231, 162, 156, 62, 150, 118, 254,
  141, 1, 105, 153, 168, 122, 177, 137, 254, 78, 1, 178, 137, 5, 39, 3, 56, 158,
  57, 254, 98, 254, 107, 61, 159, 59, 3, 200, 206, 69, 1, 232, 1, 238, 74, 172,
  0, 1, 0, 119, 0, 0, 4, 86, 5, 201, 0, 27, 0, 82, 64, 49, 6, 10, 111, 22, 18,
  8, 18, 8, 15, 0, 13, 29, 20, 0, 15, 1, 15, 9, 20, 117, 6, 47, 21, 95, 21, 127,
  21, 143, 21, 175, 21, 191, 21, 223, 21, 7, 21, 21, 12, 3, 115, 1, 26, 7, 16,
  12, 116, 15, 24, 0, 63, 225, 50, 63, 51, 225, 18, 57, 47, 93, 51, 225, 50, 1,
  47, 93, 51, 16, 206, 50, 17, 57, 57, 47, 47, 51, 225, 50, 49, 48, 1, 7, 38,
  35, 34, 21, 17, 33, 21, 33, 21, 20, 7, 33, 21, 33, 53, 54, 53, 53, 35, 53, 51,
  17, 52, 54, 51, 50, 4, 39, 66, 141, 131, 223, 1, 121, 254, 135, 140, 2, 236,
  252, 33, 200, 198, 198, 217, 181, 192, 5, 121, 144, 72, 246, 254, 217, 137,
  211, 196, 78, 166, 154, 49, 235, 213, 137, 1, 68, 168, 201, 0, 2, 0, 174, 1,
  29, 4, 31, 4, 139, 0, 27, 0, 39, 0, 94, 64, 10, 37, 171, 0, 26, 176, 26, 224,
  26, 3, 26, 184, 255, 192, 64, 29, 11, 15, 72, 26, 26, 31, 171, 192, 12, 1, 79,
  12, 95, 12, 111, 12, 3, 12, 41, 28, 174, 0, 19, 176, 19, 224, 19, 3, 19, 184,
  255, 192, 64, 21, 11, 15, 72, 19, 19, 34, 174, 31, 5, 63, 5, 79, 5, 111, 5,
  191, 5, 239, 5, 6, 5, 0, 47, 93, 225, 51, 47, 43, 93, 225, 1, 16, 222, 93, 93,
  225, 51, 47, 43, 93, 225, 49, 48, 1, 39, 55, 23, 54, 51, 50, 23, 55, 23, 7,
  22, 21, 20, 7, 23, 7, 39, 6, 35, 34, 39, 7, 39, 55, 38, 53, 52, 1, 50, 54, 53,
  52, 38, 35, 34, 6, 21, 20, 22, 1, 47, 129, 98, 127, 101, 114, 114, 99, 129,
  99, 129, 67, 67, 127, 97, 129, 99, 114, 118, 97, 127, 96, 127, 65, 1, 120,
  100, 144, 143, 101, 99, 140, 141, 3, 168, 129, 98, 129, 68, 68, 129, 96, 129,
  101, 114, 120, 95, 127, 96, 127, 66, 68, 127, 96, 127, 95, 118, 114, 254, 158,
  140, 100, 101, 143, 142, 102, 100, 140, 0, 0, 1, 0, 78, 0, 0, 4, 125, 5, 182,
  0, 22, 0, 189, 185, 0, 22, 255, 248, 64, 9, 10, 13, 72, 1, 8, 10, 13, 72, 0,
  184, 255, 232, 64, 60, 21, 24, 72, 102, 0, 118, 0, 2, 18, 14, 18, 14, 12, 22,
  207, 21, 1, 139, 21, 1, 116, 21, 1, 21, 21, 12, 5, 9, 5, 9, 1, 2, 2, 103, 0,
  1, 0, 7, 3, 11, 110, 20, 16, 192, 12, 208, 12, 2, 103, 12, 1, 16, 12, 1, 12,
  12, 23, 24, 7, 15, 184, 1, 7, 180, 14, 10, 14, 6, 18, 184, 1, 7, 64, 29, 19,
  3, 0, 19, 159, 14, 1, 48, 14, 64, 14, 2, 15, 19, 31, 19, 159, 19, 3, 14, 19,
  14, 19, 1, 11, 18, 22, 1, 6, 0, 63, 51, 63, 18, 57, 57, 47, 47, 93, 93, 93,
  17, 51, 51, 16, 225, 50, 17, 51, 16, 225, 50, 17, 18, 1, 57, 47, 93, 93, 93,
  51, 51, 225, 50, 50, 57, 93, 50, 47, 51, 57, 57, 47, 47, 17, 51, 47, 93, 93,
  93, 51, 18, 57, 57, 47, 47, 49, 48, 0, 93, 43, 1, 43, 43, 1, 1, 51, 1, 51, 21,
  33, 21, 33, 21, 33, 17, 35, 17, 33, 53, 33, 53, 33, 53, 51, 1, 51, 2, 100, 1,
  90, 191, 254, 127, 240, 254, 210, 1, 46, 254, 210, 178, 254, 211, 1, 45, 254,
  211, 234, 254, 133, 192, 2, 211, 2, 227, 253, 0, 137, 158, 137, 254, 250, 1,
  6, 137, 158, 137, 3, 0, 0, 0, 2, 2, 27, 254, 20, 2, 176, 6, 20, 0, 3, 0, 7, 0,
  33, 64, 16, 2, 6, 170, 3, 79, 7, 1, 7, 4, 3, 4, 3, 6, 27, 0, 0, 0, 63, 63, 57,
  57, 47, 47, 1, 47, 93, 51, 225, 50, 49, 48, 1, 51, 17, 35, 17, 51, 17, 35, 2,
  27, 149, 149, 149, 149, 6, 20, 252, 244, 254, 25, 252, 243, 0, 0, 2, 0, 244,
  255, 246, 3, 217, 6, 31, 0, 39, 0, 50, 0, 125, 64, 43, 8, 0, 1, 6, 20, 1, 9,
  0, 1, 40, 20, 47, 22, 0, 45, 2, 72, 42, 1, 42, 73, 18, 18, 32, 70, 7, 22, 52,
  71, 47, 1, 47, 73, 38, 12, 70, 2, 2, 27, 0, 38, 1, 38, 184, 255, 192, 64, 26,
  12, 15, 72, 38, 38, 51, 20, 40, 0, 45, 12, 45, 40, 32, 4, 5, 30, 78, 28, 25,
  22, 10, 78, 8, 5, 1, 0, 63, 51, 225, 63, 51, 225, 17, 23, 57, 17, 51, 17, 51,
  17, 1, 51, 47, 43, 93, 51, 51, 47, 225, 16, 225, 93, 16, 222, 50, 225, 51, 47,
  225, 93, 17, 57, 57, 17, 18, 57, 57, 49, 48, 0, 93, 93, 1, 93, 1, 38, 53, 52,
  54, 51, 50, 23, 7, 38, 35, 34, 21, 20, 22, 23, 22, 22, 21, 20, 7, 22, 21, 20,
  6, 35, 34, 39, 53, 22, 51, 50, 53, 52, 38, 39, 38, 38, 53, 52, 1, 54, 53, 52,
  38, 39, 6, 21, 20, 22, 23, 1, 164, 160, 208, 173, 162, 164, 56, 156, 120, 201,
  99, 147, 157, 148, 145, 145, 221, 197, 204, 119, 171, 152, 240, 86, 152, 197,
  112, 1, 197, 114, 147, 133, 133, 113, 151, 4, 43, 80, 156, 120, 144, 72, 139,
  67, 116, 54, 78, 61, 62, 155, 113, 182, 88, 80, 145, 138, 161, 65, 158, 82,
  141, 57, 80, 62, 84, 150, 104, 179, 254, 97, 76, 109, 89, 111, 48, 48, 127,
  73, 107, 63, 0, 0, 2, 1, 74, 5, 12, 3, 129, 5, 217, 0, 7, 0, 15, 0, 55, 64,
  36, 2, 133, 0, 6, 112, 6, 224, 6, 3, 6, 6, 14, 133, 10, 10, 17, 8, 0, 147, 12,
  79, 4, 111, 4, 127, 4, 159, 4, 175, 4, 207, 4, 223, 4, 7, 4, 0, 47, 93, 51,
  237, 50, 17, 1, 51, 47, 225, 51, 47, 93, 225, 49, 48, 1, 50, 21, 20, 35, 34,
  53, 52, 33, 50, 21, 20, 35, 34, 53, 52, 1, 170, 96, 96, 96, 1, 215, 96, 96,
  96, 5, 217, 102, 103, 103, 102, 102, 103, 103, 102, 0, 0, 3, 0, 6, 255, 236,
  4, 199, 5, 203, 0, 11, 0, 23, 0, 44, 0, 111, 64, 70, 41, 197, 35, 25, 31, 30,
  47, 30, 63, 30, 3, 30, 25, 30, 25, 9, 15, 195, 3, 46, 21, 195, 9, 43, 201, 27,
  24, 27, 38, 201, 33, 36, 33, 111, 27, 127, 27, 143, 27, 3, 13, 27, 29, 27, 2,
  96, 33, 112, 33, 128, 33, 3, 2, 33, 18, 33, 2, 27, 33, 27, 33, 0, 12, 200, 6,
  19, 18, 200, 0, 4, 0, 63, 225, 63, 225, 17, 57, 57, 47, 47, 93, 93, 93, 93,
  17, 51, 16, 225, 17, 51, 16, 225, 1, 47, 225, 16, 214, 225, 17, 57, 57, 47,
  47, 93, 17, 51, 225, 49, 48, 1, 32, 0, 17, 16, 0, 33, 32, 0, 17, 16, 0, 1, 50,
  0, 17, 16, 0, 35, 34, 0, 17, 16, 0, 1, 21, 6, 35, 34, 38, 53, 52, 54, 51, 50,
  23, 7, 38, 35, 34, 6, 21, 16, 51, 50, 2, 102, 1, 30, 1, 67, 254, 188, 254,
  227, 254, 226, 254, 190, 1, 65, 1, 31, 240, 1, 4, 254, 252, 240, 240, 254,
  253, 1, 3, 1, 244, 107, 114, 195, 210, 220, 191, 128, 126, 61, 110, 83, 121,
  130, 251, 94, 5, 203, 254, 104, 254, 168, 254, 167, 254, 106, 1, 151, 1, 88,
  1, 87, 1, 153, 250, 141, 1, 85, 1, 46, 1, 46, 1, 85, 254, 170, 254, 211, 254,
  211, 254, 170, 1, 109, 131, 50, 247, 214, 209, 246, 62, 127, 54, 171, 151,
  254, 189, 0, 0, 2, 1, 20, 3, 16, 3, 141, 5, 199, 0, 20, 0, 30, 0, 71, 64, 37,
  30, 1, 9, 224, 192, 19, 1, 47, 19, 127, 19, 2, 19, 19, 24, 224, 15, 48, 5,
  160, 5, 2, 5, 30, 229, 9, 9, 26, 14, 12, 228, 17, 222, 1, 26, 228, 3, 184, 1,
  0, 177, 0, 255, 0, 63, 63, 225, 50, 63, 225, 51, 18, 57, 47, 225, 1, 47, 93,
  51, 225, 51, 47, 93, 93, 225, 50, 50, 49, 48, 1, 39, 6, 35, 34, 53, 52, 54,
  55, 55, 53, 52, 35, 34, 7, 39, 54, 51, 32, 21, 17, 3, 6, 6, 21, 20, 51, 50,
  54, 53, 53, 3, 31, 33, 104, 164, 222, 170, 191, 125, 152, 112, 133, 41, 138,
  156, 1, 35, 247, 114, 120, 104, 105, 125, 3, 29, 118, 131, 205, 116, 103, 6,
  5, 10, 133, 51, 110, 58, 238, 254, 68, 1, 63, 2, 52, 75, 90, 110, 91, 20, 0,
  0, 2, 0, 197, 0, 115, 4, 6, 3, 199, 0, 6, 0, 13, 0, 71, 64, 42, 10, 235, 7,
  236, 11, 143, 9, 1, 96, 9, 1, 9, 15, 3, 235, 0, 236, 64, 4, 0, 2, 48, 2, 96,
  2, 160, 2, 4, 2, 12, 5, 238, 8, 1, 238, 32, 0, 6, 10, 3, 3, 239, 0, 25, 63,
  23, 51, 26, 237, 50, 237, 50, 1, 24, 47, 93, 51, 26, 253, 225, 16, 222, 93,
  93, 50, 253, 225, 49, 48, 19, 1, 23, 3, 19, 7, 1, 37, 1, 23, 3, 19, 7, 1, 197,
  1, 53, 117, 238, 238, 117, 254, 203, 1, 151, 1, 53, 117, 237, 237, 117, 254,
  203, 2, 41, 1, 158, 78, 254, 164, 254, 164, 78, 1, 155, 27, 1, 158, 78, 254,
  164, 254, 164, 78, 1, 155, 0, 0, 1, 0, 152, 1, 6, 4, 51, 3, 29, 0, 5, 0, 44,
  183, 3, 170, 0, 7, 0, 5, 1, 5, 184, 255, 192, 64, 13, 21, 24, 72, 5, 5, 6, 3,
  173, 0, 1, 1, 0, 179, 0, 63, 50, 47, 16, 225, 17, 1, 51, 47, 43, 93, 16, 222,
  225, 49, 48, 1, 17, 35, 17, 33, 53, 4, 51, 149, 252, 250, 3, 29, 253, 233, 1,
  129, 150, 255, 255, 1, 29, 1, 209, 3, 176, 2, 121, 2, 6, 0, 16, 0, 0, 0, 4, 0,
  6, 255, 236, 4, 199, 5, 203, 0, 11, 0, 23, 0, 35, 0, 43, 0, 150, 64, 94, 24,
  34, 36, 29, 197, 30, 26, 25, 25, 39, 197, 34, 27, 34, 96, 30, 1, 96, 34, 1,
  27, 34, 1, 30, 34, 30, 34, 9, 15, 195, 3, 45, 21, 195, 9, 26, 30, 21, 36, 1,
  36, 201, 28, 24, 28, 43, 201, 31, 240, 30, 1, 111, 30, 127, 30, 143, 30, 3,
  13, 30, 29, 30, 2, 34, 28, 1, 96, 31, 112, 31, 128, 31, 3, 2, 31, 18, 31, 2,
  30, 28, 31, 31, 28, 30, 3, 0, 12, 200, 6, 19, 18, 200, 0, 4, 0, 63, 225, 63,
  225, 17, 23, 57, 47, 47, 47, 93, 93, 93, 93, 93, 93, 16, 225, 17, 51, 16, 225,
  93, 17, 51, 1, 47, 225, 16, 214, 225, 17, 57, 57, 47, 47, 93, 93, 93, 18, 57,
  16, 225, 51, 17, 51, 16, 225, 50, 17, 57, 49, 48, 1, 32, 0, 17, 16, 0, 33, 32,
  0, 17, 16, 0, 1, 50, 0, 17, 16, 0, 35, 34, 0, 17, 16, 0, 1, 19, 35, 3, 35, 17,
  35, 17, 51, 32, 17, 20, 37, 51, 50, 53, 52, 38, 35, 35, 2, 102, 1, 30, 1, 67,
  254, 188, 254, 227, 254, 226, 254, 190, 1, 65, 1, 31, 240, 1, 4, 254, 252,
  240, 240, 254, 253, 1, 3, 1, 118, 237, 178, 207, 94, 158, 234, 1, 69, 254,
  111, 72, 170, 84, 89, 69, 5, 203, 254, 104, 254, 168, 254, 167, 254, 106, 1,
  151, 1, 88, 1, 87, 1, 153, 250, 141, 1, 85, 1, 46, 1, 46, 1, 85, 254, 170,
  254, 211, 254, 211, 254, 170, 2, 80, 254, 117, 1, 96, 254, 160, 3, 125, 254,
  247, 163, 18, 141, 74, 59, 0, 0, 1, 255, 236, 6, 20, 4, 225, 6, 160, 0, 3, 0,
  15, 181, 1, 0, 3, 186, 0, 0, 0, 63, 225, 1, 47, 47, 49, 48, 1, 33, 53, 33, 4,
  225, 251, 11, 4, 245, 6, 20, 140, 0, 2, 1, 43, 3, 86, 3, 162, 5, 203, 0, 11,
  0, 23, 0, 137, 64, 26, 169, 10, 185, 10, 2, 10, 16, 9, 15, 72, 169, 8, 185, 8,
  2, 8, 16, 9, 15, 72, 166, 4, 182, 4, 2, 4, 184, 255, 240, 64, 9, 9, 15, 72,
  166, 2, 182, 2, 2, 2, 184, 255, 240, 64, 33, 9, 15, 72, 15, 171, 159, 3, 175,
  3, 255, 3, 3, 3, 25, 21, 171, 0, 9, 32, 9, 48, 9, 144, 9, 160, 9, 176, 9, 240,
  9, 7, 9, 12, 184, 1, 2, 64, 12, 0, 6, 16, 6, 32, 6, 224, 6, 240, 6, 5, 6, 184,
  255, 192, 180, 16, 21, 72, 6, 18, 184, 1, 2, 177, 0, 4, 0, 63, 225, 212, 43,
  93, 225, 1, 47, 93, 225, 16, 222, 93, 225, 49, 48, 43, 93, 43, 93, 43, 93, 43,
  93, 1, 50, 22, 21, 20, 6, 35, 34, 38, 53, 52, 54, 19, 50, 54, 53, 52, 38, 35,
  34, 6, 21, 20, 22, 2, 102, 129, 187, 186, 130, 131, 184, 185, 130, 79, 114,
  115, 78, 79, 113, 112, 5, 203, 187, 129, 129, 184, 185, 128, 129, 187, 254, 6,
  112, 78, 81, 114, 115, 80, 78, 112, 0, 2, 0, 152, 0, 0, 4, 51, 4, 162, 0, 11,
  0, 15, 0, 41, 64, 22, 14, 9, 6, 170, 13, 0, 192, 3, 208, 3, 2, 3, 13, 173, 12,
  24, 9, 0, 173, 6, 3, 179, 0, 63, 51, 225, 50, 63, 225, 1, 47, 93, 51, 51, 225,
  50, 50, 49, 48, 1, 33, 53, 33, 17, 51, 17, 33, 21, 33, 17, 35, 1, 53, 33, 21,
  2, 27, 254, 125, 1, 131, 149, 1, 131, 254, 125, 149, 254, 125, 3, 155, 2, 135,
  150, 1, 133, 254, 123, 150, 254, 127, 254, 250, 150, 150, 0, 0, 1, 1, 92, 2,
  160, 3, 111, 5, 197, 0, 21, 0, 77, 64, 51, 21, 21, 6, 224, 15, 16, 31, 16, 79,
  16, 95, 16, 127, 16, 143, 16, 159, 16, 7, 16, 16, 20, 11, 11, 0, 1, 96, 1,
  112, 1, 128, 1, 4, 1, 6, 1, 10, 16, 17, 24, 72, 10, 8, 228, 13, 222, 2, 20,
  228, 1, 221, 0, 63, 225, 50, 63, 225, 51, 43, 18, 57, 1, 47, 93, 50, 47, 50,
  50, 47, 93, 225, 51, 47, 49, 48, 1, 33, 53, 55, 54, 54, 53, 52, 35, 34, 7, 39,
  54, 51, 50, 22, 21, 20, 6, 7, 7, 33, 3, 111, 253, 237, 187, 111, 61, 111, 81,
  83, 78, 117, 131, 118, 130, 70, 129, 135, 1, 107, 2, 160, 102, 199, 118, 101,
  57, 115, 76, 86, 103, 120, 104, 66, 136, 129, 136, 0, 1, 1, 86, 2, 143, 3, 78,
  5, 197, 0, 30, 0, 132, 64, 79, 0, 16, 19, 224, 23, 29, 1, 29, 29, 2, 16, 16,
  7, 12, 224, 15, 2, 31, 2, 79, 2, 95, 2, 127, 2, 143, 2, 159, 2, 7, 2, 2, 7,
  24, 24, 0, 7, 96, 7, 112, 7, 3, 7, 0, 15, 229, 250, 16, 1, 233, 16, 1, 168,
  16, 1, 111, 16, 1, 11, 16, 27, 16, 2, 16, 16, 10, 23, 16, 17, 24, 72, 23, 21,
  228, 26, 222, 10, 228, 8, 184, 255, 240, 181, 17, 24, 72, 8, 5, 223, 0, 63,
  51, 43, 225, 63, 225, 51, 43, 18, 57, 47, 93, 93, 93, 93, 93, 225, 57, 1, 47,
  93, 51, 47, 17, 51, 47, 93, 225, 18, 57, 47, 17, 51, 47, 93, 225, 18, 57, 49,
  48, 1, 22, 21, 20, 6, 35, 34, 39, 53, 22, 51, 50, 53, 52, 35, 35, 53, 51, 50,
  53, 52, 35, 34, 7, 39, 54, 51, 50, 22, 21, 20, 2, 158, 176, 149, 140, 131, 84,
  110, 93, 149, 147, 72, 70, 123, 97, 71, 90, 66, 111, 127, 109, 128, 4, 61, 39,
  147, 116, 128, 50, 124, 65, 137, 125, 104, 127, 111, 70, 86, 93, 109, 94, 139,
  0, 0, 1, 1, 162, 4, 217, 3, 43, 6, 33, 0, 7, 0, 31, 64, 16, 6, 7, 134, 2, 135,
  3, 3, 9, 2, 146, 15, 6, 95, 6, 2, 6, 0, 47, 93, 237, 17, 1, 51, 47, 225, 237,
  50, 49, 48, 1, 54, 55, 51, 21, 6, 7, 35, 1, 162, 94, 80, 219, 112, 160, 121,
  4, 244, 133, 168, 21, 173, 134, 0, 1, 0, 180, 254, 20, 4, 25, 4, 74, 0, 21, 0,
  61, 64, 16, 10, 5, 71, 143, 8, 1, 8, 23, 15, 0, 18, 71, 0, 19, 1, 19, 184,
  255, 192, 64, 16, 17, 20, 72, 19, 18, 27, 10, 2, 80, 13, 22, 9, 21, 20, 6, 15,
  0, 63, 51, 63, 63, 225, 50, 63, 1, 47, 43, 93, 225, 50, 50, 16, 222, 93, 225,
  50, 49, 48, 1, 16, 51, 50, 54, 53, 17, 51, 17, 35, 39, 35, 6, 35, 34, 39, 22,
  21, 17, 35, 17, 51, 1, 106, 218, 148, 138, 183, 148, 27, 10, 96, 199, 139, 74,
  6, 182, 182, 1, 135, 254, 252, 182, 215, 2, 58, 251, 182, 147, 167, 88, 153,
  87, 254, 192, 6, 54, 0, 1, 0, 66, 254, 252, 4, 55, 6, 20, 0, 14, 0, 77, 183,
  4, 154, 96, 5, 240, 5, 2, 5, 184, 255, 192, 64, 37, 18, 22, 72, 34, 5, 50, 5,
  2, 4, 5, 20, 5, 2, 5, 5, 10, 1, 154, 0, 16, 10, 64, 10, 15, 72, 10, 10, 15, 8,
  8, 0, 2, 81, 14, 0, 5, 0, 0, 47, 50, 63, 225, 18, 57, 47, 17, 1, 51, 47, 43,
  16, 222, 225, 17, 57, 47, 93, 93, 43, 93, 225, 49, 48, 1, 35, 17, 35, 17, 35,
  17, 6, 35, 32, 17, 16, 54, 51, 33, 4, 55, 121, 206, 121, 61, 85, 254, 93, 217,
  233, 2, 51, 254, 252, 6, 121, 249, 135, 3, 51, 18, 1, 245, 1, 3, 255, 0, 0, 1,
  1, 231, 2, 72, 2, 229, 3, 94, 0, 7, 0, 34, 64, 20, 2, 150, 48, 6, 96, 6, 176,
  6, 224, 6, 240, 6, 5, 6, 6, 8, 9, 0, 155, 4, 0, 47, 237, 17, 18, 1, 57, 47,
  93, 237, 49, 48, 1, 50, 21, 20, 35, 34, 53, 52, 2, 102, 127, 127, 127, 3, 94,
  139, 139, 139, 139, 0, 0, 1, 1, 172, 254, 20, 3, 33, 0, 0, 0, 15, 0, 67, 185,
  0, 13, 255, 176, 64, 33, 11, 19, 72, 7, 48, 9, 14, 72, 8, 7, 9, 10, 7, 10, 0,
  5, 132, 12, 95, 0, 1, 0, 0, 12, 12, 17, 10, 7, 8, 3, 141, 14, 8, 0, 47, 47,
  225, 17, 57, 57, 17, 1, 51, 47, 51, 47, 93, 16, 225, 17, 57, 57, 17, 51, 17,
  51, 49, 48, 43, 43, 1, 53, 22, 51, 50, 53, 52, 39, 55, 51, 7, 22, 21, 20, 33,
  34, 1, 172, 33, 47, 151, 172, 91, 120, 57, 160, 254, 221, 34, 254, 29, 108, 6,
  92, 74, 39, 176, 115, 37, 135, 205, 0, 1, 1, 111, 2, 160, 2, 209, 5, 180, 0,
  10, 0, 33, 64, 15, 10, 10, 2, 224, 0, 3, 3, 11, 12, 2, 221, 6, 9, 0, 220, 0,
  63, 205, 57, 63, 17, 18, 1, 57, 47, 51, 225, 51, 47, 49, 48, 1, 51, 17, 35,
  17, 52, 55, 6, 7, 7, 39, 2, 74, 135, 146, 9, 41, 33, 70, 73, 5, 180, 252, 236,
  1, 209, 69, 131, 44, 21, 51, 88, 0, 0, 2, 1, 25, 3, 16, 3, 180, 5, 199, 0, 11,
  0, 19, 0, 48, 64, 27, 14, 224, 176, 9, 1, 127, 9, 1, 9, 9, 18, 224, 32, 3, 48,
  3, 160, 3, 3, 3, 16, 230, 6, 222, 12, 230, 0, 184, 1, 0, 0, 63, 225, 63, 225,
  1, 47, 93, 225, 51, 47, 93, 93, 225, 49, 48, 1, 34, 38, 53, 52, 54, 51, 50,
  22, 21, 20, 6, 39, 50, 53, 52, 35, 34, 21, 20, 2, 100, 144, 187, 180, 155,
  145, 187, 184, 150, 181, 181, 182, 3, 16, 186, 163, 162, 184, 185, 161, 165,
  184, 119, 230, 225, 225, 230, 0, 2, 0, 197, 0, 115, 4, 6, 3, 199, 0, 6, 0, 13,
  0, 71, 64, 42, 2, 4, 236, 3, 235, 63, 6, 143, 6, 159, 6, 175, 6, 4, 6, 15, 9,
  11, 236, 64, 10, 235, 159, 13, 1, 0, 13, 1, 13, 12, 5, 238, 8, 1, 238, 32, 0,
  6, 10, 3, 3, 239, 0, 25, 63, 23, 51, 26, 237, 50, 237, 50, 1, 24, 47, 93, 93,
  225, 26, 237, 50, 16, 222, 93, 225, 237, 50, 49, 48, 1, 1, 39, 19, 3, 55, 1,
  5, 1, 39, 19, 3, 55, 1, 4, 6, 254, 203, 117, 238, 238, 117, 1, 53, 254, 105,
  254, 202, 116, 237, 237, 116, 1, 54, 2, 14, 254, 101, 78, 1, 92, 1, 92, 78,
  254, 98, 27, 254, 101, 78, 1, 92, 1, 92, 78, 254, 98, 255, 255, 0, 22, 0, 0,
  4, 184, 5, 182, 2, 39, 0, 123, 254, 167, 0, 0, 0, 38, 2, 23, 0, 0, 1, 7, 2,
  60, 1, 57, 253, 89, 0, 60, 64, 39, 3, 2, 18, 24, 3, 2, 240, 18, 1, 224, 18, 1,
  128, 18, 1, 127, 18, 1, 16, 18, 1, 18, 0, 240, 0, 1, 224, 0, 1, 176, 0, 1, 80,
  0, 1, 64, 0, 1, 0, 17, 93, 93, 93, 93, 93, 53, 17, 93, 93, 93, 93, 93, 53, 53,
  0, 63, 53, 53, 255, 255, 0, 3, 0, 0, 4, 201, 5, 182, 2, 39, 0, 123, 254, 148,
  0, 0, 0, 38, 2, 23, 191, 0, 1, 7, 0, 116, 1, 90, 253, 97, 0, 68, 64, 45, 2,
  16, 24, 2, 240, 16, 1, 224, 16, 1, 208, 16, 1, 192, 16, 1, 16, 16, 1, 0, 16,
  1, 16, 1, 175, 13, 1, 143, 13, 1, 13, 0, 240, 0, 1, 224, 0, 1, 80, 0, 1, 64,
  0, 1, 0, 17, 93, 93, 93, 93, 53, 17, 93, 93, 53, 17, 93, 93, 93, 93, 93, 93,
  53, 0, 63, 53, 255, 255, 0, 21, 0, 0, 4, 205, 5, 197, 2, 39, 0, 117, 254, 191,
  0, 0, 0, 38, 2, 23, 53, 0, 1, 7, 2, 60, 1, 78, 253, 89, 0, 56, 64, 36, 3, 2,
  38, 24, 3, 2, 240, 38, 1, 224, 38, 1, 128, 38, 1, 16, 38, 1, 38, 1, 244, 33,
  1, 228, 33, 1, 212, 33, 1, 196, 33, 1, 176, 33, 1, 33, 17, 93, 93, 93, 93, 93,
  53, 17, 93, 93, 93, 93, 53, 53, 0, 63, 53, 53, 0, 2, 0, 168, 254, 119, 4, 31,
  4, 94, 0, 7, 0, 33, 0, 91, 64, 55, 33, 8, 8, 6, 150, 64, 2, 80, 2, 2, 2, 2,
  15, 159, 21, 1, 21, 35, 32, 35, 1, 15, 71, 159, 26, 1, 0, 26, 1, 26, 15, 23,
  32, 8, 1, 8, 8, 0, 20, 18, 81, 48, 23, 1, 23, 26, 0, 1, 9, 0, 1, 0, 155, 4,
  16, 0, 63, 225, 93, 93, 47, 93, 225, 51, 18, 57, 47, 93, 18, 57, 1, 47, 93,
  93, 225, 93, 16, 206, 93, 17, 57, 47, 93, 229, 50, 17, 51, 49, 48, 1, 34, 53,
  52, 51, 50, 21, 20, 7, 21, 20, 6, 7, 6, 6, 21, 20, 22, 51, 50, 55, 23, 6, 35,
  34, 38, 53, 52, 54, 55, 54, 54, 53, 53, 2, 162, 127, 127, 127, 39, 89, 118,
  129, 84, 149, 132, 181, 189, 62, 219, 203, 217, 248, 107, 143, 119, 65, 3, 72,
  139, 139, 139, 139, 164, 37, 119, 149, 84, 97, 116, 101, 93, 113, 90, 144,
  106, 195, 163, 134, 166, 108, 87, 107, 90, 19, 255, 255, 0, 33, 0, 0, 4, 172,
  7, 115, 2, 38, 0, 36, 0, 0, 1, 7, 0, 67, 255, 179, 1, 82, 0, 21, 180, 2, 15,
  5, 38, 2, 184, 255, 179, 180, 18, 15, 4, 7, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 33, 0, 0, 4, 172, 7, 115, 2, 38, 0, 36, 0, 0, 1, 7, 0, 118, 0, 102, 1,
  82, 0, 19, 64, 11, 2, 21, 5, 38, 2, 102, 15, 18, 4, 7, 37, 1, 43, 53, 0, 43,
  53, 0, 255, 255, 0, 33, 0, 0, 4, 172, 7, 115, 2, 38, 0, 36, 0, 0, 1, 7, 1, 75,
  0, 0, 1, 82, 0, 19, 64, 11, 2, 15, 5, 38, 2, 0, 21, 15, 4, 7, 37, 1, 43, 53,
  0, 43, 53, 0, 255, 255, 0, 33, 0, 0, 4, 172, 7, 53, 2, 38, 0, 36, 0, 0, 1, 7,
  1, 82, 255, 255, 1, 82, 0, 21, 180, 2, 15, 5, 38, 2, 184, 255, 254, 180, 16,
  25, 4, 7, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 33, 0, 0, 4, 172, 7, 43,
  2, 38, 0, 36, 0, 0, 1, 7, 0, 106, 0, 0, 1, 82, 0, 25, 182, 3, 2, 19, 5, 38, 3,
  2, 184, 255, 255, 180, 21, 25, 4, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255,
  255, 0, 33, 0, 0, 4, 172, 7, 4, 2, 38, 0, 36, 0, 0, 1, 6, 1, 80, 0, 125, 0,
  52, 64, 26, 3, 2, 239, 26, 1, 223, 26, 1, 80, 26, 1, 64, 26, 1, 32, 26, 1, 16,
  26, 1, 0, 26, 1, 26, 3, 2, 184, 255, 255, 180, 18, 24, 4, 7, 37, 1, 43, 53,
  53, 0, 17, 93, 93, 93, 93, 93, 93, 93, 53, 53, 0, 2, 0, 0, 0, 0, 4, 186, 5,
  182, 0, 15, 0, 19, 0, 134, 64, 84, 6, 8, 11, 14, 72, 16, 3, 19, 4, 201, 19,
  217, 19, 233, 19, 3, 55, 19, 1, 19, 6, 10, 14, 90, 1, 17, 1, 15, 1, 1, 79, 1,
  95, 1, 127, 1, 143, 1, 239, 1, 255, 1, 6, 6, 1, 11, 11, 1, 6, 3, 5, 8, 0, 21,
  4, 5, 3, 95, 16, 13, 95, 10, 159, 16, 207, 16, 2, 104, 10, 1, 16, 10, 16, 10,
  14, 19, 9, 95, 6, 3, 14, 95, 4, 1, 0, 47, 51, 225, 63, 225, 50, 18, 57, 57,
  47, 47, 93, 93, 16, 225, 16, 225, 1, 47, 51, 16, 206, 50, 17, 23, 57, 47, 47,
  47, 93, 113, 17, 51, 16, 225, 50, 17, 51, 93, 93, 17, 18, 57, 57, 43, 49, 48,
  33, 33, 17, 33, 3, 35, 1, 33, 21, 33, 17, 33, 21, 33, 17, 33, 1, 51, 17, 35,
  4, 186, 253, 115, 254, 223, 96, 172, 1, 82, 3, 104, 254, 35, 1, 182, 254, 74,
  1, 221, 252, 119, 252, 106, 1, 197, 254, 59, 5, 182, 164, 254, 60, 162, 253,
  248, 1, 198, 2, 168, 255, 255, 0, 129, 254, 20, 4, 156, 5, 203, 2, 38, 0, 38,
  0, 0, 1, 6, 0, 122, 80, 0, 0, 11, 182, 1, 40, 22, 34, 6, 11, 37, 1, 43, 53, 0,
  255, 255, 0, 217, 0, 0, 4, 35, 7, 115, 2, 38, 0, 40, 0, 0, 1, 7, 0, 67, 255,
  183, 1, 82, 0, 21, 180, 1, 12, 5, 38, 1, 184, 255, 160, 180, 15, 12, 1, 0, 37,
  1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 217, 0, 0, 4, 35, 7, 115, 2, 38, 0, 40,
  0, 0, 1, 7, 0, 118, 0, 63, 1, 82, 0, 19, 64, 11, 1, 18, 5, 38, 1, 39, 12, 15,
  1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 217, 0, 0, 4, 35, 7, 115, 2,
  38, 0, 40, 0, 0, 1, 7, 1, 75, 0, 35, 1, 82, 0, 19, 64, 11, 1, 12, 5, 38, 1,
  11, 18, 12, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 217, 0, 0, 4, 35,
  7, 43, 2, 38, 0, 40, 0, 0, 1, 7, 0, 106, 0, 25, 1, 82, 0, 23, 64, 13, 2, 1,
  16, 5, 38, 2, 1, 0, 18, 22, 1, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255,
  255, 0, 225, 0, 0, 3, 233, 7, 115, 2, 38, 0, 44, 0, 0, 1, 7, 0, 67, 255, 148,
  1, 82, 0, 21, 180, 1, 12, 5, 38, 1, 184, 255, 150, 180, 15, 12, 1, 0, 37, 1,
  43, 53, 0, 43, 53, 0, 255, 255, 0, 225, 0, 0, 3, 233, 7, 115, 2, 38, 0, 44, 0,
  0, 1, 7, 0, 118, 0, 119, 1, 82, 0, 19, 64, 11, 1, 18, 5, 38, 1, 120, 12, 15,
  1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 225, 0, 0, 3, 233, 7, 115, 2,
  38, 0, 44, 0, 0, 1, 7, 1, 75, 0, 0, 1, 82, 0, 19, 64, 11, 1, 12, 5, 38, 1, 1,
  18, 12, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 225, 0, 0, 3, 233, 7,
  43, 2, 38, 0, 44, 0, 0, 1, 7, 0, 106, 0, 2, 1, 82, 0, 23, 64, 13, 2, 1, 16, 5,
  38, 2, 1, 2, 18, 22, 1, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 0, 2, 0, 0, 0,
  0, 4, 123, 5, 182, 0, 12, 0, 23, 0, 73, 64, 44, 16, 0, 21, 91, 9, 25, 14, 18,
  90, 4, 2, 0, 0, 224, 0, 240, 0, 3, 0, 17, 2, 95, 14, 104, 3, 1, 47, 3, 159, 3,
  207, 3, 3, 3, 3, 18, 13, 96, 5, 3, 18, 96, 0, 18, 0, 63, 225, 63, 225, 18, 57,
  47, 93, 93, 51, 225, 50, 1, 47, 93, 198, 51, 225, 50, 16, 222, 225, 17, 57,
  49, 48, 51, 17, 35, 53, 51, 17, 33, 32, 0, 17, 16, 0, 33, 3, 17, 33, 21, 33,
  17, 51, 32, 17, 16, 33, 135, 135, 135, 1, 86, 1, 61, 1, 97, 254, 146, 254,
  167, 114, 1, 124, 254, 132, 96, 2, 20, 254, 19, 2, 147, 162, 2, 129, 254, 134,
  254, 173, 254, 151, 254, 128, 5, 23, 254, 30, 162, 254, 13, 2, 67, 2, 52, 255,
  255, 0, 135, 0, 0, 4, 68, 7, 53, 2, 38, 0, 49, 0, 0, 1, 7, 1, 82, 0, 4, 1, 82,
  0, 19, 64, 11, 1, 16, 5, 38, 1, 4, 17, 26, 7, 0, 37, 1, 43, 53, 0, 43, 53, 0,
  255, 255, 0, 84, 255, 236, 4, 123, 7, 115, 2, 38, 0, 50, 0, 0, 1, 7, 0, 67,
  255, 175, 1, 82, 0, 21, 180, 2, 20, 5, 38, 2, 184, 255, 174, 180, 23, 20, 2,
  7, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 84, 255, 236, 4, 123, 7, 115, 2,
  38, 0, 50, 0, 0, 1, 7, 0, 118, 0, 90, 1, 82, 0, 19, 64, 11, 2, 26, 5, 38, 2,
  89, 20, 23, 2, 7, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 84, 255, 236, 4,
  123, 7, 115, 2, 38, 0, 50, 0, 0, 1, 7, 1, 75, 0, 0, 1, 82, 0, 21, 180, 2, 20,
  5, 38, 2, 184, 255, 255, 180, 26, 20, 2, 7, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 84, 255, 236, 4, 123, 7, 53, 2, 38, 0, 50, 0, 0, 1, 7, 1, 82, 0, 8, 1,
  82, 0, 19, 64, 11, 2, 20, 5, 38, 2, 6, 21, 30, 2, 7, 37, 1, 43, 53, 0, 43, 53,
  0, 255, 255, 0, 84, 255, 236, 4, 123, 7, 43, 2, 38, 0, 50, 0, 0, 1, 7, 0, 106,
  0, 2, 1, 82, 0, 23, 64, 13, 3, 2, 24, 5, 38, 3, 2, 0, 26, 30, 2, 7, 37, 1, 43,
  53, 53, 0, 43, 53, 53, 0, 0, 1, 0, 190, 1, 45, 4, 14, 4, 123, 0, 11, 0, 92,
  185, 0, 6, 255, 240, 179, 15, 22, 72, 6, 184, 255, 248, 64, 24, 10, 14, 72, 0,
  16, 15, 22, 72, 0, 8, 10, 14, 72, 9, 16, 15, 22, 72, 9, 8, 10, 14, 72, 3, 184,
  255, 240, 179, 15, 22, 72, 3, 184, 255, 248, 64, 20, 10, 14, 72, 128, 3, 192,
  3, 208, 3, 240, 3, 4, 31, 3, 1, 3, 223, 0, 1, 0, 0, 25, 47, 93, 1, 47, 93, 93,
  49, 48, 0, 43, 43, 43, 43, 1, 43, 43, 43, 43, 1, 1, 55, 1, 1, 23, 1, 1, 7, 1,
  1, 39, 1, 252, 254, 194, 105, 1, 61, 1, 66, 104, 254, 191, 1, 63, 102, 254,
  190, 254, 195, 102, 2, 211, 1, 63, 105, 254, 194, 1, 62, 103, 254, 191, 254,
  192, 102, 1, 61, 254, 197, 103, 0, 3, 0, 80, 255, 180, 4, 133, 5, 252, 0, 18,
  0, 25, 0, 33, 0, 96, 185, 0, 19, 255, 224, 64, 56, 9, 23, 72, 26, 32, 9, 23,
  72, 26, 20, 27, 19, 4, 24, 32, 91, 12, 9, 0, 3, 4, 5, 11, 14, 35, 24, 91, 2,
  31, 5, 47, 5, 2, 5, 27, 19, 26, 20, 4, 22, 29, 95, 0, 3, 12, 9, 4, 7, 1, 17,
  19, 22, 95, 10, 7, 4, 0, 63, 51, 225, 63, 51, 18, 23, 57, 225, 17, 23, 57, 1,
  47, 93, 51, 225, 16, 222, 50, 17, 23, 57, 225, 17, 23, 57, 49, 48, 0, 43, 43,
  37, 7, 39, 55, 38, 17, 16, 33, 50, 23, 55, 23, 7, 22, 17, 16, 0, 35, 34, 3, 1,
  38, 35, 32, 17, 20, 1, 1, 22, 51, 50, 18, 17, 52, 1, 53, 92, 137, 121, 117, 2,
  22, 186, 124, 92, 137, 125, 115, 254, 236, 255, 189, 108, 2, 3, 80, 136, 254,
  175, 2, 122, 254, 0, 80, 133, 173, 161, 74, 150, 78, 197, 184, 1, 96, 2, 238,
  105, 152, 78, 201, 188, 254, 180, 254, 151, 254, 120, 1, 155, 3, 68, 94, 253,
  180, 212, 2, 28, 252, 192, 86, 1, 34, 1, 44, 209, 0, 255, 255, 0, 125, 255,
  236, 4, 80, 7, 115, 2, 38, 0, 56, 0, 0, 1, 7, 0, 67, 255, 187, 1, 82, 0, 21,
  180, 1, 15, 5, 38, 1, 184, 255, 187, 180, 18, 15, 6, 0, 37, 1, 43, 53, 0, 43,
  53, 0, 255, 255, 0, 125, 255, 236, 4, 80, 7, 115, 2, 38, 0, 56, 0, 0, 1, 7, 0,
  118, 0, 76, 1, 82, 0, 19, 64, 11, 1, 21, 5, 38, 1, 76, 15, 18, 6, 0, 37, 1,
  43, 53, 0, 43, 53, 0, 255, 255, 0, 125, 255, 236, 4, 80, 7, 115, 2, 38, 0, 56,
  0, 0, 1, 7, 1, 75, 0, 0, 1, 82, 0, 19, 64, 11, 1, 15, 5, 38, 1, 0, 21, 15, 6,
  0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 125, 255, 236, 4, 80, 7, 43, 2,
  38, 0, 56, 0, 0, 1, 7, 0, 106, 0, 2, 1, 82, 0, 23, 64, 13, 2, 1, 19, 5, 38, 2,
  1, 1, 21, 25, 6, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 33, 0,
  0, 4, 170, 7, 115, 2, 38, 0, 60, 0, 0, 1, 7, 0, 118, 0, 76, 1, 82, 0, 19, 64,
  11, 1, 15, 5, 38, 1, 77, 9, 12, 7, 2, 37, 1, 43, 53, 0, 43, 53, 0, 0, 2, 0,
  176, 0, 0, 4, 70, 5, 182, 0, 11, 0, 19, 0, 62, 64, 36, 16, 91, 239, 8, 255, 8,
  2, 8, 21, 12, 5, 1, 90, 0, 2, 144, 2, 160, 2, 3, 2, 12, 96, 0, 19, 96, 5, 0,
  5, 0, 5, 1, 3, 3, 1, 18, 0, 63, 63, 18, 57, 57, 47, 47, 16, 225, 16, 225, 1,
  47, 93, 225, 50, 50, 16, 222, 93, 225, 49, 48, 1, 17, 35, 17, 51, 21, 51, 32,
  17, 20, 4, 33, 39, 51, 50, 54, 53, 16, 33, 35, 1, 106, 186, 186, 218, 2, 2,
  254, 235, 254, 248, 191, 170, 198, 171, 254, 174, 201, 1, 61, 254, 195, 5,
  182, 252, 254, 84, 219, 246, 158, 144, 153, 1, 23, 0, 1, 0, 164, 255, 236, 4,
  127, 6, 31, 0, 42, 0, 114, 64, 75, 16, 22, 1, 11, 70, 32, 15, 71, 27, 29, 0,
  1, 15, 0, 1, 79, 32, 95, 32, 2, 29, 32, 1, 15, 32, 1, 15, 27, 31, 27, 191, 27,
  207, 27, 223, 27, 5, 0, 32, 27, 27, 32, 0, 3, 21, 5, 71, 38, 44, 20, 71, 0,
  21, 160, 21, 176, 21, 3, 21, 5, 32, 15, 3, 24, 3, 80, 1, 41, 22, 17, 80, 24,
  1, 21, 21, 0, 63, 63, 225, 63, 51, 225, 18, 23, 57, 1, 47, 93, 225, 16, 222,
  225, 18, 23, 57, 47, 47, 47, 93, 93, 93, 93, 93, 93, 16, 225, 16, 225, 49, 48,
  0, 93, 37, 53, 22, 51, 50, 53, 52, 38, 39, 38, 38, 53, 52, 55, 54, 53, 52, 35,
  34, 21, 17, 35, 17, 16, 33, 50, 22, 21, 20, 7, 6, 6, 21, 20, 22, 23, 22, 22,
  21, 20, 6, 35, 34, 1, 223, 143, 134, 213, 91, 98, 123, 100, 129, 129, 227,
  242, 182, 1, 168, 194, 217, 133, 84, 49, 58, 122, 144, 94, 200, 183, 182, 49,
  166, 86, 174, 81, 102, 61, 78, 122, 87, 117, 106, 106, 90, 164, 215, 251, 78,
  4, 176, 1, 111, 159, 148, 132, 117, 74, 62, 33, 39, 60, 81, 95, 156, 98, 162,
  171, 255, 255, 0, 135, 255, 236, 4, 2, 6, 33, 2, 38, 0, 68, 0, 0, 1, 6, 0, 67,
  171, 0, 0, 21, 180, 2, 34, 17, 38, 2, 184, 255, 205, 180, 37, 34, 8, 22, 37,
  1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 135, 255, 236, 4, 2, 6, 33, 2, 38, 0,
  68, 0, 0, 1, 6, 0, 118, 84, 0, 0, 23, 64, 14, 2, 40, 17, 38, 2, 80, 34, 1,
  118, 34, 37, 8, 22, 37, 1, 43, 93, 53, 0, 43, 53, 0, 255, 255, 0, 135, 255,
  236, 4, 2, 6, 33, 2, 38, 0, 68, 0, 0, 1, 6, 1, 75, 8, 0, 0, 23, 64, 14, 2, 34,
  17, 38, 2, 96, 40, 1, 42, 40, 34, 8, 22, 37, 1, 43, 93, 53, 0, 43, 53, 0, 255,
  255, 0, 135, 255, 236, 4, 2, 5, 227, 2, 38, 0, 68, 0, 0, 1, 6, 1, 82, 10, 0,
  0, 31, 64, 20, 2, 34, 17, 38, 2, 128, 35, 1, 112, 35, 1, 96, 35, 1, 43, 35,
  44, 8, 22, 37, 1, 43, 93, 93, 93, 53, 0, 43, 53, 0, 255, 255, 0, 135, 255,
  236, 4, 2, 5, 217, 2, 38, 0, 68, 0, 0, 1, 6, 0, 106, 12, 0, 0, 35, 64, 22, 3,
  2, 38, 17, 38, 3, 2, 80, 40, 1, 64, 40, 1, 48, 40, 1, 45, 40, 44, 8, 22, 37,
  1, 43, 93, 93, 93, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 135, 255, 236, 4, 2,
  6, 135, 2, 38, 0, 68, 0, 0, 1, 6, 1, 80, 255, 0, 0, 23, 64, 13, 3, 2, 34, 17,
  38, 3, 2, 32, 37, 43, 8, 22, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 0, 3, 0, 45,
  255, 236, 4, 162, 4, 94, 0, 34, 0, 41, 0, 51, 0, 104, 64, 60, 27, 10, 35, 17,
  71, 0, 16, 51, 192, 51, 2, 51, 51, 32, 36, 70, 23, 16, 64, 10, 22, 72, 11, 16,
  1, 16, 53, 45, 71, 6, 224, 32, 240, 32, 2, 32, 42, 17, 80, 0, 35, 35, 8, 27,
  20, 48, 80, 22, 25, 25, 29, 22, 39, 10, 3, 80, 12, 5, 8, 16, 0, 63, 51, 51,
  225, 50, 50, 63, 51, 17, 51, 225, 50, 50, 17, 57, 47, 51, 225, 50, 1, 47, 93,
  51, 225, 16, 222, 93, 43, 50, 225, 17, 57, 47, 93, 51, 225, 50, 57, 57, 49,
  48, 1, 53, 52, 35, 34, 7, 39, 54, 51, 50, 23, 54, 51, 50, 18, 21, 21, 33, 22,
  22, 51, 50, 55, 21, 6, 35, 34, 39, 6, 35, 34, 38, 53, 16, 37, 37, 33, 52, 38,
  35, 34, 6, 3, 7, 6, 21, 20, 22, 51, 50, 54, 53, 2, 10, 139, 107, 104, 57, 131,
  145, 188, 58, 78, 162, 137, 172, 254, 16, 3, 128, 105, 111, 122, 107, 134,
  222, 94, 105, 196, 115, 141, 1, 72, 1, 65, 1, 60, 81, 71, 68, 90, 180, 88,
  217, 64, 55, 82, 104, 2, 150, 69, 236, 82, 137, 96, 178, 178, 254, 241, 220,
  113, 192, 183, 76, 162, 73, 229, 229, 173, 154, 1, 76, 16, 7, 141, 164, 156,
  254, 238, 7, 17, 208, 83, 95, 165, 146, 255, 255, 0, 172, 254, 20, 4, 37, 4,
  94, 2, 38, 0, 70, 0, 0, 1, 6, 0, 122, 49, 0, 0, 11, 182, 1, 47, 20, 32, 15, 0,
  37, 1, 43, 53, 0, 255, 255, 0, 133, 255, 236, 4, 72, 6, 33, 2, 38, 0, 72, 0,
  0, 1, 6, 0, 67, 212, 0, 0, 21, 180, 2, 23, 17, 38, 2, 184, 255, 212, 180, 26,
  23, 11, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 133, 255, 236, 4, 72, 6,
  33, 2, 38, 0, 72, 0, 0, 1, 6, 0, 118, 82, 0, 0, 31, 64, 20, 2, 29, 17, 38, 2,
  160, 23, 1, 16, 23, 1, 0, 23, 1, 82, 23, 26, 11, 0, 37, 1, 43, 93, 93, 93, 53,
  0, 43, 53, 0, 255, 255, 0, 133, 255, 236, 4, 72, 6, 33, 2, 38, 0, 72, 0, 0, 1,
  6, 1, 75, 16, 0, 0, 19, 64, 11, 2, 23, 17, 38, 2, 16, 29, 23, 11, 0, 37, 1,
  43, 53, 0, 43, 53, 0, 255, 255, 0, 133, 255, 236, 4, 72, 5, 217, 2, 38, 0, 72,
  0, 0, 1, 6, 0, 106, 18, 0, 0, 23, 64, 13, 3, 2, 27, 17, 38, 3, 2, 17, 29, 33,
  11, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 197, 0, 0, 4, 51, 6,
  33, 2, 38, 0, 243, 0, 0, 1, 6, 0, 67, 171, 0, 0, 21, 180, 1, 10, 17, 38, 1,
  184, 255, 150, 180, 13, 10, 7, 5, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  197, 0, 0, 4, 51, 6, 33, 2, 38, 0, 243, 0, 0, 1, 6, 0, 118, 113, 0, 0, 19, 64,
  11, 1, 16, 17, 38, 1, 91, 10, 13, 7, 5, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255,
  0, 197, 0, 0, 4, 51, 6, 33, 2, 38, 0, 243, 0, 0, 1, 6, 1, 75, 0, 0, 0, 21,
  180, 1, 10, 17, 38, 1, 184, 255, 235, 180, 16, 10, 7, 5, 37, 1, 43, 53, 0, 43,
  53, 0, 255, 255, 0, 197, 0, 0, 4, 51, 5, 217, 2, 38, 0, 243, 0, 0, 1, 6, 0,
  106, 0, 0, 0, 25, 182, 2, 1, 14, 17, 38, 2, 1, 184, 255, 234, 180, 16, 20, 7,
  5, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 0, 2, 0, 135, 255, 236, 4, 70, 6, 35,
  0, 26, 0, 36, 0, 112, 185, 0, 11, 255, 224, 64, 65, 15, 20, 72, 6, 32, 15, 19,
  72, 1, 34, 72, 16, 14, 11, 3, 6, 8, 5, 13, 5, 13, 5, 13, 22, 239, 16, 255, 16,
  2, 16, 38, 29, 72, 0, 22, 224, 22, 240, 22, 3, 22, 0, 27, 80, 25, 14, 6, 11,
  3, 48, 25, 1, 4, 25, 4, 25, 9, 31, 80, 19, 22, 12, 12, 9, 1, 0, 63, 51, 47,
  63, 225, 18, 57, 57, 47, 47, 93, 23, 57, 16, 225, 50, 1, 47, 93, 225, 16, 206,
  93, 17, 57, 57, 47, 47, 18, 23, 57, 16, 225, 50, 49, 48, 43, 0, 43, 1, 55, 38,
  39, 5, 39, 55, 38, 39, 55, 22, 23, 55, 23, 7, 0, 17, 16, 0, 35, 34, 0, 53, 52,
  18, 51, 50, 7, 32, 17, 16, 33, 50, 54, 53, 52, 38, 3, 121, 8, 58, 184, 255, 0,
  73, 217, 104, 68, 69, 143, 103, 227, 74, 194, 1, 45, 254, 255, 225, 213, 254,
  248, 241, 214, 211, 187, 254, 226, 1, 32, 154, 135, 155, 3, 84, 4, 226, 165,
  153, 114, 131, 71, 38, 123, 70, 78, 138, 113, 117, 254, 221, 254, 45, 254,
  235, 254, 196, 1, 11, 230, 234, 1, 4, 148, 254, 160, 254, 172, 199, 196, 129,
  168, 255, 255, 0, 160, 0, 0, 4, 45, 5, 227, 2, 38, 0, 81, 0, 0, 1, 6, 1, 82,
  6, 0, 0, 19, 64, 11, 1, 17, 17, 38, 1, 5, 18, 27, 7, 15, 37, 1, 43, 53, 0, 43,
  53, 0, 255, 255, 0, 115, 255, 236, 4, 88, 6, 33, 2, 38, 0, 82, 0, 0, 1, 6, 0,
  67, 216, 0, 0, 21, 180, 2, 20, 17, 38, 2, 184, 255, 217, 180, 23, 20, 3, 9,
  37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 115, 255, 236, 4, 88, 6, 33, 2, 38,
  0, 82, 0, 0, 1, 6, 0, 118, 80, 0, 0, 19, 64, 11, 2, 26, 17, 38, 2, 81, 20, 23,
  3, 9, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 115, 255, 236, 4, 88, 6, 33,
  2, 38, 0, 82, 0, 0, 1, 6, 1, 75, 251, 0, 0, 21, 180, 2, 20, 17, 38, 2, 184,
  255, 252, 180, 26, 20, 3, 9, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 115,
  255, 236, 4, 88, 5, 227, 2, 38, 0, 82, 0, 0, 1, 6, 1, 82, 0, 0, 0, 19, 64, 11,
  2, 20, 17, 38, 2, 0, 21, 30, 3, 9, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  115, 255, 236, 4, 88, 5, 217, 2, 38, 0, 82, 0, 0, 1, 6, 0, 106, 249, 0, 0, 25,
  182, 3, 2, 24, 17, 38, 3, 2, 184, 255, 249, 180, 26, 30, 3, 9, 37, 1, 43, 53,
  53, 0, 43, 53, 53, 0, 0, 3, 0, 152, 0, 248, 4, 51, 4, 172, 0, 7, 0, 11, 0, 19,
  0, 83, 64, 55, 64, 10, 1, 15, 10, 1, 10, 10, 14, 18, 6, 80, 9, 240, 9, 2, 9,
  9, 2, 172, 31, 6, 95, 6, 159, 6, 3, 6, 12, 175, 0, 16, 64, 16, 112, 16, 144,
  16, 160, 16, 176, 16, 240, 16, 7, 16, 16, 8, 4, 175, 0, 8, 173, 9, 179, 0, 63,
  225, 220, 225, 16, 200, 47, 93, 225, 1, 47, 93, 225, 51, 47, 93, 17, 51, 50,
  50, 47, 93, 93, 49, 48, 1, 50, 21, 20, 35, 34, 53, 52, 1, 53, 33, 21, 5, 50,
  21, 20, 35, 34, 53, 52, 2, 100, 115, 115, 114, 254, 166, 3, 155, 254, 49, 115,
  115, 114, 4, 172, 125, 125, 125, 125, 253, 219, 150, 150, 149, 125, 125, 125,
  125, 0, 3, 0, 115, 255, 170, 4, 88, 4, 156, 0, 19, 0, 27, 0, 35, 0, 110, 181,
  21, 16, 9, 21, 72, 29, 184, 255, 240, 179, 9, 21, 72, 20, 184, 255, 240, 64,
  54, 15, 20, 72, 28, 16, 15, 20, 72, 28, 21, 29, 20, 4, 26, 34, 72, 13, 10, 0,
  3, 4, 5, 12, 15, 37, 26, 72, 2, 0, 5, 1, 5, 29, 20, 28, 21, 4, 23, 31, 80, 10,
  13, 3, 0, 4, 8, 1, 18, 22, 23, 80, 11, 8, 16, 0, 63, 51, 225, 63, 51, 18, 23,
  57, 225, 17, 23, 57, 1, 47, 93, 51, 225, 16, 222, 50, 17, 23, 57, 225, 17, 23,
  57, 49, 48, 0, 43, 43, 1, 43, 43, 37, 7, 39, 55, 38, 17, 16, 0, 51, 50, 23,
  55, 23, 7, 22, 17, 16, 0, 35, 34, 3, 1, 38, 35, 34, 6, 21, 20, 1, 1, 22, 51,
  50, 54, 53, 52, 1, 121, 76, 131, 84, 139, 1, 10, 235, 128, 108, 76, 131, 84,
  137, 254, 243, 233, 129, 125, 1, 150, 66, 90, 161, 142, 2, 57, 254, 107, 61,
  93, 161, 142, 33, 119, 84, 131, 158, 1, 8, 1, 10, 1, 45, 57, 119, 84, 131,
  156, 254, 254, 254, 241, 254, 212, 1, 40, 2, 144, 35, 207, 209, 180, 1, 190,
  253, 115, 33, 211, 209, 164, 255, 255, 0, 160, 255, 236, 4, 45, 6, 33, 2, 38,
  0, 88, 0, 0, 1, 6, 0, 67, 179, 0, 0, 21, 180, 1, 18, 17, 38, 1, 184, 255, 179,
  180, 21, 18, 6, 16, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160, 255, 236,
  4, 45, 6, 33, 2, 38, 0, 88, 0, 0, 1, 6, 0, 118, 82, 0, 0, 19, 64, 11, 1, 24,
  17, 38, 1, 82, 18, 21, 6, 16, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160,
  255, 236, 4, 45, 6, 33, 2, 38, 0, 88, 0, 0, 1, 6, 1, 75, 8, 0, 0, 19, 64, 11,
  1, 18, 17, 38, 1, 8, 24, 18, 6, 16, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  160, 255, 236, 4, 45, 5, 217, 2, 38, 0, 88, 0, 0, 1, 6, 0, 106, 2, 0, 0, 23,
  64, 13, 2, 1, 22, 17, 38, 2, 1, 1, 24, 28, 6, 16, 37, 1, 43, 53, 53, 0, 43,
  53, 53, 0, 255, 255, 0, 82, 254, 20, 4, 121, 6, 33, 2, 38, 0, 92, 0, 0, 1, 6,
  0, 118, 76, 0, 0, 19, 64, 11, 1, 29, 17, 38, 1, 77, 23, 26, 0, 9, 37, 1, 43,
  53, 0, 43, 53, 0, 0, 2, 0, 158, 254, 20, 4, 68, 6, 20, 0, 19, 0, 30, 0, 59,
  64, 36, 26, 72, 239, 5, 255, 5, 2, 5, 32, 11, 17, 19, 21, 4, 14, 71, 0, 15,
  176, 15, 2, 15, 16, 0, 14, 27, 10, 24, 80, 8, 22, 0, 28, 80, 2, 16, 0, 63,
  225, 50, 63, 225, 50, 63, 63, 1, 47, 93, 225, 23, 50, 16, 222, 93, 225, 49,
  48, 1, 54, 51, 50, 18, 17, 16, 2, 35, 34, 39, 35, 22, 21, 17, 35, 17, 51, 17,
  7, 19, 21, 20, 22, 51, 32, 17, 16, 33, 34, 6, 1, 84, 110, 212, 201, 229, 230,
  200, 207, 115, 12, 12, 182, 182, 8, 8, 139, 152, 1, 16, 254, 238, 152, 133, 3,
  182, 168, 254, 213, 254, 244, 254, 242, 254, 211, 159, 129, 33, 254, 43, 8, 0,
  254, 54, 148, 254, 154, 41, 227, 193, 1, 166, 1, 158, 176, 0, 255, 255, 0, 82,
  254, 20, 4, 121, 5, 217, 2, 38, 0, 92, 0, 0, 1, 6, 0, 106, 8, 0, 0, 23, 64,
  13, 2, 1, 27, 17, 38, 2, 1, 8, 29, 33, 0, 9, 37, 1, 43, 53, 53, 0, 43, 53, 53,
  0, 255, 255, 0, 33, 0, 0, 4, 172, 6, 193, 2, 38, 0, 36, 0, 0, 1, 7, 1, 77, 0,
  0, 1, 82, 0, 21, 180, 2, 17, 5, 38, 2, 184, 255, 255, 180, 15, 16, 4, 7, 37,
  1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 135, 255, 236, 4, 2, 5, 111, 2, 38, 0,
  68, 0, 0, 1, 6, 1, 77, 247, 0, 0, 19, 64, 11, 2, 36, 17, 38, 2, 24, 34, 35, 8,
  22, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 33, 0, 0, 4, 172, 7, 64, 2, 38,
  0, 36, 0, 0, 1, 7, 1, 78, 255, 253, 1, 82, 0, 21, 180, 2, 18, 5, 38, 2, 184,
  255, 253, 180, 20, 15, 4, 7, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 135,
  255, 236, 4, 2, 5, 238, 2, 38, 0, 68, 0, 0, 1, 6, 1, 78, 245, 0, 0, 19, 64,
  11, 2, 37, 17, 38, 2, 22, 39, 34, 8, 22, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 33, 254, 57, 4, 190, 5, 188, 2, 38, 0, 36, 0, 0, 1, 7, 1, 81, 1, 143,
  0, 0, 0, 24, 64, 16, 2, 32, 23, 1, 16, 23, 1, 0, 23, 1, 0, 23, 23, 0, 0, 37,
  1, 43, 93, 93, 93, 53, 255, 255, 0, 135, 254, 57, 4, 82, 4, 94, 2, 38, 0, 68,
  0, 0, 1, 7, 1, 81, 1, 35, 0, 0, 0, 36, 64, 25, 2, 128, 42, 1, 112, 42, 1, 96,
  42, 1, 32, 42, 1, 16, 42, 1, 0, 42, 1, 0, 42, 42, 0, 0, 37, 1, 43, 93, 93, 93,
  93, 93, 93, 53, 255, 255, 0, 129, 255, 236, 4, 156, 7, 115, 2, 38, 0, 38, 0,
  0, 1, 7, 0, 118, 0, 242, 1, 82, 0, 19, 64, 11, 1, 28, 5, 38, 1, 202, 22, 25,
  6, 11, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 172, 255, 236, 4, 37, 6, 33,
  2, 38, 0, 70, 0, 0, 1, 7, 0, 118, 0, 160, 0, 0, 0, 19, 64, 11, 1, 26, 17, 38,
  1, 158, 20, 23, 15, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 129, 255,
  236, 4, 156, 7, 115, 2, 38, 0, 38, 0, 0, 1, 7, 1, 75, 0, 160, 1, 82, 0, 39,
  64, 26, 1, 22, 5, 38, 1, 208, 28, 1, 176, 28, 1, 128, 28, 1, 112, 28, 1, 80,
  28, 1, 120, 28, 22, 6, 11, 37, 1, 43, 93, 93, 93, 93, 93, 53, 0, 43, 53, 0,
  255, 255, 0, 172, 255, 236, 4, 37, 6, 33, 2, 38, 0, 70, 0, 0, 1, 6, 1, 75, 84,
  0, 0, 19, 64, 11, 1, 20, 17, 38, 1, 82, 26, 20, 15, 0, 37, 1, 43, 53, 0, 43,
  53, 0, 255, 255, 0, 129, 255, 236, 4, 156, 7, 55, 2, 38, 0, 38, 0, 0, 1, 7, 1,
  79, 0, 164, 1, 82, 0, 19, 64, 11, 1, 26, 5, 38, 1, 124, 28, 24, 6, 11, 37, 1,
  43, 53, 0, 43, 53, 0, 255, 255, 0, 172, 255, 236, 4, 37, 5, 229, 2, 38, 0, 70,
  0, 0, 1, 6, 1, 79, 84, 0, 0, 19, 64, 11, 1, 24, 17, 38, 1, 82, 26, 22, 15, 0,
  37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 129, 255, 236, 4, 156, 7, 115, 2,
  38, 0, 38, 0, 0, 1, 7, 1, 76, 0, 154, 1, 82, 0, 19, 64, 11, 1, 26, 5, 38, 1,
  114, 30, 22, 6, 11, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 172, 255, 236,
  4, 37, 6, 33, 2, 38, 0, 70, 0, 0, 1, 6, 1, 76, 92, 0, 0, 19, 64, 11, 1, 24,
  17, 38, 1, 90, 28, 20, 15, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 135,
  0, 0, 4, 123, 7, 115, 2, 38, 0, 39, 0, 0, 1, 7, 1, 76, 255, 247, 1, 82, 0, 21,
  180, 2, 20, 5, 38, 2, 184, 255, 221, 180, 24, 16, 0, 5, 37, 1, 43, 53, 0, 43,
  53, 0, 255, 255, 0, 79, 255, 236, 5, 35, 6, 20, 0, 38, 0, 71, 198, 0, 1, 7, 2,
  56, 2, 68, 0, 0, 0, 30, 64, 11, 2, 2, 127, 30, 1, 111, 30, 1, 79, 30, 1, 184,
  2, 136, 180, 30, 34, 6, 16, 37, 1, 43, 93, 93, 93, 53, 0, 53, 255, 255, 0, 0,
  0, 0, 4, 123, 5, 182, 2, 6, 0, 146, 0, 0, 0, 2, 0, 137, 255, 236, 4, 203, 6,
  20, 0, 26, 0, 37, 0, 89, 64, 55, 16, 6, 0, 12, 15, 18, 4, 27, 71, 23, 21, 144,
  25, 160, 25, 2, 25, 39, 33, 72, 0, 6, 224, 6, 240, 6, 3, 6, 24, 16, 79, 21,
  17, 17, 19, 12, 31, 80, 0, 9, 16, 9, 32, 9, 3, 9, 9, 19, 0, 35, 80, 3, 22, 26,
  21, 0, 63, 63, 225, 63, 57, 47, 93, 225, 50, 18, 57, 47, 51, 225, 50, 1, 47,
  93, 225, 16, 222, 93, 50, 50, 225, 23, 50, 17, 57, 49, 48, 37, 35, 6, 35, 34,
  2, 17, 16, 18, 51, 50, 23, 51, 38, 53, 53, 33, 53, 33, 53, 51, 21, 51, 21, 35,
  17, 35, 3, 53, 52, 38, 35, 32, 17, 16, 33, 50, 54, 3, 129, 8, 113, 209, 201,
  229, 230, 200, 208, 114, 12, 12, 254, 133, 1, 123, 182, 156, 156, 147, 35,
  139, 152, 254, 240, 1, 18, 151, 134, 147, 167, 1, 32, 1, 2, 1, 4, 1, 35, 159,
  126, 35, 158, 137, 182, 182, 137, 251, 43, 1, 231, 39, 216, 184, 254, 110,
  254, 119, 166, 0, 255, 255, 0, 217, 0, 0, 4, 35, 6, 193, 2, 38, 0, 40, 0, 0,
  1, 7, 1, 77, 0, 10, 1, 82, 0, 21, 180, 1, 14, 5, 38, 1, 184, 255, 242, 180,
  12, 13, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 133, 255, 236, 4, 72,
  5, 111, 2, 38, 0, 72, 0, 0, 1, 6, 1, 77, 20, 0, 0, 19, 64, 11, 2, 25, 17, 38,
  2, 19, 23, 24, 11, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 217, 0, 0, 4,
  35, 7, 64, 2, 38, 0, 40, 0, 0, 1, 7, 1, 78, 0, 29, 1, 82, 0, 19, 64, 11, 1,
  15, 5, 38, 1, 5, 17, 12, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 133,
  255, 236, 4, 72, 5, 238, 2, 38, 0, 72, 0, 0, 1, 6, 1, 78, 16, 0, 0, 19, 64,
  11, 2, 26, 17, 38, 2, 15, 28, 23, 11, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 217, 0, 0, 4, 35, 7, 26, 2, 38, 0, 40, 0, 0, 1, 7, 1, 79, 0, 35, 1,
  53, 0, 19, 64, 11, 1, 16, 5, 38, 1, 11, 18, 14, 1, 0, 37, 1, 43, 53, 0, 43,
  53, 0, 255, 255, 0, 133, 255, 236, 4, 72, 5, 229, 2, 38, 0, 72, 0, 0, 1, 6, 1,
  79, 23, 0, 0, 19, 64, 11, 2, 27, 17, 38, 2, 23, 29, 25, 11, 0, 37, 1, 43, 53,
  0, 43, 53, 0, 255, 255, 0, 217, 254, 57, 4, 35, 5, 182, 2, 38, 0, 40, 0, 0, 1,
  7, 1, 81, 0, 205, 0, 0, 0, 14, 183, 1, 1, 181, 18, 12, 1, 0, 37, 1, 43, 53, 0,
  53, 255, 255, 0, 133, 254, 88, 4, 72, 4, 94, 2, 38, 0, 72, 0, 0, 1, 7, 1, 81,
  0, 227, 0, 31, 0, 14, 183, 2, 2, 227, 29, 23, 11, 0, 37, 1, 43, 53, 0, 53,
  255, 255, 0, 217, 0, 0, 4, 35, 7, 115, 2, 38, 0, 40, 0, 0, 1, 7, 1, 76, 0, 35,
  1, 82, 0, 19, 64, 11, 1, 16, 5, 38, 1, 11, 20, 12, 1, 0, 37, 1, 43, 53, 0, 43,
  53, 0, 255, 255, 0, 133, 255, 236, 4, 72, 6, 33, 2, 38, 0, 72, 0, 0, 1, 6, 1,
  76, 25, 0, 0, 19, 64, 11, 2, 27, 17, 38, 2, 25, 31, 23, 11, 0, 37, 1, 43, 53,
  0, 43, 53, 0, 255, 255, 0, 117, 255, 236, 4, 70, 7, 115, 2, 38, 0, 42, 0, 0,
  1, 7, 1, 75, 0, 80, 1, 82, 0, 19, 64, 11, 1, 25, 5, 38, 1, 89, 31, 25, 7, 1,
  37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 102, 254, 20, 4, 102, 6, 33, 2, 38,
  0, 74, 0, 0, 1, 6, 1, 75, 247, 0, 0, 21, 180, 3, 55, 17, 38, 3, 184, 255, 248,
  180, 61, 55, 22, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 117, 255, 236,
  4, 70, 7, 64, 2, 38, 0, 42, 0, 0, 1, 7, 1, 78, 0, 98, 1, 82, 0, 27, 64, 17, 1,
  28, 5, 38, 1, 16, 30, 1, 0, 30, 1, 106, 30, 25, 7, 1, 37, 1, 43, 93, 93, 53,
  0, 43, 53, 0, 255, 255, 0, 102, 254, 20, 4, 102, 5, 238, 2, 38, 0, 74, 0, 0,
  1, 6, 1, 78, 243, 0, 0, 21, 180, 3, 58, 17, 38, 3, 184, 255, 243, 180, 60, 55,
  22, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 117, 255, 236, 4, 70, 7, 55,
  2, 38, 0, 42, 0, 0, 1, 7, 1, 79, 0, 109, 1, 82, 0, 19, 64, 11, 1, 29, 5, 38,
  1, 118, 31, 27, 7, 1, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 102, 254, 20,
  4, 102, 5, 229, 2, 38, 0, 74, 0, 0, 1, 6, 1, 79, 255, 0, 0, 19, 64, 11, 3, 59,
  17, 38, 3, 0, 61, 57, 22, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 117,
  254, 59, 4, 70, 5, 203, 2, 38, 0, 42, 0, 0, 1, 6, 2, 57, 57, 0, 0, 19, 64, 11,
  1, 27, 20, 39, 1, 65, 25, 28, 7, 1, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  102, 254, 20, 4, 102, 6, 33, 2, 38, 0, 74, 0, 0, 1, 6, 2, 58, 45, 0, 0, 19,
  64, 11, 3, 57, 17, 38, 3, 45, 58, 55, 22, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 135, 0, 0, 4, 70, 7, 115, 2, 38, 0, 43, 0, 0, 1, 7, 1, 75, 0, 0, 1,
  82, 0, 19, 64, 11, 1, 12, 5, 38, 1, 0, 18, 12, 5, 0, 37, 1, 43, 53, 0, 43, 53,
  0, 255, 255, 0, 160, 0, 0, 4, 45, 7, 170, 2, 38, 0, 75, 0, 0, 1, 7, 1, 75, 0,
  14, 1, 137, 0, 19, 64, 11, 1, 18, 2, 38, 1, 14, 24, 18, 7, 16, 37, 1, 43, 53,
  0, 43, 53, 0, 0, 2, 0, 0, 0, 0, 4, 205, 5, 182, 0, 19, 0, 23, 0, 88, 64, 48,
  20, 4, 12, 90, 9, 7, 11, 25, 23, 3, 15, 90, 18, 0, 224, 16, 240, 16, 2, 16,
  14, 95, 23, 22, 10, 104, 18, 1, 18, 96, 19, 7, 3, 19, 104, 23, 1, 23, 19, 23,
  19, 1, 16, 11, 18, 5, 1, 3, 0, 63, 51, 63, 51, 18, 57, 57, 47, 47, 93, 17, 51,
  51, 16, 225, 93, 50, 50, 16, 225, 1, 47, 93, 51, 51, 225, 50, 50, 16, 222, 50,
  50, 225, 50, 50, 49, 48, 19, 53, 51, 21, 33, 53, 51, 21, 51, 21, 35, 17, 35,
  17, 33, 17, 35, 17, 35, 53, 1, 53, 33, 21, 135, 187, 2, 73, 187, 135, 135,
  187, 253, 183, 187, 135, 3, 139, 253, 183, 4, 195, 243, 243, 243, 243, 150,
  251, 211, 2, 170, 253, 86, 4, 45, 150, 254, 139, 223, 223, 0, 1, 0, 4, 0, 0,
  4, 45, 6, 20, 0, 27, 0, 82, 64, 49, 17, 8, 0, 71, 144, 27, 160, 27, 2, 27, 29,
  15, 19, 20, 3, 7, 71, 12, 10, 0, 8, 176, 8, 2, 8, 18, 10, 79, 15, 11, 11, 13,
  20, 3, 80, 0, 23, 16, 23, 32, 23, 3, 23, 23, 13, 0, 8, 0, 21, 0, 63, 50, 63,
  57, 47, 93, 225, 50, 18, 57, 47, 51, 225, 50, 1, 47, 93, 51, 51, 225, 23, 50,
  16, 222, 93, 225, 18, 57, 49, 48, 33, 17, 16, 35, 34, 6, 21, 17, 35, 17, 35,
  53, 51, 53, 51, 21, 33, 21, 33, 21, 7, 51, 54, 51, 50, 22, 21, 17, 3, 119,
  236, 162, 147, 182, 156, 156, 184, 1, 162, 254, 92, 10, 10, 108, 238, 192,
  189, 2, 154, 1, 4, 187, 211, 253, 240, 4, 213, 137, 182, 182, 137, 184, 144,
  168, 191, 210, 253, 92, 255, 255, 0, 225, 0, 0, 3, 233, 7, 53, 2, 38, 0, 44,
  0, 0, 1, 7, 1, 82, 0, 0, 1, 82, 0, 19, 64, 11, 1, 12, 5, 38, 1, 0, 13, 22, 1,
  0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 197, 0, 0, 4, 51, 5, 227, 2, 38,
  0, 243, 0, 0, 1, 6, 1, 82, 253, 0, 0, 21, 180, 1, 10, 17, 38, 1, 184, 255,
  231, 180, 11, 20, 7, 5, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 225, 0, 0,
  3, 233, 6, 193, 2, 38, 0, 44, 0, 0, 1, 7, 1, 77, 0, 2, 1, 82, 0, 19, 64, 11,
  1, 14, 5, 38, 1, 2, 12, 13, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  197, 0, 0, 4, 51, 5, 111, 2, 38, 0, 243, 0, 0, 1, 6, 1, 77, 0, 0, 0, 21, 180,
  1, 12, 17, 38, 1, 184, 255, 234, 180, 10, 11, 7, 5, 37, 1, 43, 53, 0, 43, 53,
  0, 255, 255, 0, 225, 0, 0, 3, 233, 7, 64, 2, 38, 0, 44, 0, 0, 1, 7, 1, 78, 0,
  0, 1, 82, 0, 19, 64, 11, 1, 15, 5, 38, 1, 1, 17, 12, 1, 0, 37, 1, 43, 53, 0,
  43, 53, 0, 255, 255, 0, 197, 0, 0, 4, 51, 5, 238, 2, 38, 0, 243, 0, 0, 1, 6,
  1, 78, 25, 0, 0, 19, 64, 11, 1, 13, 17, 38, 1, 3, 15, 0, 3, 5, 37, 1, 43, 53,
  0, 43, 53, 0, 255, 255, 0, 225, 254, 57, 3, 233, 5, 182, 2, 38, 0, 44, 0, 0,
  1, 6, 1, 81, 8, 0, 0, 14, 183, 1, 1, 9, 18, 12, 1, 0, 37, 1, 43, 53, 0, 53,
  255, 255, 0, 197, 254, 57, 4, 51, 6, 14, 2, 38, 0, 76, 0, 0, 1, 6, 1, 81, 25,
  0, 0, 14, 183, 2, 2, 3, 25, 19, 16, 14, 37, 1, 43, 53, 0, 53, 255, 255, 0,
  225, 0, 0, 3, 233, 7, 55, 2, 38, 0, 44, 0, 0, 1, 7, 1, 79, 0, 0, 1, 82, 0, 19,
  64, 11, 1, 16, 5, 38, 1, 1, 18, 14, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 0, 1,
  0, 197, 0, 0, 4, 51, 4, 74, 0, 9, 0, 41, 64, 21, 5, 4, 71, 8, 1, 86, 9, 1, 9,
  9, 10, 11, 4, 9, 78, 7, 21, 0, 78, 2, 15, 0, 63, 225, 63, 225, 50, 17, 18, 1,
  57, 47, 93, 51, 51, 225, 50, 49, 48, 1, 37, 53, 33, 17, 5, 21, 33, 53, 37, 2,
  29, 254, 243, 1, 195, 1, 96, 252, 146, 1, 88, 3, 186, 21, 123, 252, 69, 20,
  123, 123, 20, 0, 0, 2, 0, 156, 255, 236, 4, 35, 5, 182, 0, 3, 0, 15, 0, 66,
  64, 40, 2, 90, 1, 10, 90, 11, 31, 4, 1, 159, 11, 175, 11, 2, 0, 1, 224, 1,
  240, 1, 3, 1, 4, 11, 11, 4, 1, 3, 16, 17, 7, 96, 5, 14, 19, 10, 1, 3, 0, 18,
  0, 63, 63, 51, 63, 51, 225, 17, 18, 1, 23, 57, 47, 47, 47, 93, 93, 93, 16,
  225, 16, 225, 49, 48, 51, 17, 51, 17, 55, 53, 22, 51, 50, 17, 17, 51, 17, 16,
  33, 34, 156, 186, 150, 93, 93, 194, 187, 254, 147, 133, 5, 182, 250, 74, 23,
  163, 45, 1, 27, 4, 14, 251, 254, 254, 56, 0, 0, 4, 0, 188, 254, 20, 4, 14, 6,
  14, 0, 8, 0, 17, 0, 21, 0, 36, 0, 88, 64, 50, 2, 20, 71, 21, 7, 21, 16, 27,
  71, 32, 11, 32, 0, 30, 1, 0, 22, 1, 0, 21, 1, 21, 22, 30, 32, 32, 30, 22, 21,
  4, 37, 38, 25, 80, 23, 35, 27, 28, 78, 18, 30, 15, 21, 21, 14, 5, 83, 9, 0, 0,
  0, 63, 50, 229, 50, 63, 63, 51, 225, 63, 51, 225, 17, 18, 1, 23, 57, 47, 47,
  47, 47, 93, 93, 93, 17, 51, 16, 225, 50, 17, 51, 16, 225, 50, 49, 48, 1, 50,
  21, 20, 6, 35, 34, 53, 52, 33, 50, 21, 20, 6, 35, 34, 53, 52, 1, 51, 17, 35,
  1, 53, 22, 51, 50, 53, 17, 39, 53, 33, 17, 20, 6, 35, 34, 1, 39, 106, 63, 43,
  107, 2, 228, 106, 63, 43, 107, 253, 150, 182, 182, 1, 43, 88, 102, 164, 215,
  1, 141, 170, 151, 123, 6, 14, 114, 58, 57, 115, 114, 114, 58, 57, 115, 114,
  254, 60, 251, 182, 254, 55, 154, 39, 215, 4, 57, 21, 123, 251, 65, 182, 193,
  0, 255, 255, 0, 137, 255, 236, 4, 190, 7, 115, 2, 38, 0, 45, 0, 0, 1, 7, 1,
  75, 1, 12, 1, 82, 0, 19, 64, 11, 1, 14, 5, 38, 1, 0, 20, 14, 7, 8, 37, 1, 43,
  53, 0, 43, 53, 0, 255, 255, 0, 135, 254, 20, 3, 198, 6, 33, 2, 38, 1, 75, 20,
  0, 1, 6, 2, 55, 0, 0, 0, 21, 180, 1, 25, 23, 39, 1, 184, 255, 116, 180, 16,
  26, 6, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 211, 254, 59, 4, 174, 5,
  182, 2, 38, 0, 46, 0, 0, 1, 6, 2, 57, 27, 0, 0, 21, 180, 1, 15, 20, 39, 1,
  184, 255, 193, 180, 13, 16, 5, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  215, 254, 59, 4, 139, 6, 20, 2, 38, 0, 78, 0, 0, 1, 6, 2, 57, 2, 0, 0, 21,
  180, 1, 17, 23, 39, 1, 184, 255, 183, 180, 15, 18, 10, 5, 37, 1, 43, 53, 0,
  43, 53, 0, 0, 1, 0, 215, 0, 0, 4, 139, 4, 74, 0, 14, 0, 119, 64, 11, 25, 6,
  41, 6, 57, 6, 3, 8, 6, 1, 4, 184, 255, 224, 64, 62, 16, 20, 72, 70, 4, 86, 4,
  2, 9, 2, 1, 9, 1, 1, 27, 7, 43, 7, 59, 7, 3, 7, 4, 5, 2, 3, 3, 6, 5, 32, 16,
  19, 72, 0, 5, 96, 5, 2, 5, 5, 16, 13, 0, 9, 70, 0, 10, 96, 10, 2, 10, 4, 7, 7,
  0, 2, 10, 5, 21, 11, 2, 15, 0, 63, 51, 63, 51, 18, 57, 57, 17, 51, 1, 47, 93,
  225, 50, 50, 17, 51, 47, 93, 43, 51, 51, 47, 51, 17, 57, 57, 49, 48, 0, 93, 1,
  93, 93, 93, 43, 93, 93, 1, 55, 1, 51, 1, 1, 35, 1, 7, 17, 35, 17, 51, 17, 3,
  1, 127, 137, 1, 146, 213, 254, 18, 2, 10, 213, 254, 86, 129, 180, 180, 16, 1,
  252, 166, 1, 168, 254, 2, 253, 180, 1, 213, 82, 254, 125, 4, 74, 254, 221,
  254, 213, 0, 255, 255, 0, 233, 0, 0, 4, 31, 7, 115, 2, 38, 0, 47, 0, 0, 1, 7,
  0, 118, 255, 101, 1, 82, 0, 21, 180, 1, 12, 5, 38, 1, 184, 255, 72, 180, 6, 9,
  0, 4, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 188, 0, 0, 4, 43, 7, 172, 2,
  38, 0, 79, 0, 0, 1, 7, 0, 118, 0, 78, 1, 139, 0, 19, 64, 11, 1, 16, 2, 38, 1,
  65, 10, 13, 7, 5, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 233, 254, 59, 4,
  31, 5, 182, 2, 38, 0, 47, 0, 0, 1, 6, 2, 57, 8, 0, 0, 21, 180, 1, 8, 20, 39,
  1, 184, 255, 234, 180, 6, 9, 0, 4, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  188, 254, 59, 4, 43, 6, 20, 2, 38, 0, 79, 0, 0, 1, 6, 2, 57, 234, 0, 0, 21,
  180, 1, 12, 23, 39, 1, 184, 255, 221, 180, 10, 13, 7, 5, 37, 1, 43, 53, 0, 43,
  53, 0, 255, 255, 0, 233, 0, 0, 4, 31, 5, 183, 2, 38, 0, 47, 0, 0, 1, 7, 2, 56,
  1, 0, 255, 163, 0, 14, 183, 1, 1, 226, 6, 10, 0, 4, 37, 1, 43, 53, 0, 53, 255,
  255, 0, 188, 0, 0, 4, 82, 6, 20, 2, 38, 0, 79, 0, 0, 1, 7, 2, 56, 1, 115, 0,
  0, 0, 17, 177, 1, 1, 184, 1, 102, 180, 10, 14, 7, 5, 37, 1, 43, 53, 0, 53, 0,
  255, 255, 0, 233, 0, 0, 4, 31, 5, 182, 2, 38, 0, 47, 0, 0, 1, 7, 1, 79, 0,
  242, 253, 148, 0, 14, 183, 1, 1, 212, 12, 8, 0, 4, 37, 1, 43, 53, 0, 53, 255,
  255, 0, 188, 0, 0, 4, 55, 6, 20, 2, 38, 0, 79, 0, 0, 1, 7, 1, 79, 1, 102, 253,
  56, 0, 21, 180, 1, 1, 127, 16, 1, 184, 1, 89, 180, 16, 12, 7, 5, 37, 1, 43,
  93, 53, 0, 53, 0, 0, 1, 0, 72, 0, 0, 4, 68, 5, 182, 0, 13, 0, 125, 64, 54, 10,
  1, 2, 9, 2, 7, 4, 3, 8, 3, 121, 8, 137, 8, 153, 8, 3, 10, 8, 26, 8, 42, 8, 3,
  118, 2, 134, 2, 150, 2, 3, 5, 2, 21, 2, 37, 2, 3, 9, 9, 0, 13, 15, 7, 11, 90,
  0, 3, 4, 3, 0, 0, 1, 0, 184, 255, 192, 64, 21, 12, 15, 72, 0, 1, 10, 4, 7, 4,
  2, 8, 2, 8, 2, 0, 5, 3, 11, 95, 0, 18, 0, 63, 225, 63, 18, 57, 57, 47, 47, 18,
  23, 57, 1, 47, 43, 93, 51, 51, 47, 16, 225, 50, 16, 206, 17, 57, 47, 49, 48,
  93, 93, 93, 93, 16, 125, 135, 4, 196, 196, 16, 135, 196, 196, 33, 17, 7, 39,
  55, 17, 51, 17, 37, 23, 5, 17, 33, 21, 1, 14, 125, 73, 198, 187, 1, 43, 78,
  254, 135, 2, 123, 1, 236, 78, 125, 125, 3, 30, 253, 88, 189, 125, 238, 254,
  70, 166, 0, 0, 1, 0, 188, 0, 0, 4, 43, 6, 20, 0, 17, 0, 141, 64, 22, 105, 11,
  1, 102, 3, 1, 11, 0, 1, 10, 1, 8, 3, 2, 9, 2, 10, 24, 13, 22, 72, 2, 184, 255,
  232, 64, 60, 13, 22, 72, 13, 111, 10, 127, 10, 2, 10, 10, 8, 12, 71, 17, 3, 5,
  16, 3, 17, 64, 2, 208, 2, 224, 2, 3, 2, 2, 93, 17, 1, 79, 17, 1, 17, 17, 18,
  19, 17, 12, 78, 14, 0, 11, 3, 8, 4, 1, 9, 1, 9, 1, 6, 14, 21, 4, 78, 6, 0, 0,
  63, 225, 63, 18, 57, 57, 47, 47, 18, 23, 57, 16, 225, 50, 17, 18, 1, 57, 47,
  93, 93, 51, 47, 93, 17, 23, 51, 16, 225, 50, 50, 47, 93, 50, 49, 48, 0, 43,
  43, 16, 125, 135, 196, 196, 16, 135, 196, 196, 0, 93, 93, 1, 7, 39, 55, 17,
  37, 53, 33, 17, 55, 23, 7, 17, 5, 21, 33, 53, 37, 2, 20, 141, 78, 219, 254,
  244, 1, 195, 164, 77, 241, 1, 96, 252, 145, 1, 88, 2, 80, 92, 121, 143, 2,
  137, 21, 122, 253, 95, 108, 121, 159, 253, 200, 20, 123, 123, 20, 0, 255, 255,
  0, 135, 0, 0, 4, 68, 7, 115, 2, 38, 0, 49, 0, 0, 1, 7, 0, 118, 0, 98, 1, 82,
  0, 19, 64, 11, 1, 22, 5, 38, 1, 99, 16, 19, 7, 0, 37, 1, 43, 53, 0, 43, 53, 0,
  255, 255, 0, 160, 0, 0, 4, 45, 6, 33, 2, 38, 0, 81, 0, 0, 1, 6, 0, 118, 111,
  0, 0, 19, 64, 11, 1, 23, 17, 38, 1, 111, 17, 20, 7, 15, 37, 1, 43, 53, 0, 43,
  53, 0, 255, 255, 0, 135, 254, 59, 4, 68, 5, 182, 2, 38, 0, 49, 0, 0, 1, 6, 2,
  57, 206, 0, 0, 21, 180, 1, 18, 20, 39, 1, 184, 255, 207, 180, 16, 19, 7, 0,
  37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160, 254, 59, 4, 45, 4, 94, 2, 38,
  0, 81, 0, 0, 1, 6, 2, 57, 228, 0, 0, 21, 180, 1, 19, 23, 39, 1, 184, 255, 228,
  180, 17, 20, 7, 15, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 135, 0, 0, 4,
  68, 7, 115, 2, 38, 0, 49, 0, 0, 1, 7, 1, 76, 255, 253, 1, 82, 0, 21, 180, 1,
  20, 5, 38, 1, 184, 255, 254, 180, 24, 16, 7, 0, 37, 1, 43, 53, 0, 43, 53, 0,
  255, 255, 0, 160, 0, 0, 4, 45, 6, 33, 2, 38, 0, 81, 0, 0, 1, 6, 1, 76, 12, 0,
  0, 19, 64, 11, 1, 21, 17, 38, 1, 12, 25, 17, 7, 15, 37, 1, 43, 53, 0, 43, 53,
  0, 0, 2, 255, 240, 0, 0, 4, 106, 5, 182, 0, 6, 0, 24, 0, 55, 64, 30, 7, 71,
  24, 26, 17, 13, 71, 47, 14, 1, 14, 6, 1, 252, 3, 4, 17, 10, 80, 21, 16, 15,
  15, 24, 14, 21, 3, 253, 6, 0, 0, 63, 237, 63, 51, 63, 63, 225, 50, 1, 47, 51,
  237, 50, 47, 93, 225, 50, 16, 222, 225, 49, 48, 1, 23, 6, 3, 35, 54, 19, 1,
  17, 16, 35, 32, 17, 17, 35, 17, 51, 23, 51, 54, 54, 51, 32, 17, 17, 1, 27, 14,
  50, 126, 137, 60, 40, 3, 96, 219, 254, 227, 182, 148, 26, 10, 42, 173, 103, 1,
  110, 5, 182, 22, 197, 254, 230, 242, 1, 3, 250, 74, 2, 195, 1, 4, 254, 114,
  253, 199, 4, 74, 148, 78, 90, 254, 111, 253, 51, 0, 1, 0, 135, 254, 123, 4,
  68, 5, 182, 0, 24, 0, 98, 181, 24, 8, 14, 24, 72, 7, 184, 255, 240, 64, 54,
  16, 24, 72, 69, 7, 85, 7, 101, 7, 3, 52, 7, 1, 21, 7, 37, 7, 2, 6, 7, 1, 19,
  19, 5, 24, 8, 12, 251, 13, 26, 7, 1, 4, 251, 0, 5, 224, 5, 240, 5, 3, 5, 22,
  95, 20, 17, 12, 0, 6, 3, 24, 8, 5, 18, 0, 63, 51, 51, 63, 51, 51, 47, 51, 225,
  1, 47, 93, 225, 50, 50, 16, 222, 225, 50, 50, 17, 57, 47, 49, 48, 93, 93, 93,
  93, 43, 43, 1, 35, 18, 21, 17, 35, 17, 51, 1, 51, 2, 53, 17, 51, 17, 20, 6,
  35, 34, 39, 53, 22, 51, 50, 53, 1, 41, 8, 18, 172, 213, 2, 66, 10, 18, 174,
  200, 187, 94, 62, 77, 81, 211, 4, 186, 254, 235, 140, 252, 231, 5, 182, 251,
  152, 1, 18, 129, 2, 213, 250, 94, 198, 211, 24, 160, 20, 225, 0, 0, 1, 0, 160,
  254, 20, 4, 45, 4, 94, 0, 24, 0, 60, 64, 35, 14, 14, 1, 19, 71, 144, 10, 160,
  10, 2, 10, 26, 4, 0, 71, 0, 1, 176, 1, 2, 1, 17, 80, 15, 12, 27, 4, 22, 80, 7,
  16, 2, 15, 1, 21, 0, 63, 63, 63, 225, 50, 63, 51, 225, 1, 47, 93, 225, 50, 16,
  222, 93, 225, 17, 57, 47, 49, 48, 33, 35, 17, 51, 23, 51, 54, 51, 32, 17, 17,
  16, 33, 34, 39, 53, 22, 51, 50, 53, 17, 16, 35, 32, 17, 1, 86, 182, 147, 27,
  10, 103, 233, 1, 133, 254, 221, 81, 52, 54, 61, 127, 238, 254, 205, 4, 74,
  148, 168, 254, 111, 252, 149, 254, 178, 25, 148, 21, 170, 3, 109, 1, 4, 254,
  114, 0, 255, 255, 0, 84, 255, 236, 4, 123, 6, 193, 2, 38, 0, 50, 0, 0, 1, 7,
  1, 77, 0, 4, 1, 82, 0, 19, 64, 11, 2, 22, 5, 38, 2, 2, 20, 21, 2, 7, 37, 1,
  43, 53, 0, 43, 53, 0, 255, 255, 0, 115, 255, 236, 4, 88, 5, 111, 2, 38, 0, 82,
  0, 0, 1, 6, 1, 77, 0, 0, 0, 19, 64, 11, 2, 22, 17, 38, 2, 0, 20, 21, 3, 9, 37,
  1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 84, 255, 236, 4, 123, 7, 64, 2, 38, 0,
  50, 0, 0, 1, 7, 1, 78, 255, 255, 1, 82, 0, 21, 180, 2, 23, 5, 38, 2, 184, 255,
  254, 180, 25, 20, 2, 7, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 115, 255,
  236, 4, 88, 5, 238, 2, 38, 0, 82, 0, 0, 1, 6, 1, 78, 0, 0, 0, 19, 64, 11, 2,
  23, 17, 38, 2, 0, 25, 20, 3, 9, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 84,
  255, 236, 4, 123, 7, 115, 2, 38, 0, 50, 0, 0, 1, 7, 1, 83, 0, 80, 1, 82, 0,
  23, 64, 13, 3, 2, 26, 5, 38, 3, 2, 78, 20, 31, 2, 7, 37, 1, 43, 53, 53, 0, 43,
  53, 53, 0, 255, 255, 0, 115, 255, 236, 4, 88, 6, 33, 2, 38, 0, 82, 0, 0, 1, 6,
  1, 83, 82, 0, 0, 23, 64, 13, 3, 2, 26, 17, 38, 3, 2, 82, 20, 31, 3, 9, 37, 1,
  43, 53, 53, 0, 43, 53, 53, 0, 0, 2, 0, 20, 255, 236, 4, 203, 5, 205, 0, 19, 0,
  28, 0, 73, 64, 41, 14, 18, 90, 16, 20, 1, 20, 16, 20, 16, 6, 12, 0, 30, 25,
  90, 6, 17, 95, 104, 14, 1, 14, 14, 19, 12, 95, 11, 3, 23, 95, 8, 4, 27, 95, 4,
  19, 19, 95, 0, 18, 0, 63, 225, 63, 225, 63, 225, 63, 225, 18, 57, 47, 93, 225,
  1, 47, 225, 16, 206, 50, 17, 57, 57, 47, 47, 93, 225, 50, 49, 48, 33, 33, 7,
  6, 35, 32, 17, 16, 33, 50, 23, 33, 21, 33, 17, 33, 21, 33, 17, 33, 37, 17, 38,
  35, 32, 17, 16, 33, 50, 4, 203, 253, 194, 48, 51, 46, 254, 24, 2, 0, 82, 72,
  2, 29, 254, 114, 1, 103, 254, 153, 1, 142, 253, 192, 58, 73, 254, 201, 1, 53,
  70, 10, 10, 2, 243, 2, 238, 23, 164, 254, 60, 162, 253, 248, 12, 4, 88, 33,
  253, 180, 253, 178, 0, 0, 3, 0, 57, 255, 236, 4, 150, 4, 94, 0, 26, 0, 36, 0,
  41, 0, 108, 64, 41, 10, 0, 41, 17, 71, 16, 29, 64, 29, 80, 29, 112, 29, 128,
  29, 176, 29, 192, 29, 208, 29, 8, 29, 29, 5, 37, 70, 22, 16, 64, 10, 22, 72,
  11, 16, 1, 16, 43, 34, 71, 5, 184, 255, 192, 64, 24, 18, 24, 72, 5, 17, 80,
  41, 41, 27, 39, 10, 31, 80, 12, 8, 16, 19, 0, 27, 80, 24, 21, 2, 22, 0, 63,
  51, 51, 225, 50, 50, 63, 51, 225, 50, 50, 18, 57, 47, 225, 1, 47, 43, 225, 16,
  222, 93, 43, 50, 225, 17, 57, 47, 93, 225, 50, 57, 57, 49, 48, 37, 6, 35, 34,
  2, 17, 16, 18, 51, 50, 23, 54, 51, 50, 18, 21, 21, 33, 18, 51, 50, 55, 21, 6,
  35, 34, 38, 37, 50, 17, 16, 35, 34, 6, 21, 20, 22, 1, 16, 35, 34, 3, 2, 139,
  88, 178, 146, 182, 176, 154, 171, 89, 84, 158, 131, 154, 254, 73, 3, 186, 108,
  96, 94, 123, 87, 143, 254, 228, 168, 170, 90, 78, 79, 2, 179, 123, 125, 12,
  201, 221, 1, 51, 1, 8, 1, 12, 1, 43, 217, 217, 254, 245, 224, 113, 254, 137,
  76, 162, 73, 118, 33, 1, 154, 1, 170, 206, 210, 211, 209, 2, 19, 1, 49, 254,
  207, 0, 255, 255, 0, 186, 0, 0, 4, 147, 7, 115, 2, 38, 0, 53, 0, 0, 1, 7, 0,
  118, 0, 29, 1, 82, 0, 21, 180, 2, 27, 5, 38, 2, 184, 255, 221, 180, 21, 24, 2,
  9, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 1, 8, 0, 0, 4, 35, 6, 33, 2, 38, 0,
  85, 0, 0, 1, 6, 0, 118, 92, 0, 0, 19, 64, 11, 1, 23, 17, 38, 1, 45, 17, 20, 8,
  0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 186, 254, 59, 4, 147, 5, 182, 2,
  38, 0, 53, 0, 0, 1, 6, 2, 57, 253, 0, 0, 21, 180, 2, 23, 20, 39, 2, 184, 255,
  189, 180, 21, 24, 2, 9, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 187, 254,
  59, 4, 35, 4, 94, 2, 38, 0, 85, 0, 0, 1, 7, 2, 57, 254, 216, 0, 0, 0, 38, 64,
  17, 1, 19, 23, 39, 1, 95, 17, 1, 63, 17, 1, 31, 17, 1, 15, 17, 1, 184, 254,
  169, 180, 17, 20, 8, 0, 37, 1, 43, 93, 93, 93, 93, 53, 0, 43, 53, 255, 255, 0,
  186, 0, 0, 4, 147, 7, 115, 2, 38, 0, 53, 0, 0, 1, 7, 1, 76, 255, 226, 1, 82,
  0, 21, 180, 2, 25, 5, 38, 2, 184, 255, 162, 180, 29, 21, 2, 9, 37, 1, 43, 53,
  0, 43, 53, 0, 255, 255, 1, 8, 0, 0, 4, 35, 6, 33, 2, 38, 0, 85, 0, 0, 1, 6, 1,
  76, 12, 0, 0, 21, 180, 1, 21, 17, 38, 1, 184, 255, 221, 180, 25, 17, 8, 0, 37,
  1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 141, 255, 236, 4, 63, 7, 115, 2, 38, 0,
  54, 0, 0, 1, 7, 0, 118, 0, 96, 1, 82, 0, 19, 64, 11, 1, 38, 5, 38, 1, 96, 32,
  35, 0, 27, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 203, 255, 236, 4, 2, 6,
  33, 2, 38, 0, 86, 0, 0, 1, 6, 0, 118, 94, 0, 0, 19, 64, 11, 1, 38, 17, 38, 1,
  94, 32, 35, 0, 27, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 141, 255, 236, 4,
  63, 7, 115, 2, 38, 0, 54, 0, 0, 1, 7, 1, 75, 0, 20, 1, 82, 0, 19, 64, 11, 1,
  32, 5, 38, 1, 20, 38, 32, 0, 27, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  203, 255, 236, 4, 2, 6, 33, 2, 38, 0, 86, 0, 0, 1, 6, 1, 75, 23, 0, 0, 19, 64,
  11, 1, 32, 17, 38, 1, 23, 38, 32, 0, 27, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 141, 254, 20, 4, 63, 5, 203, 2, 38, 0, 54, 0, 0, 1, 6, 0, 122, 234, 0,
  0, 14, 185, 0, 1, 255, 235, 180, 32, 44, 0, 27, 37, 1, 43, 53, 255, 255, 0,
  203, 254, 20, 4, 2, 4, 94, 2, 38, 0, 86, 0, 0, 1, 6, 0, 122, 247, 0, 0, 17,
  177, 1, 1, 184, 255, 247, 180, 32, 44, 0, 27, 37, 1, 43, 53, 0, 53, 0, 255,
  255, 0, 141, 255, 236, 4, 63, 7, 115, 2, 38, 0, 54, 0, 0, 1, 7, 1, 76, 0, 31,
  1, 82, 0, 19, 64, 11, 1, 36, 5, 38, 1, 31, 40, 32, 0, 27, 37, 1, 43, 53, 0,
  43, 53, 0, 255, 255, 0, 203, 255, 236, 4, 2, 6, 33, 2, 38, 0, 86, 0, 0, 1, 6,
  1, 76, 10, 0, 0, 19, 64, 11, 1, 36, 17, 38, 1, 10, 40, 32, 0, 27, 37, 1, 43,
  53, 0, 43, 53, 0, 255, 255, 0, 102, 254, 59, 4, 100, 5, 182, 2, 38, 0, 55, 0,
  0, 1, 6, 2, 57, 222, 0, 0, 21, 180, 1, 10, 20, 39, 1, 184, 255, 223, 180, 8,
  11, 3, 5, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 139, 254, 59, 4, 2, 5,
  111, 2, 38, 0, 87, 0, 0, 1, 6, 2, 57, 6, 0, 0, 19, 64, 11, 1, 22, 23, 39, 1,
  37, 20, 23, 7, 13, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 102, 0, 0, 4,
  100, 7, 115, 2, 38, 0, 55, 0, 0, 1, 7, 1, 76, 255, 255, 1, 82, 0, 19, 64, 11,
  1, 12, 5, 38, 1, 0, 16, 8, 3, 5, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  139, 255, 236, 4, 16, 6, 20, 2, 38, 0, 87, 0, 0, 1, 7, 2, 56, 1, 49, 0, 0, 0,
  17, 177, 1, 1, 184, 1, 81, 180, 20, 24, 7, 13, 37, 1, 43, 53, 0, 53, 0, 0, 1,
  0, 102, 0, 0, 4, 100, 5, 182, 0, 15, 0, 89, 64, 51, 9, 9, 11, 5, 5, 7, 11, 90,
  12, 14, 14, 2, 0, 208, 12, 1, 162, 12, 1, 147, 12, 1, 3, 142, 12, 1, 4, 99,
  12, 1, 5, 16, 12, 80, 12, 2, 12, 10, 14, 96, 7, 15, 15, 3, 11, 18, 6, 2, 95,
  3, 3, 0, 63, 225, 50, 63, 18, 57, 47, 51, 225, 50, 1, 47, 93, 95, 93, 95, 93,
  95, 93, 93, 93, 51, 196, 57, 47, 16, 241, 50, 192, 47, 17, 57, 47, 49, 48, 1,
  17, 33, 53, 33, 21, 33, 17, 33, 21, 33, 17, 35, 17, 33, 53, 2, 8, 254, 94, 3,
  254, 254, 95, 1, 38, 254, 218, 187, 254, 215, 3, 51, 1, 223, 164, 164, 254,
  33, 149, 253, 98, 2, 158, 149, 0, 1, 0, 139, 255, 236, 4, 2, 5, 111, 0, 27, 0,
  112, 64, 67, 22, 18, 20, 16, 24, 71, 5, 7, 5, 32, 11, 1, 11, 11, 13, 9, 47, 5,
  63, 5, 127, 5, 143, 5, 207, 5, 223, 5, 6, 0, 5, 1, 5, 5, 28, 29, 18, 18, 127,
  1, 143, 1, 175, 1, 3, 1, 29, 6, 23, 78, 9, 20, 20, 26, 10, 19, 78, 15, 13, 12,
  16, 15, 26, 80, 0, 3, 22, 0, 63, 51, 225, 63, 51, 51, 51, 225, 50, 18, 57, 47,
  51, 225, 50, 1, 16, 206, 93, 50, 47, 17, 18, 57, 47, 93, 93, 51, 51, 51, 47,
  93, 18, 57, 16, 225, 50, 50, 17, 57, 49, 48, 37, 21, 6, 35, 32, 17, 53, 35,
  53, 51, 53, 33, 53, 37, 19, 51, 17, 33, 21, 33, 21, 33, 21, 33, 21, 20, 51,
  50, 3, 252, 130, 122, 254, 150, 162, 162, 254, 245, 1, 11, 77, 105, 1, 182,
  254, 74, 1, 51, 254, 205, 192, 93, 150, 138, 32, 1, 88, 251, 138, 248, 94, 49,
  1, 31, 254, 219, 137, 248, 138, 251, 195, 0, 255, 255, 0, 125, 255, 236, 4,
  80, 7, 53, 2, 38, 0, 56, 0, 0, 1, 7, 1, 82, 0, 6, 1, 82, 0, 19, 64, 11, 1, 15,
  5, 38, 1, 5, 16, 25, 6, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160, 255,
  236, 4, 45, 5, 227, 2, 38, 0, 88, 0, 0, 1, 6, 1, 82, 2, 0, 0, 19, 64, 11, 1,
  18, 17, 38, 1, 1, 19, 28, 6, 16, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  125, 255, 236, 4, 80, 6, 193, 2, 38, 0, 56, 0, 0, 1, 7, 1, 77, 0, 0, 1, 82, 0,
  21, 180, 1, 17, 5, 38, 1, 184, 255, 255, 180, 15, 16, 6, 0, 37, 1, 43, 53, 0,
  43, 53, 0, 255, 255, 0, 160, 255, 236, 4, 45, 5, 111, 2, 38, 0, 88, 0, 0, 1,
  6, 1, 77, 2, 0, 0, 19, 64, 11, 1, 20, 17, 38, 1, 1, 18, 19, 6, 16, 37, 1, 43,
  53, 0, 43, 53, 0, 255, 255, 0, 125, 255, 236, 4, 80, 7, 64, 2, 38, 0, 56, 0,
  0, 1, 7, 1, 78, 255, 255, 1, 82, 0, 21, 180, 1, 18, 5, 38, 1, 184, 255, 255,
  180, 20, 15, 6, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160, 255, 236, 4,
  45, 5, 238, 2, 38, 0, 88, 0, 0, 1, 6, 1, 78, 0, 0, 0, 19, 64, 11, 1, 21, 17,
  38, 1, 0, 23, 18, 6, 16, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 125, 255,
  236, 4, 80, 7, 217, 2, 38, 0, 56, 0, 0, 1, 7, 1, 80, 0, 2, 1, 82, 0, 23, 64,
  13, 2, 1, 15, 5, 38, 2, 1, 1, 18, 24, 6, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53,
  0, 255, 255, 0, 160, 255, 236, 4, 45, 6, 135, 2, 38, 0, 88, 0, 0, 1, 6, 1, 80,
  253, 0, 0, 25, 182, 2, 1, 18, 17, 38, 2, 1, 184, 255, 252, 180, 21, 27, 6, 16,
  37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 125, 255, 236, 4, 80, 7,
  115, 2, 38, 0, 56, 0, 0, 1, 7, 1, 83, 0, 76, 1, 82, 0, 23, 64, 13, 2, 1, 21,
  5, 38, 2, 1, 75, 15, 26, 6, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255,
  0, 160, 255, 236, 4, 45, 6, 33, 2, 38, 0, 88, 0, 0, 1, 6, 1, 83, 80, 0, 0, 23,
  64, 13, 2, 1, 24, 17, 38, 2, 1, 79, 18, 29, 6, 16, 37, 1, 43, 53, 53, 0, 43,
  53, 53, 0, 255, 255, 0, 125, 254, 57, 4, 80, 5, 184, 2, 38, 0, 56, 0, 0, 1, 6,
  1, 81, 27, 0, 0, 14, 183, 1, 1, 27, 21, 15, 6, 0, 37, 1, 43, 53, 0, 53, 255,
  255, 0, 160, 254, 57, 4, 100, 4, 74, 2, 38, 0, 88, 0, 0, 1, 7, 1, 81, 1, 53,
  0, 0, 0, 23, 64, 14, 1, 1, 16, 26, 1, 0, 26, 1, 0, 26, 26, 0, 0, 37, 1, 43,
  93, 93, 53, 0, 53, 0, 255, 255, 0, 2, 0, 0, 4, 203, 7, 115, 2, 38, 0, 58, 0,
  0, 1, 7, 1, 75, 0, 2, 1, 82, 0, 19, 64, 11, 1, 26, 5, 38, 1, 2, 32, 26, 18, 8,
  37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 255, 252, 0, 0, 4, 209, 6, 33, 2, 38,
  0, 90, 0, 0, 1, 6, 1, 75, 253, 0, 0, 21, 180, 1, 26, 17, 38, 1, 184, 255, 253,
  180, 32, 26, 7, 24, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 33, 0, 0, 4,
  170, 7, 115, 2, 38, 0, 60, 0, 0, 1, 7, 1, 75, 255, 255, 1, 82, 0, 19, 64, 11,
  1, 9, 5, 38, 1, 0, 15, 9, 7, 2, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 82,
  254, 20, 4, 121, 6, 33, 2, 38, 0, 92, 0, 0, 1, 6, 1, 75, 2, 0, 0, 19, 64, 11,
  1, 23, 17, 38, 1, 3, 29, 23, 0, 9, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  33, 0, 0, 4, 170, 7, 43, 2, 38, 0, 60, 0, 0, 1, 7, 0, 106, 0, 2, 1, 82, 0, 23,
  64, 13, 2, 1, 13, 5, 38, 2, 1, 2, 15, 19, 7, 2, 37, 1, 43, 53, 53, 0, 43, 53,
  53, 0, 255, 255, 0, 102, 0, 0, 4, 100, 7, 115, 2, 38, 0, 61, 0, 0, 1, 7, 0,
  118, 0, 57, 1, 82, 0, 19, 64, 11, 1, 16, 5, 38, 1, 58, 10, 13, 1, 0, 37, 1,
  43, 53, 0, 43, 53, 0, 255, 255, 0, 182, 0, 0, 4, 20, 6, 33, 2, 38, 0, 93, 0,
  0, 1, 6, 0, 118, 78, 0, 0, 19, 64, 11, 1, 16, 17, 38, 1, 79, 10, 13, 1, 0, 37,
  1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 102, 0, 0, 4, 100, 7, 55, 2, 38, 0, 61,
  0, 0, 1, 7, 1, 79, 0, 16, 1, 82, 0, 19, 64, 11, 1, 14, 5, 38, 1, 17, 16, 12,
  1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 182, 0, 0, 4, 20, 5, 229, 2,
  38, 0, 93, 0, 0, 1, 6, 1, 79, 16, 0, 0, 19, 64, 11, 1, 14, 17, 38, 1, 17, 16,
  12, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 102, 0, 0, 4, 100, 7, 115,
  2, 38, 0, 61, 0, 0, 1, 7, 1, 76, 255, 255, 1, 82, 0, 19, 64, 11, 1, 14, 5, 38,
  1, 0, 18, 10, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 182, 0, 0, 4,
  20, 6, 33, 2, 38, 0, 93, 0, 0, 1, 6, 1, 76, 12, 0, 0, 19, 64, 11, 1, 14, 17,
  38, 1, 13, 18, 10, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 0, 1, 1, 100, 0, 0, 3,
  250, 6, 31, 0, 13, 0, 46, 64, 28, 7, 71, 79, 8, 95, 8, 191, 8, 239, 8, 255, 8,
  5, 8, 8, 14, 32, 0, 1, 0, 15, 3, 80, 1, 12, 1, 7, 21, 0, 63, 63, 51, 225, 1,
  16, 206, 93, 18, 57, 47, 93, 225, 49, 48, 1, 7, 38, 35, 34, 6, 21, 17, 35, 17,
  52, 54, 51, 50, 3, 250, 41, 105, 122, 119, 92, 183, 180, 209, 125, 5, 252,
  143, 28, 96, 119, 251, 78, 4, 176, 190, 177, 0, 0, 1, 0, 215, 254, 20, 3, 246,
  5, 203, 0, 31, 0, 82, 64, 42, 22, 30, 22, 30, 33, 0, 14, 7, 14, 7, 32, 29, 0,
  111, 13, 14, 14, 16, 31, 13, 1, 13, 13, 32, 33, 13, 0, 117, 16, 29, 29, 9, 25,
  115, 23, 20, 7, 9, 115, 7, 4, 27, 0, 63, 51, 225, 63, 51, 225, 18, 57, 47, 51,
  225, 50, 17, 18, 1, 57, 47, 93, 51, 51, 47, 16, 225, 50, 18, 57, 57, 47, 47,
  17, 18, 57, 57, 47, 47, 49, 48, 1, 17, 20, 6, 35, 34, 39, 53, 22, 51, 50, 54,
  53, 17, 35, 53, 55, 53, 52, 54, 51, 50, 23, 7, 38, 35, 34, 6, 21, 21, 51, 21,
  2, 156, 153, 179, 51, 70, 59, 56, 92, 63, 194, 194, 153, 179, 97, 100, 47, 79,
  65, 92, 63, 245, 3, 68, 252, 63, 190, 177, 15, 153, 18, 102, 113, 3, 195, 75,
  68, 137, 190, 177, 37, 141, 28, 102, 113, 145, 137, 0, 255, 255, 0, 33, 0, 0,
  4, 172, 8, 115, 2, 38, 0, 36, 0, 0, 0, 38, 1, 80, 2, 125, 1, 7, 0, 118, 0, 72,
  2, 82, 0, 82, 64, 48, 4, 176, 40, 1, 96, 40, 1, 80, 40, 1, 64, 40, 1, 40, 68,
  3, 2, 239, 26, 1, 223, 26, 1, 80, 26, 1, 64, 26, 1, 32, 26, 1, 16, 26, 1, 0,
  26, 1, 26, 4, 30, 38, 41, 18, 24, 37, 3, 2, 184, 255, 255, 180, 18, 24, 4, 7,
  37, 1, 43, 53, 53, 43, 53, 0, 17, 93, 93, 93, 93, 93, 93, 93, 53, 53, 63, 93,
  93, 93, 93, 53, 255, 255, 0, 135, 255, 236, 4, 2, 8, 0, 2, 38, 0, 68, 0, 0, 0,
  38, 1, 80, 0, 0, 1, 7, 0, 118, 0, 94, 1, 223, 0, 72, 64, 49, 4, 240, 64, 1,
  239, 64, 1, 223, 64, 1, 207, 64, 1, 96, 64, 1, 31, 64, 1, 64, 3, 2, 240, 34,
  1, 224, 34, 1, 208, 34, 1, 34, 17, 38, 4, 30, 64, 60, 37, 43, 37, 3, 2, 33,
  37, 43, 8, 22, 37, 1, 43, 53, 53, 43, 53, 0, 43, 93, 93, 93, 53, 53, 17, 93,
  93, 93, 93, 93, 93, 53, 255, 255, 0, 0, 0, 0, 4, 186, 7, 115, 2, 38, 0, 136,
  0, 0, 1, 7, 0, 118, 0, 213, 1, 82, 0, 19, 64, 11, 2, 26, 5, 38, 2, 222, 20,
  23, 5, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 45, 255, 236, 4, 162, 6,
  33, 2, 38, 0, 168, 0, 0, 1, 6, 0, 118, 113, 0, 0, 19, 64, 11, 3, 58, 17, 38,
  3, 112, 52, 55, 32, 15, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 80, 255,
  180, 4, 133, 7, 115, 2, 38, 0, 154, 0, 0, 1, 7, 0, 118, 0, 57, 1, 82, 0, 19,
  64, 11, 3, 40, 5, 38, 3, 53, 34, 37, 2, 11, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 115, 255, 170, 4, 88, 6, 33, 2, 38, 0, 186, 0, 0, 1, 6, 0, 118, 80, 0,
  0, 19, 64, 11, 3, 42, 17, 38, 3, 81, 36, 39, 5, 15, 37, 1, 43, 53, 0, 43, 53,
  0, 255, 255, 0, 141, 254, 59, 4, 63, 5, 203, 2, 38, 0, 54, 0, 0, 1, 6, 2, 57,
  0, 0, 0, 19, 64, 11, 1, 34, 20, 39, 1, 0, 32, 35, 0, 27, 37, 1, 43, 53, 0, 43,
  53, 0, 255, 255, 0, 203, 254, 59, 4, 2, 4, 94, 2, 38, 0, 86, 0, 0, 1, 6, 2,
  57, 228, 0, 0, 21, 180, 1, 34, 23, 39, 1, 184, 255, 228, 180, 32, 35, 0, 27,
  37, 1, 43, 53, 0, 43, 53, 0, 0, 1, 1, 27, 4, 217, 3, 178, 6, 33, 0, 15, 0, 43,
  64, 21, 12, 11, 3, 3, 5, 6, 149, 1, 0, 0, 17, 3, 11, 146, 6, 15, 0, 95, 0, 2,
  0, 0, 47, 93, 50, 237, 57, 17, 1, 51, 47, 51, 228, 50, 57, 25, 47, 51, 51, 49,
  48, 1, 35, 38, 39, 6, 7, 35, 53, 54, 55, 54, 55, 51, 22, 23, 23, 3, 178, 121,
  85, 126, 133, 78, 120, 25, 34, 139, 37, 193, 37, 139, 59, 4, 217, 56, 130,
  136, 50, 27, 29, 38, 155, 79, 79, 155, 67, 0, 0, 1, 1, 27, 4, 217, 3, 178, 6,
  33, 0, 15, 0, 43, 64, 21, 5, 4, 12, 12, 10, 9, 149, 14, 15, 15, 17, 12, 14, 9,
  146, 15, 5, 95, 5, 2, 5, 0, 47, 93, 228, 50, 57, 17, 1, 51, 47, 51, 228, 50,
  57, 25, 47, 51, 51, 49, 48, 1, 6, 7, 6, 7, 35, 38, 39, 39, 53, 51, 22, 23, 54,
  55, 51, 3, 178, 25, 34, 141, 35, 193, 35, 141, 59, 120, 82, 129, 122, 89, 121,
  6, 6, 29, 38, 158, 76, 76, 158, 67, 27, 54, 133, 128, 59, 0, 0, 1, 1, 70, 4,
  217, 3, 133, 5, 111, 0, 3, 0, 65, 64, 24, 31, 1, 223, 1, 239, 1, 255, 1, 4, 1,
  1, 5, 112, 0, 128, 0, 208, 0, 224, 0, 240, 0, 5, 0, 184, 255, 192, 64, 17, 9,
  12, 72, 0, 0, 4, 1, 143, 15, 2, 1, 2, 64, 12, 24, 72, 2, 0, 47, 43, 93, 225,
  17, 1, 51, 47, 43, 93, 17, 51, 47, 93, 49, 48, 1, 33, 21, 33, 1, 70, 2, 63,
  253, 193, 5, 111, 150, 0, 1, 1, 57, 4, 217, 3, 147, 5, 238, 0, 11, 0, 76, 64,
  18, 6, 131, 0, 5, 16, 5, 32, 5, 96, 5, 112, 5, 128, 5, 160, 5, 7, 5, 184, 255,
  192, 64, 32, 21, 24, 72, 5, 5, 11, 131, 31, 0, 143, 0, 175, 0, 239, 0, 255, 0,
  5, 0, 0, 13, 11, 5, 148, 9, 143, 15, 3, 95, 3, 2, 3, 0, 47, 93, 225, 237, 50,
  17, 1, 51, 47, 93, 225, 51, 47, 43, 93, 225, 49, 48, 1, 6, 6, 35, 32, 3, 51,
  22, 22, 51, 50, 55, 3, 147, 9, 160, 136, 254, 232, 17, 109, 7, 79, 104, 181,
  10, 5, 238, 127, 150, 1, 21, 76, 49, 125, 0, 0, 1, 1, 252, 5, 0, 2, 209, 5,
  229, 0, 7, 0, 74, 64, 52, 230, 6, 1, 6, 133, 2, 219, 2, 1, 201, 2, 1, 173, 2,
  1, 137, 2, 1, 91, 2, 1, 66, 2, 1, 38, 2, 1, 27, 2, 1, 2, 9, 0, 147, 79, 4,
  111, 4, 127, 4, 159, 4, 175, 4, 207, 4, 223, 4, 239, 4, 8, 4, 0, 47, 93, 237,
  17, 1, 51, 93, 93, 93, 93, 93, 93, 93, 93, 16, 225, 93, 49, 48, 1, 50, 21, 20,
  35, 34, 53, 52, 2, 102, 107, 107, 106, 5, 229, 114, 115, 115, 114, 0, 0, 2, 1,
  131, 4, 217, 3, 72, 6, 135, 0, 11, 0, 22, 0, 141, 181, 164, 10, 180, 10, 2,
  10, 184, 255, 224, 64, 9, 12, 15, 72, 164, 8, 180, 8, 2, 8, 184, 255, 224, 64,
  24, 12, 15, 72, 171, 4, 187, 4, 2, 4, 32, 12, 15, 72, 171, 2, 187, 2, 2, 2,
  32, 12, 15, 72, 15, 184, 255, 240, 64, 42, 19, 24, 72, 15, 131, 0, 3, 16, 3,
  32, 3, 3, 3, 20, 16, 19, 24, 72, 20, 131, 9, 24, 12, 8, 21, 24, 72, 12, 140,
  15, 6, 31, 6, 47, 6, 127, 6, 207, 6, 5, 6, 17, 184, 255, 240, 64, 11, 21, 24,
  72, 17, 140, 15, 0, 95, 0, 2, 0, 0, 47, 93, 225, 43, 220, 93, 225, 43, 1, 16,
  222, 225, 43, 220, 93, 225, 43, 49, 48, 43, 93, 43, 93, 43, 93, 43, 93, 1, 34,
  38, 53, 52, 54, 51, 50, 22, 21, 20, 6, 3, 34, 6, 21, 20, 51, 50, 54, 53, 52,
  38, 2, 98, 102, 121, 121, 102, 101, 129, 127, 103, 49, 63, 112, 50, 63, 63, 4,
  217, 116, 99, 99, 116, 118, 95, 98, 119, 1, 72, 60, 53, 113, 60, 53, 53, 60,
  0, 0, 1, 1, 158, 254, 57, 3, 47, 0, 0, 0, 14, 0, 56, 64, 34, 45, 7, 61, 7, 77,
  7, 3, 5, 48, 11, 19, 72, 8, 9, 0, 11, 132, 79, 6, 95, 6, 2, 6, 6, 0, 0, 16, 8,
  13, 142, 32, 3, 1, 3, 0, 47, 93, 225, 47, 17, 1, 51, 47, 51, 47, 93, 225, 17,
  57, 57, 49, 48, 43, 93, 1, 21, 6, 35, 34, 38, 53, 52, 55, 51, 6, 21, 20, 51,
  50, 3, 47, 73, 83, 119, 126, 190, 131, 170, 127, 66, 254, 193, 113, 23, 109,
  94, 144, 108, 125, 113, 96, 0, 0, 1, 0, 254, 4, 217, 3, 205, 5, 227, 0, 17, 0,
  51, 64, 30, 0, 130, 0, 1, 144, 1, 176, 1, 192, 1, 4, 1, 1, 9, 130, 10, 10, 19,
  16, 143, 9, 3, 148, 7, 143, 0, 15, 12, 1, 12, 0, 47, 93, 51, 225, 253, 50,
  225, 17, 1, 51, 47, 225, 51, 47, 93, 225, 49, 48, 1, 35, 18, 51, 50, 23, 22,
  51, 50, 55, 51, 2, 35, 34, 39, 38, 35, 34, 1, 102, 104, 25, 186, 58, 103, 102,
  34, 80, 26, 105, 27, 184, 57, 100, 100, 40, 82, 4, 217, 1, 8, 56, 56, 114,
  254, 248, 57, 56, 0, 0, 2, 0, 246, 4, 217, 3, 213, 6, 33, 0, 7, 0, 15, 0, 67,
  64, 42, 14, 15, 134, 11, 6, 7, 134, 2, 135, 64, 3, 80, 3, 2, 3, 3, 10, 135,
  79, 11, 95, 11, 111, 11, 175, 11, 223, 11, 5, 11, 11, 17, 10, 2, 146, 14, 15,
  6, 95, 6, 2, 6, 0, 47, 93, 51, 237, 50, 17, 1, 51, 47, 93, 225, 51, 47, 93,
  225, 237, 50, 16, 237, 50, 49, 48, 19, 54, 55, 51, 21, 6, 7, 35, 37, 54, 55,
  51, 21, 6, 7, 35, 246, 94, 80, 198, 112, 160, 100, 1, 106, 87, 87, 199, 112,
  160, 101, 4, 244, 133, 168, 21, 173, 134, 27, 118, 183, 21, 173, 134, 0, 0, 1,
  1, 223, 4, 217, 2, 236, 6, 33, 0, 9, 0, 32, 64, 16, 8, 9, 9, 3, 133, 4, 4, 11,
  3, 146, 15, 8, 95, 8, 2, 8, 0, 47, 93, 237, 17, 1, 51, 47, 225, 51, 47, 51,
  49, 48, 1, 55, 54, 55, 51, 21, 20, 6, 7, 35, 1, 223, 30, 30, 10, 199, 99, 61,
  109, 4, 244, 107, 114, 80, 21, 16, 208, 83, 0, 3, 1, 43, 5, 12, 3, 160, 6,
  180, 0, 7, 0, 16, 0, 24, 0, 87, 64, 57, 6, 7, 2, 135, 3, 6, 7, 22, 7, 2, 7, 3,
  7, 3, 19, 10, 133, 0, 15, 16, 15, 32, 15, 224, 15, 240, 15, 5, 15, 15, 23,
  133, 19, 2, 146, 6, 6, 17, 8, 147, 21, 79, 13, 111, 13, 127, 13, 159, 13, 175,
  13, 207, 13, 223, 13, 7, 13, 0, 47, 93, 51, 237, 50, 57, 47, 237, 1, 47, 225,
  51, 47, 93, 225, 18, 57, 57, 47, 47, 93, 16, 225, 17, 51, 49, 48, 1, 54, 55,
  51, 21, 6, 7, 35, 39, 50, 21, 20, 6, 35, 34, 53, 52, 33, 50, 21, 20, 35, 34,
  53, 52, 2, 20, 50, 41, 206, 93, 122, 82, 137, 97, 56, 41, 96, 2, 20, 97, 97,
  96, 5, 135, 139, 162, 20, 164, 143, 108, 102, 49, 54, 103, 102, 102, 103, 103,
  102, 0, 255, 255, 0, 33, 0, 0, 4, 172, 5, 188, 2, 38, 0, 36, 0, 0, 1, 7, 1,
  84, 254, 69, 255, 151, 0, 24, 182, 2, 18, 3, 2, 16, 15, 1, 184, 254, 68, 180,
  15, 19, 4, 7, 37, 1, 43, 93, 53, 0, 63, 53, 0, 1, 1, 231, 2, 72, 2, 229, 3,
  94, 0, 7, 0, 34, 64, 20, 2, 150, 48, 6, 96, 6, 176, 6, 224, 6, 240, 6, 5, 6,
  6, 8, 9, 0, 155, 4, 0, 47, 237, 17, 18, 1, 57, 47, 93, 237, 49, 48, 1, 50, 21,
  20, 35, 34, 53, 52, 2, 102, 127, 127, 127, 3, 94, 139, 139, 139, 139, 0, 255,
  255, 255, 142, 0, 0, 4, 35, 5, 184, 2, 38, 0, 40, 0, 0, 1, 7, 1, 84, 253, 175,
  255, 151, 0, 33, 64, 13, 1, 15, 3, 1, 32, 12, 1, 16, 12, 1, 0, 12, 1, 184,
  253, 151, 180, 12, 16, 1, 0, 37, 1, 43, 93, 93, 93, 53, 0, 63, 53, 0, 255,
  255, 255, 101, 0, 0, 4, 70, 5, 184, 2, 38, 0, 43, 0, 0, 1, 7, 1, 84, 253, 134,
  255, 151, 0, 33, 64, 13, 1, 15, 3, 1, 32, 12, 1, 16, 12, 1, 0, 12, 1, 184,
  253, 133, 180, 12, 16, 5, 0, 37, 1, 43, 93, 93, 93, 53, 0, 63, 53, 0, 255,
  255, 255, 163, 0, 0, 3, 233, 5, 184, 2, 38, 0, 44, 0, 0, 1, 7, 1, 84, 253,
  196, 255, 151, 0, 24, 182, 1, 15, 3, 1, 0, 12, 1, 184, 253, 197, 180, 12, 16,
  1, 0, 37, 1, 43, 93, 53, 0, 63, 53, 255, 255, 255, 124, 255, 236, 4, 123, 5,
  205, 2, 38, 0, 50, 0, 0, 1, 7, 1, 84, 253, 157, 255, 151, 0, 20, 179, 2, 23,
  3, 2, 184, 253, 155, 180, 20, 24, 2, 7, 37, 1, 43, 53, 0, 63, 53, 255, 255,
  255, 19, 0, 0, 4, 170, 5, 184, 2, 38, 0, 60, 0, 0, 1, 7, 1, 84, 253, 52, 255,
  151, 0, 20, 179, 1, 12, 3, 1, 184, 253, 52, 180, 9, 13, 7, 2, 37, 1, 43, 53,
  0, 63, 53, 255, 255, 255, 122, 0, 0, 4, 135, 5, 205, 2, 38, 1, 118, 0, 0, 1,
  7, 1, 84, 253, 155, 255, 151, 0, 20, 179, 1, 29, 3, 1, 184, 253, 152, 180, 26,
  30, 2, 15, 37, 1, 43, 53, 0, 63, 53, 255, 255, 0, 241, 255, 236, 3, 248, 6,
  180, 2, 38, 1, 134, 0, 0, 1, 6, 1, 85, 198, 0, 0, 18, 178, 3, 2, 1, 184, 255,
  90, 180, 27, 31, 10, 5, 37, 1, 43, 53, 53, 53, 255, 255, 0, 33, 0, 0, 4, 172,
  5, 188, 2, 6, 0, 36, 0, 0, 255, 255, 0, 135, 0, 0, 4, 113, 5, 182, 2, 6, 0,
  37, 0, 0, 0, 1, 0, 246, 0, 0, 4, 47, 5, 182, 0, 5, 0, 57, 64, 16, 0, 64, 18,
  22, 72, 0, 7, 3, 90, 80, 4, 1, 0, 4, 1, 4, 184, 255, 192, 179, 21, 24, 72, 4,
  184, 255, 192, 64, 10, 13, 16, 72, 4, 2, 95, 5, 3, 3, 18, 0, 63, 63, 225, 1,
  47, 43, 43, 93, 113, 225, 16, 206, 43, 49, 48, 1, 21, 33, 17, 35, 17, 4, 47,
  253, 129, 186, 5, 182, 166, 250, 240, 5, 182, 0, 0, 2, 0, 68, 0, 0, 4, 135, 5,
  182, 0, 5, 0, 12, 0, 213, 185, 0, 9, 255, 240, 64, 27, 15, 19, 72, 184, 4, 1,
  4, 8, 14, 17, 72, 72, 4, 1, 41, 4, 1, 24, 4, 1, 9, 4, 1, 183, 5, 1, 5, 184,
  255, 248, 64, 32, 14, 17, 72, 71, 5, 1, 38, 5, 1, 23, 5, 1, 6, 5, 1, 10, 16,
  15, 19, 72, 232, 4, 1, 231, 5, 1, 5, 4, 6, 6, 1, 9, 184, 255, 240, 64, 84, 20,
  24, 72, 87, 9, 1, 71, 9, 1, 37, 9, 1, 6, 9, 22, 9, 2, 9, 96, 2, 1, 2, 10, 16,
  20, 24, 72, 88, 10, 1, 72, 10, 1, 42, 10, 1, 9, 10, 25, 10, 2, 10, 128, 1,
  160, 1, 240, 1, 3, 47, 1, 79, 1, 111, 1, 3, 1, 91, 6, 1, 41, 6, 57, 6, 73, 6,
  3, 6, 16, 17, 20, 72, 29, 6, 1, 6, 4, 3, 0, 3, 9, 95, 2, 18, 0, 63, 225, 57,
  57, 63, 51, 93, 43, 93, 93, 1, 47, 93, 93, 51, 93, 93, 93, 93, 43, 47, 93, 51,
  93, 93, 93, 93, 43, 18, 57, 61, 47, 51, 51, 93, 93, 49, 48, 43, 93, 93, 93,
  93, 43, 93, 93, 93, 93, 93, 43, 93, 43, 37, 21, 33, 53, 1, 51, 7, 6, 7, 3, 33,
  3, 38, 4, 135, 251, 189, 1, 194, 187, 95, 51, 37, 254, 2, 174, 252, 52, 125,
  125, 133, 5, 49, 205, 223, 110, 253, 10, 2, 240, 155, 255, 255, 0, 217, 0, 0,
  4, 35, 5, 182, 2, 6, 0, 40, 0, 0, 255, 255, 0, 102, 0, 0, 4, 100, 5, 182, 2,
  6, 0, 61, 0, 0, 255, 255, 0, 135, 0, 0, 4, 70, 5, 182, 2, 6, 0, 43, 0, 0, 0,
  3, 0, 84, 255, 236, 4, 123, 5, 205, 0, 9, 0, 19, 0, 23, 0, 97, 64, 64, 116,
  21, 132, 21, 2, 47, 21, 63, 21, 2, 123, 20, 139, 20, 2, 32, 20, 48, 20, 2, 21,
  20, 21, 20, 2, 88, 13, 1, 13, 91, 7, 25, 87, 18, 1, 18, 91, 31, 2, 47, 2, 2,
  2, 23, 96, 159, 20, 207, 20, 2, 104, 20, 1, 20, 20, 10, 16, 95, 4, 4, 10, 95,
  0, 19, 0, 63, 225, 63, 225, 18, 57, 47, 93, 93, 225, 1, 47, 93, 225, 93, 16,
  222, 225, 93, 18, 57, 57, 47, 47, 93, 93, 93, 93, 49, 48, 5, 32, 17, 16, 33,
  32, 0, 17, 16, 0, 39, 50, 18, 17, 16, 2, 35, 32, 17, 16, 19, 33, 21, 33, 2,
  104, 253, 236, 2, 22, 1, 0, 1, 17, 254, 236, 255, 173, 161, 163, 169, 254,
  175, 129, 1, 155, 254, 101, 20, 2, 243, 2, 238, 254, 121, 254, 151, 254, 151,
  254, 120, 163, 1, 34, 1, 44, 1, 47, 1, 29, 253, 180, 253, 178, 2, 170, 161,
  255, 255, 0, 225, 0, 0, 3, 233, 5, 182, 2, 6, 0, 44, 0, 0, 255, 255, 0, 211,
  0, 0, 4, 174, 5, 182, 2, 6, 0, 46, 0, 0, 0, 1, 0, 33, 0, 0, 4, 172, 5, 182, 0,
  10, 0, 190, 185, 0, 7, 255, 240, 64, 27, 15, 19, 72, 184, 9, 1, 9, 8, 14, 17,
  72, 72, 9, 1, 41, 9, 1, 24, 9, 1, 9, 9, 1, 183, 10, 1, 10, 184, 255, 248, 64,
  31, 14, 17, 72, 71, 10, 1, 38, 10, 1, 23, 10, 1, 6, 10, 1, 2, 16, 15, 19, 72,
  232, 9, 1, 231, 10, 1, 10, 9, 4, 4, 7, 184, 255, 240, 64, 68, 20, 24, 72, 87,
  7, 1, 71, 7, 1, 37, 7, 1, 6, 7, 22, 7, 2, 7, 8, 1, 16, 20, 24, 72, 88, 1, 1,
  72, 1, 1, 42, 1, 1, 9, 1, 25, 1, 2, 1, 47, 0, 127, 0, 207, 0, 239, 0, 4, 0, 4,
  16, 17, 20, 72, 4, 16, 11, 14, 72, 29, 4, 1, 4, 9, 3, 8, 0, 18, 0, 63, 50, 63,
  51, 93, 43, 43, 1, 47, 93, 50, 93, 93, 93, 93, 43, 47, 51, 93, 93, 93, 93, 43,
  57, 61, 47, 51, 51, 93, 93, 49, 48, 43, 93, 93, 93, 93, 43, 93, 93, 93, 93,
  93, 43, 93, 43, 33, 35, 1, 38, 39, 6, 7, 1, 35, 1, 51, 4, 172, 199, 254, 220,
  63, 30, 45, 43, 254, 217, 196, 1, 231, 187, 3, 154, 199, 141, 200, 134, 252,
  96, 5, 182, 255, 255, 0, 113, 0, 0, 4, 92, 5, 182, 2, 6, 0, 48, 0, 0, 255,
  255, 0, 135, 0, 0, 4, 68, 5, 182, 2, 6, 0, 49, 0, 0, 0, 3, 0, 111, 0, 0, 4,
  92, 5, 182, 0, 3, 0, 7, 0, 11, 0, 71, 64, 41, 47, 5, 63, 5, 2, 32, 4, 48, 4,
  2, 4, 5, 4, 5, 10, 1, 1, 9, 13, 0, 0, 1, 0, 0, 10, 7, 95, 104, 4, 1, 4, 4, 0,
  11, 95, 10, 18, 3, 95, 0, 3, 0, 63, 225, 63, 225, 17, 57, 47, 93, 225, 1, 47,
  51, 47, 113, 16, 206, 50, 47, 17, 57, 57, 47, 47, 93, 93, 49, 48, 19, 33, 21,
  33, 19, 33, 21, 33, 1, 21, 33, 53, 152, 3, 155, 252, 101, 81, 2, 248, 253, 8,
  3, 115, 252, 19, 5, 182, 164, 254, 60, 162, 253, 248, 164, 164, 0, 255, 255,
  0, 84, 255, 236, 4, 123, 5, 205, 2, 6, 0, 50, 0, 0, 0, 1, 0, 135, 0, 0, 4, 70,
  5, 182, 0, 7, 0, 37, 64, 21, 1, 90, 0, 9, 4, 90, 0, 5, 224, 5, 240, 5, 3, 5,
  3, 95, 6, 3, 5, 0, 18, 0, 63, 50, 63, 225, 1, 47, 93, 225, 16, 222, 225, 49,
  48, 33, 35, 17, 33, 17, 35, 17, 33, 4, 70, 187, 253, 183, 187, 3, 191, 5, 18,
  250, 238, 5, 182, 0, 255, 255, 0, 176, 0, 0, 4, 70, 5, 182, 2, 6, 0, 51, 0, 0,
  0, 1, 0, 131, 0, 0, 4, 72, 5, 182, 0, 11, 0, 128, 64, 87, 55, 9, 215, 9, 231,
  9, 247, 9, 4, 38, 9, 1, 7, 9, 23, 9, 2, 55, 7, 215, 7, 231, 7, 247, 7, 4, 38,
  7, 1, 7, 7, 23, 7, 2, 56, 2, 216, 2, 232, 2, 248, 2, 4, 25, 2, 41, 2, 2, 8, 2,
  1, 8, 2, 2, 0, 6, 239, 10, 255, 10, 2, 10, 13, 7, 3, 3, 9, 0, 0, 240, 0, 2, 0,
  3, 7, 95, 4, 8, 2, 2, 4, 3, 1, 9, 95, 0, 18, 0, 63, 225, 57, 63, 57, 61, 47,
  51, 16, 225, 57, 1, 24, 47, 93, 51, 51, 17, 51, 16, 206, 93, 50, 17, 57, 47,
  51, 49, 48, 93, 93, 93, 93, 93, 93, 93, 93, 93, 51, 53, 1, 1, 53, 33, 21, 33,
  1, 1, 33, 21, 131, 1, 158, 254, 110, 3, 125, 253, 88, 1, 133, 254, 103, 2,
  248, 152, 2, 102, 2, 37, 147, 164, 253, 238, 253, 164, 164, 0, 255, 255, 0,
  102, 0, 0, 4, 100, 5, 182, 2, 6, 0, 55, 0, 0, 255, 255, 0, 33, 0, 0, 4, 170,
  5, 182, 2, 6, 0, 60, 0, 0, 0, 3, 0, 27, 255, 236, 4, 180, 5, 203, 0, 21, 0,
  30, 0, 39, 0, 180, 64, 89, 6, 19, 22, 19, 38, 19, 3, 9, 15, 25, 15, 41, 15, 3,
  9, 8, 25, 8, 41, 8, 3, 6, 4, 22, 4, 38, 4, 3, 22, 2, 11, 90, 39, 21, 169, 12,
  1, 154, 12, 1, 139, 12, 1, 3, 114, 12, 1, 5, 64, 12, 80, 12, 96, 12, 3, 52,
  12, 1, 6, 12, 12, 17, 26, 8, 12, 17, 72, 26, 90, 15, 6, 47, 6, 63, 6, 111, 6,
  143, 6, 191, 6, 239, 6, 255, 6, 8, 6, 41, 35, 184, 255, 248, 64, 36, 12, 17,
  72, 35, 90, 17, 39, 22, 96, 13, 80, 10, 224, 10, 240, 10, 3, 10, 10, 11, 19,
  30, 31, 96, 2, 96, 21, 112, 21, 128, 21, 3, 21, 21, 0, 4, 0, 63, 50, 47, 93,
  51, 225, 50, 63, 51, 47, 93, 51, 225, 50, 1, 47, 225, 43, 16, 222, 93, 225,
  43, 18, 57, 47, 95, 93, 93, 95, 93, 95, 93, 93, 93, 51, 51, 225, 50, 50, 49,
  48, 0, 93, 93, 93, 93, 1, 51, 21, 51, 50, 18, 21, 20, 2, 35, 35, 21, 35, 53,
  35, 34, 2, 53, 52, 18, 51, 51, 19, 51, 50, 54, 53, 52, 38, 43, 3, 34, 6, 21,
  20, 22, 51, 51, 2, 20, 166, 47, 213, 246, 253, 228, 25, 166, 24, 230, 251,
  245, 213, 47, 166, 7, 155, 172, 158, 143, 33, 166, 32, 143, 158, 172, 155, 6,
  5, 203, 180, 254, 203, 236, 236, 254, 195, 225, 225, 1, 62, 235, 235, 1, 54,
  252, 83, 213, 187, 172, 209, 209, 172, 187, 213, 0, 255, 255, 0, 53, 0, 0, 4,
  150, 5, 182, 2, 6, 0, 59, 0, 0, 0, 1, 0, 57, 0, 0, 4, 150, 5, 182, 0, 27, 0,
  117, 64, 78, 21, 5, 90, 18, 169, 6, 1, 6, 22, 18, 73, 139, 6, 1, 3, 114, 6, 1,
  5, 80, 6, 96, 6, 2, 52, 6, 68, 6, 2, 6, 6, 6, 11, 25, 90, 15, 0, 47, 0, 63, 0,
  111, 0, 143, 0, 5, 0, 29, 14, 90, 144, 11, 160, 11, 192, 11, 208, 11, 4, 11,
  21, 119, 18, 135, 18, 2, 18, 96, 4, 7, 7, 5, 26, 19, 12, 3, 5, 18, 0, 63, 63,
  51, 51, 18, 57, 47, 51, 225, 93, 50, 1, 47, 93, 225, 16, 222, 93, 225, 17, 57,
  47, 95, 93, 93, 95, 93, 95, 93, 43, 93, 51, 225, 50, 49, 48, 1, 16, 6, 35, 35,
  17, 35, 17, 35, 34, 38, 17, 17, 51, 17, 20, 22, 51, 51, 17, 51, 17, 51, 50,
  54, 53, 17, 51, 4, 150, 232, 227, 17, 166, 16, 230, 229, 172, 138, 149, 16,
  166, 17, 149, 137, 173, 3, 215, 254, 225, 250, 254, 66, 1, 190, 251, 1, 26, 1,
  227, 254, 33, 231, 148, 3, 90, 252, 166, 144, 231, 1, 227, 0, 0, 1, 0, 74, 0,
  0, 4, 135, 5, 205, 0, 25, 0, 119, 185, 0, 14, 255, 232, 64, 78, 10, 20, 72,
  14, 192, 18, 208, 18, 2, 79, 18, 95, 18, 127, 18, 143, 18, 191, 18, 5, 9, 18,
  25, 18, 2, 18, 4, 24, 10, 20, 72, 4, 64, 0, 80, 0, 2, 3, 0, 19, 0, 2, 0, 0, 6,
  88, 20, 1, 20, 91, 15, 12, 27, 87, 24, 1, 24, 91, 3, 31, 6, 47, 6, 2, 6, 22,
  95, 9, 4, 0, 14, 18, 3, 3, 95, 17, 2, 18, 0, 63, 51, 225, 23, 50, 63, 225, 1,
  47, 93, 51, 225, 93, 16, 222, 50, 225, 93, 18, 57, 47, 93, 93, 51, 43, 198,
  93, 93, 93, 50, 43, 49, 48, 37, 21, 33, 53, 33, 38, 17, 16, 0, 51, 50, 0, 17,
  16, 5, 33, 21, 33, 53, 36, 17, 16, 33, 32, 17, 16, 2, 29, 254, 45, 1, 10, 254,
  1, 24, 250, 250, 1, 25, 255, 0, 1, 12, 254, 43, 1, 4, 254, 176, 254, 177, 147,
  147, 164, 235, 1, 170, 1, 56, 1, 92, 254, 164, 254, 200, 254, 83, 232, 164,
  147, 231, 1, 187, 1, 244, 254, 12, 254, 69, 255, 255, 0, 225, 0, 0, 3, 233, 7,
  43, 2, 38, 0, 44, 0, 0, 1, 7, 0, 106, 0, 2, 1, 82, 0, 23, 64, 13, 2, 1, 16, 5,
  38, 2, 1, 2, 18, 22, 1, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0,
  33, 0, 0, 4, 170, 7, 43, 2, 38, 0, 60, 0, 0, 1, 7, 0, 106, 0, 2, 1, 82, 0, 23,
  64, 13, 2, 1, 13, 5, 38, 2, 1, 2, 15, 19, 7, 2, 37, 1, 43, 53, 53, 0, 43, 53,
  53, 0, 255, 255, 0, 121, 255, 236, 4, 154, 6, 33, 2, 38, 1, 126, 0, 0, 1, 6,
  1, 84, 16, 0, 0, 21, 180, 2, 46, 17, 38, 2, 184, 255, 236, 180, 38, 42, 22,
  11, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 201, 255, 236, 4, 8, 6, 33, 2,
  38, 1, 130, 0, 0, 1, 6, 1, 84, 96, 0, 0, 19, 64, 11, 1, 40, 17, 38, 1, 93, 32,
  36, 14, 24, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160, 254, 20, 4, 45, 6,
  33, 2, 38, 1, 132, 0, 0, 1, 6, 1, 84, 80, 0, 0, 19, 64, 11, 1, 25, 17, 38, 1,
  79, 17, 21, 7, 15, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 1, 172, 255, 236, 3,
  248, 6, 33, 2, 38, 1, 134, 0, 0, 1, 6, 1, 84, 247, 0, 0, 19, 64, 11, 1, 20,
  17, 38, 1, 42, 12, 12, 11, 11, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160,
  255, 236, 4, 59, 6, 180, 2, 38, 1, 146, 0, 0, 1, 6, 1, 85, 253, 0, 0, 25, 181,
  3, 2, 1, 3, 2, 1, 184, 255, 245, 180, 33, 37, 0, 12, 37, 1, 43, 53, 53, 53, 0,
  53, 53, 53, 0, 0, 2, 0, 121, 255, 236, 4, 154, 4, 94, 0, 26, 0, 37, 0, 61, 64,
  34, 16, 0, 28, 71, 11, 127, 7, 143, 7, 2, 7, 39, 33, 72, 0, 22, 1, 22, 16, 9,
  35, 80, 11, 14, 14, 19, 22, 0, 31, 80, 25, 16, 3, 15, 0, 63, 63, 225, 50, 63,
  51, 17, 51, 225, 50, 50, 1, 47, 93, 225, 16, 220, 93, 50, 225, 50, 50, 49, 48,
  1, 51, 54, 55, 51, 6, 17, 17, 20, 51, 50, 55, 21, 6, 35, 34, 39, 35, 6, 35,
  34, 2, 17, 16, 18, 51, 50, 19, 53, 52, 38, 35, 32, 17, 16, 33, 50, 54, 3, 94,
  12, 30, 38, 143, 51, 84, 29, 31, 52, 63, 159, 40, 12, 108, 205, 195, 223, 230,
  206, 210, 85, 134, 147, 254, 250, 1, 8, 148, 127, 3, 182, 103, 45, 166, 254,
  239, 254, 93, 111, 10, 133, 26, 167, 167, 1, 41, 1, 14, 1, 17, 1, 42, 253,
  182, 15, 227, 193, 254, 90, 254, 98, 184, 0, 0, 2, 0, 158, 254, 20, 4, 80, 6,
  31, 0, 19, 0, 38, 0, 81, 64, 46, 42, 31, 1, 0, 17, 15, 29, 1, 29, 29, 9, 33,
  72, 17, 17, 24, 71, 3, 40, 20, 9, 71, 0, 10, 176, 10, 2, 10, 0, 28, 80, 29,
  29, 6, 14, 9, 27, 22, 80, 20, 6, 22, 36, 80, 14, 1, 0, 63, 225, 63, 51, 225,
  63, 17, 18, 57, 47, 225, 57, 1, 47, 93, 225, 50, 16, 222, 225, 51, 47, 225,
  18, 57, 47, 93, 18, 57, 49, 48, 93, 1, 21, 4, 17, 20, 6, 35, 34, 39, 17, 35,
  17, 52, 54, 51, 50, 22, 21, 20, 6, 1, 22, 51, 32, 17, 52, 38, 35, 35, 53, 51,
  50, 54, 53, 52, 38, 35, 32, 17, 2, 211, 1, 125, 245, 216, 186, 117, 182, 238,
  208, 198, 236, 161, 253, 231, 135, 154, 1, 37, 190, 159, 94, 70, 142, 161,
  134, 114, 254, 248, 3, 61, 6, 48, 254, 151, 205, 229, 63, 253, 233, 6, 52,
  226, 245, 210, 183, 136, 182, 253, 121, 80, 1, 43, 146, 165, 152, 150, 126,
  118, 132, 254, 182, 0, 0, 1, 0, 82, 254, 20, 4, 121, 4, 74, 0, 15, 0, 107, 64,
  37, 2, 72, 3, 5, 0, 3, 68, 10, 84, 10, 116, 10, 132, 10, 180, 10, 5, 10, 10,
  6, 14, 8, 9, 12, 72, 14, 16, 15, 32, 15, 48, 15, 3, 15, 15, 17, 7, 184, 255,
  248, 64, 16, 9, 12, 72, 7, 47, 6, 63, 6, 2, 6, 6, 16, 14, 6, 15, 10, 184, 255,
  240, 64, 9, 9, 12, 72, 10, 0, 5, 21, 2, 27, 0, 63, 63, 51, 51, 43, 63, 51, 17,
  1, 51, 47, 93, 51, 43, 17, 51, 47, 93, 51, 43, 18, 57, 25, 47, 93, 57, 51, 51,
  16, 225, 49, 48, 37, 2, 17, 35, 52, 19, 1, 51, 19, 22, 23, 51, 54, 55, 19, 51,
  2, 227, 110, 191, 101, 254, 55, 192, 242, 71, 36, 6, 26, 72, 229, 189, 63,
  254, 232, 254, 237, 207, 1, 41, 4, 62, 253, 176, 174, 146, 104, 191, 2, 105,
  0, 0, 2, 0, 135, 255, 236, 4, 70, 6, 31, 0, 25, 0, 34, 0, 79, 64, 49, 43, 0,
  1, 9, 0, 25, 0, 2, 13, 70, 0, 26, 2, 2, 24, 33, 72, 7, 239, 18, 255, 18, 2,
  18, 36, 28, 72, 0, 24, 224, 24, 240, 24, 3, 24, 16, 0, 26, 3, 5, 31, 80, 21,
  22, 10, 80, 8, 5, 1, 0, 63, 51, 225, 63, 225, 17, 23, 57, 1, 47, 93, 225, 16,
  222, 93, 50, 225, 17, 57, 47, 57, 57, 225, 49, 48, 93, 93, 1, 38, 53, 52, 54,
  51, 50, 23, 7, 38, 35, 34, 6, 21, 20, 22, 23, 4, 17, 20, 0, 35, 34, 36, 53,
  16, 37, 4, 17, 20, 22, 51, 32, 17, 52, 2, 45, 254, 182, 160, 199, 194, 73,
  169, 159, 74, 86, 84, 172, 1, 105, 254, 253, 225, 213, 254, 250, 2, 37, 254,
  156, 152, 130, 1, 39, 3, 170, 145, 203, 133, 148, 109, 145, 106, 73, 64, 63,
  103, 100, 206, 254, 200, 246, 254, 240, 247, 211, 1, 116, 44, 100, 254, 192,
  135, 168, 1, 94, 244, 0, 0, 1, 0, 201, 255, 236, 4, 8, 4, 94, 0, 31, 0, 81,
  64, 47, 17, 19, 0, 0, 14, 24, 127, 9, 143, 9, 2, 9, 33, 29, 71, 19, 19, 4, 71,
  0, 14, 1, 14, 17, 2, 80, 191, 31, 1, 121, 31, 137, 31, 2, 31, 31, 6, 27, 80,
  25, 22, 16, 6, 80, 8, 11, 22, 0, 63, 51, 225, 63, 51, 225, 18, 57, 47, 93, 93,
  225, 57, 1, 47, 93, 225, 51, 47, 225, 16, 206, 93, 50, 17, 57, 47, 18, 57, 49,
  48, 1, 21, 35, 32, 21, 20, 33, 50, 55, 21, 6, 35, 34, 38, 53, 52, 55, 53, 38,
  53, 52, 54, 51, 50, 23, 7, 38, 35, 34, 21, 20, 33, 3, 72, 160, 254, 211, 1,
  27, 196, 170, 134, 243, 211, 239, 237, 202, 224, 189, 216, 167, 63, 161, 155,
  243, 1, 20, 2, 135, 153, 185, 180, 86, 160, 75, 168, 151, 193, 75, 11, 66,
  183, 135, 156, 76, 147, 72, 154, 166, 0, 1, 0, 162, 254, 111, 4, 43, 6, 20, 0,
  28, 0, 137, 64, 87, 10, 20, 26, 20, 42, 20, 3, 6, 9, 22, 9, 38, 9, 3, 11, 25,
  27, 25, 43, 25, 3, 25, 2, 2, 16, 16, 9, 14, 72, 16, 70, 14, 144, 11, 1, 11,
  30, 28, 5, 72, 0, 22, 160, 22, 2, 22, 153, 19, 1, 123, 19, 139, 19, 2, 109,
  19, 1, 73, 19, 1, 59, 19, 1, 45, 19, 1, 121, 8, 137, 8, 2, 107, 8, 1, 73, 8,
  1, 59, 8, 1, 45, 8, 1, 19, 8, 0, 13, 184, 1, 6, 180, 2, 28, 80, 0, 0, 0, 63,
  225, 50, 63, 18, 57, 57, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 1, 47,
  93, 225, 51, 16, 222, 93, 50, 225, 43, 51, 47, 51, 93, 49, 48, 0, 93, 93, 19,
  33, 21, 0, 0, 17, 20, 22, 23, 22, 22, 21, 20, 7, 35, 54, 53, 52, 38, 39, 38,
  38, 53, 16, 0, 37, 6, 35, 33, 223, 3, 70, 254, 116, 254, 197, 166, 229, 171,
  151, 121, 170, 121, 103, 194, 229, 209, 1, 66, 1, 120, 215, 137, 254, 227, 6,
  20, 141, 254, 224, 254, 118, 255, 0, 153, 129, 39, 30, 101, 111, 149, 166,
  162, 98, 57, 65, 29, 35, 223, 201, 1, 1, 1, 186, 247, 12, 0, 0, 1, 0, 160,
  254, 20, 4, 45, 4, 94, 0, 16, 0, 49, 64, 29, 0, 71, 144, 16, 160, 16, 2, 16,
  18, 11, 6, 71, 0, 7, 176, 7, 2, 7, 11, 3, 80, 13, 16, 8, 15, 7, 21, 0, 27, 0,
  63, 63, 63, 63, 225, 50, 1, 47, 93, 225, 50, 16, 222, 93, 225, 49, 48, 1, 17,
  16, 35, 32, 17, 17, 35, 17, 51, 23, 51, 54, 51, 32, 17, 17, 3, 119, 238, 254,
  205, 182, 147, 27, 10, 102, 234, 1, 133, 254, 20, 4, 175, 1, 4, 254, 114, 253,
  199, 4, 74, 148, 168, 254, 111, 251, 71, 0, 0, 3, 0, 147, 255, 236, 4, 57, 5,
  195, 0, 10, 0, 17, 0, 24, 0, 79, 64, 50, 12, 59, 18, 1, 6, 40, 18, 1, 18, 72,
  9, 26, 11, 39, 19, 55, 19, 2, 19, 71, 0, 3, 1, 3, 19, 79, 202, 11, 234, 11, 2,
  152, 11, 1, 47, 11, 255, 11, 2, 11, 11, 22, 15, 80, 6, 4, 22, 80, 0, 22, 0,
  63, 225, 63, 225, 18, 57, 47, 93, 93, 93, 225, 1, 47, 93, 225, 93, 50, 16,
  222, 225, 93, 95, 93, 50, 49, 48, 5, 34, 2, 17, 16, 18, 51, 50, 18, 17, 16, 1,
  33, 2, 2, 35, 34, 6, 1, 33, 18, 18, 51, 50, 18, 2, 100, 229, 236, 228, 237,
  231, 238, 253, 19, 2, 51, 7, 133, 143, 139, 133, 2, 43, 253, 205, 6, 132, 142,
  142, 135, 20, 1, 127, 1, 110, 1, 124, 1, 110, 254, 131, 254, 147, 253, 19, 3,
  59, 1, 4, 1, 0, 250, 254, 109, 254, 234, 254, 251, 1, 0, 0, 1, 1, 172, 255,
  236, 3, 248, 4, 74, 0, 11, 0, 38, 64, 20, 1, 71, 0, 10, 1, 10, 10, 12, 111, 5,
  1, 5, 13, 5, 3, 80, 8, 22, 0, 15, 0, 63, 63, 225, 51, 1, 16, 206, 93, 18, 57,
  47, 93, 225, 49, 48, 1, 17, 20, 51, 50, 55, 21, 6, 35, 32, 17, 17, 2, 98, 193,
  112, 101, 93, 132, 254, 149, 4, 74, 252, 250, 195, 21, 138, 32, 1, 88, 3, 6,
  0, 255, 255, 0, 215, 0, 0, 4, 139, 4, 74, 2, 6, 0, 250, 0, 0, 0, 1, 0, 61,
  255, 236, 4, 160, 6, 33, 0, 31, 0, 85, 64, 51, 13, 1, 27, 24, 14, 27, 14, 0,
  18, 20, 18, 36, 18, 2, 6, 18, 1, 18, 33, 31, 7, 0, 32, 13, 16, 72, 47, 0, 63,
  0, 2, 0, 31, 21, 72, 27, 1, 27, 1, 13, 3, 10, 16, 80, 18, 21, 22, 5, 80, 10,
  1, 0, 63, 225, 63, 51, 225, 17, 23, 57, 93, 63, 1, 47, 93, 43, 51, 51, 17, 51,
  93, 93, 17, 18, 57, 57, 17, 51, 17, 51, 51, 49, 48, 51, 1, 39, 38, 38, 35, 34,
  7, 53, 54, 51, 50, 22, 23, 1, 22, 51, 50, 55, 21, 6, 35, 34, 38, 39, 3, 38,
  39, 35, 6, 7, 1, 61, 1, 248, 53, 34, 86, 73, 56, 48, 65, 62, 142, 142, 70, 1,
  70, 37, 65, 29, 31, 50, 65, 82, 87, 28, 135, 69, 25, 6, 36, 83, 254, 244, 4,
  59, 160, 104, 72, 12, 145, 17, 135, 211, 252, 41, 111, 10, 133, 26, 80, 87, 1,
  162, 214, 122, 138, 183, 253, 188, 0, 1, 0, 160, 254, 20, 4, 45, 4, 74, 0, 21,
  0, 58, 64, 35, 10, 5, 71, 144, 8, 160, 8, 2, 8, 23, 0, 18, 71, 0, 19, 176, 19,
  2, 19, 18, 27, 0, 5, 10, 15, 4, 2, 80, 13, 22, 9, 21, 20, 6, 15, 0, 63, 51,
  63, 63, 225, 23, 50, 63, 1, 47, 93, 225, 50, 16, 222, 93, 225, 50, 49, 48, 1,
  16, 51, 50, 54, 53, 17, 51, 17, 35, 39, 35, 6, 35, 34, 39, 22, 21, 17, 35, 17,
  51, 1, 86, 238, 160, 147, 182, 147, 27, 10, 97, 204, 173, 75, 6, 182, 182, 1,
  135, 254, 252, 186, 211, 2, 58, 251, 182, 147, 167, 88, 153, 87, 254, 192, 6,
  54, 0, 0, 1, 0, 61, 0, 0, 4, 74, 4, 74, 0, 13, 0, 116, 64, 70, 13, 16, 10, 16,
  72, 8, 13, 1, 53, 12, 69, 12, 85, 12, 3, 36, 12, 1, 21, 12, 1, 25, 6, 41, 6,
  57, 6, 3, 13, 149, 12, 165, 12, 2, 134, 12, 1, 99, 12, 115, 12, 2, 5, 12, 1,
  12, 20, 4, 68, 4, 116, 4, 3, 4, 4, 0, 8, 71, 9, 15, 7, 1, 1, 1, 0, 64, 10, 16,
  72, 0, 184, 255, 240, 182, 0, 4, 13, 21, 8, 0, 15, 0, 63, 50, 63, 51, 1, 47,
  56, 43, 50, 93, 16, 222, 225, 18, 57, 61, 47, 93, 51, 93, 93, 93, 93, 51, 49,
  48, 93, 93, 93, 93, 93, 43, 19, 51, 19, 18, 23, 51, 54, 18, 17, 51, 16, 2, 7,
  35, 61, 189, 223, 110, 11, 6, 157, 158, 183, 201, 225, 187, 4, 74, 253, 182,
  254, 223, 69, 164, 1, 154, 1, 114, 254, 147, 254, 22, 243, 0, 0, 1, 0, 172,
  254, 111, 4, 43, 6, 20, 0, 44, 0, 151, 64, 95, 41, 70, 34, 26, 31, 0, 159, 36,
  1, 95, 28, 1, 159, 0, 1, 28, 0, 36, 36, 0, 28, 3, 22, 17, 70, 144, 12, 1, 12,
  46, 5, 72, 0, 22, 1, 22, 123, 20, 1, 109, 20, 1, 73, 20, 1, 59, 20, 1, 45, 20,
  1, 8, 20, 24, 20, 2, 20, 8, 21, 24, 72, 121, 9, 1, 107, 9, 1, 73, 9, 1, 59, 9,
  1, 45, 9, 1, 20, 9, 14, 35, 26, 2, 79, 47, 44, 1, 44, 44, 14, 37, 34, 80, 35,
  0, 14, 184, 1, 6, 0, 63, 63, 225, 50, 18, 57, 47, 93, 225, 57, 17, 18, 57, 57,
  93, 93, 93, 93, 93, 43, 93, 93, 93, 93, 93, 93, 1, 47, 93, 225, 16, 222, 93,
  225, 18, 23, 57, 47, 47, 47, 93, 93, 93, 18, 57, 57, 51, 225, 49, 48, 1, 21,
  35, 34, 6, 21, 20, 22, 22, 23, 22, 22, 21, 20, 7, 35, 54, 53, 52, 38, 39, 36,
  17, 52, 54, 55, 53, 38, 53, 52, 54, 55, 6, 35, 35, 53, 33, 21, 35, 34, 4, 21,
  20, 22, 51, 3, 217, 201, 207, 217, 76, 139, 179, 162, 151, 121, 170, 121, 99,
  188, 254, 74, 151, 132, 215, 150, 185, 176, 104, 62, 2, 252, 69, 217, 254,
  217, 183, 196, 3, 119, 137, 163, 149, 91, 105, 56, 32, 29, 100, 111, 149, 166,
  162, 100, 53, 65, 29, 68, 1, 90, 134, 211, 42, 12, 59, 220, 114, 150, 51, 12,
  153, 153, 160, 139, 113, 104, 0, 255, 255, 0, 115, 255, 236, 4, 88, 4, 94, 2,
  6, 0, 82, 0, 0, 0, 1, 0, 14, 255, 236, 4, 190, 4, 74, 0, 20, 0, 121, 64, 53,
  75, 11, 91, 11, 107, 11, 3, 58, 11, 1, 40, 11, 1, 11, 11, 1, 11, 8, 71, 9, 84,
  15, 1, 69, 15, 1, 54, 15, 1, 39, 15, 1, 4, 15, 20, 15, 2, 15, 0, 0, 5, 71, 17,
  0, 9, 64, 9, 80, 9, 96, 9, 4, 17, 184, 255, 192, 64, 23, 18, 22, 72, 9, 17, 9,
  17, 21, 22, 12, 16, 7, 10, 80, 13, 15, 9, 21, 19, 80, 0, 3, 22, 0, 63, 51,
  225, 63, 63, 225, 50, 50, 57, 17, 18, 1, 57, 57, 47, 47, 43, 93, 16, 225, 51,
  17, 51, 93, 93, 93, 93, 93, 16, 225, 51, 93, 93, 93, 93, 49, 48, 37, 21, 6,
  35, 34, 17, 17, 33, 17, 35, 17, 35, 53, 55, 33, 21, 35, 17, 20, 51, 50, 4,
  160, 52, 85, 226, 254, 109, 182, 222, 138, 4, 38, 210, 90, 46, 150, 144, 26,
  1, 6, 2, 190, 252, 80, 3, 176, 74, 80, 154, 253, 78, 125, 0, 2, 0, 158, 254,
  20, 4, 59, 4, 94, 0, 16, 0, 27, 0, 53, 64, 31, 22, 72, 12, 64, 21, 24, 72, 12,
  29, 17, 1, 4, 71, 0, 5, 176, 5, 2, 5, 17, 0, 19, 80, 15, 22, 25, 80, 9, 16, 4,
  27, 0, 63, 63, 225, 63, 225, 50, 50, 1, 47, 93, 225, 50, 50, 16, 222, 43, 225,
  49, 48, 37, 35, 22, 21, 17, 35, 17, 16, 18, 51, 50, 18, 17, 16, 2, 35, 34, 39,
  22, 51, 50, 54, 53, 52, 38, 35, 32, 17, 1, 84, 6, 6, 182, 253, 218, 206, 248,
  247, 215, 168, 113, 112, 171, 144, 128, 130, 144, 254, 231, 70, 174, 97, 254,
  221, 4, 19, 1, 7, 1, 48, 254, 205, 254, 252, 254, 242, 254, 211, 251, 100,
  211, 209, 209, 207, 254, 116, 0, 0, 1, 0, 172, 254, 111, 4, 41, 4, 94, 0, 23,
  0, 103, 64, 66, 12, 3, 70, 1, 144, 22, 1, 22, 25, 17, 72, 0, 8, 1, 8, 153, 6,
  1, 123, 6, 139, 6, 2, 109, 6, 1, 73, 6, 1, 59, 6, 1, 44, 6, 1, 8, 6, 24, 6, 2,
  121, 20, 137, 20, 2, 107, 20, 1, 73, 20, 1, 59, 20, 1, 44, 20, 1, 6, 20, 0,
  15, 81, 13, 10, 16, 0, 184, 1, 6, 0, 63, 63, 51, 225, 18, 57, 57, 93, 93, 93,
  93, 93, 93, 93, 93, 93, 93, 93, 93, 1, 47, 93, 225, 16, 222, 93, 50, 225, 51,
  49, 48, 1, 35, 54, 53, 52, 38, 39, 36, 17, 16, 33, 50, 23, 7, 38, 35, 32, 17,
  20, 22, 23, 4, 21, 20, 3, 172, 166, 121, 132, 163, 254, 84, 2, 55, 164, 158,
  62, 158, 114, 254, 145, 155, 192, 1, 102, 254, 111, 163, 99, 60, 59, 28, 71,
  1, 181, 2, 90, 59, 158, 57, 254, 72, 187, 134, 35, 66, 186, 141, 0, 0, 2, 0,
  129, 255, 236, 4, 150, 4, 74, 0, 12, 0, 24, 0, 50, 64, 30, 2, 23, 72, 1, 223,
  4, 239, 4, 255, 4, 3, 4, 26, 17, 72, 0, 10, 240, 10, 2, 10, 2, 14, 80, 12, 15,
  20, 80, 7, 22, 0, 63, 225, 63, 225, 50, 1, 47, 93, 225, 16, 222, 93, 50, 225,
  57, 49, 48, 1, 21, 33, 22, 21, 20, 0, 35, 34, 2, 17, 16, 33, 23, 35, 34, 6,
  21, 20, 22, 51, 50, 54, 53, 16, 4, 150, 254, 245, 178, 254, 255, 224, 221,
  254, 2, 43, 59, 59, 199, 168, 153, 142, 139, 146, 4, 74, 154, 195, 245, 235,
  254, 223, 1, 31, 1, 1, 2, 62, 154, 195, 225, 185, 208, 191, 174, 1, 13, 0, 1,
  0, 106, 255, 229, 4, 57, 4, 74, 0, 16, 0, 83, 64, 29, 10, 14, 26, 14, 2, 14,
  3, 71, 253, 12, 1, 12, 64, 20, 23, 72, 61, 12, 1, 47, 12, 1, 0, 12, 1, 12, 12,
  17, 1, 184, 255, 232, 64, 20, 9, 18, 72, 1, 95, 7, 1, 7, 18, 15, 2, 13, 80,
  16, 15, 7, 5, 80, 10, 22, 0, 63, 225, 51, 63, 225, 50, 57, 1, 16, 206, 93, 50,
  43, 18, 57, 47, 93, 93, 93, 43, 93, 225, 51, 93, 49, 48, 1, 21, 33, 17, 20,
  51, 50, 55, 21, 6, 35, 32, 17, 17, 33, 53, 55, 4, 57, 254, 37, 209, 107, 84,
  84, 136, 254, 150, 254, 194, 134, 4, 74, 154, 253, 162, 215, 20, 135, 35, 1,
  88, 2, 115, 74, 80, 0, 0, 1, 0, 160, 255, 236, 4, 59, 4, 74, 0, 17, 0, 51,
  179, 10, 70, 9, 9, 184, 255, 208, 64, 23, 16, 24, 72, 9, 7, 71, 12, 19, 2, 71,
  0, 17, 176, 17, 2, 17, 4, 80, 15, 22, 9, 0, 15, 0, 63, 50, 63, 225, 1, 47, 93,
  225, 16, 222, 225, 51, 43, 16, 229, 49, 48, 19, 51, 17, 16, 33, 50, 54, 53,
  52, 39, 51, 22, 21, 16, 2, 35, 32, 17, 160, 182, 1, 18, 150, 135, 63, 182, 63,
  230, 243, 254, 62, 4, 74, 253, 178, 254, 133, 232, 247, 237, 253, 245, 253,
  254, 194, 254, 210, 2, 6, 0, 2, 0, 74, 254, 20, 4, 131, 4, 94, 0, 21, 0, 28,
  0, 92, 64, 58, 22, 86, 21, 102, 21, 2, 71, 21, 1, 21, 73, 11, 6, 0, 0, 3, 24,
  70, 15, 17, 1, 17, 30, 9, 73, 80, 3, 144, 3, 160, 3, 192, 3, 208, 3, 5, 47, 3,
  63, 3, 2, 3, 6, 26, 80, 14, 5, 5, 14, 16, 22, 11, 80, 20, 1, 22, 0, 27, 0, 63,
  63, 51, 225, 50, 63, 51, 47, 16, 225, 57, 1, 47, 93, 93, 225, 16, 222, 93,
  225, 17, 57, 47, 51, 51, 225, 93, 93, 50, 49, 48, 1, 17, 36, 17, 16, 55, 23,
  6, 6, 21, 16, 5, 17, 16, 33, 50, 18, 21, 16, 2, 7, 17, 17, 36, 17, 16, 35, 34,
  21, 2, 12, 254, 62, 207, 120, 97, 68, 1, 32, 1, 25, 164, 186, 250, 223, 1, 49,
  176, 129, 254, 20, 1, 218, 25, 2, 28, 1, 58, 245, 90, 129, 206, 134, 254, 129,
  33, 2, 94, 1, 125, 254, 217, 252, 254, 248, 254, 201, 14, 254, 38, 2, 111, 29,
  1, 153, 1, 142, 228, 0, 1, 0, 43, 254, 20, 4, 141, 4, 78, 0, 30, 0, 230, 64,
  92, 3, 30, 4, 16, 20, 15, 17, 2, 17, 0, 30, 4, 19, 20, 15, 18, 1, 18, 16, 19,
  20, 15, 20, 3, 0, 30, 4, 30, 6, 30, 22, 30, 38, 30, 3, 73, 20, 89, 20, 201,
  20, 3, 21, 17, 1, 6, 17, 38, 17, 198, 17, 3, 9, 15, 25, 15, 41, 15, 3, 70, 4,
  86, 4, 198, 4, 3, 26, 1, 1, 9, 1, 41, 1, 201, 1, 3, 20, 30, 4, 15, 30, 15, 25,
  9, 19, 16, 0, 3, 4, 18, 1, 2, 184, 255, 192, 181, 13, 16, 72, 2, 2, 9, 184,
  255, 192, 64, 43, 9, 12, 72, 9, 9, 32, 17, 18, 18, 0, 25, 1, 25, 25, 31, 20,
  15, 12, 22, 80, 30, 4, 9, 24, 27, 15, 0, 19, 3, 16, 4, 1, 17, 18, 27, 9, 7,
  80, 12, 27, 2, 1, 15, 0, 63, 51, 63, 225, 51, 63, 51, 18, 23, 57, 63, 51, 18,
  57, 57, 225, 17, 57, 57, 17, 1, 51, 47, 93, 51, 47, 51, 17, 51, 47, 43, 51,
  47, 43, 51, 18, 23, 57, 17, 18, 57, 57, 17, 51, 17, 51, 93, 93, 93, 93, 93,
  93, 93, 93, 16, 125, 135, 196, 196, 16, 135, 196, 196, 16, 135, 8, 196, 8,
  196, 16, 135, 8, 196, 8, 196, 49, 48, 1, 1, 51, 1, 19, 22, 22, 51, 50, 55, 21,
  6, 35, 34, 38, 39, 3, 1, 35, 1, 3, 38, 35, 34, 7, 53, 54, 51, 50, 22, 23, 2,
  125, 1, 55, 178, 254, 95, 186, 46, 80, 64, 44, 36, 66, 52, 102, 135, 71, 147,
  254, 158, 195, 1, 219, 180, 68, 84, 29, 34, 53, 76, 81, 110, 55, 1, 250, 2,
  80, 252, 248, 254, 51, 114, 89, 8, 139, 19, 90, 177, 1, 121, 253, 124, 3, 62,
  1, 190, 168, 10, 143, 17, 109, 139, 0, 1, 0, 80, 254, 20, 4, 131, 6, 18, 0,
  22, 0, 105, 64, 22, 1, 86, 11, 102, 11, 2, 71, 11, 1, 11, 73, 21, 12, 12, 16,
  3, 70, 8, 6, 70, 5, 5, 184, 255, 208, 64, 43, 16, 24, 72, 5, 15, 8, 1, 8, 24,
  19, 70, 64, 16, 80, 16, 144, 16, 160, 16, 192, 16, 208, 16, 6, 47, 16, 63, 16,
  2, 16, 6, 17, 15, 1, 21, 80, 10, 13, 22, 11, 27, 0, 0, 0, 63, 63, 63, 51, 225,
  50, 63, 51, 1, 47, 93, 93, 225, 16, 206, 93, 50, 43, 16, 229, 16, 225, 17, 57,
  47, 51, 225, 93, 93, 50, 49, 48, 1, 17, 36, 17, 52, 3, 51, 18, 21, 16, 5, 17,
  35, 17, 38, 2, 17, 17, 51, 17, 16, 5, 17, 2, 170, 1, 45, 63, 172, 63, 254, 39,
  158, 233, 211, 172, 1, 16, 6, 18, 250, 115, 28, 1, 152, 250, 1, 23, 254, 236,
  247, 253, 201, 26, 254, 38, 1, 218, 8, 1, 14, 1, 39, 2, 31, 253, 239, 254, 90,
  16, 5, 143, 0, 0, 1, 0, 90, 255, 236, 4, 117, 4, 74, 0, 31, 0, 170, 64, 16,
  86, 19, 230, 19, 246, 19, 3, 71, 19, 1, 54, 19, 1, 19, 18, 18, 184, 255, 240,
  64, 99, 15, 18, 72, 87, 18, 1, 54, 18, 70, 18, 2, 18, 21, 25, 86, 11, 102, 11,
  2, 71, 11, 1, 11, 73, 8, 8, 30, 16, 73, 15, 21, 63, 21, 2, 21, 33, 89, 0, 233,
  0, 249, 0, 3, 72, 0, 1, 57, 0, 1, 0, 1, 1, 16, 15, 18, 72, 88, 1, 1, 57, 1,
  73, 1, 2, 1, 3, 73, 48, 30, 64, 30, 80, 30, 144, 30, 160, 30, 192, 30, 208,
  30, 7, 47, 30, 1, 30, 9, 9, 0, 25, 14, 5, 80, 23, 28, 22, 18, 0, 15, 0, 63,
  50, 63, 51, 225, 50, 50, 17, 57, 47, 1, 47, 93, 93, 225, 51, 93, 93, 43, 17,
  51, 93, 93, 93, 16, 222, 93, 225, 17, 57, 47, 225, 93, 93, 57, 17, 51, 93, 93,
  43, 17, 51, 93, 93, 93, 49, 48, 19, 51, 2, 17, 16, 51, 50, 54, 53, 17, 51, 17,
  20, 22, 51, 50, 17, 16, 3, 51, 18, 17, 16, 33, 34, 39, 35, 6, 35, 32, 17, 16,
  195, 165, 104, 139, 67, 75, 157, 79, 63, 139, 105, 166, 105, 254, 223, 181,
  50, 11, 50, 181, 254, 223, 4, 74, 254, 250, 254, 208, 254, 111, 142, 126, 1,
  50, 254, 206, 130, 138, 1, 145, 1, 50, 1, 4, 254, 254, 254, 204, 253, 216,
  178, 178, 2, 40, 1, 46, 255, 255, 1, 3, 255, 236, 3, 248, 5, 217, 2, 38, 1,
  134, 0, 0, 1, 6, 0, 106, 185, 0, 0, 23, 64, 13, 2, 1, 16, 17, 38, 2, 1, 23,
  18, 22, 11, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 160, 255,
  236, 4, 59, 5, 217, 2, 38, 1, 146, 0, 0, 1, 6, 0, 106, 0, 0, 0, 25, 182, 2, 1,
  22, 17, 38, 2, 1, 184, 255, 248, 180, 24, 28, 0, 12, 37, 1, 43, 53, 53, 0, 43,
  53, 53, 0, 255, 255, 0, 115, 255, 236, 4, 88, 6, 33, 2, 38, 0, 82, 0, 0, 1, 6,
  1, 84, 72, 0, 0, 19, 64, 11, 2, 28, 17, 38, 2, 72, 20, 24, 3, 9, 37, 1, 43,
  53, 0, 43, 53, 0, 255, 255, 0, 160, 255, 236, 4, 59, 6, 33, 2, 38, 1, 146, 0,
  0, 1, 6, 1, 84, 39, 0, 0, 19, 64, 11, 1, 26, 17, 38, 1, 31, 18, 22, 0, 12, 37,
  1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 90, 255, 236, 4, 117, 6, 33, 2, 38, 1,
  150, 0, 0, 1, 6, 1, 84, 51, 0, 0, 19, 64, 11, 1, 40, 17, 38, 1, 49, 32, 36,
  30, 21, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 217, 0, 0, 4, 35, 7, 43, 2,
  38, 0, 40, 0, 0, 1, 7, 0, 106, 0, 25, 1, 82, 0, 23, 64, 13, 2, 1, 16, 5, 38,
  2, 1, 0, 18, 22, 1, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 0, 1, 0, 23, 255,
  236, 4, 141, 5, 182, 0, 27, 0, 125, 182, 18, 16, 16, 128, 16, 2, 16, 184, 255,
  192, 64, 73, 21, 24, 72, 16, 16, 10, 90, 11, 255, 13, 1, 13, 13, 224, 11, 240,
  11, 2, 70, 11, 86, 11, 2, 55, 11, 1, 47, 0, 63, 0, 2, 11, 0, 1, 11, 0, 11, 0,
  28, 5, 90, 23, 29, 9, 95, 64, 18, 160, 18, 176, 18, 208, 18, 224, 18, 240, 18,
  6, 18, 18, 14, 3, 95, 1, 26, 19, 17, 12, 95, 14, 3, 11, 18, 0, 63, 63, 225,
  50, 63, 51, 225, 17, 57, 47, 93, 225, 1, 16, 222, 225, 18, 57, 57, 47, 47, 93,
  93, 93, 93, 93, 51, 47, 93, 16, 225, 50, 47, 43, 93, 50, 49, 48, 37, 53, 22,
  51, 50, 53, 53, 52, 35, 35, 17, 35, 17, 33, 53, 33, 21, 33, 17, 33, 50, 22,
  21, 21, 20, 6, 35, 34, 2, 152, 68, 67, 180, 227, 244, 186, 254, 213, 3, 73,
  254, 156, 1, 8, 187, 206, 189, 171, 88, 4, 160, 21, 226, 133, 231, 253, 35, 5,
  18, 164, 164, 254, 111, 193, 178, 137, 196, 213, 0, 255, 255, 0, 246, 0, 0, 4,
  47, 7, 115, 2, 38, 1, 97, 0, 0, 1, 7, 0, 118, 0, 109, 1, 82, 0, 19, 64, 11, 1,
  12, 5, 38, 1, 58, 6, 9, 4, 0, 37, 1, 43, 53, 0, 43, 53, 0, 0, 1, 0, 129, 255,
  236, 4, 156, 5, 203, 0, 23, 0, 68, 64, 39, 7, 64, 20, 24, 72, 7, 1, 7, 1, 13,
  18, 25, 0, 3, 91, 0, 13, 240, 13, 2, 13, 3, 95, 104, 0, 1, 0, 0, 5, 21, 95,
  19, 16, 4, 5, 95, 7, 10, 19, 0, 63, 51, 225, 63, 51, 225, 18, 57, 47, 93, 225,
  1, 47, 93, 225, 50, 16, 206, 17, 57, 57, 47, 47, 43, 49, 48, 1, 33, 21, 33,
  18, 33, 50, 55, 21, 6, 35, 32, 0, 17, 16, 0, 33, 50, 23, 7, 38, 35, 34, 6, 1,
  76, 2, 117, 253, 133, 23, 1, 192, 130, 197, 146, 212, 254, 203, 254, 184, 1,
  102, 1, 54, 220, 163, 78, 154, 151, 188, 250, 3, 78, 162, 253, 227, 58, 162,
  59, 1, 136, 1, 105, 1, 90, 1, 148, 86, 156, 78, 249, 255, 255, 0, 141, 255,
  236, 4, 63, 5, 203, 2, 6, 0, 54, 0, 0, 255, 255, 0, 225, 0, 0, 3, 233, 5, 182,
  2, 6, 0, 44, 0, 0, 255, 255, 0, 225, 0, 0, 3, 233, 7, 43, 2, 38, 0, 44, 0, 0,
  1, 7, 0, 106, 0, 2, 1, 82, 0, 23, 64, 13, 2, 1, 16, 5, 38, 2, 1, 2, 18, 22, 1,
  0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 137, 255, 236, 3, 211, 5,
  182, 2, 6, 0, 45, 0, 0, 0, 2, 0, 0, 255, 236, 4, 184, 5, 182, 0, 24, 0, 32, 0,
  132, 64, 88, 1, 8, 9, 14, 72, 1, 120, 0, 1, 87, 0, 103, 0, 2, 0, 250, 14, 12,
  8, 20, 24, 72, 153, 12, 169, 12, 2, 120, 12, 136, 12, 2, 12, 16, 9, 15, 72,
  12, 14, 16, 25, 90, 23, 96, 14, 144, 14, 160, 14, 224, 14, 240, 14, 5, 71, 23,
  1, 14, 23, 14, 23, 6, 28, 251, 19, 34, 0, 6, 1, 6, 32, 95, 16, 16, 14, 25, 96,
  23, 18, 0, 95, 14, 3, 9, 97, 7, 4, 19, 0, 63, 51, 225, 63, 225, 63, 225, 17,
  57, 47, 225, 1, 47, 93, 16, 214, 225, 17, 57, 57, 47, 47, 93, 93, 16, 225, 50,
  17, 51, 43, 93, 93, 43, 16, 225, 93, 93, 50, 43, 49, 48, 1, 3, 2, 6, 35, 34,
  39, 53, 22, 51, 50, 54, 54, 18, 55, 33, 17, 51, 32, 17, 20, 6, 35, 35, 17, 19,
  51, 32, 17, 52, 38, 35, 35, 1, 119, 20, 20, 127, 112, 56, 40, 32, 36, 35, 53,
  25, 41, 3, 1, 242, 39, 1, 190, 228, 216, 207, 166, 45, 1, 12, 138, 155, 20, 5,
  18, 253, 220, 253, 195, 197, 18, 145, 14, 70, 184, 3, 97, 214, 253, 152, 254,
  94, 208, 220, 5, 18, 251, 142, 1, 12, 134, 120, 0, 2, 0, 66, 0, 0, 4, 176, 5,
  182, 0, 18, 0, 26, 0, 67, 64, 37, 11, 19, 90, 8, 0, 0, 4, 22, 251, 15, 28, 7,
  3, 90, 4, 64, 10, 15, 72, 4, 26, 2, 95, 11, 104, 7, 1, 7, 7, 9, 5, 3, 19, 96,
  3, 0, 18, 0, 63, 50, 225, 63, 51, 57, 47, 93, 51, 225, 50, 1, 47, 43, 225, 50,
  16, 214, 225, 17, 57, 47, 51, 225, 50, 49, 48, 33, 17, 33, 17, 35, 17, 51, 17,
  33, 17, 51, 17, 51, 50, 22, 21, 20, 6, 35, 39, 51, 32, 17, 52, 38, 35, 35, 2,
  37, 254, 194, 165, 165, 1, 62, 166, 39, 219, 227, 228, 216, 41, 45, 1, 12,
  138, 155, 20, 2, 170, 253, 86, 5, 182, 253, 152, 2, 104, 253, 152, 215, 203,
  208, 220, 160, 1, 12, 134, 120, 0, 1, 0, 23, 0, 0, 4, 141, 5, 182, 0, 18, 0,
  105, 181, 16, 17, 128, 17, 2, 17, 184, 255, 192, 64, 59, 21, 24, 72, 17, 17,
  0, 11, 90, 12, 255, 14, 1, 14, 14, 224, 12, 240, 12, 2, 70, 12, 86, 12, 2, 55,
  12, 1, 12, 12, 19, 6, 90, 5, 20, 18, 13, 95, 15, 10, 95, 48, 0, 64, 0, 160, 0,
  176, 0, 208, 0, 5, 0, 0, 12, 15, 3, 6, 12, 18, 0, 63, 51, 63, 18, 57, 47, 93,
  225, 16, 225, 50, 1, 16, 222, 225, 18, 57, 47, 93, 93, 93, 51, 47, 93, 16,
  225, 50, 50, 47, 43, 93, 49, 48, 1, 33, 50, 22, 21, 17, 35, 17, 52, 35, 35,
  17, 35, 17, 33, 53, 33, 21, 33, 1, 252, 1, 8, 187, 206, 186, 227, 244, 186,
  254, 213, 3, 73, 254, 156, 3, 129, 193, 178, 253, 242, 1, 246, 231, 253, 35,
  5, 18, 164, 164, 0, 255, 255, 0, 211, 0, 0, 4, 174, 7, 115, 2, 38, 1, 180, 0,
  0, 1, 7, 0, 118, 0, 156, 1, 82, 0, 19, 64, 11, 1, 17, 5, 38, 1, 66, 11, 14, 4,
  0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 27, 255, 236, 4, 176, 7, 105, 2,
  38, 1, 189, 0, 0, 1, 7, 2, 54, 0, 6, 1, 82, 0, 19, 64, 11, 1, 26, 5, 38, 1, 6,
  29, 24, 14, 0, 37, 1, 43, 53, 0, 43, 53, 0, 0, 1, 0, 135, 254, 127, 4, 70, 5,
  182, 0, 11, 0, 67, 64, 42, 2, 90, 0, 3, 16, 3, 144, 3, 160, 3, 192, 3, 208, 3,
  6, 3, 3, 5, 9, 90, 0, 13, 8, 90, 0, 5, 224, 5, 240, 5, 3, 5, 10, 6, 3, 8, 95,
  5, 3, 3, 1, 5, 0, 47, 51, 51, 47, 16, 225, 63, 51, 1, 47, 93, 225, 16, 222,
  225, 17, 57, 47, 93, 225, 49, 48, 33, 33, 17, 35, 17, 33, 17, 51, 17, 33, 17,
  51, 4, 70, 254, 118, 176, 254, 123, 187, 2, 73, 187, 254, 127, 1, 129, 5, 182,
  250, 240, 5, 16, 255, 255, 0, 33, 0, 0, 4, 172, 5, 188, 2, 6, 0, 36, 0, 0, 0,
  2, 0, 135, 0, 0, 4, 111, 5, 182, 0, 11, 0, 19, 0, 51, 64, 29, 15, 91, 3, 8,
  21, 5, 12, 90, 0, 0, 224, 0, 240, 0, 3, 0, 19, 95, 5, 5, 12, 4, 95, 1, 3, 12,
  96, 0, 18, 0, 63, 225, 63, 225, 18, 57, 47, 225, 1, 47, 93, 225, 50, 16, 222,
  50, 225, 49, 48, 51, 17, 33, 21, 33, 17, 33, 32, 17, 20, 4, 35, 37, 33, 32,
  17, 52, 38, 35, 35, 135, 3, 144, 253, 43, 1, 16, 2, 29, 254, 249, 251, 254,
  213, 1, 26, 1, 82, 171, 198, 251, 5, 182, 164, 254, 60, 254, 94, 208, 220,
  160, 1, 12, 133, 121, 255, 255, 0, 135, 0, 0, 4, 113, 5, 182, 2, 6, 0, 37, 0,
  0, 255, 255, 0, 246, 0, 0, 4, 47, 5, 182, 2, 6, 1, 97, 0, 0, 0, 2, 0, 6, 254,
  127, 4, 197, 5, 182, 0, 13, 0, 19, 0, 129, 64, 25, 9, 16, 18, 24, 72, 11, 18,
  1, 18, 32, 11, 24, 72, 11, 8, 1, 8, 32, 11, 24, 72, 25, 10, 1, 19, 184, 255,
  240, 64, 13, 9, 24, 72, 19, 91, 7, 16, 90, 10, 20, 7, 1, 10, 184, 255, 192,
  64, 37, 10, 24, 72, 2, 10, 1, 7, 10, 7, 10, 5, 12, 1, 251, 0, 0, 14, 90, 12,
  21, 4, 251, 5, 16, 95, 10, 3, 19, 12, 6, 95, 3, 0, 5, 5, 3, 18, 0, 63, 51, 47,
  51, 16, 225, 50, 50, 63, 225, 1, 47, 225, 16, 220, 225, 51, 47, 225, 17, 18,
  57, 57, 47, 47, 93, 43, 93, 16, 225, 16, 225, 43, 93, 49, 48, 43, 93, 43, 93,
  43, 1, 35, 17, 33, 17, 35, 17, 51, 54, 18, 19, 33, 17, 51, 33, 17, 35, 2, 2,
  7, 4, 197, 177, 252, 162, 176, 113, 129, 174, 12, 2, 80, 195, 254, 131, 242,
  17, 163, 107, 254, 127, 1, 129, 254, 127, 2, 39, 236, 2, 204, 1, 88, 250, 240,
  4, 106, 254, 246, 253, 107, 203, 255, 255, 0, 217, 0, 0, 4, 35, 5, 182, 2, 6,
  0, 40, 0, 0, 0, 1, 0, 0, 0, 0, 4, 205, 5, 182, 0, 17, 0, 203, 64, 76, 103, 9,
  119, 9, 135, 9, 3, 6, 9, 22, 9, 54, 9, 70, 9, 86, 9, 5, 9, 5, 5, 70, 13, 86,
  13, 246, 13, 3, 55, 13, 1, 5, 13, 21, 13, 2, 13, 90, 104, 0, 120, 0, 136, 0,
  3, 9, 0, 25, 0, 57, 0, 73, 0, 89, 0, 5, 0, 4, 4, 103, 14, 1, 9, 14, 25, 14, 2,
  14, 14, 17, 10, 103, 2, 1, 2, 1, 184, 255, 240, 64, 9, 1, 1, 103, 16, 135, 16,
  2, 16, 17, 184, 255, 240, 64, 50, 17, 104, 7, 136, 7, 2, 7, 8, 16, 8, 8, 104,
  11, 136, 11, 2, 11, 16, 10, 64, 10, 80, 10, 144, 10, 160, 10, 192, 10, 208,
  10, 7, 10, 16, 10, 12, 15, 6, 3, 15, 3, 1, 17, 14, 10, 18, 7, 4, 1, 3, 0, 63,
  51, 51, 63, 51, 51, 18, 57, 57, 17, 51, 17, 51, 1, 47, 56, 93, 51, 93, 51, 47,
  56, 51, 93, 47, 56, 51, 93, 51, 47, 56, 50, 93, 17, 18, 57, 47, 93, 93, 51,
  17, 51, 93, 93, 225, 93, 93, 93, 50, 17, 51, 93, 93, 49, 48, 1, 1, 51, 1, 17,
  51, 17, 1, 51, 1, 1, 35, 1, 17, 35, 17, 1, 35, 1, 117, 254, 151, 178, 1, 93,
  155, 1, 86, 178, 254, 156, 1, 115, 185, 254, 162, 155, 254, 155, 182, 2, 242,
  2, 196, 253, 60, 2, 196, 253, 60, 2, 196, 253, 60, 253, 14, 2, 229, 253, 27,
  2, 229, 253, 27, 0, 0, 1, 0, 139, 255, 236, 4, 47, 5, 203, 0, 35, 0, 81, 64,
  46, 6, 0, 22, 0, 2, 0, 17, 22, 91, 33, 33, 4, 17, 17, 9, 14, 91, 4, 37, 28, 0,
  9, 1, 9, 0, 17, 96, 104, 18, 1, 159, 18, 1, 18, 18, 12, 27, 25, 96, 30, 4, 12,
  96, 10, 7, 19, 0, 63, 51, 225, 63, 225, 51, 18, 57, 47, 93, 93, 225, 57, 1,
  47, 93, 51, 16, 222, 225, 17, 57, 47, 17, 51, 47, 225, 18, 57, 93, 49, 48, 1,
  21, 22, 22, 21, 20, 4, 33, 34, 39, 53, 22, 51, 32, 17, 16, 33, 35, 53, 51, 50,
  54, 53, 52, 38, 35, 34, 7, 39, 54, 33, 50, 22, 21, 20, 6, 2, 190, 178, 191,
  254, 228, 254, 251, 242, 145, 184, 199, 1, 99, 254, 118, 190, 176, 180, 201,
  140, 118, 186, 168, 93, 194, 1, 5, 209, 235, 179, 3, 2, 6, 23, 182, 143, 203,
  233, 79, 170, 96, 1, 27, 1, 8, 151, 148, 125, 103, 122, 121, 125, 150, 198,
  165, 137, 186, 0, 0, 1, 0, 137, 0, 0, 4, 70, 5, 182, 0, 16, 0, 98, 185, 0, 15,
  255, 240, 64, 64, 14, 24, 72, 53, 15, 69, 15, 2, 7, 16, 14, 24, 72, 58, 7, 74,
  7, 2, 13, 9, 7, 25, 7, 41, 7, 3, 7, 10, 251, 224, 9, 240, 9, 2, 9, 105, 18, 6,
  15, 22, 15, 38, 15, 3, 15, 5, 1, 251, 0, 0, 224, 0, 240, 0, 3, 0, 16, 5, 9,
  18, 13, 7, 0, 3, 0, 63, 50, 50, 63, 51, 51, 1, 47, 93, 225, 50, 50, 93, 16,
  254, 93, 225, 50, 93, 50, 49, 48, 93, 43, 93, 43, 19, 51, 17, 20, 7, 7, 51, 1,
  51, 17, 35, 17, 52, 19, 35, 1, 35, 137, 174, 7, 7, 6, 2, 66, 213, 172, 18, 8,
  253, 188, 215, 5, 182, 252, 224, 142, 112, 150, 4, 180, 250, 74, 3, 25, 140,
  1, 21, 251, 70, 0, 255, 255, 0, 137, 0, 0, 4, 70, 7, 105, 2, 38, 1, 178, 0, 0,
  1, 7, 2, 54, 0, 0, 1, 82, 0, 21, 180, 1, 19, 5, 38, 1, 184, 255, 255, 180, 22,
  17, 0, 8, 37, 1, 43, 53, 0, 43, 53, 0, 0, 1, 0, 211, 0, 0, 4, 174, 5, 182, 0,
  10, 0, 130, 64, 96, 5, 7, 21, 7, 37, 7, 213, 7, 229, 7, 245, 7, 6, 10, 2, 26,
  2, 42, 2, 218, 2, 234, 2, 250, 2, 6, 39, 10, 1, 10, 7, 7, 3, 90, 0, 4, 96, 4,
  112, 4, 128, 4, 4, 4, 41, 8, 217, 8, 233, 8, 249, 8, 4, 8, 9, 16, 9, 9, 41, 1,
  217, 1, 233, 1, 249, 1, 4, 1, 208, 0, 240, 0, 2, 127, 0, 1, 0, 0, 16, 0, 64,
  0, 96, 0, 4, 0, 16, 0, 7, 2, 8, 5, 3, 4, 0, 18, 0, 63, 50, 63, 51, 57, 57, 1,
  47, 56, 93, 93, 93, 50, 93, 50, 47, 56, 51, 93, 47, 93, 225, 50, 17, 51, 93,
  49, 48, 0, 93, 93, 33, 35, 1, 17, 35, 17, 51, 17, 1, 51, 1, 4, 174, 219, 253,
  186, 186, 186, 2, 54, 206, 253, 203, 2, 229, 253, 27, 5, 182, 253, 60, 2, 196,
  253, 66, 0, 0, 1, 0, 4, 255, 233, 4, 70, 5, 182, 0, 15, 0, 111, 64, 33, 13,
  64, 20, 24, 72, 173, 13, 1, 124, 13, 140, 13, 156, 13, 3, 90, 13, 106, 13, 2,
  45, 13, 61, 13, 77, 13, 3, 11, 13, 27, 13, 2, 5, 184, 255, 240, 64, 16, 9, 24,
  72, 4, 24, 9, 24, 72, 3, 90, 0, 14, 16, 14, 2, 14, 184, 255, 192, 64, 22, 13,
  24, 72, 14, 14, 8, 1, 90, 0, 17, 8, 3, 95, 14, 3, 11, 96, 9, 6, 19, 0, 18, 0,
  63, 63, 51, 225, 63, 225, 1, 47, 16, 222, 225, 18, 57, 47, 43, 93, 225, 49,
  48, 43, 43, 93, 93, 93, 93, 93, 43, 33, 35, 17, 33, 2, 2, 35, 34, 39, 53, 22,
  51, 50, 18, 19, 33, 4, 70, 187, 254, 215, 117, 177, 175, 71, 66, 57, 56, 102,
  110, 126, 2, 127, 5, 18, 252, 47, 254, 168, 25, 150, 25, 1, 105, 3, 206, 0,
  255, 255, 0, 113, 0, 0, 4, 92, 5, 182, 2, 6, 0, 48, 0, 0, 255, 255, 0, 135, 0,
  0, 4, 70, 5, 182, 2, 6, 0, 43, 0, 0, 255, 255, 0, 84, 255, 236, 4, 123, 5,
  205, 2, 6, 0, 50, 0, 0, 255, 255, 0, 135, 0, 0, 4, 70, 5, 182, 2, 6, 1, 110,
  0, 0, 255, 255, 0, 176, 0, 0, 4, 70, 5, 182, 2, 6, 0, 51, 0, 0, 255, 255, 0,
  129, 255, 236, 4, 156, 5, 203, 2, 6, 0, 38, 0, 0, 255, 255, 0, 102, 0, 0, 4,
  100, 5, 182, 2, 6, 0, 55, 0, 0, 0, 1, 0, 27, 255, 236, 4, 176, 5, 182, 0, 23,
  0, 162, 64, 9, 8, 13, 24, 13, 2, 13, 1, 20, 20, 184, 255, 224, 179, 20, 24,
  72, 20, 184, 255, 224, 64, 89, 15, 18, 72, 7, 20, 7, 20, 14, 232, 23, 1, 73,
  23, 89, 23, 2, 56, 23, 1, 41, 23, 1, 26, 23, 1, 9, 23, 1, 23, 0, 0, 25, 231,
  15, 1, 70, 15, 86, 15, 2, 55, 15, 1, 38, 15, 1, 21, 15, 1, 6, 15, 1, 15, 31,
  14, 79, 14, 95, 14, 111, 14, 4, 14, 14, 24, 101, 20, 1, 54, 20, 230, 20, 2,
  37, 20, 1, 13, 1, 20, 3, 0, 10, 95, 8, 5, 19, 14, 0, 3, 0, 63, 50, 63, 51,
  225, 17, 23, 57, 93, 93, 93, 17, 1, 51, 47, 93, 51, 93, 93, 93, 93, 93, 93,
  17, 51, 47, 51, 93, 93, 93, 93, 93, 93, 18, 57, 57, 61, 47, 24, 47, 43, 43,
  17, 51, 51, 93, 49, 48, 1, 1, 14, 2, 35, 34, 39, 53, 22, 51, 50, 54, 55, 1,
  51, 1, 22, 23, 22, 23, 51, 55, 1, 4, 176, 254, 84, 76, 120, 178, 126, 104, 74,
  85, 93, 110, 121, 54, 253, 238, 204, 1, 127, 12, 8, 8, 9, 2, 39, 1, 56, 5,
  182, 251, 250, 183, 171, 98, 30, 185, 45, 103, 122, 4, 63, 252, 215, 25, 22,
  25, 20, 109, 3, 24, 255, 255, 0, 27, 255, 236, 4, 180, 5, 203, 2, 6, 1, 115,
  0, 0, 255, 255, 0, 53, 0, 0, 4, 150, 5, 182, 2, 6, 0, 59, 0, 0, 0, 1, 0, 135,
  254, 127, 4, 186, 5, 182, 0, 11, 0, 58, 64, 34, 3, 251, 2, 2, 9, 90, 127, 0,
  143, 0, 2, 0, 13, 8, 90, 0, 5, 224, 5, 240, 5, 3, 5, 10, 6, 3, 0, 8, 95, 5, 3,
  3, 5, 18, 0, 63, 51, 47, 16, 225, 50, 63, 51, 1, 47, 93, 225, 16, 220, 93,
  225, 51, 47, 225, 49, 48, 37, 51, 17, 35, 17, 33, 17, 51, 17, 33, 17, 51, 4,
  10, 176, 176, 252, 125, 187, 2, 14, 186, 166, 253, 217, 1, 129, 5, 182, 250,
  240, 5, 16, 0, 0, 1, 0, 135, 0, 0, 4, 70, 5, 182, 0, 16, 0, 47, 64, 26, 14, 1,
  90, 0, 18, 9, 90, 0, 6, 224, 6, 240, 6, 3, 6, 14, 12, 95, 4, 4, 1, 15, 7, 3,
  1, 18, 0, 63, 63, 51, 18, 57, 47, 225, 51, 1, 47, 93, 225, 16, 222, 225, 50,
  49, 48, 33, 35, 17, 6, 35, 32, 17, 17, 51, 17, 20, 22, 51, 50, 55, 17, 51, 4,
  70, 187, 227, 166, 254, 133, 187, 103, 110, 153, 219, 187, 2, 86, 90, 1, 115,
  2, 71, 253, 209, 130, 101, 80, 2, 198, 0, 0, 1, 0, 121, 0, 0, 4, 86, 5, 182,
  0, 11, 0, 92, 64, 64, 101, 8, 1, 86, 8, 1, 55, 8, 71, 8, 247, 8, 3, 123, 5,
  139, 5, 2, 8, 90, 5, 5, 1, 9, 90, 192, 0, 208, 0, 2, 15, 0, 63, 0, 2, 0, 13,
  4, 90, 0, 1, 16, 1, 48, 1, 64, 1, 80, 1, 144, 1, 160, 1, 7, 1, 10, 6, 2, 3, 8,
  4, 95, 1, 18, 0, 63, 225, 50, 63, 51, 51, 1, 47, 93, 225, 16, 222, 93, 93,
  225, 17, 57, 47, 225, 93, 93, 93, 93, 49, 48, 33, 33, 17, 51, 17, 51, 17, 51,
  17, 51, 17, 51, 4, 86, 252, 35, 166, 245, 166, 246, 166, 5, 182, 250, 240, 5,
  16, 250, 240, 5, 16, 0, 0, 1, 0, 61, 254, 127, 4, 205, 5, 182, 0, 15, 0, 127,
  64, 89, 101, 12, 1, 86, 12, 1, 55, 12, 71, 12, 247, 12, 3, 123, 9, 139, 9, 2,
  12, 90, 9, 9, 5, 0, 3, 251, 0, 2, 144, 2, 160, 2, 176, 2, 224, 2, 240, 2, 6,
  2, 2, 13, 90, 191, 0, 239, 0, 255, 0, 3, 15, 0, 63, 0, 159, 0, 175, 0, 4, 0,
  17, 8, 90, 144, 5, 160, 5, 2, 47, 5, 111, 5, 127, 5, 3, 5, 14, 10, 6, 3, 12,
  0, 8, 95, 5, 3, 3, 5, 18, 0, 63, 51, 47, 16, 225, 50, 50, 63, 51, 51, 1, 47,
  93, 93, 225, 16, 221, 93, 93, 225, 51, 47, 93, 225, 17, 18, 57, 47, 225, 93,
  93, 93, 93, 49, 48, 37, 51, 17, 35, 17, 33, 17, 51, 17, 51, 17, 51, 17, 51,
  17, 51, 4, 27, 178, 176, 252, 32, 166, 246, 166, 246, 166, 166, 253, 217, 1,
  129, 5, 182, 250, 240, 5, 16, 250, 240, 5, 16, 0, 0, 2, 0, 27, 0, 0, 4, 117,
  5, 182, 0, 12, 0, 20, 0, 59, 64, 33, 5, 13, 90, 31, 0, 143, 0, 255, 0, 3, 0,
  0, 2, 16, 91, 9, 22, 2, 2, 21, 20, 95, 5, 5, 13, 2, 95, 3, 3, 13, 96, 0, 18,
  0, 63, 225, 63, 225, 18, 57, 47, 225, 17, 1, 51, 47, 16, 222, 225, 17, 57, 47,
  93, 225, 50, 49, 48, 33, 17, 33, 53, 33, 17, 51, 32, 4, 21, 20, 4, 33, 39, 51,
  32, 17, 52, 38, 35, 35, 1, 70, 254, 213, 1, 229, 68, 1, 14, 1, 35, 254, 235,
  254, 254, 94, 98, 1, 82, 171, 197, 68, 5, 18, 164, 253, 152, 218, 200, 202,
  226, 160, 1, 12, 132, 122, 0, 3, 0, 96, 0, 0, 4, 109, 5, 182, 0, 9, 0, 17, 0,
  21, 0, 83, 64, 53, 73, 13, 1, 13, 251, 0, 6, 16, 6, 48, 6, 112, 6, 128, 6,
  240, 6, 6, 6, 6, 0, 18, 251, 15, 21, 63, 21, 2, 21, 23, 3, 10, 90, 32, 0, 48,
  0, 2, 0, 0, 22, 17, 95, 3, 3, 19, 1, 3, 10, 96, 18, 0, 18, 0, 63, 50, 225, 63,
  51, 57, 47, 225, 17, 1, 51, 47, 93, 225, 50, 16, 222, 93, 225, 17, 57, 47, 93,
  225, 93, 49, 48, 51, 17, 51, 17, 51, 32, 17, 20, 4, 35, 39, 51, 32, 17, 52,
  38, 35, 35, 1, 17, 51, 17, 96, 166, 47, 2, 29, 254, 249, 251, 74, 78, 1, 82,
  171, 198, 47, 2, 193, 166, 5, 182, 253, 152, 254, 94, 208, 220, 160, 1, 12,
  133, 121, 253, 86, 5, 182, 250, 74, 0, 2, 0, 176, 0, 0, 4, 70, 5, 182, 0, 9,
  0, 17, 0, 60, 64, 16, 13, 91, 239, 6, 255, 6, 2, 6, 19, 3, 10, 90, 0, 0, 1, 0,
  184, 255, 192, 64, 16, 18, 22, 72, 0, 0, 18, 17, 95, 3, 3, 1, 3, 10, 96, 0,
  18, 0, 63, 225, 63, 57, 47, 225, 17, 1, 51, 47, 43, 93, 225, 50, 16, 222, 93,
  225, 49, 48, 51, 17, 51, 17, 51, 32, 17, 20, 4, 35, 39, 51, 32, 17, 52, 38,
  35, 35, 176, 186, 191, 2, 29, 254, 249, 251, 218, 201, 1, 82, 171, 198, 170,
  5, 182, 253, 152, 254, 94, 208, 220, 160, 1, 12, 133, 121, 0, 1, 0, 68, 255,
  236, 4, 76, 5, 203, 0, 23, 0, 74, 64, 43, 127, 17, 143, 17, 2, 17, 17, 11, 19,
  16, 91, 255, 6, 1, 6, 25, 1, 31, 11, 47, 11, 2, 11, 11, 24, 17, 95, 104, 18,
  1, 18, 18, 3, 14, 95, 12, 9, 19, 22, 95, 0, 3, 4, 0, 63, 51, 225, 63, 51, 225,
  17, 57, 47, 93, 225, 17, 1, 51, 47, 93, 51, 16, 222, 93, 225, 50, 18, 57, 47,
  93, 49, 48, 19, 39, 54, 51, 32, 0, 17, 16, 0, 33, 34, 39, 53, 22, 51, 32, 19,
  33, 53, 33, 38, 38, 35, 34, 145, 77, 161, 222, 1, 48, 1, 89, 254, 170, 254,
  196, 212, 146, 197, 131, 1, 217, 16, 253, 139, 2, 113, 19, 237, 190, 152, 4,
  217, 156, 86, 254, 123, 254, 176, 254, 139, 254, 107, 59, 162, 58, 2, 29, 162,
  222, 251, 0, 0, 2, 0, 98, 255, 236, 4, 135, 5, 205, 0, 18, 0, 30, 0, 110, 64,
  43, 28, 251, 7, 15, 0, 47, 0, 79, 0, 95, 0, 127, 0, 143, 0, 6, 0, 64, 21, 24,
  72, 0, 0, 3, 22, 251, 13, 64, 9, 14, 72, 13, 32, 6, 55, 2, 1, 2, 90, 102, 3,
  1, 3, 184, 255, 192, 64, 26, 11, 14, 72, 3, 3, 31, 1, 95, 104, 6, 1, 6, 6, 10,
  19, 95, 16, 19, 25, 95, 10, 4, 4, 3, 2, 18, 0, 63, 63, 63, 225, 63, 225, 17,
  57, 47, 93, 225, 17, 1, 51, 47, 43, 93, 225, 93, 50, 16, 222, 43, 225, 18, 57,
  47, 43, 93, 51, 225, 49, 48, 1, 35, 17, 35, 17, 51, 17, 51, 18, 18, 51, 50,
  18, 17, 16, 2, 35, 34, 2, 5, 50, 54, 17, 16, 38, 35, 34, 6, 17, 16, 22, 1,
  147, 139, 166, 166, 144, 18, 175, 183, 192, 183, 184, 193, 190, 179, 1, 113,
  106, 95, 96, 105, 108, 94, 93, 2, 170, 253, 86, 5, 182, 253, 152, 1, 93, 1,
  34, 254, 159, 254, 113, 254, 115, 254, 156, 1, 59, 152, 233, 1, 101, 1, 104,
  228, 237, 254, 161, 254, 164, 242, 0, 2, 0, 57, 0, 0, 4, 18, 5, 182, 0, 11, 0,
  19, 0, 113, 64, 31, 11, 4, 27, 4, 2, 11, 6, 27, 6, 2, 3, 16, 12, 17, 72, 3, 0,
  5, 19, 10, 90, 143, 9, 159, 9, 175, 9, 3, 9, 21, 1, 184, 255, 240, 180, 12,
  17, 72, 1, 2, 184, 255, 240, 183, 2, 2, 15, 91, 0, 5, 1, 5, 184, 255, 192, 64,
  19, 19, 22, 72, 5, 5, 20, 3, 0, 96, 18, 18, 1, 13, 96, 7, 3, 10, 1, 18, 0, 63,
  51, 63, 225, 18, 57, 47, 225, 50, 17, 1, 51, 47, 43, 93, 225, 51, 47, 56, 51,
  43, 16, 222, 93, 225, 50, 17, 57, 57, 43, 49, 48, 93, 93, 1, 1, 35, 1, 36, 17,
  16, 33, 33, 17, 35, 17, 17, 35, 32, 17, 20, 22, 51, 51, 2, 98, 254, 178, 219,
  1, 125, 254, 240, 1, 248, 1, 116, 186, 188, 254, 202, 164, 154, 180, 2, 92,
  253, 164, 2, 143, 98, 1, 54, 1, 143, 250, 74, 2, 92, 2, 187, 255, 0, 137, 148,
  255, 255, 0, 135, 255, 236, 4, 2, 4, 94, 2, 6, 0, 68, 0, 0, 0, 2, 0, 143, 255,
  236, 4, 59, 6, 35, 0, 22, 0, 31, 0, 62, 64, 37, 27, 72, 1, 11, 64, 21, 24, 72,
  11, 33, 5, 23, 72, 0, 17, 208, 17, 224, 17, 240, 17, 4, 17, 23, 5, 29, 80, 8,
  8, 0, 25, 80, 14, 22, 1, 0, 1, 0, 63, 50, 63, 225, 17, 57, 47, 225, 50, 50, 1,
  47, 93, 225, 50, 16, 222, 43, 50, 225, 49, 48, 1, 23, 4, 6, 6, 7, 51, 54, 51,
  50, 18, 21, 16, 2, 35, 34, 2, 17, 52, 18, 62, 2, 1, 16, 33, 32, 17, 16, 35,
  34, 6, 4, 16, 33, 254, 115, 205, 127, 8, 12, 116, 220, 186, 213, 250, 221,
  219, 250, 62, 104, 138, 202, 254, 195, 1, 37, 1, 10, 240, 95, 177, 6, 35, 160,
  67, 65, 217, 210, 170, 254, 249, 229, 254, 252, 254, 222, 1, 104, 1, 63, 212,
  1, 32, 176, 106, 57, 252, 181, 253, 244, 1, 119, 1, 108, 127, 0, 0, 3, 0, 176,
  0, 0, 4, 84, 4, 74, 0, 12, 0, 20, 0, 28, 0, 91, 181, 4, 4, 20, 4, 2, 10, 184,
  255, 208, 64, 49, 9, 12, 72, 0, 14, 18, 70, 11, 11, 25, 70, 3, 30, 14, 22, 71,
  0, 7, 144, 7, 160, 7, 176, 7, 4, 7, 0, 21, 80, 191, 14, 1, 137, 14, 1, 120,
  14, 1, 14, 14, 22, 13, 80, 8, 15, 22, 80, 7, 21, 0, 63, 225, 63, 225, 18, 57,
  47, 93, 93, 93, 225, 57, 1, 47, 93, 225, 50, 16, 222, 225, 51, 47, 225, 18,
  57, 49, 48, 43, 93, 1, 21, 4, 21, 20, 6, 35, 33, 17, 33, 32, 17, 20, 1, 17,
  33, 50, 54, 53, 52, 35, 1, 17, 33, 50, 53, 52, 38, 35, 3, 76, 1, 8, 212, 208,
  254, 0, 1, 254, 1, 131, 253, 53, 1, 37, 134, 114, 217, 254, 188, 1, 62, 254,
  130, 128, 2, 70, 7, 35, 223, 149, 168, 4, 74, 254, 235, 197, 1, 64, 254, 215,
  72, 84, 141, 254, 62, 254, 168, 180, 92, 72, 0, 1, 1, 35, 0, 0, 4, 14, 4, 74,
  0, 5, 0, 46, 64, 28, 2, 71, 31, 3, 111, 3, 127, 3, 143, 3, 4, 127, 0, 143, 0,
  2, 3, 0, 3, 0, 6, 7, 1, 80, 4, 15, 2, 21, 0, 63, 63, 225, 17, 18, 1, 57, 57,
  47, 47, 93, 93, 225, 49, 48, 1, 33, 17, 35, 17, 33, 4, 14, 253, 203, 182, 2,
  235, 3, 176, 252, 80, 4, 74, 0, 0, 2, 0, 33, 254, 131, 4, 104, 4, 74, 0, 12,
  0, 17, 0, 116, 64, 9, 40, 8, 1, 9, 8, 25, 8, 2, 17, 184, 255, 240, 179, 15,
  24, 72, 17, 184, 255, 224, 64, 53, 11, 14, 72, 17, 7, 15, 9, 80, 9, 128, 9, 2,
  18, 9, 1, 7, 9, 7, 9, 5, 11, 1, 70, 0, 0, 13, 71, 79, 11, 95, 11, 111, 11, 3,
  11, 19, 4, 71, 5, 15, 78, 9, 15, 17, 11, 6, 80, 3, 1, 4, 4, 3, 21, 0, 63, 51,
  47, 51, 16, 225, 50, 50, 63, 225, 1, 47, 225, 16, 220, 93, 225, 51, 47, 225,
  17, 18, 57, 57, 47, 47, 93, 93, 17, 51, 17, 51, 43, 43, 49, 48, 93, 93, 1, 35,
  17, 33, 17, 35, 17, 51, 0, 19, 33, 17, 51, 33, 17, 35, 2, 3, 4, 104, 176, 253,
  25, 176, 86, 1, 6, 4, 2, 80, 151, 254, 179, 250, 36, 198, 254, 131, 1, 125,
  254, 131, 2, 23, 1, 133, 2, 43, 252, 80, 3, 36, 254, 31, 254, 189, 255, 255,
  0, 133, 255, 236, 4, 72, 4, 94, 2, 6, 0, 72, 0, 0, 0, 1, 0, 0, 0, 0, 4, 205,
  4, 74, 0, 17, 1, 8, 64, 140, 105, 15, 121, 15, 137, 15, 3, 75, 15, 91, 15, 2,
  41, 15, 57, 15, 2, 26, 15, 1, 9, 15, 1, 102, 6, 118, 6, 134, 6, 3, 68, 6, 84,
  6, 2, 38, 6, 54, 6, 2, 21, 6, 1, 6, 6, 1, 166, 6, 1, 6, 3, 247, 10, 1, 86, 10,
  102, 10, 2, 23, 10, 55, 10, 71, 10, 3, 6, 10, 1, 10, 71, 169, 15, 1, 15, 0,
  24, 11, 1, 9, 11, 1, 11, 11, 14, 7, 104, 4, 120, 4, 136, 4, 3, 4, 16, 11, 14,
  72, 4, 5, 16, 5, 5, 136, 8, 1, 8, 16, 11, 16, 72, 8, 16, 7, 64, 7, 80, 7, 144,
  7, 160, 7, 192, 7, 208, 7, 7, 7, 16, 7, 7, 19, 103, 17, 119, 17, 135, 17, 3,
  17, 184, 255, 240, 180, 11, 14, 72, 17, 16, 184, 255, 240, 181, 16, 16, 135,
  13, 1, 13, 184, 255, 240, 180, 11, 16, 72, 13, 14, 184, 255, 240, 64, 18, 14,
  14, 18, 9, 12, 3, 0, 12, 0, 1, 14, 11, 7, 21, 16, 4, 1, 15, 0, 63, 51, 51, 63,
  51, 51, 18, 57, 57, 17, 51, 17, 51, 17, 1, 51, 47, 56, 51, 43, 93, 51, 47, 56,
  51, 43, 93, 17, 51, 47, 56, 93, 51, 43, 93, 51, 47, 56, 51, 43, 93, 17, 18,
  57, 47, 93, 93, 51, 51, 93, 225, 93, 93, 93, 93, 50, 50, 93, 49, 48, 93, 93,
  93, 93, 93, 93, 93, 93, 93, 93, 1, 17, 51, 17, 1, 51, 1, 1, 35, 1, 17, 35, 17,
  1, 35, 1, 1, 51, 2, 23, 159, 1, 94, 185, 254, 145, 1, 109, 195, 254, 174, 159,
  254, 174, 195, 1, 111, 254, 143, 184, 2, 53, 2, 21, 253, 235, 2, 21, 253, 235,
  253, 203, 2, 45, 253, 211, 2, 45, 253, 211, 2, 53, 2, 21, 0, 1, 0, 201, 255,
  236, 4, 8, 4, 94, 0, 32, 0, 87, 64, 51, 15, 13, 32, 32, 8, 3, 70, 13, 13, 28,
  70, 18, 34, 8, 0, 23, 96, 23, 112, 23, 128, 23, 4, 23, 23, 33, 15, 31, 80,
  191, 32, 1, 137, 32, 1, 120, 32, 1, 32, 32, 10, 26, 80, 24, 21, 22, 7, 5, 80,
  10, 16, 0, 63, 225, 51, 63, 51, 225, 17, 57, 47, 93, 93, 93, 225, 57, 17, 1,
  51, 47, 93, 51, 16, 222, 225, 51, 47, 225, 17, 57, 47, 18, 57, 49, 48, 1, 50,
  54, 53, 52, 35, 34, 7, 39, 54, 51, 50, 22, 21, 20, 7, 21, 22, 21, 20, 6, 35,
  34, 39, 53, 22, 51, 32, 53, 52, 33, 35, 53, 1, 250, 172, 145, 250, 134, 175,
  63, 160, 210, 205, 221, 192, 227, 241, 224, 235, 127, 180, 186, 1, 27, 254,
  201, 150, 2, 135, 79, 87, 154, 72, 147, 76, 149, 140, 186, 57, 11, 65, 207,
  151, 172, 69, 166, 86, 180, 185, 153, 0, 1, 0, 160, 0, 0, 4, 45, 4, 74, 0, 11,
  0, 132, 185, 0, 9, 255, 240, 179, 18, 24, 72, 9, 184, 255, 224, 64, 80, 11,
  14, 72, 5, 9, 21, 9, 2, 3, 16, 18, 24, 72, 3, 32, 11, 14, 72, 10, 3, 26, 3, 2,
  139, 8, 1, 105, 8, 121, 8, 2, 132, 2, 1, 102, 2, 118, 2, 2, 8, 136, 3, 1, 105,
  3, 1, 3, 6, 70, 144, 5, 160, 5, 2, 5, 13, 135, 9, 1, 102, 9, 1, 9, 2, 0, 70,
  0, 11, 176, 11, 2, 11, 8, 3, 11, 15, 6, 2, 10, 21, 0, 63, 51, 51, 63, 51, 51,
  1, 47, 93, 225, 50, 50, 93, 93, 16, 222, 93, 225, 50, 93, 93, 50, 49, 48, 0,
  93, 93, 93, 93, 1, 93, 43, 43, 93, 43, 43, 1, 17, 7, 1, 51, 17, 35, 17, 19, 1,
  35, 17, 1, 76, 13, 2, 5, 233, 172, 10, 253, 254, 233, 4, 74, 253, 100, 252, 3,
  152, 251, 182, 2, 135, 1, 15, 252, 106, 4, 74, 255, 255, 0, 160, 0, 0, 4, 45,
  6, 23, 2, 38, 1, 210, 0, 0, 1, 6, 2, 54, 37, 0, 0, 31, 64, 20, 1, 14, 17, 38,
  1, 176, 17, 1, 128, 17, 1, 112, 17, 1, 36, 17, 12, 10, 4, 37, 1, 43, 93, 93,
  93, 53, 0, 43, 53, 0, 0, 1, 0, 215, 0, 0, 4, 150, 4, 74, 0, 10, 0, 139, 64,
  78, 88, 4, 1, 4, 16, 10, 13, 72, 230, 2, 246, 2, 2, 212, 2, 1, 150, 2, 166, 2,
  198, 2, 3, 133, 2, 1, 118, 2, 1, 101, 2, 1, 70, 2, 86, 2, 2, 53, 2, 1, 22, 2,
  38, 2, 2, 7, 2, 1, 88, 0, 1, 0, 16, 10, 13, 72, 6, 10, 1, 9, 5, 1, 0, 1, 1, 4,
  3, 12, 10, 2, 6, 71, 0, 7, 240, 7, 2, 7, 184, 255, 192, 64, 14, 15, 20, 72, 7,
  5, 10, 2, 3, 7, 3, 21, 8, 0, 15, 0, 63, 50, 63, 51, 23, 57, 1, 47, 43, 93,
  225, 50, 50, 16, 206, 50, 50, 47, 51, 49, 48, 0, 93, 93, 1, 43, 93, 93, 93,
  93, 93, 93, 93, 93, 93, 93, 93, 43, 93, 1, 51, 1, 1, 35, 1, 17, 35, 17, 51,
  17, 3, 145, 222, 253, 241, 2, 54, 232, 253, 221, 180, 180, 4, 74, 253, 241,
  253, 197, 2, 45, 253, 211, 4, 74, 253, 235, 0, 1, 0, 31, 255, 242, 4, 16, 4,
  74, 0, 15, 0, 206, 64, 11, 12, 32, 20, 24, 72, 153, 12, 169, 12, 2, 5, 184,
  255, 240, 64, 111, 21, 24, 72, 181, 5, 1, 166, 5, 1, 149, 5, 1, 84, 5, 100, 5,
  2, 50, 5, 66, 5, 2, 4, 5, 20, 5, 36, 5, 3, 4, 32, 12, 24, 72, 9, 4, 25, 4, 41,
  4, 3, 4, 3, 153, 3, 1, 120, 3, 136, 3, 2, 57, 3, 73, 3, 105, 3, 3, 3, 235, 13,
  251, 13, 2, 202, 13, 218, 13, 2, 153, 13, 169, 13, 185, 13, 3, 138, 13, 1, 13,
  32, 13, 16, 72, 25, 13, 41, 13, 57, 13, 3, 8, 13, 1, 13, 192, 14, 208, 14, 2,
  161, 14, 1, 16, 14, 32, 14, 48, 14, 3, 14, 184, 255, 192, 64, 25, 15, 18, 72,
  14, 14, 8, 1, 71, 143, 0, 1, 0, 17, 8, 3, 80, 14, 15, 11, 79, 9, 6, 22, 0, 21,
  0, 63, 63, 51, 225, 63, 225, 1, 47, 16, 222, 93, 225, 18, 57, 47, 43, 93, 93,
  93, 51, 93, 93, 43, 93, 93, 93, 93, 51, 93, 93, 93, 17, 51, 93, 43, 49, 48,
  93, 93, 93, 93, 93, 93, 43, 93, 43, 33, 35, 17, 33, 2, 2, 35, 34, 39, 53, 22,
  51, 50, 18, 19, 33, 4, 16, 182, 254, 172, 37, 178, 180, 62, 30, 21, 28, 111,
  135, 36, 2, 166, 3, 176, 254, 19, 254, 47, 12, 131, 6, 1, 219, 1, 244, 0, 1,
  0, 115, 0, 0, 4, 90, 4, 74, 0, 24, 0, 187, 64, 27, 24, 8, 72, 8, 2, 23, 7, 71,
  7, 2, 234, 8, 250, 8, 2, 8, 8, 17, 20, 72, 8, 229, 7, 245, 7, 2, 7, 184, 255,
  248, 64, 55, 17, 20, 72, 7, 18, 18, 13, 218, 23, 234, 23, 250, 23, 3, 23, 16,
  17, 21, 72, 92, 23, 108, 23, 124, 23, 3, 58, 23, 74, 23, 2, 25, 23, 41, 23, 2,
  23, 1, 73, 176, 0, 1, 15, 0, 1, 0, 26, 213, 15, 229, 15, 245, 15, 3, 15, 184,
  255, 240, 64, 48, 17, 21, 72, 83, 15, 99, 15, 115, 15, 3, 53, 15, 69, 15, 2,
  22, 15, 38, 15, 2, 15, 12, 73, 0, 13, 16, 13, 64, 13, 80, 13, 112, 13, 128,
  13, 6, 13, 2, 11, 11, 23, 14, 15, 18, 8, 1, 13, 21, 0, 63, 51, 51, 51, 63, 51,
  51, 17, 51, 1, 47, 93, 225, 50, 93, 93, 93, 43, 93, 16, 222, 93, 93, 225, 50,
  93, 93, 93, 43, 93, 18, 57, 61, 47, 51, 43, 93, 51, 43, 93, 49, 48, 93, 93,
  33, 35, 17, 6, 7, 6, 7, 3, 35, 3, 38, 39, 17, 35, 17, 51, 19, 22, 23, 54, 55,
  54, 55, 19, 51, 4, 90, 151, 8, 25, 22, 13, 213, 135, 213, 8, 60, 151, 211,
  215, 25, 48, 5, 48, 10, 11, 219, 207, 3, 129, 27, 100, 85, 38, 253, 121, 2,
  135, 25, 225, 252, 127, 4, 74, 253, 112, 77, 191, 13, 178, 39, 34, 2, 148, 0,
  0, 1, 0, 160, 0, 0, 4, 45, 4, 74, 0, 11, 0, 63, 64, 38, 2, 6, 71, 144, 5, 160,
  5, 2, 5, 13, 1, 9, 71, 0, 10, 176, 10, 2, 10, 8, 80, 191, 1, 1, 137, 1, 1,
  120, 1, 1, 1, 1, 10, 5, 21, 3, 0, 15, 0, 63, 50, 63, 51, 57, 47, 93, 93, 93,
  225, 1, 47, 93, 225, 50, 16, 222, 93, 225, 50, 49, 48, 1, 17, 33, 17, 51, 17,
  35, 17, 33, 17, 35, 17, 1, 86, 2, 33, 182, 182, 253, 223, 182, 4, 74, 254, 57,
  1, 199, 251, 182, 1, 233, 254, 23, 4, 74, 255, 255, 0, 115, 255, 236, 4, 88,
  4, 94, 2, 6, 0, 82, 0, 0, 0, 1, 0, 160, 0, 0, 4, 45, 4, 74, 0, 7, 0, 41, 64,
  24, 5, 71, 144, 4, 160, 4, 2, 4, 9, 0, 71, 0, 1, 176, 1, 2, 1, 7, 80, 2, 15,
  5, 0, 21, 0, 63, 50, 63, 225, 1, 47, 93, 225, 16, 222, 93, 225, 49, 48, 33,
  35, 17, 33, 17, 35, 17, 33, 1, 86, 182, 3, 141, 182, 253, 223, 4, 74, 251,
  182, 3, 176, 0, 255, 255, 0, 158, 254, 20, 4, 68, 4, 94, 2, 6, 0, 83, 0, 0,
  255, 255, 0, 172, 255, 236, 4, 37, 4, 94, 2, 6, 0, 70, 0, 0, 0, 1, 0, 121, 0,
  0, 4, 82, 4, 74, 0, 7, 0, 60, 64, 37, 159, 0, 175, 0, 2, 0, 0, 2, 71, 3, 224,
  5, 1, 5, 5, 16, 3, 144, 3, 160, 3, 192, 3, 208, 3, 5, 3, 3, 8, 9, 1, 5, 80, 6,
  15, 2, 21, 0, 63, 63, 225, 50, 17, 18, 1, 57, 47, 93, 51, 47, 93, 16, 225, 50,
  47, 93, 49, 48, 1, 33, 17, 35, 17, 33, 53, 33, 4, 82, 254, 111, 183, 254, 111,
  3, 217, 3, 176, 252, 80, 3, 176, 154, 255, 255, 0, 82, 254, 20, 4, 121, 4, 74,
  2, 6, 0, 92, 0, 0, 0, 3, 0, 74, 254, 20, 4, 129, 6, 20, 0, 13, 0, 18, 0, 23,
  0, 93, 64, 59, 20, 0, 86, 5, 102, 5, 2, 71, 5, 1, 5, 73, 14, 11, 6, 6, 9, 22,
  73, 15, 2, 1, 2, 25, 17, 73, 80, 9, 144, 9, 160, 9, 192, 9, 208, 9, 5, 47, 9,
  63, 9, 2, 9, 12, 0, 19, 15, 80, 0, 11, 16, 20, 14, 80, 4, 7, 22, 5, 27, 0, 63,
  63, 51, 225, 50, 63, 51, 225, 50, 63, 1, 47, 93, 93, 225, 16, 222, 93, 225,
  17, 57, 47, 51, 51, 225, 93, 93, 50, 50, 49, 48, 1, 4, 17, 16, 5, 17, 35, 17,
  36, 17, 16, 37, 17, 51, 3, 17, 4, 17, 16, 1, 17, 36, 17, 16, 2, 182, 1, 203,
  254, 53, 157, 254, 49, 1, 207, 157, 157, 254, 217, 1, 196, 1, 35, 4, 90, 50,
  253, 255, 253, 243, 42, 254, 36, 1, 220, 45, 2, 10, 2, 10, 41, 1, 186, 250,
  115, 3, 60, 29, 254, 129, 254, 126, 3, 28, 252, 198, 33, 1, 127, 1, 121, 255,
  255, 0, 96, 0, 0, 4, 106, 4, 74, 2, 6, 0, 91, 0, 0, 0, 1, 0, 152, 254, 131, 4,
  156, 4, 74, 0, 11, 0, 56, 64, 32, 1, 71, 0, 0, 7, 71, 111, 10, 127, 10, 143,
  10, 3, 10, 13, 6, 71, 0, 3, 1, 3, 8, 4, 15, 10, 6, 80, 3, 1, 1, 3, 21, 0, 63,
  51, 47, 16, 225, 50, 63, 51, 1, 47, 93, 225, 16, 220, 93, 225, 51, 47, 225,
  49, 48, 1, 35, 17, 33, 17, 51, 17, 33, 17, 51, 17, 51, 4, 156, 176, 252, 172,
  182, 1, 248, 182, 160, 254, 131, 1, 125, 4, 74, 252, 80, 3, 176, 252, 80, 0,
  1, 0, 152, 0, 0, 4, 37, 4, 74, 0, 16, 0, 47, 64, 25, 5, 9, 71, 144, 8, 1, 8,
  18, 1, 71, 0, 15, 1, 15, 10, 5, 3, 80, 12, 12, 8, 21, 6, 0, 15, 0, 63, 50, 63,
  57, 47, 225, 50, 50, 1, 47, 93, 225, 16, 222, 93, 225, 50, 49, 48, 1, 17, 20,
  51, 50, 55, 17, 51, 17, 35, 17, 6, 35, 34, 38, 53, 17, 1, 78, 205, 171, 169,
  182, 182, 181, 200, 160, 186, 4, 74, 254, 102, 174, 115, 1, 213, 251, 182, 1,
  233, 127, 175, 139, 1, 166, 0, 1, 0, 125, 0, 0, 4, 82, 4, 74, 0, 11, 0, 90,
  64, 63, 70, 0, 86, 0, 102, 0, 3, 0, 73, 9, 9, 5, 55, 1, 247, 1, 2, 1, 73, 192,
  4, 208, 4, 2, 15, 4, 63, 4, 2, 4, 13, 56, 8, 248, 8, 2, 8, 73, 0, 5, 16, 5,
  48, 5, 64, 5, 80, 5, 144, 5, 160, 5, 7, 5, 0, 8, 80, 5, 21, 10, 6, 2, 15, 0,
  63, 51, 51, 63, 225, 50, 1, 47, 93, 225, 93, 16, 222, 93, 93, 225, 93, 17, 57,
  47, 225, 93, 49, 48, 37, 51, 17, 51, 17, 33, 17, 51, 17, 51, 17, 51, 2, 184,
  248, 162, 252, 43, 162, 248, 161, 154, 3, 176, 251, 182, 4, 74, 252, 80, 3,
  176, 0, 1, 0, 109, 254, 131, 4, 184, 4, 74, 0, 15, 0, 109, 64, 73, 7, 73, 6,
  6, 4, 70, 0, 86, 0, 102, 0, 3, 0, 73, 13, 13, 9, 55, 1, 247, 1, 2, 1, 73, 239,
  4, 255, 4, 2, 192, 4, 1, 15, 4, 63, 4, 2, 4, 17, 56, 12, 248, 12, 2, 12, 73,
  16, 9, 48, 9, 64, 9, 80, 9, 144, 9, 160, 9, 6, 9, 4, 0, 12, 80, 9, 7, 7, 9,
  21, 14, 10, 2, 15, 0, 63, 51, 51, 63, 51, 47, 16, 225, 50, 50, 1, 47, 93, 225,
  93, 16, 220, 93, 93, 93, 225, 93, 17, 57, 47, 225, 93, 17, 51, 47, 225, 49,
  48, 37, 51, 17, 51, 17, 51, 17, 35, 17, 33, 17, 51, 17, 51, 17, 51, 2, 168,
  248, 162, 118, 161, 252, 86, 161, 248, 162, 154, 3, 176, 252, 80, 253, 233, 1,
  125, 4, 74, 252, 80, 3, 176, 0, 0, 2, 0, 43, 0, 0, 4, 131, 4, 74, 0, 10, 0,
  18, 0, 67, 64, 41, 0, 12, 71, 176, 6, 192, 6, 208, 6, 3, 6, 6, 8, 15, 73, 3,
  20, 207, 8, 223, 8, 239, 8, 3, 8, 11, 80, 191, 0, 1, 0, 0, 12, 8, 80, 9, 15,
  12, 80, 6, 21, 0, 63, 225, 63, 225, 18, 57, 47, 93, 225, 1, 47, 93, 16, 222,
  225, 17, 57, 47, 93, 225, 50, 49, 48, 1, 51, 32, 17, 16, 33, 33, 17, 33, 53,
  33, 17, 17, 51, 50, 53, 52, 38, 35, 2, 74, 153, 1, 160, 254, 92, 254, 180,
  254, 152, 2, 31, 137, 254, 118, 140, 2, 135, 254, 201, 254, 176, 3, 176, 154,
  253, 164, 254, 168, 172, 90, 82, 0, 0, 3, 0, 113, 0, 0, 4, 90, 4, 74, 0, 8, 0,
  16, 0, 20, 0, 99, 64, 66, 73, 13, 89, 13, 105, 13, 3, 13, 73, 96, 3, 112, 3,
  128, 3, 3, 6, 3, 1, 3, 3, 6, 55, 18, 247, 18, 2, 18, 73, 56, 17, 1, 17, 22, 0,
  56, 10, 248, 10, 2, 10, 73, 55, 6, 1, 0, 6, 16, 6, 2, 6, 9, 80, 191, 0, 1, 0,
  0, 19, 7, 15, 10, 80, 18, 6, 21, 0, 63, 51, 225, 63, 51, 57, 47, 93, 225, 1,
  47, 93, 93, 225, 93, 50, 16, 222, 93, 225, 93, 17, 57, 47, 93, 93, 225, 93,
  49, 48, 1, 51, 32, 17, 16, 33, 33, 17, 51, 17, 17, 51, 50, 53, 52, 38, 35, 1,
  35, 17, 51, 1, 18, 134, 1, 159, 254, 92, 254, 222, 161, 138, 254, 118, 140, 2,
  194, 162, 162, 2, 135, 254, 201, 254, 176, 4, 74, 253, 164, 254, 168, 172, 90,
  82, 254, 18, 4, 74, 0, 0, 2, 0, 217, 0, 0, 4, 68, 4, 74, 0, 8, 0, 16, 0, 62,
  64, 18, 13, 70, 239, 3, 255, 3, 2, 3, 18, 0, 10, 71, 0, 6, 240, 6, 2, 6, 184,
  255, 192, 64, 17, 15, 20, 72, 6, 9, 80, 191, 0, 1, 0, 0, 7, 15, 10, 80, 6, 21,
  0, 63, 225, 63, 57, 47, 93, 225, 1, 47, 43, 93, 225, 50, 16, 222, 93, 225, 49,
  48, 1, 33, 32, 17, 16, 33, 33, 17, 51, 17, 17, 33, 50, 53, 52, 38, 35, 1, 143,
  1, 21, 1, 160, 254, 92, 254, 57, 182, 1, 4, 254, 118, 140, 2, 135, 254, 201,
  254, 176, 4, 74, 253, 164, 254, 168, 172, 90, 82, 0, 1, 0, 184, 255, 236, 4,
  37, 4, 94, 0, 22, 0, 105, 182, 54, 1, 1, 57, 12, 1, 20, 184, 255, 224, 179, 9,
  12, 72, 16, 184, 255, 224, 64, 49, 9, 12, 72, 7, 7, 0, 8, 5, 72, 144, 18, 1,
  18, 24, 13, 0, 0, 128, 0, 2, 0, 0, 23, 6, 81, 47, 7, 191, 7, 2, 137, 7, 1,
  120, 7, 1, 7, 7, 15, 3, 81, 1, 21, 22, 12, 10, 81, 15, 16, 0, 63, 225, 51, 63,
  51, 225, 17, 57, 47, 93, 93, 93, 225, 17, 1, 51, 47, 93, 51, 16, 222, 93, 225,
  50, 18, 57, 47, 49, 48, 43, 43, 0, 93, 93, 55, 53, 22, 51, 32, 19, 33, 53, 33,
  2, 33, 34, 7, 39, 54, 51, 32, 0, 17, 16, 0, 33, 34, 190, 163, 153, 1, 95, 17,
  253, 230, 2, 24, 27, 254, 175, 108, 154, 62, 153, 179, 1, 11, 1, 22, 254, 226,
  254, 247, 187, 41, 160, 62, 1, 92, 154, 1, 61, 57, 158, 59, 254, 220, 254,
  229, 254, 241, 254, 220, 0, 2, 0, 123, 255, 236, 4, 141, 4, 94, 0, 15, 0, 27,
  0, 102, 64, 33, 25, 73, 0, 127, 7, 143, 7, 207, 7, 223, 7, 4, 7, 7, 3, 19, 73,
  12, 64, 9, 17, 72, 12, 29, 6, 56, 2, 248, 2, 2, 2, 73, 3, 184, 255, 192, 64,
  30, 9, 17, 72, 3, 1, 80, 191, 6, 1, 137, 6, 1, 120, 6, 1, 6, 6, 9, 16, 80, 14,
  22, 22, 80, 9, 16, 4, 15, 3, 21, 0, 63, 63, 63, 225, 63, 225, 17, 57, 47, 93,
  93, 93, 225, 1, 47, 43, 225, 93, 50, 16, 222, 43, 225, 18, 57, 47, 93, 51,
  225, 49, 48, 1, 35, 17, 35, 17, 51, 17, 51, 18, 33, 50, 18, 17, 16, 33, 32,
  37, 50, 54, 53, 52, 38, 35, 34, 6, 21, 20, 22, 1, 178, 149, 162, 162, 151, 35,
  1, 76, 171, 191, 254, 144, 254, 177, 1, 83, 103, 93, 92, 106, 104, 93, 93, 1,
  233, 254, 23, 4, 74, 254, 57, 1, 219, 254, 216, 254, 241, 253, 197, 151, 195,
  225, 218, 198, 192, 224, 221, 199, 0, 0, 2, 0, 115, 0, 0, 4, 10, 4, 74, 0, 12,
  0, 19, 0, 111, 64, 36, 2, 8, 15, 18, 72, 41, 2, 1, 24, 2, 1, 9, 2, 1, 2, 12,
  4, 13, 10, 71, 127, 9, 143, 9, 2, 9, 21, 87, 0, 119, 0, 135, 0, 3, 0, 1, 184,
  255, 240, 64, 32, 175, 1, 1, 1, 1, 55, 17, 1, 17, 71, 0, 4, 144, 4, 160, 4, 3,
  4, 2, 7, 12, 80, 19, 19, 0, 15, 80, 7, 15, 10, 0, 21, 0, 63, 50, 63, 225, 18,
  57, 47, 225, 17, 57, 1, 47, 93, 225, 93, 51, 47, 93, 56, 51, 93, 16, 222, 93,
  225, 50, 17, 57, 57, 93, 93, 93, 43, 49, 48, 33, 35, 1, 38, 53, 52, 54, 51,
  33, 17, 35, 17, 33, 37, 17, 33, 34, 21, 20, 51, 1, 57, 198, 1, 35, 234, 204,
  173, 1, 229, 182, 254, 227, 1, 29, 254, 217, 211, 238, 1, 205, 67, 248, 150,
  172, 251, 182, 1, 176, 154, 1, 102, 172, 186, 0, 255, 255, 0, 133, 255, 236,
  4, 72, 5, 217, 2, 38, 0, 72, 0, 0, 1, 6, 0, 106, 18, 0, 0, 23, 64, 13, 3, 2,
  27, 17, 38, 3, 2, 17, 29, 33, 11, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 0,
  1, 0, 4, 254, 20, 4, 45, 6, 20, 0, 34, 0, 98, 64, 58, 22, 31, 13, 0, 0, 13, 5,
  71, 144, 31, 160, 31, 2, 31, 36, 20, 24, 25, 3, 12, 71, 17, 0, 13, 176, 13, 2,
  13, 3, 80, 33, 27, 25, 8, 80, 28, 23, 15, 79, 16, 20, 16, 0, 28, 16, 28, 32,
  28, 3, 28, 16, 28, 16, 13, 18, 0, 13, 21, 0, 63, 63, 18, 57, 57, 47, 47, 93,
  17, 51, 16, 225, 50, 16, 225, 51, 63, 237, 1, 47, 93, 51, 225, 23, 50, 16,
  222, 93, 225, 17, 57, 47, 17, 18, 57, 49, 48, 1, 53, 22, 51, 50, 53, 17, 16,
  35, 34, 6, 21, 17, 35, 17, 35, 53, 51, 53, 51, 21, 33, 21, 33, 21, 7, 51, 54,
  51, 32, 17, 17, 16, 33, 34, 2, 133, 54, 61, 127, 236, 162, 147, 182, 156, 156,
  182, 1, 123, 254, 133, 8, 10, 106, 228, 1, 135, 254, 221, 81, 254, 45, 148,
  21, 170, 3, 68, 1, 4, 187, 211, 253, 240, 4, 213, 137, 182, 182, 137, 184,
  144, 168, 254, 111, 252, 190, 254, 178, 255, 255, 1, 35, 0, 0, 4, 14, 6, 33,
  2, 38, 1, 205, 0, 0, 1, 6, 0, 118, 104, 0, 0, 19, 64, 11, 1, 12, 17, 38, 1,
  54, 6, 9, 3, 0, 37, 1, 43, 53, 0, 43, 53, 0, 0, 1, 0, 172, 255, 236, 4, 37, 4,
  94, 0, 22, 0, 93, 64, 58, 54, 1, 1, 57, 12, 1, 11, 20, 27, 20, 2, 11, 16, 27,
  16, 2, 7, 7, 18, 0, 143, 13, 1, 13, 24, 5, 8, 72, 0, 18, 1, 18, 8, 81, 47, 5,
  191, 5, 2, 137, 5, 1, 120, 5, 1, 5, 5, 10, 3, 81, 1, 21, 16, 10, 81, 12, 15,
  22, 0, 63, 51, 225, 63, 51, 225, 18, 57, 47, 93, 93, 93, 225, 1, 47, 93, 225,
  50, 16, 206, 93, 50, 17, 57, 47, 49, 48, 93, 93, 0, 93, 93, 1, 7, 38, 35, 32,
  3, 33, 21, 33, 18, 33, 50, 55, 21, 6, 35, 32, 0, 17, 16, 0, 33, 50, 4, 37, 62,
  150, 112, 254, 165, 30, 2, 25, 253, 229, 20, 1, 93, 153, 162, 133, 186, 254,
  247, 254, 226, 1, 35, 1, 12, 178, 4, 35, 158, 57, 254, 195, 154, 254, 164, 62,
  160, 61, 1, 36, 1, 15, 1, 27, 1, 36, 255, 255, 0, 203, 255, 236, 4, 2, 4, 94,
  2, 6, 0, 86, 0, 0, 255, 255, 0, 197, 0, 0, 4, 51, 6, 14, 2, 6, 0, 76, 0, 0,
  255, 255, 0, 197, 0, 0, 4, 51, 5, 217, 2, 38, 0, 243, 0, 0, 1, 6, 0, 106, 0,
  0, 0, 25, 182, 2, 1, 14, 17, 38, 2, 1, 184, 255, 234, 180, 16, 20, 7, 5, 37,
  1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 135, 254, 20, 3, 86, 6, 14, 2,
  6, 0, 77, 0, 0, 0, 2, 0, 0, 255, 242, 4, 156, 4, 74, 0, 22, 0, 30, 0, 121, 64,
  78, 216, 9, 232, 9, 248, 9, 3, 9, 16, 17, 21, 72, 122, 9, 1, 9, 16, 9, 14, 72,
  9, 8, 8, 20, 24, 18, 24, 72, 20, 16, 9, 17, 72, 20, 21, 0, 24, 71, 6, 96, 21,
  1, 21, 6, 21, 6, 14, 27, 73, 207, 3, 223, 3, 2, 3, 32, 0, 14, 1, 14, 23, 80,
  0, 0, 17, 8, 80, 21, 15, 17, 79, 15, 12, 22, 24, 80, 6, 21, 0, 63, 225, 63,
  51, 225, 63, 225, 18, 57, 47, 225, 1, 47, 93, 16, 214, 93, 225, 17, 57, 57,
  47, 47, 93, 16, 225, 50, 17, 51, 43, 43, 51, 17, 51, 43, 49, 48, 93, 43, 93,
  1, 51, 32, 17, 16, 33, 35, 17, 35, 2, 2, 6, 35, 34, 39, 53, 22, 51, 50, 54,
  18, 19, 33, 17, 17, 51, 50, 53, 52, 38, 35, 2, 201, 51, 1, 160, 254, 92, 209,
  186, 33, 52, 92, 96, 62, 30, 22, 27, 41, 49, 45, 35, 1, 238, 55, 254, 118,
  140, 2, 135, 254, 201, 254, 176, 3, 176, 254, 38, 254, 135, 107, 12, 131, 6,
  84, 1, 126, 1, 253, 253, 164, 254, 168, 172, 90, 82, 0, 0, 2, 0, 106, 0, 0, 4,
  172, 4, 74, 0, 16, 0, 24, 0, 86, 64, 25, 5, 56, 18, 248, 18, 2, 18, 73, 2, 11,
  11, 15, 21, 73, 8, 26, 1, 56, 14, 248, 14, 2, 14, 73, 15, 184, 255, 192, 64,
  23, 10, 13, 72, 15, 15, 21, 17, 13, 80, 5, 191, 1, 1, 1, 1, 0, 18, 80, 11, 21,
  3, 0, 15, 0, 63, 50, 63, 225, 17, 57, 47, 93, 51, 225, 50, 63, 1, 47, 43, 225,
  93, 50, 16, 214, 225, 17, 57, 47, 51, 225, 93, 50, 49, 48, 1, 17, 33, 17, 51,
  17, 51, 32, 17, 16, 33, 35, 17, 33, 17, 35, 17, 1, 17, 51, 50, 53, 52, 38, 35,
  1, 12, 1, 43, 162, 51, 1, 160, 254, 92, 209, 254, 213, 162, 2, 111, 55, 254,
  118, 140, 4, 74, 254, 57, 1, 199, 254, 61, 254, 201, 254, 176, 1, 233, 254,
  23, 4, 74, 253, 164, 254, 168, 172, 90, 82, 255, 255, 0, 4, 0, 0, 4, 45, 6,
  20, 2, 6, 0, 233, 0, 0, 255, 255, 0, 215, 0, 0, 4, 139, 6, 33, 2, 38, 0, 250,
  0, 0, 1, 6, 0, 118, 90, 0, 0, 19, 64, 11, 1, 21, 17, 38, 1, 15, 15, 18, 10, 5,
  37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 82, 254, 20, 4, 121, 6, 23, 2, 38,
  0, 92, 0, 0, 1, 6, 2, 54, 10, 0, 0, 19, 64, 11, 1, 25, 17, 38, 1, 10, 28, 23,
  0, 9, 37, 1, 43, 53, 0, 43, 53, 0, 0, 1, 0, 160, 254, 131, 4, 45, 4, 74, 0,
  11, 0, 68, 64, 43, 6, 71, 0, 7, 16, 7, 176, 7, 192, 7, 208, 7, 5, 7, 7, 9, 1,
  71, 144, 4, 160, 4, 2, 4, 13, 0, 71, 0, 9, 176, 9, 2, 9, 7, 7, 5, 0, 80, 9,
  21, 10, 2, 15, 0, 63, 51, 63, 225, 51, 51, 47, 1, 47, 93, 225, 16, 222, 93,
  225, 17, 57, 47, 93, 225, 49, 48, 37, 33, 17, 51, 17, 33, 17, 35, 17, 33, 17,
  51, 1, 86, 2, 33, 182, 254, 158, 183, 254, 140, 182, 154, 3, 176, 251, 182,
  254, 131, 1, 125, 4, 74, 0, 1, 0, 246, 0, 0, 4, 35, 6, 227, 0, 7, 0, 62, 64,
  15, 0, 251, 3, 64, 18, 22, 72, 3, 9, 5, 90, 0, 6, 1, 6, 184, 255, 192, 179,
  21, 24, 72, 6, 184, 255, 192, 64, 13, 13, 16, 72, 6, 4, 95, 7, 1, 1, 7, 3, 5,
  18, 0, 63, 63, 51, 47, 16, 225, 1, 47, 43, 43, 93, 225, 16, 222, 43, 225, 49,
  48, 1, 17, 51, 17, 33, 17, 35, 17, 3, 115, 176, 253, 141, 186, 5, 182, 1, 45,
  254, 45, 250, 240, 5, 182, 0, 1, 1, 35, 0, 0, 3, 250, 5, 137, 0, 7, 0, 45, 64,
  27, 5, 71, 111, 0, 127, 0, 143, 0, 3, 0, 9, 2, 71, 127, 3, 143, 3, 2, 3, 6, 6,
  1, 79, 4, 15, 2, 21, 0, 63, 63, 225, 51, 47, 1, 47, 93, 225, 16, 222, 93, 225,
  49, 48, 1, 33, 17, 35, 17, 33, 17, 51, 3, 250, 253, 223, 182, 2, 33, 182, 3,
  193, 252, 63, 4, 74, 1, 63, 0, 255, 255, 0, 2, 0, 0, 4, 203, 7, 115, 2, 38, 0,
  58, 0, 0, 1, 7, 0, 67, 255, 175, 1, 82, 0, 21, 180, 1, 26, 5, 38, 1, 184, 255,
  175, 180, 29, 26, 18, 8, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 255, 252, 0,
  0, 4, 209, 6, 33, 2, 38, 0, 90, 0, 0, 1, 6, 0, 67, 142, 0, 0, 21, 180, 1, 26,
  17, 38, 1, 184, 255, 142, 180, 29, 26, 7, 24, 37, 1, 43, 53, 0, 43, 53, 0,
  255, 255, 0, 2, 0, 0, 4, 203, 7, 115, 2, 38, 0, 58, 0, 0, 1, 7, 0, 118, 0, 82,
  1, 82, 0, 19, 64, 11, 1, 32, 5, 38, 1, 82, 26, 29, 18, 8, 37, 1, 43, 53, 0,
  43, 53, 0, 255, 255, 255, 252, 0, 0, 4, 209, 6, 33, 2, 38, 0, 90, 0, 0, 1, 6,
  0, 118, 104, 0, 0, 19, 64, 11, 1, 32, 17, 38, 1, 104, 26, 29, 7, 24, 37, 1,
  43, 53, 0, 43, 53, 0, 255, 255, 0, 2, 0, 0, 4, 203, 7, 43, 2, 38, 0, 58, 0, 0,
  1, 7, 0, 106, 0, 4, 1, 82, 0, 23, 64, 13, 2, 1, 30, 5, 38, 2, 1, 3, 32, 36,
  18, 8, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 255, 252, 0, 0, 4, 209,
  5, 217, 2, 38, 0, 90, 0, 0, 1, 6, 0, 106, 255, 0, 0, 25, 182, 2, 1, 30, 17,
  38, 2, 1, 184, 255, 254, 180, 32, 36, 7, 24, 37, 1, 43, 53, 53, 0, 43, 53, 53,
  0, 255, 255, 0, 33, 0, 0, 4, 170, 7, 115, 2, 38, 0, 60, 0, 0, 1, 7, 0, 67,
  255, 142, 1, 82, 0, 21, 180, 1, 9, 5, 38, 1, 184, 255, 143, 180, 12, 9, 7, 2,
  37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 82, 254, 20, 4, 121, 6, 33, 2, 38,
  0, 92, 0, 0, 1, 6, 0, 67, 151, 0, 0, 21, 180, 1, 23, 17, 38, 1, 184, 255, 152,
  180, 26, 23, 0, 9, 37, 1, 43, 53, 0, 43, 53, 0, 0, 1, 0, 184, 1, 209, 4, 20,
  2, 121, 0, 3, 0, 24, 64, 11, 2, 2, 5, 0, 0, 1, 0, 0, 185, 1, 189, 0, 63, 225,
  1, 47, 93, 17, 51, 47, 49, 48, 19, 53, 33, 21, 184, 3, 92, 1, 209, 168, 168,
  0, 0, 1, 255, 250, 1, 209, 4, 211, 2, 121, 0, 3, 0, 19, 183, 2, 2, 5, 0, 0,
  185, 1, 189, 0, 63, 225, 1, 47, 17, 51, 47, 49, 48, 3, 53, 33, 21, 6, 4, 217,
  1, 209, 168, 168, 0, 1, 255, 250, 1, 209, 4, 211, 2, 121, 0, 3, 0, 19, 183, 2,
  2, 5, 0, 0, 185, 1, 189, 0, 63, 225, 1, 47, 17, 51, 47, 49, 48, 3, 53, 33, 21,
  6, 4, 217, 1, 209, 168, 168, 0, 2, 255, 236, 254, 49, 4, 225, 255, 211, 0, 3,
  0, 7, 0, 60, 64, 37, 4, 0, 9, 5, 1, 247, 6, 1, 38, 6, 1, 23, 6, 1, 6, 186, 32,
  5, 240, 5, 2, 5, 248, 1, 1, 41, 1, 1, 24, 1, 1, 1, 186, 239, 2, 1, 2, 0, 47,
  93, 225, 93, 93, 93, 47, 93, 225, 93, 93, 93, 1, 47, 51, 16, 196, 50, 49, 48,
  5, 33, 53, 33, 17, 33, 53, 33, 4, 225, 251, 11, 4, 245, 251, 11, 4, 245, 184,
  139, 254, 94, 139, 0, 0, 1, 1, 190, 3, 193, 3, 12, 5, 182, 0, 6, 0, 42, 64,
  26, 22, 6, 38, 6, 230, 6, 246, 6, 4, 6, 152, 4, 153, 111, 1, 191, 1, 2, 1, 1,
  7, 8, 6, 157, 3, 169, 0, 63, 237, 17, 18, 1, 57, 47, 93, 237, 225, 93, 49, 48,
  1, 39, 54, 19, 51, 6, 7, 1, 205, 15, 54, 123, 157, 62, 38, 3, 193, 22, 206, 1,
  17, 255, 246, 0, 0, 1, 1, 190, 3, 193, 3, 12, 5, 182, 0, 6, 0, 56, 64, 40, 25,
  6, 41, 6, 233, 6, 249, 6, 4, 6, 152, 1, 153, 0, 4, 32, 4, 48, 4, 112, 4, 128,
  4, 144, 4, 208, 4, 224, 4, 240, 4, 9, 4, 4, 7, 8, 3, 157, 6, 169, 0, 63, 237,
  17, 18, 1, 57, 47, 93, 253, 225, 93, 49, 48, 1, 23, 6, 3, 35, 18, 55, 2, 254,
  14, 55, 121, 158, 65, 36, 5, 182, 22, 213, 254, 246, 1, 10, 235, 0, 1, 1, 201,
  254, 248, 3, 2, 0, 238, 0, 6, 0, 67, 64, 49, 25, 6, 41, 6, 233, 6, 249, 6, 4,
  6, 152, 1, 153, 0, 4, 32, 4, 48, 4, 112, 4, 128, 4, 144, 4, 208, 4, 224, 4,
  240, 4, 9, 4, 4, 7, 8, 3, 158, 209, 6, 1, 31, 6, 47, 6, 63, 6, 3, 6, 0, 47,
  93, 93, 237, 17, 18, 1, 57, 47, 93, 253, 225, 93, 49, 48, 37, 23, 6, 3, 35,
  18, 55, 2, 244, 14, 55, 121, 137, 71, 29, 238, 23, 213, 254, 246, 1, 36, 210,
  0, 1, 1, 190, 3, 193, 3, 12, 5, 182, 0, 6, 0, 40, 64, 24, 22, 0, 38, 0, 230,
  0, 246, 0, 4, 0, 152, 2, 153, 111, 5, 1, 5, 5, 7, 8, 3, 157, 0, 169, 0, 63,
  237, 17, 18, 1, 57, 47, 93, 237, 225, 93, 49, 48, 1, 18, 23, 35, 2, 39, 55, 2,
  168, 40, 60, 157, 124, 53, 15, 5, 182, 254, 253, 242, 1, 18, 205, 22, 0, 2, 0,
  233, 3, 193, 3, 225, 5, 182, 0, 6, 0, 13, 0, 74, 64, 50, 22, 6, 38, 6, 230, 6,
  246, 6, 4, 6, 152, 4, 153, 47, 1, 127, 1, 2, 1, 1, 22, 13, 38, 13, 230, 13,
  246, 13, 4, 13, 152, 11, 153, 0, 8, 224, 8, 240, 8, 3, 8, 8, 15, 14, 13, 6,
  157, 10, 3, 169, 0, 63, 51, 237, 50, 17, 18, 1, 57, 47, 93, 237, 225, 93, 51,
  47, 93, 237, 225, 93, 49, 48, 1, 39, 54, 19, 51, 6, 7, 33, 39, 54, 19, 51, 6,
  7, 2, 162, 15, 54, 123, 157, 62, 38, 253, 123, 15, 54, 123, 157, 62, 38, 3,
  193, 22, 206, 1, 17, 255, 246, 22, 206, 1, 17, 255, 246, 0, 2, 0, 233, 3, 193,
  3, 225, 5, 182, 0, 6, 0, 13, 0, 92, 64, 65, 25, 13, 41, 13, 233, 13, 249, 13,
  4, 13, 152, 8, 153, 47, 11, 127, 11, 2, 11, 11, 4, 25, 6, 41, 6, 233, 6, 249,
  6, 4, 6, 152, 1, 153, 224, 4, 240, 4, 2, 191, 4, 207, 4, 2, 0, 4, 64, 4, 80,
  4, 112, 4, 128, 4, 5, 4, 4, 15, 14, 10, 3, 157, 13, 6, 169, 0, 63, 51, 237,
  50, 17, 18, 1, 57, 47, 93, 93, 93, 253, 225, 93, 17, 51, 47, 93, 253, 225, 93,
  49, 48, 1, 23, 6, 3, 35, 18, 55, 33, 23, 6, 3, 35, 18, 55, 2, 41, 14, 55, 121,
  158, 65, 36, 2, 133, 14, 55, 121, 158, 65, 36, 5, 182, 22, 213, 254, 246, 1,
  10, 235, 22, 213, 254, 246, 1, 10, 235, 0, 2, 0, 244, 254, 248, 3, 215, 0,
  238, 0, 6, 0, 13, 0, 93, 64, 64, 25, 13, 41, 13, 2, 13, 152, 8, 153, 63, 11,
  1, 11, 11, 4, 25, 6, 41, 6, 2, 6, 152, 1, 153, 224, 4, 240, 4, 2, 191, 4, 207,
  4, 2, 0, 4, 64, 4, 80, 4, 112, 4, 128, 4, 5, 4, 4, 15, 14, 10, 3, 158, 13,
  208, 6, 1, 31, 6, 47, 6, 63, 6, 3, 6, 0, 47, 93, 93, 51, 237, 50, 17, 18, 1,
  57, 47, 93, 93, 93, 253, 225, 93, 17, 51, 47, 93, 253, 225, 93, 49, 48, 37,
  23, 6, 3, 35, 18, 55, 33, 23, 6, 3, 35, 18, 55, 2, 31, 14, 55, 121, 137, 71,
  29, 2, 113, 14, 51, 125, 137, 71, 29, 238, 23, 213, 254, 246, 1, 36, 210, 23,
  197, 254, 230, 1, 36, 210, 0, 1, 0, 240, 0, 0, 3, 221, 6, 20, 0, 11, 0, 47,
  64, 25, 9, 0, 2, 190, 8, 5, 159, 3, 175, 3, 2, 3, 3, 12, 13, 0, 5, 191, 11, 6,
  254, 8, 0, 2, 21, 0, 63, 63, 246, 50, 225, 50, 17, 18, 1, 57, 47, 93, 51, 51,
  225, 50, 50, 49, 48, 1, 37, 19, 35, 19, 5, 53, 5, 3, 51, 3, 37, 3, 221, 254,
  180, 56, 217, 55, 254, 201, 1, 55, 55, 217, 56, 1, 76, 3, 221, 31, 252, 4, 3,
  252, 31, 180, 30, 1, 161, 254, 95, 30, 0, 1, 0, 229, 0, 0, 3, 231, 6, 20, 0,
  21, 0, 55, 64, 28, 19, 16, 2, 4, 190, 15, 12, 7, 5, 5, 22, 23, 19, 12, 191,
  18, 13, 194, 15, 0, 8, 1, 191, 7, 2, 194, 4, 21, 0, 63, 246, 50, 225, 50, 63,
  246, 50, 225, 50, 17, 18, 1, 57, 47, 51, 51, 51, 225, 50, 50, 50, 49, 48, 1,
  37, 21, 37, 19, 35, 19, 5, 53, 5, 3, 19, 5, 53, 5, 3, 51, 3, 37, 21, 37, 19,
  2, 156, 1, 75, 254, 181, 55, 217, 55, 254, 180, 1, 76, 47, 47, 254, 180, 1,
  76, 55, 217, 55, 1, 75, 254, 181, 47, 1, 240, 30, 180, 31, 254, 135, 1, 121,
  31, 180, 30, 1, 34, 1, 19, 31, 180, 30, 1, 120, 254, 136, 30, 180, 31, 254,
  237, 0, 1, 1, 123, 1, 229, 3, 82, 3, 242, 0, 9, 0, 42, 64, 28, 16, 8, 80, 8,
  96, 8, 144, 8, 160, 8, 224, 8, 6, 8, 95, 2, 111, 2, 175, 2, 3, 64, 2, 1, 2,
  11, 0, 5, 0, 47, 205, 1, 16, 222, 93, 93, 205, 93, 49, 48, 1, 50, 17, 20, 6,
  35, 34, 38, 53, 16, 2, 102, 236, 127, 109, 111, 124, 3, 242, 254, 250, 128,
  135, 134, 129, 1, 6, 0, 0, 3, 0, 78, 255, 227, 4, 127, 0, 250, 0, 7, 0, 15, 0,
  23, 0, 95, 64, 61, 52, 18, 1, 37, 18, 1, 6, 18, 22, 18, 2, 18, 150, 22, 22,
  14, 52, 2, 1, 37, 2, 1, 6, 2, 22, 2, 2, 2, 150, 6, 6, 52, 10, 1, 37, 10, 1, 6,
  10, 22, 10, 2, 10, 150, 224, 14, 240, 14, 2, 14, 14, 24, 25, 16, 0, 8, 155,
  20, 4, 12, 168, 0, 63, 51, 51, 225, 50, 50, 17, 18, 1, 57, 47, 93, 225, 93,
  93, 93, 51, 47, 225, 93, 93, 93, 17, 51, 47, 225, 93, 93, 93, 49, 48, 55, 50,
  21, 20, 35, 34, 53, 52, 33, 50, 21, 20, 35, 34, 53, 52, 33, 50, 21, 20, 35,
  34, 53, 52, 205, 127, 127, 127, 2, 24, 127, 127, 127, 2, 25, 127, 127, 127,
  250, 139, 140, 140, 139, 139, 140, 140, 139, 139, 140, 140, 139, 0, 7, 0, 4,
  0, 0, 4, 184, 5, 201, 0, 9, 0, 21, 0, 25, 0, 35, 0, 47, 0, 57, 0, 69, 0, 180,
  64, 118, 67, 180, 0, 51, 16, 51, 2, 51, 56, 45, 180, 0, 29, 16, 29, 2, 29, 39,
  180, 25, 22, 144, 34, 160, 34, 2, 111, 34, 127, 34, 143, 34, 3, 143, 22, 159,
  22, 175, 22, 207, 22, 4, 34, 22, 34, 22, 3, 61, 180, 15, 56, 1, 56, 71, 23,
  24, 24, 3, 13, 180, 15, 8, 31, 8, 2, 8, 19, 180, 3, 58, 36, 182, 26, 64, 42,
  182, 53, 31, 26, 22, 25, 24, 23, 112, 25, 128, 25, 192, 25, 224, 25, 240, 25,
  5, 175, 23, 191, 23, 239, 23, 255, 23, 4, 25, 23, 25, 23, 5, 48, 26, 25, 10,
  182, 0, 16, 182, 5, 7, 0, 63, 225, 212, 225, 63, 51, 18, 57, 57, 47, 47, 93,
  93, 17, 51, 17, 51, 16, 212, 50, 225, 50, 16, 225, 50, 1, 47, 225, 212, 93,
  225, 17, 51, 47, 51, 16, 222, 93, 225, 18, 57, 57, 47, 47, 93, 93, 93, 17, 51,
  225, 212, 93, 225, 16, 212, 93, 225, 49, 48, 1, 34, 38, 53, 16, 51, 50, 22,
  21, 16, 39, 50, 54, 53, 52, 38, 35, 34, 6, 21, 20, 22, 5, 1, 39, 1, 1, 34, 38,
  53, 16, 51, 50, 22, 21, 16, 39, 50, 54, 53, 52, 38, 35, 34, 6, 21, 20, 22, 5,
  34, 38, 53, 16, 51, 50, 22, 21, 16, 39, 50, 54, 53, 52, 38, 35, 34, 6, 21, 20,
  22, 1, 4, 114, 126, 244, 113, 127, 242, 63, 42, 47, 58, 59, 47, 43, 2, 32,
  253, 70, 41, 2, 186, 254, 244, 114, 125, 243, 113, 127, 242, 63, 42, 47, 58,
  59, 47, 43, 2, 80, 115, 125, 244, 112, 127, 241, 63, 41, 44, 60, 60, 47, 44,
  3, 92, 163, 148, 1, 54, 161, 149, 254, 201, 107, 100, 104, 116, 85, 89, 112,
  104, 100, 123, 254, 225, 98, 1, 33, 252, 80, 163, 148, 1, 54, 161, 149, 254,
  201, 106, 101, 104, 116, 85, 89, 112, 104, 101, 106, 163, 148, 1, 54, 162,
  148, 254, 201, 106, 101, 104, 114, 87, 88, 113, 104, 101, 255, 255, 1, 240, 3,
  166, 2, 221, 5, 182, 2, 6, 0, 10, 0, 0, 255, 255, 1, 29, 3, 166, 3, 176, 5,
  182, 2, 6, 0, 5, 0, 0, 0, 1, 1, 145, 0, 115, 3, 59, 3, 199, 0, 6, 0, 63, 64,
  38, 3, 235, 0, 236, 4, 239, 2, 255, 2, 2, 192, 2, 1, 159, 2, 175, 2, 2, 112,
  2, 1, 79, 2, 95, 2, 2, 2, 8, 64, 6, 5, 238, 1, 238, 32, 0, 3, 239, 0, 25, 63,
  51, 26, 237, 237, 51, 1, 26, 24, 16, 222, 93, 93, 93, 93, 93, 50, 253, 225,
  49, 48, 1, 1, 23, 3, 19, 7, 1, 1, 145, 1, 54, 116, 237, 237, 116, 254, 202, 2,
  41, 1, 158, 78, 254, 164, 254, 164, 78, 1, 155, 0, 1, 1, 145, 0, 115, 3, 59,
  3, 199, 0, 6, 0, 37, 64, 17, 2, 4, 236, 3, 235, 0, 8, 64, 6, 5, 238, 1, 238,
  32, 0, 3, 239, 0, 25, 63, 51, 26, 237, 237, 51, 1, 26, 24, 16, 222, 225, 237,
  50, 49, 48, 1, 1, 39, 19, 3, 55, 1, 3, 59, 254, 203, 117, 238, 238, 117, 1,
  53, 2, 14, 254, 101, 78, 1, 92, 1, 92, 78, 254, 98, 255, 255, 0, 255, 255,
  227, 3, 204, 5, 182, 2, 39, 0, 4, 0, 231, 0, 0, 1, 7, 0, 4, 255, 24, 0, 0, 0,
  32, 64, 21, 3, 2, 208, 22, 1, 192, 22, 1, 176, 22, 1, 64, 22, 1, 48, 22, 1,
  32, 22, 1, 22, 17, 93, 93, 93, 93, 93, 93, 53, 53, 0, 1, 0, 170, 0, 0, 4, 33,
  5, 182, 0, 3, 0, 32, 64, 15, 3, 0, 0, 5, 1, 0, 2, 1, 2, 2, 4, 3, 6, 1, 24, 0,
  63, 63, 17, 1, 51, 47, 93, 51, 17, 51, 47, 50, 49, 48, 1, 1, 35, 1, 4, 33,
  253, 39, 158, 2, 217, 5, 182, 250, 74, 5, 182, 0, 0, 1, 1, 61, 3, 29, 3, 143,
  5, 199, 0, 18, 0, 60, 64, 40, 0, 224, 47, 18, 63, 18, 2, 18, 18, 11, 7, 224,
  16, 8, 32, 8, 48, 8, 128, 8, 144, 8, 160, 8, 224, 8, 240, 8, 8, 8, 11, 3, 230,
  14, 222, 9, 220, 7, 0, 255, 0, 63, 50, 63, 63, 225, 50, 1, 47, 93, 225, 50,
  51, 47, 93, 225, 49, 48, 1, 17, 52, 35, 34, 6, 21, 17, 35, 17, 51, 23, 51, 54,
  51, 50, 22, 21, 17, 2, 252, 127, 100, 72, 148, 125, 17, 8, 68, 139, 110, 127,
  3, 29, 1, 157, 150, 106, 119, 254, 174, 2, 153, 104, 121, 130, 120, 254, 80,
  0, 0, 1, 0, 129, 0, 0, 4, 33, 5, 182, 0, 17, 0, 96, 64, 58, 2, 4, 16, 16, 5,
  159, 11, 175, 11, 2, 11, 19, 14, 0, 4, 110, 9, 7, 128, 5, 240, 5, 2, 5, 9, 0,
  117, 3, 6, 3, 17, 116, 14, 47, 14, 95, 14, 239, 14, 255, 14, 4, 14, 64, 16,
  21, 72, 3, 14, 3, 14, 4, 13, 116, 10, 3, 4, 18, 0, 63, 63, 225, 18, 57, 57,
  47, 47, 43, 93, 16, 225, 17, 51, 16, 225, 50, 1, 47, 93, 198, 51, 225, 50, 50,
  16, 206, 93, 17, 57, 47, 18, 57, 49, 48, 1, 33, 21, 33, 17, 35, 17, 35, 53,
  51, 17, 33, 21, 33, 17, 33, 21, 33, 1, 227, 1, 37, 254, 219, 178, 176, 176, 2,
  240, 253, 194, 2, 23, 253, 233, 1, 143, 137, 254, 250, 1, 6, 137, 4, 39, 164,
  253, 252, 164, 0, 0, 1, 0, 119, 0, 0, 4, 86, 5, 201, 0, 35, 0, 133, 64, 81, 9,
  6, 14, 111, 30, 27, 23, 12, 7, 23, 7, 23, 7, 19, 0, 18, 37, 29, 24, 16, 0, 19,
  1, 19, 9, 28, 117, 29, 6, 29, 10, 25, 117, 24, 14, 24, 15, 29, 31, 29, 63, 29,
  79, 29, 127, 29, 143, 29, 175, 29, 191, 29, 207, 29, 9, 134, 24, 150, 24, 2,
  119, 24, 1, 111, 24, 1, 29, 24, 29, 24, 16, 3, 115, 1, 34, 7, 20, 16, 116, 19,
  24, 0, 63, 225, 50, 63, 51, 225, 18, 57, 57, 47, 47, 93, 93, 93, 93, 17, 51,
  16, 225, 50, 17, 51, 16, 225, 50, 1, 47, 93, 51, 51, 51, 16, 206, 50, 17, 57,
  57, 47, 47, 17, 51, 17, 51, 51, 225, 50, 50, 49, 48, 1, 7, 38, 35, 34, 21, 21,
  33, 21, 33, 21, 33, 21, 33, 21, 20, 7, 33, 21, 33, 53, 54, 53, 53, 35, 53, 51,
  53, 35, 53, 51, 53, 52, 54, 51, 50, 4, 39, 66, 141, 131, 223, 1, 121, 254,
  135, 1, 121, 254, 135, 140, 2, 236, 252, 33, 200, 198, 198, 198, 198, 217,
  181, 192, 5, 121, 144, 72, 246, 192, 137, 158, 137, 19, 196, 78, 166, 154, 49,
  235, 21, 137, 158, 137, 221, 168, 201, 0, 0, 3, 0, 82, 255, 236, 4, 166, 5,
  182, 0, 9, 0, 16, 0, 36, 0, 122, 64, 75, 6, 90, 13, 26, 24, 22, 112, 33, 29,
  33, 33, 64, 16, 19, 72, 32, 13, 48, 13, 2, 13, 33, 13, 33, 2, 31, 31, 17, 64,
  9, 14, 72, 17, 38, 10, 1, 90, 31, 2, 47, 2, 63, 2, 3, 2, 35, 117, 17, 20, 25,
  23, 32, 117, 25, 26, 28, 3, 29, 29, 0, 117, 15, 10, 31, 10, 2, 10, 10, 2, 16,
  96, 3, 6, 2, 24, 0, 63, 63, 225, 18, 57, 47, 93, 225, 51, 47, 23, 51, 225, 50,
  63, 51, 225, 1, 47, 93, 225, 50, 16, 206, 43, 50, 47, 17, 57, 57, 47, 47, 93,
  43, 17, 51, 16, 225, 50, 50, 16, 225, 49, 48, 19, 17, 35, 17, 51, 32, 17, 20,
  6, 35, 39, 51, 32, 17, 16, 33, 35, 1, 21, 6, 35, 34, 17, 17, 35, 53, 55, 55,
  51, 21, 51, 21, 35, 17, 20, 51, 50, 240, 158, 205, 1, 194, 230, 226, 41, 41,
  1, 36, 254, 244, 65, 3, 182, 64, 102, 221, 115, 115, 65, 86, 209, 209, 113,
  62, 2, 57, 253, 199, 5, 182, 254, 84, 221, 244, 146, 1, 53, 1, 35, 251, 102,
  125, 32, 1, 26, 1, 100, 70, 51, 215, 211, 125, 254, 164, 153, 0, 0, 1, 0, 96,
  255, 236, 4, 106, 5, 203, 0, 39, 0, 106, 64, 20, 11, 2, 2, 7, 34, 17, 41, 27,
  22, 22, 12, 0, 7, 90, 29, 25, 21, 24, 9, 23, 184, 1, 7, 180, 22, 12, 22, 3,
  27, 184, 1, 7, 64, 29, 28, 0, 28, 15, 28, 31, 28, 47, 28, 95, 28, 159, 28,
  223, 28, 6, 22, 28, 22, 28, 14, 37, 95, 32, 4, 14, 95, 19, 19, 0, 63, 225, 63,
  225, 18, 57, 57, 47, 47, 93, 17, 51, 16, 225, 50, 17, 51, 16, 225, 50, 1, 47,
  51, 51, 51, 225, 50, 50, 51, 47, 51, 16, 206, 50, 17, 57, 17, 51, 49, 48, 1,
  33, 21, 33, 20, 7, 7, 21, 20, 23, 33, 21, 33, 18, 33, 50, 55, 21, 6, 35, 32,
  3, 35, 53, 51, 39, 55, 35, 53, 51, 18, 0, 51, 50, 23, 7, 38, 35, 34, 6, 1,
  186, 1, 176, 254, 66, 1, 1, 2, 1, 129, 254, 145, 73, 1, 40, 136, 132, 122,
  160, 254, 65, 94, 164, 148, 2, 2, 148, 160, 39, 1, 25, 219, 191, 144, 79, 122,
  120, 136, 194, 3, 166, 137, 15, 14, 25, 62, 20, 22, 137, 254, 153, 58, 162,
  59, 2, 10, 137, 38, 120, 137, 1, 6, 1, 31, 92, 146, 74, 199, 0, 0, 4, 0, 8,
  255, 248, 4, 199, 5, 193, 0, 19, 0, 23, 0, 35, 0, 43, 0, 164, 185, 0, 34, 255,
  224, 179, 9, 13, 72, 32, 184, 255, 224, 64, 30, 9, 13, 72, 28, 32, 9, 13, 72,
  26, 32, 9, 13, 72, 102, 42, 150, 42, 166, 42, 3, 42, 180, 27, 181, 33, 21, 22,
  23, 20, 22, 184, 255, 192, 64, 69, 21, 24, 72, 20, 64, 21, 24, 72, 22, 20, 22,
  20, 15, 105, 38, 153, 38, 169, 38, 3, 38, 180, 33, 45, 0, 16, 9, 32, 9, 80, 9,
  144, 9, 160, 9, 5, 9, 102, 5, 150, 5, 166, 5, 3, 5, 180, 15, 40, 182, 30, 183,
  36, 182, 24, 25, 23, 6, 21, 24, 9, 7, 182, 12, 183, 3, 182, 1, 18, 7, 0, 63,
  51, 225, 244, 225, 51, 63, 63, 63, 225, 244, 225, 1, 47, 225, 93, 196, 93, 50,
  16, 214, 225, 93, 18, 57, 57, 47, 47, 43, 43, 17, 51, 17, 51, 16, 244, 225,
  93, 49, 48, 43, 43, 43, 43, 1, 7, 38, 35, 34, 21, 20, 51, 50, 55, 21, 6, 35,
  34, 38, 53, 52, 54, 51, 50, 5, 1, 35, 1, 19, 34, 38, 53, 52, 54, 51, 50, 22,
  21, 20, 6, 39, 50, 53, 52, 35, 34, 21, 20, 2, 20, 32, 82, 68, 198, 194, 103,
  73, 74, 108, 156, 176, 180, 162, 99, 2, 81, 253, 39, 157, 2, 217, 33, 132,
  170, 166, 140, 131, 170, 164, 139, 155, 155, 158, 5, 156, 107, 33, 234, 229,
  33, 107, 37, 175, 163, 171, 176, 11, 250, 74, 5, 182, 250, 66, 185, 157, 161,
  181, 187, 155, 158, 184, 108, 234, 231, 231, 234, 0, 2, 0, 227, 255, 236, 3,
  231, 5, 203, 0, 25, 0, 33, 0, 106, 64, 62, 26, 22, 110, 6, 12, 6, 9, 9, 6, 28,
  112, 19, 0, 112, 1, 63, 6, 1, 0, 6, 1, 63, 19, 159, 19, 175, 19, 191, 19, 4,
  32, 1, 1, 6, 19, 1, 1, 19, 6, 3, 34, 35, 9, 7, 21, 118, 12, 10, 26, 26, 24,
  30, 118, 16, 6, 24, 117, 3, 1, 1, 3, 25, 0, 63, 51, 47, 16, 225, 63, 225, 18,
  57, 47, 51, 51, 225, 50, 50, 17, 18, 1, 23, 57, 47, 47, 47, 93, 93, 93, 93,
  16, 225, 16, 225, 17, 51, 47, 17, 51, 16, 225, 50, 49, 48, 1, 51, 2, 33, 34,
  38, 53, 53, 6, 7, 53, 54, 55, 17, 52, 54, 51, 50, 22, 21, 16, 5, 17, 20, 51,
  50, 1, 54, 17, 52, 35, 34, 6, 21, 3, 117, 114, 18, 254, 244, 139, 154, 86,
  107, 72, 121, 137, 133, 110, 126, 254, 172, 145, 144, 254, 223, 207, 103, 53,
  51, 1, 76, 254, 160, 183, 173, 231, 31, 26, 121, 19, 40, 1, 238, 140, 159,
  165, 136, 254, 157, 186, 254, 211, 221, 2, 139, 121, 1, 29, 188, 81, 107, 0,
  4, 0, 25, 0, 0, 4, 184, 5, 182, 0, 15, 0, 26, 0, 38, 0, 42, 0, 240, 64, 21,
  20, 25, 36, 25, 2, 20, 23, 36, 23, 2, 27, 20, 43, 20, 2, 27, 18, 43, 18, 2, 9,
  184, 255, 208, 64, 40, 18, 21, 72, 116, 9, 132, 9, 2, 86, 9, 102, 9, 2, 55, 9,
  71, 9, 2, 1, 48, 18, 21, 72, 123, 1, 139, 1, 2, 89, 1, 105, 1, 2, 56, 1, 72,
  1, 2, 39, 36, 184, 1, 3, 179, 19, 11, 1, 14, 184, 1, 3, 64, 24, 15, 111, 19,
  159, 19, 175, 19, 207, 19, 223, 19, 5, 19, 15, 19, 15, 7, 42, 64, 21, 24, 72,
  42, 30, 184, 1, 3, 180, 24, 44, 9, 3, 6, 184, 1, 3, 64, 49, 7, 27, 182, 16,
  33, 182, 21, 15, 16, 31, 16, 2, 16, 21, 16, 21, 14, 75, 2, 91, 2, 2, 2, 64, 9,
  12, 72, 2, 8, 3, 133, 40, 1, 86, 40, 102, 40, 118, 40, 3, 40, 97, 39, 68, 10,
  84, 10, 2, 10, 184, 255, 192, 182, 9, 12, 72, 10, 1, 7, 18, 0, 63, 51, 51, 43,
  93, 51, 224, 93, 93, 63, 51, 43, 93, 51, 57, 57, 47, 47, 93, 16, 225, 16, 225,
  1, 47, 225, 50, 50, 16, 214, 225, 196, 43, 18, 57, 57, 47, 47, 93, 16, 225,
  50, 50, 16, 225, 196, 49, 48, 93, 93, 93, 43, 93, 93, 93, 43, 93, 93, 93, 93,
  33, 35, 1, 35, 22, 21, 17, 35, 17, 51, 1, 51, 2, 53, 17, 51, 1, 34, 38, 53,
  16, 51, 50, 22, 21, 20, 6, 39, 50, 54, 53, 52, 38, 35, 34, 6, 21, 20, 22, 3,
  53, 33, 21, 2, 137, 174, 254, 187, 9, 19, 135, 176, 1, 67, 6, 14, 133, 1, 49,
  114, 135, 253, 114, 136, 132, 120, 63, 48, 48, 63, 64, 48, 48, 147, 1, 158, 4,
  145, 253, 164, 253, 16, 5, 182, 251, 117, 1, 47, 100, 2, 248, 251, 92, 187,
  162, 1, 90, 183, 163, 168, 181, 121, 115, 113, 114, 109, 110, 113, 112, 116,
  254, 117, 147, 147, 0, 2, 0, 0, 2, 229, 4, 156, 5, 182, 0, 7, 0, 25, 0, 107,
  64, 63, 24, 17, 20, 196, 19, 15, 9, 12, 196, 13, 191, 13, 1, 6, 13, 6, 13, 1,
  31, 19, 1, 19, 27, 182, 3, 198, 3, 2, 155, 3, 171, 3, 2, 122, 3, 138, 3, 2, 3,
  0, 196, 0, 1, 1, 1, 7, 3, 200, 4, 16, 9, 24, 3, 4, 20, 13, 8, 1, 1, 17, 14, 4,
  3, 0, 63, 51, 51, 51, 47, 51, 51, 51, 18, 23, 57, 16, 225, 50, 1, 47, 93, 225,
  51, 93, 93, 93, 16, 206, 93, 17, 57, 57, 47, 47, 93, 16, 225, 50, 50, 16, 225,
  50, 50, 49, 48, 1, 35, 17, 35, 53, 33, 21, 35, 1, 3, 35, 23, 17, 35, 17, 51,
  19, 19, 51, 17, 35, 17, 52, 55, 35, 3, 1, 47, 127, 176, 1, 225, 178, 1, 238,
  146, 12, 10, 123, 187, 139, 149, 179, 127, 10, 12, 154, 2, 229, 2, 101, 108,
  108, 253, 155, 2, 37, 180, 254, 143, 2, 209, 253, 234, 2, 22, 253, 47, 1, 86,
  87, 120, 253, 219, 0, 255, 255, 0, 74, 0, 0, 4, 135, 5, 205, 2, 6, 1, 118, 0,
  0, 0, 2, 0, 82, 255, 221, 4, 119, 4, 72, 0, 19, 0, 26, 0, 60, 64, 26, 20, 7,
  0, 28, 26, 1, 31, 13, 47, 13, 63, 13, 3, 13, 1, 119, 26, 26, 4, 23, 119, 16,
  15, 4, 119, 6, 184, 255, 224, 181, 9, 12, 72, 6, 10, 25, 0, 63, 51, 43, 225,
  63, 225, 18, 57, 47, 225, 1, 47, 93, 51, 50, 16, 206, 50, 50, 49, 48, 1, 33,
  17, 22, 51, 50, 55, 23, 6, 6, 35, 34, 0, 53, 16, 0, 51, 50, 0, 21, 39, 17, 38,
  35, 34, 7, 17, 4, 119, 252, 196, 123, 174, 254, 142, 71, 97, 219, 151, 240,
  254, 222, 1, 51, 223, 231, 1, 44, 232, 121, 180, 171, 124, 2, 18, 254, 156,
  123, 234, 41, 156, 123, 1, 68, 241, 1, 5, 1, 49, 254, 202, 251, 81, 1, 21,
  119, 117, 254, 233, 0, 255, 255, 0, 18, 255, 246, 4, 182, 5, 182, 2, 39, 0,
  123, 254, 163, 0, 0, 0, 38, 2, 23, 200, 0, 1, 7, 2, 64, 1, 86, 253, 103, 0,
  84, 64, 55, 4, 3, 2, 20, 24, 4, 3, 2, 240, 20, 1, 128, 20, 1, 16, 20, 1, 0,
  20, 1, 20, 1, 171, 13, 1, 148, 13, 1, 100, 13, 1, 84, 13, 1, 68, 13, 1, 13, 0,
  240, 0, 1, 224, 0, 1, 176, 0, 1, 80, 0, 1, 64, 0, 1, 0, 17, 93, 93, 93, 93,
  93, 53, 17, 93, 93, 93, 93, 93, 53, 17, 93, 93, 93, 93, 53, 53, 53, 0, 63, 53,
  53, 53, 255, 255, 0, 11, 255, 246, 4, 202, 5, 197, 2, 39, 0, 117, 254, 181, 0,
  0, 0, 38, 2, 23, 239, 0, 1, 7, 2, 64, 1, 106, 253, 103, 0, 76, 64, 49, 4, 3,
  2, 40, 24, 4, 3, 2, 240, 40, 1, 176, 40, 1, 128, 40, 1, 16, 40, 1, 0, 40, 1,
  40, 1, 244, 33, 1, 212, 33, 1, 196, 33, 1, 180, 33, 1, 148, 33, 1, 33, 0, 192,
  0, 1, 127, 0, 1, 0, 17, 93, 93, 53, 17, 93, 93, 93, 93, 93, 53, 17, 93, 93,
  93, 93, 93, 53, 53, 53, 0, 63, 53, 53, 53, 255, 255, 0, 24, 255, 246, 4, 202,
  5, 182, 2, 39, 2, 61, 254, 200, 0, 0, 0, 38, 2, 23, 239, 0, 1, 7, 2, 64, 1,
  106, 253, 103, 0, 80, 64, 52, 4, 3, 2, 34, 24, 4, 3, 2, 240, 34, 1, 176, 34,
  1, 128, 34, 1, 16, 34, 1, 0, 34, 1, 34, 1, 244, 27, 1, 212, 27, 1, 196, 27, 1,
  180, 27, 1, 148, 27, 1, 27, 0, 224, 0, 1, 208, 0, 1, 192, 0, 1, 0, 17, 93, 93,
  93, 53, 17, 93, 93, 93, 93, 93, 53, 17, 93, 93, 93, 93, 93, 53, 53, 53, 0, 63,
  53, 53, 53, 255, 255, 0, 28, 255, 246, 4, 202, 5, 182, 2, 39, 2, 63, 254, 173,
  0, 0, 0, 38, 2, 23, 175, 0, 1, 7, 2, 64, 1, 106, 253, 103, 0, 80, 64, 52, 4,
  3, 2, 16, 24, 4, 3, 2, 240, 16, 1, 176, 16, 1, 128, 16, 1, 16, 16, 1, 0, 16,
  1, 16, 1, 171, 9, 1, 107, 9, 1, 91, 9, 1, 75, 9, 1, 52, 9, 1, 36, 9, 1, 9, 0,
  192, 0, 1, 127, 0, 1, 0, 17, 93, 93, 53, 17, 93, 93, 93, 93, 93, 93, 53, 17,
  93, 93, 93, 93, 93, 53, 53, 53, 0, 63, 53, 53, 53, 0, 2, 0, 121, 255, 236, 4,
  82, 5, 197, 0, 20, 0, 31, 0, 57, 64, 30, 6, 6, 16, 21, 1, 70, 11, 33, 27, 72,
  0, 16, 1, 16, 21, 0, 24, 78, 19, 19, 9, 29, 80, 14, 22, 6, 4, 80, 9, 4, 0, 63,
  225, 51, 63, 225, 17, 57, 47, 225, 50, 50, 1, 47, 93, 225, 16, 222, 225, 50,
  17, 57, 47, 49, 48, 1, 55, 54, 38, 35, 34, 7, 53, 54, 51, 32, 17, 16, 0, 33,
  32, 17, 52, 0, 51, 50, 19, 38, 38, 35, 34, 2, 21, 20, 51, 50, 18, 3, 156, 2,
  9, 133, 153, 131, 127, 134, 149, 1, 176, 254, 175, 254, 226, 254, 150, 1, 20,
  244, 184, 66, 22, 127, 76, 160, 197, 187, 138, 219, 3, 94, 40, 181, 242, 84,
  174, 62, 253, 225, 254, 123, 253, 203, 1, 139, 249, 1, 130, 254, 182, 85, 105,
  254, 192, 181, 236, 1, 50, 0, 0, 2, 0, 74, 0, 0, 4, 131, 5, 182, 0, 5, 0, 12,
  0, 200, 181, 12, 16, 15, 19, 72, 11, 184, 255, 240, 182, 15, 19, 72, 183, 2,
  1, 2, 184, 255, 248, 64, 68, 13, 17, 72, 38, 2, 1, 23, 2, 1, 6, 2, 1, 184, 1,
  1, 1, 8, 13, 17, 72, 41, 1, 1, 24, 1, 1, 9, 1, 1, 231, 2, 1, 2, 232, 1, 1, 1,
  8, 8, 0, 12, 16, 20, 24, 72, 72, 12, 88, 12, 2, 42, 12, 1, 9, 12, 25, 12, 2,
  12, 95, 3, 111, 3, 2, 3, 3, 14, 11, 184, 255, 240, 64, 54, 20, 24, 72, 71, 11,
  87, 11, 2, 37, 11, 1, 6, 11, 22, 11, 2, 11, 80, 0, 96, 0, 224, 0, 240, 0, 4,
  0, 0, 3, 11, 95, 5, 18, 8, 16, 17, 24, 72, 91, 8, 1, 41, 8, 57, 8, 73, 8, 3,
  29, 8, 1, 8, 1, 3, 0, 63, 51, 93, 93, 93, 43, 63, 225, 57, 57, 1, 47, 93, 51,
  93, 93, 93, 43, 17, 51, 47, 93, 51, 93, 93, 93, 43, 18, 57, 61, 47, 51, 93,
  51, 93, 49, 48, 93, 93, 93, 43, 93, 93, 93, 93, 43, 93, 43, 43, 55, 1, 51, 1,
  21, 33, 1, 38, 39, 6, 7, 3, 33, 74, 1, 190, 187, 1, 192, 251, 199, 2, 119, 59,
  34, 45, 43, 250, 2, 166, 113, 5, 69, 250, 185, 111, 3, 154, 182, 158, 200,
  134, 253, 4, 0, 1, 0, 156, 254, 20, 4, 88, 5, 182, 0, 7, 0, 49, 64, 15, 0, 90,
  224, 7, 240, 7, 2, 7, 9, 3, 90, 0, 4, 1, 4, 184, 255, 192, 64, 11, 20, 24, 72,
  4, 2, 95, 5, 3, 4, 0, 27, 0, 63, 50, 63, 225, 1, 47, 43, 93, 225, 16, 222, 93,
  225, 49, 48, 1, 17, 33, 17, 35, 17, 33, 17, 3, 158, 253, 184, 186, 3, 188,
  254, 20, 6, 252, 249, 4, 7, 162, 248, 94, 0, 1, 0, 74, 254, 20, 4, 145, 5,
  182, 0, 11, 0, 122, 64, 82, 55, 9, 215, 9, 231, 9, 247, 9, 4, 38, 9, 1, 7, 9,
  23, 9, 2, 55, 7, 215, 7, 231, 7, 247, 7, 4, 38, 7, 1, 7, 7, 23, 7, 2, 56, 2,
  216, 2, 232, 2, 248, 2, 4, 25, 2, 41, 2, 2, 8, 2, 1, 8, 2, 2, 0, 6, 10, 13, 7,
  3, 3, 9, 0, 64, 10, 13, 72, 0, 3, 7, 95, 4, 8, 2, 2, 4, 3, 1, 9, 95, 0, 27, 0,
  63, 225, 57, 63, 57, 61, 47, 51, 16, 225, 57, 1, 24, 47, 43, 51, 51, 17, 51,
  16, 206, 50, 17, 57, 47, 51, 49, 48, 93, 93, 93, 93, 93, 93, 93, 93, 93, 19,
  53, 1, 1, 53, 33, 21, 33, 1, 1, 33, 21, 74, 2, 71, 253, 201, 3, 246, 253, 14,
  2, 17, 253, 213, 3, 77, 254, 20, 115, 3, 146, 3, 43, 114, 164, 253, 9, 252,
  157, 164, 0, 0, 1, 0, 152, 2, 135, 4, 51, 3, 29, 0, 3, 0, 26, 64, 12, 2, 5, 0,
  1, 1, 1, 1, 4, 0, 173, 1, 179, 0, 63, 225, 17, 1, 51, 47, 93, 16, 206, 49, 48,
  19, 53, 33, 21, 152, 3, 155, 2, 135, 150, 150, 0, 0, 1, 0, 23, 255, 242, 4,
  182, 6, 160, 0, 8, 0, 46, 64, 21, 1, 0, 6, 6, 7, 8, 8, 10, 5, 2, 2, 3, 3, 174,
  4, 4, 15, 7, 1, 7, 0, 0, 47, 47, 93, 57, 47, 225, 1, 47, 50, 47, 51, 17, 51,
  47, 51, 57, 25, 47, 51, 51, 49, 48, 5, 35, 1, 35, 53, 33, 19, 1, 51, 2, 100,
  133, 254, 236, 180, 1, 40, 230, 2, 0, 145, 14, 3, 10, 143, 253, 105, 5, 172,
  0, 0, 3, 0, 70, 1, 145, 4, 133, 4, 14, 0, 19, 0, 29, 0, 39, 0, 95, 185, 0, 16,
  255, 224, 179, 9, 12, 72, 14, 184, 255, 224, 64, 50, 9, 12, 72, 6, 32, 9, 12,
  72, 4, 32, 9, 12, 72, 30, 10, 0, 20, 4, 5, 35, 171, 15, 15, 1, 15, 41, 25,
  171, 5, 38, 22, 174, 10, 0, 2, 12, 8, 8, 32, 28, 174, 18, 63, 2, 143, 2, 223,
  2, 3, 2, 0, 47, 93, 51, 225, 50, 51, 47, 51, 18, 57, 57, 225, 50, 1, 47, 225,
  16, 222, 93, 225, 17, 23, 57, 49, 48, 43, 43, 43, 43, 1, 6, 35, 34, 38, 53,
  52, 54, 51, 50, 23, 54, 51, 50, 22, 21, 20, 6, 35, 34, 3, 38, 35, 34, 6, 21,
  20, 22, 51, 50, 55, 22, 51, 50, 54, 53, 52, 38, 35, 34, 2, 98, 118, 154, 119,
  149, 149, 119, 166, 108, 116, 165, 118, 146, 151, 113, 171, 181, 82, 109, 65,
  80, 80, 67, 104, 228, 86, 107, 65, 80, 84, 64, 103, 2, 109, 213, 174, 141,
  134, 181, 219, 213, 172, 143, 131, 185, 1, 66, 184, 107, 79, 81, 101, 178,
  185, 109, 78, 79, 103, 0, 1, 0, 236, 254, 20, 3, 225, 6, 20, 0, 20, 0, 41, 64,
  21, 1, 6, 170, 12, 16, 16, 1, 16, 16, 21, 22, 3, 174, 1, 19, 0, 14, 174, 12,
  9, 27, 0, 63, 51, 225, 63, 51, 225, 17, 18, 1, 57, 47, 93, 51, 225, 50, 49,
  48, 1, 21, 38, 35, 34, 21, 17, 20, 6, 35, 34, 39, 53, 22, 51, 50, 53, 17, 16,
  33, 50, 3, 225, 56, 58, 172, 178, 160, 78, 55, 60, 56, 180, 1, 74, 88, 6, 2,
  147, 26, 233, 250, 215, 174, 181, 19, 147, 24, 233, 5, 39, 1, 98, 0, 2, 0,
  152, 1, 123, 4, 51, 4, 37, 0, 17, 0, 35, 0, 72, 64, 41, 28, 9, 37, 18, 0, 0,
  1, 0, 0, 36, 34, 173, 27, 21, 178, 30, 16, 173, 9, 3, 178, 7, 173, 0, 63, 12,
  1, 12, 12, 25, 173, 18, 223, 30, 1, 80, 30, 160, 30, 2, 30, 0, 47, 93, 93, 51,
  225, 51, 47, 93, 51, 225, 253, 50, 225, 16, 253, 50, 225, 17, 1, 51, 47, 93,
  51, 16, 206, 50, 49, 48, 19, 53, 54, 51, 50, 23, 22, 51, 50, 55, 21, 6, 35,
  34, 39, 38, 35, 34, 3, 53, 54, 51, 50, 23, 22, 51, 50, 55, 21, 6, 35, 34, 39,
  38, 35, 34, 152, 98, 149, 98, 150, 127, 74, 109, 118, 97, 151, 100, 147, 128,
  73, 112, 115, 99, 148, 100, 148, 130, 71, 108, 119, 99, 149, 100, 147, 131,
  70, 108, 3, 20, 162, 109, 64, 55, 121, 162, 108, 63, 55, 253, 238, 162, 108,
  63, 56, 121, 162, 108, 63, 56, 0, 1, 0, 152, 0, 164, 4, 51, 5, 4, 0, 19, 0,
  110, 64, 65, 7, 4, 3, 0, 4, 19, 8, 8, 10, 13, 14, 17, 4, 18, 9, 18, 19, 9, 19,
  9, 19, 6, 15, 11, 21, 2, 0, 6, 1, 6, 6, 20, 15, 2, 173, 16, 112, 1, 1, 79, 1,
  95, 1, 111, 1, 3, 0, 1, 1, 1, 1, 12, 5, 173, 11, 143, 6, 1, 80, 6, 1, 15, 6,
  1, 6, 0, 47, 93, 93, 93, 51, 225, 50, 51, 47, 93, 93, 93, 51, 225, 50, 17, 1,
  51, 47, 93, 51, 16, 206, 50, 17, 57, 57, 47, 47, 17, 51, 17, 18, 23, 57, 51,
  17, 18, 23, 57, 49, 48, 1, 35, 53, 33, 19, 33, 53, 33, 19, 23, 7, 51, 21, 33,
  3, 33, 21, 33, 3, 39, 1, 143, 247, 1, 61, 121, 254, 74, 1, 251, 134, 137, 105,
  250, 254, 193, 123, 1, 186, 254, 0, 129, 137, 1, 186, 150, 1, 4, 149, 1, 27,
  59, 224, 149, 254, 252, 150, 254, 234, 57, 0, 2, 0, 152, 0, 0, 4, 51, 4, 201,
  0, 6, 0, 10, 0, 101, 64, 63, 103, 6, 119, 6, 135, 6, 3, 104, 4, 120, 4, 136,
  4, 3, 118, 5, 134, 5, 2, 5, 4, 1, 4, 9, 0, 12, 8, 1, 1, 11, 2, 1, 5, 5, 3, 6,
  224, 0, 1, 223, 0, 1, 64, 0, 1, 63, 0, 1, 0, 0, 1, 0, 0, 4, 32, 3, 192, 3, 2,
  15, 3, 1, 3, 0, 47, 93, 93, 51, 51, 47, 93, 93, 93, 93, 93, 50, 18, 57, 17,
  51, 51, 17, 1, 51, 47, 51, 16, 206, 50, 50, 17, 18, 57, 93, 49, 48, 0, 93, 93,
  37, 1, 53, 1, 21, 9, 2, 53, 33, 21, 4, 51, 252, 101, 3, 155, 253, 53, 2, 203,
  252, 101, 3, 155, 221, 1, 195, 102, 1, 195, 160, 254, 170, 254, 170, 254, 131,
  150, 150, 0, 2, 0, 152, 0, 0, 4, 51, 4, 201, 0, 6, 0, 10, 0, 99, 64, 62, 104,
  2, 120, 2, 136, 2, 3, 103, 0, 119, 0, 135, 0, 3, 121, 1, 137, 1, 2, 1, 6, 9,
  4, 12, 8, 2, 6, 6, 11, 5, 4, 1, 1, 3, 0, 224, 6, 1, 223, 6, 1, 64, 6, 1, 63,
  6, 1, 0, 6, 1, 6, 6, 2, 32, 3, 192, 3, 2, 15, 3, 1, 3, 0, 47, 93, 93, 51, 51,
  47, 93, 93, 93, 93, 93, 51, 18, 57, 17, 51, 51, 17, 1, 51, 47, 51, 51, 16,
  206, 50, 17, 57, 93, 49, 48, 0, 93, 93, 19, 1, 1, 53, 1, 21, 1, 21, 53, 33,
  21, 152, 2, 202, 253, 54, 3, 155, 252, 101, 3, 155, 1, 125, 1, 86, 1, 86, 160,
  254, 61, 102, 254, 61, 221, 150, 150, 0, 2, 0, 125, 0, 0, 4, 80, 5, 195, 0, 5,
  0, 9, 0, 68, 64, 31, 2, 1, 9, 9, 5, 4, 7, 7, 3, 6, 0, 11, 8, 0, 3, 1, 3, 3,
  10, 0, 6, 6, 3, 8, 8, 1, 7, 4, 3, 9, 1, 0, 47, 51, 63, 51, 18, 57, 61, 47, 51,
  51, 17, 51, 17, 1, 51, 24, 47, 93, 51, 16, 206, 50, 17, 57, 61, 47, 51, 51,
  51, 47, 51, 51, 49, 48, 1, 1, 35, 1, 1, 51, 9, 3, 4, 80, 254, 59, 76, 254, 62,
  1, 194, 76, 1, 13, 254, 206, 254, 207, 1, 49, 2, 225, 253, 31, 2, 223, 2, 228,
  253, 30, 2, 0, 254, 0, 253, 254, 0, 3, 0, 49, 0, 0, 4, 43, 6, 31, 0, 21, 0,
  30, 0, 34, 0, 82, 64, 43, 29, 32, 71, 31, 13, 0, 0, 3, 24, 31, 36, 20, 2, 71,
  3, 7, 3, 5, 5, 3, 27, 83, 175, 22, 1, 22, 22, 11, 4, 1, 79, 33, 7, 20, 15, 16,
  80, 14, 11, 1, 32, 2, 21, 0, 63, 51, 63, 51, 225, 63, 51, 51, 225, 50, 18, 57,
  47, 93, 237, 1, 47, 51, 47, 17, 51, 16, 225, 50, 16, 206, 50, 17, 57, 47, 57,
  16, 225, 50, 49, 48, 1, 35, 17, 35, 17, 35, 53, 55, 53, 52, 54, 51, 50, 23, 7,
  38, 35, 34, 6, 21, 21, 51, 1, 50, 21, 20, 6, 35, 34, 53, 52, 19, 35, 17, 51,
  2, 160, 246, 182, 195, 195, 153, 178, 97, 100, 47, 79, 64, 92, 64, 246, 1, 33,
  106, 63, 43, 107, 197, 183, 183, 3, 193, 252, 63, 3, 193, 75, 68, 96, 190,
  177, 37, 141, 28, 101, 114, 104, 1, 155, 114, 58, 57, 115, 114, 250, 27, 4,
  74, 0, 2, 0, 49, 0, 0, 4, 27, 6, 31, 0, 21, 0, 25, 0, 66, 64, 34, 13, 22, 0,
  0, 3, 23, 71, 22, 27, 20, 2, 71, 3, 7, 3, 5, 5, 3, 24, 0, 4, 1, 79, 7, 20, 15,
  16, 80, 14, 11, 1, 23, 2, 21, 0, 63, 51, 63, 51, 225, 63, 51, 225, 50, 63, 1,
  47, 51, 47, 17, 51, 16, 225, 50, 16, 222, 225, 18, 57, 47, 18, 57, 49, 48, 1,
  35, 17, 35, 17, 35, 53, 55, 53, 52, 54, 51, 50, 23, 7, 38, 35, 34, 6, 21, 21,
  51, 1, 35, 17, 51, 2, 160, 246, 182, 195, 195, 153, 178, 97, 100, 47, 79, 64,
  92, 64, 246, 1, 123, 183, 183, 3, 193, 252, 63, 3, 193, 75, 68, 96, 190, 177,
  37, 141, 28, 101, 114, 104, 251, 182, 6, 20, 0, 0, 1, 0, 231, 4, 217, 3, 229,
  6, 23, 0, 11, 0, 45, 64, 16, 6, 136, 0, 5, 1, 5, 5, 11, 136, 0, 0, 13, 5, 0,
  146, 9, 184, 1, 1, 181, 15, 2, 95, 2, 2, 2, 0, 47, 93, 225, 228, 50, 17, 1,
  51, 47, 225, 51, 47, 93, 225, 49, 48, 1, 2, 33, 34, 38, 39, 51, 22, 22, 51,
  50, 55, 3, 229, 20, 254, 143, 195, 172, 10, 170, 8, 84, 119, 194, 17, 6, 23,
  254, 194, 148, 170, 102, 85, 187, 0, 1, 0, 135, 254, 20, 3, 86, 4, 74, 0, 15,
  0, 47, 64, 26, 8, 0, 6, 71, 144, 11, 160, 11, 2, 11, 11, 16, 17, 0, 0, 1, 0,
  3, 80, 1, 14, 27, 7, 78, 10, 15, 0, 63, 225, 63, 51, 225, 1, 47, 93, 17, 18,
  57, 47, 93, 225, 17, 57, 49, 48, 19, 53, 22, 51, 50, 54, 53, 17, 37, 53, 33,
  17, 20, 6, 35, 34, 135, 134, 155, 117, 131, 254, 92, 2, 90, 226, 206, 164,
  254, 55, 154, 39, 114, 101, 4, 57, 21, 123, 251, 65, 180, 195, 0, 0, 1, 1,
  238, 4, 205, 2, 223, 6, 20, 0, 9, 0, 22, 64, 9, 9, 9, 4, 4, 11, 8, 146, 3, 0,
  0, 63, 237, 17, 1, 51, 47, 51, 47, 49, 48, 1, 55, 54, 55, 51, 21, 20, 6, 7,
  35, 1, 238, 26, 26, 9, 180, 84, 61, 96, 4, 231, 107, 116, 78, 20, 14, 198, 95,
  0, 1, 1, 227, 254, 59, 2, 233, 255, 131, 0, 8, 0, 27, 64, 13, 8, 8, 3, 3, 10,
  7, 146, 15, 2, 31, 2, 2, 2, 0, 47, 93, 237, 17, 1, 51, 47, 51, 47, 49, 48, 1,
  54, 55, 51, 21, 20, 6, 7, 35, 1, 227, 62, 22, 178, 96, 67, 99, 254, 86, 140,
  161, 20, 22, 204, 82, 0, 1, 1, 227, 4, 217, 2, 233, 6, 33, 0, 8, 0, 27, 64,
  13, 3, 3, 8, 8, 10, 7, 146, 15, 2, 95, 2, 2, 2, 0, 47, 93, 237, 17, 1, 51, 47,
  51, 47, 49, 48, 1, 6, 7, 35, 53, 52, 54, 55, 51, 2, 233, 63, 20, 179, 91, 73,
  98, 6, 6, 153, 148, 21, 17, 201, 89, 0, 2, 1, 57, 2, 57, 3, 147, 5, 199, 0, 9,
  0, 17, 0, 34, 64, 18, 12, 224, 48, 8, 1, 8, 8, 16, 224, 3, 14, 230, 5, 222,
  10, 230, 0, 223, 0, 63, 225, 63, 225, 1, 47, 225, 51, 47, 93, 225, 49, 48, 1,
  34, 38, 53, 16, 33, 50, 22, 21, 16, 37, 50, 17, 16, 35, 34, 17, 16, 2, 100,
  142, 157, 1, 43, 149, 154, 254, 209, 156, 156, 151, 2, 57, 234, 223, 1, 197,
  236, 217, 254, 55, 131, 1, 70, 1, 68, 254, 188, 254, 186, 0, 2, 1, 37, 2, 168,
  3, 127, 5, 195, 0, 10, 0, 17, 0, 86, 64, 52, 17, 95, 6, 207, 6, 2, 6, 6, 9,
  104, 0, 120, 0, 2, 0, 32, 11, 14, 72, 0, 2, 224, 11, 7, 31, 3, 143, 3, 2, 3,
  3, 18, 19, 4, 1, 228, 17, 6, 14, 7, 11, 9, 27, 9, 2, 9, 9, 2, 7, 222, 2, 223,
  0, 63, 63, 18, 57, 47, 93, 18, 57, 51, 51, 225, 50, 17, 18, 1, 57, 47, 93, 51,
  51, 225, 50, 43, 93, 50, 51, 47, 93, 51, 49, 48, 1, 35, 21, 35, 53, 33, 53, 1,
  51, 17, 51, 35, 53, 52, 55, 6, 7, 7, 3, 127, 84, 143, 254, 137, 1, 121, 141,
  84, 227, 6, 40, 40, 156, 3, 86, 174, 174, 98, 2, 11, 254, 4, 176, 82, 90, 73,
  58, 217, 0, 1, 1, 80, 2, 145, 3, 68, 5, 182, 0, 24, 0, 92, 64, 57, 14, 15, 15,
  11, 12, 64, 16, 24, 72, 10, 12, 10, 12, 0, 5, 224, 15, 20, 31, 20, 79, 20, 95,
  20, 127, 20, 143, 20, 159, 20, 7, 20, 20, 207, 0, 1, 112, 0, 1, 0, 10, 9, 9,
  7, 229, 17, 17, 11, 3, 228, 1, 23, 223, 14, 228, 11, 220, 0, 63, 225, 63, 51,
  225, 17, 57, 47, 225, 51, 18, 57, 1, 47, 93, 93, 51, 47, 93, 225, 18, 57, 57,
  47, 47, 43, 51, 51, 17, 51, 49, 48, 1, 53, 22, 51, 50, 53, 52, 35, 34, 7, 39,
  19, 33, 21, 33, 7, 54, 51, 50, 22, 21, 20, 6, 35, 34, 1, 80, 102, 105, 162,
  166, 52, 73, 62, 31, 1, 141, 254, 224, 17, 35, 61, 118, 147, 150, 145, 124, 2,
  193, 129, 68, 147, 146, 17, 39, 1, 125, 110, 193, 6, 130, 109, 127, 142, 0, 2,
  1, 57, 2, 57, 3, 147, 5, 213, 0, 16, 0, 27, 0, 56, 64, 30, 3, 22, 224, 15, 1,
  15, 17, 224, 48, 9, 1, 9, 9, 15, 3, 19, 228, 0, 6, 1, 6, 6, 0, 25, 230, 12,
  223, 1, 0, 222, 0, 63, 50, 63, 225, 17, 57, 47, 93, 225, 50, 1, 47, 51, 47,
  93, 225, 18, 57, 16, 225, 50, 49, 48, 1, 23, 4, 7, 51, 54, 51, 50, 22, 21, 20,
  6, 35, 34, 38, 53, 16, 1, 52, 35, 34, 6, 21, 20, 22, 51, 50, 54, 3, 29, 45,
  254, 183, 52, 10, 61, 140, 112, 131, 165, 134, 135, 168, 1, 205, 147, 74, 98,
  93, 75, 68, 83, 5, 213, 109, 110, 215, 92, 153, 128, 133, 168, 187, 157, 1,
  151, 254, 60, 172, 87, 64, 86, 113, 92, 0, 1, 1, 111, 2, 160, 3, 147, 5, 182,
  0, 6, 0, 53, 64, 34, 6, 0, 0, 1, 15, 5, 79, 5, 127, 5, 3, 5, 5, 0, 2, 80, 2,
  96, 2, 112, 2, 176, 2, 208, 2, 6, 2, 5, 2, 230, 3, 220, 0, 221, 0, 63, 63,
  225, 50, 1, 47, 93, 50, 47, 93, 51, 57, 47, 51, 49, 48, 1, 1, 33, 53, 33, 21,
  1, 1, 195, 1, 53, 254, 119, 2, 36, 254, 203, 2, 160, 2, 157, 121, 100, 253,
  78, 0, 3, 1, 49, 2, 143, 3, 96, 5, 195, 0, 19, 0, 27, 0, 36, 0, 125, 64, 83,
  10, 28, 12, 34, 224, 2, 20, 0, 2, 26, 224, 12, 22, 224, 18, 12, 18, 12, 18, 8,
  15, 2, 127, 2, 191, 2, 3, 2, 2, 30, 224, 31, 8, 239, 8, 2, 8, 105, 20, 1, 184,
  0, 200, 0, 216, 0, 3, 105, 0, 1, 184, 10, 200, 10, 216, 10, 3, 105, 10, 1,
  105, 28, 185, 28, 201, 28, 217, 28, 4, 28, 10, 0, 20, 4, 5, 24, 229, 15, 222,
  32, 229, 5, 223, 0, 63, 225, 63, 225, 18, 23, 57, 93, 93, 93, 93, 93, 93, 1,
  47, 93, 225, 51, 47, 93, 18, 57, 57, 47, 47, 16, 225, 16, 225, 17, 57, 57, 16,
  225, 17, 57, 57, 49, 48, 1, 22, 21, 20, 6, 35, 34, 38, 53, 52, 55, 38, 53, 52,
  54, 51, 50, 22, 21, 20, 7, 54, 53, 52, 35, 34, 21, 20, 23, 6, 21, 20, 51, 50,
  53, 52, 39, 2, 186, 166, 152, 124, 136, 147, 139, 114, 144, 112, 111, 141,
  252, 106, 108, 107, 92, 118, 131, 135, 135, 4, 66, 85, 122, 103, 125, 118,
  104, 130, 74, 79, 114, 91, 110, 108, 93, 116, 19, 49, 84, 96, 96, 81, 161, 63,
  90, 117, 117, 89, 58, 0, 2, 1, 57, 2, 57, 3, 147, 5, 201, 0, 20, 0, 31, 0, 57,
  64, 31, 5, 26, 224, 1, 11, 48, 17, 1, 17, 17, 21, 224, 11, 5, 23, 228, 15, 8,
  1, 8, 8, 14, 3, 228, 1, 19, 223, 29, 230, 14, 222, 0, 63, 225, 63, 51, 225,
  17, 57, 47, 93, 225, 50, 1, 47, 225, 51, 47, 93, 18, 57, 225, 50, 49, 48, 1,
  53, 22, 51, 32, 19, 35, 6, 35, 34, 38, 53, 52, 54, 51, 50, 22, 21, 16, 33, 34,
  19, 20, 51, 50, 54, 53, 52, 38, 35, 34, 6, 1, 135, 39, 62, 1, 16, 14, 8, 71,
  126, 122, 138, 160, 131, 142, 169, 254, 99, 62, 13, 149, 73, 97, 89, 77, 68,
  85, 2, 72, 125, 23, 1, 59, 98, 149, 126, 133, 170, 205, 186, 253, 247, 2, 99,
  164, 87, 56, 80, 123, 94, 0, 0, 18, 0, 55, 254, 129, 4, 150, 5, 238, 0, 19, 0,
  37, 0, 57, 0, 69, 0, 75, 0, 81, 0, 87, 0, 93, 0, 97, 0, 101, 0, 105, 0, 109,
  0, 113, 0, 117, 0, 121, 0, 125, 0, 134, 0, 143, 1, 6, 64, 46, 98, 122, 101,
  125, 122, 125, 76, 93, 63, 19, 19, 69, 9, 135, 127, 127, 37, 139, 131, 131,
  24, 15, 33, 95, 33, 111, 33, 3, 33, 33, 37, 42, 55, 79, 9, 95, 9, 2, 16, 37,
  32, 37, 96, 37, 3, 37, 184, 255, 192, 64, 100, 21, 24, 72, 64, 55, 80, 55,
  224, 55, 3, 9, 37, 55, 55, 37, 9, 3, 70, 85, 85, 118, 114, 110, 93, 70, 107,
  103, 95, 76, 116, 104, 112, 96, 120, 108, 104, 96, 108, 108, 96, 104, 3, 76,
  71, 41, 57, 57, 38, 27, 126, 126, 135, 32, 15, 19, 72, 135, 135, 20, 127, 127,
  96, 37, 1, 37, 37, 143, 20, 20, 14, 240, 38, 1, 111, 38, 1, 38, 38, 52, 45,
  60, 255, 4, 1, 4, 4, 66, 14, 45, 14, 45, 14, 88, 83, 88, 122, 76, 83, 99, 71,
  0, 47, 51, 51, 47, 51, 51, 17, 18, 57, 57, 47, 47, 17, 51, 51, 47, 93, 51, 17,
  51, 51, 47, 93, 93, 18, 57, 47, 51, 51, 47, 93, 51, 17, 18, 57, 47, 43, 51,
  18, 57, 17, 51, 17, 51, 17, 18, 23, 57, 47, 47, 47, 17, 51, 17, 51, 17, 51, 1,
  47, 50, 50, 50, 50, 47, 51, 51, 51, 51, 17, 18, 23, 57, 47, 47, 47, 93, 43,
  93, 93, 17, 51, 17, 51, 47, 93, 51, 51, 17, 51, 17, 51, 17, 51, 17, 51, 51,
  47, 51, 17, 18, 57, 57, 17, 51, 17, 51, 49, 48, 0, 14, 2, 35, 34, 46, 2, 53,
  52, 62, 2, 51, 50, 30, 2, 21, 3, 51, 50, 22, 21, 20, 6, 7, 21, 30, 3, 21, 20,
  6, 35, 35, 23, 33, 21, 35, 21, 20, 6, 35, 34, 38, 39, 53, 22, 22, 51, 50, 54,
  53, 53, 35, 0, 22, 51, 50, 54, 53, 52, 38, 35, 34, 6, 21, 37, 17, 33, 21, 35,
  21, 3, 17, 51, 21, 51, 21, 1, 53, 33, 17, 35, 53, 3, 53, 51, 53, 51, 17, 1,
  35, 17, 51, 1, 53, 33, 21, 1, 35, 17, 51, 17, 35, 17, 51, 1, 35, 17, 51, 17,
  35, 17, 51, 17, 35, 17, 51, 1, 53, 33, 21, 3, 21, 51, 50, 54, 53, 52, 38, 35,
  39, 51, 50, 54, 53, 52, 38, 35, 35, 2, 160, 25, 52, 78, 54, 54, 79, 51, 25,
  25, 51, 79, 54, 54, 78, 52, 25, 137, 137, 88, 88, 37, 35, 18, 31, 23, 14, 87,
  75, 165, 223, 1, 10, 72, 88, 69, 31, 43, 12, 12, 39, 24, 29, 39, 94, 254, 108,
  53, 56, 57, 51, 51, 57, 56, 53, 254, 213, 1, 47, 192, 111, 111, 192, 2, 0, 1,
  48, 109, 195, 195, 109, 252, 16, 111, 111, 1, 57, 1, 15, 253, 184, 111, 111,
  111, 111, 3, 240, 109, 109, 109, 109, 109, 109, 253, 73, 1, 15, 117, 59, 38,
  30, 30, 42, 55, 51, 37, 29, 33, 37, 47, 4, 5, 88, 64, 35, 35, 64, 88, 54, 55,
  89, 63, 35, 35, 63, 89, 55, 254, 224, 53, 66, 40, 54, 7, 4, 3, 14, 25, 38, 28,
  65, 72, 52, 77, 242, 80, 76, 5, 3, 82, 2, 4, 29, 41, 244, 3, 44, 83, 83, 74,
  75, 83, 83, 75, 131, 1, 48, 111, 193, 249, 195, 1, 47, 194, 109, 6, 254, 111,
  254, 208, 193, 249, 2, 109, 194, 254, 209, 3, 45, 1, 16, 2, 193, 111, 111,
  250, 168, 1, 14, 2, 2, 1, 15, 253, 104, 1, 16, 253, 105, 1, 14, 2, 2, 1, 15,
  250, 59, 109, 109, 3, 145, 122, 34, 31, 25, 32, 80, 27, 25, 27, 24, 0, 3, 0,
  4, 254, 193, 4, 203, 6, 20, 0, 3, 0, 41, 0, 57, 0, 78, 64, 38, 4, 41, 41, 42,
  113, 50, 1, 80, 50, 96, 50, 2, 50, 50, 42, 23, 23, 127, 42, 1, 42, 42, 2, 30,
  15, 15, 2, 55, 45, 41, 41, 45, 45, 3, 27, 18, 18, 3, 0, 25, 47, 51, 24, 47,
  51, 17, 51, 47, 51, 47, 17, 51, 1, 25, 47, 51, 24, 47, 51, 17, 51, 47, 93, 51,
  47, 17, 51, 47, 93, 93, 17, 51, 47, 51, 49, 48, 9, 3, 5, 53, 52, 62, 2, 55,
  62, 3, 53, 52, 38, 35, 34, 14, 2, 7, 23, 54, 54, 51, 50, 22, 21, 20, 14, 2, 7,
  14, 3, 21, 21, 7, 20, 22, 51, 50, 62, 2, 53, 52, 46, 2, 35, 34, 6, 2, 102, 2,
  101, 253, 155, 253, 158, 2, 152, 7, 20, 35, 28, 35, 53, 35, 18, 152, 135, 35,
  72, 70, 65, 28, 66, 55, 102, 45, 53, 50, 11, 24, 38, 28, 31, 43, 27, 13, 21,
  65, 50, 21, 41, 32, 19, 19, 32, 41, 21, 50, 65, 6, 20, 252, 86, 252, 87, 3,
  169, 233, 43, 23, 34, 33, 34, 23, 33, 57, 62, 71, 46, 124, 136, 14, 25, 33,
  18, 160, 31, 41, 53, 42, 26, 40, 36, 37, 24, 28, 51, 54, 59, 36, 55, 246, 65,
  58, 14, 30, 47, 32, 34, 47, 29, 13, 56, 0, 255, 255, 0, 135, 254, 20, 3, 169,
  6, 33, 2, 38, 2, 55, 0, 0, 1, 6, 1, 76, 247, 0, 0, 11, 182, 1, 111, 24, 16, 0,
  10, 37, 1, 43, 53, 0, 255, 255, 1, 190, 3, 193, 3, 12, 5, 182, 2, 6, 2, 7, 0,
  0, 0, 2, 0, 10, 255, 236, 4, 178, 6, 43, 0, 12, 0, 79, 0, 93, 64, 55, 8, 70,
  67, 67, 26, 0, 59, 71, 77, 144, 16, 160, 16, 2, 16, 16, 81, 15, 81, 175, 81,
  2, 51, 70, 144, 26, 1, 26, 62, 79, 79, 78, 0, 78, 34, 78, 41, 0, 41, 16, 41,
  2, 78, 41, 78, 41, 56, 5, 78, 72, 1, 56, 78, 21, 22, 0, 63, 225, 63, 225, 18,
  57, 57, 47, 47, 93, 16, 225, 17, 51, 16, 225, 50, 1, 47, 93, 225, 93, 17, 51,
  47, 93, 51, 225, 50, 17, 57, 47, 225, 49, 48, 1, 46, 3, 35, 34, 6, 21, 20, 30,
  2, 5, 22, 22, 21, 20, 2, 6, 6, 35, 34, 46, 2, 53, 52, 62, 2, 53, 52, 38, 35,
  34, 6, 7, 39, 54, 54, 51, 50, 30, 2, 21, 20, 14, 2, 21, 20, 30, 2, 51, 50, 18,
  17, 52, 38, 39, 46, 3, 53, 52, 62, 2, 51, 50, 30, 2, 23, 51, 21, 3, 106, 13,
  57, 77, 91, 48, 76, 86, 46, 106, 171, 1, 60, 2, 2, 64, 129, 196, 131, 111,
  146, 86, 34, 10, 11, 10, 31, 31, 24, 54, 16, 37, 37, 100, 54, 50, 69, 44, 19,
  10, 11, 10, 21, 48, 78, 58, 164, 164, 2, 2, 174, 242, 150, 67, 39, 81, 127,
  89, 104, 161, 117, 75, 18, 143, 3, 209, 108, 170, 116, 61, 88, 72, 56, 105,
  82, 51, 138, 22, 58, 31, 159, 254, 238, 201, 115, 55, 95, 125, 69, 40, 93, 89,
  75, 24, 45, 33, 15, 10, 127, 17, 26, 28, 50, 68, 40, 35, 86, 93, 97, 45, 42,
  74, 54, 31, 1, 50, 1, 48, 23, 62, 20, 2, 75, 120, 154, 81, 67, 112, 82, 46,
  84, 156, 223, 139, 137, 0, 0, 1, 0, 31, 0, 0, 4, 184, 5, 195, 0, 32, 0, 141,
  185, 0, 32, 255, 248, 179, 20, 24, 72, 32, 184, 255, 248, 64, 70, 13, 16, 72,
  38, 32, 54, 32, 2, 23, 32, 1, 32, 175, 31, 255, 31, 2, 89, 31, 1, 31, 0, 84,
  13, 1, 41, 13, 1, 13, 27, 90, 208, 30, 1, 162, 30, 1, 147, 30, 1, 3, 142, 30,
  1, 4, 99, 30, 1, 5, 16, 30, 80, 30, 2, 30, 17, 10, 10, 59, 27, 1, 59, 30, 1,
  39, 0, 183, 0, 2, 0, 184, 255, 248, 64, 12, 13, 17, 72, 0, 30, 27, 3, 29, 31,
  3, 29, 18, 0, 63, 63, 18, 23, 57, 43, 93, 93, 93, 51, 17, 51, 1, 47, 93, 95,
  93, 95, 93, 95, 93, 93, 93, 225, 50, 93, 93, 57, 205, 93, 93, 50, 93, 93, 43,
  43, 49, 48, 1, 62, 3, 55, 62, 3, 51, 50, 22, 23, 21, 38, 38, 35, 34, 6, 7, 14,
  5, 7, 17, 35, 17, 1, 51, 2, 100, 25, 75, 78, 73, 24, 22, 46, 54, 64, 41, 34,
  43, 17, 12, 33, 12, 28, 62, 35, 12, 47, 58, 66, 63, 56, 19, 187, 254, 25, 202,
  2, 219, 75, 168, 160, 137, 44, 40, 61, 39, 20, 9, 8, 145, 3, 5, 47, 60, 21,
  83, 110, 129, 136, 134, 60, 253, 227, 2, 47, 3, 135, 0, 0, 2, 0, 18, 255, 236,
  4, 180, 4, 74, 0, 32, 0, 64, 0, 95, 64, 60, 30, 29, 86, 56, 102, 56, 2, 71,
  56, 1, 56, 73, 55, 55, 5, 33, 73, 16, 21, 32, 21, 2, 21, 21, 66, 44, 73, 64,
  5, 80, 5, 144, 5, 160, 5, 192, 5, 208, 5, 6, 47, 5, 1, 5, 55, 55, 49, 39, 16,
  10, 80, 13, 15, 60, 30, 49, 80, 26, 0, 22, 0, 63, 50, 225, 50, 50, 63, 225,
  50, 50, 18, 57, 47, 1, 47, 93, 93, 225, 17, 51, 47, 93, 225, 17, 57, 47, 225,
  93, 93, 57, 57, 49, 48, 5, 34, 46, 2, 53, 52, 62, 2, 55, 35, 53, 55, 33, 21,
  35, 30, 3, 21, 20, 14, 2, 35, 34, 38, 39, 35, 6, 6, 1, 52, 46, 2, 39, 33, 14,
  3, 21, 20, 30, 2, 51, 50, 62, 2, 53, 53, 51, 21, 20, 22, 51, 50, 62, 2, 1,
  123, 79, 110, 69, 31, 10, 22, 35, 25, 164, 134, 4, 28, 155, 24, 35, 23, 10,
  31, 69, 110, 79, 94, 111, 26, 11, 26, 111, 1, 246, 10, 23, 35, 24, 253, 233,
  25, 35, 22, 10, 16, 35, 52, 36, 36, 54, 35, 17, 157, 79, 63, 36, 52, 35, 16,
  20, 68, 128, 181, 114, 67, 116, 110, 114, 66, 74, 80, 154, 66, 114, 110, 116,
  67, 114, 181, 128, 68, 87, 91, 91, 87, 1, 235, 62, 114, 112, 118, 67, 67, 118,
  112, 114, 62, 91, 129, 82, 38, 41, 72, 98, 57, 203, 203, 130, 138, 38, 82,
  129, 255, 255, 0, 113, 0, 0, 4, 92, 7, 117, 2, 38, 0, 48, 0, 0, 1, 7, 0, 118,
  0, 100, 1, 84, 0, 19, 64, 11, 1, 26, 5, 38, 1, 100, 20, 23, 6, 12, 37, 1, 43,
  53, 0, 43, 53, 0, 255, 255, 0, 92, 0, 0, 4, 115, 6, 33, 2, 38, 0, 80, 0, 0, 1,
  6, 0, 118, 127, 0, 0, 19, 64, 11, 1, 39, 17, 38, 1, 126, 33, 36, 17, 31, 37,
  1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 33, 253, 213, 4, 172, 5, 188, 2, 38, 0,
  36, 0, 0, 1, 6, 2, 91, 2, 0, 0, 23, 64, 13, 3, 2, 30, 20, 39, 3, 2, 1, 25, 15,
  4, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 135, 253, 213, 4, 2,
  4, 94, 2, 38, 0, 68, 0, 0, 1, 6, 2, 91, 251, 0, 0, 23, 64, 13, 3, 2, 49, 23,
  39, 3, 2, 28, 44, 34, 8, 22, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255,
  254, 200, 255, 236, 5, 12, 5, 205, 0, 39, 0, 50, 0, 145, 0, 0, 1, 7, 2, 92,
  253, 155, 0, 0, 0, 45, 64, 21, 3, 2, 43, 3, 3, 2, 96, 51, 1, 80, 51, 1, 64,
  51, 1, 32, 51, 1, 0, 51, 1, 184, 255, 24, 180, 51, 51, 2, 2, 37, 1, 43, 93,
  93, 93, 93, 93, 53, 53, 0, 63, 53, 53, 0, 0, 2, 1, 131, 253, 213, 3, 72, 255,
  131, 0, 19, 0, 31, 0, 77, 64, 16, 20, 16, 19, 24, 72, 20, 131, 15, 0, 31, 0,
  47, 0, 3, 0, 26, 184, 255, 240, 182, 19, 24, 72, 26, 131, 10, 29, 184, 255,
  248, 64, 25, 21, 24, 72, 29, 140, 0, 5, 16, 5, 32, 5, 112, 5, 192, 5, 5, 5,
  23, 8, 21, 24, 72, 23, 140, 15, 0, 47, 225, 43, 220, 93, 225, 43, 1, 47, 225,
  43, 220, 93, 225, 43, 49, 48, 1, 20, 14, 2, 35, 34, 46, 2, 53, 52, 62, 2, 51,
  50, 30, 2, 7, 52, 38, 35, 34, 6, 21, 20, 22, 51, 50, 54, 3, 72, 35, 62, 84,
  49, 50, 82, 59, 32, 32, 59, 82, 50, 48, 84, 62, 36, 117, 63, 50, 49, 63, 57,
  55, 50, 63, 254, 174, 51, 81, 56, 29, 29, 56, 79, 51, 51, 79, 56, 29, 29, 55,
  79, 52, 53, 60, 60, 53, 53, 60, 60, 0, 0, 2, 1, 45, 4, 104, 3, 139, 5, 199, 0,
  17, 0, 31, 0, 48, 64, 26, 64, 0, 1, 0, 64, 12, 12, 18, 32, 9, 12, 72, 18, 128,
  24, 23, 30, 23, 30, 79, 3, 95, 3, 2, 3, 15, 0, 47, 204, 93, 57, 57, 47, 47, 1,
  47, 26, 205, 43, 50, 47, 26, 205, 93, 49, 48, 1, 52, 54, 55, 21, 6, 6, 21, 20,
  30, 2, 21, 20, 6, 35, 34, 38, 5, 62, 3, 55, 51, 21, 14, 3, 7, 35, 1, 45, 120,
  122, 60, 57, 31, 36, 31, 50, 46, 59, 68, 1, 53, 11, 25, 24, 22, 8, 207, 18,
  48, 56, 62, 31, 82, 4, 231, 78, 115, 31, 76, 22, 46, 24, 19, 18, 16, 26, 28,
  37, 39, 70, 37, 30, 75, 79, 81, 36, 20, 32, 77, 80, 81, 37, 0, 0, 2, 0, 66, 0,
  0, 4, 41, 6, 31, 0, 39, 0, 52, 0, 99, 64, 55, 22, 41, 28, 28, 39, 39, 2, 41,
  6, 38, 3, 3, 6, 6, 10, 223, 2, 1, 2, 2, 54, 40, 7, 7, 13, 0, 10, 16, 10, 80,
  10, 160, 10, 176, 10, 5, 10, 10, 7, 3, 82, 40, 13, 38, 15, 47, 32, 78, 19, 25,
  1, 9, 5, 1, 21, 0, 63, 51, 51, 63, 51, 225, 50, 63, 51, 51, 225, 50, 50, 1,
  47, 93, 51, 51, 17, 51, 17, 51, 47, 93, 18, 57, 47, 51, 17, 51, 17, 51, 17,
  51, 17, 51, 17, 18, 57, 49, 48, 33, 35, 17, 35, 17, 35, 17, 35, 17, 35, 17,
  35, 53, 55, 53, 52, 62, 2, 51, 50, 22, 23, 54, 54, 51, 50, 22, 23, 7, 38, 38,
  35, 34, 14, 2, 21, 21, 33, 33, 51, 53, 52, 55, 38, 38, 35, 34, 14, 2, 21, 4,
  41, 164, 203, 163, 205, 164, 100, 100, 40, 77, 112, 72, 49, 87, 34, 38, 102,
  63, 52, 91, 37, 41, 29, 69, 37, 38, 55, 36, 17, 1, 111, 253, 33, 205, 24, 20,
  45, 23, 35, 53, 35, 18, 3, 203, 252, 53, 3, 203, 252, 53, 3, 203, 65, 62, 82,
  106, 141, 84, 35, 22, 13, 29, 27, 23, 14, 131, 11, 17, 22, 52, 87, 64, 104,
  102, 115, 78, 6, 8, 22, 52, 87, 64, 0, 2, 0, 66, 0, 0, 4, 41, 6, 31, 0, 39, 0,
  52, 0, 97, 64, 54, 44, 20, 41, 26, 26, 29, 41, 4, 38, 1, 1, 4, 4, 8, 223, 29,
  1, 29, 29, 54, 40, 5, 5, 11, 0, 8, 16, 8, 80, 8, 160, 8, 176, 8, 5, 8, 8, 5,
  1, 82, 40, 11, 38, 15, 7, 3, 28, 21, 47, 32, 78, 17, 23, 1, 0, 63, 51, 225,
  50, 63, 51, 51, 63, 51, 51, 225, 50, 50, 1, 47, 93, 51, 51, 17, 51, 17, 51,
  47, 93, 18, 57, 47, 51, 17, 51, 17, 51, 17, 51, 17, 18, 57, 57, 49, 48, 1, 35,
  17, 35, 17, 35, 17, 35, 17, 35, 53, 55, 53, 52, 62, 2, 51, 50, 22, 23, 54, 54,
  51, 50, 23, 51, 17, 35, 17, 38, 38, 35, 34, 14, 2, 21, 21, 51, 33, 51, 53, 52,
  55, 38, 38, 35, 34, 14, 2, 21, 3, 72, 142, 163, 205, 164, 100, 100, 40, 77,
  112, 72, 49, 87, 34, 38, 102, 63, 48, 46, 131, 164, 14, 29, 14, 38, 55, 36,
  17, 142, 254, 2, 205, 24, 20, 45, 23, 35, 53, 35, 18, 3, 203, 252, 53, 3, 203,
  252, 53, 3, 203, 65, 62, 82, 106, 141, 84, 35, 22, 13, 29, 27, 11, 249, 236,
  5, 141, 3, 3, 22, 52, 87, 64, 104, 102, 115, 78, 6, 8, 22, 52, 87, 64, 0, 2,
  0, 84, 255, 236, 4, 246, 6, 20, 0, 32, 0, 52, 0, 51, 64, 28, 23, 91, 25, 43,
  91, 30, 18, 0, 54, 33, 91, 31, 10, 47, 10, 2, 10, 30, 48, 95, 23, 18, 15, 4,
  38, 95, 5, 19, 0, 63, 225, 63, 51, 206, 225, 50, 1, 47, 93, 225, 16, 222, 50,
  50, 225, 214, 225, 49, 48, 1, 20, 2, 6, 6, 35, 34, 38, 38, 2, 53, 52, 18, 54,
  54, 51, 50, 22, 23, 62, 3, 55, 51, 23, 14, 3, 7, 22, 22, 5, 20, 30, 2, 51, 50,
  62, 2, 53, 52, 46, 2, 35, 34, 14, 2, 4, 123, 64, 132, 200, 135, 142, 201, 129,
  60, 60, 129, 203, 142, 124, 187, 66, 18, 23, 13, 6, 2, 198, 15, 11, 33, 49,
  68, 46, 42, 42, 252, 158, 36, 79, 128, 92, 93, 128, 78, 35, 35, 78, 127, 92,
  93, 128, 80, 36, 2, 221, 169, 254, 234, 198, 108, 108, 198, 1, 23, 170, 170,
  1, 21, 196, 107, 90, 86, 19, 52, 63, 73, 40, 22, 52, 99, 87, 74, 28, 91, 233,
  137, 137, 219, 153, 81, 81, 153, 219, 137, 138, 218, 151, 81, 81, 151, 218, 0,
  0, 2, 0, 115, 255, 236, 4, 246, 4, 242, 0, 32, 0, 43, 0, 53, 64, 28, 18, 30,
  30, 0, 23, 74, 25, 38, 72, 0, 45, 33, 72, 0, 10, 1, 10, 30, 41, 80, 23, 18,
  15, 16, 36, 80, 5, 22, 0, 63, 225, 63, 51, 198, 225, 50, 1, 47, 93, 225, 16,
  222, 225, 220, 225, 17, 51, 17, 51, 48, 49, 1, 20, 14, 2, 35, 34, 46, 2, 53,
  52, 62, 2, 51, 50, 22, 23, 62, 3, 53, 51, 23, 14, 3, 7, 22, 22, 5, 20, 22, 51,
  32, 17, 52, 38, 35, 34, 6, 4, 88, 74, 133, 184, 111, 103, 180, 134, 78, 73,
  132, 185, 111, 97, 171, 66, 38, 43, 21, 5, 198, 15, 15, 42, 57, 75, 49, 38,
  42, 252, 215, 157, 154, 1, 54, 157, 155, 154, 155, 2, 39, 137, 213, 145, 76,
  76, 145, 213, 137, 136, 211, 145, 75, 66, 65, 16, 56, 72, 87, 48, 23, 69, 114,
  91, 67, 21, 66, 165, 99, 211, 209, 1, 164, 210, 206, 206, 0, 0, 1, 0, 125,
  255, 236, 5, 23, 6, 20, 0, 38, 0, 54, 64, 30, 6, 91, 96, 8, 112, 8, 2, 8, 37,
  90, 1, 14, 40, 27, 90, 0, 24, 1, 24, 13, 1, 1, 38, 6, 25, 3, 32, 95, 19, 19,
  0, 63, 225, 63, 206, 51, 51, 47, 51, 1, 47, 93, 225, 16, 222, 50, 225, 220,
  93, 225, 49, 48, 1, 21, 62, 3, 53, 51, 23, 14, 3, 7, 17, 20, 14, 2, 35, 34,
  46, 2, 53, 17, 51, 17, 20, 30, 2, 51, 50, 62, 2, 53, 17, 3, 182, 47, 55, 29,
  9, 198, 15, 15, 48, 82, 121, 87, 45, 99, 159, 115, 108, 154, 99, 46, 186, 24,
  54, 89, 65, 67, 86, 49, 19, 5, 182, 194, 8, 52, 77, 97, 54, 22, 69, 127, 105,
  75, 17, 253, 102, 114, 183, 129, 69, 65, 126, 186, 122, 3, 215, 252, 51, 87,
  130, 86, 43, 48, 90, 129, 82, 3, 202, 0, 0, 1, 0, 160, 255, 236, 5, 23, 4,
  242, 0, 39, 0, 87, 183, 31, 74, 0, 33, 16, 33, 2, 33, 184, 255, 192, 179, 20,
  23, 72, 33, 184, 255, 192, 64, 35, 14, 17, 72, 33, 1, 0, 23, 71, 26, 38, 41,
  14, 71, 0, 13, 176, 13, 2, 13, 38, 26, 26, 13, 31, 31, 24, 13, 15, 2, 18, 80,
  7, 22, 0, 21, 0, 63, 63, 225, 50, 63, 51, 51, 47, 17, 51, 47, 51, 1, 47, 93,
  225, 16, 222, 50, 225, 50, 50, 221, 43, 43, 93, 225, 48, 49, 33, 39, 35, 14,
  3, 35, 34, 46, 2, 53, 17, 51, 17, 20, 22, 51, 50, 62, 2, 53, 17, 51, 21, 62,
  3, 53, 51, 23, 14, 3, 7, 17, 3, 18, 26, 8, 22, 60, 72, 80, 41, 79, 119, 79,
  40, 182, 84, 90, 66, 90, 56, 24, 182, 52, 62, 32, 10, 198, 15, 15, 50, 85,
  127, 92, 147, 43, 63, 41, 20, 46, 98, 152, 105, 2, 205, 253, 61, 130, 130, 52,
  101, 148, 96, 2, 58, 123, 6, 50, 78, 101, 56, 23, 70, 136, 110, 72, 7, 252,
  176, 255, 255, 1, 162, 4, 217, 3, 43, 6, 33, 2, 6, 0, 67, 0, 0, 255, 255, 1,
  162, 4, 217, 3, 43, 6, 33, 2, 6, 0, 118, 0, 0, 255, 255, 0, 254, 4, 217, 3,
  205, 5, 227, 2, 6, 1, 82, 0, 0, 0, 1, 1, 172, 4, 184, 3, 33, 6, 143, 0, 27, 0,
  46, 64, 23, 7, 5, 8, 8, 21, 13, 132, 0, 0, 21, 5, 8, 8, 6, 18, 141, 15, 25,
  31, 25, 2, 25, 6, 0, 47, 220, 93, 225, 18, 57, 47, 51, 1, 47, 51, 47, 225, 17,
  57, 47, 51, 51, 48, 49, 1, 20, 14, 2, 7, 7, 35, 39, 62, 3, 53, 52, 46, 2, 35,
  34, 6, 7, 53, 54, 54, 51, 50, 22, 3, 33, 27, 45, 60, 34, 10, 113, 14, 37, 59,
  42, 23, 20, 36, 50, 29, 28, 52, 16, 16, 50, 41, 133, 133, 5, 211, 39, 58, 41,
  26, 8, 111, 176, 6, 16, 24, 33, 24, 24, 32, 19, 7, 3, 3, 108, 3, 5, 91, 0, 0,
  1, 1, 252, 254, 152, 2, 209, 255, 125, 0, 13, 0, 15, 181, 6, 135, 0, 11, 145,
  3, 0, 47, 237, 1, 47, 237, 48, 49, 5, 52, 54, 51, 50, 22, 21, 20, 14, 2, 35,
  34, 38, 1, 252, 61, 45, 44, 63, 17, 29, 39, 22, 45, 61, 246, 60, 55, 55, 60,
  29, 43, 28, 14, 55, 255, 255, 0, 217, 0, 0, 4, 35, 7, 115, 2, 38, 0, 40, 0, 0,
  1, 7, 0, 67, 255, 183, 1, 82, 0, 21, 180, 1, 12, 5, 38, 1, 184, 255, 160, 180,
  15, 12, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 137, 0, 0, 4, 70, 7,
  115, 2, 38, 1, 178, 0, 0, 1, 7, 0, 67, 255, 181, 1, 82, 0, 21, 180, 1, 17, 5,
  38, 1, 184, 255, 180, 180, 20, 17, 0, 8, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 133, 255, 236, 4, 72, 6, 33, 2, 38, 0, 72, 0, 0, 1, 6, 0, 67, 212, 0,
  0, 21, 180, 2, 23, 17, 38, 2, 184, 255, 212, 180, 26, 23, 11, 0, 37, 1, 43,
  53, 0, 43, 53, 0, 255, 255, 0, 160, 0, 0, 4, 45, 6, 33, 2, 38, 1, 210, 0, 0,
  1, 6, 0, 67, 179, 0, 0, 21, 180, 1, 12, 17, 38, 1, 184, 255, 179, 180, 15, 12,
  10, 4, 37, 1, 43, 53, 0, 43, 53, 0, 0, 1, 0, 82, 255, 236, 4, 123, 5, 201, 0,
  60, 0, 117, 64, 31, 12, 15, 13, 191, 13, 2, 13, 64, 12, 17, 72, 13, 13, 19,
  29, 0, 251, 58, 58, 39, 7, 251, 19, 62, 46, 0, 45, 176, 45, 2, 45, 184, 255,
  192, 64, 34, 12, 17, 72, 45, 45, 51, 251, 47, 39, 1, 39, 59, 59, 56, 42, 12,
  46, 46, 10, 48, 95, 16, 42, 4, 0, 58, 58, 29, 2, 56, 95, 24, 34, 19, 0, 63,
  51, 225, 50, 50, 50, 17, 51, 63, 51, 241, 50, 194, 47, 50, 17, 18, 57, 47, 1,
  47, 93, 225, 50, 47, 43, 93, 51, 16, 222, 225, 17, 57, 47, 225, 57, 17, 51,
  47, 43, 93, 51, 49, 48, 37, 22, 51, 50, 62, 2, 53, 16, 2, 35, 34, 7, 39, 54,
  54, 51, 50, 18, 17, 20, 2, 6, 6, 35, 34, 46, 2, 39, 14, 3, 35, 34, 38, 38, 2,
  53, 16, 18, 51, 50, 22, 23, 7, 38, 35, 34, 2, 17, 20, 30, 2, 51, 50, 55, 17,
  51, 2, 188, 39, 56, 48, 67, 42, 19, 78, 66, 55, 41, 47, 34, 88, 48, 146, 147,
  34, 78, 128, 94, 33, 54, 46, 43, 23, 22, 42, 46, 53, 33, 94, 128, 79, 35, 147,
  146, 48, 88, 34, 47, 41, 56, 66, 77, 19, 43, 68, 48, 57, 37, 170, 186, 43, 89,
  164, 229, 141, 1, 19, 1, 20, 29, 152, 23, 18, 254, 153, 254, 154, 192, 254,
  219, 198, 101, 13, 24, 37, 24, 24, 37, 24, 13, 101, 198, 1, 37, 192, 1, 102,
  1, 103, 18, 23, 152, 29, 254, 236, 254, 237, 141, 229, 164, 89, 43, 1, 220, 0,
  0, 1, 255, 252, 0, 0, 4, 137, 4, 74, 0, 42, 0, 122, 64, 46, 7, 13, 1, 13, 38,
  14, 33, 21, 253, 34, 1, 187, 34, 1, 34, 34, 27, 15, 73, 95, 14, 1, 14, 14, 1,
  27, 73, 12, 28, 1, 28, 44, 42, 6, 0, 0, 1, 166, 0, 182, 0, 2, 148, 0, 1, 0,
  184, 255, 192, 64, 23, 11, 15, 72, 0, 0, 2, 73, 1, 38, 13, 13, 0, 27, 14, 1,
  15, 21, 34, 34, 7, 79, 0, 21, 0, 63, 225, 51, 17, 51, 63, 51, 51, 18, 57, 17,
  51, 1, 47, 225, 51, 47, 43, 93, 93, 113, 51, 51, 16, 222, 93, 225, 17, 57, 47,
  93, 225, 17, 51, 47, 93, 93, 51, 51, 18, 57, 57, 93, 49, 48, 33, 1, 51, 19,
  22, 22, 23, 51, 62, 3, 55, 19, 3, 51, 19, 30, 3, 23, 51, 62, 2, 18, 53, 51,
  20, 2, 2, 6, 7, 35, 3, 38, 38, 39, 6, 6, 7, 3, 1, 27, 254, 225, 160, 163, 20,
  34, 8, 4, 5, 15, 18, 20, 10, 86, 109, 150, 137, 8, 22, 23, 22, 7, 6, 63, 79,
  45, 16, 153, 26, 66, 113, 88, 163, 84, 7, 11, 3, 5, 16, 8, 106, 4, 74, 253,
  92, 85, 157, 51, 18, 56, 65, 67, 30, 1, 16, 1, 205, 253, 176, 33, 96, 103, 96,
  33, 104, 210, 230, 1, 2, 151, 163, 254, 224, 254, 245, 253, 127, 1, 84, 26,
  56, 20, 20, 62, 22, 254, 174, 0, 0, 2, 0, 20, 0, 0, 4, 117, 6, 20, 0, 22, 0,
  33, 0, 65, 64, 33, 19, 0, 23, 90, 16, 12, 12, 14, 27, 91, 21, 6, 35, 14, 33,
  95, 0, 22, 14, 95, 15, 19, 15, 0, 15, 0, 15, 17, 0, 23, 96, 12, 18, 0, 63,
  225, 63, 57, 57, 47, 47, 17, 51, 16, 225, 50, 16, 225, 1, 47, 16, 222, 204,
  225, 17, 57, 47, 51, 225, 50, 50, 48, 49, 1, 51, 50, 30, 2, 21, 20, 14, 2, 35,
  33, 17, 33, 53, 33, 17, 51, 17, 33, 21, 33, 17, 51, 50, 54, 53, 52, 46, 2, 35,
  35, 1, 250, 94, 152, 207, 127, 55, 60, 126, 194, 134, 254, 204, 254, 213, 1,
  43, 187, 1, 137, 254, 119, 104, 175, 163, 46, 91, 138, 93, 74, 3, 78, 66, 113,
  152, 87, 97, 158, 112, 61, 4, 96, 164, 1, 16, 254, 240, 164, 252, 64, 132,
  136, 70, 97, 60, 27, 0, 2, 0, 20, 0, 0, 4, 88, 5, 39, 0, 20, 0, 33, 0, 67, 64,
  34, 0, 0, 28, 19, 2, 22, 71, 16, 12, 12, 14, 28, 70, 6, 35, 14, 1, 13, 80, 16,
  21, 80, 2, 2, 19, 16, 17, 17, 16, 15, 22, 80, 12, 21, 0, 63, 225, 63, 51, 47,
  17, 51, 57, 47, 225, 16, 225, 50, 1, 47, 16, 222, 225, 17, 57, 47, 51, 225,
  50, 50, 17, 57, 47, 48, 49, 1, 33, 17, 33, 50, 22, 21, 20, 14, 2, 35, 33, 17,
  35, 53, 51, 53, 51, 21, 33, 1, 17, 51, 50, 62, 2, 53, 52, 46, 2, 35, 2, 227,
  254, 213, 1, 0, 212, 204, 47, 101, 159, 113, 254, 78, 238, 238, 182, 1, 43,
  254, 213, 240, 55, 93, 68, 38, 33, 65, 96, 64, 3, 176, 254, 215, 156, 155, 77,
  124, 88, 47, 3, 176, 154, 221, 221, 253, 164, 254, 168, 17, 41, 66, 48, 49,
  66, 40, 17, 0, 0, 1, 0, 98, 255, 236, 4, 182, 5, 203, 0, 45, 0, 86, 64, 48, 5,
  8, 34, 27, 64, 9, 12, 72, 15, 7, 1, 27, 7, 17, 17, 7, 27, 3, 30, 42, 47, 33,
  29, 251, 30, 8, 28, 95, 5, 33, 33, 13, 43, 0, 95, 42, 39, 4, 31, 3, 30, 18,
  16, 13, 95, 17, 22, 19, 0, 63, 51, 225, 50, 63, 63, 63, 51, 225, 50, 18, 57,
  47, 51, 225, 50, 1, 47, 225, 50, 16, 206, 17, 23, 57, 47, 47, 47, 93, 43, 51,
  201, 50, 48, 49, 1, 34, 14, 2, 7, 33, 21, 33, 30, 3, 51, 50, 54, 55, 21, 14,
  3, 35, 34, 38, 38, 2, 39, 35, 17, 35, 17, 51, 17, 51, 62, 3, 51, 50, 22, 23,
  7, 38, 38, 3, 145, 68, 114, 85, 55, 9, 1, 211, 254, 41, 3, 45, 85, 125, 82,
  66, 116, 57, 30, 59, 64, 73, 44, 120, 178, 120, 62, 4, 139, 166, 166, 144, 11,
  76, 128, 178, 112, 84, 149, 60, 73, 45, 106, 5, 39, 64, 122, 176, 111, 162,
  130, 201, 138, 72, 35, 23, 162, 15, 23, 14, 7, 100, 184, 1, 3, 159, 253, 86,
  5, 182, 253, 152, 143, 235, 167, 92, 44, 42, 156, 32, 46, 0, 0, 1, 0, 160,
  255, 236, 4, 123, 4, 94, 0, 45, 0, 85, 64, 47, 31, 34, 73, 12, 15, 5, 31, 5,
  2, 5, 33, 5, 33, 8, 43, 22, 47, 11, 7, 73, 0, 8, 1, 8, 23, 28, 81, 17, 34, 6,
  80, 31, 11, 11, 22, 17, 16, 9, 15, 8, 21, 42, 39, 81, 43, 0, 22, 0, 63, 50,
  225, 50, 63, 63, 63, 51, 57, 47, 51, 237, 50, 16, 225, 50, 1, 47, 93, 225, 50,
  16, 206, 50, 17, 57, 57, 47, 47, 93, 51, 225, 50, 48, 49, 5, 34, 46, 2, 39,
  35, 17, 35, 17, 51, 17, 51, 62, 3, 51, 50, 30, 2, 23, 7, 46, 3, 35, 34, 6, 7,
  33, 21, 33, 30, 3, 51, 50, 54, 55, 21, 6, 6, 3, 127, 85, 149, 114, 70, 6, 149,
  162, 162, 151, 11, 75, 114, 147, 83, 34, 68, 64, 57, 21, 47, 21, 50, 52, 51,
  23, 123, 129, 12, 1, 162, 254, 92, 4, 36, 64, 93, 61, 72, 115, 48, 47, 110,
  20, 58, 123, 193, 135, 254, 23, 4, 74, 254, 57, 128, 181, 114, 52, 9, 16, 22,
  12, 154, 10, 19, 15, 9, 151, 166, 154, 92, 132, 84, 40, 37, 25, 162, 29, 30,
  0, 0, 2, 0, 0, 0, 0, 4, 205, 5, 182, 0, 11, 0, 20, 0, 169, 64, 32, 16, 15, 14,
  13, 8, 7, 17, 7, 14, 15, 16, 3, 17, 7, 8, 7, 24, 7, 2, 7, 6, 7, 5, 1, 199, 5,
  215, 5, 231, 5, 3, 5, 184, 255, 248, 64, 64, 10, 16, 72, 5, 17, 18, 19, 20, 1,
  2, 17, 2, 20, 19, 18, 3, 2, 8, 4, 1, 200, 4, 216, 4, 232, 4, 3, 4, 8, 10, 16,
  72, 4, 17, 17, 21, 6, 10, 251, 21, 11, 1, 11, 11, 3, 6, 2, 3, 9, 8, 1, 96, 13,
  12, 12, 2, 17, 95, 4, 3, 11, 7, 2, 18, 0, 63, 51, 51, 63, 225, 18, 57, 47, 51,
  225, 50, 50, 1, 47, 51, 47, 18, 57, 47, 93, 225, 17, 18, 57, 17, 51, 43, 93,
  113, 18, 0, 23, 57, 16, 125, 135, 5, 196, 196, 196, 196, 17, 1, 51, 43, 93,
  113, 17, 51, 93, 17, 18, 0, 23, 57, 16, 135, 5, 196, 196, 196, 196, 196, 49,
  48, 1, 35, 3, 35, 1, 51, 1, 35, 3, 35, 17, 35, 3, 33, 39, 38, 38, 39, 6, 6, 7,
  2, 16, 112, 238, 178, 2, 8, 187, 2, 10, 182, 238, 115, 166, 55, 1, 29, 39, 37,
  51, 19, 18, 60, 28, 2, 170, 253, 86, 5, 182, 250, 74, 2, 170, 253, 86, 3, 68,
  110, 105, 170, 75, 75, 183, 92, 0, 0, 2, 0, 61, 0, 0, 4, 141, 4, 74, 0, 11, 0,
  23, 0, 210, 64, 108, 18, 19, 20, 21, 22, 8, 9, 17, 21, 20, 19, 18, 4, 17, 71,
  9, 1, 9, 71, 10, 5, 73, 6, 168, 11, 184, 11, 2, 138, 11, 154, 11, 2, 11, 8,
  12, 16, 72, 11, 23, 12, 13, 14, 15, 17, 2, 17, 15, 14, 13, 12, 4, 2, 198, 0,
  1, 179, 0, 1, 165, 0, 1, 134, 0, 150, 0, 2, 117, 0, 1, 70, 0, 86, 0, 102, 0,
  3, 55, 0, 1, 0, 17, 17, 134, 6, 150, 6, 2, 21, 6, 37, 6, 2, 6, 6, 1, 10, 72,
  2, 1, 2, 1, 4, 3, 8, 80, 23, 22, 184, 255, 192, 64, 20, 9, 12, 72, 22, 22, 1,
  11, 16, 17, 82, 11, 15, 9, 21, 2, 21, 10, 6, 1, 21, 0, 63, 51, 51, 63, 63, 63,
  241, 196, 17, 18, 57, 47, 43, 51, 225, 50, 50, 1, 47, 193, 93, 47, 18, 57, 47,
  93, 93, 57, 17, 51, 93, 93, 93, 93, 93, 93, 93, 18, 0, 23, 57, 16, 125, 135,
  5, 196, 196, 196, 196, 196, 1, 51, 43, 93, 93, 16, 225, 16, 241, 93, 17, 0,
  23, 57, 135, 5, 196, 196, 196, 196, 196, 196, 49, 48, 1, 1, 35, 3, 35, 17, 35,
  17, 35, 3, 35, 1, 18, 46, 2, 39, 35, 14, 3, 7, 51, 2, 217, 1, 180, 188, 184,
  99, 162, 104, 184, 183, 1, 181, 225, 35, 35, 29, 8, 12, 8, 30, 34, 34, 13,
  252, 4, 74, 251, 182, 1, 233, 254, 23, 1, 233, 254, 23, 4, 74, 254, 92, 90,
  93, 86, 30, 29, 87, 93, 91, 34, 0, 0, 2, 0, 98, 0, 0, 4, 252, 5, 182, 0, 19,
  0, 28, 1, 4, 64, 138, 198, 13, 1, 183, 13, 1, 166, 13, 1, 119, 13, 1, 13, 25,
  136, 21, 1, 89, 21, 105, 21, 2, 24, 23, 22, 21, 16, 15, 25, 15, 22, 23, 24, 3,
  25, 15, 86, 20, 102, 20, 134, 20, 3, 26, 27, 28, 20, 1, 2, 25, 2, 28, 27, 26,
  3, 2, 216, 12, 1, 201, 12, 1, 120, 12, 168, 12, 184, 12, 3, 12, 25, 25, 14, 3,
  6, 18, 1, 18, 251, 19, 1, 204, 19, 1, 181, 19, 1, 166, 19, 1, 90, 19, 106, 19,
  138, 19, 3, 5, 19, 1, 19, 19, 7, 15, 0, 14, 1, 14, 23, 2, 1, 2, 50, 3, 1, 41,
  3, 1, 24, 3, 1, 3, 3, 10, 6, 251, 7, 17, 16, 1, 96, 20, 21, 20, 80, 20, 1, 20,
  184, 255, 192, 64, 20, 9, 12, 72, 20, 4, 5, 96, 11, 10, 10, 2, 25, 12, 8, 3,
  19, 15, 7, 2, 18, 0, 63, 51, 51, 51, 63, 51, 192, 18, 57, 47, 51, 225, 50, 51,
  43, 93, 17, 51, 16, 237, 50, 50, 1, 47, 225, 50, 50, 47, 93, 93, 93, 193, 93,
  47, 93, 193, 18, 57, 47, 93, 93, 93, 93, 93, 93, 193, 93, 17, 18, 57, 17, 51,
  93, 93, 93, 18, 0, 23, 57, 16, 125, 135, 5, 196, 196, 196, 196, 196, 1, 93,
  17, 18, 0, 23, 57, 16, 135, 5, 196, 196, 196, 196, 196, 1, 93, 93, 17, 51, 93,
  93, 93, 93, 48, 49, 1, 35, 3, 35, 19, 33, 17, 35, 17, 51, 17, 33, 19, 51, 1,
  35, 3, 35, 17, 35, 3, 51, 39, 38, 38, 39, 6, 6, 7, 2, 215, 47, 168, 168, 176,
  255, 0, 166, 166, 1, 39, 162, 174, 1, 125, 168, 172, 45, 164, 8, 182, 18, 22,
  40, 12, 12, 38, 20, 2, 170, 253, 86, 2, 170, 253, 86, 5, 182, 253, 148, 2,
  108, 250, 74, 2, 170, 253, 86, 3, 74, 84, 97, 153, 75, 75, 153, 91, 0, 0, 2,
  0, 123, 0, 0, 5, 10, 4, 74, 0, 19, 0, 31, 0, 200, 64, 122, 17, 13, 73, 14,
  102, 5, 1, 84, 5, 1, 5, 73, 4, 6, 20, 6, 52, 6, 68, 6, 4, 244, 6, 1, 203, 6,
  1, 188, 6, 1, 165, 6, 1, 106, 6, 1, 89, 6, 1, 69, 6, 1, 51, 6, 1, 27, 6, 1, 6,
  6, 1, 0, 14, 16, 14, 2, 14, 18, 11, 10, 19, 10, 19, 8, 24, 30, 9, 3, 25, 30,
  2, 0, 100, 30, 1, 30, 30, 2, 9, 192, 10, 1, 15, 10, 1, 0, 10, 1, 10, 2, 0, 1,
  80, 1, 2, 1, 30, 4, 3, 8, 80, 24, 25, 24, 24, 11, 12, 80, 18, 17, 17, 1, 19,
  15, 15, 9, 2, 14, 10, 6, 1, 21, 0, 63, 51, 51, 51, 47, 47, 63, 51, 18, 57, 47,
  51, 225, 50, 51, 17, 51, 16, 225, 50, 50, 47, 1, 47, 93, 193, 47, 93, 113,
  113, 193, 17, 57, 25, 47, 93, 51, 135, 192, 192, 135, 192, 192, 1, 51, 16,
  125, 135, 196, 196, 1, 24, 47, 93, 18, 57, 47, 93, 93, 93, 93, 93, 93, 93, 93,
  93, 113, 225, 93, 93, 16, 225, 50, 49, 48, 1, 1, 35, 3, 35, 17, 35, 17, 35, 3,
  35, 19, 35, 17, 35, 17, 51, 17, 33, 19, 22, 14, 2, 7, 51, 46, 3, 39, 35, 3,
  158, 1, 108, 168, 155, 58, 161, 58, 158, 165, 163, 245, 162, 162, 1, 39, 151,
  92, 21, 26, 27, 12, 183, 12, 28, 26, 21, 4, 2, 4, 74, 251, 182, 1, 233, 254,
  23, 1, 233, 254, 23, 1, 233, 254, 23, 4, 74, 254, 57, 1, 199, 144, 86, 96, 94,
  35, 35, 94, 96, 86, 25, 0, 0, 2, 0, 0, 0, 0, 4, 205, 5, 182, 0, 35, 0, 38, 0,
  83, 64, 44, 36, 11, 26, 251, 6, 74, 27, 90, 27, 2, 22, 27, 1, 27, 27, 40, 0,
  37, 10, 10, 18, 40, 38, 7, 7, 35, 39, 0, 25, 29, 97, 36, 11, 6, 6, 0, 38, 95,
  8, 3, 27, 18, 0, 18, 0, 63, 50, 50, 63, 225, 18, 57, 47, 51, 51, 225, 50, 1,
  47, 17, 51, 51, 47, 51, 17, 51, 51, 47, 51, 17, 18, 57, 47, 93, 93, 51, 225,
  50, 57, 48, 49, 49, 19, 62, 3, 55, 1, 53, 33, 21, 1, 30, 3, 23, 19, 35, 3, 46,
  3, 35, 35, 17, 35, 17, 35, 34, 14, 2, 7, 3, 1, 1, 33, 113, 21, 49, 76, 114,
  86, 254, 178, 3, 213, 254, 178, 89, 113, 74, 47, 21, 113, 170, 113, 18, 34,
  49, 70, 54, 23, 168, 22, 54, 70, 49, 34, 18, 113, 1, 192, 1, 37, 253, 181, 1,
  197, 85, 136, 98, 58, 6, 1, 231, 139, 139, 254, 25, 6, 56, 98, 137, 86, 254,
  59, 1, 193, 72, 95, 57, 23, 253, 72, 2, 184, 23, 57, 95, 72, 254, 63, 3, 96,
  1, 178, 0, 0, 2, 0, 10, 0, 0, 4, 195, 4, 74, 0, 35, 0, 38, 0, 117, 64, 68, 36,
  102, 11, 1, 11, 26, 73, 6, 183, 27, 1, 165, 27, 1, 148, 27, 1, 139, 27, 1,
  122, 27, 1, 89, 27, 1, 75, 27, 1, 27, 27, 39, 17, 38, 0, 7, 1, 7, 7, 35, 39,
  37, 15, 10, 1, 10, 10, 17, 10, 7, 7, 8, 25, 28, 82, 36, 11, 6, 6, 0, 38, 80,
  8, 15, 27, 18, 0, 21, 0, 63, 50, 50, 63, 225, 18, 57, 47, 51, 51, 225, 50, 17,
  51, 17, 51, 1, 47, 51, 47, 93, 51, 17, 51, 51, 47, 93, 51, 17, 18, 57, 47, 93,
  93, 93, 93, 93, 93, 93, 51, 225, 50, 93, 57, 48, 49, 51, 19, 62, 3, 55, 1, 53,
  33, 21, 1, 30, 3, 23, 19, 35, 3, 46, 3, 35, 35, 17, 35, 17, 35, 34, 14, 2, 7,
  3, 1, 19, 33, 10, 119, 21, 42, 66, 100, 80, 254, 215, 3, 181, 254, 210, 80,
  100, 66, 44, 22, 119, 181, 118, 20, 36, 47, 66, 51, 4, 164, 4, 51, 66, 48, 36,
  20, 119, 1, 168, 246, 254, 25, 1, 84, 61, 101, 77, 49, 9, 1, 100, 105, 105,
  254, 156, 8, 49, 76, 102, 62, 254, 172, 1, 80, 54, 72, 43, 17, 253, 246, 2,
  10, 17, 43, 72, 54, 254, 176, 2, 131, 1, 45, 0, 0, 2, 0, 92, 0, 0, 4, 233, 5,
  182, 0, 40, 0, 43, 0, 115, 64, 64, 41, 16, 31, 251, 11, 5, 32, 1, 32, 32, 0,
  23, 251, 22, 42, 91, 15, 15, 0, 22, 1, 22, 43, 90, 12, 12, 40, 251, 4, 47, 0,
  1, 0, 0, 6, 251, 32, 7, 48, 7, 2, 7, 15, 12, 12, 13, 13, 8, 34, 30, 5, 96, 41,
  10, 10, 0, 43, 8, 3, 32, 23, 7, 0, 18, 0, 63, 50, 50, 50, 63, 192, 18, 57, 47,
  196, 237, 50, 50, 17, 51, 17, 51, 17, 51, 1, 47, 93, 225, 50, 47, 93, 51, 225,
  51, 47, 225, 47, 93, 51, 47, 225, 16, 225, 17, 57, 47, 93, 51, 225, 50, 57,
  49, 48, 33, 19, 54, 54, 55, 35, 17, 35, 17, 51, 17, 33, 3, 53, 33, 21, 1, 30,
  3, 23, 19, 35, 3, 46, 3, 35, 35, 17, 35, 17, 35, 34, 14, 2, 7, 3, 1, 19, 33,
  1, 96, 56, 9, 19, 23, 201, 166, 166, 1, 127, 246, 3, 58, 254, 254, 65, 83, 52,
  29, 10, 55, 170, 55, 9, 16, 28, 46, 38, 8, 164, 8, 39, 45, 28, 16, 9, 56, 1,
  27, 223, 254, 66, 1, 197, 81, 108, 40, 253, 86, 5, 182, 253, 148, 1, 225, 139,
  139, 254, 25, 6, 56, 97, 137, 87, 254, 59, 1, 193, 73, 95, 56, 23, 253, 72, 2,
  184, 23, 56, 95, 73, 254, 63, 3, 90, 1, 184, 0, 0, 2, 0, 123, 0, 0, 5, 10, 4,
  74, 0, 40, 0, 43, 0, 149, 64, 91, 41, 16, 31, 73, 26, 11, 1, 9, 11, 1, 11, 5,
  32, 1, 245, 32, 1, 196, 32, 1, 182, 32, 1, 117, 32, 1, 104, 32, 1, 6, 32, 1,
  32, 32, 22, 0, 42, 72, 15, 15, 23, 73, 0, 22, 1, 22, 43, 72, 96, 12, 1, 12,
  12, 40, 73, 42, 4, 1, 4, 175, 0, 1, 0, 0, 10, 6, 73, 0, 7, 16, 7, 2, 7, 30,
  34, 34, 5, 80, 41, 10, 10, 0, 43, 13, 8, 15, 32, 23, 7, 0, 21, 0, 63, 50, 50,
  50, 63, 51, 192, 18, 57, 47, 51, 241, 192, 47, 50, 1, 47, 93, 225, 50, 50, 47,
  93, 51, 93, 225, 51, 47, 93, 225, 47, 93, 225, 51, 47, 225, 17, 18, 57, 47,
  93, 93, 93, 93, 93, 93, 113, 51, 93, 93, 225, 50, 57, 49, 48, 33, 19, 54, 54,
  55, 35, 17, 35, 17, 51, 17, 33, 3, 53, 33, 21, 3, 30, 3, 23, 19, 35, 3, 46, 3,
  35, 35, 17, 35, 17, 35, 34, 14, 2, 7, 3, 1, 19, 33, 1, 115, 73, 11, 26, 17,
  213, 162, 162, 1, 129, 230, 3, 11, 238, 61, 78, 51, 32, 14, 73, 164, 73, 12,
  19, 28, 41, 33, 9, 161, 9, 33, 41, 27, 20, 12, 76, 1, 41, 193, 254, 125, 1,
  84, 50, 67, 32, 254, 23, 4, 74, 254, 57, 1, 94, 105, 105, 254, 158, 8, 49, 77,
  103, 62, 254, 172, 1, 80, 53, 71, 44, 18, 253, 246, 2, 10, 18, 44, 71, 53,
  254, 176, 2, 131, 1, 45, 0, 1, 0, 117, 254, 70, 4, 39, 6, 213, 0, 118, 0, 131,
  64, 68, 98, 71, 81, 81, 77, 89, 89, 108, 57, 91, 103, 103, 44, 91, 114, 18,
  18, 114, 120, 78, 0, 77, 1, 77, 77, 67, 68, 68, 34, 50, 50, 5, 90, 34, 90, 93,
  64, 86, 86, 78, 128, 67, 62, 97, 98, 108, 50, 97, 51, 51, 81, 71, 68, 98, 4,
  39, 96, 0, 18, 15, 10, 95, 24, 19, 29, 29, 0, 19, 0, 63, 50, 47, 51, 51, 225,
  50, 50, 16, 225, 63, 51, 51, 51, 57, 47, 225, 57, 16, 225, 50, 26, 204, 50,
  47, 26, 205, 50, 1, 47, 225, 51, 47, 17, 51, 47, 51, 51, 47, 93, 51, 16, 206,
  50, 47, 16, 225, 51, 47, 225, 50, 51, 47, 18, 57, 17, 51, 51, 48, 49, 5, 34,
  14, 2, 21, 20, 30, 2, 51, 50, 62, 2, 51, 50, 22, 23, 21, 46, 3, 35, 34, 14, 2,
  35, 34, 46, 2, 53, 52, 62, 2, 51, 50, 62, 2, 53, 52, 46, 2, 35, 35, 53, 51,
  50, 62, 2, 53, 52, 46, 2, 35, 34, 14, 2, 7, 39, 54, 54, 55, 46, 3, 39, 53, 51,
  22, 22, 23, 62, 3, 51, 50, 22, 23, 21, 38, 38, 35, 34, 14, 2, 7, 30, 3, 21,
  20, 14, 2, 7, 21, 30, 3, 21, 20, 14, 2, 2, 29, 71, 91, 52, 20, 14, 36, 61, 47,
  65, 97, 84, 81, 50, 86, 94, 25, 8, 32, 53, 78, 53, 49, 71, 74, 92, 70, 104,
  135, 80, 31, 49, 102, 157, 107, 89, 128, 81, 38, 56, 104, 144, 89, 190, 176,
  92, 142, 97, 50, 38, 68, 95, 57, 55, 97, 86, 79, 38, 92, 59, 167, 102, 24, 55,
  54, 50, 20, 121, 51, 98, 54, 26, 58, 67, 75, 42, 31, 47, 14, 11, 33, 17, 22,
  49, 48, 46, 20, 83, 125, 85, 43, 51, 91, 125, 75, 88, 137, 95, 49, 66, 132,
  195, 20, 18, 32, 41, 24, 22, 36, 26, 14, 4, 4, 4, 24, 15, 182, 7, 18, 16, 12,
  3, 3, 2, 41, 72, 96, 55, 60, 98, 70, 38, 38, 72, 106, 67, 71, 101, 63, 29,
  151, 39, 72, 101, 61, 54, 83, 58, 30, 18, 31, 45, 27, 125, 48, 75, 17, 30, 66,
  63, 57, 23, 27, 34, 97, 56, 36, 70, 56, 35, 9, 5, 119, 5, 7, 23, 41, 56, 33,
  13, 63, 92, 118, 69, 73, 120, 88, 57, 12, 6, 11, 57, 89, 119, 72, 96, 160,
  116, 64, 0, 1, 0, 143, 254, 115, 4, 8, 5, 82, 0, 110, 0, 166, 64, 96, 20, 75,
  70, 26, 136, 96, 1, 105, 96, 121, 96, 2, 58, 96, 1, 41, 96, 1, 96, 197, 10, 1,
  103, 10, 119, 10, 2, 69, 10, 85, 10, 2, 39, 10, 1, 10, 106, 106, 93, 86, 70,
  15, 4, 4, 15, 15, 49, 49, 26, 112, 64, 103, 102, 102, 92, 93, 93, 65, 79, 79,
  36, 73, 65, 7, 82, 0, 0, 103, 128, 92, 89, 78, 96, 21, 79, 80, 80, 80, 106,
  93, 10, 96, 16, 70, 78, 31, 49, 46, 41, 80, 55, 50, 60, 60, 31, 22, 0, 63, 51,
  47, 51, 51, 225, 50, 50, 16, 225, 63, 51, 51, 51, 57, 47, 225, 57, 16, 225,
  50, 26, 205, 50, 47, 225, 1, 47, 225, 51, 47, 17, 51, 47, 51, 51, 47, 51, 26,
  16, 206, 50, 47, 50, 47, 51, 47, 16, 225, 18, 57, 17, 51, 93, 93, 93, 93, 51,
  93, 93, 93, 93, 16, 225, 50, 48, 49, 1, 50, 22, 23, 21, 38, 38, 35, 34, 6, 7,
  30, 3, 21, 20, 14, 2, 7, 21, 30, 3, 21, 20, 14, 2, 35, 34, 14, 2, 21, 20, 30,
  2, 51, 50, 62, 2, 51, 50, 22, 23, 21, 46, 3, 35, 34, 14, 2, 35, 34, 46, 2, 53,
  52, 62, 2, 51, 50, 62, 2, 53, 52, 38, 35, 35, 53, 51, 50, 62, 2, 53, 52, 38,
  35, 34, 6, 7, 39, 54, 54, 55, 46, 3, 39, 53, 51, 22, 22, 23, 62, 3, 3, 125,
  22, 31, 17, 14, 22, 14, 46, 92, 42, 59, 98, 69, 38, 28, 50, 71, 43, 47, 83,
  61, 36, 55, 121, 191, 135, 74, 89, 47, 15, 15, 37, 64, 48, 54, 109, 102, 90,
  36, 72, 78, 14, 10, 36, 43, 46, 21, 34, 92, 108, 119, 60, 95, 122, 69, 26, 35,
  85, 145, 110, 81, 125, 85, 45, 154, 159, 148, 121, 59, 111, 86, 53, 129, 121,
  79, 147, 83, 63, 62, 118, 70, 21, 47, 48, 45, 20, 121, 54, 101, 56, 28, 61,
  71, 83, 5, 82, 4, 6, 117, 3, 3, 75, 62, 12, 46, 68, 92, 59, 50, 78, 59, 41,
  13, 11, 13, 43, 66, 92, 62, 67, 117, 86, 49, 14, 26, 38, 23, 22, 35, 24, 13,
  3, 4, 3, 22, 19, 151, 10, 15, 10, 6, 3, 3, 3, 43, 69, 87, 45, 51, 90, 67, 40,
  19, 43, 69, 51, 94, 91, 153, 11, 35, 66, 54, 77, 77, 38, 34, 147, 28, 34, 8,
  28, 57, 56, 51, 21, 27, 35, 96, 56, 34, 70, 57, 36, 255, 255, 0, 57, 0, 0, 4,
  150, 5, 182, 2, 6, 1, 117, 0, 0, 255, 255, 0, 80, 254, 20, 4, 131, 6, 18, 2,
  6, 1, 149, 0, 0, 0, 3, 0, 84, 255, 236, 4, 123, 5, 205, 0, 19, 0, 30, 0, 41,
  0, 43, 64, 22, 25, 37, 91, 0, 43, 36, 26, 91, 10, 26, 96, 36, 36, 20, 31, 95,
  15, 4, 20, 95, 5, 19, 0, 63, 225, 63, 225, 18, 57, 47, 225, 1, 47, 225, 50,
  16, 222, 225, 50, 48, 49, 1, 20, 2, 6, 6, 35, 34, 38, 38, 2, 53, 52, 18, 54,
  54, 51, 50, 22, 22, 18, 1, 50, 62, 2, 55, 33, 30, 3, 19, 34, 14, 2, 7, 33, 46,
  3, 4, 123, 64, 132, 200, 135, 142, 201, 129, 60, 60, 129, 203, 142, 135, 199,
  131, 64, 253, 237, 87, 123, 79, 39, 4, 253, 103, 4, 40, 80, 123, 88, 85, 122,
  81, 42, 5, 2, 153, 5, 42, 79, 120, 2, 221, 169, 254, 234, 198, 108, 108, 198,
  1, 23, 170, 170, 1, 21, 196, 107, 107, 197, 254, 235, 253, 7, 71, 134, 194,
  122, 122, 194, 134, 71, 4, 154, 67, 128, 184, 117, 117, 184, 128, 67, 0, 0, 3,
  0, 115, 255, 236, 4, 88, 4, 94, 0, 19, 0, 25, 0, 30, 0, 43, 64, 22, 29, 22,
  72, 0, 32, 28, 23, 72, 10, 23, 80, 28, 28, 20, 26, 80, 15, 16, 20, 80, 5, 22,
  0, 63, 225, 63, 225, 18, 57, 47, 225, 1, 47, 225, 50, 16, 222, 225, 50, 48,
  49, 1, 20, 14, 2, 35, 34, 46, 2, 53, 52, 62, 2, 51, 50, 30, 2, 1, 32, 19, 33,
  22, 22, 19, 32, 3, 33, 2, 4, 88, 74, 133, 184, 111, 103, 180, 134, 78, 73,
  132, 185, 111, 103, 181, 134, 78, 254, 14, 1, 26, 26, 253, 151, 11, 156, 140,
  254, 239, 32, 2, 101, 35, 2, 39, 137, 213, 145, 76, 76, 145, 213, 137, 136,
  211, 145, 75, 75, 145, 211, 253, 212, 1, 100, 179, 177, 3, 68, 254, 186, 1,
  70, 0, 0, 1, 0, 63, 0, 0, 5, 33, 5, 195, 0, 28, 0, 79, 64, 47, 26, 26, 5, 25,
  6, 55, 6, 1, 38, 6, 1, 6, 24, 7, 56, 7, 2, 7, 13, 17, 13, 8, 0, 25, 48, 25,
  80, 25, 96, 25, 4, 25, 9, 8, 26, 0, 97, 25, 22, 4, 8, 3, 13, 7, 18, 6, 18, 0,
  63, 63, 51, 63, 63, 51, 225, 50, 1, 47, 51, 47, 93, 18, 57, 57, 17, 51, 93,
  51, 93, 93, 17, 18, 57, 50, 47, 48, 49, 1, 34, 14, 2, 7, 1, 35, 1, 51, 1, 22,
  22, 23, 54, 54, 55, 19, 62, 3, 51, 50, 22, 23, 21, 38, 38, 4, 180, 35, 53, 42,
  36, 18, 254, 215, 209, 254, 61, 197, 1, 10, 26, 45, 17, 14, 42, 26, 142, 32,
  60, 76, 103, 75, 35, 68, 26, 23, 54, 5, 45, 37, 72, 103, 66, 251, 233, 5, 182,
  252, 109, 93, 185, 79, 78, 188, 97, 2, 0, 113, 156, 98, 43, 13, 8, 151, 9, 13,
  0, 1, 0, 82, 0, 0, 4, 174, 4, 82, 0, 35, 0, 80, 64, 51, 33, 24, 34, 102, 34,
  118, 34, 2, 23, 34, 55, 34, 71, 34, 87, 34, 4, 34, 24, 35, 40, 35, 56, 35, 3,
  35, 9, 16, 9, 0, 47, 24, 1, 24, 1, 64, 0, 80, 0, 2, 0, 34, 9, 35, 21, 28, 79,
  21, 15, 0, 15, 0, 63, 63, 225, 63, 51, 51, 1, 47, 93, 51, 47, 93, 18, 57, 57,
  17, 51, 93, 51, 93, 93, 17, 18, 57, 48, 49, 19, 51, 19, 30, 5, 23, 51, 62, 3,
  55, 19, 62, 3, 51, 50, 22, 23, 21, 38, 38, 35, 34, 14, 2, 7, 1, 35, 82, 188,
  224, 8, 21, 24, 24, 20, 16, 3, 6, 7, 25, 30, 31, 12, 102, 30, 53, 65, 83, 60,
  26, 44, 14, 11, 32, 18, 26, 40, 32, 29, 15, 254, 246, 231, 4, 74, 253, 162,
  22, 63, 70, 74, 67, 57, 18, 30, 93, 103, 101, 37, 1, 64, 93, 117, 67, 24, 7,
  3, 135, 3, 5, 19, 40, 65, 46, 252, 225, 255, 255, 0, 63, 0, 0, 5, 33, 7, 115,
  2, 38, 2, 128, 0, 0, 1, 7, 3, 118, 255, 224, 1, 82, 0, 25, 182, 2, 1, 29, 5,
  38, 2, 1, 184, 255, 109, 180, 49, 29, 8, 25, 37, 1, 43, 53, 53, 0, 43, 53, 53,
  0, 255, 255, 0, 82, 0, 0, 4, 174, 6, 33, 2, 38, 2, 129, 0, 0, 1, 6, 3, 118,
  212, 0, 0, 25, 182, 2, 1, 36, 17, 38, 2, 1, 184, 255, 145, 180, 56, 36, 0, 24,
  37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 0, 3, 0, 70, 254, 20, 4, 215, 5, 205, 0,
  19, 0, 39, 0, 72, 0, 111, 64, 68, 136, 72, 152, 72, 2, 72, 16, 11, 16, 72, 72,
  47, 40, 55, 65, 65, 39, 41, 1, 6, 41, 1, 41, 250, 6, 40, 1, 40, 40, 30, 250,
  15, 0, 1, 0, 0, 10, 40, 54, 1, 9, 54, 1, 54, 250, 240, 55, 1, 55, 20, 250, 10,
  72, 47, 73, 68, 61, 28, 54, 40, 15, 35, 95, 15, 4, 25, 5, 19, 0, 63, 193, 63,
  225, 63, 51, 63, 205, 17, 51, 51, 1, 47, 225, 47, 93, 225, 93, 93, 18, 57, 47,
  93, 225, 51, 47, 93, 225, 93, 93, 51, 47, 17, 18, 57, 57, 43, 93, 49, 48, 1,
  20, 2, 6, 6, 35, 34, 38, 38, 2, 53, 52, 18, 54, 54, 51, 50, 22, 22, 18, 5, 20,
  30, 2, 51, 50, 62, 2, 53, 52, 46, 2, 35, 34, 14, 2, 37, 51, 19, 30, 3, 23, 51,
  62, 3, 55, 19, 51, 3, 14, 3, 35, 34, 38, 39, 53, 22, 22, 51, 50, 54, 55, 55,
  2, 106, 16, 56, 109, 93, 93, 109, 56, 16, 16, 57, 109, 94, 93, 108, 56, 15,
  254, 121, 10, 26, 46, 35, 36, 46, 25, 10, 9, 26, 45, 35, 36, 46, 27, 10, 1,
  176, 156, 100, 4, 9, 9, 8, 3, 4, 2, 5, 7, 7, 4, 106, 156, 242, 15, 41, 62, 88,
  62, 37, 48, 21, 20, 47, 25, 49, 63, 19, 24, 2, 221, 182, 254, 231, 191, 99,
  98, 192, 1, 26, 183, 177, 1, 23, 193, 101, 101, 193, 254, 232, 178, 137, 219,
  153, 81, 81, 153, 219, 137, 138, 218, 151, 81, 81, 151, 218, 227, 253, 159,
  23, 56, 61, 63, 30, 25, 62, 64, 60, 22, 2, 97, 251, 14, 78, 120, 83, 43, 11,
  6, 145, 5, 7, 87, 99, 136, 0, 0, 3, 0, 80, 254, 20, 4, 205, 4, 94, 0, 19, 0,
  29, 0, 62, 0, 151, 64, 100, 88, 62, 104, 62, 2, 57, 62, 73, 62, 2, 40, 62, 1,
  37, 62, 45, 21, 31, 1, 31, 73, 30, 0, 30, 1, 30, 0, 0, 54, 1, 54, 54, 137, 25,
  1, 88, 25, 104, 25, 120, 25, 3, 25, 73, 89, 0, 1, 15, 0, 1, 0, 0, 10, 88, 44,
  1, 73, 44, 1, 56, 44, 1, 25, 44, 1, 8, 44, 1, 44, 73, 45, 133, 20, 1, 102, 20,
  118, 20, 2, 20, 73, 10, 37, 62, 30, 58, 80, 51, 27, 44, 30, 15, 28, 80, 15,
  16, 23, 80, 5, 22, 0, 63, 225, 63, 225, 63, 51, 63, 225, 17, 57, 57, 1, 47,
  225, 93, 93, 47, 225, 93, 93, 93, 93, 93, 18, 57, 47, 93, 93, 225, 93, 93, 51,
  47, 93, 17, 51, 93, 16, 225, 93, 18, 57, 57, 93, 93, 93, 48, 49, 1, 20, 14, 2,
  35, 34, 46, 2, 53, 52, 62, 2, 51, 50, 30, 2, 5, 20, 22, 51, 50, 17, 52, 38,
  35, 34, 37, 51, 19, 30, 3, 23, 51, 62, 3, 55, 19, 51, 3, 14, 3, 35, 34, 38,
  39, 53, 22, 22, 51, 50, 54, 55, 55, 2, 115, 38, 71, 102, 64, 61, 100, 72, 39,
  40, 73, 101, 60, 57, 100, 73, 43, 254, 123, 59, 57, 117, 60, 57, 116, 1, 155,
  156, 100, 4, 9, 9, 8, 3, 4, 2, 5, 6, 8, 4, 106, 156, 242, 15, 41, 62, 88, 62,
  37, 48, 22, 20, 48, 25, 49, 63, 19, 24, 2, 39, 168, 221, 130, 52, 52, 130,
  221, 168, 168, 219, 129, 51, 51, 129, 219, 168, 211, 209, 1, 164, 210, 206,
  131, 253, 159, 23, 56, 61, 63, 30, 25, 62, 64, 60, 22, 2, 97, 251, 14, 78,
  120, 83, 43, 11, 6, 145, 5, 7, 87, 99, 136, 0, 2, 0, 84, 255, 139, 4, 123, 6,
  41, 0, 31, 0, 63, 0, 94, 64, 53, 37, 11, 11, 59, 21, 43, 5, 5, 53, 27, 21, 27,
  16, 48, 91, 0, 65, 32, 91, 31, 16, 47, 16, 2, 16, 59, 79, 56, 95, 56, 2, 56,
  56, 53, 95, 24, 21, 27, 3, 43, 64, 40, 80, 40, 2, 40, 40, 37, 95, 8, 5, 11,
  18, 0, 63, 51, 205, 225, 50, 47, 93, 50, 63, 51, 205, 225, 50, 47, 93, 50, 1,
  47, 93, 225, 16, 222, 225, 18, 57, 57, 17, 51, 51, 17, 51, 17, 51, 51, 17, 51,
  48, 49, 1, 20, 14, 2, 7, 6, 6, 35, 34, 38, 39, 46, 3, 53, 52, 62, 2, 55, 54,
  54, 51, 50, 22, 23, 30, 3, 5, 20, 30, 2, 23, 54, 54, 51, 50, 22, 23, 62, 3,
  53, 52, 46, 2, 39, 6, 6, 35, 34, 38, 39, 14, 3, 4, 123, 48, 97, 147, 99, 14,
  74, 54, 58, 71, 14, 103, 146, 94, 44, 44, 94, 146, 103, 14, 71, 58, 54, 74,
  14, 99, 147, 97, 48, 252, 158, 22, 47, 75, 54, 17, 67, 51, 48, 69, 17, 55, 77,
  48, 22, 22, 48, 77, 55, 16, 70, 48, 52, 68, 17, 53, 74, 47, 22, 2, 221, 146,
  247, 190, 126, 26, 62, 53, 53, 62, 26, 126, 190, 248, 147, 146, 246, 189, 125,
  25, 62, 49, 50, 59, 26, 126, 189, 247, 147, 108, 182, 142, 101, 28, 45, 37,
  39, 45, 26, 100, 143, 184, 110, 110, 183, 143, 99, 26, 48, 40, 38, 46, 27,
  101, 141, 180, 0, 0, 2, 0, 115, 255, 152, 4, 88, 4, 174, 0, 33, 0, 54, 0, 88,
  64, 47, 36, 11, 11, 53, 21, 42, 5, 5, 47, 29, 21, 29, 16, 44, 72, 0, 56, 34,
  72, 0, 16, 1, 16, 53, 95, 50, 1, 50, 50, 47, 81, 24, 21, 29, 15, 80, 39, 1,
  39, 39, 36, 42, 81, 11, 8, 5, 21, 0, 63, 205, 51, 225, 50, 50, 47, 93, 63, 51,
  205, 225, 50, 47, 93, 50, 1, 47, 93, 225, 16, 222, 225, 18, 57, 57, 17, 51,
  51, 17, 51, 17, 51, 51, 17, 51, 48, 49, 1, 20, 14, 2, 7, 6, 6, 35, 34, 38, 39,
  46, 3, 53, 52, 62, 2, 55, 54, 54, 51, 50, 30, 2, 23, 30, 3, 5, 16, 23, 54, 54,
  51, 50, 22, 23, 54, 17, 52, 38, 39, 6, 6, 35, 34, 38, 39, 6, 4, 88, 54, 98,
  139, 86, 9, 60, 54, 58, 59, 8, 81, 136, 99, 56, 53, 97, 138, 84, 10, 58, 57,
  27, 42, 30, 20, 4, 81, 139, 100, 57, 252, 215, 191, 11, 56, 51, 48, 57, 12,
  195, 99, 96, 12, 57, 48, 51, 55, 12, 191, 2, 39, 117, 188, 141, 92, 19, 54,
  44, 44, 54, 20, 92, 141, 188, 116, 115, 187, 141, 91, 19, 54, 40, 9, 21, 36,
  28, 19, 91, 141, 187, 115, 254, 184, 71, 38, 29, 31, 38, 71, 1, 74, 165, 197,
  35, 42, 29, 31, 40, 71, 0, 0, 3, 0, 82, 255, 236, 4, 123, 8, 61, 0, 21, 0, 39,
  0, 102, 0, 180, 64, 107, 53, 15, 54, 63, 54, 79, 54, 95, 54, 127, 54, 143, 54,
  6, 54, 54, 48, 251, 60, 40, 70, 29, 22, 34, 25, 11, 12, 70, 34, 1, 34, 12, 12,
  34, 1, 3, 80, 60, 104, 87, 0, 86, 48, 86, 64, 86, 80, 86, 112, 86, 128, 86, 6,
  86, 86, 92, 251, 80, 53, 87, 87, 51, 89, 95, 83, 54, 86, 86, 83, 29, 37, 26,
  26, 79, 25, 95, 25, 111, 25, 3, 25, 83, 37, 37, 2, 7, 16, 16, 11, 0, 79, 2, 1,
  2, 2, 57, 83, 4, 102, 102, 43, 97, 95, 70, 65, 75, 19, 0, 63, 51, 51, 225, 50,
  50, 47, 63, 51, 51, 47, 93, 51, 51, 51, 47, 51, 17, 51, 47, 16, 198, 93, 50,
  47, 18, 57, 17, 51, 17, 51, 16, 225, 50, 50, 17, 51, 1, 47, 225, 50, 47, 93,
  51, 16, 206, 17, 23, 57, 47, 47, 47, 18, 57, 17, 51, 50, 16, 221, 205, 17, 51,
  16, 225, 50, 47, 93, 51, 49, 48, 1, 21, 35, 34, 46, 2, 35, 34, 6, 21, 21, 35,
  53, 52, 54, 51, 50, 30, 2, 51, 7, 20, 6, 7, 53, 54, 54, 53, 52, 46, 2, 53, 52,
  54, 51, 50, 22, 3, 22, 22, 51, 50, 62, 2, 53, 16, 2, 35, 34, 7, 39, 54, 54,
  51, 50, 18, 17, 20, 2, 6, 6, 35, 34, 46, 2, 39, 14, 3, 35, 34, 38, 38, 2, 53,
  16, 18, 51, 50, 22, 23, 7, 38, 35, 34, 2, 17, 20, 30, 2, 51, 50, 62, 2, 55, 3,
  221, 14, 80, 135, 114, 94, 38, 43, 55, 133, 118, 103, 54, 106, 112, 125, 74,
  232, 119, 122, 60, 56, 31, 36, 31, 50, 46, 59, 68, 125, 36, 90, 51, 48, 67,
  42, 19, 78, 66, 55, 41, 47, 34, 88, 48, 146, 147, 34, 78, 128, 94, 33, 54, 46,
  43, 23, 22, 42, 46, 53, 33, 94, 128, 79, 35, 147, 146, 48, 88, 34, 47, 41, 56,
  66, 77, 19, 43, 68, 48, 27, 45, 41, 40, 21, 7, 203, 129, 36, 42, 36, 45, 53,
  16, 35, 107, 101, 36, 42, 36, 226, 77, 115, 31, 76, 22, 45, 25, 19, 18, 16,
  26, 28, 37, 38, 70, 249, 232, 57, 66, 89, 164, 229, 141, 1, 19, 1, 20, 29,
  152, 23, 18, 254, 153, 254, 154, 192, 254, 219, 198, 101, 9, 20, 33, 24, 24,
  33, 20, 9, 101, 198, 1, 37, 192, 1, 102, 1, 103, 18, 23, 152, 29, 254, 236,
  254, 237, 141, 229, 164, 89, 17, 32, 46, 28, 0, 3, 0, 88, 255, 236, 4, 115, 7,
  8, 0, 59, 0, 81, 0, 98, 0, 156, 64, 41, 15, 47, 191, 47, 255, 47, 3, 47, 64,
  11, 17, 72, 47, 47, 41, 73, 33, 3, 11, 55, 100, 70, 73, 88, 82, 93, 93, 85,
  85, 61, 61, 72, 11, 0, 19, 176, 19, 240, 19, 3, 19, 184, 255, 192, 64, 45, 11,
  17, 72, 19, 19, 25, 73, 11, 88, 96, 86, 85, 96, 96, 72, 67, 76, 60, 61, 61,
  15, 72, 1, 72, 72, 85, 46, 44, 44, 20, 22, 81, 50, 47, 19, 16, 16, 38, 33, 28,
  81, 3, 0, 6, 22, 0, 63, 51, 51, 225, 50, 50, 63, 51, 51, 51, 225, 50, 50, 17,
  51, 206, 50, 47, 93, 51, 47, 51, 205, 50, 17, 51, 47, 16, 205, 17, 57, 1, 47,
  225, 50, 47, 43, 93, 16, 196, 50, 47, 50, 47, 51, 47, 221, 201, 47, 51, 16,
  222, 17, 57, 57, 225, 50, 47, 43, 93, 49, 48, 5, 34, 38, 39, 6, 6, 35, 34, 46,
  2, 53, 52, 62, 2, 51, 50, 22, 23, 7, 38, 35, 34, 6, 21, 20, 22, 51, 50, 62, 2,
  55, 30, 3, 51, 50, 54, 53, 52, 38, 35, 34, 7, 39, 54, 54, 51, 50, 30, 2, 21,
  20, 14, 2, 19, 21, 35, 34, 46, 2, 35, 34, 6, 21, 21, 35, 53, 52, 54, 51, 50,
  30, 2, 51, 7, 20, 6, 7, 53, 54, 53, 52, 46, 2, 53, 52, 54, 51, 50, 22, 3, 29,
  62, 91, 32, 32, 88, 60, 76, 127, 91, 50, 40, 76, 109, 68, 46, 95, 35, 51, 49,
  62, 73, 68, 102, 95, 26, 46, 40, 34, 15, 16, 35, 40, 47, 28, 94, 101, 68, 74,
  58, 50, 51, 35, 94, 45, 70, 109, 75, 39, 51, 90, 126, 105, 8, 80, 129, 110,
  96, 46, 43, 55, 134, 118, 104, 62, 108, 108, 119, 74, 232, 120, 121, 116, 31,
  36, 31, 50, 46, 59, 68, 20, 35, 32, 32, 35, 60, 133, 215, 155, 157, 219, 137,
  62, 20, 25, 145, 30, 201, 212, 211, 195, 14, 24, 30, 16, 16, 30, 24, 14, 195,
  211, 212, 201, 30, 145, 25, 20, 62, 137, 219, 157, 150, 213, 137, 63, 6, 170,
  130, 36, 43, 36, 46, 52, 17, 23, 108, 113, 36, 42, 36, 226, 77, 115, 31, 76,
  41, 51, 19, 18, 16, 26, 27, 38, 38, 70, 0, 0, 2, 0, 82, 255, 236, 4, 123, 7,
  4, 0, 13, 0, 74, 0, 173, 64, 100, 27, 27, 14, 251, 72, 0, 59, 32, 59, 2, 59,
  59, 5, 72, 1, 197, 72, 213, 72, 2, 6, 72, 150, 72, 166, 72, 3, 72, 72, 53, 21,
  251, 4, 2, 3, 5, 6, 6, 8, 7, 9, 10, 10, 11, 11, 7, 3, 3, 12, 15, 1, 31, 1, 2,
  1, 33, 76, 0, 12, 16, 12, 2, 12, 65, 251, 53, 73, 73, 56, 70, 26, 60, 60, 24,
  62, 95, 56, 27, 59, 59, 56, 13, 5, 9, 7, 3, 11, 30, 56, 4, 14, 72, 72, 16, 70,
  95, 43, 38, 48, 19, 0, 63, 51, 51, 225, 50, 50, 17, 51, 63, 51, 222, 50, 50,
  221, 50, 205, 17, 51, 17, 51, 16, 225, 50, 50, 17, 51, 17, 18, 57, 47, 1, 47,
  225, 196, 93, 16, 222, 196, 93, 17, 23, 57, 17, 51, 17, 51, 17, 51, 51, 17,
  51, 17, 51, 51, 225, 17, 57, 47, 93, 93, 113, 51, 47, 93, 16, 225, 50, 47, 49,
  48, 1, 21, 7, 35, 39, 35, 7, 35, 39, 35, 7, 35, 39, 53, 1, 22, 51, 50, 62, 2,
  53, 16, 2, 35, 34, 7, 39, 54, 54, 51, 50, 18, 17, 20, 2, 6, 6, 35, 34, 46, 2,
  39, 14, 3, 35, 34, 38, 38, 2, 53, 16, 18, 51, 50, 22, 23, 7, 38, 35, 34, 2,
  17, 20, 30, 2, 51, 50, 55, 17, 51, 3, 221, 82, 35, 49, 143, 49, 35, 49, 144,
  49, 35, 79, 1, 204, 39, 56, 48, 67, 42, 19, 78, 66, 55, 41, 47, 34, 88, 48,
  146, 147, 34, 78, 128, 94, 33, 54, 46, 43, 23, 22, 42, 46, 53, 33, 94, 128,
  79, 35, 147, 146, 48, 88, 34, 47, 41, 56, 66, 77, 19, 43, 68, 48, 57, 37, 170,
  7, 4, 27, 172, 103, 103, 103, 103, 172, 27, 249, 182, 43, 89, 164, 229, 141,
  1, 19, 1, 20, 29, 152, 23, 18, 254, 153, 254, 154, 192, 254, 219, 198, 101,
  13, 24, 37, 24, 24, 37, 24, 13, 101, 198, 1, 37, 192, 1, 102, 1, 103, 18, 23,
  152, 29, 254, 236, 254, 237, 141, 229, 164, 89, 43, 1, 220, 0, 0, 2, 255, 252,
  0, 0, 4, 137, 5, 164, 0, 13, 0, 56, 0, 204, 64, 25, 22, 47, 1, 47, 35, 48, 29,
  73, 6, 56, 22, 56, 2, 22, 56, 38, 56, 70, 56, 86, 56, 214, 56, 5, 56, 184,
  255, 240, 64, 102, 17, 20, 72, 56, 20, 14, 8, 48, 1, 152, 48, 184, 48, 216,
  48, 232, 48, 4, 25, 48, 41, 48, 73, 48, 89, 48, 105, 48, 5, 27, 52, 48, 3, 41,
  14, 15, 40, 28, 56, 28, 2, 10, 28, 1, 28, 28, 15, 41, 73, 4, 2, 3, 5, 6, 6, 8,
  7, 9, 10, 10, 11, 11, 7, 3, 3, 12, 15, 1, 1, 1, 42, 58, 0, 12, 80, 12, 2, 12,
  16, 73, 15, 35, 48, 21, 52, 27, 27, 15, 14, 13, 5, 9, 7, 3, 11, 41, 28, 15,
  15, 20, 14, 21, 0, 63, 51, 63, 51, 51, 222, 50, 50, 221, 50, 205, 17, 18, 57,
  17, 51, 63, 51, 1, 47, 225, 198, 93, 16, 222, 198, 93, 17, 23, 57, 17, 51, 17,
  51, 17, 51, 51, 17, 51, 17, 51, 51, 237, 17, 57, 47, 93, 93, 18, 57, 18, 23,
  57, 93, 93, 113, 17, 51, 51, 43, 93, 113, 225, 17, 51, 51, 93, 48, 49, 1, 21,
  7, 35, 39, 35, 7, 35, 39, 35, 7, 35, 39, 53, 19, 1, 51, 19, 22, 22, 23, 51,
  62, 3, 55, 19, 3, 51, 19, 30, 3, 23, 51, 62, 2, 18, 53, 51, 20, 2, 2, 6, 7,
  35, 3, 38, 38, 39, 6, 6, 7, 3, 3, 207, 82, 35, 49, 143, 50, 34, 50, 143, 49,
  35, 80, 58, 254, 225, 160, 163, 20, 34, 8, 4, 5, 15, 18, 20, 10, 86, 109, 150,
  137, 8, 22, 23, 22, 7, 6, 63, 79, 45, 16, 153, 26, 66, 113, 88, 163, 84, 7,
  11, 3, 5, 16, 8, 106, 5, 164, 27, 172, 103, 103, 103, 103, 172, 27, 250, 92,
  4, 74, 253, 92, 85, 157, 51, 18, 56, 65, 67, 30, 1, 16, 1, 205, 253, 176, 33,
  96, 103, 96, 33, 104, 210, 230, 1, 2, 151, 163, 254, 224, 254, 245, 253, 127,
  1, 84, 26, 56, 20, 20, 62, 22, 254, 174, 0, 0, 1, 0, 129, 254, 20, 4, 156, 5,
  203, 0, 35, 0, 52, 64, 27, 16, 90, 17, 17, 24, 33, 32, 32, 37, 5, 91, 0, 24,
  1, 24, 33, 0, 95, 32, 29, 4, 15, 10, 95, 19, 19, 16, 0, 47, 63, 225, 50, 63,
  51, 225, 50, 1, 47, 93, 225, 17, 51, 47, 51, 18, 57, 47, 225, 48, 49, 1, 34,
  14, 2, 21, 20, 30, 2, 51, 50, 62, 2, 55, 17, 35, 17, 35, 34, 38, 38, 2, 53,
  52, 18, 54, 54, 51, 50, 22, 23, 7, 38, 38, 3, 29, 107, 174, 123, 67, 59, 118,
  176, 118, 29, 45, 40, 37, 21, 187, 16, 164, 240, 157, 76, 87, 170, 249, 162,
  108, 196, 79, 78, 63, 148, 5, 39, 81, 152, 218, 137, 141, 219, 150, 78, 4, 9,
  13, 9, 253, 98, 1, 216, 108, 198, 1, 22, 169, 166, 1, 20, 198, 110, 44, 42,
  156, 32, 46, 0, 0, 1, 0, 172, 254, 20, 4, 37, 4, 94, 0, 31, 0, 53, 64, 28, 29,
  71, 30, 30, 5, 14, 13, 13, 33, 20, 72, 0, 5, 1, 5, 29, 27, 14, 17, 81, 13, 10,
  16, 28, 25, 81, 0, 22, 0, 63, 225, 50, 63, 51, 225, 50, 63, 1, 47, 93, 225,
  17, 51, 47, 51, 18, 57, 47, 225, 48, 49, 5, 34, 46, 2, 53, 52, 62, 2, 51, 50,
  22, 23, 7, 38, 38, 35, 34, 6, 21, 20, 30, 2, 51, 50, 54, 55, 17, 35, 17, 2,
  197, 113, 196, 145, 83, 84, 149, 206, 122, 90, 172, 66, 62, 58, 131, 79, 190,
  181, 49, 94, 135, 87, 53, 85, 34, 182, 20, 63, 137, 213, 150, 157, 219, 137,
  62, 34, 25, 158, 22, 35, 204, 209, 105, 154, 99, 48, 19, 14, 253, 104, 1, 216,
  0, 0, 1, 0, 94, 255, 250, 4, 111, 5, 10, 0, 19, 0, 168, 64, 75, 6, 9, 10, 13,
  4, 14, 5, 14, 3, 0, 19, 16, 4, 4, 15, 15, 2, 63, 1, 79, 1, 95, 1, 175, 1, 4,
  1, 1, 18, 17, 21, 12, 48, 11, 64, 11, 80, 11, 160, 11, 4, 11, 11, 7, 4, 5, 5,
  8, 7, 13, 16, 12, 17, 10, 19, 11, 18, 11, 12, 6, 3, 7, 2, 7, 9, 0, 1, 8, 8,
  12, 64, 21, 26, 72, 12, 184, 255, 192, 64, 9, 12, 12, 15, 14, 17, 18, 18, 1,
  2, 184, 255, 192, 182, 21, 26, 72, 2, 2, 5, 4, 0, 47, 51, 51, 47, 43, 51, 51,
  47, 51, 47, 51, 51, 47, 56, 43, 51, 47, 18, 57, 57, 51, 17, 18, 57, 57, 17,
  51, 17, 18, 57, 57, 17, 18, 57, 57, 1, 47, 51, 51, 47, 51, 17, 51, 47, 93, 51,
  16, 206, 50, 50, 47, 93, 51, 50, 47, 18, 23, 57, 51, 17, 18, 23, 57, 48, 49,
  1, 5, 7, 37, 3, 39, 19, 37, 55, 5, 19, 37, 55, 5, 19, 23, 3, 5, 7, 37, 2, 66,
  1, 28, 71, 254, 227, 180, 129, 180, 254, 229, 70, 1, 31, 198, 254, 228, 71, 1,
  29, 182, 127, 182, 1, 31, 74, 254, 229, 1, 176, 166, 123, 164, 254, 199, 74,
  1, 59, 164, 123, 164, 1, 90, 164, 125, 164, 1, 57, 73, 254, 196, 164, 123,
  164, 0, 0, 1, 0, 242, 4, 143, 3, 217, 5, 184, 0, 21, 0, 23, 64, 9, 4, 10, 16,
  0, 19, 15, 141, 4, 7, 0, 47, 221, 253, 204, 1, 47, 51, 47, 51, 48, 49, 1, 20,
  6, 35, 33, 6, 6, 35, 34, 38, 53, 52, 62, 2, 51, 33, 54, 54, 51, 50, 22, 3,
  217, 43, 57, 254, 63, 6, 44, 48, 56, 40, 9, 23, 38, 28, 1, 192, 5, 46, 48, 56,
  42, 5, 80, 57, 41, 44, 51, 51, 56, 28, 37, 22, 9, 45, 49, 50, 0, 0, 1, 0, 242,
  4, 229, 3, 221, 5, 217, 0, 21, 0, 31, 64, 14, 20, 10, 132, 15, 8, 1, 8, 21,
  20, 20, 14, 5, 128, 10, 0, 47, 26, 204, 50, 51, 47, 51, 1, 47, 93, 225, 47,
  49, 48, 1, 50, 62, 2, 51, 50, 22, 21, 21, 35, 53, 52, 38, 35, 34, 14, 2, 35,
  35, 53, 1, 0, 78, 133, 119, 112, 58, 109, 124, 133, 58, 46, 42, 101, 121, 145,
  85, 16, 5, 102, 36, 43, 36, 101, 108, 35, 17, 52, 46, 36, 43, 36, 129, 0, 1,
  1, 225, 4, 215, 2, 211, 6, 53, 0, 17, 0, 35, 64, 18, 15, 64, 9, 12, 72, 15,
  11, 6, 0, 11, 3, 14, 140, 15, 127, 3, 1, 3, 0, 47, 93, 47, 225, 18, 57, 1, 47,
  205, 205, 205, 43, 48, 49, 1, 52, 54, 51, 50, 22, 21, 20, 14, 2, 21, 20, 22,
  23, 21, 38, 38, 1, 225, 68, 59, 47, 50, 31, 37, 31, 57, 60, 122, 120, 5, 182,
  57, 70, 38, 38, 27, 26, 16, 18, 19, 25, 46, 21, 76, 31, 115, 0, 1, 1, 225, 4,
  215, 2, 211, 6, 53, 0, 17, 0, 38, 178, 12, 7, 3, 184, 255, 192, 64, 14, 9, 12,
  72, 3, 0, 7, 3, 127, 15, 1, 15, 4, 140, 3, 0, 47, 225, 47, 93, 18, 57, 1, 47,
  205, 43, 205, 205, 48, 49, 1, 20, 6, 7, 53, 54, 54, 53, 52, 46, 2, 53, 52, 54,
  51, 50, 22, 2, 211, 120, 122, 60, 57, 31, 36, 31, 50, 46, 59, 68, 5, 182, 77,
  115, 31, 76, 21, 46, 25, 19, 18, 16, 26, 27, 38, 38, 70, 0, 0, 8, 0, 41, 0,
  47, 4, 164, 4, 53, 0, 13, 0, 27, 0, 41, 0, 55, 0, 69, 0, 83, 0, 99, 0, 113, 0,
  0, 1, 50, 22, 23, 35, 38, 38, 35, 34, 6, 7, 35, 54, 54, 19, 50, 22, 23, 35,
  38, 38, 35, 34, 6, 7, 35, 54, 54, 37, 50, 22, 23, 35, 38, 38, 35, 34, 6, 7,
  35, 54, 54, 33, 50, 22, 23, 35, 38, 38, 35, 34, 6, 7, 35, 54, 54, 1, 50, 22,
  23, 35, 38, 38, 35, 34, 6, 7, 35, 54, 54, 33, 50, 22, 23, 35, 38, 38, 35, 34,
  6, 7, 35, 54, 54, 1, 50, 22, 23, 35, 46, 3, 35, 34, 6, 7, 35, 54, 54, 33, 50,
  22, 23, 35, 38, 38, 35, 34, 6, 7, 35, 54, 54, 2, 96, 65, 66, 6, 69, 5, 37, 26,
  28, 32, 3, 72, 2, 67, 66, 65, 66, 6, 69, 5, 37, 26, 28, 32, 3, 72, 2, 67, 1,
  144, 62, 70, 3, 73, 4, 33, 25, 28, 30, 3, 74, 3, 67, 253, 167, 65, 69, 6, 72,
  5, 37, 26, 27, 31, 3, 70, 4, 62, 2, 219, 62, 70, 3, 73, 4, 33, 25, 28, 30, 3,
  74, 3, 67, 253, 167, 65, 69, 6, 72, 5, 37, 26, 27, 31, 3, 70, 4, 62, 3, 72,
  63, 71, 3, 74, 1, 12, 17, 22, 11, 29, 28, 3, 73, 3, 65, 252, 212, 65, 69, 3,
  73, 4, 35, 25, 26, 30, 3, 74, 3, 67, 4, 53, 77, 62, 32, 17, 15, 34, 63, 76,
  252, 131, 75, 62, 32, 17, 15, 34, 63, 74, 162, 79, 62, 34, 17, 16, 35, 63, 78,
  79, 62, 34, 17, 16, 35, 63, 78, 2, 57, 79, 62, 32, 17, 15, 34, 63, 78, 79, 62,
  32, 17, 15, 34, 63, 78, 254, 232, 78, 65, 17, 20, 11, 3, 16, 35, 66, 77, 78,
  65, 34, 17, 16, 35, 66, 77, 0, 8, 0, 41, 255, 231, 4, 164, 4, 98, 0, 8, 0, 19,
  0, 32, 0, 43, 0, 54, 0, 63, 0, 74, 0, 85, 0, 62, 64, 30, 43, 36, 13, 0, 9, 4,
  54, 26, 31, 74, 68, 53, 47, 19, 12, 26, 33, 20, 37, 85, 62, 7, 15, 79, 31, 79,
  2, 79, 58, 4, 0, 47, 198, 196, 93, 214, 198, 198, 212, 50, 205, 50, 47, 205,
  196, 196, 198, 196, 1, 47, 198, 198, 212, 50, 205, 50, 47, 205, 48, 49, 37, 6,
  6, 7, 35, 54, 54, 55, 51, 3, 54, 54, 55, 51, 14, 3, 7, 35, 1, 30, 3, 23, 21,
  46, 3, 39, 53, 5, 38, 38, 39, 53, 30, 3, 23, 21, 1, 54, 54, 55, 23, 14, 3, 7,
  39, 1, 6, 6, 7, 39, 54, 54, 55, 23, 3, 38, 38, 39, 55, 30, 3, 23, 7, 1, 22,
  22, 23, 7, 46, 3, 39, 55, 2, 184, 12, 45, 25, 79, 17, 23, 5, 100, 145, 11, 45,
  23, 84, 7, 14, 13, 10, 3, 100, 1, 164, 22, 53, 57, 58, 27, 30, 64, 62, 57, 23,
  253, 76, 46, 117, 56, 26, 63, 65, 60, 21, 2, 19, 54, 111, 44, 63, 21, 55, 56,
  52, 18, 70, 254, 127, 47, 113, 51, 64, 41, 109, 55, 72, 119, 29, 53, 18, 61,
  17, 37, 36, 32, 13, 71, 2, 80, 31, 50, 19, 59, 18, 38, 36, 33, 13, 74, 195,
  47, 119, 54, 87, 114, 35, 2, 180, 48, 117, 54, 28, 63, 62, 58, 24, 254, 254,
  6, 17, 21, 24, 12, 84, 7, 14, 14, 10, 2, 100, 145, 12, 45, 25, 82, 6, 13, 13,
  11, 2, 103, 1, 105, 31, 52, 17, 59, 14, 36, 38, 35, 14, 71, 253, 176, 24, 55,
  19, 59, 25, 74, 39, 74, 1, 221, 53, 111, 45, 63, 27, 58, 53, 47, 17, 72, 254,
  129, 53, 111, 47, 63, 27, 58, 54, 47, 18, 72, 0, 2, 0, 137, 254, 127, 5, 8, 7,
  104, 0, 27, 0, 49, 0, 92, 64, 50, 25, 26, 27, 27, 24, 23, 49, 251, 28, 28, 39,
  251, 38, 38, 9, 21, 0, 251, 23, 51, 64, 8, 12, 251, 0, 9, 224, 9, 240, 9, 3,
  9, 49, 39, 128, 44, 33, 21, 7, 11, 3, 19, 8, 18, 26, 26, 23, 95, 0, 18, 0, 63,
  225, 51, 47, 63, 51, 63, 51, 51, 222, 50, 26, 204, 50, 1, 47, 93, 225, 50, 26,
  16, 221, 225, 50, 17, 57, 47, 225, 51, 47, 225, 16, 205, 50, 16, 205, 50, 49,
  48, 33, 17, 52, 54, 55, 54, 55, 35, 1, 35, 17, 51, 17, 20, 14, 2, 7, 6, 7, 51,
  1, 51, 17, 51, 3, 35, 19, 3, 14, 3, 35, 34, 46, 2, 39, 51, 30, 3, 51, 50, 62,
  2, 55, 3, 154, 5, 4, 4, 5, 8, 253, 188, 215, 174, 1, 2, 2, 2, 4, 3, 6, 2, 66,
  213, 194, 143, 217, 166, 97, 6, 48, 93, 142, 100, 103, 140, 87, 42, 5, 170, 5,
  27, 51, 75, 53, 44, 73, 54, 35, 5, 3, 25, 57, 142, 65, 76, 77, 251, 70, 5,
  182, 252, 224, 26, 62, 67, 67, 32, 74, 76, 4, 180, 250, 240, 253, 217, 1, 129,
  7, 104, 77, 119, 80, 41, 39, 79, 119, 80, 57, 72, 41, 16, 18, 44, 71, 53, 0,
  2, 0, 178, 254, 131, 4, 193, 6, 23, 0, 15, 0, 37, 0, 164, 185, 0, 3, 255, 240,
  179, 18, 24, 72, 3, 184, 255, 224, 64, 96, 11, 14, 72, 37, 3, 53, 3, 2, 9, 16,
  18, 24, 72, 9, 32, 11, 14, 72, 42, 9, 58, 9, 2, 171, 2, 1, 137, 2, 153, 2, 2,
  164, 8, 1, 134, 8, 150, 8, 2, 13, 14, 15, 15, 12, 11, 37, 70, 16, 16, 27, 70,
  26, 26, 4, 9, 0, 70, 11, 39, 64, 3, 6, 70, 0, 4, 16, 4, 32, 4, 176, 4, 192, 4,
  208, 4, 6, 7, 4, 37, 27, 128, 32, 21, 9, 2, 6, 15, 8, 3, 21, 14, 14, 11, 80,
  0, 21, 0, 63, 225, 51, 47, 63, 51, 63, 51, 51, 222, 50, 26, 204, 50, 1, 47,
  94, 93, 225, 50, 26, 16, 220, 225, 50, 17, 57, 47, 225, 51, 47, 225, 16, 205,
  50, 16, 205, 50, 49, 48, 0, 93, 93, 93, 93, 1, 93, 43, 43, 93, 43, 43, 33, 17,
  19, 1, 35, 17, 51, 17, 7, 1, 51, 17, 51, 3, 35, 19, 3, 14, 3, 35, 34, 46, 2,
  39, 51, 30, 3, 51, 50, 62, 2, 55, 3, 94, 10, 254, 58, 240, 172, 12, 1, 201,
  239, 183, 123, 183, 123, 37, 6, 48, 93, 142, 100, 103, 140, 87, 42, 5, 170, 5,
  27, 51, 75, 53, 44, 73, 54, 35, 5, 2, 135, 1, 15, 252, 106, 4, 74, 253, 100,
  252, 3, 152, 252, 80, 253, 233, 1, 125, 6, 23, 78, 118, 81, 41, 39, 80, 119,
  80, 57, 73, 41, 16, 19, 43, 72, 53, 0, 2, 0, 47, 0, 0, 4, 70, 5, 182, 0, 22,
  0, 33, 0, 65, 64, 33, 21, 21, 23, 27, 91, 6, 35, 19, 0, 23, 90, 16, 14, 12,
  33, 95, 0, 22, 14, 95, 15, 19, 15, 0, 15, 0, 15, 17, 3, 23, 96, 12, 18, 0, 63,
  225, 63, 57, 57, 47, 47, 17, 51, 16, 225, 50, 16, 225, 1, 47, 198, 51, 225,
  50, 50, 16, 222, 225, 17, 57, 47, 48, 49, 1, 51, 50, 30, 2, 21, 20, 14, 2, 35,
  33, 17, 35, 53, 51, 53, 51, 21, 33, 21, 33, 17, 51, 50, 54, 53, 52, 46, 2, 35,
  35, 1, 129, 168, 152, 207, 127, 55, 60, 126, 194, 134, 254, 131, 152, 152,
  186, 1, 78, 254, 178, 178, 175, 163, 46, 91, 139, 93, 147, 3, 78, 66, 113,
  152, 87, 97, 158, 112, 61, 4, 96, 164, 178, 178, 164, 252, 64, 132, 136, 70,
  97, 60, 27, 0, 2, 0, 61, 0, 0, 4, 68, 6, 20, 0, 20, 0, 33, 0, 73, 64, 39, 15,
  2, 1, 2, 2, 14, 28, 70, 8, 35, 4, 0, 22, 71, 18, 16, 14, 21, 80, 4, 3, 16, 79,
  17, 0, 17, 47, 4, 1, 4, 17, 4, 17, 19, 0, 22, 80, 14, 21, 0, 63, 225, 63, 57,
  57, 47, 47, 93, 17, 51, 16, 225, 50, 16, 225, 1, 47, 198, 51, 225, 50, 50, 16,
  222, 225, 17, 57, 47, 93, 48, 49, 1, 33, 21, 33, 17, 33, 50, 22, 21, 20, 14,
  2, 35, 33, 17, 35, 53, 51, 53, 51, 17, 17, 33, 50, 62, 2, 53, 52, 46, 2, 35,
  1, 143, 1, 23, 254, 233, 1, 21, 212, 204, 47, 101, 159, 113, 254, 57, 156,
  156, 182, 1, 4, 56, 93, 67, 38, 33, 65, 96, 64, 5, 33, 137, 253, 239, 156,
  155, 77, 124, 88, 47, 4, 152, 137, 243, 251, 218, 254, 168, 17, 41, 66, 48,
  49, 66, 40, 17, 0, 2, 0, 176, 0, 0, 4, 70, 5, 182, 0, 20, 0, 35, 0, 108, 64,
  59, 25, 8, 26, 7, 7, 28, 5, 27, 6, 6, 31, 91, 239, 0, 255, 0, 2, 0, 37, 27,
  26, 26, 21, 13, 90, 0, 14, 144, 14, 160, 14, 3, 14, 25, 8, 26, 7, 26, 28, 5,
  6, 27, 27, 21, 6, 7, 7, 12, 96, 22, 21, 21, 13, 35, 96, 15, 3, 13, 18, 0, 63,
  63, 225, 18, 57, 47, 51, 225, 50, 47, 51, 17, 51, 47, 18, 57, 57, 51, 17, 18,
  57, 57, 1, 47, 93, 225, 50, 50, 47, 51, 16, 222, 93, 225, 51, 47, 18, 57, 57,
  51, 17, 18, 57, 57, 48, 49, 1, 20, 14, 2, 7, 23, 7, 39, 6, 6, 35, 35, 17, 35,
  17, 33, 50, 30, 2, 1, 51, 50, 54, 55, 39, 55, 23, 54, 54, 53, 52, 38, 35, 35,
  4, 70, 24, 51, 82, 58, 104, 106, 125, 44, 98, 57, 191, 186, 1, 148, 134, 194,
  126, 60, 253, 36, 170, 32, 59, 26, 94, 109, 118, 60, 59, 163, 175, 201, 4, 10,
  61, 115, 102, 85, 32, 147, 78, 176, 11, 10, 253, 199, 5, 182, 57, 109, 160,
  254, 103, 3, 5, 135, 76, 170, 34, 121, 93, 142, 137, 0, 0, 2, 0, 158, 254, 20,
  4, 68, 4, 94, 0, 35, 0, 57, 0, 120, 64, 67, 50, 33, 51, 32, 32, 53, 30, 52,
  31, 31, 55, 72, 15, 27, 31, 27, 2, 27, 59, 52, 51, 51, 42, 16, 15, 6, 12, 71,
  0, 13, 16, 13, 32, 13, 208, 13, 4, 7, 13, 36, 80, 16, 22, 16, 14, 15, 12, 27,
  50, 33, 51, 32, 51, 53, 30, 31, 52, 52, 47, 80, 0, 31, 32, 32, 5, 0, 22, 0,
  63, 50, 50, 47, 51, 16, 225, 50, 47, 18, 57, 57, 51, 17, 18, 57, 57, 63, 63,
  63, 51, 225, 1, 47, 94, 93, 225, 50, 50, 50, 50, 50, 47, 51, 16, 222, 113,
  225, 51, 47, 18, 57, 57, 51, 17, 18, 57, 57, 48, 49, 5, 34, 46, 2, 39, 35, 22,
  23, 22, 22, 21, 17, 35, 17, 51, 23, 51, 62, 3, 51, 50, 30, 2, 21, 20, 6, 7,
  23, 7, 39, 6, 6, 3, 34, 14, 2, 7, 21, 20, 30, 2, 51, 50, 54, 55, 39, 55, 23,
  54, 53, 52, 38, 2, 150, 61, 98, 79, 61, 23, 12, 3, 3, 2, 4, 182, 147, 27, 8,
  23, 60, 79, 99, 61, 97, 158, 113, 62, 95, 84, 107, 107, 116, 32, 68, 68, 79,
  109, 67, 32, 2, 28, 68, 111, 84, 18, 34, 15, 106, 108, 111, 92, 132, 20, 26,
  43, 58, 32, 34, 31, 26, 55, 16, 254, 43, 6, 54, 148, 35, 61, 45, 27, 72, 143,
  212, 140, 177, 242, 69, 151, 78, 166, 9, 11, 3, 219, 46, 94, 140, 95, 41, 101,
  157, 107, 55, 3, 5, 152, 76, 160, 104, 242, 208, 206, 0, 0, 1, 0, 147, 0, 0,
  4, 100, 5, 182, 0, 13, 0, 49, 64, 24, 5, 5, 8, 0, 15, 3, 7, 90, 12, 10, 8, 6,
  10, 95, 3, 11, 11, 7, 2, 95, 13, 3, 7, 18, 0, 63, 63, 225, 18, 57, 47, 51,
  225, 50, 1, 47, 198, 51, 225, 50, 16, 206, 17, 57, 47, 48, 49, 1, 21, 33, 17,
  33, 21, 33, 17, 35, 17, 35, 53, 51, 17, 4, 100, 253, 129, 1, 80, 254, 176,
  186, 152, 152, 5, 182, 166, 254, 21, 162, 253, 125, 2, 131, 162, 2, 145, 0, 0,
  1, 0, 135, 0, 0, 4, 14, 4, 74, 0, 13, 0, 49, 64, 24, 11, 11, 0, 6, 15, 9, 13,
  71, 4, 2, 0, 12, 2, 79, 9, 3, 3, 0, 8, 80, 5, 15, 0, 21, 0, 63, 63, 225, 18,
  57, 47, 51, 225, 50, 1, 47, 198, 51, 225, 50, 16, 206, 17, 57, 47, 48, 49, 33,
  17, 35, 53, 51, 17, 33, 21, 33, 17, 33, 21, 33, 17, 1, 35, 156, 156, 2, 235,
  253, 203, 1, 23, 254, 233, 1, 225, 137, 1, 224, 154, 254, 186, 137, 254, 31,
  0, 1, 0, 160, 254, 0, 4, 113, 5, 182, 0, 38, 0, 56, 64, 29, 8, 8, 34, 91, 18,
  40, 10, 4, 90, 28, 0, 5, 1, 5, 29, 32, 95, 28, 23, 0, 13, 13, 5, 9, 95, 6, 3,
  5, 18, 0, 63, 63, 225, 18, 57, 47, 193, 47, 51, 225, 50, 1, 47, 93, 198, 225,
  50, 16, 222, 241, 192, 47, 48, 49, 1, 34, 6, 7, 17, 35, 17, 33, 21, 33, 17,
  54, 54, 51, 50, 30, 2, 21, 20, 14, 2, 35, 34, 46, 2, 39, 53, 22, 22, 51, 32,
  17, 52, 46, 2, 1, 213, 37, 60, 26, 186, 2, 248, 253, 194, 29, 72, 45, 153,
  240, 165, 87, 82, 146, 201, 118, 49, 78, 68, 60, 32, 63, 127, 72, 1, 119, 67,
  123, 174, 2, 131, 5, 5, 253, 135, 5, 182, 166, 254, 11, 5, 3, 92, 171, 242,
  151, 170, 248, 162, 79, 6, 12, 19, 12, 162, 23, 24, 1, 239, 121, 185, 126, 64,
  0, 0, 1, 0, 215, 254, 10, 4, 88, 4, 74, 0, 41, 0, 53, 64, 28, 27, 27, 16, 72,
  37, 43, 29, 23, 70, 5, 0, 24, 1, 24, 19, 81, 32, 32, 24, 28, 80, 25, 15, 24,
  21, 11, 81, 0, 0, 47, 225, 63, 63, 225, 18, 57, 47, 225, 1, 47, 93, 198, 225,
  50, 16, 214, 241, 192, 47, 48, 49, 1, 34, 46, 2, 39, 53, 30, 3, 51, 50, 62, 2,
  53, 52, 38, 35, 34, 6, 7, 17, 35, 17, 33, 21, 33, 17, 54, 54, 51, 50, 30, 2,
  21, 20, 14, 2, 2, 127, 41, 65, 55, 49, 26, 25, 48, 52, 61, 38, 70, 110, 77,
  40, 181, 198, 32, 83, 35, 180, 2, 168, 254, 12, 34, 78, 42, 125, 208, 148, 82,
  76, 129, 172, 254, 10, 7, 15, 23, 15, 161, 13, 22, 17, 9, 48, 99, 153, 105,
  211, 203, 6, 6, 254, 47, 4, 74, 154, 254, 195, 5, 5, 62, 138, 219, 157, 151,
  214, 135, 63, 0, 0, 1, 0, 0, 254, 127, 4, 205, 5, 182, 0, 21, 0, 114, 64, 64,
  17, 14, 3, 250, 11, 8, 16, 4, 1, 4, 4, 7, 21, 251, 20, 20, 15, 47, 16, 63, 16,
  2, 16, 16, 1, 171, 18, 1, 105, 18, 1, 66, 18, 1, 11, 18, 1, 18, 23, 6, 22, 10,
  9, 9, 7, 17, 5, 2, 8, 8, 6, 15, 12, 10, 3, 21, 21, 4, 6, 18, 18, 95, 1, 18, 0,
  63, 225, 63, 51, 51, 47, 63, 51, 51, 18, 57, 17, 51, 51, 51, 1, 47, 51, 47,
  51, 17, 51, 16, 205, 93, 93, 93, 93, 50, 50, 47, 93, 51, 50, 47, 225, 17, 57,
  47, 93, 51, 51, 225, 50, 50, 49, 48, 33, 35, 1, 17, 35, 17, 1, 35, 1, 1, 51,
  1, 17, 51, 17, 1, 51, 1, 1, 51, 17, 35, 4, 29, 49, 254, 182, 156, 254, 176,
  182, 1, 96, 254, 172, 178, 1, 72, 156, 1, 65, 179, 254, 176, 1, 16, 119, 176,
  2, 229, 253, 27, 2, 229, 253, 27, 2, 242, 2, 196, 253, 60, 2, 196, 253, 60, 2,
  196, 253, 60, 253, 180, 253, 217, 0, 1, 0, 0, 254, 131, 4, 184, 4, 74, 0, 21,
  0, 98, 64, 53, 5, 22, 16, 13, 2, 73, 10, 7, 3, 3, 8, 20, 73, 0, 27, 17, 1, 17,
  15, 144, 19, 160, 19, 2, 127, 19, 1, 16, 19, 1, 19, 9, 6, 8, 16, 13, 7, 10,
  10, 8, 19, 19, 22, 14, 11, 8, 15, 17, 80, 0, 0, 3, 6, 0, 47, 51, 51, 16, 225,
  63, 51, 51, 17, 51, 47, 18, 57, 17, 51, 51, 51, 1, 47, 50, 50, 47, 93, 93, 93,
  51, 205, 93, 50, 225, 17, 57, 47, 51, 51, 225, 50, 50, 17, 51, 49, 48, 33, 1,
  17, 35, 17, 1, 35, 1, 1, 51, 1, 17, 51, 17, 1, 51, 1, 19, 51, 17, 35, 17, 3,
  223, 254, 195, 160, 254, 195, 195, 1, 90, 254, 164, 184, 1, 74, 160, 1, 74,
  184, 254, 166, 250, 116, 161, 2, 45, 253, 211, 2, 45, 253, 211, 2, 53, 2, 21,
  253, 235, 2, 21, 253, 235, 2, 21, 253, 235, 254, 101, 253, 233, 1, 125, 255,
  255, 0, 139, 254, 66, 4, 47, 5, 203, 2, 38, 1, 177, 0, 0, 1, 6, 3, 127, 247,
  0, 0, 14, 183, 1, 1, 0, 50, 44, 9, 4, 37, 1, 43, 53, 0, 53, 255, 255, 0, 201,
  254, 66, 4, 8, 4, 94, 2, 38, 1, 209, 0, 0, 1, 6, 3, 127, 245, 0, 0, 17, 177,
  1, 1, 184, 255, 243, 180, 47, 41, 8, 18, 37, 1, 43, 53, 0, 53, 0, 0, 1, 0,
  211, 254, 127, 4, 186, 5, 182, 0, 14, 0, 120, 64, 77, 135, 14, 1, 117, 14, 1,
  54, 14, 86, 14, 2, 14, 11, 7, 90, 0, 8, 96, 8, 112, 8, 128, 8, 4, 8, 12, 87,
  13, 1, 64, 13, 1, 37, 13, 1, 7, 13, 1, 13, 13, 40, 5, 1, 5, 85, 0, 1, 54, 0,
  1, 36, 0, 1, 5, 0, 1, 0, 3, 251, 127, 2, 1, 2, 6, 14, 14, 7, 12, 10, 3, 5, 7,
  3, 3, 0, 7, 18, 0, 63, 196, 51, 47, 17, 51, 63, 51, 18, 57, 17, 51, 1, 47, 93,
  225, 205, 93, 93, 93, 93, 50, 93, 51, 47, 93, 93, 93, 93, 51, 47, 93, 225, 50,
  50, 93, 93, 93, 49, 48, 37, 51, 17, 35, 17, 35, 1, 17, 35, 17, 51, 17, 1, 51,
  1, 4, 43, 143, 176, 55, 253, 186, 186, 186, 2, 54, 206, 253, 203, 166, 253,
  217, 1, 129, 2, 229, 253, 27, 5, 182, 253, 60, 2, 196, 253, 66, 0, 1, 0, 215,
  254, 131, 4, 156, 4, 74, 0, 14, 0, 77, 64, 44, 7, 8, 8, 0, 10, 13, 70, 128,
  12, 1, 12, 9, 6, 2, 71, 0, 3, 16, 3, 32, 3, 128, 3, 208, 3, 5, 7, 3, 1, 9, 9,
  2, 7, 5, 15, 10, 80, 0, 0, 2, 13, 13, 2, 21, 0, 63, 51, 47, 17, 51, 16, 225,
  63, 51, 18, 57, 17, 51, 1, 47, 94, 93, 225, 50, 50, 47, 93, 225, 205, 50, 50,
  47, 51, 49, 48, 33, 1, 17, 35, 17, 51, 17, 1, 51, 1, 1, 51, 17, 35, 17, 3,
  174, 253, 221, 180, 180, 2, 6, 222, 253, 241, 1, 158, 158, 176, 2, 45, 253,
  211, 4, 74, 253, 235, 2, 21, 253, 241, 254, 95, 253, 233, 1, 125, 0, 0, 1, 0,
  211, 0, 0, 4, 174, 5, 182, 0, 18, 0, 139, 183, 11, 7, 90, 8, 18, 15, 2, 3,
  184, 1, 3, 64, 73, 12, 5, 38, 4, 1, 12, 4, 28, 4, 2, 4, 4, 0, 0, 8, 96, 8,
  112, 8, 128, 8, 4, 8, 16, 17, 17, 1, 208, 0, 240, 0, 2, 127, 0, 1, 0, 0, 16,
  0, 64, 0, 96, 0, 4, 0, 16, 0, 2, 18, 18, 5, 6, 17, 3, 15, 12, 16, 11, 16, 11,
  6, 6, 9, 8, 4, 13, 4, 13, 9, 3, 8, 0, 18, 0, 63, 50, 63, 57, 57, 47, 47, 17,
  18, 57, 17, 51, 50, 17, 18, 57, 57, 63, 18, 57, 57, 17, 51, 1, 47, 56, 93, 93,
  93, 51, 51, 47, 51, 47, 93, 18, 57, 47, 93, 93, 51, 51, 225, 50, 50, 50, 16,
  225, 50, 48, 49, 33, 35, 1, 21, 35, 17, 7, 17, 35, 17, 51, 17, 55, 17, 51, 21,
  1, 51, 1, 4, 174, 211, 254, 174, 133, 119, 186, 186, 119, 133, 1, 66, 209,
  253, 247, 1, 244, 205, 1, 100, 98, 253, 215, 5, 182, 253, 6, 164, 1, 99, 179,
  1, 166, 253, 101, 0, 1, 0, 215, 0, 0, 4, 150, 4, 74, 0, 18, 0, 127, 64, 75,
  13, 10, 17, 73, 7, 22, 18, 1, 12, 18, 1, 18, 18, 3, 14, 11, 12, 12, 15, 164,
  14, 1, 123, 14, 139, 14, 155, 14, 3, 0, 14, 96, 14, 2, 14, 16, 14, 6, 2, 71,
  0, 3, 96, 3, 2, 3, 10, 7, 11, 13, 11, 4, 16, 0, 15, 1, 13, 13, 8, 63, 18, 1,
  48, 8, 1, 18, 8, 18, 8, 2, 4, 15, 15, 2, 21, 0, 63, 51, 63, 18, 57, 57, 47,
  47, 93, 93, 18, 57, 17, 51, 18, 57, 57, 17, 51, 17, 18, 57, 57, 1, 47, 93,
  225, 50, 47, 56, 93, 93, 93, 51, 51, 47, 51, 17, 18, 57, 47, 93, 93, 51, 225,
  50, 50, 49, 48, 1, 39, 17, 35, 17, 51, 17, 55, 17, 51, 21, 1, 51, 1, 1, 35, 1,
  21, 35, 2, 16, 133, 180, 180, 133, 125, 1, 4, 222, 253, 241, 2, 54, 232, 254,
  223, 125, 1, 166, 135, 253, 211, 4, 74, 253, 235, 137, 1, 56, 185, 1, 13, 253,
  241, 253, 197, 1, 39, 205, 0, 1, 0, 59, 0, 0, 4, 174, 5, 182, 0, 20, 0, 119,
  64, 74, 14, 14, 5, 0, 20, 2, 19, 16, 12, 4, 90, 9, 7, 0, 5, 96, 5, 112, 5,
  128, 5, 4, 5, 72, 18, 88, 18, 2, 18, 19, 19, 1, 208, 0, 240, 0, 2, 127, 0, 1,
  0, 0, 16, 0, 64, 0, 96, 0, 4, 0, 16, 0, 20, 16, 2, 3, 15, 7, 95, 12, 3, 159,
  8, 175, 8, 2, 8, 8, 18, 10, 3, 5, 0, 18, 0, 63, 50, 63, 51, 57, 47, 93, 57,
  51, 225, 50, 17, 51, 51, 51, 1, 47, 56, 93, 93, 93, 51, 51, 47, 51, 93, 47,
  93, 198, 51, 225, 50, 50, 17, 57, 57, 17, 18, 57, 47, 49, 48, 33, 35, 1, 7,
  17, 35, 17, 35, 53, 51, 53, 51, 21, 51, 21, 35, 17, 55, 1, 51, 1, 4, 174, 211,
  254, 62, 140, 186, 152, 152, 186, 213, 213, 121, 1, 197, 209, 253, 247, 2,
  186, 114, 253, 184, 4, 96, 164, 178, 178, 164, 254, 123, 168, 2, 51, 253, 131,
  0, 1, 0, 59, 0, 0, 4, 139, 6, 20, 0, 22, 0, 122, 64, 73, 118, 14, 150, 14, 2,
  101, 14, 1, 86, 14, 1, 69, 14, 1, 14, 17, 6, 6, 13, 7, 3, 19, 71, 22, 1, 0,
  20, 1, 20, 12, 13, 13, 16, 15, 32, 16, 19, 72, 0, 15, 96, 15, 2, 15, 16, 15,
  14, 17, 89, 17, 1, 17, 118, 9, 1, 9, 18, 18, 12, 16, 19, 21, 6, 22, 79, 4, 1,
  1, 2, 12, 15, 2, 0, 0, 63, 63, 18, 57, 47, 51, 237, 50, 63, 51, 18, 57, 17,
  51, 93, 51, 93, 17, 51, 1, 47, 56, 93, 43, 51, 51, 47, 51, 47, 93, 51, 206,
  225, 50, 50, 17, 57, 47, 57, 57, 93, 93, 93, 93, 49, 48, 19, 51, 53, 51, 21,
  33, 21, 33, 17, 3, 51, 55, 1, 51, 1, 1, 35, 1, 7, 17, 35, 17, 35, 59, 156,
  180, 1, 123, 254, 133, 16, 4, 135, 1, 139, 222, 254, 18, 2, 10, 213, 254, 86,
  129, 180, 156, 5, 94, 182, 182, 137, 254, 117, 254, 223, 152, 1, 137, 254, 37,
  253, 145, 1, 248, 82, 254, 90, 4, 213, 0, 0, 1, 0, 23, 0, 0, 4, 174, 5, 182,
  0, 14, 0, 95, 181, 7, 14, 23, 14, 2, 14, 184, 255, 248, 64, 46, 13, 18, 72,
  14, 2, 13, 10, 4, 90, 5, 5, 0, 7, 12, 13, 8, 13, 13, 1, 0, 16, 0, 14, 2, 184,
  2, 1, 169, 2, 1, 88, 2, 1, 2, 10, 3, 3, 5, 12, 7, 95, 8, 3, 5, 0, 18, 0, 63,
  50, 63, 225, 51, 18, 57, 17, 51, 51, 93, 93, 93, 17, 51, 1, 47, 56, 51, 51,
  47, 56, 51, 47, 18, 57, 47, 225, 50, 17, 57, 57, 43, 113, 48, 49, 33, 35, 1,
  7, 17, 35, 17, 33, 53, 33, 17, 55, 1, 51, 1, 4, 174, 203, 254, 162, 137, 186,
  254, 213, 1, 229, 104, 1, 117, 195, 254, 100, 2, 184, 153, 253, 225, 5, 18,
  164, 253, 8, 170, 2, 78, 253, 135, 0, 1, 0, 43, 0, 0, 4, 203, 4, 74, 0, 12, 0,
  92, 64, 54, 167, 0, 1, 150, 0, 1, 0, 1, 16, 1, 1, 40, 4, 56, 4, 2, 4, 14, 12,
  11, 103, 2, 1, 86, 2, 1, 71, 2, 1, 2, 6, 71, 0, 7, 1, 7, 7, 3, 9, 3, 16, 3, 5,
  2, 2, 7, 9, 80, 0, 10, 15, 7, 3, 21, 0, 63, 51, 63, 51, 225, 18, 57, 17, 51,
  1, 47, 56, 47, 18, 57, 47, 93, 225, 50, 93, 93, 93, 50, 50, 17, 51, 93, 51,
  47, 56, 51, 93, 93, 48, 49, 1, 51, 1, 1, 35, 1, 17, 35, 17, 33, 53, 33, 17, 3,
  223, 197, 254, 96, 1, 199, 207, 254, 76, 181, 254, 152, 2, 29, 4, 74, 253,
  241, 253, 197, 2, 45, 253, 211, 3, 176, 154, 253, 235, 0, 0, 1, 0, 135, 254,
  127, 4, 186, 5, 182, 0, 15, 0, 78, 64, 47, 12, 8, 90, 0, 9, 1, 0, 9, 16, 9,
  240, 9, 3, 8, 9, 13, 5, 90, 159, 0, 175, 0, 2, 0, 4, 251, 127, 1, 207, 1, 2,
  1, 6, 95, 12, 12, 8, 14, 10, 3, 5, 8, 3, 3, 0, 8, 18, 0, 63, 192, 51, 47, 17,
  51, 63, 51, 18, 57, 47, 225, 1, 47, 93, 225, 221, 93, 225, 50, 47, 94, 93,
  113, 225, 50, 48, 49, 37, 51, 17, 35, 17, 35, 17, 33, 17, 35, 17, 51, 17, 33,
  17, 51, 4, 10, 176, 176, 186, 253, 242, 187, 187, 2, 14, 186, 166, 253, 217,
  1, 129, 2, 170, 253, 86, 5, 182, 253, 152, 2, 104, 0, 0, 1, 0, 160, 254, 131,
  4, 156, 4, 74, 0, 15, 0, 85, 64, 53, 8, 0, 71, 11, 15, 70, 15, 12, 1, 239, 12,
  1, 160, 12, 192, 12, 2, 79, 12, 111, 12, 2, 12, 7, 3, 71, 0, 4, 16, 4, 32, 4,
  208, 4, 4, 7, 4, 1, 80, 7, 7, 9, 6, 15, 11, 80, 0, 0, 3, 14, 14, 3, 21, 0, 63,
  51, 47, 17, 51, 16, 225, 63, 51, 57, 47, 225, 1, 47, 94, 93, 225, 50, 47, 93,
  93, 93, 113, 225, 221, 225, 50, 48, 49, 33, 17, 33, 17, 35, 17, 51, 17, 33,
  17, 51, 17, 51, 17, 35, 17, 3, 70, 254, 16, 182, 182, 1, 240, 182, 160, 176,
  1, 233, 254, 23, 4, 74, 254, 57, 1, 199, 252, 80, 253, 233, 1, 125, 0, 1, 0,
  135, 0, 0, 4, 182, 5, 182, 0, 13, 0, 75, 64, 47, 9, 1, 90, 63, 0, 79, 0, 191,
  0, 3, 0, 64, 26, 29, 72, 0, 143, 11, 1, 11, 8, 4, 90, 0, 5, 1, 0, 5, 16, 5,
  240, 5, 3, 8, 5, 3, 95, 8, 8, 0, 13, 10, 6, 3, 5, 0, 18, 0, 63, 50, 63, 51,
  192, 18, 57, 47, 225, 1, 47, 94, 93, 113, 225, 50, 47, 93, 220, 43, 93, 225,
  50, 49, 48, 33, 35, 17, 33, 17, 35, 17, 51, 17, 33, 17, 33, 21, 33, 3, 156,
  187, 254, 97, 187, 187, 1, 159, 1, 213, 254, 230, 2, 170, 253, 86, 5, 182,
  253, 152, 2, 104, 164, 0, 0, 1, 0, 160, 0, 0, 4, 182, 4, 74, 0, 13, 0, 59, 64,
  34, 9, 1, 71, 0, 79, 11, 1, 11, 8, 4, 71, 0, 5, 16, 5, 32, 5, 208, 5, 4, 7, 5,
  3, 80, 8, 8, 0, 13, 10, 6, 15, 5, 0, 21, 0, 63, 50, 63, 51, 192, 18, 57, 47,
  225, 1, 47, 94, 93, 225, 50, 47, 93, 220, 225, 50, 48, 49, 33, 35, 17, 33, 17,
  35, 17, 51, 17, 33, 17, 33, 21, 35, 3, 199, 183, 254, 70, 182, 182, 1, 186, 1,
  166, 239, 1, 233, 254, 23, 4, 74, 254, 57, 1, 199, 154, 0, 1, 0, 106, 254, 0,
  4, 156, 5, 182, 0, 36, 0, 68, 64, 38, 16, 16, 0, 29, 251, 30, 30, 34, 23, 251,
  8, 64, 9, 14, 72, 8, 38, 33, 251, 48, 34, 1, 34, 26, 3, 3, 33, 32, 95, 35, 3,
  30, 33, 18, 20, 95, 13, 19, 0, 63, 225, 63, 51, 63, 225, 18, 57, 47, 201, 1,
  47, 93, 225, 16, 222, 43, 225, 17, 57, 47, 241, 50, 192, 47, 49, 48, 1, 54,
  54, 51, 50, 30, 2, 21, 20, 14, 2, 35, 34, 38, 39, 53, 22, 22, 51, 50, 54, 53,
  52, 38, 35, 34, 7, 17, 35, 17, 33, 17, 35, 17, 33, 2, 203, 18, 49, 25, 98,
  141, 91, 43, 51, 94, 134, 84, 54, 85, 43, 38, 73, 47, 115, 100, 103, 112, 51,
  27, 166, 254, 235, 166, 2, 97, 3, 23, 5, 7, 92, 171, 242, 151, 170, 248, 162,
  79, 19, 20, 162, 16, 21, 247, 248, 243, 253, 12, 253, 137, 5, 18, 250, 238, 5,
  182, 0, 1, 0, 127, 254, 10, 4, 131, 4, 74, 0, 41, 0, 78, 64, 44, 29, 21, 73,
  22, 3, 3, 96, 22, 1, 22, 22, 26, 12, 73, 15, 37, 31, 37, 2, 37, 43, 25, 73, 0,
  26, 1, 26, 17, 81, 32, 32, 26, 24, 80, 27, 15, 22, 26, 21, 4, 7, 81, 3, 0, 0,
  47, 50, 225, 50, 63, 51, 63, 225, 18, 57, 47, 225, 1, 47, 93, 225, 16, 222,
  93, 225, 17, 57, 47, 93, 51, 47, 16, 225, 50, 49, 48, 1, 34, 38, 39, 53, 22,
  22, 51, 50, 62, 2, 53, 52, 46, 2, 35, 34, 6, 7, 17, 35, 17, 33, 17, 35, 17,
  33, 17, 54, 54, 51, 50, 30, 2, 21, 20, 14, 2, 3, 57, 60, 92, 40, 42, 82, 56,
  50, 70, 44, 20, 20, 47, 76, 57, 23, 45, 20, 162, 254, 254, 162, 2, 70, 21, 48,
  23, 78, 131, 93, 52, 48, 87, 121, 254, 10, 22, 21, 162, 22, 23, 47, 98, 153,
  107, 107, 156, 102, 49, 4, 6, 254, 45, 3, 176, 252, 80, 4, 74, 254, 39, 6, 6,
  57, 133, 221, 165, 155, 215, 133, 60, 0, 2, 0, 84, 255, 172, 4, 162, 5, 205,
  0, 65, 0, 83, 0, 107, 64, 61, 51, 18, 5, 79, 79, 0, 76, 91, 16, 56, 32, 56, 2,
  56, 56, 26, 35, 34, 34, 66, 91, 0, 0, 11, 11, 85, 43, 91, 31, 26, 47, 26, 2,
  26, 71, 96, 112, 61, 128, 61, 2, 61, 61, 38, 95, 31, 4, 79, 51, 48, 95, 21,
  11, 8, 95, 12, 15, 18, 5, 21, 19, 0, 63, 51, 51, 220, 50, 225, 50, 16, 225,
  50, 50, 63, 241, 202, 47, 93, 225, 1, 47, 93, 225, 17, 51, 47, 51, 47, 225,
  50, 47, 51, 17, 57, 47, 113, 225, 18, 57, 17, 51, 51, 51, 49, 48, 1, 20, 14,
  2, 7, 22, 22, 51, 50, 54, 55, 21, 6, 6, 35, 34, 38, 39, 6, 6, 35, 34, 38, 38,
  2, 53, 52, 18, 54, 54, 51, 50, 22, 23, 7, 38, 38, 35, 34, 14, 2, 21, 20, 30,
  2, 51, 50, 54, 55, 46, 3, 53, 52, 62, 2, 51, 50, 30, 2, 7, 52, 46, 2, 35, 34,
  14, 2, 21, 20, 22, 23, 62, 3, 4, 123, 31, 54, 71, 39, 23, 55, 35, 31, 59, 31,
  29, 68, 32, 69, 131, 62, 41, 85, 59, 126, 196, 134, 70, 69, 134, 196, 127, 50,
  93, 38, 56, 28, 61, 34, 81, 124, 84, 42, 46, 88, 126, 80, 20, 19, 16, 37, 56,
  38, 19, 41, 80, 115, 74, 74, 115, 80, 42, 197, 11, 27, 44, 32, 32, 44, 26, 11,
  56, 48, 30, 46, 31, 16, 2, 190, 106, 184, 151, 115, 37, 13, 10, 14, 11, 170,
  13, 12, 44, 52, 17, 15, 95, 188, 1, 21, 183, 193, 1, 30, 189, 94, 20, 15, 154,
  11, 14, 68, 145, 227, 158, 157, 221, 139, 63, 3, 4, 54, 117, 132, 149, 86,
  132, 192, 124, 60, 55, 118, 188, 143, 86, 132, 89, 45, 52, 96, 136, 84, 144,
  228, 79, 33, 101, 124, 139, 0, 0, 2, 0, 115, 255, 197, 4, 115, 4, 94, 0, 15,
  0, 80, 0, 137, 64, 57, 72, 52, 19, 5, 5, 67, 87, 0, 1, 0, 72, 32, 57, 1, 89,
  57, 1, 72, 57, 1, 57, 57, 27, 36, 35, 35, 8, 72, 67, 78, 78, 15, 67, 1, 67,
  82, 44, 72, 0, 27, 16, 27, 2, 27, 13, 78, 80, 62, 1, 144, 62, 160, 62, 176,
  62, 3, 62, 184, 255, 192, 64, 23, 9, 12, 72, 62, 62, 49, 36, 39, 80, 35, 32,
  16, 5, 49, 80, 22, 72, 74, 80, 16, 19, 22, 22, 0, 63, 51, 212, 225, 50, 16,
  225, 50, 63, 51, 225, 50, 18, 57, 47, 43, 93, 113, 225, 1, 47, 93, 225, 16,
  206, 93, 50, 47, 16, 225, 50, 47, 51, 17, 57, 47, 93, 93, 113, 225, 93, 18,
  57, 17, 51, 51, 51, 49, 48, 1, 20, 30, 2, 23, 54, 54, 53, 52, 46, 2, 35, 34,
  6, 1, 34, 38, 39, 6, 6, 35, 34, 46, 2, 53, 52, 62, 2, 51, 50, 22, 23, 7, 38,
  38, 35, 34, 14, 2, 21, 20, 30, 2, 51, 50, 50, 55, 46, 3, 53, 52, 62, 2, 51,
  50, 30, 2, 21, 20, 14, 2, 7, 22, 51, 50, 54, 55, 21, 6, 6, 2, 172, 19, 33, 43,
  24, 57, 66, 13, 29, 44, 31, 62, 63, 1, 82, 65, 124, 57, 38, 83, 47, 111, 182,
  129, 71, 67, 127, 185, 118, 57, 79, 32, 45, 25, 56, 42, 81, 117, 75, 36, 39,
  77, 115, 76, 10, 10, 9, 34, 52, 36, 19, 48, 84, 114, 65, 65, 110, 82, 46, 27,
  48, 64, 37, 39, 53, 26, 57, 28, 23, 63, 1, 244, 52, 91, 77, 64, 26, 45, 160,
  107, 51, 84, 58, 32, 122, 253, 104, 30, 37, 14, 14, 76, 145, 209, 133, 129,
  212, 151, 83, 15, 11, 146, 8, 13, 56, 108, 159, 103, 97, 152, 105, 56, 2, 39,
  80, 90, 103, 61, 94, 136, 89, 43, 39, 86, 138, 99, 70, 119, 99, 79, 30, 19, 6,
  8, 147, 9, 7, 0, 255, 255, 0, 129, 254, 66, 4, 156, 5, 203, 2, 38, 0, 38, 0,
  0, 1, 7, 3, 127, 0, 158, 0, 0, 0, 14, 183, 1, 1, 118, 36, 30, 6, 11, 37, 1,
  43, 53, 0, 53, 255, 255, 0, 172, 254, 66, 4, 37, 4, 94, 2, 38, 0, 70, 0, 0, 1,
  6, 3, 127, 55, 0, 0, 14, 183, 1, 1, 53, 34, 28, 15, 0, 37, 1, 43, 53, 0, 53,
  0, 1, 0, 102, 254, 127, 4, 100, 5, 182, 0, 11, 0, 74, 64, 44, 10, 251, 11, 1,
  6, 6, 8, 90, 3, 208, 1, 1, 162, 1, 1, 147, 1, 1, 3, 142, 1, 1, 4, 99, 1, 1, 5,
  16, 1, 80, 1, 2, 1, 7, 3, 95, 4, 3, 11, 11, 8, 95, 1, 18, 0, 63, 225, 51, 47,
  63, 225, 50, 1, 47, 93, 95, 93, 95, 93, 95, 93, 93, 93, 198, 241, 194, 47, 16,
  222, 225, 48, 49, 33, 35, 17, 33, 53, 33, 21, 33, 17, 51, 17, 35, 2, 195, 187,
  254, 94, 3, 254, 254, 95, 176, 176, 5, 18, 164, 164, 251, 148, 253, 217, 0, 0,
  1, 0, 121, 254, 131, 4, 82, 4, 74, 0, 11, 0, 54, 64, 32, 9, 71, 10, 0, 5, 5,
  7, 71, 2, 16, 0, 80, 0, 144, 0, 160, 0, 208, 0, 5, 0, 6, 2, 80, 3, 15, 10, 10,
  7, 80, 0, 21, 0, 63, 225, 51, 47, 63, 225, 50, 1, 47, 93, 206, 241, 202, 47,
  16, 222, 225, 49, 48, 33, 17, 33, 53, 33, 21, 33, 17, 51, 17, 35, 17, 2, 10,
  254, 111, 3, 217, 254, 111, 159, 182, 3, 176, 154, 154, 252, 234, 253, 233, 1,
  125, 255, 255, 0, 33, 0, 0, 4, 170, 5, 182, 2, 6, 0, 60, 0, 0, 0, 1, 0, 82,
  254, 20, 4, 121, 4, 74, 0, 19, 0, 99, 64, 62, 55, 4, 71, 4, 2, 38, 4, 1, 4,
  141, 3, 1, 3, 1, 72, 17, 1, 41, 17, 1, 17, 207, 18, 1, 18, 18, 10, 0, 71, 208,
  1, 1, 160, 1, 1, 147, 1, 1, 3, 123, 1, 1, 99, 1, 1, 5, 16, 1, 80, 1, 2, 1, 19,
  10, 2, 2, 1, 17, 3, 15, 1, 27, 0, 63, 63, 51, 18, 57, 17, 51, 51, 1, 47, 93,
  95, 93, 93, 95, 93, 93, 93, 241, 57, 202, 47, 93, 50, 93, 93, 16, 206, 93, 50,
  93, 93, 49, 48, 1, 35, 17, 1, 51, 19, 30, 3, 23, 51, 62, 3, 55, 19, 51, 1, 2,
  193, 183, 254, 72, 190, 238, 12, 31, 28, 24, 5, 6, 6, 23, 29, 31, 12, 239,
  189, 254, 72, 254, 20, 1, 236, 4, 74, 253, 145, 32, 90, 93, 86, 29, 29, 86,
  93, 90, 32, 2, 111, 251, 182, 0, 0, 1, 0, 33, 0, 0, 4, 170, 5, 182, 0, 16, 0,
  202, 185, 0, 16, 255, 248, 64, 36, 13, 16, 72, 38, 16, 54, 16, 2, 23, 16, 1,
  104, 1, 120, 1, 2, 90, 1, 1, 72, 1, 1, 41, 1, 57, 1, 2, 24, 1, 1, 39, 0, 183,
  0, 2, 0, 184, 255, 248, 179, 13, 17, 72, 16, 184, 255, 248, 64, 84, 20, 24,
  72, 16, 175, 15, 255, 15, 2, 89, 15, 1, 15, 9, 1, 8, 20, 24, 72, 1, 224, 2,
  240, 2, 2, 123, 2, 1, 80, 2, 1, 2, 2, 8, 0, 9, 8, 6, 6, 4, 8, 90, 13, 11, 208,
  9, 1, 162, 9, 1, 147, 9, 1, 3, 142, 9, 1, 4, 99, 9, 1, 5, 16, 9, 80, 9, 2, 9,
  3, 0, 14, 14, 7, 11, 95, 4, 12, 12, 1, 8, 18, 15, 1, 3, 0, 63, 51, 63, 18, 57,
  47, 51, 225, 50, 51, 17, 51, 51, 1, 47, 93, 95, 93, 95, 93, 95, 93, 93, 93,
  206, 51, 241, 50, 202, 47, 17, 18, 57, 16, 200, 47, 93, 93, 93, 50, 43, 16,
  204, 93, 93, 50, 43, 48, 49, 0, 43, 93, 1, 93, 93, 93, 93, 93, 93, 93, 43, 1,
  1, 51, 1, 21, 33, 21, 33, 17, 35, 17, 33, 53, 33, 53, 1, 51, 2, 100, 1, 125,
  201, 254, 25, 1, 38, 254, 218, 187, 254, 217, 1, 39, 254, 25, 203, 2, 211, 2,
  227, 252, 131, 61, 164, 254, 168, 1, 88, 164, 51, 3, 135, 0, 1, 0, 82, 254,
  20, 4, 121, 4, 74, 0, 25, 0, 136, 64, 11, 135, 10, 151, 10, 167, 10, 3, 118,
  10, 1, 10, 184, 255, 248, 64, 71, 11, 15, 72, 10, 9, 4, 168, 23, 1, 121, 23,
  1, 23, 8, 11, 15, 72, 23, 207, 24, 1, 24, 24, 3, 16, 4, 25, 3, 1, 1, 3, 71, 8,
  6, 208, 4, 1, 162, 4, 1, 147, 4, 1, 3, 142, 4, 1, 4, 99, 4, 1, 5, 16, 4, 80,
  4, 2, 4, 2, 6, 79, 25, 16, 7, 7, 3, 23, 9, 15, 3, 27, 0, 63, 63, 51, 18, 57,
  47, 51, 51, 225, 50, 1, 47, 93, 95, 93, 95, 93, 95, 93, 93, 93, 206, 51, 241,
  202, 47, 17, 51, 18, 57, 16, 200, 47, 93, 50, 43, 93, 93, 16, 204, 50, 43, 93,
  93, 48, 49, 33, 21, 33, 17, 35, 17, 33, 53, 33, 1, 51, 19, 30, 3, 23, 51, 62,
  3, 55, 19, 51, 1, 3, 203, 254, 246, 183, 254, 246, 1, 10, 254, 72, 190, 238,
  12, 31, 28, 24, 5, 6, 6, 23, 29, 31, 12, 239, 189, 254, 72, 137, 254, 157, 1,
  99, 137, 4, 74, 253, 145, 32, 90, 93, 86, 29, 29, 86, 93, 90, 32, 2, 111, 251,
  182, 0, 1, 0, 53, 254, 127, 4, 186, 5, 182, 0, 15, 0, 160, 64, 21, 71, 15, 87,
  15, 167, 15, 3, 15, 72, 9, 104, 9, 120, 9, 3, 9, 6, 12, 12, 14, 11, 184, 255,
  248, 64, 14, 12, 15, 72, 6, 11, 22, 11, 38, 11, 3, 11, 10, 10, 7, 184, 255,
  248, 64, 64, 12, 15, 72, 6, 7, 22, 7, 38, 7, 3, 7, 8, 13, 8, 12, 15, 72, 9,
  13, 25, 13, 41, 13, 3, 13, 14, 14, 1, 5, 8, 12, 15, 72, 9, 5, 25, 5, 41, 5, 3,
  5, 0, 0, 4, 251, 1, 15, 12, 6, 9, 9, 7, 13, 10, 3, 0, 95, 5, 5, 7, 3, 3, 7,
  18, 0, 63, 51, 47, 17, 51, 16, 225, 63, 51, 18, 57, 17, 51, 51, 51, 1, 47,
  225, 51, 17, 51, 93, 43, 17, 51, 47, 51, 93, 43, 47, 51, 93, 43, 51, 47, 51,
  93, 43, 18, 57, 17, 51, 51, 93, 51, 93, 48, 49, 37, 51, 17, 35, 17, 35, 1, 1,
  35, 1, 1, 51, 1, 1, 51, 1, 4, 51, 135, 176, 71, 254, 157, 254, 146, 189, 1,
  197, 254, 90, 199, 1, 75, 1, 78, 191, 254, 90, 166, 253, 217, 1, 129, 2, 123,
  253, 133, 2, 252, 2, 186, 253, 209, 2, 47, 253, 76, 0, 0, 1, 0, 96, 254, 131,
  4, 156, 4, 74, 0, 15, 0, 189, 183, 196, 14, 212, 14, 228, 14, 3, 14, 184, 255,
  240, 64, 36, 11, 14, 72, 203, 12, 219, 12, 235, 12, 3, 12, 16, 11, 14, 72,
  203, 4, 219, 4, 235, 4, 3, 4, 16, 11, 14, 72, 196, 2, 212, 2, 228, 2, 3, 6, 2,
  184, 255, 240, 64, 20, 11, 14, 72, 73, 13, 1, 13, 16, 18, 23, 72, 10, 13, 26,
  13, 2, 70, 3, 1, 3, 184, 255, 240, 64, 51, 18, 23, 72, 5, 3, 21, 3, 2, 13, 6,
  0, 3, 3, 5, 2, 1, 1, 14, 31, 15, 1, 15, 12, 7, 7, 8, 4, 5, 5, 11, 70, 8, 7,
  80, 12, 12, 14, 13, 6, 3, 0, 0, 1, 14, 10, 10, 14, 21, 4, 1, 15, 0, 63, 51,
  63, 51, 47, 17, 18, 57, 17, 51, 51, 51, 17, 51, 16, 225, 1, 47, 225, 51, 47,
  51, 17, 51, 17, 51, 47, 93, 51, 51, 47, 51, 18, 57, 17, 51, 51, 51, 48, 49, 0,
  93, 43, 93, 93, 43, 93, 1, 43, 95, 93, 43, 93, 43, 93, 43, 93, 1, 1, 51, 1, 1,
  51, 1, 1, 51, 17, 35, 17, 35, 1, 1, 35, 1, 254, 254, 119, 207, 1, 34, 1, 35,
  207, 254, 117, 1, 45, 162, 176, 80, 254, 202, 254, 201, 207, 2, 51, 2, 23,
  254, 102, 1, 154, 253, 233, 254, 103, 253, 233, 1, 125, 1, 180, 254, 76, 0, 0,
  1, 0, 23, 254, 127, 4, 186, 5, 182, 0, 15, 0, 57, 64, 31, 0, 14, 48, 14, 2,
  14, 14, 15, 90, 11, 10, 1, 90, 4, 7, 251, 6, 15, 10, 95, 2, 12, 3, 4, 0, 95,
  9, 7, 7, 9, 18, 0, 63, 51, 47, 16, 225, 50, 63, 51, 225, 50, 1, 47, 225, 221,
  225, 47, 205, 241, 201, 47, 93, 48, 49, 37, 33, 17, 51, 17, 51, 17, 35, 17,
  33, 17, 35, 53, 33, 21, 35, 1, 188, 1, 148, 186, 176, 176, 252, 248, 235, 2,
  145, 236, 166, 5, 16, 250, 240, 253, 217, 1, 129, 5, 18, 164, 164, 0, 0, 1, 0,
  20, 254, 131, 4, 156, 4, 74, 0, 15, 0, 63, 64, 36, 11, 71, 13, 2, 70, 160, 15,
  176, 15, 2, 15, 64, 8, 1, 1, 8, 1, 8, 8, 10, 71, 5, 3, 12, 4, 80, 6, 15, 14,
  10, 80, 3, 1, 1, 3, 21, 0, 63, 51, 47, 16, 225, 50, 63, 225, 51, 1, 47, 206,
  241, 202, 47, 93, 93, 47, 93, 225, 222, 225, 48, 49, 1, 35, 17, 33, 17, 35,
  53, 33, 21, 35, 17, 33, 17, 51, 17, 51, 4, 156, 176, 253, 6, 222, 2, 121, 229,
  1, 158, 182, 160, 254, 131, 1, 125, 3, 176, 154, 154, 252, 234, 3, 176, 252,
  80, 0, 1, 0, 135, 254, 127, 4, 186, 5, 182, 0, 25, 0, 61, 64, 34, 15, 90, 0,
  12, 1, 12, 23, 5, 90, 0, 3, 251, 127, 2, 207, 2, 2, 2, 23, 20, 95, 6, 9, 9,
  24, 13, 3, 0, 95, 5, 3, 3, 5, 18, 0, 63, 51, 47, 16, 225, 63, 51, 57, 47, 51,
  225, 50, 1, 47, 93, 225, 221, 225, 50, 47, 93, 225, 48, 49, 37, 51, 17, 35,
  17, 35, 17, 6, 6, 35, 34, 38, 53, 17, 51, 17, 20, 30, 2, 51, 50, 54, 55, 17,
  51, 4, 10, 176, 176, 186, 81, 169, 84, 187, 192, 187, 20, 50, 82, 61, 77, 152,
  84, 186, 166, 253, 217, 1, 129, 2, 63, 29, 38, 191, 180, 2, 71, 253, 209, 57,
  87, 58, 29, 31, 28, 2, 219, 0, 1, 0, 152, 254, 131, 4, 156, 4, 74, 0, 27, 0,
  65, 64, 37, 20, 1, 71, 23, 27, 70, 160, 24, 1, 47, 24, 1, 24, 14, 71, 0, 11,
  192, 11, 2, 11, 20, 17, 80, 1, 6, 6, 0, 21, 12, 15, 26, 26, 23, 80, 0, 21, 0,
  63, 225, 51, 47, 63, 51, 18, 57, 47, 51, 225, 50, 1, 47, 93, 225, 47, 93, 93,
  225, 221, 225, 50, 48, 49, 33, 17, 14, 3, 35, 34, 46, 2, 53, 17, 51, 17, 20,
  22, 51, 50, 54, 55, 17, 51, 17, 51, 17, 35, 17, 3, 70, 39, 78, 82, 90, 51, 82,
  129, 88, 47, 182, 105, 100, 78, 148, 73, 182, 160, 176, 1, 207, 25, 37, 26,
  13, 47, 84, 115, 68, 1, 166, 254, 102, 88, 86, 45, 43, 1, 240, 252, 80, 253,
  233, 1, 125, 0, 1, 0, 135, 0, 0, 4, 70, 5, 182, 0, 29, 0, 81, 177, 24, 6, 184,
  1, 3, 64, 38, 22, 7, 7, 12, 27, 1, 90, 0, 31, 15, 90, 0, 12, 16, 12, 2, 12,
  27, 24, 22, 22, 20, 95, 9, 8, 9, 7, 7, 5, 2, 9, 9, 1, 28, 13, 3, 1, 18, 0, 63,
  63, 51, 18, 57, 47, 51, 51, 51, 47, 17, 51, 16, 237, 50, 47, 50, 50, 1, 47,
  93, 225, 16, 222, 225, 50, 17, 57, 47, 51, 225, 50, 49, 48, 33, 35, 17, 6, 6,
  7, 17, 35, 17, 35, 34, 38, 53, 17, 51, 17, 20, 30, 2, 51, 51, 17, 51, 17, 54,
  54, 55, 17, 51, 4, 70, 187, 65, 109, 53, 133, 33, 187, 192, 187, 20, 50, 82,
  61, 12, 133, 51, 113, 63, 187, 2, 86, 25, 36, 11, 254, 199, 1, 39, 191, 180,
  2, 71, 253, 209, 57, 87, 58, 29, 1, 88, 254, 180, 9, 36, 23, 2, 198, 0, 0, 1,
  0, 152, 0, 0, 4, 37, 4, 74, 0, 28, 0, 95, 64, 55, 8, 19, 73, 6, 64, 20, 80,
  20, 112, 20, 128, 20, 4, 20, 20, 27, 10, 14, 71, 13, 30, 1, 71, 0, 27, 16, 27,
  2, 27, 21, 22, 20, 20, 18, 15, 4, 80, 22, 22, 14, 11, 28, 15, 14, 21, 10, 8,
  5, 15, 6, 1, 6, 6, 5, 21, 0, 63, 51, 47, 93, 17, 51, 51, 63, 63, 51, 18, 57,
  47, 225, 51, 51, 51, 47, 17, 51, 1, 47, 93, 225, 16, 222, 225, 50, 17, 57, 47,
  93, 51, 225, 50, 48, 49, 1, 17, 20, 22, 51, 51, 17, 51, 17, 54, 55, 17, 51,
  17, 35, 17, 6, 6, 7, 21, 35, 53, 35, 34, 46, 2, 53, 17, 1, 78, 105, 100, 6,
  125, 104, 105, 182, 182, 53, 101, 55, 125, 47, 82, 129, 88, 47, 4, 74, 254,
  102, 88, 86, 1, 45, 254, 227, 29, 70, 1, 213, 251, 182, 1, 233, 37, 51, 16,
  254, 231, 47, 84, 115, 68, 1, 166, 0, 0, 1, 0, 135, 0, 0, 4, 70, 5, 182, 0,
  19, 0, 43, 64, 22, 10, 90, 9, 21, 2, 18, 90, 0, 19, 1, 19, 17, 14, 95, 2, 5,
  5, 19, 9, 18, 0, 3, 0, 63, 63, 51, 57, 47, 51, 225, 50, 1, 47, 93, 225, 50,
  16, 222, 225, 48, 49, 19, 51, 17, 54, 54, 51, 50, 22, 21, 17, 35, 17, 52, 38,
  35, 34, 6, 7, 17, 35, 135, 187, 110, 188, 95, 183, 196, 187, 100, 117, 86,
  175, 107, 187, 5, 182, 253, 170, 45, 45, 188, 182, 253, 184, 2, 47, 116, 116,
  40, 40, 253, 57, 0, 0, 1, 0, 168, 0, 0, 4, 53, 4, 74, 0, 23, 0, 59, 64, 36, 0,
  71, 176, 23, 192, 23, 2, 23, 25, 12, 8, 71, 0, 9, 16, 9, 32, 9, 192, 9, 208,
  9, 5, 7, 9, 7, 4, 80, 12, 17, 17, 10, 15, 9, 0, 21, 0, 63, 50, 63, 57, 47, 51,
  225, 50, 1, 47, 94, 93, 225, 50, 16, 222, 93, 225, 48, 49, 33, 17, 52, 38, 35,
  34, 6, 7, 17, 35, 17, 51, 17, 62, 3, 51, 50, 30, 2, 21, 17, 3, 127, 105, 100,
  90, 166, 84, 182, 182, 44, 87, 92, 101, 57, 82, 129, 88, 47, 1, 154, 88, 86,
  58, 57, 254, 43, 4, 74, 254, 22, 31, 47, 32, 17, 47, 83, 115, 68, 254, 90, 0,
  2, 255, 248, 255, 236, 4, 123, 5, 205, 0, 45, 0, 56, 0, 84, 64, 47, 52, 91, 5,
  18, 18, 5, 58, 35, 134, 38, 1, 103, 38, 119, 38, 2, 38, 251, 31, 51, 7, 91,
  40, 31, 28, 1, 28, 34, 31, 28, 7, 96, 51, 34, 40, 40, 0, 17, 12, 95, 18, 23,
  19, 46, 95, 0, 4, 0, 63, 225, 63, 51, 225, 50, 17, 57, 47, 204, 51, 225, 50,
  1, 47, 51, 221, 93, 50, 225, 50, 16, 225, 93, 93, 50, 16, 206, 50, 47, 16,
  225, 48, 49, 1, 50, 22, 22, 18, 21, 21, 33, 30, 3, 51, 50, 62, 2, 55, 21, 14,
  3, 35, 34, 46, 2, 39, 38, 38, 53, 52, 54, 55, 51, 6, 6, 21, 20, 51, 51, 62, 3,
  23, 34, 14, 2, 7, 33, 52, 46, 2, 2, 221, 125, 160, 93, 36, 253, 96, 5, 36, 75,
  120, 90, 47, 79, 71, 65, 33, 33, 65, 76, 92, 60, 126, 179, 118, 60, 8, 144,
  143, 17, 11, 156, 6, 14, 102, 21, 11, 60, 109, 162, 110, 64, 92, 62, 33, 5, 1,
  223, 16, 48, 87, 5, 205, 101, 189, 254, 241, 170, 90, 122, 194, 134, 71, 12,
  20, 28, 16, 170, 15, 26, 18, 10, 93, 177, 254, 160, 3, 114, 122, 42, 66, 23,
  15, 62, 35, 97, 154, 244, 171, 91, 164, 65, 126, 185, 120, 117, 184, 128, 67,
  0, 0, 2, 255, 213, 255, 236, 4, 88, 4, 94, 0, 44, 0, 53, 0, 94, 64, 56, 49,
  72, 30, 40, 40, 30, 55, 12, 149, 15, 1, 102, 15, 118, 15, 134, 15, 3, 15, 73,
  8, 48, 31, 72, 19, 31, 5, 47, 5, 2, 5, 11, 8, 64, 24, 27, 72, 8, 5, 31, 80,
  48, 11, 18, 18, 34, 45, 80, 24, 16, 39, 34, 81, 40, 0, 22, 0, 63, 50, 225, 50,
  63, 225, 18, 57, 47, 204, 51, 225, 50, 1, 47, 43, 51, 221, 93, 50, 225, 50,
  16, 225, 93, 93, 50, 16, 206, 50, 47, 16, 225, 48, 49, 5, 34, 46, 2, 39, 38,
  38, 53, 52, 54, 55, 51, 6, 6, 21, 20, 22, 51, 51, 62, 3, 51, 50, 30, 2, 21,
  21, 33, 22, 22, 51, 50, 62, 2, 55, 21, 14, 3, 3, 34, 6, 7, 33, 52, 46, 2, 2,
  215, 108, 178, 131, 75, 4, 133, 141, 17, 10, 149, 6, 14, 48, 50, 27, 14, 75,
  117, 152, 90, 99, 158, 110, 59, 253, 76, 5, 152, 152, 51, 87, 80, 77, 39, 40,
  77, 81, 87, 96, 115, 132, 11, 1, 235, 27, 56, 88, 20, 70, 136, 199, 129, 2,
  111, 114, 39, 63, 21, 14, 58, 34, 47, 49, 108, 170, 117, 61, 71, 129, 181,
  110, 113, 193, 182, 10, 19, 29, 18, 162, 19, 28, 18, 8, 3, 219, 156, 149, 68,
  113, 80, 44, 0, 0, 2, 255, 248, 254, 127, 4, 123, 5, 205, 0, 48, 0, 59, 0,
  103, 64, 57, 24, 251, 25, 25, 31, 55, 91, 5, 18, 18, 5, 61, 38, 134, 41, 1,
  103, 41, 119, 41, 2, 41, 251, 34, 54, 7, 91, 44, 31, 31, 1, 31, 37, 34, 31, 7,
  96, 54, 37, 43, 43, 0, 17, 12, 95, 23, 26, 23, 24, 24, 18, 23, 19, 49, 95, 0,
  4, 0, 63, 225, 63, 51, 51, 47, 17, 51, 16, 225, 50, 17, 57, 47, 204, 51, 225,
  50, 1, 47, 51, 221, 93, 50, 225, 50, 16, 225, 93, 93, 50, 16, 206, 50, 47, 16,
  225, 18, 57, 47, 225, 48, 49, 1, 50, 22, 22, 18, 21, 21, 33, 30, 3, 51, 50,
  62, 2, 55, 21, 14, 3, 7, 17, 35, 17, 46, 3, 39, 38, 38, 53, 52, 54, 55, 51, 6,
  6, 21, 20, 51, 51, 62, 3, 23, 34, 14, 2, 7, 33, 52, 46, 2, 2, 221, 125, 160,
  93, 36, 253, 96, 5, 36, 75, 120, 90, 47, 79, 71, 65, 33, 30, 59, 67, 78, 49,
  176, 90, 130, 86, 46, 6, 144, 143, 17, 11, 156, 6, 14, 102, 21, 11, 60, 109,
  162, 110, 64, 92, 62, 33, 5, 1, 223, 16, 48, 87, 5, 205, 101, 189, 254, 241,
  170, 90, 122, 194, 134, 71, 12, 20, 28, 16, 170, 14, 23, 18, 12, 2, 254, 147,
  1, 125, 23, 111, 170, 226, 138, 3, 114, 122, 42, 66, 23, 15, 62, 35, 97, 154,
  244, 171, 91, 164, 65, 126, 185, 120, 117, 184, 128, 67, 0, 0, 2, 255, 213,
  254, 131, 4, 88, 4, 94, 0, 45, 0, 54, 0, 113, 64, 66, 20, 70, 21, 21, 27, 50,
  72, 6, 16, 16, 6, 56, 34, 149, 37, 1, 102, 37, 118, 37, 134, 37, 3, 37, 73,
  30, 49, 7, 72, 41, 31, 27, 47, 27, 2, 27, 33, 30, 64, 24, 27, 72, 30, 27, 7,
  80, 49, 33, 40, 40, 0, 15, 10, 81, 19, 22, 19, 20, 20, 16, 19, 22, 46, 80, 0,
  16, 0, 63, 225, 63, 51, 51, 47, 17, 51, 16, 225, 50, 17, 57, 47, 204, 51, 225,
  50, 1, 47, 43, 51, 221, 93, 50, 225, 50, 16, 225, 93, 93, 50, 16, 206, 50, 47,
  16, 225, 18, 57, 47, 225, 49, 48, 1, 50, 30, 2, 21, 21, 33, 22, 22, 51, 50,
  62, 2, 55, 21, 6, 6, 7, 17, 35, 17, 46, 3, 39, 38, 38, 53, 52, 54, 55, 51, 6,
  6, 21, 20, 22, 51, 51, 62, 3, 23, 34, 6, 7, 33, 52, 46, 2, 2, 174, 99, 158,
  110, 59, 253, 76, 5, 152, 152, 51, 87, 80, 77, 39, 66, 133, 78, 176, 84, 136,
  99, 57, 3, 133, 141, 17, 10, 149, 6, 14, 48, 50, 27, 14, 75, 117, 152, 86,
  115, 132, 11, 1, 235, 27, 56, 88, 4, 94, 71, 129, 181, 110, 113, 193, 182, 10,
  19, 29, 18, 162, 32, 34, 5, 254, 149, 1, 117, 17, 84, 132, 178, 111, 2, 111,
  114, 39, 63, 21, 14, 58, 34, 47, 49, 108, 170, 117, 61, 151, 156, 149, 68,
  113, 80, 44, 0, 255, 255, 0, 225, 0, 0, 3, 233, 5, 182, 2, 6, 0, 44, 0, 0,
  255, 255, 0, 0, 0, 0, 4, 205, 7, 105, 2, 38, 1, 176, 0, 0, 1, 7, 2, 54, 0, 0,
  1, 82, 0, 19, 64, 11, 1, 20, 5, 38, 1, 0, 23, 18, 17, 10, 37, 1, 43, 53, 0,
  43, 53, 0, 255, 255, 0, 0, 0, 0, 4, 205, 6, 23, 2, 38, 1, 208, 0, 0, 1, 6, 2,
  54, 0, 0, 0, 19, 64, 11, 1, 20, 17, 38, 1, 0, 23, 18, 16, 5, 37, 1, 43, 53, 0,
  43, 53, 0, 0, 1, 0, 135, 254, 0, 4, 88, 5, 182, 0, 37, 0, 88, 64, 49, 134, 11,
  1, 23, 11, 55, 11, 103, 11, 3, 119, 8, 1, 9, 10, 10, 33, 91, 17, 39, 11, 8, 4,
  90, 5, 27, 27, 0, 5, 1, 5, 8, 11, 97, 3, 0, 0, 4, 9, 6, 3, 28, 31, 95, 27, 22,
  22, 4, 18, 0, 63, 51, 47, 51, 225, 50, 63, 51, 18, 57, 47, 51, 225, 50, 1, 47,
  93, 51, 47, 16, 225, 50, 50, 16, 222, 225, 51, 47, 51, 48, 49, 0, 93, 1, 93,
  93, 1, 34, 6, 7, 17, 35, 17, 51, 17, 1, 51, 1, 51, 50, 30, 2, 21, 20, 14, 2,
  35, 34, 46, 2, 39, 53, 22, 22, 51, 32, 17, 52, 46, 2, 1, 240, 57, 82, 35, 187,
  187, 2, 53, 207, 253, 209, 6, 127, 210, 151, 83, 82, 146, 200, 119, 49, 78,
  68, 60, 31, 63, 126, 73, 1, 118, 69, 115, 152, 2, 125, 15, 14, 253, 160, 5,
  182, 253, 60, 2, 196, 253, 88, 81, 161, 237, 156, 170, 248, 162, 79, 6, 12,
  19, 12, 162, 23, 24, 1, 239, 129, 186, 119, 56, 0, 0, 1, 0, 215, 254, 10, 4,
  88, 4, 74, 0, 34, 0, 85, 64, 48, 34, 16, 25, 33, 1, 33, 34, 34, 20, 72, 5, 36,
  32, 22, 0, 54, 0, 70, 0, 3, 0, 28, 70, 29, 13, 13, 0, 29, 1, 29, 32, 0, 78,
  27, 25, 25, 29, 33, 30, 15, 14, 17, 81, 13, 10, 10, 29, 21, 0, 63, 51, 47, 51,
  225, 50, 63, 51, 18, 57, 47, 51, 225, 50, 1, 47, 93, 51, 47, 16, 225, 50, 93,
  50, 16, 222, 225, 51, 47, 51, 93, 56, 48, 49, 1, 30, 3, 21, 20, 14, 2, 35, 34,
  38, 39, 53, 22, 22, 51, 50, 54, 53, 52, 46, 2, 35, 34, 7, 17, 35, 17, 51, 17,
  1, 51, 2, 106, 100, 180, 135, 79, 74, 129, 176, 102, 76, 105, 47, 44, 105, 66,
  149, 157, 52, 97, 137, 85, 83, 75, 180, 180, 1, 228, 215, 2, 98, 2, 61, 130,
  207, 149, 150, 213, 136, 64, 31, 29, 161, 24, 37, 195, 210, 106, 152, 98, 46,
  29, 254, 76, 4, 74, 254, 6, 1, 250, 0, 1, 0, 4, 254, 127, 4, 203, 5, 182, 0,
  35, 0, 75, 64, 42, 12, 20, 7, 250, 29, 20, 0, 34, 144, 34, 160, 34, 3, 34, 34,
  5, 20, 3, 91, 2, 1, 5, 90, 0, 4, 1, 7, 95, 34, 3, 21, 24, 97, 20, 17, 19, 3,
  3, 0, 95, 5, 18, 0, 63, 225, 51, 47, 63, 51, 225, 50, 63, 225, 1, 47, 51, 221,
  225, 16, 221, 225, 47, 18, 57, 47, 93, 18, 57, 225, 17, 57, 48, 49, 37, 51, 3,
  35, 19, 35, 17, 35, 14, 3, 7, 14, 3, 35, 34, 38, 39, 53, 22, 22, 51, 50, 62,
  2, 55, 54, 54, 18, 18, 55, 33, 4, 8, 195, 144, 217, 166, 186, 236, 14, 32, 33,
  34, 16, 20, 53, 79, 110, 78, 35, 74, 28, 22, 59, 32, 48, 64, 42, 26, 10, 11,
  33, 39, 43, 22, 2, 65, 166, 253, 217, 1, 129, 5, 18, 113, 244, 236, 212, 81,
  103, 162, 111, 59, 14, 11, 150, 10, 15, 63, 98, 117, 54, 57, 200, 1, 6, 1, 58,
  170, 0, 1, 0, 31, 254, 131, 4, 174, 4, 74, 0, 24, 0, 63, 64, 33, 9, 15, 7, 73,
  20, 15, 23, 23, 5, 15, 3, 71, 2, 1, 5, 71, 0, 4, 1, 7, 80, 23, 15, 18, 79, 12,
  22, 3, 3, 0, 80, 5, 21, 0, 63, 225, 51, 47, 63, 225, 63, 225, 1, 47, 51, 221,
  225, 16, 221, 225, 47, 18, 57, 47, 18, 57, 225, 17, 57, 48, 49, 37, 51, 3, 35,
  19, 35, 17, 33, 2, 2, 6, 6, 35, 34, 38, 39, 53, 22, 51, 50, 54, 54, 18, 55,
  33, 3, 248, 182, 123, 182, 123, 182, 254, 196, 20, 64, 95, 130, 86, 28, 49,
  15, 21, 28, 55, 89, 69, 51, 18, 2, 142, 154, 253, 233, 1, 125, 3, 176, 254,
  253, 254, 148, 230, 105, 6, 6, 131, 6, 117, 241, 1, 111, 250, 0, 1, 0, 135,
  254, 0, 4, 70, 5, 182, 0, 27, 0, 78, 64, 46, 20, 12, 90, 23, 29, 19, 15, 90,
  16, 5, 5, 16, 16, 32, 16, 2, 32, 16, 48, 16, 2, 16, 14, 95, 152, 19, 1, 15,
  19, 47, 19, 2, 6, 19, 19, 16, 21, 17, 3, 16, 18, 6, 9, 95, 5, 0, 0, 47, 50,
  225, 50, 63, 63, 51, 18, 57, 47, 94, 93, 93, 225, 1, 47, 93, 113, 51, 47, 16,
  225, 50, 16, 222, 225, 50, 48, 49, 1, 34, 46, 2, 39, 53, 22, 22, 51, 50, 54,
  53, 17, 33, 17, 35, 17, 51, 17, 33, 17, 51, 17, 20, 14, 2, 2, 88, 45, 71, 61,
  54, 29, 56, 110, 63, 164, 174, 253, 183, 187, 187, 2, 73, 187, 74, 132, 181,
  254, 0, 6, 12, 19, 12, 162, 23, 24, 240, 247, 2, 31, 253, 86, 5, 182, 253,
  152, 2, 104, 250, 221, 170, 248, 162, 79, 0, 0, 1, 0, 160, 254, 10, 4, 45, 4,
  74, 0, 27, 0, 72, 64, 42, 20, 12, 71, 176, 23, 192, 23, 2, 23, 29, 19, 15, 71,
  16, 3, 3, 0, 16, 16, 16, 32, 16, 208, 16, 4, 7, 16, 14, 80, 19, 19, 16, 21,
  17, 15, 16, 21, 4, 7, 81, 3, 0, 0, 47, 50, 225, 50, 63, 63, 51, 18, 57, 47,
  225, 1, 47, 94, 93, 51, 47, 16, 225, 50, 16, 222, 93, 225, 50, 48, 49, 1, 34,
  38, 39, 53, 22, 22, 51, 50, 62, 2, 53, 17, 33, 17, 35, 17, 51, 17, 33, 17, 51,
  17, 20, 14, 2, 2, 145, 75, 105, 47, 43, 106, 66, 59, 91, 61, 31, 253, 223,
  182, 182, 2, 33, 182, 63, 111, 151, 254, 10, 31, 29, 161, 24, 37, 45, 97, 150,
  105, 1, 178, 254, 23, 4, 74, 254, 57, 1, 199, 251, 243, 150, 213, 136, 64, 0,
  0, 1, 0, 135, 254, 127, 4, 203, 5, 182, 0, 15, 0, 84, 64, 49, 12, 8, 90, 16,
  9, 32, 9, 2, 32, 9, 48, 9, 2, 9, 3, 91, 2, 1, 13, 5, 90, 0, 4, 1, 6, 95, 152,
  12, 1, 15, 12, 47, 12, 2, 6, 12, 12, 9, 14, 10, 3, 0, 5, 5, 9, 3, 3, 9, 18, 0,
  63, 51, 47, 17, 51, 16, 205, 63, 51, 18, 57, 47, 94, 93, 93, 225, 1, 47, 51,
  221, 225, 50, 16, 221, 225, 47, 93, 113, 225, 50, 48, 49, 37, 51, 3, 35, 19,
  35, 17, 33, 17, 35, 17, 51, 17, 33, 17, 51, 4, 8, 195, 144, 217, 166, 186,
  253, 244, 187, 187, 2, 12, 186, 166, 253, 217, 1, 129, 2, 170, 253, 86, 5,
  182, 253, 152, 2, 104, 0, 0, 1, 0, 160, 254, 131, 4, 174, 4, 74, 0, 15, 0, 73,
  64, 41, 14, 71, 13, 12, 8, 0, 71, 11, 15, 12, 7, 3, 71, 0, 4, 16, 4, 32, 4,
  208, 4, 4, 7, 4, 2, 80, 7, 7, 4, 9, 5, 15, 11, 80, 0, 0, 4, 14, 14, 4, 21, 0,
  63, 51, 47, 17, 51, 16, 225, 63, 51, 18, 57, 47, 225, 1, 47, 94, 93, 225, 50,
  47, 51, 221, 225, 50, 16, 221, 237, 48, 49, 33, 17, 33, 17, 35, 17, 51, 17,
  33, 17, 51, 17, 51, 3, 35, 19, 3, 66, 254, 20, 182, 182, 1, 236, 182, 182,
  123, 182, 123, 1, 233, 254, 23, 4, 74, 254, 57, 1, 199, 252, 80, 253, 233, 1,
  125, 0, 1, 0, 135, 254, 127, 4, 70, 5, 182, 0, 29, 0, 61, 64, 32, 28, 251, 27,
  27, 22, 0, 90, 25, 31, 12, 90, 0, 9, 1, 9, 1, 6, 95, 22, 17, 17, 10, 29, 95,
  26, 27, 27, 26, 18, 23, 10, 3, 0, 63, 51, 63, 51, 47, 16, 225, 17, 57, 47, 51,
  225, 50, 1, 47, 93, 225, 16, 222, 225, 50, 50, 47, 225, 48, 49, 37, 17, 14, 3,
  35, 34, 38, 53, 17, 51, 17, 20, 30, 2, 51, 50, 62, 2, 55, 17, 51, 17, 35, 17,
  35, 17, 3, 139, 57, 101, 94, 92, 49, 187, 192, 187, 20, 50, 82, 61, 45, 86,
  89, 96, 56, 187, 187, 176, 166, 1, 176, 22, 34, 22, 12, 191, 180, 2, 71, 253,
  209, 57, 87, 58, 29, 10, 20, 30, 20, 2, 198, 250, 74, 254, 127, 2, 39, 0, 1,
  0, 152, 254, 131, 4, 37, 4, 74, 0, 27, 0, 75, 64, 45, 25, 70, 24, 24, 19, 27,
  71, 176, 22, 1, 22, 29, 13, 71, 0, 10, 16, 10, 32, 10, 208, 10, 4, 7, 10, 5,
  80, 15, 16, 31, 16, 2, 16, 16, 11, 26, 80, 23, 24, 24, 23, 21, 20, 11, 15, 0,
  63, 51, 63, 51, 47, 16, 225, 17, 57, 47, 93, 225, 1, 47, 94, 93, 225, 16, 222,
  93, 225, 50, 50, 47, 225, 48, 49, 1, 14, 3, 35, 34, 46, 2, 53, 17, 51, 17, 20,
  22, 51, 50, 54, 55, 17, 51, 17, 35, 17, 35, 17, 51, 3, 111, 44, 87, 92, 101,
  57, 82, 129, 88, 47, 182, 105, 100, 89, 167, 84, 182, 166, 176, 160, 1, 233,
  30, 48, 32, 17, 47, 84, 115, 68, 1, 166, 254, 102, 88, 86, 58, 57, 1, 213,
  251, 182, 254, 131, 2, 23, 0, 0, 1, 0, 113, 254, 127, 4, 203, 5, 182, 0, 29,
  0, 219, 64, 60, 27, 14, 1, 10, 14, 1, 252, 14, 1, 237, 14, 1, 220, 14, 1, 185,
  14, 201, 14, 2, 138, 14, 154, 14, 170, 14, 3, 108, 14, 124, 14, 2, 91, 14, 1,
  58, 14, 74, 14, 2, 25, 14, 41, 14, 2, 3, 11, 19, 11, 2, 241, 11, 1, 226, 11,
  1, 212, 11, 1, 11, 184, 255, 232, 64, 88, 17, 21, 72, 99, 11, 115, 11, 2, 84,
  11, 1, 53, 11, 69, 11, 2, 22, 11, 38, 11, 2, 19, 251, 18, 17, 29, 0, 12, 12,
  8, 27, 22, 10, 14, 1, 14, 21, 250, 15, 16, 1, 191, 16, 207, 16, 223, 16, 3,
  16, 17, 5, 11, 1, 11, 7, 2, 8, 250, 0, 9, 16, 9, 2, 9, 16, 95, 21, 18, 28, 14,
  2, 11, 3, 5, 12, 1, 3, 12, 13, 0, 1, 1, 0, 8, 19, 19, 8, 18, 0, 63, 51, 47,
  17, 51, 95, 93, 50, 95, 93, 63, 51, 51, 51, 63, 225, 1, 47, 93, 225, 50, 50,
  50, 93, 47, 221, 93, 113, 225, 50, 93, 50, 50, 17, 57, 17, 51, 51, 16, 221,
  237, 48, 49, 93, 93, 93, 93, 43, 93, 93, 93, 113, 93, 93, 93, 93, 93, 93, 93,
  93, 93, 113, 113, 33, 1, 35, 22, 23, 22, 22, 21, 17, 35, 17, 51, 19, 51, 19,
  51, 17, 51, 3, 35, 19, 35, 17, 52, 54, 55, 54, 55, 35, 1, 1, 254, 254, 250, 8,
  5, 4, 4, 5, 145, 237, 236, 6, 239, 242, 154, 185, 176, 166, 108, 4, 3, 4, 3,
  8, 254, 248, 5, 0, 74, 73, 63, 139, 57, 252, 150, 5, 182, 251, 88, 4, 168,
  250, 240, 253, 217, 1, 129, 3, 119, 52, 134, 61, 71, 73, 251, 2, 0, 1, 0, 115,
  254, 131, 4, 174, 4, 74, 0, 36, 0, 204, 64, 140, 184, 36, 200, 36, 216, 36, 3,
  153, 36, 169, 36, 2, 138, 36, 1, 105, 36, 1, 90, 36, 1, 72, 36, 1, 41, 36, 57,
  36, 2, 26, 36, 1, 9, 36, 1, 213, 24, 1, 198, 24, 1, 165, 24, 181, 24, 2, 150,
  24, 1, 85, 24, 101, 24, 133, 24, 3, 70, 24, 1, 55, 24, 1, 38, 24, 1, 21, 24,
  1, 6, 24, 1, 8, 15, 1, 8, 14, 1, 7, 13, 1, 7, 12, 1, 3, 14, 13, 30, 30, 6, 24,
  21, 73, 4, 22, 20, 22, 36, 22, 3, 22, 4, 3, 2, 36, 6, 73, 1, 5, 123, 2, 203,
  2, 219, 2, 235, 2, 4, 2, 7, 36, 36, 20, 24, 15, 30, 14, 15, 14, 1, 2, 14, 21,
  4, 4, 21, 21, 1, 80, 6, 21, 0, 63, 225, 63, 51, 47, 17, 51, 95, 93, 17, 51,
  63, 51, 51, 17, 51, 1, 47, 93, 51, 221, 225, 50, 16, 221, 205, 47, 93, 225,
  50, 17, 57, 17, 51, 51, 48, 49, 95, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93,
  93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 1, 17, 51, 3, 35, 19, 35,
  17, 14, 3, 7, 3, 35, 3, 46, 3, 39, 17, 35, 17, 51, 19, 30, 3, 23, 62, 3, 55,
  19, 4, 29, 145, 123, 168, 123, 123, 4, 16, 17, 17, 5, 199, 131, 196, 4, 16,
  18, 18, 6, 145, 204, 197, 10, 21, 18, 15, 4, 5, 14, 17, 19, 10, 203, 4, 74,
  252, 80, 253, 233, 1, 125, 3, 129, 21, 69, 74, 68, 18, 253, 121, 2, 135, 14,
  62, 73, 75, 26, 252, 127, 4, 74, 253, 112, 34, 81, 75, 62, 16, 17, 61, 74, 78,
  34, 2, 148, 0, 255, 255, 0, 225, 0, 0, 3, 233, 5, 182, 2, 6, 0, 44, 0, 0, 255,
  255, 0, 33, 0, 0, 4, 172, 7, 105, 2, 38, 0, 36, 0, 0, 1, 7, 2, 54, 255, 255,
  1, 82, 0, 21, 180, 2, 17, 5, 38, 2, 184, 255, 255, 180, 20, 15, 4, 7, 37, 1,
  43, 53, 0, 43, 53, 0, 255, 255, 0, 135, 255, 236, 4, 2, 6, 23, 2, 38, 0, 68,
  0, 0, 1, 6, 2, 54, 4, 0, 0, 19, 64, 11, 2, 36, 17, 38, 2, 37, 39, 34, 8, 22,
  37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 33, 0, 0, 4, 172, 7, 43, 2, 38, 0,
  36, 0, 0, 1, 7, 0, 106, 0, 0, 1, 82, 0, 25, 182, 3, 2, 19, 5, 38, 3, 2, 184,
  255, 255, 180, 21, 25, 4, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0,
  135, 255, 236, 4, 2, 5, 217, 2, 38, 0, 68, 0, 0, 1, 6, 0, 106, 12, 0, 0, 23,
  64, 13, 3, 2, 38, 17, 38, 3, 2, 45, 40, 44, 8, 22, 37, 1, 43, 53, 53, 0, 43,
  53, 53, 0, 255, 255, 0, 0, 0, 0, 4, 186, 5, 182, 2, 6, 0, 136, 0, 0, 255, 255,
  0, 45, 255, 236, 4, 162, 4, 94, 2, 6, 0, 168, 0, 0, 255, 255, 0, 217, 0, 0, 4,
  35, 7, 105, 2, 38, 0, 40, 0, 0, 1, 7, 2, 54, 0, 23, 1, 82, 0, 21, 180, 1, 14,
  5, 38, 1, 184, 255, 255, 180, 17, 12, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 133, 255, 236, 4, 72, 6, 23, 2, 38, 0, 72, 0, 0, 1, 6, 2, 54, 16, 0,
  0, 19, 64, 11, 2, 25, 17, 38, 2, 15, 28, 23, 11, 0, 37, 1, 43, 53, 0, 43, 53,
  0, 0, 2, 0, 84, 255, 236, 4, 123, 5, 205, 0, 30, 0, 41, 0, 63, 64, 36, 36, 26,
  91, 14, 43, 37, 91, 24, 32, 3, 48, 3, 2, 3, 3, 31, 24, 47, 24, 2, 24, 37, 95,
  25, 25, 9, 31, 95, 19, 19, 3, 0, 95, 4, 9, 4, 0, 63, 51, 225, 50, 63, 225, 17,
  57, 47, 225, 1, 47, 93, 51, 47, 93, 16, 225, 16, 222, 225, 50, 48, 49, 1, 34,
  6, 7, 53, 62, 3, 51, 50, 22, 22, 18, 21, 20, 2, 6, 6, 35, 34, 38, 38, 2, 53,
  53, 33, 46, 3, 3, 50, 62, 2, 55, 33, 30, 3, 2, 35, 111, 179, 79, 38, 80, 93,
  111, 67, 141, 217, 147, 75, 73, 141, 208, 135, 137, 192, 122, 55, 3, 98, 6,
  55, 100, 145, 48, 77, 125, 90, 54, 6, 253, 99, 2, 35, 75, 119, 5, 41, 44, 32,
  170, 15, 26, 19, 10, 108, 198, 254, 233, 171, 174, 254, 235, 194, 104, 103,
  192, 1, 17, 171, 82, 122, 193, 134, 71, 251, 102, 65, 126, 185, 120, 117, 184,
  127, 68, 0, 0, 2, 0, 133, 255, 236, 4, 72, 4, 94, 0, 30, 0, 39, 0, 73, 64, 43,
  34, 17, 72, 15, 5, 1, 255, 5, 1, 5, 41, 35, 72, 15, 25, 25, 0, 15, 1, 0, 15,
  16, 15, 240, 15, 3, 8, 15, 35, 80, 16, 16, 0, 31, 80, 10, 22, 25, 20, 81, 26,
  0, 16, 0, 63, 50, 225, 50, 63, 225, 17, 57, 47, 225, 1, 47, 94, 93, 113, 51,
  47, 16, 225, 16, 222, 93, 113, 225, 50, 49, 48, 1, 50, 30, 2, 21, 20, 14, 2,
  35, 34, 46, 2, 53, 53, 33, 38, 38, 35, 34, 14, 2, 7, 53, 62, 3, 19, 50, 54,
  55, 33, 20, 30, 2, 2, 45, 119, 198, 143, 79, 72, 131, 184, 111, 108, 173, 120,
  64, 3, 6, 5, 171, 168, 56, 97, 89, 84, 44, 43, 83, 87, 96, 100, 133, 156, 12,
  253, 195, 32, 66, 103, 4, 94, 74, 142, 210, 135, 136, 214, 148, 79, 71, 129,
  181, 110, 113, 193, 181, 10, 19, 28, 18, 159, 20, 28, 19, 9, 252, 37, 156,
  149, 68, 113, 80, 44, 0, 255, 255, 0, 84, 255, 236, 4, 123, 7, 43, 2, 38, 2,
  225, 0, 0, 1, 7, 0, 106, 0, 2, 1, 82, 0, 23, 64, 13, 3, 2, 46, 5, 38, 3, 2, 0,
  48, 52, 24, 14, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 133, 255,
  236, 4, 72, 5, 217, 2, 38, 2, 226, 0, 0, 1, 6, 0, 106, 2, 0, 0, 23, 64, 13, 3,
  2, 44, 17, 38, 3, 2, 1, 46, 50, 15, 5, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0,
  255, 255, 0, 0, 0, 0, 4, 205, 7, 43, 2, 38, 1, 176, 0, 0, 1, 7, 0, 106, 0, 0,
  1, 82, 0, 25, 182, 2, 1, 22, 5, 38, 2, 1, 184, 255, 255, 180, 24, 28, 17, 10,
  37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 0, 0, 0, 4, 205, 5, 217, 2,
  38, 1, 208, 0, 0, 1, 6, 0, 106, 0, 0, 0, 25, 182, 2, 1, 22, 17, 38, 2, 1, 184,
  255, 255, 180, 24, 28, 16, 5, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255,
  0, 139, 255, 236, 4, 47, 7, 43, 2, 38, 1, 177, 0, 0, 1, 7, 0, 106, 255, 237,
  1, 82, 0, 25, 182, 2, 1, 40, 5, 38, 2, 1, 184, 255, 246, 180, 42, 46, 9, 4,
  37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 201, 255, 236, 4, 8, 5, 217,
  2, 38, 1, 209, 0, 0, 1, 6, 0, 106, 253, 0, 0, 25, 182, 2, 1, 37, 17, 38, 2, 1,
  184, 255, 250, 180, 39, 43, 8, 18, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 0, 1,
  0, 158, 255, 236, 4, 66, 5, 182, 0, 32, 0, 75, 64, 41, 87, 0, 1, 70, 0, 1, 28,
  91, 32, 32, 5, 0, 91, 26, 26, 13, 22, 5, 34, 29, 29, 0, 13, 1, 13, 32, 29, 95,
  30, 0, 97, 26, 26, 30, 3, 14, 19, 96, 13, 10, 19, 0, 63, 51, 225, 50, 63, 57,
  47, 225, 16, 225, 50, 1, 47, 93, 51, 47, 16, 222, 193, 17, 57, 47, 225, 17,
  51, 47, 225, 48, 49, 93, 93, 1, 30, 3, 21, 20, 14, 2, 35, 34, 38, 39, 53, 30,
  3, 51, 50, 54, 53, 52, 38, 35, 35, 53, 1, 33, 53, 33, 21, 2, 74, 115, 186,
  132, 71, 67, 136, 205, 137, 110, 192, 85, 43, 96, 99, 99, 46, 178, 176, 207,
  186, 123, 1, 166, 253, 166, 3, 61, 3, 59, 4, 54, 100, 151, 102, 96, 160, 116,
  64, 34, 45, 170, 23, 36, 24, 13, 148, 135, 135, 129, 151, 1, 209, 166, 145, 0,
  0, 1, 0, 170, 254, 20, 4, 59, 4, 74, 0, 36, 0, 70, 64, 38, 32, 74, 36, 36, 5,
  0, 74, 0, 30, 1, 30, 30, 13, 24, 70, 5, 38, 33, 0, 13, 1, 13, 31, 0, 78, 30,
  30, 19, 33, 80, 34, 15, 14, 19, 80, 13, 10, 27, 0, 63, 51, 225, 50, 63, 225,
  18, 57, 47, 225, 50, 1, 47, 93, 51, 16, 222, 225, 17, 57, 47, 93, 225, 17, 51,
  47, 225, 48, 49, 1, 30, 3, 21, 20, 14, 2, 35, 34, 38, 39, 55, 30, 3, 51, 50,
  62, 2, 53, 52, 46, 2, 35, 35, 53, 1, 33, 53, 33, 21, 2, 72, 104, 182, 135, 78,
  76, 139, 198, 123, 122, 193, 62, 2, 33, 84, 98, 111, 59, 77, 128, 92, 51, 59,
  108, 151, 91, 119, 1, 182, 253, 150, 3, 61, 1, 213, 7, 64, 114, 164, 108, 110,
  185, 134, 75, 36, 34, 166, 16, 31, 24, 15, 48, 89, 127, 78, 86, 123, 80, 37,
  125, 1, 237, 154, 133, 0, 255, 255, 0, 137, 0, 0, 4, 70, 6, 193, 2, 38, 1,
  178, 0, 0, 1, 7, 1, 77, 0, 2, 1, 82, 0, 19, 64, 11, 1, 19, 5, 38, 1, 0, 17,
  18, 0, 8, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160, 0, 0, 4, 45, 5, 111,
  2, 38, 1, 210, 0, 0, 1, 6, 1, 77, 2, 0, 0, 19, 64, 11, 1, 14, 17, 38, 1, 1,
  12, 13, 10, 4, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 137, 0, 0, 4, 70, 7,
  43, 2, 38, 1, 178, 0, 0, 1, 7, 0, 106, 0, 2, 1, 82, 0, 23, 64, 13, 2, 1, 21,
  5, 38, 2, 1, 0, 23, 27, 0, 8, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255,
  0, 160, 0, 0, 4, 45, 5, 217, 2, 38, 1, 210, 0, 0, 1, 6, 0, 106, 2, 0, 0, 23,
  64, 13, 2, 1, 16, 17, 38, 2, 1, 1, 18, 22, 10, 4, 37, 1, 43, 53, 53, 0, 43,
  53, 53, 0, 255, 255, 0, 84, 255, 236, 4, 123, 7, 43, 2, 38, 0, 50, 0, 0, 1, 7,
  0, 106, 0, 2, 1, 82, 0, 23, 64, 13, 3, 2, 24, 5, 38, 3, 2, 0, 26, 30, 2, 7,
  37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 115, 255, 236, 4, 88, 5,
  217, 2, 38, 0, 82, 0, 0, 1, 6, 0, 106, 249, 0, 0, 25, 182, 3, 2, 24, 17, 38,
  3, 2, 184, 255, 249, 180, 26, 30, 3, 9, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0,
  255, 255, 0, 84, 255, 236, 4, 123, 5, 205, 2, 6, 2, 126, 0, 0, 255, 255, 0,
  115, 255, 236, 4, 88, 4, 94, 2, 6, 2, 127, 0, 0, 255, 255, 0, 84, 255, 236, 4,
  123, 7, 43, 2, 38, 2, 126, 0, 0, 1, 7, 0, 106, 0, 2, 1, 82, 0, 23, 64, 13, 4,
  3, 46, 5, 38, 4, 3, 0, 48, 52, 10, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0,
  255, 255, 0, 115, 255, 236, 4, 88, 5, 217, 2, 38, 2, 127, 0, 0, 1, 6, 0, 106,
  249, 0, 0, 25, 182, 4, 3, 35, 17, 38, 4, 3, 184, 255, 249, 180, 37, 41, 10, 0,
  37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 68, 255, 236, 4, 76, 7, 43,
  2, 38, 1, 199, 0, 0, 1, 7, 0, 106, 255, 136, 1, 82, 0, 25, 182, 2, 1, 28, 5,
  38, 2, 1, 184, 255, 166, 180, 30, 34, 1, 6, 37, 1, 43, 53, 53, 0, 43, 53, 53,
  0, 255, 255, 0, 184, 255, 236, 4, 37, 5, 217, 2, 38, 1, 231, 0, 0, 1, 6, 0,
  106, 208, 0, 0, 25, 182, 2, 1, 27, 17, 38, 2, 1, 184, 255, 199, 180, 29, 33,
  13, 18, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 27, 255, 236, 4,
  176, 6, 193, 2, 38, 1, 189, 0, 0, 1, 7, 1, 77, 0, 8, 1, 82, 0, 19, 64, 11, 1,
  26, 5, 38, 1, 8, 24, 25, 14, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 82,
  254, 20, 4, 121, 5, 111, 2, 38, 0, 92, 0, 0, 1, 6, 1, 77, 2, 0, 0, 19, 64, 11,
  1, 25, 17, 38, 1, 2, 23, 24, 0, 9, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  27, 255, 236, 4, 176, 7, 43, 2, 38, 1, 189, 0, 0, 1, 7, 0, 106, 255, 255, 1,
  82, 0, 25, 182, 2, 1, 28, 5, 38, 2, 1, 184, 255, 255, 180, 30, 34, 14, 0, 37,
  1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 82, 254, 20, 4, 121, 5, 217, 2,
  38, 0, 92, 0, 0, 1, 6, 0, 106, 8, 0, 0, 23, 64, 13, 2, 1, 27, 17, 38, 2, 1, 8,
  29, 33, 0, 9, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 27, 255, 236,
  4, 176, 7, 115, 2, 38, 1, 189, 0, 0, 1, 7, 1, 83, 0, 82, 1, 82, 0, 23, 64, 13,
  2, 1, 30, 5, 38, 2, 1, 82, 24, 35, 14, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0,
  255, 255, 0, 82, 254, 20, 4, 121, 6, 33, 2, 38, 0, 92, 0, 0, 1, 6, 1, 83, 94,
  0, 0, 23, 64, 13, 2, 1, 29, 17, 38, 2, 1, 94, 23, 34, 0, 9, 37, 1, 43, 53, 53,
  0, 43, 53, 53, 0, 255, 255, 0, 135, 0, 0, 4, 70, 7, 43, 2, 38, 1, 193, 0, 0,
  1, 7, 0, 106, 0, 2, 1, 82, 0, 23, 64, 13, 2, 1, 21, 5, 38, 2, 1, 1, 23, 27, 6,
  0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 152, 0, 0, 4, 37, 5, 217,
  2, 38, 1, 225, 0, 0, 1, 6, 0, 106, 251, 0, 0, 23, 64, 13, 2, 1, 21, 17, 38, 2,
  1, 2, 23, 27, 15, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 0, 1, 1, 43, 254,
  127, 4, 100, 5, 182, 0, 9, 0, 56, 64, 35, 0, 11, 5, 251, 6, 6, 3, 90, 0, 8, 1,
  0, 8, 32, 8, 48, 8, 144, 8, 160, 8, 240, 8, 6, 8, 2, 95, 9, 3, 5, 5, 3, 95, 8,
  18, 0, 63, 225, 51, 47, 63, 225, 1, 47, 93, 113, 225, 50, 47, 225, 16, 206,
  49, 48, 1, 21, 33, 17, 51, 17, 35, 17, 35, 17, 4, 100, 253, 129, 177, 177,
  186, 5, 182, 166, 251, 150, 253, 217, 1, 129, 5, 182, 0, 1, 1, 35, 254, 131,
  4, 14, 4, 74, 0, 9, 0, 46, 64, 26, 2, 11, 7, 70, 8, 8, 5, 71, 0, 0, 144, 0,
  160, 0, 3, 0, 4, 80, 1, 15, 7, 7, 5, 80, 0, 21, 0, 63, 225, 51, 47, 63, 225,
  1, 47, 93, 225, 50, 47, 225, 16, 206, 48, 49, 33, 17, 33, 21, 33, 17, 51, 17,
  35, 17, 1, 35, 2, 235, 253, 203, 160, 176, 4, 74, 154, 252, 234, 253, 233, 1,
  125, 0, 255, 255, 0, 96, 0, 0, 4, 109, 7, 43, 2, 38, 1, 197, 0, 0, 1, 7, 0,
  106, 0, 2, 1, 82, 0, 23, 64, 13, 4, 3, 26, 5, 38, 4, 3, 1, 28, 32, 0, 20, 37,
  1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 113, 0, 0, 4, 90, 5, 217, 2, 38,
  1, 229, 0, 0, 1, 6, 0, 106, 2, 0, 0, 23, 64, 13, 4, 3, 25, 17, 38, 4, 3, 2,
  27, 31, 6, 17, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 0, 1, 0, 147, 254, 109, 4,
  100, 5, 182, 0, 29, 0, 72, 64, 38, 15, 4, 1, 4, 4, 7, 0, 31, 16, 9, 250, 23,
  23, 2, 7, 90, 28, 26, 24, 19, 6, 26, 95, 3, 27, 27, 7, 2, 95, 29, 3, 7, 95,
  24, 18, 19, 96, 12, 0, 47, 225, 63, 225, 63, 225, 18, 57, 47, 51, 225, 50, 1,
  47, 47, 206, 51, 225, 50, 50, 47, 225, 206, 16, 206, 17, 57, 47, 93, 48, 49,
  1, 21, 33, 17, 33, 21, 33, 17, 51, 17, 20, 6, 35, 34, 38, 39, 53, 22, 22, 51,
  50, 54, 53, 53, 35, 17, 35, 53, 51, 17, 4, 100, 253, 129, 1, 80, 254, 176,
  156, 110, 125, 39, 63, 21, 14, 58, 34, 47, 49, 186, 152, 152, 5, 182, 166,
  254, 21, 162, 254, 35, 254, 217, 132, 142, 17, 9, 150, 7, 14, 49, 49, 150, 2,
  131, 162, 2, 145, 0, 0, 1, 0, 135, 254, 109, 4, 14, 4, 74, 0, 29, 0, 72, 64,
  37, 10, 10, 13, 6, 31, 25, 22, 15, 73, 29, 29, 9, 13, 71, 4, 2, 0, 22, 25, 80,
  21, 18, 12, 2, 79, 9, 3, 3, 13, 8, 80, 5, 15, 13, 81, 0, 21, 0, 63, 225, 63,
  225, 18, 57, 47, 51, 225, 50, 47, 51, 225, 50, 1, 47, 206, 51, 225, 50, 50,
  47, 225, 206, 47, 16, 206, 17, 57, 47, 48, 49, 33, 17, 35, 53, 51, 17, 33, 21,
  33, 17, 33, 21, 33, 17, 51, 17, 20, 6, 35, 34, 38, 39, 53, 22, 22, 51, 50, 54,
  53, 53, 1, 35, 156, 156, 2, 235, 253, 203, 1, 23, 254, 233, 156, 110, 126, 38,
  63, 22, 14, 59, 34, 46, 50, 1, 225, 137, 1, 224, 154, 254, 186, 137, 254, 197,
  254, 217, 132, 142, 17, 9, 150, 7, 14, 49, 49, 150, 255, 255, 0, 53, 254, 109,
  4, 205, 5, 182, 2, 38, 0, 59, 0, 0, 1, 7, 3, 128, 1, 180, 0, 0, 0, 23, 182, 1,
  1, 0, 21, 176, 21, 2, 184, 1, 180, 180, 21, 12, 4, 0, 37, 1, 43, 93, 53, 0,
  53, 0, 255, 255, 0, 96, 254, 109, 4, 119, 4, 74, 2, 38, 0, 91, 0, 0, 1, 7, 3,
  129, 1, 94, 0, 0, 0, 30, 181, 1, 1, 80, 21, 1, 21, 184, 255, 192, 178, 9, 12,
  54, 184, 1, 94, 180, 21, 12, 11, 7, 37, 1, 43, 43, 93, 53, 0, 53, 0, 1, 0, 53,
  0, 0, 4, 150, 5, 182, 0, 17, 0, 164, 185, 0, 11, 255, 248, 64, 23, 12, 15, 72,
  6, 11, 22, 11, 38, 11, 3, 13, 8, 12, 15, 72, 9, 13, 25, 13, 41, 13, 3, 4, 184,
  255, 248, 64, 32, 12, 15, 72, 6, 4, 22, 4, 38, 4, 3, 2, 8, 12, 15, 72, 9, 2,
  25, 2, 41, 2, 3, 15, 9, 6, 3, 0, 12, 12, 14, 11, 10, 184, 255, 240, 64, 10,
  10, 10, 5, 7, 17, 7, 17, 1, 4, 5, 184, 255, 240, 64, 25, 5, 13, 14, 16, 14,
  14, 2, 1, 16, 1, 3, 0, 7, 95, 15, 12, 8, 8, 1, 13, 10, 3, 5, 1, 18, 0, 63, 51,
  63, 51, 18, 57, 47, 51, 51, 225, 50, 50, 1, 47, 56, 51, 51, 47, 56, 51, 47,
  56, 51, 18, 57, 57, 47, 47, 17, 51, 47, 56, 51, 18, 57, 17, 51, 51, 51, 51,
  51, 93, 43, 93, 43, 93, 43, 93, 43, 48, 49, 1, 1, 35, 1, 1, 35, 1, 33, 53, 33,
  1, 51, 1, 1, 51, 1, 33, 21, 2, 250, 1, 156, 211, 254, 157, 254, 146, 189, 1,
  154, 254, 223, 1, 21, 254, 145, 199, 1, 75, 1, 78, 191, 254, 141, 1, 29, 2,
  180, 253, 76, 2, 123, 253, 133, 2, 180, 162, 2, 96, 253, 209, 2, 47, 253, 160,
  162, 0, 1, 0, 96, 0, 0, 4, 106, 4, 74, 0, 17, 0, 194, 183, 196, 14, 212, 14,
  228, 14, 3, 14, 184, 255, 240, 64, 36, 11, 14, 72, 203, 12, 219, 12, 235, 12,
  3, 12, 16, 11, 14, 72, 203, 5, 219, 5, 235, 5, 3, 5, 16, 11, 14, 72, 196, 3,
  212, 3, 228, 3, 3, 6, 3, 184, 255, 240, 64, 20, 11, 14, 72, 73, 13, 1, 13, 16,
  18, 23, 72, 10, 13, 26, 13, 2, 70, 4, 1, 4, 184, 255, 240, 64, 55, 18, 23, 72,
  5, 4, 21, 4, 2, 17, 9, 17, 9, 15, 11, 16, 13, 10, 7, 1, 4, 4, 6, 3, 2, 2, 14,
  31, 15, 1, 15, 5, 6, 6, 12, 0, 11, 16, 11, 2, 11, 13, 10, 17, 79, 7, 4, 0, 0,
  2, 15, 11, 21, 5, 2, 15, 0, 63, 51, 63, 51, 18, 57, 47, 51, 51, 225, 50, 50,
  1, 47, 93, 51, 51, 47, 51, 47, 93, 51, 51, 47, 51, 18, 57, 17, 51, 51, 51, 51,
  51, 17, 18, 57, 57, 47, 47, 48, 49, 0, 93, 43, 93, 93, 43, 93, 1, 43, 95, 93,
  43, 93, 43, 93, 43, 93, 19, 33, 1, 51, 1, 1, 51, 1, 33, 21, 33, 1, 35, 1, 1,
  35, 1, 33, 166, 1, 41, 254, 166, 207, 1, 34, 1, 35, 207, 254, 164, 1, 45, 254,
  207, 1, 114, 206, 254, 202, 254, 201, 207, 1, 115, 254, 211, 2, 123, 1, 207,
  254, 102, 1, 154, 254, 49, 137, 254, 14, 1, 180, 254, 76, 1, 242, 0, 2, 0,
  137, 0, 0, 3, 246, 5, 182, 0, 14, 0, 25, 0, 42, 64, 22, 6, 25, 90, 9, 27, 21,
  91, 0, 0, 1, 0, 16, 95, 5, 5, 7, 24, 96, 10, 18, 7, 3, 0, 63, 63, 225, 17, 57,
  47, 225, 1, 47, 93, 225, 16, 222, 225, 50, 48, 49, 19, 52, 62, 2, 51, 51, 17,
  51, 17, 33, 34, 46, 2, 1, 35, 34, 14, 2, 21, 20, 22, 51, 51, 137, 55, 127,
  207, 152, 149, 187, 254, 149, 133, 194, 126, 61, 2, 178, 129, 93, 138, 91, 46,
  163, 175, 159, 1, 172, 87, 152, 113, 66, 2, 104, 250, 74, 61, 112, 158, 1, 95,
  27, 60, 97, 70, 136, 132, 0, 255, 255, 0, 137, 255, 236, 4, 47, 6, 20, 2, 6,
  0, 71, 0, 0, 0, 2, 0, 49, 255, 236, 4, 131, 5, 182, 0, 33, 0, 48, 0, 61, 64,
  33, 9, 24, 251, 21, 48, 48, 15, 32, 251, 15, 1, 63, 1, 2, 1, 50, 40, 90, 15,
  35, 95, 33, 20, 20, 22, 3, 27, 9, 43, 96, 6, 12, 19, 0, 63, 51, 225, 50, 50,
  63, 57, 47, 51, 225, 1, 47, 225, 16, 222, 93, 225, 17, 57, 47, 51, 225, 57,
  49, 48, 1, 17, 20, 14, 2, 35, 34, 38, 39, 6, 6, 35, 34, 38, 53, 52, 62, 2, 51,
  51, 17, 51, 17, 20, 22, 51, 50, 62, 2, 53, 17, 5, 35, 34, 14, 2, 21, 20, 22,
  51, 50, 62, 2, 53, 4, 131, 30, 67, 109, 79, 92, 109, 34, 35, 122, 97, 165,
  167, 49, 104, 161, 112, 82, 174, 65, 68, 30, 44, 29, 14, 254, 88, 80, 66, 94,
  60, 28, 78, 94, 48, 60, 35, 13, 3, 80, 254, 24, 84, 140, 101, 55, 87, 87, 79,
  93, 209, 215, 103, 163, 114, 60, 2, 104, 251, 178, 114, 103, 23, 51, 83, 60,
  1, 232, 166, 30, 67, 107, 77, 128, 130, 35, 60, 79, 43, 0, 0, 2, 0, 49, 255,
  236, 4, 131, 6, 20, 0, 44, 0, 61, 0, 62, 64, 33, 14, 40, 70, 37, 50, 50, 23,
  3, 70, 15, 6, 1, 6, 63, 59, 70, 23, 31, 56, 80, 28, 16, 4, 4, 38, 0, 14, 0,
  45, 80, 11, 20, 22, 0, 63, 51, 225, 50, 50, 63, 57, 47, 63, 225, 50, 1, 47,
  225, 16, 222, 93, 225, 17, 57, 47, 51, 225, 57, 48, 49, 37, 50, 54, 53, 17,
  51, 17, 20, 14, 2, 35, 34, 38, 39, 35, 14, 3, 35, 34, 2, 17, 52, 62, 2, 51,
  50, 22, 23, 51, 38, 39, 38, 38, 53, 17, 51, 17, 20, 30, 2, 33, 50, 62, 2, 55,
  53, 52, 46, 2, 35, 34, 6, 21, 20, 22, 3, 88, 66, 59, 174, 34, 68, 101, 67,
  110, 129, 34, 4, 19, 43, 60, 83, 59, 154, 141, 42, 77, 107, 65, 82, 104, 31,
  8, 2, 2, 2, 2, 174, 9, 26, 50, 254, 85, 46, 63, 39, 19, 1, 17, 39, 64, 48, 83,
  77, 77, 131, 124, 130, 1, 59, 254, 193, 105, 152, 98, 46, 99, 103, 41, 74, 55,
  32, 1, 30, 1, 25, 141, 214, 144, 72, 74, 65, 34, 31, 26, 55, 16, 1, 159, 251,
  146, 61, 107, 78, 45, 46, 94, 141, 94, 41, 101, 157, 107, 55, 217, 205, 209,
  205, 0, 1, 0, 35, 255, 236, 4, 84, 5, 203, 0, 57, 0, 80, 64, 42, 37, 251, 0,
  0, 31, 26, 251, 11, 11, 18, 45, 251, 15, 48, 1, 48, 59, 17, 18, 6, 6, 18, 31,
  6, 97, 7, 46, 46, 7, 7, 21, 42, 95, 53, 19, 18, 17, 17, 14, 96, 21, 4, 0, 63,
  225, 50, 17, 51, 63, 225, 17, 57, 47, 51, 47, 16, 225, 57, 1, 47, 51, 47, 17,
  51, 16, 222, 93, 225, 17, 57, 47, 225, 51, 51, 47, 225, 48, 49, 1, 52, 46, 2,
  35, 35, 53, 51, 50, 54, 53, 52, 38, 35, 34, 6, 7, 39, 54, 54, 51, 50, 30, 2,
  21, 20, 14, 2, 7, 21, 30, 3, 21, 20, 30, 2, 51, 50, 54, 53, 17, 51, 17, 20,
  14, 2, 35, 34, 46, 2, 1, 254, 16, 42, 72, 56, 156, 156, 83, 91, 88, 86, 60,
  94, 53, 82, 65, 151, 103, 81, 121, 79, 39, 30, 56, 80, 49, 57, 84, 56, 28, 14,
  31, 47, 33, 66, 59, 174, 40, 77, 109, 69, 69, 112, 79, 43, 1, 135, 77, 109,
  70, 33, 151, 134, 125, 124, 115, 33, 41, 117, 54, 57, 54, 97, 133, 79, 73,
  116, 85, 58, 16, 6, 13, 51, 83, 121, 84, 74, 103, 65, 29, 115, 133, 1, 201,
  254, 45, 107, 152, 97, 45, 38, 94, 159, 0, 1, 0, 43, 255, 236, 4, 94, 4, 92,
  0, 57, 0, 71, 64, 37, 37, 26, 70, 31, 0, 11, 11, 18, 45, 70, 15, 48, 1, 48,
  59, 17, 18, 6, 6, 18, 31, 6, 80, 46, 7, 7, 21, 42, 81, 53, 22, 17, 14, 78, 18,
  21, 16, 0, 63, 51, 225, 50, 63, 225, 17, 57, 47, 196, 225, 57, 1, 47, 51, 47,
  17, 51, 16, 222, 93, 225, 17, 57, 47, 51, 51, 225, 50, 48, 49, 1, 46, 3, 35,
  35, 53, 51, 50, 54, 53, 52, 38, 35, 34, 6, 7, 39, 54, 54, 51, 50, 30, 2, 21,
  20, 14, 2, 7, 21, 30, 3, 23, 30, 3, 51, 50, 54, 53, 17, 51, 17, 20, 14, 2, 35,
  34, 46, 2, 2, 10, 3, 18, 41, 70, 56, 139, 139, 83, 91, 75, 87, 66, 113, 63,
  61, 65, 156, 101, 81, 120, 79, 39, 30, 56, 80, 49, 53, 81, 56, 31, 4, 3, 15,
  29, 45, 33, 66, 59, 174, 40, 76, 110, 69, 69, 107, 76, 43, 1, 27, 56, 80, 51,
  24, 153, 86, 80, 82, 74, 36, 32, 141, 36, 38, 42, 73, 100, 57, 55, 86, 64, 43,
  14, 4, 6, 30, 56, 85, 61, 54, 75, 47, 21, 115, 133, 1, 53, 254, 193, 107, 152,
  97, 45, 28, 69, 117, 0, 1, 0, 39, 254, 127, 4, 117, 5, 203, 0, 49, 0, 80, 64,
  43, 1, 90, 46, 46, 49, 39, 15, 91, 34, 34, 49, 251, 0, 47, 80, 47, 2, 47, 23,
  24, 8, 8, 24, 24, 23, 23, 20, 96, 29, 39, 8, 97, 9, 9, 29, 4, 46, 95, 1, 48,
  48, 1, 18, 0, 63, 51, 47, 16, 225, 63, 57, 47, 225, 57, 16, 225, 50, 17, 51,
  1, 47, 51, 47, 17, 51, 47, 93, 225, 50, 47, 225, 50, 17, 51, 47, 225, 49, 48,
  33, 35, 17, 52, 46, 2, 35, 35, 53, 51, 50, 62, 2, 53, 52, 46, 2, 35, 34, 6, 7,
  39, 62, 3, 51, 50, 30, 2, 21, 20, 14, 2, 7, 21, 30, 3, 21, 21, 51, 17, 35, 3,
  197, 187, 56, 103, 149, 93, 191, 176, 92, 142, 97, 50, 37, 68, 95, 58, 110,
  169, 75, 92, 38, 98, 116, 131, 72, 109, 166, 112, 57, 51, 91, 125, 75, 87,
  138, 94, 50, 176, 176, 1, 160, 68, 99, 65, 32, 151, 39, 72, 101, 61, 54, 83,
  58, 30, 67, 54, 125, 31, 54, 41, 24, 54, 97, 133, 79, 73, 120, 88, 57, 12, 6,
  11, 57, 89, 119, 72, 250, 253, 217, 0, 0, 1, 0, 80, 254, 131, 4, 92, 4, 94, 0,
  47, 0, 78, 64, 41, 36, 14, 70, 31, 31, 0, 71, 43, 43, 47, 70, 44, 49, 22, 23,
  8, 8, 23, 23, 48, 22, 17, 80, 26, 36, 7, 80, 48, 8, 1, 8, 8, 23, 26, 16, 45,
  45, 43, 80, 0, 21, 0, 63, 225, 51, 47, 63, 51, 57, 47, 93, 225, 57, 16, 225,
  50, 17, 1, 51, 47, 51, 47, 17, 51, 16, 222, 225, 50, 47, 225, 51, 47, 225, 50,
  48, 49, 33, 17, 52, 46, 2, 35, 35, 53, 51, 50, 62, 2, 53, 52, 38, 35, 34, 14,
  2, 7, 39, 54, 54, 51, 50, 30, 2, 21, 20, 14, 2, 7, 21, 30, 3, 21, 21, 51, 17,
  35, 17, 3, 6, 27, 62, 102, 75, 236, 203, 62, 100, 72, 39, 140, 131, 47, 82,
  80, 80, 45, 63, 93, 201, 115, 99, 160, 113, 61, 28, 51, 71, 43, 54, 84, 58,
  31, 160, 176, 1, 43, 47, 73, 49, 26, 153, 18, 39, 64, 45, 77, 77, 10, 18, 27,
  17, 147, 39, 37, 36, 72, 106, 70, 53, 81, 59, 41, 14, 11, 13, 44, 66, 91, 62,
  145, 253, 233, 1, 125, 0, 1, 0, 0, 255, 236, 4, 131, 5, 182, 0, 48, 0, 83, 64,
  46, 22, 13, 27, 250, 1, 29, 251, 48, 6, 13, 0, 1, 16, 1, 2, 1, 48, 1, 48, 13,
  35, 251, 15, 38, 1, 38, 50, 13, 32, 95, 43, 19, 36, 36, 17, 1, 95, 27, 3, 14,
  14, 17, 96, 13, 11, 19, 0, 63, 51, 225, 50, 47, 63, 225, 18, 57, 47, 63, 225,
  1, 47, 16, 222, 93, 225, 17, 57, 57, 47, 47, 93, 18, 57, 16, 225, 16, 237, 17,
  57, 48, 49, 1, 35, 14, 3, 7, 14, 3, 35, 34, 39, 53, 22, 22, 51, 50, 62, 2, 55,
  54, 54, 18, 18, 55, 33, 17, 20, 22, 51, 50, 54, 53, 17, 51, 17, 20, 14, 2, 35,
  34, 46, 2, 53, 2, 45, 164, 9, 20, 21, 19, 9, 10, 27, 48, 78, 62, 51, 39, 14,
  26, 17, 25, 31, 21, 14, 6, 7, 19, 23, 26, 15, 1, 231, 59, 66, 68, 57, 174, 42,
  78, 109, 68, 67, 110, 80, 44, 5, 18, 116, 245, 234, 210, 81, 103, 161, 110,
  58, 22, 154, 8, 9, 60, 93, 113, 54, 59, 196, 1, 2, 1, 57, 177, 251, 209, 129,
  119, 119, 129, 1, 201, 254, 45, 105, 152, 98, 46, 44, 96, 153, 108, 0, 1, 0,
  0, 255, 236, 4, 131, 4, 74, 0, 41, 0, 73, 64, 40, 20, 73, 1, 22, 70, 41, 0, 1,
  16, 1, 2, 1, 41, 1, 41, 11, 28, 70, 15, 31, 1, 31, 43, 11, 29, 29, 15, 1, 80,
  20, 15, 25, 12, 12, 15, 79, 36, 11, 8, 22, 0, 63, 51, 51, 225, 50, 17, 51, 63,
  225, 18, 57, 47, 1, 47, 16, 222, 93, 225, 17, 57, 57, 47, 47, 93, 16, 225, 16,
  225, 49, 48, 1, 35, 6, 2, 14, 3, 35, 34, 38, 39, 53, 22, 22, 51, 50, 54, 54,
  18, 55, 33, 17, 20, 22, 51, 50, 54, 53, 17, 51, 17, 20, 14, 2, 35, 34, 46, 2,
  53, 2, 45, 174, 10, 29, 38, 48, 58, 69, 41, 26, 49, 15, 8, 17, 8, 37, 61, 48,
  37, 13, 1, 246, 55, 72, 65, 58, 174, 36, 73, 110, 74, 71, 113, 79, 42, 3, 176,
  186, 254, 226, 213, 145, 89, 39, 6, 6, 131, 3, 3, 117, 241, 1, 111, 250, 253,
  61, 135, 125, 123, 137, 1, 53, 254, 193, 105, 152, 98, 46, 37, 87, 142, 104,
  0, 1, 0, 121, 255, 236, 4, 131, 5, 182, 0, 29, 0, 72, 64, 42, 27, 0, 251, 19,
  19, 23, 6, 251, 56, 9, 1, 15, 9, 1, 9, 31, 26, 22, 251, 71, 23, 1, 0, 23, 16,
  23, 2, 23, 21, 95, 7, 26, 26, 28, 24, 3, 23, 18, 3, 95, 14, 19, 0, 63, 225,
  63, 63, 51, 57, 47, 51, 225, 1, 47, 93, 93, 225, 50, 16, 222, 93, 93, 225, 17,
  57, 47, 225, 51, 48, 49, 1, 20, 22, 51, 50, 54, 53, 17, 51, 17, 20, 14, 2, 35,
  34, 46, 2, 53, 17, 33, 17, 35, 17, 51, 17, 33, 17, 51, 2, 219, 62, 69, 69, 58,
  166, 37, 74, 111, 75, 75, 110, 72, 36, 254, 234, 166, 166, 1, 22, 166, 1, 135,
  129, 119, 119, 129, 1, 201, 254, 45, 105, 152, 98, 46, 44, 96, 153, 108, 1,
  45, 253, 86, 5, 182, 253, 152, 2, 104, 0, 1, 0, 123, 255, 236, 4, 123, 4, 74,
  0, 29, 0, 80, 64, 49, 5, 73, 2, 71, 24, 87, 24, 2, 24, 24, 28, 11, 73, 72, 14,
  88, 14, 168, 14, 3, 15, 14, 1, 14, 31, 1, 27, 73, 0, 28, 16, 28, 2, 28, 28,
  21, 26, 80, 12, 1, 1, 0, 8, 80, 19, 22, 3, 0, 15, 0, 63, 50, 63, 225, 17, 57,
  47, 196, 225, 63, 1, 47, 93, 225, 50, 16, 222, 93, 93, 225, 17, 57, 47, 93,
  51, 225, 48, 49, 1, 17, 33, 17, 51, 17, 20, 22, 51, 50, 54, 53, 17, 51, 17,
  20, 14, 2, 35, 34, 46, 2, 53, 53, 33, 17, 35, 17, 1, 29, 1, 34, 162, 55, 72,
  63, 58, 162, 35, 70, 105, 71, 67, 108, 76, 40, 254, 222, 162, 4, 74, 254, 57,
  1, 199, 253, 61, 131, 129, 130, 130, 1, 53, 254, 193, 105, 152, 98, 46, 37,
  87, 142, 104, 139, 254, 23, 4, 74, 0, 1, 0, 117, 255, 236, 4, 111, 5, 203, 0,
  40, 0, 73, 64, 42, 40, 40, 12, 39, 90, 2, 21, 20, 20, 2, 42, 29, 91, 0, 12, 1,
  12, 21, 24, 95, 17, 40, 95, 47, 0, 95, 0, 2, 0, 64, 16, 24, 72, 0, 0, 20, 17,
  4, 34, 95, 7, 19, 0, 63, 225, 63, 51, 57, 47, 43, 93, 225, 16, 225, 50, 1, 47,
  93, 225, 16, 206, 50, 47, 51, 16, 225, 17, 57, 47, 48, 49, 1, 33, 21, 20, 14,
  2, 35, 34, 38, 38, 2, 53, 52, 18, 54, 54, 51, 50, 22, 23, 7, 38, 38, 35, 34,
  14, 2, 21, 20, 30, 2, 51, 50, 62, 2, 53, 33, 2, 160, 1, 207, 52, 111, 173,
  121, 138, 210, 141, 72, 80, 151, 216, 136, 115, 181, 75, 72, 58, 153, 94, 86,
  140, 100, 55, 45, 89, 132, 87, 82, 109, 66, 27, 254, 234, 2, 246, 142, 167,
  241, 155, 73, 105, 195, 1, 23, 174, 172, 1, 22, 195, 105, 44, 42, 162, 34, 50,
  81, 152, 218, 137, 132, 217, 154, 85, 55, 111, 170, 115, 0, 0, 1, 0, 113, 255,
  236, 4, 92, 4, 94, 0, 40, 0, 65, 64, 35, 40, 40, 12, 1, 21, 63, 20, 1, 20, 20,
  39, 71, 1, 42, 29, 72, 0, 12, 1, 12, 21, 24, 78, 17, 40, 80, 0, 0, 20, 17, 16,
  34, 78, 7, 22, 0, 63, 225, 63, 51, 57, 47, 225, 16, 225, 50, 1, 47, 93, 225,
  16, 222, 225, 51, 47, 93, 51, 17, 18, 57, 47, 48, 49, 1, 33, 21, 20, 14, 2,
  35, 34, 46, 2, 53, 52, 62, 2, 51, 50, 22, 23, 7, 38, 38, 35, 34, 14, 2, 21,
  20, 30, 2, 51, 50, 62, 2, 53, 33, 2, 123, 1, 225, 50, 113, 179, 129, 135, 200,
  132, 65, 71, 140, 208, 138, 111, 172, 77, 61, 60, 148, 91, 91, 139, 92, 47,
  37, 83, 132, 94, 81, 110, 66, 28, 254, 215, 2, 74, 68, 130, 200, 137, 71, 79,
  147, 211, 132, 131, 210, 148, 80, 37, 39, 145, 29, 45, 58, 109, 157, 98, 93,
  155, 112, 62, 45, 80, 113, 67, 0, 0, 1, 0, 20, 255, 236, 4, 131, 5, 182, 0,
  25, 0, 64, 64, 38, 6, 90, 15, 9, 1, 9, 27, 48, 24, 1, 24, 24, 0, 90, 159, 21,
  1, 21, 48, 19, 128, 19, 144, 19, 3, 19, 25, 21, 95, 22, 7, 7, 22, 3, 3, 95,
  14, 19, 0, 63, 225, 63, 57, 47, 16, 225, 50, 1, 47, 93, 206, 93, 241, 202, 47,
  93, 16, 222, 93, 225, 48, 49, 1, 20, 22, 51, 50, 54, 53, 17, 51, 17, 20, 14,
  2, 35, 34, 46, 2, 53, 17, 33, 53, 33, 21, 33, 2, 113, 82, 92, 92, 82, 182, 50,
  93, 132, 81, 80, 133, 95, 53, 254, 94, 3, 254, 254, 95, 1, 135, 129, 119, 119,
  129, 1, 201, 254, 45, 105, 152, 98, 46, 39, 93, 154, 115, 3, 149, 164, 164, 0,
  0, 1, 0, 41, 255, 236, 4, 111, 4, 74, 0, 27, 0, 60, 64, 35, 13, 71, 16, 29,
  143, 3, 159, 3, 2, 3, 3, 5, 71, 31, 0, 1, 0, 0, 26, 16, 26, 2, 26, 14, 14, 1,
  10, 80, 21, 22, 4, 0, 80, 1, 15, 0, 63, 225, 50, 63, 225, 17, 57, 47, 1, 47,
  93, 206, 93, 241, 202, 47, 93, 16, 222, 225, 48, 49, 19, 53, 33, 21, 33, 17,
  20, 30, 2, 51, 50, 54, 53, 17, 51, 17, 20, 14, 2, 35, 34, 46, 2, 53, 17, 41,
  3, 53, 254, 193, 21, 49, 80, 59, 105, 95, 183, 47, 95, 143, 96, 91, 146, 102,
  55, 3, 176, 154, 154, 253, 215, 65, 98, 65, 32, 130, 130, 1, 53, 254, 193,
  105, 152, 98, 46, 46, 98, 150, 105, 2, 53, 0, 0, 1, 0, 166, 255, 236, 4, 68,
  5, 203, 0, 59, 0, 73, 64, 39, 28, 28, 49, 39, 39, 11, 10, 61, 21, 90, 0, 0,
  32, 91, 0, 49, 1, 49, 54, 29, 97, 159, 26, 1, 26, 26, 5, 38, 35, 96, 39, 44,
  19, 11, 16, 96, 10, 5, 4, 0, 63, 51, 225, 50, 63, 51, 225, 50, 17, 57, 47, 93,
  225, 57, 1, 47, 93, 225, 51, 47, 225, 16, 206, 50, 50, 47, 17, 57, 47, 48, 49,
  19, 52, 62, 2, 51, 50, 30, 2, 23, 7, 46, 3, 35, 34, 14, 2, 21, 20, 30, 2, 51,
  51, 21, 35, 34, 6, 21, 20, 22, 51, 50, 54, 55, 21, 14, 3, 35, 34, 46, 2, 53,
  52, 62, 2, 55, 53, 46, 3, 211, 60, 115, 169, 109, 71, 123, 105, 90, 39, 93,
  37, 77, 83, 91, 52, 57, 95, 68, 38, 44, 87, 131, 87, 194, 190, 186, 208, 170,
  164, 109, 203, 84, 42, 88, 99, 111, 64, 128, 195, 131, 66, 50, 94, 137, 88,
  75, 120, 84, 45, 4, 96, 79, 133, 97, 54, 24, 41, 54, 31, 125, 27, 45, 31, 18,
  30, 58, 83, 54, 61, 101, 72, 39, 151, 133, 135, 137, 142, 49, 43, 170, 19, 28,
  19, 9, 60, 111, 156, 96, 72, 123, 94, 61, 11, 6, 12, 57, 88, 120, 255, 255, 0,
  201, 255, 236, 4, 8, 4, 94, 2, 6, 1, 130, 0, 0, 255, 255, 0, 4, 255, 233, 4,
  70, 5, 182, 2, 6, 1, 181, 0, 0, 255, 255, 0, 31, 255, 242, 4, 16, 4, 74, 2, 6,
  1, 213, 0, 0, 255, 255, 0, 33, 254, 152, 4, 172, 5, 188, 2, 38, 0, 36, 0, 0,
  1, 6, 2, 103, 0, 0, 0, 19, 64, 11, 2, 18, 20, 39, 2, 0, 15, 21, 4, 7, 37, 1,
  43, 53, 0, 43, 53, 0, 255, 255, 0, 135, 254, 152, 4, 2, 4, 94, 2, 38, 0, 68,
  0, 0, 1, 6, 2, 103, 237, 0, 0, 19, 64, 11, 2, 37, 23, 39, 2, 15, 34, 40, 8,
  22, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 33, 0, 0, 4, 172, 7, 225, 2, 38,
  0, 36, 0, 0, 1, 7, 2, 102, 0, 33, 1, 82, 0, 19, 64, 11, 2, 21, 5, 38, 2, 33,
  36, 15, 4, 7, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 135, 255, 236, 4, 2,
  6, 143, 2, 38, 0, 68, 0, 0, 1, 6, 2, 102, 25, 0, 0, 19, 64, 11, 2, 40, 17, 38,
  2, 59, 55, 34, 8, 22, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 33, 0, 0, 4,
  172, 7, 209, 2, 38, 0, 36, 0, 0, 1, 7, 3, 119, 0, 121, 1, 82, 0, 23, 64, 13,
  3, 2, 15, 5, 38, 3, 2, 120, 23, 38, 4, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0,
  255, 255, 0, 135, 255, 236, 4, 141, 6, 127, 2, 38, 0, 68, 0, 0, 1, 6, 3, 119,
  125, 0, 0, 23, 64, 13, 3, 2, 34, 17, 38, 3, 2, 158, 42, 57, 8, 22, 37, 1, 43,
  53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 33, 0, 0, 4, 172, 7, 209, 2, 38, 0, 36,
  0, 0, 1, 7, 3, 120, 255, 148, 1, 82, 0, 25, 182, 3, 2, 23, 5, 38, 3, 2, 184,
  255, 148, 180, 36, 22, 4, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0,
  85, 255, 236, 4, 2, 6, 127, 2, 38, 0, 68, 0, 0, 1, 6, 3, 120, 153, 0, 0, 25,
  182, 3, 2, 42, 17, 38, 3, 2, 184, 255, 187, 180, 55, 41, 8, 22, 37, 1, 43, 53,
  53, 0, 43, 53, 53, 0, 255, 255, 0, 33, 0, 0, 4, 172, 8, 74, 2, 38, 0, 36, 0,
  0, 1, 7, 3, 121, 0, 88, 1, 82, 0, 23, 64, 13, 3, 2, 15, 5, 38, 3, 2, 88, 23,
  32, 4, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 135, 255, 236, 4,
  76, 6, 248, 2, 38, 0, 68, 0, 0, 1, 6, 3, 121, 92, 0, 0, 23, 64, 13, 3, 2, 34,
  17, 38, 3, 2, 126, 42, 51, 8, 22, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255,
  255, 0, 33, 0, 0, 4, 172, 8, 98, 2, 38, 0, 36, 0, 0, 1, 7, 3, 122, 0, 8, 1,
  82, 0, 23, 64, 13, 3, 2, 23, 5, 38, 3, 2, 7, 41, 55, 4, 7, 37, 1, 43, 53, 53,
  0, 43, 53, 53, 0, 255, 255, 0, 135, 255, 236, 4, 2, 7, 16, 2, 38, 0, 68, 0, 0,
  1, 6, 3, 122, 12, 0, 0, 23, 64, 13, 3, 2, 42, 17, 38, 3, 2, 45, 60, 74, 8, 22,
  37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 33, 254, 152, 4, 172, 7,
  115, 2, 38, 0, 36, 0, 0, 0, 39, 1, 75, 0, 0, 1, 82, 1, 6, 2, 103, 0, 0, 0, 34,
  64, 22, 3, 34, 20, 39, 2, 15, 5, 38, 3, 0, 31, 37, 4, 7, 37, 2, 0, 21, 15, 4,
  7, 37, 1, 43, 53, 43, 53, 0, 43, 53, 43, 53, 255, 255, 0, 135, 254, 152, 4, 2,
  6, 33, 2, 38, 0, 68, 0, 0, 0, 38, 1, 75, 8, 0, 1, 6, 2, 103, 237, 0, 0, 34,
  64, 22, 3, 53, 23, 39, 2, 34, 17, 38, 3, 15, 50, 56, 8, 22, 37, 2, 42, 40, 34,
  8, 22, 37, 1, 43, 53, 43, 53, 0, 43, 53, 43, 53, 255, 255, 0, 33, 0, 0, 4,
  172, 8, 19, 2, 38, 0, 36, 0, 0, 1, 7, 3, 123, 0, 0, 1, 82, 0, 23, 64, 13, 3,
  2, 32, 5, 38, 3, 2, 0, 35, 27, 4, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255,
  255, 0, 135, 255, 236, 4, 2, 6, 193, 2, 38, 0, 68, 0, 0, 1, 6, 3, 123, 255, 0,
  0, 23, 64, 13, 3, 2, 51, 17, 38, 3, 2, 32, 54, 46, 8, 22, 37, 1, 43, 53, 53,
  0, 43, 53, 53, 0, 255, 255, 0, 33, 0, 0, 4, 172, 8, 19, 2, 38, 0, 36, 0, 0, 1,
  7, 3, 124, 0, 0, 1, 82, 0, 23, 64, 13, 3, 2, 32, 5, 38, 3, 2, 0, 35, 27, 4, 7,
  37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 135, 255, 236, 4, 2, 6, 193,
  2, 38, 0, 68, 0, 0, 1, 6, 3, 124, 255, 0, 0, 23, 64, 13, 3, 2, 51, 17, 38, 3,
  2, 32, 54, 46, 8, 22, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 33, 0,
  0, 4, 172, 8, 88, 2, 38, 0, 36, 0, 0, 1, 7, 3, 125, 0, 0, 1, 82, 0, 23, 64,
  13, 3, 2, 20, 5, 38, 3, 2, 0, 23, 15, 4, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53,
  0, 255, 255, 0, 135, 255, 236, 4, 2, 7, 6, 2, 38, 0, 68, 0, 0, 1, 6, 3, 125,
  255, 0, 0, 23, 64, 13, 3, 2, 39, 17, 38, 3, 2, 32, 42, 34, 8, 22, 37, 1, 43,
  53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 33, 0, 0, 4, 172, 8, 98, 2, 38, 0, 36,
  0, 0, 1, 7, 3, 126, 0, 0, 1, 82, 0, 25, 182, 3, 2, 20, 5, 38, 3, 2, 184, 255,
  255, 180, 44, 58, 4, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 135,
  255, 236, 4, 2, 7, 16, 2, 38, 0, 68, 0, 0, 1, 6, 3, 126, 255, 0, 0, 23, 64,
  13, 3, 2, 39, 17, 38, 3, 2, 32, 63, 77, 8, 22, 37, 1, 43, 53, 53, 0, 43, 53,
  53, 0, 255, 255, 0, 33, 254, 152, 4, 172, 7, 64, 2, 38, 0, 36, 0, 0, 0, 39, 1,
  78, 255, 253, 1, 82, 1, 6, 2, 103, 0, 0, 0, 37, 64, 16, 3, 30, 20, 39, 2, 18,
  5, 38, 3, 0, 27, 33, 4, 7, 37, 2, 184, 255, 253, 180, 20, 15, 4, 7, 37, 1, 43,
  53, 43, 53, 0, 43, 53, 43, 53, 0, 255, 255, 0, 135, 254, 152, 4, 2, 5, 238, 2,
  38, 0, 68, 0, 0, 0, 38, 1, 78, 245, 0, 1, 6, 2, 103, 237, 0, 0, 34, 64, 22, 3,
  49, 23, 39, 2, 37, 17, 38, 3, 15, 46, 52, 8, 22, 37, 2, 22, 39, 34, 8, 22, 37,
  1, 43, 53, 43, 53, 0, 43, 53, 43, 53, 255, 255, 0, 217, 254, 152, 4, 35, 5,
  182, 2, 38, 0, 40, 0, 0, 1, 6, 2, 103, 23, 0, 0, 19, 64, 11, 1, 15, 20, 39, 1,
  0, 12, 18, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 133, 254, 152, 4,
  72, 4, 94, 2, 38, 0, 72, 0, 0, 1, 6, 2, 103, 23, 0, 0, 19, 64, 11, 2, 26, 23,
  39, 2, 23, 23, 29, 11, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 217, 0, 0,
  4, 35, 7, 225, 2, 38, 0, 40, 0, 0, 1, 7, 2, 102, 0, 39, 1, 82, 0, 19, 64, 11,
  1, 18, 5, 38, 1, 15, 33, 12, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  133, 255, 236, 4, 72, 6, 143, 2, 38, 0, 72, 0, 0, 1, 6, 2, 102, 57, 0, 0, 19,
  64, 11, 2, 29, 17, 38, 2, 57, 44, 23, 11, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 217, 0, 0, 4, 35, 7, 53, 2, 38, 0, 40, 0, 0, 1, 7, 1, 82, 0, 25, 1,
  82, 0, 19, 64, 11, 1, 12, 5, 38, 1, 0, 13, 22, 1, 0, 37, 1, 43, 53, 0, 43, 53,
  0, 255, 255, 0, 133, 255, 236, 4, 72, 5, 227, 2, 38, 0, 72, 0, 0, 1, 6, 1, 82,
  33, 0, 0, 19, 64, 11, 2, 23, 17, 38, 2, 32, 24, 33, 11, 0, 37, 1, 43, 53, 0,
  43, 53, 0, 255, 255, 0, 217, 0, 0, 4, 145, 7, 209, 2, 38, 0, 40, 0, 0, 1, 7,
  3, 119, 0, 129, 1, 82, 0, 23, 64, 13, 2, 1, 12, 5, 38, 2, 1, 105, 20, 35, 1,
  0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 133, 255, 236, 4, 133, 6,
  127, 2, 38, 0, 72, 0, 0, 1, 6, 3, 119, 117, 0, 0, 23, 64, 13, 3, 2, 23, 17,
  38, 3, 2, 116, 31, 46, 11, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255,
  0, 89, 0, 0, 4, 35, 7, 209, 2, 38, 0, 40, 0, 0, 1, 7, 3, 120, 255, 157, 1, 82,
  0, 25, 182, 2, 1, 20, 5, 38, 2, 1, 184, 255, 133, 180, 33, 19, 1, 0, 37, 1,
  43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 76, 255, 236, 4, 72, 6, 127, 2, 38,
  0, 72, 0, 0, 1, 6, 3, 120, 144, 0, 0, 25, 182, 3, 2, 31, 17, 38, 3, 2, 184,
  255, 144, 180, 44, 30, 11, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255,
  0, 217, 0, 0, 4, 80, 8, 74, 2, 38, 0, 40, 0, 0, 1, 7, 3, 121, 0, 96, 1, 82, 0,
  23, 64, 13, 2, 1, 12, 5, 38, 2, 1, 72, 20, 29, 1, 0, 37, 1, 43, 53, 53, 0, 43,
  53, 53, 0, 255, 255, 0, 133, 255, 236, 4, 72, 6, 248, 2, 38, 0, 72, 0, 0, 1,
  6, 3, 121, 84, 0, 0, 23, 64, 13, 3, 2, 23, 17, 38, 3, 2, 84, 31, 40, 11, 0,
  37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 217, 0, 0, 4, 35, 8, 98, 2,
  38, 0, 40, 0, 0, 1, 7, 3, 122, 0, 16, 1, 82, 0, 25, 182, 2, 1, 20, 5, 38, 2,
  1, 184, 255, 248, 180, 38, 52, 1, 0, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255,
  255, 0, 133, 255, 236, 4, 72, 7, 16, 2, 38, 0, 72, 0, 0, 1, 6, 3, 122, 4, 0,
  0, 23, 64, 13, 3, 2, 31, 17, 38, 3, 2, 3, 49, 63, 11, 0, 37, 1, 43, 53, 53, 0,
  43, 53, 53, 0, 255, 255, 0, 217, 254, 152, 4, 35, 7, 115, 2, 38, 0, 40, 0, 0,
  0, 39, 1, 75, 0, 35, 1, 82, 1, 6, 2, 103, 23, 0, 0, 34, 64, 22, 2, 31, 20, 39,
  1, 12, 5, 38, 2, 0, 28, 34, 1, 0, 37, 1, 11, 18, 12, 1, 0, 37, 1, 43, 53, 43,
  53, 0, 43, 53, 43, 53, 255, 255, 0, 133, 254, 152, 4, 72, 6, 33, 2, 38, 0, 72,
  0, 0, 0, 38, 1, 75, 16, 0, 1, 6, 2, 103, 23, 0, 0, 34, 64, 22, 3, 42, 23, 39,
  2, 23, 17, 38, 3, 23, 39, 45, 11, 0, 37, 2, 16, 29, 23, 11, 0, 37, 1, 43, 53,
  43, 53, 0, 43, 53, 43, 53, 255, 255, 0, 225, 0, 0, 3, 233, 7, 225, 2, 38, 0,
  44, 0, 0, 1, 7, 2, 102, 0, 31, 1, 82, 0, 19, 64, 11, 1, 18, 5, 38, 1, 32, 33,
  12, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 197, 0, 0, 4, 51, 6, 143,
  2, 38, 0, 243, 0, 0, 1, 6, 2, 102, 47, 0, 0, 19, 64, 11, 1, 16, 17, 38, 1, 25,
  31, 10, 7, 5, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 225, 254, 152, 3, 233,
  5, 182, 2, 38, 0, 44, 0, 0, 1, 6, 2, 103, 0, 0, 0, 19, 64, 11, 1, 15, 20, 39,
  1, 1, 12, 18, 1, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 197, 254, 152,
  4, 51, 6, 14, 2, 38, 0, 76, 0, 0, 1, 6, 2, 103, 20, 0, 0, 21, 180, 2, 22, 23,
  39, 2, 184, 255, 255, 180, 19, 25, 16, 14, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 84, 254, 152, 4, 123, 5, 205, 2, 38, 0, 50, 0, 0, 1, 6, 2, 103, 0, 0,
  0, 21, 180, 2, 23, 20, 39, 2, 184, 255, 255, 180, 20, 26, 2, 7, 37, 1, 43, 53,
  0, 43, 53, 0, 255, 255, 0, 115, 254, 152, 4, 88, 4, 94, 2, 38, 0, 82, 0, 0, 1,
  6, 2, 103, 0, 0, 0, 19, 64, 11, 2, 23, 23, 39, 2, 1, 20, 26, 3, 9, 37, 1, 43,
  53, 0, 43, 53, 0, 255, 255, 0, 84, 255, 236, 4, 123, 7, 225, 2, 38, 0, 50, 0,
  0, 1, 7, 2, 102, 0, 23, 1, 82, 0, 19, 64, 11, 2, 26, 5, 38, 2, 22, 41, 20, 2,
  7, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 115, 255, 236, 4, 88, 6, 143, 2,
  38, 0, 82, 0, 0, 1, 6, 2, 102, 31, 0, 0, 19, 64, 11, 2, 26, 17, 38, 2, 32, 41,
  20, 3, 9, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 84, 255, 236, 4, 131, 7,
  209, 2, 38, 0, 50, 0, 0, 1, 7, 3, 119, 0, 115, 1, 82, 0, 23, 64, 13, 3, 2, 20,
  5, 38, 3, 2, 113, 28, 43, 2, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255,
  0, 115, 255, 236, 4, 131, 6, 127, 2, 38, 0, 82, 0, 0, 1, 6, 3, 119, 115, 0, 0,
  23, 64, 13, 3, 2, 20, 17, 38, 3, 2, 115, 28, 43, 3, 9, 37, 1, 43, 53, 53, 0,
  43, 53, 53, 0, 255, 255, 0, 74, 255, 236, 4, 123, 7, 209, 2, 38, 0, 50, 0, 0,
  1, 7, 3, 120, 255, 142, 1, 82, 0, 25, 182, 3, 2, 28, 5, 38, 3, 2, 184, 255,
  141, 180, 41, 27, 2, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 74,
  255, 236, 4, 88, 6, 127, 2, 38, 0, 82, 0, 0, 1, 6, 3, 120, 142, 0, 0, 25, 182,
  3, 2, 28, 17, 38, 3, 2, 184, 255, 143, 180, 41, 27, 3, 9, 37, 1, 43, 53, 53,
  0, 43, 53, 53, 0, 255, 255, 0, 84, 255, 236, 4, 123, 8, 74, 2, 38, 0, 50, 0,
  0, 1, 7, 3, 121, 0, 82, 1, 82, 0, 23, 64, 13, 3, 2, 20, 5, 38, 3, 2, 81, 28,
  37, 2, 7, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 115, 255, 236, 4,
  88, 6, 248, 2, 38, 0, 82, 0, 0, 1, 6, 3, 121, 82, 0, 0, 23, 64, 13, 3, 2, 20,
  17, 38, 3, 2, 83, 28, 37, 3, 9, 37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255,
  0, 84, 255, 236, 4, 123, 8, 98, 2, 38, 0, 50, 0, 0, 1, 7, 3, 122, 0, 2, 1, 82,
  0, 23, 64, 13, 3, 2, 28, 5, 38, 3, 2, 0, 46, 60, 2, 7, 37, 1, 43, 53, 53, 0,
  43, 53, 53, 0, 255, 255, 0, 115, 255, 236, 4, 88, 7, 16, 2, 38, 0, 82, 0, 0,
  1, 6, 3, 122, 2, 0, 0, 23, 64, 13, 3, 2, 28, 17, 38, 3, 2, 2, 46, 60, 3, 9,
  37, 1, 43, 53, 53, 0, 43, 53, 53, 0, 255, 255, 0, 84, 254, 152, 4, 123, 7,
  115, 2, 38, 0, 50, 0, 0, 0, 39, 1, 75, 0, 0, 1, 82, 1, 6, 2, 103, 0, 0, 0, 40,
  64, 9, 3, 39, 20, 39, 2, 20, 5, 38, 3, 184, 255, 255, 181, 36, 42, 2, 7, 37,
  2, 184, 255, 255, 180, 26, 20, 2, 7, 37, 1, 43, 53, 43, 53, 0, 43, 53, 43, 53,
  255, 255, 0, 115, 254, 152, 4, 88, 6, 33, 2, 38, 0, 82, 0, 0, 0, 38, 1, 75, 0,
  0, 1, 6, 2, 103, 0, 0, 0, 34, 64, 22, 3, 39, 23, 39, 2, 20, 17, 38, 3, 1, 36,
  42, 3, 9, 37, 2, 1, 26, 20, 3, 9, 37, 1, 43, 53, 43, 53, 0, 43, 53, 43, 53,
  255, 255, 0, 84, 255, 236, 4, 246, 7, 115, 2, 38, 2, 95, 0, 0, 1, 7, 0, 118,
  0, 90, 1, 82, 0, 19, 64, 11, 2, 59, 5, 38, 2, 27, 53, 56, 10, 25, 37, 1, 43,
  53, 0, 43, 53, 0, 255, 255, 0, 115, 255, 236, 4, 246, 6, 33, 2, 38, 2, 96, 0,
  0, 1, 6, 0, 118, 80, 0, 0, 14, 183, 2, 2, 2, 44, 47, 10, 25, 37, 1, 43, 53, 0,
  53, 255, 255, 0, 84, 255, 236, 4, 246, 7, 115, 2, 38, 2, 95, 0, 0, 1, 7, 0,
  67, 255, 175, 1, 82, 0, 21, 180, 2, 53, 5, 38, 2, 184, 255, 113, 180, 56, 53,
  10, 25, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 115, 255, 236, 4, 246, 6,
  33, 2, 38, 2, 96, 0, 0, 1, 6, 0, 67, 216, 0, 0, 17, 177, 2, 2, 184, 255, 138,
  180, 47, 44, 10, 25, 37, 1, 43, 53, 0, 53, 0, 255, 255, 0, 84, 255, 236, 4,
  246, 7, 225, 2, 38, 2, 95, 0, 0, 1, 7, 2, 102, 0, 23, 1, 82, 0, 21, 180, 2,
  60, 5, 38, 2, 184, 255, 217, 180, 74, 53, 10, 25, 37, 1, 43, 53, 0, 43, 53, 0,
  255, 255, 0, 115, 255, 236, 4, 246, 6, 143, 2, 38, 2, 96, 0, 0, 1, 6, 2, 102,
  31, 0, 0, 21, 180, 2, 51, 17, 38, 2, 184, 255, 209, 180, 65, 44, 10, 25, 37,
  1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 84, 255, 236, 4, 246, 7, 53, 2, 38, 2,
  95, 0, 0, 1, 7, 1, 82, 0, 8, 1, 82, 0, 21, 180, 2, 53, 5, 38, 2, 184, 255,
  201, 180, 54, 63, 10, 25, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 115, 255,
  236, 4, 246, 5, 227, 2, 38, 2, 96, 0, 0, 1, 6, 1, 82, 0, 0, 0, 17, 177, 2, 2,
  184, 255, 177, 180, 45, 54, 10, 25, 37, 1, 43, 53, 0, 53, 0, 255, 255, 0, 84,
  254, 152, 4, 246, 6, 20, 2, 38, 2, 95, 0, 0, 1, 6, 2, 103, 0, 0, 0, 21, 180,
  2, 56, 20, 39, 2, 184, 255, 194, 180, 53, 59, 10, 25, 37, 1, 43, 53, 0, 43,
  53, 0, 255, 255, 0, 115, 254, 152, 4, 246, 4, 242, 2, 38, 2, 96, 0, 0, 1, 6,
  2, 103, 0, 0, 0, 21, 180, 2, 47, 23, 39, 2, 184, 255, 178, 180, 44, 50, 10,
  25, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 125, 254, 152, 4, 80, 5, 184, 2,
  38, 0, 56, 0, 0, 1, 6, 2, 103, 0, 0, 0, 19, 64, 11, 1, 18, 20, 39, 1, 0, 15,
  21, 6, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160, 254, 152, 4, 45, 4,
  74, 2, 38, 0, 88, 0, 0, 1, 6, 2, 103, 0, 0, 0, 19, 64, 11, 1, 21, 23, 39, 1,
  0, 18, 24, 6, 16, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 125, 255, 236, 4,
  80, 7, 225, 2, 38, 0, 56, 0, 0, 1, 7, 2, 102, 0, 23, 1, 82, 0, 19, 64, 11, 1,
  21, 5, 38, 1, 23, 36, 15, 6, 0, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160,
  255, 236, 4, 45, 6, 143, 2, 38, 0, 88, 0, 0, 1, 6, 2, 102, 29, 0, 0, 19, 64,
  11, 1, 24, 17, 38, 1, 29, 39, 18, 6, 16, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 125, 255, 236, 5, 23, 7, 115, 2, 38, 2, 97, 0, 0, 1, 7, 0, 118, 255,
  255, 1, 82, 0, 21, 180, 1, 45, 5, 38, 1, 184, 255, 156, 180, 39, 42, 24, 8,
  37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160, 255, 236, 5, 23, 6, 33, 2, 38,
  2, 98, 0, 0, 1, 6, 0, 118, 255, 0, 0, 17, 177, 1, 1, 184, 255, 138, 180, 40,
  43, 12, 33, 37, 1, 43, 53, 0, 53, 0, 255, 255, 0, 125, 255, 236, 5, 23, 7,
  115, 2, 38, 2, 97, 0, 0, 1, 7, 0, 67, 255, 110, 1, 82, 0, 21, 180, 1, 39, 5,
  38, 1, 184, 255, 11, 180, 42, 39, 24, 8, 37, 1, 43, 53, 0, 43, 53, 0, 255,
  255, 0, 160, 255, 236, 5, 23, 6, 33, 2, 38, 2, 98, 0, 0, 1, 7, 0, 67, 255,
  107, 0, 0, 0, 17, 177, 1, 1, 184, 254, 246, 180, 43, 40, 12, 33, 37, 1, 43,
  53, 0, 53, 0, 255, 255, 0, 125, 255, 236, 5, 23, 7, 225, 2, 38, 2, 97, 0, 0,
  1, 7, 2, 102, 255, 218, 1, 82, 0, 21, 180, 1, 46, 5, 38, 1, 184, 255, 119,
  180, 60, 39, 24, 8, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160, 255, 236,
  5, 23, 6, 143, 2, 38, 2, 98, 0, 0, 1, 6, 2, 102, 226, 0, 0, 21, 180, 1, 46,
  17, 38, 1, 184, 255, 109, 180, 61, 40, 12, 33, 37, 1, 43, 53, 0, 43, 53, 0,
  255, 255, 0, 125, 255, 236, 5, 23, 7, 53, 2, 38, 2, 97, 0, 0, 1, 7, 1, 82,
  255, 198, 1, 82, 0, 19, 64, 11, 1, 39, 5, 38, 1, 36, 40, 49, 24, 14, 37, 1,
  43, 53, 0, 43, 53, 0, 255, 255, 0, 160, 255, 236, 5, 23, 5, 227, 2, 38, 2, 98,
  0, 0, 1, 6, 1, 82, 206, 0, 0, 14, 183, 1, 1, 33, 41, 50, 12, 39, 37, 1, 43,
  53, 0, 53, 255, 255, 0, 125, 254, 152, 5, 23, 6, 20, 2, 38, 2, 97, 0, 0, 1, 6,
  2, 103, 185, 0, 0, 21, 180, 1, 42, 20, 39, 1, 184, 255, 86, 180, 39, 45, 24,
  8, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 160, 254, 152, 5, 23, 4, 242, 2,
  38, 2, 98, 0, 0, 1, 6, 2, 103, 189, 0, 0, 21, 180, 1, 43, 23, 39, 1, 184, 255,
  72, 180, 40, 46, 12, 33, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0, 33, 254,
  152, 4, 170, 5, 182, 2, 38, 0, 60, 0, 0, 1, 6, 2, 103, 255, 0, 0, 19, 64, 11,
  1, 12, 20, 39, 1, 0, 9, 15, 7, 2, 37, 1, 43, 53, 0, 43, 53, 0, 255, 255, 0,
  82, 254, 20, 4, 121, 4, 74, 2, 38, 0, 92, 0, 0, 1, 7, 2, 103, 1, 47, 0, 0, 0,
  17, 177, 1, 1, 184, 1, 48, 180, 23, 29, 0, 9, 37, 1, 43, 53, 0, 53, 0, 255,
  255, 0, 33, 0, 0, 4, 170, 7, 225, 2, 38, 0, 60, 0, 0, 1, 7, 2, 102, 0, 20, 1,
  82, 0, 19, 64, 11, 1, 15, 5, 38, 1, 21, 30, 9, 7, 2, 37, 1, 43, 53, 0, 43, 53,
  0, 255, 255, 0, 82, 254, 20, 4, 121, 6, 143, 2, 38, 0, 92, 0, 0, 1, 6, 2, 102,
  20, 0, 0, 19, 64, 11, 1, 29, 17, 38, 1, 21, 44, 23, 0, 9, 37, 1, 43, 53, 0,
  43, 53, 0, 255, 255, 0, 33, 0, 0, 4, 170, 7, 53, 2, 38, 0, 60, 0, 0, 1, 7, 1,
  82, 0, 12, 1, 82, 0, 19, 64, 11, 1, 9, 5, 38, 1, 12, 10, 19, 7, 2, 37, 1, 43,
  53, 0, 43, 53, 0, 255, 255, 0, 82, 254, 20, 4, 121, 5, 227, 2, 38, 0, 92, 0,
  0, 1, 6, 1, 82, 12, 0, 0, 19, 64, 11, 1, 23, 17, 38, 1, 12, 24, 33, 0, 9, 37,
  1, 43, 53, 0, 43, 53, 0, 0, 3, 0, 137, 254, 188, 4, 203, 6, 20, 0, 3, 0, 43,
  0, 60, 0, 118, 64, 71, 33, 33, 15, 50, 43, 35, 26, 4, 32, 71, 39, 41, 37, 3,
  3, 144, 41, 160, 41, 2, 41, 62, 58, 72, 15, 2, 2, 0, 15, 224, 15, 240, 15, 3,
  15, 43, 21, 41, 32, 79, 38, 35, 35, 20, 36, 0, 25, 55, 80, 0, 20, 16, 20, 32,
  20, 176, 20, 192, 20, 5, 20, 15, 4, 44, 80, 10, 1, 78, 2, 10, 22, 0, 63, 222,
  225, 16, 225, 50, 63, 93, 225, 50, 63, 18, 57, 47, 51, 225, 50, 63, 1, 47, 93,
  51, 47, 16, 225, 16, 206, 93, 50, 47, 50, 16, 205, 225, 50, 50, 50, 50, 50,
  17, 57, 47, 48, 49, 1, 33, 53, 33, 3, 35, 14, 3, 35, 34, 46, 2, 53, 52, 62, 2,
  51, 50, 30, 2, 23, 51, 38, 39, 38, 38, 53, 53, 33, 53, 33, 53, 51, 21, 51, 21,
  35, 17, 35, 37, 50, 62, 2, 55, 53, 52, 46, 2, 35, 34, 6, 21, 20, 22, 4, 47,
  252, 152, 3, 104, 174, 8, 23, 61, 78, 98, 62, 97, 158, 113, 62, 62, 113, 158,
  97, 61, 98, 79, 61, 23, 12, 3, 3, 2, 4, 254, 133, 1, 123, 182, 156, 156, 147,
  254, 188, 79, 109, 67, 32, 2, 28, 68, 111, 84, 140, 132, 132, 254, 188, 140,
  1, 75, 34, 61, 46, 26, 70, 138, 204, 134, 135, 206, 139, 71, 25, 44, 58, 32,
  33, 31, 26, 55, 16, 158, 137, 182, 182, 137, 251, 43, 131, 44, 89, 133, 90,
  39, 97, 149, 102, 52, 206, 196, 198, 195, 0, 2, 0, 205, 4, 217, 3, 172, 6, 33,
  0, 13, 0, 27, 0, 48, 64, 24, 15, 130, 14, 14, 20, 1, 130, 0, 0, 8, 133, 95, 6,
  1, 6, 6, 22, 133, 20, 21, 7, 128, 15, 0, 0, 47, 50, 26, 205, 50, 1, 47, 225,
  51, 47, 93, 225, 51, 47, 225, 17, 51, 47, 225, 48, 49, 1, 35, 46, 3, 39, 53,
  51, 30, 3, 23, 5, 35, 46, 3, 39, 53, 51, 30, 3, 23, 3, 172, 100, 34, 82, 77,
  64, 16, 199, 16, 43, 46, 48, 21, 254, 150, 101, 34, 82, 77, 63, 16, 198, 16,
  43, 46, 48, 22, 4, 217, 28, 83, 88, 81, 27, 21, 34, 81, 81, 76, 29, 27, 28,
  83, 88, 81, 27, 21, 34, 81, 81, 76, 29, 0, 0, 2, 0, 188, 4, 217, 4, 16, 6,
  127, 0, 16, 0, 28, 0, 68, 64, 35, 22, 136, 23, 23, 27, 130, 63, 28, 79, 28,
  111, 28, 3, 28, 28, 13, 13, 12, 4, 4, 8, 1, 0, 0, 7, 8, 22, 128, 27, 64, 4,
  12, 128, 7, 0, 0, 47, 50, 26, 205, 50, 26, 222, 26, 205, 1, 47, 51, 51, 47,
  51, 18, 57, 17, 51, 51, 17, 51, 47, 93, 225, 51, 47, 225, 48, 49, 1, 35, 38,
  38, 39, 6, 6, 7, 35, 53, 54, 54, 55, 51, 22, 22, 23, 39, 62, 3, 55, 51, 21, 6,
  6, 7, 35, 3, 43, 100, 51, 108, 52, 54, 106, 51, 101, 51, 116, 48, 193, 48,
  116, 51, 78, 20, 32, 30, 29, 16, 180, 45, 106, 55, 101, 4, 217, 34, 84, 48,
  48, 84, 34, 27, 59, 132, 69, 69, 132, 59, 194, 26, 44, 46, 52, 33, 21, 60,
  103, 43, 0, 2, 0, 188, 4, 217, 4, 16, 6, 127, 0, 16, 0, 28, 0, 68, 64, 35, 23,
  136, 22, 64, 18, 130, 48, 17, 64, 17, 96, 17, 3, 17, 17, 3, 3, 4, 12, 12, 16,
  9, 8, 8, 15, 16, 23, 128, 18, 64, 12, 3, 128, 9, 15, 0, 47, 51, 26, 205, 50,
  26, 220, 26, 205, 1, 47, 51, 51, 47, 51, 18, 57, 17, 51, 51, 17, 51, 47, 93,
  225, 26, 221, 225, 48, 49, 1, 54, 54, 55, 51, 22, 22, 23, 21, 35, 38, 38, 39,
  6, 6, 7, 35, 55, 35, 38, 38, 39, 53, 51, 30, 3, 23, 1, 162, 51, 116, 48, 192,
  48, 116, 51, 100, 51, 106, 54, 53, 107, 51, 100, 78, 101, 55, 107, 45, 181,
  16, 29, 29, 33, 20, 4, 244, 59, 132, 69, 69, 132, 59, 27, 34, 84, 48, 48, 84,
  34, 195, 43, 103, 60, 21, 33, 52, 46, 44, 26, 0, 2, 0, 221, 4, 217, 3, 240, 6,
  248, 0, 16, 0, 41, 0, 95, 64, 52, 23, 130, 24, 24, 36, 28, 130, 15, 17, 31,
  17, 2, 17, 17, 15, 36, 31, 36, 2, 36, 64, 12, 15, 72, 36, 36, 13, 13, 12, 4,
  4, 8, 1, 0, 0, 7, 8, 22, 25, 25, 24, 33, 140, 39, 39, 24, 64, 4, 12, 128, 1,
  7, 0, 47, 51, 26, 205, 50, 26, 204, 50, 47, 237, 18, 57, 47, 51, 1, 47, 51,
  51, 47, 51, 18, 57, 17, 51, 51, 17, 51, 47, 43, 93, 51, 47, 93, 225, 17, 57,
  47, 225, 48, 49, 1, 35, 38, 38, 39, 6, 6, 7, 35, 53, 54, 54, 55, 51, 22, 22,
  23, 19, 20, 14, 2, 7, 7, 35, 39, 54, 54, 53, 52, 46, 2, 35, 34, 6, 7, 53, 54,
  51, 50, 22, 3, 76, 101, 51, 107, 53, 54, 105, 51, 101, 51, 116, 48, 193, 48,
  116, 51, 164, 20, 35, 45, 25, 6, 86, 11, 56, 65, 15, 27, 37, 21, 22, 39, 11,
  21, 59, 99, 100, 4, 217, 34, 84, 48, 48, 84, 34, 27, 59, 132, 69, 69, 132, 59,
  1, 118, 29, 43, 30, 21, 6, 81, 131, 9, 31, 37, 19, 24, 14, 5, 3, 3, 82, 6, 69,
  0, 0, 2, 1, 35, 4, 217, 3, 168, 7, 16, 0, 16, 0, 44, 0, 102, 64, 36, 20, 26,
  39, 130, 40, 34, 25, 40, 4, 3, 12, 12, 16, 9, 8, 8, 15, 40, 31, 40, 47, 40, 3,
  40, 40, 25, 130, 26, 15, 16, 16, 26, 39, 39, 31, 31, 184, 1, 1, 179, 22, 25,
  64, 36, 184, 1, 1, 183, 17, 17, 25, 12, 3, 128, 9, 15, 0, 47, 51, 26, 221, 50,
  198, 50, 47, 225, 26, 16, 218, 225, 47, 50, 47, 1, 47, 51, 47, 51, 16, 237,
  51, 47, 93, 51, 47, 51, 18, 57, 17, 51, 51, 17, 18, 57, 16, 237, 17, 57, 49,
  48, 1, 54, 54, 55, 51, 22, 22, 23, 21, 35, 38, 38, 39, 6, 6, 7, 35, 1, 34, 46,
  2, 35, 34, 6, 7, 35, 62, 3, 51, 50, 30, 2, 51, 50, 54, 55, 51, 14, 3, 1, 45,
  51, 116, 48, 193, 48, 116, 51, 101, 51, 106, 54, 52, 108, 51, 100, 1, 191, 36,
  72, 69, 63, 29, 40, 42, 14, 92, 5, 28, 48, 66, 41, 38, 74, 69, 62, 26, 40, 42,
  14, 92, 4, 29, 48, 66, 4, 244, 59, 132, 69, 69, 132, 59, 27, 34, 84, 48, 48,
  84, 34, 1, 90, 28, 34, 28, 42, 50, 48, 81, 59, 33, 28, 34, 28, 43, 49, 48, 81,
  59, 33, 0, 2, 1, 57, 4, 217, 3, 147, 6, 193, 0, 11, 0, 31, 0, 45, 64, 22, 0,
  11, 1, 11, 64, 7, 31, 131, 12, 12, 21, 131, 20, 5, 128, 11, 11, 31, 20, 26,
  143, 17, 0, 47, 253, 204, 50, 50, 47, 26, 204, 1, 47, 225, 51, 47, 225, 214,
  26, 205, 93, 48, 49, 1, 62, 3, 55, 51, 21, 6, 6, 7, 35, 37, 14, 3, 35, 34, 38,
  39, 51, 30, 3, 51, 50, 62, 2, 55, 2, 37, 20, 32, 30, 29, 16, 180, 45, 106, 56,
  100, 1, 110, 4, 44, 76, 110, 71, 146, 144, 7, 109, 4, 27, 48, 68, 43, 36, 66,
  51, 34, 4, 5, 248, 25, 44, 46, 53, 33, 21, 60, 103, 44, 6, 60, 99, 69, 38,
  139, 127, 43, 49, 26, 7, 9, 27, 49, 40, 0, 0, 2, 1, 57, 4, 217, 3, 147, 6,
  193, 0, 11, 0, 31, 0, 47, 64, 23, 31, 131, 12, 12, 20, 15, 0, 1, 0, 64, 4, 21,
  131, 20, 5, 128, 1, 1, 31, 20, 26, 143, 17, 0, 47, 253, 204, 50, 50, 47, 26,
  205, 1, 47, 225, 214, 26, 205, 93, 17, 51, 47, 225, 48, 49, 1, 35, 38, 38, 39,
  53, 51, 30, 3, 23, 23, 14, 3, 35, 34, 38, 39, 51, 30, 3, 51, 50, 62, 2, 55, 2,
  152, 101, 56, 106, 45, 181, 16, 29, 29, 33, 20, 251, 4, 44, 76, 110, 71, 146,
  144, 7, 109, 4, 27, 48, 68, 43, 36, 66, 51, 34, 4, 5, 221, 44, 103, 60, 21,
  33, 53, 46, 44, 25, 21, 60, 99, 69, 38, 139, 127, 43, 49, 26, 7, 9, 27, 49,
  40, 0, 2, 1, 57, 4, 217, 3, 147, 7, 6, 0, 19, 0, 43, 0, 86, 64, 48, 26, 26,
  27, 27, 37, 37, 31, 20, 64, 9, 12, 72, 20, 20, 0, 9, 131, 8, 19, 131, 31, 0,
  1, 0, 25, 28, 28, 27, 34, 140, 41, 128, 143, 27, 159, 27, 175, 27, 3, 27, 27,
  14, 19, 8, 8, 14, 143, 5, 0, 47, 241, 200, 47, 50, 16, 202, 47, 93, 26, 220,
  225, 18, 57, 17, 51, 1, 47, 93, 225, 47, 225, 18, 57, 47, 43, 193, 51, 47, 57,
  47, 51, 47, 48, 49, 1, 14, 3, 35, 34, 38, 39, 51, 30, 3, 51, 50, 62, 2, 55,
  39, 20, 14, 2, 7, 7, 35, 39, 54, 54, 53, 52, 38, 35, 34, 6, 7, 53, 54, 54, 51,
  50, 22, 3, 147, 4, 44, 76, 110, 71, 146, 144, 7, 109, 4, 27, 48, 68, 43, 36,
  66, 51, 34, 4, 43, 20, 35, 45, 25, 6, 86, 11, 56, 65, 57, 43, 22, 39, 11, 11,
  38, 31, 99, 100, 5, 227, 60, 99, 69, 38, 139, 127, 43, 49, 26, 7, 9, 27, 49,
  40, 150, 29, 43, 31, 20, 6, 41, 90, 9, 32, 37, 37, 24, 3, 3, 82, 3, 3, 69, 0,
  2, 1, 35, 4, 217, 3, 168, 7, 16, 0, 19, 0, 47, 0, 88, 64, 24, 25, 34, 20, 39,
  34, 39, 43, 28, 130, 29, 29, 9, 131, 8, 42, 130, 43, 43, 19, 131, 0, 42, 42,
  34, 184, 1, 1, 178, 25, 29, 39, 184, 1, 1, 64, 12, 64, 20, 20, 29, 8, 19, 19,
  8, 128, 14, 143, 5, 0, 47, 225, 26, 205, 50, 47, 16, 198, 50, 47, 26, 237, 16,
  220, 237, 50, 47, 1, 47, 225, 51, 47, 225, 47, 225, 51, 47, 225, 18, 57, 57,
  17, 51, 17, 51, 49, 48, 1, 14, 3, 35, 34, 38, 39, 51, 30, 3, 51, 50, 62, 2,
  55, 39, 34, 46, 2, 35, 34, 6, 7, 35, 62, 3, 51, 50, 30, 2, 51, 50, 54, 55, 51,
  14, 3, 3, 139, 4, 44, 76, 110, 71, 146, 145, 6, 109, 4, 27, 48, 67, 44, 36,
  65, 51, 34, 5, 47, 36, 72, 69, 63, 29, 40, 42, 14, 92, 5, 28, 48, 66, 41, 38,
  74, 69, 62, 26, 40, 42, 14, 92, 4, 29, 48, 66, 5, 227, 60, 99, 69, 38, 139,
  127, 43, 49, 26, 7, 9, 27, 49, 40, 80, 28, 34, 28, 42, 50, 48, 81, 59, 33, 28,
  34, 28, 43, 49, 48, 81, 59, 33, 0, 0, 1, 1, 199, 254, 66, 3, 6, 0, 0, 0, 20,
  0, 34, 64, 18, 3, 15, 2, 31, 2, 47, 2, 3, 2, 2, 14, 8, 132, 0, 18, 142, 11, 2,
  0, 47, 47, 225, 1, 47, 237, 204, 51, 47, 93, 51, 48, 49, 5, 52, 39, 51, 30, 3,
  21, 20, 6, 35, 34, 38, 39, 53, 22, 22, 51, 50, 54, 2, 113, 140, 129, 26, 57,
  47, 30, 100, 101, 29, 63, 26, 14, 45, 25, 34, 52, 238, 106, 132, 19, 52, 64,
  75, 42, 90, 104, 8, 8, 113, 4, 5, 43, 0, 0, 1, 1, 178, 254, 109, 3, 25, 0,
  166, 0, 17, 0, 24, 64, 10, 9, 1, 73, 16, 10, 13, 80, 9, 6, 0, 0, 47, 47, 51,
  225, 50, 1, 47, 225, 204, 48, 49, 37, 17, 14, 3, 35, 34, 38, 39, 53, 22, 22,
  51, 50, 54, 53, 17, 3, 25, 1, 26, 57, 89, 63, 38, 63, 22, 14, 59, 34, 46, 50,
  166, 254, 217, 66, 102, 70, 36, 17, 9, 150, 7, 14, 49, 49, 1, 60, 0, 0, 1, 1,
  178, 254, 109, 3, 25, 0, 154, 0, 17, 0, 24, 64, 10, 9, 1, 73, 16, 10, 13, 80,
  9, 6, 0, 0, 47, 47, 51, 237, 50, 1, 47, 225, 204, 48, 49, 37, 17, 14, 3, 35,
  34, 38, 39, 53, 22, 22, 51, 50, 54, 53, 17, 3, 25, 1, 26, 57, 89, 63, 38, 63,
  22, 14, 59, 34, 46, 50, 154, 254, 229, 66, 102, 70, 36, 17, 9, 150, 7, 14, 49,
  49, 1, 48, 0, 0, 0, 0, 0, 0, 27, 1, 74, 0, 1, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 1, 0, 15, 0, 52, 0, 1, 0, 0, 0, 0, 0, 2, 0, 7, 0, 67, 0,
  1, 0, 0, 0, 0, 0, 3, 0, 26, 0, 74, 0, 1, 0, 0, 0, 0, 0, 4, 0, 15, 0, 52, 0, 1,
  0, 0, 0, 0, 0, 5, 0, 12, 0, 100, 0, 1, 0, 0, 0, 0, 0, 6, 0, 13, 0, 112, 0, 1,
  0, 0, 0, 0, 0, 7, 0, 78, 0, 125, 0, 1, 0, 0, 0, 0, 0, 8, 0, 20, 0, 203, 0, 1,
  0, 0, 0, 0, 0, 10, 0, 103, 0, 223, 0, 1, 0, 0, 0, 0, 0, 13, 0, 46, 1, 70, 0,
  1, 0, 0, 0, 0, 0, 14, 0, 42, 1, 116, 0, 1, 0, 0, 0, 0, 0, 18, 0, 15, 0, 52, 0,
  3, 0, 1, 4, 9, 0, 0, 0, 104, 1, 158, 0, 3, 0, 1, 4, 9, 0, 1, 0, 30, 2, 6, 0,
  3, 0, 1, 4, 9, 0, 2, 0, 14, 2, 36, 0, 3, 0, 1, 4, 9, 0, 3, 0, 52, 2, 50, 0, 3,
  0, 1, 4, 9, 0, 4, 0, 30, 2, 6, 0, 3, 0, 1, 4, 9, 0, 5, 0, 44, 2, 102, 0, 3, 0,
  1, 4, 9, 0, 6, 0, 26, 2, 146, 0, 3, 0, 1, 4, 9, 0, 7, 0, 156, 2, 172, 0, 3, 0,
  1, 4, 9, 0, 8, 0, 40, 3, 72, 0, 3, 0, 1, 4, 9, 0, 10, 0, 206, 3, 112, 0, 3, 0,
  1, 4, 9, 0, 11, 0, 56, 4, 62, 0, 3, 0, 1, 4, 9, 0, 12, 0, 92, 4, 118, 0, 3, 0,
  1, 4, 9, 0, 13, 0, 92, 4, 210, 0, 3, 0, 1, 4, 9, 0, 14, 0, 84, 5, 46, 68, 105,
  103, 105, 116, 105, 122, 101, 100, 32, 100, 97, 116, 97, 32, 99, 111, 112,
  121, 114, 105, 103, 104, 116, 32, 169, 32, 50, 48, 48, 55, 44, 32, 71, 111,
  111, 103, 108, 101, 32, 67, 111, 114, 112, 111, 114, 97, 116, 105, 111, 110,
  46, 68, 114, 111, 105, 100, 32, 83, 97, 110, 115, 32, 77, 111, 110, 111, 82,
  101, 103, 117, 108, 97, 114, 65, 115, 99, 101, 110, 100, 101, 114, 32, 45, 32,
  68, 114, 111, 105, 100, 32, 83, 97, 110, 115, 32, 77, 111, 110, 111, 86, 101,
  114, 115, 105, 111, 110, 32, 49, 46, 48, 48, 68, 114, 111, 105, 100, 83, 97,
  110, 115, 77, 111, 110, 111, 68, 114, 111, 105, 100, 32, 105, 115, 32, 97, 32,
  116, 114, 97, 100, 101, 109, 97, 114, 107, 32, 111, 102, 32, 71, 111, 111,
  103, 108, 101, 32, 97, 110, 100, 32, 109, 97, 121, 32, 98, 101, 32, 114, 101,
  103, 105, 115, 116, 101, 114, 101, 100, 32, 105, 110, 32, 99, 101, 114, 116,
  97, 105, 110, 32, 106, 117, 114, 105, 115, 100, 105, 99, 116, 105, 111, 110,
  115, 46, 65, 115, 99, 101, 110, 100, 101, 114, 32, 67, 111, 114, 112, 111,
  114, 97, 116, 105, 111, 110, 68, 114, 111, 105, 100, 32, 83, 97, 110, 115, 32,
  105, 115, 32, 97, 32, 104, 117, 109, 97, 110, 105, 115, 116, 32, 115, 97, 110,
  115, 32, 115, 101, 114, 105, 102, 32, 116, 121, 112, 101, 102, 97, 99, 101,
  32, 100, 101, 115, 105, 103, 110, 101, 100, 32, 102, 111, 114, 32, 117, 115,
  101, 114, 32, 105, 110, 116, 101, 114, 102, 97, 99, 101, 115, 32, 97, 110,
  100, 32, 101, 108, 101, 99, 116, 114, 111, 110, 105, 99, 32, 99, 111, 109,
  109, 117, 110, 105, 99, 97, 116, 105, 111, 110, 46, 76, 105, 99, 101, 110,
  115, 101, 100, 32, 117, 110, 100, 101, 114, 32, 116, 104, 101, 32, 65, 112,
  97, 99, 104, 101, 32, 76, 105, 99, 101, 110, 115, 101, 44, 32, 86, 101, 114,
  115, 105, 111, 110, 32, 50, 46, 48, 104, 116, 116, 112, 58, 47, 47, 119, 119,
  119, 46, 97, 112, 97, 99, 104, 101, 46, 111, 114, 103, 47, 108, 105, 99, 101,
  110, 115, 101, 115, 47, 76, 73, 67, 69, 78, 83, 69, 45, 50, 46, 48, 0, 68, 0,
  105, 0, 103, 0, 105, 0, 116, 0, 105, 0, 122, 0, 101, 0, 100, 0, 32, 0, 100, 0,
  97, 0, 116, 0, 97, 0, 32, 0, 99, 0, 111, 0, 112, 0, 121, 0, 114, 0, 105, 0,
  103, 0, 104, 0, 116, 0, 32, 0, 169, 0, 32, 0, 50, 0, 48, 0, 48, 0, 55, 0, 44,
  0, 32, 0, 71, 0, 111, 0, 111, 0, 103, 0, 108, 0, 101, 0, 32, 0, 67, 0, 111, 0,
  114, 0, 112, 0, 111, 0, 114, 0, 97, 0, 116, 0, 105, 0, 111, 0, 110, 0, 46, 0,
  68, 0, 114, 0, 111, 0, 105, 0, 100, 0, 32, 0, 83, 0, 97, 0, 110, 0, 115, 0,
  32, 0, 77, 0, 111, 0, 110, 0, 111, 0, 82, 0, 101, 0, 103, 0, 117, 0, 108, 0,
  97, 0, 114, 0, 65, 0, 115, 0, 99, 0, 101, 0, 110, 0, 100, 0, 101, 0, 114, 0,
  32, 0, 45, 0, 32, 0, 68, 0, 114, 0, 111, 0, 105, 0, 100, 0, 32, 0, 83, 0, 97,
  0, 110, 0, 115, 0, 32, 0, 77, 0, 111, 0, 110, 0, 111, 0, 86, 0, 101, 0, 114,
  0, 115, 0, 105, 0, 111, 0, 110, 0, 32, 0, 49, 0, 46, 0, 48, 0, 48, 0, 32, 0,
  98, 0, 117, 0, 105, 0, 108, 0, 100, 0, 32, 0, 49, 0, 49, 0, 50, 0, 68, 0, 114,
  0, 111, 0, 105, 0, 100, 0, 83, 0, 97, 0, 110, 0, 115, 0, 77, 0, 111, 0, 110,
  0, 111, 0, 68, 0, 114, 0, 111, 0, 105, 0, 100, 0, 32, 0, 105, 0, 115, 0, 32,
  0, 97, 0, 32, 0, 116, 0, 114, 0, 97, 0, 100, 0, 101, 0, 109, 0, 97, 0, 114, 0,
  107, 0, 32, 0, 111, 0, 102, 0, 32, 0, 71, 0, 111, 0, 111, 0, 103, 0, 108, 0,
  101, 0, 32, 0, 97, 0, 110, 0, 100, 0, 32, 0, 109, 0, 97, 0, 121, 0, 32, 0, 98,
  0, 101, 0, 32, 0, 114, 0, 101, 0, 103, 0, 105, 0, 115, 0, 116, 0, 101, 0, 114,
  0, 101, 0, 100, 0, 32, 0, 105, 0, 110, 0, 32, 0, 99, 0, 101, 0, 114, 0, 116,
  0, 97, 0, 105, 0, 110, 0, 32, 0, 106, 0, 117, 0, 114, 0, 105, 0, 115, 0, 100,
  0, 105, 0, 99, 0, 116, 0, 105, 0, 111, 0, 110, 0, 115, 0, 46, 0, 65, 0, 115,
  0, 99, 0, 101, 0, 110, 0, 100, 0, 101, 0, 114, 0, 32, 0, 67, 0, 111, 0, 114,
  0, 112, 0, 111, 0, 114, 0, 97, 0, 116, 0, 105, 0, 111, 0, 110, 0, 68, 0, 114,
  0, 111, 0, 105, 0, 100, 0, 32, 0, 83, 0, 97, 0, 110, 0, 115, 0, 32, 0, 105, 0,
  115, 0, 32, 0, 97, 0, 32, 0, 104, 0, 117, 0, 109, 0, 97, 0, 110, 0, 105, 0,
  115, 0, 116, 0, 32, 0, 115, 0, 97, 0, 110, 0, 115, 0, 32, 0, 115, 0, 101, 0,
  114, 0, 105, 0, 102, 0, 32, 0, 116, 0, 121, 0, 112, 0, 101, 0, 102, 0, 97, 0,
  99, 0, 101, 0, 32, 0, 100, 0, 101, 0, 115, 0, 105, 0, 103, 0, 110, 0, 101, 0,
  100, 0, 32, 0, 102, 0, 111, 0, 114, 0, 32, 0, 117, 0, 115, 0, 101, 0, 114, 0,
  32, 0, 105, 0, 110, 0, 116, 0, 101, 0, 114, 0, 102, 0, 97, 0, 99, 0, 101, 0,
  115, 0, 32, 0, 97, 0, 110, 0, 100, 0, 32, 0, 101, 0, 108, 0, 101, 0, 99, 0,
  116, 0, 114, 0, 111, 0, 110, 0, 105, 0, 99, 0, 32, 0, 99, 0, 111, 0, 109, 0,
  109, 0, 117, 0, 110, 0, 105, 0, 99, 0, 97, 0, 116, 0, 105, 0, 111, 0, 110, 0,
  46, 0, 104, 0, 116, 0, 116, 0, 112, 0, 58, 0, 47, 0, 47, 0, 119, 0, 119, 0,
  119, 0, 46, 0, 97, 0, 115, 0, 99, 0, 101, 0, 110, 0, 100, 0, 101, 0, 114, 0,
  99, 0, 111, 0, 114, 0, 112, 0, 46, 0, 99, 0, 111, 0, 109, 0, 47, 0, 104, 0,
  116, 0, 116, 0, 112, 0, 58, 0, 47, 0, 47, 0, 119, 0, 119, 0, 119, 0, 46, 0,
  97, 0, 115, 0, 99, 0, 101, 0, 110, 0, 100, 0, 101, 0, 114, 0, 99, 0, 111, 0,
  114, 0, 112, 0, 46, 0, 99, 0, 111, 0, 109, 0, 47, 0, 116, 0, 121, 0, 112, 0,
  101, 0, 100, 0, 101, 0, 115, 0, 105, 0, 103, 0, 110, 0, 101, 0, 114, 0, 115,
  0, 46, 0, 104, 0, 116, 0, 109, 0, 108, 0, 76, 0, 105, 0, 99, 0, 101, 0, 110,
  0, 115, 0, 101, 0, 100, 0, 32, 0, 117, 0, 110, 0, 100, 0, 101, 0, 114, 0, 32,
  0, 116, 0, 104, 0, 101, 0, 32, 0, 65, 0, 112, 0, 97, 0, 99, 0, 104, 0, 101, 0,
  32, 0, 76, 0, 105, 0, 99, 0, 101, 0, 110, 0, 115, 0, 101, 0, 44, 0, 32, 0, 86,
  0, 101, 0, 114, 0, 115, 0, 105, 0, 111, 0, 110, 0, 32, 0, 50, 0, 46, 0, 48, 0,
  104, 0, 116, 0, 116, 0, 112, 0, 58, 0, 47, 0, 47, 0, 119, 0, 119, 0, 119, 0,
  46, 0, 97, 0, 112, 0, 97, 0, 99, 0, 104, 0, 101, 0, 46, 0, 111, 0, 114, 0,
  103, 0, 47, 0, 108, 0, 105, 0, 99, 0, 101, 0, 110, 0, 115, 0, 101, 0, 115, 0,
  47, 0, 76, 0, 73, 0, 67, 0, 69, 0, 78, 0, 83, 0, 69, 0, 45, 0, 50, 0, 46, 0,
  48, 0, 2, 0, 0, 0, 0, 0, 0, 255, 102, 0, 102, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 130, 0, 0, 1, 2, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6,
  0, 7, 0, 8, 0, 9, 0, 10, 0, 11, 0, 12, 0, 13, 0, 14, 0, 15, 0, 16, 0, 17, 0,
  18, 0, 19, 0, 20, 0, 21, 0, 22, 0, 23, 0, 24, 0, 25, 0, 26, 0, 27, 0, 28, 0,
  29, 0, 30, 0, 31, 0, 32, 0, 33, 0, 34, 0, 35, 0, 36, 0, 37, 0, 38, 0, 39, 0,
  40, 0, 41, 0, 42, 0, 43, 0, 44, 0, 45, 0, 46, 0, 47, 0, 48, 0, 49, 0, 50, 0,
  51, 0, 52, 0, 53, 0, 54, 0, 55, 0, 56, 0, 57, 0, 58, 0, 59, 0, 60, 0, 61, 0,
  62, 0, 63, 0, 64, 0, 65, 0, 66, 0, 67, 0, 68, 0, 69, 0, 70, 0, 71, 0, 72, 0,
  73, 0, 74, 0, 75, 0, 76, 0, 77, 0, 78, 0, 79, 0, 80, 0, 81, 0, 82, 0, 83, 0,
  84, 0, 85, 0, 86, 0, 87, 0, 88, 0, 89, 0, 90, 0, 91, 0, 92, 0, 93, 0, 94, 0,
  95, 0, 96, 0, 97, 0, 172, 0, 163, 0, 132, 0, 133, 0, 189, 0, 150, 0, 232, 0,
  134, 0, 142, 0, 139, 0, 157, 0, 169, 0, 164, 1, 3, 0, 138, 1, 4, 0, 131, 0,
  147, 0, 242, 0, 243, 0, 141, 0, 151, 0, 136, 1, 5, 0, 222, 0, 241, 0, 158, 0,
  170, 0, 245, 0, 244, 0, 246, 0, 162, 0, 173, 0, 201, 0, 199, 0, 174, 0, 98, 0,
  99, 0, 144, 0, 100, 0, 203, 0, 101, 0, 200, 0, 202, 0, 207, 0, 204, 0, 205, 0,
  206, 0, 233, 0, 102, 0, 211, 0, 208, 0, 209, 0, 175, 0, 103, 0, 240, 0, 145,
  0, 214, 0, 212, 0, 213, 0, 104, 0, 235, 0, 237, 0, 137, 0, 106, 0, 105, 0,
  107, 0, 109, 0, 108, 0, 110, 0, 160, 0, 111, 0, 113, 0, 112, 0, 114, 0, 115,
  0, 117, 0, 116, 0, 118, 0, 119, 0, 234, 0, 120, 0, 122, 0, 121, 0, 123, 0,
  125, 0, 124, 0, 184, 0, 161, 0, 127, 0, 126, 0, 128, 0, 129, 0, 236, 0, 238,
  0, 186, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11, 0, 253, 0, 254, 1, 12, 1, 13, 1,
  14, 1, 15, 0, 255, 1, 0, 1, 16, 1, 17, 1, 18, 1, 19, 1, 20, 1, 21, 1, 22, 1,
  23, 1, 24, 1, 25, 1, 26, 1, 27, 1, 28, 1, 29, 1, 30, 1, 31, 0, 248, 0, 249, 1,
  32, 1, 33, 1, 34, 1, 35, 1, 36, 1, 37, 1, 38, 1, 39, 1, 40, 1, 41, 1, 42, 1,
  43, 1, 44, 1, 45, 1, 46, 1, 47, 1, 48, 0, 215, 1, 49, 1, 50, 1, 51, 1, 52, 1,
  53, 1, 54, 1, 55, 1, 56, 1, 57, 1, 58, 1, 59, 1, 60, 1, 61, 1, 62, 1, 63, 0,
  226, 0, 227, 1, 64, 1, 65, 1, 66, 1, 67, 1, 68, 1, 69, 1, 70, 1, 71, 1, 72, 1,
  73, 1, 74, 1, 75, 1, 76, 1, 77, 1, 78, 0, 176, 0, 177, 1, 79, 1, 80, 1, 81, 1,
  82, 1, 83, 1, 84, 1, 85, 1, 86, 1, 87, 1, 88, 0, 251, 0, 252, 0, 228, 0, 229,
  1, 89, 1, 90, 1, 91, 1, 92, 1, 93, 1, 94, 1, 95, 1, 96, 1, 97, 1, 98, 1, 99,
  1, 100, 1, 101, 1, 102, 1, 103, 1, 104, 1, 105, 1, 106, 1, 107, 1, 108, 1,
  109, 1, 110, 0, 187, 1, 111, 1, 112, 1, 113, 1, 114, 0, 230, 0, 231, 1, 115,
  0, 166, 1, 116, 1, 117, 1, 118, 1, 119, 1, 120, 1, 121, 1, 122, 1, 123, 0,
  216, 0, 225, 1, 124, 0, 219, 0, 220, 0, 221, 0, 224, 0, 217, 0, 223, 1, 125,
  1, 126, 1, 127, 1, 128, 1, 129, 1, 130, 1, 131, 1, 132, 1, 133, 1, 134, 1,
  135, 1, 136, 1, 137, 1, 138, 1, 139, 1, 140, 1, 141, 1, 142, 1, 143, 1, 144,
  1, 145, 1, 146, 1, 147, 1, 148, 1, 149, 1, 150, 1, 151, 1, 152, 1, 153, 1,
  154, 1, 155, 1, 156, 1, 157, 1, 158, 1, 159, 1, 160, 1, 161, 1, 162, 1, 163,
  1, 164, 1, 165, 1, 166, 1, 167, 1, 168, 1, 169, 1, 170, 1, 171, 1, 172, 1,
  173, 1, 174, 1, 175, 1, 176, 1, 177, 1, 178, 1, 179, 1, 180, 1, 181, 0, 155,
  1, 182, 1, 183, 1, 184, 1, 185, 1, 186, 1, 187, 1, 188, 1, 189, 1, 190, 1,
  191, 1, 192, 1, 193, 1, 194, 1, 195, 1, 196, 1, 197, 1, 198, 1, 199, 1, 200,
  1, 201, 1, 202, 1, 203, 1, 204, 1, 205, 1, 206, 1, 207, 1, 208, 1, 209, 1,
  210, 1, 211, 1, 212, 1, 213, 1, 214, 1, 215, 1, 216, 1, 217, 1, 218, 1, 219,
  1, 220, 1, 221, 1, 222, 1, 223, 1, 224, 1, 225, 1, 226, 1, 227, 1, 228, 1,
  229, 1, 230, 1, 231, 1, 232, 1, 233, 1, 234, 1, 235, 1, 236, 1, 237, 1, 238,
  1, 239, 1, 240, 1, 241, 1, 242, 1, 243, 1, 244, 1, 245, 1, 246, 1, 247, 1,
  248, 1, 249, 1, 250, 1, 251, 1, 252, 1, 253, 1, 254, 1, 255, 2, 0, 2, 1, 2, 2,
  2, 3, 2, 4, 2, 5, 2, 6, 2, 7, 2, 8, 2, 9, 2, 10, 2, 11, 2, 12, 2, 13, 2, 14,
  2, 15, 2, 16, 2, 17, 2, 18, 2, 19, 2, 20, 2, 21, 2, 22, 2, 23, 2, 24, 2, 25,
  2, 26, 2, 27, 2, 28, 2, 29, 2, 30, 2, 31, 2, 32, 2, 33, 2, 34, 2, 35, 2, 36,
  2, 37, 2, 38, 2, 39, 2, 40, 2, 41, 0, 178, 0, 179, 2, 42, 2, 43, 0, 182, 0,
  183, 0, 196, 2, 44, 0, 180, 0, 181, 0, 197, 0, 130, 0, 194, 0, 135, 0, 171, 0,
  198, 2, 45, 2, 46, 0, 190, 0, 191, 2, 47, 0, 188, 2, 48, 0, 247, 2, 49, 2, 50,
  2, 51, 2, 52, 2, 53, 2, 54, 0, 140, 0, 159, 2, 55, 2, 56, 2, 57, 2, 58, 2, 59,
  0, 152, 2, 60, 0, 154, 0, 153, 0, 239, 0, 165, 0, 146, 0, 156, 0, 167, 0, 143,
  0, 148, 0, 149, 0, 185, 2, 61, 2, 62, 2, 63, 2, 64, 2, 65, 2, 66, 2, 67, 2,
  68, 2, 69, 2, 70, 2, 71, 2, 72, 2, 73, 2, 74, 2, 75, 2, 76, 2, 77, 2, 78, 2,
  79, 2, 80, 2, 81, 2, 82, 2, 83, 2, 84, 2, 85, 2, 86, 2, 87, 2, 88, 2, 89, 2,
  90, 2, 91, 2, 92, 2, 93, 2, 94, 2, 95, 2, 96, 2, 97, 2, 98, 2, 99, 2, 100, 2,
  101, 2, 102, 2, 103, 2, 104, 2, 105, 2, 106, 2, 107, 2, 108, 2, 109, 2, 110,
  2, 111, 2, 112, 2, 113, 2, 114, 2, 115, 2, 116, 2, 117, 2, 118, 2, 119, 2,
  120, 2, 121, 2, 122, 2, 123, 2, 124, 2, 125, 2, 126, 2, 127, 2, 128, 2, 129,
  2, 130, 2, 131, 2, 132, 2, 133, 2, 134, 2, 135, 2, 136, 2, 137, 2, 138, 2,
  139, 2, 140, 2, 141, 2, 142, 2, 143, 2, 144, 2, 145, 2, 146, 2, 147, 2, 148,
  2, 149, 2, 150, 2, 151, 2, 152, 2, 153, 2, 154, 2, 155, 2, 156, 2, 157, 2,
  158, 2, 159, 2, 160, 2, 161, 2, 162, 2, 163, 2, 164, 2, 165, 2, 166, 2, 167,
  2, 168, 2, 169, 2, 170, 2, 171, 2, 172, 2, 173, 2, 174, 2, 175, 2, 176, 2,
  177, 2, 178, 2, 179, 2, 180, 2, 181, 2, 182, 2, 183, 2, 184, 2, 185, 2, 186,
  2, 187, 2, 188, 2, 189, 2, 190, 2, 191, 2, 192, 2, 193, 2, 194, 2, 195, 2,
  196, 2, 197, 2, 198, 2, 199, 2, 200, 2, 201, 2, 202, 2, 203, 2, 204, 2, 205,
  2, 206, 2, 207, 2, 208, 2, 209, 2, 210, 2, 211, 2, 212, 2, 213, 2, 214, 2,
  215, 2, 216, 2, 217, 2, 218, 2, 219, 2, 220, 2, 221, 2, 222, 2, 223, 2, 224,
  2, 225, 2, 226, 2, 227, 2, 228, 2, 229, 2, 230, 2, 231, 2, 232, 2, 233, 2,
  234, 2, 235, 2, 236, 2, 237, 2, 238, 2, 239, 2, 240, 2, 241, 2, 242, 2, 243,
  2, 244, 2, 245, 2, 246, 2, 247, 2, 248, 2, 249, 2, 250, 2, 251, 2, 252, 2,
  253, 2, 254, 2, 255, 3, 0, 3, 1, 3, 2, 3, 3, 3, 4, 3, 5, 3, 6, 3, 7, 3, 8, 3,
  9, 3, 10, 3, 11, 3, 12, 3, 13, 3, 14, 3, 15, 3, 16, 3, 17, 3, 18, 3, 19, 3,
  20, 3, 21, 3, 22, 3, 23, 3, 24, 3, 25, 3, 26, 3, 27, 3, 28, 3, 29, 3, 30, 3,
  31, 3, 32, 3, 33, 3, 34, 3, 35, 3, 36, 3, 37, 3, 38, 3, 39, 3, 40, 3, 41, 3,
  42, 3, 43, 3, 44, 3, 45, 3, 46, 3, 47, 3, 48, 3, 49, 3, 50, 3, 51, 3, 52, 3,
  53, 3, 54, 3, 55, 3, 56, 3, 57, 3, 58, 3, 59, 3, 60, 3, 61, 3, 62, 3, 63, 3,
  64, 3, 65, 3, 66, 3, 67, 3, 68, 3, 69, 3, 70, 3, 71, 3, 72, 3, 73, 3, 74, 3,
  75, 3, 76, 3, 77, 3, 78, 3, 79, 3, 80, 3, 81, 3, 82, 3, 83, 3, 84, 3, 85, 3,
  86, 3, 87, 3, 88, 3, 89, 3, 90, 3, 91, 3, 92, 3, 93, 3, 94, 3, 95, 3, 96, 3,
  97, 3, 98, 3, 99, 3, 100, 3, 101, 3, 102, 3, 103, 3, 104, 3, 105, 3, 106, 3,
  107, 3, 108, 3, 109, 3, 110, 3, 111, 3, 112, 3, 113, 3, 114, 3, 115, 3, 116,
  3, 117, 3, 118, 3, 119, 3, 120, 3, 121, 3, 122, 3, 123, 3, 124, 3, 125, 3,
  126, 3, 127, 3, 128, 3, 129, 3, 130, 3, 131, 3, 132, 3, 133, 3, 134, 3, 135,
  3, 136, 3, 137, 3, 138, 5, 46, 110, 117, 108, 108, 7, 117, 110, 105, 48, 48,
  65, 68, 9, 111, 118, 101, 114, 115, 99, 111, 114, 101, 14, 112, 101, 114, 105,
  111, 100, 99, 101, 110, 116, 101, 114, 101, 100, 7, 65, 109, 97, 99, 114, 111,
  110, 7, 97, 109, 97, 99, 114, 111, 110, 6, 65, 98, 114, 101, 118, 101, 6, 97,
  98, 114, 101, 118, 101, 7, 65, 111, 103, 111, 110, 101, 107, 7, 97, 111, 103,
  111, 110, 101, 107, 11, 67, 99, 105, 114, 99, 117, 109, 102, 108, 101, 120,
  11, 99, 99, 105, 114, 99, 117, 109, 102, 108, 101, 120, 4, 67, 100, 111, 116,
  4, 99, 100, 111, 116, 6, 68, 99, 97, 114, 111, 110, 6, 100, 99, 97, 114, 111,
  110, 6, 68, 99, 114, 111, 97, 116, 6, 100, 99, 114, 111, 97, 116, 7, 69, 109,
  97, 99, 114, 111, 110, 7, 101, 109, 97, 99, 114, 111, 110, 6, 69, 98, 114,
  101, 118, 101, 6, 101, 98, 114, 101, 118, 101, 10, 69, 100, 111, 116, 97, 99,
  99, 101, 110, 116, 10, 101, 100, 111, 116, 97, 99, 99, 101, 110, 116, 7, 69,
  111, 103, 111, 110, 101, 107, 7, 101, 111, 103, 111, 110, 101, 107, 6, 69, 99,
  97, 114, 111, 110, 6, 101, 99, 97, 114, 111, 110, 11, 71, 99, 105, 114, 99,
  117, 109, 102, 108, 101, 120, 11, 103, 99, 105, 114, 99, 117, 109, 102, 108,
  101, 120, 4, 71, 100, 111, 116, 4, 103, 100, 111, 116, 12, 71, 99, 111, 109,
  109, 97, 97, 99, 99, 101, 110, 116, 12, 103, 99, 111, 109, 109, 97, 97, 99,
  99, 101, 110, 116, 11, 72, 99, 105, 114, 99, 117, 109, 102, 108, 101, 120, 11,
  104, 99, 105, 114, 99, 117, 109, 102, 108, 101, 120, 4, 72, 98, 97, 114, 4,
  104, 98, 97, 114, 6, 73, 116, 105, 108, 100, 101, 6, 105, 116, 105, 108, 100,
  101, 7, 73, 109, 97, 99, 114, 111, 110, 7, 105, 109, 97, 99, 114, 111, 110, 6,
  73, 98, 114, 101, 118, 101, 6, 105, 98, 114, 101, 118, 101, 7, 73, 111, 103,
  111, 110, 101, 107, 7, 105, 111, 103, 111, 110, 101, 107, 10, 73, 100, 111,
  116, 97, 99, 99, 101, 110, 116, 2, 73, 74, 2, 105, 106, 11, 74, 99, 105, 114,
  99, 117, 109, 102, 108, 101, 120, 11, 106, 99, 105, 114, 99, 117, 109, 102,
  108, 101, 120, 12, 75, 99, 111, 109, 109, 97, 97, 99, 99, 101, 110, 116, 12,
  107, 99, 111, 109, 109, 97, 97, 99, 99, 101, 110, 116, 12, 107, 103, 114, 101,
  101, 110, 108, 97, 110, 100, 105, 99, 6, 76, 97, 99, 117, 116, 101, 6, 108,
  97, 99, 117, 116, 101, 12, 76, 99, 111, 109, 109, 97, 97, 99, 99, 101, 110,
  116, 12, 108, 99, 111, 109, 109, 97, 97, 99, 99, 101, 110, 116, 6, 76, 99, 97,
  114, 111, 110, 6, 108, 99, 97, 114, 111, 110, 4, 76, 100, 111, 116, 4, 108,
  100, 111, 116, 6, 78, 97, 99, 117, 116, 101, 6, 110, 97, 99, 117, 116, 101,
  12, 78, 99, 111, 109, 109, 97, 97, 99, 99, 101, 110, 116, 12, 110, 99, 111,
  109, 109, 97, 97, 99, 99, 101, 110, 116, 6, 78, 99, 97, 114, 111, 110, 6, 110,
  99, 97, 114, 111, 110, 11, 110, 97, 112, 111, 115, 116, 114, 111, 112, 104,
  101, 3, 69, 110, 103, 3, 101, 110, 103, 7, 79, 109, 97, 99, 114, 111, 110, 7,
  111, 109, 97, 99, 114, 111, 110, 6, 79, 98, 114, 101, 118, 101, 6, 111, 98,
  114, 101, 118, 101, 13, 79, 104, 117, 110, 103, 97, 114, 117, 109, 108, 97,
  117, 116, 13, 111, 104, 117, 110, 103, 97, 114, 117, 109, 108, 97, 117, 116,
  6, 82, 97, 99, 117, 116, 101, 6, 114, 97, 99, 117, 116, 101, 12, 82, 99, 111,
  109, 109, 97, 97, 99, 99, 101, 110, 116, 12, 114, 99, 111, 109, 109, 97, 97,
  99, 99, 101, 110, 116, 6, 82, 99, 97, 114, 111, 110, 6, 114, 99, 97, 114, 111,
  110, 6, 83, 97, 99, 117, 116, 101, 6, 115, 97, 99, 117, 116, 101, 11, 83, 99,
  105, 114, 99, 117, 109, 102, 108, 101, 120, 11, 115, 99, 105, 114, 99, 117,
  109, 102, 108, 101, 120, 12, 84, 99, 111, 109, 109, 97, 97, 99, 99, 101, 110,
  116, 12, 116, 99, 111, 109, 109, 97, 97, 99, 99, 101, 110, 116, 6, 84, 99, 97,
  114, 111, 110, 6, 116, 99, 97, 114, 111, 110, 4, 84, 98, 97, 114, 4, 116, 98,
  97, 114, 6, 85, 116, 105, 108, 100, 101, 6, 117, 116, 105, 108, 100, 101, 7,
  85, 109, 97, 99, 114, 111, 110, 7, 117, 109, 97, 99, 114, 111, 110, 6, 85, 98,
  114, 101, 118, 101, 6, 117, 98, 114, 101, 118, 101, 5, 85, 114, 105, 110, 103,
  5, 117, 114, 105, 110, 103, 13, 85, 104, 117, 110, 103, 97, 114, 117, 109,
  108, 97, 117, 116, 13, 117, 104, 117, 110, 103, 97, 114, 117, 109, 108, 97,
  117, 116, 7, 85, 111, 103, 111, 110, 101, 107, 7, 117, 111, 103, 111, 110,
  101, 107, 11, 87, 99, 105, 114, 99, 117, 109, 102, 108, 101, 120, 11, 119, 99,
  105, 114, 99, 117, 109, 102, 108, 101, 120, 11, 89, 99, 105, 114, 99, 117,
  109, 102, 108, 101, 120, 11, 121, 99, 105, 114, 99, 117, 109, 102, 108, 101,
  120, 6, 90, 97, 99, 117, 116, 101, 6, 122, 97, 99, 117, 116, 101, 10, 90, 100,
  111, 116, 97, 99, 99, 101, 110, 116, 10, 122, 100, 111, 116, 97, 99, 99, 101,
  110, 116, 5, 108, 111, 110, 103, 115, 10, 65, 114, 105, 110, 103, 97, 99, 117,
  116, 101, 10, 97, 114, 105, 110, 103, 97, 99, 117, 116, 101, 7, 65, 69, 97,
  99, 117, 116, 101, 7, 97, 101, 97, 99, 117, 116, 101, 11, 79, 115, 108, 97,
  115, 104, 97, 99, 117, 116, 101, 11, 111, 115, 108, 97, 115, 104, 97, 99, 117,
  116, 101, 12, 83, 99, 111, 109, 109, 97, 97, 99, 99, 101, 110, 116, 12, 115,
  99, 111, 109, 109, 97, 97, 99, 99, 101, 110, 116, 6, 109, 97, 99, 114, 111,
  110, 5, 116, 111, 110, 111, 115, 13, 100, 105, 101, 114, 101, 115, 105, 115,
  116, 111, 110, 111, 115, 10, 65, 108, 112, 104, 97, 116, 111, 110, 111, 115,
  9, 97, 110, 111, 116, 101, 108, 101, 105, 97, 12, 69, 112, 115, 105, 108, 111,
  110, 116, 111, 110, 111, 115, 8, 69, 116, 97, 116, 111, 110, 111, 115, 9, 73,
  111, 116, 97, 116, 111, 110, 111, 115, 12, 79, 109, 105, 99, 114, 111, 110,
  116, 111, 110, 111, 115, 12, 85, 112, 115, 105, 108, 111, 110, 116, 111, 110,
  111, 115, 10, 79, 109, 101, 103, 97, 116, 111, 110, 111, 115, 17, 105, 111,
  116, 97, 100, 105, 101, 114, 101, 115, 105, 115, 116, 111, 110, 111, 115, 5,
  65, 108, 112, 104, 97, 4, 66, 101, 116, 97, 5, 71, 97, 109, 109, 97, 7, 117,
  110, 105, 48, 51, 57, 52, 7, 69, 112, 115, 105, 108, 111, 110, 4, 90, 101,
  116, 97, 3, 69, 116, 97, 5, 84, 104, 101, 116, 97, 4, 73, 111, 116, 97, 5, 75,
  97, 112, 112, 97, 6, 76, 97, 109, 98, 100, 97, 2, 77, 117, 2, 78, 117, 2, 88,
  105, 7, 79, 109, 105, 99, 114, 111, 110, 2, 80, 105, 3, 82, 104, 111, 5, 83,
  105, 103, 109, 97, 3, 84, 97, 117, 7, 85, 112, 115, 105, 108, 111, 110, 3, 80,
  104, 105, 3, 67, 104, 105, 3, 80, 115, 105, 7, 117, 110, 105, 48, 51, 65, 57,
  12, 73, 111, 116, 97, 100, 105, 101, 114, 101, 115, 105, 115, 15, 85, 112,
  115, 105, 108, 111, 110, 100, 105, 101, 114, 101, 115, 105, 115, 10, 97, 108,
  112, 104, 97, 116, 111, 110, 111, 115, 12, 101, 112, 115, 105, 108, 111, 110,
  116, 111, 110, 111, 115, 8, 101, 116, 97, 116, 111, 110, 111, 115, 9, 105,
  111, 116, 97, 116, 111, 110, 111, 115, 20, 117, 112, 115, 105, 108, 111, 110,
  100, 105, 101, 114, 101, 115, 105, 115, 116, 111, 110, 111, 115, 5, 97, 108,
  112, 104, 97, 4, 98, 101, 116, 97, 5, 103, 97, 109, 109, 97, 5, 100, 101, 108,
  116, 97, 7, 101, 112, 115, 105, 108, 111, 110, 4, 122, 101, 116, 97, 3, 101,
  116, 97, 5, 116, 104, 101, 116, 97, 4, 105, 111, 116, 97, 5, 107, 97, 112,
  112, 97, 6, 108, 97, 109, 98, 100, 97, 7, 117, 110, 105, 48, 51, 66, 67, 2,
  110, 117, 2, 120, 105, 7, 111, 109, 105, 99, 114, 111, 110, 3, 114, 104, 111,
  6, 115, 105, 103, 109, 97, 49, 5, 115, 105, 103, 109, 97, 3, 116, 97, 117, 7,
  117, 112, 115, 105, 108, 111, 110, 3, 112, 104, 105, 3, 99, 104, 105, 3, 112,
  115, 105, 5, 111, 109, 101, 103, 97, 12, 105, 111, 116, 97, 100, 105, 101,
  114, 101, 115, 105, 115, 15, 117, 112, 115, 105, 108, 111, 110, 100, 105, 101,
  114, 101, 115, 105, 115, 12, 111, 109, 105, 99, 114, 111, 110, 116, 111, 110,
  111, 115, 12, 117, 112, 115, 105, 108, 111, 110, 116, 111, 110, 111, 115, 10,
  111, 109, 101, 103, 97, 116, 111, 110, 111, 115, 9, 97, 102, 105, 105, 49, 48,
  48, 50, 51, 9, 97, 102, 105, 105, 49, 48, 48, 53, 49, 9, 97, 102, 105, 105,
  49, 48, 48, 53, 50, 9, 97, 102, 105, 105, 49, 48, 48, 53, 51, 9, 97, 102, 105,
  105, 49, 48, 48, 53, 52, 9, 97, 102, 105, 105, 49, 48, 48, 53, 53, 9, 97, 102,
  105, 105, 49, 48, 48, 53, 54, 9, 97, 102, 105, 105, 49, 48, 48, 53, 55, 9, 97,
  102, 105, 105, 49, 48, 48, 53, 56, 9, 97, 102, 105, 105, 49, 48, 48, 53, 57,
  9, 97, 102, 105, 105, 49, 48, 48, 54, 48, 9, 97, 102, 105, 105, 49, 48, 48,
  54, 49, 9, 97, 102, 105, 105, 49, 48, 48, 54, 50, 9, 97, 102, 105, 105, 49,
  48, 49, 52, 53, 9, 97, 102, 105, 105, 49, 48, 48, 49, 55, 9, 97, 102, 105,
  105, 49, 48, 48, 49, 56, 9, 97, 102, 105, 105, 49, 48, 48, 49, 57, 9, 97, 102,
  105, 105, 49, 48, 48, 50, 48, 9, 97, 102, 105, 105, 49, 48, 48, 50, 49, 9, 97,
  102, 105, 105, 49, 48, 48, 50, 50, 9, 97, 102, 105, 105, 49, 48, 48, 50, 52,
  9, 97, 102, 105, 105, 49, 48, 48, 50, 53, 9, 97, 102, 105, 105, 49, 48, 48,
  50, 54, 9, 97, 102, 105, 105, 49, 48, 48, 50, 55, 9, 97, 102, 105, 105, 49,
  48, 48, 50, 56, 9, 97, 102, 105, 105, 49, 48, 48, 50, 57, 9, 97, 102, 105,
  105, 49, 48, 48, 51, 48, 9, 97, 102, 105, 105, 49, 48, 48, 51, 49, 9, 97, 102,
  105, 105, 49, 48, 48, 51, 50, 9, 97, 102, 105, 105, 49, 48, 48, 51, 51, 9, 97,
  102, 105, 105, 49, 48, 48, 51, 52, 9, 97, 102, 105, 105, 49, 48, 48, 51, 53,
  9, 97, 102, 105, 105, 49, 48, 48, 51, 54, 9, 97, 102, 105, 105, 49, 48, 48,
  51, 55, 9, 97, 102, 105, 105, 49, 48, 48, 51, 56, 9, 97, 102, 105, 105, 49,
  48, 48, 51, 57, 9, 97, 102, 105, 105, 49, 48, 48, 52, 48, 9, 97, 102, 105,
  105, 49, 48, 48, 52, 49, 9, 97, 102, 105, 105, 49, 48, 48, 52, 50, 9, 97, 102,
  105, 105, 49, 48, 48, 52, 51, 9, 97, 102, 105, 105, 49, 48, 48, 52, 52, 9, 97,
  102, 105, 105, 49, 48, 48, 52, 53, 9, 97, 102, 105, 105, 49, 48, 48, 52, 54,
  9, 97, 102, 105, 105, 49, 48, 48, 52, 55, 9, 97, 102, 105, 105, 49, 48, 48,
  52, 56, 9, 97, 102, 105, 105, 49, 48, 48, 52, 57, 9, 97, 102, 105, 105, 49,
  48, 48, 54, 53, 9, 97, 102, 105, 105, 49, 48, 48, 54, 54, 9, 97, 102, 105,
  105, 49, 48, 48, 54, 55, 9, 97, 102, 105, 105, 49, 48, 48, 54, 56, 9, 97, 102,
  105, 105, 49, 48, 48, 54, 57, 9, 97, 102, 105, 105, 49, 48, 48, 55, 48, 9, 97,
  102, 105, 105, 49, 48, 48, 55, 50, 9, 97, 102, 105, 105, 49, 48, 48, 55, 51,
  9, 97, 102, 105, 105, 49, 48, 48, 55, 52, 9, 97, 102, 105, 105, 49, 48, 48,
  55, 53, 9, 97, 102, 105, 105, 49, 48, 48, 55, 54, 9, 97, 102, 105, 105, 49,
  48, 48, 55, 55, 9, 97, 102, 105, 105, 49, 48, 48, 55, 56, 9, 97, 102, 105,
  105, 49, 48, 48, 55, 57, 9, 97, 102, 105, 105, 49, 48, 48, 56, 48, 9, 97, 102,
  105, 105, 49, 48, 48, 56, 49, 9, 97, 102, 105, 105, 49, 48, 48, 56, 50, 9, 97,
  102, 105, 105, 49, 48, 48, 56, 51, 9, 97, 102, 105, 105, 49, 48, 48, 56, 52,
  9, 97, 102, 105, 105, 49, 48, 48, 56, 53, 9, 97, 102, 105, 105, 49, 48, 48,
  56, 54, 9, 97, 102, 105, 105, 49, 48, 48, 56, 55, 9, 97, 102, 105, 105, 49,
  48, 48, 56, 56, 9, 97, 102, 105, 105, 49, 48, 48, 56, 57, 9, 97, 102, 105,
  105, 49, 48, 48, 57, 48, 9, 97, 102, 105, 105, 49, 48, 48, 57, 49, 9, 97, 102,
  105, 105, 49, 48, 48, 57, 50, 9, 97, 102, 105, 105, 49, 48, 48, 57, 51, 9, 97,
  102, 105, 105, 49, 48, 48, 57, 52, 9, 97, 102, 105, 105, 49, 48, 48, 57, 53,
  9, 97, 102, 105, 105, 49, 48, 48, 57, 54, 9, 97, 102, 105, 105, 49, 48, 48,
  57, 55, 9, 97, 102, 105, 105, 49, 48, 48, 55, 49, 9, 97, 102, 105, 105, 49,
  48, 48, 57, 57, 9, 97, 102, 105, 105, 49, 48, 49, 48, 48, 9, 97, 102, 105,
  105, 49, 48, 49, 48, 49, 9, 97, 102, 105, 105, 49, 48, 49, 48, 50, 9, 97, 102,
  105, 105, 49, 48, 49, 48, 51, 9, 97, 102, 105, 105, 49, 48, 49, 48, 52, 9, 97,
  102, 105, 105, 49, 48, 49, 48, 53, 9, 97, 102, 105, 105, 49, 48, 49, 48, 54,
  9, 97, 102, 105, 105, 49, 48, 49, 48, 55, 9, 97, 102, 105, 105, 49, 48, 49,
  48, 56, 9, 97, 102, 105, 105, 49, 48, 49, 48, 57, 9, 97, 102, 105, 105, 49,
  48, 49, 49, 48, 9, 97, 102, 105, 105, 49, 48, 49, 57, 51, 9, 97, 102, 105,
  105, 49, 48, 48, 53, 48, 9, 97, 102, 105, 105, 49, 48, 48, 57, 56, 6, 87, 103,
  114, 97, 118, 101, 6, 119, 103, 114, 97, 118, 101, 6, 87, 97, 99, 117, 116,
  101, 6, 119, 97, 99, 117, 116, 101, 9, 87, 100, 105, 101, 114, 101, 115, 105,
  115, 9, 119, 100, 105, 101, 114, 101, 115, 105, 115, 6, 89, 103, 114, 97, 118,
  101, 6, 121, 103, 114, 97, 118, 101, 9, 97, 102, 105, 105, 48, 48, 50, 48, 56,
  13, 117, 110, 100, 101, 114, 115, 99, 111, 114, 101, 100, 98, 108, 13, 113,
  117, 111, 116, 101, 114, 101, 118, 101, 114, 115, 101, 100, 6, 109, 105, 110,
  117, 116, 101, 6, 115, 101, 99, 111, 110, 100, 9, 101, 120, 99, 108, 97, 109,
  100, 98, 108, 9, 110, 115, 117, 112, 101, 114, 105, 111, 114, 9, 97, 102, 105,
  105, 48, 56, 57, 52, 49, 6, 112, 101, 115, 101, 116, 97, 4, 69, 117, 114, 111,
  9, 97, 102, 105, 105, 54, 49, 50, 52, 56, 9, 97, 102, 105, 105, 54, 49, 50,
  56, 57, 9, 97, 102, 105, 105, 54, 49, 51, 53, 50, 9, 101, 115, 116, 105, 109,
  97, 116, 101, 100, 9, 111, 110, 101, 101, 105, 103, 104, 116, 104, 12, 116,
  104, 114, 101, 101, 101, 105, 103, 104, 116, 104, 115, 11, 102, 105, 118, 101,
  101, 105, 103, 104, 116, 104, 115, 12, 115, 101, 118, 101, 110, 101, 105, 103,
  104, 116, 104, 115, 5, 68, 101, 108, 116, 97, 7, 117, 110, 105, 70, 66, 48,
  49, 7, 117, 110, 105, 70, 66, 48, 50, 13, 99, 121, 114, 105, 108, 108, 105,
  99, 98, 114, 101, 118, 101, 8, 100, 111, 116, 108, 101, 115, 115, 106, 16, 99,
  97, 114, 111, 110, 99, 111, 109, 109, 97, 97, 99, 99, 101, 110, 116, 11, 99,
  111, 109, 109, 97, 97, 99, 99, 101, 110, 116, 17, 99, 111, 109, 109, 97, 97,
  99, 99, 101, 110, 116, 114, 111, 116, 97, 116, 101, 12, 122, 101, 114, 111,
  115, 117, 112, 101, 114, 105, 111, 114, 12, 102, 111, 117, 114, 115, 117, 112,
  101, 114, 105, 111, 114, 12, 102, 105, 118, 101, 115, 117, 112, 101, 114, 105,
  111, 114, 11, 115, 105, 120, 115, 117, 112, 101, 114, 105, 111, 114, 13, 115,
  101, 118, 101, 110, 115, 117, 112, 101, 114, 105, 111, 114, 13, 101, 105, 103,
  104, 116, 115, 117, 112, 101, 114, 105, 111, 114, 12, 110, 105, 110, 101, 115,
  117, 112, 101, 114, 105, 111, 114, 7, 117, 110, 105, 50, 48, 48, 48, 7, 117,
  110, 105, 50, 48, 48, 49, 7, 117, 110, 105, 50, 48, 48, 50, 7, 117, 110, 105,
  50, 48, 48, 51, 7, 117, 110, 105, 50, 48, 48, 52, 7, 117, 110, 105, 50, 48,
  48, 53, 7, 117, 110, 105, 50, 48, 48, 54, 7, 117, 110, 105, 50, 48, 48, 55, 7,
  117, 110, 105, 50, 48, 48, 56, 7, 117, 110, 105, 50, 48, 48, 57, 7, 117, 110,
  105, 50, 48, 48, 65, 7, 117, 110, 105, 50, 48, 48, 66, 7, 117, 110, 105, 70,
  69, 70, 70, 7, 117, 110, 105, 70, 70, 70, 67, 7, 117, 110, 105, 70, 70, 70,
  68, 7, 117, 110, 105, 48, 49, 70, 48, 7, 117, 110, 105, 48, 50, 66, 67, 7,
  117, 110, 105, 48, 51, 68, 49, 7, 117, 110, 105, 48, 51, 68, 50, 7, 117, 110,
  105, 48, 51, 68, 54, 7, 117, 110, 105, 49, 69, 51, 69, 7, 117, 110, 105, 49,
  69, 51, 70, 7, 117, 110, 105, 49, 69, 48, 48, 7, 117, 110, 105, 49, 69, 48,
  49, 7, 117, 110, 105, 49, 70, 52, 68, 7, 117, 110, 105, 48, 50, 70, 51, 9,
  100, 97, 115, 105, 97, 111, 120, 105, 97, 7, 117, 110, 105, 70, 66, 48, 51, 7,
  117, 110, 105, 70, 66, 48, 52, 5, 79, 104, 111, 114, 110, 5, 111, 104, 111,
  114, 110, 5, 85, 104, 111, 114, 110, 5, 117, 104, 111, 114, 110, 7, 117, 110,
  105, 48, 51, 48, 48, 7, 117, 110, 105, 48, 51, 48, 49, 7, 117, 110, 105, 48,
  51, 48, 51, 4, 104, 111, 111, 107, 8, 100, 111, 116, 98, 101, 108, 111, 119,
  7, 117, 110, 105, 48, 52, 48, 48, 7, 117, 110, 105, 48, 52, 48, 68, 7, 117,
  110, 105, 48, 52, 53, 48, 7, 117, 110, 105, 48, 52, 53, 68, 7, 117, 110, 105,
  48, 52, 54, 48, 7, 117, 110, 105, 48, 52, 54, 49, 7, 117, 110, 105, 48, 52,
  54, 50, 7, 117, 110, 105, 48, 52, 54, 51, 7, 117, 110, 105, 48, 52, 54, 52, 7,
  117, 110, 105, 48, 52, 54, 53, 7, 117, 110, 105, 48, 52, 54, 54, 7, 117, 110,
  105, 48, 52, 54, 55, 7, 117, 110, 105, 48, 52, 54, 56, 7, 117, 110, 105, 48,
  52, 54, 57, 7, 117, 110, 105, 48, 52, 54, 65, 7, 117, 110, 105, 48, 52, 54,
  66, 7, 117, 110, 105, 48, 52, 54, 67, 7, 117, 110, 105, 48, 52, 54, 68, 7,
  117, 110, 105, 48, 52, 54, 69, 7, 117, 110, 105, 48, 52, 54, 70, 7, 117, 110,
  105, 48, 52, 55, 48, 7, 117, 110, 105, 48, 52, 55, 49, 7, 117, 110, 105, 48,
  52, 55, 50, 7, 117, 110, 105, 48, 52, 55, 51, 7, 117, 110, 105, 48, 52, 55,
  52, 7, 117, 110, 105, 48, 52, 55, 53, 7, 117, 110, 105, 48, 52, 55, 54, 7,
  117, 110, 105, 48, 52, 55, 55, 7, 117, 110, 105, 48, 52, 55, 56, 7, 117, 110,
  105, 48, 52, 55, 57, 7, 117, 110, 105, 48, 52, 55, 65, 7, 117, 110, 105, 48,
  52, 55, 66, 7, 117, 110, 105, 48, 52, 55, 67, 7, 117, 110, 105, 48, 52, 55,
  68, 7, 117, 110, 105, 48, 52, 55, 69, 7, 117, 110, 105, 48, 52, 55, 70, 7,
  117, 110, 105, 48, 52, 56, 48, 7, 117, 110, 105, 48, 52, 56, 49, 7, 117, 110,
  105, 48, 52, 56, 50, 7, 117, 110, 105, 48, 52, 56, 51, 7, 117, 110, 105, 48,
  52, 56, 52, 7, 117, 110, 105, 48, 52, 56, 53, 7, 117, 110, 105, 48, 52, 56,
  54, 7, 117, 110, 105, 48, 52, 56, 56, 7, 117, 110, 105, 48, 52, 56, 57, 7,
  117, 110, 105, 48, 52, 56, 65, 7, 117, 110, 105, 48, 52, 56, 66, 7, 117, 110,
  105, 48, 52, 56, 67, 7, 117, 110, 105, 48, 52, 56, 68, 7, 117, 110, 105, 48,
  52, 56, 69, 7, 117, 110, 105, 48, 52, 56, 70, 7, 117, 110, 105, 48, 52, 57,
  50, 7, 117, 110, 105, 48, 52, 57, 51, 7, 117, 110, 105, 48, 52, 57, 52, 7,
  117, 110, 105, 48, 52, 57, 53, 7, 117, 110, 105, 48, 52, 57, 54, 7, 117, 110,
  105, 48, 52, 57, 55, 7, 117, 110, 105, 48, 52, 57, 56, 7, 117, 110, 105, 48,
  52, 57, 57, 7, 117, 110, 105, 48, 52, 57, 65, 7, 117, 110, 105, 48, 52, 57,
  66, 7, 117, 110, 105, 48, 52, 57, 67, 7, 117, 110, 105, 48, 52, 57, 68, 7,
  117, 110, 105, 48, 52, 57, 69, 7, 117, 110, 105, 48, 52, 57, 70, 7, 117, 110,
  105, 48, 52, 65, 48, 7, 117, 110, 105, 48, 52, 65, 49, 7, 117, 110, 105, 48,
  52, 65, 50, 7, 117, 110, 105, 48, 52, 65, 51, 7, 117, 110, 105, 48, 52, 65,
  52, 7, 117, 110, 105, 48, 52, 65, 53, 7, 117, 110, 105, 48, 52, 65, 54, 7,
  117, 110, 105, 48, 52, 65, 55, 7, 117, 110, 105, 48, 52, 65, 56, 7, 117, 110,
  105, 48, 52, 65, 57, 7, 117, 110, 105, 48, 52, 65, 65, 7, 117, 110, 105, 48,
  52, 65, 66, 7, 117, 110, 105, 48, 52, 65, 67, 7, 117, 110, 105, 48, 52, 65,
  68, 7, 117, 110, 105, 48, 52, 65, 69, 7, 117, 110, 105, 48, 52, 65, 70, 7,
  117, 110, 105, 48, 52, 66, 48, 7, 117, 110, 105, 48, 52, 66, 49, 7, 117, 110,
  105, 48, 52, 66, 50, 7, 117, 110, 105, 48, 52, 66, 51, 7, 117, 110, 105, 48,
  52, 66, 52, 7, 117, 110, 105, 48, 52, 66, 53, 7, 117, 110, 105, 48, 52, 66,
  54, 7, 117, 110, 105, 48, 52, 66, 55, 7, 117, 110, 105, 48, 52, 66, 56, 7,
  117, 110, 105, 48, 52, 66, 57, 7, 117, 110, 105, 48, 52, 66, 65, 7, 117, 110,
  105, 48, 52, 66, 66, 7, 117, 110, 105, 48, 52, 66, 67, 7, 117, 110, 105, 48,
  52, 66, 68, 7, 117, 110, 105, 48, 52, 66, 69, 7, 117, 110, 105, 48, 52, 66,
  70, 7, 117, 110, 105, 48, 52, 67, 48, 7, 117, 110, 105, 48, 52, 67, 49, 7,
  117, 110, 105, 48, 52, 67, 50, 7, 117, 110, 105, 48, 52, 67, 51, 7, 117, 110,
  105, 48, 52, 67, 52, 7, 117, 110, 105, 48, 52, 67, 53, 7, 117, 110, 105, 48,
  52, 67, 54, 7, 117, 110, 105, 48, 52, 67, 55, 7, 117, 110, 105, 48, 52, 67,
  56, 7, 117, 110, 105, 48, 52, 67, 57, 7, 117, 110, 105, 48, 52, 67, 65, 7,
  117, 110, 105, 48, 52, 67, 66, 7, 117, 110, 105, 48, 52, 67, 67, 7, 117, 110,
  105, 48, 52, 67, 68, 7, 117, 110, 105, 48, 52, 67, 69, 7, 117, 110, 105, 48,
  52, 67, 70, 7, 117, 110, 105, 48, 52, 68, 48, 7, 117, 110, 105, 48, 52, 68,
  49, 7, 117, 110, 105, 48, 52, 68, 50, 7, 117, 110, 105, 48, 52, 68, 51, 7,
  117, 110, 105, 48, 52, 68, 52, 7, 117, 110, 105, 48, 52, 68, 53, 7, 117, 110,
  105, 48, 52, 68, 54, 7, 117, 110, 105, 48, 52, 68, 55, 7, 117, 110, 105, 48,
  52, 68, 56, 7, 117, 110, 105, 48, 52, 68, 57, 7, 117, 110, 105, 48, 52, 68,
  65, 7, 117, 110, 105, 48, 52, 68, 66, 7, 117, 110, 105, 48, 52, 68, 67, 7,
  117, 110, 105, 48, 52, 68, 68, 7, 117, 110, 105, 48, 52, 68, 69, 7, 117, 110,
  105, 48, 52, 68, 70, 7, 117, 110, 105, 48, 52, 69, 48, 7, 117, 110, 105, 48,
  52, 69, 49, 7, 117, 110, 105, 48, 52, 69, 50, 7, 117, 110, 105, 48, 52, 69,
  51, 7, 117, 110, 105, 48, 52, 69, 52, 7, 117, 110, 105, 48, 52, 69, 53, 7,
  117, 110, 105, 48, 52, 69, 54, 7, 117, 110, 105, 48, 52, 69, 55, 7, 117, 110,
  105, 48, 52, 69, 56, 7, 117, 110, 105, 48, 52, 69, 57, 7, 117, 110, 105, 48,
  52, 69, 65, 7, 117, 110, 105, 48, 52, 69, 66, 7, 117, 110, 105, 48, 52, 69,
  67, 7, 117, 110, 105, 48, 52, 69, 68, 7, 117, 110, 105, 48, 52, 69, 69, 7,
  117, 110, 105, 48, 52, 69, 70, 7, 117, 110, 105, 48, 52, 70, 48, 7, 117, 110,
  105, 48, 52, 70, 49, 7, 117, 110, 105, 48, 52, 70, 50, 7, 117, 110, 105, 48,
  52, 70, 51, 7, 117, 110, 105, 48, 52, 70, 52, 7, 117, 110, 105, 48, 52, 70,
  53, 7, 117, 110, 105, 48, 52, 70, 54, 7, 117, 110, 105, 48, 52, 70, 55, 7,
  117, 110, 105, 48, 52, 70, 56, 7, 117, 110, 105, 48, 52, 70, 57, 7, 117, 110,
  105, 48, 52, 70, 65, 7, 117, 110, 105, 48, 52, 70, 66, 7, 117, 110, 105, 48,
  52, 70, 67, 7, 117, 110, 105, 48, 52, 70, 68, 7, 117, 110, 105, 48, 52, 70,
  69, 7, 117, 110, 105, 48, 52, 70, 70, 7, 117, 110, 105, 48, 53, 48, 48, 7,
  117, 110, 105, 48, 53, 48, 49, 7, 117, 110, 105, 48, 53, 48, 50, 7, 117, 110,
  105, 48, 53, 48, 51, 7, 117, 110, 105, 48, 53, 48, 52, 7, 117, 110, 105, 48,
  53, 48, 53, 7, 117, 110, 105, 48, 53, 48, 54, 7, 117, 110, 105, 48, 53, 48,
  55, 7, 117, 110, 105, 48, 53, 48, 56, 7, 117, 110, 105, 48, 53, 48, 57, 7,
  117, 110, 105, 48, 53, 48, 65, 7, 117, 110, 105, 48, 53, 48, 66, 7, 117, 110,
  105, 48, 53, 48, 67, 7, 117, 110, 105, 48, 53, 48, 68, 7, 117, 110, 105, 48,
  53, 48, 69, 7, 117, 110, 105, 48, 53, 48, 70, 7, 117, 110, 105, 48, 53, 49,
  48, 7, 117, 110, 105, 48, 53, 49, 49, 7, 117, 110, 105, 48, 53, 49, 50, 7,
  117, 110, 105, 48, 53, 49, 51, 7, 117, 110, 105, 49, 69, 65, 48, 7, 117, 110,
  105, 49, 69, 65, 49, 7, 117, 110, 105, 49, 69, 65, 50, 7, 117, 110, 105, 49,
  69, 65, 51, 7, 117, 110, 105, 49, 69, 65, 52, 7, 117, 110, 105, 49, 69, 65,
  53, 7, 117, 110, 105, 49, 69, 65, 54, 7, 117, 110, 105, 49, 69, 65, 55, 7,
  117, 110, 105, 49, 69, 65, 56, 7, 117, 110, 105, 49, 69, 65, 57, 7, 117, 110,
  105, 49, 69, 65, 65, 7, 117, 110, 105, 49, 69, 65, 66, 7, 117, 110, 105, 49,
  69, 65, 67, 7, 117, 110, 105, 49, 69, 65, 68, 7, 117, 110, 105, 49, 69, 65,
  69, 7, 117, 110, 105, 49, 69, 65, 70, 7, 117, 110, 105, 49, 69, 66, 48, 7,
  117, 110, 105, 49, 69, 66, 49, 7, 117, 110, 105, 49, 69, 66, 50, 7, 117, 110,
  105, 49, 69, 66, 51, 7, 117, 110, 105, 49, 69, 66, 52, 7, 117, 110, 105, 49,
  69, 66, 53, 7, 117, 110, 105, 49, 69, 66, 54, 7, 117, 110, 105, 49, 69, 66,
  55, 7, 117, 110, 105, 49, 69, 66, 56, 7, 117, 110, 105, 49, 69, 66, 57, 7,
  117, 110, 105, 49, 69, 66, 65, 7, 117, 110, 105, 49, 69, 66, 66, 7, 117, 110,
  105, 49, 69, 66, 67, 7, 117, 110, 105, 49, 69, 66, 68, 7, 117, 110, 105, 49,
  69, 66, 69, 7, 117, 110, 105, 49, 69, 66, 70, 7, 117, 110, 105, 49, 69, 67,
  48, 7, 117, 110, 105, 49, 69, 67, 49, 7, 117, 110, 105, 49, 69, 67, 50, 7,
  117, 110, 105, 49, 69, 67, 51, 7, 117, 110, 105, 49, 69, 67, 52, 7, 117, 110,
  105, 49, 69, 67, 53, 7, 117, 110, 105, 49, 69, 67, 54, 7, 117, 110, 105, 49,
  69, 67, 55, 7, 117, 110, 105, 49, 69, 67, 56, 7, 117, 110, 105, 49, 69, 67,
  57, 7, 117, 110, 105, 49, 69, 67, 65, 7, 117, 110, 105, 49, 69, 67, 66, 7,
  117, 110, 105, 49, 69, 67, 67, 7, 117, 110, 105, 49, 69, 67, 68, 7, 117, 110,
  105, 49, 69, 67, 69, 7, 117, 110, 105, 49, 69, 67, 70, 7, 117, 110, 105, 49,
  69, 68, 48, 7, 117, 110, 105, 49, 69, 68, 49, 7, 117, 110, 105, 49, 69, 68,
  50, 7, 117, 110, 105, 49, 69, 68, 51, 7, 117, 110, 105, 49, 69, 68, 52, 7,
  117, 110, 105, 49, 69, 68, 53, 7, 117, 110, 105, 49, 69, 68, 54, 7, 117, 110,
  105, 49, 69, 68, 55, 7, 117, 110, 105, 49, 69, 68, 56, 7, 117, 110, 105, 49,
  69, 68, 57, 7, 117, 110, 105, 49, 69, 68, 65, 7, 117, 110, 105, 49, 69, 68,
  66, 7, 117, 110, 105, 49, 69, 68, 67, 7, 117, 110, 105, 49, 69, 68, 68, 7,
  117, 110, 105, 49, 69, 68, 69, 7, 117, 110, 105, 49, 69, 68, 70, 7, 117, 110,
  105, 49, 69, 69, 48, 7, 117, 110, 105, 49, 69, 69, 49, 7, 117, 110, 105, 49,
  69, 69, 50, 7, 117, 110, 105, 49, 69, 69, 51, 7, 117, 110, 105, 49, 69, 69,
  52, 7, 117, 110, 105, 49, 69, 69, 53, 7, 117, 110, 105, 49, 69, 69, 54, 7,
  117, 110, 105, 49, 69, 69, 55, 7, 117, 110, 105, 49, 69, 69, 56, 7, 117, 110,
  105, 49, 69, 69, 57, 7, 117, 110, 105, 49, 69, 69, 65, 7, 117, 110, 105, 49,
  69, 69, 66, 7, 117, 110, 105, 49, 69, 69, 67, 7, 117, 110, 105, 49, 69, 69,
  68, 7, 117, 110, 105, 49, 69, 69, 69, 7, 117, 110, 105, 49, 69, 69, 70, 7,
  117, 110, 105, 49, 69, 70, 48, 7, 117, 110, 105, 49, 69, 70, 49, 7, 117, 110,
  105, 49, 69, 70, 52, 7, 117, 110, 105, 49, 69, 70, 53, 7, 117, 110, 105, 49,
  69, 70, 54, 7, 117, 110, 105, 49, 69, 70, 55, 7, 117, 110, 105, 49, 69, 70,
  56, 7, 117, 110, 105, 49, 69, 70, 57, 7, 117, 110, 105, 50, 48, 65, 66, 7,
  117, 110, 105, 48, 51, 48, 70, 19, 99, 105, 114, 99, 117, 109, 102, 108, 101,
  120, 97, 99, 117, 116, 101, 99, 111, 109, 98, 19, 99, 105, 114, 99, 117, 109,
  102, 108, 101, 120, 103, 114, 97, 118, 101, 99, 111, 109, 98, 18, 99, 105,
  114, 99, 117, 109, 102, 108, 101, 120, 104, 111, 111, 107, 99, 111, 109, 98,
  19, 99, 105, 114, 99, 117, 109, 102, 108, 101, 120, 116, 105, 108, 100, 101,
  99, 111, 109, 98, 14, 98, 114, 101, 118, 101, 97, 99, 117, 116, 101, 99, 111,
  109, 98, 14, 98, 114, 101, 118, 101, 103, 114, 97, 118, 101, 99, 111, 109, 98,
  13, 98, 114, 101, 118, 101, 104, 111, 111, 107, 99, 111, 109, 98, 14, 98, 114,
  101, 118, 101, 116, 105, 108, 100, 101, 99, 111, 109, 98, 16, 99, 121, 114,
  105, 108, 108, 105, 99, 104, 111, 111, 107, 108, 101, 102, 116, 17, 99, 121,
  114, 105, 108, 108, 105, 99, 98, 105, 103, 104, 111, 111, 107, 85, 67, 17, 99,
  121, 114, 105, 108, 108, 105, 99, 98, 105, 103, 104, 111, 111, 107, 76, 67, 0,
  0, 0, 0, 2, 0, 5, 0, 2, 255, 255, 0, 3,
};

#endif // #if defined(REDGPU_2_EXAMPLE_NUMBER_1)

#if defined(REDGPU_2_EXAMPLE_NUMBER_2)

// COMPILE(Constantine):
// cl /std:c++17 /DREDGPU_DISABLE_NAMED_PARAMETERS /DREDGPU_2_EXAMPLE_NUMBER_0 /DREDGPU_2_EXAMPLE_NUMBER_2 /DREDGPU_USE_REDGPU_X /DImTextureID=ImU64 /DImDrawIdx=unsigned /Iimgui/ /Iglfw-3.3.8.bin.WIN64/include/ /IC:/VulkanSDK/1.3.261.0/Include redgpu_2_examples.cpp imgui/imgui.cpp imgui/imgui_demo.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/backends/imgui_impl_glfw.cpp redgpu_2.cpp misc/redgpu_memory_allocator_vma/redgpu_memory_allocator.cpp misc/redgpu_memory_allocator_vma/redgpu_memory_allocator_functions.cpp misc/redgpu_green_struct/redgpu_green_struct.c C:/RedGpuSDK/redgpu_x.lib C:/RedGpuSDK/redgpu_x12.lib glfw-3.3.8.bin.WIN64/lib-vc2019/glfw3dll.lib

// DEFINE(Constantine): REDGPU_USE_REDGPU_X

// COMPILE(Constantine): C:/RedGpuSDK/misc/redgpu_memory_allocator_vma/redgpu_memory_allocator.cpp
// COMPILE(Constantine): C:/RedGpuSDK/misc/redgpu_memory_allocator_vma/redgpu_memory_allocator_functions.cpp
// COMPILE(Constantine): C:/RedGpuSDK/misc/redgpu_green_struct/redgpu_green_struct.c

// COPY(Constantine): C:/RedGpuSDK/redgpu.dll
// COPY(Constantine): C:/RedGpuSDK/redgpu_2.dll
// COPY(Constantine): glfw-3.3.8.bin.WIN64/lib-vc2019/glfw3.dll

// DEPENDENCY(Constantine): GLFW 3.3.8, glfw-3.3.8.bin.WIN64.zip, commit 7482de6071d21db77a7236155da44c172a7f6c9e

#ifdef REDGPU_USE_REDGPU_X
#pragma comment(lib, "C:/RedGpuSDK/redgpu_x.lib")
#else
#pragma comment(lib, "C:/RedGpuSDK/redgpudll.lib")
#endif
#pragma comment(lib, "glfw-3.3.8.bin.WIN64/lib-vc2019/glfw3dll.lib")

// Includes for main_helpers.cpp

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <vector>
#include <sstream>  // For std::ostringstream
#include <fstream>  // For std::ifstream, std::ofstream
#include <assert.h> // For assert

// Includes for main.cpp

#ifdef REDGPU_USE_REDGPU_X
#else
#define REDX_STRUCT_MEMBER_TYPE_ARRAY_RO RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW
#endif

#include "C:/RedGpuSDK/redgpu.h"
#include "C:/RedGpuSDK/redgpu_wsi.h"
#include "C:/RedGpuSDK/redgpu_2.h"
#include "C:/RedGpuSDK/misc/redgpu_green_struct/redgpu_green_struct.h"
#ifdef REDGPU_USE_REDGPU_X
#include "C:/RedGpuSDK/redgpu_x.h"
#endif

#define REDGPU_DISABLE_NAMED_PARAMETERS
#include "C:/RedGpuSDK/misc/np/np_redgpu.h"
#include "C:/RedGpuSDK/misc/np/np_redgpu_wsi.h"
#include "C:/RedGpuSDK/misc/np/np_redgpu_2.h"
#include "C:/RedGpuSDK/misc/np/misc/redgpu_green_struct/np_redgpu_green_struct.h"
#ifdef REDGPU_USE_REDGPU_X
#include "C:/RedGpuSDK/misc/np/np_redgpu_x.h"
#endif

#include "C:/RedGpuSDK/misc/redgpu_memory_allocator_vma/redgpu_memory_allocator.h"
#include "C:/RedGpuSDK/misc/redgpu_memory_allocator_vma/redgpu_memory_allocator_functions.h"
#include "C:/RedGpuSDK/misc/redgpu_green_struct/redgpu_green_struct.h"

#define GLFW_INCLUDE_NONE
#include "glfw-3.3.8.bin.WIN64/include/GLFW/glfw3.h"

// FILE(Constantine): main_helpers.cpp

#define expect(x) assert(x)
#define panicIf(x) assert(!(x))

static void * msvcMalloc(uint64_t bytesCount) {
  return malloc(bytesCount);
}

static void * msvcCalloc(uint64_t count, uint64_t bytesCount) {
  return calloc(count, bytesCount);
}

static void msvcFree(void * pointer) {
  free(pointer);
}

static uint64_t msvcStrlen(const char * s) {
  return strlen(s);
}

static const char * msvcStrdup(const char * s) {
  return _strdup(s);
}

static const char * stringReadFromFile(const char * filepath) {
  std::ostringstream ss;
  ss << std::ifstream(filepath).rdbuf();
  std::string s = ss.str();
  const char * schars = s.c_str();
  return msvcStrdup(schars);
}

static void stringWriteToFile(const char * s, const char * filepath) {
  std::ofstream fs(filepath, std::ofstream::out);
  fs << s;
  fs.close();
}

static void stringAppendToFile(const char * s, const char * filepath) {
  std::ofstream fs(filepath, std::ofstream::app);
  fs << s;
  fs.close();
}

static uint64_t binaryGetByteSizeOfFile(const char * filepath) {
  std::ifstream fs(filepath, std::ifstream::binary | std::ifstream::ate);
  uint64_t bytesCount = fs.tellg();
  fs.close();
  return bytesCount;
}

static void binaryReadFromFile(const char * filepath, void * outPointer) {
  std::ifstream fs(filepath, std::ifstream::binary);
  std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(fs), {});
  memcpy(outPointer, &buffer[0], buffer.size());
  fs.close();
}

static void binaryWriteToFile(uint64_t pointerBytesCount, void * pointer, const char * filepath) {
  std::ofstream fs(filepath, std::ofstream::binary | std::ofstream::out);
  fs.write((const char *)pointer, pointerBytesCount);
  fs.close();
}

static std::string runSystemCommand(const char * command) {
  std::string out;

  if (command == NULL) {
    return out;
  }

  std::string cmd = command;
  cmd += " 2>&1"; // NOTE(Constantine): Redirects stderr to stdout.

#ifdef _WIN32
  FILE * fd = _popen(cmd.c_str(), "r");
#else
  FILE * fd = popen(cmd.c_str(), "r");
#endif

  if (fd != NULL) {
    for (int c = fgetc(fd); c != EOF; c = fgetc(fd)) {
      out += c;
    }
#ifdef _WIN32
    _pclose(fd);
#else
    pclose(fd);
#endif
  }

  return out;
}

// FILE(Constantine): main.cpp

typedef struct RmaArray {
  VmaAllocator      allocator;
  RedArray          array;
  uint64_t          arrayBytesCount;
  VmaAllocation     memory;
  VmaAllocationInfo memoryInfo;
  RedArray          gpuOnlyArray;
  uint64_t          gpuOnlyArrayBytesCount;
  VmaAllocation     gpuOnlyMemory;
  VmaAllocationInfo gpuOnlyMemoryInfo;
} RmaArray;

RedStatus rmaCreateAllocatorSimple               (RedContext context, unsigned gpuIndex, VmaAllocator * outVmaAllocator);
RedStatus rmaCreateArraySimple                   (VmaAllocator allocator, uint64_t bytesCount, RedBool32 alsoAllocateGpuOnlyArray, RedArrayType arrayType, VmaMemoryUsage memoryUsage, RedBool32 memoryMapped, unsigned initialQueueFamilyIndex, RmaArray * outArray);
void      rmaDestroyArray                        (const RmaArray * array);
void      rmaCallCopyCpuToGpuArrayToGpuOnlyArray (const RedCallProceduresAndAddresses * callPAs, RedHandleCalls calls, RedContext context, RedHandleGpu gpu, const RmaArray * array, RedAccessStageBitflags gpuOnlyArray_oldAccessStages, RedAccessBitflags gpuOnlyArray_oldAccess, RedAccessStageBitflags gpuOnlyArray_newAccessStages, RedAccessBitflags gpuOnlyArray_newAccess);
void      rmaCallCopyGpuOnlyArrayToGpuToCpuArray (const RedCallProceduresAndAddresses * callPAs, RedHandleCalls calls, RedContext context, RedHandleGpu gpu, const RmaArray * array, RedAccessStageBitflags gpuOnlyArray_oldAccessStages, RedAccessBitflags gpuOnlyArray_oldAccess);

int main() {
  const char * add_cs = ""
#if 1
  "[[vk::binding(0, 0)]] RWStructuredBuffer<float4> array0: register(u0, space0); \n"
  "[[vk::binding(1, 0)]] RWStructuredBuffer<float4> array1: register(u0, space1); \n"
  "[[vk::binding(2, 0)]] RWStructuredBuffer<float4> array2: register(u0, space2); \n"
  "\n"
  "[numthreads(1, 1, 1)] \n"
  "void main(uint3 tid: SV_DispatchThreadId) { \n"
  "  array2[0] = array0[0] + array1[0]; \n"
  "} \n"
#else
  "[[vk::binding(0, 0)]] RWByteAddressBuffer array0: register(u0, space0); \n"
  "[[vk::binding(1, 0)]] RWByteAddressBuffer array1: register(u0, space1); \n"
  "[[vk::binding(2, 0)]] RWByteAddressBuffer array2: register(u0, space2); \n"
  "\n"
  "[numthreads(1, 1, 1)] \n"
  "void main(uint3 tid: SV_DispatchThreadId) { \n"
  "  array2.Store<float4>(0, array0.Load<float4>(0) + array1.Load<float4>(0)); \n"
  "} \n"
#endif
  ;
  stringWriteToFile(add_cs, "add.cs.hlsl");
  std::string add_cs_compileCommand = "C:/RedGpuSDK/dxc/dxc_2023_08_14/bin/x64/dxc.exe add.cs.hlsl -T cs_6_0 -Fo add.cs.ir";
#ifdef REDGPU_USE_REDGPU_X
#else
  add_cs_compileCommand += " -spirv";
#endif
  std::string add_cs_compileCommandOutput = runSystemCommand(add_cs_compileCommand.c_str());
  uint64_t add_cs_ir_bytesCount = binaryGetByteSizeOfFile("add.cs.ir");
  void * add_cs_ir = msvcCalloc(1, add_cs_ir_bytesCount);
  binaryReadFromFile("add.cs.ir", add_cs_ir);

  unsigned windowWidth  = 700;
  unsigned windowHeight = 700;

  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  GLFWwindow * window = glfwCreateWindow(windowWidth, windowHeight, "REDGPU 2 Compute Example", NULL, NULL);

  panicIf(window == NULL);

#ifdef _WIN32
  unsigned extensions[] = {
    RED_SDK_EXTENSION_DRIVER_PROPERTIES,
    RED_SDK_EXTENSION_RESOLVE_DEPTH_STENCIL,
    RED_SDK_EXTENSION_DEDICATE_MEMORY,
    RED_SDK_EXTENSION_PROCEDURE_PARAMETERS_HANDLES,
    RED_SDK_EXTENSION_BATCH_MEMORY_SET,
    RED_SDK_EXTENSION_RASTERIZATION_MODE,
    RED_SDK_EXTENSION_FORMAL_MEMORY_MODEL,
    RED_SDK_EXTENSION_WSI_WIN32
  };
#endif
  RedContext context = NULL;
  np_redCreateContext(
    _8b4eaa17_malloc(malloc),
    _8b4eaa17_free(free),
    _8b4eaa17_optionalMallocTagged(NULL),
    _8b4eaa17_optionalFreeTagged(NULL),
    _8b4eaa17_debugCallback(NULL),
    _8b4eaa17_sdkVersion(RED_SDK_VERSION_1_0_135),
    _8b4eaa17_sdkExtensionsCount(_countof(extensions)),
    _8b4eaa17_sdkExtensions(extensions),
    _8b4eaa17_optionalProgramName(NULL),
    _8b4eaa17_optionalProgramVersion(0),
    _8b4eaa17_optionalEngineName(NULL),
    _8b4eaa17_optionalEngineVersion(0),
    _8b4eaa17_optionalSettings(NULL),
    _8b4eaa17_outContext(&context),
    _8b4eaa17_outStatuses(NULL),
    _8b4eaa17_optionalFile(__FILE__),
    _8b4eaa17_optionalLine(__LINE__),
    _8b4eaa17_optionalUserData(NULL)
  );

  panicIf(context == NULL);
  panicIf(context->gpusCount == 0);

  unsigned           gpuIndex         =  0;
  RedHandleGpu       gpu              =  context->gpus[gpuIndex].gpu;
  const RedGpuInfo * gpuInfo          = &context->gpus[gpuIndex];
  RedHandleQueue     queue            =  context->gpus[gpuIndex].queues[0];
  unsigned           queueFamilyIndex =  context->gpus[gpuIndex].queuesFamilyIndex[0];

  RedCallProceduresAndAddresses callPAs = {};
  np_redGetCallProceduresAndAddresses(
    _038a00b5_context(context),
    _038a00b5_gpu(gpu),
    _038a00b5_outCallProceduresAndAddresses(&callPAs),
    _038a00b5_outStatuses(NULL),
    _038a00b5_optionalFile(__FILE__),
    _038a00b5_optionalLine(__LINE__),
    _038a00b5_optionalUserData(NULL)
  );

  struct float4 {
    float x, y, z, w;
  };

  VmaAllocator vma = 0;
  rmaCreateAllocatorSimple(
    /* RedContext     context */         context,
    /* unsigned       gpuIndex */        gpuIndex,
    /* VmaAllocator * outVmaAllocator */ &vma
  );

  RmaArray array0 = {};
  rmaCreateArraySimple(
    /* VmaAllocator   allocator */                vma,
    /* uint64_t       bytesCount */               sizeof(float4),
    /* RedBool32      alsoAllocateGpuOnlyArray */ 1,
    /* RedArrayType   arrayType */                RED_ARRAY_TYPE_ARRAY_RO,
    /* VmaMemoryUsage memoryUsage */              VMA_MEMORY_USAGE_CPU_TO_GPU,
    /* RedBool32      memoryMapped */             1,
    /* unsigned       initialQueueFamilyIndex */  -1,
    /* RmaArray *     outArray */                 &array0
  );

  RmaArray array1 = {};
  rmaCreateArraySimple(
    /* VmaAllocator   allocator */                vma,
    /* uint64_t       bytesCount */               sizeof(float4),
    /* RedBool32      alsoAllocateGpuOnlyArray */ 1,
    /* RedArrayType   arrayType */                RED_ARRAY_TYPE_ARRAY_RO,
    /* VmaMemoryUsage memoryUsage */              VMA_MEMORY_USAGE_CPU_TO_GPU,
    /* RedBool32      memoryMapped */             1,
    /* unsigned       initialQueueFamilyIndex */  -1,
    /* RmaArray *     outArray */                 &array1
  );

  RmaArray array2 = {};
  rmaCreateArraySimple(
    /* VmaAllocator   allocator */                vma,
    /* uint64_t       bytesCount */               sizeof(float4),
    /* RedBool32      alsoAllocateGpuOnlyArray */ 1,
    /* RedArrayType   arrayType */                RED_ARRAY_TYPE_ARRAY_RO,
    /* VmaMemoryUsage memoryUsage */              VMA_MEMORY_USAGE_GPU_TO_CPU,
    /* RedBool32      memoryMapped */             0,
    /* unsigned       initialQueueFamilyIndex */  -1,
    /* RmaArray *     outArray */                 &array2
  );

  volatile float4 * array0p = (volatile float4 *)array0.memoryInfo.pMappedData;
  volatile float4 * array1p = (volatile float4 *)array1.memoryInfo.pMappedData;

  array0p[0].x = 4;
  array0p[0].y = 8;
  array0p[0].z = 15;
  array0p[0].w = 16;

  array1p[0].x = 16;
  array1p[0].y = 23;
  array1p[0].z = 42;
  array1p[0].w = 108;

  RedStructDeclarationMember addStructDeclarationMembers[3] = {};
  addStructDeclarationMembers[0].slot            = 0;
  addStructDeclarationMembers[0].type            = RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW;
  addStructDeclarationMembers[0].count           = 1;
  addStructDeclarationMembers[0].visibleToStages = RED_VISIBLE_TO_STAGE_BITFLAG_COMPUTE;
  addStructDeclarationMembers[0].inlineSampler   = 0;
  addStructDeclarationMembers[1].slot            = 1;
  addStructDeclarationMembers[1].type            = RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW;
  addStructDeclarationMembers[1].count           = 1;
  addStructDeclarationMembers[1].visibleToStages = RED_VISIBLE_TO_STAGE_BITFLAG_COMPUTE;
  addStructDeclarationMembers[1].inlineSampler   = 0;
  addStructDeclarationMembers[2].slot            = 2;
  addStructDeclarationMembers[2].type            = RED_STRUCT_MEMBER_TYPE_ARRAY_RO_RW;
  addStructDeclarationMembers[2].count           = 1;
  addStructDeclarationMembers[2].visibleToStages = RED_VISIBLE_TO_STAGE_BITFLAG_COMPUTE;
  addStructDeclarationMembers[2].inlineSampler   = 0;
  GreenStructDeclaration addStructDeclaration = {};
  addStructDeclaration.structDeclarationMembersCount         = sizeof(addStructDeclarationMembers) / sizeof(addStructDeclarationMembers[0]);
  addStructDeclaration.structDeclarationMembers              = addStructDeclarationMembers;
  addStructDeclaration.structDeclarationMembersArrayROCount  = 0;
  addStructDeclaration.structDeclarationMembersArrayRO       = 0;
  addStructDeclaration.procedureParametersHandlesDeclaration = 0;
  addStructDeclaration.structDeclaration                     = 0;
  np_greenCreateStructDeclaration(
    _0a8a30e6_context(context),
    _0a8a30e6_gpu(gpu),
    _0a8a30e6_handleName("addStructDeclaration"),
    _0a8a30e6_outStructDeclaration(&addStructDeclaration),
    _0a8a30e6_outStatuses(0),
    _0a8a30e6_optionalFile(__FILE__),
    _0a8a30e6_optionalLine(__LINE__),
    _0a8a30e6_optionalUserData(0)
  );
  GreenStructHeap addStructHeap = {};
  np_greenStructHeapAllocate(
    _9ceb9cf5_context(context),
    _9ceb9cf5_gpu(gpu),
    _9ceb9cf5_handleName("addStructHeap"),
    _9ceb9cf5_structDeclarationsCount(1),
    _9ceb9cf5_structDeclarations(&addStructDeclaration),
    _9ceb9cf5_outStructHeap(&addStructHeap),
    _9ceb9cf5_outStatuses(0),
    _9ceb9cf5_optionalFile(__FILE__),
    _9ceb9cf5_optionalLine(__LINE__),
    _9ceb9cf5_optionalUserData(0)
  );

  RedProcedureParametersDeclaration addParametersDecl = {};
  addParametersDecl.variablesSlot            = 0;
  addParametersDecl.variablesVisibleToStages = 0;
  addParametersDecl.variablesBytesCount      = 0;
  addParametersDecl.structsDeclarationsCount = 1;
  addParametersDecl.structsDeclarations[0]   = addStructHeap.structsDeclaration[0];
  addParametersDecl.structsDeclarations[1]   = 0;
  addParametersDecl.structsDeclarations[2]   = 0;
  addParametersDecl.structsDeclarations[3]   = 0;
  addParametersDecl.structsDeclarations[4]   = 0;
  addParametersDecl.structsDeclarations[5]   = 0;
  addParametersDecl.structsDeclarations[6]   = 0;
  addParametersDecl.structsDeclarations[7]   = 0;
  addParametersDecl.handlesDeclaration       = 0;
  RedHandleProcedureParameters addParameters = 0;
  np_redCreateProcedureParameters(
    _7067ad8e_context(context),
    _7067ad8e_gpu(gpu),
    _7067ad8e_handleName("addParameters"),
    _7067ad8e_procedureParametersDeclaration(&addParametersDecl),
    _7067ad8e_outProcedureParameters(&addParameters),
    _7067ad8e_outStatuses(0),
    _7067ad8e_optionalFile(__FILE__),
    _7067ad8e_optionalLine(__LINE__),
    _7067ad8e_optionalUserData(0)
  );

  RedHandleGpuCode addGpuCode = 0;
  np_redCreateGpuCode(
    _01c06284_context(context),
    _01c06284_gpu(gpu),
    _01c06284_handleName("addGpuCode"),
    _01c06284_irBytesCount(add_cs_ir_bytesCount),
    _01c06284_ir(add_cs_ir),
    _01c06284_outGpuCode(&addGpuCode),
    _01c06284_outStatuses(0),
    _01c06284_optionalFile(__FILE__),
    _01c06284_optionalLine(__LINE__),
    _01c06284_optionalUserData(0)
  );
  msvcFree(add_cs_ir);
  add_cs_ir = 0;
  
  RedHandleProcedure addProcedure = 0;
  np_redCreateProcedureCompute(
    _bd6d24cf_context(context),
    _bd6d24cf_gpu(gpu),
    _bd6d24cf_handleName("addProcedure"),
    _bd6d24cf_procedureCache(0),
    _bd6d24cf_procedureParameters(addParameters),
    _bd6d24cf_gpuCodeMainProcedureName("main"),
    _bd6d24cf_gpuCode(addGpuCode),
    _bd6d24cf_outProcedure(&addProcedure),
    _bd6d24cf_outStatuses(0),
    _bd6d24cf_optionalFile(__FILE__),
    _bd6d24cf_optionalLine(__LINE__),
    _bd6d24cf_optionalUserData(0)
  );

  GreenStructHeapSet updates[3] = {};
  updates[0].structHeap                     = &addStructHeap;
  updates[0].structHeapResourceHandlesFirst = 0;
  updates[0].resourceHandlesCount           = 1;
  updates[0].resourceHandles                = (void **)&array0.gpuOnlyArray.handle;
  updates[1].structHeap                     = &addStructHeap;
  updates[1].structHeapResourceHandlesFirst = 1;
  updates[1].resourceHandlesCount           = 1;
  updates[1].resourceHandles                = (void **)&array1.gpuOnlyArray.handle;
  updates[2].structHeap                     = &addStructHeap;
  updates[2].structHeapResourceHandlesFirst = 2;
  updates[2].resourceHandlesCount           = 1;
  updates[2].resourceHandles                = (void **)&array2.gpuOnlyArray.handle;
  np_greenStructHeapsSet(
    _6a2e38c0_context(context),
    _6a2e38c0_gpu(gpu),
    _6a2e38c0_structHeapsSetsCount(sizeof(updates) / sizeof(updates[0])),
    _6a2e38c0_structHeapsSets(updates),
    _6a2e38c0_optionalFile(__FILE__),
    _6a2e38c0_optionalLine(__LINE__),
    _6a2e38c0_optionalUserData(0)
  );

  RedCalls calls = {};
  np_redCreateCallsReusable(
    _abac7e66_context(context),
    _abac7e66_gpu(gpu),
    _abac7e66_handleName("calls"),
    _abac7e66_queueFamilyIndex(queueFamilyIndex),
    _abac7e66_outCalls(&calls),
    _abac7e66_outStatuses(0),
    _abac7e66_optionalFile(__FILE__),
    _abac7e66_optionalLine(__LINE__),
    _abac7e66_optionalUserData(0)
  );
  np_redCallsSet(
    _23514538_context(context),
    _23514538_gpu(gpu),
    _23514538_calls(calls.handle),
    _23514538_callsMemory(calls.memory),
    _23514538_callsReusable(calls.reusable),
    _23514538_outStatuses(0),
    _23514538_optionalFile(__FILE__),
    _23514538_optionalLine(__LINE__),
    _23514538_optionalUserData(0)
  );
  rmaCallCopyCpuToGpuArrayToGpuOnlyArray(
    /* const RedCallProceduresAndAddresses * callPAs */       &callPAs,
    /* RedHandleCalls         calls */                        calls.handle,
    /* RedContext             context */                      context,
    /* RedHandleGpu           gpu */                          gpu,
    /* const RmaArray *       array */                        &array0,
    /* RedAccessStageBitflags gpuOnlyArray_oldAccessStages */ 0,
    /* RedAccessBitflags      gpuOnlyArray_oldAccess */       0,
    /* RedAccessStageBitflags gpuOnlyArray_newAccessStages */ RED_ACCESS_STAGE_BITFLAG_COMPUTE,
    /* RedAccessBitflags      gpuOnlyArray_newAccess */       RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R
  );
  rmaCallCopyCpuToGpuArrayToGpuOnlyArray(
    /* const RedCallProceduresAndAddresses * callPAs */       &callPAs,
    /* RedHandleCalls         calls */                        calls.handle,
    /* RedContext             context */                      context,
    /* RedHandleGpu           gpu */                          gpu,
    /* const RmaArray *       array */                        &array1,
    /* RedAccessStageBitflags gpuOnlyArray_oldAccessStages */ 0,
    /* RedAccessBitflags      gpuOnlyArray_oldAccess */       0,
    /* RedAccessStageBitflags gpuOnlyArray_newAccessStages */ RED_ACCESS_STAGE_BITFLAG_COMPUTE,
    /* RedAccessBitflags      gpuOnlyArray_newAccess */       RED_ACCESS_BITFLAG_STRUCT_RESOURCE_NON_FRAGMENT_STAGE_R
  );
  np_redCallSetStructsMemory(
    _e5f0da72_address(callPAs.redCallSetStructsMemory),
    _e5f0da72_calls(calls.handle),
    _e5f0da72_structsMemory(addStructHeap.memory),
    _e5f0da72_structsMemorySamplers(0)
  );
  np_redCallSetProcedureParameters(
    _a823169a_address(callPAs.redCallSetProcedureParameters),
    _a823169a_calls(calls.handle),
    _a823169a_procedureType(RED_PROCEDURE_TYPE_COMPUTE),
    _a823169a_procedureParameters(addParameters)
  );
  np_redCallSetProcedureParametersStructs(
    _b6fcba5e_address(callPAs.redCallSetProcedureParametersStructs),
    _b6fcba5e_calls(calls.handle),
    _b6fcba5e_procedureType(RED_PROCEDURE_TYPE_COMPUTE),
    _b6fcba5e_procedureParameters(addParameters),
    _b6fcba5e_procedureParametersDeclarationStructsDeclarationsFirst(0),
    _b6fcba5e_structsCount(1),
    _b6fcba5e_structs(addStructHeap.structs),
    _b6fcba5e_setTo0(0),
    _b6fcba5e_setTo00(0)
  );
  np_redCallSetProcedure(
    _16d79404_address(callPAs.redCallSetProcedure),
    _16d79404_calls(calls.handle),
    _16d79404_procedureType(RED_PROCEDURE_TYPE_COMPUTE),
    _16d79404_procedure(addProcedure)
  );
  np_redCallProcedureCompute(
    _17fa22b3_address(callPAs.redCallProcedureCompute),
    _17fa22b3_calls(calls.handle),
    _17fa22b3_workgroupsCountX(1),
    _17fa22b3_workgroupsCountY(1),
    _17fa22b3_workgroupsCountZ(1)
  );
  rmaCallCopyGpuOnlyArrayToGpuToCpuArray(
    /* const RedCallProceduresAndAddresses * callPAs */       &callPAs,
    /* RedHandleCalls         calls */                        calls.handle,
    /* RedContext             context */                      context,
    /* RedHandleGpu           gpu */                          gpu,
    /* const RmaArray *       array */                        &array2,
    /* RedAccessStageBitflags gpuOnlyArray_oldAccessStages */ RED_ACCESS_STAGE_BITFLAG_COMPUTE,
    /* RedAccessBitflags      gpuOnlyArray_oldAccess */       RED_ACCESS_BITFLAG_STRUCT_RESOURCE_W
  );
  np_redCallsEnd(
    _2566f99f_context(context),
    _2566f99f_gpu(gpu),
    _2566f99f_calls(calls.handle),
    _2566f99f_callsMemory(calls.memory),
    _2566f99f_outStatuses(0),
    _2566f99f_optionalFile(__FILE__),
    _2566f99f_optionalLine(__LINE__),
    _2566f99f_optionalUserData(0)
  );

  RedHandleCpuSignal cpuSignal = 0;
  np_redCreateCpuSignal(
    _9dcf3e68_context(context),
    _9dcf3e68_gpu(gpu),
    _9dcf3e68_handleName("cpuSignal"),
    _9dcf3e68_createSignaled(0),
    _9dcf3e68_outCpuSignal(&cpuSignal),
    _9dcf3e68_outStatuses(0),
    _9dcf3e68_optionalFile(__FILE__),
    _9dcf3e68_optionalLine(__LINE__),
    _9dcf3e68_optionalUserData(0)
  );
  RedGpuTimeline timeline = {};
  timeline.setTo4                            = 4;
  timeline.setTo0                            = 0;
  timeline.waitForAndUnsignalGpuSignalsCount = 0;
  timeline.waitForAndUnsignalGpuSignals      = 0;
  timeline.setTo65536                        = 0;
  timeline.callsCount                        = 1;
  timeline.calls                             = &calls.handle;
  timeline.signalGpuSignalsCount             = 0;
  timeline.signalGpuSignals                  = 0;
  np_redQueueSubmit(
    _dcc70647_context(context),
    _dcc70647_gpu(gpu),
    _dcc70647_queue(queue),
    _dcc70647_timelinesCount(1),
    _dcc70647_timelines(&timeline),
    _dcc70647_signalCpuSignal(cpuSignal),
    _dcc70647_outStatuses(0),
    _dcc70647_optionalFile(__FILE__),
    _dcc70647_optionalLine(__LINE__),
    _dcc70647_optionalUserData(0)
  );
  np_redCpuSignalWait(
    _4a826452_context(context),
    _4a826452_gpu(gpu),
    _4a826452_cpuSignalsCount(1),
    _4a826452_cpuSignals(&cpuSignal),
    _4a826452_waitAll(1),
    _4a826452_outStatuses(0),
    _4a826452_optionalFile(__FILE__),
    _4a826452_optionalLine(__LINE__),
    _4a826452_optionalUserData(0)
  );
  np_redCpuSignalUnsignal(
    _fd52e10b_context(context),
    _fd52e10b_gpu(gpu),
    _fd52e10b_cpuSignalsCount(1),
    _fd52e10b_cpuSignals(&cpuSignal),
    _fd52e10b_outStatuses(0),
    _fd52e10b_optionalFile(__FILE__),
    _fd52e10b_optionalLine(__LINE__),
    _fd52e10b_optionalUserData(0)
  );

  volatile float4 * array2p = 0;
  vmaMapMemory(vma, array2.memory, (void **)&array2p);
  // NOTE(Constantine): "array2p: 20.000000 31.000000 57.000000 124.000000"
  printf("array2p: %f %f %f %f\n", array2p[0].x, array2p[0].y, array2p[0].z, array2p[0].w);
  vmaUnmapMemory(vma, array2.memory);

  while (glfwWindowShouldClose(window) == 0) {
    glfwPollEvents();
  }

  redDestroyCpuSignal(context, gpu, cpuSignal, __FILE__, __LINE__, 0);
  redDestroyCalls(context, gpu, calls.handle, calls.memory, __FILE__, __LINE__, 0);
  redDestroyProcedure(context, gpu, addProcedure, __FILE__, __LINE__, 0);
  redDestroyGpuCode(context, gpu, addGpuCode, __FILE__, __LINE__, 0);
  redDestroyProcedureParameters(context, gpu, addParameters, __FILE__, __LINE__, 0);
  greenStructHeapFree(context, gpu, &addStructHeap, __FILE__, __LINE__, 0);
  redDestroyStructDeclaration(context, gpu, addStructDeclaration.structDeclaration, __FILE__, __LINE__, 0);
  rmaDestroyArray(&array0);
  rmaDestroyArray(&array1);
  rmaDestroyArray(&array2);
  vmaDestroyAllocator(vma);

  redDestroyContext(context, __FILE__, __LINE__, NULL);

  return 0;
}

unsigned redHelperGetMemoryTypeIndex(const RedGpuInfo * gpuInfo, RedHelperMemoryType memoryType, unsigned memoryTypesSupported) {
  const unsigned        memoryTypesCount = gpuInfo->memoryTypesCount;
  const RedMemoryType * memoryTypes      = gpuInfo->memoryTypes;

  unsigned memoryTypeIsSupported[32];
  memoryTypeIsSupported[0]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0001)) == 0 ? 0 : 1;
  memoryTypeIsSupported[1]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0010)) == 0 ? 0 : 1;
  memoryTypeIsSupported[2]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,0100)) == 0 ? 0 : 1;
  memoryTypeIsSupported[3]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0000,1000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[4]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0001,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[5]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0010,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[6]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,0100,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[7]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0000,1000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[8]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0001,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[9]  = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0010,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[10] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,0100,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[11] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0000,1000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[12] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0001,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[13] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0010,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[14] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,0100,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[15] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0000,1000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[16] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0001,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[17] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0010,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[18] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,0100,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[19] = (memoryTypesSupported & REDGPU_B32(0000,0000,0000,1000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[20] = (memoryTypesSupported & REDGPU_B32(0000,0000,0001,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[21] = (memoryTypesSupported & REDGPU_B32(0000,0000,0010,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[22] = (memoryTypesSupported & REDGPU_B32(0000,0000,0100,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[23] = (memoryTypesSupported & REDGPU_B32(0000,0000,1000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[24] = (memoryTypesSupported & REDGPU_B32(0000,0001,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[25] = (memoryTypesSupported & REDGPU_B32(0000,0010,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[26] = (memoryTypesSupported & REDGPU_B32(0000,0100,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[27] = (memoryTypesSupported & REDGPU_B32(0000,1000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[28] = (memoryTypesSupported & REDGPU_B32(0001,0000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[29] = (memoryTypesSupported & REDGPU_B32(0010,0000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[30] = (memoryTypesSupported & REDGPU_B32(0100,0000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;
  memoryTypeIsSupported[31] = (memoryTypesSupported & REDGPU_B32(1000,0000,0000,0000,0000,0000,0000,0000)) == 0 ? 0 : 1;

  if (memoryType == RED_HELPER_MEMORY_TYPE_VRAM) {
    for (unsigned i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isGpuVram == 1 && memoryTypeIsSupported[i] == 1) {
        return i;
      }
    }
  } else if (memoryType == RED_HELPER_MEMORY_TYPE_UPLOAD) {
    for (unsigned i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isCpuMappable == 1 &&
          type->isCpuCoherent == 1 &&
          type->isCpuCached   == 0 && memoryTypeIsSupported[i] == 1)
      {
        return i;
      }
    }
    for (unsigned i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isCpuMappable == 1 &&
          type->isCpuCoherent == 1 && memoryTypeIsSupported[i] == 1)
      {
        return i;
      }
    }
  } else if (memoryType == RED_HELPER_MEMORY_TYPE_READBACK) {
    for (unsigned i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isCpuMappable == 1 &&
          type->isCpuCoherent == 1 &&
          type->isCpuCached   == 1 && memoryTypeIsSupported[i] == 1)
      {
        return i;
      }
    }
    for (unsigned i = 0; i < memoryTypesCount; i += 1) {
      const RedMemoryType * type = &memoryTypes[i];
      if (type->isCpuMappable == 1 &&
          type->isCpuCoherent == 1 && memoryTypeIsSupported[i] == 1)
      {
        return i;
      }
    }
  }

  return -1;
}

void redHelperImageSetStateUsable(RedContext context, RedHandleGpu gpu, uint64_t imagesCount, const RedHandleImage * images, const RedImagePartBitflags * imagesAllParts, unsigned queueFamilyIndexToSubmitImageStateChange, RedCalls * outCalls, RedStatuses * outStatuses, char * optionalFile, int optionalLine, void * optionalUserData) {
#ifdef REDGPU_USE_REDGPU_X
  redCreateCalls(
    context,
    gpu,
    NULL,
    queueFamilyIndexToSubmitImageStateChange,
    outCalls,
    outStatuses,
    optionalFile,
    optionalLine,
    optionalUserData
  );

  redCallsSet(
    context,
    gpu,
    outCalls[0].handle,
    outCalls[0].memory,
    outCalls[0].reusable,
    outStatuses,
    optionalFile,
    optionalLine,
    optionalUserData
  );

  redCallsEnd(
    context,
    gpu,
    outCalls[0].handle,
    outCalls[0].memory,
    outStatuses,
    optionalFile,
    optionalLine,
    optionalUserData
  );
#else
  RedUsageImage * imageUsages = new(std::nothrow) RedUsageImage[imagesCount];
  if (imageUsages == NULL) {
    if (outStatuses != NULL) {
      if (outStatuses->statusError == RED_STATUS_SUCCESS) {
        outStatuses->statusError               = RED_STATUS_ERROR_OUT_OF_CPU_MEMORY;
        outStatuses->statusErrorCode           = 0;
        outStatuses->statusErrorHresult        = 0;
        outStatuses->statusErrorProcedureId    = RED_PROCEDURE_ID_UNDEFINED;
        outStatuses->statusErrorFile           = optionalFile;
        outStatuses->statusErrorLine           = optionalLine;
        outStatuses->statusErrorDescription[0] = 0;
      }
    }
    return;
  }

  RedCallProceduresAndAddresses callProceduresAndAddresses = {};
  redGetCallProceduresAndAddresses(
    context,
    gpu,
    &callProceduresAndAddresses,
    outStatuses,
    optionalFile,
    optionalLine,
    optionalUserData
  );

  redCreateCalls(
    context,
    gpu,
    NULL,
    queueFamilyIndexToSubmitImageStateChange,
    outCalls,
    outStatuses,
    optionalFile,
    optionalLine,
    optionalUserData
  );

  redCallsSet(
    context,
    gpu,
    outCalls[0].handle,
    outCalls[0].memory,
    outCalls[0].reusable,
    outStatuses,
    optionalFile,
    optionalLine,
    optionalUserData
  );

  for (uint64_t i = 0; i < imagesCount; i += 1) {
    imageUsages[i].barrierSplit           = RED_BARRIER_SPLIT_NONE;
    imageUsages[i].oldAccessStages        = 0;
    imageUsages[i].newAccessStages        = 0;
    imageUsages[i].oldAccess              = 0;
    imageUsages[i].newAccess              = 0;
    imageUsages[i].oldState               = RED_STATE_UNUSABLE;
    imageUsages[i].newState               = RED_STATE_USABLE;
    imageUsages[i].queueFamilyIndexSource = -1;
    imageUsages[i].queueFamilyIndexTarget = -1;
    imageUsages[i].image                  = images[i];
    imageUsages[i].imageAllParts          = imagesAllParts[i];
    imageUsages[i].imageLevelsFirst       = 0;
    imageUsages[i].imageLevelsCount       = -1;
    imageUsages[i].imageLayersFirst       = 0;
    imageUsages[i].imageLayersCount       = -1;
  }
  redCallUsageAliasOrderBarrier(
    callProceduresAndAddresses.redCallUsageAliasOrderBarrier,
    outCalls[0].handle,
    context,
    0,
    NULL,
    imagesCount,
    imageUsages,
    0,
    NULL,
    0,
    NULL,
    0
  );
  delete[] imageUsages;

  redCallsEnd(
    context,
    gpu,
    outCalls[0].handle,
    outCalls[0].memory,
    outStatuses,
    optionalFile,
    optionalLine,
    optionalUserData
  );
#endif
}

RedStatus rmaCreateAllocatorSimple(RedContext context, unsigned gpuIndex, VmaAllocator * outVmaAllocator) {
  VmaRedGpuFunctions rmaProcedures = {};
  rmaProcedures.redgpuVkGetPhysicalDeviceProperties       = rmaVmaVkGetPhysicalDeviceProperties;
  rmaProcedures.redgpuVkGetPhysicalDeviceMemoryProperties = rmaVmaVkGetPhysicalDeviceMemoryProperties;
  rmaProcedures.redgpuVkAllocateMemory                    = rmaVmaVkAllocateMemory;
  rmaProcedures.redgpuVkFreeMemory                        = rmaVmaVkFreeMemory;
  rmaProcedures.redgpuVkMapMemory                         = rmaVmaVkMapMemory;
  rmaProcedures.redgpuVkUnmapMemory                       = rmaVmaVkUnmapMemory;
  rmaProcedures.redgpuVkFlushMappedMemoryRanges           = rmaVmaVkFlushMappedMemoryRanges;
  rmaProcedures.redgpuVkInvalidateMappedMemoryRanges      = rmaVmaVkInvalidateMappedMemoryRanges;
  rmaProcedures.redgpuVkBindBufferMemory                  = rmaVmaVkBindBufferMemory;
  rmaProcedures.redgpuVkBindImageMemory                   = rmaVmaVkBindImageMemory;
  rmaProcedures.redgpuVkGetBufferMemoryRequirements       = rmaVmaVkGetBufferMemoryRequirements;
  rmaProcedures.redgpuVkGetImageMemoryRequirements        = rmaVmaVkGetImageMemoryRequirements;
  rmaProcedures.redgpuVkCreateBuffer                      = rmaVmaVkCreateBuffer;
  rmaProcedures.redgpuVkDestroyBuffer                     = rmaVmaVkDestroyBuffer;
  rmaProcedures.redgpuVkCreateImage                       = rmaVmaVkCreateImage;
  rmaProcedures.redgpuVkDestroyImage                      = rmaVmaVkDestroyImage;
  rmaProcedures.redgpuVkCmdCopyBuffer                     = rmaVmaVkCmdCopyBuffer;
  VmaAllocatorCreateInfo vmaAllocatorInfo = {};
  vmaAllocatorInfo.flags                       = 0;
  vmaAllocatorInfo.physicalDevice              = context->gpus[gpuIndex].gpuDevice;
  vmaAllocatorInfo.device                      = context->gpus[gpuIndex].gpu;
  vmaAllocatorInfo.preferredLargeHeapBlockSize = 0;
  vmaAllocatorInfo.pAllocationCallbacks        = 0;
  vmaAllocatorInfo.pDeviceMemoryCallbacks      = 0;
  vmaAllocatorInfo.frameInUseCount             = 0;
  vmaAllocatorInfo.pHeapSizeLimit              = 0;
  vmaAllocatorInfo.pRedGpuFunctions            = &rmaProcedures;
  vmaAllocatorInfo.pRecordSettings             = 0;
  vmaAllocatorInfo.instance                    = context->handle;
  vmaAllocatorInfo.vulkanApiVersion            = 0;
  vmaAllocatorInfo.redgpuContext               = context;
  vmaAllocatorInfo.redgpuContextGpuIndex       = gpuIndex;
  return vmaCreateAllocator(&vmaAllocatorInfo, outVmaAllocator);
}

RedStatus rmaCreateArraySimple(VmaAllocator allocator, uint64_t bytesCount, RedBool32 alsoAllocateGpuOnlyArray, RedArrayType arrayType, VmaMemoryUsage memoryUsage, RedBool32 memoryMapped, unsigned initialQueueFamilyIndex, RmaArray * outArray) {
  outArray[0] = {};
  outArray->allocator              = allocator;
  outArray->arrayBytesCount        = bytesCount;
  outArray->gpuOnlyArrayBytesCount = bytesCount;
  VmaBufferCreateInfo arrayCreateInfo = {};
  arrayCreateInfo.setTo12               = 12;
  arrayCreateInfo.setTo0                = 0;
  arrayCreateInfo.setTo00               = 0;
  arrayCreateInfo.size                  = bytesCount;
  arrayCreateInfo.type                  = RED_ARRAY_TYPE_ARRAY_RW;
  arrayCreateInfo.sharingMode           = initialQueueFamilyIndex == -1 ? VMA_SHARING_MODE_CONCURRENT : VMA_SHARING_MODE_EXCLUSIVE;
  arrayCreateInfo.queueFamilyIndexCount = initialQueueFamilyIndex == -1 ? 0 : 1;
  arrayCreateInfo.pQueueFamilyIndices   = &initialQueueFamilyIndex;
  VmaAllocationCreateInfo arrayVmaInfo = {};
  arrayVmaInfo.flags          = 0;
  arrayVmaInfo.usage          = VMA_MEMORY_USAGE_GPU_ONLY;
  arrayVmaInfo.requiredFlags  = 0;
  arrayVmaInfo.preferredFlags = 0;
  arrayVmaInfo.memoryTypeBits = 0;
  arrayVmaInfo.pool           = 0;
  arrayVmaInfo.pUserData      = 0;
  arrayVmaInfo.priority       = 0;
  if (alsoAllocateGpuOnlyArray == 1) {
    RedStatus status = vmaCreateBuffer(allocator, &arrayCreateInfo, &arrayVmaInfo, &outArray->gpuOnlyArray, &outArray->gpuOnlyMemory, &outArray->gpuOnlyMemoryInfo);
    if (status != RED_STATUS_SUCCESS) {
      return status;
    }
  }
  arrayCreateInfo.type = arrayType;
  arrayVmaInfo.flags   = memoryMapped == 1 ? VMA_ALLOCATION_CREATE_MAPPED_BIT : 0;
  arrayVmaInfo.usage   = memoryUsage;
  return vmaCreateBuffer(allocator, &arrayCreateInfo, &arrayVmaInfo, &outArray->array, &outArray->memory, &outArray->memoryInfo);
}

void rmaDestroyArray(const RmaArray * array) {
  vmaDestroyBuffer(array->allocator, array->array.handle, array->memory);
  if (array->gpuOnlyArray.handle != 0) {
    vmaDestroyBuffer(array->allocator, array->gpuOnlyArray.handle, array->gpuOnlyMemory);
  }
}

void rmaCallCopyCpuToGpuArrayToGpuOnlyArray(const RedCallProceduresAndAddresses * callPAs, RedHandleCalls calls, RedContext context, RedHandleGpu gpu, const RmaArray * array, RedAccessStageBitflags gpuOnlyArray_oldAccessStages, RedAccessBitflags gpuOnlyArray_oldAccess, RedAccessStageBitflags gpuOnlyArray_newAccessStages, RedAccessBitflags gpuOnlyArray_newAccess) {
  {
    RedUsageArray arrayUsages[2] = {};

    arrayUsages[0].barrierSplit           = RED_BARRIER_SPLIT_NONE;
    arrayUsages[0].oldAccessStages        = 0;
    arrayUsages[0].newAccessStages        = RED_ACCESS_STAGE_BITFLAG_COPY;
    arrayUsages[0].oldAccess              = 0;
    arrayUsages[0].newAccess              = RED_ACCESS_BITFLAG_COPY_R;
    arrayUsages[0].queueFamilyIndexSource =-1;
    arrayUsages[0].queueFamilyIndexTarget =-1;
    arrayUsages[0].array                  = array->array.handle;
    arrayUsages[0].arrayBytesFirst        = 0;
    arrayUsages[0].arrayBytesCount        =-1;

    arrayUsages[1].barrierSplit           = RED_BARRIER_SPLIT_NONE;
    arrayUsages[1].oldAccessStages        = gpuOnlyArray_oldAccessStages;
    arrayUsages[1].newAccessStages        = RED_ACCESS_STAGE_BITFLAG_COPY;
    arrayUsages[1].oldAccess              = gpuOnlyArray_oldAccess;
    arrayUsages[1].newAccess              = RED_ACCESS_BITFLAG_COPY_W;
    arrayUsages[1].queueFamilyIndexSource =-1;
    arrayUsages[1].queueFamilyIndexTarget =-1;
    arrayUsages[1].array                  = array->gpuOnlyArray.handle;
    arrayUsages[1].arrayBytesFirst        = 0;
    arrayUsages[1].arrayBytesCount        =-1;

    red2CallUsageAliasOrderBarrier(callPAs->redCallUsageAliasOrderBarrier, calls, context, gpu, 2, arrayUsages, 0, 0, 0, 0, 0, 0, 0);
  }

  {
    RedCopyArrayRange range = {};
    range.arrayRBytesFirst = 0;
    range.arrayWBytesFirst = 0;
    range.bytesCount       = array->gpuOnlyArrayBytesCount;
    callPAs->redCallCopyArrayToArray(calls, array->array.handle, array->gpuOnlyArray.handle, 1, &range);
  }

  {
    RedUsageArray arrayUsages[1] = {};

    arrayUsages[0].barrierSplit           = RED_BARRIER_SPLIT_NONE;
    arrayUsages[0].oldAccessStages        = RED_ACCESS_STAGE_BITFLAG_COPY;
    arrayUsages[0].newAccessStages        = gpuOnlyArray_newAccessStages;
    arrayUsages[0].oldAccess              = RED_ACCESS_BITFLAG_COPY_W;
    arrayUsages[0].newAccess              = gpuOnlyArray_newAccess;
    arrayUsages[0].queueFamilyIndexSource =-1;
    arrayUsages[0].queueFamilyIndexTarget =-1;
    arrayUsages[0].array                  = array->gpuOnlyArray.handle;
    arrayUsages[0].arrayBytesFirst        = 0;
    arrayUsages[0].arrayBytesCount        =-1;

    red2CallUsageAliasOrderBarrier(callPAs->redCallUsageAliasOrderBarrier, calls, context, gpu, 1, arrayUsages, 0, 0, 0, 0, 0, 0, 0);
  }
}

void rmaCallCopyGpuOnlyArrayToGpuToCpuArray(const RedCallProceduresAndAddresses * callPAs, RedHandleCalls calls, RedContext context, RedHandleGpu gpu, const RmaArray * array, RedAccessStageBitflags gpuOnlyArray_oldAccessStages, RedAccessBitflags gpuOnlyArray_oldAccess) {
  {
    RedUsageArray arrayUsages[2] = {};

    arrayUsages[0].barrierSplit           = RED_BARRIER_SPLIT_NONE;
    arrayUsages[0].oldAccessStages        = gpuOnlyArray_oldAccessStages;
    arrayUsages[0].newAccessStages        = RED_ACCESS_STAGE_BITFLAG_COPY;
    arrayUsages[0].oldAccess              = gpuOnlyArray_oldAccess;
    arrayUsages[0].newAccess              = RED_ACCESS_BITFLAG_COPY_R;
    arrayUsages[0].queueFamilyIndexSource =-1;
    arrayUsages[0].queueFamilyIndexTarget =-1;
    arrayUsages[0].array                  = array->gpuOnlyArray.handle;
    arrayUsages[0].arrayBytesFirst        = 0;
    arrayUsages[0].arrayBytesCount        =-1;

    arrayUsages[1].barrierSplit           = RED_BARRIER_SPLIT_NONE;
    arrayUsages[1].oldAccessStages        = 0;
    arrayUsages[1].newAccessStages        = RED_ACCESS_STAGE_BITFLAG_COPY;
    arrayUsages[1].oldAccess              = 0;
    arrayUsages[1].newAccess              = RED_ACCESS_BITFLAG_COPY_W;
    arrayUsages[1].queueFamilyIndexSource =-1;
    arrayUsages[1].queueFamilyIndexTarget =-1;
    arrayUsages[1].array                  = array->array.handle;
    arrayUsages[1].arrayBytesFirst        = 0;
    arrayUsages[1].arrayBytesCount        =-1;

    red2CallUsageAliasOrderBarrier(callPAs->redCallUsageAliasOrderBarrier, calls, context, gpu, 2, arrayUsages, 0, 0, 0, 0, 0, 0, 0);
  }

  {
    RedCopyArrayRange range = {};
    range.arrayRBytesFirst = 0;
    range.arrayWBytesFirst = 0;
    range.bytesCount       = array->gpuOnlyArrayBytesCount;
    callPAs->redCallCopyArrayToArray(calls, array->gpuOnlyArray.handle, array->array.handle, 1, &range);
  }

  {
    RedUsageArray arrayUsages[1] = {};

    arrayUsages[0].barrierSplit           = RED_BARRIER_SPLIT_NONE;
    arrayUsages[0].oldAccessStages        = RED_ACCESS_STAGE_BITFLAG_COPY;
    arrayUsages[0].newAccessStages        = RED_ACCESS_STAGE_BITFLAG_CPU;
    arrayUsages[0].oldAccess              = RED_ACCESS_BITFLAG_COPY_W;
    arrayUsages[0].newAccess              = RED_ACCESS_BITFLAG_CPU_RW;
    arrayUsages[0].queueFamilyIndexSource =-1;
    arrayUsages[0].queueFamilyIndexTarget =-1;
    arrayUsages[0].array                  = array->array.handle;
    arrayUsages[0].arrayBytesFirst        = 0;
    arrayUsages[0].arrayBytesCount        =-1;

    red2CallUsageAliasOrderBarrier(callPAs->redCallUsageAliasOrderBarrier, calls, context, gpu, 1, arrayUsages, 0, 0, 0, 0, 0, 0, 0);
  }
}

#endif // #if defined(REDGPU_2_EXAMPLE_NUMBER_2)
