/* HSTMATCH module=EBOOT.BIN start=0x000573a0 end=0x0005743c symbol=FUN_000573a0 lang=c99 */
/* Clone of src/sharing_main/alloc_or_null_00057ff4.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: inverted branch order to param_3 != 0 and simplified object allocation to if (p != 0) p = ctor(p); exact match verified; names and types await human review. */

extern void *FUN_00000bcc(int size);
extern void *FUN_00056110(void *p, int b, int c);
extern void FUN_000574c4(int a, int b, void *c, int d);

void FUN_000573a0(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    if (param_3 != 0) {
        void *p = FUN_00000bcc(16);
        if (p != 0) {
            p = FUN_00056110(p, param_3, param_4);
        }
        FUN_000574c4(param_1, param_2, p, param_5);
    } else {
        FUN_000574c4(param_1, param_2, 0, param_5);
    }
}
