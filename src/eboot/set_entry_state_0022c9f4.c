/* HSTMATCH module=EBOOT.BIN start=0x0022c9f4 end=0x0022ca58 symbol=FUN_0022c9f4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char *DAT_003415a8;  /* address of the global system block */
extern void FUN_001bf62c();
extern int FUN_0022ca58();

#define DEFAULT_ENTRY_VALUE 200

/* When the predicate is false, resets the per-index halfword to 200, then forwards. */
void FUN_0022c9f4(int index)
{
  short *values;

  if (FUN_0022ca58() == 0) {
    values = (short *)(DAT_003415a8 + 0xd4e6);
    values[index] = DEFAULT_ENTRY_VALUE;
  }
  FUN_001bf62c(DAT_003415a8 + 0x80, index, 4);
}
