/* HSTMATCH module=EBOOT.BIN start=0x000c81ec end=0x000c825c symbol=FUN_000c81ec */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
#include "hst/effect_scene.h"

extern void FUN_0001f21c(EffectScene *scene, void *member);

/* Register the members 3c, 40, 48, 4c, 50, 54 and 58 with the base object. */
void FUN_000c81ec(EffectScene *scene)
{
    FUN_0001f21c(scene, scene->member3c);
    FUN_0001f21c(scene, scene->member40);
    FUN_0001f21c(scene, scene->member48);
    FUN_0001f21c(scene, scene->member4c);
    FUN_0001f21c(scene, scene->member50);
    FUN_0001f21c(scene, scene->member54);
    FUN_0001f21c(scene, scene->member58);
}
