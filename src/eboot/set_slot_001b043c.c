/* HSTMATCH module=EBOOT.BIN start=0x001b043c end=0x001b04d0 symbol=FUN_001b043c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag FUN_001b043c) corrected by hand: slot pointer is (int *)((char *)param_1 + 0x778) + param_2 computed once and reused, shared iVar2 = param_3 + 0x15b, constant select if/else; exact match verified; names and types await human review. */
extern void FUN_001b0610();
extern void FUN_001b0ef8(int, int, int, int, int);

void FUN_001b043c(int param_1, int param_2, int param_3, int param_4)
{
    int *piVar1;
    int uVar2;
    int iVar2;

    piVar1 = (int *)((char *)param_1 + 0x778) + param_2;
    if (*piVar1 != 0) {
        FUN_001b0610();
    }
    iVar2 = param_3 + 0x15b;
    if (param_4 != 0) {
        uVar2 = 1;
    } else {
        uVar2 = 2;
    }
    FUN_001b0ef8(param_1, iVar2, uVar2, 0, 0);
    *piVar1 = *(int *)(param_1 + iVar2 * 4);
}
