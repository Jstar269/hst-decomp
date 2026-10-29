/* HSTMATCH module=EBOOT.BIN start=0x000b3c68 end=0x000b3ca0 symbol=FUN_000b3c68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/chara_player.h"

/* One of the character containers (stride 0x18); the first word points at its rows. */
typedef struct CharaContainer {
  int rows;                  /* 0x00 */
  char pad04[0x14];
} CharaContainer;

enum { CHARA_RECORD_SIZE = 0x22c };

extern CharaContainer *DAT_00341508;

/* Address of the player's character record: container `chara_group`, row `chara_index`. */
int FUN_000b3c68(CharaPlayer *self)
{
  return DAT_00341508[self->chara_group].rows +
         self->chara_index * CHARA_RECORD_SIZE;
}
