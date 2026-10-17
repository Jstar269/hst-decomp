/* HSTMATCH module=EBOOT.BIN start=0x001233bc end=0x001233e0 symbol=FUN_001233bc lang=c99 */
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

extern undefined4 FUN_00125218();
extern void FUN_00126304();

void FUN_001233bc(void)
{
  undefined4 uVar1;
  
  uVar1 = FUN_00125218();
  FUN_00126304(uVar1);
  return;
}
