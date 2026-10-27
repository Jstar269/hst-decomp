/* HSTMATCH module=EBOOT.BIN start=0x001bed48 end=0x001bee20 symbol=FUN_001bed48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* For each of the 640 kind-2 objects of the manager DAT_00338b08 (FUN_000d8c24 lookup): clear the object's byte at
   +0xacc + index, then, for an existing object with a non-negative state byte, call FUN_001bf980(self, index, 5) when
   `all` is set, when the state is 1, or when FUN_001bb944(self, 2, index) accepts it. Names provisional. */
struct Obj {
  char pad[0x60];
  signed char state;
};
struct Self {
  char pad[0xacc];
  unsigned char marks[640];
};
extern "C" {
extern void *DAT_00338b08;
Obj *FUN_000d8c24(void *mgr, int kind, int index);
void FUN_001bf980(Self *self, int index, int mode);
int FUN_001bb944(Self *self, int kind, int index);
}

extern "C" void FUN_001bed48(Self *self, int all)
{
  for (int i = 0; i < 640; i++) {
    Obj *o = FUN_000d8c24(DAT_00338b08, 2, i);
    self->marks[i] = 0;
    if (o != 0 && o->state >= 0) {
      if (all) {
        FUN_001bf980(self, i, 5);
      } else if (o->state == 1) {
        FUN_001bf980(self, i, 5);
      } else if (FUN_001bb944(self, 2, i)) {
        FUN_001bf980(self, i, 5);
      }
    }
  }
}
