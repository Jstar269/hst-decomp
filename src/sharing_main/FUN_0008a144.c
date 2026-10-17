/* HSTMATCH module=hstp_trans_main.prx start=0x0008a144 end=0x0008a19c symbol=FUN_0008a144 lang=c99 */
/* Clone of src/eboot/FUN_000889ec.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: kept the four ordered case comparisons in one result-setting switch; exact match verified; names and types await human review. */
extern unsigned char DAT_003e19f8;
int FUN_0008a144(int self) {
  int result = 0;
  if (DAT_003e19f8 == 0) {
    switch (*(int *)(self + 0x3c)) {
      case 4:
      case 5:
      case 6:
      case 7:
        result = 1;
        break;
    }
  }
  return result;
}
