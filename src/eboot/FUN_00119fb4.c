/* HSTMATCH module=EBOOT.BIN start=0x00119fb4 end=0x0011a004 symbol=FUN_00119fb4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Record of the global's block: running total first, the rest not used here. */
typedef struct TallyRec {
  int total;          /* 0x00 */
  char pad04[0x58];
} TallyRec;

typedef struct TallyBlock {
  char pad00[0xb4];
  TallyRec recs[4];   /* 0xb4 */
} TallyBlock;

typedef struct TallyOwner {
  char pad00[0xa0];
  TallyBlock *block;  /* 0xa0 */
} TallyOwner;

/* Source object: four amounts, one per record. */
typedef struct AmountSet {
  char pad00[0xf4];
  int amount[4];      /* 0xf4 */
} AmountSet;

extern TallyOwner *DAT_003386b0;

/* Add each of the four amounts to the matching record total. */
void FUN_00119fb4(AmountSet *self)
{
  TallyBlock *block;

  block = DAT_003386b0->block;
  block->recs[0].total = block->recs[0].total + self->amount[0];
  block->recs[1].total = block->recs[1].total + self->amount[1];
  block->recs[2].total = block->recs[2].total + self->amount[2];
  block->recs[3].total = block->recs[3].total + self->amount[3];
}
