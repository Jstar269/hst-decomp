/* HSTMATCH module=EBOOT.BIN start=0x001aa244 end=0x001aa2a4 symbol=FUN_001aa244 lang=c99 */
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

extern undefined4 FUN_0019d474();

void FUN_001aa244(int param_1)
{
  int iVar1;
  int *pp;
  
  iVar1 = FUN_0019d474();
  pp = (int *)(param_1 + 0xc0);
  switch (*(int *)(iVar1 + 0x2f4)) {
    case 0:
      iVar1 = *pp;
      *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x28);
      break;
    case 1:
      iVar1 = *pp;
      *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x28) + 1;
      break;
    default:
      break;
  }
  return;
}

// Near miss: six instruction words remain; mode/pointer temporaries use a0/a1 opposite to retail, changing the condition and indirect-load operands.
// near miss from lane cx3 (unreviewed)
