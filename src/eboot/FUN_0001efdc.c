/* HSTMATCH module=EBOOT.BIN start=0x0001efdc end=0x0001f004 symbol=FUN_0001efdc lang=c99 */
/* Clone of src/sharing_main/FUN_0001ebb4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_002b7a88();
extern void FUN_002b7a98();

undefined4 FUN_0001efdc(void)
{
  FUN_002b7a88(1);
  FUN_002b7a98(0);
  return 1;
}
