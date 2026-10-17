/* HSTMATCH module=hstp_trans_main.prx start=0x00297ebc end=0x00297f98 symbol=FUN_00297ebc lang=c99 */
/* Clone of src/eboot/FUN_00286790_00286790.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: typed the four global values and destination fields as float; exact match verified; names and types await human review. */
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

extern float DAT_002cc280;
extern float DAT_002cc284;
extern float DAT_002cc288;
extern float DAT_002cc28c;
extern undefined DAT_003b2f94;
extern void FUN_00298404();
extern undefined4 * FUN_0029adf0();

undefined4 * FUN_00297ebc(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b2f94);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  ((float *)param_1)[8] = DAT_002cc280;
  ((float *)param_1)[9] = DAT_002cc284;
  ((float *)param_1)[10] = DAT_002cc288;
  ((float *)param_1)[0xb] = DAT_002cc28c;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0xffffffff;
  param_1[0x10] = 0xffffffff;
  param_1[0x13] = 0xffffffff;
  param_1[0x14] = 0x3fc00000;
  *(undefined1 *)(param_1 + 0x15) = 1;
  *(undefined1 *)((int)param_1 + 0x55) = 0;
  *(undefined1 *)((int)param_1 + 0x56) = 0;
  *(undefined1 *)((int)param_1 + 0x57) = 1;
  *(undefined1 *)(param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x59) = 0;
  *(undefined1 *)((int)param_1 + 0x5a) = 0;
  *(undefined1 *)((int)param_1 + 0x5b) = 0;
  *(undefined1 *)(param_1 + 0x17) = 0;
  param_1[0x18] = 0;
  FUN_0029adf0(param_1 + 0x19);
  FUN_00298404(param_1);
  param_1[0x11] = 0x3f800000;
  param_1[0x12] = 0x3f800000;
  return param_1;
}

