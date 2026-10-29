/* HSTMATCH module=EBOOT.BIN start=0x001a57d0 end=0x001a5808 symbol=FUN_001a57d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001aedc8();
extern void FUN_001bae28();

typedef struct CountedObj {
  char pad00[0x3c];
  int count;       /* 0x3c */
  char pad40[0x68 - 0x40];
  char sub[0x20];  /* 0x68 embedded sub-object */
  u32 handle;      /* 0x88 */
} CountedObj;

/* When count is positive, run the sub-object step and the handle step. */
void FUN_001a57d0(CountedObj *self)
{
  if (0 < self->count) {
    FUN_001aedc8(self->sub);
    FUN_001bae28(self->handle);
  }
}
