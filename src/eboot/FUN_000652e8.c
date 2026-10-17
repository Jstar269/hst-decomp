/* HSTMATCH module=EBOOT.BIN start=0x000652e8 end=0x0006531c symbol=FUN_000652e8 lang=c99 */
/* Clone of src/sharing_main/FUN_00066384.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00064a88();
extern void FUN_00066240();

void FUN_000652e8(int param_1)
{
  FUN_00064a88();
  FUN_00066240(param_1 + 0x10);
  FUN_00066240(param_1 + 0x20);
  return;
}
