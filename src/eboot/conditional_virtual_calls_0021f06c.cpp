/* HSTMATCH module=EBOOT.BIN start=0x0021f06c end=0x0021f0f8 symbol=FUN_0021f06c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct V { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); };
extern "C" void FUN_001031e8();
extern "C" void FUN_0021f06c(int param_1)
{
  if (*(unsigned char *)(param_1 + 0x1e4) != 0) return;
  if (!(*(float *)(param_1 + 0x1d8) > 0.0f)) return;
  if (*(unsigned char *)(param_1 + 0x208) == 0) return;
  FUN_001031e8();
  if (*(int *)(param_1 + 0x1e8) >= 0) {
    ((V *)(param_1 + 0x174))->m3();
  }
  V *p = *(V **)(param_1 + 0x16c);
  if (p != 0) p->m3();
}