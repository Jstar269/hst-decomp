/* HSTMATCH module=hstp_trans_main.prx start=0x00172d7c end=0x00172dc8 symbol=FUN_00172d7c lang=c99 */
/* Clone of src/eboot/FUN_00166bb8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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
typedef float undefined4;


void FUN_00172d7c(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)
{
  *(undefined4 *)(param_1 + 0x60) = *param_2;
  *(undefined4 *)(param_1 + 0x40) = *param_3;
  *(undefined4 *)(param_1 + 0x44) = *param_3;
  *(undefined4 *)(param_1 + 0x48) = *param_3;
  *(undefined4 *)(param_1 + 0x4c) = *param_3;
  *(undefined4 *)(param_1 + 0x50) = *param_4;
  *(undefined4 *)(param_1 + 0x54) = *param_4;
  *(undefined4 *)(param_1 + 0x58) = *param_4;
  *(undefined4 *)(param_1 + 0x5c) = *param_4;
  return;
}
