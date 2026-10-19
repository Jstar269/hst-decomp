/* HSTMATCH module=hstp_trans_main.prx start=0x0012e5b4 end=0x0012e644 symbol=FUN_0012e5b4 lang=c99 */
/* Clone of src/eboot/FUN_001233e0.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003e47dc;
extern int DAT_003e47e0;

int FUN_0012e5b4(int param_1, int mode)
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
    DAT_003e47dc = 0;
    DAT_003e47e0 = 0;
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
