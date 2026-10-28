/* HSTMATCH module=EBOOT.BIN start=0x000fcbe4 end=0x000fcc4c symbol=FUN_000fcbe4 lang=c99 data=0x002d8480 */
/* GameData::CreateFileTable(count): allocates the BDL index buffer (DAT_0033a664) and slot offset table (DAT_0033a66c); see docs/BDL-INDEX-FORMAT.md Data: its string literals (1 strings, 0x002d8480-0x002d84a8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: the propagated default constant undone and the strength-reduced sizes written as multiplies; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0033a664;
extern u32 DAT_0033a66c;
extern int FUN_00000a90();
extern int FUN_000104b0();
extern void FUN_000fcc4c();

void FUN_000fcbe4(int param_1)
{
  if (param_1 == 0) {
    param_1 = 0xa8c;
  }
  DAT_0033a664 = FUN_000104b0(param_1 * 0x14 + 0x18);
  DAT_0033a66c = FUN_00000a90(param_1 * 4);
  FUN_000fcc4c("GameData::CreateFileTable(): size = %u\n",param_1);
}
