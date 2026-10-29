/* HSTMATCH module=EBOOT.BIN start=0x00093094 end=0x00093104 symbol=FUN_00093094 lang=c99 data=0x002d2a3c */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d2a3c-0x002d2a4d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_002beb34; /* one letter per kind, indexed by kind */
extern void FUN_000143b0(); /* sprintf-style formatter */

/* Build the two name prefixes for entry id: "NNN_f_" into front_buf and "NNN_<letter>_" into kind_buf. */
void FUN_00093094(u32 unused,char *front_buf,char *kind_buf,int id,int kind)
{
  FUN_000143b0(front_buf,"%03d_f_",id);
  FUN_000143b0(kind_buf,"%03d_%c_",id,(int)(char)(&DAT_002beb34)[kind]);
}
