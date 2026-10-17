/* HSTMATCH module=EBOOT.BIN start=0x0001bc3c end=0x0001bc6c symbol=FUN_0001bc3c lang=c99 */
/* Clone of src/sharing_main/FUN_0001b6e0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_0030ebd4;
extern void FUN_0001b944();
extern void FUN_002b7978();

undefined4 FUN_0001bc3c(void)
{
  FUN_0001b944();
  DAT_0030ebd4 = 0;
  FUN_002b7978(0);
  return 0;
}
