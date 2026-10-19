/* HSTMATCH module=EBOOT.BIN start=0x0027edbc end=0x0027ee08 symbol=FUN_0027edbc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { char pad0[4]; unsigned char *data; unsigned count; } Self;
typedef struct { int a; short flag; char pad[0x28 - 6]; } Elem;

Elem *FUN_0027edbc(Self *self, int idx)
{
  Elem *t;
  Elem *r;

  if (0 <= idx && idx < self->count && (t = (Elem *)(self->data + idx * 0x28))->flag >= 0)
    r = t;
  else
    r = 0;
  return r;
}
