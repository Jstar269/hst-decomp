/* HSTMATCH module=hstp_trans_main.prx start=0x001d0494 end=0x001d05b4 symbol=FUN_001d0494 lang=c99 */
/* Clone of src/eboot/FUN_001c2250.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b2608;
extern uint * FUN_000114c0();
extern undefined4 * FUN_001dbeec();
extern undefined4 * FUN_00238740();

undefined4 * FUN_001d0494(undefined4 *param_1,undefined4 param_2)
{
  FUN_001dbeec(param_1);
  *param_1 = (unsigned int)(&DAT_003b2608);
  param_1[6] = param_2;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  FUN_00238740(param_1 + 0xd);
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  *(undefined1 *)(param_1 + 0x18) = 0;
  *(undefined1 *)((int)param_1 + 0x61) = 0;
  *(undefined1 *)((int)param_1 + 0x62) = 1;
  *(undefined1 *)((int)param_1 + 99) = 0;
  *(undefined1 *)(param_1 + 0x19) = 0;
  *(undefined1 *)((int)param_1 + 0x65) = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0xffffffff;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0xffffffff;
  param_1[0x1e] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x24) = 0;
  *(undefined1 *)((int)param_1 + 0x91) = 0;
  param_1[0x25] = 0;
  FUN_000114c0(param_1 + 0x26,0,0x10);
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  *(undefined1 *)((int)param_1 + 0xb1) = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0xffffffff;
  param_1[0x2f] = 0xffffffff;
  param_1[0x30] = 0xffffffff;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  *(undefined1 *)(param_1 + 0x39) = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 0;
  *(undefined1 *)((int)param_1 + 0xf1) = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  *(undefined1 *)(param_1 + 0x41) = 0;
  return param_1;
}
