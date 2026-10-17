/* HSTMATCH module=EBOOT.BIN start=0x001067c0 end=0x001067cc symbol=FUN_001067c0 lang=c99 */
/* Clone of src/eboot/FUN_001b4e08.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_002c106c;

undefined1 * FUN_001067c0(void)
{
  return &DAT_002c106c;
}
