/* HSTMATCH module=EBOOT.BIN start=0x00137840 end=0x0013788c symbol=FUN_00137840 lang=c99 data=0x002db990 */
/* CourtMgr_LoadAreaClip: data/court/<name>/setting/cNN_areaclip.csv; see docs/DATA-TABLES.md Data: its string literals (1 strings, 0x002db990-0x002db9b9) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003402a4;
extern void FUN_000143b0();
extern void FUN_001415e8();

void FUN_00137840(int param_1)
{
  u8 auStack_100 [256];
  
  FUN_000143b0(auStack_100,"data/court/%s/setting/c%02d_areaclip.csv",DAT_003402a4,
               *(u32 *)(param_1 + 0x1364));
  FUN_001415e8(param_1 + 0x40,0,auStack_100);
}
