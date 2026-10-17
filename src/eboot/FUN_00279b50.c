/* HSTMATCH module=EBOOT.BIN start=0x00279b50 end=0x00279b7c symbol=FUN_00279b50 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
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


void FUN_00279b50(char *param_1)
{
  int iVar1;
  
  if ((0 < *(int *)(param_1 + 0x45c)) &&
     (iVar1 = *(int *)(param_1 + 0x45c) + -1, *(int *)(param_1 + 0x45c) = iVar1, iVar1 < 1)) {
    *(undefined4 *)(param_1 + 0x45c) = 0;
    *(undefined1 *)(param_1 + 0x454) = 1;
  }
  return;
}
