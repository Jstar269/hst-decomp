/* HSTMATCH module=hstp_trans_main.prx start=0x000d4b28 end=0x000d4e34 symbol=FUN_000d4b28 lang=c++ */
/* Clone of src/eboot/deleting_dtor_vectors_000d0f2c.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed Self struct, pointer-vector iterator loop (free !(a == b), const begin()) for the first vector, member delete walks with opt_strength_reduction off, vector clears as `n = size; size -= n` (matching idiom: the two walked vectors are cleared through an identical-layout VecB view, the first through the plain member); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
extern "C" {
extern void FUN_00000a00(...);
extern int *FUN_000702c4(...);
extern int *FUN_000d926c(...);
extern int *FUN_000d92d4(...);
extern void *FUN_000ea264(...);
}
extern char DAT_003b076c;
struct Alloc {};
struct Iter {
    int **p;
    Iter(int **q) : p(q) {}
    Iter &operator++() { ++p; return *this; }
    int *&operator*() const { return *p; }
};
inline bool operator==(const Iter &a, const Iter &b) { return a.p == b.p; }
inline bool operator!=(const Iter &a, const Iter &b) { return !(a == b); }
struct Vec {
    int **data;
    unsigned size;
    Iter begin() const { return Iter(data); }
    Iter end() { return Iter(data + size); }
};
struct VecB {
    int **data;
    unsigned size;
    void shrink(int n, Alloc) { size -= n; }
};
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };
struct VC_3 { virtual ~VC_3(); };
struct VC_4 { virtual ~VC_4(); };
struct VC_5 { virtual ~VC_5(); };
struct VC_6 { virtual ~VC_6(); };
struct VC_7 { virtual ~VC_7(); };
struct VC_8 { virtual ~VC_8(); };

struct Self {
    void *vptr;
    char pad0[0xc4];
    Vec v0;
    char pad1[4];
    VC_7 *p_d4;
    char pad2[0x180 - 0xd8];
    VC_1 *p180;
    VC_2 *p184;
    VC_6 *p188;
    char pad3[4];
    VC_3 *p190;
    VC_8 *p194;
    char pad4[0x1a8 - 0x198];
    Vec v1;
    char pad5[4];
    Vec v2;
};

extern "C" Self *FUN_000d4b28(Self *self, short flag)
{
    if (self != 0) {
        self->vptr = &DAT_003b076c;
        for (Iter it = self->v0.begin(); it != self->v0.end(); ++it) {
            if (*it != 0) {
                delete ((VC_0 *)(*it));
                *it = 0;
            }
        }
        {
            int n = self->v0.size;
            self->v0.size -= n;
        }
        if (self->p180 != 0) {
            if (self->p180 != 0) {
                delete self->p180;
                self->p180 = 0;
            }
        }
        if (self->p184 != 0) {
            delete self->p184;
            self->p184 = 0;
        }
        if (self->p190 != 0) {
            delete self->p190;
            self->p190 = 0;
        }
        {
            unsigned i = 0;
            if (self->v1.size != 0) {
                do {
                    int *p = self->v1.data[i];
                    if (p != 0) {
                        delete ((VC_4 *)p);
                        self->v1.data[i] = 0;
                    }
                    i = i + 1;
                } while (i < self->v1.size);
            }
        }
        {
            int n = ((VecB *)&self->v1)->size;
            ((VecB *)&self->v1)->shrink(n, Alloc());
        }
        {
            unsigned i = 0;
            if (self->v2.size != 0) {
                do {
                    int *p = self->v2.data[i];
                    if (p != 0) {
                        delete ((VC_5 *)p);
                        self->v2.data[i] = 0;
                    }
                    i = i + 1;
                } while (i < self->v2.size);
            }
        }
        {
            int n = ((VecB *)&self->v2)->size;
            ((VecB *)&self->v2)->shrink(n, Alloc());
        }
        if (self->p188 != 0) {
            delete self->p188;
            self->p188 = 0;
        }
        if (self->p_d4 != 0) {
            delete self->p_d4;
            self->p_d4 = 0;
        }
        if (self->p194 != 0) {
            delete self->p194;
            self->p194 = 0;
        }
        {
            Vec *q = &self->v2;
            if ((q != 0) && (q != 0)) {
                FUN_000d92d4(q, 0);
            }
        }
        {
            Vec *q = &self->v1;
            if ((q != 0) && (q != 0)) {
                FUN_000d926c(q, 0);
            }
        }
        {
            Vec *q = &self->v0;
            if ((q != 0) && (q != 0)) {
                FUN_000702c4(q, 0);
            }
        }
        FUN_000ea264(self, 0);
        if (0 < flag) {
            FUN_00000a00(self);
        }
    }
    return self;
}
