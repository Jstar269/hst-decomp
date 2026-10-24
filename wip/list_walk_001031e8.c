/* HSTMATCH module=EBOOT.BIN start=0x001031e8 end=0x001033e8 symbol=FUN_001031e8 lang=c99 */
// NEAR 124: draft only, 68 of 128 words. Retail builds a 16-byte value (three floats from
// DAT_002d8bd0/d4/d8 or DAT_002d8bdc/e0/e4 plus the byte at self+0x24), copies it through
// several stack slots and passes it BY VALUE to FUN_0000100c, which receives its address
// in t9 (addiu t9,sp,56) - the invisible-reference ABI for a by-value struct. The two
// loops walk the container at self+0x10 (count at +0x14) forwards when self+0x24 == 0 and
// backwards otherwise. Our build elides the struct copies entirely, so the 144-byte frame
// and the ~40 copy words are missing. Next step: reproduce the copies (probably a second
// local assigned from the first, or a by-value struct argument modelled on
// src/eboot files that pass a struct to a callee taking t9).


typedef struct {
    float x;
    float y;
    float z;
    unsigned char w;
} Val_1031e8;

extern float DAT_002d8bd0;
extern float DAT_002d8bd4;
extern float DAT_002d8bd8;
extern float DAT_002d8bdc;
extern float DAT_002d8be0;
extern float DAT_002d8be4;
extern void FUN_001033e8(char *self, unsigned char flag, float v);
extern void FUN_00103474(char *self);
extern void FUN_0000100c(int elem, unsigned char flag, Val_1031e8 v);

void FUN_001031e8(char *self)
{
    Val_1031e8 v;
    Val_1031e8 *begin;
    Val_1031e8 *end;
    Val_1031e8 *p;

    FUN_001033e8(self, *(unsigned char *)(self + 0x50), *(float *)(self + 0x4c));
    if (*(unsigned char *)(self + 0x24) == 0) {
        v.x = DAT_002d8bd0;
        v.y = DAT_002d8bd4;
        v.z = DAT_002d8bd8;
        v.w = *(unsigned char *)(self + 0x24);
        begin = *(Val_1031e8 **)(self + 0x10);
        end = (Val_1031e8 *)((char *)begin + *(int *)(self + 0x14) * 4);
        for (p = begin; p != end; p = (Val_1031e8 *)((char *)p + 4))
            FUN_0000100c(*(int *)((char *)p + 0), v.w, v);
    } else {
        v.x = DAT_002d8bdc;
        v.y = DAT_002d8be0;
        v.z = DAT_002d8be4;
        v.w = *(unsigned char *)(self + 0x24);
        begin = *(Val_1031e8 **)(self + 0x10);
        end = (Val_1031e8 *)((char *)begin + *(int *)(self + 0x14) * 4);
        for (p = end; p != begin; p = (Val_1031e8 *)((char *)p - 4))
            FUN_0000100c(*(int *)((char *)p - 4), v.w, v);
    }
    FUN_00103474(self);
}
// near miss from lane fm7 (unreviewed)
