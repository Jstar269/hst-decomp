/* HSTMATCH module=hstp_trans_main.prx start=0x001f4008 end=0x001f4054 symbol=FUN_001f4008 lang=c99 */
/* Clone of src/eboot/FUN_001e5df0.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: retained a separate advanced cursor for the indexed calls; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108558();

void FUN_001f4008(int param_1)
{
  int iVar1;
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: kept the advanced object cursor as the helper argument; exact match verified; names and types await human review. */
  int base;

  iVar1 = 0;
  base = param_1;
  do {
    *(u32 *)(*(int *)(base + 0x1d6c) + 0x60) = 0;
    FUN_00108558(*(u32 *)(base + 0x1d6c));
    iVar1 = iVar1 + 1;
    base = base + 4;
  } while (iVar1 < 5);
}
