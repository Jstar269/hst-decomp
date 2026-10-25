/* HSTMATCH module=EBOOT.BIN start=0x0027a7a0 end=0x0027aa3c symbol=FUN_0027a7a0 lang=c++ */

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
bool FUN_0027ab84(Pred *, Record *);
}

static inline void unguarded_partition(Iterator *ret, Iterator first, Record *last_ptr, Pred *pred) {
    Iterator last(last_ptr);
    while (true) {
        while (FUN_0027ab84(pred, FUN_0027a2ec(&first)))
            FUN_0027ab98(&first);
        do {
            FUN_0027ab70(&last);
        } while (!FUN_0027ab84(pred, FUN_0027a2ec(&last)));

        if (FUN_0027ab5c(&first, &last))
            break;

        FUN_0027aa4c(first.ptr, last.ptr);
        FUN_0027ab98(&first);
    }
    FUN_0027aa3c(ret, &first);
}

extern "C" void FUN_0027a7a0(Iterator *ret, Iterator first, Iterator last, Pred *pred) {
    Record *s0 = last.ptr - 1;
    Pred *s1 = pred;
    Iterator *s2 = ret;
    Record *s3 = first.ptr;

    if (first.ptr == last.ptr) {
        s2->ptr = first.ptr;
        return;
    }

    int pivot_key = s1->pivot->key;
    bool b1 = (first.ptr->key < pivot_key);
    bool b2 = (s0->key < pivot_key);
    if (b1 && !b2) {
        s3 = s3 + 1;
        first.ptr = s3;
        unguarded_partition(s2, first, s0, s1);
        return;
    }

    if (b2) {
        if (b1) {
            do {
                s3 = s3 + 1;
                first.ptr = s3;
            } while (s3 != last.ptr && s3->key < pivot_key);
            if (s3 == last.ptr) {
                s2->ptr = s3;
                return;
            }
        }
        s0 = s0 - 1;
    } else {
        if (s3 == s0) {
            s2->ptr = s3;
            return;
        }
        for (s0 = s0 - 1; s3 != s0 && !(s0->key < pivot_key); s0 = s0 - 1) {
        }
        if (s3 == s0) {
            s2->ptr = s3;
            return;
        }
    }

    Iterator it_b(s0);
    FUN_0027a190(FUN_0027a2ec(&first), FUN_0027a2ec(&it_b));

    s3 = s3 + 1;
    first.ptr = s3;
    unguarded_partition(s2, first, s0, s1);
}
// near miss from lane ag4 (unreviewed)
