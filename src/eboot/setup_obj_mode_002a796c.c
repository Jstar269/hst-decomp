/* HSTMATCH module=EBOOT.BIN start=0x002a796c end=0x002a79fc symbol=FUN_002a796c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py) corrected by hand: struct offsets +0x1668/+0x166c/+0x1670 on the receiver, signed global compare, and the global address computed before the two zero stores; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00001668;
extern u8 DAT_0000166c;
extern u8 DAT_00001670;
extern int DAT_00301c90;
extern int DAT_003415a8;
extern void FUN_002a734c();
extern void FUN_002a761c();
extern u32 FUN_002af274();

void FUN_002a796c(int param_1)
{
  char *addr;
  int local;
  int val;
  int *p;
  int obj;

  addr = (char *)DAT_003415a8 + 0x87128;
  *(int *)(param_1 + 0x1668) = 0;
  *(int *)(param_1 + 0x166c) = 0;
  local = FUN_002af274(addr);
  p = (DAT_00301c90 < local) ? &local : &DAT_00301c90;
  val = *p;
  *(int *)(param_1 + 0x1670) = val;
  obj = *(int *)(param_1 + 0x35c);
  *(int *)(obj + 0xd8) = val;
  *(int *)(obj + 0xdc) = 0xc;
  FUN_002a734c(param_1);
  FUN_002a761c(param_1);
}
