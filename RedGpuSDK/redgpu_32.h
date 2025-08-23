#pragma once

#include <stddef.h> // For size_t
#include <stdint.h> // For uint64_t

#ifdef __cplusplus
extern "C" {
#endif

void * red32MemoryCalloc      (size_t bytesCount);
void   red32MemoryFree        (void * pointer);
void * red32GetModuleHandle   (const char * moduleName);
void * red32WindowCreate      (const char * title);
int    red32WindowDestroy     (void * windowHandle);
int    red32WindowLoop        ();
void   red32ConsolePrint      (const char * string);
void   red32ConsolePrintError (const char * string);
int    red32FileMap           (const unsigned short * filepath, void ** outFileDescriptorHandle, void ** outFileMappingHandle, size_t * outFileDataBytesCount, void ** outFileDataPointer);
int    red32FileUnmap         (void * fileDescriptorHandle, void * fileMappingHandle);
void   red32OutputDebugString (const char * string);
void   red32StringJoin        (char * joinTo, const char * joinFrom);
void   red32Exit              (int exitCode);

int    red32IntToChars        (int value, char * outChars);
int    red32UnsignedToChars   (unsigned value, char * outChars);
int    red32Int64ToChars      (int64_t value, char * outChars);
int    red32Uint64ToChars     (uint64_t value, char * outChars);
int    red32FloatToChars      (float value, char * outChars);
int    red32DoubleToChars     (double value, char * outChars);

void   red32BinaryUint8ToCharsNoNullTerm    (uint8_t value, char * outCharsNoNullTerm);
void   red32BinaryUnsignedToCharsNoNullTerm (unsigned value, char * outCharsNoNullTerm);
void   red32BinaryUint64ToCharsNoNullTerm   (uint64_t value, char * outCharsNoNullTerm);

void   red32HexUint8ToCharsNoNullTerm       (uint8_t value, char * outCharsNoNullTerm);
void   red32HexUnsignedToCharsNoNullTerm    (unsigned value, char * outCharsNoNullTerm);
void   red32HexUint64ToCharsNoNullTerm      (uint64_t value, char * outCharsNoNullTerm);

#ifdef __cplusplus
}
#endif
