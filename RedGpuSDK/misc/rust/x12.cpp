// Copyright(C) 2019-2024 Constantine Tarasenkov (iamvfx@gmail.com). All rights reserved.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "x12_d3d12.h"

#ifndef __GNUC__
#if _MSC_VER < 1700
#error 'Properties -> Configuration Properties -> General -> Platform Toolset' must be set to 'Visual Studio 2012 (v110)' or higher for std::mutex to work.
#endif
#endif

#include <new>
#include <iostream>
#if _MSC_VER >= 1700
#include <mutex>
#endif

#pragma comment(lib, "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64/d3d12.lib")
#pragma comment(lib, "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64/dxgi.lib")
#pragma comment(lib, "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64/dxguid.lib") // For DXGI_DEBUG_ALL

#if _MSC_VER >= 1700
std::mutex __X12_GLOBAL_a4c11ca6027df88068009fd7140d875add16c292_debugNon0HresultPrintingMutex;
#endif

static void x12InternalPrint(const char * format, ...) {
  va_list arguments;
  va_start(arguments, format);
  int length = _vscprintf(format, arguments) + 1;
  char * buffer = new(std::nothrow) char[length]();
  if (buffer != NULL) {
    vsprintf_s(buffer, length, format, arguments);
    OutputDebugStringA(buffer);
    delete[] buffer;
    buffer = NULL;
  } else {
    OutputDebugStringA("[X12] Failed to allocate print buffer.\n");
  }
  va_end(arguments);
}

__forceinline HRESULT x12CheckHresultEx(HRESULT hresult, const char * call, const char * optionalFile, int optionalLine) {
  if (1) {
    if (hresult != 0) {
#if _MSC_VER >= 1700
      std::lock_guard<std::mutex> __debugNon0HresultPrintingMutexScope(__X12_GLOBAL_a4c11ca6027df88068009fd7140d875add16c292_debugNon0HresultPrintingMutex);
#endif
      if (optionalFile != NULL) {
        x12InternalPrint("[X12][%s:%d] \"%s\" returned HRESULT %d\n", optionalFile, optionalLine, call, hresult);
        std::cout << "[X12][" << optionalFile << ":" << optionalLine << "] \"" << call << "\" returned HRESULT " << hresult << std::endl;
      } else {
        x12InternalPrint("[X12] \"%s\" returned HRESULT %d\n", call, hresult);
        std::cout << "[X12] \"" << call << "\" returned HRESULT " << hresult << std::endl;
      }
    }
  }
  return hresult;
}

#define x12CheckHresult(CALL) x12CheckHresultEx(CALL, #CALL, optionalFile, optionalLine)

// D3D12

HRESULT x12ObjectSetName(ID3D12Object * handle, _In_z_ LPCWSTR Name, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetName(Name));
}

HRESULT x12ResourceMap(ID3D12Resource * handle, UINT Subresource, _In_opt_ const D3D12_RANGE * pReadRange, _Outptr_opt_result_bytebuffer_(_Inexpressible_("Dependent on resource")) void ** ppData, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->Map(Subresource, pReadRange, ppData));
}

void x12ResourceUnmap(ID3D12Resource * handle, UINT Subresource, _In_opt_ const D3D12_RANGE * pWrittenRange, const char * optionalFile, int optionalLine) {
  handle->Unmap(Subresource, pWrittenRange);
}

D3D12_GPU_VIRTUAL_ADDRESS x12ResourceGetGPUVirtualAddress(ID3D12Resource * handle) {
  return handle->GetGPUVirtualAddress();
}

HRESULT x12CommandAllocatorReset(ID3D12CommandAllocator * handle, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->Reset());
}

UINT64 x12FenceGetCompletedValue(ID3D12Fence * handle, const char * optionalFile, int optionalLine) {
  return handle->GetCompletedValue();
}

HRESULT x12FenceSetEventOnCompletion(ID3D12Fence * handle, UINT64 Value, HANDLE hEvent, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetEventOnCompletion(Value, hEvent));
}

HRESULT x12FenceSignal(ID3D12Fence * handle, UINT64 Value, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->Signal(Value));
}

LPVOID x12BlobGetBufferPointer(ID3D10Blob * handle) {
  return handle->GetBufferPointer();
}

SIZE_T x12BlobGetBufferSize(ID3D10Blob * handle) {
  return handle->GetBufferSize();
}

HRESULT x12PipelineStateGetCachedBlob(ID3D12PipelineState * handle, _COM_Outptr_ ID3D10Blob ** ppBlob, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetCachedBlob(ppBlob));
}

void x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(ID3D12DescriptorHeap * handle, _Out_ D3D12_CPU_DESCRIPTOR_HANDLE * pCpuDescriptorHandle) {
  pCpuDescriptorHandle[0] = handle->GetCPUDescriptorHandleForHeapStart();
}

void x12DescriptorHeapGetGPUDescriptorHandleForHeapStart(ID3D12DescriptorHeap * handle, _Out_ D3D12_GPU_DESCRIPTOR_HANDLE * pGpuDescriptorHandle) {
  pGpuDescriptorHandle[0] = handle->GetGPUDescriptorHandleForHeapStart();
}

HRESULT x12CommandListClose(ID3D12GraphicsCommandList * handle, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->Close());
}

HRESULT x12CommandListReset(ID3D12GraphicsCommandList * handle, _In_ ID3D12CommandAllocator * pAllocator, _In_opt_ ID3D12PipelineState * pInitialState, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->Reset(pAllocator, pInitialState));
}

void x12CommandListClearState(ID3D12GraphicsCommandList * handle, _In_opt_ ID3D12PipelineState * pPipelineState) {
  handle->ClearState(pPipelineState);
}

void x12CommandListDrawInstanced(ID3D12GraphicsCommandList * handle, _In_ UINT VertexCountPerInstance, _In_ UINT InstanceCount, _In_ UINT StartVertexLocation, _In_ UINT StartInstanceLocation) {
  handle->DrawInstanced(VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation);
}

void x12CommandListDrawIndexedInstanced(ID3D12GraphicsCommandList * handle, _In_ UINT IndexCountPerInstance, _In_ UINT InstanceCount, _In_ UINT StartIndexLocation, _In_ INT BaseVertexLocation, _In_ UINT StartInstanceLocation) {
  handle->DrawIndexedInstanced(IndexCountPerInstance, InstanceCount, StartIndexLocation, BaseVertexLocation, StartInstanceLocation);
}

void x12CommandListDispatch(ID3D12GraphicsCommandList * handle, _In_ UINT ThreadGroupCountX, _In_ UINT ThreadGroupCountY, _In_ UINT ThreadGroupCountZ) {
  handle->Dispatch(ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ);
}

void x12CommandListCopyBufferRegion(ID3D12GraphicsCommandList * handle, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT64 NumBytes) {
  handle->CopyBufferRegion(pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, NumBytes);
}

void x12CommandListResolveSubresource(ID3D12GraphicsCommandList * handle, _In_ ID3D12Resource * pDstResource, _In_ UINT DstSubresource, _In_ ID3D12Resource * pSrcResource, _In_ UINT SrcSubresource, _In_ DXGI_FORMAT Format) {
  handle->ResolveSubresource(pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format);
}

void x12CommandListIASetPrimitiveTopology(ID3D12GraphicsCommandList * handle, _In_ D3D12_PRIMITIVE_TOPOLOGY PrimitiveTopology) {
  handle->IASetPrimitiveTopology(PrimitiveTopology);
}

void x12CommandListRSSetViewports(ID3D12GraphicsCommandList * handle, _In_range_(0, D3D12_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE) UINT NumViewports, _In_reads_(NumViewports) const D3D12_VIEWPORT * pViewports) {
  handle->RSSetViewports(NumViewports, pViewports);
}

void x12CommandListRSSetScissorRects(ID3D12GraphicsCommandList * handle, _In_range_(0, D3D12_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE) UINT NumRects, _In_reads_(NumRects) const D3D12_RECT * pRects) {
  handle->RSSetScissorRects(NumRects, pRects);
}

void x12CommandListOMSetBlendFactor(ID3D12GraphicsCommandList * handle, _In_reads_opt_(4) const FLOAT BlendFactor[4]) {
  handle->OMSetBlendFactor(BlendFactor);
}

void x12CommandListOMSetStencilRef(ID3D12GraphicsCommandList * handle, _In_ UINT StencilRef) {
  handle->OMSetStencilRef(StencilRef);
}

void x12CommandListSetPipelineState(ID3D12GraphicsCommandList * handle, _In_ ID3D12PipelineState * pPipelineState) {
  handle->SetPipelineState(pPipelineState);
}

void x12CommandListResourceBarrier(ID3D12GraphicsCommandList * handle, _In_ UINT NumBarriers, _In_reads_(NumBarriers) const D3D12_RESOURCE_BARRIER * pBarriers) {
  handle->ResourceBarrier(NumBarriers, pBarriers);
}

void x12CommandListSetDescriptorHeaps(ID3D12GraphicsCommandList * handle, _In_ UINT NumDescriptorHeaps, _In_reads_(NumDescriptorHeaps) ID3D12DescriptorHeap * const * ppDescriptorHeaps) {
  handle->SetDescriptorHeaps(NumDescriptorHeaps, ppDescriptorHeaps);
}

void x12CommandListSetComputeRootSignature(ID3D12GraphicsCommandList * handle, _In_opt_ ID3D12RootSignature * pRootSignature) {
  handle->SetComputeRootSignature(pRootSignature);
}

void x12CommandListSetGraphicsRootSignature(ID3D12GraphicsCommandList * handle, _In_opt_ ID3D12RootSignature * pRootSignature) {
  handle->SetGraphicsRootSignature(pRootSignature);
}

void x12CommandListSetComputeRootDescriptorTable(ID3D12GraphicsCommandList * handle, _In_ UINT RootParameterIndex, _In_ D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor) {
  handle->SetComputeRootDescriptorTable(RootParameterIndex, BaseDescriptor);
}

void x12CommandListSetGraphicsRootDescriptorTable(ID3D12GraphicsCommandList * handle, _In_ UINT RootParameterIndex, _In_ D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor) {
  handle->SetGraphicsRootDescriptorTable(RootParameterIndex, BaseDescriptor);
}

void x12CommandListSetComputeRoot32BitConstant(ID3D12GraphicsCommandList * handle, _In_ UINT RootParameterIndex, _In_ UINT SrcData, _In_ UINT DestOffsetIn32BitValues) {
  handle->SetComputeRoot32BitConstant(RootParameterIndex, SrcData, DestOffsetIn32BitValues);
}

void x12CommandListSetGraphicsRoot32BitConstant(ID3D12GraphicsCommandList * handle, _In_ UINT RootParameterIndex, _In_ UINT SrcData, _In_ UINT DestOffsetIn32BitValues) {
  handle->SetGraphicsRoot32BitConstant(RootParameterIndex, SrcData, DestOffsetIn32BitValues);
}

void x12CommandListSetComputeRoot32BitConstants(ID3D12GraphicsCommandList * handle, _In_ UINT RootParameterIndex, _In_ UINT Num32BitValuesToSet, _In_reads_(Num32BitValuesToSet * sizeof(UINT)) const void * pSrcData, _In_ UINT DestOffsetIn32BitValues) {
  handle->SetComputeRoot32BitConstants(RootParameterIndex, Num32BitValuesToSet, pSrcData, DestOffsetIn32BitValues);
}

void x12CommandListSetGraphicsRoot32BitConstants(ID3D12GraphicsCommandList * handle, _In_ UINT RootParameterIndex, _In_ UINT Num32BitValuesToSet, _In_reads_(Num32BitValuesToSet * sizeof(UINT)) const void * pSrcData, _In_ UINT DestOffsetIn32BitValues) {
  handle->SetGraphicsRoot32BitConstants(RootParameterIndex, Num32BitValuesToSet, pSrcData, DestOffsetIn32BitValues);
}

void x12CommandListSetComputeRootConstantBufferView(ID3D12GraphicsCommandList * handle, _In_ UINT RootParameterIndex, _In_ D3D12_GPU_VIRTUAL_ADDRESS BufferLocation) {
  handle->SetComputeRootConstantBufferView(RootParameterIndex, BufferLocation);
}

void x12CommandListSetGraphicsRootConstantBufferView(ID3D12GraphicsCommandList * handle, _In_ UINT RootParameterIndex, _In_ D3D12_GPU_VIRTUAL_ADDRESS BufferLocation) {
  handle->SetGraphicsRootConstantBufferView(RootParameterIndex, BufferLocation);
}

void x12CommandListSetComputeRootShaderResourceView(ID3D12GraphicsCommandList * handle, _In_ UINT RootParameterIndex, _In_ D3D12_GPU_VIRTUAL_ADDRESS BufferLocation) {
  handle->SetComputeRootShaderResourceView(RootParameterIndex, BufferLocation);
}

void x12CommandListSetGraphicsRootShaderResourceView(ID3D12GraphicsCommandList * handle, _In_ UINT RootParameterIndex, _In_ D3D12_GPU_VIRTUAL_ADDRESS BufferLocation) {
  handle->SetGraphicsRootShaderResourceView(RootParameterIndex, BufferLocation);
}

void x12CommandListSetComputeRootUnorderedAccessView(ID3D12GraphicsCommandList * handle, _In_ UINT RootParameterIndex, _In_ D3D12_GPU_VIRTUAL_ADDRESS BufferLocation) {
  handle->SetComputeRootUnorderedAccessView(RootParameterIndex, BufferLocation);
}

void x12CommandListSetGraphicsRootUnorderedAccessView(ID3D12GraphicsCommandList * handle, _In_ UINT RootParameterIndex, _In_ D3D12_GPU_VIRTUAL_ADDRESS BufferLocation) {
  handle->SetGraphicsRootUnorderedAccessView(RootParameterIndex, BufferLocation);
}

void x12CommandListIASetIndexBuffer(ID3D12GraphicsCommandList * handle, _In_opt_ const D3D12_INDEX_BUFFER_VIEW * pView) {
  handle->IASetIndexBuffer(pView);
}

void x12CommandListOMSetRenderTargets(ID3D12GraphicsCommandList * handle, _In_ UINT NumRenderTargetDescriptors, _In_opt_ const D3D12_CPU_DESCRIPTOR_HANDLE * pRenderTargetDescriptors, _In_ BOOL RTsSingleHandleToDescriptorRange, _In_opt_ const D3D12_CPU_DESCRIPTOR_HANDLE * pDepthStencilDescriptor) {
  handle->OMSetRenderTargets(NumRenderTargetDescriptors, pRenderTargetDescriptors, RTsSingleHandleToDescriptorRange, pDepthStencilDescriptor);
}

void x12CommandListClearDepthStencilView(ID3D12GraphicsCommandList * handle, _In_ D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView, _In_ D3D12_CLEAR_FLAGS ClearFlags, _In_ FLOAT Depth, _In_ UINT8 Stencil, _In_ UINT NumRects, _In_reads_(NumRects) const D3D12_RECT * pRects) {
  handle->ClearDepthStencilView(DepthStencilView, ClearFlags, Depth, Stencil, NumRects, pRects);
}

void x12CommandListClearRenderTargetView(ID3D12GraphicsCommandList * handle, _In_ D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView, _In_ const FLOAT ColorRGBA[4], _In_ UINT NumRects, _In_reads_(NumRects) const D3D12_RECT * pRects) {
  handle->ClearRenderTargetView(RenderTargetView, ColorRGBA, NumRects, pRects);
}

void x12CommandListClearUnorderedAccessViewUint(ID3D12GraphicsCommandList * handle, _In_ D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap, _In_ D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle, _In_ ID3D12Resource * pResource, _In_ const UINT Values[4], _In_ UINT NumRects, _In_reads_(NumRects) const D3D12_RECT * pRects) {
  handle->ClearUnorderedAccessViewUint(ViewGPUHandleInCurrentHeap, ViewCPUHandle, pResource, Values, NumRects, pRects);
}

void x12CommandListClearUnorderedAccessViewFloat(ID3D12GraphicsCommandList * handle, _In_ D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap, _In_ D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle, _In_ ID3D12Resource * pResource, _In_ const FLOAT Values[4], _In_ UINT NumRects, _In_reads_(NumRects) const D3D12_RECT * pRects) {
  handle->ClearUnorderedAccessViewFloat(ViewGPUHandleInCurrentHeap, ViewCPUHandle, pResource, Values, NumRects, pRects);
}

void x12CommandListDiscardResource(ID3D12GraphicsCommandList * handle, _In_ ID3D12Resource * pResource, _In_opt_ const D3D12_DISCARD_REGION * pRegion) {
  handle->DiscardResource(pResource, pRegion);
}

void x12CommandQueueExecuteCommandLists(ID3D12CommandQueue * handle, _In_ UINT NumCommandLists, _In_reads_(NumCommandLists) ID3D12CommandList * const * ppCommandLists, const char * optionalFile, int optionalLine) {
  handle->ExecuteCommandLists(NumCommandLists, ppCommandLists);
}

HRESULT x12CommandQueueSignal(ID3D12CommandQueue * handle, ID3D12Fence * pFence, UINT64 Value, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->Signal(pFence, Value));
}

HRESULT x12CommandQueueWait(ID3D12CommandQueue * handle, ID3D12Fence * pFence, UINT64 Value, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->Wait(pFence, Value));
}

HRESULT x12DeviceCreateCommandQueue(ID3D12Device3 * handle, _In_ const D3D12_COMMAND_QUEUE_DESC * pDesc, _COM_Outptr_ ID3D12CommandQueue ** ppCommandQueue, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CreateCommandQueue(pDesc, IID_PPV_ARGS(ppCommandQueue)));
}

HRESULT x12DeviceCreateCommandAllocator(ID3D12Device3 * handle, _In_ D3D12_COMMAND_LIST_TYPE type, _COM_Outptr_ ID3D12CommandAllocator ** ppCommandAllocator, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CreateCommandAllocator(type, IID_PPV_ARGS(ppCommandAllocator)));
}

HRESULT x12DeviceCreateGraphicsPipelineState(ID3D12Device3 * handle, _In_ const D3D12_GRAPHICS_PIPELINE_STATE_DESC * pDesc, _COM_Outptr_ ID3D12PipelineState ** ppPipelineState, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CreateGraphicsPipelineState(pDesc, IID_PPV_ARGS(ppPipelineState)));
}

HRESULT x12DeviceCreateComputePipelineState(ID3D12Device3 * handle, _In_ const D3D12_COMPUTE_PIPELINE_STATE_DESC * pDesc, _COM_Outptr_ ID3D12PipelineState ** ppPipelineState, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CreateComputePipelineState(pDesc, IID_PPV_ARGS(ppPipelineState)));
}

HRESULT x12DeviceCreateCommandList(ID3D12Device3 * handle, _In_ UINT nodeMask, _In_ D3D12_COMMAND_LIST_TYPE type, _In_ ID3D12CommandAllocator * pCommandAllocator, _In_opt_ ID3D12PipelineState * pInitialState, _COM_Outptr_ ID3D12GraphicsCommandList ** ppCommandList, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CreateCommandList(nodeMask, type, pCommandAllocator, pInitialState, IID_PPV_ARGS(ppCommandList)));
}

HRESULT x12DeviceCheckFeatureSupport(ID3D12Device3 * handle, D3D12_FEATURE Feature, _Inout_updates_bytes_(FeatureSupportDataSize) void * pFeatureSupportData, UINT FeatureSupportDataSize, const char * optionalFile, int optionalLine) {
  return handle->CheckFeatureSupport(Feature, pFeatureSupportData, FeatureSupportDataSize);
}

HRESULT x12DeviceCreateDescriptorHeap(ID3D12Device3 * handle, _In_ const D3D12_DESCRIPTOR_HEAP_DESC * pDescriptorHeapDesc, _COM_Outptr_ ID3D12DescriptorHeap ** ppvHeap, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CreateDescriptorHeap(pDescriptorHeapDesc, IID_PPV_ARGS(ppvHeap)));
}

UINT x12DeviceGetDescriptorHandleIncrementSize(ID3D12Device3 * handle, _In_ D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType, const char * optionalFile, int optionalLine) {
  return handle->GetDescriptorHandleIncrementSize(DescriptorHeapType);
}

HRESULT x12DeviceCreateRootSignature(ID3D12Device3 * handle, _In_ UINT nodeMask, _In_reads_(blobLengthInBytes) const void * pBlobWithRootSignature, _In_ SIZE_T blobLengthInBytes, _COM_Outptr_ ID3D12RootSignature ** ppvRootSignature, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CreateRootSignature(nodeMask, pBlobWithRootSignature, blobLengthInBytes, IID_PPV_ARGS(ppvRootSignature)));
}

void x12DeviceCreateConstantBufferView(ID3D12Device3 * handle, _In_opt_ const D3D12_CONSTANT_BUFFER_VIEW_DESC * pDesc, _In_ D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor, const char * optionalFile, int optionalLine) {
  handle->CreateConstantBufferView(pDesc, DestDescriptor);
}

void x12DeviceCreateShaderResourceView(ID3D12Device3 * handle, _In_opt_ ID3D12Resource * pResource, _In_opt_ const D3D12_SHADER_RESOURCE_VIEW_DESC * pDesc, _In_ D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor, const char * optionalFile, int optionalLine) {
  handle->CreateShaderResourceView(pResource, pDesc, DestDescriptor);
}

void x12DeviceCreateUnorderedAccessView(ID3D12Device3 * handle, _In_opt_ ID3D12Resource * pResource, _In_opt_ ID3D12Resource * pCounterResource, _In_opt_ const D3D12_UNORDERED_ACCESS_VIEW_DESC * pDesc, _In_ D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor, const char * optionalFile, int optionalLine) {
  handle->CreateUnorderedAccessView(pResource, pCounterResource, pDesc, DestDescriptor);
}

void x12DeviceCreateRenderTargetView(ID3D12Device3 * handle, _In_opt_ ID3D12Resource * pResource, _In_opt_ const D3D12_RENDER_TARGET_VIEW_DESC * pDesc, _In_ D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor, const char * optionalFile, int optionalLine) {
  handle->CreateRenderTargetView(pResource, pDesc, DestDescriptor);
}

void x12DeviceCreateDepthStencilView(ID3D12Device3 * handle, _In_opt_ ID3D12Resource * pResource, _In_opt_ const D3D12_DEPTH_STENCIL_VIEW_DESC * pDesc, _In_ D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor, const char * optionalFile, int optionalLine) {
  handle->CreateDepthStencilView(pResource, pDesc, DestDescriptor);
}

void x12DeviceCreateSampler(ID3D12Device3 * handle, _In_ const D3D12_SAMPLER_DESC * pDesc, _In_ D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor, const char * optionalFile, int optionalLine) {
  handle->CreateSampler(pDesc, DestDescriptor);
}

void x12DeviceCopyDescriptors(ID3D12Device3 * handle, _In_ UINT NumDestDescriptorRanges, _In_reads_(NumDestDescriptorRanges) const D3D12_CPU_DESCRIPTOR_HANDLE * pDestDescriptorRangeStarts, _In_reads_opt_(NumDestDescriptorRanges) const UINT * pDestDescriptorRangeSizes, _In_ UINT NumSrcDescriptorRanges, _In_reads_(NumSrcDescriptorRanges) const D3D12_CPU_DESCRIPTOR_HANDLE * pSrcDescriptorRangeStarts, _In_reads_opt_(NumSrcDescriptorRanges) const UINT * pSrcDescriptorRangeSizes, _In_ D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType, const char * optionalFile, int optionalLine) {
  handle->CopyDescriptors(NumDestDescriptorRanges, pDestDescriptorRangeStarts, pDestDescriptorRangeSizes, NumSrcDescriptorRanges, pSrcDescriptorRangeStarts, pSrcDescriptorRangeSizes, DescriptorHeapsType);
}

void x12DeviceGetResourceAllocationInfo(ID3D12Device3 * handle, _In_ UINT visibleMask, _In_ UINT numResourceDescs, _In_reads_(numResourceDescs) const D3D12_RESOURCE_DESC * pResourceDescs, _Out_ D3D12_RESOURCE_ALLOCATION_INFO * pResourceAllocationInfo, const char * optionalFile, int optionalLine) {
  pResourceAllocationInfo[0] = handle->GetResourceAllocationInfo(visibleMask, numResourceDescs, pResourceDescs);
}

HRESULT x12DeviceCreateCommittedResource(ID3D12Device3 * handle, _In_ const D3D12_HEAP_PROPERTIES * pHeapProperties, D3D12_HEAP_FLAGS HeapFlags, _In_ const D3D12_RESOURCE_DESC * pDesc, D3D12_RESOURCE_STATES InitialResourceState, _In_opt_ const D3D12_CLEAR_VALUE * pOptimizedClearValue, _COM_Outptr_ ID3D12Resource ** ppvResource, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CreateCommittedResource(pHeapProperties, HeapFlags, pDesc, InitialResourceState, pOptimizedClearValue, IID_PPV_ARGS(ppvResource)));
}

HRESULT x12DeviceCreateHeap(ID3D12Device3 * handle, _In_ const D3D12_HEAP_DESC * pDesc, _COM_Outptr_ ID3D12Heap ** ppvHeap, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CreateHeap(pDesc, IID_PPV_ARGS(ppvHeap)));
}

HRESULT x12DeviceCreatePlacedResource(ID3D12Device3 * handle, _In_ ID3D12Heap * pHeap, UINT64 HeapOffset, _In_ const D3D12_RESOURCE_DESC * pDesc, D3D12_RESOURCE_STATES InitialState, _In_opt_ const D3D12_CLEAR_VALUE * pOptimizedClearValue, _COM_Outptr_ ID3D12Resource ** ppvResource, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CreatePlacedResource(pHeap, HeapOffset, pDesc, InitialState, pOptimizedClearValue, IID_PPV_ARGS(ppvResource)));
}

HRESULT x12DeviceMakeResident(ID3D12Device3 * handle, UINT NumObjects, _In_reads_(NumObjects) ID3D12Pageable * const * ppObjects, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->MakeResident(NumObjects, ppObjects));
}

HRESULT x12DeviceEvict(ID3D12Device3 * handle, UINT NumObjects, _In_reads_(NumObjects) ID3D12Pageable * const * ppObjects, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->Evict(NumObjects, ppObjects));
}

HRESULT x12DeviceCreateFence(ID3D12Device3 * handle, UINT64 InitialValue, D3D12_FENCE_FLAGS Flags, _COM_Outptr_ ID3D12Fence ** ppFence, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CreateFence(InitialValue, Flags, IID_PPV_ARGS(ppFence)));
}

HRESULT x12DeviceGetDeviceRemovedReason(ID3D12Device3 * handle, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetDeviceRemovedReason());
}

HRESULT x12DeviceSetStablePowerState(ID3D12Device3 * handle, BOOL Enable, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetStablePowerState(Enable));
}

void x12DeviceGetAdapterLuid(ID3D12Device3 * handle, _Out_ LUID * pLuid, const char * optionalFile, int optionalLine) {
  pLuid[0] = handle->GetAdapterLuid();
}

HRESULT x12DeviceSetEventOnMultipleFenceCompletion(ID3D12Device3 * handle, _In_reads_(NumFences) ID3D12Fence * const * ppFences, _In_reads_(NumFences) const UINT64 * pFenceValues, UINT NumFences, D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags, HANDLE hEvent, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetEventOnMultipleFenceCompletion(ppFences, pFenceValues, NumFences, Flags, hEvent));
}

HRESULT x12DeviceSetResidencyPriority(ID3D12Device3 * handle, UINT NumObjects, _In_reads_(NumObjects) ID3D12Pageable * const * ppObjects, _In_reads_(NumObjects) const UINT * pPriorities, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetResidencyPriority(NumObjects, ppObjects, pPriorities));
}

HRESULT x12DeviceEnqueueMakeResident(ID3D12Device3 * handle, D3D12_RESIDENCY_FLAGS Flags, UINT NumObjects, _In_reads_(NumObjects) ID3D12Pageable * const * ppObjects, _In_ ID3D12Fence * pFenceToSignal, UINT64 FenceValueToSignal, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->EnqueueMakeResident(Flags, NumObjects, ppObjects, pFenceToSignal, FenceValueToSignal));
}

const D3D12_ROOT_SIGNATURE_DESC * x12RootSignatureDeserializerGetRootSignatureDesc(ID3D12RootSignatureDeserializer * handle, const char * optionalFile, int optionalLine) {
  return handle->GetRootSignatureDesc();
}

HRESULT x12SerializeRootSignature(_In_ const D3D12_ROOT_SIGNATURE_DESC * pRootSignature, _In_ D3D_ROOT_SIGNATURE_VERSION Version, _Out_ ID3D10Blob ** ppBlob, _Always_(_Outptr_opt_result_maybenull_) ID3D10Blob ** ppErrorBlob, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(D3D12SerializeRootSignature(pRootSignature, Version, ppBlob, ppErrorBlob));
}

HRESULT x12CreateRootSignatureDeserializer(_In_reads_bytes_(SrcDataSizeInBytes) LPCVOID pSrcData, _In_ SIZE_T SrcDataSizeInBytes, _COM_Outptr_ ID3D12RootSignatureDeserializer ** ppRootSignatureDeserializer, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(D3D12CreateRootSignatureDeserializer(pSrcData, SrcDataSizeInBytes, IID_PPV_ARGS(ppRootSignatureDeserializer)));
}

HRESULT x12CreateDevice(_In_opt_ IDXGIAdapter3 * pAdapter, D3D_FEATURE_LEVEL MinimumFeatureLevel, _COM_Outptr_ ID3D12Device3 ** ppDevice, const char * optionalFile, int optionalLine) {
  HRESULT hresult = S_OK;
  if (ppDevice != NULL) {
    ID3D12Device * device = NULL;
    hresult = x12CheckHresult(D3D12CreateDevice(pAdapter, MinimumFeatureLevel, IID_PPV_ARGS(&device)));
    if (hresult == S_OK) {
      hresult = x12CheckHresult(device->QueryInterface(IID_PPV_ARGS(ppDevice)));
      device->Release();
    }
  } else {
    // Just checking MinimumFeatureLevel support then.
    hresult = D3D12CreateDevice(pAdapter, MinimumFeatureLevel, _uuidof(ID3D12Device), nullptr);
  }
  return hresult;
}

// DXGI

HRESULT x12AdapterEnumOutputs(IDXGIAdapter3 * handle, UINT Output, _COM_Outptr_ IDXGIOutput4 ** ppOutput, const char * optionalFile, int optionalLine) {
  IDXGIOutput * output = NULL;
  HRESULT hresult = x12CheckHresult(handle->EnumOutputs(Output, &output));
  if (hresult == S_OK) {
    hresult = x12CheckHresult(output->QueryInterface(IID_PPV_ARGS(ppOutput)));
    output->Release();
  }
  return hresult;
}

HRESULT x12OutputWaitForVBlank(IDXGIOutput4 * handle, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->WaitForVBlank());
}

HRESULT x12OutputGetGammaControlCapabilities(IDXGIOutput4 * handle, _Out_ DXGI_GAMMA_CONTROL_CAPABILITIES * pGammaCaps, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetGammaControlCapabilities(pGammaCaps));
}

HRESULT x12OutputSetGammaControl(IDXGIOutput4 * handle, _In_ const DXGI_GAMMA_CONTROL * pArray, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetGammaControl(pArray));
}

HRESULT x12OutputGetGammaControl(IDXGIOutput4 * handle, _Out_ DXGI_GAMMA_CONTROL * pArray, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetGammaControl(pArray));
}

HRESULT x12OutputGetFrameStatistics(IDXGIOutput4 * handle, _Out_ DXGI_FRAME_STATISTICS * pStats, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetFrameStatistics(pStats));
}

HRESULT x12SwapChainGetBuffer(IDXGISwapChain3 * handle, UINT Buffer, _COM_Outptr_ ID3D12Resource ** ppSurface, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetBuffer(Buffer, IID_PPV_ARGS(ppSurface)));
}

HRESULT x12SwapChainSetFullscreenState(IDXGISwapChain3 * handle, BOOL Fullscreen, _In_opt_ IDXGIOutput4 * pTarget, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetFullscreenState(Fullscreen, pTarget));
}

HRESULT x12SwapChainResizeTarget(IDXGISwapChain3 * handle, _In_ const DXGI_MODE_DESC * pNewTargetParameters, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->ResizeTarget(pNewTargetParameters));
}

HRESULT x12SwapChainGetFrameStatistics(IDXGISwapChain3 * handle, _Out_ DXGI_FRAME_STATISTICS * pStats, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetFrameStatistics(pStats));
}

HRESULT x12SwapChainGetLastPresentCount(IDXGISwapChain3 * handle, _Out_ UINT * pLastPresentCount, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetLastPresentCount(pLastPresentCount));
}

HRESULT x12FactoryMakeWindowAssociation(IDXGIFactory4 * handle, HWND WindowHandle, UINT Flags, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->MakeWindowAssociation(WindowHandle, Flags));
}

HRESULT x12FactoryGetWindowAssociation(IDXGIFactory4 * handle, _Out_ HWND * pWindowHandle, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetWindowAssociation(pWindowHandle));
}

HRESULT x12FactoryEnumAdapters1(IDXGIFactory4 * handle, UINT Adapter, _COM_Outptr_ IDXGIAdapter3 ** ppAdapter, const char * optionalFile, int optionalLine) {
  IDXGIAdapter1 * adapter = NULL;
  HRESULT hresult = handle->EnumAdapters1(Adapter, &adapter);
  if (hresult == S_OK) {
    hresult = x12CheckHresult(adapter->QueryInterface(IID_PPV_ARGS(ppAdapter)));
    adapter->Release();
  } else if (hresult == /*DXGI_ERROR_NOT_FOUND*/MAKE_HRESULT(1, 0x87a, 2)) {
    // Iterating adapters, skip then.
  } else {
    // Some other error, report then.
    x12CheckHresult(hresult);
  }
  return hresult;
}

BOOL x12FactoryIsCurrent(IDXGIFactory4 * handle, const char * optionalFile, int optionalLine) {
  return handle->IsCurrent();
}

HRESULT x12SwapChainGetFullscreenDesc(IDXGISwapChain3 * handle, _Out_ DXGI_SWAP_CHAIN_FULLSCREEN_DESC * pDesc, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetFullscreenDesc(pDesc));
}

HRESULT x12SwapChainPresent1(IDXGISwapChain3 * handle, UINT SyncInterval, UINT PresentFlags, _In_ const DXGI_PRESENT_PARAMETERS * pPresentParameters, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->Present1(SyncInterval, PresentFlags, pPresentParameters));
}

HRESULT x12SwapChainSetBackgroundColor(IDXGISwapChain3 * handle, _In_ const DXGI_RGBA * pColor, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetBackgroundColor(pColor));
}

HRESULT x12SwapChainGetBackgroundColor(IDXGISwapChain3 * handle, _Out_ DXGI_RGBA * pColor, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetBackgroundColor(pColor));
}

HRESULT x12SwapChainSetRotation(IDXGISwapChain3 * handle, _In_ DXGI_MODE_ROTATION Rotation, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetRotation(Rotation));
}

HRESULT x12SwapChainGetRotation(IDXGISwapChain3 * handle, _Out_ DXGI_MODE_ROTATION * pRotation, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetRotation(pRotation));
}

HRESULT x12FactoryCreateSwapChainForHwnd(IDXGIFactory4 * handle, _In_ ID3D12CommandQueue * pCommandQueue, _In_ HWND hWnd, _In_ const DXGI_SWAP_CHAIN_DESC1 * pDesc, _In_opt_ const DXGI_SWAP_CHAIN_FULLSCREEN_DESC * pFullscreenDesc, _In_opt_ IDXGIOutput4 * pRestrictToOutput, _COM_Outptr_ IDXGISwapChain3 ** ppSwapChain, const char * optionalFile, int optionalLine) {
  IDXGISwapChain1 * swapchain = NULL;
  HRESULT hresult = x12CheckHresult(handle->CreateSwapChainForHwnd(pCommandQueue, hWnd, pDesc, pFullscreenDesc, pRestrictToOutput, &swapchain));
  if (hresult == S_OK) {
    hresult = x12CheckHresult(swapchain->QueryInterface(IID_PPV_ARGS(ppSwapChain)));
    swapchain->Release();
  }
  return hresult;
}

HRESULT x12FactoryCreateSwapChainForCoreWindow(IDXGIFactory4 * handle, _In_ ID3D12CommandQueue * pCommandQueue, _In_ const void * pWindow, _In_ const DXGI_SWAP_CHAIN_DESC1 * pDesc, _In_opt_ IDXGIOutput4 * pRestrictToOutput, _COM_Outptr_ IDXGISwapChain3 ** ppSwapChain, const char * optionalFile, int optionalLine) {
  IDXGISwapChain1 * swapchain = NULL;
  HRESULT hresult = x12CheckHresult(handle->CreateSwapChainForCoreWindow(pCommandQueue, (IUnknown *)pWindow, pDesc, pRestrictToOutput, &swapchain));
  if (hresult == S_OK) {
    hresult = x12CheckHresult(swapchain->QueryInterface(IID_PPV_ARGS(ppSwapChain)));
    swapchain->Release();
  }
  return hresult;
}

HRESULT x12FactoryRegisterOcclusionStatusWindow(IDXGIFactory4 * handle, _In_ HWND WindowHandle, _In_ UINT wMsg, _Out_ DWORD * pdwCookie, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->RegisterOcclusionStatusWindow(WindowHandle, wMsg, pdwCookie));
}

HRESULT x12FactoryRegisterOcclusionStatusEvent(IDXGIFactory4 * handle, _In_ HANDLE hEvent, _Out_ DWORD * pdwCookie, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->RegisterOcclusionStatusEvent(hEvent, pdwCookie));
}

void x12FactoryUnregisterOcclusionStatus(IDXGIFactory4 * handle, _In_ DWORD dwCookie, const char * optionalFile, int optionalLine) {
  handle->UnregisterOcclusionStatus(dwCookie);
}

HRESULT x12FactoryCreateSwapChainForComposition(IDXGIFactory4 * handle, _In_ ID3D12CommandQueue * pCommandQueue, _In_ const DXGI_SWAP_CHAIN_DESC1 * pDesc, _In_opt_ IDXGIOutput4 * pRestrictToOutput, _COM_Outptr_ IDXGISwapChain3 ** ppSwapChain, const char * optionalFile, int optionalLine) {
  IDXGISwapChain1 * swapchain = NULL;
  HRESULT hresult = x12CheckHresult(handle->CreateSwapChainForComposition(pCommandQueue, pDesc, pRestrictToOutput, &swapchain));
  if (hresult == S_OK) {
    hresult = x12CheckHresult(swapchain->QueryInterface(IID_PPV_ARGS(ppSwapChain)));
    swapchain->Release();
  }
  return hresult;
}

HRESULT x12AdapterGetDesc2(IDXGIAdapter3 * handle, _Out_ DXGI_ADAPTER_DESC2 * pDesc, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetDesc2(pDesc));
}

HRESULT x12OutputGetDesc(IDXGIOutput4 * handle, _Out_ DXGI_OUTPUT_DESC * pDesc, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetDesc(pDesc));
}

HRESULT x12OutputGetDisplayModeList1(IDXGIOutput4 * handle, DXGI_FORMAT EnumFormat, UINT Flags, _Inout_ UINT * pNumModes, _Out_writes_to_opt_(*pNumModes, *pNumModes) DXGI_MODE_DESC1 * pDesc, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetDisplayModeList1(EnumFormat, Flags, pNumModes, pDesc));
}

HRESULT x12OutputFindClosestMatchingMode1(IDXGIOutput4 * handle, _In_ const DXGI_MODE_DESC1 * pModeToMatch, _Out_ DXGI_MODE_DESC1 * pClosestMatch, _In_opt_ ID3D12Device3 * pConcernedDevice, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->FindClosestMatchingMode1(pModeToMatch, pClosestMatch, pConcernedDevice));
}

HRESULT x12SwapChainSetSourceSize(IDXGISwapChain3 * handle, UINT Width, UINT Height, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetSourceSize(Width, Height));
}

HRESULT x12SwapChainGetSourceSize(IDXGISwapChain3 * handle, _Out_ UINT * pWidth, _Out_ UINT * pHeight, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetSourceSize(pWidth, pHeight));
}

HRESULT x12SwapChainSetMaximumFrameLatency(IDXGISwapChain3 * handle, UINT MaxLatency, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetMaximumFrameLatency(MaxLatency));
}

HRESULT x12SwapChainGetMaximumFrameLatency(IDXGISwapChain3 * handle, _Out_ UINT * pMaxLatency, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetMaximumFrameLatency(pMaxLatency));
}

HANDLE x12SwapChainGetFrameLatencyWaitableObject(IDXGISwapChain3 * handle, const char * optionalFile, int optionalLine) {
  return handle->GetFrameLatencyWaitableObject();
}

HRESULT x12SwapChainSetMatrixTransform(IDXGISwapChain3 * handle, const DXGI_MATRIX_3X2_F * pMatrix, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetMatrixTransform(pMatrix));
}

HRESULT x12SwapChainGetMatrixTransform(IDXGISwapChain3 * handle, _Out_ DXGI_MATRIX_3X2_F * pMatrix, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->GetMatrixTransform(pMatrix));
}

BOOL x12OutputSupportsOverlays(IDXGIOutput4 * handle, const char * optionalFile, int optionalLine) {
  return handle->SupportsOverlays();
}

HRESULT x12OutputCheckOverlaySupport(IDXGIOutput4 * handle, _In_ DXGI_FORMAT EnumFormat, _In_ ID3D12Device3 * pConcernedDevice, _Out_ UINT * pFlags, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CheckOverlaySupport(EnumFormat, pConcernedDevice, pFlags));
}

UINT x12SwapChainGetCurrentBackBufferIndex(IDXGISwapChain3 * handle, const char * optionalFile, int optionalLine) {
  return handle->GetCurrentBackBufferIndex();
}

HRESULT x12SwapChainCheckColorSpaceSupport(IDXGISwapChain3 * handle, _In_ DXGI_COLOR_SPACE_TYPE ColorSpace, _Out_ UINT * pColorSpaceSupport, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CheckColorSpaceSupport(ColorSpace, pColorSpaceSupport));
}

HRESULT x12SwapChainSetColorSpace1(IDXGISwapChain3 * handle, _In_ DXGI_COLOR_SPACE_TYPE ColorSpace, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetColorSpace1(ColorSpace));
}

HRESULT x12SwapChainResizeBuffers1(IDXGISwapChain3 * handle, _In_ UINT BufferCount, _In_ UINT Width, _In_ UINT Height, _In_ DXGI_FORMAT Format, _In_ UINT SwapChainFlags, _In_reads_(BufferCount) const UINT * pCreationNodeMask, _In_reads_(BufferCount) ID3D12CommandQueue * const * ppPresentQueue, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->ResizeBuffers1(BufferCount, Width, Height, Format, SwapChainFlags, pCreationNodeMask, (IUnknown * const *)ppPresentQueue));
}

HRESULT x12OutputCheckOverlayColorSpaceSupport(IDXGIOutput4 * handle, _In_ DXGI_FORMAT Format, _In_ DXGI_COLOR_SPACE_TYPE ColorSpace, _In_ ID3D12Device3 * pConcernedDevice, _Out_ UINT * pFlags, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->CheckOverlayColorSpaceSupport(Format, ColorSpace, pConcernedDevice, pFlags));
}

HRESULT x12AdapterQueryVideoMemoryInfo(IDXGIAdapter3 * handle, _In_ UINT NodeIndex, _In_ DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup, _Out_ DXGI_QUERY_VIDEO_MEMORY_INFO * pVideoMemoryInfo, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->QueryVideoMemoryInfo(NodeIndex, MemorySegmentGroup, pVideoMemoryInfo));
}

HRESULT x12AdapterSetVideoMemoryReservation(IDXGIAdapter3 * handle, _In_ UINT NodeIndex, _In_ DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup, _In_ UINT64 Reservation, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetVideoMemoryReservation(NodeIndex, MemorySegmentGroup, Reservation));
}

HRESULT x12AdapterRegisterVideoMemoryBudgetChangeNotificationEvent(IDXGIAdapter3 * handle, _In_ HANDLE hEvent, _Out_ DWORD * pdwCookie, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->RegisterVideoMemoryBudgetChangeNotificationEvent(hEvent, pdwCookie));
}

void x12AdapterUnregisterVideoMemoryBudgetChangeNotification(IDXGIAdapter3 * handle, _In_ DWORD dwCookie, const char * optionalFile, int optionalLine) {
  handle->UnregisterVideoMemoryBudgetChangeNotification(dwCookie);
}

HRESULT x12CreateFactory2(UINT Flags, _COM_Outptr_ IDXGIFactory4 ** ppFactory, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(CreateDXGIFactory2(Flags, IID_PPV_ARGS(ppFactory)));
}

// Debug

static HRESULT x12GetDebugInterface(_COM_Outptr_ ID3D12Debug ** ppvDebug, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(D3D12GetDebugInterface(IID_PPV_ARGS(ppvDebug)));
}

static HRESULT x12GetDebugInterface1Debug(UINT Flags, _COM_Outptr_ IDXGIDebug1 ** ppDebug, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(DXGIGetDebugInterface1(Flags, IID_PPV_ARGS(ppDebug)));
}

static HRESULT x12GetDebugInterface1InfoQueue(UINT Flags, _COM_Outptr_ IDXGIInfoQueue ** ppInfoQueue, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(DXGIGetDebugInterface1(Flags, IID_PPV_ARGS(ppInfoQueue)));
}

static void x12DebugEnableDebugLayer(ID3D12Debug * handle, const char * optionalFile, int optionalLine) {
  handle->EnableDebugLayer();
}

static void x12DebugEnableLeakTrackingForThread(IDXGIDebug1 * handle, const char * optionalFile, int optionalLine) {
  handle->EnableLeakTrackingForThread();
}

static HRESULT x12InfoQueueSetBreakOnSeverity(IDXGIInfoQueue * handle, _In_ DXGI_DEBUG_ID Producer, _In_ DXGI_INFO_QUEUE_MESSAGE_SEVERITY Severity, _In_ BOOL bEnable, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->SetBreakOnSeverity(Producer, Severity, bEnable));
}

static HRESULT x12DebugReportLiveObjects(IDXGIDebug1 * handle, GUID apiid, DXGI_DEBUG_RLO_FLAGS flags, const char * optionalFile, int optionalLine) {
  return x12CheckHresult(handle->ReportLiveObjects(apiid, flags));
}

// Helpers

void * x12DebugEnable(const char * optionalFile, int optionalLine) {
  IDXGIDebug1 *    debugDXGI          = NULL;
  ID3D12Debug *    debugD3D12         = NULL;
  IDXGIInfoQueue * debugDXGIInfoQueue = NULL;
  x12GetDebugInterface(&debugD3D12, optionalFile, optionalLine);
  x12GetDebugInterface1Debug(0, &debugDXGI, optionalFile, optionalLine);
  x12GetDebugInterface1InfoQueue(0, &debugDXGIInfoQueue, optionalFile, optionalLine);
  x12DebugEnableDebugLayer(debugD3D12, optionalFile, optionalLine);
  x12DebugEnableLeakTrackingForThread(debugDXGI, optionalFile, optionalLine);
  x12InfoQueueSetBreakOnSeverity(debugDXGIInfoQueue, DXGI_DEBUG_ALL, DXGI_INFO_QUEUE_MESSAGE_SEVERITY_CORRUPTION, 1, optionalFile, optionalLine);
  x12InfoQueueSetBreakOnSeverity(debugDXGIInfoQueue, DXGI_DEBUG_ALL, DXGI_INFO_QUEUE_MESSAGE_SEVERITY_ERROR,      1, optionalFile, optionalLine);
  x12InfoQueueSetBreakOnSeverity(debugDXGIInfoQueue, DXGI_DEBUG_ALL, DXGI_INFO_QUEUE_MESSAGE_SEVERITY_WARNING,    1, optionalFile, optionalLine);
  x12InfoQueueSetBreakOnSeverity(debugDXGIInfoQueue, DXGI_DEBUG_ALL, DXGI_INFO_QUEUE_MESSAGE_SEVERITY_INFO,       1, optionalFile, optionalLine);
  x12InfoQueueSetBreakOnSeverity(debugDXGIInfoQueue, DXGI_DEBUG_ALL, DXGI_INFO_QUEUE_MESSAGE_SEVERITY_MESSAGE,    1, optionalFile, optionalLine);
  return debugDXGI;
}

void x12DebugReport(void * debugContext, const char * optionalFile, int optionalLine) {
  x12DebugReportLiveObjects((IDXGIDebug1 *)debugContext, DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_ALL, optionalFile, optionalLine);
}

// Release

void x12Release(IUnknown * handle, const char * optionalFile, int optionalLine) {
  if (handle != NULL) {
    handle->Release();
  }
}

// PIX

void x12CommandListSetMarker(ID3D12GraphicsCommandList * handle, UINT Metadata, _In_reads_bytes_opt_(Size) const void * pData, UINT Size) {
  handle->SetMarker(Metadata, pData, Size);
}

void x12CommandListBeginEvent(ID3D12GraphicsCommandList * handle, UINT Metadata, _In_reads_bytes_opt_(Size) const void * pData, UINT Size) {
  handle->BeginEvent(Metadata, pData, Size);
}

void x12CommandListEndEvent(ID3D12GraphicsCommandList * handle) {
  handle->EndEvent();
}

void x12CommandQueueSetMarker(ID3D12CommandQueue * handle, UINT Metadata, _In_reads_bytes_opt_(Size) const void * pData, UINT Size) {
  handle->SetMarker(Metadata, pData, Size);
}

void x12CommandQueueBeginEvent(ID3D12CommandQueue * handle, UINT Metadata, _In_reads_bytes_opt_(Size) const void * pData, UINT Size) {
  handle->BeginEvent(Metadata, pData, Size);
}

void x12CommandQueueEndEvent(ID3D12CommandQueue * handle) {
  handle->EndEvent();
}