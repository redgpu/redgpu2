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
#define np_void void
#define _7b02b7a9_RedContext(value) value
#define _7b02b7a9_RedHandleGpu(value) value
#define _7b02b7a9_void*(value) value
#define _7b02b7a9_RedXHandleMemoryCallbackBudgetChange*(value) value
#define _7b02b7a9_RedStatuses*(value) value
#define _7b02b7a9_char*(value) value
#define _7b02b7a9_int(value) value
#define _7b02b7a9_void*(value) value
#define _7b02b7a9_(value) value
#else
typedef struct _s_7b02b7a9_RedContext { redXMemoryCallbackBudgetChangeRegister value; } _s_7b02b7a9_RedContext;
typedef struct _s_7b02b7a9_RedHandleGpu { context value; } _s_7b02b7a9_RedHandleGpu;
typedef struct _s_7b02b7a9_void* { gpu value; } _s_7b02b7a9_void*;
typedef struct _s_7b02b7a9_RedXHandleMemoryCallbackBudgetChange* { eventHandle value; } _s_7b02b7a9_RedXHandleMemoryCallbackBudgetChange*;
typedef struct _s_7b02b7a9_RedStatuses* { outMemoryCallbackBudgetChange value; } _s_7b02b7a9_RedStatuses*;
typedef struct _s_7b02b7a9_char* { outStatuses value; } _s_7b02b7a9_char*;
typedef struct _s_7b02b7a9_int { optionalFile value; } _s_7b02b7a9_int;
typedef struct _s_7b02b7a9_void* { optionalLine value; } _s_7b02b7a9_void*;
typedef struct _s_7b02b7a9_ { optionalUserData value; } _s_7b02b7a9_;
static inline _s_7b02b7a9_RedContext _7b02b7a9_RedContext(redXMemoryCallbackBudgetChangeRegister value) { return REDGPU_NP_STRUCT_INIT(_s_7b02b7a9_RedContext){value}; }
static inline _s_7b02b7a9_RedHandleGpu _7b02b7a9_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_7b02b7a9_RedHandleGpu){value}; }
static inline _s_7b02b7a9_void* _7b02b7a9_void*(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_7b02b7a9_void*){value}; }
static inline _s_7b02b7a9_RedXHandleMemoryCallbackBudgetChange* _7b02b7a9_RedXHandleMemoryCallbackBudgetChange*(eventHandle value) { return REDGPU_NP_STRUCT_INIT(_s_7b02b7a9_RedXHandleMemoryCallbackBudgetChange*){value}; }
static inline _s_7b02b7a9_RedStatuses* _7b02b7a9_RedStatuses*(outMemoryCallbackBudgetChange value) { return REDGPU_NP_STRUCT_INIT(_s_7b02b7a9_RedStatuses*){value}; }
static inline _s_7b02b7a9_char* _7b02b7a9_char*(outStatuses value) { return REDGPU_NP_STRUCT_INIT(_s_7b02b7a9_char*){value}; }
static inline _s_7b02b7a9_int _7b02b7a9_int(optionalFile value) { return REDGPU_NP_STRUCT_INIT(_s_7b02b7a9_int){value}; }
static inline _s_7b02b7a9_void* _7b02b7a9_void*(optionalLine value) { return REDGPU_NP_STRUCT_INIT(_s_7b02b7a9_void*){value}; }
static inline _s_7b02b7a9_ _7b02b7a9_(optionalUserData value) { return REDGPU_NP_STRUCT_INIT(_s_7b02b7a9_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_7b02b7a9_RedContext RedContext, _s_7b02b7a9_RedHandleGpu RedHandleGpu, _s_7b02b7a9_void* void*, _s_7b02b7a9_RedXHandleMemoryCallbackBudgetChange* RedXHandleMemoryCallbackBudgetChange*, _s_7b02b7a9_RedStatuses* RedStatuses*, _s_7b02b7a9_char* char*, _s_7b02b7a9_int int, _s_7b02b7a9_void* void*, _s_7b02b7a9_ ) {
  return void(RedContext.value, RedHandleGpu.value, void*.value, RedXHandleMemoryCallbackBudgetChange*.value, RedStatuses*.value, char*.value, int.value, void*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _c2045a3f_RedContext(value) value
#define _c2045a3f_RedHandleGpu(value) value
#define _c2045a3f_RedXHandleMemoryCallbackBudgetChange(value) value
#define _c2045a3f_char*(value) value
#define _c2045a3f_int(value) value
#define _c2045a3f_void*(value) value
#define _c2045a3f_(value) value
#else
typedef struct _s_c2045a3f_RedContext { redXMemoryCallbackBudgetChangeUnregister value; } _s_c2045a3f_RedContext;
typedef struct _s_c2045a3f_RedHandleGpu { context value; } _s_c2045a3f_RedHandleGpu;
typedef struct _s_c2045a3f_RedXHandleMemoryCallbackBudgetChange { gpu value; } _s_c2045a3f_RedXHandleMemoryCallbackBudgetChange;
typedef struct _s_c2045a3f_char* { memoryCallbackBudgetChange value; } _s_c2045a3f_char*;
typedef struct _s_c2045a3f_int { optionalFile value; } _s_c2045a3f_int;
typedef struct _s_c2045a3f_void* { optionalLine value; } _s_c2045a3f_void*;
typedef struct _s_c2045a3f_ { optionalUserData value; } _s_c2045a3f_;
static inline _s_c2045a3f_RedContext _c2045a3f_RedContext(redXMemoryCallbackBudgetChangeUnregister value) { return REDGPU_NP_STRUCT_INIT(_s_c2045a3f_RedContext){value}; }
static inline _s_c2045a3f_RedHandleGpu _c2045a3f_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_c2045a3f_RedHandleGpu){value}; }
static inline _s_c2045a3f_RedXHandleMemoryCallbackBudgetChange _c2045a3f_RedXHandleMemoryCallbackBudgetChange(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_c2045a3f_RedXHandleMemoryCallbackBudgetChange){value}; }
static inline _s_c2045a3f_char* _c2045a3f_char*(memoryCallbackBudgetChange value) { return REDGPU_NP_STRUCT_INIT(_s_c2045a3f_char*){value}; }
static inline _s_c2045a3f_int _c2045a3f_int(optionalFile value) { return REDGPU_NP_STRUCT_INIT(_s_c2045a3f_int){value}; }
static inline _s_c2045a3f_void* _c2045a3f_void*(optionalLine value) { return REDGPU_NP_STRUCT_INIT(_s_c2045a3f_void*){value}; }
static inline _s_c2045a3f_ _c2045a3f_(optionalUserData value) { return REDGPU_NP_STRUCT_INIT(_s_c2045a3f_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_c2045a3f_RedContext RedContext, _s_c2045a3f_RedHandleGpu RedHandleGpu, _s_c2045a3f_RedXHandleMemoryCallbackBudgetChange RedXHandleMemoryCallbackBudgetChange, _s_c2045a3f_char* char*, _s_c2045a3f_int int, _s_c2045a3f_void* void*, _s_c2045a3f_ ) {
  return void(RedContext.value, RedHandleGpu.value, RedXHandleMemoryCallbackBudgetChange.value, char*.value, int.value, void*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _f208f968_RedContext(value) value
#define _f208f968_RedHandleGpu(value) value
#define _f208f968_RedBool32(value) value
#define _f208f968_uint64_t(value) value
#define _f208f968_RedStatuses*(value) value
#define _f208f968_char*(value) value
#define _f208f968_int(value) value
#define _f208f968_void*(value) value
#define _f208f968_(value) value
#else
typedef struct _s_f208f968_RedContext { redXMemoryReserve value; } _s_f208f968_RedContext;
typedef struct _s_f208f968_RedHandleGpu { context value; } _s_f208f968_RedHandleGpu;
typedef struct _s_f208f968_RedBool32 { gpu value; } _s_f208f968_RedBool32;
typedef struct _s_f208f968_uint64_t { sharedMemory value; } _s_f208f968_uint64_t;
typedef struct _s_f208f968_RedStatuses* { bytesCount value; } _s_f208f968_RedStatuses*;
typedef struct _s_f208f968_char* { outStatuses value; } _s_f208f968_char*;
typedef struct _s_f208f968_int { optionalFile value; } _s_f208f968_int;
typedef struct _s_f208f968_void* { optionalLine value; } _s_f208f968_void*;
typedef struct _s_f208f968_ { optionalUserData value; } _s_f208f968_;
static inline _s_f208f968_RedContext _f208f968_RedContext(redXMemoryReserve value) { return REDGPU_NP_STRUCT_INIT(_s_f208f968_RedContext){value}; }
static inline _s_f208f968_RedHandleGpu _f208f968_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_f208f968_RedHandleGpu){value}; }
static inline _s_f208f968_RedBool32 _f208f968_RedBool32(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_f208f968_RedBool32){value}; }
static inline _s_f208f968_uint64_t _f208f968_uint64_t(sharedMemory value) { return REDGPU_NP_STRUCT_INIT(_s_f208f968_uint64_t){value}; }
static inline _s_f208f968_RedStatuses* _f208f968_RedStatuses*(bytesCount value) { return REDGPU_NP_STRUCT_INIT(_s_f208f968_RedStatuses*){value}; }
static inline _s_f208f968_char* _f208f968_char*(outStatuses value) { return REDGPU_NP_STRUCT_INIT(_s_f208f968_char*){value}; }
static inline _s_f208f968_int _f208f968_int(optionalFile value) { return REDGPU_NP_STRUCT_INIT(_s_f208f968_int){value}; }
static inline _s_f208f968_void* _f208f968_void*(optionalLine value) { return REDGPU_NP_STRUCT_INIT(_s_f208f968_void*){value}; }
static inline _s_f208f968_ _f208f968_(optionalUserData value) { return REDGPU_NP_STRUCT_INIT(_s_f208f968_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_f208f968_RedContext RedContext, _s_f208f968_RedHandleGpu RedHandleGpu, _s_f208f968_RedBool32 RedBool32, _s_f208f968_uint64_t uint64_t, _s_f208f968_RedStatuses* RedStatuses*, _s_f208f968_char* char*, _s_f208f968_int int, _s_f208f968_void* void*, _s_f208f968_ ) {
  return void(RedContext.value, RedHandleGpu.value, RedBool32.value, uint64_t.value, RedStatuses*.value, char*.value, int.value, void*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_uint64_t uint64_t
#define _914598f1_RedContext(value) value
#define _914598f1_RedHandleGpu(value) value
#define _914598f1_RedHandleArray(value) value
#define _914598f1_(value) value
#else
typedef struct _s_914598f1_RedContext { redXGetMemoryAddressArray value; } _s_914598f1_RedContext;
typedef struct _s_914598f1_RedHandleGpu { context value; } _s_914598f1_RedHandleGpu;
typedef struct _s_914598f1_RedHandleArray { gpu value; } _s_914598f1_RedHandleArray;
typedef struct _s_914598f1_ { array value; } _s_914598f1_;
static inline _s_914598f1_RedContext _914598f1_RedContext(redXGetMemoryAddressArray value) { return REDGPU_NP_STRUCT_INIT(_s_914598f1_RedContext){value}; }
static inline _s_914598f1_RedHandleGpu _914598f1_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_914598f1_RedHandleGpu){value}; }
static inline _s_914598f1_RedHandleArray _914598f1_RedHandleArray(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_914598f1_RedHandleArray){value}; }
static inline _s_914598f1_ _914598f1_(array value) { return REDGPU_NP_STRUCT_INIT(_s_914598f1_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_uint64_t(_s_914598f1_RedContext RedContext, _s_914598f1_RedHandleGpu RedHandleGpu, _s_914598f1_RedHandleArray RedHandleArray, _s_914598f1_ ) {
  return uint64_t(RedContext.value, RedHandleGpu.value, RedHandleArray.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_uint64_t uint64_t
#define _303f7e83_RedContext(value) value
#define _303f7e83_RedHandleGpu(value) value
#define _303f7e83_RedHandleSampler(value) value
#define _303f7e83_(value) value
#else
typedef struct _s_303f7e83_RedContext { redXGetMemoryAddressSampler value; } _s_303f7e83_RedContext;
typedef struct _s_303f7e83_RedHandleGpu { context value; } _s_303f7e83_RedHandleGpu;
typedef struct _s_303f7e83_RedHandleSampler { gpu value; } _s_303f7e83_RedHandleSampler;
typedef struct _s_303f7e83_ { sampler value; } _s_303f7e83_;
static inline _s_303f7e83_RedContext _303f7e83_RedContext(redXGetMemoryAddressSampler value) { return REDGPU_NP_STRUCT_INIT(_s_303f7e83_RedContext){value}; }
static inline _s_303f7e83_RedHandleGpu _303f7e83_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_303f7e83_RedHandleGpu){value}; }
static inline _s_303f7e83_RedHandleSampler _303f7e83_RedHandleSampler(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_303f7e83_RedHandleSampler){value}; }
static inline _s_303f7e83_ _303f7e83_(sampler value) { return REDGPU_NP_STRUCT_INIT(_s_303f7e83_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_uint64_t(_s_303f7e83_RedContext RedContext, _s_303f7e83_RedHandleGpu RedHandleGpu, _s_303f7e83_RedHandleSampler RedHandleSampler, _s_303f7e83_ ) {
  return uint64_t(RedContext.value, RedHandleGpu.value, RedHandleSampler.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_uint64_t uint64_t
#define _08763b52_RedContext(value) value
#define _08763b52_RedHandleGpu(value) value
#define _08763b52_RedHandleTexture(value) value
#define _08763b52_(value) value
#else
typedef struct _s_08763b52_RedContext { redXGetMemoryAddressTextureRO value; } _s_08763b52_RedContext;
typedef struct _s_08763b52_RedHandleGpu { context value; } _s_08763b52_RedHandleGpu;
typedef struct _s_08763b52_RedHandleTexture { gpu value; } _s_08763b52_RedHandleTexture;
typedef struct _s_08763b52_ { texture value; } _s_08763b52_;
static inline _s_08763b52_RedContext _08763b52_RedContext(redXGetMemoryAddressTextureRO value) { return REDGPU_NP_STRUCT_INIT(_s_08763b52_RedContext){value}; }
static inline _s_08763b52_RedHandleGpu _08763b52_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_08763b52_RedHandleGpu){value}; }
static inline _s_08763b52_RedHandleTexture _08763b52_RedHandleTexture(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_08763b52_RedHandleTexture){value}; }
static inline _s_08763b52_ _08763b52_(texture value) { return REDGPU_NP_STRUCT_INIT(_s_08763b52_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_uint64_t(_s_08763b52_RedContext RedContext, _s_08763b52_RedHandleGpu RedHandleGpu, _s_08763b52_RedHandleTexture RedHandleTexture, _s_08763b52_ ) {
  return uint64_t(RedContext.value, RedHandleGpu.value, RedHandleTexture.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_uint64_t uint64_t
#define _d5acf148_RedContext(value) value
#define _d5acf148_RedHandleGpu(value) value
#define _d5acf148_RedHandleTexture(value) value
#define _d5acf148_(value) value
#else
typedef struct _s_d5acf148_RedContext { redXGetMemoryAddressTextureRW value; } _s_d5acf148_RedContext;
typedef struct _s_d5acf148_RedHandleGpu { context value; } _s_d5acf148_RedHandleGpu;
typedef struct _s_d5acf148_RedHandleTexture { gpu value; } _s_d5acf148_RedHandleTexture;
typedef struct _s_d5acf148_ { texture value; } _s_d5acf148_;
static inline _s_d5acf148_RedContext _d5acf148_RedContext(redXGetMemoryAddressTextureRW value) { return REDGPU_NP_STRUCT_INIT(_s_d5acf148_RedContext){value}; }
static inline _s_d5acf148_RedHandleGpu _d5acf148_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_d5acf148_RedHandleGpu){value}; }
static inline _s_d5acf148_RedHandleTexture _d5acf148_RedHandleTexture(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_d5acf148_RedHandleTexture){value}; }
static inline _s_d5acf148_ _d5acf148_(texture value) { return REDGPU_NP_STRUCT_INIT(_s_d5acf148_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_uint64_t(_s_d5acf148_RedContext RedContext, _s_d5acf148_RedHandleGpu RedHandleGpu, _s_d5acf148_RedHandleTexture RedHandleTexture, _s_d5acf148_ ) {
  return uint64_t(RedContext.value, RedHandleGpu.value, RedHandleTexture.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_uint64_t uint64_t
#define _28dc0dd4_RedContext(value) value
#define _28dc0dd4_RedHandleGpu(value) value
#define _28dc0dd4_RedHandleStructsMemory(value) value
#define _28dc0dd4_unsigned(value) value
#define _28dc0dd4_(value) value
#else
typedef struct _s_28dc0dd4_RedContext { redXGetMemoryAddressStructMember value; } _s_28dc0dd4_RedContext;
typedef struct _s_28dc0dd4_RedHandleGpu { context value; } _s_28dc0dd4_RedHandleGpu;
typedef struct _s_28dc0dd4_RedHandleStructsMemory { gpu value; } _s_28dc0dd4_RedHandleStructsMemory;
typedef struct _s_28dc0dd4_unsigned { structsMemory value; } _s_28dc0dd4_unsigned;
typedef struct _s_28dc0dd4_ { structMemberIndex value; } _s_28dc0dd4_;
static inline _s_28dc0dd4_RedContext _28dc0dd4_RedContext(redXGetMemoryAddressStructMember value) { return REDGPU_NP_STRUCT_INIT(_s_28dc0dd4_RedContext){value}; }
static inline _s_28dc0dd4_RedHandleGpu _28dc0dd4_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_28dc0dd4_RedHandleGpu){value}; }
static inline _s_28dc0dd4_RedHandleStructsMemory _28dc0dd4_RedHandleStructsMemory(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_28dc0dd4_RedHandleStructsMemory){value}; }
static inline _s_28dc0dd4_unsigned _28dc0dd4_unsigned(structsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_28dc0dd4_unsigned){value}; }
static inline _s_28dc0dd4_ _28dc0dd4_(structMemberIndex value) { return REDGPU_NP_STRUCT_INIT(_s_28dc0dd4_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_uint64_t(_s_28dc0dd4_RedContext RedContext, _s_28dc0dd4_RedHandleGpu RedHandleGpu, _s_28dc0dd4_RedHandleStructsMemory RedHandleStructsMemory, _s_28dc0dd4_unsigned unsigned, _s_28dc0dd4_ ) {
  return uint64_t(RedContext.value, RedHandleGpu.value, RedHandleStructsMemory.value, unsigned.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _d034eb7f_RedContext(value) value
#define _d034eb7f_RedHandleGpu(value) value
#define _d034eb7f_RedBool32(value) value
#define _d034eb7f_unsigned(value) value
#define _d034eb7f_RedXMemoryAddress*(value) value
#define _d034eb7f_unsigned*(value) value
#define _d034eb7f_unsigned(value) value
#define _d034eb7f_RedXMemoryAddress*(value) value
#define _d034eb7f_unsigned*(value) value
#define _d034eb7f_RedStatuses*(value) value
#define _d034eb7f_char*(value) value
#define _d034eb7f_int(value) value
#define _d034eb7f_void*(value) value
#define _d034eb7f_(value) value
#else
typedef struct _s_d034eb7f_RedContext { redXStructsMemorySet value; } _s_d034eb7f_RedContext;
typedef struct _s_d034eb7f_RedHandleGpu { context value; } _s_d034eb7f_RedHandleGpu;
typedef struct _s_d034eb7f_RedBool32 { gpu value; } _s_d034eb7f_RedBool32;
typedef struct _s_d034eb7f_unsigned { copyingSamplers value; } _s_d034eb7f_unsigned;
typedef struct _s_d034eb7f_RedXMemoryAddress* { sourceCopiesCount value; } _s_d034eb7f_RedXMemoryAddress*;
typedef struct _s_d034eb7f_unsigned* { sourceCopiesAddressFirst value; } _s_d034eb7f_unsigned*;
typedef struct _s_d034eb7f_unsigned { sourceCopiesAddressCount value; } _s_d034eb7f_unsigned;
typedef struct _s_d034eb7f_RedXMemoryAddress* { targetCopiesCount value; } _s_d034eb7f_RedXMemoryAddress*;
typedef struct _s_d034eb7f_unsigned* { targetCopiesAddressFirst value; } _s_d034eb7f_unsigned*;
typedef struct _s_d034eb7f_RedStatuses* { targetCopiesAddressCount value; } _s_d034eb7f_RedStatuses*;
typedef struct _s_d034eb7f_char* { outStatuses value; } _s_d034eb7f_char*;
typedef struct _s_d034eb7f_int { optionalFile value; } _s_d034eb7f_int;
typedef struct _s_d034eb7f_void* { optionalLine value; } _s_d034eb7f_void*;
typedef struct _s_d034eb7f_ { optionalUserData value; } _s_d034eb7f_;
static inline _s_d034eb7f_RedContext _d034eb7f_RedContext(redXStructsMemorySet value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_RedContext){value}; }
static inline _s_d034eb7f_RedHandleGpu _d034eb7f_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_RedHandleGpu){value}; }
static inline _s_d034eb7f_RedBool32 _d034eb7f_RedBool32(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_RedBool32){value}; }
static inline _s_d034eb7f_unsigned _d034eb7f_unsigned(copyingSamplers value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_unsigned){value}; }
static inline _s_d034eb7f_RedXMemoryAddress* _d034eb7f_RedXMemoryAddress*(sourceCopiesCount value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_RedXMemoryAddress*){value}; }
static inline _s_d034eb7f_unsigned* _d034eb7f_unsigned*(sourceCopiesAddressFirst value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_unsigned*){value}; }
static inline _s_d034eb7f_unsigned _d034eb7f_unsigned(sourceCopiesAddressCount value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_unsigned){value}; }
static inline _s_d034eb7f_RedXMemoryAddress* _d034eb7f_RedXMemoryAddress*(targetCopiesCount value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_RedXMemoryAddress*){value}; }
static inline _s_d034eb7f_unsigned* _d034eb7f_unsigned*(targetCopiesAddressFirst value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_unsigned*){value}; }
static inline _s_d034eb7f_RedStatuses* _d034eb7f_RedStatuses*(targetCopiesAddressCount value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_RedStatuses*){value}; }
static inline _s_d034eb7f_char* _d034eb7f_char*(outStatuses value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_char*){value}; }
static inline _s_d034eb7f_int _d034eb7f_int(optionalFile value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_int){value}; }
static inline _s_d034eb7f_void* _d034eb7f_void*(optionalLine value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_void*){value}; }
static inline _s_d034eb7f_ _d034eb7f_(optionalUserData value) { return REDGPU_NP_STRUCT_INIT(_s_d034eb7f_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_d034eb7f_RedContext RedContext, _s_d034eb7f_RedHandleGpu RedHandleGpu, _s_d034eb7f_RedBool32 RedBool32, _s_d034eb7f_unsigned unsigned, _s_d034eb7f_RedXMemoryAddress* RedXMemoryAddress*, _s_d034eb7f_unsigned* unsigned*, _s_d034eb7f_unsigned unsigned, _s_d034eb7f_RedXMemoryAddress* RedXMemoryAddress*, _s_d034eb7f_unsigned* unsigned*, _s_d034eb7f_RedStatuses* RedStatuses*, _s_d034eb7f_char* char*, _s_d034eb7f_int int, _s_d034eb7f_void* void*, _s_d034eb7f_ ) {
  return void(RedContext.value, RedHandleGpu.value, RedBool32.value, unsigned.value, RedXMemoryAddress*.value, unsigned*.value, unsigned.value, RedXMemoryAddress*.value, unsigned*.value, RedStatuses*.value, char*.value, int.value, void*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_RedHandleStruct RedHandleStruct
#define _4e579a96_RedContext(value) value
#define _4e579a96_RedHandleGpu(value) value
#define _4e579a96_RedHandleStructsMemory(value) value
#define _4e579a96_unsigned(value) value
#define _4e579a96_(value) value
#else
typedef struct _s_4e579a96_RedContext { redXGetHandleStruct value; } _s_4e579a96_RedContext;
typedef struct _s_4e579a96_RedHandleGpu { context value; } _s_4e579a96_RedHandleGpu;
typedef struct _s_4e579a96_RedHandleStructsMemory { gpu value; } _s_4e579a96_RedHandleStructsMemory;
typedef struct _s_4e579a96_unsigned { structsMemory value; } _s_4e579a96_unsigned;
typedef struct _s_4e579a96_ { structMemberIndex value; } _s_4e579a96_;
static inline _s_4e579a96_RedContext _4e579a96_RedContext(redXGetHandleStruct value) { return REDGPU_NP_STRUCT_INIT(_s_4e579a96_RedContext){value}; }
static inline _s_4e579a96_RedHandleGpu _4e579a96_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_4e579a96_RedHandleGpu){value}; }
static inline _s_4e579a96_RedHandleStructsMemory _4e579a96_RedHandleStructsMemory(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_4e579a96_RedHandleStructsMemory){value}; }
static inline _s_4e579a96_unsigned _4e579a96_unsigned(structsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_4e579a96_unsigned){value}; }
static inline _s_4e579a96_ _4e579a96_(structMemberIndex value) { return REDGPU_NP_STRUCT_INIT(_s_4e579a96_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_RedHandleStruct(_s_4e579a96_RedContext RedContext, _s_4e579a96_RedHandleGpu RedHandleGpu, _s_4e579a96_RedHandleStructsMemory RedHandleStructsMemory, _s_4e579a96_unsigned unsigned, _s_4e579a96_ ) {
  return RedHandleStruct(RedContext.value, RedHandleGpu.value, RedHandleStructsMemory.value, unsigned.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _f32e4677_RedContext(value) value
#define _f32e4677_RedHandleGpu(value) value
#define _f32e4677_char*(value) value
#define _f32e4677_RedBool32(value) value
#define _f32e4677_RedBool32(value) value
#define _f32e4677_RedBool32(value) value
#define _f32e4677_unsigned(value) value
#define _f32e4677_RedBool32(value) value
#define _f32e4677_RedStatuses*(value) value
#define _f32e4677_char*(value) value
#define _f32e4677_int(value) value
#define _f32e4677_void*(value) value
#define _f32e4677_(value) value
#else
typedef struct _s_f32e4677_RedContext { redXCreateQueue value; } _s_f32e4677_RedContext;
typedef struct _s_f32e4677_RedHandleGpu { context value; } _s_f32e4677_RedHandleGpu;
typedef struct _s_f32e4677_char* { gpu value; } _s_f32e4677_char*;
typedef struct _s_f32e4677_RedBool32 { handleName value; } _s_f32e4677_RedBool32;
typedef struct _s_f32e4677_RedBool32 { canCopy value; } _s_f32e4677_RedBool32;
typedef struct _s_f32e4677_RedBool32 { canDraw value; } _s_f32e4677_RedBool32;
typedef struct _s_f32e4677_unsigned { canCompute value; } _s_f32e4677_unsigned;
typedef struct _s_f32e4677_RedBool32 { priority value; } _s_f32e4677_RedBool32;
typedef struct _s_f32e4677_RedStatuses* { disableGpuTimeout value; } _s_f32e4677_RedStatuses*;
typedef struct _s_f32e4677_char* { outStatuses value; } _s_f32e4677_char*;
typedef struct _s_f32e4677_int { optionalFile value; } _s_f32e4677_int;
typedef struct _s_f32e4677_void* { optionalLine value; } _s_f32e4677_void*;
typedef struct _s_f32e4677_ { optionalUserData value; } _s_f32e4677_;
static inline _s_f32e4677_RedContext _f32e4677_RedContext(redXCreateQueue value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_RedContext){value}; }
static inline _s_f32e4677_RedHandleGpu _f32e4677_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_RedHandleGpu){value}; }
static inline _s_f32e4677_char* _f32e4677_char*(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_char*){value}; }
static inline _s_f32e4677_RedBool32 _f32e4677_RedBool32(handleName value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_RedBool32){value}; }
static inline _s_f32e4677_RedBool32 _f32e4677_RedBool32(canCopy value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_RedBool32){value}; }
static inline _s_f32e4677_RedBool32 _f32e4677_RedBool32(canDraw value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_RedBool32){value}; }
static inline _s_f32e4677_unsigned _f32e4677_unsigned(canCompute value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_unsigned){value}; }
static inline _s_f32e4677_RedBool32 _f32e4677_RedBool32(priority value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_RedBool32){value}; }
static inline _s_f32e4677_RedStatuses* _f32e4677_RedStatuses*(disableGpuTimeout value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_RedStatuses*){value}; }
static inline _s_f32e4677_char* _f32e4677_char*(outStatuses value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_char*){value}; }
static inline _s_f32e4677_int _f32e4677_int(optionalFile value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_int){value}; }
static inline _s_f32e4677_void* _f32e4677_void*(optionalLine value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_void*){value}; }
static inline _s_f32e4677_ _f32e4677_(optionalUserData value) { return REDGPU_NP_STRUCT_INIT(_s_f32e4677_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_f32e4677_RedContext RedContext, _s_f32e4677_RedHandleGpu RedHandleGpu, _s_f32e4677_char* char*, _s_f32e4677_RedBool32 RedBool32, _s_f32e4677_RedBool32 RedBool32, _s_f32e4677_RedBool32 RedBool32, _s_f32e4677_unsigned unsigned, _s_f32e4677_RedBool32 RedBool32, _s_f32e4677_RedStatuses* RedStatuses*, _s_f32e4677_char* char*, _s_f32e4677_int int, _s_f32e4677_void* void*, _s_f32e4677_ ) {
  return void(RedContext.value, RedHandleGpu.value, char*.value, RedBool32.value, RedBool32.value, RedBool32.value, unsigned.value, RedBool32.value, RedStatuses*.value, char*.value, int.value, void*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _e43f103e_RedContext(value) value
#define _e43f103e_RedHandleGpu(value) value
#define _e43f103e_char*(value) value
#define _e43f103e_RedImageDimensions(value) value
#define _e43f103e_RedFormat(value) value
#define _e43f103e_unsigned(value) value
#define _e43f103e_unsigned(value) value
#define _e43f103e_unsigned(value) value
#define _e43f103e_unsigned(value) value
#define _e43f103e_unsigned(value) value
#define _e43f103e_unsigned(value) value
#define _e43f103e_RedMultisampleCountBitflag(value) value
#define _e43f103e_RedAccessBitflags(value) value
#define _e43f103e_RedAccessBitflags(value) value
#define _e43f103e_unsigned(value) value
#define _e43f103e_RedBool32(value) value
#define _e43f103e_RedImage*(value) value
#define _e43f103e_RedStatuses*(value) value
#define _e43f103e_char*(value) value
#define _e43f103e_int(value) value
#define _e43f103e_void*(value) value
#define _e43f103e_(value) value
#else
typedef struct _s_e43f103e_RedContext { redXCreateImage value; } _s_e43f103e_RedContext;
typedef struct _s_e43f103e_RedHandleGpu { context value; } _s_e43f103e_RedHandleGpu;
typedef struct _s_e43f103e_char* { gpu value; } _s_e43f103e_char*;
typedef struct _s_e43f103e_RedImageDimensions { handleName value; } _s_e43f103e_RedImageDimensions;
typedef struct _s_e43f103e_RedFormat { dimensions value; } _s_e43f103e_RedFormat;
typedef struct _s_e43f103e_unsigned { format value; } _s_e43f103e_unsigned;
typedef struct _s_e43f103e_unsigned { xformat value; } _s_e43f103e_unsigned;
typedef struct _s_e43f103e_unsigned { width value; } _s_e43f103e_unsigned;
typedef struct _s_e43f103e_unsigned { height value; } _s_e43f103e_unsigned;
typedef struct _s_e43f103e_unsigned { depth value; } _s_e43f103e_unsigned;
typedef struct _s_e43f103e_unsigned { levelsCount value; } _s_e43f103e_unsigned;
typedef struct _s_e43f103e_RedMultisampleCountBitflag { layersCount value; } _s_e43f103e_RedMultisampleCountBitflag;
typedef struct _s_e43f103e_RedAccessBitflags { multisampleCount value; } _s_e43f103e_RedAccessBitflags;
typedef struct _s_e43f103e_RedAccessBitflags { restrictToAccess value; } _s_e43f103e_RedAccessBitflags;
typedef struct _s_e43f103e_unsigned { initialAccess value; } _s_e43f103e_unsigned;
typedef struct _s_e43f103e_RedBool32 { initialQueueFamilyIndex value; } _s_e43f103e_RedBool32;
typedef struct _s_e43f103e_RedImage* { dedicate value; } _s_e43f103e_RedImage*;
typedef struct _s_e43f103e_RedStatuses* { outImage value; } _s_e43f103e_RedStatuses*;
typedef struct _s_e43f103e_char* { outStatuses value; } _s_e43f103e_char*;
typedef struct _s_e43f103e_int { optionalFile value; } _s_e43f103e_int;
typedef struct _s_e43f103e_void* { optionalLine value; } _s_e43f103e_void*;
typedef struct _s_e43f103e_ { optionalUserData value; } _s_e43f103e_;
static inline _s_e43f103e_RedContext _e43f103e_RedContext(redXCreateImage value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_RedContext){value}; }
static inline _s_e43f103e_RedHandleGpu _e43f103e_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_RedHandleGpu){value}; }
static inline _s_e43f103e_char* _e43f103e_char*(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_char*){value}; }
static inline _s_e43f103e_RedImageDimensions _e43f103e_RedImageDimensions(handleName value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_RedImageDimensions){value}; }
static inline _s_e43f103e_RedFormat _e43f103e_RedFormat(dimensions value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_RedFormat){value}; }
static inline _s_e43f103e_unsigned _e43f103e_unsigned(format value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_unsigned){value}; }
static inline _s_e43f103e_unsigned _e43f103e_unsigned(xformat value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_unsigned){value}; }
static inline _s_e43f103e_unsigned _e43f103e_unsigned(width value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_unsigned){value}; }
static inline _s_e43f103e_unsigned _e43f103e_unsigned(height value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_unsigned){value}; }
static inline _s_e43f103e_unsigned _e43f103e_unsigned(depth value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_unsigned){value}; }
static inline _s_e43f103e_unsigned _e43f103e_unsigned(levelsCount value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_unsigned){value}; }
static inline _s_e43f103e_RedMultisampleCountBitflag _e43f103e_RedMultisampleCountBitflag(layersCount value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_RedMultisampleCountBitflag){value}; }
static inline _s_e43f103e_RedAccessBitflags _e43f103e_RedAccessBitflags(multisampleCount value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_RedAccessBitflags){value}; }
static inline _s_e43f103e_RedAccessBitflags _e43f103e_RedAccessBitflags(restrictToAccess value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_RedAccessBitflags){value}; }
static inline _s_e43f103e_unsigned _e43f103e_unsigned(initialAccess value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_unsigned){value}; }
static inline _s_e43f103e_RedBool32 _e43f103e_RedBool32(initialQueueFamilyIndex value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_RedBool32){value}; }
static inline _s_e43f103e_RedImage* _e43f103e_RedImage*(dedicate value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_RedImage*){value}; }
static inline _s_e43f103e_RedStatuses* _e43f103e_RedStatuses*(outImage value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_RedStatuses*){value}; }
static inline _s_e43f103e_char* _e43f103e_char*(outStatuses value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_char*){value}; }
static inline _s_e43f103e_int _e43f103e_int(optionalFile value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_int){value}; }
static inline _s_e43f103e_void* _e43f103e_void*(optionalLine value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_void*){value}; }
static inline _s_e43f103e_ _e43f103e_(optionalUserData value) { return REDGPU_NP_STRUCT_INIT(_s_e43f103e_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_e43f103e_RedContext RedContext, _s_e43f103e_RedHandleGpu RedHandleGpu, _s_e43f103e_char* char*, _s_e43f103e_RedImageDimensions RedImageDimensions, _s_e43f103e_RedFormat RedFormat, _s_e43f103e_unsigned unsigned, _s_e43f103e_unsigned unsigned, _s_e43f103e_unsigned unsigned, _s_e43f103e_unsigned unsigned, _s_e43f103e_unsigned unsigned, _s_e43f103e_unsigned unsigned, _s_e43f103e_RedMultisampleCountBitflag RedMultisampleCountBitflag, _s_e43f103e_RedAccessBitflags RedAccessBitflags, _s_e43f103e_RedAccessBitflags RedAccessBitflags, _s_e43f103e_unsigned unsigned, _s_e43f103e_RedBool32 RedBool32, _s_e43f103e_RedImage* RedImage*, _s_e43f103e_RedStatuses* RedStatuses*, _s_e43f103e_char* char*, _s_e43f103e_int int, _s_e43f103e_void* void*, _s_e43f103e_ ) {
  return void(RedContext.value, RedHandleGpu.value, char*.value, RedImageDimensions.value, RedFormat.value, unsigned.value, unsigned.value, unsigned.value, unsigned.value, unsigned.value, unsigned.value, RedMultisampleCountBitflag.value, RedAccessBitflags.value, RedAccessBitflags.value, unsigned.value, RedBool32.value, RedImage*.value, RedStatuses*.value, char*.value, int.value, void*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _062f19e5_RedContext(value) value
#define _062f19e5_RedHandleGpu(value) value
#define _062f19e5_char*(value) value
#define _062f19e5_RedHandleImage(value) value
#define _062f19e5_RedImagePartBitflags(value) value
#define _062f19e5_RedTextureDimensions(value) value
#define _062f19e5_RedFormat(value) value
#define _062f19e5_unsigned(value) value
#define _062f19e5_unsigned(value) value
#define _062f19e5_unsigned(value) value
#define _062f19e5_unsigned(value) value
#define _062f19e5_unsigned(value) value
#define _062f19e5_RedAccessBitflags(value) value
#define _062f19e5_RedHandleTexture*(value) value
#define _062f19e5_RedStatuses*(value) value
#define _062f19e5_char*(value) value
#define _062f19e5_int(value) value
#define _062f19e5_void*(value) value
#define _062f19e5_(value) value
#else
typedef struct _s_062f19e5_RedContext { redXCreateTexture value; } _s_062f19e5_RedContext;
typedef struct _s_062f19e5_RedHandleGpu { context value; } _s_062f19e5_RedHandleGpu;
typedef struct _s_062f19e5_char* { gpu value; } _s_062f19e5_char*;
typedef struct _s_062f19e5_RedHandleImage { handleName value; } _s_062f19e5_RedHandleImage;
typedef struct _s_062f19e5_RedImagePartBitflags { image value; } _s_062f19e5_RedImagePartBitflags;
typedef struct _s_062f19e5_RedTextureDimensions { parts value; } _s_062f19e5_RedTextureDimensions;
typedef struct _s_062f19e5_RedFormat { dimensions value; } _s_062f19e5_RedFormat;
typedef struct _s_062f19e5_unsigned { format value; } _s_062f19e5_unsigned;
typedef struct _s_062f19e5_unsigned { xformat value; } _s_062f19e5_unsigned;
typedef struct _s_062f19e5_unsigned { levelsFirst value; } _s_062f19e5_unsigned;
typedef struct _s_062f19e5_unsigned { levelsCount value; } _s_062f19e5_unsigned;
typedef struct _s_062f19e5_unsigned { layersFirst value; } _s_062f19e5_unsigned;
typedef struct _s_062f19e5_RedAccessBitflags { layersCount value; } _s_062f19e5_RedAccessBitflags;
typedef struct _s_062f19e5_RedHandleTexture* { restrictToAccess value; } _s_062f19e5_RedHandleTexture*;
typedef struct _s_062f19e5_RedStatuses* { outTexture value; } _s_062f19e5_RedStatuses*;
typedef struct _s_062f19e5_char* { outStatuses value; } _s_062f19e5_char*;
typedef struct _s_062f19e5_int { optionalFile value; } _s_062f19e5_int;
typedef struct _s_062f19e5_void* { optionalLine value; } _s_062f19e5_void*;
typedef struct _s_062f19e5_ { optionalUserData value; } _s_062f19e5_;
static inline _s_062f19e5_RedContext _062f19e5_RedContext(redXCreateTexture value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_RedContext){value}; }
static inline _s_062f19e5_RedHandleGpu _062f19e5_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_RedHandleGpu){value}; }
static inline _s_062f19e5_char* _062f19e5_char*(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_char*){value}; }
static inline _s_062f19e5_RedHandleImage _062f19e5_RedHandleImage(handleName value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_RedHandleImage){value}; }
static inline _s_062f19e5_RedImagePartBitflags _062f19e5_RedImagePartBitflags(image value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_RedImagePartBitflags){value}; }
static inline _s_062f19e5_RedTextureDimensions _062f19e5_RedTextureDimensions(parts value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_RedTextureDimensions){value}; }
static inline _s_062f19e5_RedFormat _062f19e5_RedFormat(dimensions value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_RedFormat){value}; }
static inline _s_062f19e5_unsigned _062f19e5_unsigned(format value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_unsigned){value}; }
static inline _s_062f19e5_unsigned _062f19e5_unsigned(xformat value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_unsigned){value}; }
static inline _s_062f19e5_unsigned _062f19e5_unsigned(levelsFirst value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_unsigned){value}; }
static inline _s_062f19e5_unsigned _062f19e5_unsigned(levelsCount value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_unsigned){value}; }
static inline _s_062f19e5_unsigned _062f19e5_unsigned(layersFirst value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_unsigned){value}; }
static inline _s_062f19e5_RedAccessBitflags _062f19e5_RedAccessBitflags(layersCount value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_RedAccessBitflags){value}; }
static inline _s_062f19e5_RedHandleTexture* _062f19e5_RedHandleTexture*(restrictToAccess value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_RedHandleTexture*){value}; }
static inline _s_062f19e5_RedStatuses* _062f19e5_RedStatuses*(outTexture value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_RedStatuses*){value}; }
static inline _s_062f19e5_char* _062f19e5_char*(outStatuses value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_char*){value}; }
static inline _s_062f19e5_int _062f19e5_int(optionalFile value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_int){value}; }
static inline _s_062f19e5_void* _062f19e5_void*(optionalLine value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_void*){value}; }
static inline _s_062f19e5_ _062f19e5_(optionalUserData value) { return REDGPU_NP_STRUCT_INIT(_s_062f19e5_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_062f19e5_RedContext RedContext, _s_062f19e5_RedHandleGpu RedHandleGpu, _s_062f19e5_char* char*, _s_062f19e5_RedHandleImage RedHandleImage, _s_062f19e5_RedImagePartBitflags RedImagePartBitflags, _s_062f19e5_RedTextureDimensions RedTextureDimensions, _s_062f19e5_RedFormat RedFormat, _s_062f19e5_unsigned unsigned, _s_062f19e5_unsigned unsigned, _s_062f19e5_unsigned unsigned, _s_062f19e5_unsigned unsigned, _s_062f19e5_unsigned unsigned, _s_062f19e5_RedAccessBitflags RedAccessBitflags, _s_062f19e5_RedHandleTexture* RedHandleTexture*, _s_062f19e5_RedStatuses* RedStatuses*, _s_062f19e5_char* char*, _s_062f19e5_int int, _s_062f19e5_void* void*, _s_062f19e5_ ) {
  return void(RedContext.value, RedHandleGpu.value, char*.value, RedHandleImage.value, RedImagePartBitflags.value, RedTextureDimensions.value, RedFormat.value, unsigned.value, unsigned.value, unsigned.value, unsigned.value, unsigned.value, RedAccessBitflags.value, RedHandleTexture*.value, RedStatuses*.value, char*.value, int.value, void*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_RedXHandlePageable RedXHandlePageable
#define _83c1d58c_RedContext(value) value
#define _83c1d58c_RedHandleGpu(value) value
#define _83c1d58c_RedHandleMemory(value) value
#define _83c1d58c_(value) value
#else
typedef struct _s_83c1d58c_RedContext { redXGetHandlePageableMemory value; } _s_83c1d58c_RedContext;
typedef struct _s_83c1d58c_RedHandleGpu { context value; } _s_83c1d58c_RedHandleGpu;
typedef struct _s_83c1d58c_RedHandleMemory { gpu value; } _s_83c1d58c_RedHandleMemory;
typedef struct _s_83c1d58c_ { memory value; } _s_83c1d58c_;
static inline _s_83c1d58c_RedContext _83c1d58c_RedContext(redXGetHandlePageableMemory value) { return REDGPU_NP_STRUCT_INIT(_s_83c1d58c_RedContext){value}; }
static inline _s_83c1d58c_RedHandleGpu _83c1d58c_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_83c1d58c_RedHandleGpu){value}; }
static inline _s_83c1d58c_RedHandleMemory _83c1d58c_RedHandleMemory(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_83c1d58c_RedHandleMemory){value}; }
static inline _s_83c1d58c_ _83c1d58c_(memory value) { return REDGPU_NP_STRUCT_INIT(_s_83c1d58c_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_RedXHandlePageable(_s_83c1d58c_RedContext RedContext, _s_83c1d58c_RedHandleGpu RedHandleGpu, _s_83c1d58c_RedHandleMemory RedHandleMemory, _s_83c1d58c_ ) {
  return RedXHandlePageable(RedContext.value, RedHandleGpu.value, RedHandleMemory.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_RedXHandlePageable RedXHandlePageable
#define _9abd124f_RedContext(value) value
#define _9abd124f_RedHandleGpu(value) value
#define _9abd124f_RedHandleStructsMemory(value) value
#define _9abd124f_(value) value
#else
typedef struct _s_9abd124f_RedContext { redXGetHandlePageableStructsMemory value; } _s_9abd124f_RedContext;
typedef struct _s_9abd124f_RedHandleGpu { context value; } _s_9abd124f_RedHandleGpu;
typedef struct _s_9abd124f_RedHandleStructsMemory { gpu value; } _s_9abd124f_RedHandleStructsMemory;
typedef struct _s_9abd124f_ { structsMemory value; } _s_9abd124f_;
static inline _s_9abd124f_RedContext _9abd124f_RedContext(redXGetHandlePageableStructsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_9abd124f_RedContext){value}; }
static inline _s_9abd124f_RedHandleGpu _9abd124f_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_9abd124f_RedHandleGpu){value}; }
static inline _s_9abd124f_RedHandleStructsMemory _9abd124f_RedHandleStructsMemory(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_9abd124f_RedHandleStructsMemory){value}; }
static inline _s_9abd124f_ _9abd124f_(structsMemory value) { return REDGPU_NP_STRUCT_INIT(_s_9abd124f_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_RedXHandlePageable(_s_9abd124f_RedContext RedContext, _s_9abd124f_RedHandleGpu RedHandleGpu, _s_9abd124f_RedHandleStructsMemory RedHandleStructsMemory, _s_9abd124f_ ) {
  return RedXHandlePageable(RedContext.value, RedHandleGpu.value, RedHandleStructsMemory.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _67e87168_RedContext(value) value
#define _67e87168_RedHandleGpu(value) value
#define _67e87168_unsigned(value) value
#define _67e87168_RedXHandlePageable*(value) value
#define _67e87168_RedXPageableResidencyPriorityBitflags*(value) value
#define _67e87168_RedStatuses*(value) value
#define _67e87168_char*(value) value
#define _67e87168_int(value) value
#define _67e87168_void*(value) value
#define _67e87168_(value) value
#else
typedef struct _s_67e87168_RedContext { redXPageableSetResidencyPriority value; } _s_67e87168_RedContext;
typedef struct _s_67e87168_RedHandleGpu { context value; } _s_67e87168_RedHandleGpu;
typedef struct _s_67e87168_unsigned { gpu value; } _s_67e87168_unsigned;
typedef struct _s_67e87168_RedXHandlePageable* { pageablesCount value; } _s_67e87168_RedXHandlePageable*;
typedef struct _s_67e87168_RedXPageableResidencyPriorityBitflags* { pageables value; } _s_67e87168_RedXPageableResidencyPriorityBitflags*;
typedef struct _s_67e87168_RedStatuses* { pageablesResidencyPriority value; } _s_67e87168_RedStatuses*;
typedef struct _s_67e87168_char* { outStatuses value; } _s_67e87168_char*;
typedef struct _s_67e87168_int { optionalFile value; } _s_67e87168_int;
typedef struct _s_67e87168_void* { optionalLine value; } _s_67e87168_void*;
typedef struct _s_67e87168_ { optionalUserData value; } _s_67e87168_;
static inline _s_67e87168_RedContext _67e87168_RedContext(redXPageableSetResidencyPriority value) { return REDGPU_NP_STRUCT_INIT(_s_67e87168_RedContext){value}; }
static inline _s_67e87168_RedHandleGpu _67e87168_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_67e87168_RedHandleGpu){value}; }
static inline _s_67e87168_unsigned _67e87168_unsigned(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_67e87168_unsigned){value}; }
static inline _s_67e87168_RedXHandlePageable* _67e87168_RedXHandlePageable*(pageablesCount value) { return REDGPU_NP_STRUCT_INIT(_s_67e87168_RedXHandlePageable*){value}; }
static inline _s_67e87168_RedXPageableResidencyPriorityBitflags* _67e87168_RedXPageableResidencyPriorityBitflags*(pageables value) { return REDGPU_NP_STRUCT_INIT(_s_67e87168_RedXPageableResidencyPriorityBitflags*){value}; }
static inline _s_67e87168_RedStatuses* _67e87168_RedStatuses*(pageablesResidencyPriority value) { return REDGPU_NP_STRUCT_INIT(_s_67e87168_RedStatuses*){value}; }
static inline _s_67e87168_char* _67e87168_char*(outStatuses value) { return REDGPU_NP_STRUCT_INIT(_s_67e87168_char*){value}; }
static inline _s_67e87168_int _67e87168_int(optionalFile value) { return REDGPU_NP_STRUCT_INIT(_s_67e87168_int){value}; }
static inline _s_67e87168_void* _67e87168_void*(optionalLine value) { return REDGPU_NP_STRUCT_INIT(_s_67e87168_void*){value}; }
static inline _s_67e87168_ _67e87168_(optionalUserData value) { return REDGPU_NP_STRUCT_INIT(_s_67e87168_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_67e87168_RedContext RedContext, _s_67e87168_RedHandleGpu RedHandleGpu, _s_67e87168_unsigned unsigned, _s_67e87168_RedXHandlePageable* RedXHandlePageable*, _s_67e87168_RedXPageableResidencyPriorityBitflags* RedXPageableResidencyPriorityBitflags*, _s_67e87168_RedStatuses* RedStatuses*, _s_67e87168_char* char*, _s_67e87168_int int, _s_67e87168_void* void*, _s_67e87168_ ) {
  return void(RedContext.value, RedHandleGpu.value, unsigned.value, RedXHandlePageable*.value, RedXPageableResidencyPriorityBitflags*.value, RedStatuses*.value, char*.value, int.value, void*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _797925ea_RedContext(value) value
#define _797925ea_RedHandleGpu(value) value
#define _797925ea_unsigned(value) value
#define _797925ea_RedXHandlePageable*(value) value
#define _797925ea_RedBool32(value) value
#define _797925ea_RedHandleCpuSignal(value) value
#define _797925ea_RedStatuses*(value) value
#define _797925ea_char*(value) value
#define _797925ea_int(value) value
#define _797925ea_void*(value) value
#define _797925ea_(value) value
#else
typedef struct _s_797925ea_RedContext { redXPageableMakeResident value; } _s_797925ea_RedContext;
typedef struct _s_797925ea_RedHandleGpu { context value; } _s_797925ea_RedHandleGpu;
typedef struct _s_797925ea_unsigned { gpu value; } _s_797925ea_unsigned;
typedef struct _s_797925ea_RedXHandlePageable* { pageablesCount value; } _s_797925ea_RedXHandlePageable*;
typedef struct _s_797925ea_RedBool32 { pageables value; } _s_797925ea_RedBool32;
typedef struct _s_797925ea_RedHandleCpuSignal { denyOverbudget value; } _s_797925ea_RedHandleCpuSignal;
typedef struct _s_797925ea_RedStatuses* { signalCpuSignal value; } _s_797925ea_RedStatuses*;
typedef struct _s_797925ea_char* { outStatuses value; } _s_797925ea_char*;
typedef struct _s_797925ea_int { optionalFile value; } _s_797925ea_int;
typedef struct _s_797925ea_void* { optionalLine value; } _s_797925ea_void*;
typedef struct _s_797925ea_ { optionalUserData value; } _s_797925ea_;
static inline _s_797925ea_RedContext _797925ea_RedContext(redXPageableMakeResident value) { return REDGPU_NP_STRUCT_INIT(_s_797925ea_RedContext){value}; }
static inline _s_797925ea_RedHandleGpu _797925ea_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_797925ea_RedHandleGpu){value}; }
static inline _s_797925ea_unsigned _797925ea_unsigned(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_797925ea_unsigned){value}; }
static inline _s_797925ea_RedXHandlePageable* _797925ea_RedXHandlePageable*(pageablesCount value) { return REDGPU_NP_STRUCT_INIT(_s_797925ea_RedXHandlePageable*){value}; }
static inline _s_797925ea_RedBool32 _797925ea_RedBool32(pageables value) { return REDGPU_NP_STRUCT_INIT(_s_797925ea_RedBool32){value}; }
static inline _s_797925ea_RedHandleCpuSignal _797925ea_RedHandleCpuSignal(denyOverbudget value) { return REDGPU_NP_STRUCT_INIT(_s_797925ea_RedHandleCpuSignal){value}; }
static inline _s_797925ea_RedStatuses* _797925ea_RedStatuses*(signalCpuSignal value) { return REDGPU_NP_STRUCT_INIT(_s_797925ea_RedStatuses*){value}; }
static inline _s_797925ea_char* _797925ea_char*(outStatuses value) { return REDGPU_NP_STRUCT_INIT(_s_797925ea_char*){value}; }
static inline _s_797925ea_int _797925ea_int(optionalFile value) { return REDGPU_NP_STRUCT_INIT(_s_797925ea_int){value}; }
static inline _s_797925ea_void* _797925ea_void*(optionalLine value) { return REDGPU_NP_STRUCT_INIT(_s_797925ea_void*){value}; }
static inline _s_797925ea_ _797925ea_(optionalUserData value) { return REDGPU_NP_STRUCT_INIT(_s_797925ea_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_797925ea_RedContext RedContext, _s_797925ea_RedHandleGpu RedHandleGpu, _s_797925ea_unsigned unsigned, _s_797925ea_RedXHandlePageable* RedXHandlePageable*, _s_797925ea_RedBool32 RedBool32, _s_797925ea_RedHandleCpuSignal RedHandleCpuSignal, _s_797925ea_RedStatuses* RedStatuses*, _s_797925ea_char* char*, _s_797925ea_int int, _s_797925ea_void* void*, _s_797925ea_ ) {
  return void(RedContext.value, RedHandleGpu.value, unsigned.value, RedXHandlePageable*.value, RedBool32.value, RedHandleCpuSignal.value, RedStatuses*.value, char*.value, int.value, void*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _8bc50419_RedContext(value) value
#define _8bc50419_RedHandleGpu(value) value
#define _8bc50419_unsigned(value) value
#define _8bc50419_RedXHandlePageable*(value) value
#define _8bc50419_RedStatuses*(value) value
#define _8bc50419_char*(value) value
#define _8bc50419_int(value) value
#define _8bc50419_void*(value) value
#define _8bc50419_(value) value
#else
typedef struct _s_8bc50419_RedContext { redXPageableEvict value; } _s_8bc50419_RedContext;
typedef struct _s_8bc50419_RedHandleGpu { context value; } _s_8bc50419_RedHandleGpu;
typedef struct _s_8bc50419_unsigned { gpu value; } _s_8bc50419_unsigned;
typedef struct _s_8bc50419_RedXHandlePageable* { pageablesCount value; } _s_8bc50419_RedXHandlePageable*;
typedef struct _s_8bc50419_RedStatuses* { pageables value; } _s_8bc50419_RedStatuses*;
typedef struct _s_8bc50419_char* { outStatuses value; } _s_8bc50419_char*;
typedef struct _s_8bc50419_int { optionalFile value; } _s_8bc50419_int;
typedef struct _s_8bc50419_void* { optionalLine value; } _s_8bc50419_void*;
typedef struct _s_8bc50419_ { optionalUserData value; } _s_8bc50419_;
static inline _s_8bc50419_RedContext _8bc50419_RedContext(redXPageableEvict value) { return REDGPU_NP_STRUCT_INIT(_s_8bc50419_RedContext){value}; }
static inline _s_8bc50419_RedHandleGpu _8bc50419_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_8bc50419_RedHandleGpu){value}; }
static inline _s_8bc50419_unsigned _8bc50419_unsigned(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_8bc50419_unsigned){value}; }
static inline _s_8bc50419_RedXHandlePageable* _8bc50419_RedXHandlePageable*(pageablesCount value) { return REDGPU_NP_STRUCT_INIT(_s_8bc50419_RedXHandlePageable*){value}; }
static inline _s_8bc50419_RedStatuses* _8bc50419_RedStatuses*(pageables value) { return REDGPU_NP_STRUCT_INIT(_s_8bc50419_RedStatuses*){value}; }
static inline _s_8bc50419_char* _8bc50419_char*(outStatuses value) { return REDGPU_NP_STRUCT_INIT(_s_8bc50419_char*){value}; }
static inline _s_8bc50419_int _8bc50419_int(optionalFile value) { return REDGPU_NP_STRUCT_INIT(_s_8bc50419_int){value}; }
static inline _s_8bc50419_void* _8bc50419_void*(optionalLine value) { return REDGPU_NP_STRUCT_INIT(_s_8bc50419_void*){value}; }
static inline _s_8bc50419_ _8bc50419_(optionalUserData value) { return REDGPU_NP_STRUCT_INIT(_s_8bc50419_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_8bc50419_RedContext RedContext, _s_8bc50419_RedHandleGpu RedHandleGpu, _s_8bc50419_unsigned unsigned, _s_8bc50419_RedXHandlePageable* RedXHandlePageable*, _s_8bc50419_RedStatuses* RedStatuses*, _s_8bc50419_char* char*, _s_8bc50419_int int, _s_8bc50419_void* void*, _s_8bc50419_ ) {
  return void(RedContext.value, RedHandleGpu.value, unsigned.value, RedXHandlePageable*.value, RedStatuses*.value, char*.value, int.value, void*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_RedXHandleResource RedXHandleResource
#define _ec7febf5_RedContext(value) value
#define _ec7febf5_RedHandleGpu(value) value
#define _ec7febf5_RedHandleArray(value) value
#define _ec7febf5_(value) value
#else
typedef struct _s_ec7febf5_RedContext { redXGetHandleResourceArray value; } _s_ec7febf5_RedContext;
typedef struct _s_ec7febf5_RedHandleGpu { context value; } _s_ec7febf5_RedHandleGpu;
typedef struct _s_ec7febf5_RedHandleArray { gpu value; } _s_ec7febf5_RedHandleArray;
typedef struct _s_ec7febf5_ { array value; } _s_ec7febf5_;
static inline _s_ec7febf5_RedContext _ec7febf5_RedContext(redXGetHandleResourceArray value) { return REDGPU_NP_STRUCT_INIT(_s_ec7febf5_RedContext){value}; }
static inline _s_ec7febf5_RedHandleGpu _ec7febf5_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_ec7febf5_RedHandleGpu){value}; }
static inline _s_ec7febf5_RedHandleArray _ec7febf5_RedHandleArray(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_ec7febf5_RedHandleArray){value}; }
static inline _s_ec7febf5_ _ec7febf5_(array value) { return REDGPU_NP_STRUCT_INIT(_s_ec7febf5_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_RedXHandleResource(_s_ec7febf5_RedContext RedContext, _s_ec7febf5_RedHandleGpu RedHandleGpu, _s_ec7febf5_RedHandleArray RedHandleArray, _s_ec7febf5_ ) {
  return RedXHandleResource(RedContext.value, RedHandleGpu.value, RedHandleArray.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_RedXHandleResource RedXHandleResource
#define _3ddaf326_RedContext(value) value
#define _3ddaf326_RedHandleGpu(value) value
#define _3ddaf326_RedHandleImage(value) value
#define _3ddaf326_(value) value
#else
typedef struct _s_3ddaf326_RedContext { redXGetHandleResourceImage value; } _s_3ddaf326_RedContext;
typedef struct _s_3ddaf326_RedHandleGpu { context value; } _s_3ddaf326_RedHandleGpu;
typedef struct _s_3ddaf326_RedHandleImage { gpu value; } _s_3ddaf326_RedHandleImage;
typedef struct _s_3ddaf326_ { image value; } _s_3ddaf326_;
static inline _s_3ddaf326_RedContext _3ddaf326_RedContext(redXGetHandleResourceImage value) { return REDGPU_NP_STRUCT_INIT(_s_3ddaf326_RedContext){value}; }
static inline _s_3ddaf326_RedHandleGpu _3ddaf326_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_3ddaf326_RedHandleGpu){value}; }
static inline _s_3ddaf326_RedHandleImage _3ddaf326_RedHandleImage(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_3ddaf326_RedHandleImage){value}; }
static inline _s_3ddaf326_ _3ddaf326_(image value) { return REDGPU_NP_STRUCT_INIT(_s_3ddaf326_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_RedXHandleResource(_s_3ddaf326_RedContext RedContext, _s_3ddaf326_RedHandleGpu RedHandleGpu, _s_3ddaf326_RedHandleImage RedHandleImage, _s_3ddaf326_ ) {
  return RedXHandleResource(RedContext.value, RedHandleGpu.value, RedHandleImage.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _c9ffee96_RedHandleCalls(value) value
#define _c9ffee96_RedHandleTexture(value) value
#define _c9ffee96_unsigned(value) value
#define _c9ffee96_RedHandleTexture*(value) value
#define _c9ffee96_RedSetProcedureOutputOp(value) value
#define _c9ffee96_RedSetProcedureOutputOp(value) value
#define _c9ffee96_RedSetProcedureOutputOp*(value) value
#define _c9ffee96_float(value) value
#define _c9ffee96_unsigned(value) value
#define _c9ffee96_RedColorsClearValuesFloat*(value) value
#define _c9ffee96_(value) value
#else
typedef struct _s_c9ffee96_RedHandleCalls { redXCallSetProcedureOutput value; } _s_c9ffee96_RedHandleCalls;
typedef struct _s_c9ffee96_RedHandleTexture { calls value; } _s_c9ffee96_RedHandleTexture;
typedef struct _s_c9ffee96_unsigned { depthStencil value; } _s_c9ffee96_unsigned;
typedef struct _s_c9ffee96_RedHandleTexture* { colorsCount value; } _s_c9ffee96_RedHandleTexture*;
typedef struct _s_c9ffee96_RedSetProcedureOutputOp { colors value; } _s_c9ffee96_RedSetProcedureOutputOp;
typedef struct _s_c9ffee96_RedSetProcedureOutputOp { depthSetProcedureOutputOp value; } _s_c9ffee96_RedSetProcedureOutputOp;
typedef struct _s_c9ffee96_RedSetProcedureOutputOp* { stencilSetProcedureOutputOp value; } _s_c9ffee96_RedSetProcedureOutputOp*;
typedef struct _s_c9ffee96_float { colorsSetProcedureOutputOp value; } _s_c9ffee96_float;
typedef struct _s_c9ffee96_unsigned { depthClearValue value; } _s_c9ffee96_unsigned;
typedef struct _s_c9ffee96_RedColorsClearValuesFloat* { stencilClearValue value; } _s_c9ffee96_RedColorsClearValuesFloat*;
typedef struct _s_c9ffee96_ { colorsClearValuesFloat value; } _s_c9ffee96_;
static inline _s_c9ffee96_RedHandleCalls _c9ffee96_RedHandleCalls(redXCallSetProcedureOutput value) { return REDGPU_NP_STRUCT_INIT(_s_c9ffee96_RedHandleCalls){value}; }
static inline _s_c9ffee96_RedHandleTexture _c9ffee96_RedHandleTexture(calls value) { return REDGPU_NP_STRUCT_INIT(_s_c9ffee96_RedHandleTexture){value}; }
static inline _s_c9ffee96_unsigned _c9ffee96_unsigned(depthStencil value) { return REDGPU_NP_STRUCT_INIT(_s_c9ffee96_unsigned){value}; }
static inline _s_c9ffee96_RedHandleTexture* _c9ffee96_RedHandleTexture*(colorsCount value) { return REDGPU_NP_STRUCT_INIT(_s_c9ffee96_RedHandleTexture*){value}; }
static inline _s_c9ffee96_RedSetProcedureOutputOp _c9ffee96_RedSetProcedureOutputOp(colors value) { return REDGPU_NP_STRUCT_INIT(_s_c9ffee96_RedSetProcedureOutputOp){value}; }
static inline _s_c9ffee96_RedSetProcedureOutputOp _c9ffee96_RedSetProcedureOutputOp(depthSetProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_c9ffee96_RedSetProcedureOutputOp){value}; }
static inline _s_c9ffee96_RedSetProcedureOutputOp* _c9ffee96_RedSetProcedureOutputOp*(stencilSetProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_c9ffee96_RedSetProcedureOutputOp*){value}; }
static inline _s_c9ffee96_float _c9ffee96_float(colorsSetProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_c9ffee96_float){value}; }
static inline _s_c9ffee96_unsigned _c9ffee96_unsigned(depthClearValue value) { return REDGPU_NP_STRUCT_INIT(_s_c9ffee96_unsigned){value}; }
static inline _s_c9ffee96_RedColorsClearValuesFloat* _c9ffee96_RedColorsClearValuesFloat*(stencilClearValue value) { return REDGPU_NP_STRUCT_INIT(_s_c9ffee96_RedColorsClearValuesFloat*){value}; }
static inline _s_c9ffee96_ _c9ffee96_(colorsClearValuesFloat value) { return REDGPU_NP_STRUCT_INIT(_s_c9ffee96_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_c9ffee96_RedHandleCalls RedHandleCalls, _s_c9ffee96_RedHandleTexture RedHandleTexture, _s_c9ffee96_unsigned unsigned, _s_c9ffee96_RedHandleTexture* RedHandleTexture*, _s_c9ffee96_RedSetProcedureOutputOp RedSetProcedureOutputOp, _s_c9ffee96_RedSetProcedureOutputOp RedSetProcedureOutputOp, _s_c9ffee96_RedSetProcedureOutputOp* RedSetProcedureOutputOp*, _s_c9ffee96_float float, _s_c9ffee96_unsigned unsigned, _s_c9ffee96_RedColorsClearValuesFloat* RedColorsClearValuesFloat*, _s_c9ffee96_ ) {
  return void(RedHandleCalls.value, RedHandleTexture.value, unsigned.value, RedHandleTexture*.value, RedSetProcedureOutputOp.value, RedSetProcedureOutputOp.value, RedSetProcedureOutputOp*.value, float.value, unsigned.value, RedColorsClearValuesFloat*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _95b99d38_RedHandleCalls(value) value
#define _95b99d38_RedHandleTexture*(value) value
#define _95b99d38_unsigned*(value) value
#define _95b99d38_RedEndProcedureOutputOp(value) value
#define _95b99d38_RedEndProcedureOutputOp(value) value
#define _95b99d38_RedEndProcedureOutputOp*(value) value
#define _95b99d38_(value) value
#else
typedef struct _s_95b99d38_RedHandleCalls { redXCallEndProcedureOutput value; } _s_95b99d38_RedHandleCalls;
typedef struct _s_95b99d38_RedHandleTexture* { calls value; } _s_95b99d38_RedHandleTexture*;
typedef struct _s_95b99d38_unsigned* { resolveTargetColors value; } _s_95b99d38_unsigned*;
typedef struct _s_95b99d38_RedEndProcedureOutputOp { resolveTargetColorsFormat value; } _s_95b99d38_RedEndProcedureOutputOp;
typedef struct _s_95b99d38_RedEndProcedureOutputOp { depthEndProcedureOutputOp value; } _s_95b99d38_RedEndProcedureOutputOp;
typedef struct _s_95b99d38_RedEndProcedureOutputOp* { stencilEndProcedureOutputOp value; } _s_95b99d38_RedEndProcedureOutputOp*;
typedef struct _s_95b99d38_ { colorsEndProcedureOutputOp value; } _s_95b99d38_;
static inline _s_95b99d38_RedHandleCalls _95b99d38_RedHandleCalls(redXCallEndProcedureOutput value) { return REDGPU_NP_STRUCT_INIT(_s_95b99d38_RedHandleCalls){value}; }
static inline _s_95b99d38_RedHandleTexture* _95b99d38_RedHandleTexture*(calls value) { return REDGPU_NP_STRUCT_INIT(_s_95b99d38_RedHandleTexture*){value}; }
static inline _s_95b99d38_unsigned* _95b99d38_unsigned*(resolveTargetColors value) { return REDGPU_NP_STRUCT_INIT(_s_95b99d38_unsigned*){value}; }
static inline _s_95b99d38_RedEndProcedureOutputOp _95b99d38_RedEndProcedureOutputOp(resolveTargetColorsFormat value) { return REDGPU_NP_STRUCT_INIT(_s_95b99d38_RedEndProcedureOutputOp){value}; }
static inline _s_95b99d38_RedEndProcedureOutputOp _95b99d38_RedEndProcedureOutputOp(depthEndProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_95b99d38_RedEndProcedureOutputOp){value}; }
static inline _s_95b99d38_RedEndProcedureOutputOp* _95b99d38_RedEndProcedureOutputOp*(stencilEndProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_95b99d38_RedEndProcedureOutputOp*){value}; }
static inline _s_95b99d38_ _95b99d38_(colorsEndProcedureOutputOp value) { return REDGPU_NP_STRUCT_INIT(_s_95b99d38_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_95b99d38_RedHandleCalls RedHandleCalls, _s_95b99d38_RedHandleTexture* RedHandleTexture*, _s_95b99d38_unsigned* unsigned*, _s_95b99d38_RedEndProcedureOutputOp RedEndProcedureOutputOp, _s_95b99d38_RedEndProcedureOutputOp RedEndProcedureOutputOp, _s_95b99d38_RedEndProcedureOutputOp* RedEndProcedureOutputOp*, _s_95b99d38_ ) {
  return void(RedHandleCalls.value, RedHandleTexture*.value, unsigned*.value, RedEndProcedureOutputOp.value, RedEndProcedureOutputOp.value, RedEndProcedureOutputOp*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _9a7856d8_RedHandleCalls(value) value
#define _9a7856d8_unsigned(value) value
#define _9a7856d8_void*(value) value
#define _9a7856d8_(value) value
#else
typedef struct _s_9a7856d8_RedHandleCalls { redXCallUsageAliasOrderBarrier value; } _s_9a7856d8_RedHandleCalls;
typedef struct _s_9a7856d8_unsigned { calls value; } _s_9a7856d8_unsigned;
typedef struct _s_9a7856d8_void* { barriersCount value; } _s_9a7856d8_void*;
typedef struct _s_9a7856d8_ { barriers value; } _s_9a7856d8_;
static inline _s_9a7856d8_RedHandleCalls _9a7856d8_RedHandleCalls(redXCallUsageAliasOrderBarrier value) { return REDGPU_NP_STRUCT_INIT(_s_9a7856d8_RedHandleCalls){value}; }
static inline _s_9a7856d8_unsigned _9a7856d8_unsigned(calls value) { return REDGPU_NP_STRUCT_INIT(_s_9a7856d8_unsigned){value}; }
static inline _s_9a7856d8_void* _9a7856d8_void*(barriersCount value) { return REDGPU_NP_STRUCT_INIT(_s_9a7856d8_void*){value}; }
static inline _s_9a7856d8_ _9a7856d8_(barriers value) { return REDGPU_NP_STRUCT_INIT(_s_9a7856d8_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_9a7856d8_RedHandleCalls RedHandleCalls, _s_9a7856d8_unsigned unsigned, _s_9a7856d8_void* void*, _s_9a7856d8_ ) {
  return void(RedHandleCalls.value, unsigned.value, void*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _4a33d59a_RedHandleCalls(value) value
#define _4a33d59a_unsigned(value) value
#define _4a33d59a_void*(value) value
#define _4a33d59a_(value) value
#else
typedef struct _s_4a33d59a_RedHandleCalls { redXCallCopyImageRegion value; } _s_4a33d59a_RedHandleCalls;
typedef struct _s_4a33d59a_unsigned { calls value; } _s_4a33d59a_unsigned;
typedef struct _s_4a33d59a_void* { copiesCount value; } _s_4a33d59a_void*;
typedef struct _s_4a33d59a_ { copies value; } _s_4a33d59a_;
static inline _s_4a33d59a_RedHandleCalls _4a33d59a_RedHandleCalls(redXCallCopyImageRegion value) { return REDGPU_NP_STRUCT_INIT(_s_4a33d59a_RedHandleCalls){value}; }
static inline _s_4a33d59a_unsigned _4a33d59a_unsigned(calls value) { return REDGPU_NP_STRUCT_INIT(_s_4a33d59a_unsigned){value}; }
static inline _s_4a33d59a_void* _4a33d59a_void*(copiesCount value) { return REDGPU_NP_STRUCT_INIT(_s_4a33d59a_void*){value}; }
static inline _s_4a33d59a_ _4a33d59a_(copies value) { return REDGPU_NP_STRUCT_INIT(_s_4a33d59a_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_4a33d59a_RedHandleCalls RedHandleCalls, _s_4a33d59a_unsigned unsigned, _s_4a33d59a_void* void*, _s_4a33d59a_ ) {
  return void(RedHandleCalls.value, unsigned.value, void*.value, .value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_void void
#define _f99d7240_RedContext(value) value
#define _f99d7240_RedHandleGpu(value) value
#define _f99d7240_char*(value) value
#define _f99d7240_void*(value) value
#define _f99d7240_RedHandleSurface*(value) value
#define _f99d7240_RedStatuses*(value) value
#define _f99d7240_char*(value) value
#define _f99d7240_int(value) value
#define _f99d7240_void*(value) value
#define _f99d7240_(value) value
#else
typedef struct _s_f99d7240_RedContext { redXCreateSurfaceWinRT value; } _s_f99d7240_RedContext;
typedef struct _s_f99d7240_RedHandleGpu { context value; } _s_f99d7240_RedHandleGpu;
typedef struct _s_f99d7240_char* { gpu value; } _s_f99d7240_char*;
typedef struct _s_f99d7240_void* { handleName value; } _s_f99d7240_void*;
typedef struct _s_f99d7240_RedHandleSurface* { winrtIUnknownPointerCoreWindow value; } _s_f99d7240_RedHandleSurface*;
typedef struct _s_f99d7240_RedStatuses* { outSurface value; } _s_f99d7240_RedStatuses*;
typedef struct _s_f99d7240_char* { outStatuses value; } _s_f99d7240_char*;
typedef struct _s_f99d7240_int { optionalFile value; } _s_f99d7240_int;
typedef struct _s_f99d7240_void* { optionalLine value; } _s_f99d7240_void*;
typedef struct _s_f99d7240_ { optionalUserData value; } _s_f99d7240_;
static inline _s_f99d7240_RedContext _f99d7240_RedContext(redXCreateSurfaceWinRT value) { return REDGPU_NP_STRUCT_INIT(_s_f99d7240_RedContext){value}; }
static inline _s_f99d7240_RedHandleGpu _f99d7240_RedHandleGpu(context value) { return REDGPU_NP_STRUCT_INIT(_s_f99d7240_RedHandleGpu){value}; }
static inline _s_f99d7240_char* _f99d7240_char*(gpu value) { return REDGPU_NP_STRUCT_INIT(_s_f99d7240_char*){value}; }
static inline _s_f99d7240_void* _f99d7240_void*(handleName value) { return REDGPU_NP_STRUCT_INIT(_s_f99d7240_void*){value}; }
static inline _s_f99d7240_RedHandleSurface* _f99d7240_RedHandleSurface*(winrtIUnknownPointerCoreWindow value) { return REDGPU_NP_STRUCT_INIT(_s_f99d7240_RedHandleSurface*){value}; }
static inline _s_f99d7240_RedStatuses* _f99d7240_RedStatuses*(outSurface value) { return REDGPU_NP_STRUCT_INIT(_s_f99d7240_RedStatuses*){value}; }
static inline _s_f99d7240_char* _f99d7240_char*(outStatuses value) { return REDGPU_NP_STRUCT_INIT(_s_f99d7240_char*){value}; }
static inline _s_f99d7240_int _f99d7240_int(optionalFile value) { return REDGPU_NP_STRUCT_INIT(_s_f99d7240_int){value}; }
static inline _s_f99d7240_void* _f99d7240_void*(optionalLine value) { return REDGPU_NP_STRUCT_INIT(_s_f99d7240_void*){value}; }
static inline _s_f99d7240_ _f99d7240_(optionalUserData value) { return REDGPU_NP_STRUCT_INIT(_s_f99d7240_){value}; }
REDGPU_NP_DECLSPEC REDGPU_X_DECLSPEC REDGPU_NP_API np_void(_s_f99d7240_RedContext RedContext, _s_f99d7240_RedHandleGpu RedHandleGpu, _s_f99d7240_char* char*, _s_f99d7240_void* void*, _s_f99d7240_RedHandleSurface* RedHandleSurface*, _s_f99d7240_RedStatuses* RedStatuses*, _s_f99d7240_char* char*, _s_f99d7240_int int, _s_f99d7240_void* void*, _s_f99d7240_ ) {
  return void(RedContext.value, RedHandleGpu.value, char*.value, void*.value, RedHandleSurface*.value, RedStatuses*.value, char*.value, int.value, void*.value, .value);
}
#endif

