/* HSTMATCH module=EBOOT.BIN start=0x0024dd40 end=0x0024dd8c symbol=FUN_0024dd40 lang=c99 */
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


int FUN_0024dd40(float param_1,int param_2)
{
  int iVar1;
  
  param_2 = param_2 + 0x20;
  iVar1 = 8;
  do {
    if (*(float *)(param_2 + 0x30) <= param_1) { return iVar1 + 1; }
    iVar1 = iVar1 + -1;
    param_2 = param_2 + -4;
  } while (iVar1 >= 0);
  return iVar1 + 1;
}
// Near miss: one word at +0x40 is addiu v0,a1,1 here while retail emits move v0,zero. Direct-return and break/shared-return spellings were compared; the final loop result stays in the wrong return slot.
// near miss from lane u5cr3-0 (unreviewed)
