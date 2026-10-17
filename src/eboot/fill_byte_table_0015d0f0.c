/* HSTMATCH module=EBOOT.BIN start=0x0015d0f0 end=0x0015d16c symbol=FUN_0015d0f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: indexed the global destination array instead of walking a local output pointer; exact match verified; names and types await human review. */
extern unsigned char DAT_0034100c[];
extern unsigned char *DAT_00340400;
extern int FUN_0015cce8(unsigned int, int);
void FUN_0015d0f0(unsigned int self) {
  int i = 0;
  do {
    int entry = FUN_0015cce8(self, i);
    if (entry != 0) {
      DAT_0034100c[i] = DAT_00340400[i + *(int *)(entry + 0x20) + 0x10];
    } else {
      DAT_0034100c[i] = 0;
    }
    ++i;
  } while (i < 256);
}
