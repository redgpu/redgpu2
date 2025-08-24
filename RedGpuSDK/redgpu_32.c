#define STB_SPRINTF_IMPLEMENTATION
#include "redgpu_stb_sprintf.h"

#include <stddef.h>  // For size_t
#include <stdint.h>  // For uint64_t
#include <Windows.h>

#if 0
extern HANDLE CreateFile2              (LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, DWORD dwCreationDisposition, LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams);
extern HANDLE CreateFileMappingFromApp (HANDLE hFile, PSECURITY_ATTRIBUTES SecurityAttributes, ULONG PageProtection, ULONG64 MaximumSize, PCWSTR Name);
extern PVOID  MapViewOfFileFromApp     (HANDLE hFileMappingObject, ULONG DesiredAccess, ULONG64 FileOffset, SIZE_T NumberOfBytesToMap);
#endif

extern __declspec(dllexport) void * red32MemoryCalloc(size_t bytesCount) {
  return calloc(1, bytesCount);
}

extern __declspec(dllexport) void red32MemoryFree(void * pointer) {
  free(pointer);
}

extern __declspec(dllexport) void * red32GetModuleHandle(const char * moduleName) {
  return GetModuleHandleA(moduleName);
}

extern __declspec(dllexport) void * red32WindowCreate(const char * title) {
  WNDCLASSEXA wndClassEx = {0};
  wndClassEx.cbSize        = sizeof(wndClassEx);
  wndClassEx.lpfnWndProc   = DefWindowProcA;
  wndClassEx.lpszClassName = title;
  RegisterClassExA(&wndClassEx);
  HWND window = CreateWindowExA(0, title, title, WS_POPUP | WS_MAXIMIZE | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, 0, 0);
  return (void *)window;
}

extern __declspec(dllexport) int red32WindowDestroy(void * windowHandle) {
  int out = 0;
  if (windowHandle != NULL) {
    int destroyWindowSuccess = DestroyWindow((HWND)windowHandle);
    if (destroyWindowSuccess == 0) { // "If the function fails, the return value is zero." https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-destroywindow
      out = -1;
    }
  }
  return out;
}

extern __declspec(dllexport) int red32WindowLoop() {
  int loop = 1;
  MSG msg = {0};
  while (PeekMessageA(&msg, 0, 0, 0, PM_REMOVE)) {
    if (msg.message == WM_QUIT || msg.message == WM_CLOSE || msg.message == WM_DESTROY || msg.message == WM_SYSCOMMAND) {
      loop = 0;
    }
    TranslateMessage(&msg);
    DispatchMessageA(&msg);
  }
  return loop;
}

extern __declspec(dllexport) void red32ConsolePrint(const char * string) {
  DWORD _;
  WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), string, strlen(string), &_, 0);
}

extern __declspec(dllexport) void red32ConsolePrintError(const char * string) {
  DWORD _;
  WriteConsoleA(GetStdHandle(STD_ERROR_HANDLE), string, strlen(string), &_, 0);
}

extern __declspec(dllexport) int red32FileMap(const unsigned short * filepath, void ** outFileDescriptorHandle, void ** outFileMappingHandle, size_t * outFileDataBytesCount, void ** outFileDataPointer) {
  HANDLE fd = CreateFile2((LPCWSTR)filepath, FILE_READ_DATA, FILE_SHARE_READ | FILE_SHARE_WRITE, OPEN_EXISTING, 0);
  if (fd == INVALID_HANDLE_VALUE) {
    return -1;
  }
  if (outFileDescriptorHandle != NULL) {
    outFileDescriptorHandle[0] = fd;
  }
  size_t fsize = 0;
  GetFileSizeEx(fd, (PLARGE_INTEGER)&fsize);
  if (outFileDataBytesCount != NULL) {
    outFileDataBytesCount[0] = fsize;
  }
  HANDLE fm = CreateFileMappingFromApp(fd, 0, PAGE_READONLY, fsize, 0);
  if (fm == INVALID_HANDLE_VALUE) {
    return -2;
  }
  if (outFileMappingHandle != NULL) {
    outFileMappingHandle[0] = fm;
  }
  void * fdata = MapViewOfFileFromApp(fm, FILE_MAP_READ, 0, 0);
  if (outFileDataPointer != NULL) {
    outFileDataPointer[0] = fdata;
  }
  return 0;
}

extern __declspec(dllexport) int red32FileUnmap(void * fileDescriptorHandle, void * fileMappingHandle) {
  int out = 0;
  if (fileDescriptorHandle != INVALID_HANDLE_VALUE) {
    int closeHandleSuccess = CloseHandle(fileDescriptorHandle);
    if (closeHandleSuccess == 0) {     // "If the function fails, the return value is zero." https://docs.microsoft.com/en-us/windows/win32/api/handleapi/nf-handleapi-closehandle
      out = -1;
    }
  }
  if (fileMappingHandle != INVALID_HANDLE_VALUE) {
    int unmapViewOfFileSuccess = UnmapViewOfFile(fileMappingHandle);
    if (unmapViewOfFileSuccess == 0) { // "If the function fails, the return value is zero." https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffile
      out = -2;
    }
  }
  return out;
}

extern __declspec(dllexport) void red32OutputDebugString(const char * string) {
  OutputDebugStringA(string);
}

extern __declspec(dllexport) void red32StringJoin(char * joinTo, const char * joinFrom) {
  if (joinFrom == NULL) { return; }

  size_t start = 0;
  for (size_t i = 0; ; i += 1) {
    char c = joinTo[i];
    if (c == 0) {
      start = i;
      break;
    }
  }
  for (size_t i = 0; ; i += 1) {
    char c = joinFrom[i];
    joinTo[start + i] = c;
    if (c == 0) {
      break;
    }
  }
}

extern __declspec(dllexport) void red32Exit(int exitCode) {
  exit(exitCode);
}

extern __declspec(dllexport) int red32IntToChars(int value, char * outChars) {
  int size = stbsp_snprintf(0, 0, "%d", value);
  if (outChars != 0) {
    stbsp_snprintf(outChars, size + 1, "%d", value);
  }
  return size + 1;
}

extern __declspec(dllexport) int red32UnsignedToChars(unsigned value, char * outChars) {
  int size = stbsp_snprintf(0, 0, "%u", value);
  if (outChars != 0) {
    stbsp_snprintf(outChars, size + 1, "%u", value);
  }
  return size + 1;
}

extern __declspec(dllexport) int red32Int64ToChars(int64_t value, char * outChars) {
  int size = stbsp_snprintf(0, 0, "%lld", value);
  if (outChars != 0) {
    stbsp_snprintf(outChars, size + 1, "%lld", value);
  }
  return size + 1;
}

extern __declspec(dllexport) int red32Uint64ToChars(uint64_t value, char * outChars) {
  int size = stbsp_snprintf(0, 0, "%llu", value);
  if (outChars != 0) {
    stbsp_snprintf(outChars, size + 1, "%llu", value);
  }
  return size + 1;
}

extern __declspec(dllexport) int red32FloatToChars(float value, char * outChars) {
  int size = stbsp_snprintf(0, 0, "%.9g", value);
  if (outChars != 0) {
    stbsp_snprintf(outChars, size + 1, "%.9g", value);
  }
  return size + 1;
}

extern __declspec(dllexport) int red32DoubleToChars(double value, char * outChars) {
  int size = stbsp_snprintf(0, 0, "%.17g", value);
  if (outChars != 0) {
    stbsp_snprintf(outChars, size + 1, "%.17g", value);
  }
  return size + 1;
}

extern __declspec(dllexport) void red32BinaryUint8ToCharsNoNullTerm(uint8_t value, char * outCharsNoNullTerm) {
  uint8_t b = value;
  outCharsNoNullTerm[0]  = (b & 0b10000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[1]  = (b & 0b01000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[2]  = (b & 0b00100000) == 0 ? '0' : '1';
  outCharsNoNullTerm[3]  = (b & 0b00010000) == 0 ? '0' : '1';
  outCharsNoNullTerm[4]  = (b & 0b00001000) == 0 ? '0' : '1';
  outCharsNoNullTerm[5]  = (b & 0b00000100) == 0 ? '0' : '1';
  outCharsNoNullTerm[6]  = (b & 0b00000010) == 0 ? '0' : '1';
  outCharsNoNullTerm[7]  = (b & 0b00000001) == 0 ? '0' : '1';
}

extern __declspec(dllexport) void red32BinaryUnsignedToCharsNoNullTerm(unsigned value, char * outCharsNoNullTerm) {
  unsigned b = value;
  outCharsNoNullTerm[0]  = (b & 0b10000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[1]  = (b & 0b01000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[2]  = (b & 0b00100000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[3]  = (b & 0b00010000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[4]  = (b & 0b00001000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[5]  = (b & 0b00000100000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[6]  = (b & 0b00000010000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[7]  = (b & 0b00000001000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[8]  = (b & 0b00000000100000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[9]  = (b & 0b00000000010000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[10] = (b & 0b00000000001000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[11] = (b & 0b00000000000100000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[12] = (b & 0b00000000000010000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[13] = (b & 0b00000000000001000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[14] = (b & 0b00000000000000100000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[15] = (b & 0b00000000000000010000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[16] = (b & 0b00000000000000001000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[17] = (b & 0b00000000000000000100000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[18] = (b & 0b00000000000000000010000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[19] = (b & 0b00000000000000000001000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[20] = (b & 0b00000000000000000000100000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[21] = (b & 0b00000000000000000000010000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[22] = (b & 0b00000000000000000000001000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[23] = (b & 0b00000000000000000000000100000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[24] = (b & 0b00000000000000000000000010000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[25] = (b & 0b00000000000000000000000001000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[26] = (b & 0b00000000000000000000000000100000) == 0 ? '0' : '1';
  outCharsNoNullTerm[27] = (b & 0b00000000000000000000000000010000) == 0 ? '0' : '1';
  outCharsNoNullTerm[28] = (b & 0b00000000000000000000000000001000) == 0 ? '0' : '1';
  outCharsNoNullTerm[29] = (b & 0b00000000000000000000000000000100) == 0 ? '0' : '1';
  outCharsNoNullTerm[30] = (b & 0b00000000000000000000000000000010) == 0 ? '0' : '1';
  outCharsNoNullTerm[31] = (b & 0b00000000000000000000000000000001) == 0 ? '0' : '1';
}

extern __declspec(dllexport) void red32BinaryUint64ToCharsNoNullTerm(uint64_t value, char * outCharsNoNullTerm) {
  uint64_t b = value;
  outCharsNoNullTerm[0]  = (b & 0b1000000000000000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[1]  = (b & 0b0100000000000000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[2]  = (b & 0b0010000000000000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[3]  = (b & 0b0001000000000000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[4]  = (b & 0b0000100000000000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[5]  = (b & 0b0000010000000000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[6]  = (b & 0b0000001000000000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[7]  = (b & 0b0000000100000000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[8]  = (b & 0b0000000010000000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[9]  = (b & 0b0000000001000000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[10] = (b & 0b0000000000100000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[11] = (b & 0b0000000000010000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[12] = (b & 0b0000000000001000000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[13] = (b & 0b0000000000000100000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[14] = (b & 0b0000000000000010000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[15] = (b & 0b0000000000000001000000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[16] = (b & 0b0000000000000000100000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[17] = (b & 0b0000000000000000010000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[18] = (b & 0b0000000000000000001000000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[19] = (b & 0b0000000000000000000100000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[20] = (b & 0b0000000000000000000010000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[21] = (b & 0b0000000000000000000001000000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[22] = (b & 0b0000000000000000000000100000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[23] = (b & 0b0000000000000000000000010000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[24] = (b & 0b0000000000000000000000001000000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[25] = (b & 0b0000000000000000000000000100000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[26] = (b & 0b0000000000000000000000000010000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[27] = (b & 0b0000000000000000000000000001000000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[28] = (b & 0b0000000000000000000000000000100000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[29] = (b & 0b0000000000000000000000000000010000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[30] = (b & 0b0000000000000000000000000000001000000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[31] = (b & 0b0000000000000000000000000000000100000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[32] = (b & 0b0000000000000000000000000000000010000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[33] = (b & 0b0000000000000000000000000000000001000000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[34] = (b & 0b0000000000000000000000000000000000100000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[35] = (b & 0b0000000000000000000000000000000000010000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[36] = (b & 0b0000000000000000000000000000000000001000000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[37] = (b & 0b0000000000000000000000000000000000000100000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[38] = (b & 0b0000000000000000000000000000000000000010000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[39] = (b & 0b0000000000000000000000000000000000000001000000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[40] = (b & 0b0000000000000000000000000000000000000000100000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[41] = (b & 0b0000000000000000000000000000000000000000010000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[42] = (b & 0b0000000000000000000000000000000000000000001000000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[43] = (b & 0b0000000000000000000000000000000000000000000100000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[44] = (b & 0b0000000000000000000000000000000000000000000010000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[45] = (b & 0b0000000000000000000000000000000000000000000001000000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[46] = (b & 0b0000000000000000000000000000000000000000000000100000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[47] = (b & 0b0000000000000000000000000000000000000000000000010000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[48] = (b & 0b0000000000000000000000000000000000000000000000001000000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[49] = (b & 0b0000000000000000000000000000000000000000000000000100000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[50] = (b & 0b0000000000000000000000000000000000000000000000000010000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[51] = (b & 0b0000000000000000000000000000000000000000000000000001000000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[52] = (b & 0b0000000000000000000000000000000000000000000000000000100000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[53] = (b & 0b0000000000000000000000000000000000000000000000000000010000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[54] = (b & 0b0000000000000000000000000000000000000000000000000000001000000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[55] = (b & 0b0000000000000000000000000000000000000000000000000000000100000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[56] = (b & 0b0000000000000000000000000000000000000000000000000000000010000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[57] = (b & 0b0000000000000000000000000000000000000000000000000000000001000000) == 0 ? '0' : '1';
  outCharsNoNullTerm[58] = (b & 0b0000000000000000000000000000000000000000000000000000000000100000) == 0 ? '0' : '1';
  outCharsNoNullTerm[59] = (b & 0b0000000000000000000000000000000000000000000000000000000000010000) == 0 ? '0' : '1';
  outCharsNoNullTerm[60] = (b & 0b0000000000000000000000000000000000000000000000000000000000001000) == 0 ? '0' : '1';
  outCharsNoNullTerm[61] = (b & 0b0000000000000000000000000000000000000000000000000000000000000100) == 0 ? '0' : '1';
  outCharsNoNullTerm[62] = (b & 0b0000000000000000000000000000000000000000000000000000000000000010) == 0 ? '0' : '1';
  outCharsNoNullTerm[63] = (b & 0b0000000000000000000000000000000000000000000000000000000000000001) == 0 ? '0' : '1';
}

extern __declspec(dllexport) void red32HexUint8ToCharsNoNullTerm(uint8_t value, char * outCharsNoNullTerm) {
  const char * hexTable[256] = {
    "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "0A", "0B", "0C", "0D", "0E", "0F",
    "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "1A", "1B", "1C", "1D", "1E", "1F",
    "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "2A", "2B", "2C", "2D", "2E", "2F",
    "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "3A", "3B", "3C", "3D", "3E", "3F",
    "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "4A", "4B", "4C", "4D", "4E", "4F",
    "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "5A", "5B", "5C", "5D", "5E", "5F",
    "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "6A", "6B", "6C", "6D", "6E", "6F",
    "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "7A", "7B", "7C", "7D", "7E", "7F",
    "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "8A", "8B", "8C", "8D", "8E", "8F",
    "90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "9A", "9B", "9C", "9D", "9E", "9F",
    "A0", "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "AA", "AB", "AC", "AD", "AE", "AF",
    "B0", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "BA", "BB", "BC", "BD", "BE", "BF",
    "C0", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CA", "CB", "CC", "CD", "CE", "CF",
    "D0", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DA", "DB", "DC", "DD", "DE", "DF",
    "E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "EA", "EB", "EC", "ED", "EE", "EF",
    "F0", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "FA", "FB", "FC", "FD", "FE", "FF"
  };
  const char * hex0 = hexTable[value];
  outCharsNoNullTerm[0] = hex0[0];
  outCharsNoNullTerm[1] = hex0[1];
}

extern __declspec(dllexport) void red32HexUnsignedToCharsNoNullTerm(unsigned value, char * outCharsNoNullTerm) {
  const char * hexTable[256] = {
    "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "0A", "0B", "0C", "0D", "0E", "0F",
    "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "1A", "1B", "1C", "1D", "1E", "1F",
    "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "2A", "2B", "2C", "2D", "2E", "2F",
    "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "3A", "3B", "3C", "3D", "3E", "3F",
    "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "4A", "4B", "4C", "4D", "4E", "4F",
    "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "5A", "5B", "5C", "5D", "5E", "5F",
    "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "6A", "6B", "6C", "6D", "6E", "6F",
    "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "7A", "7B", "7C", "7D", "7E", "7F",
    "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "8A", "8B", "8C", "8D", "8E", "8F",
    "90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "9A", "9B", "9C", "9D", "9E", "9F",
    "A0", "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "AA", "AB", "AC", "AD", "AE", "AF",
    "B0", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "BA", "BB", "BC", "BD", "BE", "BF",
    "C0", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CA", "CB", "CC", "CD", "CE", "CF",
    "D0", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DA", "DB", "DC", "DD", "DE", "DF",
    "E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "EA", "EB", "EC", "ED", "EE", "EF",
    "F0", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "FA", "FB", "FC", "FD", "FE", "FF"
  };
  unsigned char * vs    = (unsigned char *)(void *)&value;
  unsigned char   v0    = vs[0];
  unsigned char   v1    = vs[1];
  unsigned char   v2    = vs[2];
  unsigned char   v3    = vs[3];
  const char *    hex0  = hexTable[v0];
  const char *    hex1  = hexTable[v1];
  const char *    hex2  = hexTable[v2];
  const char *    hex3  = hexTable[v3];
  outCharsNoNullTerm[0] = hex3[0];
  outCharsNoNullTerm[1] = hex3[1];
  outCharsNoNullTerm[2] = hex2[0];
  outCharsNoNullTerm[3] = hex2[1];
  outCharsNoNullTerm[4] = hex1[0];
  outCharsNoNullTerm[5] = hex1[1];
  outCharsNoNullTerm[6] = hex0[0];
  outCharsNoNullTerm[7] = hex0[1];
}

extern __declspec(dllexport) void red32HexUint64ToCharsNoNullTerm(uint64_t value, char * outCharsNoNullTerm) {
  const char * hexTable[256] = {
    "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "0A", "0B", "0C", "0D", "0E", "0F",
    "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "1A", "1B", "1C", "1D", "1E", "1F",
    "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "2A", "2B", "2C", "2D", "2E", "2F",
    "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "3A", "3B", "3C", "3D", "3E", "3F",
    "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "4A", "4B", "4C", "4D", "4E", "4F",
    "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "5A", "5B", "5C", "5D", "5E", "5F",
    "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "6A", "6B", "6C", "6D", "6E", "6F",
    "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "7A", "7B", "7C", "7D", "7E", "7F",
    "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "8A", "8B", "8C", "8D", "8E", "8F",
    "90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "9A", "9B", "9C", "9D", "9E", "9F",
    "A0", "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "AA", "AB", "AC", "AD", "AE", "AF",
    "B0", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "BA", "BB", "BC", "BD", "BE", "BF",
    "C0", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CA", "CB", "CC", "CD", "CE", "CF",
    "D0", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DA", "DB", "DC", "DD", "DE", "DF",
    "E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "EA", "EB", "EC", "ED", "EE", "EF",
    "F0", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "FA", "FB", "FC", "FD", "FE", "FF"
  };
  unsigned char * vs   = (unsigned char *)(void *)&value;
  unsigned char   v0   = vs[0];
  unsigned char   v1   = vs[1];
  unsigned char   v2   = vs[2];
  unsigned char   v3   = vs[3];
  unsigned char   v4   = vs[4];
  unsigned char   v5   = vs[5];
  unsigned char   v6   = vs[6];
  unsigned char   v7   = vs[7];
  const char *    hex0 = hexTable[v0];
  const char *    hex1 = hexTable[v1];
  const char *    hex2 = hexTable[v2];
  const char *    hex3 = hexTable[v3];
  const char *    hex4 = hexTable[v4];
  const char *    hex5 = hexTable[v5];
  const char *    hex6 = hexTable[v6];
  const char *    hex7 = hexTable[v7];
  outCharsNoNullTerm[0]  = hex7[0];
  outCharsNoNullTerm[1]  = hex7[1];
  outCharsNoNullTerm[2]  = hex6[0];
  outCharsNoNullTerm[3]  = hex6[1];
  outCharsNoNullTerm[4]  = hex5[0];
  outCharsNoNullTerm[5]  = hex5[1];
  outCharsNoNullTerm[6]  = hex4[0];
  outCharsNoNullTerm[7]  = hex4[1];
  outCharsNoNullTerm[8]  = hex3[0];
  outCharsNoNullTerm[9]  = hex3[1];
  outCharsNoNullTerm[10] = hex2[0];
  outCharsNoNullTerm[11] = hex2[1];
  outCharsNoNullTerm[12] = hex1[0];
  outCharsNoNullTerm[13] = hex1[1];
  outCharsNoNullTerm[14] = hex0[0];
  outCharsNoNullTerm[15] = hex0[1];
}
