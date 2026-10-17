/* HSTMATCH module=hstp_trans_main.prx start=0x000d3070 end=0x000d3148 symbol=FUN_000d3070 lang=c++ */
/* Clone of src/eboot/dtor_delete_members_000cf474.cpp (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: loop index declared before the member pointer (s-register order); exact match verified; names and types await human review. */
typedef unsigned int undefined4;

extern "C" {
extern char DAT_003b07a8;
extern void FUN_00000a00(...);
extern undefined4 * FUN_0001ed28(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" undefined4 * FUN_000d3070(undefined4 *param_1,short param_2)
{
  int iVar3;
  undefined4 *puVar2;
  int *piVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b07a8);
    iVar3 = 0;
    puVar2 = param_1;
    do {
      piVar1 = (int *)puVar2[0x10];
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        puVar2[0x10] = 0;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < 0x16);
    piVar1 = (int *)param_1[0x27];
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      param_1[0x27] = 0;
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
