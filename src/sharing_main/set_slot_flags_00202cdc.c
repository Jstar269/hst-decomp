/* HSTMATCH module=hstp_trans_main.prx start=0x00202cdc end=0x00202d34 symbol=FUN_00202cdc lang=c99 */
/* Clone of src/eboot/set_slot_flags_001f474c.c (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Sub { char pad0[0x58]; void *f58; } Sub;

typedef struct {
  char pad00[0x3a0];
  void * volatile f3a0[4];
  char pad3b0[0x3e4 - 0x3b0];
  unsigned char f3e4[4];
} Obj;

void FUN_00202cdc(Obj *self, int id)
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
