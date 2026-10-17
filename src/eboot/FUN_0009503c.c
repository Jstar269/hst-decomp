/* HSTMATCH module=EBOOT.BIN start=0x0009503c end=0x00095058 symbol=FUN_0009503c lang=c99 */
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


void FUN_0009503c(int param_1)
{
  *(undefined4 *)(param_1 + 0x1b0) = 6;
  *(undefined4 *)(param_1 + 0x1b4) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x1b8) = 0;
  *(undefined1 *)(param_1 + 0x1ba) = 0;
  return;
}
