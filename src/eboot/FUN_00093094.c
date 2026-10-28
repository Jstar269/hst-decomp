/* HSTMATCH module=EBOOT.BIN start=0x00093094 end=0x00093104 symbol=FUN_00093094 lang=c99 data=0x002d2a3c */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d2a3c-0x002d2a4d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_002beb34;
extern void FUN_000143b0();

void FUN_00093094(u32 param_1,u32 param_2,u32 param_3,u32 param_4, int param_5)
{
  FUN_000143b0(param_2,"%03d_f_",param_4);
  FUN_000143b0(param_3,"%03d_%c_",param_4,(int)(char)(&DAT_002beb34)[param_5]);
}
