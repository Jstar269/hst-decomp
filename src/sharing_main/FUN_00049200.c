/* HSTMATCH module=hstp_trans_main.prx start=0x00049200 end=0x00049280 symbol=FUN_00049200 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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
extern void FUN_00000a00();
extern undefined4 * FUN_00057904();

int * FUN_00049200(int *param_1,int param_2)
{
  if (param_1 != (int *)0x0) {
    param_1[1] = (int)&DAT_003b0264;
    *(undefined **)*param_1 = &DAT_003b0270;
    *(int *)(*param_1 + 0x1b0) = (int)(param_1 + 0xc) - *param_1;
    if (param_2 != 0) {
      FUN_00057904(param_1 + 0xc,0);
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
