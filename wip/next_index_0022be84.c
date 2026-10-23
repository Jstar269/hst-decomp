/* HSTMATCH module=EBOOT.BIN start=0x0022be84 end=0x0022bf24 symbol=FUN_0022be84 lang=c99 */
extern int FUN_0022b6a0();
extern void FUN_0022b02c(int, int, int);

int FUN_0022be84(int param_1, int param_2, int param_3, int param_4)
{
    int iVar1;
    int iVar2;

    iVar1 = FUN_0022b6a0();
    if (param_3 <= iVar1) {
        iVar1 = 0;
    }
    iVar2 = iVar1 + 1;
    iVar2 = iVar2 % param_3;
    if (param_4 != 0 && iVar2 == 0 && 1 < param_3) {
        iVar2 = iVar2 + 1;
    }
    FUN_0022b02c(param_1, param_2, iVar2);
    return iVar1;
}
// near miss from lane fm3 (unreviewed)
