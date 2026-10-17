/* HSTMATCH module=EBOOT.BIN start=0x0021ca18 end=0x0021ca68 symbol=FUN_0021ca18 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: typed the integer count and float-one fields; exact match verified; names and types await human review. */
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

extern void FUN_00103480();

void FUN_0021ca18(int param_1)
{
  *(int *)(param_1 + 100) = 100;
  *(undefined4 *)(*(int *)(param_1 + 0x68) + 0x60) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(*(int *)(param_1 + 0x68) + 100) = *(undefined4 *)(param_1 + 0xe4);
  *(float *)(*(int *)(param_1 + 0x68) + 0x78) = 1.0f;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 0x60) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 100) = *(undefined4 *)(param_1 + 0xe4);
  *(float *)(*(int *)(param_1 + 0x6c) + 0x78) = 1.0f;
  FUN_00103480(param_1);
  return;
}
