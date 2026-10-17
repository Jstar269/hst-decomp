/* HSTMATCH module=EBOOT.BIN start=0x0006b9c8 end=0x0006b9e8 symbol=FUN_0006b9c8 lang=c99 */
/* Clone of src/sharing_main/FUN_0006cfb0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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


undefined4 * FUN_0006b9c8(undefined4 *param_1,undefined1 *param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = *param_2;
  param_1[3] = (unsigned int)(param_1 + 1);
  return param_1;
}
