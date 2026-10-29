/* HSTMATCH module=EBOOT.BIN start=0x002930c8 end=0x00293194 symbol=FUN_002930c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/ctl_obj.h"

typedef struct { float x, y, z, w; } Vec4;
extern int DAT_00331b84;
extern int DAT_00331b88;
void FUN_00063830(float, float, int, Vec4 *, Vec4 *, int, int, int);
void FUN_00063d08(float, float, int, int);

/* Resets the control object with the given start value and mode, then starts the matching call. */
void FUN_002930c8(float start, CtlObj *ctl, int mode)
{
    ctl->unk40 = 0;
    ctl->unk4 = 30.0f;
    ctl->unk8 = 30.0f;
    ctl->level = 0.0f;
    ctl->level = 1.0f;
    ctl->unk4c = 0;
    ctl->active = 0;
    ctl->start = start;
    ctl->unk54 = 0;
    if (mode != 0) {
        ctl->unk8 = 0.0f;
    }
    ctl->mode = mode;
    if (mode != 0) {
        FUN_00063d08(65535.0f, -1.0f, DAT_00331b88, 7);
    } else {
        Vec4 zero4, unit_w;
        unit_w.w = 1.0f;
        unit_w.x = 0.0f;
        unit_w.y = 0.0f;
        unit_w.z = 0.0f;
        zero4.x = 0.0f;
        zero4.y = 0.0f;
        zero4.z = 0.0f;
        zero4.w = 0.0f;
        FUN_00063830(start, -1.0f, DAT_00331b84, &zero4, &unit_w, 15, 0, 0);
    }
}
