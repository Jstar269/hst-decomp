/* HSTMATCH module=EBOOT.BIN start=0x000f1ad4 end=0x000f1b38 symbol=FUN_000f1ad4 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Exact match verified 2026-10-21 (rt2). Two source details are load-bearing: compute `cur` BEFORE loading
   `prev` (p[2]) so the truncation takes a0 and prev takes v1, and update the neighbour as `p[4] += diff;`
   (compound assignment) so the difference is sign-extended before p[4] is reloaded. */
extern float DAT_002d7800;

void FUN_000f1ad4(void *self, int idx, float v)
{
    int off = idx * 4;
    char *e = (char *)(off + (int)self);
    float *slot;
    short *p;
    short cur;
    short prev;
    short diff;
    slot = (float *)(e + 0x84);
    *slot = v * DAT_002d7800;
    if (idx >= 2)
        return;
    p = *(short **)(e + 0x58);
    cur = (short)(*(float *)((char *)self + 0x70) + *slot);
    prev = p[2];
    p[2] = cur;
    diff = cur - prev;
    p[4] += diff;
}
// 25/25 words, 8 differ: only the colouring/order of the two conversion temps. Retail puts the
// truncated `cur` in a0 (mfc1 a0 / sh a0,4(a1) / seh a0,a0 / subu v1,a0,v1 / seh a0,v1) with `prev`
// loaded into v1 and p[4] into v1; ours takes a0 for prev and v1 for cur. Declaration order of
// prev/cur/diff (all 3 orders) and the `(short)` spellings all give the same allocation.
// near miss from lane ds3 (unreviewed)
