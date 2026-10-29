/* HSTMATCH module=EBOOT.BIN start=0x0016b58c end=0x0016b5fc symbol=FUN_0016b58c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern int DAT_002e0498;   /* lower bound */
extern int DAT_002e049c;   /* upper bound */
extern "C" SettingsBlock *FUN_0016bb88();

/* Returns v limited to [lo, hi]. */
static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

/* Stores the value clamped to its bounds into the +0x1034 setting. */
extern "C" void FUN_0016b58c(u16 value)
{
  SettingsBlock *settings = FUN_0016bb88();
  settings->unk1034 = (u16)Clamp(value, DAT_002e0498, DAT_002e049c);
}
