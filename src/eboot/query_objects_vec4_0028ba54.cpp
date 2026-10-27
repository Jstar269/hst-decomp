/* HSTMATCH module=EBOOT.BIN start=0x0028ba54 end=0x0028bb2c symbol=FUN_0028ba54 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* For every non-null object in the manager's pointer vector, query two Vec4 values by the object's id and,
   when the query succeeds, hand them to the object's virtual slots 5 and 7. Names provisional.
   Required shapes: const begin() with non-const end() (else the entry test folds), a free operator!= written
   !(a == b) (xor/sltiu/xori), and 16-byte-aligned Vec4 locals (retail slots sp+32/sp+16). */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void SetA(Vec4 *a);
    virtual void v6();
    virtual void SetB(Vec4 *b);
    char pad[0x30 - 4];
    int id;
};

struct It {
    Obj **p;
    It(Obj **q) : p(q) {}
    Obj *&operator*() const { return *p; }
    It &operator++() { ++p; return *this; }
};
inline bool operator==(const It &a, const It &b) { return a.p == b.p; }
inline bool operator!=(const It &a, const It &b) { return !(a == b); }

struct Vector {
    Obj **data;
    unsigned size;
    It begin() const { return It(data); }
    It end() { return It(data + size); }
};

struct Mgr {
    char pad[0x7c];
    Vector objs;
};

extern Mgr *DAT_0034a114;
extern "C" int FUN_001cb204(Mgr *m, int id, Vec4 *a, Vec4 *b);

extern "C" void FUN_0028ba54(void)
{
    Vector &v = DAT_0034a114->objs;
    for (It it = v.begin(); it != v.end(); ++it) {
        Obj *o = *it;
        if (o != 0) {
            Vec4 a;
            Vec4 b;
            if (FUN_001cb204(DAT_0034a114, o->id, &a, &b)) {
                o->SetA(&a);
                o->SetB(&b);
            }
        }
    }
}
