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
    float rnd = (float)((((unsigned)(seed * 0x343fd) + 0x269ec3) >> 16) & 0x7fff) * 3.0517578e-05f;
    int value = (int)((float)*(int *)(self + 0xc) +
                      ((float)(*(int *)(self + 0x10) + 1) - (float)*(int *)(self + 0xc)) * rnd);
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
