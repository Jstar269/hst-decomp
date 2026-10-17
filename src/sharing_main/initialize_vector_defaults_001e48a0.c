/* HSTMATCH module=hstp_trans_main.prx start=0x001e48a0 end=0x001e49a0 symbol=FUN_001e48a0 lang=c99 */
/* Clone of src/eboot/initialize_vector_defaults_001d6ab0.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
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

extern float DAT_002cc260;
extern float DAT_002cc264;
extern float DAT_002cc268;
extern float DAT_002cc26c;
extern undefined4 DAT_003da704;
extern int FUN_0005c2f8();
extern int FUN_0005c688();
extern int FUN_0005c700();

undefined4 * FUN_001e48a0(undefined4 *param_1)
{
  undefined1 auStack_2c0 [704];
  
  *(float *)param_1 = DAT_002cc260;
  *(float *)(param_1 + 1) = DAT_002cc264;
  *(float *)(param_1 + 2) = DAT_002cc268;
  *(float *)(param_1 + 3) = DAT_002cc26c;
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
  FUN_0005c2f8(auStack_2c0);
  FUN_0005c700(DAT_003da704,auStack_2c0);
  FUN_0005c688(auStack_2c0,0xffffffff);
  return param_1;
}
