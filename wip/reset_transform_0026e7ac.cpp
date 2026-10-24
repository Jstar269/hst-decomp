/* HSTMATCH module=EBOOT.BIN start=0x0026e7ac end=0x0026ea04 symbol=FUN_0026e7ac lang=c++ */

typedef unsigned char undefined1;

struct Vec4_26e7ac {
    float v[4];
};

struct Matrix_26e7ac {
    Vec4_26e7ac r0, r1, r2, r3;
};

struct VC_26e7ac {
    virtual void s0();
    virtual void s1(int v);     /* vtable +0x0c */
};

struct Node_26e7ac {
    char pad0[0x30];
    Matrix_26e7ac matrix;       /* 0x30 */
};

struct Scene_26e7ac {
    char pad0[4];
    Node_26e7ac **obj;          /* 0x04 */
    char pad8[0x74 - 8];
    float f74;                  /* 0x74 */
    float f78;                  /* 0x78 */
};

struct Obj_26e7ac {
    char pad0[0xd8];
    char **fd8;                 /* 0x0d8 */
    char pad1[0x110 - 0xdc];
    undefined1 f110;            /* 0x110 */
    char pad2[0x450 - 0x111];
    int f450;                   /* 0x450 */
    char pad3[0x474 - 0x454];
    VC_26e7ac *f474;            /* 0x474 */
    char pad4[0x8c1 - 0x478];
    undefined1 f8c1;            /* 0x8c1 */
    undefined1 f8c2;            /* 0x8c2 */
    char pad5[0x8cc - 0x8c3];
    undefined1 f8cc;            /* 0x8cc */
    char pad6[0x8d4 - 0x8cd];
    int f8d4;                   /* 0x8d4 */
    char pad7[0x986 - 0x8d8];
    undefined1 f986;            /* 0x986 */
    char pad8[0x988 - 0x987];
    int f988;                   /* 0x988 */
};

extern "C" {
extern Scene_26e7ac *DAT_003415ac;
extern Matrix_26e7ac DAT_002bc410;
extern char DAT_0034179c[];
extern int FUN_001155c0(Scene_26e7ac *s);
extern int FUN_001156d4(Scene_26e7ac *s);
extern int FUN_00103628(Scene_26e7ac *s, int v);
extern void FUN_001b1c44(void *p, int v);
extern void FUN_0026fcec(Obj_26e7ac *o);
}

extern "C" void FUN_0026e7ac(Obj_26e7ac *o)
{
    Vec4_26e7ac *rows;
    Scene_26e7ac *sc;
    float y, x;

    if (o->f8c2 != 0) {
        o->f8c1 = 0;
        o->f8c2 = 0;
    }
    if (FUN_001155c0(DAT_003415ac) != 0 && o->f8c1 != 0) {
        if (FUN_001156d4(DAT_003415ac) == 0) {
            FUN_00103628(DAT_003415ac, 1);
            o->f110 = 1;
            o->f474->s1(0);
            o->f8c2 = 1;
            FUN_001b1c44(DAT_0034179c, 9);
            FUN_0026fcec(o);
            o->f8d4 = 2;
            o->f8cc = 1;
            o->f986 = 1;
            o->f988 = 0;
        } else {
            FUN_00103628(DAT_003415ac, 1);
            o->f474->s1(0);
            o->f8c2 = 1;
            o->f110 = 1;
            o->f8d4 = 2;
            o->f8cc = 1;
            o->f450 = 0;
            (*o->fd8)[1] = 0;
        }

        rows = (Vec4_26e7ac *)*DAT_003415ac->obj;
        if (rows)
            rows = (Vec4_26e7ac *)((char *)rows + 0x30);
        rows[0] = DAT_002bc410.r0;
        rows[1] = DAT_002bc410.r1;
        rows[2] = DAT_002bc410.r2;
        rows[3] = DAT_002bc410.r3;
        (*DAT_003415ac->obj)->matrix.r3.v[0] = 240.0f;
        (*DAT_003415ac->obj)->matrix.r3.v[1] = 136.0f;
        y = (*DAT_003415ac->obj)->matrix.r3.v[1];
        x = (*DAT_003415ac->obj)->matrix.r3.v[0];
        (*DAT_003415ac->obj)->matrix.r3.v[0] = x;
        (*DAT_003415ac->obj)->matrix.r3.v[1] = y;
        sc = DAT_003415ac;
        sc->f74 = 1.0f;
        sc->f78 = 1.0f;
    }
}

// 152/150 words, 28 differ; every instruction matches 1:1 from the entry to the tail, only register
// names and two extra words differ. Structure verified against retail:
// - the 4x16-byte matrix copy is four 4-float struct copies (loads f3,f2,f1,f0 then 4 stores, and the
//   rotated f2/f3 order in rows 2-4). It only comes out that way when each row is a struct with an
//   ARRAY member (struct V4 { float v[4]; }) copied as `rows[i] = src.rN` - with plain float x,y,z,w
//   members mwcc (C and C++) emits load/store per element, and a whole 64-byte struct copy becomes an
//   8-iteration word loop.
// - the vtable call is C++ (lw t9,0(a0); lw t9,12(t9); jalr t9); a C function-pointer call through the
//   same vtable slot compiles to lw v0,12(a0); jr v0, so the TU is C++ (a C version of this file gets
//   all the copies right but can never produce the t9 dispatch).
// - `rows = (Vec4 *)*DAT_003415ac->obj; if (rows) rows = (Vec4 *)((char *)rows + 0x30);` reproduces the
//   beqz/nop/addiu in-place adjust; a `n ? &n->matrix : 0` ternary instead gives beqzl + a dead move.
// Remaining diff (allocator only): in the save/restore pair retail keeps DAT_003415ac in a1 across the
// store and re-derives only *obj (lw a0,4(a1); lw a0,0(a0)); ours reloads DAT for the second store
// (fresh lui + 3 loads), which is the 2-word excess. Tried: scene-pointer locals for the pair, global
// pointer declared void*, object-pointer local, y/x declaration order - mwcc always reloads DAT after
// the intervening store. Retail also hoists `lui a0,0x34` (for that reload) one statement early.
// The `y = ...; x = ...; store x; store y;` save/restore is a matching idiom: a literal self-copy of
// the translation pair folds away, this form keeps the two loads and two stores retail has.
// near miss from lane fm7 (unreviewed)
