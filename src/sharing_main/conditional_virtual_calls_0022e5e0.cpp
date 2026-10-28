/* HSTMATCH module=hstp_trans_main.prx start=0x0022e5e0 end=0x0022e66c symbol=FUN_0022e5e0 lang=c++ */
/* Clone of src/eboot/conditional_virtual_calls_0021f06c.cpp (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct V { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); };
extern "C" void FUN_00108aec();
extern "C" void FUN_0022e5e0(int param_1)
{
  if (*(unsigned char *)(param_1 + 0x1e4) != 0) return;
  if (!(*(float *)(param_1 + 0x1d8) > 0.0f)) return;
  if (*(unsigned char *)(param_1 + 0x208) == 0) return;
  FUN_00108aec();
  if (*(int *)(param_1 + 0x1e8) >= 0) {
    ((V *)(param_1 + 0x174))->m3();
  }
  V *p = *(V **)(param_1 + 0x16c);
  if (p != 0) p->m3();
}