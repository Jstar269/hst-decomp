/* HSTMATCH module=EBOOT.BIN start=0x000f3948 end=0x000f397c symbol=FUN_000f3948 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Referenced object: only the word at +0x24 is read. */
typedef struct Part {
  char pad0[0x24];
  u32 unk24; /* 0x24 */
} Part;

typedef struct PartOwner {
  char pad0[0x128];
  Part *part128;     /* 0x128 */
  Part *part12c;     /* 0x12c */
  char pad130[8];
  Part *part138;     /* 0x138 */
  Part *part13c;     /* 0x13c */
  char pad140[0x1e0 - 0x140];
  u32 copy[4];       /* 0x1e0 receives the +0x24 word of each part */
} PartOwner;

void FUN_000f3948(PartOwner *self)
{
  self->copy[0] = self->part128->unk24;
  self->copy[1] = self->part12c->unk24;
  self->copy[2] = self->part138->unk24;
  self->copy[3] = self->part13c->unk24;
}
