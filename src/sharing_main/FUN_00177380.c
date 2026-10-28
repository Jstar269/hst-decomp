/* HSTMATCH module=hstp_trans_main.prx start=0x00177380 end=0x001773a0 symbol=FUN_00177380 lang=c99 */
/* Clone of src/eboot/FUN_0016b19c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

extern int FUN_00177434();

int FUN_00177380(void)
{
  int iVar1;
  
  iVar1 = FUN_00177434();
  return (int)*(short *)(iVar1 + 2);
}
