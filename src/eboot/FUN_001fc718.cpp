/* HSTMATCH module=EBOOT.BIN start=0x001fc718 end=0x001fc8bc symbol=FUN_001fc718 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/part_holder.h"

/* Virtual interface of the parts (slot 1 is called after each mode change). */
struct VirtualPart {
    virtual void v0();
    virtual void v1();
};

extern "C" {
extern void *DAT_00338c24;
extern void *DAT_00331b84;
extern void FUN_0006391c(void *p, float f, int n);
extern void FUN_000fbed0(void *p, int n);
extern void FUN_000ffb3c(void *p, int n);
extern int FUN_0015b698();
extern void FUN_0015b6a4(void *h, int a, int b, int c);
}

/* Switch the holder to a new mode and update its widgets accordingly. */
extern "C" void FUN_001fc718(PartHolder *self, int mode)
{
    PartB *part;
    int v;
    int enabled;

    self->mode = mode;
    switch (mode) {
    case HOLDER_MODE_SYNC:
        enabled = self->enabled;
        part = self->partB;
        part->cur = 0;
        if (enabled != 0) {
            FUN_000ffb3c(part->widget64, part->cur == 0);
            FUN_000ffb3c(part->widget70, part->cur == 0);
            FUN_000ffb3c(part->widget68, 1);
            FUN_000ffb3c(part->widget74, 1);
        } else {
            FUN_000ffb3c(part->widget64, 0);
            FUN_000ffb3c(part->widget70, 0);
            FUN_000ffb3c(part->widget68, 0);
            FUN_000ffb3c(part->widget74, 0);
        }
        ((VirtualPart *)self->partB)->v1();
        break;
    case HOLDER_MODE_OFF:
        ((VirtualPart *)self->partC)->v1();
        break;
    case HOLDER_MODE_ON:
        v = FUN_0015b698();
        FUN_0015b6a4(self->partD, v, 0, 1);
        ((VirtualPart *)self->partC)->v1();
        self->timer = 300;
        break;
    case HOLDER_MODE_SHOW:
        FUN_000fbed0(DAT_00338c24, 1);
        break;
    case HOLDER_MODE_HIDE:
        FUN_000fbed0(DAT_00338c24, 0);
        FUN_0006391c(DAT_00331b84, 65535.0f, 15);
        self->timer = 3;
        break;
    }
}
