/* HSTMATCH module=hstp_trans_main.prx start=0x0026f390 end=0x0026f428 symbol=FUN_0026f390 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/init_nested_subobject_0025e568.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/spawn_owner.h"

extern int DAT_003b0a68;
extern int DAT_003a68a0;
extern int DAT_002cc260;
extern void FUN_001017dc(SpawnedObj *);
extern void FUN_00056cac(void *);
extern void FUN_00101748(SpawnedObj *, int *);
extern void FUN_001016c0(void *, int *);

/* Constructor of a slot: builds the embedded spawned object (two matrix blocks set from the reference matrix,
   unit scales, no link, empty name). Returns the slot. */
SpawnedSlot *FUN_0026f390(SpawnedSlot *slot)
{
  SpawnedObj *sub = &slot->obj;

  FUN_001017dc(sub);
  FUN_00056cac(sub->matA);
  sub->vtable = &DAT_003b0a68;
  sub->unk70 = 0;
  sub->link = SPAWNED_NO_LINK;
  sub->unk78 = 1.0f;
  sub->unk7c = 1.0f;
  FUN_00056cac(sub->matB);
  sub->name = (int)&DAT_003a68a0;
  FUN_00101748(sub, &DAT_002cc260);
  FUN_001016c0(sub->matB, &DAT_002cc260);
  return slot;
}
