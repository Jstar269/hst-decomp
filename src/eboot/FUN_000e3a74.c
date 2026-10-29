/* HSTMATCH module=EBOOT.BIN start=0x000e3a74 end=0x000e3b24 symbol=FUN_000e3a74 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rec_array_obj.h"

extern void *FUN_00000a90(int);
extern void *FUN_000008d8(void *, void *, int, int, int);
extern void *FUN_00000bcc(int);
extern void *FUN_0005abf4(void *, int, int, int, int, int);
extern void FUN_000e3b24();

/* Allocate the record array (one record per info entry) and the owned sub-object. */
void FUN_000e3a74(RecArrayObj *self)
{
    int count;
    void *buf;
    void *obj;

    self->unk44 = 6;
    count = self->info->count;
    buf = FUN_00000a90(count * REC_ARRAY_REC_SIZE + 0x10);
    self->recs = FUN_000008d8(buf, (void *)&FUN_000e3b24, 0, REC_ARRAY_REC_SIZE, count);
    obj = FUN_00000bcc(0x70);
    if (obj != 0)
        obj = FUN_0005abf4(obj, 1, self->info->count * self->unk44, 1, 1, 0);
    self->unk40 = obj;
}
