/* HSTMATCH module=EBOOT.BIN start=0x00127788 end=0x001277e8 symbol=FUN_00127788 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
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

extern undefined4 DAT_0033b4a8;
extern undefined4 DAT_0033b4ac;
extern void FUN_000006e8();
extern void FUN_000009e4();
extern void FUN_00055e48();

void FUN_00127788(void)
{
  if (DAT_0033b4ac != 0) {
    if (DAT_0033b4ac != 0) {
      FUN_000009e4(DAT_0033b4ac + -0x10);
    }
    DAT_0033b4ac = 0;
  }
  if (DAT_0033b4a8 != 0) {
    FUN_000006e8(DAT_0033b4a8,FUN_00055e48);
    DAT_0033b4a8 = 0;
  }
  return;
}
