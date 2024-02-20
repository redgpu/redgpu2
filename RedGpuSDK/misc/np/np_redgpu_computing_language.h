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
#define np_redCreateProcedureComputingLanguage redCreateProcedureComputingLanguage
#define _18810c15_context(value) value
#define _18810c15_gpu(value) value
#define _18810c15_handleName(value) value
#define _18810c15_procedureCache(value) value
#define _18810c15_procedureParameters(value) value
#define _18810c15_gpuCodeMainProcedureName(value) value
#define _18810c15_gpuCode(value) value
#define _18810c15_stateExtension(value) value
#define _18810c15_outProcedure(value) value
#define _18810c15_outStatuses(value) value
#define _18810c15_optionalFile(value) value
#define _18810c15_optionalLine(value) value
#define _18810c15_optionalUserData(value) value
#else
typedef struct _s_18810c15_context { RedContext value; } _s_18810c15_context;
typedef struct _s_18810c15_gpu { RedHandleGpu value; } _s_18810c15_gpu;
typedef struct _s_18810c15_handleName { char* value; } _s_18810c15_handleName;
typedef struct _s_18810c15_procedureCache { RedHandleProcedureCache value; } _s_18810c15_procedureCache;
typedef struct _s_18810c15_procedureParameters { RedHandleProcedureParameters value; } _s_18810c15_procedureParameters;
typedef struct _s_18810c15_gpuCodeMainProcedureName { char* value; } _s_18810c15_gpuCodeMainProcedureName;
typedef struct _s_18810c15_gpuCode { RedHandleGpuCode value; } _s_18810c15_gpuCode;
typedef struct _s_18810c15_stateExtension { void* value; } _s_18810c15_stateExtension;
typedef struct _s_18810c15_outProcedure { RedHandleProcedure* value; } _s_18810c15_outProcedure;
typedef struct _s_18810c15_outStatuses { RedStatuses* value; } _s_18810c15_outStatuses;
typedef struct _s_18810c15_optionalFile { char* value; } _s_18810c15_optionalFile;
typedef struct _s_18810c15_optionalLine { int value; } _s_18810c15_optionalLine;
typedef struct _s_18810c15_optionalUserData { void* value; } _s_18810c15_optionalUserData;
static inline _s_18810c15_context _18810c15_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_context){value}; }
static inline _s_18810c15_gpu _18810c15_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_gpu){value}; }
static inline _s_18810c15_handleName _18810c15_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_handleName){value}; }
static inline _s_18810c15_procedureCache _18810c15_procedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_procedureCache){value}; }
static inline _s_18810c15_procedureParameters _18810c15_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_procedureParameters){value}; }
static inline _s_18810c15_gpuCodeMainProcedureName _18810c15_gpuCodeMainProcedureName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_gpuCodeMainProcedureName){value}; }
static inline _s_18810c15_gpuCode _18810c15_gpuCode(RedHandleGpuCode value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_gpuCode){value}; }
static inline _s_18810c15_stateExtension _18810c15_stateExtension(void* value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_stateExtension){value}; }
static inline _s_18810c15_outProcedure _18810c15_outProcedure(RedHandleProcedure* value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_outProcedure){value}; }
static inline _s_18810c15_outStatuses _18810c15_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_outStatuses){value}; }
static inline _s_18810c15_optionalFile _18810c15_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_optionalFile){value}; }
static inline _s_18810c15_optionalLine _18810c15_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_optionalLine){value}; }
static inline _s_18810c15_optionalUserData _18810c15_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_18810c15_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateProcedureComputingLanguage(_s_18810c15_context context, _s_18810c15_gpu gpu, _s_18810c15_handleName handleName, _s_18810c15_procedureCache procedureCache, _s_18810c15_procedureParameters procedureParameters, _s_18810c15_gpuCodeMainProcedureName gpuCodeMainProcedureName, _s_18810c15_gpuCode gpuCode, _s_18810c15_stateExtension stateExtension, _s_18810c15_outProcedure outProcedure, _s_18810c15_outStatuses outStatuses, _s_18810c15_optionalFile optionalFile, _s_18810c15_optionalLine optionalLine, _s_18810c15_optionalUserData optionalUserData) {
  redCreateProcedureComputingLanguage(context.value, gpu.value, handleName.value, procedureCache.value, procedureParameters.value, gpuCodeMainProcedureName.value, gpuCode.value, stateExtension.value, outProcedure.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

