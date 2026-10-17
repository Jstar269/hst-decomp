/* HSTMATCH module=hstp_trans_main.prx start=0x00066f5c end=0x00066ff0 symbol=FUN_00066f5c lang=c99 */
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

extern undefined4 FUN_00002f60();
extern int * FUN_00066ff0();

void FUN_00066f5c(int *param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1 + param_1[1] * 0xc;
  for (; param_2 != param_3; param_2 = param_2 + 0xc) {
    iVar1 = FUN_00002f60(0xc,iVar2);
    if (iVar1 != 0) {
      FUN_00066ff0(iVar1,param_2);
    }
    iVar1 = param_1[1];
    iVar2 = iVar2 + 0xc;
    param_1[1] = iVar1 + 1;
  }
  return;
}
// Near miss: only the stack adjustment differs: this source uses a 32-byte frame and retail uses 48 bytes. The loop, allocation null branch, copy call, and shared count update match.
// near miss from lane u1r2-2 (unreviewed)
