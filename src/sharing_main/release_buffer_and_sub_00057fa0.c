/* HSTMATCH module=hstp_trans_main.prx start=0x00057fa0 end=0x00057ff4 symbol=FUN_00057fa0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed the two members, nested the duplicated null test around delete[] (matching idiom: if (p) { if (p) delete[] p; p = 0; }); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000009e4();
extern u32 * FUN_00056de8();

typedef struct Obj {
  char pad[0x168];
  void *sub;
  char *buf;
} Obj;

void FUN_00057fa0(Obj *o)
{
  char *p;

  p = o->buf;
  if (p != 0) {
    if (p != 0) {
      FUN_000009e4(p - 0x10);
    }
    o->buf = 0;
  }
  if (o->sub != 0) {
    FUN_00056de8(o->sub,1);
    o->sub = 0;
  }
}
