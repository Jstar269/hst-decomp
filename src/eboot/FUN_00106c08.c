/* HSTMATCH module=EBOOT.BIN start=0x00106c08 end=0x00106c18 symbol=FUN_00106c08 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c1094;
extern void FUN_001006dc();

/* Forward to the two-path loader with a fixed second name. */
void FUN_00106c08(int self,u32 *path,u32 arg)
{
  FUN_001006dc(self,path,(u32 *)&DAT_002c1094,arg);
}
