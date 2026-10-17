/* HSTMATCH module=EBOOT.BIN start=0x0012c994 end=0x0012c9a0 symbol=FUN_0012c994 lang=c99 */
/* Clone of src/eboot/FUN_0027c750.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_00338714;
extern void FUN_00093da4();

void FUN_0012c994(undefined4 param_1)
{
  FUN_00093da4(param_1,DAT_00338714);
  return;
}
