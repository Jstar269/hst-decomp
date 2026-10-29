/* HSTMATCH module=EBOOT.BIN start=0x0026d5fc end=0x0026d714 symbol=FUN_0026d5fc lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Near-miss wip (lane u6cr1-1, hstgen tag a1 origin) corrected by hand: the type/subtype tests are one && condition and the loop count is re-read once for the loop test; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
#include "hst/types.h"
#include "hst/shop_scene.h"

extern void FUN_00277a1c();
extern void FUN_00279b24();

/* Switches the scene to a new state: remembers the previous one, resets the per-state fields and fixes up the item list. */
void FUN_0026d5fc(ShopScene *scene,int new_state)
{
  ShopItemVec *items;
  ShopItem *item;
  unsigned int index;
  unsigned int count;
  
  scene->prev_state = scene->state;
  scene->state = new_state;
  scene->unk110 = 1;
  scene->unk180 = SHOP_NO_VALUE;
  FUN_00279b24();
  scene->unk458 = 0;
  FUN_00277a1c(scene,scene->prev_state,scene->state);
  scene->unk8c3 = 0;
  scene->unk114 = 0;
  scene->unk8c4 = 0;
  scene->unk8bc = 0;
  scene->unk8c8 = 0;
  if (scene->state != 7 && scene->state != 1) {
    scene->unkf8 = 0;
  }
  scene->unk99c = 0;
  scene->unk9a0 = 0;
  scene->unk9a4 = 0;
  scene->unk9a8 = 0;
  scene->unk9ac = 0;
  scene->unk8ce = 0;
  items = &scene->items;
  index = 0;
  if (items->count != 0) {
    do {
      item = items->data[index];
      if (item->flag == 1) {
        item->small = 0;
      }
      item = items->data[index];
      if (item->type == 4 && item->subtype == 5) {
        item->flag = 0;
      }
      count = items->count;
      index = index + 1;
    } while (index < count);
  }
}
// Near miss: two words differ at +0xe8; this source emits bnel v1,a0 with the count load in its delay slot, while retail emits bne v1,a0 with a nop.
// Combined, nested, goto, and continue forms changed the loop layout or retained this branch and delay-slot difference.
// near miss from lane u6cr1-1 (unreviewed)
