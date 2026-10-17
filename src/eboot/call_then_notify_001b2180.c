/* HSTMATCH module=EBOOT.BIN start=0x001b2180 end=0x001b21cc symbol=FUN_001b2180 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a2) corrected by hand: float parameter (f12) between the object and the int pointer, early return 0 on failure; exact match verified; names and types await human review. */
extern int FUN_001b2438(int a, int *p);
extern void FUN_00062abc(int a, float f);

int FUN_001b2180(int a, float f, int *p)
{
  if (FUN_001b2438(a, p) == 0) return 0;
  FUN_00062abc(*p, f);
  return 1;
}
