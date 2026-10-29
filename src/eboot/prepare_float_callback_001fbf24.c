/* HSTMATCH module=EBOOT.BIN start=0x001fbf24 end=0x001fbfa8 symbol=FUN_001fbf24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed the callback argument order across the integer and floating register banks and corrected the byte and short accesses; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Descriptor record: only the halfword of flag bits is read. */
typedef struct DescRec {
    char pad00[0xe];
    unsigned short flags;   /* 0x0e */
} DescRec;

typedef struct Callback {
    char pad00[0x70];
    DescRec *desc;          /* 0x70 */
    int handle;             /* 0x74 */
    void *target;           /* 0x78 */
    unsigned char disabled; /* 0x7c */
} Callback;

extern void FUN_000ffb3c(int, int);
extern void FUN_000edec0(float, float, float, void *, DescRec *, int, int,
                         float, float);
extern void FUN_001031e8(void *);

/* Updates the handle from the disabled flag, then (with a target and no low flag bits set) calls
   FUN_000edec0 with unit scales; finishes with FUN_001031e8. */
void FUN_001fbf24(Callback *self)
{
    FUN_000ffb3c(self->handle,
                 ((self->disabled != 0) ^ 1));
    if (self->target != 0 &&
        ((self->desc->flags & 3) == 0)) {
        FUN_000edec0(0.0f, 0.0f, 1.0f,
                     self->target, self->desc, 0, 0,
                     1.0f, 1.0f);
    }
    FUN_001031e8(self);
}
