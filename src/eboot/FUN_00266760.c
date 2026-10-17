/* HSTMATCH module=EBOOT.BIN start=0x00266760 end=0x002667b8 symbol=FUN_00266760 lang=c99 */
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

extern undefined4 FUN_0012c364();
extern undefined4 FUN_0012c5ac();
extern void FUN_002667fc();

void FUN_00266760(int param_1)
{
  uchar cVar1;
  undefined1 uVar2;
  
  cVar1 = FUN_0012c364(param_1 + 0x80);
  if (cVar1 != '\0') {
    uVar2 = FUN_0012c5ac(param_1 + 0x80);
    *(undefined1 *)(param_1 + 0x120) = uVar2;
    if (*(uchar *)(param_1 + 0x120) == '\0') {
      FUN_002667fc(param_1,1);
    }
  }
  return;
}
