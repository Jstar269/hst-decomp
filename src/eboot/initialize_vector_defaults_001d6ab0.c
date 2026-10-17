/* HSTMATCH module=EBOOT.BIN start=0x001d6ab0 end=0x001d6bb0 symbol=FUN_001d6ab0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the first four copied globals and destination fields as float; exact match verified; names and types await human review. */
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

extern float DAT_002bc410;
extern float DAT_002bc414;
extern float DAT_002bc418;
extern float DAT_002bc41c;
extern undefined4 DAT_003313c4;
extern int FUN_0005b670();
extern int FUN_0005ba00();
extern int FUN_0005ba78();

undefined4 * FUN_001d6ab0(undefined4 *param_1)
{
  undefined1 auStack_2c0 [704];
  
  *(float *)param_1 = DAT_002bc410;
  *(float *)(param_1 + 1) = DAT_002bc414;
  *(float *)(param_1 + 2) = DAT_002bc418;
  *(float *)(param_1 + 3) = DAT_002bc41c;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x3f800000;
  param_1[7] = 0x3f800000;
  param_1[8] = 0x43700000;
  param_1[9] = 0x43080000;
  param_1[0xc] = 0xbf000000;
  param_1[0xd] = 0x3f000000;
  param_1[0xe] = 0xbf800000;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0xbf800000;
  param_1[0x13] = 0;
  param_1[0x14] = 0x3f800000;
  param_1[0x15] = 0x3f800000;
  param_1[0x16] = 0x3f800000;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0x3f266666;
  param_1[0x1d] = 0x3f266666;
  param_1[0x1e] = 0x3f266666;
  param_1[0x1f] = 0x3f800000;
  FUN_0005b670(auStack_2c0);
  FUN_0005ba78(DAT_003313c4,auStack_2c0);
  FUN_0005ba00(auStack_2c0,0xffffffff);
  return param_1;
}
