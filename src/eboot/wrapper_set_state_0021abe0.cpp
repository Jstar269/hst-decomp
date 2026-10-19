/* HSTMATCH module=EBOOT.BIN start=0x0021abe0 end=0x0021acb4 symbol=FUN_0021abe0 lang=c++ rodata=0x002c9908 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: the slot-3 call is a C++ virtual method (dispatch at vtable +0x0c, so the class declares two virtuals) and the switch lists all 19 states, which is what makes MWCC emit retail's jump table; exact match verified; names and types await human review. */

extern "C" int *DAT_003415ac;
extern "C" void FUN_0010b8cc(int a, int b, int c);
extern "C" void FUN_00114168(void *a, int b, void *c, int d, int e);
extern "C" void *FUN_001fea10(int a, int b, int c);

struct Obj {
  virtual void Release();
  virtual void Activate();
};

struct Wrapper {
  Obj *target;
  int state;
};

extern "C" void FUN_0021abe0(Wrapper *self, int mode)
{
  int r = -1;

  self->state = mode;
  switch (mode) {
  case 0:
    self->target->Activate();
    break;
  case 1: case 2: case 3: case 4: case 5:
    break;
  case 7: case 13: r = 0; break;
  case 8: case 9: case 10: case 11: case 12:
    break;
  case 14: case 15: case 16: case 17:
    break;
  case 18: r = 1; break;
  case 6: r = 1; break;
  }
  if (r < 0)
    return;
  FUN_00114168(DAT_003415ac, 1, FUN_001fea10(17, 8, r), 0, 0);
  if (r == 1)
    FUN_0010b8cc(**(int **)((char *)DAT_003415ac + 0x58), 0, 0);
}
