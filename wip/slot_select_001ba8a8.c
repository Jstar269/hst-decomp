/* HSTMATCH module=EBOOT.BIN start=0x001ba8a8 end=0x001ba9b4 symbol=FUN_001ba8a8 lang=c99 */
extern char *FUN_001feec4(char *self);
extern unsigned char FUN_001baf80(void *model);
extern void FUN_00205df4(void *slot, unsigned char mode, int *rect, unsigned char a, unsigned char b,
                         unsigned char c, int flag);
void FUN_001ba8a8(char *self, int idx, char **table)
{
    if (*(unsigned char *)(*table + idx * 0x30) != 0) {
    char *e = FUN_001feec4(self);
    short r0 = *(short *)(e + 0x40);
    int rect[6] = { r0, *(short *)(e + 0x42), *(short *)(e + 0x44),
                    *(short *)(e + 0x46), *(short *)(e + 0x48), *(short *)(e + 0x4a) };
    unsigned char mode = FUN_001baf80(*(void **)(*(int *)(*(int *)(self + 4) + idx * 4) + 4));
    FUN_00205df4(*(void **)(*(int *)(self + 4) + idx * 4), mode, rect, *(unsigned char *)(e + 0xde),
                 *(unsigned char *)(e + 0xdc), *(unsigned char *)(e + 0xdd),
                 *(unsigned char *)(e + 0xa6) == 2);
    self[idx + 0x10] = 1;
    self[idx + 0x14] = 1;
    }
}
// sy4 NEAR MISS (67/67 words, 22 differ). `short r0 = *(short *)(e + 0x40);` declared before `int rect[6] = { r0, ... }` hoists the first element's lh above the
// zero-fill loop exactly like retail (lh a0,64(v0) in the jal's slot region), but adds a `seh v0,a0` (retail stores the lh result unextended). Remaining:
// (1) that seh; (2) retail copies BOTH params (move s3,a0; move s2,a1) before the guard and uses a0 as the index*0x30 temp, with `beqzl v1,epilogue; lw ra` (likely branch);
// ours defers `move s3,a0` into the plain beqz slot and uses a1 as temp. Ruled out: struct-typed entry (ItemEntry with s16 v[6]), early return, local copies of self/idx,
// int r0 (no hoist), volatile r0, {0} then assigns.
// improved by lane sy4 (unreviewed): 60 -> 22 differing words
