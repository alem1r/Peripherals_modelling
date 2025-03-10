/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * schema-defined QAPI visitor functions
 *
 * Copyright IBM, Corp. 2011
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 *
 */

#ifndef QAPI_VISIT_H
#define QAPI_VISIT_H

#include "qapi/visitor.h"
#include "qapi-types.h"


#ifndef QAPI_VISIT_BUILTIN_VISITOR_DECL_H
#define QAPI_VISIT_BUILTIN_VISITOR_DECL_H

void visit_type_int32List(Visitor *m, int32List **obj, const char *name, Error **errp);
void visit_type_int16List(Visitor *m, int16List **obj, const char *name, Error **errp);
void visit_type_intList(Visitor *m, intList **obj, const char *name, Error **errp);
void visit_type_uint8List(Visitor *m, uint8List **obj, const char *name, Error **errp);
void visit_type_numberList(Visitor *m, numberList **obj, const char *name, Error **errp);
void visit_type_int8List(Visitor *m, int8List **obj, const char *name, Error **errp);
void visit_type_sizeList(Visitor *m, sizeList **obj, const char *name, Error **errp);
void visit_type_uint64List(Visitor *m, uint64List **obj, const char *name, Error **errp);
void visit_type_uint16List(Visitor *m, uint16List **obj, const char *name, Error **errp);
void visit_type_boolList(Visitor *m, boolList **obj, const char *name, Error **errp);
void visit_type_strList(Visitor *m, strList **obj, const char *name, Error **errp);
void visit_type_int64List(Visitor *m, int64List **obj, const char *name, Error **errp);
void visit_type_uint32List(Visitor *m, uint32List **obj, const char *name, Error **errp);

#endif /* QAPI_VISIT_BUILTIN_VISITOR_DECL_H */


void visit_type_ErrorClass(Visitor *m, ErrorClass *obj, const char *name, Error **errp);
void visit_type_ErrorClassList(Visitor *m, ErrorClassList **obj, const char *name, Error **errp);

void visit_type_VersionTriple(Visitor *m, VersionTriple **obj, const char *name, Error **errp);
void visit_type_VersionTripleList(Visitor *m, VersionTripleList **obj, const char *name, Error **errp);

void visit_type_VersionInfo(Visitor *m, VersionInfo **obj, const char *name, Error **errp);
void visit_type_VersionInfoList(Visitor *m, VersionInfoList **obj, const char *name, Error **errp);

void visit_type_CommandInfo(Visitor *m, CommandInfo **obj, const char *name, Error **errp);
void visit_type_CommandInfoList(Visitor *m, CommandInfoList **obj, const char *name, Error **errp);

void visit_type_OnOffAuto(Visitor *m, OnOffAuto *obj, const char *name, Error **errp);
void visit_type_OnOffAutoList(Visitor *m, OnOffAutoList **obj, const char *name, Error **errp);

void visit_type_SnapshotInfo(Visitor *m, SnapshotInfo **obj, const char *name, Error **errp);
void visit_type_SnapshotInfoList(Visitor *m, SnapshotInfoList **obj, const char *name, Error **errp);

void visit_type_ImageInfoSpecificQCow2(Visitor *m, ImageInfoSpecificQCow2 **obj, const char *name, Error **errp);
void visit_type_ImageInfoSpecificQCow2List(Visitor *m, ImageInfoSpecificQCow2List **obj, const char *name, Error **errp);

void visit_type_ImageInfoSpecificVmdk(Visitor *m, ImageInfoSpecificVmdk **obj, const char *name, Error **errp);
void visit_type_ImageInfoSpecificVmdkList(Visitor *m, ImageInfoSpecificVmdkList **obj, const char *name, Error **errp);

void visit_type_ImageInfoSpecificKind(Visitor *m, ImageInfoSpecificKind *obj, const char *name, Error **errp);

void visit_type_ImageInfoSpecific(Visitor *m, ImageInfoSpecific **obj, const char *name, Error **errp);
void visit_type_ImageInfoSpecificList(Visitor *m, ImageInfoSpecificList **obj, const char *name, Error **errp);

void visit_type_ImageInfo(Visitor *m, ImageInfo **obj, const char *name, Error **errp);
void visit_type_ImageInfoList(Visitor *m, ImageInfoList **obj, const char *name, Error **errp);

void visit_type_ImageCheck(Visitor *m, ImageCheck **obj, const char *name, Error **errp);
void visit_type_ImageCheckList(Visitor *m, ImageCheckList **obj, const char *name, Error **errp);

void visit_type_BlockdevCacheInfo(Visitor *m, BlockdevCacheInfo **obj, const char *name, Error **errp);
void visit_type_BlockdevCacheInfoList(Visitor *m, BlockdevCacheInfoList **obj, const char *name, Error **errp);

void visit_type_BlockDeviceInfo(Visitor *m, BlockDeviceInfo **obj, const char *name, Error **errp);
void visit_type_BlockDeviceInfoList(Visitor *m, BlockDeviceInfoList **obj, const char *name, Error **errp);

void visit_type_BlockDeviceIoStatus(Visitor *m, BlockDeviceIoStatus *obj, const char *name, Error **errp);
void visit_type_BlockDeviceIoStatusList(Visitor *m, BlockDeviceIoStatusList **obj, const char *name, Error **errp);

void visit_type_BlockDeviceMapEntry(Visitor *m, BlockDeviceMapEntry **obj, const char *name, Error **errp);
void visit_type_BlockDeviceMapEntryList(Visitor *m, BlockDeviceMapEntryList **obj, const char *name, Error **errp);

void visit_type_DirtyBitmapStatus(Visitor *m, DirtyBitmapStatus *obj, const char *name, Error **errp);
void visit_type_DirtyBitmapStatusList(Visitor *m, DirtyBitmapStatusList **obj, const char *name, Error **errp);

void visit_type_BlockDirtyInfo(Visitor *m, BlockDirtyInfo **obj, const char *name, Error **errp);
void visit_type_BlockDirtyInfoList(Visitor *m, BlockDirtyInfoList **obj, const char *name, Error **errp);

void visit_type_BlockInfo(Visitor *m, BlockInfo **obj, const char *name, Error **errp);
void visit_type_BlockInfoList(Visitor *m, BlockInfoList **obj, const char *name, Error **errp);

void visit_type_BlockDeviceStats(Visitor *m, BlockDeviceStats **obj, const char *name, Error **errp);
void visit_type_BlockDeviceStatsList(Visitor *m, BlockDeviceStatsList **obj, const char *name, Error **errp);

void visit_type_BlockStats(Visitor *m, BlockStats **obj, const char *name, Error **errp);
void visit_type_BlockStatsList(Visitor *m, BlockStatsList **obj, const char *name, Error **errp);

void visit_type_BlockdevOnError(Visitor *m, BlockdevOnError *obj, const char *name, Error **errp);
void visit_type_BlockdevOnErrorList(Visitor *m, BlockdevOnErrorList **obj, const char *name, Error **errp);

void visit_type_MirrorSyncMode(Visitor *m, MirrorSyncMode *obj, const char *name, Error **errp);
void visit_type_MirrorSyncModeList(Visitor *m, MirrorSyncModeList **obj, const char *name, Error **errp);

void visit_type_BlockJobType(Visitor *m, BlockJobType *obj, const char *name, Error **errp);
void visit_type_BlockJobTypeList(Visitor *m, BlockJobTypeList **obj, const char *name, Error **errp);

void visit_type_BlockJobInfo(Visitor *m, BlockJobInfo **obj, const char *name, Error **errp);
void visit_type_BlockJobInfoList(Visitor *m, BlockJobInfoList **obj, const char *name, Error **errp);

void visit_type_NewImageMode(Visitor *m, NewImageMode *obj, const char *name, Error **errp);
void visit_type_NewImageModeList(Visitor *m, NewImageModeList **obj, const char *name, Error **errp);

void visit_type_BlockdevSnapshot(Visitor *m, BlockdevSnapshot **obj, const char *name, Error **errp);
void visit_type_BlockdevSnapshotList(Visitor *m, BlockdevSnapshotList **obj, const char *name, Error **errp);

void visit_type_DriveBackup(Visitor *m, DriveBackup **obj, const char *name, Error **errp);
void visit_type_DriveBackupList(Visitor *m, DriveBackupList **obj, const char *name, Error **errp);

void visit_type_BlockdevBackup(Visitor *m, BlockdevBackup **obj, const char *name, Error **errp);
void visit_type_BlockdevBackupList(Visitor *m, BlockdevBackupList **obj, const char *name, Error **errp);

void visit_type_BlockDirtyBitmap(Visitor *m, BlockDirtyBitmap **obj, const char *name, Error **errp);
void visit_type_BlockDirtyBitmapList(Visitor *m, BlockDirtyBitmapList **obj, const char *name, Error **errp);

void visit_type_BlockDirtyBitmapAdd(Visitor *m, BlockDirtyBitmapAdd **obj, const char *name, Error **errp);
void visit_type_BlockDirtyBitmapAddList(Visitor *m, BlockDirtyBitmapAddList **obj, const char *name, Error **errp);

void visit_type_BlockdevDiscardOptions(Visitor *m, BlockdevDiscardOptions *obj, const char *name, Error **errp);
void visit_type_BlockdevDiscardOptionsList(Visitor *m, BlockdevDiscardOptionsList **obj, const char *name, Error **errp);

void visit_type_BlockdevDetectZeroesOptions(Visitor *m, BlockdevDetectZeroesOptions *obj, const char *name, Error **errp);
void visit_type_BlockdevDetectZeroesOptionsList(Visitor *m, BlockdevDetectZeroesOptionsList **obj, const char *name, Error **errp);

void visit_type_BlockdevAioOptions(Visitor *m, BlockdevAioOptions *obj, const char *name, Error **errp);
void visit_type_BlockdevAioOptionsList(Visitor *m, BlockdevAioOptionsList **obj, const char *name, Error **errp);

void visit_type_BlockdevCacheOptions(Visitor *m, BlockdevCacheOptions **obj, const char *name, Error **errp);
void visit_type_BlockdevCacheOptionsList(Visitor *m, BlockdevCacheOptionsList **obj, const char *name, Error **errp);

void visit_type_BlockdevDriver(Visitor *m, BlockdevDriver *obj, const char *name, Error **errp);
void visit_type_BlockdevDriverList(Visitor *m, BlockdevDriverList **obj, const char *name, Error **errp);

void visit_type_BlockdevOptionsBase(Visitor *m, BlockdevOptionsBase **obj, const char *name, Error **errp);
void visit_type_BlockdevOptionsBaseList(Visitor *m, BlockdevOptionsBaseList **obj, const char *name, Error **errp);

void visit_type_BlockdevOptionsFile(Visitor *m, BlockdevOptionsFile **obj, const char *name, Error **errp);
void visit_type_BlockdevOptionsFileList(Visitor *m, BlockdevOptionsFileList **obj, const char *name, Error **errp);

void visit_type_BlockdevOptionsNull(Visitor *m, BlockdevOptionsNull **obj, const char *name, Error **errp);
void visit_type_BlockdevOptionsNullList(Visitor *m, BlockdevOptionsNullList **obj, const char *name, Error **errp);

void visit_type_BlockdevOptionsVVFAT(Visitor *m, BlockdevOptionsVVFAT **obj, const char *name, Error **errp);
void visit_type_BlockdevOptionsVVFATList(Visitor *m, BlockdevOptionsVVFATList **obj, const char *name, Error **errp);

void visit_type_BlockdevOptionsGenericFormat(Visitor *m, BlockdevOptionsGenericFormat **obj, const char *name, Error **errp);
void visit_type_BlockdevOptionsGenericFormatList(Visitor *m, BlockdevOptionsGenericFormatList **obj, const char *name, Error **errp);

void visit_type_BlockdevOptionsGenericCOWFormat(Visitor *m, BlockdevOptionsGenericCOWFormat **obj, const char *name, Error **errp);
void visit_type_BlockdevOptionsGenericCOWFormatList(Visitor *m, BlockdevOptionsGenericCOWFormatList **obj, const char *name, Error **errp);

void visit_type_Qcow2OverlapCheckMode(Visitor *m, Qcow2OverlapCheckMode *obj, const char *name, Error **errp);
void visit_type_Qcow2OverlapCheckModeList(Visitor *m, Qcow2OverlapCheckModeList **obj, const char *name, Error **errp);

void visit_type_Qcow2OverlapCheckFlags(Visitor *m, Qcow2OverlapCheckFlags **obj, const char *name, Error **errp);
void visit_type_Qcow2OverlapCheckFlagsList(Visitor *m, Qcow2OverlapCheckFlagsList **obj, const char *name, Error **errp);

void visit_type_Qcow2OverlapChecksKind(Visitor *m, Qcow2OverlapChecksKind *obj, const char *name, Error **errp);

void visit_type_Qcow2OverlapChecks(Visitor *m, Qcow2OverlapChecks **obj, const char *name, Error **errp);
void visit_type_Qcow2OverlapChecksList(Visitor *m, Qcow2OverlapChecksList **obj, const char *name, Error **errp);

void visit_type_BlockdevOptionsQcow2(Visitor *m, BlockdevOptionsQcow2 **obj, const char *name, Error **errp);
void visit_type_BlockdevOptionsQcow2List(Visitor *m, BlockdevOptionsQcow2List **obj, const char *name, Error **errp);

void visit_type_BlockdevOptionsArchipelago(Visitor *m, BlockdevOptionsArchipelago **obj, const char *name, Error **errp);
void visit_type_BlockdevOptionsArchipelagoList(Visitor *m, BlockdevOptionsArchipelagoList **obj, const char *name, Error **errp);

void visit_type_BlkdebugEvent(Visitor *m, BlkdebugEvent *obj, const char *name, Error **errp);
void visit_type_BlkdebugEventList(Visitor *m, BlkdebugEventList **obj, const char *name, Error **errp);

void visit_type_BlkdebugInjectErrorOptions(Visitor *m, BlkdebugInjectErrorOptions **obj, const char *name, Error **errp);
void visit_type_BlkdebugInjectErrorOptionsList(Visitor *m, BlkdebugInjectErrorOptionsList **obj, const char *name, Error **errp);

void visit_type_BlkdebugSetStateOptions(Visitor *m, BlkdebugSetStateOptions **obj, const char *name, Error **errp);
void visit_type_BlkdebugSetStateOptionsList(Visitor *m, BlkdebugSetStateOptionsList **obj, const char *name, Error **errp);

void visit_type_BlockdevOptionsBlkdebug(Visitor *m, BlockdevOptionsBlkdebug **obj, const char *name, Error **errp);
void visit_type_BlockdevOptionsBlkdebugList(Visitor *m, BlockdevOptionsBlkdebugList **obj, const char *name, Error **errp);

void visit_type_BlockdevOptionsBlkverify(Visitor *m, BlockdevOptionsBlkverify **obj, const char *name, Error **errp);
void visit_type_BlockdevOptionsBlkverifyList(Visitor *m, BlockdevOptionsBlkverifyList **obj, const char *name, Error **errp);

void visit_type_QuorumReadPattern(Visitor *m, QuorumReadPattern *obj, const char *name, Error **errp);
void visit_type_QuorumReadPatternList(Visitor *m, QuorumReadPatternList **obj, const char *name, Error **errp);

void visit_type_BlockdevOptionsQuorum(Visitor *m, BlockdevOptionsQuorum **obj, const char *name, Error **errp);
void visit_type_BlockdevOptionsQuorumList(Visitor *m, BlockdevOptionsQuorumList **obj, const char *name, Error **errp);

void visit_type_BlockdevOptions(Visitor *m, BlockdevOptions **obj, const char *name, Error **errp);
void visit_type_BlockdevOptionsList(Visitor *m, BlockdevOptionsList **obj, const char *name, Error **errp);

void visit_type_BlockdevRefKind(Visitor *m, BlockdevRefKind *obj, const char *name, Error **errp);

void visit_type_BlockdevRef(Visitor *m, BlockdevRef **obj, const char *name, Error **errp);
void visit_type_BlockdevRefList(Visitor *m, BlockdevRefList **obj, const char *name, Error **errp);

void visit_type_BlockErrorAction(Visitor *m, BlockErrorAction *obj, const char *name, Error **errp);
void visit_type_BlockErrorActionList(Visitor *m, BlockErrorActionList **obj, const char *name, Error **errp);

void visit_type_PreallocMode(Visitor *m, PreallocMode *obj, const char *name, Error **errp);
void visit_type_PreallocModeList(Visitor *m, PreallocModeList **obj, const char *name, Error **errp);

void visit_type_BiosAtaTranslation(Visitor *m, BiosAtaTranslation *obj, const char *name, Error **errp);
void visit_type_BiosAtaTranslationList(Visitor *m, BiosAtaTranslationList **obj, const char *name, Error **errp);

void visit_type_BlockdevSnapshotInternal(Visitor *m, BlockdevSnapshotInternal **obj, const char *name, Error **errp);
void visit_type_BlockdevSnapshotInternalList(Visitor *m, BlockdevSnapshotInternalList **obj, const char *name, Error **errp);

void visit_type_TraceEventState(Visitor *m, TraceEventState *obj, const char *name, Error **errp);
void visit_type_TraceEventStateList(Visitor *m, TraceEventStateList **obj, const char *name, Error **errp);

void visit_type_TraceEventInfo(Visitor *m, TraceEventInfo **obj, const char *name, Error **errp);
void visit_type_TraceEventInfoList(Visitor *m, TraceEventInfoList **obj, const char *name, Error **errp);

void visit_type_LostTickPolicy(Visitor *m, LostTickPolicy *obj, const char *name, Error **errp);
void visit_type_LostTickPolicyList(Visitor *m, LostTickPolicyList **obj, const char *name, Error **errp);

void visit_type_NameInfo(Visitor *m, NameInfo **obj, const char *name, Error **errp);
void visit_type_NameInfoList(Visitor *m, NameInfoList **obj, const char *name, Error **errp);

void visit_type_KvmInfo(Visitor *m, KvmInfo **obj, const char *name, Error **errp);
void visit_type_KvmInfoList(Visitor *m, KvmInfoList **obj, const char *name, Error **errp);

void visit_type_RunState(Visitor *m, RunState *obj, const char *name, Error **errp);
void visit_type_RunStateList(Visitor *m, RunStateList **obj, const char *name, Error **errp);

void visit_type_StatusInfo(Visitor *m, StatusInfo **obj, const char *name, Error **errp);
void visit_type_StatusInfoList(Visitor *m, StatusInfoList **obj, const char *name, Error **errp);

void visit_type_UuidInfo(Visitor *m, UuidInfo **obj, const char *name, Error **errp);
void visit_type_UuidInfoList(Visitor *m, UuidInfoList **obj, const char *name, Error **errp);

void visit_type_ChardevInfo(Visitor *m, ChardevInfo **obj, const char *name, Error **errp);
void visit_type_ChardevInfoList(Visitor *m, ChardevInfoList **obj, const char *name, Error **errp);

void visit_type_ChardevBackendInfo(Visitor *m, ChardevBackendInfo **obj, const char *name, Error **errp);
void visit_type_ChardevBackendInfoList(Visitor *m, ChardevBackendInfoList **obj, const char *name, Error **errp);

void visit_type_DataFormat(Visitor *m, DataFormat *obj, const char *name, Error **errp);
void visit_type_DataFormatList(Visitor *m, DataFormatList **obj, const char *name, Error **errp);

void visit_type_EventInfo(Visitor *m, EventInfo **obj, const char *name, Error **errp);
void visit_type_EventInfoList(Visitor *m, EventInfoList **obj, const char *name, Error **errp);

void visit_type_MigrationStats(Visitor *m, MigrationStats **obj, const char *name, Error **errp);
void visit_type_MigrationStatsList(Visitor *m, MigrationStatsList **obj, const char *name, Error **errp);

void visit_type_XBZRLECacheStats(Visitor *m, XBZRLECacheStats **obj, const char *name, Error **errp);
void visit_type_XBZRLECacheStatsList(Visitor *m, XBZRLECacheStatsList **obj, const char *name, Error **errp);

void visit_type_MigrationStatus(Visitor *m, MigrationStatus *obj, const char *name, Error **errp);
void visit_type_MigrationStatusList(Visitor *m, MigrationStatusList **obj, const char *name, Error **errp);

void visit_type_MigrationInfo(Visitor *m, MigrationInfo **obj, const char *name, Error **errp);
void visit_type_MigrationInfoList(Visitor *m, MigrationInfoList **obj, const char *name, Error **errp);

void visit_type_MigrationCapability(Visitor *m, MigrationCapability *obj, const char *name, Error **errp);
void visit_type_MigrationCapabilityList(Visitor *m, MigrationCapabilityList **obj, const char *name, Error **errp);

void visit_type_MigrationCapabilityStatus(Visitor *m, MigrationCapabilityStatus **obj, const char *name, Error **errp);
void visit_type_MigrationCapabilityStatusList(Visitor *m, MigrationCapabilityStatusList **obj, const char *name, Error **errp);

void visit_type_MigrationParameter(Visitor *m, MigrationParameter *obj, const char *name, Error **errp);
void visit_type_MigrationParameterList(Visitor *m, MigrationParameterList **obj, const char *name, Error **errp);

void visit_type_MigrationParameters(Visitor *m, MigrationParameters **obj, const char *name, Error **errp);
void visit_type_MigrationParametersList(Visitor *m, MigrationParametersList **obj, const char *name, Error **errp);

void visit_type_MouseInfo(Visitor *m, MouseInfo **obj, const char *name, Error **errp);
void visit_type_MouseInfoList(Visitor *m, MouseInfoList **obj, const char *name, Error **errp);

void visit_type_CpuInfo(Visitor *m, CpuInfo **obj, const char *name, Error **errp);
void visit_type_CpuInfoList(Visitor *m, CpuInfoList **obj, const char *name, Error **errp);

void visit_type_IOThreadInfo(Visitor *m, IOThreadInfo **obj, const char *name, Error **errp);
void visit_type_IOThreadInfoList(Visitor *m, IOThreadInfoList **obj, const char *name, Error **errp);

void visit_type_NetworkAddressFamily(Visitor *m, NetworkAddressFamily *obj, const char *name, Error **errp);
void visit_type_NetworkAddressFamilyList(Visitor *m, NetworkAddressFamilyList **obj, const char *name, Error **errp);

void visit_type_VncBasicInfo(Visitor *m, VncBasicInfo **obj, const char *name, Error **errp);
void visit_type_VncBasicInfoList(Visitor *m, VncBasicInfoList **obj, const char *name, Error **errp);

void visit_type_VncServerInfo(Visitor *m, VncServerInfo **obj, const char *name, Error **errp);
void visit_type_VncServerInfoList(Visitor *m, VncServerInfoList **obj, const char *name, Error **errp);

void visit_type_VncClientInfo(Visitor *m, VncClientInfo **obj, const char *name, Error **errp);
void visit_type_VncClientInfoList(Visitor *m, VncClientInfoList **obj, const char *name, Error **errp);

void visit_type_VncInfo(Visitor *m, VncInfo **obj, const char *name, Error **errp);
void visit_type_VncInfoList(Visitor *m, VncInfoList **obj, const char *name, Error **errp);

void visit_type_VncPrimaryAuth(Visitor *m, VncPrimaryAuth *obj, const char *name, Error **errp);
void visit_type_VncPrimaryAuthList(Visitor *m, VncPrimaryAuthList **obj, const char *name, Error **errp);

void visit_type_VncVencryptSubAuth(Visitor *m, VncVencryptSubAuth *obj, const char *name, Error **errp);
void visit_type_VncVencryptSubAuthList(Visitor *m, VncVencryptSubAuthList **obj, const char *name, Error **errp);

void visit_type_VncInfo2(Visitor *m, VncInfo2 **obj, const char *name, Error **errp);
void visit_type_VncInfo2List(Visitor *m, VncInfo2List **obj, const char *name, Error **errp);

void visit_type_SpiceBasicInfo(Visitor *m, SpiceBasicInfo **obj, const char *name, Error **errp);
void visit_type_SpiceBasicInfoList(Visitor *m, SpiceBasicInfoList **obj, const char *name, Error **errp);

void visit_type_SpiceServerInfo(Visitor *m, SpiceServerInfo **obj, const char *name, Error **errp);
void visit_type_SpiceServerInfoList(Visitor *m, SpiceServerInfoList **obj, const char *name, Error **errp);

void visit_type_SpiceChannel(Visitor *m, SpiceChannel **obj, const char *name, Error **errp);
void visit_type_SpiceChannelList(Visitor *m, SpiceChannelList **obj, const char *name, Error **errp);

void visit_type_SpiceQueryMouseMode(Visitor *m, SpiceQueryMouseMode *obj, const char *name, Error **errp);
void visit_type_SpiceQueryMouseModeList(Visitor *m, SpiceQueryMouseModeList **obj, const char *name, Error **errp);

void visit_type_SpiceInfo(Visitor *m, SpiceInfo **obj, const char *name, Error **errp);
void visit_type_SpiceInfoList(Visitor *m, SpiceInfoList **obj, const char *name, Error **errp);

void visit_type_BalloonInfo(Visitor *m, BalloonInfo **obj, const char *name, Error **errp);
void visit_type_BalloonInfoList(Visitor *m, BalloonInfoList **obj, const char *name, Error **errp);

void visit_type_PciMemoryRange(Visitor *m, PciMemoryRange **obj, const char *name, Error **errp);
void visit_type_PciMemoryRangeList(Visitor *m, PciMemoryRangeList **obj, const char *name, Error **errp);

void visit_type_PciMemoryRegion(Visitor *m, PciMemoryRegion **obj, const char *name, Error **errp);
void visit_type_PciMemoryRegionList(Visitor *m, PciMemoryRegionList **obj, const char *name, Error **errp);

void visit_type_PciBusInfo(Visitor *m, PciBusInfo **obj, const char *name, Error **errp);
void visit_type_PciBusInfoList(Visitor *m, PciBusInfoList **obj, const char *name, Error **errp);

void visit_type_PciBridgeInfo(Visitor *m, PciBridgeInfo **obj, const char *name, Error **errp);
void visit_type_PciBridgeInfoList(Visitor *m, PciBridgeInfoList **obj, const char *name, Error **errp);

void visit_type_PciDeviceClass(Visitor *m, PciDeviceClass **obj, const char *name, Error **errp);
void visit_type_PciDeviceClassList(Visitor *m, PciDeviceClassList **obj, const char *name, Error **errp);

void visit_type_PciDeviceId(Visitor *m, PciDeviceId **obj, const char *name, Error **errp);
void visit_type_PciDeviceIdList(Visitor *m, PciDeviceIdList **obj, const char *name, Error **errp);

void visit_type_PciDeviceInfo(Visitor *m, PciDeviceInfo **obj, const char *name, Error **errp);
void visit_type_PciDeviceInfoList(Visitor *m, PciDeviceInfoList **obj, const char *name, Error **errp);

void visit_type_PciInfo(Visitor *m, PciInfo **obj, const char *name, Error **errp);
void visit_type_PciInfoList(Visitor *m, PciInfoList **obj, const char *name, Error **errp);

void visit_type_Abort(Visitor *m, Abort **obj, const char *name, Error **errp);
void visit_type_AbortList(Visitor *m, AbortList **obj, const char *name, Error **errp);

void visit_type_TransactionActionKind(Visitor *m, TransactionActionKind *obj, const char *name, Error **errp);

void visit_type_TransactionAction(Visitor *m, TransactionAction **obj, const char *name, Error **errp);
void visit_type_TransactionActionList(Visitor *m, TransactionActionList **obj, const char *name, Error **errp);

void visit_type_ObjectPropertyInfo(Visitor *m, ObjectPropertyInfo **obj, const char *name, Error **errp);
void visit_type_ObjectPropertyInfoList(Visitor *m, ObjectPropertyInfoList **obj, const char *name, Error **errp);

void visit_type_ObjectTypeInfo(Visitor *m, ObjectTypeInfo **obj, const char *name, Error **errp);
void visit_type_ObjectTypeInfoList(Visitor *m, ObjectTypeInfoList **obj, const char *name, Error **errp);

void visit_type_DevicePropertyInfo(Visitor *m, DevicePropertyInfo **obj, const char *name, Error **errp);
void visit_type_DevicePropertyInfoList(Visitor *m, DevicePropertyInfoList **obj, const char *name, Error **errp);

void visit_type_DumpGuestMemoryFormat(Visitor *m, DumpGuestMemoryFormat *obj, const char *name, Error **errp);
void visit_type_DumpGuestMemoryFormatList(Visitor *m, DumpGuestMemoryFormatList **obj, const char *name, Error **errp);

void visit_type_DumpGuestMemoryCapability(Visitor *m, DumpGuestMemoryCapability **obj, const char *name, Error **errp);
void visit_type_DumpGuestMemoryCapabilityList(Visitor *m, DumpGuestMemoryCapabilityList **obj, const char *name, Error **errp);

void visit_type_NetdevNoneOptions(Visitor *m, NetdevNoneOptions **obj, const char *name, Error **errp);
void visit_type_NetdevNoneOptionsList(Visitor *m, NetdevNoneOptionsList **obj, const char *name, Error **errp);

void visit_type_NetLegacyNicOptions(Visitor *m, NetLegacyNicOptions **obj, const char *name, Error **errp);
void visit_type_NetLegacyNicOptionsList(Visitor *m, NetLegacyNicOptionsList **obj, const char *name, Error **errp);

void visit_type_String(Visitor *m, String **obj, const char *name, Error **errp);
void visit_type_StringList(Visitor *m, StringList **obj, const char *name, Error **errp);

void visit_type_NetdevUserOptions(Visitor *m, NetdevUserOptions **obj, const char *name, Error **errp);
void visit_type_NetdevUserOptionsList(Visitor *m, NetdevUserOptionsList **obj, const char *name, Error **errp);

void visit_type_NetdevTapOptions(Visitor *m, NetdevTapOptions **obj, const char *name, Error **errp);
void visit_type_NetdevTapOptionsList(Visitor *m, NetdevTapOptionsList **obj, const char *name, Error **errp);

void visit_type_NetdevSocketOptions(Visitor *m, NetdevSocketOptions **obj, const char *name, Error **errp);
void visit_type_NetdevSocketOptionsList(Visitor *m, NetdevSocketOptionsList **obj, const char *name, Error **errp);

void visit_type_NetdevL2TPv3Options(Visitor *m, NetdevL2TPv3Options **obj, const char *name, Error **errp);
void visit_type_NetdevL2TPv3OptionsList(Visitor *m, NetdevL2TPv3OptionsList **obj, const char *name, Error **errp);

void visit_type_NetdevVdeOptions(Visitor *m, NetdevVdeOptions **obj, const char *name, Error **errp);
void visit_type_NetdevVdeOptionsList(Visitor *m, NetdevVdeOptionsList **obj, const char *name, Error **errp);

void visit_type_NetdevDumpOptions(Visitor *m, NetdevDumpOptions **obj, const char *name, Error **errp);
void visit_type_NetdevDumpOptionsList(Visitor *m, NetdevDumpOptionsList **obj, const char *name, Error **errp);

void visit_type_NetdevBridgeOptions(Visitor *m, NetdevBridgeOptions **obj, const char *name, Error **errp);
void visit_type_NetdevBridgeOptionsList(Visitor *m, NetdevBridgeOptionsList **obj, const char *name, Error **errp);

void visit_type_NetdevHubPortOptions(Visitor *m, NetdevHubPortOptions **obj, const char *name, Error **errp);
void visit_type_NetdevHubPortOptionsList(Visitor *m, NetdevHubPortOptionsList **obj, const char *name, Error **errp);

void visit_type_NetdevNetmapOptions(Visitor *m, NetdevNetmapOptions **obj, const char *name, Error **errp);
void visit_type_NetdevNetmapOptionsList(Visitor *m, NetdevNetmapOptionsList **obj, const char *name, Error **errp);

void visit_type_NetdevVhostUserOptions(Visitor *m, NetdevVhostUserOptions **obj, const char *name, Error **errp);
void visit_type_NetdevVhostUserOptionsList(Visitor *m, NetdevVhostUserOptionsList **obj, const char *name, Error **errp);

void visit_type_NetClientOptionsKind(Visitor *m, NetClientOptionsKind *obj, const char *name, Error **errp);

void visit_type_NetClientOptions(Visitor *m, NetClientOptions **obj, const char *name, Error **errp);
void visit_type_NetClientOptionsList(Visitor *m, NetClientOptionsList **obj, const char *name, Error **errp);

void visit_type_NetLegacy(Visitor *m, NetLegacy **obj, const char *name, Error **errp);
void visit_type_NetLegacyList(Visitor *m, NetLegacyList **obj, const char *name, Error **errp);

void visit_type_Netdev(Visitor *m, Netdev **obj, const char *name, Error **errp);
void visit_type_NetdevList(Visitor *m, NetdevList **obj, const char *name, Error **errp);

void visit_type_InetSocketAddress(Visitor *m, InetSocketAddress **obj, const char *name, Error **errp);
void visit_type_InetSocketAddressList(Visitor *m, InetSocketAddressList **obj, const char *name, Error **errp);

void visit_type_UnixSocketAddress(Visitor *m, UnixSocketAddress **obj, const char *name, Error **errp);
void visit_type_UnixSocketAddressList(Visitor *m, UnixSocketAddressList **obj, const char *name, Error **errp);

void visit_type_SocketAddressKind(Visitor *m, SocketAddressKind *obj, const char *name, Error **errp);

void visit_type_SocketAddress(Visitor *m, SocketAddress **obj, const char *name, Error **errp);
void visit_type_SocketAddressList(Visitor *m, SocketAddressList **obj, const char *name, Error **errp);

void visit_type_MachineInfo(Visitor *m, MachineInfo **obj, const char *name, Error **errp);
void visit_type_MachineInfoList(Visitor *m, MachineInfoList **obj, const char *name, Error **errp);

void visit_type_CpuDefinitionInfo(Visitor *m, CpuDefinitionInfo **obj, const char *name, Error **errp);
void visit_type_CpuDefinitionInfoList(Visitor *m, CpuDefinitionInfoList **obj, const char *name, Error **errp);

void visit_type_AddfdInfo(Visitor *m, AddfdInfo **obj, const char *name, Error **errp);
void visit_type_AddfdInfoList(Visitor *m, AddfdInfoList **obj, const char *name, Error **errp);

void visit_type_FdsetFdInfo(Visitor *m, FdsetFdInfo **obj, const char *name, Error **errp);
void visit_type_FdsetFdInfoList(Visitor *m, FdsetFdInfoList **obj, const char *name, Error **errp);

void visit_type_FdsetInfo(Visitor *m, FdsetInfo **obj, const char *name, Error **errp);
void visit_type_FdsetInfoList(Visitor *m, FdsetInfoList **obj, const char *name, Error **errp);

void visit_type_TargetInfo(Visitor *m, TargetInfo **obj, const char *name, Error **errp);
void visit_type_TargetInfoList(Visitor *m, TargetInfoList **obj, const char *name, Error **errp);

void visit_type_QKeyCode(Visitor *m, QKeyCode *obj, const char *name, Error **errp);
void visit_type_QKeyCodeList(Visitor *m, QKeyCodeList **obj, const char *name, Error **errp);

void visit_type_KeyValueKind(Visitor *m, KeyValueKind *obj, const char *name, Error **errp);

void visit_type_KeyValue(Visitor *m, KeyValue **obj, const char *name, Error **errp);
void visit_type_KeyValueList(Visitor *m, KeyValueList **obj, const char *name, Error **errp);

void visit_type_ChardevFile(Visitor *m, ChardevFile **obj, const char *name, Error **errp);
void visit_type_ChardevFileList(Visitor *m, ChardevFileList **obj, const char *name, Error **errp);

void visit_type_ChardevHostdev(Visitor *m, ChardevHostdev **obj, const char *name, Error **errp);
void visit_type_ChardevHostdevList(Visitor *m, ChardevHostdevList **obj, const char *name, Error **errp);

void visit_type_ChardevSocket(Visitor *m, ChardevSocket **obj, const char *name, Error **errp);
void visit_type_ChardevSocketList(Visitor *m, ChardevSocketList **obj, const char *name, Error **errp);

void visit_type_ChardevUdp(Visitor *m, ChardevUdp **obj, const char *name, Error **errp);
void visit_type_ChardevUdpList(Visitor *m, ChardevUdpList **obj, const char *name, Error **errp);

void visit_type_ChardevMux(Visitor *m, ChardevMux **obj, const char *name, Error **errp);
void visit_type_ChardevMuxList(Visitor *m, ChardevMuxList **obj, const char *name, Error **errp);

void visit_type_ChardevStdio(Visitor *m, ChardevStdio **obj, const char *name, Error **errp);
void visit_type_ChardevStdioList(Visitor *m, ChardevStdioList **obj, const char *name, Error **errp);

void visit_type_ChardevSpiceChannel(Visitor *m, ChardevSpiceChannel **obj, const char *name, Error **errp);
void visit_type_ChardevSpiceChannelList(Visitor *m, ChardevSpiceChannelList **obj, const char *name, Error **errp);

void visit_type_ChardevSpicePort(Visitor *m, ChardevSpicePort **obj, const char *name, Error **errp);
void visit_type_ChardevSpicePortList(Visitor *m, ChardevSpicePortList **obj, const char *name, Error **errp);

void visit_type_ChardevVC(Visitor *m, ChardevVC **obj, const char *name, Error **errp);
void visit_type_ChardevVCList(Visitor *m, ChardevVCList **obj, const char *name, Error **errp);

void visit_type_ChardevRingbuf(Visitor *m, ChardevRingbuf **obj, const char *name, Error **errp);
void visit_type_ChardevRingbufList(Visitor *m, ChardevRingbufList **obj, const char *name, Error **errp);

void visit_type_ChardevDummy(Visitor *m, ChardevDummy **obj, const char *name, Error **errp);
void visit_type_ChardevDummyList(Visitor *m, ChardevDummyList **obj, const char *name, Error **errp);

void visit_type_ChardevBackendKind(Visitor *m, ChardevBackendKind *obj, const char *name, Error **errp);

void visit_type_ChardevBackend(Visitor *m, ChardevBackend **obj, const char *name, Error **errp);
void visit_type_ChardevBackendList(Visitor *m, ChardevBackendList **obj, const char *name, Error **errp);

void visit_type_ChardevReturn(Visitor *m, ChardevReturn **obj, const char *name, Error **errp);
void visit_type_ChardevReturnList(Visitor *m, ChardevReturnList **obj, const char *name, Error **errp);

void visit_type_TpmModel(Visitor *m, TpmModel *obj, const char *name, Error **errp);
void visit_type_TpmModelList(Visitor *m, TpmModelList **obj, const char *name, Error **errp);

void visit_type_TpmType(Visitor *m, TpmType *obj, const char *name, Error **errp);
void visit_type_TpmTypeList(Visitor *m, TpmTypeList **obj, const char *name, Error **errp);

void visit_type_TPMPassthroughOptions(Visitor *m, TPMPassthroughOptions **obj, const char *name, Error **errp);
void visit_type_TPMPassthroughOptionsList(Visitor *m, TPMPassthroughOptionsList **obj, const char *name, Error **errp);

void visit_type_TpmTypeOptionsKind(Visitor *m, TpmTypeOptionsKind *obj, const char *name, Error **errp);

void visit_type_TpmTypeOptions(Visitor *m, TpmTypeOptions **obj, const char *name, Error **errp);
void visit_type_TpmTypeOptionsList(Visitor *m, TpmTypeOptionsList **obj, const char *name, Error **errp);

void visit_type_TPMInfo(Visitor *m, TPMInfo **obj, const char *name, Error **errp);
void visit_type_TPMInfoList(Visitor *m, TPMInfoList **obj, const char *name, Error **errp);

void visit_type_AcpiTableOptions(Visitor *m, AcpiTableOptions **obj, const char *name, Error **errp);
void visit_type_AcpiTableOptionsList(Visitor *m, AcpiTableOptionsList **obj, const char *name, Error **errp);

void visit_type_CommandLineParameterType(Visitor *m, CommandLineParameterType *obj, const char *name, Error **errp);
void visit_type_CommandLineParameterTypeList(Visitor *m, CommandLineParameterTypeList **obj, const char *name, Error **errp);

void visit_type_CommandLineParameterInfo(Visitor *m, CommandLineParameterInfo **obj, const char *name, Error **errp);
void visit_type_CommandLineParameterInfoList(Visitor *m, CommandLineParameterInfoList **obj, const char *name, Error **errp);

void visit_type_CommandLineOptionInfo(Visitor *m, CommandLineOptionInfo **obj, const char *name, Error **errp);
void visit_type_CommandLineOptionInfoList(Visitor *m, CommandLineOptionInfoList **obj, const char *name, Error **errp);

void visit_type_X86CPURegister32(Visitor *m, X86CPURegister32 *obj, const char *name, Error **errp);
void visit_type_X86CPURegister32List(Visitor *m, X86CPURegister32List **obj, const char *name, Error **errp);

void visit_type_X86CPUFeatureWordInfo(Visitor *m, X86CPUFeatureWordInfo **obj, const char *name, Error **errp);
void visit_type_X86CPUFeatureWordInfoList(Visitor *m, X86CPUFeatureWordInfoList **obj, const char *name, Error **errp);

void visit_type_RxState(Visitor *m, RxState *obj, const char *name, Error **errp);
void visit_type_RxStateList(Visitor *m, RxStateList **obj, const char *name, Error **errp);

void visit_type_RxFilterInfo(Visitor *m, RxFilterInfo **obj, const char *name, Error **errp);
void visit_type_RxFilterInfoList(Visitor *m, RxFilterInfoList **obj, const char *name, Error **errp);

void visit_type_InputButton(Visitor *m, InputButton *obj, const char *name, Error **errp);
void visit_type_InputButtonList(Visitor *m, InputButtonList **obj, const char *name, Error **errp);

void visit_type_InputAxis(Visitor *m, InputAxis *obj, const char *name, Error **errp);
void visit_type_InputAxisList(Visitor *m, InputAxisList **obj, const char *name, Error **errp);

void visit_type_InputKeyEvent(Visitor *m, InputKeyEvent **obj, const char *name, Error **errp);
void visit_type_InputKeyEventList(Visitor *m, InputKeyEventList **obj, const char *name, Error **errp);

void visit_type_InputBtnEvent(Visitor *m, InputBtnEvent **obj, const char *name, Error **errp);
void visit_type_InputBtnEventList(Visitor *m, InputBtnEventList **obj, const char *name, Error **errp);

void visit_type_InputMoveEvent(Visitor *m, InputMoveEvent **obj, const char *name, Error **errp);
void visit_type_InputMoveEventList(Visitor *m, InputMoveEventList **obj, const char *name, Error **errp);

void visit_type_InputEventKind(Visitor *m, InputEventKind *obj, const char *name, Error **errp);

void visit_type_InputEvent(Visitor *m, InputEvent **obj, const char *name, Error **errp);
void visit_type_InputEventList(Visitor *m, InputEventList **obj, const char *name, Error **errp);

void visit_type_NumaOptionsKind(Visitor *m, NumaOptionsKind *obj, const char *name, Error **errp);

void visit_type_NumaOptions(Visitor *m, NumaOptions **obj, const char *name, Error **errp);
void visit_type_NumaOptionsList(Visitor *m, NumaOptionsList **obj, const char *name, Error **errp);

void visit_type_NumaNodeOptions(Visitor *m, NumaNodeOptions **obj, const char *name, Error **errp);
void visit_type_NumaNodeOptionsList(Visitor *m, NumaNodeOptionsList **obj, const char *name, Error **errp);

void visit_type_HostMemPolicy(Visitor *m, HostMemPolicy *obj, const char *name, Error **errp);
void visit_type_HostMemPolicyList(Visitor *m, HostMemPolicyList **obj, const char *name, Error **errp);

void visit_type_Memdev(Visitor *m, Memdev **obj, const char *name, Error **errp);
void visit_type_MemdevList(Visitor *m, MemdevList **obj, const char *name, Error **errp);

void visit_type_PCDIMMDeviceInfo(Visitor *m, PCDIMMDeviceInfo **obj, const char *name, Error **errp);
void visit_type_PCDIMMDeviceInfoList(Visitor *m, PCDIMMDeviceInfoList **obj, const char *name, Error **errp);

void visit_type_MemoryDeviceInfoKind(Visitor *m, MemoryDeviceInfoKind *obj, const char *name, Error **errp);

void visit_type_MemoryDeviceInfo(Visitor *m, MemoryDeviceInfo **obj, const char *name, Error **errp);
void visit_type_MemoryDeviceInfoList(Visitor *m, MemoryDeviceInfoList **obj, const char *name, Error **errp);

void visit_type_ACPISlotType(Visitor *m, ACPISlotType *obj, const char *name, Error **errp);
void visit_type_ACPISlotTypeList(Visitor *m, ACPISlotTypeList **obj, const char *name, Error **errp);

void visit_type_ACPIOSTInfo(Visitor *m, ACPIOSTInfo **obj, const char *name, Error **errp);
void visit_type_ACPIOSTInfoList(Visitor *m, ACPIOSTInfoList **obj, const char *name, Error **errp);

void visit_type_WatchdogExpirationAction(Visitor *m, WatchdogExpirationAction *obj, const char *name, Error **errp);
void visit_type_WatchdogExpirationActionList(Visitor *m, WatchdogExpirationActionList **obj, const char *name, Error **errp);

void visit_type_IoOperationType(Visitor *m, IoOperationType *obj, const char *name, Error **errp);
void visit_type_IoOperationTypeList(Visitor *m, IoOperationTypeList **obj, const char *name, Error **errp);

void visit_type_GuestPanicAction(Visitor *m, GuestPanicAction *obj, const char *name, Error **errp);
void visit_type_GuestPanicActionList(Visitor *m, GuestPanicActionList **obj, const char *name, Error **errp);

void visit_type_RockerSwitch(Visitor *m, RockerSwitch **obj, const char *name, Error **errp);
void visit_type_RockerSwitchList(Visitor *m, RockerSwitchList **obj, const char *name, Error **errp);

void visit_type_RockerPortDuplex(Visitor *m, RockerPortDuplex *obj, const char *name, Error **errp);
void visit_type_RockerPortDuplexList(Visitor *m, RockerPortDuplexList **obj, const char *name, Error **errp);

void visit_type_RockerPortAutoneg(Visitor *m, RockerPortAutoneg *obj, const char *name, Error **errp);
void visit_type_RockerPortAutonegList(Visitor *m, RockerPortAutonegList **obj, const char *name, Error **errp);

void visit_type_RockerPort(Visitor *m, RockerPort **obj, const char *name, Error **errp);
void visit_type_RockerPortList(Visitor *m, RockerPortList **obj, const char *name, Error **errp);

void visit_type_RockerOfDpaFlowKey(Visitor *m, RockerOfDpaFlowKey **obj, const char *name, Error **errp);
void visit_type_RockerOfDpaFlowKeyList(Visitor *m, RockerOfDpaFlowKeyList **obj, const char *name, Error **errp);

void visit_type_RockerOfDpaFlowMask(Visitor *m, RockerOfDpaFlowMask **obj, const char *name, Error **errp);
void visit_type_RockerOfDpaFlowMaskList(Visitor *m, RockerOfDpaFlowMaskList **obj, const char *name, Error **errp);

void visit_type_RockerOfDpaFlowAction(Visitor *m, RockerOfDpaFlowAction **obj, const char *name, Error **errp);
void visit_type_RockerOfDpaFlowActionList(Visitor *m, RockerOfDpaFlowActionList **obj, const char *name, Error **errp);

void visit_type_RockerOfDpaFlow(Visitor *m, RockerOfDpaFlow **obj, const char *name, Error **errp);
void visit_type_RockerOfDpaFlowList(Visitor *m, RockerOfDpaFlowList **obj, const char *name, Error **errp);

void visit_type_RockerOfDpaGroup(Visitor *m, RockerOfDpaGroup **obj, const char *name, Error **errp);
void visit_type_RockerOfDpaGroupList(Visitor *m, RockerOfDpaGroupList **obj, const char *name, Error **errp);

#endif
