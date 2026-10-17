/* HSTMATCH module=hstp_trans_main.prx start=0x001d4674 end=0x001d4720 symbol=FUN_001d4674 lang=c++ */
/* Clone of src/eboot/debug_print_table_001c627c.cpp (hstclone.py tag s10170158a4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Debug-print loop through the empty variadic stub 0x47d58: ten rows (format, string, DAT_002d6914[i]), each followed by six (format, string, j + 1) lines, then a closing line. The inner `if (i < 10)` is kept as retail tests it. */
extern "C" void FUN_000481dc(...);
extern char DAT_003b8f08[];
extern char DAT_003923a8[];
extern char DAT_003923b0[];
extern char DAT_003923b8[];
extern int DAT_002d6914[];

extern "C" void FUN_001d4674(void)
{
  for (int i = 0; i < 10; i++) {
    FUN_000481dc(DAT_003b8f08, DAT_003923a8, DAT_002d6914[i]);
    if (i < 10) {
      for (int j = 0; j < 6; j++) {
        FUN_000481dc(DAT_003b8f08, DAT_003923b0, j + 1);
      }
    }
  }
  FUN_000481dc(DAT_003b8f08, DAT_003923b8);
}
