/* HSTMATCH module=hstp_trans_main.prx start=0x00113c8c end=0x00113ccc symbol=FUN_00113c8c lang=c99 */
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

extern void FUN_00107c9c(float);

void FUN_00113c8c(float param_1,int param_2)
{
  FUN_00107c9c((float)(param_1));
  *(float *)(param_2 + 0x148) = param_1 + 0.5f;
  return;
}
