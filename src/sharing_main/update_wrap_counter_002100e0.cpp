/* HSTMATCH module=hstp_trans_main.prx start=0x002100e0 end=0x0021019c symbol=FUN_002100e0 lang=c++ */
/* Clone of src/eboot/update_wrap_counter_00201910.cpp (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ virtual call on slot 2 (VC with three virtuals), typed object view with nine 0x8c-byte records, and the nine FUN_002269e8 calls written out (a for loop stays rolled); exact match verified; names and types await human review. */
struct VC { virtual void s0(); virtual void s1(); virtual void s2(); };
struct Rec { char b[0x8c]; };
struct Sub { char pad[0x24]; int f24; int f28; };
struct Obj {
  char pad0[4];
  VC *f4;
  char pad8[0x56c - 8];
  Sub *f56c;
  char pad570[0x70c - 0x570];
  int f70c;
  char pad710[8];
  Rec recs[9];
};
extern "C" void FUN_0020fdd4(Obj *);
extern "C" void FUN_002269e8(Rec *);

extern "C" void FUN_002100e0(Obj *param_1)
{
  if (param_1->f4 != 0) {
    param_1->f4->s2();
    int iVar1 = param_1->f70c + 1;
    param_1->f70c = iVar1;
    if (iVar1 >= 0x20) {
      param_1->f70c = 0;
    }
    Sub *s = param_1->f56c;
    s->f24 = s->f28 + param_1->f70c;
    FUN_0020fdd4(param_1);
    FUN_002269e8(&param_1->recs[0]);
    FUN_002269e8(&param_1->recs[1]);
    FUN_002269e8(&param_1->recs[2]);
    FUN_002269e8(&param_1->recs[3]);
    FUN_002269e8(&param_1->recs[4]);
    FUN_002269e8(&param_1->recs[5]);
    FUN_002269e8(&param_1->recs[6]);
    FUN_002269e8(&param_1->recs[7]);
    FUN_002269e8(&param_1->recs[8]);
  }
}
