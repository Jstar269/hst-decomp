/* HSTMATCH module=EBOOT.BIN start=0x001fb374 end=0x001fb3bc symbol=FUN_001fb374 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Resets the panel: clears the two counters and sets the five eight-word cells to -1
   (the loop walks the object pointer itself, so the cell offsets stay literal). */
void FUN_001fb374(int panel)
{
  int word;
  
  *(u32 *)(panel + 0x1030) = 0;
  *(u32 *)(panel + 0x1034) = 0;
  word = 0;
  do {
    *(u32 *)(panel + 0xf90) = 0xffffffff;
    *(u32 *)(panel + 0xf94) = 0xffffffff;
    *(u32 *)(panel + 0xf98) = 0xffffffff;
    *(u32 *)(panel + 0xf9c) = 0xffffffff;
    *(u32 *)(panel + 0xfa0) = 0xffffffff;
    *(u32 *)(panel + 0xfa4) = 0xffffffff;
    *(u32 *)(panel + 0xfa8) = 0xffffffff;
    word = word + 8;
    *(u32 *)(panel + 0xfac) = 0xffffffff;
    panel = panel + 0x20;
  } while (word < 0x28);
}
