/* HSTMATCH module=EBOOT.BIN start=0x001b9f78 end=0x001ba05c symbol=FUN_001b9f78 lang=c++ */
/* Clone of src/sharing_main/deleting_dtor_001c7cc0.cpp (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_00309314;
extern "C" void FUN_00000a00(void *);
extern "C" void *FUN_001bb0ec(void *, int);
extern "C" int FUN_00204ac8(void *, int);

struct Alloc {};

template <class T> struct It {
    T *p_;
    It(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It<T> &a, const It<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It<T> &a, const It<T> &b) { return !(a == b); }

template <class T> struct Vec {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It<T> begin() const { return It<T>(data_); }
    It<T> end() { return It<T>(data_ + size_); }
    void shrink(int n, Alloc) { size_ -= n; }
};

struct Obj {
    void *vptr;
    Vec<void *> vec;
};

extern "C" Obj *FUN_001b9f78(Obj *self, short flag)
{
    if (self != 0) {
        self->vptr = &DAT_00309314;
        for (It<void *> it = self->vec.begin(); it != self->vec.end(); ++it) {
            void *p = *it;
            if (p != 0) {
                FUN_00204ac8(p, 1);
                *it = 0;
            }
        }
        int n = self->vec.size_;
        self->vec.shrink(n, Alloc());
        void *pvec = &self->vec;
        if (pvec != 0 && pvec != 0) {
            FUN_001bb0ec(pvec, 0);
        }
        if (flag > 0) {
            FUN_00000a00(self);
        }
    }
    return self;
}
