/* HSTMATCH module=EBOOT.BIN start=0x0027c2c8 end=0x0027c328 symbol=FUN_0027c2c8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p128a); exact match verified; names and types await human review. */
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

extern void FUN_0027c328(int param_1,int param_2,float *param_3);

void FUN_0027c2c8(undefined4 param_1,int param_2,float *param_3,float *param_4)
{
  *(undefined4 *)(param_2 + 0x48) = 0;
  FUN_0027c328(param_2,1,param_3);
  FUN_0027c328(param_2,2,param_4);
  *(undefined4 *)(param_2 + 0x6c) = 0;
  *(undefined4 *)(param_2 + 0x70) = param_1;
  return;
}
