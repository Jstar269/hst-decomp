/* HSTMATCH module=hstp_trans_main.prx start=0x0015ad6c end=0x0015ae44 symbol=FUN_0015ad6c lang=c++ */
/* Clone of src/eboot/FUN_0014ed64.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
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
extern undefined DAT_003b1614;
extern undefined DAT_003b1698;
extern void FUN_00000a00(...);
extern void FUN_0015b32c(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_0015ad6c(undefined4 *param_1,short param_2)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined1 auStack_4 [4];
  undefined4 local_8;
  undefined4 *local_c;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b1614);
    if ((char *)param_1 + 0x4 != (char *)0) {
      piVar1 = (int *)param_1[3];
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        param_1[3] = 0;
      }
      puVar2 = param_1 + 7;
      if (((puVar2 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) &&
         (puVar2 != (undefined4 *)0x0)) {
        local_c = param_1 + 8;
        local_8 = param_1[9];
        FUN_0015b32c(auStack_4,puVar2,&local_8,&local_c);
      }
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b1698);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
