/* HSTMATCH module=EBOOT.BIN start=0x001b9410 end=0x001b9470 symbol=FUN_001b9410 lang=c99 */
typedef struct { short lo; short hi; } Rec;
extern Rec **FUN_001b9720(Rec **first, Rec **last, Rec **cur, char flag);

Rec **FUN_001b9410(Rec **first, Rec **last, char flag)
{
    while (first != last && !((*first)->lo < (*first)->hi))
        ++first;
    if (first == last)
        return first;
    return FUN_001b9720(first + 1, last, first, flag);
}
// 16 words differ: retail keeps the cursor in a2 (so the 3rd call arg needs no copy) and the
// char flag in v0 (`move v0,a2` at entry, `seb a3,v0` in the bnel slot), plus a 32-byte frame
// where ours gets 16. Loop body (lh lo, lh hi, slt, beqzl, addiu) is byte-identical.
// Ruled out: for(;;)+if layout, if(first==last)return first, `hi <= lo` polarity, separate local cursor.
// near miss from lane ds3 (unreviewed)
