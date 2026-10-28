/* HSTMATCH module=hstp_trans_main.prx start=0x000638c8 end=0x00063900 symbol=FUN_000638c8 lang=c99 */
/* Clone of src/eboot/reset_if_valid_00062a04.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00077c58(void);
extern void FUN_00063900(int);
void FUN_000638c8(int a)
{
  if (a < 0) return;
  FUN_00077c58();
  FUN_00063900(a);
}
