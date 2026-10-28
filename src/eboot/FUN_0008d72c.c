/* HSTMATCH module=EBOOT.BIN start=0x0008d72c end=0x0008d7b0 symbol=FUN_0008d72c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00(void *);
extern int FUN_000d7e30(void *, int);

/* Three 0x120-byte sub-objects, each with the base destructor FUN_000d7e30. */
typedef struct Sub120 {
  char pad[0x120];
} Sub120;

typedef struct TripleHolder {
  char pad00[0x40];
  Sub120 sub[3]; /* 0x40 */
} TripleHolder;

/* Deleting destructor: destroys the three sub-objects in reverse order, frees the object when flags > 0. */
TripleHolder *FUN_0008d72c(TripleHolder *self, short flags)
{
  if (self != 0) {
    if (&self->sub[2] != 0) {
      FUN_000d7e30(&self->sub[2], -1);
    }
    if (&self->sub[1] != 0) {
      FUN_000d7e30(&self->sub[1], -1);
    }
    if (&self->sub[0] != 0) {
      FUN_000d7e30(&self->sub[0], -1);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
