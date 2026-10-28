/* HSTMATCH module=hstp_trans_main.prx start=0x0021ed70 end=0x0021eda0 symbol=FUN_0021ed70 lang=c99 */
/* Clone of src/eboot/FUN_00210134.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern float DAT_003ea4b4;
extern float DAT_003ea4bc;

float FUN_0021ed70(float param_1)
{
  return DAT_003ea4b4 * 0.01f + DAT_003ea4bc * 0.01f * param_1;
}
