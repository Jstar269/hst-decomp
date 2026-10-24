/* HSTMATCH module=EBOOT.BIN start=0x00287ff0 end=0x00288208 symbol=FUN_00287ff0 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef unsigned char u8;
typedef unsigned int uint;

struct Tag {};

struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Node {
    Node *next;
    Node *prev;
};

struct Key {
    int tag;
    int index;
    int value;
    int mode;
    int flag;
    int extra;
};

struct Obj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual const Vec4 &m6(); // offset 0x20
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12(Vec4 *data, int count, int flag); // offset 0x38
    char pad[0x54];
    u8 f58;
    char pad59[0x64 - 0x59];
    int count;
    int sentinel;
};

extern "C" {
extern void *DAT_0034a114;
void FUN_0012ca08(void *vec, const Vec4 *val, Tag);
void FUN_000e88e4(void *vec, int flag);
void FUN_001caee4(void *g, int p2, Vec4 *out, void *buf);
void FUN_001cb334(void *g, int p2, Vec4 *out, void *buf);
void FUN_00289544(void *out, void *vec, void *list, void *key);
void FUN_00287ff0(Obj *self, int param_2, int param_3, int param_4, void *param_5, uint param_6);
}

struct VectorVec4 {
    Vec4 *data;
    uint size;
    uint capacity;

    void push_back(const Vec4 &val) {
        if (size < capacity) {
            Vec4 *dst = &data[size];
            if (dst != 0) {
                *dst = val;
            }
            size++;
        } else {
            FUN_0012ca08(this, &val, Tag());
        }
    }
};

void FUN_00287ff0(Obj *self, int param_2, int param_3, int param_4, void *param_5, uint param_6)
{
    Vec4 v[2];
    VectorVec4 vec;

    if (param_3 < 1) {
        int flag = 0;
        if (param_4 == 0) {
            flag = *(u8 *)((char *)param_5 + 0x58);
        } else if (param_4 == 2) {
            flag = 1;
        }

        vec.data = 0;
        vec.size = 0;
        vec.capacity = 0;

        vec.push_back(self->m6());

        if (flag == 0) {
            FUN_001caee4(DAT_0034a114, param_2, &v[1], &v[0]);
        } else {
            FUN_001cb334(DAT_0034a114, param_2, &v[1], &v[0]);
        }
        vec.push_back(v[1]);

        int f = (bool)self->f58;
        if (f) {
            f = (param_6 != 0) ^ 1;
        }
        self->m12(vec.data, 2, f);

        FUN_000e88e4(&vec, 0);
    } else {
        Key k;
        Node *out;
        k.tag = 0x42;
        k.index = param_3;
        k.value = param_2;
        k.mode = (self->f58 != 0) ? 2 : 1;
        k.flag = param_6 & 0xff;
        Node *sent = (Node *)((char *)self + 0x68);
        FUN_00289544(&out, (int *)((char *)self + 0x64), &sent, (int *)&k);
    }
}
