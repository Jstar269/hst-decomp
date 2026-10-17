/* HSTMATCH module=hstp_trans_main.prx start=0x001c189c end=0x001c1920 symbol=FUN_001c189c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Obj {
  char pad[0x7a8];
  int idx;
} Obj;

extern void FUN_00063304(int, int);

static inline int HasSlot(Obj *self)
{
  int index = self->idx + 0xb4;
  int ok = index < 0x1da;
  if (!ok) return ok;
  return *(int *)((char *)self + index * 4) != 0;
}

void FUN_001c189c(Obj **param_1)
{
  Obj *self = *param_1;
  if (self->idx < 0) return;
  if (HasSlot(self)) {
    int index = self->idx + 0xb4;
    int *slot = (int *)((char *)self + index * 4);
    int value = *slot;
    if (value != 0) {
      FUN_00063304(value, 1);
      *slot = 0;
    }
  }
  self->idx = -1;
}
