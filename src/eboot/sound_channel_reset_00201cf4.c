/* HSTMATCH module=EBOOT.BIN start=0x00201cf4 end=0x00201dc8 symbol=FUN_00201cf4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: corrected parameter types and orders for FUN_00093484 and FUN_000937f0; readability pass; exact match verified; names and types await human review. */

#include "hst/match_players.h"

extern void FUN_00091c48(Player *, int);
extern void FUN_00093484(Player *, float);
extern void FUN_000937f0(Player *, float, int);
extern void FUN_0012ad54(float, Player *, u32, u8, u8, int, int);

/* Restores each present player's saved values (the counterpart of the setup in FUN_00201a84). */
void FUN_00201cf4(MatchPlayers *self)
{
  Player *player;

  player = self->p1;
  if (player != 0) {
    FUN_0012ad54(-1.0f, player, self->saved20[0], self->saved28[0],
                 self->saved3c[0], 0, 1);
    FUN_00093484(self->p1, self->saved2c[0]);
    FUN_000937f0(self->p1, self->saved34[0], -1);
    FUN_00091c48(player, 0);
  }
  player = self->p2;
  if (player != 0) {
    FUN_0012ad54(-1.0f, player, self->saved20[1], self->saved28[1],
                 self->saved3c[1], 0, 1);
    FUN_00093484(self->p2, self->saved2c[1]);
    FUN_000937f0(self->p2, self->saved34[1], -1);
    FUN_00091c48(player, 0);
  }
}
