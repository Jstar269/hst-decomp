/* HSTMATCH module=EBOOT.BIN start=0x00289d60 end=0x00289e84 symbol=FUN_00289d60 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Fills the counter at +4 up to 1000 (FUN_0028c8d8), clamps it to 1000 when it is larger, and then
   collects two lists into the array at +0: FUN_00289f84 is called with the index 1..899 (ascending,
   with the third argument taken from the fourth parameter) and then with the index 999..901
   (descending, with the third argument 99 and the second argument taken from the second parameter).
   The value of FUN_0001342c is stored in the global at 0x34a7f4.
   Matching idioms: the counter is UNSIGNED, the index arithmetic is strength reduced off
   (#pragma opt_strength_reduction off), the fourth argument of FUN_0028c8d8 is an empty tag struct
   passed by value (the caller materialises it as `move v0,zero; seb a3,v0`), and the index is set to 1
   AFTER the if/else chain (inside both arms the compiler turns the inner test into a branch likely
   with the join copied into its delay slot). */
#include "hst/scene_res.h"

struct Tag {};
#pragma opt_strength_reduction off

#define TABLE_SIZE 1000        /* number of entries the table is filled to */
#define LOW_END 900            /* ascending part covers indices 1..LOW_END-1 */
#define HIGH_FIRST 901         /* descending part covers TABLE_SIZE-1 down to this index */
#define HIGH_LEVEL 99          /* level used for the descending part */

/* Table of scene resource sets: pointer array and entry count. */
struct Table {
  SceneResSet **items;
  unsigned int count;
};

extern "C" void FUN_00289e84(Table *self);
extern "C" void FUN_0028c8d8(Table *self, int count, int *out, Tag tag);
extern "C" SceneResSet *FUN_00289f84(Table *self, char *base_dir, int level, int item);
extern "C" int FUN_0001342c();
extern int DAT_0034a7f4;

/* Reset the table to TABLE_SIZE entries and load the low items from dir_low and the high items from dir_high. */
extern "C" void FUN_00289d60(Table *self, char *dir_high, char *dir_low, int level)
{
  unsigned int count;
  int idx;
  SceneResSet *set;

  FUN_00289e84(self);
  int zero = 0;
  count = self->count;
  if (count < TABLE_SIZE) {
    FUN_0028c8d8(self, TABLE_SIZE - count, &zero, Tag());
  } else if (count > TABLE_SIZE) {
    self->count -= count - TABLE_SIZE;
  }
  idx = 1;
  do {
    set = FUN_00289f84(self, dir_low, level, idx);
    if (set == 0) {
      idx = TABLE_SIZE - 1;
      break;
    }
    self->items[idx] = set;
    idx++;
  } while (idx < LOW_END);
  idx = TABLE_SIZE - 1;
  do {
    set = FUN_00289f84(self, dir_high, HIGH_LEVEL, idx);
    if (set == 0) {
      break;
    }
    self->items[idx] = set;
    idx--;
  } while (idx >= HIGH_FIRST);
  DAT_0034a7f4 = FUN_0001342c();
}
