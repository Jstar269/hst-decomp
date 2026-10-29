/* HSTMATCH module=EBOOT.BIN start=0x000b2144 end=0x000b21cc symbol=FUN_000b2144 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: shared check and failure labels preserve the mode branches and float-result join; exact match verified; names and types await human review. */
#include "hst/chara_player.h"

typedef struct GameMode {
  char pad00[0x3c];
  int mode;                 /* 0x3c */
} GameMode;

enum { MODE_A = 4, MODE_B = 5, MODE_C = 7 };

extern float DAT_003411e8;
extern GameMode *DAT_003386b0;
extern unsigned char *DAT_00340284;

/* True when the game mode allows it and the player's value at 0x43c reaches 0.7 of the global limit. */
int FUN_000b2144(CharaPlayer *self) {
  int mode = DAT_003386b0->mode;
  if (mode == MODE_A) goto check;
  if (mode == MODE_B) goto check;
  if (mode != MODE_C) goto fail;
  if (*(unsigned char *)(*(int *)(DAT_00340284 + 0x80) + 0x78) != 0) goto fail;
check:
  {
    float limit = DAT_003411e8 * 0.7f;
    float value = self->unk43c;
    if (!(value >= limit)) goto fail;
  }
  return 1;
fail:
  return 0;
}
