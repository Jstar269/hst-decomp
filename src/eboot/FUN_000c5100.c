/* HSTMATCH module=EBOOT.BIN start=0x000c5100 end=0x000c5110 symbol=FUN_000c5100 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
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


void FUN_000c5100(int param_1)
{
  *(undefined1 *)(*(int *)(param_1 + 0x784) + 4) = 1;
  return;
}
