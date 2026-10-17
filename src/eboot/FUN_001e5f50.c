/* HSTMATCH module=EBOOT.BIN start=0x001e5f50 end=0x001e5fbc symbol=FUN_001e5f50 lang=c99 */
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

extern void FUN_00103628();
extern void FUN_001e2694();
extern void FUN_001e6224();

void FUN_001e5f50(int param_1,undefined4 param_2,uint param_3,int param_4)
{
  FUN_001e2694(param_1);
  FUN_00103628(*(int *)(param_1 + 0x1958),0);
  FUN_001e6224(param_1,param_2,param_3,param_4,'\0');
  return;
}
