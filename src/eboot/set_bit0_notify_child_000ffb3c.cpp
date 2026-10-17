/* HSTMATCH module=EBOOT.BIN start=0x000ffb3c end=0x000ffb8c symbol=FUN_000ffb3c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: struct view, virtual call through a two-slot polymorphic child (slot 1), branch order of the flag update restored; exact match verified; names and types await human review. */
struct Child_000ffb3c {
  virtual void s0();
  virtual void s1();
};

struct Obj_000ffb3c {
  char pad000[0xe];
  unsigned short h00e;
  char pad010[0x10];
  Child_000ffb3c *p020;
};

extern "C" void FUN_000ffb3c(Obj_000ffb3c *o, int flag)
{
  if (flag != 0) {
    o->h00e |= 1;
  } else {
    o->h00e &= 0xfffe;
  }
  if (o->p020 != 0) {
    o->p020->s1();
  }
}
