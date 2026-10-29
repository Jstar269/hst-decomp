/* HSTMATCH module=EBOOT.BIN start=0x00281238 end=0x0028144c symbol=FUN_00281238 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ mode, non-POD struct memberwise copy assignment for 16-byte buffer, and 64-bit integer copy at tail; readability pass; exact match verified; names and types await human review. */

#include "hst/types.h"
#include "hst/slot_block.h"

extern "C" SetupData *DAT_003415a8;
extern "C" u32 *FUN_000114c0(void *, int, int);

struct Array16 {
  char data[16];
  Array16() {}
};

/* Resets a slot block: ids to -1, then each slot's record to its defaults (default name, scale 5.0, count 10). */
extern "C" void FUN_00281238(SlotBlock *blk)
{
  u32 i;
  int *idp;
  
  i = 0;
  idp = blk->ids;
  do {
    i = i + 1;
    *idp = SLOT_ID_NONE;
    idp = idp + 1;
  } while (i < 4);
  blk->unk10 = SLOT_ID_NONE;
  blk->unk14 = 0;
  FUN_000114c0(blk->unk18, 0, 0x1c);
  blk->unk20 = 1;
  
  blk->slots[0].rec.unk00 = 0;
  blk->slots[0].rec.unk03 = 0;
  blk->slots[0].rec.unk01 = 0;
  blk->slots[0].rec.unk25 = 0;
  blk->slots[0].rec.unk26 = 0;
  blk->slots[0].rec.unk27 = 0;
  blk->slots[0].rec.unk28 = 0;
  blk->slots[0].rec.unk2c = -1;
  blk->slots[0].rec.unk30 = -1;
  blk->slots[0].rec.unk34 = SLOT_REC_DEFAULT_SCALE;
  blk->slots[0].rec.unk38 = 10;
  blk->slots[0].rec.unk39 = 0;
  blk->slots[0].rec.unk3c = 0;

  blk->slots[0].rec.name[0] = -29;
  blk->slots[0].rec.name[1] = -127;
  blk->slots[0].rec.name[2] = -65;
  blk->slots[0].rec.name[3] = -29;
  blk->slots[0].rec.name[4] = -126;
  blk->slots[0].rec.name[5] = -109;
  blk->slots[0].rec.name[6] = -29;
  blk->slots[0].rec.name[7] = -125;
  blk->slots[0].rec.name[8] = -122;
  blk->slots[0].rec.name[9] = -29;
  blk->slots[0].rec.name[10] = -125;
  blk->slots[0].rec.name[11] = -117;
  blk->slots[0].rec.name[12] = 80;
  blk->slots[0].rec.name[0] = 0;

  blk->slots[1].rec.unk00 = 0;
  blk->slots[1].rec.unk03 = 0;
  blk->slots[1].rec.unk01 = 0;
  blk->slots[1].rec.unk25 = 0;
  blk->slots[1].rec.unk26 = 0;
  blk->slots[1].rec.unk27 = 0;
  blk->slots[1].rec.unk28 = 0;
  blk->slots[1].rec.unk2c = -1;
  blk->slots[1].rec.unk30 = -1;
  blk->slots[1].rec.unk34 = SLOT_REC_DEFAULT_SCALE;
  blk->slots[1].rec.unk38 = 10;
  blk->slots[1].rec.unk39 = 0;
  blk->slots[1].rec.unk3c = 0;

  blk->slots[1].rec.name[0] = -29;
  blk->slots[1].rec.name[1] = -127;
  blk->slots[1].rec.name[2] = -65;
  blk->slots[1].rec.name[3] = -29;
  blk->slots[1].rec.name[4] = -126;
  blk->slots[1].rec.name[5] = -109;
  blk->slots[1].rec.name[6] = -29;
  blk->slots[1].rec.name[7] = -125;
  blk->slots[1].rec.name[8] = -122;
  blk->slots[1].rec.name[9] = -29;
  blk->slots[1].rec.name[10] = -125;
  blk->slots[1].rec.name[11] = -117;
  blk->slots[1].rec.name[12] = 80;

  blk->slots[2].rec.unk00 = 0;
  blk->slots[2].rec.unk03 = 0;
  blk->slots[2].rec.unk01 = 0;
  blk->slots[2].rec.unk25 = 0;
  blk->slots[2].rec.unk26 = 0;
  blk->slots[2].rec.unk27 = 0;
  blk->slots[2].rec.unk28 = 0;
  blk->slots[2].rec.unk2c = -1;
  blk->slots[2].rec.unk30 = -1;
  blk->slots[2].rec.unk34 = SLOT_REC_DEFAULT_SCALE;
  blk->slots[2].rec.unk38 = 10;
  blk->slots[2].rec.unk39 = 0;
  blk->slots[2].rec.unk3c = 0;

  blk->slots[2].rec.name[0] = -29;
  blk->slots[2].rec.name[1] = -127;
  blk->slots[2].rec.name[2] = -65;
  blk->slots[2].rec.name[3] = -29;
  blk->slots[2].rec.name[4] = -126;
  blk->slots[2].rec.name[5] = -109;
  blk->slots[2].rec.name[6] = -29;
  blk->slots[2].rec.name[7] = -125;
  blk->slots[2].rec.name[8] = -122;
  blk->slots[2].rec.name[9] = -29;
  blk->slots[2].rec.name[10] = -125;
  blk->slots[2].rec.name[11] = -117;
  blk->slots[2].rec.name[12] = 80;

  blk->slots[1].rec.name[0] = 0;
  blk->slots[2].rec.name[0] = 0;

  /* second slot takes two blocks of the setup data */
  SetupData *setup = DAT_003415a8;
  *(Array16 *)blk->slots[1].unk00 = *(Array16 *)setup->unk04;
  *(long long *)blk->slots[1].unk10 = *(long long *)setup->unk18;
}
