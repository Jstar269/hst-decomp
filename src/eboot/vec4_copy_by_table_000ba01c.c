/* HSTMATCH module=EBOOT.BIN start=0x000ba01c end=0x000ba07c symbol=FUN_000ba01c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the 16-byte copy typed as four float fields (interleaved lwc1/swc1), table pointer global typed as a struct pointer with the index scaled first; readability pass; exact match verified; names and types await human review. */
#include "hst/player_slot.h"

extern PlayerTable *DAT_003386b0;
extern Float4 *FUN_00093838(PlayerExt *);

/* Copies the vector looked up for the slot's player into *out. */
void FUN_000ba01c(Float4 *out, SlotRef *ref)
{
  Float4 *src = FUN_00093838(DAT_003386b0->players[ref->slot]->unk5bc);
  out->x = src->x;
  out->y = src->y;
  out->z = src->z;
  out->w = src->w;
}
