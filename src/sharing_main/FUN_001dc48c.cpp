/* HSTMATCH module=hstp_trans_main.prx start=0x001dc48c end=0x001dc504 symbol=FUN_001dc48c lang=c++ */
/* Clone of src/eboot/FUN_001cddb0.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };
struct VC_2 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };

extern "C" bool FUN_001dc48c(undefined4 param_1,int *param_2)
{
  bool bVar1;
  int iVar2;
  
  iVar2 = ((VC_0 *)(param_2))->m();
  bVar1 = iVar2 == 3;
  if (!bVar1) {
    iVar2 = ((VC_1 *)(param_2))->m();
    bVar1 = iVar2 == 5;
  }
  if (!bVar1) {
    iVar2 = ((VC_2 *)(param_2))->m();
    bVar1 = iVar2 == 4;
  }
  return bVar1;
}
