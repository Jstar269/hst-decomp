/* HSTMATCH module=EBOOT.BIN start=0x000b55a0 end=0x000b5900 symbol=FUN_000b55a0 lang=c++ */
/* Hand-written reconstruction from the disassembly; NEAR MISS (216/216 words, 19 differ, all in the tail after the merge loop); names and types await human review. */
#pragma inline_depth(8)
struct Base {
    float f[16];
    int tag;
} __attribute__((aligned(16)));

struct Record : Base {
    Record() {}
    Record(const Record &o)
    {
        f[0] = o.f[0];
        f[1] = o.f[1];
        f[2] = o.f[2];
        f[3] = o.f[3];
        f[4] = o.f[4];
        f[5] = o.f[5];
        f[6] = o.f[6];
        f[7] = o.f[7];
        f[8] = o.f[8];
        f[9] = o.f[9];
        f[10] = o.f[10];
        f[11] = o.f[11];
        f[12] = o.f[12];
        f[13] = o.f[13];
        f[14] = o.f[14];
        f[15] = o.f[15];
        tag = o.tag;
    }
};

struct Iter {
    Record *p;
    int aux;
    Record &operator*() const { return *p; }
    Iter &operator++() { p = p + 1; return *this; }
};
inline bool operator!=(const Iter &a, const Iter &b) { return a.p != b.p; }
inline bool operator==(const Iter &a, const Iter &b) { return a.p == b.p; }
struct OutIter {
    Record *p;
    OutIter() {}
    OutIter(Record *q) : p(q) {}
    OutIter &operator++() { p = p + 1; return *this; }
    Record &operator*() const { return *p; }
};

struct Cmp {
    bool operator()(Record a, Record b) { Base x = *(Base *)&a; Base y = *(Base *)&b; return x.f[14] < y.f[14]; }
};

inline OutIter CopyRange(const Iter &first, const Iter &last, OutIter out)
{
    Record *s = first.p; do { *out = *s; ++s; ++out; } while (s != last.p);
    return out;
}

inline OutIter Tail(Iter a1, Iter b1, Iter a2, Iter b2, OutIter out)
{
    if (a1 == b1) {
        if (a2 != b2) return CopyRange(a2, b2, out);
        return out;
    } else {
        if (a1 != b1) return CopyRange(a1, b1, out);
        return out;
    }
}

extern "C" OutIter FUN_000b55a0(Iter f1, Iter l1, Iter f2, Iter l2, OutIter out, Cmp cmp)
{
    while (f1 != l1 && f2 != l2) {
        if (cmp(*f2, *f1)) {
            Record *o = *(Record * volatile *)&f2.p;
            *out = *o;
            ++f2;
        } else {
            Record *o = *(Record * volatile *)&f1.p;
            *out = *o;
            ++f1;
        }
        ++out;
    }
    return Tail(f1, l1, f2, l2, out);
}

// NEAR MISS (sn1, 216/216 words, 19 differ): std::merge over 80-byte records ({float f[16]; int tag;} aligned 16) with a functor comparing f[14]. Prologue, frame (400), the four
// 16-byte-aligned temporaries, the merge loop and the copy loops match; only the tail dispatch after the loop differs (19 words: register naming a1/t4 and the missing separate reload of the copy-loop pointer after the guard).
// What is solved: (a) iterators/functor/out-iterator are BY-VALUE parameters (hidden return pointer in a0, Iter copies from a1..t0, out in t1,
// the empty functor in t2): `extern "C" OutIter F(Iter f1, Iter l1, Iter f2, Iter l2, OutIter out, Cmp cmp)`; OutIter has user ctors so the return
// is a plain `sw t1,0(a0)` and the returned inline-call temporary supplies the unused 16-byte frame slot at sp+352. (b) the assignment source
// pointer must be a register that survives the copy loop (retail: lw t9; move t8,t9; ...; lw t6,64(t9)): `Record *o = *(Record * volatile *)&f2.p;
// *out = *o;` (a plain `*out = *f2` re-loads the pointer after the loop). (c) the two comparator copies are the Record copy ctor (unrolled 17
// statements) and a POD block copy of `Base` (`Base x = *(Base *)&a;`), 10-iteration word-pair loops. (d) `Cmp` takes Records by value; frame
// temporaries sit at 32/112 (Base copies) and 192/272 (Record copies).
// Open: retail threads the tail so the f1 != l1 entry skips the ELSE guard (`bnel a1,v1,G+4`; the guard `beq a1,v1,END` is the delay-slot
// relay of the THEN guard), the dispatch pointer lives in a1 (ours t4) and the THEN preheader reloads t3/t4 after the guard (ours shares the loads).
// Tried: for/while/do-while tails, raw pointer tails, references, volatile preheader loads (gives the retail load pattern but breaks the
// loop-exit registers), nested copy(f2,l2,copy(f1,l1,out)), sequential ifs, member operators.
// Final tail forms tried (gen_tail.py cross product of 7 copy-loop forms x 6 dispatch forms): the best is this one (do-while copy, guards inside the Tail inline).
// Retail's guard/preheader pattern (`lw a1,f.p; lw v1,l.p; lw t3,l.p; beq a1,v1,SKIP; lw t4,f.p` then the loop on t4/t3) needs the loop POINTER to be loaded
// again after the guard; ours reuses the guard's pointer register (the bound is reloaded correctly), so the delay slot is filled by `beql` instead.
// near miss from lane sn1 (unreviewed)
