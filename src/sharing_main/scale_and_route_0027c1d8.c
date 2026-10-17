/* HSTMATCH module=hstp_trans_main.prx start=0x0027c1d8 end=0x0027c26c symbol=FUN_0027c1d8 lang=c99 */
/* Clone of src/eboot/scale_and_route_0026b25c.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used fabsf and matched the float branch and mode arguments; exact match verified; names and types await human review. */
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

extern void FUN_00108dac();
extern void FUN_0027aa2c();
extern float fabsf(float);

void FUN_0027c1d8(int param_1)
{
  float fVar1;
  
  fVar1 = *(float *)(**(int **)(param_1 + 4) + 0x60);
  fVar1 = fVar1 + -fVar1 * 0.5f;
  *(float *)(**(int **)(param_1 + 4) + 0x60) = fVar1;
  FUN_00108dac();
  if (fabsf(fVar1) < 16.0f) {
    if (*(int *)(param_1 + 0x5c) == 0)
      FUN_0027aa2c(param_1,1);
    else
      FUN_0027aa2c(param_1,3);
  }
  return;
}
