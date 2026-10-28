/* HSTMATCH module=hstp_trans_main.prx start=0x00177360 end=0x00177380 symbol=FUN_00177360 lang=c99 */
/* Clone of src/eboot/FUN_0016b19c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

extern int FUN_001773e0();

int FUN_00177360(void)
{
  int iVar1;
  
  iVar1 = FUN_001773e0();
  return (int)*(short *)(iVar1 + 2);
}
