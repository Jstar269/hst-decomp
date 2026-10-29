/* HSTMATCH module=hstp_trans_main.prx start=0x0020c350 end=0x0020c384 symbol=FUN_0020c350 lang=c99 */
/* Clone of src/eboot/FUN_001fdb80.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_0001ef14();
extern void FUN_002104c4();

/* Releases the sub-object at 0x1250, then forwards to the base cleanup. */
void FUN_0020c350(int self)
{
  FUN_002104c4(self + 0x1250);
  FUN_0001ef14(self,0);
}
