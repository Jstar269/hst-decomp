/* HSTMATCH module=hstp_trans_main.prx start=0x001e9124 end=0x001e9198 symbol=FUN_001e9124 lang=c99 */
/* Clone of src/eboot/vec_to_angles_001dafe8.c (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the two products are formed in the order they are used (x * F(yaw) first, then z * G(yaw)) instead of Ghidra's hoisted locals; exact match verified; names and types await human review. */
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

extern float FUN_0000bc4c(float param_1);
extern float FUN_0000bf4c(float param_1);
extern float FUN_0000c6f4(float param_1,float param_2);

void FUN_001e9124(undefined4 param_1,float *param_2,float *param_3)
{
  float t;
  float u;
  param_2[0] = FUN_0000c6f4(param_3[0], param_3[2]);
  t = param_3[0] * FUN_0000bf4c(param_2[0]);
  u = param_3[2] * FUN_0000bc4c(param_2[0]);
  param_2[1] = FUN_0000c6f4(param_3[1], t + u);
}
