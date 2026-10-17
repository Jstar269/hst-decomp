/* HSTMATCH module=hstp_trans_main.prx start=0x0010d030 end=0x0010d16c symbol=FUN_0010d030 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: insert(pos, x). With spare capacity the tail is shifted up one element (x is
   re-pointed when it lies inside the moved range) and *pos is overwritten; otherwise the growth policy
   (0x10ddfc) is queried, the new block reserved (0x10dee0), x stored at its final slot and the old elements
   copied across by 0x10dae4. Matching idioms: `goto done` (the fast arm and the slow tail share one return
   block), `result -= n` inside the inline copy helper, a one-char flag struct built from 0 for reserve().
   Names provisional. */
extern "C" {
void *FUN_000111c0(void *dst, const void *src, unsigned n);
}
struct Flag { char v; Flag(char x) : v(x) {} };
struct Vec;
extern "C" void FUN_0010dee0(Vec *v, unsigned n, char f);
struct Vec {
    int *data;
    unsigned size;
    unsigned capacity;
    void reserve(unsigned n, Flag f) { FUN_0010dee0(this, n, f.v); }
};

extern "C" unsigned FUN_0010ddfc(Vec *v, unsigned n);
extern "C" int *FUN_0010dae4(Vec *v, int *old, int idx, int n, unsigned oldcap);

inline void CopyBackward(int *first, int *last, int *result)
{
    int n = last - first;
    result -= n;
    FUN_000111c0(result, first, n * 4);
}

extern "C" int *FUN_0010d030(Vec *v, int *pos, int *x)
{
    if (v->size >= v->capacity) {
        FUN_0010ddfc(v, 1);
    } else {
        int *end = v->data + v->size;
        if (pos <= x) {
            if (x < end)
                ++x;
        }
        v->size++;
        CopyBackward(pos, end, end + 1);
        *pos = *x;
        goto done;
    }
    unsigned oldcap = v->capacity;
    int *old = v->data;
    int idx = pos - old;
    unsigned n = FUN_0010ddfc(v, 1);
    v->reserve(n, Flag(0));
    v->data[idx] = *x;
    pos = FUN_0010dae4(v, old, idx, 1, oldcap);
done:
    return pos;
}
