/* HSTMATCH module=hstp_trans_main.prx start=0x000fb360 end=0x000fb3cc symbol=FUN_000fb360 lang=c99 */
/* Clone of src/eboot/FUN_000f5c6c.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

#define ELEM_SIZE 0x48
#define ELEM_COUNT 2

/* Object holding an inline array of ELEM_COUNT sub-objects after its vtable. */
typedef struct ArrayHolder {
  const void *vtable;                    /* 0x00 */
  char elems[ELEM_COUNT][ELEM_SIZE];     /* 0x04 */
} ArrayHolder;

extern u8 DAT_003b0aac;
extern void FUN_00000788();
extern void FUN_00000a00();
extern void FUN_000519d4();

/* Deleting destructor: sets the vtable, destroys the element array, frees the object when delete_flag > 0. */
ArrayHolder * FUN_000fb360(ArrayHolder *self,short delete_flag)
{
  if (self != (ArrayHolder *)0x0) {
    self->vtable = &DAT_003b0aac;
    FUN_00000788(self->elems,FUN_000519d4,ELEM_SIZE,ELEM_COUNT);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
