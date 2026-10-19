/* HSTMATCH module=EBOOT.BIN start=0x001b28fc end=0x001b29a8 symbol=FUN_001b28fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: restored mixed float/integer argument prototype and call ordering; exact match verified; names and types await human review. */

extern int FUN_00062c5c(int param_1, int param_2);
extern int FUN_001b2240(void *param_1, int *param_2, void *param_3, float f1, float f2, float f3, float f4, void *param_4, int param_9, int param_10);

int FUN_001b28fc(void *param_1, int param_2, void *param_3, float f1, float f2, float f3, float f4, void *param_4)
{
    int local_4;
    local_4 = FUN_00062c5c(param_2, 0);
    if (local_4 >= 0) {
        FUN_001b2240(param_1, &local_4, param_3, f1, f2, f3, f4, param_4, 0, 0);
    }
    return local_4;
}
