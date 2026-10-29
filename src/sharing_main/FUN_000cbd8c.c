/* HSTMATCH module=hstp_trans_main.prx start=0x000cbd8c end=0x000cbdfc symbol=FUN_000cbd8c */
/* Clone of src/eboot/FUN_000c81ec.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/effect_scene.h"

extern void FUN_0001ef34(EffectScene *scene, void *member);

/* Register the members 3c, 40, 48, 4c, 50, 54 and 58 with the base object. */
void FUN_000cbd8c(EffectScene *scene)
{
    FUN_0001ef34(scene, scene->member3c);
    FUN_0001ef34(scene, scene->member40);
    FUN_0001ef34(scene, scene->member48);
    FUN_0001ef34(scene, scene->member4c);
    FUN_0001ef34(scene, scene->member50);
    FUN_0001ef34(scene, scene->member54);
    FUN_0001ef34(scene, scene->member58);
}
