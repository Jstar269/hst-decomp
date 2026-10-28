/* HSTMATCH module=hstp_trans_main.prx start=0x001269c4 end=0x00126b40 symbol=FUN_001269c4 lang=c99 */
/* Clone of src/eboot/FUN_0011b7f0.c (hstclone.py tag ds1018ar1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_003e47c8;

extern void FUN_0001ef14();
extern void FUN_00127f1c();

typedef struct {
  int x;
  int y;
  float z;
} Entry;

typedef struct {
  u32 count;
  int pad;
  u32 a;
  Entry **rows;
  u32 b;
  int flag;
} Slot;

typedef struct {
  char pad0[0x3c];
  char *obj;
  char pad1[0x70];
  int b0;
  int b4;
  float b8;
  int bc;
  int c0;
  float c4;
  char pad2[4];
  int cc;
} Self;

void FUN_001269c4(Self *self)
{
  int n = self->cc - 1;
  self->cc = n;
  if (n >= 1) {
    return;
  }
  Slot *s = (Slot *)(self->obj + 0x2f8);
  if (s->flag != 0) {
    Entry *e = (Entry *)((char *)s->rows[(s->a + s->b / 0x2a) % s->count] + (s->b % 0x2a) * 0xc);
    self->b0 = e->x;
    self->b4 = e->y;
    self->b8 = e->z;
    FUN_00127f1c(s);
    if (s->flag != 0) {
      Entry *e2 = (Entry *)((char *)s->rows[(s->a + s->b / 0x2a) % s->count] + (s->b % 0x2a) * 0xc);
      self->bc = e2->x;
      self->c0 = e2->y;
      self->c4 = e2->z;
      FUN_00127f1c(s);
    }
    else {
      self->c0 = 0;
    }
    self->cc = 0x2d;
  }
  else {
    FUN_0001ef14(self, 0);
    DAT_003e47c8 = 0;
  }
}
