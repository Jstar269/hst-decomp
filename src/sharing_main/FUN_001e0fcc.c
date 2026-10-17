/* HSTMATCH module=hstp_trans_main.prx start=0x001e0fcc end=0x001e0fdc symbol=FUN_001e0fcc lang=c99 */
/* Clone of src/eboot/FUN_001d31c8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003eaad8;
extern void FUN_001c1f44();

void FUN_001e0fcc(void)
{
  FUN_001c1f44((int *)&DAT_003eaad8,1);
  return;
}
