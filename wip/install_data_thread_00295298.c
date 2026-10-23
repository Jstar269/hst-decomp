/* HSTMATCH module=EBOOT.BIN start=0x00295298 end=0x002954c8 symbol=FUN_00295298 lang=c99 */
/* NEAR MISS 136/140 words, 116 differing: the for(;;) + narrow `stop` flag gives retail's `sltu`, the varargs
   calls, offsets and error paths are right; MWCC still omits the `xori` and puts the finish block out of line
   where retail has it inline right after the test. */
extern char DAT_002cae8c[];
extern char DAT_002caedc[];
extern char DAT_002caee8[];
extern char DAT_002caef4[];
extern char DAT_002caf40[];
extern char DAT_002caf90[];
extern char DAT_002caf9c[];
extern char DAT_002cafec[];
extern char DAT_002caff8[];
extern char DAT_002cb00c[];
extern char DAT_002cb058[];
extern char DAT_002cb0a8[];

extern int FUN_00296d60(void);
extern void FUN_00294684(const char *, ...);
extern int FUN_002954c8(int, int);
extern int FUN_002973ec(const char *, ...);
extern int FUN_00297188(void);
extern int FUN_00296ff8(void);
extern void FUN_002b7888(int);
extern int FUN_002b79b0(int);

int FUN_00295298(int param_1, int *param_2)
{
  int obj;
  int ret;
  int i;
  unsigned char stop;

  obj = *param_2;
  ret = FUN_00296d60();
  *(int *)(obj + 0x1c) = ret;
  if (ret < 0) {
    FUN_00294684(DAT_002cb0a8, ret);
    ret = *(int *)(obj + 0x1c);
  } else {
    for (;;) {
      FUN_002954c8(obj, 0x7fffffff);
      stop = (*(unsigned char *)(obj + 0x20) != 0);
      if (!stop) {
        if (*(unsigned char *)(obj + 0x21) != 0) {
          FUN_00294684(DAT_002caff8);
          ret = FUN_002973ec(DAT_002cafec, (long long)*(int *)(obj + 0x18), *(int *)(obj + 4),
                             *(int *)(obj + 8));
          *(int *)(obj + 0x1c) = ret;
          if (ret < 0) {
            ret = FUN_00297188();
            if (ret < 0)
              FUN_00294684(DAT_002caf9c, ret);
          } else {
            *(int *)(obj + 0x18) = *(int *)(obj + 0xc);
            *(int *)(obj + 8) = 0;
            ret = FUN_00296ff8();
            *(int *)(obj + 0x1c) = ret;
            if (ret < 0)
              FUN_00294684(DAT_002caef4, ret);
          }
          break;
        }
        if (*(int *)(obj + 8) < 0x80000) {
          FUN_002b7888(34000);
        } else {
          ret = FUN_002973ec(DAT_002caf90, (long long)*(int *)(obj + 0x18), *(int *)(obj + 4));
          *(int *)(obj + 0x1c) = ret;
          if (ret < 0) {
            ret = FUN_00297188();
            if (ret < 0)
              FUN_00294684(DAT_002caf40, ret);
            break;
          }
          *(int *)(obj + 0x18) = *(int *)(obj + 0x18) + 0x80000;
          *(int *)(obj + 8) = 0;
        }
      } else {
        *(int *)(obj + 0x1c) = 0x80000006;
        if (*(int *)(obj + 0x18) < 1) {
          ret = FUN_00296ff8();
          if (ret < 0)
            FUN_00294684(DAT_002cb00c, ret);
        } else {
          ret = FUN_00297188();
          if (ret < 0)
            FUN_00294684(DAT_002cb058, ret);
        }
        break;
      }
    }
    ret = *(int *)(obj + 0x1c);
  }
  if (ret < 0)
    FUN_00294684(DAT_002caedc, ret);
  else
    FUN_00294684(DAT_002caee8);
  ret = FUN_002b79b0(0);
  if (ret < 0)
    FUN_00294684(DAT_002cae8c, ret);
  return 0;
}
// near miss from lane fm7 (unreviewed)
