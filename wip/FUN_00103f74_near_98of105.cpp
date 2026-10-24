/* HSTMATCH module=EBOOT.BIN start=0x00103f74 end=0x00104118 symbol=FUN_00103f74 lang=c++ */

struct Elem {
    int pad0_;
    int **items_;
    int count_;
};

struct List {
    int *begin_;
    int size_;
    int cap_;
};

struct Self {
    char pad_[4];
    Elem **vec_;
    int vec_count_;
    char pad2_[0x40 - 0xc];
    List list_;
};

struct EIt {
    Elem **p_;
    EIt() {}
    EIt(Elem **q) : p_(q) {}
    Elem *operator*() const { return *p_; }
    EIt &operator++() { ++p_; return *this; }
};
static inline int operator!=(const EIt &a, const EIt &b) { return (a.p_ == b.p_) ^ 1; }

struct IIt {
    int *p_;
    IIt() {}
    IIt(int *q) : p_(q) {}
    int &operator*() const { return *p_; }
    IIt &operator++() { ++p_; return *this; }
};

static inline int neq(const IIt &a, const IIt &b) { return a.p_ != b.p_; }
static inline int eqkey(const IIt &a, int k) { return *a.p_ == k; }
static inline void inc(IIt &a) { a.p_++; }

static inline IIt find(IIt first, IIt last, int key)
{
    for (; neq(first, last); inc(first)) {
        if (eqkey(first, key)) break;
    }
    return first;
}

extern "C" void FUN_000c3f94(List *list, int *key, int zero);

extern "C" void FUN_00103f74(Self *self)
{
    {
        int n = self->list_.size_;
        self->list_.size_ -= n;
    }
    EIt it = EIt(self->vec_);
    EIt end = EIt(self->vec_ + self->vec_count_);
    if (it != end) {
        do {
            Elem *e = *it;
            for (int j = 0; j < e->count_; j++) {
                int *item = e->items_[j];
                int key = item[1];
                if (key == -1) key = 0;
                IIt first;
                IIt last;
                first = IIt(self->list_.begin_);
                last = IIt(self->list_.begin_ + self->list_.size_);
                float fl = *(float *)&last.p_;
                IIt l2 = IIt((int *)*(int *)&fl);
                float fk = *(float *)&key;
                int k2 = *(int *)&fk;
                IIt found = find(first, l2, k2);
                if (found.p_ != last.p_) {
                    item[0x13] = (int)((char *)found.p_ - (char *)first.p_) / 4;
                } else {
                    item[0x13] = self->list_.size_;
                    if (self->list_.size_ < self->list_.cap_) {
                        self->list_.begin_[self->list_.size_] = key;
                        self->list_.size_ = self->list_.size_ + 1;
                    } else {
                        FUN_000c3f94(&self->list_, &key, 0);
                    }
                }
            }
            ++it;
            end = EIt(self->vec_ + self->vec_count_);
        } while (it != end);
    }
}
// near miss from lane ds1018ar1-0 (unreviewed)
// improved by lane fm10 (unreviewed): 100 -> 98 differing words
