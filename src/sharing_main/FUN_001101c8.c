/* HSTMATCH module=hstp_trans_main.prx start=0x001101c8 end=0x00110268 symbol=FUN_001101c8 lang=c99 */
/* Clone of src/eboot/FUN_0010a408.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern char DAT_0037fba4[];
extern uint * FUN_000114c0();
extern void FUN_00110268();
extern void FUN_001a5d44();
extern int FUN_002c79c0();

int FUN_001101c8(undefined4 *param_1,undefined4 param_2)
{
  uint iVar1;
  
  FUN_000114c0(param_1,0,0x2c4);
  *param_1 = 0x2c4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x11;
  param_1[4] = 0x13;
  param_1[5] = 0x12;
  param_1[6] = 0x10;
  FUN_001a5d44(param_1);
  param_1[0xe] = param_2;
  param_1[0xd] = 0;
  iVar1 = FUN_002c79c0(param_1);
  if (0 != iVar1) {
    FUN_00110268(DAT_0037fba4,iVar1);
  }
  return iVar1;
}
