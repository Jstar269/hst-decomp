/* HSTMATCH module=EBOOT.BIN start=0x0015e268 end=0x0015e2ac symbol=FUN_0015e268 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* If the byte flag at +4 is set: call 0x15a118 with the word at +0x20, then virtual slot 2 (vtable +0x10) of the object at +0x40. */
struct VC_0015e268 {
  virtual void s0();
  virtual void s1();
  virtual void s2();
};
struct Obj_0015e268 {
  char pad0[4];
  unsigned char active;
  char pad1[0x1b];
  int f20;
  char pad2[0x1c];
  VC_0015e268 *f40;
};
extern "C" void FUN_0015a118(int);

extern "C" void FUN_0015e268(Obj_0015e268 *o)
{
  if (o->active) {
    FUN_0015a118(o->f20);
    o->f40->s2();
  }
}
