/* HSTMATCH module=EBOOT.BIN start=0x00259ffc end=0x0025a0e8 symbol=FUN_00259ffc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: reconstructed player string branch, decrement condition, and if ((puVar2 = alloc())) pattern; readability pass; exact match verified; names and types await human review. */

#include "hst/types.h"
#include "hst/spawn_owner.h"

extern u8 DAT_002bc410;
extern u8 DAT_0030779c;
extern char DAT_002ca7d4[];
extern char DAT_002ca7e0[];
extern void *FUN_00000bcc(int);
extern int FUN_00014934(int, const char *);
extern u32 FUN_00056098(void *);
extern u32 *FUN_000fbf84(void *, void *);
extern u32 *FUN_000fc00c(void *, void *);
extern u32 *FUN_000fc0a0(void *);

/* Creates the player object for name. *in_budget is set when the name matches this owner's string
   (s_player or d_player, by mode flag) and a use was still left; that use is consumed. */
SpawnedObj *FUN_00259ffc(SpawnOwner *owner, int name, char *in_budget)
{
    const char *owner_str;
    if (owner->altNames != '\0') {
        owner_str = DAT_002ca7e0;
    } else {
        owner_str = DAT_002ca7d4;
    }

    if (FUN_00014934(name, owner_str) == 0) {
        int val = owner->remaining;
        owner->remaining = val - 1;
        *in_budget = 0 < val;
    } else {
        *in_budget = 0;
    }

    SpawnedObj *obj;
    if ((obj = (SpawnedObj *)FUN_00000bcc(SPAWNED_OBJ_SIZE)) != 0) {
        FUN_000fc0a0(obj);
        FUN_00056098(obj->matA);
        obj->vtable = &DAT_0030779c;
        obj->unk70 = 0;
        obj->link = SPAWNED_NO_LINK;
        obj->unk78 = 1.0f;
        obj->unk7c = 1.0f;
        FUN_00056098(obj->matB);
        obj->name = name;
        FUN_000fc00c(obj, &DAT_002bc410);
        FUN_000fbf84(obj->matB, &DAT_002bc410);
    }
    return obj;
}
