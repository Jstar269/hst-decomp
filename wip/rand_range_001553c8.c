/* HSTMATCH module=EBOOT.BIN start=0x001553c8 end=0x001554d0 symbol=FUN_001553c8 lang=c99 */
extern int FUN_0001342c(char *self, int *param);
extern void FUN_0014d044(int *param);
extern void FUN_0014fd94(char *fmt, int value, int lo, int hi, int id);
extern void *FUN_0014c384(int key, int id);
extern unsigned char DAT_003402f0;
extern char DAT_002dcad8[];
int FUN_001553c8(char *self, int *param)
{
    int key = *param;
    int seed = FUN_0001342c(self, param);
    float lo = (float)*(int *)(self + 0xc);
    float rnd = (float)((((unsigned)(seed * 0x343fd) + 0x269ec3) >> 16) & 0x7fff) * 3.0517578e-05f;
    int value = (int)(lo + ((float)(*(int *)(self + 0x10) + 1) - lo) * rnd);
    if (DAT_003402f0 != 0) {
        FUN_0014d044(param);
        FUN_0014fd94(DAT_002dcad8, value, *(int *)(self + 0xc), *(int *)(self + 0x10),
                     *(int *)(self + 8));
    }
    int *slot = (int *)FUN_0014c384(key, *(int *)(self + 8));
    *slot = value;
    return 0;
}
// NEAR MISS: 67/66 words (1 extra). The whole LCG + float scaling is word-for-word except: retail hoists
// `lwc1 f0,12(s2); cvt.s.w f2,f0` (the (float)lo conversion) into the bltz delay slot and keeps it in f2;
// ours emits `lw a0,12(s2)` + cvt in the fall-through only. Ruled out: int lo/hi locals (register bloat,
// 6 saved regs), inline reads (current).
// near miss from lane ds11 (unreviewed)
// sx2 lane: 1 WORD left (was 13 extra/shifted words). Fix found: hoist the lo conversion into a float local BEFORE rnd (`float lo = (float)*(int *)(self + 0xc);`)
// so retail's `lwc1/cvt.s.w f2` lands in the bltz delay slot; everything else is word-exact.
// Left: the final multiply is `mul.s f0,f1,f0` (rnd, diff) in ours, retail `mul.s f0,f0,f1` (diff, rnd). Ours puts a named-local leaf (rnd) first whatever the source
// order (`diff*rnd`, `rnd*diff`, inline Lerp(a,b,t) in both spellings, const rnd, rnd via inline RandF). Forms that DO give (diff, rnd) (`H * (R)` all inline, a named
// `span` local, Lerp with R as 3rd arg temp evaluated first, RandF(seed) as call operand) all hoist the hi+1 chain above the bltz diamond (31 words off).
// improved by lane sx2 (unreviewed): 54 -> 1 differing words
