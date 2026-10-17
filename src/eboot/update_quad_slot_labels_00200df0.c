/* HSTMATCH module=EBOOT.BIN start=0x00200df0 end=0x00200f48 symbol=FUN_00200df0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_00200df0.c (tag: a1) */
extern unsigned char *DAT_0034a13c;
extern void FUN_000ffb3c(int, int);
extern void FUN_0010b8cc(int, int, int);

void FUN_00200df0(int param_1)
{
    int iVar7;
    int *puVar6;
    int iVar5;
    int iVar4;
    int *piVar3;
    int *piVar2;
    int *puVar1;

    iVar7 = *(int *)(DAT_0034a13c + 0x50);
    FUN_0010b8cc(*(int *)(param_1 + 0x708), iVar7, 2);
    iVar5 = 0;
    iVar4 = 0;
    do {
        piVar3 = (int *)(param_1 + (iVar4 + 0x550)) + 0xc;
        piVar2 = (int *)(param_1 + (iVar4 + 0x578)) + 0xc;
        puVar1 = (int *)(param_1 + (iVar4 + 0x5a0)) + 0xc;
        puVar6 = (int *)(param_1 + (iVar4 + 0x5c8)) + 0xc;
        if (iVar7 == iVar5) {
            FUN_000ffb3c(*piVar3, 0);
            *(int *)(*piVar3 + 0x24) = *(int *)(*piVar3 + 0x28) + (1 - iVar5);
            FUN_000ffb3c(*puVar1, 0);
            FUN_000ffb3c(*piVar2, 1);
            FUN_000ffb3c(*puVar6, 1);
        } else {
            FUN_000ffb3c(*piVar3, 1);
            FUN_000ffb3c(*puVar1, 1);
            FUN_000ffb3c(*piVar2, 0);
            *(int *)(*piVar2 + 0x24) = *(int *)(*piVar2 + 0x28) + (1 - iVar5);
            FUN_000ffb3c(*puVar6, 0);
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x14;
    } while (iVar5 < 2);
}
