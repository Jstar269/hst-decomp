/* HSTMATCH module=EBOOT.BIN start=0x0028adc4 end=0x0028ae30 symbol=FUN_0028adc4 lang=c++ */
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
extern void FUN_0005743c(...);
}
struct VC_0 { virtual void d0(); virtual void m(); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void m(int, int); };

extern "C" void FUN_0028adc4(int *param_1)
{
  int *piVar1;
  
  piVar1 = (int *)param_1[0x1d];
  if (param_1[0x1c] != piVar1[0x23]) {
    ((VC_0 *)(piVar1))->m();
  }
  FUN_0005743c(param_1[0x1d],0,param_1[0x1f],0);
  ((VC_1 *)(param_1))->m((int)(0), (int)(0));
  return;
}

// Near miss: six words remain in the pointer/compare register allocation before the virtual call.
// Reversed field roles, typed the receiver, and tested direct member access; each remained six words off.
// near miss from lane u5cr1-0 (unreviewed)
