/* HSTMATCH module=hstp_trans_main.prx start=0x001d6148 end=0x001d61c4 symbol=FUN_001d6148 lang=c99 data=0x00392740 */
/* Clone of src/eboot/FUN_001c7cb4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00392740-0x0039276d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern void FUN_000104e0();
extern void FUN_000143b0();
extern u32 FUN_0004cd8c();
extern void FUN_00132578();

/* Loads the lobby's motion list file; when use_index is nonzero also passes index - 1 on to a consumer. Returns use_index. */
int FUN_001d6148(u32 unused,u32 lobby,int index,int use_index,u32 extra1, u32 extra2,u32 extra3,u32 extra4)
{
  u32 data;
  char path [128];
  int size;
  
  FUN_000143b0(path,"data/script/script_bin/lobby%02d/motlist.mld",lobby,use_index,extra1,
               extra2,extra3,extra4);
  data = FUN_0004cd8c(path,&size,0x10,1);
  if (use_index != 0) {
    FUN_00132578(data,index - 1);
  }
  FUN_000104e0(data);
  return use_index;
}
