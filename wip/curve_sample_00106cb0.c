/* HSTMATCH module=EBOOT.BIN start=0x00106cb0 end=0x00106da0 symbol=FUN_00106cb0 lang=c99 */
typedef struct {
    short x, y, z, w;
} Entry;

typedef struct {
    int count;
    Entry *entries;
} Curve;

int FUN_00106cb0(char *obj, int idx, float *a, float *b, float *c, float *d)
{
    Curve *curve;

    if (idx < 0 || (*(Curve **)(obj + 0x54))->count < 2) {
        *a = 0.0f;
        *b = 0.0f;
        *c = (float)*(int *)(obj + 8);
        *d = (float)*(int *)(obj + 0xc);
        return 1;
    }
    curve = *(Curve **)(obj + 0x54);
    if (idx + 1 >= curve->count) {
        *a = 0.0f;
        *b = 0.0f;
        *c = (float)*(int *)(obj + 8);
        *d = (float)*(int *)(obj + 0xc);
        return 0;
    }
    *a = (float)curve->entries[idx].x;
    *b = (float)curve->entries[idx].y;
    *c = (float)(curve->entries[idx].z + 1);
    *d = (float)(curve->entries[idx].w + 1);
    return 1;
}
// best: 59/60 words, 52 differ. Retail's `bltz a1` targets the delay slot of the next `beqzl`
// (`li v0,1` in the bltz delay) so one zero-fill body serves idx<0 and count<2; ours merges the
// first body into the branch (bltzl + store in delay). Ruled out: || with a hoisted curve local
// (58 words, bltz+lw delay), two separate if bodies (68 words, no merge), nested spellings.
// near miss from lane fm6 (unreviewed)
