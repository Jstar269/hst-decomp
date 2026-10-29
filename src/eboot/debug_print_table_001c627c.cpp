/* HSTMATCH module=EBOOT.BIN start=0x001c627c end=0x001c6328 symbol=FUN_001c627c lang=c++ data=0x002ea678 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002ea678-0x002ea68a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Debug-print loop through the empty variadic stub 0x47d58: ten rows (format, string, DAT_002c6404[i]), each followed by six (format, string, j + 1) lines, then a closing line. The inner `if (i < 10)` is kept as retail tests it. */
enum { ROW_COUNT = 10, COLUMN_COUNT = 6 };

extern "C" void FUN_00047d58(...);
extern char DAT_0030fc10[];
extern int DAT_002c6404[];

extern "C" void FUN_001c627c(void)
{
  for (int i = 0; i < ROW_COUNT; i++) {
    FUN_00047d58(DAT_0030fc10, "%-8s", DAT_002c6404[i]);
    if (i < ROW_COUNT) {
      for (int j = 0; j < COLUMN_COUNT; j++) {
        FUN_00047d58(DAT_0030fc10, "%02d", j + 1);
      }
    }
  }
  FUN_00047d58(DAT_0030fc10, ">");
}
