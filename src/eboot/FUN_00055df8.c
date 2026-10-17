/* HSTMATCH module=EBOOT.BIN start=0x00055df8 end=0x00055e48 symbol=FUN_00055df8 lang=c99 */
/* Clone of src/sharing_main/FUN_000569a4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00055e98();
extern undefined4 FUN_00055eac();

undefined4 FUN_00055df8(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_00055e98(param_1);
  FUN_00055eac(param_1,param_2,param_3);
  return param_1;
}
