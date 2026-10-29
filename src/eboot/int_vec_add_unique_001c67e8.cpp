/* HSTMATCH module=EBOOT.BIN start=0x001c67e8 end=0x001c68a8 symbol=FUN_001c67e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idioms: the inline Tag-taking grow() that drops its Tag and rebuilds Tag() for the out-of-line call; Ne()/Eq() helpers keep the iterator reload and the bnel operand order. */

struct Tag {};
struct IntVec;
extern "C" void FUN_001ce554(IntVec *, const int *, Tag);

struct It {
    int *p_;
    It() {}
    It(int *p) : p_(p) {}
    int &operator*() const { return *p_; }
    It &operator++() { ++p_; return *this; }
};

static inline bool Ne(const It &a, const It &b) { return a.p_ != b.p_; }
static inline bool Eq(const int &a, const int &b) { return a == b; }
static inline It Find(It first, It last, const int &val)
{
    while (Ne(first, last) && !Eq(*first, val)) ++first;
    return first;
}

struct IntVec {
    int *data;
    unsigned size;
    unsigned cap;
    It begin() { return It(data); }
    It end() { return It(data + size); }
    int &at(unsigned i) { return data[i]; }
    int &back() { return at(size - 1); }
    void grow(const int &x, Tag) { FUN_001ce554(this, &x, Tag()); }
    void push_back(const int &x, Tag)
    {
        if (size < cap) {
            size++;
            back() = x;
        } else {
            grow(x, Tag());
        }
    }
};

struct Self {
    char pad[0x40];
    IntVec items;
};

extern "C" void FUN_001c67e8(Self *self, int x)
{
    It it = Find(self->items.begin(), self->items.end(), x);
    if (it.p_ == self->items.end().p_) {
        self->items.push_back(x, Tag());
    }
}
