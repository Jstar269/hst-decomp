/* HSTMATCH module=EBOOT.BIN start=0x001e4b4c end=0x001e4c48 symbol=FUN_001e4b4c lang=c99 */
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

extern void FUN_00102c54();
extern void FUN_001ea930();

void FUN_001e4b4c(float param_1,int param_2)
{
  int iVar1;
  
  iVar1 = (int)(param_1 + 480.0f);
  *(float *)(*(int *)(param_2 + 0x9b8) + 0x60) = (float)(*(int *)(param_2 + 0x1748) + iVar1);
  FUN_00102c54(*(int *)(param_2 + 0x9b8));
  *(float *)(*(int *)(param_2 + 0x9bc) + 0x60) = (float)(*(int *)(param_2 + 0x174c) + iVar1);
  FUN_00102c54(*(int *)(param_2 + 0x9bc));
  *(float *)(*(int *)(param_2 + 0x9c0) + 0x60) = (float)(*(int *)(param_2 + 0x1750) + iVar1);
  FUN_00102c54(*(int *)(param_2 + 0x9c0));
  *(float *)(*(int *)(param_2 + 0x9c4) + 0x60) = (float)(*(int *)(param_2 + 0x1754) + iVar1);
  FUN_00102c54(*(int *)(param_2 + 0x9c4));
  *(float *)(*(int *)(param_2 + 0x9c8) + 0x60) = (float)(*(int *)(param_2 + 0x1758) + iVar1);
  FUN_00102c54(*(int *)(param_2 + 0x9c8));
  FUN_001ea930(*(int **)(*(int *)(param_2 + 0x3c) + 0x8c),(int)param_1);
  return;
}
