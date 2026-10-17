/* HSTMATCH module=EBOOT.BIN start=0x000037f8 end=0x00003828 symbol=FUN_000037f8 lang=c99 */
/* Clone of src/sharing_main/FUN_00002f90.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00002fc0();
extern undefined4 FUN_00003828();

undefined4 FUN_000037f8(undefined4 param_1)
{
  FUN_00003828();
  FUN_00002fc0(param_1);
  return param_1;
}
