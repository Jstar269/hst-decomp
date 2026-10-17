/* HSTMATCH module=hstp_trans_main.prx start=0x001f3cdc end=0x001f3d7c symbol=FUN_001f3cdc lang=c++ */
/* Clone of src/eboot/FUN_001e5ac4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
extern void FUN_00108f54(...);
extern void FUN_001f08e8(...);
extern void FUN_001f3d7c(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };
struct VC_2 { virtual void d0(); virtual void m(int); };
struct VC_3 { virtual void d0(); virtual void m(int); };
struct VC_4 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001f3cdc(int param_1)
{
  FUN_001f08e8();
  FUN_00108f54(*(undefined4 *)(param_1 + 0x1d68),0);
  ((VC_0 *)(*(int **)(param_1 + 0x1d6c)))->m((int)(0));
  ((VC_1 *)(*(int **)(param_1 + 0x1d70)))->m((int)(0));
  ((VC_2 *)(*(int **)(param_1 + 0x1d74)))->m((int)(0));
  ((VC_3 *)(*(int **)(param_1 + 0x1d78)))->m((int)(0));
  ((VC_4 *)(*(int **)(param_1 + 0x1d7c)))->m((int)(1));
  FUN_001f3d7c(param_1,0);
  return;
}
