/* HSTMATCH module=EBOOT.BIN start=0x00067830 end=0x00067898 symbol=FUN_00067830 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Allocates a 20-byte object and initialises it: the vtable pointer at +0 is the class vtable
   DAT_00307190 (symbol __vt__10C_00067640 in symbols/EBOOT.BIN.txt), +4 takes the second
   argument, +8 copies the +4 field of the first argument (0 when that argument is null),
   +0xc is cleared and the byte at +0x10 is cleared. */
struct Obj {
  void *vptr;
  int a;
  int b;
  int c;
  unsigned char d;
};

extern "C" void *FUN_00000bcc(unsigned);
extern char DAT_00307190[];

extern "C" Obj *FUN_00067830(Obj *p1, int p2)
{
  Obj *o = (Obj *)FUN_00000bcc(0x14);
  if (o != 0) {
    o->vptr = &DAT_00307190;
    o->a = p2;
    o->b = (p1 != 0) ? p1->a : 0;
    o->c = 0;
    o->d = 0;
  }
  return o;
}
