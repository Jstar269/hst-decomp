/* HSTMATCH module=EBOOT.BIN start=0x001b3148 end=0x001b31ac symbol=FUN_001b3148 lang=c99 */
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

extern void FUN_001b0ef8();

void FUN_001b3148(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = param_2 * 8;
  FUN_001b0ef8(iVar1,param_2 * 2 + 0x16a,0,0,0);
  *(undefined4 *)(iVar1 + 0x788) = *(undefined4 *)(iVar2 + iVar1 + 0x5a8);
  *(int *)(iVar1 + 0x7d8) = param_2;
  *(undefined1 *)(iVar1 + 0x7dc) = 1;
  return;
}
