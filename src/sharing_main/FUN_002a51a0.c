/* HSTMATCH module=hstp_trans_main.prx start=0x002a51a0 end=0x002a51e0 symbol=FUN_002a51a0 lang=c99 */
/* Clone of src/eboot/FUN_00293b94.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

short * FUN_002a51a0(int param_1,int param_2,int param_3)
{
  short *psVar1;
  
  psVar1 = (short *)(*(int *)(param_1 + param_2 * 0xc) + param_3 * 10);
  if (*psVar1 == -1) {
    psVar1 = (short *)0x0;
  }
  return psVar1;
}
