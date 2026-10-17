/* HSTMATCH module=EBOOT.BIN start=0x000fafec end=0x000fb02c symbol=FUN_000fafec lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Unless the word at +0x3c of the DAT_003386b0 object is 9, call virtual slot 3 (vtable +0x14) of the object at this+0x3c. Sibling of 0xfb02c (slot 1) and 0xfafb8. */
struct VC_000fafec {
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3();
};
struct Game_000fafec {
  char pad[0x3c];
  int mode;
};
struct Obj_000fafec {
  char pad[0x3c];
  VC_000fafec *f3c;
};
extern Game_000fafec *DAT_003386b0;

extern "C" void FUN_000fafec(Obj_000fafec *o)
{
  if (DAT_003386b0->mode != 9) {
    o->f3c->s3();
  }
}
