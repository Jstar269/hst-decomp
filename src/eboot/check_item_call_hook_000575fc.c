/* HSTMATCH module=EBOOT.BIN start=0x000575fc end=0x00057648 symbol=FUN_000575fc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Range-checks an index against the object's item count (member +0xe4) and, when the item pointer at
   base +0xe0 + index*4 is non-null, calls FUN_000562d8(item, member +0x8c, flag). The third parameter is
   only forwarded, which is why the callee's third argument (a2) is never set up here and the "this"
   pointer is copied into a3 instead of a2. Names provisional. */
extern void FUN_000562d8(void *, int, unsigned char);

typedef struct {
  int pad[0x23];
  int f8c;
  int pad2[0x14];
  void **fE0;
  unsigned fE4;
} Obj;

void FUN_000575fc(Obj *self, int index, unsigned char flag)
{
  if (index >= 0 && (unsigned)index < self->fE4) {
    void *item = self->fE0[index];
    if (item != 0) {
      FUN_000562d8(item, self->f8c, flag);
    }
  }
}
