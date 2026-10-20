/* HSTMATCH module=EBOOT.BIN start=0x001306e0 end=0x0013076c symbol=FUN_001306e0 lang=c99 */
extern int DAT_0034a678;
extern float DAT_002db18c;
extern int FUN_0022c860(void);

unsigned char FUN_001306e0(int param_1)
{
  if (DAT_0034a678 == 0x2a) {
    if (FUN_0022c860() != 0) {
      if (*(float *)(*(int *)(param_1 + 0x80) + 0x68) > 30.0f * DAT_002db18c) return 1;
      return 0;
    }
    return *(unsigned char *)(*(int *)(param_1 + 0x84) + 0x40);
  }
  return *(unsigned char *)(*(int *)(param_1 + 0x84) + 0x40);
}
// near miss from lane ds4 (unreviewed)
