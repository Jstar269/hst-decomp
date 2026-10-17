/* HSTMATCH module=EBOOT.BIN start=0x00049350 end=0x000493d0 symbol=FUN_00049350 lang=c99 */
/* Clone of src/sharing_main/FUN_00049200.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_00306f98;
extern undefined DAT_00306fa4;
extern void FUN_00000a00();
extern undefined4 * FUN_00056cb0();

int * FUN_00049350(int *param_1,int param_2)
{
  if (param_1 != (int *)0x0) {
    param_1[1] = (int)&DAT_00306f98;
    *(undefined **)*param_1 = &DAT_00306fa4;
    *(int *)(*param_1 + 0x1b0) = (int)(param_1 + 0xc) - *param_1;
    if (param_2 != 0) {
      FUN_00056cb0(param_1 + 0xc,0);
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
