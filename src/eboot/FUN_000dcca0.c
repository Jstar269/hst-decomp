/* HSTMATCH module=EBOOT.BIN start=0x000dcca0 end=0x000dcd64 symbol=FUN_000dcca0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the merged else-branch split back into two independent member tests; readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

/* Per-side tally block reached through the global's +0xa0 pointer. */
typedef struct SideTally {
  char pad00[0x1ec];
  int unk1ec;       /* 0x1ec, bumped when mode is 1 */
  char pad1f0[0x208 - 0x1f0];
  int unk208;       /* 0x208, bumped when mode is 2 */
} SideTally;

typedef struct TallyOwner {
  char pad00[0xa0];
  SideTally *tally; /* 0xa0 */
} TallyOwner;

extern TallyOwner *DAT_003386b0;
extern int FUN_0008882c();

/* Add delta to the mode word at +0x8c (before the tally update when positive, after it when negative). */
void FUN_000dcca0(RuleObj *self,int key,int delta)
{
  int other;

  if (0 < delta) {
    self->unk8c = self->unk8c + delta;
  }
  other = FUN_0008882c(DAT_003386b0);
  if (key == *(int *)(other + 0x148)) {
    if (self->unk8c == 1) {
      DAT_003386b0->tally->unk1ec = DAT_003386b0->tally->unk1ec + delta;
    }
    if (self->unk8c == 2) {
      DAT_003386b0->tally->unk208 = DAT_003386b0->tally->unk208 + delta;
    }
  }
  if (delta < 0) {
    self->unk8c = self->unk8c + delta;
  }
}
