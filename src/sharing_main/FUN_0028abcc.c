/* HSTMATCH module=hstp_trans_main.prx start=0x0028abcc end=0x0028ac8c symbol=FUN_0028abcc lang=c99 */
/* Clone of src/eboot/FUN_002798e8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pad_buttons.h"
#include "hst/mode_menu.h"

extern u32 DAT_003751d4;
extern void FUN_0001dc34();
extern void FUN_0001de88();

/* Clears the confirm/cancel and left/right button state and some flag bytes. */
void FUN_0028abcc(ModeMenu *self)
{
  FUN_0001dc34(DAT_003751d4,PAD_CIRCLE);
  FUN_0001de88(DAT_003751d4,PAD_CIRCLE,1);
  FUN_0001dc34(DAT_003751d4,PAD_CROSS);
  FUN_0001de88(DAT_003751d4,PAD_CROSS,1);
  self->unk170[6] = 0;
  self->unk170[7] = 0;
  FUN_0001dc34(DAT_003751d4,PAD_RIGHT);
  FUN_0001de88(DAT_003751d4,PAD_RIGHT,1);
  FUN_0001dc34(DAT_003751d4,PAD_LEFT);
  FUN_0001de88(DAT_003751d4,PAD_LEFT,1);
  self->unk17a = 0;
  self->unk17b = 0;
}
