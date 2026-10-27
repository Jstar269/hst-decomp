/* HSTMATCH module=hstp_trans_main.prx start=0x001c1984 end=0x001c1a28 symbol=FUN_001c1984 lang=c99 */
/* Hand-written reconstruction from the disassembly (matching idiom: `#pragma opt_propagation off`, which keeps the constant slot index 0x5a in a register as retail's unfolded `li a0,90; slti v1,a0,474` and recomputed slot address; no source spelling found folds less without it); exact match verified; names and types await human review. */
#pragma opt_propagation off
typedef struct Obj {
  int slot[0x1da];
  char pad[0x7a4 - 0x768];
  int f7a4;
} Obj;

extern void FUN_00063854(int, float);

static inline int HasSlot(Obj *self, int index)
{
  int ok = index < 0x1da;
  if (!ok) return ok;
  return self->slot[index] != 0;
}

void FUN_001c1984(Obj **param_1, float value)
{
  Obj *self = *param_1;
  int index = 0x5a;
  if (HasSlot(self, index)) {
    FUN_00063854(self->slot[index], value);
  }
  index = self->f7a4 + 0x84;
  if (HasSlot(self, index)) {
    FUN_00063854(self->slot[index], value);
  }
}
