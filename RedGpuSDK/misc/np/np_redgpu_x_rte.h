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
#define np_redXRteArrayGetGpuAddress redXRteArrayGetGpuAddress
#define _175aae60_array(value) value
#define _175aae60_optionalFile(value) value
#define _175aae60_optionalLine(value) value
#define _175aae60_optionalUserData(value) value
#define _175aae60_rteParameters(value) value
#else
typedef struct _s_175aae60_array { RedHandleArray value; } _s_175aae60_array;
typedef struct _s_175aae60_optionalFile { char* value; } _s_175aae60_optionalFile;
typedef struct _s_175aae60_optionalLine { int value; } _s_175aae60_optionalLine;
typedef struct _s_175aae60_optionalUserData { void* value; } _s_175aae60_optionalUserData;
typedef struct _s_175aae60_rteParameters { void* value; } _s_175aae60_rteParameters;
static inline _s_175aae60_array _175aae60_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_175aae60_array){value}; }
static inline _s_175aae60_optionalFile _175aae60_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_175aae60_optionalFile){value}; }
static inline _s_175aae60_optionalLine _175aae60_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_175aae60_optionalLine){value}; }
static inline _s_175aae60_optionalUserData _175aae60_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_175aae60_optionalUserData){value}; }
static inline _s_175aae60_rteParameters _175aae60_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_175aae60_rteParameters){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redXRteArrayGetGpuAddress(_s_175aae60_array array, _s_175aae60_optionalFile optionalFile, _s_175aae60_optionalLine optionalLine, _s_175aae60_optionalUserData optionalUserData, _s_175aae60_rteParameters rteParameters) {
  return redXRteArrayGetGpuAddress(array.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCreateBottomLevelASGenerator redXRteCreateBottomLevelASGenerator
#define _cdec3c44_outBottomLevelASGenerator(value) value
#define _cdec3c44_optionalFile(value) value
#define _cdec3c44_optionalLine(value) value
#define _cdec3c44_optionalUserData(value) value
#define _cdec3c44_rteParameters(value) value
#else
typedef struct _s_cdec3c44_outBottomLevelASGenerator { RedXRteHandleBottomLevelASGenerator* value; } _s_cdec3c44_outBottomLevelASGenerator;
typedef struct _s_cdec3c44_optionalFile { char* value; } _s_cdec3c44_optionalFile;
typedef struct _s_cdec3c44_optionalLine { int value; } _s_cdec3c44_optionalLine;
typedef struct _s_cdec3c44_optionalUserData { void* value; } _s_cdec3c44_optionalUserData;
typedef struct _s_cdec3c44_rteParameters { void* value; } _s_cdec3c44_rteParameters;
static inline _s_cdec3c44_outBottomLevelASGenerator _cdec3c44_outBottomLevelASGenerator(RedXRteHandleBottomLevelASGenerator* value) { return REDGPU_NP_STRUCT_INIT(_s_cdec3c44_outBottomLevelASGenerator){value}; }
static inline _s_cdec3c44_optionalFile _cdec3c44_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cdec3c44_optionalFile){value}; }
static inline _s_cdec3c44_optionalLine _cdec3c44_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cdec3c44_optionalLine){value}; }
static inline _s_cdec3c44_optionalUserData _cdec3c44_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cdec3c44_optionalUserData){value}; }
static inline _s_cdec3c44_rteParameters _cdec3c44_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cdec3c44_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCreateBottomLevelASGenerator(_s_cdec3c44_outBottomLevelASGenerator outBottomLevelASGenerator, _s_cdec3c44_optionalFile optionalFile, _s_cdec3c44_optionalLine optionalLine, _s_cdec3c44_optionalUserData optionalUserData, _s_cdec3c44_rteParameters rteParameters) {
  redXRteCreateBottomLevelASGenerator(outBottomLevelASGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCreateTopLevelASGenerator redXRteCreateTopLevelASGenerator
#define _83dd01e9_outTopLevelASGenerator(value) value
#define _83dd01e9_optionalFile(value) value
#define _83dd01e9_optionalLine(value) value
#define _83dd01e9_optionalUserData(value) value
#define _83dd01e9_rteParameters(value) value
#else
typedef struct _s_83dd01e9_outTopLevelASGenerator { RedXRteHandleTopLevelASGenerator* value; } _s_83dd01e9_outTopLevelASGenerator;
typedef struct _s_83dd01e9_optionalFile { char* value; } _s_83dd01e9_optionalFile;
typedef struct _s_83dd01e9_optionalLine { int value; } _s_83dd01e9_optionalLine;
typedef struct _s_83dd01e9_optionalUserData { void* value; } _s_83dd01e9_optionalUserData;
typedef struct _s_83dd01e9_rteParameters { void* value; } _s_83dd01e9_rteParameters;
static inline _s_83dd01e9_outTopLevelASGenerator _83dd01e9_outTopLevelASGenerator(RedXRteHandleTopLevelASGenerator* value) { return REDGPU_NP_STRUCT_INIT(_s_83dd01e9_outTopLevelASGenerator){value}; }
static inline _s_83dd01e9_optionalFile _83dd01e9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_83dd01e9_optionalFile){value}; }
static inline _s_83dd01e9_optionalLine _83dd01e9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_83dd01e9_optionalLine){value}; }
static inline _s_83dd01e9_optionalUserData _83dd01e9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_83dd01e9_optionalUserData){value}; }
static inline _s_83dd01e9_rteParameters _83dd01e9_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_83dd01e9_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCreateTopLevelASGenerator(_s_83dd01e9_outTopLevelASGenerator outTopLevelASGenerator, _s_83dd01e9_optionalFile optionalFile, _s_83dd01e9_optionalLine optionalLine, _s_83dd01e9_optionalUserData optionalUserData, _s_83dd01e9_rteParameters rteParameters) {
  redXRteCreateTopLevelASGenerator(outTopLevelASGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCreateRootSignatureGenerator redXRteCreateRootSignatureGenerator
#define _4fee10fa_outRootSignatureGenerator(value) value
#define _4fee10fa_optionalFile(value) value
#define _4fee10fa_optionalLine(value) value
#define _4fee10fa_optionalUserData(value) value
#define _4fee10fa_rteParameters(value) value
#else
typedef struct _s_4fee10fa_outRootSignatureGenerator { RedXRteHandleRootSignatureGenerator* value; } _s_4fee10fa_outRootSignatureGenerator;
typedef struct _s_4fee10fa_optionalFile { char* value; } _s_4fee10fa_optionalFile;
typedef struct _s_4fee10fa_optionalLine { int value; } _s_4fee10fa_optionalLine;
typedef struct _s_4fee10fa_optionalUserData { void* value; } _s_4fee10fa_optionalUserData;
typedef struct _s_4fee10fa_rteParameters { void* value; } _s_4fee10fa_rteParameters;
static inline _s_4fee10fa_outRootSignatureGenerator _4fee10fa_outRootSignatureGenerator(RedXRteHandleRootSignatureGenerator* value) { return REDGPU_NP_STRUCT_INIT(_s_4fee10fa_outRootSignatureGenerator){value}; }
static inline _s_4fee10fa_optionalFile _4fee10fa_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_4fee10fa_optionalFile){value}; }
static inline _s_4fee10fa_optionalLine _4fee10fa_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_4fee10fa_optionalLine){value}; }
static inline _s_4fee10fa_optionalUserData _4fee10fa_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4fee10fa_optionalUserData){value}; }
static inline _s_4fee10fa_rteParameters _4fee10fa_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_4fee10fa_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCreateRootSignatureGenerator(_s_4fee10fa_outRootSignatureGenerator outRootSignatureGenerator, _s_4fee10fa_optionalFile optionalFile, _s_4fee10fa_optionalLine optionalLine, _s_4fee10fa_optionalUserData optionalUserData, _s_4fee10fa_rteParameters rteParameters) {
  redXRteCreateRootSignatureGenerator(outRootSignatureGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCreateRayTracingPipelineGenerator redXRteCreateRayTracingPipelineGenerator
#define _0cf49da5_device_ID3D12Device5(value) value
#define _0cf49da5_outRayTracingPipelineGenerator(value) value
#define _0cf49da5_optionalFile(value) value
#define _0cf49da5_optionalLine(value) value
#define _0cf49da5_optionalUserData(value) value
#define _0cf49da5_rteParameters(value) value
#else
typedef struct _s_0cf49da5_device_ID3D12Device5 { void* value; } _s_0cf49da5_device_ID3D12Device5;
typedef struct _s_0cf49da5_outRayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator* value; } _s_0cf49da5_outRayTracingPipelineGenerator;
typedef struct _s_0cf49da5_optionalFile { char* value; } _s_0cf49da5_optionalFile;
typedef struct _s_0cf49da5_optionalLine { int value; } _s_0cf49da5_optionalLine;
typedef struct _s_0cf49da5_optionalUserData { void* value; } _s_0cf49da5_optionalUserData;
typedef struct _s_0cf49da5_rteParameters { void* value; } _s_0cf49da5_rteParameters;
static inline _s_0cf49da5_device_ID3D12Device5 _0cf49da5_device_ID3D12Device5(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0cf49da5_device_ID3D12Device5){value}; }
static inline _s_0cf49da5_outRayTracingPipelineGenerator _0cf49da5_outRayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator* value) { return REDGPU_NP_STRUCT_INIT(_s_0cf49da5_outRayTracingPipelineGenerator){value}; }
static inline _s_0cf49da5_optionalFile _0cf49da5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_0cf49da5_optionalFile){value}; }
static inline _s_0cf49da5_optionalLine _0cf49da5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_0cf49da5_optionalLine){value}; }
static inline _s_0cf49da5_optionalUserData _0cf49da5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0cf49da5_optionalUserData){value}; }
static inline _s_0cf49da5_rteParameters _0cf49da5_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_0cf49da5_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCreateRayTracingPipelineGenerator(_s_0cf49da5_device_ID3D12Device5 device_ID3D12Device5, _s_0cf49da5_outRayTracingPipelineGenerator outRayTracingPipelineGenerator, _s_0cf49da5_optionalFile optionalFile, _s_0cf49da5_optionalLine optionalLine, _s_0cf49da5_optionalUserData optionalUserData, _s_0cf49da5_rteParameters rteParameters) {
  redXRteCreateRayTracingPipelineGenerator(device_ID3D12Device5.value, outRayTracingPipelineGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCreateShaderBindingTableGenerator redXRteCreateShaderBindingTableGenerator
#define _3926f21b_outShaderBindingTableGenerator(value) value
#define _3926f21b_optionalFile(value) value
#define _3926f21b_optionalLine(value) value
#define _3926f21b_optionalUserData(value) value
#define _3926f21b_rteParameters(value) value
#else
typedef struct _s_3926f21b_outShaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator* value; } _s_3926f21b_outShaderBindingTableGenerator;
typedef struct _s_3926f21b_optionalFile { char* value; } _s_3926f21b_optionalFile;
typedef struct _s_3926f21b_optionalLine { int value; } _s_3926f21b_optionalLine;
typedef struct _s_3926f21b_optionalUserData { void* value; } _s_3926f21b_optionalUserData;
typedef struct _s_3926f21b_rteParameters { void* value; } _s_3926f21b_rteParameters;
static inline _s_3926f21b_outShaderBindingTableGenerator _3926f21b_outShaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator* value) { return REDGPU_NP_STRUCT_INIT(_s_3926f21b_outShaderBindingTableGenerator){value}; }
static inline _s_3926f21b_optionalFile _3926f21b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3926f21b_optionalFile){value}; }
static inline _s_3926f21b_optionalLine _3926f21b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3926f21b_optionalLine){value}; }
static inline _s_3926f21b_optionalUserData _3926f21b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3926f21b_optionalUserData){value}; }
static inline _s_3926f21b_rteParameters _3926f21b_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3926f21b_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCreateShaderBindingTableGenerator(_s_3926f21b_outShaderBindingTableGenerator outShaderBindingTableGenerator, _s_3926f21b_optionalFile optionalFile, _s_3926f21b_optionalLine optionalLine, _s_3926f21b_optionalUserData optionalUserData, _s_3926f21b_rteParameters rteParameters) {
  redXRteCreateShaderBindingTableGenerator(outShaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteDestroyBottomLevelASGenerator redXRteDestroyBottomLevelASGenerator
#define _6be10cf4_bottomLevelASGenerator(value) value
#define _6be10cf4_optionalFile(value) value
#define _6be10cf4_optionalLine(value) value
#define _6be10cf4_optionalUserData(value) value
#define _6be10cf4_rteParameters(value) value
#else
typedef struct _s_6be10cf4_bottomLevelASGenerator { RedXRteHandleBottomLevelASGenerator value; } _s_6be10cf4_bottomLevelASGenerator;
typedef struct _s_6be10cf4_optionalFile { char* value; } _s_6be10cf4_optionalFile;
typedef struct _s_6be10cf4_optionalLine { int value; } _s_6be10cf4_optionalLine;
typedef struct _s_6be10cf4_optionalUserData { void* value; } _s_6be10cf4_optionalUserData;
typedef struct _s_6be10cf4_rteParameters { void* value; } _s_6be10cf4_rteParameters;
static inline _s_6be10cf4_bottomLevelASGenerator _6be10cf4_bottomLevelASGenerator(RedXRteHandleBottomLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_6be10cf4_bottomLevelASGenerator){value}; }
static inline _s_6be10cf4_optionalFile _6be10cf4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6be10cf4_optionalFile){value}; }
static inline _s_6be10cf4_optionalLine _6be10cf4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6be10cf4_optionalLine){value}; }
static inline _s_6be10cf4_optionalUserData _6be10cf4_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6be10cf4_optionalUserData){value}; }
static inline _s_6be10cf4_rteParameters _6be10cf4_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6be10cf4_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteDestroyBottomLevelASGenerator(_s_6be10cf4_bottomLevelASGenerator bottomLevelASGenerator, _s_6be10cf4_optionalFile optionalFile, _s_6be10cf4_optionalLine optionalLine, _s_6be10cf4_optionalUserData optionalUserData, _s_6be10cf4_rteParameters rteParameters) {
  redXRteDestroyBottomLevelASGenerator(bottomLevelASGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteDestroyTopLevelASGenerator redXRteDestroyTopLevelASGenerator
#define _77e4bbf9_topLevelASGenerator(value) value
#define _77e4bbf9_optionalFile(value) value
#define _77e4bbf9_optionalLine(value) value
#define _77e4bbf9_optionalUserData(value) value
#define _77e4bbf9_rteParameters(value) value
#else
typedef struct _s_77e4bbf9_topLevelASGenerator { RedXRteHandleTopLevelASGenerator value; } _s_77e4bbf9_topLevelASGenerator;
typedef struct _s_77e4bbf9_optionalFile { char* value; } _s_77e4bbf9_optionalFile;
typedef struct _s_77e4bbf9_optionalLine { int value; } _s_77e4bbf9_optionalLine;
typedef struct _s_77e4bbf9_optionalUserData { void* value; } _s_77e4bbf9_optionalUserData;
typedef struct _s_77e4bbf9_rteParameters { void* value; } _s_77e4bbf9_rteParameters;
static inline _s_77e4bbf9_topLevelASGenerator _77e4bbf9_topLevelASGenerator(RedXRteHandleTopLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_77e4bbf9_topLevelASGenerator){value}; }
static inline _s_77e4bbf9_optionalFile _77e4bbf9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_77e4bbf9_optionalFile){value}; }
static inline _s_77e4bbf9_optionalLine _77e4bbf9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_77e4bbf9_optionalLine){value}; }
static inline _s_77e4bbf9_optionalUserData _77e4bbf9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_77e4bbf9_optionalUserData){value}; }
static inline _s_77e4bbf9_rteParameters _77e4bbf9_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_77e4bbf9_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteDestroyTopLevelASGenerator(_s_77e4bbf9_topLevelASGenerator topLevelASGenerator, _s_77e4bbf9_optionalFile optionalFile, _s_77e4bbf9_optionalLine optionalLine, _s_77e4bbf9_optionalUserData optionalUserData, _s_77e4bbf9_rteParameters rteParameters) {
  redXRteDestroyTopLevelASGenerator(topLevelASGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteDestroyRootSignatureGenerator redXRteDestroyRootSignatureGenerator
#define _79154538_rootSignatureGenerator(value) value
#define _79154538_optionalFile(value) value
#define _79154538_optionalLine(value) value
#define _79154538_optionalUserData(value) value
#define _79154538_rteParameters(value) value
#else
typedef struct _s_79154538_rootSignatureGenerator { RedXRteHandleRootSignatureGenerator value; } _s_79154538_rootSignatureGenerator;
typedef struct _s_79154538_optionalFile { char* value; } _s_79154538_optionalFile;
typedef struct _s_79154538_optionalLine { int value; } _s_79154538_optionalLine;
typedef struct _s_79154538_optionalUserData { void* value; } _s_79154538_optionalUserData;
typedef struct _s_79154538_rteParameters { void* value; } _s_79154538_rteParameters;
static inline _s_79154538_rootSignatureGenerator _79154538_rootSignatureGenerator(RedXRteHandleRootSignatureGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_79154538_rootSignatureGenerator){value}; }
static inline _s_79154538_optionalFile _79154538_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_79154538_optionalFile){value}; }
static inline _s_79154538_optionalLine _79154538_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_79154538_optionalLine){value}; }
static inline _s_79154538_optionalUserData _79154538_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_79154538_optionalUserData){value}; }
static inline _s_79154538_rteParameters _79154538_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_79154538_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteDestroyRootSignatureGenerator(_s_79154538_rootSignatureGenerator rootSignatureGenerator, _s_79154538_optionalFile optionalFile, _s_79154538_optionalLine optionalLine, _s_79154538_optionalUserData optionalUserData, _s_79154538_rteParameters rteParameters) {
  redXRteDestroyRootSignatureGenerator(rootSignatureGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteDestroyRayTracingPipelineGenerator redXRteDestroyRayTracingPipelineGenerator
#define _df8a23e4_rayTracingPipelineGenerator(value) value
#define _df8a23e4_optionalFile(value) value
#define _df8a23e4_optionalLine(value) value
#define _df8a23e4_optionalUserData(value) value
#define _df8a23e4_rteParameters(value) value
#else
typedef struct _s_df8a23e4_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_df8a23e4_rayTracingPipelineGenerator;
typedef struct _s_df8a23e4_optionalFile { char* value; } _s_df8a23e4_optionalFile;
typedef struct _s_df8a23e4_optionalLine { int value; } _s_df8a23e4_optionalLine;
typedef struct _s_df8a23e4_optionalUserData { void* value; } _s_df8a23e4_optionalUserData;
typedef struct _s_df8a23e4_rteParameters { void* value; } _s_df8a23e4_rteParameters;
static inline _s_df8a23e4_rayTracingPipelineGenerator _df8a23e4_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_df8a23e4_rayTracingPipelineGenerator){value}; }
static inline _s_df8a23e4_optionalFile _df8a23e4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_df8a23e4_optionalFile){value}; }
static inline _s_df8a23e4_optionalLine _df8a23e4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_df8a23e4_optionalLine){value}; }
static inline _s_df8a23e4_optionalUserData _df8a23e4_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_df8a23e4_optionalUserData){value}; }
static inline _s_df8a23e4_rteParameters _df8a23e4_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_df8a23e4_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteDestroyRayTracingPipelineGenerator(_s_df8a23e4_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_df8a23e4_optionalFile optionalFile, _s_df8a23e4_optionalLine optionalLine, _s_df8a23e4_optionalUserData optionalUserData, _s_df8a23e4_rteParameters rteParameters) {
  redXRteDestroyRayTracingPipelineGenerator(rayTracingPipelineGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteDestroyShaderBindingTableGenerator redXRteDestroyShaderBindingTableGenerator
#define _1ec013a2_shaderBindingTableGenerator(value) value
#define _1ec013a2_optionalFile(value) value
#define _1ec013a2_optionalLine(value) value
#define _1ec013a2_optionalUserData(value) value
#define _1ec013a2_rteParameters(value) value
#else
typedef struct _s_1ec013a2_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_1ec013a2_shaderBindingTableGenerator;
typedef struct _s_1ec013a2_optionalFile { char* value; } _s_1ec013a2_optionalFile;
typedef struct _s_1ec013a2_optionalLine { int value; } _s_1ec013a2_optionalLine;
typedef struct _s_1ec013a2_optionalUserData { void* value; } _s_1ec013a2_optionalUserData;
typedef struct _s_1ec013a2_rteParameters { void* value; } _s_1ec013a2_rteParameters;
static inline _s_1ec013a2_shaderBindingTableGenerator _1ec013a2_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_1ec013a2_shaderBindingTableGenerator){value}; }
static inline _s_1ec013a2_optionalFile _1ec013a2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1ec013a2_optionalFile){value}; }
static inline _s_1ec013a2_optionalLine _1ec013a2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1ec013a2_optionalLine){value}; }
static inline _s_1ec013a2_optionalUserData _1ec013a2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1ec013a2_optionalUserData){value}; }
static inline _s_1ec013a2_rteParameters _1ec013a2_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1ec013a2_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteDestroyShaderBindingTableGenerator(_s_1ec013a2_shaderBindingTableGenerator shaderBindingTableGenerator, _s_1ec013a2_optionalFile optionalFile, _s_1ec013a2_optionalLine optionalLine, _s_1ec013a2_optionalUserData optionalUserData, _s_1ec013a2_rteParameters rteParameters) {
  redXRteDestroyShaderBindingTableGenerator(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteBottomLevelASGeneratorAddVertexBuffer redXRteBottomLevelASGeneratorAddVertexBuffer
#define _1d57153e_bottomLevelASGenerator(value) value
#define _1d57153e_vertexBuffer_ID3D12Resource(value) value
#define _1d57153e_vertexOffsetInBytes(value) value
#define _1d57153e_vertexCount(value) value
#define _1d57153e_vertexSizeInBytes(value) value
#define _1d57153e_transformBuffer_ID3D12Resource(value) value
#define _1d57153e_transformOffsetInBytes(value) value
#define _1d57153e_isOpaqueSuggestedDefaultValueIs1(value) value
#define _1d57153e_optionalFile(value) value
#define _1d57153e_optionalLine(value) value
#define _1d57153e_optionalUserData(value) value
#define _1d57153e_rteParameters(value) value
#else
typedef struct _s_1d57153e_bottomLevelASGenerator { RedXRteHandleBottomLevelASGenerator value; } _s_1d57153e_bottomLevelASGenerator;
typedef struct _s_1d57153e_vertexBuffer_ID3D12Resource { void* value; } _s_1d57153e_vertexBuffer_ID3D12Resource;
typedef struct _s_1d57153e_vertexOffsetInBytes { uint64_t value; } _s_1d57153e_vertexOffsetInBytes;
typedef struct _s_1d57153e_vertexCount { uint32_t value; } _s_1d57153e_vertexCount;
typedef struct _s_1d57153e_vertexSizeInBytes { unsigned value; } _s_1d57153e_vertexSizeInBytes;
typedef struct _s_1d57153e_transformBuffer_ID3D12Resource { void* value; } _s_1d57153e_transformBuffer_ID3D12Resource;
typedef struct _s_1d57153e_transformOffsetInBytes { uint64_t value; } _s_1d57153e_transformOffsetInBytes;
typedef struct _s_1d57153e_isOpaqueSuggestedDefaultValueIs1 { RedBool32 value; } _s_1d57153e_isOpaqueSuggestedDefaultValueIs1;
typedef struct _s_1d57153e_optionalFile { char* value; } _s_1d57153e_optionalFile;
typedef struct _s_1d57153e_optionalLine { int value; } _s_1d57153e_optionalLine;
typedef struct _s_1d57153e_optionalUserData { void* value; } _s_1d57153e_optionalUserData;
typedef struct _s_1d57153e_rteParameters { void* value; } _s_1d57153e_rteParameters;
static inline _s_1d57153e_bottomLevelASGenerator _1d57153e_bottomLevelASGenerator(RedXRteHandleBottomLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_1d57153e_bottomLevelASGenerator){value}; }
static inline _s_1d57153e_vertexBuffer_ID3D12Resource _1d57153e_vertexBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1d57153e_vertexBuffer_ID3D12Resource){value}; }
static inline _s_1d57153e_vertexOffsetInBytes _1d57153e_vertexOffsetInBytes(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_1d57153e_vertexOffsetInBytes){value}; }
static inline _s_1d57153e_vertexCount _1d57153e_vertexCount(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_1d57153e_vertexCount){value}; }
static inline _s_1d57153e_vertexSizeInBytes _1d57153e_vertexSizeInBytes(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_1d57153e_vertexSizeInBytes){value}; }
static inline _s_1d57153e_transformBuffer_ID3D12Resource _1d57153e_transformBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1d57153e_transformBuffer_ID3D12Resource){value}; }
static inline _s_1d57153e_transformOffsetInBytes _1d57153e_transformOffsetInBytes(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_1d57153e_transformOffsetInBytes){value}; }
static inline _s_1d57153e_isOpaqueSuggestedDefaultValueIs1 _1d57153e_isOpaqueSuggestedDefaultValueIs1(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_1d57153e_isOpaqueSuggestedDefaultValueIs1){value}; }
static inline _s_1d57153e_optionalFile _1d57153e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1d57153e_optionalFile){value}; }
static inline _s_1d57153e_optionalLine _1d57153e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1d57153e_optionalLine){value}; }
static inline _s_1d57153e_optionalUserData _1d57153e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1d57153e_optionalUserData){value}; }
static inline _s_1d57153e_rteParameters _1d57153e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1d57153e_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteBottomLevelASGeneratorAddVertexBuffer(_s_1d57153e_bottomLevelASGenerator bottomLevelASGenerator, _s_1d57153e_vertexBuffer_ID3D12Resource vertexBuffer_ID3D12Resource, _s_1d57153e_vertexOffsetInBytes vertexOffsetInBytes, _s_1d57153e_vertexCount vertexCount, _s_1d57153e_vertexSizeInBytes vertexSizeInBytes, _s_1d57153e_transformBuffer_ID3D12Resource transformBuffer_ID3D12Resource, _s_1d57153e_transformOffsetInBytes transformOffsetInBytes, _s_1d57153e_isOpaqueSuggestedDefaultValueIs1 isOpaqueSuggestedDefaultValueIs1, _s_1d57153e_optionalFile optionalFile, _s_1d57153e_optionalLine optionalLine, _s_1d57153e_optionalUserData optionalUserData, _s_1d57153e_rteParameters rteParameters) {
  redXRteBottomLevelASGeneratorAddVertexBuffer(bottomLevelASGenerator.value, vertexBuffer_ID3D12Resource.value, vertexOffsetInBytes.value, vertexCount.value, vertexSizeInBytes.value, transformBuffer_ID3D12Resource.value, transformOffsetInBytes.value, isOpaqueSuggestedDefaultValueIs1.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteBottomLevelASGeneratorAddVertexIndexBuffer redXRteBottomLevelASGeneratorAddVertexIndexBuffer
#define _f5335e93_bottomLevelASGenerator(value) value
#define _f5335e93_vertexBuffer_ID3D12Resource(value) value
#define _f5335e93_vertexOffsetInBytes(value) value
#define _f5335e93_vertexCount(value) value
#define _f5335e93_vertexSizeInBytes(value) value
#define _f5335e93_indexBuffer_ID3D12Resource(value) value
#define _f5335e93_indexOffsetInBytes(value) value
#define _f5335e93_indexCount(value) value
#define _f5335e93_transformBuffer_ID3D12Resource(value) value
#define _f5335e93_transformOffsetInBytes(value) value
#define _f5335e93_isOpaqueSuggestedDefaultValueIs1(value) value
#define _f5335e93_optionalFile(value) value
#define _f5335e93_optionalLine(value) value
#define _f5335e93_optionalUserData(value) value
#define _f5335e93_rteParameters(value) value
#else
typedef struct _s_f5335e93_bottomLevelASGenerator { RedXRteHandleBottomLevelASGenerator value; } _s_f5335e93_bottomLevelASGenerator;
typedef struct _s_f5335e93_vertexBuffer_ID3D12Resource { void* value; } _s_f5335e93_vertexBuffer_ID3D12Resource;
typedef struct _s_f5335e93_vertexOffsetInBytes { uint64_t value; } _s_f5335e93_vertexOffsetInBytes;
typedef struct _s_f5335e93_vertexCount { uint32_t value; } _s_f5335e93_vertexCount;
typedef struct _s_f5335e93_vertexSizeInBytes { unsigned value; } _s_f5335e93_vertexSizeInBytes;
typedef struct _s_f5335e93_indexBuffer_ID3D12Resource { void* value; } _s_f5335e93_indexBuffer_ID3D12Resource;
typedef struct _s_f5335e93_indexOffsetInBytes { uint64_t value; } _s_f5335e93_indexOffsetInBytes;
typedef struct _s_f5335e93_indexCount { uint32_t value; } _s_f5335e93_indexCount;
typedef struct _s_f5335e93_transformBuffer_ID3D12Resource { void* value; } _s_f5335e93_transformBuffer_ID3D12Resource;
typedef struct _s_f5335e93_transformOffsetInBytes { uint64_t value; } _s_f5335e93_transformOffsetInBytes;
typedef struct _s_f5335e93_isOpaqueSuggestedDefaultValueIs1 { RedBool32 value; } _s_f5335e93_isOpaqueSuggestedDefaultValueIs1;
typedef struct _s_f5335e93_optionalFile { char* value; } _s_f5335e93_optionalFile;
typedef struct _s_f5335e93_optionalLine { int value; } _s_f5335e93_optionalLine;
typedef struct _s_f5335e93_optionalUserData { void* value; } _s_f5335e93_optionalUserData;
typedef struct _s_f5335e93_rteParameters { void* value; } _s_f5335e93_rteParameters;
static inline _s_f5335e93_bottomLevelASGenerator _f5335e93_bottomLevelASGenerator(RedXRteHandleBottomLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_bottomLevelASGenerator){value}; }
static inline _s_f5335e93_vertexBuffer_ID3D12Resource _f5335e93_vertexBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_vertexBuffer_ID3D12Resource){value}; }
static inline _s_f5335e93_vertexOffsetInBytes _f5335e93_vertexOffsetInBytes(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_vertexOffsetInBytes){value}; }
static inline _s_f5335e93_vertexCount _f5335e93_vertexCount(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_vertexCount){value}; }
static inline _s_f5335e93_vertexSizeInBytes _f5335e93_vertexSizeInBytes(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_vertexSizeInBytes){value}; }
static inline _s_f5335e93_indexBuffer_ID3D12Resource _f5335e93_indexBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_indexBuffer_ID3D12Resource){value}; }
static inline _s_f5335e93_indexOffsetInBytes _f5335e93_indexOffsetInBytes(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_indexOffsetInBytes){value}; }
static inline _s_f5335e93_indexCount _f5335e93_indexCount(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_indexCount){value}; }
static inline _s_f5335e93_transformBuffer_ID3D12Resource _f5335e93_transformBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_transformBuffer_ID3D12Resource){value}; }
static inline _s_f5335e93_transformOffsetInBytes _f5335e93_transformOffsetInBytes(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_transformOffsetInBytes){value}; }
static inline _s_f5335e93_isOpaqueSuggestedDefaultValueIs1 _f5335e93_isOpaqueSuggestedDefaultValueIs1(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_isOpaqueSuggestedDefaultValueIs1){value}; }
static inline _s_f5335e93_optionalFile _f5335e93_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_optionalFile){value}; }
static inline _s_f5335e93_optionalLine _f5335e93_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_optionalLine){value}; }
static inline _s_f5335e93_optionalUserData _f5335e93_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_optionalUserData){value}; }
static inline _s_f5335e93_rteParameters _f5335e93_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f5335e93_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteBottomLevelASGeneratorAddVertexIndexBuffer(_s_f5335e93_bottomLevelASGenerator bottomLevelASGenerator, _s_f5335e93_vertexBuffer_ID3D12Resource vertexBuffer_ID3D12Resource, _s_f5335e93_vertexOffsetInBytes vertexOffsetInBytes, _s_f5335e93_vertexCount vertexCount, _s_f5335e93_vertexSizeInBytes vertexSizeInBytes, _s_f5335e93_indexBuffer_ID3D12Resource indexBuffer_ID3D12Resource, _s_f5335e93_indexOffsetInBytes indexOffsetInBytes, _s_f5335e93_indexCount indexCount, _s_f5335e93_transformBuffer_ID3D12Resource transformBuffer_ID3D12Resource, _s_f5335e93_transformOffsetInBytes transformOffsetInBytes, _s_f5335e93_isOpaqueSuggestedDefaultValueIs1 isOpaqueSuggestedDefaultValueIs1, _s_f5335e93_optionalFile optionalFile, _s_f5335e93_optionalLine optionalLine, _s_f5335e93_optionalUserData optionalUserData, _s_f5335e93_rteParameters rteParameters) {
  redXRteBottomLevelASGeneratorAddVertexIndexBuffer(bottomLevelASGenerator.value, vertexBuffer_ID3D12Resource.value, vertexOffsetInBytes.value, vertexCount.value, vertexSizeInBytes.value, indexBuffer_ID3D12Resource.value, indexOffsetInBytes.value, indexCount.value, transformBuffer_ID3D12Resource.value, transformOffsetInBytes.value, isOpaqueSuggestedDefaultValueIs1.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteBottomLevelASGeneratorComputeASBufferSizes redXRteBottomLevelASGeneratorComputeASBufferSizes
#define _079d4826_bottomLevelASGenerator(value) value
#define _079d4826_device_ID3D12Device5(value) value
#define _079d4826_allowUpdate(value) value
#define _079d4826_scratchSizeInBytes(value) value
#define _079d4826_resultSizeInBytes(value) value
#define _079d4826_optionalFile(value) value
#define _079d4826_optionalLine(value) value
#define _079d4826_optionalUserData(value) value
#define _079d4826_rteParameters(value) value
#else
typedef struct _s_079d4826_bottomLevelASGenerator { RedXRteHandleBottomLevelASGenerator value; } _s_079d4826_bottomLevelASGenerator;
typedef struct _s_079d4826_device_ID3D12Device5 { void* value; } _s_079d4826_device_ID3D12Device5;
typedef struct _s_079d4826_allowUpdate { RedBool32 value; } _s_079d4826_allowUpdate;
typedef struct _s_079d4826_scratchSizeInBytes { uint64_t* value; } _s_079d4826_scratchSizeInBytes;
typedef struct _s_079d4826_resultSizeInBytes { uint64_t* value; } _s_079d4826_resultSizeInBytes;
typedef struct _s_079d4826_optionalFile { char* value; } _s_079d4826_optionalFile;
typedef struct _s_079d4826_optionalLine { int value; } _s_079d4826_optionalLine;
typedef struct _s_079d4826_optionalUserData { void* value; } _s_079d4826_optionalUserData;
typedef struct _s_079d4826_rteParameters { void* value; } _s_079d4826_rteParameters;
static inline _s_079d4826_bottomLevelASGenerator _079d4826_bottomLevelASGenerator(RedXRteHandleBottomLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_079d4826_bottomLevelASGenerator){value}; }
static inline _s_079d4826_device_ID3D12Device5 _079d4826_device_ID3D12Device5(void* value) { return REDGPU_NP_STRUCT_INIT(_s_079d4826_device_ID3D12Device5){value}; }
static inline _s_079d4826_allowUpdate _079d4826_allowUpdate(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_079d4826_allowUpdate){value}; }
static inline _s_079d4826_scratchSizeInBytes _079d4826_scratchSizeInBytes(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_079d4826_scratchSizeInBytes){value}; }
static inline _s_079d4826_resultSizeInBytes _079d4826_resultSizeInBytes(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_079d4826_resultSizeInBytes){value}; }
static inline _s_079d4826_optionalFile _079d4826_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_079d4826_optionalFile){value}; }
static inline _s_079d4826_optionalLine _079d4826_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_079d4826_optionalLine){value}; }
static inline _s_079d4826_optionalUserData _079d4826_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_079d4826_optionalUserData){value}; }
static inline _s_079d4826_rteParameters _079d4826_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_079d4826_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteBottomLevelASGeneratorComputeASBufferSizes(_s_079d4826_bottomLevelASGenerator bottomLevelASGenerator, _s_079d4826_device_ID3D12Device5 device_ID3D12Device5, _s_079d4826_allowUpdate allowUpdate, _s_079d4826_scratchSizeInBytes scratchSizeInBytes, _s_079d4826_resultSizeInBytes resultSizeInBytes, _s_079d4826_optionalFile optionalFile, _s_079d4826_optionalLine optionalLine, _s_079d4826_optionalUserData optionalUserData, _s_079d4826_rteParameters rteParameters) {
  redXRteBottomLevelASGeneratorComputeASBufferSizes(bottomLevelASGenerator.value, device_ID3D12Device5.value, allowUpdate.value, scratchSizeInBytes.value, resultSizeInBytes.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteBottomLevelASGeneratorGenerate redXRteBottomLevelASGeneratorGenerate
#define _f6e0bf6c_bottomLevelASGenerator(value) value
#define _f6e0bf6c_commandList_ID3D12GraphicsCommandList4(value) value
#define _f6e0bf6c_scratchBuffer_ID3D12Resource(value) value
#define _f6e0bf6c_resultBuffer_ID3D12Resource(value) value
#define _f6e0bf6c_isUpdateOnlySuggestedDefaultValueIs0(value) value
#define _f6e0bf6c_previousResultSuggestedDefaultValueIsNull_ID3D12Resource(value) value
#define _f6e0bf6c_optionalFile(value) value
#define _f6e0bf6c_optionalLine(value) value
#define _f6e0bf6c_optionalUserData(value) value
#define _f6e0bf6c_rteParameters(value) value
#else
typedef struct _s_f6e0bf6c_bottomLevelASGenerator { RedXRteHandleBottomLevelASGenerator value; } _s_f6e0bf6c_bottomLevelASGenerator;
typedef struct _s_f6e0bf6c_commandList_ID3D12GraphicsCommandList4 { void* value; } _s_f6e0bf6c_commandList_ID3D12GraphicsCommandList4;
typedef struct _s_f6e0bf6c_scratchBuffer_ID3D12Resource { void* value; } _s_f6e0bf6c_scratchBuffer_ID3D12Resource;
typedef struct _s_f6e0bf6c_resultBuffer_ID3D12Resource { void* value; } _s_f6e0bf6c_resultBuffer_ID3D12Resource;
typedef struct _s_f6e0bf6c_isUpdateOnlySuggestedDefaultValueIs0 { RedBool32 value; } _s_f6e0bf6c_isUpdateOnlySuggestedDefaultValueIs0;
typedef struct _s_f6e0bf6c_previousResultSuggestedDefaultValueIsNull_ID3D12Resource { void* value; } _s_f6e0bf6c_previousResultSuggestedDefaultValueIsNull_ID3D12Resource;
typedef struct _s_f6e0bf6c_optionalFile { char* value; } _s_f6e0bf6c_optionalFile;
typedef struct _s_f6e0bf6c_optionalLine { int value; } _s_f6e0bf6c_optionalLine;
typedef struct _s_f6e0bf6c_optionalUserData { void* value; } _s_f6e0bf6c_optionalUserData;
typedef struct _s_f6e0bf6c_rteParameters { void* value; } _s_f6e0bf6c_rteParameters;
static inline _s_f6e0bf6c_bottomLevelASGenerator _f6e0bf6c_bottomLevelASGenerator(RedXRteHandleBottomLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_f6e0bf6c_bottomLevelASGenerator){value}; }
static inline _s_f6e0bf6c_commandList_ID3D12GraphicsCommandList4 _f6e0bf6c_commandList_ID3D12GraphicsCommandList4(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f6e0bf6c_commandList_ID3D12GraphicsCommandList4){value}; }
static inline _s_f6e0bf6c_scratchBuffer_ID3D12Resource _f6e0bf6c_scratchBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f6e0bf6c_scratchBuffer_ID3D12Resource){value}; }
static inline _s_f6e0bf6c_resultBuffer_ID3D12Resource _f6e0bf6c_resultBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f6e0bf6c_resultBuffer_ID3D12Resource){value}; }
static inline _s_f6e0bf6c_isUpdateOnlySuggestedDefaultValueIs0 _f6e0bf6c_isUpdateOnlySuggestedDefaultValueIs0(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_f6e0bf6c_isUpdateOnlySuggestedDefaultValueIs0){value}; }
static inline _s_f6e0bf6c_previousResultSuggestedDefaultValueIsNull_ID3D12Resource _f6e0bf6c_previousResultSuggestedDefaultValueIsNull_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f6e0bf6c_previousResultSuggestedDefaultValueIsNull_ID3D12Resource){value}; }
static inline _s_f6e0bf6c_optionalFile _f6e0bf6c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f6e0bf6c_optionalFile){value}; }
static inline _s_f6e0bf6c_optionalLine _f6e0bf6c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f6e0bf6c_optionalLine){value}; }
static inline _s_f6e0bf6c_optionalUserData _f6e0bf6c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f6e0bf6c_optionalUserData){value}; }
static inline _s_f6e0bf6c_rteParameters _f6e0bf6c_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f6e0bf6c_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteBottomLevelASGeneratorGenerate(_s_f6e0bf6c_bottomLevelASGenerator bottomLevelASGenerator, _s_f6e0bf6c_commandList_ID3D12GraphicsCommandList4 commandList_ID3D12GraphicsCommandList4, _s_f6e0bf6c_scratchBuffer_ID3D12Resource scratchBuffer_ID3D12Resource, _s_f6e0bf6c_resultBuffer_ID3D12Resource resultBuffer_ID3D12Resource, _s_f6e0bf6c_isUpdateOnlySuggestedDefaultValueIs0 isUpdateOnlySuggestedDefaultValueIs0, _s_f6e0bf6c_previousResultSuggestedDefaultValueIsNull_ID3D12Resource previousResultSuggestedDefaultValueIsNull_ID3D12Resource, _s_f6e0bf6c_optionalFile optionalFile, _s_f6e0bf6c_optionalLine optionalLine, _s_f6e0bf6c_optionalUserData optionalUserData, _s_f6e0bf6c_rteParameters rteParameters) {
  redXRteBottomLevelASGeneratorGenerate(bottomLevelASGenerator.value, commandList_ID3D12GraphicsCommandList4.value, scratchBuffer_ID3D12Resource.value, resultBuffer_ID3D12Resource.value, isUpdateOnlySuggestedDefaultValueIs0.value, previousResultSuggestedDefaultValueIsNull_ID3D12Resource.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteTopLevelASGeneratorSetInstancesCount redXRteTopLevelASGeneratorSetInstancesCount
#define _88ada52f_topLevelASGenerator(value) value
#define _88ada52f_instancesCount(value) value
#define _88ada52f_optionalFile(value) value
#define _88ada52f_optionalLine(value) value
#define _88ada52f_optionalUserData(value) value
#define _88ada52f_rteParameters(value) value
#else
typedef struct _s_88ada52f_topLevelASGenerator { RedXRteHandleTopLevelASGenerator value; } _s_88ada52f_topLevelASGenerator;
typedef struct _s_88ada52f_instancesCount { unsigned value; } _s_88ada52f_instancesCount;
typedef struct _s_88ada52f_optionalFile { char* value; } _s_88ada52f_optionalFile;
typedef struct _s_88ada52f_optionalLine { int value; } _s_88ada52f_optionalLine;
typedef struct _s_88ada52f_optionalUserData { void* value; } _s_88ada52f_optionalUserData;
typedef struct _s_88ada52f_rteParameters { void* value; } _s_88ada52f_rteParameters;
static inline _s_88ada52f_topLevelASGenerator _88ada52f_topLevelASGenerator(RedXRteHandleTopLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_88ada52f_topLevelASGenerator){value}; }
static inline _s_88ada52f_instancesCount _88ada52f_instancesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_88ada52f_instancesCount){value}; }
static inline _s_88ada52f_optionalFile _88ada52f_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_88ada52f_optionalFile){value}; }
static inline _s_88ada52f_optionalLine _88ada52f_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_88ada52f_optionalLine){value}; }
static inline _s_88ada52f_optionalUserData _88ada52f_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_88ada52f_optionalUserData){value}; }
static inline _s_88ada52f_rteParameters _88ada52f_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_88ada52f_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteTopLevelASGeneratorSetInstancesCount(_s_88ada52f_topLevelASGenerator topLevelASGenerator, _s_88ada52f_instancesCount instancesCount, _s_88ada52f_optionalFile optionalFile, _s_88ada52f_optionalLine optionalLine, _s_88ada52f_optionalUserData optionalUserData, _s_88ada52f_rteParameters rteParameters) {
  redXRteTopLevelASGeneratorSetInstancesCount(topLevelASGenerator.value, instancesCount.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteTopLevelASGeneratorComputeASBufferSizes redXRteTopLevelASGeneratorComputeASBufferSizes
#define _eaf82f5e_topLevelASGenerator(value) value
#define _eaf82f5e_device_ID3D12Device5(value) value
#define _eaf82f5e_allowUpdate(value) value
#define _eaf82f5e_scratchSizeInBytes(value) value
#define _eaf82f5e_resultSizeInBytes(value) value
#define _eaf82f5e_descriptorsSizeInBytes(value) value
#define _eaf82f5e_optionalFile(value) value
#define _eaf82f5e_optionalLine(value) value
#define _eaf82f5e_optionalUserData(value) value
#define _eaf82f5e_rteParameters(value) value
#else
typedef struct _s_eaf82f5e_topLevelASGenerator { RedXRteHandleTopLevelASGenerator value; } _s_eaf82f5e_topLevelASGenerator;
typedef struct _s_eaf82f5e_device_ID3D12Device5 { void* value; } _s_eaf82f5e_device_ID3D12Device5;
typedef struct _s_eaf82f5e_allowUpdate { RedBool32 value; } _s_eaf82f5e_allowUpdate;
typedef struct _s_eaf82f5e_scratchSizeInBytes { uint64_t* value; } _s_eaf82f5e_scratchSizeInBytes;
typedef struct _s_eaf82f5e_resultSizeInBytes { uint64_t* value; } _s_eaf82f5e_resultSizeInBytes;
typedef struct _s_eaf82f5e_descriptorsSizeInBytes { uint64_t* value; } _s_eaf82f5e_descriptorsSizeInBytes;
typedef struct _s_eaf82f5e_optionalFile { char* value; } _s_eaf82f5e_optionalFile;
typedef struct _s_eaf82f5e_optionalLine { int value; } _s_eaf82f5e_optionalLine;
typedef struct _s_eaf82f5e_optionalUserData { void* value; } _s_eaf82f5e_optionalUserData;
typedef struct _s_eaf82f5e_rteParameters { void* value; } _s_eaf82f5e_rteParameters;
static inline _s_eaf82f5e_topLevelASGenerator _eaf82f5e_topLevelASGenerator(RedXRteHandleTopLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_eaf82f5e_topLevelASGenerator){value}; }
static inline _s_eaf82f5e_device_ID3D12Device5 _eaf82f5e_device_ID3D12Device5(void* value) { return REDGPU_NP_STRUCT_INIT(_s_eaf82f5e_device_ID3D12Device5){value}; }
static inline _s_eaf82f5e_allowUpdate _eaf82f5e_allowUpdate(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_eaf82f5e_allowUpdate){value}; }
static inline _s_eaf82f5e_scratchSizeInBytes _eaf82f5e_scratchSizeInBytes(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_eaf82f5e_scratchSizeInBytes){value}; }
static inline _s_eaf82f5e_resultSizeInBytes _eaf82f5e_resultSizeInBytes(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_eaf82f5e_resultSizeInBytes){value}; }
static inline _s_eaf82f5e_descriptorsSizeInBytes _eaf82f5e_descriptorsSizeInBytes(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_eaf82f5e_descriptorsSizeInBytes){value}; }
static inline _s_eaf82f5e_optionalFile _eaf82f5e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_eaf82f5e_optionalFile){value}; }
static inline _s_eaf82f5e_optionalLine _eaf82f5e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_eaf82f5e_optionalLine){value}; }
static inline _s_eaf82f5e_optionalUserData _eaf82f5e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_eaf82f5e_optionalUserData){value}; }
static inline _s_eaf82f5e_rteParameters _eaf82f5e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_eaf82f5e_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteTopLevelASGeneratorComputeASBufferSizes(_s_eaf82f5e_topLevelASGenerator topLevelASGenerator, _s_eaf82f5e_device_ID3D12Device5 device_ID3D12Device5, _s_eaf82f5e_allowUpdate allowUpdate, _s_eaf82f5e_scratchSizeInBytes scratchSizeInBytes, _s_eaf82f5e_resultSizeInBytes resultSizeInBytes, _s_eaf82f5e_descriptorsSizeInBytes descriptorsSizeInBytes, _s_eaf82f5e_optionalFile optionalFile, _s_eaf82f5e_optionalLine optionalLine, _s_eaf82f5e_optionalUserData optionalUserData, _s_eaf82f5e_rteParameters rteParameters) {
  redXRteTopLevelASGeneratorComputeASBufferSizes(topLevelASGenerator.value, device_ID3D12Device5.value, allowUpdate.value, scratchSizeInBytes.value, resultSizeInBytes.value, descriptorsSizeInBytes.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteTopLevelASGeneratorGenerate redXRteTopLevelASGeneratorGenerate
#define _69d9e76a_topLevelASGenerator(value) value
#define _69d9e76a_commandList_ID3D12GraphicsCommandList4(value) value
#define _69d9e76a_scratchBuffer_ID3D12Resource(value) value
#define _69d9e76a_resultBuffer_ID3D12Resource(value) value
#define _69d9e76a_descriptorsBuffer_ID3D12Resource(value) value
#define _69d9e76a_isUpdateOnlySuggestedDefaultValueIs0(value) value
#define _69d9e76a_previousResultSuggestedDefaultValueIsNull_ID3D12Resource(value) value
#define _69d9e76a_optionalFile(value) value
#define _69d9e76a_optionalLine(value) value
#define _69d9e76a_optionalUserData(value) value
#define _69d9e76a_rteParameters(value) value
#else
typedef struct _s_69d9e76a_topLevelASGenerator { RedXRteHandleTopLevelASGenerator value; } _s_69d9e76a_topLevelASGenerator;
typedef struct _s_69d9e76a_commandList_ID3D12GraphicsCommandList4 { void* value; } _s_69d9e76a_commandList_ID3D12GraphicsCommandList4;
typedef struct _s_69d9e76a_scratchBuffer_ID3D12Resource { void* value; } _s_69d9e76a_scratchBuffer_ID3D12Resource;
typedef struct _s_69d9e76a_resultBuffer_ID3D12Resource { void* value; } _s_69d9e76a_resultBuffer_ID3D12Resource;
typedef struct _s_69d9e76a_descriptorsBuffer_ID3D12Resource { void* value; } _s_69d9e76a_descriptorsBuffer_ID3D12Resource;
typedef struct _s_69d9e76a_isUpdateOnlySuggestedDefaultValueIs0 { RedBool32 value; } _s_69d9e76a_isUpdateOnlySuggestedDefaultValueIs0;
typedef struct _s_69d9e76a_previousResultSuggestedDefaultValueIsNull_ID3D12Resource { void* value; } _s_69d9e76a_previousResultSuggestedDefaultValueIsNull_ID3D12Resource;
typedef struct _s_69d9e76a_optionalFile { char* value; } _s_69d9e76a_optionalFile;
typedef struct _s_69d9e76a_optionalLine { int value; } _s_69d9e76a_optionalLine;
typedef struct _s_69d9e76a_optionalUserData { void* value; } _s_69d9e76a_optionalUserData;
typedef struct _s_69d9e76a_rteParameters { void* value; } _s_69d9e76a_rteParameters;
static inline _s_69d9e76a_topLevelASGenerator _69d9e76a_topLevelASGenerator(RedXRteHandleTopLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_69d9e76a_topLevelASGenerator){value}; }
static inline _s_69d9e76a_commandList_ID3D12GraphicsCommandList4 _69d9e76a_commandList_ID3D12GraphicsCommandList4(void* value) { return REDGPU_NP_STRUCT_INIT(_s_69d9e76a_commandList_ID3D12GraphicsCommandList4){value}; }
static inline _s_69d9e76a_scratchBuffer_ID3D12Resource _69d9e76a_scratchBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_69d9e76a_scratchBuffer_ID3D12Resource){value}; }
static inline _s_69d9e76a_resultBuffer_ID3D12Resource _69d9e76a_resultBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_69d9e76a_resultBuffer_ID3D12Resource){value}; }
static inline _s_69d9e76a_descriptorsBuffer_ID3D12Resource _69d9e76a_descriptorsBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_69d9e76a_descriptorsBuffer_ID3D12Resource){value}; }
static inline _s_69d9e76a_isUpdateOnlySuggestedDefaultValueIs0 _69d9e76a_isUpdateOnlySuggestedDefaultValueIs0(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_69d9e76a_isUpdateOnlySuggestedDefaultValueIs0){value}; }
static inline _s_69d9e76a_previousResultSuggestedDefaultValueIsNull_ID3D12Resource _69d9e76a_previousResultSuggestedDefaultValueIsNull_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_69d9e76a_previousResultSuggestedDefaultValueIsNull_ID3D12Resource){value}; }
static inline _s_69d9e76a_optionalFile _69d9e76a_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_69d9e76a_optionalFile){value}; }
static inline _s_69d9e76a_optionalLine _69d9e76a_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_69d9e76a_optionalLine){value}; }
static inline _s_69d9e76a_optionalUserData _69d9e76a_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_69d9e76a_optionalUserData){value}; }
static inline _s_69d9e76a_rteParameters _69d9e76a_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_69d9e76a_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteTopLevelASGeneratorGenerate(_s_69d9e76a_topLevelASGenerator topLevelASGenerator, _s_69d9e76a_commandList_ID3D12GraphicsCommandList4 commandList_ID3D12GraphicsCommandList4, _s_69d9e76a_scratchBuffer_ID3D12Resource scratchBuffer_ID3D12Resource, _s_69d9e76a_resultBuffer_ID3D12Resource resultBuffer_ID3D12Resource, _s_69d9e76a_descriptorsBuffer_ID3D12Resource descriptorsBuffer_ID3D12Resource, _s_69d9e76a_isUpdateOnlySuggestedDefaultValueIs0 isUpdateOnlySuggestedDefaultValueIs0, _s_69d9e76a_previousResultSuggestedDefaultValueIsNull_ID3D12Resource previousResultSuggestedDefaultValueIsNull_ID3D12Resource, _s_69d9e76a_optionalFile optionalFile, _s_69d9e76a_optionalLine optionalLine, _s_69d9e76a_optionalUserData optionalUserData, _s_69d9e76a_rteParameters rteParameters) {
  redXRteTopLevelASGeneratorGenerate(topLevelASGenerator.value, commandList_ID3D12GraphicsCommandList4.value, scratchBuffer_ID3D12Resource.value, resultBuffer_ID3D12Resource.value, descriptorsBuffer_ID3D12Resource.value, isUpdateOnlySuggestedDefaultValueIs0.value, previousResultSuggestedDefaultValueIsNull_ID3D12Resource.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRootSignatureGeneratorAddHeapRangesParameter redXRteRootSignatureGeneratorAddHeapRangesParameter
#define _99cb78c9_rootSignatureGenerator(value) value
#define _99cb78c9_rangesCount(value) value
#define _99cb78c9_ranges_D3D12_DESCRIPTOR_RANGE(value) value
#define _99cb78c9_optionalFile(value) value
#define _99cb78c9_optionalLine(value) value
#define _99cb78c9_optionalUserData(value) value
#define _99cb78c9_rteParameters(value) value
#else
typedef struct _s_99cb78c9_rootSignatureGenerator { RedXRteHandleRootSignatureGenerator value; } _s_99cb78c9_rootSignatureGenerator;
typedef struct _s_99cb78c9_rangesCount { uint64_t value; } _s_99cb78c9_rangesCount;
typedef struct _s_99cb78c9_ranges_D3D12_DESCRIPTOR_RANGE { void* value; } _s_99cb78c9_ranges_D3D12_DESCRIPTOR_RANGE;
typedef struct _s_99cb78c9_optionalFile { char* value; } _s_99cb78c9_optionalFile;
typedef struct _s_99cb78c9_optionalLine { int value; } _s_99cb78c9_optionalLine;
typedef struct _s_99cb78c9_optionalUserData { void* value; } _s_99cb78c9_optionalUserData;
typedef struct _s_99cb78c9_rteParameters { void* value; } _s_99cb78c9_rteParameters;
static inline _s_99cb78c9_rootSignatureGenerator _99cb78c9_rootSignatureGenerator(RedXRteHandleRootSignatureGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_99cb78c9_rootSignatureGenerator){value}; }
static inline _s_99cb78c9_rangesCount _99cb78c9_rangesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_99cb78c9_rangesCount){value}; }
static inline _s_99cb78c9_ranges_D3D12_DESCRIPTOR_RANGE _99cb78c9_ranges_D3D12_DESCRIPTOR_RANGE(void* value) { return REDGPU_NP_STRUCT_INIT(_s_99cb78c9_ranges_D3D12_DESCRIPTOR_RANGE){value}; }
static inline _s_99cb78c9_optionalFile _99cb78c9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_99cb78c9_optionalFile){value}; }
static inline _s_99cb78c9_optionalLine _99cb78c9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_99cb78c9_optionalLine){value}; }
static inline _s_99cb78c9_optionalUserData _99cb78c9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_99cb78c9_optionalUserData){value}; }
static inline _s_99cb78c9_rteParameters _99cb78c9_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_99cb78c9_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRootSignatureGeneratorAddHeapRangesParameter(_s_99cb78c9_rootSignatureGenerator rootSignatureGenerator, _s_99cb78c9_rangesCount rangesCount, _s_99cb78c9_ranges_D3D12_DESCRIPTOR_RANGE ranges_D3D12_DESCRIPTOR_RANGE, _s_99cb78c9_optionalFile optionalFile, _s_99cb78c9_optionalLine optionalLine, _s_99cb78c9_optionalUserData optionalUserData, _s_99cb78c9_rteParameters rteParameters) {
  redXRteRootSignatureGeneratorAddHeapRangesParameter(rootSignatureGenerator.value, rangesCount.value, ranges_D3D12_DESCRIPTOR_RANGE.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRootSignatureGeneratorAddRootParameter redXRteRootSignatureGeneratorAddRootParameter
#define _6260d546_rootSignatureGenerator(value) value
#define _6260d546_type_D3D12_ROOT_PARAMETER_TYPE(value) value
#define _6260d546_shaderRegisterSuggestedDefaultValueIs0(value) value
#define _6260d546_registerSpaceSuggestedDefaultValueIs0(value) value
#define _6260d546_numRootConstantsSuggestedDefaultValueIs1(value) value
#define _6260d546_optionalFile(value) value
#define _6260d546_optionalLine(value) value
#define _6260d546_optionalUserData(value) value
#define _6260d546_rteParameters(value) value
#else
typedef struct _s_6260d546_rootSignatureGenerator { RedXRteHandleRootSignatureGenerator value; } _s_6260d546_rootSignatureGenerator;
typedef struct _s_6260d546_type_D3D12_ROOT_PARAMETER_TYPE { unsigned value; } _s_6260d546_type_D3D12_ROOT_PARAMETER_TYPE;
typedef struct _s_6260d546_shaderRegisterSuggestedDefaultValueIs0 { unsigned value; } _s_6260d546_shaderRegisterSuggestedDefaultValueIs0;
typedef struct _s_6260d546_registerSpaceSuggestedDefaultValueIs0 { unsigned value; } _s_6260d546_registerSpaceSuggestedDefaultValueIs0;
typedef struct _s_6260d546_numRootConstantsSuggestedDefaultValueIs1 { unsigned value; } _s_6260d546_numRootConstantsSuggestedDefaultValueIs1;
typedef struct _s_6260d546_optionalFile { char* value; } _s_6260d546_optionalFile;
typedef struct _s_6260d546_optionalLine { int value; } _s_6260d546_optionalLine;
typedef struct _s_6260d546_optionalUserData { void* value; } _s_6260d546_optionalUserData;
typedef struct _s_6260d546_rteParameters { void* value; } _s_6260d546_rteParameters;
static inline _s_6260d546_rootSignatureGenerator _6260d546_rootSignatureGenerator(RedXRteHandleRootSignatureGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_6260d546_rootSignatureGenerator){value}; }
static inline _s_6260d546_type_D3D12_ROOT_PARAMETER_TYPE _6260d546_type_D3D12_ROOT_PARAMETER_TYPE(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6260d546_type_D3D12_ROOT_PARAMETER_TYPE){value}; }
static inline _s_6260d546_shaderRegisterSuggestedDefaultValueIs0 _6260d546_shaderRegisterSuggestedDefaultValueIs0(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6260d546_shaderRegisterSuggestedDefaultValueIs0){value}; }
static inline _s_6260d546_registerSpaceSuggestedDefaultValueIs0 _6260d546_registerSpaceSuggestedDefaultValueIs0(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6260d546_registerSpaceSuggestedDefaultValueIs0){value}; }
static inline _s_6260d546_numRootConstantsSuggestedDefaultValueIs1 _6260d546_numRootConstantsSuggestedDefaultValueIs1(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_6260d546_numRootConstantsSuggestedDefaultValueIs1){value}; }
static inline _s_6260d546_optionalFile _6260d546_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6260d546_optionalFile){value}; }
static inline _s_6260d546_optionalLine _6260d546_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6260d546_optionalLine){value}; }
static inline _s_6260d546_optionalUserData _6260d546_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6260d546_optionalUserData){value}; }
static inline _s_6260d546_rteParameters _6260d546_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6260d546_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRootSignatureGeneratorAddRootParameter(_s_6260d546_rootSignatureGenerator rootSignatureGenerator, _s_6260d546_type_D3D12_ROOT_PARAMETER_TYPE type_D3D12_ROOT_PARAMETER_TYPE, _s_6260d546_shaderRegisterSuggestedDefaultValueIs0 shaderRegisterSuggestedDefaultValueIs0, _s_6260d546_registerSpaceSuggestedDefaultValueIs0 registerSpaceSuggestedDefaultValueIs0, _s_6260d546_numRootConstantsSuggestedDefaultValueIs1 numRootConstantsSuggestedDefaultValueIs1, _s_6260d546_optionalFile optionalFile, _s_6260d546_optionalLine optionalLine, _s_6260d546_optionalUserData optionalUserData, _s_6260d546_rteParameters rteParameters) {
  redXRteRootSignatureGeneratorAddRootParameter(rootSignatureGenerator.value, type_D3D12_ROOT_PARAMETER_TYPE.value, shaderRegisterSuggestedDefaultValueIs0.value, registerSpaceSuggestedDefaultValueIs0.value, numRootConstantsSuggestedDefaultValueIs1.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRootSignatureGeneratorGenerate redXRteRootSignatureGeneratorGenerate
#define _deab52ff_rootSignatureGenerator(value) value
#define _deab52ff_device_ID3D12Device(value) value
#define _deab52ff_isLocal(value) value
#define _deab52ff_outRootSignature_ID3D12RootSignature(value) value
#define _deab52ff_optionalFile(value) value
#define _deab52ff_optionalLine(value) value
#define _deab52ff_optionalUserData(value) value
#define _deab52ff_rteParameters(value) value
#else
typedef struct _s_deab52ff_rootSignatureGenerator { RedXRteHandleRootSignatureGenerator value; } _s_deab52ff_rootSignatureGenerator;
typedef struct _s_deab52ff_device_ID3D12Device { void* value; } _s_deab52ff_device_ID3D12Device;
typedef struct _s_deab52ff_isLocal { RedBool32 value; } _s_deab52ff_isLocal;
typedef struct _s_deab52ff_outRootSignature_ID3D12RootSignature { void** value; } _s_deab52ff_outRootSignature_ID3D12RootSignature;
typedef struct _s_deab52ff_optionalFile { char* value; } _s_deab52ff_optionalFile;
typedef struct _s_deab52ff_optionalLine { int value; } _s_deab52ff_optionalLine;
typedef struct _s_deab52ff_optionalUserData { void* value; } _s_deab52ff_optionalUserData;
typedef struct _s_deab52ff_rteParameters { void* value; } _s_deab52ff_rteParameters;
static inline _s_deab52ff_rootSignatureGenerator _deab52ff_rootSignatureGenerator(RedXRteHandleRootSignatureGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_deab52ff_rootSignatureGenerator){value}; }
static inline _s_deab52ff_device_ID3D12Device _deab52ff_device_ID3D12Device(void* value) { return REDGPU_NP_STRUCT_INIT(_s_deab52ff_device_ID3D12Device){value}; }
static inline _s_deab52ff_isLocal _deab52ff_isLocal(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_deab52ff_isLocal){value}; }
static inline _s_deab52ff_outRootSignature_ID3D12RootSignature _deab52ff_outRootSignature_ID3D12RootSignature(void** value) { return REDGPU_NP_STRUCT_INIT(_s_deab52ff_outRootSignature_ID3D12RootSignature){value}; }
static inline _s_deab52ff_optionalFile _deab52ff_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_deab52ff_optionalFile){value}; }
static inline _s_deab52ff_optionalLine _deab52ff_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_deab52ff_optionalLine){value}; }
static inline _s_deab52ff_optionalUserData _deab52ff_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_deab52ff_optionalUserData){value}; }
static inline _s_deab52ff_rteParameters _deab52ff_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_deab52ff_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRootSignatureGeneratorGenerate(_s_deab52ff_rootSignatureGenerator rootSignatureGenerator, _s_deab52ff_device_ID3D12Device device_ID3D12Device, _s_deab52ff_isLocal isLocal, _s_deab52ff_outRootSignature_ID3D12RootSignature outRootSignature_ID3D12RootSignature, _s_deab52ff_optionalFile optionalFile, _s_deab52ff_optionalLine optionalLine, _s_deab52ff_optionalUserData optionalUserData, _s_deab52ff_rteParameters rteParameters) {
  redXRteRootSignatureGeneratorGenerate(rootSignatureGenerator.value, device_ID3D12Device.value, isLocal.value, outRootSignature_ID3D12RootSignature.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorAddLibrary redXRteRayTracingPipelineGeneratorAddLibrary
#define _6cb56816_rayTracingPipelineGenerator(value) value
#define _6cb56816_dxilLibraryBufferSize(value) value
#define _6cb56816_dxilLibraryBufferPointer(value) value
#define _6cb56816_symbolExportsCount(value) value
#define _6cb56816_symbolExports(value) value
#define _6cb56816_optionalFile(value) value
#define _6cb56816_optionalLine(value) value
#define _6cb56816_optionalUserData(value) value
#define _6cb56816_rteParameters(value) value
#else
typedef struct _s_6cb56816_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_6cb56816_rayTracingPipelineGenerator;
typedef struct _s_6cb56816_dxilLibraryBufferSize { uint64_t value; } _s_6cb56816_dxilLibraryBufferSize;
typedef struct _s_6cb56816_dxilLibraryBufferPointer { void* value; } _s_6cb56816_dxilLibraryBufferPointer;
typedef struct _s_6cb56816_symbolExportsCount { uint64_t value; } _s_6cb56816_symbolExportsCount;
typedef struct _s_6cb56816_symbolExports { wchar_t** value; } _s_6cb56816_symbolExports;
typedef struct _s_6cb56816_optionalFile { char* value; } _s_6cb56816_optionalFile;
typedef struct _s_6cb56816_optionalLine { int value; } _s_6cb56816_optionalLine;
typedef struct _s_6cb56816_optionalUserData { void* value; } _s_6cb56816_optionalUserData;
typedef struct _s_6cb56816_rteParameters { void* value; } _s_6cb56816_rteParameters;
static inline _s_6cb56816_rayTracingPipelineGenerator _6cb56816_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_6cb56816_rayTracingPipelineGenerator){value}; }
static inline _s_6cb56816_dxilLibraryBufferSize _6cb56816_dxilLibraryBufferSize(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_6cb56816_dxilLibraryBufferSize){value}; }
static inline _s_6cb56816_dxilLibraryBufferPointer _6cb56816_dxilLibraryBufferPointer(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6cb56816_dxilLibraryBufferPointer){value}; }
static inline _s_6cb56816_symbolExportsCount _6cb56816_symbolExportsCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_6cb56816_symbolExportsCount){value}; }
static inline _s_6cb56816_symbolExports _6cb56816_symbolExports(wchar_t** value) { return REDGPU_NP_STRUCT_INIT(_s_6cb56816_symbolExports){value}; }
static inline _s_6cb56816_optionalFile _6cb56816_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6cb56816_optionalFile){value}; }
static inline _s_6cb56816_optionalLine _6cb56816_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6cb56816_optionalLine){value}; }
static inline _s_6cb56816_optionalUserData _6cb56816_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6cb56816_optionalUserData){value}; }
static inline _s_6cb56816_rteParameters _6cb56816_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6cb56816_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorAddLibrary(_s_6cb56816_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_6cb56816_dxilLibraryBufferSize dxilLibraryBufferSize, _s_6cb56816_dxilLibraryBufferPointer dxilLibraryBufferPointer, _s_6cb56816_symbolExportsCount symbolExportsCount, _s_6cb56816_symbolExports symbolExports, _s_6cb56816_optionalFile optionalFile, _s_6cb56816_optionalLine optionalLine, _s_6cb56816_optionalUserData optionalUserData, _s_6cb56816_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorAddLibrary(rayTracingPipelineGenerator.value, dxilLibraryBufferSize.value, dxilLibraryBufferPointer.value, symbolExportsCount.value, symbolExports.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorAddHitGroup redXRteRayTracingPipelineGeneratorAddHitGroup
#define _80f9b631_rayTracingPipelineGenerator(value) value
#define _80f9b631_hitGroupName(value) value
#define _80f9b631_closestHitSymbol(value) value
#define _80f9b631_anyHitSymbolSuggestedDefaultValueIsNull(value) value
#define _80f9b631_intersectionSymbolSuggestedDefaultValueIsNull(value) value
#define _80f9b631_optionalFile(value) value
#define _80f9b631_optionalLine(value) value
#define _80f9b631_optionalUserData(value) value
#define _80f9b631_rteParameters(value) value
#else
typedef struct _s_80f9b631_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_80f9b631_rayTracingPipelineGenerator;
typedef struct _s_80f9b631_hitGroupName { wchar_t* value; } _s_80f9b631_hitGroupName;
typedef struct _s_80f9b631_closestHitSymbol { wchar_t* value; } _s_80f9b631_closestHitSymbol;
typedef struct _s_80f9b631_anyHitSymbolSuggestedDefaultValueIsNull { wchar_t* value; } _s_80f9b631_anyHitSymbolSuggestedDefaultValueIsNull;
typedef struct _s_80f9b631_intersectionSymbolSuggestedDefaultValueIsNull { wchar_t* value; } _s_80f9b631_intersectionSymbolSuggestedDefaultValueIsNull;
typedef struct _s_80f9b631_optionalFile { char* value; } _s_80f9b631_optionalFile;
typedef struct _s_80f9b631_optionalLine { int value; } _s_80f9b631_optionalLine;
typedef struct _s_80f9b631_optionalUserData { void* value; } _s_80f9b631_optionalUserData;
typedef struct _s_80f9b631_rteParameters { void* value; } _s_80f9b631_rteParameters;
static inline _s_80f9b631_rayTracingPipelineGenerator _80f9b631_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_80f9b631_rayTracingPipelineGenerator){value}; }
static inline _s_80f9b631_hitGroupName _80f9b631_hitGroupName(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_80f9b631_hitGroupName){value}; }
static inline _s_80f9b631_closestHitSymbol _80f9b631_closestHitSymbol(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_80f9b631_closestHitSymbol){value}; }
static inline _s_80f9b631_anyHitSymbolSuggestedDefaultValueIsNull _80f9b631_anyHitSymbolSuggestedDefaultValueIsNull(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_80f9b631_anyHitSymbolSuggestedDefaultValueIsNull){value}; }
static inline _s_80f9b631_intersectionSymbolSuggestedDefaultValueIsNull _80f9b631_intersectionSymbolSuggestedDefaultValueIsNull(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_80f9b631_intersectionSymbolSuggestedDefaultValueIsNull){value}; }
static inline _s_80f9b631_optionalFile _80f9b631_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_80f9b631_optionalFile){value}; }
static inline _s_80f9b631_optionalLine _80f9b631_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_80f9b631_optionalLine){value}; }
static inline _s_80f9b631_optionalUserData _80f9b631_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_80f9b631_optionalUserData){value}; }
static inline _s_80f9b631_rteParameters _80f9b631_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_80f9b631_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorAddHitGroup(_s_80f9b631_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_80f9b631_hitGroupName hitGroupName, _s_80f9b631_closestHitSymbol closestHitSymbol, _s_80f9b631_anyHitSymbolSuggestedDefaultValueIsNull anyHitSymbolSuggestedDefaultValueIsNull, _s_80f9b631_intersectionSymbolSuggestedDefaultValueIsNull intersectionSymbolSuggestedDefaultValueIsNull, _s_80f9b631_optionalFile optionalFile, _s_80f9b631_optionalLine optionalLine, _s_80f9b631_optionalUserData optionalUserData, _s_80f9b631_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorAddHitGroup(rayTracingPipelineGenerator.value, hitGroupName.value, closestHitSymbol.value, anyHitSymbolSuggestedDefaultValueIsNull.value, intersectionSymbolSuggestedDefaultValueIsNull.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorAddRootSignatureAssociation redXRteRayTracingPipelineGeneratorAddRootSignatureAssociation
#define _21184b2b_rayTracingPipelineGenerator(value) value
#define _21184b2b_rootSignature_ID3D12RootSignature(value) value
#define _21184b2b_symbolsCount(value) value
#define _21184b2b_symbols(value) value
#define _21184b2b_optionalFile(value) value
#define _21184b2b_optionalLine(value) value
#define _21184b2b_optionalUserData(value) value
#define _21184b2b_rteParameters(value) value
#else
typedef struct _s_21184b2b_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_21184b2b_rayTracingPipelineGenerator;
typedef struct _s_21184b2b_rootSignature_ID3D12RootSignature { void* value; } _s_21184b2b_rootSignature_ID3D12RootSignature;
typedef struct _s_21184b2b_symbolsCount { uint64_t value; } _s_21184b2b_symbolsCount;
typedef struct _s_21184b2b_symbols { wchar_t** value; } _s_21184b2b_symbols;
typedef struct _s_21184b2b_optionalFile { char* value; } _s_21184b2b_optionalFile;
typedef struct _s_21184b2b_optionalLine { int value; } _s_21184b2b_optionalLine;
typedef struct _s_21184b2b_optionalUserData { void* value; } _s_21184b2b_optionalUserData;
typedef struct _s_21184b2b_rteParameters { void* value; } _s_21184b2b_rteParameters;
static inline _s_21184b2b_rayTracingPipelineGenerator _21184b2b_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_21184b2b_rayTracingPipelineGenerator){value}; }
static inline _s_21184b2b_rootSignature_ID3D12RootSignature _21184b2b_rootSignature_ID3D12RootSignature(void* value) { return REDGPU_NP_STRUCT_INIT(_s_21184b2b_rootSignature_ID3D12RootSignature){value}; }
static inline _s_21184b2b_symbolsCount _21184b2b_symbolsCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_21184b2b_symbolsCount){value}; }
static inline _s_21184b2b_symbols _21184b2b_symbols(wchar_t** value) { return REDGPU_NP_STRUCT_INIT(_s_21184b2b_symbols){value}; }
static inline _s_21184b2b_optionalFile _21184b2b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_21184b2b_optionalFile){value}; }
static inline _s_21184b2b_optionalLine _21184b2b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_21184b2b_optionalLine){value}; }
static inline _s_21184b2b_optionalUserData _21184b2b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_21184b2b_optionalUserData){value}; }
static inline _s_21184b2b_rteParameters _21184b2b_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_21184b2b_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorAddRootSignatureAssociation(_s_21184b2b_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_21184b2b_rootSignature_ID3D12RootSignature rootSignature_ID3D12RootSignature, _s_21184b2b_symbolsCount symbolsCount, _s_21184b2b_symbols symbols, _s_21184b2b_optionalFile optionalFile, _s_21184b2b_optionalLine optionalLine, _s_21184b2b_optionalUserData optionalUserData, _s_21184b2b_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorAddRootSignatureAssociation(rayTracingPipelineGenerator.value, rootSignature_ID3D12RootSignature.value, symbolsCount.value, symbols.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorSetMaxPayloadSize redXRteRayTracingPipelineGeneratorSetMaxPayloadSize
#define _5af55de0_rayTracingPipelineGenerator(value) value
#define _5af55de0_sizeInBytes(value) value
#define _5af55de0_optionalFile(value) value
#define _5af55de0_optionalLine(value) value
#define _5af55de0_optionalUserData(value) value
#define _5af55de0_rteParameters(value) value
#else
typedef struct _s_5af55de0_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_5af55de0_rayTracingPipelineGenerator;
typedef struct _s_5af55de0_sizeInBytes { unsigned value; } _s_5af55de0_sizeInBytes;
typedef struct _s_5af55de0_optionalFile { char* value; } _s_5af55de0_optionalFile;
typedef struct _s_5af55de0_optionalLine { int value; } _s_5af55de0_optionalLine;
typedef struct _s_5af55de0_optionalUserData { void* value; } _s_5af55de0_optionalUserData;
typedef struct _s_5af55de0_rteParameters { void* value; } _s_5af55de0_rteParameters;
static inline _s_5af55de0_rayTracingPipelineGenerator _5af55de0_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_5af55de0_rayTracingPipelineGenerator){value}; }
static inline _s_5af55de0_sizeInBytes _5af55de0_sizeInBytes(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_5af55de0_sizeInBytes){value}; }
static inline _s_5af55de0_optionalFile _5af55de0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5af55de0_optionalFile){value}; }
static inline _s_5af55de0_optionalLine _5af55de0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5af55de0_optionalLine){value}; }
static inline _s_5af55de0_optionalUserData _5af55de0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5af55de0_optionalUserData){value}; }
static inline _s_5af55de0_rteParameters _5af55de0_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5af55de0_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorSetMaxPayloadSize(_s_5af55de0_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_5af55de0_sizeInBytes sizeInBytes, _s_5af55de0_optionalFile optionalFile, _s_5af55de0_optionalLine optionalLine, _s_5af55de0_optionalUserData optionalUserData, _s_5af55de0_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorSetMaxPayloadSize(rayTracingPipelineGenerator.value, sizeInBytes.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorSetMaxAttributeSize redXRteRayTracingPipelineGeneratorSetMaxAttributeSize
#define _7ac955c4_rayTracingPipelineGenerator(value) value
#define _7ac955c4_sizeInBytes(value) value
#define _7ac955c4_optionalFile(value) value
#define _7ac955c4_optionalLine(value) value
#define _7ac955c4_optionalUserData(value) value
#define _7ac955c4_rteParameters(value) value
#else
typedef struct _s_7ac955c4_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_7ac955c4_rayTracingPipelineGenerator;
typedef struct _s_7ac955c4_sizeInBytes { unsigned value; } _s_7ac955c4_sizeInBytes;
typedef struct _s_7ac955c4_optionalFile { char* value; } _s_7ac955c4_optionalFile;
typedef struct _s_7ac955c4_optionalLine { int value; } _s_7ac955c4_optionalLine;
typedef struct _s_7ac955c4_optionalUserData { void* value; } _s_7ac955c4_optionalUserData;
typedef struct _s_7ac955c4_rteParameters { void* value; } _s_7ac955c4_rteParameters;
static inline _s_7ac955c4_rayTracingPipelineGenerator _7ac955c4_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_7ac955c4_rayTracingPipelineGenerator){value}; }
static inline _s_7ac955c4_sizeInBytes _7ac955c4_sizeInBytes(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_7ac955c4_sizeInBytes){value}; }
static inline _s_7ac955c4_optionalFile _7ac955c4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7ac955c4_optionalFile){value}; }
static inline _s_7ac955c4_optionalLine _7ac955c4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7ac955c4_optionalLine){value}; }
static inline _s_7ac955c4_optionalUserData _7ac955c4_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7ac955c4_optionalUserData){value}; }
static inline _s_7ac955c4_rteParameters _7ac955c4_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7ac955c4_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorSetMaxAttributeSize(_s_7ac955c4_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_7ac955c4_sizeInBytes sizeInBytes, _s_7ac955c4_optionalFile optionalFile, _s_7ac955c4_optionalLine optionalLine, _s_7ac955c4_optionalUserData optionalUserData, _s_7ac955c4_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorSetMaxAttributeSize(rayTracingPipelineGenerator.value, sizeInBytes.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorSetMaxRecursionDepth redXRteRayTracingPipelineGeneratorSetMaxRecursionDepth
#define _23f1004d_rayTracingPipelineGenerator(value) value
#define _23f1004d_maxDepth(value) value
#define _23f1004d_optionalFile(value) value
#define _23f1004d_optionalLine(value) value
#define _23f1004d_optionalUserData(value) value
#define _23f1004d_rteParameters(value) value
#else
typedef struct _s_23f1004d_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_23f1004d_rayTracingPipelineGenerator;
typedef struct _s_23f1004d_maxDepth { unsigned value; } _s_23f1004d_maxDepth;
typedef struct _s_23f1004d_optionalFile { char* value; } _s_23f1004d_optionalFile;
typedef struct _s_23f1004d_optionalLine { int value; } _s_23f1004d_optionalLine;
typedef struct _s_23f1004d_optionalUserData { void* value; } _s_23f1004d_optionalUserData;
typedef struct _s_23f1004d_rteParameters { void* value; } _s_23f1004d_rteParameters;
static inline _s_23f1004d_rayTracingPipelineGenerator _23f1004d_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_23f1004d_rayTracingPipelineGenerator){value}; }
static inline _s_23f1004d_maxDepth _23f1004d_maxDepth(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_23f1004d_maxDepth){value}; }
static inline _s_23f1004d_optionalFile _23f1004d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_23f1004d_optionalFile){value}; }
static inline _s_23f1004d_optionalLine _23f1004d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_23f1004d_optionalLine){value}; }
static inline _s_23f1004d_optionalUserData _23f1004d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_23f1004d_optionalUserData){value}; }
static inline _s_23f1004d_rteParameters _23f1004d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_23f1004d_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorSetMaxRecursionDepth(_s_23f1004d_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_23f1004d_maxDepth maxDepth, _s_23f1004d_optionalFile optionalFile, _s_23f1004d_optionalLine optionalLine, _s_23f1004d_optionalUserData optionalUserData, _s_23f1004d_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorSetMaxRecursionDepth(rayTracingPipelineGenerator.value, maxDepth.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorGenerate redXRteRayTracingPipelineGeneratorGenerate
#define _3e2b6044_rayTracingPipelineGenerator(value) value
#define _3e2b6044_outStateObject_ID3D12StateObject(value) value
#define _3e2b6044_outStateObjectProperties_ID3D12StateObjectProperties(value) value
#define _3e2b6044_optionalFile(value) value
#define _3e2b6044_optionalLine(value) value
#define _3e2b6044_optionalUserData(value) value
#define _3e2b6044_rteParameters(value) value
#else
typedef struct _s_3e2b6044_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_3e2b6044_rayTracingPipelineGenerator;
typedef struct _s_3e2b6044_outStateObject_ID3D12StateObject { void** value; } _s_3e2b6044_outStateObject_ID3D12StateObject;
typedef struct _s_3e2b6044_outStateObjectProperties_ID3D12StateObjectProperties { void** value; } _s_3e2b6044_outStateObjectProperties_ID3D12StateObjectProperties;
typedef struct _s_3e2b6044_optionalFile { char* value; } _s_3e2b6044_optionalFile;
typedef struct _s_3e2b6044_optionalLine { int value; } _s_3e2b6044_optionalLine;
typedef struct _s_3e2b6044_optionalUserData { void* value; } _s_3e2b6044_optionalUserData;
typedef struct _s_3e2b6044_rteParameters { void* value; } _s_3e2b6044_rteParameters;
static inline _s_3e2b6044_rayTracingPipelineGenerator _3e2b6044_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_3e2b6044_rayTracingPipelineGenerator){value}; }
static inline _s_3e2b6044_outStateObject_ID3D12StateObject _3e2b6044_outStateObject_ID3D12StateObject(void** value) { return REDGPU_NP_STRUCT_INIT(_s_3e2b6044_outStateObject_ID3D12StateObject){value}; }
static inline _s_3e2b6044_outStateObjectProperties_ID3D12StateObjectProperties _3e2b6044_outStateObjectProperties_ID3D12StateObjectProperties(void** value) { return REDGPU_NP_STRUCT_INIT(_s_3e2b6044_outStateObjectProperties_ID3D12StateObjectProperties){value}; }
static inline _s_3e2b6044_optionalFile _3e2b6044_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3e2b6044_optionalFile){value}; }
static inline _s_3e2b6044_optionalLine _3e2b6044_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3e2b6044_optionalLine){value}; }
static inline _s_3e2b6044_optionalUserData _3e2b6044_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3e2b6044_optionalUserData){value}; }
static inline _s_3e2b6044_rteParameters _3e2b6044_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3e2b6044_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorGenerate(_s_3e2b6044_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_3e2b6044_outStateObject_ID3D12StateObject outStateObject_ID3D12StateObject, _s_3e2b6044_outStateObjectProperties_ID3D12StateObjectProperties outStateObjectProperties_ID3D12StateObjectProperties, _s_3e2b6044_optionalFile optionalFile, _s_3e2b6044_optionalLine optionalLine, _s_3e2b6044_optionalUserData optionalUserData, _s_3e2b6044_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorGenerate(rayTracingPipelineGenerator.value, outStateObject_ID3D12StateObject.value, outStateObjectProperties_ID3D12StateObjectProperties.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorAddRayGenerationProgram redXRteShaderBindingTableGeneratorAddRayGenerationProgram
#define _c64da9b8_shaderBindingTableGenerator(value) value
#define _c64da9b8_entryPoint(value) value
#define _c64da9b8_inputDatasCount(value) value
#define _c64da9b8_inputDatas(value) value
#define _c64da9b8_optionalFile(value) value
#define _c64da9b8_optionalLine(value) value
#define _c64da9b8_optionalUserData(value) value
#define _c64da9b8_rteParameters(value) value
#else
typedef struct _s_c64da9b8_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_c64da9b8_shaderBindingTableGenerator;
typedef struct _s_c64da9b8_entryPoint { wchar_t* value; } _s_c64da9b8_entryPoint;
typedef struct _s_c64da9b8_inputDatasCount { uint64_t value; } _s_c64da9b8_inputDatasCount;
typedef struct _s_c64da9b8_inputDatas { void** value; } _s_c64da9b8_inputDatas;
typedef struct _s_c64da9b8_optionalFile { char* value; } _s_c64da9b8_optionalFile;
typedef struct _s_c64da9b8_optionalLine { int value; } _s_c64da9b8_optionalLine;
typedef struct _s_c64da9b8_optionalUserData { void* value; } _s_c64da9b8_optionalUserData;
typedef struct _s_c64da9b8_rteParameters { void* value; } _s_c64da9b8_rteParameters;
static inline _s_c64da9b8_shaderBindingTableGenerator _c64da9b8_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_c64da9b8_shaderBindingTableGenerator){value}; }
static inline _s_c64da9b8_entryPoint _c64da9b8_entryPoint(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_c64da9b8_entryPoint){value}; }
static inline _s_c64da9b8_inputDatasCount _c64da9b8_inputDatasCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_c64da9b8_inputDatasCount){value}; }
static inline _s_c64da9b8_inputDatas _c64da9b8_inputDatas(void** value) { return REDGPU_NP_STRUCT_INIT(_s_c64da9b8_inputDatas){value}; }
static inline _s_c64da9b8_optionalFile _c64da9b8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c64da9b8_optionalFile){value}; }
static inline _s_c64da9b8_optionalLine _c64da9b8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c64da9b8_optionalLine){value}; }
static inline _s_c64da9b8_optionalUserData _c64da9b8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c64da9b8_optionalUserData){value}; }
static inline _s_c64da9b8_rteParameters _c64da9b8_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c64da9b8_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteShaderBindingTableGeneratorAddRayGenerationProgram(_s_c64da9b8_shaderBindingTableGenerator shaderBindingTableGenerator, _s_c64da9b8_entryPoint entryPoint, _s_c64da9b8_inputDatasCount inputDatasCount, _s_c64da9b8_inputDatas inputDatas, _s_c64da9b8_optionalFile optionalFile, _s_c64da9b8_optionalLine optionalLine, _s_c64da9b8_optionalUserData optionalUserData, _s_c64da9b8_rteParameters rteParameters) {
  redXRteShaderBindingTableGeneratorAddRayGenerationProgram(shaderBindingTableGenerator.value, entryPoint.value, inputDatasCount.value, inputDatas.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorAddMissProgram redXRteShaderBindingTableGeneratorAddMissProgram
#define _397e44ec_shaderBindingTableGenerator(value) value
#define _397e44ec_entryPoint(value) value
#define _397e44ec_inputDatasCount(value) value
#define _397e44ec_inputDatas(value) value
#define _397e44ec_optionalFile(value) value
#define _397e44ec_optionalLine(value) value
#define _397e44ec_optionalUserData(value) value
#define _397e44ec_rteParameters(value) value
#else
typedef struct _s_397e44ec_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_397e44ec_shaderBindingTableGenerator;
typedef struct _s_397e44ec_entryPoint { wchar_t* value; } _s_397e44ec_entryPoint;
typedef struct _s_397e44ec_inputDatasCount { uint64_t value; } _s_397e44ec_inputDatasCount;
typedef struct _s_397e44ec_inputDatas { void** value; } _s_397e44ec_inputDatas;
typedef struct _s_397e44ec_optionalFile { char* value; } _s_397e44ec_optionalFile;
typedef struct _s_397e44ec_optionalLine { int value; } _s_397e44ec_optionalLine;
typedef struct _s_397e44ec_optionalUserData { void* value; } _s_397e44ec_optionalUserData;
typedef struct _s_397e44ec_rteParameters { void* value; } _s_397e44ec_rteParameters;
static inline _s_397e44ec_shaderBindingTableGenerator _397e44ec_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_397e44ec_shaderBindingTableGenerator){value}; }
static inline _s_397e44ec_entryPoint _397e44ec_entryPoint(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_397e44ec_entryPoint){value}; }
static inline _s_397e44ec_inputDatasCount _397e44ec_inputDatasCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_397e44ec_inputDatasCount){value}; }
static inline _s_397e44ec_inputDatas _397e44ec_inputDatas(void** value) { return REDGPU_NP_STRUCT_INIT(_s_397e44ec_inputDatas){value}; }
static inline _s_397e44ec_optionalFile _397e44ec_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_397e44ec_optionalFile){value}; }
static inline _s_397e44ec_optionalLine _397e44ec_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_397e44ec_optionalLine){value}; }
static inline _s_397e44ec_optionalUserData _397e44ec_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_397e44ec_optionalUserData){value}; }
static inline _s_397e44ec_rteParameters _397e44ec_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_397e44ec_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteShaderBindingTableGeneratorAddMissProgram(_s_397e44ec_shaderBindingTableGenerator shaderBindingTableGenerator, _s_397e44ec_entryPoint entryPoint, _s_397e44ec_inputDatasCount inputDatasCount, _s_397e44ec_inputDatas inputDatas, _s_397e44ec_optionalFile optionalFile, _s_397e44ec_optionalLine optionalLine, _s_397e44ec_optionalUserData optionalUserData, _s_397e44ec_rteParameters rteParameters) {
  redXRteShaderBindingTableGeneratorAddMissProgram(shaderBindingTableGenerator.value, entryPoint.value, inputDatasCount.value, inputDatas.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorAddHitGroup redXRteShaderBindingTableGeneratorAddHitGroup
#define _1a3bff74_shaderBindingTableGenerator(value) value
#define _1a3bff74_entryPoint(value) value
#define _1a3bff74_inputDatasCount(value) value
#define _1a3bff74_inputDatas(value) value
#define _1a3bff74_optionalFile(value) value
#define _1a3bff74_optionalLine(value) value
#define _1a3bff74_optionalUserData(value) value
#define _1a3bff74_rteParameters(value) value
#else
typedef struct _s_1a3bff74_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_1a3bff74_shaderBindingTableGenerator;
typedef struct _s_1a3bff74_entryPoint { wchar_t* value; } _s_1a3bff74_entryPoint;
typedef struct _s_1a3bff74_inputDatasCount { uint64_t value; } _s_1a3bff74_inputDatasCount;
typedef struct _s_1a3bff74_inputDatas { void** value; } _s_1a3bff74_inputDatas;
typedef struct _s_1a3bff74_optionalFile { char* value; } _s_1a3bff74_optionalFile;
typedef struct _s_1a3bff74_optionalLine { int value; } _s_1a3bff74_optionalLine;
typedef struct _s_1a3bff74_optionalUserData { void* value; } _s_1a3bff74_optionalUserData;
typedef struct _s_1a3bff74_rteParameters { void* value; } _s_1a3bff74_rteParameters;
static inline _s_1a3bff74_shaderBindingTableGenerator _1a3bff74_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_1a3bff74_shaderBindingTableGenerator){value}; }
static inline _s_1a3bff74_entryPoint _1a3bff74_entryPoint(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_1a3bff74_entryPoint){value}; }
static inline _s_1a3bff74_inputDatasCount _1a3bff74_inputDatasCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_1a3bff74_inputDatasCount){value}; }
static inline _s_1a3bff74_inputDatas _1a3bff74_inputDatas(void** value) { return REDGPU_NP_STRUCT_INIT(_s_1a3bff74_inputDatas){value}; }
static inline _s_1a3bff74_optionalFile _1a3bff74_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1a3bff74_optionalFile){value}; }
static inline _s_1a3bff74_optionalLine _1a3bff74_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1a3bff74_optionalLine){value}; }
static inline _s_1a3bff74_optionalUserData _1a3bff74_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1a3bff74_optionalUserData){value}; }
static inline _s_1a3bff74_rteParameters _1a3bff74_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1a3bff74_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteShaderBindingTableGeneratorAddHitGroup(_s_1a3bff74_shaderBindingTableGenerator shaderBindingTableGenerator, _s_1a3bff74_entryPoint entryPoint, _s_1a3bff74_inputDatasCount inputDatasCount, _s_1a3bff74_inputDatas inputDatas, _s_1a3bff74_optionalFile optionalFile, _s_1a3bff74_optionalLine optionalLine, _s_1a3bff74_optionalUserData optionalUserData, _s_1a3bff74_rteParameters rteParameters) {
  redXRteShaderBindingTableGeneratorAddHitGroup(shaderBindingTableGenerator.value, entryPoint.value, inputDatasCount.value, inputDatas.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorComputeSBTSize redXRteShaderBindingTableGeneratorComputeSBTSize
#define _3113bb1b_shaderBindingTableGenerator(value) value
#define _3113bb1b_optionalFile(value) value
#define _3113bb1b_optionalLine(value) value
#define _3113bb1b_optionalUserData(value) value
#define _3113bb1b_rteParameters(value) value
#else
typedef struct _s_3113bb1b_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_3113bb1b_shaderBindingTableGenerator;
typedef struct _s_3113bb1b_optionalFile { char* value; } _s_3113bb1b_optionalFile;
typedef struct _s_3113bb1b_optionalLine { int value; } _s_3113bb1b_optionalLine;
typedef struct _s_3113bb1b_optionalUserData { void* value; } _s_3113bb1b_optionalUserData;
typedef struct _s_3113bb1b_rteParameters { void* value; } _s_3113bb1b_rteParameters;
static inline _s_3113bb1b_shaderBindingTableGenerator _3113bb1b_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_3113bb1b_shaderBindingTableGenerator){value}; }
static inline _s_3113bb1b_optionalFile _3113bb1b_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3113bb1b_optionalFile){value}; }
static inline _s_3113bb1b_optionalLine _3113bb1b_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3113bb1b_optionalLine){value}; }
static inline _s_3113bb1b_optionalUserData _3113bb1b_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3113bb1b_optionalUserData){value}; }
static inline _s_3113bb1b_rteParameters _3113bb1b_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3113bb1b_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorComputeSBTSize(_s_3113bb1b_shaderBindingTableGenerator shaderBindingTableGenerator, _s_3113bb1b_optionalFile optionalFile, _s_3113bb1b_optionalLine optionalLine, _s_3113bb1b_optionalUserData optionalUserData, _s_3113bb1b_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorComputeSBTSize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGenerate redXRteShaderBindingTableGeneratorGenerate
#define _ca1bcdd0_shaderBindingTableGenerator(value) value
#define _ca1bcdd0_sbtBuffer_ID3D12Resource(value) value
#define _ca1bcdd0_raytracingPipeline_ID3D12StateObjectProperties(value) value
#define _ca1bcdd0_optionalFile(value) value
#define _ca1bcdd0_optionalLine(value) value
#define _ca1bcdd0_optionalUserData(value) value
#define _ca1bcdd0_rteParameters(value) value
#else
typedef struct _s_ca1bcdd0_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_ca1bcdd0_shaderBindingTableGenerator;
typedef struct _s_ca1bcdd0_sbtBuffer_ID3D12Resource { void* value; } _s_ca1bcdd0_sbtBuffer_ID3D12Resource;
typedef struct _s_ca1bcdd0_raytracingPipeline_ID3D12StateObjectProperties { void* value; } _s_ca1bcdd0_raytracingPipeline_ID3D12StateObjectProperties;
typedef struct _s_ca1bcdd0_optionalFile { char* value; } _s_ca1bcdd0_optionalFile;
typedef struct _s_ca1bcdd0_optionalLine { int value; } _s_ca1bcdd0_optionalLine;
typedef struct _s_ca1bcdd0_optionalUserData { void* value; } _s_ca1bcdd0_optionalUserData;
typedef struct _s_ca1bcdd0_rteParameters { void* value; } _s_ca1bcdd0_rteParameters;
static inline _s_ca1bcdd0_shaderBindingTableGenerator _ca1bcdd0_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_ca1bcdd0_shaderBindingTableGenerator){value}; }
static inline _s_ca1bcdd0_sbtBuffer_ID3D12Resource _ca1bcdd0_sbtBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ca1bcdd0_sbtBuffer_ID3D12Resource){value}; }
static inline _s_ca1bcdd0_raytracingPipeline_ID3D12StateObjectProperties _ca1bcdd0_raytracingPipeline_ID3D12StateObjectProperties(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ca1bcdd0_raytracingPipeline_ID3D12StateObjectProperties){value}; }
static inline _s_ca1bcdd0_optionalFile _ca1bcdd0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ca1bcdd0_optionalFile){value}; }
static inline _s_ca1bcdd0_optionalLine _ca1bcdd0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ca1bcdd0_optionalLine){value}; }
static inline _s_ca1bcdd0_optionalUserData _ca1bcdd0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ca1bcdd0_optionalUserData){value}; }
static inline _s_ca1bcdd0_rteParameters _ca1bcdd0_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ca1bcdd0_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGenerate(_s_ca1bcdd0_shaderBindingTableGenerator shaderBindingTableGenerator, _s_ca1bcdd0_sbtBuffer_ID3D12Resource sbtBuffer_ID3D12Resource, _s_ca1bcdd0_raytracingPipeline_ID3D12StateObjectProperties raytracingPipeline_ID3D12StateObjectProperties, _s_ca1bcdd0_optionalFile optionalFile, _s_ca1bcdd0_optionalLine optionalLine, _s_ca1bcdd0_optionalUserData optionalUserData, _s_ca1bcdd0_rteParameters rteParameters) {
  redXRteShaderBindingTableGeneratorGenerate(shaderBindingTableGenerator.value, sbtBuffer_ID3D12Resource.value, raytracingPipeline_ID3D12StateObjectProperties.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorReset redXRteShaderBindingTableGeneratorReset
#define _125b9e04_shaderBindingTableGenerator(value) value
#define _125b9e04_optionalFile(value) value
#define _125b9e04_optionalLine(value) value
#define _125b9e04_optionalUserData(value) value
#define _125b9e04_rteParameters(value) value
#else
typedef struct _s_125b9e04_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_125b9e04_shaderBindingTableGenerator;
typedef struct _s_125b9e04_optionalFile { char* value; } _s_125b9e04_optionalFile;
typedef struct _s_125b9e04_optionalLine { int value; } _s_125b9e04_optionalLine;
typedef struct _s_125b9e04_optionalUserData { void* value; } _s_125b9e04_optionalUserData;
typedef struct _s_125b9e04_rteParameters { void* value; } _s_125b9e04_rteParameters;
static inline _s_125b9e04_shaderBindingTableGenerator _125b9e04_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_125b9e04_shaderBindingTableGenerator){value}; }
static inline _s_125b9e04_optionalFile _125b9e04_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_125b9e04_optionalFile){value}; }
static inline _s_125b9e04_optionalLine _125b9e04_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_125b9e04_optionalLine){value}; }
static inline _s_125b9e04_optionalUserData _125b9e04_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_125b9e04_optionalUserData){value}; }
static inline _s_125b9e04_rteParameters _125b9e04_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_125b9e04_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteShaderBindingTableGeneratorReset(_s_125b9e04_shaderBindingTableGenerator shaderBindingTableGenerator, _s_125b9e04_optionalFile optionalFile, _s_125b9e04_optionalLine optionalLine, _s_125b9e04_optionalUserData optionalUserData, _s_125b9e04_rteParameters rteParameters) {
  redXRteShaderBindingTableGeneratorReset(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGetRayGenSectionSize redXRteShaderBindingTableGeneratorGetRayGenSectionSize
#define _bd3fec3e_shaderBindingTableGenerator(value) value
#define _bd3fec3e_optionalFile(value) value
#define _bd3fec3e_optionalLine(value) value
#define _bd3fec3e_optionalUserData(value) value
#define _bd3fec3e_rteParameters(value) value
#else
typedef struct _s_bd3fec3e_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_bd3fec3e_shaderBindingTableGenerator;
typedef struct _s_bd3fec3e_optionalFile { char* value; } _s_bd3fec3e_optionalFile;
typedef struct _s_bd3fec3e_optionalLine { int value; } _s_bd3fec3e_optionalLine;
typedef struct _s_bd3fec3e_optionalUserData { void* value; } _s_bd3fec3e_optionalUserData;
typedef struct _s_bd3fec3e_rteParameters { void* value; } _s_bd3fec3e_rteParameters;
static inline _s_bd3fec3e_shaderBindingTableGenerator _bd3fec3e_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_bd3fec3e_shaderBindingTableGenerator){value}; }
static inline _s_bd3fec3e_optionalFile _bd3fec3e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bd3fec3e_optionalFile){value}; }
static inline _s_bd3fec3e_optionalLine _bd3fec3e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bd3fec3e_optionalLine){value}; }
static inline _s_bd3fec3e_optionalUserData _bd3fec3e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bd3fec3e_optionalUserData){value}; }
static inline _s_bd3fec3e_rteParameters _bd3fec3e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bd3fec3e_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGetRayGenSectionSize(_s_bd3fec3e_shaderBindingTableGenerator shaderBindingTableGenerator, _s_bd3fec3e_optionalFile optionalFile, _s_bd3fec3e_optionalLine optionalLine, _s_bd3fec3e_optionalUserData optionalUserData, _s_bd3fec3e_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorGetRayGenSectionSize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGetRayGenEntrySize redXRteShaderBindingTableGeneratorGetRayGenEntrySize
#define _9277b628_shaderBindingTableGenerator(value) value
#define _9277b628_optionalFile(value) value
#define _9277b628_optionalLine(value) value
#define _9277b628_optionalUserData(value) value
#define _9277b628_rteParameters(value) value
#else
typedef struct _s_9277b628_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_9277b628_shaderBindingTableGenerator;
typedef struct _s_9277b628_optionalFile { char* value; } _s_9277b628_optionalFile;
typedef struct _s_9277b628_optionalLine { int value; } _s_9277b628_optionalLine;
typedef struct _s_9277b628_optionalUserData { void* value; } _s_9277b628_optionalUserData;
typedef struct _s_9277b628_rteParameters { void* value; } _s_9277b628_rteParameters;
static inline _s_9277b628_shaderBindingTableGenerator _9277b628_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_9277b628_shaderBindingTableGenerator){value}; }
static inline _s_9277b628_optionalFile _9277b628_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9277b628_optionalFile){value}; }
static inline _s_9277b628_optionalLine _9277b628_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9277b628_optionalLine){value}; }
static inline _s_9277b628_optionalUserData _9277b628_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9277b628_optionalUserData){value}; }
static inline _s_9277b628_rteParameters _9277b628_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9277b628_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGetRayGenEntrySize(_s_9277b628_shaderBindingTableGenerator shaderBindingTableGenerator, _s_9277b628_optionalFile optionalFile, _s_9277b628_optionalLine optionalLine, _s_9277b628_optionalUserData optionalUserData, _s_9277b628_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorGetRayGenEntrySize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGetMissSectionSize redXRteShaderBindingTableGeneratorGetMissSectionSize
#define _cdf833df_shaderBindingTableGenerator(value) value
#define _cdf833df_optionalFile(value) value
#define _cdf833df_optionalLine(value) value
#define _cdf833df_optionalUserData(value) value
#define _cdf833df_rteParameters(value) value
#else
typedef struct _s_cdf833df_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_cdf833df_shaderBindingTableGenerator;
typedef struct _s_cdf833df_optionalFile { char* value; } _s_cdf833df_optionalFile;
typedef struct _s_cdf833df_optionalLine { int value; } _s_cdf833df_optionalLine;
typedef struct _s_cdf833df_optionalUserData { void* value; } _s_cdf833df_optionalUserData;
typedef struct _s_cdf833df_rteParameters { void* value; } _s_cdf833df_rteParameters;
static inline _s_cdf833df_shaderBindingTableGenerator _cdf833df_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_cdf833df_shaderBindingTableGenerator){value}; }
static inline _s_cdf833df_optionalFile _cdf833df_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cdf833df_optionalFile){value}; }
static inline _s_cdf833df_optionalLine _cdf833df_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cdf833df_optionalLine){value}; }
static inline _s_cdf833df_optionalUserData _cdf833df_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cdf833df_optionalUserData){value}; }
static inline _s_cdf833df_rteParameters _cdf833df_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cdf833df_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGetMissSectionSize(_s_cdf833df_shaderBindingTableGenerator shaderBindingTableGenerator, _s_cdf833df_optionalFile optionalFile, _s_cdf833df_optionalLine optionalLine, _s_cdf833df_optionalUserData optionalUserData, _s_cdf833df_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorGetMissSectionSize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGetMissEntrySize redXRteShaderBindingTableGeneratorGetMissEntrySize
#define _9cd8dba6_shaderBindingTableGenerator(value) value
#define _9cd8dba6_optionalFile(value) value
#define _9cd8dba6_optionalLine(value) value
#define _9cd8dba6_optionalUserData(value) value
#define _9cd8dba6_rteParameters(value) value
#else
typedef struct _s_9cd8dba6_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_9cd8dba6_shaderBindingTableGenerator;
typedef struct _s_9cd8dba6_optionalFile { char* value; } _s_9cd8dba6_optionalFile;
typedef struct _s_9cd8dba6_optionalLine { int value; } _s_9cd8dba6_optionalLine;
typedef struct _s_9cd8dba6_optionalUserData { void* value; } _s_9cd8dba6_optionalUserData;
typedef struct _s_9cd8dba6_rteParameters { void* value; } _s_9cd8dba6_rteParameters;
static inline _s_9cd8dba6_shaderBindingTableGenerator _9cd8dba6_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_9cd8dba6_shaderBindingTableGenerator){value}; }
static inline _s_9cd8dba6_optionalFile _9cd8dba6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_9cd8dba6_optionalFile){value}; }
static inline _s_9cd8dba6_optionalLine _9cd8dba6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_9cd8dba6_optionalLine){value}; }
static inline _s_9cd8dba6_optionalUserData _9cd8dba6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9cd8dba6_optionalUserData){value}; }
static inline _s_9cd8dba6_rteParameters _9cd8dba6_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_9cd8dba6_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGetMissEntrySize(_s_9cd8dba6_shaderBindingTableGenerator shaderBindingTableGenerator, _s_9cd8dba6_optionalFile optionalFile, _s_9cd8dba6_optionalLine optionalLine, _s_9cd8dba6_optionalUserData optionalUserData, _s_9cd8dba6_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorGetMissEntrySize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGetHitGroupSectionSize redXRteShaderBindingTableGeneratorGetHitGroupSectionSize
#define _a3967c14_shaderBindingTableGenerator(value) value
#define _a3967c14_optionalFile(value) value
#define _a3967c14_optionalLine(value) value
#define _a3967c14_optionalUserData(value) value
#define _a3967c14_rteParameters(value) value
#else
typedef struct _s_a3967c14_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_a3967c14_shaderBindingTableGenerator;
typedef struct _s_a3967c14_optionalFile { char* value; } _s_a3967c14_optionalFile;
typedef struct _s_a3967c14_optionalLine { int value; } _s_a3967c14_optionalLine;
typedef struct _s_a3967c14_optionalUserData { void* value; } _s_a3967c14_optionalUserData;
typedef struct _s_a3967c14_rteParameters { void* value; } _s_a3967c14_rteParameters;
static inline _s_a3967c14_shaderBindingTableGenerator _a3967c14_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_a3967c14_shaderBindingTableGenerator){value}; }
static inline _s_a3967c14_optionalFile _a3967c14_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a3967c14_optionalFile){value}; }
static inline _s_a3967c14_optionalLine _a3967c14_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a3967c14_optionalLine){value}; }
static inline _s_a3967c14_optionalUserData _a3967c14_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a3967c14_optionalUserData){value}; }
static inline _s_a3967c14_rteParameters _a3967c14_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a3967c14_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGetHitGroupSectionSize(_s_a3967c14_shaderBindingTableGenerator shaderBindingTableGenerator, _s_a3967c14_optionalFile optionalFile, _s_a3967c14_optionalLine optionalLine, _s_a3967c14_optionalUserData optionalUserData, _s_a3967c14_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorGetHitGroupSectionSize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGetHitGroupEntrySize redXRteShaderBindingTableGeneratorGetHitGroupEntrySize
#define _d9c0e7e1_shaderBindingTableGenerator(value) value
#define _d9c0e7e1_optionalFile(value) value
#define _d9c0e7e1_optionalLine(value) value
#define _d9c0e7e1_optionalUserData(value) value
#define _d9c0e7e1_rteParameters(value) value
#else
typedef struct _s_d9c0e7e1_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_d9c0e7e1_shaderBindingTableGenerator;
typedef struct _s_d9c0e7e1_optionalFile { char* value; } _s_d9c0e7e1_optionalFile;
typedef struct _s_d9c0e7e1_optionalLine { int value; } _s_d9c0e7e1_optionalLine;
typedef struct _s_d9c0e7e1_optionalUserData { void* value; } _s_d9c0e7e1_optionalUserData;
typedef struct _s_d9c0e7e1_rteParameters { void* value; } _s_d9c0e7e1_rteParameters;
static inline _s_d9c0e7e1_shaderBindingTableGenerator _d9c0e7e1_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_d9c0e7e1_shaderBindingTableGenerator){value}; }
static inline _s_d9c0e7e1_optionalFile _d9c0e7e1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d9c0e7e1_optionalFile){value}; }
static inline _s_d9c0e7e1_optionalLine _d9c0e7e1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d9c0e7e1_optionalLine){value}; }
static inline _s_d9c0e7e1_optionalUserData _d9c0e7e1_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d9c0e7e1_optionalUserData){value}; }
static inline _s_d9c0e7e1_rteParameters _d9c0e7e1_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d9c0e7e1_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGetHitGroupEntrySize(_s_d9c0e7e1_shaderBindingTableGenerator shaderBindingTableGenerator, _s_d9c0e7e1_optionalFile optionalFile, _s_d9c0e7e1_optionalLine optionalLine, _s_d9c0e7e1_optionalUserData optionalUserData, _s_d9c0e7e1_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorGetHitGroupEntrySize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCallSetStateObject redXRteCallSetStateObject
#define _386a712d_calls(value) value
#define _386a712d_stateObject_ID3D12StateObject(value) value
#define _386a712d_optionalFile(value) value
#define _386a712d_optionalLine(value) value
#define _386a712d_optionalUserData(value) value
#define _386a712d_rteParameters(value) value
#else
typedef struct _s_386a712d_calls { RedHandleCalls value; } _s_386a712d_calls;
typedef struct _s_386a712d_stateObject_ID3D12StateObject { void* value; } _s_386a712d_stateObject_ID3D12StateObject;
typedef struct _s_386a712d_optionalFile { char* value; } _s_386a712d_optionalFile;
typedef struct _s_386a712d_optionalLine { int value; } _s_386a712d_optionalLine;
typedef struct _s_386a712d_optionalUserData { void* value; } _s_386a712d_optionalUserData;
typedef struct _s_386a712d_rteParameters { void* value; } _s_386a712d_rteParameters;
static inline _s_386a712d_calls _386a712d_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_386a712d_calls){value}; }
static inline _s_386a712d_stateObject_ID3D12StateObject _386a712d_stateObject_ID3D12StateObject(void* value) { return REDGPU_NP_STRUCT_INIT(_s_386a712d_stateObject_ID3D12StateObject){value}; }
static inline _s_386a712d_optionalFile _386a712d_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_386a712d_optionalFile){value}; }
static inline _s_386a712d_optionalLine _386a712d_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_386a712d_optionalLine){value}; }
static inline _s_386a712d_optionalUserData _386a712d_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_386a712d_optionalUserData){value}; }
static inline _s_386a712d_rteParameters _386a712d_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_386a712d_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCallSetStateObject(_s_386a712d_calls calls, _s_386a712d_stateObject_ID3D12StateObject stateObject_ID3D12StateObject, _s_386a712d_optionalFile optionalFile, _s_386a712d_optionalLine optionalLine, _s_386a712d_optionalUserData optionalUserData, _s_386a712d_rteParameters rteParameters) {
  redXRteCallSetStateObject(calls.value, stateObject_ID3D12StateObject.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCallDispatchRays redXRteCallDispatchRays
#define _318e9339_calls(value) value
#define _318e9339_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC(value) value
#define _318e9339_optionalFile(value) value
#define _318e9339_optionalLine(value) value
#define _318e9339_optionalUserData(value) value
#define _318e9339_rteParameters(value) value
#else
typedef struct _s_318e9339_calls { RedHandleCalls value; } _s_318e9339_calls;
typedef struct _s_318e9339_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC { void* value; } _s_318e9339_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC;
typedef struct _s_318e9339_optionalFile { char* value; } _s_318e9339_optionalFile;
typedef struct _s_318e9339_optionalLine { int value; } _s_318e9339_optionalLine;
typedef struct _s_318e9339_optionalUserData { void* value; } _s_318e9339_optionalUserData;
typedef struct _s_318e9339_rteParameters { void* value; } _s_318e9339_rteParameters;
static inline _s_318e9339_calls _318e9339_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_318e9339_calls){value}; }
static inline _s_318e9339_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC _318e9339_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC(void* value) { return REDGPU_NP_STRUCT_INIT(_s_318e9339_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC){value}; }
static inline _s_318e9339_optionalFile _318e9339_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_318e9339_optionalFile){value}; }
static inline _s_318e9339_optionalLine _318e9339_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_318e9339_optionalLine){value}; }
static inline _s_318e9339_optionalUserData _318e9339_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_318e9339_optionalUserData){value}; }
static inline _s_318e9339_rteParameters _318e9339_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_318e9339_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCallDispatchRays(_s_318e9339_calls calls, _s_318e9339_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC, _s_318e9339_optionalFile optionalFile, _s_318e9339_optionalLine optionalLine, _s_318e9339_optionalUserData optionalUserData, _s_318e9339_rteParameters rteParameters) {
  redXRteCallDispatchRays(calls.value, dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

