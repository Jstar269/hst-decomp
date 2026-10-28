/* HSTMATCH module=EBOOT.BIN start=0x00068e54 end=0x00068f94 symbol=FUN_00068e54 lang=c++ */
struct Elem {
    char pad00[0xc0];
    char f_c0;          /* 192 */
    char pad_c1[3];
    float f_c4;         /* 196 */
    char pad_c8[8];
    float f_d0;         /* 208 */
    char pad_d4[432 - 0xd4];
};

struct Cont {
    char pad0[4];
    char head[4];       /* +4  sentinel node (compared by address) */
    char pad8[4];
    Elem *begin;        /* +0x0c */
    int count;          /* +0x10 */
    Elem *array;        /* +0x14 */
};

struct Vec2 { float x, y; };

extern "C" Cont *DAT_00331c28;
extern "C" void FUN_0005743c(Elem *e, int a, int b, int c);
extern "C" void FUN_00057b58(Elem *e, int a, int b, float f);
extern "C" void FUN_00058ddc(Elem *e, int a, int b);
extern "C" void FUN_00058ec4(Elem *e, int a, float f);
extern "C" void FUN_00059084(Elem *e, int a);
extern "C" void FUN_000643e8(Elem **it);

extern "C" void FUN_00068e54(void)
{
    Vec2 A;

    A.x = 0.0f;
    A.y = 0.0f;

    Elem *it = DAT_00331c28->begin;
    if (it == (Elem *)DAT_00331c28->head)
        return;

    for (; it != (Elem *)DAT_00331c28->head; FUN_000643e8(&it)) {
        Vec2 B = A;
        int bx = *(int *)&B.x;
        int by = *(int *)&B.y;
        Elem *p = DAT_00331c28->array;
        Elem *last = p + DAT_00331c28->count;

        while (p != last) {
            void **vt = *(void ***)p;
            ((void (*)(Elem *, int))vt[3])(p, bx);
            FUN_0005743c(p, 0, by, 0);
            FUN_00057b58(p, 0, 0, 0.0f);
            FUN_00058ddc(p, 0, -1);
            FUN_00058ec4(p, -1, 1.0f);
            p->f_c0 = 0;
            p->f_c4 = 1.0f;
            FUN_00059084(p, -1);
            p->f_d0 = p->f_c4;
            p++;
        }
    }
}
// Phase-3 pass 7 (2026-10-28): from-scratch rebuild (the old draft was a Ghidra translation). 71/80 -> 79/80 words.
// Structure now right: A = Vec2{0,0} at 52/56, B = A copied per outer iteration with lwc1/lwc1/swc1/swc1 (44/48),
// the iterator `it` at 60 (address-taken by FUN_000643e8), guard + `for (; it != end; FUN_000643e8(&it))` giving
// retail's two plain `beq` heads, and the per-element body in retail's exact order (virtual call via vt[3] with
// a1 = B.x, FUN_0005743c(p,0,B.y,0), 0x57b58, 0x58ddc, 0x58ec4, f_c0 = 0, f_c4 = 1.0f, 0x59084, f_d0 = f_c4).
// REMAINING: frame 48 vs retail 64 - our locals come to 12 bytes (MWCC folds the constant A into B and reuses
// slots), retail reserves 32 (A 8 + B 8 + it 4 + 12 unused). A union-based Pair keeps the frame at 64 but costs
// 4 extra words (84/80). Next idea: force B to stay alive by taking its address once, or declare A with a
// 16-byte object so the local area rounds to 32.
// near miss from lane dsn2 (unreviewed)
