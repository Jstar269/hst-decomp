/* HSTMATCH module=EBOOT.BIN start=0x000b9edc end=0x000b9efc symbol=FUN_000b9edc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;


void FUN_000b9edc(int param_1)
{
  int iVar1;
  
  iVar1 = (*(int *)(param_1 + 0x6c) + 1) % 3;
  *(int *)(param_1 + 0x6c) = iVar1;
  *(int *)(param_1 + 100) = iVar1;
  return;
}
