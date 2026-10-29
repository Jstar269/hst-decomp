/* HSTMATCH module=EBOOT.BIN start=0x00253da0 end=0x00253f38 symbol=FUN_00253da0 lang=c99 data=0x002fcc78 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: declared the loop index before the byte offset to match the retail saved-register allocation; readability pass; exact match verified; names and types await human review. Data: its string literals (6 strings, 0x002fcc78-0x002fcd87) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

#define CHARACTER_COUNT 0xf     /* characters with a menu motion each in variants _00 and _01 */
#define MOTION_COUNT 0x22       /* 2 * 15 character motions + 4 extra ones */
#define MOTION_SLOT_SIZE 0x10
#define MOTION_ARRAY_BYTES 0x230

extern u8 * DAT_0034a79c;       /* array of MOTION_COUNT motion slots */
extern int * FUN_000008d8();
extern int FUN_00000a90();
extern void FUN_000143b0();
extern u32 FUN_00055eac();
extern void FUN_00055dd0();
extern void FUN_00055e48();

/* Allocates the menu motion slots and loads the motion file of each one. */
void FUN_00253da0(void)
{
  u32 mem;
  int index;
  int offset;
  u8 path[256];

  mem = FUN_00000a90(MOTION_ARRAY_BYTES);
  DAT_0034a79c = (unsigned char *)(FUN_000008d8(mem,FUN_00055dd0,FUN_00055e48,MOTION_SLOT_SIZE,MOTION_COUNT));
  index = 0;
  offset = 0;
  do {
    if (index < CHARACTER_COUNT) {
      FUN_000143b0(path,"data/chara/menu_motion/%02d/chrm_pc%02d_00.i3m",index,index);
      FUN_00055eac(DAT_0034a79c + offset,path,0);
    }
    else if (index < CHARACTER_COUNT * 2) {
      FUN_000143b0(path,"data/chara/menu_motion/%02d/chrm_pc%02d_01.i3m",index - CHARACTER_COUNT,index - CHARACTER_COUNT);
      FUN_00055eac(DAT_0034a79c + offset,path,0);
    }
    else if (index == 0x1e) {
      FUN_00055eac(DAT_0034a79c + offset,"data/chara/menu_motion/99/chrm_pc_f_00.i3m",0);
    }
    else if (index == 0x1f) {
      FUN_00055eac(DAT_0034a79c + offset,"data/chara/menu_motion/99/chrm_pc_f_01.i3m",0);
    }
    else if (index == 0x20) {
      FUN_00055eac(DAT_0034a79c + offset,"data/chara/menu_motion/99/chrm_pc_m_00.i3m",0);
    }
    else if (index == 0x21) {
      FUN_00055eac(DAT_0034a79c + offset,"data/chara/menu_motion/99/chrm_pc_m_01.i3m",0);
    }
    index = index + 1;
    offset = offset + MOTION_SLOT_SIZE;
  } while (index < MOTION_COUNT);
}
