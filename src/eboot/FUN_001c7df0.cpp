/* HSTMATCH module=EBOOT.BIN start=0x001c7df0 end=0x001c7e58 symbol=FUN_001c7df0 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
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
extern int * DAT_0033b580;
extern void FUN_0012de6c(...);
extern undefined4 FUN_001caee4(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(int); };

extern "C" void FUN_001c7df0(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  undefined1 auStack_10 [16];
  undefined1 auStack_20 [16];
  
  if ((DAT_0033b580 != (int *)0x0) &&
     (iVar1 = FUN_001caee4(param_1,param_2,auStack_10,auStack_20), iVar1 != 0)) {
    FUN_0012de6c(DAT_0033b580,1,0,0);
    ((VC_0 *)(DAT_0033b580))->m((int)(auStack_10));
  }
  return;
}
