/* HSTMATCH module=EBOOT.BIN start=0x001ee950 end=0x001ee998 symbol=FUN_001ee950 lang=c99 */
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

extern void FUN_000c4040();

int FUN_001ee950(int param_1)
{
  uint iVar1;

  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  iVar1 = *(uint *)(param_1 + 0x28);
  if (iVar1 < 4) {
    FUN_000c4040(param_1 + 0x28,4);
  }
  return param_1;
}
// Near miss: 2 of 18 words differ; retail uses move v0,zero before sw zero,48(a0), while this source reloads the zeroed field at +0x28.
// Tried a local constant, a constant-bounded loop, and the final assignment value; MWCC folded the guard each time.
// near miss from lane u6cr1-2 (unreviewed)
