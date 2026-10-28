/* HSTMATCH module=EBOOT.BIN start=0x0011b7f0 end=0x0011b96c symbol=FUN_0011b7f0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_0033b488;

extern void FUN_0001f1fc();
extern void FUN_0011cd48();

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

void FUN_0011b7f0(Self *self)
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
    FUN_0011cd48(s);
    if (s->flag != 0) {
      Entry *e2 = (Entry *)((char *)s->rows[(s->a + s->b / 0x2a) % s->count] + (s->b % 0x2a) * 0xc);
      self->bc = e2->x;
      self->c0 = e2->y;
      self->c4 = e2->z;
      FUN_0011cd48(s);
    }
    else {
      self->c0 = 0;
    }
    self->cc = 0x2d;
  }
  else {
    FUN_0001f1fc(self, 0);
    DAT_0033b488 = 0;
  }
}
