/* HSTMATCH module=EBOOT.BIN start=0x00204c88 end=0x00204f18 symbol=FUN_00204c88 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern char DAT_0030ebf4;
extern char DAT_002ef624;
extern char DAT_002ef640;
extern char DAT_002ef644;
extern int DAT_002c9398[];
extern int DAT_002ef520[];
static inline int Kind(const int *t, int i) { if (i >= 0 && i < 6) return t[i]; return 0; }

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
    unsigned char local_11;
    *param_2 = 0;
    *param_3 = 0;

    int iVar9;
    int iVar8;
    int iVar7;
    const int *kinds;
    const int *names;

    *param_4 = 0;

    iVar9 = 0;
    kinds = DAT_002c9398;
    names = DAT_002ef520;
    local_11 = param_11;
    for (; iVar9 < 6; iVar9++) {
        iVar7 = Kind(kinds, iVar9);

        iVar8 = param_5[iVar9];
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
                FUN_0001ca58(&DAT_0030ebf4, &DAT_002ef624, names[iVar9], names[iVar9], iVar8, &DAT_002ef640);
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

// The two table bases are locals assigned in the loop preheader (`kinds = DAT_002c9398; names = DAT_002ef520;`, kinds read
// through Kind(kinds, i)) between `iVar9 = 0;` and the param_11 copy: MWCC keeps statement order in the preheader, so the
// spilled copy's `sb v0,56(sp)` follows the two base `addiu`s as in retail. Reading the globals directly inside the loop
// lets loop-invariant motion append the bases AFTER the copy (3 words off), whatever position the copy has.
