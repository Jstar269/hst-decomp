/* HSTMATCH module=hstp_trans_main.prx start=0x0024414c end=0x00244178 symbol=FUN_0024414c lang=c99 */
/* Clone of src/eboot/FUN_001fd0e4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003f3994;
extern void FUN_00243d48();

void FUN_0024414c(void)
{
  if (DAT_003f3994 != 0) {
    FUN_00243d48(DAT_003f3994);
  }
  return;
}
