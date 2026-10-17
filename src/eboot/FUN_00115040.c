/* HSTMATCH module=EBOOT.BIN start=0x00115040 end=0x00115088 symbol=FUN_00115040 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern void FUN_001142b0();

void FUN_00115040(int param_1,undefined4 param_2)
{
  *(undefined1 *)(*(int *)(param_1 + 0x54) + 0x90a) = 1;
  *(undefined4 *)(param_1 + 0x80) = param_2;
  FUN_001142b0(param_1,5);
  *(undefined4 *)(param_1 + 0x80) = param_2;
  return;
}
