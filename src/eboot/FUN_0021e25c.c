/* HSTMATCH module=EBOOT.BIN start=0x0021e25c end=0x0021e2d4 symbol=FUN_0021e25c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
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

extern void FUN_00103480();

void FUN_0021e25c(float param_1,float param_2,char *param_3)
{
  if (*(float *)(param_3 + 0x1dc) == param_1) {
    if (*(float *)(param_3 + 0x1e0) == param_2) {
      return;
    }
    *(float *)(param_3 + 0x1dc) = param_1;
  }
  else {
    *(float *)(param_3 + 0x1dc) = param_1;
  }
  *(float *)(param_3 + 0x1e0) = param_2;
  *(float *)(*(int *)(param_3 + 0x54) + 0x60) = param_1;
  *(float *)(*(int *)(param_3 + 0x54) + 100) = param_2;
  *(float *)(*(int *)(param_3 + 0x58) + 0x60) = param_1;
  *(float *)(*(int *)(param_3 + 0x58) + 100) = param_2;
  *(float *)(*(int *)(param_3 + 0x5c) + 0x60) = param_1;
  *(float *)(*(int *)(param_3 + 0x5c) + 100) = param_2;
  FUN_00103480(param_3);
  return;
}
