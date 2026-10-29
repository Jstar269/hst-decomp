/* HSTMATCH module=EBOOT.BIN start=0x0021aa34 end=0x0021aa6c symbol=FUN_0021aa34 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

extern void FUN_0021aabc();
extern void FUN_0021abe0();

/* Constructor of the state holder: clears the menu pointer and enters state 11. */
SelectionState * FUN_0021aa34(SelectionState *self)
{
  self->menu = 0;
  FUN_0021aabc();
  FUN_0021abe0(self,0xb);
  return self;
}
