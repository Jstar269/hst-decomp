/* HSTMATCH module=hstp_trans_main.prx start=0x0020f5c0 end=0x0020f718 symbol=FUN_0020f5c0 lang=c99 */
/* Clone of src/eboot/update_quad_slot_labels_00200df0.c (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_0020f5c0.c (tag: a1) */
extern unsigned char *DAT_003f3474;
extern void FUN_00105470(int, int);
extern void FUN_00111aa4(int, int, int);

void FUN_0020f5c0(int param_1)
{
    int iVar7;
    int *puVar6;
    int iVar5;
    int iVar4;
    int *piVar3;
    int *piVar2;
    int *puVar1;

    iVar7 = *(int *)(DAT_003f3474 + 0x50);
    FUN_00111aa4(*(int *)(param_1 + 0x708), iVar7, 2);
    iVar5 = 0;
    iVar4 = 0;
    do {
        piVar3 = (int *)(param_1 + (iVar4 + 0x550)) + 0xc;
        piVar2 = (int *)(param_1 + (iVar4 + 0x578)) + 0xc;
        puVar1 = (int *)(param_1 + (iVar4 + 0x5a0)) + 0xc;
        puVar6 = (int *)(param_1 + (iVar4 + 0x5c8)) + 0xc;
        if (iVar7 == iVar5) {
            FUN_00105470(*piVar3, 0);
            *(int *)(*piVar3 + 0x24) = *(int *)(*piVar3 + 0x28) + (1 - iVar5);
            FUN_00105470(*puVar1, 0);
            FUN_00105470(*piVar2, 1);
            FUN_00105470(*puVar6, 1);
        } else {
            FUN_00105470(*piVar3, 1);
            FUN_00105470(*puVar1, 1);
            FUN_00105470(*piVar2, 0);
            *(int *)(*piVar2 + 0x24) = *(int *)(*piVar2 + 0x28) + (1 - iVar5);
            FUN_00105470(*puVar6, 0);
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x14;
    } while (iVar5 < 2);
}
