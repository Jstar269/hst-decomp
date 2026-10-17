/* HSTMATCH module=EBOOT.BIN start=0x002249dc end=0x00224a28 symbol=FUN_002249dc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC {
  virtual void slot0();
  virtual void slot1();
  virtual void slot2();
  virtual void slot3();
};

struct Obj {
  char pad0[0x54];
  unsigned char flag;
  char pad1[0x33];
  VC *member;
};

extern "C" void FUN_001031e8(Obj *);

extern "C" void FUN_002249dc(Obj *self)
{
  if (self->flag == 0) {
    FUN_001031e8(self);
    if (self->member != 0)
      self->member->slot3();
  }
}
