/* HSTMATCH module=EBOOT.BIN start=0x001f4c54 end=0x001f4d44 symbol=FUN_001f4c54 lang=c99 rodata=0x002c908c */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/slot_group.h"

extern UiHost *DAT_003386b0;
extern void FUN_001b4e14(void *, int, int, int, int);

/* Queue a pair of host calls (ids 179..186, delays 30 and 90) chosen by the group's mode. */
void FUN_001f4c54(SlotGroup *self)
{
    HostSub *sub = DAT_003386b0->sub;

    switch (self->mode) {
    case 0:
    case 1:
        FUN_001b4e14(sub->widget, 180, 30, 0, 0);
        FUN_001b4e14(sub->widget, 185, 90, 0, 0);
        break;
    case 2:
        FUN_001b4e14(sub->widget, 180, 30, 0, 0);
        FUN_001b4e14(sub->widget, 186, 90, 0, 0);
        break;
    case 3:
    case 4:
    case 5:
        FUN_001b4e14(sub->widget, 179, 30, 0, 0);
        FUN_001b4e14(sub->widget, 184, 90, 0, 0);
        break;
    }
}
