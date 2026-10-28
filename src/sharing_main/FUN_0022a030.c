/* HSTMATCH module=hstp_trans_main.prx start=0x0022a030 end=0x0022a074 symbol=FUN_0022a030 lang=c99 */
/* Clone of src/eboot/FUN_0021aabc.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: retained and passed the allocated pointer through initialization before one shared store; exact match verified; names and types await human review. */
#include "hst/types.h"
extern u32 *FUN_00000bcc(int);
extern u32 *FUN_002294b8(u32 *);
void FUN_0022a030(u32 **param_1)
{
  u32 *p;
  p = FUN_00000bcc(0x114);
  if (p != 0) p = FUN_002294b8(p);
  *param_1 = p;
}