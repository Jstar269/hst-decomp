/* HSTMATCH module=hstp_trans_main.prx start=0x0025db40 end=0x0025dc80 symbol=FUN_0025db40 lang=c99 */
/* Clone of src/eboot/parabola_curve_0024d908.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
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

extern char DAT_003a480c[];
extern char DAT_003a4814[];
extern undefined8 FUN_0000c094(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
extern int FUN_00020f84(undefined4 param_1);
extern int FUN_00021694(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
extern int FUN_000223c8(undefined4 param_1,undefined4 param_2);
extern float FUN_00066bb0(int param_1,void *param_2,int param_3);
extern double pow(double,double);

void FUN_0025db40(int param_1)
{
  float local[9] = {0};
  float fVar6;
  float fVar7;
  int i;

  for (i = 0; i < 9; i++) {
    fVar6 = FUN_00066bb0(param_1,DAT_003a480c,1);
    fVar7 = FUN_00066bb0(param_1,DAT_003a4814,1);
    local[i] = fVar7 + pow((i + 1) + fVar6,2.0);
    if (i == 0) {
      *(float *)(param_1 + i * 4 + 0x30) = local[i];
    }
    else {
      *(float *)(param_1 + i * 4 + 0x30) = *(float *)(param_1 + i * 4 + 0x2c) + local[i];
    }
  }
}
