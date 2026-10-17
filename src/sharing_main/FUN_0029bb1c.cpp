/* HSTMATCH module=hstp_trans_main.prx start=0x0029bb1c end=0x0029bbe8 symbol=FUN_0029bb1c lang=c++ */
/* Clone of src/eboot/FUN_0028a328.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
extern undefined DAT_003b2ff0;
extern void FUN_00000a00(...);
extern undefined4 * FUN_00297f98(...);
extern int * FUN_0029e038(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" undefined4 * FUN_0029bb1c(undefined4 *param_1,short param_2)
{
  int *piVar1;
  undefined4 *puVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2ff0);
    piVar1 = (int *)param_1[0x1e];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x1e] = 0;
    }
    piVar1 = (int *)param_1[0x1d];
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      param_1[0x1d] = 0;
    }
    puVar2 = param_1 + 0x38;
    if ((puVar2 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
      FUN_0029e038(puVar2,0);
    }
    FUN_00297f98(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
