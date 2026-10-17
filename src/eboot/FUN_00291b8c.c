/* HSTMATCH module=EBOOT.BIN start=0x00291b8c end=0x00291c00 symbol=FUN_00291b8c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: express mode dispatch as a four-case switch with empty cases; exact match verified; names and types await human review. */
extern void FUN_00291c00(void *, int);
void FUN_00291b8c(void *param_1, int param_2)
{
  switch (param_2) {
    case 0:
      FUN_00291c00(param_1, 1);
      FUN_00291c00(param_1, 3);
      break;
    case 1:
      break;
    case 2:
      FUN_00291c00(param_1, 4);
      break;
    case 3:
      break;
  }
}
