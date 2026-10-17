/* HSTMATCH module=EBOOT.BIN start=0x001b413c end=0x001b41c8 symbol=FUN_001b413c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: fixed parameter types, helper prototype and call arguments, and the early-return flow; exact match verified; names and types await human review. */
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
extern void FUN_00062b1c(int, float, int);

void FUN_001b413c(int *param_3,float param_1,float param_2)
{
  int iVar1;
  
  iVar1 = *param_3;
  if (*(int *)(iVar1 + 0x7ac) < 0) {
    return;
  }
  FUN_00062b1c(*(int *)(iVar1 + 0x7ac),param_2,(int)(param_1 * 128.0f));
  if (param_1 <= 0.0f) {
    *(undefined4 *)(iVar1 + 2000) = *(undefined4 *)(iVar1 + 0x7ac);
  }
  else if (*(int *)(iVar1 + 2000) >= 0) {
    FUN_000628e4(*(int *)(iVar1 + 2000),0);
    *(undefined4 *)(iVar1 + 2000) = 0xffffffff;
  }
  *(float *)(iVar1 + 0x7d4) = param_1;
  return;
}
