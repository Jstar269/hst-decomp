/* HSTMATCH module=hstp_trans_main.prx start=0x001259f4 end=0x00125b30 symbol=FUN_001259f4 lang=c99 */
/* Clone of src/eboot/check_active_items_0011a820.c (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: the flag/goto web is an inline early-return predicate RowsOk (guarded do/while over 0x34-byte rows, ternary 0.0f fallback) inside a for(;;) with break, flags are unsigned char, the callee 0xfb590 takes the tested global as its dropped argument; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
#include "hst/types.h"
typedef struct S8 { char pad[8]; float f8; } S8;
typedef struct Ref { S8 *s; } Ref;
typedef struct RowV { char pad[0xf4]; Ref *ref; char pad2[0xc]; float f10; } RowV;
typedef struct Item {
  char pad[0x158];
  int cur;
  int end;
} Item;
typedef struct Obj {
  char pad0[0x44];
  u8 f44;
  char pad1[3];
  Item *items[27];
  u8 active[27];
} Obj;
extern int DAT_003e1f60;
extern int FUN_00100ccc(int);

static inline u8 RowsOk(Item *it)
{
  int j = it->cur;
  int end = it->end;
  if (j <= end) {
    RowV *row = (RowV *)((char *)it + j * 0x34);
    do {
      float v = row->ref != 0 ? row->ref->s->f8 : 0.0f;
      if (row->f10 < v) return 0;
      j++;
      row = (RowV *)((char *)row + 0x34);
    } while (j <= end);
  }
  return 1;
}

u8 FUN_001259f4(Obj *o)
{
  u8 a = 0;
  u8 b;
  if (o->f44 != 0) {
    int r;
    int i = 0;
    for (;;) {
      if (o->active[i] != 0) {
        if (!RowsOk(o->items[i])) { r = 0; break; }
      }
      i++;
      if (i >= 27) { r = 1; break; }
    }
    a = (r != 0) ^ 1;
    if (!a) o->f44 = 0;
  }
  b = 0;
  if (DAT_003e1f60 != 0) { int t = !FUN_00100ccc(DAT_003e1f60); if (t) b = 1; }
  return (a | b) != 0;
}
/* Matching idioms: #pragma opt_strength_reduction off (outer item/flag loop recomputes i*4), the row cursor walked by
   hand in the inline helper (retail bumps it by 52 per pass after a guard), `int t = !F(G); if (t) b = 1;` (a bare
   `if (!F(G))` or `F(G) == 0` gives bnezl / xor+sltiu), `a = (r != 0) ^ 1`, and the result as `(a | b) != 0`. */
