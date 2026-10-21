/* HSTMATCH module=EBOOT.BIN start=0x0016b998 end=0x0016ba08 symbol=FUN_0016b998 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned short ushort;

extern int DAT_002e0488;
extern int DAT_002e048c;
extern "C" int FUN_0016bb88();

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_0016b998(ushort param_1)
{
  int iVar1 = FUN_0016bb88();
  *(ushort *)(iVar1 + 0x1038) = (ushort)Clamp(param_1, DAT_002e0488, DAT_002e048c);
}
