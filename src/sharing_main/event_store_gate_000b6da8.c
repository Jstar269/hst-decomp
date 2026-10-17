/* HSTMATCH module=hstp_trans_main.prx start=0x000b6da8 end=0x000b6e80 symbol=FUN_000b6da8 lang=c99 */
/* Clone of src/eboot/event_store_gate_000b3b90.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003e19f8 and the flag at +0x1b4 typed as bytes, the gate split into bVar1 = DAT != 0 then bVar1 = (flag != 0) ^ 1 with an int flag; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char bool;
typedef unsigned int undefined4;
#define false 0
#define true 1
extern undefined *DAT_003e19f0;
extern undefined DAT_003e19f8;
extern undefined *DAT_003e1e30;
extern int FUN_000c8538();
extern int FUN_001c31b4();

void FUN_000b6da8(int param_1,int param_2,undefined4 param_3)
{
  int bVar1;
  int iVar2;

  if ((param_2 != 0xd0) &&
     (FUN_001c31b4(*(undefined4 *)(DAT_003e19f0 + 0xa8),*(undefined4 *)(param_1 + 0x148),param_2,
                   param_3), *(int *)(param_1 + 0x3c) != 7)) {
    *(int *)(param_1 + 0x5b4) = param_2;
    *(char *)(param_1 + 0x5b8) = (char)param_3;
    bVar1 = DAT_003e19f8 != 0;
    if (bVar1) {
      bVar1 = (*(unsigned char *)(param_1 + 0x1b4) != 0) ^ 1;
    }
    if (((bVar1) && (DAT_003e1e30 != 0)) && (param_2 != 0xd0)) {
      iVar2 = FUN_000c8538(DAT_003e1e30,*(undefined4 *)(param_1 + 0x148));
      *(undefined4 *)(iVar2 + 0x70) = *(undefined4 *)(DAT_003e1e30 + 0x780);
      *(int *)(iVar2 + 0x68) = param_2;
      *(char *)(iVar2 + 0x6c) = (char)param_3;
    }
  }
  return;
}
