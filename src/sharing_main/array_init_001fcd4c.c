/* HSTMATCH module=hstp_trans_main.prx start=0x001fcd4c end=0x001fcd94 symbol=FUN_001fcd4c lang=c99 */
/* Clone of src/eboot/array_init_001ee950.c (hstclone.py tag c22rt2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate carried by the wip near miss of lane u6cr1-2) corrected by hand: the guard reads the LAST stored field (+0x30), which MWCC store-forwards as `move v0,zero` instead of folding or reloading +0x28; the object is a char * with a Vec view (matching idiom: with a struct-pointer parameter the schedule differs by 6 words); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Vec {
  u32 first;
  u32 last;
  u32 cap;
} Vec;

extern void FUN_000c78a8(Vec *, int);

char *FUN_001fcd4c(char *self)
{
  Vec *v = (Vec *)(self + 0x28);
  v->first = 0;
  v->last = 0;
  v->cap = 0;
  if (v->cap < 4) {
    FUN_000c78a8(v, 4);
  }
  return self;
}
