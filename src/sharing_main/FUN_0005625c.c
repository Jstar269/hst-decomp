/* HSTMATCH module=hstp_trans_main.prx start=0x0005625c end=0x000562d0 symbol=FUN_0005625c lang=c99 */
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

extern undefined4 * FUN_000224c0(float, int, int);
extern void FUN_00054b5c();

void FUN_0005625c(int param_1,int param_2)
{
  float fVar1;
  
  FUN_00054b5c(*(undefined4 *)(param_1 + 0x8c));
  fVar1 = *(float *)(param_1 + 0x88) / *(float *)(param_1 + 0x84);
  FUN_000224c0((float)(fVar1),(int)(param_2),(int)(param_2));
  FUN_000224c0((float)(fVar1),(int)(param_2 + 0x10),(int)(param_2 + 0x10));
  *(float *)(param_2 + 0x1c) = *(float *)(param_2 + 0xc) * *(float *)(param_2 + 0xc);
  return;
}
