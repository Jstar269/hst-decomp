/* HSTMATCH module=hstp_trans_main.prx start=0x002446f8 end=0x0024476c symbol=FUN_002446f8 lang=c++ data=0x0039d18c */
/* Clone of src/eboot/state_dispatch_by_id_002345f8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0039d18c-0x0039d19f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tab { int k; int x; };
struct Obj { int id; };
extern Tab DAT_002da1e0[];
extern "C" void FUN_001104b0(char *, int);
extern "C" void FUN_00244258(Obj *, int);

extern "C" void FUN_002446f8(Obj *o)
{
  int id = o->id;
  int k;
  if (id >= 0 && id < 26) k = 26; else k = DAT_002da1e0[id].k;
  if (k == 0x59) FUN_001104b0("NextSeq is Nothing", 0);
  else FUN_00244258(o, k);
}
