/* HSTMATCH module=EBOOT.BIN start=0x001c9750 end=0x001c97b0 symbol=FUN_001c9750 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned int DAT_0034a2e0;
extern void FUN_00225d40(unsigned int, int, int);
extern int FUN_0022bf74(int);
void FUN_001c9750(void)
{
  int i = 0;
  do {
    int found = FUN_0022bf74(i) != 0;
    int not_found = found ^ 1;
    if (not_found == 0) {
      FUN_00225d40(DAT_0034a2e0, i, 0);
      return;
    }
    i++;
  } while (i < 256);
}