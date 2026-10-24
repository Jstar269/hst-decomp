/* HSTMATCH module=EBOOT.BIN start=0x000b6ffc end=0x000b74d4 symbol=FUN_000b6ffc lang=c++ */
/* STATUS CORRECTION 2026-10-24: measured 235/310 words, 309 differ (note claimed 142/310). */
/* NEAR MISS 142/310 words (structure right, inlined copies not yet reproduced).
   Stable MERGE over 80-byte elements `{ float m[16]; int id; }` (stride 0x50), key = m[6] (float at +0x18),
   writing through `*out` at the end. Recovered from the disassembly:
     - param_2 and param_3 are ITERATOR OBJECTS passed BY POINTER: `struct It { Elem *cur, *end; }`, and both are
       copied whole into sp+0x120/0x128 up front with two `lwc1/swc1` pairs (8-byte struct copies). param_4/param_5
       are plain `Elem*` and param_6 is the output cursor; the final `*param_1 = dst` stores the cursor back.
     - the comparison is a PREDICATE TAKING BOTH ELEMENTS BY VALUE: retail copies `*cur` member-by-member into
       sp+0x70 (17 words), then copies `*first` and that temp into two more frame slots as 2-word `lw/sw` loops
       (sp+0xc0 and sp+0x30) - i.e. `Less(*first, tmpA)` with `inline bool Less(Elem a, Elem b)`. Writing that
       predicate lifted this file from 92 to 142 words; comparing the fields directly produces no copies at all.
     - the branch bodies copy a whole element to `dst` as a 16-word 2-word-loop plus `dst[0x10] = src[0x10]`.
     - both tails (whichever range is exhausted) inline the SAME 8-element unrolled bulk copy as 0x000c16f0,
       including MWCC's pointer-difference overflow guard (`lui 0x8000; and ...` on the byte difference and on
       difference+0x4f). That guard is one shared idiom across 0x000c16f0 and 0x000b6ffc.
   Next step: the element copies must go through $f0-$f3 (retail uses `lwc1/swc1` for the 16 floats and separate
   `lw/sw` for the id) - a POD block copy gives the integer `lw/sw` loop we currently emit, so the element needs an
   EXPLICIT member-wise copy path (or an explicit copy ctor); then the two tails' guard block.
   Names provisional. */
struct Elem {
    float m[16];
    int id;
};
struct Range {
    Elem *cur;
    Elem *end;
};
static inline bool Less(Elem a, Elem b) { return a.m[6] < b.m[6]; }
static inline void CopyElem(Elem &d, const Elem &s)
{
    d.m[0] = s.m[0];   d.m[1] = s.m[1];   d.m[2] = s.m[2];   d.m[3] = s.m[3];
    d.m[4] = s.m[4];   d.m[5] = s.m[5];   d.m[6] = s.m[6];   d.m[7] = s.m[7];
    d.m[8] = s.m[8];   d.m[9] = s.m[9];   d.m[10] = s.m[10]; d.m[11] = s.m[11];
    d.m[12] = s.m[12]; d.m[13] = s.m[13]; d.m[14] = s.m[14]; d.m[15] = s.m[15];
    d.id = s.id;
}


extern "C" void FUN_000b6ffc(Elem **out, const Range *a, const Range *b, Elem *first, Elem *last, Elem *dst)
{
    Elem *cur = a->cur;
    while (cur != a->end && first != last) {
        Elem tmpA = *cur;
        Elem tmpB = *first;
        if (Less(tmpB, tmpA)) {
            CopyElem(*dst, tmpB);
            ++first;
        } else {
            CopyElem(*dst, tmpA);
            ++cur;
        }
        ++dst;
    }
    {
        Elem *src;
        Elem *end;
        int bytes;
        if (cur == a->end) {
            src = first;
            end = last;
        } else {
            src = cur;
            end = a->end;
        }
        bytes = (int)((char *)end - (char *)src);
        if ((bytes & 0x80000000) == 0 && (((bytes + 0x4f) & 0x80000000) != 0)) {
            while (bytes > 0) {
                CopyElem(*dst, *src);
                ++dst;
                ++src;
                bytes -= (int)sizeof(Elem);
            }
        } else {
            for (; src < end; ++src, ++dst)
                CopyElem(*dst, *src);
        }
    }
    *out = dst;
}
// near miss from lane ds2 (unreviewed)
// improved by lane fm10 (unreviewed): 310 -> 309 differing words
