/* HSTMATCH module=EBOOT.BIN start=0x00201910 end=0x002019cc symbol=FUN_00201910 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ virtual call on slot 2 (VC with three virtuals), typed object view with nine 0x8c-byte records, and the nine FUN_00217940 calls written out (a for loop stays rolled); exact match verified; names and types await human review. */
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
extern "C" void FUN_00201604(Obj *);
extern "C" void FUN_00217940(Rec *);

extern "C" void FUN_00201910(Obj *param_1)
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
    FUN_00201604(param_1);
    FUN_00217940(&param_1->recs[0]);
    FUN_00217940(&param_1->recs[1]);
    FUN_00217940(&param_1->recs[2]);
    FUN_00217940(&param_1->recs[3]);
    FUN_00217940(&param_1->recs[4]);
    FUN_00217940(&param_1->recs[5]);
    FUN_00217940(&param_1->recs[6]);
    FUN_00217940(&param_1->recs[7]);
    FUN_00217940(&param_1->recs[8]);
  }
}
