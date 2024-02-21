#pragma once

#ifndef REDGPU_NP_DECLSPEC
#define REDGPU_NP_DECLSPEC
#endif

#ifndef REDGPU_NP_API
#define REDGPU_NP_API
#endif

#ifndef REDGPU_NP_STRUCT_INIT
#ifdef __cplusplus
#define REDGPU_NP_STRUCT_INIT(x) x
#else
#define REDGPU_NP_STRUCT_INIT(x) (x)
#endif
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12AdapterRegisterVideoMemoryBudgetChangeNotificationEvent x12AdapterRegisterVideoMemoryBudgetChangeNotificationEvent
#define _234869dd_pAdapter(value) value
#define _234869dd_hEvent(value) value
#define _234869dd_outdwCookie(value) value
#define _234869dd_optionalFile(value) value
#define _234869dd_optionalLine(value) value
#else
typedef struct _s_234869dd_pAdapter { X12Adapter3* value; } _s_234869dd_pAdapter;
typedef struct _s_234869dd_hEvent { void* value; } _s_234869dd_hEvent;
typedef struct _s_234869dd_outdwCookie { unsigned* value; } _s_234869dd_outdwCookie;
typedef struct _s_234869dd_optionalFile { char* value; } _s_234869dd_optionalFile;
typedef struct _s_234869dd_optionalLine { int value; } _s_234869dd_optionalLine;
static inline _s_234869dd_pAdapter _234869dd_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_234869dd_pAdapter){value}; }
static inline _s_234869dd_hEvent _234869dd_hEvent(void* value) { return REDGPU_NP_STRUCT_INIT(_s_234869dd_hEvent){value}; }
static inline _s_234869dd_outdwCookie _234869dd_outdwCookie(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_234869dd_outdwCookie){value}; }
static inline _s_234869dd_optionalFile _234869dd_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_234869dd_optionalFile){value}; }
static inline _s_234869dd_optionalLine _234869dd_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_234869dd_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12AdapterRegisterVideoMemoryBudgetChangeNotificationEvent(_s_234869dd_pAdapter pAdapter, _s_234869dd_hEvent hEvent, _s_234869dd_outdwCookie outdwCookie, _s_234869dd_optionalFile optionalFile, _s_234869dd_optionalLine optionalLine) {
  return x12AdapterRegisterVideoMemoryBudgetChangeNotificationEvent(pAdapter.value, hEvent.value, outdwCookie.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12AdapterUnregisterVideoMemoryBudgetChangeNotification x12AdapterUnregisterVideoMemoryBudgetChangeNotification
#define _6c92cdcb_pAdapter(value) value
#define _6c92cdcb_dwCookie(value) value
#define _6c92cdcb_optionalFile(value) value
#define _6c92cdcb_optionalLine(value) value
#else
typedef struct _s_6c92cdcb_pAdapter { X12Adapter3* value; } _s_6c92cdcb_pAdapter;
typedef struct _s_6c92cdcb_dwCookie { unsigned value; } _s_6c92cdcb_dwCookie;
typedef struct _s_6c92cdcb_optionalFile { char* value; } _s_6c92cdcb_optionalFile;
typedef struct _s_6c92cdcb_optionalLine { int value; } _s_6c92cdcb_optionalLine;
static inline _s_6c92cdcb_pAdapter _6c92cdcb_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_6c92cdcb_pAdapter){value}; }
static inline _s_6c92cdcb_dwCookie _6c92cdcb_dwCookie(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6c92cdcb_dwCookie){value}; }
static inline _s_6c92cdcb_optionalFile _6c92cdcb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6c92cdcb_optionalFile){value}; }
static inline _s_6c92cdcb_optionalLine _6c92cdcb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6c92cdcb_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12AdapterUnregisterVideoMemoryBudgetChangeNotification(_s_6c92cdcb_pAdapter pAdapter, _s_6c92cdcb_dwCookie dwCookie, _s_6c92cdcb_optionalFile optionalFile, _s_6c92cdcb_optionalLine optionalLine) {
  x12AdapterUnregisterVideoMemoryBudgetChangeNotification(pAdapter.value, dwCookie.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12AdapterQueryVideoMemoryInfo x12AdapterQueryVideoMemoryInfo
#define _b624d535_pAdapter(value) value
#define _b624d535_NodeIndex(value) value
#define _b624d535_MemorySegmentGroup(value) value
#define _b624d535_pVideoMemoryInfo(value) value
#define _b624d535_optionalFile(value) value
#define _b624d535_optionalLine(value) value
#else
typedef struct _s_b624d535_pAdapter { X12Adapter3* value; } _s_b624d535_pAdapter;
typedef struct _s_b624d535_NodeIndex { unsigned value; } _s_b624d535_NodeIndex;
typedef struct _s_b624d535_MemorySegmentGroup { DXGI_MEMORY_SEGMENT_GROUP value; } _s_b624d535_MemorySegmentGroup;
typedef struct _s_b624d535_pVideoMemoryInfo { DXGI_QUERY_VIDEO_MEMORY_INFO* value; } _s_b624d535_pVideoMemoryInfo;
typedef struct _s_b624d535_optionalFile { char* value; } _s_b624d535_optionalFile;
typedef struct _s_b624d535_optionalLine { int value; } _s_b624d535_optionalLine;
static inline _s_b624d535_pAdapter _b624d535_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_b624d535_pAdapter){value}; }
static inline _s_b624d535_NodeIndex _b624d535_NodeIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b624d535_NodeIndex){value}; }
static inline _s_b624d535_MemorySegmentGroup _b624d535_MemorySegmentGroup(DXGI_MEMORY_SEGMENT_GROUP value) { return REDGPU_NP_STRUCT_INIT(_s_b624d535_MemorySegmentGroup){value}; }
static inline _s_b624d535_pVideoMemoryInfo _b624d535_pVideoMemoryInfo(DXGI_QUERY_VIDEO_MEMORY_INFO* value) { return REDGPU_NP_STRUCT_INIT(_s_b624d535_pVideoMemoryInfo){value}; }
static inline _s_b624d535_optionalFile _b624d535_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b624d535_optionalFile){value}; }
static inline _s_b624d535_optionalLine _b624d535_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b624d535_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12AdapterQueryVideoMemoryInfo(_s_b624d535_pAdapter pAdapter, _s_b624d535_NodeIndex NodeIndex, _s_b624d535_MemorySegmentGroup MemorySegmentGroup, _s_b624d535_pVideoMemoryInfo pVideoMemoryInfo, _s_b624d535_optionalFile optionalFile, _s_b624d535_optionalLine optionalLine) {
  return x12AdapterQueryVideoMemoryInfo(pAdapter.value, NodeIndex.value, MemorySegmentGroup.value, pVideoMemoryInfo.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12AdapterSetVideoMemoryReservation x12AdapterSetVideoMemoryReservation
#define _dd8569cd_pAdapter(value) value
#define _dd8569cd_NodeIndex(value) value
#define _dd8569cd_MemorySegmentGroup(value) value
#define _dd8569cd_Reservation(value) value
#define _dd8569cd_optionalFile(value) value
#define _dd8569cd_optionalLine(value) value
#else
typedef struct _s_dd8569cd_pAdapter { X12Adapter3* value; } _s_dd8569cd_pAdapter;
typedef struct _s_dd8569cd_NodeIndex { unsigned value; } _s_dd8569cd_NodeIndex;
typedef struct _s_dd8569cd_MemorySegmentGroup { DXGI_MEMORY_SEGMENT_GROUP value; } _s_dd8569cd_MemorySegmentGroup;
typedef struct _s_dd8569cd_Reservation { uint64_t value; } _s_dd8569cd_Reservation;
typedef struct _s_dd8569cd_optionalFile { char* value; } _s_dd8569cd_optionalFile;
typedef struct _s_dd8569cd_optionalLine { int value; } _s_dd8569cd_optionalLine;
static inline _s_dd8569cd_pAdapter _dd8569cd_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_dd8569cd_pAdapter){value}; }
static inline _s_dd8569cd_NodeIndex _dd8569cd_NodeIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_dd8569cd_NodeIndex){value}; }
static inline _s_dd8569cd_MemorySegmentGroup _dd8569cd_MemorySegmentGroup(DXGI_MEMORY_SEGMENT_GROUP value) { return REDGPU_NP_STRUCT_INIT(_s_dd8569cd_MemorySegmentGroup){value}; }
static inline _s_dd8569cd_Reservation _dd8569cd_Reservation(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_dd8569cd_Reservation){value}; }
static inline _s_dd8569cd_optionalFile _dd8569cd_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_dd8569cd_optionalFile){value}; }
static inline _s_dd8569cd_optionalLine _dd8569cd_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_dd8569cd_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12AdapterSetVideoMemoryReservation(_s_dd8569cd_pAdapter pAdapter, _s_dd8569cd_NodeIndex NodeIndex, _s_dd8569cd_MemorySegmentGroup MemorySegmentGroup, _s_dd8569cd_Reservation Reservation, _s_dd8569cd_optionalFile optionalFile, _s_dd8569cd_optionalLine optionalLine) {
  return x12AdapterSetVideoMemoryReservation(pAdapter.value, NodeIndex.value, MemorySegmentGroup.value, Reservation.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateHeap x12DeviceCreateHeap
#define _b26e9376_pDevice(value) value
#define _b26e9376_pDesc(value) value
#define _b26e9376_outpHeap(value) value
#define _b26e9376_optionalFile(value) value
#define _b26e9376_optionalLine(value) value
#else
typedef struct _s_b26e9376_pDevice { X12Device3* value; } _s_b26e9376_pDevice;
typedef struct _s_b26e9376_pDesc { D3D12_HEAP_DESC* value; } _s_b26e9376_pDesc;
typedef struct _s_b26e9376_outpHeap { X12Heap** value; } _s_b26e9376_outpHeap;
typedef struct _s_b26e9376_optionalFile { char* value; } _s_b26e9376_optionalFile;
typedef struct _s_b26e9376_optionalLine { int value; } _s_b26e9376_optionalLine;
static inline _s_b26e9376_pDevice _b26e9376_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_b26e9376_pDevice){value}; }
static inline _s_b26e9376_pDesc _b26e9376_pDesc(D3D12_HEAP_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_b26e9376_pDesc){value}; }
static inline _s_b26e9376_outpHeap _b26e9376_outpHeap(X12Heap** value) { return REDGPU_NP_STRUCT_INIT(_s_b26e9376_outpHeap){value}; }
static inline _s_b26e9376_optionalFile _b26e9376_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b26e9376_optionalFile){value}; }
static inline _s_b26e9376_optionalLine _b26e9376_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b26e9376_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateHeap(_s_b26e9376_pDevice pDevice, _s_b26e9376_pDesc pDesc, _s_b26e9376_outpHeap outpHeap, _s_b26e9376_optionalFile optionalFile, _s_b26e9376_optionalLine optionalLine) {
  return x12DeviceCreateHeap(pDevice.value, pDesc.value, outpHeap.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceGetResourceAllocationInfo x12DeviceGetResourceAllocationInfo
#define _abfeb258_pDevice(value) value
#define _abfeb258_visibleMask(value) value
#define _abfeb258_numResourceDescs(value) value
#define _abfeb258_pResourceDescs(value) value
#define _abfeb258_outResourceAllocationInfo(value) value
#define _abfeb258_optionalFile(value) value
#define _abfeb258_optionalLine(value) value
#else
typedef struct _s_abfeb258_pDevice { X12Device3* value; } _s_abfeb258_pDevice;
typedef struct _s_abfeb258_visibleMask { unsigned value; } _s_abfeb258_visibleMask;
typedef struct _s_abfeb258_numResourceDescs { unsigned value; } _s_abfeb258_numResourceDescs;
typedef struct _s_abfeb258_pResourceDescs { D3D12_RESOURCE_DESC* value; } _s_abfeb258_pResourceDescs;
typedef struct _s_abfeb258_outResourceAllocationInfo { D3D12_RESOURCE_ALLOCATION_INFO* value; } _s_abfeb258_outResourceAllocationInfo;
typedef struct _s_abfeb258_optionalFile { char* value; } _s_abfeb258_optionalFile;
typedef struct _s_abfeb258_optionalLine { int value; } _s_abfeb258_optionalLine;
static inline _s_abfeb258_pDevice _abfeb258_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_abfeb258_pDevice){value}; }
static inline _s_abfeb258_visibleMask _abfeb258_visibleMask(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_abfeb258_visibleMask){value}; }
static inline _s_abfeb258_numResourceDescs _abfeb258_numResourceDescs(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_abfeb258_numResourceDescs){value}; }
static inline _s_abfeb258_pResourceDescs _abfeb258_pResourceDescs(D3D12_RESOURCE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_abfeb258_pResourceDescs){value}; }
static inline _s_abfeb258_outResourceAllocationInfo _abfeb258_outResourceAllocationInfo(D3D12_RESOURCE_ALLOCATION_INFO* value) { return REDGPU_NP_STRUCT_INIT(_s_abfeb258_outResourceAllocationInfo){value}; }
static inline _s_abfeb258_optionalFile _abfeb258_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_abfeb258_optionalFile){value}; }
static inline _s_abfeb258_optionalLine _abfeb258_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_abfeb258_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceGetResourceAllocationInfo(_s_abfeb258_pDevice pDevice, _s_abfeb258_visibleMask visibleMask, _s_abfeb258_numResourceDescs numResourceDescs, _s_abfeb258_pResourceDescs pResourceDescs, _s_abfeb258_outResourceAllocationInfo outResourceAllocationInfo, _s_abfeb258_optionalFile optionalFile, _s_abfeb258_optionalLine optionalLine) {
  x12DeviceGetResourceAllocationInfo(pDevice.value, visibleMask.value, numResourceDescs.value, pResourceDescs.value, outResourceAllocationInfo.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreatePlacedResource x12DeviceCreatePlacedResource
#define _00687acf_pDevice(value) value
#define _00687acf_pHeap(value) value
#define _00687acf_HeapOffset(value) value
#define _00687acf_pDesc(value) value
#define _00687acf_InitialState(value) value
#define _00687acf_pOptimizedClearValue(value) value
#define _00687acf_outpResource(value) value
#define _00687acf_optionalFile(value) value
#define _00687acf_optionalLine(value) value
#else
typedef struct _s_00687acf_pDevice { X12Device3* value; } _s_00687acf_pDevice;
typedef struct _s_00687acf_pHeap { X12Heap* value; } _s_00687acf_pHeap;
typedef struct _s_00687acf_HeapOffset { uint64_t value; } _s_00687acf_HeapOffset;
typedef struct _s_00687acf_pDesc { D3D12_RESOURCE_DESC* value; } _s_00687acf_pDesc;
typedef struct _s_00687acf_InitialState { D3D12_RESOURCE_STATES value; } _s_00687acf_InitialState;
typedef struct _s_00687acf_pOptimizedClearValue { D3D12_CLEAR_VALUE* value; } _s_00687acf_pOptimizedClearValue;
typedef struct _s_00687acf_outpResource { X12Resource** value; } _s_00687acf_outpResource;
typedef struct _s_00687acf_optionalFile { char* value; } _s_00687acf_optionalFile;
typedef struct _s_00687acf_optionalLine { int value; } _s_00687acf_optionalLine;
static inline _s_00687acf_pDevice _00687acf_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_00687acf_pDevice){value}; }
static inline _s_00687acf_pHeap _00687acf_pHeap(X12Heap* value) { return REDGPU_NP_STRUCT_INIT(_s_00687acf_pHeap){value}; }
static inline _s_00687acf_HeapOffset _00687acf_HeapOffset(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_00687acf_HeapOffset){value}; }
static inline _s_00687acf_pDesc _00687acf_pDesc(D3D12_RESOURCE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_00687acf_pDesc){value}; }
static inline _s_00687acf_InitialState _00687acf_InitialState(D3D12_RESOURCE_STATES value) { return REDGPU_NP_STRUCT_INIT(_s_00687acf_InitialState){value}; }
static inline _s_00687acf_pOptimizedClearValue _00687acf_pOptimizedClearValue(D3D12_CLEAR_VALUE* value) { return REDGPU_NP_STRUCT_INIT(_s_00687acf_pOptimizedClearValue){value}; }
static inline _s_00687acf_outpResource _00687acf_outpResource(X12Resource** value) { return REDGPU_NP_STRUCT_INIT(_s_00687acf_outpResource){value}; }
static inline _s_00687acf_optionalFile _00687acf_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_00687acf_optionalFile){value}; }
static inline _s_00687acf_optionalLine _00687acf_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_00687acf_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreatePlacedResource(_s_00687acf_pDevice pDevice, _s_00687acf_pHeap pHeap, _s_00687acf_HeapOffset HeapOffset, _s_00687acf_pDesc pDesc, _s_00687acf_InitialState InitialState, _s_00687acf_pOptimizedClearValue pOptimizedClearValue, _s_00687acf_outpResource outpResource, _s_00687acf_optionalFile optionalFile, _s_00687acf_optionalLine optionalLine) {
  return x12DeviceCreatePlacedResource(pDevice.value, pHeap.value, HeapOffset.value, pDesc.value, InitialState.value, pOptimizedClearValue.value, outpResource.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateCommittedResource x12DeviceCreateCommittedResource
#define _af30929d_pDevice(value) value
#define _af30929d_pHeapProperties(value) value
#define _af30929d_HeapFlags(value) value
#define _af30929d_pDesc(value) value
#define _af30929d_InitialResourceState(value) value
#define _af30929d_pOptimizedClearValue(value) value
#define _af30929d_outpResource(value) value
#define _af30929d_optionalFile(value) value
#define _af30929d_optionalLine(value) value
#else
typedef struct _s_af30929d_pDevice { X12Device3* value; } _s_af30929d_pDevice;
typedef struct _s_af30929d_pHeapProperties { D3D12_HEAP_PROPERTIES* value; } _s_af30929d_pHeapProperties;
typedef struct _s_af30929d_HeapFlags { D3D12_HEAP_FLAGS value; } _s_af30929d_HeapFlags;
typedef struct _s_af30929d_pDesc { D3D12_RESOURCE_DESC* value; } _s_af30929d_pDesc;
typedef struct _s_af30929d_InitialResourceState { D3D12_RESOURCE_STATES value; } _s_af30929d_InitialResourceState;
typedef struct _s_af30929d_pOptimizedClearValue { D3D12_CLEAR_VALUE* value; } _s_af30929d_pOptimizedClearValue;
typedef struct _s_af30929d_outpResource { X12Resource** value; } _s_af30929d_outpResource;
typedef struct _s_af30929d_optionalFile { char* value; } _s_af30929d_optionalFile;
typedef struct _s_af30929d_optionalLine { int value; } _s_af30929d_optionalLine;
static inline _s_af30929d_pDevice _af30929d_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_af30929d_pDevice){value}; }
static inline _s_af30929d_pHeapProperties _af30929d_pHeapProperties(D3D12_HEAP_PROPERTIES* value) { return REDGPU_NP_STRUCT_INIT(_s_af30929d_pHeapProperties){value}; }
static inline _s_af30929d_HeapFlags _af30929d_HeapFlags(D3D12_HEAP_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_af30929d_HeapFlags){value}; }
static inline _s_af30929d_pDesc _af30929d_pDesc(D3D12_RESOURCE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_af30929d_pDesc){value}; }
static inline _s_af30929d_InitialResourceState _af30929d_InitialResourceState(D3D12_RESOURCE_STATES value) { return REDGPU_NP_STRUCT_INIT(_s_af30929d_InitialResourceState){value}; }
static inline _s_af30929d_pOptimizedClearValue _af30929d_pOptimizedClearValue(D3D12_CLEAR_VALUE* value) { return REDGPU_NP_STRUCT_INIT(_s_af30929d_pOptimizedClearValue){value}; }
static inline _s_af30929d_outpResource _af30929d_outpResource(X12Resource** value) { return REDGPU_NP_STRUCT_INIT(_s_af30929d_outpResource){value}; }
static inline _s_af30929d_optionalFile _af30929d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_af30929d_optionalFile){value}; }
static inline _s_af30929d_optionalLine _af30929d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_af30929d_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateCommittedResource(_s_af30929d_pDevice pDevice, _s_af30929d_pHeapProperties pHeapProperties, _s_af30929d_HeapFlags HeapFlags, _s_af30929d_pDesc pDesc, _s_af30929d_InitialResourceState InitialResourceState, _s_af30929d_pOptimizedClearValue pOptimizedClearValue, _s_af30929d_outpResource outpResource, _s_af30929d_optionalFile optionalFile, _s_af30929d_optionalLine optionalLine) {
  return x12DeviceCreateCommittedResource(pDevice.value, pHeapProperties.value, HeapFlags.value, pDesc.value, InitialResourceState.value, pOptimizedClearValue.value, outpResource.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12ResourceMap x12ResourceMap
#define _78514594_pResource(value) value
#define _78514594_Subresource(value) value
#define _78514594_pReadRange(value) value
#define _78514594_outpData(value) value
#define _78514594_optionalFile(value) value
#define _78514594_optionalLine(value) value
#else
typedef struct _s_78514594_pResource { X12Resource* value; } _s_78514594_pResource;
typedef struct _s_78514594_Subresource { unsigned value; } _s_78514594_Subresource;
typedef struct _s_78514594_pReadRange { D3D12_RANGE* value; } _s_78514594_pReadRange;
typedef struct _s_78514594_outpData { void** value; } _s_78514594_outpData;
typedef struct _s_78514594_optionalFile { char* value; } _s_78514594_optionalFile;
typedef struct _s_78514594_optionalLine { int value; } _s_78514594_optionalLine;
static inline _s_78514594_pResource _78514594_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_78514594_pResource){value}; }
static inline _s_78514594_Subresource _78514594_Subresource(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_78514594_Subresource){value}; }
static inline _s_78514594_pReadRange _78514594_pReadRange(D3D12_RANGE* value) { return REDGPU_NP_STRUCT_INIT(_s_78514594_pReadRange){value}; }
static inline _s_78514594_outpData _78514594_outpData(void** value) { return REDGPU_NP_STRUCT_INIT(_s_78514594_outpData){value}; }
static inline _s_78514594_optionalFile _78514594_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_78514594_optionalFile){value}; }
static inline _s_78514594_optionalLine _78514594_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_78514594_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12ResourceMap(_s_78514594_pResource pResource, _s_78514594_Subresource Subresource, _s_78514594_pReadRange pReadRange, _s_78514594_outpData outpData, _s_78514594_optionalFile optionalFile, _s_78514594_optionalLine optionalLine) {
  return x12ResourceMap(pResource.value, Subresource.value, pReadRange.value, outpData.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12ResourceUnmap x12ResourceUnmap
#define _b2aac10d_pResource(value) value
#define _b2aac10d_Subresource(value) value
#define _b2aac10d_pWrittenRange(value) value
#define _b2aac10d_optionalFile(value) value
#define _b2aac10d_optionalLine(value) value
#else
typedef struct _s_b2aac10d_pResource { X12Resource* value; } _s_b2aac10d_pResource;
typedef struct _s_b2aac10d_Subresource { unsigned value; } _s_b2aac10d_Subresource;
typedef struct _s_b2aac10d_pWrittenRange { D3D12_RANGE* value; } _s_b2aac10d_pWrittenRange;
typedef struct _s_b2aac10d_optionalFile { char* value; } _s_b2aac10d_optionalFile;
typedef struct _s_b2aac10d_optionalLine { int value; } _s_b2aac10d_optionalLine;
static inline _s_b2aac10d_pResource _b2aac10d_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_b2aac10d_pResource){value}; }
static inline _s_b2aac10d_Subresource _b2aac10d_Subresource(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b2aac10d_Subresource){value}; }
static inline _s_b2aac10d_pWrittenRange _b2aac10d_pWrittenRange(D3D12_RANGE* value) { return REDGPU_NP_STRUCT_INIT(_s_b2aac10d_pWrittenRange){value}; }
static inline _s_b2aac10d_optionalFile _b2aac10d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b2aac10d_optionalFile){value}; }
static inline _s_b2aac10d_optionalLine _b2aac10d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b2aac10d_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12ResourceUnmap(_s_b2aac10d_pResource pResource, _s_b2aac10d_Subresource Subresource, _s_b2aac10d_pWrittenRange pWrittenRange, _s_b2aac10d_optionalFile optionalFile, _s_b2aac10d_optionalLine optionalLine) {
  x12ResourceUnmap(pResource.value, Subresource.value, pWrittenRange.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateDescriptorHeap x12DeviceCreateDescriptorHeap
#define _d49cdb24_pDevice(value) value
#define _d49cdb24_pDescriptorHeapDesc(value) value
#define _d49cdb24_outpHeap(value) value
#define _d49cdb24_optionalFile(value) value
#define _d49cdb24_optionalLine(value) value
#else
typedef struct _s_d49cdb24_pDevice { X12Device3* value; } _s_d49cdb24_pDevice;
typedef struct _s_d49cdb24_pDescriptorHeapDesc { D3D12_DESCRIPTOR_HEAP_DESC* value; } _s_d49cdb24_pDescriptorHeapDesc;
typedef struct _s_d49cdb24_outpHeap { X12DescriptorHeap** value; } _s_d49cdb24_outpHeap;
typedef struct _s_d49cdb24_optionalFile { char* value; } _s_d49cdb24_optionalFile;
typedef struct _s_d49cdb24_optionalLine { int value; } _s_d49cdb24_optionalLine;
static inline _s_d49cdb24_pDevice _d49cdb24_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_d49cdb24_pDevice){value}; }
static inline _s_d49cdb24_pDescriptorHeapDesc _d49cdb24_pDescriptorHeapDesc(D3D12_DESCRIPTOR_HEAP_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_d49cdb24_pDescriptorHeapDesc){value}; }
static inline _s_d49cdb24_outpHeap _d49cdb24_outpHeap(X12DescriptorHeap** value) { return REDGPU_NP_STRUCT_INIT(_s_d49cdb24_outpHeap){value}; }
static inline _s_d49cdb24_optionalFile _d49cdb24_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d49cdb24_optionalFile){value}; }
static inline _s_d49cdb24_optionalLine _d49cdb24_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d49cdb24_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateDescriptorHeap(_s_d49cdb24_pDevice pDevice, _s_d49cdb24_pDescriptorHeapDesc pDescriptorHeapDesc, _s_d49cdb24_outpHeap outpHeap, _s_d49cdb24_optionalFile optionalFile, _s_d49cdb24_optionalLine optionalLine) {
  return x12DeviceCreateDescriptorHeap(pDevice.value, pDescriptorHeapDesc.value, outpHeap.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DescriptorHeapGetCPUDescriptorHandleForHeapStart x12DescriptorHeapGetCPUDescriptorHandleForHeapStart
#define _9d9e29d9_pDescriptorHeap(value) value
#define _9d9e29d9_pCpuDescriptorHandle(value) value
#else
typedef struct _s_9d9e29d9_pDescriptorHeap { X12DescriptorHeap* value; } _s_9d9e29d9_pDescriptorHeap;
typedef struct _s_9d9e29d9_pCpuDescriptorHandle { D3D12_CPU_DESCRIPTOR_HANDLE* value; } _s_9d9e29d9_pCpuDescriptorHandle;
static inline _s_9d9e29d9_pDescriptorHeap _9d9e29d9_pDescriptorHeap(X12DescriptorHeap* value) { return REDGPU_NP_STRUCT_INIT(_s_9d9e29d9_pDescriptorHeap){value}; }
static inline _s_9d9e29d9_pCpuDescriptorHandle _9d9e29d9_pCpuDescriptorHandle(D3D12_CPU_DESCRIPTOR_HANDLE* value) { return REDGPU_NP_STRUCT_INIT(_s_9d9e29d9_pCpuDescriptorHandle){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(_s_9d9e29d9_pDescriptorHeap pDescriptorHeap, _s_9d9e29d9_pCpuDescriptorHandle pCpuDescriptorHandle) {
  x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(pDescriptorHeap.value, pCpuDescriptorHandle.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCopyDescriptors x12DeviceCopyDescriptors
#define _fd7af7d1_pDevice(value) value
#define _fd7af7d1_NumDestDescriptorRanges(value) value
#define _fd7af7d1_pDestDescriptorRangeStarts(value) value
#define _fd7af7d1_pDestDescriptorRangeSizes(value) value
#define _fd7af7d1_NumSrcDescriptorRanges(value) value
#define _fd7af7d1_pSrcDescriptorRangeStarts(value) value
#define _fd7af7d1_pSrcDescriptorRangeSizes(value) value
#define _fd7af7d1_DescriptorHeapsType(value) value
#define _fd7af7d1_optionalFile(value) value
#define _fd7af7d1_optionalLine(value) value
#else
typedef struct _s_fd7af7d1_pDevice { X12Device3* value; } _s_fd7af7d1_pDevice;
typedef struct _s_fd7af7d1_NumDestDescriptorRanges { unsigned value; } _s_fd7af7d1_NumDestDescriptorRanges;
typedef struct _s_fd7af7d1_pDestDescriptorRangeStarts { D3D12_CPU_DESCRIPTOR_HANDLE* value; } _s_fd7af7d1_pDestDescriptorRangeStarts;
typedef struct _s_fd7af7d1_pDestDescriptorRangeSizes { unsigned* value; } _s_fd7af7d1_pDestDescriptorRangeSizes;
typedef struct _s_fd7af7d1_NumSrcDescriptorRanges { unsigned value; } _s_fd7af7d1_NumSrcDescriptorRanges;
typedef struct _s_fd7af7d1_pSrcDescriptorRangeStarts { D3D12_CPU_DESCRIPTOR_HANDLE* value; } _s_fd7af7d1_pSrcDescriptorRangeStarts;
typedef struct _s_fd7af7d1_pSrcDescriptorRangeSizes { unsigned* value; } _s_fd7af7d1_pSrcDescriptorRangeSizes;
typedef struct _s_fd7af7d1_DescriptorHeapsType { D3D12_DESCRIPTOR_HEAP_TYPE value; } _s_fd7af7d1_DescriptorHeapsType;
typedef struct _s_fd7af7d1_optionalFile { char* value; } _s_fd7af7d1_optionalFile;
typedef struct _s_fd7af7d1_optionalLine { int value; } _s_fd7af7d1_optionalLine;
static inline _s_fd7af7d1_pDevice _fd7af7d1_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_fd7af7d1_pDevice){value}; }
static inline _s_fd7af7d1_NumDestDescriptorRanges _fd7af7d1_NumDestDescriptorRanges(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_fd7af7d1_NumDestDescriptorRanges){value}; }
static inline _s_fd7af7d1_pDestDescriptorRangeStarts _fd7af7d1_pDestDescriptorRangeStarts(D3D12_CPU_DESCRIPTOR_HANDLE* value) { return REDGPU_NP_STRUCT_INIT(_s_fd7af7d1_pDestDescriptorRangeStarts){value}; }
static inline _s_fd7af7d1_pDestDescriptorRangeSizes _fd7af7d1_pDestDescriptorRangeSizes(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_fd7af7d1_pDestDescriptorRangeSizes){value}; }
static inline _s_fd7af7d1_NumSrcDescriptorRanges _fd7af7d1_NumSrcDescriptorRanges(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_fd7af7d1_NumSrcDescriptorRanges){value}; }
static inline _s_fd7af7d1_pSrcDescriptorRangeStarts _fd7af7d1_pSrcDescriptorRangeStarts(D3D12_CPU_DESCRIPTOR_HANDLE* value) { return REDGPU_NP_STRUCT_INIT(_s_fd7af7d1_pSrcDescriptorRangeStarts){value}; }
static inline _s_fd7af7d1_pSrcDescriptorRangeSizes _fd7af7d1_pSrcDescriptorRangeSizes(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_fd7af7d1_pSrcDescriptorRangeSizes){value}; }
static inline _s_fd7af7d1_DescriptorHeapsType _fd7af7d1_DescriptorHeapsType(D3D12_DESCRIPTOR_HEAP_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_fd7af7d1_DescriptorHeapsType){value}; }
static inline _s_fd7af7d1_optionalFile _fd7af7d1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fd7af7d1_optionalFile){value}; }
static inline _s_fd7af7d1_optionalLine _fd7af7d1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fd7af7d1_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCopyDescriptors(_s_fd7af7d1_pDevice pDevice, _s_fd7af7d1_NumDestDescriptorRanges NumDestDescriptorRanges, _s_fd7af7d1_pDestDescriptorRangeStarts pDestDescriptorRangeStarts, _s_fd7af7d1_pDestDescriptorRangeSizes pDestDescriptorRangeSizes, _s_fd7af7d1_NumSrcDescriptorRanges NumSrcDescriptorRanges, _s_fd7af7d1_pSrcDescriptorRangeStarts pSrcDescriptorRangeStarts, _s_fd7af7d1_pSrcDescriptorRangeSizes pSrcDescriptorRangeSizes, _s_fd7af7d1_DescriptorHeapsType DescriptorHeapsType, _s_fd7af7d1_optionalFile optionalFile, _s_fd7af7d1_optionalLine optionalLine) {
  x12DeviceCopyDescriptors(pDevice.value, NumDestDescriptorRanges.value, pDestDescriptorRangeStarts.value, pDestDescriptorRangeSizes.value, NumSrcDescriptorRanges.value, pSrcDescriptorRangeStarts.value, pSrcDescriptorRangeSizes.value, DescriptorHeapsType.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DescriptorHeapGetGPUDescriptorHandleForHeapStart x12DescriptorHeapGetGPUDescriptorHandleForHeapStart
#define _194d8253_pDescriptorHeap(value) value
#define _194d8253_pGpuDescriptorHandle(value) value
#else
typedef struct _s_194d8253_pDescriptorHeap { X12DescriptorHeap* value; } _s_194d8253_pDescriptorHeap;
typedef struct _s_194d8253_pGpuDescriptorHandle { D3D12_GPU_DESCRIPTOR_HANDLE* value; } _s_194d8253_pGpuDescriptorHandle;
static inline _s_194d8253_pDescriptorHeap _194d8253_pDescriptorHeap(X12DescriptorHeap* value) { return REDGPU_NP_STRUCT_INIT(_s_194d8253_pDescriptorHeap){value}; }
static inline _s_194d8253_pGpuDescriptorHandle _194d8253_pGpuDescriptorHandle(D3D12_GPU_DESCRIPTOR_HANDLE* value) { return REDGPU_NP_STRUCT_INIT(_s_194d8253_pGpuDescriptorHandle){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DescriptorHeapGetGPUDescriptorHandleForHeapStart(_s_194d8253_pDescriptorHeap pDescriptorHeap, _s_194d8253_pGpuDescriptorHandle pGpuDescriptorHandle) {
  x12DescriptorHeapGetGPUDescriptorHandleForHeapStart(pDescriptorHeap.value, pGpuDescriptorHandle.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceSetResidencyPriority x12DeviceSetResidencyPriority
#define _9b4b70db_pDevice(value) value
#define _9b4b70db_NumObjects(value) value
#define _9b4b70db_ppObjects(value) value
#define _9b4b70db_pPriorities(value) value
#define _9b4b70db_optionalFile(value) value
#define _9b4b70db_optionalLine(value) value
#else
typedef struct _s_9b4b70db_pDevice { X12Device3* value; } _s_9b4b70db_pDevice;
typedef struct _s_9b4b70db_NumObjects { unsigned value; } _s_9b4b70db_NumObjects;
typedef struct _s_9b4b70db_ppObjects { X12Pageable** value; } _s_9b4b70db_ppObjects;
typedef struct _s_9b4b70db_pPriorities { unsigned* value; } _s_9b4b70db_pPriorities;
typedef struct _s_9b4b70db_optionalFile { char* value; } _s_9b4b70db_optionalFile;
typedef struct _s_9b4b70db_optionalLine { int value; } _s_9b4b70db_optionalLine;
static inline _s_9b4b70db_pDevice _9b4b70db_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_9b4b70db_pDevice){value}; }
static inline _s_9b4b70db_NumObjects _9b4b70db_NumObjects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9b4b70db_NumObjects){value}; }
static inline _s_9b4b70db_ppObjects _9b4b70db_ppObjects(X12Pageable** value) { return REDGPU_NP_STRUCT_INIT(_s_9b4b70db_ppObjects){value}; }
static inline _s_9b4b70db_pPriorities _9b4b70db_pPriorities(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_9b4b70db_pPriorities){value}; }
static inline _s_9b4b70db_optionalFile _9b4b70db_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9b4b70db_optionalFile){value}; }
static inline _s_9b4b70db_optionalLine _9b4b70db_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9b4b70db_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceSetResidencyPriority(_s_9b4b70db_pDevice pDevice, _s_9b4b70db_NumObjects NumObjects, _s_9b4b70db_ppObjects ppObjects, _s_9b4b70db_pPriorities pPriorities, _s_9b4b70db_optionalFile optionalFile, _s_9b4b70db_optionalLine optionalLine) {
  return x12DeviceSetResidencyPriority(pDevice.value, NumObjects.value, ppObjects.value, pPriorities.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceEvict x12DeviceEvict
#define _100896fa_pDevice(value) value
#define _100896fa_NumObjects(value) value
#define _100896fa_ppObjects(value) value
#define _100896fa_optionalFile(value) value
#define _100896fa_optionalLine(value) value
#else
typedef struct _s_100896fa_pDevice { X12Device3* value; } _s_100896fa_pDevice;
typedef struct _s_100896fa_NumObjects { unsigned value; } _s_100896fa_NumObjects;
typedef struct _s_100896fa_ppObjects { X12Pageable** value; } _s_100896fa_ppObjects;
typedef struct _s_100896fa_optionalFile { char* value; } _s_100896fa_optionalFile;
typedef struct _s_100896fa_optionalLine { int value; } _s_100896fa_optionalLine;
static inline _s_100896fa_pDevice _100896fa_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_100896fa_pDevice){value}; }
static inline _s_100896fa_NumObjects _100896fa_NumObjects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_100896fa_NumObjects){value}; }
static inline _s_100896fa_ppObjects _100896fa_ppObjects(X12Pageable** value) { return REDGPU_NP_STRUCT_INIT(_s_100896fa_ppObjects){value}; }
static inline _s_100896fa_optionalFile _100896fa_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_100896fa_optionalFile){value}; }
static inline _s_100896fa_optionalLine _100896fa_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_100896fa_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceEvict(_s_100896fa_pDevice pDevice, _s_100896fa_NumObjects NumObjects, _s_100896fa_ppObjects ppObjects, _s_100896fa_optionalFile optionalFile, _s_100896fa_optionalLine optionalLine) {
  return x12DeviceEvict(pDevice.value, NumObjects.value, ppObjects.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceMakeResident x12DeviceMakeResident
#define _99402084_pDevice(value) value
#define _99402084_NumObjects(value) value
#define _99402084_ppObjects(value) value
#define _99402084_optionalFile(value) value
#define _99402084_optionalLine(value) value
#else
typedef struct _s_99402084_pDevice { X12Device3* value; } _s_99402084_pDevice;
typedef struct _s_99402084_NumObjects { unsigned value; } _s_99402084_NumObjects;
typedef struct _s_99402084_ppObjects { X12Pageable** value; } _s_99402084_ppObjects;
typedef struct _s_99402084_optionalFile { char* value; } _s_99402084_optionalFile;
typedef struct _s_99402084_optionalLine { int value; } _s_99402084_optionalLine;
static inline _s_99402084_pDevice _99402084_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_99402084_pDevice){value}; }
static inline _s_99402084_NumObjects _99402084_NumObjects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_99402084_NumObjects){value}; }
static inline _s_99402084_ppObjects _99402084_ppObjects(X12Pageable** value) { return REDGPU_NP_STRUCT_INIT(_s_99402084_ppObjects){value}; }
static inline _s_99402084_optionalFile _99402084_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_99402084_optionalFile){value}; }
static inline _s_99402084_optionalLine _99402084_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_99402084_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceMakeResident(_s_99402084_pDevice pDevice, _s_99402084_NumObjects NumObjects, _s_99402084_ppObjects ppObjects, _s_99402084_optionalFile optionalFile, _s_99402084_optionalLine optionalLine) {
  return x12DeviceMakeResident(pDevice.value, NumObjects.value, ppObjects.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceEnqueueMakeResident x12DeviceEnqueueMakeResident
#define _5a205dd0_pDevice(value) value
#define _5a205dd0_Flags(value) value
#define _5a205dd0_NumObjects(value) value
#define _5a205dd0_ppObjects(value) value
#define _5a205dd0_pFenceToSignal(value) value
#define _5a205dd0_FenceValueToSignal(value) value
#define _5a205dd0_optionalFile(value) value
#define _5a205dd0_optionalLine(value) value
#else
typedef struct _s_5a205dd0_pDevice { X12Device3* value; } _s_5a205dd0_pDevice;
typedef struct _s_5a205dd0_Flags { D3D12_RESIDENCY_FLAGS value; } _s_5a205dd0_Flags;
typedef struct _s_5a205dd0_NumObjects { unsigned value; } _s_5a205dd0_NumObjects;
typedef struct _s_5a205dd0_ppObjects { X12Pageable** value; } _s_5a205dd0_ppObjects;
typedef struct _s_5a205dd0_pFenceToSignal { X12Fence* value; } _s_5a205dd0_pFenceToSignal;
typedef struct _s_5a205dd0_FenceValueToSignal { uint64_t value; } _s_5a205dd0_FenceValueToSignal;
typedef struct _s_5a205dd0_optionalFile { char* value; } _s_5a205dd0_optionalFile;
typedef struct _s_5a205dd0_optionalLine { int value; } _s_5a205dd0_optionalLine;
static inline _s_5a205dd0_pDevice _5a205dd0_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_5a205dd0_pDevice){value}; }
static inline _s_5a205dd0_Flags _5a205dd0_Flags(D3D12_RESIDENCY_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_5a205dd0_Flags){value}; }
static inline _s_5a205dd0_NumObjects _5a205dd0_NumObjects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_5a205dd0_NumObjects){value}; }
static inline _s_5a205dd0_ppObjects _5a205dd0_ppObjects(X12Pageable** value) { return REDGPU_NP_STRUCT_INIT(_s_5a205dd0_ppObjects){value}; }
static inline _s_5a205dd0_pFenceToSignal _5a205dd0_pFenceToSignal(X12Fence* value) { return REDGPU_NP_STRUCT_INIT(_s_5a205dd0_pFenceToSignal){value}; }
static inline _s_5a205dd0_FenceValueToSignal _5a205dd0_FenceValueToSignal(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_5a205dd0_FenceValueToSignal){value}; }
static inline _s_5a205dd0_optionalFile _5a205dd0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5a205dd0_optionalFile){value}; }
static inline _s_5a205dd0_optionalLine _5a205dd0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5a205dd0_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceEnqueueMakeResident(_s_5a205dd0_pDevice pDevice, _s_5a205dd0_Flags Flags, _s_5a205dd0_NumObjects NumObjects, _s_5a205dd0_ppObjects ppObjects, _s_5a205dd0_pFenceToSignal pFenceToSignal, _s_5a205dd0_FenceValueToSignal FenceValueToSignal, _s_5a205dd0_optionalFile optionalFile, _s_5a205dd0_optionalLine optionalLine) {
  return x12DeviceEnqueueMakeResident(pDevice.value, Flags.value, NumObjects.value, ppObjects.value, pFenceToSignal.value, FenceValueToSignal.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DebugEnable x12DebugEnable
#define _cdead04c_optionalFile(value) value
#define _cdead04c_optionalLine(value) value
#else
typedef struct _s_cdead04c_optionalFile { char* value; } _s_cdead04c_optionalFile;
typedef struct _s_cdead04c_optionalLine { int value; } _s_cdead04c_optionalLine;
static inline _s_cdead04c_optionalFile _cdead04c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cdead04c_optionalFile){value}; }
static inline _s_cdead04c_optionalLine _cdead04c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cdead04c_optionalLine){value}; }
REDGPU_NP_DECLSPEC void* REDGPU_NP_API np_x12DebugEnable(_s_cdead04c_optionalFile optionalFile, _s_cdead04c_optionalLine optionalLine) {
  return x12DebugEnable(optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DebugReport x12DebugReport
#define _a0057177_debugContext(value) value
#define _a0057177_optionalFile(value) value
#define _a0057177_optionalLine(value) value
#else
typedef struct _s_a0057177_debugContext { void* value; } _s_a0057177_debugContext;
typedef struct _s_a0057177_optionalFile { char* value; } _s_a0057177_optionalFile;
typedef struct _s_a0057177_optionalLine { int value; } _s_a0057177_optionalLine;
static inline _s_a0057177_debugContext _a0057177_debugContext(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a0057177_debugContext){value}; }
static inline _s_a0057177_optionalFile _a0057177_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a0057177_optionalFile){value}; }
static inline _s_a0057177_optionalLine _a0057177_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a0057177_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DebugReport(_s_a0057177_debugContext debugContext, _s_a0057177_optionalFile optionalFile, _s_a0057177_optionalLine optionalLine) {
  x12DebugReport(debugContext.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CreateFactory2 x12CreateFactory2
#define _e35b5955_Flags(value) value
#define _e35b5955_outpFactory(value) value
#define _e35b5955_optionalFile(value) value
#define _e35b5955_optionalLine(value) value
#else
typedef struct _s_e35b5955_Flags { DXGI_CREATE_FACTORY_FLAGS value; } _s_e35b5955_Flags;
typedef struct _s_e35b5955_outpFactory { X12Factory4** value; } _s_e35b5955_outpFactory;
typedef struct _s_e35b5955_optionalFile { char* value; } _s_e35b5955_optionalFile;
typedef struct _s_e35b5955_optionalLine { int value; } _s_e35b5955_optionalLine;
static inline _s_e35b5955_Flags _e35b5955_Flags(DXGI_CREATE_FACTORY_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_e35b5955_Flags){value}; }
static inline _s_e35b5955_outpFactory _e35b5955_outpFactory(X12Factory4** value) { return REDGPU_NP_STRUCT_INIT(_s_e35b5955_outpFactory){value}; }
static inline _s_e35b5955_optionalFile _e35b5955_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e35b5955_optionalFile){value}; }
static inline _s_e35b5955_optionalLine _e35b5955_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e35b5955_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CreateFactory2(_s_e35b5955_Flags Flags, _s_e35b5955_outpFactory outpFactory, _s_e35b5955_optionalFile optionalFile, _s_e35b5955_optionalLine optionalLine) {
  return x12CreateFactory2(Flags.value, outpFactory.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryEnumAdapters1 x12FactoryEnumAdapters1
#define _dbf9ca0f_pFactory(value) value
#define _dbf9ca0f_Adapter(value) value
#define _dbf9ca0f_outpAdapter(value) value
#define _dbf9ca0f_optionalFile(value) value
#define _dbf9ca0f_optionalLine(value) value
#else
typedef struct _s_dbf9ca0f_pFactory { X12Factory4* value; } _s_dbf9ca0f_pFactory;
typedef struct _s_dbf9ca0f_Adapter { unsigned value; } _s_dbf9ca0f_Adapter;
typedef struct _s_dbf9ca0f_outpAdapter { X12Adapter3** value; } _s_dbf9ca0f_outpAdapter;
typedef struct _s_dbf9ca0f_optionalFile { char* value; } _s_dbf9ca0f_optionalFile;
typedef struct _s_dbf9ca0f_optionalLine { int value; } _s_dbf9ca0f_optionalLine;
static inline _s_dbf9ca0f_pFactory _dbf9ca0f_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_dbf9ca0f_pFactory){value}; }
static inline _s_dbf9ca0f_Adapter _dbf9ca0f_Adapter(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_dbf9ca0f_Adapter){value}; }
static inline _s_dbf9ca0f_outpAdapter _dbf9ca0f_outpAdapter(X12Adapter3** value) { return REDGPU_NP_STRUCT_INIT(_s_dbf9ca0f_outpAdapter){value}; }
static inline _s_dbf9ca0f_optionalFile _dbf9ca0f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_dbf9ca0f_optionalFile){value}; }
static inline _s_dbf9ca0f_optionalLine _dbf9ca0f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_dbf9ca0f_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryEnumAdapters1(_s_dbf9ca0f_pFactory pFactory, _s_dbf9ca0f_Adapter Adapter, _s_dbf9ca0f_outpAdapter outpAdapter, _s_dbf9ca0f_optionalFile optionalFile, _s_dbf9ca0f_optionalLine optionalLine) {
  return x12FactoryEnumAdapters1(pFactory.value, Adapter.value, outpAdapter.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CreateDevice x12CreateDevice
#define _d2037500_pAdapter(value) value
#define _d2037500_MinimumFeatureLevel(value) value
#define _d2037500_outpDevice(value) value
#define _d2037500_optionalFile(value) value
#define _d2037500_optionalLine(value) value
#else
typedef struct _s_d2037500_pAdapter { X12Adapter3* value; } _s_d2037500_pAdapter;
typedef struct _s_d2037500_MinimumFeatureLevel { D3D_FEATURE_LEVEL value; } _s_d2037500_MinimumFeatureLevel;
typedef struct _s_d2037500_outpDevice { X12Device3** value; } _s_d2037500_outpDevice;
typedef struct _s_d2037500_optionalFile { char* value; } _s_d2037500_optionalFile;
typedef struct _s_d2037500_optionalLine { int value; } _s_d2037500_optionalLine;
static inline _s_d2037500_pAdapter _d2037500_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_d2037500_pAdapter){value}; }
static inline _s_d2037500_MinimumFeatureLevel _d2037500_MinimumFeatureLevel(D3D_FEATURE_LEVEL value) { return REDGPU_NP_STRUCT_INIT(_s_d2037500_MinimumFeatureLevel){value}; }
static inline _s_d2037500_outpDevice _d2037500_outpDevice(X12Device3** value) { return REDGPU_NP_STRUCT_INIT(_s_d2037500_outpDevice){value}; }
static inline _s_d2037500_optionalFile _d2037500_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d2037500_optionalFile){value}; }
static inline _s_d2037500_optionalLine _d2037500_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d2037500_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CreateDevice(_s_d2037500_pAdapter pAdapter, _s_d2037500_MinimumFeatureLevel MinimumFeatureLevel, _s_d2037500_outpDevice outpDevice, _s_d2037500_optionalFile optionalFile, _s_d2037500_optionalLine optionalLine) {
  return x12CreateDevice(pAdapter.value, MinimumFeatureLevel.value, outpDevice.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateUnorderedAccessView x12DeviceCreateUnorderedAccessView
#define _b52e21e8_pDevice(value) value
#define _b52e21e8_pResource(value) value
#define _b52e21e8_pCounterResource(value) value
#define _b52e21e8_pDesc(value) value
#define _b52e21e8_DestDescriptor(value) value
#define _b52e21e8_optionalFile(value) value
#define _b52e21e8_optionalLine(value) value
#else
typedef struct _s_b52e21e8_pDevice { X12Device3* value; } _s_b52e21e8_pDevice;
typedef struct _s_b52e21e8_pResource { X12Resource* value; } _s_b52e21e8_pResource;
typedef struct _s_b52e21e8_pCounterResource { X12Resource* value; } _s_b52e21e8_pCounterResource;
typedef struct _s_b52e21e8_pDesc { D3D12_UNORDERED_ACCESS_VIEW_DESC* value; } _s_b52e21e8_pDesc;
typedef struct _s_b52e21e8_DestDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_b52e21e8_DestDescriptor;
typedef struct _s_b52e21e8_optionalFile { char* value; } _s_b52e21e8_optionalFile;
typedef struct _s_b52e21e8_optionalLine { int value; } _s_b52e21e8_optionalLine;
static inline _s_b52e21e8_pDevice _b52e21e8_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_b52e21e8_pDevice){value}; }
static inline _s_b52e21e8_pResource _b52e21e8_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_b52e21e8_pResource){value}; }
static inline _s_b52e21e8_pCounterResource _b52e21e8_pCounterResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_b52e21e8_pCounterResource){value}; }
static inline _s_b52e21e8_pDesc _b52e21e8_pDesc(D3D12_UNORDERED_ACCESS_VIEW_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_b52e21e8_pDesc){value}; }
static inline _s_b52e21e8_DestDescriptor _b52e21e8_DestDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_b52e21e8_DestDescriptor){value}; }
static inline _s_b52e21e8_optionalFile _b52e21e8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b52e21e8_optionalFile){value}; }
static inline _s_b52e21e8_optionalLine _b52e21e8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b52e21e8_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCreateUnorderedAccessView(_s_b52e21e8_pDevice pDevice, _s_b52e21e8_pResource pResource, _s_b52e21e8_pCounterResource pCounterResource, _s_b52e21e8_pDesc pDesc, _s_b52e21e8_DestDescriptor DestDescriptor, _s_b52e21e8_optionalFile optionalFile, _s_b52e21e8_optionalLine optionalLine) {
  x12DeviceCreateUnorderedAccessView(pDevice.value, pResource.value, pCounterResource.value, pDesc.value, DestDescriptor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateShaderResourceView x12DeviceCreateShaderResourceView
#define _74230bad_pDevice(value) value
#define _74230bad_pResource(value) value
#define _74230bad_pDesc(value) value
#define _74230bad_DestDescriptor(value) value
#define _74230bad_optionalFile(value) value
#define _74230bad_optionalLine(value) value
#else
typedef struct _s_74230bad_pDevice { X12Device3* value; } _s_74230bad_pDevice;
typedef struct _s_74230bad_pResource { X12Resource* value; } _s_74230bad_pResource;
typedef struct _s_74230bad_pDesc { D3D12_SHADER_RESOURCE_VIEW_DESC* value; } _s_74230bad_pDesc;
typedef struct _s_74230bad_DestDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_74230bad_DestDescriptor;
typedef struct _s_74230bad_optionalFile { char* value; } _s_74230bad_optionalFile;
typedef struct _s_74230bad_optionalLine { int value; } _s_74230bad_optionalLine;
static inline _s_74230bad_pDevice _74230bad_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_74230bad_pDevice){value}; }
static inline _s_74230bad_pResource _74230bad_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_74230bad_pResource){value}; }
static inline _s_74230bad_pDesc _74230bad_pDesc(D3D12_SHADER_RESOURCE_VIEW_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_74230bad_pDesc){value}; }
static inline _s_74230bad_DestDescriptor _74230bad_DestDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_74230bad_DestDescriptor){value}; }
static inline _s_74230bad_optionalFile _74230bad_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_74230bad_optionalFile){value}; }
static inline _s_74230bad_optionalLine _74230bad_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_74230bad_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCreateShaderResourceView(_s_74230bad_pDevice pDevice, _s_74230bad_pResource pResource, _s_74230bad_pDesc pDesc, _s_74230bad_DestDescriptor DestDescriptor, _s_74230bad_optionalFile optionalFile, _s_74230bad_optionalLine optionalLine) {
  x12DeviceCreateShaderResourceView(pDevice.value, pResource.value, pDesc.value, DestDescriptor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateConstantBufferView x12DeviceCreateConstantBufferView
#define _26025065_pDevice(value) value
#define _26025065_pDesc(value) value
#define _26025065_DestDescriptor(value) value
#define _26025065_optionalFile(value) value
#define _26025065_optionalLine(value) value
#else
typedef struct _s_26025065_pDevice { X12Device3* value; } _s_26025065_pDevice;
typedef struct _s_26025065_pDesc { D3D12_CONSTANT_BUFFER_VIEW_DESC* value; } _s_26025065_pDesc;
typedef struct _s_26025065_DestDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_26025065_DestDescriptor;
typedef struct _s_26025065_optionalFile { char* value; } _s_26025065_optionalFile;
typedef struct _s_26025065_optionalLine { int value; } _s_26025065_optionalLine;
static inline _s_26025065_pDevice _26025065_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_26025065_pDevice){value}; }
static inline _s_26025065_pDesc _26025065_pDesc(D3D12_CONSTANT_BUFFER_VIEW_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_26025065_pDesc){value}; }
static inline _s_26025065_DestDescriptor _26025065_DestDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_26025065_DestDescriptor){value}; }
static inline _s_26025065_optionalFile _26025065_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_26025065_optionalFile){value}; }
static inline _s_26025065_optionalLine _26025065_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_26025065_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCreateConstantBufferView(_s_26025065_pDevice pDevice, _s_26025065_pDesc pDesc, _s_26025065_DestDescriptor DestDescriptor, _s_26025065_optionalFile optionalFile, _s_26025065_optionalLine optionalLine) {
  x12DeviceCreateConstantBufferView(pDevice.value, pDesc.value, DestDescriptor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateSampler x12DeviceCreateSampler
#define _621dd58e_pDevice(value) value
#define _621dd58e_pDesc(value) value
#define _621dd58e_DestDescriptor(value) value
#define _621dd58e_optionalFile(value) value
#define _621dd58e_optionalLine(value) value
#else
typedef struct _s_621dd58e_pDevice { X12Device3* value; } _s_621dd58e_pDevice;
typedef struct _s_621dd58e_pDesc { D3D12_SAMPLER_DESC* value; } _s_621dd58e_pDesc;
typedef struct _s_621dd58e_DestDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_621dd58e_DestDescriptor;
typedef struct _s_621dd58e_optionalFile { char* value; } _s_621dd58e_optionalFile;
typedef struct _s_621dd58e_optionalLine { int value; } _s_621dd58e_optionalLine;
static inline _s_621dd58e_pDevice _621dd58e_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_621dd58e_pDevice){value}; }
static inline _s_621dd58e_pDesc _621dd58e_pDesc(D3D12_SAMPLER_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_621dd58e_pDesc){value}; }
static inline _s_621dd58e_DestDescriptor _621dd58e_DestDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_621dd58e_DestDescriptor){value}; }
static inline _s_621dd58e_optionalFile _621dd58e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_621dd58e_optionalFile){value}; }
static inline _s_621dd58e_optionalLine _621dd58e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_621dd58e_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCreateSampler(_s_621dd58e_pDevice pDevice, _s_621dd58e_pDesc pDesc, _s_621dd58e_DestDescriptor DestDescriptor, _s_621dd58e_optionalFile optionalFile, _s_621dd58e_optionalLine optionalLine) {
  x12DeviceCreateSampler(pDevice.value, pDesc.value, DestDescriptor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateRenderTargetView x12DeviceCreateRenderTargetView
#define _e7e93fc6_pDevice(value) value
#define _e7e93fc6_pResource(value) value
#define _e7e93fc6_pDesc(value) value
#define _e7e93fc6_DestDescriptor(value) value
#define _e7e93fc6_optionalFile(value) value
#define _e7e93fc6_optionalLine(value) value
#else
typedef struct _s_e7e93fc6_pDevice { X12Device3* value; } _s_e7e93fc6_pDevice;
typedef struct _s_e7e93fc6_pResource { X12Resource* value; } _s_e7e93fc6_pResource;
typedef struct _s_e7e93fc6_pDesc { D3D12_RENDER_TARGET_VIEW_DESC* value; } _s_e7e93fc6_pDesc;
typedef struct _s_e7e93fc6_DestDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_e7e93fc6_DestDescriptor;
typedef struct _s_e7e93fc6_optionalFile { char* value; } _s_e7e93fc6_optionalFile;
typedef struct _s_e7e93fc6_optionalLine { int value; } _s_e7e93fc6_optionalLine;
static inline _s_e7e93fc6_pDevice _e7e93fc6_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_e7e93fc6_pDevice){value}; }
static inline _s_e7e93fc6_pResource _e7e93fc6_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_e7e93fc6_pResource){value}; }
static inline _s_e7e93fc6_pDesc _e7e93fc6_pDesc(D3D12_RENDER_TARGET_VIEW_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_e7e93fc6_pDesc){value}; }
static inline _s_e7e93fc6_DestDescriptor _e7e93fc6_DestDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_e7e93fc6_DestDescriptor){value}; }
static inline _s_e7e93fc6_optionalFile _e7e93fc6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e7e93fc6_optionalFile){value}; }
static inline _s_e7e93fc6_optionalLine _e7e93fc6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e7e93fc6_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCreateRenderTargetView(_s_e7e93fc6_pDevice pDevice, _s_e7e93fc6_pResource pResource, _s_e7e93fc6_pDesc pDesc, _s_e7e93fc6_DestDescriptor DestDescriptor, _s_e7e93fc6_optionalFile optionalFile, _s_e7e93fc6_optionalLine optionalLine) {
  x12DeviceCreateRenderTargetView(pDevice.value, pResource.value, pDesc.value, DestDescriptor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateDepthStencilView x12DeviceCreateDepthStencilView
#define _a421bcf3_pDevice(value) value
#define _a421bcf3_pResource(value) value
#define _a421bcf3_pDesc(value) value
#define _a421bcf3_DestDescriptor(value) value
#define _a421bcf3_optionalFile(value) value
#define _a421bcf3_optionalLine(value) value
#else
typedef struct _s_a421bcf3_pDevice { X12Device3* value; } _s_a421bcf3_pDevice;
typedef struct _s_a421bcf3_pResource { X12Resource* value; } _s_a421bcf3_pResource;
typedef struct _s_a421bcf3_pDesc { D3D12_DEPTH_STENCIL_VIEW_DESC* value; } _s_a421bcf3_pDesc;
typedef struct _s_a421bcf3_DestDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_a421bcf3_DestDescriptor;
typedef struct _s_a421bcf3_optionalFile { char* value; } _s_a421bcf3_optionalFile;
typedef struct _s_a421bcf3_optionalLine { int value; } _s_a421bcf3_optionalLine;
static inline _s_a421bcf3_pDevice _a421bcf3_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_a421bcf3_pDevice){value}; }
static inline _s_a421bcf3_pResource _a421bcf3_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_a421bcf3_pResource){value}; }
static inline _s_a421bcf3_pDesc _a421bcf3_pDesc(D3D12_DEPTH_STENCIL_VIEW_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_a421bcf3_pDesc){value}; }
static inline _s_a421bcf3_DestDescriptor _a421bcf3_DestDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_a421bcf3_DestDescriptor){value}; }
static inline _s_a421bcf3_optionalFile _a421bcf3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a421bcf3_optionalFile){value}; }
static inline _s_a421bcf3_optionalLine _a421bcf3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a421bcf3_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceCreateDepthStencilView(_s_a421bcf3_pDevice pDevice, _s_a421bcf3_pResource pResource, _s_a421bcf3_pDesc pDesc, _s_a421bcf3_DestDescriptor DestDescriptor, _s_a421bcf3_optionalFile optionalFile, _s_a421bcf3_optionalLine optionalLine) {
  x12DeviceCreateDepthStencilView(pDevice.value, pResource.value, pDesc.value, DestDescriptor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SerializeRootSignature x12SerializeRootSignature
#define _d103985c_pRootSignature(value) value
#define _d103985c_Version(value) value
#define _d103985c_outpBlob(value) value
#define _d103985c_outpErrorBlob(value) value
#define _d103985c_optionalFile(value) value
#define _d103985c_optionalLine(value) value
#else
typedef struct _s_d103985c_pRootSignature { D3D12_ROOT_SIGNATURE_DESC* value; } _s_d103985c_pRootSignature;
typedef struct _s_d103985c_Version { D3D_ROOT_SIGNATURE_VERSION value; } _s_d103985c_Version;
typedef struct _s_d103985c_outpBlob { X12Blob** value; } _s_d103985c_outpBlob;
typedef struct _s_d103985c_outpErrorBlob { X12Blob** value; } _s_d103985c_outpErrorBlob;
typedef struct _s_d103985c_optionalFile { char* value; } _s_d103985c_optionalFile;
typedef struct _s_d103985c_optionalLine { int value; } _s_d103985c_optionalLine;
static inline _s_d103985c_pRootSignature _d103985c_pRootSignature(D3D12_ROOT_SIGNATURE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_d103985c_pRootSignature){value}; }
static inline _s_d103985c_Version _d103985c_Version(D3D_ROOT_SIGNATURE_VERSION value) { return REDGPU_NP_STRUCT_INIT(_s_d103985c_Version){value}; }
static inline _s_d103985c_outpBlob _d103985c_outpBlob(X12Blob** value) { return REDGPU_NP_STRUCT_INIT(_s_d103985c_outpBlob){value}; }
static inline _s_d103985c_outpErrorBlob _d103985c_outpErrorBlob(X12Blob** value) { return REDGPU_NP_STRUCT_INIT(_s_d103985c_outpErrorBlob){value}; }
static inline _s_d103985c_optionalFile _d103985c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d103985c_optionalFile){value}; }
static inline _s_d103985c_optionalLine _d103985c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d103985c_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SerializeRootSignature(_s_d103985c_pRootSignature pRootSignature, _s_d103985c_Version Version, _s_d103985c_outpBlob outpBlob, _s_d103985c_outpErrorBlob outpErrorBlob, _s_d103985c_optionalFile optionalFile, _s_d103985c_optionalLine optionalLine) {
  return x12SerializeRootSignature(pRootSignature.value, Version.value, outpBlob.value, outpErrorBlob.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateRootSignature x12DeviceCreateRootSignature
#define _e5a1795e_pDevice(value) value
#define _e5a1795e_nodeMask(value) value
#define _e5a1795e_pBlobWithRootSignature(value) value
#define _e5a1795e_blobLengthInBytes(value) value
#define _e5a1795e_outpRootSignature(value) value
#define _e5a1795e_optionalFile(value) value
#define _e5a1795e_optionalLine(value) value
#else
typedef struct _s_e5a1795e_pDevice { X12Device3* value; } _s_e5a1795e_pDevice;
typedef struct _s_e5a1795e_nodeMask { unsigned value; } _s_e5a1795e_nodeMask;
typedef struct _s_e5a1795e_pBlobWithRootSignature { void* value; } _s_e5a1795e_pBlobWithRootSignature;
typedef struct _s_e5a1795e_blobLengthInBytes { size_t value; } _s_e5a1795e_blobLengthInBytes;
typedef struct _s_e5a1795e_outpRootSignature { X12RootSignature** value; } _s_e5a1795e_outpRootSignature;
typedef struct _s_e5a1795e_optionalFile { char* value; } _s_e5a1795e_optionalFile;
typedef struct _s_e5a1795e_optionalLine { int value; } _s_e5a1795e_optionalLine;
static inline _s_e5a1795e_pDevice _e5a1795e_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_e5a1795e_pDevice){value}; }
static inline _s_e5a1795e_nodeMask _e5a1795e_nodeMask(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e5a1795e_nodeMask){value}; }
static inline _s_e5a1795e_pBlobWithRootSignature _e5a1795e_pBlobWithRootSignature(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e5a1795e_pBlobWithRootSignature){value}; }
static inline _s_e5a1795e_blobLengthInBytes _e5a1795e_blobLengthInBytes(size_t value) { return REDGPU_NP_STRUCT_INIT(_s_e5a1795e_blobLengthInBytes){value}; }
static inline _s_e5a1795e_outpRootSignature _e5a1795e_outpRootSignature(X12RootSignature** value) { return REDGPU_NP_STRUCT_INIT(_s_e5a1795e_outpRootSignature){value}; }
static inline _s_e5a1795e_optionalFile _e5a1795e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e5a1795e_optionalFile){value}; }
static inline _s_e5a1795e_optionalLine _e5a1795e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e5a1795e_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateRootSignature(_s_e5a1795e_pDevice pDevice, _s_e5a1795e_nodeMask nodeMask, _s_e5a1795e_pBlobWithRootSignature pBlobWithRootSignature, _s_e5a1795e_blobLengthInBytes blobLengthInBytes, _s_e5a1795e_outpRootSignature outpRootSignature, _s_e5a1795e_optionalFile optionalFile, _s_e5a1795e_optionalLine optionalLine) {
  return x12DeviceCreateRootSignature(pDevice.value, nodeMask.value, pBlobWithRootSignature.value, blobLengthInBytes.value, outpRootSignature.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateGraphicsPipelineState x12DeviceCreateGraphicsPipelineState
#define _adb03488_pDevice(value) value
#define _adb03488_pDesc(value) value
#define _adb03488_outpPipelineState(value) value
#define _adb03488_optionalFile(value) value
#define _adb03488_optionalLine(value) value
#else
typedef struct _s_adb03488_pDevice { X12Device3* value; } _s_adb03488_pDevice;
typedef struct _s_adb03488_pDesc { D3D12_GRAPHICS_PIPELINE_STATE_DESC* value; } _s_adb03488_pDesc;
typedef struct _s_adb03488_outpPipelineState { X12PipelineState** value; } _s_adb03488_outpPipelineState;
typedef struct _s_adb03488_optionalFile { char* value; } _s_adb03488_optionalFile;
typedef struct _s_adb03488_optionalLine { int value; } _s_adb03488_optionalLine;
static inline _s_adb03488_pDevice _adb03488_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_adb03488_pDevice){value}; }
static inline _s_adb03488_pDesc _adb03488_pDesc(D3D12_GRAPHICS_PIPELINE_STATE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_adb03488_pDesc){value}; }
static inline _s_adb03488_outpPipelineState _adb03488_outpPipelineState(X12PipelineState** value) { return REDGPU_NP_STRUCT_INIT(_s_adb03488_outpPipelineState){value}; }
static inline _s_adb03488_optionalFile _adb03488_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_adb03488_optionalFile){value}; }
static inline _s_adb03488_optionalLine _adb03488_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_adb03488_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateGraphicsPipelineState(_s_adb03488_pDevice pDevice, _s_adb03488_pDesc pDesc, _s_adb03488_outpPipelineState outpPipelineState, _s_adb03488_optionalFile optionalFile, _s_adb03488_optionalLine optionalLine) {
  return x12DeviceCreateGraphicsPipelineState(pDevice.value, pDesc.value, outpPipelineState.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateComputePipelineState x12DeviceCreateComputePipelineState
#define _1bece4df_pDevice(value) value
#define _1bece4df_pDesc(value) value
#define _1bece4df_outpPipelineState(value) value
#define _1bece4df_optionalFile(value) value
#define _1bece4df_optionalLine(value) value
#else
typedef struct _s_1bece4df_pDevice { X12Device3* value; } _s_1bece4df_pDevice;
typedef struct _s_1bece4df_pDesc { D3D12_COMPUTE_PIPELINE_STATE_DESC* value; } _s_1bece4df_pDesc;
typedef struct _s_1bece4df_outpPipelineState { X12PipelineState** value; } _s_1bece4df_outpPipelineState;
typedef struct _s_1bece4df_optionalFile { char* value; } _s_1bece4df_optionalFile;
typedef struct _s_1bece4df_optionalLine { int value; } _s_1bece4df_optionalLine;
static inline _s_1bece4df_pDevice _1bece4df_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_1bece4df_pDevice){value}; }
static inline _s_1bece4df_pDesc _1bece4df_pDesc(D3D12_COMPUTE_PIPELINE_STATE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_1bece4df_pDesc){value}; }
static inline _s_1bece4df_outpPipelineState _1bece4df_outpPipelineState(X12PipelineState** value) { return REDGPU_NP_STRUCT_INIT(_s_1bece4df_outpPipelineState){value}; }
static inline _s_1bece4df_optionalFile _1bece4df_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1bece4df_optionalFile){value}; }
static inline _s_1bece4df_optionalLine _1bece4df_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1bece4df_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateComputePipelineState(_s_1bece4df_pDevice pDevice, _s_1bece4df_pDesc pDesc, _s_1bece4df_outpPipelineState outpPipelineState, _s_1bece4df_optionalFile optionalFile, _s_1bece4df_optionalLine optionalLine) {
  return x12DeviceCreateComputePipelineState(pDevice.value, pDesc.value, outpPipelineState.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateFence x12DeviceCreateFence
#define _4553ea8b_pDevice(value) value
#define _4553ea8b_InitialValue(value) value
#define _4553ea8b_Flags(value) value
#define _4553ea8b_outpFence(value) value
#define _4553ea8b_optionalFile(value) value
#define _4553ea8b_optionalLine(value) value
#else
typedef struct _s_4553ea8b_pDevice { X12Device3* value; } _s_4553ea8b_pDevice;
typedef struct _s_4553ea8b_InitialValue { uint64_t value; } _s_4553ea8b_InitialValue;
typedef struct _s_4553ea8b_Flags { D3D12_FENCE_FLAGS value; } _s_4553ea8b_Flags;
typedef struct _s_4553ea8b_outpFence { X12Fence** value; } _s_4553ea8b_outpFence;
typedef struct _s_4553ea8b_optionalFile { char* value; } _s_4553ea8b_optionalFile;
typedef struct _s_4553ea8b_optionalLine { int value; } _s_4553ea8b_optionalLine;
static inline _s_4553ea8b_pDevice _4553ea8b_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_4553ea8b_pDevice){value}; }
static inline _s_4553ea8b_InitialValue _4553ea8b_InitialValue(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_4553ea8b_InitialValue){value}; }
static inline _s_4553ea8b_Flags _4553ea8b_Flags(D3D12_FENCE_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_4553ea8b_Flags){value}; }
static inline _s_4553ea8b_outpFence _4553ea8b_outpFence(X12Fence** value) { return REDGPU_NP_STRUCT_INIT(_s_4553ea8b_outpFence){value}; }
static inline _s_4553ea8b_optionalFile _4553ea8b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4553ea8b_optionalFile){value}; }
static inline _s_4553ea8b_optionalLine _4553ea8b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4553ea8b_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateFence(_s_4553ea8b_pDevice pDevice, _s_4553ea8b_InitialValue InitialValue, _s_4553ea8b_Flags Flags, _s_4553ea8b_outpFence outpFence, _s_4553ea8b_optionalFile optionalFile, _s_4553ea8b_optionalLine optionalLine) {
  return x12DeviceCreateFence(pDevice.value, InitialValue.value, Flags.value, outpFence.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateCommandQueue x12DeviceCreateCommandQueue
#define _d235d8e8_pDevice(value) value
#define _d235d8e8_pDesc(value) value
#define _d235d8e8_outpCommandQueue(value) value
#define _d235d8e8_optionalFile(value) value
#define _d235d8e8_optionalLine(value) value
#else
typedef struct _s_d235d8e8_pDevice { X12Device3* value; } _s_d235d8e8_pDevice;
typedef struct _s_d235d8e8_pDesc { D3D12_COMMAND_QUEUE_DESC* value; } _s_d235d8e8_pDesc;
typedef struct _s_d235d8e8_outpCommandQueue { X12CommandQueue** value; } _s_d235d8e8_outpCommandQueue;
typedef struct _s_d235d8e8_optionalFile { char* value; } _s_d235d8e8_optionalFile;
typedef struct _s_d235d8e8_optionalLine { int value; } _s_d235d8e8_optionalLine;
static inline _s_d235d8e8_pDevice _d235d8e8_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_d235d8e8_pDevice){value}; }
static inline _s_d235d8e8_pDesc _d235d8e8_pDesc(D3D12_COMMAND_QUEUE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_d235d8e8_pDesc){value}; }
static inline _s_d235d8e8_outpCommandQueue _d235d8e8_outpCommandQueue(X12CommandQueue** value) { return REDGPU_NP_STRUCT_INIT(_s_d235d8e8_outpCommandQueue){value}; }
static inline _s_d235d8e8_optionalFile _d235d8e8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d235d8e8_optionalFile){value}; }
static inline _s_d235d8e8_optionalLine _d235d8e8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d235d8e8_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateCommandQueue(_s_d235d8e8_pDevice pDevice, _s_d235d8e8_pDesc pDesc, _s_d235d8e8_outpCommandQueue outpCommandQueue, _s_d235d8e8_optionalFile optionalFile, _s_d235d8e8_optionalLine optionalLine) {
  return x12DeviceCreateCommandQueue(pDevice.value, pDesc.value, outpCommandQueue.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateCommandAllocator x12DeviceCreateCommandAllocator
#define _802b86b6_pDevice(value) value
#define _802b86b6_type(value) value
#define _802b86b6_outpCommandAllocator(value) value
#define _802b86b6_optionalFile(value) value
#define _802b86b6_optionalLine(value) value
#else
typedef struct _s_802b86b6_pDevice { X12Device3* value; } _s_802b86b6_pDevice;
typedef struct _s_802b86b6_type { D3D12_COMMAND_LIST_TYPE value; } _s_802b86b6_type;
typedef struct _s_802b86b6_outpCommandAllocator { X12CommandAllocator** value; } _s_802b86b6_outpCommandAllocator;
typedef struct _s_802b86b6_optionalFile { char* value; } _s_802b86b6_optionalFile;
typedef struct _s_802b86b6_optionalLine { int value; } _s_802b86b6_optionalLine;
static inline _s_802b86b6_pDevice _802b86b6_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_802b86b6_pDevice){value}; }
static inline _s_802b86b6_type _802b86b6_type(D3D12_COMMAND_LIST_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_802b86b6_type){value}; }
static inline _s_802b86b6_outpCommandAllocator _802b86b6_outpCommandAllocator(X12CommandAllocator** value) { return REDGPU_NP_STRUCT_INIT(_s_802b86b6_outpCommandAllocator){value}; }
static inline _s_802b86b6_optionalFile _802b86b6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_802b86b6_optionalFile){value}; }
static inline _s_802b86b6_optionalLine _802b86b6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_802b86b6_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateCommandAllocator(_s_802b86b6_pDevice pDevice, _s_802b86b6_type type, _s_802b86b6_outpCommandAllocator outpCommandAllocator, _s_802b86b6_optionalFile optionalFile, _s_802b86b6_optionalLine optionalLine) {
  return x12DeviceCreateCommandAllocator(pDevice.value, type.value, outpCommandAllocator.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCreateCommandList x12DeviceCreateCommandList
#define _21ed1dca_pDevice(value) value
#define _21ed1dca_nodeMask(value) value
#define _21ed1dca_type(value) value
#define _21ed1dca_pCommandAllocator(value) value
#define _21ed1dca_pInitialState(value) value
#define _21ed1dca_outpCommandList(value) value
#define _21ed1dca_optionalFile(value) value
#define _21ed1dca_optionalLine(value) value
#else
typedef struct _s_21ed1dca_pDevice { X12Device3* value; } _s_21ed1dca_pDevice;
typedef struct _s_21ed1dca_nodeMask { unsigned value; } _s_21ed1dca_nodeMask;
typedef struct _s_21ed1dca_type { D3D12_COMMAND_LIST_TYPE value; } _s_21ed1dca_type;
typedef struct _s_21ed1dca_pCommandAllocator { X12CommandAllocator* value; } _s_21ed1dca_pCommandAllocator;
typedef struct _s_21ed1dca_pInitialState { X12PipelineState* value; } _s_21ed1dca_pInitialState;
typedef struct _s_21ed1dca_outpCommandList { X12CommandList** value; } _s_21ed1dca_outpCommandList;
typedef struct _s_21ed1dca_optionalFile { char* value; } _s_21ed1dca_optionalFile;
typedef struct _s_21ed1dca_optionalLine { int value; } _s_21ed1dca_optionalLine;
static inline _s_21ed1dca_pDevice _21ed1dca_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_21ed1dca_pDevice){value}; }
static inline _s_21ed1dca_nodeMask _21ed1dca_nodeMask(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_21ed1dca_nodeMask){value}; }
static inline _s_21ed1dca_type _21ed1dca_type(D3D12_COMMAND_LIST_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_21ed1dca_type){value}; }
static inline _s_21ed1dca_pCommandAllocator _21ed1dca_pCommandAllocator(X12CommandAllocator* value) { return REDGPU_NP_STRUCT_INIT(_s_21ed1dca_pCommandAllocator){value}; }
static inline _s_21ed1dca_pInitialState _21ed1dca_pInitialState(X12PipelineState* value) { return REDGPU_NP_STRUCT_INIT(_s_21ed1dca_pInitialState){value}; }
static inline _s_21ed1dca_outpCommandList _21ed1dca_outpCommandList(X12CommandList** value) { return REDGPU_NP_STRUCT_INIT(_s_21ed1dca_outpCommandList){value}; }
static inline _s_21ed1dca_optionalFile _21ed1dca_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_21ed1dca_optionalFile){value}; }
static inline _s_21ed1dca_optionalLine _21ed1dca_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_21ed1dca_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCreateCommandList(_s_21ed1dca_pDevice pDevice, _s_21ed1dca_nodeMask nodeMask, _s_21ed1dca_type type, _s_21ed1dca_pCommandAllocator pCommandAllocator, _s_21ed1dca_pInitialState pInitialState, _s_21ed1dca_outpCommandList outpCommandList, _s_21ed1dca_optionalFile optionalFile, _s_21ed1dca_optionalLine optionalLine) {
  return x12DeviceCreateCommandList(pDevice.value, nodeMask.value, type.value, pCommandAllocator.value, pInitialState.value, outpCommandList.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12ResourceGetGPUVirtualAddress x12ResourceGetGPUVirtualAddress
#define _1979ee5b_pResource(value) value
#else
typedef struct _s_1979ee5b_pResource { X12Resource* value; } _s_1979ee5b_pResource;
static inline _s_1979ee5b_pResource _1979ee5b_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_1979ee5b_pResource){value}; }
REDGPU_NP_DECLSPEC D3D12_GPU_VIRTUAL_ADDRESS REDGPU_NP_API np_x12ResourceGetGPUVirtualAddress(_s_1979ee5b_pResource pResource) {
  return x12ResourceGetGPUVirtualAddress(pResource.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12PipelineStateGetCachedBlob x12PipelineStateGetCachedBlob
#define _c2338cc5_pPipelineState(value) value
#define _c2338cc5_outpBlob(value) value
#define _c2338cc5_optionalFile(value) value
#define _c2338cc5_optionalLine(value) value
#else
typedef struct _s_c2338cc5_pPipelineState { X12PipelineState* value; } _s_c2338cc5_pPipelineState;
typedef struct _s_c2338cc5_outpBlob { X12Blob** value; } _s_c2338cc5_outpBlob;
typedef struct _s_c2338cc5_optionalFile { char* value; } _s_c2338cc5_optionalFile;
typedef struct _s_c2338cc5_optionalLine { int value; } _s_c2338cc5_optionalLine;
static inline _s_c2338cc5_pPipelineState _c2338cc5_pPipelineState(X12PipelineState* value) { return REDGPU_NP_STRUCT_INIT(_s_c2338cc5_pPipelineState){value}; }
static inline _s_c2338cc5_outpBlob _c2338cc5_outpBlob(X12Blob** value) { return REDGPU_NP_STRUCT_INIT(_s_c2338cc5_outpBlob){value}; }
static inline _s_c2338cc5_optionalFile _c2338cc5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c2338cc5_optionalFile){value}; }
static inline _s_c2338cc5_optionalLine _c2338cc5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c2338cc5_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12PipelineStateGetCachedBlob(_s_c2338cc5_pPipelineState pPipelineState, _s_c2338cc5_outpBlob outpBlob, _s_c2338cc5_optionalFile optionalFile, _s_c2338cc5_optionalLine optionalLine) {
  return x12PipelineStateGetCachedBlob(pPipelineState.value, outpBlob.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12BlobGetBufferPointer x12BlobGetBufferPointer
#define _e8a0cdc9_pBlob(value) value
#else
typedef struct _s_e8a0cdc9_pBlob { X12Blob* value; } _s_e8a0cdc9_pBlob;
static inline _s_e8a0cdc9_pBlob _e8a0cdc9_pBlob(X12Blob* value) { return REDGPU_NP_STRUCT_INIT(_s_e8a0cdc9_pBlob){value}; }
REDGPU_NP_DECLSPEC void* REDGPU_NP_API np_x12BlobGetBufferPointer(_s_e8a0cdc9_pBlob pBlob) {
  return x12BlobGetBufferPointer(pBlob.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12BlobGetBufferSize x12BlobGetBufferSize
#define _7e8ade3b_pBlob(value) value
#else
typedef struct _s_7e8ade3b_pBlob { X12Blob* value; } _s_7e8ade3b_pBlob;
static inline _s_7e8ade3b_pBlob _7e8ade3b_pBlob(X12Blob* value) { return REDGPU_NP_STRUCT_INIT(_s_7e8ade3b_pBlob){value}; }
REDGPU_NP_DECLSPEC size_t REDGPU_NP_API np_x12BlobGetBufferSize(_s_7e8ade3b_pBlob pBlob) {
  return x12BlobGetBufferSize(pBlob.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CreateRootSignatureDeserializer x12CreateRootSignatureDeserializer
#define _b7f00c42_pSrcData(value) value
#define _b7f00c42_SrcDataSizeInBytes(value) value
#define _b7f00c42_outpRootSignatureDeserializer(value) value
#define _b7f00c42_optionalFile(value) value
#define _b7f00c42_optionalLine(value) value
#else
typedef struct _s_b7f00c42_pSrcData { void* value; } _s_b7f00c42_pSrcData;
typedef struct _s_b7f00c42_SrcDataSizeInBytes { size_t value; } _s_b7f00c42_SrcDataSizeInBytes;
typedef struct _s_b7f00c42_outpRootSignatureDeserializer { X12RootSignatureDeserializer** value; } _s_b7f00c42_outpRootSignatureDeserializer;
typedef struct _s_b7f00c42_optionalFile { char* value; } _s_b7f00c42_optionalFile;
typedef struct _s_b7f00c42_optionalLine { int value; } _s_b7f00c42_optionalLine;
static inline _s_b7f00c42_pSrcData _b7f00c42_pSrcData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b7f00c42_pSrcData){value}; }
static inline _s_b7f00c42_SrcDataSizeInBytes _b7f00c42_SrcDataSizeInBytes(size_t value) { return REDGPU_NP_STRUCT_INIT(_s_b7f00c42_SrcDataSizeInBytes){value}; }
static inline _s_b7f00c42_outpRootSignatureDeserializer _b7f00c42_outpRootSignatureDeserializer(X12RootSignatureDeserializer** value) { return REDGPU_NP_STRUCT_INIT(_s_b7f00c42_outpRootSignatureDeserializer){value}; }
static inline _s_b7f00c42_optionalFile _b7f00c42_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b7f00c42_optionalFile){value}; }
static inline _s_b7f00c42_optionalLine _b7f00c42_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b7f00c42_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CreateRootSignatureDeserializer(_s_b7f00c42_pSrcData pSrcData, _s_b7f00c42_SrcDataSizeInBytes SrcDataSizeInBytes, _s_b7f00c42_outpRootSignatureDeserializer outpRootSignatureDeserializer, _s_b7f00c42_optionalFile optionalFile, _s_b7f00c42_optionalLine optionalLine) {
  return x12CreateRootSignatureDeserializer(pSrcData.value, SrcDataSizeInBytes.value, outpRootSignatureDeserializer.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12RootSignatureDeserializerGetRootSignatureDesc x12RootSignatureDeserializerGetRootSignatureDesc
#define _1d33eb6c_pRootSignatureDeserializer(value) value
#define _1d33eb6c_optionalFile(value) value
#define _1d33eb6c_optionalLine(value) value
#else
typedef struct _s_1d33eb6c_pRootSignatureDeserializer { X12RootSignatureDeserializer* value; } _s_1d33eb6c_pRootSignatureDeserializer;
typedef struct _s_1d33eb6c_optionalFile { char* value; } _s_1d33eb6c_optionalFile;
typedef struct _s_1d33eb6c_optionalLine { int value; } _s_1d33eb6c_optionalLine;
static inline _s_1d33eb6c_pRootSignatureDeserializer _1d33eb6c_pRootSignatureDeserializer(X12RootSignatureDeserializer* value) { return REDGPU_NP_STRUCT_INIT(_s_1d33eb6c_pRootSignatureDeserializer){value}; }
static inline _s_1d33eb6c_optionalFile _1d33eb6c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1d33eb6c_optionalFile){value}; }
static inline _s_1d33eb6c_optionalLine _1d33eb6c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1d33eb6c_optionalLine){value}; }
REDGPU_NP_DECLSPEC D3D12_ROOT_SIGNATURE_DESC* REDGPU_NP_API np_x12RootSignatureDeserializerGetRootSignatureDesc(_s_1d33eb6c_pRootSignatureDeserializer pRootSignatureDeserializer, _s_1d33eb6c_optionalFile optionalFile, _s_1d33eb6c_optionalLine optionalLine) {
  return x12RootSignatureDeserializerGetRootSignatureDesc(pRootSignatureDeserializer.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FenceGetCompletedValue x12FenceGetCompletedValue
#define _5dc96348_pFence(value) value
#define _5dc96348_optionalFile(value) value
#define _5dc96348_optionalLine(value) value
#else
typedef struct _s_5dc96348_pFence { X12Fence* value; } _s_5dc96348_pFence;
typedef struct _s_5dc96348_optionalFile { char* value; } _s_5dc96348_optionalFile;
typedef struct _s_5dc96348_optionalLine { int value; } _s_5dc96348_optionalLine;
static inline _s_5dc96348_pFence _5dc96348_pFence(X12Fence* value) { return REDGPU_NP_STRUCT_INIT(_s_5dc96348_pFence){value}; }
static inline _s_5dc96348_optionalFile _5dc96348_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5dc96348_optionalFile){value}; }
static inline _s_5dc96348_optionalLine _5dc96348_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5dc96348_optionalLine){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_x12FenceGetCompletedValue(_s_5dc96348_pFence pFence, _s_5dc96348_optionalFile optionalFile, _s_5dc96348_optionalLine optionalLine) {
  return x12FenceGetCompletedValue(pFence.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FenceSetEventOnCompletion x12FenceSetEventOnCompletion
#define _797d8eba_pFence(value) value
#define _797d8eba_Value(value) value
#define _797d8eba_hEvent(value) value
#define _797d8eba_optionalFile(value) value
#define _797d8eba_optionalLine(value) value
#else
typedef struct _s_797d8eba_pFence { X12Fence* value; } _s_797d8eba_pFence;
typedef struct _s_797d8eba_Value { uint64_t value; } _s_797d8eba_Value;
typedef struct _s_797d8eba_hEvent { void* value; } _s_797d8eba_hEvent;
typedef struct _s_797d8eba_optionalFile { char* value; } _s_797d8eba_optionalFile;
typedef struct _s_797d8eba_optionalLine { int value; } _s_797d8eba_optionalLine;
static inline _s_797d8eba_pFence _797d8eba_pFence(X12Fence* value) { return REDGPU_NP_STRUCT_INIT(_s_797d8eba_pFence){value}; }
static inline _s_797d8eba_Value _797d8eba_Value(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_797d8eba_Value){value}; }
static inline _s_797d8eba_hEvent _797d8eba_hEvent(void* value) { return REDGPU_NP_STRUCT_INIT(_s_797d8eba_hEvent){value}; }
static inline _s_797d8eba_optionalFile _797d8eba_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_797d8eba_optionalFile){value}; }
static inline _s_797d8eba_optionalLine _797d8eba_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_797d8eba_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FenceSetEventOnCompletion(_s_797d8eba_pFence pFence, _s_797d8eba_Value Value, _s_797d8eba_hEvent hEvent, _s_797d8eba_optionalFile optionalFile, _s_797d8eba_optionalLine optionalLine) {
  return x12FenceSetEventOnCompletion(pFence.value, Value.value, hEvent.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceSetEventOnMultipleFenceCompletion x12DeviceSetEventOnMultipleFenceCompletion
#define _955dbbfa_pDevice(value) value
#define _955dbbfa_ppFences(value) value
#define _955dbbfa_pFenceValues(value) value
#define _955dbbfa_NumFences(value) value
#define _955dbbfa_Flag(value) value
#define _955dbbfa_hEvent(value) value
#define _955dbbfa_optionalFile(value) value
#define _955dbbfa_optionalLine(value) value
#else
typedef struct _s_955dbbfa_pDevice { X12Device3* value; } _s_955dbbfa_pDevice;
typedef struct _s_955dbbfa_ppFences { X12Fence** value; } _s_955dbbfa_ppFences;
typedef struct _s_955dbbfa_pFenceValues { uint64_t* value; } _s_955dbbfa_pFenceValues;
typedef struct _s_955dbbfa_NumFences { unsigned value; } _s_955dbbfa_NumFences;
typedef struct _s_955dbbfa_Flag { D3D12_MULTIPLE_FENCE_WAIT_FLAG value; } _s_955dbbfa_Flag;
typedef struct _s_955dbbfa_hEvent { void* value; } _s_955dbbfa_hEvent;
typedef struct _s_955dbbfa_optionalFile { char* value; } _s_955dbbfa_optionalFile;
typedef struct _s_955dbbfa_optionalLine { int value; } _s_955dbbfa_optionalLine;
static inline _s_955dbbfa_pDevice _955dbbfa_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_955dbbfa_pDevice){value}; }
static inline _s_955dbbfa_ppFences _955dbbfa_ppFences(X12Fence** value) { return REDGPU_NP_STRUCT_INIT(_s_955dbbfa_ppFences){value}; }
static inline _s_955dbbfa_pFenceValues _955dbbfa_pFenceValues(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_955dbbfa_pFenceValues){value}; }
static inline _s_955dbbfa_NumFences _955dbbfa_NumFences(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_955dbbfa_NumFences){value}; }
static inline _s_955dbbfa_Flag _955dbbfa_Flag(D3D12_MULTIPLE_FENCE_WAIT_FLAG value) { return REDGPU_NP_STRUCT_INIT(_s_955dbbfa_Flag){value}; }
static inline _s_955dbbfa_hEvent _955dbbfa_hEvent(void* value) { return REDGPU_NP_STRUCT_INIT(_s_955dbbfa_hEvent){value}; }
static inline _s_955dbbfa_optionalFile _955dbbfa_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_955dbbfa_optionalFile){value}; }
static inline _s_955dbbfa_optionalLine _955dbbfa_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_955dbbfa_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceSetEventOnMultipleFenceCompletion(_s_955dbbfa_pDevice pDevice, _s_955dbbfa_ppFences ppFences, _s_955dbbfa_pFenceValues pFenceValues, _s_955dbbfa_NumFences NumFences, _s_955dbbfa_Flag Flag, _s_955dbbfa_hEvent hEvent, _s_955dbbfa_optionalFile optionalFile, _s_955dbbfa_optionalLine optionalLine) {
  return x12DeviceSetEventOnMultipleFenceCompletion(pDevice.value, ppFences.value, pFenceValues.value, NumFences.value, Flag.value, hEvent.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FenceSignal x12FenceSignal
#define _5bab8e55_pFence(value) value
#define _5bab8e55_Value(value) value
#define _5bab8e55_optionalFile(value) value
#define _5bab8e55_optionalLine(value) value
#else
typedef struct _s_5bab8e55_pFence { X12Fence* value; } _s_5bab8e55_pFence;
typedef struct _s_5bab8e55_Value { uint64_t value; } _s_5bab8e55_Value;
typedef struct _s_5bab8e55_optionalFile { char* value; } _s_5bab8e55_optionalFile;
typedef struct _s_5bab8e55_optionalLine { int value; } _s_5bab8e55_optionalLine;
static inline _s_5bab8e55_pFence _5bab8e55_pFence(X12Fence* value) { return REDGPU_NP_STRUCT_INIT(_s_5bab8e55_pFence){value}; }
static inline _s_5bab8e55_Value _5bab8e55_Value(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_5bab8e55_Value){value}; }
static inline _s_5bab8e55_optionalFile _5bab8e55_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5bab8e55_optionalFile){value}; }
static inline _s_5bab8e55_optionalLine _5bab8e55_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5bab8e55_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FenceSignal(_s_5bab8e55_pFence pFence, _s_5bab8e55_Value Value, _s_5bab8e55_optionalFile optionalFile, _s_5bab8e55_optionalLine optionalLine) {
  return x12FenceSignal(pFence.value, Value.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandAllocatorReset x12CommandAllocatorReset
#define _57fddeab_pCommandAllocator(value) value
#define _57fddeab_optionalFile(value) value
#define _57fddeab_optionalLine(value) value
#else
typedef struct _s_57fddeab_pCommandAllocator { X12CommandAllocator* value; } _s_57fddeab_pCommandAllocator;
typedef struct _s_57fddeab_optionalFile { char* value; } _s_57fddeab_optionalFile;
typedef struct _s_57fddeab_optionalLine { int value; } _s_57fddeab_optionalLine;
static inline _s_57fddeab_pCommandAllocator _57fddeab_pCommandAllocator(X12CommandAllocator* value) { return REDGPU_NP_STRUCT_INIT(_s_57fddeab_pCommandAllocator){value}; }
static inline _s_57fddeab_optionalFile _57fddeab_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_57fddeab_optionalFile){value}; }
static inline _s_57fddeab_optionalLine _57fddeab_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_57fddeab_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CommandAllocatorReset(_s_57fddeab_pCommandAllocator pCommandAllocator, _s_57fddeab_optionalFile optionalFile, _s_57fddeab_optionalLine optionalLine) {
  return x12CommandAllocatorReset(pCommandAllocator.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListReset x12CommandListReset
#define _9b1ec6b0_pCommandList(value) value
#define _9b1ec6b0_pAllocator(value) value
#define _9b1ec6b0_pInitialState(value) value
#define _9b1ec6b0_optionalFile(value) value
#define _9b1ec6b0_optionalLine(value) value
#else
typedef struct _s_9b1ec6b0_pCommandList { X12CommandList* value; } _s_9b1ec6b0_pCommandList;
typedef struct _s_9b1ec6b0_pAllocator { X12CommandAllocator* value; } _s_9b1ec6b0_pAllocator;
typedef struct _s_9b1ec6b0_pInitialState { X12PipelineState* value; } _s_9b1ec6b0_pInitialState;
typedef struct _s_9b1ec6b0_optionalFile { char* value; } _s_9b1ec6b0_optionalFile;
typedef struct _s_9b1ec6b0_optionalLine { int value; } _s_9b1ec6b0_optionalLine;
static inline _s_9b1ec6b0_pCommandList _9b1ec6b0_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_9b1ec6b0_pCommandList){value}; }
static inline _s_9b1ec6b0_pAllocator _9b1ec6b0_pAllocator(X12CommandAllocator* value) { return REDGPU_NP_STRUCT_INIT(_s_9b1ec6b0_pAllocator){value}; }
static inline _s_9b1ec6b0_pInitialState _9b1ec6b0_pInitialState(X12PipelineState* value) { return REDGPU_NP_STRUCT_INIT(_s_9b1ec6b0_pInitialState){value}; }
static inline _s_9b1ec6b0_optionalFile _9b1ec6b0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9b1ec6b0_optionalFile){value}; }
static inline _s_9b1ec6b0_optionalLine _9b1ec6b0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9b1ec6b0_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CommandListReset(_s_9b1ec6b0_pCommandList pCommandList, _s_9b1ec6b0_pAllocator pAllocator, _s_9b1ec6b0_pInitialState pInitialState, _s_9b1ec6b0_optionalFile optionalFile, _s_9b1ec6b0_optionalLine optionalLine) {
  return x12CommandListReset(pCommandList.value, pAllocator.value, pInitialState.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListClose x12CommandListClose
#define _5c0a95bb_pCommandList(value) value
#define _5c0a95bb_optionalFile(value) value
#define _5c0a95bb_optionalLine(value) value
#else
typedef struct _s_5c0a95bb_pCommandList { X12CommandList* value; } _s_5c0a95bb_pCommandList;
typedef struct _s_5c0a95bb_optionalFile { char* value; } _s_5c0a95bb_optionalFile;
typedef struct _s_5c0a95bb_optionalLine { int value; } _s_5c0a95bb_optionalLine;
static inline _s_5c0a95bb_pCommandList _5c0a95bb_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_5c0a95bb_pCommandList){value}; }
static inline _s_5c0a95bb_optionalFile _5c0a95bb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5c0a95bb_optionalFile){value}; }
static inline _s_5c0a95bb_optionalLine _5c0a95bb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5c0a95bb_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CommandListClose(_s_5c0a95bb_pCommandList pCommandList, _s_5c0a95bb_optionalFile optionalFile, _s_5c0a95bb_optionalLine optionalLine) {
  return x12CommandListClose(pCommandList.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListCopyBufferRegion x12CommandListCopyBufferRegion
#define _0315fd19_pCommandList(value) value
#define _0315fd19_pDstBuffer(value) value
#define _0315fd19_DstOffset(value) value
#define _0315fd19_pSrcBuffer(value) value
#define _0315fd19_SrcOffset(value) value
#define _0315fd19_NumBytes(value) value
#else
typedef struct _s_0315fd19_pCommandList { X12CommandList* value; } _s_0315fd19_pCommandList;
typedef struct _s_0315fd19_pDstBuffer { X12Resource* value; } _s_0315fd19_pDstBuffer;
typedef struct _s_0315fd19_DstOffset { uint64_t value; } _s_0315fd19_DstOffset;
typedef struct _s_0315fd19_pSrcBuffer { X12Resource* value; } _s_0315fd19_pSrcBuffer;
typedef struct _s_0315fd19_SrcOffset { uint64_t value; } _s_0315fd19_SrcOffset;
typedef struct _s_0315fd19_NumBytes { uint64_t value; } _s_0315fd19_NumBytes;
static inline _s_0315fd19_pCommandList _0315fd19_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_0315fd19_pCommandList){value}; }
static inline _s_0315fd19_pDstBuffer _0315fd19_pDstBuffer(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_0315fd19_pDstBuffer){value}; }
static inline _s_0315fd19_DstOffset _0315fd19_DstOffset(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_0315fd19_DstOffset){value}; }
static inline _s_0315fd19_pSrcBuffer _0315fd19_pSrcBuffer(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_0315fd19_pSrcBuffer){value}; }
static inline _s_0315fd19_SrcOffset _0315fd19_SrcOffset(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_0315fd19_SrcOffset){value}; }
static inline _s_0315fd19_NumBytes _0315fd19_NumBytes(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_0315fd19_NumBytes){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListCopyBufferRegion(_s_0315fd19_pCommandList pCommandList, _s_0315fd19_pDstBuffer pDstBuffer, _s_0315fd19_DstOffset DstOffset, _s_0315fd19_pSrcBuffer pSrcBuffer, _s_0315fd19_SrcOffset SrcOffset, _s_0315fd19_NumBytes NumBytes) {
  x12CommandListCopyBufferRegion(pCommandList.value, pDstBuffer.value, DstOffset.value, pSrcBuffer.value, SrcOffset.value, NumBytes.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListClearUnorderedAccessViewUint x12CommandListClearUnorderedAccessViewUint
#define _6dc5b77b_pCommandList(value) value
#define _6dc5b77b_ViewGPUHandleInCurrentHeap(value) value
#define _6dc5b77b_ViewCPUHandle(value) value
#define _6dc5b77b_pResource(value) value
#define _6dc5b77b_Values[4](value) value
#define _6dc5b77b_NumRects(value) value
#define _6dc5b77b_pRects(value) value
#else
typedef struct _s_6dc5b77b_pCommandList { X12CommandList* value; } _s_6dc5b77b_pCommandList;
typedef struct _s_6dc5b77b_ViewGPUHandleInCurrentHeap { D3D12_GPU_DESCRIPTOR_HANDLE value; } _s_6dc5b77b_ViewGPUHandleInCurrentHeap;
typedef struct _s_6dc5b77b_ViewCPUHandle { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_6dc5b77b_ViewCPUHandle;
typedef struct _s_6dc5b77b_pResource { X12Resource* value; } _s_6dc5b77b_pResource;
typedef struct _s_6dc5b77b_Values[4] { unsigned value; } _s_6dc5b77b_Values[4];
typedef struct _s_6dc5b77b_NumRects { unsigned value; } _s_6dc5b77b_NumRects;
typedef struct _s_6dc5b77b_pRects { D3D12_RECT* value; } _s_6dc5b77b_pRects;
static inline _s_6dc5b77b_pCommandList _6dc5b77b_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_6dc5b77b_pCommandList){value}; }
static inline _s_6dc5b77b_ViewGPUHandleInCurrentHeap _6dc5b77b_ViewGPUHandleInCurrentHeap(D3D12_GPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_6dc5b77b_ViewGPUHandleInCurrentHeap){value}; }
static inline _s_6dc5b77b_ViewCPUHandle _6dc5b77b_ViewCPUHandle(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_6dc5b77b_ViewCPUHandle){value}; }
static inline _s_6dc5b77b_pResource _6dc5b77b_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_6dc5b77b_pResource){value}; }
static inline _s_6dc5b77b_Values[4] _6dc5b77b_Values[4](unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6dc5b77b_Values[4]){value}; }
static inline _s_6dc5b77b_NumRects _6dc5b77b_NumRects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6dc5b77b_NumRects){value}; }
static inline _s_6dc5b77b_pRects _6dc5b77b_pRects(D3D12_RECT* value) { return REDGPU_NP_STRUCT_INIT(_s_6dc5b77b_pRects){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListClearUnorderedAccessViewUint(_s_6dc5b77b_pCommandList pCommandList, _s_6dc5b77b_ViewGPUHandleInCurrentHeap ViewGPUHandleInCurrentHeap, _s_6dc5b77b_ViewCPUHandle ViewCPUHandle, _s_6dc5b77b_pResource pResource, _s_6dc5b77b_Values[4] Values[4], _s_6dc5b77b_NumRects NumRects, _s_6dc5b77b_pRects pRects) {
  x12CommandListClearUnorderedAccessViewUint(pCommandList.value, ViewGPUHandleInCurrentHeap.value, ViewCPUHandle.value, pResource.value, Values[4].value, NumRects.value, pRects.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListClearUnorderedAccessViewFloat x12CommandListClearUnorderedAccessViewFloat
#define _7cf3fec3_pCommandList(value) value
#define _7cf3fec3_ViewGPUHandleInCurrentHeap(value) value
#define _7cf3fec3_ViewCPUHandle(value) value
#define _7cf3fec3_pResource(value) value
#define _7cf3fec3_Values[4](value) value
#define _7cf3fec3_NumRects(value) value
#define _7cf3fec3_pRects(value) value
#else
typedef struct _s_7cf3fec3_pCommandList { X12CommandList* value; } _s_7cf3fec3_pCommandList;
typedef struct _s_7cf3fec3_ViewGPUHandleInCurrentHeap { D3D12_GPU_DESCRIPTOR_HANDLE value; } _s_7cf3fec3_ViewGPUHandleInCurrentHeap;
typedef struct _s_7cf3fec3_ViewCPUHandle { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_7cf3fec3_ViewCPUHandle;
typedef struct _s_7cf3fec3_pResource { X12Resource* value; } _s_7cf3fec3_pResource;
typedef struct _s_7cf3fec3_Values[4] { float value; } _s_7cf3fec3_Values[4];
typedef struct _s_7cf3fec3_NumRects { unsigned value; } _s_7cf3fec3_NumRects;
typedef struct _s_7cf3fec3_pRects { D3D12_RECT* value; } _s_7cf3fec3_pRects;
static inline _s_7cf3fec3_pCommandList _7cf3fec3_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_7cf3fec3_pCommandList){value}; }
static inline _s_7cf3fec3_ViewGPUHandleInCurrentHeap _7cf3fec3_ViewGPUHandleInCurrentHeap(D3D12_GPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_7cf3fec3_ViewGPUHandleInCurrentHeap){value}; }
static inline _s_7cf3fec3_ViewCPUHandle _7cf3fec3_ViewCPUHandle(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_7cf3fec3_ViewCPUHandle){value}; }
static inline _s_7cf3fec3_pResource _7cf3fec3_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_7cf3fec3_pResource){value}; }
static inline _s_7cf3fec3_Values[4] _7cf3fec3_Values[4](float value) { return REDGPU_NP_STRUCT_INIT(_s_7cf3fec3_Values[4]){value}; }
static inline _s_7cf3fec3_NumRects _7cf3fec3_NumRects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_7cf3fec3_NumRects){value}; }
static inline _s_7cf3fec3_pRects _7cf3fec3_pRects(D3D12_RECT* value) { return REDGPU_NP_STRUCT_INIT(_s_7cf3fec3_pRects){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListClearUnorderedAccessViewFloat(_s_7cf3fec3_pCommandList pCommandList, _s_7cf3fec3_ViewGPUHandleInCurrentHeap ViewGPUHandleInCurrentHeap, _s_7cf3fec3_ViewCPUHandle ViewCPUHandle, _s_7cf3fec3_pResource pResource, _s_7cf3fec3_Values[4] Values[4], _s_7cf3fec3_NumRects NumRects, _s_7cf3fec3_pRects pRects) {
  x12CommandListClearUnorderedAccessViewFloat(pCommandList.value, ViewGPUHandleInCurrentHeap.value, ViewCPUHandle.value, pResource.value, Values[4].value, NumRects.value, pRects.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListDrawInstanced x12CommandListDrawInstanced
#define _649f103c_pCommandList(value) value
#define _649f103c_VertexCountPerInstance(value) value
#define _649f103c_InstanceCount(value) value
#define _649f103c_StartVertexLocation(value) value
#define _649f103c_StartInstanceLocation(value) value
#else
typedef struct _s_649f103c_pCommandList { X12CommandList* value; } _s_649f103c_pCommandList;
typedef struct _s_649f103c_VertexCountPerInstance { unsigned value; } _s_649f103c_VertexCountPerInstance;
typedef struct _s_649f103c_InstanceCount { unsigned value; } _s_649f103c_InstanceCount;
typedef struct _s_649f103c_StartVertexLocation { unsigned value; } _s_649f103c_StartVertexLocation;
typedef struct _s_649f103c_StartInstanceLocation { unsigned value; } _s_649f103c_StartInstanceLocation;
static inline _s_649f103c_pCommandList _649f103c_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_649f103c_pCommandList){value}; }
static inline _s_649f103c_VertexCountPerInstance _649f103c_VertexCountPerInstance(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_649f103c_VertexCountPerInstance){value}; }
static inline _s_649f103c_InstanceCount _649f103c_InstanceCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_649f103c_InstanceCount){value}; }
static inline _s_649f103c_StartVertexLocation _649f103c_StartVertexLocation(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_649f103c_StartVertexLocation){value}; }
static inline _s_649f103c_StartInstanceLocation _649f103c_StartInstanceLocation(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_649f103c_StartInstanceLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListDrawInstanced(_s_649f103c_pCommandList pCommandList, _s_649f103c_VertexCountPerInstance VertexCountPerInstance, _s_649f103c_InstanceCount InstanceCount, _s_649f103c_StartVertexLocation StartVertexLocation, _s_649f103c_StartInstanceLocation StartInstanceLocation) {
  x12CommandListDrawInstanced(pCommandList.value, VertexCountPerInstance.value, InstanceCount.value, StartVertexLocation.value, StartInstanceLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListDrawIndexedInstanced x12CommandListDrawIndexedInstanced
#define _bff9a01f_pCommandList(value) value
#define _bff9a01f_IndexCountPerInstance(value) value
#define _bff9a01f_InstanceCount(value) value
#define _bff9a01f_StartIndexLocation(value) value
#define _bff9a01f_BaseVertexLocation(value) value
#define _bff9a01f_StartInstanceLocation(value) value
#else
typedef struct _s_bff9a01f_pCommandList { X12CommandList* value; } _s_bff9a01f_pCommandList;
typedef struct _s_bff9a01f_IndexCountPerInstance { unsigned value; } _s_bff9a01f_IndexCountPerInstance;
typedef struct _s_bff9a01f_InstanceCount { unsigned value; } _s_bff9a01f_InstanceCount;
typedef struct _s_bff9a01f_StartIndexLocation { unsigned value; } _s_bff9a01f_StartIndexLocation;
typedef struct _s_bff9a01f_BaseVertexLocation { int value; } _s_bff9a01f_BaseVertexLocation;
typedef struct _s_bff9a01f_StartInstanceLocation { unsigned value; } _s_bff9a01f_StartInstanceLocation;
static inline _s_bff9a01f_pCommandList _bff9a01f_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_bff9a01f_pCommandList){value}; }
static inline _s_bff9a01f_IndexCountPerInstance _bff9a01f_IndexCountPerInstance(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bff9a01f_IndexCountPerInstance){value}; }
static inline _s_bff9a01f_InstanceCount _bff9a01f_InstanceCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bff9a01f_InstanceCount){value}; }
static inline _s_bff9a01f_StartIndexLocation _bff9a01f_StartIndexLocation(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bff9a01f_StartIndexLocation){value}; }
static inline _s_bff9a01f_BaseVertexLocation _bff9a01f_BaseVertexLocation(int value) { return REDGPU_NP_STRUCT_INIT(_s_bff9a01f_BaseVertexLocation){value}; }
static inline _s_bff9a01f_StartInstanceLocation _bff9a01f_StartInstanceLocation(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_bff9a01f_StartInstanceLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListDrawIndexedInstanced(_s_bff9a01f_pCommandList pCommandList, _s_bff9a01f_IndexCountPerInstance IndexCountPerInstance, _s_bff9a01f_InstanceCount InstanceCount, _s_bff9a01f_StartIndexLocation StartIndexLocation, _s_bff9a01f_BaseVertexLocation BaseVertexLocation, _s_bff9a01f_StartInstanceLocation StartInstanceLocation) {
  x12CommandListDrawIndexedInstanced(pCommandList.value, IndexCountPerInstance.value, InstanceCount.value, StartIndexLocation.value, BaseVertexLocation.value, StartInstanceLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListDispatch x12CommandListDispatch
#define _19b8763f_pCommandList(value) value
#define _19b8763f_ThreadGroupCountX(value) value
#define _19b8763f_ThreadGroupCountY(value) value
#define _19b8763f_ThreadGroupCountZ(value) value
#else
typedef struct _s_19b8763f_pCommandList { X12CommandList* value; } _s_19b8763f_pCommandList;
typedef struct _s_19b8763f_ThreadGroupCountX { unsigned value; } _s_19b8763f_ThreadGroupCountX;
typedef struct _s_19b8763f_ThreadGroupCountY { unsigned value; } _s_19b8763f_ThreadGroupCountY;
typedef struct _s_19b8763f_ThreadGroupCountZ { unsigned value; } _s_19b8763f_ThreadGroupCountZ;
static inline _s_19b8763f_pCommandList _19b8763f_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_19b8763f_pCommandList){value}; }
static inline _s_19b8763f_ThreadGroupCountX _19b8763f_ThreadGroupCountX(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_19b8763f_ThreadGroupCountX){value}; }
static inline _s_19b8763f_ThreadGroupCountY _19b8763f_ThreadGroupCountY(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_19b8763f_ThreadGroupCountY){value}; }
static inline _s_19b8763f_ThreadGroupCountZ _19b8763f_ThreadGroupCountZ(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_19b8763f_ThreadGroupCountZ){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListDispatch(_s_19b8763f_pCommandList pCommandList, _s_19b8763f_ThreadGroupCountX ThreadGroupCountX, _s_19b8763f_ThreadGroupCountY ThreadGroupCountY, _s_19b8763f_ThreadGroupCountZ ThreadGroupCountZ) {
  x12CommandListDispatch(pCommandList.value, ThreadGroupCountX.value, ThreadGroupCountY.value, ThreadGroupCountZ.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetDescriptorHeaps x12CommandListSetDescriptorHeaps
#define _8486bd6e_pCommandList(value) value
#define _8486bd6e_NumDescriptorHeaps(value) value
#define _8486bd6e_ppDescriptorHeaps(value) value
#else
typedef struct _s_8486bd6e_pCommandList { X12CommandList* value; } _s_8486bd6e_pCommandList;
typedef struct _s_8486bd6e_NumDescriptorHeaps { unsigned value; } _s_8486bd6e_NumDescriptorHeaps;
typedef struct _s_8486bd6e_ppDescriptorHeaps { X12DescriptorHeap** value; } _s_8486bd6e_ppDescriptorHeaps;
static inline _s_8486bd6e_pCommandList _8486bd6e_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_8486bd6e_pCommandList){value}; }
static inline _s_8486bd6e_NumDescriptorHeaps _8486bd6e_NumDescriptorHeaps(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8486bd6e_NumDescriptorHeaps){value}; }
static inline _s_8486bd6e_ppDescriptorHeaps _8486bd6e_ppDescriptorHeaps(X12DescriptorHeap** value) { return REDGPU_NP_STRUCT_INIT(_s_8486bd6e_ppDescriptorHeaps){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetDescriptorHeaps(_s_8486bd6e_pCommandList pCommandList, _s_8486bd6e_NumDescriptorHeaps NumDescriptorHeaps, _s_8486bd6e_ppDescriptorHeaps ppDescriptorHeaps) {
  x12CommandListSetDescriptorHeaps(pCommandList.value, NumDescriptorHeaps.value, ppDescriptorHeaps.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRootSignature x12CommandListSetGraphicsRootSignature
#define _4572b4c5_pCommandList(value) value
#define _4572b4c5_pRootSignature(value) value
#else
typedef struct _s_4572b4c5_pCommandList { X12CommandList* value; } _s_4572b4c5_pCommandList;
typedef struct _s_4572b4c5_pRootSignature { X12RootSignature* value; } _s_4572b4c5_pRootSignature;
static inline _s_4572b4c5_pCommandList _4572b4c5_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_4572b4c5_pCommandList){value}; }
static inline _s_4572b4c5_pRootSignature _4572b4c5_pRootSignature(X12RootSignature* value) { return REDGPU_NP_STRUCT_INIT(_s_4572b4c5_pRootSignature){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRootSignature(_s_4572b4c5_pCommandList pCommandList, _s_4572b4c5_pRootSignature pRootSignature) {
  x12CommandListSetGraphicsRootSignature(pCommandList.value, pRootSignature.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRoot32BitConstant x12CommandListSetGraphicsRoot32BitConstant
#define _c5dd0fe0_pCommandList(value) value
#define _c5dd0fe0_RootParameterIndex(value) value
#define _c5dd0fe0_SrcData(value) value
#define _c5dd0fe0_DestOffsetIn32BitValues(value) value
#else
typedef struct _s_c5dd0fe0_pCommandList { X12CommandList* value; } _s_c5dd0fe0_pCommandList;
typedef struct _s_c5dd0fe0_RootParameterIndex { unsigned value; } _s_c5dd0fe0_RootParameterIndex;
typedef struct _s_c5dd0fe0_SrcData { unsigned value; } _s_c5dd0fe0_SrcData;
typedef struct _s_c5dd0fe0_DestOffsetIn32BitValues { unsigned value; } _s_c5dd0fe0_DestOffsetIn32BitValues;
static inline _s_c5dd0fe0_pCommandList _c5dd0fe0_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_c5dd0fe0_pCommandList){value}; }
static inline _s_c5dd0fe0_RootParameterIndex _c5dd0fe0_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c5dd0fe0_RootParameterIndex){value}; }
static inline _s_c5dd0fe0_SrcData _c5dd0fe0_SrcData(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c5dd0fe0_SrcData){value}; }
static inline _s_c5dd0fe0_DestOffsetIn32BitValues _c5dd0fe0_DestOffsetIn32BitValues(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c5dd0fe0_DestOffsetIn32BitValues){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRoot32BitConstant(_s_c5dd0fe0_pCommandList pCommandList, _s_c5dd0fe0_RootParameterIndex RootParameterIndex, _s_c5dd0fe0_SrcData SrcData, _s_c5dd0fe0_DestOffsetIn32BitValues DestOffsetIn32BitValues) {
  x12CommandListSetGraphicsRoot32BitConstant(pCommandList.value, RootParameterIndex.value, SrcData.value, DestOffsetIn32BitValues.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRoot32BitConstants x12CommandListSetGraphicsRoot32BitConstants
#define _c13e935f_pCommandList(value) value
#define _c13e935f_RootParameterIndex(value) value
#define _c13e935f_Num32BitValuesToSet(value) value
#define _c13e935f_pSrcData(value) value
#define _c13e935f_DestOffsetIn32BitValues(value) value
#else
typedef struct _s_c13e935f_pCommandList { X12CommandList* value; } _s_c13e935f_pCommandList;
typedef struct _s_c13e935f_RootParameterIndex { unsigned value; } _s_c13e935f_RootParameterIndex;
typedef struct _s_c13e935f_Num32BitValuesToSet { unsigned value; } _s_c13e935f_Num32BitValuesToSet;
typedef struct _s_c13e935f_pSrcData { void* value; } _s_c13e935f_pSrcData;
typedef struct _s_c13e935f_DestOffsetIn32BitValues { unsigned value; } _s_c13e935f_DestOffsetIn32BitValues;
static inline _s_c13e935f_pCommandList _c13e935f_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_c13e935f_pCommandList){value}; }
static inline _s_c13e935f_RootParameterIndex _c13e935f_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c13e935f_RootParameterIndex){value}; }
static inline _s_c13e935f_Num32BitValuesToSet _c13e935f_Num32BitValuesToSet(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c13e935f_Num32BitValuesToSet){value}; }
static inline _s_c13e935f_pSrcData _c13e935f_pSrcData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c13e935f_pSrcData){value}; }
static inline _s_c13e935f_DestOffsetIn32BitValues _c13e935f_DestOffsetIn32BitValues(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c13e935f_DestOffsetIn32BitValues){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRoot32BitConstants(_s_c13e935f_pCommandList pCommandList, _s_c13e935f_RootParameterIndex RootParameterIndex, _s_c13e935f_Num32BitValuesToSet Num32BitValuesToSet, _s_c13e935f_pSrcData pSrcData, _s_c13e935f_DestOffsetIn32BitValues DestOffsetIn32BitValues) {
  x12CommandListSetGraphicsRoot32BitConstants(pCommandList.value, RootParameterIndex.value, Num32BitValuesToSet.value, pSrcData.value, DestOffsetIn32BitValues.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRootDescriptorTable x12CommandListSetGraphicsRootDescriptorTable
#define _4a5f6d06_pCommandList(value) value
#define _4a5f6d06_RootParameterIndex(value) value
#define _4a5f6d06_BaseDescriptor(value) value
#else
typedef struct _s_4a5f6d06_pCommandList { X12CommandList* value; } _s_4a5f6d06_pCommandList;
typedef struct _s_4a5f6d06_RootParameterIndex { unsigned value; } _s_4a5f6d06_RootParameterIndex;
typedef struct _s_4a5f6d06_BaseDescriptor { D3D12_GPU_DESCRIPTOR_HANDLE value; } _s_4a5f6d06_BaseDescriptor;
static inline _s_4a5f6d06_pCommandList _4a5f6d06_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_4a5f6d06_pCommandList){value}; }
static inline _s_4a5f6d06_RootParameterIndex _4a5f6d06_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4a5f6d06_RootParameterIndex){value}; }
static inline _s_4a5f6d06_BaseDescriptor _4a5f6d06_BaseDescriptor(D3D12_GPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_4a5f6d06_BaseDescriptor){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRootDescriptorTable(_s_4a5f6d06_pCommandList pCommandList, _s_4a5f6d06_RootParameterIndex RootParameterIndex, _s_4a5f6d06_BaseDescriptor BaseDescriptor) {
  x12CommandListSetGraphicsRootDescriptorTable(pCommandList.value, RootParameterIndex.value, BaseDescriptor.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRootUnorderedAccessView x12CommandListSetGraphicsRootUnorderedAccessView
#define _763dfb1e_pCommandList(value) value
#define _763dfb1e_RootParameterIndex(value) value
#define _763dfb1e_BufferLocation(value) value
#else
typedef struct _s_763dfb1e_pCommandList { X12CommandList* value; } _s_763dfb1e_pCommandList;
typedef struct _s_763dfb1e_RootParameterIndex { unsigned value; } _s_763dfb1e_RootParameterIndex;
typedef struct _s_763dfb1e_BufferLocation { D3D12_GPU_VIRTUAL_ADDRESS value; } _s_763dfb1e_BufferLocation;
static inline _s_763dfb1e_pCommandList _763dfb1e_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_763dfb1e_pCommandList){value}; }
static inline _s_763dfb1e_RootParameterIndex _763dfb1e_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_763dfb1e_RootParameterIndex){value}; }
static inline _s_763dfb1e_BufferLocation _763dfb1e_BufferLocation(D3D12_GPU_VIRTUAL_ADDRESS value) { return REDGPU_NP_STRUCT_INIT(_s_763dfb1e_BufferLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRootUnorderedAccessView(_s_763dfb1e_pCommandList pCommandList, _s_763dfb1e_RootParameterIndex RootParameterIndex, _s_763dfb1e_BufferLocation BufferLocation) {
  x12CommandListSetGraphicsRootUnorderedAccessView(pCommandList.value, RootParameterIndex.value, BufferLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRootShaderResourceView x12CommandListSetGraphicsRootShaderResourceView
#define _de3bb1f2_pCommandList(value) value
#define _de3bb1f2_RootParameterIndex(value) value
#define _de3bb1f2_BufferLocation(value) value
#else
typedef struct _s_de3bb1f2_pCommandList { X12CommandList* value; } _s_de3bb1f2_pCommandList;
typedef struct _s_de3bb1f2_RootParameterIndex { unsigned value; } _s_de3bb1f2_RootParameterIndex;
typedef struct _s_de3bb1f2_BufferLocation { D3D12_GPU_VIRTUAL_ADDRESS value; } _s_de3bb1f2_BufferLocation;
static inline _s_de3bb1f2_pCommandList _de3bb1f2_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_de3bb1f2_pCommandList){value}; }
static inline _s_de3bb1f2_RootParameterIndex _de3bb1f2_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_de3bb1f2_RootParameterIndex){value}; }
static inline _s_de3bb1f2_BufferLocation _de3bb1f2_BufferLocation(D3D12_GPU_VIRTUAL_ADDRESS value) { return REDGPU_NP_STRUCT_INIT(_s_de3bb1f2_BufferLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRootShaderResourceView(_s_de3bb1f2_pCommandList pCommandList, _s_de3bb1f2_RootParameterIndex RootParameterIndex, _s_de3bb1f2_BufferLocation BufferLocation) {
  x12CommandListSetGraphicsRootShaderResourceView(pCommandList.value, RootParameterIndex.value, BufferLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetGraphicsRootConstantBufferView x12CommandListSetGraphicsRootConstantBufferView
#define _1ed09653_pCommandList(value) value
#define _1ed09653_RootParameterIndex(value) value
#define _1ed09653_BufferLocation(value) value
#else
typedef struct _s_1ed09653_pCommandList { X12CommandList* value; } _s_1ed09653_pCommandList;
typedef struct _s_1ed09653_RootParameterIndex { unsigned value; } _s_1ed09653_RootParameterIndex;
typedef struct _s_1ed09653_BufferLocation { D3D12_GPU_VIRTUAL_ADDRESS value; } _s_1ed09653_BufferLocation;
static inline _s_1ed09653_pCommandList _1ed09653_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_1ed09653_pCommandList){value}; }
static inline _s_1ed09653_RootParameterIndex _1ed09653_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1ed09653_RootParameterIndex){value}; }
static inline _s_1ed09653_BufferLocation _1ed09653_BufferLocation(D3D12_GPU_VIRTUAL_ADDRESS value) { return REDGPU_NP_STRUCT_INIT(_s_1ed09653_BufferLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetGraphicsRootConstantBufferView(_s_1ed09653_pCommandList pCommandList, _s_1ed09653_RootParameterIndex RootParameterIndex, _s_1ed09653_BufferLocation BufferLocation) {
  x12CommandListSetGraphicsRootConstantBufferView(pCommandList.value, RootParameterIndex.value, BufferLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRootSignature x12CommandListSetComputeRootSignature
#define _38d4a425_pCommandList(value) value
#define _38d4a425_pRootSignature(value) value
#else
typedef struct _s_38d4a425_pCommandList { X12CommandList* value; } _s_38d4a425_pCommandList;
typedef struct _s_38d4a425_pRootSignature { X12RootSignature* value; } _s_38d4a425_pRootSignature;
static inline _s_38d4a425_pCommandList _38d4a425_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_38d4a425_pCommandList){value}; }
static inline _s_38d4a425_pRootSignature _38d4a425_pRootSignature(X12RootSignature* value) { return REDGPU_NP_STRUCT_INIT(_s_38d4a425_pRootSignature){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRootSignature(_s_38d4a425_pCommandList pCommandList, _s_38d4a425_pRootSignature pRootSignature) {
  x12CommandListSetComputeRootSignature(pCommandList.value, pRootSignature.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRoot32BitConstant x12CommandListSetComputeRoot32BitConstant
#define _71475c80_pCommandList(value) value
#define _71475c80_RootParameterIndex(value) value
#define _71475c80_SrcData(value) value
#define _71475c80_DestOffsetIn32BitValues(value) value
#else
typedef struct _s_71475c80_pCommandList { X12CommandList* value; } _s_71475c80_pCommandList;
typedef struct _s_71475c80_RootParameterIndex { unsigned value; } _s_71475c80_RootParameterIndex;
typedef struct _s_71475c80_SrcData { unsigned value; } _s_71475c80_SrcData;
typedef struct _s_71475c80_DestOffsetIn32BitValues { unsigned value; } _s_71475c80_DestOffsetIn32BitValues;
static inline _s_71475c80_pCommandList _71475c80_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_71475c80_pCommandList){value}; }
static inline _s_71475c80_RootParameterIndex _71475c80_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_71475c80_RootParameterIndex){value}; }
static inline _s_71475c80_SrcData _71475c80_SrcData(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_71475c80_SrcData){value}; }
static inline _s_71475c80_DestOffsetIn32BitValues _71475c80_DestOffsetIn32BitValues(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_71475c80_DestOffsetIn32BitValues){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRoot32BitConstant(_s_71475c80_pCommandList pCommandList, _s_71475c80_RootParameterIndex RootParameterIndex, _s_71475c80_SrcData SrcData, _s_71475c80_DestOffsetIn32BitValues DestOffsetIn32BitValues) {
  x12CommandListSetComputeRoot32BitConstant(pCommandList.value, RootParameterIndex.value, SrcData.value, DestOffsetIn32BitValues.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRoot32BitConstants x12CommandListSetComputeRoot32BitConstants
#define _428a2fdf_pCommandList(value) value
#define _428a2fdf_RootParameterIndex(value) value
#define _428a2fdf_Num32BitValuesToSet(value) value
#define _428a2fdf_pSrcData(value) value
#define _428a2fdf_DestOffsetIn32BitValues(value) value
#else
typedef struct _s_428a2fdf_pCommandList { X12CommandList* value; } _s_428a2fdf_pCommandList;
typedef struct _s_428a2fdf_RootParameterIndex { unsigned value; } _s_428a2fdf_RootParameterIndex;
typedef struct _s_428a2fdf_Num32BitValuesToSet { unsigned value; } _s_428a2fdf_Num32BitValuesToSet;
typedef struct _s_428a2fdf_pSrcData { void* value; } _s_428a2fdf_pSrcData;
typedef struct _s_428a2fdf_DestOffsetIn32BitValues { unsigned value; } _s_428a2fdf_DestOffsetIn32BitValues;
static inline _s_428a2fdf_pCommandList _428a2fdf_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_428a2fdf_pCommandList){value}; }
static inline _s_428a2fdf_RootParameterIndex _428a2fdf_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_428a2fdf_RootParameterIndex){value}; }
static inline _s_428a2fdf_Num32BitValuesToSet _428a2fdf_Num32BitValuesToSet(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_428a2fdf_Num32BitValuesToSet){value}; }
static inline _s_428a2fdf_pSrcData _428a2fdf_pSrcData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_428a2fdf_pSrcData){value}; }
static inline _s_428a2fdf_DestOffsetIn32BitValues _428a2fdf_DestOffsetIn32BitValues(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_428a2fdf_DestOffsetIn32BitValues){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRoot32BitConstants(_s_428a2fdf_pCommandList pCommandList, _s_428a2fdf_RootParameterIndex RootParameterIndex, _s_428a2fdf_Num32BitValuesToSet Num32BitValuesToSet, _s_428a2fdf_pSrcData pSrcData, _s_428a2fdf_DestOffsetIn32BitValues DestOffsetIn32BitValues) {
  x12CommandListSetComputeRoot32BitConstants(pCommandList.value, RootParameterIndex.value, Num32BitValuesToSet.value, pSrcData.value, DestOffsetIn32BitValues.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRootDescriptorTable x12CommandListSetComputeRootDescriptorTable
#define _6804f6d4_pCommandList(value) value
#define _6804f6d4_RootParameterIndex(value) value
#define _6804f6d4_BaseDescriptor(value) value
#else
typedef struct _s_6804f6d4_pCommandList { X12CommandList* value; } _s_6804f6d4_pCommandList;
typedef struct _s_6804f6d4_RootParameterIndex { unsigned value; } _s_6804f6d4_RootParameterIndex;
typedef struct _s_6804f6d4_BaseDescriptor { D3D12_GPU_DESCRIPTOR_HANDLE value; } _s_6804f6d4_BaseDescriptor;
static inline _s_6804f6d4_pCommandList _6804f6d4_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_6804f6d4_pCommandList){value}; }
static inline _s_6804f6d4_RootParameterIndex _6804f6d4_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6804f6d4_RootParameterIndex){value}; }
static inline _s_6804f6d4_BaseDescriptor _6804f6d4_BaseDescriptor(D3D12_GPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_6804f6d4_BaseDescriptor){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRootDescriptorTable(_s_6804f6d4_pCommandList pCommandList, _s_6804f6d4_RootParameterIndex RootParameterIndex, _s_6804f6d4_BaseDescriptor BaseDescriptor) {
  x12CommandListSetComputeRootDescriptorTable(pCommandList.value, RootParameterIndex.value, BaseDescriptor.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRootUnorderedAccessView x12CommandListSetComputeRootUnorderedAccessView
#define _d49feb52_pCommandList(value) value
#define _d49feb52_RootParameterIndex(value) value
#define _d49feb52_BufferLocation(value) value
#else
typedef struct _s_d49feb52_pCommandList { X12CommandList* value; } _s_d49feb52_pCommandList;
typedef struct _s_d49feb52_RootParameterIndex { unsigned value; } _s_d49feb52_RootParameterIndex;
typedef struct _s_d49feb52_BufferLocation { D3D12_GPU_VIRTUAL_ADDRESS value; } _s_d49feb52_BufferLocation;
static inline _s_d49feb52_pCommandList _d49feb52_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_d49feb52_pCommandList){value}; }
static inline _s_d49feb52_RootParameterIndex _d49feb52_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_d49feb52_RootParameterIndex){value}; }
static inline _s_d49feb52_BufferLocation _d49feb52_BufferLocation(D3D12_GPU_VIRTUAL_ADDRESS value) { return REDGPU_NP_STRUCT_INIT(_s_d49feb52_BufferLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRootUnorderedAccessView(_s_d49feb52_pCommandList pCommandList, _s_d49feb52_RootParameterIndex RootParameterIndex, _s_d49feb52_BufferLocation BufferLocation) {
  x12CommandListSetComputeRootUnorderedAccessView(pCommandList.value, RootParameterIndex.value, BufferLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRootShaderResourceView x12CommandListSetComputeRootShaderResourceView
#define _cc395e92_pCommandList(value) value
#define _cc395e92_RootParameterIndex(value) value
#define _cc395e92_BufferLocation(value) value
#else
typedef struct _s_cc395e92_pCommandList { X12CommandList* value; } _s_cc395e92_pCommandList;
typedef struct _s_cc395e92_RootParameterIndex { unsigned value; } _s_cc395e92_RootParameterIndex;
typedef struct _s_cc395e92_BufferLocation { D3D12_GPU_VIRTUAL_ADDRESS value; } _s_cc395e92_BufferLocation;
static inline _s_cc395e92_pCommandList _cc395e92_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_cc395e92_pCommandList){value}; }
static inline _s_cc395e92_RootParameterIndex _cc395e92_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cc395e92_RootParameterIndex){value}; }
static inline _s_cc395e92_BufferLocation _cc395e92_BufferLocation(D3D12_GPU_VIRTUAL_ADDRESS value) { return REDGPU_NP_STRUCT_INIT(_s_cc395e92_BufferLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRootShaderResourceView(_s_cc395e92_pCommandList pCommandList, _s_cc395e92_RootParameterIndex RootParameterIndex, _s_cc395e92_BufferLocation BufferLocation) {
  x12CommandListSetComputeRootShaderResourceView(pCommandList.value, RootParameterIndex.value, BufferLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetComputeRootConstantBufferView x12CommandListSetComputeRootConstantBufferView
#define _b853c1ff_pCommandList(value) value
#define _b853c1ff_RootParameterIndex(value) value
#define _b853c1ff_BufferLocation(value) value
#else
typedef struct _s_b853c1ff_pCommandList { X12CommandList* value; } _s_b853c1ff_pCommandList;
typedef struct _s_b853c1ff_RootParameterIndex { unsigned value; } _s_b853c1ff_RootParameterIndex;
typedef struct _s_b853c1ff_BufferLocation { D3D12_GPU_VIRTUAL_ADDRESS value; } _s_b853c1ff_BufferLocation;
static inline _s_b853c1ff_pCommandList _b853c1ff_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_b853c1ff_pCommandList){value}; }
static inline _s_b853c1ff_RootParameterIndex _b853c1ff_RootParameterIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b853c1ff_RootParameterIndex){value}; }
static inline _s_b853c1ff_BufferLocation _b853c1ff_BufferLocation(D3D12_GPU_VIRTUAL_ADDRESS value) { return REDGPU_NP_STRUCT_INIT(_s_b853c1ff_BufferLocation){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetComputeRootConstantBufferView(_s_b853c1ff_pCommandList pCommandList, _s_b853c1ff_RootParameterIndex RootParameterIndex, _s_b853c1ff_BufferLocation BufferLocation) {
  x12CommandListSetComputeRootConstantBufferView(pCommandList.value, RootParameterIndex.value, BufferLocation.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListClearState x12CommandListClearState
#define _56553c29_pCommandList(value) value
#define _56553c29_pPipelineState(value) value
#else
typedef struct _s_56553c29_pCommandList { X12CommandList* value; } _s_56553c29_pCommandList;
typedef struct _s_56553c29_pPipelineState { X12PipelineState* value; } _s_56553c29_pPipelineState;
static inline _s_56553c29_pCommandList _56553c29_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_56553c29_pCommandList){value}; }
static inline _s_56553c29_pPipelineState _56553c29_pPipelineState(X12PipelineState* value) { return REDGPU_NP_STRUCT_INIT(_s_56553c29_pPipelineState){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListClearState(_s_56553c29_pCommandList pCommandList, _s_56553c29_pPipelineState pPipelineState) {
  x12CommandListClearState(pCommandList.value, pPipelineState.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetPipelineState x12CommandListSetPipelineState
#define _a707aa16_pCommandList(value) value
#define _a707aa16_pPipelineState(value) value
#else
typedef struct _s_a707aa16_pCommandList { X12CommandList* value; } _s_a707aa16_pCommandList;
typedef struct _s_a707aa16_pPipelineState { X12PipelineState* value; } _s_a707aa16_pPipelineState;
static inline _s_a707aa16_pCommandList _a707aa16_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_a707aa16_pCommandList){value}; }
static inline _s_a707aa16_pPipelineState _a707aa16_pPipelineState(X12PipelineState* value) { return REDGPU_NP_STRUCT_INIT(_s_a707aa16_pPipelineState){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetPipelineState(_s_a707aa16_pCommandList pCommandList, _s_a707aa16_pPipelineState pPipelineState) {
  x12CommandListSetPipelineState(pCommandList.value, pPipelineState.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListIASetPrimitiveTopology x12CommandListIASetPrimitiveTopology
#define _e0897adc_pCommandList(value) value
#define _e0897adc_PrimitiveTopology(value) value
#else
typedef struct _s_e0897adc_pCommandList { X12CommandList* value; } _s_e0897adc_pCommandList;
typedef struct _s_e0897adc_PrimitiveTopology { D3D12_PRIMITIVE_TOPOLOGY value; } _s_e0897adc_PrimitiveTopology;
static inline _s_e0897adc_pCommandList _e0897adc_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_e0897adc_pCommandList){value}; }
static inline _s_e0897adc_PrimitiveTopology _e0897adc_PrimitiveTopology(D3D12_PRIMITIVE_TOPOLOGY value) { return REDGPU_NP_STRUCT_INIT(_s_e0897adc_PrimitiveTopology){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListIASetPrimitiveTopology(_s_e0897adc_pCommandList pCommandList, _s_e0897adc_PrimitiveTopology PrimitiveTopology) {
  x12CommandListIASetPrimitiveTopology(pCommandList.value, PrimitiveTopology.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListIASetIndexBuffer x12CommandListIASetIndexBuffer
#define _9a1d3fe8_pCommandList(value) value
#define _9a1d3fe8_pView(value) value
#else
typedef struct _s_9a1d3fe8_pCommandList { X12CommandList* value; } _s_9a1d3fe8_pCommandList;
typedef struct _s_9a1d3fe8_pView { D3D12_INDEX_BUFFER_VIEW* value; } _s_9a1d3fe8_pView;
static inline _s_9a1d3fe8_pCommandList _9a1d3fe8_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_9a1d3fe8_pCommandList){value}; }
static inline _s_9a1d3fe8_pView _9a1d3fe8_pView(D3D12_INDEX_BUFFER_VIEW* value) { return REDGPU_NP_STRUCT_INIT(_s_9a1d3fe8_pView){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListIASetIndexBuffer(_s_9a1d3fe8_pCommandList pCommandList, _s_9a1d3fe8_pView pView) {
  x12CommandListIASetIndexBuffer(pCommandList.value, pView.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListOMSetStencilRef x12CommandListOMSetStencilRef
#define _5238d0fb_pCommandList(value) value
#define _5238d0fb_StencilRef(value) value
#else
typedef struct _s_5238d0fb_pCommandList { X12CommandList* value; } _s_5238d0fb_pCommandList;
typedef struct _s_5238d0fb_StencilRef { unsigned value; } _s_5238d0fb_StencilRef;
static inline _s_5238d0fb_pCommandList _5238d0fb_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_5238d0fb_pCommandList){value}; }
static inline _s_5238d0fb_StencilRef _5238d0fb_StencilRef(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_5238d0fb_StencilRef){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListOMSetStencilRef(_s_5238d0fb_pCommandList pCommandList, _s_5238d0fb_StencilRef StencilRef) {
  x12CommandListOMSetStencilRef(pCommandList.value, StencilRef.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListOMSetBlendFactor x12CommandListOMSetBlendFactor
#define _39b569d7_pCommandList(value) value
#define _39b569d7_BlendFactor4Values(value) value
#else
typedef struct _s_39b569d7_pCommandList { X12CommandList* value; } _s_39b569d7_pCommandList;
typedef struct _s_39b569d7_BlendFactor4Values { float* value; } _s_39b569d7_BlendFactor4Values;
static inline _s_39b569d7_pCommandList _39b569d7_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_39b569d7_pCommandList){value}; }
static inline _s_39b569d7_BlendFactor4Values _39b569d7_BlendFactor4Values(float* value) { return REDGPU_NP_STRUCT_INIT(_s_39b569d7_BlendFactor4Values){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListOMSetBlendFactor(_s_39b569d7_pCommandList pCommandList, _s_39b569d7_BlendFactor4Values BlendFactor4Values) {
  x12CommandListOMSetBlendFactor(pCommandList.value, BlendFactor4Values.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListRSSetViewports x12CommandListRSSetViewports
#define _65a138c6_pCommandList(value) value
#define _65a138c6_NumViewports(value) value
#define _65a138c6_pViewports(value) value
#else
typedef struct _s_65a138c6_pCommandList { X12CommandList* value; } _s_65a138c6_pCommandList;
typedef struct _s_65a138c6_NumViewports { unsigned value; } _s_65a138c6_NumViewports;
typedef struct _s_65a138c6_pViewports { D3D12_VIEWPORT* value; } _s_65a138c6_pViewports;
static inline _s_65a138c6_pCommandList _65a138c6_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_65a138c6_pCommandList){value}; }
static inline _s_65a138c6_NumViewports _65a138c6_NumViewports(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_65a138c6_NumViewports){value}; }
static inline _s_65a138c6_pViewports _65a138c6_pViewports(D3D12_VIEWPORT* value) { return REDGPU_NP_STRUCT_INIT(_s_65a138c6_pViewports){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListRSSetViewports(_s_65a138c6_pCommandList pCommandList, _s_65a138c6_NumViewports NumViewports, _s_65a138c6_pViewports pViewports) {
  x12CommandListRSSetViewports(pCommandList.value, NumViewports.value, pViewports.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListRSSetScissorRects x12CommandListRSSetScissorRects
#define _5e40e124_pCommandList(value) value
#define _5e40e124_NumRects(value) value
#define _5e40e124_pRects(value) value
#else
typedef struct _s_5e40e124_pCommandList { X12CommandList* value; } _s_5e40e124_pCommandList;
typedef struct _s_5e40e124_NumRects { unsigned value; } _s_5e40e124_NumRects;
typedef struct _s_5e40e124_pRects { D3D12_RECT* value; } _s_5e40e124_pRects;
static inline _s_5e40e124_pCommandList _5e40e124_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_5e40e124_pCommandList){value}; }
static inline _s_5e40e124_NumRects _5e40e124_NumRects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_5e40e124_NumRects){value}; }
static inline _s_5e40e124_pRects _5e40e124_pRects(D3D12_RECT* value) { return REDGPU_NP_STRUCT_INIT(_s_5e40e124_pRects){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListRSSetScissorRects(_s_5e40e124_pCommandList pCommandList, _s_5e40e124_NumRects NumRects, _s_5e40e124_pRects pRects) {
  x12CommandListRSSetScissorRects(pCommandList.value, NumRects.value, pRects.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListClearRenderTargetView x12CommandListClearRenderTargetView
#define _e2375aa0_pCommandList(value) value
#define _e2375aa0_RenderTargetView(value) value
#define _e2375aa0_ColorRGBA[4](value) value
#define _e2375aa0_NumRects(value) value
#define _e2375aa0_pRects(value) value
#else
typedef struct _s_e2375aa0_pCommandList { X12CommandList* value; } _s_e2375aa0_pCommandList;
typedef struct _s_e2375aa0_RenderTargetView { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_e2375aa0_RenderTargetView;
typedef struct _s_e2375aa0_ColorRGBA[4] { float value; } _s_e2375aa0_ColorRGBA[4];
typedef struct _s_e2375aa0_NumRects { unsigned value; } _s_e2375aa0_NumRects;
typedef struct _s_e2375aa0_pRects { D3D12_RECT* value; } _s_e2375aa0_pRects;
static inline _s_e2375aa0_pCommandList _e2375aa0_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_e2375aa0_pCommandList){value}; }
static inline _s_e2375aa0_RenderTargetView _e2375aa0_RenderTargetView(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_e2375aa0_RenderTargetView){value}; }
static inline _s_e2375aa0_ColorRGBA[4] _e2375aa0_ColorRGBA[4](float value) { return REDGPU_NP_STRUCT_INIT(_s_e2375aa0_ColorRGBA[4]){value}; }
static inline _s_e2375aa0_NumRects _e2375aa0_NumRects(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e2375aa0_NumRects){value}; }
static inline _s_e2375aa0_pRects _e2375aa0_pRects(D3D12_RECT* value) { return REDGPU_NP_STRUCT_INIT(_s_e2375aa0_pRects){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListClearRenderTargetView(_s_e2375aa0_pCommandList pCommandList, _s_e2375aa0_RenderTargetView RenderTargetView, _s_e2375aa0_ColorRGBA[4] ColorRGBA[4], _s_e2375aa0_NumRects NumRects, _s_e2375aa0_pRects pRects) {
  x12CommandListClearRenderTargetView(pCommandList.value, RenderTargetView.value, ColorRGBA[4].value, NumRects.value, pRects.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListClearDepthStencilView x12CommandListClearDepthStencilView
#define _e120a02f_pCommandList(value) value
#define _e120a02f_DepthStencilView(value) value
#define _e120a02f_ClearFlags(value) value
#define _e120a02f_Depth(value) value
#define _e120a02f_char(value) value
#define _e120a02f_unsigned(value) value
#define _e120a02f_D3D12_RECT*(value) value
#define _e120a02f_(value) value
#else
typedef struct _s_e120a02f_pCommandList { X12CommandList* value; } _s_e120a02f_pCommandList;
typedef struct _s_e120a02f_DepthStencilView { D3D12_CPU_DESCRIPTOR_HANDLE value; } _s_e120a02f_DepthStencilView;
typedef struct _s_e120a02f_ClearFlags { D3D12_CLEAR_FLAGS value; } _s_e120a02f_ClearFlags;
typedef struct _s_e120a02f_Depth { float value; } _s_e120a02f_Depth;
typedef struct _s_e120a02f_char { unsigned value; } _s_e120a02f_char;
typedef struct _s_e120a02f_unsigned { Stencil value; } _s_e120a02f_unsigned;
typedef struct _s_e120a02f_D3D12_RECT* { NumRects value; } _s_e120a02f_D3D12_RECT*;
typedef struct _s_e120a02f_ { pRects value; } _s_e120a02f_;
static inline _s_e120a02f_pCommandList _e120a02f_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_e120a02f_pCommandList){value}; }
static inline _s_e120a02f_DepthStencilView _e120a02f_DepthStencilView(D3D12_CPU_DESCRIPTOR_HANDLE value) { return REDGPU_NP_STRUCT_INIT(_s_e120a02f_DepthStencilView){value}; }
static inline _s_e120a02f_ClearFlags _e120a02f_ClearFlags(D3D12_CLEAR_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_e120a02f_ClearFlags){value}; }
static inline _s_e120a02f_Depth _e120a02f_Depth(float value) { return REDGPU_NP_STRUCT_INIT(_s_e120a02f_Depth){value}; }
static inline _s_e120a02f_char _e120a02f_char(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e120a02f_char){value}; }
static inline _s_e120a02f_unsigned _e120a02f_unsigned(Stencil value) { return REDGPU_NP_STRUCT_INIT(_s_e120a02f_unsigned){value}; }
static inline _s_e120a02f_D3D12_RECT* _e120a02f_D3D12_RECT*(NumRects value) { return REDGPU_NP_STRUCT_INIT(_s_e120a02f_D3D12_RECT*){value}; }
static inline _s_e120a02f_ _e120a02f_(pRects value) { return REDGPU_NP_STRUCT_INIT(_s_e120a02f_){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListClearDepthStencilView(_s_e120a02f_pCommandList pCommandList, _s_e120a02f_DepthStencilView DepthStencilView, _s_e120a02f_ClearFlags ClearFlags, _s_e120a02f_Depth Depth, _s_e120a02f_char char, _s_e120a02f_unsigned unsigned, _s_e120a02f_D3D12_RECT* D3D12_RECT*, _s_e120a02f_ ) {
  x12CommandListClearDepthStencilView(pCommandList.value, DepthStencilView.value, ClearFlags.value, Depth.value, char.value, unsigned.value, D3D12_RECT*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListDiscardResource x12CommandListDiscardResource
#define _a22910d9_pCommandList(value) value
#define _a22910d9_pResource(value) value
#define _a22910d9_pRegion(value) value
#else
typedef struct _s_a22910d9_pCommandList { X12CommandList* value; } _s_a22910d9_pCommandList;
typedef struct _s_a22910d9_pResource { X12Resource* value; } _s_a22910d9_pResource;
typedef struct _s_a22910d9_pRegion { D3D12_DISCARD_REGION* value; } _s_a22910d9_pRegion;
static inline _s_a22910d9_pCommandList _a22910d9_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_a22910d9_pCommandList){value}; }
static inline _s_a22910d9_pResource _a22910d9_pResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_a22910d9_pResource){value}; }
static inline _s_a22910d9_pRegion _a22910d9_pRegion(D3D12_DISCARD_REGION* value) { return REDGPU_NP_STRUCT_INIT(_s_a22910d9_pRegion){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListDiscardResource(_s_a22910d9_pCommandList pCommandList, _s_a22910d9_pResource pResource, _s_a22910d9_pRegion pRegion) {
  x12CommandListDiscardResource(pCommandList.value, pResource.value, pRegion.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListOMSetRenderTargets x12CommandListOMSetRenderTargets
#define _9d855e2a_pCommandList(value) value
#define _9d855e2a_NumRenderTargetDescriptors(value) value
#define _9d855e2a_pRenderTargetDescriptors(value) value
#define _9d855e2a_RTsSingleHandleToDescriptorRange(value) value
#define _9d855e2a_pDepthStencilDescriptor(value) value
#else
typedef struct _s_9d855e2a_pCommandList { X12CommandList* value; } _s_9d855e2a_pCommandList;
typedef struct _s_9d855e2a_NumRenderTargetDescriptors { unsigned value; } _s_9d855e2a_NumRenderTargetDescriptors;
typedef struct _s_9d855e2a_pRenderTargetDescriptors { D3D12_CPU_DESCRIPTOR_HANDLE* value; } _s_9d855e2a_pRenderTargetDescriptors;
typedef struct _s_9d855e2a_RTsSingleHandleToDescriptorRange { X12Bool value; } _s_9d855e2a_RTsSingleHandleToDescriptorRange;
typedef struct _s_9d855e2a_pDepthStencilDescriptor { D3D12_CPU_DESCRIPTOR_HANDLE* value; } _s_9d855e2a_pDepthStencilDescriptor;
static inline _s_9d855e2a_pCommandList _9d855e2a_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_9d855e2a_pCommandList){value}; }
static inline _s_9d855e2a_NumRenderTargetDescriptors _9d855e2a_NumRenderTargetDescriptors(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9d855e2a_NumRenderTargetDescriptors){value}; }
static inline _s_9d855e2a_pRenderTargetDescriptors _9d855e2a_pRenderTargetDescriptors(D3D12_CPU_DESCRIPTOR_HANDLE* value) { return REDGPU_NP_STRUCT_INIT(_s_9d855e2a_pRenderTargetDescriptors){value}; }
static inline _s_9d855e2a_RTsSingleHandleToDescriptorRange _9d855e2a_RTsSingleHandleToDescriptorRange(X12Bool value) { return REDGPU_NP_STRUCT_INIT(_s_9d855e2a_RTsSingleHandleToDescriptorRange){value}; }
static inline _s_9d855e2a_pDepthStencilDescriptor _9d855e2a_pDepthStencilDescriptor(D3D12_CPU_DESCRIPTOR_HANDLE* value) { return REDGPU_NP_STRUCT_INIT(_s_9d855e2a_pDepthStencilDescriptor){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListOMSetRenderTargets(_s_9d855e2a_pCommandList pCommandList, _s_9d855e2a_NumRenderTargetDescriptors NumRenderTargetDescriptors, _s_9d855e2a_pRenderTargetDescriptors pRenderTargetDescriptors, _s_9d855e2a_RTsSingleHandleToDescriptorRange RTsSingleHandleToDescriptorRange, _s_9d855e2a_pDepthStencilDescriptor pDepthStencilDescriptor) {
  x12CommandListOMSetRenderTargets(pCommandList.value, NumRenderTargetDescriptors.value, pRenderTargetDescriptors.value, RTsSingleHandleToDescriptorRange.value, pDepthStencilDescriptor.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListResolveSubresource x12CommandListResolveSubresource
#define _7fc942b2_pCommandList(value) value
#define _7fc942b2_pDstResource(value) value
#define _7fc942b2_DstSubresource(value) value
#define _7fc942b2_pSrcResource(value) value
#define _7fc942b2_SrcSubresource(value) value
#define _7fc942b2_Format(value) value
#else
typedef struct _s_7fc942b2_pCommandList { X12CommandList* value; } _s_7fc942b2_pCommandList;
typedef struct _s_7fc942b2_pDstResource { X12Resource* value; } _s_7fc942b2_pDstResource;
typedef struct _s_7fc942b2_DstSubresource { unsigned value; } _s_7fc942b2_DstSubresource;
typedef struct _s_7fc942b2_pSrcResource { X12Resource* value; } _s_7fc942b2_pSrcResource;
typedef struct _s_7fc942b2_SrcSubresource { unsigned value; } _s_7fc942b2_SrcSubresource;
typedef struct _s_7fc942b2_Format { DXGI_FORMAT value; } _s_7fc942b2_Format;
static inline _s_7fc942b2_pCommandList _7fc942b2_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_7fc942b2_pCommandList){value}; }
static inline _s_7fc942b2_pDstResource _7fc942b2_pDstResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_7fc942b2_pDstResource){value}; }
static inline _s_7fc942b2_DstSubresource _7fc942b2_DstSubresource(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_7fc942b2_DstSubresource){value}; }
static inline _s_7fc942b2_pSrcResource _7fc942b2_pSrcResource(X12Resource* value) { return REDGPU_NP_STRUCT_INIT(_s_7fc942b2_pSrcResource){value}; }
static inline _s_7fc942b2_SrcSubresource _7fc942b2_SrcSubresource(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_7fc942b2_SrcSubresource){value}; }
static inline _s_7fc942b2_Format _7fc942b2_Format(DXGI_FORMAT value) { return REDGPU_NP_STRUCT_INIT(_s_7fc942b2_Format){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListResolveSubresource(_s_7fc942b2_pCommandList pCommandList, _s_7fc942b2_pDstResource pDstResource, _s_7fc942b2_DstSubresource DstSubresource, _s_7fc942b2_pSrcResource pSrcResource, _s_7fc942b2_SrcSubresource SrcSubresource, _s_7fc942b2_Format Format) {
  x12CommandListResolveSubresource(pCommandList.value, pDstResource.value, DstSubresource.value, pSrcResource.value, SrcSubresource.value, Format.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListResourceBarrier x12CommandListResourceBarrier
#define _49c0e676_pCommandList(value) value
#define _49c0e676_NumBarriers(value) value
#define _49c0e676_pBarriers(value) value
#else
typedef struct _s_49c0e676_pCommandList { X12CommandList* value; } _s_49c0e676_pCommandList;
typedef struct _s_49c0e676_NumBarriers { unsigned value; } _s_49c0e676_NumBarriers;
typedef struct _s_49c0e676_pBarriers { D3D12_RESOURCE_BARRIER* value; } _s_49c0e676_pBarriers;
static inline _s_49c0e676_pCommandList _49c0e676_pCommandList(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_49c0e676_pCommandList){value}; }
static inline _s_49c0e676_NumBarriers _49c0e676_NumBarriers(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_49c0e676_NumBarriers){value}; }
static inline _s_49c0e676_pBarriers _49c0e676_pBarriers(D3D12_RESOURCE_BARRIER* value) { return REDGPU_NP_STRUCT_INIT(_s_49c0e676_pBarriers){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListResourceBarrier(_s_49c0e676_pCommandList pCommandList, _s_49c0e676_NumBarriers NumBarriers, _s_49c0e676_pBarriers pBarriers) {
  x12CommandListResourceBarrier(pCommandList.value, NumBarriers.value, pBarriers.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandQueueWait x12CommandQueueWait
#define _3178a99c_pCommandQueue(value) value
#define _3178a99c_pFence(value) value
#define _3178a99c_Value(value) value
#define _3178a99c_optionalFile(value) value
#define _3178a99c_optionalLine(value) value
#else
typedef struct _s_3178a99c_pCommandQueue { X12CommandQueue* value; } _s_3178a99c_pCommandQueue;
typedef struct _s_3178a99c_pFence { X12Fence* value; } _s_3178a99c_pFence;
typedef struct _s_3178a99c_Value { uint64_t value; } _s_3178a99c_Value;
typedef struct _s_3178a99c_optionalFile { char* value; } _s_3178a99c_optionalFile;
typedef struct _s_3178a99c_optionalLine { int value; } _s_3178a99c_optionalLine;
static inline _s_3178a99c_pCommandQueue _3178a99c_pCommandQueue(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_3178a99c_pCommandQueue){value}; }
static inline _s_3178a99c_pFence _3178a99c_pFence(X12Fence* value) { return REDGPU_NP_STRUCT_INIT(_s_3178a99c_pFence){value}; }
static inline _s_3178a99c_Value _3178a99c_Value(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_3178a99c_Value){value}; }
static inline _s_3178a99c_optionalFile _3178a99c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3178a99c_optionalFile){value}; }
static inline _s_3178a99c_optionalLine _3178a99c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3178a99c_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CommandQueueWait(_s_3178a99c_pCommandQueue pCommandQueue, _s_3178a99c_pFence pFence, _s_3178a99c_Value Value, _s_3178a99c_optionalFile optionalFile, _s_3178a99c_optionalLine optionalLine) {
  return x12CommandQueueWait(pCommandQueue.value, pFence.value, Value.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandQueueExecuteCommandLists x12CommandQueueExecuteCommandLists
#define _cf320073_pCommandQueue(value) value
#define _cf320073_NumCommandLists(value) value
#define _cf320073_ppCommandLists(value) value
#define _cf320073_optionalFile(value) value
#define _cf320073_optionalLine(value) value
#else
typedef struct _s_cf320073_pCommandQueue { X12CommandQueue* value; } _s_cf320073_pCommandQueue;
typedef struct _s_cf320073_NumCommandLists { unsigned value; } _s_cf320073_NumCommandLists;
typedef struct _s_cf320073_ppCommandLists { X12CommandList** value; } _s_cf320073_ppCommandLists;
typedef struct _s_cf320073_optionalFile { char* value; } _s_cf320073_optionalFile;
typedef struct _s_cf320073_optionalLine { int value; } _s_cf320073_optionalLine;
static inline _s_cf320073_pCommandQueue _cf320073_pCommandQueue(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_cf320073_pCommandQueue){value}; }
static inline _s_cf320073_NumCommandLists _cf320073_NumCommandLists(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cf320073_NumCommandLists){value}; }
static inline _s_cf320073_ppCommandLists _cf320073_ppCommandLists(X12CommandList** value) { return REDGPU_NP_STRUCT_INIT(_s_cf320073_ppCommandLists){value}; }
static inline _s_cf320073_optionalFile _cf320073_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cf320073_optionalFile){value}; }
static inline _s_cf320073_optionalLine _cf320073_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cf320073_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandQueueExecuteCommandLists(_s_cf320073_pCommandQueue pCommandQueue, _s_cf320073_NumCommandLists NumCommandLists, _s_cf320073_ppCommandLists ppCommandLists, _s_cf320073_optionalFile optionalFile, _s_cf320073_optionalLine optionalLine) {
  x12CommandQueueExecuteCommandLists(pCommandQueue.value, NumCommandLists.value, ppCommandLists.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandQueueSignal x12CommandQueueSignal
#define _a1760fb9_pCommandQueue(value) value
#define _a1760fb9_pFence(value) value
#define _a1760fb9_Value(value) value
#define _a1760fb9_optionalFile(value) value
#define _a1760fb9_optionalLine(value) value
#else
typedef struct _s_a1760fb9_pCommandQueue { X12CommandQueue* value; } _s_a1760fb9_pCommandQueue;
typedef struct _s_a1760fb9_pFence { X12Fence* value; } _s_a1760fb9_pFence;
typedef struct _s_a1760fb9_Value { uint64_t value; } _s_a1760fb9_Value;
typedef struct _s_a1760fb9_optionalFile { char* value; } _s_a1760fb9_optionalFile;
typedef struct _s_a1760fb9_optionalLine { int value; } _s_a1760fb9_optionalLine;
static inline _s_a1760fb9_pCommandQueue _a1760fb9_pCommandQueue(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_a1760fb9_pCommandQueue){value}; }
static inline _s_a1760fb9_pFence _a1760fb9_pFence(X12Fence* value) { return REDGPU_NP_STRUCT_INIT(_s_a1760fb9_pFence){value}; }
static inline _s_a1760fb9_Value _a1760fb9_Value(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_a1760fb9_Value){value}; }
static inline _s_a1760fb9_optionalFile _a1760fb9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a1760fb9_optionalFile){value}; }
static inline _s_a1760fb9_optionalLine _a1760fb9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a1760fb9_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12CommandQueueSignal(_s_a1760fb9_pCommandQueue pCommandQueue, _s_a1760fb9_pFence pFence, _s_a1760fb9_Value Value, _s_a1760fb9_optionalFile optionalFile, _s_a1760fb9_optionalLine optionalLine) {
  return x12CommandQueueSignal(pCommandQueue.value, pFence.value, Value.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryIsCurrent x12FactoryIsCurrent
#define _e72da452_pFactory(value) value
#define _e72da452_optionalFile(value) value
#define _e72da452_optionalLine(value) value
#else
typedef struct _s_e72da452_pFactory { X12Factory4* value; } _s_e72da452_pFactory;
typedef struct _s_e72da452_optionalFile { char* value; } _s_e72da452_optionalFile;
typedef struct _s_e72da452_optionalLine { int value; } _s_e72da452_optionalLine;
static inline _s_e72da452_pFactory _e72da452_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_e72da452_pFactory){value}; }
static inline _s_e72da452_optionalFile _e72da452_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e72da452_optionalFile){value}; }
static inline _s_e72da452_optionalLine _e72da452_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e72da452_optionalLine){value}; }
REDGPU_NP_DECLSPEC X12Bool REDGPU_NP_API np_x12FactoryIsCurrent(_s_e72da452_pFactory pFactory, _s_e72da452_optionalFile optionalFile, _s_e72da452_optionalLine optionalLine) {
  return x12FactoryIsCurrent(pFactory.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12AdapterGetDesc2 x12AdapterGetDesc2
#define _a8264d78_pAdapter(value) value
#define _a8264d78_outDesc(value) value
#define _a8264d78_optionalFile(value) value
#define _a8264d78_optionalLine(value) value
#else
typedef struct _s_a8264d78_pAdapter { X12Adapter3* value; } _s_a8264d78_pAdapter;
typedef struct _s_a8264d78_outDesc { DXGI_ADAPTER_DESC2* value; } _s_a8264d78_outDesc;
typedef struct _s_a8264d78_optionalFile { char* value; } _s_a8264d78_optionalFile;
typedef struct _s_a8264d78_optionalLine { int value; } _s_a8264d78_optionalLine;
static inline _s_a8264d78_pAdapter _a8264d78_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_a8264d78_pAdapter){value}; }
static inline _s_a8264d78_outDesc _a8264d78_outDesc(DXGI_ADAPTER_DESC2* value) { return REDGPU_NP_STRUCT_INIT(_s_a8264d78_outDesc){value}; }
static inline _s_a8264d78_optionalFile _a8264d78_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a8264d78_optionalFile){value}; }
static inline _s_a8264d78_optionalLine _a8264d78_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a8264d78_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12AdapterGetDesc2(_s_a8264d78_pAdapter pAdapter, _s_a8264d78_outDesc outDesc, _s_a8264d78_optionalFile optionalFile, _s_a8264d78_optionalLine optionalLine) {
  return x12AdapterGetDesc2(pAdapter.value, outDesc.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12AdapterEnumOutputs x12AdapterEnumOutputs
#define _6bd27d86_pAdapter(value) value
#define _6bd27d86_Output(value) value
#define _6bd27d86_outpOutput(value) value
#define _6bd27d86_optionalFile(value) value
#define _6bd27d86_optionalLine(value) value
#else
typedef struct _s_6bd27d86_pAdapter { X12Adapter3* value; } _s_6bd27d86_pAdapter;
typedef struct _s_6bd27d86_Output { unsigned value; } _s_6bd27d86_Output;
typedef struct _s_6bd27d86_outpOutput { X12Output4** value; } _s_6bd27d86_outpOutput;
typedef struct _s_6bd27d86_optionalFile { char* value; } _s_6bd27d86_optionalFile;
typedef struct _s_6bd27d86_optionalLine { int value; } _s_6bd27d86_optionalLine;
static inline _s_6bd27d86_pAdapter _6bd27d86_pAdapter(X12Adapter3* value) { return REDGPU_NP_STRUCT_INIT(_s_6bd27d86_pAdapter){value}; }
static inline _s_6bd27d86_Output _6bd27d86_Output(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6bd27d86_Output){value}; }
static inline _s_6bd27d86_outpOutput _6bd27d86_outpOutput(X12Output4** value) { return REDGPU_NP_STRUCT_INIT(_s_6bd27d86_outpOutput){value}; }
static inline _s_6bd27d86_optionalFile _6bd27d86_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6bd27d86_optionalFile){value}; }
static inline _s_6bd27d86_optionalLine _6bd27d86_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6bd27d86_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12AdapterEnumOutputs(_s_6bd27d86_pAdapter pAdapter, _s_6bd27d86_Output Output, _s_6bd27d86_outpOutput outpOutput, _s_6bd27d86_optionalFile optionalFile, _s_6bd27d86_optionalLine optionalLine) {
  return x12AdapterEnumOutputs(pAdapter.value, Output.value, outpOutput.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceGetAdapterLuid x12DeviceGetAdapterLuid
#define _efc72b2b_pDevice(value) value
#define _efc72b2b_outLuid(value) value
#define _efc72b2b_optionalFile(value) value
#define _efc72b2b_optionalLine(value) value
#else
typedef struct _s_efc72b2b_pDevice { X12Device3* value; } _s_efc72b2b_pDevice;
typedef struct _s_efc72b2b_outLuid { uint64_t* value; } _s_efc72b2b_outLuid;
typedef struct _s_efc72b2b_optionalFile { char* value; } _s_efc72b2b_optionalFile;
typedef struct _s_efc72b2b_optionalLine { int value; } _s_efc72b2b_optionalLine;
static inline _s_efc72b2b_pDevice _efc72b2b_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_efc72b2b_pDevice){value}; }
static inline _s_efc72b2b_outLuid _efc72b2b_outLuid(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_efc72b2b_outLuid){value}; }
static inline _s_efc72b2b_optionalFile _efc72b2b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_efc72b2b_optionalFile){value}; }
static inline _s_efc72b2b_optionalLine _efc72b2b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_efc72b2b_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12DeviceGetAdapterLuid(_s_efc72b2b_pDevice pDevice, _s_efc72b2b_outLuid outLuid, _s_efc72b2b_optionalFile optionalFile, _s_efc72b2b_optionalLine optionalLine) {
  x12DeviceGetAdapterLuid(pDevice.value, outLuid.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceGetDescriptorHandleIncrementSize x12DeviceGetDescriptorHandleIncrementSize
#define _24b0624d_pDevice(value) value
#define _24b0624d_DescriptorHeapType(value) value
#define _24b0624d_optionalFile(value) value
#define _24b0624d_optionalLine(value) value
#else
typedef struct _s_24b0624d_pDevice { X12Device3* value; } _s_24b0624d_pDevice;
typedef struct _s_24b0624d_DescriptorHeapType { D3D12_DESCRIPTOR_HEAP_TYPE value; } _s_24b0624d_DescriptorHeapType;
typedef struct _s_24b0624d_optionalFile { char* value; } _s_24b0624d_optionalFile;
typedef struct _s_24b0624d_optionalLine { int value; } _s_24b0624d_optionalLine;
static inline _s_24b0624d_pDevice _24b0624d_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_24b0624d_pDevice){value}; }
static inline _s_24b0624d_DescriptorHeapType _24b0624d_DescriptorHeapType(D3D12_DESCRIPTOR_HEAP_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_24b0624d_DescriptorHeapType){value}; }
static inline _s_24b0624d_optionalFile _24b0624d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_24b0624d_optionalFile){value}; }
static inline _s_24b0624d_optionalLine _24b0624d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_24b0624d_optionalLine){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_x12DeviceGetDescriptorHandleIncrementSize(_s_24b0624d_pDevice pDevice, _s_24b0624d_DescriptorHeapType DescriptorHeapType, _s_24b0624d_optionalFile optionalFile, _s_24b0624d_optionalLine optionalLine) {
  return x12DeviceGetDescriptorHandleIncrementSize(pDevice.value, DescriptorHeapType.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceCheckFeatureSupport x12DeviceCheckFeatureSupport
#define _50ab8204_pDevice(value) value
#define _50ab8204_Feature(value) value
#define _50ab8204_pFeatureSupportData(value) value
#define _50ab8204_FeatureSupportDataSize(value) value
#define _50ab8204_optionalFile(value) value
#define _50ab8204_optionalLine(value) value
#else
typedef struct _s_50ab8204_pDevice { X12Device3* value; } _s_50ab8204_pDevice;
typedef struct _s_50ab8204_Feature { D3D12_FEATURE value; } _s_50ab8204_Feature;
typedef struct _s_50ab8204_pFeatureSupportData { void* value; } _s_50ab8204_pFeatureSupportData;
typedef struct _s_50ab8204_FeatureSupportDataSize { unsigned value; } _s_50ab8204_FeatureSupportDataSize;
typedef struct _s_50ab8204_optionalFile { char* value; } _s_50ab8204_optionalFile;
typedef struct _s_50ab8204_optionalLine { int value; } _s_50ab8204_optionalLine;
static inline _s_50ab8204_pDevice _50ab8204_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_50ab8204_pDevice){value}; }
static inline _s_50ab8204_Feature _50ab8204_Feature(D3D12_FEATURE value) { return REDGPU_NP_STRUCT_INIT(_s_50ab8204_Feature){value}; }
static inline _s_50ab8204_pFeatureSupportData _50ab8204_pFeatureSupportData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_50ab8204_pFeatureSupportData){value}; }
static inline _s_50ab8204_FeatureSupportDataSize _50ab8204_FeatureSupportDataSize(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_50ab8204_FeatureSupportDataSize){value}; }
static inline _s_50ab8204_optionalFile _50ab8204_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_50ab8204_optionalFile){value}; }
static inline _s_50ab8204_optionalLine _50ab8204_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_50ab8204_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceCheckFeatureSupport(_s_50ab8204_pDevice pDevice, _s_50ab8204_Feature Feature, _s_50ab8204_pFeatureSupportData pFeatureSupportData, _s_50ab8204_FeatureSupportDataSize FeatureSupportDataSize, _s_50ab8204_optionalFile optionalFile, _s_50ab8204_optionalLine optionalLine) {
  return x12DeviceCheckFeatureSupport(pDevice.value, Feature.value, pFeatureSupportData.value, FeatureSupportDataSize.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceGetDeviceRemovedReason x12DeviceGetDeviceRemovedReason
#define _fbfa3eeb_pDevice(value) value
#define _fbfa3eeb_optionalFile(value) value
#define _fbfa3eeb_optionalLine(value) value
#else
typedef struct _s_fbfa3eeb_pDevice { X12Device3* value; } _s_fbfa3eeb_pDevice;
typedef struct _s_fbfa3eeb_optionalFile { char* value; } _s_fbfa3eeb_optionalFile;
typedef struct _s_fbfa3eeb_optionalLine { int value; } _s_fbfa3eeb_optionalLine;
static inline _s_fbfa3eeb_pDevice _fbfa3eeb_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_fbfa3eeb_pDevice){value}; }
static inline _s_fbfa3eeb_optionalFile _fbfa3eeb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fbfa3eeb_optionalFile){value}; }
static inline _s_fbfa3eeb_optionalLine _fbfa3eeb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fbfa3eeb_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceGetDeviceRemovedReason(_s_fbfa3eeb_pDevice pDevice, _s_fbfa3eeb_optionalFile optionalFile, _s_fbfa3eeb_optionalLine optionalLine) {
  return x12DeviceGetDeviceRemovedReason(pDevice.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12DeviceSetStablePowerState x12DeviceSetStablePowerState
#define _b3233c72_pDevice(value) value
#define _b3233c72_Enable(value) value
#define _b3233c72_optionalFile(value) value
#define _b3233c72_optionalLine(value) value
#else
typedef struct _s_b3233c72_pDevice { X12Device3* value; } _s_b3233c72_pDevice;
typedef struct _s_b3233c72_Enable { X12Bool value; } _s_b3233c72_Enable;
typedef struct _s_b3233c72_optionalFile { char* value; } _s_b3233c72_optionalFile;
typedef struct _s_b3233c72_optionalLine { int value; } _s_b3233c72_optionalLine;
static inline _s_b3233c72_pDevice _b3233c72_pDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_b3233c72_pDevice){value}; }
static inline _s_b3233c72_Enable _b3233c72_Enable(X12Bool value) { return REDGPU_NP_STRUCT_INIT(_s_b3233c72_Enable){value}; }
static inline _s_b3233c72_optionalFile _b3233c72_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b3233c72_optionalFile){value}; }
static inline _s_b3233c72_optionalLine _b3233c72_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b3233c72_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12DeviceSetStablePowerState(_s_b3233c72_pDevice pDevice, _s_b3233c72_Enable Enable, _s_b3233c72_optionalFile optionalFile, _s_b3233c72_optionalLine optionalLine) {
  return x12DeviceSetStablePowerState(pDevice.value, Enable.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryCreateSwapChainForHwnd x12FactoryCreateSwapChainForHwnd
#define _a800a8bf_pFactory(value) value
#define _a800a8bf_pCommandQueue(value) value
#define _a800a8bf_hWnd(value) value
#define _a800a8bf_pDesc(value) value
#define _a800a8bf_pFullscreenDesc(value) value
#define _a800a8bf_pRestrictToOutput(value) value
#define _a800a8bf_outpSwapChain(value) value
#define _a800a8bf_optionalFile(value) value
#define _a800a8bf_optionalLine(value) value
#else
typedef struct _s_a800a8bf_pFactory { X12Factory4* value; } _s_a800a8bf_pFactory;
typedef struct _s_a800a8bf_pCommandQueue { X12CommandQueue* value; } _s_a800a8bf_pCommandQueue;
typedef struct _s_a800a8bf_hWnd { void* value; } _s_a800a8bf_hWnd;
typedef struct _s_a800a8bf_pDesc { DXGI_SWAP_CHAIN_DESC1* value; } _s_a800a8bf_pDesc;
typedef struct _s_a800a8bf_pFullscreenDesc { DXGI_SWAP_CHAIN_FULLSCREEN_DESC* value; } _s_a800a8bf_pFullscreenDesc;
typedef struct _s_a800a8bf_pRestrictToOutput { X12Output4* value; } _s_a800a8bf_pRestrictToOutput;
typedef struct _s_a800a8bf_outpSwapChain { X12SwapChain3** value; } _s_a800a8bf_outpSwapChain;
typedef struct _s_a800a8bf_optionalFile { char* value; } _s_a800a8bf_optionalFile;
typedef struct _s_a800a8bf_optionalLine { int value; } _s_a800a8bf_optionalLine;
static inline _s_a800a8bf_pFactory _a800a8bf_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_a800a8bf_pFactory){value}; }
static inline _s_a800a8bf_pCommandQueue _a800a8bf_pCommandQueue(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_a800a8bf_pCommandQueue){value}; }
static inline _s_a800a8bf_hWnd _a800a8bf_hWnd(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a800a8bf_hWnd){value}; }
static inline _s_a800a8bf_pDesc _a800a8bf_pDesc(DXGI_SWAP_CHAIN_DESC1* value) { return REDGPU_NP_STRUCT_INIT(_s_a800a8bf_pDesc){value}; }
static inline _s_a800a8bf_pFullscreenDesc _a800a8bf_pFullscreenDesc(DXGI_SWAP_CHAIN_FULLSCREEN_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_a800a8bf_pFullscreenDesc){value}; }
static inline _s_a800a8bf_pRestrictToOutput _a800a8bf_pRestrictToOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_a800a8bf_pRestrictToOutput){value}; }
static inline _s_a800a8bf_outpSwapChain _a800a8bf_outpSwapChain(X12SwapChain3** value) { return REDGPU_NP_STRUCT_INIT(_s_a800a8bf_outpSwapChain){value}; }
static inline _s_a800a8bf_optionalFile _a800a8bf_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a800a8bf_optionalFile){value}; }
static inline _s_a800a8bf_optionalLine _a800a8bf_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a800a8bf_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryCreateSwapChainForHwnd(_s_a800a8bf_pFactory pFactory, _s_a800a8bf_pCommandQueue pCommandQueue, _s_a800a8bf_hWnd hWnd, _s_a800a8bf_pDesc pDesc, _s_a800a8bf_pFullscreenDesc pFullscreenDesc, _s_a800a8bf_pRestrictToOutput pRestrictToOutput, _s_a800a8bf_outpSwapChain outpSwapChain, _s_a800a8bf_optionalFile optionalFile, _s_a800a8bf_optionalLine optionalLine) {
  return x12FactoryCreateSwapChainForHwnd(pFactory.value, pCommandQueue.value, hWnd.value, pDesc.value, pFullscreenDesc.value, pRestrictToOutput.value, outpSwapChain.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryCreateSwapChainForCoreWindow x12FactoryCreateSwapChainForCoreWindow
#define _e180f1c8_pFactory(value) value
#define _e180f1c8_pCommandQueue(value) value
#define _e180f1c8_pWindow(value) value
#define _e180f1c8_pDesc(value) value
#define _e180f1c8_pRestrictToOutput(value) value
#define _e180f1c8_outpSwapChain(value) value
#define _e180f1c8_optionalFile(value) value
#define _e180f1c8_optionalLine(value) value
#else
typedef struct _s_e180f1c8_pFactory { X12Factory4* value; } _s_e180f1c8_pFactory;
typedef struct _s_e180f1c8_pCommandQueue { X12CommandQueue* value; } _s_e180f1c8_pCommandQueue;
typedef struct _s_e180f1c8_pWindow { void* value; } _s_e180f1c8_pWindow;
typedef struct _s_e180f1c8_pDesc { DXGI_SWAP_CHAIN_DESC1* value; } _s_e180f1c8_pDesc;
typedef struct _s_e180f1c8_pRestrictToOutput { X12Output4* value; } _s_e180f1c8_pRestrictToOutput;
typedef struct _s_e180f1c8_outpSwapChain { X12SwapChain3** value; } _s_e180f1c8_outpSwapChain;
typedef struct _s_e180f1c8_optionalFile { char* value; } _s_e180f1c8_optionalFile;
typedef struct _s_e180f1c8_optionalLine { int value; } _s_e180f1c8_optionalLine;
static inline _s_e180f1c8_pFactory _e180f1c8_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_e180f1c8_pFactory){value}; }
static inline _s_e180f1c8_pCommandQueue _e180f1c8_pCommandQueue(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_e180f1c8_pCommandQueue){value}; }
static inline _s_e180f1c8_pWindow _e180f1c8_pWindow(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e180f1c8_pWindow){value}; }
static inline _s_e180f1c8_pDesc _e180f1c8_pDesc(DXGI_SWAP_CHAIN_DESC1* value) { return REDGPU_NP_STRUCT_INIT(_s_e180f1c8_pDesc){value}; }
static inline _s_e180f1c8_pRestrictToOutput _e180f1c8_pRestrictToOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_e180f1c8_pRestrictToOutput){value}; }
static inline _s_e180f1c8_outpSwapChain _e180f1c8_outpSwapChain(X12SwapChain3** value) { return REDGPU_NP_STRUCT_INIT(_s_e180f1c8_outpSwapChain){value}; }
static inline _s_e180f1c8_optionalFile _e180f1c8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e180f1c8_optionalFile){value}; }
static inline _s_e180f1c8_optionalLine _e180f1c8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e180f1c8_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryCreateSwapChainForCoreWindow(_s_e180f1c8_pFactory pFactory, _s_e180f1c8_pCommandQueue pCommandQueue, _s_e180f1c8_pWindow pWindow, _s_e180f1c8_pDesc pDesc, _s_e180f1c8_pRestrictToOutput pRestrictToOutput, _s_e180f1c8_outpSwapChain outpSwapChain, _s_e180f1c8_optionalFile optionalFile, _s_e180f1c8_optionalLine optionalLine) {
  return x12FactoryCreateSwapChainForCoreWindow(pFactory.value, pCommandQueue.value, pWindow.value, pDesc.value, pRestrictToOutput.value, outpSwapChain.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryCreateSwapChainForComposition x12FactoryCreateSwapChainForComposition
#define _f514aa0a_pFactory(value) value
#define _f514aa0a_pCommandQueue(value) value
#define _f514aa0a_pDesc(value) value
#define _f514aa0a_pRestrictToOutput(value) value
#define _f514aa0a_outpSwapChain(value) value
#define _f514aa0a_optionalFile(value) value
#define _f514aa0a_optionalLine(value) value
#else
typedef struct _s_f514aa0a_pFactory { X12Factory4* value; } _s_f514aa0a_pFactory;
typedef struct _s_f514aa0a_pCommandQueue { X12CommandQueue* value; } _s_f514aa0a_pCommandQueue;
typedef struct _s_f514aa0a_pDesc { DXGI_SWAP_CHAIN_DESC1* value; } _s_f514aa0a_pDesc;
typedef struct _s_f514aa0a_pRestrictToOutput { X12Output4* value; } _s_f514aa0a_pRestrictToOutput;
typedef struct _s_f514aa0a_outpSwapChain { X12SwapChain3** value; } _s_f514aa0a_outpSwapChain;
typedef struct _s_f514aa0a_optionalFile { char* value; } _s_f514aa0a_optionalFile;
typedef struct _s_f514aa0a_optionalLine { int value; } _s_f514aa0a_optionalLine;
static inline _s_f514aa0a_pFactory _f514aa0a_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_f514aa0a_pFactory){value}; }
static inline _s_f514aa0a_pCommandQueue _f514aa0a_pCommandQueue(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_f514aa0a_pCommandQueue){value}; }
static inline _s_f514aa0a_pDesc _f514aa0a_pDesc(DXGI_SWAP_CHAIN_DESC1* value) { return REDGPU_NP_STRUCT_INIT(_s_f514aa0a_pDesc){value}; }
static inline _s_f514aa0a_pRestrictToOutput _f514aa0a_pRestrictToOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_f514aa0a_pRestrictToOutput){value}; }
static inline _s_f514aa0a_outpSwapChain _f514aa0a_outpSwapChain(X12SwapChain3** value) { return REDGPU_NP_STRUCT_INIT(_s_f514aa0a_outpSwapChain){value}; }
static inline _s_f514aa0a_optionalFile _f514aa0a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f514aa0a_optionalFile){value}; }
static inline _s_f514aa0a_optionalLine _f514aa0a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f514aa0a_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryCreateSwapChainForComposition(_s_f514aa0a_pFactory pFactory, _s_f514aa0a_pCommandQueue pCommandQueue, _s_f514aa0a_pDesc pDesc, _s_f514aa0a_pRestrictToOutput pRestrictToOutput, _s_f514aa0a_outpSwapChain outpSwapChain, _s_f514aa0a_optionalFile optionalFile, _s_f514aa0a_optionalLine optionalLine) {
  return x12FactoryCreateSwapChainForComposition(pFactory.value, pCommandQueue.value, pDesc.value, pRestrictToOutput.value, outpSwapChain.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryMakeWindowAssociation x12FactoryMakeWindowAssociation
#define _93229b36_pFactory(value) value
#define _93229b36_WindowHandle(value) value
#define _93229b36_Flags(value) value
#define _93229b36_optionalFile(value) value
#define _93229b36_optionalLine(value) value
#else
typedef struct _s_93229b36_pFactory { X12Factory4* value; } _s_93229b36_pFactory;
typedef struct _s_93229b36_WindowHandle { void* value; } _s_93229b36_WindowHandle;
typedef struct _s_93229b36_Flags { DXGI_MWA_FLAGS value; } _s_93229b36_Flags;
typedef struct _s_93229b36_optionalFile { char* value; } _s_93229b36_optionalFile;
typedef struct _s_93229b36_optionalLine { int value; } _s_93229b36_optionalLine;
static inline _s_93229b36_pFactory _93229b36_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_93229b36_pFactory){value}; }
static inline _s_93229b36_WindowHandle _93229b36_WindowHandle(void* value) { return REDGPU_NP_STRUCT_INIT(_s_93229b36_WindowHandle){value}; }
static inline _s_93229b36_Flags _93229b36_Flags(DXGI_MWA_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_93229b36_Flags){value}; }
static inline _s_93229b36_optionalFile _93229b36_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_93229b36_optionalFile){value}; }
static inline _s_93229b36_optionalLine _93229b36_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_93229b36_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryMakeWindowAssociation(_s_93229b36_pFactory pFactory, _s_93229b36_WindowHandle WindowHandle, _s_93229b36_Flags Flags, _s_93229b36_optionalFile optionalFile, _s_93229b36_optionalLine optionalLine) {
  return x12FactoryMakeWindowAssociation(pFactory.value, WindowHandle.value, Flags.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryGetWindowAssociation x12FactoryGetWindowAssociation
#define _cb86fe2e_pFactory(value) value
#define _cb86fe2e_outWindowHandle(value) value
#define _cb86fe2e_optionalFile(value) value
#define _cb86fe2e_optionalLine(value) value
#else
typedef struct _s_cb86fe2e_pFactory { X12Factory4* value; } _s_cb86fe2e_pFactory;
typedef struct _s_cb86fe2e_outWindowHandle { void** value; } _s_cb86fe2e_outWindowHandle;
typedef struct _s_cb86fe2e_optionalFile { char* value; } _s_cb86fe2e_optionalFile;
typedef struct _s_cb86fe2e_optionalLine { int value; } _s_cb86fe2e_optionalLine;
static inline _s_cb86fe2e_pFactory _cb86fe2e_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_cb86fe2e_pFactory){value}; }
static inline _s_cb86fe2e_outWindowHandle _cb86fe2e_outWindowHandle(void** value) { return REDGPU_NP_STRUCT_INIT(_s_cb86fe2e_outWindowHandle){value}; }
static inline _s_cb86fe2e_optionalFile _cb86fe2e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cb86fe2e_optionalFile){value}; }
static inline _s_cb86fe2e_optionalLine _cb86fe2e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cb86fe2e_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryGetWindowAssociation(_s_cb86fe2e_pFactory pFactory, _s_cb86fe2e_outWindowHandle outWindowHandle, _s_cb86fe2e_optionalFile optionalFile, _s_cb86fe2e_optionalLine optionalLine) {
  return x12FactoryGetWindowAssociation(pFactory.value, outWindowHandle.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryRegisterOcclusionStatusWindow x12FactoryRegisterOcclusionStatusWindow
#define _b24cf22c_pFactory(value) value
#define _b24cf22c_WindowHandle(value) value
#define _b24cf22c_wMsg(value) value
#define _b24cf22c_pdwCookie(value) value
#define _b24cf22c_optionalFile(value) value
#define _b24cf22c_optionalLine(value) value
#else
typedef struct _s_b24cf22c_pFactory { X12Factory4* value; } _s_b24cf22c_pFactory;
typedef struct _s_b24cf22c_WindowHandle { void* value; } _s_b24cf22c_WindowHandle;
typedef struct _s_b24cf22c_wMsg { unsigned value; } _s_b24cf22c_wMsg;
typedef struct _s_b24cf22c_pdwCookie { unsigned* value; } _s_b24cf22c_pdwCookie;
typedef struct _s_b24cf22c_optionalFile { char* value; } _s_b24cf22c_optionalFile;
typedef struct _s_b24cf22c_optionalLine { int value; } _s_b24cf22c_optionalLine;
static inline _s_b24cf22c_pFactory _b24cf22c_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_b24cf22c_pFactory){value}; }
static inline _s_b24cf22c_WindowHandle _b24cf22c_WindowHandle(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b24cf22c_WindowHandle){value}; }
static inline _s_b24cf22c_wMsg _b24cf22c_wMsg(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b24cf22c_wMsg){value}; }
static inline _s_b24cf22c_pdwCookie _b24cf22c_pdwCookie(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_b24cf22c_pdwCookie){value}; }
static inline _s_b24cf22c_optionalFile _b24cf22c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b24cf22c_optionalFile){value}; }
static inline _s_b24cf22c_optionalLine _b24cf22c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b24cf22c_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryRegisterOcclusionStatusWindow(_s_b24cf22c_pFactory pFactory, _s_b24cf22c_WindowHandle WindowHandle, _s_b24cf22c_wMsg wMsg, _s_b24cf22c_pdwCookie pdwCookie, _s_b24cf22c_optionalFile optionalFile, _s_b24cf22c_optionalLine optionalLine) {
  return x12FactoryRegisterOcclusionStatusWindow(pFactory.value, WindowHandle.value, wMsg.value, pdwCookie.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryRegisterOcclusionStatusEvent x12FactoryRegisterOcclusionStatusEvent
#define _e2a75b7c_pFactory(value) value
#define _e2a75b7c_hEvent(value) value
#define _e2a75b7c_pdwCookie(value) value
#define _e2a75b7c_optionalFile(value) value
#define _e2a75b7c_optionalLine(value) value
#else
typedef struct _s_e2a75b7c_pFactory { X12Factory4* value; } _s_e2a75b7c_pFactory;
typedef struct _s_e2a75b7c_hEvent { void* value; } _s_e2a75b7c_hEvent;
typedef struct _s_e2a75b7c_pdwCookie { unsigned* value; } _s_e2a75b7c_pdwCookie;
typedef struct _s_e2a75b7c_optionalFile { char* value; } _s_e2a75b7c_optionalFile;
typedef struct _s_e2a75b7c_optionalLine { int value; } _s_e2a75b7c_optionalLine;
static inline _s_e2a75b7c_pFactory _e2a75b7c_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_e2a75b7c_pFactory){value}; }
static inline _s_e2a75b7c_hEvent _e2a75b7c_hEvent(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e2a75b7c_hEvent){value}; }
static inline _s_e2a75b7c_pdwCookie _e2a75b7c_pdwCookie(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_e2a75b7c_pdwCookie){value}; }
static inline _s_e2a75b7c_optionalFile _e2a75b7c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e2a75b7c_optionalFile){value}; }
static inline _s_e2a75b7c_optionalLine _e2a75b7c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e2a75b7c_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12FactoryRegisterOcclusionStatusEvent(_s_e2a75b7c_pFactory pFactory, _s_e2a75b7c_hEvent hEvent, _s_e2a75b7c_pdwCookie pdwCookie, _s_e2a75b7c_optionalFile optionalFile, _s_e2a75b7c_optionalLine optionalLine) {
  return x12FactoryRegisterOcclusionStatusEvent(pFactory.value, hEvent.value, pdwCookie.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12FactoryUnregisterOcclusionStatus x12FactoryUnregisterOcclusionStatus
#define _083de0dd_pFactory(value) value
#define _083de0dd_dwCookie(value) value
#define _083de0dd_optionalFile(value) value
#define _083de0dd_optionalLine(value) value
#else
typedef struct _s_083de0dd_pFactory { X12Factory4* value; } _s_083de0dd_pFactory;
typedef struct _s_083de0dd_dwCookie { unsigned value; } _s_083de0dd_dwCookie;
typedef struct _s_083de0dd_optionalFile { char* value; } _s_083de0dd_optionalFile;
typedef struct _s_083de0dd_optionalLine { int value; } _s_083de0dd_optionalLine;
static inline _s_083de0dd_pFactory _083de0dd_pFactory(X12Factory4* value) { return REDGPU_NP_STRUCT_INIT(_s_083de0dd_pFactory){value}; }
static inline _s_083de0dd_dwCookie _083de0dd_dwCookie(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_083de0dd_dwCookie){value}; }
static inline _s_083de0dd_optionalFile _083de0dd_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_083de0dd_optionalFile){value}; }
static inline _s_083de0dd_optionalLine _083de0dd_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_083de0dd_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12FactoryUnregisterOcclusionStatus(_s_083de0dd_pFactory pFactory, _s_083de0dd_dwCookie dwCookie, _s_083de0dd_optionalFile optionalFile, _s_083de0dd_optionalLine optionalLine) {
  x12FactoryUnregisterOcclusionStatus(pFactory.value, dwCookie.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetBuffer x12SwapChainGetBuffer
#define _24c8bb34_pSwapChain(value) value
#define _24c8bb34_Buffer(value) value
#define _24c8bb34_outpSurface(value) value
#define _24c8bb34_optionalFile(value) value
#define _24c8bb34_optionalLine(value) value
#else
typedef struct _s_24c8bb34_pSwapChain { X12SwapChain3* value; } _s_24c8bb34_pSwapChain;
typedef struct _s_24c8bb34_Buffer { unsigned value; } _s_24c8bb34_Buffer;
typedef struct _s_24c8bb34_outpSurface { X12Resource** value; } _s_24c8bb34_outpSurface;
typedef struct _s_24c8bb34_optionalFile { char* value; } _s_24c8bb34_optionalFile;
typedef struct _s_24c8bb34_optionalLine { int value; } _s_24c8bb34_optionalLine;
static inline _s_24c8bb34_pSwapChain _24c8bb34_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_24c8bb34_pSwapChain){value}; }
static inline _s_24c8bb34_Buffer _24c8bb34_Buffer(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_24c8bb34_Buffer){value}; }
static inline _s_24c8bb34_outpSurface _24c8bb34_outpSurface(X12Resource** value) { return REDGPU_NP_STRUCT_INIT(_s_24c8bb34_outpSurface){value}; }
static inline _s_24c8bb34_optionalFile _24c8bb34_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_24c8bb34_optionalFile){value}; }
static inline _s_24c8bb34_optionalLine _24c8bb34_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_24c8bb34_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetBuffer(_s_24c8bb34_pSwapChain pSwapChain, _s_24c8bb34_Buffer Buffer, _s_24c8bb34_outpSurface outpSurface, _s_24c8bb34_optionalFile optionalFile, _s_24c8bb34_optionalLine optionalLine) {
  return x12SwapChainGetBuffer(pSwapChain.value, Buffer.value, outpSurface.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetCurrentBackBufferIndex x12SwapChainGetCurrentBackBufferIndex
#define _6d572da9_pSwapChain(value) value
#define _6d572da9_optionalFile(value) value
#define _6d572da9_optionalLine(value) value
#else
typedef struct _s_6d572da9_pSwapChain { X12SwapChain3* value; } _s_6d572da9_pSwapChain;
typedef struct _s_6d572da9_optionalFile { char* value; } _s_6d572da9_optionalFile;
typedef struct _s_6d572da9_optionalLine { int value; } _s_6d572da9_optionalLine;
static inline _s_6d572da9_pSwapChain _6d572da9_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_6d572da9_pSwapChain){value}; }
static inline _s_6d572da9_optionalFile _6d572da9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6d572da9_optionalFile){value}; }
static inline _s_6d572da9_optionalLine _6d572da9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6d572da9_optionalLine){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_x12SwapChainGetCurrentBackBufferIndex(_s_6d572da9_pSwapChain pSwapChain, _s_6d572da9_optionalFile optionalFile, _s_6d572da9_optionalLine optionalLine) {
  return x12SwapChainGetCurrentBackBufferIndex(pSwapChain.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainPresent1 x12SwapChainPresent1
#define _4a3bd7a8_pSwapChain(value) value
#define _4a3bd7a8_SyncInterval(value) value
#define _4a3bd7a8_PresentFlags(value) value
#define _4a3bd7a8_pPresentParameters(value) value
#define _4a3bd7a8_optionalFile(value) value
#define _4a3bd7a8_optionalLine(value) value
#else
typedef struct _s_4a3bd7a8_pSwapChain { X12SwapChain3* value; } _s_4a3bd7a8_pSwapChain;
typedef struct _s_4a3bd7a8_SyncInterval { unsigned value; } _s_4a3bd7a8_SyncInterval;
typedef struct _s_4a3bd7a8_PresentFlags { DXGI_PRESENT_FLAGS value; } _s_4a3bd7a8_PresentFlags;
typedef struct _s_4a3bd7a8_pPresentParameters { DXGI_PRESENT_PARAMETERS* value; } _s_4a3bd7a8_pPresentParameters;
typedef struct _s_4a3bd7a8_optionalFile { char* value; } _s_4a3bd7a8_optionalFile;
typedef struct _s_4a3bd7a8_optionalLine { int value; } _s_4a3bd7a8_optionalLine;
static inline _s_4a3bd7a8_pSwapChain _4a3bd7a8_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_4a3bd7a8_pSwapChain){value}; }
static inline _s_4a3bd7a8_SyncInterval _4a3bd7a8_SyncInterval(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_4a3bd7a8_SyncInterval){value}; }
static inline _s_4a3bd7a8_PresentFlags _4a3bd7a8_PresentFlags(DXGI_PRESENT_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_4a3bd7a8_PresentFlags){value}; }
static inline _s_4a3bd7a8_pPresentParameters _4a3bd7a8_pPresentParameters(DXGI_PRESENT_PARAMETERS* value) { return REDGPU_NP_STRUCT_INIT(_s_4a3bd7a8_pPresentParameters){value}; }
static inline _s_4a3bd7a8_optionalFile _4a3bd7a8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4a3bd7a8_optionalFile){value}; }
static inline _s_4a3bd7a8_optionalLine _4a3bd7a8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4a3bd7a8_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainPresent1(_s_4a3bd7a8_pSwapChain pSwapChain, _s_4a3bd7a8_SyncInterval SyncInterval, _s_4a3bd7a8_PresentFlags PresentFlags, _s_4a3bd7a8_pPresentParameters pPresentParameters, _s_4a3bd7a8_optionalFile optionalFile, _s_4a3bd7a8_optionalLine optionalLine) {
  return x12SwapChainPresent1(pSwapChain.value, SyncInterval.value, PresentFlags.value, pPresentParameters.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainResizeTarget x12SwapChainResizeTarget
#define _9aeb92e1_pSwapChain(value) value
#define _9aeb92e1_pNewTargetParameters(value) value
#define _9aeb92e1_optionalFile(value) value
#define _9aeb92e1_optionalLine(value) value
#else
typedef struct _s_9aeb92e1_pSwapChain { X12SwapChain3* value; } _s_9aeb92e1_pSwapChain;
typedef struct _s_9aeb92e1_pNewTargetParameters { DXGI_MODE_DESC* value; } _s_9aeb92e1_pNewTargetParameters;
typedef struct _s_9aeb92e1_optionalFile { char* value; } _s_9aeb92e1_optionalFile;
typedef struct _s_9aeb92e1_optionalLine { int value; } _s_9aeb92e1_optionalLine;
static inline _s_9aeb92e1_pSwapChain _9aeb92e1_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_9aeb92e1_pSwapChain){value}; }
static inline _s_9aeb92e1_pNewTargetParameters _9aeb92e1_pNewTargetParameters(DXGI_MODE_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_9aeb92e1_pNewTargetParameters){value}; }
static inline _s_9aeb92e1_optionalFile _9aeb92e1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9aeb92e1_optionalFile){value}; }
static inline _s_9aeb92e1_optionalLine _9aeb92e1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9aeb92e1_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainResizeTarget(_s_9aeb92e1_pSwapChain pSwapChain, _s_9aeb92e1_pNewTargetParameters pNewTargetParameters, _s_9aeb92e1_optionalFile optionalFile, _s_9aeb92e1_optionalLine optionalLine) {
  return x12SwapChainResizeTarget(pSwapChain.value, pNewTargetParameters.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainResizeBuffers1 x12SwapChainResizeBuffers1
#define _3d307839_pSwapChain(value) value
#define _3d307839_BufferCount(value) value
#define _3d307839_Width(value) value
#define _3d307839_Height(value) value
#define _3d307839_Format(value) value
#define _3d307839_SwapChainFlags(value) value
#define _3d307839_pCreationNodeMask(value) value
#define _3d307839_ppPresentQueue(value) value
#define _3d307839_optionalFile(value) value
#define _3d307839_optionalLine(value) value
#else
typedef struct _s_3d307839_pSwapChain { X12SwapChain3* value; } _s_3d307839_pSwapChain;
typedef struct _s_3d307839_BufferCount { unsigned value; } _s_3d307839_BufferCount;
typedef struct _s_3d307839_Width { unsigned value; } _s_3d307839_Width;
typedef struct _s_3d307839_Height { unsigned value; } _s_3d307839_Height;
typedef struct _s_3d307839_Format { DXGI_FORMAT value; } _s_3d307839_Format;
typedef struct _s_3d307839_SwapChainFlags { unsigned value; } _s_3d307839_SwapChainFlags;
typedef struct _s_3d307839_pCreationNodeMask { unsigned* value; } _s_3d307839_pCreationNodeMask;
typedef struct _s_3d307839_ppPresentQueue { X12CommandQueue** value; } _s_3d307839_ppPresentQueue;
typedef struct _s_3d307839_optionalFile { char* value; } _s_3d307839_optionalFile;
typedef struct _s_3d307839_optionalLine { int value; } _s_3d307839_optionalLine;
static inline _s_3d307839_pSwapChain _3d307839_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_3d307839_pSwapChain){value}; }
static inline _s_3d307839_BufferCount _3d307839_BufferCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3d307839_BufferCount){value}; }
static inline _s_3d307839_Width _3d307839_Width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3d307839_Width){value}; }
static inline _s_3d307839_Height _3d307839_Height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3d307839_Height){value}; }
static inline _s_3d307839_Format _3d307839_Format(DXGI_FORMAT value) { return REDGPU_NP_STRUCT_INIT(_s_3d307839_Format){value}; }
static inline _s_3d307839_SwapChainFlags _3d307839_SwapChainFlags(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3d307839_SwapChainFlags){value}; }
static inline _s_3d307839_pCreationNodeMask _3d307839_pCreationNodeMask(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_3d307839_pCreationNodeMask){value}; }
static inline _s_3d307839_ppPresentQueue _3d307839_ppPresentQueue(X12CommandQueue** value) { return REDGPU_NP_STRUCT_INIT(_s_3d307839_ppPresentQueue){value}; }
static inline _s_3d307839_optionalFile _3d307839_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3d307839_optionalFile){value}; }
static inline _s_3d307839_optionalLine _3d307839_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3d307839_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainResizeBuffers1(_s_3d307839_pSwapChain pSwapChain, _s_3d307839_BufferCount BufferCount, _s_3d307839_Width Width, _s_3d307839_Height Height, _s_3d307839_Format Format, _s_3d307839_SwapChainFlags SwapChainFlags, _s_3d307839_pCreationNodeMask pCreationNodeMask, _s_3d307839_ppPresentQueue ppPresentQueue, _s_3d307839_optionalFile optionalFile, _s_3d307839_optionalLine optionalLine) {
  return x12SwapChainResizeBuffers1(pSwapChain.value, BufferCount.value, Width.value, Height.value, Format.value, SwapChainFlags.value, pCreationNodeMask.value, ppPresentQueue.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetFullscreenState x12SwapChainSetFullscreenState
#define _683af9d6_pSwapChain(value) value
#define _683af9d6_Fullscreen(value) value
#define _683af9d6_pTarget(value) value
#define _683af9d6_optionalFile(value) value
#define _683af9d6_optionalLine(value) value
#else
typedef struct _s_683af9d6_pSwapChain { X12SwapChain3* value; } _s_683af9d6_pSwapChain;
typedef struct _s_683af9d6_Fullscreen { X12Bool value; } _s_683af9d6_Fullscreen;
typedef struct _s_683af9d6_pTarget { X12Output4* value; } _s_683af9d6_pTarget;
typedef struct _s_683af9d6_optionalFile { char* value; } _s_683af9d6_optionalFile;
typedef struct _s_683af9d6_optionalLine { int value; } _s_683af9d6_optionalLine;
static inline _s_683af9d6_pSwapChain _683af9d6_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_683af9d6_pSwapChain){value}; }
static inline _s_683af9d6_Fullscreen _683af9d6_Fullscreen(X12Bool value) { return REDGPU_NP_STRUCT_INIT(_s_683af9d6_Fullscreen){value}; }
static inline _s_683af9d6_pTarget _683af9d6_pTarget(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_683af9d6_pTarget){value}; }
static inline _s_683af9d6_optionalFile _683af9d6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_683af9d6_optionalFile){value}; }
static inline _s_683af9d6_optionalLine _683af9d6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_683af9d6_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetFullscreenState(_s_683af9d6_pSwapChain pSwapChain, _s_683af9d6_Fullscreen Fullscreen, _s_683af9d6_pTarget pTarget, _s_683af9d6_optionalFile optionalFile, _s_683af9d6_optionalLine optionalLine) {
  return x12SwapChainSetFullscreenState(pSwapChain.value, Fullscreen.value, pTarget.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetFullscreenDesc x12SwapChainGetFullscreenDesc
#define _a5398727_pSwapChain(value) value
#define _a5398727_outDesc(value) value
#define _a5398727_optionalFile(value) value
#define _a5398727_optionalLine(value) value
#else
typedef struct _s_a5398727_pSwapChain { X12SwapChain3* value; } _s_a5398727_pSwapChain;
typedef struct _s_a5398727_outDesc { DXGI_SWAP_CHAIN_FULLSCREEN_DESC* value; } _s_a5398727_outDesc;
typedef struct _s_a5398727_optionalFile { char* value; } _s_a5398727_optionalFile;
typedef struct _s_a5398727_optionalLine { int value; } _s_a5398727_optionalLine;
static inline _s_a5398727_pSwapChain _a5398727_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_a5398727_pSwapChain){value}; }
static inline _s_a5398727_outDesc _a5398727_outDesc(DXGI_SWAP_CHAIN_FULLSCREEN_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_a5398727_outDesc){value}; }
static inline _s_a5398727_optionalFile _a5398727_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a5398727_optionalFile){value}; }
static inline _s_a5398727_optionalLine _a5398727_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a5398727_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetFullscreenDesc(_s_a5398727_pSwapChain pSwapChain, _s_a5398727_outDesc outDesc, _s_a5398727_optionalFile optionalFile, _s_a5398727_optionalLine optionalLine) {
  return x12SwapChainGetFullscreenDesc(pSwapChain.value, outDesc.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetLastPresentCount x12SwapChainGetLastPresentCount
#define _a1a41ad9_pSwapChain(value) value
#define _a1a41ad9_outLastPresentCount(value) value
#define _a1a41ad9_optionalFile(value) value
#define _a1a41ad9_optionalLine(value) value
#else
typedef struct _s_a1a41ad9_pSwapChain { X12SwapChain3* value; } _s_a1a41ad9_pSwapChain;
typedef struct _s_a1a41ad9_outLastPresentCount { unsigned* value; } _s_a1a41ad9_outLastPresentCount;
typedef struct _s_a1a41ad9_optionalFile { char* value; } _s_a1a41ad9_optionalFile;
typedef struct _s_a1a41ad9_optionalLine { int value; } _s_a1a41ad9_optionalLine;
static inline _s_a1a41ad9_pSwapChain _a1a41ad9_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_a1a41ad9_pSwapChain){value}; }
static inline _s_a1a41ad9_outLastPresentCount _a1a41ad9_outLastPresentCount(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_a1a41ad9_outLastPresentCount){value}; }
static inline _s_a1a41ad9_optionalFile _a1a41ad9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a1a41ad9_optionalFile){value}; }
static inline _s_a1a41ad9_optionalLine _a1a41ad9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a1a41ad9_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetLastPresentCount(_s_a1a41ad9_pSwapChain pSwapChain, _s_a1a41ad9_outLastPresentCount outLastPresentCount, _s_a1a41ad9_optionalFile optionalFile, _s_a1a41ad9_optionalLine optionalLine) {
  return x12SwapChainGetLastPresentCount(pSwapChain.value, outLastPresentCount.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetFrameStatistics x12SwapChainGetFrameStatistics
#define _6c66cdd3_pSwapChain(value) value
#define _6c66cdd3_outStats(value) value
#define _6c66cdd3_optionalFile(value) value
#define _6c66cdd3_optionalLine(value) value
#else
typedef struct _s_6c66cdd3_pSwapChain { X12SwapChain3* value; } _s_6c66cdd3_pSwapChain;
typedef struct _s_6c66cdd3_outStats { DXGI_FRAME_STATISTICS* value; } _s_6c66cdd3_outStats;
typedef struct _s_6c66cdd3_optionalFile { char* value; } _s_6c66cdd3_optionalFile;
typedef struct _s_6c66cdd3_optionalLine { int value; } _s_6c66cdd3_optionalLine;
static inline _s_6c66cdd3_pSwapChain _6c66cdd3_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_6c66cdd3_pSwapChain){value}; }
static inline _s_6c66cdd3_outStats _6c66cdd3_outStats(DXGI_FRAME_STATISTICS* value) { return REDGPU_NP_STRUCT_INIT(_s_6c66cdd3_outStats){value}; }
static inline _s_6c66cdd3_optionalFile _6c66cdd3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6c66cdd3_optionalFile){value}; }
static inline _s_6c66cdd3_optionalLine _6c66cdd3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6c66cdd3_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetFrameStatistics(_s_6c66cdd3_pSwapChain pSwapChain, _s_6c66cdd3_outStats outStats, _s_6c66cdd3_optionalFile optionalFile, _s_6c66cdd3_optionalLine optionalLine) {
  return x12SwapChainGetFrameStatistics(pSwapChain.value, outStats.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetBackgroundColor x12SwapChainSetBackgroundColor
#define _2c8cdf3c_pSwapChain(value) value
#define _2c8cdf3c_pColor(value) value
#define _2c8cdf3c_optionalFile(value) value
#define _2c8cdf3c_optionalLine(value) value
#else
typedef struct _s_2c8cdf3c_pSwapChain { X12SwapChain3* value; } _s_2c8cdf3c_pSwapChain;
typedef struct _s_2c8cdf3c_pColor { DXGI_RGBA* value; } _s_2c8cdf3c_pColor;
typedef struct _s_2c8cdf3c_optionalFile { char* value; } _s_2c8cdf3c_optionalFile;
typedef struct _s_2c8cdf3c_optionalLine { int value; } _s_2c8cdf3c_optionalLine;
static inline _s_2c8cdf3c_pSwapChain _2c8cdf3c_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_2c8cdf3c_pSwapChain){value}; }
static inline _s_2c8cdf3c_pColor _2c8cdf3c_pColor(DXGI_RGBA* value) { return REDGPU_NP_STRUCT_INIT(_s_2c8cdf3c_pColor){value}; }
static inline _s_2c8cdf3c_optionalFile _2c8cdf3c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2c8cdf3c_optionalFile){value}; }
static inline _s_2c8cdf3c_optionalLine _2c8cdf3c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2c8cdf3c_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetBackgroundColor(_s_2c8cdf3c_pSwapChain pSwapChain, _s_2c8cdf3c_pColor pColor, _s_2c8cdf3c_optionalFile optionalFile, _s_2c8cdf3c_optionalLine optionalLine) {
  return x12SwapChainSetBackgroundColor(pSwapChain.value, pColor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetBackgroundColor x12SwapChainGetBackgroundColor
#define _6b38037f_pSwapChain(value) value
#define _6b38037f_outColor(value) value
#define _6b38037f_optionalFile(value) value
#define _6b38037f_optionalLine(value) value
#else
typedef struct _s_6b38037f_pSwapChain { X12SwapChain3* value; } _s_6b38037f_pSwapChain;
typedef struct _s_6b38037f_outColor { DXGI_RGBA* value; } _s_6b38037f_outColor;
typedef struct _s_6b38037f_optionalFile { char* value; } _s_6b38037f_optionalFile;
typedef struct _s_6b38037f_optionalLine { int value; } _s_6b38037f_optionalLine;
static inline _s_6b38037f_pSwapChain _6b38037f_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_6b38037f_pSwapChain){value}; }
static inline _s_6b38037f_outColor _6b38037f_outColor(DXGI_RGBA* value) { return REDGPU_NP_STRUCT_INIT(_s_6b38037f_outColor){value}; }
static inline _s_6b38037f_optionalFile _6b38037f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6b38037f_optionalFile){value}; }
static inline _s_6b38037f_optionalLine _6b38037f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6b38037f_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetBackgroundColor(_s_6b38037f_pSwapChain pSwapChain, _s_6b38037f_outColor outColor, _s_6b38037f_optionalFile optionalFile, _s_6b38037f_optionalLine optionalLine) {
  return x12SwapChainGetBackgroundColor(pSwapChain.value, outColor.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetRotation x12SwapChainSetRotation
#define _c401013e_pSwapChain(value) value
#define _c401013e_Rotation(value) value
#define _c401013e_optionalFile(value) value
#define _c401013e_optionalLine(value) value
#else
typedef struct _s_c401013e_pSwapChain { X12SwapChain3* value; } _s_c401013e_pSwapChain;
typedef struct _s_c401013e_Rotation { DXGI_MODE_ROTATION value; } _s_c401013e_Rotation;
typedef struct _s_c401013e_optionalFile { char* value; } _s_c401013e_optionalFile;
typedef struct _s_c401013e_optionalLine { int value; } _s_c401013e_optionalLine;
static inline _s_c401013e_pSwapChain _c401013e_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_c401013e_pSwapChain){value}; }
static inline _s_c401013e_Rotation _c401013e_Rotation(DXGI_MODE_ROTATION value) { return REDGPU_NP_STRUCT_INIT(_s_c401013e_Rotation){value}; }
static inline _s_c401013e_optionalFile _c401013e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c401013e_optionalFile){value}; }
static inline _s_c401013e_optionalLine _c401013e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c401013e_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetRotation(_s_c401013e_pSwapChain pSwapChain, _s_c401013e_Rotation Rotation, _s_c401013e_optionalFile optionalFile, _s_c401013e_optionalLine optionalLine) {
  return x12SwapChainSetRotation(pSwapChain.value, Rotation.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetRotation x12SwapChainGetRotation
#define _5ad0027c_pSwapChain(value) value
#define _5ad0027c_outRotation(value) value
#define _5ad0027c_optionalFile(value) value
#define _5ad0027c_optionalLine(value) value
#else
typedef struct _s_5ad0027c_pSwapChain { X12SwapChain3* value; } _s_5ad0027c_pSwapChain;
typedef struct _s_5ad0027c_outRotation { DXGI_MODE_ROTATION* value; } _s_5ad0027c_outRotation;
typedef struct _s_5ad0027c_optionalFile { char* value; } _s_5ad0027c_optionalFile;
typedef struct _s_5ad0027c_optionalLine { int value; } _s_5ad0027c_optionalLine;
static inline _s_5ad0027c_pSwapChain _5ad0027c_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_5ad0027c_pSwapChain){value}; }
static inline _s_5ad0027c_outRotation _5ad0027c_outRotation(DXGI_MODE_ROTATION* value) { return REDGPU_NP_STRUCT_INIT(_s_5ad0027c_outRotation){value}; }
static inline _s_5ad0027c_optionalFile _5ad0027c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5ad0027c_optionalFile){value}; }
static inline _s_5ad0027c_optionalLine _5ad0027c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5ad0027c_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetRotation(_s_5ad0027c_pSwapChain pSwapChain, _s_5ad0027c_outRotation outRotation, _s_5ad0027c_optionalFile optionalFile, _s_5ad0027c_optionalLine optionalLine) {
  return x12SwapChainGetRotation(pSwapChain.value, outRotation.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetSourceSize x12SwapChainSetSourceSize
#define _41956731_pSwapChain(value) value
#define _41956731_Width(value) value
#define _41956731_Height(value) value
#define _41956731_optionalFile(value) value
#define _41956731_optionalLine(value) value
#else
typedef struct _s_41956731_pSwapChain { X12SwapChain3* value; } _s_41956731_pSwapChain;
typedef struct _s_41956731_Width { unsigned value; } _s_41956731_Width;
typedef struct _s_41956731_Height { unsigned value; } _s_41956731_Height;
typedef struct _s_41956731_optionalFile { char* value; } _s_41956731_optionalFile;
typedef struct _s_41956731_optionalLine { int value; } _s_41956731_optionalLine;
static inline _s_41956731_pSwapChain _41956731_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_41956731_pSwapChain){value}; }
static inline _s_41956731_Width _41956731_Width(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_41956731_Width){value}; }
static inline _s_41956731_Height _41956731_Height(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_41956731_Height){value}; }
static inline _s_41956731_optionalFile _41956731_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_41956731_optionalFile){value}; }
static inline _s_41956731_optionalLine _41956731_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_41956731_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetSourceSize(_s_41956731_pSwapChain pSwapChain, _s_41956731_Width Width, _s_41956731_Height Height, _s_41956731_optionalFile optionalFile, _s_41956731_optionalLine optionalLine) {
  return x12SwapChainSetSourceSize(pSwapChain.value, Width.value, Height.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetSourceSize x12SwapChainGetSourceSize
#define _13a0b30a_pSwapChain(value) value
#define _13a0b30a_outWidth(value) value
#define _13a0b30a_outHeight(value) value
#define _13a0b30a_optionalFile(value) value
#define _13a0b30a_optionalLine(value) value
#else
typedef struct _s_13a0b30a_pSwapChain { X12SwapChain3* value; } _s_13a0b30a_pSwapChain;
typedef struct _s_13a0b30a_outWidth { unsigned* value; } _s_13a0b30a_outWidth;
typedef struct _s_13a0b30a_outHeight { unsigned* value; } _s_13a0b30a_outHeight;
typedef struct _s_13a0b30a_optionalFile { char* value; } _s_13a0b30a_optionalFile;
typedef struct _s_13a0b30a_optionalLine { int value; } _s_13a0b30a_optionalLine;
static inline _s_13a0b30a_pSwapChain _13a0b30a_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_13a0b30a_pSwapChain){value}; }
static inline _s_13a0b30a_outWidth _13a0b30a_outWidth(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_13a0b30a_outWidth){value}; }
static inline _s_13a0b30a_outHeight _13a0b30a_outHeight(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_13a0b30a_outHeight){value}; }
static inline _s_13a0b30a_optionalFile _13a0b30a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_13a0b30a_optionalFile){value}; }
static inline _s_13a0b30a_optionalLine _13a0b30a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_13a0b30a_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetSourceSize(_s_13a0b30a_pSwapChain pSwapChain, _s_13a0b30a_outWidth outWidth, _s_13a0b30a_outHeight outHeight, _s_13a0b30a_optionalFile optionalFile, _s_13a0b30a_optionalLine optionalLine) {
  return x12SwapChainGetSourceSize(pSwapChain.value, outWidth.value, outHeight.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetMaximumFrameLatency x12SwapChainSetMaximumFrameLatency
#define _8c89dd87_pSwapChain(value) value
#define _8c89dd87_MaxLatency(value) value
#define _8c89dd87_optionalFile(value) value
#define _8c89dd87_optionalLine(value) value
#else
typedef struct _s_8c89dd87_pSwapChain { X12SwapChain3* value; } _s_8c89dd87_pSwapChain;
typedef struct _s_8c89dd87_MaxLatency { unsigned value; } _s_8c89dd87_MaxLatency;
typedef struct _s_8c89dd87_optionalFile { char* value; } _s_8c89dd87_optionalFile;
typedef struct _s_8c89dd87_optionalLine { int value; } _s_8c89dd87_optionalLine;
static inline _s_8c89dd87_pSwapChain _8c89dd87_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_8c89dd87_pSwapChain){value}; }
static inline _s_8c89dd87_MaxLatency _8c89dd87_MaxLatency(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_8c89dd87_MaxLatency){value}; }
static inline _s_8c89dd87_optionalFile _8c89dd87_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8c89dd87_optionalFile){value}; }
static inline _s_8c89dd87_optionalLine _8c89dd87_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8c89dd87_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetMaximumFrameLatency(_s_8c89dd87_pSwapChain pSwapChain, _s_8c89dd87_MaxLatency MaxLatency, _s_8c89dd87_optionalFile optionalFile, _s_8c89dd87_optionalLine optionalLine) {
  return x12SwapChainSetMaximumFrameLatency(pSwapChain.value, MaxLatency.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetMaximumFrameLatency x12SwapChainGetMaximumFrameLatency
#define _7ff8df9b_pSwapChain(value) value
#define _7ff8df9b_outMaxLatency(value) value
#define _7ff8df9b_optionalFile(value) value
#define _7ff8df9b_optionalLine(value) value
#else
typedef struct _s_7ff8df9b_pSwapChain { X12SwapChain3* value; } _s_7ff8df9b_pSwapChain;
typedef struct _s_7ff8df9b_outMaxLatency { unsigned* value; } _s_7ff8df9b_outMaxLatency;
typedef struct _s_7ff8df9b_optionalFile { char* value; } _s_7ff8df9b_optionalFile;
typedef struct _s_7ff8df9b_optionalLine { int value; } _s_7ff8df9b_optionalLine;
static inline _s_7ff8df9b_pSwapChain _7ff8df9b_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_7ff8df9b_pSwapChain){value}; }
static inline _s_7ff8df9b_outMaxLatency _7ff8df9b_outMaxLatency(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_7ff8df9b_outMaxLatency){value}; }
static inline _s_7ff8df9b_optionalFile _7ff8df9b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7ff8df9b_optionalFile){value}; }
static inline _s_7ff8df9b_optionalLine _7ff8df9b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7ff8df9b_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetMaximumFrameLatency(_s_7ff8df9b_pSwapChain pSwapChain, _s_7ff8df9b_outMaxLatency outMaxLatency, _s_7ff8df9b_optionalFile optionalFile, _s_7ff8df9b_optionalLine optionalLine) {
  return x12SwapChainGetMaximumFrameLatency(pSwapChain.value, outMaxLatency.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetFrameLatencyWaitableObject x12SwapChainGetFrameLatencyWaitableObject
#define _3f1d196f_pSwapChain(value) value
#define _3f1d196f_optionalFile(value) value
#define _3f1d196f_optionalLine(value) value
#else
typedef struct _s_3f1d196f_pSwapChain { X12SwapChain3* value; } _s_3f1d196f_pSwapChain;
typedef struct _s_3f1d196f_optionalFile { char* value; } _s_3f1d196f_optionalFile;
typedef struct _s_3f1d196f_optionalLine { int value; } _s_3f1d196f_optionalLine;
static inline _s_3f1d196f_pSwapChain _3f1d196f_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_3f1d196f_pSwapChain){value}; }
static inline _s_3f1d196f_optionalFile _3f1d196f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3f1d196f_optionalFile){value}; }
static inline _s_3f1d196f_optionalLine _3f1d196f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3f1d196f_optionalLine){value}; }
REDGPU_NP_DECLSPEC void* REDGPU_NP_API np_x12SwapChainGetFrameLatencyWaitableObject(_s_3f1d196f_pSwapChain pSwapChain, _s_3f1d196f_optionalFile optionalFile, _s_3f1d196f_optionalLine optionalLine) {
  return x12SwapChainGetFrameLatencyWaitableObject(pSwapChain.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetMatrixTransform x12SwapChainSetMatrixTransform
#define _461a3f60_pSwapChain(value) value
#define _461a3f60_pMatrix(value) value
#define _461a3f60_optionalFile(value) value
#define _461a3f60_optionalLine(value) value
#else
typedef struct _s_461a3f60_pSwapChain { X12SwapChain3* value; } _s_461a3f60_pSwapChain;
typedef struct _s_461a3f60_pMatrix { DXGI_MATRIX_3X2_F* value; } _s_461a3f60_pMatrix;
typedef struct _s_461a3f60_optionalFile { char* value; } _s_461a3f60_optionalFile;
typedef struct _s_461a3f60_optionalLine { int value; } _s_461a3f60_optionalLine;
static inline _s_461a3f60_pSwapChain _461a3f60_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_461a3f60_pSwapChain){value}; }
static inline _s_461a3f60_pMatrix _461a3f60_pMatrix(DXGI_MATRIX_3X2_F* value) { return REDGPU_NP_STRUCT_INIT(_s_461a3f60_pMatrix){value}; }
static inline _s_461a3f60_optionalFile _461a3f60_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_461a3f60_optionalFile){value}; }
static inline _s_461a3f60_optionalLine _461a3f60_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_461a3f60_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetMatrixTransform(_s_461a3f60_pSwapChain pSwapChain, _s_461a3f60_pMatrix pMatrix, _s_461a3f60_optionalFile optionalFile, _s_461a3f60_optionalLine optionalLine) {
  return x12SwapChainSetMatrixTransform(pSwapChain.value, pMatrix.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainGetMatrixTransform x12SwapChainGetMatrixTransform
#define _4294063c_pSwapChain(value) value
#define _4294063c_outMatrix(value) value
#define _4294063c_optionalFile(value) value
#define _4294063c_optionalLine(value) value
#else
typedef struct _s_4294063c_pSwapChain { X12SwapChain3* value; } _s_4294063c_pSwapChain;
typedef struct _s_4294063c_outMatrix { DXGI_MATRIX_3X2_F* value; } _s_4294063c_outMatrix;
typedef struct _s_4294063c_optionalFile { char* value; } _s_4294063c_optionalFile;
typedef struct _s_4294063c_optionalLine { int value; } _s_4294063c_optionalLine;
static inline _s_4294063c_pSwapChain _4294063c_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_4294063c_pSwapChain){value}; }
static inline _s_4294063c_outMatrix _4294063c_outMatrix(DXGI_MATRIX_3X2_F* value) { return REDGPU_NP_STRUCT_INIT(_s_4294063c_outMatrix){value}; }
static inline _s_4294063c_optionalFile _4294063c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4294063c_optionalFile){value}; }
static inline _s_4294063c_optionalLine _4294063c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4294063c_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainGetMatrixTransform(_s_4294063c_pSwapChain pSwapChain, _s_4294063c_outMatrix outMatrix, _s_4294063c_optionalFile optionalFile, _s_4294063c_optionalLine optionalLine) {
  return x12SwapChainGetMatrixTransform(pSwapChain.value, outMatrix.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainCheckColorSpaceSupport x12SwapChainCheckColorSpaceSupport
#define _4256abc9_pSwapChain(value) value
#define _4256abc9_ColorSpace(value) value
#define _4256abc9_outColorSpaceSupport(value) value
#define _4256abc9_optionalFile(value) value
#define _4256abc9_optionalLine(value) value
#else
typedef struct _s_4256abc9_pSwapChain { X12SwapChain3* value; } _s_4256abc9_pSwapChain;
typedef struct _s_4256abc9_ColorSpace { DXGI_COLOR_SPACE_TYPE value; } _s_4256abc9_ColorSpace;
typedef struct _s_4256abc9_outColorSpaceSupport { DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAGS* value; } _s_4256abc9_outColorSpaceSupport;
typedef struct _s_4256abc9_optionalFile { char* value; } _s_4256abc9_optionalFile;
typedef struct _s_4256abc9_optionalLine { int value; } _s_4256abc9_optionalLine;
static inline _s_4256abc9_pSwapChain _4256abc9_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_4256abc9_pSwapChain){value}; }
static inline _s_4256abc9_ColorSpace _4256abc9_ColorSpace(DXGI_COLOR_SPACE_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_4256abc9_ColorSpace){value}; }
static inline _s_4256abc9_outColorSpaceSupport _4256abc9_outColorSpaceSupport(DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAGS* value) { return REDGPU_NP_STRUCT_INIT(_s_4256abc9_outColorSpaceSupport){value}; }
static inline _s_4256abc9_optionalFile _4256abc9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4256abc9_optionalFile){value}; }
static inline _s_4256abc9_optionalLine _4256abc9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4256abc9_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainCheckColorSpaceSupport(_s_4256abc9_pSwapChain pSwapChain, _s_4256abc9_ColorSpace ColorSpace, _s_4256abc9_outColorSpaceSupport outColorSpaceSupport, _s_4256abc9_optionalFile optionalFile, _s_4256abc9_optionalLine optionalLine) {
  return x12SwapChainCheckColorSpaceSupport(pSwapChain.value, ColorSpace.value, outColorSpaceSupport.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12SwapChainSetColorSpace1 x12SwapChainSetColorSpace1
#define _7d6d6d4e_pSwapChain(value) value
#define _7d6d6d4e_ColorSpace(value) value
#define _7d6d6d4e_optionalFile(value) value
#define _7d6d6d4e_optionalLine(value) value
#else
typedef struct _s_7d6d6d4e_pSwapChain { X12SwapChain3* value; } _s_7d6d6d4e_pSwapChain;
typedef struct _s_7d6d6d4e_ColorSpace { DXGI_COLOR_SPACE_TYPE value; } _s_7d6d6d4e_ColorSpace;
typedef struct _s_7d6d6d4e_optionalFile { char* value; } _s_7d6d6d4e_optionalFile;
typedef struct _s_7d6d6d4e_optionalLine { int value; } _s_7d6d6d4e_optionalLine;
static inline _s_7d6d6d4e_pSwapChain _7d6d6d4e_pSwapChain(X12SwapChain3* value) { return REDGPU_NP_STRUCT_INIT(_s_7d6d6d4e_pSwapChain){value}; }
static inline _s_7d6d6d4e_ColorSpace _7d6d6d4e_ColorSpace(DXGI_COLOR_SPACE_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_7d6d6d4e_ColorSpace){value}; }
static inline _s_7d6d6d4e_optionalFile _7d6d6d4e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7d6d6d4e_optionalFile){value}; }
static inline _s_7d6d6d4e_optionalLine _7d6d6d4e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7d6d6d4e_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12SwapChainSetColorSpace1(_s_7d6d6d4e_pSwapChain pSwapChain, _s_7d6d6d4e_ColorSpace ColorSpace, _s_7d6d6d4e_optionalFile optionalFile, _s_7d6d6d4e_optionalLine optionalLine) {
  return x12SwapChainSetColorSpace1(pSwapChain.value, ColorSpace.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputGetDesc x12OutputGetDesc
#define _5c0dfe07_pOutput(value) value
#define _5c0dfe07_outDesc(value) value
#define _5c0dfe07_optionalFile(value) value
#define _5c0dfe07_optionalLine(value) value
#else
typedef struct _s_5c0dfe07_pOutput { X12Output4* value; } _s_5c0dfe07_pOutput;
typedef struct _s_5c0dfe07_outDesc { DXGI_OUTPUT_DESC* value; } _s_5c0dfe07_outDesc;
typedef struct _s_5c0dfe07_optionalFile { char* value; } _s_5c0dfe07_optionalFile;
typedef struct _s_5c0dfe07_optionalLine { int value; } _s_5c0dfe07_optionalLine;
static inline _s_5c0dfe07_pOutput _5c0dfe07_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_5c0dfe07_pOutput){value}; }
static inline _s_5c0dfe07_outDesc _5c0dfe07_outDesc(DXGI_OUTPUT_DESC* value) { return REDGPU_NP_STRUCT_INIT(_s_5c0dfe07_outDesc){value}; }
static inline _s_5c0dfe07_optionalFile _5c0dfe07_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5c0dfe07_optionalFile){value}; }
static inline _s_5c0dfe07_optionalLine _5c0dfe07_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5c0dfe07_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputGetDesc(_s_5c0dfe07_pOutput pOutput, _s_5c0dfe07_outDesc outDesc, _s_5c0dfe07_optionalFile optionalFile, _s_5c0dfe07_optionalLine optionalLine) {
  return x12OutputGetDesc(pOutput.value, outDesc.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputGetDisplayModeList1 x12OutputGetDisplayModeList1
#define _abca16d6_pOutput(value) value
#define _abca16d6_EnumFormat(value) value
#define _abca16d6_Flags(value) value
#define _abca16d6_pNumModes(value) value
#define _abca16d6_outDesc(value) value
#define _abca16d6_optionalFile(value) value
#define _abca16d6_optionalLine(value) value
#else
typedef struct _s_abca16d6_pOutput { X12Output4* value; } _s_abca16d6_pOutput;
typedef struct _s_abca16d6_EnumFormat { DXGI_FORMAT value; } _s_abca16d6_EnumFormat;
typedef struct _s_abca16d6_Flags { DXGI_ENUM_MODES_FLAGS value; } _s_abca16d6_Flags;
typedef struct _s_abca16d6_pNumModes { unsigned* value; } _s_abca16d6_pNumModes;
typedef struct _s_abca16d6_outDesc { DXGI_MODE_DESC1* value; } _s_abca16d6_outDesc;
typedef struct _s_abca16d6_optionalFile { char* value; } _s_abca16d6_optionalFile;
typedef struct _s_abca16d6_optionalLine { int value; } _s_abca16d6_optionalLine;
static inline _s_abca16d6_pOutput _abca16d6_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_abca16d6_pOutput){value}; }
static inline _s_abca16d6_EnumFormat _abca16d6_EnumFormat(DXGI_FORMAT value) { return REDGPU_NP_STRUCT_INIT(_s_abca16d6_EnumFormat){value}; }
static inline _s_abca16d6_Flags _abca16d6_Flags(DXGI_ENUM_MODES_FLAGS value) { return REDGPU_NP_STRUCT_INIT(_s_abca16d6_Flags){value}; }
static inline _s_abca16d6_pNumModes _abca16d6_pNumModes(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_abca16d6_pNumModes){value}; }
static inline _s_abca16d6_outDesc _abca16d6_outDesc(DXGI_MODE_DESC1* value) { return REDGPU_NP_STRUCT_INIT(_s_abca16d6_outDesc){value}; }
static inline _s_abca16d6_optionalFile _abca16d6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_abca16d6_optionalFile){value}; }
static inline _s_abca16d6_optionalLine _abca16d6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_abca16d6_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputGetDisplayModeList1(_s_abca16d6_pOutput pOutput, _s_abca16d6_EnumFormat EnumFormat, _s_abca16d6_Flags Flags, _s_abca16d6_pNumModes pNumModes, _s_abca16d6_outDesc outDesc, _s_abca16d6_optionalFile optionalFile, _s_abca16d6_optionalLine optionalLine) {
  return x12OutputGetDisplayModeList1(pOutput.value, EnumFormat.value, Flags.value, pNumModes.value, outDesc.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputFindClosestMatchingMode1 x12OutputFindClosestMatchingMode1
#define _4d60e08d_pOutput(value) value
#define _4d60e08d_pModeToMatch(value) value
#define _4d60e08d_pClosestMatch(value) value
#define _4d60e08d_pConcernedDevice(value) value
#define _4d60e08d_optionalFile(value) value
#define _4d60e08d_optionalLine(value) value
#else
typedef struct _s_4d60e08d_pOutput { X12Output4* value; } _s_4d60e08d_pOutput;
typedef struct _s_4d60e08d_pModeToMatch { DXGI_MODE_DESC1* value; } _s_4d60e08d_pModeToMatch;
typedef struct _s_4d60e08d_pClosestMatch { DXGI_MODE_DESC1* value; } _s_4d60e08d_pClosestMatch;
typedef struct _s_4d60e08d_pConcernedDevice { X12Device3* value; } _s_4d60e08d_pConcernedDevice;
typedef struct _s_4d60e08d_optionalFile { char* value; } _s_4d60e08d_optionalFile;
typedef struct _s_4d60e08d_optionalLine { int value; } _s_4d60e08d_optionalLine;
static inline _s_4d60e08d_pOutput _4d60e08d_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_4d60e08d_pOutput){value}; }
static inline _s_4d60e08d_pModeToMatch _4d60e08d_pModeToMatch(DXGI_MODE_DESC1* value) { return REDGPU_NP_STRUCT_INIT(_s_4d60e08d_pModeToMatch){value}; }
static inline _s_4d60e08d_pClosestMatch _4d60e08d_pClosestMatch(DXGI_MODE_DESC1* value) { return REDGPU_NP_STRUCT_INIT(_s_4d60e08d_pClosestMatch){value}; }
static inline _s_4d60e08d_pConcernedDevice _4d60e08d_pConcernedDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_4d60e08d_pConcernedDevice){value}; }
static inline _s_4d60e08d_optionalFile _4d60e08d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4d60e08d_optionalFile){value}; }
static inline _s_4d60e08d_optionalLine _4d60e08d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4d60e08d_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputFindClosestMatchingMode1(_s_4d60e08d_pOutput pOutput, _s_4d60e08d_pModeToMatch pModeToMatch, _s_4d60e08d_pClosestMatch pClosestMatch, _s_4d60e08d_pConcernedDevice pConcernedDevice, _s_4d60e08d_optionalFile optionalFile, _s_4d60e08d_optionalLine optionalLine) {
  return x12OutputFindClosestMatchingMode1(pOutput.value, pModeToMatch.value, pClosestMatch.value, pConcernedDevice.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputWaitForVBlank x12OutputWaitForVBlank
#define _850cda34_pOutput(value) value
#define _850cda34_optionalFile(value) value
#define _850cda34_optionalLine(value) value
#else
typedef struct _s_850cda34_pOutput { X12Output4* value; } _s_850cda34_pOutput;
typedef struct _s_850cda34_optionalFile { char* value; } _s_850cda34_optionalFile;
typedef struct _s_850cda34_optionalLine { int value; } _s_850cda34_optionalLine;
static inline _s_850cda34_pOutput _850cda34_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_850cda34_pOutput){value}; }
static inline _s_850cda34_optionalFile _850cda34_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_850cda34_optionalFile){value}; }
static inline _s_850cda34_optionalLine _850cda34_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_850cda34_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputWaitForVBlank(_s_850cda34_pOutput pOutput, _s_850cda34_optionalFile optionalFile, _s_850cda34_optionalLine optionalLine) {
  return x12OutputWaitForVBlank(pOutput.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputGetGammaControlCapabilities x12OutputGetGammaControlCapabilities
#define _ede16979_pOutput(value) value
#define _ede16979_outGammaCaps(value) value
#define _ede16979_optionalFile(value) value
#define _ede16979_optionalLine(value) value
#else
typedef struct _s_ede16979_pOutput { X12Output4* value; } _s_ede16979_pOutput;
typedef struct _s_ede16979_outGammaCaps { DXGI_GAMMA_CONTROL_CAPABILITIES* value; } _s_ede16979_outGammaCaps;
typedef struct _s_ede16979_optionalFile { char* value; } _s_ede16979_optionalFile;
typedef struct _s_ede16979_optionalLine { int value; } _s_ede16979_optionalLine;
static inline _s_ede16979_pOutput _ede16979_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_ede16979_pOutput){value}; }
static inline _s_ede16979_outGammaCaps _ede16979_outGammaCaps(DXGI_GAMMA_CONTROL_CAPABILITIES* value) { return REDGPU_NP_STRUCT_INIT(_s_ede16979_outGammaCaps){value}; }
static inline _s_ede16979_optionalFile _ede16979_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ede16979_optionalFile){value}; }
static inline _s_ede16979_optionalLine _ede16979_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ede16979_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputGetGammaControlCapabilities(_s_ede16979_pOutput pOutput, _s_ede16979_outGammaCaps outGammaCaps, _s_ede16979_optionalFile optionalFile, _s_ede16979_optionalLine optionalLine) {
  return x12OutputGetGammaControlCapabilities(pOutput.value, outGammaCaps.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputSetGammaControl x12OutputSetGammaControl
#define _028483db_pOutput(value) value
#define _028483db_pArray(value) value
#define _028483db_optionalFile(value) value
#define _028483db_optionalLine(value) value
#else
typedef struct _s_028483db_pOutput { X12Output4* value; } _s_028483db_pOutput;
typedef struct _s_028483db_pArray { DXGI_GAMMA_CONTROL* value; } _s_028483db_pArray;
typedef struct _s_028483db_optionalFile { char* value; } _s_028483db_optionalFile;
typedef struct _s_028483db_optionalLine { int value; } _s_028483db_optionalLine;
static inline _s_028483db_pOutput _028483db_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_028483db_pOutput){value}; }
static inline _s_028483db_pArray _028483db_pArray(DXGI_GAMMA_CONTROL* value) { return REDGPU_NP_STRUCT_INIT(_s_028483db_pArray){value}; }
static inline _s_028483db_optionalFile _028483db_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_028483db_optionalFile){value}; }
static inline _s_028483db_optionalLine _028483db_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_028483db_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputSetGammaControl(_s_028483db_pOutput pOutput, _s_028483db_pArray pArray, _s_028483db_optionalFile optionalFile, _s_028483db_optionalLine optionalLine) {
  return x12OutputSetGammaControl(pOutput.value, pArray.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputGetGammaControl x12OutputGetGammaControl
#define _f6b0344f_pOutput(value) value
#define _f6b0344f_outArray(value) value
#define _f6b0344f_optionalFile(value) value
#define _f6b0344f_optionalLine(value) value
#else
typedef struct _s_f6b0344f_pOutput { X12Output4* value; } _s_f6b0344f_pOutput;
typedef struct _s_f6b0344f_outArray { DXGI_GAMMA_CONTROL* value; } _s_f6b0344f_outArray;
typedef struct _s_f6b0344f_optionalFile { char* value; } _s_f6b0344f_optionalFile;
typedef struct _s_f6b0344f_optionalLine { int value; } _s_f6b0344f_optionalLine;
static inline _s_f6b0344f_pOutput _f6b0344f_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_f6b0344f_pOutput){value}; }
static inline _s_f6b0344f_outArray _f6b0344f_outArray(DXGI_GAMMA_CONTROL* value) { return REDGPU_NP_STRUCT_INIT(_s_f6b0344f_outArray){value}; }
static inline _s_f6b0344f_optionalFile _f6b0344f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f6b0344f_optionalFile){value}; }
static inline _s_f6b0344f_optionalLine _f6b0344f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f6b0344f_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputGetGammaControl(_s_f6b0344f_pOutput pOutput, _s_f6b0344f_outArray outArray, _s_f6b0344f_optionalFile optionalFile, _s_f6b0344f_optionalLine optionalLine) {
  return x12OutputGetGammaControl(pOutput.value, outArray.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputGetFrameStatistics x12OutputGetFrameStatistics
#define _ed83eaeb_pOutput(value) value
#define _ed83eaeb_outStats(value) value
#define _ed83eaeb_optionalFile(value) value
#define _ed83eaeb_optionalLine(value) value
#else
typedef struct _s_ed83eaeb_pOutput { X12Output4* value; } _s_ed83eaeb_pOutput;
typedef struct _s_ed83eaeb_outStats { DXGI_FRAME_STATISTICS* value; } _s_ed83eaeb_outStats;
typedef struct _s_ed83eaeb_optionalFile { char* value; } _s_ed83eaeb_optionalFile;
typedef struct _s_ed83eaeb_optionalLine { int value; } _s_ed83eaeb_optionalLine;
static inline _s_ed83eaeb_pOutput _ed83eaeb_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_ed83eaeb_pOutput){value}; }
static inline _s_ed83eaeb_outStats _ed83eaeb_outStats(DXGI_FRAME_STATISTICS* value) { return REDGPU_NP_STRUCT_INIT(_s_ed83eaeb_outStats){value}; }
static inline _s_ed83eaeb_optionalFile _ed83eaeb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ed83eaeb_optionalFile){value}; }
static inline _s_ed83eaeb_optionalLine _ed83eaeb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ed83eaeb_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputGetFrameStatistics(_s_ed83eaeb_pOutput pOutput, _s_ed83eaeb_outStats outStats, _s_ed83eaeb_optionalFile optionalFile, _s_ed83eaeb_optionalLine optionalLine) {
  return x12OutputGetFrameStatistics(pOutput.value, outStats.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputSupportsOverlays x12OutputSupportsOverlays
#define _513e282e_pOutput(value) value
#define _513e282e_optionalFile(value) value
#define _513e282e_optionalLine(value) value
#else
typedef struct _s_513e282e_pOutput { X12Output4* value; } _s_513e282e_pOutput;
typedef struct _s_513e282e_optionalFile { char* value; } _s_513e282e_optionalFile;
typedef struct _s_513e282e_optionalLine { int value; } _s_513e282e_optionalLine;
static inline _s_513e282e_pOutput _513e282e_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_513e282e_pOutput){value}; }
static inline _s_513e282e_optionalFile _513e282e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_513e282e_optionalFile){value}; }
static inline _s_513e282e_optionalLine _513e282e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_513e282e_optionalLine){value}; }
REDGPU_NP_DECLSPEC X12Bool REDGPU_NP_API np_x12OutputSupportsOverlays(_s_513e282e_pOutput pOutput, _s_513e282e_optionalFile optionalFile, _s_513e282e_optionalLine optionalLine) {
  return x12OutputSupportsOverlays(pOutput.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputCheckOverlaySupport x12OutputCheckOverlaySupport
#define _0e69d7c5_pOutput(value) value
#define _0e69d7c5_EnumFormat(value) value
#define _0e69d7c5_pConcernedDevice(value) value
#define _0e69d7c5_pFlags(value) value
#define _0e69d7c5_optionalFile(value) value
#define _0e69d7c5_optionalLine(value) value
#else
typedef struct _s_0e69d7c5_pOutput { X12Output4* value; } _s_0e69d7c5_pOutput;
typedef struct _s_0e69d7c5_EnumFormat { DXGI_FORMAT value; } _s_0e69d7c5_EnumFormat;
typedef struct _s_0e69d7c5_pConcernedDevice { X12Device3* value; } _s_0e69d7c5_pConcernedDevice;
typedef struct _s_0e69d7c5_pFlags { unsigned* value; } _s_0e69d7c5_pFlags;
typedef struct _s_0e69d7c5_optionalFile { char* value; } _s_0e69d7c5_optionalFile;
typedef struct _s_0e69d7c5_optionalLine { int value; } _s_0e69d7c5_optionalLine;
static inline _s_0e69d7c5_pOutput _0e69d7c5_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_0e69d7c5_pOutput){value}; }
static inline _s_0e69d7c5_EnumFormat _0e69d7c5_EnumFormat(DXGI_FORMAT value) { return REDGPU_NP_STRUCT_INIT(_s_0e69d7c5_EnumFormat){value}; }
static inline _s_0e69d7c5_pConcernedDevice _0e69d7c5_pConcernedDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_0e69d7c5_pConcernedDevice){value}; }
static inline _s_0e69d7c5_pFlags _0e69d7c5_pFlags(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_0e69d7c5_pFlags){value}; }
static inline _s_0e69d7c5_optionalFile _0e69d7c5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0e69d7c5_optionalFile){value}; }
static inline _s_0e69d7c5_optionalLine _0e69d7c5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0e69d7c5_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputCheckOverlaySupport(_s_0e69d7c5_pOutput pOutput, _s_0e69d7c5_EnumFormat EnumFormat, _s_0e69d7c5_pConcernedDevice pConcernedDevice, _s_0e69d7c5_pFlags pFlags, _s_0e69d7c5_optionalFile optionalFile, _s_0e69d7c5_optionalLine optionalLine) {
  return x12OutputCheckOverlaySupport(pOutput.value, EnumFormat.value, pConcernedDevice.value, pFlags.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12OutputCheckOverlayColorSpaceSupport x12OutputCheckOverlayColorSpaceSupport
#define _d6cd0087_pOutput(value) value
#define _d6cd0087_Format(value) value
#define _d6cd0087_ColorSpace(value) value
#define _d6cd0087_pConcernedDevice(value) value
#define _d6cd0087_outFlags(value) value
#define _d6cd0087_optionalFile(value) value
#define _d6cd0087_optionalLine(value) value
#else
typedef struct _s_d6cd0087_pOutput { X12Output4* value; } _s_d6cd0087_pOutput;
typedef struct _s_d6cd0087_Format { DXGI_FORMAT value; } _s_d6cd0087_Format;
typedef struct _s_d6cd0087_ColorSpace { DXGI_COLOR_SPACE_TYPE value; } _s_d6cd0087_ColorSpace;
typedef struct _s_d6cd0087_pConcernedDevice { X12Device3* value; } _s_d6cd0087_pConcernedDevice;
typedef struct _s_d6cd0087_outFlags { DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAGS* value; } _s_d6cd0087_outFlags;
typedef struct _s_d6cd0087_optionalFile { char* value; } _s_d6cd0087_optionalFile;
typedef struct _s_d6cd0087_optionalLine { int value; } _s_d6cd0087_optionalLine;
static inline _s_d6cd0087_pOutput _d6cd0087_pOutput(X12Output4* value) { return REDGPU_NP_STRUCT_INIT(_s_d6cd0087_pOutput){value}; }
static inline _s_d6cd0087_Format _d6cd0087_Format(DXGI_FORMAT value) { return REDGPU_NP_STRUCT_INIT(_s_d6cd0087_Format){value}; }
static inline _s_d6cd0087_ColorSpace _d6cd0087_ColorSpace(DXGI_COLOR_SPACE_TYPE value) { return REDGPU_NP_STRUCT_INIT(_s_d6cd0087_ColorSpace){value}; }
static inline _s_d6cd0087_pConcernedDevice _d6cd0087_pConcernedDevice(X12Device3* value) { return REDGPU_NP_STRUCT_INIT(_s_d6cd0087_pConcernedDevice){value}; }
static inline _s_d6cd0087_outFlags _d6cd0087_outFlags(DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAGS* value) { return REDGPU_NP_STRUCT_INIT(_s_d6cd0087_outFlags){value}; }
static inline _s_d6cd0087_optionalFile _d6cd0087_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d6cd0087_optionalFile){value}; }
static inline _s_d6cd0087_optionalLine _d6cd0087_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d6cd0087_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12OutputCheckOverlayColorSpaceSupport(_s_d6cd0087_pOutput pOutput, _s_d6cd0087_Format Format, _s_d6cd0087_ColorSpace ColorSpace, _s_d6cd0087_pConcernedDevice pConcernedDevice, _s_d6cd0087_outFlags outFlags, _s_d6cd0087_optionalFile optionalFile, _s_d6cd0087_optionalLine optionalLine) {
  return x12OutputCheckOverlayColorSpaceSupport(pOutput.value, Format.value, ColorSpace.value, pConcernedDevice.value, outFlags.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12ObjectSetName x12ObjectSetName
#define _2e6913bb_handle(value) value
#define _2e6913bb_Name(value) value
#define _2e6913bb_optionalFile(value) value
#define _2e6913bb_optionalLine(value) value
#else
typedef struct _s_2e6913bb_handle { void* value; } _s_2e6913bb_handle;
typedef struct _s_2e6913bb_Name { wchar_t* value; } _s_2e6913bb_Name;
typedef struct _s_2e6913bb_optionalFile { char* value; } _s_2e6913bb_optionalFile;
typedef struct _s_2e6913bb_optionalLine { int value; } _s_2e6913bb_optionalLine;
static inline _s_2e6913bb_handle _2e6913bb_handle(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2e6913bb_handle){value}; }
static inline _s_2e6913bb_Name _2e6913bb_Name(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_2e6913bb_Name){value}; }
static inline _s_2e6913bb_optionalFile _2e6913bb_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2e6913bb_optionalFile){value}; }
static inline _s_2e6913bb_optionalLine _2e6913bb_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2e6913bb_optionalLine){value}; }
REDGPU_NP_DECLSPEC HRESULT REDGPU_NP_API np_x12ObjectSetName(_s_2e6913bb_handle handle, _s_2e6913bb_Name Name, _s_2e6913bb_optionalFile optionalFile, _s_2e6913bb_optionalLine optionalLine) {
  return x12ObjectSetName(handle.value, Name.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12Release x12Release
#define _4f9da3ac_handle(value) value
#define _4f9da3ac_optionalFile(value) value
#define _4f9da3ac_optionalLine(value) value
#else
typedef struct _s_4f9da3ac_handle { void* value; } _s_4f9da3ac_handle;
typedef struct _s_4f9da3ac_optionalFile { char* value; } _s_4f9da3ac_optionalFile;
typedef struct _s_4f9da3ac_optionalLine { int value; } _s_4f9da3ac_optionalLine;
static inline _s_4f9da3ac_handle _4f9da3ac_handle(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4f9da3ac_handle){value}; }
static inline _s_4f9da3ac_optionalFile _4f9da3ac_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4f9da3ac_optionalFile){value}; }
static inline _s_4f9da3ac_optionalLine _4f9da3ac_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4f9da3ac_optionalLine){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12Release(_s_4f9da3ac_handle handle, _s_4f9da3ac_optionalFile optionalFile, _s_4f9da3ac_optionalLine optionalLine) {
  x12Release(handle.value, optionalFile.value, optionalLine.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListSetMarker x12CommandListSetMarker
#define _16d2881c_handle(value) value
#define _16d2881c_Metadata(value) value
#define _16d2881c_pData(value) value
#define _16d2881c_Size(value) value
#else
typedef struct _s_16d2881c_handle { X12CommandList* value; } _s_16d2881c_handle;
typedef struct _s_16d2881c_Metadata { unsigned value; } _s_16d2881c_Metadata;
typedef struct _s_16d2881c_pData { void* value; } _s_16d2881c_pData;
typedef struct _s_16d2881c_Size { unsigned value; } _s_16d2881c_Size;
static inline _s_16d2881c_handle _16d2881c_handle(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_16d2881c_handle){value}; }
static inline _s_16d2881c_Metadata _16d2881c_Metadata(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_16d2881c_Metadata){value}; }
static inline _s_16d2881c_pData _16d2881c_pData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_16d2881c_pData){value}; }
static inline _s_16d2881c_Size _16d2881c_Size(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_16d2881c_Size){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListSetMarker(_s_16d2881c_handle handle, _s_16d2881c_Metadata Metadata, _s_16d2881c_pData pData, _s_16d2881c_Size Size) {
  x12CommandListSetMarker(handle.value, Metadata.value, pData.value, Size.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListBeginEvent x12CommandListBeginEvent
#define _7500dcee_handle(value) value
#define _7500dcee_Metadata(value) value
#define _7500dcee_pData(value) value
#define _7500dcee_Size(value) value
#else
typedef struct _s_7500dcee_handle { X12CommandList* value; } _s_7500dcee_handle;
typedef struct _s_7500dcee_Metadata { unsigned value; } _s_7500dcee_Metadata;
typedef struct _s_7500dcee_pData { void* value; } _s_7500dcee_pData;
typedef struct _s_7500dcee_Size { unsigned value; } _s_7500dcee_Size;
static inline _s_7500dcee_handle _7500dcee_handle(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_7500dcee_handle){value}; }
static inline _s_7500dcee_Metadata _7500dcee_Metadata(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_7500dcee_Metadata){value}; }
static inline _s_7500dcee_pData _7500dcee_pData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7500dcee_pData){value}; }
static inline _s_7500dcee_Size _7500dcee_Size(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_7500dcee_Size){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListBeginEvent(_s_7500dcee_handle handle, _s_7500dcee_Metadata Metadata, _s_7500dcee_pData pData, _s_7500dcee_Size Size) {
  x12CommandListBeginEvent(handle.value, Metadata.value, pData.value, Size.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandListEndEvent x12CommandListEndEvent
#define _a016ee3a_handle(value) value
#else
typedef struct _s_a016ee3a_handle { X12CommandList* value; } _s_a016ee3a_handle;
static inline _s_a016ee3a_handle _a016ee3a_handle(X12CommandList* value) { return REDGPU_NP_STRUCT_INIT(_s_a016ee3a_handle){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandListEndEvent(_s_a016ee3a_handle handle) {
  x12CommandListEndEvent(handle.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandQueueSetMarker x12CommandQueueSetMarker
#define _2056627d_handle(value) value
#define _2056627d_Metadata(value) value
#define _2056627d_pData(value) value
#define _2056627d_Size(value) value
#else
typedef struct _s_2056627d_handle { X12CommandQueue* value; } _s_2056627d_handle;
typedef struct _s_2056627d_Metadata { unsigned value; } _s_2056627d_Metadata;
typedef struct _s_2056627d_pData { void* value; } _s_2056627d_pData;
typedef struct _s_2056627d_Size { unsigned value; } _s_2056627d_Size;
static inline _s_2056627d_handle _2056627d_handle(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_2056627d_handle){value}; }
static inline _s_2056627d_Metadata _2056627d_Metadata(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_2056627d_Metadata){value}; }
static inline _s_2056627d_pData _2056627d_pData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2056627d_pData){value}; }
static inline _s_2056627d_Size _2056627d_Size(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_2056627d_Size){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandQueueSetMarker(_s_2056627d_handle handle, _s_2056627d_Metadata Metadata, _s_2056627d_pData pData, _s_2056627d_Size Size) {
  x12CommandQueueSetMarker(handle.value, Metadata.value, pData.value, Size.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandQueueBeginEvent x12CommandQueueBeginEvent
#define _a3651f57_handle(value) value
#define _a3651f57_Metadata(value) value
#define _a3651f57_pData(value) value
#define _a3651f57_Size(value) value
#else
typedef struct _s_a3651f57_handle { X12CommandQueue* value; } _s_a3651f57_handle;
typedef struct _s_a3651f57_Metadata { unsigned value; } _s_a3651f57_Metadata;
typedef struct _s_a3651f57_pData { void* value; } _s_a3651f57_pData;
typedef struct _s_a3651f57_Size { unsigned value; } _s_a3651f57_Size;
static inline _s_a3651f57_handle _a3651f57_handle(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_a3651f57_handle){value}; }
static inline _s_a3651f57_Metadata _a3651f57_Metadata(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a3651f57_Metadata){value}; }
static inline _s_a3651f57_pData _a3651f57_pData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a3651f57_pData){value}; }
static inline _s_a3651f57_Size _a3651f57_Size(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_a3651f57_Size){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandQueueBeginEvent(_s_a3651f57_handle handle, _s_a3651f57_Metadata Metadata, _s_a3651f57_pData pData, _s_a3651f57_Size Size) {
  x12CommandQueueBeginEvent(handle.value, Metadata.value, pData.value, Size.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_x12CommandQueueEndEvent x12CommandQueueEndEvent
#define _3af02fbb_handle(value) value
#else
typedef struct _s_3af02fbb_handle { X12CommandQueue* value; } _s_3af02fbb_handle;
static inline _s_3af02fbb_handle _3af02fbb_handle(X12CommandQueue* value) { return REDGPU_NP_STRUCT_INIT(_s_3af02fbb_handle){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_x12CommandQueueEndEvent(_s_3af02fbb_handle handle) {
  x12CommandQueueEndEvent(handle.value);
}
#endif

