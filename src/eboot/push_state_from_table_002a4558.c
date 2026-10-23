/* HSTMATCH module=EBOOT.BIN start=0x002a4558 end=0x002a45d8 symbol=FUN_002a4558 lang=c99 */
/* Hand-written reconstruction (external matching lane): the table read has to happen inside the
   second half of the && (a comma in the condition) so that it is issued after FUN_0022c988 and
   before the 0x1b0 == 5 test, which is retail's order; hoisting it into its own statement moves
   the load past the call. Exact match verified; names and types await human review. */
extern int DAT_002cc07c[];
extern int FUN_0022c1c4();
extern int FUN_0022c988(int);
extern void FUN_002a2488(int, int);

void FUN_002a4558(int param_1)
{
    int iVar1;
    int iVar2;
    int uVar3;

    iVar1 = FUN_0022c1c4();
    iVar2 = FUN_0022c988(iVar1);
    if (iVar2 == 0 && ((uVar3 = DAT_002cc07c[iVar1]), *(int *)(param_1 + 0x1b0) != 5)) {
        *(int *)(param_1 + 0x1c0) = *(int *)(param_1 + 0x1b8);
        *(int *)(param_1 + 0x1b8) = uVar3;
        *(int *)(param_1 + 0x1bc) = 0;
        FUN_002a2488(param_1, 1);
    }
}
