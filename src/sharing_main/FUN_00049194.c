/* HSTMATCH module=hstp_trans_main.prx start=0x00049194 end=0x00049200 symbol=FUN_00049194 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v16) corrected by hand: formed the relative field as this plus 0x30 minus the base pointer; exact match verified; names and types await human review. */
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

extern undefined DAT_003b0264;
extern undefined DAT_003b0270;
extern void FUN_00049280();
extern undefined4 * FUN_000577ec();

int * FUN_00049194(int *param_1,short param_2)
{
  if (param_2 != 0) {
    *param_1 = (int)(param_1 + 0xc);
    FUN_000577ec((int)param_1 + 48);
  }
  param_1[1] = (int)&DAT_003b0264;
  *(undefined **)*param_1 = &DAT_003b0270;
  *(int *)(*param_1 + 0x1b0) = (int)((char *)param_1 + 0x30) - *param_1;
  FUN_00049280(param_1,&DAT_003b0270);
  return param_1;
}
