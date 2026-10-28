/* HSTMATCH module=hstp_trans_main.prx start=0x00102320 end=0x00102388 symbol=FUN_00102320 lang=c99 data=0x0037f1a0 */
/* Clone of src/eboot/FUN_000fcbe4.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037f1a0-0x0037f1c8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: the propagated default constant undone and the strength-reduced sizes written as multiplies; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e39a4;
extern u32 DAT_003e39ac;
extern int FUN_00000a90();
extern int FUN_000104b0();
extern void FUN_00102388();

void FUN_00102320(int param_1)
{
  if (param_1 == 0) {
    param_1 = 0xa8c;
  }
  DAT_003e39a4 = FUN_000104b0(param_1 * 0x14 + 0x18);
  DAT_003e39ac = FUN_00000a90(param_1 * 4);
  FUN_00102388("GameData::CreateFileTable(): size = %u\n",param_1);
}
