/* HSTMATCH module=EBOOT.BIN start=0x002ad938 end=0x002ad998 symbol=FUN_002ad938 lang=c99 */
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

extern undefined4 DAT_0034a678;
extern int FUN_0016bb88();
extern void FUN_002ad758();

void FUN_002ad938(void)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (DAT_0034a678 == 0x20) {
    uVar2 = 2;
  }
  else if (DAT_0034a678 == 2) {
    uVar2 = 2;
  }
  uVar1 = FUN_0016bb88();
  FUN_002ad758(uVar2,uVar1,0);
  return;
}
// Near miss: 6 words differ in the mode-test branch layout and result setup; changing the result value did not remove those differences, so the generated candidate remains the best supported source.
// near miss from lane u5cr1-1 (unreviewed)
