/* HSTMATCH module=hstp_trans_main.prx start=0x0005e454 end=0x0005e634 symbol=FUN_0005e454 lang=c++ */

extern "C" void *FUN_00000bcc(unsigned int);
extern "C" void *FUN_0004cd8c(void *, void *, int, int);
extern "C" int *FUN_0005dd7c(void *, int *);
extern "C" void FUN_0005e6e0(void *);
extern "C" void FUN_0005e6ec(void *, int, int, int, int, int, int);
extern "C" void FUN_0005ea7c(void *, const void *, char);

template <class T>
struct Vec {
    T *data_;
    unsigned int size_;
    unsigned int cap_;
    Vec() : data_(0), size_(0), cap_(0) {}
    void push_back(const T &val) {
        if (size_ < cap_) {
            size_++;
            data_[size_ - 1] = val;
        } else {
            FUN_0005ea7c(this, &val, 0);
        }
    }
};

struct FloatList {
    int count;
    float *elements;
    int cap;
    int pad;
};

struct Item {
    char f0;
    int f4;
    Vec<void *> v1;
    FloatList times;
    Vec<void *> v3;
    Item() {
        f0 = 0;
        f4 = 0;
        times.count = 0;
        times.elements = 0;
        times.cap = 0;
        times.pad = 0;
    }
};

struct Self {
    int *buf;
    Vec<Item *> v;
    float max_time;
};

extern "C" Self *FUN_0005e454(Self *self, void *p2, int p3, int p4, int p5, int p6, int p7, int p8)
{
    self->v.data_ = 0;
    self->v.size_ = 0;
    self->v.cap_ = 0;
    FUN_0005e6e0(self);
    int cookie;
    int *buf = (int *)FUN_0004cd8c(p2, &cookie, 16, 1);
    self->buf = buf;
    if (buf != 0) {
        int count = *buf;
        int *p = buf + 1;
        for (int i = 0; i < count; i++) {
            Item *item = new Item();
            p = FUN_0005dd7c(item, p);
            self->v.push_back(item);
            float last_time = 0.0f;
            if (item->times.count > 0) {
                last_time = item->times.elements[item->times.count - 1];
            }
            float scaled = last_time * 30.0f;
            const float &m = (self->max_time < scaled) ? scaled : self->max_time;
            self->max_time = m;
        }
        if (p3 != 0 && p4 != 0) {
            FUN_0005e6ec(self, p3, p4, p5, p6, p7, p8);
        }
    }
    return self;
}

// What differs:
// - Frame size is 64 bytes instead of retail's 80 bytes.
// - All local stack accesses (cookie at 60 vs 76, item at 56 vs 72, scaled at 52 vs 68, p8 at 48 vs 56)
//   are shifted by 16 bytes due to a 16-byte stack slot present in retail between ra save (44) and scaled.
// What was ruled out:
// - Explicit padding arrays (char pad[16], int pad[4]) are optimized away without address-taken references.
// - Volatile padding arrays are unreferenced and do not force MWCC frame allocation.
// - Inlined vector push_back sequence and control flow match retail structure exactly.
// near miss from lane u5fr2-0 (unreviewed)
