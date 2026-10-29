/* HSTMATCH module=EBOOT.BIN start=0x00057c60 end=0x00057d6c symbol=FUN_00057c60 lang=c++ */
/* NEAR MISS: 65/67 words, 63 differ.  Checks the entries of the range [start_idx, end_idx] of the
   object: an entry with the flag at +0x114 set is compared (entry float at +0x108 against the
   entry float at +0x118 plus the float the pointer at +0xf4 points at) and the function returns 1
   on the first match; with a non-negative index only that one entry is checked.
   MATCHED: the entry layout (52-byte stride, the record fields at +0x04/+0x18/+0x24/+0x28), the
   0x114 flag test, the float taken through the pointer at +0xf4 and the compare.
   DIFFERENCE: retail keeps the two paths (the loop over the range and the single entry) as two
   separate blocks, while MWCC merges the two identical bodies of this spelling into one loop; the
   record pointer also stays in two registers (a1 for the +0x04/+0x18 fields, a2 for the +0x24
   field and for the +0x118 field, which retail reaches through an extra +0xf0 offset).
   RULED OUT: `f18 >= f28 + extra` vs the mirrored compare (retail uses c.nge.s, i.e. the +0x108
   value on the left), the record fields at other offsets, and a single merged body. */
typedef struct {
    int f00;
    int *f04;
    char pad[0x10];
    float f18;
    char pad2[8];
    int f24;
    float f28;
    char pad3[8];
} Rec;

typedef struct {
    char pad[0xf0];
    Rec recs[2];
    int start_idx;
    int end_idx;
} Self;

extern "C" int FUN_00057c60(Self *self, int idx)
{
    if (idx < 0) {
        int i = self->start_idx;
        if (self->end_idx < i) {
            return 0;
        }
        do {
            float extra = 0.0f;
            if (self->recs[i].f24 != 0) {
                if (self->recs[i].f04 != 0) {
                    extra = *(float *)(*self->recs[i].f04 + 8);
                }
                if (self->recs[i].f18 >= self->recs[i].f28 + extra) {
                    return 1;
                }
            }
            i++;
        } while (i <= self->end_idx);
        return 0;
    }
    float extra = 0.0f;
    if (self->recs[idx].f24 != 0) {
        if (self->recs[idx].f04 != 0) {
            extra = *(float *)(*self->recs[idx].f04 + 8);
        }
        if (self->recs[idx].f18 >= self->recs[idx].f28 + extra) {
            return 1;
        }
    }
    return 0;
}
// NEAR 64/67 words (sy3). Per-field `self->recs[i].fXX` accesses (no rec pointer) plus the separate loop and single-index blocks get closest.
// Still differs: retail keeps TWO induction pointers in the loop (a2 = self+52*i for the +0xf0/+0x114 reads and `addiu v1,a2,240` for the f28 read,
// a1 = a copy bumped in the likely-branch slot for +0xf4/+0x108) and an extra `move a1,a2`; an inline Hit() helper adds a result move (70/67);
// a `Rec *rec = &self->recs[i]` for f28 only gives 66/67 with 63 differing.
// near miss from lane sy3 (unreviewed)
