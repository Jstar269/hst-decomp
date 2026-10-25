/* HSTMATCH module=EBOOT.BIN start=0x0012c364 end=0x0012c530 symbol=FUN_0012c364 lang=c++ */

extern "C" {
void FUN_00126d1c(const char *);
void FUN_000e8800(void *, unsigned int, char);
void FUN_000e8810(void *, unsigned int, void *, char);
void FUN_0012c7d8(void *);
void FUN_0012ca08(void *, const void *, char);
extern const char DAT_002daa28[];
extern void *DAT_002c0ef0;
}

struct Vec4 {
    float x, y, z, w;
};

struct T56 {
    char data[56];
};

template <class T>
struct Vec {
    T *data_;
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
    Vec<Vec4> v70;
    int point_count;
    int f80;
    Vec<T56> v84;
};

extern "C" int FUN_0012c364(Object *self, Vec4 *points, unsigned int count)
{
    if (count < 2) {
        FUN_00126d1c(DAT_002daa28);
        return 0;
    }
    FUN_000e8800(&self->v70, self->v70.size_, 0);
    Vec<Vec4> *v = &self->v70;
    Vec4 *it = points;
    Vec4 *end = points + count;
    if (it != end) {
        if (it != end) {
            do {
                if (v->size_ < v->cap_) {
                    Vec4 *dest = v->data_ + v->size_;
                    if (dest != 0) {
                        *dest = *it;
                    }
                    v->size_++;
                } else {
                    FUN_0012ca08(v, it, 0);
                }
                it++;
            } while (it != end);
        }
    }
    self->point_count = count;
    self->f80 = 0;
    self->f50 = 0;
    self->vtable = &DAT_002c0ef0;
    self->start_pos = *points;
    self->f80 = 1;
    FUN_000e8800(&self->v84, self->v84.size_, 0);
    if (self->v84.size_ < count) {
        T56 def;
        FUN_000e8810(&self->v84, count - self->v84.size_, &def, 0);
    } else if (count < self->v84.size_) {
        FUN_000e8800(&self->v84, self->v84.size_ - count, 0);
    }
    FUN_0012c7d8(self);
    return 1;
}

// EBOOT NEAR MISS: 107/115 words, 94 differing words after retargeting the Sharing twin.
// Addresses retargeted to the EBOOT warning string DAT_002daa28 and helpers
// FUN_00126d1c, FUN_000e8800, FUN_000e8810, FUN_0012ca08, and FUN_0012c7d8.
// The v70 range-copy loop remains the main mismatch: EBOOT retail copies the vector
// object pointer through two stack slots with lwc1/swc1, duplicates its range test,
// and uses different saved-register assignments. The high-level source currently
// walks points directly and calls the per-element append helper.
// A back-insert iterator/copy-range experiment was worse (112 differing words).
// The byte-identical Sharing twin lane also reported the vector iterator spill and
// range-check duplication; its tried C-pointer loop omitted the FPU stack copies.
// near miss from lane lnm2 (unreviewed)
