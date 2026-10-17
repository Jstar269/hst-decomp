/* HSTMATCH module=hstp_trans_main.prx start=0x000d17a8 end=0x000d1838 symbol=FUN_000d17a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed both 16-word buffers as float pointers; exact match verified; names and types await human review. */
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


void FUN_000d17a8(undefined4 param_1,float *param_2,float *param_3)
{
  if (param_2 != (float *)0x0) {
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    param_2[2] = param_3[2];
    param_2[3] = param_3[3];
    param_2[4] = param_3[4];
    param_2[5] = param_3[5];
    param_2[6] = param_3[6];
    param_2[7] = param_3[7];
    param_2[8] = param_3[8];
    param_2[9] = param_3[9];
    param_2[10] = param_3[10];
    param_2[0xb] = param_3[0xb];
    param_2[0xc] = param_3[0xc];
    param_2[0xd] = param_3[0xd];
    param_2[0xe] = param_3[0xe];
    param_2[0xf] = param_3[0xf];
  }
  return;
}
