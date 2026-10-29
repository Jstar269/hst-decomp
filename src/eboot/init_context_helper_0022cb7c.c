/* HSTMATCH module=EBOOT.BIN start=0x0022cb7c end=0x0022cbd4 symbol=FUN_0022cb7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: nested if checks with shared final return 0; readability pass; exact match verified; names and types await human review. */
extern int DAT_003415a8;  /* address of the global system block */
extern char * DAT_0034a114;
extern int FUN_0028c4c0(int, int);

/* Forwards the object held by the global to a helper; a null `table` selects the setup table at +0x80. */
int FUN_0022cb7c(int table)
{
  if (DAT_0034a114 != 0) {
    int obj = *(int *)(DAT_0034a114 + 0x17c);
    if (obj != 0) {
      if (table == 0) {
        table = DAT_003415a8 + 0x80;
      }
      return FUN_0028c4c0(obj, table);
    }
  }
  return 0;
}
