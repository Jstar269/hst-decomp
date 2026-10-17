/* HSTMATCH module=EBOOT.BIN start=0x00047898 end=0x000478ac symbol=FUN_00047898 lang=c99 */
/* Clone of src/sharing_main/FUN_00047d1c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_002d0220;

bool FUN_00047898(void)
{
  return DAT_002d0220 == 0;
}
