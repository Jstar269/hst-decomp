/* HSTMATCH module=EBOOT.BIN start=0x0016b998 end=0x0016ba08 symbol=FUN_0016b998 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern int DAT_002e0488;   /* lower bound */
extern int DAT_002e048c;   /* upper bound */
extern "C" SettingsBlock *FUN_0016bb88();

/* Returns v limited to [lo, hi]. */
static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

/* Stores the value clamped to its bounds into the +0x1038 setting. */
extern "C" void FUN_0016b998(u16 value)
{
  SettingsBlock *settings = FUN_0016bb88();
  settings->unk1038 = (u16)Clamp(value, DAT_002e0488, DAT_002e048c);
}
