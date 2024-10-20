#pragma once

#define _np1_greenCreateStructDeclaration context
#define _np2_greenCreateStructDeclaration gpu
#define _np3_greenCreateStructDeclaration handleName
#define _np4_greenCreateStructDeclaration outStructDeclaration
#define _np5_greenCreateStructDeclaration outStatuses
#define _np6_greenCreateStructDeclaration optionalFile
#define _np7_greenCreateStructDeclaration optionalLine
#define _np8_greenCreateStructDeclaration optionalUserData

#define _np1_greenStructHeapAllocate context
#define _np2_greenStructHeapAllocate gpu
#define _np3_greenStructHeapAllocate handleName
#define _np4_greenStructHeapAllocate structDeclarationsCount
#define _np5_greenStructHeapAllocate structDeclarations
#define _np6_greenStructHeapAllocate outStructHeap
#define _np7_greenStructHeapAllocate outStatuses
#define _np8_greenStructHeapAllocate optionalFile
#define _np9_greenStructHeapAllocate optionalLine
#define _np10_greenStructHeapAllocate optionalUserData

#define _np1_greenStructHeapReset context
#define _np2_greenStructHeapReset gpu
#define _np3_greenStructHeapReset structDeclarationsCount
#define _np4_greenStructHeapReset structDeclarations
#define _np5_greenStructHeapReset outStructHeap
#define _np6_greenStructHeapReset outStatuses
#define _np7_greenStructHeapReset optionalFile
#define _np8_greenStructHeapReset optionalLine
#define _np9_greenStructHeapReset optionalUserData

#define _np1_greenStructHeapsSet context
#define _np2_greenStructHeapsSet gpu
#define _np3_greenStructHeapsSet structHeapsSetsCount
#define _np4_greenStructHeapsSet structHeapsSets
#define _np5_greenStructHeapsSet optionalFile
#define _np6_greenStructHeapsSet optionalLine
#define _np7_greenStructHeapsSet optionalUserData

#define _np1_greenStructHeapFree context
#define _np2_greenStructHeapFree gpu
#define _np3_greenStructHeapFree structHeap
#define _np4_greenStructHeapFree optionalFile
#define _np5_greenStructHeapFree optionalLine
#define _np6_greenStructHeapFree optionalUserData

