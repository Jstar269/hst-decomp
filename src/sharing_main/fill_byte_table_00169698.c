/* HSTMATCH module=hstp_trans_main.prx start=0x00169698 end=0x00169714 symbol=FUN_00169698 lang=c99 */
/* Clone of src/eboot/fill_byte_table_0015d0f0.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: indexed the global destination array instead of walking a local output pointer; exact match verified; names and types await human review. */
extern unsigned char DAT_003ea34c[];
extern unsigned char *DAT_003e9740;
extern int FUN_00169290(unsigned int, int);
void FUN_00169698(unsigned int self) {
  int i = 0;
  do {
    int entry = FUN_00169290(self, i);
    if (entry != 0) {
      DAT_003ea34c[i] = DAT_003e9740[i + *(int *)(entry + 0x20) + 0x10];
    } else {
      DAT_003ea34c[i] = 0;
    }
    ++i;
  } while (i < 256);
}
