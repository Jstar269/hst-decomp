/* HSTMATCH module=hstp_trans_main.prx start=0x001665f4 end=0x001666f0 symbol=FUN_001665f4 lang=c++ */
/* Clone of src/eboot/dtor_delete_members_loop_0015a01c.cpp (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: loop index declared before the walking pointer (swaps the s-register pair); exact match verified; names and types await human review. */
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
extern undefined DAT_003b233c;
extern undefined4 DAT_003e9738;
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

extern "C" undefined4 * FUN_001665f4(undefined4 *param_1,short param_2)
{
  int *piVar1;
  int iVar3;
  undefined4 *puVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b233c);
    DAT_003e9738 = 0;
    piVar1 = (int *)param_1[9];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[9] = 0;
    }
    piVar1 = (int *)param_1[10];
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      param_1[10] = 0;
    }
    iVar3 = 0;
    puVar2 = param_1;
    do {
      piVar1 = (int *)puVar2[0xd];
      if (piVar1 != (int *)0x0) {
        delete ((VC_2 *)(piVar1));
        puVar2[0xd] = 0;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < 3);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
