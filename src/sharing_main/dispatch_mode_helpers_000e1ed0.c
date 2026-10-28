/* HSTMATCH module=hstp_trans_main.prx start=0x000e1ed0 end=0x000e1f40 symbol=FUN_000e1ed0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh128a) corrected by hand: declared the helpers with their object argument and ordered the mode cases; exact match verified; names and types await human review. */

extern void FUN_000e1f40(int);
extern void FUN_000e1f48(int);

void FUN_000e1ed0(int param_1)
{
  int mode = *(int *)(param_1 + 0x3c);
  if (mode == 4) return;
  if (mode == 3) return;
  switch (mode) {
    case 0: break;
    case 1: FUN_000e1f40(param_1); break;
    case 2: FUN_000e1f48(param_1); break;
    default: break;
  }
}
