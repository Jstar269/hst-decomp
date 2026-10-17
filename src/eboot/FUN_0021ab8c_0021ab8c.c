/* HSTMATCH module=EBOOT.BIN start=0x0021ab8c end=0x0021abe0 symbol=FUN_0021ab8c lang=c99 rodata=0x002c98c0 */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0r) corrected by hand: indexed the table as base[index + 0x3b] to emit the retail index-first address addition; exact match verified; names and types await human review. */
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


undefined4 FUN_0021ab8c(int *param_1)
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *base;
  int index;
  
  bVar1 = false;
  switch(param_1[1]) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 8:
  case 9:
  case 10:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
    bVar1 = true;
  }
  if (bVar1) {
    base = (undefined4 *)*param_1;
    index = *(int *)((char *)base + 0xe8);
    uVar2 = base[index + 0x3b];
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
