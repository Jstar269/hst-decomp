/* HSTMATCH module=hstp_trans_main.prx start=0x00172cfc end=0x00172d40 symbol=FUN_00172cfc lang=c99 */
/* Clone of src/eboot/FUN_00166b38.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_00172cfc(int param_1,undefined4 *param_2)
{
  *(undefined4 *)(param_1 + 0x10) = *param_2;
  *(undefined4 *)(param_1 + 0x14) = param_2[1];
  *(undefined4 *)(param_1 + 0x18) = param_2[2];
  *(undefined4 *)(param_1 + 0x1c) = param_2[3];
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x1c);
  return;
}
