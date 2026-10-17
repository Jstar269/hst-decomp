/* HSTMATCH module=EBOOT.BIN start=0x0022c834 end=0x0022c84c symbol=FUN_0022c834 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
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

extern undefined * DAT_003415a8;
extern uint * FUN_000149a8();

void FUN_0022c834(undefined4 param_1)
{
  FUN_000149a8(DAT_003415a8 + 0xe010,param_1);
  return;
}
