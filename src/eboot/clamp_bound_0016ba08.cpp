/* HSTMATCH module=EBOOT.BIN start=0x0016ba08 end=0x0016ba78 symbol=FUN_0016ba08 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern int DAT_002e0480;   /* lower bound */
extern int DAT_002e0484;   /* upper bound */
extern "C" SettingsBlock *FUN_0016bb88();

/* Returns v limited to [lo, hi]. */
static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

/* Stores the value clamped to its bounds into the +0x103a setting. */
extern "C" void FUN_0016ba08(u16 value)
{
  SettingsBlock *settings = FUN_0016bb88();
  settings->unk103a = (u16)Clamp(value, DAT_002e0480, DAT_002e0484);
}
