/* HSTMATCH module=hstp_trans_main.prx start=0x002268dc end=0x00226954 symbol=FUN_002268dc lang=c99 */
/* Clone of src/eboot/FUN_00217834.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_002268dc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined1 *)(param_1 + 0x54) = 1;
  *(undefined1 *)(param_1 + 0x55) = 0;
  *(undefined4 *)(param_1 + 0x58) = param_4;
  *(ushort *)(param_1 + 0x60) = (ushort)param_2 & 0xff;
  *(ushort *)(param_1 + 0x62) = (ushort)(byte)((uint)param_2 >> 8);
  *(ushort *)(param_1 + 100) = (ushort)(byte)((uint)param_2 >> 0x10);
  *(ushort *)(param_1 + 0x66) = (ushort)(byte)((uint)param_2 >> 0x18);
  *(ushort *)(param_1 + 0x68) = (ushort)param_3 & 0xff;
  *(ushort *)(param_1 + 0x6a) = (ushort)(byte)((uint)param_3 >> 8);
  *(ushort *)(param_1 + 0x6c) = (ushort)(byte)((uint)param_3 >> 0x10);
  *(ushort *)(param_1 + 0x6e) = (ushort)(byte)((uint)param_3 >> 0x18);
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined2 *)(param_1 + 0x70) = *(undefined2 *)(param_1 + 0x60);
  *(undefined2 *)(param_1 + 0x72) = *(undefined2 *)(param_1 + 0x62);
  *(undefined2 *)(param_1 + 0x74) = *(undefined2 *)(param_1 + 100);
  *(undefined2 *)(param_1 + 0x76) = *(undefined2 *)(param_1 + 0x66);
  return;
}
