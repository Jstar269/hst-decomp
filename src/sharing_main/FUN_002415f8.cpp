/* HSTMATCH module=hstp_trans_main.prx start=0x002415f8 end=0x002416c4 symbol=FUN_002415f8 lang=c++ */
/* Clone of src/eboot/FUN_002314f8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
extern undefined DAT_003b2aec;
extern int * DAT_003f398c;
extern undefined4 DAT_003f3990;
extern void FUN_00000a00(...);
extern undefined4 * FUN_0001ed28(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_002415f8(undefined4 *param_1,short param_2)
{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2aec);
    DAT_003f3990 = 0;
    piVar1 = DAT_003f398c;
    if (DAT_003f398c != (int *)0x0) {
      if (DAT_003f398c != (int *)0x0) {
        DAT_003f398c = (int *)0x0;
        piVar2 = (int *)*piVar1;
        if (piVar2 != (int *)0x0) {
          delete ((VC_0 *)(piVar2));
          *piVar1 = 0;
        }
        FUN_00000a00(piVar1);
      }
      DAT_003f398c = (int *)0x0;
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
