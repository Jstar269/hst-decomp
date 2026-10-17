/* HSTMATCH module=EBOOT.BIN start=0x001b4464 end=0x001b4528 symbol=FUN_001b4464 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: typed helper calls include their float and mode arguments, with an explicit negative early return; exact match verified; names and types await human review. */
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

extern void FUN_000628e4(int param_1,int param_2);
extern void FUN_00062b1c(int param_1,float param_2,int param_3);

void FUN_001b4464(int *param_1,int param_2)
{
  int self = *param_1;

  if (param_2 != 0) {
    if (*(int *)(self + 0x7ac) >= 0) {
      FUN_00062b1c(*(int *)(self + 0x7ac),0.5f,0);
      *(int *)(self + 2000) = *(int *)(self + 0x7ac);
      *(float *)(self + 0x7d4) = 0.0f;
    }
    if (*(int *)(self + 0x7b4) >= 0) {
      FUN_00062b1c(*(int *)(self + 0x7b4),0.0f,128);
    }
  } else {
    if (*(int *)(self + 0x7b4) >= 0) {
      FUN_00062b1c(*(int *)(self + 0x7b4),0.5f,0);
    }
    if (*(int *)(self + 0x7ac) < 0) return;
    FUN_00062b1c(*(int *)(self + 0x7ac),0.0f,128);
    if (*(int *)(self + 2000) >= 0) {
      FUN_000628e4(*(int *)(self + 2000),0);
      *(int *)(self + 2000) = -1;
    }
    *(float *)(self + 0x7d4) = 1.0f;
  }
  return;
}
