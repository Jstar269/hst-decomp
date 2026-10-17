/* HSTMATCH module=EBOOT.BIN start=0x001b8754 end=0x001b87e8 symbol=FUN_001b8754 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char uchar;

extern int DAT_0034179c;
extern void FUN_001b4240(int *, float);
extern void FUN_001b4464(int *, int);

void FUN_001b8754(int param_1, int param_2)
{
  if (param_2 != 0 && *(uchar *)(param_1 + 0x78) != 0) {
    FUN_001b4464(&DAT_0034179c, param_2);
  }
  else if (param_2 == 0) {
    if (*(uchar *)(param_1 + 0x78) == 0) {
      FUN_001b4464(&DAT_0034179c, param_2);
      FUN_001b4240(&DAT_0034179c, 0.5f);
    }
  }
  *(uchar *)(param_1 + 0x78) = ((param_2 != 0) ^ 1);
}
