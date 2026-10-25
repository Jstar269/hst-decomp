/* HSTMATCH module=EBOOT.BIN start=0x0016cf60 end=0x0016d110 symbol=FUN_0016cf60 lang=c++ */

#pragma opt_strength_reduction off

struct Tag_0016cf60 {};

struct IVec_0016cf60;
struct Vec_0016cf60;

extern "C" {
void FUN_001799f0(IVec_0016cf60 *v, unsigned int n, const int &x);
void FUN_00179ad8(Vec_0016cf60 *v, unsigned int n, const IVec_0016cf60 &x, Tag_0016cf60 t);
void FUN_00179a70(IVec_0016cf60 *v, int dummy);
void FUN_00179840(IVec_0016cf60 *v, unsigned int n, const int &x, Tag_0016cf60 t);
}

struct IVec_0016cf60 {
    int *data_;
    unsigned int size_;
    unsigned int cap_;

    void resize(unsigned int n) {
        int zero = 0;
        if (size_ < n) {
            FUN_00179840(this, n - size_, zero, Tag_0016cf60());
        } else if (n < size_) {
            unsigned int d = size_ - n;
            size_ -= d;
        }
    }
};

struct Vec_0016cf60 {
    IVec_0016cf60 *data_;
    unsigned int size_;
    unsigned int cap_;
};

extern "C" void FUN_0016cf60(Vec_0016cf60 *dst, const IVec_0016cf60 *src) {
    int src_idx;
    int rem;
    int count;

    int s = src->size_;
    count = s / 4;
    rem = s % 4;
    if (rem != 0) {
        count++;
    }

    {
        int zero = 0;
        IVec_0016cf60 temp;
        temp.data_ = 0;
        temp.size_ = 0;
        temp.cap_ = 0;
        FUN_001799f0(&temp, 4, zero);
        FUN_00179ad8(dst, count, temp, Tag_0016cf60());
        FUN_00179a70(&temp, 0);
    }

    src_idx = 0;
    for (int i = 0; i < count; i++, src_idx += 4) {
        if (i == count - 1 && rem != 0) {
            dst->data_[i].resize(rem);
        }
        for (unsigned int j = 0; j < dst->data_[i].size_; j++) {
            dst->data_[i].data_[j] = src->data_[src_idx + j];
        }
    }
}

// Differing words: 39 / 108.
// Structural match: 100%. Frame size 64 bytes matches retail bit-for-bit.
// Prologue saves s0..s5 and ra at identical offsets (4, 8, 12, 16, 20, 24, 28).
// Differs only by register coloring permutation between s2..s5:
// Retail: s1=count, s2=src, s3=dst, s4=rem, s5=src_idx, s0=i.
// Ours:   s1=count, s2=src_idx, s3=src, s4=dst, s5=rem, s0=i.
// near miss from lane ag4 (unreviewed)
