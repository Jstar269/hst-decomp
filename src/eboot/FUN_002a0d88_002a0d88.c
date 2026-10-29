/* HSTMATCH module=EBOOT.BIN start=0x002a0d88 end=0x002a0df4 symbol=FUN_002a0d88 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: kept the update flag as int and narrowed it after the float stores; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct PairHolder {
  char pad[0x108];
  float a;            /* 0x108 */
  float b;            /* 0x10c */
} PairHolder;

extern void FUN_0010d4a8();

/* Stores a pair of floats and calls FUN_0010d4a8 when either value changed (or when forced). */
void FUN_002a0d88(float a,float b,PairHolder *self,int force)
{
  int changed;
  bool changed_flag;
  
  changed = force != 0;
  if ((!changed) && (changed = true, self->a == a)) {
    changed = false;
  }
  if (!(changed)) {
    changed = self->b != b;
  }
  self->a = a;
  self->b = b;
  changed_flag = (bool)changed;
  if (changed_flag) {
    FUN_0010d4a8();
  }
}
