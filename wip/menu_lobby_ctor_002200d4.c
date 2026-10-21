/* HSTMATCH module=EBOOT.BIN start=0x002200d4 end=0x002201d4 symbol=FUN_002200d4 lang=c99 */
extern void FUN_00102e38(void *self);
extern void FUN_00104118(void *self, const char *name, int flag);
extern void FUN_00103540(void *self, float value);
extern void FUN_001037c8(void *self, int mode);
extern void *FUN_001039d8(void *self, void *src, int flag);
extern void *FUN_001026b8(void *model, const char *name);
extern void FUN_00220338(void *self);
extern char DAT_003096e4[];
extern char DAT_002f0b14[];
extern char DAT_002f0b54[];
struct Entry_002200d4 { int idx; const char *name; int result; };
extern struct Entry_002200d4 DAT_002f0b28[3];
struct Obj_002200d4 { int pad[9]; int f24; };
void *FUN_002200d4(void *self)
{
    int *p = (int *)self;
    FUN_00102e38(self);
    *(void **)self = &DAT_003096e4;
    p[0x1c] = 0;
    FUN_00104118(self, DAT_002f0b54, 0);
    FUN_00103540(self, 1110.0f);
    FUN_001037c8(self, 18);
    p[0x18] = (int)FUN_001039d8(self, *(void **)DAT_002f0b14, 0);
#pragma opt_strength_reduction off
    int i = 0;
    struct Entry_002200d4 *e = DAT_002f0b28;
    int off = 0;
    do {
        int *h = (int *)FUN_001026b8((void *)p[0x18 + e->idx], e->name);
        *(int *)((int)self + off + 100) = (int)h;
        e->result = h[9];
        i++;
        off += 4;
        e++;
    } while (i < 3);
    p[0x17] = -1;
    *((char *)self + 0x74) = 0;
    FUN_00220338(self);
    return self;
}
// NEAR MISS: 63/64 words - one word short, everything else word-for-word exact.
// Only difference: retail materialises the global at 0x2f0b14 with `lui; addiu v0,0x2f,0xb14; lw a1,0(v0)`,
// ours folds it to `lui v0,0x2f; lw a1,0xb14(v0)`. Ruled out: char[]/void*/volatile void*, local void**,
// int-cast address forms (all fold). Loop needed #pragma opt_strength_reduction off.
// LATER (ds11-00): best is now 64/64 words, 3 differing words, with `extern char **DAT_002f0b14;
// ... *DAT_002f0b14` -- mwcc then emits `lw v0,0xb14(v0); lw a1,0(v0)` (a real double dereference)
// where retail emits `addiu v0,v0,0xb14; lw a1,0(v0)`. Every address-taking spelling folds back to
// `lui; lw a1,0xb14(v0)` (63 words): char[]/void*[]/char*[]/char*const[] array forms, `char *const`
// and `volatile char *` globals, `char **slot = &DAT` local, unsigned-cast address, `*(char**)&DAT`,
// a struct with the pointer as its first member (4-byte and 16-byte), and a C++ reference local.
// So retail's addiu form is NOT reachable from any source spelling tried; open question.
// near miss from lane ds11 (unreviewed)
