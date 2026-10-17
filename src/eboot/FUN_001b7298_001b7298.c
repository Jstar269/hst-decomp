/* HSTMATCH module=EBOOT.BIN start=0x001b7298 end=0x001b7328 symbol=FUN_001b7298 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char uchar;

extern int DAT_0034179c;
extern int FUN_001b2af0(int *, int);

void FUN_001b7298(int param_1, int param_2)
{
  int result = 10;
  int flag = 0;

  if (*(uchar *)(param_1 + 0x90) != 0 && *(uchar *)(param_1 + 0x93) != 0)
    flag = 1;
  switch (param_2) {
  case 5:
    result = 9;
    break;
  case 4:
  case 3:
    result = flag ? 9 : 0x18;
    break;
  default:
    break;
  }
  result = FUN_001b2af0(&DAT_0034179c, result);
  *(int *)(param_1 + 0x58) = result;
}
