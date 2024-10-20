#include <vector>
#include <string>
#include <fstream>
#include <sstream>

int main() {
  const int maxParametersCount = 50;

  printf("#pragma once\n");
  printf("\n");
  printf("#include <stdio.h>\n");
  printf("\n");
  printf("#define NP_STRING(a) #a\n");
  printf("#define NP_STRINGIFY(a) NP_STRING(a)\n");
  printf("\n");
  printf("#define np0(ProcedureName) ProcedureName()\n");
  printf("\n");

  for (int i = 0; i < maxParametersCount; i += 1) {

    printf("#define np%d(ProcedureName, \\\n", i + 1);

    for (int j = 0; j < (i + 1); j += 1) {
      printf("  p%d_PassedName, p%d", j + 1, j + 1);
      if (j != i) {
        printf(",");
      }
      printf(" \\\n");
    }

    printf(") \\\n");
    printf("  ProcedureName(");
    for (int j = 0; j < (i + 1); j += 1) {
      if (j != 0) printf(", ");
      printf("p%d", j + 1);
    }
    printf("); \\\n");

    for (int j = 0; j < (i + 1); j += 1) {
      printf("  static_assert(p%d_PassedName == NP_STRINGIFY(_np%d_##ProcedureName), \"Expected parameter name: \" #ProcedureName \"(\" NP_STRINGIFY(_np%d_##ProcedureName) \": ...), got: \" #ProcedureName \"(\" p%d_PassedName \": ...)\")", j + 1, j + 1, j + 1, j + 1);
      if (j != i) {
        printf("; \\");
      }
      printf("\n");
    }

    printf("\n");
  }
}
