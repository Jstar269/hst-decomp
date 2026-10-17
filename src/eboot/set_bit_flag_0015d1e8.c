/* HSTMATCH module=EBOOT.BIN start=0x0015d1e8 end=0x0015d244 symbol=FUN_0015d1e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the shifted bit is a signed char local OR-ed into the byte field (seb/andi, no shift mask); exact match verified; names and types await human review. */
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

extern code * FUN_0022cd60();

void FUN_0015d1e8(uint param_1)
{
  int iVar1;
  signed char m;
  iVar1 = (int)(FUN_0022cd60());
  m = 1 << param_1;
  *(byte *)(iVar1 + 0xf0) |= m;
  if (param_1 == 0) {
    *(undefined1 *)(iVar1 + 0x13c) = 1;
  }
  else if (param_1 == 2) {
    *(undefined1 *)(iVar1 + 0x13d) = 1;
  }
  return;
}
