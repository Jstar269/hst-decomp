/* HSTMATCH module=EBOOT.BIN start=0x000f4068 end=0x000f4100 symbol=FUN_000f4068 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declaration order reversed (iVar6 first), pointer inits in reverse order, uVar2 loaded before iVar1 in the last two blocks; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/inp_panes.h"

/* Two slots: reset the per-slot colour words and copy values into their paired items. */
void FUN_000f4068(int self)
{
  int i;
  int cur4;
  int cur8;
  int cur16;
  int value;
  PaneItem *item;

  i = 0;
  cur4 = self;
  cur8 = self;
  cur16 = self;
  do {
    i = i + 1;
    **(u32 **)(cur4 + 0x140) = 0x33000000;
    **(u32 **)(cur4 + 0x148) = 0x33000000;
    value = *(int *)(cur8 + 0x1e0);
    item = *(PaneItem **)(cur16 + 0x128);
    cur4 = cur4 + 4;
    item->unk24 = value;
    item->unk28 = value;
    value = *(int *)(cur8 + 0x1e4);
    item = *(PaneItem **)(cur16 + 0x12c);
    cur8 = cur8 + 8;
    item->unk24 = value;
    item->unk28 = value;
    value = (*(PaneItem **)(cur16 + 0x128))->unk24;
    item = *(PaneItem **)(cur16 + 0x120);
    item->unk24 = value;
    item->unk28 = value;
    value = (*(PaneItem **)(cur16 + 0x12c))->unk24;
    item = *(PaneItem **)(cur16 + 0x124);
    cur16 = cur16 + 0x10;
    item->unk24 = value;
    item->unk28 = value;
  } while (i < 2);
  *(u32 *)(self + 0x1c4) = 0x14;
  *(u32 *)(self + 0x1c8) = 0x3f800000; /* 1.0f */
}
