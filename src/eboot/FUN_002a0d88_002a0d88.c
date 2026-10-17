/* HSTMATCH module=EBOOT.BIN start=0x002a0d88 end=0x002a0df4 symbol=FUN_002a0d88 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: kept the update flag as int and narrowed it after the float stores; exact match verified; names and types await human review. */
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

extern void FUN_0010d4a8();

void FUN_002a0d88(float param_1,float param_2,int param_3,int param_4)
{
  int bVar1;
  bool bVar2;
  
  bVar1 = param_4 != 0;
  if ((!bVar1) && (bVar1 = true, *(float *)(param_3 + 0x108) == param_1)) {
    bVar1 = false;
  }
  if (!(bVar1)) {
    bVar1 = *(float *)(param_3 + 0x10c) != param_2;
  }
  *(float *)(param_3 + 0x108) = param_1;
  *(float *)(param_3 + 0x10c) = param_2;
  bVar2 = (bool)bVar1;
  if (bVar2) {
    FUN_0010d4a8();
  }
  return;
}
