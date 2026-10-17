/* HSTMATCH module=hstp_trans_main.prx start=0x0020dd74 end=0x0020dda0 symbol=FUN_0020dd74 lang=c99 */
/* Clone of src/eboot/FUN_001ff5a4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e1a08;
extern void FUN_00292408();

void FUN_0020dd74(void)
{
  if (DAT_003e1a08 != 0) {
    FUN_00292408(*(undefined4 *)(DAT_003e1a08 + 0x40));
  }
  return;
}
