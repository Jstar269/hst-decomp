/* HSTMATCH module=EBOOT.BIN start=0x002044b4 end=0x0020452c symbol=FUN_002044b4 lang=c99 */
/* Clone of src/eboot/format_slot_kind_0020443c.c (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1) corrected by hand: the or-chain on kind is a switch (case 2..5 -> 99), typed ints; exact match verified; names and types await human review. */
extern char DAT_002ef600[];
extern void FUN_000143b0(int a, char *fmt, int b, int c);

void FUN_002044b4(int a, int b, int c, int kind)
{
  switch (kind) {
  case 2:
  case 3:
  case 4:
  case 5:
    FUN_000143b0(a, DAT_002ef600, 99, c);
    break;
  default:
    FUN_000143b0(a, DAT_002ef600, b, c);
    break;
  }
}
