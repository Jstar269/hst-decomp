/* HSTMATCH module=hstp_trans_main.prx start=0x001b2d9c end=0x001b2dd4 symbol=FUN_001b2d9c lang=c99 */
/* Clone of src/eboot/FUN_001a57d0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001bc4a0();
extern void FUN_001c8b70();

typedef struct CountedObj {
  char pad00[0x3c];
  int count;       /* 0x3c */
  char pad40[0x68 - 0x40];
  char sub[0x20];  /* 0x68 embedded sub-object */
  u32 handle;      /* 0x88 */
} CountedObj;

/* When count is positive, run the sub-object step and the handle step. */
void FUN_001b2d9c(CountedObj *self)
{
  if (0 < self->count) {
    FUN_001bc4a0(self->sub);
    FUN_001c8b70(self->handle);
  }
}
