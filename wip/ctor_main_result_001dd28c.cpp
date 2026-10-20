/* HSTMATCH module=EBOOT.BIN start=0x001dd28c end=0x001dd370 symbol=FUN_001dd28c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { int idx; int name; int out; } Rec;

extern "C" Rec DAT_002eba68[];
extern "C" void *DAT_002eba54;
extern "C" char DAT_002eba80;
extern "C" char DAT_00309440;

extern "C" void FUN_00102e38();
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void *FUN_001039d8(void *, void *, int);
extern "C" void *FUN_001026b8(void *, void *);

extern "C" void *FUN_001dd28c(char *o) {
    int i;
    Rec *r;
    int off;
    FUN_00102e38();
    *(void **)o = &DAT_00309440;
    FUN_00104118(o, &DAT_002eba80, 0);
    FUN_00103540(o, 5000.0f);
    *(void **)(o + 0x58) = FUN_001039d8(o, DAT_002eba54, 0);
    i = 0;
    r = DAT_002eba68;
    off = 0;
    do {
        void *q = FUN_001026b8(*(void **)(o + 0x58 + r->idx * 4), (void *)r->name);
        *(void **)(o + 0x5c + off) = q;
        r->out = *(int *)((char *)q + 0x24);
        i = i + 1;
        off = off + 4;
        r++;
    } while (i < 2);
    *(int *)(o + 0x54) = 5;
    return o;
}

// NEAR MISS: 1 word (56 vs 57). Retail materialises the storage address of the name-pointer global
// before loading it (`lui v0,0x2f; addiu v0,v0,-17836; lw a1,0(v0)`) where this source gets the usual
// folded `lui v0,0x2f; lw a1,-17836(v0)`; everything else in the constructor matches and the rest of
// the function is shifted by that one word. Tried: `*(void**)&DAT_xx`, `((void**)&DAT_xx)[0]`,
// `*(void**)DAT_xx` with a char[] declaration, `void *DAT_xx[]` + `[0]`, a 1-member struct view
// (`DAT_xx.p`, array of 1), `const`/`volatile` globals, an inline reference-returning accessor, an
// inline `Deref(&DAT_xx)`, and the C99 front end.
// near miss from lane ds7 (unreviewed)
