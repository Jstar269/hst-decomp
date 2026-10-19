/* HSTMATCH module=EBOOT.BIN start=0x002b7214 end=0x002b7258 symbol=FUN_002b7214 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef struct {
  char pad0[4];
  unsigned char *data;
  unsigned count;
} Self;

typedef struct {
  int a;
  signed char flag;
  char pad[3];
} Elem;

Elem *FUN_002b7214(Self *self, int idx)
{
  Elem *t;
  Elem *e;

  if (0 <= idx && idx < self->count && (t = (Elem *)(self->data + idx * 8))->flag >= 0)
    e = t;
  else
    e = 0;
  return e;
}
