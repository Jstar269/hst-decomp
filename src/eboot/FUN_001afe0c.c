/* HSTMATCH module=EBOOT.BIN start=0x001afe0c end=0x001afe6c symbol=FUN_001afe0c lang=c99 */
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

extern void FUN_001b04d0();

void FUN_001afe0c(int param_1)
{
  *(undefined4 *)(param_1 + 0x7cc) = 0x1da;
  FUN_001b04d0(param_1,0x3e);
  FUN_001b04d0(param_1,0x53);
  FUN_001b04d0(param_1,0xaf);
  FUN_001b04d0(param_1,0xae);
  FUN_001b04d0(param_1,1);
  return;
}
