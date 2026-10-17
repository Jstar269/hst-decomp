/* HSTMATCH module=EBOOT.BIN start=0x00225b00 end=0x00225b6c symbol=FUN_00225b00 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_00225b00.c (tag: a1) */
extern int DAT_002f1210[];
extern void FUN_000f68b4(int, int);
extern void FUN_00225b78(int, int);

void FUN_00225b00(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    FUN_000f68b4(*(int *)(*(int *)(param_1 + 0x3c) + 0x30), DAT_002f1210[param_2]);
    if (param_5 != 0) {
        FUN_00225b78(param_1, param_2);
    }
}
