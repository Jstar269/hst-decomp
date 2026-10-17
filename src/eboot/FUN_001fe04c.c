/* HSTMATCH module=EBOOT.BIN start=0x001fe04c end=0x001fe080 symbol=FUN_001fe04c lang=c99 */
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

extern void FUN_002019cc();
extern void FUN_0020212c();

void FUN_001fe04c(int param_1)
{
  FUN_002019cc(param_1 + 200);
  FUN_0020212c(param_1 + 0x1250,param_1 + 0xcd0);
  return;
}
