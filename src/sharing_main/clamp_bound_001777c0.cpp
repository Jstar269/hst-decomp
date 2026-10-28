/* HSTMATCH module=hstp_trans_main.prx start=0x001777c0 end=0x00177830 symbol=FUN_001777c0 lang=c++ */
/* Clone of src/eboot/clamp_bound_0016b5fc.cpp (hstclone.py tag c160307): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int DAT_00387a4c;
extern int DAT_00387a50;
extern "C" int FUN_00177d4c();

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_001777c0(u16 param_1)
{
  int iVar1 = FUN_00177d4c();
  *(u16 *)(iVar1 + 0x1036) = (u16)Clamp(param_1, DAT_00387a4c, DAT_00387a50);
}
