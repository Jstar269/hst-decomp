/* HSTMATCH module=EBOOT.BIN start=0x000ba23c end=0x000ba2a8 symbol=FUN_000ba23c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: modeled the 64-byte matrix temporary and copied its fourth row field by field; readability pass; exact match verified; names and types await human review. */
#include "hst/player_slot.h"

extern PlayerTable *DAT_003386b0;
extern void FUN_0005548c(Mat4 *, int, void *);

/* Copies the translation row of the matrix built for the slot's player into *out. */
void FUN_000ba23c(Float4 *out, SlotRef *ref)
{
    Mat4 matrix;
    PlayerExt *ext = DAT_003386b0->players[ref->slot]->unk5bc;
    FUN_0005548c(&matrix, ext->unk58, ref->unk1c);
    out->x = matrix.row[3].x;
    out->y = matrix.row[3].y;
    out->z = matrix.row[3].z;
    out->w = matrix.row[3].w;
}
