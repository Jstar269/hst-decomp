/* HSTMATCH module=hstp_trans_main.prx start=0x001380b8 end=0x0013813c symbol=FUN_001380b8 lang=c99 */
/* Clone of src/eboot/FUN_0012cc4c.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b13d4;
extern undefined DAT_003b13f0;
extern undefined4 DAT_003da704;
extern undefined4 DAT_003e48b4;
extern int FUN_0005c2f8();
extern int FUN_0005c688();
extern int FUN_0005c700();
extern undefined4 * FUN_0014b1a4();
extern undefined4 * FUN_00297ebc();

undefined4 * FUN_001380b8(undefined4 *param_1)
{
  undefined1 auStack_2c0 [704];
  
  FUN_0014b1a4();
  FUN_00297ebc(param_1 + 0x4c8);
  *param_1 = (unsigned int)(&DAT_003b13d4);
  param_1[0x4c8] = (unsigned int)(&DAT_003b13f0);
  param_1[0x4e4] = 0;
  param_1[0x4e5] = 0;
  param_1[0x4e6] = 0;
  param_1[0x4e7] = 0;
  DAT_003e48b4 = (unsigned int)(param_1);
  FUN_0005c2f8(auStack_2c0);
  FUN_0005c700(DAT_003da704,auStack_2c0);
  FUN_0005c688(auStack_2c0,0xffffffff);
  return param_1;
}
