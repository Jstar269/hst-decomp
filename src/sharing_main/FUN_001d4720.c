/* HSTMATCH module=hstp_trans_main.prx start=0x001d4720 end=0x001d474c symbol=FUN_001d4720 lang=c99 */
/* Clone of src/eboot/FUN_001c6328.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_001668dc();

void FUN_001d4720(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x15c) + 0x58);
  if (iVar1 != 0) {
    FUN_001668dc(iVar1);
  }
}
