/* HSTMATCH module=EBOOT.BIN start=0x00286f00 end=0x00286f2c symbol=FUN_00286f00 lang=c99 */
struct S { void **vtbl; char pad[44]; int f30, f34, f38; };
typedef void (*Tramp)(void *, int, int, int, int);

void FUN_00286f00(struct S *o, int a, int b, int c, int d, int e, int f, int g)
{
    Tramp fn;
    o->f30 = a;
    o->f34 = b;
    o->f38 = c;
    fn = (Tramp)o->vtbl[6];
    fn(o, d, e, f, g);
}

// NEAR (3 words, 44 bytes): everything matches except the indirect-call target register. Retail loads the
// vtable slot into t9 (`lw t9,0(a0); lw t9,24(t9); jr t9`); every C spelling (direct cast, cast of the
// element, function-pointer local, named vtable array) gives v0 and `jr v0`. A real C++ virtual call
// (class with the vptr / virtuals) loads t9 but adds a frame + `jalr`, giving 15 words.
// So this is a C++ virtual tail call: t9 comes from the virtual-dispatch path, `jr` from the sibling call.
// near miss from lane dsn3 (unreviewed)
