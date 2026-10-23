/* HSTMATCH module=EBOOT.BIN start=0x00117d70 end=0x00117dd0 symbol=FUN_00117d70 lang=c99 */
void FUN_00117d70(int param_1, int param_2, int param_3, int param_4)
{
    int i;

    if (param_4 != 0) {
        i = *(int *)(param_1 + 0x5c);
        if (i >= 0) {
            while (*(char *)(param_1 + i * 0x70 + 0xe0) == 0 &&
                   i != *(int *)(param_1 + 0x60)) {
                param_2++;
                i = (i + 8) % 9;
            }
        }
        *(int *)(param_1 + 0x44) = param_2;
    }
    *(int *)(param_1 + 0x44) = param_2;
    *(int *)(param_1 + 0x48) = param_3;
}
// near miss: 24/24 words, 18 differ. Retail: beqzl a3->jr_ra with the +0x44 store in the delay slot,
// bltz (NOT bltzl, nop delay) to the single merge store, and i in t0 with the constant 9 hoisted into v1.
// This source (store inside the if + the same store again after it) reproduces the beqzl+store slot and
// the merge store but MWCC merges the second store into the bltz delay slot (bltzl) and keeps i in v1
// with `li a3,9` inside the loop. Ruled out: if(==0){store}else{loop} (h1/h5: bnezl layout),
// store-only-after-the-if (h2: 23 words, no delay-slot store), early return (h4: 26 words),
// for-loop header (h6), block-scoped i.
// near miss from lane fm6 (unreviewed)
