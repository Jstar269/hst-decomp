/* HSTMATCH module=EBOOT.BIN start=0x00067d90 end=0x00067e54 symbol=FUN_00067d90 lang=c99 */
/* Clone of src/sharing_main/function_000691e4.c (hstclone.py tag u6cr5e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: declared a three-float callback and float output fields to preserve the EABI FPR arguments and callback results; exact match verified; names and types await human review. */
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


typedef float (*callback_t)(float,float,float);

void FUN_00067d90(float param_1,float *param_2,callback_t param_3)
{
  if (param_1 < 0.5f) {
    param_2[0] = param_3(255.0f,0.0f,param_1 * 2.0f);
    param_2[1] = 0.0f;
    param_2[2] = 0.0f;
    param_2[3] = 128.0f;
  }
  else {
    float value = 2.0f - param_1 * 2.0f;
    float result = param_3(255.0f,0.0f,value);
    param_2[2] = result;
    param_2[1] = result;
    param_2[0] = result;
    param_2[3] = param_3(0.0f,128.0f,value);
  }
  return;
}
