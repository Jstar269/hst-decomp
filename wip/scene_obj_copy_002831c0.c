/* HSTMATCH module=EBOOT.BIN start=0x002831c0 end=0x00283358 symbol=FUN_002831c0 lang=c99 */
struct Pair1 {
    unsigned char a, b;
};

struct Pair2 {
    char a, b;
};

struct Vec4 {
    float v[4];
};

struct PairF {
    float a, b;
};

struct PairS {
    short a, b;
};

struct Obj {
    char pad0[0x9c];
    struct Pair1 f9c;
    unsigned char f9e;
    unsigned char f9f;
    signed char fa0;
    char pad1[3];
    struct Vec4 fa4;
    float fb4;
    int fb8;
    struct PairS m[3];
    unsigned char fc8;
    unsigned char fc9;
    unsigned char fca;
    unsigned char fcb;
    struct Pair2 n[16];
    unsigned char fec;
    unsigned char fed;
    unsigned char fee;
    unsigned char fef;
    unsigned char ff0;
    char pad2[3];
    int ff4;
    int ff8;
    float ffc;
    unsigned char f100;
    unsigned char f101;
    char pad3[2];
    int f104;
    struct Pair2 o[8];
    struct PairF f118;
};

extern void FUN_00097b2c(struct Obj *, struct Obj *);

struct Obj *FUN_002831c0(struct Obj *param_1, struct Obj *param_2)
{

    FUN_00097b2c(param_1, param_2);
    param_1->f9c = param_2->f9c;
    param_1->f9e = param_2->f9e;
    param_1->f9f = param_2->f9f;
    param_1->fa0 = param_2->fa0;
    param_1->fa4 = param_2->fa4;
    param_1->fb4 = param_2->fb4;
    param_1->fb8 = param_2->fb8;
    {
        struct PairS *sp = param_2->m;
        struct PairS *dp = param_1->m;
        int i = 3;
        do {
            *dp++ = *sp++;
        } while (--i > 0);
    }
    param_1->fc8 = param_2->fc8;
    param_1->fc9 = param_2->fc9;
    param_1->fca = param_2->fca;
    param_1->fcb = param_2->fcb;
    {
        struct Pair2 *tp = param_2->n;
        struct Pair2 *up = param_1->n;
        int i = 16;
        do {
            *up++ = *tp++;
        } while (--i > 0);
    }
    param_1->fec = param_2->fec;
    param_1->fed = param_2->fed;
    param_1->fee = param_2->fee;
    param_1->fef = param_2->fef;
    param_1->ff0 = param_2->ff0;
    param_1->ff4 = param_2->ff4;
    param_1->ff8 = param_2->ff8;
    param_1->ffc = param_2->ffc;
    param_1->f100 = param_2->f100;
    param_1->f101 = param_2->f101;
    param_1->f104 = param_2->f104;
    {
        struct Pair2 *tp = param_2->o;
        struct Pair2 *up = param_1->o;
        int i = 8;
        do {
            *up++ = *tp++;
        } while (--i > 0);
    }
    param_1->f118 = param_2->f118;
    return param_1;
}
// near miss: 102/102 words, 4 differ, all at +0xcc - retail copies the 2-byte Pair1 member as two
// SERIALIZED lbu/sb pairs (lbu v0,156; addiu a3,s0,188; addiu a2,s1,188; sb v0,156; lbu v0,157;
// li a1,3; sb v0,157) while we batch both loads then both stores, and our m[3] loop pointers land
// in a2/a1 where retail uses a3/a2 (our `li` counter is a0 vs retail a1 - retail keeps one more
// value live across the copy). Ruled out: char temp serialization, field-wise copies, struct copy
// via char*, declaring the loop counter outside the block. Everything else in the function is
// word-for-word (block-scoped per-loop pointers give retail's a0/a1/a2 mapping).
// near miss from lane fm9 (unreviewed)
