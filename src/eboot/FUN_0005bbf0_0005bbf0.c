/* HSTMATCH module=EBOOT.BIN start=0x0005bbf0 end=0x0005bc58 symbol=FUN_0005bbf0 lang=c99 */
/* Clone of src/sharing_main/FUN_0005c878_0005c878.c (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: typed the six copied fields and output pointers as float; exact match verified; names and types await human review. */
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


void FUN_0005bbf0(int param_1,float *param_2,float *param_3,float *param_4,float *param_5,float *param_6,float *param_7)
{
  if (param_2 != (float *)0x0) {
    *param_2 = *(float *)(param_1 + 0x218);
  }
  if (param_3 != (float *)0x0) {
    *param_3 = *(float *)(param_1 + 0x21c);
  }
  if (param_4 != (float *)0x0) {
    *param_4 = *(float *)(param_1 + 0x220);
  }
  if (param_5 != (float *)0x0) {
    *param_5 = *(float *)(param_1 + 0x224);
  }
  if (param_6 != (float *)0x0) {
    *param_6 = *(float *)(param_1 + 0x228);
  }
  if (param_7 != (float *)0x0) {
    *param_7 = *(float *)(param_1 + 0x22c);
  }
  return;
}
