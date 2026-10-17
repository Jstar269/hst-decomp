/* HSTMATCH module=hstp_trans_main.prx start=0x00274308 end=0x00274340 symbol=FUN_00274308 lang=c++ */
/* Clone of src/eboot/FUN_0026348c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
extern undefined4 DAT_003e1a08;
extern undefined4 FUN_0008f170(...);
extern void FUN_0026a188(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void m(); };

extern "C" void FUN_00274308(void)
{
  int *piVar1;
  
  FUN_0026a188();
  piVar1 = (int *)FUN_0008f170(DAT_003e1a08);
  ((VC_0 *)(piVar1))->m();
  return;
}
