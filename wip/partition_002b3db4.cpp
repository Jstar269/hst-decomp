/* HSTMATCH module=EBOOT.BIN start=0x002b3db4 end=0x002b4050 symbol=FUN_002b3db4 lang=c++ */

struct Record {
    char pad[80];
    int key;
    char pad2[100 - 84];
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
Record *FUN_002b39d8(Iterator *);
Iterator *FUN_002b42b4(Iterator *);
Iterator *FUN_002b428c(Iterator *);
bool FUN_002b4278(Iterator *, Iterator *);
void FUN_002b4060(Record *, Record *);
Iterator *FUN_002b4050(Iterator *, Iterator *);
void FUN_002b3738(Record *, Record *);
bool FUN_002b42a0(Pred *, Record *);
}

static inline void unguarded_partition(Iterator *ret, Iterator first, Record *last_ptr, Pred *pred) {
    Iterator last(last_ptr);
    while (true) {
        while (FUN_002b42a0(pred, FUN_002b39d8(&first)))
            FUN_002b42b4(&first);
        do {
            FUN_002b428c(&last);
        } while (!FUN_002b42a0(pred, FUN_002b39d8(&last)));

        if (FUN_002b4278(&first, &last))
            break;

        FUN_002b4060(first.ptr, last.ptr);
        FUN_002b42b4(&first);
    }
    FUN_002b4050(ret, &first);
}

extern "C" void FUN_002b3db4(Iterator *ret, Iterator first, Iterator last, Pred *pred) {
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
    FUN_002b3738(FUN_002b39d8(&first), FUN_002b39d8(&it_b));

    s3 = s3 + 1;
    first.ptr = s3;
    unguarded_partition(s2, first, s0, s1);
}
// near miss from lane ag4 (unreviewed)
