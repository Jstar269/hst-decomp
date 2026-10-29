/* HSTMATCH module=EBOOT.BIN start=0x0024df94 end=0x0024e064 symbol=FUN_0024df94 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reordered nested-loop counters and isolated the final record cursor; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Slot grid dimensions: two sides, 16 rows, 6 slots per row. */
#define SLOT_SIDES 2
#define SLOT_ROWS 0x10
#define SLOT_COLUMNS 6

/* Record of seven words that is cleared at start-up. */
typedef struct SlotRecord {
  u32 unk00;
  u32 unk04;
  u32 unk08;
  u32 unk0c;
  u32 unk10;
  u32 unk14;
  u32 unk18;
} SlotRecord;

typedef struct SlotGrid {
  char pad00[0xc0];
  u32 unkc0;              /* 0xc0 */
  u32 unkc4;              /* 0xc4 */
  SlotRecord records[2];  /* 0xc8 */
} SlotGrid;

extern void FUN_0024e1f8();

/* Reset every slot of the grid (first side flagged) and clear the two trailing records. */
SlotGrid * FUN_0024df94(SlotGrid *self)
{
  int side;
  int row;
  int slot;
  
  side = 0;
  do {
    row = 0;
    do {
      slot = 0;
      do {
        FUN_0024e1f8(self,side == 0,row,slot,0xffffffff);
        slot = slot + 1;
      } while (slot < SLOT_COLUMNS);
      row = row + 1;
    } while (row < SLOT_ROWS);
    side = side + 1;
  } while (side < SLOT_SIDES);
  self->unkc0 = 0;
  self->unkc4 = 0;
  {
    int off = 0;
    SlotGrid *rec = self; /* advances one record per pass, the records sit at a fixed offset inside it */
    do {
      rec->records[0].unk00 = 0;
      rec->records[0].unk04 = 0;
      rec->records[0].unk08 = 0;
      rec->records[0].unk0c = 0;
      rec->records[0].unk10 = 0;
      rec->records[0].unk14 = 0;
      off = off + 7;
      rec->records[0].unk18 = 0;
      rec = (SlotGrid *)((char *)rec + sizeof(SlotRecord));
    } while (off < 0xe);
  }
  return self;
}
