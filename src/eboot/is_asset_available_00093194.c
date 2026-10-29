/* HSTMATCH module=EBOOT.BIN start=0x00093194 end=0x000931ec symbol=FUN_00093194 lang=c99 data=0x002d2a64 */
/* Ghidra pseudocode (hstgen.py tag a1/v2) corrected by hand: used an integer result and the retail early return layout; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d2a64-0x002d2a6f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern char DAT_002d2890[]; /* bone name to replace */
extern int FUN_00014934(); /* string compare */
extern unsigned int * FUN_000149a8(); /* string copy */

/* Rename the bone in place to "Bip01LHand" when it equals DAT_002d2890; returns 1 when renamed. */
int FUN_00093194(char *name)
{
  int differs;

  if (name != 0) {
    differs = FUN_00014934(name,DAT_002d2890);
    if (differs == 0) {
      FUN_000149a8(name,"Bip01LHand");
      return 1;
    }
  }
  return 0;
}
