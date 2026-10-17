/* HSTMATCH module=hstp_trans_main.prx start=0x001c0214 end=0x001c0260 symbol=FUN_001c0214 lang=c99 */
/* Clone of src/eboot/call_then_notify_001b2180.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a2) corrected by hand: float parameter (f12) between the object and the int pointer, early return 0 on failure; exact match verified; names and types await human review. */
extern int FUN_001c04cc(int a, int *p);
extern void FUN_00063980(int a, float f);

int FUN_001c0214(int a, float f, int *p)
{
  if (FUN_001c04cc(a, p) == 0) return 0;
  FUN_00063980(*p, f);
  return 1;
}
