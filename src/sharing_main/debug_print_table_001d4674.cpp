/* HSTMATCH module=hstp_trans_main.prx start=0x001d4674 end=0x001d4720 symbol=FUN_001d4674 lang=c++ data=0x003923a8 */
/* Clone of src/eboot/debug_print_table_001c627c.cpp (hstclone.py tag s10170158a4r1s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x003923a8-0x003923ba) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Debug-print loop through the empty variadic stub 0x47d58: ten rows (format, string, DAT_002d6914[i]), each followed by six (format, string, j + 1) lines, then a closing line. The inner `if (i < 10)` is kept as retail tests it. */
extern "C" void FUN_000481dc(...);
extern char DAT_003b8f08[];
extern int DAT_002d6914[];

extern "C" void FUN_001d4674(void)
{
  for (int i = 0; i < 10; i++) {
    FUN_000481dc(DAT_003b8f08, "%-8s", DAT_002d6914[i]);
    if (i < 10) {
      for (int j = 0; j < 6; j++) {
        FUN_000481dc(DAT_003b8f08, "%02d", j + 1);
      }
    }
  }
  FUN_000481dc(DAT_003b8f08, ">");
}
