#pragma once

#ifndef REDGPU_NP_STRUCT_INIT
#ifdef __cplusplus
#define REDGPU_NP_STRUCT_INIT(x) x
#else
#define REDGPU_NP_STRUCT_INIT(x) (x)
#endif
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12AdapterRegisterVideoMemoryBudgetChangeNotificationEvent x12AdapterRegisterVideoMemoryBudgetChangeNotificationEvent
#define _0404f986_pAdapter(value) value
#define _0404f986_hEvent(value) value
#define _0404f986_outdwCookie(value) value
#define _0404f986_optionalFile(value) value
#define _0404f986_optionalLine(value) value
#else
typedef struct _s_0404f986_pAdapter { X12Adapter3* value; } _s_0404f986_pAdapter;
typedef struct _s_0404f986_hEvent { void* value; } _s_0404f986_hEvent;
typedef struct _s_0404f986_outdwCookie { unsigned* value; } _s_0404f986_outdwCookie;
typedef struct _s_0404f986_optionalFile { char* value; } _s_0404f986_optionalFile;
typedef struct _s_0404f986_optionalLine { int value; } _s_0404f986_optionalLine;
static inline _s_0404f986_pAdapter _0404f986_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_0404f986_pAdapter){value}; }
static inline _s_0404f986_hEvent _0404f986_hEvent(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0404f986_hEvent){value}; }
static inline _s_0404f986_outdwCookie _0404f986_outdwCookie(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_0404f986_outdwCookie){value}; }
static inline _s_0404f986_optionalFile _0404f986_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0404f986_optionalFile){value}; }
static inline _s_0404f986_optionalLine _0404f986_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0404f986_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12AdapterRegisterVideoMemoryBudgetChangeNotificationEvent(_s_0404f986_pAdapter pAdapter, _s_0404f986_hEvent hEvent, _s_0404f986_outdwCookie outdwCookie, _s_0404f986_optionalFile optionalFile, _s_0404f986_optionalLine optionalLine) {
  return x12AdapterRegisterVideoMemoryBudgetChangeNotificationEvent(pAdapter.value, hEvent.value, outdwCookie.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12AdapterUnregisterVideoMemoryBudgetChangeNotification x12AdapterUnregisterVideoMemoryBudgetChangeNotification
#define _791fa4df_pAdapter(value) value
#define _791fa4df_dwCookie(value) value
#define _791fa4df_optionalFile(value) value
#define _791fa4df_optionalLine(value) value
#else
typedef struct _s_791fa4df_pAdapter { X12Adapter3* value; } _s_791fa4df_pAdapter;
typedef struct _s_791fa4df_dwCookie { unsigned value; } _s_791fa4df_dwCookie;
typedef struct _s_791fa4df_optionalFile { char* value; } _s_791fa4df_optionalFile;
typedef struct _s_791fa4df_optionalLine { int value; } _s_791fa4df_optionalLine;
static inline _s_791fa4df_pAdapter _791fa4df_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_791fa4df_pAdapter){value}; }
static inline _s_791fa4df_dwCookie _791fa4df_dwCookie(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_791fa4df_dwCookie){value}; }
static inline _s_791fa4df_optionalFile _791fa4df_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_791fa4df_optionalFile){value}; }
static inline _s_791fa4df_optionalLine _791fa4df_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_791fa4df_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12AdapterUnregisterVideoMemoryBudgetChangeNotification(_s_791fa4df_pAdapter pAdapter, _s_791fa4df_dwCookie dwCookie, _s_791fa4df_optionalFile optionalFile, _s_791fa4df_optionalLine optionalLine) {
  x12AdapterUnregisterVideoMemoryBudgetChangeNotification(pAdapter.value, dwCookie.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12AdapterQueryVideoMemoryInfo x12AdapterQueryVideoMemoryInfo
#define _87a9b1d6_pAdapter(value) value
#define _87a9b1d6_NodeIndex(value) value
#define _87a9b1d6_MemorySegmentGroup(value) value
#define _87a9b1d6_pVideoMemoryInfo(value) value
#define _87a9b1d6_optionalFile(value) value
#define _87a9b1d6_optionalLine(value) value
#else
typedef struct _s_87a9b1d6_pAdapter { X12Adapter3* value; } _s_87a9b1d6_pAdapter;
typedef struct _s_87a9b1d6_NodeIndex { unsigned value; } _s_87a9b1d6_NodeIndex;
typedef struct _s_87a9b1d6_MemorySegmentGroup { DXGI_MEMORY_SEGMENT_GROUP value; } _s_87a9b1d6_MemorySegmentGroup;
typedef struct _s_87a9b1d6_pVideoMemoryInfo { DXGI_QUERY_VIDEO_MEMORY_INFO* value; } _s_87a9b1d6_pVideoMemoryInfo;
typedef struct _s_87a9b1d6_optionalFile { char* value; } _s_87a9b1d6_optionalFile;
typedef struct _s_87a9b1d6_optionalLine { int value; } _s_87a9b1d6_optionalLine;
static inline _s_87a9b1d6_pAdapter _87a9b1d6_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_87a9b1d6_pAdapter){value}; }
static inline _s_87a9b1d6_NodeIndex _87a9b1d6_NodeIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_87a9b1d6_NodeIndex){value}; }
static inline _s_87a9b1d6_MemorySegmentGroup _87a9b1d6_MemorySegmentGroup(DXGI_MEMORY_SEGMENT_GROUP value) { return REDGPU_NP_STRUCT_INIT(_s_87a9b1d6_MemorySegmentGroup){value}; }
static inline _s_87a9b1d6_pVideoMemoryInfo _87a9b1d6_pVideoMemoryInfo(DXGI_QUERY_VIDEO_MEMORY_INFO* value) { return REDGPU_NP_STRUCT_INIT(_s_87a9b1d6_pVideoMemoryInfo){value}; }
static inline _s_87a9b1d6_optionalFile _87a9b1d6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_87a9b1d6_optionalFile){value}; }
static inline _s_87a9b1d6_optionalLine _87a9b1d6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_87a9b1d6_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12AdapterQueryVideoMemoryInfo(_s_87a9b1d6_pAdapter pAdapter, _s_87a9b1d6_NodeIndex NodeIndex, _s_87a9b1d6_MemorySegmentGroup MemorySegmentGroup, _s_87a9b1d6_pVideoMemoryInfo pVideoMemoryInfo, _s_87a9b1d6_optionalFile optionalFile, _s_87a9b1d6_optionalLine optionalLine) {
  return x12AdapterQueryVideoMemoryInfo(pAdapter.value, NodeIndex.value, MemorySegmentGroup.value, pVideoMemoryInfo.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12AdapterSetVideoMemoryReservation x12AdapterSetVideoMemoryReservation
#define _d78fab0a_pAdapter(value) value
#define _d78fab0a_NodeIndex(value) value
#define _d78fab0a_MemorySegmentGroup(value) value
#define _d78fab0a_Reservation(value) value
#define _d78fab0a_optionalFile(value) value
#define _d78fab0a_optionalLine(value) value
#else
typedef struct _s_d78fab0a_pAdapter { X12Adapter3* value; } _s_d78fab0a_pAdapter;
typedef struct _s_d78fab0a_NodeIndex { unsigned value; } _s_d78fab0a_NodeIndex;
typedef struct _s_d78fab0a_MemorySegmentGroup { DXGI_MEMORY_SEGMENT_GROUP value; } _s_d78fab0a_MemorySegmentGroup;
typedef struct _s_d78fab0a_Reservation { uint64_t value; } _s_d78fab0a_Reservation;
typedef struct _s_d78fab0a_optionalFile { char* value; } _s_d78fab0a_optionalFile;
typedef struct _s_d78fab0a_optionalLine { int value; } _s_d78fab0a_optionalLine;
static inline _s_d78fab0a_pAdapter _d78fab0a_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_d78fab0a_pAdapter){value}; }
static inline _s_d78fab0a_NodeIndex _d78fab0a_NodeIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_d78fab0a_NodeIndex){value}; }
static inline _s_d78fab0a_MemorySegmentGroup _d78fab0a_MemorySegmentGroup(DXGI_MEMORY_SEGMENT_GROUP value) { return REDGPU_NP_STRUCT_INIT(_s_d78fab0a_MemorySegmentGroup){value}; }
static inline _s_d78fab0a_Reservation _d78fab0a_Reservation(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_d78fab0a_Reservation){value}; }
static inline _s_d78fab0a_optionalFile _d78fab0a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d78fab0a_optionalFile){value}; }
static inline _s_d78fab0a_optionalLine _d78fab0a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d78fab0a_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12AdapterSetVideoMemoryReservation(_s_d78fab0a_pAdapter pAdapter, _s_d78fab0a_NodeIndex NodeIndex, _s_d78fab0a_MemorySegmentGroup MemorySegmentGroup, _s_d78fab0a_Reservation Reservation, _s_d78fab0a_optionalFile optionalFile, _s_d78fab0a_optionalLine optionalLine) {
  return x12AdapterSetVideoMemoryReservation(pAdapter.value, NodeIndex.value, MemorySegmentGroup.value, Reservation.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateHeap x12DeviceCreateHeap
#define _f0fe9751_pDevice(value) value
#define _f0fe9751_pDesc(value) value
#define _f0fe9751_outpHeap(value) value
#define _f0fe9751_optionalFile(value) value
#define _f0fe9751_optionalLine(value) value
#else
typedef struct _s_f0fe9751_pDevice { X12Device3* value; } _s_f0fe9751_pDevice;
typedef struct _s_f0fe9751_pDesc { D3D12_HEAP_DESC* value; } _s_f0fe9751_pDesc;
typedef struct _s_f0fe9751_outpHeap { X12Heap** value; } _s_f0fe9751_outpHeap;
typedef struct _s_f0fe9751_optionalFile { char* value; } _s_f0fe9751_optionalFile;
typedef struct _s_f0fe9751_optionalLine { int value; } _s_f0fe9751_optionalLine;
static inline _s_f0fe9751_pDevice _f0fe9751_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_f0fe9751_pDevice){value}; }
static inline _s_f0fe9751_pDesc _f0fe9751_pDesc(D3D12_HEAP_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_f0fe9751_pDesc){value}; }
static inline _s_f0fe9751_outpHeap _f0fe9751_outpHeap(X12Heap** value) { return REDGPU_NP_STRUCT_INIT(_s_f0fe9751_outpHeap){value}; }
static inline _s_f0fe9751_optionalFile _f0fe9751_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f0fe9751_optionalFile){value}; }
static inline _s_f0fe9751_optionalLine _f0fe9751_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f0fe9751_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateHeap(_s_f0fe9751_pDevice pDevice, _s_f0fe9751_pDesc pDesc, _s_f0fe9751_outpHeap outpHeap, _s_f0fe9751_optionalFile optionalFile, _s_f0fe9751_optionalLine optionalLine) {
  return x12DeviceCreateHeap(pDevice.value, pDesc.value, outpHeap.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceGetResourceAllocationInfo x12DeviceGetResourceAllocationInfo
#define _060aada2_pDevice(value) value
#define _060aada2_visibleMask(value) value
#define _060aada2_numResourceDescs(value) value
#define _060aada2_pResourceDescs(value) value
#define _060aada2_outResourceAllocationInfo(value) value
#define _060aada2_optionalFile(value) value
#define _060aada2_optionalLine(value) value
#else
typedef struct _s_060aada2_pDevice { X12Device3* value; } _s_060aada2_pDevice;
typedef struct _s_060aada2_visibleMask { unsigned value; } _s_060aada2_visibleMask;
typedef struct _s_060aada2_numResourceDescs { unsigned value; } _s_060aada2_numResourceDescs;
typedef struct _s_060aada2_pResourceDescs { D3D12_RESOURCE_DESC* value; } _s_060aada2_pResourceDescs;
typedef struct _s_060aada2_outResourceAllocationInfo { D3D12_RESOURCE_ALLOCATION_INFO* value; } _s_060aada2_outResourceAllocationInfo;
typedef struct _s_060aada2_optionalFile { char* value; } _s_060aada2_optionalFile;
typedef struct _s_060aada2_optionalLine { int value; } _s_060aada2_optionalLine;
static inline _s_060aada2_pDevice _060aada2_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_060aada2_pDevice){value}; }
static inline _s_060aada2_visibleMask _060aada2_visibleMask(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_060aada2_visibleMask){value}; }
static inline _s_060aada2_numResourceDescs _060aada2_numResourceDescs(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_060aada2_numResourceDescs){value}; }
static inline _s_060aada2_pResourceDescs _060aada2_pResourceDescs(D3D12_RESOURCE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_060aada2_pResourceDescs){value}; }
static inline _s_060aada2_outResourceAllocationInfo _060aada2_outResourceAllocationInfo(D3D12_RESOURCE_ALLOCATION_INFO* value) { return REDGPU_NP_STRUCT_INIT(_s_060aada2_outResourceAllocationInfo){value}; }
static inline _s_060aada2_optionalFile _060aada2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_060aada2_optionalFile){value}; }
static inline _s_060aada2_optionalLine _060aada2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_060aada2_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceGetResourceAllocationInfo(_s_060aada2_pDevice pDevice, _s_060aada2_visibleMask visibleMask, _s_060aada2_numResourceDescs numResourceDescs, _s_060aada2_pResourceDescs pResourceDescs, _s_060aada2_outResourceAllocationInfo outResourceAllocationInfo, _s_060aada2_optionalFile optionalFile, _s_060aada2_optionalLine optionalLine) {
  x12DeviceGetResourceAllocationInfo(pDevice.value, visibleMask.value, numResourceDescs.value, pResourceDescs.value, outResourceAllocationInfo.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreatePlacedResource x12DeviceCreatePlacedResource
#define _44b05863_pDevice(value) value
#define _44b05863_pHeap(value) value
#define _44b05863_HeapOffset(value) value
#define _44b05863_pDesc(value) value
#define _44b05863_InitialState(value) value
#define _44b05863_pOptimizedClearValue(value) value
#define _44b05863_outpResource(value) value
#define _44b05863_optionalFile(value) value
#define _44b05863_optionalLine(value) value
#else
typedef struct _s_44b05863_pDevice { X12Device3* value; } _s_44b05863_pDevice;
typedef struct _s_44b05863_pHeap { X12Heap* value; } _s_44b05863_pHeap;
typedef struct _s_44b05863_HeapOffset { uint64_t value; } _s_44b05863_HeapOffset;
typedef struct _s_44b05863_pDesc { D3D12_RESOURCE_DESC* value; } _s_44b05863_pDesc;
typedef struct _s_44b05863_InitialState { D3D12_RESOURCE_STATES value; } _s_44b05863_InitialState;
typedef struct _s_44b05863_pOptimizedClearValue { D3D12_CLEAR_VALUE* value; } _s_44b05863_pOptimizedClearValue;
typedef struct _s_44b05863_outpResource { X12Resource** value; } _s_44b05863_outpResource;
typedef struct _s_44b05863_optionalFile { char* value; } _s_44b05863_optionalFile;
typedef struct _s_44b05863_optionalLine { int value; } _s_44b05863_optionalLine;
static inline _s_44b05863_pDevice _44b05863_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_44b05863_pDevice){value}; }
static inline _s_44b05863_pHeap _44b05863_pHeap(X12Heap* value) { return REDGPU_NP_STRUCT_INIT(_s_44b05863_pHeap){value}; }
static inline _s_44b05863_HeapOffset _44b05863_HeapOffset(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_44b05863_HeapOffset){value}; }
static inline _s_44b05863_pDesc _44b05863_pDesc(D3D12_RESOURCE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_44b05863_pDesc){value}; }
static inline _s_44b05863_InitialState _44b05863_InitialState(D3D12_RESOURCE_STATES value) { return REDGPU_NP_STRUCT_INIT(_s_44b05863_InitialState){value}; }
static inline _s_44b05863_pOptimizedClearValue _44b05863_pOptimizedClearValue(D3D12_CLEAR_VALUE* value) { return REDGPU_NP_STRUCT_INIT(_s_44b05863_pOptimizedClearValue){value}; }
static inline _s_44b05863_outpResource _44b05863_outpResource(X12Resource** value) { return REDGPU_NP_STRUCT_INIT(_s_44b05863_outpResource){value}; }
static inline _s_44b05863_optionalFile _44b05863_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_44b05863_optionalFile){value}; }
static inline _s_44b05863_optionalLine _44b05863_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_44b05863_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreatePlacedResource(_s_44b05863_pDevice pDevice, _s_44b05863_pHeap pHeap, _s_44b05863_HeapOffset HeapOffset, _s_44b05863_pDesc pDesc, _s_44b05863_InitialState InitialState, _s_44b05863_pOptimizedClearValue pOptimizedClearValue, _s_44b05863_outpResource outpResource, _s_44b05863_optionalFile optionalFile, _s_44b05863_optionalLine optionalLine) {
  return x12DeviceCreatePlacedResource(pDevice.value, pHeap.value, HeapOffset.value, pDesc.value, InitialState.value, pOptimizedClearValue.value, outpResource.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateCommittedResource x12DeviceCreateCommittedResource
#define _0f2aa25a_pDevice(value) value
#define _0f2aa25a_pHeapProperties(value) value
#define _0f2aa25a_HeapFlags(value) value
#define _0f2aa25a_pDesc(value) value
#define _0f2aa25a_InitialResourceState(value) value
#define _0f2aa25a_pOptimizedClearValue(value) value
#define _0f2aa25a_outpResource(value) value
#define _0f2aa25a_optionalFile(value) value
#define _0f2aa25a_optionalLine(value) value
#else
typedef struct _s_0f2aa25a_pDevice { X12Device3* value; } _s_0f2aa25a_pDevice;
typedef struct _s_0f2aa25a_pHeapProperties { D3D12_HEAP_PROPERTIES* value; } _s_0f2aa25a_pHeapProperties;
typedef struct _s_0f2aa25a_HeapFlags { D3D12_HEAP_FLAGS value; } _s_0f2aa25a_HeapFlags;
typedef struct _s_0f2aa25a_pDesc { D3D12_RESOURCE_DESC* value; } _s_0f2aa25a_pDesc;
typedef struct _s_0f2aa25a_InitialResourceState { D3D12_RESOURCE_STATES value; } _s_0f2aa25a_InitialResourceState;
typedef struct _s_0f2aa25a_pOptimizedClearValue { D3D12_CLEAR_VALUE* value; } _s_0f2aa25a_pOptimizedClearValue;
typedef struct _s_0f2aa25a_outpResource { X12Resource** value; } _s_0f2aa25a_outpResource;
typedef struct _s_0f2aa25a_optionalFile { char* value; } _s_0f2aa25a_optionalFile;
typedef struct _s_0f2aa25a_optionalLine { int value; } _s_0f2aa25a_optionalLine;
static inline _s_0f2aa25a_pDevice _0f2aa25a_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_0f2aa25a_pDevice){value}; }
static inline _s_0f2aa25a_pHeapProperties _0f2aa25a_pHeapProperties(D3D12_HEAP_PROPERTIES* value) { return REDGPU_NP_STRUCT_INIT(_s_0f2aa25a_pHeapProperties){value}; }
static inline _s_0f2aa25a_HeapFlags _0f2aa25a_HeapFlags(D3D12_HEAP_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_0f2aa25a_HeapFlags){value}; }
static inline _s_0f2aa25a_pDesc _0f2aa25a_pDesc(D3D12_RESOURCE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_0f2aa25a_pDesc){value}; }
static inline _s_0f2aa25a_InitialResourceState _0f2aa25a_InitialResourceState(D3D12_RESOURCE_STATES value) { return REDGPU_NP_STRUCT_INIT(_s_0f2aa25a_InitialResourceState){value}; }
static inline _s_0f2aa25a_pOptimizedClearValue _0f2aa25a_pOptimizedClearValue(D3D12_CLEAR_VALUE* value) { return REDGPU_NP_STRUCT_INIT(_s_0f2aa25a_pOptimizedClearValue){value}; }
static inline _s_0f2aa25a_outpResource _0f2aa25a_outpResource(X12Resource** value) { return REDGPU_NP_STRUCT_INIT(_s_0f2aa25a_outpResource){value}; }
static inline _s_0f2aa25a_optionalFile _0f2aa25a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0f2aa25a_optionalFile){value}; }
static inline _s_0f2aa25a_optionalLine _0f2aa25a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0f2aa25a_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateCommittedResource(_s_0f2aa25a_pDevice pDevice, _s_0f2aa25a_pHeapProperties pHeapProperties, _s_0f2aa25a_HeapFlags HeapFlags, _s_0f2aa25a_pDesc pDesc, _s_0f2aa25a_InitialResourceState InitialResourceState, _s_0f2aa25a_pOptimizedClearValue pOptimizedClearValue, _s_0f2aa25a_outpResource outpResource, _s_0f2aa25a_optionalFile optionalFile, _s_0f2aa25a_optionalLine optionalLine) {
  return x12DeviceCreateCommittedResource(pDevice.value, pHeapProperties.value, HeapFlags.value, pDesc.value, InitialResourceState.value, pOptimizedClearValue.value, outpResource.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12ResourceMap x12ResourceMap
#define _348cbddc_pResource(value) value
#define _348cbddc_Subresource(value) value
#define _348cbddc_pReadRange(value) value
#define _348cbddc_outpData(value) value
#define _348cbddc_optionalFile(value) value
#define _348cbddc_optionalLine(value) value
#else
typedef struct _s_348cbddc_pResource { X12Resource* value; } _s_348cbddc_pResource;
typedef struct _s_348cbddc_Subresource { unsigned value; } _s_348cbddc_Subresource;
typedef struct _s_348cbddc_pReadRange { D3D12_RANGE* value; } _s_348cbddc_pReadRange;
typedef struct _s_348cbddc_outpData { void** value; } _s_348cbddc_outpData;
typedef struct _s_348cbddc_optionalFile { char* value; } _s_348cbddc_optionalFile;
typedef struct _s_348cbddc_optionalLine { int value; } _s_348cbddc_optionalLine;
static inline _s_348cbddc_pResource _348cbddc_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_348cbddc_pResource){value}; }
static inline _s_348cbddc_Subresource _348cbddc_Subresource(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_348cbddc_Subresource){value}; }
static inline _s_348cbddc_pReadRange _348cbddc_pReadRange(D3D12_RANGE* value) { return REDGPU_NP_STRUCT_INIT(_s_348cbddc_pReadRange){value}; }
static inline _s_348cbddc_outpData _348cbddc_outpData(void** value) { return REDGPU_NP_STRUCT_INIT(_s_348cbddc_outpData){value}; }
static inline _s_348cbddc_optionalFile _348cbddc_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_348cbddc_optionalFile){value}; }
static inline _s_348cbddc_optionalLine _348cbddc_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_348cbddc_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12ResourceMap(_s_348cbddc_pResource pResource, _s_348cbddc_Subresource Subresource, _s_348cbddc_pReadRange pReadRange, _s_348cbddc_outpData outpData, _s_348cbddc_optionalFile optionalFile, _s_348cbddc_optionalLine optionalLine) {
  return x12ResourceMap(pResource.value, Subresource.value, pReadRange.value, outpData.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12ResourceUnmap x12ResourceUnmap
#define _3d6ea00f_pResource(value) value
#define _3d6ea00f_Subresource(value) value
#define _3d6ea00f_pWrittenRange(value) value
#define _3d6ea00f_optionalFile(value) value
#define _3d6ea00f_optionalLine(value) value
#else
typedef struct _s_3d6ea00f_pResource { X12Resource* value; } _s_3d6ea00f_pResource;
typedef struct _s_3d6ea00f_Subresource { unsigned value; } _s_3d6ea00f_Subresource;
typedef struct _s_3d6ea00f_pWrittenRange { D3D12_RANGE* value; } _s_3d6ea00f_pWrittenRange;
typedef struct _s_3d6ea00f_optionalFile { char* value; } _s_3d6ea00f_optionalFile;
typedef struct _s_3d6ea00f_optionalLine { int value; } _s_3d6ea00f_optionalLine;
static inline _s_3d6ea00f_pResource _3d6ea00f_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_3d6ea00f_pResource){value}; }
static inline _s_3d6ea00f_Subresource _3d6ea00f_Subresource(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3d6ea00f_Subresource){value}; }
static inline _s_3d6ea00f_pWrittenRange _3d6ea00f_pWrittenRange(D3D12_RANGE* value) { return REDGPU_NP_STRUCT_INIT(_s_3d6ea00f_pWrittenRange){value}; }
static inline _s_3d6ea00f_optionalFile _3d6ea00f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3d6ea00f_optionalFile){value}; }
static inline _s_3d6ea00f_optionalLine _3d6ea00f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3d6ea00f_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12ResourceUnmap(_s_3d6ea00f_pResource pResource, _s_3d6ea00f_Subresource Subresource, _s_3d6ea00f_pWrittenRange pWrittenRange, _s_3d6ea00f_optionalFile optionalFile, _s_3d6ea00f_optionalLine optionalLine) {
  x12ResourceUnmap(pResource.value, Subresource.value, pWrittenRange.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateDescriptorHeap x12DeviceCreateDescriptorHeap
#define _5cfa45d4_pDevice(value) value
#define _5cfa45d4_pDescriptorHeapDesc(value) value
#define _5cfa45d4_outpHeap(value) value
#define _5cfa45d4_optionalFile(value) value
#define _5cfa45d4_optionalLine(value) value
#else
typedef struct _s_5cfa45d4_pDevice { X12Device3* value; } _s_5cfa45d4_pDevice;
typedef struct _s_5cfa45d4_pDescriptorHeapDesc { D3D12_DESCRIPTOR_HEAP_DESC* value; } _s_5cfa45d4_pDescriptorHeapDesc;
typedef struct _s_5cfa45d4_outpHeap { X12DescriptorHeap** value; } _s_5cfa45d4_outpHeap;
typedef struct _s_5cfa45d4_optionalFile { char* value; } _s_5cfa45d4_optionalFile;
typedef struct _s_5cfa45d4_optionalLine { int value; } _s_5cfa45d4_optionalLine;
static inline _s_5cfa45d4_pDevice _5cfa45d4_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_5cfa45d4_pDevice){value}; }
static inline _s_5cfa45d4_pDescriptorHeapDesc _5cfa45d4_pDescriptorHeapDesc(D3D12_DESCRIPTOR_HEAP_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_5cfa45d4_pDescriptorHeapDesc){value}; }
static inline _s_5cfa45d4_outpHeap _5cfa45d4_outpHeap(X12DescriptorHeap** value) { return REDGPU_NP_STRUCT_INIT(_s_5cfa45d4_outpHeap){value}; }
static inline _s_5cfa45d4_optionalFile _5cfa45d4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5cfa45d4_optionalFile){value}; }
static inline _s_5cfa45d4_optionalLine _5cfa45d4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5cfa45d4_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateDescriptorHeap(_s_5cfa45d4_pDevice pDevice, _s_5cfa45d4_pDescriptorHeapDesc pDescriptorHeapDesc, _s_5cfa45d4_outpHeap outpHeap, _s_5cfa45d4_optionalFile optionalFile, _s_5cfa45d4_optionalLine optionalLine) {
  return x12DeviceCreateDescriptorHeap(pDevice.value, pDescriptorHeapDesc.value, outpHeap.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DescriptorHeapGetCPUDescriptorHandleForHeapStart x12DescriptorHeapGetCPUDescriptorHandleForHeapStart
#define _40ff2495_pDescriptorHeap(value) value
#define _40ff2495_pCpuDescriptorHandle(value) value
#else
typedef struct _s_40ff2495_pDescriptorHeap { X12DescriptorHeap* value; } _s_40ff2495_pDescriptorHeap;
typedef struct _s_40ff2495_pCpuDescriptorHandle { D3D12_CPU_DESCRIPTOR_HANDLE* value; } _s_40ff2495_pCpuDescriptorHandle;
static inline _s_40ff2495_pDescriptorHeap _40ff2495_pDescriptorHeap(X12DescriptorHeap* value) { return REDGPU_NP_STRUCT_INIT(_s_40ff2495_pDescriptorHeap){value}; }
static inline _s_40ff2495_pCpuDescriptorHandle _40ff2495_pCpuDescriptorHandle(D3D12_CPU_DESCRIPTOR_HANDLE* value) { return REDGPU_NP_STRUCT_INIT(_s_40ff2495_pCpuDescriptorHandle){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(_s_40ff2495_pDescriptorHeap pDescriptorHeap, _s_40ff2495_pCpuDescriptorHandle pCpuDescriptorHandle) {
  x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(pDescriptorHeap.value, pCpuDescriptorHandle.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCopyDescriptors x12DeviceCopyDescriptors
#define _8123fff2_pDevice(value) value
#define _8123fff2_NumDestDescriptorRanges(value) value
#define _8123fff2_pDestDescriptorRangeStarts(value) value
#define _8123fff2_pDestDescriptorRangeSizes(value) value
#define _8123fff2_NumSrcDescriptorRanges(value) value
#define _8123fff2_pSrcDescriptorRangeStarts(value) value
#define _8123fff2_pSrcDescriptorRangeSizes(value) value
#define _8123fff2_DescriptorHeapsType(value) value
#define _8123fff2_optionalFile(value) value
#define _8123fff2_optionalLine(value) value
#else
typedef struct _s_8123fff2_pDevice { X12Device3* value; } _s_8123fff2_pDevice;
typedef struct _s_8123fff2_NumDestDescriptorRanges { unsigned value; } _s_8123fff2_NumDestDescriptorRanges;
typedef struct _s_8123fff2_pDestDescriptorRangeStarts { D3D12_CPU_DESCRIPTOR_HANDLE* value; } _s_8123fff2_pDestDescriptorRangeStarts;
typedef struct _s_8123fff2_pDestDescriptorRangeSizes { unsigned* value; } _s_8123fff2_pDestDescriptorRangeSizes;
typedef struct _s_8123fff2_NumSrcDescriptorRanges { unsigned value; } _s_8123fff2_NumSrcDescriptorRanges;
typedef struct _s_8123fff2_pSrcDescriptorRangeStarts { D3D12_CPU_DESCRIPTOR_HANDLE* value; } _s_8123fff2_pSrcDescriptorRangeStarts;
typedef struct _s_8123fff2_pSrcDescriptorRangeSizes { unsigned* value; } _s_8123fff2_pSrcDescriptorRangeSizes;
typedef struct _s_8123fff2_DescriptorHeapsType { D3D12_DESCRIPTOR_HEAP_TYPE value; } _s_8123fff2_DescriptorHeapsType;
typedef struct _s_8123fff2_optionalFile { char* value; } _s_8123fff2_optionalFile;
typedef struct _s_8123fff2_optionalLine { int value; } _s_8123fff2_optionalLine;
static inline _s_8123fff2_pDevice _8123fff2_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_8123fff2_pDevice){value}; }
static inline _s_8123fff2_NumDestDescriptorRanges _8123fff2_NumDestDescriptorRanges(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8123fff2_NumDestDescriptorRanges){value}; }
static inline _s_8123fff2_pDestDescriptorRangeStarts _8123fff2_pDestDescriptorRangeStarts(D3D12_CPU_DESCRIPTOR_HANDLE* value) { return REDGPU_NP_STRUCT_INIT(_s_8123fff2_pDestDescriptorRangeStarts){value}; }
static inline _s_8123fff2_pDestDescriptorRangeSizes _8123fff2_pDestDescriptorRangeSizes(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_8123fff2_pDestDescriptorRangeSizes){value}; }
static inline _s_8123fff2_NumSrcDescriptorRanges _8123fff2_NumSrcDescriptorRanges(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8123fff2_NumSrcDescriptorRanges){value}; }
static inline _s_8123fff2_pSrcDescriptorRangeStarts _8123fff2_pSrcDescriptorRangeStarts(D3D12_CPU_DESCRIPTOR_HANDLE* value) { return REDGPU_NP_STRUCT_INIT(_s_8123fff2_pSrcDescriptorRangeStarts){value}; }
static inline _s_8123fff2_pSrcDescriptorRangeSizes _8123fff2_pSrcDescriptorRangeSizes(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_8123fff2_pSrcDescriptorRangeSizes){value}; }
static inline _s_8123fff2_DescriptorHeapsType _8123fff2_DescriptorHeapsType(D3D12_DESCRIPTOR_HEAP_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_8123fff2_DescriptorHeapsType){value}; }
static inline _s_8123fff2_optionalFile _8123fff2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8123fff2_optionalFile){value}; }
static inline _s_8123fff2_optionalLine _8123fff2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8123fff2_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCopyDescriptors(_s_8123fff2_pDevice pDevice, _s_8123fff2_NumDestDescriptorRanges NumDestDescriptorRanges, _s_8123fff2_pDestDescriptorRangeStarts pDestDescriptorRangeStarts, _s_8123fff2_pDestDescriptorRangeSizes pDestDescriptorRangeSizes, _s_8123fff2_NumSrcDescriptorRanges NumSrcDescriptorRanges, _s_8123fff2_pSrcDescriptorRangeStarts pSrcDescriptorRangeStarts, _s_8123fff2_pSrcDescriptorRangeSizes pSrcDescriptorRangeSizes, _s_8123fff2_DescriptorHeapsType DescriptorHeapsType, _s_8123fff2_optionalFile optionalFile, _s_8123fff2_optionalLine optionalLine) {
  x12DeviceCopyDescriptors(pDevice.value, NumDestDescriptorRanges.value, pDestDescriptorRangeStarts.value, pDestDescriptorRangeSizes.value, NumSrcDescriptorRanges.value, pSrcDescriptorRangeStarts.value, pSrcDescriptorRangeSizes.value, DescriptorHeapsType.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DescriptorHeapGetGPUDescriptorHandleForHeapStart x12DescriptorHeapGetGPUDescriptorHandleForHeapStart
#define _d607616b_pDescriptorHeap(value) value
#define _d607616b_pGpuDescriptorHandle(value) value
#else
typedef struct _s_d607616b_pDescriptorHeap { X12DescriptorHeap* value; } _s_d607616b_pDescriptorHeap;
typedef struct _s_d607616b_pGpuDescriptorHandle { D3D12_GPU_DESCRIPTOR_HANDLE* value; } _s_d607616b_pGpuDescriptorHandle;
static inline _s_d607616b_pDescriptorHeap _d607616b_pDescriptorHeap(X12DescriptorHeap* value) { return REDGPU_NP_STRUCT_INIT(_s_d607616b_pDescriptorHeap){value}; }
static inline _s_d607616b_pGpuDescriptorHandle _d607616b_pGpuDescriptorHandle(D3D12_GPU_DESCRIPTOR_HANDLE* value) { return REDGPU_NP_STRUCT_INIT(_s_d607616b_pGpuDescriptorHandle){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DescriptorHeapGetGPUDescriptorHandleForHeapStart(_s_d607616b_pDescriptorHeap pDescriptorHeap, _s_d607616b_pGpuDescriptorHandle pGpuDescriptorHandle) {
  x12DescriptorHeapGetGPUDescriptorHandleForHeapStart(pDescriptorHeap.value, pGpuDescriptorHandle.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceSetResidencyPriority x12DeviceSetResidencyPriority
#define _d561b36f_pDevice(value) value
#define _d561b36f_NumObjects(value) value
#define _d561b36f_ppObjects(value) value
#define _d561b36f_pPriorities(value) value
#define _d561b36f_optionalFile(value) value
#define _d561b36f_optionalLine(value) value
#else
typedef struct _s_d561b36f_pDevice { X12Device3* value; } _s_d561b36f_pDevice;
typedef struct _s_d561b36f_NumObjects { unsigned value; } _s_d561b36f_NumObjects;
typedef struct _s_d561b36f_ppObjects { X12Pageable** value; } _s_d561b36f_ppObjects;
typedef struct _s_d561b36f_pPriorities { unsigned* value; } _s_d561b36f_pPriorities;
typedef struct _s_d561b36f_optionalFile { char* value; } _s_d561b36f_optionalFile;
typedef struct _s_d561b36f_optionalLine { int value; } _s_d561b36f_optionalLine;
static inline _s_d561b36f_pDevice _d561b36f_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_d561b36f_pDevice){value}; }
static inline _s_d561b36f_NumObjects _d561b36f_NumObjects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_d561b36f_NumObjects){value}; }
static inline _s_d561b36f_ppObjects _d561b36f_ppObjects(X12Pageable** value) { return REDGPU_NP_STRUCT_INIT(_s_d561b36f_ppObjects){value}; }
static inline _s_d561b36f_pPriorities _d561b36f_pPriorities(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_d561b36f_pPriorities){value}; }
static inline _s_d561b36f_optionalFile _d561b36f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d561b36f_optionalFile){value}; }
static inline _s_d561b36f_optionalLine _d561b36f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d561b36f_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceSetResidencyPriority(_s_d561b36f_pDevice pDevice, _s_d561b36f_NumObjects NumObjects, _s_d561b36f_ppObjects ppObjects, _s_d561b36f_pPriorities pPriorities, _s_d561b36f_optionalFile optionalFile, _s_d561b36f_optionalLine optionalLine) {
  return x12DeviceSetResidencyPriority(pDevice.value, NumObjects.value, ppObjects.value, pPriorities.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceEvict x12DeviceEvict
#define _35e697b1_pDevice(value) value
#define _35e697b1_NumObjects(value) value
#define _35e697b1_ppObjects(value) value
#define _35e697b1_optionalFile(value) value
#define _35e697b1_optionalLine(value) value
#else
typedef struct _s_35e697b1_pDevice { X12Device3* value; } _s_35e697b1_pDevice;
typedef struct _s_35e697b1_NumObjects { unsigned value; } _s_35e697b1_NumObjects;
typedef struct _s_35e697b1_ppObjects { X12Pageable** value; } _s_35e697b1_ppObjects;
typedef struct _s_35e697b1_optionalFile { char* value; } _s_35e697b1_optionalFile;
typedef struct _s_35e697b1_optionalLine { int value; } _s_35e697b1_optionalLine;
static inline _s_35e697b1_pDevice _35e697b1_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_35e697b1_pDevice){value}; }
static inline _s_35e697b1_NumObjects _35e697b1_NumObjects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_35e697b1_NumObjects){value}; }
static inline _s_35e697b1_ppObjects _35e697b1_ppObjects(X12Pageable** value) { return REDGPU_NP_STRUCT_INIT(_s_35e697b1_ppObjects){value}; }
static inline _s_35e697b1_optionalFile _35e697b1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_35e697b1_optionalFile){value}; }
static inline _s_35e697b1_optionalLine _35e697b1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_35e697b1_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceEvict(_s_35e697b1_pDevice pDevice, _s_35e697b1_NumObjects NumObjects, _s_35e697b1_ppObjects ppObjects, _s_35e697b1_optionalFile optionalFile, _s_35e697b1_optionalLine optionalLine) {
  return x12DeviceEvict(pDevice.value, NumObjects.value, ppObjects.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceMakeResident x12DeviceMakeResident
#define _9d48d4aa_pDevice(value) value
#define _9d48d4aa_NumObjects(value) value
#define _9d48d4aa_ppObjects(value) value
#define _9d48d4aa_optionalFile(value) value
#define _9d48d4aa_optionalLine(value) value
#else
typedef struct _s_9d48d4aa_pDevice { X12Device3* value; } _s_9d48d4aa_pDevice;
typedef struct _s_9d48d4aa_NumObjects { unsigned value; } _s_9d48d4aa_NumObjects;
typedef struct _s_9d48d4aa_ppObjects { X12Pageable** value; } _s_9d48d4aa_ppObjects;
typedef struct _s_9d48d4aa_optionalFile { char* value; } _s_9d48d4aa_optionalFile;
typedef struct _s_9d48d4aa_optionalLine { int value; } _s_9d48d4aa_optionalLine;
static inline _s_9d48d4aa_pDevice _9d48d4aa_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_9d48d4aa_pDevice){value}; }
static inline _s_9d48d4aa_NumObjects _9d48d4aa_NumObjects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9d48d4aa_NumObjects){value}; }
static inline _s_9d48d4aa_ppObjects _9d48d4aa_ppObjects(X12Pageable** value) { return REDGPU_NP_STRUCT_INIT(_s_9d48d4aa_ppObjects){value}; }
static inline _s_9d48d4aa_optionalFile _9d48d4aa_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9d48d4aa_optionalFile){value}; }
static inline _s_9d48d4aa_optionalLine _9d48d4aa_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9d48d4aa_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceMakeResident(_s_9d48d4aa_pDevice pDevice, _s_9d48d4aa_NumObjects NumObjects, _s_9d48d4aa_ppObjects ppObjects, _s_9d48d4aa_optionalFile optionalFile, _s_9d48d4aa_optionalLine optionalLine) {
  return x12DeviceMakeResident(pDevice.value, NumObjects.value, ppObjects.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceEnqueueMakeResident x12DeviceEnqueueMakeResident
#define _ab10c8c9_pDevice(value) value
#define _ab10c8c9_Flags(value) value
#define _ab10c8c9_NumObjects(value) value
#define _ab10c8c9_ppObjects(value) value
#define _ab10c8c9_pFenceToSignal(value) value
#define _ab10c8c9_FenceValueToSignal(value) value
#define _ab10c8c9_optionalFile(value) value
#define _ab10c8c9_optionalLine(value) value
#else
typedef struct _s_ab10c8c9_pDevice { X12Device3* value; } _s_ab10c8c9_pDevice;
typedef struct _s_ab10c8c9_Flags { D3D12_RESIDENCY_FLAGS value; } _s_ab10c8c9_Flags;
typedef struct _s_ab10c8c9_NumObjects { unsigned value; } _s_ab10c8c9_NumObjects;
typedef struct _s_ab10c8c9_ppObjects { X12Pageable** value; } _s_ab10c8c9_ppObjects;
typedef struct _s_ab10c8c9_pFenceToSignal { X12Fence* value; } _s_ab10c8c9_pFenceToSignal;
typedef struct _s_ab10c8c9_FenceValueToSignal { uint64_t value; } _s_ab10c8c9_FenceValueToSignal;
typedef struct _s_ab10c8c9_optionalFile { char* value; } _s_ab10c8c9_optionalFile;
typedef struct _s_ab10c8c9_optionalLine { int value; } _s_ab10c8c9_optionalLine;
static inline _s_ab10c8c9_pDevice _ab10c8c9_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_ab10c8c9_pDevice){value}; }
static inline _s_ab10c8c9_Flags _ab10c8c9_Flags(D3D12_RESIDENCY_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_ab10c8c9_Flags){value}; }
static inline _s_ab10c8c9_NumObjects _ab10c8c9_NumObjects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ab10c8c9_NumObjects){value}; }
static inline _s_ab10c8c9_ppObjects _ab10c8c9_ppObjects(X12Pageable** value) { return REDGPU_NP_STRUCT_INIT(_s_ab10c8c9_ppObjects){value}; }
static inline _s_ab10c8c9_pFenceToSignal _ab10c8c9_pFenceToSignal(X12Fence* value) { return REDGPU_NP_STRUCT_INIT(_s_ab10c8c9_pFenceToSignal){value}; }
static inline _s_ab10c8c9_FenceValueToSignal _ab10c8c9_FenceValueToSignal(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_ab10c8c9_FenceValueToSignal){value}; }
static inline _s_ab10c8c9_optionalFile _ab10c8c9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ab10c8c9_optionalFile){value}; }
static inline _s_ab10c8c9_optionalLine _ab10c8c9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ab10c8c9_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceEnqueueMakeResident(_s_ab10c8c9_pDevice pDevice, _s_ab10c8c9_Flags Flags, _s_ab10c8c9_NumObjects NumObjects, _s_ab10c8c9_ppObjects ppObjects, _s_ab10c8c9_pFenceToSignal pFenceToSignal, _s_ab10c8c9_FenceValueToSignal FenceValueToSignal, _s_ab10c8c9_optionalFile optionalFile, _s_ab10c8c9_optionalLine optionalLine) {
  return x12DeviceEnqueueMakeResident(pDevice.value, Flags.value, NumObjects.value, ppObjects.value, pFenceToSignal.value, FenceValueToSignal.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DebugEnable x12DebugEnable
#define _d2a85089_optionalFile(value) value
#define _d2a85089_optionalLine(value) value
#else
typedef struct _s_d2a85089_optionalFile { char* value; } _s_d2a85089_optionalFile;
typedef struct _s_d2a85089_optionalLine { int value; } _s_d2a85089_optionalLine;
static inline _s_d2a85089_optionalFile _d2a85089_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d2a85089_optionalFile){value}; }
static inline _s_d2a85089_optionalLine _d2a85089_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d2a85089_optionalLine){value}; }
REDGPU_NP_DECLSPEC void* REDGPU_NP_API np_x12DebugEnable(_s_d2a85089_optionalFile optionalFile, _s_d2a85089_optionalLine optionalLine) {
  return x12DebugEnable(optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DebugReport x12DebugReport
#define _56feeaf7_debugContext(value) value
#define _56feeaf7_optionalFile(value) value
#define _56feeaf7_optionalLine(value) value
#else
typedef struct _s_56feeaf7_debugContext { void* value; } _s_56feeaf7_debugContext;
typedef struct _s_56feeaf7_optionalFile { char* value; } _s_56feeaf7_optionalFile;
typedef struct _s_56feeaf7_optionalLine { int value; } _s_56feeaf7_optionalLine;
static inline _s_56feeaf7_debugContext _56feeaf7_debugContext(void* value) { return REDGPU_NP_STRUCT_INIT(_s_56feeaf7_debugContext){value}; }
static inline _s_56feeaf7_optionalFile _56feeaf7_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_56feeaf7_optionalFile){value}; }
static inline _s_56feeaf7_optionalLine _56feeaf7_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_56feeaf7_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DebugReport(_s_56feeaf7_debugContext debugContext, _s_56feeaf7_optionalFile optionalFile, _s_56feeaf7_optionalLine optionalLine) {
  x12DebugReport(debugContext.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CreateFactory2 x12CreateFactory2
#define _84f589f2_Flags(value) value
#define _84f589f2_outpFactory(value) value
#define _84f589f2_optionalFile(value) value
#define _84f589f2_optionalLine(value) value
#else
typedef struct _s_84f589f2_Flags { DXGI_CREATE_FACTORY_FLAGS value; } _s_84f589f2_Flags;
typedef struct _s_84f589f2_outpFactory { X12Factory4** value; } _s_84f589f2_outpFactory;
typedef struct _s_84f589f2_optionalFile { char* value; } _s_84f589f2_optionalFile;
typedef struct _s_84f589f2_optionalLine { int value; } _s_84f589f2_optionalLine;
static inline _s_84f589f2_Flags _84f589f2_Flags(DXGI_CREATE_FACTORY_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_84f589f2_Flags){value}; }
static inline _s_84f589f2_outpFactory _84f589f2_outpFactory(X12Factory4** value) { return REDGPU_NP_STRUCT_INIT(_s_84f589f2_outpFactory){value}; }
static inline _s_84f589f2_optionalFile _84f589f2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_84f589f2_optionalFile){value}; }
static inline _s_84f589f2_optionalLine _84f589f2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_84f589f2_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CreateFactory2(_s_84f589f2_Flags Flags, _s_84f589f2_outpFactory outpFactory, _s_84f589f2_optionalFile optionalFile, _s_84f589f2_optionalLine optionalLine) {
  return x12CreateFactory2(Flags.value, outpFactory.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryEnumAdapters1 x12FactoryEnumAdapters1
#define _40208e96_pFactory(value) value
#define _40208e96_Adapter(value) value
#define _40208e96_outpAdapter(value) value
#define _40208e96_optionalFile(value) value
#define _40208e96_optionalLine(value) value
#else
typedef struct _s_40208e96_pFactory { X12Factory4* value; } _s_40208e96_pFactory;
typedef struct _s_40208e96_Adapter { unsigned value; } _s_40208e96_Adapter;
typedef struct _s_40208e96_outpAdapter { X12Adapter3** value; } _s_40208e96_outpAdapter;
typedef struct _s_40208e96_optionalFile { char* value; } _s_40208e96_optionalFile;
typedef struct _s_40208e96_optionalLine { int value; } _s_40208e96_optionalLine;
static inline _s_40208e96_pFactory _40208e96_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_40208e96_pFactory){value}; }
static inline _s_40208e96_Adapter _40208e96_Adapter(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_40208e96_Adapter){value}; }
static inline _s_40208e96_outpAdapter _40208e96_outpAdapter(X12Adapter3** value) { return REDGPU_NP_STRUCT_INIT(_s_40208e96_outpAdapter){value}; }
static inline _s_40208e96_optionalFile _40208e96_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_40208e96_optionalFile){value}; }
static inline _s_40208e96_optionalLine _40208e96_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_40208e96_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryEnumAdapters1(_s_40208e96_pFactory pFactory, _s_40208e96_Adapter Adapter, _s_40208e96_outpAdapter outpAdapter, _s_40208e96_optionalFile optionalFile, _s_40208e96_optionalLine optionalLine) {
  return x12FactoryEnumAdapters1(pFactory.value, Adapter.value, outpAdapter.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CreateDevice x12CreateDevice
#define _04e646fa_pAdapter(value) value
#define _04e646fa_MinimumFeatureLevel(value) value
#define _04e646fa_outpDevice(value) value
#define _04e646fa_optionalFile(value) value
#define _04e646fa_optionalLine(value) value
#else
typedef struct _s_04e646fa_pAdapter { X12Adapter3* value; } _s_04e646fa_pAdapter;
typedef struct _s_04e646fa_MinimumFeatureLevel { D3D_FEATURE_LEVEL value; } _s_04e646fa_MinimumFeatureLevel;
typedef struct _s_04e646fa_outpDevice { X12Device3** value; } _s_04e646fa_outpDevice;
typedef struct _s_04e646fa_optionalFile { char* value; } _s_04e646fa_optionalFile;
typedef struct _s_04e646fa_optionalLine { int value; } _s_04e646fa_optionalLine;
static inline _s_04e646fa_pAdapter _04e646fa_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_04e646fa_pAdapter){value}; }
static inline _s_04e646fa_MinimumFeatureLevel _04e646fa_MinimumFeatureLevel(D3D_FEATURE_LEVEL value) { return REDGPU_NP_STRUCT_INIT(_s_04e646fa_MinimumFeatureLevel){value}; }
static inline _s_04e646fa_outpDevice _04e646fa_outpDevice(X12Device3** value) { return REDGPU_NP_STRUCT_INIT(_s_04e646fa_outpDevice){value}; }
static inline _s_04e646fa_optionalFile _04e646fa_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_04e646fa_optionalFile){value}; }
static inline _s_04e646fa_optionalLine _04e646fa_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_04e646fa_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CreateDevice(_s_04e646fa_pAdapter pAdapter, _s_04e646fa_MinimumFeatureLevel MinimumFeatureLevel, _s_04e646fa_outpDevice outpDevice, _s_04e646fa_optionalFile optionalFile, _s_04e646fa_optionalLine optionalLine) {
  return x12CreateDevice(pAdapter.value, MinimumFeatureLevel.value, outpDevice.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateUnorderedAccessView x12DeviceCreateUnorderedAccessView
#define _de8b8820_pDevice(value) value
#define _de8b8820_pResource(value) value
#define _de8b8820_pCounterResource(value) value
#define _de8b8820_pDesc(value) value
#define _de8b8820_DestDescriptor(value) value
#define _de8b8820_optionalFile(value) value
#define _de8b8820_optionalLine(value) value
#else
typedef struct _s_de8b8820_pDevice { X12Device3* value; } _s_de8b8820_pDevice;
typedef struct _s_de8b8820_pResource { X12Resource* value; } _s_de8b8820_pResource;
typedef struct _s_de8b8820_pCounterResource { X12Resource* value; } _s_de8b8820_pCounterResource;
typedef struct _s_de8b8820_pDesc { D3D12_UNORDERED_ACCESS_VIEW_DESC* value; } _s_de8b8820_pDesc;
typedef struct _s_de8b8820_DestDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_de8b8820_DestDescriptor;
typedef struct _s_de8b8820_optionalFile { char* value; } _s_de8b8820_optionalFile;
typedef struct _s_de8b8820_optionalLine { int value; } _s_de8b8820_optionalLine;
static inline _s_de8b8820_pDevice _de8b8820_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_de8b8820_pDevice){value}; }
static inline _s_de8b8820_pResource _de8b8820_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_de8b8820_pResource){value}; }
static inline _s_de8b8820_pCounterResource _de8b8820_pCounterResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_de8b8820_pCounterResource){value}; }
static inline _s_de8b8820_pDesc _de8b8820_pDesc(D3D12_UNORDERED_ACCESS_VIEW_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_de8b8820_pDesc){value}; }
static inline _s_de8b8820_DestDescriptor _de8b8820_DestDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_de8b8820_DestDescriptor){value}; }
static inline _s_de8b8820_optionalFile _de8b8820_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_de8b8820_optionalFile){value}; }
static inline _s_de8b8820_optionalLine _de8b8820_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_de8b8820_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCreateUnorderedAccessView(_s_de8b8820_pDevice pDevice, _s_de8b8820_pResource pResource, _s_de8b8820_pCounterResource pCounterResource, _s_de8b8820_pDesc pDesc, _s_de8b8820_DestDescriptor DestDescriptor, _s_de8b8820_optionalFile optionalFile, _s_de8b8820_optionalLine optionalLine) {
  x12DeviceCreateUnorderedAccessView(pDevice.value, pResource.value, pCounterResource.value, pDesc.value, DestDescriptor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateShaderResourceView x12DeviceCreateShaderResourceView
#define _c154a46f_pDevice(value) value
#define _c154a46f_pResource(value) value
#define _c154a46f_pDesc(value) value
#define _c154a46f_DestDescriptor(value) value
#define _c154a46f_optionalFile(value) value
#define _c154a46f_optionalLine(value) value
#else
typedef struct _s_c154a46f_pDevice { X12Device3* value; } _s_c154a46f_pDevice;
typedef struct _s_c154a46f_pResource { X12Resource* value; } _s_c154a46f_pResource;
typedef struct _s_c154a46f_pDesc { D3D12_SHADER_RESOURCE_VIEW_DESC* value; } _s_c154a46f_pDesc;
typedef struct _s_c154a46f_DestDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_c154a46f_DestDescriptor;
typedef struct _s_c154a46f_optionalFile { char* value; } _s_c154a46f_optionalFile;
typedef struct _s_c154a46f_optionalLine { int value; } _s_c154a46f_optionalLine;
static inline _s_c154a46f_pDevice _c154a46f_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_c154a46f_pDevice){value}; }
static inline _s_c154a46f_pResource _c154a46f_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_c154a46f_pResource){value}; }
static inline _s_c154a46f_pDesc _c154a46f_pDesc(D3D12_SHADER_RESOURCE_VIEW_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_c154a46f_pDesc){value}; }
static inline _s_c154a46f_DestDescriptor _c154a46f_DestDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_c154a46f_DestDescriptor){value}; }
static inline _s_c154a46f_optionalFile _c154a46f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c154a46f_optionalFile){value}; }
static inline _s_c154a46f_optionalLine _c154a46f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c154a46f_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCreateShaderResourceView(_s_c154a46f_pDevice pDevice, _s_c154a46f_pResource pResource, _s_c154a46f_pDesc pDesc, _s_c154a46f_DestDescriptor DestDescriptor, _s_c154a46f_optionalFile optionalFile, _s_c154a46f_optionalLine optionalLine) {
  x12DeviceCreateShaderResourceView(pDevice.value, pResource.value, pDesc.value, DestDescriptor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateConstantBufferView x12DeviceCreateConstantBufferView
#define _58fd7937_pDevice(value) value
#define _58fd7937_pDesc(value) value
#define _58fd7937_DestDescriptor(value) value
#define _58fd7937_optionalFile(value) value
#define _58fd7937_optionalLine(value) value
#else
typedef struct _s_58fd7937_pDevice { X12Device3* value; } _s_58fd7937_pDevice;
typedef struct _s_58fd7937_pDesc { D3D12_CONSTANT_BUFFER_VIEW_DESC* value; } _s_58fd7937_pDesc;
typedef struct _s_58fd7937_DestDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_58fd7937_DestDescriptor;
typedef struct _s_58fd7937_optionalFile { char* value; } _s_58fd7937_optionalFile;
typedef struct _s_58fd7937_optionalLine { int value; } _s_58fd7937_optionalLine;
static inline _s_58fd7937_pDevice _58fd7937_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_58fd7937_pDevice){value}; }
static inline _s_58fd7937_pDesc _58fd7937_pDesc(D3D12_CONSTANT_BUFFER_VIEW_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_58fd7937_pDesc){value}; }
static inline _s_58fd7937_DestDescriptor _58fd7937_DestDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_58fd7937_DestDescriptor){value}; }
static inline _s_58fd7937_optionalFile _58fd7937_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_58fd7937_optionalFile){value}; }
static inline _s_58fd7937_optionalLine _58fd7937_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_58fd7937_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCreateConstantBufferView(_s_58fd7937_pDevice pDevice, _s_58fd7937_pDesc pDesc, _s_58fd7937_DestDescriptor DestDescriptor, _s_58fd7937_optionalFile optionalFile, _s_58fd7937_optionalLine optionalLine) {
  x12DeviceCreateConstantBufferView(pDevice.value, pDesc.value, DestDescriptor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateSampler x12DeviceCreateSampler
#define _d2d18cb5_pDevice(value) value
#define _d2d18cb5_pDesc(value) value
#define _d2d18cb5_DestDescriptor(value) value
#define _d2d18cb5_optionalFile(value) value
#define _d2d18cb5_optionalLine(value) value
#else
typedef struct _s_d2d18cb5_pDevice { X12Device3* value; } _s_d2d18cb5_pDevice;
typedef struct _s_d2d18cb5_pDesc { D3D12_SAMPLER_DESC* value; } _s_d2d18cb5_pDesc;
typedef struct _s_d2d18cb5_DestDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_d2d18cb5_DestDescriptor;
typedef struct _s_d2d18cb5_optionalFile { char* value; } _s_d2d18cb5_optionalFile;
typedef struct _s_d2d18cb5_optionalLine { int value; } _s_d2d18cb5_optionalLine;
static inline _s_d2d18cb5_pDevice _d2d18cb5_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_d2d18cb5_pDevice){value}; }
static inline _s_d2d18cb5_pDesc _d2d18cb5_pDesc(D3D12_SAMPLER_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_d2d18cb5_pDesc){value}; }
static inline _s_d2d18cb5_DestDescriptor _d2d18cb5_DestDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_d2d18cb5_DestDescriptor){value}; }
static inline _s_d2d18cb5_optionalFile _d2d18cb5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d2d18cb5_optionalFile){value}; }
static inline _s_d2d18cb5_optionalLine _d2d18cb5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d2d18cb5_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCreateSampler(_s_d2d18cb5_pDevice pDevice, _s_d2d18cb5_pDesc pDesc, _s_d2d18cb5_DestDescriptor DestDescriptor, _s_d2d18cb5_optionalFile optionalFile, _s_d2d18cb5_optionalLine optionalLine) {
  x12DeviceCreateSampler(pDevice.value, pDesc.value, DestDescriptor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateRenderTargetView x12DeviceCreateRenderTargetView
#define _a403c238_pDevice(value) value
#define _a403c238_pResource(value) value
#define _a403c238_pDesc(value) value
#define _a403c238_DestDescriptor(value) value
#define _a403c238_optionalFile(value) value
#define _a403c238_optionalLine(value) value
#else
typedef struct _s_a403c238_pDevice { X12Device3* value; } _s_a403c238_pDevice;
typedef struct _s_a403c238_pResource { X12Resource* value; } _s_a403c238_pResource;
typedef struct _s_a403c238_pDesc { D3D12_RENDER_TARGET_VIEW_DESC* value; } _s_a403c238_pDesc;
typedef struct _s_a403c238_DestDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_a403c238_DestDescriptor;
typedef struct _s_a403c238_optionalFile { char* value; } _s_a403c238_optionalFile;
typedef struct _s_a403c238_optionalLine { int value; } _s_a403c238_optionalLine;
static inline _s_a403c238_pDevice _a403c238_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_a403c238_pDevice){value}; }
static inline _s_a403c238_pResource _a403c238_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_a403c238_pResource){value}; }
static inline _s_a403c238_pDesc _a403c238_pDesc(D3D12_RENDER_TARGET_VIEW_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_a403c238_pDesc){value}; }
static inline _s_a403c238_DestDescriptor _a403c238_DestDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_a403c238_DestDescriptor){value}; }
static inline _s_a403c238_optionalFile _a403c238_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a403c238_optionalFile){value}; }
static inline _s_a403c238_optionalLine _a403c238_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a403c238_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCreateRenderTargetView(_s_a403c238_pDevice pDevice, _s_a403c238_pResource pResource, _s_a403c238_pDesc pDesc, _s_a403c238_DestDescriptor DestDescriptor, _s_a403c238_optionalFile optionalFile, _s_a403c238_optionalLine optionalLine) {
  x12DeviceCreateRenderTargetView(pDevice.value, pResource.value, pDesc.value, DestDescriptor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateDepthStencilView x12DeviceCreateDepthStencilView
#define _39ced2d2_pDevice(value) value
#define _39ced2d2_pResource(value) value
#define _39ced2d2_pDesc(value) value
#define _39ced2d2_DestDescriptor(value) value
#define _39ced2d2_optionalFile(value) value
#define _39ced2d2_optionalLine(value) value
#else
typedef struct _s_39ced2d2_pDevice { X12Device3* value; } _s_39ced2d2_pDevice;
typedef struct _s_39ced2d2_pResource { X12Resource* value; } _s_39ced2d2_pResource;
typedef struct _s_39ced2d2_pDesc { D3D12_DEPTH_STENCIL_VIEW_DESC* value; } _s_39ced2d2_pDesc;
typedef struct _s_39ced2d2_DestDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_39ced2d2_DestDescriptor;
typedef struct _s_39ced2d2_optionalFile { char* value; } _s_39ced2d2_optionalFile;
typedef struct _s_39ced2d2_optionalLine { int value; } _s_39ced2d2_optionalLine;
static inline _s_39ced2d2_pDevice _39ced2d2_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_39ced2d2_pDevice){value}; }
static inline _s_39ced2d2_pResource _39ced2d2_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_39ced2d2_pResource){value}; }
static inline _s_39ced2d2_pDesc _39ced2d2_pDesc(D3D12_DEPTH_STENCIL_VIEW_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_39ced2d2_pDesc){value}; }
static inline _s_39ced2d2_DestDescriptor _39ced2d2_DestDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_39ced2d2_DestDescriptor){value}; }
static inline _s_39ced2d2_optionalFile _39ced2d2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_39ced2d2_optionalFile){value}; }
static inline _s_39ced2d2_optionalLine _39ced2d2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_39ced2d2_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCreateDepthStencilView(_s_39ced2d2_pDevice pDevice, _s_39ced2d2_pResource pResource, _s_39ced2d2_pDesc pDesc, _s_39ced2d2_DestDescriptor DestDescriptor, _s_39ced2d2_optionalFile optionalFile, _s_39ced2d2_optionalLine optionalLine) {
  x12DeviceCreateDepthStencilView(pDevice.value, pResource.value, pDesc.value, DestDescriptor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SerializeRootSignature x12SerializeRootSignature
#define _ac015392_pRootSignature(value) value
#define _ac015392_Version(value) value
#define _ac015392_outpBlob(value) value
#define _ac015392_outpErrorBlob(value) value
#define _ac015392_optionalFile(value) value
#define _ac015392_optionalLine(value) value
#else
typedef struct _s_ac015392_pRootSignature { D3D12_ROOT_SIGNATURE_DESC* value; } _s_ac015392_pRootSignature;
typedef struct _s_ac015392_Version { D3D_ROOT_SIGNATURE_VERSION value; } _s_ac015392_Version;
typedef struct _s_ac015392_outpBlob { X12Blob** value; } _s_ac015392_outpBlob;
typedef struct _s_ac015392_outpErrorBlob { X12Blob** value; } _s_ac015392_outpErrorBlob;
typedef struct _s_ac015392_optionalFile { char* value; } _s_ac015392_optionalFile;
typedef struct _s_ac015392_optionalLine { int value; } _s_ac015392_optionalLine;
static inline _s_ac015392_pRootSignature _ac015392_pRootSignature(D3D12_ROOT_SIGNATURE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_ac015392_pRootSignature){value}; }
static inline _s_ac015392_Version _ac015392_Version(D3D_ROOT_SIGNATURE_VERSION value) { return REDGPU_NP_STRUCT_INIT(_s_ac015392_Version){value}; }
static inline _s_ac015392_outpBlob _ac015392_outpBlob(X12Blob** value) { return REDGPU_NP_STRUCT_INIT(_s_ac015392_outpBlob){value}; }
static inline _s_ac015392_outpErrorBlob _ac015392_outpErrorBlob(X12Blob** value) { return REDGPU_NP_STRUCT_INIT(_s_ac015392_outpErrorBlob){value}; }
static inline _s_ac015392_optionalFile _ac015392_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ac015392_optionalFile){value}; }
static inline _s_ac015392_optionalLine _ac015392_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ac015392_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SerializeRootSignature(_s_ac015392_pRootSignature pRootSignature, _s_ac015392_Version Version, _s_ac015392_outpBlob outpBlob, _s_ac015392_outpErrorBlob outpErrorBlob, _s_ac015392_optionalFile optionalFile, _s_ac015392_optionalLine optionalLine) {
  return x12SerializeRootSignature(pRootSignature.value, Version.value, outpBlob.value, outpErrorBlob.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateRootSignature x12DeviceCreateRootSignature
#define _564e3f3d_pDevice(value) value
#define _564e3f3d_nodeMask(value) value
#define _564e3f3d_pBlobWithRootSignature(value) value
#define _564e3f3d_blobLengthInBytes(value) value
#define _564e3f3d_outpRootSignature(value) value
#define _564e3f3d_optionalFile(value) value
#define _564e3f3d_optionalLine(value) value
#else
typedef struct _s_564e3f3d_pDevice { X12Device3* value; } _s_564e3f3d_pDevice;
typedef struct _s_564e3f3d_nodeMask { unsigned value; } _s_564e3f3d_nodeMask;
typedef struct _s_564e3f3d_pBlobWithRootSignature { void* value; } _s_564e3f3d_pBlobWithRootSignature;
typedef struct _s_564e3f3d_blobLengthInBytes { size_t value; } _s_564e3f3d_blobLengthInBytes;
typedef struct _s_564e3f3d_outpRootSignature { X12RootSignature** value; } _s_564e3f3d_outpRootSignature;
typedef struct _s_564e3f3d_optionalFile { char* value; } _s_564e3f3d_optionalFile;
typedef struct _s_564e3f3d_optionalLine { int value; } _s_564e3f3d_optionalLine;
static inline _s_564e3f3d_pDevice _564e3f3d_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_564e3f3d_pDevice){value}; }
static inline _s_564e3f3d_nodeMask _564e3f3d_nodeMask(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_564e3f3d_nodeMask){value}; }
static inline _s_564e3f3d_pBlobWithRootSignature _564e3f3d_pBlobWithRootSignature(void* value) { return REDGPU_NP_STRUCT_INIT(_s_564e3f3d_pBlobWithRootSignature){value}; }
static inline _s_564e3f3d_blobLengthInBytes _564e3f3d_blobLengthInBytes(size_t value) { return REDGPU_NP_STRUCT_INIT(_s_564e3f3d_blobLengthInBytes){value}; }
static inline _s_564e3f3d_outpRootSignature _564e3f3d_outpRootSignature(X12RootSignature** value) { return REDGPU_NP_STRUCT_INIT(_s_564e3f3d_outpRootSignature){value}; }
static inline _s_564e3f3d_optionalFile _564e3f3d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_564e3f3d_optionalFile){value}; }
static inline _s_564e3f3d_optionalLine _564e3f3d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_564e3f3d_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateRootSignature(_s_564e3f3d_pDevice pDevice, _s_564e3f3d_nodeMask nodeMask, _s_564e3f3d_pBlobWithRootSignature pBlobWithRootSignature, _s_564e3f3d_blobLengthInBytes blobLengthInBytes, _s_564e3f3d_outpRootSignature outpRootSignature, _s_564e3f3d_optionalFile optionalFile, _s_564e3f3d_optionalLine optionalLine) {
  return x12DeviceCreateRootSignature(pDevice.value, nodeMask.value, pBlobWithRootSignature.value, blobLengthInBytes.value, outpRootSignature.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateGraphicsPipelineState x12DeviceCreateGraphicsPipelineState
#define _340f647a_pDevice(value) value
#define _340f647a_pDesc(value) value
#define _340f647a_outpPipelineState(value) value
#define _340f647a_optionalFile(value) value
#define _340f647a_optionalLine(value) value
#else
typedef struct _s_340f647a_pDevice { X12Device3* value; } _s_340f647a_pDevice;
typedef struct _s_340f647a_pDesc { D3D12_GRAPHICS_PIPELINE_STATE_DESC* value; } _s_340f647a_pDesc;
typedef struct _s_340f647a_outpPipelineState { X12PipelineState** value; } _s_340f647a_outpPipelineState;
typedef struct _s_340f647a_optionalFile { char* value; } _s_340f647a_optionalFile;
typedef struct _s_340f647a_optionalLine { int value; } _s_340f647a_optionalLine;
static inline _s_340f647a_pDevice _340f647a_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_340f647a_pDevice){value}; }
static inline _s_340f647a_pDesc _340f647a_pDesc(D3D12_GRAPHICS_PIPELINE_STATE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_340f647a_pDesc){value}; }
static inline _s_340f647a_outpPipelineState _340f647a_outpPipelineState(X12PipelineState** value) { return REDGPU_NP_STRUCT_INIT(_s_340f647a_outpPipelineState){value}; }
static inline _s_340f647a_optionalFile _340f647a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_340f647a_optionalFile){value}; }
static inline _s_340f647a_optionalLine _340f647a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_340f647a_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateGraphicsPipelineState(_s_340f647a_pDevice pDevice, _s_340f647a_pDesc pDesc, _s_340f647a_outpPipelineState outpPipelineState, _s_340f647a_optionalFile optionalFile, _s_340f647a_optionalLine optionalLine) {
  return x12DeviceCreateGraphicsPipelineState(pDevice.value, pDesc.value, outpPipelineState.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateComputePipelineState x12DeviceCreateComputePipelineState
#define _d38a55d0_pDevice(value) value
#define _d38a55d0_pDesc(value) value
#define _d38a55d0_outpPipelineState(value) value
#define _d38a55d0_optionalFile(value) value
#define _d38a55d0_optionalLine(value) value
#else
typedef struct _s_d38a55d0_pDevice { X12Device3* value; } _s_d38a55d0_pDevice;
typedef struct _s_d38a55d0_pDesc { D3D12_COMPUTE_PIPELINE_STATE_DESC* value; } _s_d38a55d0_pDesc;
typedef struct _s_d38a55d0_outpPipelineState { X12PipelineState** value; } _s_d38a55d0_outpPipelineState;
typedef struct _s_d38a55d0_optionalFile { char* value; } _s_d38a55d0_optionalFile;
typedef struct _s_d38a55d0_optionalLine { int value; } _s_d38a55d0_optionalLine;
static inline _s_d38a55d0_pDevice _d38a55d0_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_d38a55d0_pDevice){value}; }
static inline _s_d38a55d0_pDesc _d38a55d0_pDesc(D3D12_COMPUTE_PIPELINE_STATE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_d38a55d0_pDesc){value}; }
static inline _s_d38a55d0_outpPipelineState _d38a55d0_outpPipelineState(X12PipelineState** value) { return REDGPU_NP_STRUCT_INIT(_s_d38a55d0_outpPipelineState){value}; }
static inline _s_d38a55d0_optionalFile _d38a55d0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d38a55d0_optionalFile){value}; }
static inline _s_d38a55d0_optionalLine _d38a55d0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d38a55d0_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateComputePipelineState(_s_d38a55d0_pDevice pDevice, _s_d38a55d0_pDesc pDesc, _s_d38a55d0_outpPipelineState outpPipelineState, _s_d38a55d0_optionalFile optionalFile, _s_d38a55d0_optionalLine optionalLine) {
  return x12DeviceCreateComputePipelineState(pDevice.value, pDesc.value, outpPipelineState.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateFence x12DeviceCreateFence
#define _1d170a96_pDevice(value) value
#define _1d170a96_InitialValue(value) value
#define _1d170a96_Flags(value) value
#define _1d170a96_outpFence(value) value
#define _1d170a96_optionalFile(value) value
#define _1d170a96_optionalLine(value) value
#else
typedef struct _s_1d170a96_pDevice { X12Device3* value; } _s_1d170a96_pDevice;
typedef struct _s_1d170a96_InitialValue { uint64_t value; } _s_1d170a96_InitialValue;
typedef struct _s_1d170a96_Flags { D3D12_FENCE_FLAGS value; } _s_1d170a96_Flags;
typedef struct _s_1d170a96_outpFence { X12Fence** value; } _s_1d170a96_outpFence;
typedef struct _s_1d170a96_optionalFile { char* value; } _s_1d170a96_optionalFile;
typedef struct _s_1d170a96_optionalLine { int value; } _s_1d170a96_optionalLine;
static inline _s_1d170a96_pDevice _1d170a96_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_1d170a96_pDevice){value}; }
static inline _s_1d170a96_InitialValue _1d170a96_InitialValue(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_1d170a96_InitialValue){value}; }
static inline _s_1d170a96_Flags _1d170a96_Flags(D3D12_FENCE_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_1d170a96_Flags){value}; }
static inline _s_1d170a96_outpFence _1d170a96_outpFence(X12Fence** value) { return REDGPU_NP_STRUCT_INIT(_s_1d170a96_outpFence){value}; }
static inline _s_1d170a96_optionalFile _1d170a96_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1d170a96_optionalFile){value}; }
static inline _s_1d170a96_optionalLine _1d170a96_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1d170a96_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateFence(_s_1d170a96_pDevice pDevice, _s_1d170a96_InitialValue InitialValue, _s_1d170a96_Flags Flags, _s_1d170a96_outpFence outpFence, _s_1d170a96_optionalFile optionalFile, _s_1d170a96_optionalLine optionalLine) {
  return x12DeviceCreateFence(pDevice.value, InitialValue.value, Flags.value, outpFence.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateCommandQueue x12DeviceCreateCommandQueue
#define _1d44d710_pDevice(value) value
#define _1d44d710_pDesc(value) value
#define _1d44d710_outpCommandQueue(value) value
#define _1d44d710_optionalFile(value) value
#define _1d44d710_optionalLine(value) value
#else
typedef struct _s_1d44d710_pDevice { X12Device3* value; } _s_1d44d710_pDevice;
typedef struct _s_1d44d710_pDesc { D3D12_COMMAND_QUEUE_DESC* value; } _s_1d44d710_pDesc;
typedef struct _s_1d44d710_outpCommandQueue { X12CommandQueue** value; } _s_1d44d710_outpCommandQueue;
typedef struct _s_1d44d710_optionalFile { char* value; } _s_1d44d710_optionalFile;
typedef struct _s_1d44d710_optionalLine { int value; } _s_1d44d710_optionalLine;
static inline _s_1d44d710_pDevice _1d44d710_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_1d44d710_pDevice){value}; }
static inline _s_1d44d710_pDesc _1d44d710_pDesc(D3D12_COMMAND_QUEUE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_1d44d710_pDesc){value}; }
static inline _s_1d44d710_outpCommandQueue _1d44d710_outpCommandQueue(X12CommandQueue** value) { return REDGPU_NP_STRUCT_INIT(_s_1d44d710_outpCommandQueue){value}; }
static inline _s_1d44d710_optionalFile _1d44d710_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1d44d710_optionalFile){value}; }
static inline _s_1d44d710_optionalLine _1d44d710_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1d44d710_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateCommandQueue(_s_1d44d710_pDevice pDevice, _s_1d44d710_pDesc pDesc, _s_1d44d710_outpCommandQueue outpCommandQueue, _s_1d44d710_optionalFile optionalFile, _s_1d44d710_optionalLine optionalLine) {
  return x12DeviceCreateCommandQueue(pDevice.value, pDesc.value, outpCommandQueue.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateCommandAllocator x12DeviceCreateCommandAllocator
#define _b20267c3_pDevice(value) value
#define _b20267c3_type(value) value
#define _b20267c3_outpCommandAllocator(value) value
#define _b20267c3_optionalFile(value) value
#define _b20267c3_optionalLine(value) value
#else
typedef struct _s_b20267c3_pDevice { X12Device3* value; } _s_b20267c3_pDevice;
typedef struct _s_b20267c3_type { D3D12_COMMAND_LIST_TYPE value; } _s_b20267c3_type;
typedef struct _s_b20267c3_outpCommandAllocator { X12CommandAllocator** value; } _s_b20267c3_outpCommandAllocator;
typedef struct _s_b20267c3_optionalFile { char* value; } _s_b20267c3_optionalFile;
typedef struct _s_b20267c3_optionalLine { int value; } _s_b20267c3_optionalLine;
static inline _s_b20267c3_pDevice _b20267c3_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_b20267c3_pDevice){value}; }
static inline _s_b20267c3_type _b20267c3_type(D3D12_COMMAND_LIST_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_b20267c3_type){value}; }
static inline _s_b20267c3_outpCommandAllocator _b20267c3_outpCommandAllocator(X12CommandAllocator** value) { return REDGPU_NP_STRUCT_INIT(_s_b20267c3_outpCommandAllocator){value}; }
static inline _s_b20267c3_optionalFile _b20267c3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b20267c3_optionalFile){value}; }
static inline _s_b20267c3_optionalLine _b20267c3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b20267c3_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateCommandAllocator(_s_b20267c3_pDevice pDevice, _s_b20267c3_type type, _s_b20267c3_outpCommandAllocator outpCommandAllocator, _s_b20267c3_optionalFile optionalFile, _s_b20267c3_optionalLine optionalLine) {
  return x12DeviceCreateCommandAllocator(pDevice.value, type.value, outpCommandAllocator.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateCommandList x12DeviceCreateCommandList
#define _b4d09a0a_pDevice(value) value
#define _b4d09a0a_nodeMask(value) value
#define _b4d09a0a_type(value) value
#define _b4d09a0a_pCommandAllocator(value) value
#define _b4d09a0a_pInitialState(value) value
#define _b4d09a0a_outpCommandList(value) value
#define _b4d09a0a_optionalFile(value) value
#define _b4d09a0a_optionalLine(value) value
#else
typedef struct _s_b4d09a0a_pDevice { X12Device3* value; } _s_b4d09a0a_pDevice;
typedef struct _s_b4d09a0a_nodeMask { unsigned value; } _s_b4d09a0a_nodeMask;
typedef struct _s_b4d09a0a_type { D3D12_COMMAND_LIST_TYPE value; } _s_b4d09a0a_type;
typedef struct _s_b4d09a0a_pCommandAllocator { X12CommandAllocator* value; } _s_b4d09a0a_pCommandAllocator;
typedef struct _s_b4d09a0a_pInitialState { X12PipelineState* value; } _s_b4d09a0a_pInitialState;
typedef struct _s_b4d09a0a_outpCommandList { X12CommandList** value; } _s_b4d09a0a_outpCommandList;
typedef struct _s_b4d09a0a_optionalFile { char* value; } _s_b4d09a0a_optionalFile;
typedef struct _s_b4d09a0a_optionalLine { int value; } _s_b4d09a0a_optionalLine;
static inline _s_b4d09a0a_pDevice _b4d09a0a_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_b4d09a0a_pDevice){value}; }
static inline _s_b4d09a0a_nodeMask _b4d09a0a_nodeMask(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b4d09a0a_nodeMask){value}; }
static inline _s_b4d09a0a_type _b4d09a0a_type(D3D12_COMMAND_LIST_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_b4d09a0a_type){value}; }
static inline _s_b4d09a0a_pCommandAllocator _b4d09a0a_pCommandAllocator(X12CommandAllocator* value) { return REDGPU_NP_STRUCT_INIT(_s_b4d09a0a_pCommandAllocator){value}; }
static inline _s_b4d09a0a_pInitialState _b4d09a0a_pInitialState(X12PipelineState* value) { return REDGPU_NP_STRUCT_INIT(_s_b4d09a0a_pInitialState){value}; }
static inline _s_b4d09a0a_outpCommandList _b4d09a0a_outpCommandList(X12CommandList** value) { return REDGPU_NP_STRUCT_INIT(_s_b4d09a0a_outpCommandList){value}; }
static inline _s_b4d09a0a_optionalFile _b4d09a0a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b4d09a0a_optionalFile){value}; }
static inline _s_b4d09a0a_optionalLine _b4d09a0a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b4d09a0a_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateCommandList(_s_b4d09a0a_pDevice pDevice, _s_b4d09a0a_nodeMask nodeMask, _s_b4d09a0a_type type, _s_b4d09a0a_pCommandAllocator pCommandAllocator, _s_b4d09a0a_pInitialState pInitialState, _s_b4d09a0a_outpCommandList outpCommandList, _s_b4d09a0a_optionalFile optionalFile, _s_b4d09a0a_optionalLine optionalLine) {
  return x12DeviceCreateCommandList(pDevice.value, nodeMask.value, type.value, pCommandAllocator.value, pInitialState.value, outpCommandList.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12ResourceGetGPUVirtualAddress x12ResourceGetGPUVirtualAddress
#define _7218cbed_pResource(value) value
#else
typedef struct _s_7218cbed_pResource { X12Resource* value; } _s_7218cbed_pResource;
static inline _s_7218cbed_pResource _7218cbed_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_7218cbed_pResource){value}; }
REDGPU_NP_DECLSPEC D3D12_GPU_VIRTUAL_ADDRESS REDGPU_NP_API np_x12ResourceGetGPUVirtualAddress(_s_7218cbed_pResource pResource) {
  return x12ResourceGetGPUVirtualAddress(pResource.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12PipelineStateGetCachedBlob x12PipelineStateGetCachedBlob
#define _82159365_pPipelineState(value) value
#define _82159365_outpBlob(value) value
#define _82159365_optionalFile(value) value
#define _82159365_optionalLine(value) value
#else
typedef struct _s_82159365_pPipelineState { X12PipelineState* value; } _s_82159365_pPipelineState;
typedef struct _s_82159365_outpBlob { X12Blob** value; } _s_82159365_outpBlob;
typedef struct _s_82159365_optionalFile { char* value; } _s_82159365_optionalFile;
typedef struct _s_82159365_optionalLine { int value; } _s_82159365_optionalLine;
static inline _s_82159365_pPipelineState _82159365_pPipelineState(X12PipelineState* value) { return REDGPU_NP_STRUCT_INIT(_s_82159365_pPipelineState){value}; }
static inline _s_82159365_outpBlob _82159365_outpBlob(X12Blob** value) { return REDGPU_NP_STRUCT_INIT(_s_82159365_outpBlob){value}; }
static inline _s_82159365_optionalFile _82159365_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_82159365_optionalFile){value}; }
static inline _s_82159365_optionalLine _82159365_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_82159365_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12PipelineStateGetCachedBlob(_s_82159365_pPipelineState pPipelineState, _s_82159365_outpBlob outpBlob, _s_82159365_optionalFile optionalFile, _s_82159365_optionalLine optionalLine) {
  return x12PipelineStateGetCachedBlob(pPipelineState.value, outpBlob.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12BlobGetBufferPointer x12BlobGetBufferPointer
#define _567bd3e8_pBlob(value) value
#else
typedef struct _s_567bd3e8_pBlob { X12Blob* value; } _s_567bd3e8_pBlob;
static inline _s_567bd3e8_pBlob _567bd3e8_pBlob(X12Blob* value) { return REDGPU_NP_STRUCT_INIT(_s_567bd3e8_pBlob){value}; }
REDGPU_NP_DECLSPEC void* REDGPU_NP_API np_x12BlobGetBufferPointer(_s_567bd3e8_pBlob pBlob) {
  return x12BlobGetBufferPointer(pBlob.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12BlobGetBufferSize x12BlobGetBufferSize
#define _7b9069ad_pBlob(value) value
#else
typedef struct _s_7b9069ad_pBlob { X12Blob* value; } _s_7b9069ad_pBlob;
static inline _s_7b9069ad_pBlob _7b9069ad_pBlob(X12Blob* value) { return REDGPU_NP_STRUCT_INIT(_s_7b9069ad_pBlob){value}; }
REDGPU_NP_DECLSPEC size_t REDGPU_NP_API np_x12BlobGetBufferSize(_s_7b9069ad_pBlob pBlob) {
  return x12BlobGetBufferSize(pBlob.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CreateRootSignatureDeserializer x12CreateRootSignatureDeserializer
#define _bc58735f_pSrcData(value) value
#define _bc58735f_SrcDataSizeInBytes(value) value
#define _bc58735f_outpRootSignatureDeserializer(value) value
#define _bc58735f_optionalFile(value) value
#define _bc58735f_optionalLine(value) value
#else
typedef struct _s_bc58735f_pSrcData { void* value; } _s_bc58735f_pSrcData;
typedef struct _s_bc58735f_SrcDataSizeInBytes { size_t value; } _s_bc58735f_SrcDataSizeInBytes;
typedef struct _s_bc58735f_outpRootSignatureDeserializer { X12RootSignatureDeserializer** value; } _s_bc58735f_outpRootSignatureDeserializer;
typedef struct _s_bc58735f_optionalFile { char* value; } _s_bc58735f_optionalFile;
typedef struct _s_bc58735f_optionalLine { int value; } _s_bc58735f_optionalLine;
static inline _s_bc58735f_pSrcData _bc58735f_pSrcData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bc58735f_pSrcData){value}; }
static inline _s_bc58735f_SrcDataSizeInBytes _bc58735f_SrcDataSizeInBytes(size_t value) { return REDGPU_NP_STRUCT_INIT(_s_bc58735f_SrcDataSizeInBytes){value}; }
static inline _s_bc58735f_outpRootSignatureDeserializer _bc58735f_outpRootSignatureDeserializer(X12RootSignatureDeserializer** value) { return REDGPU_NP_STRUCT_INIT(_s_bc58735f_outpRootSignatureDeserializer){value}; }
static inline _s_bc58735f_optionalFile _bc58735f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bc58735f_optionalFile){value}; }
static inline _s_bc58735f_optionalLine _bc58735f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bc58735f_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CreateRootSignatureDeserializer(_s_bc58735f_pSrcData pSrcData, _s_bc58735f_SrcDataSizeInBytes SrcDataSizeInBytes, _s_bc58735f_outpRootSignatureDeserializer outpRootSignatureDeserializer, _s_bc58735f_optionalFile optionalFile, _s_bc58735f_optionalLine optionalLine) {
  return x12CreateRootSignatureDeserializer(pSrcData.value, SrcDataSizeInBytes.value, outpRootSignatureDeserializer.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12RootSignatureDeserializerGetRootSignatureDesc x12RootSignatureDeserializerGetRootSignatureDesc
#define _575fab4f_pRootSignatureDeserializer(value) value
#define _575fab4f_optionalFile(value) value
#define _575fab4f_optionalLine(value) value
#else
typedef struct _s_575fab4f_pRootSignatureDeserializer { X12RootSignatureDeserializer* value; } _s_575fab4f_pRootSignatureDeserializer;
typedef struct _s_575fab4f_optionalFile { char* value; } _s_575fab4f_optionalFile;
typedef struct _s_575fab4f_optionalLine { int value; } _s_575fab4f_optionalLine;
static inline _s_575fab4f_pRootSignatureDeserializer _575fab4f_pRootSignatureDeserializer(X12RootSignatureDeserializer* value) { return REDGPU_NP_STRUCT_INIT(_s_575fab4f_pRootSignatureDeserializer){value}; }
static inline _s_575fab4f_optionalFile _575fab4f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_575fab4f_optionalFile){value}; }
static inline _s_575fab4f_optionalLine _575fab4f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_575fab4f_optionalLine){value}; }
REDGPU_NP_DECLSPEC D3D12_ROOT_SIGNATURE_DESC* REDGPU_NP_API np_x12RootSignatureDeserializerGetRootSignatureDesc(_s_575fab4f_pRootSignatureDeserializer pRootSignatureDeserializer, _s_575fab4f_optionalFile optionalFile, _s_575fab4f_optionalLine optionalLine) {
  return x12RootSignatureDeserializerGetRootSignatureDesc(pRootSignatureDeserializer.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FenceGetCompletedValue x12FenceGetCompletedValue
#define _1baee875_pFence(value) value
#define _1baee875_optionalFile(value) value
#define _1baee875_optionalLine(value) value
#else
typedef struct _s_1baee875_pFence { X12Fence* value; } _s_1baee875_pFence;
typedef struct _s_1baee875_optionalFile { char* value; } _s_1baee875_optionalFile;
typedef struct _s_1baee875_optionalLine { int value; } _s_1baee875_optionalLine;
static inline _s_1baee875_pFence _1baee875_pFence(X12Fence* value) { return REDGPU_NP_STRUCT_INIT(_s_1baee875_pFence){value}; }
static inline _s_1baee875_optionalFile _1baee875_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1baee875_optionalFile){value}; }
static inline _s_1baee875_optionalLine _1baee875_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1baee875_optionalLine){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_x12FenceGetCompletedValue(_s_1baee875_pFence pFence, _s_1baee875_optionalFile optionalFile, _s_1baee875_optionalLine optionalLine) {
  return x12FenceGetCompletedValue(pFence.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FenceSetEventOnCompletion x12FenceSetEventOnCompletion
#define _30599f75_pFence(value) value
#define _30599f75_Value(value) value
#define _30599f75_hEvent(value) value
#define _30599f75_optionalFile(value) value
#define _30599f75_optionalLine(value) value
#else
typedef struct _s_30599f75_pFence { X12Fence* value; } _s_30599f75_pFence;
typedef struct _s_30599f75_Value { uint64_t value; } _s_30599f75_Value;
typedef struct _s_30599f75_hEvent { void* value; } _s_30599f75_hEvent;
typedef struct _s_30599f75_optionalFile { char* value; } _s_30599f75_optionalFile;
typedef struct _s_30599f75_optionalLine { int value; } _s_30599f75_optionalLine;
static inline _s_30599f75_pFence _30599f75_pFence(X12Fence* value) { return REDGPU_NP_STRUCT_INIT(_s_30599f75_pFence){value}; }
static inline _s_30599f75_Value _30599f75_Value(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_30599f75_Value){value}; }
static inline _s_30599f75_hEvent _30599f75_hEvent(void* value) { return REDGPU_NP_STRUCT_INIT(_s_30599f75_hEvent){value}; }
static inline _s_30599f75_optionalFile _30599f75_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_30599f75_optionalFile){value}; }
static inline _s_30599f75_optionalLine _30599f75_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_30599f75_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FenceSetEventOnCompletion(_s_30599f75_pFence pFence, _s_30599f75_Value Value, _s_30599f75_hEvent hEvent, _s_30599f75_optionalFile optionalFile, _s_30599f75_optionalLine optionalLine) {
  return x12FenceSetEventOnCompletion(pFence.value, Value.value, hEvent.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceSetEventOnMultipleFenceCompletion x12DeviceSetEventOnMultipleFenceCompletion
#define _bcd20225_pDevice(value) value
#define _bcd20225_ppFences(value) value
#define _bcd20225_pFenceValues(value) value
#define _bcd20225_NumFences(value) value
#define _bcd20225_Flag(value) value
#define _bcd20225_hEvent(value) value
#define _bcd20225_optionalFile(value) value
#define _bcd20225_optionalLine(value) value
#else
typedef struct _s_bcd20225_pDevice { X12Device3* value; } _s_bcd20225_pDevice;
typedef struct _s_bcd20225_ppFences { X12Fence** value; } _s_bcd20225_ppFences;
typedef struct _s_bcd20225_pFenceValues { uint64_t* value; } _s_bcd20225_pFenceValues;
typedef struct _s_bcd20225_NumFences { unsigned value; } _s_bcd20225_NumFences;
typedef struct _s_bcd20225_Flag { D3D12_MULTIPLE_FENCE_WAIT_FLAG value; } _s_bcd20225_Flag;
typedef struct _s_bcd20225_hEvent { void* value; } _s_bcd20225_hEvent;
typedef struct _s_bcd20225_optionalFile { char* value; } _s_bcd20225_optionalFile;
typedef struct _s_bcd20225_optionalLine { int value; } _s_bcd20225_optionalLine;
static inline _s_bcd20225_pDevice _bcd20225_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_bcd20225_pDevice){value}; }
static inline _s_bcd20225_ppFences _bcd20225_ppFences(X12Fence** value) { return REDGPU_NP_STRUCT_INIT(_s_bcd20225_ppFences){value}; }
static inline _s_bcd20225_pFenceValues _bcd20225_pFenceValues(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_bcd20225_pFenceValues){value}; }
static inline _s_bcd20225_NumFences _bcd20225_NumFences(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bcd20225_NumFences){value}; }
static inline _s_bcd20225_Flag _bcd20225_Flag(D3D12_MULTIPLE_FENCE_WAIT_FLAG value) { return REDGPU_NP_STRUCT_INIT(_s_bcd20225_Flag){value}; }
static inline _s_bcd20225_hEvent _bcd20225_hEvent(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bcd20225_hEvent){value}; }
static inline _s_bcd20225_optionalFile _bcd20225_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bcd20225_optionalFile){value}; }
static inline _s_bcd20225_optionalLine _bcd20225_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bcd20225_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceSetEventOnMultipleFenceCompletion(_s_bcd20225_pDevice pDevice, _s_bcd20225_ppFences ppFences, _s_bcd20225_pFenceValues pFenceValues, _s_bcd20225_NumFences NumFences, _s_bcd20225_Flag Flag, _s_bcd20225_hEvent hEvent, _s_bcd20225_optionalFile optionalFile, _s_bcd20225_optionalLine optionalLine) {
  return x12DeviceSetEventOnMultipleFenceCompletion(pDevice.value, ppFences.value, pFenceValues.value, NumFences.value, Flag.value, hEvent.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FenceSignal x12FenceSignal
#define _97432823_pFence(value) value
#define _97432823_Value(value) value
#define _97432823_optionalFile(value) value
#define _97432823_optionalLine(value) value
#else
typedef struct _s_97432823_pFence { X12Fence* value; } _s_97432823_pFence;
typedef struct _s_97432823_Value { uint64_t value; } _s_97432823_Value;
typedef struct _s_97432823_optionalFile { char* value; } _s_97432823_optionalFile;
typedef struct _s_97432823_optionalLine { int value; } _s_97432823_optionalLine;
static inline _s_97432823_pFence _97432823_pFence(X12Fence* value) { return REDGPU_NP_STRUCT_INIT(_s_97432823_pFence){value}; }
static inline _s_97432823_Value _97432823_Value(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_97432823_Value){value}; }
static inline _s_97432823_optionalFile _97432823_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_97432823_optionalFile){value}; }
static inline _s_97432823_optionalLine _97432823_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_97432823_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FenceSignal(_s_97432823_pFence pFence, _s_97432823_Value Value, _s_97432823_optionalFile optionalFile, _s_97432823_optionalLine optionalLine) {
  return x12FenceSignal(pFence.value, Value.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandAllocatorReset x12CommandAllocatorReset
#define _3c114868_pCommandAllocator(value) value
#define _3c114868_optionalFile(value) value
#define _3c114868_optionalLine(value) value
#else
typedef struct _s_3c114868_pCommandAllocator { X12CommandAllocator* value; } _s_3c114868_pCommandAllocator;
typedef struct _s_3c114868_optionalFile { char* value; } _s_3c114868_optionalFile;
typedef struct _s_3c114868_optionalLine { int value; } _s_3c114868_optionalLine;
static inline _s_3c114868_pCommandAllocator _3c114868_pCommandAllocator(X12CommandAllocator* value) { return REDGPU_NP_STRUCT_INIT(_s_3c114868_pCommandAllocator){value}; }
static inline _s_3c114868_optionalFile _3c114868_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3c114868_optionalFile){value}; }
static inline _s_3c114868_optionalLine _3c114868_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3c114868_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CommandAllocatorReset(_s_3c114868_pCommandAllocator pCommandAllocator, _s_3c114868_optionalFile optionalFile, _s_3c114868_optionalLine optionalLine) {
  return x12CommandAllocatorReset(pCommandAllocator.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListReset x12CommandListReset
#define _8b12b876_pCommandList(value) value
#define _8b12b876_pAllocator(value) value
#define _8b12b876_pInitialState(value) value
#define _8b12b876_optionalFile(value) value
#define _8b12b876_optionalLine(value) value
#else
typedef struct _s_8b12b876_pCommandList { X12CommandList* value; } _s_8b12b876_pCommandList;
typedef struct _s_8b12b876_pAllocator { X12CommandAllocator* value; } _s_8b12b876_pAllocator;
typedef struct _s_8b12b876_pInitialState { X12PipelineState* value; } _s_8b12b876_pInitialState;
typedef struct _s_8b12b876_optionalFile { char* value; } _s_8b12b876_optionalFile;
typedef struct _s_8b12b876_optionalLine { int value; } _s_8b12b876_optionalLine;
static inline _s_8b12b876_pCommandList _8b12b876_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_8b12b876_pCommandList){value}; }
static inline _s_8b12b876_pAllocator _8b12b876_pAllocator(X12CommandAllocator* value) { return REDGPU_NP_STRUCT_INIT(_s_8b12b876_pAllocator){value}; }
static inline _s_8b12b876_pInitialState _8b12b876_pInitialState(X12PipelineState* value) { return REDGPU_NP_STRUCT_INIT(_s_8b12b876_pInitialState){value}; }
static inline _s_8b12b876_optionalFile _8b12b876_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8b12b876_optionalFile){value}; }
static inline _s_8b12b876_optionalLine _8b12b876_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8b12b876_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CommandListReset(_s_8b12b876_pCommandList pCommandList, _s_8b12b876_pAllocator pAllocator, _s_8b12b876_pInitialState pInitialState, _s_8b12b876_optionalFile optionalFile, _s_8b12b876_optionalLine optionalLine) {
  return x12CommandListReset(pCommandList.value, pAllocator.value, pInitialState.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListClose x12CommandListClose
#define _54956ba0_pCommandList(value) value
#define _54956ba0_optionalFile(value) value
#define _54956ba0_optionalLine(value) value
#else
typedef struct _s_54956ba0_pCommandList { X12CommandList* value; } _s_54956ba0_pCommandList;
typedef struct _s_54956ba0_optionalFile { char* value; } _s_54956ba0_optionalFile;
typedef struct _s_54956ba0_optionalLine { int value; } _s_54956ba0_optionalLine;
static inline _s_54956ba0_pCommandList _54956ba0_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_54956ba0_pCommandList){value}; }
static inline _s_54956ba0_optionalFile _54956ba0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_54956ba0_optionalFile){value}; }
static inline _s_54956ba0_optionalLine _54956ba0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_54956ba0_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CommandListClose(_s_54956ba0_pCommandList pCommandList, _s_54956ba0_optionalFile optionalFile, _s_54956ba0_optionalLine optionalLine) {
  return x12CommandListClose(pCommandList.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListCopyBufferRegion x12CommandListCopyBufferRegion
#define _2f34767b_pCommandList(value) value
#define _2f34767b_pDstBuffer(value) value
#define _2f34767b_DstOffset(value) value
#define _2f34767b_pSrcBuffer(value) value
#define _2f34767b_SrcOffset(value) value
#define _2f34767b_NumBytes(value) value
#else
typedef struct _s_2f34767b_pCommandList { X12CommandList* value; } _s_2f34767b_pCommandList;
typedef struct _s_2f34767b_pDstBuffer { X12Resource* value; } _s_2f34767b_pDstBuffer;
typedef struct _s_2f34767b_DstOffset { uint64_t value; } _s_2f34767b_DstOffset;
typedef struct _s_2f34767b_pSrcBuffer { X12Resource* value; } _s_2f34767b_pSrcBuffer;
typedef struct _s_2f34767b_SrcOffset { uint64_t value; } _s_2f34767b_SrcOffset;
typedef struct _s_2f34767b_NumBytes { uint64_t value; } _s_2f34767b_NumBytes;
static inline _s_2f34767b_pCommandList _2f34767b_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_2f34767b_pCommandList){value}; }
static inline _s_2f34767b_pDstBuffer _2f34767b_pDstBuffer(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_2f34767b_pDstBuffer){value}; }
static inline _s_2f34767b_DstOffset _2f34767b_DstOffset(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_2f34767b_DstOffset){value}; }
static inline _s_2f34767b_pSrcBuffer _2f34767b_pSrcBuffer(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_2f34767b_pSrcBuffer){value}; }
static inline _s_2f34767b_SrcOffset _2f34767b_SrcOffset(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_2f34767b_SrcOffset){value}; }
static inline _s_2f34767b_NumBytes _2f34767b_NumBytes(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_2f34767b_NumBytes){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListCopyBufferRegion(_s_2f34767b_pCommandList pCommandList, _s_2f34767b_pDstBuffer pDstBuffer, _s_2f34767b_DstOffset DstOffset, _s_2f34767b_pSrcBuffer pSrcBuffer, _s_2f34767b_SrcOffset SrcOffset, _s_2f34767b_NumBytes NumBytes) {
  x12CommandListCopyBufferRegion(pCommandList.value, pDstBuffer.value, DstOffset.value, pSrcBuffer.value, SrcOffset.value, NumBytes.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListClearUnorderedAccessViewUint x12CommandListClearUnorderedAccessViewUint
#define _28c713f9_pCommandList(value) value
#define _28c713f9_ViewGPUHandleInCurrentHeap(value) value
#define _28c713f9_ViewCPUHandle(value) value
#define _28c713f9_pResource(value) value
#define _28c713f9_Values[4](value) value
#define _28c713f9_NumRects(value) value
#define _28c713f9_pRects(value) value
#else
typedef struct _s_28c713f9_pCommandList { X12CommandList* value; } _s_28c713f9_pCommandList;
typedef struct _s_28c713f9_ViewGPUHandleInCurrentHeap { D3D12_GPU_DESCRIPTOR_HANDLE value; } _s_28c713f9_ViewGPUHandleInCurrentHeap;
typedef struct _s_28c713f9_ViewCPUHandle { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_28c713f9_ViewCPUHandle;
typedef struct _s_28c713f9_pResource { X12Resource* value; } _s_28c713f9_pResource;
typedef struct _s_28c713f9_Values[4] { unsigned value; } _s_28c713f9_Values[4];
typedef struct _s_28c713f9_NumRects { unsigned value; } _s_28c713f9_NumRects;
typedef struct _s_28c713f9_pRects { D3D12_RECT* value; } _s_28c713f9_pRects;
static inline _s_28c713f9_pCommandList _28c713f9_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_28c713f9_pCommandList){value}; }
static inline _s_28c713f9_ViewGPUHandleInCurrentHeap _28c713f9_ViewGPUHandleInCurrentHeap(D3D12_GPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_28c713f9_ViewGPUHandleInCurrentHeap){value}; }
static inline _s_28c713f9_ViewCPUHandle _28c713f9_ViewCPUHandle(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_28c713f9_ViewCPUHandle){value}; }
static inline _s_28c713f9_pResource _28c713f9_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_28c713f9_pResource){value}; }
static inline _s_28c713f9_Values[4] _28c713f9_Values[4](unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_28c713f9_Values[4]){value}; }
static inline _s_28c713f9_NumRects _28c713f9_NumRects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_28c713f9_NumRects){value}; }
static inline _s_28c713f9_pRects _28c713f9_pRects(D3D12_RECT* value) { return REDGPU_NP_STRUCT_INIT(_s_28c713f9_pRects){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListClearUnorderedAccessViewUint(_s_28c713f9_pCommandList pCommandList, _s_28c713f9_ViewGPUHandleInCurrentHeap ViewGPUHandleInCurrentHeap, _s_28c713f9_ViewCPUHandle ViewCPUHandle, _s_28c713f9_pResource pResource, _s_28c713f9_Values[4] Values[4], _s_28c713f9_NumRects NumRects, _s_28c713f9_pRects pRects) {
  x12CommandListClearUnorderedAccessViewUint(pCommandList.value, ViewGPUHandleInCurrentHeap.value, ViewCPUHandle.value, pResource.value, Values[4].value, NumRects.value, pRects.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListClearUnorderedAccessViewFloat x12CommandListClearUnorderedAccessViewFloat
#define _e0b9920e_pCommandList(value) value
#define _e0b9920e_ViewGPUHandleInCurrentHeap(value) value
#define _e0b9920e_ViewCPUHandle(value) value
#define _e0b9920e_pResource(value) value
#define _e0b9920e_Values[4](value) value
#define _e0b9920e_NumRects(value) value
#define _e0b9920e_pRects(value) value
#else
typedef struct _s_e0b9920e_pCommandList { X12CommandList* value; } _s_e0b9920e_pCommandList;
typedef struct _s_e0b9920e_ViewGPUHandleInCurrentHeap { D3D12_GPU_DESCRIPTOR_HANDLE value; } _s_e0b9920e_ViewGPUHandleInCurrentHeap;
typedef struct _s_e0b9920e_ViewCPUHandle { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_e0b9920e_ViewCPUHandle;
typedef struct _s_e0b9920e_pResource { X12Resource* value; } _s_e0b9920e_pResource;
typedef struct _s_e0b9920e_Values[4] { float value; } _s_e0b9920e_Values[4];
typedef struct _s_e0b9920e_NumRects { unsigned value; } _s_e0b9920e_NumRects;
typedef struct _s_e0b9920e_pRects { D3D12_RECT* value; } _s_e0b9920e_pRects;
static inline _s_e0b9920e_pCommandList _e0b9920e_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_e0b9920e_pCommandList){value}; }
static inline _s_e0b9920e_ViewGPUHandleInCurrentHeap _e0b9920e_ViewGPUHandleInCurrentHeap(D3D12_GPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_e0b9920e_ViewGPUHandleInCurrentHeap){value}; }
static inline _s_e0b9920e_ViewCPUHandle _e0b9920e_ViewCPUHandle(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_e0b9920e_ViewCPUHandle){value}; }
static inline _s_e0b9920e_pResource _e0b9920e_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_e0b9920e_pResource){value}; }
static inline _s_e0b9920e_Values[4] _e0b9920e_Values[4](float value) { return REDGPU_NP_STRUCT_INIT(_s_e0b9920e_Values[4]){value}; }
static inline _s_e0b9920e_NumRects _e0b9920e_NumRects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e0b9920e_NumRects){value}; }
static inline _s_e0b9920e_pRects _e0b9920e_pRects(D3D12_RECT* value) { return REDGPU_NP_STRUCT_INIT(_s_e0b9920e_pRects){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListClearUnorderedAccessViewFloat(_s_e0b9920e_pCommandList pCommandList, _s_e0b9920e_ViewGPUHandleInCurrentHeap ViewGPUHandleInCurrentHeap, _s_e0b9920e_ViewCPUHandle ViewCPUHandle, _s_e0b9920e_pResource pResource, _s_e0b9920e_Values[4] Values[4], _s_e0b9920e_NumRects NumRects, _s_e0b9920e_pRects pRects) {
  x12CommandListClearUnorderedAccessViewFloat(pCommandList.value, ViewGPUHandleInCurrentHeap.value, ViewCPUHandle.value, pResource.value, Values[4].value, NumRects.value, pRects.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListDrawInstanced x12CommandListDrawInstanced
#define _693d4dd6_pCommandList(value) value
#define _693d4dd6_VertexCountPerInstance(value) value
#define _693d4dd6_InstanceCount(value) value
#define _693d4dd6_StartVertexLocation(value) value
#define _693d4dd6_StartInstanceLocation(value) value
#else
typedef struct _s_693d4dd6_pCommandList { X12CommandList* value; } _s_693d4dd6_pCommandList;
typedef struct _s_693d4dd6_VertexCountPerInstance { unsigned value; } _s_693d4dd6_VertexCountPerInstance;
typedef struct _s_693d4dd6_InstanceCount { unsigned value; } _s_693d4dd6_InstanceCount;
typedef struct _s_693d4dd6_StartVertexLocation { unsigned value; } _s_693d4dd6_StartVertexLocation;
typedef struct _s_693d4dd6_StartInstanceLocation { unsigned value; } _s_693d4dd6_StartInstanceLocation;
static inline _s_693d4dd6_pCommandList _693d4dd6_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_693d4dd6_pCommandList){value}; }
static inline _s_693d4dd6_VertexCountPerInstance _693d4dd6_VertexCountPerInstance(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_693d4dd6_VertexCountPerInstance){value}; }
static inline _s_693d4dd6_InstanceCount _693d4dd6_InstanceCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_693d4dd6_InstanceCount){value}; }
static inline _s_693d4dd6_StartVertexLocation _693d4dd6_StartVertexLocation(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_693d4dd6_StartVertexLocation){value}; }
static inline _s_693d4dd6_StartInstanceLocation _693d4dd6_StartInstanceLocation(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_693d4dd6_StartInstanceLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListDrawInstanced(_s_693d4dd6_pCommandList pCommandList, _s_693d4dd6_VertexCountPerInstance VertexCountPerInstance, _s_693d4dd6_InstanceCount InstanceCount, _s_693d4dd6_StartVertexLocation StartVertexLocation, _s_693d4dd6_StartInstanceLocation StartInstanceLocation) {
  x12CommandListDrawInstanced(pCommandList.value, VertexCountPerInstance.value, InstanceCount.value, StartVertexLocation.value, StartInstanceLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListDrawIndexedInstanced x12CommandListDrawIndexedInstanced
#define _c0a461f9_pCommandList(value) value
#define _c0a461f9_IndexCountPerInstance(value) value
#define _c0a461f9_InstanceCount(value) value
#define _c0a461f9_StartIndexLocation(value) value
#define _c0a461f9_BaseVertexLocation(value) value
#define _c0a461f9_StartInstanceLocation(value) value
#else
typedef struct _s_c0a461f9_pCommandList { X12CommandList* value; } _s_c0a461f9_pCommandList;
typedef struct _s_c0a461f9_IndexCountPerInstance { unsigned value; } _s_c0a461f9_IndexCountPerInstance;
typedef struct _s_c0a461f9_InstanceCount { unsigned value; } _s_c0a461f9_InstanceCount;
typedef struct _s_c0a461f9_StartIndexLocation { unsigned value; } _s_c0a461f9_StartIndexLocation;
typedef struct _s_c0a461f9_BaseVertexLocation { int value; } _s_c0a461f9_BaseVertexLocation;
typedef struct _s_c0a461f9_StartInstanceLocation { unsigned value; } _s_c0a461f9_StartInstanceLocation;
static inline _s_c0a461f9_pCommandList _c0a461f9_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_c0a461f9_pCommandList){value}; }
static inline _s_c0a461f9_IndexCountPerInstance _c0a461f9_IndexCountPerInstance(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c0a461f9_IndexCountPerInstance){value}; }
static inline _s_c0a461f9_InstanceCount _c0a461f9_InstanceCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c0a461f9_InstanceCount){value}; }
static inline _s_c0a461f9_StartIndexLocation _c0a461f9_StartIndexLocation(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c0a461f9_StartIndexLocation){value}; }
static inline _s_c0a461f9_BaseVertexLocation _c0a461f9_BaseVertexLocation(int value) { return REDGPU_NP_STRUCT_INIT(_s_c0a461f9_BaseVertexLocation){value}; }
static inline _s_c0a461f9_StartInstanceLocation _c0a461f9_StartInstanceLocation(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c0a461f9_StartInstanceLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListDrawIndexedInstanced(_s_c0a461f9_pCommandList pCommandList, _s_c0a461f9_IndexCountPerInstance IndexCountPerInstance, _s_c0a461f9_InstanceCount InstanceCount, _s_c0a461f9_StartIndexLocation StartIndexLocation, _s_c0a461f9_BaseVertexLocation BaseVertexLocation, _s_c0a461f9_StartInstanceLocation StartInstanceLocation) {
  x12CommandListDrawIndexedInstanced(pCommandList.value, IndexCountPerInstance.value, InstanceCount.value, StartIndexLocation.value, BaseVertexLocation.value, StartInstanceLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListDispatch x12CommandListDispatch
#define _9b0aef4d_pCommandList(value) value
#define _9b0aef4d_ThreadGroupCountX(value) value
#define _9b0aef4d_ThreadGroupCountY(value) value
#define _9b0aef4d_ThreadGroupCountZ(value) value
#else
typedef struct _s_9b0aef4d_pCommandList { X12CommandList* value; } _s_9b0aef4d_pCommandList;
typedef struct _s_9b0aef4d_ThreadGroupCountX { unsigned value; } _s_9b0aef4d_ThreadGroupCountX;
typedef struct _s_9b0aef4d_ThreadGroupCountY { unsigned value; } _s_9b0aef4d_ThreadGroupCountY;
typedef struct _s_9b0aef4d_ThreadGroupCountZ { unsigned value; } _s_9b0aef4d_ThreadGroupCountZ;
static inline _s_9b0aef4d_pCommandList _9b0aef4d_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_9b0aef4d_pCommandList){value}; }
static inline _s_9b0aef4d_ThreadGroupCountX _9b0aef4d_ThreadGroupCountX(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9b0aef4d_ThreadGroupCountX){value}; }
static inline _s_9b0aef4d_ThreadGroupCountY _9b0aef4d_ThreadGroupCountY(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9b0aef4d_ThreadGroupCountY){value}; }
static inline _s_9b0aef4d_ThreadGroupCountZ _9b0aef4d_ThreadGroupCountZ(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9b0aef4d_ThreadGroupCountZ){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListDispatch(_s_9b0aef4d_pCommandList pCommandList, _s_9b0aef4d_ThreadGroupCountX ThreadGroupCountX, _s_9b0aef4d_ThreadGroupCountY ThreadGroupCountY, _s_9b0aef4d_ThreadGroupCountZ ThreadGroupCountZ) {
  x12CommandListDispatch(pCommandList.value, ThreadGroupCountX.value, ThreadGroupCountY.value, ThreadGroupCountZ.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetDescriptorHeaps x12CommandListSetDescriptorHeaps
#define _ff682668_pCommandList(value) value
#define _ff682668_NumDescriptorHeaps(value) value
#define _ff682668_ppDescriptorHeaps(value) value
#else
typedef struct _s_ff682668_pCommandList { X12CommandList* value; } _s_ff682668_pCommandList;
typedef struct _s_ff682668_NumDescriptorHeaps { unsigned value; } _s_ff682668_NumDescriptorHeaps;
typedef struct _s_ff682668_ppDescriptorHeaps { X12DescriptorHeap** value; } _s_ff682668_ppDescriptorHeaps;
static inline _s_ff682668_pCommandList _ff682668_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_ff682668_pCommandList){value}; }
static inline _s_ff682668_NumDescriptorHeaps _ff682668_NumDescriptorHeaps(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ff682668_NumDescriptorHeaps){value}; }
static inline _s_ff682668_ppDescriptorHeaps _ff682668_ppDescriptorHeaps(X12DescriptorHeap** value) { return REDGPU_NP_STRUCT_INIT(_s_ff682668_ppDescriptorHeaps){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetDescriptorHeaps(_s_ff682668_pCommandList pCommandList, _s_ff682668_NumDescriptorHeaps NumDescriptorHeaps, _s_ff682668_ppDescriptorHeaps ppDescriptorHeaps) {
  x12CommandListSetDescriptorHeaps(pCommandList.value, NumDescriptorHeaps.value, ppDescriptorHeaps.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRootSignature x12CommandListSetGraphicsRootSignature
#define _f9537293_pCommandList(value) value
#define _f9537293_pRootSignature(value) value
#else
typedef struct _s_f9537293_pCommandList { X12CommandList* value; } _s_f9537293_pCommandList;
typedef struct _s_f9537293_pRootSignature { X12RootSignature* value; } _s_f9537293_pRootSignature;
static inline _s_f9537293_pCommandList _f9537293_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_f9537293_pCommandList){value}; }
static inline _s_f9537293_pRootSignature _f9537293_pRootSignature(X12RootSignature* value) { return REDGPU_NP_STRUCT_INIT(_s_f9537293_pRootSignature){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRootSignature(_s_f9537293_pCommandList pCommandList, _s_f9537293_pRootSignature pRootSignature) {
  x12CommandListSetGraphicsRootSignature(pCommandList.value, pRootSignature.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRoot32BitConstant x12CommandListSetGraphicsRoot32BitConstant
#define _3379462e_pCommandList(value) value
#define _3379462e_RootParameterIndex(value) value
#define _3379462e_SrcData(value) value
#define _3379462e_DestOffsetIn32BitValues(value) value
#else
typedef struct _s_3379462e_pCommandList { X12CommandList* value; } _s_3379462e_pCommandList;
typedef struct _s_3379462e_RootParameterIndex { unsigned value; } _s_3379462e_RootParameterIndex;
typedef struct _s_3379462e_SrcData { unsigned value; } _s_3379462e_SrcData;
typedef struct _s_3379462e_DestOffsetIn32BitValues { unsigned value; } _s_3379462e_DestOffsetIn32BitValues;
static inline _s_3379462e_pCommandList _3379462e_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_3379462e_pCommandList){value}; }
static inline _s_3379462e_RootParameterIndex _3379462e_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3379462e_RootParameterIndex){value}; }
static inline _s_3379462e_SrcData _3379462e_SrcData(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3379462e_SrcData){value}; }
static inline _s_3379462e_DestOffsetIn32BitValues _3379462e_DestOffsetIn32BitValues(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3379462e_DestOffsetIn32BitValues){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRoot32BitConstant(_s_3379462e_pCommandList pCommandList, _s_3379462e_RootParameterIndex RootParameterIndex, _s_3379462e_SrcData SrcData, _s_3379462e_DestOffsetIn32BitValues DestOffsetIn32BitValues) {
  x12CommandListSetGraphicsRoot32BitConstant(pCommandList.value, RootParameterIndex.value, SrcData.value, DestOffsetIn32BitValues.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRoot32BitConstants x12CommandListSetGraphicsRoot32BitConstants
#define _22801cd1_pCommandList(value) value
#define _22801cd1_RootParameterIndex(value) value
#define _22801cd1_Num32BitValuesToSet(value) value
#define _22801cd1_pSrcData(value) value
#define _22801cd1_DestOffsetIn32BitValues(value) value
#else
typedef struct _s_22801cd1_pCommandList { X12CommandList* value; } _s_22801cd1_pCommandList;
typedef struct _s_22801cd1_RootParameterIndex { unsigned value; } _s_22801cd1_RootParameterIndex;
typedef struct _s_22801cd1_Num32BitValuesToSet { unsigned value; } _s_22801cd1_Num32BitValuesToSet;
typedef struct _s_22801cd1_pSrcData { void* value; } _s_22801cd1_pSrcData;
typedef struct _s_22801cd1_DestOffsetIn32BitValues { unsigned value; } _s_22801cd1_DestOffsetIn32BitValues;
static inline _s_22801cd1_pCommandList _22801cd1_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_22801cd1_pCommandList){value}; }
static inline _s_22801cd1_RootParameterIndex _22801cd1_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_22801cd1_RootParameterIndex){value}; }
static inline _s_22801cd1_Num32BitValuesToSet _22801cd1_Num32BitValuesToSet(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_22801cd1_Num32BitValuesToSet){value}; }
static inline _s_22801cd1_pSrcData _22801cd1_pSrcData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_22801cd1_pSrcData){value}; }
static inline _s_22801cd1_DestOffsetIn32BitValues _22801cd1_DestOffsetIn32BitValues(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_22801cd1_DestOffsetIn32BitValues){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRoot32BitConstants(_s_22801cd1_pCommandList pCommandList, _s_22801cd1_RootParameterIndex RootParameterIndex, _s_22801cd1_Num32BitValuesToSet Num32BitValuesToSet, _s_22801cd1_pSrcData pSrcData, _s_22801cd1_DestOffsetIn32BitValues DestOffsetIn32BitValues) {
  x12CommandListSetGraphicsRoot32BitConstants(pCommandList.value, RootParameterIndex.value, Num32BitValuesToSet.value, pSrcData.value, DestOffsetIn32BitValues.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRootDescriptorTable x12CommandListSetGraphicsRootDescriptorTable
#define _c49ea06a_pCommandList(value) value
#define _c49ea06a_RootParameterIndex(value) value
#define _c49ea06a_BaseDescriptor(value) value
#else
typedef struct _s_c49ea06a_pCommandList { X12CommandList* value; } _s_c49ea06a_pCommandList;
typedef struct _s_c49ea06a_RootParameterIndex { unsigned value; } _s_c49ea06a_RootParameterIndex;
typedef struct _s_c49ea06a_BaseDescriptor { D3D12_GPU_DESCRIPTOR_HANDLE value; } _s_c49ea06a_BaseDescriptor;
static inline _s_c49ea06a_pCommandList _c49ea06a_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_c49ea06a_pCommandList){value}; }
static inline _s_c49ea06a_RootParameterIndex _c49ea06a_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c49ea06a_RootParameterIndex){value}; }
static inline _s_c49ea06a_BaseDescriptor _c49ea06a_BaseDescriptor(D3D12_GPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_c49ea06a_BaseDescriptor){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRootDescriptorTable(_s_c49ea06a_pCommandList pCommandList, _s_c49ea06a_RootParameterIndex RootParameterIndex, _s_c49ea06a_BaseDescriptor BaseDescriptor) {
  x12CommandListSetGraphicsRootDescriptorTable(pCommandList.value, RootParameterIndex.value, BaseDescriptor.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRootUnorderedAccessView x12CommandListSetGraphicsRootUnorderedAccessView
#define _9cd0e741_pCommandList(value) value
#define _9cd0e741_RootParameterIndex(value) value
#define _9cd0e741_BufferLocation(value) value
#else
typedef struct _s_9cd0e741_pCommandList { X12CommandList* value; } _s_9cd0e741_pCommandList;
typedef struct _s_9cd0e741_RootParameterIndex { unsigned value; } _s_9cd0e741_RootParameterIndex;
typedef struct _s_9cd0e741_BufferLocation { D3D12_GPU_VIRTUAL_ADDRESS value; } _s_9cd0e741_BufferLocation;
static inline _s_9cd0e741_pCommandList _9cd0e741_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_9cd0e741_pCommandList){value}; }
static inline _s_9cd0e741_RootParameterIndex _9cd0e741_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9cd0e741_RootParameterIndex){value}; }
static inline _s_9cd0e741_BufferLocation _9cd0e741_BufferLocation(D3D12_GPU_VIRTUAL_ADDRESS value) { return REDGPU_NP_STRUCT_INIT(_s_9cd0e741_BufferLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRootUnorderedAccessView(_s_9cd0e741_pCommandList pCommandList, _s_9cd0e741_RootParameterIndex RootParameterIndex, _s_9cd0e741_BufferLocation BufferLocation) {
  x12CommandListSetGraphicsRootUnorderedAccessView(pCommandList.value, RootParameterIndex.value, BufferLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRootShaderResourceView x12CommandListSetGraphicsRootShaderResourceView
#define _abbf2dd4_pCommandList(value) value
#define _abbf2dd4_RootParameterIndex(value) value
#define _abbf2dd4_BufferLocation(value) value
#else
typedef struct _s_abbf2dd4_pCommandList { X12CommandList* value; } _s_abbf2dd4_pCommandList;
typedef struct _s_abbf2dd4_RootParameterIndex { unsigned value; } _s_abbf2dd4_RootParameterIndex;
typedef struct _s_abbf2dd4_BufferLocation { D3D12_GPU_VIRTUAL_ADDRESS value; } _s_abbf2dd4_BufferLocation;
static inline _s_abbf2dd4_pCommandList _abbf2dd4_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_abbf2dd4_pCommandList){value}; }
static inline _s_abbf2dd4_RootParameterIndex _abbf2dd4_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_abbf2dd4_RootParameterIndex){value}; }
static inline _s_abbf2dd4_BufferLocation _abbf2dd4_BufferLocation(D3D12_GPU_VIRTUAL_ADDRESS value) { return REDGPU_NP_STRUCT_INIT(_s_abbf2dd4_BufferLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRootShaderResourceView(_s_abbf2dd4_pCommandList pCommandList, _s_abbf2dd4_RootParameterIndex RootParameterIndex, _s_abbf2dd4_BufferLocation BufferLocation) {
  x12CommandListSetGraphicsRootShaderResourceView(pCommandList.value, RootParameterIndex.value, BufferLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRootConstantBufferView x12CommandListSetGraphicsRootConstantBufferView
#define _0541222e_pCommandList(value) value
#define _0541222e_RootParameterIndex(value) value
#define _0541222e_BufferLocation(value) value
#else
typedef struct _s_0541222e_pCommandList { X12CommandList* value; } _s_0541222e_pCommandList;
typedef struct _s_0541222e_RootParameterIndex { unsigned value; } _s_0541222e_RootParameterIndex;
typedef struct _s_0541222e_BufferLocation { D3D12_GPU_VIRTUAL_ADDRESS value; } _s_0541222e_BufferLocation;
static inline _s_0541222e_pCommandList _0541222e_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_0541222e_pCommandList){value}; }
static inline _s_0541222e_RootParameterIndex _0541222e_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_0541222e_RootParameterIndex){value}; }
static inline _s_0541222e_BufferLocation _0541222e_BufferLocation(D3D12_GPU_VIRTUAL_ADDRESS value) { return REDGPU_NP_STRUCT_INIT(_s_0541222e_BufferLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRootConstantBufferView(_s_0541222e_pCommandList pCommandList, _s_0541222e_RootParameterIndex RootParameterIndex, _s_0541222e_BufferLocation BufferLocation) {
  x12CommandListSetGraphicsRootConstantBufferView(pCommandList.value, RootParameterIndex.value, BufferLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRootSignature x12CommandListSetComputeRootSignature
#define _6cc0c2a5_pCommandList(value) value
#define _6cc0c2a5_pRootSignature(value) value
#else
typedef struct _s_6cc0c2a5_pCommandList { X12CommandList* value; } _s_6cc0c2a5_pCommandList;
typedef struct _s_6cc0c2a5_pRootSignature { X12RootSignature* value; } _s_6cc0c2a5_pRootSignature;
static inline _s_6cc0c2a5_pCommandList _6cc0c2a5_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_6cc0c2a5_pCommandList){value}; }
static inline _s_6cc0c2a5_pRootSignature _6cc0c2a5_pRootSignature(X12RootSignature* value) { return REDGPU_NP_STRUCT_INIT(_s_6cc0c2a5_pRootSignature){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRootSignature(_s_6cc0c2a5_pCommandList pCommandList, _s_6cc0c2a5_pRootSignature pRootSignature) {
  x12CommandListSetComputeRootSignature(pCommandList.value, pRootSignature.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRoot32BitConstant x12CommandListSetComputeRoot32BitConstant
#define _e86dfae9_pCommandList(value) value
#define _e86dfae9_RootParameterIndex(value) value
#define _e86dfae9_SrcData(value) value
#define _e86dfae9_DestOffsetIn32BitValues(value) value
#else
typedef struct _s_e86dfae9_pCommandList { X12CommandList* value; } _s_e86dfae9_pCommandList;
typedef struct _s_e86dfae9_RootParameterIndex { unsigned value; } _s_e86dfae9_RootParameterIndex;
typedef struct _s_e86dfae9_SrcData { unsigned value; } _s_e86dfae9_SrcData;
typedef struct _s_e86dfae9_DestOffsetIn32BitValues { unsigned value; } _s_e86dfae9_DestOffsetIn32BitValues;
static inline _s_e86dfae9_pCommandList _e86dfae9_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_e86dfae9_pCommandList){value}; }
static inline _s_e86dfae9_RootParameterIndex _e86dfae9_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e86dfae9_RootParameterIndex){value}; }
static inline _s_e86dfae9_SrcData _e86dfae9_SrcData(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e86dfae9_SrcData){value}; }
static inline _s_e86dfae9_DestOffsetIn32BitValues _e86dfae9_DestOffsetIn32BitValues(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e86dfae9_DestOffsetIn32BitValues){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRoot32BitConstant(_s_e86dfae9_pCommandList pCommandList, _s_e86dfae9_RootParameterIndex RootParameterIndex, _s_e86dfae9_SrcData SrcData, _s_e86dfae9_DestOffsetIn32BitValues DestOffsetIn32BitValues) {
  x12CommandListSetComputeRoot32BitConstant(pCommandList.value, RootParameterIndex.value, SrcData.value, DestOffsetIn32BitValues.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRoot32BitConstants x12CommandListSetComputeRoot32BitConstants
#define _598775b7_pCommandList(value) value
#define _598775b7_RootParameterIndex(value) value
#define _598775b7_Num32BitValuesToSet(value) value
#define _598775b7_pSrcData(value) value
#define _598775b7_DestOffsetIn32BitValues(value) value
#else
typedef struct _s_598775b7_pCommandList { X12CommandList* value; } _s_598775b7_pCommandList;
typedef struct _s_598775b7_RootParameterIndex { unsigned value; } _s_598775b7_RootParameterIndex;
typedef struct _s_598775b7_Num32BitValuesToSet { unsigned value; } _s_598775b7_Num32BitValuesToSet;
typedef struct _s_598775b7_pSrcData { void* value; } _s_598775b7_pSrcData;
typedef struct _s_598775b7_DestOffsetIn32BitValues { unsigned value; } _s_598775b7_DestOffsetIn32BitValues;
static inline _s_598775b7_pCommandList _598775b7_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_598775b7_pCommandList){value}; }
static inline _s_598775b7_RootParameterIndex _598775b7_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_598775b7_RootParameterIndex){value}; }
static inline _s_598775b7_Num32BitValuesToSet _598775b7_Num32BitValuesToSet(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_598775b7_Num32BitValuesToSet){value}; }
static inline _s_598775b7_pSrcData _598775b7_pSrcData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_598775b7_pSrcData){value}; }
static inline _s_598775b7_DestOffsetIn32BitValues _598775b7_DestOffsetIn32BitValues(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_598775b7_DestOffsetIn32BitValues){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRoot32BitConstants(_s_598775b7_pCommandList pCommandList, _s_598775b7_RootParameterIndex RootParameterIndex, _s_598775b7_Num32BitValuesToSet Num32BitValuesToSet, _s_598775b7_pSrcData pSrcData, _s_598775b7_DestOffsetIn32BitValues DestOffsetIn32BitValues) {
  x12CommandListSetComputeRoot32BitConstants(pCommandList.value, RootParameterIndex.value, Num32BitValuesToSet.value, pSrcData.value, DestOffsetIn32BitValues.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRootDescriptorTable x12CommandListSetComputeRootDescriptorTable
#define _b08d2bb8_pCommandList(value) value
#define _b08d2bb8_RootParameterIndex(value) value
#define _b08d2bb8_BaseDescriptor(value) value
#else
typedef struct _s_b08d2bb8_pCommandList { X12CommandList* value; } _s_b08d2bb8_pCommandList;
typedef struct _s_b08d2bb8_RootParameterIndex { unsigned value; } _s_b08d2bb8_RootParameterIndex;
typedef struct _s_b08d2bb8_BaseDescriptor { D3D12_GPU_DESCRIPTOR_HANDLE value; } _s_b08d2bb8_BaseDescriptor;
static inline _s_b08d2bb8_pCommandList _b08d2bb8_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_b08d2bb8_pCommandList){value}; }
static inline _s_b08d2bb8_RootParameterIndex _b08d2bb8_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b08d2bb8_RootParameterIndex){value}; }
static inline _s_b08d2bb8_BaseDescriptor _b08d2bb8_BaseDescriptor(D3D12_GPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_b08d2bb8_BaseDescriptor){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRootDescriptorTable(_s_b08d2bb8_pCommandList pCommandList, _s_b08d2bb8_RootParameterIndex RootParameterIndex, _s_b08d2bb8_BaseDescriptor BaseDescriptor) {
  x12CommandListSetComputeRootDescriptorTable(pCommandList.value, RootParameterIndex.value, BaseDescriptor.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRootUnorderedAccessView x12CommandListSetComputeRootUnorderedAccessView
#define _77839388_pCommandList(value) value
#define _77839388_RootParameterIndex(value) value
#define _77839388_BufferLocation(value) value
#else
typedef struct _s_77839388_pCommandList { X12CommandList* value; } _s_77839388_pCommandList;
typedef struct _s_77839388_RootParameterIndex { unsigned value; } _s_77839388_RootParameterIndex;
typedef struct _s_77839388_BufferLocation { D3D12_GPU_VIRTUAL_ADDRESS value; } _s_77839388_BufferLocation;
static inline _s_77839388_pCommandList _77839388_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_77839388_pCommandList){value}; }
static inline _s_77839388_RootParameterIndex _77839388_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_77839388_RootParameterIndex){value}; }
static inline _s_77839388_BufferLocation _77839388_BufferLocation(D3D12_GPU_VIRTUAL_ADDRESS value) { return REDGPU_NP_STRUCT_INIT(_s_77839388_BufferLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRootUnorderedAccessView(_s_77839388_pCommandList pCommandList, _s_77839388_RootParameterIndex RootParameterIndex, _s_77839388_BufferLocation BufferLocation) {
  x12CommandListSetComputeRootUnorderedAccessView(pCommandList.value, RootParameterIndex.value, BufferLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRootShaderResourceView x12CommandListSetComputeRootShaderResourceView
#define _be5a833e_pCommandList(value) value
#define _be5a833e_RootParameterIndex(value) value
#define _be5a833e_BufferLocation(value) value
#else
typedef struct _s_be5a833e_pCommandList { X12CommandList* value; } _s_be5a833e_pCommandList;
typedef struct _s_be5a833e_RootParameterIndex { unsigned value; } _s_be5a833e_RootParameterIndex;
typedef struct _s_be5a833e_BufferLocation { D3D12_GPU_VIRTUAL_ADDRESS value; } _s_be5a833e_BufferLocation;
static inline _s_be5a833e_pCommandList _be5a833e_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_be5a833e_pCommandList){value}; }
static inline _s_be5a833e_RootParameterIndex _be5a833e_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_be5a833e_RootParameterIndex){value}; }
static inline _s_be5a833e_BufferLocation _be5a833e_BufferLocation(D3D12_GPU_VIRTUAL_ADDRESS value) { return REDGPU_NP_STRUCT_INIT(_s_be5a833e_BufferLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRootShaderResourceView(_s_be5a833e_pCommandList pCommandList, _s_be5a833e_RootParameterIndex RootParameterIndex, _s_be5a833e_BufferLocation BufferLocation) {
  x12CommandListSetComputeRootShaderResourceView(pCommandList.value, RootParameterIndex.value, BufferLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRootConstantBufferView x12CommandListSetComputeRootConstantBufferView
#define _dc5411bc_pCommandList(value) value
#define _dc5411bc_RootParameterIndex(value) value
#define _dc5411bc_BufferLocation(value) value
#else
typedef struct _s_dc5411bc_pCommandList { X12CommandList* value; } _s_dc5411bc_pCommandList;
typedef struct _s_dc5411bc_RootParameterIndex { unsigned value; } _s_dc5411bc_RootParameterIndex;
typedef struct _s_dc5411bc_BufferLocation { D3D12_GPU_VIRTUAL_ADDRESS value; } _s_dc5411bc_BufferLocation;
static inline _s_dc5411bc_pCommandList _dc5411bc_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_dc5411bc_pCommandList){value}; }
static inline _s_dc5411bc_RootParameterIndex _dc5411bc_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_dc5411bc_RootParameterIndex){value}; }
static inline _s_dc5411bc_BufferLocation _dc5411bc_BufferLocation(D3D12_GPU_VIRTUAL_ADDRESS value) { return REDGPU_NP_STRUCT_INIT(_s_dc5411bc_BufferLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRootConstantBufferView(_s_dc5411bc_pCommandList pCommandList, _s_dc5411bc_RootParameterIndex RootParameterIndex, _s_dc5411bc_BufferLocation BufferLocation) {
  x12CommandListSetComputeRootConstantBufferView(pCommandList.value, RootParameterIndex.value, BufferLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListClearState x12CommandListClearState
#define _1393e4b5_pCommandList(value) value
#define _1393e4b5_pPipelineState(value) value
#else
typedef struct _s_1393e4b5_pCommandList { X12CommandList* value; } _s_1393e4b5_pCommandList;
typedef struct _s_1393e4b5_pPipelineState { X12PipelineState* value; } _s_1393e4b5_pPipelineState;
static inline _s_1393e4b5_pCommandList _1393e4b5_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_1393e4b5_pCommandList){value}; }
static inline _s_1393e4b5_pPipelineState _1393e4b5_pPipelineState(X12PipelineState* value) { return REDGPU_NP_STRUCT_INIT(_s_1393e4b5_pPipelineState){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListClearState(_s_1393e4b5_pCommandList pCommandList, _s_1393e4b5_pPipelineState pPipelineState) {
  x12CommandListClearState(pCommandList.value, pPipelineState.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetPipelineState x12CommandListSetPipelineState
#define _b38561d1_pCommandList(value) value
#define _b38561d1_pPipelineState(value) value
#else
typedef struct _s_b38561d1_pCommandList { X12CommandList* value; } _s_b38561d1_pCommandList;
typedef struct _s_b38561d1_pPipelineState { X12PipelineState* value; } _s_b38561d1_pPipelineState;
static inline _s_b38561d1_pCommandList _b38561d1_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_b38561d1_pCommandList){value}; }
static inline _s_b38561d1_pPipelineState _b38561d1_pPipelineState(X12PipelineState* value) { return REDGPU_NP_STRUCT_INIT(_s_b38561d1_pPipelineState){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetPipelineState(_s_b38561d1_pCommandList pCommandList, _s_b38561d1_pPipelineState pPipelineState) {
  x12CommandListSetPipelineState(pCommandList.value, pPipelineState.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListIASetPrimitiveTopology x12CommandListIASetPrimitiveTopology
#define _f2b85f62_pCommandList(value) value
#define _f2b85f62_PrimitiveTopology(value) value
#else
typedef struct _s_f2b85f62_pCommandList { X12CommandList* value; } _s_f2b85f62_pCommandList;
typedef struct _s_f2b85f62_PrimitiveTopology { D3D12_PRIMITIVE_TOPOLOGY value; } _s_f2b85f62_PrimitiveTopology;
static inline _s_f2b85f62_pCommandList _f2b85f62_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_f2b85f62_pCommandList){value}; }
static inline _s_f2b85f62_PrimitiveTopology _f2b85f62_PrimitiveTopology(D3D12_PRIMITIVE_TOPOLOGY value) { return REDGPU_NP_STRUCT_INIT(_s_f2b85f62_PrimitiveTopology){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListIASetPrimitiveTopology(_s_f2b85f62_pCommandList pCommandList, _s_f2b85f62_PrimitiveTopology PrimitiveTopology) {
  x12CommandListIASetPrimitiveTopology(pCommandList.value, PrimitiveTopology.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListIASetIndexBuffer x12CommandListIASetIndexBuffer
#define _bb6cc19d_pCommandList(value) value
#define _bb6cc19d_pView(value) value
#else
typedef struct _s_bb6cc19d_pCommandList { X12CommandList* value; } _s_bb6cc19d_pCommandList;
typedef struct _s_bb6cc19d_pView { D3D12_INDEX_BUFFER_VIEW* value; } _s_bb6cc19d_pView;
static inline _s_bb6cc19d_pCommandList _bb6cc19d_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_bb6cc19d_pCommandList){value}; }
static inline _s_bb6cc19d_pView _bb6cc19d_pView(D3D12_INDEX_BUFFER_VIEW* value) { return REDGPU_NP_STRUCT_INIT(_s_bb6cc19d_pView){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListIASetIndexBuffer(_s_bb6cc19d_pCommandList pCommandList, _s_bb6cc19d_pView pView) {
  x12CommandListIASetIndexBuffer(pCommandList.value, pView.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListOMSetStencilRef x12CommandListOMSetStencilRef
#define _52037b92_pCommandList(value) value
#define _52037b92_StencilRef(value) value
#else
typedef struct _s_52037b92_pCommandList { X12CommandList* value; } _s_52037b92_pCommandList;
typedef struct _s_52037b92_StencilRef { unsigned value; } _s_52037b92_StencilRef;
static inline _s_52037b92_pCommandList _52037b92_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_52037b92_pCommandList){value}; }
static inline _s_52037b92_StencilRef _52037b92_StencilRef(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_52037b92_StencilRef){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListOMSetStencilRef(_s_52037b92_pCommandList pCommandList, _s_52037b92_StencilRef StencilRef) {
  x12CommandListOMSetStencilRef(pCommandList.value, StencilRef.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListOMSetBlendFactor x12CommandListOMSetBlendFactor
#define _f1752472_pCommandList(value) value
#define _f1752472_BlendFactor4Values(value) value
#else
typedef struct _s_f1752472_pCommandList { X12CommandList* value; } _s_f1752472_pCommandList;
typedef struct _s_f1752472_BlendFactor4Values { float* value; } _s_f1752472_BlendFactor4Values;
static inline _s_f1752472_pCommandList _f1752472_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_f1752472_pCommandList){value}; }
static inline _s_f1752472_BlendFactor4Values _f1752472_BlendFactor4Values(float* value) { return REDGPU_NP_STRUCT_INIT(_s_f1752472_BlendFactor4Values){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListOMSetBlendFactor(_s_f1752472_pCommandList pCommandList, _s_f1752472_BlendFactor4Values BlendFactor4Values) {
  x12CommandListOMSetBlendFactor(pCommandList.value, BlendFactor4Values.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListRSSetViewports x12CommandListRSSetViewports
#define _62ac10ec_pCommandList(value) value
#define _62ac10ec_NumViewports(value) value
#define _62ac10ec_pViewports(value) value
#else
typedef struct _s_62ac10ec_pCommandList { X12CommandList* value; } _s_62ac10ec_pCommandList;
typedef struct _s_62ac10ec_NumViewports { unsigned value; } _s_62ac10ec_NumViewports;
typedef struct _s_62ac10ec_pViewports { D3D12_VIEWPORT* value; } _s_62ac10ec_pViewports;
static inline _s_62ac10ec_pCommandList _62ac10ec_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_62ac10ec_pCommandList){value}; }
static inline _s_62ac10ec_NumViewports _62ac10ec_NumViewports(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_62ac10ec_NumViewports){value}; }
static inline _s_62ac10ec_pViewports _62ac10ec_pViewports(D3D12_VIEWPORT* value) { return REDGPU_NP_STRUCT_INIT(_s_62ac10ec_pViewports){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListRSSetViewports(_s_62ac10ec_pCommandList pCommandList, _s_62ac10ec_NumViewports NumViewports, _s_62ac10ec_pViewports pViewports) {
  x12CommandListRSSetViewports(pCommandList.value, NumViewports.value, pViewports.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListRSSetScissorRects x12CommandListRSSetScissorRects
#define _b598625b_pCommandList(value) value
#define _b598625b_NumRects(value) value
#define _b598625b_pRects(value) value
#else
typedef struct _s_b598625b_pCommandList { X12CommandList* value; } _s_b598625b_pCommandList;
typedef struct _s_b598625b_NumRects { unsigned value; } _s_b598625b_NumRects;
typedef struct _s_b598625b_pRects { D3D12_RECT* value; } _s_b598625b_pRects;
static inline _s_b598625b_pCommandList _b598625b_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_b598625b_pCommandList){value}; }
static inline _s_b598625b_NumRects _b598625b_NumRects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b598625b_NumRects){value}; }
static inline _s_b598625b_pRects _b598625b_pRects(D3D12_RECT* value) { return REDGPU_NP_STRUCT_INIT(_s_b598625b_pRects){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListRSSetScissorRects(_s_b598625b_pCommandList pCommandList, _s_b598625b_NumRects NumRects, _s_b598625b_pRects pRects) {
  x12CommandListRSSetScissorRects(pCommandList.value, NumRects.value, pRects.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListClearRenderTargetView x12CommandListClearRenderTargetView
#define _46fb18e0_pCommandList(value) value
#define _46fb18e0_RenderTargetView(value) value
#define _46fb18e0_ColorRGBA[4](value) value
#define _46fb18e0_NumRects(value) value
#define _46fb18e0_pRects(value) value
#else
typedef struct _s_46fb18e0_pCommandList { X12CommandList* value; } _s_46fb18e0_pCommandList;
typedef struct _s_46fb18e0_RenderTargetView { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_46fb18e0_RenderTargetView;
typedef struct _s_46fb18e0_ColorRGBA[4] { float value; } _s_46fb18e0_ColorRGBA[4];
typedef struct _s_46fb18e0_NumRects { unsigned value; } _s_46fb18e0_NumRects;
typedef struct _s_46fb18e0_pRects { D3D12_RECT* value; } _s_46fb18e0_pRects;
static inline _s_46fb18e0_pCommandList _46fb18e0_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_46fb18e0_pCommandList){value}; }
static inline _s_46fb18e0_RenderTargetView _46fb18e0_RenderTargetView(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_46fb18e0_RenderTargetView){value}; }
static inline _s_46fb18e0_ColorRGBA[4] _46fb18e0_ColorRGBA[4](float value) { return REDGPU_NP_STRUCT_INIT(_s_46fb18e0_ColorRGBA[4]){value}; }
static inline _s_46fb18e0_NumRects _46fb18e0_NumRects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_46fb18e0_NumRects){value}; }
static inline _s_46fb18e0_pRects _46fb18e0_pRects(D3D12_RECT* value) { return REDGPU_NP_STRUCT_INIT(_s_46fb18e0_pRects){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListClearRenderTargetView(_s_46fb18e0_pCommandList pCommandList, _s_46fb18e0_RenderTargetView RenderTargetView, _s_46fb18e0_ColorRGBA[4] ColorRGBA[4], _s_46fb18e0_NumRects NumRects, _s_46fb18e0_pRects pRects) {
  x12CommandListClearRenderTargetView(pCommandList.value, RenderTargetView.value, ColorRGBA[4].value, NumRects.value, pRects.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListClearDepthStencilView x12CommandListClearDepthStencilView
#define _956cade0_pCommandList(value) value
#define _956cade0_DepthStencilView(value) value
#define _956cade0_ClearFlags(value) value
#define _956cade0_Depth(value) value
#define _956cade0_char(value) value
#define _956cade0_unsigned(value) value
#define _956cade0_D3D12_RECT*(value) value
#define _956cade0_(value) value
#else
typedef struct _s_956cade0_pCommandList { X12CommandList* value; } _s_956cade0_pCommandList;
typedef struct _s_956cade0_DepthStencilView { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_956cade0_DepthStencilView;
typedef struct _s_956cade0_ClearFlags { D3D12_CLEAR_FLAGS value; } _s_956cade0_ClearFlags;
typedef struct _s_956cade0_Depth { float value; } _s_956cade0_Depth;
typedef struct _s_956cade0_char { unsigned value; } _s_956cade0_char;
typedef struct _s_956cade0_unsigned { Stencil value; } _s_956cade0_unsigned;
typedef struct _s_956cade0_D3D12_RECT* { NumRects value; } _s_956cade0_D3D12_RECT*;
typedef struct _s_956cade0_ { pRects value; } _s_956cade0_;
static inline _s_956cade0_pCommandList _956cade0_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_956cade0_pCommandList){value}; }
static inline _s_956cade0_DepthStencilView _956cade0_DepthStencilView(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_956cade0_DepthStencilView){value}; }
static inline _s_956cade0_ClearFlags _956cade0_ClearFlags(D3D12_CLEAR_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_956cade0_ClearFlags){value}; }
static inline _s_956cade0_Depth _956cade0_Depth(float value) { return REDGPU_NP_STRUCT_INIT(_s_956cade0_Depth){value}; }
static inline _s_956cade0_char _956cade0_char(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_956cade0_char){value}; }
static inline _s_956cade0_unsigned _956cade0_unsigned(Stencil value) { return REDGPU_NP_STRUCT_INIT(_s_956cade0_unsigned){value}; }
static inline _s_956cade0_D3D12_RECT* _956cade0_D3D12_RECT*(NumRects value) { return REDGPU_NP_STRUCT_INIT(_s_956cade0_D3D12_RECT*){value}; }
static inline _s_956cade0_ _956cade0_(pRects value) { return REDGPU_NP_STRUCT_INIT(_s_956cade0_){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListClearDepthStencilView(_s_956cade0_pCommandList pCommandList, _s_956cade0_DepthStencilView DepthStencilView, _s_956cade0_ClearFlags ClearFlags, _s_956cade0_Depth Depth, _s_956cade0_char char, _s_956cade0_unsigned unsigned, _s_956cade0_D3D12_RECT* D3D12_RECT*, _s_956cade0_ ) {
  x12CommandListClearDepthStencilView(pCommandList.value, DepthStencilView.value, ClearFlags.value, Depth.value, char.value, unsigned.value, D3D12_RECT*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListDiscardResource x12CommandListDiscardResource
#define _f8c18bd3_pCommandList(value) value
#define _f8c18bd3_pResource(value) value
#define _f8c18bd3_pRegion(value) value
#else
typedef struct _s_f8c18bd3_pCommandList { X12CommandList* value; } _s_f8c18bd3_pCommandList;
typedef struct _s_f8c18bd3_pResource { X12Resource* value; } _s_f8c18bd3_pResource;
typedef struct _s_f8c18bd3_pRegion { D3D12_DISCARD_REGION* value; } _s_f8c18bd3_pRegion;
static inline _s_f8c18bd3_pCommandList _f8c18bd3_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_f8c18bd3_pCommandList){value}; }
static inline _s_f8c18bd3_pResource _f8c18bd3_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_f8c18bd3_pResource){value}; }
static inline _s_f8c18bd3_pRegion _f8c18bd3_pRegion(D3D12_DISCARD_REGION* value) { return REDGPU_NP_STRUCT_INIT(_s_f8c18bd3_pRegion){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListDiscardResource(_s_f8c18bd3_pCommandList pCommandList, _s_f8c18bd3_pResource pResource, _s_f8c18bd3_pRegion pRegion) {
  x12CommandListDiscardResource(pCommandList.value, pResource.value, pRegion.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListOMSetRenderTargets x12CommandListOMSetRenderTargets
#define _06b6812d_pCommandList(value) value
#define _06b6812d_NumRenderTargetDescriptors(value) value
#define _06b6812d_pRenderTargetDescriptors(value) value
#define _06b6812d_RTsSingleHandleToDescriptorRange(value) value
#define _06b6812d_pDepthStencilDescriptor(value) value
#else
typedef struct _s_06b6812d_pCommandList { X12CommandList* value; } _s_06b6812d_pCommandList;
typedef struct _s_06b6812d_NumRenderTargetDescriptors { unsigned value; } _s_06b6812d_NumRenderTargetDescriptors;
typedef struct _s_06b6812d_pRenderTargetDescriptors { D3D12_CPU_DESCRIPTOR_HANDLE* value; } _s_06b6812d_pRenderTargetDescriptors;
typedef struct _s_06b6812d_RTsSingleHandleToDescriptorRange { X12Bool value; } _s_06b6812d_RTsSingleHandleToDescriptorRange;
typedef struct _s_06b6812d_pDepthStencilDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE* value; } _s_06b6812d_pDepthStencilDescriptor;
static inline _s_06b6812d_pCommandList _06b6812d_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_06b6812d_pCommandList){value}; }
static inline _s_06b6812d_NumRenderTargetDescriptors _06b6812d_NumRenderTargetDescriptors(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_06b6812d_NumRenderTargetDescriptors){value}; }
static inline _s_06b6812d_pRenderTargetDescriptors _06b6812d_pRenderTargetDescriptors(D3D12_CPU_DESCRIPTOR_HANDLE* value) { return REDGPU_NP_STRUCT_INIT(_s_06b6812d_pRenderTargetDescriptors){value}; }
static inline _s_06b6812d_RTsSingleHandleToDescriptorRange _06b6812d_RTsSingleHandleToDescriptorRange(X12Bool value) { return REDGPU_NP_STRUCT_INIT(_s_06b6812d_RTsSingleHandleToDescriptorRange){value}; }
static inline _s_06b6812d_pDepthStencilDescriptor _06b6812d_pDepthStencilDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE* value) { return REDGPU_NP_STRUCT_INIT(_s_06b6812d_pDepthStencilDescriptor){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListOMSetRenderTargets(_s_06b6812d_pCommandList pCommandList, _s_06b6812d_NumRenderTargetDescriptors NumRenderTargetDescriptors, _s_06b6812d_pRenderTargetDescriptors pRenderTargetDescriptors, _s_06b6812d_RTsSingleHandleToDescriptorRange RTsSingleHandleToDescriptorRange, _s_06b6812d_pDepthStencilDescriptor pDepthStencilDescriptor) {
  x12CommandListOMSetRenderTargets(pCommandList.value, NumRenderTargetDescriptors.value, pRenderTargetDescriptors.value, RTsSingleHandleToDescriptorRange.value, pDepthStencilDescriptor.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListResolveSubresource x12CommandListResolveSubresource
#define _71889692_pCommandList(value) value
#define _71889692_pDstResource(value) value
#define _71889692_DstSubresource(value) value
#define _71889692_pSrcResource(value) value
#define _71889692_SrcSubresource(value) value
#define _71889692_Format(value) value
#else
typedef struct _s_71889692_pCommandList { X12CommandList* value; } _s_71889692_pCommandList;
typedef struct _s_71889692_pDstResource { X12Resource* value; } _s_71889692_pDstResource;
typedef struct _s_71889692_DstSubresource { unsigned value; } _s_71889692_DstSubresource;
typedef struct _s_71889692_pSrcResource { X12Resource* value; } _s_71889692_pSrcResource;
typedef struct _s_71889692_SrcSubresource { unsigned value; } _s_71889692_SrcSubresource;
typedef struct _s_71889692_Format { DXGI_FORMAT value; } _s_71889692_Format;
static inline _s_71889692_pCommandList _71889692_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_71889692_pCommandList){value}; }
static inline _s_71889692_pDstResource _71889692_pDstResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_71889692_pDstResource){value}; }
static inline _s_71889692_DstSubresource _71889692_DstSubresource(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_71889692_DstSubresource){value}; }
static inline _s_71889692_pSrcResource _71889692_pSrcResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_71889692_pSrcResource){value}; }
static inline _s_71889692_SrcSubresource _71889692_SrcSubresource(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_71889692_SrcSubresource){value}; }
static inline _s_71889692_Format _71889692_Format(DXGI_FORMAT value) { return REDGPU_NP_STRUCT_INIT(_s_71889692_Format){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListResolveSubresource(_s_71889692_pCommandList pCommandList, _s_71889692_pDstResource pDstResource, _s_71889692_DstSubresource DstSubresource, _s_71889692_pSrcResource pSrcResource, _s_71889692_SrcSubresource SrcSubresource, _s_71889692_Format Format) {
  x12CommandListResolveSubresource(pCommandList.value, pDstResource.value, DstSubresource.value, pSrcResource.value, SrcSubresource.value, Format.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListResourceBarrier x12CommandListResourceBarrier
#define _cfe6cc6b_pCommandList(value) value
#define _cfe6cc6b_NumBarriers(value) value
#define _cfe6cc6b_pBarriers(value) value
#else
typedef struct _s_cfe6cc6b_pCommandList { X12CommandList* value; } _s_cfe6cc6b_pCommandList;
typedef struct _s_cfe6cc6b_NumBarriers { unsigned value; } _s_cfe6cc6b_NumBarriers;
typedef struct _s_cfe6cc6b_pBarriers { D3D12_RESOURCE_BARRIER* value; } _s_cfe6cc6b_pBarriers;
static inline _s_cfe6cc6b_pCommandList _cfe6cc6b_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_cfe6cc6b_pCommandList){value}; }
static inline _s_cfe6cc6b_NumBarriers _cfe6cc6b_NumBarriers(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cfe6cc6b_NumBarriers){value}; }
static inline _s_cfe6cc6b_pBarriers _cfe6cc6b_pBarriers(D3D12_RESOURCE_BARRIER* value) { return REDGPU_NP_STRUCT_INIT(_s_cfe6cc6b_pBarriers){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListResourceBarrier(_s_cfe6cc6b_pCommandList pCommandList, _s_cfe6cc6b_NumBarriers NumBarriers, _s_cfe6cc6b_pBarriers pBarriers) {
  x12CommandListResourceBarrier(pCommandList.value, NumBarriers.value, pBarriers.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandQueueWait x12CommandQueueWait
#define _43ccea0e_pCommandQueue(value) value
#define _43ccea0e_pFence(value) value
#define _43ccea0e_Value(value) value
#define _43ccea0e_optionalFile(value) value
#define _43ccea0e_optionalLine(value) value
#else
typedef struct _s_43ccea0e_pCommandQueue { X12CommandQueue* value; } _s_43ccea0e_pCommandQueue;
typedef struct _s_43ccea0e_pFence { X12Fence* value; } _s_43ccea0e_pFence;
typedef struct _s_43ccea0e_Value { uint64_t value; } _s_43ccea0e_Value;
typedef struct _s_43ccea0e_optionalFile { char* value; } _s_43ccea0e_optionalFile;
typedef struct _s_43ccea0e_optionalLine { int value; } _s_43ccea0e_optionalLine;
static inline _s_43ccea0e_pCommandQueue _43ccea0e_pCommandQueue(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_43ccea0e_pCommandQueue){value}; }
static inline _s_43ccea0e_pFence _43ccea0e_pFence(X12Fence* value) { return REDGPU_NP_STRUCT_INIT(_s_43ccea0e_pFence){value}; }
static inline _s_43ccea0e_Value _43ccea0e_Value(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_43ccea0e_Value){value}; }
static inline _s_43ccea0e_optionalFile _43ccea0e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_43ccea0e_optionalFile){value}; }
static inline _s_43ccea0e_optionalLine _43ccea0e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_43ccea0e_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CommandQueueWait(_s_43ccea0e_pCommandQueue pCommandQueue, _s_43ccea0e_pFence pFence, _s_43ccea0e_Value Value, _s_43ccea0e_optionalFile optionalFile, _s_43ccea0e_optionalLine optionalLine) {
  return x12CommandQueueWait(pCommandQueue.value, pFence.value, Value.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandQueueExecuteCommandLists x12CommandQueueExecuteCommandLists
#define _0b49c663_pCommandQueue(value) value
#define _0b49c663_NumCommandLists(value) value
#define _0b49c663_ppCommandLists(value) value
#define _0b49c663_optionalFile(value) value
#define _0b49c663_optionalLine(value) value
#else
typedef struct _s_0b49c663_pCommandQueue { X12CommandQueue* value; } _s_0b49c663_pCommandQueue;
typedef struct _s_0b49c663_NumCommandLists { unsigned value; } _s_0b49c663_NumCommandLists;
typedef struct _s_0b49c663_ppCommandLists { X12CommandList** value; } _s_0b49c663_ppCommandLists;
typedef struct _s_0b49c663_optionalFile { char* value; } _s_0b49c663_optionalFile;
typedef struct _s_0b49c663_optionalLine { int value; } _s_0b49c663_optionalLine;
static inline _s_0b49c663_pCommandQueue _0b49c663_pCommandQueue(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_0b49c663_pCommandQueue){value}; }
static inline _s_0b49c663_NumCommandLists _0b49c663_NumCommandLists(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_0b49c663_NumCommandLists){value}; }
static inline _s_0b49c663_ppCommandLists _0b49c663_ppCommandLists(X12CommandList** value) { return REDGPU_NP_STRUCT_INIT(_s_0b49c663_ppCommandLists){value}; }
static inline _s_0b49c663_optionalFile _0b49c663_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0b49c663_optionalFile){value}; }
static inline _s_0b49c663_optionalLine _0b49c663_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0b49c663_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandQueueExecuteCommandLists(_s_0b49c663_pCommandQueue pCommandQueue, _s_0b49c663_NumCommandLists NumCommandLists, _s_0b49c663_ppCommandLists ppCommandLists, _s_0b49c663_optionalFile optionalFile, _s_0b49c663_optionalLine optionalLine) {
  x12CommandQueueExecuteCommandLists(pCommandQueue.value, NumCommandLists.value, ppCommandLists.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandQueueSignal x12CommandQueueSignal
#define _7ec05531_pCommandQueue(value) value
#define _7ec05531_pFence(value) value
#define _7ec05531_Value(value) value
#define _7ec05531_optionalFile(value) value
#define _7ec05531_optionalLine(value) value
#else
typedef struct _s_7ec05531_pCommandQueue { X12CommandQueue* value; } _s_7ec05531_pCommandQueue;
typedef struct _s_7ec05531_pFence { X12Fence* value; } _s_7ec05531_pFence;
typedef struct _s_7ec05531_Value { uint64_t value; } _s_7ec05531_Value;
typedef struct _s_7ec05531_optionalFile { char* value; } _s_7ec05531_optionalFile;
typedef struct _s_7ec05531_optionalLine { int value; } _s_7ec05531_optionalLine;
static inline _s_7ec05531_pCommandQueue _7ec05531_pCommandQueue(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_7ec05531_pCommandQueue){value}; }
static inline _s_7ec05531_pFence _7ec05531_pFence(X12Fence* value) { return REDGPU_NP_STRUCT_INIT(_s_7ec05531_pFence){value}; }
static inline _s_7ec05531_Value _7ec05531_Value(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_7ec05531_Value){value}; }
static inline _s_7ec05531_optionalFile _7ec05531_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7ec05531_optionalFile){value}; }
static inline _s_7ec05531_optionalLine _7ec05531_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7ec05531_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CommandQueueSignal(_s_7ec05531_pCommandQueue pCommandQueue, _s_7ec05531_pFence pFence, _s_7ec05531_Value Value, _s_7ec05531_optionalFile optionalFile, _s_7ec05531_optionalLine optionalLine) {
  return x12CommandQueueSignal(pCommandQueue.value, pFence.value, Value.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryIsCurrent x12FactoryIsCurrent
#define _4170edb2_pFactory(value) value
#define _4170edb2_optionalFile(value) value
#define _4170edb2_optionalLine(value) value
#else
typedef struct _s_4170edb2_pFactory { X12Factory4* value; } _s_4170edb2_pFactory;
typedef struct _s_4170edb2_optionalFile { char* value; } _s_4170edb2_optionalFile;
typedef struct _s_4170edb2_optionalLine { int value; } _s_4170edb2_optionalLine;
static inline _s_4170edb2_pFactory _4170edb2_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_4170edb2_pFactory){value}; }
static inline _s_4170edb2_optionalFile _4170edb2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4170edb2_optionalFile){value}; }
static inline _s_4170edb2_optionalLine _4170edb2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4170edb2_optionalLine){value}; }
REDGPU_NP_DECLSPEC X12Bool REDGPU_NP_API np_x12FactoryIsCurrent(_s_4170edb2_pFactory pFactory, _s_4170edb2_optionalFile optionalFile, _s_4170edb2_optionalLine optionalLine) {
  return x12FactoryIsCurrent(pFactory.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12AdapterGetDesc2 x12AdapterGetDesc2
#define _08fe2fc2_pAdapter(value) value
#define _08fe2fc2_outDesc(value) value
#define _08fe2fc2_optionalFile(value) value
#define _08fe2fc2_optionalLine(value) value
#else
typedef struct _s_08fe2fc2_pAdapter { X12Adapter3* value; } _s_08fe2fc2_pAdapter;
typedef struct _s_08fe2fc2_outDesc { DXGI_ADAPTER_DESC2* value; } _s_08fe2fc2_outDesc;
typedef struct _s_08fe2fc2_optionalFile { char* value; } _s_08fe2fc2_optionalFile;
typedef struct _s_08fe2fc2_optionalLine { int value; } _s_08fe2fc2_optionalLine;
static inline _s_08fe2fc2_pAdapter _08fe2fc2_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_08fe2fc2_pAdapter){value}; }
static inline _s_08fe2fc2_outDesc _08fe2fc2_outDesc(DXGI_ADAPTER_DESC2* value) { return REDGPU_NP_STRUCT_INIT(_s_08fe2fc2_outDesc){value}; }
static inline _s_08fe2fc2_optionalFile _08fe2fc2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_08fe2fc2_optionalFile){value}; }
static inline _s_08fe2fc2_optionalLine _08fe2fc2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_08fe2fc2_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12AdapterGetDesc2(_s_08fe2fc2_pAdapter pAdapter, _s_08fe2fc2_outDesc outDesc, _s_08fe2fc2_optionalFile optionalFile, _s_08fe2fc2_optionalLine optionalLine) {
  return x12AdapterGetDesc2(pAdapter.value, outDesc.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12AdapterEnumOutputs x12AdapterEnumOutputs
#define _a1b771af_pAdapter(value) value
#define _a1b771af_Output(value) value
#define _a1b771af_outpOutput(value) value
#define _a1b771af_optionalFile(value) value
#define _a1b771af_optionalLine(value) value
#else
typedef struct _s_a1b771af_pAdapter { X12Adapter3* value; } _s_a1b771af_pAdapter;
typedef struct _s_a1b771af_Output { unsigned value; } _s_a1b771af_Output;
typedef struct _s_a1b771af_outpOutput { X12Output4** value; } _s_a1b771af_outpOutput;
typedef struct _s_a1b771af_optionalFile { char* value; } _s_a1b771af_optionalFile;
typedef struct _s_a1b771af_optionalLine { int value; } _s_a1b771af_optionalLine;
static inline _s_a1b771af_pAdapter _a1b771af_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_a1b771af_pAdapter){value}; }
static inline _s_a1b771af_Output _a1b771af_Output(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a1b771af_Output){value}; }
static inline _s_a1b771af_outpOutput _a1b771af_outpOutput(X12Output4** value) { return REDGPU_NP_STRUCT_INIT(_s_a1b771af_outpOutput){value}; }
static inline _s_a1b771af_optionalFile _a1b771af_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a1b771af_optionalFile){value}; }
static inline _s_a1b771af_optionalLine _a1b771af_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a1b771af_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12AdapterEnumOutputs(_s_a1b771af_pAdapter pAdapter, _s_a1b771af_Output Output, _s_a1b771af_outpOutput outpOutput, _s_a1b771af_optionalFile optionalFile, _s_a1b771af_optionalLine optionalLine) {
  return x12AdapterEnumOutputs(pAdapter.value, Output.value, outpOutput.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceGetAdapterLuid x12DeviceGetAdapterLuid
#define _06f5b26f_pDevice(value) value
#define _06f5b26f_outLuid(value) value
#define _06f5b26f_optionalFile(value) value
#define _06f5b26f_optionalLine(value) value
#else
typedef struct _s_06f5b26f_pDevice { X12Device3* value; } _s_06f5b26f_pDevice;
typedef struct _s_06f5b26f_outLuid { uint64_t* value; } _s_06f5b26f_outLuid;
typedef struct _s_06f5b26f_optionalFile { char* value; } _s_06f5b26f_optionalFile;
typedef struct _s_06f5b26f_optionalLine { int value; } _s_06f5b26f_optionalLine;
static inline _s_06f5b26f_pDevice _06f5b26f_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_06f5b26f_pDevice){value}; }
static inline _s_06f5b26f_outLuid _06f5b26f_outLuid(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_06f5b26f_outLuid){value}; }
static inline _s_06f5b26f_optionalFile _06f5b26f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_06f5b26f_optionalFile){value}; }
static inline _s_06f5b26f_optionalLine _06f5b26f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_06f5b26f_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceGetAdapterLuid(_s_06f5b26f_pDevice pDevice, _s_06f5b26f_outLuid outLuid, _s_06f5b26f_optionalFile optionalFile, _s_06f5b26f_optionalLine optionalLine) {
  x12DeviceGetAdapterLuid(pDevice.value, outLuid.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceGetDescriptorHandleIncrementSize x12DeviceGetDescriptorHandleIncrementSize
#define _4df2ab4b_pDevice(value) value
#define _4df2ab4b_DescriptorHeapType(value) value
#define _4df2ab4b_optionalFile(value) value
#define _4df2ab4b_optionalLine(value) value
#else
typedef struct _s_4df2ab4b_pDevice { X12Device3* value; } _s_4df2ab4b_pDevice;
typedef struct _s_4df2ab4b_DescriptorHeapType { D3D12_DESCRIPTOR_HEAP_TYPE value; } _s_4df2ab4b_DescriptorHeapType;
typedef struct _s_4df2ab4b_optionalFile { char* value; } _s_4df2ab4b_optionalFile;
typedef struct _s_4df2ab4b_optionalLine { int value; } _s_4df2ab4b_optionalLine;
static inline _s_4df2ab4b_pDevice _4df2ab4b_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_4df2ab4b_pDevice){value}; }
static inline _s_4df2ab4b_DescriptorHeapType _4df2ab4b_DescriptorHeapType(D3D12_DESCRIPTOR_HEAP_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_4df2ab4b_DescriptorHeapType){value}; }
static inline _s_4df2ab4b_optionalFile _4df2ab4b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4df2ab4b_optionalFile){value}; }
static inline _s_4df2ab4b_optionalLine _4df2ab4b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4df2ab4b_optionalLine){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_x12DeviceGetDescriptorHandleIncrementSize(_s_4df2ab4b_pDevice pDevice, _s_4df2ab4b_DescriptorHeapType DescriptorHeapType, _s_4df2ab4b_optionalFile optionalFile, _s_4df2ab4b_optionalLine optionalLine) {
  return x12DeviceGetDescriptorHandleIncrementSize(pDevice.value, DescriptorHeapType.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCheckFeatureSupport x12DeviceCheckFeatureSupport
#define _3395267d_pDevice(value) value
#define _3395267d_Feature(value) value
#define _3395267d_pFeatureSupportData(value) value
#define _3395267d_FeatureSupportDataSize(value) value
#define _3395267d_optionalFile(value) value
#define _3395267d_optionalLine(value) value
#else
typedef struct _s_3395267d_pDevice { X12Device3* value; } _s_3395267d_pDevice;
typedef struct _s_3395267d_Feature { D3D12_FEATURE value; } _s_3395267d_Feature;
typedef struct _s_3395267d_pFeatureSupportData { void* value; } _s_3395267d_pFeatureSupportData;
typedef struct _s_3395267d_FeatureSupportDataSize { unsigned value; } _s_3395267d_FeatureSupportDataSize;
typedef struct _s_3395267d_optionalFile { char* value; } _s_3395267d_optionalFile;
typedef struct _s_3395267d_optionalLine { int value; } _s_3395267d_optionalLine;
static inline _s_3395267d_pDevice _3395267d_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_3395267d_pDevice){value}; }
static inline _s_3395267d_Feature _3395267d_Feature(D3D12_FEATURE value) { return REDGPU_NP_STRUCT_INIT(_s_3395267d_Feature){value}; }
static inline _s_3395267d_pFeatureSupportData _3395267d_pFeatureSupportData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3395267d_pFeatureSupportData){value}; }
static inline _s_3395267d_FeatureSupportDataSize _3395267d_FeatureSupportDataSize(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3395267d_FeatureSupportDataSize){value}; }
static inline _s_3395267d_optionalFile _3395267d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3395267d_optionalFile){value}; }
static inline _s_3395267d_optionalLine _3395267d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3395267d_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCheckFeatureSupport(_s_3395267d_pDevice pDevice, _s_3395267d_Feature Feature, _s_3395267d_pFeatureSupportData pFeatureSupportData, _s_3395267d_FeatureSupportDataSize FeatureSupportDataSize, _s_3395267d_optionalFile optionalFile, _s_3395267d_optionalLine optionalLine) {
  return x12DeviceCheckFeatureSupport(pDevice.value, Feature.value, pFeatureSupportData.value, FeatureSupportDataSize.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceGetDeviceRemovedReason x12DeviceGetDeviceRemovedReason
#define _734e4ed4_pDevice(value) value
#define _734e4ed4_optionalFile(value) value
#define _734e4ed4_optionalLine(value) value
#else
typedef struct _s_734e4ed4_pDevice { X12Device3* value; } _s_734e4ed4_pDevice;
typedef struct _s_734e4ed4_optionalFile { char* value; } _s_734e4ed4_optionalFile;
typedef struct _s_734e4ed4_optionalLine { int value; } _s_734e4ed4_optionalLine;
static inline _s_734e4ed4_pDevice _734e4ed4_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_734e4ed4_pDevice){value}; }
static inline _s_734e4ed4_optionalFile _734e4ed4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_734e4ed4_optionalFile){value}; }
static inline _s_734e4ed4_optionalLine _734e4ed4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_734e4ed4_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceGetDeviceRemovedReason(_s_734e4ed4_pDevice pDevice, _s_734e4ed4_optionalFile optionalFile, _s_734e4ed4_optionalLine optionalLine) {
  return x12DeviceGetDeviceRemovedReason(pDevice.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceSetStablePowerState x12DeviceSetStablePowerState
#define _5d90ff03_pDevice(value) value
#define _5d90ff03_Enable(value) value
#define _5d90ff03_optionalFile(value) value
#define _5d90ff03_optionalLine(value) value
#else
typedef struct _s_5d90ff03_pDevice { X12Device3* value; } _s_5d90ff03_pDevice;
typedef struct _s_5d90ff03_Enable { X12Bool value; } _s_5d90ff03_Enable;
typedef struct _s_5d90ff03_optionalFile { char* value; } _s_5d90ff03_optionalFile;
typedef struct _s_5d90ff03_optionalLine { int value; } _s_5d90ff03_optionalLine;
static inline _s_5d90ff03_pDevice _5d90ff03_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_5d90ff03_pDevice){value}; }
static inline _s_5d90ff03_Enable _5d90ff03_Enable(X12Bool value) { return REDGPU_NP_STRUCT_INIT(_s_5d90ff03_Enable){value}; }
static inline _s_5d90ff03_optionalFile _5d90ff03_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5d90ff03_optionalFile){value}; }
static inline _s_5d90ff03_optionalLine _5d90ff03_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5d90ff03_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceSetStablePowerState(_s_5d90ff03_pDevice pDevice, _s_5d90ff03_Enable Enable, _s_5d90ff03_optionalFile optionalFile, _s_5d90ff03_optionalLine optionalLine) {
  return x12DeviceSetStablePowerState(pDevice.value, Enable.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryCreateSwapChainForHwnd x12FactoryCreateSwapChainForHwnd
#define _cf57aa2d_pFactory(value) value
#define _cf57aa2d_pCommandQueue(value) value
#define _cf57aa2d_hWnd(value) value
#define _cf57aa2d_pDesc(value) value
#define _cf57aa2d_pFullscreenDesc(value) value
#define _cf57aa2d_pRestrictToOutput(value) value
#define _cf57aa2d_outpSwapChain(value) value
#define _cf57aa2d_optionalFile(value) value
#define _cf57aa2d_optionalLine(value) value
#else
typedef struct _s_cf57aa2d_pFactory { X12Factory4* value; } _s_cf57aa2d_pFactory;
typedef struct _s_cf57aa2d_pCommandQueue { X12CommandQueue* value; } _s_cf57aa2d_pCommandQueue;
typedef struct _s_cf57aa2d_hWnd { void* value; } _s_cf57aa2d_hWnd;
typedef struct _s_cf57aa2d_pDesc { DXGI_SWAP_CHAIN_DESC1* value; } _s_cf57aa2d_pDesc;
typedef struct _s_cf57aa2d_pFullscreenDesc { DXGI_SWAP_CHAIN_FULLSCREEN_DESC* value; } _s_cf57aa2d_pFullscreenDesc;
typedef struct _s_cf57aa2d_pRestrictToOutput { X12Output4* value; } _s_cf57aa2d_pRestrictToOutput;
typedef struct _s_cf57aa2d_outpSwapChain { X12SwapChain3** value; } _s_cf57aa2d_outpSwapChain;
typedef struct _s_cf57aa2d_optionalFile { char* value; } _s_cf57aa2d_optionalFile;
typedef struct _s_cf57aa2d_optionalLine { int value; } _s_cf57aa2d_optionalLine;
static inline _s_cf57aa2d_pFactory _cf57aa2d_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_cf57aa2d_pFactory){value}; }
static inline _s_cf57aa2d_pCommandQueue _cf57aa2d_pCommandQueue(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_cf57aa2d_pCommandQueue){value}; }
static inline _s_cf57aa2d_hWnd _cf57aa2d_hWnd(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cf57aa2d_hWnd){value}; }
static inline _s_cf57aa2d_pDesc _cf57aa2d_pDesc(DXGI_SWAP_CHAIN_DESC1* value) { return REDGPU_NP_STRUCT_INIT(_s_cf57aa2d_pDesc){value}; }
static inline _s_cf57aa2d_pFullscreenDesc _cf57aa2d_pFullscreenDesc(DXGI_SWAP_CHAIN_FULLSCREEN_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_cf57aa2d_pFullscreenDesc){value}; }
static inline _s_cf57aa2d_pRestrictToOutput _cf57aa2d_pRestrictToOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_cf57aa2d_pRestrictToOutput){value}; }
static inline _s_cf57aa2d_outpSwapChain _cf57aa2d_outpSwapChain(X12SwapChain3** value) { return REDGPU_NP_STRUCT_INIT(_s_cf57aa2d_outpSwapChain){value}; }
static inline _s_cf57aa2d_optionalFile _cf57aa2d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cf57aa2d_optionalFile){value}; }
static inline _s_cf57aa2d_optionalLine _cf57aa2d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cf57aa2d_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryCreateSwapChainForHwnd(_s_cf57aa2d_pFactory pFactory, _s_cf57aa2d_pCommandQueue pCommandQueue, _s_cf57aa2d_hWnd hWnd, _s_cf57aa2d_pDesc pDesc, _s_cf57aa2d_pFullscreenDesc pFullscreenDesc, _s_cf57aa2d_pRestrictToOutput pRestrictToOutput, _s_cf57aa2d_outpSwapChain outpSwapChain, _s_cf57aa2d_optionalFile optionalFile, _s_cf57aa2d_optionalLine optionalLine) {
  return x12FactoryCreateSwapChainForHwnd(pFactory.value, pCommandQueue.value, hWnd.value, pDesc.value, pFullscreenDesc.value, pRestrictToOutput.value, outpSwapChain.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryCreateSwapChainForCoreWindow x12FactoryCreateSwapChainForCoreWindow
#define _db201ad8_pFactory(value) value
#define _db201ad8_pCommandQueue(value) value
#define _db201ad8_pWindow(value) value
#define _db201ad8_pDesc(value) value
#define _db201ad8_pRestrictToOutput(value) value
#define _db201ad8_outpSwapChain(value) value
#define _db201ad8_optionalFile(value) value
#define _db201ad8_optionalLine(value) value
#else
typedef struct _s_db201ad8_pFactory { X12Factory4* value; } _s_db201ad8_pFactory;
typedef struct _s_db201ad8_pCommandQueue { X12CommandQueue* value; } _s_db201ad8_pCommandQueue;
typedef struct _s_db201ad8_pWindow { void* value; } _s_db201ad8_pWindow;
typedef struct _s_db201ad8_pDesc { DXGI_SWAP_CHAIN_DESC1* value; } _s_db201ad8_pDesc;
typedef struct _s_db201ad8_pRestrictToOutput { X12Output4* value; } _s_db201ad8_pRestrictToOutput;
typedef struct _s_db201ad8_outpSwapChain { X12SwapChain3** value; } _s_db201ad8_outpSwapChain;
typedef struct _s_db201ad8_optionalFile { char* value; } _s_db201ad8_optionalFile;
typedef struct _s_db201ad8_optionalLine { int value; } _s_db201ad8_optionalLine;
static inline _s_db201ad8_pFactory _db201ad8_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_db201ad8_pFactory){value}; }
static inline _s_db201ad8_pCommandQueue _db201ad8_pCommandQueue(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_db201ad8_pCommandQueue){value}; }
static inline _s_db201ad8_pWindow _db201ad8_pWindow(void* value) { return REDGPU_NP_STRUCT_INIT(_s_db201ad8_pWindow){value}; }
static inline _s_db201ad8_pDesc _db201ad8_pDesc(DXGI_SWAP_CHAIN_DESC1* value) { return REDGPU_NP_STRUCT_INIT(_s_db201ad8_pDesc){value}; }
static inline _s_db201ad8_pRestrictToOutput _db201ad8_pRestrictToOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_db201ad8_pRestrictToOutput){value}; }
static inline _s_db201ad8_outpSwapChain _db201ad8_outpSwapChain(X12SwapChain3** value) { return REDGPU_NP_STRUCT_INIT(_s_db201ad8_outpSwapChain){value}; }
static inline _s_db201ad8_optionalFile _db201ad8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_db201ad8_optionalFile){value}; }
static inline _s_db201ad8_optionalLine _db201ad8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_db201ad8_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryCreateSwapChainForCoreWindow(_s_db201ad8_pFactory pFactory, _s_db201ad8_pCommandQueue pCommandQueue, _s_db201ad8_pWindow pWindow, _s_db201ad8_pDesc pDesc, _s_db201ad8_pRestrictToOutput pRestrictToOutput, _s_db201ad8_outpSwapChain outpSwapChain, _s_db201ad8_optionalFile optionalFile, _s_db201ad8_optionalLine optionalLine) {
  return x12FactoryCreateSwapChainForCoreWindow(pFactory.value, pCommandQueue.value, pWindow.value, pDesc.value, pRestrictToOutput.value, outpSwapChain.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryCreateSwapChainForComposition x12FactoryCreateSwapChainForComposition
#define _d171f464_pFactory(value) value
#define _d171f464_pCommandQueue(value) value
#define _d171f464_pDesc(value) value
#define _d171f464_pRestrictToOutput(value) value
#define _d171f464_outpSwapChain(value) value
#define _d171f464_optionalFile(value) value
#define _d171f464_optionalLine(value) value
#else
typedef struct _s_d171f464_pFactory { X12Factory4* value; } _s_d171f464_pFactory;
typedef struct _s_d171f464_pCommandQueue { X12CommandQueue* value; } _s_d171f464_pCommandQueue;
typedef struct _s_d171f464_pDesc { DXGI_SWAP_CHAIN_DESC1* value; } _s_d171f464_pDesc;
typedef struct _s_d171f464_pRestrictToOutput { X12Output4* value; } _s_d171f464_pRestrictToOutput;
typedef struct _s_d171f464_outpSwapChain { X12SwapChain3** value; } _s_d171f464_outpSwapChain;
typedef struct _s_d171f464_optionalFile { char* value; } _s_d171f464_optionalFile;
typedef struct _s_d171f464_optionalLine { int value; } _s_d171f464_optionalLine;
static inline _s_d171f464_pFactory _d171f464_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_d171f464_pFactory){value}; }
static inline _s_d171f464_pCommandQueue _d171f464_pCommandQueue(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_d171f464_pCommandQueue){value}; }
static inline _s_d171f464_pDesc _d171f464_pDesc(DXGI_SWAP_CHAIN_DESC1* value) { return REDGPU_NP_STRUCT_INIT(_s_d171f464_pDesc){value}; }
static inline _s_d171f464_pRestrictToOutput _d171f464_pRestrictToOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_d171f464_pRestrictToOutput){value}; }
static inline _s_d171f464_outpSwapChain _d171f464_outpSwapChain(X12SwapChain3** value) { return REDGPU_NP_STRUCT_INIT(_s_d171f464_outpSwapChain){value}; }
static inline _s_d171f464_optionalFile _d171f464_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d171f464_optionalFile){value}; }
static inline _s_d171f464_optionalLine _d171f464_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d171f464_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryCreateSwapChainForComposition(_s_d171f464_pFactory pFactory, _s_d171f464_pCommandQueue pCommandQueue, _s_d171f464_pDesc pDesc, _s_d171f464_pRestrictToOutput pRestrictToOutput, _s_d171f464_outpSwapChain outpSwapChain, _s_d171f464_optionalFile optionalFile, _s_d171f464_optionalLine optionalLine) {
  return x12FactoryCreateSwapChainForComposition(pFactory.value, pCommandQueue.value, pDesc.value, pRestrictToOutput.value, outpSwapChain.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryMakeWindowAssociation x12FactoryMakeWindowAssociation
#define _1f51f54b_pFactory(value) value
#define _1f51f54b_WindowHandle(value) value
#define _1f51f54b_Flags(value) value
#define _1f51f54b_optionalFile(value) value
#define _1f51f54b_optionalLine(value) value
#else
typedef struct _s_1f51f54b_pFactory { X12Factory4* value; } _s_1f51f54b_pFactory;
typedef struct _s_1f51f54b_WindowHandle { void* value; } _s_1f51f54b_WindowHandle;
typedef struct _s_1f51f54b_Flags { DXGI_MWA_FLAGS value; } _s_1f51f54b_Flags;
typedef struct _s_1f51f54b_optionalFile { char* value; } _s_1f51f54b_optionalFile;
typedef struct _s_1f51f54b_optionalLine { int value; } _s_1f51f54b_optionalLine;
static inline _s_1f51f54b_pFactory _1f51f54b_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_1f51f54b_pFactory){value}; }
static inline _s_1f51f54b_WindowHandle _1f51f54b_WindowHandle(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1f51f54b_WindowHandle){value}; }
static inline _s_1f51f54b_Flags _1f51f54b_Flags(DXGI_MWA_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_1f51f54b_Flags){value}; }
static inline _s_1f51f54b_optionalFile _1f51f54b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1f51f54b_optionalFile){value}; }
static inline _s_1f51f54b_optionalLine _1f51f54b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1f51f54b_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryMakeWindowAssociation(_s_1f51f54b_pFactory pFactory, _s_1f51f54b_WindowHandle WindowHandle, _s_1f51f54b_Flags Flags, _s_1f51f54b_optionalFile optionalFile, _s_1f51f54b_optionalLine optionalLine) {
  return x12FactoryMakeWindowAssociation(pFactory.value, WindowHandle.value, Flags.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryGetWindowAssociation x12FactoryGetWindowAssociation
#define _4a2f44c1_pFactory(value) value
#define _4a2f44c1_outWindowHandle(value) value
#define _4a2f44c1_optionalFile(value) value
#define _4a2f44c1_optionalLine(value) value
#else
typedef struct _s_4a2f44c1_pFactory { X12Factory4* value; } _s_4a2f44c1_pFactory;
typedef struct _s_4a2f44c1_outWindowHandle { void** value; } _s_4a2f44c1_outWindowHandle;
typedef struct _s_4a2f44c1_optionalFile { char* value; } _s_4a2f44c1_optionalFile;
typedef struct _s_4a2f44c1_optionalLine { int value; } _s_4a2f44c1_optionalLine;
static inline _s_4a2f44c1_pFactory _4a2f44c1_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_4a2f44c1_pFactory){value}; }
static inline _s_4a2f44c1_outWindowHandle _4a2f44c1_outWindowHandle(void** value) { return REDGPU_NP_STRUCT_INIT(_s_4a2f44c1_outWindowHandle){value}; }
static inline _s_4a2f44c1_optionalFile _4a2f44c1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4a2f44c1_optionalFile){value}; }
static inline _s_4a2f44c1_optionalLine _4a2f44c1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4a2f44c1_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryGetWindowAssociation(_s_4a2f44c1_pFactory pFactory, _s_4a2f44c1_outWindowHandle outWindowHandle, _s_4a2f44c1_optionalFile optionalFile, _s_4a2f44c1_optionalLine optionalLine) {
  return x12FactoryGetWindowAssociation(pFactory.value, outWindowHandle.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryRegisterOcclusionStatusWindow x12FactoryRegisterOcclusionStatusWindow
#define _0f119ea6_pFactory(value) value
#define _0f119ea6_WindowHandle(value) value
#define _0f119ea6_wMsg(value) value
#define _0f119ea6_pdwCookie(value) value
#define _0f119ea6_optionalFile(value) value
#define _0f119ea6_optionalLine(value) value
#else
typedef struct _s_0f119ea6_pFactory { X12Factory4* value; } _s_0f119ea6_pFactory;
typedef struct _s_0f119ea6_WindowHandle { void* value; } _s_0f119ea6_WindowHandle;
typedef struct _s_0f119ea6_wMsg { unsigned value; } _s_0f119ea6_wMsg;
typedef struct _s_0f119ea6_pdwCookie { unsigned* value; } _s_0f119ea6_pdwCookie;
typedef struct _s_0f119ea6_optionalFile { char* value; } _s_0f119ea6_optionalFile;
typedef struct _s_0f119ea6_optionalLine { int value; } _s_0f119ea6_optionalLine;
static inline _s_0f119ea6_pFactory _0f119ea6_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_0f119ea6_pFactory){value}; }
static inline _s_0f119ea6_WindowHandle _0f119ea6_WindowHandle(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0f119ea6_WindowHandle){value}; }
static inline _s_0f119ea6_wMsg _0f119ea6_wMsg(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_0f119ea6_wMsg){value}; }
static inline _s_0f119ea6_pdwCookie _0f119ea6_pdwCookie(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_0f119ea6_pdwCookie){value}; }
static inline _s_0f119ea6_optionalFile _0f119ea6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0f119ea6_optionalFile){value}; }
static inline _s_0f119ea6_optionalLine _0f119ea6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0f119ea6_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryRegisterOcclusionStatusWindow(_s_0f119ea6_pFactory pFactory, _s_0f119ea6_WindowHandle WindowHandle, _s_0f119ea6_wMsg wMsg, _s_0f119ea6_pdwCookie pdwCookie, _s_0f119ea6_optionalFile optionalFile, _s_0f119ea6_optionalLine optionalLine) {
  return x12FactoryRegisterOcclusionStatusWindow(pFactory.value, WindowHandle.value, wMsg.value, pdwCookie.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryRegisterOcclusionStatusEvent x12FactoryRegisterOcclusionStatusEvent
#define _f17f5d37_pFactory(value) value
#define _f17f5d37_hEvent(value) value
#define _f17f5d37_pdwCookie(value) value
#define _f17f5d37_optionalFile(value) value
#define _f17f5d37_optionalLine(value) value
#else
typedef struct _s_f17f5d37_pFactory { X12Factory4* value; } _s_f17f5d37_pFactory;
typedef struct _s_f17f5d37_hEvent { void* value; } _s_f17f5d37_hEvent;
typedef struct _s_f17f5d37_pdwCookie { unsigned* value; } _s_f17f5d37_pdwCookie;
typedef struct _s_f17f5d37_optionalFile { char* value; } _s_f17f5d37_optionalFile;
typedef struct _s_f17f5d37_optionalLine { int value; } _s_f17f5d37_optionalLine;
static inline _s_f17f5d37_pFactory _f17f5d37_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_f17f5d37_pFactory){value}; }
static inline _s_f17f5d37_hEvent _f17f5d37_hEvent(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f17f5d37_hEvent){value}; }
static inline _s_f17f5d37_pdwCookie _f17f5d37_pdwCookie(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_f17f5d37_pdwCookie){value}; }
static inline _s_f17f5d37_optionalFile _f17f5d37_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f17f5d37_optionalFile){value}; }
static inline _s_f17f5d37_optionalLine _f17f5d37_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f17f5d37_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryRegisterOcclusionStatusEvent(_s_f17f5d37_pFactory pFactory, _s_f17f5d37_hEvent hEvent, _s_f17f5d37_pdwCookie pdwCookie, _s_f17f5d37_optionalFile optionalFile, _s_f17f5d37_optionalLine optionalLine) {
  return x12FactoryRegisterOcclusionStatusEvent(pFactory.value, hEvent.value, pdwCookie.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryUnregisterOcclusionStatus x12FactoryUnregisterOcclusionStatus
#define _d88cdc72_pFactory(value) value
#define _d88cdc72_dwCookie(value) value
#define _d88cdc72_optionalFile(value) value
#define _d88cdc72_optionalLine(value) value
#else
typedef struct _s_d88cdc72_pFactory { X12Factory4* value; } _s_d88cdc72_pFactory;
typedef struct _s_d88cdc72_dwCookie { unsigned value; } _s_d88cdc72_dwCookie;
typedef struct _s_d88cdc72_optionalFile { char* value; } _s_d88cdc72_optionalFile;
typedef struct _s_d88cdc72_optionalLine { int value; } _s_d88cdc72_optionalLine;
static inline _s_d88cdc72_pFactory _d88cdc72_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_d88cdc72_pFactory){value}; }
static inline _s_d88cdc72_dwCookie _d88cdc72_dwCookie(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_d88cdc72_dwCookie){value}; }
static inline _s_d88cdc72_optionalFile _d88cdc72_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d88cdc72_optionalFile){value}; }
static inline _s_d88cdc72_optionalLine _d88cdc72_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d88cdc72_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12FactoryUnregisterOcclusionStatus(_s_d88cdc72_pFactory pFactory, _s_d88cdc72_dwCookie dwCookie, _s_d88cdc72_optionalFile optionalFile, _s_d88cdc72_optionalLine optionalLine) {
  x12FactoryUnregisterOcclusionStatus(pFactory.value, dwCookie.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetBuffer x12SwapChainGetBuffer
#define _6a1aedce_pSwapChain(value) value
#define _6a1aedce_Buffer(value) value
#define _6a1aedce_outpSurface(value) value
#define _6a1aedce_optionalFile(value) value
#define _6a1aedce_optionalLine(value) value
#else
typedef struct _s_6a1aedce_pSwapChain { X12SwapChain3* value; } _s_6a1aedce_pSwapChain;
typedef struct _s_6a1aedce_Buffer { unsigned value; } _s_6a1aedce_Buffer;
typedef struct _s_6a1aedce_outpSurface { X12Resource** value; } _s_6a1aedce_outpSurface;
typedef struct _s_6a1aedce_optionalFile { char* value; } _s_6a1aedce_optionalFile;
typedef struct _s_6a1aedce_optionalLine { int value; } _s_6a1aedce_optionalLine;
static inline _s_6a1aedce_pSwapChain _6a1aedce_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_6a1aedce_pSwapChain){value}; }
static inline _s_6a1aedce_Buffer _6a1aedce_Buffer(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6a1aedce_Buffer){value}; }
static inline _s_6a1aedce_outpSurface _6a1aedce_outpSurface(X12Resource** value) { return REDGPU_NP_STRUCT_INIT(_s_6a1aedce_outpSurface){value}; }
static inline _s_6a1aedce_optionalFile _6a1aedce_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6a1aedce_optionalFile){value}; }
static inline _s_6a1aedce_optionalLine _6a1aedce_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6a1aedce_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetBuffer(_s_6a1aedce_pSwapChain pSwapChain, _s_6a1aedce_Buffer Buffer, _s_6a1aedce_outpSurface outpSurface, _s_6a1aedce_optionalFile optionalFile, _s_6a1aedce_optionalLine optionalLine) {
  return x12SwapChainGetBuffer(pSwapChain.value, Buffer.value, outpSurface.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetCurrentBackBufferIndex x12SwapChainGetCurrentBackBufferIndex
#define _cd05cabb_pSwapChain(value) value
#define _cd05cabb_optionalFile(value) value
#define _cd05cabb_optionalLine(value) value
#else
typedef struct _s_cd05cabb_pSwapChain { X12SwapChain3* value; } _s_cd05cabb_pSwapChain;
typedef struct _s_cd05cabb_optionalFile { char* value; } _s_cd05cabb_optionalFile;
typedef struct _s_cd05cabb_optionalLine { int value; } _s_cd05cabb_optionalLine;
static inline _s_cd05cabb_pSwapChain _cd05cabb_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_cd05cabb_pSwapChain){value}; }
static inline _s_cd05cabb_optionalFile _cd05cabb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cd05cabb_optionalFile){value}; }
static inline _s_cd05cabb_optionalLine _cd05cabb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cd05cabb_optionalLine){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_x12SwapChainGetCurrentBackBufferIndex(_s_cd05cabb_pSwapChain pSwapChain, _s_cd05cabb_optionalFile optionalFile, _s_cd05cabb_optionalLine optionalLine) {
  return x12SwapChainGetCurrentBackBufferIndex(pSwapChain.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainPresent1 x12SwapChainPresent1
#define _b3a00e7d_pSwapChain(value) value
#define _b3a00e7d_SyncInterval(value) value
#define _b3a00e7d_PresentFlags(value) value
#define _b3a00e7d_pPresentParameters(value) value
#define _b3a00e7d_optionalFile(value) value
#define _b3a00e7d_optionalLine(value) value
#else
typedef struct _s_b3a00e7d_pSwapChain { X12SwapChain3* value; } _s_b3a00e7d_pSwapChain;
typedef struct _s_b3a00e7d_SyncInterval { unsigned value; } _s_b3a00e7d_SyncInterval;
typedef struct _s_b3a00e7d_PresentFlags { DXGI_PRESENT_FLAGS value; } _s_b3a00e7d_PresentFlags;
typedef struct _s_b3a00e7d_pPresentParameters { DXGI_PRESENT_PARAMETERS* value; } _s_b3a00e7d_pPresentParameters;
typedef struct _s_b3a00e7d_optionalFile { char* value; } _s_b3a00e7d_optionalFile;
typedef struct _s_b3a00e7d_optionalLine { int value; } _s_b3a00e7d_optionalLine;
static inline _s_b3a00e7d_pSwapChain _b3a00e7d_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_b3a00e7d_pSwapChain){value}; }
static inline _s_b3a00e7d_SyncInterval _b3a00e7d_SyncInterval(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b3a00e7d_SyncInterval){value}; }
static inline _s_b3a00e7d_PresentFlags _b3a00e7d_PresentFlags(DXGI_PRESENT_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_b3a00e7d_PresentFlags){value}; }
static inline _s_b3a00e7d_pPresentParameters _b3a00e7d_pPresentParameters(DXGI_PRESENT_PARAMETERS* value) { return REDGPU_NP_STRUCT_INIT(_s_b3a00e7d_pPresentParameters){value}; }
static inline _s_b3a00e7d_optionalFile _b3a00e7d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b3a00e7d_optionalFile){value}; }
static inline _s_b3a00e7d_optionalLine _b3a00e7d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b3a00e7d_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainPresent1(_s_b3a00e7d_pSwapChain pSwapChain, _s_b3a00e7d_SyncInterval SyncInterval, _s_b3a00e7d_PresentFlags PresentFlags, _s_b3a00e7d_pPresentParameters pPresentParameters, _s_b3a00e7d_optionalFile optionalFile, _s_b3a00e7d_optionalLine optionalLine) {
  return x12SwapChainPresent1(pSwapChain.value, SyncInterval.value, PresentFlags.value, pPresentParameters.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainResizeTarget x12SwapChainResizeTarget
#define _6f94c162_pSwapChain(value) value
#define _6f94c162_pNewTargetParameters(value) value
#define _6f94c162_optionalFile(value) value
#define _6f94c162_optionalLine(value) value
#else
typedef struct _s_6f94c162_pSwapChain { X12SwapChain3* value; } _s_6f94c162_pSwapChain;
typedef struct _s_6f94c162_pNewTargetParameters { DXGI_MODE_DESC* value; } _s_6f94c162_pNewTargetParameters;
typedef struct _s_6f94c162_optionalFile { char* value; } _s_6f94c162_optionalFile;
typedef struct _s_6f94c162_optionalLine { int value; } _s_6f94c162_optionalLine;
static inline _s_6f94c162_pSwapChain _6f94c162_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_6f94c162_pSwapChain){value}; }
static inline _s_6f94c162_pNewTargetParameters _6f94c162_pNewTargetParameters(DXGI_MODE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_6f94c162_pNewTargetParameters){value}; }
static inline _s_6f94c162_optionalFile _6f94c162_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6f94c162_optionalFile){value}; }
static inline _s_6f94c162_optionalLine _6f94c162_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6f94c162_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainResizeTarget(_s_6f94c162_pSwapChain pSwapChain, _s_6f94c162_pNewTargetParameters pNewTargetParameters, _s_6f94c162_optionalFile optionalFile, _s_6f94c162_optionalLine optionalLine) {
  return x12SwapChainResizeTarget(pSwapChain.value, pNewTargetParameters.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainResizeBuffers1 x12SwapChainResizeBuffers1
#define _b7d94981_pSwapChain(value) value
#define _b7d94981_BufferCount(value) value
#define _b7d94981_Width(value) value
#define _b7d94981_Height(value) value
#define _b7d94981_Format(value) value
#define _b7d94981_SwapChainFlags(value) value
#define _b7d94981_pCreationNodeMask(value) value
#define _b7d94981_ppPresentQueue(value) value
#define _b7d94981_optionalFile(value) value
#define _b7d94981_optionalLine(value) value
#else
typedef struct _s_b7d94981_pSwapChain { X12SwapChain3* value; } _s_b7d94981_pSwapChain;
typedef struct _s_b7d94981_BufferCount { unsigned value; } _s_b7d94981_BufferCount;
typedef struct _s_b7d94981_Width { unsigned value; } _s_b7d94981_Width;
typedef struct _s_b7d94981_Height { unsigned value; } _s_b7d94981_Height;
typedef struct _s_b7d94981_Format { DXGI_FORMAT value; } _s_b7d94981_Format;
typedef struct _s_b7d94981_SwapChainFlags { unsigned value; } _s_b7d94981_SwapChainFlags;
typedef struct _s_b7d94981_pCreationNodeMask { unsigned* value; } _s_b7d94981_pCreationNodeMask;
typedef struct _s_b7d94981_ppPresentQueue { X12CommandQueue** value; } _s_b7d94981_ppPresentQueue;
typedef struct _s_b7d94981_optionalFile { char* value; } _s_b7d94981_optionalFile;
typedef struct _s_b7d94981_optionalLine { int value; } _s_b7d94981_optionalLine;
static inline _s_b7d94981_pSwapChain _b7d94981_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_b7d94981_pSwapChain){value}; }
static inline _s_b7d94981_BufferCount _b7d94981_BufferCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b7d94981_BufferCount){value}; }
static inline _s_b7d94981_Width _b7d94981_Width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b7d94981_Width){value}; }
static inline _s_b7d94981_Height _b7d94981_Height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b7d94981_Height){value}; }
static inline _s_b7d94981_Format _b7d94981_Format(DXGI_FORMAT value) { return REDGPU_NP_STRUCT_INIT(_s_b7d94981_Format){value}; }
static inline _s_b7d94981_SwapChainFlags _b7d94981_SwapChainFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b7d94981_SwapChainFlags){value}; }
static inline _s_b7d94981_pCreationNodeMask _b7d94981_pCreationNodeMask(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_b7d94981_pCreationNodeMask){value}; }
static inline _s_b7d94981_ppPresentQueue _b7d94981_ppPresentQueue(X12CommandQueue** value) { return REDGPU_NP_STRUCT_INIT(_s_b7d94981_ppPresentQueue){value}; }
static inline _s_b7d94981_optionalFile _b7d94981_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b7d94981_optionalFile){value}; }
static inline _s_b7d94981_optionalLine _b7d94981_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b7d94981_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainResizeBuffers1(_s_b7d94981_pSwapChain pSwapChain, _s_b7d94981_BufferCount BufferCount, _s_b7d94981_Width Width, _s_b7d94981_Height Height, _s_b7d94981_Format Format, _s_b7d94981_SwapChainFlags SwapChainFlags, _s_b7d94981_pCreationNodeMask pCreationNodeMask, _s_b7d94981_ppPresentQueue ppPresentQueue, _s_b7d94981_optionalFile optionalFile, _s_b7d94981_optionalLine optionalLine) {
  return x12SwapChainResizeBuffers1(pSwapChain.value, BufferCount.value, Width.value, Height.value, Format.value, SwapChainFlags.value, pCreationNodeMask.value, ppPresentQueue.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetFullscreenState x12SwapChainSetFullscreenState
#define _686222ed_pSwapChain(value) value
#define _686222ed_Fullscreen(value) value
#define _686222ed_pTarget(value) value
#define _686222ed_optionalFile(value) value
#define _686222ed_optionalLine(value) value
#else
typedef struct _s_686222ed_pSwapChain { X12SwapChain3* value; } _s_686222ed_pSwapChain;
typedef struct _s_686222ed_Fullscreen { X12Bool value; } _s_686222ed_Fullscreen;
typedef struct _s_686222ed_pTarget { X12Output4* value; } _s_686222ed_pTarget;
typedef struct _s_686222ed_optionalFile { char* value; } _s_686222ed_optionalFile;
typedef struct _s_686222ed_optionalLine { int value; } _s_686222ed_optionalLine;
static inline _s_686222ed_pSwapChain _686222ed_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_686222ed_pSwapChain){value}; }
static inline _s_686222ed_Fullscreen _686222ed_Fullscreen(X12Bool value) { return REDGPU_NP_STRUCT_INIT(_s_686222ed_Fullscreen){value}; }
static inline _s_686222ed_pTarget _686222ed_pTarget(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_686222ed_pTarget){value}; }
static inline _s_686222ed_optionalFile _686222ed_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_686222ed_optionalFile){value}; }
static inline _s_686222ed_optionalLine _686222ed_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_686222ed_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetFullscreenState(_s_686222ed_pSwapChain pSwapChain, _s_686222ed_Fullscreen Fullscreen, _s_686222ed_pTarget pTarget, _s_686222ed_optionalFile optionalFile, _s_686222ed_optionalLine optionalLine) {
  return x12SwapChainSetFullscreenState(pSwapChain.value, Fullscreen.value, pTarget.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetFullscreenDesc x12SwapChainGetFullscreenDesc
#define _58d5653d_pSwapChain(value) value
#define _58d5653d_outDesc(value) value
#define _58d5653d_optionalFile(value) value
#define _58d5653d_optionalLine(value) value
#else
typedef struct _s_58d5653d_pSwapChain { X12SwapChain3* value; } _s_58d5653d_pSwapChain;
typedef struct _s_58d5653d_outDesc { DXGI_SWAP_CHAIN_FULLSCREEN_DESC* value; } _s_58d5653d_outDesc;
typedef struct _s_58d5653d_optionalFile { char* value; } _s_58d5653d_optionalFile;
typedef struct _s_58d5653d_optionalLine { int value; } _s_58d5653d_optionalLine;
static inline _s_58d5653d_pSwapChain _58d5653d_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_58d5653d_pSwapChain){value}; }
static inline _s_58d5653d_outDesc _58d5653d_outDesc(DXGI_SWAP_CHAIN_FULLSCREEN_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_58d5653d_outDesc){value}; }
static inline _s_58d5653d_optionalFile _58d5653d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_58d5653d_optionalFile){value}; }
static inline _s_58d5653d_optionalLine _58d5653d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_58d5653d_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetFullscreenDesc(_s_58d5653d_pSwapChain pSwapChain, _s_58d5653d_outDesc outDesc, _s_58d5653d_optionalFile optionalFile, _s_58d5653d_optionalLine optionalLine) {
  return x12SwapChainGetFullscreenDesc(pSwapChain.value, outDesc.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetLastPresentCount x12SwapChainGetLastPresentCount
#define _4c10d738_pSwapChain(value) value
#define _4c10d738_outLastPresentCount(value) value
#define _4c10d738_optionalFile(value) value
#define _4c10d738_optionalLine(value) value
#else
typedef struct _s_4c10d738_pSwapChain { X12SwapChain3* value; } _s_4c10d738_pSwapChain;
typedef struct _s_4c10d738_outLastPresentCount { unsigned* value; } _s_4c10d738_outLastPresentCount;
typedef struct _s_4c10d738_optionalFile { char* value; } _s_4c10d738_optionalFile;
typedef struct _s_4c10d738_optionalLine { int value; } _s_4c10d738_optionalLine;
static inline _s_4c10d738_pSwapChain _4c10d738_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_4c10d738_pSwapChain){value}; }
static inline _s_4c10d738_outLastPresentCount _4c10d738_outLastPresentCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_4c10d738_outLastPresentCount){value}; }
static inline _s_4c10d738_optionalFile _4c10d738_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4c10d738_optionalFile){value}; }
static inline _s_4c10d738_optionalLine _4c10d738_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4c10d738_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetLastPresentCount(_s_4c10d738_pSwapChain pSwapChain, _s_4c10d738_outLastPresentCount outLastPresentCount, _s_4c10d738_optionalFile optionalFile, _s_4c10d738_optionalLine optionalLine) {
  return x12SwapChainGetLastPresentCount(pSwapChain.value, outLastPresentCount.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetFrameStatistics x12SwapChainGetFrameStatistics
#define _e0229a3f_pSwapChain(value) value
#define _e0229a3f_outStats(value) value
#define _e0229a3f_optionalFile(value) value
#define _e0229a3f_optionalLine(value) value
#else
typedef struct _s_e0229a3f_pSwapChain { X12SwapChain3* value; } _s_e0229a3f_pSwapChain;
typedef struct _s_e0229a3f_outStats { DXGI_FRAME_STATISTICS* value; } _s_e0229a3f_outStats;
typedef struct _s_e0229a3f_optionalFile { char* value; } _s_e0229a3f_optionalFile;
typedef struct _s_e0229a3f_optionalLine { int value; } _s_e0229a3f_optionalLine;
static inline _s_e0229a3f_pSwapChain _e0229a3f_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_e0229a3f_pSwapChain){value}; }
static inline _s_e0229a3f_outStats _e0229a3f_outStats(DXGI_FRAME_STATISTICS* value) { return REDGPU_NP_STRUCT_INIT(_s_e0229a3f_outStats){value}; }
static inline _s_e0229a3f_optionalFile _e0229a3f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e0229a3f_optionalFile){value}; }
static inline _s_e0229a3f_optionalLine _e0229a3f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e0229a3f_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetFrameStatistics(_s_e0229a3f_pSwapChain pSwapChain, _s_e0229a3f_outStats outStats, _s_e0229a3f_optionalFile optionalFile, _s_e0229a3f_optionalLine optionalLine) {
  return x12SwapChainGetFrameStatistics(pSwapChain.value, outStats.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetBackgroundColor x12SwapChainSetBackgroundColor
#define _2a24c011_pSwapChain(value) value
#define _2a24c011_pColor(value) value
#define _2a24c011_optionalFile(value) value
#define _2a24c011_optionalLine(value) value
#else
typedef struct _s_2a24c011_pSwapChain { X12SwapChain3* value; } _s_2a24c011_pSwapChain;
typedef struct _s_2a24c011_pColor { DXGI_RGBA* value; } _s_2a24c011_pColor;
typedef struct _s_2a24c011_optionalFile { char* value; } _s_2a24c011_optionalFile;
typedef struct _s_2a24c011_optionalLine { int value; } _s_2a24c011_optionalLine;
static inline _s_2a24c011_pSwapChain _2a24c011_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_2a24c011_pSwapChain){value}; }
static inline _s_2a24c011_pColor _2a24c011_pColor(DXGI_RGBA* value) { return REDGPU_NP_STRUCT_INIT(_s_2a24c011_pColor){value}; }
static inline _s_2a24c011_optionalFile _2a24c011_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2a24c011_optionalFile){value}; }
static inline _s_2a24c011_optionalLine _2a24c011_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2a24c011_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetBackgroundColor(_s_2a24c011_pSwapChain pSwapChain, _s_2a24c011_pColor pColor, _s_2a24c011_optionalFile optionalFile, _s_2a24c011_optionalLine optionalLine) {
  return x12SwapChainSetBackgroundColor(pSwapChain.value, pColor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetBackgroundColor x12SwapChainGetBackgroundColor
#define _8e6f39c8_pSwapChain(value) value
#define _8e6f39c8_outColor(value) value
#define _8e6f39c8_optionalFile(value) value
#define _8e6f39c8_optionalLine(value) value
#else
typedef struct _s_8e6f39c8_pSwapChain { X12SwapChain3* value; } _s_8e6f39c8_pSwapChain;
typedef struct _s_8e6f39c8_outColor { DXGI_RGBA* value; } _s_8e6f39c8_outColor;
typedef struct _s_8e6f39c8_optionalFile { char* value; } _s_8e6f39c8_optionalFile;
typedef struct _s_8e6f39c8_optionalLine { int value; } _s_8e6f39c8_optionalLine;
static inline _s_8e6f39c8_pSwapChain _8e6f39c8_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_8e6f39c8_pSwapChain){value}; }
static inline _s_8e6f39c8_outColor _8e6f39c8_outColor(DXGI_RGBA* value) { return REDGPU_NP_STRUCT_INIT(_s_8e6f39c8_outColor){value}; }
static inline _s_8e6f39c8_optionalFile _8e6f39c8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8e6f39c8_optionalFile){value}; }
static inline _s_8e6f39c8_optionalLine _8e6f39c8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8e6f39c8_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetBackgroundColor(_s_8e6f39c8_pSwapChain pSwapChain, _s_8e6f39c8_outColor outColor, _s_8e6f39c8_optionalFile optionalFile, _s_8e6f39c8_optionalLine optionalLine) {
  return x12SwapChainGetBackgroundColor(pSwapChain.value, outColor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetRotation x12SwapChainSetRotation
#define _6d834bc2_pSwapChain(value) value
#define _6d834bc2_Rotation(value) value
#define _6d834bc2_optionalFile(value) value
#define _6d834bc2_optionalLine(value) value
#else
typedef struct _s_6d834bc2_pSwapChain { X12SwapChain3* value; } _s_6d834bc2_pSwapChain;
typedef struct _s_6d834bc2_Rotation { DXGI_MODE_ROTATION value; } _s_6d834bc2_Rotation;
typedef struct _s_6d834bc2_optionalFile { char* value; } _s_6d834bc2_optionalFile;
typedef struct _s_6d834bc2_optionalLine { int value; } _s_6d834bc2_optionalLine;
static inline _s_6d834bc2_pSwapChain _6d834bc2_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_6d834bc2_pSwapChain){value}; }
static inline _s_6d834bc2_Rotation _6d834bc2_Rotation(DXGI_MODE_ROTATION value) { return REDGPU_NP_STRUCT_INIT(_s_6d834bc2_Rotation){value}; }
static inline _s_6d834bc2_optionalFile _6d834bc2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6d834bc2_optionalFile){value}; }
static inline _s_6d834bc2_optionalLine _6d834bc2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6d834bc2_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetRotation(_s_6d834bc2_pSwapChain pSwapChain, _s_6d834bc2_Rotation Rotation, _s_6d834bc2_optionalFile optionalFile, _s_6d834bc2_optionalLine optionalLine) {
  return x12SwapChainSetRotation(pSwapChain.value, Rotation.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetRotation x12SwapChainGetRotation
#define _be44884a_pSwapChain(value) value
#define _be44884a_outRotation(value) value
#define _be44884a_optionalFile(value) value
#define _be44884a_optionalLine(value) value
#else
typedef struct _s_be44884a_pSwapChain { X12SwapChain3* value; } _s_be44884a_pSwapChain;
typedef struct _s_be44884a_outRotation { DXGI_MODE_ROTATION* value; } _s_be44884a_outRotation;
typedef struct _s_be44884a_optionalFile { char* value; } _s_be44884a_optionalFile;
typedef struct _s_be44884a_optionalLine { int value; } _s_be44884a_optionalLine;
static inline _s_be44884a_pSwapChain _be44884a_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_be44884a_pSwapChain){value}; }
static inline _s_be44884a_outRotation _be44884a_outRotation(DXGI_MODE_ROTATION* value) { return REDGPU_NP_STRUCT_INIT(_s_be44884a_outRotation){value}; }
static inline _s_be44884a_optionalFile _be44884a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_be44884a_optionalFile){value}; }
static inline _s_be44884a_optionalLine _be44884a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_be44884a_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetRotation(_s_be44884a_pSwapChain pSwapChain, _s_be44884a_outRotation outRotation, _s_be44884a_optionalFile optionalFile, _s_be44884a_optionalLine optionalLine) {
  return x12SwapChainGetRotation(pSwapChain.value, outRotation.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetSourceSize x12SwapChainSetSourceSize
#define _26ee6ffe_pSwapChain(value) value
#define _26ee6ffe_Width(value) value
#define _26ee6ffe_Height(value) value
#define _26ee6ffe_optionalFile(value) value
#define _26ee6ffe_optionalLine(value) value
#else
typedef struct _s_26ee6ffe_pSwapChain { X12SwapChain3* value; } _s_26ee6ffe_pSwapChain;
typedef struct _s_26ee6ffe_Width { unsigned value; } _s_26ee6ffe_Width;
typedef struct _s_26ee6ffe_Height { unsigned value; } _s_26ee6ffe_Height;
typedef struct _s_26ee6ffe_optionalFile { char* value; } _s_26ee6ffe_optionalFile;
typedef struct _s_26ee6ffe_optionalLine { int value; } _s_26ee6ffe_optionalLine;
static inline _s_26ee6ffe_pSwapChain _26ee6ffe_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_26ee6ffe_pSwapChain){value}; }
static inline _s_26ee6ffe_Width _26ee6ffe_Width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_26ee6ffe_Width){value}; }
static inline _s_26ee6ffe_Height _26ee6ffe_Height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_26ee6ffe_Height){value}; }
static inline _s_26ee6ffe_optionalFile _26ee6ffe_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_26ee6ffe_optionalFile){value}; }
static inline _s_26ee6ffe_optionalLine _26ee6ffe_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_26ee6ffe_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetSourceSize(_s_26ee6ffe_pSwapChain pSwapChain, _s_26ee6ffe_Width Width, _s_26ee6ffe_Height Height, _s_26ee6ffe_optionalFile optionalFile, _s_26ee6ffe_optionalLine optionalLine) {
  return x12SwapChainSetSourceSize(pSwapChain.value, Width.value, Height.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetSourceSize x12SwapChainGetSourceSize
#define _d5d1f995_pSwapChain(value) value
#define _d5d1f995_outWidth(value) value
#define _d5d1f995_outHeight(value) value
#define _d5d1f995_optionalFile(value) value
#define _d5d1f995_optionalLine(value) value
#else
typedef struct _s_d5d1f995_pSwapChain { X12SwapChain3* value; } _s_d5d1f995_pSwapChain;
typedef struct _s_d5d1f995_outWidth { unsigned* value; } _s_d5d1f995_outWidth;
typedef struct _s_d5d1f995_outHeight { unsigned* value; } _s_d5d1f995_outHeight;
typedef struct _s_d5d1f995_optionalFile { char* value; } _s_d5d1f995_optionalFile;
typedef struct _s_d5d1f995_optionalLine { int value; } _s_d5d1f995_optionalLine;
static inline _s_d5d1f995_pSwapChain _d5d1f995_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_d5d1f995_pSwapChain){value}; }
static inline _s_d5d1f995_outWidth _d5d1f995_outWidth(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_d5d1f995_outWidth){value}; }
static inline _s_d5d1f995_outHeight _d5d1f995_outHeight(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_d5d1f995_outHeight){value}; }
static inline _s_d5d1f995_optionalFile _d5d1f995_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d5d1f995_optionalFile){value}; }
static inline _s_d5d1f995_optionalLine _d5d1f995_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d5d1f995_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetSourceSize(_s_d5d1f995_pSwapChain pSwapChain, _s_d5d1f995_outWidth outWidth, _s_d5d1f995_outHeight outHeight, _s_d5d1f995_optionalFile optionalFile, _s_d5d1f995_optionalLine optionalLine) {
  return x12SwapChainGetSourceSize(pSwapChain.value, outWidth.value, outHeight.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetMaximumFrameLatency x12SwapChainSetMaximumFrameLatency
#define _618ad4c8_pSwapChain(value) value
#define _618ad4c8_MaxLatency(value) value
#define _618ad4c8_optionalFile(value) value
#define _618ad4c8_optionalLine(value) value
#else
typedef struct _s_618ad4c8_pSwapChain { X12SwapChain3* value; } _s_618ad4c8_pSwapChain;
typedef struct _s_618ad4c8_MaxLatency { unsigned value; } _s_618ad4c8_MaxLatency;
typedef struct _s_618ad4c8_optionalFile { char* value; } _s_618ad4c8_optionalFile;
typedef struct _s_618ad4c8_optionalLine { int value; } _s_618ad4c8_optionalLine;
static inline _s_618ad4c8_pSwapChain _618ad4c8_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_618ad4c8_pSwapChain){value}; }
static inline _s_618ad4c8_MaxLatency _618ad4c8_MaxLatency(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_618ad4c8_MaxLatency){value}; }
static inline _s_618ad4c8_optionalFile _618ad4c8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_618ad4c8_optionalFile){value}; }
static inline _s_618ad4c8_optionalLine _618ad4c8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_618ad4c8_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetMaximumFrameLatency(_s_618ad4c8_pSwapChain pSwapChain, _s_618ad4c8_MaxLatency MaxLatency, _s_618ad4c8_optionalFile optionalFile, _s_618ad4c8_optionalLine optionalLine) {
  return x12SwapChainSetMaximumFrameLatency(pSwapChain.value, MaxLatency.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetMaximumFrameLatency x12SwapChainGetMaximumFrameLatency
#define _21da914b_pSwapChain(value) value
#define _21da914b_outMaxLatency(value) value
#define _21da914b_optionalFile(value) value
#define _21da914b_optionalLine(value) value
#else
typedef struct _s_21da914b_pSwapChain { X12SwapChain3* value; } _s_21da914b_pSwapChain;
typedef struct _s_21da914b_outMaxLatency { unsigned* value; } _s_21da914b_outMaxLatency;
typedef struct _s_21da914b_optionalFile { char* value; } _s_21da914b_optionalFile;
typedef struct _s_21da914b_optionalLine { int value; } _s_21da914b_optionalLine;
static inline _s_21da914b_pSwapChain _21da914b_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_21da914b_pSwapChain){value}; }
static inline _s_21da914b_outMaxLatency _21da914b_outMaxLatency(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_21da914b_outMaxLatency){value}; }
static inline _s_21da914b_optionalFile _21da914b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_21da914b_optionalFile){value}; }
static inline _s_21da914b_optionalLine _21da914b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_21da914b_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetMaximumFrameLatency(_s_21da914b_pSwapChain pSwapChain, _s_21da914b_outMaxLatency outMaxLatency, _s_21da914b_optionalFile optionalFile, _s_21da914b_optionalLine optionalLine) {
  return x12SwapChainGetMaximumFrameLatency(pSwapChain.value, outMaxLatency.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetFrameLatencyWaitableObject x12SwapChainGetFrameLatencyWaitableObject
#define _729d18bf_pSwapChain(value) value
#define _729d18bf_optionalFile(value) value
#define _729d18bf_optionalLine(value) value
#else
typedef struct _s_729d18bf_pSwapChain { X12SwapChain3* value; } _s_729d18bf_pSwapChain;
typedef struct _s_729d18bf_optionalFile { char* value; } _s_729d18bf_optionalFile;
typedef struct _s_729d18bf_optionalLine { int value; } _s_729d18bf_optionalLine;
static inline _s_729d18bf_pSwapChain _729d18bf_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_729d18bf_pSwapChain){value}; }
static inline _s_729d18bf_optionalFile _729d18bf_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_729d18bf_optionalFile){value}; }
static inline _s_729d18bf_optionalLine _729d18bf_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_729d18bf_optionalLine){value}; }
REDGPU_NP_DECLSPEC void* REDGPU_NP_API np_x12SwapChainGetFrameLatencyWaitableObject(_s_729d18bf_pSwapChain pSwapChain, _s_729d18bf_optionalFile optionalFile, _s_729d18bf_optionalLine optionalLine) {
  return x12SwapChainGetFrameLatencyWaitableObject(pSwapChain.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetMatrixTransform x12SwapChainSetMatrixTransform
#define _d90c2919_pSwapChain(value) value
#define _d90c2919_pMatrix(value) value
#define _d90c2919_optionalFile(value) value
#define _d90c2919_optionalLine(value) value
#else
typedef struct _s_d90c2919_pSwapChain { X12SwapChain3* value; } _s_d90c2919_pSwapChain;
typedef struct _s_d90c2919_pMatrix { DXGI_MATRIX_3X2_F* value; } _s_d90c2919_pMatrix;
typedef struct _s_d90c2919_optionalFile { char* value; } _s_d90c2919_optionalFile;
typedef struct _s_d90c2919_optionalLine { int value; } _s_d90c2919_optionalLine;
static inline _s_d90c2919_pSwapChain _d90c2919_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_d90c2919_pSwapChain){value}; }
static inline _s_d90c2919_pMatrix _d90c2919_pMatrix(DXGI_MATRIX_3X2_F* value) { return REDGPU_NP_STRUCT_INIT(_s_d90c2919_pMatrix){value}; }
static inline _s_d90c2919_optionalFile _d90c2919_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d90c2919_optionalFile){value}; }
static inline _s_d90c2919_optionalLine _d90c2919_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d90c2919_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetMatrixTransform(_s_d90c2919_pSwapChain pSwapChain, _s_d90c2919_pMatrix pMatrix, _s_d90c2919_optionalFile optionalFile, _s_d90c2919_optionalLine optionalLine) {
  return x12SwapChainSetMatrixTransform(pSwapChain.value, pMatrix.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetMatrixTransform x12SwapChainGetMatrixTransform
#define _aa37e001_pSwapChain(value) value
#define _aa37e001_outMatrix(value) value
#define _aa37e001_optionalFile(value) value
#define _aa37e001_optionalLine(value) value
#else
typedef struct _s_aa37e001_pSwapChain { X12SwapChain3* value; } _s_aa37e001_pSwapChain;
typedef struct _s_aa37e001_outMatrix { DXGI_MATRIX_3X2_F* value; } _s_aa37e001_outMatrix;
typedef struct _s_aa37e001_optionalFile { char* value; } _s_aa37e001_optionalFile;
typedef struct _s_aa37e001_optionalLine { int value; } _s_aa37e001_optionalLine;
static inline _s_aa37e001_pSwapChain _aa37e001_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_aa37e001_pSwapChain){value}; }
static inline _s_aa37e001_outMatrix _aa37e001_outMatrix(DXGI_MATRIX_3X2_F* value) { return REDGPU_NP_STRUCT_INIT(_s_aa37e001_outMatrix){value}; }
static inline _s_aa37e001_optionalFile _aa37e001_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_aa37e001_optionalFile){value}; }
static inline _s_aa37e001_optionalLine _aa37e001_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_aa37e001_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetMatrixTransform(_s_aa37e001_pSwapChain pSwapChain, _s_aa37e001_outMatrix outMatrix, _s_aa37e001_optionalFile optionalFile, _s_aa37e001_optionalLine optionalLine) {
  return x12SwapChainGetMatrixTransform(pSwapChain.value, outMatrix.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainCheckColorSpaceSupport x12SwapChainCheckColorSpaceSupport
#define _1dbae055_pSwapChain(value) value
#define _1dbae055_ColorSpace(value) value
#define _1dbae055_outColorSpaceSupport(value) value
#define _1dbae055_optionalFile(value) value
#define _1dbae055_optionalLine(value) value
#else
typedef struct _s_1dbae055_pSwapChain { X12SwapChain3* value; } _s_1dbae055_pSwapChain;
typedef struct _s_1dbae055_ColorSpace { DXGI_COLOR_SPACE_TYPE value; } _s_1dbae055_ColorSpace;
typedef struct _s_1dbae055_outColorSpaceSupport { DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAGS* value; } _s_1dbae055_outColorSpaceSupport;
typedef struct _s_1dbae055_optionalFile { char* value; } _s_1dbae055_optionalFile;
typedef struct _s_1dbae055_optionalLine { int value; } _s_1dbae055_optionalLine;
static inline _s_1dbae055_pSwapChain _1dbae055_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_1dbae055_pSwapChain){value}; }
static inline _s_1dbae055_ColorSpace _1dbae055_ColorSpace(DXGI_COLOR_SPACE_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_1dbae055_ColorSpace){value}; }
static inline _s_1dbae055_outColorSpaceSupport _1dbae055_outColorSpaceSupport(DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAGS* value) { return REDGPU_NP_STRUCT_INIT(_s_1dbae055_outColorSpaceSupport){value}; }
static inline _s_1dbae055_optionalFile _1dbae055_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1dbae055_optionalFile){value}; }
static inline _s_1dbae055_optionalLine _1dbae055_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1dbae055_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainCheckColorSpaceSupport(_s_1dbae055_pSwapChain pSwapChain, _s_1dbae055_ColorSpace ColorSpace, _s_1dbae055_outColorSpaceSupport outColorSpaceSupport, _s_1dbae055_optionalFile optionalFile, _s_1dbae055_optionalLine optionalLine) {
  return x12SwapChainCheckColorSpaceSupport(pSwapChain.value, ColorSpace.value, outColorSpaceSupport.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetColorSpace1 x12SwapChainSetColorSpace1
#define _2e246d33_pSwapChain(value) value
#define _2e246d33_ColorSpace(value) value
#define _2e246d33_optionalFile(value) value
#define _2e246d33_optionalLine(value) value
#else
typedef struct _s_2e246d33_pSwapChain { X12SwapChain3* value; } _s_2e246d33_pSwapChain;
typedef struct _s_2e246d33_ColorSpace { DXGI_COLOR_SPACE_TYPE value; } _s_2e246d33_ColorSpace;
typedef struct _s_2e246d33_optionalFile { char* value; } _s_2e246d33_optionalFile;
typedef struct _s_2e246d33_optionalLine { int value; } _s_2e246d33_optionalLine;
static inline _s_2e246d33_pSwapChain _2e246d33_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_2e246d33_pSwapChain){value}; }
static inline _s_2e246d33_ColorSpace _2e246d33_ColorSpace(DXGI_COLOR_SPACE_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_2e246d33_ColorSpace){value}; }
static inline _s_2e246d33_optionalFile _2e246d33_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2e246d33_optionalFile){value}; }
static inline _s_2e246d33_optionalLine _2e246d33_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2e246d33_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetColorSpace1(_s_2e246d33_pSwapChain pSwapChain, _s_2e246d33_ColorSpace ColorSpace, _s_2e246d33_optionalFile optionalFile, _s_2e246d33_optionalLine optionalLine) {
  return x12SwapChainSetColorSpace1(pSwapChain.value, ColorSpace.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputGetDesc x12OutputGetDesc
#define _6309c126_pOutput(value) value
#define _6309c126_outDesc(value) value
#define _6309c126_optionalFile(value) value
#define _6309c126_optionalLine(value) value
#else
typedef struct _s_6309c126_pOutput { X12Output4* value; } _s_6309c126_pOutput;
typedef struct _s_6309c126_outDesc { DXGI_OUTPUT_DESC* value; } _s_6309c126_outDesc;
typedef struct _s_6309c126_optionalFile { char* value; } _s_6309c126_optionalFile;
typedef struct _s_6309c126_optionalLine { int value; } _s_6309c126_optionalLine;
static inline _s_6309c126_pOutput _6309c126_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_6309c126_pOutput){value}; }
static inline _s_6309c126_outDesc _6309c126_outDesc(DXGI_OUTPUT_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_6309c126_outDesc){value}; }
static inline _s_6309c126_optionalFile _6309c126_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6309c126_optionalFile){value}; }
static inline _s_6309c126_optionalLine _6309c126_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6309c126_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputGetDesc(_s_6309c126_pOutput pOutput, _s_6309c126_outDesc outDesc, _s_6309c126_optionalFile optionalFile, _s_6309c126_optionalLine optionalLine) {
  return x12OutputGetDesc(pOutput.value, outDesc.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputGetDisplayModeList1 x12OutputGetDisplayModeList1
#define _b5ea5eb6_pOutput(value) value
#define _b5ea5eb6_EnumFormat(value) value
#define _b5ea5eb6_Flags(value) value
#define _b5ea5eb6_pNumModes(value) value
#define _b5ea5eb6_outDesc(value) value
#define _b5ea5eb6_optionalFile(value) value
#define _b5ea5eb6_optionalLine(value) value
#else
typedef struct _s_b5ea5eb6_pOutput { X12Output4* value; } _s_b5ea5eb6_pOutput;
typedef struct _s_b5ea5eb6_EnumFormat { DXGI_FORMAT value; } _s_b5ea5eb6_EnumFormat;
typedef struct _s_b5ea5eb6_Flags { DXGI_ENUM_MODES_FLAGS value; } _s_b5ea5eb6_Flags;
typedef struct _s_b5ea5eb6_pNumModes { unsigned* value; } _s_b5ea5eb6_pNumModes;
typedef struct _s_b5ea5eb6_outDesc { DXGI_MODE_DESC1* value; } _s_b5ea5eb6_outDesc;
typedef struct _s_b5ea5eb6_optionalFile { char* value; } _s_b5ea5eb6_optionalFile;
typedef struct _s_b5ea5eb6_optionalLine { int value; } _s_b5ea5eb6_optionalLine;
static inline _s_b5ea5eb6_pOutput _b5ea5eb6_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_b5ea5eb6_pOutput){value}; }
static inline _s_b5ea5eb6_EnumFormat _b5ea5eb6_EnumFormat(DXGI_FORMAT value) { return REDGPU_NP_STRUCT_INIT(_s_b5ea5eb6_EnumFormat){value}; }
static inline _s_b5ea5eb6_Flags _b5ea5eb6_Flags(DXGI_ENUM_MODES_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_b5ea5eb6_Flags){value}; }
static inline _s_b5ea5eb6_pNumModes _b5ea5eb6_pNumModes(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_b5ea5eb6_pNumModes){value}; }
static inline _s_b5ea5eb6_outDesc _b5ea5eb6_outDesc(DXGI_MODE_DESC1* value) { return REDGPU_NP_STRUCT_INIT(_s_b5ea5eb6_outDesc){value}; }
static inline _s_b5ea5eb6_optionalFile _b5ea5eb6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b5ea5eb6_optionalFile){value}; }
static inline _s_b5ea5eb6_optionalLine _b5ea5eb6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b5ea5eb6_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputGetDisplayModeList1(_s_b5ea5eb6_pOutput pOutput, _s_b5ea5eb6_EnumFormat EnumFormat, _s_b5ea5eb6_Flags Flags, _s_b5ea5eb6_pNumModes pNumModes, _s_b5ea5eb6_outDesc outDesc, _s_b5ea5eb6_optionalFile optionalFile, _s_b5ea5eb6_optionalLine optionalLine) {
  return x12OutputGetDisplayModeList1(pOutput.value, EnumFormat.value, Flags.value, pNumModes.value, outDesc.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputFindClosestMatchingMode1 x12OutputFindClosestMatchingMode1
#define _b60965e9_pOutput(value) value
#define _b60965e9_pModeToMatch(value) value
#define _b60965e9_pClosestMatch(value) value
#define _b60965e9_pConcernedDevice(value) value
#define _b60965e9_optionalFile(value) value
#define _b60965e9_optionalLine(value) value
#else
typedef struct _s_b60965e9_pOutput { X12Output4* value; } _s_b60965e9_pOutput;
typedef struct _s_b60965e9_pModeToMatch { DXGI_MODE_DESC1* value; } _s_b60965e9_pModeToMatch;
typedef struct _s_b60965e9_pClosestMatch { DXGI_MODE_DESC1* value; } _s_b60965e9_pClosestMatch;
typedef struct _s_b60965e9_pConcernedDevice { X12Device3* value; } _s_b60965e9_pConcernedDevice;
typedef struct _s_b60965e9_optionalFile { char* value; } _s_b60965e9_optionalFile;
typedef struct _s_b60965e9_optionalLine { int value; } _s_b60965e9_optionalLine;
static inline _s_b60965e9_pOutput _b60965e9_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_b60965e9_pOutput){value}; }
static inline _s_b60965e9_pModeToMatch _b60965e9_pModeToMatch(DXGI_MODE_DESC1* value) { return REDGPU_NP_STRUCT_INIT(_s_b60965e9_pModeToMatch){value}; }
static inline _s_b60965e9_pClosestMatch _b60965e9_pClosestMatch(DXGI_MODE_DESC1* value) { return REDGPU_NP_STRUCT_INIT(_s_b60965e9_pClosestMatch){value}; }
static inline _s_b60965e9_pConcernedDevice _b60965e9_pConcernedDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_b60965e9_pConcernedDevice){value}; }
static inline _s_b60965e9_optionalFile _b60965e9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b60965e9_optionalFile){value}; }
static inline _s_b60965e9_optionalLine _b60965e9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b60965e9_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputFindClosestMatchingMode1(_s_b60965e9_pOutput pOutput, _s_b60965e9_pModeToMatch pModeToMatch, _s_b60965e9_pClosestMatch pClosestMatch, _s_b60965e9_pConcernedDevice pConcernedDevice, _s_b60965e9_optionalFile optionalFile, _s_b60965e9_optionalLine optionalLine) {
  return x12OutputFindClosestMatchingMode1(pOutput.value, pModeToMatch.value, pClosestMatch.value, pConcernedDevice.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputWaitForVBlank x12OutputWaitForVBlank
#define _30d9d0d4_pOutput(value) value
#define _30d9d0d4_optionalFile(value) value
#define _30d9d0d4_optionalLine(value) value
#else
typedef struct _s_30d9d0d4_pOutput { X12Output4* value; } _s_30d9d0d4_pOutput;
typedef struct _s_30d9d0d4_optionalFile { char* value; } _s_30d9d0d4_optionalFile;
typedef struct _s_30d9d0d4_optionalLine { int value; } _s_30d9d0d4_optionalLine;
static inline _s_30d9d0d4_pOutput _30d9d0d4_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_30d9d0d4_pOutput){value}; }
static inline _s_30d9d0d4_optionalFile _30d9d0d4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_30d9d0d4_optionalFile){value}; }
static inline _s_30d9d0d4_optionalLine _30d9d0d4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_30d9d0d4_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputWaitForVBlank(_s_30d9d0d4_pOutput pOutput, _s_30d9d0d4_optionalFile optionalFile, _s_30d9d0d4_optionalLine optionalLine) {
  return x12OutputWaitForVBlank(pOutput.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputGetGammaControlCapabilities x12OutputGetGammaControlCapabilities
#define _3ddfef5a_pOutput(value) value
#define _3ddfef5a_outGammaCaps(value) value
#define _3ddfef5a_optionalFile(value) value
#define _3ddfef5a_optionalLine(value) value
#else
typedef struct _s_3ddfef5a_pOutput { X12Output4* value; } _s_3ddfef5a_pOutput;
typedef struct _s_3ddfef5a_outGammaCaps { DXGI_GAMMA_CONTROL_CAPABILITIES* value; } _s_3ddfef5a_outGammaCaps;
typedef struct _s_3ddfef5a_optionalFile { char* value; } _s_3ddfef5a_optionalFile;
typedef struct _s_3ddfef5a_optionalLine { int value; } _s_3ddfef5a_optionalLine;
static inline _s_3ddfef5a_pOutput _3ddfef5a_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_3ddfef5a_pOutput){value}; }
static inline _s_3ddfef5a_outGammaCaps _3ddfef5a_outGammaCaps(DXGI_GAMMA_CONTROL_CAPABILITIES* value) { return REDGPU_NP_STRUCT_INIT(_s_3ddfef5a_outGammaCaps){value}; }
static inline _s_3ddfef5a_optionalFile _3ddfef5a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3ddfef5a_optionalFile){value}; }
static inline _s_3ddfef5a_optionalLine _3ddfef5a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3ddfef5a_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputGetGammaControlCapabilities(_s_3ddfef5a_pOutput pOutput, _s_3ddfef5a_outGammaCaps outGammaCaps, _s_3ddfef5a_optionalFile optionalFile, _s_3ddfef5a_optionalLine optionalLine) {
  return x12OutputGetGammaControlCapabilities(pOutput.value, outGammaCaps.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputSetGammaControl x12OutputSetGammaControl
#define _434a1f0c_pOutput(value) value
#define _434a1f0c_pArray(value) value
#define _434a1f0c_optionalFile(value) value
#define _434a1f0c_optionalLine(value) value
#else
typedef struct _s_434a1f0c_pOutput { X12Output4* value; } _s_434a1f0c_pOutput;
typedef struct _s_434a1f0c_pArray { DXGI_GAMMA_CONTROL* value; } _s_434a1f0c_pArray;
typedef struct _s_434a1f0c_optionalFile { char* value; } _s_434a1f0c_optionalFile;
typedef struct _s_434a1f0c_optionalLine { int value; } _s_434a1f0c_optionalLine;
static inline _s_434a1f0c_pOutput _434a1f0c_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_434a1f0c_pOutput){value}; }
static inline _s_434a1f0c_pArray _434a1f0c_pArray(DXGI_GAMMA_CONTROL* value) { return REDGPU_NP_STRUCT_INIT(_s_434a1f0c_pArray){value}; }
static inline _s_434a1f0c_optionalFile _434a1f0c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_434a1f0c_optionalFile){value}; }
static inline _s_434a1f0c_optionalLine _434a1f0c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_434a1f0c_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputSetGammaControl(_s_434a1f0c_pOutput pOutput, _s_434a1f0c_pArray pArray, _s_434a1f0c_optionalFile optionalFile, _s_434a1f0c_optionalLine optionalLine) {
  return x12OutputSetGammaControl(pOutput.value, pArray.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputGetGammaControl x12OutputGetGammaControl
#define _515c635a_pOutput(value) value
#define _515c635a_outArray(value) value
#define _515c635a_optionalFile(value) value
#define _515c635a_optionalLine(value) value
#else
typedef struct _s_515c635a_pOutput { X12Output4* value; } _s_515c635a_pOutput;
typedef struct _s_515c635a_outArray { DXGI_GAMMA_CONTROL* value; } _s_515c635a_outArray;
typedef struct _s_515c635a_optionalFile { char* value; } _s_515c635a_optionalFile;
typedef struct _s_515c635a_optionalLine { int value; } _s_515c635a_optionalLine;
static inline _s_515c635a_pOutput _515c635a_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_515c635a_pOutput){value}; }
static inline _s_515c635a_outArray _515c635a_outArray(DXGI_GAMMA_CONTROL* value) { return REDGPU_NP_STRUCT_INIT(_s_515c635a_outArray){value}; }
static inline _s_515c635a_optionalFile _515c635a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_515c635a_optionalFile){value}; }
static inline _s_515c635a_optionalLine _515c635a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_515c635a_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputGetGammaControl(_s_515c635a_pOutput pOutput, _s_515c635a_outArray outArray, _s_515c635a_optionalFile optionalFile, _s_515c635a_optionalLine optionalLine) {
  return x12OutputGetGammaControl(pOutput.value, outArray.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputGetFrameStatistics x12OutputGetFrameStatistics
#define _32312055_pOutput(value) value
#define _32312055_outStats(value) value
#define _32312055_optionalFile(value) value
#define _32312055_optionalLine(value) value
#else
typedef struct _s_32312055_pOutput { X12Output4* value; } _s_32312055_pOutput;
typedef struct _s_32312055_outStats { DXGI_FRAME_STATISTICS* value; } _s_32312055_outStats;
typedef struct _s_32312055_optionalFile { char* value; } _s_32312055_optionalFile;
typedef struct _s_32312055_optionalLine { int value; } _s_32312055_optionalLine;
static inline _s_32312055_pOutput _32312055_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_32312055_pOutput){value}; }
static inline _s_32312055_outStats _32312055_outStats(DXGI_FRAME_STATISTICS* value) { return REDGPU_NP_STRUCT_INIT(_s_32312055_outStats){value}; }
static inline _s_32312055_optionalFile _32312055_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_32312055_optionalFile){value}; }
static inline _s_32312055_optionalLine _32312055_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_32312055_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputGetFrameStatistics(_s_32312055_pOutput pOutput, _s_32312055_outStats outStats, _s_32312055_optionalFile optionalFile, _s_32312055_optionalLine optionalLine) {
  return x12OutputGetFrameStatistics(pOutput.value, outStats.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputSupportsOverlays x12OutputSupportsOverlays
#define _d24c1965_pOutput(value) value
#define _d24c1965_optionalFile(value) value
#define _d24c1965_optionalLine(value) value
#else
typedef struct _s_d24c1965_pOutput { X12Output4* value; } _s_d24c1965_pOutput;
typedef struct _s_d24c1965_optionalFile { char* value; } _s_d24c1965_optionalFile;
typedef struct _s_d24c1965_optionalLine { int value; } _s_d24c1965_optionalLine;
static inline _s_d24c1965_pOutput _d24c1965_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_d24c1965_pOutput){value}; }
static inline _s_d24c1965_optionalFile _d24c1965_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d24c1965_optionalFile){value}; }
static inline _s_d24c1965_optionalLine _d24c1965_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d24c1965_optionalLine){value}; }
REDGPU_NP_DECLSPEC X12Bool REDGPU_NP_API np_x12OutputSupportsOverlays(_s_d24c1965_pOutput pOutput, _s_d24c1965_optionalFile optionalFile, _s_d24c1965_optionalLine optionalLine) {
  return x12OutputSupportsOverlays(pOutput.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputCheckOverlaySupport x12OutputCheckOverlaySupport
#define _dafe90be_pOutput(value) value
#define _dafe90be_EnumFormat(value) value
#define _dafe90be_pConcernedDevice(value) value
#define _dafe90be_pFlags(value) value
#define _dafe90be_optionalFile(value) value
#define _dafe90be_optionalLine(value) value
#else
typedef struct _s_dafe90be_pOutput { X12Output4* value; } _s_dafe90be_pOutput;
typedef struct _s_dafe90be_EnumFormat { DXGI_FORMAT value; } _s_dafe90be_EnumFormat;
typedef struct _s_dafe90be_pConcernedDevice { X12Device3* value; } _s_dafe90be_pConcernedDevice;
typedef struct _s_dafe90be_pFlags { unsigned* value; } _s_dafe90be_pFlags;
typedef struct _s_dafe90be_optionalFile { char* value; } _s_dafe90be_optionalFile;
typedef struct _s_dafe90be_optionalLine { int value; } _s_dafe90be_optionalLine;
static inline _s_dafe90be_pOutput _dafe90be_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_dafe90be_pOutput){value}; }
static inline _s_dafe90be_EnumFormat _dafe90be_EnumFormat(DXGI_FORMAT value) { return REDGPU_NP_STRUCT_INIT(_s_dafe90be_EnumFormat){value}; }
static inline _s_dafe90be_pConcernedDevice _dafe90be_pConcernedDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_dafe90be_pConcernedDevice){value}; }
static inline _s_dafe90be_pFlags _dafe90be_pFlags(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_dafe90be_pFlags){value}; }
static inline _s_dafe90be_optionalFile _dafe90be_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_dafe90be_optionalFile){value}; }
static inline _s_dafe90be_optionalLine _dafe90be_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_dafe90be_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputCheckOverlaySupport(_s_dafe90be_pOutput pOutput, _s_dafe90be_EnumFormat EnumFormat, _s_dafe90be_pConcernedDevice pConcernedDevice, _s_dafe90be_pFlags pFlags, _s_dafe90be_optionalFile optionalFile, _s_dafe90be_optionalLine optionalLine) {
  return x12OutputCheckOverlaySupport(pOutput.value, EnumFormat.value, pConcernedDevice.value, pFlags.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputCheckOverlayColorSpaceSupport x12OutputCheckOverlayColorSpaceSupport
#define _10a74f17_pOutput(value) value
#define _10a74f17_Format(value) value
#define _10a74f17_ColorSpace(value) value
#define _10a74f17_pConcernedDevice(value) value
#define _10a74f17_outFlags(value) value
#define _10a74f17_optionalFile(value) value
#define _10a74f17_optionalLine(value) value
#else
typedef struct _s_10a74f17_pOutput { X12Output4* value; } _s_10a74f17_pOutput;
typedef struct _s_10a74f17_Format { DXGI_FORMAT value; } _s_10a74f17_Format;
typedef struct _s_10a74f17_ColorSpace { DXGI_COLOR_SPACE_TYPE value; } _s_10a74f17_ColorSpace;
typedef struct _s_10a74f17_pConcernedDevice { X12Device3* value; } _s_10a74f17_pConcernedDevice;
typedef struct _s_10a74f17_outFlags { DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAGS* value; } _s_10a74f17_outFlags;
typedef struct _s_10a74f17_optionalFile { char* value; } _s_10a74f17_optionalFile;
typedef struct _s_10a74f17_optionalLine { int value; } _s_10a74f17_optionalLine;
static inline _s_10a74f17_pOutput _10a74f17_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_10a74f17_pOutput){value}; }
static inline _s_10a74f17_Format _10a74f17_Format(DXGI_FORMAT value) { return REDGPU_NP_STRUCT_INIT(_s_10a74f17_Format){value}; }
static inline _s_10a74f17_ColorSpace _10a74f17_ColorSpace(DXGI_COLOR_SPACE_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_10a74f17_ColorSpace){value}; }
static inline _s_10a74f17_pConcernedDevice _10a74f17_pConcernedDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_10a74f17_pConcernedDevice){value}; }
static inline _s_10a74f17_outFlags _10a74f17_outFlags(DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAGS* value) { return REDGPU_NP_STRUCT_INIT(_s_10a74f17_outFlags){value}; }
static inline _s_10a74f17_optionalFile _10a74f17_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_10a74f17_optionalFile){value}; }
static inline _s_10a74f17_optionalLine _10a74f17_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_10a74f17_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputCheckOverlayColorSpaceSupport(_s_10a74f17_pOutput pOutput, _s_10a74f17_Format Format, _s_10a74f17_ColorSpace ColorSpace, _s_10a74f17_pConcernedDevice pConcernedDevice, _s_10a74f17_outFlags outFlags, _s_10a74f17_optionalFile optionalFile, _s_10a74f17_optionalLine optionalLine) {
  return x12OutputCheckOverlayColorSpaceSupport(pOutput.value, Format.value, ColorSpace.value, pConcernedDevice.value, outFlags.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12ObjectSetName x12ObjectSetName
#define _15835d83_handle(value) value
#define _15835d83_Name(value) value
#define _15835d83_optionalFile(value) value
#define _15835d83_optionalLine(value) value
#else
typedef struct _s_15835d83_handle { void* value; } _s_15835d83_handle;
typedef struct _s_15835d83_Name { wchar_t* value; } _s_15835d83_Name;
typedef struct _s_15835d83_optionalFile { char* value; } _s_15835d83_optionalFile;
typedef struct _s_15835d83_optionalLine { int value; } _s_15835d83_optionalLine;
static inline _s_15835d83_handle _15835d83_handle(void* value) { return REDGPU_NP_STRUCT_INIT(_s_15835d83_handle){value}; }
static inline _s_15835d83_Name _15835d83_Name(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_15835d83_Name){value}; }
static inline _s_15835d83_optionalFile _15835d83_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_15835d83_optionalFile){value}; }
static inline _s_15835d83_optionalLine _15835d83_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_15835d83_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12ObjectSetName(_s_15835d83_handle handle, _s_15835d83_Name Name, _s_15835d83_optionalFile optionalFile, _s_15835d83_optionalLine optionalLine) {
  return x12ObjectSetName(handle.value, Name.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12Release x12Release
#define _fcf06563_handle(value) value
#define _fcf06563_optionalFile(value) value
#define _fcf06563_optionalLine(value) value
#else
typedef struct _s_fcf06563_handle { void* value; } _s_fcf06563_handle;
typedef struct _s_fcf06563_optionalFile { char* value; } _s_fcf06563_optionalFile;
typedef struct _s_fcf06563_optionalLine { int value; } _s_fcf06563_optionalLine;
static inline _s_fcf06563_handle _fcf06563_handle(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fcf06563_handle){value}; }
static inline _s_fcf06563_optionalFile _fcf06563_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fcf06563_optionalFile){value}; }
static inline _s_fcf06563_optionalLine _fcf06563_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fcf06563_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12Release(_s_fcf06563_handle handle, _s_fcf06563_optionalFile optionalFile, _s_fcf06563_optionalLine optionalLine) {
  x12Release(handle.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetMarker x12CommandListSetMarker
#define _f5185c66_handle(value) value
#define _f5185c66_Metadata(value) value
#define _f5185c66_pData(value) value
#define _f5185c66_Size(value) value
#else
typedef struct _s_f5185c66_handle { X12CommandList* value; } _s_f5185c66_handle;
typedef struct _s_f5185c66_Metadata { unsigned value; } _s_f5185c66_Metadata;
typedef struct _s_f5185c66_pData { void* value; } _s_f5185c66_pData;
typedef struct _s_f5185c66_Size { unsigned value; } _s_f5185c66_Size;
static inline _s_f5185c66_handle _f5185c66_handle(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_f5185c66_handle){value}; }
static inline _s_f5185c66_Metadata _f5185c66_Metadata(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f5185c66_Metadata){value}; }
static inline _s_f5185c66_pData _f5185c66_pData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f5185c66_pData){value}; }
static inline _s_f5185c66_Size _f5185c66_Size(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f5185c66_Size){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetMarker(_s_f5185c66_handle handle, _s_f5185c66_Metadata Metadata, _s_f5185c66_pData pData, _s_f5185c66_Size Size) {
  x12CommandListSetMarker(handle.value, Metadata.value, pData.value, Size.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListBeginEvent x12CommandListBeginEvent
#define _d1e10f82_handle(value) value
#define _d1e10f82_Metadata(value) value
#define _d1e10f82_pData(value) value
#define _d1e10f82_Size(value) value
#else
typedef struct _s_d1e10f82_handle { X12CommandList* value; } _s_d1e10f82_handle;
typedef struct _s_d1e10f82_Metadata { unsigned value; } _s_d1e10f82_Metadata;
typedef struct _s_d1e10f82_pData { void* value; } _s_d1e10f82_pData;
typedef struct _s_d1e10f82_Size { unsigned value; } _s_d1e10f82_Size;
static inline _s_d1e10f82_handle _d1e10f82_handle(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_d1e10f82_handle){value}; }
static inline _s_d1e10f82_Metadata _d1e10f82_Metadata(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_d1e10f82_Metadata){value}; }
static inline _s_d1e10f82_pData _d1e10f82_pData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d1e10f82_pData){value}; }
static inline _s_d1e10f82_Size _d1e10f82_Size(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_d1e10f82_Size){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListBeginEvent(_s_d1e10f82_handle handle, _s_d1e10f82_Metadata Metadata, _s_d1e10f82_pData pData, _s_d1e10f82_Size Size) {
  x12CommandListBeginEvent(handle.value, Metadata.value, pData.value, Size.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListEndEvent x12CommandListEndEvent
#define _415aeede_handle(value) value
#else
typedef struct _s_415aeede_handle { X12CommandList* value; } _s_415aeede_handle;
static inline _s_415aeede_handle _415aeede_handle(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_415aeede_handle){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListEndEvent(_s_415aeede_handle handle) {
  x12CommandListEndEvent(handle.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandQueueSetMarker x12CommandQueueSetMarker
#define _ace01430_handle(value) value
#define _ace01430_Metadata(value) value
#define _ace01430_pData(value) value
#define _ace01430_Size(value) value
#else
typedef struct _s_ace01430_handle { X12CommandQueue* value; } _s_ace01430_handle;
typedef struct _s_ace01430_Metadata { unsigned value; } _s_ace01430_Metadata;
typedef struct _s_ace01430_pData { void* value; } _s_ace01430_pData;
typedef struct _s_ace01430_Size { unsigned value; } _s_ace01430_Size;
static inline _s_ace01430_handle _ace01430_handle(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_ace01430_handle){value}; }
static inline _s_ace01430_Metadata _ace01430_Metadata(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ace01430_Metadata){value}; }
static inline _s_ace01430_pData _ace01430_pData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ace01430_pData){value}; }
static inline _s_ace01430_Size _ace01430_Size(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_ace01430_Size){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandQueueSetMarker(_s_ace01430_handle handle, _s_ace01430_Metadata Metadata, _s_ace01430_pData pData, _s_ace01430_Size Size) {
  x12CommandQueueSetMarker(handle.value, Metadata.value, pData.value, Size.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandQueueBeginEvent x12CommandQueueBeginEvent
#define _a58f1e6e_handle(value) value
#define _a58f1e6e_Metadata(value) value
#define _a58f1e6e_pData(value) value
#define _a58f1e6e_Size(value) value
#else
typedef struct _s_a58f1e6e_handle { X12CommandQueue* value; } _s_a58f1e6e_handle;
typedef struct _s_a58f1e6e_Metadata { unsigned value; } _s_a58f1e6e_Metadata;
typedef struct _s_a58f1e6e_pData { void* value; } _s_a58f1e6e_pData;
typedef struct _s_a58f1e6e_Size { unsigned value; } _s_a58f1e6e_Size;
static inline _s_a58f1e6e_handle _a58f1e6e_handle(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_a58f1e6e_handle){value}; }
static inline _s_a58f1e6e_Metadata _a58f1e6e_Metadata(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a58f1e6e_Metadata){value}; }
static inline _s_a58f1e6e_pData _a58f1e6e_pData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a58f1e6e_pData){value}; }
static inline _s_a58f1e6e_Size _a58f1e6e_Size(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a58f1e6e_Size){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandQueueBeginEvent(_s_a58f1e6e_handle handle, _s_a58f1e6e_Metadata Metadata, _s_a58f1e6e_pData pData, _s_a58f1e6e_Size Size) {
  x12CommandQueueBeginEvent(handle.value, Metadata.value, pData.value, Size.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandQueueEndEvent x12CommandQueueEndEvent
#define _f4f03828_handle(value) value
#else
typedef struct _s_f4f03828_handle { X12CommandQueue* value; } _s_f4f03828_handle;
static inline _s_f4f03828_handle _f4f03828_handle(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_f4f03828_handle){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandQueueEndEvent(_s_f4f03828_handle handle) {
  x12CommandQueueEndEvent(handle.value);
}
#endif

