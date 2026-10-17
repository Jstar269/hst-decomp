/* HSTMATCH module=EBOOT.BIN start=0x001cc830 end=0x001cc880 symbol=FUN_001cc830 lang=c99 */
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

extern undefined4 DAT_0033b574;
extern void FUN_001cc8e8();
extern char FUN_002869cc();

void FUN_001cc830(int param_1)
{
  FUN_002869cc(DAT_0033b574 + 0x1320,param_1 + 0x114,1);
  *(undefined1 *)(param_1 + 0x114) = 0;
  *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x15c) + 0x20) + 0x6d) = 0;
  FUN_001cc8e8(param_1);
  return;
}
