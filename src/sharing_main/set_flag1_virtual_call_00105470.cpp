/* HSTMATCH module=hstp_trans_main.prx start=0x00105470 end=0x001054c0 symbol=FUN_00105470 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sets or clears bit 0 of the halfword at +0xe, then calls virtual slot 1 (vtable +0xc) of the object at +0x20 if present. */
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

extern "C" void FUN_00105470(Obj *o, int on)
{
  if (on != 0) {
    o->flags |= 1;
  } else {
    o->flags &= ~1;
  }
  if (o->child != 0) {
    o->child->s1();
  }
}
