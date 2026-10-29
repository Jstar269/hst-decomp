/* HSTMATCH module=hstp_trans_main.prx start=0x0023876c end=0x0023881c symbol=FUN_0023876c lang=c99 */
/* Clone of src/eboot/FUN_002291f8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_00000a00();
extern void FUN_00238948();
extern void FUN_00238ce8();
extern int FUN_00238fc8();
extern int FUN_00239108();

/* Destructor of the two-tree map: frees the string keys, then both trees; frees self when delete_flag > 0. */
TreePair *FUN_0023876c(TreePair *self,short delete_flag)
{
  TreeMap *pairs;
  
  if (self != 0) {
    FUN_00238ce8();
    FUN_00238948(self);
    pairs = &self->pairs;
    if ((((pairs != 0) && (pairs != 0)) && (pairs != 0)) && (pairs != 0)) {
      FUN_00239108(pairs,0);
    }
    if (((self != 0) && (self != 0)) && ((self != 0 && (self != 0)))) {
      FUN_00238fc8(self,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
