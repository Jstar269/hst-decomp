/* HSTMATCH module=EBOOT.BIN start=0x0001dc00 end=0x0001dc7c symbol=FUN_0001dc00 lang=c99 */
/* Clone of src/sharing_main/FUN_0001d84c.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed the copied globals as bytes to preserve retail byte loads and stores; exact match verified; names and types await human review. */
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
extern undefined DAT_0030fe0c;
extern undefined DAT_0030fe0d;
extern undefined DAT_0030fe0e;
extern undefined DAT_0030fe0f;
extern undefined DAT_0030fe10;
extern undefined DAT_0030fe11;
extern undefined DAT_0030fe12;
extern undefined DAT_0030fe13;
extern void FUN_0001e268();
extern undefined4 FUN_0001f004();

void FUN_0001dc00(void)
{
  DAT_002cfc8c = (unsigned int)(&DAT_0030fc40);
  DAT_0030fe0c = DAT_0030fe10;
  DAT_0030fe0d = DAT_0030fe11;
  DAT_0030fe0e = DAT_0030fe12;
  DAT_0030fe0f = DAT_0030fe13;
  FUN_0001f004(&DAT_0030fe10);
  FUN_0001e268(DAT_002cfc8c);
  return;
}
