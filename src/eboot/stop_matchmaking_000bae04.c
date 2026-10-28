/* HSTMATCH module=EBOOT.BIN start=0x000bae04 end=0x000bae98 symbol=FUN_000bae04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_000bae04.c) corrected by hand: FUN_002b7db0 takes the dropped handle argument (loaded into a0 before the test), the handle is a struct member tested as `h > -1` inside one outer if (gives slti/bnezl, not bgez); exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_002d512c[];
extern char DAT_002d515c[];
extern char DAT_002d5190[];
extern void FUN_000ba3ac();
extern int FUN_002b7db0(int);
extern int FUN_002b7df8();

typedef struct Obj { char pad[0x16c]; int h; } Obj;

u32 FUN_000bae04(Obj *o)
{
  int iVar2;
  if (o->h > -1) {
    iVar2 = FUN_002b7db0(o->h);
    if (iVar2 < 0) {
      FUN_000ba3ac(DAT_002d512c, iVar2);
      return 0;
    }
    iVar2 = FUN_002b7df8(o->h);
    if (iVar2 < 0) {
      FUN_000ba3ac(DAT_002d515c, iVar2);
      return 0;
    }
    FUN_000ba3ac(DAT_002d5190);
    o->h = -1;
    return 1;
  }
  return 0;
}
