/* HSTMATCH module=EBOOT.BIN start=0x0011bba0 end=0x0011bc2c symbol=FUN_0011bba0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the cleared flag global DAT_0033b488 typed as a byte; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030702c;
extern u8 DAT_00307fc4;
extern unsigned char DAT_0033b488;
extern u32 DAT_0033b48c;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern u32 * FUN_0005a410();

/* Object with a vtable pointer and an embedded sub-object that has its own vtable pointer. */
typedef struct SubObj {
  const void *vtable;     /* 0x0 */
} SubObj;

typedef struct ObjWithSub {
  const void *vtable;     /* 0x00 */
  char pad04[0x3c];
  SubObj sub;             /* 0x40 */
} ObjWithSub;

/* Deleting destructor: resets two shared globals, destroys the sub-object and the base, and frees the object
   when flag > 0. */
ObjWithSub * FUN_0011bba0(ObjWithSub *self,short flag)
{
  if (self != (ObjWithSub *)0x0) {
    self->vtable = &DAT_00307fc4;
    DAT_0033b488 = 0;
    DAT_0033b48c = 0;
    if (&self->sub != (SubObj *)0x0) {
      self->sub.vtable = &DAT_0030702c;
      FUN_0005a410(&self->sub,0);
    }
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
