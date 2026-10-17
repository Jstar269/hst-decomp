/* HSTMATCH module=hstp_trans_main.prx start=0x00057c88 end=0x00057ce0 symbol=FUN_00057c88 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: restored param_1 passed to FUN_00057fa0 and simplified object allocation; exact match verified; names and types await human review. */

extern void FUN_00057fa0(void *param_1);
extern void *FUN_00000bcc(int size);
extern void *FUN_00056dac(void *p, int param_2);
extern void FUN_00057ce0(void *param_1);

void FUN_00057c88(char *param_1, int param_2)
{
    void *p;
    FUN_00057fa0(param_1);
    p = FUN_00000bcc(16);
    if (p != 0) {
        p = FUN_00056dac(p, param_2);
    }
    *(void **)(param_1 + 0x168) = p;
    FUN_00057ce0(param_1);
}
