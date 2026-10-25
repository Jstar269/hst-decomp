/* HSTMATCH module=hstp_trans_main.prx start=0x0013f4e4 end=0x0013f724 symbol=FUN_0013f4e4 lang=c++ */
/* Clone of src/eboot/spawn_setup_00133e98.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

struct Tag {};

struct Vec4 {
    float x, y, z, w;

    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

inline void *operator new(unsigned int, void *p) {
    return p;
}

struct ObjA {
    char pad[0x280];
    Vec4 pos;
};

struct ObjB {
    char pad[0x40];
    Vec4 pos;
};

struct ObjC {
    char pad[0x3c0];
    Vec4 pos;
};

template <typename T>
struct PVecPtr {
    T **data;
    unsigned size;
    unsigned capacity;
};

struct PVec_Vec4;
extern "C" {
    void FUN_000ed8d4(PVec_Vec4 *v, unsigned int n, Tag tag);
    void FUN_00137e74(PVec_Vec4 *v, const Vec4 *val, Tag tag);
}

struct PVec_Vec4 {
    Vec4 *data;
    unsigned size;
    unsigned capacity;
};

struct Owner {
    char pad0[0x188];
    PVecPtr<ObjC> objectsC; // 0x188
    char pad1[0x1398 - 0x194];
    PVecPtr<ObjA> objectsA; // 0x1398
    char pad2[0x13b0 - 0x13a4];
    PVecPtr<ObjB> objectsB; // 0x13b0
    char pad3[0x1430 - 0x13bc];
    PVec_Vec4 out_vec;      // 0x1430
};

#define PUSH_BACK(vec, val) do { \
    if ((vec).size < (vec).capacity) { \
        new (&(vec).data[(vec).size]) Vec4(val); \
        (vec).size++; \
    } else { \
        FUN_00137e74(&(vec), &(val), Tag()); \
    } \
} while (0)

extern "C" PVec_Vec4 *FUN_0013f4e4(Owner *self) {
    Vec4 v[3];

    unsigned sz = self->out_vec.size;
    FUN_000ed8d4(&self->out_vec, sz, Tag());

    for (unsigned i = 0; i < self->objectsA.size; i++) {
        v[1] = self->objectsA.data[i]->pos;
        PUSH_BACK(self->out_vec, v[1]);
    }

    for (unsigned i = 0; i < self->objectsB.size; i++) {
        v[0] = self->objectsB.data[i]->pos;
        PUSH_BACK(self->out_vec, v[0]);
    }

    for (unsigned i = 0; i < self->objectsC.size; i++) {
        ObjC *c = self->objectsC.data[i];
        PUSH_BACK(self->out_vec, c->pos);
    }

    return &self->out_vec;
}
