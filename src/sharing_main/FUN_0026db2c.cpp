/* HSTMATCH module=hstp_trans_main.prx start=0x0026db2c end=0x0026db70 symbol=FUN_0026db2c lang=c++ */
/* Clone of src/eboot/FUN_0025d580.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
extern void FUN_0026db70(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void m(int); };

extern "C" void FUN_0026db2c(int param_1)
{
  FUN_00108f54(param_1,1);
  ((VC_0 *)(*(int **)(param_1 + 0x68)))->m((int)(0));
  FUN_0026db70(param_1);
  return;
}
