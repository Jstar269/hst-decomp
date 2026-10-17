/* HSTMATCH module=EBOOT.BIN start=0x00057034 end=0x0005708c symbol=FUN_00057034 lang=c99 */
/* Clone of src/sharing_main/reinit_member_00057c88.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: restored param_1 passed to FUN_0005734c and simplified object allocation; exact match verified; names and types await human review. */

extern void FUN_0005734c(void *param_1);
extern void *FUN_00000bcc(int size);
extern void *FUN_00056198(void *p, int param_2);
extern void FUN_0005708c(void *param_1);

void FUN_00057034(char *param_1, int param_2)
{
    void *p;
    FUN_0005734c(param_1);
    p = FUN_00000bcc(16);
    if (p != 0) {
        p = FUN_00056198(p, param_2);
    }
    *(void **)(param_1 + 0x168) = p;
    FUN_0005708c(param_1);
}
