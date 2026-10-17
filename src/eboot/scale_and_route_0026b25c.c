/* HSTMATCH module=EBOOT.BIN start=0x0026b25c end=0x0026b2f0 symbol=FUN_0026b25c lang=c99 */
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

extern void FUN_00103480();
extern void FUN_00269ab0();
extern float fabsf(float);

void FUN_0026b25c(int param_1)
{
  float fVar1;
  
  fVar1 = *(float *)(**(int **)(param_1 + 4) + 0x60);
  fVar1 = fVar1 + -fVar1 * 0.5f;
  *(float *)(**(int **)(param_1 + 4) + 0x60) = fVar1;
  FUN_00103480();
  if (fabsf(fVar1) < 16.0f) {
    if (*(int *)(param_1 + 0x5c) == 0)
      FUN_00269ab0(param_1,1);
    else
      FUN_00269ab0(param_1,3);
  }
  return;
}
