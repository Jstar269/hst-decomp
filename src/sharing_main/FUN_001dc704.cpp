/* HSTMATCH module=hstp_trans_main.prx start=0x001dc704 end=0x001dc730 symbol=FUN_001dc704 lang=c++ */
/* Clone of src/eboot/FUN_001ce028.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" bool FUN_001dc704(undefined4 param_1,int *param_2)
{
  int iVar1;
  
  iVar1 = ((VC_0 *)(param_2))->m();
  return iVar1 == 3;
}
