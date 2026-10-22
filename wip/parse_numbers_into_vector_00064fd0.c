/* HSTMATCH module=EBOOT.BIN start=0x00064fd0 end=0x00065078 symbol=FUN_00064fd0 lang=c99 */
/* NEAR MISS: 42/42 words, 5 differ.  Parses the numbers of a text row into an int vector. */
/* The row cursor is a 12-byte object at sp+16 (its first word is the string pointer that is also
   handed to FUN_00065078 as the "where we stopped" out parameter); the parsed value is a 4-byte
   local at sp+28.  The loop shape, the `int done = !r` materialisation (sltu/xori), the unsigned
   capacity test and the vector append all match retail exactly.
   DIFFERENCE: retail's third argument of FUN_00066098 is a signed char whose value is 0 and which
   MWCC materialises as `move v0,zero` in the delay slot of the capacity branch plus `seb a2,v0`.
   Here the same argument is computed from the container fields, so the two loads come out in the
   wrong order (capacity before count), the compare is mirrored and the delay slot holds
   `subu v0,v0,v1` instead of `move v0,zero`.
   RULED OUT for the third argument: a literal 0 (MWCC folds it to `move a2,zero`, 12 words off),
   a char/unsigned char/signed char/short/int local set to 0 (all folded the same way), an int
   local declared at function scope, `(signed char)(self->count < self->capacity)` (MWCC recomputes
   the compare as a byte compare `sltu a2`), `self->count - self->count` and `count * 0` (folded),
   and passing the `done` flag (kept in a saved register s2 instead of a materialised 0). */
typedef struct {
    int *data;
    unsigned count;
    unsigned capacity;
} Vec;

typedef struct {
    char *p;
    char *q;
    char *r;
} Slice;

extern int FUN_00065078(char *a, char *b, char **out);
extern int FUN_00064820(int s);
extern void FUN_00066098(Vec *self, int *value, signed char flag);

void FUN_00064fd0(Vec *self, char *p, char *pat)
{
    int v;
    Slice s;
    s.p = p;
    unsigned r;
    for (;;) {
        r = FUN_00065078(s.p, pat, &s.p);
        int done = !r;
        if (done) {
            break;
        }
        v = FUN_00064820(r);
        if (self->count < self->capacity) {
            unsigned n = self->count + 1;
            self->count = n;
            self->data[n - 1] = v;
        } else {
            FUN_00066098(self, &v, (signed char)(self->count - self->capacity));
        }
    }
}
// near miss from lane om1 (unreviewed)
