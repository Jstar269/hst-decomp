/* HSTMATCH module=EBOOT.BIN start=0x00095dd8 end=0x00095e10 symbol=FUN_00095dd8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000114c0();

/* Constructor of a 0x40-byte object: sets a field, then calls the fill routine (value 0, size 0x40). */
int FUN_00095dd8(int self)
{
  *(u32 *)(self + 0x2c) = 1;
  FUN_000114c0(self,0,0x40);
  return self;
}
