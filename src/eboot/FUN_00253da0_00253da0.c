/* HSTMATCH module=EBOOT.BIN start=0x00253da0 end=0x00253f38 symbol=FUN_00253da0 lang=c99 data=0x002fcc78 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: declared the loop index before the byte offset to match the retail saved-register allocation; exact match verified; names and types await human review. Data: its string literals (6 strings, 0x002fcc78-0x002fcd87) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 * DAT_0034a79c;
extern int * FUN_000008d8();
extern int FUN_00000a90();
extern void FUN_000143b0();
extern u32 FUN_00055eac();
extern void FUN_00055dd0();
extern void FUN_00055e48();

void FUN_00253da0(void)
{
  u32 uVar1;
  int iVar3;
  int iVar2;
  u8 auStack_100 [256];
  
  uVar1 = FUN_00000a90(0x230);
  DAT_0034a79c = (unsigned char *)(FUN_000008d8(uVar1,FUN_00055dd0,FUN_00055e48,0x10,0x22));
  iVar3 = 0;
  iVar2 = 0;
  do {
    if (iVar3 < 0xf) {
      FUN_000143b0(auStack_100,"data/chara/menu_motion/%02d/chrm_pc%02d_00.i3m",iVar3,iVar3);
      FUN_00055eac(DAT_0034a79c + iVar2,auStack_100,0);
    }
    else if (iVar3 < 0x1e) {
      FUN_000143b0(auStack_100,"data/chara/menu_motion/%02d/chrm_pc%02d_01.i3m",iVar3 + -0xf,iVar3 + -0xf
                  );
      FUN_00055eac(DAT_0034a79c + iVar2,auStack_100,0);
    }
    else if (iVar3 == 0x1e) {
      FUN_00055eac(DAT_0034a79c + iVar2,"data/chara/menu_motion/99/chrm_pc_f_00.i3m",0);
    }
    else if (iVar3 == 0x1f) {
      FUN_00055eac(DAT_0034a79c + iVar2,"data/chara/menu_motion/99/chrm_pc_f_01.i3m",0);
    }
    else if (iVar3 == 0x20) {
      FUN_00055eac(DAT_0034a79c + iVar2,"data/chara/menu_motion/99/chrm_pc_m_00.i3m",0);
    }
    else if (iVar3 == 0x21) {
      FUN_00055eac(DAT_0034a79c + iVar2,"data/chara/menu_motion/99/chrm_pc_m_01.i3m",0);
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 0x10;
  } while (iVar3 < 0x22);
}

