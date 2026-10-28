/* HSTMATCH module=hstp_trans_main.prx start=0x00094f28 end=0x00094f98 symbol=FUN_00094f28 lang=c99 data=0x00378d00 */
/* Clone of src/eboot/FUN_00093094.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00378d00-0x00378d11) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_002ceac4;
extern void FUN_000143b0();

void FUN_00094f28(u32 param_1,u32 param_2,u32 param_3,u32 param_4, int param_5)
{
  FUN_000143b0(param_2,"%03d_f_",param_4);
  FUN_000143b0(param_3,"%03d_%c_",param_4,(int)(char)(&DAT_002ceac4)[param_5]);
}
