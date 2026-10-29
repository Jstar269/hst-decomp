/* HSTMATCH module=EBOOT.BIN start=0x000b2f0c end=0x000b2fc0 symbol=FUN_000b2f0c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the else arm assigns the default explicitly (id = chara_id) instead of leaving it unassigned, which gives retail's bnez/b-join layout; started from the lane fm3 near miss. */
#include "hst/chara_player.h"

extern unsigned char *DAT_00338b08;

extern int DAT_0034a7e8;
extern char DAT_0034180e[];
extern int FUN_000d8c24(unsigned char *, int, int);

/* Address of the 0x68-byte table record for the player's character (or the slot's own id when the kind is non-zero). */
int FUN_000b2f0c(CharaPlayer *self)
{
  short *chara = self->chara;
  int chara_id = *chara;
  int rec = FUN_000d8c24(DAT_00338b08, 0, chara_id);
  int kind = ((int)(*(signed char *)(rec + 0x62) << 0x1c)) >> 0x1c;
  int *tbl = (int *)(DAT_0034a7e8 + (kind != 0) * 0xc);
  int id;
  if (kind == 0) {
    id = chara_id;
  } else {
    id = *(short *)(DAT_0034180e + self->slot * 0x120);
  }
  return *tbl + id * 0x68;
}
