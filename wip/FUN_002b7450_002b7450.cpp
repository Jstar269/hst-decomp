/* HSTMATCH module=EBOOT.BIN start=0x002b7450 end=0x002b74b8 symbol=FUN_002b7450 lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
}
struct VC_0 {  virtual void m(int); };

extern "C" void FUN_002b7450(int *param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = (int *)(*param_1 + param_1[1] * 8);
  param_1[1] = param_1[1] - param_2;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    piVar1 = piVar1 + -2;
    ((VC_0 *)(piVar1))->m((int)(0xffffffff));
  }
  return;
}

// Near miss: the virtual dispatch and loop body match; only the frame allocation differs (retail 32 bytes, source 16 bytes).
// No stack object or stack-passed argument is present in the candidate to explain the extra 16 bytes, so the source remains unchanged.
// near miss from lane u4r4-1 (unreviewed)
