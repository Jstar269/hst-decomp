/* HSTMATCH module=EBOOT.BIN start=0x00109db8 end=0x0010a058 symbol=FUN_00109db8 lang=c++ */
/* Hand-written near miss for SGI/MSL STL __rotate_adaptive: 168/168 words generated (exact size).
   All control flow, branches, comparisons, memcpy and fallback calls match retail 100%.
   Remaining diffs are stack frame size (96 vs retail 112) and s1/s2 register allocation. */

template <class T>
struct It {
    T *p_;
    It() {}
    It(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It &operator++() { ++p_; return *this; }
    It &operator--() { --p_; return *this; }
    It operator+(int n) const { return It(p_ + n); }
    It operator-(int n) const { return It(p_ - n); }
};

template <class T>
inline bool operator==(const It<T> &a, const It<T> &b) { return a.p_ == b.p_; }
template <class T>
inline bool operator!=(const It<T> &a, const It<T> &b) { return !(a == b); }

struct TempBufInfo {
    int pad0;
    int count;
    int *base;
};

struct TempBufIter {
    int *p_;
    TempBufInfo *info_;

    struct Ref {
        int *p_;
        TempBufInfo *info_;
        Ref(int *p, TempBufInfo *info) : p_(p), info_(info) {}
        void operator=(int val) {
            if (p_ - info_->base < info_->count) {
                *p_ = val;
            } else {
                if (p_ != 0) *p_ = val;
                info_->count++;
            }
        }
    };

    Ref operator*() const { return Ref(p_, info_); }
    TempBufIter &operator++() { ++p_; return *this; }
    int operator-(const TempBufIter &o) const { return p_ - o.p_; }
};

struct Tag {
    char dummy;
};

extern "C" {
void *FUN_000111c0(void *dest, const void *src, unsigned int n);
void FUN_0010a360(It<int> first, It<int> middle, It<int> last, Tag tag);
}

template <class In, class Out>
inline void copy_to_buf(In first, In last, Out &res) {
    while (first != last) {
        *res = *first;
        ++first;
        ++res;
    }
}

extern "C" void FUN_00109db8(It<int> *ret, It<int> first, It<int> middle, It<int> last,
                             int len1, int len2,
                             TempBufIter buf, TempBufIter buf_end)
{
    Tag tag;
    int buf_len = buf_end - buf;

    if (len1 <= len2 && len1 <= buf_len) {
        TempBufIter cur;
        cur = buf;
        copy_to_buf(first, middle, cur);
        int bytes = (last.p_ - middle.p_) * 4;
        FUN_000111c0(first.p_, middle.p_, bytes);
        if (cur.p_ != buf.p_) {
            do {
                --cur.p_;
                --last.p_;
                *last.p_ = *cur.p_;
            } while (cur.p_ != buf.p_);
        }
        *ret = last;
        return;
    } else if (len2 <= buf_len) {
        TempBufIter cur;
        cur = buf;
        copy_to_buf(middle, last, cur);
        int bytes = (middle.p_ - first.p_) * 4;
        FUN_000111c0(last.p_ - (middle.p_ - first.p_), first.p_, bytes);
        for (int *p = buf.p_; p != cur.p_; ++p, ++first.p_) {
            *first.p_ = *p;
        }
        *ret = first;
        return;
    }

    FUN_0010a360(first, middle, last, tag);
    *ret = first + len2;
}
// near miss from lane ag2 (unreviewed)
