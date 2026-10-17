/* HSTMATCH module=EBOOT.BIN start=0x000a817c end=0x000a81b4 symbol=FUN_000a817c lang=c99 */
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

extern undefined4 DAT_00338b44;
extern void FUN_000dc820();
extern void FUN_000dc90c();

void FUN_000a817c(int param_1)
{
  FUN_000dc90c(DAT_00338b44,*(undefined4 *)(param_1 + 0x144),*(undefined4 *)(param_1 + 0x148));
  FUN_000dc820(DAT_00338b44);
  return;
}
