/* HSTMATCH module=hstp_trans_main.prx start=0x002923dc end=0x00292408 symbol=FUN_002923dc lang=c99 */
/* Clone of src/eboot/FUN_00281064.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e1e04;
extern void FUN_000c0c80();

void FUN_002923dc(void)
{
  if (DAT_003e1e04 != 0) {
    FUN_000c0c80(DAT_003e1e04,0xffffffff);
  }
  return;
}
