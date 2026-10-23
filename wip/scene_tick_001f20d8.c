/* HSTMATCH module=EBOOT.BIN start=0x001f20d8 end=0x001f2264 symbol=FUN_001f20d8 lang=c99 */
extern int DAT_003415ac;
extern void FUN_001e7b48(int);
extern int FUN_001fea10(int, int, int);
extern void FUN_00114168(int, int, int, int, int);
extern void FUN_0010b8cc(int, int, int);
extern void FUN_001fb928(int, int, int);
extern int FUN_001155c0(int);
extern void FUN_00103628(int, int);
extern int FUN_001156d4(int);
extern void FUN_001f94b8(int);
extern void FUN_001f4bfc(int);
extern void FUN_001f483c(int);

void FUN_001f20d8(char *param_1)
{
    int n;

    if (*(int *)(param_1 + 0x44) == 0) {
        FUN_001e7b48(*(int *)(param_1 + 0x510));
        FUN_00114168(DAT_003415ac, 1, FUN_001fea10(0x11, 0x12, 0), 0, 0);
        FUN_0010b8cc(*(int *)(*(int *)(DAT_003415ac + 0x58)), 0, 0);
        *(int *)(param_1 + 0x8190) = 0;
        *(int *)(param_1 + 0x8194) = 0;
    }
    n = *(int *)(param_1 + 0x8190);
    if (n == 2) {
        n = *(int *)(param_1 + 0x8194) + 1;
        *(int *)(param_1 + 0x8194) = n;
        if (n > 5)
            FUN_001fb928((int)param_1 + 0x3c, 0x13, 1);
    } else if (n == 1) {
        if (FUN_001155c0(DAT_003415ac) != 0) {
            FUN_00103628(DAT_003415ac, 1);
            *(char *)(param_1 + 0x8198) = 1;
            if (FUN_001156d4(DAT_003415ac) == 0) {
                *(int *)(param_1 + 0x8190) = 2;
                *(int *)(param_1 + 0x8194) = 0;
            } else {
                *(char *)(param_1 + 0x517) = 1;
                FUN_001f94b8((int)param_1);
            }
        }
    } else if (n == 0) {
        *(int *)(param_1 + 0x8190) = 1;
    }
    FUN_001f4bfc((int)param_1);
    FUN_001f483c((int)param_1);
}
// near miss: 100/99 words, 62 differ, first at +0x90. The +0x44 == 0 init block (FUN_001e7b48 /
// FUN_00114168(DAT_003415ac, 1, FUN_001fea10(0x11,0x12,0), 0, 0) / FUN_0010b8cc), the byte +0x8198
// write, the +0x8190 / +0x8194 zero pair and the reload of +0x8190 now match word for word: the
// parameter has to be `char *` (or every field cast `(char *)param_1 + off`) or MWCC builds
// `addiu v0,s0,32767` plus lwr/swr pairs instead of retail's per-access `lui 0x1; addu; sw`.
// Remaining delta: the state chain. Retail lays all three arms out of line (`beql a0,2`, `beql
// a0,1`, `beqzl a0`, `b end`); ours inlines the n == 2 arm (`bnel a0,v0,skip`) and a real
// `switch (n)` emits the compares ascending (0,1,2). Everything after the chain (the 1-arm calls
// and the FUN_001f4bfc / FUN_001f483c tail) is exact.
// improved by lane fm6 (unreviewed): 74 -> 62 differing words
