/* HSTMATCH module=EBOOT.BIN start=0x001972d0 end=0x001972fc symbol=FUN_001972d0 lang=c99 */
/* Clone of src/eboot/FUN_001fd0e4.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_00341768;
extern void FUN_00196ef4();

void FUN_001972d0(void)
{
  if (DAT_00341768 != 0) {
    FUN_00196ef4(DAT_00341768);
  }
  return;
}
