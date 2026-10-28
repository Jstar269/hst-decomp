/* HSTMATCH module=EBOOT.BIN start=0x000ddce4 end=0x000ddd54 symbol=FUN_000ddce4 lang=c99 */
/* Clone of src/sharing_main/dispatch_mode_helpers_000e1ed0.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh128a) corrected by hand: declared the helpers with their object argument and ordered the mode cases; exact match verified; names and types await human review. */

extern void FUN_000ddd54(int);
extern void FUN_000ddd5c(int);

void FUN_000ddce4(int param_1)
{
  int mode = *(int *)(param_1 + 0x3c);
  if (mode == 4) return;
  if (mode == 3) return;
  switch (mode) {
    case 0: break;
    case 1: FUN_000ddd54(param_1); break;
    case 2: FUN_000ddd5c(param_1); break;
    default: break;
  }
}
