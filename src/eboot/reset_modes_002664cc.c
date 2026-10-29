/* HSTMATCH module=EBOOT.BIN start=0x002664cc end=0x002665dc symbol=FUN_002664cc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/mover.h"

extern void FUN_00057b58(void *p, int a1, int a2, float f);
extern void FUN_00058ddc(void *p, int a1, int a2);
extern void FUN_00058f38(void *p, int a1, float f);
extern void FUN_0005f110(void *p, float f);
extern void FUN_00059084(void *p, int a1);

static inline void ModeA_002664cc(MoverBody *body, int x)
{
    FUN_00057b58(body, 0, x, 0.0f);
}

static inline void ModeB_002664cc(MoverBody *body, int y)
{
    FUN_00058ddc(body, y, -1);
    body->unkc0 = y;
}

static inline void ModeC_002664cc(MoverBody *body)
{
    FUN_00058f38(body, -1, 0.0f);
    FUN_0005f110(body, 0.0f);
}

static inline void ModeD_002664cc(MoverBody *body)
{
    FUN_00059084(body, -1);
    body->unkd0 = body->unkc4;
}

/* Resets all four modes of the body, and of the second body when there is one. */
void FUN_002664cc(Mover *self, int x, int y)
{
    ModeA_002664cc(self->body, x);
    ModeB_002664cc(self->body, y);
    ModeC_002664cc(self->body);
    ModeD_002664cc(self->body);
    if (self->body2 == 0)
        return;
    ModeA_002664cc(self->body2, x);
    ModeB_002664cc(self->body2, y);
    ModeC_002664cc(self->body2);
    ModeD_002664cc(self->body2);
}
