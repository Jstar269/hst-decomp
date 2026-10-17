/* HSTMATCH module=hstp_trans_main.prx start=0x00152f14 end=0x0015300c symbol=FUN_00152f14 lang=c99 */
/* Clone of src/eboot/vec_dtor_0014762c.c (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0) corrected by hand: the three calls to the delete function (0xa00) take their arguments (element field +8, the buffer pointer *param_1, and the object itself); exact match verified; names and types await human review. */
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

extern void FUN_00000a00(void *);
extern int FUN_0015300c();
extern int FUN_00153014();

int * FUN_00152f14(int *param_1,short param_2)
{
  uint *puVar1;
  uint *puVar2;
  
  if (param_1 != (int *)0x0) {
    puVar1 = (uint *)(*param_1 + param_1[4] * 0x28);
    puVar2 = puVar1 + param_1[1] * 10;
    if (puVar1 < puVar2) {
      do {
        puVar2 = puVar2 + -10;
        if (((puVar2 != (uint *)0x0) && (puVar2 != (uint *)0x0)) && ((*puVar2 & 1) != 0)) {
          FUN_00000a00((void *)puVar2[2]);
        }
      } while (puVar1 < puVar2);
      param_1[1] = 0;
    }
    else {
      param_1[1] = 0;
    }
    if ((param_1 != (int *)0x0) && (FUN_00153014((int)param_1), *param_1 != 0)) {
      FUN_0015300c((int)param_1);
      FUN_00000a00((void *)*param_1);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
