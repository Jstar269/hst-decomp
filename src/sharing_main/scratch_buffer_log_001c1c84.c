/* HSTMATCH module=hstp_trans_main.prx start=0x001c1c84 end=0x001c1d6c symbol=FUN_001c1c84 lang=c99 data=0x00390f10 */
/* Clone of src/eboot/scratch_buffer_log_001b37f4.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00390f10-0x00390f47) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the two module addresses written as &DAT_003b3e6c / &DAT_003b7ebc (lui/addiu, not lui/ori); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b3e6c;
extern u8 DAT_003b7ebc;
extern u8 DAT_0038d204;
extern u8 DAT_0038d208;
extern int FUN_00010184();
extern void FUN_000104e0();
extern void FUN_0001bb2c();
extern void FUN_0001c5f4();
extern void FUN_0001c73c();
extern int FUN_0001c848();
extern u32 FUN_0001c8a0();
extern void FUN_001be0d0();

void FUN_001c1c84(u32 *param_1)
{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  
  uVar3 = *param_1;
  uVar1 = FUN_00010184(0x40,0x100000);
  FUN_0001bb2c(&DAT_003b3e6c,uVar1,0x100000);
  FUN_0001c5f4(&DAT_003b7ebc,"sound/menu/000_common_0.xb");
  FUN_001be0d0(uVar3,&DAT_0038d204,1,0);
  FUN_0001c73c(&DAT_003b7ebc);
  FUN_0001c5f4(&DAT_003b7ebc,"sound/menu/000_common_1.xb");
  FUN_001be0d0(uVar3,&DAT_0038d208,3,0);
  FUN_0001c73c(&DAT_003b7ebc);
  uVar3 = FUN_0001c848();
  uVar2 = FUN_0001c8a0();
  FUN_0001bb2c(&DAT_003b3e6c,uVar3,uVar2);
  FUN_000104e0(uVar1);
}
