/* HSTMATCH module=EBOOT.BIN start=0x00261d70 end=0x00261e1c symbol=FUN_00261d70 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00102c54();

typedef struct Entry {
  char pad0[0x20];
  char sub[0x60];
  float f80;
  char pad84[0x6c];
} Entry;

typedef struct Self {
  Entry e[3];
  char pad2d0[8];
  int count;
} Self;

void FUN_00261d70(Self *self)
{
  unsigned int i;
  Entry *p;

  i = 0;
  p = self->e;
  do {
    if ((int)i >= 1 && self->count < 2) goto next;
    if ((int)i >= 2 && self->count < 4) goto next;
    p->f80 += -p->f80 * 0.5f;
    FUN_00102c54(p->sub);
next:
    p++;
  } while (++i < 3);
  self->count = self->count + 1;
}
