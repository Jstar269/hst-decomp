/* HSTMATCH module=EBOOT.BIN start=0x001b9410 end=0x001b9470 symbol=FUN_001b9410 lang=c++ */
typedef struct { short lo; short hi; } Rec;
struct Tag { };
extern "C" Rec **FUN_001b9720(Rec **first, Rec **last, Rec **cur, char flag, Tag t);

extern "C" Rec **FUN_001b9410(Rec **first, Rec **last, char flag)
{
    Rec **p = first;
    while (p != last && !((*p)->lo < (*p)->hi))
        ++p;
    if (p != last)
        p = FUN_001b9720(p + 1, last, p, (char)flag, Tag());
    return p;
}
// BEST: 24/24 words, 9 differ. Frame 32 and loop body/back-edge now correct.
// The 32-byte frame (= hidden 16-byte never-written slot) comes from the empty Tag passed BY VALUE
// to an INLINE helper (`Step(.., Tag())`, which forwards to the out-of-line call) or from an empty
// 5th call argument -- NOT from anything in the loop expression.
// Remaining: retail's preheader copies the flag a2->v0 (`move v0,a2`) and sign-extends only at the
// call (`seb a3,v0`); every source shape tried gives `move a3,a2` (flag home = its call register),
// which also cascades into the record-load colours (retail v1/a0/v1 vs ours v0/v1/v0).
// Ruled out: char param, int param, (char)cast, `int f = flag`, `char f = flag`, unsigned char/bool
// param, functor form (frame OK but materialises the test as `slt;xori;beqz`), 4-arg callee (frame 16).
// near miss from lane ds3 (unreviewed)
