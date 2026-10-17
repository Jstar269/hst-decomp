/* HSTMATCH module=EBOOT.BIN start=0x0018a950 end=0x0018a960 symbol=FUN_0018a950 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
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

extern void FUN_0010d4a8();

void FUN_0018a950(int param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x78);
  *(undefined4 *)(iVar1 + 0xf8) = param_2;
  *(undefined4 *)(iVar1 + 0x138) = 0;
  FUN_0010d4a8(iVar1);
  return;
}
