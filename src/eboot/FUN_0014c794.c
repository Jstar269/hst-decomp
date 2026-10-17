/* HSTMATCH module=EBOOT.BIN start=0x0014c794 end=0x0014c820 symbol=FUN_0014c794 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256c); exact match verified; names and types await human review. */
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

extern void FUN_0014f32c();
extern undefined4 * FUN_0014f528();

undefined4 * FUN_0014c794(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  int *piVar1;
  undefined1 auStack_4 [4];
  undefined4 local_8;
  undefined4 *local_c;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = param_4;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_0014f528(param_1 + 6);
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 == 0) {
      param_1[5] = (unsigned int)(piVar1 + 1);
    }
    else {
      param_1[5] = piVar1[2];
    }
  }
  local_c = param_1 + 7;
  local_8 = param_1[8];
  FUN_0014f32c(auStack_4,param_1 + 6,&local_8,&local_c);
  return param_1;
}
