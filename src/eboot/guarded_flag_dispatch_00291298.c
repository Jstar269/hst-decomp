/* HSTMATCH module=EBOOT.BIN start=0x00291298 end=0x00291338 symbol=FUN_00291298 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: typed object struct with the two flag bytes and two pointers, the first `if` kept as a nested test with a re-read flag, and the dropped argument of FUN_00051450 (the +0x30 member, loaded into a0) restored; readability pass; exact match verified; names and types await human review. */
#include "hst/player_service.h"

extern void FUN_0028fb70(void *);
extern void *FUN_00051450(void *);
extern void FUN_00022a48(void *, void *, int);
extern void FUN_002b79f0(int);
extern unsigned char DAT_0034a80c;

/* Per-tick check: runs FUN_0028fb70 while ready and suspended; once fully set up, passes unk2c on through FUN_00022a48. */
void FUN_00291298(PlayerService **pp)
{
  PlayerService *o = *pp;
  if (o->ready != 0) {
    if (DAT_0034a80c != 0) {
      FUN_0028fb70(o);
    }
  }
  if (o->ready != 0 && o->unk30 != 0 && o->unk2c != 0 && o->unk29 != 0) {
    FUN_00022a48(FUN_00051450(o->unk30), o->unk2c, 0x88000);
    FUN_002b79f0(6);
  }
}
