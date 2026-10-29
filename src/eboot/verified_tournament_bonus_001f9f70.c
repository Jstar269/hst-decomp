/* HSTMATCH module=EBOOT.BIN start=0x001f9f70 end=0x001fa018 symbol=FUN_001f9f70 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034a678;
extern unsigned char DAT_003418bc[];
extern int DAT_003386b0;
extern unsigned char DAT_00341954;
extern void FUN_0008882c(int);
extern int FUN_001fb524(int);
extern void FUN_0024e07c(int, int);
extern void FUN_0024e0ec(int, int);

void FUN_001f9f70(int param_1, int param_2)
{
    int uVar1;

    switch (DAT_0034a678) {
    case 0x31:
        if (DAT_003418bc[*(int *)(param_1 + 0x3cc) * 0x120] == 0) {
            FUN_0008882c(DAT_003386b0);
            uVar1 = FUN_001fb524(param_1);
            FUN_0024e07c(param_2, uVar1);
            if (*(unsigned char *)(param_1 + 0x521) != 0) {
                FUN_0024e0ec(param_2, DAT_00341954);
            }
        }
        break;
    }
}
