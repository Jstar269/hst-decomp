/* HSTMATCH module=EBOOT.BIN start=0x0012f3f0 end=0x0012f414 symbol=FUN_0012f3f0 lang=c99 */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef float undefined4;

extern void FUN_0012f248();

void FUN_0012f3f0(int param_1)
{
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x7c);
  FUN_0012f248();
  return;
}
