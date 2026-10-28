/* HSTMATCH module=hstp_trans_main.prx start=0x002a5b90 end=0x002a5b98 symbol=FUN_002a5b90 lang=c99 */
/* Clone of src/eboot/FUN_00295cc4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_0011d7f8(float param_1,int param_2);

void FUN_002a5b90(float param_1,int param_2)
{
  FUN_0011d7f8(param_1,*(int *)(param_2 + 100));
}
