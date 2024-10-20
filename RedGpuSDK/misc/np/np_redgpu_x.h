#pragma once

#define _np1_redXMemoryCallbackBudgetChangeRegister context
#define _np2_redXMemoryCallbackBudgetChangeRegister gpu
#define _np3_redXMemoryCallbackBudgetChangeRegister eventHandle
#define _np4_redXMemoryCallbackBudgetChangeRegister outMemoryCallbackBudgetChange
#define _np5_redXMemoryCallbackBudgetChangeRegister outStatuses
#define _np6_redXMemoryCallbackBudgetChangeRegister optionalFile
#define _np7_redXMemoryCallbackBudgetChangeRegister optionalLine
#define _np8_redXMemoryCallbackBudgetChangeRegister optionalUserData

#define _np1_redXMemoryCallbackBudgetChangeUnregister context
#define _np2_redXMemoryCallbackBudgetChangeUnregister gpu
#define _np3_redXMemoryCallbackBudgetChangeUnregister memoryCallbackBudgetChange
#define _np4_redXMemoryCallbackBudgetChangeUnregister optionalFile
#define _np5_redXMemoryCallbackBudgetChangeUnregister optionalLine
#define _np6_redXMemoryCallbackBudgetChangeUnregister optionalUserData

#define _np1_redXMemoryReserve context
#define _np2_redXMemoryReserve gpu
#define _np3_redXMemoryReserve sharedMemory
#define _np4_redXMemoryReserve bytesCount
#define _np5_redXMemoryReserve outStatuses
#define _np6_redXMemoryReserve optionalFile
#define _np7_redXMemoryReserve optionalLine
#define _np8_redXMemoryReserve optionalUserData

#define _np1_redXGetMemoryAddressArray context
#define _np2_redXGetMemoryAddressArray gpu
#define _np3_redXGetMemoryAddressArray array

#define _np1_redXGetMemoryAddressSampler context
#define _np2_redXGetMemoryAddressSampler gpu
#define _np3_redXGetMemoryAddressSampler sampler

#define _np1_redXGetMemoryAddressTextureRO context
#define _np2_redXGetMemoryAddressTextureRO gpu
#define _np3_redXGetMemoryAddressTextureRO texture

#define _np1_redXGetMemoryAddressTextureRW context
#define _np2_redXGetMemoryAddressTextureRW gpu
#define _np3_redXGetMemoryAddressTextureRW texture

#define _np1_redXGetMemoryAddressStructMember context
#define _np2_redXGetMemoryAddressStructMember gpu
#define _np3_redXGetMemoryAddressStructMember structsMemory
#define _np4_redXGetMemoryAddressStructMember structMemberIndex

#define _np1_redXStructsMemorySet context
#define _np2_redXStructsMemorySet gpu
#define _np3_redXStructsMemorySet copyingSamplers
#define _np4_redXStructsMemorySet sourceCopiesCount
#define _np5_redXStructsMemorySet sourceCopiesAddressFirst
#define _np6_redXStructsMemorySet sourceCopiesAddressCount
#define _np7_redXStructsMemorySet targetCopiesCount
#define _np8_redXStructsMemorySet targetCopiesAddressFirst
#define _np9_redXStructsMemorySet targetCopiesAddressCount
#define _np10_redXStructsMemorySet outStatuses
#define _np11_redXStructsMemorySet optionalFile
#define _np12_redXStructsMemorySet optionalLine
#define _np13_redXStructsMemorySet optionalUserData

#define _np1_redXGetHandleStruct context
#define _np2_redXGetHandleStruct gpu
#define _np3_redXGetHandleStruct structsMemory
#define _np4_redXGetHandleStruct structMemberIndex

#define _np1_redXCreateQueue context
#define _np2_redXCreateQueue gpu
#define _np3_redXCreateQueue handleName
#define _np4_redXCreateQueue canCopy
#define _np5_redXCreateQueue canDraw
#define _np6_redXCreateQueue canCompute
#define _np7_redXCreateQueue priority
#define _np8_redXCreateQueue disableGpuTimeout
#define _np9_redXCreateQueue outStatuses
#define _np10_redXCreateQueue optionalFile
#define _np11_redXCreateQueue optionalLine
#define _np12_redXCreateQueue optionalUserData

#define _np1_redXCreateImage context
#define _np2_redXCreateImage gpu
#define _np3_redXCreateImage handleName
#define _np4_redXCreateImage dimensions
#define _np5_redXCreateImage format
#define _np6_redXCreateImage xformat
#define _np7_redXCreateImage width
#define _np8_redXCreateImage height
#define _np9_redXCreateImage depth
#define _np10_redXCreateImage levelsCount
#define _np11_redXCreateImage layersCount
#define _np12_redXCreateImage multisampleCount
#define _np13_redXCreateImage restrictToAccess
#define _np14_redXCreateImage initialAccess
#define _np15_redXCreateImage initialQueueFamilyIndex
#define _np16_redXCreateImage dedicate
#define _np17_redXCreateImage outImage
#define _np18_redXCreateImage outStatuses
#define _np19_redXCreateImage optionalFile
#define _np20_redXCreateImage optionalLine
#define _np21_redXCreateImage optionalUserData

#define _np1_redXCreateTexture context
#define _np2_redXCreateTexture gpu
#define _np3_redXCreateTexture handleName
#define _np4_redXCreateTexture image
#define _np5_redXCreateTexture parts
#define _np6_redXCreateTexture dimensions
#define _np7_redXCreateTexture format
#define _np8_redXCreateTexture xformat
#define _np9_redXCreateTexture levelsFirst
#define _np10_redXCreateTexture levelsCount
#define _np11_redXCreateTexture layersFirst
#define _np12_redXCreateTexture layersCount
#define _np13_redXCreateTexture restrictToAccess
#define _np14_redXCreateTexture outTexture
#define _np15_redXCreateTexture outStatuses
#define _np16_redXCreateTexture optionalFile
#define _np17_redXCreateTexture optionalLine
#define _np18_redXCreateTexture optionalUserData

#define _np1_redXGetHandlePageableMemory context
#define _np2_redXGetHandlePageableMemory gpu
#define _np3_redXGetHandlePageableMemory memory

#define _np1_redXGetHandlePageableStructsMemory context
#define _np2_redXGetHandlePageableStructsMemory gpu
#define _np3_redXGetHandlePageableStructsMemory structsMemory

#define _np1_redXPageableSetResidencyPriority context
#define _np2_redXPageableSetResidencyPriority gpu
#define _np3_redXPageableSetResidencyPriority pageablesCount
#define _np4_redXPageableSetResidencyPriority pageables
#define _np5_redXPageableSetResidencyPriority pageablesResidencyPriority
#define _np6_redXPageableSetResidencyPriority outStatuses
#define _np7_redXPageableSetResidencyPriority optionalFile
#define _np8_redXPageableSetResidencyPriority optionalLine
#define _np9_redXPageableSetResidencyPriority optionalUserData

#define _np1_redXPageableMakeResident context
#define _np2_redXPageableMakeResident gpu
#define _np3_redXPageableMakeResident pageablesCount
#define _np4_redXPageableMakeResident pageables
#define _np5_redXPageableMakeResident denyOverbudget
#define _np6_redXPageableMakeResident signalCpuSignal
#define _np7_redXPageableMakeResident outStatuses
#define _np8_redXPageableMakeResident optionalFile
#define _np9_redXPageableMakeResident optionalLine
#define _np10_redXPageableMakeResident optionalUserData

#define _np1_redXPageableEvict context
#define _np2_redXPageableEvict gpu
#define _np3_redXPageableEvict pageablesCount
#define _np4_redXPageableEvict pageables
#define _np5_redXPageableEvict outStatuses
#define _np6_redXPageableEvict optionalFile
#define _np7_redXPageableEvict optionalLine
#define _np8_redXPageableEvict optionalUserData

#define _np1_redXGetHandleResourceArray context
#define _np2_redXGetHandleResourceArray gpu
#define _np3_redXGetHandleResourceArray array

#define _np1_redXGetHandleResourceImage context
#define _np2_redXGetHandleResourceImage gpu
#define _np3_redXGetHandleResourceImage image

#define _np1_redXCallSetProcedureOutput calls
#define _np2_redXCallSetProcedureOutput depthStencil
#define _np3_redXCallSetProcedureOutput colorsCount
#define _np4_redXCallSetProcedureOutput colors
#define _np5_redXCallSetProcedureOutput depthSetProcedureOutputOp
#define _np6_redXCallSetProcedureOutput stencilSetProcedureOutputOp
#define _np7_redXCallSetProcedureOutput colorsSetProcedureOutputOp
#define _np8_redXCallSetProcedureOutput depthClearValue
#define _np9_redXCallSetProcedureOutput stencilClearValue
#define _np10_redXCallSetProcedureOutput colorsClearValuesFloat

#define _np1_redXCallEndProcedureOutput calls
#define _np2_redXCallEndProcedureOutput resolveTargetColors
#define _np3_redXCallEndProcedureOutput resolveTargetColorsFormat
#define _np4_redXCallEndProcedureOutput depthEndProcedureOutputOp
#define _np5_redXCallEndProcedureOutput stencilEndProcedureOutputOp
#define _np6_redXCallEndProcedureOutput colorsEndProcedureOutputOp

#define _np1_redXCallUsageAliasOrderBarrier calls
#define _np2_redXCallUsageAliasOrderBarrier barriersCount
#define _np3_redXCallUsageAliasOrderBarrier barriers

#define _np1_redXCallCopyImageRegion calls
#define _np2_redXCallCopyImageRegion copiesCount
#define _np3_redXCallCopyImageRegion copies

#define _np1_redXCreateSurfaceWinRT context
#define _np2_redXCreateSurfaceWinRT gpu
#define _np3_redXCreateSurfaceWinRT handleName
#define _np4_redXCreateSurfaceWinRT winrtIUnknownPointerCoreWindow
#define _np5_redXCreateSurfaceWinRT outSurface
#define _np6_redXCreateSurfaceWinRT outStatuses
#define _np7_redXCreateSurfaceWinRT optionalFile
#define _np8_redXCreateSurfaceWinRT optionalLine
#define _np9_redXCreateSurfaceWinRT optionalUserData

