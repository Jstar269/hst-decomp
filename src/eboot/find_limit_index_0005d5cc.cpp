/* HSTMATCH module=EBOOT.BIN start=0x0005d5cc end=0x0005d638 symbol=FUN_0005d5cc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Walks the float array at +0x18 of the object and returns the entry of the index array at +0x1c
   for the first value above the limit; the limit is the argument raised by 1e-7.  An empty array
   (count at +0x14 == 0) returns -1.
   Matching idiom: the limit is built with a compound assignment (`lim += 1e-7f`), which keeps
   retail's `add.s f12,f12,f0` (the value in place, the constant second). */
typedef struct {
    char pad[0x14];
    int f14;
    float *f18;
    int *f1c;
} Obj;

extern "C" int FUN_0005d5cc(float x, Obj *self)
{
    int n = self->f14;
    if (n == 0) {
        return -1;
    }
    int last = n - 1;
    float lim = x;
    lim += 1e-7f;
    int i = 0;
    while (i < last) {
        if (self->f18[i + 1] > lim) {
            break;
        }
        i++;
    }
    return self->f1c[i];
}
