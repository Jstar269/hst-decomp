/* HSTMATCH module=EBOOT.BIN start=0x00125d38 end=0x00125d74 symbol=FUN_00125d38 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object built on the base class; only the vtable pointer and two cleared words are touched. */
typedef struct BaseDerived {
  const void *vtable; /* 0x00 */
  char pad04[0x8c];
  u32 unk90;          /* 0x90 */
  u32 unk94;          /* 0x94 */
} BaseDerived;

extern u8 DAT_00308018;
extern u32 * FUN_00060e2c();

/* Constructor: runs the base constructor, sets the vtable and clears the two trailing words. */
BaseDerived * FUN_00125d38(BaseDerived *self)
{
  FUN_00060e2c();
  self->vtable = &DAT_00308018;
  self->unk90 = 0;
  self->unk94 = 0;
  return self;
}
