/* HSTMATCH module=EBOOT.BIN start=0x001b2380 end=0x001b23c0 symbol=FUN_001b2380 lang=c99 */
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

extern void FUN_001b0ef8();
extern void FUN_001b1810();

void FUN_001b2380(undefined4 *param_1)
{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  FUN_001b0ef8(uVar1,0x58,0,0,0);
  FUN_001b1810(uVar1);
  return;
}
