/* HSTMATCH module=hstp_trans_main.prx start=0x0028a488 end=0x0028a4f0 symbol=FUN_0028a488 lang=c99 */
/* Clone of src/eboot/lookup_002791a4.c (hstclone.py tag s10171846c1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: grouped valid switch cases around the shared table lookup; exact match verified; names and types await human review. */
extern char DAT_003a7310[];
extern void FUN_00280834();
int FUN_0028a488(int param_1, int param_2)
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
      FUN_00280834(DAT_003a7310);
      value = 4;
      break;
  }
  return value - 4;
}
