/* HSTMATCH module=EBOOT.BIN start=0x001ba8a8 end=0x001ba9b4 symbol=FUN_001ba8a8 lang=c99 */
extern char *FUN_001feec4(char *self);
extern unsigned char FUN_001baf80(void *model);
extern void FUN_00205df4(void *slot, unsigned char mode, int *rect, unsigned char a, unsigned char b,
                         unsigned char c, int flag);
void FUN_001ba8a8(char *self, int idx, char **table)
{
    if (*(unsigned char *)(*table + idx * 0x30) != 0) {
    char *e = FUN_001feec4(self);
    int rect[6] = {0};
    rect[0] = *(short *)(e + 0x40);
    rect[1] = *(short *)(e + 0x42);
    rect[2] = *(short *)(e + 0x44);
    rect[3] = *(short *)(e + 0x46);
    rect[4] = *(short *)(e + 0x48);
    rect[5] = *(short *)(e + 0x4a);
    unsigned char mode = FUN_001baf80(*(void **)(*(int *)(*(int *)(self + 4) + idx * 4) + 4));
    FUN_00205df4(*(void **)(*(int *)(self + 4) + idx * 4), mode, rect, *(unsigned char *)(e + 0xde),
                 *(unsigned char *)(e + 0xdc), *(unsigned char *)(e + 0xdd),
                 *(unsigned char *)(e + 0xa6) == 2);
    self[idx + 0x10] = 1;
    self[idx + 0x14] = 1;
    }
}
// NEAR MISS: 66/67 words, 60 differ (one-word shift from the prologue). Only real differences: retail copies
// both params (s3,s2) before the guard and uses `beqzl ...; lw ra` for the early return; ours defers the
// `move s3,a0` into the branch delay slot. Declared-form, inverted-if and split-load variants identical.
// Twin 0x001ba9b4 has the same shape (parked with this one).
// near miss from lane ds11 (unreviewed)
