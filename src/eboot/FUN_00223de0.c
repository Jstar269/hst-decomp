/* HSTMATCH module=EBOOT.BIN start=0x00223de0 end=0x00223e18 symbol=FUN_00223de0 lang=c99 */
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
typedef unsigned int undefined4;

extern void FUN_000ffb3c();
extern void FUN_00103628();

void FUN_00223de0(int param_1)
{
  FUN_00103628(param_1,0);
  *(undefined1 *)(param_1 + 0x54) = 0;
  FUN_000ffb3c(*(undefined4 *)(param_1 + 100),1);
  return;
}
