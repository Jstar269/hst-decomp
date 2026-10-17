/* HSTMATCH module=EBOOT.BIN start=0x00115e60 end=0x00115f24 symbol=FUN_00115e60 lang=c99 */
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

extern undefined DAT_0030779c;
extern undefined DAT_00307f04;
extern undefined DAT_00307f18;
extern undefined DAT_00307f60;
extern void FUN_00000a00();
extern undefined4 * FUN_00100b24();
extern int * FUN_00107514();

int * FUN_00115e60(int *param_1,int param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    param_1[1] = (int)&DAT_00307f04;
    *(undefined **)*param_1 = &DAT_00307f18;
    *(int *)(*param_1 + 0x130) = (int)(param_1 + 0x1c) - *param_1;
    if ((param_2 != 0) && (param_1 + 0x1c != (int *)0x0)) {
      piVar1 = param_1 + 100;
      param_1[0x1c] = (int)&DAT_00307f60;
      if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
        FUN_00107514(piVar1,0);
      }
      if (param_1 + 0x1c != (int *)0x0) {
        param_1[0x1c] = (int)&DAT_0030779c;
        FUN_00100b24(param_1 + 0x1c,0);
      }
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
