/* HSTMATCH module=EBOOT.BIN start=0x001503bc end=0x00150458 symbol=FUN_001503bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag global typed unsigned char (lbu), the call result masked with 0xff before the store, uVar4/uVar5 declaration order swapped for the s-registers; exact match verified; names and types await human review. */
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned int undefined4;

extern uchar DAT_003402f0;
extern undefined4 DAT_0034a114;
extern char DAT_002dc3c0[];
extern int FUN_0014c384();
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern int FUN_001cd1b8();

undefined4 FUN_001503bc(int param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar5;
  undefined4 uVar4;
  
  uVar4 = param_2[3];
  uVar5 = *param_2;
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    puVar1 = (undefined4 *)FUN_0014c384(uVar5,8);
    FUN_0014fd94(DAT_002dc3c0,*(undefined4 *)(param_1 + 8),*puVar1,
                 *(undefined4 *)(param_1 + 0xc));
  }
  uVar2 = FUN_001cd1b8(DAT_0034a114,uVar4,*(undefined4 *)(param_1 + 8)) & 0xff;
  puVar3 = (uint *)FUN_0014c384(uVar5,*(undefined4 *)(param_1 + 0xc));
  *puVar3 = uVar2;
  return 0;
}
