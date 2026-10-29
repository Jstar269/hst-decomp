/* HSTMATCH module=EBOOT.BIN start=0x00231168 end=0x002311cc symbol=FUN_00231168 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed struct, shared assignment join; readability pass; exact match verified; names and types await human review. */
#include "hst/singleton_holder.h"

#define TARGET_SIZE 0x418 /* size of the object the holder creates */
#define LOCK_MODE 1

extern char DAT_002f3650[];
extern char DAT_0030ebf4[];

extern void *FUN_00000bcc(unsigned int size);
extern void FUN_0001cad0(void *lock, int mode, void *name);
extern void FUN_0001cb88(void *lock);
extern void *FUN_0022cdd0(void *p, unsigned char flag);

/* Create the holder's target (an object built with the holder's flag) while holding the lock. */
void FUN_00231168(SingletonHolder *self)
{
    void *target;

    FUN_0001cad0(&DAT_0030ebf4, LOCK_MODE, DAT_002f3650);
    target = FUN_00000bcc(TARGET_SIZE);
    if (target != 0) {
        target = FUN_0022cdd0(target, self->flag);
    }
    self->target = target;
    FUN_0001cb88(&DAT_0030ebf4);
}
