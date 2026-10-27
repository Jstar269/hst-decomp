/* HSTMATCH module=hstp_trans_main.prx start=0x0015c3f4 end=0x0015c490 symbol=FUN_0015c3f4 lang=c99 data=0x003838a8 */
/* Clone of src/eboot/store_masked_result_001503bc.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003838a8-0x003838c7) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag global typed unsigned char (lbu), the call result masked with 0xff before the store, uVar4/uVar5 declaration order swapped for the s-registers; exact match verified; names and types await human review. */
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned int undefined4;

extern uchar DAT_003e9630;
extern undefined4 DAT_003f344c;
extern int FUN_00157e10();
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern int FUN_001db920();

undefined4 FUN_0015c3f4(int param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar5;
  undefined4 uVar4;
  
  uVar4 = param_2[3];
  uVar5 = *param_2;
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    puVar1 = (undefined4 *)FUN_00157e10(uVar5,8);
    FUN_0015bb68("IsExistText [%s_%02d, reg:%d]\n",*(undefined4 *)(param_1 + 8),*puVar1,
                 *(undefined4 *)(param_1 + 0xc));
  }
  uVar2 = FUN_001db920(DAT_003f344c,uVar4,*(undefined4 *)(param_1 + 8)) & 0xff;
  puVar3 = (uint *)FUN_00157e10(uVar5,*(undefined4 *)(param_1 + 0xc));
  *puVar3 = uVar2;
  return 0;
}
