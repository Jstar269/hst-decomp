/* HSTMATCH module=EBOOT.BIN start=0x0007fa1c end=0x0007fb78 symbol=FUN_0007fa1c lang=c99 */

extern int FUN_000704c4(int);
extern void FUN_00086620(int, int, int, int);

void FUN_0007fa1c(char *param_1, char *param_2)
{
    short flags = *(short *)(param_2 + 2);
    int s3 = *(short *)(param_1 + 76);

    if (flags & 0x200) {
        s3 = (s3 * *(short *)(param_2 + 18)) >> 12;
    }
    if (flags & 0x800) {
        s3 = (s3 * FUN_000704c4(*(short *)(param_2 + 22))) >> 12;
    }

    int a1 = 0;
    if (flags & 0x100) {
        a1 = *(short *)(param_2 + 16);
    }

    int *p16 = *(int **)(param_1 + 16);
    if (p16[5] == 1) {
        int idx = param_1[11];
        int delta = (int)*(unsigned char *)((char *)p16 + idx * 6 + 61) - 64;
        a1 += delta * 64;
    }

    if (a1 != 0) {
        signed char factor;
        if (a1 < 0) {
            factor = *(signed char *)(param_1 + 82);
        } else if (a1 > 0) {
            factor = *(signed char *)(param_1 + 83);
        }
        s3 = (s3 * FUN_000704c4(((factor * 128) * a1) >> 12)) >> 12;
    }

    int count = (signed char)*(unsigned char *)(param_1 + 54);
    if (count > 0) {
        int i = 0;
        short *ptr = (short *)(param_1 + 56);
        do {
            short val = *ptr++;
            i++;
            if (val >= 0) {
                FUN_00086620(val, 5, s3, 0);
            }
        } while (i < (signed char)*(unsigned char *)(param_1 + 54));
    }
}

// Differing words: ~25 / 87 words.
// Identified compiler as MWCC (emits Allegrex seb and branch-likely beql, bltzl, beqzl, bnezl).
// Sound effect / voice track volume and pitch modulation with call to FUN_000704c4 and loop over FUN_00086620.
// Differs in register allocation (param_2 in s1 vs s4, p16 in s4 vs s1, factor multiply order).
// near miss from lane u1r3-3 (unreviewed)
