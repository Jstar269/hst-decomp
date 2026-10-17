/* HSTMATCH module=EBOOT.BIN start=0x0020443c end=0x002044b4 symbol=FUN_0020443c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1) corrected by hand: the or-chain on kind is a switch (case 2..5 -> 99), typed ints; exact match verified; names and types await human review. */
extern char DAT_002ef5dc[];
extern void FUN_000143b0(int a, char *fmt, int b, int c);

void FUN_0020443c(int a, int b, int c, int kind)
{
  switch (kind) {
  case 2:
  case 3:
  case 4:
  case 5:
    FUN_000143b0(a, DAT_002ef5dc, 99, c);
    break;
  default:
    FUN_000143b0(a, DAT_002ef5dc, b, c);
    break;
  }
}
