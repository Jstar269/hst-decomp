/* HSTMATCH module=EBOOT.BIN start=0x000e7cdc end=0x000e7df0 symbol=FUN_000e7cdc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/seg_ring.h"

/* If an entry is pending, appends (a, b) to the ring and advances head (wrapping) and the total; then re-arms pending from unk24. */
void FUN_000e7cdc(SegRingB *self, Float4 a, Float4 b)
{
    if (self->pending != 0) {
        Float4Seg p;
        p.a = a;
        p.b = b;
        int i = self->head;
        self->head = i + 1;
        Float4Seg *dst = &self->entries[i];
        *dst = p;
        self->head = self->head % self->capacity;
        self->total = self->total + 1;
    }
    self->pending = self->unk24;
}
