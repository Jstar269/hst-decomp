/* HSTMATCH module=hstp_trans_main.prx start=0x000f126c end=0x000f1354 symbol=FUN_000f126c lang=c99 */
/* Clone of src/eboot/FUN_000ebd14.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag q4, float variant) corrected by hand: the int field and the 1.0f constants typed; exact match verified; names and types await human review. */
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

extern undefined4 DAT_002cc260;
extern undefined4 DAT_002cc264;
extern undefined4 DAT_002cc268;
extern undefined4 DAT_002cc26c;
extern undefined4 DAT_002cc270;
extern undefined4 DAT_002cc274;
extern undefined4 DAT_002cc278;
extern undefined4 DAT_002cc27c;
extern undefined4 DAT_002cc280;
extern undefined4 DAT_002cc284;
extern undefined4 DAT_002cc288;
extern undefined4 DAT_002cc28c;
extern undefined4 DAT_002cc290;
extern undefined4 DAT_002cc294;
extern undefined4 DAT_002cc298;
extern undefined4 DAT_002cc29c;

undefined4 * FUN_000f126c(undefined4 *param_1)
{
  *param_1 = DAT_002cc260;
  param_1[1] = DAT_002cc264;
  param_1[2] = DAT_002cc268;
  param_1[3] = DAT_002cc26c;
  param_1[4] = DAT_002cc270;
  param_1[5] = DAT_002cc274;
  param_1[6] = DAT_002cc278;
  param_1[7] = DAT_002cc27c;
  param_1[8] = DAT_002cc280;
  param_1[9] = DAT_002cc284;
  param_1[10] = DAT_002cc288;
  param_1[0xb] = DAT_002cc28c;
  param_1[0xc] = DAT_002cc290;
  param_1[0xd] = DAT_002cc294;
  param_1[0xe] = DAT_002cc298;
  param_1[0xf] = DAT_002cc29c;
  param_1[0x10] = 0;
  *(int *)(param_1 + 0x11) = 6;
  param_1[0x12] = 1.0f;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 1.0f;
  return param_1;
}
