/* HSTMATCH module=hstp_trans_main.prx start=0x00058250 end=0x0005829c symbol=FUN_00058250 lang=c99 */
/* Clone of src/eboot/check_item_call_hook_000575fc.c (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Range-checks an index against the object's item count (member +0xe4) and, when the item pointer at
   base +0xe0 + index*4 is non-null, calls FUN_00056eec(item, member +0x8c, flag). The third parameter is
   only forwarded, which is why the callee's third argument (a2) is never set up here and the "this"
   pointer is copied into a3 instead of a2. Names provisional. */
extern void FUN_00056eec(void *, int, unsigned char);

typedef struct {
  int pad[0x23];
  int f8c;
  int pad2[0x14];
  void **fE0;
  unsigned fE4;
} Obj;

void FUN_00058250(Obj *self, int index, unsigned char flag)
{
  if (index >= 0 && (unsigned)index < self->fE4) {
    void *item = self->fE0[index];
    if (item != 0) {
      FUN_00056eec(item, self->f8c, flag);
    }
  }
}
