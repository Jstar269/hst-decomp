/* HSTMATCH module=EBOOT.BIN start=0x000c81c0 end=0x000c81ec symbol=FUN_000c81c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/effect_scene.h"

extern void FUN_000ce72c();

/* Run FUN_000ce72c on member 44 when it exists. */
u32 FUN_000c81c0(EffectScene *scene)
{
  if (scene->member44 != 0) {
    FUN_000ce72c(scene->member44);
  }
  return 1;
}
