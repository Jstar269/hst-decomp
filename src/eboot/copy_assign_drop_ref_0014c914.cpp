/* HSTMATCH module=EBOOT.BIN start=0x0014c914 end=0x0014c9b8 symbol=FUN_0014c914 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: the address-taken local_c = param_1 + 7 assigned after the field copies, just before the call; exact match verified; names and types await human review. */
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
extern void FUN_0014f32c(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_0014c914(undefined4 *param_1,undefined4 *param_2)
{
  int *piVar1;
  undefined1 auStack_4 [4];
  undefined4 local_8;
  undefined4 *local_c;
  
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    param_1[2] = 0;
  }
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[3] = param_2[3];
  *(undefined1 *)(param_1 + 4) = *(undefined1 *)(param_2 + 4);
  param_1[5] = param_2[5];
  param_1[2] = 0;
  local_c = param_1 + 7;
  local_8 = param_1[8];
  FUN_0014f32c(auStack_4,param_1 + 6,&local_8,&local_c);
  return param_1;
}
