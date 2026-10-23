/* HSTMATCH module=EBOOT.BIN start=0x0018c39c end=0x0018c4dc symbol=FUN_0018c39c lang=c99 */
/* Hand-written reconstruction (external matching lane): the two copies are guarded by
   `if (iVar2 != 0) { if (iVar1 != 0) {...} } else { <table check> }` so the iVar2==0 block is laid
   out last; each row walk is `if (0 < count) { do { iVar4 = stride; .. } while (i >= 0 && i < count); }`
   with the stride load at the TOP of the body, which is what puts the reload in the bnezl delay slot.
   Exact match verified; names and types await human review. */
extern int DAT_0034156c[];
extern int DAT_00341530[];
extern int FUN_00051450(int);
extern void FUN_00011090(int, int, int);

void FUN_0018c39c(int param_1, int param_2, int param_3, int param_4)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;

    iVar1 = (*(int (**)(int, int))(param_1 + 0x7c))(param_3, param_4);
    iVar2 = (*(int (**)(int, int))(param_1 + 0x80))(param_3, param_4);
    if (iVar2 != 0) {
        if (iVar1 != 0) {
            iVar2 = FUN_00051450(param_2);
            iVar5 = 0;
            if (0 < *(int *)(param_1 + 0x4c)) {
                do {
                    iVar4 = *(int *)(param_1 + 0x48);
                    iVar3 = iVar5 * iVar4 * 2;
                    FUN_00011090(iVar2 + iVar3, iVar1 + iVar3, iVar4 << 1);
                    iVar5 = iVar5 + 1;
                } while (iVar5 < *(int *)(param_1 + 0x4c));
            }
        }
    } else {
        if (DAT_0034156c[param_3] != 0) {
            iVar2 = DAT_00341530[param_3];
            iVar1 = FUN_00051450(param_2);
            iVar5 = 0;
            if (0 < *(int *)(param_1 + 0x4c)) {
                do {
                    iVar4 = *(int *)(param_1 + 0x48);
                    iVar3 = iVar5 * iVar4 * 2;
                    FUN_00011090(iVar1 + iVar3, iVar2 + iVar3, iVar4 << 1);
                    iVar5 = iVar5 + 1;
                } while (iVar5 < *(int *)(param_1 + 0x4c));
            }
        }
    }
}
