/* HSTMATCH module=EBOOT.BIN start=0x0023404c end=0x00234078 symbol=FUN_0023404c lang=c99 */
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

extern undefined4 DAT_0034a664;
extern void FUN_00233c48();

void FUN_0023404c(void)
{
  if (DAT_0034a664 != 0) {
    FUN_00233c48(DAT_0034a664);
  }
  return;
}
