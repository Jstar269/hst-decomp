/* HSTMATCH module=EBOOT.BIN start=0x001c7cb4 end=0x001c7d30 symbol=FUN_001c7cb4 lang=c99 data=0x002ea9e4 */
/* Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0201_001c7cb4_m04.c), corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ea9e4-0x002eaa11) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern void FUN_000104e0();
extern void FUN_000143b0();
extern u32 FUN_0004cad0();
extern void FUN_00127308();

/* Loads the lobby's motion list file; when use_index is nonzero also passes index - 1 on to a consumer. Returns use_index. */
int FUN_001c7cb4(u32 unused,u32 lobby,int index,int use_index,u32 extra1, u32 extra2,u32 extra3,u32 extra4)
{
  u32 data;
  char path [128];
  int size;
  
  FUN_000143b0(path,"data/script/script_bin/lobby%02d/motlist.mld",lobby,use_index,extra1,
               extra2,extra3,extra4);
  data = FUN_0004cad0(path,&size,0x10,1);
  if (use_index != 0) {
    FUN_00127308(data,index - 1);
  }
  FUN_000104e0(data);
  return use_index;
}
