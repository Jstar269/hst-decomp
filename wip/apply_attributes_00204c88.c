/* HSTMATCH module=EBOOT.BIN start=0x00204c88 end=0x00204f18 symbol=FUN_00204c88 lang=c99 */

extern char DAT_0030ebf4;
extern char DAT_002ef624;
extern char DAT_002ef640;
extern char DAT_002ef644;
extern int DAT_002c9398;
extern int DAT_002ef520;

extern void FUN_00092c38(int, int);
extern int FUN_00092720(int, int, int, int, int);
extern void FUN_0001ca58(void *, ...);
extern unsigned char FUN_00092790(int, int, int, int, unsigned char);
extern void FUN_0001cb88(void *);
extern void FUN_00092d10(int, int);
extern void FUN_000931ec(int, int, void *, unsigned char);

void FUN_00204c88(int param_1, unsigned char *param_2, unsigned char *param_3, unsigned char *param_4,
                  int *param_5, unsigned char param_6, unsigned char param_7, unsigned char param_8,
                  int param_9, int param_10, unsigned char param_11)
{
    unsigned char local_11 = param_11;
    *param_2 = 0;
    *param_3 = 0;

    int *p5 = param_5;
    int *piVar6 = &DAT_002c9398;
    int *ppuVar10 = &DAT_002ef520;
    int iVar8;
    int iVar7;
    int iVar9;

    *param_4 = 0;

    for (iVar9 = 0; iVar9 < 6; iVar9++, piVar6++, ppuVar10++, p5++) {
        if (iVar9 >= 0 && iVar9 < 6) {
            iVar7 = *piVar6;
        } else {
            iVar7 = 0;
        }

        iVar8 = *p5;
        if (iVar8 == 0x7fffffff) {
            continue;
        }

        if (iVar8 >= 0) {
            if (iVar7 == 5) {
                iVar8 = iVar8 / 10;
            }
            if ((unsigned int)(iVar7 - 3) < 2 && iVar8 == 0) {
                FUN_00092c38(param_1, iVar7);
            }
            if (FUN_00092720(param_1, iVar7, iVar8, param_9, 0) == 0) {
                FUN_0001ca58(&DAT_0030ebf4, &DAT_002ef624, *ppuVar10, *ppuVar10, iVar8, &DAT_002ef640);
                unsigned char uVar2 = FUN_00092790(param_1, iVar7, iVar8, param_9, local_11);
                if (iVar7 == 2) {
                    *param_3 = uVar2;
                } else if (iVar7 == 0) {
                    *param_2 = uVar2;
                } else if (iVar7 == 5) {
                    *param_4 = uVar2;
                }
                FUN_0001cb88(&DAT_0030ebf4);
            }
        } else {
            FUN_00092c38(param_1, iVar7);
        }

        if (iVar7 == 2 && param_10 != *(int *)(param_1 + 0x68)) {
            FUN_0001ca58(&DAT_0030ebf4, &DAT_002ef644, param_10);
            FUN_00092d10(param_1, param_10);
            FUN_0001cb88(&DAT_0030ebf4);
        }
    }

    char local_4[2] = {0};
    local_4[0] = param_6;
    local_4[1] = param_7;
    FUN_000931ec(param_1, 1, local_4, param_8);
}

// Differing words: 15 / 164.
// Exact instruction count and CFG match retail.
// Difference: 3 loop registers rotated (piVar6 in s6 vs s0, iVar9 in s0 vs s3, param_5 in s3 vs s6).
// Ruled out: array indexing (&DAT_002c9398[i]), inverted if branches, separate local declaration orders.
// near miss from lane ag2 (unreviewed)
