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
#define _3e8464a5_context(value) value
#define _3e8464a5_gpu(value) value
#define _3e8464a5_handleName(value) value
#define _3e8464a5_procedureCache(value) value
#define _3e8464a5_procedureParameters(value) value
#define _3e8464a5_gpuCodeMainProcedureName(value) value
#define _3e8464a5_gpuCode(value) value
#define _3e8464a5_stateExtension(value) value
#define _3e8464a5_outProcedure(value) value
#define _3e8464a5_outStatuses(value) value
#define _3e8464a5_optionalFile(value) value
#define _3e8464a5_optionalLine(value) value
#define _3e8464a5_optionalUserData(value) value
#else
typedef struct _s_3e8464a5_context { RedContext value; } _s_3e8464a5_context;
typedef struct _s_3e8464a5_gpu { RedHandleGpu value; } _s_3e8464a5_gpu;
typedef struct _s_3e8464a5_handleName { char* value; } _s_3e8464a5_handleName;
typedef struct _s_3e8464a5_procedureCache { RedHandleProcedureCache value; } _s_3e8464a5_procedureCache;
typedef struct _s_3e8464a5_procedureParameters { RedHandleProcedureParameters value; } _s_3e8464a5_procedureParameters;
typedef struct _s_3e8464a5_gpuCodeMainProcedureName { char* value; } _s_3e8464a5_gpuCodeMainProcedureName;
typedef struct _s_3e8464a5_gpuCode { RedHandleGpuCode value; } _s_3e8464a5_gpuCode;
typedef struct _s_3e8464a5_stateExtension { void* value; } _s_3e8464a5_stateExtension;
typedef struct _s_3e8464a5_outProcedure { RedHandleProcedure* value; } _s_3e8464a5_outProcedure;
typedef struct _s_3e8464a5_outStatuses { RedStatuses* value; } _s_3e8464a5_outStatuses;
typedef struct _s_3e8464a5_optionalFile { char* value; } _s_3e8464a5_optionalFile;
typedef struct _s_3e8464a5_optionalLine { int value; } _s_3e8464a5_optionalLine;
typedef struct _s_3e8464a5_optionalUserData { void* value; } _s_3e8464a5_optionalUserData;
static inline _s_3e8464a5_context _3e8464a5_context(RedContext value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_context){value}; }
static inline _s_3e8464a5_gpu _3e8464a5_gpu(RedHandleGpu value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_gpu){value}; }
static inline _s_3e8464a5_handleName _3e8464a5_handleName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_handleName){value}; }
static inline _s_3e8464a5_procedureCache _3e8464a5_procedureCache(RedHandleProcedureCache value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_procedureCache){value}; }
static inline _s_3e8464a5_procedureParameters _3e8464a5_procedureParameters(RedHandleProcedureParameters value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_procedureParameters){value}; }
static inline _s_3e8464a5_gpuCodeMainProcedureName _3e8464a5_gpuCodeMainProcedureName(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_gpuCodeMainProcedureName){value}; }
static inline _s_3e8464a5_gpuCode _3e8464a5_gpuCode(RedHandleGpuCode value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_gpuCode){value}; }
static inline _s_3e8464a5_stateExtension _3e8464a5_stateExtension(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_stateExtension){value}; }
static inline _s_3e8464a5_outProcedure _3e8464a5_outProcedure(RedHandleProcedure* value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_outProcedure){value}; }
static inline _s_3e8464a5_outStatuses _3e8464a5_outStatuses(RedStatuses* value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_outStatuses){value}; }
static inline _s_3e8464a5_optionalFile _3e8464a5_optionalFile(char* value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_optionalFile){value}; }
static inline _s_3e8464a5_optionalLine _3e8464a5_optionalLine(int value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_optionalLine){value}; }
static inline _s_3e8464a5_optionalUserData _3e8464a5_optionalUserData(void* value) { return REDGPU_NP_STRUCT_INIT(_s_3e8464a5_optionalUserData){value}; }
REDGPU_NP_DECLSPEC void REDGPU_NP_API np_redCreateProcedureComputingLanguage(_s_3e8464a5_context context, _s_3e8464a5_gpu gpu, _s_3e8464a5_handleName handleName, _s_3e8464a5_procedureCache procedureCache, _s_3e8464a5_procedureParameters procedureParameters, _s_3e8464a5_gpuCodeMainProcedureName gpuCodeMainProcedureName, _s_3e8464a5_gpuCode gpuCode, _s_3e8464a5_stateExtension stateExtension, _s_3e8464a5_outProcedure outProcedure, _s_3e8464a5_outStatuses outStatuses, _s_3e8464a5_optionalFile optionalFile, _s_3e8464a5_optionalLine optionalLine, _s_3e8464a5_optionalUserData optionalUserData) {
  redCreateProcedureComputingLanguage(context.value, gpu.value, handleName.value, procedureCache.value, procedureParameters.value, gpuCodeMainProcedureName.value, gpuCode.value, stateExtension.value, outProcedure.value, outStatuses.value, optionalFile.value, optionalLine.value, optionalUserData.value);
}
#endif

