/* HSTMATCH module=EBOOT.BIN start=0x00266a24 end=0x00266a9c symbol=FUN_00266a24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: modeled the helper output as a four-word vector and typed object float fields; exact match verified; names and types await human review. */
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
typedef float undefined4;

extern float FUN_0000c6dc(float param_1,float param_2);
struct Vector4 {
  float value[3];
  int tail;
};
extern void FUN_00022518(struct Vector4 *out, const float *in);

void FUN_00266a24(int param_1,undefined1 (*param_2) [12],int param_3)
{
  float *object = (float *)param_1;
  struct Vector4 local;
  float result;
  
  object[90] = object[89];
  FUN_00022518(&local,(const float *)param_2);
  local.tail = 0;
  result = FUN_0000c6dc(local.value[0],local.value[2]);
  object[89] = result;
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0x130);
    *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_1 + 0x134);
    *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(param_1 + 0x138);
    *(undefined4 *)(param_1 + 0x15c) = *(undefined4 *)(param_1 + 0x13c);
    *(undefined1 *)(param_1 + 0x160) = 0;
  }
  return;
}
