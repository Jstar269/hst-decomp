/* HSTMATCH module=EBOOT.BIN start=0x001cc510 end=0x001cc6cc symbol=FUN_001cc510 lang=c++ */

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
    float m[4][4];
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

struct Obj {
    char pad[76];
    Elem **data;      // 76 (0x4c)
    int size;         // 80 (0x50)
    char pad2[264];   // 84..347
    Sub15c *sub_15c;  // 348 (0x15c)
};

extern "C" void FUN_001cc510(Obj *self) {
    void *local_sub;
    float out_a[2];
    float out_b[2];
    Vec4 out_vec[2];
    Matrix44 mat;

    Elem **first = self->data;
    Elem **last = first + self->size;
    if (first != last) {
        do {
            Elem *elem = *first;
            if (elem != 0 && elem->type == 1000) {
                int idx = elem->idx;
                local_sub = 0;
                void *p = FUN_00288f2c(elem, &local_sub);
                if (local_sub != 0) {
                    FUN_00055240(&mat, local_sub, p);
                    Vec4 *v = (Vec4 *)((char *)&mat + 48);
                    out_vec[idx] = *v;
                }
            }
            ++first;
        } while (first != self->data + self->size);
    }

    float *pa = out_a;
    float *pb = out_b;
    Vec4 *pv = out_vec;
    for (int k = 0; k < 2; k++, pa++, pb++, pv++) {
        if (!FUN_00064324(pv, pa, pb)) {
            *pa = -1.0f;
            *pb = -1000.0f;
        }
    }

    Sub15c *sub = self->sub_15c;
    float b1 = out_b[1];
    float a1 = out_a[1];
    sub->field_f4 = 0;
    FUN_00225f6c(DAT_0034a2e0, 0, out_a[0], out_b[0]);
    FUN_00225f6c(DAT_0034a2e0, 1, a1, b1);
    FUN_00226030(DAT_0034a2e0);
    FUN_001cd88c(sub, 10, 1);
    FUN_001c2498(sub);
}

// Differing words: 97 / 111.
// Total words: 105 / 111.
// Frame size: 176 bytes matches retail bit-for-bit.
// Saved registers: ra (44), s4 (40), s3 (36), s2 (32), s1 (28), s0 (24), f21 (20), f20 (16) match bit-for-bit.
// Stack variables: mat (48), out_vec (112), out_b (152), out_a (160) match retail offsets.
// Differences are in the first loop iterator first != last condition lowering and register assignment.
// near miss from lane ag4 (unreviewed)
