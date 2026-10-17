/* HSTMATCH module=EBOOT.BIN start=0x001158f8 end=0x00115a44 symbol=FUN_001158f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: formed relative pointers from field addresses before subtracting nested bases and corrected a nested offset; exact match verified; names and types await human review. */
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

extern undefined DAT_0030779c;
extern undefined DAT_00307c80;
extern undefined DAT_00307c90;
extern undefined DAT_00307cd4;
extern undefined DAT_00307ce4;
extern undefined DAT_00307cf0;
extern undefined DAT_00307cfc;
extern undefined DAT_00307d40;
extern undefined DAT_00307d50;
extern void FUN_00000a00();
extern undefined4 * FUN_00100b24();

int * FUN_001158f8(int *param_1,int param_2)
{
  if (param_1 != (int *)0x0) {
    param_1[2] = (int)&DAT_00307c80;
    *(undefined **)(*param_1 + 4) = &DAT_00307cd4;
    **(undefined4 **)*param_1 = (unsigned int)(&DAT_00307c90);
    *(undefined **)(param_1[1] + 0x7c) = &DAT_00307ce4;
    *(int *)(*(int *)*param_1 + 0xd0) = (int)((char *)param_1 + 0x30) - *(int *)*param_1;
    *(int *)(*param_1 + 0x10) = (int)((char *)param_1 + 0x110) - *param_1;
    *(int *)(param_1[1] + 0x80) = (int)(param_1 + 0x4c) - param_1[1];
    if (param_2 != 0) {
      if (param_1 + 0x4c != (int *)0x0) {
        param_1[0x6b] = (int)&DAT_00307cf0;
        *(undefined **)param_1[0x4c] = &DAT_00307cfc;
        *(int *)(param_1[0x4c] + 0xd0) = (int)((char *)param_1 + 0x1b0) - param_1[0x4c];
      }
      if (param_1 + 0x44 != (int *)0x0) {
        param_1[0x45] = (int)&DAT_00307d40;
        *(undefined **)param_1[0x44] = &DAT_00307d50;
        *(int *)(param_1[0x44] + 0xd0) = (int)((char *)param_1 + 0x120) - param_1[0x44];
      }
      if (param_1 + 0xc != (int *)0x0) {
        param_1[0xc] = (int)&DAT_0030779c;
        FUN_00100b24(param_1 + 0xc,0);
      }
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
