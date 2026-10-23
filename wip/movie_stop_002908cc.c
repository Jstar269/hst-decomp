/* HSTMATCH module=EBOOT.BIN start=0x002908cc end=0x00290b0c symbol=FUN_002908cc lang=c99 */
/* NEAR MISS 146/144 words, 91 differing: the early-return guard for the non-(4|0x200) status (which is what makes
   retail place the else block inline after the two compares), the thread wait/delete sequence and the
   `return ok != 0` sltu all match; the psmf status loop and the handle blocks still schedule differently. */
extern char DAT_002ff534[];
extern char DAT_002ff6c8[];
extern char DAT_002ff6fc[];
extern char DAT_002ff714[];
extern char DAT_002cabe4[];
extern char DAT_002cabbc[];
extern char DAT_002ff408[];
extern char DAT_002ff3e0[];
extern char DAT_002ff434[];
extern char DAT_002ff3bc[];

extern void FUN_0028fb44(const char *, ...);
extern int FUN_002b7ee0(int);
extern int FUN_002b7e78(int);
extern int FUN_002b7e90(int);
extern int FUN_002b7ed8(int);
extern void FUN_002b7958(int);
extern int FUN_002b7980(int, int);
extern int FUN_002b79a8(void);

int FUN_002908cc(int param_1)
{
  int ok;
  int v;
  int i;

  if (*(unsigned char *)(param_1 + 0x28) == 0) {
    FUN_0028fb44(DAT_002ff534);
    return 0;
  }
  ok = 1;
  v = FUN_002b7ee0(param_1);
  if (v < 0) {
    FUN_0028fb44(DAT_002ff6c8, v);
    ok = 0;
  }
  if (v != 4 && v != 0x200) {
    *(unsigned char *)(param_1 + 0x29) = 0;
    FUN_0028fb44(DAT_002ff6fc, v);
    return 1;
  }
    i = FUN_002b7e78(param_1);
    if (i != 0) {
      FUN_0028fb44(DAT_002ff3bc, i);
      ok = 0;
    }
    while ((i = FUN_002b7ee0(param_1)) >= 0) {
      if (i == 2)
        break;
      FUN_002b7958(1000);
    }
    if (*(int *)(param_1 + 0x80) >= 0) {
      i = FUN_002b7980(*(int *)(param_1 + 0x80), 0);
      if (i != 0)
        FUN_0028fb44(DAT_002cabe4, i);
    }
    if (*(int *)(param_1 + 0x80) >= 0) {
      i = FUN_002b79a8();
      if (i != 0)
        FUN_0028fb44(DAT_002cabbc, i);
      *(int *)(param_1 + 0x80) = -1;
    }
    if (*(int *)(param_1 + 0x64) >= 0) {
      i = FUN_002b7980(*(int *)(param_1 + 0x64), 0);
      if (i != 0)
        FUN_0028fb44(DAT_002cabe4, i);
    }
    if (*(int *)(param_1 + 0x64) >= 0) {
      i = FUN_002b79a8();
      if (i != 0)
        FUN_0028fb44(DAT_002cabbc, i);
      *(int *)(param_1 + 0x64) = -1;
    }
    i = FUN_002b7ed8(param_1);
    if (i != 0) {
      FUN_0028fb44(DAT_002ff408, i);
      ok = 0;
    }
    if (v != 1 && v != 0) {
      i = FUN_002b7e90(param_1);
      if (i != 0) {
        FUN_0028fb44(DAT_002ff3e0, i);
        ok = 0;
      }
      FUN_0028fb44(DAT_002ff434);
    }
    *(unsigned char *)(param_1 + 0x29) = 0;
    FUN_0028fb44(DAT_002ff714);
  return ok != 0;
}
// near miss from lane fm7 (unreviewed)
