/* HSTMATCH module=EBOOT.BIN start=0x001bb5f8 end=0x001bb63c symbol=FUN_001bb5f8 lang=c99 helpers=FUN_001bb640@0x001bb640-0x001bb6b0 rodata=0x002c6260 */
extern int DAT_003417a4;
extern void FUN_002b7e70(int, int);
void FUN_001bb640(int kind);

void FUN_001bb5f8(int x)
{
    int v = 0;

    switch (x) {
    case 1: v = 1; break;
    case 2: v = 2; break;
    case 3: v = 3; break;
    default: break;
    }
    FUN_001bb640(v);
}

void FUN_001bb640(int kind)
{
    int code;
    DAT_003417a4 = kind;
    code = 1;
    switch (kind) {
    case 0:
    case 1:
        code = 1;
        break;
    case 2:
        code = 2;
        break;
    case 3:
        code = 3;
        break;
    case 4:
        code = 4;
        break;
    case 5:
        code = 5;
        break;
    case 6:
    case 7:
    case 8:
        break;
    case 9:
        code = 9;
        break;
    case 10:
        code = 10;
        break;
    }
    FUN_002b7e70(code, 1);
}

// 11 words differ (17/17 words, same size). The helper FUN_001bb640 at 0x001bb640 matches EXACTLY
// (placed with helpers=; the ledger range 0x1bb5f8-0x1bb6b0 contains both functions, the first ends in
// a `j 0x1bb640` tail call).
// Retail tests the cases 3,2,1 (so the source order is 1,2,3) and keeps case 1's body OUT OF LINE at
// 0x1bb624 followed by `b JOIN` (that body is unreachable: the `beq a0,1` goes straight to the join),
// while case 2's body sits in the beql delay slot and case 3's body sits last, right before the join.
// Ours fuses case 1 into the third test's delay slot (beql + move) and puts case 3's body at 0x1bb624.
// Ruled out: if/else chains (bne form, 15 words), every case order (1,2,3 / 3,2,1 / 2,1,3 / 3,1,2),
// default v=0 / default break / default absent / case 0 instead of default, `switch` with and without a
// trailing break, and an explicit trailing `else v = 0;`. All 17 words, 11-16 differ.
// near miss from lane fm6 (unreviewed)
