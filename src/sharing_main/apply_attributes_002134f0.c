/* HSTMATCH module=hstp_trans_main.prx start=0x002134f0 end=0x00213780 symbol=FUN_002134f0 lang=c99 */
/* Clone of src/eboot/apply_attributes_00204c88.c (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern char DAT_003b7ebc;
extern char DAT_00397718;
extern char DAT_00397734;
extern char DAT_00397738;
extern int DAT_002d9830[];
extern int DAT_00397614[];
static inline int Kind(const int *t, int i) { if (i >= 0 && i < 6) return t[i]; return 0; }

extern void FUN_00094a98(int, int);
extern int FUN_000943b8(int, int, int, int, int);
extern void FUN_0001c5f4(void *, ...);
extern unsigned char FUN_000944c0(int, int, int, int, unsigned char);
extern void FUN_0001c73c(void *);
extern void FUN_00094ba4(int, int);
extern void FUN_00095080(int, int, void *, unsigned char);

void FUN_002134f0(int param_1, unsigned char *param_2, unsigned char *param_3, unsigned char *param_4,
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
    kinds = DAT_002d9830;
    names = DAT_00397614;
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
                FUN_00094a98(param_1, iVar7);
            }
            if (FUN_000943b8(param_1, iVar7, iVar8, param_9, 0) == 0) {
                FUN_0001c5f4(&DAT_003b7ebc, &DAT_00397718, names[iVar9], names[iVar9], iVar8, &DAT_00397734);
                unsigned char uVar2 = FUN_000944c0(param_1, iVar7, iVar8, param_9, local_11);
                if (iVar7 == 2) {
                    *param_3 = uVar2;
                } else if (iVar7 == 0) {
                    *param_2 = uVar2;
                } else if (iVar7 == 5) {
                    *param_4 = uVar2;
                }
                FUN_0001c73c(&DAT_003b7ebc);
            }
        } else {
            FUN_00094a98(param_1, iVar7);
        }

        if (iVar7 == 2 && param_10 != *(int *)(param_1 + 0x68)) {
            FUN_0001c5f4(&DAT_003b7ebc, &DAT_00397738, param_10);
            FUN_00094ba4(param_1, param_10);
            FUN_0001c73c(&DAT_003b7ebc);
        }
    }

    char local_4[2] = {0};
    local_4[0] = param_6;
    local_4[1] = param_7;
    FUN_00095080(param_1, 1, local_4, param_8);
}

// The two table bases are locals assigned in the loop preheader (`kinds = DAT_002d9830; names = DAT_00397614;`, kinds read
// through Kind(kinds, i)) between `iVar9 = 0;` and the param_11 copy: MWCC keeps statement order in the preheader, so the
// spilled copy's `sb v0,56(sp)` follows the two base `addiu`s as in retail. Reading the globals directly inside the loop
// lets loop-invariant motion append the bases AFTER the copy (3 words off), whatever position the copy has.
