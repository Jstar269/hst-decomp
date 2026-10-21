/* HSTMATCH module=hstp_trans_main.prx start=0x0022a154 end=0x0022a228 symbol=FUN_0022a154 lang=c++ rodata=0x002d9ec8 */
/* Clone of src/eboot/wrapper_set_state_0021abe0.cpp (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: the slot-3 call is a C++ virtual method (dispatch at vtable +0x0c, so the class declares two virtuals) and the switch lists all 19 states, which is what makes MWCC emit retail's jump table; exact match verified; names and types await human review. */

extern "C" int *DAT_003ea8ec;
extern "C" void FUN_00111aa4(int a, int b, int c);
extern "C" void FUN_0011e940(void *a, int b, void *c, int d, int e);
extern "C" void *FUN_0020d1e0(int a, int b, int c);

struct Obj {
  virtual void Release();
  virtual void Activate();
};

struct Wrapper {
  Obj *target;
  int state;
};

extern "C" void FUN_0022a154(Wrapper *self, int mode)
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
  FUN_0011e940(DAT_003ea8ec, 1, FUN_0020d1e0(17, 8, r), 0, 0);
  if (r == 1)
    FUN_00111aa4(**(int **)((char *)DAT_003ea8ec + 0x58), 0, 0);
}
