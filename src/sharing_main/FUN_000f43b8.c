/* HSTMATCH module=hstp_trans_main.prx start=0x000f43b8 end=0x000f4414 symbol=FUN_000f43b8 lang=c99 */
/* Clone of src/eboot/FUN_000eecf0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/inp_panes.h"
#include "hst/scene.h"

extern Scene *DAT_003e19f0;
extern void FUN_00105470(PaneItem *, int);
extern void FUN_00108a2c(SlotPane *);

/* Per-frame update of the slot pane: its first two items follow a scene byte while the pane is not shown. */
void FUN_000f43b8(SlotPane *pane)
{
  u8 flag;

  if (pane->base.shown == '\0') {
    flag = DAT_003e19f0->unk4c;
    FUN_00105470(pane->item[0],flag);
    FUN_00105470(pane->item[1],flag);
    FUN_00108a2c(pane);
  }
}
