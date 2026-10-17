/* HSTMATCH module=EBOOT.BIN start=0x00286790 end=0x0028686c symbol=FUN_00286790 lang=c99 */
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

extern float DAT_002bc430;
extern float DAT_002bc434;
extern float DAT_002bc438;
extern float DAT_002bc43c;
extern undefined DAT_00309cac;
extern void FUN_00286d08();
extern undefined4 * FUN_00289654();

undefined4 * FUN_00286790(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00309cac);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  ((float *)param_1)[8] = DAT_002bc430;
  ((float *)param_1)[9] = DAT_002bc434;
  ((float *)param_1)[10] = DAT_002bc438;
  ((float *)param_1)[0xb] = DAT_002bc43c;
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
  FUN_00289654(param_1 + 0x19);
  FUN_00286d08(param_1);
  param_1[0x11] = 0x3f800000;
  param_1[0x12] = 0x3f800000;
  return param_1;
}

