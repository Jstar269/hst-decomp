/* HSTMATCH module=EBOOT.BIN start=0x0005734c end=0x000573a0 symbol=FUN_0005734c lang=c99 */
/* Clone of src/sharing_main/release_buffer_and_sub_00057fa0.c (hstclone.py tag s10170158a3r1e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed the two members, nested the duplicated null test around delete[] (matching idiom: if (p) { if (p) delete[] p; p = 0; }); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000009e4();
extern u32 * FUN_000561d4();

typedef struct Obj {
  char pad[0x168];
  void *sub;
  char *buf;
} Obj;

void FUN_0005734c(Obj *o)
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
    FUN_000561d4(o->sub,1);
    o->sub = 0;
  }
}
