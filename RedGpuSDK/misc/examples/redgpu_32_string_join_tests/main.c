#include "C:/RedGpuSDK/redgpu_2.h"
#include "C:/RedGpuSDK/redgpu_32.h"

#include <stdlib.h> // For exit
#include <stdio.h>  // For printf

void red2Crash(const char * error, const char * functionName, RedHandleGpu optionalGpuHandle, const char * optionalFile, int optionalLine) {
  printf("[REDGPU 2][Crash][%s:%d][%s] %s\n", optionalFile, optionalLine, functionName, error);
  exit(1);
}

int main() {
  {
    #define STRING_SIZE 13

    char * str = (char *)red32MemoryCalloc(STRING_SIZE);
    ((uint64_t *)(void *)str)[0] = red32MirrorBytesOfUint64(STRING_SIZE);

    REDGPU_2_EXPECTFL( 0 == red32MirrorStringJoin(str, "Hi") );

    REDGPU_2_EXPECTFL( str[0] == 'H' );
    REDGPU_2_EXPECTFL( str[1] == 'i' );
    REDGPU_2_EXPECTFL( str[2] == 0   );
    REDGPU_2_EXPECTFL( ((uint64_t *)(void *)&str[2])[0] == red32MirrorBytesOfUint64(STRING_SIZE) );

    REDGPU_2_EXPECTFL( 0 == red32MirrorStringJoin(str, "!!!") );

    REDGPU_2_EXPECTFL( str[0] == 'H' );
    REDGPU_2_EXPECTFL( str[1] == 'i' );
    REDGPU_2_EXPECTFL( str[2] == '!' );
    REDGPU_2_EXPECTFL( str[3] == '!' );
    REDGPU_2_EXPECTFL( str[4] == '!' );
    REDGPU_2_EXPECTFL( str[5] == 0   );
    REDGPU_2_EXPECTFL( ((uint64_t *)(void *)&str[5])[0] == red32MirrorBytesOfUint64(STRING_SIZE) );

    red32MemoryFree(str);
    #undef STRING_SIZE
  }

  {
    char * str = (char *)red32MemoryCalloc(8);
    ((uint64_t *)(void *)str)[0] = red32MirrorBytesOfUint64(8);

    REDGPU_2_EXPECTFL(  0 == red32MirrorStringJoin(str, "")  );

    REDGPU_2_EXPECTFL( -2 == red32MirrorStringJoin(str, "!") );
  }

  printf("All tests are passed successfully.\n");
}
