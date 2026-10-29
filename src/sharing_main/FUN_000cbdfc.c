/* HSTMATCH module=hstp_trans_main.prx start=0x000cbdfc end=0x000cbe68 symbol=FUN_000cbdfc lang=c99 */
/* Clone of src/eboot/FUN_000c825c.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/effect_scene.h"

extern int * FUN_000008d8();
extern int FUN_00000a90();
extern void FUN_000577ec();
extern void FUN_00057904();

/* Create the array of four 0x1b0-byte objects and the four-byte block if they do not exist yet. */
void FUN_000cbdfc(EffectScene *scene)
{
  u32 mem;
  
  if (scene->table1d0 == 0) {
    mem = FUN_00000a90(0x6d0);
    mem = (unsigned int)(FUN_000008d8(mem,FUN_000577ec,FUN_00057904,0x1b0,4));
    scene->table1d0 = (void *)mem;
  }
  if (scene->block1d4 == 0) {
    mem = FUN_00000a90(4);
    scene->block1d4 = (void *)mem;
  }
}
