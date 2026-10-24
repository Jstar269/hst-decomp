/* HSTMATCH module=EBOOT.BIN start=0x001c16b0 end=0x001c184c symbol=FUN_001c16b0 lang=c99 */

extern char *DAT_003415a8;
extern int DAT_0034a77c;
extern void *FUN_00193474(int);
extern int FUN_0016bb98(int, int);
extern int FUN_0024dd40(float, int);
extern void FUN_001c1c50();

void FUN_001c16b0(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    int sVar1 = *(short *)(param_3 + 2);
    char *pSub = DAT_003415a8 + 0x86a9c;
    int sub = param_3 + *(unsigned char *)(param_3 + 1) * 12 + 8;

    void *item = FUN_00193474(param_2);

    char *global = DAT_003415a8;
    int s4;
    if (param_2 < 0) {
        s4 = 1;
    } else {
        char *base = global + 128;
        if (param_2 < 15) {
            s4 = *(unsigned char *)(base + param_2 + 4133);
        } else {
            s4 = 1;
        }
    }

    int uVar6 = FUN_0016bb98(param_2, (int)item + 0x68);
    int uVar7 = FUN_0024dd40(*(float *)(param_3 + 4), DAT_0034a77c);

    FUN_001c1c50(
        param_1,
        global + 0x20,
        param_2,
        *(unsigned short *)(sub + 0),
        *(unsigned short *)(sub + 2),
        *(unsigned short *)(sub + 4),
        *(unsigned short *)(sub + 6),
        sVar1,
        *(unsigned char *)(sub + 9) != 0,
        *(unsigned char *)(sub + 10) != 0,
        *(unsigned char *)(sub + 8) != 0,
        param_5,
        *(int *)(global + 0x10d4),
        uVar6,
        param_2,
        (char *)item + 0x68,
        s4,
        (unsigned char)pSub[0x130],
        0,
        uVar7,
        0,
        param_4,
        param_6,
        0,
        item
    );
}
// near miss: 72 words differ out of 103 words (0x1c16dc..0x1c1818).
// Frame size (144 bytes), prologue/epilogue saves (s0-s8, ra), calls (0x193474, 0x16bb98, 0x24dd40, 0x1c1c50),
// stack argument layout (17 words on stack at 0(sp)..64(sp)), and temporary spills (132, 136, 143) all match retail.
// Difference is register allocation: retail assigns s5 to param_2 and s0 to param_3 (reused for uVar6), shifting s1-s4.
// Ruled out: C vs C++, parameter typing (structs vs int), local declaration ordering, register keyword, inline helper wrapper.
// near miss from lane ag3 (unreviewed)
