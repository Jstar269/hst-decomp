/* HSTMATCH module=hstp_trans_main.prx start=0x001a4bcc end=0x001a4c58 symbol=FUN_001a4bcc lang=c99 data=0x00388f88 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00388f88-0x00388f8e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern char DAT_00388f14[];
extern char DAT_00388f48[];
extern void FUN_001a33a4();
extern void FUN_001a4184();
extern void FUN_001a49ec();

int FUN_001a4bcc(u32 param_1,u32 param_2,u32 param_3,int param_4)
{
  u8 auStack_400 [1024];
  
  if (param_4 == 0) {
    FUN_001a33a4(DAT_00388f14,"p_dst",
                 DAT_00388f48,0x603);
    do {
                    
    } while( true );
  }
  FUN_001a49ec(param_1,param_2,auStack_400);
  FUN_001a4184(param_1,auStack_400,0,0,param_3,param_4);
  return param_4;
}
