/* HSTMATCH module=hstp_trans_main.prx start=0x00139708 end=0x00139740 symbol=FUN_00139708 lang=c99 */
/* Clone of src/eboot/FUN_0012e1b0.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e48bc;

void FUN_00139708(int param_1,undefined4 *param_2)
{
  *(undefined4 *)(param_1 + 0x70) = *param_2;
  *(undefined4 *)(param_1 + 0x74) = param_2[1];
  *(undefined4 *)(param_1 + 0x78) = param_2[2];
  *(undefined4 *)(param_1 + 0x7c) = param_2[3];
  *(float *)(param_1 + 0x74) = *(float *)(param_1 + 0x74) + DAT_003e48bc;
  return;
}
