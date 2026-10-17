/* HSTMATCH module=hstp_trans_main.prx start=0x0017cdfc end=0x0017cef0 symbol=FUN_0017cdfc lang=c++ */
/* Clone of src/eboot/release_or_create_slot_00170b30.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a6, variant v17) corrected by hand: flag byte typed unsigned char (lbu) and the new-then-construct store shared (p = alloc; if (p) p = ctor(p); *slot = p); exact match verified; names and types await human review. */
typedef unsigned int uint;
typedef unsigned int undefined4;
typedef unsigned char undefined;

extern "C" {
extern undefined DAT_003f468c;
extern int FUN_00000bcc(...);
extern undefined4 * FUN_000934c8(...);
extern void FUN_000935b4(...);
extern void FUN_000938e0(...);
extern void FUN_00094e8c(...);
extern undefined4 FUN_00188a38(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_0017cdfc(int param_1,int param_2)
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  
  if (*(unsigned char *)(param_1 + 0x4d) != 0) {
    uVar1 = FUN_00188a38(*(int *)(param_1 + 0x178));
    if ((uVar1 & 0xff) == 0) {
      piVar4 = (int *)(&DAT_003f468c + param_2 * 4);
      piVar5 = (int *)*piVar4;
      if (piVar5 != (int *)0x0) {
        delete ((VC_0 *)(piVar5));
        *piVar4 = 0;
      }
    }
    else {
      piVar5 = (int *)(&DAT_003f468c + param_2 * 4);
      if (*piVar5 == 0) {
        puVar3 = (undefined4 *)FUN_00000bcc(0xe0);
        if (puVar3 != (undefined4 *)0x0) {
          puVar3 = FUN_000934c8(puVar3);
        }
        *piVar5 = (int)puVar3;
      }
      iVar2 = *(int *)(param_1 + 0x178);
      FUN_000935b4(*piVar5,*(int *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 4) * 4) + 0x10);
      FUN_000938e0(*piVar5,0);
      FUN_00094e8c(*piVar5);
    }
  }
  return;
}
