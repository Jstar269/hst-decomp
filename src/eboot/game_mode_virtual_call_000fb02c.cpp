/* HSTMATCH module=EBOOT.BIN start=0x000fb02c end=0x000fb06c symbol=FUN_000fb02c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Unless the word at +0x3c of the DAT_003386b0 object is 9, call virtual slot 1 (vtable +0xc) of the object at this+0x3c. Sibling of 0xfafec (slot 3) and 0xfafb8. */
struct VC_000fb02c {
  virtual void s0();
  virtual void s1();
};
struct Game_000fb02c {
  char pad[0x3c];
  int mode;
};
struct Obj_000fb02c {
  char pad[0x3c];
  VC_000fb02c *f3c;
};
extern Game_000fb02c *DAT_003386b0;

extern "C" void FUN_000fb02c(Obj_000fb02c *o)
{
  if (DAT_003386b0->mode != 9) {
    o->f3c->s1();
  }
}
