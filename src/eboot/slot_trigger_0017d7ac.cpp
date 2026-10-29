/* HSTMATCH module=EBOOT.BIN start=0x0017d7ac end=0x0017d880 symbol=FUN_0017d7ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/slot_mgr.h"

/* Virtual interface of the entry's sub-object (slot 1 starts it). */
struct VC { virtual void s0(); virtual void s1(); };
extern "C" {
int FUN_001fe984(void *, int, int);
void FUN_000931ec(void *, int, unsigned char *, int);
float FUN_0017dab8(SlotMgr *, int);
void FUN_00093484(float, void *);
}
/* Start slot `idx` unless the lookup rejects it: set its two bytes, apply the scaled value, then trigger it. */
extern "C" void FUN_0017d7ac(SlotMgr *self, int idx, unsigned char c1, unsigned char c2, int extra)
{
    if (FUN_001fe984(self->sub2e4, idx, 0) == 0) {
        unsigned char arr[2] = { c1, c2 };
        SlotEntry *s = self->entries[idx];
        FUN_000931ec(s->sub, 1, arr, extra);
        FUN_00093484(FUN_0017dab8(self, idx), s->sub);
        ((VC *)s->sub)->s1();
    }
}
