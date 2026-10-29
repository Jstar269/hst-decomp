/* HSTMATCH module=EBOOT.BIN start=0x000c801c end=0x000c80e0 symbol=FUN_000c801c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/effect_scene.h"

extern void *FUN_00000bcc(int size);
extern void *FUN_000ce954(void *p);
extern void *FUN_000cede4(void *p, void *a);
extern void *FUN_000d0cfc(void *p);
extern void *FUN_000ebdfc(void *p);

/* Create the first members of the effect scene (members 3c, 40, 48 and 4c) if they do not exist yet. */
int FUN_000c801c(EffectScene *s)
{
    void *p;

    if (s->member3c == 0) {
        p = FUN_00000bcc(1360);
        if (p != 0)
            p = FUN_000ce954(p);
        s->member3c = p;
    }
    if (s->member40 == 0) {
        p = FUN_00000bcc(192);
        if (p != 0)
            p = FUN_000cede4(p, s->unk5c);
        s->member40 = p;
    }
    if (s->member48 == 0) {
        p = FUN_00000bcc(464);
        if (p != 0)
            p = FUN_000d0cfc(p);
        s->member48 = p;
    }
    if (s->member4c == 0) {
        p = FUN_00000bcc(116);
        if (p != 0)
            p = FUN_000ebdfc(p);
        s->member4c = p;
    }
    return 1;
}
