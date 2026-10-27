/* HSTMATCH module=hstp_trans_main.prx start=0x001cca9c end=0x001ccb74 symbol=FUN_001cca9c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* For each of the 640 kind-2 objects of the manager DAT_003e1e48 (FUN_000dca74 lookup): clear the object's byte at
   +0xacc + index, then, for an existing object with a non-negative state byte, call FUN_001cd780(self, index, 5) when
   `all` is set, when the state is 1, or when FUN_001c972c(self, 2, index) accepts it. Names provisional. */
struct Obj {
  char pad[0x60];
  signed char state;
};
struct Self {
  char pad[0xacc];
  unsigned char marks[640];
};
extern "C" {
extern void *DAT_003e1e48;
Obj *FUN_000dca74(void *mgr, int kind, int index);
void FUN_001cd780(Self *self, int index, int mode);
int FUN_001c972c(Self *self, int kind, int index);
}

extern "C" void FUN_001cca9c(Self *self, int all)
{
  for (int i = 0; i < 640; i++) {
    Obj *o = FUN_000dca74(DAT_003e1e48, 2, i);
    self->marks[i] = 0;
    if (o != 0 && o->state >= 0) {
      if (all) {
        FUN_001cd780(self, i, 5);
      } else if (o->state == 1) {
        FUN_001cd780(self, i, 5);
      } else if (FUN_001c972c(self, 2, i)) {
        FUN_001cd780(self, i, 5);
      }
    }
  }
}
