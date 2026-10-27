/* HSTMATCH module=EBOOT.BIN start=0x002345f8 end=0x0023466c symbol=FUN_002345f8 lang=c++ data=0x002f48c8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002f48c8-0x002f48db) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Tab { int k; int x; };
struct Obj { int id; };
extern Tab DAT_002c9c20[];
extern "C" void FUN_0010a6f0(char *, int);
extern "C" void FUN_00234158(Obj *, int);

extern "C" void FUN_002345f8(Obj *o)
{
  int id = o->id;
  int k;
  if (id >= 0 && id < 26) k = 26; else k = DAT_002c9c20[id].k;
  if (k == 0x59) FUN_0010a6f0("NextSeq is Nothing", 0);
  else FUN_00234158(o, k);
}
