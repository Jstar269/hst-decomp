/* HSTMATCH module=EBOOT.BIN start=0x001233e0 end=0x00123470 symbol=FUN_001233e0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0033b49c;
extern int DAT_0033b4a0;

int FUN_001233e0(int param_1, int mode)
{
  switch (mode) {
  case 0:
  case 1:
    break;
  case 8:
    *(unsigned char *)(param_1 + 140) = 0;
    *(unsigned char *)(param_1 + 122) = 1;
    *(unsigned char *)(param_1 + 123) = 0;
    *(unsigned char *)(param_1 + 124) = 0;
    DAT_0033b49c = 0;
    DAT_0033b4a0 = 0;
    break;
  case 9:
  case 10:
  case 11:
  case 14:
  case 15:
    break;
  default:
    break;
  }
  return 0;
}
