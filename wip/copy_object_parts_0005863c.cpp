/* HSTMATCH module=EBOOT.BIN start=0x0005863c end=0x00058694 symbol=FUN_0005863c lang=c++ */
/* NEAR MISS: 22/22 words, 11 differ - the ONLY difference is which callee-saved register holds
   which parameter: retail copies a1 into s0 first and a2 into s1, ours does the opposite
   (`move s1,a1` / `move s0,a2`).  Everything else (the null test, the two calls with the
   +0x40 offsets and the two byte copies at +0x80/+0x81) is byte identical. */
/* Copies the two 0x40-byte parts of one object into another and then the two flag bytes at
   +0x80/+0x81; the first parameter is not used at all. */
typedef struct {
    char pad[0x40];
} Part;

typedef struct {
    Part a;
    Part b;
    signed char f80;
    signed char f81;
} Obj;

extern "C" void FUN_00058694(Part *dst, Part *src);

extern "C" void FUN_0005863c(Obj *out, Obj *src, Obj *other)
{
    if (src != 0) {
        FUN_00058694(&src->a, &other->a);
        FUN_00058694(&src->b, &other->b);
        src->f80 = other->f80;
        src->f81 = other->f81;
    }
}
// near miss from lane om1 (unreviewed)
