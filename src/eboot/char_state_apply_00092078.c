/* HSTMATCH module=EBOOT.BIN start=0x00092078 end=0x00092258 symbol=FUN_00092078 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: restored the float types, split the table index into two statements and reordered the float/int call parameters; exact match verified; names and types await human review. */
extern float DAT_002d2900;
extern float DAT_002d2904;
extern void FUN_00058f38(int, float, int);
extern void FUN_0005f030(float, int, int);
extern void FUN_0005f110(int, float);
extern void FUN_00093750(float, int, int, int);
extern void FUN_00093778(int, int, int);
extern void FUN_00093be0(int, int);
extern void FUN_00093c08(int, int);

void FUN_00092078(float param_1, int param_2, int param_3, int param_4, int param_5)
{
    float local_4;
    float fVar2;
    float *pfVar3;
    int iVar4;
    int bVar1;

    local_4 = param_1;
    bVar1 = 0;
    if (*(int *)(param_2 + 0x58) != 0) {
        iVar4 = param_5 * 0x34;
        iVar4 += *(int *)(param_2 + 0x58);
        iVar4 = *(int *)(iVar4 + 0xf0);
    } else
        iVar4 = -1;
    if (param_3 != iVar4) {
        bVar1 = 1;
        FUN_00093778(param_2, param_4, param_5);
        if (DAT_002d2900 < local_4)
            pfVar3 = &local_4;
        else
            pfVar3 = &DAT_002d2900;
        FUN_00093750(*pfVar3, param_2, param_5, param_3);
        if (param_3 >= 0)
            FUN_00093be0(param_2, param_5);
        else
            FUN_00093c08(param_2, param_5);
    }
    if (((param_5 == 0) && (iVar4 = *(int *)(param_2 + 0x50), iVar4 != 0)) &&
        (param_3 != *(int *)(iVar4 + 0xa0)) && (iVar4 != 0)) {
        if (DAT_002d2904 < local_4)
            pfVar3 = &local_4;
        else
            pfVar3 = &DAT_002d2904;
        FUN_0005f030(*pfVar3, iVar4, param_3);
        *(char *)(*(int *)(param_2 + 0x50) + 0xc0) = (char)param_4;
        *(float *)(*(int *)(param_2 + 0x50) + 0xd0) = *(float *)(*(int *)(param_2 + 0x50) + 0xc4);
    }
    fVar2 = local_4;
    if ((local_4 >= 0.0f) && (param_3 >= 0)) {
        iVar4 = *(int *)(param_2 + 0x58);
        if ((iVar4 != 0) && (!bVar1)) {
            FUN_00058f38(iVar4, fVar2, param_5);
            FUN_0005f110(iVar4, fVar2);
        }
        if ((param_5 == 0) && (*(int *)(param_2 + 0x50) != 0))
            FUN_0005f110(*(int *)(param_2 + 0x50), local_4);
    }
}
