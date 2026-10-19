/* HSTMATCH module=EBOOT.BIN start=0x001baf40 end=0x001baf80 symbol=FUN_001baf40 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Matching idioms used here:
//  - the `unsigned char c = v;` local must be declared INSIDE the `if (i < l->count)` block that guards the
//    do-while, not before the loop.  Only then does the `andi a2,a1,0xff` narrowing conversion land in the
//    rotated loop's preheader (right after the `beqz` guard), which is where retail has it.  Declared before
//    the loop, MWCC schedules it above the guard (3 words off); declared inside the loop body it is folded
//    into the `sb` and vanishes.
//  - `#pragma opt_strength_reduction off` is required, otherwise the index becomes a walking byte offset.
//  - an `unsigned int` count is what makes the back-edge `sltu`.
#pragma opt_strength_reduction off

struct Item {
    char pad[9];
    unsigned char flag;
};

struct List {
    int f0;
    struct Item **items;
    unsigned int count;
};

void FUN_001baf40(struct List *l, int v)
{
    unsigned int i = 0;

    if (i < l->count) {
        unsigned char c = v;
        do {
            l->items[i]->flag = c;
            i++;
        } while (i < l->count);
    }
}
