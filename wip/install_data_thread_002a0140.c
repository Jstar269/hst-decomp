/* HSTMATCH module=EBOOT.BIN start=0x002a0140 end=0x002a0370 symbol=FUN_002a0140 lang=c99 */
/* NEAR MISS (same body as 0x00295298, offsets +4, 0x40000 chunk): 136/140 words; MWCC omits retail's `xori`
   and keeps the finish block out of line where retail places it inline after the loop test. */
extern char DAT_002cbbf0[];
extern char DAT_002cbc80[];
extern char DAT_002cbc8c[];
extern char DAT_002cbbbc[];
extern char DAT_002cbc08[];
extern char DAT_002cbc58[];
extern char DAT_002cbc64[];
extern char DAT_002cbcb4[];
extern char DAT_002cbcc0[];
extern char DAT_002cbcd4[];
extern char DAT_002cbd20[];
extern char DAT_002cbd70[];

extern int FUN_00296d60(void);
extern void FUN_0029e3cc(const char *, ...);
extern int FUN_0029f70c(int, int);
extern int FUN_002973ec(const char *, ...);
extern int FUN_00297188(void);
extern int FUN_00296ff8(void);
extern void FUN_002b7888(int);
extern int FUN_002b79b0(int);

int FUN_002a0140(int param_1, int *param_2)
{
  int obj;
  int ret;
  int i;
  unsigned char stop;

  obj = *param_2;
  ret = FUN_00296d60();
  *(int *)(obj + 0x20) = ret;
  if (ret < 0) {
    FUN_0029e3cc(DAT_002cbd70, ret);
    ret = *(int *)(obj + 0x20);
  } else {
    for (;;) {
      FUN_0029f70c(obj, 0x7fffffff);
      stop = (*(unsigned char *)(obj + 0x24) != 0);
      if (!stop) {
        if (*(unsigned char *)(obj + 0x25) != 0) {
          FUN_0029e3cc(DAT_002cbcc0);
          ret = FUN_002973ec(DAT_002cbcb4, (long long)*(int *)(obj + 0x1c), *(int *)(obj + 8),
                             *(int *)(obj + 0xc));
          *(int *)(obj + 0x20) = ret;
          if (ret < 0) {
            ret = FUN_00297188();
            if (ret < 0)
              FUN_0029e3cc(DAT_002cbc64, ret);
          } else {
            *(int *)(obj + 0x1c) = *(int *)(obj + 0x10);
            *(int *)(obj + 0xc) = 0;
            ret = FUN_00296ff8();
            *(int *)(obj + 0x20) = ret;
            if (ret < 0)
              FUN_0029e3cc(DAT_002cbbbc, ret);
          }
          break;
        }
        if (*(int *)(obj + 0xc) < 0x40000) {
          FUN_002b7888(34000);
        } else {
          ret = FUN_002973ec(DAT_002cbc58, (long long)*(int *)(obj + 0x1c), *(int *)(obj + 8));
          *(int *)(obj + 0x20) = ret;
          if (ret < 0) {
            ret = FUN_00297188();
            if (ret < 0)
              FUN_0029e3cc(DAT_002cbc08, ret);
            break;
          }
          *(int *)(obj + 0x1c) = *(int *)(obj + 0x1c) + 0x40000;
          *(int *)(obj + 0xc) = 0;
        }
      } else {
        *(int *)(obj + 0x20) = 0x40000006;
        if (*(int *)(obj + 0x1c) < 1) {
          ret = FUN_00296ff8();
          if (ret < 0)
            FUN_0029e3cc(DAT_002cbcd4, ret);
        } else {
          ret = FUN_00297188();
          if (ret < 0)
            FUN_0029e3cc(DAT_002cbd20, ret);
        }
        break;
      }
    }
    ret = *(int *)(obj + 0x20);
  }
  if (ret < 0)
    FUN_0029e3cc(DAT_002cbc80, ret);
  else
    FUN_0029e3cc(DAT_002cbc8c);
  ret = FUN_002b79b0(0);
  if (ret < 0)
    FUN_0029e3cc(DAT_002cbbf0, ret);
  return 0;
}
// near miss from lane fm7 (unreviewed)
