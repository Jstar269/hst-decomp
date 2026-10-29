/* HSTMATCH module=EBOOT.BIN start=0x00137840 end=0x0013788c symbol=FUN_00137840 lang=c99 data=0x002db990 */
/* CourtMgr_LoadAreaClip: data/court/<name>/setting/cNN_areaclip.csv; see docs/DATA-TABLES.md Data: its string literals (1 strings, 0x002db990-0x002db9b9) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/court.h"

extern u32 DAT_003402a4;
extern void FUN_000143b0();
extern void FUN_001415e8();

void FUN_00137840(Court *court)
{
  u8 path[256];
  
  FUN_000143b0(path,"data/court/%s/setting/c%02d_areaclip.csv",DAT_003402a4,
               court->mode);
  FUN_001415e8(&court->vptr1,0,path);
}
