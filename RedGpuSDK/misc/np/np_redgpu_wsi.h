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
#define np_redCreateSurfaceWin32 redCreateSurfaceWin32
#define _27ff40c9_context(value) value
#define _27ff40c9_gpu(value) value
#define _27ff40c9_handleName(value) value
#define _27ff40c9_win32Hinstance(value) value
#define _27ff40c9_win32Hwnd(value) value
#define _27ff40c9_outSurface(value) value
#define _27ff40c9_outStatuses(value) value
#define _27ff40c9_optionalFile(value) value
#define _27ff40c9_optionalLine(value) value
#define _27ff40c9_optionalUserData(value) value
#else
typedef struct _s_27ff40c9_context { RedContext value; } _s_27ff40c9_context;
typedef struct _s_27ff40c9_gpu { RedHandleGpu value; } _s_27ff40c9_gpu;
typedef struct _s_27ff40c9_handleName { char* value; } _s_27ff40c9_handleName;
typedef struct _s_27ff40c9_win32Hinstance { void* value; } _s_27ff40c9_win32Hinstance;
typedef struct _s_27ff40c9_win32Hwnd { void* value; } _s_27ff40c9_win32Hwnd;
typedef struct _s_27ff40c9_outSurface { RedHandleSurface* value; } _s_27ff40c9_outSurface;
typedef struct _s_27ff40c9_outStatuses { RedStatuses* value; } _s_27ff40c9_outStatuses;
typedef struct _s_27ff40c9_optionalFile { char* value; } _s_27ff40c9_optionalFile;
typedef struct _s_27ff40c9_optionalLine { int value; } _s_27ff40c9_optionalLine;
typedef struct _s_27ff40c9_optionalUserData { void* value; } _s_27ff40c9_optionalUserData;
static inline _s_27ff40c9_context _27ff40c9_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_27ff40c9_context){value}; }
static inline _s_27ff40c9_gpu _27ff40c9_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_27ff40c9_gpu){value}; }
static inline _s_27ff40c9_handleName _27ff40c9_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_27ff40c9_handleName){value}; }
static inline _s_27ff40c9_win32Hinstance _27ff40c9_win32Hinstance(void* value) { return REDGPU_NP_STRUCT_INIT(_s_27ff40c9_win32Hinstance){value}; }
static inline _s_27ff40c9_win32Hwnd _27ff40c9_win32Hwnd(void* value) { return REDGPU_NP_STRUCT_INIT(_s_27ff40c9_win32Hwnd){value}; }
static inline _s_27ff40c9_outSurface _27ff40c9_outSurface(RedHandleSurface* value) { return REDGPU_NP_STRUCT_INIT(_s_27ff40c9_outSurface){value}; }
static inline _s_27ff40c9_outStatuses _27ff40c9_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_27ff40c9_outStatuses){value}; }
static inline _s_27ff40c9_optionalFile _27ff40c9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_27ff40c9_optionalFile){value}; }
static inline _s_27ff40c9_optionalLine _27ff40c9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_27ff40c9_optionalLine){value}; }
static inline _s_27ff40c9_optionalUserData _27ff40c9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_27ff40c9_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateSurfaceWin32(_s_27ff40c9_context context, _s_27ff40c9_gpu gpu, _s_27ff40c9_handleName handleName, _s_27ff40c9_win32Hinstance win32Hinstance, _s_27ff40c9_win32Hwnd win32Hwnd, _s_27ff40c9_outSurface outSurface, _s_27ff40c9_outStatuses outStatuses, _s_27ff40c9_optionalFile optionalFile, _s_27ff40c9_optionalLine optionalLine, _s_27ff40c9_optionalUserData optionalUserData) {
  redCreateSurfaceWin32(context.value, gpu.value, handleName.value, win32Hinstance.value, win32Hwnd.value, outSurface.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateSurfaceXlibOrXcb redCreateSurfaceXlibOrXcb
#define _9f5708fc_context(value) value
#define _9f5708fc_gpu(value) value
#define _9f5708fc_handleName(value) value
#define _9f5708fc_xlibDisplay(value) value
#define _9f5708fc_xlibWindow(value) value
#define _9f5708fc_xcbConnection(value) value
#define _9f5708fc_xcbWindow(value) value
#define _9f5708fc_outSurface(value) value
#define _9f5708fc_outStatuses(value) value
#define _9f5708fc_optionalFile(value) value
#define _9f5708fc_optionalLine(value) value
#define _9f5708fc_optionalUserData(value) value
#else
typedef struct _s_9f5708fc_context { RedContext value; } _s_9f5708fc_context;
typedef struct _s_9f5708fc_gpu { RedHandleGpu value; } _s_9f5708fc_gpu;
typedef struct _s_9f5708fc_handleName { char* value; } _s_9f5708fc_handleName;
typedef struct _s_9f5708fc_xlibDisplay { void* value; } _s_9f5708fc_xlibDisplay;
typedef struct _s_9f5708fc_xlibWindow { uint64_t value; } _s_9f5708fc_xlibWindow;
typedef struct _s_9f5708fc_xcbConnection { void* value; } _s_9f5708fc_xcbConnection;
typedef struct _s_9f5708fc_xcbWindow { unsigned value; } _s_9f5708fc_xcbWindow;
typedef struct _s_9f5708fc_outSurface { RedHandleSurface* value; } _s_9f5708fc_outSurface;
typedef struct _s_9f5708fc_outStatuses { RedStatuses* value; } _s_9f5708fc_outStatuses;
typedef struct _s_9f5708fc_optionalFile { char* value; } _s_9f5708fc_optionalFile;
typedef struct _s_9f5708fc_optionalLine { int value; } _s_9f5708fc_optionalLine;
typedef struct _s_9f5708fc_optionalUserData { void* value; } _s_9f5708fc_optionalUserData;
static inline _s_9f5708fc_context _9f5708fc_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_9f5708fc_context){value}; }
static inline _s_9f5708fc_gpu _9f5708fc_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_9f5708fc_gpu){value}; }
static inline _s_9f5708fc_handleName _9f5708fc_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9f5708fc_handleName){value}; }
static inline _s_9f5708fc_xlibDisplay _9f5708fc_xlibDisplay(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9f5708fc_xlibDisplay){value}; }
static inline _s_9f5708fc_xlibWindow _9f5708fc_xlibWindow(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_9f5708fc_xlibWindow){value}; }
static inline _s_9f5708fc_xcbConnection _9f5708fc_xcbConnection(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9f5708fc_xcbConnection){value}; }
static inline _s_9f5708fc_xcbWindow _9f5708fc_xcbWindow(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_9f5708fc_xcbWindow){value}; }
static inline _s_9f5708fc_outSurface _9f5708fc_outSurface(RedHandleSurface* value) { return REDGPU_NP_STRUCT_INIT(_s_9f5708fc_outSurface){value}; }
static inline _s_9f5708fc_outStatuses _9f5708fc_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_9f5708fc_outStatuses){value}; }
static inline _s_9f5708fc_optionalFile _9f5708fc_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9f5708fc_optionalFile){value}; }
static inline _s_9f5708fc_optionalLine _9f5708fc_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9f5708fc_optionalLine){value}; }
static inline _s_9f5708fc_optionalUserData _9f5708fc_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9f5708fc_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateSurfaceXlibOrXcb(_s_9f5708fc_context context, _s_9f5708fc_gpu gpu, _s_9f5708fc_handleName handleName, _s_9f5708fc_xlibDisplay xlibDisplay, _s_9f5708fc_xlibWindow xlibWindow, _s_9f5708fc_xcbConnection xcbConnection, _s_9f5708fc_xcbWindow xcbWindow, _s_9f5708fc_outSurface outSurface, _s_9f5708fc_outStatuses outStatuses, _s_9f5708fc_optionalFile optionalFile, _s_9f5708fc_optionalLine optionalLine, _s_9f5708fc_optionalUserData optionalUserData) {
  redCreateSurfaceXlibOrXcb(context.value, gpu.value, handleName.value, xlibDisplay.value, xlibWindow.value, xcbConnection.value, xcbWindow.value, outSurface.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreatePresent redCreatePresent
#define _b9c19ac2_context(value) value
#define _b9c19ac2_gpu(value) value
#define _b9c19ac2_queue(value) value
#define _b9c19ac2_handleName(value) value
#define _b9c19ac2_surface(value) value
#define _b9c19ac2_imagesCount(value) value
#define _b9c19ac2_imagesWidth(value) value
#define _b9c19ac2_imagesHeight(value) value
#define _b9c19ac2_imagesLayersCount(value) value
#define _b9c19ac2_imagesRestrictToAccess(value) value
#define _b9c19ac2_transform(value) value
#define _b9c19ac2_compositeAlpha(value) value
#define _b9c19ac2_vsyncMode(value) value
#define _b9c19ac2_clipped(value) value
#define _b9c19ac2_discardAfterPresent(value) value
#define _b9c19ac2_oldPresent(value) value
#define _b9c19ac2_outPresent(value) value
#define _b9c19ac2_outImages(value) value
#define _b9c19ac2_outTextures(value) value
#define _b9c19ac2_outStatuses(value) value
#define _b9c19ac2_optionalFile(value) value
#define _b9c19ac2_optionalLine(value) value
#define _b9c19ac2_optionalUserData(value) value
#else
typedef struct _s_b9c19ac2_context { RedContext value; } _s_b9c19ac2_context;
typedef struct _s_b9c19ac2_gpu { RedHandleGpu value; } _s_b9c19ac2_gpu;
typedef struct _s_b9c19ac2_queue { RedHandleQueue value; } _s_b9c19ac2_queue;
typedef struct _s_b9c19ac2_handleName { char* value; } _s_b9c19ac2_handleName;
typedef struct _s_b9c19ac2_surface { RedHandleSurface value; } _s_b9c19ac2_surface;
typedef struct _s_b9c19ac2_imagesCount { unsigned value; } _s_b9c19ac2_imagesCount;
typedef struct _s_b9c19ac2_imagesWidth { unsigned value; } _s_b9c19ac2_imagesWidth;
typedef struct _s_b9c19ac2_imagesHeight { unsigned value; } _s_b9c19ac2_imagesHeight;
typedef struct _s_b9c19ac2_imagesLayersCount { unsigned value; } _s_b9c19ac2_imagesLayersCount;
typedef struct _s_b9c19ac2_imagesRestrictToAccess { RedAccessBitflags value; } _s_b9c19ac2_imagesRestrictToAccess;
typedef struct _s_b9c19ac2_transform { RedSurfaceTransformBitflag value; } _s_b9c19ac2_transform;
typedef struct _s_b9c19ac2_compositeAlpha { RedSurfaceCompositeAlphaBitflag value; } _s_b9c19ac2_compositeAlpha;
typedef struct _s_b9c19ac2_vsyncMode { RedPresentVsyncMode value; } _s_b9c19ac2_vsyncMode;
typedef struct _s_b9c19ac2_clipped { RedBool32 value; } _s_b9c19ac2_clipped;
typedef struct _s_b9c19ac2_discardAfterPresent { RedBool32 value; } _s_b9c19ac2_discardAfterPresent;
typedef struct _s_b9c19ac2_oldPresent { RedHandlePresent value; } _s_b9c19ac2_oldPresent;
typedef struct _s_b9c19ac2_outPresent { RedHandlePresent* value; } _s_b9c19ac2_outPresent;
typedef struct _s_b9c19ac2_outImages { RedHandleImage* value; } _s_b9c19ac2_outImages;
typedef struct _s_b9c19ac2_outTextures { RedHandleTexture* value; } _s_b9c19ac2_outTextures;
typedef struct _s_b9c19ac2_outStatuses { RedStatuses* value; } _s_b9c19ac2_outStatuses;
typedef struct _s_b9c19ac2_optionalFile { char* value; } _s_b9c19ac2_optionalFile;
typedef struct _s_b9c19ac2_optionalLine { int value; } _s_b9c19ac2_optionalLine;
typedef struct _s_b9c19ac2_optionalUserData { void* value; } _s_b9c19ac2_optionalUserData;
static inline _s_b9c19ac2_context _b9c19ac2_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_context){value}; }
static inline _s_b9c19ac2_gpu _b9c19ac2_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_gpu){value}; }
static inline _s_b9c19ac2_queue _b9c19ac2_queue(RedHandleQueue value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_queue){value}; }
static inline _s_b9c19ac2_handleName _b9c19ac2_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_handleName){value}; }
static inline _s_b9c19ac2_surface _b9c19ac2_surface(RedHandleSurface value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_surface){value}; }
static inline _s_b9c19ac2_imagesCount _b9c19ac2_imagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_imagesCount){value}; }
static inline _s_b9c19ac2_imagesWidth _b9c19ac2_imagesWidth(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_imagesWidth){value}; }
static inline _s_b9c19ac2_imagesHeight _b9c19ac2_imagesHeight(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_imagesHeight){value}; }
static inline _s_b9c19ac2_imagesLayersCount _b9c19ac2_imagesLayersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_imagesLayersCount){value}; }
static inline _s_b9c19ac2_imagesRestrictToAccess _b9c19ac2_imagesRestrictToAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_imagesRestrictToAccess){value}; }
static inline _s_b9c19ac2_transform _b9c19ac2_transform(RedSurfaceTransformBitflag value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_transform){value}; }
static inline _s_b9c19ac2_compositeAlpha _b9c19ac2_compositeAlpha(RedSurfaceCompositeAlphaBitflag value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_compositeAlpha){value}; }
static inline _s_b9c19ac2_vsyncMode _b9c19ac2_vsyncMode(RedPresentVsyncMode value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_vsyncMode){value}; }
static inline _s_b9c19ac2_clipped _b9c19ac2_clipped(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_clipped){value}; }
static inline _s_b9c19ac2_discardAfterPresent _b9c19ac2_discardAfterPresent(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_discardAfterPresent){value}; }
static inline _s_b9c19ac2_oldPresent _b9c19ac2_oldPresent(RedHandlePresent value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_oldPresent){value}; }
static inline _s_b9c19ac2_outPresent _b9c19ac2_outPresent(RedHandlePresent* value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_outPresent){value}; }
static inline _s_b9c19ac2_outImages _b9c19ac2_outImages(RedHandleImage* value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_outImages){value}; }
static inline _s_b9c19ac2_outTextures _b9c19ac2_outTextures(RedHandleTexture* value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_outTextures){value}; }
static inline _s_b9c19ac2_outStatuses _b9c19ac2_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_outStatuses){value}; }
static inline _s_b9c19ac2_optionalFile _b9c19ac2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_optionalFile){value}; }
static inline _s_b9c19ac2_optionalLine _b9c19ac2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_optionalLine){value}; }
static inline _s_b9c19ac2_optionalUserData _b9c19ac2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b9c19ac2_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreatePresent(_s_b9c19ac2_context context, _s_b9c19ac2_gpu gpu, _s_b9c19ac2_queue queue, _s_b9c19ac2_handleName handleName, _s_b9c19ac2_surface surface, _s_b9c19ac2_imagesCount imagesCount, _s_b9c19ac2_imagesWidth imagesWidth, _s_b9c19ac2_imagesHeight imagesHeight, _s_b9c19ac2_imagesLayersCount imagesLayersCount, _s_b9c19ac2_imagesRestrictToAccess imagesRestrictToAccess, _s_b9c19ac2_transform transform, _s_b9c19ac2_compositeAlpha compositeAlpha, _s_b9c19ac2_vsyncMode vsyncMode, _s_b9c19ac2_clipped clipped, _s_b9c19ac2_discardAfterPresent discardAfterPresent, _s_b9c19ac2_oldPresent oldPresent, _s_b9c19ac2_outPresent outPresent, _s_b9c19ac2_outImages outImages, _s_b9c19ac2_outTextures outTextures, _s_b9c19ac2_outStatuses outStatuses, _s_b9c19ac2_optionalFile optionalFile, _s_b9c19ac2_optionalLine optionalLine, _s_b9c19ac2_optionalUserData optionalUserData) {
  redCreatePresent(context.value, gpu.value, queue.value, handleName.value, surface.value, imagesCount.value, imagesWidth.value, imagesHeight.value, imagesLayersCount.value, imagesRestrictToAccess.value, transform.value, compositeAlpha.value, vsyncMode.value, clipped.value, discardAfterPresent.value, oldPresent.value, outPresent.value, outImages.value, outTextures.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroySurface redDestroySurface
#define _804310d3_context(value) value
#define _804310d3_gpu(value) value
#define _804310d3_surface(value) value
#define _804310d3_optionalFile(value) value
#define _804310d3_optionalLine(value) value
#define _804310d3_optionalUserData(value) value
#else
typedef struct _s_804310d3_context { RedContext value; } _s_804310d3_context;
typedef struct _s_804310d3_gpu { RedHandleGpu value; } _s_804310d3_gpu;
typedef struct _s_804310d3_surface { RedHandleSurface value; } _s_804310d3_surface;
typedef struct _s_804310d3_optionalFile { char* value; } _s_804310d3_optionalFile;
typedef struct _s_804310d3_optionalLine { int value; } _s_804310d3_optionalLine;
typedef struct _s_804310d3_optionalUserData { void* value; } _s_804310d3_optionalUserData;
static inline _s_804310d3_context _804310d3_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_804310d3_context){value}; }
static inline _s_804310d3_gpu _804310d3_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_804310d3_gpu){value}; }
static inline _s_804310d3_surface _804310d3_surface(RedHandleSurface value) { return REDGPU_NP_STRUCT_INIT(_s_804310d3_surface){value}; }
static inline _s_804310d3_optionalFile _804310d3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_804310d3_optionalFile){value}; }
static inline _s_804310d3_optionalLine _804310d3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_804310d3_optionalLine){value}; }
static inline _s_804310d3_optionalUserData _804310d3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_804310d3_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroySurface(_s_804310d3_context context, _s_804310d3_gpu gpu, _s_804310d3_surface surface, _s_804310d3_optionalFile optionalFile, _s_804310d3_optionalLine optionalLine, _s_804310d3_optionalUserData optionalUserData) {
  redDestroySurface(context.value, gpu.value, surface.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyPresent redDestroyPresent
#define _7c2cce55_context(value) value
#define _7c2cce55_gpu(value) value
#define _7c2cce55_present(value) value
#define _7c2cce55_optionalFile(value) value
#define _7c2cce55_optionalLine(value) value
#define _7c2cce55_optionalUserData(value) value
#else
typedef struct _s_7c2cce55_context { RedContext value; } _s_7c2cce55_context;
typedef struct _s_7c2cce55_gpu { RedHandleGpu value; } _s_7c2cce55_gpu;
typedef struct _s_7c2cce55_present { RedHandlePresent value; } _s_7c2cce55_present;
typedef struct _s_7c2cce55_optionalFile { char* value; } _s_7c2cce55_optionalFile;
typedef struct _s_7c2cce55_optionalLine { int value; } _s_7c2cce55_optionalLine;
typedef struct _s_7c2cce55_optionalUserData { void* value; } _s_7c2cce55_optionalUserData;
static inline _s_7c2cce55_context _7c2cce55_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_7c2cce55_context){value}; }
static inline _s_7c2cce55_gpu _7c2cce55_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_7c2cce55_gpu){value}; }
static inline _s_7c2cce55_present _7c2cce55_present(RedHandlePresent value) { return REDGPU_NP_STRUCT_INIT(_s_7c2cce55_present){value}; }
static inline _s_7c2cce55_optionalFile _7c2cce55_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7c2cce55_optionalFile){value}; }
static inline _s_7c2cce55_optionalLine _7c2cce55_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7c2cce55_optionalLine){value}; }
static inline _s_7c2cce55_optionalUserData _7c2cce55_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7c2cce55_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyPresent(_s_7c2cce55_context context, _s_7c2cce55_gpu gpu, _s_7c2cce55_present present, _s_7c2cce55_optionalFile optionalFile, _s_7c2cce55_optionalLine optionalLine, _s_7c2cce55_optionalUserData optionalUserData) {
  redDestroyPresent(context.value, gpu.value, present.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redQueueFamilyIndexGetSupportsPresent redQueueFamilyIndexGetSupportsPresent
#define _eace2bad_context(value) value
#define _eace2bad_gpu(value) value
#define _eace2bad_queueFamilyIndex(value) value
#define _eace2bad_supportsPresentOnWin32(value) value
#define _eace2bad_supportsPresentOnXlib(value) value
#define _eace2bad_supportsPresentOnXcb(value) value
#define _eace2bad_supportsPresentOnSurface(value) value
#define _eace2bad_outStatuses(value) value
#define _eace2bad_optionalFile(value) value
#define _eace2bad_optionalLine(value) value
#define _eace2bad_optionalUserData(value) value
#else
typedef struct _s_eace2bad_context { RedContext value; } _s_eace2bad_context;
typedef struct _s_eace2bad_gpu { RedHandleGpu value; } _s_eace2bad_gpu;
typedef struct _s_eace2bad_queueFamilyIndex { unsigned value; } _s_eace2bad_queueFamilyIndex;
typedef struct _s_eace2bad_supportsPresentOnWin32 { RedQueueFamilyIndexGetSupportsPresentOnWin32* value; } _s_eace2bad_supportsPresentOnWin32;
typedef struct _s_eace2bad_supportsPresentOnXlib { RedQueueFamilyIndexGetSupportsPresentOnXlib* value; } _s_eace2bad_supportsPresentOnXlib;
typedef struct _s_eace2bad_supportsPresentOnXcb { RedQueueFamilyIndexGetSupportsPresentOnXcb* value; } _s_eace2bad_supportsPresentOnXcb;
typedef struct _s_eace2bad_supportsPresentOnSurface { RedQueueFamilyIndexGetSupportsPresentOnSurface* value; } _s_eace2bad_supportsPresentOnSurface;
typedef struct _s_eace2bad_outStatuses { RedStatuses* value; } _s_eace2bad_outStatuses;
typedef struct _s_eace2bad_optionalFile { char* value; } _s_eace2bad_optionalFile;
typedef struct _s_eace2bad_optionalLine { int value; } _s_eace2bad_optionalLine;
typedef struct _s_eace2bad_optionalUserData { void* value; } _s_eace2bad_optionalUserData;
static inline _s_eace2bad_context _eace2bad_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_eace2bad_context){value}; }
static inline _s_eace2bad_gpu _eace2bad_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_eace2bad_gpu){value}; }
static inline _s_eace2bad_queueFamilyIndex _eace2bad_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_eace2bad_queueFamilyIndex){value}; }
static inline _s_eace2bad_supportsPresentOnWin32 _eace2bad_supportsPresentOnWin32(RedQueueFamilyIndexGetSupportsPresentOnWin32* value) { return REDGPU_NP_STRUCT_INIT(_s_eace2bad_supportsPresentOnWin32){value}; }
static inline _s_eace2bad_supportsPresentOnXlib _eace2bad_supportsPresentOnXlib(RedQueueFamilyIndexGetSupportsPresentOnXlib* value) { return REDGPU_NP_STRUCT_INIT(_s_eace2bad_supportsPresentOnXlib){value}; }
static inline _s_eace2bad_supportsPresentOnXcb _eace2bad_supportsPresentOnXcb(RedQueueFamilyIndexGetSupportsPresentOnXcb* value) { return REDGPU_NP_STRUCT_INIT(_s_eace2bad_supportsPresentOnXcb){value}; }
static inline _s_eace2bad_supportsPresentOnSurface _eace2bad_supportsPresentOnSurface(RedQueueFamilyIndexGetSupportsPresentOnSurface* value) { return REDGPU_NP_STRUCT_INIT(_s_eace2bad_supportsPresentOnSurface){value}; }
static inline _s_eace2bad_outStatuses _eace2bad_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_eace2bad_outStatuses){value}; }
static inline _s_eace2bad_optionalFile _eace2bad_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_eace2bad_optionalFile){value}; }
static inline _s_eace2bad_optionalLine _eace2bad_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_eace2bad_optionalLine){value}; }
static inline _s_eace2bad_optionalUserData _eace2bad_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_eace2bad_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redQueueFamilyIndexGetSupportsPresent(_s_eace2bad_context context, _s_eace2bad_gpu gpu, _s_eace2bad_queueFamilyIndex queueFamilyIndex, _s_eace2bad_supportsPresentOnWin32 supportsPresentOnWin32, _s_eace2bad_supportsPresentOnXlib supportsPresentOnXlib, _s_eace2bad_supportsPresentOnXcb supportsPresentOnXcb, _s_eace2bad_supportsPresentOnSurface supportsPresentOnSurface, _s_eace2bad_outStatuses outStatuses, _s_eace2bad_optionalFile optionalFile, _s_eace2bad_optionalLine optionalLine, _s_eace2bad_optionalUserData optionalUserData) {
  redQueueFamilyIndexGetSupportsPresent(context.value, gpu.value, queueFamilyIndex.value, supportsPresentOnWin32.value, supportsPresentOnXlib.value, supportsPresentOnXcb.value, supportsPresentOnSurface.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redSurfaceGetPresentFeatures redSurfaceGetPresentFeatures
#define _46fd1bf9_context(value) value
#define _46fd1bf9_gpu(value) value
#define _46fd1bf9_surface(value) value
#define _46fd1bf9_outSurfacePresentFeatures(value) value
#define _46fd1bf9_outStatuses(value) value
#define _46fd1bf9_optionalFile(value) value
#define _46fd1bf9_optionalLine(value) value
#define _46fd1bf9_optionalUserData(value) value
#else
typedef struct _s_46fd1bf9_context { RedContext value; } _s_46fd1bf9_context;
typedef struct _s_46fd1bf9_gpu { RedHandleGpu value; } _s_46fd1bf9_gpu;
typedef struct _s_46fd1bf9_surface { RedHandleSurface value; } _s_46fd1bf9_surface;
typedef struct _s_46fd1bf9_outSurfacePresentFeatures { RedSurfacePresentFeatures* value; } _s_46fd1bf9_outSurfacePresentFeatures;
typedef struct _s_46fd1bf9_outStatuses { RedStatuses* value; } _s_46fd1bf9_outStatuses;
typedef struct _s_46fd1bf9_optionalFile { char* value; } _s_46fd1bf9_optionalFile;
typedef struct _s_46fd1bf9_optionalLine { int value; } _s_46fd1bf9_optionalLine;
typedef struct _s_46fd1bf9_optionalUserData { void* value; } _s_46fd1bf9_optionalUserData;
static inline _s_46fd1bf9_context _46fd1bf9_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_46fd1bf9_context){value}; }
static inline _s_46fd1bf9_gpu _46fd1bf9_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_46fd1bf9_gpu){value}; }
static inline _s_46fd1bf9_surface _46fd1bf9_surface(RedHandleSurface value) { return REDGPU_NP_STRUCT_INIT(_s_46fd1bf9_surface){value}; }
static inline _s_46fd1bf9_outSurfacePresentFeatures _46fd1bf9_outSurfacePresentFeatures(RedSurfacePresentFeatures* value) { return REDGPU_NP_STRUCT_INIT(_s_46fd1bf9_outSurfacePresentFeatures){value}; }
static inline _s_46fd1bf9_outStatuses _46fd1bf9_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_46fd1bf9_outStatuses){value}; }
static inline _s_46fd1bf9_optionalFile _46fd1bf9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_46fd1bf9_optionalFile){value}; }
static inline _s_46fd1bf9_optionalLine _46fd1bf9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_46fd1bf9_optionalLine){value}; }
static inline _s_46fd1bf9_optionalUserData _46fd1bf9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_46fd1bf9_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redSurfaceGetPresentFeatures(_s_46fd1bf9_context context, _s_46fd1bf9_gpu gpu, _s_46fd1bf9_surface surface, _s_46fd1bf9_outSurfacePresentFeatures outSurfacePresentFeatures, _s_46fd1bf9_outStatuses outStatuses, _s_46fd1bf9_optionalFile optionalFile, _s_46fd1bf9_optionalLine optionalLine, _s_46fd1bf9_optionalUserData optionalUserData) {
  redSurfaceGetPresentFeatures(context.value, gpu.value, surface.value, outSurfacePresentFeatures.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redSurfaceGetCurrentPropertiesAndPresentLimits redSurfaceGetCurrentPropertiesAndPresentLimits
#define _c3dd4a0b_context(value) value
#define _c3dd4a0b_gpu(value) value
#define _c3dd4a0b_surface(value) value
#define _c3dd4a0b_outSurfaceCurrentPropertiesAndPresentLimits(value) value
#define _c3dd4a0b_outStatuses(value) value
#define _c3dd4a0b_optionalFile(value) value
#define _c3dd4a0b_optionalLine(value) value
#define _c3dd4a0b_optionalUserData(value) value
#else
typedef struct _s_c3dd4a0b_context { RedContext value; } _s_c3dd4a0b_context;
typedef struct _s_c3dd4a0b_gpu { RedHandleGpu value; } _s_c3dd4a0b_gpu;
typedef struct _s_c3dd4a0b_surface { RedHandleSurface value; } _s_c3dd4a0b_surface;
typedef struct _s_c3dd4a0b_outSurfaceCurrentPropertiesAndPresentLimits { RedSurfaceCurrentPropertiesAndPresentLimits* value; } _s_c3dd4a0b_outSurfaceCurrentPropertiesAndPresentLimits;
typedef struct _s_c3dd4a0b_outStatuses { RedStatuses* value; } _s_c3dd4a0b_outStatuses;
typedef struct _s_c3dd4a0b_optionalFile { char* value; } _s_c3dd4a0b_optionalFile;
typedef struct _s_c3dd4a0b_optionalLine { int value; } _s_c3dd4a0b_optionalLine;
typedef struct _s_c3dd4a0b_optionalUserData { void* value; } _s_c3dd4a0b_optionalUserData;
static inline _s_c3dd4a0b_context _c3dd4a0b_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_c3dd4a0b_context){value}; }
static inline _s_c3dd4a0b_gpu _c3dd4a0b_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_c3dd4a0b_gpu){value}; }
static inline _s_c3dd4a0b_surface _c3dd4a0b_surface(RedHandleSurface value) { return REDGPU_NP_STRUCT_INIT(_s_c3dd4a0b_surface){value}; }
static inline _s_c3dd4a0b_outSurfaceCurrentPropertiesAndPresentLimits _c3dd4a0b_outSurfaceCurrentPropertiesAndPresentLimits(RedSurfaceCurrentPropertiesAndPresentLimits* value) { return REDGPU_NP_STRUCT_INIT(_s_c3dd4a0b_outSurfaceCurrentPropertiesAndPresentLimits){value}; }
static inline _s_c3dd4a0b_outStatuses _c3dd4a0b_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_c3dd4a0b_outStatuses){value}; }
static inline _s_c3dd4a0b_optionalFile _c3dd4a0b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c3dd4a0b_optionalFile){value}; }
static inline _s_c3dd4a0b_optionalLine _c3dd4a0b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c3dd4a0b_optionalLine){value}; }
static inline _s_c3dd4a0b_optionalUserData _c3dd4a0b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c3dd4a0b_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redSurfaceGetCurrentPropertiesAndPresentLimits(_s_c3dd4a0b_context context, _s_c3dd4a0b_gpu gpu, _s_c3dd4a0b_surface surface, _s_c3dd4a0b_outSurfaceCurrentPropertiesAndPresentLimits outSurfaceCurrentPropertiesAndPresentLimits, _s_c3dd4a0b_outStatuses outStatuses, _s_c3dd4a0b_optionalFile optionalFile, _s_c3dd4a0b_optionalLine optionalLine, _s_c3dd4a0b_optionalUserData optionalUserData) {
  redSurfaceGetCurrentPropertiesAndPresentLimits(context.value, gpu.value, surface.value, outSurfaceCurrentPropertiesAndPresentLimits.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redPresentGetImageIndex redPresentGetImageIndex
#define _62720c7e_context(value) value
#define _62720c7e_gpu(value) value
#define _62720c7e_present(value) value
#define _62720c7e_signalCpuSignal(value) value
#define _62720c7e_signalGpuSignal(value) value
#define _62720c7e_outImageIndex(value) value
#define _62720c7e_outStatuses(value) value
#define _62720c7e_optionalFile(value) value
#define _62720c7e_optionalLine(value) value
#define _62720c7e_optionalUserData(value) value
#else
typedef struct _s_62720c7e_context { RedContext value; } _s_62720c7e_context;
typedef struct _s_62720c7e_gpu { RedHandleGpu value; } _s_62720c7e_gpu;
typedef struct _s_62720c7e_present { RedHandlePresent value; } _s_62720c7e_present;
typedef struct _s_62720c7e_signalCpuSignal { RedHandleCpuSignal value; } _s_62720c7e_signalCpuSignal;
typedef struct _s_62720c7e_signalGpuSignal { RedHandleGpuSignal value; } _s_62720c7e_signalGpuSignal;
typedef struct _s_62720c7e_outImageIndex { unsigned* value; } _s_62720c7e_outImageIndex;
typedef struct _s_62720c7e_outStatuses { RedStatuses* value; } _s_62720c7e_outStatuses;
typedef struct _s_62720c7e_optionalFile { char* value; } _s_62720c7e_optionalFile;
typedef struct _s_62720c7e_optionalLine { int value; } _s_62720c7e_optionalLine;
typedef struct _s_62720c7e_optionalUserData { void* value; } _s_62720c7e_optionalUserData;
static inline _s_62720c7e_context _62720c7e_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_62720c7e_context){value}; }
static inline _s_62720c7e_gpu _62720c7e_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_62720c7e_gpu){value}; }
static inline _s_62720c7e_present _62720c7e_present(RedHandlePresent value) { return REDGPU_NP_STRUCT_INIT(_s_62720c7e_present){value}; }
static inline _s_62720c7e_signalCpuSignal _62720c7e_signalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_62720c7e_signalCpuSignal){value}; }
static inline _s_62720c7e_signalGpuSignal _62720c7e_signalGpuSignal(RedHandleGpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_62720c7e_signalGpuSignal){value}; }
static inline _s_62720c7e_outImageIndex _62720c7e_outImageIndex(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_62720c7e_outImageIndex){value}; }
static inline _s_62720c7e_outStatuses _62720c7e_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_62720c7e_outStatuses){value}; }
static inline _s_62720c7e_optionalFile _62720c7e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_62720c7e_optionalFile){value}; }
static inline _s_62720c7e_optionalLine _62720c7e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_62720c7e_optionalLine){value}; }
static inline _s_62720c7e_optionalUserData _62720c7e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_62720c7e_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redPresentGetImageIndex(_s_62720c7e_context context, _s_62720c7e_gpu gpu, _s_62720c7e_present present, _s_62720c7e_signalCpuSignal signalCpuSignal, _s_62720c7e_signalGpuSignal signalGpuSignal, _s_62720c7e_outImageIndex outImageIndex, _s_62720c7e_outStatuses outStatuses, _s_62720c7e_optionalFile optionalFile, _s_62720c7e_optionalLine optionalLine, _s_62720c7e_optionalUserData optionalUserData) {
  redPresentGetImageIndex(context.value, gpu.value, present.value, signalCpuSignal.value, signalGpuSignal.value, outImageIndex.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redQueuePresent redQueuePresent
#define _73c9e772_context(value) value
#define _73c9e772_gpu(value) value
#define _73c9e772_queue(value) value
#define _73c9e772_waitForAndUnsignalGpuSignalsCount(value) value
#define _73c9e772_waitForAndUnsignalGpuSignals(value) value
#define _73c9e772_presentsCount(value) value
#define _73c9e772_presents(value) value
#define _73c9e772_presentsImageIndex(value) value
#define _73c9e772_outPresentsStatus(value) value
#define _73c9e772_outStatuses(value) value
#define _73c9e772_optionalFile(value) value
#define _73c9e772_optionalLine(value) value
#define _73c9e772_optionalUserData(value) value
#else
typedef struct _s_73c9e772_context { RedContext value; } _s_73c9e772_context;
typedef struct _s_73c9e772_gpu { RedHandleGpu value; } _s_73c9e772_gpu;
typedef struct _s_73c9e772_queue { RedHandleQueue value; } _s_73c9e772_queue;
typedef struct _s_73c9e772_waitForAndUnsignalGpuSignalsCount { unsigned value; } _s_73c9e772_waitForAndUnsignalGpuSignalsCount;
typedef struct _s_73c9e772_waitForAndUnsignalGpuSignals { RedHandleGpuSignal* value; } _s_73c9e772_waitForAndUnsignalGpuSignals;
typedef struct _s_73c9e772_presentsCount { unsigned value; } _s_73c9e772_presentsCount;
typedef struct _s_73c9e772_presents { RedHandlePresent* value; } _s_73c9e772_presents;
typedef struct _s_73c9e772_presentsImageIndex { unsigned* value; } _s_73c9e772_presentsImageIndex;
typedef struct _s_73c9e772_outPresentsStatus { RedStatus* value; } _s_73c9e772_outPresentsStatus;
typedef struct _s_73c9e772_outStatuses { RedStatuses* value; } _s_73c9e772_outStatuses;
typedef struct _s_73c9e772_optionalFile { char* value; } _s_73c9e772_optionalFile;
typedef struct _s_73c9e772_optionalLine { int value; } _s_73c9e772_optionalLine;
typedef struct _s_73c9e772_optionalUserData { void* value; } _s_73c9e772_optionalUserData;
static inline _s_73c9e772_context _73c9e772_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_context){value}; }
static inline _s_73c9e772_gpu _73c9e772_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_gpu){value}; }
static inline _s_73c9e772_queue _73c9e772_queue(RedHandleQueue value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_queue){value}; }
static inline _s_73c9e772_waitForAndUnsignalGpuSignalsCount _73c9e772_waitForAndUnsignalGpuSignalsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_waitForAndUnsignalGpuSignalsCount){value}; }
static inline _s_73c9e772_waitForAndUnsignalGpuSignals _73c9e772_waitForAndUnsignalGpuSignals(RedHandleGpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_waitForAndUnsignalGpuSignals){value}; }
static inline _s_73c9e772_presentsCount _73c9e772_presentsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_presentsCount){value}; }
static inline _s_73c9e772_presents _73c9e772_presents(RedHandlePresent* value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_presents){value}; }
static inline _s_73c9e772_presentsImageIndex _73c9e772_presentsImageIndex(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_presentsImageIndex){value}; }
static inline _s_73c9e772_outPresentsStatus _73c9e772_outPresentsStatus(RedStatus* value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_outPresentsStatus){value}; }
static inline _s_73c9e772_outStatuses _73c9e772_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_outStatuses){value}; }
static inline _s_73c9e772_optionalFile _73c9e772_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_optionalFile){value}; }
static inline _s_73c9e772_optionalLine _73c9e772_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_optionalLine){value}; }
static inline _s_73c9e772_optionalUserData _73c9e772_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_73c9e772_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redQueuePresent(_s_73c9e772_context context, _s_73c9e772_gpu gpu, _s_73c9e772_queue queue, _s_73c9e772_waitForAndUnsignalGpuSignalsCount waitForAndUnsignalGpuSignalsCount, _s_73c9e772_waitForAndUnsignalGpuSignals waitForAndUnsignalGpuSignals, _s_73c9e772_presentsCount presentsCount, _s_73c9e772_presents presents, _s_73c9e772_presentsImageIndex presentsImageIndex, _s_73c9e772_outPresentsStatus outPresentsStatus, _s_73c9e772_outStatuses outStatuses, _s_73c9e772_optionalFile optionalFile, _s_73c9e772_optionalLine optionalLine, _s_73c9e772_optionalUserData optionalUserData) {
  redQueuePresent(context.value, gpu.value, queue.value, waitForAndUnsignalGpuSignalsCount.value, waitForAndUnsignalGpuSignals.value, presentsCount.value, presents.value, presentsImageIndex.value, outPresentsStatus.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

