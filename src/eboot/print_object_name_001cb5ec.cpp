/* HSTMATCH module=EBOOT.BIN start=0x001cb5ec end=0x001cb700 symbol=FUN_001cb5ec lang=c++ data=0x002eaa9c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002eaa9c-0x002eaaac) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

extern "C" {
extern unsigned char DAT_002ea308;
extern int FUN_0000d62c(const char *);
extern void FUN_000143b0(void *, const char *, int, int);
extern int FUN_000149a8(...);
extern int FUN_00014a40(int);
extern int FUN_002295f4(int, void *, int);
extern int FUN_00287460(void *);
}

struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
  virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
  virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };

extern "C" void FUN_001cb5ec(int param_1, void *param_2, VC_0 *param_3, int param_4)
{
  char *p;
  int v;
  int r;
  int s;

  if (((VC_0 *)param_3)->m() == 1) {
    s = FUN_00287460(param_3);
    v = -1;
    if (s != 0) {
      p = (char *)(s + FUN_00014a40(s));
      p--;
      while (*p >= '0' && *p <= '9') p--;
      if (p != 0) v = FUN_0000d62c(p + 1);
    }
    FUN_000143b0(param_2, "EVENT%02d_%02d_", v, param_4);
    r = FUN_002295f4(*(int *)(param_1 + 0x15c) + 0x34, param_2, 0);
    if (r != 0) FUN_000149a8(param_2, r);
  }
  else {
    FUN_000149a8(param_2, &DAT_002ea308);
  }
}
