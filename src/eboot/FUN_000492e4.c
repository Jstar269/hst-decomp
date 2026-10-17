/* HSTMATCH module=EBOOT.BIN start=0x000492e4 end=0x00049350 symbol=FUN_000492e4 lang=c99 */
/* Clone of src/sharing_main/FUN_00049194.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v16) corrected by hand: formed the relative field as this plus 0x30 minus the base pointer; exact match verified; names and types await human review. */
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
extern void FUN_000493d0();
extern undefined4 * FUN_00056b98();

int * FUN_000492e4(int *param_1,short param_2)
{
  if (param_2 != 0) {
    *param_1 = (int)(param_1 + 0xc);
    FUN_00056b98((int)param_1 + 48);
  }
  param_1[1] = (int)&DAT_00306f98;
  *(undefined **)*param_1 = &DAT_00306fa4;
  *(int *)(*param_1 + 0x1b0) = (int)((char *)param_1 + 0x30) - *param_1;
  FUN_000493d0(param_1,&DAT_00306fa4);
  return param_1;
}
