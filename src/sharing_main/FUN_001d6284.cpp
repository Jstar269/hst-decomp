/* HSTMATCH module=hstp_trans_main.prx start=0x001d6284 end=0x001d62ec symbol=FUN_001d6284 lang=c++ */
/* Clone of src/eboot/FUN_001c7df0.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
extern int * DAT_003e48c0;
extern void FUN_0013936c(...);
extern undefined4 FUN_001d94ec(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(int); };

extern "C" void FUN_001d6284(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  undefined1 auStack_10 [16];
  undefined1 auStack_20 [16];
  
  if ((DAT_003e48c0 != (int *)0x0) &&
     (iVar1 = FUN_001d94ec(param_1,param_2,auStack_10,auStack_20), iVar1 != 0)) {
    FUN_0013936c(DAT_003e48c0,1,0,0);
    ((VC_0 *)(DAT_003e48c0))->m((int)(auStack_10));
  }
  return;
}
