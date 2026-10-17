/* HSTMATCH module=EBOOT.BIN start=0x002345f8 end=0x0023466c symbol=FUN_002345f8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tab { int k; int x; };
struct Obj { int id; };
extern Tab DAT_002c9c20[];
extern char DAT_002f48c8[];
extern "C" void FUN_0010a6f0(char *, int);
extern "C" void FUN_00234158(Obj *, int);

extern "C" void FUN_002345f8(Obj *o)
{
  int id = o->id;
  int k;
  if (id >= 0 && id < 26) k = 26; else k = DAT_002c9c20[id].k;
  if (k == 0x59) FUN_0010a6f0(DAT_002f48c8, 0);
  else FUN_00234158(o, k);
}
