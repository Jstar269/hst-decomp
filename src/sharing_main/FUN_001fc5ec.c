/* HSTMATCH module=hstp_trans_main.prx start=0x001fc5ec end=0x001fc5fc symbol=FUN_001fc5ec lang=c99 */
/* Clone of src/eboot/FUN_001ee224.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e19f0;
extern undefined4 FUN_001fd6dc();

void FUN_001fc5ec(void)
{
  FUN_001fd6dc(*(undefined4 *)(DAT_003e19f0 + 0xa0));
  return;
}
