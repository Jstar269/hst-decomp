/* HSTMATCH module=EBOOT.BIN start=0x0027dc90 end=0x0027dcd8 symbol=FUN_0027dc90 lang=c99 */
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

extern int *DAT_0034a7e4;

int *FUN_0027dc90(int param_1,int *param_2)
{
  int *base;
  int *p;
  int i;
  int off;

  base = DAT_0034a7e4;
  p = base;
  for (i = 0; i < 0x80; i++) {
    if (param_1 == *(int *)((char *)p + 0x30)) {
      off = i * 0x40;
      if (param_2 != 0) {
        *param_2 = i;
      }
      return (int *)((char *)base + off);
    }
    p = (int *)((char *)p + 0x40);
  }
  return 0;
}
// near miss from lane od3 (unreviewed)
