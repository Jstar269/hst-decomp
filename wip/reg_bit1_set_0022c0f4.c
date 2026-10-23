/* HSTMATCH module=EBOOT.BIN start=0x0022c0f4 end=0x0022c15c symbol=FUN_0022c0f4 lang=c99 */
extern int DAT_003415a8;

void FUN_0022c0f4(int param_1,int param_2)
{
  if (param_1 == 0) {
    *(unsigned short *)(DAT_003415a8 + 0x10000 - 11004) =
      *(unsigned short *)(DAT_003415a8 + 0x10000 - 11004) & 0xfffd;
  }
  else {
    *(unsigned short *)(DAT_003415a8 + 0x10000 - 11004) =
      *(unsigned short *)(DAT_003415a8 + 0x10000 - 11004) | 2;
  }
  *(int *)(DAT_003415a8 + 0x10000 - 11040) = param_2;
}

// NEAR MISS: 20/26 words. Same bit set/clear as 0x0022c07c for bit 1, plus a trailing store of param_2 to DAT_003415a8+0x10000-11040 (that store's single addu already matches); the duplicated set/clear address is the whole gap.
// near miss from lane fm5 (unreviewed)
