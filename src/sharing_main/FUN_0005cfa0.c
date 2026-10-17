/* HSTMATCH module=hstp_trans_main.prx start=0x0005cfa0 end=0x0005cffc symbol=FUN_0005cfa0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern float FUN_0000b8c0(float param_1);
extern float FUN_0000c018(float param_1);

float FUN_0005cfa0(int param_1)
{
  float fVar1;
  
  fVar1 = (float)FUN_0000c018(*(float *)(param_1 + 0x200) * 0.008726646f);
  fVar1 = (float)FUN_0000b8c0(fVar1 * (*(float *)(param_1 + 0x224) / *(float *)(param_1 + 0x220)));
  return fVar1 * 114.59156f;
}
