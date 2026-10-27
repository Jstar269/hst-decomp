/* HSTMATCH module=EBOOT.BIN start=0x0023466c end=0x002346e0 symbol=FUN_0023466c lang=c++ data=0x002f48dc */
/* Clone of src/eboot/state_dispatch_by_id_002345f8.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002f48dc-0x002f48ef) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tab { int k; int x; };
struct Obj { int id; };
extern Tab DAT_002c9c1c[];
extern "C" void FUN_0010a6f0(char *, int);
extern "C" void FUN_00234158(Obj *, int);

extern "C" void FUN_0023466c(Obj *o)
{
  int id = o->id;
  int k;
  if (id >= 0 && id < 26) k = 26; else k = DAT_002c9c1c[id].k;
  if (k == 0x59) FUN_0010a6f0("PrevSeq is Nothing", 0);
  else FUN_00234158(o, k);
}
