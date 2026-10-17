/* HSTMATCH module=EBOOT.BIN start=0x00217704 end=0x00217778 symbol=FUN_00217704 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern void FUN_0021791c();
extern void FUN_00217928();
extern void FUN_00217934();

void FUN_00217704(undefined4 *param_1,int param_2)
{
  *param_1 = 0;
  param_1[1] = param_2;
  param_1[4] = 0;
  if (param_1[1] != 0) {
    *(short *)(param_1 + 2) = (short)(int)*(float *)(param_2 + 0x60);
    *(short *)((int)param_1 + 10) = (short)(int)*(float *)(param_2 + 100);
    *(undefined2 *)(param_1 + 3) = 0x80;
  }
  FUN_0021791c(param_1);
  FUN_00217928(param_1);
  FUN_00217934(param_1);
  return;
}
