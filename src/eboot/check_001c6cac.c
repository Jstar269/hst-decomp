/* HSTMATCH module=EBOOT.BIN start=0x001c6cac end=0x001c6cf4 symbol=FUN_001c6cac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: return condition variable directly and negate equality !(x == 1); exact match verified; names and types await human review. */
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

int FUN_001c6cac(int param_1)
{
  int iVar3 = *(int *)(param_1 + 0x15c);
  int cond = *(int *)(iVar3 + 0x6c) >= 0;
  if (!cond) {
    cond = *(int *)(iVar3 + 4) == 2;
  }
  if (cond) {
    cond = !(*(int *)(*(int *)(iVar3 + 0x20) + 0x54) == 1);
  }
  return cond;
}
