/* HSTMATCH module=hstp_trans_main.prx start=0x00094f28 end=0x00094f98 symbol=FUN_00094f28 lang=c99 data=0x00378d00 */
/* Clone of src/eboot/FUN_00093094.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00378d00-0x00378d11) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_002ceac4; /* one letter per kind, indexed by kind */
extern void FUN_000143b0(); /* sprintf-style formatter */

/* Build the two name prefixes for entry id: "NNN_f_" into front_buf and "NNN_<letter>_" into kind_buf. */
void FUN_00094f28(u32 unused,char *front_buf,char *kind_buf,int id,int kind)
{
  FUN_000143b0(front_buf,"%03d_f_",id);
  FUN_000143b0(kind_buf,"%03d_%c_",id,(int)(char)(&DAT_002ceac4)[kind]);
}
