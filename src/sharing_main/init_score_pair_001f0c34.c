/* HSTMATCH module=hstp_trans_main.prx start=0x001f0c34 end=0x001f0ca8 symbol=FUN_001f0c34 lang=c99 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT sibling src/eboot/init_score_pair_001e29e0.c, same instruction shape with this module's addresses): both arms read DAT_00393850 at their top, so the address is materialised first and the value loaded after the 0x3c/0x60 chain (hoisting the read changes the bnel delay-slot copy); exact match verified; names and types await human review. */
extern int DAT_00393850;
extern unsigned char DAT_003eaaf0;
extern void FUN_00105470(int);

void FUN_001f0c34(int param_1)
{
    int iVar1;
    int iVar2;

    FUN_00105470(*(int *)(*(int *)(param_1 + 0x3c) + 0x60));
    if (DAT_003eaaf0 == 1) {
        iVar1 = DAT_00393850 + 1;
        iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 0x60);
        *(int *)(iVar2 + 0x24) = iVar1;
        *(int *)(iVar2 + 0x28) = iVar1;
    } else {
        iVar1 = DAT_00393850;
        iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 0x60);
        *(int *)(iVar2 + 0x24) = iVar1;
        *(int *)(iVar2 + 0x28) = iVar1;
    }
}
