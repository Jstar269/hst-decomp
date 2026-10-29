/* HSTMATCH module=EBOOT.BIN start=0x000c825c end=0x000c82c8 symbol=FUN_000c825c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/effect_scene.h"

extern int * FUN_000008d8();
extern int FUN_00000a90();
extern void FUN_00056b98();
extern void FUN_00056cb0();

/* Create the array of four 0x1b0-byte objects and the four-byte block if they do not exist yet. */
void FUN_000c825c(EffectScene *scene)
{
  u32 mem;
  
  if (scene->table1d0 == 0) {
    mem = FUN_00000a90(0x6d0);
    mem = (unsigned int)(FUN_000008d8(mem,FUN_00056b98,FUN_00056cb0,0x1b0,4));
    scene->table1d0 = (void *)mem;
  }
  if (scene->block1d4 == 0) {
    mem = FUN_00000a90(4);
    scene->block1d4 = (void *)mem;
  }
}
