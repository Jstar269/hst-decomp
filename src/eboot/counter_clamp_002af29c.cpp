/* HSTMATCH module=EBOOT.BIN start=0x002af29c end=0x002af314 symbol=FUN_002af29c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern int DAT_00302ddc;
extern int DAT_00302de0;
extern void FUN_002af5b0(int *list);
}

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_002af29c(int param_1)
{
  FUN_002af5b0((int *)(param_1 + 0x4b78));
  *(int *)(param_1 + 0x4b74) = Clamp(*(int *)(param_1 + 0x4b74) - 1, DAT_00302ddc, DAT_00302de0);
}
