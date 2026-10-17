/* HSTMATCH module=EBOOT.BIN start=0x00198d68 end=0x00198de0 symbol=FUN_00198d68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: expressed range and null checks as ordered early returns; exact match verified; names and types await human review. */
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

extern uint * FUN_000149a8();
extern int FUN_00014a40();

void FUN_00198d68(int param_1,int param_2,int param_3)
{
  uint uVar1;

  if (param_2 < 0) return;
  if (param_2 >= 4) return;
  if (param_3 == 0) return;
  uVar1 = FUN_00014a40(param_3);
  if (uVar1 >= 8) return;
  FUN_000149a8(param_1 + param_2 * 8 + 0xa0,param_3);
  return;
}
