/* HSTMATCH module=EBOOT.BIN start=0x0012d550 end=0x0012d75c symbol=FUN_0012d550 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

template<typename T>
struct Vector {
    T *data;
    int count;

    struct Iter {
        T *p;
        Iter(T *p_) : p(p_) {}
        T &operator*() const { return *p; }
        Iter &operator++() { ++p; return *this; }
        friend bool operator!=(const Iter &a, const Iter &b) {
            return !(a.p == b.p);
        }
    };

    Iter begin() const { return Iter(data); }
    Iter end() { return Iter(data + count); }
};

struct Obj {
    virtual void _0() = 0;
    virtual void _1() = 0;
    virtual void _2() = 0;
    virtual void _3() = 0;
    virtual void _4() = 0;
    virtual void _5() = 0;
    virtual void _6() = 0;
    virtual void _7() = 0;
    virtual void _8() = 0;
    virtual void _9() = 0;
    virtual void _10() = 0;
    virtual int GetType() = 0; // offset 52 (0x34)

    char pad[0x54 - 4];
    unsigned char flag;        // 84 (0x54)
    char pad55[0x74 - 0x55];
    void *subobj1;             // 116 (0x74)
    void *subobj2;             // 120 (0x78)
};

struct SceneObj {
    char pad[0x70];
    Vector<Obj *> vec1;        // 0x70
    char pad78[4];
    Vector<Obj *> vec2;        // 0x7c
};

struct RayHit {
    char pad[0x30];
    unsigned int dist;         // 48 (0x30)
    int f34;                   // 52 (0x34)
    char pad38[4];
    int f3c;                   // 60 (0x3c)
    int f40;                   // 64 (0x40)
};

struct Context {
    char pad[12];
    void *main_obj;            // 12 (0x0c)
};

extern "C" {
extern char DAT_002c1514;
extern SceneObj *DAT_0034a114;
extern bool FUN_00055b54(void *, RayHit *, int, void *, int, int, int);
}

extern "C" bool FUN_0012d550(Context *ctx, RayHit *hit, int tag)
{
    hit->dist = 0x7f7fffff;
    hit->f34 = 0;
    hit->f3c = 0;
    hit->f40 = 0;

    bool result = false;
    if (FUN_00055b54(ctx->main_obj, hit, tag, &DAT_002c1514, 0, 0, 1)) {
        result = true;
    }

    Obj *obj;
    Vector<Obj *> &vec1 = DAT_0034a114->vec1;
    for (Vector<Obj *>::Iter it = vec1.begin(); it != vec1.end(); ++it) {
        obj = *it;
        if (obj->GetType() == 4) {
            if (obj->flag && obj->subobj1) {
                if (FUN_00055b54(obj->subobj1, hit, tag, 0, 0, 0, 1)) {
                    result = true;
                }
            }
        }
    }

    Vector<Obj *> &vec2 = DAT_0034a114->vec2;
    for (Vector<Obj *>::Iter it = vec2.begin(); it != vec2.end(); ++it) {
        obj = *it;
        if (obj != 0) {
            if (obj->GetType() == 5 && obj->flag && obj->subobj2) {
                if (FUN_00055b54(obj->subobj2, hit, tag, 0, 0, 0, 1)) {
                    result = true;
                }
            }
        }
    }

    return result;
}
