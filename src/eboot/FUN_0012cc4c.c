/* HSTMATCH module=EBOOT.BIN start=0x0012cc4c end=0x0012ccd0 symbol=FUN_0012cc4c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Size of the temporary object built on the stack. */
#define TEMP_OBJ_SIZE 704

extern u8 DAT_00308108;
extern u8 DAT_00308124;
extern u32 DAT_003313c4;
extern u32 DAT_0033b574; /* the one live instance */
extern int FUN_0005b670();
extern int FUN_0005ba00();
extern int FUN_0005ba78();
extern u32 * FUN_0013fb58();
extern u32 * FUN_00286790();

/* Constructor: builds the base and the member (word offset 0x4c8), sets both vtables, clears four words, records
   the instance, and hands a temporary object to the shared registry before destroying it. */
u32 * FUN_0012cc4c(u32 *self)
{
  u8 temp_obj [TEMP_OBJ_SIZE];
  
  FUN_0013fb58();
  FUN_00286790(self + 0x4c8);
  *self = (unsigned int)(&DAT_00308108);
  self[0x4c8] = (unsigned int)(&DAT_00308124);
  self[0x4e4] = 0;
  self[0x4e5] = 0;
  self[0x4e6] = 0;
  self[0x4e7] = 0;
  DAT_0033b574 = (unsigned int)(self);
  FUN_0005b670(temp_obj);
  FUN_0005ba78(DAT_003313c4,temp_obj);
  FUN_0005ba00(temp_obj,0xffffffff);
  return self;
}
