/* HSTMATCH module=hstp_trans_main.prx start=0x0022cfb0 end=0x0022d048 symbol=FUN_0022cfb0 lang=c++ */
/* Clone of src/eboot/FUN_0021da3c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
extern undefined DAT_003b2a10;
extern void FUN_00000a00(...);
extern undefined4 * FUN_001087a8(...);
extern void FUN_0022d130(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_0022cfb0(undefined4 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2a10);
    FUN_0022d130();
    piVar1 = (int *)param_1[0x5b];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x5b] = 0;
    }
    FUN_001087a8(param_1 + 0x5d,0xffffffff);
    FUN_001087a8(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
