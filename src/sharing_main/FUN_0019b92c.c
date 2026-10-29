/* HSTMATCH module=hstp_trans_main.prx start=0x0019b92c end=0x0019b98c symbol=FUN_0019b92c lang=c99 */
/* Clone of src/eboot/FUN_0018f14c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Obj {
  char pad00[0xc];
  char member[4];   /* 0x0c, destroyed with flag -1 */
} Obj;

extern void FUN_00000a00();
extern int FUN_00004138();
extern u32 * FUN_000463a0();

/* Deleting destructor: destroys the member at 0x0c, runs the base destructor, frees the object when delete_flag > 0. */
Obj * FUN_0019b92c(Obj *self,short delete_flag)
{
  if (self != 0) {
    FUN_000463a0(self->member,0xffffffff);
    FUN_00004138(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
