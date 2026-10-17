/* HSTMATCH module=EBOOT.BIN start=0x0021dd14 end=0x0021de38 symbol=FUN_0021dd14 lang=c99 */
/* WIP Near-miss: 73/73 words; 30 differ.
 * The function prologue and initialization (0x21dd14 - 0x21dd54) and the final float computation
 * and method call (0x21dde4 - 0x21de34) match retail 100%.
 * The 30 differing words are in the two table lookups into DAT_0034b5d4:
 * Retail hoists DAT_0034b5d4 into the delay slot of bltz in the first lookup, and hoists it before
 * the branch in the second lookup, causing subtle branch-likely (bltzl/beqzl vs bltz/beqz) divergences.
 */

extern int *DAT_0034b5d4;

extern int FUN_002af920(int arg);
extern void FUN_002afa48(int *pIdx, void *zero, int val);
extern void FUN_0021df6c(void *self, int idx);
extern void FUN_0021e090(void *self, float pct);

struct Obj_0021dd14 {
    char pad[0x170];
    int f170;
    char pad2[0x1f0 - 0x174];
    int f1F0;
    int f1F4;
    int f1F8;
    int f1FC;
    int f200;
};

void FUN_0021dd14(struct Obj_0021dd14 *self)
{
    float fVar2;
    int idx;

    self->f1F8 = FUN_002af920(self->f170);
    self->f200 = self->f1F8;
    self->f1FC = self->f1F8;
    FUN_002afa48(&idx, 0, self->f1F8);
    FUN_0021df6c(self, idx);

    if (idx < 0) {
        fVar2 = 0.0f;
    } else if (idx < 0x1e) {
        fVar2 = (float)(*(int *)((int)DAT_0034b5d4 + idx * 8) >> 4);
    } else {
        fVar2 = 0.0f;
    }
    self->f1F0 = (int)fVar2;

    idx = idx + 1;
    if (idx < 0) {
        fVar2 = 0.0f;
    } else if (idx < 0x1e) {
        fVar2 = (float)(*(int *)((int)DAT_0034b5d4 + idx * 8) >> 4);
    } else {
        fVar2 = 0.0f;
    }
    self->f1F4 = (int)fVar2;

    FUN_0021e090(self, (float)(self->f200 - self->f1F0) * 100.0f / (float)((int)fVar2 - self->f1F0));
}
// near miss from lane u5fr4-0 (unreviewed)
