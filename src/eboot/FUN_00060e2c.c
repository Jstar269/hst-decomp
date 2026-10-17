/* HSTMATCH module=EBOOT.BIN start=0x00060e2c end=0x00060e7c symbol=FUN_00060e2c lang=c99 */
/* Clone of src/sharing_main/FUN_00061cb0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_0030707c;
extern undefined4 * FUN_000607b8();

undefined4 * FUN_00060e2c(undefined4 *param_1)
{
  FUN_000607b8();
  *param_1 = (unsigned int)(&DAT_0030707c);
  param_1[0x20] = 0x42340000;
  param_1[0x21] = 0x3e4ccccd;
  param_1[0x22] = 0x447a0000;
  return param_1;
}
