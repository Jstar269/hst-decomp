/* HSTMATCH module=EBOOT.BIN start=0x000bae04 end=0x000bae98 symbol=FUN_000bae04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_000bae04.c) corrected by hand: FUN_002b7db0 takes the dropped handle argument (loaded into a0 before the test), the handle is a struct member tested as `h > -1` inside one outer if (gives slti/bnezl, not bgez); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/adhoc_net.h"

extern char DAT_002d512c[];
extern char DAT_002d515c[];
extern char DAT_002d5190[];
extern void FUN_000ba3ac();
extern int FUN_002b7db0(int);
extern int FUN_002b7df8();

/* Stops and deletes the matching session; returns 1 when it was closed. */
u32 FUN_000bae04(AdhocNet *net)
{
  int result;
  if (net->matchingId > -1) {
    result = FUN_002b7db0(net->matchingId);
    if (result < 0) {
      FUN_000ba3ac(DAT_002d512c, result);
      return 0;
    }
    result = FUN_002b7df8(net->matchingId);
    if (result < 0) {
      FUN_000ba3ac(DAT_002d515c, result);
      return 0;
    }
    FUN_000ba3ac(DAT_002d5190);
    net->matchingId = -1;
    return 1;
  }
  return 0;
}
