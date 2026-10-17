/* HSTMATCH module=hstp_trans_main.prx start=0x0024476c end=0x002447e0 symbol=FUN_0024476c lang=c++ */
/* Clone of src/eboot/state_dispatch_by_id_002345f8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tab { int k; int x; };
struct Obj { int id; };
extern Tab DAT_002da1dc[];
extern char DAT_0039d1a0[];
extern "C" void FUN_001104b0(char *, int);
extern "C" void FUN_00244258(Obj *, int);

extern "C" void FUN_0024476c(Obj *o)
{
  int id = o->id;
  int k;
  if (id >= 0 && id < 26) k = 26; else k = DAT_002da1dc[id].k;
  if (k == 0x59) FUN_001104b0(DAT_0039d1a0, 0);
  else FUN_00244258(o, k);
}
