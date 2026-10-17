/* HSTMATCH module=EBOOT.BIN start=0x001c627c end=0x001c6328 symbol=FUN_001c627c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Debug-print loop through the empty variadic stub 0x47d58: ten rows (format, string, DAT_002c6404[i]), each followed by six (format, string, j + 1) lines, then a closing line. The inner `if (i < 10)` is kept as retail tests it. */
extern "C" void FUN_00047d58(...);
extern char DAT_0030fc10[];
extern char DAT_002ea678[];
extern char DAT_002ea680[];
extern char DAT_002ea688[];
extern int DAT_002c6404[];

extern "C" void FUN_001c627c(void)
{
  for (int i = 0; i < 10; i++) {
    FUN_00047d58(DAT_0030fc10, DAT_002ea678, DAT_002c6404[i]);
    if (i < 10) {
      for (int j = 0; j < 6; j++) {
        FUN_00047d58(DAT_0030fc10, DAT_002ea680, j + 1);
      }
    }
  }
  FUN_00047d58(DAT_0030fc10, DAT_002ea688);
}
