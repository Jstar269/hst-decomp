/* HSTMATCH module=EBOOT.BIN start=0x001dafe8 end=0x001db05c symbol=FUN_001dafe8 lang=c99 */
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

extern float FUN_0000bc34(float param_1);
extern float FUN_0000bf34(float param_1);
extern float FUN_0000c6dc(float param_1,float param_2);

void FUN_001dafe8(undefined4 param_1,float *param_2,float *param_3)
{
  float t;
  float u;
  param_2[0] = FUN_0000c6dc(param_3[0], param_3[2]);
  t = param_3[0] * FUN_0000bf34(param_2[0]);
  u = param_3[2] * FUN_0000bc34(param_2[0]);
  param_2[1] = FUN_0000c6dc(param_3[1], t + u);
}
