/* HSTMATCH module=EBOOT.BIN start=0x0012ce50 end=0x0012cea0 symbol=FUN_0012ce50 lang=c99 */
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

extern undefined4 DAT_003313c4;
extern undefined4 DAT_00338714;
extern int FUN_0005ba78();
extern void FUN_00140acc();
extern void FUN_00145c5c();

void FUN_0012ce50(undefined4 param_1)
{
  if (DAT_00338714 != 0) {
    FUN_0005ba78(DAT_00338714,DAT_003313c4);
  }
  FUN_00140acc(param_1);
  FUN_00145c5c(param_1);
  return;
}
