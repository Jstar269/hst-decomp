/* HSTMATCH module=EBOOT.BIN start=0x0022c8d8 end=0x0022c928 symbol=FUN_0022c8d8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: put the set-bit path in the true arm and clear in the else arm. */
#include "hst/types.h"
#include "hst/entry_flags.h"

extern u32 DAT_003415a8;  /* address of the global system block */

/* Sets or clears flag C of the flag byte at `index` (the flag table starts 0xc200 into the block). */
void FUN_0022c8d8(int index,int enable)
{
  int addr;
  
  if (enable != 0) {
    addr = index + 0x8d00 + DAT_003415a8;
    *(u8 *)(addr + 0x3500) = *(u8 *)(addr + 0x3500) | ENTRY_FLAG_C;
  } else {
    addr = index + 0x8d00 + DAT_003415a8;
    *(u8 *)(addr + 0x3500) = *(u8 *)(addr + 0x3500) & 0xfb;
  }
}
