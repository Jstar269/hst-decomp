/* HSTMATCH module=hstp_trans_main.prx start=0x001a1630 end=0x001a1644 symbol=FUN_001a1630 lang=c99 */
/* Clone of src/eboot/FUN_00194e20.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003eb004;
extern void FUN_001a13b4();

void FUN_001a1630(undefined4 param_1)
{
  FUN_001a13b4(param_1,*(undefined2 *)(DAT_003eb004 + 0x1034),0x20);
  return;
}
