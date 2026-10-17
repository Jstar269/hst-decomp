/* HSTMATCH module=hstp_trans_main.prx start=0x0022687c end=0x002268b4 symbol=FUN_0022687c lang=c99 */
/* Clone of src/eboot/FUN_002177d4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_0022687c(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4, undefined2 param_5,undefined4 param_6)
{
  *(undefined1 *)(param_1 + 0x24) = 1;
  *(undefined1 *)(param_1 + 0x25) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_6;
  *(undefined2 *)(param_1 + 0x30) = param_2;
  *(undefined2 *)(param_1 + 0x32) = param_3;
  *(undefined2 *)(param_1 + 0x34) = param_4;
  *(undefined2 *)(param_1 + 0x36) = param_5;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined2 *)(param_1 + 0x38) = *(undefined2 *)(param_1 + 0x30);
  *(undefined2 *)(param_1 + 0x3a) = *(undefined2 *)(param_1 + 0x32);
  return;
}
