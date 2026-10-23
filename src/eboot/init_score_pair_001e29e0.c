/* HSTMATCH module=EBOOT.BIN start=0x001e29e0 end=0x001e2a54 symbol=FUN_001e29e0 lang=c99 */
/* Hand-written reconstruction (external matching lane): the two arms must read DAT_002eb9a0 at their
   top (address materialised first, value loaded after the 0x3c/0x60 chain) - hoisting `iVar1 =
   DAT_002eb9a0;` above the if, or reading it after the pointer in the else arm, changes which
   instruction mwcc copies into the bnel delay slot and costs 2-7 words. Exact match verified;
   names and types await human review. */
extern int DAT_002eb9a0;
extern unsigned char DAT_003417b8;
extern void FUN_000ffb3c(int);

void FUN_001e29e0(int param_1)
{
    int iVar1;
    int iVar2;

    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x3c) + 0x60));
    if (DAT_003417b8 == 1) {
        iVar1 = DAT_002eb9a0 + 1;
        iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 0x60);
        *(int *)(iVar2 + 0x24) = iVar1;
        *(int *)(iVar2 + 0x28) = iVar1;
    } else {
        iVar1 = DAT_002eb9a0;
        iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 0x60);
        *(int *)(iVar2 + 0x24) = iVar1;
        *(int *)(iVar2 + 0x28) = iVar1;
    }
}
