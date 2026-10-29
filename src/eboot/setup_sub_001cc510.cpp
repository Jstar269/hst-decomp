/* HSTMATCH module=EBOOT.BIN start=0x001cc510 end=0x001cc6cc symbol=FUN_001cc510 lang=c++ */
/* Hand-written reconstruction from the disassembly (wip from lane ag4 restructured: iterator class with !(==) and const begin()/end(), Matrix44 rows, unsigned loop counter); exact match verified; names and types await human review. Matching idioms: `void *local_sub[2]` (only [0] used) reproduces retail's 4-byte frame hole above the out-parameter slot; the second loop initialises all its cursors in the for-init. */

extern "C" {
extern void *DAT_0034a2e0;

void *FUN_00288f2c(void *elem, void **out_sub);
void FUN_00055240(void *buf, void *sub, void *p);
int FUN_00064324(void *vec, float *out_a, float *out_b);
void FUN_00225f6c(void *mgr, int idx, float a, float b);
void FUN_00226030(void *mgr);
void FUN_001cd88c(void *obj, int a, int b);
void FUN_001c2498(void *obj);
}

struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Matrix44 {
    Vec4 r0, r1, r2, r3;
} __attribute__((aligned(16)));

struct Elem {
    char pad[52]; // 0..51
    int type;     // 52 (0x34)
    int idx;      // 56 (0x38)
};

struct Sub15c {
    char pad[244];
    int field_f4; // 244 (0xf4)
};

struct It {
    Elem **p;
    It(Elem **q) : p(q) {}
    Elem *&operator*() const { return *p; }
    It &operator++() { ++p; return *this; }
};
inline bool operator==(const It &a, const It &b) { return a.p == b.p; }
inline bool operator!=(const It &a, const It &b) { return !(a == b); }

struct Obj {
    char pad[76];
    Elem **data;      // 76 (0x4c)
    int size;         // 80 (0x50)
    char pad2[264];   // 84..347
    Sub15c *sub_15c;  // 348 (0x15c)
    It begin() const { return It(data); }
    It end() const { return It(data + size); }
};

extern "C" void FUN_001cc510(Obj *self) {
    void *local_sub[2];
    float out_a[2];
    float out_b[2];
    Vec4 out_vec[2];
    Matrix44 mat;

    for (It it = self->begin(); it != self->end(); ++it) {
        Elem *elem = *it;
        if (elem != 0 && elem->type == 1000) {
            int idx = elem->idx;
            local_sub[0] = 0;
            void *p = FUN_00288f2c(elem, &local_sub[0]);
            if (local_sub[0] != 0) {
                FUN_00055240(&mat, local_sub[0], p);
                out_vec[idx] = mat.r3;
            }
        }
    }

unsigned k;
    float *pb;
    float *pa;
    Vec4 *pv;
    for (k = 0, pb = out_b, pa = out_a, pv = out_vec; k < 2; k++, pb++, pa++, pv++) {
        if (!FUN_00064324(pv, pa, pb)) {
            *pa = -1.0f;
            *pb = -1000.0f;
        }
    }

    Sub15c *sub = self->sub_15c;
    float a1;
    float b1;
    b1 = out_b[1];
    a1 = out_a[1];
    sub->field_f4 = 0;
    FUN_00225f6c(DAT_0034a2e0, 0, out_a[0], out_b[0]);
    FUN_00225f6c(DAT_0034a2e0, 1, a1, b1);
    FUN_00226030(DAT_0034a2e0);
    FUN_001cd88c(sub, 10, 1);
    FUN_001c2498(sub);
}
