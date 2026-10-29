/* HSTMATCH module=EBOOT.BIN start=0x0012c364 end=0x0012c530 symbol=FUN_0012c364 lang=c++ */
#pragma inline_depth(8)

struct False {};

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
    Vec4 &operator=(const Vec4 &o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};

struct T56 {
    char data[56];
};

inline void *operator new(unsigned int, void *p) { return p; }

struct Vec4Vec;
extern "C" {
void FUN_00126d1c(const char *);
void FUN_000e8800(void *, unsigned int, False);
void FUN_000e8810(void *, unsigned int, void *, False);
void FUN_0012c7d8(void *);
void FUN_0012ca08(Vec4Vec *, const Vec4 *, False);
extern const char DAT_002daa28[];
extern void *DAT_002c0ef0;
}

struct Vec4Vec {
    Vec4 *data_;
    unsigned int size_;
    unsigned int cap_;
    void push_back(const Vec4 &v)
    {
        if (size_ < cap_) {
            new (data_ + size_) Vec4(v);
            size_++;
        } else {
            FUN_0012ca08(this, &v, False());
        }
    }
};

struct BackIt {
    Vec4Vec *c;
    BackIt &operator=(const Vec4 &v) { c->push_back(v); return *this; }
};

inline BackIt back_inserter(Vec4Vec &v)
{
    BackIt it;
    it.c = &v;
    return it;
}

inline void copy_range(const Vec4 *first, const Vec4 *last, BackIt out)
{
    for (; first != last; ++first)
        out = *first;
}

inline void copy(const Vec4 *first, const Vec4 *last, BackIt out)
{
    if (first != last)
        copy_range(first, last, out);
}

struct Vec56 {
    T56 *data_;
    unsigned int size_;
    unsigned int cap_;
};

struct Object {
    char pad[0x40];
    void *vtable;
    char pad2[0xc];
    int f50;
    char pad3[0xc];
    Vec4 start_pos;
    Vec4Vec v70;
    int point_count;
    int f80;
    Vec56 v84;
};

extern "C" int FUN_0012c364(Object *self, Vec4 *points, unsigned int count)
{
    if (count < 2) {
        FUN_00126d1c(DAT_002daa28);
        return 0;
    }
    FUN_000e8800(&self->v70, self->v70.size_, False());
    copy(points, points + count, back_inserter(self->v70));
    self->point_count = count;
    self->f80 = 0;
    self->f50 = 0;
    self->vtable = &DAT_002c0ef0;
    self->start_pos = *points;
    self->f80 = 1;
    FUN_000e8800(&self->v84, self->v84.size_, False());
    if (self->v84.size_ < count) {
        T56 def;
        FUN_000e8810(&self->v84, count - self->v84.size_, &def, False());
    } else if (count < self->v84.size_) {
        FUN_000e8800(&self->v84, self->v84.size_ - count, False());
    }
    FUN_0012c7d8(self);
    return 1;
}

// lane sx4: 58 of 115 words differ (was 94). Natural form: inline back-insert iterator (aggregate, copied through two stack slots by lwc1/swc1 exactly as retail),
// inline vector push_back with placement new + out-of-line grow (FUN_0012ca08, empty False tag -> `move v0,zero; seb a2,v0`), inline copy with the duplicated `first != last` guard,
// `#pragma inline_depth(8)` (without it push_back stays an out-of-line call). The whole loop body now matches.
// Remaining: frame is 128 instead of 96 (the two iterator slots and the T56 default temp are laid out 16 bytes apart / above instead of retail's 32..88 T56, 88/92 slots),
// which shifts every s-register by one. Ruled out: T56 as long long/double/float array or user-ctor temp passed as const T56& (moves it to the frame top), T56 declared at function top,
// copy split into copy/copy_range (extra slot), BackIt& parameter, resize as an inline helper, non-tag char 0 for the grow call.
// improved by lane sx4 (unreviewed): 94 -> 58 differing words
