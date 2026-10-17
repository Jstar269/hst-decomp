/* HSTMATCH module=EBOOT.BIN start=0x00101590 end=0x00101630 symbol=FUN_00101590 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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

extern void FUN_00101798(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5, undefined4 param_6,undefined4 param_7);
extern void FUN_00107174(int *param_1,undefined4 param_2);

void FUN_00101590(int param_1,undefined4 *param_2,uint param_3)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x14) == 0) && (*(uint *)(param_1 + 0x18) < param_3)) {
    FUN_00107174((int *)(param_1 + 0x10),(undefined4)(param_3));
  }
  iVar1 = 0;
  if (0 < (int)param_3) {
    do {
      FUN_00101798((int *)(param_1),(int)(*param_2),(int)(param_2[1]),(undefined4)((int)*(short *)(param_2 + 2)),(undefined4)((int)*(short *)((int)param_2 + 10)),(undefined4)((int)*(short *)(param_2 + 3)),(undefined4)(param_2[4]));
      iVar1 = iVar1 + 1;
      param_2 = param_2 + 5;
    } while (iVar1 < (int)param_3);
  }
  return;
}
