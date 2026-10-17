/* HSTMATCH module=hstp_trans_main.prx start=0x0028ac8c end=0x0028ad10 symbol=FUN_0028ac8c lang=c99 */
/* Clone of src/eboot/update_pairs_002799a8.c (hstclone.py tag u5fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declaration order and loop pointer; exact match verified; names and types await human review. */

extern void FUN_00105470(void *, int);

void FUN_0028ac8c(char *param_1, int param_2)
{
    int i;
    char *p = param_1;
    for (i = 0; i < 16; i++, p += 0x10) {
        if (i == param_2) {
            FUN_00105470(*(void **)(p + 0x4b8), 0);
            FUN_00105470(*(void **)(p + 0x4bc), 0);
        } else {
            FUN_00105470(*(void **)(p + 0x4b8), 1);
            FUN_00105470(*(void **)(p + 0x4bc), 1);
        }
    }
}
