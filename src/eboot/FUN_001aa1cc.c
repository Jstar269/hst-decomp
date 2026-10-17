/* HSTMATCH module=EBOOT.BIN start=0x001aa1cc end=0x001aa208 symbol=FUN_001aa1cc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
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

extern undefined4 FUN_0016b070();
extern undefined4 FUN_0019d474();

void FUN_001aa1cc(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_0019d474();
  iVar1 = FUN_0016b070(*(undefined4 *)(iVar1 + 0x2e4));
  *(int *)(*(int *)(param_1 + 0x98) + 0x24) = *(int *)(*(int *)(param_1 + 0x98) + 0x28) + iVar1;
  return;
}
