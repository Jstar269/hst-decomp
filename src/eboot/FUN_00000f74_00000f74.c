/* HSTMATCH module=EBOOT.BIN start=0x00000f74 end=0x00000f98 symbol=FUN_00000f74 lang=c99 */
/* Clone of src/sharing_main/FUN_00000f74.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_0030a03c;

undefined4 FUN_00000f74(undefined4 param_1,undefined4 param_2,undefined4 *param_3)
{
  *param_3 = DAT_0030a03c;
  param_3[1] = param_2;
  param_3[2] = param_1;
  DAT_0030a03c = (unsigned int)(param_3);
  return param_1;
}
