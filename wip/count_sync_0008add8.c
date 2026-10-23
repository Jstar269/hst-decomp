/* HSTMATCH module=EBOOT.BIN start=0x0008add8 end=0x0008aee4 symbol=FUN_0008add8 lang=c99 */
extern unsigned char DAT_003386b8;
extern int DAT_00338af0;
extern unsigned char *DAT_00338b44;
extern void FUN_000c50cc(int);
extern int FUN_000c4ba0(int, int);
extern void FUN_0008822c(char *, int, int);
extern char DAT_002d2428[];

int FUN_0008add8(int param_1)
{
    int n;
    int i;
    int row;
    int m;

    if (DAT_003386b8 != 0) {
        if (DAT_00338af0 != 0) {
            n = *(int *)(param_1 + 0x50);
            if (n < 1) {
                return 0;
            }
            if (0 < n) {
                m = n - 1;
                *(int *)(param_1 + 0x50) = m;
                if (m == 0) {
                    FUN_000c50cc(DAT_00338af0);
                    return 0;
                }
            }
            if (*(unsigned char *)(DAT_00338b44 + 0x45) != 0) {
                n = 2;
            } else {
                n = 4;
            }
            for (i = 0; i < n; i++) {
                row = FUN_000c4ba0(DAT_00338af0, i);
                if (*(int *)(param_1 + 0x64) != *(int *)(row + *(int *)(param_1 + 0x5c) * 4 + 4)) {
                    return 0;
                }
            }
            FUN_0008822c(DAT_002d2428, *(int *)(param_1 + 0x64), *(int *)(param_1 + 0x5c));
            *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x64) + 1;
        } else {
            return 1;
        }
    }
    return 1;
}
// NEAR MISS (lane fm3): 67/67 words, only 2 words differ -- retail keeps the counter store
// s2-relative (`sw v0,80(s2)` with a nop in the bgtz delay) while we get an address temp
// (`addiu v1,s2,80` in that nop slot, then `sw v0,0(v1)`). Ruled out: storing a local copy
// (`m = n - 1`), a plain comma expression, `-= 1`, `((int *)param_1)[20]`, and testing a reload vs
// testing the value. Everything else in the function is byte-identical, so the rest of this file
// (lbu globals as unsigned char, `if (x != 0) {..} else { return 1; }` to keep retail's beqzl+li
// into the epilogue, and `if (c != 0) n = 2; else n = 4;` for the beqzl/li s0,4 arm order) is the
// shape to keep.
// near miss from lane fm3 (unreviewed)
