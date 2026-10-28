/* HSTMATCH module=hstp_trans_main.prx start=0x000fbe24 end=0x000fbe68 symbol=FUN_000fbe24 lang=c99 */
/* Clone of src/eboot/FUN_000f6730.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00108e6c(float, int);

void FUN_000fbe24(int *param_1,int param_2)
{
  if (*param_1 != 0) {
    FUN_00108e6c((float)((float)param_2),(int)(*param_1));
  }
  param_1[4] = param_2;
}
