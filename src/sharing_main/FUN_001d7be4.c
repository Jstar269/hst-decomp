/* HSTMATCH module=hstp_trans_main.prx start=0x001d7be4 end=0x001d7c44 symbol=FUN_001d7be4 lang=c99 */
/* Clone of src/eboot/FUN_001c9750.c (hstclone.py tag u6cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned int DAT_003f3610;
extern void FUN_002352b4(unsigned int, int, int);
extern int FUN_0023b9e4(int);
void FUN_001d7be4(void)
{
  int i = 0;
  do {
    int found = FUN_0023b9e4(i) != 0;
    int not_found = found ^ 1;
    if (not_found == 0) {
      FUN_002352b4(DAT_003f3610, i, 0);
      return;
    }
    i++;
  } while (i < 256);
}