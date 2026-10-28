/* HSTMATCH module=hstp_trans_main.prx start=0x0008eec4 end=0x0008ef48 symbol=FUN_0008eec4 lang=c99 */
/* Clone of src/eboot/FUN_0008d72c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00(void *);
extern int FUN_000dbb20(void *, int);

/* Three 0x120-byte sub-objects, each with the base destructor FUN_000dbb20. */
typedef struct Sub120 {
  char pad[0x120];
} Sub120;

typedef struct TripleHolder {
  char pad00[0x40];
  Sub120 sub[3]; /* 0x40 */
} TripleHolder;

/* Deleting destructor: destroys the three sub-objects in reverse order, frees the object when flags > 0. */
TripleHolder *FUN_0008eec4(TripleHolder *self, short flags)
{
  if (self != 0) {
    if (&self->sub[2] != 0) {
      FUN_000dbb20(&self->sub[2], -1);
    }
    if (&self->sub[1] != 0) {
      FUN_000dbb20(&self->sub[1], -1);
    }
    if (&self->sub[0] != 0) {
      FUN_000dbb20(&self->sub[0], -1);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
