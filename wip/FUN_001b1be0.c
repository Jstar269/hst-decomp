/* HSTMATCH module=EBOOT.BIN start=0x001b1be0 end=0x001b1c44 symbol=FUN_001b1be0 lang=c99 */
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

extern void FUN_000628e4();
extern int FUN_00062a6c();
extern undefined4 FUN_00062b3c();

struct State_001b1be0 { char pad[2000]; int handle; };

void FUN_001b1be0(int *param_1)
{
  int handle;
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  handle = ((struct State_001b1be0 *)iVar2)->handle;
  if (handle <= 0) {
    return;
  }
  iVar1 = FUN_00062a6c();
  if (iVar1 == 0) {
    *(undefined4 *)(iVar2 + 2000) = 0xffffffff;
  }
  else {
    iVar1 = FUN_00062b3c(*(undefined4 *)(iVar2 + 2000));
    if (iVar1 < 1) {
      FUN_000628e4(*(undefined4 *)(iVar2 + 2000),1);
    }
  }
  return;
}
// Best near miss: 2 differing words remain; the initial handle load and blezl use v1 rather than retail a0. Raw and typed field views produced the same register choice.
// near miss from lane u1r1-0 (unreviewed)
