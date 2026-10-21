/* HSTMATCH module=EBOOT.BIN start=0x0014e698 end=0x0014e7d0 symbol=FUN_0014e698 lang=c++ */
struct Node { Node *prev; Node *next; int value; };
struct List { int size_; Node *head_; };
struct Obj { char pad[0x18]; List list; };
struct EraseIt {
  Node *node;
  EraseIt(Node *n) : node(n) {}
  EraseIt(const EraseIt &o) : node(o.node) {}
};
struct InsertIt {
  Node *node_;
  InsertIt(Node *n) : node_(n) {}
};

extern "C" {
extern unsigned char DAT_003402f0;
extern char DAT_002dc240[];
extern char DAT_002dc24c[];
extern char DAT_002dc32c[];
extern char DAT_002dc31c[];
extern char DAT_002dc324[];
EraseIt FUN_0014f3cc(List *l, EraseIt pos);
InsertIt FUN_0014f43c(List *l, const InsertIt &pos, const int &x);
}

static void FUN_0014c610(const char *fmt, ...) {}

extern "C" int FUN_0014e698(int unused, Obj *obj)
{
  Node *first = obj->list.head_;
  int state = first->value;
  FUN_0014f3cc(&obj->list, EraseIt(first));
  if (DAT_003402f0 != 0) {
    if (DAT_003402f0 != 0) {
      FUN_0014c610(DAT_002dc240);
      for (int i = 0; i < obj->list.size_ + 1; i++)
        FUN_0014c610(DAT_002dc24c);
    }
    FUN_0014c610(DAT_002dc32c);
  }
  if (state == 1) {
    int v = 0;
    FUN_0014f43c(&obj->list, InsertIt((Node *)&obj->list.head_), v);
    if (DAT_003402f0 != 0)
      FUN_0014c610(DAT_002dc31c);
  } else {
    int v = 2;
    FUN_0014f43c(&obj->list, InsertIt((Node *)&obj->list.head_), v);
    if (DAT_003402f0 != 0)
      FUN_0014c610(DAT_002dc324);
  }
  return 0;
}
// NEAR MISS (5 words, all jal targets; everything else is byte-identical to retail): retail keeps the loop counter in v1 across the
// jal to the empty variadic print stub FUN_0014c610 (extern prototype => s-register counter, frame 64/48 and a saved s2).
// MWCC only does that for a stub defined EARLIER IN THE SAME FILE (here a `static ... {}` placed before the function; see
// NOTES 2026-10-15 0x195bb0): with it the function matches except that the five `jal` words point at the local stub instead of
// 0x0014c610, so hstmatch reports MISPLACED. It would be exact inside a multi-function run starting at 0x0014c610 (the stub), which is
// not buildable here (0x14c63c..0x14e698 contains unmatched functions). To compile standalone replace the static stub by
// `void FUN_0014c610(const char *fmt, ...);` (then 22 words differ: counter in s1, frame 64, sltu).
// Layout lessons found on the way: pass the list iterators as TEMPORARIES in the calls (`FUN_0014f3cc(&obj->list, EraseIt(first))`,
// `FUN_0014f43c(&obj->list, InsertIt((Node *)&obj->list.head_), v)`), not as named locals (named ones add 16 bytes of frame);
// `int v = 0;` / `int v = 2;` named locals inside the two branches give the 44/40 slots; List::size_ is int (slt, not sltu).
// near miss from lane sn4 (unreviewed)
