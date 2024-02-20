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
#define _976dd369_context(value) value
#define _976dd369_gpu(value) value
#define _976dd369_handleName(value) value
#define _976dd369_win32Hinstance(value) value
#define _976dd369_win32Hwnd(value) value
#define _976dd369_outSurface(value) value
#define _976dd369_outStatuses(value) value
#define _976dd369_optionalFile(value) value
#define _976dd369_optionalLine(value) value
#define _976dd369_optionalUserData(value) value
#else
typedef struct _s_976dd369_context { RedContext value; } _s_976dd369_context;
typedef struct _s_976dd369_gpu { RedHandleGpu value; } _s_976dd369_gpu;
typedef struct _s_976dd369_handleName { char* value; } _s_976dd369_handleName;
typedef struct _s_976dd369_win32Hinstance { void* value; } _s_976dd369_win32Hinstance;
typedef struct _s_976dd369_win32Hwnd { void* value; } _s_976dd369_win32Hwnd;
typedef struct _s_976dd369_outSurface { RedHandleSurface* value; } _s_976dd369_outSurface;
typedef struct _s_976dd369_outStatuses { RedStatuses* value; } _s_976dd369_outStatuses;
typedef struct _s_976dd369_optionalFile { char* value; } _s_976dd369_optionalFile;
typedef struct _s_976dd369_optionalLine { int value; } _s_976dd369_optionalLine;
typedef struct _s_976dd369_optionalUserData { void* value; } _s_976dd369_optionalUserData;
static inline _s_976dd369_context _976dd369_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_976dd369_context){value}; }
static inline _s_976dd369_gpu _976dd369_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_976dd369_gpu){value}; }
static inline _s_976dd369_handleName _976dd369_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_976dd369_handleName){value}; }
static inline _s_976dd369_win32Hinstance _976dd369_win32Hinstance(void* value) { return REDGPU_NP_STRUCT_INIT(_s_976dd369_win32Hinstance){value}; }
static inline _s_976dd369_win32Hwnd _976dd369_win32Hwnd(void* value) { return REDGPU_NP_STRUCT_INIT(_s_976dd369_win32Hwnd){value}; }
static inline _s_976dd369_outSurface _976dd369_outSurface(RedHandleSurface* value) { return REDGPU_NP_STRUCT_INIT(_s_976dd369_outSurface){value}; }
static inline _s_976dd369_outStatuses _976dd369_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_976dd369_outStatuses){value}; }
static inline _s_976dd369_optionalFile _976dd369_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_976dd369_optionalFile){value}; }
static inline _s_976dd369_optionalLine _976dd369_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_976dd369_optionalLine){value}; }
static inline _s_976dd369_optionalUserData _976dd369_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_976dd369_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateSurfaceWin32(_s_976dd369_context context, _s_976dd369_gpu gpu, _s_976dd369_handleName handleName, _s_976dd369_win32Hinstance win32Hinstance, _s_976dd369_win32Hwnd win32Hwnd, _s_976dd369_outSurface outSurface, _s_976dd369_outStatuses outStatuses, _s_976dd369_optionalFile optionalFile, _s_976dd369_optionalLine optionalLine, _s_976dd369_optionalUserData optionalUserData) {
  redCreateSurfaceWin32(context.value, gpu.value, handleName.value, win32Hinstance.value, win32Hwnd.value, outSurface.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreateSurfaceXlibOrXcb redCreateSurfaceXlibOrXcb
#define _86a3dd1a_context(value) value
#define _86a3dd1a_gpu(value) value
#define _86a3dd1a_handleName(value) value
#define _86a3dd1a_xlibDisplay(value) value
#define _86a3dd1a_xlibWindow(value) value
#define _86a3dd1a_xcbConnection(value) value
#define _86a3dd1a_xcbWindow(value) value
#define _86a3dd1a_outSurface(value) value
#define _86a3dd1a_outStatuses(value) value
#define _86a3dd1a_optionalFile(value) value
#define _86a3dd1a_optionalLine(value) value
#define _86a3dd1a_optionalUserData(value) value
#else
typedef struct _s_86a3dd1a_context { RedContext value; } _s_86a3dd1a_context;
typedef struct _s_86a3dd1a_gpu { RedHandleGpu value; } _s_86a3dd1a_gpu;
typedef struct _s_86a3dd1a_handleName { char* value; } _s_86a3dd1a_handleName;
typedef struct _s_86a3dd1a_xlibDisplay { void* value; } _s_86a3dd1a_xlibDisplay;
typedef struct _s_86a3dd1a_xlibWindow { uint64_t value; } _s_86a3dd1a_xlibWindow;
typedef struct _s_86a3dd1a_xcbConnection { void* value; } _s_86a3dd1a_xcbConnection;
typedef struct _s_86a3dd1a_xcbWindow { unsigned value; } _s_86a3dd1a_xcbWindow;
typedef struct _s_86a3dd1a_outSurface { RedHandleSurface* value; } _s_86a3dd1a_outSurface;
typedef struct _s_86a3dd1a_outStatuses { RedStatuses* value; } _s_86a3dd1a_outStatuses;
typedef struct _s_86a3dd1a_optionalFile { char* value; } _s_86a3dd1a_optionalFile;
typedef struct _s_86a3dd1a_optionalLine { int value; } _s_86a3dd1a_optionalLine;
typedef struct _s_86a3dd1a_optionalUserData { void* value; } _s_86a3dd1a_optionalUserData;
static inline _s_86a3dd1a_context _86a3dd1a_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_86a3dd1a_context){value}; }
static inline _s_86a3dd1a_gpu _86a3dd1a_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_86a3dd1a_gpu){value}; }
static inline _s_86a3dd1a_handleName _86a3dd1a_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_86a3dd1a_handleName){value}; }
static inline _s_86a3dd1a_xlibDisplay _86a3dd1a_xlibDisplay(void* value) { return REDGPU_NP_STRUCT_INIT(_s_86a3dd1a_xlibDisplay){value}; }
static inline _s_86a3dd1a_xlibWindow _86a3dd1a_xlibWindow(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_86a3dd1a_xlibWindow){value}; }
static inline _s_86a3dd1a_xcbConnection _86a3dd1a_xcbConnection(void* value) { return REDGPU_NP_STRUCT_INIT(_s_86a3dd1a_xcbConnection){value}; }
static inline _s_86a3dd1a_xcbWindow _86a3dd1a_xcbWindow(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_86a3dd1a_xcbWindow){value}; }
static inline _s_86a3dd1a_outSurface _86a3dd1a_outSurface(RedHandleSurface* value) { return REDGPU_NP_STRUCT_INIT(_s_86a3dd1a_outSurface){value}; }
static inline _s_86a3dd1a_outStatuses _86a3dd1a_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_86a3dd1a_outStatuses){value}; }
static inline _s_86a3dd1a_optionalFile _86a3dd1a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_86a3dd1a_optionalFile){value}; }
static inline _s_86a3dd1a_optionalLine _86a3dd1a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_86a3dd1a_optionalLine){value}; }
static inline _s_86a3dd1a_optionalUserData _86a3dd1a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_86a3dd1a_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateSurfaceXlibOrXcb(_s_86a3dd1a_context context, _s_86a3dd1a_gpu gpu, _s_86a3dd1a_handleName handleName, _s_86a3dd1a_xlibDisplay xlibDisplay, _s_86a3dd1a_xlibWindow xlibWindow, _s_86a3dd1a_xcbConnection xcbConnection, _s_86a3dd1a_xcbWindow xcbWindow, _s_86a3dd1a_outSurface outSurface, _s_86a3dd1a_outStatuses outStatuses, _s_86a3dd1a_optionalFile optionalFile, _s_86a3dd1a_optionalLine optionalLine, _s_86a3dd1a_optionalUserData optionalUserData) {
  redCreateSurfaceXlibOrXcb(context.value, gpu.value, handleName.value, xlibDisplay.value, xlibWindow.value, xcbConnection.value, xcbWindow.value, outSurface.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redCreatePresent redCreatePresent
#define _1b10d07d_context(value) value
#define _1b10d07d_gpu(value) value
#define _1b10d07d_queue(value) value
#define _1b10d07d_handleName(value) value
#define _1b10d07d_surface(value) value
#define _1b10d07d_imagesCount(value) value
#define _1b10d07d_imagesWidth(value) value
#define _1b10d07d_imagesHeight(value) value
#define _1b10d07d_imagesLayersCount(value) value
#define _1b10d07d_imagesRestrictToAccess(value) value
#define _1b10d07d_transform(value) value
#define _1b10d07d_compositeAlpha(value) value
#define _1b10d07d_vsyncMode(value) value
#define _1b10d07d_clipped(value) value
#define _1b10d07d_discardAfterPresent(value) value
#define _1b10d07d_oldPresent(value) value
#define _1b10d07d_outPresent(value) value
#define _1b10d07d_outImages(value) value
#define _1b10d07d_outTextures(value) value
#define _1b10d07d_outStatuses(value) value
#define _1b10d07d_optionalFile(value) value
#define _1b10d07d_optionalLine(value) value
#define _1b10d07d_optionalUserData(value) value
#else
typedef struct _s_1b10d07d_context { RedContext value; } _s_1b10d07d_context;
typedef struct _s_1b10d07d_gpu { RedHandleGpu value; } _s_1b10d07d_gpu;
typedef struct _s_1b10d07d_queue { RedHandleQueue value; } _s_1b10d07d_queue;
typedef struct _s_1b10d07d_handleName { char* value; } _s_1b10d07d_handleName;
typedef struct _s_1b10d07d_surface { RedHandleSurface value; } _s_1b10d07d_surface;
typedef struct _s_1b10d07d_imagesCount { unsigned value; } _s_1b10d07d_imagesCount;
typedef struct _s_1b10d07d_imagesWidth { unsigned value; } _s_1b10d07d_imagesWidth;
typedef struct _s_1b10d07d_imagesHeight { unsigned value; } _s_1b10d07d_imagesHeight;
typedef struct _s_1b10d07d_imagesLayersCount { unsigned value; } _s_1b10d07d_imagesLayersCount;
typedef struct _s_1b10d07d_imagesRestrictToAccess { RedAccessBitflags value; } _s_1b10d07d_imagesRestrictToAccess;
typedef struct _s_1b10d07d_transform { RedSurfaceTransformBitflag value; } _s_1b10d07d_transform;
typedef struct _s_1b10d07d_compositeAlpha { RedSurfaceCompositeAlphaBitflag value; } _s_1b10d07d_compositeAlpha;
typedef struct _s_1b10d07d_vsyncMode { RedPresentVsyncMode value; } _s_1b10d07d_vsyncMode;
typedef struct _s_1b10d07d_clipped { RedBool32 value; } _s_1b10d07d_clipped;
typedef struct _s_1b10d07d_discardAfterPresent { RedBool32 value; } _s_1b10d07d_discardAfterPresent;
typedef struct _s_1b10d07d_oldPresent { RedHandlePresent value; } _s_1b10d07d_oldPresent;
typedef struct _s_1b10d07d_outPresent { RedHandlePresent* value; } _s_1b10d07d_outPresent;
typedef struct _s_1b10d07d_outImages { RedHandleImage* value; } _s_1b10d07d_outImages;
typedef struct _s_1b10d07d_outTextures { RedHandleTexture* value; } _s_1b10d07d_outTextures;
typedef struct _s_1b10d07d_outStatuses { RedStatuses* value; } _s_1b10d07d_outStatuses;
typedef struct _s_1b10d07d_optionalFile { char* value; } _s_1b10d07d_optionalFile;
typedef struct _s_1b10d07d_optionalLine { int value; } _s_1b10d07d_optionalLine;
typedef struct _s_1b10d07d_optionalUserData { void* value; } _s_1b10d07d_optionalUserData;
static inline _s_1b10d07d_context _1b10d07d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_context){value}; }
static inline _s_1b10d07d_gpu _1b10d07d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_gpu){value}; }
static inline _s_1b10d07d_queue _1b10d07d_queue(RedHandleQueue value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_queue){value}; }
static inline _s_1b10d07d_handleName _1b10d07d_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_handleName){value}; }
static inline _s_1b10d07d_surface _1b10d07d_surface(RedHandleSurface value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_surface){value}; }
static inline _s_1b10d07d_imagesCount _1b10d07d_imagesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_imagesCount){value}; }
static inline _s_1b10d07d_imagesWidth _1b10d07d_imagesWidth(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_imagesWidth){value}; }
static inline _s_1b10d07d_imagesHeight _1b10d07d_imagesHeight(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_imagesHeight){value}; }
static inline _s_1b10d07d_imagesLayersCount _1b10d07d_imagesLayersCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_imagesLayersCount){value}; }
static inline _s_1b10d07d_imagesRestrictToAccess _1b10d07d_imagesRestrictToAccess(RedAccessBitflags value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_imagesRestrictToAccess){value}; }
static inline _s_1b10d07d_transform _1b10d07d_transform(RedSurfaceTransformBitflag value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_transform){value}; }
static inline _s_1b10d07d_compositeAlpha _1b10d07d_compositeAlpha(RedSurfaceCompositeAlphaBitflag value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_compositeAlpha){value}; }
static inline _s_1b10d07d_vsyncMode _1b10d07d_vsyncMode(RedPresentVsyncMode value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_vsyncMode){value}; }
static inline _s_1b10d07d_clipped _1b10d07d_clipped(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_clipped){value}; }
static inline _s_1b10d07d_discardAfterPresent _1b10d07d_discardAfterPresent(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_discardAfterPresent){value}; }
static inline _s_1b10d07d_oldPresent _1b10d07d_oldPresent(RedHandlePresent value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_oldPresent){value}; }
static inline _s_1b10d07d_outPresent _1b10d07d_outPresent(RedHandlePresent* value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_outPresent){value}; }
static inline _s_1b10d07d_outImages _1b10d07d_outImages(RedHandleImage* value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_outImages){value}; }
static inline _s_1b10d07d_outTextures _1b10d07d_outTextures(RedHandleTexture* value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_outTextures){value}; }
static inline _s_1b10d07d_outStatuses _1b10d07d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_outStatuses){value}; }
static inline _s_1b10d07d_optionalFile _1b10d07d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_optionalFile){value}; }
static inline _s_1b10d07d_optionalLine _1b10d07d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_optionalLine){value}; }
static inline _s_1b10d07d_optionalUserData _1b10d07d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1b10d07d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreatePresent(_s_1b10d07d_context context, _s_1b10d07d_gpu gpu, _s_1b10d07d_queue queue, _s_1b10d07d_handleName handleName, _s_1b10d07d_surface surface, _s_1b10d07d_imagesCount imagesCount, _s_1b10d07d_imagesWidth imagesWidth, _s_1b10d07d_imagesHeight imagesHeight, _s_1b10d07d_imagesLayersCount imagesLayersCount, _s_1b10d07d_imagesRestrictToAccess imagesRestrictToAccess, _s_1b10d07d_transform transform, _s_1b10d07d_compositeAlpha compositeAlpha, _s_1b10d07d_vsyncMode vsyncMode, _s_1b10d07d_clipped clipped, _s_1b10d07d_discardAfterPresent discardAfterPresent, _s_1b10d07d_oldPresent oldPresent, _s_1b10d07d_outPresent outPresent, _s_1b10d07d_outImages outImages, _s_1b10d07d_outTextures outTextures, _s_1b10d07d_outStatuses outStatuses, _s_1b10d07d_optionalFile optionalFile, _s_1b10d07d_optionalLine optionalLine, _s_1b10d07d_optionalUserData optionalUserData) {
  redCreatePresent(context.value, gpu.value, queue.value, handleName.value, surface.value, imagesCount.value, imagesWidth.value, imagesHeight.value, imagesLayersCount.value, imagesRestrictToAccess.value, transform.value, compositeAlpha.value, vsyncMode.value, clipped.value, discardAfterPresent.value, oldPresent.value, outPresent.value, outImages.value, outTextures.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroySurface redDestroySurface
#define _5fc7e092_context(value) value
#define _5fc7e092_gpu(value) value
#define _5fc7e092_surface(value) value
#define _5fc7e092_optionalFile(value) value
#define _5fc7e092_optionalLine(value) value
#define _5fc7e092_optionalUserData(value) value
#else
typedef struct _s_5fc7e092_context { RedContext value; } _s_5fc7e092_context;
typedef struct _s_5fc7e092_gpu { RedHandleGpu value; } _s_5fc7e092_gpu;
typedef struct _s_5fc7e092_surface { RedHandleSurface value; } _s_5fc7e092_surface;
typedef struct _s_5fc7e092_optionalFile { char* value; } _s_5fc7e092_optionalFile;
typedef struct _s_5fc7e092_optionalLine { int value; } _s_5fc7e092_optionalLine;
typedef struct _s_5fc7e092_optionalUserData { void* value; } _s_5fc7e092_optionalUserData;
static inline _s_5fc7e092_context _5fc7e092_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_5fc7e092_context){value}; }
static inline _s_5fc7e092_gpu _5fc7e092_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_5fc7e092_gpu){value}; }
static inline _s_5fc7e092_surface _5fc7e092_surface(RedHandleSurface value) { return REDGPU_NP_STRUCT_INIT(_s_5fc7e092_surface){value}; }
static inline _s_5fc7e092_optionalFile _5fc7e092_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5fc7e092_optionalFile){value}; }
static inline _s_5fc7e092_optionalLine _5fc7e092_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5fc7e092_optionalLine){value}; }
static inline _s_5fc7e092_optionalUserData _5fc7e092_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5fc7e092_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroySurface(_s_5fc7e092_context context, _s_5fc7e092_gpu gpu, _s_5fc7e092_surface surface, _s_5fc7e092_optionalFile optionalFile, _s_5fc7e092_optionalLine optionalLine, _s_5fc7e092_optionalUserData optionalUserData) {
  redDestroySurface(context.value, gpu.value, surface.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redDestroyPresent redDestroyPresent
#define _c3c397b9_context(value) value
#define _c3c397b9_gpu(value) value
#define _c3c397b9_present(value) value
#define _c3c397b9_optionalFile(value) value
#define _c3c397b9_optionalLine(value) value
#define _c3c397b9_optionalUserData(value) value
#else
typedef struct _s_c3c397b9_context { RedContext value; } _s_c3c397b9_context;
typedef struct _s_c3c397b9_gpu { RedHandleGpu value; } _s_c3c397b9_gpu;
typedef struct _s_c3c397b9_present { RedHandlePresent value; } _s_c3c397b9_present;
typedef struct _s_c3c397b9_optionalFile { char* value; } _s_c3c397b9_optionalFile;
typedef struct _s_c3c397b9_optionalLine { int value; } _s_c3c397b9_optionalLine;
typedef struct _s_c3c397b9_optionalUserData { void* value; } _s_c3c397b9_optionalUserData;
static inline _s_c3c397b9_context _c3c397b9_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_c3c397b9_context){value}; }
static inline _s_c3c397b9_gpu _c3c397b9_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_c3c397b9_gpu){value}; }
static inline _s_c3c397b9_present _c3c397b9_present(RedHandlePresent value) { return REDGPU_NP_STRUCT_INIT(_s_c3c397b9_present){value}; }
static inline _s_c3c397b9_optionalFile _c3c397b9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c3c397b9_optionalFile){value}; }
static inline _s_c3c397b9_optionalLine _c3c397b9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c3c397b9_optionalLine){value}; }
static inline _s_c3c397b9_optionalUserData _c3c397b9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c3c397b9_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redDestroyPresent(_s_c3c397b9_context context, _s_c3c397b9_gpu gpu, _s_c3c397b9_present present, _s_c3c397b9_optionalFile optionalFile, _s_c3c397b9_optionalLine optionalLine, _s_c3c397b9_optionalUserData optionalUserData) {
  redDestroyPresent(context.value, gpu.value, present.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redQueueFamilyIndexGetSupportsPresent redQueueFamilyIndexGetSupportsPresent
#define _da8da169_context(value) value
#define _da8da169_gpu(value) value
#define _da8da169_queueFamilyIndex(value) value
#define _da8da169_supportsPresentOnWin32(value) value
#define _da8da169_supportsPresentOnXlib(value) value
#define _da8da169_supportsPresentOnXcb(value) value
#define _da8da169_supportsPresentOnSurface(value) value
#define _da8da169_outStatuses(value) value
#define _da8da169_optionalFile(value) value
#define _da8da169_optionalLine(value) value
#define _da8da169_optionalUserData(value) value
#else
typedef struct _s_da8da169_context { RedContext value; } _s_da8da169_context;
typedef struct _s_da8da169_gpu { RedHandleGpu value; } _s_da8da169_gpu;
typedef struct _s_da8da169_queueFamilyIndex { unsigned value; } _s_da8da169_queueFamilyIndex;
typedef struct _s_da8da169_supportsPresentOnWin32 { RedQueueFamilyIndexGetSupportsPresentOnWin32* value; } _s_da8da169_supportsPresentOnWin32;
typedef struct _s_da8da169_supportsPresentOnXlib { RedQueueFamilyIndexGetSupportsPresentOnXlib* value; } _s_da8da169_supportsPresentOnXlib;
typedef struct _s_da8da169_supportsPresentOnXcb { RedQueueFamilyIndexGetSupportsPresentOnXcb* value; } _s_da8da169_supportsPresentOnXcb;
typedef struct _s_da8da169_supportsPresentOnSurface { RedQueueFamilyIndexGetSupportsPresentOnSurface* value; } _s_da8da169_supportsPresentOnSurface;
typedef struct _s_da8da169_outStatuses { RedStatuses* value; } _s_da8da169_outStatuses;
typedef struct _s_da8da169_optionalFile { char* value; } _s_da8da169_optionalFile;
typedef struct _s_da8da169_optionalLine { int value; } _s_da8da169_optionalLine;
typedef struct _s_da8da169_optionalUserData { void* value; } _s_da8da169_optionalUserData;
static inline _s_da8da169_context _da8da169_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_da8da169_context){value}; }
static inline _s_da8da169_gpu _da8da169_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_da8da169_gpu){value}; }
static inline _s_da8da169_queueFamilyIndex _da8da169_queueFamilyIndex(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_da8da169_queueFamilyIndex){value}; }
static inline _s_da8da169_supportsPresentOnWin32 _da8da169_supportsPresentOnWin32(RedQueueFamilyIndexGetSupportsPresentOnWin32* value) { return REDGPU_NP_STRUCT_INIT(_s_da8da169_supportsPresentOnWin32){value}; }
static inline _s_da8da169_supportsPresentOnXlib _da8da169_supportsPresentOnXlib(RedQueueFamilyIndexGetSupportsPresentOnXlib* value) { return REDGPU_NP_STRUCT_INIT(_s_da8da169_supportsPresentOnXlib){value}; }
static inline _s_da8da169_supportsPresentOnXcb _da8da169_supportsPresentOnXcb(RedQueueFamilyIndexGetSupportsPresentOnXcb* value) { return REDGPU_NP_STRUCT_INIT(_s_da8da169_supportsPresentOnXcb){value}; }
static inline _s_da8da169_supportsPresentOnSurface _da8da169_supportsPresentOnSurface(RedQueueFamilyIndexGetSupportsPresentOnSurface* value) { return REDGPU_NP_STRUCT_INIT(_s_da8da169_supportsPresentOnSurface){value}; }
static inline _s_da8da169_outStatuses _da8da169_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_da8da169_outStatuses){value}; }
static inline _s_da8da169_optionalFile _da8da169_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_da8da169_optionalFile){value}; }
static inline _s_da8da169_optionalLine _da8da169_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_da8da169_optionalLine){value}; }
static inline _s_da8da169_optionalUserData _da8da169_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_da8da169_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redQueueFamilyIndexGetSupportsPresent(_s_da8da169_context context, _s_da8da169_gpu gpu, _s_da8da169_queueFamilyIndex queueFamilyIndex, _s_da8da169_supportsPresentOnWin32 supportsPresentOnWin32, _s_da8da169_supportsPresentOnXlib supportsPresentOnXlib, _s_da8da169_supportsPresentOnXcb supportsPresentOnXcb, _s_da8da169_supportsPresentOnSurface supportsPresentOnSurface, _s_da8da169_outStatuses outStatuses, _s_da8da169_optionalFile optionalFile, _s_da8da169_optionalLine optionalLine, _s_da8da169_optionalUserData optionalUserData) {
  redQueueFamilyIndexGetSupportsPresent(context.value, gpu.value, queueFamilyIndex.value, supportsPresentOnWin32.value, supportsPresentOnXlib.value, supportsPresentOnXcb.value, supportsPresentOnSurface.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redSurfaceGetPresentFeatures redSurfaceGetPresentFeatures
#define _7ac8007d_context(value) value
#define _7ac8007d_gpu(value) value
#define _7ac8007d_surface(value) value
#define _7ac8007d_outSurfacePresentFeatures(value) value
#define _7ac8007d_outStatuses(value) value
#define _7ac8007d_optionalFile(value) value
#define _7ac8007d_optionalLine(value) value
#define _7ac8007d_optionalUserData(value) value
#else
typedef struct _s_7ac8007d_context { RedContext value; } _s_7ac8007d_context;
typedef struct _s_7ac8007d_gpu { RedHandleGpu value; } _s_7ac8007d_gpu;
typedef struct _s_7ac8007d_surface { RedHandleSurface value; } _s_7ac8007d_surface;
typedef struct _s_7ac8007d_outSurfacePresentFeatures { RedSurfacePresentFeatures* value; } _s_7ac8007d_outSurfacePresentFeatures;
typedef struct _s_7ac8007d_outStatuses { RedStatuses* value; } _s_7ac8007d_outStatuses;
typedef struct _s_7ac8007d_optionalFile { char* value; } _s_7ac8007d_optionalFile;
typedef struct _s_7ac8007d_optionalLine { int value; } _s_7ac8007d_optionalLine;
typedef struct _s_7ac8007d_optionalUserData { void* value; } _s_7ac8007d_optionalUserData;
static inline _s_7ac8007d_context _7ac8007d_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_7ac8007d_context){value}; }
static inline _s_7ac8007d_gpu _7ac8007d_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_7ac8007d_gpu){value}; }
static inline _s_7ac8007d_surface _7ac8007d_surface(RedHandleSurface value) { return REDGPU_NP_STRUCT_INIT(_s_7ac8007d_surface){value}; }
static inline _s_7ac8007d_outSurfacePresentFeatures _7ac8007d_outSurfacePresentFeatures(RedSurfacePresentFeatures* value) { return REDGPU_NP_STRUCT_INIT(_s_7ac8007d_outSurfacePresentFeatures){value}; }
static inline _s_7ac8007d_outStatuses _7ac8007d_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_7ac8007d_outStatuses){value}; }
static inline _s_7ac8007d_optionalFile _7ac8007d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7ac8007d_optionalFile){value}; }
static inline _s_7ac8007d_optionalLine _7ac8007d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7ac8007d_optionalLine){value}; }
static inline _s_7ac8007d_optionalUserData _7ac8007d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7ac8007d_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redSurfaceGetPresentFeatures(_s_7ac8007d_context context, _s_7ac8007d_gpu gpu, _s_7ac8007d_surface surface, _s_7ac8007d_outSurfacePresentFeatures outSurfacePresentFeatures, _s_7ac8007d_outStatuses outStatuses, _s_7ac8007d_optionalFile optionalFile, _s_7ac8007d_optionalLine optionalLine, _s_7ac8007d_optionalUserData optionalUserData) {
  redSurfaceGetPresentFeatures(context.value, gpu.value, surface.value, outSurfacePresentFeatures.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redSurfaceGetCurrentPropertiesAndPresentLimits redSurfaceGetCurrentPropertiesAndPresentLimits
#define _cf46f9e2_context(value) value
#define _cf46f9e2_gpu(value) value
#define _cf46f9e2_surface(value) value
#define _cf46f9e2_outSurfaceCurrentPropertiesAndPresentLimits(value) value
#define _cf46f9e2_outStatuses(value) value
#define _cf46f9e2_optionalFile(value) value
#define _cf46f9e2_optionalLine(value) value
#define _cf46f9e2_optionalUserData(value) value
#else
typedef struct _s_cf46f9e2_context { RedContext value; } _s_cf46f9e2_context;
typedef struct _s_cf46f9e2_gpu { RedHandleGpu value; } _s_cf46f9e2_gpu;
typedef struct _s_cf46f9e2_surface { RedHandleSurface value; } _s_cf46f9e2_surface;
typedef struct _s_cf46f9e2_outSurfaceCurrentPropertiesAndPresentLimits { RedSurfaceCurrentPropertiesAndPresentLimits* value; } _s_cf46f9e2_outSurfaceCurrentPropertiesAndPresentLimits;
typedef struct _s_cf46f9e2_outStatuses { RedStatuses* value; } _s_cf46f9e2_outStatuses;
typedef struct _s_cf46f9e2_optionalFile { char* value; } _s_cf46f9e2_optionalFile;
typedef struct _s_cf46f9e2_optionalLine { int value; } _s_cf46f9e2_optionalLine;
typedef struct _s_cf46f9e2_optionalUserData { void* value; } _s_cf46f9e2_optionalUserData;
static inline _s_cf46f9e2_context _cf46f9e2_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_cf46f9e2_context){value}; }
static inline _s_cf46f9e2_gpu _cf46f9e2_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_cf46f9e2_gpu){value}; }
static inline _s_cf46f9e2_surface _cf46f9e2_surface(RedHandleSurface value) { return REDGPU_NP_STRUCT_INIT(_s_cf46f9e2_surface){value}; }
static inline _s_cf46f9e2_outSurfaceCurrentPropertiesAndPresentLimits _cf46f9e2_outSurfaceCurrentPropertiesAndPresentLimits(RedSurfaceCurrentPropertiesAndPresentLimits* value) { return REDGPU_NP_STRUCT_INIT(_s_cf46f9e2_outSurfaceCurrentPropertiesAndPresentLimits){value}; }
static inline _s_cf46f9e2_outStatuses _cf46f9e2_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_cf46f9e2_outStatuses){value}; }
static inline _s_cf46f9e2_optionalFile _cf46f9e2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cf46f9e2_optionalFile){value}; }
static inline _s_cf46f9e2_optionalLine _cf46f9e2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cf46f9e2_optionalLine){value}; }
static inline _s_cf46f9e2_optionalUserData _cf46f9e2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cf46f9e2_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redSurfaceGetCurrentPropertiesAndPresentLimits(_s_cf46f9e2_context context, _s_cf46f9e2_gpu gpu, _s_cf46f9e2_surface surface, _s_cf46f9e2_outSurfaceCurrentPropertiesAndPresentLimits outSurfaceCurrentPropertiesAndPresentLimits, _s_cf46f9e2_outStatuses outStatuses, _s_cf46f9e2_optionalFile optionalFile, _s_cf46f9e2_optionalLine optionalLine, _s_cf46f9e2_optionalUserData optionalUserData) {
  redSurfaceGetCurrentPropertiesAndPresentLimits(context.value, gpu.value, surface.value, outSurfaceCurrentPropertiesAndPresentLimits.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redPresentGetImageIndex redPresentGetImageIndex
#define _0850d50a_context(value) value
#define _0850d50a_gpu(value) value
#define _0850d50a_present(value) value
#define _0850d50a_signalCpuSignal(value) value
#define _0850d50a_signalGpuSignal(value) value
#define _0850d50a_outImageIndex(value) value
#define _0850d50a_outStatuses(value) value
#define _0850d50a_optionalFile(value) value
#define _0850d50a_optionalLine(value) value
#define _0850d50a_optionalUserData(value) value
#else
typedef struct _s_0850d50a_context { RedContext value; } _s_0850d50a_context;
typedef struct _s_0850d50a_gpu { RedHandleGpu value; } _s_0850d50a_gpu;
typedef struct _s_0850d50a_present { RedHandlePresent value; } _s_0850d50a_present;
typedef struct _s_0850d50a_signalCpuSignal { RedHandleCpuSignal value; } _s_0850d50a_signalCpuSignal;
typedef struct _s_0850d50a_signalGpuSignal { RedHandleGpuSignal value; } _s_0850d50a_signalGpuSignal;
typedef struct _s_0850d50a_outImageIndex { unsigned* value; } _s_0850d50a_outImageIndex;
typedef struct _s_0850d50a_outStatuses { RedStatuses* value; } _s_0850d50a_outStatuses;
typedef struct _s_0850d50a_optionalFile { char* value; } _s_0850d50a_optionalFile;
typedef struct _s_0850d50a_optionalLine { int value; } _s_0850d50a_optionalLine;
typedef struct _s_0850d50a_optionalUserData { void* value; } _s_0850d50a_optionalUserData;
static inline _s_0850d50a_context _0850d50a_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_0850d50a_context){value}; }
static inline _s_0850d50a_gpu _0850d50a_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_0850d50a_gpu){value}; }
static inline _s_0850d50a_present _0850d50a_present(RedHandlePresent value) { return REDGPU_NP_STRUCT_INIT(_s_0850d50a_present){value}; }
static inline _s_0850d50a_signalCpuSignal _0850d50a_signalCpuSignal(RedHandleCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_0850d50a_signalCpuSignal){value}; }
static inline _s_0850d50a_signalGpuSignal _0850d50a_signalGpuSignal(RedHandleGpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_0850d50a_signalGpuSignal){value}; }
static inline _s_0850d50a_outImageIndex _0850d50a_outImageIndex(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_0850d50a_outImageIndex){value}; }
static inline _s_0850d50a_outStatuses _0850d50a_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_0850d50a_outStatuses){value}; }
static inline _s_0850d50a_optionalFile _0850d50a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0850d50a_optionalFile){value}; }
static inline _s_0850d50a_optionalLine _0850d50a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0850d50a_optionalLine){value}; }
static inline _s_0850d50a_optionalUserData _0850d50a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0850d50a_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redPresentGetImageIndex(_s_0850d50a_context context, _s_0850d50a_gpu gpu, _s_0850d50a_present present, _s_0850d50a_signalCpuSignal signalCpuSignal, _s_0850d50a_signalGpuSignal signalGpuSignal, _s_0850d50a_outImageIndex outImageIndex, _s_0850d50a_outStatuses outStatuses, _s_0850d50a_optionalFile optionalFile, _s_0850d50a_optionalLine optionalLine, _s_0850d50a_optionalUserData optionalUserData) {
  redPresentGetImageIndex(context.value, gpu.value, present.value, signalCpuSignal.value, signalGpuSignal.value, outImageIndex.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redQueuePresent redQueuePresent
#define _e942825c_context(value) value
#define _e942825c_gpu(value) value
#define _e942825c_queue(value) value
#define _e942825c_waitForAndUnsignalGpuSignalsCount(value) value
#define _e942825c_waitForAndUnsignalGpuSignals(value) value
#define _e942825c_presentsCount(value) value
#define _e942825c_presents(value) value
#define _e942825c_presentsImageIndex(value) value
#define _e942825c_outPresentsStatus(value) value
#define _e942825c_outStatuses(value) value
#define _e942825c_optionalFile(value) value
#define _e942825c_optionalLine(value) value
#define _e942825c_optionalUserData(value) value
#else
typedef struct _s_e942825c_context { RedContext value; } _s_e942825c_context;
typedef struct _s_e942825c_gpu { RedHandleGpu value; } _s_e942825c_gpu;
typedef struct _s_e942825c_queue { RedHandleQueue value; } _s_e942825c_queue;
typedef struct _s_e942825c_waitForAndUnsignalGpuSignalsCount { unsigned value; } _s_e942825c_waitForAndUnsignalGpuSignalsCount;
typedef struct _s_e942825c_waitForAndUnsignalGpuSignals { RedHandleGpuSignal* value; } _s_e942825c_waitForAndUnsignalGpuSignals;
typedef struct _s_e942825c_presentsCount { unsigned value; } _s_e942825c_presentsCount;
typedef struct _s_e942825c_presents { RedHandlePresent* value; } _s_e942825c_presents;
typedef struct _s_e942825c_presentsImageIndex { unsigned* value; } _s_e942825c_presentsImageIndex;
typedef struct _s_e942825c_outPresentsStatus { RedStatus* value; } _s_e942825c_outPresentsStatus;
typedef struct _s_e942825c_outStatuses { RedStatuses* value; } _s_e942825c_outStatuses;
typedef struct _s_e942825c_optionalFile { char* value; } _s_e942825c_optionalFile;
typedef struct _s_e942825c_optionalLine { int value; } _s_e942825c_optionalLine;
typedef struct _s_e942825c_optionalUserData { void* value; } _s_e942825c_optionalUserData;
static inline _s_e942825c_context _e942825c_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_context){value}; }
static inline _s_e942825c_gpu _e942825c_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_gpu){value}; }
static inline _s_e942825c_queue _e942825c_queue(RedHandleQueue value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_queue){value}; }
static inline _s_e942825c_waitForAndUnsignalGpuSignalsCount _e942825c_waitForAndUnsignalGpuSignalsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_waitForAndUnsignalGpuSignalsCount){value}; }
static inline _s_e942825c_waitForAndUnsignalGpuSignals _e942825c_waitForAndUnsignalGpuSignals(RedHandleGpuSignal* value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_waitForAndUnsignalGpuSignals){value}; }
static inline _s_e942825c_presentsCount _e942825c_presentsCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_presentsCount){value}; }
static inline _s_e942825c_presents _e942825c_presents(RedHandlePresent* value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_presents){value}; }
static inline _s_e942825c_presentsImageIndex _e942825c_presentsImageIndex(unsigned* value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_presentsImageIndex){value}; }
static inline _s_e942825c_outPresentsStatus _e942825c_outPresentsStatus(RedStatus* value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_outPresentsStatus){value}; }
static inline _s_e942825c_outStatuses _e942825c_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_outStatuses){value}; }
static inline _s_e942825c_optionalFile _e942825c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_optionalFile){value}; }
static inline _s_e942825c_optionalLine _e942825c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_optionalLine){value}; }
static inline _s_e942825c_optionalUserData _e942825c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_e942825c_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redQueuePresent(_s_e942825c_context context, _s_e942825c_gpu gpu, _s_e942825c_queue queue, _s_e942825c_waitForAndUnsignalGpuSignalsCount waitForAndUnsignalGpuSignalsCount, _s_e942825c_waitForAndUnsignalGpuSignals waitForAndUnsignalGpuSignals, _s_e942825c_presentsCount presentsCount, _s_e942825c_presents presents, _s_e942825c_presentsImageIndex presentsImageIndex, _s_e942825c_outPresentsStatus outPresentsStatus, _s_e942825c_outStatuses outStatuses, _s_e942825c_optionalFile optionalFile, _s_e942825c_optionalLine optionalLine, _s_e942825c_optionalUserData optionalUserData) {
  redQueuePresent(context.value, gpu.value, queue.value, waitForAndUnsignalGpuSignalsCount.value, waitForAndUnsignalGpuSignals.value, presentsCount.value, presents.value, presentsImageIndex.value, outPresentsStatus.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

