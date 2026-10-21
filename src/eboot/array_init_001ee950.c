/* HSTMATCH module=EBOOT.BIN start=0x001ee950 end=0x001ee998 symbol=FUN_001ee950 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate carried by the wip near miss of lane u6cr1-2) corrected by hand: the guard reads the LAST stored field (+0x30), which MWCC store-forwards as `move v0,zero` instead of folding or reloading +0x28; the object is a char * with a Vec view (matching idiom: with a struct-pointer parameter the schedule differs by 6 words); exact match verified; names and types await human review. */
typedef unsigned int uint;

typedef struct Vec {
  uint first;
  uint last;
  uint cap;
} Vec;

extern void FUN_000c4040(Vec *, int);

char *FUN_001ee950(char *self)
{
  Vec *v = (Vec *)(self + 0x28);
  v->first = 0;
  v->last = 0;
  v->cap = 0;
  if (v->cap < 4) {
    FUN_000c4040(v, 4);
  }
  return self;
}
