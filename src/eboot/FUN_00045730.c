/* HSTMATCH module=EBOOT.BIN start=0x00045730 end=0x0004577c symbol=FUN_00045730 lang=c99 */
/* Clone of src/sharing_main/FUN_00045830.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_000458d0();
extern void FUN_000459f8();

undefined4 * FUN_00045730(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  FUN_000459f8(param_1 + 3);
  FUN_000458d0(param_1);
  return param_1;
}
