/* HSTMATCH module=EBOOT.BIN start=0x001bf62c end=0x001bf884 symbol=FUN_001bf62c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag km4 near miss, wip/best_001bf62c.c) corrected by hand: last byte-threshold test written `diff > 1u` instead of `>= 2u` (gives the sltiu at / bnez at pair); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/item_table.h"

extern int FUN_001bb8b8();
extern void FUN_001bbab8();
extern void FUN_001bf948();
extern void FUN_001bf980();
extern void FUN_001bf9b8();

/* Set the state of slot `index`; when it becomes state A or B, give the linked items state A too. */
void FUN_001bf62c(ItemTable *table,int index,u8 state)
{
  int link_a;
  int link_b;
  int link_c;
  int link_d;
  u32 diff;
  u8 *flag;
  ItemSlot *slot;
  
  if ((index >= 0) && (index < ITEM_SLOT_COUNT)) {
    slot = &table->slot[index];
  }
  else {
    slot = (ItemSlot *)0x0;
  }
  if (slot != (ItemSlot *)0x0) {
    slot->state = state;
    diff = (u32)slot->state - ITEM_STATE_A;
    if (diff < 2u) {
      link_a = FUN_001bb8b8(1,index);
      link_b = FUN_001bb8b8(1,index);
      link_c = FUN_001bb8b8(3,index);
      link_d = FUN_001bb8b8(4,index);
      if ((link_a >= 0) && (link_a < ITEM_FLAG_COUNT)) {
        flag = &table->flag_a[link_a];
      }
      else {
        flag = (u8 *)0x0;
      }
      diff = (u32)(*flag - ITEM_STATE_A);
      if (diff > 1u) {
        FUN_001bf948(table,link_a,ITEM_STATE_A);
      }
      if ((link_b >= 0) && (link_b < ITEM_FLAG_COUNT)) {
        flag = &table->flag_b[link_b];
      }
      else {
        flag = (u8 *)0x0;
      }
      diff = (u32)(*flag - ITEM_STATE_A);
      if (diff > 1u) {
        FUN_001bf980(table,link_b,ITEM_STATE_A);
      }
      if (link_c != 0) {
        if ((link_c >= 0) && (link_c < ITEM_FLAG_COUNT)) {
          flag = &table->flag_c[link_c];
        }
        else {
          flag = (u8 *)0x0;
        }
        diff = (u32)(*flag - ITEM_STATE_A);
      if (diff > 1u) {
          FUN_001bf9b8(table,link_c,ITEM_STATE_A);
        }
      }
      if (link_d != 0) {
        if ((link_d >= 0) && (link_d < ITEM_FLAG_COUNT)) {
          flag = &table->flag_c[link_d];
        }
        else {
          flag = (u8 *)0x0;
        }
        diff = (u32)(*flag - ITEM_STATE_A);
      if (diff > 1u) {
          FUN_001bf9b8(table,link_d,ITEM_STATE_A);
        }
      }
      if (index == 0xb) {
        diff = (u32)table->flag_b[3] - ITEM_STATE_A;
        if (diff > 1u) {
          FUN_001bf980(table,3,ITEM_STATE_A);
        }
      }
    }
    diff = (u32)slot->state - ITEM_STATE_A;
    if (diff < 2u) {
      FUN_001bbab8(slot);
    }
  }
}
