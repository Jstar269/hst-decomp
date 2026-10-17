/* HSTMATCH module=hstp_trans_main.prx start=0x0012dc54 end=0x0012dd1c symbol=FUN_0012dc54 lang=c++ */
/* Clone of src/eboot/dtor_delete_members_00122a80.cpp (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: loop index declared before the member pointer (s-register order); exact match verified; names and types await human review. */
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
extern undefined DAT_003b12f4;
extern void FUN_00000a00(...);
extern undefined4 * FUN_0001ed28(...);
extern int FUN_002251c8(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_0012dc54(undefined4 *param_1,short param_2)
{
  int iVar3;
  undefined4 *puVar2;
  int *piVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b12f4);
    iVar3 = 0;
    puVar2 = param_1;
    do {
      piVar1 = (int *)puVar2[0xf];
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        puVar2[0xf] = 0;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < 3);
    if (param_1[0x15] != 0) {
      FUN_002251c8(param_1[0x15],1);
      param_1[0x15] = 0;
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
