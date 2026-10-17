/* HSTMATCH module=EBOOT.BIN start=0x000889ec end=0x00088a44 symbol=FUN_000889ec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: kept the four ordered case comparisons in one result-setting switch; exact match verified; names and types await human review. */
extern unsigned char DAT_003386b8;
int FUN_000889ec(int self) {
  int result = 0;
  if (DAT_003386b8 == 0) {
    switch (*(int *)(self + 0x3c)) {
      case 4:
      case 5:
      case 6:
      case 7:
        result = 1;
        break;
    }
  }
  return result;
}
