/* HSTMATCH module=EBOOT.BIN start=0x000db7f4 end=0x000db868 symbol=FUN_000db7f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: the two odd-address globals typed as bytes; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

extern u8 DAT_0034189b; /* points each side starts a game with */
extern u8 DAT_003419bb;
extern u32 * FUN_000114c0();

/* Reset the running score (sets, games, points) and the server state. */
void FUN_000db7f4(RuleObj *self)
{
  FUN_000114c0((u32 *)self->resultGame,0,0x30);
  self->points[0] = (u32)DAT_0034189b;
  self->games[0] = 0;
  self->sets[0] = 0;
  self->points[1] = (u32)DAT_003419bb;
  self->games[1] = 0;
  self->sets[1] = 0;
  self->unk48 = 1;
  self->dir = 1;
  self->base = 0;
  self->server = 0;
  self->unk58 = 1;
  self->unk108 = 0;
}
