#if 0
clang -c C:/RedGpuSDK/redgpu.c
clang -c C:/RedGpuSDK/redgpu_2.c
clang -c C:/RedGpuSDK/redgpu_32.c
clang main.c redgpu.o redgpu_2.o redgpu_32.o
#endif

#ifndef __cplusplus
#define REDGPU_DISABLE_NAMED_PARAMETERS
#endif

#include "C:/RedGpuSDK/redgpu_2.h"
#include "C:/RedGpuSDK/redgpu_32.h"

#include "C:/RedGpuSDK/misc/np/np.h"
#include "C:/RedGpuSDK/misc/np/np_redgpu.h"
#include "C:/RedGpuSDK/misc/np/np_redgpu_2.h"

void red2Crash(const char * error, const char * functionName, RedHandleGpu optionalGpuHandle, const char * optionalFile, int optionalLine) {
  char * optionalLineStr = (char *)red32MemoryCalloc(4096);

  char * out = (char *)red32MemoryCalloc(32768);
  ((uint64_t *)(void *)out)[0] = red32MirrorBytesOfUint64(32768);

  red32IntToChars(optionalLine, optionalLineStr);

  red32StringJoin(out, "[REDGPU 2][Crash][");
  red32StringJoin(out, optionalFile);
  red32StringJoin(out, ":");
  red32StringJoin(out, optionalLineStr);
  red32StringJoin(out, "][");
  red32StringJoin(out, functionName);
  red32StringJoin(out, "] ");
  red32StringJoin(out, error);
  red32StringJoin(out, "\n");

  red32ConsolePrintError(out);

  red32MemoryFree(optionalLineStr);
  red32MemoryFree(out);

  red32Exit(1);
}

int main() {
  RedContext redcontext = NULL;
  np18(redCreateContext,
    "malloc", red32MemoryCalloc,
    "free", red32MemoryFree,
    "optionalMallocTagged", NULL,
    "optionalFreeTagged", NULL,
    "debugCallback", NULL,
    "sdkVersion", RED_SDK_VERSION_1_0_135,
    "sdkExtensionsCount", 0,
    "sdkExtensions", NULL,
    "optionalProgramName", NULL,
    "optionalProgramVersion", 0,
    "optionalEngineName", NULL,
    "optionalEngineVersion", 0,
    "optionalSettings", NULL,
    "outContext", &redcontext,
    "outStatuses", NULL,
    "optionalFile", __FILE__,
    "optionalLine", __LINE__,
    "optionalUserData", NULL
  );

  REDGPU_2_EXPECTFL(redcontext != NULL);
  REDGPU_2_EXPECTFL(redcontext->gpusCount > 0);

  np3(red2ExpectMinimumGuarantees,
    "gpuInfo", &redcontext->gpus[0],
    "optionalFile", __FILE__,
    "optionalLine", __LINE__
  );
  np3(red2ExpectAllMemoryToBeCoherent,
    "gpuInfo", &redcontext->gpus[0],
    "optionalFile", __FILE__,
    "optionalLine", __LINE__
  );

  red32ConsolePrint("Success: redcontext is created successfully and REDGPU 2 minimum guarantees checks are passed.\n");
}
