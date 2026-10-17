/* HSTMATCH module=hstp_trans_main.prx start=0x0024c860 end=0x0024c8b4 symbol=FUN_0024c860 lang=c++ */
/* Clone of src/eboot/FUN_0023c6c8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
extern void FUN_001118ac(...);
extern void FUN_0024e004(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_0024c860(int param_1)
{
  ((VC_0 *)(*(int **)(param_1 + 0x11b8)))->m((int)(0));
  FUN_001118ac(*(undefined4 *)(param_1 + 0x11b8),0x11,0x19);
  FUN_0024e004(param_1,1,0);
  return;
}
