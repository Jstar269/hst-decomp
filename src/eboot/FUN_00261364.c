/* HSTMATCH module=EBOOT.BIN start=0x00261364 end=0x002613a0 symbol=FUN_00261364 lang=c99 */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern uint * FUN_000114c0();

void FUN_00261364(int param_1)
{
  FUN_000114c0(param_1,0,0x6c);
  *(undefined2 *)(param_1 + 0x68) = 0xffff;
  *(undefined2 *)(param_1 + 0x6a) = 0xffff;
  *(undefined2 *)(param_1 + 0x24) = 0xffff;
  return;
}
