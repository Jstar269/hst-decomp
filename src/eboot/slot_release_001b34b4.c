/* HSTMATCH module=EBOOT.BIN start=0x001b34b4 end=0x001b3538 symbol=FUN_001b34b4 lang=c99 */
/* Clone of src/sharing_main/slot_release_001c189c.c (hstclone.py tag u6cr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Obj {
  char pad[0x7a8];
  int idx;
} Obj;

extern void FUN_00062418(int, int);

static inline int HasSlot(Obj *self)
{
  int index = self->idx + 0xb4;
  int ok = index < 0x1da;
  if (!ok) return ok;
  return *(int *)((char *)self + index * 4) != 0;
}

void FUN_001b34b4(Obj **param_1)
{
  Obj *self = *param_1;
  if (self->idx < 0) return;
  if (HasSlot(self)) {
    int index = self->idx + 0xb4;
    int *slot = (int *)((char *)self + index * 4);
    int value = *slot;
    if (value != 0) {
      FUN_00062418(value, 1);
      *slot = 0;
    }
  }
  self->idx = -1;
}
