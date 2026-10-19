/* HSTMATCH module=hstp_trans_main.prx start=0x0024c444 end=0x0024c4d0 symbol=FUN_0024c444 lang=c++ */
/* Clone of src/eboot/FUN_0023c2ac.cpp (hstclone.py tag s10181937g11r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the +0x1750 access is a member of param_1, the two vtable calls are real C++ virtuals (slot 0x10) on two view structs, the two float stores re-read the param_1+0x14c0 member (no CSE) and keep the destination pointer in a0; exact match verified; names and types await human review. */
extern "C" void FUN_00226564(int);
extern "C" void FUN_00108558(void);
struct V { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); };
struct W { virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); };

extern "C" void FUN_0024c444(int param_1)
{
  V *p = *(V **)(param_1 + 0x1750);
  W *q;
  float *out;
  if (p != 0) p->v2();
  q = *(W **)(param_1 + 4);
  q->w2();
  FUN_00226564(*(int *)(param_1 + 0x14c0));
  out = *(float **)(param_1 + 0x20);
  out[0x18] = (float)*(int *)(*(int *)(param_1 + 0x14c0) + 0x14);
  out[0x19] = (float)(*(int *)(*(int *)(param_1 + 0x14c0) + 0x18) + *(int *)(*(int *)(param_1 + 0x14c0) + 0x1c));
  FUN_00108558();
}
