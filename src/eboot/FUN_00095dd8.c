/* HSTMATCH module=EBOOT.BIN start=0x00095dd8 end=0x00095e10 symbol=FUN_00095dd8 lang=c99 */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern uint * FUN_000114c0();

int FUN_00095dd8(int param_1)
{
  *(undefined4 *)(param_1 + 0x2c) = 1;
  FUN_000114c0(param_1,0,0x40);
  return param_1;
}
