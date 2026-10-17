/* HSTMATCH module=EBOOT.BIN start=0x00023b9c end=0x00023bb8 symbol=FUN_00023b9c lang=c99 */
/* Clone of src/sharing_main/FUN_00023bc4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_00023b9c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x6c) = param_4;
    *(undefined4 *)(param_1 + 100) = param_2;
    *(undefined4 *)(param_1 + 0x68) = param_3;
  }
  return;
}
