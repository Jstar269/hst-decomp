/* HSTMATCH module=hstp_trans_main.prx start=0x001c0990 end=0x001c0a3c symbol=FUN_001c0990 lang=c99 */
/* Clone of src/eboot/FUN_001b28fc.c (hstclone.py tag s10172123g5r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: restored mixed float/integer argument prototype and call ordering; exact match verified; names and types await human review. */

extern int FUN_00063b20(int param_1, int param_2);
extern int FUN_001c02d4(void *param_1, int *param_2, void *param_3, float f1, float f2, float f3, float f4, void *param_4, int param_9, int param_10);

int FUN_001c0990(void *param_1, int param_2, void *param_3, float f1, float f2, float f3, float f4, void *param_4)
{
    int local_4;
    local_4 = FUN_00063b20(param_2, 0);
    if (local_4 >= 0) {
        FUN_001c02d4(param_1, &local_4, param_3, f1, f2, f3, f4, param_4, 0, 0);
    }
    return local_4;
}
