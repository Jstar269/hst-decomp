/* HSTMATCH module=EBOOT.BIN start=0x0008d1ec end=0x0008d22c symbol=FUN_0008d1ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern uint * FUN_000114c0();

int FUN_0008d1ec(int param_1)
{
  FUN_000114c0(param_1,0,0x6c);
  *(undefined2 *)(param_1 + 0x68) = 0xffff;
  *(undefined2 *)(param_1 + 0x6a) = 0xffff;
  *(undefined2 *)(param_1 + 0x24) = 0xffff;
  return param_1;
}
