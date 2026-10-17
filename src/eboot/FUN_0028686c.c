/* HSTMATCH module=EBOOT.BIN start=0x0028686c end=0x00286938 symbol=FUN_0028686c lang=c99 */
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

extern undefined DAT_00309cac;
extern void FUN_000009e4();
extern void FUN_00000a00();
extern int * FUN_0014c028();
extern void FUN_00286cb8();
extern void FUN_00289434();

undefined4 * FUN_0028686c(undefined4 *param_1,short param_2)
{
  int *piVar1;
  undefined4 uStack_4;
  int local_8;
  undefined4 *local_c;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309cac);
    if (param_1[4] != 0) {
      FUN_000009e4(*(int *)((int)param_1 + 16));
      param_1[4] = 0;
    }
    FUN_00286cb8((int)param_1);
    if ((int *)param_1[1] != (int *)0x0) {
      FUN_0014c028((int *)param_1[1],1);
      param_1[1] = 0;
    }
    piVar1 = (int *)(param_1 + 0x19);
    if (((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) && (piVar1 != (int *)0x0)) {
      local_c = param_1 + 0x1a;
      local_8 = param_1[0x1b];
      FUN_00289434(&uStack_4,piVar1,&local_8,&local_c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
