/* HSTMATCH module=EBOOT.BIN start=0x000c1fdc end=0x000c2028 symbol=FUN_000c1fdc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1) corrected by hand: the nested conditional stores are a switch on the mode (cases 1, 0, 2 in source order) storing the float argument; readability pass; exact match verified; names and types await human review. */
extern int DAT_002d5a8c;
extern float DAT_003412e4;
extern float DAT_003412ec;
extern float DAT_003412f4;

/* Stores the value into the slot selected by the current mode. */
void FUN_000c1fdc(float value)
{
  switch (DAT_002d5a8c) {
  case 1:
    DAT_003412e4 = value;
    break;
  case 0:
    DAT_003412ec = value;
    break;
  case 2:
    DAT_003412f4 = value;
    break;
  }
}
