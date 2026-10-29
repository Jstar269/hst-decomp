/* HSTMATCH module=EBOOT.BIN start=0x002afd70 end=0x002afeac symbol=FUN_002afd70 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/slot_array_obj.h"

#define OWNED_SIZE 0x74  /* size of the heap object kept in the last member */

extern void FUN_0001f06c(void *p);
extern void FUN_00102e38(void *p);
extern void FUN_000007f4(void *p, void *ctor, void *dtor, int size, int n);
extern void LAB_002aff04(void);
extern void FUN_002afeac(void);
extern void FUN_002175a4(void *p);
extern void FUN_0001f21c(void *a, void *self);
extern void FUN_002b3a34(void *p, int n);
extern void FUN_002b2e3c(void *self);
extern void *FUN_00000bcc(int n);
extern void *FUN_0021f0f8(void *p);
extern char DAT_00309f98[];
extern char DAT_00309fb4[];

/* Constructor for the object laid out by SlotArrayObj (raw offsets: typed field access changes register allocation):
   base parts, ten slot vectors grown to the reserve size, counters cleared, owned object created. */
char *FUN_002afd70(char *self, void *param_2)
{
    FUN_0001f06c(self);
    FUN_00102e38(self + 0x3c);
    *(void **)self = DAT_00309f98;
    *(void **)(self + 0x3c) = DAT_00309fb4;
    FUN_000007f4(self + 0x98, (void *)LAB_002aff04, (void *)FUN_002afeac, sizeof(SlotVec), SLOT_ARRAY_COUNT);
    FUN_002175a4(self + 0x41c);
    *(char *)(self + 0x168) = 0;
    *(char *)(self + 0x90) = 0;
    *(char *)(self + 0x169) = 0;
    *(char *)(self + 0x38a) = 0;
    *(int *)(self + 0x400) = 0;
    *(int *)(self + 0x40c) = 0;
    *(int *)(self + 0x410) = 0;
    *(char *)(self + 0x414) = 0;
    *(int *)(self + 0x418) = 0;
    *(int *)(self + 0x38c) = 0;
    *(char *)(self + 0x408) = 0;
    *(int *)(self + 0x3f8) = -1;
    FUN_0001f21c(param_2, self);
    int i = 0;
    int slotOff = 0;     /* i * sizeof(SlotVec) */
    int counterOff = 0;  /* i * sizeof(int) */
    do {
        if (*(unsigned int *)(self + slotOff + 0xa0) < SLOT_ARRAY_RESERVE)
            FUN_002b3a34(self + slotOff + 0x98, SLOT_ARRAY_RESERVE);
        *(int *)(self + counterOff + 0x3a8) = 0;
        *(int *)(self + counterOff + 0x3d0) = 0;
        i++;
        slotOff += sizeof(SlotVec);
        counterOff += sizeof(int);
    } while (i < SLOT_ARRAY_COUNT);
    FUN_002b2e3c(self);
    void *p = FUN_00000bcc(OWNED_SIZE);
    if (p != 0)
        *(void **)(self + 0x4a8) = FUN_0021f0f8(p);
    else
        *(void **)(self + 0x4a8) = p;
    return self;
}
