/* HSTMATCH module=EBOOT.BIN start=0x0016b998 end=0x0016ba08 symbol=FUN_0016b998 lang=c99 */
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

extern volatile int DAT_002e0488;
extern volatile int DAT_002e048c;
extern int FUN_0016bb88();

void FUN_0016b998(ushort param_1)
{
  int iVar1;
  int low;
  int value;
  int high;
  
  iVar1 = FUN_0016bb88();
  low = DAT_002e0488;
  value = param_1;
  if (value < DAT_002e0488) {
    *(short *)(iVar1 + 0x1038) = (short)low;
  }
  else {
    high = DAT_002e048c;
    if (value > DAT_002e048c) {
      high = DAT_002e048c;
    }
    else {
      high = value;
    }
    *(ushort *)(iVar1 + 0x1038) = (ushort)high;
  }
  return;
}// Best near miss: 6 differing words remain in the upper-bound compare/store branch and its delay slots.
// near miss from lane u1r1-0 (unreviewed)
