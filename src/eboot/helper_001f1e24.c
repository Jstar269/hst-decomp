/* HSTMATCH module=EBOOT.BIN start=0x001f1e24 end=0x001f1e8c symbol=FUN_001f1e24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: materialized the zero-float guard result with a default-true flag; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/prize_screen.h"

typedef struct FloatHost {
  char pad00[0xc];
  float unkc;               /* 0xc */
} FloatHost;

extern FloatHost * DAT_00331b84;
extern void FUN_001f47a4();
extern void FUN_001f4bfc();
extern void FUN_001f9518();

/* Per-frame update: calls the helper only while the global's float at 0xc is zero, then the shared steps. */
void FUN_001f1e24(PrizeScreen *self)
{
  int should_call = 1;
  if (DAT_00331b84->unkc != 0.0f) {
    should_call = 0;
  }
  if (should_call != 0) {
    FUN_001f9518(self);
  }
  FUN_001f4bfc(self);
  FUN_001f47a4(self);
}
