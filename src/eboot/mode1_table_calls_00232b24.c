/* HSTMATCH module=EBOOT.BIN start=0x00232b24 end=0x00232c08 symbol=FUN_00232b24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed object struct with the two pointer tables, the goto/shared mode re-read written as two successive mode tests, flag bytes unsigned, and the callee FUN_000edec0 declared with its integer and float parameters interleaved as (obj, rect, f, f, f, int, int, f, f) (this declared order, one of ten of the 126 float placements that schedule like retail, fixes the argument setup order); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_menu.h"

extern void FUN_000edec0(void *, u32 *, float, float, float, int, int, float, float);
extern void FUN_001031e8(void *);
extern int DAT_002f3d08[];

/* Parts that supply the rectangle for the extras / character widgets drawn below. */
#define PART_EXTRA_RECT 65
#define PART_CHAR_RECT 23

/* In mode 1 draws the selected extra widget and the character widget mapped from the selection, then runs the base update. */
void FUN_00232b24(ChallengeMenu *self)
{
  if (self->mode == 1) {
    if (self->unk1d9 != 0) {
      FUN_000edec0(self->extras[self->selected], self->parts[PART_EXTRA_RECT], 0.0f, 0.0f, 1.0f, 0, 0, 1.0f, 1.0f);
    }
  }
  if (self->mode == 1 && self->unk1d8 != 0) {
    FUN_000edec0(self->chars[DAT_002f3d08[self->selected]], self->parts[PART_CHAR_RECT], 0.0f, 0.0f, 1.0f, 0, 0, 1.0f, 1.0f);
  }
  FUN_001031e8(self);
}
