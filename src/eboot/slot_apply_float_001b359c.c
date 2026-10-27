/* HSTMATCH module=EBOOT.BIN start=0x001b359c end=0x001b3640 symbol=FUN_001b359c lang=c99 */
/* Clone of src/sharing_main/slot_apply_float_001c1984.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (matching idiom: `#pragma opt_propagation off`, which keeps the constant slot index 0x5a in a register as retail's unfolded `li a0,90; slti v1,a0,474` and recomputed slot address; no source spelling found folds less without it); exact match verified; names and types await human review. */
#pragma opt_propagation off
typedef struct Obj {
  int slot[0x1da];
  char pad[0x7a4 - 0x768];
  int f7a4;
} Obj;

extern void FUN_00062990(int, float);

static inline int HasSlot(Obj *self, int index)
{
  int ok = index < 0x1da;
  if (!ok) return ok;
  return self->slot[index] != 0;
}

void FUN_001b359c(Obj **param_1, float value)
{
  Obj *self = *param_1;
  int index = 0x5a;
  if (HasSlot(self, index)) {
    FUN_00062990(self->slot[index], value);
  }
  index = self->f7a4 + 0x84;
  if (HasSlot(self, index)) {
    FUN_00062990(self->slot[index], value);
  }
}
