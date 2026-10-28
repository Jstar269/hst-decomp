/* HSTMATCH module=hstp_trans_main.prx start=0x00100bb4 end=0x00100be8 symbol=FUN_00100bb4 lang=c99 */
/* Clone of src/eboot/FUN_000fb478.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_000fc08c(int param_1,int param_2,float *param_3);

void FUN_00100bb4(int param_1,int param_2,float *param_3)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x3c) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x8c), iVar1 != 0)) {
    FUN_000fc08c(iVar1,param_2,param_3);
  }
}
