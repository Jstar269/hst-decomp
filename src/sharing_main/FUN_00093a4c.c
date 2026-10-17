/* HSTMATCH module=hstp_trans_main.prx start=0x00093a4c end=0x00093a70 symbol=FUN_00093a4c lang=c99 */
/* Clone of src/eboot/FUN_00091db4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef float undefined4;


void FUN_00093a4c(int param_1,undefined4 *param_2)
{
  *(undefined4 *)(param_1 + 0x40) = *param_2;
  *(undefined4 *)(param_1 + 0x44) = param_2[1];
  *(undefined4 *)(param_1 + 0x48) = param_2[2];
  *(undefined4 *)(param_1 + 0x4c) = param_2[3];
  return;
}
