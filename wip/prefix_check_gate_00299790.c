/* HSTMATCH module=EBOOT.BIN start=0x00299790 end=0x0029988c symbol=FUN_00299790 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern char DAT_002cb3d0[];
extern int FUN_002b7710();
extern int FUN_002b7780();

int FUN_00299790(char *param_1)
{
  int n;
  int i;
  int mismatch;
  int r;
  int t;
  int local;

  if (param_1 != 0) {
    n = 0;
    if (DAT_002cb3d0[0] != 0) {
      n = 1;
      while (n < 5 && DAT_002cb3d0[n] != 0) {
        n++;
      }
    }
    mismatch = 0;
    for (i = 0; i < n; i++) {
      if (DAT_002cb3d0[i] != param_1[i]) {
        mismatch = 1;
        break;
      }
    }
    if (!mismatch) {
      r = FUN_002b7780();
      if (r != 0x8001000d) {
        return r;
      }
      t = FUN_002b7710(DAT_002cb3d0,0x2425824,0,0,&local,4);
      if (t < 0) {
        local = t;
      }
      return (local == 1) ? -1 : 0x8001000d;
    }
  }
  return 0x800001fe;
}
// near miss from lane od3 (unreviewed)
