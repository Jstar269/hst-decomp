/* HSTMATCH module=hstp_trans_main.prx start=0x0005d938 end=0x0005d980 symbol=FUN_0005d938 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the copied components and output pointers as float; exact match verified; names and types await human review. */
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


void FUN_0005d938(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)
{
  if (param_2 != (float *)0x0) {
    *param_2 = *param_1;
  }
  if (param_3 != (float *)0x0) {
    *param_3 = param_1[1];
  }
  if (param_4 != (float *)0x0) {
    *param_4 = param_1[2];
  }
  if (param_5 != (float *)0x0) {
    *param_5 = param_1[3];
  }
  return;
}
