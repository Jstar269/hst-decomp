/* HSTMATCH module=hstp_trans_main.prx start=0x000fcc4c end=0x000fcd74 symbol=FUN_000fcc4c lang=c99 data=0x0037ef90 */
/* Clone of src/eboot/FUN_000f7558.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (4 strings, 0x0037ef90-0x0037efdc) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a2/v0c) corrected by hand: typed helper arguments and reused the allocation result; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern u32 * FUN_000fbaf4();
extern void FUN_000fbe68();
extern int FUN_00108124();
extern u32 * FUN_0010873c();
extern void FUN_00108e6c(float param_1,int param_2);
extern void FUN_001090f4(int param_1,int param_2);
extern int FUN_00109304();
extern void FUN_00109a44();

u32 * FUN_000fcc4c(u32 *param_1)
{
  u32 *puVar1;
  int iVar3;
  
  FUN_000fbaf4(param_1);
  puVar1 = (u32 *)FUN_00000bcc(0x54);
  if (puVar1 != (u32 *)0x0) {
    puVar1 = FUN_0010873c(puVar1);
  }
  *param_1 = (unsigned int)(puVar1);
  FUN_00109a44((int)*param_1,(u32 *)"data/menu/inpane/inp_emoji/inpaneinp_emoji.lay",0);
  FUN_00108e6c(3099.0f,*param_1);
  FUN_001090f4(*param_1,-4096);
  FUN_00108e6c(3099.0f,*param_1);
  FUN_001090f4(*param_1,-4096);
  FUN_000fbe68((int)param_1,0xf);
  iVar3 = FUN_00109304(*param_1,(u8 *)"emoji",0);
  param_1[5] = iVar3;
  iVar3 = FUN_00108124(iVar3,(u8 *)"inp_info0");
  param_1[8] = *(u32 *)(iVar3 + 0x24);
  param_1[6] = iVar3;
  iVar3 = FUN_00108124(param_1[5],(u8 *)"inp_bg0");
  param_1[9] = *(u32 *)(iVar3 + 0x24);
  param_1[7] = iVar3;
  param_1[0x20f] = 0x41a00000;
  param_1[0x210] = 0;
  param_1[0x211] = 0x40a00000;
  param_1[0x212] = 0x3f19999a;
  param_1[0x218] = 0x42800000;
  param_1[0x219] = 0x42800000;
  param_1[0x21a] = 0x42800000;
  param_1[0x21b] = 0x42800000;
  return param_1;
}

