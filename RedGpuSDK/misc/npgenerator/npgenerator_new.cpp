#include <vector>
#include <string>
#include <fstream>
#include <sstream>

int main() {
  // NOTE(Constantine):
  //
  // The rules:
  // * No const's.
  // * Pointer chars * should be sticked to the left, to the name of their parameter type.
  //
  // The format is:
  // FunctionReturnType
  // <space>
  // FunctionName
  // (
  // ParameterType until <space>
  // <space>
  // ParameterName until ,
  // ,
  // repeat the 4 rules above until )
  // )

  srand(time(0));

  std::string s_Declspec = "REDGPU_NP_DECLSPEC";
  std::string s_Api      = "REDGPU_NP_API";

  std::string line;
  std::ifstream file("functions.txt");
  if (file.is_open() == false) {
    printf("Error: can't open functions.txt file.\n");
  } else {
     printf("#pragma once\n");
     printf("\n");
     printf("#ifndef REDGPU_NP_DECLSPEC\n");
     printf("#define REDGPU_NP_DECLSPEC\n");
     printf("#endif\n");
     printf("\n");
     printf("#ifndef REDGPU_NP_API\n");
     printf("#define REDGPU_NP_API\n");
     printf("#endif\n");
     printf("\n");
     printf("#ifndef REDGPU_NP_STRUCT_INIT\n");
     printf("#ifdef __cplusplus\n");
     printf("#define REDGPU_NP_STRUCT_INIT(x) x\n");
     printf("#else\n");
     printf("#define REDGPU_NP_STRUCT_INIT(x) (x)\n");
     printf("#endif\n");
     printf("#endif\n");
     printf("\n");
     while (getline(file, line)) {

      std::string string = line;

      std::vector<std::string> tokens;
      std::string              s_FunctionReturnType;
      std::string              s_FunctionName;
      std::vector<std::string> s_ParameterTypes;
      std::vector<std::string> s_ParameterNames;

      std::string s = string;
      std::stringstream ss(s);
      std::string tmp;
      while (getline(ss, tmp, ' ')) {
        std::stringstream sss(tmp);
        while(getline(sss, tmp, '(')) {
          std::stringstream ssss(tmp);
          while(getline(ssss, tmp, ',')) {
            std::stringstream sssss(tmp);
            while(getline(sssss, tmp, ')')) {
              tokens.push_back(tmp);
            }
          }
        }
      }

      s_FunctionReturnType = tokens[0];
      s_FunctionName       = tokens[1];

      tokens.erase(tokens.begin() + 0); // Pop FunctionReturnType
      tokens.erase(tokens.begin() + 0); // Pop FunctionName

      for (size_t i = 0, count = tokens.size(); i < count; i += 2) {
        s_ParameterTypes.push_back(tokens[i + 0]);
        s_ParameterNames.push_back(tokens[i + 1]);
      }

      // Generate 8 random hex chars
      char randomHex[9];
      randomHex[8] = 0;
      for(int i = 0; i < 8; i += 1) {
        sprintf(randomHex + i, "%x", rand() % 16);
      }

      printf("#ifdef REDGPU_DISABLE_NAMED_PARAMETERS\n");
      printf("#define np_%s %s\n", s_FunctionName.c_str(), s_FunctionName.c_str());
      for (size_t i = 0, count = s_ParameterNames.size(); i < count; i += 1) {
        printf("#define _%s_%s(value) value\n", randomHex, s_ParameterNames[i].c_str());
      }
      printf("#else\n");
      for (size_t i = 0, count = s_ParameterNames.size(); i < count; i += 1) {
        printf("typedef struct _s_%s_%s { %s value; } _s_%s_%s;\n", randomHex, s_ParameterNames[i].c_str(), s_ParameterTypes[i].c_str(), randomHex, s_ParameterNames[i].c_str());
      }
      for (size_t i = 0, count = s_ParameterNames.size(); i < count; i += 1) {
        printf("static inline _s_%s_%s _%s_%s(%s value) { return REDGPU_NP_STRUCT_INIT(_s_%s_%s){value}; }\n", randomHex, s_ParameterNames[i].c_str(), randomHex, s_ParameterNames[i].c_str(), s_ParameterTypes[i].c_str(), randomHex, s_ParameterNames[i].c_str());
      }
      printf("%s %s %s np_%s(", s_Declspec.c_str(), s_FunctionReturnType.c_str(), s_Api.c_str(), s_FunctionName.c_str());
      for (size_t i = 0, count = s_ParameterNames.size(); i < count; i += 1) {
        if (i > 0) {
          printf(", ");
        }
        printf("_s_%s_%s %s", randomHex, s_ParameterNames[i].c_str(), s_ParameterNames[i].c_str());
      }
      printf(") {\n");
      printf("  %s%s(", s_FunctionReturnType == "void" ? "" : "return ", s_FunctionName.c_str());
      for (size_t i = 0, count = s_ParameterNames.size(); i < count; i += 1) {
        if (i > 0) {
          printf(", ");
        }
        printf("%s.value", s_ParameterNames[i].c_str());
      }
      printf(");\n");
      printf("}\n");
      printf("#endif\n");
      printf("\n");

    }
  }
}
