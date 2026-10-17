/* HSTMATCH module=hstp_trans_main.prx start=0x001dcf40 end=0x001dcfa4 symbol=FUN_001dcf40 lang=c++ */
/* Clone of src/eboot/FUN_001ce864.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
struct VC_0 { virtual void d0(); virtual void d1(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001dcf40(int *param_1,int param_2)
{
  ((VC_0 *)(param_1))->m((int)(param_1[1]));
  param_1[5] = param_1[1];
  param_1[1] = param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  ((VC_1 *)(param_1))->m((int)(param_2));
  return;
}
