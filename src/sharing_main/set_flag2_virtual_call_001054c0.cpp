/* HSTMATCH module=hstp_trans_main.prx start=0x001054c0 end=0x00105510 symbol=FUN_001054c0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sets or clears bit 1 of the halfword at +0xe, then calls virtual slot 2 (vtable +0x10) of the object at +0x20 if present. */
struct VC {
  virtual void s0();
  virtual void s1();
  virtual void s2();
};
struct Obj {
  char pad0[0xe];
  unsigned short flags;
  char pad1[0x10];
  VC *child;
};

extern "C" void FUN_001054c0(Obj *o, int on)
{
  if (on != 0) {
    o->flags |= 2;
  } else {
    o->flags &= ~2;
  }
  if (o->child != 0) {
    o->child->s2();
  }
}
