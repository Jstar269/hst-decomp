/* HSTMATCH module=hstp_trans_main.prx start=0x00057ff4 end=0x00058090 symbol=FUN_00057ff4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: inverted branch order to param_3 != 0 and simplified object allocation to if (p != 0) p = ctor(p); exact match verified; names and types await human review. */

extern void *FUN_00000bcc(int size);
extern void *FUN_00056d24(void *p, int b, int c);
extern void FUN_00058118(int a, int b, void *c, int d);

void FUN_00057ff4(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    if (param_3 != 0) {
        void *p = FUN_00000bcc(16);
        if (p != 0) {
            p = FUN_00056d24(p, param_3, param_4);
        }
        FUN_00058118(param_1, param_2, p, param_5);
    } else {
        FUN_00058118(param_1, param_2, 0, param_5);
    }
}
