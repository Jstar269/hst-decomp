/* HSTMATCH module=EBOOT.BIN start=0x000c210c end=0x000c2158 symbol=FUN_000c210c lang=c99 */
/* Clone of src/eboot/store_float_by_mode_000c1fdc.c (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1) corrected by hand: the nested conditional stores are a switch on the mode (cases 1, 0, 2 in source order) storing the float argument; exact match verified; names and types await human review. */
extern int DAT_002d5a8c;
extern float DAT_003412e8;
extern float DAT_003412f0;
extern float DAT_003412f8;

void FUN_000c210c(float v)
{
  switch (DAT_002d5a8c) {
  case 1:
    DAT_003412e8 = v;
    break;
  case 0:
    DAT_003412f0 = v;
    break;
  case 2:
    DAT_003412f8 = v;
    break;
  }
}
