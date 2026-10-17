/* HSTMATCH module=hstp_trans_main.prx start=0x001377d0 end=0x0013799c symbol=FUN_001377d0 lang=c++ */

extern "C" {
void FUN_00131f8c(const char *);
void FUN_000ed8d4(void *, unsigned int, char);
void FUN_000ed8e4(void *, unsigned int, void *, char);
void FUN_00137c44(void *);
void FUN_00137e74(void *, const void *, char);
extern const char DAT_00381b18[];
extern void *DAT_002d11a0;
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

extern "C" int FUN_001377d0(Object *self, Vec4 *points, unsigned int count)
{
    if (count < 2) {
        FUN_00131f8c(DAT_00381b18);
        return 0;
    }
    FUN_000ed8d4(&self->v70, self->v70.size_, 0);
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
                    FUN_00137e74(v, it, 0);
                }
                it++;
            } while (it != end);
        }
    }
    self->point_count = count;
    self->f80 = 0;
    self->f50 = 0;
    self->vtable = &DAT_002d11a0;
    self->start_pos = *points;
    self->f80 = 1;
    FUN_000ed8d4(&self->v84, self->v84.size_, 0);
    if (self->v84.size_ < count) {
        T56 def;
        FUN_000ed8e4(&self->v84, count - self->v84.size_, &def, 0);
    } else if (count < self->v84.size_) {
        FUN_000ed8d4(&self->v84, self->v84.size_ - count, 0);
    }
    FUN_00137c44(self);
    return 1;
}

// What differs:
// - Vector copy loop: retail uses temporary stack copies through float registers
//   (lwc1/swc1) and duplicates the range check branch (beq s4, s0) due to inlined
//   vector::insert / vector::assign range logic.
// - Register allocation around v70 pointer and loop index differs by ~30 words.
// What was ruled out:
// - Plain C pointer loops emit integer word copies (lw/sw) rather than retail's float register copies (lwc1/swc1).
// - Single-condition loops omit the outer pre-check seen in retail.
// near miss from lane u5fr2-0 (unreviewed)
