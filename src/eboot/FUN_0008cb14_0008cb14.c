/* HSTMATCH module=EBOOT.BIN start=0x0008cb14 end=0x0008cb68 symbol=FUN_0008cb14 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: update guard and old-state reload; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/scene_seq.h"

extern u8 DAT_002d26b0;
extern u32 DAT_003386c4;
extern void FUN_00110a78();

/* Same layout as SceneSeq; MWCC only re-reads the field for the old value when it is accessed through a different (identical) struct type. */
struct SeqView { char pad[0x9c0]; int next; };

/* Requests a sequence change unless it is already current (and not forced). */
void FUN_0008cb14(SceneSeq *seq,int next,int force)
{
  int old = seq->next;
  if (old == next && force == 0) {
    return;
  }
  old = ((struct SeqView *)seq)->next;
  seq->prev = old;
  seq->next = next;
  seq->change = 1;
  FUN_00110a78(DAT_003386c4,&DAT_002d26b0,0);
}
