/* HSTMATCH module=EBOOT.BIN start=0x00054f08 end=0x00054f4c symbol=FUN_00054f08 lang=c99 */
/* Clone of src/sharing_main/FUN_00055a28.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_00306fd4;
extern void FUN_00054fb0();

undefined4 * FUN_00054f08(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = (unsigned int)(&DAT_00306fd4);
  FUN_00054fb0();
  param_1[0x23] = param_2;
  return param_1;
}
