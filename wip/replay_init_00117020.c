/* HSTMATCH module=EBOOT.BIN start=0x00117020 end=0x00117128 symbol=FUN_00117020 lang=c99 */
extern char DAT_002d93e4[];
extern int FUN_0001cbfc(void);
extern int FUN_0001cc54(void);
extern void FUN_00116f98(char *, unsigned int);

void FUN_00117020(int param_1)
{
    int total;
    int lo;
    int hi;
    int i;
    int j;

    *(char *)(param_1 + 0x4c) = 0;
    *(int *)(param_1 + 0x50) = 0;
    *(char *)(param_1 + 0x54) = 0;
    *(int *)(param_1 + 0x58) = 0;
    *(int *)(param_1 + 0x44) = 0;
    *(int *)(param_1 + 0x48) = 0;
    *(int *)(param_1 + 0x5c) = 0;
    *(int *)(param_1 + 0x60) = 0;
    *(int *)(param_1 + 0x64) = 0;
    *(int *)(param_1 + 0x68) = 0;
    *(int *)(param_1 + 0x6c) = 0;
    *(int *)(param_1 + 0x70) = 0;
    total = FUN_0001cbfc() + FUN_0001cc54();
    hi = total - 0x7e900;
    lo = total - 0x8e620;
    FUN_00116f98(DAT_002d93e4, (unsigned int)(total - lo) >> 10);
    for (i = 0; i < 3; i++) {
        *(int *)(param_1 + i * 0xc + 0x500) = lo;
        *(int *)(param_1 + i * 0xc + 0x504) = lo + 0x1c20;
        *(int *)(param_1 + i * 0xc + 0x508) = lo + 0x3840;
        lo = lo + 0x5460;
    }
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 3; i++) {
            *(int *)(param_1 + j * 0x24 + i * 0xc + 0x470) = hi;
            *(int *)(param_1 + j * 0x24 + i * 0xc + 0x474) = hi + 0x3840;
            *(int *)(param_1 + j * 0x24 + i * 0xc + 0x478) = hi + 0x7080;
            hi = hi + 0xa8c0;
        }
    }
}
// near miss: 87/66 words. The initialisation list and both nested loops are recovered (12 zero
// stores at +0x4c/+0x50/+0x54/+0x58/+0x44/+0x48/+0x5c/+0x60/+0x64/+0x68/+0x6c/+0x70, the
// FUN_0001cbfc()+FUN_0001cc54() split into the hi = total-0x7e900 / lo = total-0x8e620 bases with
// FUN_00116f98((total-lo) >> 10), then the 3x (+0x500/+0x504/+0x508) slot table stepping by 0x5460
// and the 4x3 (+0x470/+0x474/+0x478) table stepping by 0xa8c0). Ours is 21 words long: retail
// strength-reduces both loops to pointer walks (a0 += 0xc / += 0x24, counters += 3 against < 9),
// ours indexes with j * 0x24 + i * 0xc + 0x470 and keeps a full multiply.
// near miss from lane fm6 (unreviewed)
