/* HSTMATCH module=EBOOT.BIN start=0x001fb374 end=0x001fb3bc symbol=FUN_001fb374 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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


void FUN_001fb374(int param_1)
{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1030) = 0;
  *(undefined4 *)(param_1 + 0x1034) = 0;
  iVar1 = 0;
  do {
    *(undefined4 *)(param_1 + 0xf90) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xf94) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xf98) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xf9c) = 0xffffffff;
    *(undefined4 *)(param_1 + 4000) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xfa4) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xfa8) = 0xffffffff;
    iVar1 = iVar1 + 8;
    *(undefined4 *)(param_1 + 0xfac) = 0xffffffff;
    param_1 = param_1 + 0x20;
  } while (iVar1 < 0x28);
  return;
}
