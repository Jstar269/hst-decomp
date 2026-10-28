/* HSTMATCH module=hstp_trans_main.prx start=0x00001178 end=0x000011b0 symbol=FUN_00001178 lang=c99 */
/* Clone of src/eboot/invoke_slot_00001178.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
void FUN_00001178(int *self)
{
  if (self[0] == 0) return;
  if (self[2] == 0) return;
  ((void (*)(int,int))self[2])(self[0],-1);
}
