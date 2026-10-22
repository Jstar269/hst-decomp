/* HSTMATCH module=EBOOT.BIN start=0x001afef4 end=0x001aff8c symbol=FUN_001afef4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern void FUN_001b043c();
extern void FUN_001b0ef8();

void FUN_001afef4(int param_1,int param_2)
{
  int iVar1;
  
  FUN_001b0ef8(param_1,param_2 * 2 + 0xc3,0,0,0);
  FUN_001b0ef8(param_1,param_2 * 2 + 0xe1,0,0,0);
  FUN_001b043c(param_1,0,param_2,0);
  iVar1 = (param_2 << 3) + param_1;
  *(undefined4 *)(param_1 + 0x768) = *(undefined4 *)(iVar1 + 0x30c);
  *(undefined4 *)(param_1 + 0x76c) = *(undefined4 *)(iVar1 + 900);
  *(int *)(param_1 + 0x7d8) = param_2;
  *(undefined1 *)(param_1 + 0x7dc) = 0;
  return;
}
