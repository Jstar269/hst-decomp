/* HSTMATCH module=EBOOT.BIN start=0x0025e568 end=0x0025e600 symbol=FUN_0025e568 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/spawn_owner.h"

extern int DAT_0030779c;
extern int DAT_002fdc90;
extern int DAT_002bc410;
extern void FUN_000fc0a0(SpawnedObj *);
extern void FUN_00056098(void *);
extern void FUN_000fc00c(SpawnedObj *, int *);
extern void FUN_000fbf84(void *, int *);

/* Constructor of a slot: builds the embedded spawned object (two matrix blocks set from the reference matrix,
   unit scales, no link, empty name). Returns the slot. */
SpawnedSlot *FUN_0025e568(SpawnedSlot *slot)
{
  SpawnedObj *sub = &slot->obj;

  FUN_000fc0a0(sub);
  FUN_00056098(sub->matA);
  sub->vtable = &DAT_0030779c;
  sub->unk70 = 0;
  sub->link = SPAWNED_NO_LINK;
  sub->unk78 = 1.0f;
  sub->unk7c = 1.0f;
  FUN_00056098(sub->matB);
  sub->name = (int)&DAT_002fdc90;
  FUN_000fc00c(sub, &DAT_002bc410);
  FUN_000fbf84(sub->matB, &DAT_002bc410);
  return slot;
}
