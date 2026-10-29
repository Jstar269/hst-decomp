/* HSTMATCH module=EBOOT.BIN start=0x00286d08 end=0x00286db0 symbol=FUN_00286d08 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed struct, merged alloc/ctor pattern, deletion order; readability pass; exact match verified; names and types await human review. */
#include "hst/cmd_actor.h"

extern void *FUN_00000bcc(unsigned int size);
extern void *FUN_0014c794(void *p, int a, int b, int c);
extern void FUN_0014c820(void *p, int flag);

#define PAIR_OBJ_SIZE 36 /* size of each pair object */

/* Deletes the actor's two pair objects and creates fresh empty ones. */
void FUN_00286d08(CmdActor *self)
{
    void *p;

    if (self->objB != 0) {
        FUN_0014c820(self->objB, 1);
        self->objB = 0;
    }
    if (self->objA != 0) {
        FUN_0014c820(self->objA, 1);
        self->objA = 0;
    }

    p = FUN_00000bcc(PAIR_OBJ_SIZE);
    if (p != 0) {
        p = FUN_0014c794(p, 0, 0, 0);
    }
    self->objA = p;

    p = FUN_00000bcc(PAIR_OBJ_SIZE);
    if (p != 0) {
        p = FUN_0014c794(p, 0, 0, 0);
    }
    self->objB = p;
}
