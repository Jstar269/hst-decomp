/* HSTMATCH module=EBOOT.BIN start=0x000f5c6c end=0x000f5cd8 symbol=FUN_000f5c6c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define ELEM_SIZE 0x48
#define ELEM_COUNT 2

/* Object holding an inline array of ELEM_COUNT sub-objects after its vtable. */
typedef struct ArrayHolder {
  const void *vtable;                    /* 0x00 */
  char elems[ELEM_COUNT][ELEM_SIZE];     /* 0x04 */
} ArrayHolder;

extern u8 DAT_003077e0;
extern void FUN_00000788();
extern void FUN_00000a00();
extern void FUN_000510c0();

/* Deleting destructor: sets the vtable, destroys the element array, frees the object when delete_flag > 0. */
ArrayHolder * FUN_000f5c6c(ArrayHolder *self,short delete_flag)
{
  if (self != (ArrayHolder *)0x0) {
    self->vtable = &DAT_003077e0;
    FUN_00000788(self->elems,FUN_000510c0,ELEM_SIZE,ELEM_COUNT);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
