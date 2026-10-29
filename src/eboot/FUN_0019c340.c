/* HSTMATCH module=EBOOT.BIN start=0x0019c340 end=0x0019c384 symbol=FUN_0019c340 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/save_task.h"

extern u8 DAT_00309250;
extern void *DAT_003415d4; /* save menu */
extern u32 * FUN_0001f06c();
extern void FUN_001905b8();

/* Constructor: run the base constructor, set the vtable, then call FUN_001905b8 on the save menu with 1. */
SaveTask * FUN_0019c340(SaveTask *self)
{
  FUN_0001f06c();
  self->vtable = &DAT_00309250;
  FUN_001905b8(DAT_003415d4,1);
  return self;
}
