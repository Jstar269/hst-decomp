/* HSTMATCH module=hstp_trans_main.prx start=0x0015284c end=0x00152a70 symbol=FUN_0015284c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 40-byte string-led records: insert(pos, x), the 40-byte sibling of vec_insert_one_0010d030.cpp. With spare capacity the new tail slot is copy-constructed from the last element, x is re-pointed when it lies in the moved range, the tail is shifted up by the inline element-wise operator= (the string part is the out-of-line 0x3e04) and *pos is assigned; otherwise a split buffer (0x154a10) is filled, swapped in by 0x1547d0 and destroyed by 0x152f14. Matching idioms: `goto done` shared return, and `end` taken through the inline Vec::End() member (the plain expression v->data + v->size swaps the s0/s1 colours of v and end). Names provisional. */
extern "C" void FUN_00003e04(void *, const void *);

struct Str {
    char d[12];
    Str &operator=(const Str &o) { FUN_00003e04(this, &o); return *this; }
};

struct Elem {
    Str s;
    unsigned f3, f4, f5;
    unsigned char f6;
    unsigned f7;
    float f8, f9;
};

struct Vec {
    Elem *data;
    unsigned size;
    unsigned capacity;
    Elem *End() { return data + size; }
};

struct Buf {
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
};

extern "C" {
void *FUN_00002f60(unsigned, void *);
void FUN_00152704(Elem *, const Elem *);
unsigned FUN_00154dcc(Vec *, unsigned);
void FUN_00154a10(Vec *, Buf *, Elem *, unsigned);
Elem *FUN_001547d0(Vec *, Buf *, Elem *);
void FUN_00152f14(Buf *, int);
}

inline Elem *CopyBackward(Elem *first, Elem *last, Elem *result)
{
    while (first < last) {
        --last;
        --result;
        *result = *last;
    }
    return result;
}

extern "C" Elem *FUN_0015284c(Vec *v, Elem *pos, Elem *x)
{
    if (v->size >= v->capacity) {
        FUN_00154dcc(v, 1);
        goto slow;
    }
    {
        Elem *end = v->End();
        if (pos == end) {
            Elem *p = (Elem *)FUN_00002f60(sizeof(Elem), end);
            if (p) FUN_00152704(p, x);
            ++v->size;
        } else {
            Elem *p = (Elem *)FUN_00002f60(sizeof(Elem), end);
            if (p) FUN_00152704(p, end - 1);
            ++v->size;
            if (pos <= x) {
                if (x < end) ++x;
            }
            CopyBackward(pos, end - 1, end);
            *pos = *x;
        }
        goto done;
    }
slow:
    {
        Buf buf(&v->capacity);
        FUN_00154a10(v, &buf, pos, 1);
        Elem *p = (Elem *)FUN_00002f60(sizeof(Elem), buf.data + buf.start);
        if (p) FUN_00152704(p, x);
        ++buf.size;
        pos = FUN_001547d0(v, &buf, pos);
        FUN_00152f14(&buf, -1);
    }
done:
    return pos;
}
