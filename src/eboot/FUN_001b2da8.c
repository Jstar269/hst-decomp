/* HSTMATCH module=EBOOT.BIN start=0x001b2da8 end=0x001b2de8 symbol=FUN_001b2da8 lang=c99 */
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

extern int FUN_00062418();

void FUN_001b2da8(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0x2c0);
  if ((iVar1 != 0) && (iVar1 != 0)) {
    FUN_00062418(iVar1,1);
    *(undefined4 *)(iVar2 + 0x2c0) = 0;
  }
  return;
}
