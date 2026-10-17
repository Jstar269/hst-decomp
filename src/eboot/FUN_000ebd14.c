/* HSTMATCH module=EBOOT.BIN start=0x000ebd14 end=0x000ebdfc symbol=FUN_000ebd14 lang=c99 */
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

extern undefined4 DAT_002bc410;
extern undefined4 DAT_002bc414;
extern undefined4 DAT_002bc418;
extern undefined4 DAT_002bc41c;
extern undefined4 DAT_002bc420;
extern undefined4 DAT_002bc424;
extern undefined4 DAT_002bc428;
extern undefined4 DAT_002bc42c;
extern undefined4 DAT_002bc430;
extern undefined4 DAT_002bc434;
extern undefined4 DAT_002bc438;
extern undefined4 DAT_002bc43c;
extern undefined4 DAT_002bc440;
extern undefined4 DAT_002bc444;
extern undefined4 DAT_002bc448;
extern undefined4 DAT_002bc44c;

undefined4 * FUN_000ebd14(undefined4 *param_1)
{
  *param_1 = DAT_002bc410;
  param_1[1] = DAT_002bc414;
  param_1[2] = DAT_002bc418;
  param_1[3] = DAT_002bc41c;
  param_1[4] = DAT_002bc420;
  param_1[5] = DAT_002bc424;
  param_1[6] = DAT_002bc428;
  param_1[7] = DAT_002bc42c;
  param_1[8] = DAT_002bc430;
  param_1[9] = DAT_002bc434;
  param_1[10] = DAT_002bc438;
  param_1[0xb] = DAT_002bc43c;
  param_1[0xc] = DAT_002bc440;
  param_1[0xd] = DAT_002bc444;
  param_1[0xe] = DAT_002bc448;
  param_1[0xf] = DAT_002bc44c;
  param_1[0x10] = 0;
  *(int *)(param_1 + 0x11) = 6;
  param_1[0x12] = 1.0f;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 1.0f;
  return param_1;
}
