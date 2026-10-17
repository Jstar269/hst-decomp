/* HSTMATCH module=EBOOT.BIN start=0x0027be20 end=0x0027be44 symbol=FUN_0027be20 lang=c99 */
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

extern undefined4 FUN_0027c75c();
extern void FUN_0027cc28();

void FUN_0027be20(void)
{
  undefined4 uVar1;
  
  uVar1 = FUN_0027c75c();
  FUN_0027cc28(uVar1);
  return;
}
