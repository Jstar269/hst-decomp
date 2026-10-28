/* HSTMATCH module=hstp_trans_main.prx start=0x000ed168 end=0x000ed1c4 symbol=FUN_000ed168 lang=c99 */
/* Clone of src/eboot/FUN_000e8094.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */

void FUN_000ed168(int param_1)
{
  int iVar1;
  
  *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0x40) - 0.14285715f;
  iVar1 = *(int *)(param_1 + 0x314) + 10;
  *(int *)(param_1 + 0x314) = iVar1;
  *(int *)(param_1 + 0x314) = iVar1 % 0x168;
  *(float *)(param_1 + 0x310) = *(float *)(param_1 + 0x310) + 0.2f;
  *(int *)(param_1 + 0x318) = *(int *)(param_1 + 0x318) + 1;
}
