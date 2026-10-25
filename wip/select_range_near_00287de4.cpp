/* HSTMATCH module=EBOOT.BIN start=0x00287de4 end=0x00287ff0 symbol=FUN_00287de4 lang=c++ */
struct Tag {};
struct CmpBase {}; struct Compare : CmpBase {};

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
    char pad[0x3c];
    int cur;
    char pad2[0x64 - 0x44];
    int count;
    Node sentinel;
};

struct VIter { Vec4 *p; VIter operator-(int n) const { VIter r; r.p = p - n; return r; } bool operator==(const VIter &o) const { return p == o.p; } bool operator!=(const VIter &o) const { return p != o.p; } };

extern "C" {
extern int DAT_002fea14;
extern void *DAT_0034a114;
void FUN_001cb464(void *vec, void *g, int id);
void FUN_0012ca08(void *vec, const Vec4 *val, Tag);
void FUN_000e88e4(void *vec, int flag);
void FUN_00289330(VIter first, VIter middle, VIter last, Compare);
struct ListIt { Node *p; ListIt() {} ListIt(Node *q) : p(q) {} ListIt(const ListIt &o) : p(o.p) {} };
ListIt FUN_00289544(void *list, ListIt pos, const Key &k);
void FUN_00287de4(Obj *self, int param_2, int param_3, int param_4);
}

struct VectorVec4 {
    Vec4 *data;
    unsigned size;
    unsigned capacity;

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
    VIter begin() { VIter i; i.p = data; return i; }
    VIter end() { VIter i; i.p = data + size; return i; }
};

static inline void IM(VIter first, VIter middle, VIter last)
{
    if (first != middle && middle != last) FUN_00289330(first, middle, last, Compare());
}

static inline void ListInsertEnd(Obj *self, const Key &k)
{
    FUN_00289544((char *)self + 0x64, ListIt((Node *)((char *)self + 0x68)), k);
}

template <class T> static inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }

void FUN_00287de4(Obj *self, int param_2, int param_3, int param_4)
{
    if (param_4 < 1) {
        VectorVec4 vec;
        int from;
        FUN_001cb464(&vec, DAT_0034a114, param_2);
        int old = self->cur;
        from = old;
        int n0 = vec.size;
        if (param_3 < 0) {
            param_3 = n0 - 1;
        }
        if (from >= n0 || param_3 >= n0) {
            FUN_000e88e4(&vec, 0);
            return;
        }
            if (param_3 < old) {
                from = param_3;
                param_3 = old;
            }
            if (from < 0) {
                vec.push_back(self->m6());
                VIter m; m.p = vec.data + vec.size - 1; IM(vec.begin(), m, vec.end());
            }
            int n = param_3 - from + 1;
            from = Max(from, DAT_002fea14);
            if (vec.size != 0) {
                self->m12(&vec.data[from], n, 0);
            }
            self->cur = param_3;
            FUN_000e88e4(&vec, 0);
    } else {
        Key k;
        k.tag = 0x2f;
        k.index = param_4;
        k.value = param_2;
        k.mode = param_3;
        ListInsertEnd(self, k);
    }
}
// NEAR: 43 of 131 words differ, all residue is stack-slot placement (frame 96 vs 112) plus one operand order:
//  - retail's inlined merge call has slots T1=64 T2=60 (begin()/end() temps), homes 56/52/48 (first, middle, last), tag 44, then a gap at 40, then the list temps 36/32.
//    Ours puts the (empty) Tag slot of the inline push_back at 44 BETWEEN the temps and the homes, so every slot below shifts by 4 and the frame is 16 short.
//  - retail: `sll v0,v1,4; lw v1,100(sp); addu a1,v1,v0` (index first) for &vec.data[from]; ours loads data first.
// Ruled out: const& middle (Tmid temp lands between T1/T2), named middle local, two-level wrapper (extra FPR copies), pointer middle param,
//   forwarding the Tag through another inline (grow(val,Tag())), wrapping push_back in a free inline (code shape changes, 101 words).
// Found: cur kept as two vars (`old` and `from`), `int n0=vec.size` hoists the size load, early `if(from>=n0||to>=n0){cleanup;return;}` gives retail's else-first layout,
//   `n=to-from+1` computed before the max() call, list insert via ListIt (user copy ctor) built in an inline helper puts the 2 list temps lowest.
// near miss from lane sn8 (unreviewed)
