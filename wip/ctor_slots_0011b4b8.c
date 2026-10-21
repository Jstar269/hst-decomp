/* HSTMATCH module=EBOOT.BIN start=0x0011b4b8 end=0x0011b5c4 symbol=FUN_0011b4b8 lang=c99 */
extern void FUN_000143b0(void *dst, const char *a, const char *b, int c);
extern void *FUN_00000bcc(unsigned size);
extern void *FUN_00102e38(void *self);
extern void FUN_00104118(void *self, const void *src, int flag);
extern void FUN_00103540(void *self, float value);
extern void FUN_001037c8(void *self, int mode);
extern void *FUN_001039d8(void *self, void *src, int flag);
extern void *FUN_001026b8(void *model, const char *name);
extern char DAT_002d9c5c[];
extern char DAT_002c1308[];
extern int DAT_002da0f4;
extern void *DAT_002da0b8;
struct Entry_0011b4b8 { int idx; const char *name; int result; };
extern struct Entry_0011b4b8 DAT_002da0cc[2];

void *FUN_0011b4b8(void **self)
{
    char buf[256];
    FUN_000143b0(buf, DAT_002d9c5c, DAT_002c1308, DAT_002da0f4);
    *self = FUN_00000bcc(0x54);
    if (*self != 0)
        FUN_00104118(*self = FUN_00102e38(*self), buf, 0);
    FUN_00103540(*self, 3099.0f);
    FUN_001037c8(*self, -4096);
    self[1] = FUN_001039d8(*self, DAT_002da0b8, 0);
    int i = 0;
    struct Entry_0011b4b8 *e = DAT_002da0cc;
    int off = 0;
    do {
        int *h = (int *)FUN_001026b8(*(void **)((char *)self + (e->idx << 2) + 4), e->name);
        *(void **)((char *)self + off + 8) = h;
        e->result = h[9];
        i++;
        off += 4;
        e++;
    } while (i < 2);
    return self;
}
// NEAR MISS first pass: 66/67 words, 44 differ. The whole constructor body (256-byte temp built by
// FUN_000143b0, allocation, conditional base ctor returning `this`, 3099.0f, -4096, the 2-entry
// 12-byte table walk with per-entry FUN_001026b8 -> self->[8+4i] and e->result) is instruction-for-
// instruction retail except ONE word: the `DAT_002da0b8` pointer load. Retail materialises the
// address (`lui v0; addiu v0,0x...; lw a1,0(v0)`) while every spelling folds to `lui; lw a1,lo(v0)`:
// `char[]`, `char`, `int`, `void *`, `void *volatile`, `*(void **)&DAT`, `DAT` — 5 more spellings on
// top of the ~45 already ruled out for 0x002200d4. It also evaluates that load before `lw a0,0(s3)`
// where we load a0 first (argument order). Prologue save order (s2,s1,s0 then lw v0/a1/a2) differs.
// near miss from lane ds11 (unreviewed)
