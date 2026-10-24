/* HSTMATCH module=EBOOT.BIN start=0x0027abac end=0x0027ae4c symbol=FUN_0027abac lang=c++ */

struct Record {
    char pad[16];
    int key;
    char pad2[28];
};

struct Pred {
    int pad;
    Record *pivot;
};

struct Iterator {
    Record *ptr;
    Iterator() {}
    Iterator(Record *p) : ptr(p) {}
};

extern "C" {
Record *FUN_0027a2ec(Iterator *);
Iterator *FUN_0027ab98(Iterator *);
Iterator *FUN_0027ab70(Iterator *);
bool FUN_0027ab5c(Iterator *, Iterator *);
void FUN_0027aa4c(Record *, Record *);
Iterator *FUN_0027aa3c(Iterator *, Iterator *);
void FUN_0027a190(Record *, Record *);
bool FUN_0027ae4c(Pred *, Record *);
}

static inline void unguarded_partition(Iterator *ret, Iterator first, Record *last_ptr, Pred *pred) {
    Iterator last(last_ptr);
    while (true) {
        while (FUN_0027ae4c(pred, FUN_0027a2ec(&first)))
            FUN_0027ab98(&first);
        do {
            FUN_0027ab70(&last);
        } while (!FUN_0027ae4c(pred, FUN_0027a2ec(&last)));

        if (FUN_0027ab5c(&first, &last))
            break;

        FUN_0027aa4c(first.ptr, last.ptr);
        FUN_0027ab98(&first);
    }
    FUN_0027aa3c(ret, &first);
}

extern "C" void FUN_0027abac(Iterator *ret, Iterator first, Iterator last, Pred *pred) {
    Record *s0 = last.ptr - 1;
    Pred *s1 = pred;
    Iterator *s2 = ret;
    Record *s3 = first.ptr;

    if (first.ptr == last.ptr) {
        s2->ptr = first.ptr;
        return;
    }

    int pivot_key = s1->pivot->key;
    bool b1 = (first.ptr->key <= pivot_key);
    if (b1 && pivot_key < s0->key) {
        s3 = s3 + 1;
        first.ptr = s3;
        unguarded_partition(s2, first, s0, s1);
        return;
    }

    if (pivot_key < s0->key) {
        if (s3 == s0) {
            s2->ptr = s3;
            return;
        }
        for (s0 = s0 - 1; s3 != s0 && pivot_key < s0->key; s0 = s0 - 1) {
        }
        if (s3 == s0) {
            s2->ptr = s3;
            return;
        }
    } else {
        if (b1) {
            do {
                s3 = s3 + 1;
                first.ptr = s3;
            } while (s3 != s0 && s3->key <= pivot_key);
            if (s3 == s0) {
                s2->ptr = s3;
                return;
            }
        }
    }

    Iterator it_b(s0);
    FUN_0027a190(FUN_0027a2ec(&first), FUN_0027a2ec(&it_b));

    s3 = s3 + 1;
    first.ptr = s3;
    unguarded_partition(s2, first, s0, s1);
}

// Differing words: 158 words out of 168 words.
// Exact 64-byte frame and prologue match.
// Algorithm is STL partition instantiated with a custom Iterator over 48-byte records,
// inlining __unguarded_partition in two branches and calling helper operators (0x27ab98, 0x27ab70, 0x27ab5c, 0x27aa4c, 0x27aa3c).
// Differences are register coloring permutations across s0..s3 in the outer partition checks and loops.
// near miss from lane ag4 (unreviewed)
