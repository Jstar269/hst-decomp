/* HSTMATCH module=hstp_trans_main.prx start=0x001fa638 end=0x001fa69c symbol=FUN_001fa638 lang=c99 */
/* Clone of src/eboot/FUN_001ec2f8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003f3470;
extern void FUN_001fa6f8();
extern void FUN_001fa8a4();

undefined4 * FUN_001fa638(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  DAT_003f3470 = (unsigned int)(param_1);
  FUN_001fa6f8();
  FUN_001fa8a4(param_1,0xb,0);
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  param_1[5] = 0;
  *(undefined1 *)((int)param_1 + 0x1d) = 1;
  *(undefined1 *)((int)param_1 + 0x1e) = 0;
  return param_1;
}
