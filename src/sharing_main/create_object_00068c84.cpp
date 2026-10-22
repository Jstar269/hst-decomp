/* HSTMATCH module=hstp_trans_main.prx start=0x00068c84 end=0x00068cec symbol=FUN_00068c84 lang=c++ */
/* Clone of src/eboot/create_object_00067830.cpp (hstclone.py tag om1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Allocates a 20-byte object and initialises it: the vtable pointer at +0 is the class vtable
   DAT_003b045c (symbol __vt__10C_00067640 in symbols/EBOOT.BIN.txt), +4 takes the second
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
extern char DAT_003b045c[];

extern "C" Obj *FUN_00068c84(Obj *p1, int p2)
{
  Obj *o = (Obj *)FUN_00000bcc(0x14);
  if (o != 0) {
    o->vptr = &DAT_003b045c;
    o->a = p2;
    o->b = (p1 != 0) ? p1->a : 0;
    o->c = 0;
    o->d = 0;
  }
  return o;
}
