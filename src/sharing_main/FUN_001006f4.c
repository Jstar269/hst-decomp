/* HSTMATCH module=hstp_trans_main.prx start=0x001006f4 end=0x00100728 symbol=FUN_001006f4 lang=c99 */
/* Clone of src/eboot/FUN_000fafb8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/hud_scene.h"

typedef struct GameState {
  char pad[0x3c];
  int mode; /* 0x3c */
} GameState;

extern GameState *DAT_003e19f0;
extern void FUN_000fe984();

void FUN_001006f4(HudScene *self)
{
  if (DAT_003e19f0->mode != 9) {
    FUN_000fe984(self->unk3c);
  }
}
