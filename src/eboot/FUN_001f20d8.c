/* HSTMATCH module=EBOOT.BIN start=0x001f20d8 end=0x001f2264 symbol=FUN_001f20d8 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
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
    switch (n) {
    case 0:
        *(int *)(param_1 + 0x8190) = 1;
        break;
    case 1:
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
        break;
    case 2:
        n = *(int *)(param_1 + 0x8194) + 1;
        *(int *)(param_1 + 0x8194) = n;
        if (n > 5)
            FUN_001fb928((int)param_1 + 0x3c, 0x13, 1);
        break;
    }
    FUN_001f4bfc((int)param_1);
    FUN_001f483c((int)param_1);
}