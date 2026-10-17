/* HSTMATCH module=EBOOT.BIN start=0x000ffb8c end=0x000ffbdc symbol=FUN_000ffb8c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: struct view, virtual call through a three-slot polymorphic child (slot 2), branch order of the flag update restored; exact match verified; names and types await human review. */
struct Child_000ffb8c {
  virtual void s0();
  virtual void s1();
  virtual void s2();
};

struct Obj_000ffb8c {
  char pad000[0xe];
  unsigned short h00e;
  char pad010[0x10];
  Child_000ffb8c *p020;
};

extern "C" void FUN_000ffb8c(Obj_000ffb8c *o, int flag)
{
  if (flag != 0) {
    o->h00e |= 2;
  } else {
    o->h00e &= 0xfffd;
  }
  if (o->p020 != 0) {
    o->p020->s2();
  }
}
