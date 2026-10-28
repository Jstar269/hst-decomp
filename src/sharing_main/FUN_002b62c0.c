/* HSTMATCH module=hstp_trans_main.prx start=0x002b62c0 end=0x002b62f8 symbol=FUN_002b62c0 lang=c99 */
/* Clone of src/eboot/FUN_002a6b30.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00108aec();
extern void FUN_002b5df8();

void FUN_002b62c0(int param_1)
{
  if (*(int *)(param_1 + 0x880) == 0) {
    FUN_002b5df8();
  }
  FUN_00108aec(param_1);
}
