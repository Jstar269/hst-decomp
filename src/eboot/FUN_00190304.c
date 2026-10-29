/* HSTMATCH module=EBOOT.BIN start=0x00190304 end=0x00190348 symbol=FUN_00190304 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object with an embedded sub-object at 0x3c. */
typedef struct HostObj {
  const void *vtable;   /* 0x00 */
  char pad04[0x3c - 4];
  char sub3c[1];        /* 0x3c */
} HostObj;

extern u8 DAT_00309194;
extern u32 * FUN_0001f06c();
extern void FUN_00198df0();
extern void FUN_00198eb4();

/* Constructor: base setup, vtable, then the embedded sub-object and the object's own setup. */
HostObj * FUN_00190304(HostObj *self)
{
  FUN_0001f06c();
  self->vtable = &DAT_00309194;
  FUN_00198df0(self->sub3c);
  FUN_00198eb4(self);
  return self;
}
