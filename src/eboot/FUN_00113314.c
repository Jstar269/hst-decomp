/* HSTMATCH module=EBOOT.BIN start=0x00113314 end=0x001133a8 symbol=FUN_00113314 lang=c99 */
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
extern undefined DAT_00307cf0;
extern undefined DAT_00307cfc;
extern void FUN_00000a00();
extern undefined4 * FUN_00100b24();

int * FUN_00113314(int *param_1,int param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    param_1[0x1f] = (int)&DAT_00307cf0;
    *(undefined **)*param_1 = &DAT_00307cfc;
    piVar1 = param_1 + 0x20;
    *(int *)(*param_1 + 0xd0) = (int)piVar1 - *param_1;
    if ((param_2 != 0) && (piVar1 != (int *)0x0)) {
      param_1[0x20] = (int)&DAT_0030779c;
      FUN_00100b24(piVar1,0);
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
