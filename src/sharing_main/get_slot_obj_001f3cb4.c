/* HSTMATCH module=hstp_trans_main.prx start=0x001f3cb4 end=0x001f3cdc symbol=FUN_001f3cb4 lang=c99 */
/* Clone of src/eboot/get_slot_obj_001e5a9c.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_002320bc(int);
int FUN_001f3cb4(int self)
{
  int p = *(int *)(self + 0x1954);
  if (!p) return 0;
  return FUN_002320bc(p);
}
