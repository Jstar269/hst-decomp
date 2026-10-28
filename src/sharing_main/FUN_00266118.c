/* HSTMATCH module=hstp_trans_main.prx start=0x00266118 end=0x00266160 symbol=FUN_00266118 lang=c99 */
/* Clone of src/eboot/FUN_00255c68.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00105470();

void FUN_00266118(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + param_2 * 0xa4 + param_3 * 4);
  if (iVar1 != 0) {
    FUN_00105470(iVar1,1);
  }
}
