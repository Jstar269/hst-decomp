/* HSTMATCH module=EBOOT.BIN start=0x001bb944 end=0x001bbab8 symbol=FUN_001bb944 lang=c99 */
/* Hand-written reconstruction from the disassembly (matching idioms: static inline bounds-checked SlotAt() that still dereferences its null result, bool flag set in both arms of an && / else, switch on the kind with cases in source order 1,2,3); exact match verified; names and types await human review. */
#include "hst/record_info.h"

typedef unsigned char bool;

enum { SLOT_COUNT = 15 };
/* One slot of a block; only its state byte is read. */
typedef struct Ent { char pad0[4]; unsigned char state; char pad1[0x33]; } Ent;
typedef struct Block { Ent ents[SLOT_COUNT]; } Block;
typedef struct Res { char pad[0x60]; char unk60; } Res;

extern int DAT_00338b08;
extern Res *FUN_000d8c24(int, int, int);
extern RecordInfo *FUN_00193474(int);

static inline unsigned char *SlotAt(Block *b, int idx)
{
  if (idx >= 0 && idx < SLOT_COUNT)
    return &b->ents[idx].state;
  return 0;
}

/* Returns 1 when a live slot's info record has a halfword equal to value; mode selects which halfword(s) are compared. */
int FUN_001bb944(Block *block, int mode, int value)
{
  int i;
  for (i = 0; i < SLOT_COUNT; i++) {
    bool found = 0;
    if (block != 0 && (unsigned)(*SlotAt(block, i) - 4) < 2) {
      found = 1;
    } else {
      if (FUN_000d8c24(DAT_00338b08, 0, i)->unk60 == 1)
        found = 1;
    }
    if (found) {
      RecordInfo *r = FUN_00193474(i);
      if (r != 0) {
        switch (mode) {
        case 1:
          if (r->vals[1] == value) return 1;
          break;
        case 2:
          if (r->vals[2] == value) return 1;
          break;
        case 3:
          if (value != 0 && r->vals[3] == value) return 1;
          if (value != 0 && r->vals[4] == value) return 1;
          break;
        }
      }
    }
  }
  return 0;
}
