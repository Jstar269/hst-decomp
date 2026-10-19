/* HSTMATCH module=EBOOT.BIN start=0x001cd30c end=0x001cd354 symbol=FUN_001cd30c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  char pad0[0x4c];
  void **items;
  unsigned count;
  char pad1[0x94];
  int idx;
} Self;

void *FUN_001cd30c(Self *self)
{
  void *p;
  void *r;

  if (0 <= self->idx && self->idx < self->count && (p = self->items[self->idx]) != 0)
    r = p;
  else
    r = 0;
  return r;
}
