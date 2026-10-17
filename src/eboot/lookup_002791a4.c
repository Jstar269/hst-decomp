/* HSTMATCH module=EBOOT.BIN start=0x002791a4 end=0x0027920c symbol=FUN_002791a4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: grouped valid switch cases around the shared table lookup; exact match verified; names and types await human review. */
extern char DAT_002fe5e8[];
extern void FUN_0026f7f4();
int FUN_002791a4(int param_1, int param_2)
{
  int value;
  switch (param_2) {
    case 1:
    case 2:
    case 3:
    case 4: {
      int offset = param_2 * 4;
      value = *(int *)(offset + param_1 + 0x114);
      break;
    }
    default:
      FUN_0026f7f4(DAT_002fe5e8);
      value = 4;
      break;
  }
  return value - 4;
}
