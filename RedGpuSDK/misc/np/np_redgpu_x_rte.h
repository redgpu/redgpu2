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
#define _2fad8097_array(value) value
#define _2fad8097_optionalFile(value) value
#define _2fad8097_optionalLine(value) value
#define _2fad8097_optionalUserData(value) value
#define _2fad8097_rteParameters(value) value
#else
typedef struct _s_2fad8097_array { RedHandleArray value; } _s_2fad8097_array;
typedef struct _s_2fad8097_optionalFile { char* value; } _s_2fad8097_optionalFile;
typedef struct _s_2fad8097_optionalLine { int value; } _s_2fad8097_optionalLine;
typedef struct _s_2fad8097_optionalUserData { void* value; } _s_2fad8097_optionalUserData;
typedef struct _s_2fad8097_rteParameters { void* value; } _s_2fad8097_rteParameters;
static inline _s_2fad8097_array _2fad8097_array(RedHandleArray value) { return REDGPU_NP_STRUCT_INIT(_s_2fad8097_array){value}; }
static inline _s_2fad8097_optionalFile _2fad8097_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2fad8097_optionalFile){value}; }
static inline _s_2fad8097_optionalLine _2fad8097_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2fad8097_optionalLine){value}; }
static inline _s_2fad8097_optionalUserData _2fad8097_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2fad8097_optionalUserData){value}; }
static inline _s_2fad8097_rteParameters _2fad8097_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2fad8097_rteParameters){value}; }
REDGPU_NP_DECLSPEC uint64_t REDGPU_NP_API np_redXRteArrayGetGpuAddress(_s_2fad8097_array array, _s_2fad8097_optionalFile optionalFile, _s_2fad8097_optionalLine optionalLine, _s_2fad8097_optionalUserData optionalUserData, _s_2fad8097_rteParameters rteParameters) {
  return redXRteArrayGetGpuAddress(array.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCreateBottomLevelASGenerator redXRteCreateBottomLevelASGenerator
#define _1e4aeed4_outBottomLevelASGenerator(value) value
#define _1e4aeed4_optionalFile(value) value
#define _1e4aeed4_optionalLine(value) value
#define _1e4aeed4_optionalUserData(value) value
#define _1e4aeed4_rteParameters(value) value
#else
typedef struct _s_1e4aeed4_outBottomLevelASGenerator { RedXRteHandleBottomLevelASGenerator* value; } _s_1e4aeed4_outBottomLevelASGenerator;
typedef struct _s_1e4aeed4_optionalFile { char* value; } _s_1e4aeed4_optionalFile;
typedef struct _s_1e4aeed4_optionalLine { int value; } _s_1e4aeed4_optionalLine;
typedef struct _s_1e4aeed4_optionalUserData { void* value; } _s_1e4aeed4_optionalUserData;
typedef struct _s_1e4aeed4_rteParameters { void* value; } _s_1e4aeed4_rteParameters;
static inline _s_1e4aeed4_outBottomLevelASGenerator _1e4aeed4_outBottomLevelASGenerator(RedXRteHandleBottomLevelASGenerator* value) { return REDGPU_NP_STRUCT_INIT(_s_1e4aeed4_outBottomLevelASGenerator){value}; }
static inline _s_1e4aeed4_optionalFile _1e4aeed4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1e4aeed4_optionalFile){value}; }
static inline _s_1e4aeed4_optionalLine _1e4aeed4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1e4aeed4_optionalLine){value}; }
static inline _s_1e4aeed4_optionalUserData _1e4aeed4_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1e4aeed4_optionalUserData){value}; }
static inline _s_1e4aeed4_rteParameters _1e4aeed4_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1e4aeed4_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCreateBottomLevelASGenerator(_s_1e4aeed4_outBottomLevelASGenerator outBottomLevelASGenerator, _s_1e4aeed4_optionalFile optionalFile, _s_1e4aeed4_optionalLine optionalLine, _s_1e4aeed4_optionalUserData optionalUserData, _s_1e4aeed4_rteParameters rteParameters) {
  redXRteCreateBottomLevelASGenerator(outBottomLevelASGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCreateTopLevelASGenerator redXRteCreateTopLevelASGenerator
#define _daf1e7c5_outTopLevelASGenerator(value) value
#define _daf1e7c5_optionalFile(value) value
#define _daf1e7c5_optionalLine(value) value
#define _daf1e7c5_optionalUserData(value) value
#define _daf1e7c5_rteParameters(value) value
#else
typedef struct _s_daf1e7c5_outTopLevelASGenerator { RedXRteHandleTopLevelASGenerator* value; } _s_daf1e7c5_outTopLevelASGenerator;
typedef struct _s_daf1e7c5_optionalFile { char* value; } _s_daf1e7c5_optionalFile;
typedef struct _s_daf1e7c5_optionalLine { int value; } _s_daf1e7c5_optionalLine;
typedef struct _s_daf1e7c5_optionalUserData { void* value; } _s_daf1e7c5_optionalUserData;
typedef struct _s_daf1e7c5_rteParameters { void* value; } _s_daf1e7c5_rteParameters;
static inline _s_daf1e7c5_outTopLevelASGenerator _daf1e7c5_outTopLevelASGenerator(RedXRteHandleTopLevelASGenerator* value) { return REDGPU_NP_STRUCT_INIT(_s_daf1e7c5_outTopLevelASGenerator){value}; }
static inline _s_daf1e7c5_optionalFile _daf1e7c5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_daf1e7c5_optionalFile){value}; }
static inline _s_daf1e7c5_optionalLine _daf1e7c5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_daf1e7c5_optionalLine){value}; }
static inline _s_daf1e7c5_optionalUserData _daf1e7c5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_daf1e7c5_optionalUserData){value}; }
static inline _s_daf1e7c5_rteParameters _daf1e7c5_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_daf1e7c5_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCreateTopLevelASGenerator(_s_daf1e7c5_outTopLevelASGenerator outTopLevelASGenerator, _s_daf1e7c5_optionalFile optionalFile, _s_daf1e7c5_optionalLine optionalLine, _s_daf1e7c5_optionalUserData optionalUserData, _s_daf1e7c5_rteParameters rteParameters) {
  redXRteCreateTopLevelASGenerator(outTopLevelASGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCreateRootSignatureGenerator redXRteCreateRootSignatureGenerator
#define _646d4ac6_outRootSignatureGenerator(value) value
#define _646d4ac6_optionalFile(value) value
#define _646d4ac6_optionalLine(value) value
#define _646d4ac6_optionalUserData(value) value
#define _646d4ac6_rteParameters(value) value
#else
typedef struct _s_646d4ac6_outRootSignatureGenerator { RedXRteHandleRootSignatureGenerator* value; } _s_646d4ac6_outRootSignatureGenerator;
typedef struct _s_646d4ac6_optionalFile { char* value; } _s_646d4ac6_optionalFile;
typedef struct _s_646d4ac6_optionalLine { int value; } _s_646d4ac6_optionalLine;
typedef struct _s_646d4ac6_optionalUserData { void* value; } _s_646d4ac6_optionalUserData;
typedef struct _s_646d4ac6_rteParameters { void* value; } _s_646d4ac6_rteParameters;
static inline _s_646d4ac6_outRootSignatureGenerator _646d4ac6_outRootSignatureGenerator(RedXRteHandleRootSignatureGenerator* value) { return REDGPU_NP_STRUCT_INIT(_s_646d4ac6_outRootSignatureGenerator){value}; }
static inline _s_646d4ac6_optionalFile _646d4ac6_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_646d4ac6_optionalFile){value}; }
static inline _s_646d4ac6_optionalLine _646d4ac6_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_646d4ac6_optionalLine){value}; }
static inline _s_646d4ac6_optionalUserData _646d4ac6_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_646d4ac6_optionalUserData){value}; }
static inline _s_646d4ac6_rteParameters _646d4ac6_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_646d4ac6_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCreateRootSignatureGenerator(_s_646d4ac6_outRootSignatureGenerator outRootSignatureGenerator, _s_646d4ac6_optionalFile optionalFile, _s_646d4ac6_optionalLine optionalLine, _s_646d4ac6_optionalUserData optionalUserData, _s_646d4ac6_rteParameters rteParameters) {
  redXRteCreateRootSignatureGenerator(outRootSignatureGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCreateRayTracingPipelineGenerator redXRteCreateRayTracingPipelineGenerator
#define _96316c87_device_ID3D12Device5(value) value
#define _96316c87_outRayTracingPipelineGenerator(value) value
#define _96316c87_optionalFile(value) value
#define _96316c87_optionalLine(value) value
#define _96316c87_optionalUserData(value) value
#define _96316c87_rteParameters(value) value
#else
typedef struct _s_96316c87_device_ID3D12Device5 { void* value; } _s_96316c87_device_ID3D12Device5;
typedef struct _s_96316c87_outRayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator* value; } _s_96316c87_outRayTracingPipelineGenerator;
typedef struct _s_96316c87_optionalFile { char* value; } _s_96316c87_optionalFile;
typedef struct _s_96316c87_optionalLine { int value; } _s_96316c87_optionalLine;
typedef struct _s_96316c87_optionalUserData { void* value; } _s_96316c87_optionalUserData;
typedef struct _s_96316c87_rteParameters { void* value; } _s_96316c87_rteParameters;
static inline _s_96316c87_device_ID3D12Device5 _96316c87_device_ID3D12Device5(void* value) { return REDGPU_NP_STRUCT_INIT(_s_96316c87_device_ID3D12Device5){value}; }
static inline _s_96316c87_outRayTracingPipelineGenerator _96316c87_outRayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator* value) { return REDGPU_NP_STRUCT_INIT(_s_96316c87_outRayTracingPipelineGenerator){value}; }
static inline _s_96316c87_optionalFile _96316c87_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_96316c87_optionalFile){value}; }
static inline _s_96316c87_optionalLine _96316c87_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_96316c87_optionalLine){value}; }
static inline _s_96316c87_optionalUserData _96316c87_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_96316c87_optionalUserData){value}; }
static inline _s_96316c87_rteParameters _96316c87_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_96316c87_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCreateRayTracingPipelineGenerator(_s_96316c87_device_ID3D12Device5 device_ID3D12Device5, _s_96316c87_outRayTracingPipelineGenerator outRayTracingPipelineGenerator, _s_96316c87_optionalFile optionalFile, _s_96316c87_optionalLine optionalLine, _s_96316c87_optionalUserData optionalUserData, _s_96316c87_rteParameters rteParameters) {
  redXRteCreateRayTracingPipelineGenerator(device_ID3D12Device5.value, outRayTracingPipelineGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCreateShaderBindingTableGenerator redXRteCreateShaderBindingTableGenerator
#define _ac19bed8_outShaderBindingTableGenerator(value) value
#define _ac19bed8_optionalFile(value) value
#define _ac19bed8_optionalLine(value) value
#define _ac19bed8_optionalUserData(value) value
#define _ac19bed8_rteParameters(value) value
#else
typedef struct _s_ac19bed8_outShaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator* value; } _s_ac19bed8_outShaderBindingTableGenerator;
typedef struct _s_ac19bed8_optionalFile { char* value; } _s_ac19bed8_optionalFile;
typedef struct _s_ac19bed8_optionalLine { int value; } _s_ac19bed8_optionalLine;
typedef struct _s_ac19bed8_optionalUserData { void* value; } _s_ac19bed8_optionalUserData;
typedef struct _s_ac19bed8_rteParameters { void* value; } _s_ac19bed8_rteParameters;
static inline _s_ac19bed8_outShaderBindingTableGenerator _ac19bed8_outShaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator* value) { return REDGPU_NP_STRUCT_INIT(_s_ac19bed8_outShaderBindingTableGenerator){value}; }
static inline _s_ac19bed8_optionalFile _ac19bed8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ac19bed8_optionalFile){value}; }
static inline _s_ac19bed8_optionalLine _ac19bed8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ac19bed8_optionalLine){value}; }
static inline _s_ac19bed8_optionalUserData _ac19bed8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ac19bed8_optionalUserData){value}; }
static inline _s_ac19bed8_rteParameters _ac19bed8_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ac19bed8_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCreateShaderBindingTableGenerator(_s_ac19bed8_outShaderBindingTableGenerator outShaderBindingTableGenerator, _s_ac19bed8_optionalFile optionalFile, _s_ac19bed8_optionalLine optionalLine, _s_ac19bed8_optionalUserData optionalUserData, _s_ac19bed8_rteParameters rteParameters) {
  redXRteCreateShaderBindingTableGenerator(outShaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteDestroyBottomLevelASGenerator redXRteDestroyBottomLevelASGenerator
#define _8c9736ca_bottomLevelASGenerator(value) value
#define _8c9736ca_optionalFile(value) value
#define _8c9736ca_optionalLine(value) value
#define _8c9736ca_optionalUserData(value) value
#define _8c9736ca_rteParameters(value) value
#else
typedef struct _s_8c9736ca_bottomLevelASGenerator { RedXRteHandleBottomLevelASGenerator value; } _s_8c9736ca_bottomLevelASGenerator;
typedef struct _s_8c9736ca_optionalFile { char* value; } _s_8c9736ca_optionalFile;
typedef struct _s_8c9736ca_optionalLine { int value; } _s_8c9736ca_optionalLine;
typedef struct _s_8c9736ca_optionalUserData { void* value; } _s_8c9736ca_optionalUserData;
typedef struct _s_8c9736ca_rteParameters { void* value; } _s_8c9736ca_rteParameters;
static inline _s_8c9736ca_bottomLevelASGenerator _8c9736ca_bottomLevelASGenerator(RedXRteHandleBottomLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_8c9736ca_bottomLevelASGenerator){value}; }
static inline _s_8c9736ca_optionalFile _8c9736ca_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_8c9736ca_optionalFile){value}; }
static inline _s_8c9736ca_optionalLine _8c9736ca_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_8c9736ca_optionalLine){value}; }
static inline _s_8c9736ca_optionalUserData _8c9736ca_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8c9736ca_optionalUserData){value}; }
static inline _s_8c9736ca_rteParameters _8c9736ca_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_8c9736ca_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteDestroyBottomLevelASGenerator(_s_8c9736ca_bottomLevelASGenerator bottomLevelASGenerator, _s_8c9736ca_optionalFile optionalFile, _s_8c9736ca_optionalLine optionalLine, _s_8c9736ca_optionalUserData optionalUserData, _s_8c9736ca_rteParameters rteParameters) {
  redXRteDestroyBottomLevelASGenerator(bottomLevelASGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteDestroyTopLevelASGenerator redXRteDestroyTopLevelASGenerator
#define _a27ec345_topLevelASGenerator(value) value
#define _a27ec345_optionalFile(value) value
#define _a27ec345_optionalLine(value) value
#define _a27ec345_optionalUserData(value) value
#define _a27ec345_rteParameters(value) value
#else
typedef struct _s_a27ec345_topLevelASGenerator { RedXRteHandleTopLevelASGenerator value; } _s_a27ec345_topLevelASGenerator;
typedef struct _s_a27ec345_optionalFile { char* value; } _s_a27ec345_optionalFile;
typedef struct _s_a27ec345_optionalLine { int value; } _s_a27ec345_optionalLine;
typedef struct _s_a27ec345_optionalUserData { void* value; } _s_a27ec345_optionalUserData;
typedef struct _s_a27ec345_rteParameters { void* value; } _s_a27ec345_rteParameters;
static inline _s_a27ec345_topLevelASGenerator _a27ec345_topLevelASGenerator(RedXRteHandleTopLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_a27ec345_topLevelASGenerator){value}; }
static inline _s_a27ec345_optionalFile _a27ec345_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a27ec345_optionalFile){value}; }
static inline _s_a27ec345_optionalLine _a27ec345_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a27ec345_optionalLine){value}; }
static inline _s_a27ec345_optionalUserData _a27ec345_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a27ec345_optionalUserData){value}; }
static inline _s_a27ec345_rteParameters _a27ec345_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a27ec345_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteDestroyTopLevelASGenerator(_s_a27ec345_topLevelASGenerator topLevelASGenerator, _s_a27ec345_optionalFile optionalFile, _s_a27ec345_optionalLine optionalLine, _s_a27ec345_optionalUserData optionalUserData, _s_a27ec345_rteParameters rteParameters) {
  redXRteDestroyTopLevelASGenerator(topLevelASGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteDestroyRootSignatureGenerator redXRteDestroyRootSignatureGenerator
#define _a7604f8e_rootSignatureGenerator(value) value
#define _a7604f8e_optionalFile(value) value
#define _a7604f8e_optionalLine(value) value
#define _a7604f8e_optionalUserData(value) value
#define _a7604f8e_rteParameters(value) value
#else
typedef struct _s_a7604f8e_rootSignatureGenerator { RedXRteHandleRootSignatureGenerator value; } _s_a7604f8e_rootSignatureGenerator;
typedef struct _s_a7604f8e_optionalFile { char* value; } _s_a7604f8e_optionalFile;
typedef struct _s_a7604f8e_optionalLine { int value; } _s_a7604f8e_optionalLine;
typedef struct _s_a7604f8e_optionalUserData { void* value; } _s_a7604f8e_optionalUserData;
typedef struct _s_a7604f8e_rteParameters { void* value; } _s_a7604f8e_rteParameters;
static inline _s_a7604f8e_rootSignatureGenerator _a7604f8e_rootSignatureGenerator(RedXRteHandleRootSignatureGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_a7604f8e_rootSignatureGenerator){value}; }
static inline _s_a7604f8e_optionalFile _a7604f8e_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_a7604f8e_optionalFile){value}; }
static inline _s_a7604f8e_optionalLine _a7604f8e_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_a7604f8e_optionalLine){value}; }
static inline _s_a7604f8e_optionalUserData _a7604f8e_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a7604f8e_optionalUserData){value}; }
static inline _s_a7604f8e_rteParameters _a7604f8e_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_a7604f8e_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteDestroyRootSignatureGenerator(_s_a7604f8e_rootSignatureGenerator rootSignatureGenerator, _s_a7604f8e_optionalFile optionalFile, _s_a7604f8e_optionalLine optionalLine, _s_a7604f8e_optionalUserData optionalUserData, _s_a7604f8e_rteParameters rteParameters) {
  redXRteDestroyRootSignatureGenerator(rootSignatureGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteDestroyRayTracingPipelineGenerator redXRteDestroyRayTracingPipelineGenerator
#define _b97685e0_rayTracingPipelineGenerator(value) value
#define _b97685e0_optionalFile(value) value
#define _b97685e0_optionalLine(value) value
#define _b97685e0_optionalUserData(value) value
#define _b97685e0_rteParameters(value) value
#else
typedef struct _s_b97685e0_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_b97685e0_rayTracingPipelineGenerator;
typedef struct _s_b97685e0_optionalFile { char* value; } _s_b97685e0_optionalFile;
typedef struct _s_b97685e0_optionalLine { int value; } _s_b97685e0_optionalLine;
typedef struct _s_b97685e0_optionalUserData { void* value; } _s_b97685e0_optionalUserData;
typedef struct _s_b97685e0_rteParameters { void* value; } _s_b97685e0_rteParameters;
static inline _s_b97685e0_rayTracingPipelineGenerator _b97685e0_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_b97685e0_rayTracingPipelineGenerator){value}; }
static inline _s_b97685e0_optionalFile _b97685e0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b97685e0_optionalFile){value}; }
static inline _s_b97685e0_optionalLine _b97685e0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b97685e0_optionalLine){value}; }
static inline _s_b97685e0_optionalUserData _b97685e0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b97685e0_optionalUserData){value}; }
static inline _s_b97685e0_rteParameters _b97685e0_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b97685e0_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteDestroyRayTracingPipelineGenerator(_s_b97685e0_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_b97685e0_optionalFile optionalFile, _s_b97685e0_optionalLine optionalLine, _s_b97685e0_optionalUserData optionalUserData, _s_b97685e0_rteParameters rteParameters) {
  redXRteDestroyRayTracingPipelineGenerator(rayTracingPipelineGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteDestroyShaderBindingTableGenerator redXRteDestroyShaderBindingTableGenerator
#define _1875e4f8_shaderBindingTableGenerator(value) value
#define _1875e4f8_optionalFile(value) value
#define _1875e4f8_optionalLine(value) value
#define _1875e4f8_optionalUserData(value) value
#define _1875e4f8_rteParameters(value) value
#else
typedef struct _s_1875e4f8_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_1875e4f8_shaderBindingTableGenerator;
typedef struct _s_1875e4f8_optionalFile { char* value; } _s_1875e4f8_optionalFile;
typedef struct _s_1875e4f8_optionalLine { int value; } _s_1875e4f8_optionalLine;
typedef struct _s_1875e4f8_optionalUserData { void* value; } _s_1875e4f8_optionalUserData;
typedef struct _s_1875e4f8_rteParameters { void* value; } _s_1875e4f8_rteParameters;
static inline _s_1875e4f8_shaderBindingTableGenerator _1875e4f8_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_1875e4f8_shaderBindingTableGenerator){value}; }
static inline _s_1875e4f8_optionalFile _1875e4f8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1875e4f8_optionalFile){value}; }
static inline _s_1875e4f8_optionalLine _1875e4f8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1875e4f8_optionalLine){value}; }
static inline _s_1875e4f8_optionalUserData _1875e4f8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1875e4f8_optionalUserData){value}; }
static inline _s_1875e4f8_rteParameters _1875e4f8_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1875e4f8_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteDestroyShaderBindingTableGenerator(_s_1875e4f8_shaderBindingTableGenerator shaderBindingTableGenerator, _s_1875e4f8_optionalFile optionalFile, _s_1875e4f8_optionalLine optionalLine, _s_1875e4f8_optionalUserData optionalUserData, _s_1875e4f8_rteParameters rteParameters) {
  redXRteDestroyShaderBindingTableGenerator(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteBottomLevelASGeneratorAddVertexBuffer redXRteBottomLevelASGeneratorAddVertexBuffer
#define _66739b83_bottomLevelASGenerator(value) value
#define _66739b83_vertexBuffer_ID3D12Resource(value) value
#define _66739b83_vertexOffsetInBytes(value) value
#define _66739b83_vertexCount(value) value
#define _66739b83_vertexSizeInBytes(value) value
#define _66739b83_transformBuffer_ID3D12Resource(value) value
#define _66739b83_transformOffsetInBytes(value) value
#define _66739b83_isOpaqueSuggestedDefaultValueIs1(value) value
#define _66739b83_optionalFile(value) value
#define _66739b83_optionalLine(value) value
#define _66739b83_optionalUserData(value) value
#define _66739b83_rteParameters(value) value
#else
typedef struct _s_66739b83_bottomLevelASGenerator { RedXRteHandleBottomLevelASGenerator value; } _s_66739b83_bottomLevelASGenerator;
typedef struct _s_66739b83_vertexBuffer_ID3D12Resource { void* value; } _s_66739b83_vertexBuffer_ID3D12Resource;
typedef struct _s_66739b83_vertexOffsetInBytes { uint64_t value; } _s_66739b83_vertexOffsetInBytes;
typedef struct _s_66739b83_vertexCount { uint32_t value; } _s_66739b83_vertexCount;
typedef struct _s_66739b83_vertexSizeInBytes { unsigned value; } _s_66739b83_vertexSizeInBytes;
typedef struct _s_66739b83_transformBuffer_ID3D12Resource { void* value; } _s_66739b83_transformBuffer_ID3D12Resource;
typedef struct _s_66739b83_transformOffsetInBytes { uint64_t value; } _s_66739b83_transformOffsetInBytes;
typedef struct _s_66739b83_isOpaqueSuggestedDefaultValueIs1 { RedBool32 value; } _s_66739b83_isOpaqueSuggestedDefaultValueIs1;
typedef struct _s_66739b83_optionalFile { char* value; } _s_66739b83_optionalFile;
typedef struct _s_66739b83_optionalLine { int value; } _s_66739b83_optionalLine;
typedef struct _s_66739b83_optionalUserData { void* value; } _s_66739b83_optionalUserData;
typedef struct _s_66739b83_rteParameters { void* value; } _s_66739b83_rteParameters;
static inline _s_66739b83_bottomLevelASGenerator _66739b83_bottomLevelASGenerator(RedXRteHandleBottomLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_66739b83_bottomLevelASGenerator){value}; }
static inline _s_66739b83_vertexBuffer_ID3D12Resource _66739b83_vertexBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_66739b83_vertexBuffer_ID3D12Resource){value}; }
static inline _s_66739b83_vertexOffsetInBytes _66739b83_vertexOffsetInBytes(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_66739b83_vertexOffsetInBytes){value}; }
static inline _s_66739b83_vertexCount _66739b83_vertexCount(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_66739b83_vertexCount){value}; }
static inline _s_66739b83_vertexSizeInBytes _66739b83_vertexSizeInBytes(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_66739b83_vertexSizeInBytes){value}; }
static inline _s_66739b83_transformBuffer_ID3D12Resource _66739b83_transformBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_66739b83_transformBuffer_ID3D12Resource){value}; }
static inline _s_66739b83_transformOffsetInBytes _66739b83_transformOffsetInBytes(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_66739b83_transformOffsetInBytes){value}; }
static inline _s_66739b83_isOpaqueSuggestedDefaultValueIs1 _66739b83_isOpaqueSuggestedDefaultValueIs1(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_66739b83_isOpaqueSuggestedDefaultValueIs1){value}; }
static inline _s_66739b83_optionalFile _66739b83_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_66739b83_optionalFile){value}; }
static inline _s_66739b83_optionalLine _66739b83_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_66739b83_optionalLine){value}; }
static inline _s_66739b83_optionalUserData _66739b83_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_66739b83_optionalUserData){value}; }
static inline _s_66739b83_rteParameters _66739b83_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_66739b83_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteBottomLevelASGeneratorAddVertexBuffer(_s_66739b83_bottomLevelASGenerator bottomLevelASGenerator, _s_66739b83_vertexBuffer_ID3D12Resource vertexBuffer_ID3D12Resource, _s_66739b83_vertexOffsetInBytes vertexOffsetInBytes, _s_66739b83_vertexCount vertexCount, _s_66739b83_vertexSizeInBytes vertexSizeInBytes, _s_66739b83_transformBuffer_ID3D12Resource transformBuffer_ID3D12Resource, _s_66739b83_transformOffsetInBytes transformOffsetInBytes, _s_66739b83_isOpaqueSuggestedDefaultValueIs1 isOpaqueSuggestedDefaultValueIs1, _s_66739b83_optionalFile optionalFile, _s_66739b83_optionalLine optionalLine, _s_66739b83_optionalUserData optionalUserData, _s_66739b83_rteParameters rteParameters) {
  redXRteBottomLevelASGeneratorAddVertexBuffer(bottomLevelASGenerator.value, vertexBuffer_ID3D12Resource.value, vertexOffsetInBytes.value, vertexCount.value, vertexSizeInBytes.value, transformBuffer_ID3D12Resource.value, transformOffsetInBytes.value, isOpaqueSuggestedDefaultValueIs1.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteBottomLevelASGeneratorAddVertexIndexBuffer redXRteBottomLevelASGeneratorAddVertexIndexBuffer
#define _3f47ec59_bottomLevelASGenerator(value) value
#define _3f47ec59_vertexBuffer_ID3D12Resource(value) value
#define _3f47ec59_vertexOffsetInBytes(value) value
#define _3f47ec59_vertexCount(value) value
#define _3f47ec59_vertexSizeInBytes(value) value
#define _3f47ec59_indexBuffer_ID3D12Resource(value) value
#define _3f47ec59_indexOffsetInBytes(value) value
#define _3f47ec59_indexCount(value) value
#define _3f47ec59_transformBuffer_ID3D12Resource(value) value
#define _3f47ec59_transformOffsetInBytes(value) value
#define _3f47ec59_isOpaqueSuggestedDefaultValueIs1(value) value
#define _3f47ec59_optionalFile(value) value
#define _3f47ec59_optionalLine(value) value
#define _3f47ec59_optionalUserData(value) value
#define _3f47ec59_rteParameters(value) value
#else
typedef struct _s_3f47ec59_bottomLevelASGenerator { RedXRteHandleBottomLevelASGenerator value; } _s_3f47ec59_bottomLevelASGenerator;
typedef struct _s_3f47ec59_vertexBuffer_ID3D12Resource { void* value; } _s_3f47ec59_vertexBuffer_ID3D12Resource;
typedef struct _s_3f47ec59_vertexOffsetInBytes { uint64_t value; } _s_3f47ec59_vertexOffsetInBytes;
typedef struct _s_3f47ec59_vertexCount { uint32_t value; } _s_3f47ec59_vertexCount;
typedef struct _s_3f47ec59_vertexSizeInBytes { unsigned value; } _s_3f47ec59_vertexSizeInBytes;
typedef struct _s_3f47ec59_indexBuffer_ID3D12Resource { void* value; } _s_3f47ec59_indexBuffer_ID3D12Resource;
typedef struct _s_3f47ec59_indexOffsetInBytes { uint64_t value; } _s_3f47ec59_indexOffsetInBytes;
typedef struct _s_3f47ec59_indexCount { uint32_t value; } _s_3f47ec59_indexCount;
typedef struct _s_3f47ec59_transformBuffer_ID3D12Resource { void* value; } _s_3f47ec59_transformBuffer_ID3D12Resource;
typedef struct _s_3f47ec59_transformOffsetInBytes { uint64_t value; } _s_3f47ec59_transformOffsetInBytes;
typedef struct _s_3f47ec59_isOpaqueSuggestedDefaultValueIs1 { RedBool32 value; } _s_3f47ec59_isOpaqueSuggestedDefaultValueIs1;
typedef struct _s_3f47ec59_optionalFile { char* value; } _s_3f47ec59_optionalFile;
typedef struct _s_3f47ec59_optionalLine { int value; } _s_3f47ec59_optionalLine;
typedef struct _s_3f47ec59_optionalUserData { void* value; } _s_3f47ec59_optionalUserData;
typedef struct _s_3f47ec59_rteParameters { void* value; } _s_3f47ec59_rteParameters;
static inline _s_3f47ec59_bottomLevelASGenerator _3f47ec59_bottomLevelASGenerator(RedXRteHandleBottomLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_bottomLevelASGenerator){value}; }
static inline _s_3f47ec59_vertexBuffer_ID3D12Resource _3f47ec59_vertexBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_vertexBuffer_ID3D12Resource){value}; }
static inline _s_3f47ec59_vertexOffsetInBytes _3f47ec59_vertexOffsetInBytes(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_vertexOffsetInBytes){value}; }
static inline _s_3f47ec59_vertexCount _3f47ec59_vertexCount(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_vertexCount){value}; }
static inline _s_3f47ec59_vertexSizeInBytes _3f47ec59_vertexSizeInBytes(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_vertexSizeInBytes){value}; }
static inline _s_3f47ec59_indexBuffer_ID3D12Resource _3f47ec59_indexBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_indexBuffer_ID3D12Resource){value}; }
static inline _s_3f47ec59_indexOffsetInBytes _3f47ec59_indexOffsetInBytes(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_indexOffsetInBytes){value}; }
static inline _s_3f47ec59_indexCount _3f47ec59_indexCount(uint32_t value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_indexCount){value}; }
static inline _s_3f47ec59_transformBuffer_ID3D12Resource _3f47ec59_transformBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_transformBuffer_ID3D12Resource){value}; }
static inline _s_3f47ec59_transformOffsetInBytes _3f47ec59_transformOffsetInBytes(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_transformOffsetInBytes){value}; }
static inline _s_3f47ec59_isOpaqueSuggestedDefaultValueIs1 _3f47ec59_isOpaqueSuggestedDefaultValueIs1(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_isOpaqueSuggestedDefaultValueIs1){value}; }
static inline _s_3f47ec59_optionalFile _3f47ec59_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_optionalFile){value}; }
static inline _s_3f47ec59_optionalLine _3f47ec59_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_optionalLine){value}; }
static inline _s_3f47ec59_optionalUserData _3f47ec59_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_optionalUserData){value}; }
static inline _s_3f47ec59_rteParameters _3f47ec59_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3f47ec59_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteBottomLevelASGeneratorAddVertexIndexBuffer(_s_3f47ec59_bottomLevelASGenerator bottomLevelASGenerator, _s_3f47ec59_vertexBuffer_ID3D12Resource vertexBuffer_ID3D12Resource, _s_3f47ec59_vertexOffsetInBytes vertexOffsetInBytes, _s_3f47ec59_vertexCount vertexCount, _s_3f47ec59_vertexSizeInBytes vertexSizeInBytes, _s_3f47ec59_indexBuffer_ID3D12Resource indexBuffer_ID3D12Resource, _s_3f47ec59_indexOffsetInBytes indexOffsetInBytes, _s_3f47ec59_indexCount indexCount, _s_3f47ec59_transformBuffer_ID3D12Resource transformBuffer_ID3D12Resource, _s_3f47ec59_transformOffsetInBytes transformOffsetInBytes, _s_3f47ec59_isOpaqueSuggestedDefaultValueIs1 isOpaqueSuggestedDefaultValueIs1, _s_3f47ec59_optionalFile optionalFile, _s_3f47ec59_optionalLine optionalLine, _s_3f47ec59_optionalUserData optionalUserData, _s_3f47ec59_rteParameters rteParameters) {
  redXRteBottomLevelASGeneratorAddVertexIndexBuffer(bottomLevelASGenerator.value, vertexBuffer_ID3D12Resource.value, vertexOffsetInBytes.value, vertexCount.value, vertexSizeInBytes.value, indexBuffer_ID3D12Resource.value, indexOffsetInBytes.value, indexCount.value, transformBuffer_ID3D12Resource.value, transformOffsetInBytes.value, isOpaqueSuggestedDefaultValueIs1.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteBottomLevelASGeneratorComputeASBufferSizes redXRteBottomLevelASGeneratorComputeASBufferSizes
#define _5d0d2ee3_bottomLevelASGenerator(value) value
#define _5d0d2ee3_device_ID3D12Device5(value) value
#define _5d0d2ee3_allowUpdate(value) value
#define _5d0d2ee3_scratchSizeInBytes(value) value
#define _5d0d2ee3_resultSizeInBytes(value) value
#define _5d0d2ee3_optionalFile(value) value
#define _5d0d2ee3_optionalLine(value) value
#define _5d0d2ee3_optionalUserData(value) value
#define _5d0d2ee3_rteParameters(value) value
#else
typedef struct _s_5d0d2ee3_bottomLevelASGenerator { RedXRteHandleBottomLevelASGenerator value; } _s_5d0d2ee3_bottomLevelASGenerator;
typedef struct _s_5d0d2ee3_device_ID3D12Device5 { void* value; } _s_5d0d2ee3_device_ID3D12Device5;
typedef struct _s_5d0d2ee3_allowUpdate { RedBool32 value; } _s_5d0d2ee3_allowUpdate;
typedef struct _s_5d0d2ee3_scratchSizeInBytes { uint64_t* value; } _s_5d0d2ee3_scratchSizeInBytes;
typedef struct _s_5d0d2ee3_resultSizeInBytes { uint64_t* value; } _s_5d0d2ee3_resultSizeInBytes;
typedef struct _s_5d0d2ee3_optionalFile { char* value; } _s_5d0d2ee3_optionalFile;
typedef struct _s_5d0d2ee3_optionalLine { int value; } _s_5d0d2ee3_optionalLine;
typedef struct _s_5d0d2ee3_optionalUserData { void* value; } _s_5d0d2ee3_optionalUserData;
typedef struct _s_5d0d2ee3_rteParameters { void* value; } _s_5d0d2ee3_rteParameters;
static inline _s_5d0d2ee3_bottomLevelASGenerator _5d0d2ee3_bottomLevelASGenerator(RedXRteHandleBottomLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_5d0d2ee3_bottomLevelASGenerator){value}; }
static inline _s_5d0d2ee3_device_ID3D12Device5 _5d0d2ee3_device_ID3D12Device5(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5d0d2ee3_device_ID3D12Device5){value}; }
static inline _s_5d0d2ee3_allowUpdate _5d0d2ee3_allowUpdate(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_5d0d2ee3_allowUpdate){value}; }
static inline _s_5d0d2ee3_scratchSizeInBytes _5d0d2ee3_scratchSizeInBytes(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_5d0d2ee3_scratchSizeInBytes){value}; }
static inline _s_5d0d2ee3_resultSizeInBytes _5d0d2ee3_resultSizeInBytes(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_5d0d2ee3_resultSizeInBytes){value}; }
static inline _s_5d0d2ee3_optionalFile _5d0d2ee3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_5d0d2ee3_optionalFile){value}; }
static inline _s_5d0d2ee3_optionalLine _5d0d2ee3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_5d0d2ee3_optionalLine){value}; }
static inline _s_5d0d2ee3_optionalUserData _5d0d2ee3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5d0d2ee3_optionalUserData){value}; }
static inline _s_5d0d2ee3_rteParameters _5d0d2ee3_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_5d0d2ee3_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteBottomLevelASGeneratorComputeASBufferSizes(_s_5d0d2ee3_bottomLevelASGenerator bottomLevelASGenerator, _s_5d0d2ee3_device_ID3D12Device5 device_ID3D12Device5, _s_5d0d2ee3_allowUpdate allowUpdate, _s_5d0d2ee3_scratchSizeInBytes scratchSizeInBytes, _s_5d0d2ee3_resultSizeInBytes resultSizeInBytes, _s_5d0d2ee3_optionalFile optionalFile, _s_5d0d2ee3_optionalLine optionalLine, _s_5d0d2ee3_optionalUserData optionalUserData, _s_5d0d2ee3_rteParameters rteParameters) {
  redXRteBottomLevelASGeneratorComputeASBufferSizes(bottomLevelASGenerator.value, device_ID3D12Device5.value, allowUpdate.value, scratchSizeInBytes.value, resultSizeInBytes.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteBottomLevelASGeneratorGenerate redXRteBottomLevelASGeneratorGenerate
#define _658497d0_bottomLevelASGenerator(value) value
#define _658497d0_commandList_ID3D12GraphicsCommandList4(value) value
#define _658497d0_scratchBuffer_ID3D12Resource(value) value
#define _658497d0_resultBuffer_ID3D12Resource(value) value
#define _658497d0_isUpdateOnlySuggestedDefaultValueIs0(value) value
#define _658497d0_previousResultSuggestedDefaultValueIsNull_ID3D12Resource(value) value
#define _658497d0_optionalFile(value) value
#define _658497d0_optionalLine(value) value
#define _658497d0_optionalUserData(value) value
#define _658497d0_rteParameters(value) value
#else
typedef struct _s_658497d0_bottomLevelASGenerator { RedXRteHandleBottomLevelASGenerator value; } _s_658497d0_bottomLevelASGenerator;
typedef struct _s_658497d0_commandList_ID3D12GraphicsCommandList4 { void* value; } _s_658497d0_commandList_ID3D12GraphicsCommandList4;
typedef struct _s_658497d0_scratchBuffer_ID3D12Resource { void* value; } _s_658497d0_scratchBuffer_ID3D12Resource;
typedef struct _s_658497d0_resultBuffer_ID3D12Resource { void* value; } _s_658497d0_resultBuffer_ID3D12Resource;
typedef struct _s_658497d0_isUpdateOnlySuggestedDefaultValueIs0 { RedBool32 value; } _s_658497d0_isUpdateOnlySuggestedDefaultValueIs0;
typedef struct _s_658497d0_previousResultSuggestedDefaultValueIsNull_ID3D12Resource { void* value; } _s_658497d0_previousResultSuggestedDefaultValueIsNull_ID3D12Resource;
typedef struct _s_658497d0_optionalFile { char* value; } _s_658497d0_optionalFile;
typedef struct _s_658497d0_optionalLine { int value; } _s_658497d0_optionalLine;
typedef struct _s_658497d0_optionalUserData { void* value; } _s_658497d0_optionalUserData;
typedef struct _s_658497d0_rteParameters { void* value; } _s_658497d0_rteParameters;
static inline _s_658497d0_bottomLevelASGenerator _658497d0_bottomLevelASGenerator(RedXRteHandleBottomLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_658497d0_bottomLevelASGenerator){value}; }
static inline _s_658497d0_commandList_ID3D12GraphicsCommandList4 _658497d0_commandList_ID3D12GraphicsCommandList4(void* value) { return REDGPU_NP_STRUCT_INIT(_s_658497d0_commandList_ID3D12GraphicsCommandList4){value}; }
static inline _s_658497d0_scratchBuffer_ID3D12Resource _658497d0_scratchBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_658497d0_scratchBuffer_ID3D12Resource){value}; }
static inline _s_658497d0_resultBuffer_ID3D12Resource _658497d0_resultBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_658497d0_resultBuffer_ID3D12Resource){value}; }
static inline _s_658497d0_isUpdateOnlySuggestedDefaultValueIs0 _658497d0_isUpdateOnlySuggestedDefaultValueIs0(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_658497d0_isUpdateOnlySuggestedDefaultValueIs0){value}; }
static inline _s_658497d0_previousResultSuggestedDefaultValueIsNull_ID3D12Resource _658497d0_previousResultSuggestedDefaultValueIsNull_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_658497d0_previousResultSuggestedDefaultValueIsNull_ID3D12Resource){value}; }
static inline _s_658497d0_optionalFile _658497d0_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_658497d0_optionalFile){value}; }
static inline _s_658497d0_optionalLine _658497d0_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_658497d0_optionalLine){value}; }
static inline _s_658497d0_optionalUserData _658497d0_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_658497d0_optionalUserData){value}; }
static inline _s_658497d0_rteParameters _658497d0_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_658497d0_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteBottomLevelASGeneratorGenerate(_s_658497d0_bottomLevelASGenerator bottomLevelASGenerator, _s_658497d0_commandList_ID3D12GraphicsCommandList4 commandList_ID3D12GraphicsCommandList4, _s_658497d0_scratchBuffer_ID3D12Resource scratchBuffer_ID3D12Resource, _s_658497d0_resultBuffer_ID3D12Resource resultBuffer_ID3D12Resource, _s_658497d0_isUpdateOnlySuggestedDefaultValueIs0 isUpdateOnlySuggestedDefaultValueIs0, _s_658497d0_previousResultSuggestedDefaultValueIsNull_ID3D12Resource previousResultSuggestedDefaultValueIsNull_ID3D12Resource, _s_658497d0_optionalFile optionalFile, _s_658497d0_optionalLine optionalLine, _s_658497d0_optionalUserData optionalUserData, _s_658497d0_rteParameters rteParameters) {
  redXRteBottomLevelASGeneratorGenerate(bottomLevelASGenerator.value, commandList_ID3D12GraphicsCommandList4.value, scratchBuffer_ID3D12Resource.value, resultBuffer_ID3D12Resource.value, isUpdateOnlySuggestedDefaultValueIs0.value, previousResultSuggestedDefaultValueIsNull_ID3D12Resource.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteTopLevelASGeneratorSetInstancesCount redXRteTopLevelASGeneratorSetInstancesCount
#define _d437fba2_topLevelASGenerator(value) value
#define _d437fba2_instancesCount(value) value
#define _d437fba2_optionalFile(value) value
#define _d437fba2_optionalLine(value) value
#define _d437fba2_optionalUserData(value) value
#define _d437fba2_rteParameters(value) value
#else
typedef struct _s_d437fba2_topLevelASGenerator { RedXRteHandleTopLevelASGenerator value; } _s_d437fba2_topLevelASGenerator;
typedef struct _s_d437fba2_instancesCount { unsigned value; } _s_d437fba2_instancesCount;
typedef struct _s_d437fba2_optionalFile { char* value; } _s_d437fba2_optionalFile;
typedef struct _s_d437fba2_optionalLine { int value; } _s_d437fba2_optionalLine;
typedef struct _s_d437fba2_optionalUserData { void* value; } _s_d437fba2_optionalUserData;
typedef struct _s_d437fba2_rteParameters { void* value; } _s_d437fba2_rteParameters;
static inline _s_d437fba2_topLevelASGenerator _d437fba2_topLevelASGenerator(RedXRteHandleTopLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_d437fba2_topLevelASGenerator){value}; }
static inline _s_d437fba2_instancesCount _d437fba2_instancesCount(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_d437fba2_instancesCount){value}; }
static inline _s_d437fba2_optionalFile _d437fba2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_d437fba2_optionalFile){value}; }
static inline _s_d437fba2_optionalLine _d437fba2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_d437fba2_optionalLine){value}; }
static inline _s_d437fba2_optionalUserData _d437fba2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d437fba2_optionalUserData){value}; }
static inline _s_d437fba2_rteParameters _d437fba2_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_d437fba2_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteTopLevelASGeneratorSetInstancesCount(_s_d437fba2_topLevelASGenerator topLevelASGenerator, _s_d437fba2_instancesCount instancesCount, _s_d437fba2_optionalFile optionalFile, _s_d437fba2_optionalLine optionalLine, _s_d437fba2_optionalUserData optionalUserData, _s_d437fba2_rteParameters rteParameters) {
  redXRteTopLevelASGeneratorSetInstancesCount(topLevelASGenerator.value, instancesCount.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteTopLevelASGeneratorComputeASBufferSizes redXRteTopLevelASGeneratorComputeASBufferSizes
#define _ae98af20_topLevelASGenerator(value) value
#define _ae98af20_device_ID3D12Device5(value) value
#define _ae98af20_allowUpdate(value) value
#define _ae98af20_scratchSizeInBytes(value) value
#define _ae98af20_resultSizeInBytes(value) value
#define _ae98af20_descriptorsSizeInBytes(value) value
#define _ae98af20_optionalFile(value) value
#define _ae98af20_optionalLine(value) value
#define _ae98af20_optionalUserData(value) value
#define _ae98af20_rteParameters(value) value
#else
typedef struct _s_ae98af20_topLevelASGenerator { RedXRteHandleTopLevelASGenerator value; } _s_ae98af20_topLevelASGenerator;
typedef struct _s_ae98af20_device_ID3D12Device5 { void* value; } _s_ae98af20_device_ID3D12Device5;
typedef struct _s_ae98af20_allowUpdate { RedBool32 value; } _s_ae98af20_allowUpdate;
typedef struct _s_ae98af20_scratchSizeInBytes { uint64_t* value; } _s_ae98af20_scratchSizeInBytes;
typedef struct _s_ae98af20_resultSizeInBytes { uint64_t* value; } _s_ae98af20_resultSizeInBytes;
typedef struct _s_ae98af20_descriptorsSizeInBytes { uint64_t* value; } _s_ae98af20_descriptorsSizeInBytes;
typedef struct _s_ae98af20_optionalFile { char* value; } _s_ae98af20_optionalFile;
typedef struct _s_ae98af20_optionalLine { int value; } _s_ae98af20_optionalLine;
typedef struct _s_ae98af20_optionalUserData { void* value; } _s_ae98af20_optionalUserData;
typedef struct _s_ae98af20_rteParameters { void* value; } _s_ae98af20_rteParameters;
static inline _s_ae98af20_topLevelASGenerator _ae98af20_topLevelASGenerator(RedXRteHandleTopLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_ae98af20_topLevelASGenerator){value}; }
static inline _s_ae98af20_device_ID3D12Device5 _ae98af20_device_ID3D12Device5(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ae98af20_device_ID3D12Device5){value}; }
static inline _s_ae98af20_allowUpdate _ae98af20_allowUpdate(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_ae98af20_allowUpdate){value}; }
static inline _s_ae98af20_scratchSizeInBytes _ae98af20_scratchSizeInBytes(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_ae98af20_scratchSizeInBytes){value}; }
static inline _s_ae98af20_resultSizeInBytes _ae98af20_resultSizeInBytes(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_ae98af20_resultSizeInBytes){value}; }
static inline _s_ae98af20_descriptorsSizeInBytes _ae98af20_descriptorsSizeInBytes(uint64_t* value) { return REDGPU_NP_STRUCT_INIT(_s_ae98af20_descriptorsSizeInBytes){value}; }
static inline _s_ae98af20_optionalFile _ae98af20_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ae98af20_optionalFile){value}; }
static inline _s_ae98af20_optionalLine _ae98af20_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ae98af20_optionalLine){value}; }
static inline _s_ae98af20_optionalUserData _ae98af20_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ae98af20_optionalUserData){value}; }
static inline _s_ae98af20_rteParameters _ae98af20_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ae98af20_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteTopLevelASGeneratorComputeASBufferSizes(_s_ae98af20_topLevelASGenerator topLevelASGenerator, _s_ae98af20_device_ID3D12Device5 device_ID3D12Device5, _s_ae98af20_allowUpdate allowUpdate, _s_ae98af20_scratchSizeInBytes scratchSizeInBytes, _s_ae98af20_resultSizeInBytes resultSizeInBytes, _s_ae98af20_descriptorsSizeInBytes descriptorsSizeInBytes, _s_ae98af20_optionalFile optionalFile, _s_ae98af20_optionalLine optionalLine, _s_ae98af20_optionalUserData optionalUserData, _s_ae98af20_rteParameters rteParameters) {
  redXRteTopLevelASGeneratorComputeASBufferSizes(topLevelASGenerator.value, device_ID3D12Device5.value, allowUpdate.value, scratchSizeInBytes.value, resultSizeInBytes.value, descriptorsSizeInBytes.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteTopLevelASGeneratorGenerate redXRteTopLevelASGeneratorGenerate
#define _c2de0b17_topLevelASGenerator(value) value
#define _c2de0b17_commandList_ID3D12GraphicsCommandList4(value) value
#define _c2de0b17_scratchBuffer_ID3D12Resource(value) value
#define _c2de0b17_resultBuffer_ID3D12Resource(value) value
#define _c2de0b17_descriptorsBuffer_ID3D12Resource(value) value
#define _c2de0b17_isUpdateOnlySuggestedDefaultValueIs0(value) value
#define _c2de0b17_previousResultSuggestedDefaultValueIsNull_ID3D12Resource(value) value
#define _c2de0b17_optionalFile(value) value
#define _c2de0b17_optionalLine(value) value
#define _c2de0b17_optionalUserData(value) value
#define _c2de0b17_rteParameters(value) value
#else
typedef struct _s_c2de0b17_topLevelASGenerator { RedXRteHandleTopLevelASGenerator value; } _s_c2de0b17_topLevelASGenerator;
typedef struct _s_c2de0b17_commandList_ID3D12GraphicsCommandList4 { void* value; } _s_c2de0b17_commandList_ID3D12GraphicsCommandList4;
typedef struct _s_c2de0b17_scratchBuffer_ID3D12Resource { void* value; } _s_c2de0b17_scratchBuffer_ID3D12Resource;
typedef struct _s_c2de0b17_resultBuffer_ID3D12Resource { void* value; } _s_c2de0b17_resultBuffer_ID3D12Resource;
typedef struct _s_c2de0b17_descriptorsBuffer_ID3D12Resource { void* value; } _s_c2de0b17_descriptorsBuffer_ID3D12Resource;
typedef struct _s_c2de0b17_isUpdateOnlySuggestedDefaultValueIs0 { RedBool32 value; } _s_c2de0b17_isUpdateOnlySuggestedDefaultValueIs0;
typedef struct _s_c2de0b17_previousResultSuggestedDefaultValueIsNull_ID3D12Resource { void* value; } _s_c2de0b17_previousResultSuggestedDefaultValueIsNull_ID3D12Resource;
typedef struct _s_c2de0b17_optionalFile { char* value; } _s_c2de0b17_optionalFile;
typedef struct _s_c2de0b17_optionalLine { int value; } _s_c2de0b17_optionalLine;
typedef struct _s_c2de0b17_optionalUserData { void* value; } _s_c2de0b17_optionalUserData;
typedef struct _s_c2de0b17_rteParameters { void* value; } _s_c2de0b17_rteParameters;
static inline _s_c2de0b17_topLevelASGenerator _c2de0b17_topLevelASGenerator(RedXRteHandleTopLevelASGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_c2de0b17_topLevelASGenerator){value}; }
static inline _s_c2de0b17_commandList_ID3D12GraphicsCommandList4 _c2de0b17_commandList_ID3D12GraphicsCommandList4(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c2de0b17_commandList_ID3D12GraphicsCommandList4){value}; }
static inline _s_c2de0b17_scratchBuffer_ID3D12Resource _c2de0b17_scratchBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c2de0b17_scratchBuffer_ID3D12Resource){value}; }
static inline _s_c2de0b17_resultBuffer_ID3D12Resource _c2de0b17_resultBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c2de0b17_resultBuffer_ID3D12Resource){value}; }
static inline _s_c2de0b17_descriptorsBuffer_ID3D12Resource _c2de0b17_descriptorsBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c2de0b17_descriptorsBuffer_ID3D12Resource){value}; }
static inline _s_c2de0b17_isUpdateOnlySuggestedDefaultValueIs0 _c2de0b17_isUpdateOnlySuggestedDefaultValueIs0(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_c2de0b17_isUpdateOnlySuggestedDefaultValueIs0){value}; }
static inline _s_c2de0b17_previousResultSuggestedDefaultValueIsNull_ID3D12Resource _c2de0b17_previousResultSuggestedDefaultValueIsNull_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c2de0b17_previousResultSuggestedDefaultValueIsNull_ID3D12Resource){value}; }
static inline _s_c2de0b17_optionalFile _c2de0b17_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c2de0b17_optionalFile){value}; }
static inline _s_c2de0b17_optionalLine _c2de0b17_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c2de0b17_optionalLine){value}; }
static inline _s_c2de0b17_optionalUserData _c2de0b17_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c2de0b17_optionalUserData){value}; }
static inline _s_c2de0b17_rteParameters _c2de0b17_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c2de0b17_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteTopLevelASGeneratorGenerate(_s_c2de0b17_topLevelASGenerator topLevelASGenerator, _s_c2de0b17_commandList_ID3D12GraphicsCommandList4 commandList_ID3D12GraphicsCommandList4, _s_c2de0b17_scratchBuffer_ID3D12Resource scratchBuffer_ID3D12Resource, _s_c2de0b17_resultBuffer_ID3D12Resource resultBuffer_ID3D12Resource, _s_c2de0b17_descriptorsBuffer_ID3D12Resource descriptorsBuffer_ID3D12Resource, _s_c2de0b17_isUpdateOnlySuggestedDefaultValueIs0 isUpdateOnlySuggestedDefaultValueIs0, _s_c2de0b17_previousResultSuggestedDefaultValueIsNull_ID3D12Resource previousResultSuggestedDefaultValueIsNull_ID3D12Resource, _s_c2de0b17_optionalFile optionalFile, _s_c2de0b17_optionalLine optionalLine, _s_c2de0b17_optionalUserData optionalUserData, _s_c2de0b17_rteParameters rteParameters) {
  redXRteTopLevelASGeneratorGenerate(topLevelASGenerator.value, commandList_ID3D12GraphicsCommandList4.value, scratchBuffer_ID3D12Resource.value, resultBuffer_ID3D12Resource.value, descriptorsBuffer_ID3D12Resource.value, isUpdateOnlySuggestedDefaultValueIs0.value, previousResultSuggestedDefaultValueIsNull_ID3D12Resource.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRootSignatureGeneratorAddHeapRangesParameter redXRteRootSignatureGeneratorAddHeapRangesParameter
#define _1aba18af_rootSignatureGenerator(value) value
#define _1aba18af_rangesCount(value) value
#define _1aba18af_ranges_D3D12_DESCRIPTOR_RANGE(value) value
#define _1aba18af_optionalFile(value) value
#define _1aba18af_optionalLine(value) value
#define _1aba18af_optionalUserData(value) value
#define _1aba18af_rteParameters(value) value
#else
typedef struct _s_1aba18af_rootSignatureGenerator { RedXRteHandleRootSignatureGenerator value; } _s_1aba18af_rootSignatureGenerator;
typedef struct _s_1aba18af_rangesCount { uint64_t value; } _s_1aba18af_rangesCount;
typedef struct _s_1aba18af_ranges_D3D12_DESCRIPTOR_RANGE { void* value; } _s_1aba18af_ranges_D3D12_DESCRIPTOR_RANGE;
typedef struct _s_1aba18af_optionalFile { char* value; } _s_1aba18af_optionalFile;
typedef struct _s_1aba18af_optionalLine { int value; } _s_1aba18af_optionalLine;
typedef struct _s_1aba18af_optionalUserData { void* value; } _s_1aba18af_optionalUserData;
typedef struct _s_1aba18af_rteParameters { void* value; } _s_1aba18af_rteParameters;
static inline _s_1aba18af_rootSignatureGenerator _1aba18af_rootSignatureGenerator(RedXRteHandleRootSignatureGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_1aba18af_rootSignatureGenerator){value}; }
static inline _s_1aba18af_rangesCount _1aba18af_rangesCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_1aba18af_rangesCount){value}; }
static inline _s_1aba18af_ranges_D3D12_DESCRIPTOR_RANGE _1aba18af_ranges_D3D12_DESCRIPTOR_RANGE(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1aba18af_ranges_D3D12_DESCRIPTOR_RANGE){value}; }
static inline _s_1aba18af_optionalFile _1aba18af_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_1aba18af_optionalFile){value}; }
static inline _s_1aba18af_optionalLine _1aba18af_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_1aba18af_optionalLine){value}; }
static inline _s_1aba18af_optionalUserData _1aba18af_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1aba18af_optionalUserData){value}; }
static inline _s_1aba18af_rteParameters _1aba18af_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_1aba18af_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRootSignatureGeneratorAddHeapRangesParameter(_s_1aba18af_rootSignatureGenerator rootSignatureGenerator, _s_1aba18af_rangesCount rangesCount, _s_1aba18af_ranges_D3D12_DESCRIPTOR_RANGE ranges_D3D12_DESCRIPTOR_RANGE, _s_1aba18af_optionalFile optionalFile, _s_1aba18af_optionalLine optionalLine, _s_1aba18af_optionalUserData optionalUserData, _s_1aba18af_rteParameters rteParameters) {
  redXRteRootSignatureGeneratorAddHeapRangesParameter(rootSignatureGenerator.value, rangesCount.value, ranges_D3D12_DESCRIPTOR_RANGE.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRootSignatureGeneratorAddRootParameter redXRteRootSignatureGeneratorAddRootParameter
#define _cd6c90e3_rootSignatureGenerator(value) value
#define _cd6c90e3_type_D3D12_ROOT_PARAMETER_TYPE(value) value
#define _cd6c90e3_shaderRegisterSuggestedDefaultValueIs0(value) value
#define _cd6c90e3_registerSpaceSuggestedDefaultValueIs0(value) value
#define _cd6c90e3_numRootConstantsSuggestedDefaultValueIs1(value) value
#define _cd6c90e3_optionalFile(value) value
#define _cd6c90e3_optionalLine(value) value
#define _cd6c90e3_optionalUserData(value) value
#define _cd6c90e3_rteParameters(value) value
#else
typedef struct _s_cd6c90e3_rootSignatureGenerator { RedXRteHandleRootSignatureGenerator value; } _s_cd6c90e3_rootSignatureGenerator;
typedef struct _s_cd6c90e3_type_D3D12_ROOT_PARAMETER_TYPE { unsigned value; } _s_cd6c90e3_type_D3D12_ROOT_PARAMETER_TYPE;
typedef struct _s_cd6c90e3_shaderRegisterSuggestedDefaultValueIs0 { unsigned value; } _s_cd6c90e3_shaderRegisterSuggestedDefaultValueIs0;
typedef struct _s_cd6c90e3_registerSpaceSuggestedDefaultValueIs0 { unsigned value; } _s_cd6c90e3_registerSpaceSuggestedDefaultValueIs0;
typedef struct _s_cd6c90e3_numRootConstantsSuggestedDefaultValueIs1 { unsigned value; } _s_cd6c90e3_numRootConstantsSuggestedDefaultValueIs1;
typedef struct _s_cd6c90e3_optionalFile { char* value; } _s_cd6c90e3_optionalFile;
typedef struct _s_cd6c90e3_optionalLine { int value; } _s_cd6c90e3_optionalLine;
typedef struct _s_cd6c90e3_optionalUserData { void* value; } _s_cd6c90e3_optionalUserData;
typedef struct _s_cd6c90e3_rteParameters { void* value; } _s_cd6c90e3_rteParameters;
static inline _s_cd6c90e3_rootSignatureGenerator _cd6c90e3_rootSignatureGenerator(RedXRteHandleRootSignatureGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_cd6c90e3_rootSignatureGenerator){value}; }
static inline _s_cd6c90e3_type_D3D12_ROOT_PARAMETER_TYPE _cd6c90e3_type_D3D12_ROOT_PARAMETER_TYPE(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cd6c90e3_type_D3D12_ROOT_PARAMETER_TYPE){value}; }
static inline _s_cd6c90e3_shaderRegisterSuggestedDefaultValueIs0 _cd6c90e3_shaderRegisterSuggestedDefaultValueIs0(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cd6c90e3_shaderRegisterSuggestedDefaultValueIs0){value}; }
static inline _s_cd6c90e3_registerSpaceSuggestedDefaultValueIs0 _cd6c90e3_registerSpaceSuggestedDefaultValueIs0(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cd6c90e3_registerSpaceSuggestedDefaultValueIs0){value}; }
static inline _s_cd6c90e3_numRootConstantsSuggestedDefaultValueIs1 _cd6c90e3_numRootConstantsSuggestedDefaultValueIs1(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_cd6c90e3_numRootConstantsSuggestedDefaultValueIs1){value}; }
static inline _s_cd6c90e3_optionalFile _cd6c90e3_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_cd6c90e3_optionalFile){value}; }
static inline _s_cd6c90e3_optionalLine _cd6c90e3_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_cd6c90e3_optionalLine){value}; }
static inline _s_cd6c90e3_optionalUserData _cd6c90e3_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cd6c90e3_optionalUserData){value}; }
static inline _s_cd6c90e3_rteParameters _cd6c90e3_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_cd6c90e3_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRootSignatureGeneratorAddRootParameter(_s_cd6c90e3_rootSignatureGenerator rootSignatureGenerator, _s_cd6c90e3_type_D3D12_ROOT_PARAMETER_TYPE type_D3D12_ROOT_PARAMETER_TYPE, _s_cd6c90e3_shaderRegisterSuggestedDefaultValueIs0 shaderRegisterSuggestedDefaultValueIs0, _s_cd6c90e3_registerSpaceSuggestedDefaultValueIs0 registerSpaceSuggestedDefaultValueIs0, _s_cd6c90e3_numRootConstantsSuggestedDefaultValueIs1 numRootConstantsSuggestedDefaultValueIs1, _s_cd6c90e3_optionalFile optionalFile, _s_cd6c90e3_optionalLine optionalLine, _s_cd6c90e3_optionalUserData optionalUserData, _s_cd6c90e3_rteParameters rteParameters) {
  redXRteRootSignatureGeneratorAddRootParameter(rootSignatureGenerator.value, type_D3D12_ROOT_PARAMETER_TYPE.value, shaderRegisterSuggestedDefaultValueIs0.value, registerSpaceSuggestedDefaultValueIs0.value, numRootConstantsSuggestedDefaultValueIs1.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRootSignatureGeneratorGenerate redXRteRootSignatureGeneratorGenerate
#define _f8c97e93_rootSignatureGenerator(value) value
#define _f8c97e93_device_ID3D12Device(value) value
#define _f8c97e93_isLocal(value) value
#define _f8c97e93_outRootSignature_ID3D12RootSignature(value) value
#define _f8c97e93_optionalFile(value) value
#define _f8c97e93_optionalLine(value) value
#define _f8c97e93_optionalUserData(value) value
#define _f8c97e93_rteParameters(value) value
#else
typedef struct _s_f8c97e93_rootSignatureGenerator { RedXRteHandleRootSignatureGenerator value; } _s_f8c97e93_rootSignatureGenerator;
typedef struct _s_f8c97e93_device_ID3D12Device { void* value; } _s_f8c97e93_device_ID3D12Device;
typedef struct _s_f8c97e93_isLocal { RedBool32 value; } _s_f8c97e93_isLocal;
typedef struct _s_f8c97e93_outRootSignature_ID3D12RootSignature { void** value; } _s_f8c97e93_outRootSignature_ID3D12RootSignature;
typedef struct _s_f8c97e93_optionalFile { char* value; } _s_f8c97e93_optionalFile;
typedef struct _s_f8c97e93_optionalLine { int value; } _s_f8c97e93_optionalLine;
typedef struct _s_f8c97e93_optionalUserData { void* value; } _s_f8c97e93_optionalUserData;
typedef struct _s_f8c97e93_rteParameters { void* value; } _s_f8c97e93_rteParameters;
static inline _s_f8c97e93_rootSignatureGenerator _f8c97e93_rootSignatureGenerator(RedXRteHandleRootSignatureGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_f8c97e93_rootSignatureGenerator){value}; }
static inline _s_f8c97e93_device_ID3D12Device _f8c97e93_device_ID3D12Device(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f8c97e93_device_ID3D12Device){value}; }
static inline _s_f8c97e93_isLocal _f8c97e93_isLocal(RedBool32 value) { return REDGPU_NP_STRUCT_INIT(_s_f8c97e93_isLocal){value}; }
static inline _s_f8c97e93_outRootSignature_ID3D12RootSignature _f8c97e93_outRootSignature_ID3D12RootSignature(void** value) { return REDGPU_NP_STRUCT_INIT(_s_f8c97e93_outRootSignature_ID3D12RootSignature){value}; }
static inline _s_f8c97e93_optionalFile _f8c97e93_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f8c97e93_optionalFile){value}; }
static inline _s_f8c97e93_optionalLine _f8c97e93_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f8c97e93_optionalLine){value}; }
static inline _s_f8c97e93_optionalUserData _f8c97e93_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f8c97e93_optionalUserData){value}; }
static inline _s_f8c97e93_rteParameters _f8c97e93_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f8c97e93_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRootSignatureGeneratorGenerate(_s_f8c97e93_rootSignatureGenerator rootSignatureGenerator, _s_f8c97e93_device_ID3D12Device device_ID3D12Device, _s_f8c97e93_isLocal isLocal, _s_f8c97e93_outRootSignature_ID3D12RootSignature outRootSignature_ID3D12RootSignature, _s_f8c97e93_optionalFile optionalFile, _s_f8c97e93_optionalLine optionalLine, _s_f8c97e93_optionalUserData optionalUserData, _s_f8c97e93_rteParameters rteParameters) {
  redXRteRootSignatureGeneratorGenerate(rootSignatureGenerator.value, device_ID3D12Device.value, isLocal.value, outRootSignature_ID3D12RootSignature.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorAddLibrary redXRteRayTracingPipelineGeneratorAddLibrary
#define _07102273_rayTracingPipelineGenerator(value) value
#define _07102273_dxilLibraryBufferSize(value) value
#define _07102273_dxilLibraryBufferPointer(value) value
#define _07102273_symbolExportsCount(value) value
#define _07102273_symbolExports(value) value
#define _07102273_optionalFile(value) value
#define _07102273_optionalLine(value) value
#define _07102273_optionalUserData(value) value
#define _07102273_rteParameters(value) value
#else
typedef struct _s_07102273_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_07102273_rayTracingPipelineGenerator;
typedef struct _s_07102273_dxilLibraryBufferSize { uint64_t value; } _s_07102273_dxilLibraryBufferSize;
typedef struct _s_07102273_dxilLibraryBufferPointer { void* value; } _s_07102273_dxilLibraryBufferPointer;
typedef struct _s_07102273_symbolExportsCount { uint64_t value; } _s_07102273_symbolExportsCount;
typedef struct _s_07102273_symbolExports { wchar_t** value; } _s_07102273_symbolExports;
typedef struct _s_07102273_optionalFile { char* value; } _s_07102273_optionalFile;
typedef struct _s_07102273_optionalLine { int value; } _s_07102273_optionalLine;
typedef struct _s_07102273_optionalUserData { void* value; } _s_07102273_optionalUserData;
typedef struct _s_07102273_rteParameters { void* value; } _s_07102273_rteParameters;
static inline _s_07102273_rayTracingPipelineGenerator _07102273_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_07102273_rayTracingPipelineGenerator){value}; }
static inline _s_07102273_dxilLibraryBufferSize _07102273_dxilLibraryBufferSize(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_07102273_dxilLibraryBufferSize){value}; }
static inline _s_07102273_dxilLibraryBufferPointer _07102273_dxilLibraryBufferPointer(void* value) { return REDGPU_NP_STRUCT_INIT(_s_07102273_dxilLibraryBufferPointer){value}; }
static inline _s_07102273_symbolExportsCount _07102273_symbolExportsCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_07102273_symbolExportsCount){value}; }
static inline _s_07102273_symbolExports _07102273_symbolExports(wchar_t** value) { return REDGPU_NP_STRUCT_INIT(_s_07102273_symbolExports){value}; }
static inline _s_07102273_optionalFile _07102273_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_07102273_optionalFile){value}; }
static inline _s_07102273_optionalLine _07102273_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_07102273_optionalLine){value}; }
static inline _s_07102273_optionalUserData _07102273_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_07102273_optionalUserData){value}; }
static inline _s_07102273_rteParameters _07102273_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_07102273_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorAddLibrary(_s_07102273_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_07102273_dxilLibraryBufferSize dxilLibraryBufferSize, _s_07102273_dxilLibraryBufferPointer dxilLibraryBufferPointer, _s_07102273_symbolExportsCount symbolExportsCount, _s_07102273_symbolExports symbolExports, _s_07102273_optionalFile optionalFile, _s_07102273_optionalLine optionalLine, _s_07102273_optionalUserData optionalUserData, _s_07102273_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorAddLibrary(rayTracingPipelineGenerator.value, dxilLibraryBufferSize.value, dxilLibraryBufferPointer.value, symbolExportsCount.value, symbolExports.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorAddHitGroup redXRteRayTracingPipelineGeneratorAddHitGroup
#define _c3eeb8d8_rayTracingPipelineGenerator(value) value
#define _c3eeb8d8_hitGroupName(value) value
#define _c3eeb8d8_closestHitSymbol(value) value
#define _c3eeb8d8_anyHitSymbolSuggestedDefaultValueIsNull(value) value
#define _c3eeb8d8_intersectionSymbolSuggestedDefaultValueIsNull(value) value
#define _c3eeb8d8_optionalFile(value) value
#define _c3eeb8d8_optionalLine(value) value
#define _c3eeb8d8_optionalUserData(value) value
#define _c3eeb8d8_rteParameters(value) value
#else
typedef struct _s_c3eeb8d8_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_c3eeb8d8_rayTracingPipelineGenerator;
typedef struct _s_c3eeb8d8_hitGroupName { wchar_t* value; } _s_c3eeb8d8_hitGroupName;
typedef struct _s_c3eeb8d8_closestHitSymbol { wchar_t* value; } _s_c3eeb8d8_closestHitSymbol;
typedef struct _s_c3eeb8d8_anyHitSymbolSuggestedDefaultValueIsNull { wchar_t* value; } _s_c3eeb8d8_anyHitSymbolSuggestedDefaultValueIsNull;
typedef struct _s_c3eeb8d8_intersectionSymbolSuggestedDefaultValueIsNull { wchar_t* value; } _s_c3eeb8d8_intersectionSymbolSuggestedDefaultValueIsNull;
typedef struct _s_c3eeb8d8_optionalFile { char* value; } _s_c3eeb8d8_optionalFile;
typedef struct _s_c3eeb8d8_optionalLine { int value; } _s_c3eeb8d8_optionalLine;
typedef struct _s_c3eeb8d8_optionalUserData { void* value; } _s_c3eeb8d8_optionalUserData;
typedef struct _s_c3eeb8d8_rteParameters { void* value; } _s_c3eeb8d8_rteParameters;
static inline _s_c3eeb8d8_rayTracingPipelineGenerator _c3eeb8d8_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_c3eeb8d8_rayTracingPipelineGenerator){value}; }
static inline _s_c3eeb8d8_hitGroupName _c3eeb8d8_hitGroupName(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_c3eeb8d8_hitGroupName){value}; }
static inline _s_c3eeb8d8_closestHitSymbol _c3eeb8d8_closestHitSymbol(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_c3eeb8d8_closestHitSymbol){value}; }
static inline _s_c3eeb8d8_anyHitSymbolSuggestedDefaultValueIsNull _c3eeb8d8_anyHitSymbolSuggestedDefaultValueIsNull(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_c3eeb8d8_anyHitSymbolSuggestedDefaultValueIsNull){value}; }
static inline _s_c3eeb8d8_intersectionSymbolSuggestedDefaultValueIsNull _c3eeb8d8_intersectionSymbolSuggestedDefaultValueIsNull(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_c3eeb8d8_intersectionSymbolSuggestedDefaultValueIsNull){value}; }
static inline _s_c3eeb8d8_optionalFile _c3eeb8d8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c3eeb8d8_optionalFile){value}; }
static inline _s_c3eeb8d8_optionalLine _c3eeb8d8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c3eeb8d8_optionalLine){value}; }
static inline _s_c3eeb8d8_optionalUserData _c3eeb8d8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c3eeb8d8_optionalUserData){value}; }
static inline _s_c3eeb8d8_rteParameters _c3eeb8d8_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c3eeb8d8_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorAddHitGroup(_s_c3eeb8d8_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_c3eeb8d8_hitGroupName hitGroupName, _s_c3eeb8d8_closestHitSymbol closestHitSymbol, _s_c3eeb8d8_anyHitSymbolSuggestedDefaultValueIsNull anyHitSymbolSuggestedDefaultValueIsNull, _s_c3eeb8d8_intersectionSymbolSuggestedDefaultValueIsNull intersectionSymbolSuggestedDefaultValueIsNull, _s_c3eeb8d8_optionalFile optionalFile, _s_c3eeb8d8_optionalLine optionalLine, _s_c3eeb8d8_optionalUserData optionalUserData, _s_c3eeb8d8_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorAddHitGroup(rayTracingPipelineGenerator.value, hitGroupName.value, closestHitSymbol.value, anyHitSymbolSuggestedDefaultValueIsNull.value, intersectionSymbolSuggestedDefaultValueIsNull.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorAddRootSignatureAssociation redXRteRayTracingPipelineGeneratorAddRootSignatureAssociation
#define _634f3222_rayTracingPipelineGenerator(value) value
#define _634f3222_rootSignature_ID3D12RootSignature(value) value
#define _634f3222_symbolsCount(value) value
#define _634f3222_symbols(value) value
#define _634f3222_optionalFile(value) value
#define _634f3222_optionalLine(value) value
#define _634f3222_optionalUserData(value) value
#define _634f3222_rteParameters(value) value
#else
typedef struct _s_634f3222_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_634f3222_rayTracingPipelineGenerator;
typedef struct _s_634f3222_rootSignature_ID3D12RootSignature { void* value; } _s_634f3222_rootSignature_ID3D12RootSignature;
typedef struct _s_634f3222_symbolsCount { uint64_t value; } _s_634f3222_symbolsCount;
typedef struct _s_634f3222_symbols { wchar_t** value; } _s_634f3222_symbols;
typedef struct _s_634f3222_optionalFile { char* value; } _s_634f3222_optionalFile;
typedef struct _s_634f3222_optionalLine { int value; } _s_634f3222_optionalLine;
typedef struct _s_634f3222_optionalUserData { void* value; } _s_634f3222_optionalUserData;
typedef struct _s_634f3222_rteParameters { void* value; } _s_634f3222_rteParameters;
static inline _s_634f3222_rayTracingPipelineGenerator _634f3222_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_634f3222_rayTracingPipelineGenerator){value}; }
static inline _s_634f3222_rootSignature_ID3D12RootSignature _634f3222_rootSignature_ID3D12RootSignature(void* value) { return REDGPU_NP_STRUCT_INIT(_s_634f3222_rootSignature_ID3D12RootSignature){value}; }
static inline _s_634f3222_symbolsCount _634f3222_symbolsCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_634f3222_symbolsCount){value}; }
static inline _s_634f3222_symbols _634f3222_symbols(wchar_t** value) { return REDGPU_NP_STRUCT_INIT(_s_634f3222_symbols){value}; }
static inline _s_634f3222_optionalFile _634f3222_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_634f3222_optionalFile){value}; }
static inline _s_634f3222_optionalLine _634f3222_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_634f3222_optionalLine){value}; }
static inline _s_634f3222_optionalUserData _634f3222_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_634f3222_optionalUserData){value}; }
static inline _s_634f3222_rteParameters _634f3222_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_634f3222_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorAddRootSignatureAssociation(_s_634f3222_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_634f3222_rootSignature_ID3D12RootSignature rootSignature_ID3D12RootSignature, _s_634f3222_symbolsCount symbolsCount, _s_634f3222_symbols symbols, _s_634f3222_optionalFile optionalFile, _s_634f3222_optionalLine optionalLine, _s_634f3222_optionalUserData optionalUserData, _s_634f3222_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorAddRootSignatureAssociation(rayTracingPipelineGenerator.value, rootSignature_ID3D12RootSignature.value, symbolsCount.value, symbols.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorSetMaxPayloadSize redXRteRayTracingPipelineGeneratorSetMaxPayloadSize
#define _aec1c54c_rayTracingPipelineGenerator(value) value
#define _aec1c54c_sizeInBytes(value) value
#define _aec1c54c_optionalFile(value) value
#define _aec1c54c_optionalLine(value) value
#define _aec1c54c_optionalUserData(value) value
#define _aec1c54c_rteParameters(value) value
#else
typedef struct _s_aec1c54c_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_aec1c54c_rayTracingPipelineGenerator;
typedef struct _s_aec1c54c_sizeInBytes { unsigned value; } _s_aec1c54c_sizeInBytes;
typedef struct _s_aec1c54c_optionalFile { char* value; } _s_aec1c54c_optionalFile;
typedef struct _s_aec1c54c_optionalLine { int value; } _s_aec1c54c_optionalLine;
typedef struct _s_aec1c54c_optionalUserData { void* value; } _s_aec1c54c_optionalUserData;
typedef struct _s_aec1c54c_rteParameters { void* value; } _s_aec1c54c_rteParameters;
static inline _s_aec1c54c_rayTracingPipelineGenerator _aec1c54c_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_aec1c54c_rayTracingPipelineGenerator){value}; }
static inline _s_aec1c54c_sizeInBytes _aec1c54c_sizeInBytes(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_aec1c54c_sizeInBytes){value}; }
static inline _s_aec1c54c_optionalFile _aec1c54c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_aec1c54c_optionalFile){value}; }
static inline _s_aec1c54c_optionalLine _aec1c54c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_aec1c54c_optionalLine){value}; }
static inline _s_aec1c54c_optionalUserData _aec1c54c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_aec1c54c_optionalUserData){value}; }
static inline _s_aec1c54c_rteParameters _aec1c54c_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_aec1c54c_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorSetMaxPayloadSize(_s_aec1c54c_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_aec1c54c_sizeInBytes sizeInBytes, _s_aec1c54c_optionalFile optionalFile, _s_aec1c54c_optionalLine optionalLine, _s_aec1c54c_optionalUserData optionalUserData, _s_aec1c54c_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorSetMaxPayloadSize(rayTracingPipelineGenerator.value, sizeInBytes.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorSetMaxAttributeSize redXRteRayTracingPipelineGeneratorSetMaxAttributeSize
#define _c5df8424_rayTracingPipelineGenerator(value) value
#define _c5df8424_sizeInBytes(value) value
#define _c5df8424_optionalFile(value) value
#define _c5df8424_optionalLine(value) value
#define _c5df8424_optionalUserData(value) value
#define _c5df8424_rteParameters(value) value
#else
typedef struct _s_c5df8424_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_c5df8424_rayTracingPipelineGenerator;
typedef struct _s_c5df8424_sizeInBytes { unsigned value; } _s_c5df8424_sizeInBytes;
typedef struct _s_c5df8424_optionalFile { char* value; } _s_c5df8424_optionalFile;
typedef struct _s_c5df8424_optionalLine { int value; } _s_c5df8424_optionalLine;
typedef struct _s_c5df8424_optionalUserData { void* value; } _s_c5df8424_optionalUserData;
typedef struct _s_c5df8424_rteParameters { void* value; } _s_c5df8424_rteParameters;
static inline _s_c5df8424_rayTracingPipelineGenerator _c5df8424_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_c5df8424_rayTracingPipelineGenerator){value}; }
static inline _s_c5df8424_sizeInBytes _c5df8424_sizeInBytes(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_c5df8424_sizeInBytes){value}; }
static inline _s_c5df8424_optionalFile _c5df8424_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c5df8424_optionalFile){value}; }
static inline _s_c5df8424_optionalLine _c5df8424_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c5df8424_optionalLine){value}; }
static inline _s_c5df8424_optionalUserData _c5df8424_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c5df8424_optionalUserData){value}; }
static inline _s_c5df8424_rteParameters _c5df8424_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c5df8424_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorSetMaxAttributeSize(_s_c5df8424_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_c5df8424_sizeInBytes sizeInBytes, _s_c5df8424_optionalFile optionalFile, _s_c5df8424_optionalLine optionalLine, _s_c5df8424_optionalUserData optionalUserData, _s_c5df8424_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorSetMaxAttributeSize(rayTracingPipelineGenerator.value, sizeInBytes.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorSetMaxRecursionDepth redXRteRayTracingPipelineGeneratorSetMaxRecursionDepth
#define _70239fbf_rayTracingPipelineGenerator(value) value
#define _70239fbf_maxDepth(value) value
#define _70239fbf_optionalFile(value) value
#define _70239fbf_optionalLine(value) value
#define _70239fbf_optionalUserData(value) value
#define _70239fbf_rteParameters(value) value
#else
typedef struct _s_70239fbf_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_70239fbf_rayTracingPipelineGenerator;
typedef struct _s_70239fbf_maxDepth { unsigned value; } _s_70239fbf_maxDepth;
typedef struct _s_70239fbf_optionalFile { char* value; } _s_70239fbf_optionalFile;
typedef struct _s_70239fbf_optionalLine { int value; } _s_70239fbf_optionalLine;
typedef struct _s_70239fbf_optionalUserData { void* value; } _s_70239fbf_optionalUserData;
typedef struct _s_70239fbf_rteParameters { void* value; } _s_70239fbf_rteParameters;
static inline _s_70239fbf_rayTracingPipelineGenerator _70239fbf_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_70239fbf_rayTracingPipelineGenerator){value}; }
static inline _s_70239fbf_maxDepth _70239fbf_maxDepth(unsigned value) { return REDGPU_NP_STRUCT_INIT(_s_70239fbf_maxDepth){value}; }
static inline _s_70239fbf_optionalFile _70239fbf_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_70239fbf_optionalFile){value}; }
static inline _s_70239fbf_optionalLine _70239fbf_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_70239fbf_optionalLine){value}; }
static inline _s_70239fbf_optionalUserData _70239fbf_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_70239fbf_optionalUserData){value}; }
static inline _s_70239fbf_rteParameters _70239fbf_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_70239fbf_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorSetMaxRecursionDepth(_s_70239fbf_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_70239fbf_maxDepth maxDepth, _s_70239fbf_optionalFile optionalFile, _s_70239fbf_optionalLine optionalLine, _s_70239fbf_optionalUserData optionalUserData, _s_70239fbf_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorSetMaxRecursionDepth(rayTracingPipelineGenerator.value, maxDepth.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteRayTracingPipelineGeneratorGenerate redXRteRayTracingPipelineGeneratorGenerate
#define _2fe6108c_rayTracingPipelineGenerator(value) value
#define _2fe6108c_outStateObject_ID3D12StateObject(value) value
#define _2fe6108c_outStateObjectProperties_ID3D12StateObjectProperties(value) value
#define _2fe6108c_optionalFile(value) value
#define _2fe6108c_optionalLine(value) value
#define _2fe6108c_optionalUserData(value) value
#define _2fe6108c_rteParameters(value) value
#else
typedef struct _s_2fe6108c_rayTracingPipelineGenerator { RedXRteHandleRayTracingPipelineGenerator value; } _s_2fe6108c_rayTracingPipelineGenerator;
typedef struct _s_2fe6108c_outStateObject_ID3D12StateObject { void** value; } _s_2fe6108c_outStateObject_ID3D12StateObject;
typedef struct _s_2fe6108c_outStateObjectProperties_ID3D12StateObjectProperties { void** value; } _s_2fe6108c_outStateObjectProperties_ID3D12StateObjectProperties;
typedef struct _s_2fe6108c_optionalFile { char* value; } _s_2fe6108c_optionalFile;
typedef struct _s_2fe6108c_optionalLine { int value; } _s_2fe6108c_optionalLine;
typedef struct _s_2fe6108c_optionalUserData { void* value; } _s_2fe6108c_optionalUserData;
typedef struct _s_2fe6108c_rteParameters { void* value; } _s_2fe6108c_rteParameters;
static inline _s_2fe6108c_rayTracingPipelineGenerator _2fe6108c_rayTracingPipelineGenerator(RedXRteHandleRayTracingPipelineGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_2fe6108c_rayTracingPipelineGenerator){value}; }
static inline _s_2fe6108c_outStateObject_ID3D12StateObject _2fe6108c_outStateObject_ID3D12StateObject(void** value) { return REDGPU_NP_STRUCT_INIT(_s_2fe6108c_outStateObject_ID3D12StateObject){value}; }
static inline _s_2fe6108c_outStateObjectProperties_ID3D12StateObjectProperties _2fe6108c_outStateObjectProperties_ID3D12StateObjectProperties(void** value) { return REDGPU_NP_STRUCT_INIT(_s_2fe6108c_outStateObjectProperties_ID3D12StateObjectProperties){value}; }
static inline _s_2fe6108c_optionalFile _2fe6108c_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_2fe6108c_optionalFile){value}; }
static inline _s_2fe6108c_optionalLine _2fe6108c_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_2fe6108c_optionalLine){value}; }
static inline _s_2fe6108c_optionalUserData _2fe6108c_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2fe6108c_optionalUserData){value}; }
static inline _s_2fe6108c_rteParameters _2fe6108c_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_2fe6108c_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteRayTracingPipelineGeneratorGenerate(_s_2fe6108c_rayTracingPipelineGenerator rayTracingPipelineGenerator, _s_2fe6108c_outStateObject_ID3D12StateObject outStateObject_ID3D12StateObject, _s_2fe6108c_outStateObjectProperties_ID3D12StateObjectProperties outStateObjectProperties_ID3D12StateObjectProperties, _s_2fe6108c_optionalFile optionalFile, _s_2fe6108c_optionalLine optionalLine, _s_2fe6108c_optionalUserData optionalUserData, _s_2fe6108c_rteParameters rteParameters) {
  redXRteRayTracingPipelineGeneratorGenerate(rayTracingPipelineGenerator.value, outStateObject_ID3D12StateObject.value, outStateObjectProperties_ID3D12StateObjectProperties.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorAddRayGenerationProgram redXRteShaderBindingTableGeneratorAddRayGenerationProgram
#define _f4dba286_shaderBindingTableGenerator(value) value
#define _f4dba286_entryPoint(value) value
#define _f4dba286_inputDatasCount(value) value
#define _f4dba286_inputDatas(value) value
#define _f4dba286_optionalFile(value) value
#define _f4dba286_optionalLine(value) value
#define _f4dba286_optionalUserData(value) value
#define _f4dba286_rteParameters(value) value
#else
typedef struct _s_f4dba286_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_f4dba286_shaderBindingTableGenerator;
typedef struct _s_f4dba286_entryPoint { wchar_t* value; } _s_f4dba286_entryPoint;
typedef struct _s_f4dba286_inputDatasCount { uint64_t value; } _s_f4dba286_inputDatasCount;
typedef struct _s_f4dba286_inputDatas { void** value; } _s_f4dba286_inputDatas;
typedef struct _s_f4dba286_optionalFile { char* value; } _s_f4dba286_optionalFile;
typedef struct _s_f4dba286_optionalLine { int value; } _s_f4dba286_optionalLine;
typedef struct _s_f4dba286_optionalUserData { void* value; } _s_f4dba286_optionalUserData;
typedef struct _s_f4dba286_rteParameters { void* value; } _s_f4dba286_rteParameters;
static inline _s_f4dba286_shaderBindingTableGenerator _f4dba286_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_f4dba286_shaderBindingTableGenerator){value}; }
static inline _s_f4dba286_entryPoint _f4dba286_entryPoint(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_f4dba286_entryPoint){value}; }
static inline _s_f4dba286_inputDatasCount _f4dba286_inputDatasCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_f4dba286_inputDatasCount){value}; }
static inline _s_f4dba286_inputDatas _f4dba286_inputDatas(void** value) { return REDGPU_NP_STRUCT_INIT(_s_f4dba286_inputDatas){value}; }
static inline _s_f4dba286_optionalFile _f4dba286_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f4dba286_optionalFile){value}; }
static inline _s_f4dba286_optionalLine _f4dba286_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f4dba286_optionalLine){value}; }
static inline _s_f4dba286_optionalUserData _f4dba286_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f4dba286_optionalUserData){value}; }
static inline _s_f4dba286_rteParameters _f4dba286_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f4dba286_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteShaderBindingTableGeneratorAddRayGenerationProgram(_s_f4dba286_shaderBindingTableGenerator shaderBindingTableGenerator, _s_f4dba286_entryPoint entryPoint, _s_f4dba286_inputDatasCount inputDatasCount, _s_f4dba286_inputDatas inputDatas, _s_f4dba286_optionalFile optionalFile, _s_f4dba286_optionalLine optionalLine, _s_f4dba286_optionalUserData optionalUserData, _s_f4dba286_rteParameters rteParameters) {
  redXRteShaderBindingTableGeneratorAddRayGenerationProgram(shaderBindingTableGenerator.value, entryPoint.value, inputDatasCount.value, inputDatas.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorAddMissProgram redXRteShaderBindingTableGeneratorAddMissProgram
#define _755f9841_shaderBindingTableGenerator(value) value
#define _755f9841_entryPoint(value) value
#define _755f9841_inputDatasCount(value) value
#define _755f9841_inputDatas(value) value
#define _755f9841_optionalFile(value) value
#define _755f9841_optionalLine(value) value
#define _755f9841_optionalUserData(value) value
#define _755f9841_rteParameters(value) value
#else
typedef struct _s_755f9841_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_755f9841_shaderBindingTableGenerator;
typedef struct _s_755f9841_entryPoint { wchar_t* value; } _s_755f9841_entryPoint;
typedef struct _s_755f9841_inputDatasCount { uint64_t value; } _s_755f9841_inputDatasCount;
typedef struct _s_755f9841_inputDatas { void** value; } _s_755f9841_inputDatas;
typedef struct _s_755f9841_optionalFile { char* value; } _s_755f9841_optionalFile;
typedef struct _s_755f9841_optionalLine { int value; } _s_755f9841_optionalLine;
typedef struct _s_755f9841_optionalUserData { void* value; } _s_755f9841_optionalUserData;
typedef struct _s_755f9841_rteParameters { void* value; } _s_755f9841_rteParameters;
static inline _s_755f9841_shaderBindingTableGenerator _755f9841_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_755f9841_shaderBindingTableGenerator){value}; }
static inline _s_755f9841_entryPoint _755f9841_entryPoint(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_755f9841_entryPoint){value}; }
static inline _s_755f9841_inputDatasCount _755f9841_inputDatasCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_755f9841_inputDatasCount){value}; }
static inline _s_755f9841_inputDatas _755f9841_inputDatas(void** value) { return REDGPU_NP_STRUCT_INIT(_s_755f9841_inputDatas){value}; }
static inline _s_755f9841_optionalFile _755f9841_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_755f9841_optionalFile){value}; }
static inline _s_755f9841_optionalLine _755f9841_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_755f9841_optionalLine){value}; }
static inline _s_755f9841_optionalUserData _755f9841_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_755f9841_optionalUserData){value}; }
static inline _s_755f9841_rteParameters _755f9841_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_755f9841_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteShaderBindingTableGeneratorAddMissProgram(_s_755f9841_shaderBindingTableGenerator shaderBindingTableGenerator, _s_755f9841_entryPoint entryPoint, _s_755f9841_inputDatasCount inputDatasCount, _s_755f9841_inputDatas inputDatas, _s_755f9841_optionalFile optionalFile, _s_755f9841_optionalLine optionalLine, _s_755f9841_optionalUserData optionalUserData, _s_755f9841_rteParameters rteParameters) {
  redXRteShaderBindingTableGeneratorAddMissProgram(shaderBindingTableGenerator.value, entryPoint.value, inputDatasCount.value, inputDatas.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorAddHitGroup redXRteShaderBindingTableGeneratorAddHitGroup
#define _86416f08_shaderBindingTableGenerator(value) value
#define _86416f08_entryPoint(value) value
#define _86416f08_inputDatasCount(value) value
#define _86416f08_inputDatas(value) value
#define _86416f08_optionalFile(value) value
#define _86416f08_optionalLine(value) value
#define _86416f08_optionalUserData(value) value
#define _86416f08_rteParameters(value) value
#else
typedef struct _s_86416f08_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_86416f08_shaderBindingTableGenerator;
typedef struct _s_86416f08_entryPoint { wchar_t* value; } _s_86416f08_entryPoint;
typedef struct _s_86416f08_inputDatasCount { uint64_t value; } _s_86416f08_inputDatasCount;
typedef struct _s_86416f08_inputDatas { void** value; } _s_86416f08_inputDatas;
typedef struct _s_86416f08_optionalFile { char* value; } _s_86416f08_optionalFile;
typedef struct _s_86416f08_optionalLine { int value; } _s_86416f08_optionalLine;
typedef struct _s_86416f08_optionalUserData { void* value; } _s_86416f08_optionalUserData;
typedef struct _s_86416f08_rteParameters { void* value; } _s_86416f08_rteParameters;
static inline _s_86416f08_shaderBindingTableGenerator _86416f08_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_86416f08_shaderBindingTableGenerator){value}; }
static inline _s_86416f08_entryPoint _86416f08_entryPoint(wchar_t* value) { return REDGPU_NP_STRUCT_INIT(_s_86416f08_entryPoint){value}; }
static inline _s_86416f08_inputDatasCount _86416f08_inputDatasCount(uint64_t value) { return REDGPU_NP_STRUCT_INIT(_s_86416f08_inputDatasCount){value}; }
static inline _s_86416f08_inputDatas _86416f08_inputDatas(void** value) { return REDGPU_NP_STRUCT_INIT(_s_86416f08_inputDatas){value}; }
static inline _s_86416f08_optionalFile _86416f08_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_86416f08_optionalFile){value}; }
static inline _s_86416f08_optionalLine _86416f08_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_86416f08_optionalLine){value}; }
static inline _s_86416f08_optionalUserData _86416f08_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_86416f08_optionalUserData){value}; }
static inline _s_86416f08_rteParameters _86416f08_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_86416f08_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteShaderBindingTableGeneratorAddHitGroup(_s_86416f08_shaderBindingTableGenerator shaderBindingTableGenerator, _s_86416f08_entryPoint entryPoint, _s_86416f08_inputDatasCount inputDatasCount, _s_86416f08_inputDatas inputDatas, _s_86416f08_optionalFile optionalFile, _s_86416f08_optionalLine optionalLine, _s_86416f08_optionalUserData optionalUserData, _s_86416f08_rteParameters rteParameters) {
  redXRteShaderBindingTableGeneratorAddHitGroup(shaderBindingTableGenerator.value, entryPoint.value, inputDatasCount.value, inputDatas.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorComputeSBTSize redXRteShaderBindingTableGeneratorComputeSBTSize
#define _eeeff7be_shaderBindingTableGenerator(value) value
#define _eeeff7be_optionalFile(value) value
#define _eeeff7be_optionalLine(value) value
#define _eeeff7be_optionalUserData(value) value
#define _eeeff7be_rteParameters(value) value
#else
typedef struct _s_eeeff7be_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_eeeff7be_shaderBindingTableGenerator;
typedef struct _s_eeeff7be_optionalFile { char* value; } _s_eeeff7be_optionalFile;
typedef struct _s_eeeff7be_optionalLine { int value; } _s_eeeff7be_optionalLine;
typedef struct _s_eeeff7be_optionalUserData { void* value; } _s_eeeff7be_optionalUserData;
typedef struct _s_eeeff7be_rteParameters { void* value; } _s_eeeff7be_rteParameters;
static inline _s_eeeff7be_shaderBindingTableGenerator _eeeff7be_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_eeeff7be_shaderBindingTableGenerator){value}; }
static inline _s_eeeff7be_optionalFile _eeeff7be_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_eeeff7be_optionalFile){value}; }
static inline _s_eeeff7be_optionalLine _eeeff7be_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_eeeff7be_optionalLine){value}; }
static inline _s_eeeff7be_optionalUserData _eeeff7be_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_eeeff7be_optionalUserData){value}; }
static inline _s_eeeff7be_rteParameters _eeeff7be_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_eeeff7be_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorComputeSBTSize(_s_eeeff7be_shaderBindingTableGenerator shaderBindingTableGenerator, _s_eeeff7be_optionalFile optionalFile, _s_eeeff7be_optionalLine optionalLine, _s_eeeff7be_optionalUserData optionalUserData, _s_eeeff7be_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorComputeSBTSize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGenerate redXRteShaderBindingTableGeneratorGenerate
#define _b995b1c2_shaderBindingTableGenerator(value) value
#define _b995b1c2_sbtBuffer_ID3D12Resource(value) value
#define _b995b1c2_raytracingPipeline_ID3D12StateObjectProperties(value) value
#define _b995b1c2_optionalFile(value) value
#define _b995b1c2_optionalLine(value) value
#define _b995b1c2_optionalUserData(value) value
#define _b995b1c2_rteParameters(value) value
#else
typedef struct _s_b995b1c2_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_b995b1c2_shaderBindingTableGenerator;
typedef struct _s_b995b1c2_sbtBuffer_ID3D12Resource { void* value; } _s_b995b1c2_sbtBuffer_ID3D12Resource;
typedef struct _s_b995b1c2_raytracingPipeline_ID3D12StateObjectProperties { void* value; } _s_b995b1c2_raytracingPipeline_ID3D12StateObjectProperties;
typedef struct _s_b995b1c2_optionalFile { char* value; } _s_b995b1c2_optionalFile;
typedef struct _s_b995b1c2_optionalLine { int value; } _s_b995b1c2_optionalLine;
typedef struct _s_b995b1c2_optionalUserData { void* value; } _s_b995b1c2_optionalUserData;
typedef struct _s_b995b1c2_rteParameters { void* value; } _s_b995b1c2_rteParameters;
static inline _s_b995b1c2_shaderBindingTableGenerator _b995b1c2_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_b995b1c2_shaderBindingTableGenerator){value}; }
static inline _s_b995b1c2_sbtBuffer_ID3D12Resource _b995b1c2_sbtBuffer_ID3D12Resource(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b995b1c2_sbtBuffer_ID3D12Resource){value}; }
static inline _s_b995b1c2_raytracingPipeline_ID3D12StateObjectProperties _b995b1c2_raytracingPipeline_ID3D12StateObjectProperties(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b995b1c2_raytracingPipeline_ID3D12StateObjectProperties){value}; }
static inline _s_b995b1c2_optionalFile _b995b1c2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_b995b1c2_optionalFile){value}; }
static inline _s_b995b1c2_optionalLine _b995b1c2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_b995b1c2_optionalLine){value}; }
static inline _s_b995b1c2_optionalUserData _b995b1c2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b995b1c2_optionalUserData){value}; }
static inline _s_b995b1c2_rteParameters _b995b1c2_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_b995b1c2_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGenerate(_s_b995b1c2_shaderBindingTableGenerator shaderBindingTableGenerator, _s_b995b1c2_sbtBuffer_ID3D12Resource sbtBuffer_ID3D12Resource, _s_b995b1c2_raytracingPipeline_ID3D12StateObjectProperties raytracingPipeline_ID3D12StateObjectProperties, _s_b995b1c2_optionalFile optionalFile, _s_b995b1c2_optionalLine optionalLine, _s_b995b1c2_optionalUserData optionalUserData, _s_b995b1c2_rteParameters rteParameters) {
  redXRteShaderBindingTableGeneratorGenerate(shaderBindingTableGenerator.value, sbtBuffer_ID3D12Resource.value, raytracingPipeline_ID3D12StateObjectProperties.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorReset redXRteShaderBindingTableGeneratorReset
#define _61209612_shaderBindingTableGenerator(value) value
#define _61209612_optionalFile(value) value
#define _61209612_optionalLine(value) value
#define _61209612_optionalUserData(value) value
#define _61209612_rteParameters(value) value
#else
typedef struct _s_61209612_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_61209612_shaderBindingTableGenerator;
typedef struct _s_61209612_optionalFile { char* value; } _s_61209612_optionalFile;
typedef struct _s_61209612_optionalLine { int value; } _s_61209612_optionalLine;
typedef struct _s_61209612_optionalUserData { void* value; } _s_61209612_optionalUserData;
typedef struct _s_61209612_rteParameters { void* value; } _s_61209612_rteParameters;
static inline _s_61209612_shaderBindingTableGenerator _61209612_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_61209612_shaderBindingTableGenerator){value}; }
static inline _s_61209612_optionalFile _61209612_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_61209612_optionalFile){value}; }
static inline _s_61209612_optionalLine _61209612_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_61209612_optionalLine){value}; }
static inline _s_61209612_optionalUserData _61209612_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_61209612_optionalUserData){value}; }
static inline _s_61209612_rteParameters _61209612_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_61209612_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteShaderBindingTableGeneratorReset(_s_61209612_shaderBindingTableGenerator shaderBindingTableGenerator, _s_61209612_optionalFile optionalFile, _s_61209612_optionalLine optionalLine, _s_61209612_optionalUserData optionalUserData, _s_61209612_rteParameters rteParameters) {
  redXRteShaderBindingTableGeneratorReset(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGetRayGenSectionSize redXRteShaderBindingTableGeneratorGetRayGenSectionSize
#define _c53244b2_shaderBindingTableGenerator(value) value
#define _c53244b2_optionalFile(value) value
#define _c53244b2_optionalLine(value) value
#define _c53244b2_optionalUserData(value) value
#define _c53244b2_rteParameters(value) value
#else
typedef struct _s_c53244b2_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_c53244b2_shaderBindingTableGenerator;
typedef struct _s_c53244b2_optionalFile { char* value; } _s_c53244b2_optionalFile;
typedef struct _s_c53244b2_optionalLine { int value; } _s_c53244b2_optionalLine;
typedef struct _s_c53244b2_optionalUserData { void* value; } _s_c53244b2_optionalUserData;
typedef struct _s_c53244b2_rteParameters { void* value; } _s_c53244b2_rteParameters;
static inline _s_c53244b2_shaderBindingTableGenerator _c53244b2_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_c53244b2_shaderBindingTableGenerator){value}; }
static inline _s_c53244b2_optionalFile _c53244b2_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_c53244b2_optionalFile){value}; }
static inline _s_c53244b2_optionalLine _c53244b2_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_c53244b2_optionalLine){value}; }
static inline _s_c53244b2_optionalUserData _c53244b2_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c53244b2_optionalUserData){value}; }
static inline _s_c53244b2_rteParameters _c53244b2_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_c53244b2_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGetRayGenSectionSize(_s_c53244b2_shaderBindingTableGenerator shaderBindingTableGenerator, _s_c53244b2_optionalFile optionalFile, _s_c53244b2_optionalLine optionalLine, _s_c53244b2_optionalUserData optionalUserData, _s_c53244b2_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorGetRayGenSectionSize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGetRayGenEntrySize redXRteShaderBindingTableGeneratorGetRayGenEntrySize
#define _29110dfc_shaderBindingTableGenerator(value) value
#define _29110dfc_optionalFile(value) value
#define _29110dfc_optionalLine(value) value
#define _29110dfc_optionalUserData(value) value
#define _29110dfc_rteParameters(value) value
#else
typedef struct _s_29110dfc_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_29110dfc_shaderBindingTableGenerator;
typedef struct _s_29110dfc_optionalFile { char* value; } _s_29110dfc_optionalFile;
typedef struct _s_29110dfc_optionalLine { int value; } _s_29110dfc_optionalLine;
typedef struct _s_29110dfc_optionalUserData { void* value; } _s_29110dfc_optionalUserData;
typedef struct _s_29110dfc_rteParameters { void* value; } _s_29110dfc_rteParameters;
static inline _s_29110dfc_shaderBindingTableGenerator _29110dfc_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_29110dfc_shaderBindingTableGenerator){value}; }
static inline _s_29110dfc_optionalFile _29110dfc_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_29110dfc_optionalFile){value}; }
static inline _s_29110dfc_optionalLine _29110dfc_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_29110dfc_optionalLine){value}; }
static inline _s_29110dfc_optionalUserData _29110dfc_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_29110dfc_optionalUserData){value}; }
static inline _s_29110dfc_rteParameters _29110dfc_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_29110dfc_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGetRayGenEntrySize(_s_29110dfc_shaderBindingTableGenerator shaderBindingTableGenerator, _s_29110dfc_optionalFile optionalFile, _s_29110dfc_optionalLine optionalLine, _s_29110dfc_optionalUserData optionalUserData, _s_29110dfc_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorGetRayGenEntrySize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGetMissSectionSize redXRteShaderBindingTableGeneratorGetMissSectionSize
#define _6911ad31_shaderBindingTableGenerator(value) value
#define _6911ad31_optionalFile(value) value
#define _6911ad31_optionalLine(value) value
#define _6911ad31_optionalUserData(value) value
#define _6911ad31_rteParameters(value) value
#else
typedef struct _s_6911ad31_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_6911ad31_shaderBindingTableGenerator;
typedef struct _s_6911ad31_optionalFile { char* value; } _s_6911ad31_optionalFile;
typedef struct _s_6911ad31_optionalLine { int value; } _s_6911ad31_optionalLine;
typedef struct _s_6911ad31_optionalUserData { void* value; } _s_6911ad31_optionalUserData;
typedef struct _s_6911ad31_rteParameters { void* value; } _s_6911ad31_rteParameters;
static inline _s_6911ad31_shaderBindingTableGenerator _6911ad31_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_6911ad31_shaderBindingTableGenerator){value}; }
static inline _s_6911ad31_optionalFile _6911ad31_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_6911ad31_optionalFile){value}; }
static inline _s_6911ad31_optionalLine _6911ad31_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_6911ad31_optionalLine){value}; }
static inline _s_6911ad31_optionalUserData _6911ad31_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6911ad31_optionalUserData){value}; }
static inline _s_6911ad31_rteParameters _6911ad31_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_6911ad31_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGetMissSectionSize(_s_6911ad31_shaderBindingTableGenerator shaderBindingTableGenerator, _s_6911ad31_optionalFile optionalFile, _s_6911ad31_optionalLine optionalLine, _s_6911ad31_optionalUserData optionalUserData, _s_6911ad31_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorGetMissSectionSize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGetMissEntrySize redXRteShaderBindingTableGeneratorGetMissEntrySize
#define _f518b2a8_shaderBindingTableGenerator(value) value
#define _f518b2a8_optionalFile(value) value
#define _f518b2a8_optionalLine(value) value
#define _f518b2a8_optionalUserData(value) value
#define _f518b2a8_rteParameters(value) value
#else
typedef struct _s_f518b2a8_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_f518b2a8_shaderBindingTableGenerator;
typedef struct _s_f518b2a8_optionalFile { char* value; } _s_f518b2a8_optionalFile;
typedef struct _s_f518b2a8_optionalLine { int value; } _s_f518b2a8_optionalLine;
typedef struct _s_f518b2a8_optionalUserData { void* value; } _s_f518b2a8_optionalUserData;
typedef struct _s_f518b2a8_rteParameters { void* value; } _s_f518b2a8_rteParameters;
static inline _s_f518b2a8_shaderBindingTableGenerator _f518b2a8_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_f518b2a8_shaderBindingTableGenerator){value}; }
static inline _s_f518b2a8_optionalFile _f518b2a8_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_f518b2a8_optionalFile){value}; }
static inline _s_f518b2a8_optionalLine _f518b2a8_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_f518b2a8_optionalLine){value}; }
static inline _s_f518b2a8_optionalUserData _f518b2a8_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f518b2a8_optionalUserData){value}; }
static inline _s_f518b2a8_rteParameters _f518b2a8_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_f518b2a8_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGetMissEntrySize(_s_f518b2a8_shaderBindingTableGenerator shaderBindingTableGenerator, _s_f518b2a8_optionalFile optionalFile, _s_f518b2a8_optionalLine optionalLine, _s_f518b2a8_optionalUserData optionalUserData, _s_f518b2a8_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorGetMissEntrySize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGetHitGroupSectionSize redXRteShaderBindingTableGeneratorGetHitGroupSectionSize
#define _7eab25d4_shaderBindingTableGenerator(value) value
#define _7eab25d4_optionalFile(value) value
#define _7eab25d4_optionalLine(value) value
#define _7eab25d4_optionalUserData(value) value
#define _7eab25d4_rteParameters(value) value
#else
typedef struct _s_7eab25d4_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_7eab25d4_shaderBindingTableGenerator;
typedef struct _s_7eab25d4_optionalFile { char* value; } _s_7eab25d4_optionalFile;
typedef struct _s_7eab25d4_optionalLine { int value; } _s_7eab25d4_optionalLine;
typedef struct _s_7eab25d4_optionalUserData { void* value; } _s_7eab25d4_optionalUserData;
typedef struct _s_7eab25d4_rteParameters { void* value; } _s_7eab25d4_rteParameters;
static inline _s_7eab25d4_shaderBindingTableGenerator _7eab25d4_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_7eab25d4_shaderBindingTableGenerator){value}; }
static inline _s_7eab25d4_optionalFile _7eab25d4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_7eab25d4_optionalFile){value}; }
static inline _s_7eab25d4_optionalLine _7eab25d4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_7eab25d4_optionalLine){value}; }
static inline _s_7eab25d4_optionalUserData _7eab25d4_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7eab25d4_optionalUserData){value}; }
static inline _s_7eab25d4_rteParameters _7eab25d4_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_7eab25d4_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGetHitGroupSectionSize(_s_7eab25d4_shaderBindingTableGenerator shaderBindingTableGenerator, _s_7eab25d4_optionalFile optionalFile, _s_7eab25d4_optionalLine optionalLine, _s_7eab25d4_optionalUserData optionalUserData, _s_7eab25d4_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorGetHitGroupSectionSize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteShaderBindingTableGeneratorGetHitGroupEntrySize redXRteShaderBindingTableGeneratorGetHitGroupEntrySize
#define _fe6fb5b1_shaderBindingTableGenerator(value) value
#define _fe6fb5b1_optionalFile(value) value
#define _fe6fb5b1_optionalLine(value) value
#define _fe6fb5b1_optionalUserData(value) value
#define _fe6fb5b1_rteParameters(value) value
#else
typedef struct _s_fe6fb5b1_shaderBindingTableGenerator { RedXRteHandleShaderBindingTableGenerator value; } _s_fe6fb5b1_shaderBindingTableGenerator;
typedef struct _s_fe6fb5b1_optionalFile { char* value; } _s_fe6fb5b1_optionalFile;
typedef struct _s_fe6fb5b1_optionalLine { int value; } _s_fe6fb5b1_optionalLine;
typedef struct _s_fe6fb5b1_optionalUserData { void* value; } _s_fe6fb5b1_optionalUserData;
typedef struct _s_fe6fb5b1_rteParameters { void* value; } _s_fe6fb5b1_rteParameters;
static inline _s_fe6fb5b1_shaderBindingTableGenerator _fe6fb5b1_shaderBindingTableGenerator(RedXRteHandleShaderBindingTableGenerator value) { return REDGPU_NP_STRUCT_INIT(_s_fe6fb5b1_shaderBindingTableGenerator){value}; }
static inline _s_fe6fb5b1_optionalFile _fe6fb5b1_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_fe6fb5b1_optionalFile){value}; }
static inline _s_fe6fb5b1_optionalLine _fe6fb5b1_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_fe6fb5b1_optionalLine){value}; }
static inline _s_fe6fb5b1_optionalUserData _fe6fb5b1_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fe6fb5b1_optionalUserData){value}; }
static inline _s_fe6fb5b1_rteParameters _fe6fb5b1_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_fe6fb5b1_rteParameters){value}; }
REDGPU_NP_DECLSPEC unsigned REDGPU_NP_API np_redXRteShaderBindingTableGeneratorGetHitGroupEntrySize(_s_fe6fb5b1_shaderBindingTableGenerator shaderBindingTableGenerator, _s_fe6fb5b1_optionalFile optionalFile, _s_fe6fb5b1_optionalLine optionalLine, _s_fe6fb5b1_optionalUserData optionalUserData, _s_fe6fb5b1_rteParameters rteParameters) {
  return redXRteShaderBindingTableGeneratorGetHitGroupEntrySize(shaderBindingTableGenerator.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCallSetStateObject redXRteCallSetStateObject
#define _ed29a6a9_calls(value) value
#define _ed29a6a9_stateObject_ID3D12StateObject(value) value
#define _ed29a6a9_optionalFile(value) value
#define _ed29a6a9_optionalLine(value) value
#define _ed29a6a9_optionalUserData(value) value
#define _ed29a6a9_rteParameters(value) value
#else
typedef struct _s_ed29a6a9_calls { RedHandleCalls value; } _s_ed29a6a9_calls;
typedef struct _s_ed29a6a9_stateObject_ID3D12StateObject { void* value; } _s_ed29a6a9_stateObject_ID3D12StateObject;
typedef struct _s_ed29a6a9_optionalFile { char* value; } _s_ed29a6a9_optionalFile;
typedef struct _s_ed29a6a9_optionalLine { int value; } _s_ed29a6a9_optionalLine;
typedef struct _s_ed29a6a9_optionalUserData { void* value; } _s_ed29a6a9_optionalUserData;
typedef struct _s_ed29a6a9_rteParameters { void* value; } _s_ed29a6a9_rteParameters;
static inline _s_ed29a6a9_calls _ed29a6a9_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_ed29a6a9_calls){value}; }
static inline _s_ed29a6a9_stateObject_ID3D12StateObject _ed29a6a9_stateObject_ID3D12StateObject(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ed29a6a9_stateObject_ID3D12StateObject){value}; }
static inline _s_ed29a6a9_optionalFile _ed29a6a9_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_ed29a6a9_optionalFile){value}; }
static inline _s_ed29a6a9_optionalLine _ed29a6a9_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_ed29a6a9_optionalLine){value}; }
static inline _s_ed29a6a9_optionalUserData _ed29a6a9_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ed29a6a9_optionalUserData){value}; }
static inline _s_ed29a6a9_rteParameters _ed29a6a9_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_ed29a6a9_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCallSetStateObject(_s_ed29a6a9_calls calls, _s_ed29a6a9_stateObject_ID3D12StateObject stateObject_ID3D12StateObject, _s_ed29a6a9_optionalFile optionalFile, _s_ed29a6a9_optionalLine optionalLine, _s_ed29a6a9_optionalUserData optionalUserData, _s_ed29a6a9_rteParameters rteParameters) {
  redXRteCallSetStateObject(calls.value, stateObject_ID3D12StateObject.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

#ifdef REDGPU_DISABLE_NAMED_PARAMETERS
#define np_redXRteCallDispatchRays redXRteCallDispatchRays
#define _bb27dcf4_calls(value) value
#define _bb27dcf4_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC(value) value
#define _bb27dcf4_optionalFile(value) value
#define _bb27dcf4_optionalLine(value) value
#define _bb27dcf4_optionalUserData(value) value
#define _bb27dcf4_rteParameters(value) value
#else
typedef struct _s_bb27dcf4_calls { RedHandleCalls value; } _s_bb27dcf4_calls;
typedef struct _s_bb27dcf4_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC { void* value; } _s_bb27dcf4_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC;
typedef struct _s_bb27dcf4_optionalFile { char* value; } _s_bb27dcf4_optionalFile;
typedef struct _s_bb27dcf4_optionalLine { int value; } _s_bb27dcf4_optionalLine;
typedef struct _s_bb27dcf4_optionalUserData { void* value; } _s_bb27dcf4_optionalUserData;
typedef struct _s_bb27dcf4_rteParameters { void* value; } _s_bb27dcf4_rteParameters;
static inline _s_bb27dcf4_calls _bb27dcf4_calls(RedHandleCalls value) { return REDGPU_NP_STRUCT_INIT(_s_bb27dcf4_calls){value}; }
static inline _s_bb27dcf4_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC _bb27dcf4_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bb27dcf4_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC){value}; }
static inline _s_bb27dcf4_optionalFile _bb27dcf4_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_bb27dcf4_optionalFile){value}; }
static inline _s_bb27dcf4_optionalLine _bb27dcf4_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_bb27dcf4_optionalLine){value}; }
static inline _s_bb27dcf4_optionalUserData _bb27dcf4_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bb27dcf4_optionalUserData){value}; }
static inline _s_bb27dcf4_rteParameters _bb27dcf4_rteParameters(void* value) { return REDGPU_NP_STRUCT_INIT(_s_bb27dcf4_rteParameters){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redXRteCallDispatchRays(_s_bb27dcf4_calls calls, _s_bb27dcf4_dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC, _s_bb27dcf4_optionalFile optionalFile, _s_bb27dcf4_optionalLine optionalLine, _s_bb27dcf4_optionalUserData optionalUserData, _s_bb27dcf4_rteParameters rteParameters) {
  redXRteCallDispatchRays(calls.value, dispatchRaysDescription_D3D12_DISPATCH_RAYS_DESC.value, optionalFile.value, optionalLine.value, optionalUserData.value, rteParameters.value);
}
#endif

