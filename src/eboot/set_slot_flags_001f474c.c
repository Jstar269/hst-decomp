/* HSTMATCH module=EBOOT.BIN start=0x001f474c end=0x001f47a4 symbol=FUN_001f474c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Sub { char pad0[0x58]; void *f58; } Sub;

typedef struct {
  char pad00[0x3a0];
  void * volatile f3a0[4];
  char pad3b0[0x3e4 - 0x3b0];
  unsigned char f3e4[4];
} Obj;

void FUN_001f474c(Obj *self, int id)
{
  int i;

  for (i = 0; i < 4; i++) {
    void *cur;
    /* matching idiom: the "id == 0" arm has to be the ELSE arm of the test so
       that mwccpsp emits the branch-likely that jumps to the shared check, and
       the slot pointer has to be read through a volatile so that the load is
       not CSE'd across the branch (retail reloads it). */
    if (id != 0) {
      if (id != (int)self->f3a0[i]) {
        continue;
      }
      cur = self->f3a0[i];
    } else {
      cur = self->f3a0[i];
    }
    {
      void *v = (cur != 0) ? ((Sub *)cur)->f58 : 0;
      if (v != 0) {
        self->f3e4[i] = 1;
      }
    }
  }
}
