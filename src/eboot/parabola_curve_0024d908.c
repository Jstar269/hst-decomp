/* HSTMATCH module=EBOOT.BIN start=0x0024d908 end=0x0024da48 symbol=FUN_0024d908 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py) corrected by hand: calls are `pow(double,double)` (0xc07c is newlib pow), the float sum `(i+1)+NeedX` is computed in single precision before the double conversion, and the destination walker is the same base pointer in the i==0 branch via `param_1 + i*4 + 0x30`; exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern char DAT_002fbdf8[];
extern char DAT_002fbe00[];
extern undefined8 FUN_0000c07c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
extern int FUN_00020f5c(undefined4 param_1);
extern int FUN_0002166c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
extern int FUN_000223a0(undefined4 param_1,undefined4 param_2);
extern float FUN_000657e4(int param_1,void *param_2,int param_3);
extern double pow(double,double);

void FUN_0024d908(int param_1)
{
  float local[9] = {0};
  float fVar6;
  float fVar7;
  int i;

  for (i = 0; i < 9; i++) {
    fVar6 = FUN_000657e4(param_1,DAT_002fbdf8,1);
    fVar7 = FUN_000657e4(param_1,DAT_002fbe00,1);
    local[i] = fVar7 + pow((i + 1) + fVar6,2.0);
    if (i == 0) {
      *(float *)(param_1 + i * 4 + 0x30) = local[i];
    }
    else {
      *(float *)(param_1 + i * 4 + 0x30) = *(float *)(param_1 + i * 4 + 0x2c) + local[i];
    }
  }
}
