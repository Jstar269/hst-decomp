/* HSTMATCH module=EBOOT.BIN start=0x000562b8 end=0x000562d8 symbol=FUN_000562b8 lang=c99 */
/* Clone of src/sharing_main/FUN_00056ecc.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;


void FUN_000562b8(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined2 *)((int)param_1 + 10) = 0xffff;
  *(undefined2 *)(param_1 + 3) = 0xffff;
  return;
}
