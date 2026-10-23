/* HSTMATCH module=EBOOT.BIN start=0x000bce08 end=0x000bcf88 symbol=FUN_000bce08 lang=c99 */
extern char DAT_002d53a4[];
extern void FUN_00011090(int, void *);
extern int FUN_000bdb14(int, int, int, int, int, int, int, int);
extern void FUN_000ba3ac(char *);

void FUN_000bce08(int param_1)
{
    int args[4];
    int i;
    int n;
    int sel;
    char *src;
    char *dst;
    unsigned char t;

    args[0] = 4;
    *(float *)(args + 2) = *(float *)(param_1 + 0x27c);
    *(float *)(args + 3) = *(float *)(param_1 + 0x280);
    args[1] = 0x10;
    FUN_00011090(*(int *)(param_1 + 0x184), args);
    for (i = 0; i < 0x10; i++) {
        if (*(unsigned char *)(param_1 + i * 7 + 0x5e) != 0 && i != *(int *)(param_1 + 0x198)) {
            if (FUN_000bdb14(param_1, *(int *)(param_1 + 0x17c), param_1 + i * 7 + 0x58,
                             *(unsigned short *)(param_1 + 0x10), *(int *)(param_1 + 0x184),
                             args[1], 0, 1) < 0)
                FUN_000ba3ac(DAT_002d53a4);
        }
    }
    sel = 0;
    for (i = 0; i < 0x10; i++) {
        if (*(unsigned char *)(param_1 + i * 7 + 0x5e) != 0) {
            src = (char *)(param_1 + i * 7 + 0x58);
            dst = (char *)(param_1 + sel * 6 + 0x108);
            n = 3;
            do {
                t = src[1];
                n--;
                *dst = *src;
                dst[1] = t;
                src += 2;
                dst += 2;
            } while (n > 0);
            sel++;
        }
    }
    *(int *)(param_1 + 0x194) = *(int *)(param_1 + 400);
    *(int *)(param_1 + 0x28) = 0xb;
}
// near miss: 76/96 words. Both loops have the right shape (16-slot scan with the +0x5e flag and
// the +0x198 exclusion, FUN_000bdb14's 8 arguments, the <0 -> FUN_000ba3ac(s_SendPdp___failed)
// path, then the compacting 2-byte copy loop into +0x108 at 6 bytes per kept slot, then +0x194 =
// +0x190 and +0x28 = 0xb). Ours is 20 words short: MWCC keeps the second loop's destination
// counter in an extra register and hoists the src/dst adds differently (retail uses t0/t1 as the
// running src/dst and t3 as the dest index, ours t2/t3/a2/t0/t1). Facts: +0x27c/+0x280 are FLOATS
// (lwc1), the +0x5e flag is UNSIGNED (lbu), and the argument block is {4, 0x10, f27c, f280}.
// near miss from lane fm6 (unreviewed)
