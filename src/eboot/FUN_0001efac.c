/* HSTMATCH module=EBOOT.BIN start=0x0001efac end=0x0001efc0 symbol=FUN_0001efac lang=c99 */
/* Clone of src/sharing_main/FUN_0001eb84.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_002cfc8c;
extern undefined DAT_0030fc40;

void FUN_0001efac(void)
{
  DAT_002cfc8c = (unsigned int)(&DAT_0030fc40);
  return;
}
