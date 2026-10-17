/* HSTMATCH module=hstp_trans_main.prx start=0x001c1ef4 end=0x001c1f3c symbol=FUN_001c1ef4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Stores 0x81 when the field at +0x7a4 is 6; otherwise 0x1da for a negative index, else 0x98 + 2 * (field at +0x7a4) + index; the result goes to +0x7c8 of the object pointed to by the first word. */
struct Inner {
  char pad0[0x7a4];
  int f7a4;
  char pad1[0x20];
  int f7c8;
};
struct Obj {
  Inner *p;
};

extern "C" void FUN_001c1ef4(Obj *o, int idx)
{
  Inner *i = o->p;
  if (i->f7a4 == 6) {
    i->f7c8 = 0x81;
  } else if (idx >= 0) {
    i->f7c8 = i->f7a4 * 2 + 0x98 + idx;
  } else {
    i->f7c8 = 0x1da;
  }
}
